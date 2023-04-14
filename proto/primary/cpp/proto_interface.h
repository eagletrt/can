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

#include "../../../lib/primary/c/network.h"

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
        primary_to_string_Toggle((primary_Toggle)pack->set_tlm_status(i).tlm_status(), buffer);
        (*net_strings)["SET_TLM_STATUS"]["tlm_status"].push(buffer);
        memset(buffer, 0, 1024);
    }
    for(int i = 0; i < pack->tlm_status_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->tlm_status(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->tlm_status(i)._inner_timestamp();
        (*net_signals)["TLM_STATUS"]["_timestamp"].push(pack->tlm_status(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

        (*net_enums)["TLM_STATUS"]["tlm_status"].push(pack->tlm_status(i).tlm_status());
        primary_to_string_Toggle((primary_Toggle)pack->tlm_status(i).tlm_status(), buffer);
        (*net_strings)["TLM_STATUS"]["tlm_status"].push(buffer);
        memset(buffer, 0, 1024);
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

        (*net_enums)["HV_ERRORS"]["warnings"].push(pack->hv_errors(i).warnings());
        primary_to_string_HvErrors((primary_HvErrors)pack->hv_errors(i).warnings(), buffer);
        (*net_strings)["HV_ERRORS"]["warnings"].push(buffer);
        memset(buffer, 0, 1024);
        (*net_enums)["HV_ERRORS"]["errors"].push(pack->hv_errors(i).errors());
        primary_to_string_HvErrors((primary_HvErrors)pack->hv_errors(i).errors(), buffer);
        (*net_strings)["HV_ERRORS"]["errors"].push(buffer);
        memset(buffer, 0, 1024);
    }
    for(int i = 0; i < pack->hv_can_forward_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_can_forward(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_can_forward(i)._inner_timestamp();
        (*net_signals)["HV_CAN_FORWARD"]["_timestamp"].push(pack->hv_can_forward(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

        (*net_enums)["HV_CAN_FORWARD"]["can_forward_set"].push(pack->hv_can_forward(i).can_forward_set());
        primary_to_string_Toggle((primary_Toggle)pack->hv_can_forward(i).can_forward_set(), buffer);
        (*net_strings)["HV_CAN_FORWARD"]["can_forward_set"].push(buffer);
        memset(buffer, 0, 1024);
    }
    for(int i = 0; i < pack->hv_fans_override_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_fans_override(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_fans_override(i)._inner_timestamp();
        (*net_signals)["HV_FANS_OVERRIDE"]["_timestamp"].push(pack->hv_fans_override(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

        (*net_enums)["HV_FANS_OVERRIDE"]["fans_override"].push(pack->hv_fans_override(i).fans_override());
        primary_to_string_Toggle((primary_Toggle)pack->hv_fans_override(i).fans_override(), buffer);
        (*net_strings)["HV_FANS_OVERRIDE"]["fans_override"].push(buffer);
        memset(buffer, 0, 1024);
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
        primary_to_string_Toggle((primary_Toggle)pack->hv_can_forward_status(i).can_forward_status(), buffer);
        (*net_strings)["HV_CAN_FORWARD_STATUS"]["can_forward_status"].push(buffer);
        memset(buffer, 0, 1024);
    }
    for(int i = 0; i < pack->hv_fans_override_status_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_fans_override_status(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_fans_override_status(i)._inner_timestamp();
        (*net_signals)["HV_FANS_OVERRIDE_STATUS"]["_timestamp"].push(pack->hv_fans_override_status(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

        (*net_enums)["HV_FANS_OVERRIDE_STATUS"]["fans_override"].push(pack->hv_fans_override_status(i).fans_override());
        primary_to_string_Toggle((primary_Toggle)pack->hv_fans_override_status(i).fans_override(), buffer);
        (*net_strings)["HV_FANS_OVERRIDE_STATUS"]["fans_override"].push(buffer);
        memset(buffer, 0, 1024);
        (*net_signals)["HV_FANS_OVERRIDE_STATUS"]["fans_speed"].push(pack->hv_fans_override_status(i).fans_speed());
    }
    for(int i = 0; i < pack->hv_feedbacks_status_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->hv_feedbacks_status(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->hv_feedbacks_status(i)._inner_timestamp();
        (*net_signals)["HV_FEEDBACKS_STATUS"]["_timestamp"].push(pack->hv_feedbacks_status(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

        (*net_enums)["HV_FEEDBACKS_STATUS"]["feedbacks_status"].push(pack->hv_feedbacks_status(i).feedbacks_status());
        primary_to_string_HvFeedbacks((primary_HvFeedbacks)pack->hv_feedbacks_status(i).feedbacks_status(), buffer);
        (*net_strings)["HV_FEEDBACKS_STATUS"]["feedbacks_status"].push(buffer);
        memset(buffer, 0, 1024);
        (*net_enums)["HV_FEEDBACKS_STATUS"]["is_circuitry_error"].push(pack->hv_feedbacks_status(i).is_circuitry_error());
        primary_to_string_HvFeedbacks((primary_HvFeedbacks)pack->hv_feedbacks_status(i).is_circuitry_error(), buffer);
        (*net_strings)["HV_FEEDBACKS_STATUS"]["is_circuitry_error"].push(buffer);
        memset(buffer, 0, 1024);
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
        primary_to_string_ImdStatus((primary_ImdStatus)pack->hv_imd_status(i).imd_status(), buffer);
        (*net_strings)["HV_IMD_STATUS"]["imd_status"].push(buffer);
        memset(buffer, 0, 1024);
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
        primary_to_string_TsStatus((primary_TsStatus)pack->ts_status(i).ts_status(), buffer);
        (*net_strings)["TS_STATUS"]["ts_status"].push(buffer);
        memset(buffer, 0, 1024);
    }
    for(int i = 0; i < pack->set_ts_status_das_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->set_ts_status_das(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->set_ts_status_das(i)._inner_timestamp();
        (*net_signals)["SET_TS_STATUS_DAS"]["_timestamp"].push(pack->set_ts_status_das(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

        (*net_enums)["SET_TS_STATUS_DAS"]["ts_status_set"].push(pack->set_ts_status_das(i).ts_status_set());
        primary_to_string_Toggle((primary_Toggle)pack->set_ts_status_das(i).ts_status_set(), buffer);
        (*net_strings)["SET_TS_STATUS_DAS"]["ts_status_set"].push(buffer);
        memset(buffer, 0, 1024);
    }
    for(int i = 0; i < pack->set_ts_status_handcart_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->set_ts_status_handcart(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->set_ts_status_handcart(i)._inner_timestamp();
        (*net_signals)["SET_TS_STATUS_HANDCART"]["_timestamp"].push(pack->set_ts_status_handcart(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

        (*net_enums)["SET_TS_STATUS_HANDCART"]["ts_status_set"].push(pack->set_ts_status_handcart(i).ts_status_set());
        primary_to_string_Toggle((primary_Toggle)pack->set_ts_status_handcart(i).ts_status_set(), buffer);
        (*net_strings)["SET_TS_STATUS_HANDCART"]["ts_status_set"].push(buffer);
        memset(buffer, 0, 1024);
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
        primary_to_string_SetCarStatus((primary_SetCarStatus)pack->set_car_status(i).car_status_set(), buffer);
        (*net_strings)["SET_CAR_STATUS"]["car_status_set"].push(buffer);
        memset(buffer, 0, 1024);
    }
    for(int i = 0; i < pack->set_pedals_range_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->set_pedals_range(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->set_pedals_range(i)._inner_timestamp();
        (*net_signals)["SET_PEDALS_RANGE"]["_timestamp"].push(pack->set_pedals_range(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

        (*net_enums)["SET_PEDALS_RANGE"]["bound"].push(pack->set_pedals_range(i).bound());
        primary_to_string_Bound((primary_Bound)pack->set_pedals_range(i).bound(), buffer);
        (*net_strings)["SET_PEDALS_RANGE"]["bound"].push(buffer);
        memset(buffer, 0, 1024);
        (*net_enums)["SET_PEDALS_RANGE"]["pedal"].push(pack->set_pedals_range(i).pedal());
        primary_to_string_Pedal((primary_Pedal)pack->set_pedals_range(i).pedal(), buffer);
        (*net_strings)["SET_PEDALS_RANGE"]["pedal"].push(buffer);
        memset(buffer, 0, 1024);
    }
    for(int i = 0; i < pack->set_steering_angle_range_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->set_steering_angle_range(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->set_steering_angle_range(i)._inner_timestamp();
        (*net_signals)["SET_STEERING_ANGLE_RANGE"]["_timestamp"].push(pack->set_steering_angle_range(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

        (*net_enums)["SET_STEERING_ANGLE_RANGE"]["bound"].push(pack->set_steering_angle_range(i).bound());
        primary_to_string_Bound((primary_Bound)pack->set_steering_angle_range(i).bound(), buffer);
        (*net_strings)["SET_STEERING_ANGLE_RANGE"]["bound"].push(buffer);
        memset(buffer, 0, 1024);
    }
    for(int i = 0; i < pack->car_status_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->car_status(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->car_status(i)._inner_timestamp();
        (*net_signals)["CAR_STATUS"]["_timestamp"].push(pack->car_status(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

        (*net_enums)["CAR_STATUS"]["inverter_l"].push(pack->car_status(i).inverter_l());
        primary_to_string_InverterStatus((primary_InverterStatus)pack->car_status(i).inverter_l(), buffer);
        (*net_strings)["CAR_STATUS"]["inverter_l"].push(buffer);
        memset(buffer, 0, 1024);
        (*net_enums)["CAR_STATUS"]["inverter_r"].push(pack->car_status(i).inverter_r());
        primary_to_string_InverterStatus((primary_InverterStatus)pack->car_status(i).inverter_r(), buffer);
        (*net_strings)["CAR_STATUS"]["inverter_r"].push(buffer);
        memset(buffer, 0, 1024);
        (*net_enums)["CAR_STATUS"]["car_status"].push(pack->car_status(i).car_status());
        primary_to_string_CarStatus((primary_CarStatus)pack->car_status(i).car_status(), buffer);
        (*net_strings)["CAR_STATUS"]["car_status"].push(buffer);
        memset(buffer, 0, 1024);
    }
    for(int i = 0; i < pack->das_errors_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->das_errors(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->das_errors(i)._inner_timestamp();
        (*net_signals)["DAS_ERRORS"]["_timestamp"].push(pack->das_errors(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

        (*net_enums)["DAS_ERRORS"]["das_error"].push(pack->das_errors(i).das_error());
        primary_to_string_DasErrors((primary_DasErrors)pack->das_errors(i).das_error(), buffer);
        (*net_strings)["DAS_ERRORS"]["das_error"].push(buffer);
        memset(buffer, 0, 1024);
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
        primary_to_string_Toggle((primary_Toggle)pack->set_inverter_connection_status(i).status(), buffer);
        (*net_strings)["SET_INVERTER_CONNECTION_STATUS"]["status"].push(buffer);
        memset(buffer, 0, 1024);
    }
    for(int i = 0; i < pack->inverter_connection_status_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->inverter_connection_status(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->inverter_connection_status(i)._inner_timestamp();
        (*net_signals)["INVERTER_CONNECTION_STATUS"]["_timestamp"].push(pack->inverter_connection_status(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

        (*net_enums)["INVERTER_CONNECTION_STATUS"]["status"].push(pack->inverter_connection_status(i).status());
        primary_to_string_Toggle((primary_Toggle)pack->inverter_connection_status(i).status(), buffer);
        (*net_strings)["INVERTER_CONNECTION_STATUS"]["status"].push(buffer);
        memset(buffer, 0, 1024);
    }
    for(int i = 0; i < pack->lv_errors_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->lv_errors(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->lv_errors(i)._inner_timestamp();
        (*net_signals)["LV_ERRORS"]["_timestamp"].push(pack->lv_errors(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

        (*net_enums)["LV_ERRORS"]["warnings"].push(pack->lv_errors(i).warnings());
        primary_to_string_LvErrors((primary_LvErrors)pack->lv_errors(i).warnings(), buffer);
        (*net_strings)["LV_ERRORS"]["warnings"].push(buffer);
        memset(buffer, 0, 1024);
        (*net_enums)["LV_ERRORS"]["errors"].push(pack->lv_errors(i).errors());
        primary_to_string_LvErrors((primary_LvErrors)pack->lv_errors(i).errors(), buffer);
        (*net_strings)["LV_ERRORS"]["errors"].push(buffer);
        memset(buffer, 0, 1024);
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
        primary_to_string_Toggle((primary_Toggle)pack->hv_cell_balancing_status(i).balancing_status(), buffer);
        (*net_strings)["HV_CELL_BALANCING_STATUS"]["balancing_status"].push(buffer);
        memset(buffer, 0, 1024);
    }
    for(int i = 0; i < pack->set_cell_balancing_status_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->set_cell_balancing_status(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->set_cell_balancing_status(i)._inner_timestamp();
        (*net_signals)["SET_CELL_BALANCING_STATUS"]["_timestamp"].push(pack->set_cell_balancing_status(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

        (*net_enums)["SET_CELL_BALANCING_STATUS"]["set_balancing_status"].push(pack->set_cell_balancing_status(i).set_balancing_status());
        primary_to_string_Toggle((primary_Toggle)pack->set_cell_balancing_status(i).set_balancing_status(), buffer);
        (*net_strings)["SET_CELL_BALANCING_STATUS"]["set_balancing_status"].push(buffer);
        memset(buffer, 0, 1024);
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
        case 0: {
            primary_message_BMS_HV_JMP_TO_BLT* msg = (primary_message_BMS_HV_JMP_TO_BLT*)(&(*map)[index].message_raw);
            primary::BMS_HV_JMP_TO_BLT* proto_msg = pack->add_bms_hv_jmp_to_blt();
            break;
        }
        case 32: {
            primary_message_BMS_LV_JMP_TO_BLT* msg = (primary_message_BMS_LV_JMP_TO_BLT*)(&(*map)[index].message_raw);
            primary::BMS_LV_JMP_TO_BLT* proto_msg = pack->add_bms_lv_jmp_to_blt();
            break;
        }
        case 1025: {
            primary_message_STEER_VERSION* msg = (primary_message_STEER_VERSION*)(&(*map)[index].message_raw);
            primary::STEER_VERSION* proto_msg = pack->add_steer_version();
            proto_msg->set_component_version(msg->component_version);
            proto_msg->set_canlib_build_time(msg->canlib_build_time);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }
        case 1057: {
            primary_message_DAS_VERSION* msg = (primary_message_DAS_VERSION*)(&(*map)[index].message_raw);
            primary::DAS_VERSION* proto_msg = pack->add_das_version();
            proto_msg->set_component_version(msg->component_version);
            proto_msg->set_canlib_build_time(msg->canlib_build_time);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }
        case 1089: {
            primary_message_HV_VERSION* msg = (primary_message_HV_VERSION*)(&(*map)[index].message_raw);
            primary::HV_VERSION* proto_msg = pack->add_hv_version();
            proto_msg->set_component_version(msg->component_version);
            proto_msg->set_canlib_build_time(msg->canlib_build_time);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }
        case 1121: {
            primary_message_LV_VERSION* msg = (primary_message_LV_VERSION*)(&(*map)[index].message_raw);
            primary::LV_VERSION* proto_msg = pack->add_lv_version();
            proto_msg->set_component_version(msg->component_version);
            proto_msg->set_canlib_build_time(msg->canlib_build_time);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }
        case 1153: {
            primary_message_TLM_VERSION* msg = (primary_message_TLM_VERSION*)(&(*map)[index].message_raw);
            primary::TLM_VERSION* proto_msg = pack->add_tlm_version();
            proto_msg->set_component_version(msg->component_version);
            proto_msg->set_canlib_build_time(msg->canlib_build_time);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }
        case 257: {
            primary_message_TIMESTAMP* msg = (primary_message_TIMESTAMP*)(&(*map)[index].message_raw);
            primary::TIMESTAMP* proto_msg = pack->add_timestamp();
            proto_msg->set_timestamp(msg->timestamp);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }
        case 289: {
            primary_message_AMBIENT_TEMPERATURE* msg = (primary_message_AMBIENT_TEMPERATURE*)(&(*map)[index].message_raw);
            primary::AMBIENT_TEMPERATURE* proto_msg = pack->add_ambient_temperature();
            proto_msg->set_temp(msg->temp);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }
        case 1072: {
            primary_message_DATA_LOGGER* msg = (primary_message_DATA_LOGGER*)(&(*map)[index].message_raw);
            primary::DATA_LOGGER* proto_msg = pack->add_data_logger();
            proto_msg->set_placeholder1(msg->placeholder1);
            proto_msg->set_placeholder2(msg->placeholder2);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }
        case 259: {
            primary_message_SET_TLM_STATUS* msg = (primary_message_SET_TLM_STATUS*)(&(*map)[index].message_raw);
            primary::SET_TLM_STATUS* proto_msg = pack->add_set_tlm_status();
            proto_msg->set_tlm_status((primary::Toggle)msg->tlm_status);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }
        case 260: {
            primary_message_TLM_STATUS* msg = (primary_message_TLM_STATUS*)(&(*map)[index].message_raw);
            primary::TLM_STATUS* proto_msg = pack->add_tlm_status();
            proto_msg->set_tlm_status((primary::Toggle)msg->tlm_status);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }
        case 1795: {
            primary_message_STEER_SYSTEM_STATUS* msg = (primary_message_STEER_SYSTEM_STATUS*)(&(*map)[index].message_raw);
            primary::STEER_SYSTEM_STATUS* proto_msg = pack->add_steer_system_status();
            proto_msg->set_soc_temp(msg->soc_temp);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }
        case 773: {
            primary_message_HV_VOLTAGE_conversion* msg = (primary_message_HV_VOLTAGE_conversion*)(&(*map)[index].message_conversion);
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
        case 805: {
            primary_message_HV_CURRENT_conversion* msg = (primary_message_HV_CURRENT_conversion*)(&(*map)[index].message_conversion);
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
        case 837: {
            primary_message_HV_TEMP_conversion* msg = (primary_message_HV_TEMP_conversion*)(&(*map)[index].message_conversion);
            primary::HV_TEMP* proto_msg = pack->add_hv_temp();
            proto_msg->set_average_temp(msg->average_temp);
            proto_msg->set_max_temp(msg->max_temp);
            proto_msg->set_min_temp(msg->min_temp);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }
        case 5: {
            primary_message_HV_ERRORS* msg = (primary_message_HV_ERRORS*)(&(*map)[index].message_raw);
            primary::HV_ERRORS* proto_msg = pack->add_hv_errors();
            proto_msg->set_warnings(msg->warnings);
            proto_msg->set_errors(msg->errors);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }
        case 6: {
            primary_message_HV_CAN_FORWARD* msg = (primary_message_HV_CAN_FORWARD*)(&(*map)[index].message_raw);
            primary::HV_CAN_FORWARD* proto_msg = pack->add_hv_can_forward();
            proto_msg->set_can_forward_set((primary::Toggle)msg->can_forward_set);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }
        case 38: {
            primary_message_HV_FANS_OVERRIDE_conversion* msg = (primary_message_HV_FANS_OVERRIDE_conversion*)(&(*map)[index].message_conversion);
            primary::HV_FANS_OVERRIDE* proto_msg = pack->add_hv_fans_override();
            proto_msg->set_fans_override((primary::Toggle)msg->fans_override);
            proto_msg->set_fans_speed(msg->fans_speed);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }
        case 7: {
            primary_message_HV_CAN_FORWARD_STATUS* msg = (primary_message_HV_CAN_FORWARD_STATUS*)(&(*map)[index].message_raw);
            primary::HV_CAN_FORWARD_STATUS* proto_msg = pack->add_hv_can_forward_status();
            proto_msg->set_can_forward_status((primary::Toggle)msg->can_forward_status);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }
        case 775: {
            primary_message_HV_FANS_OVERRIDE_STATUS_conversion* msg = (primary_message_HV_FANS_OVERRIDE_STATUS_conversion*)(&(*map)[index].message_conversion);
            primary::HV_FANS_OVERRIDE_STATUS* proto_msg = pack->add_hv_fans_override_status();
            proto_msg->set_fans_override((primary::Toggle)msg->fans_override);
            proto_msg->set_fans_speed(msg->fans_speed);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }
        case 776: {
            primary_message_HV_FEEDBACKS_STATUS* msg = (primary_message_HV_FEEDBACKS_STATUS*)(&(*map)[index].message_raw);
            primary::HV_FEEDBACKS_STATUS* proto_msg = pack->add_hv_feedbacks_status();
            proto_msg->set_feedbacks_status(msg->feedbacks_status);
            proto_msg->set_is_circuitry_error(msg->is_circuitry_error);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }
        case 808: {
            primary_message_HV_IMD_STATUS* msg = (primary_message_HV_IMD_STATUS*)(&(*map)[index].message_raw);
            primary::HV_IMD_STATUS* proto_msg = pack->add_hv_imd_status();
            proto_msg->set_imd_fault(msg->imd_fault);
            proto_msg->set_imd_status((primary::ImdStatus)msg->imd_status);
            proto_msg->set_imd_info(msg->imd_info);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }
        case 37: {
            primary_message_TS_STATUS* msg = (primary_message_TS_STATUS*)(&(*map)[index].message_raw);
            primary::TS_STATUS* proto_msg = pack->add_ts_status();
            proto_msg->set_ts_status((primary::TsStatus)msg->ts_status);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }
        case 70: {
            primary_message_SET_TS_STATUS* msg = (primary_message_SET_TS_STATUS*)(&(*map)[index].message_raw);
            primary::SET_TS_STATUS_DAS* proto_msg = pack->add_set_ts_status_das();
            proto_msg->set_ts_status_set((primary::Toggle)msg->ts_status_set);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }
        case 102: {
            primary_message_SET_TS_STATUS* msg = (primary_message_SET_TS_STATUS*)(&(*map)[index].message_raw);
            primary::SET_TS_STATUS_HANDCART* proto_msg = pack->add_set_ts_status_handcart();
            proto_msg->set_ts_status_set((primary::Toggle)msg->ts_status_set);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }
        case 265: {
            primary_message_STEER_STATUS_conversion* msg = (primary_message_STEER_STATUS_conversion*)(&(*map)[index].message_conversion);
            primary::STEER_STATUS* proto_msg = pack->add_steer_status();
            proto_msg->set_map_pw(msg->map_pw);
            proto_msg->set_map_sc(msg->map_sc);
            proto_msg->set_map_tv(msg->map_tv);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }
        case 777: {
            primary_message_SET_CAR_STATUS* msg = (primary_message_SET_CAR_STATUS*)(&(*map)[index].message_raw);
            primary::SET_CAR_STATUS* proto_msg = pack->add_set_car_status();
            proto_msg->set_car_status_set((primary::SetCarStatus)msg->car_status_set);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }
        case 1033: {
            primary_message_SET_PEDALS_RANGE* msg = (primary_message_SET_PEDALS_RANGE*)(&(*map)[index].message_raw);
            primary::SET_PEDALS_RANGE* proto_msg = pack->add_set_pedals_range();
            proto_msg->set_bound((primary::Bound)msg->bound);
            proto_msg->set_pedal((primary::Pedal)msg->pedal);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }
        case 1065: {
            primary_message_SET_STEERING_ANGLE_RANGE* msg = (primary_message_SET_STEERING_ANGLE_RANGE*)(&(*map)[index].message_raw);
            primary::SET_STEERING_ANGLE_RANGE* proto_msg = pack->add_set_steering_angle_range();
            proto_msg->set_bound((primary::Bound)msg->bound);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }
        case 516: {
            primary_message_CAR_STATUS* msg = (primary_message_CAR_STATUS*)(&(*map)[index].message_raw);
            primary::CAR_STATUS* proto_msg = pack->add_car_status();
            proto_msg->set_inverter_l((primary::InverterStatus)msg->inverter_l);
            proto_msg->set_inverter_r((primary::InverterStatus)msg->inverter_r);
            proto_msg->set_car_status((primary::CarStatus)msg->car_status);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }
        case 4: {
            primary_message_DAS_ERRORS* msg = (primary_message_DAS_ERRORS*)(&(*map)[index].message_raw);
            primary::DAS_ERRORS* proto_msg = pack->add_das_errors();
            proto_msg->set_das_error(msg->das_error);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }
        case 840: {
            primary_message_LV_CURRENT_conversion* msg = (primary_message_LV_CURRENT_conversion*)(&(*map)[index].message_conversion);
            primary::LV_CURRENT* proto_msg = pack->add_lv_current();
            proto_msg->set_current(msg->current);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }
        case 872: {
            primary_message_LV_VOLTAGE_conversion* msg = (primary_message_LV_VOLTAGE_conversion*)(&(*map)[index].message_conversion);
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
        case 904: {
            primary_message_LV_TOTAL_VOLTAGE_conversion* msg = (primary_message_LV_TOTAL_VOLTAGE_conversion*)(&(*map)[index].message_conversion);
            primary::LV_TOTAL_VOLTAGE* proto_msg = pack->add_lv_total_voltage();
            proto_msg->set_total_voltage(msg->total_voltage);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }
        case 936: {
            primary_message_LV_TEMPERATURE_conversion* msg = (primary_message_LV_TEMPERATURE_conversion*)(&(*map)[index].message_conversion);
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
        case 968: {
            primary_message_COOLING_STATUS_conversion* msg = (primary_message_COOLING_STATUS_conversion*)(&(*map)[index].message_conversion);
            primary::COOLING_STATUS* proto_msg = pack->add_cooling_status();
            proto_msg->set_radiators_speed(msg->radiators_speed);
            proto_msg->set_pumps_speed(msg->pumps_speed);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }
        case 778: {
            primary_message_SET_RADIATOR_SPEED_conversion* msg = (primary_message_SET_RADIATOR_SPEED_conversion*)(&(*map)[index].message_conversion);
            primary::SET_RADIATOR_SPEED* proto_msg = pack->add_set_radiator_speed();
            proto_msg->set_radiators_speed(msg->radiators_speed);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }
        case 810: {
            primary_message_SET_PUMPS_SPEED_conversion* msg = (primary_message_SET_PUMPS_SPEED_conversion*)(&(*map)[index].message_conversion);
            primary::SET_PUMPS_SPEED* proto_msg = pack->add_set_pumps_speed();
            proto_msg->set_pumps_speed(msg->pumps_speed);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }
        case 266: {
            primary_message_SET_INVERTER_CONNECTION_STATUS* msg = (primary_message_SET_INVERTER_CONNECTION_STATUS*)(&(*map)[index].message_raw);
            primary::SET_INVERTER_CONNECTION_STATUS* proto_msg = pack->add_set_inverter_connection_status();
            proto_msg->set_status((primary::Toggle)msg->status);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }
        case 264: {
            primary_message_INVERTER_CONNECTION_STATUS* msg = (primary_message_INVERTER_CONNECTION_STATUS*)(&(*map)[index].message_raw);
            primary::INVERTER_CONNECTION_STATUS* proto_msg = pack->add_inverter_connection_status();
            proto_msg->set_status((primary::Toggle)msg->status);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }
        case 8: {
            primary_message_LV_ERRORS* msg = (primary_message_LV_ERRORS*)(&(*map)[index].message_raw);
            primary::LV_ERRORS* proto_msg = pack->add_lv_errors();
            proto_msg->set_warnings(msg->warnings);
            proto_msg->set_errors(msg->errors);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }
        case 296: {
            primary_message_SHUTDOWN_STATUS* msg = (primary_message_SHUTDOWN_STATUS*)(&(*map)[index].message_raw);
            primary::SHUTDOWN_STATUS* proto_msg = pack->add_shutdown_status();
            proto_msg->set_input(msg->input);
            proto_msg->set_output(msg->output);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }
        case 3: {
            primary_message_MARKER* msg = (primary_message_MARKER*)(&(*map)[index].message_raw);
            primary::MARKER* proto_msg = pack->add_marker();
            break;
        }
        case 519: {
            primary_message_HV_CELLS_VOLTAGE_conversion* msg = (primary_message_HV_CELLS_VOLTAGE_conversion*)(&(*map)[index].message_conversion);
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
        case 551: {
            primary_message_HV_CELLS_TEMP_conversion* msg = (primary_message_HV_CELLS_TEMP_conversion*)(&(*map)[index].message_conversion);
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
        case 583: {
            primary_message_HV_CELL_BALANCING_STATUS* msg = (primary_message_HV_CELL_BALANCING_STATUS*)(&(*map)[index].message_raw);
            primary::HV_CELL_BALANCING_STATUS* proto_msg = pack->add_hv_cell_balancing_status();
            proto_msg->set_balancing_status((primary::Toggle)msg->balancing_status);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }
        case 518: {
            primary_message_SET_CELL_BALANCING_STATUS* msg = (primary_message_SET_CELL_BALANCING_STATUS*)(&(*map)[index].message_raw);
            primary::SET_CELL_BALANCING_STATUS* proto_msg = pack->add_set_cell_balancing_status();
            proto_msg->set_set_balancing_status((primary::Toggle)msg->set_balancing_status);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }
        case 774: {
            primary_message_HANDCART_STATUS* msg = (primary_message_HANDCART_STATUS*)(&(*map)[index].message_raw);
            primary::HANDCART_STATUS* proto_msg = pack->add_handcart_status();
            proto_msg->set_connected(msg->connected);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }
        case 548: {
            primary_message_SPEED_conversion* msg = (primary_message_SPEED_conversion*)(&(*map)[index].message_conversion);
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
            primary_message_INV_L_REQUEST* msg = (primary_message_INV_L_REQUEST*)(&(*map)[index].message_raw);
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
            primary_message_INV_R_REQUEST* msg = (primary_message_INV_R_REQUEST*)(&(*map)[index].message_raw);
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
            primary_message_INV_L_RESPONSE* msg = (primary_message_INV_L_RESPONSE*)(&(*map)[index].message_raw);
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
            primary_message_INV_R_RESPONSE* msg = (primary_message_INV_R_RESPONSE*)(&(*map)[index].message_raw);
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
            primary_message_FLASH_CELLBOARD_0_TX* msg = (primary_message_FLASH_CELLBOARD_0_TX*)(&(*map)[index].message_raw);
            primary::FLASH_CELLBOARD_0_TX* proto_msg = pack->add_flash_cellboard_0_tx();
            break;
        }
        case 17: {
            primary_message_FLASH_CELLBOARD_0_RX* msg = (primary_message_FLASH_CELLBOARD_0_RX*)(&(*map)[index].message_raw);
            primary::FLASH_CELLBOARD_0_RX* proto_msg = pack->add_flash_cellboard_0_rx();
            break;
        }
        case 18: {
            primary_message_FLASH_CELLBOARD_1_TX* msg = (primary_message_FLASH_CELLBOARD_1_TX*)(&(*map)[index].message_raw);
            primary::FLASH_CELLBOARD_1_TX* proto_msg = pack->add_flash_cellboard_1_tx();
            break;
        }
        case 19: {
            primary_message_FLASH_CELLBOARD_1_RX* msg = (primary_message_FLASH_CELLBOARD_1_RX*)(&(*map)[index].message_raw);
            primary::FLASH_CELLBOARD_1_RX* proto_msg = pack->add_flash_cellboard_1_rx();
            break;
        }
        case 20: {
            primary_message_FLASH_CELLBOARD_2_TX* msg = (primary_message_FLASH_CELLBOARD_2_TX*)(&(*map)[index].message_raw);
            primary::FLASH_CELLBOARD_2_TX* proto_msg = pack->add_flash_cellboard_2_tx();
            break;
        }
        case 21: {
            primary_message_FLASH_CELLBOARD_2_RX* msg = (primary_message_FLASH_CELLBOARD_2_RX*)(&(*map)[index].message_raw);
            primary::FLASH_CELLBOARD_2_RX* proto_msg = pack->add_flash_cellboard_2_rx();
            break;
        }
        case 22: {
            primary_message_FLASH_CELLBOARD_3_TX* msg = (primary_message_FLASH_CELLBOARD_3_TX*)(&(*map)[index].message_raw);
            primary::FLASH_CELLBOARD_3_TX* proto_msg = pack->add_flash_cellboard_3_tx();
            break;
        }
        case 23: {
            primary_message_FLASH_CELLBOARD_3_RX* msg = (primary_message_FLASH_CELLBOARD_3_RX*)(&(*map)[index].message_raw);
            primary::FLASH_CELLBOARD_3_RX* proto_msg = pack->add_flash_cellboard_3_rx();
            break;
        }
        case 24: {
            primary_message_FLASH_CELLBOARD_4_TX* msg = (primary_message_FLASH_CELLBOARD_4_TX*)(&(*map)[index].message_raw);
            primary::FLASH_CELLBOARD_4_TX* proto_msg = pack->add_flash_cellboard_4_tx();
            break;
        }
        case 25: {
            primary_message_FLASH_CELLBOARD_4_RX* msg = (primary_message_FLASH_CELLBOARD_4_RX*)(&(*map)[index].message_raw);
            primary::FLASH_CELLBOARD_4_RX* proto_msg = pack->add_flash_cellboard_4_rx();
            break;
        }
        case 26: {
            primary_message_FLASH_CELLBOARD_5_TX* msg = (primary_message_FLASH_CELLBOARD_5_TX*)(&(*map)[index].message_raw);
            primary::FLASH_CELLBOARD_5_TX* proto_msg = pack->add_flash_cellboard_5_tx();
            break;
        }
        case 27: {
            primary_message_FLASH_CELLBOARD_5_RX* msg = (primary_message_FLASH_CELLBOARD_5_RX*)(&(*map)[index].message_raw);
            primary::FLASH_CELLBOARD_5_RX* proto_msg = pack->add_flash_cellboard_5_rx();
            break;
        }
        case 2017: {
            primary_message_FLASH_BMS_HV_TX* msg = (primary_message_FLASH_BMS_HV_TX*)(&(*map)[index].message_raw);
            primary::FLASH_BMS_HV_TX* proto_msg = pack->add_flash_bms_hv_tx();
            break;
        }
        case 1639: {
            primary_message_FLASH_BMS_HV_RX* msg = (primary_message_FLASH_BMS_HV_RX*)(&(*map)[index].message_raw);
            primary::FLASH_BMS_HV_RX* proto_msg = pack->add_flash_bms_hv_rx();
            break;
        }
        case 2033: {
            primary_message_FLASH_BMS_LV_TX* msg = (primary_message_FLASH_BMS_LV_TX*)(&(*map)[index].message_raw);
            primary::FLASH_BMS_LV_TX* proto_msg = pack->add_flash_bms_lv_tx();
            break;
        }
        case 1655: {
            primary_message_FLASH_BMS_LV_RX* msg = (primary_message_FLASH_BMS_LV_RX*)(&(*map)[index].message_raw);
            primary::FLASH_BMS_LV_RX* proto_msg = pack->add_flash_bms_lv_rx();
            break;
        }
        case 618: {
            primary_message_BRUSA_NLG5_CTL* msg = (primary_message_BRUSA_NLG5_CTL*)(&(*map)[index].message_raw);
            primary::BRUSA_NLG5_CTL* proto_msg = pack->add_brusa_nlg5_ctl();
            break;
        }
        case 610: {
            primary_message_BRUSA_ST* msg = (primary_message_BRUSA_ST*)(&(*map)[index].message_raw);
            primary::BRUSA_ST* proto_msg = pack->add_brusa_st();
            break;
        }
        case 611: {
            primary_message_BRUSA_ACT_I* msg = (primary_message_BRUSA_ACT_I*)(&(*map)[index].message_raw);
            primary::BRUSA_ACT_I* proto_msg = pack->add_brusa_act_i();
            break;
        }
        case 612: {
            primary_message_BRUSA_ACT_II* msg = (primary_message_BRUSA_ACT_II*)(&(*map)[index].message_raw);
            primary::BRUSA_ACT_II* proto_msg = pack->add_brusa_act_ii();
            break;
        }
        case 613: {
            primary_message_BRUSA_TEMP* msg = (primary_message_BRUSA_TEMP*)(&(*map)[index].message_raw);
            primary::BRUSA_TEMP* proto_msg = pack->add_brusa_temp();
            break;
        }
        case 614: {
            primary_message_BRUSA_ERR* msg = (primary_message_BRUSA_ERR*)(&(*map)[index].message_raw);
            primary::BRUSA_ERR* proto_msg = pack->add_brusa_err();
            break;
        }
        case 1284: {
            primary_message_CONTROL_OUTPUT_conversion* msg = (primary_message_CONTROL_OUTPUT_conversion*)(&(*map)[index].message_conversion);
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
        case 523: {
            primary_message_LC_RESET* msg = (primary_message_LC_RESET*)(&(*map)[index].message_raw);
            primary::LC_RESET* proto_msg = pack->add_lc_reset();
            break;
        }
    }
}



#endif // primary_PROTO_INTERAFCE_IMPLEMENTATION

#endif // primary_PROTO_INTERFACE_H