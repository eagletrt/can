#ifndef primary_MAPPING_H
#define primary_MAPPING_H

#include <string>
#include <unordered_map>
#include <functional>

#include "primary.pb.h"

#ifdef primary_IMPLEMENTATION
#undef primary_IMPLEMENTATION
#define __primary_IMPLEMENTATION
#endif

#include "../../../lib/primary/c/network.h"

#ifdef __primary_IMPLEMENTATION
#undef __primary_IMPLEMENTATION
#define primary_IMPLEMENTATION
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
    canlib_circular_buffer<primary_message_BMS_HV_JMP_TO_BLT, CANLIB_CIRCULAR_BUFFER_SIZE> BMS_HV_JMP_TO_BLT;
    canlib_circular_buffer<primary_message_BMS_LV_JMP_TO_BLT, CANLIB_CIRCULAR_BUFFER_SIZE> BMS_LV_JMP_TO_BLT;
    canlib_circular_buffer<primary_message_STEER_VERSION, CANLIB_CIRCULAR_BUFFER_SIZE> STEER_VERSION;
    canlib_circular_buffer<primary_message_DAS_VERSION, CANLIB_CIRCULAR_BUFFER_SIZE> DAS_VERSION;
    canlib_circular_buffer<primary_message_HV_VERSION, CANLIB_CIRCULAR_BUFFER_SIZE> HV_VERSION;
    canlib_circular_buffer<primary_message_LV_VERSION, CANLIB_CIRCULAR_BUFFER_SIZE> LV_VERSION;
    canlib_circular_buffer<primary_message_TLM_VERSION, CANLIB_CIRCULAR_BUFFER_SIZE> TLM_VERSION;
    canlib_circular_buffer<primary_message_TIMESTAMP, CANLIB_CIRCULAR_BUFFER_SIZE> TIMESTAMP;
    canlib_circular_buffer<primary_message_AMBIENT_TEMPERATURE, CANLIB_CIRCULAR_BUFFER_SIZE> AMBIENT_TEMPERATURE;
    canlib_circular_buffer<primary_message_DATA_LOGGER, CANLIB_CIRCULAR_BUFFER_SIZE> DATA_LOGGER;
    canlib_circular_buffer<primary_message_SET_TLM_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE> SET_TLM_STATUS;
    canlib_circular_buffer<primary_message_TLM_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE> TLM_STATUS;
    canlib_circular_buffer<primary_message_STEER_SYSTEM_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE> STEER_SYSTEM_STATUS;
    canlib_circular_buffer<primary_message_HV_VOLTAGE_conversion, CANLIB_CIRCULAR_BUFFER_SIZE> HV_VOLTAGE;
    canlib_circular_buffer<primary_message_HV_CURRENT_conversion, CANLIB_CIRCULAR_BUFFER_SIZE> HV_CURRENT;
    canlib_circular_buffer<primary_message_HV_TEMP_conversion, CANLIB_CIRCULAR_BUFFER_SIZE> HV_TEMP;
    canlib_circular_buffer<primary_message_HV_ERRORS, CANLIB_CIRCULAR_BUFFER_SIZE> HV_ERRORS;
    canlib_circular_buffer<primary_message_HV_CAN_FORWARD, CANLIB_CIRCULAR_BUFFER_SIZE> HV_CAN_FORWARD;
    canlib_circular_buffer<primary_message_HV_FANS_OVERRIDE_conversion, CANLIB_CIRCULAR_BUFFER_SIZE> HV_FANS_OVERRIDE;
    canlib_circular_buffer<primary_message_HV_CAN_FORWARD_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE> HV_CAN_FORWARD_STATUS;
    canlib_circular_buffer<primary_message_HV_FANS_OVERRIDE_STATUS_conversion, CANLIB_CIRCULAR_BUFFER_SIZE> HV_FANS_OVERRIDE_STATUS;
    canlib_circular_buffer<primary_message_HV_FEEDBACKS_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE> HV_FEEDBACKS_STATUS;
    canlib_circular_buffer<primary_message_HV_IMD_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE> HV_IMD_STATUS;
    canlib_circular_buffer<primary_message_TS_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE> TS_STATUS;
    canlib_circular_buffer<primary_message_SET_TS_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE> SET_TS_STATUS_DAS;
    canlib_circular_buffer<primary_message_SET_TS_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE> SET_TS_STATUS_HANDCART;
    canlib_circular_buffer<primary_message_STEER_STATUS_conversion, CANLIB_CIRCULAR_BUFFER_SIZE> STEER_STATUS;
    canlib_circular_buffer<primary_message_SET_CAR_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE> SET_CAR_STATUS;
    canlib_circular_buffer<primary_message_SET_PEDALS_RANGE, CANLIB_CIRCULAR_BUFFER_SIZE> SET_PEDALS_RANGE;
    canlib_circular_buffer<primary_message_SET_STEERING_ANGLE_RANGE, CANLIB_CIRCULAR_BUFFER_SIZE> SET_STEERING_ANGLE_RANGE;
    canlib_circular_buffer<primary_message_CAR_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE> CAR_STATUS;
    canlib_circular_buffer<primary_message_DAS_ERRORS, CANLIB_CIRCULAR_BUFFER_SIZE> DAS_ERRORS;
    canlib_circular_buffer<primary_message_LV_CURRENT_conversion, CANLIB_CIRCULAR_BUFFER_SIZE> LV_CURRENT;
    canlib_circular_buffer<primary_message_LV_VOLTAGE_conversion, CANLIB_CIRCULAR_BUFFER_SIZE> LV_VOLTAGE;
    canlib_circular_buffer<primary_message_LV_TOTAL_VOLTAGE_conversion, CANLIB_CIRCULAR_BUFFER_SIZE> LV_TOTAL_VOLTAGE;
    canlib_circular_buffer<primary_message_LV_TEMPERATURE_conversion, CANLIB_CIRCULAR_BUFFER_SIZE> LV_TEMPERATURE;
    canlib_circular_buffer<primary_message_COOLING_STATUS_conversion, CANLIB_CIRCULAR_BUFFER_SIZE> COOLING_STATUS;
    canlib_circular_buffer<primary_message_SET_RADIATOR_SPEED_conversion, CANLIB_CIRCULAR_BUFFER_SIZE> SET_RADIATOR_SPEED;
    canlib_circular_buffer<primary_message_SET_PUMPS_SPEED_conversion, CANLIB_CIRCULAR_BUFFER_SIZE> SET_PUMPS_SPEED;
    canlib_circular_buffer<primary_message_SET_INVERTER_CONNECTION_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE> SET_INVERTER_CONNECTION_STATUS;
    canlib_circular_buffer<primary_message_INVERTER_CONNECTION_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE> INVERTER_CONNECTION_STATUS;
    canlib_circular_buffer<primary_message_LV_ERRORS, CANLIB_CIRCULAR_BUFFER_SIZE> LV_ERRORS;
    canlib_circular_buffer<primary_message_SHUTDOWN_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE> SHUTDOWN_STATUS;
    canlib_circular_buffer<primary_message_MARKER, CANLIB_CIRCULAR_BUFFER_SIZE> MARKER;
    canlib_circular_buffer<primary_message_HV_CELLS_VOLTAGE_conversion, CANLIB_CIRCULAR_BUFFER_SIZE> HV_CELLS_VOLTAGE;
    canlib_circular_buffer<primary_message_HV_CELLS_TEMP_conversion, CANLIB_CIRCULAR_BUFFER_SIZE> HV_CELLS_TEMP;
    canlib_circular_buffer<primary_message_HV_CELL_BALANCING_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE> HV_CELL_BALANCING_STATUS;
    canlib_circular_buffer<primary_message_SET_CELL_BALANCING_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE> SET_CELL_BALANCING_STATUS;
    canlib_circular_buffer<primary_message_HANDCART_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE> HANDCART_STATUS;
    canlib_circular_buffer<primary_message_SPEED_conversion, CANLIB_CIRCULAR_BUFFER_SIZE> SPEED;
    canlib_circular_buffer<primary_message_INV_L_REQUEST, CANLIB_CIRCULAR_BUFFER_SIZE> INV_L_REQUEST;
    canlib_circular_buffer<primary_message_INV_R_REQUEST, CANLIB_CIRCULAR_BUFFER_SIZE> INV_R_REQUEST;
    canlib_circular_buffer<primary_message_INV_L_RESPONSE, CANLIB_CIRCULAR_BUFFER_SIZE> INV_L_RESPONSE;
    canlib_circular_buffer<primary_message_INV_R_RESPONSE, CANLIB_CIRCULAR_BUFFER_SIZE> INV_R_RESPONSE;
    canlib_circular_buffer<primary_message_FLASH_CELLBOARD_0_TX, CANLIB_CIRCULAR_BUFFER_SIZE> FLASH_CELLBOARD_0_TX;
    canlib_circular_buffer<primary_message_FLASH_CELLBOARD_0_RX, CANLIB_CIRCULAR_BUFFER_SIZE> FLASH_CELLBOARD_0_RX;
    canlib_circular_buffer<primary_message_FLASH_CELLBOARD_1_TX, CANLIB_CIRCULAR_BUFFER_SIZE> FLASH_CELLBOARD_1_TX;
    canlib_circular_buffer<primary_message_FLASH_CELLBOARD_1_RX, CANLIB_CIRCULAR_BUFFER_SIZE> FLASH_CELLBOARD_1_RX;
    canlib_circular_buffer<primary_message_FLASH_CELLBOARD_2_TX, CANLIB_CIRCULAR_BUFFER_SIZE> FLASH_CELLBOARD_2_TX;
    canlib_circular_buffer<primary_message_FLASH_CELLBOARD_2_RX, CANLIB_CIRCULAR_BUFFER_SIZE> FLASH_CELLBOARD_2_RX;
    canlib_circular_buffer<primary_message_FLASH_CELLBOARD_3_TX, CANLIB_CIRCULAR_BUFFER_SIZE> FLASH_CELLBOARD_3_TX;
    canlib_circular_buffer<primary_message_FLASH_CELLBOARD_3_RX, CANLIB_CIRCULAR_BUFFER_SIZE> FLASH_CELLBOARD_3_RX;
    canlib_circular_buffer<primary_message_FLASH_CELLBOARD_4_TX, CANLIB_CIRCULAR_BUFFER_SIZE> FLASH_CELLBOARD_4_TX;
    canlib_circular_buffer<primary_message_FLASH_CELLBOARD_4_RX, CANLIB_CIRCULAR_BUFFER_SIZE> FLASH_CELLBOARD_4_RX;
    canlib_circular_buffer<primary_message_FLASH_CELLBOARD_5_TX, CANLIB_CIRCULAR_BUFFER_SIZE> FLASH_CELLBOARD_5_TX;
    canlib_circular_buffer<primary_message_FLASH_CELLBOARD_5_RX, CANLIB_CIRCULAR_BUFFER_SIZE> FLASH_CELLBOARD_5_RX;
    canlib_circular_buffer<primary_message_FLASH_BMS_HV_TX, CANLIB_CIRCULAR_BUFFER_SIZE> FLASH_BMS_HV_TX;
    canlib_circular_buffer<primary_message_FLASH_BMS_HV_RX, CANLIB_CIRCULAR_BUFFER_SIZE> FLASH_BMS_HV_RX;
    canlib_circular_buffer<primary_message_FLASH_BMS_LV_TX, CANLIB_CIRCULAR_BUFFER_SIZE> FLASH_BMS_LV_TX;
    canlib_circular_buffer<primary_message_FLASH_BMS_LV_RX, CANLIB_CIRCULAR_BUFFER_SIZE> FLASH_BMS_LV_RX;
    canlib_circular_buffer<primary_message_BRUSA_NLG5_CTL, CANLIB_CIRCULAR_BUFFER_SIZE> BRUSA_NLG5_CTL;
    canlib_circular_buffer<primary_message_BRUSA_ST, CANLIB_CIRCULAR_BUFFER_SIZE> BRUSA_ST;
    canlib_circular_buffer<primary_message_BRUSA_ACT_I, CANLIB_CIRCULAR_BUFFER_SIZE> BRUSA_ACT_I;
    canlib_circular_buffer<primary_message_BRUSA_ACT_II, CANLIB_CIRCULAR_BUFFER_SIZE> BRUSA_ACT_II;
    canlib_circular_buffer<primary_message_BRUSA_TEMP, CANLIB_CIRCULAR_BUFFER_SIZE> BRUSA_TEMP;
    canlib_circular_buffer<primary_message_BRUSA_ERR, CANLIB_CIRCULAR_BUFFER_SIZE> BRUSA_ERR;
    canlib_circular_buffer<primary_message_CONTROL_OUTPUT_conversion, CANLIB_CIRCULAR_BUFFER_SIZE> CONTROL_OUTPUT;
    canlib_circular_buffer<primary_message_LC_RESET, CANLIB_CIRCULAR_BUFFER_SIZE> LC_RESET;
} primary_proto_pack;

void primary_mapping_adaptor_construct(const primary_proto_pack& pack, mapping_adaptor& mapping_map);
void primary_proto_serialize_from_id(canlib_message_id id, primary::Pack* pack, primary_devices* map);
void primary_proto_deserialize(primary::Pack* pack, primary_proto_pack* map, uint64_t resample_us);

#ifdef primary_MAPPING_IMPLEMENTATION

