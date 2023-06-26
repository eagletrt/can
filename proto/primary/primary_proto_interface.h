
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

void primary_proto_interface_serialize_from_id(canlib_message_id id, primary::Pack* pack, device_t* device);
void primary_proto_interface_deserialize(primary::Pack* pack, network_enums* net_enums, network_signals* net_signals, network_strings* net_strings, uint64_t resample_us);

#ifdef primary_PROTO_INTERAFCE_IMPLEMENTATION

void primary_proto_interface_deserialize(primary::Pack* pack, network_enums* net_enums, network_signals* net_signals, network_strings* net_strings, uint64_t resample_us) {
    char buffer[1024];
    
    for(int i = 0; i < pack->nlg5_diag_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->nlg5_diag_tx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->nlg5_diag_tx(i)._inner_timestamp();
        (*net_signals)["NLG5_DIAG_TX"]["_timestamp"].push(pack->nlg5_diag_tx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["NLG5_DIAG_TX"]["lad_d_paramrp"].push(pack->nlg5_diag_tx(i).lad_d_paramrp());

    }

    for(int i = 0; i < pack->nlg5_diag_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->nlg5_diag_rx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->nlg5_diag_rx(i)._inner_timestamp();
        (*net_signals)["NLG5_DIAG_RX"]["_timestamp"].push(pack->nlg5_diag_rx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["NLG5_DIAG_RX"]["lad_d_paramrq"].push(pack->nlg5_diag_rx(i).lad_d_paramrq());

    }

    for(int i = 0; i < pack->nlg5_err_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->nlg5_err(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->nlg5_err(i)._inner_timestamp();
        (*net_signals)["NLG5_ERR"]["_timestamp"].push(pack->nlg5_err(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["NLG5_ERR"]["nlg5_e_oov"].push(pack->nlg5_err(i).nlg5_e_oov());
		(*net_enums)["NLG5_ERR"]["nlg5_e_mov_ii"].push(pack->nlg5_err(i).nlg5_e_mov_ii());
		(*net_enums)["NLG5_ERR"]["nlg5_e_mov_i"].push(pack->nlg5_err(i).nlg5_e_mov_i());
		(*net_enums)["NLG5_ERR"]["nlg5_e_sc"].push(pack->nlg5_err(i).nlg5_e_sc());
		(*net_enums)["NLG5_ERR"]["nlg5_e_p_om"].push(pack->nlg5_err(i).nlg5_e_p_om());
		(*net_enums)["NLG5_ERR"]["nlg5_e_p_mv"].push(pack->nlg5_err(i).nlg5_e_p_mv());
		(*net_enums)["NLG5_ERR"]["nlg5_e_of"].push(pack->nlg5_err(i).nlg5_e_of());
		(*net_enums)["NLG5_ERR"]["nlg5_e_mf"].push(pack->nlg5_err(i).nlg5_e_mf());
		(*net_enums)["NLG5_ERR"]["nlg5_e_b_p"].push(pack->nlg5_err(i).nlg5_e_b_p());
		(*net_enums)["NLG5_ERR"]["nlg5_e_t_c"].push(pack->nlg5_err(i).nlg5_e_t_c());
		(*net_enums)["NLG5_ERR"]["nlg5_e_t_pow"].push(pack->nlg5_err(i).nlg5_e_t_pow());
		(*net_enums)["NLG5_ERR"]["nlg5_e_t_dio"].push(pack->nlg5_err(i).nlg5_e_t_dio());
		(*net_enums)["NLG5_ERR"]["nlg5_e_t_tr"].push(pack->nlg5_err(i).nlg5_e_t_tr());
		(*net_enums)["NLG5_ERR"]["nlg5_e_t_ext1"].push(pack->nlg5_err(i).nlg5_e_t_ext1());
		(*net_enums)["NLG5_ERR"]["nlg5_e_t_ext2"].push(pack->nlg5_err(i).nlg5_e_t_ext2());
		(*net_enums)["NLG5_ERR"]["nlg5_e_t_ext3"].push(pack->nlg5_err(i).nlg5_e_t_ext3());
		(*net_enums)["NLG5_ERR"]["nlg5_e_f_crc"].push(pack->nlg5_err(i).nlg5_e_f_crc());
		(*net_enums)["NLG5_ERR"]["nlg5_e_nv_crc"].push(pack->nlg5_err(i).nlg5_e_nv_crc());
		(*net_enums)["NLG5_ERR"]["nlg5_e_es_crc"].push(pack->nlg5_err(i).nlg5_e_es_crc());
		(*net_enums)["NLG5_ERR"]["nlg5_e_ep_crc"].push(pack->nlg5_err(i).nlg5_e_ep_crc());
		(*net_enums)["NLG5_ERR"]["nlg5_e_wdt"].push(pack->nlg5_err(i).nlg5_e_wdt());
		(*net_enums)["NLG5_ERR"]["nlg5_e_init"].push(pack->nlg5_err(i).nlg5_e_init());
		(*net_enums)["NLG5_ERR"]["nlg5_e_c_to"].push(pack->nlg5_err(i).nlg5_e_c_to());
		(*net_enums)["NLG5_ERR"]["nlg5_e_c_off"].push(pack->nlg5_err(i).nlg5_e_c_off());
		(*net_enums)["NLG5_ERR"]["nlg5_e_c_tx"].push(pack->nlg5_err(i).nlg5_e_c_tx());
		(*net_enums)["NLG5_ERR"]["nlg5_e_c_rx"].push(pack->nlg5_err(i).nlg5_e_c_rx());
		(*net_enums)["NLG5_ERR"]["nlg5_e_sdt_bt"].push(pack->nlg5_err(i).nlg5_e_sdt_bt());
		(*net_enums)["NLG5_ERR"]["nlg5_e_sdt_bv"].push(pack->nlg5_err(i).nlg5_e_sdt_bv());
		(*net_enums)["NLG5_ERR"]["nlg5_e_sdt_ah"].push(pack->nlg5_err(i).nlg5_e_sdt_ah());
		(*net_enums)["NLG5_ERR"]["nlg5_e_sdt_ct"].push(pack->nlg5_err(i).nlg5_e_sdt_ct());
		(*net_enums)["NLG5_ERR"]["nlg5_w_pl_mv"].push(pack->nlg5_err(i).nlg5_w_pl_mv());
		(*net_enums)["NLG5_ERR"]["nlg5_w_pl_bv"].push(pack->nlg5_err(i).nlg5_w_pl_bv());
		(*net_enums)["NLG5_ERR"]["nlg5_w_pl_it"].push(pack->nlg5_err(i).nlg5_w_pl_it());
		(*net_enums)["NLG5_ERR"]["nlg5_w_c_vor"].push(pack->nlg5_err(i).nlg5_w_c_vor());
		(*net_signals)["NLG5_ERR"]["nlg5_w_cm_na"].push(pack->nlg5_err(i).nlg5_w_cm_na());
		(*net_signals)["NLG5_ERR"]["nlg5_w_od"].push(pack->nlg5_err(i).nlg5_w_od());
		(*net_signals)["NLG5_ERR"]["nlg5_w_sc_m"].push(pack->nlg5_err(i).nlg5_w_sc_m());

    }

    for(int i = 0; i < pack->nlg5_temp_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->nlg5_temp(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->nlg5_temp(i)._inner_timestamp();
        (*net_signals)["NLG5_TEMP"]["_timestamp"].push(pack->nlg5_temp(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["NLG5_TEMP"]["nlg5_p_tmp"].push(pack->nlg5_temp(i).nlg5_p_tmp());
		(*net_signals)["NLG5_TEMP"]["nlg5_tmp_ext1"].push(pack->nlg5_temp(i).nlg5_tmp_ext1());
		(*net_signals)["NLG5_TEMP"]["nlg5_temp_ext2"].push(pack->nlg5_temp(i).nlg5_temp_ext2());
		(*net_signals)["NLG5_TEMP"]["nlg5_tmp_ext3"].push(pack->nlg5_temp(i).nlg5_tmp_ext3());

    }

    for(int i = 0; i < pack->nlg5_act_ii_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->nlg5_act_ii(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->nlg5_act_ii(i)._inner_timestamp();
        (*net_signals)["NLG5_ACT_II"]["_timestamp"].push(pack->nlg5_act_ii(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["NLG5_ACT_II"]["nlg5_s_mc_m_cp"].push(pack->nlg5_act_ii(i).nlg5_s_mc_m_cp());
		(*net_signals)["NLG5_ACT_II"]["nlg5_s_mc_m_pi"].push(pack->nlg5_act_ii(i).nlg5_s_mc_m_pi());
		(*net_signals)["NLG5_ACT_II"]["nlg5_abv"].push(pack->nlg5_act_ii(i).nlg5_abv());
		(*net_signals)["NLG5_ACT_II"]["nlg5_ahc_ext"].push(pack->nlg5_act_ii(i).nlg5_ahc_ext());
		(*net_signals)["NLG5_ACT_II"]["nlg5_oc_bo"].push(pack->nlg5_act_ii(i).nlg5_oc_bo());

    }

    for(int i = 0; i < pack->nlg5_act_i_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->nlg5_act_i(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->nlg5_act_i(i)._inner_timestamp();
        (*net_signals)["NLG5_ACT_I"]["_timestamp"].push(pack->nlg5_act_i(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["NLG5_ACT_I"]["nlg5_mc_act"].push(pack->nlg5_act_i(i).nlg5_mc_act());
		(*net_signals)["NLG5_ACT_I"]["nlg5_mv_act"].push(pack->nlg5_act_i(i).nlg5_mv_act());
		(*net_signals)["NLG5_ACT_I"]["nlg5_ov_act"].push(pack->nlg5_act_i(i).nlg5_ov_act());
		(*net_signals)["NLG5_ACT_I"]["nlg5_oc_act"].push(pack->nlg5_act_i(i).nlg5_oc_act());

    }

    for(int i = 0; i < pack->nlg5_st_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->nlg5_st(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->nlg5_st(i)._inner_timestamp();
        (*net_signals)["NLG5_ST"]["_timestamp"].push(pack->nlg5_st(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["NLG5_ST"]["nlg5_s_he"].push(pack->nlg5_st(i).nlg5_s_he());
		(*net_enums)["NLG5_ST"]["nlg5_s_err"].push(pack->nlg5_st(i).nlg5_s_err());
		(*net_enums)["NLG5_ST"]["nlg5_s_war"].push(pack->nlg5_st(i).nlg5_s_war());
		(*net_enums)["NLG5_ST"]["nlg5_s_fan"].push(pack->nlg5_st(i).nlg5_s_fan());
		(*net_enums)["NLG5_ST"]["nlg5_s_eum"].push(pack->nlg5_st(i).nlg5_s_eum());
		(*net_enums)["NLG5_ST"]["nlg5_s_um_i"].push(pack->nlg5_st(i).nlg5_s_um_i());
		(*net_enums)["NLG5_ST"]["nlg5_s_um_ii"].push(pack->nlg5_st(i).nlg5_s_um_ii());
		(*net_enums)["NLG5_ST"]["nlg5_s_cp_dt"].push(pack->nlg5_st(i).nlg5_s_cp_dt());
		(*net_enums)["NLG5_ST"]["nlg5_s_bpd_i"].push(pack->nlg5_st(i).nlg5_s_bpd_i());
		(*net_enums)["NLG5_ST"]["nlg5_s_bpd_ii"].push(pack->nlg5_st(i).nlg5_s_bpd_ii());
		(*net_enums)["NLG5_ST"]["nlg5_s_l_ov"].push(pack->nlg5_st(i).nlg5_s_l_ov());
		(*net_enums)["NLG5_ST"]["nlg5_s_l_oc"].push(pack->nlg5_st(i).nlg5_s_l_oc());
		(*net_enums)["NLG5_ST"]["nlg5_s_l_mc"].push(pack->nlg5_st(i).nlg5_s_l_mc());
		(*net_enums)["NLG5_ST"]["nlg5_s_l_pi"].push(pack->nlg5_st(i).nlg5_s_l_pi());
		(*net_enums)["NLG5_ST"]["nlg5_s_l_cp"].push(pack->nlg5_st(i).nlg5_s_l_cp());
		(*net_enums)["NLG5_ST"]["nlg5_s_l_pmax"].push(pack->nlg5_st(i).nlg5_s_l_pmax());
		(*net_enums)["NLG5_ST"]["nlg5_s_l_mc_max"].push(pack->nlg5_st(i).nlg5_s_l_mc_max());
		(*net_enums)["NLG5_ST"]["nlg5_s_l_oc_max"].push(pack->nlg5_st(i).nlg5_s_l_oc_max());
		(*net_enums)["NLG5_ST"]["nlg5_s_l_mo_max"].push(pack->nlg5_st(i).nlg5_s_l_mo_max());
		(*net_enums)["NLG5_ST"]["nlg5_s_l_t_cprim"].push(pack->nlg5_st(i).nlg5_s_l_t_cprim());
		(*net_enums)["NLG5_ST"]["nlg5_s_l_t_pow"].push(pack->nlg5_st(i).nlg5_s_l_t_pow());
		(*net_enums)["NLG5_ST"]["nlg5_s_l_t_dio"].push(pack->nlg5_st(i).nlg5_s_l_t_dio());
		(*net_enums)["NLG5_ST"]["nlg5_s_l_t_tr"].push(pack->nlg5_st(i).nlg5_s_l_t_tr());
		(*net_enums)["NLG5_ST"]["nlg5_s_l_t_batt"].push(pack->nlg5_st(i).nlg5_s_l_t_batt());
		(*net_enums)["NLG5_ST"]["nlg5_s_aac"].push(pack->nlg5_st(i).nlg5_s_aac());

    }

    for(int i = 0; i < pack->nlg5_ctl_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->nlg5_ctl(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->nlg5_ctl(i)._inner_timestamp();
        (*net_signals)["NLG5_CTL"]["_timestamp"].push(pack->nlg5_ctl(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["NLG5_CTL"]["nlg5_c_c_en"].push(pack->nlg5_ctl(i).nlg5_c_c_en());
		(*net_enums)["NLG5_CTL"]["nlg5_c_c_el"].push(pack->nlg5_ctl(i).nlg5_c_c_el());
		(*net_enums)["NLG5_CTL"]["nlg5_c_cp_v"].push(pack->nlg5_ctl(i).nlg5_c_cp_v());
		(*net_enums)["NLG5_CTL"]["nlg5_c_mr"].push(pack->nlg5_ctl(i).nlg5_c_mr());
		(*net_signals)["NLG5_CTL"]["nlg5_mc_max"].push(pack->nlg5_ctl(i).nlg5_mc_max());
		(*net_signals)["NLG5_CTL"]["nlg5_ov_com"].push(pack->nlg5_ctl(i).nlg5_ov_com());
		(*net_signals)["NLG5_CTL"]["nlg5_oc_com"].push(pack->nlg5_ctl(i).nlg5_oc_com());

    }

    for(int i = 0; i < pack->bms_hv_jmp_to_blt_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->bms_hv_jmp_to_blt(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->bms_hv_jmp_to_blt(i)._inner_timestamp();
        (*net_signals)["BMS_HV_JMP_TO_BLT"]["_timestamp"].push(pack->bms_hv_jmp_to_blt(i)._inner_timestamp());
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

    for(int i = 0; i < pack->bms_lv_jmp_to_blt_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->bms_lv_jmp_to_blt(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->bms_lv_jmp_to_blt(i)._inner_timestamp();
        (*net_signals)["BMS_LV_JMP_TO_BLT"]["_timestamp"].push(pack->bms_lv_jmp_to_blt(i)._inner_timestamp());
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

    for(int i = 0; i < pack->ecu_jmp_to_blt_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->ecu_jmp_to_blt(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->ecu_jmp_to_blt(i)._inner_timestamp();
        (*net_signals)["ECU_JMP_TO_BLT"]["_timestamp"].push(pack->ecu_jmp_to_blt(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->flash_ecu_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->flash_ecu_tx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->flash_ecu_tx(i)._inner_timestamp();
        (*net_signals)["FLASH_ECU_TX"]["_timestamp"].push(pack->flash_ecu_tx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->flash_ecu_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->flash_ecu_rx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->flash_ecu_rx(i)._inner_timestamp();
        (*net_signals)["FLASH_ECU_RX"]["_timestamp"].push(pack->flash_ecu_rx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->steering_jmp_to_blt_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->steering_jmp_to_blt(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->steering_jmp_to_blt(i)._inner_timestamp();
        (*net_signals)["STEERING_JMP_TO_BLT"]["_timestamp"].push(pack->steering_jmp_to_blt(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->flash_steering_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->flash_steering_tx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->flash_steering_tx(i)._inner_timestamp();
        (*net_signals)["FLASH_STEERING_TX"]["_timestamp"].push(pack->flash_steering_tx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->flash_steering_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->flash_steering_rx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->flash_steering_rx(i)._inner_timestamp();
        (*net_signals)["FLASH_STEERING_RX"]["_timestamp"].push(pack->flash_steering_rx(i)._inner_timestamp());
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

		(*net_enums)["HV_ERRORS"]["warnings_cell_low_voltage"].push(pack->hv_errors(i).warnings_cell_low_voltage());
		(*net_enums)["HV_ERRORS"]["warnings_cell_under_voltage"].push(pack->hv_errors(i).warnings_cell_under_voltage());
		(*net_enums)["HV_ERRORS"]["warnings_cell_over_voltage"].push(pack->hv_errors(i).warnings_cell_over_voltage());
		(*net_enums)["HV_ERRORS"]["warnings_cell_high_temperature"].push(pack->hv_errors(i).warnings_cell_high_temperature());
		(*net_enums)["HV_ERRORS"]["warnings_cell_over_temperature"].push(pack->hv_errors(i).warnings_cell_over_temperature());
		(*net_enums)["HV_ERRORS"]["warnings_over_current"].push(pack->hv_errors(i).warnings_over_current());
		(*net_enums)["HV_ERRORS"]["warnings_can"].push(pack->hv_errors(i).warnings_can());
		(*net_enums)["HV_ERRORS"]["warnings_int_voltage_mismatch"].push(pack->hv_errors(i).warnings_int_voltage_mismatch());
		(*net_enums)["HV_ERRORS"]["warnings_cellboard_comm"].push(pack->hv_errors(i).warnings_cellboard_comm());
		(*net_enums)["HV_ERRORS"]["warnings_cellboard_internal"].push(pack->hv_errors(i).warnings_cellboard_internal());
		(*net_enums)["HV_ERRORS"]["warnings_feedback"].push(pack->hv_errors(i).warnings_feedback());
		(*net_enums)["HV_ERRORS"]["warnings_feedback_circuitry"].push(pack->hv_errors(i).warnings_feedback_circuitry());
		(*net_enums)["HV_ERRORS"]["warnings_eeprom_comm"].push(pack->hv_errors(i).warnings_eeprom_comm());
		(*net_enums)["HV_ERRORS"]["warnings_eeprom_write"].push(pack->hv_errors(i).warnings_eeprom_write());
		(*net_enums)["HV_ERRORS"]["errors_cell_low_voltage"].push(pack->hv_errors(i).errors_cell_low_voltage());
		(*net_enums)["HV_ERRORS"]["errors_cell_under_voltage"].push(pack->hv_errors(i).errors_cell_under_voltage());
		(*net_enums)["HV_ERRORS"]["errors_cell_over_voltage"].push(pack->hv_errors(i).errors_cell_over_voltage());
		(*net_enums)["HV_ERRORS"]["errors_cell_high_temperature"].push(pack->hv_errors(i).errors_cell_high_temperature());
		(*net_enums)["HV_ERRORS"]["errors_cell_over_temperature"].push(pack->hv_errors(i).errors_cell_over_temperature());
		(*net_enums)["HV_ERRORS"]["errors_over_current"].push(pack->hv_errors(i).errors_over_current());
		(*net_enums)["HV_ERRORS"]["errors_can"].push(pack->hv_errors(i).errors_can());
		(*net_enums)["HV_ERRORS"]["errors_int_voltage_mismatch"].push(pack->hv_errors(i).errors_int_voltage_mismatch());
		(*net_enums)["HV_ERRORS"]["errors_cellboard_comm"].push(pack->hv_errors(i).errors_cellboard_comm());
		(*net_enums)["HV_ERRORS"]["errors_cellboard_internal"].push(pack->hv_errors(i).errors_cellboard_internal());
		(*net_enums)["HV_ERRORS"]["errors_feedback"].push(pack->hv_errors(i).errors_feedback());
		(*net_enums)["HV_ERRORS"]["errors_feedback_circuitry"].push(pack->hv_errors(i).errors_feedback_circuitry());
		(*net_enums)["HV_ERRORS"]["errors_eeprom_comm"].push(pack->hv_errors(i).errors_eeprom_comm());
		(*net_enums)["HV_ERRORS"]["errors_eeprom_write"].push(pack->hv_errors(i).errors_eeprom_write());

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

		(*net_enums)["HV_FEEDBACKS_STATUS"]["feedbacks_status_feedback_tsal_green_fault"].push(pack->hv_feedbacks_status(i).feedbacks_status_feedback_tsal_green_fault());
		(*net_enums)["HV_FEEDBACKS_STATUS"]["feedbacks_status_feedback_imd_latched"].push(pack->hv_feedbacks_status(i).feedbacks_status_feedback_imd_latched());
		(*net_enums)["HV_FEEDBACKS_STATUS"]["feedbacks_status_feedback_tsal_green_fault_latched"].push(pack->hv_feedbacks_status(i).feedbacks_status_feedback_tsal_green_fault_latched());
		(*net_enums)["HV_FEEDBACKS_STATUS"]["feedbacks_status_feedback_bms_latched"].push(pack->hv_feedbacks_status(i).feedbacks_status_feedback_bms_latched());
		(*net_enums)["HV_FEEDBACKS_STATUS"]["feedbacks_status_feedback_ext_latched"].push(pack->hv_feedbacks_status(i).feedbacks_status_feedback_ext_latched());
		(*net_enums)["HV_FEEDBACKS_STATUS"]["feedbacks_status_feedback_tsal_green"].push(pack->hv_feedbacks_status(i).feedbacks_status_feedback_tsal_green());
		(*net_enums)["HV_FEEDBACKS_STATUS"]["feedbacks_status_feedback_ts_over_60v_status"].push(pack->hv_feedbacks_status(i).feedbacks_status_feedback_ts_over_60v_status());
		(*net_enums)["HV_FEEDBACKS_STATUS"]["feedbacks_status_feedback_airn_status"].push(pack->hv_feedbacks_status(i).feedbacks_status_feedback_airn_status());
		(*net_enums)["HV_FEEDBACKS_STATUS"]["feedbacks_status_feedback_airp_status"].push(pack->hv_feedbacks_status(i).feedbacks_status_feedback_airp_status());
		(*net_enums)["HV_FEEDBACKS_STATUS"]["feedbacks_status_feedback_airp_gate"].push(pack->hv_feedbacks_status(i).feedbacks_status_feedback_airp_gate());
		(*net_enums)["HV_FEEDBACKS_STATUS"]["feedbacks_status_feedback_airn_gate"].push(pack->hv_feedbacks_status(i).feedbacks_status_feedback_airn_gate());
		(*net_enums)["HV_FEEDBACKS_STATUS"]["feedbacks_status_feedback_precharge_status"].push(pack->hv_feedbacks_status(i).feedbacks_status_feedback_precharge_status());
		(*net_enums)["HV_FEEDBACKS_STATUS"]["feedbacks_status_feedback_tsp_over_60v_status"].push(pack->hv_feedbacks_status(i).feedbacks_status_feedback_tsp_over_60v_status());
		(*net_enums)["HV_FEEDBACKS_STATUS"]["feedbacks_status_feedback_check_mux"].push(pack->hv_feedbacks_status(i).feedbacks_status_feedback_check_mux());
		(*net_enums)["HV_FEEDBACKS_STATUS"]["feedbacks_status_feedback_sd_in"].push(pack->hv_feedbacks_status(i).feedbacks_status_feedback_sd_in());
		(*net_enums)["HV_FEEDBACKS_STATUS"]["feedbacks_status_feedback_sd_out"].push(pack->hv_feedbacks_status(i).feedbacks_status_feedback_sd_out());
		(*net_enums)["HV_FEEDBACKS_STATUS"]["feedbacks_status_feedback_relay_sd"].push(pack->hv_feedbacks_status(i).feedbacks_status_feedback_relay_sd());
		(*net_enums)["HV_FEEDBACKS_STATUS"]["feedbacks_status_feedback_imd_fault"].push(pack->hv_feedbacks_status(i).feedbacks_status_feedback_imd_fault());
		(*net_enums)["HV_FEEDBACKS_STATUS"]["feedbacks_status_feedback_sd_end"].push(pack->hv_feedbacks_status(i).feedbacks_status_feedback_sd_end());
		(*net_enums)["HV_FEEDBACKS_STATUS"]["is_circuitry_error_feedback_tsal_green_fault"].push(pack->hv_feedbacks_status(i).is_circuitry_error_feedback_tsal_green_fault());
		(*net_enums)["HV_FEEDBACKS_STATUS"]["is_circuitry_error_feedback_imd_latched"].push(pack->hv_feedbacks_status(i).is_circuitry_error_feedback_imd_latched());
		(*net_enums)["HV_FEEDBACKS_STATUS"]["is_circuitry_error_feedback_tsal_green_fault_latched"].push(pack->hv_feedbacks_status(i).is_circuitry_error_feedback_tsal_green_fault_latched());
		(*net_enums)["HV_FEEDBACKS_STATUS"]["is_circuitry_error_feedback_bms_latched"].push(pack->hv_feedbacks_status(i).is_circuitry_error_feedback_bms_latched());
		(*net_enums)["HV_FEEDBACKS_STATUS"]["is_circuitry_error_feedback_ext_latched"].push(pack->hv_feedbacks_status(i).is_circuitry_error_feedback_ext_latched());
		(*net_enums)["HV_FEEDBACKS_STATUS"]["is_circuitry_error_feedback_tsal_green"].push(pack->hv_feedbacks_status(i).is_circuitry_error_feedback_tsal_green());
		(*net_enums)["HV_FEEDBACKS_STATUS"]["is_circuitry_error_feedback_ts_over_60v_status"].push(pack->hv_feedbacks_status(i).is_circuitry_error_feedback_ts_over_60v_status());
		(*net_enums)["HV_FEEDBACKS_STATUS"]["is_circuitry_error_feedback_airn_status"].push(pack->hv_feedbacks_status(i).is_circuitry_error_feedback_airn_status());
		(*net_enums)["HV_FEEDBACKS_STATUS"]["is_circuitry_error_feedback_airp_status"].push(pack->hv_feedbacks_status(i).is_circuitry_error_feedback_airp_status());
		(*net_enums)["HV_FEEDBACKS_STATUS"]["is_circuitry_error_feedback_airp_gate"].push(pack->hv_feedbacks_status(i).is_circuitry_error_feedback_airp_gate());
		(*net_enums)["HV_FEEDBACKS_STATUS"]["is_circuitry_error_feedback_airn_gate"].push(pack->hv_feedbacks_status(i).is_circuitry_error_feedback_airn_gate());
		(*net_enums)["HV_FEEDBACKS_STATUS"]["is_circuitry_error_feedback_precharge_status"].push(pack->hv_feedbacks_status(i).is_circuitry_error_feedback_precharge_status());
		(*net_enums)["HV_FEEDBACKS_STATUS"]["is_circuitry_error_feedback_tsp_over_60v_status"].push(pack->hv_feedbacks_status(i).is_circuitry_error_feedback_tsp_over_60v_status());
		(*net_enums)["HV_FEEDBACKS_STATUS"]["is_circuitry_error_feedback_check_mux"].push(pack->hv_feedbacks_status(i).is_circuitry_error_feedback_check_mux());
		(*net_enums)["HV_FEEDBACKS_STATUS"]["is_circuitry_error_feedback_sd_in"].push(pack->hv_feedbacks_status(i).is_circuitry_error_feedback_sd_in());
		(*net_enums)["HV_FEEDBACKS_STATUS"]["is_circuitry_error_feedback_sd_out"].push(pack->hv_feedbacks_status(i).is_circuitry_error_feedback_sd_out());
		(*net_enums)["HV_FEEDBACKS_STATUS"]["is_circuitry_error_feedback_relay_sd"].push(pack->hv_feedbacks_status(i).is_circuitry_error_feedback_relay_sd());
		(*net_enums)["HV_FEEDBACKS_STATUS"]["is_circuitry_error_feedback_imd_fault"].push(pack->hv_feedbacks_status(i).is_circuitry_error_feedback_imd_fault());
		(*net_enums)["HV_FEEDBACKS_STATUS"]["is_circuitry_error_feedback_sd_end"].push(pack->hv_feedbacks_status(i).is_circuitry_error_feedback_sd_end());

    }

    for(int i = 0; i < pack->hv_imd_status_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_imd_status(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_imd_status(i)._inner_timestamp();
        (*net_signals)["HV_IMD_STATUS"]["_timestamp"].push(pack->hv_imd_status(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["HV_IMD_STATUS"]["imd_fault"].push(pack->hv_imd_status(i).imd_fault());
		(*net_enums)["HV_IMD_STATUS"]["imd_status"].push(pack->hv_imd_status(i).imd_status());
		primary_hv_imd_status_imd_status_enum_to_string((primary_hv_imd_status_imd_status)pack->hv_imd_status(i).imd_status(), buffer);
		(*net_strings)["HV_IMD_STATUS"]["imd_status"].push(buffer);
		(*net_signals)["HV_IMD_STATUS"]["imd_info"].push(pack->hv_imd_status(i).imd_info());

    }

    for(int i = 0; i < pack->ts_status_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->ts_status(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->ts_status(i)._inner_timestamp();
        (*net_signals)["TS_STATUS"]["_timestamp"].push(pack->ts_status(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["TS_STATUS"]["ts_status"].push(pack->ts_status(i).ts_status());
		primary_ts_status_ts_status_enum_to_string((primary_ts_status_ts_status)pack->ts_status(i).ts_status(), buffer);
		(*net_strings)["TS_STATUS"]["ts_status"].push(buffer);

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

		(*net_enums)["DAS_ERRORS"]["das_error_pedal_adc"].push(pack->das_errors(i).das_error_pedal_adc());
		(*net_enums)["DAS_ERRORS"]["das_error_pedal_implausibility"].push(pack->das_errors(i).das_error_pedal_implausibility());
		(*net_enums)["DAS_ERRORS"]["das_error_imu_tout"].push(pack->das_errors(i).das_error_imu_tout());
		(*net_enums)["DAS_ERRORS"]["das_error_irts_tout"].push(pack->das_errors(i).das_error_irts_tout());
		(*net_enums)["DAS_ERRORS"]["das_error_ts_tout"].push(pack->das_errors(i).das_error_ts_tout());
		(*net_enums)["DAS_ERRORS"]["das_error_invl_tout"].push(pack->das_errors(i).das_error_invl_tout());
		(*net_enums)["DAS_ERRORS"]["das_error_invr_tout"].push(pack->das_errors(i).das_error_invr_tout());
		(*net_enums)["DAS_ERRORS"]["das_error_steer_tout"].push(pack->das_errors(i).das_error_steer_tout());
		(*net_enums)["DAS_ERRORS"]["das_error_fsm"].push(pack->das_errors(i).das_error_fsm());

    }

    for(int i = 0; i < pack->lv_currents_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->lv_currents(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->lv_currents(i)._inner_timestamp();
        (*net_signals)["LV_CURRENTS"]["_timestamp"].push(pack->lv_currents(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["LV_CURRENTS"]["current_as_battery"].push(pack->lv_currents(i).current_as_battery());
		(*net_signals)["LV_CURRENTS"]["current_lv_battery"].push(pack->lv_currents(i).current_lv_battery());
		(*net_signals)["LV_CURRENTS"]["current_charger"].push(pack->lv_currents(i).current_charger());

    }

    for(int i = 0; i < pack->lv_cells_voltage_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->lv_cells_voltage(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->lv_cells_voltage(i)._inner_timestamp();
        (*net_signals)["LV_CELLS_VOLTAGE"]["_timestamp"].push(pack->lv_cells_voltage(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["LV_CELLS_VOLTAGE"]["start_index"].push(pack->lv_cells_voltage(i).start_index());
		(*net_signals)["LV_CELLS_VOLTAGE"]["voltage_0"].push(pack->lv_cells_voltage(i).voltage_0());
		(*net_signals)["LV_CELLS_VOLTAGE"]["voltage_1"].push(pack->lv_cells_voltage(i).voltage_1());
		(*net_signals)["LV_CELLS_VOLTAGE"]["voltage_2"].push(pack->lv_cells_voltage(i).voltage_2());

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

    for(int i = 0; i < pack->lv_cells_temp_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->lv_cells_temp(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->lv_cells_temp(i)._inner_timestamp();
        (*net_signals)["LV_CELLS_TEMP"]["_timestamp"].push(pack->lv_cells_temp(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["LV_CELLS_TEMP"]["start_index"].push(pack->lv_cells_temp(i).start_index());
		(*net_signals)["LV_CELLS_TEMP"]["temp0"].push(pack->lv_cells_temp(i).temp0());
		(*net_signals)["LV_CELLS_TEMP"]["temp1"].push(pack->lv_cells_temp(i).temp1());
		(*net_signals)["LV_CELLS_TEMP"]["temp2"].push(pack->lv_cells_temp(i).temp2());

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

		(*net_enums)["LV_ERRORS"]["warnings_cell_undervoltage"].push(pack->lv_errors(i).warnings_cell_undervoltage());
		(*net_enums)["LV_ERRORS"]["warnings_cell_overvoltage"].push(pack->lv_errors(i).warnings_cell_overvoltage());
		(*net_enums)["LV_ERRORS"]["warnings_battery_open_wire"].push(pack->lv_errors(i).warnings_battery_open_wire());
		(*net_enums)["LV_ERRORS"]["warnings_can"].push(pack->lv_errors(i).warnings_can());
		(*net_enums)["LV_ERRORS"]["warnings_spi"].push(pack->lv_errors(i).warnings_spi());
		(*net_enums)["LV_ERRORS"]["warnings_over_current"].push(pack->lv_errors(i).warnings_over_current());
		(*net_enums)["LV_ERRORS"]["warnings_cell_under_temperature"].push(pack->lv_errors(i).warnings_cell_under_temperature());
		(*net_enums)["LV_ERRORS"]["warnings_cell_over_temperature"].push(pack->lv_errors(i).warnings_cell_over_temperature());
		(*net_enums)["LV_ERRORS"]["warnings_relay"].push(pack->lv_errors(i).warnings_relay());
		(*net_enums)["LV_ERRORS"]["warnings_bms_monitor"].push(pack->lv_errors(i).warnings_bms_monitor());
		(*net_enums)["LV_ERRORS"]["warnings_voltages_not_ready"].push(pack->lv_errors(i).warnings_voltages_not_ready());
		(*net_enums)["LV_ERRORS"]["warnings_mcp23017"].push(pack->lv_errors(i).warnings_mcp23017());
		(*net_enums)["LV_ERRORS"]["warnings_radiator"].push(pack->lv_errors(i).warnings_radiator());
		(*net_enums)["LV_ERRORS"]["warnings_fan"].push(pack->lv_errors(i).warnings_fan());
		(*net_enums)["LV_ERRORS"]["warnings_pump"].push(pack->lv_errors(i).warnings_pump());
		(*net_enums)["LV_ERRORS"]["warnings_adc_init"].push(pack->lv_errors(i).warnings_adc_init());
		(*net_enums)["LV_ERRORS"]["warnings_mux"].push(pack->lv_errors(i).warnings_mux());
		(*net_enums)["LV_ERRORS"]["errors_cell_undervoltage"].push(pack->lv_errors(i).errors_cell_undervoltage());
		(*net_enums)["LV_ERRORS"]["errors_cell_overvoltage"].push(pack->lv_errors(i).errors_cell_overvoltage());
		(*net_enums)["LV_ERRORS"]["errors_battery_open_wire"].push(pack->lv_errors(i).errors_battery_open_wire());
		(*net_enums)["LV_ERRORS"]["errors_can"].push(pack->lv_errors(i).errors_can());
		(*net_enums)["LV_ERRORS"]["errors_spi"].push(pack->lv_errors(i).errors_spi());
		(*net_enums)["LV_ERRORS"]["errors_over_current"].push(pack->lv_errors(i).errors_over_current());
		(*net_enums)["LV_ERRORS"]["errors_cell_under_temperature"].push(pack->lv_errors(i).errors_cell_under_temperature());
		(*net_enums)["LV_ERRORS"]["errors_cell_over_temperature"].push(pack->lv_errors(i).errors_cell_over_temperature());
		(*net_enums)["LV_ERRORS"]["errors_relay"].push(pack->lv_errors(i).errors_relay());
		(*net_enums)["LV_ERRORS"]["errors_bms_monitor"].push(pack->lv_errors(i).errors_bms_monitor());
		(*net_enums)["LV_ERRORS"]["errors_voltages_not_ready"].push(pack->lv_errors(i).errors_voltages_not_ready());
		(*net_enums)["LV_ERRORS"]["errors_mcp23017"].push(pack->lv_errors(i).errors_mcp23017());
		(*net_enums)["LV_ERRORS"]["errors_radiator"].push(pack->lv_errors(i).errors_radiator());
		(*net_enums)["LV_ERRORS"]["errors_fan"].push(pack->lv_errors(i).errors_fan());
		(*net_enums)["LV_ERRORS"]["errors_pump"].push(pack->lv_errors(i).errors_pump());
		(*net_enums)["LV_ERRORS"]["errors_adc_init"].push(pack->lv_errors(i).errors_adc_init());
		(*net_enums)["LV_ERRORS"]["errors_mux"].push(pack->lv_errors(i).errors_mux());

    }

    for(int i = 0; i < pack->lv_health_signals_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->lv_health_signals(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->lv_health_signals(i)._inner_timestamp();
        (*net_signals)["LV_HEALTH_SIGNALS"]["_timestamp"].push(pack->lv_health_signals(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["LV_HEALTH_SIGNALS"]["health_signals_lvms_out"].push(pack->lv_health_signals(i).health_signals_lvms_out());
		(*net_enums)["LV_HEALTH_SIGNALS"]["health_signals_relay_out"].push(pack->lv_health_signals(i).health_signals_relay_out());
		(*net_enums)["LV_HEALTH_SIGNALS"]["health_signals_battery_voltage_out"].push(pack->lv_health_signals(i).health_signals_battery_voltage_out());
		(*net_enums)["LV_HEALTH_SIGNALS"]["health_signals_charger_current"].push(pack->lv_health_signals(i).health_signals_charger_current());
		(*net_enums)["LV_HEALTH_SIGNALS"]["health_signals_battery_current"].push(pack->lv_health_signals(i).health_signals_battery_current());
		(*net_enums)["LV_HEALTH_SIGNALS"]["health_signals_sign_battery_current"].push(pack->lv_health_signals(i).health_signals_sign_battery_current());

    }

    for(int i = 0; i < pack->lv_feedbacks_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->lv_feedbacks(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->lv_feedbacks(i)._inner_timestamp();
        (*net_signals)["LV_FEEDBACKS"]["_timestamp"].push(pack->lv_feedbacks(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["LV_FEEDBACKS"]["feedbacks_bspd_fb"].push(pack->lv_feedbacks(i).feedbacks_bspd_fb());
		(*net_enums)["LV_FEEDBACKS"]["feedbacks_imd_fb"].push(pack->lv_feedbacks(i).feedbacks_imd_fb());
		(*net_enums)["LV_FEEDBACKS"]["feedbacks_lvms_fb"].push(pack->lv_feedbacks(i).feedbacks_lvms_fb());
		(*net_enums)["LV_FEEDBACKS"]["feedbacks_res_fb"].push(pack->lv_feedbacks(i).feedbacks_res_fb());
		(*net_enums)["LV_FEEDBACKS"]["feedbacks_lv_encl"].push(pack->lv_feedbacks(i).feedbacks_lv_encl());
		(*net_enums)["LV_FEEDBACKS"]["feedbacks_hv_encl_1_fb"].push(pack->lv_feedbacks(i).feedbacks_hv_encl_1_fb());
		(*net_enums)["LV_FEEDBACKS"]["feedbacks_hv_encl_2_fb"].push(pack->lv_feedbacks(i).feedbacks_hv_encl_2_fb());
		(*net_enums)["LV_FEEDBACKS"]["feedbacks_back_plate_fb"].push(pack->lv_feedbacks(i).feedbacks_back_plate_fb());
		(*net_enums)["LV_FEEDBACKS"]["feedbacks_hvd_fb"].push(pack->lv_feedbacks(i).feedbacks_hvd_fb());
		(*net_enums)["LV_FEEDBACKS"]["feedbacks_ams_fb"].push(pack->lv_feedbacks(i).feedbacks_ams_fb());
		(*net_enums)["LV_FEEDBACKS"]["feedbacks_asms_fb"].push(pack->lv_feedbacks(i).feedbacks_asms_fb());
		(*net_enums)["LV_FEEDBACKS"]["feedbacks_interlock_fb"].push(pack->lv_feedbacks(i).feedbacks_interlock_fb());
		(*net_enums)["LV_FEEDBACKS"]["feedbacks_inverters_fb"].push(pack->lv_feedbacks(i).feedbacks_inverters_fb());
		(*net_enums)["LV_FEEDBACKS"]["feedbacks_pcbs_fb"].push(pack->lv_feedbacks(i).feedbacks_pcbs_fb());
		(*net_enums)["LV_FEEDBACKS"]["feedbacks_pumps_fb"].push(pack->lv_feedbacks(i).feedbacks_pumps_fb());
		(*net_enums)["LV_FEEDBACKS"]["feedbacks_shutdown_fb"].push(pack->lv_feedbacks(i).feedbacks_shutdown_fb());
		(*net_enums)["LV_FEEDBACKS"]["feedbacks_radiators_fb"].push(pack->lv_feedbacks(i).feedbacks_radiators_fb());
		(*net_enums)["LV_FEEDBACKS"]["feedbacks_fan_fb"].push(pack->lv_feedbacks(i).feedbacks_fan_fb());
		(*net_enums)["LV_FEEDBACKS"]["feedbacks_as_actuation_fb"].push(pack->lv_feedbacks(i).feedbacks_as_actuation_fb());
		(*net_signals)["LV_FEEDBACKS"]["sd_start"].push(pack->lv_feedbacks(i).sd_start());
		(*net_signals)["LV_FEEDBACKS"]["sd_end"].push(pack->lv_feedbacks(i).sd_end());

    }

    for(int i = 0; i < pack->shutdown_status_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->shutdown_status(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->shutdown_status(i)._inner_timestamp();
        (*net_signals)["SHUTDOWN_STATUS"]["_timestamp"].push(pack->shutdown_status(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["SHUTDOWN_STATUS"]["input"].push(pack->shutdown_status(i).input());
		(*net_enums)["SHUTDOWN_STATUS"]["output"].push(pack->shutdown_status(i).output());

    }

    for(int i = 0; i < pack->lv_can_flash_req_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->lv_can_flash_req(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->lv_can_flash_req(i)._inner_timestamp();
        (*net_signals)["LV_CAN_FLASH_REQ"]["_timestamp"].push(pack->lv_can_flash_req(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->lv_can_flash_ack_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->lv_can_flash_ack(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->lv_can_flash_ack(i)._inner_timestamp();
        (*net_signals)["LV_CAN_FLASH_ACK"]["_timestamp"].push(pack->lv_can_flash_ack(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["LV_CAN_FLASH_ACK"]["response"].push(pack->lv_can_flash_ack(i).response());
		primary_lv_can_flash_ack_response_enum_to_string((primary_lv_can_flash_ack_response)pack->lv_can_flash_ack(i).response(), buffer);
		(*net_strings)["LV_CAN_FLASH_ACK"]["response"].push(buffer);

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

    for(int i = 0; i < pack->handcart_status_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->handcart_status(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->handcart_status(i)._inner_timestamp();
        (*net_signals)["HANDCART_STATUS"]["_timestamp"].push(pack->handcart_status(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["HANDCART_STATUS"]["connected"].push(pack->handcart_status(i).connected());

    }

    for(int i = 0; i < pack->handcart_settings_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->handcart_settings(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->handcart_settings(i)._inner_timestamp();
        (*net_signals)["HANDCART_SETTINGS"]["_timestamp"].push(pack->handcart_settings(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["HANDCART_SETTINGS"]["target_voltage"].push(pack->handcart_settings(i).target_voltage());
		(*net_enums)["HANDCART_SETTINGS"]["fans_override"].push(pack->handcart_settings(i).fans_override());
		primary_handcart_settings_fans_override_enum_to_string((primary_handcart_settings_fans_override)pack->handcart_settings(i).fans_override(), buffer);
		(*net_strings)["HANDCART_SETTINGS"]["fans_override"].push(buffer);
		(*net_signals)["HANDCART_SETTINGS"]["fans_speed"].push(pack->handcart_settings(i).fans_speed());
		(*net_signals)["HANDCART_SETTINGS"]["acc_charge_current"].push(pack->handcart_settings(i).acc_charge_current());
		(*net_signals)["HANDCART_SETTINGS"]["grid_max_current"].push(pack->handcart_settings(i).grid_max_current());
		(*net_enums)["HANDCART_SETTINGS"]["status"].push(pack->handcart_settings(i).status());
		primary_handcart_settings_status_enum_to_string((primary_handcart_settings_status)pack->handcart_settings(i).status(), buffer);
		(*net_strings)["HANDCART_SETTINGS"]["status"].push(buffer);

    }

    for(int i = 0; i < pack->handcart_settings_set_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->handcart_settings_set(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->handcart_settings_set(i)._inner_timestamp();
        (*net_signals)["HANDCART_SETTINGS_SET"]["_timestamp"].push(pack->handcart_settings_set(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["HANDCART_SETTINGS_SET"]["target_voltage"].push(pack->handcart_settings_set(i).target_voltage());
		(*net_enums)["HANDCART_SETTINGS_SET"]["fans_override"].push(pack->handcart_settings_set(i).fans_override());
		primary_handcart_settings_set_fans_override_enum_to_string((primary_handcart_settings_set_fans_override)pack->handcart_settings_set(i).fans_override(), buffer);
		(*net_strings)["HANDCART_SETTINGS_SET"]["fans_override"].push(buffer);
		(*net_signals)["HANDCART_SETTINGS_SET"]["fans_speed"].push(pack->handcart_settings_set(i).fans_speed());
		(*net_signals)["HANDCART_SETTINGS_SET"]["acc_charge_current"].push(pack->handcart_settings_set(i).acc_charge_current());
		(*net_signals)["HANDCART_SETTINGS_SET"]["grid_max_current"].push(pack->handcart_settings_set(i).grid_max_current());
		(*net_enums)["HANDCART_SETTINGS_SET"]["status"].push(pack->handcart_settings_set(i).status());
		primary_handcart_settings_set_status_enum_to_string((primary_handcart_settings_set_status)pack->handcart_settings_set(i).status(), buffer);
		(*net_strings)["HANDCART_SETTINGS_SET"]["status"].push(buffer);

    }

    for(int i = 0; i < pack->set_ptt_status_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->set_ptt_status(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->set_ptt_status(i)._inner_timestamp();
        (*net_signals)["SET_PTT_STATUS"]["_timestamp"].push(pack->set_ptt_status(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["SET_PTT_STATUS"]["status"].push(pack->set_ptt_status(i).status());
		primary_set_ptt_status_status_enum_to_string((primary_set_ptt_status_status)pack->set_ptt_status(i).status(), buffer);
		(*net_strings)["SET_PTT_STATUS"]["status"].push(buffer);

    }

    for(int i = 0; i < pack->ptt_status_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->ptt_status(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->ptt_status(i)._inner_timestamp();
        (*net_signals)["PTT_STATUS"]["_timestamp"].push(pack->ptt_status(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["PTT_STATUS"]["status"].push(pack->ptt_status(i).status());
		primary_ptt_status_status_enum_to_string((primary_ptt_status_status)pack->ptt_status(i).status(), buffer);
		(*net_strings)["PTT_STATUS"]["status"].push(buffer);

    }

}

void primary_proto_interface_serialize_from_id(canlib_message_id id, primary::Pack* pack, device_t* device) {
    int index = primary_index_from_id(id);

    if (index == -1) return;

    switch(id) {
        
        case 1818: {
            primary_nlg5_diag_tx_t* msg = (primary_nlg5_diag_tx_t*)(device->message);
            primary::NLG5_DIAG_TX* proto_msg = pack->add_nlg5_diag_tx();
			proto_msg->set_lad_d_paramrp(msg->lad_d_paramrp);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1816: {
            primary_nlg5_diag_rx_t* msg = (primary_nlg5_diag_rx_t*)(device->message);
            primary::NLG5_DIAG_RX* proto_msg = pack->add_nlg5_diag_rx();
			proto_msg->set_lad_d_paramrq(msg->lad_d_paramrq);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1556: {
            primary_nlg5_err_t* msg = (primary_nlg5_err_t*)(device->message);
            primary::NLG5_ERR* proto_msg = pack->add_nlg5_err();
			proto_msg->set_nlg5_e_oov(msg->nlg5_e_oov);
			proto_msg->set_nlg5_e_mov_ii(msg->nlg5_e_mov_ii);
			proto_msg->set_nlg5_e_mov_i(msg->nlg5_e_mov_i);
			proto_msg->set_nlg5_e_sc(msg->nlg5_e_sc);
			proto_msg->set_nlg5_e_p_om(msg->nlg5_e_p_om);
			proto_msg->set_nlg5_e_p_mv(msg->nlg5_e_p_mv);
			proto_msg->set_nlg5_e_of(msg->nlg5_e_of);
			proto_msg->set_nlg5_e_mf(msg->nlg5_e_mf);
			proto_msg->set_nlg5_e_b_p(msg->nlg5_e_b_p);
			proto_msg->set_nlg5_e_t_c(msg->nlg5_e_t_c);
			proto_msg->set_nlg5_e_t_pow(msg->nlg5_e_t_pow);
			proto_msg->set_nlg5_e_t_dio(msg->nlg5_e_t_dio);
			proto_msg->set_nlg5_e_t_tr(msg->nlg5_e_t_tr);
			proto_msg->set_nlg5_e_t_ext1(msg->nlg5_e_t_ext1);
			proto_msg->set_nlg5_e_t_ext2(msg->nlg5_e_t_ext2);
			proto_msg->set_nlg5_e_t_ext3(msg->nlg5_e_t_ext3);
			proto_msg->set_nlg5_e_f_crc(msg->nlg5_e_f_crc);
			proto_msg->set_nlg5_e_nv_crc(msg->nlg5_e_nv_crc);
			proto_msg->set_nlg5_e_es_crc(msg->nlg5_e_es_crc);
			proto_msg->set_nlg5_e_ep_crc(msg->nlg5_e_ep_crc);
			proto_msg->set_nlg5_e_wdt(msg->nlg5_e_wdt);
			proto_msg->set_nlg5_e_init(msg->nlg5_e_init);
			proto_msg->set_nlg5_e_c_to(msg->nlg5_e_c_to);
			proto_msg->set_nlg5_e_c_off(msg->nlg5_e_c_off);
			proto_msg->set_nlg5_e_c_tx(msg->nlg5_e_c_tx);
			proto_msg->set_nlg5_e_c_rx(msg->nlg5_e_c_rx);
			proto_msg->set_nlg5_e_sdt_bt(msg->nlg5_e_sdt_bt);
			proto_msg->set_nlg5_e_sdt_bv(msg->nlg5_e_sdt_bv);
			proto_msg->set_nlg5_e_sdt_ah(msg->nlg5_e_sdt_ah);
			proto_msg->set_nlg5_e_sdt_ct(msg->nlg5_e_sdt_ct);
			proto_msg->set_nlg5_w_pl_mv(msg->nlg5_w_pl_mv);
			proto_msg->set_nlg5_w_pl_bv(msg->nlg5_w_pl_bv);
			proto_msg->set_nlg5_w_pl_it(msg->nlg5_w_pl_it);
			proto_msg->set_nlg5_w_c_vor(msg->nlg5_w_c_vor);
			proto_msg->set_nlg5_w_cm_na(msg->nlg5_w_cm_na);
			proto_msg->set_nlg5_w_od(msg->nlg5_w_od);
			proto_msg->set_nlg5_w_sc_m(msg->nlg5_w_sc_m);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1555: {
            primary_nlg5_temp_converted_t* msg = (primary_nlg5_temp_converted_t*)(device->message);
            primary::NLG5_TEMP* proto_msg = pack->add_nlg5_temp();
			proto_msg->set_nlg5_p_tmp(msg->nlg5_p_tmp);
			proto_msg->set_nlg5_tmp_ext1(msg->nlg5_tmp_ext1);
			proto_msg->set_nlg5_temp_ext2(msg->nlg5_temp_ext2);
			proto_msg->set_nlg5_tmp_ext3(msg->nlg5_tmp_ext3);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1554: {
            primary_nlg5_act_ii_converted_t* msg = (primary_nlg5_act_ii_converted_t*)(device->message);
            primary::NLG5_ACT_II* proto_msg = pack->add_nlg5_act_ii();
			proto_msg->set_nlg5_s_mc_m_cp(msg->nlg5_s_mc_m_cp);
			proto_msg->set_nlg5_s_mc_m_pi(msg->nlg5_s_mc_m_pi);
			proto_msg->set_nlg5_abv(msg->nlg5_abv);
			proto_msg->set_nlg5_ahc_ext(msg->nlg5_ahc_ext);
			proto_msg->set_nlg5_oc_bo(msg->nlg5_oc_bo);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1553: {
            primary_nlg5_act_i_converted_t* msg = (primary_nlg5_act_i_converted_t*)(device->message);
            primary::NLG5_ACT_I* proto_msg = pack->add_nlg5_act_i();
			proto_msg->set_nlg5_mc_act(msg->nlg5_mc_act);
			proto_msg->set_nlg5_mv_act(msg->nlg5_mv_act);
			proto_msg->set_nlg5_ov_act(msg->nlg5_ov_act);
			proto_msg->set_nlg5_oc_act(msg->nlg5_oc_act);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1552: {
            primary_nlg5_st_t* msg = (primary_nlg5_st_t*)(device->message);
            primary::NLG5_ST* proto_msg = pack->add_nlg5_st();
			proto_msg->set_nlg5_s_he(msg->nlg5_s_he);
			proto_msg->set_nlg5_s_err(msg->nlg5_s_err);
			proto_msg->set_nlg5_s_war(msg->nlg5_s_war);
			proto_msg->set_nlg5_s_fan(msg->nlg5_s_fan);
			proto_msg->set_nlg5_s_eum(msg->nlg5_s_eum);
			proto_msg->set_nlg5_s_um_i(msg->nlg5_s_um_i);
			proto_msg->set_nlg5_s_um_ii(msg->nlg5_s_um_ii);
			proto_msg->set_nlg5_s_cp_dt(msg->nlg5_s_cp_dt);
			proto_msg->set_nlg5_s_bpd_i(msg->nlg5_s_bpd_i);
			proto_msg->set_nlg5_s_bpd_ii(msg->nlg5_s_bpd_ii);
			proto_msg->set_nlg5_s_l_ov(msg->nlg5_s_l_ov);
			proto_msg->set_nlg5_s_l_oc(msg->nlg5_s_l_oc);
			proto_msg->set_nlg5_s_l_mc(msg->nlg5_s_l_mc);
			proto_msg->set_nlg5_s_l_pi(msg->nlg5_s_l_pi);
			proto_msg->set_nlg5_s_l_cp(msg->nlg5_s_l_cp);
			proto_msg->set_nlg5_s_l_pmax(msg->nlg5_s_l_pmax);
			proto_msg->set_nlg5_s_l_mc_max(msg->nlg5_s_l_mc_max);
			proto_msg->set_nlg5_s_l_oc_max(msg->nlg5_s_l_oc_max);
			proto_msg->set_nlg5_s_l_mo_max(msg->nlg5_s_l_mo_max);
			proto_msg->set_nlg5_s_l_t_cprim(msg->nlg5_s_l_t_cprim);
			proto_msg->set_nlg5_s_l_t_pow(msg->nlg5_s_l_t_pow);
			proto_msg->set_nlg5_s_l_t_dio(msg->nlg5_s_l_t_dio);
			proto_msg->set_nlg5_s_l_t_tr(msg->nlg5_s_l_t_tr);
			proto_msg->set_nlg5_s_l_t_batt(msg->nlg5_s_l_t_batt);
			proto_msg->set_nlg5_s_aac(msg->nlg5_s_aac);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1560: {
            primary_nlg5_ctl_converted_t* msg = (primary_nlg5_ctl_converted_t*)(device->message);
            primary::NLG5_CTL* proto_msg = pack->add_nlg5_ctl();
			proto_msg->set_nlg5_c_c_en(msg->nlg5_c_c_en);
			proto_msg->set_nlg5_c_c_el(msg->nlg5_c_c_el);
			proto_msg->set_nlg5_c_cp_v(msg->nlg5_c_cp_v);
			proto_msg->set_nlg5_c_mr(msg->nlg5_c_mr);
			proto_msg->set_nlg5_mc_max(msg->nlg5_mc_max);
			proto_msg->set_nlg5_ov_com(msg->nlg5_ov_com);
			proto_msg->set_nlg5_oc_com(msg->nlg5_oc_com);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 0: {
            primary_bms_hv_jmp_to_blt_t* msg = (primary_bms_hv_jmp_to_blt_t*)(device->message);
            primary::BMS_HV_JMP_TO_BLT* proto_msg = pack->add_bms_hv_jmp_to_blt();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1: {
            primary_flash_bms_hv_tx_t* msg = (primary_flash_bms_hv_tx_t*)(device->message);
            primary::FLASH_BMS_HV_TX* proto_msg = pack->add_flash_bms_hv_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 2: {
            primary_flash_bms_hv_rx_t* msg = (primary_flash_bms_hv_rx_t*)(device->message);
            primary::FLASH_BMS_HV_RX* proto_msg = pack->add_flash_bms_hv_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 3: {
            primary_hv_can_forward_t* msg = (primary_hv_can_forward_t*)(device->message);
            primary::HV_CAN_FORWARD* proto_msg = pack->add_hv_can_forward();
			proto_msg->set_can_forward_set((primary::primary_hv_can_forward_can_forward_set)msg->can_forward_set);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 4: {
            primary_flash_cellboard_0_tx_t* msg = (primary_flash_cellboard_0_tx_t*)(device->message);
            primary::FLASH_CELLBOARD_0_TX* proto_msg = pack->add_flash_cellboard_0_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 5: {
            primary_flash_cellboard_0_rx_t* msg = (primary_flash_cellboard_0_rx_t*)(device->message);
            primary::FLASH_CELLBOARD_0_RX* proto_msg = pack->add_flash_cellboard_0_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 6: {
            primary_flash_cellboard_1_tx_t* msg = (primary_flash_cellboard_1_tx_t*)(device->message);
            primary::FLASH_CELLBOARD_1_TX* proto_msg = pack->add_flash_cellboard_1_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 7: {
            primary_flash_cellboard_1_rx_t* msg = (primary_flash_cellboard_1_rx_t*)(device->message);
            primary::FLASH_CELLBOARD_1_RX* proto_msg = pack->add_flash_cellboard_1_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 8: {
            primary_flash_cellboard_2_tx_t* msg = (primary_flash_cellboard_2_tx_t*)(device->message);
            primary::FLASH_CELLBOARD_2_TX* proto_msg = pack->add_flash_cellboard_2_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 9: {
            primary_flash_cellboard_2_rx_t* msg = (primary_flash_cellboard_2_rx_t*)(device->message);
            primary::FLASH_CELLBOARD_2_RX* proto_msg = pack->add_flash_cellboard_2_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 10: {
            primary_flash_cellboard_3_tx_t* msg = (primary_flash_cellboard_3_tx_t*)(device->message);
            primary::FLASH_CELLBOARD_3_TX* proto_msg = pack->add_flash_cellboard_3_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 11: {
            primary_flash_cellboard_3_rx_t* msg = (primary_flash_cellboard_3_rx_t*)(device->message);
            primary::FLASH_CELLBOARD_3_RX* proto_msg = pack->add_flash_cellboard_3_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 12: {
            primary_flash_cellboard_4_tx_t* msg = (primary_flash_cellboard_4_tx_t*)(device->message);
            primary::FLASH_CELLBOARD_4_TX* proto_msg = pack->add_flash_cellboard_4_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 13: {
            primary_flash_cellboard_4_rx_t* msg = (primary_flash_cellboard_4_rx_t*)(device->message);
            primary::FLASH_CELLBOARD_4_RX* proto_msg = pack->add_flash_cellboard_4_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 14: {
            primary_flash_cellboard_5_tx_t* msg = (primary_flash_cellboard_5_tx_t*)(device->message);
            primary::FLASH_CELLBOARD_5_TX* proto_msg = pack->add_flash_cellboard_5_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 15: {
            primary_flash_cellboard_5_rx_t* msg = (primary_flash_cellboard_5_rx_t*)(device->message);
            primary::FLASH_CELLBOARD_5_RX* proto_msg = pack->add_flash_cellboard_5_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 16: {
            primary_bms_lv_jmp_to_blt_t* msg = (primary_bms_lv_jmp_to_blt_t*)(device->message);
            primary::BMS_LV_JMP_TO_BLT* proto_msg = pack->add_bms_lv_jmp_to_blt();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 17: {
            primary_flash_bms_lv_tx_t* msg = (primary_flash_bms_lv_tx_t*)(device->message);
            primary::FLASH_BMS_LV_TX* proto_msg = pack->add_flash_bms_lv_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 18: {
            primary_flash_bms_lv_rx_t* msg = (primary_flash_bms_lv_rx_t*)(device->message);
            primary::FLASH_BMS_LV_RX* proto_msg = pack->add_flash_bms_lv_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 19: {
            primary_ecu_jmp_to_blt_t* msg = (primary_ecu_jmp_to_blt_t*)(device->message);
            primary::ECU_JMP_TO_BLT* proto_msg = pack->add_ecu_jmp_to_blt();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 20: {
            primary_flash_ecu_tx_t* msg = (primary_flash_ecu_tx_t*)(device->message);
            primary::FLASH_ECU_TX* proto_msg = pack->add_flash_ecu_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 21: {
            primary_flash_ecu_rx_t* msg = (primary_flash_ecu_rx_t*)(device->message);
            primary::FLASH_ECU_RX* proto_msg = pack->add_flash_ecu_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 22: {
            primary_steering_jmp_to_blt_t* msg = (primary_steering_jmp_to_blt_t*)(device->message);
            primary::STEERING_JMP_TO_BLT* proto_msg = pack->add_steering_jmp_to_blt();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 23: {
            primary_flash_steering_tx_t* msg = (primary_flash_steering_tx_t*)(device->message);
            primary::FLASH_STEERING_TX* proto_msg = pack->add_flash_steering_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 24: {
            primary_flash_steering_rx_t* msg = (primary_flash_steering_rx_t*)(device->message);
            primary::FLASH_STEERING_RX* proto_msg = pack->add_flash_steering_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1032: {
            primary_steer_version_t* msg = (primary_steer_version_t*)(device->message);
            primary::STEER_VERSION* proto_msg = pack->add_steer_version();
			proto_msg->set_component_version(msg->component_version);
			proto_msg->set_canlib_build_time(msg->canlib_build_time);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1064: {
            primary_das_version_t* msg = (primary_das_version_t*)(device->message);
            primary::DAS_VERSION* proto_msg = pack->add_das_version();
			proto_msg->set_component_version(msg->component_version);
			proto_msg->set_canlib_build_time(msg->canlib_build_time);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1096: {
            primary_hv_version_t* msg = (primary_hv_version_t*)(device->message);
            primary::HV_VERSION* proto_msg = pack->add_hv_version();
			proto_msg->set_component_version(msg->component_version);
			proto_msg->set_canlib_build_time(msg->canlib_build_time);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1128: {
            primary_lv_version_t* msg = (primary_lv_version_t*)(device->message);
            primary::LV_VERSION* proto_msg = pack->add_lv_version();
			proto_msg->set_component_version(msg->component_version);
			proto_msg->set_canlib_build_time(msg->canlib_build_time);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1160: {
            primary_tlm_version_t* msg = (primary_tlm_version_t*)(device->message);
            primary::TLM_VERSION* proto_msg = pack->add_tlm_version();
			proto_msg->set_component_version(msg->component_version);
			proto_msg->set_canlib_build_time(msg->canlib_build_time);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 264: {
            primary_timestamp_t* msg = (primary_timestamp_t*)(device->message);
            primary::TIMESTAMP* proto_msg = pack->add_timestamp();
			proto_msg->set_timestamp(msg->timestamp);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 296: {
            primary_ambient_temperature_t* msg = (primary_ambient_temperature_t*)(device->message);
            primary::AMBIENT_TEMPERATURE* proto_msg = pack->add_ambient_temperature();
			proto_msg->set_temp(msg->temp);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1072: {
            primary_data_logger_t* msg = (primary_data_logger_t*)(device->message);
            primary::DATA_LOGGER* proto_msg = pack->add_data_logger();
			proto_msg->set_placeholder1(msg->placeholder1);
			proto_msg->set_placeholder2(msg->placeholder2);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 265: {
            primary_set_tlm_status_t* msg = (primary_set_tlm_status_t*)(device->message);
            primary::SET_TLM_STATUS* proto_msg = pack->add_set_tlm_status();
			proto_msg->set_tlm_status((primary::primary_set_tlm_status_tlm_status)msg->tlm_status);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 261: {
            primary_tlm_status_t* msg = (primary_tlm_status_t*)(device->message);
            primary::TLM_STATUS* proto_msg = pack->add_tlm_status();
			proto_msg->set_tlm_status((primary::primary_tlm_status_tlm_status)msg->tlm_status);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1801: {
            primary_steer_system_status_t* msg = (primary_steer_system_status_t*)(device->message);
            primary::STEER_SYSTEM_STATUS* proto_msg = pack->add_steer_system_status();
			proto_msg->set_soc_temp(msg->soc_temp);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 771: {
            primary_hv_voltage_converted_t* msg = (primary_hv_voltage_converted_t*)(device->message);
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

        case 803: {
            primary_hv_current_converted_t* msg = (primary_hv_current_converted_t*)(device->message);
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

        case 835: {
            primary_hv_temp_converted_t* msg = (primary_hv_temp_converted_t*)(device->message);
            primary::HV_TEMP* proto_msg = pack->add_hv_temp();
			proto_msg->set_average_temp(msg->average_temp);
			proto_msg->set_max_temp(msg->max_temp);
			proto_msg->set_min_temp(msg->min_temp);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 35: {
            primary_hv_errors_t* msg = (primary_hv_errors_t*)(device->message);
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

        case 38: {
            primary_hv_fans_override_converted_t* msg = (primary_hv_fans_override_converted_t*)(device->message);
            primary::HV_FANS_OVERRIDE* proto_msg = pack->add_hv_fans_override();
			proto_msg->set_fans_override((primary::primary_hv_fans_override_fans_override)msg->fans_override);
			proto_msg->set_fans_speed(msg->fans_speed);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 34: {
            primary_hv_can_forward_status_t* msg = (primary_hv_can_forward_status_t*)(device->message);
            primary::HV_CAN_FORWARD_STATUS* proto_msg = pack->add_hv_can_forward_status();
			proto_msg->set_can_forward_status((primary::primary_hv_can_forward_status_can_forward_status)msg->can_forward_status);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 770: {
            primary_hv_fans_override_status_converted_t* msg = (primary_hv_fans_override_status_converted_t*)(device->message);
            primary::HV_FANS_OVERRIDE_STATUS* proto_msg = pack->add_hv_fans_override_status();
			proto_msg->set_fans_override((primary::primary_hv_fans_override_status_fans_override)msg->fans_override);
			proto_msg->set_fans_speed(msg->fans_speed);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 769: {
            primary_hv_feedbacks_status_t* msg = (primary_hv_feedbacks_status_t*)(device->message);
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

        case 801: {
            primary_hv_imd_status_t* msg = (primary_hv_imd_status_t*)(device->message);
            primary::HV_IMD_STATUS* proto_msg = pack->add_hv_imd_status();
			proto_msg->set_imd_fault(msg->imd_fault);
			proto_msg->set_imd_status((primary::primary_hv_imd_status_imd_status)msg->imd_status);
			proto_msg->set_imd_info(msg->imd_info);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 67: {
            primary_ts_status_t* msg = (primary_ts_status_t*)(device->message);
            primary::TS_STATUS* proto_msg = pack->add_ts_status();
			proto_msg->set_ts_status((primary::primary_ts_status_ts_status)msg->ts_status);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 70: {
            primary_set_ts_status_das_t* msg = (primary_set_ts_status_das_t*)(device->message);
            primary::SET_TS_STATUS_DAS* proto_msg = pack->add_set_ts_status_das();
			proto_msg->set_ts_status_set((primary::primary_set_ts_status_das_ts_status_set)msg->ts_status_set);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 102: {
            primary_set_ts_status_handcart_t* msg = (primary_set_ts_status_handcart_t*)(device->message);
            primary::SET_TS_STATUS_HANDCART* proto_msg = pack->add_set_ts_status_handcart();
			proto_msg->set_ts_status_set((primary::primary_set_ts_status_handcart_ts_status_set)msg->ts_status_set);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 256: {
            primary_steer_status_converted_t* msg = (primary_steer_status_converted_t*)(device->message);
            primary::STEER_STATUS* proto_msg = pack->add_steer_status();
			proto_msg->set_map_pw(msg->map_pw);
			proto_msg->set_map_sc(msg->map_sc);
			proto_msg->set_map_tv(msg->map_tv);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 768: {
            primary_set_car_status_t* msg = (primary_set_car_status_t*)(device->message);
            primary::SET_CAR_STATUS* proto_msg = pack->add_set_car_status();
			proto_msg->set_car_status_set((primary::primary_set_car_status_car_status_set)msg->car_status_set);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1024: {
            primary_set_pedals_range_t* msg = (primary_set_pedals_range_t*)(device->message);
            primary::SET_PEDALS_RANGE* proto_msg = pack->add_set_pedals_range();
			proto_msg->set_bound((primary::primary_set_pedals_range_bound)msg->bound);
			proto_msg->set_pedal((primary::primary_set_pedals_range_pedal)msg->pedal);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1056: {
            primary_set_steering_angle_range_t* msg = (primary_set_steering_angle_range_t*)(device->message);
            primary::SET_STEERING_ANGLE_RANGE* proto_msg = pack->add_set_steering_angle_range();
			proto_msg->set_bound((primary::primary_set_steering_angle_range_bound)msg->bound);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 517: {
            primary_car_status_t* msg = (primary_car_status_t*)(device->message);
            primary::CAR_STATUS* proto_msg = pack->add_car_status();
			proto_msg->set_inverter_l((primary::primary_car_status_inverter_l)msg->inverter_l);
			proto_msg->set_inverter_r((primary::primary_car_status_inverter_r)msg->inverter_r);
			proto_msg->set_car_status((primary::primary_car_status_car_status)msg->car_status);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 37: {
            primary_das_errors_t* msg = (primary_das_errors_t*)(device->message);
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

        case 833: {
            primary_lv_currents_converted_t* msg = (primary_lv_currents_converted_t*)(device->message);
            primary::LV_CURRENTS* proto_msg = pack->add_lv_currents();
			proto_msg->set_current_as_battery(msg->current_as_battery);
			proto_msg->set_current_lv_battery(msg->current_lv_battery);
			proto_msg->set_current_charger(msg->current_charger);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 865: {
            primary_lv_cells_voltage_converted_t* msg = (primary_lv_cells_voltage_converted_t*)(device->message);
            primary::LV_CELLS_VOLTAGE* proto_msg = pack->add_lv_cells_voltage();
			proto_msg->set_start_index(msg->start_index);
			proto_msg->set_voltage_0(msg->voltage_0);
			proto_msg->set_voltage_1(msg->voltage_1);
			proto_msg->set_voltage_2(msg->voltage_2);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 897: {
            primary_lv_total_voltage_converted_t* msg = (primary_lv_total_voltage_converted_t*)(device->message);
            primary::LV_TOTAL_VOLTAGE* proto_msg = pack->add_lv_total_voltage();
			proto_msg->set_total_voltage(msg->total_voltage);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 929: {
            primary_lv_cells_temp_converted_t* msg = (primary_lv_cells_temp_converted_t*)(device->message);
            primary::LV_CELLS_TEMP* proto_msg = pack->add_lv_cells_temp();
			proto_msg->set_start_index(msg->start_index);
			proto_msg->set_temp0(msg->temp0);
			proto_msg->set_temp1(msg->temp1);
			proto_msg->set_temp2(msg->temp2);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 961: {
            primary_cooling_status_converted_t* msg = (primary_cooling_status_converted_t*)(device->message);
            primary::COOLING_STATUS* proto_msg = pack->add_cooling_status();
			proto_msg->set_radiators_speed(msg->radiators_speed);
			proto_msg->set_pumps_speed(msg->pumps_speed);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 772: {
            primary_set_radiator_speed_converted_t* msg = (primary_set_radiator_speed_converted_t*)(device->message);
            primary::SET_RADIATOR_SPEED* proto_msg = pack->add_set_radiator_speed();
			proto_msg->set_radiators_speed(msg->radiators_speed);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 804: {
            primary_set_pumps_speed_converted_t* msg = (primary_set_pumps_speed_converted_t*)(device->message);
            primary::SET_PUMPS_SPEED* proto_msg = pack->add_set_pumps_speed();
			proto_msg->set_pumps_speed(msg->pumps_speed);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 260: {
            primary_set_inverter_connection_status_t* msg = (primary_set_inverter_connection_status_t*)(device->message);
            primary::SET_INVERTER_CONNECTION_STATUS* proto_msg = pack->add_set_inverter_connection_status();
			proto_msg->set_status((primary::primary_set_inverter_connection_status_status)msg->status);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 257: {
            primary_inverter_connection_status_t* msg = (primary_inverter_connection_status_t*)(device->message);
            primary::INVERTER_CONNECTION_STATUS* proto_msg = pack->add_inverter_connection_status();
			proto_msg->set_status((primary::primary_inverter_connection_status_status)msg->status);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 545: {
            primary_lv_errors_t* msg = (primary_lv_errors_t*)(device->message);
            primary::LV_ERRORS* proto_msg = pack->add_lv_errors();
			proto_msg->set_warnings_cell_undervoltage(msg->warnings_cell_undervoltage);
			proto_msg->set_warnings_cell_overvoltage(msg->warnings_cell_overvoltage);
			proto_msg->set_warnings_battery_open_wire(msg->warnings_battery_open_wire);
			proto_msg->set_warnings_can(msg->warnings_can);
			proto_msg->set_warnings_spi(msg->warnings_spi);
			proto_msg->set_warnings_over_current(msg->warnings_over_current);
			proto_msg->set_warnings_cell_under_temperature(msg->warnings_cell_under_temperature);
			proto_msg->set_warnings_cell_over_temperature(msg->warnings_cell_over_temperature);
			proto_msg->set_warnings_relay(msg->warnings_relay);
			proto_msg->set_warnings_bms_monitor(msg->warnings_bms_monitor);
			proto_msg->set_warnings_voltages_not_ready(msg->warnings_voltages_not_ready);
			proto_msg->set_warnings_mcp23017(msg->warnings_mcp23017);
			proto_msg->set_warnings_radiator(msg->warnings_radiator);
			proto_msg->set_warnings_fan(msg->warnings_fan);
			proto_msg->set_warnings_pump(msg->warnings_pump);
			proto_msg->set_warnings_adc_init(msg->warnings_adc_init);
			proto_msg->set_warnings_mux(msg->warnings_mux);
			proto_msg->set_errors_cell_undervoltage(msg->errors_cell_undervoltage);
			proto_msg->set_errors_cell_overvoltage(msg->errors_cell_overvoltage);
			proto_msg->set_errors_battery_open_wire(msg->errors_battery_open_wire);
			proto_msg->set_errors_can(msg->errors_can);
			proto_msg->set_errors_spi(msg->errors_spi);
			proto_msg->set_errors_over_current(msg->errors_over_current);
			proto_msg->set_errors_cell_under_temperature(msg->errors_cell_under_temperature);
			proto_msg->set_errors_cell_over_temperature(msg->errors_cell_over_temperature);
			proto_msg->set_errors_relay(msg->errors_relay);
			proto_msg->set_errors_bms_monitor(msg->errors_bms_monitor);
			proto_msg->set_errors_voltages_not_ready(msg->errors_voltages_not_ready);
			proto_msg->set_errors_mcp23017(msg->errors_mcp23017);
			proto_msg->set_errors_radiator(msg->errors_radiator);
			proto_msg->set_errors_fan(msg->errors_fan);
			proto_msg->set_errors_pump(msg->errors_pump);
			proto_msg->set_errors_adc_init(msg->errors_adc_init);
			proto_msg->set_errors_mux(msg->errors_mux);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 289: {
            primary_lv_health_signals_t* msg = (primary_lv_health_signals_t*)(device->message);
            primary::LV_HEALTH_SIGNALS* proto_msg = pack->add_lv_health_signals();
			proto_msg->set_health_signals_lvms_out(msg->health_signals_lvms_out);
			proto_msg->set_health_signals_relay_out(msg->health_signals_relay_out);
			proto_msg->set_health_signals_battery_voltage_out(msg->health_signals_battery_voltage_out);
			proto_msg->set_health_signals_charger_current(msg->health_signals_charger_current);
			proto_msg->set_health_signals_battery_current(msg->health_signals_battery_current);
			proto_msg->set_health_signals_sign_battery_current(msg->health_signals_sign_battery_current);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 321: {
            primary_lv_feedbacks_converted_t* msg = (primary_lv_feedbacks_converted_t*)(device->message);
            primary::LV_FEEDBACKS* proto_msg = pack->add_lv_feedbacks();
			proto_msg->set_feedbacks_bspd_fb(msg->feedbacks_bspd_fb);
			proto_msg->set_feedbacks_imd_fb(msg->feedbacks_imd_fb);
			proto_msg->set_feedbacks_lvms_fb(msg->feedbacks_lvms_fb);
			proto_msg->set_feedbacks_res_fb(msg->feedbacks_res_fb);
			proto_msg->set_feedbacks_lv_encl(msg->feedbacks_lv_encl);
			proto_msg->set_feedbacks_hv_encl_1_fb(msg->feedbacks_hv_encl_1_fb);
			proto_msg->set_feedbacks_hv_encl_2_fb(msg->feedbacks_hv_encl_2_fb);
			proto_msg->set_feedbacks_back_plate_fb(msg->feedbacks_back_plate_fb);
			proto_msg->set_feedbacks_hvd_fb(msg->feedbacks_hvd_fb);
			proto_msg->set_feedbacks_ams_fb(msg->feedbacks_ams_fb);
			proto_msg->set_feedbacks_asms_fb(msg->feedbacks_asms_fb);
			proto_msg->set_feedbacks_interlock_fb(msg->feedbacks_interlock_fb);
			proto_msg->set_feedbacks_inverters_fb(msg->feedbacks_inverters_fb);
			proto_msg->set_feedbacks_pcbs_fb(msg->feedbacks_pcbs_fb);
			proto_msg->set_feedbacks_pumps_fb(msg->feedbacks_pumps_fb);
			proto_msg->set_feedbacks_shutdown_fb(msg->feedbacks_shutdown_fb);
			proto_msg->set_feedbacks_radiators_fb(msg->feedbacks_radiators_fb);
			proto_msg->set_feedbacks_fan_fb(msg->feedbacks_fan_fb);
			proto_msg->set_feedbacks_as_actuation_fb(msg->feedbacks_as_actuation_fb);
			proto_msg->set_sd_start(msg->sd_start);
			proto_msg->set_sd_end(msg->sd_end);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 353: {
            primary_shutdown_status_t* msg = (primary_shutdown_status_t*)(device->message);
            primary::SHUTDOWN_STATUS* proto_msg = pack->add_shutdown_status();
			proto_msg->set_input(msg->input);
			proto_msg->set_output(msg->output);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1833: {
            primary_lv_can_flash_req_t* msg = (primary_lv_can_flash_req_t*)(device->message);
            primary::LV_CAN_FLASH_REQ* proto_msg = pack->add_lv_can_flash_req();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1865: {
            primary_lv_can_flash_ack_t* msg = (primary_lv_can_flash_ack_t*)(device->message);
            primary::LV_CAN_FLASH_ACK* proto_msg = pack->add_lv_can_flash_ack();
			proto_msg->set_response((primary::primary_lv_can_flash_ack_response)msg->response);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 41: {
            primary_marker_t* msg = (primary_marker_t*)(device->message);
            primary::MARKER* proto_msg = pack->add_marker();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 546: {
            primary_hv_cells_voltage_converted_t* msg = (primary_hv_cells_voltage_converted_t*)(device->message);
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

        case 578: {
            primary_hv_cells_temp_converted_t* msg = (primary_hv_cells_temp_converted_t*)(device->message);
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

        case 610: {
            primary_hv_cell_balancing_status_t* msg = (primary_hv_cell_balancing_status_t*)(device->message);
            primary::HV_CELL_BALANCING_STATUS* proto_msg = pack->add_hv_cell_balancing_status();
			proto_msg->set_balancing_status((primary::primary_hv_cell_balancing_status_balancing_status)msg->balancing_status);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 518: {
            primary_set_cell_balancing_status_t* msg = (primary_set_cell_balancing_status_t*)(device->message);
            primary::SET_CELL_BALANCING_STATUS* proto_msg = pack->add_set_cell_balancing_status();
			proto_msg->set_set_balancing_status((primary::primary_set_cell_balancing_status_set_balancing_status)msg->set_balancing_status);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 549: {
            primary_speed_converted_t* msg = (primary_speed_converted_t*)(device->message);
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
            primary_inv_l_request_t* msg = (primary_inv_l_request_t*)(device->message);
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
            primary_inv_r_request_t* msg = (primary_inv_r_request_t*)(device->message);
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
            primary_inv_l_response_t* msg = (primary_inv_l_response_t*)(device->message);
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
            primary_inv_r_response_t* msg = (primary_inv_r_response_t*)(device->message);
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

        case 293: {
            primary_control_output_converted_t* msg = (primary_control_output_converted_t*)(device->message);
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
            primary_lc_reset_t* msg = (primary_lc_reset_t*)(device->message);
            primary::LC_RESET* proto_msg = pack->add_lc_reset();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 774: {
            primary_handcart_status_t* msg = (primary_handcart_status_t*)(device->message);
            primary::HANDCART_STATUS* proto_msg = pack->add_handcart_status();
			proto_msg->set_connected(msg->connected);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 806: {
            primary_handcart_settings_converted_t* msg = (primary_handcart_settings_converted_t*)(device->message);
            primary::HANDCART_SETTINGS* proto_msg = pack->add_handcart_settings();
			proto_msg->set_target_voltage(msg->target_voltage);
			proto_msg->set_fans_override((primary::primary_handcart_settings_fans_override)msg->fans_override);
			proto_msg->set_fans_speed(msg->fans_speed);
			proto_msg->set_acc_charge_current(msg->acc_charge_current);
			proto_msg->set_grid_max_current(msg->grid_max_current);
			proto_msg->set_status((primary::primary_handcart_settings_status)msg->status);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 838: {
            primary_handcart_settings_set_converted_t* msg = (primary_handcart_settings_set_converted_t*)(device->message);
            primary::HANDCART_SETTINGS_SET* proto_msg = pack->add_handcart_settings_set();
			proto_msg->set_target_voltage(msg->target_voltage);
			proto_msg->set_fans_override((primary::primary_handcart_settings_set_fans_override)msg->fans_override);
			proto_msg->set_fans_speed(msg->fans_speed);
			proto_msg->set_acc_charge_current(msg->acc_charge_current);
			proto_msg->set_grid_max_current(msg->grid_max_current);
			proto_msg->set_status((primary::primary_handcart_settings_set_status)msg->status);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 577: {
            primary_set_ptt_status_t* msg = (primary_set_ptt_status_t*)(device->message);
            primary::SET_PTT_STATUS* proto_msg = pack->add_set_ptt_status();
			proto_msg->set_status((primary::primary_set_ptt_status_status)msg->status);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 609: {
            primary_ptt_status_t* msg = (primary_ptt_status_t*)(device->message);
            primary::PTT_STATUS* proto_msg = pack->add_ptt_status();
			proto_msg->set_status((primary::primary_ptt_status_status)msg->status);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

    }
}



#endif // primary_PROTO_INTERAFCE_IMPLEMENTATION

#endif // primary_PROTO_INTERFACE_H
