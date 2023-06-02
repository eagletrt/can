
#ifndef bms_PROTO_INTERFACE_H
#define bms_PROTO_INTERFACE_H

#include <string>
#include <unordered_map>
#include <functional>

#include "bms.pb.h"

#ifdef bms_IMPLEMENTATION
#undef bms_IMPLEMENTATION
#define __bms_IMPLEMENTATION
#endif

#include "../../lib/bms/network.h"

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

void bms_proto_interface_serialize_from_id(canlib_message_id id, bms::Pack* pack, bms_devices* map);
void bms_proto_interface_deserialize(bms::Pack* pack, network_enums* net_enums, network_signals* net_signals, network_strings* net_strings, uint64_t resample_us);

#ifdef bms_PROTO_INTERAFCE_IMPLEMENTATION

void bms_proto_interface_deserialize(bms::Pack* pack, network_enums* net_enums, network_signals* net_signals, network_strings* net_strings, uint64_t resample_us) {
    char buffer[1024];
    
    for(int i = 0; i < pack->board_status_cellboard0_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->board_status_cellboard0(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->board_status_cellboard0(i)._inner_timestamp();
        (*net_signals)["BOARD_STATUS_CELLBOARD0"]["_timestamp"].push(pack->board_status_cellboard0(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["BOARD_STATUS_CELLBOARD0"]["errors_can_comm"].push(pack->board_status_cellboard0(i).errors_can_comm());
		(*net_signals)["BOARD_STATUS_CELLBOARD0"]["errors_ltc_comm"].push(pack->board_status_cellboard0(i).errors_ltc_comm());
		(*net_signals)["BOARD_STATUS_CELLBOARD0"]["errors_temp_comm_0"].push(pack->board_status_cellboard0(i).errors_temp_comm_0());
		(*net_signals)["BOARD_STATUS_CELLBOARD0"]["errors_temp_comm_1"].push(pack->board_status_cellboard0(i).errors_temp_comm_1());
		(*net_signals)["BOARD_STATUS_CELLBOARD0"]["errors_temp_comm_2"].push(pack->board_status_cellboard0(i).errors_temp_comm_2());
		(*net_signals)["BOARD_STATUS_CELLBOARD0"]["errors_temp_comm_3"].push(pack->board_status_cellboard0(i).errors_temp_comm_3());
		(*net_signals)["BOARD_STATUS_CELLBOARD0"]["errors_temp_comm_4"].push(pack->board_status_cellboard0(i).errors_temp_comm_4());
		(*net_signals)["BOARD_STATUS_CELLBOARD0"]["errors_temp_comm_5"].push(pack->board_status_cellboard0(i).errors_temp_comm_5());
		(*net_signals)["BOARD_STATUS_CELLBOARD0"]["errors_open_wire"].push(pack->board_status_cellboard0(i).errors_open_wire());
		(*net_enums)["BOARD_STATUS_CELLBOARD0"]["balancing_status"].push(pack->board_status_cellboard0(i).balancing_status());
		bms_board_status_cellboard0_balancing_status_enum_to_string((bms_board_status_cellboard0_balancing_status)pack->board_status_cellboard0(i).balancing_status(), buffer);
		(*net_strings)["BOARD_STATUS_CELLBOARD0"]["balancing_status"].push(buffer);

    }

    for(int i = 0; i < pack->board_status_cellboard1_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->board_status_cellboard1(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->board_status_cellboard1(i)._inner_timestamp();
        (*net_signals)["BOARD_STATUS_CELLBOARD1"]["_timestamp"].push(pack->board_status_cellboard1(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["BOARD_STATUS_CELLBOARD1"]["errors_can_comm"].push(pack->board_status_cellboard1(i).errors_can_comm());
		(*net_signals)["BOARD_STATUS_CELLBOARD1"]["errors_ltc_comm"].push(pack->board_status_cellboard1(i).errors_ltc_comm());
		(*net_signals)["BOARD_STATUS_CELLBOARD1"]["errors_temp_comm_0"].push(pack->board_status_cellboard1(i).errors_temp_comm_0());
		(*net_signals)["BOARD_STATUS_CELLBOARD1"]["errors_temp_comm_1"].push(pack->board_status_cellboard1(i).errors_temp_comm_1());
		(*net_signals)["BOARD_STATUS_CELLBOARD1"]["errors_temp_comm_2"].push(pack->board_status_cellboard1(i).errors_temp_comm_2());
		(*net_signals)["BOARD_STATUS_CELLBOARD1"]["errors_temp_comm_3"].push(pack->board_status_cellboard1(i).errors_temp_comm_3());
		(*net_signals)["BOARD_STATUS_CELLBOARD1"]["errors_temp_comm_4"].push(pack->board_status_cellboard1(i).errors_temp_comm_4());
		(*net_signals)["BOARD_STATUS_CELLBOARD1"]["errors_temp_comm_5"].push(pack->board_status_cellboard1(i).errors_temp_comm_5());
		(*net_signals)["BOARD_STATUS_CELLBOARD1"]["errors_open_wire"].push(pack->board_status_cellboard1(i).errors_open_wire());
		(*net_enums)["BOARD_STATUS_CELLBOARD1"]["balancing_status"].push(pack->board_status_cellboard1(i).balancing_status());
		bms_board_status_cellboard1_balancing_status_enum_to_string((bms_board_status_cellboard1_balancing_status)pack->board_status_cellboard1(i).balancing_status(), buffer);
		(*net_strings)["BOARD_STATUS_CELLBOARD1"]["balancing_status"].push(buffer);

    }

    for(int i = 0; i < pack->board_status_cellboard2_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->board_status_cellboard2(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->board_status_cellboard2(i)._inner_timestamp();
        (*net_signals)["BOARD_STATUS_CELLBOARD2"]["_timestamp"].push(pack->board_status_cellboard2(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["BOARD_STATUS_CELLBOARD2"]["errors_can_comm"].push(pack->board_status_cellboard2(i).errors_can_comm());
		(*net_signals)["BOARD_STATUS_CELLBOARD2"]["errors_ltc_comm"].push(pack->board_status_cellboard2(i).errors_ltc_comm());
		(*net_signals)["BOARD_STATUS_CELLBOARD2"]["errors_temp_comm_0"].push(pack->board_status_cellboard2(i).errors_temp_comm_0());
		(*net_signals)["BOARD_STATUS_CELLBOARD2"]["errors_temp_comm_1"].push(pack->board_status_cellboard2(i).errors_temp_comm_1());
		(*net_signals)["BOARD_STATUS_CELLBOARD2"]["errors_temp_comm_2"].push(pack->board_status_cellboard2(i).errors_temp_comm_2());
		(*net_signals)["BOARD_STATUS_CELLBOARD2"]["errors_temp_comm_3"].push(pack->board_status_cellboard2(i).errors_temp_comm_3());
		(*net_signals)["BOARD_STATUS_CELLBOARD2"]["errors_temp_comm_4"].push(pack->board_status_cellboard2(i).errors_temp_comm_4());
		(*net_signals)["BOARD_STATUS_CELLBOARD2"]["errors_temp_comm_5"].push(pack->board_status_cellboard2(i).errors_temp_comm_5());
		(*net_signals)["BOARD_STATUS_CELLBOARD2"]["errors_open_wire"].push(pack->board_status_cellboard2(i).errors_open_wire());
		(*net_enums)["BOARD_STATUS_CELLBOARD2"]["balancing_status"].push(pack->board_status_cellboard2(i).balancing_status());
		bms_board_status_cellboard2_balancing_status_enum_to_string((bms_board_status_cellboard2_balancing_status)pack->board_status_cellboard2(i).balancing_status(), buffer);
		(*net_strings)["BOARD_STATUS_CELLBOARD2"]["balancing_status"].push(buffer);

    }

    for(int i = 0; i < pack->board_status_cellboard3_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->board_status_cellboard3(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->board_status_cellboard3(i)._inner_timestamp();
        (*net_signals)["BOARD_STATUS_CELLBOARD3"]["_timestamp"].push(pack->board_status_cellboard3(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["BOARD_STATUS_CELLBOARD3"]["errors_can_comm"].push(pack->board_status_cellboard3(i).errors_can_comm());
		(*net_signals)["BOARD_STATUS_CELLBOARD3"]["errors_ltc_comm"].push(pack->board_status_cellboard3(i).errors_ltc_comm());
		(*net_signals)["BOARD_STATUS_CELLBOARD3"]["errors_temp_comm_0"].push(pack->board_status_cellboard3(i).errors_temp_comm_0());
		(*net_signals)["BOARD_STATUS_CELLBOARD3"]["errors_temp_comm_1"].push(pack->board_status_cellboard3(i).errors_temp_comm_1());
		(*net_signals)["BOARD_STATUS_CELLBOARD3"]["errors_temp_comm_2"].push(pack->board_status_cellboard3(i).errors_temp_comm_2());
		(*net_signals)["BOARD_STATUS_CELLBOARD3"]["errors_temp_comm_3"].push(pack->board_status_cellboard3(i).errors_temp_comm_3());
		(*net_signals)["BOARD_STATUS_CELLBOARD3"]["errors_temp_comm_4"].push(pack->board_status_cellboard3(i).errors_temp_comm_4());
		(*net_signals)["BOARD_STATUS_CELLBOARD3"]["errors_temp_comm_5"].push(pack->board_status_cellboard3(i).errors_temp_comm_5());
		(*net_signals)["BOARD_STATUS_CELLBOARD3"]["errors_open_wire"].push(pack->board_status_cellboard3(i).errors_open_wire());
		(*net_enums)["BOARD_STATUS_CELLBOARD3"]["balancing_status"].push(pack->board_status_cellboard3(i).balancing_status());
		bms_board_status_cellboard3_balancing_status_enum_to_string((bms_board_status_cellboard3_balancing_status)pack->board_status_cellboard3(i).balancing_status(), buffer);
		(*net_strings)["BOARD_STATUS_CELLBOARD3"]["balancing_status"].push(buffer);

    }

    for(int i = 0; i < pack->board_status_cellboard4_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->board_status_cellboard4(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->board_status_cellboard4(i)._inner_timestamp();
        (*net_signals)["BOARD_STATUS_CELLBOARD4"]["_timestamp"].push(pack->board_status_cellboard4(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["BOARD_STATUS_CELLBOARD4"]["errors_can_comm"].push(pack->board_status_cellboard4(i).errors_can_comm());
		(*net_signals)["BOARD_STATUS_CELLBOARD4"]["errors_ltc_comm"].push(pack->board_status_cellboard4(i).errors_ltc_comm());
		(*net_signals)["BOARD_STATUS_CELLBOARD4"]["errors_temp_comm_0"].push(pack->board_status_cellboard4(i).errors_temp_comm_0());
		(*net_signals)["BOARD_STATUS_CELLBOARD4"]["errors_temp_comm_1"].push(pack->board_status_cellboard4(i).errors_temp_comm_1());
		(*net_signals)["BOARD_STATUS_CELLBOARD4"]["errors_temp_comm_2"].push(pack->board_status_cellboard4(i).errors_temp_comm_2());
		(*net_signals)["BOARD_STATUS_CELLBOARD4"]["errors_temp_comm_3"].push(pack->board_status_cellboard4(i).errors_temp_comm_3());
		(*net_signals)["BOARD_STATUS_CELLBOARD4"]["errors_temp_comm_4"].push(pack->board_status_cellboard4(i).errors_temp_comm_4());
		(*net_signals)["BOARD_STATUS_CELLBOARD4"]["errors_temp_comm_5"].push(pack->board_status_cellboard4(i).errors_temp_comm_5());
		(*net_signals)["BOARD_STATUS_CELLBOARD4"]["errors_open_wire"].push(pack->board_status_cellboard4(i).errors_open_wire());
		(*net_enums)["BOARD_STATUS_CELLBOARD4"]["balancing_status"].push(pack->board_status_cellboard4(i).balancing_status());
		bms_board_status_cellboard4_balancing_status_enum_to_string((bms_board_status_cellboard4_balancing_status)pack->board_status_cellboard4(i).balancing_status(), buffer);
		(*net_strings)["BOARD_STATUS_CELLBOARD4"]["balancing_status"].push(buffer);

    }

    for(int i = 0; i < pack->board_status_cellboard5_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->board_status_cellboard5(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->board_status_cellboard5(i)._inner_timestamp();
        (*net_signals)["BOARD_STATUS_CELLBOARD5"]["_timestamp"].push(pack->board_status_cellboard5(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["BOARD_STATUS_CELLBOARD5"]["errors_can_comm"].push(pack->board_status_cellboard5(i).errors_can_comm());
		(*net_signals)["BOARD_STATUS_CELLBOARD5"]["errors_ltc_comm"].push(pack->board_status_cellboard5(i).errors_ltc_comm());
		(*net_signals)["BOARD_STATUS_CELLBOARD5"]["errors_temp_comm_0"].push(pack->board_status_cellboard5(i).errors_temp_comm_0());
		(*net_signals)["BOARD_STATUS_CELLBOARD5"]["errors_temp_comm_1"].push(pack->board_status_cellboard5(i).errors_temp_comm_1());
		(*net_signals)["BOARD_STATUS_CELLBOARD5"]["errors_temp_comm_2"].push(pack->board_status_cellboard5(i).errors_temp_comm_2());
		(*net_signals)["BOARD_STATUS_CELLBOARD5"]["errors_temp_comm_3"].push(pack->board_status_cellboard5(i).errors_temp_comm_3());
		(*net_signals)["BOARD_STATUS_CELLBOARD5"]["errors_temp_comm_4"].push(pack->board_status_cellboard5(i).errors_temp_comm_4());
		(*net_signals)["BOARD_STATUS_CELLBOARD5"]["errors_temp_comm_5"].push(pack->board_status_cellboard5(i).errors_temp_comm_5());
		(*net_signals)["BOARD_STATUS_CELLBOARD5"]["errors_open_wire"].push(pack->board_status_cellboard5(i).errors_open_wire());
		(*net_enums)["BOARD_STATUS_CELLBOARD5"]["balancing_status"].push(pack->board_status_cellboard5(i).balancing_status());
		bms_board_status_cellboard5_balancing_status_enum_to_string((bms_board_status_cellboard5_balancing_status)pack->board_status_cellboard5(i).balancing_status(), buffer);
		(*net_strings)["BOARD_STATUS_CELLBOARD5"]["balancing_status"].push(buffer);

    }

    for(int i = 0; i < pack->temperatures_cellboard0_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->temperatures_cellboard0(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->temperatures_cellboard0(i)._inner_timestamp();
        (*net_signals)["TEMPERATURES_CELLBOARD0"]["_timestamp"].push(pack->temperatures_cellboard0(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["TEMPERATURES_CELLBOARD0"]["start_index"].push(pack->temperatures_cellboard0(i).start_index());
		(*net_signals)["TEMPERATURES_CELLBOARD0"]["temp0"].push(pack->temperatures_cellboard0(i).temp0());
		(*net_signals)["TEMPERATURES_CELLBOARD0"]["temp1"].push(pack->temperatures_cellboard0(i).temp1());
		(*net_signals)["TEMPERATURES_CELLBOARD0"]["temp2"].push(pack->temperatures_cellboard0(i).temp2());
		(*net_signals)["TEMPERATURES_CELLBOARD0"]["temp3"].push(pack->temperatures_cellboard0(i).temp3());
		(*net_signals)["TEMPERATURES_CELLBOARD0"]["temp4"].push(pack->temperatures_cellboard0(i).temp4());
		(*net_signals)["TEMPERATURES_CELLBOARD0"]["temp5"].push(pack->temperatures_cellboard0(i).temp5());

    }

    for(int i = 0; i < pack->temperatures_cellboard1_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->temperatures_cellboard1(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->temperatures_cellboard1(i)._inner_timestamp();
        (*net_signals)["TEMPERATURES_CELLBOARD1"]["_timestamp"].push(pack->temperatures_cellboard1(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["TEMPERATURES_CELLBOARD1"]["start_index"].push(pack->temperatures_cellboard1(i).start_index());
		(*net_signals)["TEMPERATURES_CELLBOARD1"]["temp0"].push(pack->temperatures_cellboard1(i).temp0());
		(*net_signals)["TEMPERATURES_CELLBOARD1"]["temp1"].push(pack->temperatures_cellboard1(i).temp1());
		(*net_signals)["TEMPERATURES_CELLBOARD1"]["temp2"].push(pack->temperatures_cellboard1(i).temp2());
		(*net_signals)["TEMPERATURES_CELLBOARD1"]["temp3"].push(pack->temperatures_cellboard1(i).temp3());
		(*net_signals)["TEMPERATURES_CELLBOARD1"]["temp4"].push(pack->temperatures_cellboard1(i).temp4());
		(*net_signals)["TEMPERATURES_CELLBOARD1"]["temp5"].push(pack->temperatures_cellboard1(i).temp5());

    }

    for(int i = 0; i < pack->temperatures_cellboard2_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->temperatures_cellboard2(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->temperatures_cellboard2(i)._inner_timestamp();
        (*net_signals)["TEMPERATURES_CELLBOARD2"]["_timestamp"].push(pack->temperatures_cellboard2(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["TEMPERATURES_CELLBOARD2"]["start_index"].push(pack->temperatures_cellboard2(i).start_index());
		(*net_signals)["TEMPERATURES_CELLBOARD2"]["temp0"].push(pack->temperatures_cellboard2(i).temp0());
		(*net_signals)["TEMPERATURES_CELLBOARD2"]["temp1"].push(pack->temperatures_cellboard2(i).temp1());
		(*net_signals)["TEMPERATURES_CELLBOARD2"]["temp2"].push(pack->temperatures_cellboard2(i).temp2());
		(*net_signals)["TEMPERATURES_CELLBOARD2"]["temp3"].push(pack->temperatures_cellboard2(i).temp3());
		(*net_signals)["TEMPERATURES_CELLBOARD2"]["temp4"].push(pack->temperatures_cellboard2(i).temp4());
		(*net_signals)["TEMPERATURES_CELLBOARD2"]["temp5"].push(pack->temperatures_cellboard2(i).temp5());

    }

    for(int i = 0; i < pack->temperatures_cellboard3_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->temperatures_cellboard3(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->temperatures_cellboard3(i)._inner_timestamp();
        (*net_signals)["TEMPERATURES_CELLBOARD3"]["_timestamp"].push(pack->temperatures_cellboard3(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["TEMPERATURES_CELLBOARD3"]["start_index"].push(pack->temperatures_cellboard3(i).start_index());
		(*net_signals)["TEMPERATURES_CELLBOARD3"]["temp0"].push(pack->temperatures_cellboard3(i).temp0());
		(*net_signals)["TEMPERATURES_CELLBOARD3"]["temp1"].push(pack->temperatures_cellboard3(i).temp1());
		(*net_signals)["TEMPERATURES_CELLBOARD3"]["temp2"].push(pack->temperatures_cellboard3(i).temp2());
		(*net_signals)["TEMPERATURES_CELLBOARD3"]["temp3"].push(pack->temperatures_cellboard3(i).temp3());
		(*net_signals)["TEMPERATURES_CELLBOARD3"]["temp4"].push(pack->temperatures_cellboard3(i).temp4());
		(*net_signals)["TEMPERATURES_CELLBOARD3"]["temp5"].push(pack->temperatures_cellboard3(i).temp5());

    }

    for(int i = 0; i < pack->temperatures_cellboard4_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->temperatures_cellboard4(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->temperatures_cellboard4(i)._inner_timestamp();
        (*net_signals)["TEMPERATURES_CELLBOARD4"]["_timestamp"].push(pack->temperatures_cellboard4(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["TEMPERATURES_CELLBOARD4"]["start_index"].push(pack->temperatures_cellboard4(i).start_index());
		(*net_signals)["TEMPERATURES_CELLBOARD4"]["temp0"].push(pack->temperatures_cellboard4(i).temp0());
		(*net_signals)["TEMPERATURES_CELLBOARD4"]["temp1"].push(pack->temperatures_cellboard4(i).temp1());
		(*net_signals)["TEMPERATURES_CELLBOARD4"]["temp2"].push(pack->temperatures_cellboard4(i).temp2());
		(*net_signals)["TEMPERATURES_CELLBOARD4"]["temp3"].push(pack->temperatures_cellboard4(i).temp3());
		(*net_signals)["TEMPERATURES_CELLBOARD4"]["temp4"].push(pack->temperatures_cellboard4(i).temp4());
		(*net_signals)["TEMPERATURES_CELLBOARD4"]["temp5"].push(pack->temperatures_cellboard4(i).temp5());

    }

    for(int i = 0; i < pack->temperatures_cellboard5_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->temperatures_cellboard5(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->temperatures_cellboard5(i)._inner_timestamp();
        (*net_signals)["TEMPERATURES_CELLBOARD5"]["_timestamp"].push(pack->temperatures_cellboard5(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["TEMPERATURES_CELLBOARD5"]["start_index"].push(pack->temperatures_cellboard5(i).start_index());
		(*net_signals)["TEMPERATURES_CELLBOARD5"]["temp0"].push(pack->temperatures_cellboard5(i).temp0());
		(*net_signals)["TEMPERATURES_CELLBOARD5"]["temp1"].push(pack->temperatures_cellboard5(i).temp1());
		(*net_signals)["TEMPERATURES_CELLBOARD5"]["temp2"].push(pack->temperatures_cellboard5(i).temp2());
		(*net_signals)["TEMPERATURES_CELLBOARD5"]["temp3"].push(pack->temperatures_cellboard5(i).temp3());
		(*net_signals)["TEMPERATURES_CELLBOARD5"]["temp4"].push(pack->temperatures_cellboard5(i).temp4());
		(*net_signals)["TEMPERATURES_CELLBOARD5"]["temp5"].push(pack->temperatures_cellboard5(i).temp5());

    }

    for(int i = 0; i < pack->voltages_cellboard0_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->voltages_cellboard0(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->voltages_cellboard0(i)._inner_timestamp();
        (*net_signals)["VOLTAGES_CELLBOARD0"]["_timestamp"].push(pack->voltages_cellboard0(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["VOLTAGES_CELLBOARD0"]["start_index"].push(pack->voltages_cellboard0(i).start_index());
		(*net_signals)["VOLTAGES_CELLBOARD0"]["voltage0"].push(pack->voltages_cellboard0(i).voltage0());
		(*net_signals)["VOLTAGES_CELLBOARD0"]["voltage1"].push(pack->voltages_cellboard0(i).voltage1());
		(*net_signals)["VOLTAGES_CELLBOARD0"]["voltage2"].push(pack->voltages_cellboard0(i).voltage2());

    }

    for(int i = 0; i < pack->voltages_cellboard1_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->voltages_cellboard1(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->voltages_cellboard1(i)._inner_timestamp();
        (*net_signals)["VOLTAGES_CELLBOARD1"]["_timestamp"].push(pack->voltages_cellboard1(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["VOLTAGES_CELLBOARD1"]["start_index"].push(pack->voltages_cellboard1(i).start_index());
		(*net_signals)["VOLTAGES_CELLBOARD1"]["voltage0"].push(pack->voltages_cellboard1(i).voltage0());
		(*net_signals)["VOLTAGES_CELLBOARD1"]["voltage1"].push(pack->voltages_cellboard1(i).voltage1());
		(*net_signals)["VOLTAGES_CELLBOARD1"]["voltage2"].push(pack->voltages_cellboard1(i).voltage2());

    }

    for(int i = 0; i < pack->voltages_cellboard2_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->voltages_cellboard2(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->voltages_cellboard2(i)._inner_timestamp();
        (*net_signals)["VOLTAGES_CELLBOARD2"]["_timestamp"].push(pack->voltages_cellboard2(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["VOLTAGES_CELLBOARD2"]["start_index"].push(pack->voltages_cellboard2(i).start_index());
		(*net_signals)["VOLTAGES_CELLBOARD2"]["voltage0"].push(pack->voltages_cellboard2(i).voltage0());
		(*net_signals)["VOLTAGES_CELLBOARD2"]["voltage1"].push(pack->voltages_cellboard2(i).voltage1());
		(*net_signals)["VOLTAGES_CELLBOARD2"]["voltage2"].push(pack->voltages_cellboard2(i).voltage2());

    }

    for(int i = 0; i < pack->voltages_cellboard3_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->voltages_cellboard3(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->voltages_cellboard3(i)._inner_timestamp();
        (*net_signals)["VOLTAGES_CELLBOARD3"]["_timestamp"].push(pack->voltages_cellboard3(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["VOLTAGES_CELLBOARD3"]["start_index"].push(pack->voltages_cellboard3(i).start_index());
		(*net_signals)["VOLTAGES_CELLBOARD3"]["voltage0"].push(pack->voltages_cellboard3(i).voltage0());
		(*net_signals)["VOLTAGES_CELLBOARD3"]["voltage1"].push(pack->voltages_cellboard3(i).voltage1());
		(*net_signals)["VOLTAGES_CELLBOARD3"]["voltage2"].push(pack->voltages_cellboard3(i).voltage2());

    }

    for(int i = 0; i < pack->voltages_cellboard4_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->voltages_cellboard4(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->voltages_cellboard4(i)._inner_timestamp();
        (*net_signals)["VOLTAGES_CELLBOARD4"]["_timestamp"].push(pack->voltages_cellboard4(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["VOLTAGES_CELLBOARD4"]["start_index"].push(pack->voltages_cellboard4(i).start_index());
		(*net_signals)["VOLTAGES_CELLBOARD4"]["voltage0"].push(pack->voltages_cellboard4(i).voltage0());
		(*net_signals)["VOLTAGES_CELLBOARD4"]["voltage1"].push(pack->voltages_cellboard4(i).voltage1());
		(*net_signals)["VOLTAGES_CELLBOARD4"]["voltage2"].push(pack->voltages_cellboard4(i).voltage2());

    }

    for(int i = 0; i < pack->voltages_cellboard5_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->voltages_cellboard5(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->voltages_cellboard5(i)._inner_timestamp();
        (*net_signals)["VOLTAGES_CELLBOARD5"]["_timestamp"].push(pack->voltages_cellboard5(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["VOLTAGES_CELLBOARD5"]["start_index"].push(pack->voltages_cellboard5(i).start_index());
		(*net_signals)["VOLTAGES_CELLBOARD5"]["voltage0"].push(pack->voltages_cellboard5(i).voltage0());
		(*net_signals)["VOLTAGES_CELLBOARD5"]["voltage1"].push(pack->voltages_cellboard5(i).voltage1());
		(*net_signals)["VOLTAGES_CELLBOARD5"]["voltage2"].push(pack->voltages_cellboard5(i).voltage2());

    }

    for(int i = 0; i < pack->balancing_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->balancing(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->balancing(i)._inner_timestamp();
        (*net_signals)["BALANCING"]["_timestamp"].push(pack->balancing(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["BALANCING"]["board_index"].push(pack->balancing(i).board_index());
		(*net_signals)["BALANCING"]["cells_cell0"].push(pack->balancing(i).cells_cell0());
		(*net_signals)["BALANCING"]["cells_cell1"].push(pack->balancing(i).cells_cell1());
		(*net_signals)["BALANCING"]["cells_cell2"].push(pack->balancing(i).cells_cell2());
		(*net_signals)["BALANCING"]["cells_cell3"].push(pack->balancing(i).cells_cell3());
		(*net_signals)["BALANCING"]["cells_cell4"].push(pack->balancing(i).cells_cell4());
		(*net_signals)["BALANCING"]["cells_cell5"].push(pack->balancing(i).cells_cell5());
		(*net_signals)["BALANCING"]["cells_cell6"].push(pack->balancing(i).cells_cell6());
		(*net_signals)["BALANCING"]["cells_cell7"].push(pack->balancing(i).cells_cell7());
		(*net_signals)["BALANCING"]["cells_cell8"].push(pack->balancing(i).cells_cell8());
		(*net_signals)["BALANCING"]["cells_cell9"].push(pack->balancing(i).cells_cell9());
		(*net_signals)["BALANCING"]["cells_cell10"].push(pack->balancing(i).cells_cell10());
		(*net_signals)["BALANCING"]["cells_cell11"].push(pack->balancing(i).cells_cell11());
		(*net_signals)["BALANCING"]["cells_cell12"].push(pack->balancing(i).cells_cell12());
		(*net_signals)["BALANCING"]["cells_cell13"].push(pack->balancing(i).cells_cell13());
		(*net_signals)["BALANCING"]["cells_cell14"].push(pack->balancing(i).cells_cell14());
		(*net_signals)["BALANCING"]["cells_cell15"].push(pack->balancing(i).cells_cell15());
		(*net_signals)["BALANCING"]["cells_cell16"].push(pack->balancing(i).cells_cell16());
		(*net_signals)["BALANCING"]["cells_cell17"].push(pack->balancing(i).cells_cell17());

    }

    for(int i = 0; i < pack->fw_update_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->fw_update(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->fw_update(i)._inner_timestamp();
        (*net_signals)["FW_UPDATE"]["_timestamp"].push(pack->fw_update(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["FW_UPDATE"]["board_index"].push(pack->fw_update(i).board_index());

    }

    for(int i = 0; i < pack->flash_cellboard_0_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->flash_cellboard_0_tx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->flash_cellboard_0_tx(i)._inner_timestamp();
        (*net_signals)["FLASH_CELLBOARD_0_TX"]["_timestamp"].push(pack->flash_cellboard_0_tx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->flash_cellboard_0_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->flash_cellboard_0_rx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->flash_cellboard_0_rx(i)._inner_timestamp();
        (*net_signals)["FLASH_CELLBOARD_0_RX"]["_timestamp"].push(pack->flash_cellboard_0_rx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->flash_cellboard_1_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->flash_cellboard_1_tx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->flash_cellboard_1_tx(i)._inner_timestamp();
        (*net_signals)["FLASH_CELLBOARD_1_TX"]["_timestamp"].push(pack->flash_cellboard_1_tx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->flash_cellboard_1_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->flash_cellboard_1_rx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->flash_cellboard_1_rx(i)._inner_timestamp();
        (*net_signals)["FLASH_CELLBOARD_1_RX"]["_timestamp"].push(pack->flash_cellboard_1_rx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->flash_cellboard_2_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->flash_cellboard_2_tx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->flash_cellboard_2_tx(i)._inner_timestamp();
        (*net_signals)["FLASH_CELLBOARD_2_TX"]["_timestamp"].push(pack->flash_cellboard_2_tx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->flash_cellboard_2_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->flash_cellboard_2_rx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->flash_cellboard_2_rx(i)._inner_timestamp();
        (*net_signals)["FLASH_CELLBOARD_2_RX"]["_timestamp"].push(pack->flash_cellboard_2_rx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->flash_cellboard_3_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->flash_cellboard_3_tx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->flash_cellboard_3_tx(i)._inner_timestamp();
        (*net_signals)["FLASH_CELLBOARD_3_TX"]["_timestamp"].push(pack->flash_cellboard_3_tx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->flash_cellboard_3_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->flash_cellboard_3_rx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->flash_cellboard_3_rx(i)._inner_timestamp();
        (*net_signals)["FLASH_CELLBOARD_3_RX"]["_timestamp"].push(pack->flash_cellboard_3_rx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->flash_cellboard_4_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->flash_cellboard_4_tx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->flash_cellboard_4_tx(i)._inner_timestamp();
        (*net_signals)["FLASH_CELLBOARD_4_TX"]["_timestamp"].push(pack->flash_cellboard_4_tx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->flash_cellboard_4_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->flash_cellboard_4_rx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->flash_cellboard_4_rx(i)._inner_timestamp();
        (*net_signals)["FLASH_CELLBOARD_4_RX"]["_timestamp"].push(pack->flash_cellboard_4_rx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->flash_cellboard_5_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->flash_cellboard_5_tx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->flash_cellboard_5_tx(i)._inner_timestamp();
        (*net_signals)["FLASH_CELLBOARD_5_TX"]["_timestamp"].push(pack->flash_cellboard_5_tx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->flash_cellboard_5_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->flash_cellboard_5_rx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->flash_cellboard_5_rx(i)._inner_timestamp();
        (*net_signals)["FLASH_CELLBOARD_5_RX"]["_timestamp"].push(pack->flash_cellboard_5_rx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

}

void bms_proto_interface_serialize_from_id(canlib_message_id id, bms::Pack* pack, bms_devices* map) {
    int index = bms_index_from_id(id);

    if (index == -1) return;

    switch(id) {
        
        case 1539: {
            bms_board_status_cellboard0_t* msg = (bms_board_status_cellboard0_t*)((*map)[index].message_raw);
            bms::BOARD_STATUS_CELLBOARD0* proto_msg = pack->add_board_status_cellboard0();
			proto_msg->set_errors_can_comm(msg->errors_can_comm);
			proto_msg->set_errors_ltc_comm(msg->errors_ltc_comm);
			proto_msg->set_errors_temp_comm_0(msg->errors_temp_comm_0);
			proto_msg->set_errors_temp_comm_1(msg->errors_temp_comm_1);
			proto_msg->set_errors_temp_comm_2(msg->errors_temp_comm_2);
			proto_msg->set_errors_temp_comm_3(msg->errors_temp_comm_3);
			proto_msg->set_errors_temp_comm_4(msg->errors_temp_comm_4);
			proto_msg->set_errors_temp_comm_5(msg->errors_temp_comm_5);
			proto_msg->set_errors_open_wire(msg->errors_open_wire);
			proto_msg->set_balancing_status((bms::bms_board_status_cellboard0_balancing_status)msg->balancing_status);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1571: {
            bms_board_status_cellboard1_t* msg = (bms_board_status_cellboard1_t*)((*map)[index].message_raw);
            bms::BOARD_STATUS_CELLBOARD1* proto_msg = pack->add_board_status_cellboard1();
			proto_msg->set_errors_can_comm(msg->errors_can_comm);
			proto_msg->set_errors_ltc_comm(msg->errors_ltc_comm);
			proto_msg->set_errors_temp_comm_0(msg->errors_temp_comm_0);
			proto_msg->set_errors_temp_comm_1(msg->errors_temp_comm_1);
			proto_msg->set_errors_temp_comm_2(msg->errors_temp_comm_2);
			proto_msg->set_errors_temp_comm_3(msg->errors_temp_comm_3);
			proto_msg->set_errors_temp_comm_4(msg->errors_temp_comm_4);
			proto_msg->set_errors_temp_comm_5(msg->errors_temp_comm_5);
			proto_msg->set_errors_open_wire(msg->errors_open_wire);
			proto_msg->set_balancing_status((bms::bms_board_status_cellboard1_balancing_status)msg->balancing_status);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1603: {
            bms_board_status_cellboard2_t* msg = (bms_board_status_cellboard2_t*)((*map)[index].message_raw);
            bms::BOARD_STATUS_CELLBOARD2* proto_msg = pack->add_board_status_cellboard2();
			proto_msg->set_errors_can_comm(msg->errors_can_comm);
			proto_msg->set_errors_ltc_comm(msg->errors_ltc_comm);
			proto_msg->set_errors_temp_comm_0(msg->errors_temp_comm_0);
			proto_msg->set_errors_temp_comm_1(msg->errors_temp_comm_1);
			proto_msg->set_errors_temp_comm_2(msg->errors_temp_comm_2);
			proto_msg->set_errors_temp_comm_3(msg->errors_temp_comm_3);
			proto_msg->set_errors_temp_comm_4(msg->errors_temp_comm_4);
			proto_msg->set_errors_temp_comm_5(msg->errors_temp_comm_5);
			proto_msg->set_errors_open_wire(msg->errors_open_wire);
			proto_msg->set_balancing_status((bms::bms_board_status_cellboard2_balancing_status)msg->balancing_status);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1635: {
            bms_board_status_cellboard3_t* msg = (bms_board_status_cellboard3_t*)((*map)[index].message_raw);
            bms::BOARD_STATUS_CELLBOARD3* proto_msg = pack->add_board_status_cellboard3();
			proto_msg->set_errors_can_comm(msg->errors_can_comm);
			proto_msg->set_errors_ltc_comm(msg->errors_ltc_comm);
			proto_msg->set_errors_temp_comm_0(msg->errors_temp_comm_0);
			proto_msg->set_errors_temp_comm_1(msg->errors_temp_comm_1);
			proto_msg->set_errors_temp_comm_2(msg->errors_temp_comm_2);
			proto_msg->set_errors_temp_comm_3(msg->errors_temp_comm_3);
			proto_msg->set_errors_temp_comm_4(msg->errors_temp_comm_4);
			proto_msg->set_errors_temp_comm_5(msg->errors_temp_comm_5);
			proto_msg->set_errors_open_wire(msg->errors_open_wire);
			proto_msg->set_balancing_status((bms::bms_board_status_cellboard3_balancing_status)msg->balancing_status);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1667: {
            bms_board_status_cellboard4_t* msg = (bms_board_status_cellboard4_t*)((*map)[index].message_raw);
            bms::BOARD_STATUS_CELLBOARD4* proto_msg = pack->add_board_status_cellboard4();
			proto_msg->set_errors_can_comm(msg->errors_can_comm);
			proto_msg->set_errors_ltc_comm(msg->errors_ltc_comm);
			proto_msg->set_errors_temp_comm_0(msg->errors_temp_comm_0);
			proto_msg->set_errors_temp_comm_1(msg->errors_temp_comm_1);
			proto_msg->set_errors_temp_comm_2(msg->errors_temp_comm_2);
			proto_msg->set_errors_temp_comm_3(msg->errors_temp_comm_3);
			proto_msg->set_errors_temp_comm_4(msg->errors_temp_comm_4);
			proto_msg->set_errors_temp_comm_5(msg->errors_temp_comm_5);
			proto_msg->set_errors_open_wire(msg->errors_open_wire);
			proto_msg->set_balancing_status((bms::bms_board_status_cellboard4_balancing_status)msg->balancing_status);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1699: {
            bms_board_status_cellboard5_t* msg = (bms_board_status_cellboard5_t*)((*map)[index].message_raw);
            bms::BOARD_STATUS_CELLBOARD5* proto_msg = pack->add_board_status_cellboard5();
			proto_msg->set_errors_can_comm(msg->errors_can_comm);
			proto_msg->set_errors_ltc_comm(msg->errors_ltc_comm);
			proto_msg->set_errors_temp_comm_0(msg->errors_temp_comm_0);
			proto_msg->set_errors_temp_comm_1(msg->errors_temp_comm_1);
			proto_msg->set_errors_temp_comm_2(msg->errors_temp_comm_2);
			proto_msg->set_errors_temp_comm_3(msg->errors_temp_comm_3);
			proto_msg->set_errors_temp_comm_4(msg->errors_temp_comm_4);
			proto_msg->set_errors_temp_comm_5(msg->errors_temp_comm_5);
			proto_msg->set_errors_open_wire(msg->errors_open_wire);
			proto_msg->set_balancing_status((bms::bms_board_status_cellboard5_balancing_status)msg->balancing_status);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1280: {
            bms_temperatures_cellboard0_converted_t* msg = (bms_temperatures_cellboard0_converted_t*)((*map)[index].message_conversion);
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

        case 1312: {
            bms_temperatures_cellboard1_converted_t* msg = (bms_temperatures_cellboard1_converted_t*)((*map)[index].message_conversion);
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

        case 1344: {
            bms_temperatures_cellboard2_converted_t* msg = (bms_temperatures_cellboard2_converted_t*)((*map)[index].message_conversion);
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

        case 1376: {
            bms_temperatures_cellboard3_converted_t* msg = (bms_temperatures_cellboard3_converted_t*)((*map)[index].message_conversion);
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

        case 1408: {
            bms_temperatures_cellboard4_converted_t* msg = (bms_temperatures_cellboard4_converted_t*)((*map)[index].message_conversion);
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

        case 1440: {
            bms_temperatures_cellboard5_converted_t* msg = (bms_temperatures_cellboard5_converted_t*)((*map)[index].message_conversion);
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

        case 513: {
            bms_voltages_cellboard0_converted_t* msg = (bms_voltages_cellboard0_converted_t*)((*map)[index].message_conversion);
            bms::VOLTAGES_CELLBOARD0* proto_msg = pack->add_voltages_cellboard0();
			proto_msg->set_start_index(msg->start_index);
			proto_msg->set_voltage0(msg->voltage0);
			proto_msg->set_voltage1(msg->voltage1);
			proto_msg->set_voltage2(msg->voltage2);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 545: {
            bms_voltages_cellboard1_converted_t* msg = (bms_voltages_cellboard1_converted_t*)((*map)[index].message_conversion);
            bms::VOLTAGES_CELLBOARD1* proto_msg = pack->add_voltages_cellboard1();
			proto_msg->set_start_index(msg->start_index);
			proto_msg->set_voltage0(msg->voltage0);
			proto_msg->set_voltage1(msg->voltage1);
			proto_msg->set_voltage2(msg->voltage2);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 577: {
            bms_voltages_cellboard2_converted_t* msg = (bms_voltages_cellboard2_converted_t*)((*map)[index].message_conversion);
            bms::VOLTAGES_CELLBOARD2* proto_msg = pack->add_voltages_cellboard2();
			proto_msg->set_start_index(msg->start_index);
			proto_msg->set_voltage0(msg->voltage0);
			proto_msg->set_voltage1(msg->voltage1);
			proto_msg->set_voltage2(msg->voltage2);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 609: {
            bms_voltages_cellboard3_converted_t* msg = (bms_voltages_cellboard3_converted_t*)((*map)[index].message_conversion);
            bms::VOLTAGES_CELLBOARD3* proto_msg = pack->add_voltages_cellboard3();
			proto_msg->set_start_index(msg->start_index);
			proto_msg->set_voltage0(msg->voltage0);
			proto_msg->set_voltage1(msg->voltage1);
			proto_msg->set_voltage2(msg->voltage2);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 641: {
            bms_voltages_cellboard4_converted_t* msg = (bms_voltages_cellboard4_converted_t*)((*map)[index].message_conversion);
            bms::VOLTAGES_CELLBOARD4* proto_msg = pack->add_voltages_cellboard4();
			proto_msg->set_start_index(msg->start_index);
			proto_msg->set_voltage0(msg->voltage0);
			proto_msg->set_voltage1(msg->voltage1);
			proto_msg->set_voltage2(msg->voltage2);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 673: {
            bms_voltages_cellboard5_converted_t* msg = (bms_voltages_cellboard5_converted_t*)((*map)[index].message_conversion);
            bms::VOLTAGES_CELLBOARD5* proto_msg = pack->add_voltages_cellboard5();
			proto_msg->set_start_index(msg->start_index);
			proto_msg->set_voltage0(msg->voltage0);
			proto_msg->set_voltage1(msg->voltage1);
			proto_msg->set_voltage2(msg->voltage2);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 514: {
            bms_balancing_t* msg = (bms_balancing_t*)((*map)[index].message_raw);
            bms::BALANCING* proto_msg = pack->add_balancing();
			proto_msg->set_board_index(msg->board_index);
			proto_msg->set_cells_cell0(msg->cells_cell0);
			proto_msg->set_cells_cell1(msg->cells_cell1);
			proto_msg->set_cells_cell2(msg->cells_cell2);
			proto_msg->set_cells_cell3(msg->cells_cell3);
			proto_msg->set_cells_cell4(msg->cells_cell4);
			proto_msg->set_cells_cell5(msg->cells_cell5);
			proto_msg->set_cells_cell6(msg->cells_cell6);
			proto_msg->set_cells_cell7(msg->cells_cell7);
			proto_msg->set_cells_cell8(msg->cells_cell8);
			proto_msg->set_cells_cell9(msg->cells_cell9);
			proto_msg->set_cells_cell10(msg->cells_cell10);
			proto_msg->set_cells_cell11(msg->cells_cell11);
			proto_msg->set_cells_cell12(msg->cells_cell12);
			proto_msg->set_cells_cell13(msg->cells_cell13);
			proto_msg->set_cells_cell14(msg->cells_cell14);
			proto_msg->set_cells_cell15(msg->cells_cell15);
			proto_msg->set_cells_cell16(msg->cells_cell16);
			proto_msg->set_cells_cell17(msg->cells_cell17);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 10: {
            bms_fw_update_t* msg = (bms_fw_update_t*)((*map)[index].message_raw);
            bms::FW_UPDATE* proto_msg = pack->add_fw_update();
			proto_msg->set_board_index(msg->board_index);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 16: {
            bms_flash_cellboard_0_tx_t* msg = (bms_flash_cellboard_0_tx_t*)((*map)[index].message_raw);
            bms::FLASH_CELLBOARD_0_TX* proto_msg = pack->add_flash_cellboard_0_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 17: {
            bms_flash_cellboard_0_rx_t* msg = (bms_flash_cellboard_0_rx_t*)((*map)[index].message_raw);
            bms::FLASH_CELLBOARD_0_RX* proto_msg = pack->add_flash_cellboard_0_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 18: {
            bms_flash_cellboard_1_tx_t* msg = (bms_flash_cellboard_1_tx_t*)((*map)[index].message_raw);
            bms::FLASH_CELLBOARD_1_TX* proto_msg = pack->add_flash_cellboard_1_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 19: {
            bms_flash_cellboard_1_rx_t* msg = (bms_flash_cellboard_1_rx_t*)((*map)[index].message_raw);
            bms::FLASH_CELLBOARD_1_RX* proto_msg = pack->add_flash_cellboard_1_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 20: {
            bms_flash_cellboard_2_tx_t* msg = (bms_flash_cellboard_2_tx_t*)((*map)[index].message_raw);
            bms::FLASH_CELLBOARD_2_TX* proto_msg = pack->add_flash_cellboard_2_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 21: {
            bms_flash_cellboard_2_rx_t* msg = (bms_flash_cellboard_2_rx_t*)((*map)[index].message_raw);
            bms::FLASH_CELLBOARD_2_RX* proto_msg = pack->add_flash_cellboard_2_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 22: {
            bms_flash_cellboard_3_tx_t* msg = (bms_flash_cellboard_3_tx_t*)((*map)[index].message_raw);
            bms::FLASH_CELLBOARD_3_TX* proto_msg = pack->add_flash_cellboard_3_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 23: {
            bms_flash_cellboard_3_rx_t* msg = (bms_flash_cellboard_3_rx_t*)((*map)[index].message_raw);
            bms::FLASH_CELLBOARD_3_RX* proto_msg = pack->add_flash_cellboard_3_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 24: {
            bms_flash_cellboard_4_tx_t* msg = (bms_flash_cellboard_4_tx_t*)((*map)[index].message_raw);
            bms::FLASH_CELLBOARD_4_TX* proto_msg = pack->add_flash_cellboard_4_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 25: {
            bms_flash_cellboard_4_rx_t* msg = (bms_flash_cellboard_4_rx_t*)((*map)[index].message_raw);
            bms::FLASH_CELLBOARD_4_RX* proto_msg = pack->add_flash_cellboard_4_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 26: {
            bms_flash_cellboard_5_tx_t* msg = (bms_flash_cellboard_5_tx_t*)((*map)[index].message_raw);
            bms::FLASH_CELLBOARD_5_TX* proto_msg = pack->add_flash_cellboard_5_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 27: {
            bms_flash_cellboard_5_rx_t* msg = (bms_flash_cellboard_5_rx_t*)((*map)[index].message_raw);
            bms::FLASH_CELLBOARD_5_RX* proto_msg = pack->add_flash_cellboard_5_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

    }
}



#endif // bms_PROTO_INTERAFCE_IMPLEMENTATION

#endif // bms_PROTO_INTERFACE_H
