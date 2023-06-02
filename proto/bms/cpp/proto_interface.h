#ifndef bms_PROTO_INTERFACE_H
#define bms_PROTO_INTERFACE_H

#include <string>
#include <unordered_map>
#include <functional>

#include "bms.pb.h"

#ifdef bms_IMPLEMENTATION
#undef bms_IMPLEMENTATION
#define __bms_IMPLEMENTATION
#endif

#include "../../../lib/bms/c/network.h"

#ifdef __bms_IMPLEMENTATION
#undef __bms_IMPLEMENTATION
#define bms_IMPLEMENTATION
#endif

#ifndef CANLIB_MESSAGE_ID_TYPE
#define CANLIB_MESSAGE_ID_TYPE
typedef uint16_t canlib_message_id;
#endif // CANLIB_MESSAGE_ID_TYPE

#ifndef CANLIB_CIRCULAR_BUFFER
#define CANLIB_CIRCULAR_BUFFER
namespace Helper {
template <bool FITS8, bool FITS16>
struct Index {
  using Type = uint32_t;
};

template <>
struct Index<false, true> {
  using Type = uint16_t;
};

template <>
struct Index<true, true> {
  using Type = uint8_t;
};
}  // namespace Helper

template <typename T, size_t S,
          typename IT =
              typename Helper::Index<(S <= UINT8_MAX), (S <= UINT16_MAX)>::Type>
class canlib_circular_buffer {
 public:
  static constexpr IT capacity = static_cast<IT>(S);

  using index_t = IT;

  constexpr canlib_circular_buffer();
  canlib_circular_buffer(const canlib_circular_buffer &) = delete;
  canlib_circular_buffer(canlib_circular_buffer &&) = delete;
  canlib_circular_buffer &operator=(const canlib_circular_buffer &) = delete;
  canlib_circular_buffer &operator=(canlib_circular_buffer &&) = delete;

  bool unshift(T value);
  bool push(T value);
  T shift();
  T pop();
  const T& start() const;
  T inline first() const;
  T inline last() const;
  const T& operator[](IT index) const;
  IT inline size() const;
  IT inline available() const;
  bool inline empty() const;
  bool inline full() const;
  void inline clear();
  size_t inline offset() const;


 private:
  T buffer[S];
  T *head;
  T *tail;
  size_t _offset;
#ifndef CIRCULAR_BUFFER_INT_SAFE
  IT count;
#else
  volatile IT count;
#endif
};

template <typename T, size_t S, typename IT>
constexpr canlib_circular_buffer<T, S, IT>::canlib_circular_buffer()
    : head(buffer), tail(buffer), count(0), _offset(0) {}

template <typename T, size_t S, typename IT>
bool canlib_circular_buffer<T, S, IT>::unshift(T value) {
  if (head == buffer) {
    head = buffer + capacity;
  }
  *--head = value;
  if (count == capacity) {
    if (tail-- == buffer) {
      tail = buffer + capacity - 1;
    }
    return false;
  } else {
    if (count++ == 0) {
      tail = head;
    }
    return true;
  }
}

template <typename T, size_t S, typename IT>
bool canlib_circular_buffer<T, S, IT>::push(T value) {
  if (++tail == buffer + capacity) {
    tail = buffer;
  }
  *tail = value;
  if (count == capacity) {
    if (++head == buffer + capacity) {
      head = buffer;
    }
    _offset = (_offset + 1) % capacity;
    return false;
  } else {
    if (count++ == 0) {
      head = tail;
    }
    return true;
  }
}

template <typename T, size_t S, typename IT>
T canlib_circular_buffer<T, S, IT>::shift() {
  if (count == 0) return *head;
  T result = *head++;
  if (head >= buffer + capacity) {
    head = buffer;
  }
  count--;
  return result;
}

template <typename T, size_t S, typename IT>
T canlib_circular_buffer<T, S, IT>::pop() {
  if (count == 0) return *tail;
  T result = *tail--;
  if (tail < buffer) {
    tail = buffer + capacity - 1;
  }
  count--;
  return result;
}

template <typename T, size_t S, typename IT>
T inline canlib_circular_buffer<T, S, IT>::first() const {
  return *head;
}

template <typename T, size_t S, typename IT>
T inline canlib_circular_buffer<T, S, IT>::last() const {
  return *tail;
}

template <typename T, size_t S, typename IT>
const T& canlib_circular_buffer<T, S, IT>::start() const {
  return buffer[1];
}

template <typename T, size_t S, typename IT>
const T& canlib_circular_buffer<T, S, IT>::operator[](IT index) const {
  if (index >= count) return *tail;
  return *(buffer + ((head - buffer + index) % capacity));
}

