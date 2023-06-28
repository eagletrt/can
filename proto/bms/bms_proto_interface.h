
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

#include "../../lib/bms/bms_network.h"

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

void bms_proto_interface_serialize_from_id(canlib_message_id id, bms::Pack* pack, device_t* device);
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
		bms_board_status_cellboard_id_enum_to_string((bms_board_status_cellboard_id)pack->board_status(i).cellboard_id(), buffer);
		(*net_strings)["BOARD_STATUS"]["cellboard_id"].push(buffer);
		(*net_enums)["BOARD_STATUS"]["errors_can_comm"].push(pack->board_status(i).errors_can_comm());
		(*net_enums)["BOARD_STATUS"]["errors_ltc_comm"].push(pack->board_status(i).errors_ltc_comm());
		(*net_enums)["BOARD_STATUS"]["errors_temp_comm_0"].push(pack->board_status(i).errors_temp_comm_0());
		(*net_enums)["BOARD_STATUS"]["errors_temp_comm_1"].push(pack->board_status(i).errors_temp_comm_1());
		(*net_enums)["BOARD_STATUS"]["errors_temp_comm_2"].push(pack->board_status(i).errors_temp_comm_2());
		(*net_enums)["BOARD_STATUS"]["errors_temp_comm_3"].push(pack->board_status(i).errors_temp_comm_3());
		(*net_enums)["BOARD_STATUS"]["errors_temp_comm_4"].push(pack->board_status(i).errors_temp_comm_4());
		(*net_enums)["BOARD_STATUS"]["errors_temp_comm_5"].push(pack->board_status(i).errors_temp_comm_5());
		(*net_enums)["BOARD_STATUS"]["errors_open_wire"].push(pack->board_status(i).errors_open_wire());
		(*net_enums)["BOARD_STATUS"]["balancing_status"].push(pack->board_status(i).balancing_status());
		bms_board_status_balancing_status_enum_to_string((bms_board_status_balancing_status)pack->board_status(i).balancing_status(), buffer);
		(*net_strings)["BOARD_STATUS"]["balancing_status"].push(buffer);

    }

    for(int i = 0; i < pack->temperatures_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->temperatures(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->temperatures(i)._inner_timestamp();
        (*net_signals)["TEMPERATURES"]["_timestamp"].push(pack->temperatures(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["TEMPERATURES"]["cellboard_id"].push(pack->temperatures(i).cellboard_id());
		bms_temperatures_cellboard_id_enum_to_string((bms_temperatures_cellboard_id)pack->temperatures(i).cellboard_id(), buffer);
		(*net_strings)["TEMPERATURES"]["cellboard_id"].push(buffer);
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
		bms_voltages_cellboard_id_enum_to_string((bms_voltages_cellboard_id)pack->voltages(i).cellboard_id(), buffer);
		(*net_strings)["VOLTAGES"]["cellboard_id"].push(buffer);
		(*net_signals)["VOLTAGES"]["start_index"].push(pack->voltages(i).start_index());
		(*net_signals)["VOLTAGES"]["voltage0"].push(pack->voltages(i).voltage0());
		(*net_signals)["VOLTAGES"]["voltage1"].push(pack->voltages(i).voltage1());
		(*net_signals)["VOLTAGES"]["voltage2"].push(pack->voltages(i).voltage2());

    }

    for(int i = 0; i < pack->set_balancing_status_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->set_balancing_status(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->set_balancing_status(i)._inner_timestamp();
        (*net_signals)["SET_BALANCING_STATUS"]["_timestamp"].push(pack->set_balancing_status(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["SET_BALANCING_STATUS"]["threshold"].push(pack->set_balancing_status(i).threshold());
		(*net_signals)["SET_BALANCING_STATUS"]["target"].push(pack->set_balancing_status(i).target());
		(*net_enums)["SET_BALANCING_STATUS"]["balancing_status"].push(pack->set_balancing_status(i).balancing_status());
		bms_set_balancing_status_balancing_status_enum_to_string((bms_set_balancing_status_balancing_status)pack->set_balancing_status(i).balancing_status(), buffer);
		(*net_strings)["SET_BALANCING_STATUS"]["balancing_status"].push(buffer);

    }

    for(int i = 0; i < pack->jmp_to_blt_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->jmp_to_blt(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->jmp_to_blt(i)._inner_timestamp();
        (*net_signals)["JMP_TO_BLT"]["_timestamp"].push(pack->jmp_to_blt(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["JMP_TO_BLT"]["cellboard_id"].push(pack->jmp_to_blt(i).cellboard_id());
		bms_jmp_to_blt_cellboard_id_enum_to_string((bms_jmp_to_blt_cellboard_id)pack->jmp_to_blt(i).cellboard_id(), buffer);
		(*net_strings)["JMP_TO_BLT"]["cellboard_id"].push(buffer);
		(*net_signals)["JMP_TO_BLT"]["board_index"].push(pack->jmp_to_blt(i).board_index());

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

void bms_proto_interface_serialize_from_id(canlib_message_id id, bms::Pack* pack, device_t* device) {
    int index = bms_index_from_id(id);

    if (index == -1) return;

    switch(id) {
        
        case 1539: {
            bms_board_status_t* msg = (bms_board_status_t*)(device->message);
            bms::BOARD_STATUS* proto_msg = pack->add_board_status();
			proto_msg->set_cellboard_id((bms::bms_board_status_cellboard_id)msg->cellboard_id);
			proto_msg->set_errors_can_comm(msg->errors_can_comm);
			proto_msg->set_errors_ltc_comm(msg->errors_ltc_comm);
			proto_msg->set_errors_temp_comm_0(msg->errors_temp_comm_0);
			proto_msg->set_errors_temp_comm_1(msg->errors_temp_comm_1);
			proto_msg->set_errors_temp_comm_2(msg->errors_temp_comm_2);
			proto_msg->set_errors_temp_comm_3(msg->errors_temp_comm_3);
			proto_msg->set_errors_temp_comm_4(msg->errors_temp_comm_4);
			proto_msg->set_errors_temp_comm_5(msg->errors_temp_comm_5);
			proto_msg->set_errors_open_wire(msg->errors_open_wire);
			proto_msg->set_balancing_status((bms::bms_board_status_balancing_status)msg->balancing_status);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1281: {
            bms_temperatures_converted_t* msg = (bms_temperatures_converted_t*)(device->message);
            bms::TEMPERATURES* proto_msg = pack->add_temperatures();
			proto_msg->set_cellboard_id((bms::bms_temperatures_cellboard_id)msg->cellboard_id);
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
            bms_voltages_converted_t* msg = (bms_voltages_converted_t*)(device->message);
            bms::VOLTAGES* proto_msg = pack->add_voltages();
			proto_msg->set_cellboard_id((bms::bms_voltages_cellboard_id)msg->cellboard_id);
			proto_msg->set_start_index(msg->start_index);
			proto_msg->set_voltage0(msg->voltage0);
			proto_msg->set_voltage1(msg->voltage1);
			proto_msg->set_voltage2(msg->voltage2);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 512: {
            bms_set_balancing_status_t* msg = (bms_set_balancing_status_t*)(device->message);
            bms::SET_BALANCING_STATUS* proto_msg = pack->add_set_balancing_status();
			proto_msg->set_threshold(msg->threshold);
			proto_msg->set_target(msg->target);
			proto_msg->set_balancing_status((bms::bms_set_balancing_status_balancing_status)msg->balancing_status);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 0: {
            bms_jmp_to_blt_t* msg = (bms_jmp_to_blt_t*)(device->message);
            bms::JMP_TO_BLT* proto_msg = pack->add_jmp_to_blt();
			proto_msg->set_cellboard_id((bms::bms_jmp_to_blt_cellboard_id)msg->cellboard_id);
			proto_msg->set_board_index(msg->board_index);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 4: {
            bms_flash_cellboard_0_tx_t* msg = (bms_flash_cellboard_0_tx_t*)(device->message);
            bms::FLASH_CELLBOARD_0_TX* proto_msg = pack->add_flash_cellboard_0_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 5: {
            bms_flash_cellboard_0_rx_t* msg = (bms_flash_cellboard_0_rx_t*)(device->message);
            bms::FLASH_CELLBOARD_0_RX* proto_msg = pack->add_flash_cellboard_0_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 6: {
            bms_flash_cellboard_1_tx_t* msg = (bms_flash_cellboard_1_tx_t*)(device->message);
            bms::FLASH_CELLBOARD_1_TX* proto_msg = pack->add_flash_cellboard_1_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 7: {
            bms_flash_cellboard_1_rx_t* msg = (bms_flash_cellboard_1_rx_t*)(device->message);
            bms::FLASH_CELLBOARD_1_RX* proto_msg = pack->add_flash_cellboard_1_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 8: {
            bms_flash_cellboard_2_tx_t* msg = (bms_flash_cellboard_2_tx_t*)(device->message);
            bms::FLASH_CELLBOARD_2_TX* proto_msg = pack->add_flash_cellboard_2_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 9: {
            bms_flash_cellboard_2_rx_t* msg = (bms_flash_cellboard_2_rx_t*)(device->message);
            bms::FLASH_CELLBOARD_2_RX* proto_msg = pack->add_flash_cellboard_2_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 10: {
            bms_flash_cellboard_3_tx_t* msg = (bms_flash_cellboard_3_tx_t*)(device->message);
            bms::FLASH_CELLBOARD_3_TX* proto_msg = pack->add_flash_cellboard_3_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 11: {
            bms_flash_cellboard_3_rx_t* msg = (bms_flash_cellboard_3_rx_t*)(device->message);
            bms::FLASH_CELLBOARD_3_RX* proto_msg = pack->add_flash_cellboard_3_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 12: {
            bms_flash_cellboard_4_tx_t* msg = (bms_flash_cellboard_4_tx_t*)(device->message);
            bms::FLASH_CELLBOARD_4_TX* proto_msg = pack->add_flash_cellboard_4_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 13: {
            bms_flash_cellboard_4_rx_t* msg = (bms_flash_cellboard_4_rx_t*)(device->message);
            bms::FLASH_CELLBOARD_4_RX* proto_msg = pack->add_flash_cellboard_4_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 14: {
            bms_flash_cellboard_5_tx_t* msg = (bms_flash_cellboard_5_tx_t*)(device->message);
            bms::FLASH_CELLBOARD_5_TX* proto_msg = pack->add_flash_cellboard_5_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 15: {
            bms_flash_cellboard_5_rx_t* msg = (bms_flash_cellboard_5_rx_t*)(device->message);
            bms::FLASH_CELLBOARD_5_RX* proto_msg = pack->add_flash_cellboard_5_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

    }
}



#endif // bms_PROTO_INTERAFCE_IMPLEMENTATION

#endif // bms_PROTO_INTERFACE_H
