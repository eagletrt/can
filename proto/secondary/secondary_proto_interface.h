
#ifndef secondary_PROTO_INTERFACE_H
#define secondary_PROTO_INTERFACE_H

#include <string>
#include <unordered_map>
#include <functional>

#include "secondary.pb.h"

#ifdef secondary_IMPLEMENTATION
#undef secondary_IMPLEMENTATION
#define __secondary_IMPLEMENTATION
#endif

#include "../../lib/secondary/secondary_network.h"

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

void secondary_proto_interface_serialize_from_id(canlib_message_id id, secondary::Pack* pack, device_t* device);
void secondary_proto_interface_deserialize(secondary::Pack* pack, network_enums* net_enums, network_signals* net_signals, network_strings* net_strings, uint64_t resample_us);

#ifdef secondary_PROTO_INTERAFCE_IMPLEMENTATION

void secondary_proto_interface_deserialize(secondary::Pack* pack, network_enums* net_enums, network_signals* net_signals, network_strings* net_strings, uint64_t resample_us) {
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

    for(int i = 0; i < pack->irts_fl_0_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->irts_fl_0(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->irts_fl_0(i)._inner_timestamp();
        (*net_signals)["IRTS_FL_0"]["_timestamp"].push(pack->irts_fl_0(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["IRTS_FL_0"]["channel1"].push(pack->irts_fl_0(i).channel1());
		(*net_signals)["IRTS_FL_0"]["channel2"].push(pack->irts_fl_0(i).channel2());
		(*net_signals)["IRTS_FL_0"]["channel3"].push(pack->irts_fl_0(i).channel3());
		(*net_signals)["IRTS_FL_0"]["channel4"].push(pack->irts_fl_0(i).channel4());

    }

    for(int i = 0; i < pack->irts_fl_1_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->irts_fl_1(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->irts_fl_1(i)._inner_timestamp();
        (*net_signals)["IRTS_FL_1"]["_timestamp"].push(pack->irts_fl_1(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["IRTS_FL_1"]["channel5"].push(pack->irts_fl_1(i).channel5());
		(*net_signals)["IRTS_FL_1"]["channel6"].push(pack->irts_fl_1(i).channel6());
		(*net_signals)["IRTS_FL_1"]["channel7"].push(pack->irts_fl_1(i).channel7());
		(*net_signals)["IRTS_FL_1"]["channel8"].push(pack->irts_fl_1(i).channel8());

    }

    for(int i = 0; i < pack->irts_fl_2_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->irts_fl_2(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->irts_fl_2(i)._inner_timestamp();
        (*net_signals)["IRTS_FL_2"]["_timestamp"].push(pack->irts_fl_2(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["IRTS_FL_2"]["channel9"].push(pack->irts_fl_2(i).channel9());
		(*net_signals)["IRTS_FL_2"]["channel10"].push(pack->irts_fl_2(i).channel10());
		(*net_signals)["IRTS_FL_2"]["channel11"].push(pack->irts_fl_2(i).channel11());
		(*net_signals)["IRTS_FL_2"]["channel12"].push(pack->irts_fl_2(i).channel12());

    }

    for(int i = 0; i < pack->irts_fl_3_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->irts_fl_3(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->irts_fl_3(i)._inner_timestamp();
        (*net_signals)["IRTS_FL_3"]["_timestamp"].push(pack->irts_fl_3(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["IRTS_FL_3"]["channel13"].push(pack->irts_fl_3(i).channel13());
		(*net_signals)["IRTS_FL_3"]["channel14"].push(pack->irts_fl_3(i).channel14());
		(*net_signals)["IRTS_FL_3"]["channel15"].push(pack->irts_fl_3(i).channel15());
		(*net_signals)["IRTS_FL_3"]["channel16"].push(pack->irts_fl_3(i).channel16());

    }

    for(int i = 0; i < pack->irts_fr_0_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->irts_fr_0(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->irts_fr_0(i)._inner_timestamp();
        (*net_signals)["IRTS_FR_0"]["_timestamp"].push(pack->irts_fr_0(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["IRTS_FR_0"]["channel1"].push(pack->irts_fr_0(i).channel1());
		(*net_signals)["IRTS_FR_0"]["channel2"].push(pack->irts_fr_0(i).channel2());
		(*net_signals)["IRTS_FR_0"]["channel3"].push(pack->irts_fr_0(i).channel3());
		(*net_signals)["IRTS_FR_0"]["channel4"].push(pack->irts_fr_0(i).channel4());

    }

    for(int i = 0; i < pack->irts_fr_1_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->irts_fr_1(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->irts_fr_1(i)._inner_timestamp();
        (*net_signals)["IRTS_FR_1"]["_timestamp"].push(pack->irts_fr_1(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["IRTS_FR_1"]["channel5"].push(pack->irts_fr_1(i).channel5());
		(*net_signals)["IRTS_FR_1"]["channel6"].push(pack->irts_fr_1(i).channel6());
		(*net_signals)["IRTS_FR_1"]["channel7"].push(pack->irts_fr_1(i).channel7());
		(*net_signals)["IRTS_FR_1"]["channel8"].push(pack->irts_fr_1(i).channel8());

    }

    for(int i = 0; i < pack->irts_fr_2_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->irts_fr_2(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->irts_fr_2(i)._inner_timestamp();
        (*net_signals)["IRTS_FR_2"]["_timestamp"].push(pack->irts_fr_2(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["IRTS_FR_2"]["channel9"].push(pack->irts_fr_2(i).channel9());
		(*net_signals)["IRTS_FR_2"]["channel10"].push(pack->irts_fr_2(i).channel10());
		(*net_signals)["IRTS_FR_2"]["channel11"].push(pack->irts_fr_2(i).channel11());
		(*net_signals)["IRTS_FR_2"]["channel12"].push(pack->irts_fr_2(i).channel12());

    }

    for(int i = 0; i < pack->irts_fr_3_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->irts_fr_3(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->irts_fr_3(i)._inner_timestamp();
        (*net_signals)["IRTS_FR_3"]["_timestamp"].push(pack->irts_fr_3(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["IRTS_FR_3"]["channel13"].push(pack->irts_fr_3(i).channel13());
		(*net_signals)["IRTS_FR_3"]["channel14"].push(pack->irts_fr_3(i).channel14());
		(*net_signals)["IRTS_FR_3"]["channel15"].push(pack->irts_fr_3(i).channel15());
		(*net_signals)["IRTS_FR_3"]["channel16"].push(pack->irts_fr_3(i).channel16());

    }

    for(int i = 0; i < pack->irts_rl_0_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->irts_rl_0(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->irts_rl_0(i)._inner_timestamp();
        (*net_signals)["IRTS_RL_0"]["_timestamp"].push(pack->irts_rl_0(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["IRTS_RL_0"]["channel1"].push(pack->irts_rl_0(i).channel1());
		(*net_signals)["IRTS_RL_0"]["channel2"].push(pack->irts_rl_0(i).channel2());
		(*net_signals)["IRTS_RL_0"]["channel3"].push(pack->irts_rl_0(i).channel3());
		(*net_signals)["IRTS_RL_0"]["channel4"].push(pack->irts_rl_0(i).channel4());

    }

    for(int i = 0; i < pack->irts_rl_1_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->irts_rl_1(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->irts_rl_1(i)._inner_timestamp();
        (*net_signals)["IRTS_RL_1"]["_timestamp"].push(pack->irts_rl_1(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["IRTS_RL_1"]["channel5"].push(pack->irts_rl_1(i).channel5());
		(*net_signals)["IRTS_RL_1"]["channel6"].push(pack->irts_rl_1(i).channel6());
		(*net_signals)["IRTS_RL_1"]["channel7"].push(pack->irts_rl_1(i).channel7());
		(*net_signals)["IRTS_RL_1"]["channel8"].push(pack->irts_rl_1(i).channel8());

    }

    for(int i = 0; i < pack->irts_rl_2_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->irts_rl_2(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->irts_rl_2(i)._inner_timestamp();
        (*net_signals)["IRTS_RL_2"]["_timestamp"].push(pack->irts_rl_2(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["IRTS_RL_2"]["channel9"].push(pack->irts_rl_2(i).channel9());
		(*net_signals)["IRTS_RL_2"]["channel10"].push(pack->irts_rl_2(i).channel10());
		(*net_signals)["IRTS_RL_2"]["channel11"].push(pack->irts_rl_2(i).channel11());
		(*net_signals)["IRTS_RL_2"]["channel12"].push(pack->irts_rl_2(i).channel12());

    }

    for(int i = 0; i < pack->irts_rl_3_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->irts_rl_3(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->irts_rl_3(i)._inner_timestamp();
        (*net_signals)["IRTS_RL_3"]["_timestamp"].push(pack->irts_rl_3(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["IRTS_RL_3"]["channel13"].push(pack->irts_rl_3(i).channel13());
		(*net_signals)["IRTS_RL_3"]["channel14"].push(pack->irts_rl_3(i).channel14());
		(*net_signals)["IRTS_RL_3"]["channel15"].push(pack->irts_rl_3(i).channel15());
		(*net_signals)["IRTS_RL_3"]["channel16"].push(pack->irts_rl_3(i).channel16());

    }

    for(int i = 0; i < pack->irts_rr_0_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->irts_rr_0(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->irts_rr_0(i)._inner_timestamp();
        (*net_signals)["IRTS_RR_0"]["_timestamp"].push(pack->irts_rr_0(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["IRTS_RR_0"]["channel1"].push(pack->irts_rr_0(i).channel1());
		(*net_signals)["IRTS_RR_0"]["channel2"].push(pack->irts_rr_0(i).channel2());
		(*net_signals)["IRTS_RR_0"]["channel3"].push(pack->irts_rr_0(i).channel3());
		(*net_signals)["IRTS_RR_0"]["channel4"].push(pack->irts_rr_0(i).channel4());

    }

    for(int i = 0; i < pack->irts_rr_1_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->irts_rr_1(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->irts_rr_1(i)._inner_timestamp();
        (*net_signals)["IRTS_RR_1"]["_timestamp"].push(pack->irts_rr_1(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["IRTS_RR_1"]["channel5"].push(pack->irts_rr_1(i).channel5());
		(*net_signals)["IRTS_RR_1"]["channel6"].push(pack->irts_rr_1(i).channel6());
		(*net_signals)["IRTS_RR_1"]["channel7"].push(pack->irts_rr_1(i).channel7());
		(*net_signals)["IRTS_RR_1"]["channel8"].push(pack->irts_rr_1(i).channel8());

    }

    for(int i = 0; i < pack->irts_rr_2_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->irts_rr_2(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->irts_rr_2(i)._inner_timestamp();
        (*net_signals)["IRTS_RR_2"]["_timestamp"].push(pack->irts_rr_2(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["IRTS_RR_2"]["channel9"].push(pack->irts_rr_2(i).channel9());
		(*net_signals)["IRTS_RR_2"]["channel10"].push(pack->irts_rr_2(i).channel10());
		(*net_signals)["IRTS_RR_2"]["channel11"].push(pack->irts_rr_2(i).channel11());
		(*net_signals)["IRTS_RR_2"]["channel12"].push(pack->irts_rr_2(i).channel12());

    }

    for(int i = 0; i < pack->irts_rr_3_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->irts_rr_3(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->irts_rr_3(i)._inner_timestamp();
        (*net_signals)["IRTS_RR_3"]["_timestamp"].push(pack->irts_rr_3(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["IRTS_RR_3"]["channel13"].push(pack->irts_rr_3(i).channel13());
		(*net_signals)["IRTS_RR_3"]["channel14"].push(pack->irts_rr_3(i).channel14());
		(*net_signals)["IRTS_RR_3"]["channel15"].push(pack->irts_rr_3(i).channel15());
		(*net_signals)["IRTS_RR_3"]["channel16"].push(pack->irts_rr_3(i).channel16());

    }

    for(int i = 0; i < pack->gps_coords_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->gps_coords(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->gps_coords(i)._inner_timestamp();
        (*net_signals)["GPS_COORDS"]["_timestamp"].push(pack->gps_coords(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["GPS_COORDS"]["latitude"].push(pack->gps_coords(i).latitude());
		(*net_signals)["GPS_COORDS"]["longitude"].push(pack->gps_coords(i).longitude());

    }

    for(int i = 0; i < pack->gps_speed_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->gps_speed(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->gps_speed(i)._inner_timestamp();
        (*net_signals)["GPS_SPEED"]["_timestamp"].push(pack->gps_speed(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["GPS_SPEED"]["speed"].push(pack->gps_speed(i).speed());

    }

    for(int i = 0; i < pack->angular_velocity_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->angular_velocity(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->angular_velocity(i)._inner_timestamp();
        (*net_signals)["ANGULAR_VELOCITY"]["_timestamp"].push(pack->angular_velocity(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["ANGULAR_VELOCITY"]["fl"].push(pack->angular_velocity(i).fl());
		(*net_signals)["ANGULAR_VELOCITY"]["fr"].push(pack->angular_velocity(i).fr());

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

    for(int i = 0; i < pack->tpms_pressure_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->tpms_pressure(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->tpms_pressure(i)._inner_timestamp();
        (*net_signals)["TPMS_PRESSURE"]["_timestamp"].push(pack->tpms_pressure(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["TPMS_PRESSURE"]["fl"].push(pack->tpms_pressure(i).fl());
		(*net_signals)["TPMS_PRESSURE"]["fr"].push(pack->tpms_pressure(i).fr());
		(*net_signals)["TPMS_PRESSURE"]["rl"].push(pack->tpms_pressure(i).rl());
		(*net_signals)["TPMS_PRESSURE"]["rr"].push(pack->tpms_pressure(i).rr());

    }

    for(int i = 0; i < pack->tpms_temperature_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->tpms_temperature(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->tpms_temperature(i)._inner_timestamp();
        (*net_signals)["TPMS_TEMPERATURE"]["_timestamp"].push(pack->tpms_temperature(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["TPMS_TEMPERATURE"]["fl"].push(pack->tpms_temperature(i).fl());
		(*net_signals)["TPMS_TEMPERATURE"]["fr"].push(pack->tpms_temperature(i).fr());
		(*net_signals)["TPMS_TEMPERATURE"]["rl"].push(pack->tpms_temperature(i).rl());
		(*net_signals)["TPMS_TEMPERATURE"]["rr"].push(pack->tpms_temperature(i).rr());

    }

    for(int i = 0; i < pack->tlm_unix_timestamp_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->tlm_unix_timestamp(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->tlm_unix_timestamp(i)._inner_timestamp();
        (*net_signals)["TLM_UNIX_TIMESTAMP"]["_timestamp"].push(pack->tlm_unix_timestamp(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["TLM_UNIX_TIMESTAMP"]["timestamp"].push(pack->tlm_unix_timestamp(i).timestamp());

    }

    for(int i = 0; i < pack->tlm_lap_time_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->tlm_lap_time(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->tlm_lap_time(i)._inner_timestamp();
        (*net_signals)["TLM_LAP_TIME"]["_timestamp"].push(pack->tlm_lap_time(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["TLM_LAP_TIME"]["lap_count"].push(pack->tlm_lap_time(i).lap_count());
		(*net_signals)["TLM_LAP_TIME"]["lap_time"].push(pack->tlm_lap_time(i).lap_time());

    }

    for(int i = 0; i < pack->tlm_laps_stats_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->tlm_laps_stats(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->tlm_laps_stats(i)._inner_timestamp();
        (*net_signals)["TLM_LAPS_STATS"]["_timestamp"].push(pack->tlm_laps_stats(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["TLM_LAPS_STATS"]["lap_number"].push(pack->tlm_laps_stats(i).lap_number());
		(*net_signals)["TLM_LAPS_STATS"]["best_time"].push(pack->tlm_laps_stats(i).best_time());
		(*net_signals)["TLM_LAPS_STATS"]["last_time"].push(pack->tlm_laps_stats(i).last_time());

    }

    for(int i = 0; i < pack->ammo_compression_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->ammo_compression(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->ammo_compression(i)._inner_timestamp();
        (*net_signals)["AMMO_COMPRESSION"]["_timestamp"].push(pack->ammo_compression(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["AMMO_COMPRESSION"]["rl"].push(pack->ammo_compression(i).rl());
		(*net_signals)["AMMO_COMPRESSION"]["rr"].push(pack->ammo_compression(i).rr());
		(*net_signals)["AMMO_COMPRESSION"]["fl"].push(pack->ammo_compression(i).fl());
		(*net_signals)["AMMO_COMPRESSION"]["fr"].push(pack->ammo_compression(i).fr());

    }

    for(int i = 0; i < pack->link_deformation_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->link_deformation(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->link_deformation(i)._inner_timestamp();
        (*net_signals)["LINK_DEFORMATION"]["_timestamp"].push(pack->link_deformation(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["LINK_DEFORMATION"]["rod_id"].push(pack->link_deformation(i).rod_id());
		(*net_signals)["LINK_DEFORMATION"]["deformation"].push(pack->link_deformation(i).deformation());

    }

    for(int i = 0; i < pack->debug_signal_1_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->debug_signal_1(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->debug_signal_1(i)._inner_timestamp();
        (*net_signals)["DEBUG_SIGNAL_1"]["_timestamp"].push(pack->debug_signal_1(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["DEBUG_SIGNAL_1"]["field_1"].push(pack->debug_signal_1(i).field_1());
		(*net_signals)["DEBUG_SIGNAL_1"]["field_2"].push(pack->debug_signal_1(i).field_2());
		(*net_signals)["DEBUG_SIGNAL_1"]["field_3"].push(pack->debug_signal_1(i).field_3());
		(*net_signals)["DEBUG_SIGNAL_1"]["field_4"].push(pack->debug_signal_1(i).field_4());

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

    for(int i = 0; i < pack->cooling_temp_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->cooling_temp(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->cooling_temp(i)._inner_timestamp();
        (*net_signals)["COOLING_TEMP"]["_timestamp"].push(pack->cooling_temp(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["COOLING_TEMP"]["top_left"].push(pack->cooling_temp(i).top_left());
		(*net_signals)["COOLING_TEMP"]["bottom_left"].push(pack->cooling_temp(i).bottom_left());
		(*net_signals)["COOLING_TEMP"]["top_right"].push(pack->cooling_temp(i).top_right());
		(*net_signals)["COOLING_TEMP"]["bottom_right"].push(pack->cooling_temp(i).bottom_right());

    }

}

void secondary_proto_interface_serialize_from_id(canlib_message_id id, secondary::Pack* pack, device_t* device) {
    int index = secondary_index_from_id(id);

    if (index == -1) return;

    switch(id) {
        
        case 1260: {
            secondary_imu_angular_rate_converted_t* msg = (secondary_imu_angular_rate_converted_t*)(device->message);
            secondary::IMU_ANGULAR_RATE* proto_msg = pack->add_imu_angular_rate();
			proto_msg->set_x(msg->x);
			proto_msg->set_y(msg->y);
			proto_msg->set_z(msg->z);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1261: {
            secondary_imu_acceleration_converted_t* msg = (secondary_imu_acceleration_converted_t*)(device->message);
            secondary::IMU_ACCELERATION* proto_msg = pack->add_imu_acceleration();
			proto_msg->set_x(msg->x);
			proto_msg->set_y(msg->y);
			proto_msg->set_z(msg->z);
			proto_msg->set_imu_temperature(msg->imu_temperature);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1456: {
            secondary_irts_fl_0_converted_t* msg = (secondary_irts_fl_0_converted_t*)(device->message);
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

        case 1457: {
            secondary_irts_fl_1_converted_t* msg = (secondary_irts_fl_1_converted_t*)(device->message);
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

        case 1458: {
            secondary_irts_fl_2_converted_t* msg = (secondary_irts_fl_2_converted_t*)(device->message);
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

        case 1459: {
            secondary_irts_fl_3_converted_t* msg = (secondary_irts_fl_3_converted_t*)(device->message);
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
            secondary_irts_fr_0_converted_t* msg = (secondary_irts_fr_0_converted_t*)(device->message);
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
            secondary_irts_fr_1_converted_t* msg = (secondary_irts_fr_1_converted_t*)(device->message);
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
            secondary_irts_fr_2_converted_t* msg = (secondary_irts_fr_2_converted_t*)(device->message);
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
            secondary_irts_fr_3_converted_t* msg = (secondary_irts_fr_3_converted_t*)(device->message);
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
            secondary_irts_rl_0_converted_t* msg = (secondary_irts_rl_0_converted_t*)(device->message);
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
            secondary_irts_rl_1_converted_t* msg = (secondary_irts_rl_1_converted_t*)(device->message);
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
            secondary_irts_rl_2_converted_t* msg = (secondary_irts_rl_2_converted_t*)(device->message);
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
            secondary_irts_rl_3_converted_t* msg = (secondary_irts_rl_3_converted_t*)(device->message);
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

        case 1200: {
            secondary_irts_rr_0_converted_t* msg = (secondary_irts_rr_0_converted_t*)(device->message);
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

        case 1201: {
            secondary_irts_rr_1_converted_t* msg = (secondary_irts_rr_1_converted_t*)(device->message);
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

        case 1202: {
            secondary_irts_rr_2_converted_t* msg = (secondary_irts_rr_2_converted_t*)(device->message);
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

        case 1203: {
            secondary_irts_rr_3_converted_t* msg = (secondary_irts_rr_3_converted_t*)(device->message);
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

        case 1536: {
            secondary_gps_coords_t* msg = (secondary_gps_coords_t*)(device->message);
            secondary::GPS_COORDS* proto_msg = pack->add_gps_coords();
			proto_msg->set_latitude(msg->latitude);
			proto_msg->set_longitude(msg->longitude);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1544: {
            secondary_gps_speed_t* msg = (secondary_gps_speed_t*)(device->message);
            secondary::GPS_SPEED* proto_msg = pack->add_gps_speed();
			proto_msg->set_speed(msg->speed);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1552: {
            secondary_angular_velocity_converted_t* msg = (secondary_angular_velocity_converted_t*)(device->message);
            secondary::ANGULAR_VELOCITY* proto_msg = pack->add_angular_velocity();
			proto_msg->set_fl(msg->fl);
			proto_msg->set_fr(msg->fr);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1560: {
            secondary_pedal_throttle_converted_t* msg = (secondary_pedal_throttle_converted_t*)(device->message);
            secondary::PEDAL_THROTTLE* proto_msg = pack->add_pedal_throttle();
			proto_msg->set_throttle(msg->throttle);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1568: {
            secondary_pedal_brakes_pressure_converted_t* msg = (secondary_pedal_brakes_pressure_converted_t*)(device->message);
            secondary::PEDAL_BRAKES_PRESSURE* proto_msg = pack->add_pedal_brakes_pressure();
			proto_msg->set_front(msg->front);
			proto_msg->set_rear(msg->rear);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1576: {
            secondary_steer_angle_converted_t* msg = (secondary_steer_angle_converted_t*)(device->message);
            secondary::STEER_ANGLE* proto_msg = pack->add_steer_angle();
			proto_msg->set_angle(msg->angle);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1584: {
            secondary_tpms_pressure_t* msg = (secondary_tpms_pressure_t*)(device->message);
            secondary::TPMS_PRESSURE* proto_msg = pack->add_tpms_pressure();
			proto_msg->set_fl(msg->fl);
			proto_msg->set_fr(msg->fr);
			proto_msg->set_rl(msg->rl);
			proto_msg->set_rr(msg->rr);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1592: {
            secondary_tpms_temperature_t* msg = (secondary_tpms_temperature_t*)(device->message);
            secondary::TPMS_TEMPERATURE* proto_msg = pack->add_tpms_temperature();
			proto_msg->set_fl(msg->fl);
			proto_msg->set_fr(msg->fr);
			proto_msg->set_rl(msg->rl);
			proto_msg->set_rr(msg->rr);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1600: {
            secondary_tlm_unix_timestamp_t* msg = (secondary_tlm_unix_timestamp_t*)(device->message);
            secondary::TLM_UNIX_TIMESTAMP* proto_msg = pack->add_tlm_unix_timestamp();
			proto_msg->set_timestamp(msg->timestamp);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1608: {
            secondary_tlm_lap_time_converted_t* msg = (secondary_tlm_lap_time_converted_t*)(device->message);
            secondary::TLM_LAP_TIME* proto_msg = pack->add_tlm_lap_time();
			proto_msg->set_lap_count(msg->lap_count);
			proto_msg->set_lap_time(msg->lap_time);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1616: {
            secondary_tlm_laps_stats_converted_t* msg = (secondary_tlm_laps_stats_converted_t*)(device->message);
            secondary::TLM_LAPS_STATS* proto_msg = pack->add_tlm_laps_stats();
			proto_msg->set_lap_number(msg->lap_number);
			proto_msg->set_best_time(msg->best_time);
			proto_msg->set_last_time(msg->last_time);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1624: {
            secondary_ammo_compression_converted_t* msg = (secondary_ammo_compression_converted_t*)(device->message);
            secondary::AMMO_COMPRESSION* proto_msg = pack->add_ammo_compression();
			proto_msg->set_rl(msg->rl);
			proto_msg->set_rr(msg->rr);
			proto_msg->set_fl(msg->fl);
			proto_msg->set_fr(msg->fr);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1632: {
            secondary_link_deformation_converted_t* msg = (secondary_link_deformation_converted_t*)(device->message);
            secondary::LINK_DEFORMATION* proto_msg = pack->add_link_deformation();
			proto_msg->set_rod_id(msg->rod_id);
			proto_msg->set_deformation(msg->deformation);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1640: {
            secondary_debug_signal_1_converted_t* msg = (secondary_debug_signal_1_converted_t*)(device->message);
            secondary::DEBUG_SIGNAL_1* proto_msg = pack->add_debug_signal_1();
			proto_msg->set_field_1(msg->field_1);
			proto_msg->set_field_2(msg->field_2);
			proto_msg->set_field_3(msg->field_3);
			proto_msg->set_field_4(msg->field_4);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1648: {
            secondary_debug_signal_2_converted_t* msg = (secondary_debug_signal_2_converted_t*)(device->message);
            secondary::DEBUG_SIGNAL_2* proto_msg = pack->add_debug_signal_2();
			proto_msg->set_field_1(msg->field_1);
			proto_msg->set_field_2(msg->field_2);
			proto_msg->set_field_3(msg->field_3);
			proto_msg->set_field_4(msg->field_4);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1656: {
            secondary_cooling_temp_converted_t* msg = (secondary_cooling_temp_converted_t*)(device->message);
            secondary::COOLING_TEMP* proto_msg = pack->add_cooling_temp();
			proto_msg->set_top_left(msg->top_left);
			proto_msg->set_bottom_left(msg->bottom_left);
			proto_msg->set_top_right(msg->top_right);
			proto_msg->set_bottom_right(msg->bottom_right);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

    }
}



#endif // secondary_PROTO_INTERAFCE_IMPLEMENTATION

#endif // secondary_PROTO_INTERFACE_H