void primary_mapping_adaptor_construct(const primary_proto_pack& pack, mapping_adaptor& mapping_map){
    mapping_map["BMS_HV_JMP_TO_BLT"].size = std::bind(&canlib_circular_buffer<primary_message_BMS_HV_JMP_TO_BLT, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.BMS_HV_JMP_TO_BLT);
    mapping_map["BMS_HV_JMP_TO_BLT"].offset = std::bind(&canlib_circular_buffer<primary_message_BMS_HV_JMP_TO_BLT, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.BMS_HV_JMP_TO_BLT);
    mapping_map["BMS_HV_JMP_TO_BLT"].stride = sizeof(primary_message_BMS_HV_JMP_TO_BLT);
#ifdef CANLIB_TIMESTAMP
    mapping_map["BMS_HV_JMP_TO_BLT"].field["_timestamp"].value._uint64 = &pack.BMS_HV_JMP_TO_BLT.start()._timestamp;
    mapping_map["BMS_HV_JMP_TO_BLT"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["BMS_LV_JMP_TO_BLT"].size = std::bind(&canlib_circular_buffer<primary_message_BMS_LV_JMP_TO_BLT, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.BMS_LV_JMP_TO_BLT);
    mapping_map["BMS_LV_JMP_TO_BLT"].offset = std::bind(&canlib_circular_buffer<primary_message_BMS_LV_JMP_TO_BLT, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.BMS_LV_JMP_TO_BLT);
    mapping_map["BMS_LV_JMP_TO_BLT"].stride = sizeof(primary_message_BMS_LV_JMP_TO_BLT);
#ifdef CANLIB_TIMESTAMP
    mapping_map["BMS_LV_JMP_TO_BLT"].field["_timestamp"].value._uint64 = &pack.BMS_LV_JMP_TO_BLT.start()._timestamp;
    mapping_map["BMS_LV_JMP_TO_BLT"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["STEER_VERSION"].size = std::bind(&canlib_circular_buffer<primary_message_STEER_VERSION, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.STEER_VERSION);
    mapping_map["STEER_VERSION"].offset = std::bind(&canlib_circular_buffer<primary_message_STEER_VERSION, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.STEER_VERSION);
    mapping_map["STEER_VERSION"].stride = sizeof(primary_message_STEER_VERSION);
    mapping_map["STEER_VERSION"].field["component_version"].value._uint8 = &pack.STEER_VERSION.start().component_version;
    mapping_map["STEER_VERSION"].field["component_version"].type = mapping_type_uint8;
    mapping_map["STEER_VERSION"].field["canlib_build_time"].value._uint32 = &pack.STEER_VERSION.start().canlib_build_time;
    mapping_map["STEER_VERSION"].field["canlib_build_time"].type = mapping_type_uint32;
#ifdef CANLIB_TIMESTAMP
    mapping_map["STEER_VERSION"].field["_timestamp"].value._uint64 = &pack.STEER_VERSION.start()._timestamp;
    mapping_map["STEER_VERSION"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["DAS_VERSION"].size = std::bind(&canlib_circular_buffer<primary_message_DAS_VERSION, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.DAS_VERSION);
    mapping_map["DAS_VERSION"].offset = std::bind(&canlib_circular_buffer<primary_message_DAS_VERSION, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.DAS_VERSION);
    mapping_map["DAS_VERSION"].stride = sizeof(primary_message_DAS_VERSION);
    mapping_map["DAS_VERSION"].field["component_version"].value._uint8 = &pack.DAS_VERSION.start().component_version;
    mapping_map["DAS_VERSION"].field["component_version"].type = mapping_type_uint8;
    mapping_map["DAS_VERSION"].field["canlib_build_time"].value._uint32 = &pack.DAS_VERSION.start().canlib_build_time;
    mapping_map["DAS_VERSION"].field["canlib_build_time"].type = mapping_type_uint32;
#ifdef CANLIB_TIMESTAMP
    mapping_map["DAS_VERSION"].field["_timestamp"].value._uint64 = &pack.DAS_VERSION.start()._timestamp;
    mapping_map["DAS_VERSION"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["HV_VERSION"].size = std::bind(&canlib_circular_buffer<primary_message_HV_VERSION, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.HV_VERSION);
    mapping_map["HV_VERSION"].offset = std::bind(&canlib_circular_buffer<primary_message_HV_VERSION, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.HV_VERSION);
    mapping_map["HV_VERSION"].stride = sizeof(primary_message_HV_VERSION);
    mapping_map["HV_VERSION"].field["component_version"].value._uint8 = &pack.HV_VERSION.start().component_version;
    mapping_map["HV_VERSION"].field["component_version"].type = mapping_type_uint8;
    mapping_map["HV_VERSION"].field["canlib_build_time"].value._uint32 = &pack.HV_VERSION.start().canlib_build_time;
    mapping_map["HV_VERSION"].field["canlib_build_time"].type = mapping_type_uint32;
#ifdef CANLIB_TIMESTAMP
    mapping_map["HV_VERSION"].field["_timestamp"].value._uint64 = &pack.HV_VERSION.start()._timestamp;
    mapping_map["HV_VERSION"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["LV_VERSION"].size = std::bind(&canlib_circular_buffer<primary_message_LV_VERSION, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.LV_VERSION);
    mapping_map["LV_VERSION"].offset = std::bind(&canlib_circular_buffer<primary_message_LV_VERSION, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.LV_VERSION);
    mapping_map["LV_VERSION"].stride = sizeof(primary_message_LV_VERSION);
    mapping_map["LV_VERSION"].field["component_version"].value._uint8 = &pack.LV_VERSION.start().component_version;
    mapping_map["LV_VERSION"].field["component_version"].type = mapping_type_uint8;
    mapping_map["LV_VERSION"].field["canlib_build_time"].value._uint32 = &pack.LV_VERSION.start().canlib_build_time;
    mapping_map["LV_VERSION"].field["canlib_build_time"].type = mapping_type_uint32;
#ifdef CANLIB_TIMESTAMP
    mapping_map["LV_VERSION"].field["_timestamp"].value._uint64 = &pack.LV_VERSION.start()._timestamp;
    mapping_map["LV_VERSION"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["TLM_VERSION"].size = std::bind(&canlib_circular_buffer<primary_message_TLM_VERSION, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.TLM_VERSION);
    mapping_map["TLM_VERSION"].offset = std::bind(&canlib_circular_buffer<primary_message_TLM_VERSION, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.TLM_VERSION);
    mapping_map["TLM_VERSION"].stride = sizeof(primary_message_TLM_VERSION);
    mapping_map["TLM_VERSION"].field["component_version"].value._uint8 = &pack.TLM_VERSION.start().component_version;
    mapping_map["TLM_VERSION"].field["component_version"].type = mapping_type_uint8;
    mapping_map["TLM_VERSION"].field["canlib_build_time"].value._uint32 = &pack.TLM_VERSION.start().canlib_build_time;
    mapping_map["TLM_VERSION"].field["canlib_build_time"].type = mapping_type_uint32;
#ifdef CANLIB_TIMESTAMP
    mapping_map["TLM_VERSION"].field["_timestamp"].value._uint64 = &pack.TLM_VERSION.start()._timestamp;
    mapping_map["TLM_VERSION"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["TIMESTAMP"].size = std::bind(&canlib_circular_buffer<primary_message_TIMESTAMP, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.TIMESTAMP);
    mapping_map["TIMESTAMP"].offset = std::bind(&canlib_circular_buffer<primary_message_TIMESTAMP, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.TIMESTAMP);
    mapping_map["TIMESTAMP"].stride = sizeof(primary_message_TIMESTAMP);
    mapping_map["TIMESTAMP"].field["timestamp"].value._uint32 = &pack.TIMESTAMP.start().timestamp;
    mapping_map["TIMESTAMP"].field["timestamp"].type = mapping_type_uint32;
#ifdef CANLIB_TIMESTAMP
    mapping_map["TIMESTAMP"].field["_timestamp"].value._uint64 = &pack.TIMESTAMP.start()._timestamp;
    mapping_map["TIMESTAMP"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["AMBIENT_TEMPERATURE"].size = std::bind(&canlib_circular_buffer<primary_message_AMBIENT_TEMPERATURE, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.AMBIENT_TEMPERATURE);
    mapping_map["AMBIENT_TEMPERATURE"].offset = std::bind(&canlib_circular_buffer<primary_message_AMBIENT_TEMPERATURE, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.AMBIENT_TEMPERATURE);
    mapping_map["AMBIENT_TEMPERATURE"].stride = sizeof(primary_message_AMBIENT_TEMPERATURE);
    mapping_map["AMBIENT_TEMPERATURE"].field["temp"].value._int16 = &pack.AMBIENT_TEMPERATURE.start().temp;
    mapping_map["AMBIENT_TEMPERATURE"].field["temp"].type = mapping_type_int16;
#ifdef CANLIB_TIMESTAMP
    mapping_map["AMBIENT_TEMPERATURE"].field["_timestamp"].value._uint64 = &pack.AMBIENT_TEMPERATURE.start()._timestamp;
    mapping_map["AMBIENT_TEMPERATURE"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["DATA_LOGGER"].size = std::bind(&canlib_circular_buffer<primary_message_DATA_LOGGER, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.DATA_LOGGER);
    mapping_map["DATA_LOGGER"].offset = std::bind(&canlib_circular_buffer<primary_message_DATA_LOGGER, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.DATA_LOGGER);
    mapping_map["DATA_LOGGER"].stride = sizeof(primary_message_DATA_LOGGER);
    mapping_map["DATA_LOGGER"].field["placeholder1"].value._uint32 = &pack.DATA_LOGGER.start().placeholder1;
    mapping_map["DATA_LOGGER"].field["placeholder1"].type = mapping_type_uint32;
    mapping_map["DATA_LOGGER"].field["placeholder2"].value._uint32 = &pack.DATA_LOGGER.start().placeholder2;
    mapping_map["DATA_LOGGER"].field["placeholder2"].type = mapping_type_uint32;
#ifdef CANLIB_TIMESTAMP
    mapping_map["DATA_LOGGER"].field["_timestamp"].value._uint64 = &pack.DATA_LOGGER.start()._timestamp;
    mapping_map["DATA_LOGGER"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["SET_TLM_STATUS"].size = std::bind(&canlib_circular_buffer<primary_message_SET_TLM_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.SET_TLM_STATUS);
    mapping_map["SET_TLM_STATUS"].offset = std::bind(&canlib_circular_buffer<primary_message_SET_TLM_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.SET_TLM_STATUS);
    mapping_map["SET_TLM_STATUS"].stride = sizeof(primary_message_SET_TLM_STATUS);
    mapping_map["SET_TLM_STATUS"].field["tlm_status"].value._uint16 = (uint16_t*)&pack.SET_TLM_STATUS.start().tlm_status;
    mapping_map["SET_TLM_STATUS"].field["tlm_status"].type = mapping_type_uint16;
#ifdef CANLIB_TIMESTAMP
    mapping_map["SET_TLM_STATUS"].field["_timestamp"].value._uint64 = &pack.SET_TLM_STATUS.start()._timestamp;
    mapping_map["SET_TLM_STATUS"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["TLM_STATUS"].size = std::bind(&canlib_circular_buffer<primary_message_TLM_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.TLM_STATUS);
    mapping_map["TLM_STATUS"].offset = std::bind(&canlib_circular_buffer<primary_message_TLM_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.TLM_STATUS);
    mapping_map["TLM_STATUS"].stride = sizeof(primary_message_TLM_STATUS);
    mapping_map["TLM_STATUS"].field["tlm_status"].value._uint16 = (uint16_t*)&pack.TLM_STATUS.start().tlm_status;
    mapping_map["TLM_STATUS"].field["tlm_status"].type = mapping_type_uint16;
#ifdef CANLIB_TIMESTAMP
    mapping_map["TLM_STATUS"].field["_timestamp"].value._uint64 = &pack.TLM_STATUS.start()._timestamp;
    mapping_map["TLM_STATUS"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["STEER_SYSTEM_STATUS"].size = std::bind(&canlib_circular_buffer<primary_message_STEER_SYSTEM_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.STEER_SYSTEM_STATUS);
    mapping_map["STEER_SYSTEM_STATUS"].offset = std::bind(&canlib_circular_buffer<primary_message_STEER_SYSTEM_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.STEER_SYSTEM_STATUS);
    mapping_map["STEER_SYSTEM_STATUS"].stride = sizeof(primary_message_STEER_SYSTEM_STATUS);
    mapping_map["STEER_SYSTEM_STATUS"].field["soc_temp"].value._uint8 = &pack.STEER_SYSTEM_STATUS.start().soc_temp;
    mapping_map["STEER_SYSTEM_STATUS"].field["soc_temp"].type = mapping_type_uint8;
#ifdef CANLIB_TIMESTAMP
    mapping_map["STEER_SYSTEM_STATUS"].field["_timestamp"].value._uint64 = &pack.STEER_SYSTEM_STATUS.start()._timestamp;
    mapping_map["STEER_SYSTEM_STATUS"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["HV_VOLTAGE"].size = std::bind(&canlib_circular_buffer<primary_message_HV_VOLTAGE_conversion, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.HV_VOLTAGE);
    mapping_map["HV_VOLTAGE"].offset = std::bind(&canlib_circular_buffer<primary_message_HV_VOLTAGE_conversion, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.HV_VOLTAGE);
    mapping_map["HV_VOLTAGE"].stride = sizeof(primary_message_HV_VOLTAGE_conversion);
    mapping_map["HV_VOLTAGE"].field["pack_voltage"].value._float32 = &pack.HV_VOLTAGE.start().pack_voltage;
    mapping_map["HV_VOLTAGE"].field["pack_voltage"].type = mapping_type_float32;
    mapping_map["HV_VOLTAGE"].field["bus_voltage"].value._float32 = &pack.HV_VOLTAGE.start().bus_voltage;
    mapping_map["HV_VOLTAGE"].field["bus_voltage"].type = mapping_type_float32;
    mapping_map["HV_VOLTAGE"].field["max_cell_voltage"].value._float32 = &pack.HV_VOLTAGE.start().max_cell_voltage;
    mapping_map["HV_VOLTAGE"].field["max_cell_voltage"].type = mapping_type_float32;
    mapping_map["HV_VOLTAGE"].field["min_cell_voltage"].value._float32 = &pack.HV_VOLTAGE.start().min_cell_voltage;
    mapping_map["HV_VOLTAGE"].field["min_cell_voltage"].type = mapping_type_float32;
#ifdef CANLIB_TIMESTAMP
    mapping_map["HV_VOLTAGE"].field["_timestamp"].value._uint64 = &pack.HV_VOLTAGE.start()._timestamp;
    mapping_map["HV_VOLTAGE"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["HV_CURRENT"].size = std::bind(&canlib_circular_buffer<primary_message_HV_CURRENT_conversion, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.HV_CURRENT);
    mapping_map["HV_CURRENT"].offset = std::bind(&canlib_circular_buffer<primary_message_HV_CURRENT_conversion, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.HV_CURRENT);
    mapping_map["HV_CURRENT"].stride = sizeof(primary_message_HV_CURRENT_conversion);
    mapping_map["HV_CURRENT"].field["current"].value._float32 = &pack.HV_CURRENT.start().current;
    mapping_map["HV_CURRENT"].field["current"].type = mapping_type_float32;
    mapping_map["HV_CURRENT"].field["power"].value._float32 = &pack.HV_CURRENT.start().power;
    mapping_map["HV_CURRENT"].field["power"].type = mapping_type_float32;
    mapping_map["HV_CURRENT"].field["energy"].value._float32 = &pack.HV_CURRENT.start().energy;
    mapping_map["HV_CURRENT"].field["energy"].type = mapping_type_float32;
    mapping_map["HV_CURRENT"].field["soc"].value._float32 = &pack.HV_CURRENT.start().soc;
    mapping_map["HV_CURRENT"].field["soc"].type = mapping_type_float32;
#ifdef CANLIB_TIMESTAMP
    mapping_map["HV_CURRENT"].field["_timestamp"].value._uint64 = &pack.HV_CURRENT.start()._timestamp;
    mapping_map["HV_CURRENT"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["HV_TEMP"].size = std::bind(&canlib_circular_buffer<primary_message_HV_TEMP_conversion, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.HV_TEMP);
    mapping_map["HV_TEMP"].offset = std::bind(&canlib_circular_buffer<primary_message_HV_TEMP_conversion, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.HV_TEMP);
    mapping_map["HV_TEMP"].stride = sizeof(primary_message_HV_TEMP_conversion);
    mapping_map["HV_TEMP"].field["average_temp"].value._float32 = &pack.HV_TEMP.start().average_temp;
    mapping_map["HV_TEMP"].field["average_temp"].type = mapping_type_float32;
    mapping_map["HV_TEMP"].field["max_temp"].value._float32 = &pack.HV_TEMP.start().max_temp;
    mapping_map["HV_TEMP"].field["max_temp"].type = mapping_type_float32;
    mapping_map["HV_TEMP"].field["min_temp"].value._float32 = &pack.HV_TEMP.start().min_temp;
    mapping_map["HV_TEMP"].field["min_temp"].type = mapping_type_float32;
#ifdef CANLIB_TIMESTAMP
    mapping_map["HV_TEMP"].field["_timestamp"].value._uint64 = &pack.HV_TEMP.start()._timestamp;
    mapping_map["HV_TEMP"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["HV_ERRORS"].size = std::bind(&canlib_circular_buffer<primary_message_HV_ERRORS, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.HV_ERRORS);
    mapping_map["HV_ERRORS"].offset = std::bind(&canlib_circular_buffer<primary_message_HV_ERRORS, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.HV_ERRORS);
    mapping_map["HV_ERRORS"].stride = sizeof(primary_message_HV_ERRORS);
    mapping_map["HV_ERRORS"].field["warnings"].value._uint16 = (uint16_t*)&pack.HV_ERRORS.start().warnings;
    mapping_map["HV_ERRORS"].field["warnings"].type = mapping_type_uint16;
    mapping_map["HV_ERRORS"].field["errors"].value._uint16 = (uint16_t*)&pack.HV_ERRORS.start().errors;
    mapping_map["HV_ERRORS"].field["errors"].type = mapping_type_uint16;
#ifdef CANLIB_TIMESTAMP
    mapping_map["HV_ERRORS"].field["_timestamp"].value._uint64 = &pack.HV_ERRORS.start()._timestamp;
    mapping_map["HV_ERRORS"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["HV_CAN_FORWARD"].size = std::bind(&canlib_circular_buffer<primary_message_HV_CAN_FORWARD, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.HV_CAN_FORWARD);
    mapping_map["HV_CAN_FORWARD"].offset = std::bind(&canlib_circular_buffer<primary_message_HV_CAN_FORWARD, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.HV_CAN_FORWARD);
    mapping_map["HV_CAN_FORWARD"].stride = sizeof(primary_message_HV_CAN_FORWARD);
    mapping_map["HV_CAN_FORWARD"].field["can_forward_set"].value._uint16 = (uint16_t*)&pack.HV_CAN_FORWARD.start().can_forward_set;
    mapping_map["HV_CAN_FORWARD"].field["can_forward_set"].type = mapping_type_uint16;
#ifdef CANLIB_TIMESTAMP
    mapping_map["HV_CAN_FORWARD"].field["_timestamp"].value._uint64 = &pack.HV_CAN_FORWARD.start()._timestamp;
    mapping_map["HV_CAN_FORWARD"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["HV_FANS_OVERRIDE"].size = std::bind(&canlib_circular_buffer<primary_message_HV_FANS_OVERRIDE_conversion, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.HV_FANS_OVERRIDE);
    mapping_map["HV_FANS_OVERRIDE"].offset = std::bind(&canlib_circular_buffer<primary_message_HV_FANS_OVERRIDE_conversion, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.HV_FANS_OVERRIDE);
    mapping_map["HV_FANS_OVERRIDE"].stride = sizeof(primary_message_HV_FANS_OVERRIDE_conversion);
    mapping_map["HV_FANS_OVERRIDE"].field["fans_override"].value._uint16 = (uint16_t*)&pack.HV_FANS_OVERRIDE.start().fans_override;
    mapping_map["HV_FANS_OVERRIDE"].field["fans_override"].type = mapping_type_uint16;
    mapping_map["HV_FANS_OVERRIDE"].field["fans_speed"].value._float32 = &pack.HV_FANS_OVERRIDE.start().fans_speed;
    mapping_map["HV_FANS_OVERRIDE"].field["fans_speed"].type = mapping_type_float32;
#ifdef CANLIB_TIMESTAMP
    mapping_map["HV_FANS_OVERRIDE"].field["_timestamp"].value._uint64 = &pack.HV_FANS_OVERRIDE.start()._timestamp;
    mapping_map["HV_FANS_OVERRIDE"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["HV_CAN_FORWARD_STATUS"].size = std::bind(&canlib_circular_buffer<primary_message_HV_CAN_FORWARD_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.HV_CAN_FORWARD_STATUS);
    mapping_map["HV_CAN_FORWARD_STATUS"].offset = std::bind(&canlib_circular_buffer<primary_message_HV_CAN_FORWARD_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.HV_CAN_FORWARD_STATUS);
    mapping_map["HV_CAN_FORWARD_STATUS"].stride = sizeof(primary_message_HV_CAN_FORWARD_STATUS);
    mapping_map["HV_CAN_FORWARD_STATUS"].field["can_forward_status"].value._uint16 = (uint16_t*)&pack.HV_CAN_FORWARD_STATUS.start().can_forward_status;
    mapping_map["HV_CAN_FORWARD_STATUS"].field["can_forward_status"].type = mapping_type_uint16;
#ifdef CANLIB_TIMESTAMP
    mapping_map["HV_CAN_FORWARD_STATUS"].field["_timestamp"].value._uint64 = &pack.HV_CAN_FORWARD_STATUS.start()._timestamp;
    mapping_map["HV_CAN_FORWARD_STATUS"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["HV_FANS_OVERRIDE_STATUS"].size = std::bind(&canlib_circular_buffer<primary_message_HV_FANS_OVERRIDE_STATUS_conversion, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.HV_FANS_OVERRIDE_STATUS);
    mapping_map["HV_FANS_OVERRIDE_STATUS"].offset = std::bind(&canlib_circular_buffer<primary_message_HV_FANS_OVERRIDE_STATUS_conversion, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.HV_FANS_OVERRIDE_STATUS);
    mapping_map["HV_FANS_OVERRIDE_STATUS"].stride = sizeof(primary_message_HV_FANS_OVERRIDE_STATUS_conversion);
    mapping_map["HV_FANS_OVERRIDE_STATUS"].field["fans_override"].value._uint16 = (uint16_t*)&pack.HV_FANS_OVERRIDE_STATUS.start().fans_override;
    mapping_map["HV_FANS_OVERRIDE_STATUS"].field["fans_override"].type = mapping_type_uint16;
    mapping_map["HV_FANS_OVERRIDE_STATUS"].field["fans_speed"].value._float32 = &pack.HV_FANS_OVERRIDE_STATUS.start().fans_speed;
    mapping_map["HV_FANS_OVERRIDE_STATUS"].field["fans_speed"].type = mapping_type_float32;
#ifdef CANLIB_TIMESTAMP
    mapping_map["HV_FANS_OVERRIDE_STATUS"].field["_timestamp"].value._uint64 = &pack.HV_FANS_OVERRIDE_STATUS.start()._timestamp;
    mapping_map["HV_FANS_OVERRIDE_STATUS"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["HV_FEEDBACKS_STATUS"].size = std::bind(&canlib_circular_buffer<primary_message_HV_FEEDBACKS_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.HV_FEEDBACKS_STATUS);
    mapping_map["HV_FEEDBACKS_STATUS"].offset = std::bind(&canlib_circular_buffer<primary_message_HV_FEEDBACKS_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.HV_FEEDBACKS_STATUS);
    mapping_map["HV_FEEDBACKS_STATUS"].stride = sizeof(primary_message_HV_FEEDBACKS_STATUS);
    mapping_map["HV_FEEDBACKS_STATUS"].field["feedbacks_status"].value._uint16 = (uint16_t*)&pack.HV_FEEDBACKS_STATUS.start().feedbacks_status;
    mapping_map["HV_FEEDBACKS_STATUS"].field["feedbacks_status"].type = mapping_type_uint16;
    mapping_map["HV_FEEDBACKS_STATUS"].field["is_circuitry_error"].value._uint16 = (uint16_t*)&pack.HV_FEEDBACKS_STATUS.start().is_circuitry_error;
    mapping_map["HV_FEEDBACKS_STATUS"].field["is_circuitry_error"].type = mapping_type_uint16;
#ifdef CANLIB_TIMESTAMP
    mapping_map["HV_FEEDBACKS_STATUS"].field["_timestamp"].value._uint64 = &pack.HV_FEEDBACKS_STATUS.start()._timestamp;
    mapping_map["HV_FEEDBACKS_STATUS"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["HV_IMD_STATUS"].size = std::bind(&canlib_circular_buffer<primary_message_HV_IMD_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.HV_IMD_STATUS);
    mapping_map["HV_IMD_STATUS"].offset = std::bind(&canlib_circular_buffer<primary_message_HV_IMD_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.HV_IMD_STATUS);
    mapping_map["HV_IMD_STATUS"].stride = sizeof(primary_message_HV_IMD_STATUS);
    mapping_map["HV_IMD_STATUS"].field["imd_fault"].value._bool = &pack.HV_IMD_STATUS.start().imd_fault;
    mapping_map["HV_IMD_STATUS"].field["imd_fault"].type = mapping_type_bool;
    mapping_map["HV_IMD_STATUS"].field["imd_status"].value._uint16 = (uint16_t*)&pack.HV_IMD_STATUS.start().imd_status;
    mapping_map["HV_IMD_STATUS"].field["imd_status"].type = mapping_type_uint16;
    mapping_map["HV_IMD_STATUS"].field["imd_info"].value._int32 = &pack.HV_IMD_STATUS.start().imd_info;
    mapping_map["HV_IMD_STATUS"].field["imd_info"].type = mapping_type_int32;
#ifdef CANLIB_TIMESTAMP
    mapping_map["HV_IMD_STATUS"].field["_timestamp"].value._uint64 = &pack.HV_IMD_STATUS.start()._timestamp;
    mapping_map["HV_IMD_STATUS"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["TS_STATUS"].size = std::bind(&canlib_circular_buffer<primary_message_TS_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.TS_STATUS);
    mapping_map["TS_STATUS"].offset = std::bind(&canlib_circular_buffer<primary_message_TS_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.TS_STATUS);
    mapping_map["TS_STATUS"].stride = sizeof(primary_message_TS_STATUS);
    mapping_map["TS_STATUS"].field["ts_status"].value._uint16 = (uint16_t*)&pack.TS_STATUS.start().ts_status;
    mapping_map["TS_STATUS"].field["ts_status"].type = mapping_type_uint16;
#ifdef CANLIB_TIMESTAMP
    mapping_map["TS_STATUS"].field["_timestamp"].value._uint64 = &pack.TS_STATUS.start()._timestamp;
    mapping_map["TS_STATUS"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["SET_TS_STATUS"].size = std::bind(&canlib_circular_buffer<primary_message_SET_TS_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.SET_TS_STATUS_DAS);
    mapping_map["SET_TS_STATUS"].offset = std::bind(&canlib_circular_buffer<primary_message_SET_TS_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.SET_TS_STATUS_DAS);
    mapping_map["SET_TS_STATUS"].stride = sizeof(primary_message_SET_TS_STATUS);
    mapping_map["SET_TS_STATUS"].field["ts_status_set"].value._uint16 = (uint16_t*)&pack.SET_TS_STATUS_DAS.start().ts_status_set;
    mapping_map["SET_TS_STATUS"].field["ts_status_set"].type = mapping_type_uint16;
#ifdef CANLIB_TIMESTAMP
    mapping_map["SET_TS_STATUS"].field["_timestamp"].value._uint64 = &pack.SET_TS_STATUS_DAS.start()._timestamp;
    mapping_map["SET_TS_STATUS"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["SET_TS_STATUS"].size = std::bind(&canlib_circular_buffer<primary_message_SET_TS_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.SET_TS_STATUS_HANDCART);
    mapping_map["SET_TS_STATUS"].offset = std::bind(&canlib_circular_buffer<primary_message_SET_TS_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.SET_TS_STATUS_HANDCART);
    mapping_map["SET_TS_STATUS"].stride = sizeof(primary_message_SET_TS_STATUS);
    mapping_map["SET_TS_STATUS"].field["ts_status_set"].value._uint16 = (uint16_t*)&pack.SET_TS_STATUS_HANDCART.start().ts_status_set;
    mapping_map["SET_TS_STATUS"].field["ts_status_set"].type = mapping_type_uint16;
#ifdef CANLIB_TIMESTAMP
    mapping_map["SET_TS_STATUS"].field["_timestamp"].value._uint64 = &pack.SET_TS_STATUS_HANDCART.start()._timestamp;
    mapping_map["SET_TS_STATUS"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["STEER_STATUS"].size = std::bind(&canlib_circular_buffer<primary_message_STEER_STATUS_conversion, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.STEER_STATUS);
    mapping_map["STEER_STATUS"].offset = std::bind(&canlib_circular_buffer<primary_message_STEER_STATUS_conversion, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.STEER_STATUS);
    mapping_map["STEER_STATUS"].stride = sizeof(primary_message_STEER_STATUS_conversion);
    mapping_map["STEER_STATUS"].field["map_pw"].value._float32 = &pack.STEER_STATUS.start().map_pw;
    mapping_map["STEER_STATUS"].field["map_pw"].type = mapping_type_float32;
    mapping_map["STEER_STATUS"].field["map_sc"].value._float32 = &pack.STEER_STATUS.start().map_sc;
    mapping_map["STEER_STATUS"].field["map_sc"].type = mapping_type_float32;
    mapping_map["STEER_STATUS"].field["map_tv"].value._float32 = &pack.STEER_STATUS.start().map_tv;
    mapping_map["STEER_STATUS"].field["map_tv"].type = mapping_type_float32;
#ifdef CANLIB_TIMESTAMP
    mapping_map["STEER_STATUS"].field["_timestamp"].value._uint64 = &pack.STEER_STATUS.start()._timestamp;
    mapping_map["STEER_STATUS"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["SET_CAR_STATUS"].size = std::bind(&canlib_circular_buffer<primary_message_SET_CAR_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.SET_CAR_STATUS);
    mapping_map["SET_CAR_STATUS"].offset = std::bind(&canlib_circular_buffer<primary_message_SET_CAR_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.SET_CAR_STATUS);
    mapping_map["SET_CAR_STATUS"].stride = sizeof(primary_message_SET_CAR_STATUS);
    mapping_map["SET_CAR_STATUS"].field["car_status_set"].value._uint16 = (uint16_t*)&pack.SET_CAR_STATUS.start().car_status_set;
    mapping_map["SET_CAR_STATUS"].field["car_status_set"].type = mapping_type_uint16;
#ifdef CANLIB_TIMESTAMP
    mapping_map["SET_CAR_STATUS"].field["_timestamp"].value._uint64 = &pack.SET_CAR_STATUS.start()._timestamp;
    mapping_map["SET_CAR_STATUS"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["SET_PEDALS_RANGE"].size = std::bind(&canlib_circular_buffer<primary_message_SET_PEDALS_RANGE, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.SET_PEDALS_RANGE);
    mapping_map["SET_PEDALS_RANGE"].offset = std::bind(&canlib_circular_buffer<primary_message_SET_PEDALS_RANGE, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.SET_PEDALS_RANGE);
    mapping_map["SET_PEDALS_RANGE"].stride = sizeof(primary_message_SET_PEDALS_RANGE);
    mapping_map["SET_PEDALS_RANGE"].field["bound"].value._uint16 = (uint16_t*)&pack.SET_PEDALS_RANGE.start().bound;
    mapping_map["SET_PEDALS_RANGE"].field["bound"].type = mapping_type_uint16;
    mapping_map["SET_PEDALS_RANGE"].field["pedal"].value._uint16 = (uint16_t*)&pack.SET_PEDALS_RANGE.start().pedal;
    mapping_map["SET_PEDALS_RANGE"].field["pedal"].type = mapping_type_uint16;
#ifdef CANLIB_TIMESTAMP
    mapping_map["SET_PEDALS_RANGE"].field["_timestamp"].value._uint64 = &pack.SET_PEDALS_RANGE.start()._timestamp;
    mapping_map["SET_PEDALS_RANGE"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["SET_STEERING_ANGLE_RANGE"].size = std::bind(&canlib_circular_buffer<primary_message_SET_STEERING_ANGLE_RANGE, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.SET_STEERING_ANGLE_RANGE);
    mapping_map["SET_STEERING_ANGLE_RANGE"].offset = std::bind(&canlib_circular_buffer<primary_message_SET_STEERING_ANGLE_RANGE, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.SET_STEERING_ANGLE_RANGE);
    mapping_map["SET_STEERING_ANGLE_RANGE"].stride = sizeof(primary_message_SET_STEERING_ANGLE_RANGE);
    mapping_map["SET_STEERING_ANGLE_RANGE"].field["bound"].value._uint16 = (uint16_t*)&pack.SET_STEERING_ANGLE_RANGE.start().bound;
    mapping_map["SET_STEERING_ANGLE_RANGE"].field["bound"].type = mapping_type_uint16;
#ifdef CANLIB_TIMESTAMP
    mapping_map["SET_STEERING_ANGLE_RANGE"].field["_timestamp"].value._uint64 = &pack.SET_STEERING_ANGLE_RANGE.start()._timestamp;
    mapping_map["SET_STEERING_ANGLE_RANGE"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["CAR_STATUS"].size = std::bind(&canlib_circular_buffer<primary_message_CAR_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.CAR_STATUS);
    mapping_map["CAR_STATUS"].offset = std::bind(&canlib_circular_buffer<primary_message_CAR_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.CAR_STATUS);
    mapping_map["CAR_STATUS"].stride = sizeof(primary_message_CAR_STATUS);
    mapping_map["CAR_STATUS"].field["inverter_l"].value._uint16 = (uint16_t*)&pack.CAR_STATUS.start().inverter_l;
    mapping_map["CAR_STATUS"].field["inverter_l"].type = mapping_type_uint16;
    mapping_map["CAR_STATUS"].field["inverter_r"].value._uint16 = (uint16_t*)&pack.CAR_STATUS.start().inverter_r;
    mapping_map["CAR_STATUS"].field["inverter_r"].type = mapping_type_uint16;
    mapping_map["CAR_STATUS"].field["car_status"].value._uint16 = (uint16_t*)&pack.CAR_STATUS.start().car_status;
    mapping_map["CAR_STATUS"].field["car_status"].type = mapping_type_uint16;
#ifdef CANLIB_TIMESTAMP
    mapping_map["CAR_STATUS"].field["_timestamp"].value._uint64 = &pack.CAR_STATUS.start()._timestamp;
    mapping_map["CAR_STATUS"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["DAS_ERRORS"].size = std::bind(&canlib_circular_buffer<primary_message_DAS_ERRORS, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.DAS_ERRORS);
    mapping_map["DAS_ERRORS"].offset = std::bind(&canlib_circular_buffer<primary_message_DAS_ERRORS, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.DAS_ERRORS);
    mapping_map["DAS_ERRORS"].stride = sizeof(primary_message_DAS_ERRORS);
    mapping_map["DAS_ERRORS"].field["das_error"].value._uint16 = (uint16_t*)&pack.DAS_ERRORS.start().das_error;
    mapping_map["DAS_ERRORS"].field["das_error"].type = mapping_type_uint16;
#ifdef CANLIB_TIMESTAMP
    mapping_map["DAS_ERRORS"].field["_timestamp"].value._uint64 = &pack.DAS_ERRORS.start()._timestamp;
    mapping_map["DAS_ERRORS"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["LV_CURRENT"].size = std::bind(&canlib_circular_buffer<primary_message_LV_CURRENT_conversion, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.LV_CURRENT);
    mapping_map["LV_CURRENT"].offset = std::bind(&canlib_circular_buffer<primary_message_LV_CURRENT_conversion, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.LV_CURRENT);
    mapping_map["LV_CURRENT"].stride = sizeof(primary_message_LV_CURRENT_conversion);
    mapping_map["LV_CURRENT"].field["current"].value._float32 = &pack.LV_CURRENT.start().current;
    mapping_map["LV_CURRENT"].field["current"].type = mapping_type_float32;
#ifdef CANLIB_TIMESTAMP
    mapping_map["LV_CURRENT"].field["_timestamp"].value._uint64 = &pack.LV_CURRENT.start()._timestamp;
    mapping_map["LV_CURRENT"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["LV_VOLTAGE"].size = std::bind(&canlib_circular_buffer<primary_message_LV_VOLTAGE_conversion, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.LV_VOLTAGE);
    mapping_map["LV_VOLTAGE"].offset = std::bind(&canlib_circular_buffer<primary_message_LV_VOLTAGE_conversion, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.LV_VOLTAGE);
    mapping_map["LV_VOLTAGE"].stride = sizeof(primary_message_LV_VOLTAGE_conversion);
    mapping_map["LV_VOLTAGE"].field["voltage_1"].value._float32 = &pack.LV_VOLTAGE.start().voltage_1;
    mapping_map["LV_VOLTAGE"].field["voltage_1"].type = mapping_type_float32;
    mapping_map["LV_VOLTAGE"].field["voltage_2"].value._float32 = &pack.LV_VOLTAGE.start().voltage_2;
    mapping_map["LV_VOLTAGE"].field["voltage_2"].type = mapping_type_float32;
    mapping_map["LV_VOLTAGE"].field["voltage_3"].value._float32 = &pack.LV_VOLTAGE.start().voltage_3;
    mapping_map["LV_VOLTAGE"].field["voltage_3"].type = mapping_type_float32;
    mapping_map["LV_VOLTAGE"].field["voltage_4"].value._float32 = &pack.LV_VOLTAGE.start().voltage_4;
    mapping_map["LV_VOLTAGE"].field["voltage_4"].type = mapping_type_float32;
#ifdef CANLIB_TIMESTAMP
    mapping_map["LV_VOLTAGE"].field["_timestamp"].value._uint64 = &pack.LV_VOLTAGE.start()._timestamp;
    mapping_map["LV_VOLTAGE"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["LV_TOTAL_VOLTAGE"].size = std::bind(&canlib_circular_buffer<primary_message_LV_TOTAL_VOLTAGE_conversion, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.LV_TOTAL_VOLTAGE);
    mapping_map["LV_TOTAL_VOLTAGE"].offset = std::bind(&canlib_circular_buffer<primary_message_LV_TOTAL_VOLTAGE_conversion, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.LV_TOTAL_VOLTAGE);
    mapping_map["LV_TOTAL_VOLTAGE"].stride = sizeof(primary_message_LV_TOTAL_VOLTAGE_conversion);
    mapping_map["LV_TOTAL_VOLTAGE"].field["total_voltage"].value._float32 = &pack.LV_TOTAL_VOLTAGE.start().total_voltage;
    mapping_map["LV_TOTAL_VOLTAGE"].field["total_voltage"].type = mapping_type_float32;
#ifdef CANLIB_TIMESTAMP
    mapping_map["LV_TOTAL_VOLTAGE"].field["_timestamp"].value._uint64 = &pack.LV_TOTAL_VOLTAGE.start()._timestamp;
    mapping_map["LV_TOTAL_VOLTAGE"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["LV_TEMPERATURE"].size = std::bind(&canlib_circular_buffer<primary_message_LV_TEMPERATURE_conversion, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.LV_TEMPERATURE);
    mapping_map["LV_TEMPERATURE"].offset = std::bind(&canlib_circular_buffer<primary_message_LV_TEMPERATURE_conversion, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.LV_TEMPERATURE);
    mapping_map["LV_TEMPERATURE"].stride = sizeof(primary_message_LV_TEMPERATURE_conversion);
    mapping_map["LV_TEMPERATURE"].field["bp_temperature_1"].value._float32 = &pack.LV_TEMPERATURE.start().bp_temperature_1;
    mapping_map["LV_TEMPERATURE"].field["bp_temperature_1"].type = mapping_type_float32;
    mapping_map["LV_TEMPERATURE"].field["bp_temperature_2"].value._float32 = &pack.LV_TEMPERATURE.start().bp_temperature_2;
    mapping_map["LV_TEMPERATURE"].field["bp_temperature_2"].type = mapping_type_float32;
    mapping_map["LV_TEMPERATURE"].field["dcdc12_temperature"].value._float32 = &pack.LV_TEMPERATURE.start().dcdc12_temperature;
    mapping_map["LV_TEMPERATURE"].field["dcdc12_temperature"].type = mapping_type_float32;
    mapping_map["LV_TEMPERATURE"].field["dcdc24_temperature"].value._float32 = &pack.LV_TEMPERATURE.start().dcdc24_temperature;
    mapping_map["LV_TEMPERATURE"].field["dcdc24_temperature"].type = mapping_type_float32;
#ifdef CANLIB_TIMESTAMP
    mapping_map["LV_TEMPERATURE"].field["_timestamp"].value._uint64 = &pack.LV_TEMPERATURE.start()._timestamp;
    mapping_map["LV_TEMPERATURE"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["COOLING_STATUS"].size = std::bind(&canlib_circular_buffer<primary_message_COOLING_STATUS_conversion, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.COOLING_STATUS);
    mapping_map["COOLING_STATUS"].offset = std::bind(&canlib_circular_buffer<primary_message_COOLING_STATUS_conversion, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.COOLING_STATUS);
    mapping_map["COOLING_STATUS"].stride = sizeof(primary_message_COOLING_STATUS_conversion);
    mapping_map["COOLING_STATUS"].field["radiators_speed"].value._float32 = &pack.COOLING_STATUS.start().radiators_speed;
    mapping_map["COOLING_STATUS"].field["radiators_speed"].type = mapping_type_float32;
    mapping_map["COOLING_STATUS"].field["pumps_speed"].value._float32 = &pack.COOLING_STATUS.start().pumps_speed;
    mapping_map["COOLING_STATUS"].field["pumps_speed"].type = mapping_type_float32;
#ifdef CANLIB_TIMESTAMP
    mapping_map["COOLING_STATUS"].field["_timestamp"].value._uint64 = &pack.COOLING_STATUS.start()._timestamp;
    mapping_map["COOLING_STATUS"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["SET_RADIATOR_SPEED"].size = std::bind(&canlib_circular_buffer<primary_message_SET_RADIATOR_SPEED_conversion, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.SET_RADIATOR_SPEED);
    mapping_map["SET_RADIATOR_SPEED"].offset = std::bind(&canlib_circular_buffer<primary_message_SET_RADIATOR_SPEED_conversion, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.SET_RADIATOR_SPEED);
    mapping_map["SET_RADIATOR_SPEED"].stride = sizeof(primary_message_SET_RADIATOR_SPEED_conversion);
    mapping_map["SET_RADIATOR_SPEED"].field["radiators_speed"].value._float32 = &pack.SET_RADIATOR_SPEED.start().radiators_speed;
    mapping_map["SET_RADIATOR_SPEED"].field["radiators_speed"].type = mapping_type_float32;
#ifdef CANLIB_TIMESTAMP
    mapping_map["SET_RADIATOR_SPEED"].field["_timestamp"].value._uint64 = &pack.SET_RADIATOR_SPEED.start()._timestamp;
    mapping_map["SET_RADIATOR_SPEED"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["SET_PUMPS_SPEED"].size = std::bind(&canlib_circular_buffer<primary_message_SET_PUMPS_SPEED_conversion, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.SET_PUMPS_SPEED);
    mapping_map["SET_PUMPS_SPEED"].offset = std::bind(&canlib_circular_buffer<primary_message_SET_PUMPS_SPEED_conversion, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.SET_PUMPS_SPEED);
    mapping_map["SET_PUMPS_SPEED"].stride = sizeof(primary_message_SET_PUMPS_SPEED_conversion);
    mapping_map["SET_PUMPS_SPEED"].field["pumps_speed"].value._float32 = &pack.SET_PUMPS_SPEED.start().pumps_speed;
    mapping_map["SET_PUMPS_SPEED"].field["pumps_speed"].type = mapping_type_float32;
#ifdef CANLIB_TIMESTAMP
    mapping_map["SET_PUMPS_SPEED"].field["_timestamp"].value._uint64 = &pack.SET_PUMPS_SPEED.start()._timestamp;
    mapping_map["SET_PUMPS_SPEED"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["SET_INVERTER_CONNECTION_STATUS"].size = std::bind(&canlib_circular_buffer<primary_message_SET_INVERTER_CONNECTION_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.SET_INVERTER_CONNECTION_STATUS);
    mapping_map["SET_INVERTER_CONNECTION_STATUS"].offset = std::bind(&canlib_circular_buffer<primary_message_SET_INVERTER_CONNECTION_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.SET_INVERTER_CONNECTION_STATUS);
    mapping_map["SET_INVERTER_CONNECTION_STATUS"].stride = sizeof(primary_message_SET_INVERTER_CONNECTION_STATUS);
    mapping_map["SET_INVERTER_CONNECTION_STATUS"].field["status"].value._uint16 = (uint16_t*)&pack.SET_INVERTER_CONNECTION_STATUS.start().status;
    mapping_map["SET_INVERTER_CONNECTION_STATUS"].field["status"].type = mapping_type_uint16;
#ifdef CANLIB_TIMESTAMP
    mapping_map["SET_INVERTER_CONNECTION_STATUS"].field["_timestamp"].value._uint64 = &pack.SET_INVERTER_CONNECTION_STATUS.start()._timestamp;
    mapping_map["SET_INVERTER_CONNECTION_STATUS"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["INVERTER_CONNECTION_STATUS"].size = std::bind(&canlib_circular_buffer<primary_message_INVERTER_CONNECTION_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.INVERTER_CONNECTION_STATUS);
    mapping_map["INVERTER_CONNECTION_STATUS"].offset = std::bind(&canlib_circular_buffer<primary_message_INVERTER_CONNECTION_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.INVERTER_CONNECTION_STATUS);
    mapping_map["INVERTER_CONNECTION_STATUS"].stride = sizeof(primary_message_INVERTER_CONNECTION_STATUS);
    mapping_map["INVERTER_CONNECTION_STATUS"].field["status"].value._uint16 = (uint16_t*)&pack.INVERTER_CONNECTION_STATUS.start().status;
    mapping_map["INVERTER_CONNECTION_STATUS"].field["status"].type = mapping_type_uint16;
#ifdef CANLIB_TIMESTAMP
    mapping_map["INVERTER_CONNECTION_STATUS"].field["_timestamp"].value._uint64 = &pack.INVERTER_CONNECTION_STATUS.start()._timestamp;
    mapping_map["INVERTER_CONNECTION_STATUS"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["LV_ERRORS"].size = std::bind(&canlib_circular_buffer<primary_message_LV_ERRORS, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.LV_ERRORS);
    mapping_map["LV_ERRORS"].offset = std::bind(&canlib_circular_buffer<primary_message_LV_ERRORS, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.LV_ERRORS);
    mapping_map["LV_ERRORS"].stride = sizeof(primary_message_LV_ERRORS);
    mapping_map["LV_ERRORS"].field["warnings"].value._uint16 = (uint16_t*)&pack.LV_ERRORS.start().warnings;
    mapping_map["LV_ERRORS"].field["warnings"].type = mapping_type_uint16;
    mapping_map["LV_ERRORS"].field["errors"].value._uint16 = (uint16_t*)&pack.LV_ERRORS.start().errors;
    mapping_map["LV_ERRORS"].field["errors"].type = mapping_type_uint16;
#ifdef CANLIB_TIMESTAMP
    mapping_map["LV_ERRORS"].field["_timestamp"].value._uint64 = &pack.LV_ERRORS.start()._timestamp;
    mapping_map["LV_ERRORS"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["SHUTDOWN_STATUS"].size = std::bind(&canlib_circular_buffer<primary_message_SHUTDOWN_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.SHUTDOWN_STATUS);
    mapping_map["SHUTDOWN_STATUS"].offset = std::bind(&canlib_circular_buffer<primary_message_SHUTDOWN_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.SHUTDOWN_STATUS);
    mapping_map["SHUTDOWN_STATUS"].stride = sizeof(primary_message_SHUTDOWN_STATUS);
    mapping_map["SHUTDOWN_STATUS"].field["input"].value._bool = &pack.SHUTDOWN_STATUS.start().input;
    mapping_map["SHUTDOWN_STATUS"].field["input"].type = mapping_type_bool;
    mapping_map["SHUTDOWN_STATUS"].field["output"].value._bool = &pack.SHUTDOWN_STATUS.start().output;
    mapping_map["SHUTDOWN_STATUS"].field["output"].type = mapping_type_bool;
#ifdef CANLIB_TIMESTAMP
    mapping_map["SHUTDOWN_STATUS"].field["_timestamp"].value._uint64 = &pack.SHUTDOWN_STATUS.start()._timestamp;
    mapping_map["SHUTDOWN_STATUS"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["MARKER"].size = std::bind(&canlib_circular_buffer<primary_message_MARKER, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.MARKER);
    mapping_map["MARKER"].offset = std::bind(&canlib_circular_buffer<primary_message_MARKER, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.MARKER);
    mapping_map["MARKER"].stride = sizeof(primary_message_MARKER);
#ifdef CANLIB_TIMESTAMP
    mapping_map["MARKER"].field["_timestamp"].value._uint64 = &pack.MARKER.start()._timestamp;
    mapping_map["MARKER"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["HV_CELLS_VOLTAGE"].size = std::bind(&canlib_circular_buffer<primary_message_HV_CELLS_VOLTAGE_conversion, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.HV_CELLS_VOLTAGE);
    mapping_map["HV_CELLS_VOLTAGE"].offset = std::bind(&canlib_circular_buffer<primary_message_HV_CELLS_VOLTAGE_conversion, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.HV_CELLS_VOLTAGE);
    mapping_map["HV_CELLS_VOLTAGE"].stride = sizeof(primary_message_HV_CELLS_VOLTAGE_conversion);
    mapping_map["HV_CELLS_VOLTAGE"].field["start_index"].value._uint8 = &pack.HV_CELLS_VOLTAGE.start().start_index;
    mapping_map["HV_CELLS_VOLTAGE"].field["start_index"].type = mapping_type_uint8;
    mapping_map["HV_CELLS_VOLTAGE"].field["voltage_0"].value._float32 = &pack.HV_CELLS_VOLTAGE.start().voltage_0;
    mapping_map["HV_CELLS_VOLTAGE"].field["voltage_0"].type = mapping_type_float32;
    mapping_map["HV_CELLS_VOLTAGE"].field["voltage_1"].value._float32 = &pack.HV_CELLS_VOLTAGE.start().voltage_1;
    mapping_map["HV_CELLS_VOLTAGE"].field["voltage_1"].type = mapping_type_float32;
    mapping_map["HV_CELLS_VOLTAGE"].field["voltage_2"].value._float32 = &pack.HV_CELLS_VOLTAGE.start().voltage_2;
    mapping_map["HV_CELLS_VOLTAGE"].field["voltage_2"].type = mapping_type_float32;
#ifdef CANLIB_TIMESTAMP
    mapping_map["HV_CELLS_VOLTAGE"].field["_timestamp"].value._uint64 = &pack.HV_CELLS_VOLTAGE.start()._timestamp;
    mapping_map["HV_CELLS_VOLTAGE"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["HV_CELLS_TEMP"].size = std::bind(&canlib_circular_buffer<primary_message_HV_CELLS_TEMP_conversion, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.HV_CELLS_TEMP);
    mapping_map["HV_CELLS_TEMP"].offset = std::bind(&canlib_circular_buffer<primary_message_HV_CELLS_TEMP_conversion, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.HV_CELLS_TEMP);
    mapping_map["HV_CELLS_TEMP"].stride = sizeof(primary_message_HV_CELLS_TEMP_conversion);
    mapping_map["HV_CELLS_TEMP"].field["start_index"].value._uint8 = &pack.HV_CELLS_TEMP.start().start_index;
    mapping_map["HV_CELLS_TEMP"].field["start_index"].type = mapping_type_uint8;
    mapping_map["HV_CELLS_TEMP"].field["temp_0"].value._float32 = &pack.HV_CELLS_TEMP.start().temp_0;
    mapping_map["HV_CELLS_TEMP"].field["temp_0"].type = mapping_type_float32;
    mapping_map["HV_CELLS_TEMP"].field["temp_1"].value._float32 = &pack.HV_CELLS_TEMP.start().temp_1;
    mapping_map["HV_CELLS_TEMP"].field["temp_1"].type = mapping_type_float32;
    mapping_map["HV_CELLS_TEMP"].field["temp_2"].value._float32 = &pack.HV_CELLS_TEMP.start().temp_2;
    mapping_map["HV_CELLS_TEMP"].field["temp_2"].type = mapping_type_float32;
    mapping_map["HV_CELLS_TEMP"].field["temp_3"].value._float32 = &pack.HV_CELLS_TEMP.start().temp_3;
    mapping_map["HV_CELLS_TEMP"].field["temp_3"].type = mapping_type_float32;
    mapping_map["HV_CELLS_TEMP"].field["temp_4"].value._float32 = &pack.HV_CELLS_TEMP.start().temp_4;
    mapping_map["HV_CELLS_TEMP"].field["temp_4"].type = mapping_type_float32;
    mapping_map["HV_CELLS_TEMP"].field["temp_5"].value._float32 = &pack.HV_CELLS_TEMP.start().temp_5;
    mapping_map["HV_CELLS_TEMP"].field["temp_5"].type = mapping_type_float32;
#ifdef CANLIB_TIMESTAMP
    mapping_map["HV_CELLS_TEMP"].field["_timestamp"].value._uint64 = &pack.HV_CELLS_TEMP.start()._timestamp;
    mapping_map["HV_CELLS_TEMP"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["HV_CELL_BALANCING_STATUS"].size = std::bind(&canlib_circular_buffer<primary_message_HV_CELL_BALANCING_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.HV_CELL_BALANCING_STATUS);
    mapping_map["HV_CELL_BALANCING_STATUS"].offset = std::bind(&canlib_circular_buffer<primary_message_HV_CELL_BALANCING_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.HV_CELL_BALANCING_STATUS);
    mapping_map["HV_CELL_BALANCING_STATUS"].stride = sizeof(primary_message_HV_CELL_BALANCING_STATUS);
    mapping_map["HV_CELL_BALANCING_STATUS"].field["balancing_status"].value._uint16 = (uint16_t*)&pack.HV_CELL_BALANCING_STATUS.start().balancing_status;
    mapping_map["HV_CELL_BALANCING_STATUS"].field["balancing_status"].type = mapping_type_uint16;
#ifdef CANLIB_TIMESTAMP
    mapping_map["HV_CELL_BALANCING_STATUS"].field["_timestamp"].value._uint64 = &pack.HV_CELL_BALANCING_STATUS.start()._timestamp;
    mapping_map["HV_CELL_BALANCING_STATUS"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["SET_CELL_BALANCING_STATUS"].size = std::bind(&canlib_circular_buffer<primary_message_SET_CELL_BALANCING_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.SET_CELL_BALANCING_STATUS);
    mapping_map["SET_CELL_BALANCING_STATUS"].offset = std::bind(&canlib_circular_buffer<primary_message_SET_CELL_BALANCING_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.SET_CELL_BALANCING_STATUS);
    mapping_map["SET_CELL_BALANCING_STATUS"].stride = sizeof(primary_message_SET_CELL_BALANCING_STATUS);
    mapping_map["SET_CELL_BALANCING_STATUS"].field["set_balancing_status"].value._uint16 = (uint16_t*)&pack.SET_CELL_BALANCING_STATUS.start().set_balancing_status;
    mapping_map["SET_CELL_BALANCING_STATUS"].field["set_balancing_status"].type = mapping_type_uint16;
#ifdef CANLIB_TIMESTAMP
    mapping_map["SET_CELL_BALANCING_STATUS"].field["_timestamp"].value._uint64 = &pack.SET_CELL_BALANCING_STATUS.start()._timestamp;
    mapping_map["SET_CELL_BALANCING_STATUS"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["HANDCART_STATUS"].size = std::bind(&canlib_circular_buffer<primary_message_HANDCART_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.HANDCART_STATUS);
    mapping_map["HANDCART_STATUS"].offset = std::bind(&canlib_circular_buffer<primary_message_HANDCART_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.HANDCART_STATUS);
    mapping_map["HANDCART_STATUS"].stride = sizeof(primary_message_HANDCART_STATUS);
    mapping_map["HANDCART_STATUS"].field["connected"].value._bool = &pack.HANDCART_STATUS.start().connected;
    mapping_map["HANDCART_STATUS"].field["connected"].type = mapping_type_bool;
#ifdef CANLIB_TIMESTAMP
    mapping_map["HANDCART_STATUS"].field["_timestamp"].value._uint64 = &pack.HANDCART_STATUS.start()._timestamp;
    mapping_map["HANDCART_STATUS"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["SPEED"].size = std::bind(&canlib_circular_buffer<primary_message_SPEED_conversion, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.SPEED);
    mapping_map["SPEED"].offset = std::bind(&canlib_circular_buffer<primary_message_SPEED_conversion, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.SPEED);
    mapping_map["SPEED"].stride = sizeof(primary_message_SPEED_conversion);
    mapping_map["SPEED"].field["encoder_r"].value._float32 = &pack.SPEED.start().encoder_r;
    mapping_map["SPEED"].field["encoder_r"].type = mapping_type_float32;
    mapping_map["SPEED"].field["encoder_l"].value._float32 = &pack.SPEED.start().encoder_l;
    mapping_map["SPEED"].field["encoder_l"].type = mapping_type_float32;
    mapping_map["SPEED"].field["inverter_r"].value._float32 = &pack.SPEED.start().inverter_r;
    mapping_map["SPEED"].field["inverter_r"].type = mapping_type_float32;
    mapping_map["SPEED"].field["inverter_l"].value._float32 = &pack.SPEED.start().inverter_l;
    mapping_map["SPEED"].field["inverter_l"].type = mapping_type_float32;
#ifdef CANLIB_TIMESTAMP
    mapping_map["SPEED"].field["_timestamp"].value._uint64 = &pack.SPEED.start()._timestamp;
    mapping_map["SPEED"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["INV_L_REQUEST"].size = std::bind(&canlib_circular_buffer<primary_message_INV_L_REQUEST, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.INV_L_REQUEST);
    mapping_map["INV_L_REQUEST"].offset = std::bind(&canlib_circular_buffer<primary_message_INV_L_REQUEST, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.INV_L_REQUEST);
    mapping_map["INV_L_REQUEST"].stride = sizeof(primary_message_INV_L_REQUEST);
    mapping_map["INV_L_REQUEST"].field["data_0"].value._uint8 = &pack.INV_L_REQUEST.start().data_0;
    mapping_map["INV_L_REQUEST"].field["data_0"].type = mapping_type_uint8;
    mapping_map["INV_L_REQUEST"].field["data_1"].value._uint8 = &pack.INV_L_REQUEST.start().data_1;
    mapping_map["INV_L_REQUEST"].field["data_1"].type = mapping_type_uint8;
    mapping_map["INV_L_REQUEST"].field["data_2"].value._uint8 = &pack.INV_L_REQUEST.start().data_2;
    mapping_map["INV_L_REQUEST"].field["data_2"].type = mapping_type_uint8;
    mapping_map["INV_L_REQUEST"].field["data_3"].value._uint8 = &pack.INV_L_REQUEST.start().data_3;
    mapping_map["INV_L_REQUEST"].field["data_3"].type = mapping_type_uint8;
    mapping_map["INV_L_REQUEST"].field["data_4"].value._uint8 = &pack.INV_L_REQUEST.start().data_4;
    mapping_map["INV_L_REQUEST"].field["data_4"].type = mapping_type_uint8;
    mapping_map["INV_L_REQUEST"].field["data_5"].value._uint8 = &pack.INV_L_REQUEST.start().data_5;
    mapping_map["INV_L_REQUEST"].field["data_5"].type = mapping_type_uint8;
    mapping_map["INV_L_REQUEST"].field["data_6"].value._uint8 = &pack.INV_L_REQUEST.start().data_6;
    mapping_map["INV_L_REQUEST"].field["data_6"].type = mapping_type_uint8;
    mapping_map["INV_L_REQUEST"].field["data_7"].value._uint8 = &pack.INV_L_REQUEST.start().data_7;
    mapping_map["INV_L_REQUEST"].field["data_7"].type = mapping_type_uint8;
#ifdef CANLIB_TIMESTAMP
    mapping_map["INV_L_REQUEST"].field["_timestamp"].value._uint64 = &pack.INV_L_REQUEST.start()._timestamp;
    mapping_map["INV_L_REQUEST"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["INV_R_REQUEST"].size = std::bind(&canlib_circular_buffer<primary_message_INV_R_REQUEST, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.INV_R_REQUEST);
    mapping_map["INV_R_REQUEST"].offset = std::bind(&canlib_circular_buffer<primary_message_INV_R_REQUEST, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.INV_R_REQUEST);
    mapping_map["INV_R_REQUEST"].stride = sizeof(primary_message_INV_R_REQUEST);
    mapping_map["INV_R_REQUEST"].field["data_0"].value._uint8 = &pack.INV_R_REQUEST.start().data_0;
    mapping_map["INV_R_REQUEST"].field["data_0"].type = mapping_type_uint8;
    mapping_map["INV_R_REQUEST"].field["data_1"].value._uint8 = &pack.INV_R_REQUEST.start().data_1;
    mapping_map["INV_R_REQUEST"].field["data_1"].type = mapping_type_uint8;
    mapping_map["INV_R_REQUEST"].field["data_2"].value._uint8 = &pack.INV_R_REQUEST.start().data_2;
    mapping_map["INV_R_REQUEST"].field["data_2"].type = mapping_type_uint8;
    mapping_map["INV_R_REQUEST"].field["data_3"].value._uint8 = &pack.INV_R_REQUEST.start().data_3;
    mapping_map["INV_R_REQUEST"].field["data_3"].type = mapping_type_uint8;
    mapping_map["INV_R_REQUEST"].field["data_4"].value._uint8 = &pack.INV_R_REQUEST.start().data_4;
    mapping_map["INV_R_REQUEST"].field["data_4"].type = mapping_type_uint8;
    mapping_map["INV_R_REQUEST"].field["data_5"].value._uint8 = &pack.INV_R_REQUEST.start().data_5;
    mapping_map["INV_R_REQUEST"].field["data_5"].type = mapping_type_uint8;
    mapping_map["INV_R_REQUEST"].field["data_6"].value._uint8 = &pack.INV_R_REQUEST.start().data_6;
    mapping_map["INV_R_REQUEST"].field["data_6"].type = mapping_type_uint8;
    mapping_map["INV_R_REQUEST"].field["data_7"].value._uint8 = &pack.INV_R_REQUEST.start().data_7;
    mapping_map["INV_R_REQUEST"].field["data_7"].type = mapping_type_uint8;
#ifdef CANLIB_TIMESTAMP
    mapping_map["INV_R_REQUEST"].field["_timestamp"].value._uint64 = &pack.INV_R_REQUEST.start()._timestamp;
    mapping_map["INV_R_REQUEST"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["INV_L_RESPONSE"].size = std::bind(&canlib_circular_buffer<primary_message_INV_L_RESPONSE, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.INV_L_RESPONSE);
    mapping_map["INV_L_RESPONSE"].offset = std::bind(&canlib_circular_buffer<primary_message_INV_L_RESPONSE, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.INV_L_RESPONSE);
    mapping_map["INV_L_RESPONSE"].stride = sizeof(primary_message_INV_L_RESPONSE);
    mapping_map["INV_L_RESPONSE"].field["reg_id"].value._uint8 = &pack.INV_L_RESPONSE.start().reg_id;
    mapping_map["INV_L_RESPONSE"].field["reg_id"].type = mapping_type_uint8;
    mapping_map["INV_L_RESPONSE"].field["data_0"].value._uint8 = &pack.INV_L_RESPONSE.start().data_0;
    mapping_map["INV_L_RESPONSE"].field["data_0"].type = mapping_type_uint8;
    mapping_map["INV_L_RESPONSE"].field["data_1"].value._uint8 = &pack.INV_L_RESPONSE.start().data_1;
    mapping_map["INV_L_RESPONSE"].field["data_1"].type = mapping_type_uint8;
    mapping_map["INV_L_RESPONSE"].field["data_2"].value._uint8 = &pack.INV_L_RESPONSE.start().data_2;
    mapping_map["INV_L_RESPONSE"].field["data_2"].type = mapping_type_uint8;
    mapping_map["INV_L_RESPONSE"].field["data_3"].value._uint8 = &pack.INV_L_RESPONSE.start().data_3;
    mapping_map["INV_L_RESPONSE"].field["data_3"].type = mapping_type_uint8;
    mapping_map["INV_L_RESPONSE"].field["data_4"].value._uint8 = &pack.INV_L_RESPONSE.start().data_4;
    mapping_map["INV_L_RESPONSE"].field["data_4"].type = mapping_type_uint8;
    mapping_map["INV_L_RESPONSE"].field["data_5"].value._uint8 = &pack.INV_L_RESPONSE.start().data_5;
    mapping_map["INV_L_RESPONSE"].field["data_5"].type = mapping_type_uint8;
    mapping_map["INV_L_RESPONSE"].field["data_6"].value._uint8 = &pack.INV_L_RESPONSE.start().data_6;
    mapping_map["INV_L_RESPONSE"].field["data_6"].type = mapping_type_uint8;
#ifdef CANLIB_TIMESTAMP
    mapping_map["INV_L_RESPONSE"].field["_timestamp"].value._uint64 = &pack.INV_L_RESPONSE.start()._timestamp;
    mapping_map["INV_L_RESPONSE"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["INV_R_RESPONSE"].size = std::bind(&canlib_circular_buffer<primary_message_INV_R_RESPONSE, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.INV_R_RESPONSE);
    mapping_map["INV_R_RESPONSE"].offset = std::bind(&canlib_circular_buffer<primary_message_INV_R_RESPONSE, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.INV_R_RESPONSE);
    mapping_map["INV_R_RESPONSE"].stride = sizeof(primary_message_INV_R_RESPONSE);
    mapping_map["INV_R_RESPONSE"].field["reg_id"].value._uint8 = &pack.INV_R_RESPONSE.start().reg_id;
    mapping_map["INV_R_RESPONSE"].field["reg_id"].type = mapping_type_uint8;
    mapping_map["INV_R_RESPONSE"].field["data_0"].value._uint8 = &pack.INV_R_RESPONSE.start().data_0;
    mapping_map["INV_R_RESPONSE"].field["data_0"].type = mapping_type_uint8;
    mapping_map["INV_R_RESPONSE"].field["data_1"].value._uint8 = &pack.INV_R_RESPONSE.start().data_1;
    mapping_map["INV_R_RESPONSE"].field["data_1"].type = mapping_type_uint8;
    mapping_map["INV_R_RESPONSE"].field["data_2"].value._uint8 = &pack.INV_R_RESPONSE.start().data_2;
    mapping_map["INV_R_RESPONSE"].field["data_2"].type = mapping_type_uint8;
    mapping_map["INV_R_RESPONSE"].field["data_3"].value._uint8 = &pack.INV_R_RESPONSE.start().data_3;
    mapping_map["INV_R_RESPONSE"].field["data_3"].type = mapping_type_uint8;
    mapping_map["INV_R_RESPONSE"].field["data_4"].value._uint8 = &pack.INV_R_RESPONSE.start().data_4;
    mapping_map["INV_R_RESPONSE"].field["data_4"].type = mapping_type_uint8;
    mapping_map["INV_R_RESPONSE"].field["data_5"].value._uint8 = &pack.INV_R_RESPONSE.start().data_5;
    mapping_map["INV_R_RESPONSE"].field["data_5"].type = mapping_type_uint8;
    mapping_map["INV_R_RESPONSE"].field["data_6"].value._uint8 = &pack.INV_R_RESPONSE.start().data_6;
    mapping_map["INV_R_RESPONSE"].field["data_6"].type = mapping_type_uint8;
#ifdef CANLIB_TIMESTAMP
    mapping_map["INV_R_RESPONSE"].field["_timestamp"].value._uint64 = &pack.INV_R_RESPONSE.start()._timestamp;
    mapping_map["INV_R_RESPONSE"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["FLASH_CELLBOARD_0_TX"].size = std::bind(&canlib_circular_buffer<primary_message_FLASH_CELLBOARD_0_TX, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.FLASH_CELLBOARD_0_TX);
    mapping_map["FLASH_CELLBOARD_0_TX"].offset = std::bind(&canlib_circular_buffer<primary_message_FLASH_CELLBOARD_0_TX, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.FLASH_CELLBOARD_0_TX);
    mapping_map["FLASH_CELLBOARD_0_TX"].stride = sizeof(primary_message_FLASH_CELLBOARD_0_TX);
#ifdef CANLIB_TIMESTAMP
    mapping_map["FLASH_CELLBOARD_0_TX"].field["_timestamp"].value._uint64 = &pack.FLASH_CELLBOARD_0_TX.start()._timestamp;
    mapping_map["FLASH_CELLBOARD_0_TX"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["FLASH_CELLBOARD_0_RX"].size = std::bind(&canlib_circular_buffer<primary_message_FLASH_CELLBOARD_0_RX, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.FLASH_CELLBOARD_0_RX);
    mapping_map["FLASH_CELLBOARD_0_RX"].offset = std::bind(&canlib_circular_buffer<primary_message_FLASH_CELLBOARD_0_RX, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.FLASH_CELLBOARD_0_RX);
    mapping_map["FLASH_CELLBOARD_0_RX"].stride = sizeof(primary_message_FLASH_CELLBOARD_0_RX);
#ifdef CANLIB_TIMESTAMP
    mapping_map["FLASH_CELLBOARD_0_RX"].field["_timestamp"].value._uint64 = &pack.FLASH_CELLBOARD_0_RX.start()._timestamp;
    mapping_map["FLASH_CELLBOARD_0_RX"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["FLASH_CELLBOARD_1_TX"].size = std::bind(&canlib_circular_buffer<primary_message_FLASH_CELLBOARD_1_TX, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.FLASH_CELLBOARD_1_TX);
    mapping_map["FLASH_CELLBOARD_1_TX"].offset = std::bind(&canlib_circular_buffer<primary_message_FLASH_CELLBOARD_1_TX, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.FLASH_CELLBOARD_1_TX);
    mapping_map["FLASH_CELLBOARD_1_TX"].stride = sizeof(primary_message_FLASH_CELLBOARD_1_TX);
#ifdef CANLIB_TIMESTAMP
    mapping_map["FLASH_CELLBOARD_1_TX"].field["_timestamp"].value._uint64 = &pack.FLASH_CELLBOARD_1_TX.start()._timestamp;
    mapping_map["FLASH_CELLBOARD_1_TX"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["FLASH_CELLBOARD_1_RX"].size = std::bind(&canlib_circular_buffer<primary_message_FLASH_CELLBOARD_1_RX, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.FLASH_CELLBOARD_1_RX);
    mapping_map["FLASH_CELLBOARD_1_RX"].offset = std::bind(&canlib_circular_buffer<primary_message_FLASH_CELLBOARD_1_RX, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.FLASH_CELLBOARD_1_RX);
    mapping_map["FLASH_CELLBOARD_1_RX"].stride = sizeof(primary_message_FLASH_CELLBOARD_1_RX);
#ifdef CANLIB_TIMESTAMP
    mapping_map["FLASH_CELLBOARD_1_RX"].field["_timestamp"].value._uint64 = &pack.FLASH_CELLBOARD_1_RX.start()._timestamp;
    mapping_map["FLASH_CELLBOARD_1_RX"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["FLASH_CELLBOARD_2_TX"].size = std::bind(&canlib_circular_buffer<primary_message_FLASH_CELLBOARD_2_TX, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.FLASH_CELLBOARD_2_TX);
    mapping_map["FLASH_CELLBOARD_2_TX"].offset = std::bind(&canlib_circular_buffer<primary_message_FLASH_CELLBOARD_2_TX, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.FLASH_CELLBOARD_2_TX);
    mapping_map["FLASH_CELLBOARD_2_TX"].stride = sizeof(primary_message_FLASH_CELLBOARD_2_TX);
#ifdef CANLIB_TIMESTAMP
    mapping_map["FLASH_CELLBOARD_2_TX"].field["_timestamp"].value._uint64 = &pack.FLASH_CELLBOARD_2_TX.start()._timestamp;
    mapping_map["FLASH_CELLBOARD_2_TX"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["FLASH_CELLBOARD_2_RX"].size = std::bind(&canlib_circular_buffer<primary_message_FLASH_CELLBOARD_2_RX, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.FLASH_CELLBOARD_2_RX);
    mapping_map["FLASH_CELLBOARD_2_RX"].offset = std::bind(&canlib_circular_buffer<primary_message_FLASH_CELLBOARD_2_RX, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.FLASH_CELLBOARD_2_RX);
    mapping_map["FLASH_CELLBOARD_2_RX"].stride = sizeof(primary_message_FLASH_CELLBOARD_2_RX);
#ifdef CANLIB_TIMESTAMP
    mapping_map["FLASH_CELLBOARD_2_RX"].field["_timestamp"].value._uint64 = &pack.FLASH_CELLBOARD_2_RX.start()._timestamp;
    mapping_map["FLASH_CELLBOARD_2_RX"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["FLASH_CELLBOARD_3_TX"].size = std::bind(&canlib_circular_buffer<primary_message_FLASH_CELLBOARD_3_TX, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.FLASH_CELLBOARD_3_TX);
    mapping_map["FLASH_CELLBOARD_3_TX"].offset = std::bind(&canlib_circular_buffer<primary_message_FLASH_CELLBOARD_3_TX, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.FLASH_CELLBOARD_3_TX);
    mapping_map["FLASH_CELLBOARD_3_TX"].stride = sizeof(primary_message_FLASH_CELLBOARD_3_TX);
#ifdef CANLIB_TIMESTAMP
    mapping_map["FLASH_CELLBOARD_3_TX"].field["_timestamp"].value._uint64 = &pack.FLASH_CELLBOARD_3_TX.start()._timestamp;
    mapping_map["FLASH_CELLBOARD_3_TX"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["FLASH_CELLBOARD_3_RX"].size = std::bind(&canlib_circular_buffer<primary_message_FLASH_CELLBOARD_3_RX, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.FLASH_CELLBOARD_3_RX);
    mapping_map["FLASH_CELLBOARD_3_RX"].offset = std::bind(&canlib_circular_buffer<primary_message_FLASH_CELLBOARD_3_RX, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.FLASH_CELLBOARD_3_RX);
    mapping_map["FLASH_CELLBOARD_3_RX"].stride = sizeof(primary_message_FLASH_CELLBOARD_3_RX);
#ifdef CANLIB_TIMESTAMP
    mapping_map["FLASH_CELLBOARD_3_RX"].field["_timestamp"].value._uint64 = &pack.FLASH_CELLBOARD_3_RX.start()._timestamp;
    mapping_map["FLASH_CELLBOARD_3_RX"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["FLASH_CELLBOARD_4_TX"].size = std::bind(&canlib_circular_buffer<primary_message_FLASH_CELLBOARD_4_TX, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.FLASH_CELLBOARD_4_TX);
    mapping_map["FLASH_CELLBOARD_4_TX"].offset = std::bind(&canlib_circular_buffer<primary_message_FLASH_CELLBOARD_4_TX, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.FLASH_CELLBOARD_4_TX);
    mapping_map["FLASH_CELLBOARD_4_TX"].stride = sizeof(primary_message_FLASH_CELLBOARD_4_TX);
#ifdef CANLIB_TIMESTAMP
    mapping_map["FLASH_CELLBOARD_4_TX"].field["_timestamp"].value._uint64 = &pack.FLASH_CELLBOARD_4_TX.start()._timestamp;
    mapping_map["FLASH_CELLBOARD_4_TX"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["FLASH_CELLBOARD_4_RX"].size = std::bind(&canlib_circular_buffer<primary_message_FLASH_CELLBOARD_4_RX, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.FLASH_CELLBOARD_4_RX);
    mapping_map["FLASH_CELLBOARD_4_RX"].offset = std::bind(&canlib_circular_buffer<primary_message_FLASH_CELLBOARD_4_RX, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.FLASH_CELLBOARD_4_RX);
    mapping_map["FLASH_CELLBOARD_4_RX"].stride = sizeof(primary_message_FLASH_CELLBOARD_4_RX);
#ifdef CANLIB_TIMESTAMP
    mapping_map["FLASH_CELLBOARD_4_RX"].field["_timestamp"].value._uint64 = &pack.FLASH_CELLBOARD_4_RX.start()._timestamp;
    mapping_map["FLASH_CELLBOARD_4_RX"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["FLASH_CELLBOARD_5_TX"].size = std::bind(&canlib_circular_buffer<primary_message_FLASH_CELLBOARD_5_TX, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.FLASH_CELLBOARD_5_TX);
    mapping_map["FLASH_CELLBOARD_5_TX"].offset = std::bind(&canlib_circular_buffer<primary_message_FLASH_CELLBOARD_5_TX, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.FLASH_CELLBOARD_5_TX);
    mapping_map["FLASH_CELLBOARD_5_TX"].stride = sizeof(primary_message_FLASH_CELLBOARD_5_TX);
#ifdef CANLIB_TIMESTAMP
    mapping_map["FLASH_CELLBOARD_5_TX"].field["_timestamp"].value._uint64 = &pack.FLASH_CELLBOARD_5_TX.start()._timestamp;
    mapping_map["FLASH_CELLBOARD_5_TX"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["FLASH_CELLBOARD_5_RX"].size = std::bind(&canlib_circular_buffer<primary_message_FLASH_CELLBOARD_5_RX, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.FLASH_CELLBOARD_5_RX);
    mapping_map["FLASH_CELLBOARD_5_RX"].offset = std::bind(&canlib_circular_buffer<primary_message_FLASH_CELLBOARD_5_RX, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.FLASH_CELLBOARD_5_RX);
    mapping_map["FLASH_CELLBOARD_5_RX"].stride = sizeof(primary_message_FLASH_CELLBOARD_5_RX);
#ifdef CANLIB_TIMESTAMP
    mapping_map["FLASH_CELLBOARD_5_RX"].field["_timestamp"].value._uint64 = &pack.FLASH_CELLBOARD_5_RX.start()._timestamp;
    mapping_map["FLASH_CELLBOARD_5_RX"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["FLASH_BMS_HV_TX"].size = std::bind(&canlib_circular_buffer<primary_message_FLASH_BMS_HV_TX, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.FLASH_BMS_HV_TX);
    mapping_map["FLASH_BMS_HV_TX"].offset = std::bind(&canlib_circular_buffer<primary_message_FLASH_BMS_HV_TX, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.FLASH_BMS_HV_TX);
    mapping_map["FLASH_BMS_HV_TX"].stride = sizeof(primary_message_FLASH_BMS_HV_TX);
#ifdef CANLIB_TIMESTAMP
    mapping_map["FLASH_BMS_HV_TX"].field["_timestamp"].value._uint64 = &pack.FLASH_BMS_HV_TX.start()._timestamp;
    mapping_map["FLASH_BMS_HV_TX"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["FLASH_BMS_HV_RX"].size = std::bind(&canlib_circular_buffer<primary_message_FLASH_BMS_HV_RX, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.FLASH_BMS_HV_RX);
    mapping_map["FLASH_BMS_HV_RX"].offset = std::bind(&canlib_circular_buffer<primary_message_FLASH_BMS_HV_RX, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.FLASH_BMS_HV_RX);
    mapping_map["FLASH_BMS_HV_RX"].stride = sizeof(primary_message_FLASH_BMS_HV_RX);
#ifdef CANLIB_TIMESTAMP
    mapping_map["FLASH_BMS_HV_RX"].field["_timestamp"].value._uint64 = &pack.FLASH_BMS_HV_RX.start()._timestamp;
    mapping_map["FLASH_BMS_HV_RX"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["FLASH_BMS_LV_TX"].size = std::bind(&canlib_circular_buffer<primary_message_FLASH_BMS_LV_TX, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.FLASH_BMS_LV_TX);
    mapping_map["FLASH_BMS_LV_TX"].offset = std::bind(&canlib_circular_buffer<primary_message_FLASH_BMS_LV_TX, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.FLASH_BMS_LV_TX);
    mapping_map["FLASH_BMS_LV_TX"].stride = sizeof(primary_message_FLASH_BMS_LV_TX);
#ifdef CANLIB_TIMESTAMP
    mapping_map["FLASH_BMS_LV_TX"].field["_timestamp"].value._uint64 = &pack.FLASH_BMS_LV_TX.start()._timestamp;
    mapping_map["FLASH_BMS_LV_TX"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["FLASH_BMS_LV_RX"].size = std::bind(&canlib_circular_buffer<primary_message_FLASH_BMS_LV_RX, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.FLASH_BMS_LV_RX);
    mapping_map["FLASH_BMS_LV_RX"].offset = std::bind(&canlib_circular_buffer<primary_message_FLASH_BMS_LV_RX, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.FLASH_BMS_LV_RX);
    mapping_map["FLASH_BMS_LV_RX"].stride = sizeof(primary_message_FLASH_BMS_LV_RX);
#ifdef CANLIB_TIMESTAMP
    mapping_map["FLASH_BMS_LV_RX"].field["_timestamp"].value._uint64 = &pack.FLASH_BMS_LV_RX.start()._timestamp;
    mapping_map["FLASH_BMS_LV_RX"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["BRUSA_NLG5_CTL"].size = std::bind(&canlib_circular_buffer<primary_message_BRUSA_NLG5_CTL, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.BRUSA_NLG5_CTL);
    mapping_map["BRUSA_NLG5_CTL"].offset = std::bind(&canlib_circular_buffer<primary_message_BRUSA_NLG5_CTL, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.BRUSA_NLG5_CTL);
    mapping_map["BRUSA_NLG5_CTL"].stride = sizeof(primary_message_BRUSA_NLG5_CTL);
#ifdef CANLIB_TIMESTAMP
    mapping_map["BRUSA_NLG5_CTL"].field["_timestamp"].value._uint64 = &pack.BRUSA_NLG5_CTL.start()._timestamp;
    mapping_map["BRUSA_NLG5_CTL"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["BRUSA_ST"].size = std::bind(&canlib_circular_buffer<primary_message_BRUSA_ST, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.BRUSA_ST);
    mapping_map["BRUSA_ST"].offset = std::bind(&canlib_circular_buffer<primary_message_BRUSA_ST, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.BRUSA_ST);
    mapping_map["BRUSA_ST"].stride = sizeof(primary_message_BRUSA_ST);
#ifdef CANLIB_TIMESTAMP
    mapping_map["BRUSA_ST"].field["_timestamp"].value._uint64 = &pack.BRUSA_ST.start()._timestamp;
    mapping_map["BRUSA_ST"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["BRUSA_ACT_I"].size = std::bind(&canlib_circular_buffer<primary_message_BRUSA_ACT_I, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.BRUSA_ACT_I);
    mapping_map["BRUSA_ACT_I"].offset = std::bind(&canlib_circular_buffer<primary_message_BRUSA_ACT_I, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.BRUSA_ACT_I);
    mapping_map["BRUSA_ACT_I"].stride = sizeof(primary_message_BRUSA_ACT_I);
#ifdef CANLIB_TIMESTAMP
    mapping_map["BRUSA_ACT_I"].field["_timestamp"].value._uint64 = &pack.BRUSA_ACT_I.start()._timestamp;
    mapping_map["BRUSA_ACT_I"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["BRUSA_ACT_II"].size = std::bind(&canlib_circular_buffer<primary_message_BRUSA_ACT_II, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.BRUSA_ACT_II);
    mapping_map["BRUSA_ACT_II"].offset = std::bind(&canlib_circular_buffer<primary_message_BRUSA_ACT_II, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.BRUSA_ACT_II);
    mapping_map["BRUSA_ACT_II"].stride = sizeof(primary_message_BRUSA_ACT_II);
#ifdef CANLIB_TIMESTAMP
    mapping_map["BRUSA_ACT_II"].field["_timestamp"].value._uint64 = &pack.BRUSA_ACT_II.start()._timestamp;
    mapping_map["BRUSA_ACT_II"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["BRUSA_TEMP"].size = std::bind(&canlib_circular_buffer<primary_message_BRUSA_TEMP, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.BRUSA_TEMP);
    mapping_map["BRUSA_TEMP"].offset = std::bind(&canlib_circular_buffer<primary_message_BRUSA_TEMP, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.BRUSA_TEMP);
    mapping_map["BRUSA_TEMP"].stride = sizeof(primary_message_BRUSA_TEMP);
#ifdef CANLIB_TIMESTAMP
    mapping_map["BRUSA_TEMP"].field["_timestamp"].value._uint64 = &pack.BRUSA_TEMP.start()._timestamp;
    mapping_map["BRUSA_TEMP"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["BRUSA_ERR"].size = std::bind(&canlib_circular_buffer<primary_message_BRUSA_ERR, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.BRUSA_ERR);
    mapping_map["BRUSA_ERR"].offset = std::bind(&canlib_circular_buffer<primary_message_BRUSA_ERR, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.BRUSA_ERR);
    mapping_map["BRUSA_ERR"].stride = sizeof(primary_message_BRUSA_ERR);
#ifdef CANLIB_TIMESTAMP
    mapping_map["BRUSA_ERR"].field["_timestamp"].value._uint64 = &pack.BRUSA_ERR.start()._timestamp;
    mapping_map["BRUSA_ERR"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["CONTROL_OUTPUT"].size = std::bind(&canlib_circular_buffer<primary_message_CONTROL_OUTPUT_conversion, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.CONTROL_OUTPUT);
    mapping_map["CONTROL_OUTPUT"].offset = std::bind(&canlib_circular_buffer<primary_message_CONTROL_OUTPUT_conversion, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.CONTROL_OUTPUT);
    mapping_map["CONTROL_OUTPUT"].stride = sizeof(primary_message_CONTROL_OUTPUT_conversion);
    mapping_map["CONTROL_OUTPUT"].field["estimated_velocity"].value._float32 = &pack.CONTROL_OUTPUT.start().estimated_velocity;
    mapping_map["CONTROL_OUTPUT"].field["estimated_velocity"].type = mapping_type_float32;
    mapping_map["CONTROL_OUTPUT"].field["tmax_r"].value._float32 = &pack.CONTROL_OUTPUT.start().tmax_r;
    mapping_map["CONTROL_OUTPUT"].field["tmax_r"].type = mapping_type_float32;
    mapping_map["CONTROL_OUTPUT"].field["tmax_l"].value._float32 = &pack.CONTROL_OUTPUT.start().tmax_l;
    mapping_map["CONTROL_OUTPUT"].field["tmax_l"].type = mapping_type_float32;
    mapping_map["CONTROL_OUTPUT"].field["torque_l"].value._float32 = &pack.CONTROL_OUTPUT.start().torque_l;
    mapping_map["CONTROL_OUTPUT"].field["torque_l"].type = mapping_type_float32;
    mapping_map["CONTROL_OUTPUT"].field["torque_r"].value._float32 = &pack.CONTROL_OUTPUT.start().torque_r;
    mapping_map["CONTROL_OUTPUT"].field["torque_r"].type = mapping_type_float32;
#ifdef CANLIB_TIMESTAMP
    mapping_map["CONTROL_OUTPUT"].field["_timestamp"].value._uint64 = &pack.CONTROL_OUTPUT.start()._timestamp;
    mapping_map["CONTROL_OUTPUT"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["LC_RESET"].size = std::bind(&canlib_circular_buffer<primary_message_LC_RESET, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.LC_RESET);
    mapping_map["LC_RESET"].offset = std::bind(&canlib_circular_buffer<primary_message_LC_RESET, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.LC_RESET);
    mapping_map["LC_RESET"].stride = sizeof(primary_message_LC_RESET);
#ifdef CANLIB_TIMESTAMP
    mapping_map["LC_RESET"].field["_timestamp"].value._uint64 = &pack.LC_RESET.start()._timestamp;
    mapping_map["LC_RESET"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP 
}

void primary_proto_serialize_from_id(canlib_message_id id, primary::Pack* pack, primary_devices* map) {
    int index = primary_index_from_id(id);

    if (index == -1) return;

    switch(id) {
        case 0: {
            primary_message_BMS_HV_JMP_TO_BLT* msg = (primary_message_BMS_HV_JMP_TO_BLT*) (*map)[index].message_raw;
            primary::BMS_HV_JMP_TO_BLT* proto_msg = pack->add_bms_hv_jmp_to_blt();
            break;
        }

        case 32: {
            primary_message_BMS_LV_JMP_TO_BLT* msg = (primary_message_BMS_LV_JMP_TO_BLT*) (*map)[index].message_raw;
            primary::BMS_LV_JMP_TO_BLT* proto_msg = pack->add_bms_lv_jmp_to_blt();
            break;
        }

        case 1025: {
            primary_message_STEER_VERSION* msg = (primary_message_STEER_VERSION*) (*map)[index].message_raw;
            primary::STEER_VERSION* proto_msg = pack->add_steer_version();
            proto_msg->set_component_version(msg->component_version);
            proto_msg->set_canlib_build_time(msg->canlib_build_time);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1057: {
            primary_message_DAS_VERSION* msg = (primary_message_DAS_VERSION*) (*map)[index].message_raw;
            primary::DAS_VERSION* proto_msg = pack->add_das_version();
            proto_msg->set_component_version(msg->component_version);
            proto_msg->set_canlib_build_time(msg->canlib_build_time);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1089: {
            primary_message_HV_VERSION* msg = (primary_message_HV_VERSION*) (*map)[index].message_raw;
            primary::HV_VERSION* proto_msg = pack->add_hv_version();
            proto_msg->set_component_version(msg->component_version);
            proto_msg->set_canlib_build_time(msg->canlib_build_time);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1121: {
            primary_message_LV_VERSION* msg = (primary_message_LV_VERSION*) (*map)[index].message_raw;
            primary::LV_VERSION* proto_msg = pack->add_lv_version();
            proto_msg->set_component_version(msg->component_version);
            proto_msg->set_canlib_build_time(msg->canlib_build_time);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1153: {
            primary_message_TLM_VERSION* msg = (primary_message_TLM_VERSION*) (*map)[index].message_raw;
            primary::TLM_VERSION* proto_msg = pack->add_tlm_version();
            proto_msg->set_component_version(msg->component_version);
            proto_msg->set_canlib_build_time(msg->canlib_build_time);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 257: {
            primary_message_TIMESTAMP* msg = (primary_message_TIMESTAMP*) (*map)[index].message_raw;
            primary::TIMESTAMP* proto_msg = pack->add_timestamp();
            proto_msg->set_timestamp(msg->timestamp);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 289: {
            primary_message_AMBIENT_TEMPERATURE* msg = (primary_message_AMBIENT_TEMPERATURE*) (*map)[index].message_raw;
            primary::AMBIENT_TEMPERATURE* proto_msg = pack->add_ambient_temperature();
            proto_msg->set_temp(msg->temp);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1072: {
            primary_message_DATA_LOGGER* msg = (primary_message_DATA_LOGGER*) (*map)[index].message_raw;
            primary::DATA_LOGGER* proto_msg = pack->add_data_logger();
            proto_msg->set_placeholder1(msg->placeholder1);
            proto_msg->set_placeholder2(msg->placeholder2);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 259: {
            primary_message_SET_TLM_STATUS* msg = (primary_message_SET_TLM_STATUS*) (*map)[index].message_raw;
            primary::SET_TLM_STATUS* proto_msg = pack->add_set_tlm_status();
            proto_msg->set_tlm_status((primary::Toggle)msg->tlm_status);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 260: {
            primary_message_TLM_STATUS* msg = (primary_message_TLM_STATUS*) (*map)[index].message_raw;
            primary::TLM_STATUS* proto_msg = pack->add_tlm_status();
            proto_msg->set_tlm_status((primary::Toggle)msg->tlm_status);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1795: {
            primary_message_STEER_SYSTEM_STATUS* msg = (primary_message_STEER_SYSTEM_STATUS*) (*map)[index].message_raw;
            primary::STEER_SYSTEM_STATUS* proto_msg = pack->add_steer_system_status();
            proto_msg->set_soc_temp(msg->soc_temp);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 773: {
            primary_message_HV_VOLTAGE_conversion* msg = (primary_message_HV_VOLTAGE_conversion*) (*map)[index].message_conversion;
            primary::HV_VOLTAGE* proto_msg = pack->add_hv_voltage();
            proto_msg->set_pack_voltage(msg->pack_voltage);
            proto_msg->set_bus_voltage(msg->bus_voltage);
            proto_msg->set_max_cell_voltage(msg->max_cell_voltage);
            proto_msg->set_min_cell_voltage(msg->min_cell_voltage);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 805: {
            primary_message_HV_CURRENT_conversion* msg = (primary_message_HV_CURRENT_conversion*) (*map)[index].message_conversion;
            primary::HV_CURRENT* proto_msg = pack->add_hv_current();
            proto_msg->set_current(msg->current);
            proto_msg->set_power(msg->power);
            proto_msg->set_energy(msg->energy);
            proto_msg->set_soc(msg->soc);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 837: {
            primary_message_HV_TEMP_conversion* msg = (primary_message_HV_TEMP_conversion*) (*map)[index].message_conversion;
            primary::HV_TEMP* proto_msg = pack->add_hv_temp();
            proto_msg->set_average_temp(msg->average_temp);
            proto_msg->set_max_temp(msg->max_temp);
            proto_msg->set_min_temp(msg->min_temp);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 5: {
            primary_message_HV_ERRORS* msg = (primary_message_HV_ERRORS*) (*map)[index].message_raw;
            primary::HV_ERRORS* proto_msg = pack->add_hv_errors();
            proto_msg->set_warnings(msg->warnings);
            proto_msg->set_errors(msg->errors);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 6: {
            primary_message_HV_CAN_FORWARD* msg = (primary_message_HV_CAN_FORWARD*) (*map)[index].message_raw;
            primary::HV_CAN_FORWARD* proto_msg = pack->add_hv_can_forward();
            proto_msg->set_can_forward_set((primary::Toggle)msg->can_forward_set);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 38: {
            primary_message_HV_FANS_OVERRIDE_conversion* msg = (primary_message_HV_FANS_OVERRIDE_conversion*) (*map)[index].message_conversion;
            primary::HV_FANS_OVERRIDE* proto_msg = pack->add_hv_fans_override();
            proto_msg->set_fans_override((primary::Toggle)msg->fans_override);
            proto_msg->set_fans_speed(msg->fans_speed);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 7: {
            primary_message_HV_CAN_FORWARD_STATUS* msg = (primary_message_HV_CAN_FORWARD_STATUS*) (*map)[index].message_raw;
            primary::HV_CAN_FORWARD_STATUS* proto_msg = pack->add_hv_can_forward_status();
            proto_msg->set_can_forward_status((primary::Toggle)msg->can_forward_status);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 775: {
            primary_message_HV_FANS_OVERRIDE_STATUS_conversion* msg = (primary_message_HV_FANS_OVERRIDE_STATUS_conversion*) (*map)[index].message_conversion;
            primary::HV_FANS_OVERRIDE_STATUS* proto_msg = pack->add_hv_fans_override_status();
            proto_msg->set_fans_override((primary::Toggle)msg->fans_override);
            proto_msg->set_fans_speed(msg->fans_speed);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 776: {
            primary_message_HV_FEEDBACKS_STATUS* msg = (primary_message_HV_FEEDBACKS_STATUS*) (*map)[index].message_raw;
            primary::HV_FEEDBACKS_STATUS* proto_msg = pack->add_hv_feedbacks_status();
            proto_msg->set_feedbacks_status(msg->feedbacks_status);
            proto_msg->set_is_circuitry_error(msg->is_circuitry_error);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 808: {
            primary_message_HV_IMD_STATUS* msg = (primary_message_HV_IMD_STATUS*) (*map)[index].message_raw;
            primary::HV_IMD_STATUS* proto_msg = pack->add_hv_imd_status();
            proto_msg->set_imd_fault(msg->imd_fault);
            proto_msg->set_imd_status((primary::ImdStatus)msg->imd_status);
            proto_msg->set_imd_info(msg->imd_info);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 37: {
            primary_message_TS_STATUS* msg = (primary_message_TS_STATUS*) (*map)[index].message_raw;
            primary::TS_STATUS* proto_msg = pack->add_ts_status();
            proto_msg->set_ts_status((primary::TsStatus)msg->ts_status);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 70: {
            primary_message_SET_TS_STATUS* msg = (primary_message_SET_TS_STATUS*) (*map)[index].message_raw;
            primary::SET_TS_STATUS_DAS* proto_msg = pack->add_set_ts_status_das();
            proto_msg->set_ts_status_set((primary::Toggle)msg->ts_status_set);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 102: {
            primary_message_SET_TS_STATUS* msg = (primary_message_SET_TS_STATUS*) (*map)[index].message_raw;
            primary::SET_TS_STATUS_HANDCART* proto_msg = pack->add_set_ts_status_handcart();
            proto_msg->set_ts_status_set((primary::Toggle)msg->ts_status_set);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 265: {
            primary_message_STEER_STATUS_conversion* msg = (primary_message_STEER_STATUS_conversion*) (*map)[index].message_conversion;
            primary::STEER_STATUS* proto_msg = pack->add_steer_status();
            proto_msg->set_map_pw(msg->map_pw);
            proto_msg->set_map_sc(msg->map_sc);
            proto_msg->set_map_tv(msg->map_tv);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 777: {
            primary_message_SET_CAR_STATUS* msg = (primary_message_SET_CAR_STATUS*) (*map)[index].message_raw;
            primary::SET_CAR_STATUS* proto_msg = pack->add_set_car_status();
            proto_msg->set_car_status_set((primary::SetCarStatus)msg->car_status_set);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1033: {
            primary_message_SET_PEDALS_RANGE* msg = (primary_message_SET_PEDALS_RANGE*) (*map)[index].message_raw;
            primary::SET_PEDALS_RANGE* proto_msg = pack->add_set_pedals_range();
            proto_msg->set_bound((primary::Bound)msg->bound);
            proto_msg->set_pedal((primary::Pedal)msg->pedal);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1065: {
            primary_message_SET_STEERING_ANGLE_RANGE* msg = (primary_message_SET_STEERING_ANGLE_RANGE*) (*map)[index].message_raw;
            primary::SET_STEERING_ANGLE_RANGE* proto_msg = pack->add_set_steering_angle_range();
            proto_msg->set_bound((primary::Bound)msg->bound);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 516: {
            primary_message_CAR_STATUS* msg = (primary_message_CAR_STATUS*) (*map)[index].message_raw;
            primary::CAR_STATUS* proto_msg = pack->add_car_status();
            proto_msg->set_inverter_l((primary::InverterStatus)msg->inverter_l);
            proto_msg->set_inverter_r((primary::InverterStatus)msg->inverter_r);
            proto_msg->set_car_status((primary::CarStatus)msg->car_status);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 4: {
            primary_message_DAS_ERRORS* msg = (primary_message_DAS_ERRORS*) (*map)[index].message_raw;
            primary::DAS_ERRORS* proto_msg = pack->add_das_errors();
            proto_msg->set_das_error(msg->das_error);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 840: {
            primary_message_LV_CURRENT_conversion* msg = (primary_message_LV_CURRENT_conversion*) (*map)[index].message_conversion;
            primary::LV_CURRENT* proto_msg = pack->add_lv_current();
            proto_msg->set_current(msg->current);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 872: {
            primary_message_LV_VOLTAGE_conversion* msg = (primary_message_LV_VOLTAGE_conversion*) (*map)[index].message_conversion;
            primary::LV_VOLTAGE* proto_msg = pack->add_lv_voltage();
            proto_msg->set_voltage_1(msg->voltage_1);
            proto_msg->set_voltage_2(msg->voltage_2);
            proto_msg->set_voltage_3(msg->voltage_3);
            proto_msg->set_voltage_4(msg->voltage_4);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 904: {
            primary_message_LV_TOTAL_VOLTAGE_conversion* msg = (primary_message_LV_TOTAL_VOLTAGE_conversion*) (*map)[index].message_conversion;
            primary::LV_TOTAL_VOLTAGE* proto_msg = pack->add_lv_total_voltage();
            proto_msg->set_total_voltage(msg->total_voltage);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 936: {
            primary_message_LV_TEMPERATURE_conversion* msg = (primary_message_LV_TEMPERATURE_conversion*) (*map)[index].message_conversion;
            primary::LV_TEMPERATURE* proto_msg = pack->add_lv_temperature();
            proto_msg->set_bp_temperature_1(msg->bp_temperature_1);
            proto_msg->set_bp_temperature_2(msg->bp_temperature_2);
            proto_msg->set_dcdc12_temperature(msg->dcdc12_temperature);
            proto_msg->set_dcdc24_temperature(msg->dcdc24_temperature);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 968: {
            primary_message_COOLING_STATUS_conversion* msg = (primary_message_COOLING_STATUS_conversion*) (*map)[index].message_conversion;
            primary::COOLING_STATUS* proto_msg = pack->add_cooling_status();
            proto_msg->set_radiators_speed(msg->radiators_speed);
            proto_msg->set_pumps_speed(msg->pumps_speed);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 778: {
            primary_message_SET_RADIATOR_SPEED_conversion* msg = (primary_message_SET_RADIATOR_SPEED_conversion*) (*map)[index].message_conversion;
            primary::SET_RADIATOR_SPEED* proto_msg = pack->add_set_radiator_speed();
            proto_msg->set_radiators_speed(msg->radiators_speed);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 810: {
            primary_message_SET_PUMPS_SPEED_conversion* msg = (primary_message_SET_PUMPS_SPEED_conversion*) (*map)[index].message_conversion;
            primary::SET_PUMPS_SPEED* proto_msg = pack->add_set_pumps_speed();
            proto_msg->set_pumps_speed(msg->pumps_speed);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 266: {
            primary_message_SET_INVERTER_CONNECTION_STATUS* msg = (primary_message_SET_INVERTER_CONNECTION_STATUS*) (*map)[index].message_raw;
            primary::SET_INVERTER_CONNECTION_STATUS* proto_msg = pack->add_set_inverter_connection_status();
            proto_msg->set_status((primary::Toggle)msg->status);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 264: {
            primary_message_INVERTER_CONNECTION_STATUS* msg = (primary_message_INVERTER_CONNECTION_STATUS*) (*map)[index].message_raw;
            primary::INVERTER_CONNECTION_STATUS* proto_msg = pack->add_inverter_connection_status();
            proto_msg->set_status((primary::Toggle)msg->status);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 8: {
            primary_message_LV_ERRORS* msg = (primary_message_LV_ERRORS*) (*map)[index].message_raw;
            primary::LV_ERRORS* proto_msg = pack->add_lv_errors();
            proto_msg->set_warnings(msg->warnings);
            proto_msg->set_errors(msg->errors);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 296: {
            primary_message_SHUTDOWN_STATUS* msg = (primary_message_SHUTDOWN_STATUS*) (*map)[index].message_raw;
            primary::SHUTDOWN_STATUS* proto_msg = pack->add_shutdown_status();
            proto_msg->set_input(msg->input);
            proto_msg->set_output(msg->output);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 3: {
            primary_message_MARKER* msg = (primary_message_MARKER*) (*map)[index].message_raw;
            primary::MARKER* proto_msg = pack->add_marker();
            break;
        }

        case 519: {
            primary_message_HV_CELLS_VOLTAGE_conversion* msg = (primary_message_HV_CELLS_VOLTAGE_conversion*) (*map)[index].message_conversion;
            primary::HV_CELLS_VOLTAGE* proto_msg = pack->add_hv_cells_voltage();
            proto_msg->set_start_index(msg->start_index);
            proto_msg->set_voltage_0(msg->voltage_0);
            proto_msg->set_voltage_1(msg->voltage_1);
            proto_msg->set_voltage_2(msg->voltage_2);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 551: {
            primary_message_HV_CELLS_TEMP_conversion* msg = (primary_message_HV_CELLS_TEMP_conversion*) (*map)[index].message_conversion;
            primary::HV_CELLS_TEMP* proto_msg = pack->add_hv_cells_temp();
            proto_msg->set_start_index(msg->start_index);
            proto_msg->set_temp_0(msg->temp_0);
            proto_msg->set_temp_1(msg->temp_1);
            proto_msg->set_temp_2(msg->temp_2);
            proto_msg->set_temp_3(msg->temp_3);
            proto_msg->set_temp_4(msg->temp_4);
            proto_msg->set_temp_5(msg->temp_5);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 583: {
            primary_message_HV_CELL_BALANCING_STATUS* msg = (primary_message_HV_CELL_BALANCING_STATUS*) (*map)[index].message_raw;
            primary::HV_CELL_BALANCING_STATUS* proto_msg = pack->add_hv_cell_balancing_status();
            proto_msg->set_balancing_status((primary::Toggle)msg->balancing_status);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 518: {
            primary_message_SET_CELL_BALANCING_STATUS* msg = (primary_message_SET_CELL_BALANCING_STATUS*) (*map)[index].message_raw;
            primary::SET_CELL_BALANCING_STATUS* proto_msg = pack->add_set_cell_balancing_status();
            proto_msg->set_set_balancing_status((primary::Toggle)msg->set_balancing_status);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 774: {
            primary_message_HANDCART_STATUS* msg = (primary_message_HANDCART_STATUS*) (*map)[index].message_raw;
            primary::HANDCART_STATUS* proto_msg = pack->add_handcart_status();
            proto_msg->set_connected(msg->connected);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 548: {
            primary_message_SPEED_conversion* msg = (primary_message_SPEED_conversion*) (*map)[index].message_conversion;
            primary::SPEED* proto_msg = pack->add_speed();
            proto_msg->set_encoder_r(msg->encoder_r);
            proto_msg->set_encoder_l(msg->encoder_l);
            proto_msg->set_inverter_r(msg->inverter_r);
            proto_msg->set_inverter_l(msg->inverter_l);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 513: {
            primary_message_INV_L_REQUEST* msg = (primary_message_INV_L_REQUEST*) (*map)[index].message_raw;
            primary::INV_L_REQUEST* proto_msg = pack->add_inv_l_request();
            proto_msg->set_data_0(msg->data_0);
            proto_msg->set_data_1(msg->data_1);
            proto_msg->set_data_2(msg->data_2);
            proto_msg->set_data_3(msg->data_3);
            proto_msg->set_data_4(msg->data_4);
            proto_msg->set_data_5(msg->data_5);
            proto_msg->set_data_6(msg->data_6);
            proto_msg->set_data_7(msg->data_7);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 514: {
            primary_message_INV_R_REQUEST* msg = (primary_message_INV_R_REQUEST*) (*map)[index].message_raw;
            primary::INV_R_REQUEST* proto_msg = pack->add_inv_r_request();
            proto_msg->set_data_0(msg->data_0);
            proto_msg->set_data_1(msg->data_1);
            proto_msg->set_data_2(msg->data_2);
            proto_msg->set_data_3(msg->data_3);
            proto_msg->set_data_4(msg->data_4);
            proto_msg->set_data_5(msg->data_5);
            proto_msg->set_data_6(msg->data_6);
            proto_msg->set_data_7(msg->data_7);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 385: {
            primary_message_INV_L_RESPONSE* msg = (primary_message_INV_L_RESPONSE*) (*map)[index].message_raw;
            primary::INV_L_RESPONSE* proto_msg = pack->add_inv_l_response();
            proto_msg->set_reg_id(msg->reg_id);
            proto_msg->set_data_0(msg->data_0);
            proto_msg->set_data_1(msg->data_1);
            proto_msg->set_data_2(msg->data_2);
            proto_msg->set_data_3(msg->data_3);
            proto_msg->set_data_4(msg->data_4);
            proto_msg->set_data_5(msg->data_5);
            proto_msg->set_data_6(msg->data_6);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 386: {
            primary_message_INV_R_RESPONSE* msg = (primary_message_INV_R_RESPONSE*) (*map)[index].message_raw;
            primary::INV_R_RESPONSE* proto_msg = pack->add_inv_r_response();
            proto_msg->set_reg_id(msg->reg_id);
            proto_msg->set_data_0(msg->data_0);
            proto_msg->set_data_1(msg->data_1);
            proto_msg->set_data_2(msg->data_2);
            proto_msg->set_data_3(msg->data_3);
            proto_msg->set_data_4(msg->data_4);
            proto_msg->set_data_5(msg->data_5);
            proto_msg->set_data_6(msg->data_6);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 16: {
            primary_message_FLASH_CELLBOARD_0_TX* msg = (primary_message_FLASH_CELLBOARD_0_TX*) (*map)[index].message_raw;
            primary::FLASH_CELLBOARD_0_TX* proto_msg = pack->add_flash_cellboard_0_tx();
            break;
        }

        case 17: {
            primary_message_FLASH_CELLBOARD_0_RX* msg = (primary_message_FLASH_CELLBOARD_0_RX*) (*map)[index].message_raw;
            primary::FLASH_CELLBOARD_0_RX* proto_msg = pack->add_flash_cellboard_0_rx();
            break;
        }

        case 18: {
            primary_message_FLASH_CELLBOARD_1_TX* msg = (primary_message_FLASH_CELLBOARD_1_TX*) (*map)[index].message_raw;
            primary::FLASH_CELLBOARD_1_TX* proto_msg = pack->add_flash_cellboard_1_tx();
            break;
        }

        case 19: {
            primary_message_FLASH_CELLBOARD_1_RX* msg = (primary_message_FLASH_CELLBOARD_1_RX*) (*map)[index].message_raw;
            primary::FLASH_CELLBOARD_1_RX* proto_msg = pack->add_flash_cellboard_1_rx();
            break;
        }

        case 20: {
            primary_message_FLASH_CELLBOARD_2_TX* msg = (primary_message_FLASH_CELLBOARD_2_TX*) (*map)[index].message_raw;
            primary::FLASH_CELLBOARD_2_TX* proto_msg = pack->add_flash_cellboard_2_tx();
            break;
        }

        case 21: {
            primary_message_FLASH_CELLBOARD_2_RX* msg = (primary_message_FLASH_CELLBOARD_2_RX*) (*map)[index].message_raw;
            primary::FLASH_CELLBOARD_2_RX* proto_msg = pack->add_flash_cellboard_2_rx();
            break;
        }

        case 22: {
            primary_message_FLASH_CELLBOARD_3_TX* msg = (primary_message_FLASH_CELLBOARD_3_TX*) (*map)[index].message_raw;
            primary::FLASH_CELLBOARD_3_TX* proto_msg = pack->add_flash_cellboard_3_tx();
            break;
        }

        case 23: {
            primary_message_FLASH_CELLBOARD_3_RX* msg = (primary_message_FLASH_CELLBOARD_3_RX*) (*map)[index].message_raw;
            primary::FLASH_CELLBOARD_3_RX* proto_msg = pack->add_flash_cellboard_3_rx();
            break;
        }

        case 24: {
            primary_message_FLASH_CELLBOARD_4_TX* msg = (primary_message_FLASH_CELLBOARD_4_TX*) (*map)[index].message_raw;
            primary::FLASH_CELLBOARD_4_TX* proto_msg = pack->add_flash_cellboard_4_tx();
            break;
        }

        case 25: {
            primary_message_FLASH_CELLBOARD_4_RX* msg = (primary_message_FLASH_CELLBOARD_4_RX*) (*map)[index].message_raw;
            primary::FLASH_CELLBOARD_4_RX* proto_msg = pack->add_flash_cellboard_4_rx();
            break;
        }

        case 26: {
            primary_message_FLASH_CELLBOARD_5_TX* msg = (primary_message_FLASH_CELLBOARD_5_TX*) (*map)[index].message_raw;
            primary::FLASH_CELLBOARD_5_TX* proto_msg = pack->add_flash_cellboard_5_tx();
            break;
        }

        case 27: {
            primary_message_FLASH_CELLBOARD_5_RX* msg = (primary_message_FLASH_CELLBOARD_5_RX*) (*map)[index].message_raw;
            primary::FLASH_CELLBOARD_5_RX* proto_msg = pack->add_flash_cellboard_5_rx();
            break;
        }

        case 2017: {
            primary_message_FLASH_BMS_HV_TX* msg = (primary_message_FLASH_BMS_HV_TX*) (*map)[index].message_raw;
            primary::FLASH_BMS_HV_TX* proto_msg = pack->add_flash_bms_hv_tx();
            break;
        }

        case 1639: {
            primary_message_FLASH_BMS_HV_RX* msg = (primary_message_FLASH_BMS_HV_RX*) (*map)[index].message_raw;
            primary::FLASH_BMS_HV_RX* proto_msg = pack->add_flash_bms_hv_rx();
            break;
        }

        case 2033: {
            primary_message_FLASH_BMS_LV_TX* msg = (primary_message_FLASH_BMS_LV_TX*) (*map)[index].message_raw;
            primary::FLASH_BMS_LV_TX* proto_msg = pack->add_flash_bms_lv_tx();
            break;
        }

        case 1655: {
            primary_message_FLASH_BMS_LV_RX* msg = (primary_message_FLASH_BMS_LV_RX*) (*map)[index].message_raw;
            primary::FLASH_BMS_LV_RX* proto_msg = pack->add_flash_bms_lv_rx();
            break;
        }

        case 618: {
            primary_message_BRUSA_NLG5_CTL* msg = (primary_message_BRUSA_NLG5_CTL*) (*map)[index].message_raw;
            primary::BRUSA_NLG5_CTL* proto_msg = pack->add_brusa_nlg5_ctl();
            break;
        }

        case 610: {
            primary_message_BRUSA_ST* msg = (primary_message_BRUSA_ST*) (*map)[index].message_raw;
            primary::BRUSA_ST* proto_msg = pack->add_brusa_st();
            break;
        }

        case 611: {
            primary_message_BRUSA_ACT_I* msg = (primary_message_BRUSA_ACT_I*) (*map)[index].message_raw;
            primary::BRUSA_ACT_I* proto_msg = pack->add_brusa_act_i();
            break;
        }

        case 612: {
            primary_message_BRUSA_ACT_II* msg = (primary_message_BRUSA_ACT_II*) (*map)[index].message_raw;
            primary::BRUSA_ACT_II* proto_msg = pack->add_brusa_act_ii();
            break;
        }

        case 613: {
            primary_message_BRUSA_TEMP* msg = (primary_message_BRUSA_TEMP*) (*map)[index].message_raw;
            primary::BRUSA_TEMP* proto_msg = pack->add_brusa_temp();
            break;
        }

        case 614: {
            primary_message_BRUSA_ERR* msg = (primary_message_BRUSA_ERR*) (*map)[index].message_raw;
            primary::BRUSA_ERR* proto_msg = pack->add_brusa_err();
            break;
        }

        case 1284: {
            primary_message_CONTROL_OUTPUT_conversion* msg = (primary_message_CONTROL_OUTPUT_conversion*) (*map)[index].message_conversion;
            primary::CONTROL_OUTPUT* proto_msg = pack->add_control_output();
            proto_msg->set_estimated_velocity(msg->estimated_velocity);
            proto_msg->set_tmax_r(msg->tmax_r);
            proto_msg->set_tmax_l(msg->tmax_l);
            proto_msg->set_torque_l(msg->torque_l);
            proto_msg->set_torque_r(msg->torque_r);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 523: {
            primary_message_LC_RESET* msg = (primary_message_LC_RESET*) (*map)[index].message_raw;
            primary::LC_RESET* proto_msg = pack->add_lc_reset();
            break;
        }

    }
}

void primary_proto_deserialize(primary::Pack* pack, primary_proto_pack* map, uint64_t resample_us) {
    for(int i = 0; i < pack->bms_hv_jmp_to_blt_size(); i++){
        static primary_message_BMS_HV_JMP_TO_BLT instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->bms_hv_jmp_to_blt(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        map->BMS_HV_JMP_TO_BLT.push(instance);
    }
    for(int i = 0; i < pack->bms_lv_jmp_to_blt_size(); i++){
        static primary_message_BMS_LV_JMP_TO_BLT instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->bms_lv_jmp_to_blt(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        map->BMS_LV_JMP_TO_BLT.push(instance);
    }
    for(int i = 0; i < pack->steer_version_size(); i++){
        static primary_message_STEER_VERSION instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->steer_version(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.component_version =pack->steer_version(i).component_version();
        instance.canlib_build_time =pack->steer_version(i).canlib_build_time();
        map->STEER_VERSION.push(instance);
    }
    for(int i = 0; i < pack->das_version_size(); i++){
        static primary_message_DAS_VERSION instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->das_version(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.component_version =pack->das_version(i).component_version();
        instance.canlib_build_time =pack->das_version(i).canlib_build_time();
        map->DAS_VERSION.push(instance);
    }
    for(int i = 0; i < pack->hv_version_size(); i++){
        static primary_message_HV_VERSION instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->hv_version(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.component_version =pack->hv_version(i).component_version();
        instance.canlib_build_time =pack->hv_version(i).canlib_build_time();
        map->HV_VERSION.push(instance);
    }
    for(int i = 0; i < pack->lv_version_size(); i++){
        static primary_message_LV_VERSION instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->lv_version(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.component_version =pack->lv_version(i).component_version();
        instance.canlib_build_time =pack->lv_version(i).canlib_build_time();
        map->LV_VERSION.push(instance);
    }
    for(int i = 0; i < pack->tlm_version_size(); i++){
        static primary_message_TLM_VERSION instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->tlm_version(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.component_version =pack->tlm_version(i).component_version();
        instance.canlib_build_time =pack->tlm_version(i).canlib_build_time();
        map->TLM_VERSION.push(instance);
    }
    for(int i = 0; i < pack->timestamp_size(); i++){
        static primary_message_TIMESTAMP instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->timestamp(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.timestamp =pack->timestamp(i).timestamp();
        map->TIMESTAMP.push(instance);
    }
    for(int i = 0; i < pack->ambient_temperature_size(); i++){
        static primary_message_AMBIENT_TEMPERATURE instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->ambient_temperature(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.temp =pack->ambient_temperature(i).temp();
        map->AMBIENT_TEMPERATURE.push(instance);
    }
    for(int i = 0; i < pack->data_logger_size(); i++){
        static primary_message_DATA_LOGGER instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->data_logger(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.placeholder1 =pack->data_logger(i).placeholder1();
        instance.placeholder2 =pack->data_logger(i).placeholder2();
        map->DATA_LOGGER.push(instance);
    }
    for(int i = 0; i < pack->set_tlm_status_size(); i++){
        static primary_message_SET_TLM_STATUS instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->set_tlm_status(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.tlm_status =(primary_Toggle)pack->set_tlm_status(i).tlm_status();
        map->SET_TLM_STATUS.push(instance);
    }
    for(int i = 0; i < pack->tlm_status_size(); i++){
        static primary_message_TLM_STATUS instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->tlm_status(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.tlm_status =(primary_Toggle)pack->tlm_status(i).tlm_status();
        map->TLM_STATUS.push(instance);
    }
    for(int i = 0; i < pack->steer_system_status_size(); i++){
        static primary_message_STEER_SYSTEM_STATUS instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->steer_system_status(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.soc_temp =pack->steer_system_status(i).soc_temp();
        map->STEER_SYSTEM_STATUS.push(instance);
    }
    for(int i = 0; i < pack->hv_voltage_size(); i++){
        static primary_message_HV_VOLTAGE_conversion instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->hv_voltage(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.pack_voltage =pack->hv_voltage(i).pack_voltage();
        instance.bus_voltage =pack->hv_voltage(i).bus_voltage();
        instance.max_cell_voltage =pack->hv_voltage(i).max_cell_voltage();
        instance.min_cell_voltage =pack->hv_voltage(i).min_cell_voltage();
        map->HV_VOLTAGE.push(instance);
    }
    for(int i = 0; i < pack->hv_current_size(); i++){
        static primary_message_HV_CURRENT_conversion instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->hv_current(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.current =pack->hv_current(i).current();
        instance.power =pack->hv_current(i).power();
        instance.energy =pack->hv_current(i).energy();
        instance.soc =pack->hv_current(i).soc();
        map->HV_CURRENT.push(instance);
    }
    for(int i = 0; i < pack->hv_temp_size(); i++){
        static primary_message_HV_TEMP_conversion instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->hv_temp(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.average_temp =pack->hv_temp(i).average_temp();
        instance.max_temp =pack->hv_temp(i).max_temp();
        instance.min_temp =pack->hv_temp(i).min_temp();
        map->HV_TEMP.push(instance);
    }
    for(int i = 0; i < pack->hv_errors_size(); i++){
        static primary_message_HV_ERRORS instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->hv_errors(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.warnings =pack->hv_errors(i).warnings();
        instance.errors =pack->hv_errors(i).errors();
        map->HV_ERRORS.push(instance);
    }
    for(int i = 0; i < pack->hv_can_forward_size(); i++){
        static primary_message_HV_CAN_FORWARD instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->hv_can_forward(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.can_forward_set =(primary_Toggle)pack->hv_can_forward(i).can_forward_set();
        map->HV_CAN_FORWARD.push(instance);
    }
    for(int i = 0; i < pack->hv_fans_override_size(); i++){
        static primary_message_HV_FANS_OVERRIDE_conversion instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->hv_fans_override(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.fans_override =(primary_Toggle)pack->hv_fans_override(i).fans_override();
        instance.fans_speed =pack->hv_fans_override(i).fans_speed();
        map->HV_FANS_OVERRIDE.push(instance);
    }
    for(int i = 0; i < pack->hv_can_forward_status_size(); i++){
        static primary_message_HV_CAN_FORWARD_STATUS instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->hv_can_forward_status(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.can_forward_status =(primary_Toggle)pack->hv_can_forward_status(i).can_forward_status();
        map->HV_CAN_FORWARD_STATUS.push(instance);
    }
    for(int i = 0; i < pack->hv_fans_override_status_size(); i++){
        static primary_message_HV_FANS_OVERRIDE_STATUS_conversion instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->hv_fans_override_status(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.fans_override =(primary_Toggle)pack->hv_fans_override_status(i).fans_override();
        instance.fans_speed =pack->hv_fans_override_status(i).fans_speed();
        map->HV_FANS_OVERRIDE_STATUS.push(instance);
    }
    for(int i = 0; i < pack->hv_feedbacks_status_size(); i++){
        static primary_message_HV_FEEDBACKS_STATUS instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->hv_feedbacks_status(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.feedbacks_status =pack->hv_feedbacks_status(i).feedbacks_status();
        instance.is_circuitry_error =pack->hv_feedbacks_status(i).is_circuitry_error();
        map->HV_FEEDBACKS_STATUS.push(instance);
    }
    for(int i = 0; i < pack->hv_imd_status_size(); i++){
        static primary_message_HV_IMD_STATUS instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->hv_imd_status(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.imd_fault =pack->hv_imd_status(i).imd_fault();
        instance.imd_status =(primary_ImdStatus)pack->hv_imd_status(i).imd_status();
        instance.imd_info =pack->hv_imd_status(i).imd_info();
        map->HV_IMD_STATUS.push(instance);
    }
    for(int i = 0; i < pack->ts_status_size(); i++){
        static primary_message_TS_STATUS instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->ts_status(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.ts_status =(primary_TsStatus)pack->ts_status(i).ts_status();
        map->TS_STATUS.push(instance);
    }
    for(int i = 0; i < pack->set_ts_status_das_size(); i++){
        static primary_message_SET_TS_STATUS instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->set_ts_status_das(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.ts_status_set =(primary_Toggle)pack->set_ts_status_das(i).ts_status_set();
        map->SET_TS_STATUS_DAS.push(instance);
    }
    for(int i = 0; i < pack->set_ts_status_handcart_size(); i++){
        static primary_message_SET_TS_STATUS instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->set_ts_status_handcart(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.ts_status_set =(primary_Toggle)pack->set_ts_status_handcart(i).ts_status_set();
        map->SET_TS_STATUS_HANDCART.push(instance);
    }
    for(int i = 0; i < pack->steer_status_size(); i++){
        static primary_message_STEER_STATUS_conversion instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->steer_status(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.map_pw =pack->steer_status(i).map_pw();
        instance.map_sc =pack->steer_status(i).map_sc();
        instance.map_tv =pack->steer_status(i).map_tv();
        map->STEER_STATUS.push(instance);
    }
    for(int i = 0; i < pack->set_car_status_size(); i++){
        static primary_message_SET_CAR_STATUS instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->set_car_status(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.car_status_set =(primary_SetCarStatus)pack->set_car_status(i).car_status_set();
        map->SET_CAR_STATUS.push(instance);
    }
    for(int i = 0; i < pack->set_pedals_range_size(); i++){
        static primary_message_SET_PEDALS_RANGE instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->set_pedals_range(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.bound =(primary_Bound)pack->set_pedals_range(i).bound();
        instance.pedal =(primary_Pedal)pack->set_pedals_range(i).pedal();
        map->SET_PEDALS_RANGE.push(instance);
    }
    for(int i = 0; i < pack->set_steering_angle_range_size(); i++){
        static primary_message_SET_STEERING_ANGLE_RANGE instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->set_steering_angle_range(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.bound =(primary_Bound)pack->set_steering_angle_range(i).bound();
        map->SET_STEERING_ANGLE_RANGE.push(instance);
    }
    for(int i = 0; i < pack->car_status_size(); i++){
        static primary_message_CAR_STATUS instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->car_status(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.inverter_l =(primary_InverterStatus)pack->car_status(i).inverter_l();
        instance.inverter_r =(primary_InverterStatus)pack->car_status(i).inverter_r();
        instance.car_status =(primary_CarStatus)pack->car_status(i).car_status();
        map->CAR_STATUS.push(instance);
    }
    for(int i = 0; i < pack->das_errors_size(); i++){
        static primary_message_DAS_ERRORS instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->das_errors(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.das_error =pack->das_errors(i).das_error();
        map->DAS_ERRORS.push(instance);
    }
    for(int i = 0; i < pack->lv_current_size(); i++){
        static primary_message_LV_CURRENT_conversion instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->lv_current(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.current =pack->lv_current(i).current();
        map->LV_CURRENT.push(instance);
    }
    for(int i = 0; i < pack->lv_voltage_size(); i++){
        static primary_message_LV_VOLTAGE_conversion instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->lv_voltage(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.voltage_1 =pack->lv_voltage(i).voltage_1();
        instance.voltage_2 =pack->lv_voltage(i).voltage_2();
        instance.voltage_3 =pack->lv_voltage(i).voltage_3();
        instance.voltage_4 =pack->lv_voltage(i).voltage_4();
        map->LV_VOLTAGE.push(instance);
    }
    for(int i = 0; i < pack->lv_total_voltage_size(); i++){
        static primary_message_LV_TOTAL_VOLTAGE_conversion instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->lv_total_voltage(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.total_voltage =pack->lv_total_voltage(i).total_voltage();
        map->LV_TOTAL_VOLTAGE.push(instance);
    }
    for(int i = 0; i < pack->lv_temperature_size(); i++){
        static primary_message_LV_TEMPERATURE_conversion instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->lv_temperature(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.bp_temperature_1 =pack->lv_temperature(i).bp_temperature_1();
        instance.bp_temperature_2 =pack->lv_temperature(i).bp_temperature_2();
        instance.dcdc12_temperature =pack->lv_temperature(i).dcdc12_temperature();
        instance.dcdc24_temperature =pack->lv_temperature(i).dcdc24_temperature();
        map->LV_TEMPERATURE.push(instance);
    }
    for(int i = 0; i < pack->cooling_status_size(); i++){
        static primary_message_COOLING_STATUS_conversion instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->cooling_status(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.radiators_speed =pack->cooling_status(i).radiators_speed();
        instance.pumps_speed =pack->cooling_status(i).pumps_speed();
        map->COOLING_STATUS.push(instance);
    }
    for(int i = 0; i < pack->set_radiator_speed_size(); i++){
        static primary_message_SET_RADIATOR_SPEED_conversion instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->set_radiator_speed(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.radiators_speed =pack->set_radiator_speed(i).radiators_speed();
        map->SET_RADIATOR_SPEED.push(instance);
    }
    for(int i = 0; i < pack->set_pumps_speed_size(); i++){
        static primary_message_SET_PUMPS_SPEED_conversion instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->set_pumps_speed(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.pumps_speed =pack->set_pumps_speed(i).pumps_speed();
        map->SET_PUMPS_SPEED.push(instance);
    }
    for(int i = 0; i < pack->set_inverter_connection_status_size(); i++){
        static primary_message_SET_INVERTER_CONNECTION_STATUS instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->set_inverter_connection_status(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.status =(primary_Toggle)pack->set_inverter_connection_status(i).status();
        map->SET_INVERTER_CONNECTION_STATUS.push(instance);
    }
    for(int i = 0; i < pack->inverter_connection_status_size(); i++){
        static primary_message_INVERTER_CONNECTION_STATUS instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->inverter_connection_status(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.status =(primary_Toggle)pack->inverter_connection_status(i).status();
        map->INVERTER_CONNECTION_STATUS.push(instance);
    }
    for(int i = 0; i < pack->lv_errors_size(); i++){
        static primary_message_LV_ERRORS instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->lv_errors(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.warnings =pack->lv_errors(i).warnings();
        instance.errors =pack->lv_errors(i).errors();
        map->LV_ERRORS.push(instance);
    }
    for(int i = 0; i < pack->shutdown_status_size(); i++){
        static primary_message_SHUTDOWN_STATUS instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->shutdown_status(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.input =pack->shutdown_status(i).input();
        instance.output =pack->shutdown_status(i).output();
        map->SHUTDOWN_STATUS.push(instance);
    }
    for(int i = 0; i < pack->marker_size(); i++){
        static primary_message_MARKER instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->marker(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        map->MARKER.push(instance);
    }
    for(int i = 0; i < pack->hv_cells_voltage_size(); i++){
        static primary_message_HV_CELLS_VOLTAGE_conversion instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->hv_cells_voltage(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.start_index =pack->hv_cells_voltage(i).start_index();
        instance.voltage_0 =pack->hv_cells_voltage(i).voltage_0();
        instance.voltage_1 =pack->hv_cells_voltage(i).voltage_1();
        instance.voltage_2 =pack->hv_cells_voltage(i).voltage_2();
        map->HV_CELLS_VOLTAGE.push(instance);
    }
    for(int i = 0; i < pack->hv_cells_temp_size(); i++){
        static primary_message_HV_CELLS_TEMP_conversion instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->hv_cells_temp(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.start_index =pack->hv_cells_temp(i).start_index();
        instance.temp_0 =pack->hv_cells_temp(i).temp_0();
        instance.temp_1 =pack->hv_cells_temp(i).temp_1();
        instance.temp_2 =pack->hv_cells_temp(i).temp_2();
        instance.temp_3 =pack->hv_cells_temp(i).temp_3();
        instance.temp_4 =pack->hv_cells_temp(i).temp_4();
        instance.temp_5 =pack->hv_cells_temp(i).temp_5();
        map->HV_CELLS_TEMP.push(instance);
    }
    for(int i = 0; i < pack->hv_cell_balancing_status_size(); i++){
        static primary_message_HV_CELL_BALANCING_STATUS instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->hv_cell_balancing_status(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.balancing_status =(primary_Toggle)pack->hv_cell_balancing_status(i).balancing_status();
        map->HV_CELL_BALANCING_STATUS.push(instance);
    }
    for(int i = 0; i < pack->set_cell_balancing_status_size(); i++){
        static primary_message_SET_CELL_BALANCING_STATUS instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->set_cell_balancing_status(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.set_balancing_status =(primary_Toggle)pack->set_cell_balancing_status(i).set_balancing_status();
        map->SET_CELL_BALANCING_STATUS.push(instance);
    }
    for(int i = 0; i < pack->handcart_status_size(); i++){
        static primary_message_HANDCART_STATUS instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->handcart_status(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.connected =pack->handcart_status(i).connected();
        map->HANDCART_STATUS.push(instance);
    }
    for(int i = 0; i < pack->speed_size(); i++){
        static primary_message_SPEED_conversion instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->speed(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.encoder_r =pack->speed(i).encoder_r();
        instance.encoder_l =pack->speed(i).encoder_l();
        instance.inverter_r =pack->speed(i).inverter_r();
        instance.inverter_l =pack->speed(i).inverter_l();
        map->SPEED.push(instance);
    }
    for(int i = 0; i < pack->inv_l_request_size(); i++){
        static primary_message_INV_L_REQUEST instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->inv_l_request(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.data_0 =pack->inv_l_request(i).data_0();
        instance.data_1 =pack->inv_l_request(i).data_1();
        instance.data_2 =pack->inv_l_request(i).data_2();
        instance.data_3 =pack->inv_l_request(i).data_3();
        instance.data_4 =pack->inv_l_request(i).data_4();
        instance.data_5 =pack->inv_l_request(i).data_5();
        instance.data_6 =pack->inv_l_request(i).data_6();
        instance.data_7 =pack->inv_l_request(i).data_7();
        map->INV_L_REQUEST.push(instance);
    }
    for(int i = 0; i < pack->inv_r_request_size(); i++){
        static primary_message_INV_R_REQUEST instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->inv_r_request(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.data_0 =pack->inv_r_request(i).data_0();
        instance.data_1 =pack->inv_r_request(i).data_1();
        instance.data_2 =pack->inv_r_request(i).data_2();
        instance.data_3 =pack->inv_r_request(i).data_3();
        instance.data_4 =pack->inv_r_request(i).data_4();
        instance.data_5 =pack->inv_r_request(i).data_5();
        instance.data_6 =pack->inv_r_request(i).data_6();
        instance.data_7 =pack->inv_r_request(i).data_7();
        map->INV_R_REQUEST.push(instance);
    }
    for(int i = 0; i < pack->inv_l_response_size(); i++){
        static primary_message_INV_L_RESPONSE instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->inv_l_response(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.reg_id =pack->inv_l_response(i).reg_id();
        instance.data_0 =pack->inv_l_response(i).data_0();
        instance.data_1 =pack->inv_l_response(i).data_1();
        instance.data_2 =pack->inv_l_response(i).data_2();
        instance.data_3 =pack->inv_l_response(i).data_3();
        instance.data_4 =pack->inv_l_response(i).data_4();
        instance.data_5 =pack->inv_l_response(i).data_5();
        instance.data_6 =pack->inv_l_response(i).data_6();
        map->INV_L_RESPONSE.push(instance);
    }
    for(int i = 0; i < pack->inv_r_response_size(); i++){
        static primary_message_INV_R_RESPONSE instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->inv_r_response(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.reg_id =pack->inv_r_response(i).reg_id();
        instance.data_0 =pack->inv_r_response(i).data_0();
        instance.data_1 =pack->inv_r_response(i).data_1();
        instance.data_2 =pack->inv_r_response(i).data_2();
        instance.data_3 =pack->inv_r_response(i).data_3();
        instance.data_4 =pack->inv_r_response(i).data_4();
        instance.data_5 =pack->inv_r_response(i).data_5();
        instance.data_6 =pack->inv_r_response(i).data_6();
        map->INV_R_RESPONSE.push(instance);
    }
    for(int i = 0; i < pack->flash_cellboard_0_tx_size(); i++){
        static primary_message_FLASH_CELLBOARD_0_TX instance;
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
        static primary_message_FLASH_CELLBOARD_0_RX instance;
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
        static primary_message_FLASH_CELLBOARD_1_TX instance;
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
        static primary_message_FLASH_CELLBOARD_1_RX instance;
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
        static primary_message_FLASH_CELLBOARD_2_TX instance;
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
        static primary_message_FLASH_CELLBOARD_2_RX instance;
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
        static primary_message_FLASH_CELLBOARD_3_TX instance;
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
        static primary_message_FLASH_CELLBOARD_3_RX instance;
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
        static primary_message_FLASH_CELLBOARD_4_TX instance;
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
        static primary_message_FLASH_CELLBOARD_4_RX instance;
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
        static primary_message_FLASH_CELLBOARD_5_TX instance;
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
        static primary_message_FLASH_CELLBOARD_5_RX instance;
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
    for(int i = 0; i < pack->flash_bms_hv_tx_size(); i++){
        static primary_message_FLASH_BMS_HV_TX instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->flash_bms_hv_tx(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        map->FLASH_BMS_HV_TX.push(instance);
    }
    for(int i = 0; i < pack->flash_bms_hv_rx_size(); i++){
        static primary_message_FLASH_BMS_HV_RX instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->flash_bms_hv_rx(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        map->FLASH_BMS_HV_RX.push(instance);
    }
    for(int i = 0; i < pack->flash_bms_lv_tx_size(); i++){
        static primary_message_FLASH_BMS_LV_TX instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->flash_bms_lv_tx(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        map->FLASH_BMS_LV_TX.push(instance);
    }
    for(int i = 0; i < pack->flash_bms_lv_rx_size(); i++){
        static primary_message_FLASH_BMS_LV_RX instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->flash_bms_lv_rx(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        map->FLASH_BMS_LV_RX.push(instance);
    }
    for(int i = 0; i < pack->brusa_nlg5_ctl_size(); i++){
        static primary_message_BRUSA_NLG5_CTL instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->brusa_nlg5_ctl(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        map->BRUSA_NLG5_CTL.push(instance);
    }
    for(int i = 0; i < pack->brusa_st_size(); i++){
        static primary_message_BRUSA_ST instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->brusa_st(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        map->BRUSA_ST.push(instance);
    }
    for(int i = 0; i < pack->brusa_act_i_size(); i++){
        static primary_message_BRUSA_ACT_I instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->brusa_act_i(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        map->BRUSA_ACT_I.push(instance);
    }
    for(int i = 0; i < pack->brusa_act_ii_size(); i++){
        static primary_message_BRUSA_ACT_II instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->brusa_act_ii(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        map->BRUSA_ACT_II.push(instance);
    }
    for(int i = 0; i < pack->brusa_temp_size(); i++){
        static primary_message_BRUSA_TEMP instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->brusa_temp(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        map->BRUSA_TEMP.push(instance);
    }
    for(int i = 0; i < pack->brusa_err_size(); i++){
        static primary_message_BRUSA_ERR instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->brusa_err(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        map->BRUSA_ERR.push(instance);
    }
    for(int i = 0; i < pack->control_output_size(); i++){
        static primary_message_CONTROL_OUTPUT_conversion instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->control_output(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.estimated_velocity =pack->control_output(i).estimated_velocity();
        instance.tmax_r =pack->control_output(i).tmax_r();
        instance.tmax_l =pack->control_output(i).tmax_l();
        instance.torque_l =pack->control_output(i).torque_l();
        instance.torque_r =pack->control_output(i).torque_r();
        map->CONTROL_OUTPUT.push(instance);
    }
    for(int i = 0; i < pack->lc_reset_size(); i++){
        static primary_message_LC_RESET instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->lc_reset(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        map->LC_RESET.push(instance);
    }
}

#endif // primary_MAPPING_IMPLEMENTATION

#endif // primary_MAPPING_H