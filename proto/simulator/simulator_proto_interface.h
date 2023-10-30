
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
    
    for(int i = 0; i < pack->angular_rate_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->angular_rate(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->angular_rate(i)._inner_timestamp();
        (*net_signals)["ANGULAR_RATE"]["_timestamp"].push(pack->angular_rate(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["ANGULAR_RATE"]["x"].push(pack->angular_rate(i).x());
		(*net_signals)["ANGULAR_RATE"]["y"].push(pack->angular_rate(i).y());
		(*net_signals)["ANGULAR_RATE"]["z"].push(pack->angular_rate(i).z());

    }

    for(int i = 0; i < pack->acceleration_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->acceleration(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->acceleration(i)._inner_timestamp();
        (*net_signals)["ACCELERATION"]["_timestamp"].push(pack->acceleration(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["ACCELERATION"]["x"].push(pack->acceleration(i).x());
		(*net_signals)["ACCELERATION"]["y"].push(pack->acceleration(i).y());
		(*net_signals)["ACCELERATION"]["z"].push(pack->acceleration(i).z());
		(*net_signals)["ACCELERATION"]["temperature"].push(pack->acceleration(i).temperature());

    }

    for(int i = 0; i < pack->pedals_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->pedals(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->pedals(i)._inner_timestamp();
        (*net_signals)["PEDALS"]["_timestamp"].push(pack->pedals(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["PEDALS"]["throttle"].push(pack->pedals(i).throttle());
		(*net_signals)["PEDALS"]["brake_front"].push(pack->pedals(i).brake_front());
		(*net_signals)["PEDALS"]["brake_rear"].push(pack->pedals(i).brake_rear());

    }

    for(int i = 0; i < pack->steering_angle_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->steering_angle(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->steering_angle(i)._inner_timestamp();
        (*net_signals)["STEERING_ANGLE"]["_timestamp"].push(pack->steering_angle(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["STEERING_ANGLE"]["angle"].push(pack->steering_angle(i).angle());

    }

    for(int i = 0; i < pack->control_state_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->control_state(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->control_state(i)._inner_timestamp();
        (*net_signals)["CONTROL_STATE"]["_timestamp"].push(pack->control_state(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["CONTROL_STATE"]["map_pw"].push(pack->control_state(i).map_pw());
		(*net_signals)["CONTROL_STATE"]["map_sc"].push(pack->control_state(i).map_sc());
		(*net_signals)["CONTROL_STATE"]["map_tv"].push(pack->control_state(i).map_tv());

    }

    for(int i = 0; i < pack->control_output_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->control_output(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->control_output(i)._inner_timestamp();
        (*net_signals)["CONTROL_OUTPUT"]["_timestamp"].push(pack->control_output(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["CONTROL_OUTPUT"]["estimated_velocity"].push(pack->control_output(i).estimated_velocity());
		(*net_signals)["CONTROL_OUTPUT"]["tmax_r"].push(pack->control_output(i).tmax_r());
		(*net_signals)["CONTROL_OUTPUT"]["tmax_l"].push(pack->control_output(i).tmax_l());
		(*net_signals)["CONTROL_OUTPUT"]["torque_l"].push(pack->control_output(i).torque_l());
		(*net_signals)["CONTROL_OUTPUT"]["torque_r"].push(pack->control_output(i).torque_r());

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
		(*net_signals)["SPEED"]["rl"].push(pack->speed(i).rl());
		(*net_signals)["SPEED"]["rr"].push(pack->speed(i).rr());

    }

}

void simulator_proto_interface_serialize_from_id(canlib_message_id id, simulator::Pack* pack, device_t* device) {
    int index = simulator_index_from_id(id);

    if (index == -1) return;

    switch(id) {
        
        case 1260: {
            simulator_angular_rate_converted_t* msg = (simulator_angular_rate_converted_t*)(device->message);
            simulator::ANGULAR_RATE* proto_msg = pack->add_angular_rate();
			proto_msg->set_x(msg->x);
			proto_msg->set_y(msg->y);
			proto_msg->set_z(msg->z);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1261: {
            simulator_acceleration_converted_t* msg = (simulator_acceleration_converted_t*)(device->message);
            simulator::ACCELERATION* proto_msg = pack->add_acceleration();
			proto_msg->set_x(msg->x);
			proto_msg->set_y(msg->y);
			proto_msg->set_z(msg->z);
			proto_msg->set_temperature(msg->temperature);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 769: {
            simulator_pedals_converted_t* msg = (simulator_pedals_converted_t*)(device->message);
            simulator::PEDALS* proto_msg = pack->add_pedals();
			proto_msg->set_throttle(msg->throttle);
			proto_msg->set_brake_front(msg->brake_front);
			proto_msg->set_brake_rear(msg->brake_rear);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 258: {
            simulator_steering_angle_converted_t* msg = (simulator_steering_angle_converted_t*)(device->message);
            simulator::STEERING_ANGLE* proto_msg = pack->add_steering_angle();
			proto_msg->set_angle(msg->angle);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1280: {
            simulator_control_state_converted_t* msg = (simulator_control_state_converted_t*)(device->message);
            simulator::CONTROL_STATE* proto_msg = pack->add_control_state();
			proto_msg->set_map_pw(msg->map_pw);
			proto_msg->set_map_sc(msg->map_sc);
			proto_msg->set_map_tv(msg->map_tv);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 257: {
            simulator_control_output_converted_t* msg = (simulator_control_output_converted_t*)(device->message);
            simulator::CONTROL_OUTPUT* proto_msg = pack->add_control_output();
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

        case 513: {
            simulator_speed_converted_t* msg = (simulator_speed_converted_t*)(device->message);
            simulator::SPEED* proto_msg = pack->add_speed();
			proto_msg->set_fl(msg->fl);
			proto_msg->set_fr(msg->fr);
			proto_msg->set_rl(msg->rl);
			proto_msg->set_rr(msg->rr);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

    }
}



#endif // simulator_PROTO_INTERAFCE_IMPLEMENTATION

#endif // simulator_PROTO_INTERFACE_H
