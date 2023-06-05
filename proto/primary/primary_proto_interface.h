
#ifndef primary_PROTO_INTERFACE_H
#define primary_PROTO_INTERFACE_H

#include <string>
#include <unordered_map>
#include <functional>

#include "primary.pb.h"

#ifdef primary_IMPLEMENTATION
#undef primary_IMPLEMENTATION
#define __primary_IMPLEMENTATION
#endif

#include "../../lib/primary/primary_network.h"

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

void primary_proto_interface_serialize_from_id(canlib_message_id id, primary::Pack* pack, primary_devices* map);
void primary_proto_interface_deserialize(primary::Pack* pack, network_enums* net_enums, network_signals* net_signals, network_strings* net_strings, uint64_t resample_us);

#ifdef primary_PROTO_INTERAFCE_IMPLEMENTATION

void primary_proto_interface_deserialize(primary::Pack* pack, network_enums* net_enums, network_signals* net_signals, network_strings* net_strings, uint64_t resample_us) {
    char buffer[1024];
    
    for(int i = 0; i < pack->inverter_l_send_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->inverter_l_send(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->inverter_l_send(i)._inner_timestamp();
        (*net_signals)["INVERTER_L_SEND"]["_timestamp"].push(pack->inverter_l_send(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["INVERTER_L_SEND"]["send_mux"].push(pack->inverter_l_send(i).send_mux());
		primary_inverter_l_send_send_mux_enum_to_string((primary_inverter_l_send_send_mux)pack->inverter_l_send(i).send_mux(), buffer);
		(*net_strings)["INVERTER_L_SEND"]["send_mux"].push(buffer);
		(*net_signals)["INVERTER_L_SEND"]["motor_f_n"].push(pack->inverter_l_send(i).motor_f_n());
		(*net_signals)["INVERTER_L_SEND"]["t_dc__start"].push(pack->inverter_l_send(i).t_dc__start());
		(*net_signals)["INVERTER_L_SEND"]["v_dc__start"].push(pack->inverter_l_send(i).v_dc__start());
		(*net_signals)["INVERTER_L_SEND"]["special__start"].push(pack->inverter_l_send(i).special__start());
		(*net_signals)["INVERTER_L_SEND"]["v_min__start"].push(pack->inverter_l_send(i).v_min__start());
		(*net_signals)["INVERTER_L_SEND"]["f_min__start"].push(pack->inverter_l_send(i).f_min__start());
		(*net_signals)["INVERTER_L_SEND"]["v_corner__start"].push(pack->inverter_l_send(i).v_corner__start());
		(*net_signals)["INVERTER_L_SEND"]["f_corner__start"].push(pack->inverter_l_send(i).f_corner__start());
		(*net_signals)["INVERTER_L_SEND"]["cos_phi"].push(pack->inverter_l_send(i).cos_phi());
		(*net_signals)["INVERTER_L_SEND"]["extra__start"].push(pack->inverter_l_send(i).extra__start());
		(*net_signals)["INVERTER_L_SEND"]["capture_channel"].push(pack->inverter_l_send(i).capture_channel());
		(*net_signals)["INVERTER_L_SEND"]["trig_level"].push(pack->inverter_l_send(i).trig_level());
		(*net_signals)["INVERTER_L_SEND"]["trig_edge"].push(pack->inverter_l_send(i).trig_edge());
		(*net_signals)["INVERTER_L_SEND"]["trig_source"].push(pack->inverter_l_send(i).trig_source());
		(*net_signals)["INVERTER_L_SEND"]["oszi_source"].push(pack->inverter_l_send(i).oszi_source());
		(*net_signals)["INVERTER_L_SEND"]["oszi_skip"].push(pack->inverter_l_send(i).oszi_skip());
		(*net_signals)["INVERTER_L_SEND"]["oszi_read_cmd"].push(pack->inverter_l_send(i).oszi_read_cmd());
		(*net_signals)["INVERTER_L_SEND"]["oszi_run_cmd"].push(pack->inverter_l_send(i).oszi_run_cmd());
		(*net_signals)["INVERTER_L_SEND"]["calib_ref_value"].push(pack->inverter_l_send(i).calib_ref_value());
		(*net_signals)["INVERTER_L_SEND"]["pid_i__kp__iq"].push(pack->inverter_l_send(i).pid_i__kp__iq());
		(*net_signals)["INVERTER_L_SEND"]["pid_i__ti__iq"].push(pack->inverter_l_send(i).pid_i__ti__iq());
		(*net_signals)["INVERTER_L_SEND"]["cutoffdig"].push(pack->inverter_l_send(i).cutoffdig());
		(*net_signals)["INVERTER_L_SEND"]["id_setdig__id"].push(pack->inverter_l_send(i).id_setdig__id());
		(*net_signals)["INVERTER_L_SEND"]["i_delta_ramp"].push(pack->inverter_l_send(i).i_delta_ramp());
		(*net_signals)["INVERTER_L_SEND"]["pid_i__tim__iq"].push(pack->inverter_l_send(i).pid_i__tim__iq());
		(*net_signals)["INVERTER_L_SEND"]["pid_n__kp"].push(pack->inverter_l_send(i).pid_n__kp());
		(*net_signals)["INVERTER_L_SEND"]["pid_n__ti"].push(pack->inverter_l_send(i).pid_n__ti());
		(*net_signals)["INVERTER_L_SEND"]["pid_n__td"].push(pack->inverter_l_send(i).pid_n__td());
		(*net_signals)["INVERTER_L_SEND"]["ain_in_1_offsetval"].push(pack->inverter_l_send(i).ain_in_1_offsetval());
		(*net_signals)["INVERTER_L_SEND"]["n_setdig"].push(pack->inverter_l_send(i).n_setdig());
		(*net_signals)["INVERTER_L_SEND"]["n_lim"].push(pack->inverter_l_send(i).n_lim());
		(*net_signals)["INVERTER_L_SEND"]["n_r_acc"].push(pack->inverter_l_send(i).n_r_acc());
		(*net_enums)["INVERTER_L_SEND"]["cs_ain_1_format"].push(pack->inverter_l_send(i).cs_ain_1_format());
		primary_inverter_l_send_cs_ain_1_format_enum_to_string((primary_inverter_l_send_cs_ain_1_format)pack->inverter_l_send(i).cs_ain_1_format(), buffer);
		(*net_strings)["INVERTER_L_SEND"]["cs_ain_1_format"].push(buffer);
		(*net_signals)["INVERTER_L_SEND"]["pid_n__tim"].push(pack->inverter_l_send(i).pid_n__tim());
		(*net_signals)["INVERTER_L_SEND"]["i_red_n"].push(pack->inverter_l_send(i).i_red_n());
		(*net_signals)["INVERTER_L_SEND"]["n_lim_minus"].push(pack->inverter_l_send(i).n_lim_minus());
		(*net_signals)["INVERTER_L_SEND"]["n_lim_plus"].push(pack->inverter_l_send(i).n_lim_plus());
		(*net_signals)["INVERTER_L_SEND"]["fb_offset"].push(pack->inverter_l_send(i).fb_offset());
		(*net_enums)["INVERTER_L_SEND"]["read_id"].push(pack->inverter_l_send(i).read_id());
		primary_inverter_l_send_read_id_enum_to_string((primary_inverter_l_send_read_id)pack->inverter_l_send(i).read_id(), buffer);
		(*net_strings)["INVERTER_L_SEND"]["read_id"].push(buffer);
		(*net_signals)["INVERTER_L_SEND"]["i_lim_dig"].push(pack->inverter_l_send(i).i_lim_dig());
		(*net_signals)["INVERTER_L_SEND"]["i_red_te"].push(pack->inverter_l_send(i).i_red_te());
		(*net_signals)["INVERTER_L_SEND"]["i_max_eff"].push(pack->inverter_l_send(i).i_max_eff());
		(*net_signals)["INVERTER_L_SEND"]["i_nom_eff"].push(pack->inverter_l_send(i).i_nom_eff());
		(*net_signals)["INVERTER_L_SEND"]["motor_pole"].push(pack->inverter_l_send(i).motor_pole());
		(*net_signals)["INVERTER_L_SEND"]["ain_in_1_cutoff"].push(pack->inverter_l_send(i).ain_in_1_cutoff());
		(*net_signals)["INVERTER_L_SEND"]["km_rsvd_0"].push(pack->inverter_l_send(i).km_rsvd_0());
		(*net_signals)["INVERTER_L_SEND"]["ain_in_2_cutoff"].push(pack->inverter_l_send(i).ain_in_2_cutoff());
		(*net_signals)["INVERTER_L_SEND"]["i_red_td"].push(pack->inverter_l_send(i).i_red_td());
		(*net_signals)["INVERTER_L_SEND"]["n_nom"].push(pack->inverter_l_send(i).n_nom());
		(*net_signals)["INVERTER_L_SEND"]["dc_bus_comp"].push(pack->inverter_l_send(i).dc_bus_comp());
		(*net_signals)["INVERTER_L_SEND"]["pid_n__kacc"].push(pack->inverter_l_send(i).pid_n__kacc());
		(*net_signals)["INVERTER_L_SEND"]["speed_filter"].push(pack->inverter_l_send(i).speed_filter());
		(*net_signals)["INVERTER_L_SEND"]["ain_in_1_filter"].push(pack->inverter_l_send(i).ain_in_1_filter());
		(*net_signals)["INVERTER_L_SEND"]["snr"].push(pack->inverter_l_send(i).snr());
		(*net_signals)["INVERTER_L_SEND"]["device_mains"].push(pack->inverter_l_send(i).device_mains());
		(*net_signals)["INVERTER_L_SEND"]["regen_p"].push(pack->inverter_l_send(i).regen_p());
		(*net_enums)["INVERTER_L_SEND"]["devicetype"].push(pack->inverter_l_send(i).devicetype());
		primary_inverter_l_send_devicetype_enum_to_string((primary_inverter_l_send_devicetype)pack->inverter_l_send(i).devicetype(), buffer);
		(*net_strings)["INVERTER_L_SEND"]["devicetype"].push(buffer);
		(*net_signals)["INVERTER_L_SEND"]["can_id_rx"].push(pack->inverter_l_send(i).can_id_rx());
		(*net_signals)["INVERTER_L_SEND"]["can_id_tx"].push(pack->inverter_l_send(i).can_id_tx());
		(*net_signals)["INVERTER_L_SEND"]["pos_kp"].push(pack->inverter_l_send(i).pos_kp());
		(*net_signals)["INVERTER_L_SEND"]["pos_ti"].push(pack->inverter_l_send(i).pos_ti());
		(*net_signals)["INVERTER_L_SEND"]["pos_td"].push(pack->inverter_l_send(i).pos_td());
		(*net_signals)["INVERTER_L_SEND"]["pos_dest"].push(pack->inverter_l_send(i).pos_dest());
		(*net_signals)["INVERTER_L_SEND"]["pos_tim"].push(pack->inverter_l_send(i).pos_tim());
		(*net_signals)["INVERTER_L_SEND"]["pos_offsref"].push(pack->inverter_l_send(i).pos_offsref());
		(*net_enums)["INVERTER_L_SEND"]["can_nbt"].push(pack->inverter_l_send(i).can_nbt());
		primary_inverter_l_send_can_nbt_enum_to_string((primary_inverter_l_send_can_nbt)pack->inverter_l_send(i).can_nbt(), buffer);
		(*net_strings)["INVERTER_L_SEND"]["can_nbt"].push(buffer);
		(*net_signals)["INVERTER_L_SEND"]["ref_reso_edge"].push(pack->inverter_l_send(i).ref_reso_edge());
		(*net_signals)["INVERTER_L_SEND"]["speed_1"].push(pack->inverter_l_send(i).speed_1());
		(*net_signals)["INVERTER_L_SEND"]["speed_2"].push(pack->inverter_l_send(i).speed_2());
		(*net_signals)["INVERTER_L_SEND"]["pos_tol_win"].push(pack->inverter_l_send(i).pos_tol_win());
		(*net_signals)["INVERTER_L_SEND"]["pos_preset_val"].push(pack->inverter_l_send(i).pos_preset_val());
		(*net_signals)["INVERTER_L_SEND"]["pos_nd_scale"].push(pack->inverter_l_send(i).pos_nd_scale());
		(*net_signals)["INVERTER_L_SEND"]["pos_nd_offset"].push(pack->inverter_l_send(i).pos_nd_offset());
		(*net_signals)["INVERTER_L_SEND"]["fb2_scale_ext"].push(pack->inverter_l_send(i).fb2_scale_ext());
		(*net_signals)["INVERTER_L_SEND"]["pos_offset_slack"].push(pack->inverter_l_send(i).pos_offset_slack());
		(*net_signals)["INVERTER_L_SEND"]["pos_diff_slack"].push(pack->inverter_l_send(i).pos_diff_slack());
		(*net_enums)["INVERTER_L_SEND"]["eprom131"].push(pack->inverter_l_send(i).eprom131());
		primary_inverter_l_send_eprom131_enum_to_string((primary_inverter_l_send_eprom131)pack->inverter_l_send(i).eprom131(), buffer);
		(*net_strings)["INVERTER_L_SEND"]["eprom131"].push(buffer);
		(*net_enums)["INVERTER_L_SEND"]["eprom132"].push(pack->inverter_l_send(i).eprom132());
		primary_inverter_l_send_eprom132_enum_to_string((primary_inverter_l_send_eprom132)pack->inverter_l_send(i).eprom132(), buffer);
		(*net_strings)["INVERTER_L_SEND"]["eprom132"].push(buffer);
		(*net_signals)["INVERTER_L_SEND"]["fun_special"].push(pack->inverter_l_send(i).fun_special());
		(*net_signals)["INVERTER_L_SEND"]["can_id_2_rx"].push(pack->inverter_l_send(i).can_id_2_rx());
		(*net_signals)["INVERTER_L_SEND"]["can_id_2_tx"].push(pack->inverter_l_send(i).can_id_2_tx());
		(*net_signals)["INVERTER_L_SEND"]["v_ref"].push(pack->inverter_l_send(i).v_ref());
		(*net_signals)["INVERTER_L_SEND"]["v_kp"].push(pack->inverter_l_send(i).v_kp());
		(*net_signals)["INVERTER_L_SEND"]["v_ti"].push(pack->inverter_l_send(i).v_ti());
		(*net_signals)["INVERTER_L_SEND"]["clear_errors"].push(pack->inverter_l_send(i).clear_errors());
		(*net_signals)["INVERTER_L_SEND"]["m_setdig__iq"].push(pack->inverter_l_send(i).m_setdig__iq());
		(*net_signals)["INVERTER_L_SEND"]["i_red_tm"].push(pack->inverter_l_send(i).i_red_tm());
		(*net_signals)["INVERTER_L_SEND"]["m_temp"].push(pack->inverter_l_send(i).m_temp());
		(*net_enums)["INVERTER_L_SEND"]["mo_feedback_1"].push(pack->inverter_l_send(i).mo_feedback_1());
		primary_inverter_l_send_mo_feedback_1_enum_to_string((primary_inverter_l_send_mo_feedback_1)pack->inverter_l_send(i).mo_feedback_1(), buffer);
		(*net_strings)["INVERTER_L_SEND"]["mo_feedback_1"].push(buffer);
		(*net_signals)["INVERTER_L_SEND"]["dc_bus_min_lim"].push(pack->inverter_l_send(i).dc_bus_min_lim());
		(*net_signals)["INVERTER_L_SEND"]["fb_incr_mot"].push(pack->inverter_l_send(i).fb_incr_mot());
		(*net_signals)["INVERTER_L_SEND"]["fb_pole"].push(pack->inverter_l_send(i).fb_pole());
		(*net_signals)["INVERTER_L_SEND"]["motor_lsq"].push(pack->inverter_l_send(i).motor_lsq());
		(*net_signals)["INVERTER_L_SEND"]["id_nom"].push(pack->inverter_l_send(i).id_nom());
		(*net_signals)["INVERTER_L_SEND"]["motor_lm"].push(pack->inverter_l_send(i).motor_lm());
		(*net_signals)["INVERTER_L_SEND"]["motor_rr"].push(pack->inverter_l_send(i).motor_rr());
		(*net_signals)["INVERTER_L_SEND"]["id_min"].push(pack->inverter_l_send(i).id_min());
		(*net_signals)["INVERTER_L_SEND"]["motor_tr"].push(pack->inverter_l_send(i).motor_tr());
		(*net_signals)["INVERTER_L_SEND"]["motor_lsd"].push(pack->inverter_l_send(i).motor_lsd());
		(*net_signals)["INVERTER_L_SEND"]["motor_rs"].push(pack->inverter_l_send(i).motor_rs());
		(*net_signals)["INVERTER_L_SEND"]["motor_ts"].push(pack->inverter_l_send(i).motor_ts());
		(*net_enums)["INVERTER_L_SEND"]["def_end_1"].push(pack->inverter_l_send(i).def_end_1());
		primary_inverter_l_send_def_end_1_enum_to_string((primary_inverter_l_send_def_end_1)pack->inverter_l_send(i).def_end_1(), buffer);
		(*net_strings)["INVERTER_L_SEND"]["def_end_1"].push(buffer);
		(*net_enums)["INVERTER_L_SEND"]["def_end_2"].push(pack->inverter_l_send(i).def_end_2());
		primary_inverter_l_send_def_end_2_enum_to_string((primary_inverter_l_send_def_end_2)pack->inverter_l_send(i).def_end_2(), buffer);
		(*net_strings)["INVERTER_L_SEND"]["def_end_2"].push(buffer);
		(*net_enums)["INVERTER_L_SEND"]["def_din_1"].push(pack->inverter_l_send(i).def_din_1());
		primary_inverter_l_send_def_din_1_enum_to_string((primary_inverter_l_send_def_din_1)pack->inverter_l_send(i).def_din_1(), buffer);
		(*net_strings)["INVERTER_L_SEND"]["def_din_1"].push(buffer);
		(*net_enums)["INVERTER_L_SEND"]["def_din_2"].push(pack->inverter_l_send(i).def_din_2());
		primary_inverter_l_send_def_din_2_enum_to_string((primary_inverter_l_send_def_din_2)pack->inverter_l_send(i).def_din_2(), buffer);
		(*net_strings)["INVERTER_L_SEND"]["def_din_2"].push(buffer);
		(*net_enums)["INVERTER_L_SEND"]["operand194"].push(pack->inverter_l_send(i).operand194());
		primary_inverter_l_send_operand194_enum_to_string((primary_inverter_l_send_operand194)pack->inverter_l_send(i).operand194(), buffer);
		(*net_strings)["INVERTER_L_SEND"]["operand194"].push(buffer);
		(*net_enums)["INVERTER_L_SEND"]["operand195"].push(pack->inverter_l_send(i).operand195());
		primary_inverter_l_send_operand195_enum_to_string((primary_inverter_l_send_operand195)pack->inverter_l_send(i).operand195(), buffer);
		(*net_strings)["INVERTER_L_SEND"]["operand195"].push(buffer);
		(*net_enums)["INVERTER_L_SEND"]["operand218"].push(pack->inverter_l_send(i).operand218());
		primary_inverter_l_send_operand218_enum_to_string((primary_inverter_l_send_operand218)pack->inverter_l_send(i).operand218(), buffer);
		(*net_strings)["INVERTER_L_SEND"]["operand218"].push(buffer);
		(*net_enums)["INVERTER_L_SEND"]["operand219"].push(pack->inverter_l_send(i).operand219());
		primary_inverter_l_send_operand219_enum_to_string((primary_inverter_l_send_operand219)pack->inverter_l_send(i).operand219(), buffer);
		(*net_strings)["INVERTER_L_SEND"]["operand219"].push(buffer);
		(*net_signals)["INVERTER_L_SEND"]["i_max_pk"].push(pack->inverter_l_send(i).i_max_pk());
		(*net_signals)["INVERTER_L_SEND"]["i_con_eff"].push(pack->inverter_l_send(i).i_con_eff());
		(*net_signals)["INVERTER_L_SEND"]["i_device"].push(pack->inverter_l_send(i).i_device());
		(*net_signals)["INVERTER_L_SEND"]["n_r_lim"].push(pack->inverter_l_send(i).n_r_lim());
		(*net_signals)["INVERTER_L_SEND"]["nmax100perc"].push(pack->inverter_l_send(i).nmax100perc());
		(*net_signals)["INVERTER_L_SEND"]["pid_i__xkp__iq"].push(pack->inverter_l_send(i).pid_i__xkp__iq());
		(*net_signals)["INVERTER_L_SEND"]["bat_opr_limit__mot"].push(pack->inverter_l_send(i).bat_opr_limit__mot());
		(*net_signals)["INVERTER_L_SEND"]["pid_i__kf__iq"].push(pack->inverter_l_send(i).pid_i__kf__iq());
		(*net_signals)["INVERTER_L_SEND"]["cmc__bit0__dc_current_sens_ena"].push(pack->inverter_l_send(i).cmc__bit0__dc_current_sens_ena());
		(*net_signals)["INVERTER_L_SEND"]["can_rxtimeout"].push(pack->inverter_l_send(i).can_rxtimeout());
		(*net_signals)["INVERTER_L_SEND"]["var_1"].push(pack->inverter_l_send(i).var_1());
		(*net_signals)["INVERTER_L_SEND"]["var_2"].push(pack->inverter_l_send(i).var_2());
		(*net_signals)["INVERTER_L_SEND"]["var_3"].push(pack->inverter_l_send(i).var_3());
		(*net_signals)["INVERTER_L_SEND"]["var_4"].push(pack->inverter_l_send(i).var_4());
		(*net_signals)["INVERTER_L_SEND"]["ain_in_2_offsetval"].push(pack->inverter_l_send(i).ain_in_2_offsetval());
		(*net_signals)["INVERTER_L_SEND"]["dup__bit7_0__dac_source_channel"].push(pack->inverter_l_send(i).dup__bit7_0__dac_source_channel());
		(*net_signals)["INVERTER_L_SEND"]["n_r_dec"].push(pack->inverter_l_send(i).n_r_dec());
		(*net_signals)["INVERTER_L_SEND"]["v_shunt"].push(pack->inverter_l_send(i).v_shunt());
		(*net_signals)["INVERTER_L_SEND"]["t_peak"].push(pack->inverter_l_send(i).t_peak());
		(*net_signals)["INVERTER_L_SEND"]["brake_delay"].push(pack->inverter_l_send(i).brake_delay());
		(*net_signals)["INVERTER_L_SEND"]["axis"].push(pack->inverter_l_send(i).axis());
		(*net_signals)["INVERTER_L_SEND"]["km_speed_0"].push(pack->inverter_l_send(i).km_speed_0());
		(*net_signals)["INVERTER_L_SEND"]["ballast_ext"].push(pack->inverter_l_send(i).ballast_ext());
		(*net_signals)["INVERTER_L_SEND"]["cmc__bit1__idc_limit_ena"].push(pack->inverter_l_send(i).cmc__bit1__idc_limit_ena());
		(*net_enums)["INVERTER_L_SEND"]["cs_ain_2_format"].push(pack->inverter_l_send(i).cs_ain_2_format());
		primary_inverter_l_send_cs_ain_2_format_enum_to_string((primary_inverter_l_send_cs_ain_2_format)pack->inverter_l_send(i).cs_ain_2_format(), buffer);
		(*net_strings)["INVERTER_L_SEND"]["cs_ain_2_format"].push(buffer);
		(*net_signals)["INVERTER_L_SEND"]["km_frg_off"].push(pack->inverter_l_send(i).km_frg_off());
		(*net_signals)["INVERTER_L_SEND"]["fb_special"].push(pack->inverter_l_send(i).fb_special());
		(*net_signals)["INVERTER_L_SEND"]["cmc__bit2__pdc_limit_usage"].push(pack->inverter_l_send(i).cmc__bit2__pdc_limit_usage());
		(*net_signals)["INVERTER_L_SEND"]["km_cal_off"].push(pack->inverter_l_send(i).km_cal_off());
		(*net_signals)["INVERTER_L_SEND"]["coaststop"].push(pack->inverter_l_send(i).coaststop());
		(*net_signals)["INVERTER_L_SEND"]["cmc__bit3__torqueval_init_ena"].push(pack->inverter_l_send(i).cmc__bit3__torqueval_init_ena());
		(*net_enums)["INVERTER_L_SEND"]["cs_ain_1_mode"].push(pack->inverter_l_send(i).cs_ain_1_mode());
		primary_inverter_l_send_cs_ain_1_mode_enum_to_string((primary_inverter_l_send_cs_ain_1_mode)pack->inverter_l_send(i).cs_ain_1_mode(), buffer);
		(*net_strings)["INVERTER_L_SEND"]["cs_ain_1_mode"].push(buffer);
		(*net_signals)["INVERTER_L_SEND"]["km_tx_tog_stat"].push(pack->inverter_l_send(i).km_tx_tog_stat());
		(*net_signals)["INVERTER_L_SEND"]["i_ist_inverse"].push(pack->inverter_l_send(i).i_ist_inverse());
		(*net_enums)["INVERTER_L_SEND"]["compare_var194"].push(pack->inverter_l_send(i).compare_var194());
		primary_inverter_l_send_compare_var194_enum_to_string((primary_inverter_l_send_compare_var194)pack->inverter_l_send(i).compare_var194(), buffer);
		(*net_strings)["INVERTER_L_SEND"]["compare_var194"].push(buffer);
		(*net_enums)["INVERTER_L_SEND"]["compare_var195"].push(pack->inverter_l_send(i).compare_var195());
		primary_inverter_l_send_compare_var195_enum_to_string((primary_inverter_l_send_compare_var195)pack->inverter_l_send(i).compare_var195(), buffer);
		(*net_strings)["INVERTER_L_SEND"]["compare_var195"].push(buffer);
		(*net_enums)["INVERTER_L_SEND"]["compare_var218"].push(pack->inverter_l_send(i).compare_var218());
		primary_inverter_l_send_compare_var218_enum_to_string((primary_inverter_l_send_compare_var218)pack->inverter_l_send(i).compare_var218(), buffer);
		(*net_strings)["INVERTER_L_SEND"]["compare_var218"].push(buffer);
		(*net_enums)["INVERTER_L_SEND"]["compare_var219"].push(pack->inverter_l_send(i).compare_var219());
		primary_inverter_l_send_compare_var219_enum_to_string((primary_inverter_l_send_compare_var219)pack->inverter_l_send(i).compare_var219(), buffer);
		(*net_strings)["INVERTER_L_SEND"]["compare_var219"].push(buffer);
		(*net_signals)["INVERTER_L_SEND"]["cmc__bit4__dig_m_rcpramp_ena"].push(pack->inverter_l_send(i).cmc__bit4__dig_m_rcpramp_ena());
		(*net_signals)["INVERTER_L_SEND"]["km_i_limit"].push(pack->inverter_l_send(i).km_i_limit());
		(*net_signals)["INVERTER_L_SEND"]["refsoft"].push(pack->inverter_l_send(i).refsoft());
		(*net_enums)["INVERTER_L_SEND"]["mo_feedback_2"].push(pack->inverter_l_send(i).mo_feedback_2());
		primary_inverter_l_send_mo_feedback_2_enum_to_string((primary_inverter_l_send_mo_feedback_2)pack->inverter_l_send(i).mo_feedback_2(), buffer);
		(*net_strings)["INVERTER_L_SEND"]["mo_feedback_2"].push(buffer);
		(*net_signals)["INVERTER_L_SEND"]["cmc__bit5__reset_nramp_atnzero"].push(pack->inverter_l_send(i).cmc__bit5__reset_nramp_atnzero());
		(*net_signals)["INVERTER_L_SEND"]["km_n_clip"].push(pack->inverter_l_send(i).km_n_clip());
		(*net_signals)["INVERTER_L_SEND"]["no_uesp_btb"].push(pack->inverter_l_send(i).no_uesp_btb());
		(*net_signals)["INVERTER_L_SEND"]["cmc__bit6__torquetimeout_100ms_e"].push(pack->inverter_l_send(i).cmc__bit6__torquetimeout_100ms_e());
		(*net_signals)["INVERTER_L_SEND"]["cs_oora1"].push(pack->inverter_l_send(i).cs_oora1());
		(*net_signals)["INVERTER_L_SEND"]["km_mix_ana_on"].push(pack->inverter_l_send(i).km_mix_ana_on());
		(*net_signals)["INVERTER_L_SEND"]["vdc_ana"].push(pack->inverter_l_send(i).vdc_ana());
		(*net_signals)["INVERTER_L_SEND"]["cmc__bit13_7__free"].push(pack->inverter_l_send(i).cmc__bit13_7__free());
		(*net_enums)["INVERTER_L_SEND"]["cs_ain_2_mode"].push(pack->inverter_l_send(i).cs_ain_2_mode());
		primary_inverter_l_send_cs_ain_2_mode_enum_to_string((primary_inverter_l_send_cs_ain_2_mode)pack->inverter_l_send(i).cs_ain_2_mode(), buffer);
		(*net_strings)["INVERTER_L_SEND"]["cs_ain_2_mode"].push(buffer);
		(*net_enums)["INVERTER_L_SEND"]["ret_interval"].push(pack->inverter_l_send(i).ret_interval());
		primary_inverter_l_send_ret_interval_enum_to_string((primary_inverter_l_send_ret_interval)pack->inverter_l_send(i).ret_interval(), buffer);
		(*net_strings)["INVERTER_L_SEND"]["ret_interval"].push(buffer);
		(*net_signals)["INVERTER_L_SEND"]["km_allow_sync"].push(pack->inverter_l_send(i).km_allow_sync());
		(*net_signals)["INVERTER_L_SEND"]["i1_adc_ena"].push(pack->inverter_l_send(i).i1_adc_ena());
		(*net_signals)["INVERTER_L_SEND"]["ain_in_2_filter"].push(pack->inverter_l_send(i).ain_in_2_filter());
		(*net_enums)["INVERTER_L_SEND"]["mo_sc1_reso"].push(pack->inverter_l_send(i).mo_sc1_reso());
		primary_inverter_l_send_mo_sc1_reso_enum_to_string((primary_inverter_l_send_mo_sc1_reso)pack->inverter_l_send(i).mo_sc1_reso(), buffer);
		(*net_strings)["INVERTER_L_SEND"]["mo_sc1_reso"].push(buffer);
		(*net_enums)["INVERTER_L_SEND"]["source_id194"].push(pack->inverter_l_send(i).source_id194());
		primary_inverter_l_send_source_id194_enum_to_string((primary_inverter_l_send_source_id194)pack->inverter_l_send(i).source_id194(), buffer);
		(*net_strings)["INVERTER_L_SEND"]["source_id194"].push(buffer);
		(*net_enums)["INVERTER_L_SEND"]["source_id195"].push(pack->inverter_l_send(i).source_id195());
		primary_inverter_l_send_source_id195_enum_to_string((primary_inverter_l_send_source_id195)pack->inverter_l_send(i).source_id195(), buffer);
		(*net_strings)["INVERTER_L_SEND"]["source_id195"].push(buffer);
		(*net_enums)["INVERTER_L_SEND"]["source_id218"].push(pack->inverter_l_send(i).source_id218());
		primary_inverter_l_send_source_id218_enum_to_string((primary_inverter_l_send_source_id218)pack->inverter_l_send(i).source_id218(), buffer);
		(*net_strings)["INVERTER_L_SEND"]["source_id218"].push(buffer);
		(*net_enums)["INVERTER_L_SEND"]["source_id219"].push(pack->inverter_l_send(i).source_id219());
		primary_inverter_l_send_source_id219_enum_to_string((primary_inverter_l_send_source_id219)pack->inverter_l_send(i).source_id219(), buffer);
		(*net_strings)["INVERTER_L_SEND"]["source_id219"].push(buffer);
		(*net_signals)["INVERTER_L_SEND"]["dup__bit8__can_extended_0"].push(pack->inverter_l_send(i).dup__bit8__can_extended_0());
		(*net_signals)["INVERTER_L_SEND"]["km_handwheel"].push(pack->inverter_l_send(i).km_handwheel());
		(*net_signals)["INVERTER_L_SEND"]["hxinv"].push(pack->inverter_l_send(i).hxinv());
		(*net_signals)["INVERTER_L_SEND"]["dup__bit9__generator"].push(pack->inverter_l_send(i).dup__bit9__generator());
		(*net_signals)["INVERTER_L_SEND"]["km_phasing_extend"].push(pack->inverter_l_send(i).km_phasing_extend());
		(*net_signals)["INVERTER_L_SEND"]["h2inv"].push(pack->inverter_l_send(i).h2inv());
		(*net_signals)["INVERTER_L_SEND"]["dup__bit10__park_rms"].push(pack->inverter_l_send(i).dup__bit10__park_rms());
		(*net_signals)["INVERTER_L_SEND"]["cs_oora2"].push(pack->inverter_l_send(i).cs_oora2());
		(*net_signals)["INVERTER_L_SEND"]["km_rsvd_11"].push(pack->inverter_l_send(i).km_rsvd_11());
		(*net_signals)["INVERTER_L_SEND"]["ol_comp"].push(pack->inverter_l_send(i).ol_comp());
		(*net_signals)["INVERTER_L_SEND"]["mo_sc1_comp"].push(pack->inverter_l_send(i).mo_sc1_comp());
		(*net_signals)["INVERTER_L_SEND"]["dup__bit11__dcbus_volts"].push(pack->inverter_l_send(i).dup__bit11__dcbus_volts());
		(*net_enums)["INVERTER_L_SEND"]["cs_cmd_type"].push(pack->inverter_l_send(i).cs_cmd_type());
		primary_inverter_l_send_cs_cmd_type_enum_to_string((primary_inverter_l_send_cs_cmd_type)pack->inverter_l_send(i).cs_cmd_type(), buffer);
		(*net_strings)["INVERTER_L_SEND"]["cs_cmd_type"].push(buffer);
		(*net_signals)["INVERTER_L_SEND"]["km_rsvd_12"].push(pack->inverter_l_send(i).km_rsvd_12());
		(*net_enums)["INVERTER_L_SEND"]["motortype"].push(pack->inverter_l_send(i).motortype());
		primary_inverter_l_send_motortype_enum_to_string((primary_inverter_l_send_motortype)pack->inverter_l_send(i).motortype(), buffer);
		(*net_strings)["INVERTER_L_SEND"]["motortype"].push(buffer);
		(*net_enums)["INVERTER_L_SEND"]["mo_sc2_reso"].push(pack->inverter_l_send(i).mo_sc2_reso());
		primary_inverter_l_send_mo_sc2_reso_enum_to_string((primary_inverter_l_send_mo_sc2_reso)pack->inverter_l_send(i).mo_sc2_reso(), buffer);
		(*net_strings)["INVERTER_L_SEND"]["mo_sc2_reso"].push(buffer);
		(*net_signals)["INVERTER_L_SEND"]["dup__bit12__boat_pedal"].push(pack->inverter_l_send(i).dup__bit12__boat_pedal());
		(*net_signals)["INVERTER_L_SEND"]["km_rsvd_13"].push(pack->inverter_l_send(i).km_rsvd_13());
		(*net_signals)["INVERTER_L_SEND"]["dup__bit13__gen_autoiaclimit"].push(pack->inverter_l_send(i).dup__bit13__gen_autoiaclimit());
		(*net_signals)["INVERTER_L_SEND"]["cs_ain_2__i_limit"].push(pack->inverter_l_send(i).cs_ain_2__i_limit());
		(*net_signals)["INVERTER_L_SEND"]["km_pseudo_enable"].push(pack->inverter_l_send(i).km_pseudo_enable());
		(*net_signals)["INVERTER_L_SEND"]["ana_0up"].push(pack->inverter_l_send(i).ana_0up());
		(*net_signals)["INVERTER_L_SEND"]["cmc__bit14__idc_limit_ena_v2"].push(pack->inverter_l_send(i).cmc__bit14__idc_limit_ena_v2());
		(*net_signals)["INVERTER_L_SEND"]["dup__bit14__mtpa_reluct_enab"].push(pack->inverter_l_send(i).dup__bit14__mtpa_reluct_enab());
		(*net_signals)["INVERTER_L_SEND"]["cs_ain_1__n_limit"].push(pack->inverter_l_send(i).cs_ain_1__n_limit());
		(*net_signals)["INVERTER_L_SEND"]["km_debug_test"].push(pack->inverter_l_send(i).km_debug_test());
		(*net_signals)["INVERTER_L_SEND"]["lowbd"].push(pack->inverter_l_send(i).lowbd());
		(*net_signals)["INVERTER_L_SEND"]["mo_sc2_inv"].push(pack->inverter_l_send(i).mo_sc2_inv());
		(*net_enums)["INVERTER_L_SEND"]["active190"].push(pack->inverter_l_send(i).active190());
		primary_inverter_l_send_active190_enum_to_string((primary_inverter_l_send_active190)pack->inverter_l_send(i).active190(), buffer);
		(*net_strings)["INVERTER_L_SEND"]["active190"].push(buffer);
		(*net_enums)["INVERTER_L_SEND"]["active191"].push(pack->inverter_l_send(i).active191());
		primary_inverter_l_send_active191_enum_to_string((primary_inverter_l_send_active191)pack->inverter_l_send(i).active191(), buffer);
		(*net_strings)["INVERTER_L_SEND"]["active191"].push(buffer);
		(*net_enums)["INVERTER_L_SEND"]["active192"].push(pack->inverter_l_send(i).active192());
		primary_inverter_l_send_active192_enum_to_string((primary_inverter_l_send_active192)pack->inverter_l_send(i).active192(), buffer);
		(*net_strings)["INVERTER_L_SEND"]["active192"].push(buffer);
		(*net_enums)["INVERTER_L_SEND"]["active193"].push(pack->inverter_l_send(i).active193());
		primary_inverter_l_send_active193_enum_to_string((primary_inverter_l_send_active193)pack->inverter_l_send(i).active193(), buffer);
		(*net_strings)["INVERTER_L_SEND"]["active193"].push(buffer);
		(*net_signals)["INVERTER_L_SEND"]["cmc__bit15__dig_e_brake_act"].push(pack->inverter_l_send(i).cmc__bit15__dig_e_brake_act());
		(*net_signals)["INVERTER_L_SEND"]["dup__bit15__canopen_acv"].push(pack->inverter_l_send(i).dup__bit15__canopen_acv());
		(*net_signals)["INVERTER_L_SEND"]["t_dc__stop"].push(pack->inverter_l_send(i).t_dc__stop());
		(*net_signals)["INVERTER_L_SEND"]["v_dc__stop"].push(pack->inverter_l_send(i).v_dc__stop());
		(*net_signals)["INVERTER_L_SEND"]["special__stop"].push(pack->inverter_l_send(i).special__stop());
		(*net_signals)["INVERTER_L_SEND"]["v_min__stop"].push(pack->inverter_l_send(i).v_min__stop());
		(*net_signals)["INVERTER_L_SEND"]["f_min__stop"].push(pack->inverter_l_send(i).f_min__stop());
		(*net_signals)["INVERTER_L_SEND"]["v_corner__stop"].push(pack->inverter_l_send(i).v_corner__stop());
		(*net_signals)["INVERTER_L_SEND"]["f_corner__stop"].push(pack->inverter_l_send(i).f_corner__stop());
		(*net_signals)["INVERTER_L_SEND"]["pid_i__kp__id"].push(pack->inverter_l_send(i).pid_i__kp__id());
		(*net_signals)["INVERTER_L_SEND"]["pid_i__ti__id"].push(pack->inverter_l_send(i).pid_i__ti__id());
		(*net_signals)["INVERTER_L_SEND"]["pid_i__tim__id"].push(pack->inverter_l_send(i).pid_i__tim__id());
		(*net_signals)["INVERTER_L_SEND"]["ain_in_1_scaleval"].push(pack->inverter_l_send(i).ain_in_1_scaleval());
		(*net_signals)["INVERTER_L_SEND"]["m_r_acc"].push(pack->inverter_l_send(i).m_r_acc());
		(*net_signals)["INVERTER_L_SEND"]["sramp"].push(pack->inverter_l_send(i).sramp());
		(*net_signals)["INVERTER_L_SEND"]["regen_r"].push(pack->inverter_l_send(i).regen_r());
		(*net_signals)["INVERTER_L_SEND"]["dc_bus_max_lim"].push(pack->inverter_l_send(i).dc_bus_max_lim());
		(*net_signals)["INVERTER_L_SEND"]["m_r_rcp"].push(pack->inverter_l_send(i).m_r_rcp());
		(*net_signals)["INVERTER_L_SEND"]["pid_i__xkp__id"].push(pack->inverter_l_send(i).pid_i__xkp__id());
		(*net_signals)["INVERTER_L_SEND"]["bat_opr_limit__gen"].push(pack->inverter_l_send(i).bat_opr_limit__gen());
		(*net_signals)["INVERTER_L_SEND"]["pid_i__kf__id"].push(pack->inverter_l_send(i).pid_i__kf__id());
		(*net_signals)["INVERTER_L_SEND"]["cmc__bit17_16__checkipeak_config"].push(pack->inverter_l_send(i).cmc__bit17_16__checkipeak_config());
		(*net_signals)["INVERTER_L_SEND"]["ain_in_2_scaleval"].push(pack->inverter_l_send(i).ain_in_2_scaleval());
		(*net_signals)["INVERTER_L_SEND"]["dup__bit16__bamobil3_2_offcrct"].push(pack->inverter_l_send(i).dup__bit16__bamobil3_2_offcrct());
		(*net_signals)["INVERTER_L_SEND"]["m_r_dec"].push(pack->inverter_l_send(i).m_r_dec());
		(*net_signals)["INVERTER_L_SEND"]["ramp4"].push(pack->inverter_l_send(i).ramp4());
		(*net_signals)["INVERTER_L_SEND"]["dup__bit19_17__ecode_redefine"].push(pack->inverter_l_send(i).dup__bit19_17__ecode_redefine());
		(*net_signals)["INVERTER_L_SEND"]["motbrake"].push(pack->inverter_l_send(i).motbrake());
		(*net_signals)["INVERTER_L_SEND"]["cmc__bit18__tractioncontrol_ena"].push(pack->inverter_l_send(i).cmc__bit18__tractioncontrol_ena());
		(*net_signals)["INVERTER_L_SEND"]["ac_dc"].push(pack->inverter_l_send(i).ac_dc());
		(*net_signals)["INVERTER_L_SEND"]["cmc__bit20_19__tc_deltatime_conf"].push(pack->inverter_l_send(i).cmc__bit20_19__tc_deltatime_conf());
		(*net_enums)["INVERTER_L_SEND"]["pwm_freq"].push(pack->inverter_l_send(i).pwm_freq());
		primary_inverter_l_send_pwm_freq_enum_to_string((primary_inverter_l_send_pwm_freq)pack->inverter_l_send(i).pwm_freq(), buffer);
		(*net_strings)["INVERTER_L_SEND"]["pwm_freq"].push(buffer);
		(*net_signals)["INVERTER_L_SEND"]["dup__bit20__hal_extmr_acv"].push(pack->inverter_l_send(i).dup__bit20__hal_extmr_acv());
		(*net_signals)["INVERTER_L_SEND"]["cmc__bit22_21__tc_minspeed_conf"].push(pack->inverter_l_send(i).cmc__bit22_21__tc_minspeed_conf());
		(*net_signals)["INVERTER_L_SEND"]["dup__bit21__initwith_frg_off"].push(pack->inverter_l_send(i).dup__bit21__initwith_frg_off());
		(*net_signals)["INVERTER_L_SEND"]["dup__bit31_22__free"].push(pack->inverter_l_send(i).dup__bit31_22__free());
		(*net_signals)["INVERTER_L_SEND"]["ntc"].push(pack->inverter_l_send(i).ntc());
		(*net_signals)["INVERTER_L_SEND"]["cmc__bit23__tc_ncmdrestoption"].push(pack->inverter_l_send(i).cmc__bit23__tc_ncmdrestoption());
		(*net_signals)["INVERTER_L_SEND"]["delta"].push(pack->inverter_l_send(i).delta());
		(*net_signals)["INVERTER_L_SEND"]["cmc__bit31_24__free"].push(pack->inverter_l_send(i).cmc__bit31_24__free());
		(*net_signals)["INVERTER_L_SEND"]["dc_1qdirvolt"].push(pack->inverter_l_send(i).dc_1qdirvolt());
		(*net_signals)["INVERTER_L_SEND"]["dc_field"].push(pack->inverter_l_send(i).dc_field());
		(*net_signals)["INVERTER_L_SEND"]["dead_2"].push(pack->inverter_l_send(i).dead_2());
		(*net_signals)["INVERTER_L_SEND"]["block"].push(pack->inverter_l_send(i).block());
		(*net_signals)["INVERTER_L_SEND"]["dc_1qmv"].push(pack->inverter_l_send(i).dc_1qmv());
		(*net_signals)["INVERTER_L_SEND"]["dc_1q3p"].push(pack->inverter_l_send(i).dc_1q3p());
		(*net_signals)["INVERTER_L_SEND"]["reducelosses"].push(pack->inverter_l_send(i).reducelosses());

    }

    for(int i = 0; i < pack->inverter_l_rcv_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->inverter_l_rcv(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->inverter_l_rcv(i)._inner_timestamp();
        (*net_signals)["INVERTER_L_RCV"]["_timestamp"].push(pack->inverter_l_rcv(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["INVERTER_L_RCV"]["rcv_mux"].push(pack->inverter_l_rcv(i).rcv_mux());
		primary_inverter_l_rcv_rcv_mux_enum_to_string((primary_inverter_l_rcv_rcv_mux)pack->inverter_l_rcv(i).rcv_mux(), buffer);
		(*net_strings)["INVERTER_L_RCV"]["rcv_mux"].push(buffer);
		(*net_signals)["INVERTER_L_RCV"]["n_actual"].push(pack->inverter_l_rcv(i).n_actual());
		(*net_signals)["INVERTER_L_RCV"]["n_r_dec"].push(pack->inverter_l_rcv(i).n_r_dec());
		(*net_signals)["INVERTER_L_RCV"]["n_r_lim"].push(pack->inverter_l_rcv(i).n_r_lim());
		(*net_signals)["INVERTER_L_RCV"]["n_actual_filt"].push(pack->inverter_l_rcv(i).n_actual_filt());
		(*net_signals)["INVERTER_L_RCV"]["firmware"].push(pack->inverter_l_rcv(i).firmware());
		(*net_enums)["INVERTER_L_RCV"]["devicetype"].push(pack->inverter_l_rcv(i).devicetype());
		primary_inverter_l_rcv_devicetype_enum_to_string((primary_inverter_l_rcv_devicetype)pack->inverter_l_rcv(i).devicetype(), buffer);
		(*net_strings)["INVERTER_L_RCV"]["devicetype"].push(buffer);
		(*net_signals)["INVERTER_L_RCV"]["snr"].push(pack->inverter_l_rcv(i).snr());
		(*net_signals)["INVERTER_L_RCV"]["axis"].push(pack->inverter_l_rcv(i).axis());
		(*net_signals)["INVERTER_L_RCV"]["i_device"].push(pack->inverter_l_rcv(i).i_device());
		(*net_signals)["INVERTER_L_RCV"]["v_shunt"].push(pack->inverter_l_rcv(i).v_shunt());
		(*net_signals)["INVERTER_L_RCV"]["i_200perc"].push(pack->inverter_l_rcv(i).i_200perc());
		(*net_signals)["INVERTER_L_RCV"]["dc_bus_comp"].push(pack->inverter_l_rcv(i).dc_bus_comp());
		(*net_signals)["INVERTER_L_RCV"]["ena64"].push(pack->inverter_l_rcv(i).ena64());
		(*net_signals)["INVERTER_L_RCV"]["err_badparas"].push(pack->inverter_l_rcv(i).err_badparas());
		(*net_signals)["INVERTER_L_RCV"]["lmt1"].push(pack->inverter_l_rcv(i).lmt1());
		(*net_signals)["INVERTER_L_RCV"]["ain_in_1_raw"].push(pack->inverter_l_rcv(i).ain_in_1_raw());
		(*net_signals)["INVERTER_L_RCV"]["ain_in_2_raw"].push(pack->inverter_l_rcv(i).ain_in_2_raw());
		(*net_signals)["INVERTER_L_RCV"]["nmax100perc"].push(pack->inverter_l_rcv(i).nmax100perc());
		(*net_signals)["INVERTER_L_RCV"]["n_setdig"].push(pack->inverter_l_rcv(i).n_setdig());
		(*net_signals)["INVERTER_L_RCV"]["n_cmd"].push(pack->inverter_l_rcv(i).n_cmd());
		(*net_signals)["INVERTER_L_RCV"]["n_cmd_ramp"].push(pack->inverter_l_rcv(i).n_cmd_ramp());
		(*net_signals)["INVERTER_L_RCV"]["n_lim"].push(pack->inverter_l_rcv(i).n_lim());
		(*net_signals)["INVERTER_L_RCV"]["n_error"].push(pack->inverter_l_rcv(i).n_error());
		(*net_signals)["INVERTER_L_RCV"]["m_setdig__iq"].push(pack->inverter_l_rcv(i).m_setdig__iq());
		(*net_signals)["INVERTER_L_RCV"]["id_setdig__id"].push(pack->inverter_l_rcv(i).id_setdig__id());
		(*net_signals)["INVERTER_L_RCV"]["i_max_pk"].push(pack->inverter_l_rcv(i).i_max_pk());
		(*net_signals)["INVERTER_L_RCV"]["i_con_eff"].push(pack->inverter_l_rcv(i).i_con_eff());
		(*net_signals)["INVERTER_L_RCV"]["i_max_eff"].push(pack->inverter_l_rcv(i).i_max_eff());
		(*net_signals)["INVERTER_L_RCV"]["i_nom_eff"].push(pack->inverter_l_rcv(i).i_nom_eff());
		(*net_signals)["INVERTER_L_RCV"]["i_limit_inuse"].push(pack->inverter_l_rcv(i).i_limit_inuse());
		(*net_signals)["INVERTER_L_RCV"]["i_cmd"].push(pack->inverter_l_rcv(i).i_cmd());
		(*net_signals)["INVERTER_L_RCV"]["i_cmd_ramp"].push(pack->inverter_l_rcv(i).i_cmd_ramp());
		(*net_signals)["INVERTER_L_RCV"]["i_actual"].push(pack->inverter_l_rcv(i).i_actual());
		(*net_signals)["INVERTER_L_RCV"]["i_actual_filt"].push(pack->inverter_l_rcv(i).i_actual_filt());
		(*net_signals)["INVERTER_L_RCV"]["iq_actual"].push(pack->inverter_l_rcv(i).iq_actual());
		(*net_signals)["INVERTER_L_RCV"]["id_actual"].push(pack->inverter_l_rcv(i).id_actual());
		(*net_signals)["INVERTER_L_RCV"]["iq_error"].push(pack->inverter_l_rcv(i).iq_error());
		(*net_signals)["INVERTER_L_RCV"]["id_error"].push(pack->inverter_l_rcv(i).id_error());
		(*net_signals)["INVERTER_L_RCV"]["i1_actual"].push(pack->inverter_l_rcv(i).i1_actual());
		(*net_signals)["INVERTER_L_RCV"]["i2_actual"].push(pack->inverter_l_rcv(i).i2_actual());
		(*net_signals)["INVERTER_L_RCV"]["i3_actual"].push(pack->inverter_l_rcv(i).i3_actual());
		(*net_signals)["INVERTER_L_RCV"]["i3_adc"].push(pack->inverter_l_rcv(i).i3_adc());
		(*net_signals)["INVERTER_L_RCV"]["i2_adc"].push(pack->inverter_l_rcv(i).i2_adc());
		(*net_signals)["INVERTER_L_RCV"]["vq"].push(pack->inverter_l_rcv(i).vq());
		(*net_signals)["INVERTER_L_RCV"]["vd"].push(pack->inverter_l_rcv(i).vd());
		(*net_signals)["INVERTER_L_RCV"]["vout"].push(pack->inverter_l_rcv(i).vout());
		(*net_signals)["INVERTER_L_RCV"]["t_motor"].push(pack->inverter_l_rcv(i).t_motor());
		(*net_signals)["INVERTER_L_RCV"]["t_igbt"].push(pack->inverter_l_rcv(i).t_igbt());
		(*net_signals)["INVERTER_L_RCV"]["t_air"].push(pack->inverter_l_rcv(i).t_air());
		(*net_signals)["INVERTER_L_RCV"]["vdc_bus_filt"].push(pack->inverter_l_rcv(i).vdc_bus_filt());
		(*net_signals)["INVERTER_L_RCV"]["end_1"].push(pack->inverter_l_rcv(i).end_1());
		(*net_signals)["INVERTER_L_RCV"]["din_1"].push(pack->inverter_l_rcv(i).din_1());
		(*net_signals)["INVERTER_L_RCV"]["end_2"].push(pack->inverter_l_rcv(i).end_2());
		(*net_signals)["INVERTER_L_RCV"]["din_2"].push(pack->inverter_l_rcv(i).din_2());
		(*net_signals)["INVERTER_L_RCV"]["run232"].push(pack->inverter_l_rcv(i).run232());
		(*net_signals)["INVERTER_L_RCV"]["dout_1"].push(pack->inverter_l_rcv(i).dout_1());
		(*net_signals)["INVERTER_L_RCV"]["dout_2"].push(pack->inverter_l_rcv(i).dout_2());
		(*net_signals)["INVERTER_L_RCV"]["dout_3"].push(pack->inverter_l_rcv(i).dout_3());
		(*net_signals)["INVERTER_L_RCV"]["rdy_btb"].push(pack->inverter_l_rcv(i).rdy_btb());
		(*net_signals)["INVERTER_L_RCV"]["i_fault"].push(pack->inverter_l_rcv(i).i_fault());
		(*net_signals)["INVERTER_L_RCV"]["dout_4"].push(pack->inverter_l_rcv(i).dout_4());
		(*net_signals)["INVERTER_L_RCV"]["i_lim_dig"].push(pack->inverter_l_rcv(i).i_lim_dig());
		(*net_signals)["INVERTER_L_RCV"]["i_red_n"].push(pack->inverter_l_rcv(i).i_red_n());
		(*net_signals)["INVERTER_L_RCV"]["i_red_td"].push(pack->inverter_l_rcv(i).i_red_td());
		(*net_signals)["INVERTER_L_RCV"]["i_red_te"].push(pack->inverter_l_rcv(i).i_red_te());
		(*net_signals)["INVERTER_L_RCV"]["i_red_tm"].push(pack->inverter_l_rcv(i).i_red_tm());
		(*net_enums)["INVERTER_L_RCV"]["cs_ain_1_format"].push(pack->inverter_l_rcv(i).cs_ain_1_format());
		primary_inverter_l_rcv_cs_ain_1_format_enum_to_string((primary_inverter_l_rcv_cs_ain_1_format)pack->inverter_l_rcv(i).cs_ain_1_format(), buffer);
		(*net_strings)["INVERTER_L_RCV"]["cs_ain_1_format"].push(buffer);
		(*net_signals)["INVERTER_L_RCV"]["id_ref"].push(pack->inverter_l_rcv(i).id_ref());
		(*net_signals)["INVERTER_L_RCV"]["m_outdig__iq"].push(pack->inverter_l_rcv(i).m_outdig__iq());
		(*net_signals)["INVERTER_L_RCV"]["ptr_1_debug"].push(pack->inverter_l_rcv(i).ptr_1_debug());
		(*net_signals)["INVERTER_L_RCV"]["ptr_2_debug"].push(pack->inverter_l_rcv(i).ptr_2_debug());
		(*net_signals)["INVERTER_L_RCV"]["temp_debug"].push(pack->inverter_l_rcv(i).temp_debug());
		(*net_signals)["INVERTER_L_RCV"]["motor_f_n"].push(pack->inverter_l_rcv(i).motor_f_n());
		(*net_signals)["INVERTER_L_RCV"]["motor_v_n"].push(pack->inverter_l_rcv(i).motor_v_n());
		(*net_signals)["INVERTER_L_RCV"]["t_dc__start"].push(pack->inverter_l_rcv(i).t_dc__start());
		(*net_signals)["INVERTER_L_RCV"]["v_dc__start"].push(pack->inverter_l_rcv(i).v_dc__start());
		(*net_signals)["INVERTER_L_RCV"]["v_min__start"].push(pack->inverter_l_rcv(i).v_min__start());
		(*net_signals)["INVERTER_L_RCV"]["f_min__start"].push(pack->inverter_l_rcv(i).f_min__start());
		(*net_signals)["INVERTER_L_RCV"]["v_corner__start"].push(pack->inverter_l_rcv(i).v_corner__start());
		(*net_signals)["INVERTER_L_RCV"]["f_corner__start"].push(pack->inverter_l_rcv(i).f_corner__start());
		(*net_signals)["INVERTER_L_RCV"]["cos_phi"].push(pack->inverter_l_rcv(i).cos_phi());
		(*net_signals)["INVERTER_L_RCV"]["pwm_enum"].push(pack->inverter_l_rcv(i).pwm_enum());
		(*net_signals)["INVERTER_L_RCV"]["calib_ref_value"].push(pack->inverter_l_rcv(i).calib_ref_value());
		(*net_signals)["INVERTER_L_RCV"]["pid_i__kp__iq"].push(pack->inverter_l_rcv(i).pid_i__kp__iq());
		(*net_signals)["INVERTER_L_RCV"]["pid_i__ti__iq"].push(pack->inverter_l_rcv(i).pid_i__ti__iq());
		(*net_signals)["INVERTER_L_RCV"]["cutoffdig"].push(pack->inverter_l_rcv(i).cutoffdig());
		(*net_signals)["INVERTER_L_RCV"]["i3_offset"].push(pack->inverter_l_rcv(i).i3_offset());
		(*net_signals)["INVERTER_L_RCV"]["i_delta_ramp"].push(pack->inverter_l_rcv(i).i_delta_ramp());
		(*net_signals)["INVERTER_L_RCV"]["pid_i__tim__iq"].push(pack->inverter_l_rcv(i).pid_i__tim__iq());
		(*net_signals)["INVERTER_L_RCV"]["pid_n__kp"].push(pack->inverter_l_rcv(i).pid_n__kp());
		(*net_signals)["INVERTER_L_RCV"]["v_ti"].push(pack->inverter_l_rcv(i).v_ti());
		(*net_signals)["INVERTER_L_RCV"]["pid_n__td"].push(pack->inverter_l_rcv(i).pid_n__td());
		(*net_signals)["INVERTER_L_RCV"]["ain_in_1_offsetval"].push(pack->inverter_l_rcv(i).ain_in_1_offsetval());
		(*net_signals)["INVERTER_L_RCV"]["ain_in_2_offsetval"].push(pack->inverter_l_rcv(i).ain_in_2_offsetval());
		(*net_signals)["INVERTER_L_RCV"]["dzr_seq"].push(pack->inverter_l_rcv(i).dzr_seq());
		(*net_signals)["INVERTER_L_RCV"]["pid_n__tim"].push(pack->inverter_l_rcv(i).pid_n__tim());
		(*net_signals)["INVERTER_L_RCV"]["n_lim_plus"].push(pack->inverter_l_rcv(i).n_lim_plus());
		(*net_signals)["INVERTER_L_RCV"]["n_lim_minus"].push(pack->inverter_l_rcv(i).n_lim_minus());
		(*net_signals)["INVERTER_L_RCV"]["incr_delta"].push(pack->inverter_l_rcv(i).incr_delta());
		(*net_signals)["INVERTER_L_RCV"]["motorpos_mech"].push(pack->inverter_l_rcv(i).motorpos_mech());
		(*net_signals)["INVERTER_L_RCV"]["motorpos_elec"].push(pack->inverter_l_rcv(i).motorpos_elec());
		(*net_signals)["INVERTER_L_RCV"]["fb_offset"].push(pack->inverter_l_rcv(i).fb_offset());
		(*net_signals)["INVERTER_L_RCV"]["it_rg_monitor"].push(pack->inverter_l_rcv(i).it_rg_monitor());
		(*net_signals)["INVERTER_L_RCV"]["motor_pole"].push(pack->inverter_l_rcv(i).motor_pole());
		(*net_signals)["INVERTER_L_RCV"]["ain_in_1_cutoff"].push(pack->inverter_l_rcv(i).ain_in_1_cutoff());
		(*net_enums)["INVERTER_L_RCV"]["activecontrolmode"].push(pack->inverter_l_rcv(i).activecontrolmode());
		primary_inverter_l_rcv_activecontrolmode_enum_to_string((primary_inverter_l_rcv_activecontrolmode)pack->inverter_l_rcv(i).activecontrolmode(), buffer);
		(*net_strings)["INVERTER_L_RCV"]["activecontrolmode"].push(buffer);
		(*net_signals)["INVERTER_L_RCV"]["km_rsvd_0"].push(pack->inverter_l_rcv(i).km_rsvd_0());
		(*net_signals)["INVERTER_L_RCV"]["ena82"].push(pack->inverter_l_rcv(i).ena82());
		(*net_signals)["INVERTER_L_RCV"]["ain_in_2_cutoff"].push(pack->inverter_l_rcv(i).ain_in_2_cutoff());
		(*net_signals)["INVERTER_L_RCV"]["i_limit_inuse_ramp"].push(pack->inverter_l_rcv(i).i_limit_inuse_ramp());
		(*net_signals)["INVERTER_L_RCV"]["n_nom"].push(pack->inverter_l_rcv(i).n_nom());
		(*net_signals)["INVERTER_L_RCV"]["pid_n__kacc"].push(pack->inverter_l_rcv(i).pid_n__kacc());
		(*net_signals)["INVERTER_L_RCV"]["rotor_signals"].push(pack->inverter_l_rcv(i).rotor_signals());
		(*net_signals)["INVERTER_L_RCV"]["speed_filter"].push(pack->inverter_l_rcv(i).speed_filter());
		(*net_signals)["INVERTER_L_RCV"]["ain_in_1_filter"].push(pack->inverter_l_rcv(i).ain_in_1_filter());
		(*net_signals)["INVERTER_L_RCV"]["ixt_monitor"].push(pack->inverter_l_rcv(i).ixt_monitor());
		(*net_signals)["INVERTER_L_RCV"]["ecode_bit0_firsterrordtcd99"].push(pack->inverter_l_rcv(i).ecode_bit0_firsterrordtcd99());
		(*net_signals)["INVERTER_L_RCV"]["device_mains"].push(pack->inverter_l_rcv(i).device_mains());
		(*net_signals)["INVERTER_L_RCV"]["regen_p"].push(pack->inverter_l_rcv(i).regen_p());
		(*net_signals)["INVERTER_L_RCV"]["can_id_rx"].push(pack->inverter_l_rcv(i).can_id_rx());
		(*net_signals)["INVERTER_L_RCV"]["can_id_tx"].push(pack->inverter_l_rcv(i).can_id_tx());
		(*net_signals)["INVERTER_L_RCV"]["pos_kp"].push(pack->inverter_l_rcv(i).pos_kp());
		(*net_signals)["INVERTER_L_RCV"]["pos_ti"].push(pack->inverter_l_rcv(i).pos_ti());
		(*net_signals)["INVERTER_L_RCV"]["pos_td"].push(pack->inverter_l_rcv(i).pos_td());
		(*net_signals)["INVERTER_L_RCV"]["pos_actual"].push(pack->inverter_l_rcv(i).pos_actual());
		(*net_signals)["INVERTER_L_RCV"]["pos_dest"].push(pack->inverter_l_rcv(i).pos_dest());
		(*net_signals)["INVERTER_L_RCV"]["pos_actual_2"].push(pack->inverter_l_rcv(i).pos_actual_2());
		(*net_signals)["INVERTER_L_RCV"]["pos_error"].push(pack->inverter_l_rcv(i).pos_error());
		(*net_signals)["INVERTER_L_RCV"]["pos_tim"].push(pack->inverter_l_rcv(i).pos_tim());
		(*net_signals)["INVERTER_L_RCV"]["pos_offsref"].push(pack->inverter_l_rcv(i).pos_offsref());
		(*net_enums)["INVERTER_L_RCV"]["can_nbt"].push(pack->inverter_l_rcv(i).can_nbt());
		primary_inverter_l_rcv_can_nbt_enum_to_string((primary_inverter_l_rcv_can_nbt)pack->inverter_l_rcv(i).can_nbt(), buffer);
		(*net_strings)["INVERTER_L_RCV"]["can_nbt"].push(buffer);
		(*net_signals)["INVERTER_L_RCV"]["pos_zero_capture"].push(pack->inverter_l_rcv(i).pos_zero_capture());
		(*net_signals)["INVERTER_L_RCV"]["ref_reso_edge"].push(pack->inverter_l_rcv(i).ref_reso_edge());
		(*net_signals)["INVERTER_L_RCV"]["speed_1"].push(pack->inverter_l_rcv(i).speed_1());
		(*net_signals)["INVERTER_L_RCV"]["speed_2"].push(pack->inverter_l_rcv(i).speed_2());
		(*net_signals)["INVERTER_L_RCV"]["pos_tol_win"].push(pack->inverter_l_rcv(i).pos_tol_win());
		(*net_signals)["INVERTER_L_RCV"]["pos_preset_val"].push(pack->inverter_l_rcv(i).pos_preset_val());
		(*net_signals)["INVERTER_L_RCV"]["pos_zero_offset"].push(pack->inverter_l_rcv(i).pos_zero_offset());
		(*net_signals)["INVERTER_L_RCV"]["pos_nd_scale"].push(pack->inverter_l_rcv(i).pos_nd_scale());
		(*net_signals)["INVERTER_L_RCV"]["pos_nd_offset"].push(pack->inverter_l_rcv(i).pos_nd_offset());
		(*net_signals)["INVERTER_L_RCV"]["fb2_scale_ext"].push(pack->inverter_l_rcv(i).fb2_scale_ext());
		(*net_signals)["INVERTER_L_RCV"]["pos_offset_slack"].push(pack->inverter_l_rcv(i).pos_offset_slack());
		(*net_signals)["INVERTER_L_RCV"]["pos_diff_slack"].push(pack->inverter_l_rcv(i).pos_diff_slack());
		(*net_signals)["INVERTER_L_RCV"]["fun_para_read"].push(pack->inverter_l_rcv(i).fun_para_read());
		(*net_signals)["INVERTER_L_RCV"]["fun_para_write"].push(pack->inverter_l_rcv(i).fun_para_write());
		(*net_signals)["INVERTER_L_RCV"]["fun_special"].push(pack->inverter_l_rcv(i).fun_special());
		(*net_signals)["INVERTER_L_RCV"]["can_id_2_rx"].push(pack->inverter_l_rcv(i).can_id_2_rx());
		(*net_signals)["INVERTER_L_RCV"]["can_id_2_tx"].push(pack->inverter_l_rcv(i).can_id_2_tx());
		(*net_signals)["INVERTER_L_RCV"]["v_ref"].push(pack->inverter_l_rcv(i).v_ref());
		(*net_signals)["INVERTER_L_RCV"]["v_kp"].push(pack->inverter_l_rcv(i).v_kp());
		(*net_signals)["INVERTER_L_RCV"]["pid_n__ti"].push(pack->inverter_l_rcv(i).pid_n__ti());
		(*net_signals)["INVERTER_L_RCV"]["clear_errors"].push(pack->inverter_l_rcv(i).clear_errors());
		(*net_signals)["INVERTER_L_RCV"]["pos_cmd"].push(pack->inverter_l_rcv(i).pos_cmd());
		(*net_signals)["INVERTER_L_RCV"]["can_error_busoff"].push(pack->inverter_l_rcv(i).can_error_busoff());
		(*net_signals)["INVERTER_L_RCV"]["can_error_writetime"].push(pack->inverter_l_rcv(i).can_error_writetime());
		(*net_signals)["INVERTER_L_RCV"]["ecode_bit0_firsterrordtcd148"].push(pack->inverter_l_rcv(i).ecode_bit0_firsterrordtcd148());
		(*net_signals)["INVERTER_L_RCV"]["can_error_no_ack"].push(pack->inverter_l_rcv(i).can_error_no_ack());
		(*net_signals)["INVERTER_L_RCV"]["can_error_crc_check150"].push(pack->inverter_l_rcv(i).can_error_crc_check150());
		(*net_signals)["INVERTER_L_RCV"]["can_error_crc_check151"].push(pack->inverter_l_rcv(i).can_error_crc_check151());
		(*net_signals)["INVERTER_L_RCV"]["info_timer_diff"].push(pack->inverter_l_rcv(i).info_timer_diff());
		(*net_signals)["INVERTER_L_RCV"]["ballastcount"].push(pack->inverter_l_rcv(i).ballastcount());
		(*net_signals)["INVERTER_L_RCV"]["m_temp"].push(pack->inverter_l_rcv(i).m_temp());
		(*net_enums)["INVERTER_L_RCV"]["mo_feedback_1"].push(pack->inverter_l_rcv(i).mo_feedback_1());
		primary_inverter_l_rcv_mo_feedback_1_enum_to_string((primary_inverter_l_rcv_mo_feedback_1)pack->inverter_l_rcv(i).mo_feedback_1(), buffer);
		(*net_strings)["INVERTER_L_RCV"]["mo_feedback_1"].push(buffer);
		(*net_signals)["INVERTER_L_RCV"]["dc_bus_min_lim"].push(pack->inverter_l_rcv(i).dc_bus_min_lim());
		(*net_signals)["INVERTER_L_RCV"]["fb_incr_mot"].push(pack->inverter_l_rcv(i).fb_incr_mot());
		(*net_signals)["INVERTER_L_RCV"]["fb_pole"].push(pack->inverter_l_rcv(i).fb_pole());
		(*net_signals)["INVERTER_L_RCV"]["logic_freq"].push(pack->inverter_l_rcv(i).logic_freq());
		(*net_signals)["INVERTER_L_RCV"]["pwm_1"].push(pack->inverter_l_rcv(i).pwm_1());
		(*net_signals)["INVERTER_L_RCV"]["pwm_2"].push(pack->inverter_l_rcv(i).pwm_2());
		(*net_signals)["INVERTER_L_RCV"]["pwm_3"].push(pack->inverter_l_rcv(i).pwm_3());
		(*net_signals)["INVERTER_L_RCV"]["timer_delta"].push(pack->inverter_l_rcv(i).timer_delta());
		(*net_signals)["INVERTER_L_RCV"]["motor_lsq"].push(pack->inverter_l_rcv(i).motor_lsq());
		(*net_signals)["INVERTER_L_RCV"]["motor_lsd"].push(pack->inverter_l_rcv(i).motor_lsd());
		(*net_signals)["INVERTER_L_RCV"]["id_nom"].push(pack->inverter_l_rcv(i).id_nom());
		(*net_signals)["INVERTER_L_RCV"]["motor_lm"].push(pack->inverter_l_rcv(i).motor_lm());
		(*net_signals)["INVERTER_L_RCV"]["motor_rr"].push(pack->inverter_l_rcv(i).motor_rr());
		(*net_signals)["INVERTER_L_RCV"]["id_min"].push(pack->inverter_l_rcv(i).id_min());
		(*net_signals)["INVERTER_L_RCV"]["motor_tr"].push(pack->inverter_l_rcv(i).motor_tr());
		(*net_signals)["INVERTER_L_RCV"]["motor_rs"].push(pack->inverter_l_rcv(i).motor_rs());
		(*net_signals)["INVERTER_L_RCV"]["motor_ts"].push(pack->inverter_l_rcv(i).motor_ts());
		(*net_enums)["INVERTER_L_RCV"]["def_end_1"].push(pack->inverter_l_rcv(i).def_end_1());
		primary_inverter_l_rcv_def_end_1_enum_to_string((primary_inverter_l_rcv_def_end_1)pack->inverter_l_rcv(i).def_end_1(), buffer);
		(*net_strings)["INVERTER_L_RCV"]["def_end_1"].push(buffer);
		(*net_enums)["INVERTER_L_RCV"]["def_end_2"].push(pack->inverter_l_rcv(i).def_end_2());
		primary_inverter_l_rcv_def_end_2_enum_to_string((primary_inverter_l_rcv_def_end_2)pack->inverter_l_rcv(i).def_end_2(), buffer);
		(*net_strings)["INVERTER_L_RCV"]["def_end_2"].push(buffer);
		(*net_enums)["INVERTER_L_RCV"]["def_din_1"].push(pack->inverter_l_rcv(i).def_din_1());
		primary_inverter_l_rcv_def_din_1_enum_to_string((primary_inverter_l_rcv_def_din_1)pack->inverter_l_rcv(i).def_din_1(), buffer);
		(*net_strings)["INVERTER_L_RCV"]["def_din_1"].push(buffer);
		(*net_enums)["INVERTER_L_RCV"]["def_din_2"].push(pack->inverter_l_rcv(i).def_din_2());
		primary_inverter_l_rcv_def_din_2_enum_to_string((primary_inverter_l_rcv_def_din_2)pack->inverter_l_rcv(i).def_din_2(), buffer);
		(*net_strings)["INVERTER_L_RCV"]["def_din_2"].push(buffer);
		(*net_enums)["INVERTER_L_RCV"]["operand194"].push(pack->inverter_l_rcv(i).operand194());
		primary_inverter_l_rcv_operand194_enum_to_string((primary_inverter_l_rcv_operand194)pack->inverter_l_rcv(i).operand194(), buffer);
		(*net_strings)["INVERTER_L_RCV"]["operand194"].push(buffer);
		(*net_signals)["INVERTER_L_RCV"]["i_max_inuse"].push(pack->inverter_l_rcv(i).i_max_inuse());
		(*net_signals)["INVERTER_L_RCV"]["signal_go"].push(pack->inverter_l_rcv(i).signal_go());
		(*net_signals)["INVERTER_L_RCV"]["signal_brake"].push(pack->inverter_l_rcv(i).signal_brake());
		(*net_signals)["INVERTER_L_RCV"]["signal_icns"].push(pack->inverter_l_rcv(i).signal_icns());
		(*net_signals)["INVERTER_L_RCV"]["signal_lessn0"].push(pack->inverter_l_rcv(i).signal_lessn0());
		(*net_signals)["INVERTER_L_RCV"]["signal_postolerance"].push(pack->inverter_l_rcv(i).signal_postolerance());
		(*net_signals)["INVERTER_L_RCV"]["ain_in_1_scaled251"].push(pack->inverter_l_rcv(i).ain_in_1_scaled251());
		(*net_signals)["INVERTER_L_RCV"]["ain_in_2_scaled252"].push(pack->inverter_l_rcv(i).ain_in_2_scaled252());
		(*net_enums)["INVERTER_L_RCV"]["operand195"].push(pack->inverter_l_rcv(i).operand195());
		primary_inverter_l_rcv_operand195_enum_to_string((primary_inverter_l_rcv_operand195)pack->inverter_l_rcv(i).operand195(), buffer);
		(*net_strings)["INVERTER_L_RCV"]["operand195"].push(buffer);
		(*net_enums)["INVERTER_L_RCV"]["operand218"].push(pack->inverter_l_rcv(i).operand218());
		primary_inverter_l_rcv_operand218_enum_to_string((primary_inverter_l_rcv_operand218)pack->inverter_l_rcv(i).operand218(), buffer);
		(*net_strings)["INVERTER_L_RCV"]["operand218"].push(buffer);
		(*net_enums)["INVERTER_L_RCV"]["operand219"].push(pack->inverter_l_rcv(i).operand219());
		primary_inverter_l_rcv_operand219_enum_to_string((primary_inverter_l_rcv_operand219)pack->inverter_l_rcv(i).operand219(), buffer);
		(*net_strings)["INVERTER_L_RCV"]["operand219"].push(buffer);
		(*net_signals)["INVERTER_L_RCV"]["pid_i__xkp__iq"].push(pack->inverter_l_rcv(i).pid_i__xkp__iq());
		(*net_signals)["INVERTER_L_RCV"]["bat_opr_limit__mot"].push(pack->inverter_l_rcv(i).bat_opr_limit__mot());
		(*net_signals)["INVERTER_L_RCV"]["pid_i__kf__iq"].push(pack->inverter_l_rcv(i).pid_i__kf__iq());
		(*net_signals)["INVERTER_L_RCV"]["dc_current_sens_ena_set"].push(pack->inverter_l_rcv(i).dc_current_sens_ena_set());
		(*net_signals)["INVERTER_L_RCV"]["cmc__bit0__dc_current_sens_ena"].push(pack->inverter_l_rcv(i).cmc__bit0__dc_current_sens_ena());
		(*net_signals)["INVERTER_L_RCV"]["n_rpm_maxint"].push(pack->inverter_l_rcv(i).n_rpm_maxint());
		(*net_signals)["INVERTER_L_RCV"]["var_1"].push(pack->inverter_l_rcv(i).var_1());
		(*net_signals)["INVERTER_L_RCV"]["can_rxtimeout"].push(pack->inverter_l_rcv(i).can_rxtimeout());
		(*net_signals)["INVERTER_L_RCV"]["var_2"].push(pack->inverter_l_rcv(i).var_2());
		(*net_signals)["INVERTER_L_RCV"]["var_3"].push(pack->inverter_l_rcv(i).var_3());
		(*net_signals)["INVERTER_L_RCV"]["var_4"].push(pack->inverter_l_rcv(i).var_4());
		(*net_signals)["INVERTER_L_RCV"]["dup__bit7_0__dac_source_channel"].push(pack->inverter_l_rcv(i).dup__bit7_0__dac_source_channel());
		(*net_signals)["INVERTER_L_RCV"]["fb_lossofsignal"].push(pack->inverter_l_rcv(i).fb_lossofsignal());
		(*net_signals)["INVERTER_L_RCV"]["no_hw_fault"].push(pack->inverter_l_rcv(i).no_hw_fault());
		(*net_signals)["INVERTER_L_RCV"]["t_peak"].push(pack->inverter_l_rcv(i).t_peak());
		(*net_signals)["INVERTER_L_RCV"]["brake_delay"].push(pack->inverter_l_rcv(i).brake_delay());
		(*net_signals)["INVERTER_L_RCV"]["power"].push(pack->inverter_l_rcv(i).power());
		(*net_signals)["INVERTER_L_RCV"]["work"].push(pack->inverter_l_rcv(i).work());
		(*net_signals)["INVERTER_L_RCV"]["extra__start"].push(pack->inverter_l_rcv(i).extra__start());
		(*net_signals)["INVERTER_L_RCV"]["capture_channel"].push(pack->inverter_l_rcv(i).capture_channel());
		(*net_signals)["INVERTER_L_RCV"]["trig_level"].push(pack->inverter_l_rcv(i).trig_level());
		(*net_signals)["INVERTER_L_RCV"]["trig_edge"].push(pack->inverter_l_rcv(i).trig_edge());
		(*net_signals)["INVERTER_L_RCV"]["trig_source"].push(pack->inverter_l_rcv(i).trig_source());
		(*net_signals)["INVERTER_L_RCV"]["oszi_source"].push(pack->inverter_l_rcv(i).oszi_source());
		(*net_signals)["INVERTER_L_RCV"]["oszi_skip"].push(pack->inverter_l_rcv(i).oszi_skip());
		(*net_signals)["INVERTER_L_RCV"]["oszi_run_cmd"].push(pack->inverter_l_rcv(i).oszi_run_cmd());
		(*net_signals)["INVERTER_L_RCV"]["oszi_read_cmd"].push(pack->inverter_l_rcv(i).oszi_read_cmd());
		(*net_signals)["INVERTER_L_RCV"]["pos_ref_start"].push(pack->inverter_l_rcv(i).pos_ref_start());
		(*net_signals)["INVERTER_L_RCV"]["vdc_bus"].push(pack->inverter_l_rcv(i).vdc_bus());
		(*net_signals)["INVERTER_L_RCV"]["m_cmd_ramp"].push(pack->inverter_l_rcv(i).m_cmd_ramp());
		(*net_signals)["INVERTER_L_RCV"]["lmt_1"].push(pack->inverter_l_rcv(i).lmt_1());
		(*net_signals)["INVERTER_L_RCV"]["out_1"].push(pack->inverter_l_rcv(i).out_1());
		(*net_signals)["INVERTER_L_RCV"]["subversion_nr"].push(pack->inverter_l_rcv(i).subversion_nr());
		(*net_signals)["INVERTER_L_RCV"]["ballast_ext"].push(pack->inverter_l_rcv(i).ballast_ext());
		(*net_signals)["INVERTER_L_RCV"]["ncr064"].push(pack->inverter_l_rcv(i).ncr064());
		(*net_signals)["INVERTER_L_RCV"]["err_powerfault"].push(pack->inverter_l_rcv(i).err_powerfault());
		(*net_signals)["INVERTER_L_RCV"]["lmt2"].push(pack->inverter_l_rcv(i).lmt2());
		(*net_signals)["INVERTER_L_RCV"]["km_speed_0"].push(pack->inverter_l_rcv(i).km_speed_0());
		(*net_signals)["INVERTER_L_RCV"]["ncr082"].push(pack->inverter_l_rcv(i).ncr082());
		(*net_signals)["INVERTER_L_RCV"]["ecode_bit1__hw1_state99"].push(pack->inverter_l_rcv(i).ecode_bit1__hw1_state99());
		(*net_signals)["INVERTER_L_RCV"]["ecode_bit1__hw1_state148"].push(pack->inverter_l_rcv(i).ecode_bit1__hw1_state148());
		(*net_signals)["INVERTER_L_RCV"]["dc_i_sensena_set"].push(pack->inverter_l_rcv(i).dc_i_sensena_set());
		(*net_signals)["INVERTER_L_RCV"]["cmc__bit1__idc_limit_ena"].push(pack->inverter_l_rcv(i).cmc__bit1__idc_limit_ena());
		(*net_signals)["INVERTER_L_RCV"]["lmt_2"].push(pack->inverter_l_rcv(i).lmt_2());
		(*net_signals)["INVERTER_L_RCV"]["out_2"].push(pack->inverter_l_rcv(i).out_2());
		(*net_signals)["INVERTER_L_RCV"]["fb_special"].push(pack->inverter_l_rcv(i).fb_special());
		(*net_signals)["INVERTER_L_RCV"]["lim_plus64"].push(pack->inverter_l_rcv(i).lim_plus64());
		(*net_signals)["INVERTER_L_RCV"]["err_rfe_fault"].push(pack->inverter_l_rcv(i).err_rfe_fault());
		(*net_signals)["INVERTER_L_RCV"]["in2"].push(pack->inverter_l_rcv(i).in2());
		(*net_enums)["INVERTER_L_RCV"]["cs_ain_2_format"].push(pack->inverter_l_rcv(i).cs_ain_2_format());
		primary_inverter_l_rcv_cs_ain_2_format_enum_to_string((primary_inverter_l_rcv_cs_ain_2_format)pack->inverter_l_rcv(i).cs_ain_2_format(), buffer);
		(*net_strings)["INVERTER_L_RCV"]["cs_ain_2_format"].push(buffer);
		(*net_signals)["INVERTER_L_RCV"]["km_frg_off"].push(pack->inverter_l_rcv(i).km_frg_off());
		(*net_signals)["INVERTER_L_RCV"]["lim_plus82"].push(pack->inverter_l_rcv(i).lim_plus82());
		(*net_signals)["INVERTER_L_RCV"]["ecode_bit2__hw0_state99"].push(pack->inverter_l_rcv(i).ecode_bit2__hw0_state99());
		(*net_signals)["INVERTER_L_RCV"]["ecode_bit2__hw0_state148"].push(pack->inverter_l_rcv(i).ecode_bit2__hw0_state148());
		(*net_signals)["INVERTER_L_RCV"]["op_mode_quadrant"].push(pack->inverter_l_rcv(i).op_mode_quadrant());
		(*net_signals)["INVERTER_L_RCV"]["cmc__bit2__pdc_limit_usage"].push(pack->inverter_l_rcv(i).cmc__bit2__pdc_limit_usage());
		(*net_signals)["INVERTER_L_RCV"]["in_2"].push(pack->inverter_l_rcv(i).in_2());
		(*net_signals)["INVERTER_L_RCV"]["rdy155"].push(pack->inverter_l_rcv(i).rdy155());
		(*net_signals)["INVERTER_L_RCV"]["coaststop"].push(pack->inverter_l_rcv(i).coaststop());
		(*net_signals)["INVERTER_L_RCV"]["lim_minus64"].push(pack->inverter_l_rcv(i).lim_minus64());
		(*net_signals)["INVERTER_L_RCV"]["err_bustimeout"].push(pack->inverter_l_rcv(i).err_bustimeout());
		(*net_signals)["INVERTER_L_RCV"]["in1"].push(pack->inverter_l_rcv(i).in1());
		(*net_signals)["INVERTER_L_RCV"]["km_cal_off"].push(pack->inverter_l_rcv(i).km_cal_off());
		(*net_signals)["INVERTER_L_RCV"]["lim_minus82"].push(pack->inverter_l_rcv(i).lim_minus82());
		(*net_signals)["INVERTER_L_RCV"]["ecode_bit3__free99"].push(pack->inverter_l_rcv(i).ecode_bit3__free99());
		(*net_signals)["INVERTER_L_RCV"]["ecode_bit3__free148"].push(pack->inverter_l_rcv(i).ecode_bit3__free148());
		(*net_signals)["INVERTER_L_RCV"]["cmc__bit3__torqueval_init_ena"].push(pack->inverter_l_rcv(i).cmc__bit3__torqueval_init_ena());
		(*net_signals)["INVERTER_L_RCV"]["in_1"].push(pack->inverter_l_rcv(i).in_1());
		(*net_signals)["INVERTER_L_RCV"]["go155"].push(pack->inverter_l_rcv(i).go155());
		(*net_signals)["INVERTER_L_RCV"]["i_ist_inverse"].push(pack->inverter_l_rcv(i).i_ist_inverse());
		(*net_signals)["INVERTER_L_RCV"]["ok64"].push(pack->inverter_l_rcv(i).ok64());
		(*net_signals)["INVERTER_L_RCV"]["err_feedbacksignal"].push(pack->inverter_l_rcv(i).err_feedbacksignal());
		(*net_signals)["INVERTER_L_RCV"]["frgrun"].push(pack->inverter_l_rcv(i).frgrun());
		(*net_enums)["INVERTER_L_RCV"]["cs_ain_1_mode"].push(pack->inverter_l_rcv(i).cs_ain_1_mode());
		primary_inverter_l_rcv_cs_ain_1_mode_enum_to_string((primary_inverter_l_rcv_cs_ain_1_mode)pack->inverter_l_rcv(i).cs_ain_1_mode(), buffer);
		(*net_strings)["INVERTER_L_RCV"]["cs_ain_1_mode"].push(buffer);
		(*net_signals)["INVERTER_L_RCV"]["km_tx_tog_stat"].push(pack->inverter_l_rcv(i).km_tx_tog_stat());
		(*net_signals)["INVERTER_L_RCV"]["ok82"].push(pack->inverter_l_rcv(i).ok82());
		(*net_signals)["INVERTER_L_RCV"]["ecode_bit4__rdy399"].push(pack->inverter_l_rcv(i).ecode_bit4__rdy399());
		(*net_signals)["INVERTER_L_RCV"]["ecode_bit4__rdy3148"].push(pack->inverter_l_rcv(i).ecode_bit4__rdy3148());
		(*net_enums)["INVERTER_L_RCV"]["compare_var194"].push(pack->inverter_l_rcv(i).compare_var194());
		primary_inverter_l_rcv_compare_var194_enum_to_string((primary_inverter_l_rcv_compare_var194)pack->inverter_l_rcv(i).compare_var194(), buffer);
		(*net_strings)["INVERTER_L_RCV"]["compare_var194"].push(buffer);
		(*net_enums)["INVERTER_L_RCV"]["compare_var195"].push(pack->inverter_l_rcv(i).compare_var195());
		primary_inverter_l_rcv_compare_var195_enum_to_string((primary_inverter_l_rcv_compare_var195)pack->inverter_l_rcv(i).compare_var195(), buffer);
		(*net_strings)["INVERTER_L_RCV"]["compare_var195"].push(buffer);
		(*net_enums)["INVERTER_L_RCV"]["compare_var218"].push(pack->inverter_l_rcv(i).compare_var218());
		primary_inverter_l_rcv_compare_var218_enum_to_string((primary_inverter_l_rcv_compare_var218)pack->inverter_l_rcv(i).compare_var218(), buffer);
		(*net_strings)["INVERTER_L_RCV"]["compare_var218"].push(buffer);
		(*net_enums)["INVERTER_L_RCV"]["compare_var219"].push(pack->inverter_l_rcv(i).compare_var219());
		primary_inverter_l_rcv_compare_var219_enum_to_string((primary_inverter_l_rcv_compare_var219)pack->inverter_l_rcv(i).compare_var219(), buffer);
		(*net_strings)["INVERTER_L_RCV"]["compare_var219"].push(buffer);
		(*net_signals)["INVERTER_L_RCV"]["cmc__bit4__dig_m_rcpramp_ena"].push(pack->inverter_l_rcv(i).cmc__bit4__dig_m_rcpramp_ena());
		(*net_signals)["INVERTER_L_RCV"]["run152"].push(pack->inverter_l_rcv(i).run152());
		(*net_signals)["INVERTER_L_RCV"]["out_3"].push(pack->inverter_l_rcv(i).out_3());
		(*net_signals)["INVERTER_L_RCV"]["refsoft"].push(pack->inverter_l_rcv(i).refsoft());
		(*net_signals)["INVERTER_L_RCV"]["icns64"].push(pack->inverter_l_rcv(i).icns64());
		(*net_signals)["INVERTER_L_RCV"]["err_powervoltage_low"].push(pack->inverter_l_rcv(i).err_powervoltage_low());
		(*net_signals)["INVERTER_L_RCV"]["rfe216"].push(pack->inverter_l_rcv(i).rfe216());
		(*net_signals)["INVERTER_L_RCV"]["km_i_limit"].push(pack->inverter_l_rcv(i).km_i_limit());
		(*net_signals)["INVERTER_L_RCV"]["icns82"].push(pack->inverter_l_rcv(i).icns82());
		(*net_signals)["INVERTER_L_RCV"]["ecode_bit5__n_fail99"].push(pack->inverter_l_rcv(i).ecode_bit5__n_fail99());
		(*net_signals)["INVERTER_L_RCV"]["ecode_bit5__n_fail148"].push(pack->inverter_l_rcv(i).ecode_bit5__n_fail148());
		(*net_enums)["INVERTER_L_RCV"]["mo_feedback_2"].push(pack->inverter_l_rcv(i).mo_feedback_2());
		primary_inverter_l_rcv_mo_feedback_2_enum_to_string((primary_inverter_l_rcv_mo_feedback_2)pack->inverter_l_rcv(i).mo_feedback_2(), buffer);
		(*net_strings)["INVERTER_L_RCV"]["mo_feedback_2"].push(buffer);
		(*net_signals)["INVERTER_L_RCV"]["recup_is_acv"].push(pack->inverter_l_rcv(i).recup_is_acv());
		(*net_signals)["INVERTER_L_RCV"]["cmc__bit5__reset_nramp_atnzero"].push(pack->inverter_l_rcv(i).cmc__bit5__reset_nramp_atnzero());
		(*net_signals)["INVERTER_L_RCV"]["rfe152"].push(pack->inverter_l_rcv(i).rfe152());
		(*net_signals)["INVERTER_L_RCV"]["out_4"].push(pack->inverter_l_rcv(i).out_4());
		(*net_signals)["INVERTER_L_RCV"]["no_uesp_btb"].push(pack->inverter_l_rcv(i).no_uesp_btb());
		(*net_signals)["INVERTER_L_RCV"]["tnlim64"].push(pack->inverter_l_rcv(i).tnlim64());
		(*net_signals)["INVERTER_L_RCV"]["err_motortemp"].push(pack->inverter_l_rcv(i).err_motortemp());
		(*net_signals)["INVERTER_L_RCV"]["km_n_clip"].push(pack->inverter_l_rcv(i).km_n_clip());
		(*net_signals)["INVERTER_L_RCV"]["tnlim82"].push(pack->inverter_l_rcv(i).tnlim82());
		(*net_signals)["INVERTER_L_RCV"]["ecode_bit6__flths99"].push(pack->inverter_l_rcv(i).ecode_bit6__flths99());
		(*net_signals)["INVERTER_L_RCV"]["ecode_bit6__flths148"].push(pack->inverter_l_rcv(i).ecode_bit6__flths148());
		(*net_signals)["INVERTER_L_RCV"]["i_dc_limit_is_acv"].push(pack->inverter_l_rcv(i).i_dc_limit_is_acv());
		(*net_signals)["INVERTER_L_RCV"]["cmc__bit6__torquetimeout_100ms_e"].push(pack->inverter_l_rcv(i).cmc__bit6__torquetimeout_100ms_e());
		(*net_signals)["INVERTER_L_RCV"]["rsvd"].push(pack->inverter_l_rcv(i).rsvd());
		(*net_signals)["INVERTER_L_RCV"]["rsvd1"].push(pack->inverter_l_rcv(i).rsvd1());
		(*net_signals)["INVERTER_L_RCV"]["vdc_ana"].push(pack->inverter_l_rcv(i).vdc_ana());
		(*net_signals)["INVERTER_L_RCV"]["pn64"].push(pack->inverter_l_rcv(i).pn64());
		(*net_signals)["INVERTER_L_RCV"]["err_devicetemp"].push(pack->inverter_l_rcv(i).err_devicetemp());
		(*net_signals)["INVERTER_L_RCV"]["cs_oora1"].push(pack->inverter_l_rcv(i).cs_oora1());
		(*net_signals)["INVERTER_L_RCV"]["km_mix_ana_on"].push(pack->inverter_l_rcv(i).km_mix_ana_on());
		(*net_signals)["INVERTER_L_RCV"]["pn82"].push(pack->inverter_l_rcv(i).pn82());
		(*net_signals)["INVERTER_L_RCV"]["ecode_bit7__fltls99"].push(pack->inverter_l_rcv(i).ecode_bit7__fltls99());
		(*net_signals)["INVERTER_L_RCV"]["ecode_bit7__fltls148"].push(pack->inverter_l_rcv(i).ecode_bit7__fltls148());
		(*net_signals)["INVERTER_L_RCV"]["cmc__bit13_7__free"].push(pack->inverter_l_rcv(i).cmc__bit13_7__free());
		(*net_signals)["INVERTER_L_RCV"]["brk1155"].push(pack->inverter_l_rcv(i).brk1155());
		(*net_signals)["INVERTER_L_RCV"]["i1_adc_ena"].push(pack->inverter_l_rcv(i).i1_adc_ena());
		(*net_signals)["INVERTER_L_RCV"]["ni64"].push(pack->inverter_l_rcv(i).ni64());
		(*net_signals)["INVERTER_L_RCV"]["err_overvoltage"].push(pack->inverter_l_rcv(i).err_overvoltage());
		(*net_signals)["INVERTER_L_RCV"]["out1"].push(pack->inverter_l_rcv(i).out1());
		(*net_enums)["INVERTER_L_RCV"]["cs_ain_2_mode"].push(pack->inverter_l_rcv(i).cs_ain_2_mode());
		primary_inverter_l_rcv_cs_ain_2_mode_enum_to_string((primary_inverter_l_rcv_cs_ain_2_mode)pack->inverter_l_rcv(i).cs_ain_2_mode(), buffer);
		(*net_strings)["INVERTER_L_RCV"]["cs_ain_2_mode"].push(buffer);
		(*net_enums)["INVERTER_L_RCV"]["ctrlsubmode"].push(pack->inverter_l_rcv(i).ctrlsubmode());
		primary_inverter_l_rcv_ctrlsubmode_enum_to_string((primary_inverter_l_rcv_ctrlsubmode)pack->inverter_l_rcv(i).ctrlsubmode(), buffer);
		(*net_strings)["INVERTER_L_RCV"]["ctrlsubmode"].push(buffer);
		(*net_signals)["INVERTER_L_RCV"]["km_allow_sync"].push(pack->inverter_l_rcv(i).km_allow_sync());
		(*net_signals)["INVERTER_L_RCV"]["ni82"].push(pack->inverter_l_rcv(i).ni82());
		(*net_signals)["INVERTER_L_RCV"]["ain_in_2_filter"].push(pack->inverter_l_rcv(i).ain_in_2_filter());
		(*net_signals)["INVERTER_L_RCV"]["ecode_bit8__fail_idc99"].push(pack->inverter_l_rcv(i).ecode_bit8__fail_idc99());
		(*net_signals)["INVERTER_L_RCV"]["ecode_bit8__fail_idc148"].push(pack->inverter_l_rcv(i).ecode_bit8__fail_idc148());
		(*net_enums)["INVERTER_L_RCV"]["mo_sc1_reso"].push(pack->inverter_l_rcv(i).mo_sc1_reso());
		primary_inverter_l_rcv_mo_sc1_reso_enum_to_string((primary_inverter_l_rcv_mo_sc1_reso)pack->inverter_l_rcv(i).mo_sc1_reso(), buffer);
		(*net_strings)["INVERTER_L_RCV"]["mo_sc1_reso"].push(buffer);
		(*net_enums)["INVERTER_L_RCV"]["source_id194"].push(pack->inverter_l_rcv(i).source_id194());
		primary_inverter_l_rcv_source_id194_enum_to_string((primary_inverter_l_rcv_source_id194)pack->inverter_l_rcv(i).source_id194(), buffer);
		(*net_strings)["INVERTER_L_RCV"]["source_id194"].push(buffer);
		(*net_enums)["INVERTER_L_RCV"]["source_id195"].push(pack->inverter_l_rcv(i).source_id195());
		primary_inverter_l_rcv_source_id195_enum_to_string((primary_inverter_l_rcv_source_id195)pack->inverter_l_rcv(i).source_id195(), buffer);
		(*net_strings)["INVERTER_L_RCV"]["source_id195"].push(buffer);
		(*net_enums)["INVERTER_L_RCV"]["source_id218"].push(pack->inverter_l_rcv(i).source_id218());
		primary_inverter_l_rcv_source_id218_enum_to_string((primary_inverter_l_rcv_source_id218)pack->inverter_l_rcv(i).source_id218(), buffer);
		(*net_strings)["INVERTER_L_RCV"]["source_id218"].push(buffer);
		(*net_enums)["INVERTER_L_RCV"]["source_id219"].push(pack->inverter_l_rcv(i).source_id219());
		primary_inverter_l_rcv_source_id219_enum_to_string((primary_inverter_l_rcv_source_id219)pack->inverter_l_rcv(i).source_id219(), buffer);
		(*net_strings)["INVERTER_L_RCV"]["source_id219"].push(buffer);
		(*net_signals)["INVERTER_L_RCV"]["dup__bit8__can_extended_0"].push(pack->inverter_l_rcv(i).dup__bit8__can_extended_0());
		(*net_signals)["INVERTER_L_RCV"]["hxinv"].push(pack->inverter_l_rcv(i).hxinv());
		(*net_signals)["INVERTER_L_RCV"]["_n064"].push(pack->inverter_l_rcv(i)._n064());
		(*net_signals)["INVERTER_L_RCV"]["err_ipeak"].push(pack->inverter_l_rcv(i).err_ipeak());
		(*net_signals)["INVERTER_L_RCV"]["out2"].push(pack->inverter_l_rcv(i).out2());
		(*net_signals)["INVERTER_L_RCV"]["km_handwheel"].push(pack->inverter_l_rcv(i).km_handwheel());
		(*net_signals)["INVERTER_L_RCV"]["_n082"].push(pack->inverter_l_rcv(i)._n082());
		(*net_signals)["INVERTER_L_RCV"]["ecode_bit9__fail_i99"].push(pack->inverter_l_rcv(i).ecode_bit9__fail_i99());
		(*net_signals)["INVERTER_L_RCV"]["ecode_bit9__fail_i148"].push(pack->inverter_l_rcv(i).ecode_bit9__fail_i148());
		(*net_signals)["INVERTER_L_RCV"]["dup__bit9__generator"].push(pack->inverter_l_rcv(i).dup__bit9__generator());
		(*net_signals)["INVERTER_L_RCV"]["h2inv"].push(pack->inverter_l_rcv(i).h2inv());
		(*net_signals)["INVERTER_L_RCV"]["rsw64"].push(pack->inverter_l_rcv(i).rsw64());
		(*net_signals)["INVERTER_L_RCV"]["err_raceaway"].push(pack->inverter_l_rcv(i).err_raceaway());
		(*net_signals)["INVERTER_L_RCV"]["btbrdy"].push(pack->inverter_l_rcv(i).btbrdy());
		(*net_signals)["INVERTER_L_RCV"]["km_phasing_extend"].push(pack->inverter_l_rcv(i).km_phasing_extend());
		(*net_signals)["INVERTER_L_RCV"]["rsw82"].push(pack->inverter_l_rcv(i).rsw82());
		(*net_signals)["INVERTER_L_RCV"]["ecode_bit10__vccm99"].push(pack->inverter_l_rcv(i).ecode_bit10__vccm99());
		(*net_signals)["INVERTER_L_RCV"]["ecode_bit10__vccm148"].push(pack->inverter_l_rcv(i).ecode_bit10__vccm148());
		(*net_signals)["INVERTER_L_RCV"]["dup__bit10__park_rms"].push(pack->inverter_l_rcv(i).dup__bit10__park_rms());
		(*net_signals)["INVERTER_L_RCV"]["ol_comp"].push(pack->inverter_l_rcv(i).ol_comp());
		(*net_signals)["INVERTER_L_RCV"]["cal064"].push(pack->inverter_l_rcv(i).cal064());
		(*net_signals)["INVERTER_L_RCV"]["err_user"].push(pack->inverter_l_rcv(i).err_user());
		(*net_signals)["INVERTER_L_RCV"]["go216"].push(pack->inverter_l_rcv(i).go216());
		(*net_signals)["INVERTER_L_RCV"]["cs_oora2"].push(pack->inverter_l_rcv(i).cs_oora2());
		(*net_signals)["INVERTER_L_RCV"]["km_rsvd_11"].push(pack->inverter_l_rcv(i).km_rsvd_11());
		(*net_signals)["INVERTER_L_RCV"]["cal082"].push(pack->inverter_l_rcv(i).cal082());
		(*net_signals)["INVERTER_L_RCV"]["ecode_bit11__15m_minus99"].push(pack->inverter_l_rcv(i).ecode_bit11__15m_minus99());
		(*net_signals)["INVERTER_L_RCV"]["ecode_bit11__15m_minus148"].push(pack->inverter_l_rcv(i).ecode_bit11__15m_minus148());
		(*net_signals)["INVERTER_L_RCV"]["mo_sc1_comp"].push(pack->inverter_l_rcv(i).mo_sc1_comp());
		(*net_signals)["INVERTER_L_RCV"]["dup__bit11__dcbus_volts"].push(pack->inverter_l_rcv(i).dup__bit11__dcbus_volts());
		(*net_signals)["INVERTER_L_RCV"]["test"].push(pack->inverter_l_rcv(i).test());
		(*net_enums)["INVERTER_L_RCV"]["motortype"].push(pack->inverter_l_rcv(i).motortype());
		primary_inverter_l_rcv_motortype_enum_to_string((primary_inverter_l_rcv_motortype)pack->inverter_l_rcv(i).motortype(), buffer);
		(*net_strings)["INVERTER_L_RCV"]["motortype"].push(buffer);
		(*net_signals)["INVERTER_L_RCV"]["cal64"].push(pack->inverter_l_rcv(i).cal64());
		(*net_signals)["INVERTER_L_RCV"]["out3"].push(pack->inverter_l_rcv(i).out3());
		(*net_enums)["INVERTER_L_RCV"]["cs_cmd_type"].push(pack->inverter_l_rcv(i).cs_cmd_type());
		primary_inverter_l_rcv_cs_cmd_type_enum_to_string((primary_inverter_l_rcv_cs_cmd_type)pack->inverter_l_rcv(i).cs_cmd_type(), buffer);
		(*net_strings)["INVERTER_L_RCV"]["cs_cmd_type"].push(buffer);
		(*net_enums)["INVERTER_L_RCV"]["currentmode"].push(pack->inverter_l_rcv(i).currentmode());
		primary_inverter_l_rcv_currentmode_enum_to_string((primary_inverter_l_rcv_currentmode)pack->inverter_l_rcv(i).currentmode(), buffer);
		(*net_strings)["INVERTER_L_RCV"]["currentmode"].push(buffer);
		(*net_signals)["INVERTER_L_RCV"]["km_rsvd_12"].push(pack->inverter_l_rcv(i).km_rsvd_12());
		(*net_signals)["INVERTER_L_RCV"]["cal82"].push(pack->inverter_l_rcv(i).cal82());
		(*net_signals)["INVERTER_L_RCV"]["ecode_bit12__15m_plus99"].push(pack->inverter_l_rcv(i).ecode_bit12__15m_plus99());
		(*net_signals)["INVERTER_L_RCV"]["ecode_bit12__15m_plus148"].push(pack->inverter_l_rcv(i).ecode_bit12__15m_plus148());
		(*net_enums)["INVERTER_L_RCV"]["mo_sc2_reso"].push(pack->inverter_l_rcv(i).mo_sc2_reso());
		primary_inverter_l_rcv_mo_sc2_reso_enum_to_string((primary_inverter_l_rcv_mo_sc2_reso)pack->inverter_l_rcv(i).mo_sc2_reso(), buffer);
		(*net_strings)["INVERTER_L_RCV"]["mo_sc2_reso"].push(buffer);
		(*net_signals)["INVERTER_L_RCV"]["dup__bit12__boat_pedal"].push(pack->inverter_l_rcv(i).dup__bit12__boat_pedal());
		(*net_signals)["INVERTER_L_RCV"]["tol64"].push(pack->inverter_l_rcv(i).tol64());
		(*net_signals)["INVERTER_L_RCV"]["out4"].push(pack->inverter_l_rcv(i).out4());
		(*net_signals)["INVERTER_L_RCV"]["km_rsvd_13"].push(pack->inverter_l_rcv(i).km_rsvd_13());
		(*net_signals)["INVERTER_L_RCV"]["tol82"].push(pack->inverter_l_rcv(i).tol82());
		(*net_signals)["INVERTER_L_RCV"]["ecode_bit13__18m_plus99"].push(pack->inverter_l_rcv(i).ecode_bit13__18m_plus99());
		(*net_signals)["INVERTER_L_RCV"]["ecode_bit13__18m_plus148"].push(pack->inverter_l_rcv(i).ecode_bit13__18m_plus148());
		(*net_signals)["INVERTER_L_RCV"]["dup__bit13__gen_autoiaclimit"].push(pack->inverter_l_rcv(i).dup__bit13__gen_autoiaclimit());
		(*net_signals)["INVERTER_L_RCV"]["ana_0up"].push(pack->inverter_l_rcv(i).ana_0up());
		(*net_signals)["INVERTER_L_RCV"]["rdy64"].push(pack->inverter_l_rcv(i).rdy64());
		(*net_signals)["INVERTER_L_RCV"]["err_hwerr"].push(pack->inverter_l_rcv(i).err_hwerr());
		(*net_signals)["INVERTER_L_RCV"]["goff"].push(pack->inverter_l_rcv(i).goff());
		(*net_signals)["INVERTER_L_RCV"]["cs_ain_2__i_limit"].push(pack->inverter_l_rcv(i).cs_ain_2__i_limit());
		(*net_signals)["INVERTER_L_RCV"]["km_pseudo_enable"].push(pack->inverter_l_rcv(i).km_pseudo_enable());
		(*net_signals)["INVERTER_L_RCV"]["rdy82"].push(pack->inverter_l_rcv(i).rdy82());
		(*net_signals)["INVERTER_L_RCV"]["ecode_bit14__ubmam99"].push(pack->inverter_l_rcv(i).ecode_bit14__ubmam99());
		(*net_signals)["INVERTER_L_RCV"]["ecode_bit14__ubmam148"].push(pack->inverter_l_rcv(i).ecode_bit14__ubmam148());
		(*net_signals)["INVERTER_L_RCV"]["cmc__bit14__idc_limit_ena_v2"].push(pack->inverter_l_rcv(i).cmc__bit14__idc_limit_ena_v2());
		(*net_signals)["INVERTER_L_RCV"]["dup__bit14__mtpa_reluct_enab"].push(pack->inverter_l_rcv(i).dup__bit14__mtpa_reluct_enab());
		(*net_signals)["INVERTER_L_RCV"]["lowbd"].push(pack->inverter_l_rcv(i).lowbd());
		(*net_signals)["INVERTER_L_RCV"]["brk064"].push(pack->inverter_l_rcv(i).brk064());
		(*net_signals)["INVERTER_L_RCV"]["err_ballast"].push(pack->inverter_l_rcv(i).err_ballast());
		(*net_signals)["INVERTER_L_RCV"]["brk1216"].push(pack->inverter_l_rcv(i).brk1216());
		(*net_signals)["INVERTER_L_RCV"]["cs_ain_1__n_limit"].push(pack->inverter_l_rcv(i).cs_ain_1__n_limit());
		(*net_signals)["INVERTER_L_RCV"]["km_debug_test"].push(pack->inverter_l_rcv(i).km_debug_test());
		(*net_signals)["INVERTER_L_RCV"]["brk082"].push(pack->inverter_l_rcv(i).brk082());
		(*net_signals)["INVERTER_L_RCV"]["ecode_bit15__t_igbt99"].push(pack->inverter_l_rcv(i).ecode_bit15__t_igbt99());
		(*net_signals)["INVERTER_L_RCV"]["ecode_bit15__t_igbt148"].push(pack->inverter_l_rcv(i).ecode_bit15__t_igbt148());
		(*net_signals)["INVERTER_L_RCV"]["mo_sc2_inv"].push(pack->inverter_l_rcv(i).mo_sc2_inv());
		(*net_enums)["INVERTER_L_RCV"]["active190"].push(pack->inverter_l_rcv(i).active190());
		primary_inverter_l_rcv_active190_enum_to_string((primary_inverter_l_rcv_active190)pack->inverter_l_rcv(i).active190(), buffer);
		(*net_strings)["INVERTER_L_RCV"]["active190"].push(buffer);
		(*net_enums)["INVERTER_L_RCV"]["active191"].push(pack->inverter_l_rcv(i).active191());
		primary_inverter_l_rcv_active191_enum_to_string((primary_inverter_l_rcv_active191)pack->inverter_l_rcv(i).active191(), buffer);
		(*net_strings)["INVERTER_L_RCV"]["active191"].push(buffer);
		(*net_enums)["INVERTER_L_RCV"]["active192"].push(pack->inverter_l_rcv(i).active192());
		primary_inverter_l_rcv_active192_enum_to_string((primary_inverter_l_rcv_active192)pack->inverter_l_rcv(i).active192(), buffer);
		(*net_strings)["INVERTER_L_RCV"]["active192"].push(buffer);
		(*net_enums)["INVERTER_L_RCV"]["active193"].push(pack->inverter_l_rcv(i).active193());
		primary_inverter_l_rcv_active193_enum_to_string((primary_inverter_l_rcv_active193)pack->inverter_l_rcv(i).active193(), buffer);
		(*net_strings)["INVERTER_L_RCV"]["active193"].push(buffer);
		(*net_signals)["INVERTER_L_RCV"]["gen_autoiaclimit_is_acv"].push(pack->inverter_l_rcv(i).gen_autoiaclimit_is_acv());
		(*net_signals)["INVERTER_L_RCV"]["cmc__bit15__dig_e_brake_act"].push(pack->inverter_l_rcv(i).cmc__bit15__dig_e_brake_act());
		(*net_signals)["INVERTER_L_RCV"]["dup__bit15__canopen_acv"].push(pack->inverter_l_rcv(i).dup__bit15__canopen_acv());
		(*net_signals)["INVERTER_L_RCV"]["m_r_dec"].push(pack->inverter_l_rcv(i).m_r_dec());
		(*net_signals)["INVERTER_L_RCV"]["m_r_rcp"].push(pack->inverter_l_rcv(i).m_r_rcp());
		(*net_signals)["INVERTER_L_RCV"]["sramp"].push(pack->inverter_l_rcv(i).sramp());
		(*net_signals)["INVERTER_L_RCV"]["signmag64"].push(pack->inverter_l_rcv(i).signmag64());
		(*net_signals)["INVERTER_L_RCV"]["warn_warning_0"].push(pack->inverter_l_rcv(i).warn_warning_0());
		(*net_signals)["INVERTER_L_RCV"]["ain_in_1_scaled213"].push(pack->inverter_l_rcv(i).ain_in_1_scaled213());
		(*net_signals)["INVERTER_L_RCV"]["ain_in_2_scaled214"].push(pack->inverter_l_rcv(i).ain_in_2_scaled214());
		(*net_signals)["INVERTER_L_RCV"]["t_dc__stop"].push(pack->inverter_l_rcv(i).t_dc__stop());
		(*net_signals)["INVERTER_L_RCV"]["v_dc__stop"].push(pack->inverter_l_rcv(i).v_dc__stop());
		(*net_signals)["INVERTER_L_RCV"]["v_min__stop"].push(pack->inverter_l_rcv(i).v_min__stop());
		(*net_signals)["INVERTER_L_RCV"]["f_min__stop"].push(pack->inverter_l_rcv(i).f_min__stop());
		(*net_signals)["INVERTER_L_RCV"]["v_corner__stop"].push(pack->inverter_l_rcv(i).v_corner__stop());
		(*net_signals)["INVERTER_L_RCV"]["f_corner__stop"].push(pack->inverter_l_rcv(i).f_corner__stop());
		(*net_signals)["INVERTER_L_RCV"]["pid_i__kp__id"].push(pack->inverter_l_rcv(i).pid_i__kp__id());
		(*net_signals)["INVERTER_L_RCV"]["pid_i__ti__id"].push(pack->inverter_l_rcv(i).pid_i__ti__id());
		(*net_signals)["INVERTER_L_RCV"]["pid_i__tim__id"].push(pack->inverter_l_rcv(i).pid_i__tim__id());
		(*net_signals)["INVERTER_L_RCV"]["ain_in_1_scaleval"].push(pack->inverter_l_rcv(i).ain_in_1_scaleval());
		(*net_signals)["INVERTER_L_RCV"]["ain_in_2_scaleval"].push(pack->inverter_l_rcv(i).ain_in_2_scaleval());
		(*net_signals)["INVERTER_L_RCV"]["signmag82"].push(pack->inverter_l_rcv(i).signmag82());
		(*net_signals)["INVERTER_L_RCV"]["regen_r"].push(pack->inverter_l_rcv(i).regen_r());
		(*net_signals)["INVERTER_L_RCV"]["dc_bus_max_lim"].push(pack->inverter_l_rcv(i).dc_bus_max_lim());
		(*net_signals)["INVERTER_L_RCV"]["pid_i__xkp__id"].push(pack->inverter_l_rcv(i).pid_i__xkp__id());
		(*net_signals)["INVERTER_L_RCV"]["bat_opr_limit__gen"].push(pack->inverter_l_rcv(i).bat_opr_limit__gen());
		(*net_signals)["INVERTER_L_RCV"]["pid_i__kf__id"].push(pack->inverter_l_rcv(i).pid_i__kf__id());
		(*net_signals)["INVERTER_L_RCV"]["cmc__bit17_16__checkipeak_config"].push(pack->inverter_l_rcv(i).cmc__bit17_16__checkipeak_config());
		(*net_signals)["INVERTER_L_RCV"]["dup__bit16__bamobil3_2_offcrct"].push(pack->inverter_l_rcv(i).dup__bit16__bamobil3_2_offcrct());
		(*net_signals)["INVERTER_L_RCV"]["special__stop"].push(pack->inverter_l_rcv(i).special__stop());
		(*net_signals)["INVERTER_L_RCV"]["free"].push(pack->inverter_l_rcv(i).free());
		(*net_signals)["INVERTER_L_RCV"]["svnrevision_nr"].push(pack->inverter_l_rcv(i).svnrevision_nr());
		(*net_signals)["INVERTER_L_RCV"]["ramp4"].push(pack->inverter_l_rcv(i).ramp4());
		(*net_signals)["INVERTER_L_RCV"]["nclip64"].push(pack->inverter_l_rcv(i).nclip64());
		(*net_signals)["INVERTER_L_RCV"]["warn_illegal_status"].push(pack->inverter_l_rcv(i).warn_illegal_status());
		(*net_signals)["INVERTER_L_RCV"]["nclip82"].push(pack->inverter_l_rcv(i).nclip82());
		(*net_signals)["INVERTER_L_RCV"]["dup__bit19_17__ecode_redefine"].push(pack->inverter_l_rcv(i).dup__bit19_17__ecode_redefine());
		(*net_signals)["INVERTER_L_RCV"]["motbrake"].push(pack->inverter_l_rcv(i).motbrake());
		(*net_signals)["INVERTER_L_RCV"]["nclip_minus64"].push(pack->inverter_l_rcv(i).nclip_minus64());
		(*net_signals)["INVERTER_L_RCV"]["warn_safe_in"].push(pack->inverter_l_rcv(i).warn_safe_in());
		(*net_signals)["INVERTER_L_RCV"]["nclip_minus82"].push(pack->inverter_l_rcv(i).nclip_minus82());
		(*net_signals)["INVERTER_L_RCV"]["cmc__bit18__tractioncontrol_ena"].push(pack->inverter_l_rcv(i).cmc__bit18__tractioncontrol_ena());
		(*net_signals)["INVERTER_L_RCV"]["ac_dc"].push(pack->inverter_l_rcv(i).ac_dc());
		(*net_signals)["INVERTER_L_RCV"]["nclip_plus64"].push(pack->inverter_l_rcv(i).nclip_plus64());
		(*net_signals)["INVERTER_L_RCV"]["nclip_plus82"].push(pack->inverter_l_rcv(i).nclip_plus82());
		(*net_signals)["INVERTER_L_RCV"]["cmc__bit20_19__tc_deltatime_conf"].push(pack->inverter_l_rcv(i).cmc__bit20_19__tc_deltatime_conf());
		(*net_enums)["INVERTER_L_RCV"]["pwm_freq"].push(pack->inverter_l_rcv(i).pwm_freq());
		primary_inverter_l_rcv_pwm_freq_enum_to_string((primary_inverter_l_rcv_pwm_freq)pack->inverter_l_rcv(i).pwm_freq(), buffer);
		(*net_strings)["INVERTER_L_RCV"]["pwm_freq"].push(buffer);
		(*net_signals)["INVERTER_L_RCV"]["irddig64"].push(pack->inverter_l_rcv(i).irddig64());
		(*net_signals)["INVERTER_L_RCV"]["irddig82"].push(pack->inverter_l_rcv(i).irddig82());
		(*net_signals)["INVERTER_L_RCV"]["dup__bit20__hal_extmr_acv"].push(pack->inverter_l_rcv(i).dup__bit20__hal_extmr_acv());
		(*net_signals)["INVERTER_L_RCV"]["iuserchd64"].push(pack->inverter_l_rcv(i).iuserchd64());
		(*net_signals)["INVERTER_L_RCV"]["iuserchd82"].push(pack->inverter_l_rcv(i).iuserchd82());
		(*net_signals)["INVERTER_L_RCV"]["cmc__bit22_21__tc_minspeed_conf"].push(pack->inverter_l_rcv(i).cmc__bit22_21__tc_minspeed_conf());
		(*net_signals)["INVERTER_L_RCV"]["dup__bit21__initwith_frg_off"].push(pack->inverter_l_rcv(i).dup__bit21__initwith_frg_off());
		(*net_signals)["INVERTER_L_RCV"]["irdn64"].push(pack->inverter_l_rcv(i).irdn64());
		(*net_signals)["INVERTER_L_RCV"]["warn_motortemp"].push(pack->inverter_l_rcv(i).warn_motortemp());
		(*net_signals)["INVERTER_L_RCV"]["irdn82"].push(pack->inverter_l_rcv(i).irdn82());
		(*net_signals)["INVERTER_L_RCV"]["dup__bit31_22__free"].push(pack->inverter_l_rcv(i).dup__bit31_22__free());
		(*net_signals)["INVERTER_L_RCV"]["ntc"].push(pack->inverter_l_rcv(i).ntc());
		(*net_signals)["INVERTER_L_RCV"]["irdti64"].push(pack->inverter_l_rcv(i).irdti64());
		(*net_signals)["INVERTER_L_RCV"]["warn_devicetemp"].push(pack->inverter_l_rcv(i).warn_devicetemp());
		(*net_signals)["INVERTER_L_RCV"]["irdti82"].push(pack->inverter_l_rcv(i).irdti82());
		(*net_signals)["INVERTER_L_RCV"]["cmc__bit23__tc_ncmdrestoption"].push(pack->inverter_l_rcv(i).cmc__bit23__tc_ncmdrestoption());
		(*net_signals)["INVERTER_L_RCV"]["m_r_acc"].push(pack->inverter_l_rcv(i).m_r_acc());
		(*net_signals)["INVERTER_L_RCV"]["delta"].push(pack->inverter_l_rcv(i).delta());
		(*net_signals)["INVERTER_L_RCV"]["irdtir64"].push(pack->inverter_l_rcv(i).irdtir64());
		(*net_signals)["INVERTER_L_RCV"]["warn_vout_sat"].push(pack->inverter_l_rcv(i).warn_vout_sat());
		(*net_signals)["INVERTER_L_RCV"]["irdtir82"].push(pack->inverter_l_rcv(i).irdtir82());
		(*net_signals)["INVERTER_L_RCV"]["cmc__bit31_24__free"].push(pack->inverter_l_rcv(i).cmc__bit31_24__free());
		(*net_signals)["INVERTER_L_RCV"]["dc_1qdirvolt"].push(pack->inverter_l_rcv(i).dc_1qdirvolt());
		(*net_signals)["INVERTER_L_RCV"]["_10hz64"].push(pack->inverter_l_rcv(i)._10hz64());
		(*net_signals)["INVERTER_L_RCV"]["warn_ipeak"].push(pack->inverter_l_rcv(i).warn_ipeak());
		(*net_signals)["INVERTER_L_RCV"]["_10hz82"].push(pack->inverter_l_rcv(i)._10hz82());
		(*net_signals)["INVERTER_L_RCV"]["dc_field"].push(pack->inverter_l_rcv(i).dc_field());
		(*net_signals)["INVERTER_L_RCV"]["irdtm64"].push(pack->inverter_l_rcv(i).irdtm64());
		(*net_signals)["INVERTER_L_RCV"]["warn_raceaway"].push(pack->inverter_l_rcv(i).warn_raceaway());
		(*net_signals)["INVERTER_L_RCV"]["irdtm82"].push(pack->inverter_l_rcv(i).irdtm82());
		(*net_signals)["INVERTER_L_RCV"]["dead_2"].push(pack->inverter_l_rcv(i).dead_2());
		(*net_signals)["INVERTER_L_RCV"]["irdana64"].push(pack->inverter_l_rcv(i).irdana64());
		(*net_signals)["INVERTER_L_RCV"]["irdana82"].push(pack->inverter_l_rcv(i).irdana82());
		(*net_signals)["INVERTER_L_RCV"]["block"].push(pack->inverter_l_rcv(i).block());
		(*net_signals)["INVERTER_L_RCV"]["iwcns64"].push(pack->inverter_l_rcv(i).iwcns64());
		(*net_signals)["INVERTER_L_RCV"]["iwcns82"].push(pack->inverter_l_rcv(i).iwcns82());
		(*net_signals)["INVERTER_L_RCV"]["dc_1qmv"].push(pack->inverter_l_rcv(i).dc_1qmv());
		(*net_signals)["INVERTER_L_RCV"]["rfepulse64"].push(pack->inverter_l_rcv(i).rfepulse64());
		(*net_signals)["INVERTER_L_RCV"]["rfepulse82"].push(pack->inverter_l_rcv(i).rfepulse82());
		(*net_signals)["INVERTER_L_RCV"]["dc_1q3p"].push(pack->inverter_l_rcv(i).dc_1q3p());
		(*net_signals)["INVERTER_L_RCV"]["md64"].push(pack->inverter_l_rcv(i).md64());
		(*net_signals)["INVERTER_L_RCV"]["md82"].push(pack->inverter_l_rcv(i).md82());
		(*net_signals)["INVERTER_L_RCV"]["reducelosses"].push(pack->inverter_l_rcv(i).reducelosses());
		(*net_signals)["INVERTER_L_RCV"]["hndwhl64"].push(pack->inverter_l_rcv(i).hndwhl64());
		(*net_signals)["INVERTER_L_RCV"]["warn_ballast"].push(pack->inverter_l_rcv(i).warn_ballast());
		(*net_signals)["INVERTER_L_RCV"]["hndwhl82"].push(pack->inverter_l_rcv(i).hndwhl82());

    }

    for(int i = 0; i < pack->inverter_r_send_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->inverter_r_send(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->inverter_r_send(i)._inner_timestamp();
        (*net_signals)["INVERTER_R_SEND"]["_timestamp"].push(pack->inverter_r_send(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["INVERTER_R_SEND"]["send_mux"].push(pack->inverter_r_send(i).send_mux());
		(*net_signals)["INVERTER_R_SEND"]["motor_f_n"].push(pack->inverter_r_send(i).motor_f_n());
		(*net_signals)["INVERTER_R_SEND"]["t_dc__start"].push(pack->inverter_r_send(i).t_dc__start());
		(*net_signals)["INVERTER_R_SEND"]["v_dc__start"].push(pack->inverter_r_send(i).v_dc__start());
		(*net_signals)["INVERTER_R_SEND"]["special__start"].push(pack->inverter_r_send(i).special__start());
		(*net_signals)["INVERTER_R_SEND"]["v_min__start"].push(pack->inverter_r_send(i).v_min__start());
		(*net_signals)["INVERTER_R_SEND"]["f_min__start"].push(pack->inverter_r_send(i).f_min__start());
		(*net_signals)["INVERTER_R_SEND"]["v_corner__start"].push(pack->inverter_r_send(i).v_corner__start());
		(*net_signals)["INVERTER_R_SEND"]["f_corner__start"].push(pack->inverter_r_send(i).f_corner__start());
		(*net_signals)["INVERTER_R_SEND"]["cos_phi"].push(pack->inverter_r_send(i).cos_phi());
		(*net_signals)["INVERTER_R_SEND"]["extra__start"].push(pack->inverter_r_send(i).extra__start());
		(*net_signals)["INVERTER_R_SEND"]["capture_channel"].push(pack->inverter_r_send(i).capture_channel());
		(*net_signals)["INVERTER_R_SEND"]["trig_level"].push(pack->inverter_r_send(i).trig_level());
		(*net_signals)["INVERTER_R_SEND"]["trig_edge"].push(pack->inverter_r_send(i).trig_edge());
		(*net_signals)["INVERTER_R_SEND"]["trig_source"].push(pack->inverter_r_send(i).trig_source());
		(*net_signals)["INVERTER_R_SEND"]["oszi_source"].push(pack->inverter_r_send(i).oszi_source());
		(*net_signals)["INVERTER_R_SEND"]["oszi_skip"].push(pack->inverter_r_send(i).oszi_skip());
		(*net_signals)["INVERTER_R_SEND"]["oszi_read_cmd"].push(pack->inverter_r_send(i).oszi_read_cmd());
		(*net_signals)["INVERTER_R_SEND"]["oszi_run_cmd"].push(pack->inverter_r_send(i).oszi_run_cmd());
		(*net_signals)["INVERTER_R_SEND"]["calib_ref_value"].push(pack->inverter_r_send(i).calib_ref_value());
		(*net_signals)["INVERTER_R_SEND"]["pid_i__kp__iq"].push(pack->inverter_r_send(i).pid_i__kp__iq());
		(*net_signals)["INVERTER_R_SEND"]["pid_i__ti__iq"].push(pack->inverter_r_send(i).pid_i__ti__iq());
		(*net_signals)["INVERTER_R_SEND"]["cutoffdig"].push(pack->inverter_r_send(i).cutoffdig());
		(*net_signals)["INVERTER_R_SEND"]["id_setdig__id"].push(pack->inverter_r_send(i).id_setdig__id());
		(*net_signals)["INVERTER_R_SEND"]["i_delta_ramp"].push(pack->inverter_r_send(i).i_delta_ramp());
		(*net_signals)["INVERTER_R_SEND"]["pid_i__tim__iq"].push(pack->inverter_r_send(i).pid_i__tim__iq());
		(*net_signals)["INVERTER_R_SEND"]["pid_n__kp"].push(pack->inverter_r_send(i).pid_n__kp());
		(*net_signals)["INVERTER_R_SEND"]["pid_n__ti"].push(pack->inverter_r_send(i).pid_n__ti());
		(*net_signals)["INVERTER_R_SEND"]["pid_n__td"].push(pack->inverter_r_send(i).pid_n__td());
		(*net_signals)["INVERTER_R_SEND"]["ain_in_1_offsetval"].push(pack->inverter_r_send(i).ain_in_1_offsetval());
		(*net_signals)["INVERTER_R_SEND"]["n_setdig"].push(pack->inverter_r_send(i).n_setdig());
		(*net_signals)["INVERTER_R_SEND"]["n_lim"].push(pack->inverter_r_send(i).n_lim());
		(*net_signals)["INVERTER_R_SEND"]["n_r_acc"].push(pack->inverter_r_send(i).n_r_acc());
		(*net_signals)["INVERTER_R_SEND"]["cs_ain_1_format"].push(pack->inverter_r_send(i).cs_ain_1_format());
		(*net_signals)["INVERTER_R_SEND"]["pid_n__tim"].push(pack->inverter_r_send(i).pid_n__tim());
		(*net_signals)["INVERTER_R_SEND"]["i_red_n"].push(pack->inverter_r_send(i).i_red_n());
		(*net_signals)["INVERTER_R_SEND"]["n_lim_minus"].push(pack->inverter_r_send(i).n_lim_minus());
		(*net_signals)["INVERTER_R_SEND"]["n_lim_plus"].push(pack->inverter_r_send(i).n_lim_plus());
		(*net_signals)["INVERTER_R_SEND"]["fb_offset"].push(pack->inverter_r_send(i).fb_offset());
		(*net_signals)["INVERTER_R_SEND"]["read_id"].push(pack->inverter_r_send(i).read_id());
		(*net_signals)["INVERTER_R_SEND"]["i_lim_dig"].push(pack->inverter_r_send(i).i_lim_dig());
		(*net_signals)["INVERTER_R_SEND"]["i_red_te"].push(pack->inverter_r_send(i).i_red_te());
		(*net_signals)["INVERTER_R_SEND"]["i_max_eff"].push(pack->inverter_r_send(i).i_max_eff());
		(*net_signals)["INVERTER_R_SEND"]["i_nom_eff"].push(pack->inverter_r_send(i).i_nom_eff());
		(*net_signals)["INVERTER_R_SEND"]["motor_pole"].push(pack->inverter_r_send(i).motor_pole());
		(*net_signals)["INVERTER_R_SEND"]["ain_in_1_cutoff"].push(pack->inverter_r_send(i).ain_in_1_cutoff());
		(*net_signals)["INVERTER_R_SEND"]["km_rsvd_0"].push(pack->inverter_r_send(i).km_rsvd_0());
		(*net_signals)["INVERTER_R_SEND"]["ain_in_2_cutoff"].push(pack->inverter_r_send(i).ain_in_2_cutoff());
		(*net_signals)["INVERTER_R_SEND"]["i_red_td"].push(pack->inverter_r_send(i).i_red_td());
		(*net_signals)["INVERTER_R_SEND"]["n_nom"].push(pack->inverter_r_send(i).n_nom());
		(*net_signals)["INVERTER_R_SEND"]["dc_bus_comp"].push(pack->inverter_r_send(i).dc_bus_comp());
		(*net_signals)["INVERTER_R_SEND"]["pid_n__kacc"].push(pack->inverter_r_send(i).pid_n__kacc());
		(*net_signals)["INVERTER_R_SEND"]["speed_filter"].push(pack->inverter_r_send(i).speed_filter());
		(*net_signals)["INVERTER_R_SEND"]["ain_in_1_filter"].push(pack->inverter_r_send(i).ain_in_1_filter());
		(*net_signals)["INVERTER_R_SEND"]["snr"].push(pack->inverter_r_send(i).snr());
		(*net_signals)["INVERTER_R_SEND"]["device_mains"].push(pack->inverter_r_send(i).device_mains());
		(*net_signals)["INVERTER_R_SEND"]["regen_p"].push(pack->inverter_r_send(i).regen_p());
		(*net_signals)["INVERTER_R_SEND"]["devicetype"].push(pack->inverter_r_send(i).devicetype());
		(*net_signals)["INVERTER_R_SEND"]["can_id_rx"].push(pack->inverter_r_send(i).can_id_rx());
		(*net_signals)["INVERTER_R_SEND"]["can_id_tx"].push(pack->inverter_r_send(i).can_id_tx());
		(*net_signals)["INVERTER_R_SEND"]["pos_kp"].push(pack->inverter_r_send(i).pos_kp());
		(*net_signals)["INVERTER_R_SEND"]["pos_ti"].push(pack->inverter_r_send(i).pos_ti());
		(*net_signals)["INVERTER_R_SEND"]["pos_td"].push(pack->inverter_r_send(i).pos_td());
		(*net_signals)["INVERTER_R_SEND"]["pos_dest"].push(pack->inverter_r_send(i).pos_dest());
		(*net_signals)["INVERTER_R_SEND"]["pos_tim"].push(pack->inverter_r_send(i).pos_tim());
		(*net_signals)["INVERTER_R_SEND"]["pos_offsref"].push(pack->inverter_r_send(i).pos_offsref());
		(*net_signals)["INVERTER_R_SEND"]["can_nbt"].push(pack->inverter_r_send(i).can_nbt());
		(*net_signals)["INVERTER_R_SEND"]["ref_reso_edge"].push(pack->inverter_r_send(i).ref_reso_edge());
		(*net_signals)["INVERTER_R_SEND"]["speed_1"].push(pack->inverter_r_send(i).speed_1());
		(*net_signals)["INVERTER_R_SEND"]["speed_2"].push(pack->inverter_r_send(i).speed_2());
		(*net_signals)["INVERTER_R_SEND"]["pos_tol_win"].push(pack->inverter_r_send(i).pos_tol_win());
		(*net_signals)["INVERTER_R_SEND"]["pos_preset_val"].push(pack->inverter_r_send(i).pos_preset_val());
		(*net_signals)["INVERTER_R_SEND"]["pos_nd_scale"].push(pack->inverter_r_send(i).pos_nd_scale());
		(*net_signals)["INVERTER_R_SEND"]["pos_nd_offset"].push(pack->inverter_r_send(i).pos_nd_offset());
		(*net_signals)["INVERTER_R_SEND"]["fb2_scale_ext"].push(pack->inverter_r_send(i).fb2_scale_ext());
		(*net_signals)["INVERTER_R_SEND"]["pos_offset_slack"].push(pack->inverter_r_send(i).pos_offset_slack());
		(*net_signals)["INVERTER_R_SEND"]["pos_diff_slack"].push(pack->inverter_r_send(i).pos_diff_slack());
		(*net_signals)["INVERTER_R_SEND"]["eprom131"].push(pack->inverter_r_send(i).eprom131());
		(*net_signals)["INVERTER_R_SEND"]["eprom132"].push(pack->inverter_r_send(i).eprom132());
		(*net_signals)["INVERTER_R_SEND"]["fun_special"].push(pack->inverter_r_send(i).fun_special());
		(*net_signals)["INVERTER_R_SEND"]["can_id_2_rx"].push(pack->inverter_r_send(i).can_id_2_rx());
		(*net_signals)["INVERTER_R_SEND"]["can_id_2_tx"].push(pack->inverter_r_send(i).can_id_2_tx());
		(*net_signals)["INVERTER_R_SEND"]["v_ref"].push(pack->inverter_r_send(i).v_ref());
		(*net_signals)["INVERTER_R_SEND"]["v_kp"].push(pack->inverter_r_send(i).v_kp());
		(*net_signals)["INVERTER_R_SEND"]["v_ti"].push(pack->inverter_r_send(i).v_ti());
		(*net_signals)["INVERTER_R_SEND"]["clear_errors"].push(pack->inverter_r_send(i).clear_errors());
		(*net_signals)["INVERTER_R_SEND"]["m_setdig__iq"].push(pack->inverter_r_send(i).m_setdig__iq());
		(*net_signals)["INVERTER_R_SEND"]["i_red_tm"].push(pack->inverter_r_send(i).i_red_tm());
		(*net_signals)["INVERTER_R_SEND"]["m_temp"].push(pack->inverter_r_send(i).m_temp());
		(*net_signals)["INVERTER_R_SEND"]["mo_feedback_1"].push(pack->inverter_r_send(i).mo_feedback_1());
		(*net_signals)["INVERTER_R_SEND"]["dc_bus_min_lim"].push(pack->inverter_r_send(i).dc_bus_min_lim());
		(*net_signals)["INVERTER_R_SEND"]["fb_incr_mot"].push(pack->inverter_r_send(i).fb_incr_mot());
		(*net_signals)["INVERTER_R_SEND"]["fb_pole"].push(pack->inverter_r_send(i).fb_pole());
		(*net_signals)["INVERTER_R_SEND"]["motor_lsq"].push(pack->inverter_r_send(i).motor_lsq());
		(*net_signals)["INVERTER_R_SEND"]["id_nom"].push(pack->inverter_r_send(i).id_nom());
		(*net_signals)["INVERTER_R_SEND"]["motor_lm"].push(pack->inverter_r_send(i).motor_lm());
		(*net_signals)["INVERTER_R_SEND"]["motor_rr"].push(pack->inverter_r_send(i).motor_rr());
		(*net_signals)["INVERTER_R_SEND"]["id_min"].push(pack->inverter_r_send(i).id_min());
		(*net_signals)["INVERTER_R_SEND"]["motor_tr"].push(pack->inverter_r_send(i).motor_tr());
		(*net_signals)["INVERTER_R_SEND"]["motor_lsd"].push(pack->inverter_r_send(i).motor_lsd());
		(*net_signals)["INVERTER_R_SEND"]["motor_rs"].push(pack->inverter_r_send(i).motor_rs());
		(*net_signals)["INVERTER_R_SEND"]["motor_ts"].push(pack->inverter_r_send(i).motor_ts());
		(*net_signals)["INVERTER_R_SEND"]["def_end_1"].push(pack->inverter_r_send(i).def_end_1());
		(*net_signals)["INVERTER_R_SEND"]["def_end_2"].push(pack->inverter_r_send(i).def_end_2());
		(*net_signals)["INVERTER_R_SEND"]["def_din_1"].push(pack->inverter_r_send(i).def_din_1());
		(*net_signals)["INVERTER_R_SEND"]["def_din_2"].push(pack->inverter_r_send(i).def_din_2());
		(*net_signals)["INVERTER_R_SEND"]["operand194"].push(pack->inverter_r_send(i).operand194());
		(*net_signals)["INVERTER_R_SEND"]["operand195"].push(pack->inverter_r_send(i).operand195());
		(*net_signals)["INVERTER_R_SEND"]["operand218"].push(pack->inverter_r_send(i).operand218());
		(*net_signals)["INVERTER_R_SEND"]["operand219"].push(pack->inverter_r_send(i).operand219());
		(*net_signals)["INVERTER_R_SEND"]["i_max_pk"].push(pack->inverter_r_send(i).i_max_pk());
		(*net_signals)["INVERTER_R_SEND"]["i_con_eff"].push(pack->inverter_r_send(i).i_con_eff());
		(*net_signals)["INVERTER_R_SEND"]["i_device"].push(pack->inverter_r_send(i).i_device());
		(*net_signals)["INVERTER_R_SEND"]["n_r_lim"].push(pack->inverter_r_send(i).n_r_lim());
		(*net_signals)["INVERTER_R_SEND"]["nmax100perc"].push(pack->inverter_r_send(i).nmax100perc());
		(*net_signals)["INVERTER_R_SEND"]["pid_i__xkp__iq"].push(pack->inverter_r_send(i).pid_i__xkp__iq());
		(*net_signals)["INVERTER_R_SEND"]["bat_opr_limit__mot"].push(pack->inverter_r_send(i).bat_opr_limit__mot());
		(*net_signals)["INVERTER_R_SEND"]["pid_i__kf__iq"].push(pack->inverter_r_send(i).pid_i__kf__iq());
		(*net_signals)["INVERTER_R_SEND"]["cmc__bit0__dc_current_sens_ena"].push(pack->inverter_r_send(i).cmc__bit0__dc_current_sens_ena());
		(*net_signals)["INVERTER_R_SEND"]["can_rxtimeout"].push(pack->inverter_r_send(i).can_rxtimeout());
		(*net_signals)["INVERTER_R_SEND"]["var_1"].push(pack->inverter_r_send(i).var_1());
		(*net_signals)["INVERTER_R_SEND"]["var_2"].push(pack->inverter_r_send(i).var_2());
		(*net_signals)["INVERTER_R_SEND"]["var_3"].push(pack->inverter_r_send(i).var_3());
		(*net_signals)["INVERTER_R_SEND"]["var_4"].push(pack->inverter_r_send(i).var_4());
		(*net_signals)["INVERTER_R_SEND"]["ain_in_2_offsetval"].push(pack->inverter_r_send(i).ain_in_2_offsetval());
		(*net_signals)["INVERTER_R_SEND"]["dup__bit7_0__dac_source_channel"].push(pack->inverter_r_send(i).dup__bit7_0__dac_source_channel());
		(*net_signals)["INVERTER_R_SEND"]["n_r_dec"].push(pack->inverter_r_send(i).n_r_dec());
		(*net_signals)["INVERTER_R_SEND"]["v_shunt"].push(pack->inverter_r_send(i).v_shunt());
		(*net_signals)["INVERTER_R_SEND"]["t_peak"].push(pack->inverter_r_send(i).t_peak());
		(*net_signals)["INVERTER_R_SEND"]["brake_delay"].push(pack->inverter_r_send(i).brake_delay());
		(*net_signals)["INVERTER_R_SEND"]["axis"].push(pack->inverter_r_send(i).axis());
		(*net_signals)["INVERTER_R_SEND"]["km_speed_0"].push(pack->inverter_r_send(i).km_speed_0());
		(*net_signals)["INVERTER_R_SEND"]["ballast_ext"].push(pack->inverter_r_send(i).ballast_ext());
		(*net_signals)["INVERTER_R_SEND"]["cmc__bit1__idc_limit_ena"].push(pack->inverter_r_send(i).cmc__bit1__idc_limit_ena());
		(*net_signals)["INVERTER_R_SEND"]["cs_ain_2_format"].push(pack->inverter_r_send(i).cs_ain_2_format());
		(*net_signals)["INVERTER_R_SEND"]["km_frg_off"].push(pack->inverter_r_send(i).km_frg_off());
		(*net_signals)["INVERTER_R_SEND"]["fb_special"].push(pack->inverter_r_send(i).fb_special());
		(*net_signals)["INVERTER_R_SEND"]["cmc__bit2__pdc_limit_usage"].push(pack->inverter_r_send(i).cmc__bit2__pdc_limit_usage());
		(*net_signals)["INVERTER_R_SEND"]["km_cal_off"].push(pack->inverter_r_send(i).km_cal_off());
		(*net_signals)["INVERTER_R_SEND"]["coaststop"].push(pack->inverter_r_send(i).coaststop());
		(*net_signals)["INVERTER_R_SEND"]["cmc__bit3__torqueval_init_ena"].push(pack->inverter_r_send(i).cmc__bit3__torqueval_init_ena());
		(*net_signals)["INVERTER_R_SEND"]["cs_ain_1_mode"].push(pack->inverter_r_send(i).cs_ain_1_mode());
		(*net_signals)["INVERTER_R_SEND"]["km_tx_tog_stat"].push(pack->inverter_r_send(i).km_tx_tog_stat());
		(*net_signals)["INVERTER_R_SEND"]["i_ist_inverse"].push(pack->inverter_r_send(i).i_ist_inverse());
		(*net_signals)["INVERTER_R_SEND"]["compare_var194"].push(pack->inverter_r_send(i).compare_var194());
		(*net_signals)["INVERTER_R_SEND"]["compare_var195"].push(pack->inverter_r_send(i).compare_var195());
		(*net_signals)["INVERTER_R_SEND"]["compare_var218"].push(pack->inverter_r_send(i).compare_var218());
		(*net_signals)["INVERTER_R_SEND"]["compare_var219"].push(pack->inverter_r_send(i).compare_var219());
		(*net_signals)["INVERTER_R_SEND"]["cmc__bit4__dig_m_rcpramp_ena"].push(pack->inverter_r_send(i).cmc__bit4__dig_m_rcpramp_ena());
		(*net_signals)["INVERTER_R_SEND"]["km_i_limit"].push(pack->inverter_r_send(i).km_i_limit());
		(*net_signals)["INVERTER_R_SEND"]["refsoft"].push(pack->inverter_r_send(i).refsoft());
		(*net_signals)["INVERTER_R_SEND"]["mo_feedback_2"].push(pack->inverter_r_send(i).mo_feedback_2());
		(*net_signals)["INVERTER_R_SEND"]["cmc__bit5__reset_nramp_atnzero"].push(pack->inverter_r_send(i).cmc__bit5__reset_nramp_atnzero());
		(*net_signals)["INVERTER_R_SEND"]["km_n_clip"].push(pack->inverter_r_send(i).km_n_clip());
		(*net_signals)["INVERTER_R_SEND"]["no_uesp_btb"].push(pack->inverter_r_send(i).no_uesp_btb());
		(*net_signals)["INVERTER_R_SEND"]["cmc__bit6__torquetimeout_100ms_e"].push(pack->inverter_r_send(i).cmc__bit6__torquetimeout_100ms_e());
		(*net_signals)["INVERTER_R_SEND"]["cs_oora1"].push(pack->inverter_r_send(i).cs_oora1());
		(*net_signals)["INVERTER_R_SEND"]["km_mix_ana_on"].push(pack->inverter_r_send(i).km_mix_ana_on());
		(*net_signals)["INVERTER_R_SEND"]["vdc_ana"].push(pack->inverter_r_send(i).vdc_ana());
		(*net_signals)["INVERTER_R_SEND"]["cmc__bit13_7__free"].push(pack->inverter_r_send(i).cmc__bit13_7__free());
		(*net_signals)["INVERTER_R_SEND"]["cs_ain_2_mode"].push(pack->inverter_r_send(i).cs_ain_2_mode());
		(*net_signals)["INVERTER_R_SEND"]["ret_interval"].push(pack->inverter_r_send(i).ret_interval());
		(*net_signals)["INVERTER_R_SEND"]["km_allow_sync"].push(pack->inverter_r_send(i).km_allow_sync());
		(*net_signals)["INVERTER_R_SEND"]["i1_adc_ena"].push(pack->inverter_r_send(i).i1_adc_ena());
		(*net_signals)["INVERTER_R_SEND"]["ain_in_2_filter"].push(pack->inverter_r_send(i).ain_in_2_filter());
		(*net_signals)["INVERTER_R_SEND"]["mo_sc1_reso"].push(pack->inverter_r_send(i).mo_sc1_reso());
		(*net_signals)["INVERTER_R_SEND"]["source_id194"].push(pack->inverter_r_send(i).source_id194());
		(*net_signals)["INVERTER_R_SEND"]["source_id195"].push(pack->inverter_r_send(i).source_id195());
		(*net_signals)["INVERTER_R_SEND"]["source_id218"].push(pack->inverter_r_send(i).source_id218());
		(*net_signals)["INVERTER_R_SEND"]["source_id219"].push(pack->inverter_r_send(i).source_id219());
		(*net_signals)["INVERTER_R_SEND"]["dup__bit8__can_extended_0"].push(pack->inverter_r_send(i).dup__bit8__can_extended_0());
		(*net_signals)["INVERTER_R_SEND"]["km_handwheel"].push(pack->inverter_r_send(i).km_handwheel());
		(*net_signals)["INVERTER_R_SEND"]["hxinv"].push(pack->inverter_r_send(i).hxinv());
		(*net_signals)["INVERTER_R_SEND"]["dup__bit9__generator"].push(pack->inverter_r_send(i).dup__bit9__generator());
		(*net_signals)["INVERTER_R_SEND"]["km_phasing_extend"].push(pack->inverter_r_send(i).km_phasing_extend());
		(*net_signals)["INVERTER_R_SEND"]["h2inv"].push(pack->inverter_r_send(i).h2inv());
		(*net_signals)["INVERTER_R_SEND"]["dup__bit10__park_rms"].push(pack->inverter_r_send(i).dup__bit10__park_rms());
		(*net_signals)["INVERTER_R_SEND"]["cs_oora2"].push(pack->inverter_r_send(i).cs_oora2());
		(*net_signals)["INVERTER_R_SEND"]["km_rsvd_11"].push(pack->inverter_r_send(i).km_rsvd_11());
		(*net_signals)["INVERTER_R_SEND"]["ol_comp"].push(pack->inverter_r_send(i).ol_comp());
		(*net_signals)["INVERTER_R_SEND"]["mo_sc1_comp"].push(pack->inverter_r_send(i).mo_sc1_comp());
		(*net_signals)["INVERTER_R_SEND"]["dup__bit11__dcbus_volts"].push(pack->inverter_r_send(i).dup__bit11__dcbus_volts());
		(*net_signals)["INVERTER_R_SEND"]["cs_cmd_type"].push(pack->inverter_r_send(i).cs_cmd_type());
		(*net_signals)["INVERTER_R_SEND"]["km_rsvd_12"].push(pack->inverter_r_send(i).km_rsvd_12());
		(*net_signals)["INVERTER_R_SEND"]["motortype"].push(pack->inverter_r_send(i).motortype());
		(*net_signals)["INVERTER_R_SEND"]["mo_sc2_reso"].push(pack->inverter_r_send(i).mo_sc2_reso());
		(*net_signals)["INVERTER_R_SEND"]["dup__bit12__boat_pedal"].push(pack->inverter_r_send(i).dup__bit12__boat_pedal());
		(*net_signals)["INVERTER_R_SEND"]["km_rsvd_13"].push(pack->inverter_r_send(i).km_rsvd_13());
		(*net_signals)["INVERTER_R_SEND"]["dup__bit13__gen_autoiaclimit"].push(pack->inverter_r_send(i).dup__bit13__gen_autoiaclimit());
		(*net_signals)["INVERTER_R_SEND"]["cs_ain_2__i_limit"].push(pack->inverter_r_send(i).cs_ain_2__i_limit());
		(*net_signals)["INVERTER_R_SEND"]["km_pseudo_enable"].push(pack->inverter_r_send(i).km_pseudo_enable());
		(*net_signals)["INVERTER_R_SEND"]["ana_0up"].push(pack->inverter_r_send(i).ana_0up());
		(*net_signals)["INVERTER_R_SEND"]["cmc__bit14__idc_limit_ena_v2"].push(pack->inverter_r_send(i).cmc__bit14__idc_limit_ena_v2());
		(*net_signals)["INVERTER_R_SEND"]["dup__bit14__mtpa_reluct_enab"].push(pack->inverter_r_send(i).dup__bit14__mtpa_reluct_enab());
		(*net_signals)["INVERTER_R_SEND"]["cs_ain_1__n_limit"].push(pack->inverter_r_send(i).cs_ain_1__n_limit());
		(*net_signals)["INVERTER_R_SEND"]["km_debug_test"].push(pack->inverter_r_send(i).km_debug_test());
		(*net_signals)["INVERTER_R_SEND"]["lowbd"].push(pack->inverter_r_send(i).lowbd());
		(*net_signals)["INVERTER_R_SEND"]["mo_sc2_inv"].push(pack->inverter_r_send(i).mo_sc2_inv());
		(*net_signals)["INVERTER_R_SEND"]["active190"].push(pack->inverter_r_send(i).active190());
		(*net_signals)["INVERTER_R_SEND"]["active191"].push(pack->inverter_r_send(i).active191());
		(*net_signals)["INVERTER_R_SEND"]["active192"].push(pack->inverter_r_send(i).active192());
		(*net_signals)["INVERTER_R_SEND"]["active193"].push(pack->inverter_r_send(i).active193());
		(*net_signals)["INVERTER_R_SEND"]["cmc__bit15__dig_e_brake_act"].push(pack->inverter_r_send(i).cmc__bit15__dig_e_brake_act());
		(*net_signals)["INVERTER_R_SEND"]["dup__bit15__canopen_acv"].push(pack->inverter_r_send(i).dup__bit15__canopen_acv());
		(*net_signals)["INVERTER_R_SEND"]["t_dc__stop"].push(pack->inverter_r_send(i).t_dc__stop());
		(*net_signals)["INVERTER_R_SEND"]["v_dc__stop"].push(pack->inverter_r_send(i).v_dc__stop());
		(*net_signals)["INVERTER_R_SEND"]["special__stop"].push(pack->inverter_r_send(i).special__stop());
		(*net_signals)["INVERTER_R_SEND"]["v_min__stop"].push(pack->inverter_r_send(i).v_min__stop());
		(*net_signals)["INVERTER_R_SEND"]["f_min__stop"].push(pack->inverter_r_send(i).f_min__stop());
		(*net_signals)["INVERTER_R_SEND"]["v_corner__stop"].push(pack->inverter_r_send(i).v_corner__stop());
		(*net_signals)["INVERTER_R_SEND"]["f_corner__stop"].push(pack->inverter_r_send(i).f_corner__stop());
		(*net_signals)["INVERTER_R_SEND"]["pid_i__kp__id"].push(pack->inverter_r_send(i).pid_i__kp__id());
		(*net_signals)["INVERTER_R_SEND"]["pid_i__ti__id"].push(pack->inverter_r_send(i).pid_i__ti__id());
		(*net_signals)["INVERTER_R_SEND"]["pid_i__tim__id"].push(pack->inverter_r_send(i).pid_i__tim__id());
		(*net_signals)["INVERTER_R_SEND"]["ain_in_1_scaleval"].push(pack->inverter_r_send(i).ain_in_1_scaleval());
		(*net_signals)["INVERTER_R_SEND"]["m_r_acc"].push(pack->inverter_r_send(i).m_r_acc());
		(*net_signals)["INVERTER_R_SEND"]["sramp"].push(pack->inverter_r_send(i).sramp());
		(*net_signals)["INVERTER_R_SEND"]["regen_r"].push(pack->inverter_r_send(i).regen_r());
		(*net_signals)["INVERTER_R_SEND"]["dc_bus_max_lim"].push(pack->inverter_r_send(i).dc_bus_max_lim());
		(*net_signals)["INVERTER_R_SEND"]["m_r_rcp"].push(pack->inverter_r_send(i).m_r_rcp());
		(*net_signals)["INVERTER_R_SEND"]["pid_i__xkp__id"].push(pack->inverter_r_send(i).pid_i__xkp__id());
		(*net_signals)["INVERTER_R_SEND"]["bat_opr_limit__gen"].push(pack->inverter_r_send(i).bat_opr_limit__gen());
		(*net_signals)["INVERTER_R_SEND"]["pid_i__kf__id"].push(pack->inverter_r_send(i).pid_i__kf__id());
		(*net_signals)["INVERTER_R_SEND"]["cmc__bit17_16__checkipeak_config"].push(pack->inverter_r_send(i).cmc__bit17_16__checkipeak_config());
		(*net_signals)["INVERTER_R_SEND"]["ain_in_2_scaleval"].push(pack->inverter_r_send(i).ain_in_2_scaleval());
		(*net_signals)["INVERTER_R_SEND"]["dup__bit16__bamobil3_2_offcrct"].push(pack->inverter_r_send(i).dup__bit16__bamobil3_2_offcrct());
		(*net_signals)["INVERTER_R_SEND"]["m_r_dec"].push(pack->inverter_r_send(i).m_r_dec());
		(*net_signals)["INVERTER_R_SEND"]["ramp4"].push(pack->inverter_r_send(i).ramp4());
		(*net_signals)["INVERTER_R_SEND"]["dup__bit19_17__ecode_redefine"].push(pack->inverter_r_send(i).dup__bit19_17__ecode_redefine());
		(*net_signals)["INVERTER_R_SEND"]["motbrake"].push(pack->inverter_r_send(i).motbrake());
		(*net_signals)["INVERTER_R_SEND"]["cmc__bit18__tractioncontrol_ena"].push(pack->inverter_r_send(i).cmc__bit18__tractioncontrol_ena());
		(*net_signals)["INVERTER_R_SEND"]["ac_dc"].push(pack->inverter_r_send(i).ac_dc());
		(*net_signals)["INVERTER_R_SEND"]["cmc__bit20_19__tc_deltatime_conf"].push(pack->inverter_r_send(i).cmc__bit20_19__tc_deltatime_conf());
		(*net_signals)["INVERTER_R_SEND"]["pwm_freq"].push(pack->inverter_r_send(i).pwm_freq());
		(*net_signals)["INVERTER_R_SEND"]["dup__bit20__hal_extmr_acv"].push(pack->inverter_r_send(i).dup__bit20__hal_extmr_acv());
		(*net_signals)["INVERTER_R_SEND"]["cmc__bit22_21__tc_minspeed_conf"].push(pack->inverter_r_send(i).cmc__bit22_21__tc_minspeed_conf());
		(*net_signals)["INVERTER_R_SEND"]["dup__bit21__initwith_frg_off"].push(pack->inverter_r_send(i).dup__bit21__initwith_frg_off());
		(*net_signals)["INVERTER_R_SEND"]["dup__bit31_22__free"].push(pack->inverter_r_send(i).dup__bit31_22__free());
		(*net_signals)["INVERTER_R_SEND"]["ntc"].push(pack->inverter_r_send(i).ntc());
		(*net_signals)["INVERTER_R_SEND"]["cmc__bit23__tc_ncmdrestoption"].push(pack->inverter_r_send(i).cmc__bit23__tc_ncmdrestoption());
		(*net_signals)["INVERTER_R_SEND"]["delta"].push(pack->inverter_r_send(i).delta());
		(*net_signals)["INVERTER_R_SEND"]["cmc__bit31_24__free"].push(pack->inverter_r_send(i).cmc__bit31_24__free());
		(*net_signals)["INVERTER_R_SEND"]["dc_1qdirvolt"].push(pack->inverter_r_send(i).dc_1qdirvolt());
		(*net_signals)["INVERTER_R_SEND"]["dc_field"].push(pack->inverter_r_send(i).dc_field());
		(*net_signals)["INVERTER_R_SEND"]["dead_2"].push(pack->inverter_r_send(i).dead_2());
		(*net_signals)["INVERTER_R_SEND"]["block"].push(pack->inverter_r_send(i).block());
		(*net_signals)["INVERTER_R_SEND"]["dc_1qmv"].push(pack->inverter_r_send(i).dc_1qmv());
		(*net_signals)["INVERTER_R_SEND"]["dc_1q3p"].push(pack->inverter_r_send(i).dc_1q3p());
		(*net_signals)["INVERTER_R_SEND"]["reducelosses"].push(pack->inverter_r_send(i).reducelosses());

    }

    for(int i = 0; i < pack->inverter_r_rcv_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->inverter_r_rcv(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->inverter_r_rcv(i)._inner_timestamp();
        (*net_signals)["INVERTER_R_RCV"]["_timestamp"].push(pack->inverter_r_rcv(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["INVERTER_R_RCV"]["rcv_mux"].push(pack->inverter_r_rcv(i).rcv_mux());
		(*net_signals)["INVERTER_R_RCV"]["n_actual"].push(pack->inverter_r_rcv(i).n_actual());
		(*net_signals)["INVERTER_R_RCV"]["n_r_dec"].push(pack->inverter_r_rcv(i).n_r_dec());
		(*net_signals)["INVERTER_R_RCV"]["n_r_lim"].push(pack->inverter_r_rcv(i).n_r_lim());
		(*net_signals)["INVERTER_R_RCV"]["n_actual_filt"].push(pack->inverter_r_rcv(i).n_actual_filt());
		(*net_signals)["INVERTER_R_RCV"]["firmware"].push(pack->inverter_r_rcv(i).firmware());
		(*net_signals)["INVERTER_R_RCV"]["devicetype"].push(pack->inverter_r_rcv(i).devicetype());
		(*net_signals)["INVERTER_R_RCV"]["snr"].push(pack->inverter_r_rcv(i).snr());
		(*net_signals)["INVERTER_R_RCV"]["axis"].push(pack->inverter_r_rcv(i).axis());
		(*net_signals)["INVERTER_R_RCV"]["i_device"].push(pack->inverter_r_rcv(i).i_device());
		(*net_signals)["INVERTER_R_RCV"]["v_shunt"].push(pack->inverter_r_rcv(i).v_shunt());
		(*net_signals)["INVERTER_R_RCV"]["i_200perc"].push(pack->inverter_r_rcv(i).i_200perc());
		(*net_signals)["INVERTER_R_RCV"]["dc_bus_comp"].push(pack->inverter_r_rcv(i).dc_bus_comp());
		(*net_signals)["INVERTER_R_RCV"]["ena64"].push(pack->inverter_r_rcv(i).ena64());
		(*net_signals)["INVERTER_R_RCV"]["err_badparas"].push(pack->inverter_r_rcv(i).err_badparas());
		(*net_signals)["INVERTER_R_RCV"]["lmt1"].push(pack->inverter_r_rcv(i).lmt1());
		(*net_signals)["INVERTER_R_RCV"]["ain_in_1_raw"].push(pack->inverter_r_rcv(i).ain_in_1_raw());
		(*net_signals)["INVERTER_R_RCV"]["ain_in_2_raw"].push(pack->inverter_r_rcv(i).ain_in_2_raw());
		(*net_signals)["INVERTER_R_RCV"]["nmax100perc"].push(pack->inverter_r_rcv(i).nmax100perc());
		(*net_signals)["INVERTER_R_RCV"]["n_setdig"].push(pack->inverter_r_rcv(i).n_setdig());
		(*net_signals)["INVERTER_R_RCV"]["n_cmd"].push(pack->inverter_r_rcv(i).n_cmd());
		(*net_signals)["INVERTER_R_RCV"]["n_cmd_ramp"].push(pack->inverter_r_rcv(i).n_cmd_ramp());
		(*net_signals)["INVERTER_R_RCV"]["n_lim"].push(pack->inverter_r_rcv(i).n_lim());
		(*net_signals)["INVERTER_R_RCV"]["n_error"].push(pack->inverter_r_rcv(i).n_error());
		(*net_signals)["INVERTER_R_RCV"]["m_setdig__iq"].push(pack->inverter_r_rcv(i).m_setdig__iq());
		(*net_signals)["INVERTER_R_RCV"]["id_setdig__id"].push(pack->inverter_r_rcv(i).id_setdig__id());
		(*net_signals)["INVERTER_R_RCV"]["i_max_pk"].push(pack->inverter_r_rcv(i).i_max_pk());
		(*net_signals)["INVERTER_R_RCV"]["i_con_eff"].push(pack->inverter_r_rcv(i).i_con_eff());
		(*net_signals)["INVERTER_R_RCV"]["i_max_eff"].push(pack->inverter_r_rcv(i).i_max_eff());
		(*net_signals)["INVERTER_R_RCV"]["i_nom_eff"].push(pack->inverter_r_rcv(i).i_nom_eff());
		(*net_signals)["INVERTER_R_RCV"]["i_limit_inuse"].push(pack->inverter_r_rcv(i).i_limit_inuse());
		(*net_signals)["INVERTER_R_RCV"]["i_cmd"].push(pack->inverter_r_rcv(i).i_cmd());
		(*net_signals)["INVERTER_R_RCV"]["i_cmd_ramp"].push(pack->inverter_r_rcv(i).i_cmd_ramp());
		(*net_signals)["INVERTER_R_RCV"]["i_actual"].push(pack->inverter_r_rcv(i).i_actual());
		(*net_signals)["INVERTER_R_RCV"]["i_actual_filt"].push(pack->inverter_r_rcv(i).i_actual_filt());
		(*net_signals)["INVERTER_R_RCV"]["iq_actual"].push(pack->inverter_r_rcv(i).iq_actual());
		(*net_signals)["INVERTER_R_RCV"]["id_actual"].push(pack->inverter_r_rcv(i).id_actual());
		(*net_signals)["INVERTER_R_RCV"]["iq_error"].push(pack->inverter_r_rcv(i).iq_error());
		(*net_signals)["INVERTER_R_RCV"]["id_error"].push(pack->inverter_r_rcv(i).id_error());
		(*net_signals)["INVERTER_R_RCV"]["i1_actual"].push(pack->inverter_r_rcv(i).i1_actual());
		(*net_signals)["INVERTER_R_RCV"]["i2_actual"].push(pack->inverter_r_rcv(i).i2_actual());
		(*net_signals)["INVERTER_R_RCV"]["i3_actual"].push(pack->inverter_r_rcv(i).i3_actual());
		(*net_signals)["INVERTER_R_RCV"]["i3_adc"].push(pack->inverter_r_rcv(i).i3_adc());
		(*net_signals)["INVERTER_R_RCV"]["i2_adc"].push(pack->inverter_r_rcv(i).i2_adc());
		(*net_signals)["INVERTER_R_RCV"]["vq"].push(pack->inverter_r_rcv(i).vq());
		(*net_signals)["INVERTER_R_RCV"]["vd"].push(pack->inverter_r_rcv(i).vd());
		(*net_signals)["INVERTER_R_RCV"]["vout"].push(pack->inverter_r_rcv(i).vout());
		(*net_signals)["INVERTER_R_RCV"]["t_motor"].push(pack->inverter_r_rcv(i).t_motor());
		(*net_signals)["INVERTER_R_RCV"]["t_igbt"].push(pack->inverter_r_rcv(i).t_igbt());
		(*net_signals)["INVERTER_R_RCV"]["t_air"].push(pack->inverter_r_rcv(i).t_air());
		(*net_signals)["INVERTER_R_RCV"]["vdc_bus_filt"].push(pack->inverter_r_rcv(i).vdc_bus_filt());
		(*net_signals)["INVERTER_R_RCV"]["end_1"].push(pack->inverter_r_rcv(i).end_1());
		(*net_signals)["INVERTER_R_RCV"]["din_1"].push(pack->inverter_r_rcv(i).din_1());
		(*net_signals)["INVERTER_R_RCV"]["end_2"].push(pack->inverter_r_rcv(i).end_2());
		(*net_signals)["INVERTER_R_RCV"]["din_2"].push(pack->inverter_r_rcv(i).din_2());
		(*net_signals)["INVERTER_R_RCV"]["run232"].push(pack->inverter_r_rcv(i).run232());
		(*net_signals)["INVERTER_R_RCV"]["dout_1"].push(pack->inverter_r_rcv(i).dout_1());
		(*net_signals)["INVERTER_R_RCV"]["dout_2"].push(pack->inverter_r_rcv(i).dout_2());
		(*net_signals)["INVERTER_R_RCV"]["dout_3"].push(pack->inverter_r_rcv(i).dout_3());
		(*net_signals)["INVERTER_R_RCV"]["rdy_btb"].push(pack->inverter_r_rcv(i).rdy_btb());
		(*net_signals)["INVERTER_R_RCV"]["i_fault"].push(pack->inverter_r_rcv(i).i_fault());
		(*net_signals)["INVERTER_R_RCV"]["dout_4"].push(pack->inverter_r_rcv(i).dout_4());
		(*net_signals)["INVERTER_R_RCV"]["i_lim_dig"].push(pack->inverter_r_rcv(i).i_lim_dig());
		(*net_signals)["INVERTER_R_RCV"]["i_red_n"].push(pack->inverter_r_rcv(i).i_red_n());
		(*net_signals)["INVERTER_R_RCV"]["i_red_td"].push(pack->inverter_r_rcv(i).i_red_td());
		(*net_signals)["INVERTER_R_RCV"]["i_red_te"].push(pack->inverter_r_rcv(i).i_red_te());
		(*net_signals)["INVERTER_R_RCV"]["i_red_tm"].push(pack->inverter_r_rcv(i).i_red_tm());
		(*net_signals)["INVERTER_R_RCV"]["cs_ain_1_format"].push(pack->inverter_r_rcv(i).cs_ain_1_format());
		(*net_signals)["INVERTER_R_RCV"]["id_ref"].push(pack->inverter_r_rcv(i).id_ref());
		(*net_signals)["INVERTER_R_RCV"]["m_outdig__iq"].push(pack->inverter_r_rcv(i).m_outdig__iq());
		(*net_signals)["INVERTER_R_RCV"]["ptr_1_debug"].push(pack->inverter_r_rcv(i).ptr_1_debug());
		(*net_signals)["INVERTER_R_RCV"]["ptr_2_debug"].push(pack->inverter_r_rcv(i).ptr_2_debug());
		(*net_signals)["INVERTER_R_RCV"]["temp_debug"].push(pack->inverter_r_rcv(i).temp_debug());
		(*net_signals)["INVERTER_R_RCV"]["motor_f_n"].push(pack->inverter_r_rcv(i).motor_f_n());
		(*net_signals)["INVERTER_R_RCV"]["motor_v_n"].push(pack->inverter_r_rcv(i).motor_v_n());
		(*net_signals)["INVERTER_R_RCV"]["t_dc__start"].push(pack->inverter_r_rcv(i).t_dc__start());
		(*net_signals)["INVERTER_R_RCV"]["v_dc__start"].push(pack->inverter_r_rcv(i).v_dc__start());
		(*net_signals)["INVERTER_R_RCV"]["v_min__start"].push(pack->inverter_r_rcv(i).v_min__start());
		(*net_signals)["INVERTER_R_RCV"]["f_min__start"].push(pack->inverter_r_rcv(i).f_min__start());
		(*net_signals)["INVERTER_R_RCV"]["v_corner__start"].push(pack->inverter_r_rcv(i).v_corner__start());
		(*net_signals)["INVERTER_R_RCV"]["f_corner__start"].push(pack->inverter_r_rcv(i).f_corner__start());
		(*net_signals)["INVERTER_R_RCV"]["cos_phi"].push(pack->inverter_r_rcv(i).cos_phi());
		(*net_signals)["INVERTER_R_RCV"]["pwm_enum"].push(pack->inverter_r_rcv(i).pwm_enum());
		(*net_signals)["INVERTER_R_RCV"]["calib_ref_value"].push(pack->inverter_r_rcv(i).calib_ref_value());
		(*net_signals)["INVERTER_R_RCV"]["pid_i__kp__iq"].push(pack->inverter_r_rcv(i).pid_i__kp__iq());
		(*net_signals)["INVERTER_R_RCV"]["pid_i__ti__iq"].push(pack->inverter_r_rcv(i).pid_i__ti__iq());
		(*net_signals)["INVERTER_R_RCV"]["cutoffdig"].push(pack->inverter_r_rcv(i).cutoffdig());
		(*net_signals)["INVERTER_R_RCV"]["i3_offset"].push(pack->inverter_r_rcv(i).i3_offset());
		(*net_signals)["INVERTER_R_RCV"]["i_delta_ramp"].push(pack->inverter_r_rcv(i).i_delta_ramp());
		(*net_signals)["INVERTER_R_RCV"]["pid_i__tim__iq"].push(pack->inverter_r_rcv(i).pid_i__tim__iq());
		(*net_signals)["INVERTER_R_RCV"]["pid_n__kp"].push(pack->inverter_r_rcv(i).pid_n__kp());
		(*net_signals)["INVERTER_R_RCV"]["v_ti"].push(pack->inverter_r_rcv(i).v_ti());
		(*net_signals)["INVERTER_R_RCV"]["pid_n__td"].push(pack->inverter_r_rcv(i).pid_n__td());
		(*net_signals)["INVERTER_R_RCV"]["ain_in_1_offsetval"].push(pack->inverter_r_rcv(i).ain_in_1_offsetval());
		(*net_signals)["INVERTER_R_RCV"]["ain_in_2_offsetval"].push(pack->inverter_r_rcv(i).ain_in_2_offsetval());
		(*net_signals)["INVERTER_R_RCV"]["dzr_seq"].push(pack->inverter_r_rcv(i).dzr_seq());
		(*net_signals)["INVERTER_R_RCV"]["pid_n__tim"].push(pack->inverter_r_rcv(i).pid_n__tim());
		(*net_signals)["INVERTER_R_RCV"]["n_lim_plus"].push(pack->inverter_r_rcv(i).n_lim_plus());
		(*net_signals)["INVERTER_R_RCV"]["n_lim_minus"].push(pack->inverter_r_rcv(i).n_lim_minus());
		(*net_signals)["INVERTER_R_RCV"]["incr_delta"].push(pack->inverter_r_rcv(i).incr_delta());
		(*net_signals)["INVERTER_R_RCV"]["motorpos_mech"].push(pack->inverter_r_rcv(i).motorpos_mech());
		(*net_signals)["INVERTER_R_RCV"]["motorpos_elec"].push(pack->inverter_r_rcv(i).motorpos_elec());
		(*net_signals)["INVERTER_R_RCV"]["fb_offset"].push(pack->inverter_r_rcv(i).fb_offset());
		(*net_signals)["INVERTER_R_RCV"]["it_rg_monitor"].push(pack->inverter_r_rcv(i).it_rg_monitor());
		(*net_signals)["INVERTER_R_RCV"]["motor_pole"].push(pack->inverter_r_rcv(i).motor_pole());
		(*net_signals)["INVERTER_R_RCV"]["ain_in_1_cutoff"].push(pack->inverter_r_rcv(i).ain_in_1_cutoff());
		(*net_signals)["INVERTER_R_RCV"]["activecontrolmode"].push(pack->inverter_r_rcv(i).activecontrolmode());
		(*net_signals)["INVERTER_R_RCV"]["km_rsvd_0"].push(pack->inverter_r_rcv(i).km_rsvd_0());
		(*net_signals)["INVERTER_R_RCV"]["ena82"].push(pack->inverter_r_rcv(i).ena82());
		(*net_signals)["INVERTER_R_RCV"]["ain_in_2_cutoff"].push(pack->inverter_r_rcv(i).ain_in_2_cutoff());
		(*net_signals)["INVERTER_R_RCV"]["i_limit_inuse_ramp"].push(pack->inverter_r_rcv(i).i_limit_inuse_ramp());
		(*net_signals)["INVERTER_R_RCV"]["n_nom"].push(pack->inverter_r_rcv(i).n_nom());
		(*net_signals)["INVERTER_R_RCV"]["pid_n__kacc"].push(pack->inverter_r_rcv(i).pid_n__kacc());
		(*net_signals)["INVERTER_R_RCV"]["rotor_signals"].push(pack->inverter_r_rcv(i).rotor_signals());
		(*net_signals)["INVERTER_R_RCV"]["speed_filter"].push(pack->inverter_r_rcv(i).speed_filter());
		(*net_signals)["INVERTER_R_RCV"]["ain_in_1_filter"].push(pack->inverter_r_rcv(i).ain_in_1_filter());
		(*net_signals)["INVERTER_R_RCV"]["ixt_monitor"].push(pack->inverter_r_rcv(i).ixt_monitor());
		(*net_signals)["INVERTER_R_RCV"]["ecode_bit0_firsterrordtcd99"].push(pack->inverter_r_rcv(i).ecode_bit0_firsterrordtcd99());
		(*net_signals)["INVERTER_R_RCV"]["device_mains"].push(pack->inverter_r_rcv(i).device_mains());
		(*net_signals)["INVERTER_R_RCV"]["regen_p"].push(pack->inverter_r_rcv(i).regen_p());
		(*net_signals)["INVERTER_R_RCV"]["can_id_rx"].push(pack->inverter_r_rcv(i).can_id_rx());
		(*net_signals)["INVERTER_R_RCV"]["can_id_tx"].push(pack->inverter_r_rcv(i).can_id_tx());
		(*net_signals)["INVERTER_R_RCV"]["pos_kp"].push(pack->inverter_r_rcv(i).pos_kp());
		(*net_signals)["INVERTER_R_RCV"]["pos_ti"].push(pack->inverter_r_rcv(i).pos_ti());
		(*net_signals)["INVERTER_R_RCV"]["pos_td"].push(pack->inverter_r_rcv(i).pos_td());
		(*net_signals)["INVERTER_R_RCV"]["pos_actual"].push(pack->inverter_r_rcv(i).pos_actual());
		(*net_signals)["INVERTER_R_RCV"]["pos_dest"].push(pack->inverter_r_rcv(i).pos_dest());
		(*net_signals)["INVERTER_R_RCV"]["pos_actual_2"].push(pack->inverter_r_rcv(i).pos_actual_2());
		(*net_signals)["INVERTER_R_RCV"]["pos_error"].push(pack->inverter_r_rcv(i).pos_error());
		(*net_signals)["INVERTER_R_RCV"]["pos_tim"].push(pack->inverter_r_rcv(i).pos_tim());
		(*net_signals)["INVERTER_R_RCV"]["pos_offsref"].push(pack->inverter_r_rcv(i).pos_offsref());
		(*net_signals)["INVERTER_R_RCV"]["can_nbt"].push(pack->inverter_r_rcv(i).can_nbt());
		(*net_signals)["INVERTER_R_RCV"]["pos_zero_capture"].push(pack->inverter_r_rcv(i).pos_zero_capture());
		(*net_signals)["INVERTER_R_RCV"]["ref_reso_edge"].push(pack->inverter_r_rcv(i).ref_reso_edge());
		(*net_signals)["INVERTER_R_RCV"]["speed_1"].push(pack->inverter_r_rcv(i).speed_1());
		(*net_signals)["INVERTER_R_RCV"]["speed_2"].push(pack->inverter_r_rcv(i).speed_2());
		(*net_signals)["INVERTER_R_RCV"]["pos_tol_win"].push(pack->inverter_r_rcv(i).pos_tol_win());
		(*net_signals)["INVERTER_R_RCV"]["pos_preset_val"].push(pack->inverter_r_rcv(i).pos_preset_val());
		(*net_signals)["INVERTER_R_RCV"]["pos_zero_offset"].push(pack->inverter_r_rcv(i).pos_zero_offset());
		(*net_signals)["INVERTER_R_RCV"]["pos_nd_scale"].push(pack->inverter_r_rcv(i).pos_nd_scale());
		(*net_signals)["INVERTER_R_RCV"]["pos_nd_offset"].push(pack->inverter_r_rcv(i).pos_nd_offset());
		(*net_signals)["INVERTER_R_RCV"]["fb2_scale_ext"].push(pack->inverter_r_rcv(i).fb2_scale_ext());
		(*net_signals)["INVERTER_R_RCV"]["pos_offset_slack"].push(pack->inverter_r_rcv(i).pos_offset_slack());
		(*net_signals)["INVERTER_R_RCV"]["pos_diff_slack"].push(pack->inverter_r_rcv(i).pos_diff_slack());
		(*net_signals)["INVERTER_R_RCV"]["fun_para_read"].push(pack->inverter_r_rcv(i).fun_para_read());
		(*net_signals)["INVERTER_R_RCV"]["fun_para_write"].push(pack->inverter_r_rcv(i).fun_para_write());
		(*net_signals)["INVERTER_R_RCV"]["fun_special"].push(pack->inverter_r_rcv(i).fun_special());
		(*net_signals)["INVERTER_R_RCV"]["can_id_2_rx"].push(pack->inverter_r_rcv(i).can_id_2_rx());
		(*net_signals)["INVERTER_R_RCV"]["can_id_2_tx"].push(pack->inverter_r_rcv(i).can_id_2_tx());
		(*net_signals)["INVERTER_R_RCV"]["v_ref"].push(pack->inverter_r_rcv(i).v_ref());
		(*net_signals)["INVERTER_R_RCV"]["v_kp"].push(pack->inverter_r_rcv(i).v_kp());
		(*net_signals)["INVERTER_R_RCV"]["pid_n__ti"].push(pack->inverter_r_rcv(i).pid_n__ti());
		(*net_signals)["INVERTER_R_RCV"]["clear_errors"].push(pack->inverter_r_rcv(i).clear_errors());
		(*net_signals)["INVERTER_R_RCV"]["pos_cmd"].push(pack->inverter_r_rcv(i).pos_cmd());
		(*net_signals)["INVERTER_R_RCV"]["can_error_busoff"].push(pack->inverter_r_rcv(i).can_error_busoff());
		(*net_signals)["INVERTER_R_RCV"]["can_error_writetime"].push(pack->inverter_r_rcv(i).can_error_writetime());
		(*net_signals)["INVERTER_R_RCV"]["ecode_bit0_firsterrordtcd148"].push(pack->inverter_r_rcv(i).ecode_bit0_firsterrordtcd148());
		(*net_signals)["INVERTER_R_RCV"]["can_error_no_ack"].push(pack->inverter_r_rcv(i).can_error_no_ack());
		(*net_signals)["INVERTER_R_RCV"]["can_error_crc_check150"].push(pack->inverter_r_rcv(i).can_error_crc_check150());
		(*net_signals)["INVERTER_R_RCV"]["can_error_crc_check151"].push(pack->inverter_r_rcv(i).can_error_crc_check151());
		(*net_signals)["INVERTER_R_RCV"]["info_timer_diff"].push(pack->inverter_r_rcv(i).info_timer_diff());
		(*net_signals)["INVERTER_R_RCV"]["ballastcount"].push(pack->inverter_r_rcv(i).ballastcount());
		(*net_signals)["INVERTER_R_RCV"]["m_temp"].push(pack->inverter_r_rcv(i).m_temp());
		(*net_signals)["INVERTER_R_RCV"]["mo_feedback_1"].push(pack->inverter_r_rcv(i).mo_feedback_1());
		(*net_signals)["INVERTER_R_RCV"]["dc_bus_min_lim"].push(pack->inverter_r_rcv(i).dc_bus_min_lim());
		(*net_signals)["INVERTER_R_RCV"]["fb_incr_mot"].push(pack->inverter_r_rcv(i).fb_incr_mot());
		(*net_signals)["INVERTER_R_RCV"]["fb_pole"].push(pack->inverter_r_rcv(i).fb_pole());
		(*net_signals)["INVERTER_R_RCV"]["logic_freq"].push(pack->inverter_r_rcv(i).logic_freq());
		(*net_signals)["INVERTER_R_RCV"]["pwm_1"].push(pack->inverter_r_rcv(i).pwm_1());
		(*net_signals)["INVERTER_R_RCV"]["pwm_2"].push(pack->inverter_r_rcv(i).pwm_2());
		(*net_signals)["INVERTER_R_RCV"]["pwm_3"].push(pack->inverter_r_rcv(i).pwm_3());
		(*net_signals)["INVERTER_R_RCV"]["timer_delta"].push(pack->inverter_r_rcv(i).timer_delta());
		(*net_signals)["INVERTER_R_RCV"]["motor_lsq"].push(pack->inverter_r_rcv(i).motor_lsq());
		(*net_signals)["INVERTER_R_RCV"]["motor_lsd"].push(pack->inverter_r_rcv(i).motor_lsd());
		(*net_signals)["INVERTER_R_RCV"]["id_nom"].push(pack->inverter_r_rcv(i).id_nom());
		(*net_signals)["INVERTER_R_RCV"]["motor_lm"].push(pack->inverter_r_rcv(i).motor_lm());
		(*net_signals)["INVERTER_R_RCV"]["motor_rr"].push(pack->inverter_r_rcv(i).motor_rr());
		(*net_signals)["INVERTER_R_RCV"]["id_min"].push(pack->inverter_r_rcv(i).id_min());
		(*net_signals)["INVERTER_R_RCV"]["motor_tr"].push(pack->inverter_r_rcv(i).motor_tr());
		(*net_signals)["INVERTER_R_RCV"]["motor_rs"].push(pack->inverter_r_rcv(i).motor_rs());
		(*net_signals)["INVERTER_R_RCV"]["motor_ts"].push(pack->inverter_r_rcv(i).motor_ts());
		(*net_signals)["INVERTER_R_RCV"]["def_end_1"].push(pack->inverter_r_rcv(i).def_end_1());
		(*net_signals)["INVERTER_R_RCV"]["def_end_2"].push(pack->inverter_r_rcv(i).def_end_2());
		(*net_signals)["INVERTER_R_RCV"]["def_din_1"].push(pack->inverter_r_rcv(i).def_din_1());
		(*net_signals)["INVERTER_R_RCV"]["def_din_2"].push(pack->inverter_r_rcv(i).def_din_2());
		(*net_signals)["INVERTER_R_RCV"]["operand194"].push(pack->inverter_r_rcv(i).operand194());
		(*net_signals)["INVERTER_R_RCV"]["i_max_inuse"].push(pack->inverter_r_rcv(i).i_max_inuse());
		(*net_signals)["INVERTER_R_RCV"]["signal_go"].push(pack->inverter_r_rcv(i).signal_go());
		(*net_signals)["INVERTER_R_RCV"]["signal_brake"].push(pack->inverter_r_rcv(i).signal_brake());
		(*net_signals)["INVERTER_R_RCV"]["signal_icns"].push(pack->inverter_r_rcv(i).signal_icns());
		(*net_signals)["INVERTER_R_RCV"]["signal_lessn0"].push(pack->inverter_r_rcv(i).signal_lessn0());
		(*net_signals)["INVERTER_R_RCV"]["signal_postolerance"].push(pack->inverter_r_rcv(i).signal_postolerance());
		(*net_signals)["INVERTER_R_RCV"]["ain_in_1_scaled251"].push(pack->inverter_r_rcv(i).ain_in_1_scaled251());
		(*net_signals)["INVERTER_R_RCV"]["ain_in_2_scaled252"].push(pack->inverter_r_rcv(i).ain_in_2_scaled252());
		(*net_signals)["INVERTER_R_RCV"]["operand195"].push(pack->inverter_r_rcv(i).operand195());
		(*net_signals)["INVERTER_R_RCV"]["operand218"].push(pack->inverter_r_rcv(i).operand218());
		(*net_signals)["INVERTER_R_RCV"]["operand219"].push(pack->inverter_r_rcv(i).operand219());
		(*net_signals)["INVERTER_R_RCV"]["pid_i__xkp__iq"].push(pack->inverter_r_rcv(i).pid_i__xkp__iq());
		(*net_signals)["INVERTER_R_RCV"]["bat_opr_limit__mot"].push(pack->inverter_r_rcv(i).bat_opr_limit__mot());
		(*net_signals)["INVERTER_R_RCV"]["pid_i__kf__iq"].push(pack->inverter_r_rcv(i).pid_i__kf__iq());
		(*net_signals)["INVERTER_R_RCV"]["dc_current_sens_ena_set"].push(pack->inverter_r_rcv(i).dc_current_sens_ena_set());
		(*net_signals)["INVERTER_R_RCV"]["cmc__bit0__dc_current_sens_ena"].push(pack->inverter_r_rcv(i).cmc__bit0__dc_current_sens_ena());
		(*net_signals)["INVERTER_R_RCV"]["n_rpm_maxint"].push(pack->inverter_r_rcv(i).n_rpm_maxint());
		(*net_signals)["INVERTER_R_RCV"]["var_1"].push(pack->inverter_r_rcv(i).var_1());
		(*net_signals)["INVERTER_R_RCV"]["can_rxtimeout"].push(pack->inverter_r_rcv(i).can_rxtimeout());
		(*net_signals)["INVERTER_R_RCV"]["var_2"].push(pack->inverter_r_rcv(i).var_2());
		(*net_signals)["INVERTER_R_RCV"]["var_3"].push(pack->inverter_r_rcv(i).var_3());
		(*net_signals)["INVERTER_R_RCV"]["var_4"].push(pack->inverter_r_rcv(i).var_4());
		(*net_signals)["INVERTER_R_RCV"]["dup__bit7_0__dac_source_channel"].push(pack->inverter_r_rcv(i).dup__bit7_0__dac_source_channel());
		(*net_signals)["INVERTER_R_RCV"]["fb_lossofsignal"].push(pack->inverter_r_rcv(i).fb_lossofsignal());
		(*net_signals)["INVERTER_R_RCV"]["no_hw_fault"].push(pack->inverter_r_rcv(i).no_hw_fault());
		(*net_signals)["INVERTER_R_RCV"]["t_peak"].push(pack->inverter_r_rcv(i).t_peak());
		(*net_signals)["INVERTER_R_RCV"]["brake_delay"].push(pack->inverter_r_rcv(i).brake_delay());
		(*net_signals)["INVERTER_R_RCV"]["power"].push(pack->inverter_r_rcv(i).power());
		(*net_signals)["INVERTER_R_RCV"]["work"].push(pack->inverter_r_rcv(i).work());
		(*net_signals)["INVERTER_R_RCV"]["extra__start"].push(pack->inverter_r_rcv(i).extra__start());
		(*net_signals)["INVERTER_R_RCV"]["capture_channel"].push(pack->inverter_r_rcv(i).capture_channel());
		(*net_signals)["INVERTER_R_RCV"]["trig_level"].push(pack->inverter_r_rcv(i).trig_level());
		(*net_signals)["INVERTER_R_RCV"]["trig_edge"].push(pack->inverter_r_rcv(i).trig_edge());
		(*net_signals)["INVERTER_R_RCV"]["trig_source"].push(pack->inverter_r_rcv(i).trig_source());
		(*net_signals)["INVERTER_R_RCV"]["oszi_source"].push(pack->inverter_r_rcv(i).oszi_source());
		(*net_signals)["INVERTER_R_RCV"]["oszi_skip"].push(pack->inverter_r_rcv(i).oszi_skip());
		(*net_signals)["INVERTER_R_RCV"]["oszi_run_cmd"].push(pack->inverter_r_rcv(i).oszi_run_cmd());
		(*net_signals)["INVERTER_R_RCV"]["oszi_read_cmd"].push(pack->inverter_r_rcv(i).oszi_read_cmd());
		(*net_signals)["INVERTER_R_RCV"]["pos_ref_start"].push(pack->inverter_r_rcv(i).pos_ref_start());
		(*net_signals)["INVERTER_R_RCV"]["vdc_bus"].push(pack->inverter_r_rcv(i).vdc_bus());
		(*net_signals)["INVERTER_R_RCV"]["m_cmd_ramp"].push(pack->inverter_r_rcv(i).m_cmd_ramp());
		(*net_signals)["INVERTER_R_RCV"]["lmt_1"].push(pack->inverter_r_rcv(i).lmt_1());
		(*net_signals)["INVERTER_R_RCV"]["out_1"].push(pack->inverter_r_rcv(i).out_1());
		(*net_signals)["INVERTER_R_RCV"]["subversion_nr"].push(pack->inverter_r_rcv(i).subversion_nr());
		(*net_signals)["INVERTER_R_RCV"]["ballast_ext"].push(pack->inverter_r_rcv(i).ballast_ext());
		(*net_signals)["INVERTER_R_RCV"]["ncr064"].push(pack->inverter_r_rcv(i).ncr064());
		(*net_signals)["INVERTER_R_RCV"]["err_powerfault"].push(pack->inverter_r_rcv(i).err_powerfault());
		(*net_signals)["INVERTER_R_RCV"]["lmt2"].push(pack->inverter_r_rcv(i).lmt2());
		(*net_signals)["INVERTER_R_RCV"]["km_speed_0"].push(pack->inverter_r_rcv(i).km_speed_0());
		(*net_signals)["INVERTER_R_RCV"]["ncr082"].push(pack->inverter_r_rcv(i).ncr082());
		(*net_signals)["INVERTER_R_RCV"]["ecode_bit1__hw1_state99"].push(pack->inverter_r_rcv(i).ecode_bit1__hw1_state99());
		(*net_signals)["INVERTER_R_RCV"]["ecode_bit1__hw1_state148"].push(pack->inverter_r_rcv(i).ecode_bit1__hw1_state148());
		(*net_signals)["INVERTER_R_RCV"]["dc_i_sensena_set"].push(pack->inverter_r_rcv(i).dc_i_sensena_set());
		(*net_signals)["INVERTER_R_RCV"]["cmc__bit1__idc_limit_ena"].push(pack->inverter_r_rcv(i).cmc__bit1__idc_limit_ena());
		(*net_signals)["INVERTER_R_RCV"]["lmt_2"].push(pack->inverter_r_rcv(i).lmt_2());
		(*net_signals)["INVERTER_R_RCV"]["out_2"].push(pack->inverter_r_rcv(i).out_2());
		(*net_signals)["INVERTER_R_RCV"]["fb_special"].push(pack->inverter_r_rcv(i).fb_special());
		(*net_signals)["INVERTER_R_RCV"]["lim_plus64"].push(pack->inverter_r_rcv(i).lim_plus64());
		(*net_signals)["INVERTER_R_RCV"]["err_rfe_fault"].push(pack->inverter_r_rcv(i).err_rfe_fault());
		(*net_signals)["INVERTER_R_RCV"]["in2"].push(pack->inverter_r_rcv(i).in2());
		(*net_signals)["INVERTER_R_RCV"]["cs_ain_2_format"].push(pack->inverter_r_rcv(i).cs_ain_2_format());
		(*net_signals)["INVERTER_R_RCV"]["km_frg_off"].push(pack->inverter_r_rcv(i).km_frg_off());
		(*net_signals)["INVERTER_R_RCV"]["lim_plus82"].push(pack->inverter_r_rcv(i).lim_plus82());
		(*net_signals)["INVERTER_R_RCV"]["ecode_bit2__hw0_state99"].push(pack->inverter_r_rcv(i).ecode_bit2__hw0_state99());
		(*net_signals)["INVERTER_R_RCV"]["ecode_bit2__hw0_state148"].push(pack->inverter_r_rcv(i).ecode_bit2__hw0_state148());
		(*net_signals)["INVERTER_R_RCV"]["op_mode_quadrant"].push(pack->inverter_r_rcv(i).op_mode_quadrant());
		(*net_signals)["INVERTER_R_RCV"]["cmc__bit2__pdc_limit_usage"].push(pack->inverter_r_rcv(i).cmc__bit2__pdc_limit_usage());
		(*net_signals)["INVERTER_R_RCV"]["in_2"].push(pack->inverter_r_rcv(i).in_2());
		(*net_signals)["INVERTER_R_RCV"]["rdy155"].push(pack->inverter_r_rcv(i).rdy155());
		(*net_signals)["INVERTER_R_RCV"]["coaststop"].push(pack->inverter_r_rcv(i).coaststop());
		(*net_signals)["INVERTER_R_RCV"]["lim_minus64"].push(pack->inverter_r_rcv(i).lim_minus64());
		(*net_signals)["INVERTER_R_RCV"]["err_bustimeout"].push(pack->inverter_r_rcv(i).err_bustimeout());
		(*net_signals)["INVERTER_R_RCV"]["in1"].push(pack->inverter_r_rcv(i).in1());
		(*net_signals)["INVERTER_R_RCV"]["km_cal_off"].push(pack->inverter_r_rcv(i).km_cal_off());
		(*net_signals)["INVERTER_R_RCV"]["lim_minus82"].push(pack->inverter_r_rcv(i).lim_minus82());
		(*net_signals)["INVERTER_R_RCV"]["ecode_bit3__free99"].push(pack->inverter_r_rcv(i).ecode_bit3__free99());
		(*net_signals)["INVERTER_R_RCV"]["ecode_bit3__free148"].push(pack->inverter_r_rcv(i).ecode_bit3__free148());
		(*net_signals)["INVERTER_R_RCV"]["cmc__bit3__torqueval_init_ena"].push(pack->inverter_r_rcv(i).cmc__bit3__torqueval_init_ena());
		(*net_signals)["INVERTER_R_RCV"]["in_1"].push(pack->inverter_r_rcv(i).in_1());
		(*net_signals)["INVERTER_R_RCV"]["go155"].push(pack->inverter_r_rcv(i).go155());
		(*net_signals)["INVERTER_R_RCV"]["i_ist_inverse"].push(pack->inverter_r_rcv(i).i_ist_inverse());
		(*net_signals)["INVERTER_R_RCV"]["ok64"].push(pack->inverter_r_rcv(i).ok64());
		(*net_signals)["INVERTER_R_RCV"]["err_feedbacksignal"].push(pack->inverter_r_rcv(i).err_feedbacksignal());
		(*net_signals)["INVERTER_R_RCV"]["frgrun"].push(pack->inverter_r_rcv(i).frgrun());
		(*net_signals)["INVERTER_R_RCV"]["cs_ain_1_mode"].push(pack->inverter_r_rcv(i).cs_ain_1_mode());
		(*net_signals)["INVERTER_R_RCV"]["km_tx_tog_stat"].push(pack->inverter_r_rcv(i).km_tx_tog_stat());
		(*net_signals)["INVERTER_R_RCV"]["ok82"].push(pack->inverter_r_rcv(i).ok82());
		(*net_signals)["INVERTER_R_RCV"]["ecode_bit4__rdy399"].push(pack->inverter_r_rcv(i).ecode_bit4__rdy399());
		(*net_signals)["INVERTER_R_RCV"]["ecode_bit4__rdy3148"].push(pack->inverter_r_rcv(i).ecode_bit4__rdy3148());
		(*net_signals)["INVERTER_R_RCV"]["compare_var194"].push(pack->inverter_r_rcv(i).compare_var194());
		(*net_signals)["INVERTER_R_RCV"]["compare_var195"].push(pack->inverter_r_rcv(i).compare_var195());
		(*net_signals)["INVERTER_R_RCV"]["compare_var218"].push(pack->inverter_r_rcv(i).compare_var218());
		(*net_signals)["INVERTER_R_RCV"]["compare_var219"].push(pack->inverter_r_rcv(i).compare_var219());
		(*net_signals)["INVERTER_R_RCV"]["cmc__bit4__dig_m_rcpramp_ena"].push(pack->inverter_r_rcv(i).cmc__bit4__dig_m_rcpramp_ena());
		(*net_signals)["INVERTER_R_RCV"]["run152"].push(pack->inverter_r_rcv(i).run152());
		(*net_signals)["INVERTER_R_RCV"]["out_3"].push(pack->inverter_r_rcv(i).out_3());
		(*net_signals)["INVERTER_R_RCV"]["refsoft"].push(pack->inverter_r_rcv(i).refsoft());
		(*net_signals)["INVERTER_R_RCV"]["icns64"].push(pack->inverter_r_rcv(i).icns64());
		(*net_signals)["INVERTER_R_RCV"]["err_powervoltage_low"].push(pack->inverter_r_rcv(i).err_powervoltage_low());
		(*net_signals)["INVERTER_R_RCV"]["rfe216"].push(pack->inverter_r_rcv(i).rfe216());
		(*net_signals)["INVERTER_R_RCV"]["km_i_limit"].push(pack->inverter_r_rcv(i).km_i_limit());
		(*net_signals)["INVERTER_R_RCV"]["icns82"].push(pack->inverter_r_rcv(i).icns82());
		(*net_signals)["INVERTER_R_RCV"]["ecode_bit5__n_fail99"].push(pack->inverter_r_rcv(i).ecode_bit5__n_fail99());
		(*net_signals)["INVERTER_R_RCV"]["ecode_bit5__n_fail148"].push(pack->inverter_r_rcv(i).ecode_bit5__n_fail148());
		(*net_signals)["INVERTER_R_RCV"]["mo_feedback_2"].push(pack->inverter_r_rcv(i).mo_feedback_2());
		(*net_signals)["INVERTER_R_RCV"]["recup_is_acv"].push(pack->inverter_r_rcv(i).recup_is_acv());
		(*net_signals)["INVERTER_R_RCV"]["cmc__bit5__reset_nramp_atnzero"].push(pack->inverter_r_rcv(i).cmc__bit5__reset_nramp_atnzero());
		(*net_signals)["INVERTER_R_RCV"]["rfe152"].push(pack->inverter_r_rcv(i).rfe152());
		(*net_signals)["INVERTER_R_RCV"]["out_4"].push(pack->inverter_r_rcv(i).out_4());
		(*net_signals)["INVERTER_R_RCV"]["no_uesp_btb"].push(pack->inverter_r_rcv(i).no_uesp_btb());
		(*net_signals)["INVERTER_R_RCV"]["tnlim64"].push(pack->inverter_r_rcv(i).tnlim64());
		(*net_signals)["INVERTER_R_RCV"]["err_motortemp"].push(pack->inverter_r_rcv(i).err_motortemp());
		(*net_signals)["INVERTER_R_RCV"]["km_n_clip"].push(pack->inverter_r_rcv(i).km_n_clip());
		(*net_signals)["INVERTER_R_RCV"]["tnlim82"].push(pack->inverter_r_rcv(i).tnlim82());
		(*net_signals)["INVERTER_R_RCV"]["ecode_bit6__flths99"].push(pack->inverter_r_rcv(i).ecode_bit6__flths99());
		(*net_signals)["INVERTER_R_RCV"]["ecode_bit6__flths148"].push(pack->inverter_r_rcv(i).ecode_bit6__flths148());
		(*net_signals)["INVERTER_R_RCV"]["i_dc_limit_is_acv"].push(pack->inverter_r_rcv(i).i_dc_limit_is_acv());
		(*net_signals)["INVERTER_R_RCV"]["cmc__bit6__torquetimeout_100ms_e"].push(pack->inverter_r_rcv(i).cmc__bit6__torquetimeout_100ms_e());
		(*net_signals)["INVERTER_R_RCV"]["rsvd"].push(pack->inverter_r_rcv(i).rsvd());
		(*net_signals)["INVERTER_R_RCV"]["rsvd1"].push(pack->inverter_r_rcv(i).rsvd1());
		(*net_signals)["INVERTER_R_RCV"]["vdc_ana"].push(pack->inverter_r_rcv(i).vdc_ana());
		(*net_signals)["INVERTER_R_RCV"]["pn64"].push(pack->inverter_r_rcv(i).pn64());
		(*net_signals)["INVERTER_R_RCV"]["err_devicetemp"].push(pack->inverter_r_rcv(i).err_devicetemp());
		(*net_signals)["INVERTER_R_RCV"]["cs_oora1"].push(pack->inverter_r_rcv(i).cs_oora1());
		(*net_signals)["INVERTER_R_RCV"]["km_mix_ana_on"].push(pack->inverter_r_rcv(i).km_mix_ana_on());
		(*net_signals)["INVERTER_R_RCV"]["pn82"].push(pack->inverter_r_rcv(i).pn82());
		(*net_signals)["INVERTER_R_RCV"]["ecode_bit7__fltls99"].push(pack->inverter_r_rcv(i).ecode_bit7__fltls99());
		(*net_signals)["INVERTER_R_RCV"]["ecode_bit7__fltls148"].push(pack->inverter_r_rcv(i).ecode_bit7__fltls148());
		(*net_signals)["INVERTER_R_RCV"]["cmc__bit13_7__free"].push(pack->inverter_r_rcv(i).cmc__bit13_7__free());
		(*net_signals)["INVERTER_R_RCV"]["brk1155"].push(pack->inverter_r_rcv(i).brk1155());
		(*net_signals)["INVERTER_R_RCV"]["i1_adc_ena"].push(pack->inverter_r_rcv(i).i1_adc_ena());
		(*net_signals)["INVERTER_R_RCV"]["ni64"].push(pack->inverter_r_rcv(i).ni64());
		(*net_signals)["INVERTER_R_RCV"]["err_overvoltage"].push(pack->inverter_r_rcv(i).err_overvoltage());
		(*net_signals)["INVERTER_R_RCV"]["out1"].push(pack->inverter_r_rcv(i).out1());
		(*net_signals)["INVERTER_R_RCV"]["cs_ain_2_mode"].push(pack->inverter_r_rcv(i).cs_ain_2_mode());
		(*net_signals)["INVERTER_R_RCV"]["ctrlsubmode"].push(pack->inverter_r_rcv(i).ctrlsubmode());
		(*net_signals)["INVERTER_R_RCV"]["km_allow_sync"].push(pack->inverter_r_rcv(i).km_allow_sync());
		(*net_signals)["INVERTER_R_RCV"]["ni82"].push(pack->inverter_r_rcv(i).ni82());
		(*net_signals)["INVERTER_R_RCV"]["ain_in_2_filter"].push(pack->inverter_r_rcv(i).ain_in_2_filter());
		(*net_signals)["INVERTER_R_RCV"]["ecode_bit8__fail_idc99"].push(pack->inverter_r_rcv(i).ecode_bit8__fail_idc99());
		(*net_signals)["INVERTER_R_RCV"]["ecode_bit8__fail_idc148"].push(pack->inverter_r_rcv(i).ecode_bit8__fail_idc148());
		(*net_signals)["INVERTER_R_RCV"]["mo_sc1_reso"].push(pack->inverter_r_rcv(i).mo_sc1_reso());
		(*net_signals)["INVERTER_R_RCV"]["source_id194"].push(pack->inverter_r_rcv(i).source_id194());
		(*net_signals)["INVERTER_R_RCV"]["source_id195"].push(pack->inverter_r_rcv(i).source_id195());
		(*net_signals)["INVERTER_R_RCV"]["source_id218"].push(pack->inverter_r_rcv(i).source_id218());
		(*net_signals)["INVERTER_R_RCV"]["source_id219"].push(pack->inverter_r_rcv(i).source_id219());
		(*net_signals)["INVERTER_R_RCV"]["dup__bit8__can_extended_0"].push(pack->inverter_r_rcv(i).dup__bit8__can_extended_0());
		(*net_signals)["INVERTER_R_RCV"]["hxinv"].push(pack->inverter_r_rcv(i).hxinv());
		(*net_signals)["INVERTER_R_RCV"]["_n064"].push(pack->inverter_r_rcv(i)._n064());
		(*net_signals)["INVERTER_R_RCV"]["err_ipeak"].push(pack->inverter_r_rcv(i).err_ipeak());
		(*net_signals)["INVERTER_R_RCV"]["out2"].push(pack->inverter_r_rcv(i).out2());
		(*net_signals)["INVERTER_R_RCV"]["km_handwheel"].push(pack->inverter_r_rcv(i).km_handwheel());
		(*net_signals)["INVERTER_R_RCV"]["_n082"].push(pack->inverter_r_rcv(i)._n082());
		(*net_signals)["INVERTER_R_RCV"]["ecode_bit9__fail_i99"].push(pack->inverter_r_rcv(i).ecode_bit9__fail_i99());
		(*net_signals)["INVERTER_R_RCV"]["ecode_bit9__fail_i148"].push(pack->inverter_r_rcv(i).ecode_bit9__fail_i148());
		(*net_signals)["INVERTER_R_RCV"]["dup__bit9__generator"].push(pack->inverter_r_rcv(i).dup__bit9__generator());
		(*net_signals)["INVERTER_R_RCV"]["h2inv"].push(pack->inverter_r_rcv(i).h2inv());
		(*net_signals)["INVERTER_R_RCV"]["rsw64"].push(pack->inverter_r_rcv(i).rsw64());
		(*net_signals)["INVERTER_R_RCV"]["err_raceaway"].push(pack->inverter_r_rcv(i).err_raceaway());
		(*net_signals)["INVERTER_R_RCV"]["btbrdy"].push(pack->inverter_r_rcv(i).btbrdy());
		(*net_signals)["INVERTER_R_RCV"]["km_phasing_extend"].push(pack->inverter_r_rcv(i).km_phasing_extend());
		(*net_signals)["INVERTER_R_RCV"]["rsw82"].push(pack->inverter_r_rcv(i).rsw82());
		(*net_signals)["INVERTER_R_RCV"]["ecode_bit10__vccm99"].push(pack->inverter_r_rcv(i).ecode_bit10__vccm99());
		(*net_signals)["INVERTER_R_RCV"]["ecode_bit10__vccm148"].push(pack->inverter_r_rcv(i).ecode_bit10__vccm148());
		(*net_signals)["INVERTER_R_RCV"]["dup__bit10__park_rms"].push(pack->inverter_r_rcv(i).dup__bit10__park_rms());
		(*net_signals)["INVERTER_R_RCV"]["ol_comp"].push(pack->inverter_r_rcv(i).ol_comp());
		(*net_signals)["INVERTER_R_RCV"]["cal064"].push(pack->inverter_r_rcv(i).cal064());
		(*net_signals)["INVERTER_R_RCV"]["err_user"].push(pack->inverter_r_rcv(i).err_user());
		(*net_signals)["INVERTER_R_RCV"]["go216"].push(pack->inverter_r_rcv(i).go216());
		(*net_signals)["INVERTER_R_RCV"]["cs_oora2"].push(pack->inverter_r_rcv(i).cs_oora2());
		(*net_signals)["INVERTER_R_RCV"]["km_rsvd_11"].push(pack->inverter_r_rcv(i).km_rsvd_11());
		(*net_signals)["INVERTER_R_RCV"]["cal082"].push(pack->inverter_r_rcv(i).cal082());
		(*net_signals)["INVERTER_R_RCV"]["ecode_bit11__15m_minus99"].push(pack->inverter_r_rcv(i).ecode_bit11__15m_minus99());
		(*net_signals)["INVERTER_R_RCV"]["ecode_bit11__15m_minus148"].push(pack->inverter_r_rcv(i).ecode_bit11__15m_minus148());
		(*net_signals)["INVERTER_R_RCV"]["mo_sc1_comp"].push(pack->inverter_r_rcv(i).mo_sc1_comp());
		(*net_signals)["INVERTER_R_RCV"]["dup__bit11__dcbus_volts"].push(pack->inverter_r_rcv(i).dup__bit11__dcbus_volts());
		(*net_signals)["INVERTER_R_RCV"]["test"].push(pack->inverter_r_rcv(i).test());
		(*net_signals)["INVERTER_R_RCV"]["motortype"].push(pack->inverter_r_rcv(i).motortype());
		(*net_signals)["INVERTER_R_RCV"]["cal64"].push(pack->inverter_r_rcv(i).cal64());
		(*net_signals)["INVERTER_R_RCV"]["out3"].push(pack->inverter_r_rcv(i).out3());
		(*net_signals)["INVERTER_R_RCV"]["cs_cmd_type"].push(pack->inverter_r_rcv(i).cs_cmd_type());
		(*net_signals)["INVERTER_R_RCV"]["currentmode"].push(pack->inverter_r_rcv(i).currentmode());
		(*net_signals)["INVERTER_R_RCV"]["km_rsvd_12"].push(pack->inverter_r_rcv(i).km_rsvd_12());
		(*net_signals)["INVERTER_R_RCV"]["cal82"].push(pack->inverter_r_rcv(i).cal82());
		(*net_signals)["INVERTER_R_RCV"]["ecode_bit12__15m_plus99"].push(pack->inverter_r_rcv(i).ecode_bit12__15m_plus99());
		(*net_signals)["INVERTER_R_RCV"]["ecode_bit12__15m_plus148"].push(pack->inverter_r_rcv(i).ecode_bit12__15m_plus148());
		(*net_signals)["INVERTER_R_RCV"]["mo_sc2_reso"].push(pack->inverter_r_rcv(i).mo_sc2_reso());
		(*net_signals)["INVERTER_R_RCV"]["dup__bit12__boat_pedal"].push(pack->inverter_r_rcv(i).dup__bit12__boat_pedal());
		(*net_signals)["INVERTER_R_RCV"]["tol64"].push(pack->inverter_r_rcv(i).tol64());
		(*net_signals)["INVERTER_R_RCV"]["out4"].push(pack->inverter_r_rcv(i).out4());
		(*net_signals)["INVERTER_R_RCV"]["km_rsvd_13"].push(pack->inverter_r_rcv(i).km_rsvd_13());
		(*net_signals)["INVERTER_R_RCV"]["tol82"].push(pack->inverter_r_rcv(i).tol82());
		(*net_signals)["INVERTER_R_RCV"]["ecode_bit13__18m_plus99"].push(pack->inverter_r_rcv(i).ecode_bit13__18m_plus99());
		(*net_signals)["INVERTER_R_RCV"]["ecode_bit13__18m_plus148"].push(pack->inverter_r_rcv(i).ecode_bit13__18m_plus148());
		(*net_signals)["INVERTER_R_RCV"]["dup__bit13__gen_autoiaclimit"].push(pack->inverter_r_rcv(i).dup__bit13__gen_autoiaclimit());
		(*net_signals)["INVERTER_R_RCV"]["ana_0up"].push(pack->inverter_r_rcv(i).ana_0up());
		(*net_signals)["INVERTER_R_RCV"]["rdy64"].push(pack->inverter_r_rcv(i).rdy64());
		(*net_signals)["INVERTER_R_RCV"]["err_hwerr"].push(pack->inverter_r_rcv(i).err_hwerr());
		(*net_signals)["INVERTER_R_RCV"]["goff"].push(pack->inverter_r_rcv(i).goff());
		(*net_signals)["INVERTER_R_RCV"]["cs_ain_2__i_limit"].push(pack->inverter_r_rcv(i).cs_ain_2__i_limit());
		(*net_signals)["INVERTER_R_RCV"]["km_pseudo_enable"].push(pack->inverter_r_rcv(i).km_pseudo_enable());
		(*net_signals)["INVERTER_R_RCV"]["rdy82"].push(pack->inverter_r_rcv(i).rdy82());
		(*net_signals)["INVERTER_R_RCV"]["ecode_bit14__ubmam99"].push(pack->inverter_r_rcv(i).ecode_bit14__ubmam99());
		(*net_signals)["INVERTER_R_RCV"]["ecode_bit14__ubmam148"].push(pack->inverter_r_rcv(i).ecode_bit14__ubmam148());
		(*net_signals)["INVERTER_R_RCV"]["cmc__bit14__idc_limit_ena_v2"].push(pack->inverter_r_rcv(i).cmc__bit14__idc_limit_ena_v2());
		(*net_signals)["INVERTER_R_RCV"]["dup__bit14__mtpa_reluct_enab"].push(pack->inverter_r_rcv(i).dup__bit14__mtpa_reluct_enab());
		(*net_signals)["INVERTER_R_RCV"]["lowbd"].push(pack->inverter_r_rcv(i).lowbd());
		(*net_signals)["INVERTER_R_RCV"]["brk064"].push(pack->inverter_r_rcv(i).brk064());
		(*net_signals)["INVERTER_R_RCV"]["err_ballast"].push(pack->inverter_r_rcv(i).err_ballast());
		(*net_signals)["INVERTER_R_RCV"]["brk1216"].push(pack->inverter_r_rcv(i).brk1216());
		(*net_signals)["INVERTER_R_RCV"]["cs_ain_1__n_limit"].push(pack->inverter_r_rcv(i).cs_ain_1__n_limit());
		(*net_signals)["INVERTER_R_RCV"]["km_debug_test"].push(pack->inverter_r_rcv(i).km_debug_test());
		(*net_signals)["INVERTER_R_RCV"]["brk082"].push(pack->inverter_r_rcv(i).brk082());
		(*net_signals)["INVERTER_R_RCV"]["ecode_bit15__t_igbt99"].push(pack->inverter_r_rcv(i).ecode_bit15__t_igbt99());
		(*net_signals)["INVERTER_R_RCV"]["ecode_bit15__t_igbt148"].push(pack->inverter_r_rcv(i).ecode_bit15__t_igbt148());
		(*net_signals)["INVERTER_R_RCV"]["mo_sc2_inv"].push(pack->inverter_r_rcv(i).mo_sc2_inv());
		(*net_signals)["INVERTER_R_RCV"]["active190"].push(pack->inverter_r_rcv(i).active190());
		(*net_signals)["INVERTER_R_RCV"]["active191"].push(pack->inverter_r_rcv(i).active191());
		(*net_signals)["INVERTER_R_RCV"]["active192"].push(pack->inverter_r_rcv(i).active192());
		(*net_signals)["INVERTER_R_RCV"]["active193"].push(pack->inverter_r_rcv(i).active193());
		(*net_signals)["INVERTER_R_RCV"]["gen_autoiaclimit_is_acv"].push(pack->inverter_r_rcv(i).gen_autoiaclimit_is_acv());
		(*net_signals)["INVERTER_R_RCV"]["cmc__bit15__dig_e_brake_act"].push(pack->inverter_r_rcv(i).cmc__bit15__dig_e_brake_act());
		(*net_signals)["INVERTER_R_RCV"]["dup__bit15__canopen_acv"].push(pack->inverter_r_rcv(i).dup__bit15__canopen_acv());
		(*net_signals)["INVERTER_R_RCV"]["m_r_dec"].push(pack->inverter_r_rcv(i).m_r_dec());
		(*net_signals)["INVERTER_R_RCV"]["m_r_rcp"].push(pack->inverter_r_rcv(i).m_r_rcp());
		(*net_signals)["INVERTER_R_RCV"]["sramp"].push(pack->inverter_r_rcv(i).sramp());
		(*net_signals)["INVERTER_R_RCV"]["signmag64"].push(pack->inverter_r_rcv(i).signmag64());
		(*net_signals)["INVERTER_R_RCV"]["warn_warning_0"].push(pack->inverter_r_rcv(i).warn_warning_0());
		(*net_signals)["INVERTER_R_RCV"]["ain_in_1_scaled213"].push(pack->inverter_r_rcv(i).ain_in_1_scaled213());
		(*net_signals)["INVERTER_R_RCV"]["ain_in_2_scaled214"].push(pack->inverter_r_rcv(i).ain_in_2_scaled214());
		(*net_signals)["INVERTER_R_RCV"]["t_dc__stop"].push(pack->inverter_r_rcv(i).t_dc__stop());
		(*net_signals)["INVERTER_R_RCV"]["v_dc__stop"].push(pack->inverter_r_rcv(i).v_dc__stop());
		(*net_signals)["INVERTER_R_RCV"]["v_min__stop"].push(pack->inverter_r_rcv(i).v_min__stop());
		(*net_signals)["INVERTER_R_RCV"]["f_min__stop"].push(pack->inverter_r_rcv(i).f_min__stop());
		(*net_signals)["INVERTER_R_RCV"]["v_corner__stop"].push(pack->inverter_r_rcv(i).v_corner__stop());
		(*net_signals)["INVERTER_R_RCV"]["f_corner__stop"].push(pack->inverter_r_rcv(i).f_corner__stop());
		(*net_signals)["INVERTER_R_RCV"]["pid_i__kp__id"].push(pack->inverter_r_rcv(i).pid_i__kp__id());
		(*net_signals)["INVERTER_R_RCV"]["pid_i__ti__id"].push(pack->inverter_r_rcv(i).pid_i__ti__id());
		(*net_signals)["INVERTER_R_RCV"]["pid_i__tim__id"].push(pack->inverter_r_rcv(i).pid_i__tim__id());
		(*net_signals)["INVERTER_R_RCV"]["ain_in_1_scaleval"].push(pack->inverter_r_rcv(i).ain_in_1_scaleval());
		(*net_signals)["INVERTER_R_RCV"]["ain_in_2_scaleval"].push(pack->inverter_r_rcv(i).ain_in_2_scaleval());
		(*net_signals)["INVERTER_R_RCV"]["signmag82"].push(pack->inverter_r_rcv(i).signmag82());
		(*net_signals)["INVERTER_R_RCV"]["regen_r"].push(pack->inverter_r_rcv(i).regen_r());
		(*net_signals)["INVERTER_R_RCV"]["dc_bus_max_lim"].push(pack->inverter_r_rcv(i).dc_bus_max_lim());
		(*net_signals)["INVERTER_R_RCV"]["pid_i__xkp__id"].push(pack->inverter_r_rcv(i).pid_i__xkp__id());
		(*net_signals)["INVERTER_R_RCV"]["bat_opr_limit__gen"].push(pack->inverter_r_rcv(i).bat_opr_limit__gen());
		(*net_signals)["INVERTER_R_RCV"]["pid_i__kf__id"].push(pack->inverter_r_rcv(i).pid_i__kf__id());
		(*net_signals)["INVERTER_R_RCV"]["cmc__bit17_16__checkipeak_config"].push(pack->inverter_r_rcv(i).cmc__bit17_16__checkipeak_config());
		(*net_signals)["INVERTER_R_RCV"]["dup__bit16__bamobil3_2_offcrct"].push(pack->inverter_r_rcv(i).dup__bit16__bamobil3_2_offcrct());
		(*net_signals)["INVERTER_R_RCV"]["special__stop"].push(pack->inverter_r_rcv(i).special__stop());
		(*net_signals)["INVERTER_R_RCV"]["free"].push(pack->inverter_r_rcv(i).free());
		(*net_signals)["INVERTER_R_RCV"]["svnrevision_nr"].push(pack->inverter_r_rcv(i).svnrevision_nr());
		(*net_signals)["INVERTER_R_RCV"]["ramp4"].push(pack->inverter_r_rcv(i).ramp4());
		(*net_signals)["INVERTER_R_RCV"]["nclip64"].push(pack->inverter_r_rcv(i).nclip64());
		(*net_signals)["INVERTER_R_RCV"]["warn_illegal_status"].push(pack->inverter_r_rcv(i).warn_illegal_status());
		(*net_signals)["INVERTER_R_RCV"]["nclip82"].push(pack->inverter_r_rcv(i).nclip82());
		(*net_signals)["INVERTER_R_RCV"]["dup__bit19_17__ecode_redefine"].push(pack->inverter_r_rcv(i).dup__bit19_17__ecode_redefine());
		(*net_signals)["INVERTER_R_RCV"]["motbrake"].push(pack->inverter_r_rcv(i).motbrake());
		(*net_signals)["INVERTER_R_RCV"]["nclip_minus64"].push(pack->inverter_r_rcv(i).nclip_minus64());
		(*net_signals)["INVERTER_R_RCV"]["warn_safe_in"].push(pack->inverter_r_rcv(i).warn_safe_in());
		(*net_signals)["INVERTER_R_RCV"]["nclip_minus82"].push(pack->inverter_r_rcv(i).nclip_minus82());
		(*net_signals)["INVERTER_R_RCV"]["cmc__bit18__tractioncontrol_ena"].push(pack->inverter_r_rcv(i).cmc__bit18__tractioncontrol_ena());
		(*net_signals)["INVERTER_R_RCV"]["ac_dc"].push(pack->inverter_r_rcv(i).ac_dc());
		(*net_signals)["INVERTER_R_RCV"]["nclip_plus64"].push(pack->inverter_r_rcv(i).nclip_plus64());
		(*net_signals)["INVERTER_R_RCV"]["nclip_plus82"].push(pack->inverter_r_rcv(i).nclip_plus82());
		(*net_signals)["INVERTER_R_RCV"]["cmc__bit20_19__tc_deltatime_conf"].push(pack->inverter_r_rcv(i).cmc__bit20_19__tc_deltatime_conf());
		(*net_signals)["INVERTER_R_RCV"]["pwm_freq"].push(pack->inverter_r_rcv(i).pwm_freq());
		(*net_signals)["INVERTER_R_RCV"]["irddig64"].push(pack->inverter_r_rcv(i).irddig64());
		(*net_signals)["INVERTER_R_RCV"]["irddig82"].push(pack->inverter_r_rcv(i).irddig82());
		(*net_signals)["INVERTER_R_RCV"]["dup__bit20__hal_extmr_acv"].push(pack->inverter_r_rcv(i).dup__bit20__hal_extmr_acv());
		(*net_signals)["INVERTER_R_RCV"]["iuserchd64"].push(pack->inverter_r_rcv(i).iuserchd64());
		(*net_signals)["INVERTER_R_RCV"]["iuserchd82"].push(pack->inverter_r_rcv(i).iuserchd82());
		(*net_signals)["INVERTER_R_RCV"]["cmc__bit22_21__tc_minspeed_conf"].push(pack->inverter_r_rcv(i).cmc__bit22_21__tc_minspeed_conf());
		(*net_signals)["INVERTER_R_RCV"]["dup__bit21__initwith_frg_off"].push(pack->inverter_r_rcv(i).dup__bit21__initwith_frg_off());
		(*net_signals)["INVERTER_R_RCV"]["irdn64"].push(pack->inverter_r_rcv(i).irdn64());
		(*net_signals)["INVERTER_R_RCV"]["warn_motortemp"].push(pack->inverter_r_rcv(i).warn_motortemp());
		(*net_signals)["INVERTER_R_RCV"]["irdn82"].push(pack->inverter_r_rcv(i).irdn82());
		(*net_signals)["INVERTER_R_RCV"]["dup__bit31_22__free"].push(pack->inverter_r_rcv(i).dup__bit31_22__free());
		(*net_signals)["INVERTER_R_RCV"]["ntc"].push(pack->inverter_r_rcv(i).ntc());
		(*net_signals)["INVERTER_R_RCV"]["irdti64"].push(pack->inverter_r_rcv(i).irdti64());
		(*net_signals)["INVERTER_R_RCV"]["warn_devicetemp"].push(pack->inverter_r_rcv(i).warn_devicetemp());
		(*net_signals)["INVERTER_R_RCV"]["irdti82"].push(pack->inverter_r_rcv(i).irdti82());
		(*net_signals)["INVERTER_R_RCV"]["cmc__bit23__tc_ncmdrestoption"].push(pack->inverter_r_rcv(i).cmc__bit23__tc_ncmdrestoption());
		(*net_signals)["INVERTER_R_RCV"]["m_r_acc"].push(pack->inverter_r_rcv(i).m_r_acc());
		(*net_signals)["INVERTER_R_RCV"]["delta"].push(pack->inverter_r_rcv(i).delta());
		(*net_signals)["INVERTER_R_RCV"]["irdtir64"].push(pack->inverter_r_rcv(i).irdtir64());
		(*net_signals)["INVERTER_R_RCV"]["warn_vout_sat"].push(pack->inverter_r_rcv(i).warn_vout_sat());
		(*net_signals)["INVERTER_R_RCV"]["irdtir82"].push(pack->inverter_r_rcv(i).irdtir82());
		(*net_signals)["INVERTER_R_RCV"]["cmc__bit31_24__free"].push(pack->inverter_r_rcv(i).cmc__bit31_24__free());
		(*net_signals)["INVERTER_R_RCV"]["dc_1qdirvolt"].push(pack->inverter_r_rcv(i).dc_1qdirvolt());
		(*net_signals)["INVERTER_R_RCV"]["_10hz64"].push(pack->inverter_r_rcv(i)._10hz64());
		(*net_signals)["INVERTER_R_RCV"]["warn_ipeak"].push(pack->inverter_r_rcv(i).warn_ipeak());
		(*net_signals)["INVERTER_R_RCV"]["_10hz82"].push(pack->inverter_r_rcv(i)._10hz82());
		(*net_signals)["INVERTER_R_RCV"]["dc_field"].push(pack->inverter_r_rcv(i).dc_field());
		(*net_signals)["INVERTER_R_RCV"]["irdtm64"].push(pack->inverter_r_rcv(i).irdtm64());
		(*net_signals)["INVERTER_R_RCV"]["warn_raceaway"].push(pack->inverter_r_rcv(i).warn_raceaway());
		(*net_signals)["INVERTER_R_RCV"]["irdtm82"].push(pack->inverter_r_rcv(i).irdtm82());
		(*net_signals)["INVERTER_R_RCV"]["dead_2"].push(pack->inverter_r_rcv(i).dead_2());
		(*net_signals)["INVERTER_R_RCV"]["irdana64"].push(pack->inverter_r_rcv(i).irdana64());
		(*net_signals)["INVERTER_R_RCV"]["irdana82"].push(pack->inverter_r_rcv(i).irdana82());
		(*net_signals)["INVERTER_R_RCV"]["block"].push(pack->inverter_r_rcv(i).block());
		(*net_signals)["INVERTER_R_RCV"]["iwcns64"].push(pack->inverter_r_rcv(i).iwcns64());
		(*net_signals)["INVERTER_R_RCV"]["iwcns82"].push(pack->inverter_r_rcv(i).iwcns82());
		(*net_signals)["INVERTER_R_RCV"]["dc_1qmv"].push(pack->inverter_r_rcv(i).dc_1qmv());
		(*net_signals)["INVERTER_R_RCV"]["rfepulse64"].push(pack->inverter_r_rcv(i).rfepulse64());
		(*net_signals)["INVERTER_R_RCV"]["rfepulse82"].push(pack->inverter_r_rcv(i).rfepulse82());
		(*net_signals)["INVERTER_R_RCV"]["dc_1q3p"].push(pack->inverter_r_rcv(i).dc_1q3p());
		(*net_signals)["INVERTER_R_RCV"]["md64"].push(pack->inverter_r_rcv(i).md64());
		(*net_signals)["INVERTER_R_RCV"]["md82"].push(pack->inverter_r_rcv(i).md82());
		(*net_signals)["INVERTER_R_RCV"]["reducelosses"].push(pack->inverter_r_rcv(i).reducelosses());
		(*net_signals)["INVERTER_R_RCV"]["hndwhl64"].push(pack->inverter_r_rcv(i).hndwhl64());
		(*net_signals)["INVERTER_R_RCV"]["warn_ballast"].push(pack->inverter_r_rcv(i).warn_ballast());
		(*net_signals)["INVERTER_R_RCV"]["hndwhl82"].push(pack->inverter_r_rcv(i).hndwhl82());

    }

    for(int i = 0; i < pack->bms_hv_jmp_to_blt_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->bms_hv_jmp_to_blt(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->bms_hv_jmp_to_blt(i)._inner_timestamp();
        (*net_signals)["BMS_HV_JMP_TO_BLT"]["_timestamp"].push(pack->bms_hv_jmp_to_blt(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->bms_lv_jmp_to_blt_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->bms_lv_jmp_to_blt(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->bms_lv_jmp_to_blt(i)._inner_timestamp();
        (*net_signals)["BMS_LV_JMP_TO_BLT"]["_timestamp"].push(pack->bms_lv_jmp_to_blt(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->steer_version_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->steer_version(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->steer_version(i)._inner_timestamp();
        (*net_signals)["STEER_VERSION"]["_timestamp"].push(pack->steer_version(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["STEER_VERSION"]["component_version"].push(pack->steer_version(i).component_version());
		(*net_signals)["STEER_VERSION"]["canlib_build_time"].push(pack->steer_version(i).canlib_build_time());

    }

    for(int i = 0; i < pack->das_version_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->das_version(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->das_version(i)._inner_timestamp();
        (*net_signals)["DAS_VERSION"]["_timestamp"].push(pack->das_version(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["DAS_VERSION"]["component_version"].push(pack->das_version(i).component_version());
		(*net_signals)["DAS_VERSION"]["canlib_build_time"].push(pack->das_version(i).canlib_build_time());

    }

    for(int i = 0; i < pack->hv_version_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_version(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_version(i)._inner_timestamp();
        (*net_signals)["HV_VERSION"]["_timestamp"].push(pack->hv_version(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["HV_VERSION"]["component_version"].push(pack->hv_version(i).component_version());
		(*net_signals)["HV_VERSION"]["canlib_build_time"].push(pack->hv_version(i).canlib_build_time());

    }

    for(int i = 0; i < pack->lv_version_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->lv_version(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->lv_version(i)._inner_timestamp();
        (*net_signals)["LV_VERSION"]["_timestamp"].push(pack->lv_version(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["LV_VERSION"]["component_version"].push(pack->lv_version(i).component_version());
		(*net_signals)["LV_VERSION"]["canlib_build_time"].push(pack->lv_version(i).canlib_build_time());

    }

    for(int i = 0; i < pack->tlm_version_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->tlm_version(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->tlm_version(i)._inner_timestamp();
        (*net_signals)["TLM_VERSION"]["_timestamp"].push(pack->tlm_version(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["TLM_VERSION"]["component_version"].push(pack->tlm_version(i).component_version());
		(*net_signals)["TLM_VERSION"]["canlib_build_time"].push(pack->tlm_version(i).canlib_build_time());

    }

    for(int i = 0; i < pack->timestamp_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->timestamp(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->timestamp(i)._inner_timestamp();
        (*net_signals)["TIMESTAMP"]["_timestamp"].push(pack->timestamp(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["TIMESTAMP"]["timestamp"].push(pack->timestamp(i).timestamp());

    }

    for(int i = 0; i < pack->ambient_temperature_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->ambient_temperature(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->ambient_temperature(i)._inner_timestamp();
        (*net_signals)["AMBIENT_TEMPERATURE"]["_timestamp"].push(pack->ambient_temperature(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["AMBIENT_TEMPERATURE"]["temp"].push(pack->ambient_temperature(i).temp());

    }

    for(int i = 0; i < pack->data_logger_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->data_logger(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->data_logger(i)._inner_timestamp();
        (*net_signals)["DATA_LOGGER"]["_timestamp"].push(pack->data_logger(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["DATA_LOGGER"]["placeholder1"].push(pack->data_logger(i).placeholder1());
		(*net_signals)["DATA_LOGGER"]["placeholder2"].push(pack->data_logger(i).placeholder2());

    }

    for(int i = 0; i < pack->set_tlm_status_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->set_tlm_status(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->set_tlm_status(i)._inner_timestamp();
        (*net_signals)["SET_TLM_STATUS"]["_timestamp"].push(pack->set_tlm_status(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["SET_TLM_STATUS"]["tlm_status"].push(pack->set_tlm_status(i).tlm_status());
		primary_set_tlm_status_tlm_status_enum_to_string((primary_set_tlm_status_tlm_status)pack->set_tlm_status(i).tlm_status(), buffer);
		(*net_strings)["SET_TLM_STATUS"]["tlm_status"].push(buffer);

    }

    for(int i = 0; i < pack->tlm_status_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->tlm_status(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->tlm_status(i)._inner_timestamp();
        (*net_signals)["TLM_STATUS"]["_timestamp"].push(pack->tlm_status(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["TLM_STATUS"]["tlm_status"].push(pack->tlm_status(i).tlm_status());
		primary_tlm_status_tlm_status_enum_to_string((primary_tlm_status_tlm_status)pack->tlm_status(i).tlm_status(), buffer);
		(*net_strings)["TLM_STATUS"]["tlm_status"].push(buffer);

    }

    for(int i = 0; i < pack->steer_system_status_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->steer_system_status(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->steer_system_status(i)._inner_timestamp();
        (*net_signals)["STEER_SYSTEM_STATUS"]["_timestamp"].push(pack->steer_system_status(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["STEER_SYSTEM_STATUS"]["soc_temp"].push(pack->steer_system_status(i).soc_temp());

    }

    for(int i = 0; i < pack->hv_voltage_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_voltage(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_voltage(i)._inner_timestamp();
        (*net_signals)["HV_VOLTAGE"]["_timestamp"].push(pack->hv_voltage(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["HV_VOLTAGE"]["pack_voltage"].push(pack->hv_voltage(i).pack_voltage());
		(*net_signals)["HV_VOLTAGE"]["bus_voltage"].push(pack->hv_voltage(i).bus_voltage());
		(*net_signals)["HV_VOLTAGE"]["max_cell_voltage"].push(pack->hv_voltage(i).max_cell_voltage());
		(*net_signals)["HV_VOLTAGE"]["min_cell_voltage"].push(pack->hv_voltage(i).min_cell_voltage());

    }

    for(int i = 0; i < pack->hv_current_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_current(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_current(i)._inner_timestamp();
        (*net_signals)["HV_CURRENT"]["_timestamp"].push(pack->hv_current(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["HV_CURRENT"]["current"].push(pack->hv_current(i).current());
		(*net_signals)["HV_CURRENT"]["power"].push(pack->hv_current(i).power());
		(*net_signals)["HV_CURRENT"]["energy"].push(pack->hv_current(i).energy());
		(*net_signals)["HV_CURRENT"]["soc"].push(pack->hv_current(i).soc());

    }

    for(int i = 0; i < pack->hv_temp_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_temp(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_temp(i)._inner_timestamp();
        (*net_signals)["HV_TEMP"]["_timestamp"].push(pack->hv_temp(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["HV_TEMP"]["average_temp"].push(pack->hv_temp(i).average_temp());
		(*net_signals)["HV_TEMP"]["max_temp"].push(pack->hv_temp(i).max_temp());
		(*net_signals)["HV_TEMP"]["min_temp"].push(pack->hv_temp(i).min_temp());

    }

    for(int i = 0; i < pack->hv_errors_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_errors(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_errors(i)._inner_timestamp();
        (*net_signals)["HV_ERRORS"]["_timestamp"].push(pack->hv_errors(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["HV_ERRORS"]["warnings_cell_low_voltage"].push(pack->hv_errors(i).warnings_cell_low_voltage());
		(*net_signals)["HV_ERRORS"]["warnings_cell_under_voltage"].push(pack->hv_errors(i).warnings_cell_under_voltage());
		(*net_signals)["HV_ERRORS"]["warnings_cell_over_voltage"].push(pack->hv_errors(i).warnings_cell_over_voltage());
		(*net_signals)["HV_ERRORS"]["warnings_cell_high_temperature"].push(pack->hv_errors(i).warnings_cell_high_temperature());
		(*net_signals)["HV_ERRORS"]["warnings_cell_over_temperature"].push(pack->hv_errors(i).warnings_cell_over_temperature());
		(*net_signals)["HV_ERRORS"]["warnings_over_current"].push(pack->hv_errors(i).warnings_over_current());
		(*net_signals)["HV_ERRORS"]["warnings_can"].push(pack->hv_errors(i).warnings_can());
		(*net_signals)["HV_ERRORS"]["warnings_int_voltage_mismatch"].push(pack->hv_errors(i).warnings_int_voltage_mismatch());
		(*net_signals)["HV_ERRORS"]["warnings_cellboard_comm"].push(pack->hv_errors(i).warnings_cellboard_comm());
		(*net_signals)["HV_ERRORS"]["warnings_cellboard_internal"].push(pack->hv_errors(i).warnings_cellboard_internal());
		(*net_signals)["HV_ERRORS"]["warnings_feedback"].push(pack->hv_errors(i).warnings_feedback());
		(*net_signals)["HV_ERRORS"]["warnings_feedback_circuitry"].push(pack->hv_errors(i).warnings_feedback_circuitry());
		(*net_signals)["HV_ERRORS"]["warnings_eeprom_comm"].push(pack->hv_errors(i).warnings_eeprom_comm());
		(*net_signals)["HV_ERRORS"]["warnings_eeprom_write"].push(pack->hv_errors(i).warnings_eeprom_write());
		(*net_signals)["HV_ERRORS"]["errors_cell_low_voltage"].push(pack->hv_errors(i).errors_cell_low_voltage());
		(*net_signals)["HV_ERRORS"]["errors_cell_under_voltage"].push(pack->hv_errors(i).errors_cell_under_voltage());
		(*net_signals)["HV_ERRORS"]["errors_cell_over_voltage"].push(pack->hv_errors(i).errors_cell_over_voltage());
		(*net_signals)["HV_ERRORS"]["errors_cell_high_temperature"].push(pack->hv_errors(i).errors_cell_high_temperature());
		(*net_signals)["HV_ERRORS"]["errors_cell_over_temperature"].push(pack->hv_errors(i).errors_cell_over_temperature());
		(*net_signals)["HV_ERRORS"]["errors_over_current"].push(pack->hv_errors(i).errors_over_current());
		(*net_signals)["HV_ERRORS"]["errors_can"].push(pack->hv_errors(i).errors_can());
		(*net_signals)["HV_ERRORS"]["errors_int_voltage_mismatch"].push(pack->hv_errors(i).errors_int_voltage_mismatch());
		(*net_signals)["HV_ERRORS"]["errors_cellboard_comm"].push(pack->hv_errors(i).errors_cellboard_comm());
		(*net_signals)["HV_ERRORS"]["errors_cellboard_internal"].push(pack->hv_errors(i).errors_cellboard_internal());
		(*net_signals)["HV_ERRORS"]["errors_feedback"].push(pack->hv_errors(i).errors_feedback());
		(*net_signals)["HV_ERRORS"]["errors_feedback_circuitry"].push(pack->hv_errors(i).errors_feedback_circuitry());
		(*net_signals)["HV_ERRORS"]["errors_eeprom_comm"].push(pack->hv_errors(i).errors_eeprom_comm());
		(*net_signals)["HV_ERRORS"]["errors_eeprom_write"].push(pack->hv_errors(i).errors_eeprom_write());

    }

    for(int i = 0; i < pack->hv_can_forward_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_can_forward(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_can_forward(i)._inner_timestamp();
        (*net_signals)["HV_CAN_FORWARD"]["_timestamp"].push(pack->hv_can_forward(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["HV_CAN_FORWARD"]["can_forward_set"].push(pack->hv_can_forward(i).can_forward_set());
		primary_hv_can_forward_can_forward_set_enum_to_string((primary_hv_can_forward_can_forward_set)pack->hv_can_forward(i).can_forward_set(), buffer);
		(*net_strings)["HV_CAN_FORWARD"]["can_forward_set"].push(buffer);

    }

    for(int i = 0; i < pack->hv_fans_override_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_fans_override(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_fans_override(i)._inner_timestamp();
        (*net_signals)["HV_FANS_OVERRIDE"]["_timestamp"].push(pack->hv_fans_override(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["HV_FANS_OVERRIDE"]["fans_override"].push(pack->hv_fans_override(i).fans_override());
		primary_hv_fans_override_fans_override_enum_to_string((primary_hv_fans_override_fans_override)pack->hv_fans_override(i).fans_override(), buffer);
		(*net_strings)["HV_FANS_OVERRIDE"]["fans_override"].push(buffer);
		(*net_signals)["HV_FANS_OVERRIDE"]["fans_speed"].push(pack->hv_fans_override(i).fans_speed());

    }

    for(int i = 0; i < pack->hv_can_forward_status_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_can_forward_status(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_can_forward_status(i)._inner_timestamp();
        (*net_signals)["HV_CAN_FORWARD_STATUS"]["_timestamp"].push(pack->hv_can_forward_status(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["HV_CAN_FORWARD_STATUS"]["can_forward_status"].push(pack->hv_can_forward_status(i).can_forward_status());
		primary_hv_can_forward_status_can_forward_status_enum_to_string((primary_hv_can_forward_status_can_forward_status)pack->hv_can_forward_status(i).can_forward_status(), buffer);
		(*net_strings)["HV_CAN_FORWARD_STATUS"]["can_forward_status"].push(buffer);

    }

    for(int i = 0; i < pack->hv_fans_override_status_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_fans_override_status(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_fans_override_status(i)._inner_timestamp();
        (*net_signals)["HV_FANS_OVERRIDE_STATUS"]["_timestamp"].push(pack->hv_fans_override_status(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["HV_FANS_OVERRIDE_STATUS"]["fans_override"].push(pack->hv_fans_override_status(i).fans_override());
		primary_hv_fans_override_status_fans_override_enum_to_string((primary_hv_fans_override_status_fans_override)pack->hv_fans_override_status(i).fans_override(), buffer);
		(*net_strings)["HV_FANS_OVERRIDE_STATUS"]["fans_override"].push(buffer);
		(*net_signals)["HV_FANS_OVERRIDE_STATUS"]["fans_speed"].push(pack->hv_fans_override_status(i).fans_speed());

    }

    for(int i = 0; i < pack->hv_feedbacks_status_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_feedbacks_status(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_feedbacks_status(i)._inner_timestamp();
        (*net_signals)["HV_FEEDBACKS_STATUS"]["_timestamp"].push(pack->hv_feedbacks_status(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["HV_FEEDBACKS_STATUS"]["feedbacks_status_feedback_tsal_green_fault"].push(pack->hv_feedbacks_status(i).feedbacks_status_feedback_tsal_green_fault());
		(*net_signals)["HV_FEEDBACKS_STATUS"]["feedbacks_status_feedback_imd_latched"].push(pack->hv_feedbacks_status(i).feedbacks_status_feedback_imd_latched());
		(*net_signals)["HV_FEEDBACKS_STATUS"]["feedbacks_status_feedback_tsal_green_fault_latched"].push(pack->hv_feedbacks_status(i).feedbacks_status_feedback_tsal_green_fault_latched());
		(*net_signals)["HV_FEEDBACKS_STATUS"]["feedbacks_status_feedback_bms_latched"].push(pack->hv_feedbacks_status(i).feedbacks_status_feedback_bms_latched());
		(*net_signals)["HV_FEEDBACKS_STATUS"]["feedbacks_status_feedback_ext_latched"].push(pack->hv_feedbacks_status(i).feedbacks_status_feedback_ext_latched());
		(*net_signals)["HV_FEEDBACKS_STATUS"]["feedbacks_status_feedback_tsal_green"].push(pack->hv_feedbacks_status(i).feedbacks_status_feedback_tsal_green());
		(*net_signals)["HV_FEEDBACKS_STATUS"]["feedbacks_status_feedback_ts_over_60v_status"].push(pack->hv_feedbacks_status(i).feedbacks_status_feedback_ts_over_60v_status());
		(*net_signals)["HV_FEEDBACKS_STATUS"]["feedbacks_status_feedback_airn_status"].push(pack->hv_feedbacks_status(i).feedbacks_status_feedback_airn_status());
		(*net_signals)["HV_FEEDBACKS_STATUS"]["feedbacks_status_feedback_airp_status"].push(pack->hv_feedbacks_status(i).feedbacks_status_feedback_airp_status());
		(*net_signals)["HV_FEEDBACKS_STATUS"]["feedbacks_status_feedback_airp_gate"].push(pack->hv_feedbacks_status(i).feedbacks_status_feedback_airp_gate());
		(*net_signals)["HV_FEEDBACKS_STATUS"]["feedbacks_status_feedback_airn_gate"].push(pack->hv_feedbacks_status(i).feedbacks_status_feedback_airn_gate());
		(*net_signals)["HV_FEEDBACKS_STATUS"]["feedbacks_status_feedback_precharge_status"].push(pack->hv_feedbacks_status(i).feedbacks_status_feedback_precharge_status());
		(*net_signals)["HV_FEEDBACKS_STATUS"]["feedbacks_status_feedback_tsp_over_60v_status"].push(pack->hv_feedbacks_status(i).feedbacks_status_feedback_tsp_over_60v_status());
		(*net_signals)["HV_FEEDBACKS_STATUS"]["feedbacks_status_feedback_check_mux"].push(pack->hv_feedbacks_status(i).feedbacks_status_feedback_check_mux());
		(*net_signals)["HV_FEEDBACKS_STATUS"]["feedbacks_status_feedback_sd_in"].push(pack->hv_feedbacks_status(i).feedbacks_status_feedback_sd_in());
		(*net_signals)["HV_FEEDBACKS_STATUS"]["feedbacks_status_feedback_sd_out"].push(pack->hv_feedbacks_status(i).feedbacks_status_feedback_sd_out());
		(*net_signals)["HV_FEEDBACKS_STATUS"]["feedbacks_status_feedback_relay_sd"].push(pack->hv_feedbacks_status(i).feedbacks_status_feedback_relay_sd());
		(*net_signals)["HV_FEEDBACKS_STATUS"]["feedbacks_status_feedback_imd_fault"].push(pack->hv_feedbacks_status(i).feedbacks_status_feedback_imd_fault());
		(*net_signals)["HV_FEEDBACKS_STATUS"]["feedbacks_status_feedback_sd_end"].push(pack->hv_feedbacks_status(i).feedbacks_status_feedback_sd_end());
		(*net_signals)["HV_FEEDBACKS_STATUS"]["is_circuitry_error_feedback_tsal_green_fault"].push(pack->hv_feedbacks_status(i).is_circuitry_error_feedback_tsal_green_fault());
		(*net_signals)["HV_FEEDBACKS_STATUS"]["is_circuitry_error_feedback_imd_latched"].push(pack->hv_feedbacks_status(i).is_circuitry_error_feedback_imd_latched());
		(*net_signals)["HV_FEEDBACKS_STATUS"]["is_circuitry_error_feedback_tsal_green_fault_latched"].push(pack->hv_feedbacks_status(i).is_circuitry_error_feedback_tsal_green_fault_latched());
		(*net_signals)["HV_FEEDBACKS_STATUS"]["is_circuitry_error_feedback_bms_latched"].push(pack->hv_feedbacks_status(i).is_circuitry_error_feedback_bms_latched());
		(*net_signals)["HV_FEEDBACKS_STATUS"]["is_circuitry_error_feedback_ext_latched"].push(pack->hv_feedbacks_status(i).is_circuitry_error_feedback_ext_latched());
		(*net_signals)["HV_FEEDBACKS_STATUS"]["is_circuitry_error_feedback_tsal_green"].push(pack->hv_feedbacks_status(i).is_circuitry_error_feedback_tsal_green());
		(*net_signals)["HV_FEEDBACKS_STATUS"]["is_circuitry_error_feedback_ts_over_60v_status"].push(pack->hv_feedbacks_status(i).is_circuitry_error_feedback_ts_over_60v_status());
		(*net_signals)["HV_FEEDBACKS_STATUS"]["is_circuitry_error_feedback_airn_status"].push(pack->hv_feedbacks_status(i).is_circuitry_error_feedback_airn_status());
		(*net_signals)["HV_FEEDBACKS_STATUS"]["is_circuitry_error_feedback_airp_status"].push(pack->hv_feedbacks_status(i).is_circuitry_error_feedback_airp_status());
		(*net_signals)["HV_FEEDBACKS_STATUS"]["is_circuitry_error_feedback_airp_gate"].push(pack->hv_feedbacks_status(i).is_circuitry_error_feedback_airp_gate());
		(*net_signals)["HV_FEEDBACKS_STATUS"]["is_circuitry_error_feedback_airn_gate"].push(pack->hv_feedbacks_status(i).is_circuitry_error_feedback_airn_gate());
		(*net_signals)["HV_FEEDBACKS_STATUS"]["is_circuitry_error_feedback_precharge_status"].push(pack->hv_feedbacks_status(i).is_circuitry_error_feedback_precharge_status());
		(*net_signals)["HV_FEEDBACKS_STATUS"]["is_circuitry_error_feedback_tsp_over_60v_status"].push(pack->hv_feedbacks_status(i).is_circuitry_error_feedback_tsp_over_60v_status());
		(*net_signals)["HV_FEEDBACKS_STATUS"]["is_circuitry_error_feedback_check_mux"].push(pack->hv_feedbacks_status(i).is_circuitry_error_feedback_check_mux());
		(*net_signals)["HV_FEEDBACKS_STATUS"]["is_circuitry_error_feedback_sd_in"].push(pack->hv_feedbacks_status(i).is_circuitry_error_feedback_sd_in());
		(*net_signals)["HV_FEEDBACKS_STATUS"]["is_circuitry_error_feedback_sd_out"].push(pack->hv_feedbacks_status(i).is_circuitry_error_feedback_sd_out());
		(*net_signals)["HV_FEEDBACKS_STATUS"]["is_circuitry_error_feedback_relay_sd"].push(pack->hv_feedbacks_status(i).is_circuitry_error_feedback_relay_sd());
		(*net_signals)["HV_FEEDBACKS_STATUS"]["is_circuitry_error_feedback_imd_fault"].push(pack->hv_feedbacks_status(i).is_circuitry_error_feedback_imd_fault());
		(*net_signals)["HV_FEEDBACKS_STATUS"]["is_circuitry_error_feedback_sd_end"].push(pack->hv_feedbacks_status(i).is_circuitry_error_feedback_sd_end());

    }

    for(int i = 0; i < pack->hv_imd_status_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_imd_status(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_imd_status(i)._inner_timestamp();
        (*net_signals)["HV_IMD_STATUS"]["_timestamp"].push(pack->hv_imd_status(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["HV_IMD_STATUS"]["imd_fault"].push(pack->hv_imd_status(i).imd_fault());
		(*net_enums)["HV_IMD_STATUS"]["imd_status"].push(pack->hv_imd_status(i).imd_status());
		primary_hv_imd_status_imd_status_enum_to_string((primary_hv_imd_status_imd_status)pack->hv_imd_status(i).imd_status(), buffer);
		(*net_strings)["HV_IMD_STATUS"]["imd_status"].push(buffer);
		(*net_signals)["HV_IMD_STATUS"]["imd_info"].push(pack->hv_imd_status(i).imd_info());

    }

    for(int i = 0; i < pack->ts_status_das_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->ts_status_das(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->ts_status_das(i)._inner_timestamp();
        (*net_signals)["TS_STATUS_DAS"]["_timestamp"].push(pack->ts_status_das(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["TS_STATUS_DAS"]["ts_status"].push(pack->ts_status_das(i).ts_status());
		primary_ts_status_das_ts_status_enum_to_string((primary_ts_status_das_ts_status)pack->ts_status_das(i).ts_status(), buffer);
		(*net_strings)["TS_STATUS_DAS"]["ts_status"].push(buffer);

    }

    for(int i = 0; i < pack->ts_status_steer_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->ts_status_steer(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->ts_status_steer(i)._inner_timestamp();
        (*net_signals)["TS_STATUS_STEER"]["_timestamp"].push(pack->ts_status_steer(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["TS_STATUS_STEER"]["ts_status"].push(pack->ts_status_steer(i).ts_status());
		primary_ts_status_steer_ts_status_enum_to_string((primary_ts_status_steer_ts_status)pack->ts_status_steer(i).ts_status(), buffer);
		(*net_strings)["TS_STATUS_STEER"]["ts_status"].push(buffer);

    }

    for(int i = 0; i < pack->ts_status_handcart_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->ts_status_handcart(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->ts_status_handcart(i)._inner_timestamp();
        (*net_signals)["TS_STATUS_HANDCART"]["_timestamp"].push(pack->ts_status_handcart(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["TS_STATUS_HANDCART"]["ts_status"].push(pack->ts_status_handcart(i).ts_status());
		primary_ts_status_handcart_ts_status_enum_to_string((primary_ts_status_handcart_ts_status)pack->ts_status_handcart(i).ts_status(), buffer);
		(*net_strings)["TS_STATUS_HANDCART"]["ts_status"].push(buffer);

    }

    for(int i = 0; i < pack->set_ts_status_das_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->set_ts_status_das(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->set_ts_status_das(i)._inner_timestamp();
        (*net_signals)["SET_TS_STATUS_DAS"]["_timestamp"].push(pack->set_ts_status_das(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["SET_TS_STATUS_DAS"]["ts_status_set"].push(pack->set_ts_status_das(i).ts_status_set());
		primary_set_ts_status_das_ts_status_set_enum_to_string((primary_set_ts_status_das_ts_status_set)pack->set_ts_status_das(i).ts_status_set(), buffer);
		(*net_strings)["SET_TS_STATUS_DAS"]["ts_status_set"].push(buffer);

    }

    for(int i = 0; i < pack->set_ts_status_handcart_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->set_ts_status_handcart(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->set_ts_status_handcart(i)._inner_timestamp();
        (*net_signals)["SET_TS_STATUS_HANDCART"]["_timestamp"].push(pack->set_ts_status_handcart(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["SET_TS_STATUS_HANDCART"]["ts_status_set"].push(pack->set_ts_status_handcart(i).ts_status_set());
		primary_set_ts_status_handcart_ts_status_set_enum_to_string((primary_set_ts_status_handcart_ts_status_set)pack->set_ts_status_handcart(i).ts_status_set(), buffer);
		(*net_strings)["SET_TS_STATUS_HANDCART"]["ts_status_set"].push(buffer);

    }

    for(int i = 0; i < pack->steer_status_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->steer_status(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->steer_status(i)._inner_timestamp();
        (*net_signals)["STEER_STATUS"]["_timestamp"].push(pack->steer_status(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["STEER_STATUS"]["map_pw"].push(pack->steer_status(i).map_pw());
		(*net_signals)["STEER_STATUS"]["map_sc"].push(pack->steer_status(i).map_sc());
		(*net_signals)["STEER_STATUS"]["map_tv"].push(pack->steer_status(i).map_tv());

    }

    for(int i = 0; i < pack->set_car_status_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->set_car_status(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->set_car_status(i)._inner_timestamp();
        (*net_signals)["SET_CAR_STATUS"]["_timestamp"].push(pack->set_car_status(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["SET_CAR_STATUS"]["car_status_set"].push(pack->set_car_status(i).car_status_set());
		primary_set_car_status_car_status_set_enum_to_string((primary_set_car_status_car_status_set)pack->set_car_status(i).car_status_set(), buffer);
		(*net_strings)["SET_CAR_STATUS"]["car_status_set"].push(buffer);

    }

    for(int i = 0; i < pack->set_pedals_range_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->set_pedals_range(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->set_pedals_range(i)._inner_timestamp();
        (*net_signals)["SET_PEDALS_RANGE"]["_timestamp"].push(pack->set_pedals_range(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["SET_PEDALS_RANGE"]["bound"].push(pack->set_pedals_range(i).bound());
		primary_set_pedals_range_bound_enum_to_string((primary_set_pedals_range_bound)pack->set_pedals_range(i).bound(), buffer);
		(*net_strings)["SET_PEDALS_RANGE"]["bound"].push(buffer);
		(*net_enums)["SET_PEDALS_RANGE"]["pedal"].push(pack->set_pedals_range(i).pedal());
		primary_set_pedals_range_pedal_enum_to_string((primary_set_pedals_range_pedal)pack->set_pedals_range(i).pedal(), buffer);
		(*net_strings)["SET_PEDALS_RANGE"]["pedal"].push(buffer);

    }

    for(int i = 0; i < pack->set_steering_angle_range_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->set_steering_angle_range(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->set_steering_angle_range(i)._inner_timestamp();
        (*net_signals)["SET_STEERING_ANGLE_RANGE"]["_timestamp"].push(pack->set_steering_angle_range(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["SET_STEERING_ANGLE_RANGE"]["bound"].push(pack->set_steering_angle_range(i).bound());
		primary_set_steering_angle_range_bound_enum_to_string((primary_set_steering_angle_range_bound)pack->set_steering_angle_range(i).bound(), buffer);
		(*net_strings)["SET_STEERING_ANGLE_RANGE"]["bound"].push(buffer);

    }

    for(int i = 0; i < pack->car_status_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->car_status(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->car_status(i)._inner_timestamp();
        (*net_signals)["CAR_STATUS"]["_timestamp"].push(pack->car_status(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["CAR_STATUS"]["inverter_l"].push(pack->car_status(i).inverter_l());
		primary_car_status_inverter_l_enum_to_string((primary_car_status_inverter_l)pack->car_status(i).inverter_l(), buffer);
		(*net_strings)["CAR_STATUS"]["inverter_l"].push(buffer);
		(*net_enums)["CAR_STATUS"]["inverter_r"].push(pack->car_status(i).inverter_r());
		primary_car_status_inverter_r_enum_to_string((primary_car_status_inverter_r)pack->car_status(i).inverter_r(), buffer);
		(*net_strings)["CAR_STATUS"]["inverter_r"].push(buffer);
		(*net_enums)["CAR_STATUS"]["car_status"].push(pack->car_status(i).car_status());
		primary_car_status_car_status_enum_to_string((primary_car_status_car_status)pack->car_status(i).car_status(), buffer);
		(*net_strings)["CAR_STATUS"]["car_status"].push(buffer);

    }

    for(int i = 0; i < pack->das_errors_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->das_errors(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->das_errors(i)._inner_timestamp();
        (*net_signals)["DAS_ERRORS"]["_timestamp"].push(pack->das_errors(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["DAS_ERRORS"]["das_error_pedal_adc"].push(pack->das_errors(i).das_error_pedal_adc());
		(*net_signals)["DAS_ERRORS"]["das_error_pedal_implausibility"].push(pack->das_errors(i).das_error_pedal_implausibility());
		(*net_signals)["DAS_ERRORS"]["das_error_imu_tout"].push(pack->das_errors(i).das_error_imu_tout());
		(*net_signals)["DAS_ERRORS"]["das_error_irts_tout"].push(pack->das_errors(i).das_error_irts_tout());
		(*net_signals)["DAS_ERRORS"]["das_error_ts_tout"].push(pack->das_errors(i).das_error_ts_tout());
		(*net_signals)["DAS_ERRORS"]["das_error_invl_tout"].push(pack->das_errors(i).das_error_invl_tout());
		(*net_signals)["DAS_ERRORS"]["das_error_invr_tout"].push(pack->das_errors(i).das_error_invr_tout());
		(*net_signals)["DAS_ERRORS"]["das_error_steer_tout"].push(pack->das_errors(i).das_error_steer_tout());
		(*net_signals)["DAS_ERRORS"]["das_error_fsm"].push(pack->das_errors(i).das_error_fsm());

    }

    for(int i = 0; i < pack->lv_current_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->lv_current(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->lv_current(i)._inner_timestamp();
        (*net_signals)["LV_CURRENT"]["_timestamp"].push(pack->lv_current(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["LV_CURRENT"]["current"].push(pack->lv_current(i).current());

    }

    for(int i = 0; i < pack->lv_voltage_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->lv_voltage(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->lv_voltage(i)._inner_timestamp();
        (*net_signals)["LV_VOLTAGE"]["_timestamp"].push(pack->lv_voltage(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["LV_VOLTAGE"]["voltage_1"].push(pack->lv_voltage(i).voltage_1());
		(*net_signals)["LV_VOLTAGE"]["voltage_2"].push(pack->lv_voltage(i).voltage_2());
		(*net_signals)["LV_VOLTAGE"]["voltage_3"].push(pack->lv_voltage(i).voltage_3());
		(*net_signals)["LV_VOLTAGE"]["voltage_4"].push(pack->lv_voltage(i).voltage_4());

    }

    for(int i = 0; i < pack->lv_total_voltage_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->lv_total_voltage(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->lv_total_voltage(i)._inner_timestamp();
        (*net_signals)["LV_TOTAL_VOLTAGE"]["_timestamp"].push(pack->lv_total_voltage(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["LV_TOTAL_VOLTAGE"]["total_voltage"].push(pack->lv_total_voltage(i).total_voltage());

    }

    for(int i = 0; i < pack->lv_temperature_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->lv_temperature(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->lv_temperature(i)._inner_timestamp();
        (*net_signals)["LV_TEMPERATURE"]["_timestamp"].push(pack->lv_temperature(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["LV_TEMPERATURE"]["bp_temperature_1"].push(pack->lv_temperature(i).bp_temperature_1());
		(*net_signals)["LV_TEMPERATURE"]["bp_temperature_2"].push(pack->lv_temperature(i).bp_temperature_2());
		(*net_signals)["LV_TEMPERATURE"]["dcdc12_temperature"].push(pack->lv_temperature(i).dcdc12_temperature());
		(*net_signals)["LV_TEMPERATURE"]["dcdc24_temperature"].push(pack->lv_temperature(i).dcdc24_temperature());

    }

    for(int i = 0; i < pack->cooling_status_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->cooling_status(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->cooling_status(i)._inner_timestamp();
        (*net_signals)["COOLING_STATUS"]["_timestamp"].push(pack->cooling_status(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["COOLING_STATUS"]["radiators_speed"].push(pack->cooling_status(i).radiators_speed());
		(*net_signals)["COOLING_STATUS"]["pumps_speed"].push(pack->cooling_status(i).pumps_speed());

    }

    for(int i = 0; i < pack->set_radiator_speed_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->set_radiator_speed(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->set_radiator_speed(i)._inner_timestamp();
        (*net_signals)["SET_RADIATOR_SPEED"]["_timestamp"].push(pack->set_radiator_speed(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["SET_RADIATOR_SPEED"]["radiators_speed"].push(pack->set_radiator_speed(i).radiators_speed());

    }

    for(int i = 0; i < pack->set_pumps_speed_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->set_pumps_speed(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->set_pumps_speed(i)._inner_timestamp();
        (*net_signals)["SET_PUMPS_SPEED"]["_timestamp"].push(pack->set_pumps_speed(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["SET_PUMPS_SPEED"]["pumps_speed"].push(pack->set_pumps_speed(i).pumps_speed());

    }

    for(int i = 0; i < pack->set_inverter_connection_status_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->set_inverter_connection_status(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->set_inverter_connection_status(i)._inner_timestamp();
        (*net_signals)["SET_INVERTER_CONNECTION_STATUS"]["_timestamp"].push(pack->set_inverter_connection_status(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["SET_INVERTER_CONNECTION_STATUS"]["status"].push(pack->set_inverter_connection_status(i).status());
		primary_set_inverter_connection_status_status_enum_to_string((primary_set_inverter_connection_status_status)pack->set_inverter_connection_status(i).status(), buffer);
		(*net_strings)["SET_INVERTER_CONNECTION_STATUS"]["status"].push(buffer);

    }

    for(int i = 0; i < pack->inverter_connection_status_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->inverter_connection_status(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->inverter_connection_status(i)._inner_timestamp();
        (*net_signals)["INVERTER_CONNECTION_STATUS"]["_timestamp"].push(pack->inverter_connection_status(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["INVERTER_CONNECTION_STATUS"]["status"].push(pack->inverter_connection_status(i).status());
		primary_inverter_connection_status_status_enum_to_string((primary_inverter_connection_status_status)pack->inverter_connection_status(i).status(), buffer);
		(*net_strings)["INVERTER_CONNECTION_STATUS"]["status"].push(buffer);

    }

    for(int i = 0; i < pack->lv_errors_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->lv_errors(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->lv_errors(i)._inner_timestamp();
        (*net_signals)["LV_ERRORS"]["_timestamp"].push(pack->lv_errors(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["LV_ERRORS"]["warnings_cell_undervoltage"].push(pack->lv_errors(i).warnings_cell_undervoltage());
		(*net_signals)["LV_ERRORS"]["warnings_cell_overvoltage"].push(pack->lv_errors(i).warnings_cell_overvoltage());
		(*net_signals)["LV_ERRORS"]["warnings_open_wire"].push(pack->lv_errors(i).warnings_open_wire());
		(*net_signals)["LV_ERRORS"]["warnings_can"].push(pack->lv_errors(i).warnings_can());
		(*net_signals)["LV_ERRORS"]["warnings_spi"].push(pack->lv_errors(i).warnings_spi());
		(*net_signals)["LV_ERRORS"]["warnings_over_current"].push(pack->lv_errors(i).warnings_over_current());
		(*net_signals)["LV_ERRORS"]["warnings_dcdc12_under_temperature"].push(pack->lv_errors(i).warnings_dcdc12_under_temperature());
		(*net_signals)["LV_ERRORS"]["warnings_dcdc12_over_temperature"].push(pack->lv_errors(i).warnings_dcdc12_over_temperature());
		(*net_signals)["LV_ERRORS"]["warnings_dcdc24_under_temperature"].push(pack->lv_errors(i).warnings_dcdc24_under_temperature());
		(*net_signals)["LV_ERRORS"]["warnings_dcdc24_over_temperature"].push(pack->lv_errors(i).warnings_dcdc24_over_temperature());
		(*net_signals)["LV_ERRORS"]["warnings_cell_under_temperature"].push(pack->lv_errors(i).warnings_cell_under_temperature());
		(*net_signals)["LV_ERRORS"]["warnings_cell_over_temperature"].push(pack->lv_errors(i).warnings_cell_over_temperature());
		(*net_signals)["LV_ERRORS"]["warnings_relay"].push(pack->lv_errors(i).warnings_relay());
		(*net_signals)["LV_ERRORS"]["warnings_ltc6810"].push(pack->lv_errors(i).warnings_ltc6810());
		(*net_signals)["LV_ERRORS"]["warnings_voltages_not_ready"].push(pack->lv_errors(i).warnings_voltages_not_ready());
		(*net_signals)["LV_ERRORS"]["warnings_mcp23017"].push(pack->lv_errors(i).warnings_mcp23017());
		(*net_signals)["LV_ERRORS"]["warnings_radiator"].push(pack->lv_errors(i).warnings_radiator());
		(*net_signals)["LV_ERRORS"]["warnings_fan"].push(pack->lv_errors(i).warnings_fan());
		(*net_signals)["LV_ERRORS"]["warnings_pump"].push(pack->lv_errors(i).warnings_pump());
		(*net_signals)["LV_ERRORS"]["warnings_adc_init"].push(pack->lv_errors(i).warnings_adc_init());
		(*net_signals)["LV_ERRORS"]["warnings_dcdc12"].push(pack->lv_errors(i).warnings_dcdc12());
		(*net_signals)["LV_ERRORS"]["warnings_dcdc24"].push(pack->lv_errors(i).warnings_dcdc24());
		(*net_signals)["LV_ERRORS"]["errors_cell_undervoltage"].push(pack->lv_errors(i).errors_cell_undervoltage());
		(*net_signals)["LV_ERRORS"]["errors_cell_overvoltage"].push(pack->lv_errors(i).errors_cell_overvoltage());
		(*net_signals)["LV_ERRORS"]["errors_open_wire"].push(pack->lv_errors(i).errors_open_wire());
		(*net_signals)["LV_ERRORS"]["errors_can"].push(pack->lv_errors(i).errors_can());
		(*net_signals)["LV_ERRORS"]["errors_spi"].push(pack->lv_errors(i).errors_spi());
		(*net_signals)["LV_ERRORS"]["errors_over_current"].push(pack->lv_errors(i).errors_over_current());
		(*net_signals)["LV_ERRORS"]["errors_dcdc12_under_temperature"].push(pack->lv_errors(i).errors_dcdc12_under_temperature());
		(*net_signals)["LV_ERRORS"]["errors_dcdc12_over_temperature"].push(pack->lv_errors(i).errors_dcdc12_over_temperature());
		(*net_signals)["LV_ERRORS"]["errors_dcdc24_under_temperature"].push(pack->lv_errors(i).errors_dcdc24_under_temperature());
		(*net_signals)["LV_ERRORS"]["errors_dcdc24_over_temperature"].push(pack->lv_errors(i).errors_dcdc24_over_temperature());
		(*net_signals)["LV_ERRORS"]["errors_cell_under_temperature"].push(pack->lv_errors(i).errors_cell_under_temperature());
		(*net_signals)["LV_ERRORS"]["errors_cell_over_temperature"].push(pack->lv_errors(i).errors_cell_over_temperature());
		(*net_signals)["LV_ERRORS"]["errors_relay"].push(pack->lv_errors(i).errors_relay());
		(*net_signals)["LV_ERRORS"]["errors_ltc6810"].push(pack->lv_errors(i).errors_ltc6810());
		(*net_signals)["LV_ERRORS"]["errors_voltages_not_ready"].push(pack->lv_errors(i).errors_voltages_not_ready());
		(*net_signals)["LV_ERRORS"]["errors_mcp23017"].push(pack->lv_errors(i).errors_mcp23017());
		(*net_signals)["LV_ERRORS"]["errors_radiator"].push(pack->lv_errors(i).errors_radiator());
		(*net_signals)["LV_ERRORS"]["errors_fan"].push(pack->lv_errors(i).errors_fan());
		(*net_signals)["LV_ERRORS"]["errors_pump"].push(pack->lv_errors(i).errors_pump());
		(*net_signals)["LV_ERRORS"]["errors_adc_init"].push(pack->lv_errors(i).errors_adc_init());
		(*net_signals)["LV_ERRORS"]["errors_dcdc12"].push(pack->lv_errors(i).errors_dcdc12());
		(*net_signals)["LV_ERRORS"]["errors_dcdc24"].push(pack->lv_errors(i).errors_dcdc24());

    }

    for(int i = 0; i < pack->shutdown_status_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->shutdown_status(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->shutdown_status(i)._inner_timestamp();
        (*net_signals)["SHUTDOWN_STATUS"]["_timestamp"].push(pack->shutdown_status(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["SHUTDOWN_STATUS"]["input"].push(pack->shutdown_status(i).input());
		(*net_signals)["SHUTDOWN_STATUS"]["output"].push(pack->shutdown_status(i).output());

    }

    for(int i = 0; i < pack->marker_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->marker(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->marker(i)._inner_timestamp();
        (*net_signals)["MARKER"]["_timestamp"].push(pack->marker(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->hv_cells_voltage_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_cells_voltage(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_cells_voltage(i)._inner_timestamp();
        (*net_signals)["HV_CELLS_VOLTAGE"]["_timestamp"].push(pack->hv_cells_voltage(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["HV_CELLS_VOLTAGE"]["start_index"].push(pack->hv_cells_voltage(i).start_index());
		(*net_signals)["HV_CELLS_VOLTAGE"]["voltage_0"].push(pack->hv_cells_voltage(i).voltage_0());
		(*net_signals)["HV_CELLS_VOLTAGE"]["voltage_1"].push(pack->hv_cells_voltage(i).voltage_1());
		(*net_signals)["HV_CELLS_VOLTAGE"]["voltage_2"].push(pack->hv_cells_voltage(i).voltage_2());

    }

    for(int i = 0; i < pack->hv_cells_temp_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_cells_temp(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_cells_temp(i)._inner_timestamp();
        (*net_signals)["HV_CELLS_TEMP"]["_timestamp"].push(pack->hv_cells_temp(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["HV_CELLS_TEMP"]["start_index"].push(pack->hv_cells_temp(i).start_index());
		(*net_signals)["HV_CELLS_TEMP"]["temp_0"].push(pack->hv_cells_temp(i).temp_0());
		(*net_signals)["HV_CELLS_TEMP"]["temp_1"].push(pack->hv_cells_temp(i).temp_1());
		(*net_signals)["HV_CELLS_TEMP"]["temp_2"].push(pack->hv_cells_temp(i).temp_2());
		(*net_signals)["HV_CELLS_TEMP"]["temp_3"].push(pack->hv_cells_temp(i).temp_3());
		(*net_signals)["HV_CELLS_TEMP"]["temp_4"].push(pack->hv_cells_temp(i).temp_4());
		(*net_signals)["HV_CELLS_TEMP"]["temp_5"].push(pack->hv_cells_temp(i).temp_5());

    }

    for(int i = 0; i < pack->hv_cell_balancing_status_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_cell_balancing_status(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_cell_balancing_status(i)._inner_timestamp();
        (*net_signals)["HV_CELL_BALANCING_STATUS"]["_timestamp"].push(pack->hv_cell_balancing_status(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["HV_CELL_BALANCING_STATUS"]["balancing_status"].push(pack->hv_cell_balancing_status(i).balancing_status());
		primary_hv_cell_balancing_status_balancing_status_enum_to_string((primary_hv_cell_balancing_status_balancing_status)pack->hv_cell_balancing_status(i).balancing_status(), buffer);
		(*net_strings)["HV_CELL_BALANCING_STATUS"]["balancing_status"].push(buffer);

    }

    for(int i = 0; i < pack->set_cell_balancing_status_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->set_cell_balancing_status(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->set_cell_balancing_status(i)._inner_timestamp();
        (*net_signals)["SET_CELL_BALANCING_STATUS"]["_timestamp"].push(pack->set_cell_balancing_status(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["SET_CELL_BALANCING_STATUS"]["set_balancing_status"].push(pack->set_cell_balancing_status(i).set_balancing_status());
		primary_set_cell_balancing_status_set_balancing_status_enum_to_string((primary_set_cell_balancing_status_set_balancing_status)pack->set_cell_balancing_status(i).set_balancing_status(), buffer);
		(*net_strings)["SET_CELL_BALANCING_STATUS"]["set_balancing_status"].push(buffer);

    }

    for(int i = 0; i < pack->handcart_status_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->handcart_status(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->handcart_status(i)._inner_timestamp();
        (*net_signals)["HANDCART_STATUS"]["_timestamp"].push(pack->handcart_status(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["HANDCART_STATUS"]["connected"].push(pack->handcart_status(i).connected());

    }

    for(int i = 0; i < pack->speed_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->speed(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->speed(i)._inner_timestamp();
        (*net_signals)["SPEED"]["_timestamp"].push(pack->speed(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["SPEED"]["encoder_r"].push(pack->speed(i).encoder_r());
		(*net_signals)["SPEED"]["encoder_l"].push(pack->speed(i).encoder_l());
		(*net_signals)["SPEED"]["inverter_r"].push(pack->speed(i).inverter_r());
		(*net_signals)["SPEED"]["inverter_l"].push(pack->speed(i).inverter_l());

    }

    for(int i = 0; i < pack->inv_l_request_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->inv_l_request(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->inv_l_request(i)._inner_timestamp();
        (*net_signals)["INV_L_REQUEST"]["_timestamp"].push(pack->inv_l_request(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["INV_L_REQUEST"]["data_0"].push(pack->inv_l_request(i).data_0());
		(*net_signals)["INV_L_REQUEST"]["data_1"].push(pack->inv_l_request(i).data_1());
		(*net_signals)["INV_L_REQUEST"]["data_2"].push(pack->inv_l_request(i).data_2());
		(*net_signals)["INV_L_REQUEST"]["data_3"].push(pack->inv_l_request(i).data_3());
		(*net_signals)["INV_L_REQUEST"]["data_4"].push(pack->inv_l_request(i).data_4());
		(*net_signals)["INV_L_REQUEST"]["data_5"].push(pack->inv_l_request(i).data_5());
		(*net_signals)["INV_L_REQUEST"]["data_6"].push(pack->inv_l_request(i).data_6());
		(*net_signals)["INV_L_REQUEST"]["data_7"].push(pack->inv_l_request(i).data_7());

    }

    for(int i = 0; i < pack->inv_r_request_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->inv_r_request(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->inv_r_request(i)._inner_timestamp();
        (*net_signals)["INV_R_REQUEST"]["_timestamp"].push(pack->inv_r_request(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["INV_R_REQUEST"]["data_0"].push(pack->inv_r_request(i).data_0());
		(*net_signals)["INV_R_REQUEST"]["data_1"].push(pack->inv_r_request(i).data_1());
		(*net_signals)["INV_R_REQUEST"]["data_2"].push(pack->inv_r_request(i).data_2());
		(*net_signals)["INV_R_REQUEST"]["data_3"].push(pack->inv_r_request(i).data_3());
		(*net_signals)["INV_R_REQUEST"]["data_4"].push(pack->inv_r_request(i).data_4());
		(*net_signals)["INV_R_REQUEST"]["data_5"].push(pack->inv_r_request(i).data_5());
		(*net_signals)["INV_R_REQUEST"]["data_6"].push(pack->inv_r_request(i).data_6());
		(*net_signals)["INV_R_REQUEST"]["data_7"].push(pack->inv_r_request(i).data_7());

    }

    for(int i = 0; i < pack->inv_l_response_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->inv_l_response(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->inv_l_response(i)._inner_timestamp();
        (*net_signals)["INV_L_RESPONSE"]["_timestamp"].push(pack->inv_l_response(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["INV_L_RESPONSE"]["reg_id"].push(pack->inv_l_response(i).reg_id());
		(*net_signals)["INV_L_RESPONSE"]["data_0"].push(pack->inv_l_response(i).data_0());
		(*net_signals)["INV_L_RESPONSE"]["data_1"].push(pack->inv_l_response(i).data_1());
		(*net_signals)["INV_L_RESPONSE"]["data_2"].push(pack->inv_l_response(i).data_2());
		(*net_signals)["INV_L_RESPONSE"]["data_3"].push(pack->inv_l_response(i).data_3());
		(*net_signals)["INV_L_RESPONSE"]["data_4"].push(pack->inv_l_response(i).data_4());
		(*net_signals)["INV_L_RESPONSE"]["data_5"].push(pack->inv_l_response(i).data_5());
		(*net_signals)["INV_L_RESPONSE"]["data_6"].push(pack->inv_l_response(i).data_6());

    }

    for(int i = 0; i < pack->inv_r_response_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->inv_r_response(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->inv_r_response(i)._inner_timestamp();
        (*net_signals)["INV_R_RESPONSE"]["_timestamp"].push(pack->inv_r_response(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["INV_R_RESPONSE"]["reg_id"].push(pack->inv_r_response(i).reg_id());
		(*net_signals)["INV_R_RESPONSE"]["data_0"].push(pack->inv_r_response(i).data_0());
		(*net_signals)["INV_R_RESPONSE"]["data_1"].push(pack->inv_r_response(i).data_1());
		(*net_signals)["INV_R_RESPONSE"]["data_2"].push(pack->inv_r_response(i).data_2());
		(*net_signals)["INV_R_RESPONSE"]["data_3"].push(pack->inv_r_response(i).data_3());
		(*net_signals)["INV_R_RESPONSE"]["data_4"].push(pack->inv_r_response(i).data_4());
		(*net_signals)["INV_R_RESPONSE"]["data_5"].push(pack->inv_r_response(i).data_5());
		(*net_signals)["INV_R_RESPONSE"]["data_6"].push(pack->inv_r_response(i).data_6());

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

    for(int i = 0; i < pack->flash_bms_hv_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->flash_bms_hv_tx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->flash_bms_hv_tx(i)._inner_timestamp();
        (*net_signals)["FLASH_BMS_HV_TX"]["_timestamp"].push(pack->flash_bms_hv_tx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->flash_bms_hv_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->flash_bms_hv_rx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->flash_bms_hv_rx(i)._inner_timestamp();
        (*net_signals)["FLASH_BMS_HV_RX"]["_timestamp"].push(pack->flash_bms_hv_rx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->flash_bms_lv_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->flash_bms_lv_tx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->flash_bms_lv_tx(i)._inner_timestamp();
        (*net_signals)["FLASH_BMS_LV_TX"]["_timestamp"].push(pack->flash_bms_lv_tx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->flash_bms_lv_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->flash_bms_lv_rx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->flash_bms_lv_rx(i)._inner_timestamp();
        (*net_signals)["FLASH_BMS_LV_RX"]["_timestamp"].push(pack->flash_bms_lv_rx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->brusa_nlg5_ctl_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->brusa_nlg5_ctl(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->brusa_nlg5_ctl(i)._inner_timestamp();
        (*net_signals)["BRUSA_NLG5_CTL"]["_timestamp"].push(pack->brusa_nlg5_ctl(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->brusa_st_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->brusa_st(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->brusa_st(i)._inner_timestamp();
        (*net_signals)["BRUSA_ST"]["_timestamp"].push(pack->brusa_st(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->brusa_act_i_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->brusa_act_i(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->brusa_act_i(i)._inner_timestamp();
        (*net_signals)["BRUSA_ACT_I"]["_timestamp"].push(pack->brusa_act_i(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->brusa_act_ii_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->brusa_act_ii(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->brusa_act_ii(i)._inner_timestamp();
        (*net_signals)["BRUSA_ACT_II"]["_timestamp"].push(pack->brusa_act_ii(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->brusa_temp_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->brusa_temp(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->brusa_temp(i)._inner_timestamp();
        (*net_signals)["BRUSA_TEMP"]["_timestamp"].push(pack->brusa_temp(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->brusa_err_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->brusa_err(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->brusa_err(i)._inner_timestamp();
        (*net_signals)["BRUSA_ERR"]["_timestamp"].push(pack->brusa_err(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


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

    for(int i = 0; i < pack->lc_reset_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->lc_reset(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->lc_reset(i)._inner_timestamp();
        (*net_signals)["LC_RESET"]["_timestamp"].push(pack->lc_reset(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

}

void primary_proto_interface_serialize_from_id(canlib_message_id id, primary::Pack* pack, primary_devices* map) {
    int index = primary_index_from_id(id);

    if (index == -1) return;

    switch(id) {
        
        case 513: {
            primary_inverter_l_send_converted_t* msg = (primary_inverter_l_send_converted_t*)((*map)[index].message_conversion);
            primary::INVERTER_L_SEND* proto_msg = pack->add_inverter_l_send();
			proto_msg->set_send_mux((primary::primary_inverter_l_send_send_mux)msg->send_mux);
			proto_msg->set_motor_f_n(msg->motor_f_n);
			proto_msg->set_t_dc__start(msg->t_dc__start);
			proto_msg->set_v_dc__start(msg->v_dc__start);
			proto_msg->set_special__start(msg->special__start);
			proto_msg->set_v_min__start(msg->v_min__start);
			proto_msg->set_f_min__start(msg->f_min__start);
			proto_msg->set_v_corner__start(msg->v_corner__start);
			proto_msg->set_f_corner__start(msg->f_corner__start);
			proto_msg->set_cos_phi(msg->cos_phi);
			proto_msg->set_extra__start(msg->extra__start);
			proto_msg->set_capture_channel(msg->capture_channel);
			proto_msg->set_trig_level(msg->trig_level);
			proto_msg->set_trig_edge(msg->trig_edge);
			proto_msg->set_trig_source(msg->trig_source);
			proto_msg->set_oszi_source(msg->oszi_source);
			proto_msg->set_oszi_skip(msg->oszi_skip);
			proto_msg->set_oszi_read_cmd(msg->oszi_read_cmd);
			proto_msg->set_oszi_run_cmd(msg->oszi_run_cmd);
			proto_msg->set_calib_ref_value(msg->calib_ref_value);
			proto_msg->set_pid_i__kp__iq(msg->pid_i__kp__iq);
			proto_msg->set_pid_i__ti__iq(msg->pid_i__ti__iq);
			proto_msg->set_cutoffdig(msg->cutoffdig);
			proto_msg->set_id_setdig__id(msg->id_setdig__id);
			proto_msg->set_i_delta_ramp(msg->i_delta_ramp);
			proto_msg->set_pid_i__tim__iq(msg->pid_i__tim__iq);
			proto_msg->set_pid_n__kp(msg->pid_n__kp);
			proto_msg->set_pid_n__ti(msg->pid_n__ti);
			proto_msg->set_pid_n__td(msg->pid_n__td);
			proto_msg->set_ain_in_1_offsetval(msg->ain_in_1_offsetval);
			proto_msg->set_n_setdig(msg->n_setdig);
			proto_msg->set_n_lim(msg->n_lim);
			proto_msg->set_n_r_acc(msg->n_r_acc);
			proto_msg->set_cs_ain_1_format((primary::primary_inverter_l_send_cs_ain_1_format)msg->cs_ain_1_format);
			proto_msg->set_pid_n__tim(msg->pid_n__tim);
			proto_msg->set_i_red_n(msg->i_red_n);
			proto_msg->set_n_lim_minus(msg->n_lim_minus);
			proto_msg->set_n_lim_plus(msg->n_lim_plus);
			proto_msg->set_fb_offset(msg->fb_offset);
			proto_msg->set_read_id((primary::primary_inverter_l_send_read_id)msg->read_id);
			proto_msg->set_i_lim_dig(msg->i_lim_dig);
			proto_msg->set_i_red_te(msg->i_red_te);
			proto_msg->set_i_max_eff(msg->i_max_eff);
			proto_msg->set_i_nom_eff(msg->i_nom_eff);
			proto_msg->set_motor_pole(msg->motor_pole);
			proto_msg->set_ain_in_1_cutoff(msg->ain_in_1_cutoff);
			proto_msg->set_km_rsvd_0(msg->km_rsvd_0);
			proto_msg->set_ain_in_2_cutoff(msg->ain_in_2_cutoff);
			proto_msg->set_i_red_td(msg->i_red_td);
			proto_msg->set_n_nom(msg->n_nom);
			proto_msg->set_dc_bus_comp(msg->dc_bus_comp);
			proto_msg->set_pid_n__kacc(msg->pid_n__kacc);
			proto_msg->set_speed_filter(msg->speed_filter);
			proto_msg->set_ain_in_1_filter(msg->ain_in_1_filter);
			proto_msg->set_snr(msg->snr);
			proto_msg->set_device_mains(msg->device_mains);
			proto_msg->set_regen_p(msg->regen_p);
			proto_msg->set_devicetype((primary::primary_inverter_l_send_devicetype)msg->devicetype);
			proto_msg->set_can_id_rx(msg->can_id_rx);
			proto_msg->set_can_id_tx(msg->can_id_tx);
			proto_msg->set_pos_kp(msg->pos_kp);
			proto_msg->set_pos_ti(msg->pos_ti);
			proto_msg->set_pos_td(msg->pos_td);
			proto_msg->set_pos_dest(msg->pos_dest);
			proto_msg->set_pos_tim(msg->pos_tim);
			proto_msg->set_pos_offsref(msg->pos_offsref);
			proto_msg->set_can_nbt((primary::primary_inverter_l_send_can_nbt)msg->can_nbt);
			proto_msg->set_ref_reso_edge(msg->ref_reso_edge);
			proto_msg->set_speed_1(msg->speed_1);
			proto_msg->set_speed_2(msg->speed_2);
			proto_msg->set_pos_tol_win(msg->pos_tol_win);
			proto_msg->set_pos_preset_val(msg->pos_preset_val);
			proto_msg->set_pos_nd_scale(msg->pos_nd_scale);
			proto_msg->set_pos_nd_offset(msg->pos_nd_offset);
			proto_msg->set_fb2_scale_ext(msg->fb2_scale_ext);
			proto_msg->set_pos_offset_slack(msg->pos_offset_slack);
			proto_msg->set_pos_diff_slack(msg->pos_diff_slack);
			proto_msg->set_eprom131((primary::primary_inverter_l_send_eprom131)msg->eprom131);
			proto_msg->set_eprom132((primary::primary_inverter_l_send_eprom132)msg->eprom132);
			proto_msg->set_fun_special(msg->fun_special);
			proto_msg->set_can_id_2_rx(msg->can_id_2_rx);
			proto_msg->set_can_id_2_tx(msg->can_id_2_tx);
			proto_msg->set_v_ref(msg->v_ref);
			proto_msg->set_v_kp(msg->v_kp);
			proto_msg->set_v_ti(msg->v_ti);
			proto_msg->set_clear_errors(msg->clear_errors);
			proto_msg->set_m_setdig__iq(msg->m_setdig__iq);
			proto_msg->set_i_red_tm(msg->i_red_tm);
			proto_msg->set_m_temp(msg->m_temp);
			proto_msg->set_mo_feedback_1((primary::primary_inverter_l_send_mo_feedback_1)msg->mo_feedback_1);
			proto_msg->set_dc_bus_min_lim(msg->dc_bus_min_lim);
			proto_msg->set_fb_incr_mot(msg->fb_incr_mot);
			proto_msg->set_fb_pole(msg->fb_pole);
			proto_msg->set_motor_lsq(msg->motor_lsq);
			proto_msg->set_id_nom(msg->id_nom);
			proto_msg->set_motor_lm(msg->motor_lm);
			proto_msg->set_motor_rr(msg->motor_rr);
			proto_msg->set_id_min(msg->id_min);
			proto_msg->set_motor_tr(msg->motor_tr);
			proto_msg->set_motor_lsd(msg->motor_lsd);
			proto_msg->set_motor_rs(msg->motor_rs);
			proto_msg->set_motor_ts(msg->motor_ts);
			proto_msg->set_def_end_1((primary::primary_inverter_l_send_def_end_1)msg->def_end_1);
			proto_msg->set_def_end_2((primary::primary_inverter_l_send_def_end_2)msg->def_end_2);
			proto_msg->set_def_din_1((primary::primary_inverter_l_send_def_din_1)msg->def_din_1);
			proto_msg->set_def_din_2((primary::primary_inverter_l_send_def_din_2)msg->def_din_2);
			proto_msg->set_operand194((primary::primary_inverter_l_send_operand194)msg->operand194);
			proto_msg->set_operand195((primary::primary_inverter_l_send_operand195)msg->operand195);
			proto_msg->set_operand218((primary::primary_inverter_l_send_operand218)msg->operand218);
			proto_msg->set_operand219((primary::primary_inverter_l_send_operand219)msg->operand219);
			proto_msg->set_i_max_pk(msg->i_max_pk);
			proto_msg->set_i_con_eff(msg->i_con_eff);
			proto_msg->set_i_device(msg->i_device);
			proto_msg->set_n_r_lim(msg->n_r_lim);
			proto_msg->set_nmax100perc(msg->nmax100perc);
			proto_msg->set_pid_i__xkp__iq(msg->pid_i__xkp__iq);
			proto_msg->set_bat_opr_limit__mot(msg->bat_opr_limit__mot);
			proto_msg->set_pid_i__kf__iq(msg->pid_i__kf__iq);
			proto_msg->set_cmc__bit0__dc_current_sens_ena(msg->cmc__bit0__dc_current_sens_ena);
			proto_msg->set_can_rxtimeout(msg->can_rxtimeout);
			proto_msg->set_var_1(msg->var_1);
			proto_msg->set_var_2(msg->var_2);
			proto_msg->set_var_3(msg->var_3);
			proto_msg->set_var_4(msg->var_4);
			proto_msg->set_ain_in_2_offsetval(msg->ain_in_2_offsetval);
			proto_msg->set_dup__bit7_0__dac_source_channel(msg->dup__bit7_0__dac_source_channel);
			proto_msg->set_n_r_dec(msg->n_r_dec);
			proto_msg->set_v_shunt(msg->v_shunt);
			proto_msg->set_t_peak(msg->t_peak);
			proto_msg->set_brake_delay(msg->brake_delay);
			proto_msg->set_axis(msg->axis);
			proto_msg->set_km_speed_0(msg->km_speed_0);
			proto_msg->set_ballast_ext(msg->ballast_ext);
			proto_msg->set_cmc__bit1__idc_limit_ena(msg->cmc__bit1__idc_limit_ena);
			proto_msg->set_cs_ain_2_format((primary::primary_inverter_l_send_cs_ain_2_format)msg->cs_ain_2_format);
			proto_msg->set_km_frg_off(msg->km_frg_off);
			proto_msg->set_fb_special(msg->fb_special);
			proto_msg->set_cmc__bit2__pdc_limit_usage(msg->cmc__bit2__pdc_limit_usage);
			proto_msg->set_km_cal_off(msg->km_cal_off);
			proto_msg->set_coaststop(msg->coaststop);
			proto_msg->set_cmc__bit3__torqueval_init_ena(msg->cmc__bit3__torqueval_init_ena);
			proto_msg->set_cs_ain_1_mode((primary::primary_inverter_l_send_cs_ain_1_mode)msg->cs_ain_1_mode);
			proto_msg->set_km_tx_tog_stat(msg->km_tx_tog_stat);
			proto_msg->set_i_ist_inverse(msg->i_ist_inverse);
			proto_msg->set_compare_var194((primary::primary_inverter_l_send_compare_var194)msg->compare_var194);
			proto_msg->set_compare_var195((primary::primary_inverter_l_send_compare_var195)msg->compare_var195);
			proto_msg->set_compare_var218((primary::primary_inverter_l_send_compare_var218)msg->compare_var218);
			proto_msg->set_compare_var219((primary::primary_inverter_l_send_compare_var219)msg->compare_var219);
			proto_msg->set_cmc__bit4__dig_m_rcpramp_ena(msg->cmc__bit4__dig_m_rcpramp_ena);
			proto_msg->set_km_i_limit(msg->km_i_limit);
			proto_msg->set_refsoft(msg->refsoft);
			proto_msg->set_mo_feedback_2((primary::primary_inverter_l_send_mo_feedback_2)msg->mo_feedback_2);
			proto_msg->set_cmc__bit5__reset_nramp_atnzero(msg->cmc__bit5__reset_nramp_atnzero);
			proto_msg->set_km_n_clip(msg->km_n_clip);
			proto_msg->set_no_uesp_btb(msg->no_uesp_btb);
			proto_msg->set_cmc__bit6__torquetimeout_100ms_e(msg->cmc__bit6__torquetimeout_100ms_e);
			proto_msg->set_cs_oora1(msg->cs_oora1);
			proto_msg->set_km_mix_ana_on(msg->km_mix_ana_on);
			proto_msg->set_vdc_ana(msg->vdc_ana);
			proto_msg->set_cmc__bit13_7__free(msg->cmc__bit13_7__free);
			proto_msg->set_cs_ain_2_mode((primary::primary_inverter_l_send_cs_ain_2_mode)msg->cs_ain_2_mode);
			proto_msg->set_ret_interval((primary::primary_inverter_l_send_ret_interval)msg->ret_interval);
			proto_msg->set_km_allow_sync(msg->km_allow_sync);
			proto_msg->set_i1_adc_ena(msg->i1_adc_ena);
			proto_msg->set_ain_in_2_filter(msg->ain_in_2_filter);
			proto_msg->set_mo_sc1_reso((primary::primary_inverter_l_send_mo_sc1_reso)msg->mo_sc1_reso);
			proto_msg->set_source_id194((primary::primary_inverter_l_send_source_id194)msg->source_id194);
			proto_msg->set_source_id195((primary::primary_inverter_l_send_source_id195)msg->source_id195);
			proto_msg->set_source_id218((primary::primary_inverter_l_send_source_id218)msg->source_id218);
			proto_msg->set_source_id219((primary::primary_inverter_l_send_source_id219)msg->source_id219);
			proto_msg->set_dup__bit8__can_extended_0(msg->dup__bit8__can_extended_0);
			proto_msg->set_km_handwheel(msg->km_handwheel);
			proto_msg->set_hxinv(msg->hxinv);
			proto_msg->set_dup__bit9__generator(msg->dup__bit9__generator);
			proto_msg->set_km_phasing_extend(msg->km_phasing_extend);
			proto_msg->set_h2inv(msg->h2inv);
			proto_msg->set_dup__bit10__park_rms(msg->dup__bit10__park_rms);
			proto_msg->set_cs_oora2(msg->cs_oora2);
			proto_msg->set_km_rsvd_11(msg->km_rsvd_11);
			proto_msg->set_ol_comp(msg->ol_comp);
			proto_msg->set_mo_sc1_comp(msg->mo_sc1_comp);
			proto_msg->set_dup__bit11__dcbus_volts(msg->dup__bit11__dcbus_volts);
			proto_msg->set_cs_cmd_type((primary::primary_inverter_l_send_cs_cmd_type)msg->cs_cmd_type);
			proto_msg->set_km_rsvd_12(msg->km_rsvd_12);
			proto_msg->set_motortype((primary::primary_inverter_l_send_motortype)msg->motortype);
			proto_msg->set_mo_sc2_reso((primary::primary_inverter_l_send_mo_sc2_reso)msg->mo_sc2_reso);
			proto_msg->set_dup__bit12__boat_pedal(msg->dup__bit12__boat_pedal);
			proto_msg->set_km_rsvd_13(msg->km_rsvd_13);
			proto_msg->set_dup__bit13__gen_autoiaclimit(msg->dup__bit13__gen_autoiaclimit);
			proto_msg->set_cs_ain_2__i_limit(msg->cs_ain_2__i_limit);
			proto_msg->set_km_pseudo_enable(msg->km_pseudo_enable);
			proto_msg->set_ana_0up(msg->ana_0up);
			proto_msg->set_cmc__bit14__idc_limit_ena_v2(msg->cmc__bit14__idc_limit_ena_v2);
			proto_msg->set_dup__bit14__mtpa_reluct_enab(msg->dup__bit14__mtpa_reluct_enab);
			proto_msg->set_cs_ain_1__n_limit(msg->cs_ain_1__n_limit);
			proto_msg->set_km_debug_test(msg->km_debug_test);
			proto_msg->set_lowbd(msg->lowbd);
			proto_msg->set_mo_sc2_inv(msg->mo_sc2_inv);
			proto_msg->set_active190((primary::primary_inverter_l_send_active190)msg->active190);
			proto_msg->set_active191((primary::primary_inverter_l_send_active191)msg->active191);
			proto_msg->set_active192((primary::primary_inverter_l_send_active192)msg->active192);
			proto_msg->set_active193((primary::primary_inverter_l_send_active193)msg->active193);
			proto_msg->set_cmc__bit15__dig_e_brake_act(msg->cmc__bit15__dig_e_brake_act);
			proto_msg->set_dup__bit15__canopen_acv(msg->dup__bit15__canopen_acv);
			proto_msg->set_t_dc__stop(msg->t_dc__stop);
			proto_msg->set_v_dc__stop(msg->v_dc__stop);
			proto_msg->set_special__stop(msg->special__stop);
			proto_msg->set_v_min__stop(msg->v_min__stop);
			proto_msg->set_f_min__stop(msg->f_min__stop);
			proto_msg->set_v_corner__stop(msg->v_corner__stop);
			proto_msg->set_f_corner__stop(msg->f_corner__stop);
			proto_msg->set_pid_i__kp__id(msg->pid_i__kp__id);
			proto_msg->set_pid_i__ti__id(msg->pid_i__ti__id);
			proto_msg->set_pid_i__tim__id(msg->pid_i__tim__id);
			proto_msg->set_ain_in_1_scaleval(msg->ain_in_1_scaleval);
			proto_msg->set_m_r_acc(msg->m_r_acc);
			proto_msg->set_sramp(msg->sramp);
			proto_msg->set_regen_r(msg->regen_r);
			proto_msg->set_dc_bus_max_lim(msg->dc_bus_max_lim);
			proto_msg->set_m_r_rcp(msg->m_r_rcp);
			proto_msg->set_pid_i__xkp__id(msg->pid_i__xkp__id);
			proto_msg->set_bat_opr_limit__gen(msg->bat_opr_limit__gen);
			proto_msg->set_pid_i__kf__id(msg->pid_i__kf__id);
			proto_msg->set_cmc__bit17_16__checkipeak_config(msg->cmc__bit17_16__checkipeak_config);
			proto_msg->set_ain_in_2_scaleval(msg->ain_in_2_scaleval);
			proto_msg->set_dup__bit16__bamobil3_2_offcrct(msg->dup__bit16__bamobil3_2_offcrct);
			proto_msg->set_m_r_dec(msg->m_r_dec);
			proto_msg->set_ramp4(msg->ramp4);
			proto_msg->set_dup__bit19_17__ecode_redefine(msg->dup__bit19_17__ecode_redefine);
			proto_msg->set_motbrake(msg->motbrake);
			proto_msg->set_cmc__bit18__tractioncontrol_ena(msg->cmc__bit18__tractioncontrol_ena);
			proto_msg->set_ac_dc(msg->ac_dc);
			proto_msg->set_cmc__bit20_19__tc_deltatime_conf(msg->cmc__bit20_19__tc_deltatime_conf);
			proto_msg->set_pwm_freq((primary::primary_inverter_l_send_pwm_freq)msg->pwm_freq);
			proto_msg->set_dup__bit20__hal_extmr_acv(msg->dup__bit20__hal_extmr_acv);
			proto_msg->set_cmc__bit22_21__tc_minspeed_conf(msg->cmc__bit22_21__tc_minspeed_conf);
			proto_msg->set_dup__bit21__initwith_frg_off(msg->dup__bit21__initwith_frg_off);
			proto_msg->set_dup__bit31_22__free(msg->dup__bit31_22__free);
			proto_msg->set_ntc(msg->ntc);
			proto_msg->set_cmc__bit23__tc_ncmdrestoption(msg->cmc__bit23__tc_ncmdrestoption);
			proto_msg->set_delta(msg->delta);
			proto_msg->set_cmc__bit31_24__free(msg->cmc__bit31_24__free);
			proto_msg->set_dc_1qdirvolt(msg->dc_1qdirvolt);
			proto_msg->set_dc_field(msg->dc_field);
			proto_msg->set_dead_2(msg->dead_2);
			proto_msg->set_block(msg->block);
			proto_msg->set_dc_1qmv(msg->dc_1qmv);
			proto_msg->set_dc_1q3p(msg->dc_1q3p);
			proto_msg->set_reducelosses(msg->reducelosses);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 385: {
            primary_inverter_l_rcv_converted_t* msg = (primary_inverter_l_rcv_converted_t*)((*map)[index].message_conversion);
            primary::INVERTER_L_RCV* proto_msg = pack->add_inverter_l_rcv();
			proto_msg->set_rcv_mux((primary::primary_inverter_l_rcv_rcv_mux)msg->rcv_mux);
			proto_msg->set_n_actual(msg->n_actual);
			proto_msg->set_n_r_dec(msg->n_r_dec);
			proto_msg->set_n_r_lim(msg->n_r_lim);
			proto_msg->set_n_actual_filt(msg->n_actual_filt);
			proto_msg->set_firmware(msg->firmware);
			proto_msg->set_devicetype((primary::primary_inverter_l_rcv_devicetype)msg->devicetype);
			proto_msg->set_snr(msg->snr);
			proto_msg->set_axis(msg->axis);
			proto_msg->set_i_device(msg->i_device);
			proto_msg->set_v_shunt(msg->v_shunt);
			proto_msg->set_i_200perc(msg->i_200perc);
			proto_msg->set_dc_bus_comp(msg->dc_bus_comp);
			proto_msg->set_ena64(msg->ena64);
			proto_msg->set_err_badparas(msg->err_badparas);
			proto_msg->set_lmt1(msg->lmt1);
			proto_msg->set_ain_in_1_raw(msg->ain_in_1_raw);
			proto_msg->set_ain_in_2_raw(msg->ain_in_2_raw);
			proto_msg->set_nmax100perc(msg->nmax100perc);
			proto_msg->set_n_setdig(msg->n_setdig);
			proto_msg->set_n_cmd(msg->n_cmd);
			proto_msg->set_n_cmd_ramp(msg->n_cmd_ramp);
			proto_msg->set_n_lim(msg->n_lim);
			proto_msg->set_n_error(msg->n_error);
			proto_msg->set_m_setdig__iq(msg->m_setdig__iq);
			proto_msg->set_id_setdig__id(msg->id_setdig__id);
			proto_msg->set_i_max_pk(msg->i_max_pk);
			proto_msg->set_i_con_eff(msg->i_con_eff);
			proto_msg->set_i_max_eff(msg->i_max_eff);
			proto_msg->set_i_nom_eff(msg->i_nom_eff);
			proto_msg->set_i_limit_inuse(msg->i_limit_inuse);
			proto_msg->set_i_cmd(msg->i_cmd);
			proto_msg->set_i_cmd_ramp(msg->i_cmd_ramp);
			proto_msg->set_i_actual(msg->i_actual);
			proto_msg->set_i_actual_filt(msg->i_actual_filt);
			proto_msg->set_iq_actual(msg->iq_actual);
			proto_msg->set_id_actual(msg->id_actual);
			proto_msg->set_iq_error(msg->iq_error);
			proto_msg->set_id_error(msg->id_error);
			proto_msg->set_i1_actual(msg->i1_actual);
			proto_msg->set_i2_actual(msg->i2_actual);
			proto_msg->set_i3_actual(msg->i3_actual);
			proto_msg->set_i3_adc(msg->i3_adc);
			proto_msg->set_i2_adc(msg->i2_adc);
			proto_msg->set_vq(msg->vq);
			proto_msg->set_vd(msg->vd);
			proto_msg->set_vout(msg->vout);
			proto_msg->set_t_motor(msg->t_motor);
			proto_msg->set_t_igbt(msg->t_igbt);
			proto_msg->set_t_air(msg->t_air);
			proto_msg->set_vdc_bus_filt(msg->vdc_bus_filt);
			proto_msg->set_end_1(msg->end_1);
			proto_msg->set_din_1(msg->din_1);
			proto_msg->set_end_2(msg->end_2);
			proto_msg->set_din_2(msg->din_2);
			proto_msg->set_run232(msg->run232);
			proto_msg->set_dout_1(msg->dout_1);
			proto_msg->set_dout_2(msg->dout_2);
			proto_msg->set_dout_3(msg->dout_3);
			proto_msg->set_rdy_btb(msg->rdy_btb);
			proto_msg->set_i_fault(msg->i_fault);
			proto_msg->set_dout_4(msg->dout_4);
			proto_msg->set_i_lim_dig(msg->i_lim_dig);
			proto_msg->set_i_red_n(msg->i_red_n);
			proto_msg->set_i_red_td(msg->i_red_td);
			proto_msg->set_i_red_te(msg->i_red_te);
			proto_msg->set_i_red_tm(msg->i_red_tm);
			proto_msg->set_cs_ain_1_format((primary::primary_inverter_l_rcv_cs_ain_1_format)msg->cs_ain_1_format);
			proto_msg->set_id_ref(msg->id_ref);
			proto_msg->set_m_outdig__iq(msg->m_outdig__iq);
			proto_msg->set_ptr_1_debug(msg->ptr_1_debug);
			proto_msg->set_ptr_2_debug(msg->ptr_2_debug);
			proto_msg->set_temp_debug(msg->temp_debug);
			proto_msg->set_motor_f_n(msg->motor_f_n);
			proto_msg->set_motor_v_n(msg->motor_v_n);
			proto_msg->set_t_dc__start(msg->t_dc__start);
			proto_msg->set_v_dc__start(msg->v_dc__start);
			proto_msg->set_v_min__start(msg->v_min__start);
			proto_msg->set_f_min__start(msg->f_min__start);
			proto_msg->set_v_corner__start(msg->v_corner__start);
			proto_msg->set_f_corner__start(msg->f_corner__start);
			proto_msg->set_cos_phi(msg->cos_phi);
			proto_msg->set_pwm_enum(msg->pwm_enum);
			proto_msg->set_calib_ref_value(msg->calib_ref_value);
			proto_msg->set_pid_i__kp__iq(msg->pid_i__kp__iq);
			proto_msg->set_pid_i__ti__iq(msg->pid_i__ti__iq);
			proto_msg->set_cutoffdig(msg->cutoffdig);
			proto_msg->set_i3_offset(msg->i3_offset);
			proto_msg->set_i_delta_ramp(msg->i_delta_ramp);
			proto_msg->set_pid_i__tim__iq(msg->pid_i__tim__iq);
			proto_msg->set_pid_n__kp(msg->pid_n__kp);
			proto_msg->set_v_ti(msg->v_ti);
			proto_msg->set_pid_n__td(msg->pid_n__td);
			proto_msg->set_ain_in_1_offsetval(msg->ain_in_1_offsetval);
			proto_msg->set_ain_in_2_offsetval(msg->ain_in_2_offsetval);
			proto_msg->set_dzr_seq(msg->dzr_seq);
			proto_msg->set_pid_n__tim(msg->pid_n__tim);
			proto_msg->set_n_lim_plus(msg->n_lim_plus);
			proto_msg->set_n_lim_minus(msg->n_lim_minus);
			proto_msg->set_incr_delta(msg->incr_delta);
			proto_msg->set_motorpos_mech(msg->motorpos_mech);
			proto_msg->set_motorpos_elec(msg->motorpos_elec);
			proto_msg->set_fb_offset(msg->fb_offset);
			proto_msg->set_it_rg_monitor(msg->it_rg_monitor);
			proto_msg->set_motor_pole(msg->motor_pole);
			proto_msg->set_ain_in_1_cutoff(msg->ain_in_1_cutoff);
			proto_msg->set_activecontrolmode((primary::primary_inverter_l_rcv_activecontrolmode)msg->activecontrolmode);
			proto_msg->set_km_rsvd_0(msg->km_rsvd_0);
			proto_msg->set_ena82(msg->ena82);
			proto_msg->set_ain_in_2_cutoff(msg->ain_in_2_cutoff);
			proto_msg->set_i_limit_inuse_ramp(msg->i_limit_inuse_ramp);
			proto_msg->set_n_nom(msg->n_nom);
			proto_msg->set_pid_n__kacc(msg->pid_n__kacc);
			proto_msg->set_rotor_signals(msg->rotor_signals);
			proto_msg->set_speed_filter(msg->speed_filter);
			proto_msg->set_ain_in_1_filter(msg->ain_in_1_filter);
			proto_msg->set_ixt_monitor(msg->ixt_monitor);
			proto_msg->set_ecode_bit0_firsterrordtcd99(msg->ecode_bit0_firsterrordtcd99);
			proto_msg->set_device_mains(msg->device_mains);
			proto_msg->set_regen_p(msg->regen_p);
			proto_msg->set_can_id_rx(msg->can_id_rx);
			proto_msg->set_can_id_tx(msg->can_id_tx);
			proto_msg->set_pos_kp(msg->pos_kp);
			proto_msg->set_pos_ti(msg->pos_ti);
			proto_msg->set_pos_td(msg->pos_td);
			proto_msg->set_pos_actual(msg->pos_actual);
			proto_msg->set_pos_dest(msg->pos_dest);
			proto_msg->set_pos_actual_2(msg->pos_actual_2);
			proto_msg->set_pos_error(msg->pos_error);
			proto_msg->set_pos_tim(msg->pos_tim);
			proto_msg->set_pos_offsref(msg->pos_offsref);
			proto_msg->set_can_nbt((primary::primary_inverter_l_rcv_can_nbt)msg->can_nbt);
			proto_msg->set_pos_zero_capture(msg->pos_zero_capture);
			proto_msg->set_ref_reso_edge(msg->ref_reso_edge);
			proto_msg->set_speed_1(msg->speed_1);
			proto_msg->set_speed_2(msg->speed_2);
			proto_msg->set_pos_tol_win(msg->pos_tol_win);
			proto_msg->set_pos_preset_val(msg->pos_preset_val);
			proto_msg->set_pos_zero_offset(msg->pos_zero_offset);
			proto_msg->set_pos_nd_scale(msg->pos_nd_scale);
			proto_msg->set_pos_nd_offset(msg->pos_nd_offset);
			proto_msg->set_fb2_scale_ext(msg->fb2_scale_ext);
			proto_msg->set_pos_offset_slack(msg->pos_offset_slack);
			proto_msg->set_pos_diff_slack(msg->pos_diff_slack);
			proto_msg->set_fun_para_read(msg->fun_para_read);
			proto_msg->set_fun_para_write(msg->fun_para_write);
			proto_msg->set_fun_special(msg->fun_special);
			proto_msg->set_can_id_2_rx(msg->can_id_2_rx);
			proto_msg->set_can_id_2_tx(msg->can_id_2_tx);
			proto_msg->set_v_ref(msg->v_ref);
			proto_msg->set_v_kp(msg->v_kp);
			proto_msg->set_pid_n__ti(msg->pid_n__ti);
			proto_msg->set_clear_errors(msg->clear_errors);
			proto_msg->set_pos_cmd(msg->pos_cmd);
			proto_msg->set_can_error_busoff(msg->can_error_busoff);
			proto_msg->set_can_error_writetime(msg->can_error_writetime);
			proto_msg->set_ecode_bit0_firsterrordtcd148(msg->ecode_bit0_firsterrordtcd148);
			proto_msg->set_can_error_no_ack(msg->can_error_no_ack);
			proto_msg->set_can_error_crc_check150(msg->can_error_crc_check150);
			proto_msg->set_can_error_crc_check151(msg->can_error_crc_check151);
			proto_msg->set_info_timer_diff(msg->info_timer_diff);
			proto_msg->set_ballastcount(msg->ballastcount);
			proto_msg->set_m_temp(msg->m_temp);
			proto_msg->set_mo_feedback_1((primary::primary_inverter_l_rcv_mo_feedback_1)msg->mo_feedback_1);
			proto_msg->set_dc_bus_min_lim(msg->dc_bus_min_lim);
			proto_msg->set_fb_incr_mot(msg->fb_incr_mot);
			proto_msg->set_fb_pole(msg->fb_pole);
			proto_msg->set_logic_freq(msg->logic_freq);
			proto_msg->set_pwm_1(msg->pwm_1);
			proto_msg->set_pwm_2(msg->pwm_2);
			proto_msg->set_pwm_3(msg->pwm_3);
			proto_msg->set_timer_delta(msg->timer_delta);
			proto_msg->set_motor_lsq(msg->motor_lsq);
			proto_msg->set_motor_lsd(msg->motor_lsd);
			proto_msg->set_id_nom(msg->id_nom);
			proto_msg->set_motor_lm(msg->motor_lm);
			proto_msg->set_motor_rr(msg->motor_rr);
			proto_msg->set_id_min(msg->id_min);
			proto_msg->set_motor_tr(msg->motor_tr);
			proto_msg->set_motor_rs(msg->motor_rs);
			proto_msg->set_motor_ts(msg->motor_ts);
			proto_msg->set_def_end_1((primary::primary_inverter_l_rcv_def_end_1)msg->def_end_1);
			proto_msg->set_def_end_2((primary::primary_inverter_l_rcv_def_end_2)msg->def_end_2);
			proto_msg->set_def_din_1((primary::primary_inverter_l_rcv_def_din_1)msg->def_din_1);
			proto_msg->set_def_din_2((primary::primary_inverter_l_rcv_def_din_2)msg->def_din_2);
			proto_msg->set_operand194((primary::primary_inverter_l_rcv_operand194)msg->operand194);
			proto_msg->set_i_max_inuse(msg->i_max_inuse);
			proto_msg->set_signal_go(msg->signal_go);
			proto_msg->set_signal_brake(msg->signal_brake);
			proto_msg->set_signal_icns(msg->signal_icns);
			proto_msg->set_signal_lessn0(msg->signal_lessn0);
			proto_msg->set_signal_postolerance(msg->signal_postolerance);
			proto_msg->set_ain_in_1_scaled251(msg->ain_in_1_scaled251);
			proto_msg->set_ain_in_2_scaled252(msg->ain_in_2_scaled252);
			proto_msg->set_operand195((primary::primary_inverter_l_rcv_operand195)msg->operand195);
			proto_msg->set_operand218((primary::primary_inverter_l_rcv_operand218)msg->operand218);
			proto_msg->set_operand219((primary::primary_inverter_l_rcv_operand219)msg->operand219);
			proto_msg->set_pid_i__xkp__iq(msg->pid_i__xkp__iq);
			proto_msg->set_bat_opr_limit__mot(msg->bat_opr_limit__mot);
			proto_msg->set_pid_i__kf__iq(msg->pid_i__kf__iq);
			proto_msg->set_dc_current_sens_ena_set(msg->dc_current_sens_ena_set);
			proto_msg->set_cmc__bit0__dc_current_sens_ena(msg->cmc__bit0__dc_current_sens_ena);
			proto_msg->set_n_rpm_maxint(msg->n_rpm_maxint);
			proto_msg->set_var_1(msg->var_1);
			proto_msg->set_can_rxtimeout(msg->can_rxtimeout);
			proto_msg->set_var_2(msg->var_2);
			proto_msg->set_var_3(msg->var_3);
			proto_msg->set_var_4(msg->var_4);
			proto_msg->set_dup__bit7_0__dac_source_channel(msg->dup__bit7_0__dac_source_channel);
			proto_msg->set_fb_lossofsignal(msg->fb_lossofsignal);
			proto_msg->set_no_hw_fault(msg->no_hw_fault);
			proto_msg->set_t_peak(msg->t_peak);
			proto_msg->set_brake_delay(msg->brake_delay);
			proto_msg->set_power(msg->power);
			proto_msg->set_work(msg->work);
			proto_msg->set_extra__start(msg->extra__start);
			proto_msg->set_capture_channel(msg->capture_channel);
			proto_msg->set_trig_level(msg->trig_level);
			proto_msg->set_trig_edge(msg->trig_edge);
			proto_msg->set_trig_source(msg->trig_source);
			proto_msg->set_oszi_source(msg->oszi_source);
			proto_msg->set_oszi_skip(msg->oszi_skip);
			proto_msg->set_oszi_run_cmd(msg->oszi_run_cmd);
			proto_msg->set_oszi_read_cmd(msg->oszi_read_cmd);
			proto_msg->set_pos_ref_start(msg->pos_ref_start);
			proto_msg->set_vdc_bus(msg->vdc_bus);
			proto_msg->set_m_cmd_ramp(msg->m_cmd_ramp);
			proto_msg->set_lmt_1(msg->lmt_1);
			proto_msg->set_out_1(msg->out_1);
			proto_msg->set_subversion_nr(msg->subversion_nr);
			proto_msg->set_ballast_ext(msg->ballast_ext);
			proto_msg->set_ncr064(msg->ncr064);
			proto_msg->set_err_powerfault(msg->err_powerfault);
			proto_msg->set_lmt2(msg->lmt2);
			proto_msg->set_km_speed_0(msg->km_speed_0);
			proto_msg->set_ncr082(msg->ncr082);
			proto_msg->set_ecode_bit1__hw1_state99(msg->ecode_bit1__hw1_state99);
			proto_msg->set_ecode_bit1__hw1_state148(msg->ecode_bit1__hw1_state148);
			proto_msg->set_dc_i_sensena_set(msg->dc_i_sensena_set);
			proto_msg->set_cmc__bit1__idc_limit_ena(msg->cmc__bit1__idc_limit_ena);
			proto_msg->set_lmt_2(msg->lmt_2);
			proto_msg->set_out_2(msg->out_2);
			proto_msg->set_fb_special(msg->fb_special);
			proto_msg->set_lim_plus64(msg->lim_plus64);
			proto_msg->set_err_rfe_fault(msg->err_rfe_fault);
			proto_msg->set_in2(msg->in2);
			proto_msg->set_cs_ain_2_format((primary::primary_inverter_l_rcv_cs_ain_2_format)msg->cs_ain_2_format);
			proto_msg->set_km_frg_off(msg->km_frg_off);
			proto_msg->set_lim_plus82(msg->lim_plus82);
			proto_msg->set_ecode_bit2__hw0_state99(msg->ecode_bit2__hw0_state99);
			proto_msg->set_ecode_bit2__hw0_state148(msg->ecode_bit2__hw0_state148);
			proto_msg->set_op_mode_quadrant(msg->op_mode_quadrant);
			proto_msg->set_cmc__bit2__pdc_limit_usage(msg->cmc__bit2__pdc_limit_usage);
			proto_msg->set_in_2(msg->in_2);
			proto_msg->set_rdy155(msg->rdy155);
			proto_msg->set_coaststop(msg->coaststop);
			proto_msg->set_lim_minus64(msg->lim_minus64);
			proto_msg->set_err_bustimeout(msg->err_bustimeout);
			proto_msg->set_in1(msg->in1);
			proto_msg->set_km_cal_off(msg->km_cal_off);
			proto_msg->set_lim_minus82(msg->lim_minus82);
			proto_msg->set_ecode_bit3__free99(msg->ecode_bit3__free99);
			proto_msg->set_ecode_bit3__free148(msg->ecode_bit3__free148);
			proto_msg->set_cmc__bit3__torqueval_init_ena(msg->cmc__bit3__torqueval_init_ena);
			proto_msg->set_in_1(msg->in_1);
			proto_msg->set_go155(msg->go155);
			proto_msg->set_i_ist_inverse(msg->i_ist_inverse);
			proto_msg->set_ok64(msg->ok64);
			proto_msg->set_err_feedbacksignal(msg->err_feedbacksignal);
			proto_msg->set_frgrun(msg->frgrun);
			proto_msg->set_cs_ain_1_mode((primary::primary_inverter_l_rcv_cs_ain_1_mode)msg->cs_ain_1_mode);
			proto_msg->set_km_tx_tog_stat(msg->km_tx_tog_stat);
			proto_msg->set_ok82(msg->ok82);
			proto_msg->set_ecode_bit4__rdy399(msg->ecode_bit4__rdy399);
			proto_msg->set_ecode_bit4__rdy3148(msg->ecode_bit4__rdy3148);
			proto_msg->set_compare_var194((primary::primary_inverter_l_rcv_compare_var194)msg->compare_var194);
			proto_msg->set_compare_var195((primary::primary_inverter_l_rcv_compare_var195)msg->compare_var195);
			proto_msg->set_compare_var218((primary::primary_inverter_l_rcv_compare_var218)msg->compare_var218);
			proto_msg->set_compare_var219((primary::primary_inverter_l_rcv_compare_var219)msg->compare_var219);
			proto_msg->set_cmc__bit4__dig_m_rcpramp_ena(msg->cmc__bit4__dig_m_rcpramp_ena);
			proto_msg->set_run152(msg->run152);
			proto_msg->set_out_3(msg->out_3);
			proto_msg->set_refsoft(msg->refsoft);
			proto_msg->set_icns64(msg->icns64);
			proto_msg->set_err_powervoltage_low(msg->err_powervoltage_low);
			proto_msg->set_rfe216(msg->rfe216);
			proto_msg->set_km_i_limit(msg->km_i_limit);
			proto_msg->set_icns82(msg->icns82);
			proto_msg->set_ecode_bit5__n_fail99(msg->ecode_bit5__n_fail99);
			proto_msg->set_ecode_bit5__n_fail148(msg->ecode_bit5__n_fail148);
			proto_msg->set_mo_feedback_2((primary::primary_inverter_l_rcv_mo_feedback_2)msg->mo_feedback_2);
			proto_msg->set_recup_is_acv(msg->recup_is_acv);
			proto_msg->set_cmc__bit5__reset_nramp_atnzero(msg->cmc__bit5__reset_nramp_atnzero);
			proto_msg->set_rfe152(msg->rfe152);
			proto_msg->set_out_4(msg->out_4);
			proto_msg->set_no_uesp_btb(msg->no_uesp_btb);
			proto_msg->set_tnlim64(msg->tnlim64);
			proto_msg->set_err_motortemp(msg->err_motortemp);
			proto_msg->set_km_n_clip(msg->km_n_clip);
			proto_msg->set_tnlim82(msg->tnlim82);
			proto_msg->set_ecode_bit6__flths99(msg->ecode_bit6__flths99);
			proto_msg->set_ecode_bit6__flths148(msg->ecode_bit6__flths148);
			proto_msg->set_i_dc_limit_is_acv(msg->i_dc_limit_is_acv);
			proto_msg->set_cmc__bit6__torquetimeout_100ms_e(msg->cmc__bit6__torquetimeout_100ms_e);
			proto_msg->set_rsvd(msg->rsvd);
			proto_msg->set_rsvd1(msg->rsvd1);
			proto_msg->set_vdc_ana(msg->vdc_ana);
			proto_msg->set_pn64(msg->pn64);
			proto_msg->set_err_devicetemp(msg->err_devicetemp);
			proto_msg->set_cs_oora1(msg->cs_oora1);
			proto_msg->set_km_mix_ana_on(msg->km_mix_ana_on);
			proto_msg->set_pn82(msg->pn82);
			proto_msg->set_ecode_bit7__fltls99(msg->ecode_bit7__fltls99);
			proto_msg->set_ecode_bit7__fltls148(msg->ecode_bit7__fltls148);
			proto_msg->set_cmc__bit13_7__free(msg->cmc__bit13_7__free);
			proto_msg->set_brk1155(msg->brk1155);
			proto_msg->set_i1_adc_ena(msg->i1_adc_ena);
			proto_msg->set_ni64(msg->ni64);
			proto_msg->set_err_overvoltage(msg->err_overvoltage);
			proto_msg->set_out1(msg->out1);
			proto_msg->set_cs_ain_2_mode((primary::primary_inverter_l_rcv_cs_ain_2_mode)msg->cs_ain_2_mode);
			proto_msg->set_ctrlsubmode((primary::primary_inverter_l_rcv_ctrlsubmode)msg->ctrlsubmode);
			proto_msg->set_km_allow_sync(msg->km_allow_sync);
			proto_msg->set_ni82(msg->ni82);
			proto_msg->set_ain_in_2_filter(msg->ain_in_2_filter);
			proto_msg->set_ecode_bit8__fail_idc99(msg->ecode_bit8__fail_idc99);
			proto_msg->set_ecode_bit8__fail_idc148(msg->ecode_bit8__fail_idc148);
			proto_msg->set_mo_sc1_reso((primary::primary_inverter_l_rcv_mo_sc1_reso)msg->mo_sc1_reso);
			proto_msg->set_source_id194((primary::primary_inverter_l_rcv_source_id194)msg->source_id194);
			proto_msg->set_source_id195((primary::primary_inverter_l_rcv_source_id195)msg->source_id195);
			proto_msg->set_source_id218((primary::primary_inverter_l_rcv_source_id218)msg->source_id218);
			proto_msg->set_source_id219((primary::primary_inverter_l_rcv_source_id219)msg->source_id219);
			proto_msg->set_dup__bit8__can_extended_0(msg->dup__bit8__can_extended_0);
			proto_msg->set_hxinv(msg->hxinv);
			proto_msg->set__n064(msg->_n064);
			proto_msg->set_err_ipeak(msg->err_ipeak);
			proto_msg->set_out2(msg->out2);
			proto_msg->set_km_handwheel(msg->km_handwheel);
			proto_msg->set__n082(msg->_n082);
			proto_msg->set_ecode_bit9__fail_i99(msg->ecode_bit9__fail_i99);
			proto_msg->set_ecode_bit9__fail_i148(msg->ecode_bit9__fail_i148);
			proto_msg->set_dup__bit9__generator(msg->dup__bit9__generator);
			proto_msg->set_h2inv(msg->h2inv);
			proto_msg->set_rsw64(msg->rsw64);
			proto_msg->set_err_raceaway(msg->err_raceaway);
			proto_msg->set_btbrdy(msg->btbrdy);
			proto_msg->set_km_phasing_extend(msg->km_phasing_extend);
			proto_msg->set_rsw82(msg->rsw82);
			proto_msg->set_ecode_bit10__vccm99(msg->ecode_bit10__vccm99);
			proto_msg->set_ecode_bit10__vccm148(msg->ecode_bit10__vccm148);
			proto_msg->set_dup__bit10__park_rms(msg->dup__bit10__park_rms);
			proto_msg->set_ol_comp(msg->ol_comp);
			proto_msg->set_cal064(msg->cal064);
			proto_msg->set_err_user(msg->err_user);
			proto_msg->set_go216(msg->go216);
			proto_msg->set_cs_oora2(msg->cs_oora2);
			proto_msg->set_km_rsvd_11(msg->km_rsvd_11);
			proto_msg->set_cal082(msg->cal082);
			proto_msg->set_ecode_bit11__15m_minus99(msg->ecode_bit11__15m_minus99);
			proto_msg->set_ecode_bit11__15m_minus148(msg->ecode_bit11__15m_minus148);
			proto_msg->set_mo_sc1_comp(msg->mo_sc1_comp);
			proto_msg->set_dup__bit11__dcbus_volts(msg->dup__bit11__dcbus_volts);
			proto_msg->set_test(msg->test);
			proto_msg->set_motortype((primary::primary_inverter_l_rcv_motortype)msg->motortype);
			proto_msg->set_cal64(msg->cal64);
			proto_msg->set_out3(msg->out3);
			proto_msg->set_cs_cmd_type((primary::primary_inverter_l_rcv_cs_cmd_type)msg->cs_cmd_type);
			proto_msg->set_currentmode((primary::primary_inverter_l_rcv_currentmode)msg->currentmode);
			proto_msg->set_km_rsvd_12(msg->km_rsvd_12);
			proto_msg->set_cal82(msg->cal82);
			proto_msg->set_ecode_bit12__15m_plus99(msg->ecode_bit12__15m_plus99);
			proto_msg->set_ecode_bit12__15m_plus148(msg->ecode_bit12__15m_plus148);
			proto_msg->set_mo_sc2_reso((primary::primary_inverter_l_rcv_mo_sc2_reso)msg->mo_sc2_reso);
			proto_msg->set_dup__bit12__boat_pedal(msg->dup__bit12__boat_pedal);
			proto_msg->set_tol64(msg->tol64);
			proto_msg->set_out4(msg->out4);
			proto_msg->set_km_rsvd_13(msg->km_rsvd_13);
			proto_msg->set_tol82(msg->tol82);
			proto_msg->set_ecode_bit13__18m_plus99(msg->ecode_bit13__18m_plus99);
			proto_msg->set_ecode_bit13__18m_plus148(msg->ecode_bit13__18m_plus148);
			proto_msg->set_dup__bit13__gen_autoiaclimit(msg->dup__bit13__gen_autoiaclimit);
			proto_msg->set_ana_0up(msg->ana_0up);
			proto_msg->set_rdy64(msg->rdy64);
			proto_msg->set_err_hwerr(msg->err_hwerr);
			proto_msg->set_goff(msg->goff);
			proto_msg->set_cs_ain_2__i_limit(msg->cs_ain_2__i_limit);
			proto_msg->set_km_pseudo_enable(msg->km_pseudo_enable);
			proto_msg->set_rdy82(msg->rdy82);
			proto_msg->set_ecode_bit14__ubmam99(msg->ecode_bit14__ubmam99);
			proto_msg->set_ecode_bit14__ubmam148(msg->ecode_bit14__ubmam148);
			proto_msg->set_cmc__bit14__idc_limit_ena_v2(msg->cmc__bit14__idc_limit_ena_v2);
			proto_msg->set_dup__bit14__mtpa_reluct_enab(msg->dup__bit14__mtpa_reluct_enab);
			proto_msg->set_lowbd(msg->lowbd);
			proto_msg->set_brk064(msg->brk064);
			proto_msg->set_err_ballast(msg->err_ballast);
			proto_msg->set_brk1216(msg->brk1216);
			proto_msg->set_cs_ain_1__n_limit(msg->cs_ain_1__n_limit);
			proto_msg->set_km_debug_test(msg->km_debug_test);
			proto_msg->set_brk082(msg->brk082);
			proto_msg->set_ecode_bit15__t_igbt99(msg->ecode_bit15__t_igbt99);
			proto_msg->set_ecode_bit15__t_igbt148(msg->ecode_bit15__t_igbt148);
			proto_msg->set_mo_sc2_inv(msg->mo_sc2_inv);
			proto_msg->set_active190((primary::primary_inverter_l_rcv_active190)msg->active190);
			proto_msg->set_active191((primary::primary_inverter_l_rcv_active191)msg->active191);
			proto_msg->set_active192((primary::primary_inverter_l_rcv_active192)msg->active192);
			proto_msg->set_active193((primary::primary_inverter_l_rcv_active193)msg->active193);
			proto_msg->set_gen_autoiaclimit_is_acv(msg->gen_autoiaclimit_is_acv);
			proto_msg->set_cmc__bit15__dig_e_brake_act(msg->cmc__bit15__dig_e_brake_act);
			proto_msg->set_dup__bit15__canopen_acv(msg->dup__bit15__canopen_acv);
			proto_msg->set_m_r_dec(msg->m_r_dec);
			proto_msg->set_m_r_rcp(msg->m_r_rcp);
			proto_msg->set_sramp(msg->sramp);
			proto_msg->set_signmag64(msg->signmag64);
			proto_msg->set_warn_warning_0(msg->warn_warning_0);
			proto_msg->set_ain_in_1_scaled213(msg->ain_in_1_scaled213);
			proto_msg->set_ain_in_2_scaled214(msg->ain_in_2_scaled214);
			proto_msg->set_t_dc__stop(msg->t_dc__stop);
			proto_msg->set_v_dc__stop(msg->v_dc__stop);
			proto_msg->set_v_min__stop(msg->v_min__stop);
			proto_msg->set_f_min__stop(msg->f_min__stop);
			proto_msg->set_v_corner__stop(msg->v_corner__stop);
			proto_msg->set_f_corner__stop(msg->f_corner__stop);
			proto_msg->set_pid_i__kp__id(msg->pid_i__kp__id);
			proto_msg->set_pid_i__ti__id(msg->pid_i__ti__id);
			proto_msg->set_pid_i__tim__id(msg->pid_i__tim__id);
			proto_msg->set_ain_in_1_scaleval(msg->ain_in_1_scaleval);
			proto_msg->set_ain_in_2_scaleval(msg->ain_in_2_scaleval);
			proto_msg->set_signmag82(msg->signmag82);
			proto_msg->set_regen_r(msg->regen_r);
			proto_msg->set_dc_bus_max_lim(msg->dc_bus_max_lim);
			proto_msg->set_pid_i__xkp__id(msg->pid_i__xkp__id);
			proto_msg->set_bat_opr_limit__gen(msg->bat_opr_limit__gen);
			proto_msg->set_pid_i__kf__id(msg->pid_i__kf__id);
			proto_msg->set_cmc__bit17_16__checkipeak_config(msg->cmc__bit17_16__checkipeak_config);
			proto_msg->set_dup__bit16__bamobil3_2_offcrct(msg->dup__bit16__bamobil3_2_offcrct);
			proto_msg->set_special__stop(msg->special__stop);
			proto_msg->set_free(msg->free);
			proto_msg->set_svnrevision_nr(msg->svnrevision_nr);
			proto_msg->set_ramp4(msg->ramp4);
			proto_msg->set_nclip64(msg->nclip64);
			proto_msg->set_warn_illegal_status(msg->warn_illegal_status);
			proto_msg->set_nclip82(msg->nclip82);
			proto_msg->set_dup__bit19_17__ecode_redefine(msg->dup__bit19_17__ecode_redefine);
			proto_msg->set_motbrake(msg->motbrake);
			proto_msg->set_nclip_minus64(msg->nclip_minus64);
			proto_msg->set_warn_safe_in(msg->warn_safe_in);
			proto_msg->set_nclip_minus82(msg->nclip_minus82);
			proto_msg->set_cmc__bit18__tractioncontrol_ena(msg->cmc__bit18__tractioncontrol_ena);
			proto_msg->set_ac_dc(msg->ac_dc);
			proto_msg->set_nclip_plus64(msg->nclip_plus64);
			proto_msg->set_nclip_plus82(msg->nclip_plus82);
			proto_msg->set_cmc__bit20_19__tc_deltatime_conf(msg->cmc__bit20_19__tc_deltatime_conf);
			proto_msg->set_pwm_freq((primary::primary_inverter_l_rcv_pwm_freq)msg->pwm_freq);
			proto_msg->set_irddig64(msg->irddig64);
			proto_msg->set_irddig82(msg->irddig82);
			proto_msg->set_dup__bit20__hal_extmr_acv(msg->dup__bit20__hal_extmr_acv);
			proto_msg->set_iuserchd64(msg->iuserchd64);
			proto_msg->set_iuserchd82(msg->iuserchd82);
			proto_msg->set_cmc__bit22_21__tc_minspeed_conf(msg->cmc__bit22_21__tc_minspeed_conf);
			proto_msg->set_dup__bit21__initwith_frg_off(msg->dup__bit21__initwith_frg_off);
			proto_msg->set_irdn64(msg->irdn64);
			proto_msg->set_warn_motortemp(msg->warn_motortemp);
			proto_msg->set_irdn82(msg->irdn82);
			proto_msg->set_dup__bit31_22__free(msg->dup__bit31_22__free);
			proto_msg->set_ntc(msg->ntc);
			proto_msg->set_irdti64(msg->irdti64);
			proto_msg->set_warn_devicetemp(msg->warn_devicetemp);
			proto_msg->set_irdti82(msg->irdti82);
			proto_msg->set_cmc__bit23__tc_ncmdrestoption(msg->cmc__bit23__tc_ncmdrestoption);
			proto_msg->set_m_r_acc(msg->m_r_acc);
			proto_msg->set_delta(msg->delta);
			proto_msg->set_irdtir64(msg->irdtir64);
			proto_msg->set_warn_vout_sat(msg->warn_vout_sat);
			proto_msg->set_irdtir82(msg->irdtir82);
			proto_msg->set_cmc__bit31_24__free(msg->cmc__bit31_24__free);
			proto_msg->set_dc_1qdirvolt(msg->dc_1qdirvolt);
			proto_msg->set__10hz64(msg->_10hz64);
			proto_msg->set_warn_ipeak(msg->warn_ipeak);
			proto_msg->set__10hz82(msg->_10hz82);
			proto_msg->set_dc_field(msg->dc_field);
			proto_msg->set_irdtm64(msg->irdtm64);
			proto_msg->set_warn_raceaway(msg->warn_raceaway);
			proto_msg->set_irdtm82(msg->irdtm82);
			proto_msg->set_dead_2(msg->dead_2);
			proto_msg->set_irdana64(msg->irdana64);
			proto_msg->set_irdana82(msg->irdana82);
			proto_msg->set_block(msg->block);
			proto_msg->set_iwcns64(msg->iwcns64);
			proto_msg->set_iwcns82(msg->iwcns82);
			proto_msg->set_dc_1qmv(msg->dc_1qmv);
			proto_msg->set_rfepulse64(msg->rfepulse64);
			proto_msg->set_rfepulse82(msg->rfepulse82);
			proto_msg->set_dc_1q3p(msg->dc_1q3p);
			proto_msg->set_md64(msg->md64);
			proto_msg->set_md82(msg->md82);
			proto_msg->set_reducelosses(msg->reducelosses);
			proto_msg->set_hndwhl64(msg->hndwhl64);
			proto_msg->set_warn_ballast(msg->warn_ballast);
			proto_msg->set_hndwhl82(msg->hndwhl82);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 514: {
            primary_inverter_r_send_converted_t* msg = (primary_inverter_r_send_converted_t*)((*map)[index].message_conversion);
            primary::INVERTER_R_SEND* proto_msg = pack->add_inverter_r_send();
			proto_msg->set_send_mux(msg->send_mux);
			proto_msg->set_motor_f_n(msg->motor_f_n);
			proto_msg->set_t_dc__start(msg->t_dc__start);
			proto_msg->set_v_dc__start(msg->v_dc__start);
			proto_msg->set_special__start(msg->special__start);
			proto_msg->set_v_min__start(msg->v_min__start);
			proto_msg->set_f_min__start(msg->f_min__start);
			proto_msg->set_v_corner__start(msg->v_corner__start);
			proto_msg->set_f_corner__start(msg->f_corner__start);
			proto_msg->set_cos_phi(msg->cos_phi);
			proto_msg->set_extra__start(msg->extra__start);
			proto_msg->set_capture_channel(msg->capture_channel);
			proto_msg->set_trig_level(msg->trig_level);
			proto_msg->set_trig_edge(msg->trig_edge);
			proto_msg->set_trig_source(msg->trig_source);
			proto_msg->set_oszi_source(msg->oszi_source);
			proto_msg->set_oszi_skip(msg->oszi_skip);
			proto_msg->set_oszi_read_cmd(msg->oszi_read_cmd);
			proto_msg->set_oszi_run_cmd(msg->oszi_run_cmd);
			proto_msg->set_calib_ref_value(msg->calib_ref_value);
			proto_msg->set_pid_i__kp__iq(msg->pid_i__kp__iq);
			proto_msg->set_pid_i__ti__iq(msg->pid_i__ti__iq);
			proto_msg->set_cutoffdig(msg->cutoffdig);
			proto_msg->set_id_setdig__id(msg->id_setdig__id);
			proto_msg->set_i_delta_ramp(msg->i_delta_ramp);
			proto_msg->set_pid_i__tim__iq(msg->pid_i__tim__iq);
			proto_msg->set_pid_n__kp(msg->pid_n__kp);
			proto_msg->set_pid_n__ti(msg->pid_n__ti);
			proto_msg->set_pid_n__td(msg->pid_n__td);
			proto_msg->set_ain_in_1_offsetval(msg->ain_in_1_offsetval);
			proto_msg->set_n_setdig(msg->n_setdig);
			proto_msg->set_n_lim(msg->n_lim);
			proto_msg->set_n_r_acc(msg->n_r_acc);
			proto_msg->set_cs_ain_1_format(msg->cs_ain_1_format);
			proto_msg->set_pid_n__tim(msg->pid_n__tim);
			proto_msg->set_i_red_n(msg->i_red_n);
			proto_msg->set_n_lim_minus(msg->n_lim_minus);
			proto_msg->set_n_lim_plus(msg->n_lim_plus);
			proto_msg->set_fb_offset(msg->fb_offset);
			proto_msg->set_read_id(msg->read_id);
			proto_msg->set_i_lim_dig(msg->i_lim_dig);
			proto_msg->set_i_red_te(msg->i_red_te);
			proto_msg->set_i_max_eff(msg->i_max_eff);
			proto_msg->set_i_nom_eff(msg->i_nom_eff);
			proto_msg->set_motor_pole(msg->motor_pole);
			proto_msg->set_ain_in_1_cutoff(msg->ain_in_1_cutoff);
			proto_msg->set_km_rsvd_0(msg->km_rsvd_0);
			proto_msg->set_ain_in_2_cutoff(msg->ain_in_2_cutoff);
			proto_msg->set_i_red_td(msg->i_red_td);
			proto_msg->set_n_nom(msg->n_nom);
			proto_msg->set_dc_bus_comp(msg->dc_bus_comp);
			proto_msg->set_pid_n__kacc(msg->pid_n__kacc);
			proto_msg->set_speed_filter(msg->speed_filter);
			proto_msg->set_ain_in_1_filter(msg->ain_in_1_filter);
			proto_msg->set_snr(msg->snr);
			proto_msg->set_device_mains(msg->device_mains);
			proto_msg->set_regen_p(msg->regen_p);
			proto_msg->set_devicetype(msg->devicetype);
			proto_msg->set_can_id_rx(msg->can_id_rx);
			proto_msg->set_can_id_tx(msg->can_id_tx);
			proto_msg->set_pos_kp(msg->pos_kp);
			proto_msg->set_pos_ti(msg->pos_ti);
			proto_msg->set_pos_td(msg->pos_td);
			proto_msg->set_pos_dest(msg->pos_dest);
			proto_msg->set_pos_tim(msg->pos_tim);
			proto_msg->set_pos_offsref(msg->pos_offsref);
			proto_msg->set_can_nbt(msg->can_nbt);
			proto_msg->set_ref_reso_edge(msg->ref_reso_edge);
			proto_msg->set_speed_1(msg->speed_1);
			proto_msg->set_speed_2(msg->speed_2);
			proto_msg->set_pos_tol_win(msg->pos_tol_win);
			proto_msg->set_pos_preset_val(msg->pos_preset_val);
			proto_msg->set_pos_nd_scale(msg->pos_nd_scale);
			proto_msg->set_pos_nd_offset(msg->pos_nd_offset);
			proto_msg->set_fb2_scale_ext(msg->fb2_scale_ext);
			proto_msg->set_pos_offset_slack(msg->pos_offset_slack);
			proto_msg->set_pos_diff_slack(msg->pos_diff_slack);
			proto_msg->set_eprom131(msg->eprom131);
			proto_msg->set_eprom132(msg->eprom132);
			proto_msg->set_fun_special(msg->fun_special);
			proto_msg->set_can_id_2_rx(msg->can_id_2_rx);
			proto_msg->set_can_id_2_tx(msg->can_id_2_tx);
			proto_msg->set_v_ref(msg->v_ref);
			proto_msg->set_v_kp(msg->v_kp);
			proto_msg->set_v_ti(msg->v_ti);
			proto_msg->set_clear_errors(msg->clear_errors);
			proto_msg->set_m_setdig__iq(msg->m_setdig__iq);
			proto_msg->set_i_red_tm(msg->i_red_tm);
			proto_msg->set_m_temp(msg->m_temp);
			proto_msg->set_mo_feedback_1(msg->mo_feedback_1);
			proto_msg->set_dc_bus_min_lim(msg->dc_bus_min_lim);
			proto_msg->set_fb_incr_mot(msg->fb_incr_mot);
			proto_msg->set_fb_pole(msg->fb_pole);
			proto_msg->set_motor_lsq(msg->motor_lsq);
			proto_msg->set_id_nom(msg->id_nom);
			proto_msg->set_motor_lm(msg->motor_lm);
			proto_msg->set_motor_rr(msg->motor_rr);
			proto_msg->set_id_min(msg->id_min);
			proto_msg->set_motor_tr(msg->motor_tr);
			proto_msg->set_motor_lsd(msg->motor_lsd);
			proto_msg->set_motor_rs(msg->motor_rs);
			proto_msg->set_motor_ts(msg->motor_ts);
			proto_msg->set_def_end_1(msg->def_end_1);
			proto_msg->set_def_end_2(msg->def_end_2);
			proto_msg->set_def_din_1(msg->def_din_1);
			proto_msg->set_def_din_2(msg->def_din_2);
			proto_msg->set_operand194(msg->operand194);
			proto_msg->set_operand195(msg->operand195);
			proto_msg->set_operand218(msg->operand218);
			proto_msg->set_operand219(msg->operand219);
			proto_msg->set_i_max_pk(msg->i_max_pk);
			proto_msg->set_i_con_eff(msg->i_con_eff);
			proto_msg->set_i_device(msg->i_device);
			proto_msg->set_n_r_lim(msg->n_r_lim);
			proto_msg->set_nmax100perc(msg->nmax100perc);
			proto_msg->set_pid_i__xkp__iq(msg->pid_i__xkp__iq);
			proto_msg->set_bat_opr_limit__mot(msg->bat_opr_limit__mot);
			proto_msg->set_pid_i__kf__iq(msg->pid_i__kf__iq);
			proto_msg->set_cmc__bit0__dc_current_sens_ena(msg->cmc__bit0__dc_current_sens_ena);
			proto_msg->set_can_rxtimeout(msg->can_rxtimeout);
			proto_msg->set_var_1(msg->var_1);
			proto_msg->set_var_2(msg->var_2);
			proto_msg->set_var_3(msg->var_3);
			proto_msg->set_var_4(msg->var_4);
			proto_msg->set_ain_in_2_offsetval(msg->ain_in_2_offsetval);
			proto_msg->set_dup__bit7_0__dac_source_channel(msg->dup__bit7_0__dac_source_channel);
			proto_msg->set_n_r_dec(msg->n_r_dec);
			proto_msg->set_v_shunt(msg->v_shunt);
			proto_msg->set_t_peak(msg->t_peak);
			proto_msg->set_brake_delay(msg->brake_delay);
			proto_msg->set_axis(msg->axis);
			proto_msg->set_km_speed_0(msg->km_speed_0);
			proto_msg->set_ballast_ext(msg->ballast_ext);
			proto_msg->set_cmc__bit1__idc_limit_ena(msg->cmc__bit1__idc_limit_ena);
			proto_msg->set_cs_ain_2_format(msg->cs_ain_2_format);
			proto_msg->set_km_frg_off(msg->km_frg_off);
			proto_msg->set_fb_special(msg->fb_special);
			proto_msg->set_cmc__bit2__pdc_limit_usage(msg->cmc__bit2__pdc_limit_usage);
			proto_msg->set_km_cal_off(msg->km_cal_off);
			proto_msg->set_coaststop(msg->coaststop);
			proto_msg->set_cmc__bit3__torqueval_init_ena(msg->cmc__bit3__torqueval_init_ena);
			proto_msg->set_cs_ain_1_mode(msg->cs_ain_1_mode);
			proto_msg->set_km_tx_tog_stat(msg->km_tx_tog_stat);
			proto_msg->set_i_ist_inverse(msg->i_ist_inverse);
			proto_msg->set_compare_var194(msg->compare_var194);
			proto_msg->set_compare_var195(msg->compare_var195);
			proto_msg->set_compare_var218(msg->compare_var218);
			proto_msg->set_compare_var219(msg->compare_var219);
			proto_msg->set_cmc__bit4__dig_m_rcpramp_ena(msg->cmc__bit4__dig_m_rcpramp_ena);
			proto_msg->set_km_i_limit(msg->km_i_limit);
			proto_msg->set_refsoft(msg->refsoft);
			proto_msg->set_mo_feedback_2(msg->mo_feedback_2);
			proto_msg->set_cmc__bit5__reset_nramp_atnzero(msg->cmc__bit5__reset_nramp_atnzero);
			proto_msg->set_km_n_clip(msg->km_n_clip);
			proto_msg->set_no_uesp_btb(msg->no_uesp_btb);
			proto_msg->set_cmc__bit6__torquetimeout_100ms_e(msg->cmc__bit6__torquetimeout_100ms_e);
			proto_msg->set_cs_oora1(msg->cs_oora1);
			proto_msg->set_km_mix_ana_on(msg->km_mix_ana_on);
			proto_msg->set_vdc_ana(msg->vdc_ana);
			proto_msg->set_cmc__bit13_7__free(msg->cmc__bit13_7__free);
			proto_msg->set_cs_ain_2_mode(msg->cs_ain_2_mode);
			proto_msg->set_ret_interval(msg->ret_interval);
			proto_msg->set_km_allow_sync(msg->km_allow_sync);
			proto_msg->set_i1_adc_ena(msg->i1_adc_ena);
			proto_msg->set_ain_in_2_filter(msg->ain_in_2_filter);
			proto_msg->set_mo_sc1_reso(msg->mo_sc1_reso);
			proto_msg->set_source_id194(msg->source_id194);
			proto_msg->set_source_id195(msg->source_id195);
			proto_msg->set_source_id218(msg->source_id218);
			proto_msg->set_source_id219(msg->source_id219);
			proto_msg->set_dup__bit8__can_extended_0(msg->dup__bit8__can_extended_0);
			proto_msg->set_km_handwheel(msg->km_handwheel);
			proto_msg->set_hxinv(msg->hxinv);
			proto_msg->set_dup__bit9__generator(msg->dup__bit9__generator);
			proto_msg->set_km_phasing_extend(msg->km_phasing_extend);
			proto_msg->set_h2inv(msg->h2inv);
			proto_msg->set_dup__bit10__park_rms(msg->dup__bit10__park_rms);
			proto_msg->set_cs_oora2(msg->cs_oora2);
			proto_msg->set_km_rsvd_11(msg->km_rsvd_11);
			proto_msg->set_ol_comp(msg->ol_comp);
			proto_msg->set_mo_sc1_comp(msg->mo_sc1_comp);
			proto_msg->set_dup__bit11__dcbus_volts(msg->dup__bit11__dcbus_volts);
			proto_msg->set_cs_cmd_type(msg->cs_cmd_type);
			proto_msg->set_km_rsvd_12(msg->km_rsvd_12);
			proto_msg->set_motortype(msg->motortype);
			proto_msg->set_mo_sc2_reso(msg->mo_sc2_reso);
			proto_msg->set_dup__bit12__boat_pedal(msg->dup__bit12__boat_pedal);
			proto_msg->set_km_rsvd_13(msg->km_rsvd_13);
			proto_msg->set_dup__bit13__gen_autoiaclimit(msg->dup__bit13__gen_autoiaclimit);
			proto_msg->set_cs_ain_2__i_limit(msg->cs_ain_2__i_limit);
			proto_msg->set_km_pseudo_enable(msg->km_pseudo_enable);
			proto_msg->set_ana_0up(msg->ana_0up);
			proto_msg->set_cmc__bit14__idc_limit_ena_v2(msg->cmc__bit14__idc_limit_ena_v2);
			proto_msg->set_dup__bit14__mtpa_reluct_enab(msg->dup__bit14__mtpa_reluct_enab);
			proto_msg->set_cs_ain_1__n_limit(msg->cs_ain_1__n_limit);
			proto_msg->set_km_debug_test(msg->km_debug_test);
			proto_msg->set_lowbd(msg->lowbd);
			proto_msg->set_mo_sc2_inv(msg->mo_sc2_inv);
			proto_msg->set_active190(msg->active190);
			proto_msg->set_active191(msg->active191);
			proto_msg->set_active192(msg->active192);
			proto_msg->set_active193(msg->active193);
			proto_msg->set_cmc__bit15__dig_e_brake_act(msg->cmc__bit15__dig_e_brake_act);
			proto_msg->set_dup__bit15__canopen_acv(msg->dup__bit15__canopen_acv);
			proto_msg->set_t_dc__stop(msg->t_dc__stop);
			proto_msg->set_v_dc__stop(msg->v_dc__stop);
			proto_msg->set_special__stop(msg->special__stop);
			proto_msg->set_v_min__stop(msg->v_min__stop);
			proto_msg->set_f_min__stop(msg->f_min__stop);
			proto_msg->set_v_corner__stop(msg->v_corner__stop);
			proto_msg->set_f_corner__stop(msg->f_corner__stop);
			proto_msg->set_pid_i__kp__id(msg->pid_i__kp__id);
			proto_msg->set_pid_i__ti__id(msg->pid_i__ti__id);
			proto_msg->set_pid_i__tim__id(msg->pid_i__tim__id);
			proto_msg->set_ain_in_1_scaleval(msg->ain_in_1_scaleval);
			proto_msg->set_m_r_acc(msg->m_r_acc);
			proto_msg->set_sramp(msg->sramp);
			proto_msg->set_regen_r(msg->regen_r);
			proto_msg->set_dc_bus_max_lim(msg->dc_bus_max_lim);
			proto_msg->set_m_r_rcp(msg->m_r_rcp);
			proto_msg->set_pid_i__xkp__id(msg->pid_i__xkp__id);
			proto_msg->set_bat_opr_limit__gen(msg->bat_opr_limit__gen);
			proto_msg->set_pid_i__kf__id(msg->pid_i__kf__id);
			proto_msg->set_cmc__bit17_16__checkipeak_config(msg->cmc__bit17_16__checkipeak_config);
			proto_msg->set_ain_in_2_scaleval(msg->ain_in_2_scaleval);
			proto_msg->set_dup__bit16__bamobil3_2_offcrct(msg->dup__bit16__bamobil3_2_offcrct);
			proto_msg->set_m_r_dec(msg->m_r_dec);
			proto_msg->set_ramp4(msg->ramp4);
			proto_msg->set_dup__bit19_17__ecode_redefine(msg->dup__bit19_17__ecode_redefine);
			proto_msg->set_motbrake(msg->motbrake);
			proto_msg->set_cmc__bit18__tractioncontrol_ena(msg->cmc__bit18__tractioncontrol_ena);
			proto_msg->set_ac_dc(msg->ac_dc);
			proto_msg->set_cmc__bit20_19__tc_deltatime_conf(msg->cmc__bit20_19__tc_deltatime_conf);
			proto_msg->set_pwm_freq(msg->pwm_freq);
			proto_msg->set_dup__bit20__hal_extmr_acv(msg->dup__bit20__hal_extmr_acv);
			proto_msg->set_cmc__bit22_21__tc_minspeed_conf(msg->cmc__bit22_21__tc_minspeed_conf);
			proto_msg->set_dup__bit21__initwith_frg_off(msg->dup__bit21__initwith_frg_off);
			proto_msg->set_dup__bit31_22__free(msg->dup__bit31_22__free);
			proto_msg->set_ntc(msg->ntc);
			proto_msg->set_cmc__bit23__tc_ncmdrestoption(msg->cmc__bit23__tc_ncmdrestoption);
			proto_msg->set_delta(msg->delta);
			proto_msg->set_cmc__bit31_24__free(msg->cmc__bit31_24__free);
			proto_msg->set_dc_1qdirvolt(msg->dc_1qdirvolt);
			proto_msg->set_dc_field(msg->dc_field);
			proto_msg->set_dead_2(msg->dead_2);
			proto_msg->set_block(msg->block);
			proto_msg->set_dc_1qmv(msg->dc_1qmv);
			proto_msg->set_dc_1q3p(msg->dc_1q3p);
			proto_msg->set_reducelosses(msg->reducelosses);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 386: {
            primary_inverter_r_rcv_converted_t* msg = (primary_inverter_r_rcv_converted_t*)((*map)[index].message_conversion);
            primary::INVERTER_R_RCV* proto_msg = pack->add_inverter_r_rcv();
			proto_msg->set_rcv_mux(msg->rcv_mux);
			proto_msg->set_n_actual(msg->n_actual);
			proto_msg->set_n_r_dec(msg->n_r_dec);
			proto_msg->set_n_r_lim(msg->n_r_lim);
			proto_msg->set_n_actual_filt(msg->n_actual_filt);
			proto_msg->set_firmware(msg->firmware);
			proto_msg->set_devicetype(msg->devicetype);
			proto_msg->set_snr(msg->snr);
			proto_msg->set_axis(msg->axis);
			proto_msg->set_i_device(msg->i_device);
			proto_msg->set_v_shunt(msg->v_shunt);
			proto_msg->set_i_200perc(msg->i_200perc);
			proto_msg->set_dc_bus_comp(msg->dc_bus_comp);
			proto_msg->set_ena64(msg->ena64);
			proto_msg->set_err_badparas(msg->err_badparas);
			proto_msg->set_lmt1(msg->lmt1);
			proto_msg->set_ain_in_1_raw(msg->ain_in_1_raw);
			proto_msg->set_ain_in_2_raw(msg->ain_in_2_raw);
			proto_msg->set_nmax100perc(msg->nmax100perc);
			proto_msg->set_n_setdig(msg->n_setdig);
			proto_msg->set_n_cmd(msg->n_cmd);
			proto_msg->set_n_cmd_ramp(msg->n_cmd_ramp);
			proto_msg->set_n_lim(msg->n_lim);
			proto_msg->set_n_error(msg->n_error);
			proto_msg->set_m_setdig__iq(msg->m_setdig__iq);
			proto_msg->set_id_setdig__id(msg->id_setdig__id);
			proto_msg->set_i_max_pk(msg->i_max_pk);
			proto_msg->set_i_con_eff(msg->i_con_eff);
			proto_msg->set_i_max_eff(msg->i_max_eff);
			proto_msg->set_i_nom_eff(msg->i_nom_eff);
			proto_msg->set_i_limit_inuse(msg->i_limit_inuse);
			proto_msg->set_i_cmd(msg->i_cmd);
			proto_msg->set_i_cmd_ramp(msg->i_cmd_ramp);
			proto_msg->set_i_actual(msg->i_actual);
			proto_msg->set_i_actual_filt(msg->i_actual_filt);
			proto_msg->set_iq_actual(msg->iq_actual);
			proto_msg->set_id_actual(msg->id_actual);
			proto_msg->set_iq_error(msg->iq_error);
			proto_msg->set_id_error(msg->id_error);
			proto_msg->set_i1_actual(msg->i1_actual);
			proto_msg->set_i2_actual(msg->i2_actual);
			proto_msg->set_i3_actual(msg->i3_actual);
			proto_msg->set_i3_adc(msg->i3_adc);
			proto_msg->set_i2_adc(msg->i2_adc);
			proto_msg->set_vq(msg->vq);
			proto_msg->set_vd(msg->vd);
			proto_msg->set_vout(msg->vout);
			proto_msg->set_t_motor(msg->t_motor);
			proto_msg->set_t_igbt(msg->t_igbt);
			proto_msg->set_t_air(msg->t_air);
			proto_msg->set_vdc_bus_filt(msg->vdc_bus_filt);
			proto_msg->set_end_1(msg->end_1);
			proto_msg->set_din_1(msg->din_1);
			proto_msg->set_end_2(msg->end_2);
			proto_msg->set_din_2(msg->din_2);
			proto_msg->set_run232(msg->run232);
			proto_msg->set_dout_1(msg->dout_1);
			proto_msg->set_dout_2(msg->dout_2);
			proto_msg->set_dout_3(msg->dout_3);
			proto_msg->set_rdy_btb(msg->rdy_btb);
			proto_msg->set_i_fault(msg->i_fault);
			proto_msg->set_dout_4(msg->dout_4);
			proto_msg->set_i_lim_dig(msg->i_lim_dig);
			proto_msg->set_i_red_n(msg->i_red_n);
			proto_msg->set_i_red_td(msg->i_red_td);
			proto_msg->set_i_red_te(msg->i_red_te);
			proto_msg->set_i_red_tm(msg->i_red_tm);
			proto_msg->set_cs_ain_1_format(msg->cs_ain_1_format);
			proto_msg->set_id_ref(msg->id_ref);
			proto_msg->set_m_outdig__iq(msg->m_outdig__iq);
			proto_msg->set_ptr_1_debug(msg->ptr_1_debug);
			proto_msg->set_ptr_2_debug(msg->ptr_2_debug);
			proto_msg->set_temp_debug(msg->temp_debug);
			proto_msg->set_motor_f_n(msg->motor_f_n);
			proto_msg->set_motor_v_n(msg->motor_v_n);
			proto_msg->set_t_dc__start(msg->t_dc__start);
			proto_msg->set_v_dc__start(msg->v_dc__start);
			proto_msg->set_v_min__start(msg->v_min__start);
			proto_msg->set_f_min__start(msg->f_min__start);
			proto_msg->set_v_corner__start(msg->v_corner__start);
			proto_msg->set_f_corner__start(msg->f_corner__start);
			proto_msg->set_cos_phi(msg->cos_phi);
			proto_msg->set_pwm_enum(msg->pwm_enum);
			proto_msg->set_calib_ref_value(msg->calib_ref_value);
			proto_msg->set_pid_i__kp__iq(msg->pid_i__kp__iq);
			proto_msg->set_pid_i__ti__iq(msg->pid_i__ti__iq);
			proto_msg->set_cutoffdig(msg->cutoffdig);
			proto_msg->set_i3_offset(msg->i3_offset);
			proto_msg->set_i_delta_ramp(msg->i_delta_ramp);
			proto_msg->set_pid_i__tim__iq(msg->pid_i__tim__iq);
			proto_msg->set_pid_n__kp(msg->pid_n__kp);
			proto_msg->set_v_ti(msg->v_ti);
			proto_msg->set_pid_n__td(msg->pid_n__td);
			proto_msg->set_ain_in_1_offsetval(msg->ain_in_1_offsetval);
			proto_msg->set_ain_in_2_offsetval(msg->ain_in_2_offsetval);
			proto_msg->set_dzr_seq(msg->dzr_seq);
			proto_msg->set_pid_n__tim(msg->pid_n__tim);
			proto_msg->set_n_lim_plus(msg->n_lim_plus);
			proto_msg->set_n_lim_minus(msg->n_lim_minus);
			proto_msg->set_incr_delta(msg->incr_delta);
			proto_msg->set_motorpos_mech(msg->motorpos_mech);
			proto_msg->set_motorpos_elec(msg->motorpos_elec);
			proto_msg->set_fb_offset(msg->fb_offset);
			proto_msg->set_it_rg_monitor(msg->it_rg_monitor);
			proto_msg->set_motor_pole(msg->motor_pole);
			proto_msg->set_ain_in_1_cutoff(msg->ain_in_1_cutoff);
			proto_msg->set_activecontrolmode(msg->activecontrolmode);
			proto_msg->set_km_rsvd_0(msg->km_rsvd_0);
			proto_msg->set_ena82(msg->ena82);
			proto_msg->set_ain_in_2_cutoff(msg->ain_in_2_cutoff);
			proto_msg->set_i_limit_inuse_ramp(msg->i_limit_inuse_ramp);
			proto_msg->set_n_nom(msg->n_nom);
			proto_msg->set_pid_n__kacc(msg->pid_n__kacc);
			proto_msg->set_rotor_signals(msg->rotor_signals);
			proto_msg->set_speed_filter(msg->speed_filter);
			proto_msg->set_ain_in_1_filter(msg->ain_in_1_filter);
			proto_msg->set_ixt_monitor(msg->ixt_monitor);
			proto_msg->set_ecode_bit0_firsterrordtcd99(msg->ecode_bit0_firsterrordtcd99);
			proto_msg->set_device_mains(msg->device_mains);
			proto_msg->set_regen_p(msg->regen_p);
			proto_msg->set_can_id_rx(msg->can_id_rx);
			proto_msg->set_can_id_tx(msg->can_id_tx);
			proto_msg->set_pos_kp(msg->pos_kp);
			proto_msg->set_pos_ti(msg->pos_ti);
			proto_msg->set_pos_td(msg->pos_td);
			proto_msg->set_pos_actual(msg->pos_actual);
			proto_msg->set_pos_dest(msg->pos_dest);
			proto_msg->set_pos_actual_2(msg->pos_actual_2);
			proto_msg->set_pos_error(msg->pos_error);
			proto_msg->set_pos_tim(msg->pos_tim);
			proto_msg->set_pos_offsref(msg->pos_offsref);
			proto_msg->set_can_nbt(msg->can_nbt);
			proto_msg->set_pos_zero_capture(msg->pos_zero_capture);
			proto_msg->set_ref_reso_edge(msg->ref_reso_edge);
			proto_msg->set_speed_1(msg->speed_1);
			proto_msg->set_speed_2(msg->speed_2);
			proto_msg->set_pos_tol_win(msg->pos_tol_win);
			proto_msg->set_pos_preset_val(msg->pos_preset_val);
			proto_msg->set_pos_zero_offset(msg->pos_zero_offset);
			proto_msg->set_pos_nd_scale(msg->pos_nd_scale);
			proto_msg->set_pos_nd_offset(msg->pos_nd_offset);
			proto_msg->set_fb2_scale_ext(msg->fb2_scale_ext);
			proto_msg->set_pos_offset_slack(msg->pos_offset_slack);
			proto_msg->set_pos_diff_slack(msg->pos_diff_slack);
			proto_msg->set_fun_para_read(msg->fun_para_read);
			proto_msg->set_fun_para_write(msg->fun_para_write);
			proto_msg->set_fun_special(msg->fun_special);
			proto_msg->set_can_id_2_rx(msg->can_id_2_rx);
			proto_msg->set_can_id_2_tx(msg->can_id_2_tx);
			proto_msg->set_v_ref(msg->v_ref);
			proto_msg->set_v_kp(msg->v_kp);
			proto_msg->set_pid_n__ti(msg->pid_n__ti);
			proto_msg->set_clear_errors(msg->clear_errors);
			proto_msg->set_pos_cmd(msg->pos_cmd);
			proto_msg->set_can_error_busoff(msg->can_error_busoff);
			proto_msg->set_can_error_writetime(msg->can_error_writetime);
			proto_msg->set_ecode_bit0_firsterrordtcd148(msg->ecode_bit0_firsterrordtcd148);
			proto_msg->set_can_error_no_ack(msg->can_error_no_ack);
			proto_msg->set_can_error_crc_check150(msg->can_error_crc_check150);
			proto_msg->set_can_error_crc_check151(msg->can_error_crc_check151);
			proto_msg->set_info_timer_diff(msg->info_timer_diff);
			proto_msg->set_ballastcount(msg->ballastcount);
			proto_msg->set_m_temp(msg->m_temp);
			proto_msg->set_mo_feedback_1(msg->mo_feedback_1);
			proto_msg->set_dc_bus_min_lim(msg->dc_bus_min_lim);
			proto_msg->set_fb_incr_mot(msg->fb_incr_mot);
			proto_msg->set_fb_pole(msg->fb_pole);
			proto_msg->set_logic_freq(msg->logic_freq);
			proto_msg->set_pwm_1(msg->pwm_1);
			proto_msg->set_pwm_2(msg->pwm_2);
			proto_msg->set_pwm_3(msg->pwm_3);
			proto_msg->set_timer_delta(msg->timer_delta);
			proto_msg->set_motor_lsq(msg->motor_lsq);
			proto_msg->set_motor_lsd(msg->motor_lsd);
			proto_msg->set_id_nom(msg->id_nom);
			proto_msg->set_motor_lm(msg->motor_lm);
			proto_msg->set_motor_rr(msg->motor_rr);
			proto_msg->set_id_min(msg->id_min);
			proto_msg->set_motor_tr(msg->motor_tr);
			proto_msg->set_motor_rs(msg->motor_rs);
			proto_msg->set_motor_ts(msg->motor_ts);
			proto_msg->set_def_end_1(msg->def_end_1);
			proto_msg->set_def_end_2(msg->def_end_2);
			proto_msg->set_def_din_1(msg->def_din_1);
			proto_msg->set_def_din_2(msg->def_din_2);
			proto_msg->set_operand194(msg->operand194);
			proto_msg->set_i_max_inuse(msg->i_max_inuse);
			proto_msg->set_signal_go(msg->signal_go);
			proto_msg->set_signal_brake(msg->signal_brake);
			proto_msg->set_signal_icns(msg->signal_icns);
			proto_msg->set_signal_lessn0(msg->signal_lessn0);
			proto_msg->set_signal_postolerance(msg->signal_postolerance);
			proto_msg->set_ain_in_1_scaled251(msg->ain_in_1_scaled251);
			proto_msg->set_ain_in_2_scaled252(msg->ain_in_2_scaled252);
			proto_msg->set_operand195(msg->operand195);
			proto_msg->set_operand218(msg->operand218);
			proto_msg->set_operand219(msg->operand219);
			proto_msg->set_pid_i__xkp__iq(msg->pid_i__xkp__iq);
			proto_msg->set_bat_opr_limit__mot(msg->bat_opr_limit__mot);
			proto_msg->set_pid_i__kf__iq(msg->pid_i__kf__iq);
			proto_msg->set_dc_current_sens_ena_set(msg->dc_current_sens_ena_set);
			proto_msg->set_cmc__bit0__dc_current_sens_ena(msg->cmc__bit0__dc_current_sens_ena);
			proto_msg->set_n_rpm_maxint(msg->n_rpm_maxint);
			proto_msg->set_var_1(msg->var_1);
			proto_msg->set_can_rxtimeout(msg->can_rxtimeout);
			proto_msg->set_var_2(msg->var_2);
			proto_msg->set_var_3(msg->var_3);
			proto_msg->set_var_4(msg->var_4);
			proto_msg->set_dup__bit7_0__dac_source_channel(msg->dup__bit7_0__dac_source_channel);
			proto_msg->set_fb_lossofsignal(msg->fb_lossofsignal);
			proto_msg->set_no_hw_fault(msg->no_hw_fault);
			proto_msg->set_t_peak(msg->t_peak);
			proto_msg->set_brake_delay(msg->brake_delay);
			proto_msg->set_power(msg->power);
			proto_msg->set_work(msg->work);
			proto_msg->set_extra__start(msg->extra__start);
			proto_msg->set_capture_channel(msg->capture_channel);
			proto_msg->set_trig_level(msg->trig_level);
			proto_msg->set_trig_edge(msg->trig_edge);
			proto_msg->set_trig_source(msg->trig_source);
			proto_msg->set_oszi_source(msg->oszi_source);
			proto_msg->set_oszi_skip(msg->oszi_skip);
			proto_msg->set_oszi_run_cmd(msg->oszi_run_cmd);
			proto_msg->set_oszi_read_cmd(msg->oszi_read_cmd);
			proto_msg->set_pos_ref_start(msg->pos_ref_start);
			proto_msg->set_vdc_bus(msg->vdc_bus);
			proto_msg->set_m_cmd_ramp(msg->m_cmd_ramp);
			proto_msg->set_lmt_1(msg->lmt_1);
			proto_msg->set_out_1(msg->out_1);
			proto_msg->set_subversion_nr(msg->subversion_nr);
			proto_msg->set_ballast_ext(msg->ballast_ext);
			proto_msg->set_ncr064(msg->ncr064);
			proto_msg->set_err_powerfault(msg->err_powerfault);
			proto_msg->set_lmt2(msg->lmt2);
			proto_msg->set_km_speed_0(msg->km_speed_0);
			proto_msg->set_ncr082(msg->ncr082);
			proto_msg->set_ecode_bit1__hw1_state99(msg->ecode_bit1__hw1_state99);
			proto_msg->set_ecode_bit1__hw1_state148(msg->ecode_bit1__hw1_state148);
			proto_msg->set_dc_i_sensena_set(msg->dc_i_sensena_set);
			proto_msg->set_cmc__bit1__idc_limit_ena(msg->cmc__bit1__idc_limit_ena);
			proto_msg->set_lmt_2(msg->lmt_2);
			proto_msg->set_out_2(msg->out_2);
			proto_msg->set_fb_special(msg->fb_special);
			proto_msg->set_lim_plus64(msg->lim_plus64);
			proto_msg->set_err_rfe_fault(msg->err_rfe_fault);
			proto_msg->set_in2(msg->in2);
			proto_msg->set_cs_ain_2_format(msg->cs_ain_2_format);
			proto_msg->set_km_frg_off(msg->km_frg_off);
			proto_msg->set_lim_plus82(msg->lim_plus82);
			proto_msg->set_ecode_bit2__hw0_state99(msg->ecode_bit2__hw0_state99);
			proto_msg->set_ecode_bit2__hw0_state148(msg->ecode_bit2__hw0_state148);
			proto_msg->set_op_mode_quadrant(msg->op_mode_quadrant);
			proto_msg->set_cmc__bit2__pdc_limit_usage(msg->cmc__bit2__pdc_limit_usage);
			proto_msg->set_in_2(msg->in_2);
			proto_msg->set_rdy155(msg->rdy155);
			proto_msg->set_coaststop(msg->coaststop);
			proto_msg->set_lim_minus64(msg->lim_minus64);
			proto_msg->set_err_bustimeout(msg->err_bustimeout);
			proto_msg->set_in1(msg->in1);
			proto_msg->set_km_cal_off(msg->km_cal_off);
			proto_msg->set_lim_minus82(msg->lim_minus82);
			proto_msg->set_ecode_bit3__free99(msg->ecode_bit3__free99);
			proto_msg->set_ecode_bit3__free148(msg->ecode_bit3__free148);
			proto_msg->set_cmc__bit3__torqueval_init_ena(msg->cmc__bit3__torqueval_init_ena);
			proto_msg->set_in_1(msg->in_1);
			proto_msg->set_go155(msg->go155);
			proto_msg->set_i_ist_inverse(msg->i_ist_inverse);
			proto_msg->set_ok64(msg->ok64);
			proto_msg->set_err_feedbacksignal(msg->err_feedbacksignal);
			proto_msg->set_frgrun(msg->frgrun);
			proto_msg->set_cs_ain_1_mode(msg->cs_ain_1_mode);
			proto_msg->set_km_tx_tog_stat(msg->km_tx_tog_stat);
			proto_msg->set_ok82(msg->ok82);
			proto_msg->set_ecode_bit4__rdy399(msg->ecode_bit4__rdy399);
			proto_msg->set_ecode_bit4__rdy3148(msg->ecode_bit4__rdy3148);
			proto_msg->set_compare_var194(msg->compare_var194);
			proto_msg->set_compare_var195(msg->compare_var195);
			proto_msg->set_compare_var218(msg->compare_var218);
			proto_msg->set_compare_var219(msg->compare_var219);
			proto_msg->set_cmc__bit4__dig_m_rcpramp_ena(msg->cmc__bit4__dig_m_rcpramp_ena);
			proto_msg->set_run152(msg->run152);
			proto_msg->set_out_3(msg->out_3);
			proto_msg->set_refsoft(msg->refsoft);
			proto_msg->set_icns64(msg->icns64);
			proto_msg->set_err_powervoltage_low(msg->err_powervoltage_low);
			proto_msg->set_rfe216(msg->rfe216);
			proto_msg->set_km_i_limit(msg->km_i_limit);
			proto_msg->set_icns82(msg->icns82);
			proto_msg->set_ecode_bit5__n_fail99(msg->ecode_bit5__n_fail99);
			proto_msg->set_ecode_bit5__n_fail148(msg->ecode_bit5__n_fail148);
			proto_msg->set_mo_feedback_2(msg->mo_feedback_2);
			proto_msg->set_recup_is_acv(msg->recup_is_acv);
			proto_msg->set_cmc__bit5__reset_nramp_atnzero(msg->cmc__bit5__reset_nramp_atnzero);
			proto_msg->set_rfe152(msg->rfe152);
			proto_msg->set_out_4(msg->out_4);
			proto_msg->set_no_uesp_btb(msg->no_uesp_btb);
			proto_msg->set_tnlim64(msg->tnlim64);
			proto_msg->set_err_motortemp(msg->err_motortemp);
			proto_msg->set_km_n_clip(msg->km_n_clip);
			proto_msg->set_tnlim82(msg->tnlim82);
			proto_msg->set_ecode_bit6__flths99(msg->ecode_bit6__flths99);
			proto_msg->set_ecode_bit6__flths148(msg->ecode_bit6__flths148);
			proto_msg->set_i_dc_limit_is_acv(msg->i_dc_limit_is_acv);
			proto_msg->set_cmc__bit6__torquetimeout_100ms_e(msg->cmc__bit6__torquetimeout_100ms_e);
			proto_msg->set_rsvd(msg->rsvd);
			proto_msg->set_rsvd1(msg->rsvd1);
			proto_msg->set_vdc_ana(msg->vdc_ana);
			proto_msg->set_pn64(msg->pn64);
			proto_msg->set_err_devicetemp(msg->err_devicetemp);
			proto_msg->set_cs_oora1(msg->cs_oora1);
			proto_msg->set_km_mix_ana_on(msg->km_mix_ana_on);
			proto_msg->set_pn82(msg->pn82);
			proto_msg->set_ecode_bit7__fltls99(msg->ecode_bit7__fltls99);
			proto_msg->set_ecode_bit7__fltls148(msg->ecode_bit7__fltls148);
			proto_msg->set_cmc__bit13_7__free(msg->cmc__bit13_7__free);
			proto_msg->set_brk1155(msg->brk1155);
			proto_msg->set_i1_adc_ena(msg->i1_adc_ena);
			proto_msg->set_ni64(msg->ni64);
			proto_msg->set_err_overvoltage(msg->err_overvoltage);
			proto_msg->set_out1(msg->out1);
			proto_msg->set_cs_ain_2_mode(msg->cs_ain_2_mode);
			proto_msg->set_ctrlsubmode(msg->ctrlsubmode);
			proto_msg->set_km_allow_sync(msg->km_allow_sync);
			proto_msg->set_ni82(msg->ni82);
			proto_msg->set_ain_in_2_filter(msg->ain_in_2_filter);
			proto_msg->set_ecode_bit8__fail_idc99(msg->ecode_bit8__fail_idc99);
			proto_msg->set_ecode_bit8__fail_idc148(msg->ecode_bit8__fail_idc148);
			proto_msg->set_mo_sc1_reso(msg->mo_sc1_reso);
			proto_msg->set_source_id194(msg->source_id194);
			proto_msg->set_source_id195(msg->source_id195);
			proto_msg->set_source_id218(msg->source_id218);
			proto_msg->set_source_id219(msg->source_id219);
			proto_msg->set_dup__bit8__can_extended_0(msg->dup__bit8__can_extended_0);
			proto_msg->set_hxinv(msg->hxinv);
			proto_msg->set__n064(msg->_n064);
			proto_msg->set_err_ipeak(msg->err_ipeak);
			proto_msg->set_out2(msg->out2);
			proto_msg->set_km_handwheel(msg->km_handwheel);
			proto_msg->set__n082(msg->_n082);
			proto_msg->set_ecode_bit9__fail_i99(msg->ecode_bit9__fail_i99);
			proto_msg->set_ecode_bit9__fail_i148(msg->ecode_bit9__fail_i148);
			proto_msg->set_dup__bit9__generator(msg->dup__bit9__generator);
			proto_msg->set_h2inv(msg->h2inv);
			proto_msg->set_rsw64(msg->rsw64);
			proto_msg->set_err_raceaway(msg->err_raceaway);
			proto_msg->set_btbrdy(msg->btbrdy);
			proto_msg->set_km_phasing_extend(msg->km_phasing_extend);
			proto_msg->set_rsw82(msg->rsw82);
			proto_msg->set_ecode_bit10__vccm99(msg->ecode_bit10__vccm99);
			proto_msg->set_ecode_bit10__vccm148(msg->ecode_bit10__vccm148);
			proto_msg->set_dup__bit10__park_rms(msg->dup__bit10__park_rms);
			proto_msg->set_ol_comp(msg->ol_comp);
			proto_msg->set_cal064(msg->cal064);
			proto_msg->set_err_user(msg->err_user);
			proto_msg->set_go216(msg->go216);
			proto_msg->set_cs_oora2(msg->cs_oora2);
			proto_msg->set_km_rsvd_11(msg->km_rsvd_11);
			proto_msg->set_cal082(msg->cal082);
			proto_msg->set_ecode_bit11__15m_minus99(msg->ecode_bit11__15m_minus99);
			proto_msg->set_ecode_bit11__15m_minus148(msg->ecode_bit11__15m_minus148);
			proto_msg->set_mo_sc1_comp(msg->mo_sc1_comp);
			proto_msg->set_dup__bit11__dcbus_volts(msg->dup__bit11__dcbus_volts);
			proto_msg->set_test(msg->test);
			proto_msg->set_motortype(msg->motortype);
			proto_msg->set_cal64(msg->cal64);
			proto_msg->set_out3(msg->out3);
			proto_msg->set_cs_cmd_type(msg->cs_cmd_type);
			proto_msg->set_currentmode(msg->currentmode);
			proto_msg->set_km_rsvd_12(msg->km_rsvd_12);
			proto_msg->set_cal82(msg->cal82);
			proto_msg->set_ecode_bit12__15m_plus99(msg->ecode_bit12__15m_plus99);
			proto_msg->set_ecode_bit12__15m_plus148(msg->ecode_bit12__15m_plus148);
			proto_msg->set_mo_sc2_reso(msg->mo_sc2_reso);
			proto_msg->set_dup__bit12__boat_pedal(msg->dup__bit12__boat_pedal);
			proto_msg->set_tol64(msg->tol64);
			proto_msg->set_out4(msg->out4);
			proto_msg->set_km_rsvd_13(msg->km_rsvd_13);
			proto_msg->set_tol82(msg->tol82);
			proto_msg->set_ecode_bit13__18m_plus99(msg->ecode_bit13__18m_plus99);
			proto_msg->set_ecode_bit13__18m_plus148(msg->ecode_bit13__18m_plus148);
			proto_msg->set_dup__bit13__gen_autoiaclimit(msg->dup__bit13__gen_autoiaclimit);
			proto_msg->set_ana_0up(msg->ana_0up);
			proto_msg->set_rdy64(msg->rdy64);
			proto_msg->set_err_hwerr(msg->err_hwerr);
			proto_msg->set_goff(msg->goff);
			proto_msg->set_cs_ain_2__i_limit(msg->cs_ain_2__i_limit);
			proto_msg->set_km_pseudo_enable(msg->km_pseudo_enable);
			proto_msg->set_rdy82(msg->rdy82);
			proto_msg->set_ecode_bit14__ubmam99(msg->ecode_bit14__ubmam99);
			proto_msg->set_ecode_bit14__ubmam148(msg->ecode_bit14__ubmam148);
			proto_msg->set_cmc__bit14__idc_limit_ena_v2(msg->cmc__bit14__idc_limit_ena_v2);
			proto_msg->set_dup__bit14__mtpa_reluct_enab(msg->dup__bit14__mtpa_reluct_enab);
			proto_msg->set_lowbd(msg->lowbd);
			proto_msg->set_brk064(msg->brk064);
			proto_msg->set_err_ballast(msg->err_ballast);
			proto_msg->set_brk1216(msg->brk1216);
			proto_msg->set_cs_ain_1__n_limit(msg->cs_ain_1__n_limit);
			proto_msg->set_km_debug_test(msg->km_debug_test);
			proto_msg->set_brk082(msg->brk082);
			proto_msg->set_ecode_bit15__t_igbt99(msg->ecode_bit15__t_igbt99);
			proto_msg->set_ecode_bit15__t_igbt148(msg->ecode_bit15__t_igbt148);
			proto_msg->set_mo_sc2_inv(msg->mo_sc2_inv);
			proto_msg->set_active190(msg->active190);
			proto_msg->set_active191(msg->active191);
			proto_msg->set_active192(msg->active192);
			proto_msg->set_active193(msg->active193);
			proto_msg->set_gen_autoiaclimit_is_acv(msg->gen_autoiaclimit_is_acv);
			proto_msg->set_cmc__bit15__dig_e_brake_act(msg->cmc__bit15__dig_e_brake_act);
			proto_msg->set_dup__bit15__canopen_acv(msg->dup__bit15__canopen_acv);
			proto_msg->set_m_r_dec(msg->m_r_dec);
			proto_msg->set_m_r_rcp(msg->m_r_rcp);
			proto_msg->set_sramp(msg->sramp);
			proto_msg->set_signmag64(msg->signmag64);
			proto_msg->set_warn_warning_0(msg->warn_warning_0);
			proto_msg->set_ain_in_1_scaled213(msg->ain_in_1_scaled213);
			proto_msg->set_ain_in_2_scaled214(msg->ain_in_2_scaled214);
			proto_msg->set_t_dc__stop(msg->t_dc__stop);
			proto_msg->set_v_dc__stop(msg->v_dc__stop);
			proto_msg->set_v_min__stop(msg->v_min__stop);
			proto_msg->set_f_min__stop(msg->f_min__stop);
			proto_msg->set_v_corner__stop(msg->v_corner__stop);
			proto_msg->set_f_corner__stop(msg->f_corner__stop);
			proto_msg->set_pid_i__kp__id(msg->pid_i__kp__id);
			proto_msg->set_pid_i__ti__id(msg->pid_i__ti__id);
			proto_msg->set_pid_i__tim__id(msg->pid_i__tim__id);
			proto_msg->set_ain_in_1_scaleval(msg->ain_in_1_scaleval);
			proto_msg->set_ain_in_2_scaleval(msg->ain_in_2_scaleval);
			proto_msg->set_signmag82(msg->signmag82);
			proto_msg->set_regen_r(msg->regen_r);
			proto_msg->set_dc_bus_max_lim(msg->dc_bus_max_lim);
			proto_msg->set_pid_i__xkp__id(msg->pid_i__xkp__id);
			proto_msg->set_bat_opr_limit__gen(msg->bat_opr_limit__gen);
			proto_msg->set_pid_i__kf__id(msg->pid_i__kf__id);
			proto_msg->set_cmc__bit17_16__checkipeak_config(msg->cmc__bit17_16__checkipeak_config);
			proto_msg->set_dup__bit16__bamobil3_2_offcrct(msg->dup__bit16__bamobil3_2_offcrct);
			proto_msg->set_special__stop(msg->special__stop);
			proto_msg->set_free(msg->free);
			proto_msg->set_svnrevision_nr(msg->svnrevision_nr);
			proto_msg->set_ramp4(msg->ramp4);
			proto_msg->set_nclip64(msg->nclip64);
			proto_msg->set_warn_illegal_status(msg->warn_illegal_status);
			proto_msg->set_nclip82(msg->nclip82);
			proto_msg->set_dup__bit19_17__ecode_redefine(msg->dup__bit19_17__ecode_redefine);
			proto_msg->set_motbrake(msg->motbrake);
			proto_msg->set_nclip_minus64(msg->nclip_minus64);
			proto_msg->set_warn_safe_in(msg->warn_safe_in);
			proto_msg->set_nclip_minus82(msg->nclip_minus82);
			proto_msg->set_cmc__bit18__tractioncontrol_ena(msg->cmc__bit18__tractioncontrol_ena);
			proto_msg->set_ac_dc(msg->ac_dc);
			proto_msg->set_nclip_plus64(msg->nclip_plus64);
			proto_msg->set_nclip_plus82(msg->nclip_plus82);
			proto_msg->set_cmc__bit20_19__tc_deltatime_conf(msg->cmc__bit20_19__tc_deltatime_conf);
			proto_msg->set_pwm_freq(msg->pwm_freq);
			proto_msg->set_irddig64(msg->irddig64);
			proto_msg->set_irddig82(msg->irddig82);
			proto_msg->set_dup__bit20__hal_extmr_acv(msg->dup__bit20__hal_extmr_acv);
			proto_msg->set_iuserchd64(msg->iuserchd64);
			proto_msg->set_iuserchd82(msg->iuserchd82);
			proto_msg->set_cmc__bit22_21__tc_minspeed_conf(msg->cmc__bit22_21__tc_minspeed_conf);
			proto_msg->set_dup__bit21__initwith_frg_off(msg->dup__bit21__initwith_frg_off);
			proto_msg->set_irdn64(msg->irdn64);
			proto_msg->set_warn_motortemp(msg->warn_motortemp);
			proto_msg->set_irdn82(msg->irdn82);
			proto_msg->set_dup__bit31_22__free(msg->dup__bit31_22__free);
			proto_msg->set_ntc(msg->ntc);
			proto_msg->set_irdti64(msg->irdti64);
			proto_msg->set_warn_devicetemp(msg->warn_devicetemp);
			proto_msg->set_irdti82(msg->irdti82);
			proto_msg->set_cmc__bit23__tc_ncmdrestoption(msg->cmc__bit23__tc_ncmdrestoption);
			proto_msg->set_m_r_acc(msg->m_r_acc);
			proto_msg->set_delta(msg->delta);
			proto_msg->set_irdtir64(msg->irdtir64);
			proto_msg->set_warn_vout_sat(msg->warn_vout_sat);
			proto_msg->set_irdtir82(msg->irdtir82);
			proto_msg->set_cmc__bit31_24__free(msg->cmc__bit31_24__free);
			proto_msg->set_dc_1qdirvolt(msg->dc_1qdirvolt);
			proto_msg->set__10hz64(msg->_10hz64);
			proto_msg->set_warn_ipeak(msg->warn_ipeak);
			proto_msg->set__10hz82(msg->_10hz82);
			proto_msg->set_dc_field(msg->dc_field);
			proto_msg->set_irdtm64(msg->irdtm64);
			proto_msg->set_warn_raceaway(msg->warn_raceaway);
			proto_msg->set_irdtm82(msg->irdtm82);
			proto_msg->set_dead_2(msg->dead_2);
			proto_msg->set_irdana64(msg->irdana64);
			proto_msg->set_irdana82(msg->irdana82);
			proto_msg->set_block(msg->block);
			proto_msg->set_iwcns64(msg->iwcns64);
			proto_msg->set_iwcns82(msg->iwcns82);
			proto_msg->set_dc_1qmv(msg->dc_1qmv);
			proto_msg->set_rfepulse64(msg->rfepulse64);
			proto_msg->set_rfepulse82(msg->rfepulse82);
			proto_msg->set_dc_1q3p(msg->dc_1q3p);
			proto_msg->set_md64(msg->md64);
			proto_msg->set_md82(msg->md82);
			proto_msg->set_reducelosses(msg->reducelosses);
			proto_msg->set_hndwhl64(msg->hndwhl64);
			proto_msg->set_warn_ballast(msg->warn_ballast);
			proto_msg->set_hndwhl82(msg->hndwhl82);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 9: {
            primary_bms_hv_jmp_to_blt_t* msg = (primary_bms_hv_jmp_to_blt_t*)((*map)[index].message_raw);
            primary::BMS_HV_JMP_TO_BLT* proto_msg = pack->add_bms_hv_jmp_to_blt();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 41: {
            primary_bms_lv_jmp_to_blt_t* msg = (primary_bms_lv_jmp_to_blt_t*)((*map)[index].message_raw);
            primary::BMS_LV_JMP_TO_BLT* proto_msg = pack->add_bms_lv_jmp_to_blt();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1029: {
            primary_steer_version_t* msg = (primary_steer_version_t*)((*map)[index].message_raw);
            primary::STEER_VERSION* proto_msg = pack->add_steer_version();
			proto_msg->set_component_version(msg->component_version);
			proto_msg->set_canlib_build_time(msg->canlib_build_time);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1061: {
            primary_das_version_t* msg = (primary_das_version_t*)((*map)[index].message_raw);
            primary::DAS_VERSION* proto_msg = pack->add_das_version();
			proto_msg->set_component_version(msg->component_version);
			proto_msg->set_canlib_build_time(msg->canlib_build_time);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1093: {
            primary_hv_version_t* msg = (primary_hv_version_t*)((*map)[index].message_raw);
            primary::HV_VERSION* proto_msg = pack->add_hv_version();
			proto_msg->set_component_version(msg->component_version);
			proto_msg->set_canlib_build_time(msg->canlib_build_time);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1125: {
            primary_lv_version_t* msg = (primary_lv_version_t*)((*map)[index].message_raw);
            primary::LV_VERSION* proto_msg = pack->add_lv_version();
			proto_msg->set_component_version(msg->component_version);
			proto_msg->set_canlib_build_time(msg->canlib_build_time);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1157: {
            primary_tlm_version_t* msg = (primary_tlm_version_t*)((*map)[index].message_raw);
            primary::TLM_VERSION* proto_msg = pack->add_tlm_version();
			proto_msg->set_component_version(msg->component_version);
			proto_msg->set_canlib_build_time(msg->canlib_build_time);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 261: {
            primary_timestamp_t* msg = (primary_timestamp_t*)((*map)[index].message_raw);
            primary::TIMESTAMP* proto_msg = pack->add_timestamp();
			proto_msg->set_timestamp(msg->timestamp);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 293: {
            primary_ambient_temperature_t* msg = (primary_ambient_temperature_t*)((*map)[index].message_raw);
            primary::AMBIENT_TEMPERATURE* proto_msg = pack->add_ambient_temperature();
			proto_msg->set_temp(msg->temp);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1072: {
            primary_data_logger_t* msg = (primary_data_logger_t*)((*map)[index].message_raw);
            primary::DATA_LOGGER* proto_msg = pack->add_data_logger();
			proto_msg->set_placeholder1(msg->placeholder1);
			proto_msg->set_placeholder2(msg->placeholder2);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 257: {
            primary_set_tlm_status_t* msg = (primary_set_tlm_status_t*)((*map)[index].message_raw);
            primary::SET_TLM_STATUS* proto_msg = pack->add_set_tlm_status();
			proto_msg->set_tlm_status((primary::primary_set_tlm_status_tlm_status)msg->tlm_status);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 258: {
            primary_tlm_status_t* msg = (primary_tlm_status_t*)((*map)[index].message_raw);
            primary::TLM_STATUS* proto_msg = pack->add_tlm_status();
			proto_msg->set_tlm_status((primary::primary_tlm_status_tlm_status)msg->tlm_status);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1793: {
            primary_steer_system_status_t* msg = (primary_steer_system_status_t*)((*map)[index].message_raw);
            primary::STEER_SYSTEM_STATUS* proto_msg = pack->add_steer_system_status();
			proto_msg->set_soc_temp(msg->soc_temp);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 774: {
            primary_hv_voltage_converted_t* msg = (primary_hv_voltage_converted_t*)((*map)[index].message_conversion);
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

        case 806: {
            primary_hv_current_converted_t* msg = (primary_hv_current_converted_t*)((*map)[index].message_conversion);
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

        case 838: {
            primary_hv_temp_converted_t* msg = (primary_hv_temp_converted_t*)((*map)[index].message_conversion);
            primary::HV_TEMP* proto_msg = pack->add_hv_temp();
			proto_msg->set_average_temp(msg->average_temp);
			proto_msg->set_max_temp(msg->max_temp);
			proto_msg->set_min_temp(msg->min_temp);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 6: {
            primary_hv_errors_t* msg = (primary_hv_errors_t*)((*map)[index].message_raw);
            primary::HV_ERRORS* proto_msg = pack->add_hv_errors();
			proto_msg->set_warnings_cell_low_voltage(msg->warnings_cell_low_voltage);
			proto_msg->set_warnings_cell_under_voltage(msg->warnings_cell_under_voltage);
			proto_msg->set_warnings_cell_over_voltage(msg->warnings_cell_over_voltage);
			proto_msg->set_warnings_cell_high_temperature(msg->warnings_cell_high_temperature);
			proto_msg->set_warnings_cell_over_temperature(msg->warnings_cell_over_temperature);
			proto_msg->set_warnings_over_current(msg->warnings_over_current);
			proto_msg->set_warnings_can(msg->warnings_can);
			proto_msg->set_warnings_int_voltage_mismatch(msg->warnings_int_voltage_mismatch);
			proto_msg->set_warnings_cellboard_comm(msg->warnings_cellboard_comm);
			proto_msg->set_warnings_cellboard_internal(msg->warnings_cellboard_internal);
			proto_msg->set_warnings_feedback(msg->warnings_feedback);
			proto_msg->set_warnings_feedback_circuitry(msg->warnings_feedback_circuitry);
			proto_msg->set_warnings_eeprom_comm(msg->warnings_eeprom_comm);
			proto_msg->set_warnings_eeprom_write(msg->warnings_eeprom_write);
			proto_msg->set_errors_cell_low_voltage(msg->errors_cell_low_voltage);
			proto_msg->set_errors_cell_under_voltage(msg->errors_cell_under_voltage);
			proto_msg->set_errors_cell_over_voltage(msg->errors_cell_over_voltage);
			proto_msg->set_errors_cell_high_temperature(msg->errors_cell_high_temperature);
			proto_msg->set_errors_cell_over_temperature(msg->errors_cell_over_temperature);
			proto_msg->set_errors_over_current(msg->errors_over_current);
			proto_msg->set_errors_can(msg->errors_can);
			proto_msg->set_errors_int_voltage_mismatch(msg->errors_int_voltage_mismatch);
			proto_msg->set_errors_cellboard_comm(msg->errors_cellboard_comm);
			proto_msg->set_errors_cellboard_internal(msg->errors_cellboard_internal);
			proto_msg->set_errors_feedback(msg->errors_feedback);
			proto_msg->set_errors_feedback_circuitry(msg->errors_feedback_circuitry);
			proto_msg->set_errors_eeprom_comm(msg->errors_eeprom_comm);
			proto_msg->set_errors_eeprom_write(msg->errors_eeprom_write);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 10: {
            primary_hv_can_forward_t* msg = (primary_hv_can_forward_t*)((*map)[index].message_raw);
            primary::HV_CAN_FORWARD* proto_msg = pack->add_hv_can_forward();
			proto_msg->set_can_forward_set((primary::primary_hv_can_forward_can_forward_set)msg->can_forward_set);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 42: {
            primary_hv_fans_override_converted_t* msg = (primary_hv_fans_override_converted_t*)((*map)[index].message_conversion);
            primary::HV_FANS_OVERRIDE* proto_msg = pack->add_hv_fans_override();
			proto_msg->set_fans_override((primary::primary_hv_fans_override_fans_override)msg->fans_override);
			proto_msg->set_fans_speed(msg->fans_speed);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 8: {
            primary_hv_can_forward_status_t* msg = (primary_hv_can_forward_status_t*)((*map)[index].message_raw);
            primary::HV_CAN_FORWARD_STATUS* proto_msg = pack->add_hv_can_forward_status();
			proto_msg->set_can_forward_status((primary::primary_hv_can_forward_status_can_forward_status)msg->can_forward_status);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 776: {
            primary_hv_fans_override_status_converted_t* msg = (primary_hv_fans_override_status_converted_t*)((*map)[index].message_conversion);
            primary::HV_FANS_OVERRIDE_STATUS* proto_msg = pack->add_hv_fans_override_status();
			proto_msg->set_fans_override((primary::primary_hv_fans_override_status_fans_override)msg->fans_override);
			proto_msg->set_fans_speed(msg->fans_speed);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 768: {
            primary_hv_feedbacks_status_t* msg = (primary_hv_feedbacks_status_t*)((*map)[index].message_raw);
            primary::HV_FEEDBACKS_STATUS* proto_msg = pack->add_hv_feedbacks_status();
			proto_msg->set_feedbacks_status_feedback_tsal_green_fault(msg->feedbacks_status_feedback_tsal_green_fault);
			proto_msg->set_feedbacks_status_feedback_imd_latched(msg->feedbacks_status_feedback_imd_latched);
			proto_msg->set_feedbacks_status_feedback_tsal_green_fault_latched(msg->feedbacks_status_feedback_tsal_green_fault_latched);
			proto_msg->set_feedbacks_status_feedback_bms_latched(msg->feedbacks_status_feedback_bms_latched);
			proto_msg->set_feedbacks_status_feedback_ext_latched(msg->feedbacks_status_feedback_ext_latched);
			proto_msg->set_feedbacks_status_feedback_tsal_green(msg->feedbacks_status_feedback_tsal_green);
			proto_msg->set_feedbacks_status_feedback_ts_over_60v_status(msg->feedbacks_status_feedback_ts_over_60v_status);
			proto_msg->set_feedbacks_status_feedback_airn_status(msg->feedbacks_status_feedback_airn_status);
			proto_msg->set_feedbacks_status_feedback_airp_status(msg->feedbacks_status_feedback_airp_status);
			proto_msg->set_feedbacks_status_feedback_airp_gate(msg->feedbacks_status_feedback_airp_gate);
			proto_msg->set_feedbacks_status_feedback_airn_gate(msg->feedbacks_status_feedback_airn_gate);
			proto_msg->set_feedbacks_status_feedback_precharge_status(msg->feedbacks_status_feedback_precharge_status);
			proto_msg->set_feedbacks_status_feedback_tsp_over_60v_status(msg->feedbacks_status_feedback_tsp_over_60v_status);
			proto_msg->set_feedbacks_status_feedback_check_mux(msg->feedbacks_status_feedback_check_mux);
			proto_msg->set_feedbacks_status_feedback_sd_in(msg->feedbacks_status_feedback_sd_in);
			proto_msg->set_feedbacks_status_feedback_sd_out(msg->feedbacks_status_feedback_sd_out);
			proto_msg->set_feedbacks_status_feedback_relay_sd(msg->feedbacks_status_feedback_relay_sd);
			proto_msg->set_feedbacks_status_feedback_imd_fault(msg->feedbacks_status_feedback_imd_fault);
			proto_msg->set_feedbacks_status_feedback_sd_end(msg->feedbacks_status_feedback_sd_end);
			proto_msg->set_is_circuitry_error_feedback_tsal_green_fault(msg->is_circuitry_error_feedback_tsal_green_fault);
			proto_msg->set_is_circuitry_error_feedback_imd_latched(msg->is_circuitry_error_feedback_imd_latched);
			proto_msg->set_is_circuitry_error_feedback_tsal_green_fault_latched(msg->is_circuitry_error_feedback_tsal_green_fault_latched);
			proto_msg->set_is_circuitry_error_feedback_bms_latched(msg->is_circuitry_error_feedback_bms_latched);
			proto_msg->set_is_circuitry_error_feedback_ext_latched(msg->is_circuitry_error_feedback_ext_latched);
			proto_msg->set_is_circuitry_error_feedback_tsal_green(msg->is_circuitry_error_feedback_tsal_green);
			proto_msg->set_is_circuitry_error_feedback_ts_over_60v_status(msg->is_circuitry_error_feedback_ts_over_60v_status);
			proto_msg->set_is_circuitry_error_feedback_airn_status(msg->is_circuitry_error_feedback_airn_status);
			proto_msg->set_is_circuitry_error_feedback_airp_status(msg->is_circuitry_error_feedback_airp_status);
			proto_msg->set_is_circuitry_error_feedback_airp_gate(msg->is_circuitry_error_feedback_airp_gate);
			proto_msg->set_is_circuitry_error_feedback_airn_gate(msg->is_circuitry_error_feedback_airn_gate);
			proto_msg->set_is_circuitry_error_feedback_precharge_status(msg->is_circuitry_error_feedback_precharge_status);
			proto_msg->set_is_circuitry_error_feedback_tsp_over_60v_status(msg->is_circuitry_error_feedback_tsp_over_60v_status);
			proto_msg->set_is_circuitry_error_feedback_check_mux(msg->is_circuitry_error_feedback_check_mux);
			proto_msg->set_is_circuitry_error_feedback_sd_in(msg->is_circuitry_error_feedback_sd_in);
			proto_msg->set_is_circuitry_error_feedback_sd_out(msg->is_circuitry_error_feedback_sd_out);
			proto_msg->set_is_circuitry_error_feedback_relay_sd(msg->is_circuitry_error_feedback_relay_sd);
			proto_msg->set_is_circuitry_error_feedback_imd_fault(msg->is_circuitry_error_feedback_imd_fault);
			proto_msg->set_is_circuitry_error_feedback_sd_end(msg->is_circuitry_error_feedback_sd_end);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 800: {
            primary_hv_imd_status_t* msg = (primary_hv_imd_status_t*)((*map)[index].message_raw);
            primary::HV_IMD_STATUS* proto_msg = pack->add_hv_imd_status();
			proto_msg->set_imd_fault(msg->imd_fault);
			proto_msg->set_imd_status((primary::primary_hv_imd_status_imd_status)msg->imd_status);
			proto_msg->set_imd_info(msg->imd_info);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 38: {
            primary_ts_status_das_t* msg = (primary_ts_status_das_t*)((*map)[index].message_raw);
            primary::TS_STATUS_DAS* proto_msg = pack->add_ts_status_das();
			proto_msg->set_ts_status((primary::primary_ts_status_das_ts_status)msg->ts_status);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 70: {
            primary_ts_status_steer_t* msg = (primary_ts_status_steer_t*)((*map)[index].message_raw);
            primary::TS_STATUS_STEER* proto_msg = pack->add_ts_status_steer();
			proto_msg->set_ts_status((primary::primary_ts_status_steer_ts_status)msg->ts_status);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 102: {
            primary_ts_status_handcart_t* msg = (primary_ts_status_handcart_t*)((*map)[index].message_raw);
            primary::TS_STATUS_HANDCART* proto_msg = pack->add_ts_status_handcart();
			proto_msg->set_ts_status((primary::primary_ts_status_handcart_ts_status)msg->ts_status);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 74: {
            primary_set_ts_status_das_t* msg = (primary_set_ts_status_das_t*)((*map)[index].message_raw);
            primary::SET_TS_STATUS_DAS* proto_msg = pack->add_set_ts_status_das();
			proto_msg->set_ts_status_set((primary::primary_set_ts_status_das_ts_status_set)msg->ts_status_set);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 106: {
            primary_set_ts_status_handcart_t* msg = (primary_set_ts_status_handcart_t*)((*map)[index].message_raw);
            primary::SET_TS_STATUS_HANDCART* proto_msg = pack->add_set_ts_status_handcart();
			proto_msg->set_ts_status_set((primary::primary_set_ts_status_handcart_ts_status_set)msg->ts_status_set);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 259: {
            primary_steer_status_converted_t* msg = (primary_steer_status_converted_t*)((*map)[index].message_conversion);
            primary::STEER_STATUS* proto_msg = pack->add_steer_status();
			proto_msg->set_map_pw(msg->map_pw);
			proto_msg->set_map_sc(msg->map_sc);
			proto_msg->set_map_tv(msg->map_tv);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 771: {
            primary_set_car_status_t* msg = (primary_set_car_status_t*)((*map)[index].message_raw);
            primary::SET_CAR_STATUS* proto_msg = pack->add_set_car_status();
			proto_msg->set_car_status_set((primary::primary_set_car_status_car_status_set)msg->car_status_set);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1027: {
            primary_set_pedals_range_t* msg = (primary_set_pedals_range_t*)((*map)[index].message_raw);
            primary::SET_PEDALS_RANGE* proto_msg = pack->add_set_pedals_range();
			proto_msg->set_bound((primary::primary_set_pedals_range_bound)msg->bound);
			proto_msg->set_pedal((primary::primary_set_pedals_range_pedal)msg->pedal);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1059: {
            primary_set_steering_angle_range_t* msg = (primary_set_steering_angle_range_t*)((*map)[index].message_raw);
            primary::SET_STEERING_ANGLE_RANGE* proto_msg = pack->add_set_steering_angle_range();
			proto_msg->set_bound((primary::primary_set_steering_angle_range_bound)msg->bound);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 546: {
            primary_car_status_t* msg = (primary_car_status_t*)((*map)[index].message_raw);
            primary::CAR_STATUS* proto_msg = pack->add_car_status();
			proto_msg->set_inverter_l((primary::primary_car_status_inverter_l)msg->inverter_l);
			proto_msg->set_inverter_r((primary::primary_car_status_inverter_r)msg->inverter_r);
			proto_msg->set_car_status((primary::primary_car_status_car_status)msg->car_status);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 2: {
            primary_das_errors_t* msg = (primary_das_errors_t*)((*map)[index].message_raw);
            primary::DAS_ERRORS* proto_msg = pack->add_das_errors();
			proto_msg->set_das_error_pedal_adc(msg->das_error_pedal_adc);
			proto_msg->set_das_error_pedal_implausibility(msg->das_error_pedal_implausibility);
			proto_msg->set_das_error_imu_tout(msg->das_error_imu_tout);
			proto_msg->set_das_error_irts_tout(msg->das_error_irts_tout);
			proto_msg->set_das_error_ts_tout(msg->das_error_ts_tout);
			proto_msg->set_das_error_invl_tout(msg->das_error_invl_tout);
			proto_msg->set_das_error_invr_tout(msg->das_error_invr_tout);
			proto_msg->set_das_error_steer_tout(msg->das_error_steer_tout);
			proto_msg->set_das_error_fsm(msg->das_error_fsm);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 832: {
            primary_lv_current_converted_t* msg = (primary_lv_current_converted_t*)((*map)[index].message_conversion);
            primary::LV_CURRENT* proto_msg = pack->add_lv_current();
			proto_msg->set_current(msg->current);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 864: {
            primary_lv_voltage_converted_t* msg = (primary_lv_voltage_converted_t*)((*map)[index].message_conversion);
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

        case 896: {
            primary_lv_total_voltage_converted_t* msg = (primary_lv_total_voltage_converted_t*)((*map)[index].message_conversion);
            primary::LV_TOTAL_VOLTAGE* proto_msg = pack->add_lv_total_voltage();
			proto_msg->set_total_voltage(msg->total_voltage);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 928: {
            primary_lv_temperature_converted_t* msg = (primary_lv_temperature_converted_t*)((*map)[index].message_conversion);
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

        case 960: {
            primary_cooling_status_converted_t* msg = (primary_cooling_status_converted_t*)((*map)[index].message_conversion);
            primary::COOLING_STATUS* proto_msg = pack->add_cooling_status();
			proto_msg->set_radiators_speed(msg->radiators_speed);
			proto_msg->set_pumps_speed(msg->pumps_speed);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 772: {
            primary_set_radiator_speed_converted_t* msg = (primary_set_radiator_speed_converted_t*)((*map)[index].message_conversion);
            primary::SET_RADIATOR_SPEED* proto_msg = pack->add_set_radiator_speed();
			proto_msg->set_radiators_speed(msg->radiators_speed);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 804: {
            primary_set_pumps_speed_converted_t* msg = (primary_set_pumps_speed_converted_t*)((*map)[index].message_conversion);
            primary::SET_PUMPS_SPEED* proto_msg = pack->add_set_pumps_speed();
			proto_msg->set_pumps_speed(msg->pumps_speed);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 260: {
            primary_set_inverter_connection_status_t* msg = (primary_set_inverter_connection_status_t*)((*map)[index].message_raw);
            primary::SET_INVERTER_CONNECTION_STATUS* proto_msg = pack->add_set_inverter_connection_status();
			proto_msg->set_status((primary::primary_set_inverter_connection_status_status)msg->status);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 256: {
            primary_inverter_connection_status_t* msg = (primary_inverter_connection_status_t*)((*map)[index].message_raw);
            primary::INVERTER_CONNECTION_STATUS* proto_msg = pack->add_inverter_connection_status();
			proto_msg->set_status((primary::primary_inverter_connection_status_status)msg->status);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 0: {
            primary_lv_errors_t* msg = (primary_lv_errors_t*)((*map)[index].message_raw);
            primary::LV_ERRORS* proto_msg = pack->add_lv_errors();
			proto_msg->set_warnings_cell_undervoltage(msg->warnings_cell_undervoltage);
			proto_msg->set_warnings_cell_overvoltage(msg->warnings_cell_overvoltage);
			proto_msg->set_warnings_open_wire(msg->warnings_open_wire);
			proto_msg->set_warnings_can(msg->warnings_can);
			proto_msg->set_warnings_spi(msg->warnings_spi);
			proto_msg->set_warnings_over_current(msg->warnings_over_current);
			proto_msg->set_warnings_dcdc12_under_temperature(msg->warnings_dcdc12_under_temperature);
			proto_msg->set_warnings_dcdc12_over_temperature(msg->warnings_dcdc12_over_temperature);
			proto_msg->set_warnings_dcdc24_under_temperature(msg->warnings_dcdc24_under_temperature);
			proto_msg->set_warnings_dcdc24_over_temperature(msg->warnings_dcdc24_over_temperature);
			proto_msg->set_warnings_cell_under_temperature(msg->warnings_cell_under_temperature);
			proto_msg->set_warnings_cell_over_temperature(msg->warnings_cell_over_temperature);
			proto_msg->set_warnings_relay(msg->warnings_relay);
			proto_msg->set_warnings_ltc6810(msg->warnings_ltc6810);
			proto_msg->set_warnings_voltages_not_ready(msg->warnings_voltages_not_ready);
			proto_msg->set_warnings_mcp23017(msg->warnings_mcp23017);
			proto_msg->set_warnings_radiator(msg->warnings_radiator);
			proto_msg->set_warnings_fan(msg->warnings_fan);
			proto_msg->set_warnings_pump(msg->warnings_pump);
			proto_msg->set_warnings_adc_init(msg->warnings_adc_init);
			proto_msg->set_warnings_dcdc12(msg->warnings_dcdc12);
			proto_msg->set_warnings_dcdc24(msg->warnings_dcdc24);
			proto_msg->set_errors_cell_undervoltage(msg->errors_cell_undervoltage);
			proto_msg->set_errors_cell_overvoltage(msg->errors_cell_overvoltage);
			proto_msg->set_errors_open_wire(msg->errors_open_wire);
			proto_msg->set_errors_can(msg->errors_can);
			proto_msg->set_errors_spi(msg->errors_spi);
			proto_msg->set_errors_over_current(msg->errors_over_current);
			proto_msg->set_errors_dcdc12_under_temperature(msg->errors_dcdc12_under_temperature);
			proto_msg->set_errors_dcdc12_over_temperature(msg->errors_dcdc12_over_temperature);
			proto_msg->set_errors_dcdc24_under_temperature(msg->errors_dcdc24_under_temperature);
			proto_msg->set_errors_dcdc24_over_temperature(msg->errors_dcdc24_over_temperature);
			proto_msg->set_errors_cell_under_temperature(msg->errors_cell_under_temperature);
			proto_msg->set_errors_cell_over_temperature(msg->errors_cell_over_temperature);
			proto_msg->set_errors_relay(msg->errors_relay);
			proto_msg->set_errors_ltc6810(msg->errors_ltc6810);
			proto_msg->set_errors_voltages_not_ready(msg->errors_voltages_not_ready);
			proto_msg->set_errors_mcp23017(msg->errors_mcp23017);
			proto_msg->set_errors_radiator(msg->errors_radiator);
			proto_msg->set_errors_fan(msg->errors_fan);
			proto_msg->set_errors_pump(msg->errors_pump);
			proto_msg->set_errors_adc_init(msg->errors_adc_init);
			proto_msg->set_errors_dcdc12(msg->errors_dcdc12);
			proto_msg->set_errors_dcdc24(msg->errors_dcdc24);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 288: {
            primary_shutdown_status_t* msg = (primary_shutdown_status_t*)((*map)[index].message_raw);
            primary::SHUTDOWN_STATUS* proto_msg = pack->add_shutdown_status();
			proto_msg->set_input(msg->input);
			proto_msg->set_output(msg->output);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1: {
            primary_marker_t* msg = (primary_marker_t*)((*map)[index].message_raw);
            primary::MARKER* proto_msg = pack->add_marker();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 520: {
            primary_hv_cells_voltage_converted_t* msg = (primary_hv_cells_voltage_converted_t*)((*map)[index].message_conversion);
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

        case 552: {
            primary_hv_cells_temp_converted_t* msg = (primary_hv_cells_temp_converted_t*)((*map)[index].message_conversion);
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

        case 584: {
            primary_hv_cell_balancing_status_t* msg = (primary_hv_cell_balancing_status_t*)((*map)[index].message_raw);
            primary::HV_CELL_BALANCING_STATUS* proto_msg = pack->add_hv_cell_balancing_status();
			proto_msg->set_balancing_status((primary::primary_hv_cell_balancing_status_balancing_status)msg->balancing_status);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 522: {
            primary_set_cell_balancing_status_t* msg = (primary_set_cell_balancing_status_t*)((*map)[index].message_raw);
            primary::SET_CELL_BALANCING_STATUS* proto_msg = pack->add_set_cell_balancing_status();
			proto_msg->set_set_balancing_status((primary::primary_set_cell_balancing_status_set_balancing_status)msg->set_balancing_status);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 778: {
            primary_handcart_status_t* msg = (primary_handcart_status_t*)((*map)[index].message_raw);
            primary::HANDCART_STATUS* proto_msg = pack->add_handcart_status();
			proto_msg->set_connected(msg->connected);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 578: {
            primary_speed_converted_t* msg = (primary_speed_converted_t*)((*map)[index].message_conversion);
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
            primary_inv_l_request_t* msg = (primary_inv_l_request_t*)((*map)[index].message_raw);
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
            primary_inv_r_request_t* msg = (primary_inv_r_request_t*)((*map)[index].message_raw);
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
            primary_inv_l_response_t* msg = (primary_inv_l_response_t*)((*map)[index].message_raw);
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
            primary_inv_r_response_t* msg = (primary_inv_r_response_t*)((*map)[index].message_raw);
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
            primary_flash_cellboard_0_tx_t* msg = (primary_flash_cellboard_0_tx_t*)((*map)[index].message_raw);
            primary::FLASH_CELLBOARD_0_TX* proto_msg = pack->add_flash_cellboard_0_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 17: {
            primary_flash_cellboard_0_rx_t* msg = (primary_flash_cellboard_0_rx_t*)((*map)[index].message_raw);
            primary::FLASH_CELLBOARD_0_RX* proto_msg = pack->add_flash_cellboard_0_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 18: {
            primary_flash_cellboard_1_tx_t* msg = (primary_flash_cellboard_1_tx_t*)((*map)[index].message_raw);
            primary::FLASH_CELLBOARD_1_TX* proto_msg = pack->add_flash_cellboard_1_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 19: {
            primary_flash_cellboard_1_rx_t* msg = (primary_flash_cellboard_1_rx_t*)((*map)[index].message_raw);
            primary::FLASH_CELLBOARD_1_RX* proto_msg = pack->add_flash_cellboard_1_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 20: {
            primary_flash_cellboard_2_tx_t* msg = (primary_flash_cellboard_2_tx_t*)((*map)[index].message_raw);
            primary::FLASH_CELLBOARD_2_TX* proto_msg = pack->add_flash_cellboard_2_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 21: {
            primary_flash_cellboard_2_rx_t* msg = (primary_flash_cellboard_2_rx_t*)((*map)[index].message_raw);
            primary::FLASH_CELLBOARD_2_RX* proto_msg = pack->add_flash_cellboard_2_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 22: {
            primary_flash_cellboard_3_tx_t* msg = (primary_flash_cellboard_3_tx_t*)((*map)[index].message_raw);
            primary::FLASH_CELLBOARD_3_TX* proto_msg = pack->add_flash_cellboard_3_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 23: {
            primary_flash_cellboard_3_rx_t* msg = (primary_flash_cellboard_3_rx_t*)((*map)[index].message_raw);
            primary::FLASH_CELLBOARD_3_RX* proto_msg = pack->add_flash_cellboard_3_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 24: {
            primary_flash_cellboard_4_tx_t* msg = (primary_flash_cellboard_4_tx_t*)((*map)[index].message_raw);
            primary::FLASH_CELLBOARD_4_TX* proto_msg = pack->add_flash_cellboard_4_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 25: {
            primary_flash_cellboard_4_rx_t* msg = (primary_flash_cellboard_4_rx_t*)((*map)[index].message_raw);
            primary::FLASH_CELLBOARD_4_RX* proto_msg = pack->add_flash_cellboard_4_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 26: {
            primary_flash_cellboard_5_tx_t* msg = (primary_flash_cellboard_5_tx_t*)((*map)[index].message_raw);
            primary::FLASH_CELLBOARD_5_TX* proto_msg = pack->add_flash_cellboard_5_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 27: {
            primary_flash_cellboard_5_rx_t* msg = (primary_flash_cellboard_5_rx_t*)((*map)[index].message_raw);
            primary::FLASH_CELLBOARD_5_RX* proto_msg = pack->add_flash_cellboard_5_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 2017: {
            primary_flash_bms_hv_tx_t* msg = (primary_flash_bms_hv_tx_t*)((*map)[index].message_raw);
            primary::FLASH_BMS_HV_TX* proto_msg = pack->add_flash_bms_hv_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1639: {
            primary_flash_bms_hv_rx_t* msg = (primary_flash_bms_hv_rx_t*)((*map)[index].message_raw);
            primary::FLASH_BMS_HV_RX* proto_msg = pack->add_flash_bms_hv_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 2033: {
            primary_flash_bms_lv_tx_t* msg = (primary_flash_bms_lv_tx_t*)((*map)[index].message_raw);
            primary::FLASH_BMS_LV_TX* proto_msg = pack->add_flash_bms_lv_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1655: {
            primary_flash_bms_lv_rx_t* msg = (primary_flash_bms_lv_rx_t*)((*map)[index].message_raw);
            primary::FLASH_BMS_LV_RX* proto_msg = pack->add_flash_bms_lv_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 618: {
            primary_brusa_nlg5_ctl_t* msg = (primary_brusa_nlg5_ctl_t*)((*map)[index].message_raw);
            primary::BRUSA_NLG5_CTL* proto_msg = pack->add_brusa_nlg5_ctl();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 610: {
            primary_brusa_st_t* msg = (primary_brusa_st_t*)((*map)[index].message_raw);
            primary::BRUSA_ST* proto_msg = pack->add_brusa_st();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 611: {
            primary_brusa_act_i_t* msg = (primary_brusa_act_i_t*)((*map)[index].message_raw);
            primary::BRUSA_ACT_I* proto_msg = pack->add_brusa_act_i();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 612: {
            primary_brusa_act_ii_t* msg = (primary_brusa_act_ii_t*)((*map)[index].message_raw);
            primary::BRUSA_ACT_II* proto_msg = pack->add_brusa_act_ii();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 613: {
            primary_brusa_temp_t* msg = (primary_brusa_temp_t*)((*map)[index].message_raw);
            primary::BRUSA_TEMP* proto_msg = pack->add_brusa_temp();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 614: {
            primary_brusa_err_t* msg = (primary_brusa_err_t*)((*map)[index].message_raw);
            primary::BRUSA_ERR* proto_msg = pack->add_brusa_err();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 290: {
            primary_control_output_converted_t* msg = (primary_control_output_converted_t*)((*map)[index].message_conversion);
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

        case 519: {
            primary_lc_reset_t* msg = (primary_lc_reset_t*)((*map)[index].message_raw);
            primary::LC_RESET* proto_msg = pack->add_lc_reset();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

    }
}



#endif // primary_PROTO_INTERAFCE_IMPLEMENTATION

#endif // primary_PROTO_INTERFACE_H
