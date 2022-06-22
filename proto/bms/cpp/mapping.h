#ifndef bms_MAPPING_H
#define bms_MAPPING_H

#include <string>
#include <vector>

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
  T inline first() const;
  T inline last() const;
  T operator[](IT index) const;
  IT inline size() const;
  IT inline available() const;
  bool inline empty() const;
  bool inline full() const;
  void inline clear();

 private:
  T buffer[S];
  T *head;
  T *tail;
#ifndef CIRCULAR_BUFFER_INT_SAFE
  IT count;
#else
  volatile IT count;
#endif
};

template <typename T, size_t S, typename IT>
constexpr canlib_circular_buffer<T, S, IT>::canlib_circular_buffer()
    : head(buffer), tail(buffer), count(0) {}

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
T canlib_circular_buffer<T, S, IT>::operator[](IT index) const {
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
#endif // CANLIB_CIRCULAR_BUFFER

#ifndef CANLIB_CIRCULAR_BUFFER_SIZE
#define CANLIB_CIRCULAR_BUFFER_SIZE 500
#endif // CANLIB_CIRCULAR_BUFFER_SIZE

typedef struct {
    canlib_circular_buffer<bms_message_BOARD_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE> BOARD_STATUS_CELLBOARD0;
    canlib_circular_buffer<bms_message_BOARD_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE> BOARD_STATUS_CELLBOARD1;
    canlib_circular_buffer<bms_message_BOARD_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE> BOARD_STATUS_CELLBOARD2;
    canlib_circular_buffer<bms_message_BOARD_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE> BOARD_STATUS_CELLBOARD3;
    canlib_circular_buffer<bms_message_BOARD_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE> BOARD_STATUS_CELLBOARD4;
    canlib_circular_buffer<bms_message_BOARD_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE> BOARD_STATUS_CELLBOARD5;
    canlib_circular_buffer<bms_message_TEMPERATURES_conversion, CANLIB_CIRCULAR_BUFFER_SIZE> TEMPERATURES_CELLBOARD0;
    canlib_circular_buffer<bms_message_TEMPERATURES_conversion, CANLIB_CIRCULAR_BUFFER_SIZE> TEMPERATURES_CELLBOARD1;
    canlib_circular_buffer<bms_message_TEMPERATURES_conversion, CANLIB_CIRCULAR_BUFFER_SIZE> TEMPERATURES_CELLBOARD2;
    canlib_circular_buffer<bms_message_TEMPERATURES_conversion, CANLIB_CIRCULAR_BUFFER_SIZE> TEMPERATURES_CELLBOARD3;
    canlib_circular_buffer<bms_message_TEMPERATURES_conversion, CANLIB_CIRCULAR_BUFFER_SIZE> TEMPERATURES_CELLBOARD4;
    canlib_circular_buffer<bms_message_TEMPERATURES_conversion, CANLIB_CIRCULAR_BUFFER_SIZE> TEMPERATURES_CELLBOARD5;
    canlib_circular_buffer<bms_message_VOLTAGES_conversion, CANLIB_CIRCULAR_BUFFER_SIZE> VOLTAGES_CELLBOARD0;
    canlib_circular_buffer<bms_message_VOLTAGES_conversion, CANLIB_CIRCULAR_BUFFER_SIZE> VOLTAGES_CELLBOARD1;
    canlib_circular_buffer<bms_message_VOLTAGES_conversion, CANLIB_CIRCULAR_BUFFER_SIZE> VOLTAGES_CELLBOARD2;
    canlib_circular_buffer<bms_message_VOLTAGES_conversion, CANLIB_CIRCULAR_BUFFER_SIZE> VOLTAGES_CELLBOARD3;
    canlib_circular_buffer<bms_message_VOLTAGES_conversion, CANLIB_CIRCULAR_BUFFER_SIZE> VOLTAGES_CELLBOARD4;
    canlib_circular_buffer<bms_message_VOLTAGES_conversion, CANLIB_CIRCULAR_BUFFER_SIZE> VOLTAGES_CELLBOARD5;
    canlib_circular_buffer<bms_message_BALANCING, CANLIB_CIRCULAR_BUFFER_SIZE> BALANCING;
    canlib_circular_buffer<bms_message_FW_UPDATE, CANLIB_CIRCULAR_BUFFER_SIZE> FW_UPDATE;
    canlib_circular_buffer<bms_message_FLASH_CELLBOARD_0_TX, CANLIB_CIRCULAR_BUFFER_SIZE> FLASH_CELLBOARD_0_TX;
    canlib_circular_buffer<bms_message_FLASH_CELLBOARD_0_RX, CANLIB_CIRCULAR_BUFFER_SIZE> FLASH_CELLBOARD_0_RX;
    canlib_circular_buffer<bms_message_FLASH_CELLBOARD_1_TX, CANLIB_CIRCULAR_BUFFER_SIZE> FLASH_CELLBOARD_1_TX;
    canlib_circular_buffer<bms_message_FLASH_CELLBOARD_1_RX, CANLIB_CIRCULAR_BUFFER_SIZE> FLASH_CELLBOARD_1_RX;
    canlib_circular_buffer<bms_message_FLASH_CELLBOARD_2_TX, CANLIB_CIRCULAR_BUFFER_SIZE> FLASH_CELLBOARD_2_TX;
    canlib_circular_buffer<bms_message_FLASH_CELLBOARD_2_RX, CANLIB_CIRCULAR_BUFFER_SIZE> FLASH_CELLBOARD_2_RX;
    canlib_circular_buffer<bms_message_FLASH_CELLBOARD_3_TX, CANLIB_CIRCULAR_BUFFER_SIZE> FLASH_CELLBOARD_3_TX;
    canlib_circular_buffer<bms_message_FLASH_CELLBOARD_3_RX, CANLIB_CIRCULAR_BUFFER_SIZE> FLASH_CELLBOARD_3_RX;
    canlib_circular_buffer<bms_message_FLASH_CELLBOARD_4_TX, CANLIB_CIRCULAR_BUFFER_SIZE> FLASH_CELLBOARD_4_TX;
    canlib_circular_buffer<bms_message_FLASH_CELLBOARD_4_RX, CANLIB_CIRCULAR_BUFFER_SIZE> FLASH_CELLBOARD_4_RX;
    canlib_circular_buffer<bms_message_FLASH_CELLBOARD_5_TX, CANLIB_CIRCULAR_BUFFER_SIZE> FLASH_CELLBOARD_5_TX;
    canlib_circular_buffer<bms_message_FLASH_CELLBOARD_5_RX, CANLIB_CIRCULAR_BUFFER_SIZE> FLASH_CELLBOARD_5_RX;
} bms_proto_pack;

void bms_proto_serialize_from_id(canlib_message_id id, bms::Pack* pack, bms_devices* map);
void bms_proto_deserialize(bms::Pack* pack, bms_proto_pack* map);

#ifdef bms_MAPPING_IMPLEMENTATION

void bms_proto_serialize_from_id(canlib_message_id id, bms::Pack* pack, bms_devices* map) {
    int index = bms_index_from_id(id);

    if (index == -1) return;

    switch(id) {
        case 1536: {
            bms_message_BOARD_STATUS* msg = (bms_message_BOARD_STATUS*) (*map)[index].message_raw;
            bms::BOARD_STATUS_CELLBOARD0* proto_msg = pack->add_board_status_cellboard0();
            proto_msg->set_errors(msg->errors);
            proto_msg->set_balancing_status((bms::BalancingStatus)msg->balancing_status);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1568: {
            bms_message_BOARD_STATUS* msg = (bms_message_BOARD_STATUS*) (*map)[index].message_raw;
            bms::BOARD_STATUS_CELLBOARD1* proto_msg = pack->add_board_status_cellboard1();
            proto_msg->set_errors(msg->errors);
            proto_msg->set_balancing_status((bms::BalancingStatus)msg->balancing_status);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1600: {
            bms_message_BOARD_STATUS* msg = (bms_message_BOARD_STATUS*) (*map)[index].message_raw;
            bms::BOARD_STATUS_CELLBOARD2* proto_msg = pack->add_board_status_cellboard2();
            proto_msg->set_errors(msg->errors);
            proto_msg->set_balancing_status((bms::BalancingStatus)msg->balancing_status);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1632: {
            bms_message_BOARD_STATUS* msg = (bms_message_BOARD_STATUS*) (*map)[index].message_raw;
            bms::BOARD_STATUS_CELLBOARD3* proto_msg = pack->add_board_status_cellboard3();
            proto_msg->set_errors(msg->errors);
            proto_msg->set_balancing_status((bms::BalancingStatus)msg->balancing_status);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1664: {
            bms_message_BOARD_STATUS* msg = (bms_message_BOARD_STATUS*) (*map)[index].message_raw;
            bms::BOARD_STATUS_CELLBOARD4* proto_msg = pack->add_board_status_cellboard4();
            proto_msg->set_errors(msg->errors);
            proto_msg->set_balancing_status((bms::BalancingStatus)msg->balancing_status);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1696: {
            bms_message_BOARD_STATUS* msg = (bms_message_BOARD_STATUS*) (*map)[index].message_raw;
            bms::BOARD_STATUS_CELLBOARD5* proto_msg = pack->add_board_status_cellboard5();
            proto_msg->set_errors(msg->errors);
            proto_msg->set_balancing_status((bms::BalancingStatus)msg->balancing_status);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1281: {
            bms_message_TEMPERATURES_conversion* msg = (bms_message_TEMPERATURES_conversion*) (*map)[index].message_conversion;
            bms::TEMPERATURES_CELLBOARD0* proto_msg = pack->add_temperatures_cellboard0();
            proto_msg->set_start_index(msg->start_index);
            proto_msg->set_temp0(msg->temp0);
            proto_msg->set_temp1(msg->temp1);
            proto_msg->set_temp2(msg->temp2);
            proto_msg->set_temp3(msg->temp3);
            proto_msg->set_temp4(msg->temp4);
            proto_msg->set_temp5(msg->temp5);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1313: {
            bms_message_TEMPERATURES_conversion* msg = (bms_message_TEMPERATURES_conversion*) (*map)[index].message_conversion;
            bms::TEMPERATURES_CELLBOARD1* proto_msg = pack->add_temperatures_cellboard1();
            proto_msg->set_start_index(msg->start_index);
            proto_msg->set_temp0(msg->temp0);
            proto_msg->set_temp1(msg->temp1);
            proto_msg->set_temp2(msg->temp2);
            proto_msg->set_temp3(msg->temp3);
            proto_msg->set_temp4(msg->temp4);
            proto_msg->set_temp5(msg->temp5);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1345: {
            bms_message_TEMPERATURES_conversion* msg = (bms_message_TEMPERATURES_conversion*) (*map)[index].message_conversion;
            bms::TEMPERATURES_CELLBOARD2* proto_msg = pack->add_temperatures_cellboard2();
            proto_msg->set_start_index(msg->start_index);
            proto_msg->set_temp0(msg->temp0);
            proto_msg->set_temp1(msg->temp1);
            proto_msg->set_temp2(msg->temp2);
            proto_msg->set_temp3(msg->temp3);
            proto_msg->set_temp4(msg->temp4);
            proto_msg->set_temp5(msg->temp5);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1377: {
            bms_message_TEMPERATURES_conversion* msg = (bms_message_TEMPERATURES_conversion*) (*map)[index].message_conversion;
            bms::TEMPERATURES_CELLBOARD3* proto_msg = pack->add_temperatures_cellboard3();
            proto_msg->set_start_index(msg->start_index);
            proto_msg->set_temp0(msg->temp0);
            proto_msg->set_temp1(msg->temp1);
            proto_msg->set_temp2(msg->temp2);
            proto_msg->set_temp3(msg->temp3);
            proto_msg->set_temp4(msg->temp4);
            proto_msg->set_temp5(msg->temp5);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1409: {
            bms_message_TEMPERATURES_conversion* msg = (bms_message_TEMPERATURES_conversion*) (*map)[index].message_conversion;
            bms::TEMPERATURES_CELLBOARD4* proto_msg = pack->add_temperatures_cellboard4();
            proto_msg->set_start_index(msg->start_index);
            proto_msg->set_temp0(msg->temp0);
            proto_msg->set_temp1(msg->temp1);
            proto_msg->set_temp2(msg->temp2);
            proto_msg->set_temp3(msg->temp3);
            proto_msg->set_temp4(msg->temp4);
            proto_msg->set_temp5(msg->temp5);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1441: {
            bms_message_TEMPERATURES_conversion* msg = (bms_message_TEMPERATURES_conversion*) (*map)[index].message_conversion;
            bms::TEMPERATURES_CELLBOARD5* proto_msg = pack->add_temperatures_cellboard5();
            proto_msg->set_start_index(msg->start_index);
            proto_msg->set_temp0(msg->temp0);
            proto_msg->set_temp1(msg->temp1);
            proto_msg->set_temp2(msg->temp2);
            proto_msg->set_temp3(msg->temp3);
            proto_msg->set_temp4(msg->temp4);
            proto_msg->set_temp5(msg->temp5);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 514: {
            bms_message_VOLTAGES_conversion* msg = (bms_message_VOLTAGES_conversion*) (*map)[index].message_conversion;
            bms::VOLTAGES_CELLBOARD0* proto_msg = pack->add_voltages_cellboard0();
            proto_msg->set_voltage0(msg->voltage0);
            proto_msg->set_voltage1(msg->voltage1);
            proto_msg->set_voltage2(msg->voltage2);
            proto_msg->set_start_index(msg->start_index);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 546: {
            bms_message_VOLTAGES_conversion* msg = (bms_message_VOLTAGES_conversion*) (*map)[index].message_conversion;
            bms::VOLTAGES_CELLBOARD1* proto_msg = pack->add_voltages_cellboard1();
            proto_msg->set_voltage0(msg->voltage0);
            proto_msg->set_voltage1(msg->voltage1);
            proto_msg->set_voltage2(msg->voltage2);
            proto_msg->set_start_index(msg->start_index);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 578: {
            bms_message_VOLTAGES_conversion* msg = (bms_message_VOLTAGES_conversion*) (*map)[index].message_conversion;
            bms::VOLTAGES_CELLBOARD2* proto_msg = pack->add_voltages_cellboard2();
            proto_msg->set_voltage0(msg->voltage0);
            proto_msg->set_voltage1(msg->voltage1);
            proto_msg->set_voltage2(msg->voltage2);
            proto_msg->set_start_index(msg->start_index);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 610: {
            bms_message_VOLTAGES_conversion* msg = (bms_message_VOLTAGES_conversion*) (*map)[index].message_conversion;
            bms::VOLTAGES_CELLBOARD3* proto_msg = pack->add_voltages_cellboard3();
            proto_msg->set_voltage0(msg->voltage0);
            proto_msg->set_voltage1(msg->voltage1);
            proto_msg->set_voltage2(msg->voltage2);
            proto_msg->set_start_index(msg->start_index);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 642: {
            bms_message_VOLTAGES_conversion* msg = (bms_message_VOLTAGES_conversion*) (*map)[index].message_conversion;
            bms::VOLTAGES_CELLBOARD4* proto_msg = pack->add_voltages_cellboard4();
            proto_msg->set_voltage0(msg->voltage0);
            proto_msg->set_voltage1(msg->voltage1);
            proto_msg->set_voltage2(msg->voltage2);
            proto_msg->set_start_index(msg->start_index);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 674: {
            bms_message_VOLTAGES_conversion* msg = (bms_message_VOLTAGES_conversion*) (*map)[index].message_conversion;
            bms::VOLTAGES_CELLBOARD5* proto_msg = pack->add_voltages_cellboard5();
            proto_msg->set_voltage0(msg->voltage0);
            proto_msg->set_voltage1(msg->voltage1);
            proto_msg->set_voltage2(msg->voltage2);
            proto_msg->set_start_index(msg->start_index);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 515: {
            bms_message_BALANCING* msg = (bms_message_BALANCING*) (*map)[index].message_raw;
            bms::BALANCING* proto_msg = pack->add_balancing();
            proto_msg->set_cells(msg->cells);
            proto_msg->set_board_index(msg->board_index);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 10: {
            bms_message_FW_UPDATE* msg = (bms_message_FW_UPDATE*) (*map)[index].message_raw;
            bms::FW_UPDATE* proto_msg = pack->add_fw_update();
            proto_msg->set_board_index(msg->board_index);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 16: {
            bms_message_FLASH_CELLBOARD_0_TX* msg = (bms_message_FLASH_CELLBOARD_0_TX*) (*map)[index].message_raw;
            bms::FLASH_CELLBOARD_0_TX* proto_msg = pack->add_flash_cellboard_0_tx();
            break;
        }

        case 17: {
            bms_message_FLASH_CELLBOARD_0_RX* msg = (bms_message_FLASH_CELLBOARD_0_RX*) (*map)[index].message_raw;
            bms::FLASH_CELLBOARD_0_RX* proto_msg = pack->add_flash_cellboard_0_rx();
            break;
        }

        case 18: {
            bms_message_FLASH_CELLBOARD_1_TX* msg = (bms_message_FLASH_CELLBOARD_1_TX*) (*map)[index].message_raw;
            bms::FLASH_CELLBOARD_1_TX* proto_msg = pack->add_flash_cellboard_1_tx();
            break;
        }

        case 19: {
            bms_message_FLASH_CELLBOARD_1_RX* msg = (bms_message_FLASH_CELLBOARD_1_RX*) (*map)[index].message_raw;
            bms::FLASH_CELLBOARD_1_RX* proto_msg = pack->add_flash_cellboard_1_rx();
            break;
        }

        case 20: {
            bms_message_FLASH_CELLBOARD_2_TX* msg = (bms_message_FLASH_CELLBOARD_2_TX*) (*map)[index].message_raw;
            bms::FLASH_CELLBOARD_2_TX* proto_msg = pack->add_flash_cellboard_2_tx();
            break;
        }

        case 21: {
            bms_message_FLASH_CELLBOARD_2_RX* msg = (bms_message_FLASH_CELLBOARD_2_RX*) (*map)[index].message_raw;
            bms::FLASH_CELLBOARD_2_RX* proto_msg = pack->add_flash_cellboard_2_rx();
            break;
        }

        case 22: {
            bms_message_FLASH_CELLBOARD_3_TX* msg = (bms_message_FLASH_CELLBOARD_3_TX*) (*map)[index].message_raw;
            bms::FLASH_CELLBOARD_3_TX* proto_msg = pack->add_flash_cellboard_3_tx();
            break;
        }

        case 23: {
            bms_message_FLASH_CELLBOARD_3_RX* msg = (bms_message_FLASH_CELLBOARD_3_RX*) (*map)[index].message_raw;
            bms::FLASH_CELLBOARD_3_RX* proto_msg = pack->add_flash_cellboard_3_rx();
            break;
        }

        case 24: {
            bms_message_FLASH_CELLBOARD_4_TX* msg = (bms_message_FLASH_CELLBOARD_4_TX*) (*map)[index].message_raw;
            bms::FLASH_CELLBOARD_4_TX* proto_msg = pack->add_flash_cellboard_4_tx();
            break;
        }

        case 25: {
            bms_message_FLASH_CELLBOARD_4_RX* msg = (bms_message_FLASH_CELLBOARD_4_RX*) (*map)[index].message_raw;
            bms::FLASH_CELLBOARD_4_RX* proto_msg = pack->add_flash_cellboard_4_rx();
            break;
        }

        case 26: {
            bms_message_FLASH_CELLBOARD_5_TX* msg = (bms_message_FLASH_CELLBOARD_5_TX*) (*map)[index].message_raw;
            bms::FLASH_CELLBOARD_5_TX* proto_msg = pack->add_flash_cellboard_5_tx();
            break;
        }

        case 27: {
            bms_message_FLASH_CELLBOARD_5_RX* msg = (bms_message_FLASH_CELLBOARD_5_RX*) (*map)[index].message_raw;
            bms::FLASH_CELLBOARD_5_RX* proto_msg = pack->add_flash_cellboard_5_rx();
            break;
        }

    }
}

void bms_proto_deserialize(bms::Pack* pack, bms_proto_pack* map) {
    for(int i = 0; i < pack->board_status_cellboard0_size(); i++){
        static bms_message_BOARD_STATUS instance;
        instance.errors =pack->board_status_cellboard0(i).errors();
        instance.balancing_status =(bms_BalancingStatus)pack->board_status_cellboard0(i).balancing_status();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->board_status_cellboard0(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->BOARD_STATUS_CELLBOARD0.push(instance);
    }
    for(int i = 0; i < pack->board_status_cellboard1_size(); i++){
        static bms_message_BOARD_STATUS instance;
        instance.errors =pack->board_status_cellboard1(i).errors();
        instance.balancing_status =(bms_BalancingStatus)pack->board_status_cellboard1(i).balancing_status();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->board_status_cellboard1(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->BOARD_STATUS_CELLBOARD1.push(instance);
    }
    for(int i = 0; i < pack->board_status_cellboard2_size(); i++){
        static bms_message_BOARD_STATUS instance;
        instance.errors =pack->board_status_cellboard2(i).errors();
        instance.balancing_status =(bms_BalancingStatus)pack->board_status_cellboard2(i).balancing_status();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->board_status_cellboard2(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->BOARD_STATUS_CELLBOARD2.push(instance);
    }
    for(int i = 0; i < pack->board_status_cellboard3_size(); i++){
        static bms_message_BOARD_STATUS instance;
        instance.errors =pack->board_status_cellboard3(i).errors();
        instance.balancing_status =(bms_BalancingStatus)pack->board_status_cellboard3(i).balancing_status();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->board_status_cellboard3(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->BOARD_STATUS_CELLBOARD3.push(instance);
    }
    for(int i = 0; i < pack->board_status_cellboard4_size(); i++){
        static bms_message_BOARD_STATUS instance;
        instance.errors =pack->board_status_cellboard4(i).errors();
        instance.balancing_status =(bms_BalancingStatus)pack->board_status_cellboard4(i).balancing_status();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->board_status_cellboard4(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->BOARD_STATUS_CELLBOARD4.push(instance);
    }
    for(int i = 0; i < pack->board_status_cellboard5_size(); i++){
        static bms_message_BOARD_STATUS instance;
        instance.errors =pack->board_status_cellboard5(i).errors();
        instance.balancing_status =(bms_BalancingStatus)pack->board_status_cellboard5(i).balancing_status();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->board_status_cellboard5(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->BOARD_STATUS_CELLBOARD5.push(instance);
    }
    for(int i = 0; i < pack->temperatures_cellboard0_size(); i++){
        static bms_message_TEMPERATURES_conversion instance;
        instance.start_index =pack->temperatures_cellboard0(i).start_index();
        instance.temp0 =pack->temperatures_cellboard0(i).temp0();
        instance.temp1 =pack->temperatures_cellboard0(i).temp1();
        instance.temp2 =pack->temperatures_cellboard0(i).temp2();
        instance.temp3 =pack->temperatures_cellboard0(i).temp3();
        instance.temp4 =pack->temperatures_cellboard0(i).temp4();
        instance.temp5 =pack->temperatures_cellboard0(i).temp5();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->temperatures_cellboard0(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->TEMPERATURES_CELLBOARD0.push(instance);
    }
    for(int i = 0; i < pack->temperatures_cellboard1_size(); i++){
        static bms_message_TEMPERATURES_conversion instance;
        instance.start_index =pack->temperatures_cellboard1(i).start_index();
        instance.temp0 =pack->temperatures_cellboard1(i).temp0();
        instance.temp1 =pack->temperatures_cellboard1(i).temp1();
        instance.temp2 =pack->temperatures_cellboard1(i).temp2();
        instance.temp3 =pack->temperatures_cellboard1(i).temp3();
        instance.temp4 =pack->temperatures_cellboard1(i).temp4();
        instance.temp5 =pack->temperatures_cellboard1(i).temp5();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->temperatures_cellboard1(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->TEMPERATURES_CELLBOARD1.push(instance);
    }
    for(int i = 0; i < pack->temperatures_cellboard2_size(); i++){
        static bms_message_TEMPERATURES_conversion instance;
        instance.start_index =pack->temperatures_cellboard2(i).start_index();
        instance.temp0 =pack->temperatures_cellboard2(i).temp0();
        instance.temp1 =pack->temperatures_cellboard2(i).temp1();
        instance.temp2 =pack->temperatures_cellboard2(i).temp2();
        instance.temp3 =pack->temperatures_cellboard2(i).temp3();
        instance.temp4 =pack->temperatures_cellboard2(i).temp4();
        instance.temp5 =pack->temperatures_cellboard2(i).temp5();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->temperatures_cellboard2(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->TEMPERATURES_CELLBOARD2.push(instance);
    }
    for(int i = 0; i < pack->temperatures_cellboard3_size(); i++){
        static bms_message_TEMPERATURES_conversion instance;
        instance.start_index =pack->temperatures_cellboard3(i).start_index();
        instance.temp0 =pack->temperatures_cellboard3(i).temp0();
        instance.temp1 =pack->temperatures_cellboard3(i).temp1();
        instance.temp2 =pack->temperatures_cellboard3(i).temp2();
        instance.temp3 =pack->temperatures_cellboard3(i).temp3();
        instance.temp4 =pack->temperatures_cellboard3(i).temp4();
        instance.temp5 =pack->temperatures_cellboard3(i).temp5();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->temperatures_cellboard3(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->TEMPERATURES_CELLBOARD3.push(instance);
    }
    for(int i = 0; i < pack->temperatures_cellboard4_size(); i++){
        static bms_message_TEMPERATURES_conversion instance;
        instance.start_index =pack->temperatures_cellboard4(i).start_index();
        instance.temp0 =pack->temperatures_cellboard4(i).temp0();
        instance.temp1 =pack->temperatures_cellboard4(i).temp1();
        instance.temp2 =pack->temperatures_cellboard4(i).temp2();
        instance.temp3 =pack->temperatures_cellboard4(i).temp3();
        instance.temp4 =pack->temperatures_cellboard4(i).temp4();
        instance.temp5 =pack->temperatures_cellboard4(i).temp5();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->temperatures_cellboard4(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->TEMPERATURES_CELLBOARD4.push(instance);
    }
    for(int i = 0; i < pack->temperatures_cellboard5_size(); i++){
        static bms_message_TEMPERATURES_conversion instance;
        instance.start_index =pack->temperatures_cellboard5(i).start_index();
        instance.temp0 =pack->temperatures_cellboard5(i).temp0();
        instance.temp1 =pack->temperatures_cellboard5(i).temp1();
        instance.temp2 =pack->temperatures_cellboard5(i).temp2();
        instance.temp3 =pack->temperatures_cellboard5(i).temp3();
        instance.temp4 =pack->temperatures_cellboard5(i).temp4();
        instance.temp5 =pack->temperatures_cellboard5(i).temp5();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->temperatures_cellboard5(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->TEMPERATURES_CELLBOARD5.push(instance);
    }
    for(int i = 0; i < pack->voltages_cellboard0_size(); i++){
        static bms_message_VOLTAGES_conversion instance;
        instance.voltage0 =pack->voltages_cellboard0(i).voltage0();
        instance.voltage1 =pack->voltages_cellboard0(i).voltage1();
        instance.voltage2 =pack->voltages_cellboard0(i).voltage2();
        instance.start_index =pack->voltages_cellboard0(i).start_index();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->voltages_cellboard0(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->VOLTAGES_CELLBOARD0.push(instance);
    }
    for(int i = 0; i < pack->voltages_cellboard1_size(); i++){
        static bms_message_VOLTAGES_conversion instance;
        instance.voltage0 =pack->voltages_cellboard1(i).voltage0();
        instance.voltage1 =pack->voltages_cellboard1(i).voltage1();
        instance.voltage2 =pack->voltages_cellboard1(i).voltage2();
        instance.start_index =pack->voltages_cellboard1(i).start_index();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->voltages_cellboard1(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->VOLTAGES_CELLBOARD1.push(instance);
    }
    for(int i = 0; i < pack->voltages_cellboard2_size(); i++){
        static bms_message_VOLTAGES_conversion instance;
        instance.voltage0 =pack->voltages_cellboard2(i).voltage0();
        instance.voltage1 =pack->voltages_cellboard2(i).voltage1();
        instance.voltage2 =pack->voltages_cellboard2(i).voltage2();
        instance.start_index =pack->voltages_cellboard2(i).start_index();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->voltages_cellboard2(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->VOLTAGES_CELLBOARD2.push(instance);
    }
    for(int i = 0; i < pack->voltages_cellboard3_size(); i++){
        static bms_message_VOLTAGES_conversion instance;
        instance.voltage0 =pack->voltages_cellboard3(i).voltage0();
        instance.voltage1 =pack->voltages_cellboard3(i).voltage1();
        instance.voltage2 =pack->voltages_cellboard3(i).voltage2();
        instance.start_index =pack->voltages_cellboard3(i).start_index();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->voltages_cellboard3(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->VOLTAGES_CELLBOARD3.push(instance);
    }
    for(int i = 0; i < pack->voltages_cellboard4_size(); i++){
        static bms_message_VOLTAGES_conversion instance;
        instance.voltage0 =pack->voltages_cellboard4(i).voltage0();
        instance.voltage1 =pack->voltages_cellboard4(i).voltage1();
        instance.voltage2 =pack->voltages_cellboard4(i).voltage2();
        instance.start_index =pack->voltages_cellboard4(i).start_index();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->voltages_cellboard4(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->VOLTAGES_CELLBOARD4.push(instance);
    }
    for(int i = 0; i < pack->voltages_cellboard5_size(); i++){
        static bms_message_VOLTAGES_conversion instance;
        instance.voltage0 =pack->voltages_cellboard5(i).voltage0();
        instance.voltage1 =pack->voltages_cellboard5(i).voltage1();
        instance.voltage2 =pack->voltages_cellboard5(i).voltage2();
        instance.start_index =pack->voltages_cellboard5(i).start_index();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->voltages_cellboard5(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->VOLTAGES_CELLBOARD5.push(instance);
    }
    for(int i = 0; i < pack->balancing_size(); i++){
        static bms_message_BALANCING instance;
        instance.cells =pack->balancing(i).cells();
        instance.board_index =pack->balancing(i).board_index();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->balancing(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->BALANCING.push(instance);
    }
    for(int i = 0; i < pack->fw_update_size(); i++){
        static bms_message_FW_UPDATE instance;
        instance.board_index =pack->fw_update(i).board_index();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->fw_update(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->FW_UPDATE.push(instance);
    }
    for(int i = 0; i < pack->flash_cellboard_0_tx_size(); i++){
        static bms_message_FLASH_CELLBOARD_0_TX instance;
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->flash_cellboard_0_tx(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->FLASH_CELLBOARD_0_TX.push(instance);
    }
    for(int i = 0; i < pack->flash_cellboard_0_rx_size(); i++){
        static bms_message_FLASH_CELLBOARD_0_RX instance;
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->flash_cellboard_0_rx(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->FLASH_CELLBOARD_0_RX.push(instance);
    }
    for(int i = 0; i < pack->flash_cellboard_1_tx_size(); i++){
        static bms_message_FLASH_CELLBOARD_1_TX instance;
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->flash_cellboard_1_tx(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->FLASH_CELLBOARD_1_TX.push(instance);
    }
    for(int i = 0; i < pack->flash_cellboard_1_rx_size(); i++){
        static bms_message_FLASH_CELLBOARD_1_RX instance;
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->flash_cellboard_1_rx(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->FLASH_CELLBOARD_1_RX.push(instance);
    }
    for(int i = 0; i < pack->flash_cellboard_2_tx_size(); i++){
        static bms_message_FLASH_CELLBOARD_2_TX instance;
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->flash_cellboard_2_tx(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->FLASH_CELLBOARD_2_TX.push(instance);
    }
    for(int i = 0; i < pack->flash_cellboard_2_rx_size(); i++){
        static bms_message_FLASH_CELLBOARD_2_RX instance;
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->flash_cellboard_2_rx(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->FLASH_CELLBOARD_2_RX.push(instance);
    }
    for(int i = 0; i < pack->flash_cellboard_3_tx_size(); i++){
        static bms_message_FLASH_CELLBOARD_3_TX instance;
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->flash_cellboard_3_tx(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->FLASH_CELLBOARD_3_TX.push(instance);
    }
    for(int i = 0; i < pack->flash_cellboard_3_rx_size(); i++){
        static bms_message_FLASH_CELLBOARD_3_RX instance;
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->flash_cellboard_3_rx(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->FLASH_CELLBOARD_3_RX.push(instance);
    }
    for(int i = 0; i < pack->flash_cellboard_4_tx_size(); i++){
        static bms_message_FLASH_CELLBOARD_4_TX instance;
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->flash_cellboard_4_tx(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->FLASH_CELLBOARD_4_TX.push(instance);
    }
    for(int i = 0; i < pack->flash_cellboard_4_rx_size(); i++){
        static bms_message_FLASH_CELLBOARD_4_RX instance;
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->flash_cellboard_4_rx(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->FLASH_CELLBOARD_4_RX.push(instance);
    }
    for(int i = 0; i < pack->flash_cellboard_5_tx_size(); i++){
        static bms_message_FLASH_CELLBOARD_5_TX instance;
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->flash_cellboard_5_tx(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->FLASH_CELLBOARD_5_TX.push(instance);
    }
    for(int i = 0; i < pack->flash_cellboard_5_rx_size(); i++){
        static bms_message_FLASH_CELLBOARD_5_RX instance;
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->flash_cellboard_5_rx(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->FLASH_CELLBOARD_5_RX.push(instance);
    }
}

#endif // bms_MAPPING_IMPLEMENTATION

#endif // bms_MAPPING_H