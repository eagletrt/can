
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

#include "../../lib/primary/network.h"

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

    for(int i = 0; i < pack->set_ts_status_size(); i++){
#ifdef CANLIB_TIMESTAMP
        static uint64_t last_timestamp = 0;
        if(pack->set_ts_status(i)._inner_timestamp() - last_timestamp < resample_us) continue;
        else last_timestamp = pack->set_ts_status(i)._inner_timestamp();
        (*net_signals)["SET_TS_STATUS"]["_timestamp"].push(pack->set_ts_status(i)._inner_timestamp());
#endif // CANLIB_TIMESTAMP

		(*net_enums)["SET_TS_STATUS"]["ts_status_set"].push(pack->set_ts_status(i).ts_status_set());
		primary_set_ts_status_ts_status_set_enum_to_string((primary_set_ts_status_ts_status_set)pack->set_ts_status(i).ts_status_set(), buffer);
		(*net_strings)["SET_TS_STATUS"]["ts_status_set"].push(buffer);

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
        
        case 5: {
            primary_bms_hv_jmp_to_blt_t* msg = (primary_bms_hv_jmp_to_blt_t*)((*map)[index].message_raw);
            primary::BMS_HV_JMP_TO_BLT* proto_msg = pack->add_bms_hv_jmp_to_blt();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 37: {
            primary_bms_lv_jmp_to_blt_t* msg = (primary_bms_lv_jmp_to_blt_t*)((*map)[index].message_raw);
            primary::BMS_LV_JMP_TO_BLT* proto_msg = pack->add_bms_lv_jmp_to_blt();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1025: {
            primary_steer_version_t* msg = (primary_steer_version_t*)((*map)[index].message_raw);
            primary::STEER_VERSION* proto_msg = pack->add_steer_version();
			proto_msg->set_component_version(msg->component_version);
			proto_msg->set_canlib_build_time(msg->canlib_build_time);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1057: {
            primary_das_version_t* msg = (primary_das_version_t*)((*map)[index].message_raw);
            primary::DAS_VERSION* proto_msg = pack->add_das_version();
			proto_msg->set_component_version(msg->component_version);
			proto_msg->set_canlib_build_time(msg->canlib_build_time);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1089: {
            primary_hv_version_t* msg = (primary_hv_version_t*)((*map)[index].message_raw);
            primary::HV_VERSION* proto_msg = pack->add_hv_version();
			proto_msg->set_component_version(msg->component_version);
			proto_msg->set_canlib_build_time(msg->canlib_build_time);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1121: {
            primary_lv_version_t* msg = (primary_lv_version_t*)((*map)[index].message_raw);
            primary::LV_VERSION* proto_msg = pack->add_lv_version();
			proto_msg->set_component_version(msg->component_version);
			proto_msg->set_canlib_build_time(msg->canlib_build_time);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1153: {
            primary_tlm_version_t* msg = (primary_tlm_version_t*)((*map)[index].message_raw);
            primary::TLM_VERSION* proto_msg = pack->add_tlm_version();
			proto_msg->set_component_version(msg->component_version);
			proto_msg->set_canlib_build_time(msg->canlib_build_time);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 257: {
            primary_timestamp_t* msg = (primary_timestamp_t*)((*map)[index].message_raw);
            primary::TIMESTAMP* proto_msg = pack->add_timestamp();
			proto_msg->set_timestamp(msg->timestamp);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 289: {
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

        case 260: {
            primary_set_tlm_status_t* msg = (primary_set_tlm_status_t*)((*map)[index].message_raw);
            primary::SET_TLM_STATUS* proto_msg = pack->add_set_tlm_status();
			proto_msg->set_tlm_status((primary::primary_set_tlm_status_tlm_status)msg->tlm_status);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 259: {
            primary_tlm_status_t* msg = (primary_tlm_status_t*)((*map)[index].message_raw);
            primary::TLM_STATUS* proto_msg = pack->add_tlm_status();
			proto_msg->set_tlm_status((primary::primary_tlm_status_tlm_status)msg->tlm_status);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1796: {
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

        case 2: {
            primary_hv_can_forward_t* msg = (primary_hv_can_forward_t*)((*map)[index].message_raw);
            primary::HV_CAN_FORWARD* proto_msg = pack->add_hv_can_forward();
			proto_msg->set_can_forward_set((primary::primary_hv_can_forward_can_forward_set)msg->can_forward_set);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 34: {
            primary_hv_fans_override_converted_t* msg = (primary_hv_fans_override_converted_t*)((*map)[index].message_conversion);
            primary::HV_FANS_OVERRIDE* proto_msg = pack->add_hv_fans_override();
			proto_msg->set_fans_override((primary::primary_hv_fans_override_fans_override)msg->fans_override);
			proto_msg->set_fans_speed(msg->fans_speed);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 0: {
            primary_hv_can_forward_status_t* msg = (primary_hv_can_forward_status_t*)((*map)[index].message_raw);
            primary::HV_CAN_FORWARD_STATUS* proto_msg = pack->add_hv_can_forward_status();
			proto_msg->set_can_forward_status((primary::primary_hv_can_forward_status_can_forward_status)msg->can_forward_status);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 768: {
            primary_hv_fans_override_status_converted_t* msg = (primary_hv_fans_override_status_converted_t*)((*map)[index].message_conversion);
            primary::HV_FANS_OVERRIDE_STATUS* proto_msg = pack->add_hv_fans_override_status();
			proto_msg->set_fans_override((primary::primary_hv_fans_override_status_fans_override)msg->fans_override);
			proto_msg->set_fans_speed(msg->fans_speed);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 778: {
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

        case 810: {
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
            primary_ts_status_t* msg = (primary_ts_status_t*)((*map)[index].message_raw);
            primary::TS_STATUS* proto_msg = pack->add_ts_status();
			proto_msg->set_ts_status((primary::primary_ts_status_ts_status)msg->ts_status);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 98: {
            primary_set_ts_status_t* msg = (primary_set_ts_status_t*)((*map)[index].message_raw);
            primary::SET_TS_STATUS* proto_msg = pack->add_set_ts_status();
			proto_msg->set_ts_status_set((primary::primary_set_ts_status_ts_status_set)msg->ts_status_set);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 265: {
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

        case 777: {
            primary_set_car_status_t* msg = (primary_set_car_status_t*)((*map)[index].message_raw);
            primary::SET_CAR_STATUS* proto_msg = pack->add_set_car_status();
			proto_msg->set_car_status_set((primary::primary_set_car_status_car_status_set)msg->car_status_set);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1033: {
            primary_set_pedals_range_t* msg = (primary_set_pedals_range_t*)((*map)[index].message_raw);
            primary::SET_PEDALS_RANGE* proto_msg = pack->add_set_pedals_range();
			proto_msg->set_bound((primary::primary_set_pedals_range_bound)msg->bound);
			proto_msg->set_pedal((primary::primary_set_pedals_range_pedal)msg->pedal);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1065: {
            primary_set_steering_angle_range_t* msg = (primary_set_steering_angle_range_t*)((*map)[index].message_raw);
            primary::SET_STEERING_ANGLE_RANGE* proto_msg = pack->add_set_steering_angle_range();
			proto_msg->set_bound((primary::primary_set_steering_angle_range_bound)msg->bound);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 515: {
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

        case 3: {
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

        case 842: {
            primary_lv_current_converted_t* msg = (primary_lv_current_converted_t*)((*map)[index].message_conversion);
            primary::LV_CURRENT* proto_msg = pack->add_lv_current();
			proto_msg->set_current(msg->current);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 874: {
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

        case 906: {
            primary_lv_total_voltage_converted_t* msg = (primary_lv_total_voltage_converted_t*)((*map)[index].message_conversion);
            primary::LV_TOTAL_VOLTAGE* proto_msg = pack->add_lv_total_voltage();
			proto_msg->set_total_voltage(msg->total_voltage);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 938: {
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

        case 970: {
            primary_cooling_status_converted_t* msg = (primary_cooling_status_converted_t*)((*map)[index].message_conversion);
            primary::COOLING_STATUS* proto_msg = pack->add_cooling_status();
			proto_msg->set_radiators_speed(msg->radiators_speed);
			proto_msg->set_pumps_speed(msg->pumps_speed);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 775: {
            primary_set_radiator_speed_converted_t* msg = (primary_set_radiator_speed_converted_t*)((*map)[index].message_conversion);
            primary::SET_RADIATOR_SPEED* proto_msg = pack->add_set_radiator_speed();
			proto_msg->set_radiators_speed(msg->radiators_speed);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 807: {
            primary_set_pumps_speed_converted_t* msg = (primary_set_pumps_speed_converted_t*)((*map)[index].message_conversion);
            primary::SET_PUMPS_SPEED* proto_msg = pack->add_set_pumps_speed();
			proto_msg->set_pumps_speed(msg->pumps_speed);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 263: {
            primary_set_inverter_connection_status_t* msg = (primary_set_inverter_connection_status_t*)((*map)[index].message_raw);
            primary::SET_INVERTER_CONNECTION_STATUS* proto_msg = pack->add_set_inverter_connection_status();
			proto_msg->set_status((primary::primary_set_inverter_connection_status_status)msg->status);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 266: {
            primary_inverter_connection_status_t* msg = (primary_inverter_connection_status_t*)((*map)[index].message_raw);
            primary::INVERTER_CONNECTION_STATUS* proto_msg = pack->add_inverter_connection_status();
			proto_msg->set_status((primary::primary_inverter_connection_status_status)msg->status);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 10: {
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

        case 298: {
            primary_shutdown_status_t* msg = (primary_shutdown_status_t*)((*map)[index].message_raw);
            primary::SHUTDOWN_STATUS* proto_msg = pack->add_shutdown_status();
			proto_msg->set_input(msg->input);
			proto_msg->set_output(msg->output);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 4: {
            primary_marker_t* msg = (primary_marker_t*)((*map)[index].message_raw);
            primary::MARKER* proto_msg = pack->add_marker();

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 512: {
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

        case 544: {
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

        case 576: {
            primary_hv_cell_balancing_status_t* msg = (primary_hv_cell_balancing_status_t*)((*map)[index].message_raw);
            primary::HV_CELL_BALANCING_STATUS* proto_msg = pack->add_hv_cell_balancing_status();
			proto_msg->set_balancing_status((primary::primary_hv_cell_balancing_status_balancing_status)msg->balancing_status);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 546: {
            primary_set_cell_balancing_status_t* msg = (primary_set_cell_balancing_status_t*)((*map)[index].message_raw);
            primary::SET_CELL_BALANCING_STATUS* proto_msg = pack->add_set_cell_balancing_status();
			proto_msg->set_set_balancing_status((primary::primary_set_cell_balancing_status_set_balancing_status)msg->set_balancing_status);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 770: {
            primary_handcart_status_t* msg = (primary_handcart_status_t*)((*map)[index].message_raw);
            primary::HANDCART_STATUS* proto_msg = pack->add_handcart_status();
			proto_msg->set_connected(msg->connected);

#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 547: {
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

        case 291: {
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

        case 520: {
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
