
#ifndef simulator_PROTO_INTERFACE_H
#define simulator_PROTO_INTERFACE_H

#include <string>
#include <unordered_map>
#include <functional>

#include "simulator.pb.h"

#ifdef simulator_IMPLEMENTATION
#undef simulator_IMPLEMENTATION
#define __simulator_IMPLEMENTATION
#endif

#include "../../lib/simulator/simulator_network.h"

#ifdef __simulator_IMPLEMENTATION
#undef __simulator_IMPLEMENTATION
#define simulator_IMPLEMENTATION
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
  T& operator[](IT index);
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
T& canlib_circular_buffer<T, S, IT>::operator[](IT index) {
  if (index >= count) return *tail;
  return *(buffer + ((head - buffer + index) % capacity));
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

void simulator_proto_interface_serialize_from_id(canlib_message_id id, simulator::Pack* pack, device_t* device);
void simulator_proto_interface_deserialize(simulator::Pack* pack, network_enums* net_enums, network_signals* net_signals, network_strings* net_strings, uint64_t resample_us);

#ifdef simulator_PROTO_INTERAFCE_IMPLEMENTATION

void simulator_proto_interface_deserialize(simulator::Pack* pack, network_enums* net_enums, network_signals* net_signals, network_strings* net_strings, uint64_t resample_us) {
    char buffer[1024];
    
    for(int i = 0; i < pack->imu_angular_rate_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->imu_angular_rate(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->imu_angular_rate(i)._inner_timestamp();
        (*net_signals)["IMU_ANGULAR_RATE"]["_timestamp"].push(pack->imu_angular_rate(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["IMU_ANGULAR_RATE"]["x"].push(pack->imu_angular_rate(i).x());
		(*net_signals)["IMU_ANGULAR_RATE"]["y"].push(pack->imu_angular_rate(i).y());
		(*net_signals)["IMU_ANGULAR_RATE"]["z"].push(pack->imu_angular_rate(i).z());

    }

    for(int i = 0; i < pack->imu_acceleration_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->imu_acceleration(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->imu_acceleration(i)._inner_timestamp();
        (*net_signals)["IMU_ACCELERATION"]["_timestamp"].push(pack->imu_acceleration(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["IMU_ACCELERATION"]["x"].push(pack->imu_acceleration(i).x());
		(*net_signals)["IMU_ACCELERATION"]["y"].push(pack->imu_acceleration(i).y());
		(*net_signals)["IMU_ACCELERATION"]["z"].push(pack->imu_acceleration(i).z());
		(*net_signals)["IMU_ACCELERATION"]["imu_temperature"].push(pack->imu_acceleration(i).imu_temperature());

    }

    for(int i = 0; i < pack->pedal_throttle_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->pedal_throttle(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->pedal_throttle(i)._inner_timestamp();
        (*net_signals)["PEDAL_THROTTLE"]["_timestamp"].push(pack->pedal_throttle(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["PEDAL_THROTTLE"]["throttle"].push(pack->pedal_throttle(i).throttle());

    }

    for(int i = 0; i < pack->pedal_brakes_pressure_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->pedal_brakes_pressure(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->pedal_brakes_pressure(i)._inner_timestamp();
        (*net_signals)["PEDAL_BRAKES_PRESSURE"]["_timestamp"].push(pack->pedal_brakes_pressure(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["PEDAL_BRAKES_PRESSURE"]["front"].push(pack->pedal_brakes_pressure(i).front());
		(*net_signals)["PEDAL_BRAKES_PRESSURE"]["rear"].push(pack->pedal_brakes_pressure(i).rear());

    }

    for(int i = 0; i < pack->steer_angle_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->steer_angle(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->steer_angle(i)._inner_timestamp();
        (*net_signals)["STEER_ANGLE"]["_timestamp"].push(pack->steer_angle(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["STEER_ANGLE"]["angle"].push(pack->steer_angle(i).angle());

    }

    for(int i = 0; i < pack->control_output_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->control_output(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->control_output(i)._inner_timestamp();
        (*net_signals)["CONTROL_OUTPUT"]["_timestamp"].push(pack->control_output(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["CONTROL_OUTPUT"]["estimated_velocity"].push(pack->control_output(i).estimated_velocity());
		(*net_signals)["CONTROL_OUTPUT"]["torque_max_l"].push(pack->control_output(i).torque_max_l());
		(*net_signals)["CONTROL_OUTPUT"]["torque_max_r"].push(pack->control_output(i).torque_max_r());
		(*net_signals)["CONTROL_OUTPUT"]["torque_l"].push(pack->control_output(i).torque_l());
		(*net_signals)["CONTROL_OUTPUT"]["torque_r"].push(pack->control_output(i).torque_r());

    }

    for(int i = 0; i < pack->control_status_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->control_status(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->control_status(i)._inner_timestamp();
        (*net_signals)["CONTROL_STATUS"]["_timestamp"].push(pack->control_status(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["CONTROL_STATUS"]["map_pw"].push(pack->control_status(i).map_pw());
		(*net_signals)["CONTROL_STATUS"]["map_sc"].push(pack->control_status(i).map_sc());
		(*net_signals)["CONTROL_STATUS"]["map_tv"].push(pack->control_status(i).map_tv());

    }

    for(int i = 0; i < pack->speed_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->speed(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->speed(i)._inner_timestamp();
        (*net_signals)["SPEED"]["_timestamp"].push(pack->speed(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["SPEED"]["fl"].push(pack->speed(i).fl());
		(*net_signals)["SPEED"]["fr"].push(pack->speed(i).fr());

    }

    for(int i = 0; i < pack->debug_signal_2_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->debug_signal_2(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->debug_signal_2(i)._inner_timestamp();
        (*net_signals)["DEBUG_SIGNAL_2"]["_timestamp"].push(pack->debug_signal_2(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["DEBUG_SIGNAL_2"]["field_1"].push(pack->debug_signal_2(i).field_1());
		(*net_signals)["DEBUG_SIGNAL_2"]["field_2"].push(pack->debug_signal_2(i).field_2());
		(*net_signals)["DEBUG_SIGNAL_2"]["field_3"].push(pack->debug_signal_2(i).field_3());
		(*net_signals)["DEBUG_SIGNAL_2"]["field_4"].push(pack->debug_signal_2(i).field_4());

    }

}

void simulator_proto_interface_serialize_from_id(canlib_message_id id, simulator::Pack* pack, device_t* device) {
    int index = simulator_index_from_id(id);

    if (index == -1) return;

    switch(id) {
        
        case 1260: {
            simulator_imu_angular_rate_converted_t* msg = (simulator_imu_angular_rate_converted_t*)(device->message);
            simulator::IMU_ANGULAR_RATE* proto_msg = pack->add_imu_angular_rate();
			proto_msg->set_x(msg->x);
			proto_msg->set_y(msg->y);
			proto_msg->set_z(msg->z);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1261: {
            simulator_imu_acceleration_converted_t* msg = (simulator_imu_acceleration_converted_t*)(device->message);
            simulator::IMU_ACCELERATION* proto_msg = pack->add_imu_acceleration();
			proto_msg->set_x(msg->x);
			proto_msg->set_y(msg->y);
			proto_msg->set_z(msg->z);
			proto_msg->set_imu_temperature(msg->imu_temperature);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1536: {
            simulator_pedal_throttle_converted_t* msg = (simulator_pedal_throttle_converted_t*)(device->message);
            simulator::PEDAL_THROTTLE* proto_msg = pack->add_pedal_throttle();
			proto_msg->set_throttle(msg->throttle);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1544: {
            simulator_pedal_brakes_pressure_converted_t* msg = (simulator_pedal_brakes_pressure_converted_t*)(device->message);
            simulator::PEDAL_BRAKES_PRESSURE* proto_msg = pack->add_pedal_brakes_pressure();
			proto_msg->set_front(msg->front);
			proto_msg->set_rear(msg->rear);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1552: {
            simulator_steer_angle_converted_t* msg = (simulator_steer_angle_converted_t*)(device->message);
            simulator::STEER_ANGLE* proto_msg = pack->add_steer_angle();
			proto_msg->set_angle(msg->angle);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 512: {
            simulator_control_output_converted_t* msg = (simulator_control_output_converted_t*)(device->message);
            simulator::CONTROL_OUTPUT* proto_msg = pack->add_control_output();
			proto_msg->set_estimated_velocity(msg->estimated_velocity);
			proto_msg->set_torque_max_l(msg->torque_max_l);
			proto_msg->set_torque_max_r(msg->torque_max_r);
			proto_msg->set_torque_l(msg->torque_l);
			proto_msg->set_torque_r(msg->torque_r);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 520: {
            simulator_control_status_converted_t* msg = (simulator_control_status_converted_t*)(device->message);
            simulator::CONTROL_STATUS* proto_msg = pack->add_control_status();
			proto_msg->set_map_pw(msg->map_pw);
			proto_msg->set_map_sc(msg->map_sc);
			proto_msg->set_map_tv(msg->map_tv);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1560: {
            simulator_speed_converted_t* msg = (simulator_speed_converted_t*)(device->message);
            simulator::SPEED* proto_msg = pack->add_speed();
			proto_msg->set_fl(msg->fl);
			proto_msg->set_fr(msg->fr);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1568: {
            simulator_debug_signal_2_converted_t* msg = (simulator_debug_signal_2_converted_t*)(device->message);
            simulator::DEBUG_SIGNAL_2* proto_msg = pack->add_debug_signal_2();
			proto_msg->set_field_1(msg->field_1);
			proto_msg->set_field_2(msg->field_2);
			proto_msg->set_field_3(msg->field_3);
			proto_msg->set_field_4(msg->field_4);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

    }
}



#endif // simulator_PROTO_INTERAFCE_IMPLEMENTATION

#endif // simulator_PROTO_INTERFACE_H
