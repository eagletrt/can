#ifndef bms_MAPPING_H
#define bms_MAPPING_H

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
#define CANLIB_CIRCULAR_BUFFER_SIZE 500
#endif // CANLIB_CIRCULAR_BUFFER_SIZE


#ifndef CANLIB_MAPPING_ADAPTOR
#define CANLIB_MAPPING_ADAPTOR

union mapping_union{
    const int* _int;
    const bool* _bool;
    const float* _float32;
    const double* _float64;

    const int8_t* _int8;
    const int16_t* _int16;
    const int32_t* _int32;
    const int64_t* _int64;

    const uint8_t* _uint8;
    const uint16_t* _uint16;
    const uint32_t* _uint32;
    const uint64_t* _uint64;

    const char* _char;
};

enum mapping_type{
    mapping_type_int,
    mapping_type_bool,
    mapping_type_float32,
    mapping_type_float64,
    mapping_type_int8,
    mapping_type_int16,
    mapping_type_int32,
    mapping_type_int64,
    mapping_type_uint8,
    mapping_type_uint16,
    mapping_type_uint32,
    mapping_type_uint64,
    mapping_type_char,
    mapping_type_none
};

struct mapping_element_t{
    mapping_union value;
    mapping_type type;
};

struct message_element_t{
  std::unordered_map<std::string, mapping_element_t> field;
  size_t stride;
  std::function<size_t()> size;
  std::function<size_t()> offset;
};

typedef std::unordered_map<std::string, message_element_t> mapping_adaptor;

#endif // CANLIB_MAPPING_ADAPTOR