template <typename T, size_t S, typename IT>
IT inline canlib_circular_buffer<T, S, IT>::size() const {
  return count;
}

template <typename T, size_t S, typename IT>
IT inline canlib_circular_buffer<T, S, IT>::available() const {
  return capacity - count;
}

template <typename T, size_t S, typename IT>
bool inline canlib_circular_buffer<T, S, IT>::empty() const {
  return count == 0;
}

template <typename T, size_t S, typename IT>
bool inline canlib_circular_buffer<T, S, IT>::full() const {
  return count == capacity;
}

template <typename T, size_t S, typename IT>
void inline canlib_circular_buffer<T, S, IT>::clear() {
  head = tail = buffer;
  count = 0;
}

template <typename T, size_t S, typename IT>
size_t inline canlib_circular_buffer<T, S, IT>::offset() const {
  return _offset;
}

#endif // CANLIB_CIRCULAR_BUFFER

#ifndef CANLIB_CIRCULAR_BUFFER_SIZE
#define CANLIB_CIRCULAR_BUFFER_SIZE 2000
#endif // CANLIB_CIRCULAR_BUFFER_SIZE


#ifndef CANLIB_PROTO_INTERFACE_TYPES
#define CANLIB_PROTO_INTERFACE_TYPES

/**
*  Use network_<> to get all the values from the protobuffer.
*  Every network can be consensed into one network_<> as all the
*  messages names are unique.
**/

typedef std::string field_name;
typedef std::string messages_name;
typedef canlib_circular_buffer<double,      CANLIB_CIRCULAR_BUFFER_SIZE> double_buffer;
typedef canlib_circular_buffer<uint64_t,    CANLIB_CIRCULAR_BUFFER_SIZE> uint64_buffer;
typedef canlib_circular_buffer<std::string, CANLIB_CIRCULAR_BUFFER_SIZE> string_buffer;

// structure contains all the messages with a enum value associated
// the type is unified to uint64_t
typedef std::unordered_map<field_name,    uint64_buffer> message_enums;
typedef std::unordered_map<messages_name, message_enums> network_enums;

// structure contains all the messages with a signal associated
// the type is unified to double
typedef std::unordered_map<field_name,    double_buffer>   message_signals;
typedef std::unordered_map<messages_name, message_signals> network_signals;

// structure contains all the messages with a string associated
// the type is unified to string
typedef std::unordered_map<field_name,    string_buffer>   message_strings;
typedef std::unordered_map<messages_name, message_strings> network_strings;

#endif // CANLIB_PROTO_INTERFACE_TYPES

void bms_proto_interface_serialize_from_id(canlib_message_id id, bms::Pack* pack, bms_devices* map);
void bms_proto_interface_deserialize(bms::Pack* pack, network_enums* net_enums, network_signals* net_signals, network_strings* net_strings, uint64_t resample_us);

#ifdef bms_PROTO_INTERAFCE_IMPLEMENTATION

