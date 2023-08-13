
#ifndef inverters_PROTO_INTERFACE_H
#define inverters_PROTO_INTERFACE_H

#include <string>
#include <unordered_map>
#include <functional>

#include "inverters.pb.h"

#ifdef inverters_IMPLEMENTATION
#undef inverters_IMPLEMENTATION
#define __inverters_IMPLEMENTATION
#endif

#include "../../lib/inverters/inverters_network.h"

#ifdef __inverters_IMPLEMENTATION
#undef __inverters_IMPLEMENTATION
#define inverters_IMPLEMENTATION
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

void inverters_proto_interface_serialize_from_id(canlib_message_id id, inverters::Pack* pack, device_t* device);
void inverters_proto_interface_deserialize(inverters::Pack* pack, network_enums* net_enums, network_signals* net_signals, network_strings* net_strings, uint64_t resample_us);

#ifdef inverters_PROTO_INTERAFCE_IMPLEMENTATION

void inverters_proto_interface_deserialize(inverters::Pack* pack, network_enums* net_enums, network_signals* net_signals, network_strings* net_strings, uint64_t resample_us) {
    char buffer[1024];
    
    for(int i = 0; i < pack->inv_l_send_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->inv_l_send(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->inv_l_send(i)._inner_timestamp();
        (*net_signals)["INV_L_SEND"]["_timestamp"].push(pack->inv_l_send(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["INV_L_SEND"]["send_mux"].push(pack->inv_l_send(i).send_mux());
		inverters_inv_l_send_send_mux_enum_to_string((inverters_inv_l_send_send_mux)pack->inv_l_send(i).send_mux(), buffer);
		(*net_strings)["INV_L_SEND"]["send_mux"].push(buffer);
		(*net_enums)["INV_L_SEND"]["read_id"].push(pack->inv_l_send(i).read_id());
		inverters_inv_l_send_read_id_enum_to_string((inverters_inv_l_send_read_id)pack->inv_l_send(i).read_id(), buffer);
		(*net_strings)["INV_L_SEND"]["read_id"].push(buffer);
		(*net_enums)["INV_L_SEND"]["km_rsvd_0"].push(pack->inv_l_send(i).km_rsvd_0());
		(*net_signals)["INV_L_SEND"]["m_setdig__iq"].push(pack->inv_l_send(i).m_setdig__iq());
		(*net_enums)["INV_L_SEND"]["def_din_1"].push(pack->inv_l_send(i).def_din_1());
		inverters_inv_l_send_def_din_1_enum_to_string((inverters_inv_l_send_def_din_1)pack->inv_l_send(i).def_din_1(), buffer);
		(*net_strings)["INV_L_SEND"]["def_din_1"].push(buffer);
		(*net_enums)["INV_L_SEND"]["def_end_1"].push(pack->inv_l_send(i).def_end_1());
		inverters_inv_l_send_def_end_1_enum_to_string((inverters_inv_l_send_def_end_1)pack->inv_l_send(i).def_end_1(), buffer);
		(*net_strings)["INV_L_SEND"]["def_end_1"].push(buffer);
		(*net_enums)["INV_L_SEND"]["km_speed_0"].push(pack->inv_l_send(i).km_speed_0());
		(*net_enums)["INV_L_SEND"]["km_frg_off"].push(pack->inv_l_send(i).km_frg_off());
		(*net_enums)["INV_L_SEND"]["km_cal_off"].push(pack->inv_l_send(i).km_cal_off());
		(*net_enums)["INV_L_SEND"]["km_tx_tog_stat"].push(pack->inv_l_send(i).km_tx_tog_stat());
		(*net_enums)["INV_L_SEND"]["km_i_limit"].push(pack->inv_l_send(i).km_i_limit());
		(*net_enums)["INV_L_SEND"]["km_n_clip"].push(pack->inv_l_send(i).km_n_clip());
		(*net_enums)["INV_L_SEND"]["km_mix_ana_on"].push(pack->inv_l_send(i).km_mix_ana_on());
		(*net_enums)["INV_L_SEND"]["ret_interval"].push(pack->inv_l_send(i).ret_interval());
		inverters_inv_l_send_ret_interval_enum_to_string((inverters_inv_l_send_ret_interval)pack->inv_l_send(i).ret_interval(), buffer);
		(*net_strings)["INV_L_SEND"]["ret_interval"].push(buffer);
		(*net_enums)["INV_L_SEND"]["km_allow_sync"].push(pack->inv_l_send(i).km_allow_sync());
		(*net_enums)["INV_L_SEND"]["km_handwheel"].push(pack->inv_l_send(i).km_handwheel());
		(*net_enums)["INV_L_SEND"]["km_phasing_extend"].push(pack->inv_l_send(i).km_phasing_extend());
		(*net_enums)["INV_L_SEND"]["km_rsvd_11"].push(pack->inv_l_send(i).km_rsvd_11());
		(*net_enums)["INV_L_SEND"]["km_rsvd_12"].push(pack->inv_l_send(i).km_rsvd_12());
		(*net_enums)["INV_L_SEND"]["km_rsvd_13"].push(pack->inv_l_send(i).km_rsvd_13());
		(*net_enums)["INV_L_SEND"]["km_pseudo_enable"].push(pack->inv_l_send(i).km_pseudo_enable());
		(*net_enums)["INV_L_SEND"]["km_debug_test"].push(pack->inv_l_send(i).km_debug_test());
		(*net_enums)["INV_L_SEND"]["active192"].push(pack->inv_l_send(i).active192());
		inverters_inv_l_send_active192_enum_to_string((inverters_inv_l_send_active192)pack->inv_l_send(i).active192(), buffer);
		(*net_strings)["INV_L_SEND"]["active192"].push(buffer);
		(*net_enums)["INV_L_SEND"]["active190"].push(pack->inv_l_send(i).active190());
		inverters_inv_l_send_active190_enum_to_string((inverters_inv_l_send_active190)pack->inv_l_send(i).active190(), buffer);
		(*net_strings)["INV_L_SEND"]["active190"].push(buffer);

    }

    for(int i = 0; i < pack->inv_l_rcv_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->inv_l_rcv(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->inv_l_rcv(i)._inner_timestamp();
        (*net_signals)["INV_L_RCV"]["_timestamp"].push(pack->inv_l_rcv(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["INV_L_RCV"]["rcv_mux"].push(pack->inv_l_rcv(i).rcv_mux());
		inverters_inv_l_rcv_rcv_mux_enum_to_string((inverters_inv_l_rcv_rcv_mux)pack->inv_l_rcv(i).rcv_mux(), buffer);
		(*net_strings)["INV_L_RCV"]["rcv_mux"].push(buffer);
		(*net_signals)["INV_L_RCV"]["n_actual_filt"].push(pack->inv_l_rcv(i).n_actual_filt());
		(*net_enums)["INV_L_RCV"]["ena64"].push(pack->inv_l_rcv(i).ena64());
		(*net_enums)["INV_L_RCV"]["err_badparas"].push(pack->inv_l_rcv(i).err_badparas());
		(*net_enums)["INV_L_RCV"]["def_end_1"].push(pack->inv_l_rcv(i).def_end_1());
		inverters_inv_l_rcv_def_end_1_enum_to_string((inverters_inv_l_rcv_def_end_1)pack->inv_l_rcv(i).def_end_1(), buffer);
		(*net_strings)["INV_L_RCV"]["def_end_1"].push(buffer);
		(*net_enums)["INV_L_RCV"]["lmt_active_1"].push(pack->inv_l_rcv(i).lmt_active_1());
		(*net_signals)["INV_L_RCV"]["i_cmd"].push(pack->inv_l_rcv(i).i_cmd());
		(*net_signals)["INV_L_RCV"]["i_cmd_ramp"].push(pack->inv_l_rcv(i).i_cmd_ramp());
		(*net_signals)["INV_L_RCV"]["iq_actual"].push(pack->inv_l_rcv(i).iq_actual());
		(*net_signals)["INV_L_RCV"]["t_motor"].push(pack->inv_l_rcv(i).t_motor());
		(*net_signals)["INV_L_RCV"]["t_igbt"].push(pack->inv_l_rcv(i).t_igbt());
		(*net_signals)["INV_L_RCV"]["vdc_bus_filt"].push(pack->inv_l_rcv(i).vdc_bus_filt());
		(*net_enums)["INV_L_RCV"]["km_rsvd_0"].push(pack->inv_l_rcv(i).km_rsvd_0());
		(*net_enums)["INV_L_RCV"]["ena82"].push(pack->inv_l_rcv(i).ena82());
		(*net_enums)["INV_L_RCV"]["def_din_1"].push(pack->inv_l_rcv(i).def_din_1());
		inverters_inv_l_rcv_def_din_1_enum_to_string((inverters_inv_l_rcv_def_din_1)pack->inv_l_rcv(i).def_din_1(), buffer);
		(*net_strings)["INV_L_RCV"]["def_din_1"].push(buffer);
		(*net_signals)["INV_L_RCV"]["m_cmd_ramp"].push(pack->inv_l_rcv(i).m_cmd_ramp());
		(*net_enums)["INV_L_RCV"]["ncr064"].push(pack->inv_l_rcv(i).ncr064());
		(*net_enums)["INV_L_RCV"]["err_powerfault"].push(pack->inv_l_rcv(i).err_powerfault());
		(*net_enums)["INV_L_RCV"]["lmt_active_2"].push(pack->inv_l_rcv(i).lmt_active_2());
		(*net_enums)["INV_L_RCV"]["km_speed_0"].push(pack->inv_l_rcv(i).km_speed_0());
		(*net_enums)["INV_L_RCV"]["ncr082"].push(pack->inv_l_rcv(i).ncr082());
		(*net_enums)["INV_L_RCV"]["lim_plus64"].push(pack->inv_l_rcv(i).lim_plus64());
		(*net_enums)["INV_L_RCV"]["err_rfe_fault"].push(pack->inv_l_rcv(i).err_rfe_fault());
		(*net_enums)["INV_L_RCV"]["in_active_2"].push(pack->inv_l_rcv(i).in_active_2());
		(*net_enums)["INV_L_RCV"]["km_frg_off"].push(pack->inv_l_rcv(i).km_frg_off());
		(*net_enums)["INV_L_RCV"]["lim_plus82"].push(pack->inv_l_rcv(i).lim_plus82());
		(*net_enums)["INV_L_RCV"]["lim_minus64"].push(pack->inv_l_rcv(i).lim_minus64());
		(*net_enums)["INV_L_RCV"]["err_bustimeout"].push(pack->inv_l_rcv(i).err_bustimeout());
		(*net_enums)["INV_L_RCV"]["in_active_1"].push(pack->inv_l_rcv(i).in_active_1());
		(*net_enums)["INV_L_RCV"]["km_cal_off"].push(pack->inv_l_rcv(i).km_cal_off());
		(*net_enums)["INV_L_RCV"]["lim_minus82"].push(pack->inv_l_rcv(i).lim_minus82());
		(*net_enums)["INV_L_RCV"]["ok64"].push(pack->inv_l_rcv(i).ok64());
		(*net_enums)["INV_L_RCV"]["err_feedbacksignal"].push(pack->inv_l_rcv(i).err_feedbacksignal());
		(*net_enums)["INV_L_RCV"]["frgrun"].push(pack->inv_l_rcv(i).frgrun());
		(*net_enums)["INV_L_RCV"]["km_tx_tog_stat"].push(pack->inv_l_rcv(i).km_tx_tog_stat());
		(*net_enums)["INV_L_RCV"]["ok82"].push(pack->inv_l_rcv(i).ok82());
		(*net_enums)["INV_L_RCV"]["icns64"].push(pack->inv_l_rcv(i).icns64());
		(*net_enums)["INV_L_RCV"]["err_powervoltage_low"].push(pack->inv_l_rcv(i).err_powervoltage_low());
		(*net_enums)["INV_L_RCV"]["rfe216"].push(pack->inv_l_rcv(i).rfe216());
		(*net_enums)["INV_L_RCV"]["km_i_limit"].push(pack->inv_l_rcv(i).km_i_limit());
		(*net_enums)["INV_L_RCV"]["icns82"].push(pack->inv_l_rcv(i).icns82());
		(*net_enums)["INV_L_RCV"]["tnlim64"].push(pack->inv_l_rcv(i).tnlim64());
		(*net_enums)["INV_L_RCV"]["err_motortemp"].push(pack->inv_l_rcv(i).err_motortemp());
		(*net_enums)["INV_L_RCV"]["km_n_clip"].push(pack->inv_l_rcv(i).km_n_clip());
		(*net_enums)["INV_L_RCV"]["tnlim82"].push(pack->inv_l_rcv(i).tnlim82());
		(*net_enums)["INV_L_RCV"]["pn64"].push(pack->inv_l_rcv(i).pn64());
		(*net_enums)["INV_L_RCV"]["err_devicetemp"].push(pack->inv_l_rcv(i).err_devicetemp());
		(*net_enums)["INV_L_RCV"]["km_mix_ana_on"].push(pack->inv_l_rcv(i).km_mix_ana_on());
		(*net_enums)["INV_L_RCV"]["pn82"].push(pack->inv_l_rcv(i).pn82());
		(*net_enums)["INV_L_RCV"]["ni64"].push(pack->inv_l_rcv(i).ni64());
		(*net_enums)["INV_L_RCV"]["err_overvoltage"].push(pack->inv_l_rcv(i).err_overvoltage());
		(*net_enums)["INV_L_RCV"]["d_out_1_on"].push(pack->inv_l_rcv(i).d_out_1_on());
		(*net_enums)["INV_L_RCV"]["km_allow_sync"].push(pack->inv_l_rcv(i).km_allow_sync());
		(*net_enums)["INV_L_RCV"]["ni82"].push(pack->inv_l_rcv(i).ni82());
		(*net_enums)["INV_L_RCV"]["_n064"].push(pack->inv_l_rcv(i)._n064());
		(*net_enums)["INV_L_RCV"]["err_ipeak"].push(pack->inv_l_rcv(i).err_ipeak());
		(*net_enums)["INV_L_RCV"]["d_out_2_on"].push(pack->inv_l_rcv(i).d_out_2_on());
		(*net_enums)["INV_L_RCV"]["km_handwheel"].push(pack->inv_l_rcv(i).km_handwheel());
		(*net_enums)["INV_L_RCV"]["_n082"].push(pack->inv_l_rcv(i)._n082());
		(*net_enums)["INV_L_RCV"]["rsw64"].push(pack->inv_l_rcv(i).rsw64());
		(*net_enums)["INV_L_RCV"]["err_raceaway"].push(pack->inv_l_rcv(i).err_raceaway());
		(*net_enums)["INV_L_RCV"]["btbrdy"].push(pack->inv_l_rcv(i).btbrdy());
		(*net_enums)["INV_L_RCV"]["km_phasing_extend"].push(pack->inv_l_rcv(i).km_phasing_extend());
		(*net_enums)["INV_L_RCV"]["rsw82"].push(pack->inv_l_rcv(i).rsw82());
		(*net_enums)["INV_L_RCV"]["cal064"].push(pack->inv_l_rcv(i).cal064());
		(*net_enums)["INV_L_RCV"]["err_user"].push(pack->inv_l_rcv(i).err_user());
		(*net_enums)["INV_L_RCV"]["go216"].push(pack->inv_l_rcv(i).go216());
		(*net_enums)["INV_L_RCV"]["km_rsvd_11"].push(pack->inv_l_rcv(i).km_rsvd_11());
		(*net_enums)["INV_L_RCV"]["cal082"].push(pack->inv_l_rcv(i).cal082());
		(*net_enums)["INV_L_RCV"]["cal64"].push(pack->inv_l_rcv(i).cal64());
		(*net_enums)["INV_L_RCV"]["d_out_3_on"].push(pack->inv_l_rcv(i).d_out_3_on());
		(*net_enums)["INV_L_RCV"]["km_rsvd_12"].push(pack->inv_l_rcv(i).km_rsvd_12());
		(*net_enums)["INV_L_RCV"]["cal82"].push(pack->inv_l_rcv(i).cal82());
		(*net_enums)["INV_L_RCV"]["tol64"].push(pack->inv_l_rcv(i).tol64());
		(*net_enums)["INV_L_RCV"]["d_out_4_on"].push(pack->inv_l_rcv(i).d_out_4_on());
		(*net_enums)["INV_L_RCV"]["km_rsvd_13"].push(pack->inv_l_rcv(i).km_rsvd_13());
		(*net_enums)["INV_L_RCV"]["tol82"].push(pack->inv_l_rcv(i).tol82());
		(*net_enums)["INV_L_RCV"]["rdy64"].push(pack->inv_l_rcv(i).rdy64());
		(*net_enums)["INV_L_RCV"]["err_hwerr"].push(pack->inv_l_rcv(i).err_hwerr());
		(*net_enums)["INV_L_RCV"]["goff"].push(pack->inv_l_rcv(i).goff());
		(*net_enums)["INV_L_RCV"]["km_pseudo_enable"].push(pack->inv_l_rcv(i).km_pseudo_enable());
		(*net_enums)["INV_L_RCV"]["rdy82"].push(pack->inv_l_rcv(i).rdy82());
		(*net_enums)["INV_L_RCV"]["brk064"].push(pack->inv_l_rcv(i).brk064());
		(*net_enums)["INV_L_RCV"]["err_ballast"].push(pack->inv_l_rcv(i).err_ballast());
		(*net_enums)["INV_L_RCV"]["active190"].push(pack->inv_l_rcv(i).active190());
		inverters_inv_l_rcv_active190_enum_to_string((inverters_inv_l_rcv_active190)pack->inv_l_rcv(i).active190(), buffer);
		(*net_strings)["INV_L_RCV"]["active190"].push(buffer);
		(*net_enums)["INV_L_RCV"]["brk1216"].push(pack->inv_l_rcv(i).brk1216());
		(*net_enums)["INV_L_RCV"]["km_debug_test"].push(pack->inv_l_rcv(i).km_debug_test());
		(*net_enums)["INV_L_RCV"]["brk082"].push(pack->inv_l_rcv(i).brk082());
		(*net_enums)["INV_L_RCV"]["active192"].push(pack->inv_l_rcv(i).active192());
		inverters_inv_l_rcv_active192_enum_to_string((inverters_inv_l_rcv_active192)pack->inv_l_rcv(i).active192(), buffer);
		(*net_strings)["INV_L_RCV"]["active192"].push(buffer);
		(*net_enums)["INV_L_RCV"]["signmag64"].push(pack->inv_l_rcv(i).signmag64());
		(*net_enums)["INV_L_RCV"]["warn_warning_0"].push(pack->inv_l_rcv(i).warn_warning_0());
		(*net_enums)["INV_L_RCV"]["signmag82"].push(pack->inv_l_rcv(i).signmag82());
		(*net_signals)["INV_L_RCV"]["free"].push(pack->inv_l_rcv(i).free());
		(*net_enums)["INV_L_RCV"]["nclip64"].push(pack->inv_l_rcv(i).nclip64());
		(*net_enums)["INV_L_RCV"]["warn_illegal_status"].push(pack->inv_l_rcv(i).warn_illegal_status());
		(*net_enums)["INV_L_RCV"]["nclip82"].push(pack->inv_l_rcv(i).nclip82());
		(*net_enums)["INV_L_RCV"]["nclip_minus64"].push(pack->inv_l_rcv(i).nclip_minus64());
		(*net_enums)["INV_L_RCV"]["warn_safe_in"].push(pack->inv_l_rcv(i).warn_safe_in());
		(*net_enums)["INV_L_RCV"]["nclip_minus82"].push(pack->inv_l_rcv(i).nclip_minus82());
		(*net_enums)["INV_L_RCV"]["nclip_plus64"].push(pack->inv_l_rcv(i).nclip_plus64());
		(*net_enums)["INV_L_RCV"]["nclip_plus82"].push(pack->inv_l_rcv(i).nclip_plus82());
		(*net_enums)["INV_L_RCV"]["irddig64"].push(pack->inv_l_rcv(i).irddig64());
		(*net_enums)["INV_L_RCV"]["irddig82"].push(pack->inv_l_rcv(i).irddig82());
		(*net_enums)["INV_L_RCV"]["iuserchd64"].push(pack->inv_l_rcv(i).iuserchd64());
		(*net_enums)["INV_L_RCV"]["iuserchd82"].push(pack->inv_l_rcv(i).iuserchd82());
		(*net_enums)["INV_L_RCV"]["irdn64"].push(pack->inv_l_rcv(i).irdn64());
		(*net_enums)["INV_L_RCV"]["warn_motortemp"].push(pack->inv_l_rcv(i).warn_motortemp());
		(*net_enums)["INV_L_RCV"]["irdn82"].push(pack->inv_l_rcv(i).irdn82());
		(*net_enums)["INV_L_RCV"]["irdti64"].push(pack->inv_l_rcv(i).irdti64());
		(*net_enums)["INV_L_RCV"]["warn_devicetemp"].push(pack->inv_l_rcv(i).warn_devicetemp());
		(*net_enums)["INV_L_RCV"]["irdti82"].push(pack->inv_l_rcv(i).irdti82());
		(*net_enums)["INV_L_RCV"]["irdtir64"].push(pack->inv_l_rcv(i).irdtir64());
		(*net_enums)["INV_L_RCV"]["warn_vout_sat"].push(pack->inv_l_rcv(i).warn_vout_sat());
		(*net_enums)["INV_L_RCV"]["irdtir82"].push(pack->inv_l_rcv(i).irdtir82());
		(*net_enums)["INV_L_RCV"]["_10hz64"].push(pack->inv_l_rcv(i)._10hz64());
		(*net_enums)["INV_L_RCV"]["warn_ipeak"].push(pack->inv_l_rcv(i).warn_ipeak());
		(*net_enums)["INV_L_RCV"]["_10hz82"].push(pack->inv_l_rcv(i)._10hz82());
		(*net_enums)["INV_L_RCV"]["irdtm64"].push(pack->inv_l_rcv(i).irdtm64());
		(*net_enums)["INV_L_RCV"]["warn_raceaway"].push(pack->inv_l_rcv(i).warn_raceaway());
		(*net_enums)["INV_L_RCV"]["irdtm82"].push(pack->inv_l_rcv(i).irdtm82());
		(*net_enums)["INV_L_RCV"]["irdana64"].push(pack->inv_l_rcv(i).irdana64());
		(*net_enums)["INV_L_RCV"]["irdana82"].push(pack->inv_l_rcv(i).irdana82());
		(*net_enums)["INV_L_RCV"]["iwcns64"].push(pack->inv_l_rcv(i).iwcns64());
		(*net_enums)["INV_L_RCV"]["iwcns82"].push(pack->inv_l_rcv(i).iwcns82());
		(*net_enums)["INV_L_RCV"]["rfepulse64"].push(pack->inv_l_rcv(i).rfepulse64());
		(*net_enums)["INV_L_RCV"]["rfepulse82"].push(pack->inv_l_rcv(i).rfepulse82());
		(*net_enums)["INV_L_RCV"]["md64"].push(pack->inv_l_rcv(i).md64());
		(*net_enums)["INV_L_RCV"]["md82"].push(pack->inv_l_rcv(i).md82());
		(*net_enums)["INV_L_RCV"]["hndwhl64"].push(pack->inv_l_rcv(i).hndwhl64());
		(*net_enums)["INV_L_RCV"]["warn_ballast"].push(pack->inv_l_rcv(i).warn_ballast());
		(*net_enums)["INV_L_RCV"]["hndwhl82"].push(pack->inv_l_rcv(i).hndwhl82());

    }

    for(int i = 0; i < pack->inv_r_send_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->inv_r_send(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->inv_r_send(i)._inner_timestamp();
        (*net_signals)["INV_R_SEND"]["_timestamp"].push(pack->inv_r_send(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["INV_R_SEND"]["send_mux"].push(pack->inv_r_send(i).send_mux());
		inverters_inv_r_send_send_mux_enum_to_string((inverters_inv_r_send_send_mux)pack->inv_r_send(i).send_mux(), buffer);
		(*net_strings)["INV_R_SEND"]["send_mux"].push(buffer);
		(*net_enums)["INV_R_SEND"]["read_id"].push(pack->inv_r_send(i).read_id());
		inverters_inv_r_send_read_id_enum_to_string((inverters_inv_r_send_read_id)pack->inv_r_send(i).read_id(), buffer);
		(*net_strings)["INV_R_SEND"]["read_id"].push(buffer);
		(*net_enums)["INV_R_SEND"]["km_rsvd_0"].push(pack->inv_r_send(i).km_rsvd_0());
		(*net_signals)["INV_R_SEND"]["m_setdig__iq"].push(pack->inv_r_send(i).m_setdig__iq());
		(*net_enums)["INV_R_SEND"]["def_din_1"].push(pack->inv_r_send(i).def_din_1());
		inverters_inv_r_send_def_din_1_enum_to_string((inverters_inv_r_send_def_din_1)pack->inv_r_send(i).def_din_1(), buffer);
		(*net_strings)["INV_R_SEND"]["def_din_1"].push(buffer);
		(*net_enums)["INV_R_SEND"]["def_end_1"].push(pack->inv_r_send(i).def_end_1());
		inverters_inv_r_send_def_end_1_enum_to_string((inverters_inv_r_send_def_end_1)pack->inv_r_send(i).def_end_1(), buffer);
		(*net_strings)["INV_R_SEND"]["def_end_1"].push(buffer);
		(*net_enums)["INV_R_SEND"]["km_speed_0"].push(pack->inv_r_send(i).km_speed_0());
		(*net_enums)["INV_R_SEND"]["km_frg_off"].push(pack->inv_r_send(i).km_frg_off());
		(*net_enums)["INV_R_SEND"]["km_cal_off"].push(pack->inv_r_send(i).km_cal_off());
		(*net_enums)["INV_R_SEND"]["km_tx_tog_stat"].push(pack->inv_r_send(i).km_tx_tog_stat());
		(*net_enums)["INV_R_SEND"]["km_i_limit"].push(pack->inv_r_send(i).km_i_limit());
		(*net_enums)["INV_R_SEND"]["km_n_clip"].push(pack->inv_r_send(i).km_n_clip());
		(*net_enums)["INV_R_SEND"]["km_mix_ana_on"].push(pack->inv_r_send(i).km_mix_ana_on());
		(*net_enums)["INV_R_SEND"]["ret_interval"].push(pack->inv_r_send(i).ret_interval());
		inverters_inv_r_send_ret_interval_enum_to_string((inverters_inv_r_send_ret_interval)pack->inv_r_send(i).ret_interval(), buffer);
		(*net_strings)["INV_R_SEND"]["ret_interval"].push(buffer);
		(*net_enums)["INV_R_SEND"]["km_allow_sync"].push(pack->inv_r_send(i).km_allow_sync());
		(*net_enums)["INV_R_SEND"]["km_handwheel"].push(pack->inv_r_send(i).km_handwheel());
		(*net_enums)["INV_R_SEND"]["km_phasing_extend"].push(pack->inv_r_send(i).km_phasing_extend());
		(*net_enums)["INV_R_SEND"]["km_rsvd_11"].push(pack->inv_r_send(i).km_rsvd_11());
		(*net_enums)["INV_R_SEND"]["km_rsvd_12"].push(pack->inv_r_send(i).km_rsvd_12());
		(*net_enums)["INV_R_SEND"]["km_rsvd_13"].push(pack->inv_r_send(i).km_rsvd_13());
		(*net_enums)["INV_R_SEND"]["km_pseudo_enable"].push(pack->inv_r_send(i).km_pseudo_enable());
		(*net_enums)["INV_R_SEND"]["km_debug_test"].push(pack->inv_r_send(i).km_debug_test());
		(*net_enums)["INV_R_SEND"]["active192"].push(pack->inv_r_send(i).active192());
		inverters_inv_r_send_active192_enum_to_string((inverters_inv_r_send_active192)pack->inv_r_send(i).active192(), buffer);
		(*net_strings)["INV_R_SEND"]["active192"].push(buffer);
		(*net_enums)["INV_R_SEND"]["active190"].push(pack->inv_r_send(i).active190());
		inverters_inv_r_send_active190_enum_to_string((inverters_inv_r_send_active190)pack->inv_r_send(i).active190(), buffer);
		(*net_strings)["INV_R_SEND"]["active190"].push(buffer);

    }

    for(int i = 0; i < pack->inv_r_rcv_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->inv_r_rcv(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->inv_r_rcv(i)._inner_timestamp();
        (*net_signals)["INV_R_RCV"]["_timestamp"].push(pack->inv_r_rcv(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["INV_R_RCV"]["rcv_mux"].push(pack->inv_r_rcv(i).rcv_mux());
		inverters_inv_r_rcv_rcv_mux_enum_to_string((inverters_inv_r_rcv_rcv_mux)pack->inv_r_rcv(i).rcv_mux(), buffer);
		(*net_strings)["INV_R_RCV"]["rcv_mux"].push(buffer);
		(*net_signals)["INV_R_RCV"]["n_actual_filt"].push(pack->inv_r_rcv(i).n_actual_filt());
		(*net_enums)["INV_R_RCV"]["ena64"].push(pack->inv_r_rcv(i).ena64());
		(*net_enums)["INV_R_RCV"]["err_badparas"].push(pack->inv_r_rcv(i).err_badparas());
		(*net_enums)["INV_R_RCV"]["def_end_1"].push(pack->inv_r_rcv(i).def_end_1());
		inverters_inv_r_rcv_def_end_1_enum_to_string((inverters_inv_r_rcv_def_end_1)pack->inv_r_rcv(i).def_end_1(), buffer);
		(*net_strings)["INV_R_RCV"]["def_end_1"].push(buffer);
		(*net_enums)["INV_R_RCV"]["lmt_active_1"].push(pack->inv_r_rcv(i).lmt_active_1());
		(*net_signals)["INV_R_RCV"]["i_cmd"].push(pack->inv_r_rcv(i).i_cmd());
		(*net_signals)["INV_R_RCV"]["i_cmd_ramp"].push(pack->inv_r_rcv(i).i_cmd_ramp());
		(*net_signals)["INV_R_RCV"]["iq_actual"].push(pack->inv_r_rcv(i).iq_actual());
		(*net_signals)["INV_R_RCV"]["t_motor"].push(pack->inv_r_rcv(i).t_motor());
		(*net_signals)["INV_R_RCV"]["t_igbt"].push(pack->inv_r_rcv(i).t_igbt());
		(*net_signals)["INV_R_RCV"]["vdc_bus_filt"].push(pack->inv_r_rcv(i).vdc_bus_filt());
		(*net_enums)["INV_R_RCV"]["km_rsvd_0"].push(pack->inv_r_rcv(i).km_rsvd_0());
		(*net_enums)["INV_R_RCV"]["ena82"].push(pack->inv_r_rcv(i).ena82());
		(*net_enums)["INV_R_RCV"]["def_din_1"].push(pack->inv_r_rcv(i).def_din_1());
		inverters_inv_r_rcv_def_din_1_enum_to_string((inverters_inv_r_rcv_def_din_1)pack->inv_r_rcv(i).def_din_1(), buffer);
		(*net_strings)["INV_R_RCV"]["def_din_1"].push(buffer);
		(*net_signals)["INV_R_RCV"]["m_cmd_ramp"].push(pack->inv_r_rcv(i).m_cmd_ramp());
		(*net_enums)["INV_R_RCV"]["ncr064"].push(pack->inv_r_rcv(i).ncr064());
		(*net_enums)["INV_R_RCV"]["err_powerfault"].push(pack->inv_r_rcv(i).err_powerfault());
		(*net_enums)["INV_R_RCV"]["lmt_active_2"].push(pack->inv_r_rcv(i).lmt_active_2());
		(*net_enums)["INV_R_RCV"]["km_speed_0"].push(pack->inv_r_rcv(i).km_speed_0());
		(*net_enums)["INV_R_RCV"]["ncr082"].push(pack->inv_r_rcv(i).ncr082());
		(*net_enums)["INV_R_RCV"]["lim_plus64"].push(pack->inv_r_rcv(i).lim_plus64());
		(*net_enums)["INV_R_RCV"]["err_rfe_fault"].push(pack->inv_r_rcv(i).err_rfe_fault());
		(*net_enums)["INV_R_RCV"]["in_active_2"].push(pack->inv_r_rcv(i).in_active_2());
		(*net_enums)["INV_R_RCV"]["km_frg_off"].push(pack->inv_r_rcv(i).km_frg_off());
		(*net_enums)["INV_R_RCV"]["lim_plus82"].push(pack->inv_r_rcv(i).lim_plus82());
		(*net_enums)["INV_R_RCV"]["lim_minus64"].push(pack->inv_r_rcv(i).lim_minus64());
		(*net_enums)["INV_R_RCV"]["err_bustimeout"].push(pack->inv_r_rcv(i).err_bustimeout());
		(*net_enums)["INV_R_RCV"]["in_active_1"].push(pack->inv_r_rcv(i).in_active_1());
		(*net_enums)["INV_R_RCV"]["km_cal_off"].push(pack->inv_r_rcv(i).km_cal_off());
		(*net_enums)["INV_R_RCV"]["lim_minus82"].push(pack->inv_r_rcv(i).lim_minus82());
		(*net_enums)["INV_R_RCV"]["ok64"].push(pack->inv_r_rcv(i).ok64());
		(*net_enums)["INV_R_RCV"]["err_feedbacksignal"].push(pack->inv_r_rcv(i).err_feedbacksignal());
		(*net_enums)["INV_R_RCV"]["frgrun"].push(pack->inv_r_rcv(i).frgrun());
		(*net_enums)["INV_R_RCV"]["km_tx_tog_stat"].push(pack->inv_r_rcv(i).km_tx_tog_stat());
		(*net_enums)["INV_R_RCV"]["ok82"].push(pack->inv_r_rcv(i).ok82());
		(*net_enums)["INV_R_RCV"]["icns64"].push(pack->inv_r_rcv(i).icns64());
		(*net_enums)["INV_R_RCV"]["err_powervoltage_low"].push(pack->inv_r_rcv(i).err_powervoltage_low());
		(*net_enums)["INV_R_RCV"]["rfe216"].push(pack->inv_r_rcv(i).rfe216());
		(*net_enums)["INV_R_RCV"]["km_i_limit"].push(pack->inv_r_rcv(i).km_i_limit());
		(*net_enums)["INV_R_RCV"]["icns82"].push(pack->inv_r_rcv(i).icns82());
		(*net_enums)["INV_R_RCV"]["tnlim64"].push(pack->inv_r_rcv(i).tnlim64());
		(*net_enums)["INV_R_RCV"]["err_motortemp"].push(pack->inv_r_rcv(i).err_motortemp());
		(*net_enums)["INV_R_RCV"]["km_n_clip"].push(pack->inv_r_rcv(i).km_n_clip());
		(*net_enums)["INV_R_RCV"]["tnlim82"].push(pack->inv_r_rcv(i).tnlim82());
		(*net_enums)["INV_R_RCV"]["pn64"].push(pack->inv_r_rcv(i).pn64());
		(*net_enums)["INV_R_RCV"]["err_devicetemp"].push(pack->inv_r_rcv(i).err_devicetemp());
		(*net_enums)["INV_R_RCV"]["km_mix_ana_on"].push(pack->inv_r_rcv(i).km_mix_ana_on());
		(*net_enums)["INV_R_RCV"]["pn82"].push(pack->inv_r_rcv(i).pn82());
		(*net_enums)["INV_R_RCV"]["ni64"].push(pack->inv_r_rcv(i).ni64());
		(*net_enums)["INV_R_RCV"]["err_overvoltage"].push(pack->inv_r_rcv(i).err_overvoltage());
		(*net_enums)["INV_R_RCV"]["d_out_1_on"].push(pack->inv_r_rcv(i).d_out_1_on());
		(*net_enums)["INV_R_RCV"]["km_allow_sync"].push(pack->inv_r_rcv(i).km_allow_sync());
		(*net_enums)["INV_R_RCV"]["ni82"].push(pack->inv_r_rcv(i).ni82());
		(*net_enums)["INV_R_RCV"]["_n064"].push(pack->inv_r_rcv(i)._n064());
		(*net_enums)["INV_R_RCV"]["err_ipeak"].push(pack->inv_r_rcv(i).err_ipeak());
		(*net_enums)["INV_R_RCV"]["d_out_2_on"].push(pack->inv_r_rcv(i).d_out_2_on());
		(*net_enums)["INV_R_RCV"]["km_handwheel"].push(pack->inv_r_rcv(i).km_handwheel());
		(*net_enums)["INV_R_RCV"]["_n082"].push(pack->inv_r_rcv(i)._n082());
		(*net_enums)["INV_R_RCV"]["rsw64"].push(pack->inv_r_rcv(i).rsw64());
		(*net_enums)["INV_R_RCV"]["err_raceaway"].push(pack->inv_r_rcv(i).err_raceaway());
		(*net_enums)["INV_R_RCV"]["btbrdy"].push(pack->inv_r_rcv(i).btbrdy());
		(*net_enums)["INV_R_RCV"]["km_phasing_extend"].push(pack->inv_r_rcv(i).km_phasing_extend());
		(*net_enums)["INV_R_RCV"]["rsw82"].push(pack->inv_r_rcv(i).rsw82());
		(*net_enums)["INV_R_RCV"]["cal064"].push(pack->inv_r_rcv(i).cal064());
		(*net_enums)["INV_R_RCV"]["err_user"].push(pack->inv_r_rcv(i).err_user());
		(*net_enums)["INV_R_RCV"]["go216"].push(pack->inv_r_rcv(i).go216());
		(*net_enums)["INV_R_RCV"]["km_rsvd_11"].push(pack->inv_r_rcv(i).km_rsvd_11());
		(*net_enums)["INV_R_RCV"]["cal082"].push(pack->inv_r_rcv(i).cal082());
		(*net_enums)["INV_R_RCV"]["cal64"].push(pack->inv_r_rcv(i).cal64());
		(*net_enums)["INV_R_RCV"]["d_out_3_on"].push(pack->inv_r_rcv(i).d_out_3_on());
		(*net_enums)["INV_R_RCV"]["km_rsvd_12"].push(pack->inv_r_rcv(i).km_rsvd_12());
		(*net_enums)["INV_R_RCV"]["cal82"].push(pack->inv_r_rcv(i).cal82());
		(*net_enums)["INV_R_RCV"]["tol64"].push(pack->inv_r_rcv(i).tol64());
		(*net_enums)["INV_R_RCV"]["d_out_4_on"].push(pack->inv_r_rcv(i).d_out_4_on());
		(*net_enums)["INV_R_RCV"]["km_rsvd_13"].push(pack->inv_r_rcv(i).km_rsvd_13());
		(*net_enums)["INV_R_RCV"]["tol82"].push(pack->inv_r_rcv(i).tol82());
		(*net_enums)["INV_R_RCV"]["rdy64"].push(pack->inv_r_rcv(i).rdy64());
		(*net_enums)["INV_R_RCV"]["err_hwerr"].push(pack->inv_r_rcv(i).err_hwerr());
		(*net_enums)["INV_R_RCV"]["goff"].push(pack->inv_r_rcv(i).goff());
		(*net_enums)["INV_R_RCV"]["km_pseudo_enable"].push(pack->inv_r_rcv(i).km_pseudo_enable());
		(*net_enums)["INV_R_RCV"]["rdy82"].push(pack->inv_r_rcv(i).rdy82());
		(*net_enums)["INV_R_RCV"]["brk064"].push(pack->inv_r_rcv(i).brk064());
		(*net_enums)["INV_R_RCV"]["err_ballast"].push(pack->inv_r_rcv(i).err_ballast());
		(*net_enums)["INV_R_RCV"]["active190"].push(pack->inv_r_rcv(i).active190());
		inverters_inv_r_rcv_active190_enum_to_string((inverters_inv_r_rcv_active190)pack->inv_r_rcv(i).active190(), buffer);
		(*net_strings)["INV_R_RCV"]["active190"].push(buffer);
		(*net_enums)["INV_R_RCV"]["brk1216"].push(pack->inv_r_rcv(i).brk1216());
		(*net_enums)["INV_R_RCV"]["km_debug_test"].push(pack->inv_r_rcv(i).km_debug_test());
		(*net_enums)["INV_R_RCV"]["brk082"].push(pack->inv_r_rcv(i).brk082());
		(*net_enums)["INV_R_RCV"]["active192"].push(pack->inv_r_rcv(i).active192());
		inverters_inv_r_rcv_active192_enum_to_string((inverters_inv_r_rcv_active192)pack->inv_r_rcv(i).active192(), buffer);
		(*net_strings)["INV_R_RCV"]["active192"].push(buffer);
		(*net_enums)["INV_R_RCV"]["signmag64"].push(pack->inv_r_rcv(i).signmag64());
		(*net_enums)["INV_R_RCV"]["warn_warning_0"].push(pack->inv_r_rcv(i).warn_warning_0());
		(*net_enums)["INV_R_RCV"]["signmag82"].push(pack->inv_r_rcv(i).signmag82());
		(*net_signals)["INV_R_RCV"]["free"].push(pack->inv_r_rcv(i).free());
		(*net_enums)["INV_R_RCV"]["nclip64"].push(pack->inv_r_rcv(i).nclip64());
		(*net_enums)["INV_R_RCV"]["warn_illegal_status"].push(pack->inv_r_rcv(i).warn_illegal_status());
		(*net_enums)["INV_R_RCV"]["nclip82"].push(pack->inv_r_rcv(i).nclip82());
		(*net_enums)["INV_R_RCV"]["nclip_minus64"].push(pack->inv_r_rcv(i).nclip_minus64());
		(*net_enums)["INV_R_RCV"]["warn_safe_in"].push(pack->inv_r_rcv(i).warn_safe_in());
		(*net_enums)["INV_R_RCV"]["nclip_minus82"].push(pack->inv_r_rcv(i).nclip_minus82());
		(*net_enums)["INV_R_RCV"]["nclip_plus64"].push(pack->inv_r_rcv(i).nclip_plus64());
		(*net_enums)["INV_R_RCV"]["nclip_plus82"].push(pack->inv_r_rcv(i).nclip_plus82());
		(*net_enums)["INV_R_RCV"]["irddig64"].push(pack->inv_r_rcv(i).irddig64());
		(*net_enums)["INV_R_RCV"]["irddig82"].push(pack->inv_r_rcv(i).irddig82());
		(*net_enums)["INV_R_RCV"]["iuserchd64"].push(pack->inv_r_rcv(i).iuserchd64());
		(*net_enums)["INV_R_RCV"]["iuserchd82"].push(pack->inv_r_rcv(i).iuserchd82());
		(*net_enums)["INV_R_RCV"]["irdn64"].push(pack->inv_r_rcv(i).irdn64());
		(*net_enums)["INV_R_RCV"]["warn_motortemp"].push(pack->inv_r_rcv(i).warn_motortemp());
		(*net_enums)["INV_R_RCV"]["irdn82"].push(pack->inv_r_rcv(i).irdn82());
		(*net_enums)["INV_R_RCV"]["irdti64"].push(pack->inv_r_rcv(i).irdti64());
		(*net_enums)["INV_R_RCV"]["warn_devicetemp"].push(pack->inv_r_rcv(i).warn_devicetemp());
		(*net_enums)["INV_R_RCV"]["irdti82"].push(pack->inv_r_rcv(i).irdti82());
		(*net_enums)["INV_R_RCV"]["irdtir64"].push(pack->inv_r_rcv(i).irdtir64());
		(*net_enums)["INV_R_RCV"]["warn_vout_sat"].push(pack->inv_r_rcv(i).warn_vout_sat());
		(*net_enums)["INV_R_RCV"]["irdtir82"].push(pack->inv_r_rcv(i).irdtir82());
		(*net_enums)["INV_R_RCV"]["_10hz64"].push(pack->inv_r_rcv(i)._10hz64());
		(*net_enums)["INV_R_RCV"]["warn_ipeak"].push(pack->inv_r_rcv(i).warn_ipeak());
		(*net_enums)["INV_R_RCV"]["_10hz82"].push(pack->inv_r_rcv(i)._10hz82());
		(*net_enums)["INV_R_RCV"]["irdtm64"].push(pack->inv_r_rcv(i).irdtm64());
		(*net_enums)["INV_R_RCV"]["warn_raceaway"].push(pack->inv_r_rcv(i).warn_raceaway());
		(*net_enums)["INV_R_RCV"]["irdtm82"].push(pack->inv_r_rcv(i).irdtm82());
		(*net_enums)["INV_R_RCV"]["irdana64"].push(pack->inv_r_rcv(i).irdana64());
		(*net_enums)["INV_R_RCV"]["irdana82"].push(pack->inv_r_rcv(i).irdana82());
		(*net_enums)["INV_R_RCV"]["iwcns64"].push(pack->inv_r_rcv(i).iwcns64());
		(*net_enums)["INV_R_RCV"]["iwcns82"].push(pack->inv_r_rcv(i).iwcns82());
		(*net_enums)["INV_R_RCV"]["rfepulse64"].push(pack->inv_r_rcv(i).rfepulse64());
		(*net_enums)["INV_R_RCV"]["rfepulse82"].push(pack->inv_r_rcv(i).rfepulse82());
		(*net_enums)["INV_R_RCV"]["md64"].push(pack->inv_r_rcv(i).md64());
		(*net_enums)["INV_R_RCV"]["md82"].push(pack->inv_r_rcv(i).md82());
		(*net_enums)["INV_R_RCV"]["hndwhl64"].push(pack->inv_r_rcv(i).hndwhl64());
		(*net_enums)["INV_R_RCV"]["warn_ballast"].push(pack->inv_r_rcv(i).warn_ballast());
		(*net_enums)["INV_R_RCV"]["hndwhl82"].push(pack->inv_r_rcv(i).hndwhl82());

    }

}

void inverters_proto_interface_serialize_from_id(canlib_message_id id, inverters::Pack* pack, device_t* device) {
    int index = inverters_index_from_id(id);

    if (index == -1) return;

    switch(id) {
        
        case 513: {
            inverters_inv_l_send_t* msg = (inverters_inv_l_send_t*)(device->message);
            inverters::INV_L_SEND* proto_msg = pack->add_inv_l_send();
			proto_msg->set_send_mux((inverters::inverters_inv_l_send_send_mux)msg->send_mux);
			proto_msg->set_read_id((inverters::inverters_inv_l_send_read_id)msg->read_id);
			proto_msg->set_km_rsvd_0(msg->km_rsvd_0);
			proto_msg->set_m_setdig__iq(msg->m_setdig__iq);
			proto_msg->set_def_din_1((inverters::inverters_inv_l_send_def_din_1)msg->def_din_1);
			proto_msg->set_def_end_1((inverters::inverters_inv_l_send_def_end_1)msg->def_end_1);
			proto_msg->set_km_speed_0(msg->km_speed_0);
			proto_msg->set_km_frg_off(msg->km_frg_off);
			proto_msg->set_km_cal_off(msg->km_cal_off);
			proto_msg->set_km_tx_tog_stat(msg->km_tx_tog_stat);
			proto_msg->set_km_i_limit(msg->km_i_limit);
			proto_msg->set_km_n_clip(msg->km_n_clip);
			proto_msg->set_km_mix_ana_on(msg->km_mix_ana_on);
			proto_msg->set_ret_interval((inverters::inverters_inv_l_send_ret_interval)msg->ret_interval);
			proto_msg->set_km_allow_sync(msg->km_allow_sync);
			proto_msg->set_km_handwheel(msg->km_handwheel);
			proto_msg->set_km_phasing_extend(msg->km_phasing_extend);
			proto_msg->set_km_rsvd_11(msg->km_rsvd_11);
			proto_msg->set_km_rsvd_12(msg->km_rsvd_12);
			proto_msg->set_km_rsvd_13(msg->km_rsvd_13);
			proto_msg->set_km_pseudo_enable(msg->km_pseudo_enable);
			proto_msg->set_km_debug_test(msg->km_debug_test);
			proto_msg->set_active192((inverters::inverters_inv_l_send_active192)msg->active192);
			proto_msg->set_active190((inverters::inverters_inv_l_send_active190)msg->active190);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 385: {
            inverters_inv_l_rcv_converted_t* msg = (inverters_inv_l_rcv_converted_t*)(device->message);
            inverters::INV_L_RCV* proto_msg = pack->add_inv_l_rcv();
			proto_msg->set_rcv_mux((inverters::inverters_inv_l_rcv_rcv_mux)msg->rcv_mux);
			proto_msg->set_n_actual_filt(msg->n_actual_filt);
			proto_msg->set_ena64(msg->ena64);
			proto_msg->set_err_badparas(msg->err_badparas);
			proto_msg->set_def_end_1((inverters::inverters_inv_l_rcv_def_end_1)msg->def_end_1);
			proto_msg->set_lmt_active_1(msg->lmt_active_1);
			proto_msg->set_i_cmd(msg->i_cmd);
			proto_msg->set_i_cmd_ramp(msg->i_cmd_ramp);
			proto_msg->set_iq_actual(msg->iq_actual);
			proto_msg->set_t_motor(msg->t_motor);
			proto_msg->set_t_igbt(msg->t_igbt);
			proto_msg->set_vdc_bus_filt(msg->vdc_bus_filt);
			proto_msg->set_km_rsvd_0(msg->km_rsvd_0);
			proto_msg->set_ena82(msg->ena82);
			proto_msg->set_def_din_1((inverters::inverters_inv_l_rcv_def_din_1)msg->def_din_1);
			proto_msg->set_m_cmd_ramp(msg->m_cmd_ramp);
			proto_msg->set_ncr064(msg->ncr064);
			proto_msg->set_err_powerfault(msg->err_powerfault);
			proto_msg->set_lmt_active_2(msg->lmt_active_2);
			proto_msg->set_km_speed_0(msg->km_speed_0);
			proto_msg->set_ncr082(msg->ncr082);
			proto_msg->set_lim_plus64(msg->lim_plus64);
			proto_msg->set_err_rfe_fault(msg->err_rfe_fault);
			proto_msg->set_in_active_2(msg->in_active_2);
			proto_msg->set_km_frg_off(msg->km_frg_off);
			proto_msg->set_lim_plus82(msg->lim_plus82);
			proto_msg->set_lim_minus64(msg->lim_minus64);
			proto_msg->set_err_bustimeout(msg->err_bustimeout);
			proto_msg->set_in_active_1(msg->in_active_1);
			proto_msg->set_km_cal_off(msg->km_cal_off);
			proto_msg->set_lim_minus82(msg->lim_minus82);
			proto_msg->set_ok64(msg->ok64);
			proto_msg->set_err_feedbacksignal(msg->err_feedbacksignal);
			proto_msg->set_frgrun(msg->frgrun);
			proto_msg->set_km_tx_tog_stat(msg->km_tx_tog_stat);
			proto_msg->set_ok82(msg->ok82);
			proto_msg->set_icns64(msg->icns64);
			proto_msg->set_err_powervoltage_low(msg->err_powervoltage_low);
			proto_msg->set_rfe216(msg->rfe216);
			proto_msg->set_km_i_limit(msg->km_i_limit);
			proto_msg->set_icns82(msg->icns82);
			proto_msg->set_tnlim64(msg->tnlim64);
			proto_msg->set_err_motortemp(msg->err_motortemp);
			proto_msg->set_km_n_clip(msg->km_n_clip);
			proto_msg->set_tnlim82(msg->tnlim82);
			proto_msg->set_pn64(msg->pn64);
			proto_msg->set_err_devicetemp(msg->err_devicetemp);
			proto_msg->set_km_mix_ana_on(msg->km_mix_ana_on);
			proto_msg->set_pn82(msg->pn82);
			proto_msg->set_ni64(msg->ni64);
			proto_msg->set_err_overvoltage(msg->err_overvoltage);
			proto_msg->set_d_out_1_on(msg->d_out_1_on);
			proto_msg->set_km_allow_sync(msg->km_allow_sync);
			proto_msg->set_ni82(msg->ni82);
			proto_msg->set__n064(msg->_n064);
			proto_msg->set_err_ipeak(msg->err_ipeak);
			proto_msg->set_d_out_2_on(msg->d_out_2_on);
			proto_msg->set_km_handwheel(msg->km_handwheel);
			proto_msg->set__n082(msg->_n082);
			proto_msg->set_rsw64(msg->rsw64);
			proto_msg->set_err_raceaway(msg->err_raceaway);
			proto_msg->set_btbrdy(msg->btbrdy);
			proto_msg->set_km_phasing_extend(msg->km_phasing_extend);
			proto_msg->set_rsw82(msg->rsw82);
			proto_msg->set_cal064(msg->cal064);
			proto_msg->set_err_user(msg->err_user);
			proto_msg->set_go216(msg->go216);
			proto_msg->set_km_rsvd_11(msg->km_rsvd_11);
			proto_msg->set_cal082(msg->cal082);
			proto_msg->set_cal64(msg->cal64);
			proto_msg->set_d_out_3_on(msg->d_out_3_on);
			proto_msg->set_km_rsvd_12(msg->km_rsvd_12);
			proto_msg->set_cal82(msg->cal82);
			proto_msg->set_tol64(msg->tol64);
			proto_msg->set_d_out_4_on(msg->d_out_4_on);
			proto_msg->set_km_rsvd_13(msg->km_rsvd_13);
			proto_msg->set_tol82(msg->tol82);
			proto_msg->set_rdy64(msg->rdy64);
			proto_msg->set_err_hwerr(msg->err_hwerr);
			proto_msg->set_goff(msg->goff);
			proto_msg->set_km_pseudo_enable(msg->km_pseudo_enable);
			proto_msg->set_rdy82(msg->rdy82);
			proto_msg->set_brk064(msg->brk064);
			proto_msg->set_err_ballast(msg->err_ballast);
			proto_msg->set_active190((inverters::inverters_inv_l_rcv_active190)msg->active190);
			proto_msg->set_brk1216(msg->brk1216);
			proto_msg->set_km_debug_test(msg->km_debug_test);
			proto_msg->set_brk082(msg->brk082);
			proto_msg->set_active192((inverters::inverters_inv_l_rcv_active192)msg->active192);
			proto_msg->set_signmag64(msg->signmag64);
			proto_msg->set_warn_warning_0(msg->warn_warning_0);
			proto_msg->set_signmag82(msg->signmag82);
			proto_msg->set_free(msg->free);
			proto_msg->set_nclip64(msg->nclip64);
			proto_msg->set_warn_illegal_status(msg->warn_illegal_status);
			proto_msg->set_nclip82(msg->nclip82);
			proto_msg->set_nclip_minus64(msg->nclip_minus64);
			proto_msg->set_warn_safe_in(msg->warn_safe_in);
			proto_msg->set_nclip_minus82(msg->nclip_minus82);
			proto_msg->set_nclip_plus64(msg->nclip_plus64);
			proto_msg->set_nclip_plus82(msg->nclip_plus82);
			proto_msg->set_irddig64(msg->irddig64);
			proto_msg->set_irddig82(msg->irddig82);
			proto_msg->set_iuserchd64(msg->iuserchd64);
			proto_msg->set_iuserchd82(msg->iuserchd82);
			proto_msg->set_irdn64(msg->irdn64);
			proto_msg->set_warn_motortemp(msg->warn_motortemp);
			proto_msg->set_irdn82(msg->irdn82);
			proto_msg->set_irdti64(msg->irdti64);
			proto_msg->set_warn_devicetemp(msg->warn_devicetemp);
			proto_msg->set_irdti82(msg->irdti82);
			proto_msg->set_irdtir64(msg->irdtir64);
			proto_msg->set_warn_vout_sat(msg->warn_vout_sat);
			proto_msg->set_irdtir82(msg->irdtir82);
			proto_msg->set__10hz64(msg->_10hz64);
			proto_msg->set_warn_ipeak(msg->warn_ipeak);
			proto_msg->set__10hz82(msg->_10hz82);
			proto_msg->set_irdtm64(msg->irdtm64);
			proto_msg->set_warn_raceaway(msg->warn_raceaway);
			proto_msg->set_irdtm82(msg->irdtm82);
			proto_msg->set_irdana64(msg->irdana64);
			proto_msg->set_irdana82(msg->irdana82);
			proto_msg->set_iwcns64(msg->iwcns64);
			proto_msg->set_iwcns82(msg->iwcns82);
			proto_msg->set_rfepulse64(msg->rfepulse64);
			proto_msg->set_rfepulse82(msg->rfepulse82);
			proto_msg->set_md64(msg->md64);
			proto_msg->set_md82(msg->md82);
			proto_msg->set_hndwhl64(msg->hndwhl64);
			proto_msg->set_warn_ballast(msg->warn_ballast);
			proto_msg->set_hndwhl82(msg->hndwhl82);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 514: {
            inverters_inv_r_send_t* msg = (inverters_inv_r_send_t*)(device->message);
            inverters::INV_R_SEND* proto_msg = pack->add_inv_r_send();
			proto_msg->set_send_mux((inverters::inverters_inv_r_send_send_mux)msg->send_mux);
			proto_msg->set_read_id((inverters::inverters_inv_r_send_read_id)msg->read_id);
			proto_msg->set_km_rsvd_0(msg->km_rsvd_0);
			proto_msg->set_m_setdig__iq(msg->m_setdig__iq);
			proto_msg->set_def_din_1((inverters::inverters_inv_r_send_def_din_1)msg->def_din_1);
			proto_msg->set_def_end_1((inverters::inverters_inv_r_send_def_end_1)msg->def_end_1);
			proto_msg->set_km_speed_0(msg->km_speed_0);
			proto_msg->set_km_frg_off(msg->km_frg_off);
			proto_msg->set_km_cal_off(msg->km_cal_off);
			proto_msg->set_km_tx_tog_stat(msg->km_tx_tog_stat);
			proto_msg->set_km_i_limit(msg->km_i_limit);
			proto_msg->set_km_n_clip(msg->km_n_clip);
			proto_msg->set_km_mix_ana_on(msg->km_mix_ana_on);
			proto_msg->set_ret_interval((inverters::inverters_inv_r_send_ret_interval)msg->ret_interval);
			proto_msg->set_km_allow_sync(msg->km_allow_sync);
			proto_msg->set_km_handwheel(msg->km_handwheel);
			proto_msg->set_km_phasing_extend(msg->km_phasing_extend);
			proto_msg->set_km_rsvd_11(msg->km_rsvd_11);
			proto_msg->set_km_rsvd_12(msg->km_rsvd_12);
			proto_msg->set_km_rsvd_13(msg->km_rsvd_13);
			proto_msg->set_km_pseudo_enable(msg->km_pseudo_enable);
			proto_msg->set_km_debug_test(msg->km_debug_test);
			proto_msg->set_active192((inverters::inverters_inv_r_send_active192)msg->active192);
			proto_msg->set_active190((inverters::inverters_inv_r_send_active190)msg->active190);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 386: {
            inverters_inv_r_rcv_converted_t* msg = (inverters_inv_r_rcv_converted_t*)(device->message);
            inverters::INV_R_RCV* proto_msg = pack->add_inv_r_rcv();
			proto_msg->set_rcv_mux((inverters::inverters_inv_r_rcv_rcv_mux)msg->rcv_mux);
			proto_msg->set_n_actual_filt(msg->n_actual_filt);
			proto_msg->set_ena64(msg->ena64);
			proto_msg->set_err_badparas(msg->err_badparas);
			proto_msg->set_def_end_1((inverters::inverters_inv_r_rcv_def_end_1)msg->def_end_1);
			proto_msg->set_lmt_active_1(msg->lmt_active_1);
			proto_msg->set_i_cmd(msg->i_cmd);
			proto_msg->set_i_cmd_ramp(msg->i_cmd_ramp);
			proto_msg->set_iq_actual(msg->iq_actual);
			proto_msg->set_t_motor(msg->t_motor);
			proto_msg->set_t_igbt(msg->t_igbt);
			proto_msg->set_vdc_bus_filt(msg->vdc_bus_filt);
			proto_msg->set_km_rsvd_0(msg->km_rsvd_0);
			proto_msg->set_ena82(msg->ena82);
			proto_msg->set_def_din_1((inverters::inverters_inv_r_rcv_def_din_1)msg->def_din_1);
			proto_msg->set_m_cmd_ramp(msg->m_cmd_ramp);
			proto_msg->set_ncr064(msg->ncr064);
			proto_msg->set_err_powerfault(msg->err_powerfault);
			proto_msg->set_lmt_active_2(msg->lmt_active_2);
			proto_msg->set_km_speed_0(msg->km_speed_0);
			proto_msg->set_ncr082(msg->ncr082);
			proto_msg->set_lim_plus64(msg->lim_plus64);
			proto_msg->set_err_rfe_fault(msg->err_rfe_fault);
			proto_msg->set_in_active_2(msg->in_active_2);
			proto_msg->set_km_frg_off(msg->km_frg_off);
			proto_msg->set_lim_plus82(msg->lim_plus82);
			proto_msg->set_lim_minus64(msg->lim_minus64);
			proto_msg->set_err_bustimeout(msg->err_bustimeout);
			proto_msg->set_in_active_1(msg->in_active_1);
			proto_msg->set_km_cal_off(msg->km_cal_off);
			proto_msg->set_lim_minus82(msg->lim_minus82);
			proto_msg->set_ok64(msg->ok64);
			proto_msg->set_err_feedbacksignal(msg->err_feedbacksignal);
			proto_msg->set_frgrun(msg->frgrun);
			proto_msg->set_km_tx_tog_stat(msg->km_tx_tog_stat);
			proto_msg->set_ok82(msg->ok82);
			proto_msg->set_icns64(msg->icns64);
			proto_msg->set_err_powervoltage_low(msg->err_powervoltage_low);
			proto_msg->set_rfe216(msg->rfe216);
			proto_msg->set_km_i_limit(msg->km_i_limit);
			proto_msg->set_icns82(msg->icns82);
			proto_msg->set_tnlim64(msg->tnlim64);
			proto_msg->set_err_motortemp(msg->err_motortemp);
			proto_msg->set_km_n_clip(msg->km_n_clip);
			proto_msg->set_tnlim82(msg->tnlim82);
			proto_msg->set_pn64(msg->pn64);
			proto_msg->set_err_devicetemp(msg->err_devicetemp);
			proto_msg->set_km_mix_ana_on(msg->km_mix_ana_on);
			proto_msg->set_pn82(msg->pn82);
			proto_msg->set_ni64(msg->ni64);
			proto_msg->set_err_overvoltage(msg->err_overvoltage);
			proto_msg->set_d_out_1_on(msg->d_out_1_on);
			proto_msg->set_km_allow_sync(msg->km_allow_sync);
			proto_msg->set_ni82(msg->ni82);
			proto_msg->set__n064(msg->_n064);
			proto_msg->set_err_ipeak(msg->err_ipeak);
			proto_msg->set_d_out_2_on(msg->d_out_2_on);
			proto_msg->set_km_handwheel(msg->km_handwheel);
			proto_msg->set__n082(msg->_n082);
			proto_msg->set_rsw64(msg->rsw64);
			proto_msg->set_err_raceaway(msg->err_raceaway);
			proto_msg->set_btbrdy(msg->btbrdy);
			proto_msg->set_km_phasing_extend(msg->km_phasing_extend);
			proto_msg->set_rsw82(msg->rsw82);
			proto_msg->set_cal064(msg->cal064);
			proto_msg->set_err_user(msg->err_user);
			proto_msg->set_go216(msg->go216);
			proto_msg->set_km_rsvd_11(msg->km_rsvd_11);
			proto_msg->set_cal082(msg->cal082);
			proto_msg->set_cal64(msg->cal64);
			proto_msg->set_d_out_3_on(msg->d_out_3_on);
			proto_msg->set_km_rsvd_12(msg->km_rsvd_12);
			proto_msg->set_cal82(msg->cal82);
			proto_msg->set_tol64(msg->tol64);
			proto_msg->set_d_out_4_on(msg->d_out_4_on);
			proto_msg->set_km_rsvd_13(msg->km_rsvd_13);
			proto_msg->set_tol82(msg->tol82);
			proto_msg->set_rdy64(msg->rdy64);
			proto_msg->set_err_hwerr(msg->err_hwerr);
			proto_msg->set_goff(msg->goff);
			proto_msg->set_km_pseudo_enable(msg->km_pseudo_enable);
			proto_msg->set_rdy82(msg->rdy82);
			proto_msg->set_brk064(msg->brk064);
			proto_msg->set_err_ballast(msg->err_ballast);
			proto_msg->set_active190((inverters::inverters_inv_r_rcv_active190)msg->active190);
			proto_msg->set_brk1216(msg->brk1216);
			proto_msg->set_km_debug_test(msg->km_debug_test);
			proto_msg->set_brk082(msg->brk082);
			proto_msg->set_active192((inverters::inverters_inv_r_rcv_active192)msg->active192);
			proto_msg->set_signmag64(msg->signmag64);
			proto_msg->set_warn_warning_0(msg->warn_warning_0);
			proto_msg->set_signmag82(msg->signmag82);
			proto_msg->set_free(msg->free);
			proto_msg->set_nclip64(msg->nclip64);
			proto_msg->set_warn_illegal_status(msg->warn_illegal_status);
			proto_msg->set_nclip82(msg->nclip82);
			proto_msg->set_nclip_minus64(msg->nclip_minus64);
			proto_msg->set_warn_safe_in(msg->warn_safe_in);
			proto_msg->set_nclip_minus82(msg->nclip_minus82);
			proto_msg->set_nclip_plus64(msg->nclip_plus64);
			proto_msg->set_nclip_plus82(msg->nclip_plus82);
			proto_msg->set_irddig64(msg->irddig64);
			proto_msg->set_irddig82(msg->irddig82);
			proto_msg->set_iuserchd64(msg->iuserchd64);
			proto_msg->set_iuserchd82(msg->iuserchd82);
			proto_msg->set_irdn64(msg->irdn64);
			proto_msg->set_warn_motortemp(msg->warn_motortemp);
			proto_msg->set_irdn82(msg->irdn82);
			proto_msg->set_irdti64(msg->irdti64);
			proto_msg->set_warn_devicetemp(msg->warn_devicetemp);
			proto_msg->set_irdti82(msg->irdti82);
			proto_msg->set_irdtir64(msg->irdtir64);
			proto_msg->set_warn_vout_sat(msg->warn_vout_sat);
			proto_msg->set_irdtir82(msg->irdtir82);
			proto_msg->set__10hz64(msg->_10hz64);
			proto_msg->set_warn_ipeak(msg->warn_ipeak);
			proto_msg->set__10hz82(msg->_10hz82);
			proto_msg->set_irdtm64(msg->irdtm64);
			proto_msg->set_warn_raceaway(msg->warn_raceaway);
			proto_msg->set_irdtm82(msg->irdtm82);
			proto_msg->set_irdana64(msg->irdana64);
			proto_msg->set_irdana82(msg->irdana82);
			proto_msg->set_iwcns64(msg->iwcns64);
			proto_msg->set_iwcns82(msg->iwcns82);
			proto_msg->set_rfepulse64(msg->rfepulse64);
			proto_msg->set_rfepulse82(msg->rfepulse82);
			proto_msg->set_md64(msg->md64);
			proto_msg->set_md82(msg->md82);
			proto_msg->set_hndwhl64(msg->hndwhl64);
			proto_msg->set_warn_ballast(msg->warn_ballast);
			proto_msg->set_hndwhl82(msg->hndwhl82);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

    }
}



#endif // inverters_PROTO_INTERAFCE_IMPLEMENTATION

#endif // inverters_PROTO_INTERFACE_H
