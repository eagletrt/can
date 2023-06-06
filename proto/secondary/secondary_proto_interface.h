
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

void secondary_proto_interface_serialize_from_id(canlib_message_id id, secondary::Pack* pack, secondary_devices* map);
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

		(*net_signals)["IMU_ANGULAR_RATE"]["ang_rate_x"].push(pack->imu_angular_rate(i).ang_rate_x());
		(*net_signals)["IMU_ANGULAR_RATE"]["ang_rate_y"].push(pack->imu_angular_rate(i).ang_rate_y());
		(*net_signals)["IMU_ANGULAR_RATE"]["ang_rate_z"].push(pack->imu_angular_rate(i).ang_rate_z());

    }

    for(int i = 0; i < pack->imu_acceleration_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->imu_acceleration(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->imu_acceleration(i)._inner_timestamp();
        (*net_signals)["IMU_ACCELERATION"]["_timestamp"].push(pack->imu_acceleration(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["IMU_ACCELERATION"]["accel_x"].push(pack->imu_acceleration(i).accel_x());
		(*net_signals)["IMU_ACCELERATION"]["accel_y"].push(pack->imu_acceleration(i).accel_y());
		(*net_signals)["IMU_ACCELERATION"]["accel_z"].push(pack->imu_acceleration(i).accel_z());
		(*net_signals)["IMU_ACCELERATION"]["temperature"].push(pack->imu_acceleration(i).temperature());

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

    for(int i = 0; i < pack->lap_count_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->lap_count(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->lap_count(i)._inner_timestamp();
        (*net_signals)["LAP_COUNT"]["_timestamp"].push(pack->lap_count(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["LAP_COUNT"]["lap_count"].push(pack->lap_count(i).lap_count());
		(*net_signals)["LAP_COUNT"]["lap_time"].push(pack->lap_count(i).lap_time());

    }

    for(int i = 0; i < pack->pedals_output_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->pedals_output(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->pedals_output(i)._inner_timestamp();
        (*net_signals)["PEDALS_OUTPUT"]["_timestamp"].push(pack->pedals_output(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["PEDALS_OUTPUT"]["apps"].push(pack->pedals_output(i).apps());
		(*net_signals)["PEDALS_OUTPUT"]["bse_front"].push(pack->pedals_output(i).bse_front());
		(*net_signals)["PEDALS_OUTPUT"]["bse_rear"].push(pack->pedals_output(i).bse_rear());

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

    for(int i = 0; i < pack->tpms_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->tpms(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->tpms(i)._inner_timestamp();
        (*net_signals)["TPMS"]["_timestamp"].push(pack->tpms(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["TPMS"]["fl_pressure"].push(pack->tpms(i).fl_pressure());
		(*net_signals)["TPMS"]["fr_pressure"].push(pack->tpms(i).fr_pressure());
		(*net_signals)["TPMS"]["rl_pressure"].push(pack->tpms(i).rl_pressure());
		(*net_signals)["TPMS"]["rr_pressure"].push(pack->tpms(i).rr_pressure());
		(*net_signals)["TPMS"]["fl_temperature"].push(pack->tpms(i).fl_temperature());
		(*net_signals)["TPMS"]["fr_temperature"].push(pack->tpms(i).fr_temperature());
		(*net_signals)["TPMS"]["rl_temperature"].push(pack->tpms(i).rl_temperature());
		(*net_signals)["TPMS"]["rr_temperature"].push(pack->tpms(i).rr_temperature());

    }

    for(int i = 0; i < pack->lc_status_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->lc_status(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->lc_status(i)._inner_timestamp();
        (*net_signals)["LC_STATUS"]["_timestamp"].push(pack->lc_status(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["LC_STATUS"]["last_time"].push(pack->lc_status(i).last_time());
		(*net_signals)["LC_STATUS"]["lap_number"].push(pack->lc_status(i).lap_number());

    }

}

void secondary_proto_interface_serialize_from_id(canlib_message_id id, secondary::Pack* pack, secondary_devices* map) {
    int index = secondary_index_from_id(id);

    if (index == -1) return;

    switch(id) {
        
        case 1260: {
            secondary_imu_angular_rate_converted_t* msg = (secondary_imu_angular_rate_converted_t*)((*map)[index].message_conversion);
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
            secondary_imu_acceleration_converted_t* msg = (secondary_imu_acceleration_converted_t*)((*map)[index].message_conversion);
            secondary::IMU_ACCELERATION* proto_msg = pack->add_imu_acceleration();
			proto_msg->set_accel_x(msg->accel_x);
			proto_msg->set_accel_y(msg->accel_y);
			proto_msg->set_accel_z(msg->accel_z);
			proto_msg->set_temperature(msg->temperature);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1460: {
            secondary_irts_fl_0_converted_t* msg = (secondary_irts_fl_0_converted_t*)((*map)[index].message_conversion);
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
            secondary_irts_fl_1_converted_t* msg = (secondary_irts_fl_1_converted_t*)((*map)[index].message_conversion);
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
            secondary_irts_fl_2_converted_t* msg = (secondary_irts_fl_2_converted_t*)((*map)[index].message_conversion);
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
            secondary_irts_fl_3_converted_t* msg = (secondary_irts_fl_3_converted_t*)((*map)[index].message_conversion);
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
            secondary_irts_fr_0_converted_t* msg = (secondary_irts_fr_0_converted_t*)((*map)[index].message_conversion);
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
            secondary_irts_fr_1_converted_t* msg = (secondary_irts_fr_1_converted_t*)((*map)[index].message_conversion);
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
            secondary_irts_fr_2_converted_t* msg = (secondary_irts_fr_2_converted_t*)((*map)[index].message_conversion);
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
            secondary_irts_fr_3_converted_t* msg = (secondary_irts_fr_3_converted_t*)((*map)[index].message_conversion);
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
            secondary_irts_rl_0_converted_t* msg = (secondary_irts_rl_0_converted_t*)((*map)[index].message_conversion);
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
            secondary_irts_rl_1_converted_t* msg = (secondary_irts_rl_1_converted_t*)((*map)[index].message_conversion);
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
            secondary_irts_rl_2_converted_t* msg = (secondary_irts_rl_2_converted_t*)((*map)[index].message_conversion);
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
            secondary_irts_rl_3_converted_t* msg = (secondary_irts_rl_3_converted_t*)((*map)[index].message_conversion);
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
            secondary_irts_rr_0_converted_t* msg = (secondary_irts_rr_0_converted_t*)((*map)[index].message_conversion);
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
            secondary_irts_rr_1_converted_t* msg = (secondary_irts_rr_1_converted_t*)((*map)[index].message_conversion);
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
            secondary_irts_rr_2_converted_t* msg = (secondary_irts_rr_2_converted_t*)((*map)[index].message_conversion);
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
            secondary_irts_rr_3_converted_t* msg = (secondary_irts_rr_3_converted_t*)((*map)[index].message_conversion);
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

        case 1024: {
            secondary_gps_coords_t* msg = (secondary_gps_coords_t*)((*map)[index].message_raw);
            secondary::GPS_COORDS* proto_msg = pack->add_gps_coords();
			proto_msg->set_latitude(msg->latitude);
			proto_msg->set_longitude(msg->longitude);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1056: {
            secondary_gps_speed_t* msg = (secondary_gps_speed_t*)((*map)[index].message_raw);
            secondary::GPS_SPEED* proto_msg = pack->add_gps_speed();
			proto_msg->set_speed(msg->speed);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1088: {
            secondary_lap_count_t* msg = (secondary_lap_count_t*)((*map)[index].message_raw);
            secondary::LAP_COUNT* proto_msg = pack->add_lap_count();
			proto_msg->set_lap_count(msg->lap_count);
			proto_msg->set_lap_time(msg->lap_time);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 768: {
            secondary_pedals_output_converted_t* msg = (secondary_pedals_output_converted_t*)((*map)[index].message_conversion);
            secondary::PEDALS_OUTPUT* proto_msg = pack->add_pedals_output();
			proto_msg->set_apps(msg->apps);
			proto_msg->set_bse_front(msg->bse_front);
			proto_msg->set_bse_rear(msg->bse_rear);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 259: {
            secondary_steering_angle_t* msg = (secondary_steering_angle_t*)((*map)[index].message_raw);
            secondary::STEERING_ANGLE* proto_msg = pack->add_steering_angle();
			proto_msg->set_angle(msg->angle);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1282: {
            secondary_control_state_converted_t* msg = (secondary_control_state_converted_t*)((*map)[index].message_conversion);
            secondary::CONTROL_STATE* proto_msg = pack->add_control_state();
			proto_msg->set_map_pw(msg->map_pw);
			proto_msg->set_map_sc(msg->map_sc);
			proto_msg->set_map_tv(msg->map_tv);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 512: {
            secondary_tpms_t* msg = (secondary_tpms_t*)((*map)[index].message_raw);
            secondary::TPMS* proto_msg = pack->add_tpms();
			proto_msg->set_fl_pressure(msg->fl_pressure);
			proto_msg->set_fr_pressure(msg->fr_pressure);
			proto_msg->set_rl_pressure(msg->rl_pressure);
			proto_msg->set_rr_pressure(msg->rr_pressure);
			proto_msg->set_fl_temperature(msg->fl_temperature);
			proto_msg->set_fr_temperature(msg->fr_temperature);
			proto_msg->set_rl_temperature(msg->rl_temperature);
			proto_msg->set_rr_temperature(msg->rr_temperature);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 769: {
            secondary_lc_status_t* msg = (secondary_lc_status_t*)((*map)[index].message_raw);
            secondary::LC_STATUS* proto_msg = pack->add_lc_status();
			proto_msg->set_last_time(msg->last_time);
			proto_msg->set_lap_number(msg->lap_number);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

    }
}



#endif // secondary_PROTO_INTERAFCE_IMPLEMENTATION

#endif // secondary_PROTO_INTERFACE_H