void bms_proto_interface_deserialize(bms::Pack* pack, network_enums* net_enums, network_signals* net_signals, network_strings* net_strings, uint64_t resample_us) {
  char buffer[1024];
    for(int i = 0; i < pack->board_status_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->board_status(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->board_status(i)._inner_timestamp();
        (*net_signals)["BOARD_STATUS"]["_timestamp"].push(pack->board_status(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

        (*net_enums)["BOARD_STATUS"]["cellboard_id"].push(pack->board_status(i).cellboard_id());
        bms_to_string_Cellboard((bms_Cellboard)pack->board_status(i).cellboard_id(), buffer);
        (*net_strings)["BOARD_STATUS"]["cellboard_id"].push(buffer);
        memset(buffer, 0, 1024);
        (*net_enums)["BOARD_STATUS"]["errors"].push(pack->board_status(i).errors());
        bms_to_string_Errors((bms_Errors)pack->board_status(i).errors(), buffer);
        (*net_strings)["BOARD_STATUS"]["errors"].push(buffer);
        memset(buffer, 0, 1024);
        (*net_enums)["BOARD_STATUS"]["balancing_status"].push(pack->board_status(i).balancing_status());
        bms_to_string_BalancingStatus((bms_BalancingStatus)pack->board_status(i).balancing_status(), buffer);
        (*net_strings)["BOARD_STATUS"]["balancing_status"].push(buffer);
        memset(buffer, 0, 1024);
    }
    for(int i = 0; i < pack->temperatures_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->temperatures(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->temperatures(i)._inner_timestamp();
        (*net_signals)["TEMPERATURES"]["_timestamp"].push(pack->temperatures(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

        (*net_enums)["TEMPERATURES"]["cellboard_id"].push(pack->temperatures(i).cellboard_id());
        bms_to_string_Cellboard((bms_Cellboard)pack->temperatures(i).cellboard_id(), buffer);
        (*net_strings)["TEMPERATURES"]["cellboard_id"].push(buffer);
        memset(buffer, 0, 1024);
        (*net_signals)["TEMPERATURES"]["start_index"].push(pack->temperatures(i).start_index());
        (*net_signals)["TEMPERATURES"]["temp0"].push(pack->temperatures(i).temp0());
        (*net_signals)["TEMPERATURES"]["temp1"].push(pack->temperatures(i).temp1());
        (*net_signals)["TEMPERATURES"]["temp2"].push(pack->temperatures(i).temp2());
        (*net_signals)["TEMPERATURES"]["temp3"].push(pack->temperatures(i).temp3());
    }
    for(int i = 0; i < pack->voltages_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->voltages(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->voltages(i)._inner_timestamp();
        (*net_signals)["VOLTAGES"]["_timestamp"].push(pack->voltages(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

        (*net_enums)["VOLTAGES"]["cellboard_id"].push(pack->voltages(i).cellboard_id());
        bms_to_string_Cellboard((bms_Cellboard)pack->voltages(i).cellboard_id(), buffer);
        (*net_strings)["VOLTAGES"]["cellboard_id"].push(buffer);
        memset(buffer, 0, 1024);
        (*net_signals)["VOLTAGES"]["start_index"].push(pack->voltages(i).start_index());
        (*net_signals)["VOLTAGES"]["voltage0"].push(pack->voltages(i).voltage0());
        (*net_signals)["VOLTAGES"]["voltage1"].push(pack->voltages(i).voltage1());
        (*net_signals)["VOLTAGES"]["voltage2"].push(pack->voltages(i).voltage2());
    }
    for(int i = 0; i < pack->balancing_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->balancing(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->balancing(i)._inner_timestamp();
        (*net_signals)["BALANCING"]["_timestamp"].push(pack->balancing(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

        (*net_enums)["BALANCING"]["cellboard_id"].push(pack->balancing(i).cellboard_id());
        bms_to_string_Cellboard((bms_Cellboard)pack->balancing(i).cellboard_id(), buffer);
        (*net_strings)["BALANCING"]["cellboard_id"].push(buffer);
        memset(buffer, 0, 1024);
        (*net_signals)["BALANCING"]["board_index"].push(pack->balancing(i).board_index());
        (*net_enums)["BALANCING"]["cells"].push(pack->balancing(i).cells());
        bms_to_string_BalancingCells((bms_BalancingCells)pack->balancing(i).cells(), buffer);
        (*net_strings)["BALANCING"]["cells"].push(buffer);
        memset(buffer, 0, 1024);
    }
    for(int i = 0; i < pack->fw_update_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->fw_update(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->fw_update(i)._inner_timestamp();
        (*net_signals)["FW_UPDATE"]["_timestamp"].push(pack->fw_update(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

        (*net_enums)["FW_UPDATE"]["cellboard_id"].push(pack->fw_update(i).cellboard_id());
        bms_to_string_Cellboard((bms_Cellboard)pack->fw_update(i).cellboard_id(), buffer);
        (*net_strings)["FW_UPDATE"]["cellboard_id"].push(buffer);
        memset(buffer, 0, 1024);
        (*net_signals)["FW_UPDATE"]["board_index"].push(pack->fw_update(i).board_index());
    }
    for(int i = 0; i < pack->flash_cellboard_0_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->flash_cellboard_0_tx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->flash_cellboard_0_tx(i)._inner_timestamp();
        (*net_signals)["FLASH_CELLBOARD_0_TX"]["_timestamp"].push(pack->flash_cellboard_0_tx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

    }
    for(int i = 0; i < pack->flash_cellboard_0_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->flash_cellboard_0_rx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->flash_cellboard_0_rx(i)._inner_timestamp();
        (*net_signals)["FLASH_CELLBOARD_0_RX"]["_timestamp"].push(pack->flash_cellboard_0_rx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

    }
    for(int i = 0; i < pack->flash_cellboard_1_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->flash_cellboard_1_tx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->flash_cellboard_1_tx(i)._inner_timestamp();
        (*net_signals)["FLASH_CELLBOARD_1_TX"]["_timestamp"].push(pack->flash_cellboard_1_tx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

    }
    for(int i = 0; i < pack->flash_cellboard_1_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->flash_cellboard_1_rx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->flash_cellboard_1_rx(i)._inner_timestamp();
        (*net_signals)["FLASH_CELLBOARD_1_RX"]["_timestamp"].push(pack->flash_cellboard_1_rx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

    }
    for(int i = 0; i < pack->flash_cellboard_2_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->flash_cellboard_2_tx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->flash_cellboard_2_tx(i)._inner_timestamp();
        (*net_signals)["FLASH_CELLBOARD_2_TX"]["_timestamp"].push(pack->flash_cellboard_2_tx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

    }
    for(int i = 0; i < pack->flash_cellboard_2_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->flash_cellboard_2_rx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->flash_cellboard_2_rx(i)._inner_timestamp();
        (*net_signals)["FLASH_CELLBOARD_2_RX"]["_timestamp"].push(pack->flash_cellboard_2_rx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

    }
    for(int i = 0; i < pack->flash_cellboard_3_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->flash_cellboard_3_tx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->flash_cellboard_3_tx(i)._inner_timestamp();
        (*net_signals)["FLASH_CELLBOARD_3_TX"]["_timestamp"].push(pack->flash_cellboard_3_tx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

    }
    for(int i = 0; i < pack->flash_cellboard_3_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->flash_cellboard_3_rx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->flash_cellboard_3_rx(i)._inner_timestamp();
        (*net_signals)["FLASH_CELLBOARD_3_RX"]["_timestamp"].push(pack->flash_cellboard_3_rx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

    }
    for(int i = 0; i < pack->flash_cellboard_4_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->flash_cellboard_4_tx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->flash_cellboard_4_tx(i)._inner_timestamp();
        (*net_signals)["FLASH_CELLBOARD_4_TX"]["_timestamp"].push(pack->flash_cellboard_4_tx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

    }
    for(int i = 0; i < pack->flash_cellboard_4_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->flash_cellboard_4_rx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->flash_cellboard_4_rx(i)._inner_timestamp();
        (*net_signals)["FLASH_CELLBOARD_4_RX"]["_timestamp"].push(pack->flash_cellboard_4_rx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

    }
    for(int i = 0; i < pack->flash_cellboard_5_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->flash_cellboard_5_tx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->flash_cellboard_5_tx(i)._inner_timestamp();
        (*net_signals)["FLASH_CELLBOARD_5_TX"]["_timestamp"].push(pack->flash_cellboard_5_tx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

    }
    for(int i = 0; i < pack->flash_cellboard_5_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->flash_cellboard_5_rx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->flash_cellboard_5_rx(i)._inner_timestamp();
        (*net_signals)["FLASH_CELLBOARD_5_RX"]["_timestamp"].push(pack->flash_cellboard_5_rx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

    }
}

void bms_proto_interface_serialize_from_id(canlib_message_id id, bms::Pack* pack, bms_devices* map) {
    int index = bms_index_from_id(id);

    if (index == -1) return;

    switch(id) {
        case 1536: {
            bms_message_BOARD_STATUS* msg = (bms_message_BOARD_STATUS*)(&(*map)[index].message_raw);
            bms::BOARD_STATUS* proto_msg = pack->add_board_status();
            proto_msg->set_cellboard_id((bms::Cellboard)msg->cellboard_id);
            proto_msg->set_errors(msg->errors);
            proto_msg->set_balancing_status((bms::BalancingStatus)msg->balancing_status);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }
        case 1281: {
            bms_message_TEMPERATURES_conversion* msg = (bms_message_TEMPERATURES_conversion*)(&(*map)[index].message_conversion);
            bms::TEMPERATURES* proto_msg = pack->add_temperatures();
            proto_msg->set_cellboard_id((bms::Cellboard)msg->cellboard_id);
            proto_msg->set_start_index(msg->start_index);
            proto_msg->set_temp0(msg->temp0);
            proto_msg->set_temp1(msg->temp1);
            proto_msg->set_temp2(msg->temp2);
            proto_msg->set_temp3(msg->temp3);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }
        case 514: {
            bms_message_VOLTAGES_conversion* msg = (bms_message_VOLTAGES_conversion*)(&(*map)[index].message_conversion);
            bms::VOLTAGES* proto_msg = pack->add_voltages();
            proto_msg->set_cellboard_id((bms::Cellboard)msg->cellboard_id);
            proto_msg->set_start_index(msg->start_index);
            proto_msg->set_voltage0(msg->voltage0);
            proto_msg->set_voltage1(msg->voltage1);
            proto_msg->set_voltage2(msg->voltage2);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }
        case 515: {
            bms_message_BALANCING* msg = (bms_message_BALANCING*)(&(*map)[index].message_raw);
            bms::BALANCING* proto_msg = pack->add_balancing();
            proto_msg->set_cellboard_id((bms::Cellboard)msg->cellboard_id);
            proto_msg->set_board_index(msg->board_index);
            proto_msg->set_cells(msg->cells);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }
        case 10: {
            bms_message_FW_UPDATE* msg = (bms_message_FW_UPDATE*)(&(*map)[index].message_raw);
            bms::FW_UPDATE* proto_msg = pack->add_fw_update();
            proto_msg->set_cellboard_id((bms::Cellboard)msg->cellboard_id);
            proto_msg->set_board_index(msg->board_index);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }
        case 16: {
            bms_message_FLASH_CELLBOARD_0_TX* msg = (bms_message_FLASH_CELLBOARD_0_TX*)(&(*map)[index].message_raw);
            bms::FLASH_CELLBOARD_0_TX* proto_msg = pack->add_flash_cellboard_0_tx();
            break;
        }
        case 17: {
            bms_message_FLASH_CELLBOARD_0_RX* msg = (bms_message_FLASH_CELLBOARD_0_RX*)(&(*map)[index].message_raw);
            bms::FLASH_CELLBOARD_0_RX* proto_msg = pack->add_flash_cellboard_0_rx();
            break;
        }
        case 18: {
            bms_message_FLASH_CELLBOARD_1_TX* msg = (bms_message_FLASH_CELLBOARD_1_TX*)(&(*map)[index].message_raw);
            bms::FLASH_CELLBOARD_1_TX* proto_msg = pack->add_flash_cellboard_1_tx();
            break;
        }
        case 19: {
            bms_message_FLASH_CELLBOARD_1_RX* msg = (bms_message_FLASH_CELLBOARD_1_RX*)(&(*map)[index].message_raw);
            bms::FLASH_CELLBOARD_1_RX* proto_msg = pack->add_flash_cellboard_1_rx();
            break;
        }
        case 20: {
            bms_message_FLASH_CELLBOARD_2_TX* msg = (bms_message_FLASH_CELLBOARD_2_TX*)(&(*map)[index].message_raw);
            bms::FLASH_CELLBOARD_2_TX* proto_msg = pack->add_flash_cellboard_2_tx();
            break;
        }
        case 21: {
            bms_message_FLASH_CELLBOARD_2_RX* msg = (bms_message_FLASH_CELLBOARD_2_RX*)(&(*map)[index].message_raw);
            bms::FLASH_CELLBOARD_2_RX* proto_msg = pack->add_flash_cellboard_2_rx();
            break;
        }
        case 22: {
            bms_message_FLASH_CELLBOARD_3_TX* msg = (bms_message_FLASH_CELLBOARD_3_TX*)(&(*map)[index].message_raw);
            bms::FLASH_CELLBOARD_3_TX* proto_msg = pack->add_flash_cellboard_3_tx();
            break;
        }
        case 23: {
            bms_message_FLASH_CELLBOARD_3_RX* msg = (bms_message_FLASH_CELLBOARD_3_RX*)(&(*map)[index].message_raw);
            bms::FLASH_CELLBOARD_3_RX* proto_msg = pack->add_flash_cellboard_3_rx();
            break;
        }
        case 24: {
            bms_message_FLASH_CELLBOARD_4_TX* msg = (bms_message_FLASH_CELLBOARD_4_TX*)(&(*map)[index].message_raw);
            bms::FLASH_CELLBOARD_4_TX* proto_msg = pack->add_flash_cellboard_4_tx();
            break;
        }
        case 25: {
            bms_message_FLASH_CELLBOARD_4_RX* msg = (bms_message_FLASH_CELLBOARD_4_RX*)(&(*map)[index].message_raw);
            bms::FLASH_CELLBOARD_4_RX* proto_msg = pack->add_flash_cellboard_4_rx();
            break;
        }
        case 26: {
            bms_message_FLASH_CELLBOARD_5_TX* msg = (bms_message_FLASH_CELLBOARD_5_TX*)(&(*map)[index].message_raw);
            bms::FLASH_CELLBOARD_5_TX* proto_msg = pack->add_flash_cellboard_5_tx();
            break;
        }
        case 27: {
            bms_message_FLASH_CELLBOARD_5_RX* msg = (bms_message_FLASH_CELLBOARD_5_RX*)(&(*map)[index].message_raw);
            bms::FLASH_CELLBOARD_5_RX* proto_msg = pack->add_flash_cellboard_5_rx();
            break;
        }
    }
}



#endif // bms_PROTO_INTERAFCE_IMPLEMENTATION

#endif // bms_PROTO_INTERFACE_H