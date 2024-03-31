
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

    for(int i = 0; i < pack->hv_jmp_to_blt_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_jmp_to_blt(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_jmp_to_blt(i)._inner_timestamp();
        (*net_signals)["HV_JMP_TO_BLT"]["_timestamp"].push(pack->hv_jmp_to_blt(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->hv_flash_mainboard_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_flash_mainboard_tx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_flash_mainboard_tx(i)._inner_timestamp();
        (*net_signals)["HV_FLASH_MAINBOARD_TX"]["_timestamp"].push(pack->hv_flash_mainboard_tx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->hv_flash_mainboard_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_flash_mainboard_rx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_flash_mainboard_rx(i)._inner_timestamp();
        (*net_signals)["HV_FLASH_MAINBOARD_RX"]["_timestamp"].push(pack->hv_flash_mainboard_rx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->hv_flash_cellboard_0_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_flash_cellboard_0_tx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_flash_cellboard_0_tx(i)._inner_timestamp();
        (*net_signals)["HV_FLASH_CELLBOARD_0_TX"]["_timestamp"].push(pack->hv_flash_cellboard_0_tx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->hv_flash_cellboard_0_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_flash_cellboard_0_rx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_flash_cellboard_0_rx(i)._inner_timestamp();
        (*net_signals)["HV_FLASH_CELLBOARD_0_RX"]["_timestamp"].push(pack->hv_flash_cellboard_0_rx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->hv_flash_cellboard_1_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_flash_cellboard_1_tx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_flash_cellboard_1_tx(i)._inner_timestamp();
        (*net_signals)["HV_FLASH_CELLBOARD_1_TX"]["_timestamp"].push(pack->hv_flash_cellboard_1_tx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->hv_flash_cellboard_1_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_flash_cellboard_1_rx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_flash_cellboard_1_rx(i)._inner_timestamp();
        (*net_signals)["HV_FLASH_CELLBOARD_1_RX"]["_timestamp"].push(pack->hv_flash_cellboard_1_rx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->hv_flash_cellboard_2_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_flash_cellboard_2_tx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_flash_cellboard_2_tx(i)._inner_timestamp();
        (*net_signals)["HV_FLASH_CELLBOARD_2_TX"]["_timestamp"].push(pack->hv_flash_cellboard_2_tx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->hv_flash_cellboard_2_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_flash_cellboard_2_rx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_flash_cellboard_2_rx(i)._inner_timestamp();
        (*net_signals)["HV_FLASH_CELLBOARD_2_RX"]["_timestamp"].push(pack->hv_flash_cellboard_2_rx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->hv_flash_cellboard_3_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_flash_cellboard_3_tx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_flash_cellboard_3_tx(i)._inner_timestamp();
        (*net_signals)["HV_FLASH_CELLBOARD_3_TX"]["_timestamp"].push(pack->hv_flash_cellboard_3_tx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->hv_flash_cellboard_3_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_flash_cellboard_3_rx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_flash_cellboard_3_rx(i)._inner_timestamp();
        (*net_signals)["HV_FLASH_CELLBOARD_3_RX"]["_timestamp"].push(pack->hv_flash_cellboard_3_rx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->hv_flash_cellboard_4_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_flash_cellboard_4_tx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_flash_cellboard_4_tx(i)._inner_timestamp();
        (*net_signals)["HV_FLASH_CELLBOARD_4_TX"]["_timestamp"].push(pack->hv_flash_cellboard_4_tx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->hv_flash_cellboard_4_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_flash_cellboard_4_rx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_flash_cellboard_4_rx(i)._inner_timestamp();
        (*net_signals)["HV_FLASH_CELLBOARD_4_RX"]["_timestamp"].push(pack->hv_flash_cellboard_4_rx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->hv_flash_cellboard_5_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_flash_cellboard_5_tx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_flash_cellboard_5_tx(i)._inner_timestamp();
        (*net_signals)["HV_FLASH_CELLBOARD_5_TX"]["_timestamp"].push(pack->hv_flash_cellboard_5_tx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->hv_flash_cellboard_5_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_flash_cellboard_5_rx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_flash_cellboard_5_rx(i)._inner_timestamp();
        (*net_signals)["HV_FLASH_CELLBOARD_5_RX"]["_timestamp"].push(pack->hv_flash_cellboard_5_rx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->lv_jmp_to_blt_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->lv_jmp_to_blt(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->lv_jmp_to_blt(i)._inner_timestamp();
        (*net_signals)["LV_JMP_TO_BLT"]["_timestamp"].push(pack->lv_jmp_to_blt(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->lv_flash_bms_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->lv_flash_bms_tx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->lv_flash_bms_tx(i)._inner_timestamp();
        (*net_signals)["LV_FLASH_BMS_TX"]["_timestamp"].push(pack->lv_flash_bms_tx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->lv_flash_bms_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->lv_flash_bms_rx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->lv_flash_bms_rx(i)._inner_timestamp();
        (*net_signals)["LV_FLASH_BMS_RX"]["_timestamp"].push(pack->lv_flash_bms_rx(i)._inner_timestamp());
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

    for(int i = 0; i < pack->ecu_flash_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->ecu_flash_tx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->ecu_flash_tx(i)._inner_timestamp();
        (*net_signals)["ECU_FLASH_TX"]["_timestamp"].push(pack->ecu_flash_tx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->ecu_flash_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->ecu_flash_rx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->ecu_flash_rx(i)._inner_timestamp();
        (*net_signals)["ECU_FLASH_RX"]["_timestamp"].push(pack->ecu_flash_rx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->steering_wheel_jmp_to_blt_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->steering_wheel_jmp_to_blt(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->steering_wheel_jmp_to_blt(i)._inner_timestamp();
        (*net_signals)["STEERING_WHEEL_JMP_TO_BLT"]["_timestamp"].push(pack->steering_wheel_jmp_to_blt(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->steering_wheel_flash_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->steering_wheel_flash_tx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->steering_wheel_flash_tx(i)._inner_timestamp();
        (*net_signals)["STEERING_WHEEL_FLASH_TX"]["_timestamp"].push(pack->steering_wheel_flash_tx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->steering_wheel_flash_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->steering_wheel_flash_rx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->steering_wheel_flash_rx(i)._inner_timestamp();
        (*net_signals)["STEERING_WHEEL_FLASH_RX"]["_timestamp"].push(pack->steering_wheel_flash_rx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->steering_wheel_version_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->steering_wheel_version(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->steering_wheel_version(i)._inner_timestamp();
        (*net_signals)["STEERING_WHEEL_VERSION"]["_timestamp"].push(pack->steering_wheel_version(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["STEERING_WHEEL_VERSION"]["component_build_time"].push(pack->steering_wheel_version(i).component_build_time());
		(*net_signals)["STEERING_WHEEL_VERSION"]["canlib_build_time"].push(pack->steering_wheel_version(i).canlib_build_time());

    }

    for(int i = 0; i < pack->ecu_version_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->ecu_version(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->ecu_version(i)._inner_timestamp();
        (*net_signals)["ECU_VERSION"]["_timestamp"].push(pack->ecu_version(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["ECU_VERSION"]["component_build_time"].push(pack->ecu_version(i).component_build_time());
		(*net_signals)["ECU_VERSION"]["canlib_build_time"].push(pack->ecu_version(i).canlib_build_time());

    }

    for(int i = 0; i < pack->lv_version_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->lv_version(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->lv_version(i)._inner_timestamp();
        (*net_signals)["LV_VERSION"]["_timestamp"].push(pack->lv_version(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["LV_VERSION"]["component_build_time"].push(pack->lv_version(i).component_build_time());
		(*net_signals)["LV_VERSION"]["canlib_build_time"].push(pack->lv_version(i).canlib_build_time());

    }

    for(int i = 0; i < pack->tlm_version_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->tlm_version(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->tlm_version(i)._inner_timestamp();
        (*net_signals)["TLM_VERSION"]["_timestamp"].push(pack->tlm_version(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["TLM_VERSION"]["component_build_time"].push(pack->tlm_version(i).component_build_time());
		(*net_signals)["TLM_VERSION"]["canlib_build_time"].push(pack->tlm_version(i).canlib_build_time());

    }

    for(int i = 0; i < pack->hv_mainboard_version_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_mainboard_version(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_mainboard_version(i)._inner_timestamp();
        (*net_signals)["HV_MAINBOARD_VERSION"]["_timestamp"].push(pack->hv_mainboard_version(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["HV_MAINBOARD_VERSION"]["component_build_time"].push(pack->hv_mainboard_version(i).component_build_time());
		(*net_signals)["HV_MAINBOARD_VERSION"]["canlib_build_time"].push(pack->hv_mainboard_version(i).canlib_build_time());

    }

    for(int i = 0; i < pack->hv_cellboard_0_version_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_cellboard_0_version(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_cellboard_0_version(i)._inner_timestamp();
        (*net_signals)["HV_CELLBOARD_0_VERSION"]["_timestamp"].push(pack->hv_cellboard_0_version(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["HV_CELLBOARD_0_VERSION"]["component_build_time"].push(pack->hv_cellboard_0_version(i).component_build_time());
		(*net_signals)["HV_CELLBOARD_0_VERSION"]["canlib_build_time"].push(pack->hv_cellboard_0_version(i).canlib_build_time());

    }

    for(int i = 0; i < pack->hv_cellboard_1_version_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_cellboard_1_version(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_cellboard_1_version(i)._inner_timestamp();
        (*net_signals)["HV_CELLBOARD_1_VERSION"]["_timestamp"].push(pack->hv_cellboard_1_version(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["HV_CELLBOARD_1_VERSION"]["component_build_time"].push(pack->hv_cellboard_1_version(i).component_build_time());
		(*net_signals)["HV_CELLBOARD_1_VERSION"]["canlib_build_time"].push(pack->hv_cellboard_1_version(i).canlib_build_time());

    }

    for(int i = 0; i < pack->hv_cellboard_2_version_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_cellboard_2_version(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_cellboard_2_version(i)._inner_timestamp();
        (*net_signals)["HV_CELLBOARD_2_VERSION"]["_timestamp"].push(pack->hv_cellboard_2_version(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["HV_CELLBOARD_2_VERSION"]["component_build_time"].push(pack->hv_cellboard_2_version(i).component_build_time());
		(*net_signals)["HV_CELLBOARD_2_VERSION"]["canlib_build_time"].push(pack->hv_cellboard_2_version(i).canlib_build_time());

    }

    for(int i = 0; i < pack->hv_cellboard_3_version_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_cellboard_3_version(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_cellboard_3_version(i)._inner_timestamp();
        (*net_signals)["HV_CELLBOARD_3_VERSION"]["_timestamp"].push(pack->hv_cellboard_3_version(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["HV_CELLBOARD_3_VERSION"]["component_build_time"].push(pack->hv_cellboard_3_version(i).component_build_time());
		(*net_signals)["HV_CELLBOARD_3_VERSION"]["canlib_build_time"].push(pack->hv_cellboard_3_version(i).canlib_build_time());

    }

    for(int i = 0; i < pack->hv_cellboard_4_version_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_cellboard_4_version(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_cellboard_4_version(i)._inner_timestamp();
        (*net_signals)["HV_CELLBOARD_4_VERSION"]["_timestamp"].push(pack->hv_cellboard_4_version(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["HV_CELLBOARD_4_VERSION"]["component_build_time"].push(pack->hv_cellboard_4_version(i).component_build_time());
		(*net_signals)["HV_CELLBOARD_4_VERSION"]["canlib_build_time"].push(pack->hv_cellboard_4_version(i).canlib_build_time());

    }

    for(int i = 0; i < pack->hv_cellboard_5_version_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_cellboard_5_version(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_cellboard_5_version(i)._inner_timestamp();
        (*net_signals)["HV_CELLBOARD_5_VERSION"]["_timestamp"].push(pack->hv_cellboard_5_version(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["HV_CELLBOARD_5_VERSION"]["component_build_time"].push(pack->hv_cellboard_5_version(i).component_build_time());
		(*net_signals)["HV_CELLBOARD_5_VERSION"]["canlib_build_time"].push(pack->hv_cellboard_5_version(i).canlib_build_time());

    }

    for(int i = 0; i < pack->hv_errors_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_errors(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_errors(i)._inner_timestamp();
        (*net_signals)["HV_ERRORS"]["_timestamp"].push(pack->hv_errors(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

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
		(*net_enums)["HV_ERRORS"]["errors_connector_disconnected"].push(pack->hv_errors(i).errors_connector_disconnected());
		(*net_enums)["HV_ERRORS"]["errors_fans_disconnected"].push(pack->hv_errors(i).errors_fans_disconnected());
		(*net_enums)["HV_ERRORS"]["errors_feedback"].push(pack->hv_errors(i).errors_feedback());
		(*net_enums)["HV_ERRORS"]["errors_feedback_circuitry"].push(pack->hv_errors(i).errors_feedback_circuitry());
		(*net_enums)["HV_ERRORS"]["errors_eeprom_comm"].push(pack->hv_errors(i).errors_eeprom_comm());
		(*net_enums)["HV_ERRORS"]["errors_eeprom_write"].push(pack->hv_errors(i).errors_eeprom_write());

    }

    for(int i = 0; i < pack->hv_debug_signals_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_debug_signals(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_debug_signals(i)._inner_timestamp();
        (*net_signals)["HV_DEBUG_SIGNALS"]["_timestamp"].push(pack->hv_debug_signals(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["HV_DEBUG_SIGNALS"]["feedbacks_implausibility_detected"].push(pack->hv_debug_signals(i).feedbacks_implausibility_detected());
		(*net_enums)["HV_DEBUG_SIGNALS"]["feedbacks_imd_cockpit"].push(pack->hv_debug_signals(i).feedbacks_imd_cockpit());
		(*net_enums)["HV_DEBUG_SIGNALS"]["feedbacks_tsal_green_fault_latched"].push(pack->hv_debug_signals(i).feedbacks_tsal_green_fault_latched());
		(*net_enums)["HV_DEBUG_SIGNALS"]["feedbacks_bms_cockpit"].push(pack->hv_debug_signals(i).feedbacks_bms_cockpit());
		(*net_enums)["HV_DEBUG_SIGNALS"]["feedbacks_ext_latched"].push(pack->hv_debug_signals(i).feedbacks_ext_latched());
		(*net_enums)["HV_DEBUG_SIGNALS"]["feedbacks_tsal_green"].push(pack->hv_debug_signals(i).feedbacks_tsal_green());
		(*net_enums)["HV_DEBUG_SIGNALS"]["feedbacks_ts_over_60v_status"].push(pack->hv_debug_signals(i).feedbacks_ts_over_60v_status());
		(*net_enums)["HV_DEBUG_SIGNALS"]["feedbacks_airn_status"].push(pack->hv_debug_signals(i).feedbacks_airn_status());
		(*net_enums)["HV_DEBUG_SIGNALS"]["feedbacks_airp_status"].push(pack->hv_debug_signals(i).feedbacks_airp_status());
		(*net_enums)["HV_DEBUG_SIGNALS"]["feedbacks_airp_gate"].push(pack->hv_debug_signals(i).feedbacks_airp_gate());
		(*net_enums)["HV_DEBUG_SIGNALS"]["feedbacks_airn_gate"].push(pack->hv_debug_signals(i).feedbacks_airn_gate());
		(*net_enums)["HV_DEBUG_SIGNALS"]["feedbacks_precharge_status"].push(pack->hv_debug_signals(i).feedbacks_precharge_status());
		(*net_enums)["HV_DEBUG_SIGNALS"]["feedbacks_tsp_over_60v_status"].push(pack->hv_debug_signals(i).feedbacks_tsp_over_60v_status());
		(*net_enums)["HV_DEBUG_SIGNALS"]["feedbacks_imd_fault"].push(pack->hv_debug_signals(i).feedbacks_imd_fault());
		(*net_enums)["HV_DEBUG_SIGNALS"]["feedbacks_check_mux"].push(pack->hv_debug_signals(i).feedbacks_check_mux());
		(*net_enums)["HV_DEBUG_SIGNALS"]["feedbacks_sd_end"].push(pack->hv_debug_signals(i).feedbacks_sd_end());
		(*net_enums)["HV_DEBUG_SIGNALS"]["feedbacks_sd_out"].push(pack->hv_debug_signals(i).feedbacks_sd_out());
		(*net_enums)["HV_DEBUG_SIGNALS"]["feedbacks_sd_in"].push(pack->hv_debug_signals(i).feedbacks_sd_in());
		(*net_enums)["HV_DEBUG_SIGNALS"]["feedbacks_sd_bms"].push(pack->hv_debug_signals(i).feedbacks_sd_bms());
		(*net_enums)["HV_DEBUG_SIGNALS"]["feedbacks_sd_imd"].push(pack->hv_debug_signals(i).feedbacks_sd_imd());
		(*net_enums)["HV_DEBUG_SIGNALS"]["errors_cell_low_voltage"].push(pack->hv_debug_signals(i).errors_cell_low_voltage());
		(*net_enums)["HV_DEBUG_SIGNALS"]["errors_cell_under_voltage"].push(pack->hv_debug_signals(i).errors_cell_under_voltage());
		(*net_enums)["HV_DEBUG_SIGNALS"]["errors_cell_over_voltage"].push(pack->hv_debug_signals(i).errors_cell_over_voltage());
		(*net_enums)["HV_DEBUG_SIGNALS"]["errors_cell_high_temperature"].push(pack->hv_debug_signals(i).errors_cell_high_temperature());
		(*net_enums)["HV_DEBUG_SIGNALS"]["errors_cell_over_temperature"].push(pack->hv_debug_signals(i).errors_cell_over_temperature());
		(*net_enums)["HV_DEBUG_SIGNALS"]["errors_over_current"].push(pack->hv_debug_signals(i).errors_over_current());
		(*net_enums)["HV_DEBUG_SIGNALS"]["errors_can"].push(pack->hv_debug_signals(i).errors_can());
		(*net_enums)["HV_DEBUG_SIGNALS"]["errors_int_voltage_mismatch"].push(pack->hv_debug_signals(i).errors_int_voltage_mismatch());
		(*net_enums)["HV_DEBUG_SIGNALS"]["errors_cellboard_comm"].push(pack->hv_debug_signals(i).errors_cellboard_comm());
		(*net_enums)["HV_DEBUG_SIGNALS"]["errors_cellboard_internal"].push(pack->hv_debug_signals(i).errors_cellboard_internal());
		(*net_enums)["HV_DEBUG_SIGNALS"]["errors_connector_disconnected"].push(pack->hv_debug_signals(i).errors_connector_disconnected());
		(*net_enums)["HV_DEBUG_SIGNALS"]["errors_fans_disconnected"].push(pack->hv_debug_signals(i).errors_fans_disconnected());
		(*net_enums)["HV_DEBUG_SIGNALS"]["errors_feedback"].push(pack->hv_debug_signals(i).errors_feedback());
		(*net_enums)["HV_DEBUG_SIGNALS"]["errors_feedback_circuitry"].push(pack->hv_debug_signals(i).errors_feedback_circuitry());
		(*net_enums)["HV_DEBUG_SIGNALS"]["errors_eeprom_comm"].push(pack->hv_debug_signals(i).errors_eeprom_comm());
		(*net_enums)["HV_DEBUG_SIGNALS"]["errors_eeprom_write"].push(pack->hv_debug_signals(i).errors_eeprom_write());

    }

    for(int i = 0; i < pack->hv_fans_status_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_fans_status(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_fans_status(i)._inner_timestamp();
        (*net_signals)["HV_FANS_STATUS"]["_timestamp"].push(pack->hv_fans_status(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["HV_FANS_STATUS"]["fans_override"].push(pack->hv_fans_status(i).fans_override());
		primary_hv_fans_status_fans_override_enum_to_string((primary_hv_fans_status_fans_override)pack->hv_fans_status(i).fans_override(), buffer);
		(*net_strings)["HV_FANS_STATUS"]["fans_override"].push(buffer);
		(*net_signals)["HV_FANS_STATUS"]["fans_speed"].push(pack->hv_fans_status(i).fans_speed());

    }

    for(int i = 0; i < pack->hv_set_fans_status_handcart_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_set_fans_status_handcart(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_set_fans_status_handcart(i)._inner_timestamp();
        (*net_signals)["HV_SET_FANS_STATUS_HANDCART"]["_timestamp"].push(pack->hv_set_fans_status_handcart(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["HV_SET_FANS_STATUS_HANDCART"]["fans_override"].push(pack->hv_set_fans_status_handcart(i).fans_override());
		primary_hv_set_fans_status_handcart_fans_override_enum_to_string((primary_hv_set_fans_status_handcart_fans_override)pack->hv_set_fans_status_handcart(i).fans_override(), buffer);
		(*net_strings)["HV_SET_FANS_STATUS_HANDCART"]["fans_override"].push(buffer);
		(*net_signals)["HV_SET_FANS_STATUS_HANDCART"]["fans_speed"].push(pack->hv_set_fans_status_handcart(i).fans_speed());

    }

    for(int i = 0; i < pack->hv_feedback_status_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_feedback_status(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_feedback_status(i)._inner_timestamp();
        (*net_signals)["HV_FEEDBACK_STATUS"]["_timestamp"].push(pack->hv_feedback_status(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["HV_FEEDBACK_STATUS"]["feedbacks_implausibility_detected"].push(pack->hv_feedback_status(i).feedbacks_implausibility_detected());
		(*net_enums)["HV_FEEDBACK_STATUS"]["feedbacks_imd_cockpit"].push(pack->hv_feedback_status(i).feedbacks_imd_cockpit());
		(*net_enums)["HV_FEEDBACK_STATUS"]["feedbacks_tsal_green_fault_latched"].push(pack->hv_feedback_status(i).feedbacks_tsal_green_fault_latched());
		(*net_enums)["HV_FEEDBACK_STATUS"]["feedbacks_bms_cockpit"].push(pack->hv_feedback_status(i).feedbacks_bms_cockpit());
		(*net_enums)["HV_FEEDBACK_STATUS"]["feedbacks_ext_latched"].push(pack->hv_feedback_status(i).feedbacks_ext_latched());
		(*net_enums)["HV_FEEDBACK_STATUS"]["feedbacks_tsal_green"].push(pack->hv_feedback_status(i).feedbacks_tsal_green());
		(*net_enums)["HV_FEEDBACK_STATUS"]["feedbacks_ts_over_60v_status"].push(pack->hv_feedback_status(i).feedbacks_ts_over_60v_status());
		(*net_enums)["HV_FEEDBACK_STATUS"]["feedbacks_airn_status"].push(pack->hv_feedback_status(i).feedbacks_airn_status());
		(*net_enums)["HV_FEEDBACK_STATUS"]["feedbacks_airp_status"].push(pack->hv_feedback_status(i).feedbacks_airp_status());
		(*net_enums)["HV_FEEDBACK_STATUS"]["feedbacks_airp_gate"].push(pack->hv_feedback_status(i).feedbacks_airp_gate());
		(*net_enums)["HV_FEEDBACK_STATUS"]["feedbacks_airn_gate"].push(pack->hv_feedback_status(i).feedbacks_airn_gate());
		(*net_enums)["HV_FEEDBACK_STATUS"]["feedbacks_precharge_status"].push(pack->hv_feedback_status(i).feedbacks_precharge_status());
		(*net_enums)["HV_FEEDBACK_STATUS"]["feedbacks_tsp_over_60v_status"].push(pack->hv_feedback_status(i).feedbacks_tsp_over_60v_status());
		(*net_enums)["HV_FEEDBACK_STATUS"]["feedbacks_imd_fault"].push(pack->hv_feedback_status(i).feedbacks_imd_fault());
		(*net_enums)["HV_FEEDBACK_STATUS"]["feedbacks_check_mux"].push(pack->hv_feedback_status(i).feedbacks_check_mux());
		(*net_enums)["HV_FEEDBACK_STATUS"]["feedbacks_sd_end"].push(pack->hv_feedback_status(i).feedbacks_sd_end());
		(*net_enums)["HV_FEEDBACK_STATUS"]["feedbacks_sd_out"].push(pack->hv_feedback_status(i).feedbacks_sd_out());
		(*net_enums)["HV_FEEDBACK_STATUS"]["feedbacks_sd_in"].push(pack->hv_feedback_status(i).feedbacks_sd_in());
		(*net_enums)["HV_FEEDBACK_STATUS"]["feedbacks_sd_bms"].push(pack->hv_feedback_status(i).feedbacks_sd_bms());
		(*net_enums)["HV_FEEDBACK_STATUS"]["feedbacks_sd_imd"].push(pack->hv_feedback_status(i).feedbacks_sd_imd());

    }

    for(int i = 0; i < pack->hv_feedback_ts_voltage_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_feedback_ts_voltage(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_feedback_ts_voltage(i)._inner_timestamp();
        (*net_signals)["HV_FEEDBACK_TS_VOLTAGE"]["_timestamp"].push(pack->hv_feedback_ts_voltage(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["HV_FEEDBACK_TS_VOLTAGE"]["ts_over_60v_status"].push(pack->hv_feedback_ts_voltage(i).ts_over_60v_status());
		(*net_signals)["HV_FEEDBACK_TS_VOLTAGE"]["airn_status"].push(pack->hv_feedback_ts_voltage(i).airn_status());
		(*net_signals)["HV_FEEDBACK_TS_VOLTAGE"]["airp_status"].push(pack->hv_feedback_ts_voltage(i).airp_status());
		(*net_signals)["HV_FEEDBACK_TS_VOLTAGE"]["airp_gate"].push(pack->hv_feedback_ts_voltage(i).airp_gate());
		(*net_signals)["HV_FEEDBACK_TS_VOLTAGE"]["airn_gate"].push(pack->hv_feedback_ts_voltage(i).airn_gate());
		(*net_signals)["HV_FEEDBACK_TS_VOLTAGE"]["precharge_status"].push(pack->hv_feedback_ts_voltage(i).precharge_status());
		(*net_signals)["HV_FEEDBACK_TS_VOLTAGE"]["tsp_over_60v_status"].push(pack->hv_feedback_ts_voltage(i).tsp_over_60v_status());

    }

    for(int i = 0; i < pack->hv_feedback_misc_voltage_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_feedback_misc_voltage(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_feedback_misc_voltage(i)._inner_timestamp();
        (*net_signals)["HV_FEEDBACK_MISC_VOLTAGE"]["_timestamp"].push(pack->hv_feedback_misc_voltage(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["HV_FEEDBACK_MISC_VOLTAGE"]["implausibility_detected"].push(pack->hv_feedback_misc_voltage(i).implausibility_detected());
		(*net_signals)["HV_FEEDBACK_MISC_VOLTAGE"]["imd_cockpit"].push(pack->hv_feedback_misc_voltage(i).imd_cockpit());
		(*net_signals)["HV_FEEDBACK_MISC_VOLTAGE"]["tsal_green_fault_latched"].push(pack->hv_feedback_misc_voltage(i).tsal_green_fault_latched());
		(*net_signals)["HV_FEEDBACK_MISC_VOLTAGE"]["bms_cockpit"].push(pack->hv_feedback_misc_voltage(i).bms_cockpit());
		(*net_signals)["HV_FEEDBACK_MISC_VOLTAGE"]["ext_latched"].push(pack->hv_feedback_misc_voltage(i).ext_latched());
		(*net_signals)["HV_FEEDBACK_MISC_VOLTAGE"]["tsal_green"].push(pack->hv_feedback_misc_voltage(i).tsal_green());
		(*net_signals)["HV_FEEDBACK_MISC_VOLTAGE"]["imd_fault"].push(pack->hv_feedback_misc_voltage(i).imd_fault());
		(*net_signals)["HV_FEEDBACK_MISC_VOLTAGE"]["check_mux"].push(pack->hv_feedback_misc_voltage(i).check_mux());

    }

    for(int i = 0; i < pack->hv_feedback_sd_voltage_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_feedback_sd_voltage(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_feedback_sd_voltage(i)._inner_timestamp();
        (*net_signals)["HV_FEEDBACK_SD_VOLTAGE"]["_timestamp"].push(pack->hv_feedback_sd_voltage(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["HV_FEEDBACK_SD_VOLTAGE"]["sd_end"].push(pack->hv_feedback_sd_voltage(i).sd_end());
		(*net_signals)["HV_FEEDBACK_SD_VOLTAGE"]["sd_out"].push(pack->hv_feedback_sd_voltage(i).sd_out());
		(*net_signals)["HV_FEEDBACK_SD_VOLTAGE"]["sd_in"].push(pack->hv_feedback_sd_voltage(i).sd_in());
		(*net_signals)["HV_FEEDBACK_SD_VOLTAGE"]["sd_bms"].push(pack->hv_feedback_sd_voltage(i).sd_bms());
		(*net_signals)["HV_FEEDBACK_SD_VOLTAGE"]["sd_imd"].push(pack->hv_feedback_sd_voltage(i).sd_imd());

    }

    for(int i = 0; i < pack->hv_imd_status_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_imd_status(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_imd_status(i)._inner_timestamp();
        (*net_signals)["HV_IMD_STATUS"]["_timestamp"].push(pack->hv_imd_status(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["HV_IMD_STATUS"]["imd_fault"].push(pack->hv_imd_status(i).imd_fault());
		(*net_signals)["HV_IMD_STATUS"]["imd_status"].push(pack->hv_imd_status(i).imd_status());
		(*net_signals)["HV_IMD_STATUS"]["imd_details"].push(pack->hv_imd_status(i).imd_details());
		(*net_signals)["HV_IMD_STATUS"]["imd_duty_cycle"].push(pack->hv_imd_status(i).imd_duty_cycle());
		(*net_signals)["HV_IMD_STATUS"]["imd_freq"].push(pack->hv_imd_status(i).imd_freq());
		(*net_signals)["HV_IMD_STATUS"]["imd_period"].push(pack->hv_imd_status(i).imd_period());

    }

    for(int i = 0; i < pack->hv_status_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_status(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_status(i)._inner_timestamp();
        (*net_signals)["HV_STATUS"]["_timestamp"].push(pack->hv_status(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["HV_STATUS"]["status"].push(pack->hv_status(i).status());
		primary_hv_status_status_enum_to_string((primary_hv_status_status)pack->hv_status(i).status(), buffer);
		(*net_strings)["HV_STATUS"]["status"].push(buffer);

    }

    for(int i = 0; i < pack->hv_set_status_ecu_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_set_status_ecu(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_set_status_ecu(i)._inner_timestamp();
        (*net_signals)["HV_SET_STATUS_ECU"]["_timestamp"].push(pack->hv_set_status_ecu(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["HV_SET_STATUS_ECU"]["hv_status_set"].push(pack->hv_set_status_ecu(i).hv_status_set());
		primary_hv_set_status_ecu_hv_status_set_enum_to_string((primary_hv_set_status_ecu_hv_status_set)pack->hv_set_status_ecu(i).hv_status_set(), buffer);
		(*net_strings)["HV_SET_STATUS_ECU"]["hv_status_set"].push(buffer);

    }

    for(int i = 0; i < pack->hv_set_status_handcart_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_set_status_handcart(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_set_status_handcart(i)._inner_timestamp();
        (*net_signals)["HV_SET_STATUS_HANDCART"]["_timestamp"].push(pack->hv_set_status_handcart(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["HV_SET_STATUS_HANDCART"]["hv_status_set"].push(pack->hv_set_status_handcart(i).hv_status_set());
		primary_hv_set_status_handcart_hv_status_set_enum_to_string((primary_hv_set_status_handcart_hv_status_set)pack->hv_set_status_handcart(i).hv_status_set(), buffer);
		(*net_strings)["HV_SET_STATUS_HANDCART"]["hv_status_set"].push(buffer);

    }

    for(int i = 0; i < pack->hv_balancing_status_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_balancing_status(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_balancing_status(i)._inner_timestamp();
        (*net_signals)["HV_BALANCING_STATUS"]["_timestamp"].push(pack->hv_balancing_status(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["HV_BALANCING_STATUS"]["cellboard_id"].push(pack->hv_balancing_status(i).cellboard_id());
		primary_hv_balancing_status_cellboard_id_enum_to_string((primary_hv_balancing_status_cellboard_id)pack->hv_balancing_status(i).cellboard_id(), buffer);
		(*net_strings)["HV_BALANCING_STATUS"]["cellboard_id"].push(buffer);
		(*net_enums)["HV_BALANCING_STATUS"]["balancing_status"].push(pack->hv_balancing_status(i).balancing_status());
		primary_hv_balancing_status_balancing_status_enum_to_string((primary_hv_balancing_status_balancing_status)pack->hv_balancing_status(i).balancing_status(), buffer);
		(*net_strings)["HV_BALANCING_STATUS"]["balancing_status"].push(buffer);
		(*net_enums)["HV_BALANCING_STATUS"]["errors_can_comm"].push(pack->hv_balancing_status(i).errors_can_comm());
		(*net_enums)["HV_BALANCING_STATUS"]["errors_ltc_comm"].push(pack->hv_balancing_status(i).errors_ltc_comm());
		(*net_enums)["HV_BALANCING_STATUS"]["errors_temp_comm_0"].push(pack->hv_balancing_status(i).errors_temp_comm_0());
		(*net_enums)["HV_BALANCING_STATUS"]["errors_temp_comm_1"].push(pack->hv_balancing_status(i).errors_temp_comm_1());
		(*net_enums)["HV_BALANCING_STATUS"]["errors_temp_comm_2"].push(pack->hv_balancing_status(i).errors_temp_comm_2());
		(*net_enums)["HV_BALANCING_STATUS"]["errors_temp_comm_3"].push(pack->hv_balancing_status(i).errors_temp_comm_3());
		(*net_enums)["HV_BALANCING_STATUS"]["errors_temp_comm_4"].push(pack->hv_balancing_status(i).errors_temp_comm_4());
		(*net_enums)["HV_BALANCING_STATUS"]["errors_temp_comm_5"].push(pack->hv_balancing_status(i).errors_temp_comm_5());
		(*net_enums)["HV_BALANCING_STATUS"]["errors_open_wire"].push(pack->hv_balancing_status(i).errors_open_wire());
		(*net_enums)["HV_BALANCING_STATUS"]["balancing_cells_cell0"].push(pack->hv_balancing_status(i).balancing_cells_cell0());
		(*net_enums)["HV_BALANCING_STATUS"]["balancing_cells_cell1"].push(pack->hv_balancing_status(i).balancing_cells_cell1());
		(*net_enums)["HV_BALANCING_STATUS"]["balancing_cells_cell2"].push(pack->hv_balancing_status(i).balancing_cells_cell2());
		(*net_enums)["HV_BALANCING_STATUS"]["balancing_cells_cell3"].push(pack->hv_balancing_status(i).balancing_cells_cell3());
		(*net_enums)["HV_BALANCING_STATUS"]["balancing_cells_cell4"].push(pack->hv_balancing_status(i).balancing_cells_cell4());
		(*net_enums)["HV_BALANCING_STATUS"]["balancing_cells_cell5"].push(pack->hv_balancing_status(i).balancing_cells_cell5());
		(*net_enums)["HV_BALANCING_STATUS"]["balancing_cells_cell6"].push(pack->hv_balancing_status(i).balancing_cells_cell6());
		(*net_enums)["HV_BALANCING_STATUS"]["balancing_cells_cell7"].push(pack->hv_balancing_status(i).balancing_cells_cell7());
		(*net_enums)["HV_BALANCING_STATUS"]["balancing_cells_cell8"].push(pack->hv_balancing_status(i).balancing_cells_cell8());
		(*net_enums)["HV_BALANCING_STATUS"]["balancing_cells_cell9"].push(pack->hv_balancing_status(i).balancing_cells_cell9());
		(*net_enums)["HV_BALANCING_STATUS"]["balancing_cells_cell10"].push(pack->hv_balancing_status(i).balancing_cells_cell10());
		(*net_enums)["HV_BALANCING_STATUS"]["balancing_cells_cell11"].push(pack->hv_balancing_status(i).balancing_cells_cell11());
		(*net_enums)["HV_BALANCING_STATUS"]["balancing_cells_cell12"].push(pack->hv_balancing_status(i).balancing_cells_cell12());
		(*net_enums)["HV_BALANCING_STATUS"]["balancing_cells_cell13"].push(pack->hv_balancing_status(i).balancing_cells_cell13());
		(*net_enums)["HV_BALANCING_STATUS"]["balancing_cells_cell14"].push(pack->hv_balancing_status(i).balancing_cells_cell14());
		(*net_enums)["HV_BALANCING_STATUS"]["balancing_cells_cell15"].push(pack->hv_balancing_status(i).balancing_cells_cell15());
		(*net_enums)["HV_BALANCING_STATUS"]["balancing_cells_cell16"].push(pack->hv_balancing_status(i).balancing_cells_cell16());
		(*net_enums)["HV_BALANCING_STATUS"]["balancing_cells_cell17"].push(pack->hv_balancing_status(i).balancing_cells_cell17());

    }

    for(int i = 0; i < pack->hv_set_balancing_status_handcart_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_set_balancing_status_handcart(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_set_balancing_status_handcart(i)._inner_timestamp();
        (*net_signals)["HV_SET_BALANCING_STATUS_HANDCART"]["_timestamp"].push(pack->hv_set_balancing_status_handcart(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["HV_SET_BALANCING_STATUS_HANDCART"]["set_balancing_status"].push(pack->hv_set_balancing_status_handcart(i).set_balancing_status());
		primary_hv_set_balancing_status_handcart_set_balancing_status_enum_to_string((primary_hv_set_balancing_status_handcart_set_balancing_status)pack->hv_set_balancing_status_handcart(i).set_balancing_status(), buffer);
		(*net_strings)["HV_SET_BALANCING_STATUS_HANDCART"]["set_balancing_status"].push(buffer);
		(*net_signals)["HV_SET_BALANCING_STATUS_HANDCART"]["balancing_threshold"].push(pack->hv_set_balancing_status_handcart(i).balancing_threshold());

    }

    for(int i = 0; i < pack->lv_status_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->lv_status(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->lv_status(i)._inner_timestamp();
        (*net_signals)["LV_STATUS"]["_timestamp"].push(pack->lv_status(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["LV_STATUS"]["status"].push(pack->lv_status(i).status());
		primary_lv_status_status_enum_to_string((primary_lv_status_status)pack->lv_status(i).status(), buffer);
		(*net_strings)["LV_STATUS"]["status"].push(buffer);

    }

    for(int i = 0; i < pack->lv_radiator_speed_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->lv_radiator_speed(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->lv_radiator_speed(i)._inner_timestamp();
        (*net_signals)["LV_RADIATOR_SPEED"]["_timestamp"].push(pack->lv_radiator_speed(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["LV_RADIATOR_SPEED"]["radiator_speed"].push(pack->lv_radiator_speed(i).radiator_speed());

    }

    for(int i = 0; i < pack->lv_pumps_speed_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->lv_pumps_speed(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->lv_pumps_speed(i)._inner_timestamp();
        (*net_signals)["LV_PUMPS_SPEED"]["_timestamp"].push(pack->lv_pumps_speed(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["LV_PUMPS_SPEED"]["pumps_speed"].push(pack->lv_pumps_speed(i).pumps_speed());

    }

    for(int i = 0; i < pack->lv_set_radiator_speed_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->lv_set_radiator_speed(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->lv_set_radiator_speed(i)._inner_timestamp();
        (*net_signals)["LV_SET_RADIATOR_SPEED"]["_timestamp"].push(pack->lv_set_radiator_speed(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["LV_SET_RADIATOR_SPEED"]["radiator_speed"].push(pack->lv_set_radiator_speed(i).radiator_speed());

    }

    for(int i = 0; i < pack->lv_set_pumps_speed_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->lv_set_pumps_speed(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->lv_set_pumps_speed(i)._inner_timestamp();
        (*net_signals)["LV_SET_PUMPS_SPEED"]["_timestamp"].push(pack->lv_set_pumps_speed(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["LV_SET_PUMPS_SPEED"]["pumps_speed"].push(pack->lv_set_pumps_speed(i).pumps_speed());

    }

    for(int i = 0; i < pack->lv_errors_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->lv_errors(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->lv_errors(i)._inner_timestamp();
        (*net_signals)["LV_ERRORS"]["_timestamp"].push(pack->lv_errors(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

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
		(*net_enums)["LV_ERRORS"]["health_signals_lvms_out"].push(pack->lv_errors(i).health_signals_lvms_out());
		(*net_enums)["LV_ERRORS"]["health_signals_relay_out"].push(pack->lv_errors(i).health_signals_relay_out());
		(*net_enums)["LV_ERRORS"]["health_signals_battery_voltage_out"].push(pack->lv_errors(i).health_signals_battery_voltage_out());
		(*net_enums)["LV_ERRORS"]["health_signals_charger_current"].push(pack->lv_errors(i).health_signals_charger_current());
		(*net_enums)["LV_ERRORS"]["health_signals_battery_current"].push(pack->lv_errors(i).health_signals_battery_current());
		(*net_enums)["LV_ERRORS"]["health_signals_sign_battery_current"].push(pack->lv_errors(i).health_signals_sign_battery_current());

    }

    for(int i = 0; i < pack->lv_feedback_ts_voltage_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->lv_feedback_ts_voltage(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->lv_feedback_ts_voltage(i)._inner_timestamp();
        (*net_signals)["LV_FEEDBACK_TS_VOLTAGE"]["_timestamp"].push(pack->lv_feedback_ts_voltage(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["LV_FEEDBACK_TS_VOLTAGE"]["bspd"].push(pack->lv_feedback_ts_voltage(i).bspd());
		(*net_signals)["LV_FEEDBACK_TS_VOLTAGE"]["hvd"].push(pack->lv_feedback_ts_voltage(i).hvd());
		(*net_signals)["LV_FEEDBACK_TS_VOLTAGE"]["invc_interlock"].push(pack->lv_feedback_ts_voltage(i).invc_interlock());
		(*net_signals)["LV_FEEDBACK_TS_VOLTAGE"]["ams"].push(pack->lv_feedback_ts_voltage(i).ams());

    }

    for(int i = 0; i < pack->lv_feedback_sd_voltage_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->lv_feedback_sd_voltage(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->lv_feedback_sd_voltage(i)._inner_timestamp();
        (*net_signals)["LV_FEEDBACK_SD_VOLTAGE"]["_timestamp"].push(pack->lv_feedback_sd_voltage(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["LV_FEEDBACK_SD_VOLTAGE"]["sd_end"].push(pack->lv_feedback_sd_voltage(i).sd_end());
		(*net_signals)["LV_FEEDBACK_SD_VOLTAGE"]["lvms"].push(pack->lv_feedback_sd_voltage(i).lvms());
		(*net_signals)["LV_FEEDBACK_SD_VOLTAGE"]["interlock"].push(pack->lv_feedback_sd_voltage(i).interlock());
		(*net_signals)["LV_FEEDBACK_SD_VOLTAGE"]["sd_start"].push(pack->lv_feedback_sd_voltage(i).sd_start());

    }

    for(int i = 0; i < pack->lv_feedback_enclosure_voltage_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->lv_feedback_enclosure_voltage(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->lv_feedback_enclosure_voltage(i)._inner_timestamp();
        (*net_signals)["LV_FEEDBACK_ENCLOSURE_VOLTAGE"]["_timestamp"].push(pack->lv_feedback_enclosure_voltage(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["LV_FEEDBACK_ENCLOSURE_VOLTAGE"]["lv_encl"].push(pack->lv_feedback_enclosure_voltage(i).lv_encl());
		(*net_signals)["LV_FEEDBACK_ENCLOSURE_VOLTAGE"]["invc_lid"].push(pack->lv_feedback_enclosure_voltage(i).invc_lid());
		(*net_signals)["LV_FEEDBACK_ENCLOSURE_VOLTAGE"]["hv_encl_2"].push(pack->lv_feedback_enclosure_voltage(i).hv_encl_2());
		(*net_signals)["LV_FEEDBACK_ENCLOSURE_VOLTAGE"]["backplate"].push(pack->lv_feedback_enclosure_voltage(i).backplate());

    }

    for(int i = 0; i < pack->lv_feedback_gpio_extender_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->lv_feedback_gpio_extender(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->lv_feedback_gpio_extender(i)._inner_timestamp();
        (*net_signals)["LV_FEEDBACK_GPIO_EXTENDER"]["_timestamp"].push(pack->lv_feedback_gpio_extender(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["LV_FEEDBACK_GPIO_EXTENDER"]["feedback_inverters"].push(pack->lv_feedback_gpio_extender(i).feedback_inverters());
		(*net_enums)["LV_FEEDBACK_GPIO_EXTENDER"]["feedback_pcbs"].push(pack->lv_feedback_gpio_extender(i).feedback_pcbs());
		(*net_enums)["LV_FEEDBACK_GPIO_EXTENDER"]["feedback_pumps"].push(pack->lv_feedback_gpio_extender(i).feedback_pumps());
		(*net_enums)["LV_FEEDBACK_GPIO_EXTENDER"]["feedback_radiators"].push(pack->lv_feedback_gpio_extender(i).feedback_radiators());
		(*net_enums)["LV_FEEDBACK_GPIO_EXTENDER"]["feedback_shutdown"].push(pack->lv_feedback_gpio_extender(i).feedback_shutdown());
		(*net_enums)["LV_FEEDBACK_GPIO_EXTENDER"]["feedback_hv_fans"].push(pack->lv_feedback_gpio_extender(i).feedback_hv_fans());
		(*net_enums)["LV_FEEDBACK_GPIO_EXTENDER"]["feedback_autonomous_system_actuation"].push(pack->lv_feedback_gpio_extender(i).feedback_autonomous_system_actuation());

    }

    for(int i = 0; i < pack->lv_can_flash_req_steering_wheel_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->lv_can_flash_req_steering_wheel(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->lv_can_flash_req_steering_wheel(i)._inner_timestamp();
        (*net_signals)["LV_CAN_FLASH_REQ_STEERING_WHEEL"]["_timestamp"].push(pack->lv_can_flash_req_steering_wheel(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->lv_can_flash_ack_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->lv_can_flash_ack(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->lv_can_flash_ack(i)._inner_timestamp();
        (*net_signals)["LV_CAN_FLASH_ACK"]["_timestamp"].push(pack->lv_can_flash_ack(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->lv_inverter_connection_status_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->lv_inverter_connection_status(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->lv_inverter_connection_status(i)._inner_timestamp();
        (*net_signals)["LV_INVERTER_CONNECTION_STATUS"]["_timestamp"].push(pack->lv_inverter_connection_status(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["LV_INVERTER_CONNECTION_STATUS"]["status"].push(pack->lv_inverter_connection_status(i).status());
		primary_lv_inverter_connection_status_status_enum_to_string((primary_lv_inverter_connection_status_status)pack->lv_inverter_connection_status(i).status(), buffer);
		(*net_strings)["LV_INVERTER_CONNECTION_STATUS"]["status"].push(buffer);

    }

    for(int i = 0; i < pack->lv_set_inverter_connection_status_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->lv_set_inverter_connection_status(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->lv_set_inverter_connection_status(i)._inner_timestamp();
        (*net_signals)["LV_SET_INVERTER_CONNECTION_STATUS"]["_timestamp"].push(pack->lv_set_inverter_connection_status(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["LV_SET_INVERTER_CONNECTION_STATUS"]["status"].push(pack->lv_set_inverter_connection_status(i).status());
		primary_lv_set_inverter_connection_status_status_enum_to_string((primary_lv_set_inverter_connection_status_status)pack->lv_set_inverter_connection_status(i).status(), buffer);
		(*net_strings)["LV_SET_INVERTER_CONNECTION_STATUS"]["status"].push(buffer);

    }

    for(int i = 0; i < pack->tlm_status_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->tlm_status(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->tlm_status(i)._inner_timestamp();
        (*net_signals)["TLM_STATUS"]["_timestamp"].push(pack->tlm_status(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["TLM_STATUS"]["status"].push(pack->tlm_status(i).status());
		primary_tlm_status_status_enum_to_string((primary_tlm_status_status)pack->tlm_status(i).status(), buffer);
		(*net_strings)["TLM_STATUS"]["status"].push(buffer);

    }

    for(int i = 0; i < pack->tlm_set_status_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->tlm_set_status(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->tlm_set_status(i)._inner_timestamp();
        (*net_signals)["TLM_SET_STATUS"]["_timestamp"].push(pack->tlm_set_status(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["TLM_SET_STATUS"]["status"].push(pack->tlm_set_status(i).status());
		primary_tlm_set_status_status_enum_to_string((primary_tlm_set_status_status)pack->tlm_set_status(i).status(), buffer);
		(*net_strings)["TLM_SET_STATUS"]["status"].push(buffer);

    }

    for(int i = 0; i < pack->handcart_status_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->handcart_status(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->handcart_status(i)._inner_timestamp();
        (*net_signals)["HANDCART_STATUS"]["_timestamp"].push(pack->handcart_status(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["HANDCART_STATUS"]["connected"].push(pack->handcart_status(i).connected());
		primary_handcart_status_connected_enum_to_string((primary_handcart_status_connected)pack->handcart_status(i).connected(), buffer);
		(*net_strings)["HANDCART_STATUS"]["connected"].push(buffer);

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

    for(int i = 0; i < pack->handcart_set_settings_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->handcart_set_settings(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->handcart_set_settings(i)._inner_timestamp();
        (*net_signals)["HANDCART_SET_SETTINGS"]["_timestamp"].push(pack->handcart_set_settings(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["HANDCART_SET_SETTINGS"]["target_voltage"].push(pack->handcart_set_settings(i).target_voltage());
		(*net_enums)["HANDCART_SET_SETTINGS"]["fans_override"].push(pack->handcart_set_settings(i).fans_override());
		primary_handcart_set_settings_fans_override_enum_to_string((primary_handcart_set_settings_fans_override)pack->handcart_set_settings(i).fans_override(), buffer);
		(*net_strings)["HANDCART_SET_SETTINGS"]["fans_override"].push(buffer);
		(*net_signals)["HANDCART_SET_SETTINGS"]["fans_speed"].push(pack->handcart_set_settings(i).fans_speed());
		(*net_signals)["HANDCART_SET_SETTINGS"]["acc_charge_current"].push(pack->handcart_set_settings(i).acc_charge_current());
		(*net_signals)["HANDCART_SET_SETTINGS"]["grid_max_current"].push(pack->handcart_set_settings(i).grid_max_current());
		(*net_enums)["HANDCART_SET_SETTINGS"]["status"].push(pack->handcart_set_settings(i).status());
		primary_handcart_set_settings_status_enum_to_string((primary_handcart_set_settings_status)pack->handcart_set_settings(i).status(), buffer);
		(*net_strings)["HANDCART_SET_SETTINGS"]["status"].push(buffer);

    }

    for(int i = 0; i < pack->ecu_status_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->ecu_status(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->ecu_status(i)._inner_timestamp();
        (*net_signals)["ECU_STATUS"]["_timestamp"].push(pack->ecu_status(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["ECU_STATUS"]["status"].push(pack->ecu_status(i).status());
		primary_ecu_status_status_enum_to_string((primary_ecu_status_status)pack->ecu_status(i).status(), buffer);
		(*net_strings)["ECU_STATUS"]["status"].push(buffer);

    }

    for(int i = 0; i < pack->ecu_set_status_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->ecu_set_status(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->ecu_set_status(i)._inner_timestamp();
        (*net_signals)["ECU_SET_STATUS"]["_timestamp"].push(pack->ecu_set_status(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["ECU_SET_STATUS"]["status"].push(pack->ecu_set_status(i).status());
		primary_ecu_set_status_status_enum_to_string((primary_ecu_set_status_status)pack->ecu_set_status(i).status(), buffer);
		(*net_strings)["ECU_SET_STATUS"]["status"].push(buffer);

    }

    for(int i = 0; i < pack->ecu_inverter_status_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->ecu_inverter_status(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->ecu_inverter_status(i)._inner_timestamp();
        (*net_signals)["ECU_INVERTER_STATUS"]["_timestamp"].push(pack->ecu_inverter_status(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["ECU_INVERTER_STATUS"]["rl"].push(pack->ecu_inverter_status(i).rl());
		primary_ecu_inverter_status_rl_enum_to_string((primary_ecu_inverter_status_rl)pack->ecu_inverter_status(i).rl(), buffer);
		(*net_strings)["ECU_INVERTER_STATUS"]["rl"].push(buffer);
		(*net_enums)["ECU_INVERTER_STATUS"]["rr"].push(pack->ecu_inverter_status(i).rr());
		primary_ecu_inverter_status_rr_enum_to_string((primary_ecu_inverter_status_rr)pack->ecu_inverter_status(i).rr(), buffer);
		(*net_strings)["ECU_INVERTER_STATUS"]["rr"].push(buffer);

    }

    for(int i = 0; i < pack->ecu_control_status_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->ecu_control_status(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->ecu_control_status(i)._inner_timestamp();
        (*net_signals)["ECU_CONTROL_STATUS"]["_timestamp"].push(pack->ecu_control_status(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["ECU_CONTROL_STATUS"]["control_enabled"].push(pack->ecu_control_status(i).control_enabled());
		(*net_enums)["ECU_CONTROL_STATUS"]["control_errors_forced_off"].push(pack->ecu_control_status(i).control_errors_forced_off());
		(*net_enums)["ECU_CONTROL_STATUS"]["control_errors_wrong_maps"].push(pack->ecu_control_status(i).control_errors_wrong_maps());
		(*net_enums)["ECU_CONTROL_STATUS"]["control_errors_control_watchdog"].push(pack->ecu_control_status(i).control_errors_control_watchdog());

    }

    for(int i = 0; i < pack->ecu_errors_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->ecu_errors(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->ecu_errors(i)._inner_timestamp();
        (*net_signals)["ECU_ERRORS"]["_timestamp"].push(pack->ecu_errors(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["ECU_ERRORS"]["error_pedal_adc"].push(pack->ecu_errors(i).error_pedal_adc());
		(*net_enums)["ECU_ERRORS"]["error_pedal_implausibility"].push(pack->ecu_errors(i).error_pedal_implausibility());
		(*net_enums)["ECU_ERRORS"]["error_imu_tout"].push(pack->ecu_errors(i).error_imu_tout());
		(*net_enums)["ECU_ERRORS"]["error_irts_tout"].push(pack->ecu_errors(i).error_irts_tout());
		(*net_enums)["ECU_ERRORS"]["error_ts_tout"].push(pack->ecu_errors(i).error_ts_tout());
		(*net_enums)["ECU_ERRORS"]["error_invl_tout"].push(pack->ecu_errors(i).error_invl_tout());
		(*net_enums)["ECU_ERRORS"]["error_invr_tout"].push(pack->ecu_errors(i).error_invr_tout());
		(*net_enums)["ECU_ERRORS"]["error_steer_tout"].push(pack->ecu_errors(i).error_steer_tout());
		(*net_enums)["ECU_ERRORS"]["error_fsm"].push(pack->ecu_errors(i).error_fsm());

    }

    for(int i = 0; i < pack->ecu_feedbacks_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->ecu_feedbacks(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->ecu_feedbacks(i)._inner_timestamp();
        (*net_signals)["ECU_FEEDBACKS"]["_timestamp"].push(pack->ecu_feedbacks(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["ECU_FEEDBACKS"]["feedbacks_sd_cock_fb"].push(pack->ecu_feedbacks(i).feedbacks_sd_cock_fb());
		(*net_enums)["ECU_FEEDBACKS"]["feedbacks_sd_fb1"].push(pack->ecu_feedbacks(i).feedbacks_sd_fb1());
		(*net_enums)["ECU_FEEDBACKS"]["feedbacks_sd_bots_fb"].push(pack->ecu_feedbacks(i).feedbacks_sd_bots_fb());
		(*net_enums)["ECU_FEEDBACKS"]["feedbacks_sd_interial_fb"].push(pack->ecu_feedbacks(i).feedbacks_sd_interial_fb());
		(*net_enums)["ECU_FEEDBACKS"]["feedbacks_sd_fb4"].push(pack->ecu_feedbacks(i).feedbacks_sd_fb4());
		(*net_enums)["ECU_FEEDBACKS"]["feedbacks_sd_in"].push(pack->ecu_feedbacks(i).feedbacks_sd_in());
		(*net_enums)["ECU_FEEDBACKS"]["feedbacks_sd_out"].push(pack->ecu_feedbacks(i).feedbacks_sd_out());
		(*net_enums)["ECU_FEEDBACKS"]["feedbacks_sd_ctrl_pin"].push(pack->ecu_feedbacks(i).feedbacks_sd_ctrl_pin());

    }

    for(int i = 0; i < pack->ecu_power_maps_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->ecu_power_maps(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->ecu_power_maps(i)._inner_timestamp();
        (*net_signals)["ECU_POWER_MAPS"]["_timestamp"].push(pack->ecu_power_maps(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["ECU_POWER_MAPS"]["map_pw"].push(pack->ecu_power_maps(i).map_pw());
		(*net_signals)["ECU_POWER_MAPS"]["map_sc"].push(pack->ecu_power_maps(i).map_sc());
		(*net_signals)["ECU_POWER_MAPS"]["map_tv"].push(pack->ecu_power_maps(i).map_tv());

    }

    for(int i = 0; i < pack->ecu_set_power_maps_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->ecu_set_power_maps(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->ecu_set_power_maps(i)._inner_timestamp();
        (*net_signals)["ECU_SET_POWER_MAPS"]["_timestamp"].push(pack->ecu_set_power_maps(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["ECU_SET_POWER_MAPS"]["map_pw"].push(pack->ecu_set_power_maps(i).map_pw());
		(*net_signals)["ECU_SET_POWER_MAPS"]["map_sc"].push(pack->ecu_set_power_maps(i).map_sc());
		(*net_signals)["ECU_SET_POWER_MAPS"]["map_tv"].push(pack->ecu_set_power_maps(i).map_tv());

    }

    for(int i = 0; i < pack->ecu_ptt_status_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->ecu_ptt_status(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->ecu_ptt_status(i)._inner_timestamp();
        (*net_signals)["ECU_PTT_STATUS"]["_timestamp"].push(pack->ecu_ptt_status(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["ECU_PTT_STATUS"]["status"].push(pack->ecu_ptt_status(i).status());
		primary_ecu_ptt_status_status_enum_to_string((primary_ecu_ptt_status_status)pack->ecu_ptt_status(i).status(), buffer);
		(*net_strings)["ECU_PTT_STATUS"]["status"].push(buffer);

    }

    for(int i = 0; i < pack->ecu_set_ptt_status_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->ecu_set_ptt_status(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->ecu_set_ptt_status(i)._inner_timestamp();
        (*net_signals)["ECU_SET_PTT_STATUS"]["_timestamp"].push(pack->ecu_set_ptt_status(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["ECU_SET_PTT_STATUS"]["status"].push(pack->ecu_set_ptt_status(i).status());
		primary_ecu_set_ptt_status_status_enum_to_string((primary_ecu_set_ptt_status_status)pack->ecu_set_ptt_status(i).status(), buffer);
		(*net_strings)["ECU_SET_PTT_STATUS"]["status"].push(buffer);

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

    for(int i = 0; i < pack->lv_current_battery_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->lv_current_battery(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->lv_current_battery(i)._inner_timestamp();
        (*net_signals)["LV_CURRENT_BATTERY"]["_timestamp"].push(pack->lv_current_battery(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["LV_CURRENT_BATTERY"]["lv_current"].push(pack->lv_current_battery(i).lv_current());

    }

    for(int i = 0; i < pack->lv_current_charger_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->lv_current_charger(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->lv_current_charger(i)._inner_timestamp();
        (*net_signals)["LV_CURRENT_CHARGER"]["_timestamp"].push(pack->lv_current_charger(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["LV_CURRENT_CHARGER"]["charger_current"].push(pack->lv_current_charger(i).charger_current());

    }

    for(int i = 0; i < pack->lv_total_voltage_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->lv_total_voltage(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->lv_total_voltage(i)._inner_timestamp();
        (*net_signals)["LV_TOTAL_VOLTAGE"]["_timestamp"].push(pack->lv_total_voltage(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["LV_TOTAL_VOLTAGE"]["total"].push(pack->lv_total_voltage(i).total());

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

    for(int i = 0; i < pack->lv_cells_voltage_stats_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->lv_cells_voltage_stats(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->lv_cells_voltage_stats(i)._inner_timestamp();
        (*net_signals)["LV_CELLS_VOLTAGE_STATS"]["_timestamp"].push(pack->lv_cells_voltage_stats(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["LV_CELLS_VOLTAGE_STATS"]["max"].push(pack->lv_cells_voltage_stats(i).max());
		(*net_signals)["LV_CELLS_VOLTAGE_STATS"]["min"].push(pack->lv_cells_voltage_stats(i).min());
		(*net_signals)["LV_CELLS_VOLTAGE_STATS"]["delta"].push(pack->lv_cells_voltage_stats(i).delta());
		(*net_signals)["LV_CELLS_VOLTAGE_STATS"]["avg"].push(pack->lv_cells_voltage_stats(i).avg());

    }

    for(int i = 0; i < pack->lv_cells_temp_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->lv_cells_temp(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->lv_cells_temp(i)._inner_timestamp();
        (*net_signals)["LV_CELLS_TEMP"]["_timestamp"].push(pack->lv_cells_temp(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["LV_CELLS_TEMP"]["start_index"].push(pack->lv_cells_temp(i).start_index());
		(*net_signals)["LV_CELLS_TEMP"]["temp_0"].push(pack->lv_cells_temp(i).temp_0());
		(*net_signals)["LV_CELLS_TEMP"]["temp_1"].push(pack->lv_cells_temp(i).temp_1());
		(*net_signals)["LV_CELLS_TEMP"]["temp_2"].push(pack->lv_cells_temp(i).temp_2());

    }

    for(int i = 0; i < pack->lv_cells_temp_stats_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->lv_cells_temp_stats(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->lv_cells_temp_stats(i)._inner_timestamp();
        (*net_signals)["LV_CELLS_TEMP_STATS"]["_timestamp"].push(pack->lv_cells_temp_stats(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["LV_CELLS_TEMP_STATS"]["max"].push(pack->lv_cells_temp_stats(i).max());
		(*net_signals)["LV_CELLS_TEMP_STATS"]["min"].push(pack->lv_cells_temp_stats(i).min());
		(*net_signals)["LV_CELLS_TEMP_STATS"]["avg"].push(pack->lv_cells_temp_stats(i).avg());

    }

    for(int i = 0; i < pack->hv_current_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_current(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_current(i)._inner_timestamp();
        (*net_signals)["HV_CURRENT"]["_timestamp"].push(pack->hv_current(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["HV_CURRENT"]["current"].push(pack->hv_current(i).current());

    }

    for(int i = 0; i < pack->hv_power_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_power(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_power(i)._inner_timestamp();
        (*net_signals)["HV_POWER"]["_timestamp"].push(pack->hv_power(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["HV_POWER"]["power"].push(pack->hv_power(i).power());

    }

    for(int i = 0; i < pack->hv_energy_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_energy(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_energy(i)._inner_timestamp();
        (*net_signals)["HV_ENERGY"]["_timestamp"].push(pack->hv_energy(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["HV_ENERGY"]["energy"].push(pack->hv_energy(i).energy());

    }

    for(int i = 0; i < pack->hv_soc_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_soc(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_soc(i)._inner_timestamp();
        (*net_signals)["HV_SOC"]["_timestamp"].push(pack->hv_soc(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["HV_SOC"]["soc"].push(pack->hv_soc(i).soc());

    }

    for(int i = 0; i < pack->hv_total_voltage_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_total_voltage(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_total_voltage(i)._inner_timestamp();
        (*net_signals)["HV_TOTAL_VOLTAGE"]["_timestamp"].push(pack->hv_total_voltage(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["HV_TOTAL_VOLTAGE"]["pack"].push(pack->hv_total_voltage(i).pack());
		(*net_signals)["HV_TOTAL_VOLTAGE"]["sum_cell"].push(pack->hv_total_voltage(i).sum_cell());
		(*net_signals)["HV_TOTAL_VOLTAGE"]["bus"].push(pack->hv_total_voltage(i).bus());

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

    for(int i = 0; i < pack->hv_cells_voltage_stats_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_cells_voltage_stats(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_cells_voltage_stats(i)._inner_timestamp();
        (*net_signals)["HV_CELLS_VOLTAGE_STATS"]["_timestamp"].push(pack->hv_cells_voltage_stats(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["HV_CELLS_VOLTAGE_STATS"]["max"].push(pack->hv_cells_voltage_stats(i).max());
		(*net_signals)["HV_CELLS_VOLTAGE_STATS"]["min"].push(pack->hv_cells_voltage_stats(i).min());
		(*net_signals)["HV_CELLS_VOLTAGE_STATS"]["sum"].push(pack->hv_cells_voltage_stats(i).sum());
		(*net_signals)["HV_CELLS_VOLTAGE_STATS"]["avg"].push(pack->hv_cells_voltage_stats(i).avg());

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

    }

    for(int i = 0; i < pack->hv_cells_temp_stats_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_cells_temp_stats(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_cells_temp_stats(i)._inner_timestamp();
        (*net_signals)["HV_CELLS_TEMP_STATS"]["_timestamp"].push(pack->hv_cells_temp_stats(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["HV_CELLS_TEMP_STATS"]["max"].push(pack->hv_cells_temp_stats(i).max());
		(*net_signals)["HV_CELLS_TEMP_STATS"]["min"].push(pack->hv_cells_temp_stats(i).min());
		(*net_signals)["HV_CELLS_TEMP_STATS"]["avg"].push(pack->hv_cells_temp_stats(i).avg());

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
            primary_hv_jmp_to_blt_t* msg = (primary_hv_jmp_to_blt_t*)(device->message);
            primary::HV_JMP_TO_BLT* proto_msg = pack->add_hv_jmp_to_blt();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1: {
            primary_hv_flash_mainboard_tx_t* msg = (primary_hv_flash_mainboard_tx_t*)(device->message);
            primary::HV_FLASH_MAINBOARD_TX* proto_msg = pack->add_hv_flash_mainboard_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 2: {
            primary_hv_flash_mainboard_rx_t* msg = (primary_hv_flash_mainboard_rx_t*)(device->message);
            primary::HV_FLASH_MAINBOARD_RX* proto_msg = pack->add_hv_flash_mainboard_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 3: {
            primary_hv_flash_cellboard_0_tx_t* msg = (primary_hv_flash_cellboard_0_tx_t*)(device->message);
            primary::HV_FLASH_CELLBOARD_0_TX* proto_msg = pack->add_hv_flash_cellboard_0_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 4: {
            primary_hv_flash_cellboard_0_rx_t* msg = (primary_hv_flash_cellboard_0_rx_t*)(device->message);
            primary::HV_FLASH_CELLBOARD_0_RX* proto_msg = pack->add_hv_flash_cellboard_0_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 5: {
            primary_hv_flash_cellboard_1_tx_t* msg = (primary_hv_flash_cellboard_1_tx_t*)(device->message);
            primary::HV_FLASH_CELLBOARD_1_TX* proto_msg = pack->add_hv_flash_cellboard_1_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 6: {
            primary_hv_flash_cellboard_1_rx_t* msg = (primary_hv_flash_cellboard_1_rx_t*)(device->message);
            primary::HV_FLASH_CELLBOARD_1_RX* proto_msg = pack->add_hv_flash_cellboard_1_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 7: {
            primary_hv_flash_cellboard_2_tx_t* msg = (primary_hv_flash_cellboard_2_tx_t*)(device->message);
            primary::HV_FLASH_CELLBOARD_2_TX* proto_msg = pack->add_hv_flash_cellboard_2_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 8: {
            primary_hv_flash_cellboard_2_rx_t* msg = (primary_hv_flash_cellboard_2_rx_t*)(device->message);
            primary::HV_FLASH_CELLBOARD_2_RX* proto_msg = pack->add_hv_flash_cellboard_2_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 9: {
            primary_hv_flash_cellboard_3_tx_t* msg = (primary_hv_flash_cellboard_3_tx_t*)(device->message);
            primary::HV_FLASH_CELLBOARD_3_TX* proto_msg = pack->add_hv_flash_cellboard_3_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 10: {
            primary_hv_flash_cellboard_3_rx_t* msg = (primary_hv_flash_cellboard_3_rx_t*)(device->message);
            primary::HV_FLASH_CELLBOARD_3_RX* proto_msg = pack->add_hv_flash_cellboard_3_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 11: {
            primary_hv_flash_cellboard_4_tx_t* msg = (primary_hv_flash_cellboard_4_tx_t*)(device->message);
            primary::HV_FLASH_CELLBOARD_4_TX* proto_msg = pack->add_hv_flash_cellboard_4_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 12: {
            primary_hv_flash_cellboard_4_rx_t* msg = (primary_hv_flash_cellboard_4_rx_t*)(device->message);
            primary::HV_FLASH_CELLBOARD_4_RX* proto_msg = pack->add_hv_flash_cellboard_4_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 13: {
            primary_hv_flash_cellboard_5_tx_t* msg = (primary_hv_flash_cellboard_5_tx_t*)(device->message);
            primary::HV_FLASH_CELLBOARD_5_TX* proto_msg = pack->add_hv_flash_cellboard_5_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 14: {
            primary_hv_flash_cellboard_5_rx_t* msg = (primary_hv_flash_cellboard_5_rx_t*)(device->message);
            primary::HV_FLASH_CELLBOARD_5_RX* proto_msg = pack->add_hv_flash_cellboard_5_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 15: {
            primary_lv_jmp_to_blt_t* msg = (primary_lv_jmp_to_blt_t*)(device->message);
            primary::LV_JMP_TO_BLT* proto_msg = pack->add_lv_jmp_to_blt();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 16: {
            primary_lv_flash_bms_tx_t* msg = (primary_lv_flash_bms_tx_t*)(device->message);
            primary::LV_FLASH_BMS_TX* proto_msg = pack->add_lv_flash_bms_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 17: {
            primary_lv_flash_bms_rx_t* msg = (primary_lv_flash_bms_rx_t*)(device->message);
            primary::LV_FLASH_BMS_RX* proto_msg = pack->add_lv_flash_bms_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 18: {
            primary_ecu_jmp_to_blt_t* msg = (primary_ecu_jmp_to_blt_t*)(device->message);
            primary::ECU_JMP_TO_BLT* proto_msg = pack->add_ecu_jmp_to_blt();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 19: {
            primary_ecu_flash_tx_t* msg = (primary_ecu_flash_tx_t*)(device->message);
            primary::ECU_FLASH_TX* proto_msg = pack->add_ecu_flash_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 20: {
            primary_ecu_flash_rx_t* msg = (primary_ecu_flash_rx_t*)(device->message);
            primary::ECU_FLASH_RX* proto_msg = pack->add_ecu_flash_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 21: {
            primary_steering_wheel_jmp_to_blt_t* msg = (primary_steering_wheel_jmp_to_blt_t*)(device->message);
            primary::STEERING_WHEEL_JMP_TO_BLT* proto_msg = pack->add_steering_wheel_jmp_to_blt();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 22: {
            primary_steering_wheel_flash_tx_t* msg = (primary_steering_wheel_flash_tx_t*)(device->message);
            primary::STEERING_WHEEL_FLASH_TX* proto_msg = pack->add_steering_wheel_flash_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 23: {
            primary_steering_wheel_flash_rx_t* msg = (primary_steering_wheel_flash_rx_t*)(device->message);
            primary::STEERING_WHEEL_FLASH_RX* proto_msg = pack->add_steering_wheel_flash_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 700: {
            primary_steering_wheel_version_t* msg = (primary_steering_wheel_version_t*)(device->message);
            primary::STEERING_WHEEL_VERSION* proto_msg = pack->add_steering_wheel_version();
			proto_msg->set_component_build_time(msg->component_build_time);
			proto_msg->set_canlib_build_time(msg->canlib_build_time);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 701: {
            primary_ecu_version_t* msg = (primary_ecu_version_t*)(device->message);
            primary::ECU_VERSION* proto_msg = pack->add_ecu_version();
			proto_msg->set_component_build_time(msg->component_build_time);
			proto_msg->set_canlib_build_time(msg->canlib_build_time);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 703: {
            primary_lv_version_t* msg = (primary_lv_version_t*)(device->message);
            primary::LV_VERSION* proto_msg = pack->add_lv_version();
			proto_msg->set_component_build_time(msg->component_build_time);
			proto_msg->set_canlib_build_time(msg->canlib_build_time);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 704: {
            primary_tlm_version_t* msg = (primary_tlm_version_t*)(device->message);
            primary::TLM_VERSION* proto_msg = pack->add_tlm_version();
			proto_msg->set_component_build_time(msg->component_build_time);
			proto_msg->set_canlib_build_time(msg->canlib_build_time);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 702: {
            primary_hv_mainboard_version_t* msg = (primary_hv_mainboard_version_t*)(device->message);
            primary::HV_MAINBOARD_VERSION* proto_msg = pack->add_hv_mainboard_version();
			proto_msg->set_component_build_time(msg->component_build_time);
			proto_msg->set_canlib_build_time(msg->canlib_build_time);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 705: {
            primary_hv_cellboard_0_version_t* msg = (primary_hv_cellboard_0_version_t*)(device->message);
            primary::HV_CELLBOARD_0_VERSION* proto_msg = pack->add_hv_cellboard_0_version();
			proto_msg->set_component_build_time(msg->component_build_time);
			proto_msg->set_canlib_build_time(msg->canlib_build_time);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 706: {
            primary_hv_cellboard_1_version_t* msg = (primary_hv_cellboard_1_version_t*)(device->message);
            primary::HV_CELLBOARD_1_VERSION* proto_msg = pack->add_hv_cellboard_1_version();
			proto_msg->set_component_build_time(msg->component_build_time);
			proto_msg->set_canlib_build_time(msg->canlib_build_time);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 707: {
            primary_hv_cellboard_2_version_t* msg = (primary_hv_cellboard_2_version_t*)(device->message);
            primary::HV_CELLBOARD_2_VERSION* proto_msg = pack->add_hv_cellboard_2_version();
			proto_msg->set_component_build_time(msg->component_build_time);
			proto_msg->set_canlib_build_time(msg->canlib_build_time);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 708: {
            primary_hv_cellboard_3_version_t* msg = (primary_hv_cellboard_3_version_t*)(device->message);
            primary::HV_CELLBOARD_3_VERSION* proto_msg = pack->add_hv_cellboard_3_version();
			proto_msg->set_component_build_time(msg->component_build_time);
			proto_msg->set_canlib_build_time(msg->canlib_build_time);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 709: {
            primary_hv_cellboard_4_version_t* msg = (primary_hv_cellboard_4_version_t*)(device->message);
            primary::HV_CELLBOARD_4_VERSION* proto_msg = pack->add_hv_cellboard_4_version();
			proto_msg->set_component_build_time(msg->component_build_time);
			proto_msg->set_canlib_build_time(msg->canlib_build_time);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 710: {
            primary_hv_cellboard_5_version_t* msg = (primary_hv_cellboard_5_version_t*)(device->message);
            primary::HV_CELLBOARD_5_VERSION* proto_msg = pack->add_hv_cellboard_5_version();
			proto_msg->set_component_build_time(msg->component_build_time);
			proto_msg->set_canlib_build_time(msg->canlib_build_time);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 24: {
            primary_hv_errors_t* msg = (primary_hv_errors_t*)(device->message);
            primary::HV_ERRORS* proto_msg = pack->add_hv_errors();
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
			proto_msg->set_errors_connector_disconnected(msg->errors_connector_disconnected);
			proto_msg->set_errors_fans_disconnected(msg->errors_fans_disconnected);
			proto_msg->set_errors_feedback(msg->errors_feedback);
			proto_msg->set_errors_feedback_circuitry(msg->errors_feedback_circuitry);
			proto_msg->set_errors_eeprom_comm(msg->errors_eeprom_comm);
			proto_msg->set_errors_eeprom_write(msg->errors_eeprom_write);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 512: {
            primary_hv_debug_signals_t* msg = (primary_hv_debug_signals_t*)(device->message);
            primary::HV_DEBUG_SIGNALS* proto_msg = pack->add_hv_debug_signals();
			proto_msg->set_feedbacks_implausibility_detected(msg->feedbacks_implausibility_detected);
			proto_msg->set_feedbacks_imd_cockpit(msg->feedbacks_imd_cockpit);
			proto_msg->set_feedbacks_tsal_green_fault_latched(msg->feedbacks_tsal_green_fault_latched);
			proto_msg->set_feedbacks_bms_cockpit(msg->feedbacks_bms_cockpit);
			proto_msg->set_feedbacks_ext_latched(msg->feedbacks_ext_latched);
			proto_msg->set_feedbacks_tsal_green(msg->feedbacks_tsal_green);
			proto_msg->set_feedbacks_ts_over_60v_status(msg->feedbacks_ts_over_60v_status);
			proto_msg->set_feedbacks_airn_status(msg->feedbacks_airn_status);
			proto_msg->set_feedbacks_airp_status(msg->feedbacks_airp_status);
			proto_msg->set_feedbacks_airp_gate(msg->feedbacks_airp_gate);
			proto_msg->set_feedbacks_airn_gate(msg->feedbacks_airn_gate);
			proto_msg->set_feedbacks_precharge_status(msg->feedbacks_precharge_status);
			proto_msg->set_feedbacks_tsp_over_60v_status(msg->feedbacks_tsp_over_60v_status);
			proto_msg->set_feedbacks_imd_fault(msg->feedbacks_imd_fault);
			proto_msg->set_feedbacks_check_mux(msg->feedbacks_check_mux);
			proto_msg->set_feedbacks_sd_end(msg->feedbacks_sd_end);
			proto_msg->set_feedbacks_sd_out(msg->feedbacks_sd_out);
			proto_msg->set_feedbacks_sd_in(msg->feedbacks_sd_in);
			proto_msg->set_feedbacks_sd_bms(msg->feedbacks_sd_bms);
			proto_msg->set_feedbacks_sd_imd(msg->feedbacks_sd_imd);
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
			proto_msg->set_errors_connector_disconnected(msg->errors_connector_disconnected);
			proto_msg->set_errors_fans_disconnected(msg->errors_fans_disconnected);
			proto_msg->set_errors_feedback(msg->errors_feedback);
			proto_msg->set_errors_feedback_circuitry(msg->errors_feedback_circuitry);
			proto_msg->set_errors_eeprom_comm(msg->errors_eeprom_comm);
			proto_msg->set_errors_eeprom_write(msg->errors_eeprom_write);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1536: {
            primary_hv_fans_status_converted_t* msg = (primary_hv_fans_status_converted_t*)(device->message);
            primary::HV_FANS_STATUS* proto_msg = pack->add_hv_fans_status();
			proto_msg->set_fans_override((primary::primary_hv_fans_status_fans_override)msg->fans_override);
			proto_msg->set_fans_speed(msg->fans_speed);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1032: {
            primary_hv_set_fans_status_handcart_converted_t* msg = (primary_hv_set_fans_status_handcart_converted_t*)(device->message);
            primary::HV_SET_FANS_STATUS_HANDCART* proto_msg = pack->add_hv_set_fans_status_handcart();
			proto_msg->set_fans_override((primary::primary_hv_set_fans_status_handcart_fans_override)msg->fans_override);
			proto_msg->set_fans_speed(msg->fans_speed);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 520: {
            primary_hv_feedback_status_t* msg = (primary_hv_feedback_status_t*)(device->message);
            primary::HV_FEEDBACK_STATUS* proto_msg = pack->add_hv_feedback_status();
			proto_msg->set_feedbacks_implausibility_detected(msg->feedbacks_implausibility_detected);
			proto_msg->set_feedbacks_imd_cockpit(msg->feedbacks_imd_cockpit);
			proto_msg->set_feedbacks_tsal_green_fault_latched(msg->feedbacks_tsal_green_fault_latched);
			proto_msg->set_feedbacks_bms_cockpit(msg->feedbacks_bms_cockpit);
			proto_msg->set_feedbacks_ext_latched(msg->feedbacks_ext_latched);
			proto_msg->set_feedbacks_tsal_green(msg->feedbacks_tsal_green);
			proto_msg->set_feedbacks_ts_over_60v_status(msg->feedbacks_ts_over_60v_status);
			proto_msg->set_feedbacks_airn_status(msg->feedbacks_airn_status);
			proto_msg->set_feedbacks_airp_status(msg->feedbacks_airp_status);
			proto_msg->set_feedbacks_airp_gate(msg->feedbacks_airp_gate);
			proto_msg->set_feedbacks_airn_gate(msg->feedbacks_airn_gate);
			proto_msg->set_feedbacks_precharge_status(msg->feedbacks_precharge_status);
			proto_msg->set_feedbacks_tsp_over_60v_status(msg->feedbacks_tsp_over_60v_status);
			proto_msg->set_feedbacks_imd_fault(msg->feedbacks_imd_fault);
			proto_msg->set_feedbacks_check_mux(msg->feedbacks_check_mux);
			proto_msg->set_feedbacks_sd_end(msg->feedbacks_sd_end);
			proto_msg->set_feedbacks_sd_out(msg->feedbacks_sd_out);
			proto_msg->set_feedbacks_sd_in(msg->feedbacks_sd_in);
			proto_msg->set_feedbacks_sd_bms(msg->feedbacks_sd_bms);
			proto_msg->set_feedbacks_sd_imd(msg->feedbacks_sd_imd);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 528: {
            primary_hv_feedback_ts_voltage_converted_t* msg = (primary_hv_feedback_ts_voltage_converted_t*)(device->message);
            primary::HV_FEEDBACK_TS_VOLTAGE* proto_msg = pack->add_hv_feedback_ts_voltage();
			proto_msg->set_ts_over_60v_status(msg->ts_over_60v_status);
			proto_msg->set_airn_status(msg->airn_status);
			proto_msg->set_airp_status(msg->airp_status);
			proto_msg->set_airp_gate(msg->airp_gate);
			proto_msg->set_airn_gate(msg->airn_gate);
			proto_msg->set_precharge_status(msg->precharge_status);
			proto_msg->set_tsp_over_60v_status(msg->tsp_over_60v_status);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 536: {
            primary_hv_feedback_misc_voltage_t* msg = (primary_hv_feedback_misc_voltage_t*)(device->message);
            primary::HV_FEEDBACK_MISC_VOLTAGE* proto_msg = pack->add_hv_feedback_misc_voltage();
			proto_msg->set_implausibility_detected(msg->implausibility_detected);
			proto_msg->set_imd_cockpit(msg->imd_cockpit);
			proto_msg->set_tsal_green_fault_latched(msg->tsal_green_fault_latched);
			proto_msg->set_bms_cockpit(msg->bms_cockpit);
			proto_msg->set_ext_latched(msg->ext_latched);
			proto_msg->set_tsal_green(msg->tsal_green);
			proto_msg->set_imd_fault(msg->imd_fault);
			proto_msg->set_check_mux(msg->check_mux);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 544: {
            primary_hv_feedback_sd_voltage_t* msg = (primary_hv_feedback_sd_voltage_t*)(device->message);
            primary::HV_FEEDBACK_SD_VOLTAGE* proto_msg = pack->add_hv_feedback_sd_voltage();
			proto_msg->set_sd_end(msg->sd_end);
			proto_msg->set_sd_out(msg->sd_out);
			proto_msg->set_sd_in(msg->sd_in);
			proto_msg->set_sd_bms(msg->sd_bms);
			proto_msg->set_sd_imd(msg->sd_imd);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 552: {
            primary_hv_imd_status_t* msg = (primary_hv_imd_status_t*)(device->message);
            primary::HV_IMD_STATUS* proto_msg = pack->add_hv_imd_status();
			proto_msg->set_imd_fault(msg->imd_fault);
			proto_msg->set_imd_status(msg->imd_status);
			proto_msg->set_imd_details(msg->imd_details);
			proto_msg->set_imd_duty_cycle(msg->imd_duty_cycle);
			proto_msg->set_imd_freq(msg->imd_freq);
			proto_msg->set_imd_period(msg->imd_period);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 560: {
            primary_hv_status_t* msg = (primary_hv_status_t*)(device->message);
            primary::HV_STATUS* proto_msg = pack->add_hv_status();
			proto_msg->set_status((primary::primary_hv_status_status)msg->status);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 32: {
            primary_hv_set_status_ecu_t* msg = (primary_hv_set_status_ecu_t*)(device->message);
            primary::HV_SET_STATUS_ECU* proto_msg = pack->add_hv_set_status_ecu();
			proto_msg->set_hv_status_set((primary::primary_hv_set_status_ecu_hv_status_set)msg->hv_status_set);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 40: {
            primary_hv_set_status_handcart_t* msg = (primary_hv_set_status_handcart_t*)(device->message);
            primary::HV_SET_STATUS_HANDCART* proto_msg = pack->add_hv_set_status_handcart();
			proto_msg->set_hv_status_set((primary::primary_hv_set_status_handcart_hv_status_set)msg->hv_status_set);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1544: {
            primary_hv_balancing_status_t* msg = (primary_hv_balancing_status_t*)(device->message);
            primary::HV_BALANCING_STATUS* proto_msg = pack->add_hv_balancing_status();
			proto_msg->set_cellboard_id((primary::primary_hv_balancing_status_cellboard_id)msg->cellboard_id);
			proto_msg->set_balancing_status((primary::primary_hv_balancing_status_balancing_status)msg->balancing_status);
			proto_msg->set_errors_can_comm(msg->errors_can_comm);
			proto_msg->set_errors_ltc_comm(msg->errors_ltc_comm);
			proto_msg->set_errors_temp_comm_0(msg->errors_temp_comm_0);
			proto_msg->set_errors_temp_comm_1(msg->errors_temp_comm_1);
			proto_msg->set_errors_temp_comm_2(msg->errors_temp_comm_2);
			proto_msg->set_errors_temp_comm_3(msg->errors_temp_comm_3);
			proto_msg->set_errors_temp_comm_4(msg->errors_temp_comm_4);
			proto_msg->set_errors_temp_comm_5(msg->errors_temp_comm_5);
			proto_msg->set_errors_open_wire(msg->errors_open_wire);
			proto_msg->set_balancing_cells_cell0(msg->balancing_cells_cell0);
			proto_msg->set_balancing_cells_cell1(msg->balancing_cells_cell1);
			proto_msg->set_balancing_cells_cell2(msg->balancing_cells_cell2);
			proto_msg->set_balancing_cells_cell3(msg->balancing_cells_cell3);
			proto_msg->set_balancing_cells_cell4(msg->balancing_cells_cell4);
			proto_msg->set_balancing_cells_cell5(msg->balancing_cells_cell5);
			proto_msg->set_balancing_cells_cell6(msg->balancing_cells_cell6);
			proto_msg->set_balancing_cells_cell7(msg->balancing_cells_cell7);
			proto_msg->set_balancing_cells_cell8(msg->balancing_cells_cell8);
			proto_msg->set_balancing_cells_cell9(msg->balancing_cells_cell9);
			proto_msg->set_balancing_cells_cell10(msg->balancing_cells_cell10);
			proto_msg->set_balancing_cells_cell11(msg->balancing_cells_cell11);
			proto_msg->set_balancing_cells_cell12(msg->balancing_cells_cell12);
			proto_msg->set_balancing_cells_cell13(msg->balancing_cells_cell13);
			proto_msg->set_balancing_cells_cell14(msg->balancing_cells_cell14);
			proto_msg->set_balancing_cells_cell15(msg->balancing_cells_cell15);
			proto_msg->set_balancing_cells_cell16(msg->balancing_cells_cell16);
			proto_msg->set_balancing_cells_cell17(msg->balancing_cells_cell17);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1048: {
            primary_hv_set_balancing_status_handcart_t* msg = (primary_hv_set_balancing_status_handcart_t*)(device->message);
            primary::HV_SET_BALANCING_STATUS_HANDCART* proto_msg = pack->add_hv_set_balancing_status_handcart();
			proto_msg->set_set_balancing_status((primary::primary_hv_set_balancing_status_handcart_set_balancing_status)msg->set_balancing_status);
			proto_msg->set_balancing_threshold(msg->balancing_threshold);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 568: {
            primary_lv_status_t* msg = (primary_lv_status_t*)(device->message);
            primary::LV_STATUS* proto_msg = pack->add_lv_status();
			proto_msg->set_status((primary::primary_lv_status_status)msg->status);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1568: {
            primary_lv_radiator_speed_converted_t* msg = (primary_lv_radiator_speed_converted_t*)(device->message);
            primary::LV_RADIATOR_SPEED* proto_msg = pack->add_lv_radiator_speed();
			proto_msg->set_radiator_speed(msg->radiator_speed);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1576: {
            primary_lv_pumps_speed_converted_t* msg = (primary_lv_pumps_speed_converted_t*)(device->message);
            primary::LV_PUMPS_SPEED* proto_msg = pack->add_lv_pumps_speed();
			proto_msg->set_pumps_speed(msg->pumps_speed);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1056: {
            primary_lv_set_radiator_speed_converted_t* msg = (primary_lv_set_radiator_speed_converted_t*)(device->message);
            primary::LV_SET_RADIATOR_SPEED* proto_msg = pack->add_lv_set_radiator_speed();
			proto_msg->set_radiator_speed(msg->radiator_speed);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1064: {
            primary_lv_set_pumps_speed_converted_t* msg = (primary_lv_set_pumps_speed_converted_t*)(device->message);
            primary::LV_SET_PUMPS_SPEED* proto_msg = pack->add_lv_set_pumps_speed();
			proto_msg->set_pumps_speed(msg->pumps_speed);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 576: {
            primary_lv_errors_t* msg = (primary_lv_errors_t*)(device->message);
            primary::LV_ERRORS* proto_msg = pack->add_lv_errors();
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

        case 584: {
            primary_lv_feedback_ts_voltage_converted_t* msg = (primary_lv_feedback_ts_voltage_converted_t*)(device->message);
            primary::LV_FEEDBACK_TS_VOLTAGE* proto_msg = pack->add_lv_feedback_ts_voltage();
			proto_msg->set_bspd(msg->bspd);
			proto_msg->set_hvd(msg->hvd);
			proto_msg->set_invc_interlock(msg->invc_interlock);
			proto_msg->set_ams(msg->ams);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 592: {
            primary_lv_feedback_sd_voltage_converted_t* msg = (primary_lv_feedback_sd_voltage_converted_t*)(device->message);
            primary::LV_FEEDBACK_SD_VOLTAGE* proto_msg = pack->add_lv_feedback_sd_voltage();
			proto_msg->set_sd_end(msg->sd_end);
			proto_msg->set_lvms(msg->lvms);
			proto_msg->set_interlock(msg->interlock);
			proto_msg->set_sd_start(msg->sd_start);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 600: {
            primary_lv_feedback_enclosure_voltage_converted_t* msg = (primary_lv_feedback_enclosure_voltage_converted_t*)(device->message);
            primary::LV_FEEDBACK_ENCLOSURE_VOLTAGE* proto_msg = pack->add_lv_feedback_enclosure_voltage();
			proto_msg->set_lv_encl(msg->lv_encl);
			proto_msg->set_invc_lid(msg->invc_lid);
			proto_msg->set_hv_encl_2(msg->hv_encl_2);
			proto_msg->set_backplate(msg->backplate);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 608: {
            primary_lv_feedback_gpio_extender_t* msg = (primary_lv_feedback_gpio_extender_t*)(device->message);
            primary::LV_FEEDBACK_GPIO_EXTENDER* proto_msg = pack->add_lv_feedback_gpio_extender();
			proto_msg->set_feedback_inverters(msg->feedback_inverters);
			proto_msg->set_feedback_pcbs(msg->feedback_pcbs);
			proto_msg->set_feedback_pumps(msg->feedback_pumps);
			proto_msg->set_feedback_radiators(msg->feedback_radiators);
			proto_msg->set_feedback_shutdown(msg->feedback_shutdown);
			proto_msg->set_feedback_hv_fans(msg->feedback_hv_fans);
			proto_msg->set_feedback_autonomous_system_actuation(msg->feedback_autonomous_system_actuation);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 56: {
            primary_lv_can_flash_req_steering_wheel_t* msg = (primary_lv_can_flash_req_steering_wheel_t*)(device->message);
            primary::LV_CAN_FLASH_REQ_STEERING_WHEEL* proto_msg = pack->add_lv_can_flash_req_steering_wheel();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 64: {
            primary_lv_can_flash_ack_t* msg = (primary_lv_can_flash_ack_t*)(device->message);
            primary::LV_CAN_FLASH_ACK* proto_msg = pack->add_lv_can_flash_ack();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 616: {
            primary_lv_inverter_connection_status_t* msg = (primary_lv_inverter_connection_status_t*)(device->message);
            primary::LV_INVERTER_CONNECTION_STATUS* proto_msg = pack->add_lv_inverter_connection_status();
			proto_msg->set_status((primary::primary_lv_inverter_connection_status_status)msg->status);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 72: {
            primary_lv_set_inverter_connection_status_t* msg = (primary_lv_set_inverter_connection_status_t*)(device->message);
            primary::LV_SET_INVERTER_CONNECTION_STATUS* proto_msg = pack->add_lv_set_inverter_connection_status();
			proto_msg->set_status((primary::primary_lv_set_inverter_connection_status_status)msg->status);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1584: {
            primary_tlm_status_t* msg = (primary_tlm_status_t*)(device->message);
            primary::TLM_STATUS* proto_msg = pack->add_tlm_status();
			proto_msg->set_status((primary::primary_tlm_status_status)msg->status);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1072: {
            primary_tlm_set_status_t* msg = (primary_tlm_set_status_t*)(device->message);
            primary::TLM_SET_STATUS* proto_msg = pack->add_tlm_set_status();
			proto_msg->set_status((primary::primary_tlm_set_status_status)msg->status);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 624: {
            primary_handcart_status_t* msg = (primary_handcart_status_t*)(device->message);
            primary::HANDCART_STATUS* proto_msg = pack->add_handcart_status();
			proto_msg->set_connected((primary::primary_handcart_status_connected)msg->connected);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1592: {
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

        case 1080: {
            primary_handcart_set_settings_converted_t* msg = (primary_handcart_set_settings_converted_t*)(device->message);
            primary::HANDCART_SET_SETTINGS* proto_msg = pack->add_handcart_set_settings();
			proto_msg->set_target_voltage(msg->target_voltage);
			proto_msg->set_fans_override((primary::primary_handcart_set_settings_fans_override)msg->fans_override);
			proto_msg->set_fans_speed(msg->fans_speed);
			proto_msg->set_acc_charge_current(msg->acc_charge_current);
			proto_msg->set_grid_max_current(msg->grid_max_current);
			proto_msg->set_status((primary::primary_handcart_set_settings_status)msg->status);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 632: {
            primary_ecu_status_t* msg = (primary_ecu_status_t*)(device->message);
            primary::ECU_STATUS* proto_msg = pack->add_ecu_status();
			proto_msg->set_status((primary::primary_ecu_status_status)msg->status);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 80: {
            primary_ecu_set_status_t* msg = (primary_ecu_set_status_t*)(device->message);
            primary::ECU_SET_STATUS* proto_msg = pack->add_ecu_set_status();
			proto_msg->set_status((primary::primary_ecu_set_status_status)msg->status);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1088: {
            primary_ecu_inverter_status_t* msg = (primary_ecu_inverter_status_t*)(device->message);
            primary::ECU_INVERTER_STATUS* proto_msg = pack->add_ecu_inverter_status();
			proto_msg->set_rl((primary::primary_ecu_inverter_status_rl)msg->rl);
			proto_msg->set_rr((primary::primary_ecu_inverter_status_rr)msg->rr);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 640: {
            primary_ecu_control_status_t* msg = (primary_ecu_control_status_t*)(device->message);
            primary::ECU_CONTROL_STATUS* proto_msg = pack->add_ecu_control_status();
			proto_msg->set_control_enabled(msg->control_enabled);
			proto_msg->set_control_errors_forced_off(msg->control_errors_forced_off);
			proto_msg->set_control_errors_wrong_maps(msg->control_errors_wrong_maps);
			proto_msg->set_control_errors_control_watchdog(msg->control_errors_control_watchdog);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 648: {
            primary_ecu_errors_t* msg = (primary_ecu_errors_t*)(device->message);
            primary::ECU_ERRORS* proto_msg = pack->add_ecu_errors();
			proto_msg->set_error_pedal_adc(msg->error_pedal_adc);
			proto_msg->set_error_pedal_implausibility(msg->error_pedal_implausibility);
			proto_msg->set_error_imu_tout(msg->error_imu_tout);
			proto_msg->set_error_irts_tout(msg->error_irts_tout);
			proto_msg->set_error_ts_tout(msg->error_ts_tout);
			proto_msg->set_error_invl_tout(msg->error_invl_tout);
			proto_msg->set_error_invr_tout(msg->error_invr_tout);
			proto_msg->set_error_steer_tout(msg->error_steer_tout);
			proto_msg->set_error_fsm(msg->error_fsm);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 656: {
            primary_ecu_feedbacks_t* msg = (primary_ecu_feedbacks_t*)(device->message);
            primary::ECU_FEEDBACKS* proto_msg = pack->add_ecu_feedbacks();
			proto_msg->set_feedbacks_sd_cock_fb(msg->feedbacks_sd_cock_fb);
			proto_msg->set_feedbacks_sd_fb1(msg->feedbacks_sd_fb1);
			proto_msg->set_feedbacks_sd_bots_fb(msg->feedbacks_sd_bots_fb);
			proto_msg->set_feedbacks_sd_interial_fb(msg->feedbacks_sd_interial_fb);
			proto_msg->set_feedbacks_sd_fb4(msg->feedbacks_sd_fb4);
			proto_msg->set_feedbacks_sd_in(msg->feedbacks_sd_in);
			proto_msg->set_feedbacks_sd_out(msg->feedbacks_sd_out);
			proto_msg->set_feedbacks_sd_ctrl_pin(msg->feedbacks_sd_ctrl_pin);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 664: {
            primary_ecu_power_maps_converted_t* msg = (primary_ecu_power_maps_converted_t*)(device->message);
            primary::ECU_POWER_MAPS* proto_msg = pack->add_ecu_power_maps();
			proto_msg->set_map_pw(msg->map_pw);
			proto_msg->set_map_sc(msg->map_sc);
			proto_msg->set_map_tv(msg->map_tv);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 88: {
            primary_ecu_set_power_maps_converted_t* msg = (primary_ecu_set_power_maps_converted_t*)(device->message);
            primary::ECU_SET_POWER_MAPS* proto_msg = pack->add_ecu_set_power_maps();
			proto_msg->set_map_pw(msg->map_pw);
			proto_msg->set_map_sc(msg->map_sc);
			proto_msg->set_map_tv(msg->map_tv);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1600: {
            primary_ecu_ptt_status_t* msg = (primary_ecu_ptt_status_t*)(device->message);
            primary::ECU_PTT_STATUS* proto_msg = pack->add_ecu_ptt_status();
			proto_msg->set_status((primary::primary_ecu_ptt_status_status)msg->status);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1096: {
            primary_ecu_set_ptt_status_t* msg = (primary_ecu_set_ptt_status_t*)(device->message);
            primary::ECU_SET_PTT_STATUS* proto_msg = pack->add_ecu_set_ptt_status();
			proto_msg->set_status((primary::primary_ecu_set_ptt_status_status)msg->status);

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

        case 672: {
            primary_control_output_converted_t* msg = (primary_control_output_converted_t*)(device->message);
            primary::CONTROL_OUTPUT* proto_msg = pack->add_control_output();
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

        case 680: {
            primary_control_status_converted_t* msg = (primary_control_status_converted_t*)(device->message);
            primary::CONTROL_STATUS* proto_msg = pack->add_control_status();
			proto_msg->set_map_pw(msg->map_pw);
			proto_msg->set_map_sc(msg->map_sc);
			proto_msg->set_map_tv(msg->map_tv);

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

        case 1608: {
            primary_lv_current_battery_converted_t* msg = (primary_lv_current_battery_converted_t*)(device->message);
            primary::LV_CURRENT_BATTERY* proto_msg = pack->add_lv_current_battery();
			proto_msg->set_lv_current(msg->lv_current);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1616: {
            primary_lv_current_charger_converted_t* msg = (primary_lv_current_charger_converted_t*)(device->message);
            primary::LV_CURRENT_CHARGER* proto_msg = pack->add_lv_current_charger();
			proto_msg->set_charger_current(msg->charger_current);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1624: {
            primary_lv_total_voltage_converted_t* msg = (primary_lv_total_voltage_converted_t*)(device->message);
            primary::LV_TOTAL_VOLTAGE* proto_msg = pack->add_lv_total_voltage();
			proto_msg->set_total(msg->total);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1632: {
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

        case 1640: {
            primary_lv_cells_voltage_stats_converted_t* msg = (primary_lv_cells_voltage_stats_converted_t*)(device->message);
            primary::LV_CELLS_VOLTAGE_STATS* proto_msg = pack->add_lv_cells_voltage_stats();
			proto_msg->set_max(msg->max);
			proto_msg->set_min(msg->min);
			proto_msg->set_delta(msg->delta);
			proto_msg->set_avg(msg->avg);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1648: {
            primary_lv_cells_temp_converted_t* msg = (primary_lv_cells_temp_converted_t*)(device->message);
            primary::LV_CELLS_TEMP* proto_msg = pack->add_lv_cells_temp();
			proto_msg->set_start_index(msg->start_index);
			proto_msg->set_temp_0(msg->temp_0);
			proto_msg->set_temp_1(msg->temp_1);
			proto_msg->set_temp_2(msg->temp_2);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1656: {
            primary_lv_cells_temp_stats_converted_t* msg = (primary_lv_cells_temp_stats_converted_t*)(device->message);
            primary::LV_CELLS_TEMP_STATS* proto_msg = pack->add_lv_cells_temp_stats();
			proto_msg->set_max(msg->max);
			proto_msg->set_min(msg->min);
			proto_msg->set_avg(msg->avg);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1664: {
            primary_hv_current_converted_t* msg = (primary_hv_current_converted_t*)(device->message);
            primary::HV_CURRENT* proto_msg = pack->add_hv_current();
			proto_msg->set_current(msg->current);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1672: {
            primary_hv_power_converted_t* msg = (primary_hv_power_converted_t*)(device->message);
            primary::HV_POWER* proto_msg = pack->add_hv_power();
			proto_msg->set_power(msg->power);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1680: {
            primary_hv_energy_converted_t* msg = (primary_hv_energy_converted_t*)(device->message);
            primary::HV_ENERGY* proto_msg = pack->add_hv_energy();
			proto_msg->set_energy(msg->energy);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1688: {
            primary_hv_soc_converted_t* msg = (primary_hv_soc_converted_t*)(device->message);
            primary::HV_SOC* proto_msg = pack->add_hv_soc();
			proto_msg->set_soc(msg->soc);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1696: {
            primary_hv_total_voltage_converted_t* msg = (primary_hv_total_voltage_converted_t*)(device->message);
            primary::HV_TOTAL_VOLTAGE* proto_msg = pack->add_hv_total_voltage();
			proto_msg->set_pack(msg->pack);
			proto_msg->set_sum_cell(msg->sum_cell);
			proto_msg->set_bus(msg->bus);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1704: {
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

        case 1712: {
            primary_hv_cells_voltage_stats_converted_t* msg = (primary_hv_cells_voltage_stats_converted_t*)(device->message);
            primary::HV_CELLS_VOLTAGE_STATS* proto_msg = pack->add_hv_cells_voltage_stats();
			proto_msg->set_max(msg->max);
			proto_msg->set_min(msg->min);
			proto_msg->set_sum(msg->sum);
			proto_msg->set_avg(msg->avg);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1720: {
            primary_hv_cells_temp_converted_t* msg = (primary_hv_cells_temp_converted_t*)(device->message);
            primary::HV_CELLS_TEMP* proto_msg = pack->add_hv_cells_temp();
			proto_msg->set_start_index(msg->start_index);
			proto_msg->set_temp_0(msg->temp_0);
			proto_msg->set_temp_1(msg->temp_1);
			proto_msg->set_temp_2(msg->temp_2);
			proto_msg->set_temp_3(msg->temp_3);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1728: {
            primary_hv_cells_temp_stats_converted_t* msg = (primary_hv_cells_temp_stats_converted_t*)(device->message);
            primary::HV_CELLS_TEMP_STATS* proto_msg = pack->add_hv_cells_temp_stats();
			proto_msg->set_max(msg->max);
			proto_msg->set_min(msg->min);
			proto_msg->set_avg(msg->avg);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1736: {
            primary_debug_signal_1_converted_t* msg = (primary_debug_signal_1_converted_t*)(device->message);
            primary::DEBUG_SIGNAL_1* proto_msg = pack->add_debug_signal_1();
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



#endif // primary_PROTO_INTERAFCE_IMPLEMENTATION

#endif // primary_PROTO_INTERFACE_H