typedef struct {
    canlib_circular_buffer<bms_message_BOARD_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE> BOARD_STATUS;
    canlib_circular_buffer<bms_message_TEMPERATURES_conversion, CANLIB_CIRCULAR_BUFFER_SIZE> TEMPERATURES;
    canlib_circular_buffer<bms_message_VOLTAGES_conversion, CANLIB_CIRCULAR_BUFFER_SIZE> VOLTAGES;
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

void bms_mapping_adaptor_construct(const bms_proto_pack& pack, mapping_adaptor& mapping_map);
void bms_proto_serialize_from_id(canlib_message_id id, bms::Pack* pack, bms_devices* map);
void bms_proto_deserialize(bms::Pack* pack, bms_proto_pack* map, uint64_t resample_us);

#ifdef bms_MAPPING_IMPLEMENTATION

void bms_mapping_adaptor_construct(const bms_proto_pack& pack, mapping_adaptor& mapping_map){
    mapping_map["BOARD_STATUS"].size = std::bind(&canlib_circular_buffer<bms_message_BOARD_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.BOARD_STATUS);
    mapping_map["BOARD_STATUS"].offset = std::bind(&canlib_circular_buffer<bms_message_BOARD_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.BOARD_STATUS);
    mapping_map["BOARD_STATUS"].stride = sizeof(bms_message_BOARD_STATUS);
    mapping_map["BOARD_STATUS"].field["cellboard_id"].value._uint16 = (uint16_t*)&pack.BOARD_STATUS.start().cellboard_id;
    mapping_map["BOARD_STATUS"].field["cellboard_id"].type = mapping_type_uint16;
    mapping_map["BOARD_STATUS"].field["errors"].value._uint16 = (uint16_t*)&pack.BOARD_STATUS.start().errors;
    mapping_map["BOARD_STATUS"].field["errors"].type = mapping_type_uint16;
    mapping_map["BOARD_STATUS"].field["balancing_status"].value._uint16 = (uint16_t*)&pack.BOARD_STATUS.start().balancing_status;
    mapping_map["BOARD_STATUS"].field["balancing_status"].type = mapping_type_uint16;
#ifdef CANLIB_TIMESTAMP
    mapping_map["BOARD_STATUS"].field["_timestamp"].value._uint64 = &pack.BOARD_STATUS.start()._timestamp;
    mapping_map["BOARD_STATUS"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["TEMPERATURES"].size = std::bind(&canlib_circular_buffer<bms_message_TEMPERATURES_conversion, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.TEMPERATURES);
    mapping_map["TEMPERATURES"].offset = std::bind(&canlib_circular_buffer<bms_message_TEMPERATURES_conversion, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.TEMPERATURES);
    mapping_map["TEMPERATURES"].stride = sizeof(bms_message_TEMPERATURES_conversion);
    mapping_map["TEMPERATURES"].field["cellboard_id"].value._uint16 = (uint16_t*)&pack.TEMPERATURES.start().cellboard_id;
    mapping_map["TEMPERATURES"].field["cellboard_id"].type = mapping_type_uint16;
    mapping_map["TEMPERATURES"].field["start_index"].value._uint8 = &pack.TEMPERATURES.start().start_index;
    mapping_map["TEMPERATURES"].field["start_index"].type = mapping_type_uint8;
    mapping_map["TEMPERATURES"].field["temp0"].value._float32 = &pack.TEMPERATURES.start().temp0;
    mapping_map["TEMPERATURES"].field["temp0"].type = mapping_type_float32;
    mapping_map["TEMPERATURES"].field["temp1"].value._float32 = &pack.TEMPERATURES.start().temp1;
    mapping_map["TEMPERATURES"].field["temp1"].type = mapping_type_float32;
    mapping_map["TEMPERATURES"].field["temp2"].value._float32 = &pack.TEMPERATURES.start().temp2;
    mapping_map["TEMPERATURES"].field["temp2"].type = mapping_type_float32;
    mapping_map["TEMPERATURES"].field["temp3"].value._float32 = &pack.TEMPERATURES.start().temp3;
    mapping_map["TEMPERATURES"].field["temp3"].type = mapping_type_float32;
#ifdef CANLIB_TIMESTAMP
    mapping_map["TEMPERATURES"].field["_timestamp"].value._uint64 = &pack.TEMPERATURES.start()._timestamp;
    mapping_map["TEMPERATURES"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["VOLTAGES"].size = std::bind(&canlib_circular_buffer<bms_message_VOLTAGES_conversion, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.VOLTAGES);
    mapping_map["VOLTAGES"].offset = std::bind(&canlib_circular_buffer<bms_message_VOLTAGES_conversion, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.VOLTAGES);
    mapping_map["VOLTAGES"].stride = sizeof(bms_message_VOLTAGES_conversion);
    mapping_map["VOLTAGES"].field["cellboard_id"].value._uint16 = (uint16_t*)&pack.VOLTAGES.start().cellboard_id;
    mapping_map["VOLTAGES"].field["cellboard_id"].type = mapping_type_uint16;
    mapping_map["VOLTAGES"].field["start_index"].value._uint8 = &pack.VOLTAGES.start().start_index;
    mapping_map["VOLTAGES"].field["start_index"].type = mapping_type_uint8;
    mapping_map["VOLTAGES"].field["voltage0"].value._float32 = &pack.VOLTAGES.start().voltage0;
    mapping_map["VOLTAGES"].field["voltage0"].type = mapping_type_float32;
    mapping_map["VOLTAGES"].field["voltage1"].value._float32 = &pack.VOLTAGES.start().voltage1;
    mapping_map["VOLTAGES"].field["voltage1"].type = mapping_type_float32;
    mapping_map["VOLTAGES"].field["voltage2"].value._float32 = &pack.VOLTAGES.start().voltage2;
    mapping_map["VOLTAGES"].field["voltage2"].type = mapping_type_float32;
#ifdef CANLIB_TIMESTAMP
    mapping_map["VOLTAGES"].field["_timestamp"].value._uint64 = &pack.VOLTAGES.start()._timestamp;
    mapping_map["VOLTAGES"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["BALANCING"].size = std::bind(&canlib_circular_buffer<bms_message_BALANCING, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.BALANCING);
    mapping_map["BALANCING"].offset = std::bind(&canlib_circular_buffer<bms_message_BALANCING, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.BALANCING);
    mapping_map["BALANCING"].stride = sizeof(bms_message_BALANCING);
    mapping_map["BALANCING"].field["cellboard_id"].value._uint16 = (uint16_t*)&pack.BALANCING.start().cellboard_id;
    mapping_map["BALANCING"].field["cellboard_id"].type = mapping_type_uint16;
    mapping_map["BALANCING"].field["board_index"].value._uint8 = &pack.BALANCING.start().board_index;
    mapping_map["BALANCING"].field["board_index"].type = mapping_type_uint8;
    mapping_map["BALANCING"].field["cells"].value._uint16 = (uint16_t*)&pack.BALANCING.start().cells;
    mapping_map["BALANCING"].field["cells"].type = mapping_type_uint16;
#ifdef CANLIB_TIMESTAMP
    mapping_map["BALANCING"].field["_timestamp"].value._uint64 = &pack.BALANCING.start()._timestamp;
    mapping_map["BALANCING"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["FW_UPDATE"].size = std::bind(&canlib_circular_buffer<bms_message_FW_UPDATE, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.FW_UPDATE);
    mapping_map["FW_UPDATE"].offset = std::bind(&canlib_circular_buffer<bms_message_FW_UPDATE, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.FW_UPDATE);
    mapping_map["FW_UPDATE"].stride = sizeof(bms_message_FW_UPDATE);
    mapping_map["FW_UPDATE"].field["cellboard_id"].value._uint16 = (uint16_t*)&pack.FW_UPDATE.start().cellboard_id;
    mapping_map["FW_UPDATE"].field["cellboard_id"].type = mapping_type_uint16;
    mapping_map["FW_UPDATE"].field["board_index"].value._uint8 = &pack.FW_UPDATE.start().board_index;
    mapping_map["FW_UPDATE"].field["board_index"].type = mapping_type_uint8;
#ifdef CANLIB_TIMESTAMP
    mapping_map["FW_UPDATE"].field["_timestamp"].value._uint64 = &pack.FW_UPDATE.start()._timestamp;
    mapping_map["FW_UPDATE"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["FLASH_CELLBOARD_0_TX"].size = std::bind(&canlib_circular_buffer<bms_message_FLASH_CELLBOARD_0_TX, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.FLASH_CELLBOARD_0_TX);
    mapping_map["FLASH_CELLBOARD_0_TX"].offset = std::bind(&canlib_circular_buffer<bms_message_FLASH_CELLBOARD_0_TX, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.FLASH_CELLBOARD_0_TX);
    mapping_map["FLASH_CELLBOARD_0_TX"].stride = sizeof(bms_message_FLASH_CELLBOARD_0_TX);
#ifdef CANLIB_TIMESTAMP
    mapping_map["FLASH_CELLBOARD_0_TX"].field["_timestamp"].value._uint64 = &pack.FLASH_CELLBOARD_0_TX.start()._timestamp;
    mapping_map["FLASH_CELLBOARD_0_TX"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["FLASH_CELLBOARD_0_RX"].size = std::bind(&canlib_circular_buffer<bms_message_FLASH_CELLBOARD_0_RX, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.FLASH_CELLBOARD_0_RX);
    mapping_map["FLASH_CELLBOARD_0_RX"].offset = std::bind(&canlib_circular_buffer<bms_message_FLASH_CELLBOARD_0_RX, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.FLASH_CELLBOARD_0_RX);
    mapping_map["FLASH_CELLBOARD_0_RX"].stride = sizeof(bms_message_FLASH_CELLBOARD_0_RX);
#ifdef CANLIB_TIMESTAMP
    mapping_map["FLASH_CELLBOARD_0_RX"].field["_timestamp"].value._uint64 = &pack.FLASH_CELLBOARD_0_RX.start()._timestamp;
    mapping_map["FLASH_CELLBOARD_0_RX"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["FLASH_CELLBOARD_1_TX"].size = std::bind(&canlib_circular_buffer<bms_message_FLASH_CELLBOARD_1_TX, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.FLASH_CELLBOARD_1_TX);
    mapping_map["FLASH_CELLBOARD_1_TX"].offset = std::bind(&canlib_circular_buffer<bms_message_FLASH_CELLBOARD_1_TX, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.FLASH_CELLBOARD_1_TX);
    mapping_map["FLASH_CELLBOARD_1_TX"].stride = sizeof(bms_message_FLASH_CELLBOARD_1_TX);
#ifdef CANLIB_TIMESTAMP
    mapping_map["FLASH_CELLBOARD_1_TX"].field["_timestamp"].value._uint64 = &pack.FLASH_CELLBOARD_1_TX.start()._timestamp;
    mapping_map["FLASH_CELLBOARD_1_TX"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["FLASH_CELLBOARD_1_RX"].size = std::bind(&canlib_circular_buffer<bms_message_FLASH_CELLBOARD_1_RX, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.FLASH_CELLBOARD_1_RX);
    mapping_map["FLASH_CELLBOARD_1_RX"].offset = std::bind(&canlib_circular_buffer<bms_message_FLASH_CELLBOARD_1_RX, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.FLASH_CELLBOARD_1_RX);
    mapping_map["FLASH_CELLBOARD_1_RX"].stride = sizeof(bms_message_FLASH_CELLBOARD_1_RX);
#ifdef CANLIB_TIMESTAMP
    mapping_map["FLASH_CELLBOARD_1_RX"].field["_timestamp"].value._uint64 = &pack.FLASH_CELLBOARD_1_RX.start()._timestamp;
    mapping_map["FLASH_CELLBOARD_1_RX"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["FLASH_CELLBOARD_2_TX"].size = std::bind(&canlib_circular_buffer<bms_message_FLASH_CELLBOARD_2_TX, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.FLASH_CELLBOARD_2_TX);
    mapping_map["FLASH_CELLBOARD_2_TX"].offset = std::bind(&canlib_circular_buffer<bms_message_FLASH_CELLBOARD_2_TX, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.FLASH_CELLBOARD_2_TX);
    mapping_map["FLASH_CELLBOARD_2_TX"].stride = sizeof(bms_message_FLASH_CELLBOARD_2_TX);
#ifdef CANLIB_TIMESTAMP
    mapping_map["FLASH_CELLBOARD_2_TX"].field["_timestamp"].value._uint64 = &pack.FLASH_CELLBOARD_2_TX.start()._timestamp;
    mapping_map["FLASH_CELLBOARD_2_TX"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["FLASH_CELLBOARD_2_RX"].size = std::bind(&canlib_circular_buffer<bms_message_FLASH_CELLBOARD_2_RX, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.FLASH_CELLBOARD_2_RX);
    mapping_map["FLASH_CELLBOARD_2_RX"].offset = std::bind(&canlib_circular_buffer<bms_message_FLASH_CELLBOARD_2_RX, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.FLASH_CELLBOARD_2_RX);
    mapping_map["FLASH_CELLBOARD_2_RX"].stride = sizeof(bms_message_FLASH_CELLBOARD_2_RX);
#ifdef CANLIB_TIMESTAMP
    mapping_map["FLASH_CELLBOARD_2_RX"].field["_timestamp"].value._uint64 = &pack.FLASH_CELLBOARD_2_RX.start()._timestamp;
    mapping_map["FLASH_CELLBOARD_2_RX"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["FLASH_CELLBOARD_3_TX"].size = std::bind(&canlib_circular_buffer<bms_message_FLASH_CELLBOARD_3_TX, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.FLASH_CELLBOARD_3_TX);
    mapping_map["FLASH_CELLBOARD_3_TX"].offset = std::bind(&canlib_circular_buffer<bms_message_FLASH_CELLBOARD_3_TX, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.FLASH_CELLBOARD_3_TX);
    mapping_map["FLASH_CELLBOARD_3_TX"].stride = sizeof(bms_message_FLASH_CELLBOARD_3_TX);
#ifdef CANLIB_TIMESTAMP
    mapping_map["FLASH_CELLBOARD_3_TX"].field["_timestamp"].value._uint64 = &pack.FLASH_CELLBOARD_3_TX.start()._timestamp;
    mapping_map["FLASH_CELLBOARD_3_TX"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["FLASH_CELLBOARD_3_RX"].size = std::bind(&canlib_circular_buffer<bms_message_FLASH_CELLBOARD_3_RX, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.FLASH_CELLBOARD_3_RX);
    mapping_map["FLASH_CELLBOARD_3_RX"].offset = std::bind(&canlib_circular_buffer<bms_message_FLASH_CELLBOARD_3_RX, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.FLASH_CELLBOARD_3_RX);
    mapping_map["FLASH_CELLBOARD_3_RX"].stride = sizeof(bms_message_FLASH_CELLBOARD_3_RX);
#ifdef CANLIB_TIMESTAMP
    mapping_map["FLASH_CELLBOARD_3_RX"].field["_timestamp"].value._uint64 = &pack.FLASH_CELLBOARD_3_RX.start()._timestamp;
    mapping_map["FLASH_CELLBOARD_3_RX"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["FLASH_CELLBOARD_4_TX"].size = std::bind(&canlib_circular_buffer<bms_message_FLASH_CELLBOARD_4_TX, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.FLASH_CELLBOARD_4_TX);
    mapping_map["FLASH_CELLBOARD_4_TX"].offset = std::bind(&canlib_circular_buffer<bms_message_FLASH_CELLBOARD_4_TX, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.FLASH_CELLBOARD_4_TX);
    mapping_map["FLASH_CELLBOARD_4_TX"].stride = sizeof(bms_message_FLASH_CELLBOARD_4_TX);
#ifdef CANLIB_TIMESTAMP
    mapping_map["FLASH_CELLBOARD_4_TX"].field["_timestamp"].value._uint64 = &pack.FLASH_CELLBOARD_4_TX.start()._timestamp;
    mapping_map["FLASH_CELLBOARD_4_TX"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["FLASH_CELLBOARD_4_RX"].size = std::bind(&canlib_circular_buffer<bms_message_FLASH_CELLBOARD_4_RX, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.FLASH_CELLBOARD_4_RX);
    mapping_map["FLASH_CELLBOARD_4_RX"].offset = std::bind(&canlib_circular_buffer<bms_message_FLASH_CELLBOARD_4_RX, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.FLASH_CELLBOARD_4_RX);
    mapping_map["FLASH_CELLBOARD_4_RX"].stride = sizeof(bms_message_FLASH_CELLBOARD_4_RX);
#ifdef CANLIB_TIMESTAMP
    mapping_map["FLASH_CELLBOARD_4_RX"].field["_timestamp"].value._uint64 = &pack.FLASH_CELLBOARD_4_RX.start()._timestamp;
    mapping_map["FLASH_CELLBOARD_4_RX"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["FLASH_CELLBOARD_5_TX"].size = std::bind(&canlib_circular_buffer<bms_message_FLASH_CELLBOARD_5_TX, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.FLASH_CELLBOARD_5_TX);
    mapping_map["FLASH_CELLBOARD_5_TX"].offset = std::bind(&canlib_circular_buffer<bms_message_FLASH_CELLBOARD_5_TX, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.FLASH_CELLBOARD_5_TX);
    mapping_map["FLASH_CELLBOARD_5_TX"].stride = sizeof(bms_message_FLASH_CELLBOARD_5_TX);
#ifdef CANLIB_TIMESTAMP
    mapping_map["FLASH_CELLBOARD_5_TX"].field["_timestamp"].value._uint64 = &pack.FLASH_CELLBOARD_5_TX.start()._timestamp;
    mapping_map["FLASH_CELLBOARD_5_TX"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["FLASH_CELLBOARD_5_RX"].size = std::bind(&canlib_circular_buffer<bms_message_FLASH_CELLBOARD_5_RX, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.FLASH_CELLBOARD_5_RX);
    mapping_map["FLASH_CELLBOARD_5_RX"].offset = std::bind(&canlib_circular_buffer<bms_message_FLASH_CELLBOARD_5_RX, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.FLASH_CELLBOARD_5_RX);
    mapping_map["FLASH_CELLBOARD_5_RX"].stride = sizeof(bms_message_FLASH_CELLBOARD_5_RX);
#ifdef CANLIB_TIMESTAMP
    mapping_map["FLASH_CELLBOARD_5_RX"].field["_timestamp"].value._uint64 = &pack.FLASH_CELLBOARD_5_RX.start()._timestamp;
    mapping_map["FLASH_CELLBOARD_5_RX"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP 
}

void bms_proto_serialize_from_id(canlib_message_id id, bms::Pack* pack, bms_devices* map) {
    int index = bms_index_from_id(id);

    if (index == -1) return;

    switch(id) {
        case 1536: {
            bms_message_BOARD_STATUS* msg = (bms_message_BOARD_STATUS*) (*map)[index].message_raw;
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
            bms_message_TEMPERATURES_conversion* msg = (bms_message_TEMPERATURES_conversion*) (*map)[index].message_conversion;
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
            bms_message_VOLTAGES_conversion* msg = (bms_message_VOLTAGES_conversion*) (*map)[index].message_conversion;
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
            bms_message_BALANCING* msg = (bms_message_BALANCING*) (*map)[index].message_raw;
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
            bms_message_FW_UPDATE* msg = (bms_message_FW_UPDATE*) (*map)[index].message_raw;
            bms::FW_UPDATE* proto_msg = pack->add_fw_update();
            proto_msg->set_cellboard_id((bms::Cellboard)msg->cellboard_id);
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

void bms_proto_deserialize(bms::Pack* pack, bms_proto_pack* map, uint64_t resample_us) {
    for(int i = 0; i < pack->board_status_size(); i++){
        static bms_message_BOARD_STATUS instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->board_status(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.cellboard_id =(bms_Cellboard)pack->board_status(i).cellboard_id();
        instance.errors =pack->board_status(i).errors();
        instance.balancing_status =(bms_BalancingStatus)pack->board_status(i).balancing_status();
        map->BOARD_STATUS.push(instance);
    }
    for(int i = 0; i < pack->temperatures_size(); i++){
        static bms_message_TEMPERATURES_conversion instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->temperatures(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.cellboard_id =(bms_Cellboard)pack->temperatures(i).cellboard_id();
        instance.start_index =pack->temperatures(i).start_index();
        instance.temp0 =pack->temperatures(i).temp0();
        instance.temp1 =pack->temperatures(i).temp1();
        instance.temp2 =pack->temperatures(i).temp2();
        instance.temp3 =pack->temperatures(i).temp3();
        map->TEMPERATURES.push(instance);
    }
    for(int i = 0; i < pack->voltages_size(); i++){
        static bms_message_VOLTAGES_conversion instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->voltages(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.cellboard_id =(bms_Cellboard)pack->voltages(i).cellboard_id();
        instance.start_index =pack->voltages(i).start_index();
        instance.voltage0 =pack->voltages(i).voltage0();
        instance.voltage1 =pack->voltages(i).voltage1();
        instance.voltage2 =pack->voltages(i).voltage2();
        map->VOLTAGES.push(instance);
    }
    for(int i = 0; i < pack->balancing_size(); i++){
        static bms_message_BALANCING instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->balancing(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.cellboard_id =(bms_Cellboard)pack->balancing(i).cellboard_id();
        instance.board_index =pack->balancing(i).board_index();
        instance.cells =pack->balancing(i).cells();
        map->BALANCING.push(instance);
    }
    for(int i = 0; i < pack->fw_update_size(); i++){
        static bms_message_FW_UPDATE instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->fw_update(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.cellboard_id =(bms_Cellboard)pack->fw_update(i).cellboard_id();
        instance.board_index =pack->fw_update(i).board_index();
        map->FW_UPDATE.push(instance);
    }
    for(int i = 0; i < pack->flash_cellboard_0_tx_size(); i++){
        static bms_message_FLASH_CELLBOARD_0_TX instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->flash_cellboard_0_tx(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        map->FLASH_CELLBOARD_0_TX.push(instance);
    }
    for(int i = 0; i < pack->flash_cellboard_0_rx_size(); i++){
        static bms_message_FLASH_CELLBOARD_0_RX instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->flash_cellboard_0_rx(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        map->FLASH_CELLBOARD_0_RX.push(instance);
    }
    for(int i = 0; i < pack->flash_cellboard_1_tx_size(); i++){
        static bms_message_FLASH_CELLBOARD_1_TX instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->flash_cellboard_1_tx(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        map->FLASH_CELLBOARD_1_TX.push(instance);
    }
    for(int i = 0; i < pack->flash_cellboard_1_rx_size(); i++){
        static bms_message_FLASH_CELLBOARD_1_RX instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->flash_cellboard_1_rx(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        map->FLASH_CELLBOARD_1_RX.push(instance);
    }
    for(int i = 0; i < pack->flash_cellboard_2_tx_size(); i++){
        static bms_message_FLASH_CELLBOARD_2_TX instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->flash_cellboard_2_tx(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        map->FLASH_CELLBOARD_2_TX.push(instance);
    }
    for(int i = 0; i < pack->flash_cellboard_2_rx_size(); i++){
        static bms_message_FLASH_CELLBOARD_2_RX instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->flash_cellboard_2_rx(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        map->FLASH_CELLBOARD_2_RX.push(instance);
    }
    for(int i = 0; i < pack->flash_cellboard_3_tx_size(); i++){
        static bms_message_FLASH_CELLBOARD_3_TX instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->flash_cellboard_3_tx(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        map->FLASH_CELLBOARD_3_TX.push(instance);
    }
    for(int i = 0; i < pack->flash_cellboard_3_rx_size(); i++){
        static bms_message_FLASH_CELLBOARD_3_RX instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->flash_cellboard_3_rx(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        map->FLASH_CELLBOARD_3_RX.push(instance);
    }
    for(int i = 0; i < pack->flash_cellboard_4_tx_size(); i++){
        static bms_message_FLASH_CELLBOARD_4_TX instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->flash_cellboard_4_tx(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        map->FLASH_CELLBOARD_4_TX.push(instance);
    }
    for(int i = 0; i < pack->flash_cellboard_4_rx_size(); i++){
        static bms_message_FLASH_CELLBOARD_4_RX instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->flash_cellboard_4_rx(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        map->FLASH_CELLBOARD_4_RX.push(instance);
    }
    for(int i = 0; i < pack->flash_cellboard_5_tx_size(); i++){
        static bms_message_FLASH_CELLBOARD_5_TX instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->flash_cellboard_5_tx(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        map->FLASH_CELLBOARD_5_TX.push(instance);
    }
    for(int i = 0; i < pack->flash_cellboard_5_rx_size(); i++){
        static bms_message_FLASH_CELLBOARD_5_RX instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->flash_cellboard_5_rx(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        map->FLASH_CELLBOARD_5_RX.push(instance);
    }
}

#endif // bms_MAPPING_IMPLEMENTATION

#endif // bms_MAPPING_H