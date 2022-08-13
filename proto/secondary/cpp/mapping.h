#ifndef secondary_MAPPING_H
#define secondary_MAPPING_H

#include <string>
#include <unordered_map>
#include <functional>

#include "secondary.pb.h"

#ifdef secondary_IMPLEMENTATION
#undef secondary_IMPLEMENTATION
#define __secondary_IMPLEMENTATION
#endif

#include "../../../lib/secondary/c/network.h"

#ifdef __secondary_IMPLEMENTATION
#undef __secondary_IMPLEMENTATION
#define secondary_IMPLEMENTATION
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
    canlib_circular_buffer<secondary_message_IMU_ANGULAR_RATE_conversion, CANLIB_CIRCULAR_BUFFER_SIZE> IMU_ANGULAR_RATE;
    canlib_circular_buffer<secondary_message_IMU_ACCELERATION_conversion, CANLIB_CIRCULAR_BUFFER_SIZE> IMU_ACCELERATION;
    canlib_circular_buffer<secondary_message_IRTS_FL_0, CANLIB_CIRCULAR_BUFFER_SIZE> IRTS_FL_0;
    canlib_circular_buffer<secondary_message_IRTS_FL_1, CANLIB_CIRCULAR_BUFFER_SIZE> IRTS_FL_1;
    canlib_circular_buffer<secondary_message_IRTS_FL_2, CANLIB_CIRCULAR_BUFFER_SIZE> IRTS_FL_2;
    canlib_circular_buffer<secondary_message_IRTS_FL_3, CANLIB_CIRCULAR_BUFFER_SIZE> IRTS_FL_3;
    canlib_circular_buffer<secondary_message_IRTS_FR_0, CANLIB_CIRCULAR_BUFFER_SIZE> IRTS_FR_0;
    canlib_circular_buffer<secondary_message_IRTS_FR_1, CANLIB_CIRCULAR_BUFFER_SIZE> IRTS_FR_1;
    canlib_circular_buffer<secondary_message_IRTS_FR_2, CANLIB_CIRCULAR_BUFFER_SIZE> IRTS_FR_2;
    canlib_circular_buffer<secondary_message_IRTS_FR_3, CANLIB_CIRCULAR_BUFFER_SIZE> IRTS_FR_3;
    canlib_circular_buffer<secondary_message_IRTS_RL_0, CANLIB_CIRCULAR_BUFFER_SIZE> IRTS_RL_0;
    canlib_circular_buffer<secondary_message_IRTS_RL_1, CANLIB_CIRCULAR_BUFFER_SIZE> IRTS_RL_1;
    canlib_circular_buffer<secondary_message_IRTS_RL_2, CANLIB_CIRCULAR_BUFFER_SIZE> IRTS_RL_2;
    canlib_circular_buffer<secondary_message_IRTS_RL_3, CANLIB_CIRCULAR_BUFFER_SIZE> IRTS_RL_3;
    canlib_circular_buffer<secondary_message_IRTS_RR_0, CANLIB_CIRCULAR_BUFFER_SIZE> IRTS_RR_0;
    canlib_circular_buffer<secondary_message_IRTS_RR_1, CANLIB_CIRCULAR_BUFFER_SIZE> IRTS_RR_1;
    canlib_circular_buffer<secondary_message_IRTS_RR_2, CANLIB_CIRCULAR_BUFFER_SIZE> IRTS_RR_2;
    canlib_circular_buffer<secondary_message_IRTS_RR_3, CANLIB_CIRCULAR_BUFFER_SIZE> IRTS_RR_3;
    canlib_circular_buffer<secondary_message_GPS_COORDS, CANLIB_CIRCULAR_BUFFER_SIZE> GPS_COORDS;
    canlib_circular_buffer<secondary_message_GPS_SPEED, CANLIB_CIRCULAR_BUFFER_SIZE> GPS_SPEED;
    canlib_circular_buffer<secondary_message_LAP_COUNT, CANLIB_CIRCULAR_BUFFER_SIZE> LAP_COUNT;
    canlib_circular_buffer<secondary_message_PEDALS_OUTPUT_conversion, CANLIB_CIRCULAR_BUFFER_SIZE> PEDALS_OUTPUT;
    canlib_circular_buffer<secondary_message_CONTROL_OUTPUT, CANLIB_CIRCULAR_BUFFER_SIZE> CONTROL_OUTPUT;
    canlib_circular_buffer<secondary_message_STEERING_ANGLE, CANLIB_CIRCULAR_BUFFER_SIZE> STEERING_ANGLE;
} secondary_proto_pack;

void secondary_mapping_adaptor_construct(const secondary_proto_pack& pack, mapping_adaptor& mapping_map);
void secondary_proto_serialize_from_id(canlib_message_id id, secondary::Pack* pack, secondary_devices* map);
void secondary_proto_deserialize(secondary::Pack* pack, secondary_proto_pack* map, uint64_t resample_us);

#ifdef secondary_MAPPING_IMPLEMENTATION

