
#ifndef hv_current_PROTO_INTERFACE_H
#define hv_current_PROTO_INTERFACE_H

#include <string>
#include <unordered_map>
#include <functional>

#include "hv_current.pb.h"

#ifdef hv_current_IMPLEMENTATION
#undef hv_current_IMPLEMENTATION
#define __hv_current_IMPLEMENTATION
#endif

#include "../../lib/hv_current/hv_current_network.h"

#ifdef __hv_current_IMPLEMENTATION
#undef __hv_current_IMPLEMENTATION
#define hv_current_IMPLEMENTATION
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

void hv_current_proto_interface_serialize_from_id(canlib_message_id id, hv_current::Pack* pack, device_t* device);
void hv_current_proto_interface_deserialize(hv_current::Pack* pack, network_enums* net_enums, network_signals* net_signals, network_strings* net_strings, uint64_t resample_us);

#ifdef hv_current_PROTO_INTERAFCE_IMPLEMENTATION

void hv_current_proto_interface_deserialize(hv_current::Pack* pack, network_enums* net_enums, network_signals* net_signals, network_strings* net_strings, uint64_t resample_us) {
    char buffer[1024];
    
    for(int i = 0; i < pack->ivt_msg_result_wh_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->ivt_msg_result_wh(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->ivt_msg_result_wh(i)._inner_timestamp();
        (*net_signals)["IVT_MSG_RESULT_WH"]["_timestamp"].push(pack->ivt_msg_result_wh(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["IVT_MSG_RESULT_WH"]["ivt_id_result_wh"].push(pack->ivt_msg_result_wh(i).ivt_id_result_wh());
		hv_current_ivt_msg_result_wh_ivt_id_result_wh_enum_to_string((hv_current_ivt_msg_result_wh_ivt_id_result_wh)pack->ivt_msg_result_wh(i).ivt_id_result_wh(), buffer);
		(*net_strings)["IVT_MSG_RESULT_WH"]["ivt_id_result_wh"].push(buffer);
		(*net_signals)["IVT_MSG_RESULT_WH"]["ivt_result_wh_system_error"].push(pack->ivt_msg_result_wh(i).ivt_result_wh_system_error());
		(*net_signals)["IVT_MSG_RESULT_WH"]["ivt_result_wh_measurement_error"].push(pack->ivt_msg_result_wh(i).ivt_result_wh_measurement_error());
		(*net_signals)["IVT_MSG_RESULT_WH"]["ivt_result_wh_channel_error"].push(pack->ivt_msg_result_wh(i).ivt_result_wh_channel_error());
		(*net_signals)["IVT_MSG_RESULT_WH"]["ivt_result_wh_ocs"].push(pack->ivt_msg_result_wh(i).ivt_result_wh_ocs());
		(*net_signals)["IVT_MSG_RESULT_WH"]["ivt_msgcount_result_wh"].push(pack->ivt_msg_result_wh(i).ivt_msgcount_result_wh());
		(*net_signals)["IVT_MSG_RESULT_WH"]["ivt_result_wh"].push(pack->ivt_msg_result_wh(i).ivt_result_wh());

    }

    for(int i = 0; i < pack->ivt_msg_result_as_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->ivt_msg_result_as(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->ivt_msg_result_as(i)._inner_timestamp();
        (*net_signals)["IVT_MSG_RESULT_AS"]["_timestamp"].push(pack->ivt_msg_result_as(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["IVT_MSG_RESULT_AS"]["ivt_id_result_as"].push(pack->ivt_msg_result_as(i).ivt_id_result_as());
		hv_current_ivt_msg_result_as_ivt_id_result_as_enum_to_string((hv_current_ivt_msg_result_as_ivt_id_result_as)pack->ivt_msg_result_as(i).ivt_id_result_as(), buffer);
		(*net_strings)["IVT_MSG_RESULT_AS"]["ivt_id_result_as"].push(buffer);
		(*net_signals)["IVT_MSG_RESULT_AS"]["ivt_result_as_system_error"].push(pack->ivt_msg_result_as(i).ivt_result_as_system_error());
		(*net_signals)["IVT_MSG_RESULT_AS"]["ivt_result_as_measurement_error"].push(pack->ivt_msg_result_as(i).ivt_result_as_measurement_error());
		(*net_signals)["IVT_MSG_RESULT_AS"]["ivt_result_as_channel_error"].push(pack->ivt_msg_result_as(i).ivt_result_as_channel_error());
		(*net_signals)["IVT_MSG_RESULT_AS"]["ivt_result_as_ocs"].push(pack->ivt_msg_result_as(i).ivt_result_as_ocs());
		(*net_signals)["IVT_MSG_RESULT_AS"]["ivt_msgcount_result_as"].push(pack->ivt_msg_result_as(i).ivt_msgcount_result_as());
		(*net_signals)["IVT_MSG_RESULT_AS"]["ivt_result_as"].push(pack->ivt_msg_result_as(i).ivt_result_as());

    }

    for(int i = 0; i < pack->ivt_msg_result_w_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->ivt_msg_result_w(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->ivt_msg_result_w(i)._inner_timestamp();
        (*net_signals)["IVT_MSG_RESULT_W"]["_timestamp"].push(pack->ivt_msg_result_w(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["IVT_MSG_RESULT_W"]["ivt_id_result_w"].push(pack->ivt_msg_result_w(i).ivt_id_result_w());
		hv_current_ivt_msg_result_w_ivt_id_result_w_enum_to_string((hv_current_ivt_msg_result_w_ivt_id_result_w)pack->ivt_msg_result_w(i).ivt_id_result_w(), buffer);
		(*net_strings)["IVT_MSG_RESULT_W"]["ivt_id_result_w"].push(buffer);
		(*net_signals)["IVT_MSG_RESULT_W"]["ivt_result_w_system_error"].push(pack->ivt_msg_result_w(i).ivt_result_w_system_error());
		(*net_signals)["IVT_MSG_RESULT_W"]["ivt_result_w_measurement_error"].push(pack->ivt_msg_result_w(i).ivt_result_w_measurement_error());
		(*net_signals)["IVT_MSG_RESULT_W"]["ivt_result_w_channel_error"].push(pack->ivt_msg_result_w(i).ivt_result_w_channel_error());
		(*net_signals)["IVT_MSG_RESULT_W"]["ivt_result_w_ocs"].push(pack->ivt_msg_result_w(i).ivt_result_w_ocs());
		(*net_signals)["IVT_MSG_RESULT_W"]["ivt_msgcount_result_w"].push(pack->ivt_msg_result_w(i).ivt_msgcount_result_w());
		(*net_signals)["IVT_MSG_RESULT_W"]["ivt_result_w"].push(pack->ivt_msg_result_w(i).ivt_result_w());

    }

    for(int i = 0; i < pack->ivt_msg_response_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->ivt_msg_response(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->ivt_msg_response(i)._inner_timestamp();
        (*net_signals)["IVT_MSG_RESPONSE"]["_timestamp"].push(pack->ivt_msg_response(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["IVT_MSG_RESPONSE"]["ivt_id_response"].push(pack->ivt_msg_response(i).ivt_id_response());
		hv_current_ivt_msg_response_ivt_id_response_enum_to_string((hv_current_ivt_msg_response_ivt_id_response)pack->ivt_msg_response(i).ivt_id_response(), buffer);
		(*net_strings)["IVT_MSG_RESPONSE"]["ivt_id_response"].push(buffer);
		(*net_signals)["IVT_MSG_RESPONSE"]["_b1_trigger_spare"].push(pack->ivt_msg_response(i)._b1_trigger_spare());
		(*net_signals)["IVT_MSG_RESPONSE"]["_ff_wrong_command"].push(pack->ivt_msg_response(i)._ff_wrong_command());
		(*net_signals)["IVT_MSG_RESPONSE"]["_bf_restart_alive_cmd_id"].push(pack->ivt_msg_response(i)._bf_restart_alive_cmd_id());
		(*net_enums)["IVT_MSG_RESPONSE"]["_80_resp_measerror_item"].push(pack->ivt_msg_response(i)._80_resp_measerror_item());
		hv_current_ivt_msg_response__80_resp_measerror_item_enum_to_string((hv_current_ivt_msg_response__80_resp_measerror_item)pack->ivt_msg_response(i)._80_resp_measerror_item(), buffer);
		(*net_strings)["IVT_MSG_RESPONSE"]["_80_resp_measerror_item"].push(buffer);
		(*net_enums)["IVT_MSG_RESPONSE"]["_81_resp_systemerror_item"].push(pack->ivt_msg_response(i)._81_resp_systemerror_item());
		hv_current_ivt_msg_response__81_resp_systemerror_item_enum_to_string((hv_current_ivt_msg_response__81_resp_systemerror_item)pack->ivt_msg_response(i)._81_resp_systemerror_item(), buffer);
		(*net_strings)["IVT_MSG_RESPONSE"]["_81_resp_systemerror_item"].push(buffer);
		(*net_enums)["IVT_MSG_RESPONSE"]["_82_resp_alllogdata_item"].push(pack->ivt_msg_response(i)._82_resp_alllogdata_item());
		hv_current_ivt_msg_response__82_resp_alllogdata_item_enum_to_string((hv_current_ivt_msg_response__82_resp_alllogdata_item)pack->ivt_msg_response(i)._82_resp_alllogdata_item(), buffer);
		(*net_strings)["IVT_MSG_RESPONSE"]["_82_resp_alllogdata_item"].push(buffer);
		(*net_enums)["IVT_MSG_RESPONSE"]["_83_resp_logdata_item"].push(pack->ivt_msg_response(i)._83_resp_logdata_item());
		hv_current_ivt_msg_response__83_resp_logdata_item_enum_to_string((hv_current_ivt_msg_response__83_resp_logdata_item)pack->ivt_msg_response(i)._83_resp_logdata_item(), buffer);
		(*net_strings)["IVT_MSG_RESPONSE"]["_83_resp_logdata_item"].push(buffer);
		(*net_signals)["IVT_MSG_RESPONSE"]["_90_resp_can_id_val_i"].push(pack->ivt_msg_response(i)._90_resp_can_id_val_i());
		(*net_signals)["IVT_MSG_RESPONSE"]["_91_resp_can_id_val_u1"].push(pack->ivt_msg_response(i)._91_resp_can_id_val_u1());
		(*net_signals)["IVT_MSG_RESPONSE"]["_92_resp_can_id_val_u2"].push(pack->ivt_msg_response(i)._92_resp_can_id_val_u2());
		(*net_signals)["IVT_MSG_RESPONSE"]["_93_resp_can_id_val_u3"].push(pack->ivt_msg_response(i)._93_resp_can_id_val_u3());
		(*net_signals)["IVT_MSG_RESPONSE"]["_94_resp_can_id_val_t"].push(pack->ivt_msg_response(i)._94_resp_can_id_val_t());
		(*net_signals)["IVT_MSG_RESPONSE"]["_95_resp_can_id_val_w"].push(pack->ivt_msg_response(i)._95_resp_can_id_val_w());
		(*net_signals)["IVT_MSG_RESPONSE"]["_96_resp_can_id_val_as"].push(pack->ivt_msg_response(i)._96_resp_can_id_val_as());
		(*net_signals)["IVT_MSG_RESPONSE"]["_97_resp_can_id_val_wh"].push(pack->ivt_msg_response(i)._97_resp_can_id_val_wh());
		(*net_signals)["IVT_MSG_RESPONSE"]["_9d_resp_can_id_val_command"].push(pack->ivt_msg_response(i)._9d_resp_can_id_val_command());
		(*net_signals)["IVT_MSG_RESPONSE"]["_9f_resp_can_id_val_response"].push(pack->ivt_msg_response(i)._9f_resp_can_id_val_response());
		(*net_signals)["IVT_MSG_RESPONSE"]["_a0_resp_sign_i"].push(pack->ivt_msg_response(i)._a0_resp_sign_i());
		(*net_signals)["IVT_MSG_RESPONSE"]["_a1_resp_sign_u1"].push(pack->ivt_msg_response(i)._a1_resp_sign_u1());
		(*net_signals)["IVT_MSG_RESPONSE"]["_a2_resp_sign_u2"].push(pack->ivt_msg_response(i)._a2_resp_sign_u2());
		(*net_signals)["IVT_MSG_RESPONSE"]["_a3_resp_sign_u3"].push(pack->ivt_msg_response(i)._a3_resp_sign_u3());
		(*net_signals)["IVT_MSG_RESPONSE"]["_a4_resp_sign_t"].push(pack->ivt_msg_response(i)._a4_resp_sign_t());
		(*net_signals)["IVT_MSG_RESPONSE"]["_a5_resp_sign_w"].push(pack->ivt_msg_response(i)._a5_resp_sign_w());
		(*net_signals)["IVT_MSG_RESPONSE"]["_a6_resp_sign_as"].push(pack->ivt_msg_response(i)._a6_resp_sign_as());
		(*net_signals)["IVT_MSG_RESPONSE"]["_a7_resp_sign_wh"].push(pack->ivt_msg_response(i)._a7_resp_sign_wh());
		(*net_enums)["IVT_MSG_RESPONSE"]["_b0_resp_reset_item"].push(pack->ivt_msg_response(i)._b0_resp_reset_item());
		hv_current_ivt_msg_response__b0_resp_reset_item_enum_to_string((hv_current_ivt_msg_response__b0_resp_reset_item)pack->ivt_msg_response(i)._b0_resp_reset_item(), buffer);
		(*net_strings)["IVT_MSG_RESPONSE"]["_b0_resp_reset_item"].push(buffer);
		(*net_signals)["IVT_MSG_RESPONSE"]["_b2_resp_store_dummy"].push(pack->ivt_msg_response(i)._b2_resp_store_dummy());
		(*net_signals)["IVT_MSG_RESPONSE"]["_b3_resp_oc_test_time"].push(pack->ivt_msg_response(i)._b3_resp_oc_test_time());
		(*net_signals)["IVT_MSG_RESPONSE"]["_b5_resp_oc_pos_set_threshold"].push(pack->ivt_msg_response(i)._b5_resp_oc_pos_set_threshold());
		(*net_signals)["IVT_MSG_RESPONSE"]["_b6_resp_oc_neg_set_threshold"].push(pack->ivt_msg_response(i)._b6_resp_oc_neg_set_threshold());
		(*net_enums)["IVT_MSG_RESPONSE"]["_b9_resp_device_type"].push(pack->ivt_msg_response(i)._b9_resp_device_type());
		hv_current_ivt_msg_response__b9_resp_device_type_enum_to_string((hv_current_ivt_msg_response__b9_resp_device_type)pack->ivt_msg_response(i)._b9_resp_device_type(), buffer);
		(*net_strings)["IVT_MSG_RESPONSE"]["_b9_resp_device_type"].push(buffer);
		(*net_signals)["IVT_MSG_RESPONSE"]["_ba_resp_sw_ver_major_hw"].push(pack->ivt_msg_response(i)._ba_resp_sw_ver_major_hw());
		(*net_signals)["IVT_MSG_RESPONSE"]["_bb_resp_serien_nr"].push(pack->ivt_msg_response(i)._bb_resp_serien_nr());
		(*net_signals)["IVT_MSG_RESPONSE"]["_bc_resp_art_n"].push(pack->ivt_msg_response(i)._bc_resp_art_n());
		(*net_signals)["IVT_MSG_RESPONSE"]["_a0_resp_endianess_i"].push(pack->ivt_msg_response(i)._a0_resp_endianess_i());
		(*net_signals)["IVT_MSG_RESPONSE"]["_a1_resp_endianess_u1"].push(pack->ivt_msg_response(i)._a1_resp_endianess_u1());
		(*net_signals)["IVT_MSG_RESPONSE"]["_a2_resp_endianess_u2"].push(pack->ivt_msg_response(i)._a2_resp_endianess_u2());
		(*net_signals)["IVT_MSG_RESPONSE"]["_a3_resp_endianess_u3"].push(pack->ivt_msg_response(i)._a3_resp_endianess_u3());
		(*net_signals)["IVT_MSG_RESPONSE"]["_a4_resp_endianess_t"].push(pack->ivt_msg_response(i)._a4_resp_endianess_t());
		(*net_signals)["IVT_MSG_RESPONSE"]["_a5_resp_endianess_w"].push(pack->ivt_msg_response(i)._a5_resp_endianess_w());
		(*net_signals)["IVT_MSG_RESPONSE"]["_a6_resp_endianess_as"].push(pack->ivt_msg_response(i)._a6_resp_endianess_as());
		(*net_signals)["IVT_MSG_RESPONSE"]["_a7_resp_endianess_wh"].push(pack->ivt_msg_response(i)._a7_resp_endianess_wh());
		(*net_enums)["IVT_MSG_RESPONSE"]["_a0_resp_triggermode_i"].push(pack->ivt_msg_response(i)._a0_resp_triggermode_i());
		hv_current_ivt_msg_response__a0_resp_triggermode_i_enum_to_string((hv_current_ivt_msg_response__a0_resp_triggermode_i)pack->ivt_msg_response(i)._a0_resp_triggermode_i(), buffer);
		(*net_strings)["IVT_MSG_RESPONSE"]["_a0_resp_triggermode_i"].push(buffer);
		(*net_enums)["IVT_MSG_RESPONSE"]["_a1_resp_triggermode_u1"].push(pack->ivt_msg_response(i)._a1_resp_triggermode_u1());
		hv_current_ivt_msg_response__a1_resp_triggermode_u1_enum_to_string((hv_current_ivt_msg_response__a1_resp_triggermode_u1)pack->ivt_msg_response(i)._a1_resp_triggermode_u1(), buffer);
		(*net_strings)["IVT_MSG_RESPONSE"]["_a1_resp_triggermode_u1"].push(buffer);
		(*net_enums)["IVT_MSG_RESPONSE"]["_a2_resp_triggermode_u2"].push(pack->ivt_msg_response(i)._a2_resp_triggermode_u2());
		hv_current_ivt_msg_response__a2_resp_triggermode_u2_enum_to_string((hv_current_ivt_msg_response__a2_resp_triggermode_u2)pack->ivt_msg_response(i)._a2_resp_triggermode_u2(), buffer);
		(*net_strings)["IVT_MSG_RESPONSE"]["_a2_resp_triggermode_u2"].push(buffer);
		(*net_enums)["IVT_MSG_RESPONSE"]["_a3_resp_triggermode_u3"].push(pack->ivt_msg_response(i)._a3_resp_triggermode_u3());
		hv_current_ivt_msg_response__a3_resp_triggermode_u3_enum_to_string((hv_current_ivt_msg_response__a3_resp_triggermode_u3)pack->ivt_msg_response(i)._a3_resp_triggermode_u3(), buffer);
		(*net_strings)["IVT_MSG_RESPONSE"]["_a3_resp_triggermode_u3"].push(buffer);
		(*net_enums)["IVT_MSG_RESPONSE"]["_a4_resp_triggermode_t"].push(pack->ivt_msg_response(i)._a4_resp_triggermode_t());
		hv_current_ivt_msg_response__a4_resp_triggermode_t_enum_to_string((hv_current_ivt_msg_response__a4_resp_triggermode_t)pack->ivt_msg_response(i)._a4_resp_triggermode_t(), buffer);
		(*net_strings)["IVT_MSG_RESPONSE"]["_a4_resp_triggermode_t"].push(buffer);
		(*net_enums)["IVT_MSG_RESPONSE"]["_a5_resp_triggermode_w"].push(pack->ivt_msg_response(i)._a5_resp_triggermode_w());
		hv_current_ivt_msg_response__a5_resp_triggermode_w_enum_to_string((hv_current_ivt_msg_response__a5_resp_triggermode_w)pack->ivt_msg_response(i)._a5_resp_triggermode_w(), buffer);
		(*net_strings)["IVT_MSG_RESPONSE"]["_a5_resp_triggermode_w"].push(buffer);
		(*net_enums)["IVT_MSG_RESPONSE"]["_a6_resp_triggermode_as"].push(pack->ivt_msg_response(i)._a6_resp_triggermode_as());
		hv_current_ivt_msg_response__a6_resp_triggermode_as_enum_to_string((hv_current_ivt_msg_response__a6_resp_triggermode_as)pack->ivt_msg_response(i)._a6_resp_triggermode_as(), buffer);
		(*net_strings)["IVT_MSG_RESPONSE"]["_a6_resp_triggermode_as"].push(buffer);
		(*net_enums)["IVT_MSG_RESPONSE"]["_a7_resp_triggermode_wh"].push(pack->ivt_msg_response(i)._a7_resp_triggermode_wh());
		hv_current_ivt_msg_response__a7_resp_triggermode_wh_enum_to_string((hv_current_ivt_msg_response__a7_resp_triggermode_wh)pack->ivt_msg_response(i)._a7_resp_triggermode_wh(), buffer);
		(*net_strings)["IVT_MSG_RESPONSE"]["_a7_resp_triggermode_wh"].push(buffer);
		(*net_enums)["IVT_MSG_RESPONSE"]["_b4_resp_actual_mode"].push(pack->ivt_msg_response(i)._b4_resp_actual_mode());
		hv_current_ivt_msg_response__b4_resp_actual_mode_enum_to_string((hv_current_ivt_msg_response__b4_resp_actual_mode)pack->ivt_msg_response(i)._b4_resp_actual_mode(), buffer);
		(*net_strings)["IVT_MSG_RESPONSE"]["_b4_resp_actual_mode"].push(buffer);
		(*net_signals)["IVT_MSG_RESPONSE"]["_b1_07_trigger_wh"].push(pack->ivt_msg_response(i)._b1_07_trigger_wh());
		(*net_signals)["IVT_MSG_RESPONSE"]["_b2_resp_store_device_sn"].push(pack->ivt_msg_response(i)._b2_resp_store_device_sn());
		(*net_signals)["IVT_MSG_RESPONSE"]["_ba_resp_sw_ver_minor"].push(pack->ivt_msg_response(i)._ba_resp_sw_ver_minor());
		(*net_enums)["IVT_MSG_RESPONSE"]["_b9_resp_device_current"].push(pack->ivt_msg_response(i)._b9_resp_device_current());
		hv_current_ivt_msg_response__b9_resp_device_current_enum_to_string((hv_current_ivt_msg_response__b9_resp_device_current)pack->ivt_msg_response(i)._b9_resp_device_current(), buffer);
		(*net_strings)["IVT_MSG_RESPONSE"]["_b9_resp_device_current"].push(buffer);
		(*net_signals)["IVT_MSG_RESPONSE"]["_80_resp_measerror_count_mask"].push(pack->ivt_msg_response(i)._80_resp_measerror_count_mask());
		(*net_signals)["IVT_MSG_RESPONSE"]["_81_resp_systemerror_count_mask"].push(pack->ivt_msg_response(i)._81_resp_systemerror_count_mask());
		(*net_signals)["IVT_MSG_RESPONSE"]["_82_resp_alllogdata_counter"].push(pack->ivt_msg_response(i)._82_resp_alllogdata_counter());
		(*net_signals)["IVT_MSG_RESPONSE"]["_83_resp_logdata_counter"].push(pack->ivt_msg_response(i)._83_resp_logdata_counter());
		(*net_signals)["IVT_MSG_RESPONSE"]["_a0_resp_cycletime_i"].push(pack->ivt_msg_response(i)._a0_resp_cycletime_i());
		(*net_signals)["IVT_MSG_RESPONSE"]["_a1_resp_cycletime_u1"].push(pack->ivt_msg_response(i)._a1_resp_cycletime_u1());
		(*net_signals)["IVT_MSG_RESPONSE"]["_a2_resp_cycletime_u2"].push(pack->ivt_msg_response(i)._a2_resp_cycletime_u2());
		(*net_signals)["IVT_MSG_RESPONSE"]["_a3_resp_cycletime_u3"].push(pack->ivt_msg_response(i)._a3_resp_cycletime_u3());
		(*net_signals)["IVT_MSG_RESPONSE"]["_a4_resp_cycletime_t"].push(pack->ivt_msg_response(i)._a4_resp_cycletime_t());
		(*net_signals)["IVT_MSG_RESPONSE"]["_a5_resp_cycletime_w"].push(pack->ivt_msg_response(i)._a5_resp_cycletime_w());
		(*net_signals)["IVT_MSG_RESPONSE"]["_a6_resp_cycletime_as"].push(pack->ivt_msg_response(i)._a6_resp_cycletime_as());
		(*net_signals)["IVT_MSG_RESPONSE"]["_a7_resp_cycletime_wh"].push(pack->ivt_msg_response(i)._a7_resp_cycletime_wh());
		(*net_signals)["IVT_MSG_RESPONSE"]["_b1_06_trigger_as"].push(pack->ivt_msg_response(i)._b1_06_trigger_as());
		(*net_signals)["IVT_MSG_RESPONSE"]["_b1_05_trigger_w"].push(pack->ivt_msg_response(i)._b1_05_trigger_w());
		(*net_signals)["IVT_MSG_RESPONSE"]["_b1_04_trigger_t"].push(pack->ivt_msg_response(i)._b1_04_trigger_t());
		(*net_signals)["IVT_MSG_RESPONSE"]["_b1_03_trigger_u3"].push(pack->ivt_msg_response(i)._b1_03_trigger_u3());
		(*net_signals)["IVT_MSG_RESPONSE"]["_b1_02_trigger_u2"].push(pack->ivt_msg_response(i)._b1_02_trigger_u2());
		(*net_signals)["IVT_MSG_RESPONSE"]["_b1_01_trigger_u1"].push(pack->ivt_msg_response(i)._b1_01_trigger_u1());
		(*net_signals)["IVT_MSG_RESPONSE"]["_b1_00_trigger_i"].push(pack->ivt_msg_response(i)._b1_00_trigger_i());
		(*net_enums)["IVT_MSG_RESPONSE"]["_b4_resp_startup_mode"].push(pack->ivt_msg_response(i)._b4_resp_startup_mode());
		hv_current_ivt_msg_response__b4_resp_startup_mode_enum_to_string((hv_current_ivt_msg_response__b4_resp_startup_mode)pack->ivt_msg_response(i)._b4_resp_startup_mode(), buffer);
		(*net_strings)["IVT_MSG_RESPONSE"]["_b4_resp_startup_mode"].push(buffer);
		(*net_signals)["IVT_MSG_RESPONSE"]["_bf_restart_alive_sn"].push(pack->ivt_msg_response(i)._bf_restart_alive_sn());
		(*net_signals)["IVT_MSG_RESPONSE"]["_ba_resp_sw_ver_revision"].push(pack->ivt_msg_response(i)._ba_resp_sw_ver_revision());
		(*net_signals)["IVT_MSG_RESPONSE"]["_90_resp_can_id_sn_i"].push(pack->ivt_msg_response(i)._90_resp_can_id_sn_i());
		(*net_signals)["IVT_MSG_RESPONSE"]["_91_resp_can_id_sn_u1"].push(pack->ivt_msg_response(i)._91_resp_can_id_sn_u1());
		(*net_signals)["IVT_MSG_RESPONSE"]["_92_resp_can_id_sn_u2"].push(pack->ivt_msg_response(i)._92_resp_can_id_sn_u2());
		(*net_signals)["IVT_MSG_RESPONSE"]["_93_resp_can_id_sn_u3"].push(pack->ivt_msg_response(i)._93_resp_can_id_sn_u3());
		(*net_signals)["IVT_MSG_RESPONSE"]["_94_resp_can_id_sn_t"].push(pack->ivt_msg_response(i)._94_resp_can_id_sn_t());
		(*net_signals)["IVT_MSG_RESPONSE"]["_95_resp_can_id_sn_w"].push(pack->ivt_msg_response(i)._95_resp_can_id_sn_w());
		(*net_signals)["IVT_MSG_RESPONSE"]["_96_resp_can_id_sn_as"].push(pack->ivt_msg_response(i)._96_resp_can_id_sn_as());
		(*net_signals)["IVT_MSG_RESPONSE"]["_97_resp_can_id_sn_wh"].push(pack->ivt_msg_response(i)._97_resp_can_id_sn_wh());
		(*net_signals)["IVT_MSG_RESPONSE"]["_9d_resp_can_id_sn_command"].push(pack->ivt_msg_response(i)._9d_resp_can_id_sn_command());
		(*net_signals)["IVT_MSG_RESPONSE"]["_9f_resp_can_id_sn_response"].push(pack->ivt_msg_response(i)._9f_resp_can_id_sn_response());
		(*net_signals)["IVT_MSG_RESPONSE"]["_b0_resp_reset_device_sn"].push(pack->ivt_msg_response(i)._b0_resp_reset_device_sn());
		(*net_signals)["IVT_MSG_RESPONSE"]["_b4_resp_code_level"].push(pack->ivt_msg_response(i)._b4_resp_code_level());
		(*net_signals)["IVT_MSG_RESPONSE"]["_b5_resp_oc_pos_reset_threshold"].push(pack->ivt_msg_response(i)._b5_resp_oc_pos_reset_threshold());
		(*net_signals)["IVT_MSG_RESPONSE"]["_b6_resp_oc_neg_reset_threshold"].push(pack->ivt_msg_response(i)._b6_resp_oc_neg_reset_threshold());
		(*net_enums)["IVT_MSG_RESPONSE"]["_b9_resp_device_voltage_chan"].push(pack->ivt_msg_response(i)._b9_resp_device_voltage_chan());
		hv_current_ivt_msg_response__b9_resp_device_voltage_chan_enum_to_string((hv_current_ivt_msg_response__b9_resp_device_voltage_chan)pack->ivt_msg_response(i)._b9_resp_device_voltage_chan(), buffer);
		(*net_strings)["IVT_MSG_RESPONSE"]["_b9_resp_device_voltage_chan"].push(buffer);
		(*net_signals)["IVT_MSG_RESPONSE"]["_ba_resp_sw_ver_vear"].push(pack->ivt_msg_response(i)._ba_resp_sw_ver_vear());
		(*net_enums)["IVT_MSG_RESPONSE"]["_b9_resp_device_toi"].push(pack->ivt_msg_response(i)._b9_resp_device_toi());
		hv_current_ivt_msg_response__b9_resp_device_toi_enum_to_string((hv_current_ivt_msg_response__b9_resp_device_toi)pack->ivt_msg_response(i)._b9_resp_device_toi(), buffer);
		(*net_strings)["IVT_MSG_RESPONSE"]["_b9_resp_device_toi"].push(buffer);
		(*net_signals)["IVT_MSG_RESPONSE"]["_ba_resp_sw_ver_month"].push(pack->ivt_msg_response(i)._ba_resp_sw_ver_month());
		(*net_enums)["IVT_MSG_RESPONSE"]["_b9_resp_device_com"].push(pack->ivt_msg_response(i)._b9_resp_device_com());
		hv_current_ivt_msg_response__b9_resp_device_com_enum_to_string((hv_current_ivt_msg_response__b9_resp_device_com)pack->ivt_msg_response(i)._b9_resp_device_com(), buffer);
		(*net_strings)["IVT_MSG_RESPONSE"]["_b9_resp_device_com"].push(buffer);
		(*net_signals)["IVT_MSG_RESPONSE"]["_ba_resp_sw_ver_day"].push(pack->ivt_msg_response(i)._ba_resp_sw_ver_day());
		(*net_enums)["IVT_MSG_RESPONSE"]["_b9_resp_device_v_supply"].push(pack->ivt_msg_response(i)._b9_resp_device_v_supply());
		hv_current_ivt_msg_response__b9_resp_device_v_supply_enum_to_string((hv_current_ivt_msg_response__b9_resp_device_v_supply)pack->ivt_msg_response(i)._b9_resp_device_v_supply(), buffer);
		(*net_strings)["IVT_MSG_RESPONSE"]["_b9_resp_device_v_supply"].push(buffer);
		(*net_signals)["IVT_MSG_RESPONSE"]["_ba_resp_sw_ver_internal"].push(pack->ivt_msg_response(i)._ba_resp_sw_ver_internal());

    }

    for(int i = 0; i < pack->ivt_msg_result_t_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->ivt_msg_result_t(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->ivt_msg_result_t(i)._inner_timestamp();
        (*net_signals)["IVT_MSG_RESULT_T"]["_timestamp"].push(pack->ivt_msg_result_t(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["IVT_MSG_RESULT_T"]["ivt_id_result_t"].push(pack->ivt_msg_result_t(i).ivt_id_result_t());
		hv_current_ivt_msg_result_t_ivt_id_result_t_enum_to_string((hv_current_ivt_msg_result_t_ivt_id_result_t)pack->ivt_msg_result_t(i).ivt_id_result_t(), buffer);
		(*net_strings)["IVT_MSG_RESULT_T"]["ivt_id_result_t"].push(buffer);
		(*net_signals)["IVT_MSG_RESULT_T"]["ivt_result_t_system_error"].push(pack->ivt_msg_result_t(i).ivt_result_t_system_error());
		(*net_signals)["IVT_MSG_RESULT_T"]["ivt_result_t_measurement_error"].push(pack->ivt_msg_result_t(i).ivt_result_t_measurement_error());
		(*net_signals)["IVT_MSG_RESULT_T"]["ivt_result_t_channel_error"].push(pack->ivt_msg_result_t(i).ivt_result_t_channel_error());
		(*net_signals)["IVT_MSG_RESULT_T"]["ivt_result_t_ocs"].push(pack->ivt_msg_result_t(i).ivt_result_t_ocs());
		(*net_signals)["IVT_MSG_RESULT_T"]["ivt_msgcount_result_t"].push(pack->ivt_msg_result_t(i).ivt_msgcount_result_t());
		(*net_signals)["IVT_MSG_RESULT_T"]["ivt_result_t"].push(pack->ivt_msg_result_t(i).ivt_result_t());

    }

    for(int i = 0; i < pack->ivt_msg_result_u3_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->ivt_msg_result_u3(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->ivt_msg_result_u3(i)._inner_timestamp();
        (*net_signals)["IVT_MSG_RESULT_U3"]["_timestamp"].push(pack->ivt_msg_result_u3(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["IVT_MSG_RESULT_U3"]["ivt_id_result_u3"].push(pack->ivt_msg_result_u3(i).ivt_id_result_u3());
		hv_current_ivt_msg_result_u3_ivt_id_result_u3_enum_to_string((hv_current_ivt_msg_result_u3_ivt_id_result_u3)pack->ivt_msg_result_u3(i).ivt_id_result_u3(), buffer);
		(*net_strings)["IVT_MSG_RESULT_U3"]["ivt_id_result_u3"].push(buffer);
		(*net_signals)["IVT_MSG_RESULT_U3"]["ivt_result_u3_system_error"].push(pack->ivt_msg_result_u3(i).ivt_result_u3_system_error());
		(*net_signals)["IVT_MSG_RESULT_U3"]["ivt_result_u3_measurement_error"].push(pack->ivt_msg_result_u3(i).ivt_result_u3_measurement_error());
		(*net_signals)["IVT_MSG_RESULT_U3"]["ivt_result_u3_channel_error"].push(pack->ivt_msg_result_u3(i).ivt_result_u3_channel_error());
		(*net_signals)["IVT_MSG_RESULT_U3"]["ivt_result_u3_ocs"].push(pack->ivt_msg_result_u3(i).ivt_result_u3_ocs());
		(*net_signals)["IVT_MSG_RESULT_U3"]["ivt_msgcount_result_u3"].push(pack->ivt_msg_result_u3(i).ivt_msgcount_result_u3());
		(*net_signals)["IVT_MSG_RESULT_U3"]["ivt_result_u3"].push(pack->ivt_msg_result_u3(i).ivt_result_u3());

    }

    for(int i = 0; i < pack->ivt_msg_result_u2_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->ivt_msg_result_u2(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->ivt_msg_result_u2(i)._inner_timestamp();
        (*net_signals)["IVT_MSG_RESULT_U2"]["_timestamp"].push(pack->ivt_msg_result_u2(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["IVT_MSG_RESULT_U2"]["ivt_id_result_u2"].push(pack->ivt_msg_result_u2(i).ivt_id_result_u2());
		hv_current_ivt_msg_result_u2_ivt_id_result_u2_enum_to_string((hv_current_ivt_msg_result_u2_ivt_id_result_u2)pack->ivt_msg_result_u2(i).ivt_id_result_u2(), buffer);
		(*net_strings)["IVT_MSG_RESULT_U2"]["ivt_id_result_u2"].push(buffer);
		(*net_signals)["IVT_MSG_RESULT_U2"]["ivt_result_u2_system_error"].push(pack->ivt_msg_result_u2(i).ivt_result_u2_system_error());
		(*net_signals)["IVT_MSG_RESULT_U2"]["ivt_result_u2_measurement_error"].push(pack->ivt_msg_result_u2(i).ivt_result_u2_measurement_error());
		(*net_signals)["IVT_MSG_RESULT_U2"]["ivt_result_u2_channel_error"].push(pack->ivt_msg_result_u2(i).ivt_result_u2_channel_error());
		(*net_signals)["IVT_MSG_RESULT_U2"]["ivt_result_u2_ocs"].push(pack->ivt_msg_result_u2(i).ivt_result_u2_ocs());
		(*net_signals)["IVT_MSG_RESULT_U2"]["ivt_msgcount_result_u2"].push(pack->ivt_msg_result_u2(i).ivt_msgcount_result_u2());
		(*net_signals)["IVT_MSG_RESULT_U2"]["ivt_result_u2"].push(pack->ivt_msg_result_u2(i).ivt_result_u2());

    }

    for(int i = 0; i < pack->ivt_msg_result_u1_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->ivt_msg_result_u1(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->ivt_msg_result_u1(i)._inner_timestamp();
        (*net_signals)["IVT_MSG_RESULT_U1"]["_timestamp"].push(pack->ivt_msg_result_u1(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["IVT_MSG_RESULT_U1"]["ivt_id_result_u1"].push(pack->ivt_msg_result_u1(i).ivt_id_result_u1());
		hv_current_ivt_msg_result_u1_ivt_id_result_u1_enum_to_string((hv_current_ivt_msg_result_u1_ivt_id_result_u1)pack->ivt_msg_result_u1(i).ivt_id_result_u1(), buffer);
		(*net_strings)["IVT_MSG_RESULT_U1"]["ivt_id_result_u1"].push(buffer);
		(*net_signals)["IVT_MSG_RESULT_U1"]["ivt_result_u1_system_error"].push(pack->ivt_msg_result_u1(i).ivt_result_u1_system_error());
		(*net_signals)["IVT_MSG_RESULT_U1"]["ivt_result_u1_measurement_error"].push(pack->ivt_msg_result_u1(i).ivt_result_u1_measurement_error());
		(*net_signals)["IVT_MSG_RESULT_U1"]["ivt_result_u1_channel_error"].push(pack->ivt_msg_result_u1(i).ivt_result_u1_channel_error());
		(*net_signals)["IVT_MSG_RESULT_U1"]["ivt_result_u1_ocs"].push(pack->ivt_msg_result_u1(i).ivt_result_u1_ocs());
		(*net_signals)["IVT_MSG_RESULT_U1"]["ivt_msgcount_result_u1"].push(pack->ivt_msg_result_u1(i).ivt_msgcount_result_u1());
		(*net_signals)["IVT_MSG_RESULT_U1"]["ivt_result_u1"].push(pack->ivt_msg_result_u1(i).ivt_result_u1());

    }

    for(int i = 0; i < pack->ivt_msg_result_i_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->ivt_msg_result_i(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->ivt_msg_result_i(i)._inner_timestamp();
        (*net_signals)["IVT_MSG_RESULT_I"]["_timestamp"].push(pack->ivt_msg_result_i(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["IVT_MSG_RESULT_I"]["ivt_id_result_i"].push(pack->ivt_msg_result_i(i).ivt_id_result_i());
		hv_current_ivt_msg_result_i_ivt_id_result_i_enum_to_string((hv_current_ivt_msg_result_i_ivt_id_result_i)pack->ivt_msg_result_i(i).ivt_id_result_i(), buffer);
		(*net_strings)["IVT_MSG_RESULT_I"]["ivt_id_result_i"].push(buffer);
		(*net_signals)["IVT_MSG_RESULT_I"]["ivt_result_i_system_error"].push(pack->ivt_msg_result_i(i).ivt_result_i_system_error());
		(*net_signals)["IVT_MSG_RESULT_I"]["ivt_result_i_measurement_error"].push(pack->ivt_msg_result_i(i).ivt_result_i_measurement_error());
		(*net_signals)["IVT_MSG_RESULT_I"]["ivt_result_i_channel_error"].push(pack->ivt_msg_result_i(i).ivt_result_i_channel_error());
		(*net_signals)["IVT_MSG_RESULT_I"]["ivt_result_i_ocs"].push(pack->ivt_msg_result_i(i).ivt_result_i_ocs());
		(*net_signals)["IVT_MSG_RESULT_I"]["ivt_msgcount_result_i"].push(pack->ivt_msg_result_i(i).ivt_msgcount_result_i());
		(*net_signals)["IVT_MSG_RESULT_I"]["ivt_result_i"].push(pack->ivt_msg_result_i(i).ivt_result_i());

    }

    for(int i = 0; i < pack->ivt_msg_cmd_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->ivt_msg_cmd(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->ivt_msg_cmd(i)._inner_timestamp();
        (*net_signals)["IVT_MSG_CMD"]["_timestamp"].push(pack->ivt_msg_cmd(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["IVT_MSG_CMD"]["ivt_id_cmd"].push(pack->ivt_msg_cmd(i).ivt_id_cmd());
		hv_current_ivt_msg_cmd_ivt_id_cmd_enum_to_string((hv_current_ivt_msg_cmd_ivt_id_cmd)pack->ivt_msg_cmd(i).ivt_id_cmd(), buffer);
		(*net_strings)["IVT_MSG_CMD"]["ivt_id_cmd"].push(buffer);
		(*net_signals)["IVT_MSG_CMD"]["_31_trigger_spare"].push(pack->ivt_msg_cmd(i)._31_trigger_spare());
		(*net_signals)["IVT_MSG_CMD"]["_10_set_can_id_val_i"].push(pack->ivt_msg_cmd(i)._10_set_can_id_val_i());
		(*net_signals)["IVT_MSG_CMD"]["_11_set_can_id_val_u1"].push(pack->ivt_msg_cmd(i)._11_set_can_id_val_u1());
		(*net_signals)["IVT_MSG_CMD"]["_12_set_can_id_val_u2"].push(pack->ivt_msg_cmd(i)._12_set_can_id_val_u2());
		(*net_signals)["IVT_MSG_CMD"]["_13_set_can_id_val_u3"].push(pack->ivt_msg_cmd(i)._13_set_can_id_val_u3());
		(*net_signals)["IVT_MSG_CMD"]["_14_set_can_id_val_t"].push(pack->ivt_msg_cmd(i)._14_set_can_id_val_t());
		(*net_signals)["IVT_MSG_CMD"]["_15_set_can_id_val_w"].push(pack->ivt_msg_cmd(i)._15_set_can_id_val_w());
		(*net_signals)["IVT_MSG_CMD"]["_16_set_can_id_val_as"].push(pack->ivt_msg_cmd(i)._16_set_can_id_val_as());
		(*net_signals)["IVT_MSG_CMD"]["_17_set_can_id_val_wh"].push(pack->ivt_msg_cmd(i)._17_set_can_id_val_wh());
		(*net_signals)["IVT_MSG_CMD"]["_1d_set_can_id_val_command"].push(pack->ivt_msg_cmd(i)._1d_set_can_id_val_command());
		(*net_signals)["IVT_MSG_CMD"]["_1f_set_can_id_val_response"].push(pack->ivt_msg_cmd(i)._1f_set_can_id_val_response());
		(*net_signals)["IVT_MSG_CMD"]["_20_conf_sign_i"].push(pack->ivt_msg_cmd(i)._20_conf_sign_i());
		(*net_signals)["IVT_MSG_CMD"]["_21_conf_sign_u1"].push(pack->ivt_msg_cmd(i)._21_conf_sign_u1());
		(*net_signals)["IVT_MSG_CMD"]["_22_conf_sign_u2"].push(pack->ivt_msg_cmd(i)._22_conf_sign_u2());
		(*net_signals)["IVT_MSG_CMD"]["_23_conf_sign_u3"].push(pack->ivt_msg_cmd(i)._23_conf_sign_u3());
		(*net_signals)["IVT_MSG_CMD"]["_24_conf_sign_t"].push(pack->ivt_msg_cmd(i)._24_conf_sign_t());
		(*net_signals)["IVT_MSG_CMD"]["_25_conf_sign_w"].push(pack->ivt_msg_cmd(i)._25_conf_sign_w());
		(*net_signals)["IVT_MSG_CMD"]["_26_conf_sign_as"].push(pack->ivt_msg_cmd(i)._26_conf_sign_as());
		(*net_signals)["IVT_MSG_CMD"]["_27_conf_sign_wh"].push(pack->ivt_msg_cmd(i)._27_conf_sign_wh());
		(*net_enums)["IVT_MSG_CMD"]["_30_reset_item"].push(pack->ivt_msg_cmd(i)._30_reset_item());
		hv_current_ivt_msg_cmd__30_reset_item_enum_to_string((hv_current_ivt_msg_cmd__30_reset_item)pack->ivt_msg_cmd(i)._30_reset_item(), buffer);
		(*net_strings)["IVT_MSG_CMD"]["_30_reset_item"].push(buffer);
		(*net_signals)["IVT_MSG_CMD"]["_32_store_dummy"].push(pack->ivt_msg_cmd(i)._32_store_dummy());
		(*net_signals)["IVT_MSG_CMD"]["_33_oc_test_time"].push(pack->ivt_msg_cmd(i)._33_oc_test_time());
		(*net_signals)["IVT_MSG_CMD"]["_35_oc_pos_set_threshold"].push(pack->ivt_msg_cmd(i)._35_oc_pos_set_threshold());
		(*net_signals)["IVT_MSG_CMD"]["_36_oc_neg_set_threshold"].push(pack->ivt_msg_cmd(i)._36_oc_neg_set_threshold());
		(*net_enums)["IVT_MSG_CMD"]["_3a_restart_to_bitrate"].push(pack->ivt_msg_cmd(i)._3a_restart_to_bitrate());
		hv_current_ivt_msg_cmd__3a_restart_to_bitrate_enum_to_string((hv_current_ivt_msg_cmd__3a_restart_to_bitrate)pack->ivt_msg_cmd(i)._3a_restart_to_bitrate(), buffer);
		(*net_strings)["IVT_MSG_CMD"]["_3a_restart_to_bitrate"].push(buffer);
		(*net_signals)["IVT_MSG_CMD"]["_3d_restart_default_dummy"].push(pack->ivt_msg_cmd(i)._3d_restart_default_dummy());
		(*net_signals)["IVT_MSG_CMD"]["_3f_restart_dummy"].push(pack->ivt_msg_cmd(i)._3f_restart_dummy());
		(*net_enums)["IVT_MSG_CMD"]["_40_get_measerror_item"].push(pack->ivt_msg_cmd(i)._40_get_measerror_item());
		hv_current_ivt_msg_cmd__40_get_measerror_item_enum_to_string((hv_current_ivt_msg_cmd__40_get_measerror_item)pack->ivt_msg_cmd(i)._40_get_measerror_item(), buffer);
		(*net_strings)["IVT_MSG_CMD"]["_40_get_measerror_item"].push(buffer);
		(*net_enums)["IVT_MSG_CMD"]["_41_get_systemerror_item"].push(pack->ivt_msg_cmd(i)._41_get_systemerror_item());
		hv_current_ivt_msg_cmd__41_get_systemerror_item_enum_to_string((hv_current_ivt_msg_cmd__41_get_systemerror_item)pack->ivt_msg_cmd(i)._41_get_systemerror_item(), buffer);
		(*net_strings)["IVT_MSG_CMD"]["_41_get_systemerror_item"].push(buffer);
		(*net_enums)["IVT_MSG_CMD"]["_42_get_alllogdata_item"].push(pack->ivt_msg_cmd(i)._42_get_alllogdata_item());
		hv_current_ivt_msg_cmd__42_get_alllogdata_item_enum_to_string((hv_current_ivt_msg_cmd__42_get_alllogdata_item)pack->ivt_msg_cmd(i)._42_get_alllogdata_item(), buffer);
		(*net_strings)["IVT_MSG_CMD"]["_42_get_alllogdata_item"].push(buffer);
		(*net_enums)["IVT_MSG_CMD"]["_43_get_logdata_item"].push(pack->ivt_msg_cmd(i)._43_get_logdata_item());
		hv_current_ivt_msg_cmd__43_get_logdata_item_enum_to_string((hv_current_ivt_msg_cmd__43_get_logdata_item)pack->ivt_msg_cmd(i)._43_get_logdata_item(), buffer);
		(*net_strings)["IVT_MSG_CMD"]["_43_get_logdata_item"].push(buffer);
		(*net_signals)["IVT_MSG_CMD"]["_60_get_result_dummy_i"].push(pack->ivt_msg_cmd(i)._60_get_result_dummy_i());
		(*net_signals)["IVT_MSG_CMD"]["_61_get_result_dummy_u1"].push(pack->ivt_msg_cmd(i)._61_get_result_dummy_u1());
		(*net_signals)["IVT_MSG_CMD"]["_62_get_result_dummy_u2"].push(pack->ivt_msg_cmd(i)._62_get_result_dummy_u2());
		(*net_signals)["IVT_MSG_CMD"]["_63_get_result_dummy_u3"].push(pack->ivt_msg_cmd(i)._63_get_result_dummy_u3());
		(*net_signals)["IVT_MSG_CMD"]["_64_get_result_dummy_t"].push(pack->ivt_msg_cmd(i)._64_get_result_dummy_t());
		(*net_signals)["IVT_MSG_CMD"]["_65_get_result_dummy_w"].push(pack->ivt_msg_cmd(i)._65_get_result_dummy_w());
		(*net_signals)["IVT_MSG_CMD"]["_66_get_result_dummy_as"].push(pack->ivt_msg_cmd(i)._66_get_result_dummy_as());
		(*net_signals)["IVT_MSG_CMD"]["_67_get_result_dummy_wh"].push(pack->ivt_msg_cmd(i)._67_get_result_dummy_wh());
		(*net_signals)["IVT_MSG_CMD"]["_73_get_oc_test_dummy"].push(pack->ivt_msg_cmd(i)._73_get_oc_test_dummy());
		(*net_signals)["IVT_MSG_CMD"]["_74_get_mode_dummy"].push(pack->ivt_msg_cmd(i)._74_get_mode_dummy());
		(*net_signals)["IVT_MSG_CMD"]["_75_get_oc_pos_dummy"].push(pack->ivt_msg_cmd(i)._75_get_oc_pos_dummy());
		(*net_signals)["IVT_MSG_CMD"]["_76_get_oc_neg_dummy"].push(pack->ivt_msg_cmd(i)._76_get_oc_neg_dummy());
		(*net_signals)["IVT_MSG_CMD"]["_79_get_device_id_dummy"].push(pack->ivt_msg_cmd(i)._79_get_device_id_dummy());
		(*net_signals)["IVT_MSG_CMD"]["_7a_get_sw_version_dummy"].push(pack->ivt_msg_cmd(i)._7a_get_sw_version_dummy());
		(*net_signals)["IVT_MSG_CMD"]["_7b_get_serien_nr_dummy"].push(pack->ivt_msg_cmd(i)._7b_get_serien_nr_dummy());
		(*net_signals)["IVT_MSG_CMD"]["_7c_get_art_nr_dummy"].push(pack->ivt_msg_cmd(i)._7c_get_art_nr_dummy());
		(*net_signals)["IVT_MSG_CMD"]["_20_conf_endianess_i"].push(pack->ivt_msg_cmd(i)._20_conf_endianess_i());
		(*net_signals)["IVT_MSG_CMD"]["_21_conf_endianess_u1"].push(pack->ivt_msg_cmd(i)._21_conf_endianess_u1());
		(*net_signals)["IVT_MSG_CMD"]["_22_conf_endianess_u2"].push(pack->ivt_msg_cmd(i)._22_conf_endianess_u2());
		(*net_signals)["IVT_MSG_CMD"]["_23_conf_endianess_u3"].push(pack->ivt_msg_cmd(i)._23_conf_endianess_u3());
		(*net_signals)["IVT_MSG_CMD"]["_24_conf_endianess_t"].push(pack->ivt_msg_cmd(i)._24_conf_endianess_t());
		(*net_signals)["IVT_MSG_CMD"]["_25_conf_endianess_w"].push(pack->ivt_msg_cmd(i)._25_conf_endianess_w());
		(*net_signals)["IVT_MSG_CMD"]["_26_conf_endianess_as"].push(pack->ivt_msg_cmd(i)._26_conf_endianess_as());
		(*net_signals)["IVT_MSG_CMD"]["_27_conf_endianess_wh"].push(pack->ivt_msg_cmd(i)._27_conf_endianess_wh());
		(*net_enums)["IVT_MSG_CMD"]["_20_conf_triggermode_i"].push(pack->ivt_msg_cmd(i)._20_conf_triggermode_i());
		hv_current_ivt_msg_cmd__20_conf_triggermode_i_enum_to_string((hv_current_ivt_msg_cmd__20_conf_triggermode_i)pack->ivt_msg_cmd(i)._20_conf_triggermode_i(), buffer);
		(*net_strings)["IVT_MSG_CMD"]["_20_conf_triggermode_i"].push(buffer);
		(*net_enums)["IVT_MSG_CMD"]["_21_conf_triggermode_u1"].push(pack->ivt_msg_cmd(i)._21_conf_triggermode_u1());
		hv_current_ivt_msg_cmd__21_conf_triggermode_u1_enum_to_string((hv_current_ivt_msg_cmd__21_conf_triggermode_u1)pack->ivt_msg_cmd(i)._21_conf_triggermode_u1(), buffer);
		(*net_strings)["IVT_MSG_CMD"]["_21_conf_triggermode_u1"].push(buffer);
		(*net_enums)["IVT_MSG_CMD"]["_22_conf_triggermode_u2"].push(pack->ivt_msg_cmd(i)._22_conf_triggermode_u2());
		hv_current_ivt_msg_cmd__22_conf_triggermode_u2_enum_to_string((hv_current_ivt_msg_cmd__22_conf_triggermode_u2)pack->ivt_msg_cmd(i)._22_conf_triggermode_u2(), buffer);
		(*net_strings)["IVT_MSG_CMD"]["_22_conf_triggermode_u2"].push(buffer);
		(*net_enums)["IVT_MSG_CMD"]["_23_conf_triggermode_u3"].push(pack->ivt_msg_cmd(i)._23_conf_triggermode_u3());
		hv_current_ivt_msg_cmd__23_conf_triggermode_u3_enum_to_string((hv_current_ivt_msg_cmd__23_conf_triggermode_u3)pack->ivt_msg_cmd(i)._23_conf_triggermode_u3(), buffer);
		(*net_strings)["IVT_MSG_CMD"]["_23_conf_triggermode_u3"].push(buffer);
		(*net_enums)["IVT_MSG_CMD"]["_24_conf_triggermode_t"].push(pack->ivt_msg_cmd(i)._24_conf_triggermode_t());
		hv_current_ivt_msg_cmd__24_conf_triggermode_t_enum_to_string((hv_current_ivt_msg_cmd__24_conf_triggermode_t)pack->ivt_msg_cmd(i)._24_conf_triggermode_t(), buffer);
		(*net_strings)["IVT_MSG_CMD"]["_24_conf_triggermode_t"].push(buffer);
		(*net_enums)["IVT_MSG_CMD"]["_25_conf_triggermode_w"].push(pack->ivt_msg_cmd(i)._25_conf_triggermode_w());
		hv_current_ivt_msg_cmd__25_conf_triggermode_w_enum_to_string((hv_current_ivt_msg_cmd__25_conf_triggermode_w)pack->ivt_msg_cmd(i)._25_conf_triggermode_w(), buffer);
		(*net_strings)["IVT_MSG_CMD"]["_25_conf_triggermode_w"].push(buffer);
		(*net_enums)["IVT_MSG_CMD"]["_26_conf_triggermode_as"].push(pack->ivt_msg_cmd(i)._26_conf_triggermode_as());
		hv_current_ivt_msg_cmd__26_conf_triggermode_as_enum_to_string((hv_current_ivt_msg_cmd__26_conf_triggermode_as)pack->ivt_msg_cmd(i)._26_conf_triggermode_as(), buffer);
		(*net_strings)["IVT_MSG_CMD"]["_26_conf_triggermode_as"].push(buffer);
		(*net_enums)["IVT_MSG_CMD"]["_27_conf_triggermode_wh"].push(pack->ivt_msg_cmd(i)._27_conf_triggermode_wh());
		hv_current_ivt_msg_cmd__27_conf_triggermode_wh_enum_to_string((hv_current_ivt_msg_cmd__27_conf_triggermode_wh)pack->ivt_msg_cmd(i)._27_conf_triggermode_wh(), buffer);
		(*net_strings)["IVT_MSG_CMD"]["_27_conf_triggermode_wh"].push(buffer);
		(*net_enums)["IVT_MSG_CMD"]["_34_actual_mode"].push(pack->ivt_msg_cmd(i)._34_actual_mode());
		hv_current_ivt_msg_cmd__34_actual_mode_enum_to_string((hv_current_ivt_msg_cmd__34_actual_mode)pack->ivt_msg_cmd(i)._34_actual_mode(), buffer);
		(*net_strings)["IVT_MSG_CMD"]["_34_actual_mode"].push(buffer);
		(*net_signals)["IVT_MSG_CMD"]["_31_07_trigger_wh"].push(pack->ivt_msg_cmd(i)._31_07_trigger_wh());
		(*net_signals)["IVT_MSG_CMD"]["_20_conf_cycletime_i"].push(pack->ivt_msg_cmd(i)._20_conf_cycletime_i());
		(*net_signals)["IVT_MSG_CMD"]["_21_conf_cycletime_u1"].push(pack->ivt_msg_cmd(i)._21_conf_cycletime_u1());
		(*net_signals)["IVT_MSG_CMD"]["_22_conf_cycletime_u2"].push(pack->ivt_msg_cmd(i)._22_conf_cycletime_u2());
		(*net_signals)["IVT_MSG_CMD"]["_23_conf_cycletime_u3"].push(pack->ivt_msg_cmd(i)._23_conf_cycletime_u3());
		(*net_signals)["IVT_MSG_CMD"]["_24_conf_cycletime_t"].push(pack->ivt_msg_cmd(i)._24_conf_cycletime_t());
		(*net_signals)["IVT_MSG_CMD"]["_25_conf_cycletime_w"].push(pack->ivt_msg_cmd(i)._25_conf_cycletime_w());
		(*net_signals)["IVT_MSG_CMD"]["_26_conf_cycletime_as"].push(pack->ivt_msg_cmd(i)._26_conf_cycletime_as());
		(*net_signals)["IVT_MSG_CMD"]["_27_conf_cycletime_wh"].push(pack->ivt_msg_cmd(i)._27_conf_cycletime_wh());
		(*net_signals)["IVT_MSG_CMD"]["_31_06_trigger_as"].push(pack->ivt_msg_cmd(i)._31_06_trigger_as());
		(*net_signals)["IVT_MSG_CMD"]["_31_05_trigger_w"].push(pack->ivt_msg_cmd(i)._31_05_trigger_w());
		(*net_signals)["IVT_MSG_CMD"]["_31_04_trigger_t"].push(pack->ivt_msg_cmd(i)._31_04_trigger_t());
		(*net_signals)["IVT_MSG_CMD"]["_31_03_trigger_u3"].push(pack->ivt_msg_cmd(i)._31_03_trigger_u3());
		(*net_signals)["IVT_MSG_CMD"]["_31_02_trigger_u2"].push(pack->ivt_msg_cmd(i)._31_02_trigger_u2());
		(*net_signals)["IVT_MSG_CMD"]["_31_01_trigger_u1"].push(pack->ivt_msg_cmd(i)._31_01_trigger_u1());
		(*net_signals)["IVT_MSG_CMD"]["_31_00_trigger_i"].push(pack->ivt_msg_cmd(i)._31_00_trigger_i());
		(*net_enums)["IVT_MSG_CMD"]["_34_startup_mode"].push(pack->ivt_msg_cmd(i)._34_startup_mode());
		hv_current_ivt_msg_cmd__34_startup_mode_enum_to_string((hv_current_ivt_msg_cmd__34_startup_mode)pack->ivt_msg_cmd(i)._34_startup_mode(), buffer);
		(*net_strings)["IVT_MSG_CMD"]["_34_startup_mode"].push(buffer);
		(*net_signals)["IVT_MSG_CMD"]["_10_set_can_id_sn_i"].push(pack->ivt_msg_cmd(i)._10_set_can_id_sn_i());
		(*net_signals)["IVT_MSG_CMD"]["_11_set_can_id_sn_u1"].push(pack->ivt_msg_cmd(i)._11_set_can_id_sn_u1());
		(*net_signals)["IVT_MSG_CMD"]["_12_set_can_id_sn_u2"].push(pack->ivt_msg_cmd(i)._12_set_can_id_sn_u2());
		(*net_signals)["IVT_MSG_CMD"]["_13_set_can_id_sn_u3"].push(pack->ivt_msg_cmd(i)._13_set_can_id_sn_u3());
		(*net_signals)["IVT_MSG_CMD"]["_14_set_can_id_sn_t"].push(pack->ivt_msg_cmd(i)._14_set_can_id_sn_t());
		(*net_signals)["IVT_MSG_CMD"]["_15_set_can_id_sn_w"].push(pack->ivt_msg_cmd(i)._15_set_can_id_sn_w());
		(*net_signals)["IVT_MSG_CMD"]["_16_set_can_id_sn_as"].push(pack->ivt_msg_cmd(i)._16_set_can_id_sn_as());
		(*net_signals)["IVT_MSG_CMD"]["_17_set_can_id_sn_wh"].push(pack->ivt_msg_cmd(i)._17_set_can_id_sn_wh());
		(*net_signals)["IVT_MSG_CMD"]["_1d_set_can_id_sn_command"].push(pack->ivt_msg_cmd(i)._1d_set_can_id_sn_command());
		(*net_signals)["IVT_MSG_CMD"]["_1f_set_can_id_sn_response"].push(pack->ivt_msg_cmd(i)._1f_set_can_id_sn_response());
		(*net_signals)["IVT_MSG_CMD"]["_30_reset_device_sn"].push(pack->ivt_msg_cmd(i)._30_reset_device_sn());
		(*net_signals)["IVT_MSG_CMD"]["_34_code_level"].push(pack->ivt_msg_cmd(i)._34_code_level());
		(*net_signals)["IVT_MSG_CMD"]["_35_oc_pos_reset_threshold"].push(pack->ivt_msg_cmd(i)._35_oc_pos_reset_threshold());
		(*net_signals)["IVT_MSG_CMD"]["_36_oc_neg_reset_threshold"].push(pack->ivt_msg_cmd(i)._36_oc_neg_reset_threshold());
		(*net_signals)["IVT_MSG_CMD"]["_50_get_can_id_sn_i"].push(pack->ivt_msg_cmd(i)._50_get_can_id_sn_i());
		(*net_signals)["IVT_MSG_CMD"]["_51_get_can_id_sn_u1"].push(pack->ivt_msg_cmd(i)._51_get_can_id_sn_u1());
		(*net_signals)["IVT_MSG_CMD"]["_52_get_can_id_sn_u2"].push(pack->ivt_msg_cmd(i)._52_get_can_id_sn_u2());
		(*net_signals)["IVT_MSG_CMD"]["_53_get_can_id_sn_u3"].push(pack->ivt_msg_cmd(i)._53_get_can_id_sn_u3());
		(*net_signals)["IVT_MSG_CMD"]["_54_get_can_id_sn_t"].push(pack->ivt_msg_cmd(i)._54_get_can_id_sn_t());
		(*net_signals)["IVT_MSG_CMD"]["_55_get_can_id_sn_w"].push(pack->ivt_msg_cmd(i)._55_get_can_id_sn_w());
		(*net_signals)["IVT_MSG_CMD"]["_56_get_can_id_sn_as"].push(pack->ivt_msg_cmd(i)._56_get_can_id_sn_as());
		(*net_signals)["IVT_MSG_CMD"]["_57_get_can_id_sn_wh"].push(pack->ivt_msg_cmd(i)._57_get_can_id_sn_wh());
		(*net_signals)["IVT_MSG_CMD"]["_5d_get_can_id_sn_command"].push(pack->ivt_msg_cmd(i)._5d_get_can_id_sn_command());
		(*net_signals)["IVT_MSG_CMD"]["_5f_get_can_id_sn_response"].push(pack->ivt_msg_cmd(i)._5f_get_can_id_sn_response());

    }

}

void hv_current_proto_interface_serialize_from_id(canlib_message_id id, hv_current::Pack* pack, device_t* device) {
    int index = hv_current_index_from_id(id);

    if (index == -1) return;

    switch(id) {
        
        case 1320: {
            hv_current_ivt_msg_result_wh_t* msg = (hv_current_ivt_msg_result_wh_t*)(device->message);
            hv_current::IVT_MSG_RESULT_WH* proto_msg = pack->add_ivt_msg_result_wh();
			proto_msg->set_ivt_id_result_wh((hv_current::hv_current_ivt_msg_result_wh_ivt_id_result_wh)msg->ivt_id_result_wh);
			proto_msg->set_ivt_result_wh_system_error(msg->ivt_result_wh_system_error);
			proto_msg->set_ivt_result_wh_measurement_error(msg->ivt_result_wh_measurement_error);
			proto_msg->set_ivt_result_wh_channel_error(msg->ivt_result_wh_channel_error);
			proto_msg->set_ivt_result_wh_ocs(msg->ivt_result_wh_ocs);
			proto_msg->set_ivt_msgcount_result_wh(msg->ivt_msgcount_result_wh);
			proto_msg->set_ivt_result_wh(msg->ivt_result_wh);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1319: {
            hv_current_ivt_msg_result_as_t* msg = (hv_current_ivt_msg_result_as_t*)(device->message);
            hv_current::IVT_MSG_RESULT_AS* proto_msg = pack->add_ivt_msg_result_as();
			proto_msg->set_ivt_id_result_as((hv_current::hv_current_ivt_msg_result_as_ivt_id_result_as)msg->ivt_id_result_as);
			proto_msg->set_ivt_result_as_system_error(msg->ivt_result_as_system_error);
			proto_msg->set_ivt_result_as_measurement_error(msg->ivt_result_as_measurement_error);
			proto_msg->set_ivt_result_as_channel_error(msg->ivt_result_as_channel_error);
			proto_msg->set_ivt_result_as_ocs(msg->ivt_result_as_ocs);
			proto_msg->set_ivt_msgcount_result_as(msg->ivt_msgcount_result_as);
			proto_msg->set_ivt_result_as(msg->ivt_result_as);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1318: {
            hv_current_ivt_msg_result_w_t* msg = (hv_current_ivt_msg_result_w_t*)(device->message);
            hv_current::IVT_MSG_RESULT_W* proto_msg = pack->add_ivt_msg_result_w();
			proto_msg->set_ivt_id_result_w((hv_current::hv_current_ivt_msg_result_w_ivt_id_result_w)msg->ivt_id_result_w);
			proto_msg->set_ivt_result_w_system_error(msg->ivt_result_w_system_error);
			proto_msg->set_ivt_result_w_measurement_error(msg->ivt_result_w_measurement_error);
			proto_msg->set_ivt_result_w_channel_error(msg->ivt_result_w_channel_error);
			proto_msg->set_ivt_result_w_ocs(msg->ivt_result_w_ocs);
			proto_msg->set_ivt_msgcount_result_w(msg->ivt_msgcount_result_w);
			proto_msg->set_ivt_result_w(msg->ivt_result_w);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1297: {
            hv_current_ivt_msg_response_t* msg = (hv_current_ivt_msg_response_t*)(device->message);
            hv_current::IVT_MSG_RESPONSE* proto_msg = pack->add_ivt_msg_response();
			proto_msg->set_ivt_id_response((hv_current::hv_current_ivt_msg_response_ivt_id_response)msg->ivt_id_response);
			proto_msg->set__b1_trigger_spare(msg->_b1_trigger_spare);
			proto_msg->set__ff_wrong_command(msg->_ff_wrong_command);
			proto_msg->set__bf_restart_alive_cmd_id(msg->_bf_restart_alive_cmd_id);
			proto_msg->set__80_resp_measerror_item((hv_current::hv_current_ivt_msg_response__80_resp_measerror_item)msg->_80_resp_measerror_item);
			proto_msg->set__81_resp_systemerror_item((hv_current::hv_current_ivt_msg_response__81_resp_systemerror_item)msg->_81_resp_systemerror_item);
			proto_msg->set__82_resp_alllogdata_item((hv_current::hv_current_ivt_msg_response__82_resp_alllogdata_item)msg->_82_resp_alllogdata_item);
			proto_msg->set__83_resp_logdata_item((hv_current::hv_current_ivt_msg_response__83_resp_logdata_item)msg->_83_resp_logdata_item);
			proto_msg->set__90_resp_can_id_val_i(msg->_90_resp_can_id_val_i);
			proto_msg->set__91_resp_can_id_val_u1(msg->_91_resp_can_id_val_u1);
			proto_msg->set__92_resp_can_id_val_u2(msg->_92_resp_can_id_val_u2);
			proto_msg->set__93_resp_can_id_val_u3(msg->_93_resp_can_id_val_u3);
			proto_msg->set__94_resp_can_id_val_t(msg->_94_resp_can_id_val_t);
			proto_msg->set__95_resp_can_id_val_w(msg->_95_resp_can_id_val_w);
			proto_msg->set__96_resp_can_id_val_as(msg->_96_resp_can_id_val_as);
			proto_msg->set__97_resp_can_id_val_wh(msg->_97_resp_can_id_val_wh);
			proto_msg->set__9d_resp_can_id_val_command(msg->_9d_resp_can_id_val_command);
			proto_msg->set__9f_resp_can_id_val_response(msg->_9f_resp_can_id_val_response);
			proto_msg->set__a0_resp_sign_i(msg->_a0_resp_sign_i);
			proto_msg->set__a1_resp_sign_u1(msg->_a1_resp_sign_u1);
			proto_msg->set__a2_resp_sign_u2(msg->_a2_resp_sign_u2);
			proto_msg->set__a3_resp_sign_u3(msg->_a3_resp_sign_u3);
			proto_msg->set__a4_resp_sign_t(msg->_a4_resp_sign_t);
			proto_msg->set__a5_resp_sign_w(msg->_a5_resp_sign_w);
			proto_msg->set__a6_resp_sign_as(msg->_a6_resp_sign_as);
			proto_msg->set__a7_resp_sign_wh(msg->_a7_resp_sign_wh);
			proto_msg->set__b0_resp_reset_item((hv_current::hv_current_ivt_msg_response__b0_resp_reset_item)msg->_b0_resp_reset_item);
			proto_msg->set__b2_resp_store_dummy(msg->_b2_resp_store_dummy);
			proto_msg->set__b3_resp_oc_test_time(msg->_b3_resp_oc_test_time);
			proto_msg->set__b5_resp_oc_pos_set_threshold(msg->_b5_resp_oc_pos_set_threshold);
			proto_msg->set__b6_resp_oc_neg_set_threshold(msg->_b6_resp_oc_neg_set_threshold);
			proto_msg->set__b9_resp_device_type((hv_current::hv_current_ivt_msg_response__b9_resp_device_type)msg->_b9_resp_device_type);
			proto_msg->set__ba_resp_sw_ver_major_hw(msg->_ba_resp_sw_ver_major_hw);
			proto_msg->set__bb_resp_serien_nr(msg->_bb_resp_serien_nr);
			proto_msg->set__bc_resp_art_n(msg->_bc_resp_art_n);
			proto_msg->set__a0_resp_endianess_i(msg->_a0_resp_endianess_i);
			proto_msg->set__a1_resp_endianess_u1(msg->_a1_resp_endianess_u1);
			proto_msg->set__a2_resp_endianess_u2(msg->_a2_resp_endianess_u2);
			proto_msg->set__a3_resp_endianess_u3(msg->_a3_resp_endianess_u3);
			proto_msg->set__a4_resp_endianess_t(msg->_a4_resp_endianess_t);
			proto_msg->set__a5_resp_endianess_w(msg->_a5_resp_endianess_w);
			proto_msg->set__a6_resp_endianess_as(msg->_a6_resp_endianess_as);
			proto_msg->set__a7_resp_endianess_wh(msg->_a7_resp_endianess_wh);
			proto_msg->set__a0_resp_triggermode_i((hv_current::hv_current_ivt_msg_response__a0_resp_triggermode_i)msg->_a0_resp_triggermode_i);
			proto_msg->set__a1_resp_triggermode_u1((hv_current::hv_current_ivt_msg_response__a1_resp_triggermode_u1)msg->_a1_resp_triggermode_u1);
			proto_msg->set__a2_resp_triggermode_u2((hv_current::hv_current_ivt_msg_response__a2_resp_triggermode_u2)msg->_a2_resp_triggermode_u2);
			proto_msg->set__a3_resp_triggermode_u3((hv_current::hv_current_ivt_msg_response__a3_resp_triggermode_u3)msg->_a3_resp_triggermode_u3);
			proto_msg->set__a4_resp_triggermode_t((hv_current::hv_current_ivt_msg_response__a4_resp_triggermode_t)msg->_a4_resp_triggermode_t);
			proto_msg->set__a5_resp_triggermode_w((hv_current::hv_current_ivt_msg_response__a5_resp_triggermode_w)msg->_a5_resp_triggermode_w);
			proto_msg->set__a6_resp_triggermode_as((hv_current::hv_current_ivt_msg_response__a6_resp_triggermode_as)msg->_a6_resp_triggermode_as);
			proto_msg->set__a7_resp_triggermode_wh((hv_current::hv_current_ivt_msg_response__a7_resp_triggermode_wh)msg->_a7_resp_triggermode_wh);
			proto_msg->set__b4_resp_actual_mode((hv_current::hv_current_ivt_msg_response__b4_resp_actual_mode)msg->_b4_resp_actual_mode);
			proto_msg->set__b1_07_trigger_wh(msg->_b1_07_trigger_wh);
			proto_msg->set__b2_resp_store_device_sn(msg->_b2_resp_store_device_sn);
			proto_msg->set__ba_resp_sw_ver_minor(msg->_ba_resp_sw_ver_minor);
			proto_msg->set__b9_resp_device_current((hv_current::hv_current_ivt_msg_response__b9_resp_device_current)msg->_b9_resp_device_current);
			proto_msg->set__80_resp_measerror_count_mask(msg->_80_resp_measerror_count_mask);
			proto_msg->set__81_resp_systemerror_count_mask(msg->_81_resp_systemerror_count_mask);
			proto_msg->set__82_resp_alllogdata_counter(msg->_82_resp_alllogdata_counter);
			proto_msg->set__83_resp_logdata_counter(msg->_83_resp_logdata_counter);
			proto_msg->set__a0_resp_cycletime_i(msg->_a0_resp_cycletime_i);
			proto_msg->set__a1_resp_cycletime_u1(msg->_a1_resp_cycletime_u1);
			proto_msg->set__a2_resp_cycletime_u2(msg->_a2_resp_cycletime_u2);
			proto_msg->set__a3_resp_cycletime_u3(msg->_a3_resp_cycletime_u3);
			proto_msg->set__a4_resp_cycletime_t(msg->_a4_resp_cycletime_t);
			proto_msg->set__a5_resp_cycletime_w(msg->_a5_resp_cycletime_w);
			proto_msg->set__a6_resp_cycletime_as(msg->_a6_resp_cycletime_as);
			proto_msg->set__a7_resp_cycletime_wh(msg->_a7_resp_cycletime_wh);
			proto_msg->set__b1_06_trigger_as(msg->_b1_06_trigger_as);
			proto_msg->set__b1_05_trigger_w(msg->_b1_05_trigger_w);
			proto_msg->set__b1_04_trigger_t(msg->_b1_04_trigger_t);
			proto_msg->set__b1_03_trigger_u3(msg->_b1_03_trigger_u3);
			proto_msg->set__b1_02_trigger_u2(msg->_b1_02_trigger_u2);
			proto_msg->set__b1_01_trigger_u1(msg->_b1_01_trigger_u1);
			proto_msg->set__b1_00_trigger_i(msg->_b1_00_trigger_i);
			proto_msg->set__b4_resp_startup_mode((hv_current::hv_current_ivt_msg_response__b4_resp_startup_mode)msg->_b4_resp_startup_mode);
			proto_msg->set__bf_restart_alive_sn(msg->_bf_restart_alive_sn);
			proto_msg->set__ba_resp_sw_ver_revision(msg->_ba_resp_sw_ver_revision);
			proto_msg->set__90_resp_can_id_sn_i(msg->_90_resp_can_id_sn_i);
			proto_msg->set__91_resp_can_id_sn_u1(msg->_91_resp_can_id_sn_u1);
			proto_msg->set__92_resp_can_id_sn_u2(msg->_92_resp_can_id_sn_u2);
			proto_msg->set__93_resp_can_id_sn_u3(msg->_93_resp_can_id_sn_u3);
			proto_msg->set__94_resp_can_id_sn_t(msg->_94_resp_can_id_sn_t);
			proto_msg->set__95_resp_can_id_sn_w(msg->_95_resp_can_id_sn_w);
			proto_msg->set__96_resp_can_id_sn_as(msg->_96_resp_can_id_sn_as);
			proto_msg->set__97_resp_can_id_sn_wh(msg->_97_resp_can_id_sn_wh);
			proto_msg->set__9d_resp_can_id_sn_command(msg->_9d_resp_can_id_sn_command);
			proto_msg->set__9f_resp_can_id_sn_response(msg->_9f_resp_can_id_sn_response);
			proto_msg->set__b0_resp_reset_device_sn(msg->_b0_resp_reset_device_sn);
			proto_msg->set__b4_resp_code_level(msg->_b4_resp_code_level);
			proto_msg->set__b5_resp_oc_pos_reset_threshold(msg->_b5_resp_oc_pos_reset_threshold);
			proto_msg->set__b6_resp_oc_neg_reset_threshold(msg->_b6_resp_oc_neg_reset_threshold);
			proto_msg->set__b9_resp_device_voltage_chan((hv_current::hv_current_ivt_msg_response__b9_resp_device_voltage_chan)msg->_b9_resp_device_voltage_chan);
			proto_msg->set__ba_resp_sw_ver_vear(msg->_ba_resp_sw_ver_vear);
			proto_msg->set__b9_resp_device_toi((hv_current::hv_current_ivt_msg_response__b9_resp_device_toi)msg->_b9_resp_device_toi);
			proto_msg->set__ba_resp_sw_ver_month(msg->_ba_resp_sw_ver_month);
			proto_msg->set__b9_resp_device_com((hv_current::hv_current_ivt_msg_response__b9_resp_device_com)msg->_b9_resp_device_com);
			proto_msg->set__ba_resp_sw_ver_day(msg->_ba_resp_sw_ver_day);
			proto_msg->set__b9_resp_device_v_supply((hv_current::hv_current_ivt_msg_response__b9_resp_device_v_supply)msg->_b9_resp_device_v_supply);
			proto_msg->set__ba_resp_sw_ver_internal(msg->_ba_resp_sw_ver_internal);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1317: {
            hv_current_ivt_msg_result_t_converted_t* msg = (hv_current_ivt_msg_result_t_converted_t*)(device->message);
            hv_current::IVT_MSG_RESULT_T* proto_msg = pack->add_ivt_msg_result_t();
			proto_msg->set_ivt_id_result_t((hv_current::hv_current_ivt_msg_result_t_ivt_id_result_t)msg->ivt_id_result_t);
			proto_msg->set_ivt_result_t_system_error(msg->ivt_result_t_system_error);
			proto_msg->set_ivt_result_t_measurement_error(msg->ivt_result_t_measurement_error);
			proto_msg->set_ivt_result_t_channel_error(msg->ivt_result_t_channel_error);
			proto_msg->set_ivt_result_t_ocs(msg->ivt_result_t_ocs);
			proto_msg->set_ivt_msgcount_result_t(msg->ivt_msgcount_result_t);
			proto_msg->set_ivt_result_t(msg->ivt_result_t);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1316: {
            hv_current_ivt_msg_result_u3_t* msg = (hv_current_ivt_msg_result_u3_t*)(device->message);
            hv_current::IVT_MSG_RESULT_U3* proto_msg = pack->add_ivt_msg_result_u3();
			proto_msg->set_ivt_id_result_u3((hv_current::hv_current_ivt_msg_result_u3_ivt_id_result_u3)msg->ivt_id_result_u3);
			proto_msg->set_ivt_result_u3_system_error(msg->ivt_result_u3_system_error);
			proto_msg->set_ivt_result_u3_measurement_error(msg->ivt_result_u3_measurement_error);
			proto_msg->set_ivt_result_u3_channel_error(msg->ivt_result_u3_channel_error);
			proto_msg->set_ivt_result_u3_ocs(msg->ivt_result_u3_ocs);
			proto_msg->set_ivt_msgcount_result_u3(msg->ivt_msgcount_result_u3);
			proto_msg->set_ivt_result_u3(msg->ivt_result_u3);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1315: {
            hv_current_ivt_msg_result_u2_t* msg = (hv_current_ivt_msg_result_u2_t*)(device->message);
            hv_current::IVT_MSG_RESULT_U2* proto_msg = pack->add_ivt_msg_result_u2();
			proto_msg->set_ivt_id_result_u2((hv_current::hv_current_ivt_msg_result_u2_ivt_id_result_u2)msg->ivt_id_result_u2);
			proto_msg->set_ivt_result_u2_system_error(msg->ivt_result_u2_system_error);
			proto_msg->set_ivt_result_u2_measurement_error(msg->ivt_result_u2_measurement_error);
			proto_msg->set_ivt_result_u2_channel_error(msg->ivt_result_u2_channel_error);
			proto_msg->set_ivt_result_u2_ocs(msg->ivt_result_u2_ocs);
			proto_msg->set_ivt_msgcount_result_u2(msg->ivt_msgcount_result_u2);
			proto_msg->set_ivt_result_u2(msg->ivt_result_u2);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1314: {
            hv_current_ivt_msg_result_u1_t* msg = (hv_current_ivt_msg_result_u1_t*)(device->message);
            hv_current::IVT_MSG_RESULT_U1* proto_msg = pack->add_ivt_msg_result_u1();
			proto_msg->set_ivt_id_result_u1((hv_current::hv_current_ivt_msg_result_u1_ivt_id_result_u1)msg->ivt_id_result_u1);
			proto_msg->set_ivt_result_u1_system_error(msg->ivt_result_u1_system_error);
			proto_msg->set_ivt_result_u1_measurement_error(msg->ivt_result_u1_measurement_error);
			proto_msg->set_ivt_result_u1_channel_error(msg->ivt_result_u1_channel_error);
			proto_msg->set_ivt_result_u1_ocs(msg->ivt_result_u1_ocs);
			proto_msg->set_ivt_msgcount_result_u1(msg->ivt_msgcount_result_u1);
			proto_msg->set_ivt_result_u1(msg->ivt_result_u1);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1313: {
            hv_current_ivt_msg_result_i_t* msg = (hv_current_ivt_msg_result_i_t*)(device->message);
            hv_current::IVT_MSG_RESULT_I* proto_msg = pack->add_ivt_msg_result_i();
			proto_msg->set_ivt_id_result_i((hv_current::hv_current_ivt_msg_result_i_ivt_id_result_i)msg->ivt_id_result_i);
			proto_msg->set_ivt_result_i_system_error(msg->ivt_result_i_system_error);
			proto_msg->set_ivt_result_i_measurement_error(msg->ivt_result_i_measurement_error);
			proto_msg->set_ivt_result_i_channel_error(msg->ivt_result_i_channel_error);
			proto_msg->set_ivt_result_i_ocs(msg->ivt_result_i_ocs);
			proto_msg->set_ivt_msgcount_result_i(msg->ivt_msgcount_result_i);
			proto_msg->set_ivt_result_i(msg->ivt_result_i);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1041: {
            hv_current_ivt_msg_cmd_t* msg = (hv_current_ivt_msg_cmd_t*)(device->message);
            hv_current::IVT_MSG_CMD* proto_msg = pack->add_ivt_msg_cmd();
			proto_msg->set_ivt_id_cmd((hv_current::hv_current_ivt_msg_cmd_ivt_id_cmd)msg->ivt_id_cmd);
			proto_msg->set__31_trigger_spare(msg->_31_trigger_spare);
			proto_msg->set__10_set_can_id_val_i(msg->_10_set_can_id_val_i);
			proto_msg->set__11_set_can_id_val_u1(msg->_11_set_can_id_val_u1);
			proto_msg->set__12_set_can_id_val_u2(msg->_12_set_can_id_val_u2);
			proto_msg->set__13_set_can_id_val_u3(msg->_13_set_can_id_val_u3);
			proto_msg->set__14_set_can_id_val_t(msg->_14_set_can_id_val_t);
			proto_msg->set__15_set_can_id_val_w(msg->_15_set_can_id_val_w);
			proto_msg->set__16_set_can_id_val_as(msg->_16_set_can_id_val_as);
			proto_msg->set__17_set_can_id_val_wh(msg->_17_set_can_id_val_wh);
			proto_msg->set__1d_set_can_id_val_command(msg->_1d_set_can_id_val_command);
			proto_msg->set__1f_set_can_id_val_response(msg->_1f_set_can_id_val_response);
			proto_msg->set__20_conf_sign_i(msg->_20_conf_sign_i);
			proto_msg->set__21_conf_sign_u1(msg->_21_conf_sign_u1);
			proto_msg->set__22_conf_sign_u2(msg->_22_conf_sign_u2);
			proto_msg->set__23_conf_sign_u3(msg->_23_conf_sign_u3);
			proto_msg->set__24_conf_sign_t(msg->_24_conf_sign_t);
			proto_msg->set__25_conf_sign_w(msg->_25_conf_sign_w);
			proto_msg->set__26_conf_sign_as(msg->_26_conf_sign_as);
			proto_msg->set__27_conf_sign_wh(msg->_27_conf_sign_wh);
			proto_msg->set__30_reset_item((hv_current::hv_current_ivt_msg_cmd__30_reset_item)msg->_30_reset_item);
			proto_msg->set__32_store_dummy(msg->_32_store_dummy);
			proto_msg->set__33_oc_test_time(msg->_33_oc_test_time);
			proto_msg->set__35_oc_pos_set_threshold(msg->_35_oc_pos_set_threshold);
			proto_msg->set__36_oc_neg_set_threshold(msg->_36_oc_neg_set_threshold);
			proto_msg->set__3a_restart_to_bitrate((hv_current::hv_current_ivt_msg_cmd__3a_restart_to_bitrate)msg->_3a_restart_to_bitrate);
			proto_msg->set__3d_restart_default_dummy(msg->_3d_restart_default_dummy);
			proto_msg->set__3f_restart_dummy(msg->_3f_restart_dummy);
			proto_msg->set__40_get_measerror_item((hv_current::hv_current_ivt_msg_cmd__40_get_measerror_item)msg->_40_get_measerror_item);
			proto_msg->set__41_get_systemerror_item((hv_current::hv_current_ivt_msg_cmd__41_get_systemerror_item)msg->_41_get_systemerror_item);
			proto_msg->set__42_get_alllogdata_item((hv_current::hv_current_ivt_msg_cmd__42_get_alllogdata_item)msg->_42_get_alllogdata_item);
			proto_msg->set__43_get_logdata_item((hv_current::hv_current_ivt_msg_cmd__43_get_logdata_item)msg->_43_get_logdata_item);
			proto_msg->set__60_get_result_dummy_i(msg->_60_get_result_dummy_i);
			proto_msg->set__61_get_result_dummy_u1(msg->_61_get_result_dummy_u1);
			proto_msg->set__62_get_result_dummy_u2(msg->_62_get_result_dummy_u2);
			proto_msg->set__63_get_result_dummy_u3(msg->_63_get_result_dummy_u3);
			proto_msg->set__64_get_result_dummy_t(msg->_64_get_result_dummy_t);
			proto_msg->set__65_get_result_dummy_w(msg->_65_get_result_dummy_w);
			proto_msg->set__66_get_result_dummy_as(msg->_66_get_result_dummy_as);
			proto_msg->set__67_get_result_dummy_wh(msg->_67_get_result_dummy_wh);
			proto_msg->set__73_get_oc_test_dummy(msg->_73_get_oc_test_dummy);
			proto_msg->set__74_get_mode_dummy(msg->_74_get_mode_dummy);
			proto_msg->set__75_get_oc_pos_dummy(msg->_75_get_oc_pos_dummy);
			proto_msg->set__76_get_oc_neg_dummy(msg->_76_get_oc_neg_dummy);
			proto_msg->set__79_get_device_id_dummy(msg->_79_get_device_id_dummy);
			proto_msg->set__7a_get_sw_version_dummy(msg->_7a_get_sw_version_dummy);
			proto_msg->set__7b_get_serien_nr_dummy(msg->_7b_get_serien_nr_dummy);
			proto_msg->set__7c_get_art_nr_dummy(msg->_7c_get_art_nr_dummy);
			proto_msg->set__20_conf_endianess_i(msg->_20_conf_endianess_i);
			proto_msg->set__21_conf_endianess_u1(msg->_21_conf_endianess_u1);
			proto_msg->set__22_conf_endianess_u2(msg->_22_conf_endianess_u2);
			proto_msg->set__23_conf_endianess_u3(msg->_23_conf_endianess_u3);
			proto_msg->set__24_conf_endianess_t(msg->_24_conf_endianess_t);
			proto_msg->set__25_conf_endianess_w(msg->_25_conf_endianess_w);
			proto_msg->set__26_conf_endianess_as(msg->_26_conf_endianess_as);
			proto_msg->set__27_conf_endianess_wh(msg->_27_conf_endianess_wh);
			proto_msg->set__20_conf_triggermode_i((hv_current::hv_current_ivt_msg_cmd__20_conf_triggermode_i)msg->_20_conf_triggermode_i);
			proto_msg->set__21_conf_triggermode_u1((hv_current::hv_current_ivt_msg_cmd__21_conf_triggermode_u1)msg->_21_conf_triggermode_u1);
			proto_msg->set__22_conf_triggermode_u2((hv_current::hv_current_ivt_msg_cmd__22_conf_triggermode_u2)msg->_22_conf_triggermode_u2);
			proto_msg->set__23_conf_triggermode_u3((hv_current::hv_current_ivt_msg_cmd__23_conf_triggermode_u3)msg->_23_conf_triggermode_u3);
			proto_msg->set__24_conf_triggermode_t((hv_current::hv_current_ivt_msg_cmd__24_conf_triggermode_t)msg->_24_conf_triggermode_t);
			proto_msg->set__25_conf_triggermode_w((hv_current::hv_current_ivt_msg_cmd__25_conf_triggermode_w)msg->_25_conf_triggermode_w);
			proto_msg->set__26_conf_triggermode_as((hv_current::hv_current_ivt_msg_cmd__26_conf_triggermode_as)msg->_26_conf_triggermode_as);
			proto_msg->set__27_conf_triggermode_wh((hv_current::hv_current_ivt_msg_cmd__27_conf_triggermode_wh)msg->_27_conf_triggermode_wh);
			proto_msg->set__34_actual_mode((hv_current::hv_current_ivt_msg_cmd__34_actual_mode)msg->_34_actual_mode);
			proto_msg->set__31_07_trigger_wh(msg->_31_07_trigger_wh);
			proto_msg->set__20_conf_cycletime_i(msg->_20_conf_cycletime_i);
			proto_msg->set__21_conf_cycletime_u1(msg->_21_conf_cycletime_u1);
			proto_msg->set__22_conf_cycletime_u2(msg->_22_conf_cycletime_u2);
			proto_msg->set__23_conf_cycletime_u3(msg->_23_conf_cycletime_u3);
			proto_msg->set__24_conf_cycletime_t(msg->_24_conf_cycletime_t);
			proto_msg->set__25_conf_cycletime_w(msg->_25_conf_cycletime_w);
			proto_msg->set__26_conf_cycletime_as(msg->_26_conf_cycletime_as);
			proto_msg->set__27_conf_cycletime_wh(msg->_27_conf_cycletime_wh);
			proto_msg->set__31_06_trigger_as(msg->_31_06_trigger_as);
			proto_msg->set__31_05_trigger_w(msg->_31_05_trigger_w);
			proto_msg->set__31_04_trigger_t(msg->_31_04_trigger_t);
			proto_msg->set__31_03_trigger_u3(msg->_31_03_trigger_u3);
			proto_msg->set__31_02_trigger_u2(msg->_31_02_trigger_u2);
			proto_msg->set__31_01_trigger_u1(msg->_31_01_trigger_u1);
			proto_msg->set__31_00_trigger_i(msg->_31_00_trigger_i);
			proto_msg->set__34_startup_mode((hv_current::hv_current_ivt_msg_cmd__34_startup_mode)msg->_34_startup_mode);
			proto_msg->set__10_set_can_id_sn_i(msg->_10_set_can_id_sn_i);
			proto_msg->set__11_set_can_id_sn_u1(msg->_11_set_can_id_sn_u1);
			proto_msg->set__12_set_can_id_sn_u2(msg->_12_set_can_id_sn_u2);
			proto_msg->set__13_set_can_id_sn_u3(msg->_13_set_can_id_sn_u3);
			proto_msg->set__14_set_can_id_sn_t(msg->_14_set_can_id_sn_t);
			proto_msg->set__15_set_can_id_sn_w(msg->_15_set_can_id_sn_w);
			proto_msg->set__16_set_can_id_sn_as(msg->_16_set_can_id_sn_as);
			proto_msg->set__17_set_can_id_sn_wh(msg->_17_set_can_id_sn_wh);
			proto_msg->set__1d_set_can_id_sn_command(msg->_1d_set_can_id_sn_command);
			proto_msg->set__1f_set_can_id_sn_response(msg->_1f_set_can_id_sn_response);
			proto_msg->set__30_reset_device_sn(msg->_30_reset_device_sn);
			proto_msg->set__34_code_level(msg->_34_code_level);
			proto_msg->set__35_oc_pos_reset_threshold(msg->_35_oc_pos_reset_threshold);
			proto_msg->set__36_oc_neg_reset_threshold(msg->_36_oc_neg_reset_threshold);
			proto_msg->set__50_get_can_id_sn_i(msg->_50_get_can_id_sn_i);
			proto_msg->set__51_get_can_id_sn_u1(msg->_51_get_can_id_sn_u1);
			proto_msg->set__52_get_can_id_sn_u2(msg->_52_get_can_id_sn_u2);
			proto_msg->set__53_get_can_id_sn_u3(msg->_53_get_can_id_sn_u3);
			proto_msg->set__54_get_can_id_sn_t(msg->_54_get_can_id_sn_t);
			proto_msg->set__55_get_can_id_sn_w(msg->_55_get_can_id_sn_w);
			proto_msg->set__56_get_can_id_sn_as(msg->_56_get_can_id_sn_as);
			proto_msg->set__57_get_can_id_sn_wh(msg->_57_get_can_id_sn_wh);
			proto_msg->set__5d_get_can_id_sn_command(msg->_5d_get_can_id_sn_command);
			proto_msg->set__5f_get_can_id_sn_response(msg->_5f_get_can_id_sn_response);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

    }
}



#endif // hv_current_PROTO_INTERAFCE_IMPLEMENTATION

#endif // hv_current_PROTO_INTERFACE_H
