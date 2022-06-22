#ifndef secondary_MAPPING_H
#define secondary_MAPPING_H

#include <string>
#include <vector>

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
    canlib_circular_buffer<secondary_message_IMU_ANGULAR_RATE, CANLIB_CIRCULAR_BUFFER_SIZE> IMU_ANGULAR_RATE;
    canlib_circular_buffer<secondary_message_IMU_ACCELERATION, CANLIB_CIRCULAR_BUFFER_SIZE> IMU_ACCELERATION;
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

void secondary_proto_serialize_from_id(canlib_message_id id, secondary::Pack* pack, secondary_devices* map);
void secondary_proto_deserialize(secondary::Pack* pack, secondary_proto_pack* map);

#ifdef secondary_MAPPING_IMPLEMENTATION

void secondary_proto_serialize_from_id(canlib_message_id id, secondary::Pack* pack, secondary_devices* map) {
    int index = secondary_index_from_id(id);

    if (index == -1) return;

    switch(id) {
        case 1260: {
            secondary_message_IMU_ANGULAR_RATE* msg = (secondary_message_IMU_ANGULAR_RATE*) (*map)[index].message_raw;
            secondary::IMU_ANGULAR_RATE* proto_msg = pack->add_imu_angular_rate();
            proto_msg->set_ang_rate_x(msg->ang_rate_x);
            proto_msg->set_ang_rate_y(msg->ang_rate_y);
            proto_msg->set_ang_rate_z(msg->ang_rate_z);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1261: {
            secondary_message_IMU_ACCELERATION* msg = (secondary_message_IMU_ACCELERATION*) (*map)[index].message_raw;
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
            proto_msg->set_timestamp(msg->timestamp);
            proto_msg->set_lap_count(msg->lap_count);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 769: {
            secondary_message_PEDALS_OUTPUT_conversion* msg = (secondary_message_PEDALS_OUTPUT_conversion*) (*map)[index].message_conversion;
            secondary::PEDALS_OUTPUT* proto_msg = pack->add_pedals_output();
            proto_msg->set_bse_front(msg->bse_front);
            proto_msg->set_bse_rear(msg->bse_rear);
            proto_msg->set_apps(msg->apps);
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

void secondary_proto_deserialize(secondary::Pack* pack, secondary_proto_pack* map) {
    for(int i = 0; i < pack->imu_angular_rate_size(); i++){
        static secondary_message_IMU_ANGULAR_RATE instance;
        instance.ang_rate_x =pack->imu_angular_rate(i).ang_rate_x();
        instance.ang_rate_y =pack->imu_angular_rate(i).ang_rate_y();
        instance.ang_rate_z =pack->imu_angular_rate(i).ang_rate_z();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->imu_angular_rate(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->IMU_ANGULAR_RATE.push(instance);
    }
    for(int i = 0; i < pack->imu_acceleration_size(); i++){
        static secondary_message_IMU_ACCELERATION instance;
        instance.accel_x =pack->imu_acceleration(i).accel_x();
        instance.accel_y =pack->imu_acceleration(i).accel_y();
        instance.accel_z =pack->imu_acceleration(i).accel_z();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->imu_acceleration(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->IMU_ACCELERATION.push(instance);
    }
    for(int i = 0; i < pack->irts_fl_0_size(); i++){
        static secondary_message_IRTS_FL_0 instance;
        instance.channel1 =pack->irts_fl_0(i).channel1();
        instance.channel2 =pack->irts_fl_0(i).channel2();
        instance.channel3 =pack->irts_fl_0(i).channel3();
        instance.channel4 =pack->irts_fl_0(i).channel4();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->irts_fl_0(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->IRTS_FL_0.push(instance);
    }
    for(int i = 0; i < pack->irts_fl_1_size(); i++){
        static secondary_message_IRTS_FL_1 instance;
        instance.channel5 =pack->irts_fl_1(i).channel5();
        instance.channel6 =pack->irts_fl_1(i).channel6();
        instance.channel7 =pack->irts_fl_1(i).channel7();
        instance.channel8 =pack->irts_fl_1(i).channel8();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->irts_fl_1(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->IRTS_FL_1.push(instance);
    }
    for(int i = 0; i < pack->irts_fl_2_size(); i++){
        static secondary_message_IRTS_FL_2 instance;
        instance.channel9 =pack->irts_fl_2(i).channel9();
        instance.channel10 =pack->irts_fl_2(i).channel10();
        instance.channel11 =pack->irts_fl_2(i).channel11();
        instance.channel12 =pack->irts_fl_2(i).channel12();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->irts_fl_2(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->IRTS_FL_2.push(instance);
    }
    for(int i = 0; i < pack->irts_fl_3_size(); i++){
        static secondary_message_IRTS_FL_3 instance;
        instance.channel13 =pack->irts_fl_3(i).channel13();
        instance.channel14 =pack->irts_fl_3(i).channel14();
        instance.channel15 =pack->irts_fl_3(i).channel15();
        instance.channel16 =pack->irts_fl_3(i).channel16();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->irts_fl_3(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->IRTS_FL_3.push(instance);
    }
    for(int i = 0; i < pack->irts_fr_0_size(); i++){
        static secondary_message_IRTS_FR_0 instance;
        instance.channel1 =pack->irts_fr_0(i).channel1();
        instance.channel2 =pack->irts_fr_0(i).channel2();
        instance.channel3 =pack->irts_fr_0(i).channel3();
        instance.channel4 =pack->irts_fr_0(i).channel4();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->irts_fr_0(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->IRTS_FR_0.push(instance);
    }
    for(int i = 0; i < pack->irts_fr_1_size(); i++){
        static secondary_message_IRTS_FR_1 instance;
        instance.channel5 =pack->irts_fr_1(i).channel5();
        instance.channel6 =pack->irts_fr_1(i).channel6();
        instance.channel7 =pack->irts_fr_1(i).channel7();
        instance.channel8 =pack->irts_fr_1(i).channel8();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->irts_fr_1(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->IRTS_FR_1.push(instance);
    }
    for(int i = 0; i < pack->irts_fr_2_size(); i++){
        static secondary_message_IRTS_FR_2 instance;
        instance.channel9 =pack->irts_fr_2(i).channel9();
        instance.channel10 =pack->irts_fr_2(i).channel10();
        instance.channel11 =pack->irts_fr_2(i).channel11();
        instance.channel12 =pack->irts_fr_2(i).channel12();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->irts_fr_2(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->IRTS_FR_2.push(instance);
    }
    for(int i = 0; i < pack->irts_fr_3_size(); i++){
        static secondary_message_IRTS_FR_3 instance;
        instance.channel13 =pack->irts_fr_3(i).channel13();
        instance.channel14 =pack->irts_fr_3(i).channel14();
        instance.channel15 =pack->irts_fr_3(i).channel15();
        instance.channel16 =pack->irts_fr_3(i).channel16();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->irts_fr_3(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->IRTS_FR_3.push(instance);
    }
    for(int i = 0; i < pack->irts_rl_0_size(); i++){
        static secondary_message_IRTS_RL_0 instance;
        instance.channel1 =pack->irts_rl_0(i).channel1();
        instance.channel2 =pack->irts_rl_0(i).channel2();
        instance.channel3 =pack->irts_rl_0(i).channel3();
        instance.channel4 =pack->irts_rl_0(i).channel4();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->irts_rl_0(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->IRTS_RL_0.push(instance);
    }
    for(int i = 0; i < pack->irts_rl_1_size(); i++){
        static secondary_message_IRTS_RL_1 instance;
        instance.channel5 =pack->irts_rl_1(i).channel5();
        instance.channel6 =pack->irts_rl_1(i).channel6();
        instance.channel7 =pack->irts_rl_1(i).channel7();
        instance.channel8 =pack->irts_rl_1(i).channel8();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->irts_rl_1(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->IRTS_RL_1.push(instance);
    }
    for(int i = 0; i < pack->irts_rl_2_size(); i++){
        static secondary_message_IRTS_RL_2 instance;
        instance.channel9 =pack->irts_rl_2(i).channel9();
        instance.channel10 =pack->irts_rl_2(i).channel10();
        instance.channel11 =pack->irts_rl_2(i).channel11();
        instance.channel12 =pack->irts_rl_2(i).channel12();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->irts_rl_2(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->IRTS_RL_2.push(instance);
    }
    for(int i = 0; i < pack->irts_rl_3_size(); i++){
        static secondary_message_IRTS_RL_3 instance;
        instance.channel13 =pack->irts_rl_3(i).channel13();
        instance.channel14 =pack->irts_rl_3(i).channel14();
        instance.channel15 =pack->irts_rl_3(i).channel15();
        instance.channel16 =pack->irts_rl_3(i).channel16();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->irts_rl_3(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->IRTS_RL_3.push(instance);
    }
    for(int i = 0; i < pack->irts_rr_0_size(); i++){
        static secondary_message_IRTS_RR_0 instance;
        instance.channel1 =pack->irts_rr_0(i).channel1();
        instance.channel2 =pack->irts_rr_0(i).channel2();
        instance.channel3 =pack->irts_rr_0(i).channel3();
        instance.channel4 =pack->irts_rr_0(i).channel4();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->irts_rr_0(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->IRTS_RR_0.push(instance);
    }
    for(int i = 0; i < pack->irts_rr_1_size(); i++){
        static secondary_message_IRTS_RR_1 instance;
        instance.channel5 =pack->irts_rr_1(i).channel5();
        instance.channel6 =pack->irts_rr_1(i).channel6();
        instance.channel7 =pack->irts_rr_1(i).channel7();
        instance.channel8 =pack->irts_rr_1(i).channel8();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->irts_rr_1(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->IRTS_RR_1.push(instance);
    }
    for(int i = 0; i < pack->irts_rr_2_size(); i++){
        static secondary_message_IRTS_RR_2 instance;
        instance.channel9 =pack->irts_rr_2(i).channel9();
        instance.channel10 =pack->irts_rr_2(i).channel10();
        instance.channel11 =pack->irts_rr_2(i).channel11();
        instance.channel12 =pack->irts_rr_2(i).channel12();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->irts_rr_2(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->IRTS_RR_2.push(instance);
    }
    for(int i = 0; i < pack->irts_rr_3_size(); i++){
        static secondary_message_IRTS_RR_3 instance;
        instance.channel13 =pack->irts_rr_3(i).channel13();
        instance.channel14 =pack->irts_rr_3(i).channel14();
        instance.channel15 =pack->irts_rr_3(i).channel15();
        instance.channel16 =pack->irts_rr_3(i).channel16();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->irts_rr_3(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->IRTS_RR_3.push(instance);
    }
    for(int i = 0; i < pack->gps_coords_size(); i++){
        static secondary_message_GPS_COORDS instance;
        instance.latitude =pack->gps_coords(i).latitude();
        instance.longitude =pack->gps_coords(i).longitude();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->gps_coords(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->GPS_COORDS.push(instance);
    }
    for(int i = 0; i < pack->gps_speed_size(); i++){
        static secondary_message_GPS_SPEED instance;
        instance.speed =pack->gps_speed(i).speed();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->gps_speed(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->GPS_SPEED.push(instance);
    }
    for(int i = 0; i < pack->lap_count_size(); i++){
        static secondary_message_LAP_COUNT instance;
        instance.timestamp =pack->lap_count(i).timestamp();
        instance.lap_count =pack->lap_count(i).lap_count();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->lap_count(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->LAP_COUNT.push(instance);
    }
    for(int i = 0; i < pack->pedals_output_size(); i++){
        static secondary_message_PEDALS_OUTPUT_conversion instance;
        instance.bse_front =pack->pedals_output(i).bse_front();
        instance.bse_rear =pack->pedals_output(i).bse_rear();
        instance.apps =pack->pedals_output(i).apps();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->pedals_output(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->PEDALS_OUTPUT.push(instance);
    }
    for(int i = 0; i < pack->control_output_size(); i++){
        static secondary_message_CONTROL_OUTPUT instance;
        instance.right =pack->control_output(i).right();
        instance.left =pack->control_output(i).left();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->control_output(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->CONTROL_OUTPUT.push(instance);
    }
    for(int i = 0; i < pack->steering_angle_size(); i++){
        static secondary_message_STEERING_ANGLE instance;
        instance.angle =pack->steering_angle(i).angle();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->steering_angle(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->STEERING_ANGLE.push(instance);
    }
}

#endif // secondary_MAPPING_IMPLEMENTATION

#endif // secondary_MAPPING_H