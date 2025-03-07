
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
  _offset = 0;
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
		(*net_enums)["CONTROL_STATUS"]["sc_state"].push(pack->control_status(i).sc_state());
		simulator_control_status_sc_state_enum_to_string((simulator_control_status_sc_state)pack->control_status(i).sc_state(), buffer);
		(*net_strings)["CONTROL_STATUS"]["sc_state"].push(buffer);
		(*net_enums)["CONTROL_STATUS"]["tv_state"].push(pack->control_status(i).tv_state());
		simulator_control_status_tv_state_enum_to_string((simulator_control_status_tv_state)pack->control_status(i).tv_state(), buffer);
		(*net_strings)["CONTROL_STATUS"]["tv_state"].push(buffer);
		(*net_enums)["CONTROL_STATUS"]["reg_state"].push(pack->control_status(i).reg_state());
		simulator_control_status_reg_state_enum_to_string((simulator_control_status_reg_state)pack->control_status(i).reg_state(), buffer);
		(*net_strings)["CONTROL_STATUS"]["reg_state"].push(buffer);

    }

    for(int i = 0; i < pack->front_angular_velocity_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->front_angular_velocity(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->front_angular_velocity(i)._inner_timestamp();
        (*net_signals)["FRONT_ANGULAR_VELOCITY"]["_timestamp"].push(pack->front_angular_velocity(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["FRONT_ANGULAR_VELOCITY"]["fl"].push(pack->front_angular_velocity(i).fl());
		(*net_signals)["FRONT_ANGULAR_VELOCITY"]["fr"].push(pack->front_angular_velocity(i).fr());

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

    for(int i = 0; i < pack->inv_l_rcv_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->inv_l_rcv(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->inv_l_rcv(i)._inner_timestamp();
        (*net_signals)["INV_L_RCV"]["_timestamp"].push(pack->inv_l_rcv(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["INV_L_RCV"]["n_actual_filt"].push(pack->inv_l_rcv(i).n_actual_filt());
		(*net_signals)["INV_L_RCV"]["m_setdig__iq"].push(pack->inv_l_rcv(i).m_setdig__iq());

    }

    for(int i = 0; i < pack->inv_r_rcv_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->inv_r_rcv(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->inv_r_rcv(i)._inner_timestamp();
        (*net_signals)["INV_R_RCV"]["_timestamp"].push(pack->inv_r_rcv(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["INV_R_RCV"]["n_actual_filt"].push(pack->inv_r_rcv(i).n_actual_filt());
		(*net_signals)["INV_R_RCV"]["m_setdig__iq"].push(pack->inv_r_rcv(i).m_setdig__iq());

    }

    for(int i = 0; i < pack->as_commands_status_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->as_commands_status(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->as_commands_status(i)._inner_timestamp();
        (*net_signals)["AS_COMMANDS_STATUS"]["_timestamp"].push(pack->as_commands_status(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["AS_COMMANDS_STATUS"]["steerstatus"].push(pack->as_commands_status(i).steerstatus());
		simulator_as_commands_status_steerstatus_enum_to_string((simulator_as_commands_status_steerstatus)pack->as_commands_status(i).steerstatus(), buffer);
		(*net_strings)["AS_COMMANDS_STATUS"]["steerstatus"].push(buffer);
		(*net_enums)["AS_COMMANDS_STATUS"]["throttlestatus"].push(pack->as_commands_status(i).throttlestatus());
		simulator_as_commands_status_throttlestatus_enum_to_string((simulator_as_commands_status_throttlestatus)pack->as_commands_status(i).throttlestatus(), buffer);
		(*net_strings)["AS_COMMANDS_STATUS"]["throttlestatus"].push(buffer);
		(*net_enums)["AS_COMMANDS_STATUS"]["brakestatus"].push(pack->as_commands_status(i).brakestatus());
		simulator_as_commands_status_brakestatus_enum_to_string((simulator_as_commands_status_brakestatus)pack->as_commands_status(i).brakestatus(), buffer);
		(*net_strings)["AS_COMMANDS_STATUS"]["brakestatus"].push(buffer);

    }

    for(int i = 0; i < pack->as_commands_set_status_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->as_commands_set_status(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->as_commands_set_status(i)._inner_timestamp();
        (*net_signals)["AS_COMMANDS_SET_STATUS"]["_timestamp"].push(pack->as_commands_set_status(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["AS_COMMANDS_SET_STATUS"]["steerstatus"].push(pack->as_commands_set_status(i).steerstatus());
		simulator_as_commands_set_status_steerstatus_enum_to_string((simulator_as_commands_set_status_steerstatus)pack->as_commands_set_status(i).steerstatus(), buffer);
		(*net_strings)["AS_COMMANDS_SET_STATUS"]["steerstatus"].push(buffer);
		(*net_enums)["AS_COMMANDS_SET_STATUS"]["throttlestatus"].push(pack->as_commands_set_status(i).throttlestatus());
		simulator_as_commands_set_status_throttlestatus_enum_to_string((simulator_as_commands_set_status_throttlestatus)pack->as_commands_set_status(i).throttlestatus(), buffer);
		(*net_strings)["AS_COMMANDS_SET_STATUS"]["throttlestatus"].push(buffer);
		(*net_enums)["AS_COMMANDS_SET_STATUS"]["brakestatus"].push(pack->as_commands_set_status(i).brakestatus());
		simulator_as_commands_set_status_brakestatus_enum_to_string((simulator_as_commands_set_status_brakestatus)pack->as_commands_set_status(i).brakestatus(), buffer);
		(*net_strings)["AS_COMMANDS_SET_STATUS"]["brakestatus"].push(buffer);

    }

    for(int i = 0; i < pack->as_commands_set_value_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->as_commands_set_value(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->as_commands_set_value(i)._inner_timestamp();
        (*net_signals)["AS_COMMANDS_SET_VALUE"]["_timestamp"].push(pack->as_commands_set_value(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["AS_COMMANDS_SET_VALUE"]["steerangle"].push(pack->as_commands_set_value(i).steerangle());
		(*net_signals)["AS_COMMANDS_SET_VALUE"]["throttle"].push(pack->as_commands_set_value(i).throttle());
		(*net_signals)["AS_COMMANDS_SET_VALUE"]["brake"].push(pack->as_commands_set_value(i).brake());

    }

    for(int i = 0; i < pack->vehicle_position_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->vehicle_position(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->vehicle_position(i)._inner_timestamp();
        (*net_signals)["VEHICLE_POSITION"]["_timestamp"].push(pack->vehicle_position(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["VEHICLE_POSITION"]["x"].push(pack->vehicle_position(i).x());
		(*net_signals)["VEHICLE_POSITION"]["y"].push(pack->vehicle_position(i).y());
		(*net_signals)["VEHICLE_POSITION"]["heading"].push(pack->vehicle_position(i).heading());

    }

    for(int i = 0; i < pack->vehicle_speed_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->vehicle_speed(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->vehicle_speed(i)._inner_timestamp();
        (*net_signals)["VEHICLE_SPEED"]["_timestamp"].push(pack->vehicle_speed(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["VEHICLE_SPEED"]["u"].push(pack->vehicle_speed(i).u());
		(*net_signals)["VEHICLE_SPEED"]["v"].push(pack->vehicle_speed(i).v());

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
			proto_msg->set_sc_state((simulator::simulator_control_status_sc_state)msg->sc_state);
			proto_msg->set_tv_state((simulator::simulator_control_status_tv_state)msg->tv_state);
			proto_msg->set_reg_state((simulator::simulator_control_status_reg_state)msg->reg_state);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1560: {
            simulator_front_angular_velocity_converted_t* msg = (simulator_front_angular_velocity_converted_t*)(device->message);
            simulator::FRONT_ANGULAR_VELOCITY* proto_msg = pack->add_front_angular_velocity();
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

        case 1576: {
            simulator_inv_l_rcv_converted_t* msg = (simulator_inv_l_rcv_converted_t*)(device->message);
            simulator::INV_L_RCV* proto_msg = pack->add_inv_l_rcv();
			proto_msg->set_n_actual_filt(msg->n_actual_filt);
			proto_msg->set_m_setdig__iq(msg->m_setdig__iq);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1584: {
            simulator_inv_r_rcv_converted_t* msg = (simulator_inv_r_rcv_converted_t*)(device->message);
            simulator::INV_R_RCV* proto_msg = pack->add_inv_r_rcv();
			proto_msg->set_n_actual_filt(msg->n_actual_filt);
			proto_msg->set_m_setdig__iq(msg->m_setdig__iq);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1592: {
            simulator_as_commands_status_t* msg = (simulator_as_commands_status_t*)(device->message);
            simulator::AS_COMMANDS_STATUS* proto_msg = pack->add_as_commands_status();
			proto_msg->set_steerstatus((simulator::simulator_as_commands_status_steerstatus)msg->steerstatus);
			proto_msg->set_throttlestatus((simulator::simulator_as_commands_status_throttlestatus)msg->throttlestatus);
			proto_msg->set_brakestatus((simulator::simulator_as_commands_status_brakestatus)msg->brakestatus);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1024: {
            simulator_as_commands_set_status_t* msg = (simulator_as_commands_set_status_t*)(device->message);
            simulator::AS_COMMANDS_SET_STATUS* proto_msg = pack->add_as_commands_set_status();
			proto_msg->set_steerstatus((simulator::simulator_as_commands_set_status_steerstatus)msg->steerstatus);
			proto_msg->set_throttlestatus((simulator::simulator_as_commands_set_status_throttlestatus)msg->throttlestatus);
			proto_msg->set_brakestatus((simulator::simulator_as_commands_set_status_brakestatus)msg->brakestatus);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1600: {
            simulator_as_commands_set_value_converted_t* msg = (simulator_as_commands_set_value_converted_t*)(device->message);
            simulator::AS_COMMANDS_SET_VALUE* proto_msg = pack->add_as_commands_set_value();
			proto_msg->set_steerangle(msg->steerangle);
			proto_msg->set_throttle(msg->throttle);
			proto_msg->set_brake(msg->brake);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1608: {
            simulator_vehicle_position_converted_t* msg = (simulator_vehicle_position_converted_t*)(device->message);
            simulator::VEHICLE_POSITION* proto_msg = pack->add_vehicle_position();
			proto_msg->set_x(msg->x);
			proto_msg->set_y(msg->y);
			proto_msg->set_heading(msg->heading);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1616: {
            simulator_vehicle_speed_converted_t* msg = (simulator_vehicle_speed_converted_t*)(device->message);
            simulator::VEHICLE_SPEED* proto_msg = pack->add_vehicle_speed();
			proto_msg->set_u(msg->u);
			proto_msg->set_v(msg->v);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

    }
}



#endif // simulator_PROTO_INTERAFCE_IMPLEMENTATION

#endif // simulator_PROTO_INTERFACE_H
