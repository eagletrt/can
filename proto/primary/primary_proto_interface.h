
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

    for(int i = 0; i < pack->hv_flash_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_flash(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_flash(i)._inner_timestamp();
        (*net_signals)["HV_FLASH"]["_timestamp"].push(pack->hv_flash(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["HV_FLASH"]["start"].push(pack->hv_flash(i).start());
		(*net_enums)["HV_FLASH"]["forward"].push(pack->hv_flash(i).forward());
		primary_hv_flash_forward_enum_to_string((primary_hv_flash_forward)pack->hv_flash(i).forward(), buffer);
		(*net_strings)["HV_FLASH"]["forward"].push(buffer);
		(*net_enums)["HV_FLASH"]["cellboard_id"].push(pack->hv_flash(i).cellboard_id());
		primary_hv_flash_cellboard_id_enum_to_string((primary_hv_flash_cellboard_id)pack->hv_flash(i).cellboard_id(), buffer);
		(*net_strings)["HV_FLASH"]["cellboard_id"].push(buffer);

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

    for(int i = 0; i < pack->lv_flash_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->lv_flash_tx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->lv_flash_tx(i)._inner_timestamp();
        (*net_signals)["LV_FLASH_TX"]["_timestamp"].push(pack->lv_flash_tx(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


    }

    for(int i = 0; i < pack->lv_flash_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->lv_flash_rx(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->lv_flash_rx(i)._inner_timestamp();
        (*net_signals)["LV_FLASH_RX"]["_timestamp"].push(pack->lv_flash_rx(i)._inner_timestamp());
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

    for(int i = 0; i < pack->hv_cellboard_version_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_cellboard_version(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_cellboard_version(i)._inner_timestamp();
        (*net_signals)["HV_CELLBOARD_VERSION"]["_timestamp"].push(pack->hv_cellboard_version(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["HV_CELLBOARD_VERSION"]["cellboard_id"].push(pack->hv_cellboard_version(i).cellboard_id());
		primary_hv_cellboard_version_cellboard_id_enum_to_string((primary_hv_cellboard_version_cellboard_id)pack->hv_cellboard_version(i).cellboard_id(), buffer);
		(*net_strings)["HV_CELLBOARD_VERSION"]["cellboard_id"].push(buffer);
		(*net_signals)["HV_CELLBOARD_VERSION"]["canlib_build_time"].push(pack->hv_cellboard_version(i).canlib_build_time());
		(*net_signals)["HV_CELLBOARD_VERSION"]["component_build_time"].push(pack->hv_cellboard_version(i).component_build_time());

    }

    for(int i = 0; i < pack->hv_errors_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_errors(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_errors(i)._inner_timestamp();
        (*net_signals)["HV_ERRORS"]["_timestamp"].push(pack->hv_errors(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["HV_ERRORS"]["errors_cell_under_voltage"].push(pack->hv_errors(i).errors_cell_under_voltage());
		(*net_enums)["HV_ERRORS"]["errors_cell_over_voltage"].push(pack->hv_errors(i).errors_cell_over_voltage());
		(*net_enums)["HV_ERRORS"]["errors_cell_under_temperature"].push(pack->hv_errors(i).errors_cell_under_temperature());
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
		(*net_enums)["HV_DEBUG_SIGNALS"]["errors_cell_under_voltage"].push(pack->hv_debug_signals(i).errors_cell_under_voltage());
		(*net_enums)["HV_DEBUG_SIGNALS"]["errors_cell_over_voltage"].push(pack->hv_debug_signals(i).errors_cell_over_voltage());
		(*net_enums)["HV_DEBUG_SIGNALS"]["errors_cell_under_temperature"].push(pack->hv_debug_signals(i).errors_cell_under_temperature());
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

    for(int i = 0; i < pack->hv_set_fans_status_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_set_fans_status(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_set_fans_status(i)._inner_timestamp();
        (*net_signals)["HV_SET_FANS_STATUS"]["_timestamp"].push(pack->hv_set_fans_status(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["HV_SET_FANS_STATUS"]["fans_override"].push(pack->hv_set_fans_status(i).fans_override());
		primary_hv_set_fans_status_fans_override_enum_to_string((primary_hv_set_fans_status_fans_override)pack->hv_set_fans_status(i).fans_override(), buffer);
		(*net_strings)["HV_SET_FANS_STATUS"]["fans_override"].push(buffer);
		(*net_signals)["HV_SET_FANS_STATUS"]["fans_speed"].push(pack->hv_set_fans_status(i).fans_speed());

    }

    for(int i = 0; i < pack->hv_feedback_status_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_feedback_status(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_feedback_status(i)._inner_timestamp();
        (*net_signals)["HV_FEEDBACK_STATUS"]["_timestamp"].push(pack->hv_feedback_status(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["HV_FEEDBACK_STATUS"]["airn_open_com"].push(pack->hv_feedback_status(i).airn_open_com());
		primary_hv_feedback_status_airn_open_com_enum_to_string((primary_hv_feedback_status_airn_open_com)pack->hv_feedback_status(i).airn_open_com(), buffer);
		(*net_strings)["HV_FEEDBACK_STATUS"]["airn_open_com"].push(buffer);
		(*net_enums)["HV_FEEDBACK_STATUS"]["precharge_open_com"].push(pack->hv_feedback_status(i).precharge_open_com());
		primary_hv_feedback_status_precharge_open_com_enum_to_string((primary_hv_feedback_status_precharge_open_com)pack->hv_feedback_status(i).precharge_open_com(), buffer);
		(*net_strings)["HV_FEEDBACK_STATUS"]["precharge_open_com"].push(buffer);
		(*net_enums)["HV_FEEDBACK_STATUS"]["airp_open_com"].push(pack->hv_feedback_status(i).airp_open_com());
		primary_hv_feedback_status_airp_open_com_enum_to_string((primary_hv_feedback_status_airp_open_com)pack->hv_feedback_status(i).airp_open_com(), buffer);
		(*net_strings)["HV_FEEDBACK_STATUS"]["airp_open_com"].push(buffer);
		(*net_enums)["HV_FEEDBACK_STATUS"]["airn_open_mec"].push(pack->hv_feedback_status(i).airn_open_mec());
		primary_hv_feedback_status_airn_open_mec_enum_to_string((primary_hv_feedback_status_airn_open_mec)pack->hv_feedback_status(i).airn_open_mec(), buffer);
		(*net_strings)["HV_FEEDBACK_STATUS"]["airn_open_mec"].push(buffer);
		(*net_enums)["HV_FEEDBACK_STATUS"]["precharge_open_mec"].push(pack->hv_feedback_status(i).precharge_open_mec());
		primary_hv_feedback_status_precharge_open_mec_enum_to_string((primary_hv_feedback_status_precharge_open_mec)pack->hv_feedback_status(i).precharge_open_mec(), buffer);
		(*net_strings)["HV_FEEDBACK_STATUS"]["precharge_open_mec"].push(buffer);
		(*net_enums)["HV_FEEDBACK_STATUS"]["airp_open_mec"].push(pack->hv_feedback_status(i).airp_open_mec());
		primary_hv_feedback_status_airp_open_mec_enum_to_string((primary_hv_feedback_status_airp_open_mec)pack->hv_feedback_status(i).airp_open_mec(), buffer);
		(*net_strings)["HV_FEEDBACK_STATUS"]["airp_open_mec"].push(buffer);
		(*net_enums)["HV_FEEDBACK_STATUS"]["sd_imd_fb"].push(pack->hv_feedback_status(i).sd_imd_fb());
		primary_hv_feedback_status_sd_imd_fb_enum_to_string((primary_hv_feedback_status_sd_imd_fb)pack->hv_feedback_status(i).sd_imd_fb(), buffer);
		(*net_strings)["HV_FEEDBACK_STATUS"]["sd_imd_fb"].push(buffer);
		(*net_enums)["HV_FEEDBACK_STATUS"]["sd_bms_fb"].push(pack->hv_feedback_status(i).sd_bms_fb());
		primary_hv_feedback_status_sd_bms_fb_enum_to_string((primary_hv_feedback_status_sd_bms_fb)pack->hv_feedback_status(i).sd_bms_fb(), buffer);
		(*net_strings)["HV_FEEDBACK_STATUS"]["sd_bms_fb"].push(buffer);
		(*net_enums)["HV_FEEDBACK_STATUS"]["ts_less_than_60v"].push(pack->hv_feedback_status(i).ts_less_than_60v());
		primary_hv_feedback_status_ts_less_than_60v_enum_to_string((primary_hv_feedback_status_ts_less_than_60v)pack->hv_feedback_status(i).ts_less_than_60v(), buffer);
		(*net_strings)["HV_FEEDBACK_STATUS"]["ts_less_than_60v"].push(buffer);
		(*net_enums)["HV_FEEDBACK_STATUS"]["plausible_state_persisted"].push(pack->hv_feedback_status(i).plausible_state_persisted());
		primary_hv_feedback_status_plausible_state_persisted_enum_to_string((primary_hv_feedback_status_plausible_state_persisted)pack->hv_feedback_status(i).plausible_state_persisted(), buffer);
		(*net_strings)["HV_FEEDBACK_STATUS"]["plausible_state_persisted"].push(buffer);
		(*net_enums)["HV_FEEDBACK_STATUS"]["plausible_state"].push(pack->hv_feedback_status(i).plausible_state());
		primary_hv_feedback_status_plausible_state_enum_to_string((primary_hv_feedback_status_plausible_state)pack->hv_feedback_status(i).plausible_state(), buffer);
		(*net_strings)["HV_FEEDBACK_STATUS"]["plausible_state"].push(buffer);
		(*net_enums)["HV_FEEDBACK_STATUS"]["not_bms_fault_cockpit_led"].push(pack->hv_feedback_status(i).not_bms_fault_cockpit_led());
		primary_hv_feedback_status_not_bms_fault_cockpit_led_enum_to_string((primary_hv_feedback_status_not_bms_fault_cockpit_led)pack->hv_feedback_status(i).not_bms_fault_cockpit_led(), buffer);
		(*net_strings)["HV_FEEDBACK_STATUS"]["not_bms_fault_cockpit_led"].push(buffer);
		(*net_enums)["HV_FEEDBACK_STATUS"]["not_imd_fault_cockpit_led"].push(pack->hv_feedback_status(i).not_imd_fault_cockpit_led());
		primary_hv_feedback_status_not_imd_fault_cockpit_led_enum_to_string((primary_hv_feedback_status_not_imd_fault_cockpit_led)pack->hv_feedback_status(i).not_imd_fault_cockpit_led(), buffer);
		(*net_strings)["HV_FEEDBACK_STATUS"]["not_imd_fault_cockpit_led"].push(buffer);
		(*net_enums)["HV_FEEDBACK_STATUS"]["indicator_connected"].push(pack->hv_feedback_status(i).indicator_connected());
		primary_hv_feedback_status_indicator_connected_enum_to_string((primary_hv_feedback_status_indicator_connected)pack->hv_feedback_status(i).indicator_connected(), buffer);
		(*net_strings)["HV_FEEDBACK_STATUS"]["indicator_connected"].push(buffer);
		(*net_enums)["HV_FEEDBACK_STATUS"]["not_latch_reset"].push(pack->hv_feedback_status(i).not_latch_reset());
		primary_hv_feedback_status_not_latch_reset_enum_to_string((primary_hv_feedback_status_not_latch_reset)pack->hv_feedback_status(i).not_latch_reset(), buffer);
		(*net_strings)["HV_FEEDBACK_STATUS"]["not_latch_reset"].push(buffer);
		(*net_enums)["HV_FEEDBACK_STATUS"]["plausible_state_latched"].push(pack->hv_feedback_status(i).plausible_state_latched());
		primary_hv_feedback_status_plausible_state_latched_enum_to_string((primary_hv_feedback_status_plausible_state_latched)pack->hv_feedback_status(i).plausible_state_latched(), buffer);
		(*net_strings)["HV_FEEDBACK_STATUS"]["plausible_state_latched"].push(buffer);
		(*net_enums)["HV_FEEDBACK_STATUS"]["not_bms_fault_latched"].push(pack->hv_feedback_status(i).not_bms_fault_latched());
		primary_hv_feedback_status_not_bms_fault_latched_enum_to_string((primary_hv_feedback_status_not_bms_fault_latched)pack->hv_feedback_status(i).not_bms_fault_latched(), buffer);
		(*net_strings)["HV_FEEDBACK_STATUS"]["not_bms_fault_latched"].push(buffer);
		(*net_enums)["HV_FEEDBACK_STATUS"]["not_imd_fault_latched"].push(pack->hv_feedback_status(i).not_imd_fault_latched());
		primary_hv_feedback_status_not_imd_fault_latched_enum_to_string((primary_hv_feedback_status_not_imd_fault_latched)pack->hv_feedback_status(i).not_imd_fault_latched(), buffer);
		(*net_strings)["HV_FEEDBACK_STATUS"]["not_imd_fault_latched"].push(buffer);
		(*net_enums)["HV_FEEDBACK_STATUS"]["not_ext_fault_latched"].push(pack->hv_feedback_status(i).not_ext_fault_latched());
		primary_hv_feedback_status_not_ext_fault_latched_enum_to_string((primary_hv_feedback_status_not_ext_fault_latched)pack->hv_feedback_status(i).not_ext_fault_latched(), buffer);
		(*net_strings)["HV_FEEDBACK_STATUS"]["not_ext_fault_latched"].push(buffer);
		(*net_enums)["HV_FEEDBACK_STATUS"]["imd_ok"].push(pack->hv_feedback_status(i).imd_ok());
		primary_hv_feedback_status_imd_ok_enum_to_string((primary_hv_feedback_status_imd_ok)pack->hv_feedback_status(i).imd_ok(), buffer);
		(*net_strings)["HV_FEEDBACK_STATUS"]["imd_ok"].push(buffer);
		(*net_enums)["HV_FEEDBACK_STATUS"]["plausible_state_rc"].push(pack->hv_feedback_status(i).plausible_state_rc());
		primary_hv_feedback_status_plausible_state_rc_enum_to_string((primary_hv_feedback_status_plausible_state_rc)pack->hv_feedback_status(i).plausible_state_rc(), buffer);
		(*net_strings)["HV_FEEDBACK_STATUS"]["plausible_state_rc"].push(buffer);
		(*net_enums)["HV_FEEDBACK_STATUS"]["tsal_green"].push(pack->hv_feedback_status(i).tsal_green());
		primary_hv_feedback_status_tsal_green_enum_to_string((primary_hv_feedback_status_tsal_green)pack->hv_feedback_status(i).tsal_green(), buffer);
		(*net_strings)["HV_FEEDBACK_STATUS"]["tsal_green"].push(buffer);
		(*net_enums)["HV_FEEDBACK_STATUS"]["probing_3v3"].push(pack->hv_feedback_status(i).probing_3v3());
		primary_hv_feedback_status_probing_3v3_enum_to_string((primary_hv_feedback_status_probing_3v3)pack->hv_feedback_status(i).probing_3v3(), buffer);
		(*net_strings)["HV_FEEDBACK_STATUS"]["probing_3v3"].push(buffer);
		(*net_enums)["HV_FEEDBACK_STATUS"]["sd_out"].push(pack->hv_feedback_status(i).sd_out());
		primary_hv_feedback_status_sd_out_enum_to_string((primary_hv_feedback_status_sd_out)pack->hv_feedback_status(i).sd_out(), buffer);
		(*net_strings)["HV_FEEDBACK_STATUS"]["sd_out"].push(buffer);
		(*net_enums)["HV_FEEDBACK_STATUS"]["sd_in"].push(pack->hv_feedback_status(i).sd_in());
		primary_hv_feedback_status_sd_in_enum_to_string((primary_hv_feedback_status_sd_in)pack->hv_feedback_status(i).sd_in(), buffer);
		(*net_strings)["HV_FEEDBACK_STATUS"]["sd_in"].push(buffer);
		(*net_enums)["HV_FEEDBACK_STATUS"]["sd_end"].push(pack->hv_feedback_status(i).sd_end());
		primary_hv_feedback_status_sd_end_enum_to_string((primary_hv_feedback_status_sd_end)pack->hv_feedback_status(i).sd_end(), buffer);
		(*net_strings)["HV_FEEDBACK_STATUS"]["sd_end"].push(buffer);
		(*net_enums)["HV_FEEDBACK_STATUS"]["v5_mcu"].push(pack->hv_feedback_status(i).v5_mcu());
		primary_hv_feedback_status_v5_mcu_enum_to_string((primary_hv_feedback_status_v5_mcu)pack->hv_feedback_status(i).v5_mcu(), buffer);
		(*net_strings)["HV_FEEDBACK_STATUS"]["v5_mcu"].push(buffer);
		(*net_enums)["HV_FEEDBACK_STATUS"]["feedback_tsal_green_fault_latched"].push(pack->hv_feedback_status(i).feedback_tsal_green_fault_latched());
		primary_hv_feedback_status_feedback_tsal_green_fault_latched_enum_to_string((primary_hv_feedback_status_feedback_tsal_green_fault_latched)pack->hv_feedback_status(i).feedback_tsal_green_fault_latched(), buffer);
		(*net_strings)["HV_FEEDBACK_STATUS"]["feedback_tsal_green_fault_latched"].push(buffer);
		(*net_enums)["HV_FEEDBACK_STATUS"]["feedback_ext_latched"].push(pack->hv_feedback_status(i).feedback_ext_latched());
		primary_hv_feedback_status_feedback_ext_latched_enum_to_string((primary_hv_feedback_status_feedback_ext_latched)pack->hv_feedback_status(i).feedback_ext_latched(), buffer);
		(*net_strings)["HV_FEEDBACK_STATUS"]["feedback_ext_latched"].push(buffer);
		(*net_enums)["HV_FEEDBACK_STATUS"]["feedback_precharge_status"].push(pack->hv_feedback_status(i).feedback_precharge_status());
		primary_hv_feedback_status_feedback_precharge_status_enum_to_string((primary_hv_feedback_status_feedback_precharge_status)pack->hv_feedback_status(i).feedback_precharge_status(), buffer);
		(*net_strings)["HV_FEEDBACK_STATUS"]["feedback_precharge_status"].push(buffer);
		(*net_enums)["HV_FEEDBACK_STATUS"]["feedback_tsp_over_60v_status"].push(pack->hv_feedback_status(i).feedback_tsp_over_60v_status());
		primary_hv_feedback_status_feedback_tsp_over_60v_status_enum_to_string((primary_hv_feedback_status_feedback_tsp_over_60v_status)pack->hv_feedback_status(i).feedback_tsp_over_60v_status(), buffer);
		(*net_strings)["HV_FEEDBACK_STATUS"]["feedback_tsp_over_60v_status"].push(buffer);
		(*net_enums)["HV_FEEDBACK_STATUS"]["feedback_check_mux"].push(pack->hv_feedback_status(i).feedback_check_mux());
		primary_hv_feedback_status_feedback_check_mux_enum_to_string((primary_hv_feedback_status_feedback_check_mux)pack->hv_feedback_status(i).feedback_check_mux(), buffer);
		(*net_strings)["HV_FEEDBACK_STATUS"]["feedback_check_mux"].push(buffer);

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

		(*net_enums)["HV_IMD_STATUS"]["status"].push(pack->hv_imd_status(i).status());
		primary_hv_imd_status_status_enum_to_string((primary_hv_imd_status_status)pack->hv_imd_status(i).status(), buffer);
		(*net_strings)["HV_IMD_STATUS"]["status"].push(buffer);
		(*net_signals)["HV_IMD_STATUS"]["frequency"].push(pack->hv_imd_status(i).frequency());
		(*net_signals)["HV_IMD_STATUS"]["duty_cycle"].push(pack->hv_imd_status(i).duty_cycle());
		(*net_enums)["HV_IMD_STATUS"]["feedback_not_imd_fault_cockpit_led"].push(pack->hv_imd_status(i).feedback_not_imd_fault_cockpit_led());
		primary_hv_imd_status_feedback_not_imd_fault_cockpit_led_enum_to_string((primary_hv_imd_status_feedback_not_imd_fault_cockpit_led)pack->hv_imd_status(i).feedback_not_imd_fault_cockpit_led(), buffer);
		(*net_strings)["HV_IMD_STATUS"]["feedback_not_imd_fault_cockpit_led"].push(buffer);
		(*net_enums)["HV_IMD_STATUS"]["feedback_not_imd_fault_latched"].push(pack->hv_imd_status(i).feedback_not_imd_fault_latched());
		primary_hv_imd_status_feedback_not_imd_fault_latched_enum_to_string((primary_hv_imd_status_feedback_not_imd_fault_latched)pack->hv_imd_status(i).feedback_not_imd_fault_latched(), buffer);
		(*net_strings)["HV_IMD_STATUS"]["feedback_not_imd_fault_latched"].push(buffer);
		(*net_enums)["HV_IMD_STATUS"]["imd_fault"].push(pack->hv_imd_status(i).imd_fault());
		(*net_signals)["HV_IMD_STATUS"]["imd_details"].push(pack->hv_imd_status(i).imd_details());
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
		(*net_enums)["HV_STATUS"]["cellboard_0"].push(pack->hv_status(i).cellboard_0());
		primary_hv_status_cellboard_0_enum_to_string((primary_hv_status_cellboard_0)pack->hv_status(i).cellboard_0(), buffer);
		(*net_strings)["HV_STATUS"]["cellboard_0"].push(buffer);
		(*net_enums)["HV_STATUS"]["cellboard_1"].push(pack->hv_status(i).cellboard_1());
		primary_hv_status_cellboard_1_enum_to_string((primary_hv_status_cellboard_1)pack->hv_status(i).cellboard_1(), buffer);
		(*net_strings)["HV_STATUS"]["cellboard_1"].push(buffer);
		(*net_enums)["HV_STATUS"]["cellboard_2"].push(pack->hv_status(i).cellboard_2());
		primary_hv_status_cellboard_2_enum_to_string((primary_hv_status_cellboard_2)pack->hv_status(i).cellboard_2(), buffer);
		(*net_strings)["HV_STATUS"]["cellboard_2"].push(buffer);
		(*net_enums)["HV_STATUS"]["cellboard_3"].push(pack->hv_status(i).cellboard_3());
		primary_hv_status_cellboard_3_enum_to_string((primary_hv_status_cellboard_3)pack->hv_status(i).cellboard_3(), buffer);
		(*net_strings)["HV_STATUS"]["cellboard_3"].push(buffer);
		(*net_enums)["HV_STATUS"]["cellboard_4"].push(pack->hv_status(i).cellboard_4());
		primary_hv_status_cellboard_4_enum_to_string((primary_hv_status_cellboard_4)pack->hv_status(i).cellboard_4(), buffer);
		(*net_strings)["HV_STATUS"]["cellboard_4"].push(buffer);
		(*net_enums)["HV_STATUS"]["cellboard_5"].push(pack->hv_status(i).cellboard_5());
		primary_hv_status_cellboard_5_enum_to_string((primary_hv_status_cellboard_5)pack->hv_status(i).cellboard_5(), buffer);
		(*net_strings)["HV_STATUS"]["cellboard_5"].push(buffer);

    }

    for(int i = 0; i < pack->hv_set_status_ecu_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_set_status_ecu(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_set_status_ecu(i)._inner_timestamp();
        (*net_signals)["HV_SET_STATUS_ECU"]["_timestamp"].push(pack->hv_set_status_ecu(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["HV_SET_STATUS_ECU"]["status"].push(pack->hv_set_status_ecu(i).status());
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

		(*net_enums)["HV_SET_STATUS_HANDCART"]["status"].push(pack->hv_set_status_handcart(i).status());
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
		(*net_enums)["HV_BALANCING_STATUS"]["status"].push(pack->hv_balancing_status(i).status());
		primary_hv_balancing_status_status_enum_to_string((primary_hv_balancing_status_status)pack->hv_balancing_status(i).status(), buffer);
		(*net_strings)["HV_BALANCING_STATUS"]["status"].push(buffer);
		(*net_enums)["HV_BALANCING_STATUS"]["discharging_cell_0"].push(pack->hv_balancing_status(i).discharging_cell_0());
		(*net_enums)["HV_BALANCING_STATUS"]["discharging_cell_1"].push(pack->hv_balancing_status(i).discharging_cell_1());
		(*net_enums)["HV_BALANCING_STATUS"]["discharging_cell_2"].push(pack->hv_balancing_status(i).discharging_cell_2());
		(*net_enums)["HV_BALANCING_STATUS"]["discharging_cell_3"].push(pack->hv_balancing_status(i).discharging_cell_3());
		(*net_enums)["HV_BALANCING_STATUS"]["discharging_cell_4"].push(pack->hv_balancing_status(i).discharging_cell_4());
		(*net_enums)["HV_BALANCING_STATUS"]["discharging_cell_5"].push(pack->hv_balancing_status(i).discharging_cell_5());
		(*net_enums)["HV_BALANCING_STATUS"]["discharging_cell_6"].push(pack->hv_balancing_status(i).discharging_cell_6());
		(*net_enums)["HV_BALANCING_STATUS"]["discharging_cell_7"].push(pack->hv_balancing_status(i).discharging_cell_7());
		(*net_enums)["HV_BALANCING_STATUS"]["discharging_cell_8"].push(pack->hv_balancing_status(i).discharging_cell_8());
		(*net_enums)["HV_BALANCING_STATUS"]["discharging_cell_9"].push(pack->hv_balancing_status(i).discharging_cell_9());
		(*net_enums)["HV_BALANCING_STATUS"]["discharging_cell_10"].push(pack->hv_balancing_status(i).discharging_cell_10());
		(*net_enums)["HV_BALANCING_STATUS"]["discharging_cell_11"].push(pack->hv_balancing_status(i).discharging_cell_11());
		(*net_enums)["HV_BALANCING_STATUS"]["discharging_cell_12"].push(pack->hv_balancing_status(i).discharging_cell_12());
		(*net_enums)["HV_BALANCING_STATUS"]["discharging_cell_13"].push(pack->hv_balancing_status(i).discharging_cell_13());
		(*net_enums)["HV_BALANCING_STATUS"]["discharging_cell_14"].push(pack->hv_balancing_status(i).discharging_cell_14());
		(*net_enums)["HV_BALANCING_STATUS"]["discharging_cell_15"].push(pack->hv_balancing_status(i).discharging_cell_15());
		(*net_enums)["HV_BALANCING_STATUS"]["discharging_cell_16"].push(pack->hv_balancing_status(i).discharging_cell_16());
		(*net_enums)["HV_BALANCING_STATUS"]["discharging_cell_17"].push(pack->hv_balancing_status(i).discharging_cell_17());
		(*net_enums)["HV_BALANCING_STATUS"]["discharging_cell_18"].push(pack->hv_balancing_status(i).discharging_cell_18());
		(*net_enums)["HV_BALANCING_STATUS"]["discharging_cell_19"].push(pack->hv_balancing_status(i).discharging_cell_19());
		(*net_enums)["HV_BALANCING_STATUS"]["discharging_cell_20"].push(pack->hv_balancing_status(i).discharging_cell_20());
		(*net_enums)["HV_BALANCING_STATUS"]["discharging_cell_21"].push(pack->hv_balancing_status(i).discharging_cell_21());
		(*net_enums)["HV_BALANCING_STATUS"]["discharging_cell_22"].push(pack->hv_balancing_status(i).discharging_cell_22());
		(*net_enums)["HV_BALANCING_STATUS"]["discharging_cell_23"].push(pack->hv_balancing_status(i).discharging_cell_23());

    }

    for(int i = 0; i < pack->hv_set_balancing_status_steering_wheel_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_set_balancing_status_steering_wheel(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_set_balancing_status_steering_wheel(i)._inner_timestamp();
        (*net_signals)["HV_SET_BALANCING_STATUS_STEERING_WHEEL"]["_timestamp"].push(pack->hv_set_balancing_status_steering_wheel(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["HV_SET_BALANCING_STATUS_STEERING_WHEEL"]["status"].push(pack->hv_set_balancing_status_steering_wheel(i).status());
		(*net_signals)["HV_SET_BALANCING_STATUS_STEERING_WHEEL"]["threshold"].push(pack->hv_set_balancing_status_steering_wheel(i).threshold());
		(*net_enums)["HV_SET_BALANCING_STATUS_STEERING_WHEEL"]["set_balancing_status"].push(pack->hv_set_balancing_status_steering_wheel(i).set_balancing_status());
		primary_hv_set_balancing_status_steering_wheel_set_balancing_status_enum_to_string((primary_hv_set_balancing_status_steering_wheel_set_balancing_status)pack->hv_set_balancing_status_steering_wheel(i).set_balancing_status(), buffer);
		(*net_strings)["HV_SET_BALANCING_STATUS_STEERING_WHEEL"]["set_balancing_status"].push(buffer);
		(*net_signals)["HV_SET_BALANCING_STATUS_STEERING_WHEEL"]["balancing_threshold"].push(pack->hv_set_balancing_status_steering_wheel(i).balancing_threshold());

    }

    for(int i = 0; i < pack->hv_set_balancing_status_handcart_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_set_balancing_status_handcart(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_set_balancing_status_handcart(i)._inner_timestamp();
        (*net_signals)["HV_SET_BALANCING_STATUS_HANDCART"]["_timestamp"].push(pack->hv_set_balancing_status_handcart(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["HV_SET_BALANCING_STATUS_HANDCART"]["status"].push(pack->hv_set_balancing_status_handcart(i).status());
		(*net_signals)["HV_SET_BALANCING_STATUS_HANDCART"]["threshold"].push(pack->hv_set_balancing_status_handcart(i).threshold());
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

    for(int i = 0; i < pack->lv_charging_status_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->lv_charging_status(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->lv_charging_status(i)._inner_timestamp();
        (*net_signals)["LV_CHARGING_STATUS"]["_timestamp"].push(pack->lv_charging_status(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["LV_CHARGING_STATUS"]["status"].push(pack->lv_charging_status(i).status());
		primary_lv_charging_status_status_enum_to_string((primary_lv_charging_status_status)pack->lv_charging_status(i).status(), buffer);
		(*net_strings)["LV_CHARGING_STATUS"]["status"].push(buffer);

    }

    for(int i = 0; i < pack->lv_cooling_aggressiveness_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->lv_cooling_aggressiveness(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->lv_cooling_aggressiveness(i)._inner_timestamp();
        (*net_signals)["LV_COOLING_AGGRESSIVENESS"]["_timestamp"].push(pack->lv_cooling_aggressiveness(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["LV_COOLING_AGGRESSIVENESS"]["status"].push(pack->lv_cooling_aggressiveness(i).status());
		primary_lv_cooling_aggressiveness_status_enum_to_string((primary_lv_cooling_aggressiveness_status)pack->lv_cooling_aggressiveness(i).status(), buffer);
		(*net_strings)["LV_COOLING_AGGRESSIVENESS"]["status"].push(buffer);

    }

    for(int i = 0; i < pack->lv_set_cooling_aggressiveness_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->lv_set_cooling_aggressiveness(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->lv_set_cooling_aggressiveness(i)._inner_timestamp();
        (*net_signals)["LV_SET_COOLING_AGGRESSIVENESS"]["_timestamp"].push(pack->lv_set_cooling_aggressiveness(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["LV_SET_COOLING_AGGRESSIVENESS"]["status"].push(pack->lv_set_cooling_aggressiveness(i).status());
		primary_lv_set_cooling_aggressiveness_status_enum_to_string((primary_lv_set_cooling_aggressiveness_status)pack->lv_set_cooling_aggressiveness(i).status(), buffer);
		(*net_strings)["LV_SET_COOLING_AGGRESSIVENESS"]["status"].push(buffer);

    }

    for(int i = 0; i < pack->lv_radiator_speed_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->lv_radiator_speed(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->lv_radiator_speed(i)._inner_timestamp();
        (*net_signals)["LV_RADIATOR_SPEED"]["_timestamp"].push(pack->lv_radiator_speed(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["LV_RADIATOR_SPEED"]["status"].push(pack->lv_radiator_speed(i).status());
		primary_lv_radiator_speed_status_enum_to_string((primary_lv_radiator_speed_status)pack->lv_radiator_speed(i).status(), buffer);
		(*net_strings)["LV_RADIATOR_SPEED"]["status"].push(buffer);
		(*net_signals)["LV_RADIATOR_SPEED"]["radiator_speed"].push(pack->lv_radiator_speed(i).radiator_speed());

    }

    for(int i = 0; i < pack->lv_pumps_speed_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->lv_pumps_speed(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->lv_pumps_speed(i)._inner_timestamp();
        (*net_signals)["LV_PUMPS_SPEED"]["_timestamp"].push(pack->lv_pumps_speed(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["LV_PUMPS_SPEED"]["status"].push(pack->lv_pumps_speed(i).status());
		primary_lv_pumps_speed_status_enum_to_string((primary_lv_pumps_speed_status)pack->lv_pumps_speed(i).status(), buffer);
		(*net_strings)["LV_PUMPS_SPEED"]["status"].push(buffer);
		(*net_signals)["LV_PUMPS_SPEED"]["pumps_speed"].push(pack->lv_pumps_speed(i).pumps_speed());

    }

    for(int i = 0; i < pack->lv_set_radiator_speed_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->lv_set_radiator_speed(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->lv_set_radiator_speed(i)._inner_timestamp();
        (*net_signals)["LV_SET_RADIATOR_SPEED"]["_timestamp"].push(pack->lv_set_radiator_speed(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["LV_SET_RADIATOR_SPEED"]["status"].push(pack->lv_set_radiator_speed(i).status());
		primary_lv_set_radiator_speed_status_enum_to_string((primary_lv_set_radiator_speed_status)pack->lv_set_radiator_speed(i).status(), buffer);
		(*net_strings)["LV_SET_RADIATOR_SPEED"]["status"].push(buffer);
		(*net_signals)["LV_SET_RADIATOR_SPEED"]["radiator_speed"].push(pack->lv_set_radiator_speed(i).radiator_speed());

    }

    for(int i = 0; i < pack->lv_set_pumps_speed_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->lv_set_pumps_speed(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->lv_set_pumps_speed(i)._inner_timestamp();
        (*net_signals)["LV_SET_PUMPS_SPEED"]["_timestamp"].push(pack->lv_set_pumps_speed(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["LV_SET_PUMPS_SPEED"]["status"].push(pack->lv_set_pumps_speed(i).status());
		primary_lv_set_pumps_speed_status_enum_to_string((primary_lv_set_pumps_speed_status)pack->lv_set_pumps_speed(i).status(), buffer);
		(*net_strings)["LV_SET_PUMPS_SPEED"]["status"].push(buffer);
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

    for(int i = 0; i < pack->lv_feedback_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->lv_feedback(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->lv_feedback(i)._inner_timestamp();
        (*net_signals)["LV_FEEDBACK"]["_timestamp"].push(pack->lv_feedback(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["LV_FEEDBACK"]["feedbacks_bspd"].push(pack->lv_feedback(i).feedbacks_bspd());
		(*net_enums)["LV_FEEDBACK"]["feedbacks_hvd"].push(pack->lv_feedback(i).feedbacks_hvd());
		(*net_enums)["LV_FEEDBACK"]["feedbacks_invc_interlock"].push(pack->lv_feedback(i).feedbacks_invc_interlock());
		(*net_enums)["LV_FEEDBACK"]["feedbacks_ams"].push(pack->lv_feedback(i).feedbacks_ams());
		(*net_enums)["LV_FEEDBACK"]["feedbacks_sd_end"].push(pack->lv_feedback(i).feedbacks_sd_end());
		(*net_enums)["LV_FEEDBACK"]["feedbacks_lvms"].push(pack->lv_feedback(i).feedbacks_lvms());
		(*net_enums)["LV_FEEDBACK"]["feedbacks_interlock"].push(pack->lv_feedback(i).feedbacks_interlock());
		(*net_enums)["LV_FEEDBACK"]["feedbacks_sd_start"].push(pack->lv_feedback(i).feedbacks_sd_start());

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
		(*net_enums)["LV_FEEDBACK_GPIO_EXTENDER"]["feedback_rfe"].push(pack->lv_feedback_gpio_extender(i).feedback_rfe());
		(*net_enums)["LV_FEEDBACK_GPIO_EXTENDER"]["feedback_frg"].push(pack->lv_feedback_gpio_extender(i).feedback_frg());
		(*net_enums)["LV_FEEDBACK_GPIO_EXTENDER"]["feedback_discharge"].push(pack->lv_feedback_gpio_extender(i).feedback_discharge());

    }

    for(int i = 0; i < pack->lv_can_flash_req_tlm_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->lv_can_flash_req_tlm(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->lv_can_flash_req_tlm(i)._inner_timestamp();
        (*net_signals)["LV_CAN_FLASH_REQ_TLM"]["_timestamp"].push(pack->lv_can_flash_req_tlm(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP


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
		(*net_enums)["ECU_CONTROL_STATUS"]["control_errors_disabled_from_ecu"].push(pack->ecu_control_status(i).control_errors_disabled_from_ecu());
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
		(*net_enums)["ECU_ERRORS"]["error_bspd_limits"].push(pack->ecu_errors(i).error_bspd_limits());
		(*net_enums)["ECU_ERRORS"]["error_no_brake_to_rtd"].push(pack->ecu_errors(i).error_no_brake_to_rtd());

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

		(*net_signals)["ECU_POWER_MAPS"]["map_power"].push(pack->ecu_power_maps(i).map_power());
		(*net_enums)["ECU_POWER_MAPS"]["sc_state"].push(pack->ecu_power_maps(i).sc_state());
		primary_ecu_power_maps_sc_state_enum_to_string((primary_ecu_power_maps_sc_state)pack->ecu_power_maps(i).sc_state(), buffer);
		(*net_strings)["ECU_POWER_MAPS"]["sc_state"].push(buffer);
		(*net_enums)["ECU_POWER_MAPS"]["tv_state"].push(pack->ecu_power_maps(i).tv_state());
		primary_ecu_power_maps_tv_state_enum_to_string((primary_ecu_power_maps_tv_state)pack->ecu_power_maps(i).tv_state(), buffer);
		(*net_strings)["ECU_POWER_MAPS"]["tv_state"].push(buffer);
		(*net_enums)["ECU_POWER_MAPS"]["reg_state"].push(pack->ecu_power_maps(i).reg_state());
		primary_ecu_power_maps_reg_state_enum_to_string((primary_ecu_power_maps_reg_state)pack->ecu_power_maps(i).reg_state(), buffer);
		(*net_strings)["ECU_POWER_MAPS"]["reg_state"].push(buffer);

    }

    for(int i = 0; i < pack->ecu_set_power_maps_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->ecu_set_power_maps(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->ecu_set_power_maps(i)._inner_timestamp();
        (*net_signals)["ECU_SET_POWER_MAPS"]["_timestamp"].push(pack->ecu_set_power_maps(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["ECU_SET_POWER_MAPS"]["map_power"].push(pack->ecu_set_power_maps(i).map_power());
		(*net_enums)["ECU_SET_POWER_MAPS"]["sc_state"].push(pack->ecu_set_power_maps(i).sc_state());
		primary_ecu_set_power_maps_sc_state_enum_to_string((primary_ecu_set_power_maps_sc_state)pack->ecu_set_power_maps(i).sc_state(), buffer);
		(*net_strings)["ECU_SET_POWER_MAPS"]["sc_state"].push(buffer);
		(*net_enums)["ECU_SET_POWER_MAPS"]["tv_state"].push(pack->ecu_set_power_maps(i).tv_state());
		primary_ecu_set_power_maps_tv_state_enum_to_string((primary_ecu_set_power_maps_tv_state)pack->ecu_set_power_maps(i).tv_state(), buffer);
		(*net_strings)["ECU_SET_POWER_MAPS"]["tv_state"].push(buffer);
		(*net_enums)["ECU_SET_POWER_MAPS"]["reg_state"].push(pack->ecu_set_power_maps(i).reg_state());
		primary_ecu_set_power_maps_reg_state_enum_to_string((primary_ecu_set_power_maps_reg_state)pack->ecu_set_power_maps(i).reg_state(), buffer);
		(*net_strings)["ECU_SET_POWER_MAPS"]["reg_state"].push(buffer);

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

		(*net_signals)["CONTROL_STATUS"]["map_power"].push(pack->control_status(i).map_power());
		(*net_enums)["CONTROL_STATUS"]["sc_state"].push(pack->control_status(i).sc_state());
		primary_control_status_sc_state_enum_to_string((primary_control_status_sc_state)pack->control_status(i).sc_state(), buffer);
		(*net_strings)["CONTROL_STATUS"]["sc_state"].push(buffer);
		(*net_enums)["CONTROL_STATUS"]["tv_state"].push(pack->control_status(i).tv_state());
		primary_control_status_tv_state_enum_to_string((primary_control_status_tv_state)pack->control_status(i).tv_state(), buffer);
		(*net_strings)["CONTROL_STATUS"]["tv_state"].push(buffer);
		(*net_enums)["CONTROL_STATUS"]["reg_state"].push(pack->control_status(i).reg_state());
		primary_control_status_reg_state_enum_to_string((primary_control_status_reg_state)pack->control_status(i).reg_state(), buffer);
		(*net_strings)["CONTROL_STATUS"]["reg_state"].push(buffer);

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

		(*net_enums)["HV_CELLS_VOLTAGE"]["cellboard_id"].push(pack->hv_cells_voltage(i).cellboard_id());
		primary_hv_cells_voltage_cellboard_id_enum_to_string((primary_hv_cells_voltage_cellboard_id)pack->hv_cells_voltage(i).cellboard_id(), buffer);
		(*net_strings)["HV_CELLS_VOLTAGE"]["cellboard_id"].push(buffer);
		(*net_signals)["HV_CELLS_VOLTAGE"]["offset"].push(pack->hv_cells_voltage(i).offset());
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
		(*net_signals)["HV_CELLS_VOLTAGE_STATS"]["delta"].push(pack->hv_cells_voltage_stats(i).delta());
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

    for(int i = 0; i < pack->ecu_steer_actuator_status_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->ecu_steer_actuator_status(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->ecu_steer_actuator_status(i)._inner_timestamp();
        (*net_signals)["ECU_STEER_ACTUATOR_STATUS"]["_timestamp"].push(pack->ecu_steer_actuator_status(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["ECU_STEER_ACTUATOR_STATUS"]["status"].push(pack->ecu_steer_actuator_status(i).status());
		primary_ecu_steer_actuator_status_status_enum_to_string((primary_ecu_steer_actuator_status_status)pack->ecu_steer_actuator_status(i).status(), buffer);
		(*net_strings)["ECU_STEER_ACTUATOR_STATUS"]["status"].push(buffer);

    }

    for(int i = 0; i < pack->ecu_set_steer_actuator_status_steering_wheel_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->ecu_set_steer_actuator_status_steering_wheel(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->ecu_set_steer_actuator_status_steering_wheel(i)._inner_timestamp();
        (*net_signals)["ECU_SET_STEER_ACTUATOR_STATUS_STEERING_WHEEL"]["_timestamp"].push(pack->ecu_set_steer_actuator_status_steering_wheel(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["ECU_SET_STEER_ACTUATOR_STATUS_STEERING_WHEEL"]["status"].push(pack->ecu_set_steer_actuator_status_steering_wheel(i).status());
		primary_ecu_set_steer_actuator_status_steering_wheel_status_enum_to_string((primary_ecu_set_steer_actuator_status_steering_wheel_status)pack->ecu_set_steer_actuator_status_steering_wheel(i).status(), buffer);
		(*net_strings)["ECU_SET_STEER_ACTUATOR_STATUS_STEERING_WHEEL"]["status"].push(buffer);

    }

    for(int i = 0; i < pack->ecu_set_steer_actuator_status_tlm_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->ecu_set_steer_actuator_status_tlm(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->ecu_set_steer_actuator_status_tlm(i)._inner_timestamp();
        (*net_signals)["ECU_SET_STEER_ACTUATOR_STATUS_TLM"]["_timestamp"].push(pack->ecu_set_steer_actuator_status_tlm(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["ECU_SET_STEER_ACTUATOR_STATUS_TLM"]["status"].push(pack->ecu_set_steer_actuator_status_tlm(i).status());
		primary_ecu_set_steer_actuator_status_tlm_status_enum_to_string((primary_ecu_set_steer_actuator_status_tlm_status)pack->ecu_set_steer_actuator_status_tlm(i).status(), buffer);
		(*net_strings)["ECU_SET_STEER_ACTUATOR_STATUS_TLM"]["status"].push(buffer);

    }

    for(int i = 0; i < pack->ecu_set_steer_actuator_angle_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->ecu_set_steer_actuator_angle(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->ecu_set_steer_actuator_angle(i)._inner_timestamp();
        (*net_signals)["ECU_SET_STEER_ACTUATOR_ANGLE"]["_timestamp"].push(pack->ecu_set_steer_actuator_angle(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["ECU_SET_STEER_ACTUATOR_ANGLE"]["angle"].push(pack->ecu_set_steer_actuator_angle(i).angle());

    }

    for(int i = 0; i < pack->ecu_steer_actuator_current_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->ecu_steer_actuator_current(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->ecu_steer_actuator_current(i)._inner_timestamp();
        (*net_signals)["ECU_STEER_ACTUATOR_CURRENT"]["_timestamp"].push(pack->ecu_steer_actuator_current(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["ECU_STEER_ACTUATOR_CURRENT"]["current"].push(pack->ecu_steer_actuator_current(i).current());

    }

    for(int i = 0; i < pack->debug_signal_crash_debug_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->debug_signal_crash_debug(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->debug_signal_crash_debug(i)._inner_timestamp();
        (*net_signals)["DEBUG_SIGNAL_CRASH_DEBUG"]["_timestamp"].push(pack->debug_signal_crash_debug(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["DEBUG_SIGNAL_CRASH_DEBUG"]["seq_number"].push(pack->debug_signal_crash_debug(i).seq_number());
		(*net_signals)["DEBUG_SIGNAL_CRASH_DEBUG"]["byte_1"].push(pack->debug_signal_crash_debug(i).byte_1());
		(*net_signals)["DEBUG_SIGNAL_CRASH_DEBUG"]["byte_2"].push(pack->debug_signal_crash_debug(i).byte_2());
		(*net_signals)["DEBUG_SIGNAL_CRASH_DEBUG"]["byte_3"].push(pack->debug_signal_crash_debug(i).byte_3());
		(*net_signals)["DEBUG_SIGNAL_CRASH_DEBUG"]["byte_4"].push(pack->debug_signal_crash_debug(i).byte_4());
		(*net_signals)["DEBUG_SIGNAL_CRASH_DEBUG"]["byte_5"].push(pack->debug_signal_crash_debug(i).byte_5());
		(*net_signals)["DEBUG_SIGNAL_CRASH_DEBUG"]["byte_6"].push(pack->debug_signal_crash_debug(i).byte_6());
		(*net_signals)["DEBUG_SIGNAL_CRASH_DEBUG"]["byte_7"].push(pack->debug_signal_crash_debug(i).byte_7());

    }

    for(int i = 0; i < pack->debug_signal_crash_debug_ack_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->debug_signal_crash_debug_ack(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->debug_signal_crash_debug_ack(i)._inner_timestamp();
        (*net_signals)["DEBUG_SIGNAL_CRASH_DEBUG_ACK"]["_timestamp"].push(pack->debug_signal_crash_debug_ack(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["DEBUG_SIGNAL_CRASH_DEBUG_ACK"]["seq_number"].push(pack->debug_signal_crash_debug_ack(i).seq_number());

    }

    for(int i = 0; i < pack->debug_signal_1_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->debug_signal_1(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->debug_signal_1(i)._inner_timestamp();
        (*net_signals)["DEBUG_SIGNAL_1"]["_timestamp"].push(pack->debug_signal_1(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["DEBUG_SIGNAL_1"]["device_id"].push(pack->debug_signal_1(i).device_id());
		primary_debug_signal_1_device_id_enum_to_string((primary_debug_signal_1_device_id)pack->debug_signal_1(i).device_id(), buffer);
		(*net_strings)["DEBUG_SIGNAL_1"]["device_id"].push(buffer);
		(*net_signals)["DEBUG_SIGNAL_1"]["field_1"].push(pack->debug_signal_1(i).field_1());
		(*net_signals)["DEBUG_SIGNAL_1"]["field_2"].push(pack->debug_signal_1(i).field_2());
		(*net_signals)["DEBUG_SIGNAL_1"]["field_3"].push(pack->debug_signal_1(i).field_3());

    }

    for(int i = 0; i < pack->debug_signal_2_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->debug_signal_2(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->debug_signal_2(i)._inner_timestamp();
        (*net_signals)["DEBUG_SIGNAL_2"]["_timestamp"].push(pack->debug_signal_2(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["DEBUG_SIGNAL_2"]["device_id"].push(pack->debug_signal_2(i).device_id());
		primary_debug_signal_2_device_id_enum_to_string((primary_debug_signal_2_device_id)pack->debug_signal_2(i).device_id(), buffer);
		(*net_strings)["DEBUG_SIGNAL_2"]["device_id"].push(buffer);
		(*net_signals)["DEBUG_SIGNAL_2"]["field_1"].push(pack->debug_signal_2(i).field_1());
		(*net_signals)["DEBUG_SIGNAL_2"]["field_2"].push(pack->debug_signal_2(i).field_2());
		(*net_signals)["DEBUG_SIGNAL_2"]["field_3"].push(pack->debug_signal_2(i).field_3());

    }

    for(int i = 0; i < pack->debug_signal_3_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->debug_signal_3(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->debug_signal_3(i)._inner_timestamp();
        (*net_signals)["DEBUG_SIGNAL_3"]["_timestamp"].push(pack->debug_signal_3(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["DEBUG_SIGNAL_3"]["device_id"].push(pack->debug_signal_3(i).device_id());
		primary_debug_signal_3_device_id_enum_to_string((primary_debug_signal_3_device_id)pack->debug_signal_3(i).device_id(), buffer);
		(*net_strings)["DEBUG_SIGNAL_3"]["device_id"].push(buffer);
		(*net_signals)["DEBUG_SIGNAL_3"]["field_1"].push(pack->debug_signal_3(i).field_1());
		(*net_signals)["DEBUG_SIGNAL_3"]["field_2"].push(pack->debug_signal_3(i).field_2());
		(*net_signals)["DEBUG_SIGNAL_3"]["field_3"].push(pack->debug_signal_3(i).field_3());

    }

    for(int i = 0; i < pack->debug_signal_4_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->debug_signal_4(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->debug_signal_4(i)._inner_timestamp();
        (*net_signals)["DEBUG_SIGNAL_4"]["_timestamp"].push(pack->debug_signal_4(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["DEBUG_SIGNAL_4"]["device_id"].push(pack->debug_signal_4(i).device_id());
		primary_debug_signal_4_device_id_enum_to_string((primary_debug_signal_4_device_id)pack->debug_signal_4(i).device_id(), buffer);
		(*net_strings)["DEBUG_SIGNAL_4"]["device_id"].push(buffer);
		(*net_signals)["DEBUG_SIGNAL_4"]["field_1"].push(pack->debug_signal_4(i).field_1());
		(*net_signals)["DEBUG_SIGNAL_4"]["field_2"].push(pack->debug_signal_4(i).field_2());
		(*net_signals)["DEBUG_SIGNAL_4"]["field_3"].push(pack->debug_signal_4(i).field_3());

    }

    for(int i = 0; i < pack->hv_flash_request_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_flash_request(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_flash_request(i)._inner_timestamp();
        (*net_signals)["HV_FLASH_REQUEST"]["_timestamp"].push(pack->hv_flash_request(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["HV_FLASH_REQUEST"]["mainboard"].push(pack->hv_flash_request(i).mainboard());
		(*net_enums)["HV_FLASH_REQUEST"]["cellboard_id"].push(pack->hv_flash_request(i).cellboard_id());
		primary_hv_flash_request_cellboard_id_enum_to_string((primary_hv_flash_request_cellboard_id)pack->hv_flash_request(i).cellboard_id(), buffer);
		(*net_strings)["HV_FLASH_REQUEST"]["cellboard_id"].push(buffer);

    }

    for(int i = 0; i < pack->hv_flash_response_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_flash_response(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_flash_response(i)._inner_timestamp();
        (*net_signals)["HV_FLASH_RESPONSE"]["_timestamp"].push(pack->hv_flash_response(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["HV_FLASH_RESPONSE"]["ready"].push(pack->hv_flash_response(i).ready());

    }

    for(int i = 0; i < pack->hv_ts_voltage_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_ts_voltage(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_ts_voltage(i)._inner_timestamp();
        (*net_signals)["HV_TS_VOLTAGE"]["_timestamp"].push(pack->hv_ts_voltage(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["HV_TS_VOLTAGE"]["ts"].push(pack->hv_ts_voltage(i).ts());
		(*net_signals)["HV_TS_VOLTAGE"]["pack"].push(pack->hv_ts_voltage(i).pack());
		(*net_signals)["HV_TS_VOLTAGE"]["cells_sum"].push(pack->hv_ts_voltage(i).cells_sum());

    }

    for(int i = 0; i < pack->hv_cells_temperature_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_cells_temperature(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_cells_temperature(i)._inner_timestamp();
        (*net_signals)["HV_CELLS_TEMPERATURE"]["_timestamp"].push(pack->hv_cells_temperature(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["HV_CELLS_TEMPERATURE"]["cellboard_id"].push(pack->hv_cells_temperature(i).cellboard_id());
		primary_hv_cells_temperature_cellboard_id_enum_to_string((primary_hv_cells_temperature_cellboard_id)pack->hv_cells_temperature(i).cellboard_id(), buffer);
		(*net_strings)["HV_CELLS_TEMPERATURE"]["cellboard_id"].push(buffer);
		(*net_signals)["HV_CELLS_TEMPERATURE"]["temperature_id_0"].push(pack->hv_cells_temperature(i).temperature_id_0());
		(*net_signals)["HV_CELLS_TEMPERATURE"]["temperature_id_1"].push(pack->hv_cells_temperature(i).temperature_id_1());
		(*net_signals)["HV_CELLS_TEMPERATURE"]["temperature_id_2"].push(pack->hv_cells_temperature(i).temperature_id_2());
		(*net_signals)["HV_CELLS_TEMPERATURE"]["temperature_id_3"].push(pack->hv_cells_temperature(i).temperature_id_3());
		(*net_signals)["HV_CELLS_TEMPERATURE"]["temperature_0"].push(pack->hv_cells_temperature(i).temperature_0());
		(*net_signals)["HV_CELLS_TEMPERATURE"]["temperature_1"].push(pack->hv_cells_temperature(i).temperature_1());
		(*net_signals)["HV_CELLS_TEMPERATURE"]["temperature_2"].push(pack->hv_cells_temperature(i).temperature_2());
		(*net_signals)["HV_CELLS_TEMPERATURE"]["temperature_3"].push(pack->hv_cells_temperature(i).temperature_3());

    }

    for(int i = 0; i < pack->charger_1_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->charger_1(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->charger_1(i)._inner_timestamp();
        (*net_signals)["CHARGER_1"]["_timestamp"].push(pack->charger_1(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["CHARGER_1"]["data_0"].push(pack->charger_1(i).data_0());
		(*net_signals)["CHARGER_1"]["data_1"].push(pack->charger_1(i).data_1());
		(*net_signals)["CHARGER_1"]["data_2"].push(pack->charger_1(i).data_2());
		(*net_signals)["CHARGER_1"]["data_3"].push(pack->charger_1(i).data_3());
		(*net_signals)["CHARGER_1"]["data_4"].push(pack->charger_1(i).data_4());
		(*net_signals)["CHARGER_1"]["data_5"].push(pack->charger_1(i).data_5());
		(*net_signals)["CHARGER_1"]["data_6"].push(pack->charger_1(i).data_6());
		(*net_signals)["CHARGER_1"]["data_7"].push(pack->charger_1(i).data_7());

    }

    for(int i = 0; i < pack->charger_2_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->charger_2(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->charger_2(i)._inner_timestamp();
        (*net_signals)["CHARGER_2"]["_timestamp"].push(pack->charger_2(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["CHARGER_2"]["data_0"].push(pack->charger_2(i).data_0());
		(*net_signals)["CHARGER_2"]["data_1"].push(pack->charger_2(i).data_1());
		(*net_signals)["CHARGER_2"]["data_2"].push(pack->charger_2(i).data_2());
		(*net_signals)["CHARGER_2"]["data_3"].push(pack->charger_2(i).data_3());
		(*net_signals)["CHARGER_2"]["data_4"].push(pack->charger_2(i).data_4());
		(*net_signals)["CHARGER_2"]["data_5"].push(pack->charger_2(i).data_5());
		(*net_signals)["CHARGER_2"]["data_6"].push(pack->charger_2(i).data_6());
		(*net_signals)["CHARGER_2"]["data_7"].push(pack->charger_2(i).data_7());

    }

    for(int i = 0; i < pack->charger_3_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->charger_3(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->charger_3(i)._inner_timestamp();
        (*net_signals)["CHARGER_3"]["_timestamp"].push(pack->charger_3(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["CHARGER_3"]["data_0"].push(pack->charger_3(i).data_0());
		(*net_signals)["CHARGER_3"]["data_1"].push(pack->charger_3(i).data_1());
		(*net_signals)["CHARGER_3"]["data_2"].push(pack->charger_3(i).data_2());
		(*net_signals)["CHARGER_3"]["data_3"].push(pack->charger_3(i).data_3());
		(*net_signals)["CHARGER_3"]["data_4"].push(pack->charger_3(i).data_4());
		(*net_signals)["CHARGER_3"]["data_5"].push(pack->charger_3(i).data_5());
		(*net_signals)["CHARGER_3"]["data_6"].push(pack->charger_3(i).data_6());
		(*net_signals)["CHARGER_3"]["data_7"].push(pack->charger_3(i).data_7());

    }

    for(int i = 0; i < pack->charger_4_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->charger_4(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->charger_4(i)._inner_timestamp();
        (*net_signals)["CHARGER_4"]["_timestamp"].push(pack->charger_4(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["CHARGER_4"]["data_0"].push(pack->charger_4(i).data_0());
		(*net_signals)["CHARGER_4"]["data_1"].push(pack->charger_4(i).data_1());
		(*net_signals)["CHARGER_4"]["data_2"].push(pack->charger_4(i).data_2());
		(*net_signals)["CHARGER_4"]["data_3"].push(pack->charger_4(i).data_3());
		(*net_signals)["CHARGER_4"]["data_4"].push(pack->charger_4(i).data_4());
		(*net_signals)["CHARGER_4"]["data_5"].push(pack->charger_4(i).data_5());
		(*net_signals)["CHARGER_4"]["data_6"].push(pack->charger_4(i).data_6());
		(*net_signals)["CHARGER_4"]["data_7"].push(pack->charger_4(i).data_7());

    }

    for(int i = 0; i < pack->charger_5_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->charger_5(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->charger_5(i)._inner_timestamp();
        (*net_signals)["CHARGER_5"]["_timestamp"].push(pack->charger_5(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["CHARGER_5"]["data_0"].push(pack->charger_5(i).data_0());
		(*net_signals)["CHARGER_5"]["data_1"].push(pack->charger_5(i).data_1());
		(*net_signals)["CHARGER_5"]["data_2"].push(pack->charger_5(i).data_2());
		(*net_signals)["CHARGER_5"]["data_3"].push(pack->charger_5(i).data_3());
		(*net_signals)["CHARGER_5"]["data_4"].push(pack->charger_5(i).data_4());
		(*net_signals)["CHARGER_5"]["data_5"].push(pack->charger_5(i).data_5());
		(*net_signals)["CHARGER_5"]["data_6"].push(pack->charger_5(i).data_6());
		(*net_signals)["CHARGER_5"]["data_7"].push(pack->charger_5(i).data_7());

    }

    for(int i = 0; i < pack->charger_6_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->charger_6(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->charger_6(i)._inner_timestamp();
        (*net_signals)["CHARGER_6"]["_timestamp"].push(pack->charger_6(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["CHARGER_6"]["data_0"].push(pack->charger_6(i).data_0());
		(*net_signals)["CHARGER_6"]["data_1"].push(pack->charger_6(i).data_1());
		(*net_signals)["CHARGER_6"]["data_2"].push(pack->charger_6(i).data_2());
		(*net_signals)["CHARGER_6"]["data_3"].push(pack->charger_6(i).data_3());
		(*net_signals)["CHARGER_6"]["data_4"].push(pack->charger_6(i).data_4());
		(*net_signals)["CHARGER_6"]["data_5"].push(pack->charger_6(i).data_5());
		(*net_signals)["CHARGER_6"]["data_6"].push(pack->charger_6(i).data_6());
		(*net_signals)["CHARGER_6"]["data_7"].push(pack->charger_6(i).data_7());

    }

    for(int i = 0; i < pack->charger_7_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->charger_7(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->charger_7(i)._inner_timestamp();
        (*net_signals)["CHARGER_7"]["_timestamp"].push(pack->charger_7(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["CHARGER_7"]["data_0"].push(pack->charger_7(i).data_0());
		(*net_signals)["CHARGER_7"]["data_1"].push(pack->charger_7(i).data_1());
		(*net_signals)["CHARGER_7"]["data_2"].push(pack->charger_7(i).data_2());
		(*net_signals)["CHARGER_7"]["data_3"].push(pack->charger_7(i).data_3());
		(*net_signals)["CHARGER_7"]["data_4"].push(pack->charger_7(i).data_4());
		(*net_signals)["CHARGER_7"]["data_5"].push(pack->charger_7(i).data_5());
		(*net_signals)["CHARGER_7"]["data_6"].push(pack->charger_7(i).data_6());
		(*net_signals)["CHARGER_7"]["data_7"].push(pack->charger_7(i).data_7());

    }

    for(int i = 0; i < pack->charger_8_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->charger_8(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->charger_8(i)._inner_timestamp();
        (*net_signals)["CHARGER_8"]["_timestamp"].push(pack->charger_8(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["CHARGER_8"]["data_0"].push(pack->charger_8(i).data_0());
		(*net_signals)["CHARGER_8"]["data_1"].push(pack->charger_8(i).data_1());
		(*net_signals)["CHARGER_8"]["data_2"].push(pack->charger_8(i).data_2());
		(*net_signals)["CHARGER_8"]["data_3"].push(pack->charger_8(i).data_3());
		(*net_signals)["CHARGER_8"]["data_4"].push(pack->charger_8(i).data_4());
		(*net_signals)["CHARGER_8"]["data_5"].push(pack->charger_8(i).data_5());
		(*net_signals)["CHARGER_8"]["data_6"].push(pack->charger_8(i).data_6());
		(*net_signals)["CHARGER_8"]["data_7"].push(pack->charger_8(i).data_7());

    }

    for(int i = 0; i < pack->charger_9_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->charger_9(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->charger_9(i)._inner_timestamp();
        (*net_signals)["CHARGER_9"]["_timestamp"].push(pack->charger_9(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["CHARGER_9"]["data_0"].push(pack->charger_9(i).data_0());
		(*net_signals)["CHARGER_9"]["data_1"].push(pack->charger_9(i).data_1());
		(*net_signals)["CHARGER_9"]["data_2"].push(pack->charger_9(i).data_2());
		(*net_signals)["CHARGER_9"]["data_3"].push(pack->charger_9(i).data_3());
		(*net_signals)["CHARGER_9"]["data_4"].push(pack->charger_9(i).data_4());
		(*net_signals)["CHARGER_9"]["data_5"].push(pack->charger_9(i).data_5());
		(*net_signals)["CHARGER_9"]["data_6"].push(pack->charger_9(i).data_6());
		(*net_signals)["CHARGER_9"]["data_7"].push(pack->charger_9(i).data_7());

    }

    for(int i = 0; i < pack->charger_10_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->charger_10(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->charger_10(i)._inner_timestamp();
        (*net_signals)["CHARGER_10"]["_timestamp"].push(pack->charger_10(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["CHARGER_10"]["data_0"].push(pack->charger_10(i).data_0());
		(*net_signals)["CHARGER_10"]["data_1"].push(pack->charger_10(i).data_1());
		(*net_signals)["CHARGER_10"]["data_2"].push(pack->charger_10(i).data_2());
		(*net_signals)["CHARGER_10"]["data_3"].push(pack->charger_10(i).data_3());
		(*net_signals)["CHARGER_10"]["data_4"].push(pack->charger_10(i).data_4());
		(*net_signals)["CHARGER_10"]["data_5"].push(pack->charger_10(i).data_5());
		(*net_signals)["CHARGER_10"]["data_6"].push(pack->charger_10(i).data_6());
		(*net_signals)["CHARGER_10"]["data_7"].push(pack->charger_10(i).data_7());

    }

    for(int i = 0; i < pack->charger_11_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->charger_11(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->charger_11(i)._inner_timestamp();
        (*net_signals)["CHARGER_11"]["_timestamp"].push(pack->charger_11(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["CHARGER_11"]["data_0"].push(pack->charger_11(i).data_0());
		(*net_signals)["CHARGER_11"]["data_1"].push(pack->charger_11(i).data_1());
		(*net_signals)["CHARGER_11"]["data_2"].push(pack->charger_11(i).data_2());
		(*net_signals)["CHARGER_11"]["data_3"].push(pack->charger_11(i).data_3());
		(*net_signals)["CHARGER_11"]["data_4"].push(pack->charger_11(i).data_4());
		(*net_signals)["CHARGER_11"]["data_5"].push(pack->charger_11(i).data_5());
		(*net_signals)["CHARGER_11"]["data_6"].push(pack->charger_11(i).data_6());
		(*net_signals)["CHARGER_11"]["data_7"].push(pack->charger_11(i).data_7());

    }

    for(int i = 0; i < pack->charger_12_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->charger_12(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->charger_12(i)._inner_timestamp();
        (*net_signals)["CHARGER_12"]["_timestamp"].push(pack->charger_12(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["CHARGER_12"]["data_0"].push(pack->charger_12(i).data_0());
		(*net_signals)["CHARGER_12"]["data_1"].push(pack->charger_12(i).data_1());
		(*net_signals)["CHARGER_12"]["data_2"].push(pack->charger_12(i).data_2());
		(*net_signals)["CHARGER_12"]["data_3"].push(pack->charger_12(i).data_3());
		(*net_signals)["CHARGER_12"]["data_4"].push(pack->charger_12(i).data_4());
		(*net_signals)["CHARGER_12"]["data_5"].push(pack->charger_12(i).data_5());
		(*net_signals)["CHARGER_12"]["data_6"].push(pack->charger_12(i).data_6());
		(*net_signals)["CHARGER_12"]["data_7"].push(pack->charger_12(i).data_7());

    }

    for(int i = 0; i < pack->charger_13_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->charger_13(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->charger_13(i)._inner_timestamp();
        (*net_signals)["CHARGER_13"]["_timestamp"].push(pack->charger_13(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["CHARGER_13"]["data_0"].push(pack->charger_13(i).data_0());
		(*net_signals)["CHARGER_13"]["data_1"].push(pack->charger_13(i).data_1());
		(*net_signals)["CHARGER_13"]["data_2"].push(pack->charger_13(i).data_2());
		(*net_signals)["CHARGER_13"]["data_3"].push(pack->charger_13(i).data_3());
		(*net_signals)["CHARGER_13"]["data_4"].push(pack->charger_13(i).data_4());
		(*net_signals)["CHARGER_13"]["data_5"].push(pack->charger_13(i).data_5());
		(*net_signals)["CHARGER_13"]["data_6"].push(pack->charger_13(i).data_6());
		(*net_signals)["CHARGER_13"]["data_7"].push(pack->charger_13(i).data_7());

    }

    for(int i = 0; i < pack->charger_14_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->charger_14(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->charger_14(i)._inner_timestamp();
        (*net_signals)["CHARGER_14"]["_timestamp"].push(pack->charger_14(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["CHARGER_14"]["data_0"].push(pack->charger_14(i).data_0());
		(*net_signals)["CHARGER_14"]["data_1"].push(pack->charger_14(i).data_1());
		(*net_signals)["CHARGER_14"]["data_2"].push(pack->charger_14(i).data_2());
		(*net_signals)["CHARGER_14"]["data_3"].push(pack->charger_14(i).data_3());
		(*net_signals)["CHARGER_14"]["data_4"].push(pack->charger_14(i).data_4());
		(*net_signals)["CHARGER_14"]["data_5"].push(pack->charger_14(i).data_5());
		(*net_signals)["CHARGER_14"]["data_6"].push(pack->charger_14(i).data_6());
		(*net_signals)["CHARGER_14"]["data_7"].push(pack->charger_14(i).data_7());

    }

    for(int i = 0; i < pack->charger_15_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->charger_15(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->charger_15(i)._inner_timestamp();
        (*net_signals)["CHARGER_15"]["_timestamp"].push(pack->charger_15(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["CHARGER_15"]["data_0"].push(pack->charger_15(i).data_0());
		(*net_signals)["CHARGER_15"]["data_1"].push(pack->charger_15(i).data_1());
		(*net_signals)["CHARGER_15"]["data_2"].push(pack->charger_15(i).data_2());
		(*net_signals)["CHARGER_15"]["data_3"].push(pack->charger_15(i).data_3());
		(*net_signals)["CHARGER_15"]["data_4"].push(pack->charger_15(i).data_4());
		(*net_signals)["CHARGER_15"]["data_5"].push(pack->charger_15(i).data_5());
		(*net_signals)["CHARGER_15"]["data_6"].push(pack->charger_15(i).data_6());
		(*net_signals)["CHARGER_15"]["data_7"].push(pack->charger_15(i).data_7());

    }

    for(int i = 0; i < pack->charger_16_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->charger_16(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->charger_16(i)._inner_timestamp();
        (*net_signals)["CHARGER_16"]["_timestamp"].push(pack->charger_16(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["CHARGER_16"]["data_0"].push(pack->charger_16(i).data_0());
		(*net_signals)["CHARGER_16"]["data_1"].push(pack->charger_16(i).data_1());
		(*net_signals)["CHARGER_16"]["data_2"].push(pack->charger_16(i).data_2());
		(*net_signals)["CHARGER_16"]["data_3"].push(pack->charger_16(i).data_3());
		(*net_signals)["CHARGER_16"]["data_4"].push(pack->charger_16(i).data_4());
		(*net_signals)["CHARGER_16"]["data_5"].push(pack->charger_16(i).data_5());
		(*net_signals)["CHARGER_16"]["data_6"].push(pack->charger_16(i).data_6());
		(*net_signals)["CHARGER_16"]["data_7"].push(pack->charger_16(i).data_7());

    }

    for(int i = 0; i < pack->charger_17_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->charger_17(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->charger_17(i)._inner_timestamp();
        (*net_signals)["CHARGER_17"]["_timestamp"].push(pack->charger_17(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["CHARGER_17"]["data_0"].push(pack->charger_17(i).data_0());
		(*net_signals)["CHARGER_17"]["data_1"].push(pack->charger_17(i).data_1());
		(*net_signals)["CHARGER_17"]["data_2"].push(pack->charger_17(i).data_2());
		(*net_signals)["CHARGER_17"]["data_3"].push(pack->charger_17(i).data_3());
		(*net_signals)["CHARGER_17"]["data_4"].push(pack->charger_17(i).data_4());
		(*net_signals)["CHARGER_17"]["data_5"].push(pack->charger_17(i).data_5());
		(*net_signals)["CHARGER_17"]["data_6"].push(pack->charger_17(i).data_6());
		(*net_signals)["CHARGER_17"]["data_7"].push(pack->charger_17(i).data_7());

    }

    for(int i = 0; i < pack->charger_18_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->charger_18(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->charger_18(i)._inner_timestamp();
        (*net_signals)["CHARGER_18"]["_timestamp"].push(pack->charger_18(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["CHARGER_18"]["data_0"].push(pack->charger_18(i).data_0());
		(*net_signals)["CHARGER_18"]["data_1"].push(pack->charger_18(i).data_1());
		(*net_signals)["CHARGER_18"]["data_2"].push(pack->charger_18(i).data_2());
		(*net_signals)["CHARGER_18"]["data_3"].push(pack->charger_18(i).data_3());
		(*net_signals)["CHARGER_18"]["data_4"].push(pack->charger_18(i).data_4());
		(*net_signals)["CHARGER_18"]["data_5"].push(pack->charger_18(i).data_5());
		(*net_signals)["CHARGER_18"]["data_6"].push(pack->charger_18(i).data_6());
		(*net_signals)["CHARGER_18"]["data_7"].push(pack->charger_18(i).data_7());

    }

    for(int i = 0; i < pack->charger_19_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->charger_19(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->charger_19(i)._inner_timestamp();
        (*net_signals)["CHARGER_19"]["_timestamp"].push(pack->charger_19(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["CHARGER_19"]["data_0"].push(pack->charger_19(i).data_0());
		(*net_signals)["CHARGER_19"]["data_1"].push(pack->charger_19(i).data_1());
		(*net_signals)["CHARGER_19"]["data_2"].push(pack->charger_19(i).data_2());
		(*net_signals)["CHARGER_19"]["data_3"].push(pack->charger_19(i).data_3());
		(*net_signals)["CHARGER_19"]["data_4"].push(pack->charger_19(i).data_4());
		(*net_signals)["CHARGER_19"]["data_5"].push(pack->charger_19(i).data_5());
		(*net_signals)["CHARGER_19"]["data_6"].push(pack->charger_19(i).data_6());
		(*net_signals)["CHARGER_19"]["data_7"].push(pack->charger_19(i).data_7());

    }

    for(int i = 0; i < pack->hv_feedback_digital_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_feedback_digital(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_feedback_digital(i)._inner_timestamp();
        (*net_signals)["HV_FEEDBACK_DIGITAL"]["_timestamp"].push(pack->hv_feedback_digital(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["HV_FEEDBACK_DIGITAL"]["digital_airn_open_com"].push(pack->hv_feedback_digital(i).digital_airn_open_com());
		(*net_enums)["HV_FEEDBACK_DIGITAL"]["digital_airp_open_com"].push(pack->hv_feedback_digital(i).digital_airp_open_com());
		(*net_enums)["HV_FEEDBACK_DIGITAL"]["digital_sd_imd_fb"].push(pack->hv_feedback_digital(i).digital_sd_imd_fb());
		(*net_enums)["HV_FEEDBACK_DIGITAL"]["digital_sd_bms_fb"].push(pack->hv_feedback_digital(i).digital_sd_bms_fb());
		(*net_enums)["HV_FEEDBACK_DIGITAL"]["digital_precharge_open_com"].push(pack->hv_feedback_digital(i).digital_precharge_open_com());
		(*net_enums)["HV_FEEDBACK_DIGITAL"]["digital_precharge_open_mec"].push(pack->hv_feedback_digital(i).digital_precharge_open_mec());
		(*net_enums)["HV_FEEDBACK_DIGITAL"]["digital_ts_less_than_60v"].push(pack->hv_feedback_digital(i).digital_ts_less_than_60v());
		(*net_enums)["HV_FEEDBACK_DIGITAL"]["digital_plausible_state_persisted"].push(pack->hv_feedback_digital(i).digital_plausible_state_persisted());
		(*net_enums)["HV_FEEDBACK_DIGITAL"]["digital_plausible_state"].push(pack->hv_feedback_digital(i).digital_plausible_state());
		(*net_enums)["HV_FEEDBACK_DIGITAL"]["digital_not_bms_fault_cockpit_led"].push(pack->hv_feedback_digital(i).digital_not_bms_fault_cockpit_led());
		(*net_enums)["HV_FEEDBACK_DIGITAL"]["digital_not_imd_fault_cockpit_led"].push(pack->hv_feedback_digital(i).digital_not_imd_fault_cockpit_led());
		(*net_enums)["HV_FEEDBACK_DIGITAL"]["digital_indicator_connected"].push(pack->hv_feedback_digital(i).digital_indicator_connected());
		(*net_enums)["HV_FEEDBACK_DIGITAL"]["digital_not_latch_reset"].push(pack->hv_feedback_digital(i).digital_not_latch_reset());
		(*net_enums)["HV_FEEDBACK_DIGITAL"]["digital_plausible_state_latched"].push(pack->hv_feedback_digital(i).digital_plausible_state_latched());
		(*net_enums)["HV_FEEDBACK_DIGITAL"]["digital_not_bms_fault_latched"].push(pack->hv_feedback_digital(i).digital_not_bms_fault_latched());
		(*net_enums)["HV_FEEDBACK_DIGITAL"]["digital_not_imd_fault_latched"].push(pack->hv_feedback_digital(i).digital_not_imd_fault_latched());
		(*net_enums)["HV_FEEDBACK_DIGITAL"]["digital_not_ext_fault_latched"].push(pack->hv_feedback_digital(i).digital_not_ext_fault_latched());

    }

    for(int i = 0; i < pack->hv_feedback_analog_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_feedback_analog(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_feedback_analog(i)._inner_timestamp();
        (*net_signals)["HV_FEEDBACK_ANALOG"]["_timestamp"].push(pack->hv_feedback_analog(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["HV_FEEDBACK_ANALOG"]["analog_airn_open_mec"].push(pack->hv_feedback_analog(i).analog_airn_open_mec());
		(*net_signals)["HV_FEEDBACK_ANALOG"]["analog_airp_open_mec"].push(pack->hv_feedback_analog(i).analog_airp_open_mec());
		(*net_signals)["HV_FEEDBACK_ANALOG"]["analog_imd_ok"].push(pack->hv_feedback_analog(i).analog_imd_ok());
		(*net_signals)["HV_FEEDBACK_ANALOG"]["analog_plausible_state_rc"].push(pack->hv_feedback_analog(i).analog_plausible_state_rc());
		(*net_signals)["HV_FEEDBACK_ANALOG"]["analog_tsal_green"].push(pack->hv_feedback_analog(i).analog_tsal_green());
		(*net_signals)["HV_FEEDBACK_ANALOG"]["analog_probing_3v3"].push(pack->hv_feedback_analog(i).analog_probing_3v3());
		(*net_signals)["HV_FEEDBACK_ANALOG"]["analog_v5_mcu"].push(pack->hv_feedback_analog(i).analog_v5_mcu());

    }

    for(int i = 0; i < pack->hv_feedback_analog_sd_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_feedback_analog_sd(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_feedback_analog_sd(i)._inner_timestamp();
        (*net_signals)["HV_FEEDBACK_ANALOG_SD"]["_timestamp"].push(pack->hv_feedback_analog_sd(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_signals)["HV_FEEDBACK_ANALOG_SD"]["sd_out"].push(pack->hv_feedback_analog_sd(i).sd_out());
		(*net_signals)["HV_FEEDBACK_ANALOG_SD"]["sd_in"].push(pack->hv_feedback_analog_sd(i).sd_in());
		(*net_signals)["HV_FEEDBACK_ANALOG_SD"]["sd_end"].push(pack->hv_feedback_analog_sd(i).sd_end());

    }

    for(int i = 0; i < pack->hv_feedback_enzomma_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_feedback_enzomma(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_feedback_enzomma(i)._inner_timestamp();
        (*net_signals)["HV_FEEDBACK_ENZOMMA"]["_timestamp"].push(pack->hv_feedback_enzomma(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["HV_FEEDBACK_ENZOMMA"]["feedback"].push(pack->hv_feedback_enzomma(i).feedback());
		primary_hv_feedback_enzomma_feedback_enum_to_string((primary_hv_feedback_enzomma_feedback)pack->hv_feedback_enzomma(i).feedback(), buffer);
		(*net_strings)["HV_FEEDBACK_ENZOMMA"]["feedback"].push(buffer);
		(*net_enums)["HV_FEEDBACK_ENZOMMA"]["status"].push(pack->hv_feedback_enzomma(i).status());
		primary_hv_feedback_enzomma_status_enum_to_string((primary_hv_feedback_enzomma_status)pack->hv_feedback_enzomma(i).status(), buffer);
		(*net_strings)["HV_FEEDBACK_ENZOMMA"]["status"].push(buffer);
		(*net_enums)["HV_FEEDBACK_ENZOMMA"]["is_digital"].push(pack->hv_feedback_enzomma(i).is_digital());
		(*net_enums)["HV_FEEDBACK_ENZOMMA"]["digital"].push(pack->hv_feedback_enzomma(i).digital());
		(*net_signals)["HV_FEEDBACK_ENZOMMA"]["analog"].push(pack->hv_feedback_enzomma(i).analog());

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
            primary_hv_flash_t* msg = (primary_hv_flash_t*)(device->message);
            primary::HV_FLASH* proto_msg = pack->add_hv_flash();
			proto_msg->set_start(msg->start);
			proto_msg->set_forward((primary::primary_hv_flash_forward)msg->forward);
			proto_msg->set_cellboard_id((primary::primary_hv_flash_cellboard_id)msg->cellboard_id);

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

        case 4: {
            primary_hv_flash_cellboard_0_tx_t* msg = (primary_hv_flash_cellboard_0_tx_t*)(device->message);
            primary::HV_FLASH_CELLBOARD_0_TX* proto_msg = pack->add_hv_flash_cellboard_0_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 5: {
            primary_hv_flash_cellboard_0_rx_t* msg = (primary_hv_flash_cellboard_0_rx_t*)(device->message);
            primary::HV_FLASH_CELLBOARD_0_RX* proto_msg = pack->add_hv_flash_cellboard_0_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 6: {
            primary_hv_flash_cellboard_1_tx_t* msg = (primary_hv_flash_cellboard_1_tx_t*)(device->message);
            primary::HV_FLASH_CELLBOARD_1_TX* proto_msg = pack->add_hv_flash_cellboard_1_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 7: {
            primary_hv_flash_cellboard_1_rx_t* msg = (primary_hv_flash_cellboard_1_rx_t*)(device->message);
            primary::HV_FLASH_CELLBOARD_1_RX* proto_msg = pack->add_hv_flash_cellboard_1_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 8: {
            primary_hv_flash_cellboard_2_tx_t* msg = (primary_hv_flash_cellboard_2_tx_t*)(device->message);
            primary::HV_FLASH_CELLBOARD_2_TX* proto_msg = pack->add_hv_flash_cellboard_2_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 9: {
            primary_hv_flash_cellboard_2_rx_t* msg = (primary_hv_flash_cellboard_2_rx_t*)(device->message);
            primary::HV_FLASH_CELLBOARD_2_RX* proto_msg = pack->add_hv_flash_cellboard_2_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 10: {
            primary_hv_flash_cellboard_3_tx_t* msg = (primary_hv_flash_cellboard_3_tx_t*)(device->message);
            primary::HV_FLASH_CELLBOARD_3_TX* proto_msg = pack->add_hv_flash_cellboard_3_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 11: {
            primary_hv_flash_cellboard_3_rx_t* msg = (primary_hv_flash_cellboard_3_rx_t*)(device->message);
            primary::HV_FLASH_CELLBOARD_3_RX* proto_msg = pack->add_hv_flash_cellboard_3_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 12: {
            primary_hv_flash_cellboard_4_tx_t* msg = (primary_hv_flash_cellboard_4_tx_t*)(device->message);
            primary::HV_FLASH_CELLBOARD_4_TX* proto_msg = pack->add_hv_flash_cellboard_4_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 13: {
            primary_hv_flash_cellboard_4_rx_t* msg = (primary_hv_flash_cellboard_4_rx_t*)(device->message);
            primary::HV_FLASH_CELLBOARD_4_RX* proto_msg = pack->add_hv_flash_cellboard_4_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 14: {
            primary_hv_flash_cellboard_5_tx_t* msg = (primary_hv_flash_cellboard_5_tx_t*)(device->message);
            primary::HV_FLASH_CELLBOARD_5_TX* proto_msg = pack->add_hv_flash_cellboard_5_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 15: {
            primary_hv_flash_cellboard_5_rx_t* msg = (primary_hv_flash_cellboard_5_rx_t*)(device->message);
            primary::HV_FLASH_CELLBOARD_5_RX* proto_msg = pack->add_hv_flash_cellboard_5_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 16: {
            primary_lv_jmp_to_blt_t* msg = (primary_lv_jmp_to_blt_t*)(device->message);
            primary::LV_JMP_TO_BLT* proto_msg = pack->add_lv_jmp_to_blt();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 17: {
            primary_lv_flash_tx_t* msg = (primary_lv_flash_tx_t*)(device->message);
            primary::LV_FLASH_TX* proto_msg = pack->add_lv_flash_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 18: {
            primary_lv_flash_rx_t* msg = (primary_lv_flash_rx_t*)(device->message);
            primary::LV_FLASH_RX* proto_msg = pack->add_lv_flash_rx();

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
            primary_ecu_flash_tx_t* msg = (primary_ecu_flash_tx_t*)(device->message);
            primary::ECU_FLASH_TX* proto_msg = pack->add_ecu_flash_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 21: {
            primary_ecu_flash_rx_t* msg = (primary_ecu_flash_rx_t*)(device->message);
            primary::ECU_FLASH_RX* proto_msg = pack->add_ecu_flash_rx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 22: {
            primary_steering_wheel_jmp_to_blt_t* msg = (primary_steering_wheel_jmp_to_blt_t*)(device->message);
            primary::STEERING_WHEEL_JMP_TO_BLT* proto_msg = pack->add_steering_wheel_jmp_to_blt();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 23: {
            primary_steering_wheel_flash_tx_t* msg = (primary_steering_wheel_flash_tx_t*)(device->message);
            primary::STEERING_WHEEL_FLASH_TX* proto_msg = pack->add_steering_wheel_flash_tx();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 24: {
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
            primary_hv_cellboard_version_t* msg = (primary_hv_cellboard_version_t*)(device->message);
            primary::HV_CELLBOARD_VERSION* proto_msg = pack->add_hv_cellboard_version();
			proto_msg->set_cellboard_id((primary::primary_hv_cellboard_version_cellboard_id)msg->cellboard_id);
			proto_msg->set_canlib_build_time(msg->canlib_build_time);
			proto_msg->set_component_build_time(msg->component_build_time);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 32: {
            primary_hv_errors_t* msg = (primary_hv_errors_t*)(device->message);
            primary::HV_ERRORS* proto_msg = pack->add_hv_errors();
			proto_msg->set_errors_cell_under_voltage(msg->errors_cell_under_voltage);
			proto_msg->set_errors_cell_over_voltage(msg->errors_cell_over_voltage);
			proto_msg->set_errors_cell_under_temperature(msg->errors_cell_under_temperature);
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
			proto_msg->set_errors_cell_under_voltage(msg->errors_cell_under_voltage);
			proto_msg->set_errors_cell_over_voltage(msg->errors_cell_over_voltage);
			proto_msg->set_errors_cell_under_temperature(msg->errors_cell_under_temperature);
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

        case 1024: {
            primary_hv_set_fans_status_converted_t* msg = (primary_hv_set_fans_status_converted_t*)(device->message);
            primary::HV_SET_FANS_STATUS* proto_msg = pack->add_hv_set_fans_status();
			proto_msg->set_fans_override((primary::primary_hv_set_fans_status_fans_override)msg->fans_override);
			proto_msg->set_fans_speed(msg->fans_speed);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 520: {
            primary_hv_feedback_status_t* msg = (primary_hv_feedback_status_t*)(device->message);
            primary::HV_FEEDBACK_STATUS* proto_msg = pack->add_hv_feedback_status();
			proto_msg->set_airn_open_com((primary::primary_hv_feedback_status_airn_open_com)msg->airn_open_com);
			proto_msg->set_precharge_open_com((primary::primary_hv_feedback_status_precharge_open_com)msg->precharge_open_com);
			proto_msg->set_airp_open_com((primary::primary_hv_feedback_status_airp_open_com)msg->airp_open_com);
			proto_msg->set_airn_open_mec((primary::primary_hv_feedback_status_airn_open_mec)msg->airn_open_mec);
			proto_msg->set_precharge_open_mec((primary::primary_hv_feedback_status_precharge_open_mec)msg->precharge_open_mec);
			proto_msg->set_airp_open_mec((primary::primary_hv_feedback_status_airp_open_mec)msg->airp_open_mec);
			proto_msg->set_sd_imd_fb((primary::primary_hv_feedback_status_sd_imd_fb)msg->sd_imd_fb);
			proto_msg->set_sd_bms_fb((primary::primary_hv_feedback_status_sd_bms_fb)msg->sd_bms_fb);
			proto_msg->set_ts_less_than_60v((primary::primary_hv_feedback_status_ts_less_than_60v)msg->ts_less_than_60v);
			proto_msg->set_plausible_state_persisted((primary::primary_hv_feedback_status_plausible_state_persisted)msg->plausible_state_persisted);
			proto_msg->set_plausible_state((primary::primary_hv_feedback_status_plausible_state)msg->plausible_state);
			proto_msg->set_not_bms_fault_cockpit_led((primary::primary_hv_feedback_status_not_bms_fault_cockpit_led)msg->not_bms_fault_cockpit_led);
			proto_msg->set_not_imd_fault_cockpit_led((primary::primary_hv_feedback_status_not_imd_fault_cockpit_led)msg->not_imd_fault_cockpit_led);
			proto_msg->set_indicator_connected((primary::primary_hv_feedback_status_indicator_connected)msg->indicator_connected);
			proto_msg->set_not_latch_reset((primary::primary_hv_feedback_status_not_latch_reset)msg->not_latch_reset);
			proto_msg->set_plausible_state_latched((primary::primary_hv_feedback_status_plausible_state_latched)msg->plausible_state_latched);
			proto_msg->set_not_bms_fault_latched((primary::primary_hv_feedback_status_not_bms_fault_latched)msg->not_bms_fault_latched);
			proto_msg->set_not_imd_fault_latched((primary::primary_hv_feedback_status_not_imd_fault_latched)msg->not_imd_fault_latched);
			proto_msg->set_not_ext_fault_latched((primary::primary_hv_feedback_status_not_ext_fault_latched)msg->not_ext_fault_latched);
			proto_msg->set_imd_ok((primary::primary_hv_feedback_status_imd_ok)msg->imd_ok);
			proto_msg->set_plausible_state_rc((primary::primary_hv_feedback_status_plausible_state_rc)msg->plausible_state_rc);
			proto_msg->set_tsal_green((primary::primary_hv_feedback_status_tsal_green)msg->tsal_green);
			proto_msg->set_probing_3v3((primary::primary_hv_feedback_status_probing_3v3)msg->probing_3v3);
			proto_msg->set_sd_out((primary::primary_hv_feedback_status_sd_out)msg->sd_out);
			proto_msg->set_sd_in((primary::primary_hv_feedback_status_sd_in)msg->sd_in);
			proto_msg->set_sd_end((primary::primary_hv_feedback_status_sd_end)msg->sd_end);
			proto_msg->set_v5_mcu((primary::primary_hv_feedback_status_v5_mcu)msg->v5_mcu);
			proto_msg->set_feedback_tsal_green_fault_latched((primary::primary_hv_feedback_status_feedback_tsal_green_fault_latched)msg->feedback_tsal_green_fault_latched);
			proto_msg->set_feedback_ext_latched((primary::primary_hv_feedback_status_feedback_ext_latched)msg->feedback_ext_latched);
			proto_msg->set_feedback_precharge_status((primary::primary_hv_feedback_status_feedback_precharge_status)msg->feedback_precharge_status);
			proto_msg->set_feedback_tsp_over_60v_status((primary::primary_hv_feedback_status_feedback_tsp_over_60v_status)msg->feedback_tsp_over_60v_status);
			proto_msg->set_feedback_check_mux((primary::primary_hv_feedback_status_feedback_check_mux)msg->feedback_check_mux);

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
            primary_hv_feedback_misc_voltage_converted_t* msg = (primary_hv_feedback_misc_voltage_converted_t*)(device->message);
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
            primary_hv_feedback_sd_voltage_converted_t* msg = (primary_hv_feedback_sd_voltage_converted_t*)(device->message);
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
            primary_hv_imd_status_converted_t* msg = (primary_hv_imd_status_converted_t*)(device->message);
            primary::HV_IMD_STATUS* proto_msg = pack->add_hv_imd_status();
			proto_msg->set_status((primary::primary_hv_imd_status_status)msg->status);
			proto_msg->set_frequency(msg->frequency);
			proto_msg->set_duty_cycle(msg->duty_cycle);
			proto_msg->set_feedback_not_imd_fault_cockpit_led((primary::primary_hv_imd_status_feedback_not_imd_fault_cockpit_led)msg->feedback_not_imd_fault_cockpit_led);
			proto_msg->set_feedback_not_imd_fault_latched((primary::primary_hv_imd_status_feedback_not_imd_fault_latched)msg->feedback_not_imd_fault_latched);
			proto_msg->set_imd_fault(msg->imd_fault);
			proto_msg->set_imd_details(msg->imd_details);
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
			proto_msg->set_cellboard_0((primary::primary_hv_status_cellboard_0)msg->cellboard_0);
			proto_msg->set_cellboard_1((primary::primary_hv_status_cellboard_1)msg->cellboard_1);
			proto_msg->set_cellboard_2((primary::primary_hv_status_cellboard_2)msg->cellboard_2);
			proto_msg->set_cellboard_3((primary::primary_hv_status_cellboard_3)msg->cellboard_3);
			proto_msg->set_cellboard_4((primary::primary_hv_status_cellboard_4)msg->cellboard_4);
			proto_msg->set_cellboard_5((primary::primary_hv_status_cellboard_5)msg->cellboard_5);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 40: {
            primary_hv_set_status_ecu_t* msg = (primary_hv_set_status_ecu_t*)(device->message);
            primary::HV_SET_STATUS_ECU* proto_msg = pack->add_hv_set_status_ecu();
			proto_msg->set_status(msg->status);
			proto_msg->set_hv_status_set((primary::primary_hv_set_status_ecu_hv_status_set)msg->hv_status_set);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 48: {
            primary_hv_set_status_handcart_t* msg = (primary_hv_set_status_handcart_t*)(device->message);
            primary::HV_SET_STATUS_HANDCART* proto_msg = pack->add_hv_set_status_handcart();
			proto_msg->set_status(msg->status);
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
			proto_msg->set_status((primary::primary_hv_balancing_status_status)msg->status);
			proto_msg->set_discharging_cell_0(msg->discharging_cell_0);
			proto_msg->set_discharging_cell_1(msg->discharging_cell_1);
			proto_msg->set_discharging_cell_2(msg->discharging_cell_2);
			proto_msg->set_discharging_cell_3(msg->discharging_cell_3);
			proto_msg->set_discharging_cell_4(msg->discharging_cell_4);
			proto_msg->set_discharging_cell_5(msg->discharging_cell_5);
			proto_msg->set_discharging_cell_6(msg->discharging_cell_6);
			proto_msg->set_discharging_cell_7(msg->discharging_cell_7);
			proto_msg->set_discharging_cell_8(msg->discharging_cell_8);
			proto_msg->set_discharging_cell_9(msg->discharging_cell_9);
			proto_msg->set_discharging_cell_10(msg->discharging_cell_10);
			proto_msg->set_discharging_cell_11(msg->discharging_cell_11);
			proto_msg->set_discharging_cell_12(msg->discharging_cell_12);
			proto_msg->set_discharging_cell_13(msg->discharging_cell_13);
			proto_msg->set_discharging_cell_14(msg->discharging_cell_14);
			proto_msg->set_discharging_cell_15(msg->discharging_cell_15);
			proto_msg->set_discharging_cell_16(msg->discharging_cell_16);
			proto_msg->set_discharging_cell_17(msg->discharging_cell_17);
			proto_msg->set_discharging_cell_18(msg->discharging_cell_18);
			proto_msg->set_discharging_cell_19(msg->discharging_cell_19);
			proto_msg->set_discharging_cell_20(msg->discharging_cell_20);
			proto_msg->set_discharging_cell_21(msg->discharging_cell_21);
			proto_msg->set_discharging_cell_22(msg->discharging_cell_22);
			proto_msg->set_discharging_cell_23(msg->discharging_cell_23);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1032: {
            primary_hv_set_balancing_status_steering_wheel_converted_t* msg = (primary_hv_set_balancing_status_steering_wheel_converted_t*)(device->message);
            primary::HV_SET_BALANCING_STATUS_STEERING_WHEEL* proto_msg = pack->add_hv_set_balancing_status_steering_wheel();
			proto_msg->set_status(msg->status);
			proto_msg->set_threshold(msg->threshold);
			proto_msg->set_set_balancing_status((primary::primary_hv_set_balancing_status_steering_wheel_set_balancing_status)msg->set_balancing_status);
			proto_msg->set_balancing_threshold(msg->balancing_threshold);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1040: {
            primary_hv_set_balancing_status_handcart_converted_t* msg = (primary_hv_set_balancing_status_handcart_converted_t*)(device->message);
            primary::HV_SET_BALANCING_STATUS_HANDCART* proto_msg = pack->add_hv_set_balancing_status_handcart();
			proto_msg->set_status(msg->status);
			proto_msg->set_threshold(msg->threshold);
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
            primary_lv_charging_status_t* msg = (primary_lv_charging_status_t*)(device->message);
            primary::LV_CHARGING_STATUS* proto_msg = pack->add_lv_charging_status();
			proto_msg->set_status((primary::primary_lv_charging_status_status)msg->status);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1576: {
            primary_lv_cooling_aggressiveness_t* msg = (primary_lv_cooling_aggressiveness_t*)(device->message);
            primary::LV_COOLING_AGGRESSIVENESS* proto_msg = pack->add_lv_cooling_aggressiveness();
			proto_msg->set_status((primary::primary_lv_cooling_aggressiveness_status)msg->status);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1048: {
            primary_lv_set_cooling_aggressiveness_t* msg = (primary_lv_set_cooling_aggressiveness_t*)(device->message);
            primary::LV_SET_COOLING_AGGRESSIVENESS* proto_msg = pack->add_lv_set_cooling_aggressiveness();
			proto_msg->set_status((primary::primary_lv_set_cooling_aggressiveness_status)msg->status);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1584: {
            primary_lv_radiator_speed_converted_t* msg = (primary_lv_radiator_speed_converted_t*)(device->message);
            primary::LV_RADIATOR_SPEED* proto_msg = pack->add_lv_radiator_speed();
			proto_msg->set_status((primary::primary_lv_radiator_speed_status)msg->status);
			proto_msg->set_radiator_speed(msg->radiator_speed);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1592: {
            primary_lv_pumps_speed_converted_t* msg = (primary_lv_pumps_speed_converted_t*)(device->message);
            primary::LV_PUMPS_SPEED* proto_msg = pack->add_lv_pumps_speed();
			proto_msg->set_status((primary::primary_lv_pumps_speed_status)msg->status);
			proto_msg->set_pumps_speed(msg->pumps_speed);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1056: {
            primary_lv_set_radiator_speed_converted_t* msg = (primary_lv_set_radiator_speed_converted_t*)(device->message);
            primary::LV_SET_RADIATOR_SPEED* proto_msg = pack->add_lv_set_radiator_speed();
			proto_msg->set_status((primary::primary_lv_set_radiator_speed_status)msg->status);
			proto_msg->set_radiator_speed(msg->radiator_speed);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1064: {
            primary_lv_set_pumps_speed_converted_t* msg = (primary_lv_set_pumps_speed_converted_t*)(device->message);
            primary::LV_SET_PUMPS_SPEED* proto_msg = pack->add_lv_set_pumps_speed();
			proto_msg->set_status((primary::primary_lv_set_pumps_speed_status)msg->status);
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
            primary_lv_feedback_t* msg = (primary_lv_feedback_t*)(device->message);
            primary::LV_FEEDBACK* proto_msg = pack->add_lv_feedback();
			proto_msg->set_feedbacks_bspd(msg->feedbacks_bspd);
			proto_msg->set_feedbacks_hvd(msg->feedbacks_hvd);
			proto_msg->set_feedbacks_invc_interlock(msg->feedbacks_invc_interlock);
			proto_msg->set_feedbacks_ams(msg->feedbacks_ams);
			proto_msg->set_feedbacks_sd_end(msg->feedbacks_sd_end);
			proto_msg->set_feedbacks_lvms(msg->feedbacks_lvms);
			proto_msg->set_feedbacks_interlock(msg->feedbacks_interlock);
			proto_msg->set_feedbacks_sd_start(msg->feedbacks_sd_start);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 592: {
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

        case 600: {
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

        case 608: {
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

        case 616: {
            primary_lv_feedback_gpio_extender_t* msg = (primary_lv_feedback_gpio_extender_t*)(device->message);
            primary::LV_FEEDBACK_GPIO_EXTENDER* proto_msg = pack->add_lv_feedback_gpio_extender();
			proto_msg->set_feedback_inverters(msg->feedback_inverters);
			proto_msg->set_feedback_pcbs(msg->feedback_pcbs);
			proto_msg->set_feedback_pumps(msg->feedback_pumps);
			proto_msg->set_feedback_radiators(msg->feedback_radiators);
			proto_msg->set_feedback_shutdown(msg->feedback_shutdown);
			proto_msg->set_feedback_hv_fans(msg->feedback_hv_fans);
			proto_msg->set_feedback_autonomous_system_actuation(msg->feedback_autonomous_system_actuation);
			proto_msg->set_feedback_rfe(msg->feedback_rfe);
			proto_msg->set_feedback_frg(msg->feedback_frg);
			proto_msg->set_feedback_discharge(msg->feedback_discharge);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 56: {
            primary_lv_can_flash_req_tlm_t* msg = (primary_lv_can_flash_req_tlm_t*)(device->message);
            primary::LV_CAN_FLASH_REQ_TLM* proto_msg = pack->add_lv_can_flash_req_tlm();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 64: {
            primary_lv_can_flash_req_steering_wheel_t* msg = (primary_lv_can_flash_req_steering_wheel_t*)(device->message);
            primary::LV_CAN_FLASH_REQ_STEERING_WHEEL* proto_msg = pack->add_lv_can_flash_req_steering_wheel();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 72: {
            primary_lv_can_flash_ack_t* msg = (primary_lv_can_flash_ack_t*)(device->message);
            primary::LV_CAN_FLASH_ACK* proto_msg = pack->add_lv_can_flash_ack();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 624: {
            primary_lv_inverter_connection_status_t* msg = (primary_lv_inverter_connection_status_t*)(device->message);
            primary::LV_INVERTER_CONNECTION_STATUS* proto_msg = pack->add_lv_inverter_connection_status();
			proto_msg->set_status((primary::primary_lv_inverter_connection_status_status)msg->status);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 80: {
            primary_lv_set_inverter_connection_status_t* msg = (primary_lv_set_inverter_connection_status_t*)(device->message);
            primary::LV_SET_INVERTER_CONNECTION_STATUS* proto_msg = pack->add_lv_set_inverter_connection_status();
			proto_msg->set_status((primary::primary_lv_set_inverter_connection_status_status)msg->status);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1600: {
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

        case 632: {
            primary_handcart_status_t* msg = (primary_handcart_status_t*)(device->message);
            primary::HANDCART_STATUS* proto_msg = pack->add_handcart_status();
			proto_msg->set_connected((primary::primary_handcart_status_connected)msg->connected);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1608: {
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

        case 640: {
            primary_ecu_status_t* msg = (primary_ecu_status_t*)(device->message);
            primary::ECU_STATUS* proto_msg = pack->add_ecu_status();
			proto_msg->set_status((primary::primary_ecu_status_status)msg->status);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 88: {
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

        case 648: {
            primary_ecu_control_status_t* msg = (primary_ecu_control_status_t*)(device->message);
            primary::ECU_CONTROL_STATUS* proto_msg = pack->add_ecu_control_status();
			proto_msg->set_control_enabled(msg->control_enabled);
			proto_msg->set_control_errors_disabled_from_ecu(msg->control_errors_disabled_from_ecu);
			proto_msg->set_control_errors_wrong_maps(msg->control_errors_wrong_maps);
			proto_msg->set_control_errors_control_watchdog(msg->control_errors_control_watchdog);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 656: {
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
			proto_msg->set_error_bspd_limits(msg->error_bspd_limits);
			proto_msg->set_error_no_brake_to_rtd(msg->error_no_brake_to_rtd);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 664: {
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

        case 672: {
            primary_ecu_power_maps_converted_t* msg = (primary_ecu_power_maps_converted_t*)(device->message);
            primary::ECU_POWER_MAPS* proto_msg = pack->add_ecu_power_maps();
			proto_msg->set_map_power(msg->map_power);
			proto_msg->set_sc_state((primary::primary_ecu_power_maps_sc_state)msg->sc_state);
			proto_msg->set_tv_state((primary::primary_ecu_power_maps_tv_state)msg->tv_state);
			proto_msg->set_reg_state((primary::primary_ecu_power_maps_reg_state)msg->reg_state);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 96: {
            primary_ecu_set_power_maps_converted_t* msg = (primary_ecu_set_power_maps_converted_t*)(device->message);
            primary::ECU_SET_POWER_MAPS* proto_msg = pack->add_ecu_set_power_maps();
			proto_msg->set_map_power(msg->map_power);
			proto_msg->set_sc_state((primary::primary_ecu_set_power_maps_sc_state)msg->sc_state);
			proto_msg->set_tv_state((primary::primary_ecu_set_power_maps_tv_state)msg->tv_state);
			proto_msg->set_reg_state((primary::primary_ecu_set_power_maps_reg_state)msg->reg_state);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1616: {
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

        case 680: {
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

        case 688: {
            primary_control_status_converted_t* msg = (primary_control_status_converted_t*)(device->message);
            primary::CONTROL_STATUS* proto_msg = pack->add_control_status();
			proto_msg->set_map_power(msg->map_power);
			proto_msg->set_sc_state((primary::primary_control_status_sc_state)msg->sc_state);
			proto_msg->set_tv_state((primary::primary_control_status_tv_state)msg->tv_state);
			proto_msg->set_reg_state((primary::primary_control_status_reg_state)msg->reg_state);

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

        case 1624: {
            primary_lv_current_battery_converted_t* msg = (primary_lv_current_battery_converted_t*)(device->message);
            primary::LV_CURRENT_BATTERY* proto_msg = pack->add_lv_current_battery();
			proto_msg->set_lv_current(msg->lv_current);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1632: {
            primary_lv_current_charger_converted_t* msg = (primary_lv_current_charger_converted_t*)(device->message);
            primary::LV_CURRENT_CHARGER* proto_msg = pack->add_lv_current_charger();
			proto_msg->set_charger_current(msg->charger_current);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1640: {
            primary_lv_total_voltage_converted_t* msg = (primary_lv_total_voltage_converted_t*)(device->message);
            primary::LV_TOTAL_VOLTAGE* proto_msg = pack->add_lv_total_voltage();
			proto_msg->set_total(msg->total);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1648: {
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

        case 1656: {
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

        case 1664: {
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

        case 1672: {
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

        case 1680: {
            primary_hv_current_converted_t* msg = (primary_hv_current_converted_t*)(device->message);
            primary::HV_CURRENT* proto_msg = pack->add_hv_current();
			proto_msg->set_current(msg->current);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1688: {
            primary_hv_power_converted_t* msg = (primary_hv_power_converted_t*)(device->message);
            primary::HV_POWER* proto_msg = pack->add_hv_power();
			proto_msg->set_power(msg->power);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1696: {
            primary_hv_energy_converted_t* msg = (primary_hv_energy_converted_t*)(device->message);
            primary::HV_ENERGY* proto_msg = pack->add_hv_energy();
			proto_msg->set_energy(msg->energy);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1704: {
            primary_hv_soc_converted_t* msg = (primary_hv_soc_converted_t*)(device->message);
            primary::HV_SOC* proto_msg = pack->add_hv_soc();
			proto_msg->set_soc(msg->soc);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1712: {
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

        case 1720: {
            primary_hv_cells_voltage_converted_t* msg = (primary_hv_cells_voltage_converted_t*)(device->message);
            primary::HV_CELLS_VOLTAGE* proto_msg = pack->add_hv_cells_voltage();
			proto_msg->set_cellboard_id((primary::primary_hv_cells_voltage_cellboard_id)msg->cellboard_id);
			proto_msg->set_offset(msg->offset);
			proto_msg->set_voltage_0(msg->voltage_0);
			proto_msg->set_voltage_1(msg->voltage_1);
			proto_msg->set_voltage_2(msg->voltage_2);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1728: {
            primary_hv_cells_voltage_stats_converted_t* msg = (primary_hv_cells_voltage_stats_converted_t*)(device->message);
            primary::HV_CELLS_VOLTAGE_STATS* proto_msg = pack->add_hv_cells_voltage_stats();
			proto_msg->set_max(msg->max);
			proto_msg->set_min(msg->min);
			proto_msg->set_delta(msg->delta);
			proto_msg->set_avg(msg->avg);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1736: {
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

        case 1744: {
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

        case 1752: {
            primary_ecu_steer_actuator_status_t* msg = (primary_ecu_steer_actuator_status_t*)(device->message);
            primary::ECU_STEER_ACTUATOR_STATUS* proto_msg = pack->add_ecu_steer_actuator_status();
			proto_msg->set_status((primary::primary_ecu_steer_actuator_status_status)msg->status);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1104: {
            primary_ecu_set_steer_actuator_status_steering_wheel_t* msg = (primary_ecu_set_steer_actuator_status_steering_wheel_t*)(device->message);
            primary::ECU_SET_STEER_ACTUATOR_STATUS_STEERING_WHEEL* proto_msg = pack->add_ecu_set_steer_actuator_status_steering_wheel();
			proto_msg->set_status((primary::primary_ecu_set_steer_actuator_status_steering_wheel_status)msg->status);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1112: {
            primary_ecu_set_steer_actuator_status_tlm_t* msg = (primary_ecu_set_steer_actuator_status_tlm_t*)(device->message);
            primary::ECU_SET_STEER_ACTUATOR_STATUS_TLM* proto_msg = pack->add_ecu_set_steer_actuator_status_tlm();
			proto_msg->set_status((primary::primary_ecu_set_steer_actuator_status_tlm_status)msg->status);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1760: {
            primary_ecu_set_steer_actuator_angle_converted_t* msg = (primary_ecu_set_steer_actuator_angle_converted_t*)(device->message);
            primary::ECU_SET_STEER_ACTUATOR_ANGLE* proto_msg = pack->add_ecu_set_steer_actuator_angle();
			proto_msg->set_angle(msg->angle);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1768: {
            primary_ecu_steer_actuator_current_converted_t* msg = (primary_ecu_steer_actuator_current_converted_t*)(device->message);
            primary::ECU_STEER_ACTUATOR_CURRENT* proto_msg = pack->add_ecu_steer_actuator_current();
			proto_msg->set_current(msg->current);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1776: {
            primary_debug_signal_crash_debug_t* msg = (primary_debug_signal_crash_debug_t*)(device->message);
            primary::DEBUG_SIGNAL_CRASH_DEBUG* proto_msg = pack->add_debug_signal_crash_debug();
			proto_msg->set_seq_number(msg->seq_number);
			proto_msg->set_byte_1(msg->byte_1);
			proto_msg->set_byte_2(msg->byte_2);
			proto_msg->set_byte_3(msg->byte_3);
			proto_msg->set_byte_4(msg->byte_4);
			proto_msg->set_byte_5(msg->byte_5);
			proto_msg->set_byte_6(msg->byte_6);
			proto_msg->set_byte_7(msg->byte_7);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1784: {
            primary_debug_signal_crash_debug_ack_t* msg = (primary_debug_signal_crash_debug_ack_t*)(device->message);
            primary::DEBUG_SIGNAL_CRASH_DEBUG_ACK* proto_msg = pack->add_debug_signal_crash_debug_ack();
			proto_msg->set_seq_number(msg->seq_number);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1792: {
            primary_debug_signal_1_converted_t* msg = (primary_debug_signal_1_converted_t*)(device->message);
            primary::DEBUG_SIGNAL_1* proto_msg = pack->add_debug_signal_1();
			proto_msg->set_device_id((primary::primary_debug_signal_1_device_id)msg->device_id);
			proto_msg->set_field_1(msg->field_1);
			proto_msg->set_field_2(msg->field_2);
			proto_msg->set_field_3(msg->field_3);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1800: {
            primary_debug_signal_2_converted_t* msg = (primary_debug_signal_2_converted_t*)(device->message);
            primary::DEBUG_SIGNAL_2* proto_msg = pack->add_debug_signal_2();
			proto_msg->set_device_id((primary::primary_debug_signal_2_device_id)msg->device_id);
			proto_msg->set_field_1(msg->field_1);
			proto_msg->set_field_2(msg->field_2);
			proto_msg->set_field_3(msg->field_3);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1808: {
            primary_debug_signal_3_converted_t* msg = (primary_debug_signal_3_converted_t*)(device->message);
            primary::DEBUG_SIGNAL_3* proto_msg = pack->add_debug_signal_3();
			proto_msg->set_device_id((primary::primary_debug_signal_3_device_id)msg->device_id);
			proto_msg->set_field_1(msg->field_1);
			proto_msg->set_field_2(msg->field_2);
			proto_msg->set_field_3(msg->field_3);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1824: {
            primary_debug_signal_4_converted_t* msg = (primary_debug_signal_4_converted_t*)(device->message);
            primary::DEBUG_SIGNAL_4* proto_msg = pack->add_debug_signal_4();
			proto_msg->set_device_id((primary::primary_debug_signal_4_device_id)msg->device_id);
			proto_msg->set_field_1(msg->field_1);
			proto_msg->set_field_2(msg->field_2);
			proto_msg->set_field_3(msg->field_3);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 50: {
            primary_hv_flash_request_t* msg = (primary_hv_flash_request_t*)(device->message);
            primary::HV_FLASH_REQUEST* proto_msg = pack->add_hv_flash_request();
			proto_msg->set_mainboard(msg->mainboard);
			proto_msg->set_cellboard_id((primary::primary_hv_flash_request_cellboard_id)msg->cellboard_id);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 51: {
            primary_hv_flash_response_t* msg = (primary_hv_flash_response_t*)(device->message);
            primary::HV_FLASH_RESPONSE* proto_msg = pack->add_hv_flash_response();
			proto_msg->set_ready(msg->ready);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1120: {
            primary_hv_ts_voltage_converted_t* msg = (primary_hv_ts_voltage_converted_t*)(device->message);
            primary::HV_TS_VOLTAGE* proto_msg = pack->add_hv_ts_voltage();
			proto_msg->set_ts(msg->ts);
			proto_msg->set_pack(msg->pack);
			proto_msg->set_cells_sum(msg->cells_sum);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1832: {
            primary_hv_cells_temperature_converted_t* msg = (primary_hv_cells_temperature_converted_t*)(device->message);
            primary::HV_CELLS_TEMPERATURE* proto_msg = pack->add_hv_cells_temperature();
			proto_msg->set_cellboard_id((primary::primary_hv_cells_temperature_cellboard_id)msg->cellboard_id);
			proto_msg->set_temperature_id_0(msg->temperature_id_0);
			proto_msg->set_temperature_id_1(msg->temperature_id_1);
			proto_msg->set_temperature_id_2(msg->temperature_id_2);
			proto_msg->set_temperature_id_3(msg->temperature_id_3);
			proto_msg->set_temperature_0(msg->temperature_0);
			proto_msg->set_temperature_1(msg->temperature_1);
			proto_msg->set_temperature_2(msg->temperature_2);
			proto_msg->set_temperature_3(msg->temperature_3);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 256: {
            primary_charger_1_t* msg = (primary_charger_1_t*)(device->message);
            primary::CHARGER_1* proto_msg = pack->add_charger_1();
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

        case 272: {
            primary_charger_2_t* msg = (primary_charger_2_t*)(device->message);
            primary::CHARGER_2* proto_msg = pack->add_charger_2();
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

        case 288: {
            primary_charger_3_t* msg = (primary_charger_3_t*)(device->message);
            primary::CHARGER_3* proto_msg = pack->add_charger_3();
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

        case 304: {
            primary_charger_4_t* msg = (primary_charger_4_t*)(device->message);
            primary::CHARGER_4* proto_msg = pack->add_charger_4();
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

        case 320: {
            primary_charger_5_t* msg = (primary_charger_5_t*)(device->message);
            primary::CHARGER_5* proto_msg = pack->add_charger_5();
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

        case 336: {
            primary_charger_6_t* msg = (primary_charger_6_t*)(device->message);
            primary::CHARGER_6* proto_msg = pack->add_charger_6();
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

        case 344: {
            primary_charger_7_t* msg = (primary_charger_7_t*)(device->message);
            primary::CHARGER_7* proto_msg = pack->add_charger_7();
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

        case 352: {
            primary_charger_8_t* msg = (primary_charger_8_t*)(device->message);
            primary::CHARGER_8* proto_msg = pack->add_charger_8();
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

        case 368: {
            primary_charger_9_t* msg = (primary_charger_9_t*)(device->message);
            primary::CHARGER_9* proto_msg = pack->add_charger_9();
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

        case 384: {
            primary_charger_10_t* msg = (primary_charger_10_t*)(device->message);
            primary::CHARGER_10* proto_msg = pack->add_charger_10();
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

        case 392: {
            primary_charger_11_t* msg = (primary_charger_11_t*)(device->message);
            primary::CHARGER_11* proto_msg = pack->add_charger_11();
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

        case 400: {
            primary_charger_12_t* msg = (primary_charger_12_t*)(device->message);
            primary::CHARGER_12* proto_msg = pack->add_charger_12();
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

        case 408: {
            primary_charger_13_t* msg = (primary_charger_13_t*)(device->message);
            primary::CHARGER_13* proto_msg = pack->add_charger_13();
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

        case 416: {
            primary_charger_14_t* msg = (primary_charger_14_t*)(device->message);
            primary::CHARGER_14* proto_msg = pack->add_charger_14();
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

        case 432: {
            primary_charger_15_t* msg = (primary_charger_15_t*)(device->message);
            primary::CHARGER_15* proto_msg = pack->add_charger_15();
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

        case 448: {
            primary_charger_16_t* msg = (primary_charger_16_t*)(device->message);
            primary::CHARGER_16* proto_msg = pack->add_charger_16();
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

        case 464: {
            primary_charger_17_t* msg = (primary_charger_17_t*)(device->message);
            primary::CHARGER_17* proto_msg = pack->add_charger_17();
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

        case 480: {
            primary_charger_18_t* msg = (primary_charger_18_t*)(device->message);
            primary::CHARGER_18* proto_msg = pack->add_charger_18();
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

        case 496: {
            primary_charger_19_t* msg = (primary_charger_19_t*)(device->message);
            primary::CHARGER_19* proto_msg = pack->add_charger_19();
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

        case 696: {
            primary_hv_feedback_digital_t* msg = (primary_hv_feedback_digital_t*)(device->message);
            primary::HV_FEEDBACK_DIGITAL* proto_msg = pack->add_hv_feedback_digital();
			proto_msg->set_digital_airn_open_com(msg->digital_airn_open_com);
			proto_msg->set_digital_airp_open_com(msg->digital_airp_open_com);
			proto_msg->set_digital_sd_imd_fb(msg->digital_sd_imd_fb);
			proto_msg->set_digital_sd_bms_fb(msg->digital_sd_bms_fb);
			proto_msg->set_digital_precharge_open_com(msg->digital_precharge_open_com);
			proto_msg->set_digital_precharge_open_mec(msg->digital_precharge_open_mec);
			proto_msg->set_digital_ts_less_than_60v(msg->digital_ts_less_than_60v);
			proto_msg->set_digital_plausible_state_persisted(msg->digital_plausible_state_persisted);
			proto_msg->set_digital_plausible_state(msg->digital_plausible_state);
			proto_msg->set_digital_not_bms_fault_cockpit_led(msg->digital_not_bms_fault_cockpit_led);
			proto_msg->set_digital_not_imd_fault_cockpit_led(msg->digital_not_imd_fault_cockpit_led);
			proto_msg->set_digital_indicator_connected(msg->digital_indicator_connected);
			proto_msg->set_digital_not_latch_reset(msg->digital_not_latch_reset);
			proto_msg->set_digital_plausible_state_latched(msg->digital_plausible_state_latched);
			proto_msg->set_digital_not_bms_fault_latched(msg->digital_not_bms_fault_latched);
			proto_msg->set_digital_not_imd_fault_latched(msg->digital_not_imd_fault_latched);
			proto_msg->set_digital_not_ext_fault_latched(msg->digital_not_ext_fault_latched);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 712: {
            primary_hv_feedback_analog_converted_t* msg = (primary_hv_feedback_analog_converted_t*)(device->message);
            primary::HV_FEEDBACK_ANALOG* proto_msg = pack->add_hv_feedback_analog();
			proto_msg->set_analog_airn_open_mec(msg->analog_airn_open_mec);
			proto_msg->set_analog_airp_open_mec(msg->analog_airp_open_mec);
			proto_msg->set_analog_imd_ok(msg->analog_imd_ok);
			proto_msg->set_analog_plausible_state_rc(msg->analog_plausible_state_rc);
			proto_msg->set_analog_tsal_green(msg->analog_tsal_green);
			proto_msg->set_analog_probing_3v3(msg->analog_probing_3v3);
			proto_msg->set_analog_v5_mcu(msg->analog_v5_mcu);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 720: {
            primary_hv_feedback_analog_sd_converted_t* msg = (primary_hv_feedback_analog_sd_converted_t*)(device->message);
            primary::HV_FEEDBACK_ANALOG_SD* proto_msg = pack->add_hv_feedback_analog_sd();
			proto_msg->set_sd_out(msg->sd_out);
			proto_msg->set_sd_in(msg->sd_in);
			proto_msg->set_sd_end(msg->sd_end);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 728: {
            primary_hv_feedback_enzomma_converted_t* msg = (primary_hv_feedback_enzomma_converted_t*)(device->message);
            primary::HV_FEEDBACK_ENZOMMA* proto_msg = pack->add_hv_feedback_enzomma();
			proto_msg->set_feedback((primary::primary_hv_feedback_enzomma_feedback)msg->feedback);
			proto_msg->set_status((primary::primary_hv_feedback_enzomma_status)msg->status);
			proto_msg->set_is_digital(msg->is_digital);
			proto_msg->set_digital(msg->digital);
			proto_msg->set_analog(msg->analog);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

    }
}



#endif // primary_PROTO_INTERAFCE_IMPLEMENTATION

#endif // primary_PROTO_INTERFACE_H