void secondary_mapping_adaptor_construct(const secondary_proto_pack& pack, mapping_adaptor& mapping_map){
    mapping_map["IMU_ANGULAR_RATE"].size = std::bind(&canlib_circular_buffer<secondary_message_IMU_ANGULAR_RATE_conversion, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.IMU_ANGULAR_RATE);
    mapping_map["IMU_ANGULAR_RATE"].offset = std::bind(&canlib_circular_buffer<secondary_message_IMU_ANGULAR_RATE_conversion, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.IMU_ANGULAR_RATE);
    mapping_map["IMU_ANGULAR_RATE"].stride = sizeof(secondary_message_IMU_ANGULAR_RATE_conversion);
    mapping_map["IMU_ANGULAR_RATE"].field["ang_rate_x"].value._float32 = &pack.IMU_ANGULAR_RATE.start().ang_rate_x;
    mapping_map["IMU_ANGULAR_RATE"].field["ang_rate_x"].type = mapping_type_float32;
    mapping_map["IMU_ANGULAR_RATE"].field["ang_rate_y"].value._float32 = &pack.IMU_ANGULAR_RATE.start().ang_rate_y;
    mapping_map["IMU_ANGULAR_RATE"].field["ang_rate_y"].type = mapping_type_float32;
    mapping_map["IMU_ANGULAR_RATE"].field["ang_rate_z"].value._float32 = &pack.IMU_ANGULAR_RATE.start().ang_rate_z;
    mapping_map["IMU_ANGULAR_RATE"].field["ang_rate_z"].type = mapping_type_float32;
    mapping_map["IMU_ANGULAR_RATE"].field["temperature"].value._int16 = &pack.IMU_ANGULAR_RATE.start().temperature;
    mapping_map["IMU_ANGULAR_RATE"].field["temperature"].type = mapping_type_int16;
#ifdef CANLIB_TIMESTAMP
    mapping_map["IMU_ANGULAR_RATE"].field["_timestamp"].value._uint64 = &pack.IMU_ANGULAR_RATE.start()._timestamp;
    mapping_map["IMU_ANGULAR_RATE"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["IMU_ACCELERATION"].size = std::bind(&canlib_circular_buffer<secondary_message_IMU_ACCELERATION_conversion, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.IMU_ACCELERATION);
    mapping_map["IMU_ACCELERATION"].offset = std::bind(&canlib_circular_buffer<secondary_message_IMU_ACCELERATION_conversion, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.IMU_ACCELERATION);
    mapping_map["IMU_ACCELERATION"].stride = sizeof(secondary_message_IMU_ACCELERATION_conversion);
    mapping_map["IMU_ACCELERATION"].field["accel_x"].value._float32 = &pack.IMU_ACCELERATION.start().accel_x;
    mapping_map["IMU_ACCELERATION"].field["accel_x"].type = mapping_type_float32;
    mapping_map["IMU_ACCELERATION"].field["accel_y"].value._float32 = &pack.IMU_ACCELERATION.start().accel_y;
    mapping_map["IMU_ACCELERATION"].field["accel_y"].type = mapping_type_float32;
    mapping_map["IMU_ACCELERATION"].field["accel_z"].value._float32 = &pack.IMU_ACCELERATION.start().accel_z;
    mapping_map["IMU_ACCELERATION"].field["accel_z"].type = mapping_type_float32;
#ifdef CANLIB_TIMESTAMP
    mapping_map["IMU_ACCELERATION"].field["_timestamp"].value._uint64 = &pack.IMU_ACCELERATION.start()._timestamp;
    mapping_map["IMU_ACCELERATION"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["IRTS_FL_0"].size = std::bind(&canlib_circular_buffer<secondary_message_IRTS_FL_0, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.IRTS_FL_0);
    mapping_map["IRTS_FL_0"].offset = std::bind(&canlib_circular_buffer<secondary_message_IRTS_FL_0, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.IRTS_FL_0);
    mapping_map["IRTS_FL_0"].stride = sizeof(secondary_message_IRTS_FL_0);
    mapping_map["IRTS_FL_0"].field["channel1"].value._uint16 = &pack.IRTS_FL_0.start().channel1;
    mapping_map["IRTS_FL_0"].field["channel1"].type = mapping_type_uint16;
    mapping_map["IRTS_FL_0"].field["channel2"].value._uint16 = &pack.IRTS_FL_0.start().channel2;
    mapping_map["IRTS_FL_0"].field["channel2"].type = mapping_type_uint16;
    mapping_map["IRTS_FL_0"].field["channel3"].value._uint16 = &pack.IRTS_FL_0.start().channel3;
    mapping_map["IRTS_FL_0"].field["channel3"].type = mapping_type_uint16;
    mapping_map["IRTS_FL_0"].field["channel4"].value._uint16 = &pack.IRTS_FL_0.start().channel4;
    mapping_map["IRTS_FL_0"].field["channel4"].type = mapping_type_uint16;
#ifdef CANLIB_TIMESTAMP
    mapping_map["IRTS_FL_0"].field["_timestamp"].value._uint64 = &pack.IRTS_FL_0.start()._timestamp;
    mapping_map["IRTS_FL_0"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["IRTS_FL_1"].size = std::bind(&canlib_circular_buffer<secondary_message_IRTS_FL_1, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.IRTS_FL_1);
    mapping_map["IRTS_FL_1"].offset = std::bind(&canlib_circular_buffer<secondary_message_IRTS_FL_1, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.IRTS_FL_1);
    mapping_map["IRTS_FL_1"].stride = sizeof(secondary_message_IRTS_FL_1);
    mapping_map["IRTS_FL_1"].field["channel5"].value._uint16 = &pack.IRTS_FL_1.start().channel5;
    mapping_map["IRTS_FL_1"].field["channel5"].type = mapping_type_uint16;
    mapping_map["IRTS_FL_1"].field["channel6"].value._uint16 = &pack.IRTS_FL_1.start().channel6;
    mapping_map["IRTS_FL_1"].field["channel6"].type = mapping_type_uint16;
    mapping_map["IRTS_FL_1"].field["channel7"].value._uint16 = &pack.IRTS_FL_1.start().channel7;
    mapping_map["IRTS_FL_1"].field["channel7"].type = mapping_type_uint16;
    mapping_map["IRTS_FL_1"].field["channel8"].value._uint16 = &pack.IRTS_FL_1.start().channel8;
    mapping_map["IRTS_FL_1"].field["channel8"].type = mapping_type_uint16;
#ifdef CANLIB_TIMESTAMP
    mapping_map["IRTS_FL_1"].field["_timestamp"].value._uint64 = &pack.IRTS_FL_1.start()._timestamp;
    mapping_map["IRTS_FL_1"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["IRTS_FL_2"].size = std::bind(&canlib_circular_buffer<secondary_message_IRTS_FL_2, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.IRTS_FL_2);
    mapping_map["IRTS_FL_2"].offset = std::bind(&canlib_circular_buffer<secondary_message_IRTS_FL_2, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.IRTS_FL_2);
    mapping_map["IRTS_FL_2"].stride = sizeof(secondary_message_IRTS_FL_2);
    mapping_map["IRTS_FL_2"].field["channel9"].value._uint16 = &pack.IRTS_FL_2.start().channel9;
    mapping_map["IRTS_FL_2"].field["channel9"].type = mapping_type_uint16;
    mapping_map["IRTS_FL_2"].field["channel10"].value._uint16 = &pack.IRTS_FL_2.start().channel10;
    mapping_map["IRTS_FL_2"].field["channel10"].type = mapping_type_uint16;
    mapping_map["IRTS_FL_2"].field["channel11"].value._uint16 = &pack.IRTS_FL_2.start().channel11;
    mapping_map["IRTS_FL_2"].field["channel11"].type = mapping_type_uint16;
    mapping_map["IRTS_FL_2"].field["channel12"].value._uint16 = &pack.IRTS_FL_2.start().channel12;
    mapping_map["IRTS_FL_2"].field["channel12"].type = mapping_type_uint16;
#ifdef CANLIB_TIMESTAMP
    mapping_map["IRTS_FL_2"].field["_timestamp"].value._uint64 = &pack.IRTS_FL_2.start()._timestamp;
    mapping_map["IRTS_FL_2"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["IRTS_FL_3"].size = std::bind(&canlib_circular_buffer<secondary_message_IRTS_FL_3, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.IRTS_FL_3);
    mapping_map["IRTS_FL_3"].offset = std::bind(&canlib_circular_buffer<secondary_message_IRTS_FL_3, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.IRTS_FL_3);
    mapping_map["IRTS_FL_3"].stride = sizeof(secondary_message_IRTS_FL_3);
    mapping_map["IRTS_FL_3"].field["channel13"].value._uint16 = &pack.IRTS_FL_3.start().channel13;
    mapping_map["IRTS_FL_3"].field["channel13"].type = mapping_type_uint16;
    mapping_map["IRTS_FL_3"].field["channel14"].value._uint16 = &pack.IRTS_FL_3.start().channel14;
    mapping_map["IRTS_FL_3"].field["channel14"].type = mapping_type_uint16;
    mapping_map["IRTS_FL_3"].field["channel15"].value._uint16 = &pack.IRTS_FL_3.start().channel15;
    mapping_map["IRTS_FL_3"].field["channel15"].type = mapping_type_uint16;
    mapping_map["IRTS_FL_3"].field["channel16"].value._uint16 = &pack.IRTS_FL_3.start().channel16;
    mapping_map["IRTS_FL_3"].field["channel16"].type = mapping_type_uint16;
#ifdef CANLIB_TIMESTAMP
    mapping_map["IRTS_FL_3"].field["_timestamp"].value._uint64 = &pack.IRTS_FL_3.start()._timestamp;
    mapping_map["IRTS_FL_3"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["IRTS_FR_0"].size = std::bind(&canlib_circular_buffer<secondary_message_IRTS_FR_0, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.IRTS_FR_0);
    mapping_map["IRTS_FR_0"].offset = std::bind(&canlib_circular_buffer<secondary_message_IRTS_FR_0, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.IRTS_FR_0);
    mapping_map["IRTS_FR_0"].stride = sizeof(secondary_message_IRTS_FR_0);
    mapping_map["IRTS_FR_0"].field["channel1"].value._uint16 = &pack.IRTS_FR_0.start().channel1;
    mapping_map["IRTS_FR_0"].field["channel1"].type = mapping_type_uint16;
    mapping_map["IRTS_FR_0"].field["channel2"].value._uint16 = &pack.IRTS_FR_0.start().channel2;
    mapping_map["IRTS_FR_0"].field["channel2"].type = mapping_type_uint16;
    mapping_map["IRTS_FR_0"].field["channel3"].value._uint16 = &pack.IRTS_FR_0.start().channel3;
    mapping_map["IRTS_FR_0"].field["channel3"].type = mapping_type_uint16;
    mapping_map["IRTS_FR_0"].field["channel4"].value._uint16 = &pack.IRTS_FR_0.start().channel4;
    mapping_map["IRTS_FR_0"].field["channel4"].type = mapping_type_uint16;
#ifdef CANLIB_TIMESTAMP
    mapping_map["IRTS_FR_0"].field["_timestamp"].value._uint64 = &pack.IRTS_FR_0.start()._timestamp;
    mapping_map["IRTS_FR_0"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["IRTS_FR_1"].size = std::bind(&canlib_circular_buffer<secondary_message_IRTS_FR_1, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.IRTS_FR_1);
    mapping_map["IRTS_FR_1"].offset = std::bind(&canlib_circular_buffer<secondary_message_IRTS_FR_1, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.IRTS_FR_1);
    mapping_map["IRTS_FR_1"].stride = sizeof(secondary_message_IRTS_FR_1);
    mapping_map["IRTS_FR_1"].field["channel5"].value._uint16 = &pack.IRTS_FR_1.start().channel5;
    mapping_map["IRTS_FR_1"].field["channel5"].type = mapping_type_uint16;
    mapping_map["IRTS_FR_1"].field["channel6"].value._uint16 = &pack.IRTS_FR_1.start().channel6;
    mapping_map["IRTS_FR_1"].field["channel6"].type = mapping_type_uint16;
    mapping_map["IRTS_FR_1"].field["channel7"].value._uint16 = &pack.IRTS_FR_1.start().channel7;
    mapping_map["IRTS_FR_1"].field["channel7"].type = mapping_type_uint16;
    mapping_map["IRTS_FR_1"].field["channel8"].value._uint16 = &pack.IRTS_FR_1.start().channel8;
    mapping_map["IRTS_FR_1"].field["channel8"].type = mapping_type_uint16;
#ifdef CANLIB_TIMESTAMP
    mapping_map["IRTS_FR_1"].field["_timestamp"].value._uint64 = &pack.IRTS_FR_1.start()._timestamp;
    mapping_map["IRTS_FR_1"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["IRTS_FR_2"].size = std::bind(&canlib_circular_buffer<secondary_message_IRTS_FR_2, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.IRTS_FR_2);
    mapping_map["IRTS_FR_2"].offset = std::bind(&canlib_circular_buffer<secondary_message_IRTS_FR_2, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.IRTS_FR_2);
    mapping_map["IRTS_FR_2"].stride = sizeof(secondary_message_IRTS_FR_2);
    mapping_map["IRTS_FR_2"].field["channel9"].value._uint16 = &pack.IRTS_FR_2.start().channel9;
    mapping_map["IRTS_FR_2"].field["channel9"].type = mapping_type_uint16;
    mapping_map["IRTS_FR_2"].field["channel10"].value._uint16 = &pack.IRTS_FR_2.start().channel10;
    mapping_map["IRTS_FR_2"].field["channel10"].type = mapping_type_uint16;
    mapping_map["IRTS_FR_2"].field["channel11"].value._uint16 = &pack.IRTS_FR_2.start().channel11;
    mapping_map["IRTS_FR_2"].field["channel11"].type = mapping_type_uint16;
    mapping_map["IRTS_FR_2"].field["channel12"].value._uint16 = &pack.IRTS_FR_2.start().channel12;
    mapping_map["IRTS_FR_2"].field["channel12"].type = mapping_type_uint16;
#ifdef CANLIB_TIMESTAMP
    mapping_map["IRTS_FR_2"].field["_timestamp"].value._uint64 = &pack.IRTS_FR_2.start()._timestamp;
    mapping_map["IRTS_FR_2"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["IRTS_FR_3"].size = std::bind(&canlib_circular_buffer<secondary_message_IRTS_FR_3, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.IRTS_FR_3);
    mapping_map["IRTS_FR_3"].offset = std::bind(&canlib_circular_buffer<secondary_message_IRTS_FR_3, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.IRTS_FR_3);
    mapping_map["IRTS_FR_3"].stride = sizeof(secondary_message_IRTS_FR_3);
    mapping_map["IRTS_FR_3"].field["channel13"].value._uint16 = &pack.IRTS_FR_3.start().channel13;
    mapping_map["IRTS_FR_3"].field["channel13"].type = mapping_type_uint16;
    mapping_map["IRTS_FR_3"].field["channel14"].value._uint16 = &pack.IRTS_FR_3.start().channel14;
    mapping_map["IRTS_FR_3"].field["channel14"].type = mapping_type_uint16;
    mapping_map["IRTS_FR_3"].field["channel15"].value._uint16 = &pack.IRTS_FR_3.start().channel15;
    mapping_map["IRTS_FR_3"].field["channel15"].type = mapping_type_uint16;
    mapping_map["IRTS_FR_3"].field["channel16"].value._uint16 = &pack.IRTS_FR_3.start().channel16;
    mapping_map["IRTS_FR_3"].field["channel16"].type = mapping_type_uint16;
#ifdef CANLIB_TIMESTAMP
    mapping_map["IRTS_FR_3"].field["_timestamp"].value._uint64 = &pack.IRTS_FR_3.start()._timestamp;
    mapping_map["IRTS_FR_3"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["IRTS_RL_0"].size = std::bind(&canlib_circular_buffer<secondary_message_IRTS_RL_0, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.IRTS_RL_0);
    mapping_map["IRTS_RL_0"].offset = std::bind(&canlib_circular_buffer<secondary_message_IRTS_RL_0, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.IRTS_RL_0);
    mapping_map["IRTS_RL_0"].stride = sizeof(secondary_message_IRTS_RL_0);
    mapping_map["IRTS_RL_0"].field["channel1"].value._uint16 = &pack.IRTS_RL_0.start().channel1;
    mapping_map["IRTS_RL_0"].field["channel1"].type = mapping_type_uint16;
    mapping_map["IRTS_RL_0"].field["channel2"].value._uint16 = &pack.IRTS_RL_0.start().channel2;
    mapping_map["IRTS_RL_0"].field["channel2"].type = mapping_type_uint16;
    mapping_map["IRTS_RL_0"].field["channel3"].value._uint16 = &pack.IRTS_RL_0.start().channel3;
    mapping_map["IRTS_RL_0"].field["channel3"].type = mapping_type_uint16;
    mapping_map["IRTS_RL_0"].field["channel4"].value._uint16 = &pack.IRTS_RL_0.start().channel4;
    mapping_map["IRTS_RL_0"].field["channel4"].type = mapping_type_uint16;
#ifdef CANLIB_TIMESTAMP
    mapping_map["IRTS_RL_0"].field["_timestamp"].value._uint64 = &pack.IRTS_RL_0.start()._timestamp;
    mapping_map["IRTS_RL_0"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["IRTS_RL_1"].size = std::bind(&canlib_circular_buffer<secondary_message_IRTS_RL_1, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.IRTS_RL_1);
    mapping_map["IRTS_RL_1"].offset = std::bind(&canlib_circular_buffer<secondary_message_IRTS_RL_1, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.IRTS_RL_1);
    mapping_map["IRTS_RL_1"].stride = sizeof(secondary_message_IRTS_RL_1);
    mapping_map["IRTS_RL_1"].field["channel5"].value._uint16 = &pack.IRTS_RL_1.start().channel5;
    mapping_map["IRTS_RL_1"].field["channel5"].type = mapping_type_uint16;
    mapping_map["IRTS_RL_1"].field["channel6"].value._uint16 = &pack.IRTS_RL_1.start().channel6;
    mapping_map["IRTS_RL_1"].field["channel6"].type = mapping_type_uint16;
    mapping_map["IRTS_RL_1"].field["channel7"].value._uint16 = &pack.IRTS_RL_1.start().channel7;
    mapping_map["IRTS_RL_1"].field["channel7"].type = mapping_type_uint16;
    mapping_map["IRTS_RL_1"].field["channel8"].value._uint16 = &pack.IRTS_RL_1.start().channel8;
    mapping_map["IRTS_RL_1"].field["channel8"].type = mapping_type_uint16;
#ifdef CANLIB_TIMESTAMP
    mapping_map["IRTS_RL_1"].field["_timestamp"].value._uint64 = &pack.IRTS_RL_1.start()._timestamp;
    mapping_map["IRTS_RL_1"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["IRTS_RL_2"].size = std::bind(&canlib_circular_buffer<secondary_message_IRTS_RL_2, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.IRTS_RL_2);
    mapping_map["IRTS_RL_2"].offset = std::bind(&canlib_circular_buffer<secondary_message_IRTS_RL_2, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.IRTS_RL_2);
    mapping_map["IRTS_RL_2"].stride = sizeof(secondary_message_IRTS_RL_2);
    mapping_map["IRTS_RL_2"].field["channel9"].value._uint16 = &pack.IRTS_RL_2.start().channel9;
    mapping_map["IRTS_RL_2"].field["channel9"].type = mapping_type_uint16;
    mapping_map["IRTS_RL_2"].field["channel10"].value._uint16 = &pack.IRTS_RL_2.start().channel10;
    mapping_map["IRTS_RL_2"].field["channel10"].type = mapping_type_uint16;
    mapping_map["IRTS_RL_2"].field["channel11"].value._uint16 = &pack.IRTS_RL_2.start().channel11;
    mapping_map["IRTS_RL_2"].field["channel11"].type = mapping_type_uint16;
    mapping_map["IRTS_RL_2"].field["channel12"].value._uint16 = &pack.IRTS_RL_2.start().channel12;
    mapping_map["IRTS_RL_2"].field["channel12"].type = mapping_type_uint16;
#ifdef CANLIB_TIMESTAMP
    mapping_map["IRTS_RL_2"].field["_timestamp"].value._uint64 = &pack.IRTS_RL_2.start()._timestamp;
    mapping_map["IRTS_RL_2"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["IRTS_RL_3"].size = std::bind(&canlib_circular_buffer<secondary_message_IRTS_RL_3, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.IRTS_RL_3);
    mapping_map["IRTS_RL_3"].offset = std::bind(&canlib_circular_buffer<secondary_message_IRTS_RL_3, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.IRTS_RL_3);
    mapping_map["IRTS_RL_3"].stride = sizeof(secondary_message_IRTS_RL_3);
    mapping_map["IRTS_RL_3"].field["channel13"].value._uint16 = &pack.IRTS_RL_3.start().channel13;
    mapping_map["IRTS_RL_3"].field["channel13"].type = mapping_type_uint16;
    mapping_map["IRTS_RL_3"].field["channel14"].value._uint16 = &pack.IRTS_RL_3.start().channel14;
    mapping_map["IRTS_RL_3"].field["channel14"].type = mapping_type_uint16;
    mapping_map["IRTS_RL_3"].field["channel15"].value._uint16 = &pack.IRTS_RL_3.start().channel15;
    mapping_map["IRTS_RL_3"].field["channel15"].type = mapping_type_uint16;
    mapping_map["IRTS_RL_3"].field["channel16"].value._uint16 = &pack.IRTS_RL_3.start().channel16;
    mapping_map["IRTS_RL_3"].field["channel16"].type = mapping_type_uint16;
#ifdef CANLIB_TIMESTAMP
    mapping_map["IRTS_RL_3"].field["_timestamp"].value._uint64 = &pack.IRTS_RL_3.start()._timestamp;
    mapping_map["IRTS_RL_3"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["IRTS_RR_0"].size = std::bind(&canlib_circular_buffer<secondary_message_IRTS_RR_0, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.IRTS_RR_0);
    mapping_map["IRTS_RR_0"].offset = std::bind(&canlib_circular_buffer<secondary_message_IRTS_RR_0, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.IRTS_RR_0);
    mapping_map["IRTS_RR_0"].stride = sizeof(secondary_message_IRTS_RR_0);
    mapping_map["IRTS_RR_0"].field["channel1"].value._uint16 = &pack.IRTS_RR_0.start().channel1;
    mapping_map["IRTS_RR_0"].field["channel1"].type = mapping_type_uint16;
    mapping_map["IRTS_RR_0"].field["channel2"].value._uint16 = &pack.IRTS_RR_0.start().channel2;
    mapping_map["IRTS_RR_0"].field["channel2"].type = mapping_type_uint16;
    mapping_map["IRTS_RR_0"].field["channel3"].value._uint16 = &pack.IRTS_RR_0.start().channel3;
    mapping_map["IRTS_RR_0"].field["channel3"].type = mapping_type_uint16;
    mapping_map["IRTS_RR_0"].field["channel4"].value._uint16 = &pack.IRTS_RR_0.start().channel4;
    mapping_map["IRTS_RR_0"].field["channel4"].type = mapping_type_uint16;
#ifdef CANLIB_TIMESTAMP
    mapping_map["IRTS_RR_0"].field["_timestamp"].value._uint64 = &pack.IRTS_RR_0.start()._timestamp;
    mapping_map["IRTS_RR_0"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["IRTS_RR_1"].size = std::bind(&canlib_circular_buffer<secondary_message_IRTS_RR_1, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.IRTS_RR_1);
    mapping_map["IRTS_RR_1"].offset = std::bind(&canlib_circular_buffer<secondary_message_IRTS_RR_1, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.IRTS_RR_1);
    mapping_map["IRTS_RR_1"].stride = sizeof(secondary_message_IRTS_RR_1);
    mapping_map["IRTS_RR_1"].field["channel5"].value._uint16 = &pack.IRTS_RR_1.start().channel5;
    mapping_map["IRTS_RR_1"].field["channel5"].type = mapping_type_uint16;
    mapping_map["IRTS_RR_1"].field["channel6"].value._uint16 = &pack.IRTS_RR_1.start().channel6;
    mapping_map["IRTS_RR_1"].field["channel6"].type = mapping_type_uint16;
    mapping_map["IRTS_RR_1"].field["channel7"].value._uint16 = &pack.IRTS_RR_1.start().channel7;
    mapping_map["IRTS_RR_1"].field["channel7"].type = mapping_type_uint16;
    mapping_map["IRTS_RR_1"].field["channel8"].value._uint16 = &pack.IRTS_RR_1.start().channel8;
    mapping_map["IRTS_RR_1"].field["channel8"].type = mapping_type_uint16;
#ifdef CANLIB_TIMESTAMP
    mapping_map["IRTS_RR_1"].field["_timestamp"].value._uint64 = &pack.IRTS_RR_1.start()._timestamp;
    mapping_map["IRTS_RR_1"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["IRTS_RR_2"].size = std::bind(&canlib_circular_buffer<secondary_message_IRTS_RR_2, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.IRTS_RR_2);
    mapping_map["IRTS_RR_2"].offset = std::bind(&canlib_circular_buffer<secondary_message_IRTS_RR_2, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.IRTS_RR_2);
    mapping_map["IRTS_RR_2"].stride = sizeof(secondary_message_IRTS_RR_2);
    mapping_map["IRTS_RR_2"].field["channel9"].value._uint16 = &pack.IRTS_RR_2.start().channel9;
    mapping_map["IRTS_RR_2"].field["channel9"].type = mapping_type_uint16;
    mapping_map["IRTS_RR_2"].field["channel10"].value._uint16 = &pack.IRTS_RR_2.start().channel10;
    mapping_map["IRTS_RR_2"].field["channel10"].type = mapping_type_uint16;
    mapping_map["IRTS_RR_2"].field["channel11"].value._uint16 = &pack.IRTS_RR_2.start().channel11;
    mapping_map["IRTS_RR_2"].field["channel11"].type = mapping_type_uint16;
    mapping_map["IRTS_RR_2"].field["channel12"].value._uint16 = &pack.IRTS_RR_2.start().channel12;
    mapping_map["IRTS_RR_2"].field["channel12"].type = mapping_type_uint16;
#ifdef CANLIB_TIMESTAMP
    mapping_map["IRTS_RR_2"].field["_timestamp"].value._uint64 = &pack.IRTS_RR_2.start()._timestamp;
    mapping_map["IRTS_RR_2"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["IRTS_RR_3"].size = std::bind(&canlib_circular_buffer<secondary_message_IRTS_RR_3, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.IRTS_RR_3);
    mapping_map["IRTS_RR_3"].offset = std::bind(&canlib_circular_buffer<secondary_message_IRTS_RR_3, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.IRTS_RR_3);
    mapping_map["IRTS_RR_3"].stride = sizeof(secondary_message_IRTS_RR_3);
    mapping_map["IRTS_RR_3"].field["channel13"].value._uint16 = &pack.IRTS_RR_3.start().channel13;
    mapping_map["IRTS_RR_3"].field["channel13"].type = mapping_type_uint16;
    mapping_map["IRTS_RR_3"].field["channel14"].value._uint16 = &pack.IRTS_RR_3.start().channel14;
    mapping_map["IRTS_RR_3"].field["channel14"].type = mapping_type_uint16;
    mapping_map["IRTS_RR_3"].field["channel15"].value._uint16 = &pack.IRTS_RR_3.start().channel15;
    mapping_map["IRTS_RR_3"].field["channel15"].type = mapping_type_uint16;
    mapping_map["IRTS_RR_3"].field["channel16"].value._uint16 = &pack.IRTS_RR_3.start().channel16;
    mapping_map["IRTS_RR_3"].field["channel16"].type = mapping_type_uint16;
#ifdef CANLIB_TIMESTAMP
    mapping_map["IRTS_RR_3"].field["_timestamp"].value._uint64 = &pack.IRTS_RR_3.start()._timestamp;
    mapping_map["IRTS_RR_3"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["GPS_COORDS"].size = std::bind(&canlib_circular_buffer<secondary_message_GPS_COORDS, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.GPS_COORDS);
    mapping_map["GPS_COORDS"].offset = std::bind(&canlib_circular_buffer<secondary_message_GPS_COORDS, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.GPS_COORDS);
    mapping_map["GPS_COORDS"].stride = sizeof(secondary_message_GPS_COORDS);
    mapping_map["GPS_COORDS"].field["latitude"].value._float32 = &pack.GPS_COORDS.start().latitude;
    mapping_map["GPS_COORDS"].field["latitude"].type = mapping_type_float32;
    mapping_map["GPS_COORDS"].field["longitude"].value._float32 = &pack.GPS_COORDS.start().longitude;
    mapping_map["GPS_COORDS"].field["longitude"].type = mapping_type_float32;
#ifdef CANLIB_TIMESTAMP
    mapping_map["GPS_COORDS"].field["_timestamp"].value._uint64 = &pack.GPS_COORDS.start()._timestamp;
    mapping_map["GPS_COORDS"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["GPS_SPEED"].size = std::bind(&canlib_circular_buffer<secondary_message_GPS_SPEED, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.GPS_SPEED);
    mapping_map["GPS_SPEED"].offset = std::bind(&canlib_circular_buffer<secondary_message_GPS_SPEED, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.GPS_SPEED);
    mapping_map["GPS_SPEED"].stride = sizeof(secondary_message_GPS_SPEED);
    mapping_map["GPS_SPEED"].field["speed"].value._uint16 = &pack.GPS_SPEED.start().speed;
    mapping_map["GPS_SPEED"].field["speed"].type = mapping_type_uint16;
#ifdef CANLIB_TIMESTAMP
    mapping_map["GPS_SPEED"].field["_timestamp"].value._uint64 = &pack.GPS_SPEED.start()._timestamp;
    mapping_map["GPS_SPEED"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["LAP_COUNT"].size = std::bind(&canlib_circular_buffer<secondary_message_LAP_COUNT, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.LAP_COUNT);
    mapping_map["LAP_COUNT"].offset = std::bind(&canlib_circular_buffer<secondary_message_LAP_COUNT, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.LAP_COUNT);
    mapping_map["LAP_COUNT"].stride = sizeof(secondary_message_LAP_COUNT);
    mapping_map["LAP_COUNT"].field["lap_count"].value._uint8 = &pack.LAP_COUNT.start().lap_count;
    mapping_map["LAP_COUNT"].field["lap_count"].type = mapping_type_uint8;
    mapping_map["LAP_COUNT"].field["lap_time"].value._uint32 = &pack.LAP_COUNT.start().lap_time;
    mapping_map["LAP_COUNT"].field["lap_time"].type = mapping_type_uint32;
#ifdef CANLIB_TIMESTAMP
    mapping_map["LAP_COUNT"].field["_timestamp"].value._uint64 = &pack.LAP_COUNT.start()._timestamp;
    mapping_map["LAP_COUNT"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["PEDALS_OUTPUT"].size = std::bind(&canlib_circular_buffer<secondary_message_PEDALS_OUTPUT_conversion, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.PEDALS_OUTPUT);
    mapping_map["PEDALS_OUTPUT"].offset = std::bind(&canlib_circular_buffer<secondary_message_PEDALS_OUTPUT_conversion, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.PEDALS_OUTPUT);
    mapping_map["PEDALS_OUTPUT"].stride = sizeof(secondary_message_PEDALS_OUTPUT_conversion);
    mapping_map["PEDALS_OUTPUT"].field["apps"].value._uint8 = &pack.PEDALS_OUTPUT.start().apps;
    mapping_map["PEDALS_OUTPUT"].field["apps"].type = mapping_type_uint8;
    mapping_map["PEDALS_OUTPUT"].field["bse_front"].value._float32 = &pack.PEDALS_OUTPUT.start().bse_front;
    mapping_map["PEDALS_OUTPUT"].field["bse_front"].type = mapping_type_float32;
    mapping_map["PEDALS_OUTPUT"].field["bse_rear"].value._float32 = &pack.PEDALS_OUTPUT.start().bse_rear;
    mapping_map["PEDALS_OUTPUT"].field["bse_rear"].type = mapping_type_float32;
#ifdef CANLIB_TIMESTAMP
    mapping_map["PEDALS_OUTPUT"].field["_timestamp"].value._uint64 = &pack.PEDALS_OUTPUT.start()._timestamp;
    mapping_map["PEDALS_OUTPUT"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["CONTROL_OUTPUT"].size = std::bind(&canlib_circular_buffer<secondary_message_CONTROL_OUTPUT, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.CONTROL_OUTPUT);
    mapping_map["CONTROL_OUTPUT"].offset = std::bind(&canlib_circular_buffer<secondary_message_CONTROL_OUTPUT, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.CONTROL_OUTPUT);
    mapping_map["CONTROL_OUTPUT"].stride = sizeof(secondary_message_CONTROL_OUTPUT);
    mapping_map["CONTROL_OUTPUT"].field["right"].value._float32 = &pack.CONTROL_OUTPUT.start().right;
    mapping_map["CONTROL_OUTPUT"].field["right"].type = mapping_type_float32;
    mapping_map["CONTROL_OUTPUT"].field["left"].value._float32 = &pack.CONTROL_OUTPUT.start().left;
    mapping_map["CONTROL_OUTPUT"].field["left"].type = mapping_type_float32;
#ifdef CANLIB_TIMESTAMP
    mapping_map["CONTROL_OUTPUT"].field["_timestamp"].value._uint64 = &pack.CONTROL_OUTPUT.start()._timestamp;
    mapping_map["CONTROL_OUTPUT"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP
    mapping_map["STEERING_ANGLE"].size = std::bind(&canlib_circular_buffer<secondary_message_STEERING_ANGLE, CANLIB_CIRCULAR_BUFFER_SIZE>::size, &pack.STEERING_ANGLE);
    mapping_map["STEERING_ANGLE"].offset = std::bind(&canlib_circular_buffer<secondary_message_STEERING_ANGLE, CANLIB_CIRCULAR_BUFFER_SIZE>::offset, &pack.STEERING_ANGLE);
    mapping_map["STEERING_ANGLE"].stride = sizeof(secondary_message_STEERING_ANGLE);
    mapping_map["STEERING_ANGLE"].field["angle"].value._float32 = &pack.STEERING_ANGLE.start().angle;
    mapping_map["STEERING_ANGLE"].field["angle"].type = mapping_type_float32;
#ifdef CANLIB_TIMESTAMP
    mapping_map["STEERING_ANGLE"].field["_timestamp"].value._uint64 = &pack.STEERING_ANGLE.start()._timestamp;
    mapping_map["STEERING_ANGLE"].field["_timestamp"].type = mapping_type_uint64;
#endif // CANLIB_TIMESTAMP 
}

void secondary_proto_serialize_from_id(canlib_message_id id, secondary::Pack* pack, secondary_devices* map) {
    int index = secondary_index_from_id(id);

    if (index == -1) return;

    switch(id) {
        case 1260: {
            secondary_message_IMU_ANGULAR_RATE_conversion* msg = (secondary_message_IMU_ANGULAR_RATE_conversion*) (*map)[index].message_conversion;
            secondary::IMU_ANGULAR_RATE* proto_msg = pack->add_imu_angular_rate();
            proto_msg->set_ang_rate_x(msg->ang_rate_x);
            proto_msg->set_ang_rate_y(msg->ang_rate_y);
            proto_msg->set_ang_rate_z(msg->ang_rate_z);
            proto_msg->set_temperature(msg->temperature);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1261: {
            secondary_message_IMU_ACCELERATION_conversion* msg = (secondary_message_IMU_ACCELERATION_conversion*) (*map)[index].message_conversion;
            secondary::IMU_ACCELERATION* proto_msg = pack->add_imu_acceleration();
            proto_msg->set_accel_x(msg->accel_x);
            proto_msg->set_accel_y(msg->accel_y);
            proto_msg->set_accel_z(msg->accel_z);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1460: {
            secondary_message_IRTS_FL_0* msg = (secondary_message_IRTS_FL_0*) (*map)[index].message_raw;
            secondary::IRTS_FL_0* proto_msg = pack->add_irts_fl_0();
            proto_msg->set_channel1(msg->channel1);
            proto_msg->set_channel2(msg->channel2);
            proto_msg->set_channel3(msg->channel3);
            proto_msg->set_channel4(msg->channel4);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1461: {
            secondary_message_IRTS_FL_1* msg = (secondary_message_IRTS_FL_1*) (*map)[index].message_raw;
            secondary::IRTS_FL_1* proto_msg = pack->add_irts_fl_1();
            proto_msg->set_channel5(msg->channel5);
            proto_msg->set_channel6(msg->channel6);
            proto_msg->set_channel7(msg->channel7);
            proto_msg->set_channel8(msg->channel8);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1462: {
            secondary_message_IRTS_FL_2* msg = (secondary_message_IRTS_FL_2*) (*map)[index].message_raw;
            secondary::IRTS_FL_2* proto_msg = pack->add_irts_fl_2();
            proto_msg->set_channel9(msg->channel9);
            proto_msg->set_channel10(msg->channel10);
            proto_msg->set_channel11(msg->channel11);
            proto_msg->set_channel12(msg->channel12);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1463: {
            secondary_message_IRTS_FL_3* msg = (secondary_message_IRTS_FL_3*) (*map)[index].message_raw;
            secondary::IRTS_FL_3* proto_msg = pack->add_irts_fl_3();
            proto_msg->set_channel13(msg->channel13);
            proto_msg->set_channel14(msg->channel14);
            proto_msg->set_channel15(msg->channel15);
            proto_msg->set_channel16(msg->channel16);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1464: {
            secondary_message_IRTS_FR_0* msg = (secondary_message_IRTS_FR_0*) (*map)[index].message_raw;
            secondary::IRTS_FR_0* proto_msg = pack->add_irts_fr_0();
            proto_msg->set_channel1(msg->channel1);
            proto_msg->set_channel2(msg->channel2);
            proto_msg->set_channel3(msg->channel3);
            proto_msg->set_channel4(msg->channel4);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1465: {
            secondary_message_IRTS_FR_1* msg = (secondary_message_IRTS_FR_1*) (*map)[index].message_raw;
            secondary::IRTS_FR_1* proto_msg = pack->add_irts_fr_1();
            proto_msg->set_channel5(msg->channel5);
            proto_msg->set_channel6(msg->channel6);
            proto_msg->set_channel7(msg->channel7);
            proto_msg->set_channel8(msg->channel8);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1466: {
            secondary_message_IRTS_FR_2* msg = (secondary_message_IRTS_FR_2*) (*map)[index].message_raw;
            secondary::IRTS_FR_2* proto_msg = pack->add_irts_fr_2();
            proto_msg->set_channel9(msg->channel9);
            proto_msg->set_channel10(msg->channel10);
            proto_msg->set_channel11(msg->channel11);
            proto_msg->set_channel12(msg->channel12);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1467: {
            secondary_message_IRTS_FR_3* msg = (secondary_message_IRTS_FR_3*) (*map)[index].message_raw;
            secondary::IRTS_FR_3* proto_msg = pack->add_irts_fr_3();
            proto_msg->set_channel13(msg->channel13);
            proto_msg->set_channel14(msg->channel14);
            proto_msg->set_channel15(msg->channel15);
            proto_msg->set_channel16(msg->channel16);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1468: {
            secondary_message_IRTS_RL_0* msg = (secondary_message_IRTS_RL_0*) (*map)[index].message_raw;
            secondary::IRTS_RL_0* proto_msg = pack->add_irts_rl_0();
            proto_msg->set_channel1(msg->channel1);
            proto_msg->set_channel2(msg->channel2);
            proto_msg->set_channel3(msg->channel3);
            proto_msg->set_channel4(msg->channel4);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1469: {
            secondary_message_IRTS_RL_1* msg = (secondary_message_IRTS_RL_1*) (*map)[index].message_raw;
            secondary::IRTS_RL_1* proto_msg = pack->add_irts_rl_1();
            proto_msg->set_channel5(msg->channel5);
            proto_msg->set_channel6(msg->channel6);
            proto_msg->set_channel7(msg->channel7);
            proto_msg->set_channel8(msg->channel8);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1470: {
            secondary_message_IRTS_RL_2* msg = (secondary_message_IRTS_RL_2*) (*map)[index].message_raw;
            secondary::IRTS_RL_2* proto_msg = pack->add_irts_rl_2();
            proto_msg->set_channel9(msg->channel9);
            proto_msg->set_channel10(msg->channel10);
            proto_msg->set_channel11(msg->channel11);
            proto_msg->set_channel12(msg->channel12);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1471: {
            secondary_message_IRTS_RL_3* msg = (secondary_message_IRTS_RL_3*) (*map)[index].message_raw;
            secondary::IRTS_RL_3* proto_msg = pack->add_irts_rl_3();
            proto_msg->set_channel13(msg->channel13);
            proto_msg->set_channel14(msg->channel14);
            proto_msg->set_channel15(msg->channel15);
            proto_msg->set_channel16(msg->channel16);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1472: {
            secondary_message_IRTS_RR_0* msg = (secondary_message_IRTS_RR_0*) (*map)[index].message_raw;
            secondary::IRTS_RR_0* proto_msg = pack->add_irts_rr_0();
            proto_msg->set_channel1(msg->channel1);
            proto_msg->set_channel2(msg->channel2);
            proto_msg->set_channel3(msg->channel3);
            proto_msg->set_channel4(msg->channel4);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1473: {
            secondary_message_IRTS_RR_1* msg = (secondary_message_IRTS_RR_1*) (*map)[index].message_raw;
            secondary::IRTS_RR_1* proto_msg = pack->add_irts_rr_1();
            proto_msg->set_channel5(msg->channel5);
            proto_msg->set_channel6(msg->channel6);
            proto_msg->set_channel7(msg->channel7);
            proto_msg->set_channel8(msg->channel8);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1474: {
            secondary_message_IRTS_RR_2* msg = (secondary_message_IRTS_RR_2*) (*map)[index].message_raw;
            secondary::IRTS_RR_2* proto_msg = pack->add_irts_rr_2();
            proto_msg->set_channel9(msg->channel9);
            proto_msg->set_channel10(msg->channel10);
            proto_msg->set_channel11(msg->channel11);
            proto_msg->set_channel12(msg->channel12);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1475: {
            secondary_message_IRTS_RR_3* msg = (secondary_message_IRTS_RR_3*) (*map)[index].message_raw;
            secondary::IRTS_RR_3* proto_msg = pack->add_irts_rr_3();
            proto_msg->set_channel13(msg->channel13);
            proto_msg->set_channel14(msg->channel14);
            proto_msg->set_channel15(msg->channel15);
            proto_msg->set_channel16(msg->channel16);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1025: {
            secondary_message_GPS_COORDS* msg = (secondary_message_GPS_COORDS*) (*map)[index].message_raw;
            secondary::GPS_COORDS* proto_msg = pack->add_gps_coords();
            proto_msg->set_latitude(msg->latitude);
            proto_msg->set_longitude(msg->longitude);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1057: {
            secondary_message_GPS_SPEED* msg = (secondary_message_GPS_SPEED*) (*map)[index].message_raw;
            secondary::GPS_SPEED* proto_msg = pack->add_gps_speed();
            proto_msg->set_speed(msg->speed);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1089: {
            secondary_message_LAP_COUNT* msg = (secondary_message_LAP_COUNT*) (*map)[index].message_raw;
            secondary::LAP_COUNT* proto_msg = pack->add_lap_count();
            proto_msg->set_lap_count(msg->lap_count);
            proto_msg->set_lap_time(msg->lap_time);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 769: {
            secondary_message_PEDALS_OUTPUT_conversion* msg = (secondary_message_PEDALS_OUTPUT_conversion*) (*map)[index].message_conversion;
            secondary::PEDALS_OUTPUT* proto_msg = pack->add_pedals_output();
            proto_msg->set_apps(msg->apps);
            proto_msg->set_bse_front(msg->bse_front);
            proto_msg->set_bse_rear(msg->bse_rear);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 801: {
            secondary_message_CONTROL_OUTPUT* msg = (secondary_message_CONTROL_OUTPUT*) (*map)[index].message_raw;
            secondary::CONTROL_OUTPUT* proto_msg = pack->add_control_output();
            proto_msg->set_right(msg->right);
            proto_msg->set_left(msg->left);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 258: {
            secondary_message_STEERING_ANGLE* msg = (secondary_message_STEERING_ANGLE*) (*map)[index].message_raw;
            secondary::STEERING_ANGLE* proto_msg = pack->add_steering_angle();
            proto_msg->set_angle(msg->angle);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

    }
}

void secondary_proto_deserialize(secondary::Pack* pack, secondary_proto_pack* map, uint64_t resample_us) {
    for(int i = 0; i < pack->imu_angular_rate_size(); i++){
        static secondary_message_IMU_ANGULAR_RATE_conversion instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->imu_angular_rate(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.ang_rate_x =pack->imu_angular_rate(i).ang_rate_x();
        instance.ang_rate_y =pack->imu_angular_rate(i).ang_rate_y();
        instance.ang_rate_z =pack->imu_angular_rate(i).ang_rate_z();
        instance.temperature =pack->imu_angular_rate(i).temperature();
        map->IMU_ANGULAR_RATE.push(instance);
    }
    for(int i = 0; i < pack->imu_acceleration_size(); i++){
        static secondary_message_IMU_ACCELERATION_conversion instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->imu_acceleration(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.accel_x =pack->imu_acceleration(i).accel_x();
        instance.accel_y =pack->imu_acceleration(i).accel_y();
        instance.accel_z =pack->imu_acceleration(i).accel_z();
        map->IMU_ACCELERATION.push(instance);
    }
    for(int i = 0; i < pack->irts_fl_0_size(); i++){
        static secondary_message_IRTS_FL_0 instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->irts_fl_0(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.channel1 =pack->irts_fl_0(i).channel1();
        instance.channel2 =pack->irts_fl_0(i).channel2();
        instance.channel3 =pack->irts_fl_0(i).channel3();
        instance.channel4 =pack->irts_fl_0(i).channel4();
        map->IRTS_FL_0.push(instance);
    }
    for(int i = 0; i < pack->irts_fl_1_size(); i++){
        static secondary_message_IRTS_FL_1 instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->irts_fl_1(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.channel5 =pack->irts_fl_1(i).channel5();
        instance.channel6 =pack->irts_fl_1(i).channel6();
        instance.channel7 =pack->irts_fl_1(i).channel7();
        instance.channel8 =pack->irts_fl_1(i).channel8();
        map->IRTS_FL_1.push(instance);
    }
    for(int i = 0; i < pack->irts_fl_2_size(); i++){
        static secondary_message_IRTS_FL_2 instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->irts_fl_2(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.channel9 =pack->irts_fl_2(i).channel9();
        instance.channel10 =pack->irts_fl_2(i).channel10();
        instance.channel11 =pack->irts_fl_2(i).channel11();
        instance.channel12 =pack->irts_fl_2(i).channel12();
        map->IRTS_FL_2.push(instance);
    }
    for(int i = 0; i < pack->irts_fl_3_size(); i++){
        static secondary_message_IRTS_FL_3 instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->irts_fl_3(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.channel13 =pack->irts_fl_3(i).channel13();
        instance.channel14 =pack->irts_fl_3(i).channel14();
        instance.channel15 =pack->irts_fl_3(i).channel15();
        instance.channel16 =pack->irts_fl_3(i).channel16();
        map->IRTS_FL_3.push(instance);
    }
    for(int i = 0; i < pack->irts_fr_0_size(); i++){
        static secondary_message_IRTS_FR_0 instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->irts_fr_0(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.channel1 =pack->irts_fr_0(i).channel1();
        instance.channel2 =pack->irts_fr_0(i).channel2();
        instance.channel3 =pack->irts_fr_0(i).channel3();
        instance.channel4 =pack->irts_fr_0(i).channel4();
        map->IRTS_FR_0.push(instance);
    }
    for(int i = 0; i < pack->irts_fr_1_size(); i++){
        static secondary_message_IRTS_FR_1 instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->irts_fr_1(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.channel5 =pack->irts_fr_1(i).channel5();
        instance.channel6 =pack->irts_fr_1(i).channel6();
        instance.channel7 =pack->irts_fr_1(i).channel7();
        instance.channel8 =pack->irts_fr_1(i).channel8();
        map->IRTS_FR_1.push(instance);
    }
    for(int i = 0; i < pack->irts_fr_2_size(); i++){
        static secondary_message_IRTS_FR_2 instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->irts_fr_2(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.channel9 =pack->irts_fr_2(i).channel9();
        instance.channel10 =pack->irts_fr_2(i).channel10();
        instance.channel11 =pack->irts_fr_2(i).channel11();
        instance.channel12 =pack->irts_fr_2(i).channel12();
        map->IRTS_FR_2.push(instance);
    }
    for(int i = 0; i < pack->irts_fr_3_size(); i++){
        static secondary_message_IRTS_FR_3 instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->irts_fr_3(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.channel13 =pack->irts_fr_3(i).channel13();
        instance.channel14 =pack->irts_fr_3(i).channel14();
        instance.channel15 =pack->irts_fr_3(i).channel15();
        instance.channel16 =pack->irts_fr_3(i).channel16();
        map->IRTS_FR_3.push(instance);
    }
    for(int i = 0; i < pack->irts_rl_0_size(); i++){
        static secondary_message_IRTS_RL_0 instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->irts_rl_0(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.channel1 =pack->irts_rl_0(i).channel1();
        instance.channel2 =pack->irts_rl_0(i).channel2();
        instance.channel3 =pack->irts_rl_0(i).channel3();
        instance.channel4 =pack->irts_rl_0(i).channel4();
        map->IRTS_RL_0.push(instance);
    }
    for(int i = 0; i < pack->irts_rl_1_size(); i++){
        static secondary_message_IRTS_RL_1 instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->irts_rl_1(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.channel5 =pack->irts_rl_1(i).channel5();
        instance.channel6 =pack->irts_rl_1(i).channel6();
        instance.channel7 =pack->irts_rl_1(i).channel7();
        instance.channel8 =pack->irts_rl_1(i).channel8();
        map->IRTS_RL_1.push(instance);
    }
    for(int i = 0; i < pack->irts_rl_2_size(); i++){
        static secondary_message_IRTS_RL_2 instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->irts_rl_2(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.channel9 =pack->irts_rl_2(i).channel9();
        instance.channel10 =pack->irts_rl_2(i).channel10();
        instance.channel11 =pack->irts_rl_2(i).channel11();
        instance.channel12 =pack->irts_rl_2(i).channel12();
        map->IRTS_RL_2.push(instance);
    }
    for(int i = 0; i < pack->irts_rl_3_size(); i++){
        static secondary_message_IRTS_RL_3 instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->irts_rl_3(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.channel13 =pack->irts_rl_3(i).channel13();
        instance.channel14 =pack->irts_rl_3(i).channel14();
        instance.channel15 =pack->irts_rl_3(i).channel15();
        instance.channel16 =pack->irts_rl_3(i).channel16();
        map->IRTS_RL_3.push(instance);
    }
    for(int i = 0; i < pack->irts_rr_0_size(); i++){
        static secondary_message_IRTS_RR_0 instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->irts_rr_0(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.channel1 =pack->irts_rr_0(i).channel1();
        instance.channel2 =pack->irts_rr_0(i).channel2();
        instance.channel3 =pack->irts_rr_0(i).channel3();
        instance.channel4 =pack->irts_rr_0(i).channel4();
        map->IRTS_RR_0.push(instance);
    }
    for(int i = 0; i < pack->irts_rr_1_size(); i++){
        static secondary_message_IRTS_RR_1 instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->irts_rr_1(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.channel5 =pack->irts_rr_1(i).channel5();
        instance.channel6 =pack->irts_rr_1(i).channel6();
        instance.channel7 =pack->irts_rr_1(i).channel7();
        instance.channel8 =pack->irts_rr_1(i).channel8();
        map->IRTS_RR_1.push(instance);
    }
    for(int i = 0; i < pack->irts_rr_2_size(); i++){
        static secondary_message_IRTS_RR_2 instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->irts_rr_2(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.channel9 =pack->irts_rr_2(i).channel9();
        instance.channel10 =pack->irts_rr_2(i).channel10();
        instance.channel11 =pack->irts_rr_2(i).channel11();
        instance.channel12 =pack->irts_rr_2(i).channel12();
        map->IRTS_RR_2.push(instance);
    }
    for(int i = 0; i < pack->irts_rr_3_size(); i++){
        static secondary_message_IRTS_RR_3 instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->irts_rr_3(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.channel13 =pack->irts_rr_3(i).channel13();
        instance.channel14 =pack->irts_rr_3(i).channel14();
        instance.channel15 =pack->irts_rr_3(i).channel15();
        instance.channel16 =pack->irts_rr_3(i).channel16();
        map->IRTS_RR_3.push(instance);
    }
    for(int i = 0; i < pack->gps_coords_size(); i++){
        static secondary_message_GPS_COORDS instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->gps_coords(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.latitude =pack->gps_coords(i).latitude();
        instance.longitude =pack->gps_coords(i).longitude();
        map->GPS_COORDS.push(instance);
    }
    for(int i = 0; i < pack->gps_speed_size(); i++){
        static secondary_message_GPS_SPEED instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->gps_speed(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.speed =pack->gps_speed(i).speed();
        map->GPS_SPEED.push(instance);
    }
    for(int i = 0; i < pack->lap_count_size(); i++){
        static secondary_message_LAP_COUNT instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->lap_count(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.lap_count =pack->lap_count(i).lap_count();
        instance.lap_time =pack->lap_count(i).lap_time();
        map->LAP_COUNT.push(instance);
    }
    for(int i = 0; i < pack->pedals_output_size(); i++){
        static secondary_message_PEDALS_OUTPUT_conversion instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->pedals_output(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.apps =pack->pedals_output(i).apps();
        instance.bse_front =pack->pedals_output(i).bse_front();
        instance.bse_rear =pack->pedals_output(i).bse_rear();
        map->PEDALS_OUTPUT.push(instance);
    }
    for(int i = 0; i < pack->control_output_size(); i++){
        static secondary_message_CONTROL_OUTPUT instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->control_output(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.right =pack->control_output(i).right();
        instance.left =pack->control_output(i).left();
        map->CONTROL_OUTPUT.push(instance);
    }
    for(int i = 0; i < pack->steering_angle_size(); i++){
        static secondary_message_STEERING_ANGLE instance;
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        instance._timestamp = pack->steering_angle(i)._inner_timestamp();
        if(instance._timestamp - last_timestamp < resample_us)
            continue;
        else
            last_timestamp = instance._timestamp;
#endif // CANLIB_TIMESTAMP
        instance.angle =pack->steering_angle(i).angle();
        map->STEERING_ANGLE.push(instance);
    }
}

#endif // secondary_MAPPING_IMPLEMENTATION

#endif // secondary_MAPPING_H