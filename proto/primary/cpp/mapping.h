#ifndef primary_MAPPING_H
#define primary_MAPPING_H

#include <string>
#include <vector>

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
  T inline first() const;
  T inline last() const;
  T operator[](IT index) const;
  IT inline size() const;
  IT inline available() const;
  bool inline empty() const;
  bool inline full() const;
  void inline clear();

 private:
  T buffer[S];
  T *head;
  T *tail;
#ifndef CIRCULAR_BUFFER_INT_SAFE
  IT count;
#else
  volatile IT count;
#endif
};

template <typename T, size_t S, typename IT>
constexpr canlib_circular_buffer<T, S, IT>::canlib_circular_buffer()
    : head(buffer), tail(buffer), count(0) {}

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
T canlib_circular_buffer<T, S, IT>::operator[](IT index) const {
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
#endif // CANLIB_CIRCULAR_BUFFER

#ifndef CANLIB_CIRCULAR_BUFFER_SIZE
#define CANLIB_CIRCULAR_BUFFER_SIZE 500
#endif // CANLIB_CIRCULAR_BUFFER_SIZE

typedef struct {
    canlib_circular_buffer<primary_message_BMS_HV_JMP_TO_BLT, CANLIB_CIRCULAR_BUFFER_SIZE> BMS_HV_JMP_TO_BLT;
    canlib_circular_buffer<primary_message_BMS_LV_JMP_TO_BLT, CANLIB_CIRCULAR_BUFFER_SIZE> BMS_LV_JMP_TO_BLT;
    canlib_circular_buffer<primary_message_STEER_VERSION, CANLIB_CIRCULAR_BUFFER_SIZE> STEER_VERSION;
    canlib_circular_buffer<primary_message_DAS_VERSION, CANLIB_CIRCULAR_BUFFER_SIZE> DAS_VERSION;
    canlib_circular_buffer<primary_message_HV_VERSION, CANLIB_CIRCULAR_BUFFER_SIZE> HV_VERSION;
    canlib_circular_buffer<primary_message_LV_VERSION, CANLIB_CIRCULAR_BUFFER_SIZE> LV_VERSION;
    canlib_circular_buffer<primary_message_TLM_VERSION, CANLIB_CIRCULAR_BUFFER_SIZE> TLM_VERSION;
    canlib_circular_buffer<primary_message_TIMESTAMP, CANLIB_CIRCULAR_BUFFER_SIZE> TIMESTAMP;
    canlib_circular_buffer<primary_message_SET_TLM_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE> SET_TLM_STATUS;
    canlib_circular_buffer<primary_message_TLM_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE> TLM_STATUS;
    canlib_circular_buffer<primary_message_STEER_SYSTEM_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE> STEER_SYSTEM_STATUS;
    canlib_circular_buffer<primary_message_HV_VOLTAGE_conversion, CANLIB_CIRCULAR_BUFFER_SIZE> HV_VOLTAGE;
    canlib_circular_buffer<primary_message_HV_CURRENT_conversion, CANLIB_CIRCULAR_BUFFER_SIZE> HV_CURRENT;
    canlib_circular_buffer<primary_message_HV_TEMP_conversion, CANLIB_CIRCULAR_BUFFER_SIZE> HV_TEMP;
    canlib_circular_buffer<primary_message_HV_ERRORS, CANLIB_CIRCULAR_BUFFER_SIZE> HV_ERRORS;
    canlib_circular_buffer<primary_message_HV_CAN_FORWARD, CANLIB_CIRCULAR_BUFFER_SIZE> HV_CAN_FORWARD;
    canlib_circular_buffer<primary_message_HV_FANS_OVERRIDE_conversion, CANLIB_CIRCULAR_BUFFER_SIZE> HV_FANS_OVERRIDE;
    canlib_circular_buffer<primary_message_HV_CAN_FORWARD_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE> HV_CAN_FORWARD_STATUS;
    canlib_circular_buffer<primary_message_HV_FANS_OVERRIDE_STATUS_conversion, CANLIB_CIRCULAR_BUFFER_SIZE> HV_FANS_OVERRIDE_STATUS;
    canlib_circular_buffer<primary_message_HV_FEEDBACKS_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE> HV_FEEDBACKS_STATUS;
    canlib_circular_buffer<primary_message_HV_IMD_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE> HV_IMD_STATUS;
    canlib_circular_buffer<primary_message_TS_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE> TS_STATUS;
    canlib_circular_buffer<primary_message_SET_TS_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE> SET_TS_STATUS_DAS;
    canlib_circular_buffer<primary_message_SET_TS_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE> SET_TS_STATUS_HANDCART;
    canlib_circular_buffer<primary_message_STEER_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE> STEER_STATUS;
    canlib_circular_buffer<primary_message_SET_CAR_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE> SET_CAR_STATUS;
    canlib_circular_buffer<primary_message_SET_PEDALS_RANGE, CANLIB_CIRCULAR_BUFFER_SIZE> SET_PEDALS_RANGE;
    canlib_circular_buffer<primary_message_SET_STEERING_ANGLE_RANGE, CANLIB_CIRCULAR_BUFFER_SIZE> SET_STEERING_ANGLE_RANGE;
    canlib_circular_buffer<primary_message_CAR_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE> CAR_STATUS;
    canlib_circular_buffer<primary_message_DAS_ERRORS, CANLIB_CIRCULAR_BUFFER_SIZE> DAS_ERRORS;
    canlib_circular_buffer<primary_message_LV_CURRENT_conversion, CANLIB_CIRCULAR_BUFFER_SIZE> LV_CURRENT;
    canlib_circular_buffer<primary_message_LV_VOLTAGE_conversion, CANLIB_CIRCULAR_BUFFER_SIZE> LV_VOLTAGE;
    canlib_circular_buffer<primary_message_LV_TOTAL_VOLTAGE_conversion, CANLIB_CIRCULAR_BUFFER_SIZE> LV_TOTAL_VOLTAGE;
    canlib_circular_buffer<primary_message_LV_TEMPERATURE_conversion, CANLIB_CIRCULAR_BUFFER_SIZE> LV_TEMPERATURE;
    canlib_circular_buffer<primary_message_COOLING_STATUS_conversion, CANLIB_CIRCULAR_BUFFER_SIZE> COOLING_STATUS;
    canlib_circular_buffer<primary_message_SET_RADIATOR_SPEED_conversion, CANLIB_CIRCULAR_BUFFER_SIZE> SET_RADIATOR_SPEED;
    canlib_circular_buffer<primary_message_SET_PUMPS_SPEED_conversion, CANLIB_CIRCULAR_BUFFER_SIZE> SET_PUMPS_SPEED;
    canlib_circular_buffer<primary_message_SET_INVERTER_CONNECTION_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE> SET_INVERTER_CONNECTION_STATUS;
    canlib_circular_buffer<primary_message_INVERTER_CONNECTION_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE> INVERTER_CONNECTION_STATUS;
    canlib_circular_buffer<primary_message_SHUTDOWN_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE> SHUTDOWN_STATUS;
    canlib_circular_buffer<primary_message_MARKER, CANLIB_CIRCULAR_BUFFER_SIZE> MARKER;
    canlib_circular_buffer<primary_message_HV_CELLS_VOLTAGE_conversion, CANLIB_CIRCULAR_BUFFER_SIZE> HV_CELLS_VOLTAGE;
    canlib_circular_buffer<primary_message_HV_CELLS_TEMP_conversion, CANLIB_CIRCULAR_BUFFER_SIZE> HV_CELLS_TEMP;
    canlib_circular_buffer<primary_message_HV_CELL_BALANCING_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE> HV_CELL_BALANCING_STATUS;
    canlib_circular_buffer<primary_message_SET_CELL_BALANCING_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE> SET_CELL_BALANCING_STATUS;
    canlib_circular_buffer<primary_message_HANDCART_STATUS, CANLIB_CIRCULAR_BUFFER_SIZE> HANDCART_STATUS;
    canlib_circular_buffer<primary_message_SPEED_conversion, CANLIB_CIRCULAR_BUFFER_SIZE> SPEED;
    canlib_circular_buffer<primary_message_INV_L_REQUEST, CANLIB_CIRCULAR_BUFFER_SIZE> INV_L_REQUEST;
    canlib_circular_buffer<primary_message_INV_R_REQUEST, CANLIB_CIRCULAR_BUFFER_SIZE> INV_R_REQUEST;
    canlib_circular_buffer<primary_message_INV_L_RESPONSE, CANLIB_CIRCULAR_BUFFER_SIZE> INV_L_RESPONSE;
    canlib_circular_buffer<primary_message_INV_R_RESPONSE, CANLIB_CIRCULAR_BUFFER_SIZE> INV_R_RESPONSE;
    canlib_circular_buffer<primary_message_FLASH_CELLBOARD_0_TX, CANLIB_CIRCULAR_BUFFER_SIZE> FLASH_CELLBOARD_0_TX;
    canlib_circular_buffer<primary_message_FLASH_CELLBOARD_0_RX, CANLIB_CIRCULAR_BUFFER_SIZE> FLASH_CELLBOARD_0_RX;
    canlib_circular_buffer<primary_message_FLASH_CELLBOARD_1_TX, CANLIB_CIRCULAR_BUFFER_SIZE> FLASH_CELLBOARD_1_TX;
    canlib_circular_buffer<primary_message_FLASH_CELLBOARD_1_RX, CANLIB_CIRCULAR_BUFFER_SIZE> FLASH_CELLBOARD_1_RX;
    canlib_circular_buffer<primary_message_FLASH_CELLBOARD_2_TX, CANLIB_CIRCULAR_BUFFER_SIZE> FLASH_CELLBOARD_2_TX;
    canlib_circular_buffer<primary_message_FLASH_CELLBOARD_2_RX, CANLIB_CIRCULAR_BUFFER_SIZE> FLASH_CELLBOARD_2_RX;
    canlib_circular_buffer<primary_message_FLASH_CELLBOARD_3_TX, CANLIB_CIRCULAR_BUFFER_SIZE> FLASH_CELLBOARD_3_TX;
    canlib_circular_buffer<primary_message_FLASH_CELLBOARD_3_RX, CANLIB_CIRCULAR_BUFFER_SIZE> FLASH_CELLBOARD_3_RX;
    canlib_circular_buffer<primary_message_FLASH_CELLBOARD_4_TX, CANLIB_CIRCULAR_BUFFER_SIZE> FLASH_CELLBOARD_4_TX;
    canlib_circular_buffer<primary_message_FLASH_CELLBOARD_4_RX, CANLIB_CIRCULAR_BUFFER_SIZE> FLASH_CELLBOARD_4_RX;
    canlib_circular_buffer<primary_message_FLASH_CELLBOARD_5_TX, CANLIB_CIRCULAR_BUFFER_SIZE> FLASH_CELLBOARD_5_TX;
    canlib_circular_buffer<primary_message_FLASH_CELLBOARD_5_RX, CANLIB_CIRCULAR_BUFFER_SIZE> FLASH_CELLBOARD_5_RX;
    canlib_circular_buffer<primary_message_FLASH_BMS_HV_TX, CANLIB_CIRCULAR_BUFFER_SIZE> FLASH_BMS_HV_TX;
    canlib_circular_buffer<primary_message_FLASH_BMS_HV_RX, CANLIB_CIRCULAR_BUFFER_SIZE> FLASH_BMS_HV_RX;
    canlib_circular_buffer<primary_message_FLASH_BMS_LV_TX, CANLIB_CIRCULAR_BUFFER_SIZE> FLASH_BMS_LV_TX;
    canlib_circular_buffer<primary_message_FLASH_BMS_LV_RX, CANLIB_CIRCULAR_BUFFER_SIZE> FLASH_BMS_LV_RX;
    canlib_circular_buffer<primary_message_BRUSA_NLG5_CTL, CANLIB_CIRCULAR_BUFFER_SIZE> BRUSA_NLG5_CTL;
    canlib_circular_buffer<primary_message_BRUSA_ST, CANLIB_CIRCULAR_BUFFER_SIZE> BRUSA_ST;
    canlib_circular_buffer<primary_message_BRUSA_ACT_I, CANLIB_CIRCULAR_BUFFER_SIZE> BRUSA_ACT_I;
    canlib_circular_buffer<primary_message_BRUSA_ACT_II, CANLIB_CIRCULAR_BUFFER_SIZE> BRUSA_ACT_II;
    canlib_circular_buffer<primary_message_BRUSA_TEMP, CANLIB_CIRCULAR_BUFFER_SIZE> BRUSA_TEMP;
    canlib_circular_buffer<primary_message_BRUSA_ERR, CANLIB_CIRCULAR_BUFFER_SIZE> BRUSA_ERR;
    canlib_circular_buffer<primary_message_BMS_HV_CHIMERA, CANLIB_CIRCULAR_BUFFER_SIZE> BMS_HV_CHIMERA;
    canlib_circular_buffer<primary_message_ECU_CHIMERA, CANLIB_CIRCULAR_BUFFER_SIZE> ECU_CHIMERA;
} primary_proto_pack;

void primary_proto_serialize_from_id(canlib_message_id id, primary::Pack* pack, primary_devices* map);
void primary_proto_deserialize(primary::Pack* pack, primary_proto_pack* map);

#ifdef primary_MAPPING_IMPLEMENTATION

void primary_proto_serialize_from_id(canlib_message_id id, primary::Pack* pack, primary_devices* map) {
    int index = primary_index_from_id(id);

    if (index == -1) return;

    switch(id) {
        case 0: {
            primary_message_BMS_HV_JMP_TO_BLT* msg = (primary_message_BMS_HV_JMP_TO_BLT*) (*map)[index].message_raw;
            primary::BMS_HV_JMP_TO_BLT* proto_msg = pack->add_bms_hv_jmp_to_blt();
            break;
        }

        case 32: {
            primary_message_BMS_LV_JMP_TO_BLT* msg = (primary_message_BMS_LV_JMP_TO_BLT*) (*map)[index].message_raw;
            primary::BMS_LV_JMP_TO_BLT* proto_msg = pack->add_bms_lv_jmp_to_blt();
            break;
        }

        case 1025: {
            primary_message_STEER_VERSION* msg = (primary_message_STEER_VERSION*) (*map)[index].message_raw;
            primary::STEER_VERSION* proto_msg = pack->add_steer_version();
            proto_msg->set_component_version(msg->component_version);
            proto_msg->set_cancicd_version(msg->cancicd_version);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1057: {
            primary_message_DAS_VERSION* msg = (primary_message_DAS_VERSION*) (*map)[index].message_raw;
            primary::DAS_VERSION* proto_msg = pack->add_das_version();
            proto_msg->set_component_version(msg->component_version);
            proto_msg->set_cancicd_version(msg->cancicd_version);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1089: {
            primary_message_HV_VERSION* msg = (primary_message_HV_VERSION*) (*map)[index].message_raw;
            primary::HV_VERSION* proto_msg = pack->add_hv_version();
            proto_msg->set_component_version(msg->component_version);
            proto_msg->set_cancicd_version(msg->cancicd_version);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1121: {
            primary_message_LV_VERSION* msg = (primary_message_LV_VERSION*) (*map)[index].message_raw;
            primary::LV_VERSION* proto_msg = pack->add_lv_version();
            proto_msg->set_component_version(msg->component_version);
            proto_msg->set_cancicd_version(msg->cancicd_version);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1153: {
            primary_message_TLM_VERSION* msg = (primary_message_TLM_VERSION*) (*map)[index].message_raw;
            primary::TLM_VERSION* proto_msg = pack->add_tlm_version();
            proto_msg->set_component_version(msg->component_version);
            proto_msg->set_cancicd_version(msg->cancicd_version);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 257: {
            primary_message_TIMESTAMP* msg = (primary_message_TIMESTAMP*) (*map)[index].message_raw;
            primary::TIMESTAMP* proto_msg = pack->add_timestamp();
            proto_msg->set_timestamp(msg->timestamp);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 258: {
            primary_message_SET_TLM_STATUS* msg = (primary_message_SET_TLM_STATUS*) (*map)[index].message_raw;
            primary::SET_TLM_STATUS* proto_msg = pack->add_set_tlm_status();
            proto_msg->set_tlm_status((primary::Toggle)msg->tlm_status);
            proto_msg->set_race_type((primary::RaceType)msg->race_type);
            proto_msg->set_driver(msg->driver);
            proto_msg->set_circuit(msg->circuit);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 259: {
            primary_message_TLM_STATUS* msg = (primary_message_TLM_STATUS*) (*map)[index].message_raw;
            primary::TLM_STATUS* proto_msg = pack->add_tlm_status();
            proto_msg->set_tlm_status((primary::Toggle)msg->tlm_status);
            proto_msg->set_race_type((primary::RaceType)msg->race_type);
            proto_msg->set_driver(msg->driver);
            proto_msg->set_circuit(msg->circuit);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1794: {
            primary_message_STEER_SYSTEM_STATUS* msg = (primary_message_STEER_SYSTEM_STATUS*) (*map)[index].message_raw;
            primary::STEER_SYSTEM_STATUS* proto_msg = pack->add_steer_system_status();
            proto_msg->set_soc_temp(msg->soc_temp);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 772: {
            primary_message_HV_VOLTAGE_conversion* msg = (primary_message_HV_VOLTAGE_conversion*) (*map)[index].message_conversion;
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

        case 804: {
            primary_message_HV_CURRENT_conversion* msg = (primary_message_HV_CURRENT_conversion*) (*map)[index].message_conversion;
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

        case 836: {
            primary_message_HV_TEMP_conversion* msg = (primary_message_HV_TEMP_conversion*) (*map)[index].message_conversion;
            primary::HV_TEMP* proto_msg = pack->add_hv_temp();
            proto_msg->set_average_temp(msg->average_temp);
            proto_msg->set_max_temp(msg->max_temp);
            proto_msg->set_min_temp(msg->min_temp);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 4: {
            primary_message_HV_ERRORS* msg = (primary_message_HV_ERRORS*) (*map)[index].message_raw;
            primary::HV_ERRORS* proto_msg = pack->add_hv_errors();
            proto_msg->set_warnings(msg->warnings);
            proto_msg->set_errors(msg->errors);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 5: {
            primary_message_HV_CAN_FORWARD* msg = (primary_message_HV_CAN_FORWARD*) (*map)[index].message_raw;
            primary::HV_CAN_FORWARD* proto_msg = pack->add_hv_can_forward();
            proto_msg->set_can_forward_set((primary::Toggle)msg->can_forward_set);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 37: {
            primary_message_HV_FANS_OVERRIDE_conversion* msg = (primary_message_HV_FANS_OVERRIDE_conversion*) (*map)[index].message_conversion;
            primary::HV_FANS_OVERRIDE* proto_msg = pack->add_hv_fans_override();
            proto_msg->set_fans_override((primary::Toggle)msg->fans_override);
            proto_msg->set_fans_speed(msg->fans_speed);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 6: {
            primary_message_HV_CAN_FORWARD_STATUS* msg = (primary_message_HV_CAN_FORWARD_STATUS*) (*map)[index].message_raw;
            primary::HV_CAN_FORWARD_STATUS* proto_msg = pack->add_hv_can_forward_status();
            proto_msg->set_can_forward_status((primary::Toggle)msg->can_forward_status);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 774: {
            primary_message_HV_FANS_OVERRIDE_STATUS_conversion* msg = (primary_message_HV_FANS_OVERRIDE_STATUS_conversion*) (*map)[index].message_conversion;
            primary::HV_FANS_OVERRIDE_STATUS* proto_msg = pack->add_hv_fans_override_status();
            proto_msg->set_fans_override((primary::Toggle)msg->fans_override);
            proto_msg->set_fans_speed(msg->fans_speed);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 775: {
            primary_message_HV_FEEDBACKS_STATUS* msg = (primary_message_HV_FEEDBACKS_STATUS*) (*map)[index].message_raw;
            primary::HV_FEEDBACKS_STATUS* proto_msg = pack->add_hv_feedbacks_status();
            proto_msg->set_feedbacks_status(msg->feedbacks_status);
            proto_msg->set_is_circuitry_error(msg->is_circuitry_error);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 807: {
            primary_message_HV_IMD_STATUS* msg = (primary_message_HV_IMD_STATUS*) (*map)[index].message_raw;
            primary::HV_IMD_STATUS* proto_msg = pack->add_hv_imd_status();
            proto_msg->set_imd_fault(msg->imd_fault);
            proto_msg->set_imd_status((primary::ImdStatus)msg->imd_status);
            proto_msg->set_imd_info(msg->imd_info);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 36: {
            primary_message_TS_STATUS* msg = (primary_message_TS_STATUS*) (*map)[index].message_raw;
            primary::TS_STATUS* proto_msg = pack->add_ts_status();
            proto_msg->set_ts_status((primary::TsStatus)msg->ts_status);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 69: {
            primary_message_SET_TS_STATUS* msg = (primary_message_SET_TS_STATUS*) (*map)[index].message_raw;
            primary::SET_TS_STATUS_DAS* proto_msg = pack->add_set_ts_status_das();
            proto_msg->set_ts_status_set((primary::Toggle)msg->ts_status_set);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 101: {
            primary_message_SET_TS_STATUS* msg = (primary_message_SET_TS_STATUS*) (*map)[index].message_raw;
            primary::SET_TS_STATUS_HANDCART* proto_msg = pack->add_set_ts_status_handcart();
            proto_msg->set_ts_status_set((primary::Toggle)msg->ts_status_set);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 264: {
            primary_message_STEER_STATUS* msg = (primary_message_STEER_STATUS*) (*map)[index].message_raw;
            primary::STEER_STATUS* proto_msg = pack->add_steer_status();
            proto_msg->set_traction_control((primary::TractionControl)msg->traction_control);
            proto_msg->set_map((primary::Map)msg->map);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 776: {
            primary_message_SET_CAR_STATUS* msg = (primary_message_SET_CAR_STATUS*) (*map)[index].message_raw;
            primary::SET_CAR_STATUS* proto_msg = pack->add_set_car_status();
            proto_msg->set_car_status_set((primary::SetCarStatus)msg->car_status_set);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1032: {
            primary_message_SET_PEDALS_RANGE* msg = (primary_message_SET_PEDALS_RANGE*) (*map)[index].message_raw;
            primary::SET_PEDALS_RANGE* proto_msg = pack->add_set_pedals_range();
            proto_msg->set_bound((primary::Bound)msg->bound);
            proto_msg->set_pedal((primary::Pedal)msg->pedal);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1064: {
            primary_message_SET_STEERING_ANGLE_RANGE* msg = (primary_message_SET_STEERING_ANGLE_RANGE*) (*map)[index].message_raw;
            primary::SET_STEERING_ANGLE_RANGE* proto_msg = pack->add_set_steering_angle_range();
            proto_msg->set_bound((primary::Bound)msg->bound);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 515: {
            primary_message_CAR_STATUS* msg = (primary_message_CAR_STATUS*) (*map)[index].message_raw;
            primary::CAR_STATUS* proto_msg = pack->add_car_status();
            proto_msg->set_inverter_l((primary::InverterStatus)msg->inverter_l);
            proto_msg->set_inverter_r((primary::InverterStatus)msg->inverter_r);
            proto_msg->set_car_status((primary::CarStatus)msg->car_status);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 3: {
            primary_message_DAS_ERRORS* msg = (primary_message_DAS_ERRORS*) (*map)[index].message_raw;
            primary::DAS_ERRORS* proto_msg = pack->add_das_errors();
            proto_msg->set_das_error(msg->das_error);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 839: {
            primary_message_LV_CURRENT_conversion* msg = (primary_message_LV_CURRENT_conversion*) (*map)[index].message_conversion;
            primary::LV_CURRENT* proto_msg = pack->add_lv_current();
            proto_msg->set_current(msg->current);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 871: {
            primary_message_LV_VOLTAGE_conversion* msg = (primary_message_LV_VOLTAGE_conversion*) (*map)[index].message_conversion;
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

        case 903: {
            primary_message_LV_TOTAL_VOLTAGE_conversion* msg = (primary_message_LV_TOTAL_VOLTAGE_conversion*) (*map)[index].message_conversion;
            primary::LV_TOTAL_VOLTAGE* proto_msg = pack->add_lv_total_voltage();
            proto_msg->set_total_voltage(msg->total_voltage);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 935: {
            primary_message_LV_TEMPERATURE_conversion* msg = (primary_message_LV_TEMPERATURE_conversion*) (*map)[index].message_conversion;
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

        case 967: {
            primary_message_COOLING_STATUS_conversion* msg = (primary_message_COOLING_STATUS_conversion*) (*map)[index].message_conversion;
            primary::COOLING_STATUS* proto_msg = pack->add_cooling_status();
            proto_msg->set_radiators_speed(msg->radiators_speed);
            proto_msg->set_pumps_speed(msg->pumps_speed);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 777: {
            primary_message_SET_RADIATOR_SPEED_conversion* msg = (primary_message_SET_RADIATOR_SPEED_conversion*) (*map)[index].message_conversion;
            primary::SET_RADIATOR_SPEED* proto_msg = pack->add_set_radiator_speed();
            proto_msg->set_radiators_speed(msg->radiators_speed);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 809: {
            primary_message_SET_PUMPS_SPEED_conversion* msg = (primary_message_SET_PUMPS_SPEED_conversion*) (*map)[index].message_conversion;
            primary::SET_PUMPS_SPEED* proto_msg = pack->add_set_pumps_speed();
            proto_msg->set_pumps_speed(msg->pumps_speed);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 265: {
            primary_message_SET_INVERTER_CONNECTION_STATUS* msg = (primary_message_SET_INVERTER_CONNECTION_STATUS*) (*map)[index].message_raw;
            primary::SET_INVERTER_CONNECTION_STATUS* proto_msg = pack->add_set_inverter_connection_status();
            proto_msg->set_status((primary::Toggle)msg->status);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 263: {
            primary_message_INVERTER_CONNECTION_STATUS* msg = (primary_message_INVERTER_CONNECTION_STATUS*) (*map)[index].message_raw;
            primary::INVERTER_CONNECTION_STATUS* proto_msg = pack->add_inverter_connection_status();
            proto_msg->set_status((primary::Toggle)msg->status);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 295: {
            primary_message_SHUTDOWN_STATUS* msg = (primary_message_SHUTDOWN_STATUS*) (*map)[index].message_raw;
            primary::SHUTDOWN_STATUS* proto_msg = pack->add_shutdown_status();
            proto_msg->set_input(msg->input);
            proto_msg->set_output(msg->output);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 2: {
            primary_message_MARKER* msg = (primary_message_MARKER*) (*map)[index].message_raw;
            primary::MARKER* proto_msg = pack->add_marker();
            break;
        }

        case 518: {
            primary_message_HV_CELLS_VOLTAGE_conversion* msg = (primary_message_HV_CELLS_VOLTAGE_conversion*) (*map)[index].message_conversion;
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

        case 550: {
            primary_message_HV_CELLS_TEMP_conversion* msg = (primary_message_HV_CELLS_TEMP_conversion*) (*map)[index].message_conversion;
            primary::HV_CELLS_TEMP* proto_msg = pack->add_hv_cells_temp();
            proto_msg->set_start_index(msg->start_index);
            proto_msg->set_temp_0(msg->temp_0);
            proto_msg->set_temp_1(msg->temp_1);
            proto_msg->set_temp_2(msg->temp_2);
            proto_msg->set_temp_3(msg->temp_3);
            proto_msg->set_temp_4(msg->temp_4);
            proto_msg->set_temp_5(msg->temp_5);
            proto_msg->set_temp_6(msg->temp_6);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 582: {
            primary_message_HV_CELL_BALANCING_STATUS* msg = (primary_message_HV_CELL_BALANCING_STATUS*) (*map)[index].message_raw;
            primary::HV_CELL_BALANCING_STATUS* proto_msg = pack->add_hv_cell_balancing_status();
            proto_msg->set_balancing_status((primary::Toggle)msg->balancing_status);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 517: {
            primary_message_SET_CELL_BALANCING_STATUS* msg = (primary_message_SET_CELL_BALANCING_STATUS*) (*map)[index].message_raw;
            primary::SET_CELL_BALANCING_STATUS* proto_msg = pack->add_set_cell_balancing_status();
            proto_msg->set_set_balancing_status((primary::Toggle)msg->set_balancing_status);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 773: {
            primary_message_HANDCART_STATUS* msg = (primary_message_HANDCART_STATUS*) (*map)[index].message_raw;
            primary::HANDCART_STATUS* proto_msg = pack->add_handcart_status();
            proto_msg->set_connected(msg->connected);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 547: {
            primary_message_SPEED_conversion* msg = (primary_message_SPEED_conversion*) (*map)[index].message_conversion;
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
            primary_message_INV_L_REQUEST* msg = (primary_message_INV_L_REQUEST*) (*map)[index].message_raw;
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
            primary_message_INV_R_REQUEST* msg = (primary_message_INV_R_REQUEST*) (*map)[index].message_raw;
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
            primary_message_INV_L_RESPONSE* msg = (primary_message_INV_L_RESPONSE*) (*map)[index].message_raw;
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
            primary_message_INV_R_RESPONSE* msg = (primary_message_INV_R_RESPONSE*) (*map)[index].message_raw;
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
            primary_message_FLASH_CELLBOARD_0_TX* msg = (primary_message_FLASH_CELLBOARD_0_TX*) (*map)[index].message_raw;
            primary::FLASH_CELLBOARD_0_TX* proto_msg = pack->add_flash_cellboard_0_tx();
            break;
        }

        case 17: {
            primary_message_FLASH_CELLBOARD_0_RX* msg = (primary_message_FLASH_CELLBOARD_0_RX*) (*map)[index].message_raw;
            primary::FLASH_CELLBOARD_0_RX* proto_msg = pack->add_flash_cellboard_0_rx();
            break;
        }

        case 18: {
            primary_message_FLASH_CELLBOARD_1_TX* msg = (primary_message_FLASH_CELLBOARD_1_TX*) (*map)[index].message_raw;
            primary::FLASH_CELLBOARD_1_TX* proto_msg = pack->add_flash_cellboard_1_tx();
            break;
        }

        case 19: {
            primary_message_FLASH_CELLBOARD_1_RX* msg = (primary_message_FLASH_CELLBOARD_1_RX*) (*map)[index].message_raw;
            primary::FLASH_CELLBOARD_1_RX* proto_msg = pack->add_flash_cellboard_1_rx();
            break;
        }

        case 20: {
            primary_message_FLASH_CELLBOARD_2_TX* msg = (primary_message_FLASH_CELLBOARD_2_TX*) (*map)[index].message_raw;
            primary::FLASH_CELLBOARD_2_TX* proto_msg = pack->add_flash_cellboard_2_tx();
            break;
        }

        case 21: {
            primary_message_FLASH_CELLBOARD_2_RX* msg = (primary_message_FLASH_CELLBOARD_2_RX*) (*map)[index].message_raw;
            primary::FLASH_CELLBOARD_2_RX* proto_msg = pack->add_flash_cellboard_2_rx();
            break;
        }

        case 22: {
            primary_message_FLASH_CELLBOARD_3_TX* msg = (primary_message_FLASH_CELLBOARD_3_TX*) (*map)[index].message_raw;
            primary::FLASH_CELLBOARD_3_TX* proto_msg = pack->add_flash_cellboard_3_tx();
            break;
        }

        case 23: {
            primary_message_FLASH_CELLBOARD_3_RX* msg = (primary_message_FLASH_CELLBOARD_3_RX*) (*map)[index].message_raw;
            primary::FLASH_CELLBOARD_3_RX* proto_msg = pack->add_flash_cellboard_3_rx();
            break;
        }

        case 24: {
            primary_message_FLASH_CELLBOARD_4_TX* msg = (primary_message_FLASH_CELLBOARD_4_TX*) (*map)[index].message_raw;
            primary::FLASH_CELLBOARD_4_TX* proto_msg = pack->add_flash_cellboard_4_tx();
            break;
        }

        case 25: {
            primary_message_FLASH_CELLBOARD_4_RX* msg = (primary_message_FLASH_CELLBOARD_4_RX*) (*map)[index].message_raw;
            primary::FLASH_CELLBOARD_4_RX* proto_msg = pack->add_flash_cellboard_4_rx();
            break;
        }

        case 26: {
            primary_message_FLASH_CELLBOARD_5_TX* msg = (primary_message_FLASH_CELLBOARD_5_TX*) (*map)[index].message_raw;
            primary::FLASH_CELLBOARD_5_TX* proto_msg = pack->add_flash_cellboard_5_tx();
            break;
        }

        case 27: {
            primary_message_FLASH_CELLBOARD_5_RX* msg = (primary_message_FLASH_CELLBOARD_5_RX*) (*map)[index].message_raw;
            primary::FLASH_CELLBOARD_5_RX* proto_msg = pack->add_flash_cellboard_5_rx();
            break;
        }

        case 2017: {
            primary_message_FLASH_BMS_HV_TX* msg = (primary_message_FLASH_BMS_HV_TX*) (*map)[index].message_raw;
            primary::FLASH_BMS_HV_TX* proto_msg = pack->add_flash_bms_hv_tx();
            break;
        }

        case 1639: {
            primary_message_FLASH_BMS_HV_RX* msg = (primary_message_FLASH_BMS_HV_RX*) (*map)[index].message_raw;
            primary::FLASH_BMS_HV_RX* proto_msg = pack->add_flash_bms_hv_rx();
            break;
        }

        case 2033: {
            primary_message_FLASH_BMS_LV_TX* msg = (primary_message_FLASH_BMS_LV_TX*) (*map)[index].message_raw;
            primary::FLASH_BMS_LV_TX* proto_msg = pack->add_flash_bms_lv_tx();
            break;
        }

        case 1655: {
            primary_message_FLASH_BMS_LV_RX* msg = (primary_message_FLASH_BMS_LV_RX*) (*map)[index].message_raw;
            primary::FLASH_BMS_LV_RX* proto_msg = pack->add_flash_bms_lv_rx();
            break;
        }

        case 618: {
            primary_message_BRUSA_NLG5_CTL* msg = (primary_message_BRUSA_NLG5_CTL*) (*map)[index].message_raw;
            primary::BRUSA_NLG5_CTL* proto_msg = pack->add_brusa_nlg5_ctl();
            break;
        }

        case 610: {
            primary_message_BRUSA_ST* msg = (primary_message_BRUSA_ST*) (*map)[index].message_raw;
            primary::BRUSA_ST* proto_msg = pack->add_brusa_st();
            break;
        }

        case 611: {
            primary_message_BRUSA_ACT_I* msg = (primary_message_BRUSA_ACT_I*) (*map)[index].message_raw;
            primary::BRUSA_ACT_I* proto_msg = pack->add_brusa_act_i();
            break;
        }

        case 612: {
            primary_message_BRUSA_ACT_II* msg = (primary_message_BRUSA_ACT_II*) (*map)[index].message_raw;
            primary::BRUSA_ACT_II* proto_msg = pack->add_brusa_act_ii();
            break;
        }

        case 613: {
            primary_message_BRUSA_TEMP* msg = (primary_message_BRUSA_TEMP*) (*map)[index].message_raw;
            primary::BRUSA_TEMP* proto_msg = pack->add_brusa_temp();
            break;
        }

        case 614: {
            primary_message_BRUSA_ERR* msg = (primary_message_BRUSA_ERR*) (*map)[index].message_raw;
            primary::BRUSA_ERR* proto_msg = pack->add_brusa_err();
            break;
        }

        case 170: {
            primary_message_BMS_HV_CHIMERA* msg = (primary_message_BMS_HV_CHIMERA*) (*map)[index].message_raw;
            primary::BMS_HV_CHIMERA* proto_msg = pack->add_bms_hv_chimera();
            break;
        }

        case 85: {
            primary_message_ECU_CHIMERA* msg = (primary_message_ECU_CHIMERA*) (*map)[index].message_raw;
            primary::ECU_CHIMERA* proto_msg = pack->add_ecu_chimera();
            break;
        }

    }
}

void primary_proto_deserialize(primary::Pack* pack, primary_proto_pack* map) {
    for(int i = 0; i < pack->bms_hv_jmp_to_blt_size(); i++){
        static primary_message_BMS_HV_JMP_TO_BLT instance;
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->bms_hv_jmp_to_blt(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->BMS_HV_JMP_TO_BLT.push(instance);
    }
    for(int i = 0; i < pack->bms_lv_jmp_to_blt_size(); i++){
        static primary_message_BMS_LV_JMP_TO_BLT instance;
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->bms_lv_jmp_to_blt(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->BMS_LV_JMP_TO_BLT.push(instance);
    }
    for(int i = 0; i < pack->steer_version_size(); i++){
        static primary_message_STEER_VERSION instance;
        instance.component_version =pack->steer_version(i).component_version();
        instance.cancicd_version =pack->steer_version(i).cancicd_version();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->steer_version(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->STEER_VERSION.push(instance);
    }
    for(int i = 0; i < pack->das_version_size(); i++){
        static primary_message_DAS_VERSION instance;
        instance.component_version =pack->das_version(i).component_version();
        instance.cancicd_version =pack->das_version(i).cancicd_version();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->das_version(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->DAS_VERSION.push(instance);
    }
    for(int i = 0; i < pack->hv_version_size(); i++){
        static primary_message_HV_VERSION instance;
        instance.component_version =pack->hv_version(i).component_version();
        instance.cancicd_version =pack->hv_version(i).cancicd_version();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->hv_version(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->HV_VERSION.push(instance);
    }
    for(int i = 0; i < pack->lv_version_size(); i++){
        static primary_message_LV_VERSION instance;
        instance.component_version =pack->lv_version(i).component_version();
        instance.cancicd_version =pack->lv_version(i).cancicd_version();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->lv_version(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->LV_VERSION.push(instance);
    }
    for(int i = 0; i < pack->tlm_version_size(); i++){
        static primary_message_TLM_VERSION instance;
        instance.component_version =pack->tlm_version(i).component_version();
        instance.cancicd_version =pack->tlm_version(i).cancicd_version();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->tlm_version(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->TLM_VERSION.push(instance);
    }
    for(int i = 0; i < pack->timestamp_size(); i++){
        static primary_message_TIMESTAMP instance;
        instance.timestamp =pack->timestamp(i).timestamp();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->timestamp(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->TIMESTAMP.push(instance);
    }
    for(int i = 0; i < pack->set_tlm_status_size(); i++){
        static primary_message_SET_TLM_STATUS instance;
        instance.tlm_status =(primary_Toggle)pack->set_tlm_status(i).tlm_status();
        instance.race_type =(primary_RaceType)pack->set_tlm_status(i).race_type();
        instance.driver =pack->set_tlm_status(i).driver();
        instance.circuit =pack->set_tlm_status(i).circuit();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->set_tlm_status(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->SET_TLM_STATUS.push(instance);
    }
    for(int i = 0; i < pack->tlm_status_size(); i++){
        static primary_message_TLM_STATUS instance;
        instance.tlm_status =(primary_Toggle)pack->tlm_status(i).tlm_status();
        instance.race_type =(primary_RaceType)pack->tlm_status(i).race_type();
        instance.driver =pack->tlm_status(i).driver();
        instance.circuit =pack->tlm_status(i).circuit();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->tlm_status(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->TLM_STATUS.push(instance);
    }
    for(int i = 0; i < pack->steer_system_status_size(); i++){
        static primary_message_STEER_SYSTEM_STATUS instance;
        instance.soc_temp =pack->steer_system_status(i).soc_temp();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->steer_system_status(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->STEER_SYSTEM_STATUS.push(instance);
    }
    for(int i = 0; i < pack->hv_voltage_size(); i++){
        static primary_message_HV_VOLTAGE_conversion instance;
        instance.pack_voltage =pack->hv_voltage(i).pack_voltage();
        instance.bus_voltage =pack->hv_voltage(i).bus_voltage();
        instance.max_cell_voltage =pack->hv_voltage(i).max_cell_voltage();
        instance.min_cell_voltage =pack->hv_voltage(i).min_cell_voltage();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->hv_voltage(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->HV_VOLTAGE.push(instance);
    }
    for(int i = 0; i < pack->hv_current_size(); i++){
        static primary_message_HV_CURRENT_conversion instance;
        instance.current =pack->hv_current(i).current();
        instance.power =pack->hv_current(i).power();
        instance.energy =pack->hv_current(i).energy();
        instance.soc =pack->hv_current(i).soc();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->hv_current(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->HV_CURRENT.push(instance);
    }
    for(int i = 0; i < pack->hv_temp_size(); i++){
        static primary_message_HV_TEMP_conversion instance;
        instance.average_temp =pack->hv_temp(i).average_temp();
        instance.max_temp =pack->hv_temp(i).max_temp();
        instance.min_temp =pack->hv_temp(i).min_temp();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->hv_temp(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->HV_TEMP.push(instance);
    }
    for(int i = 0; i < pack->hv_errors_size(); i++){
        static primary_message_HV_ERRORS instance;
        instance.warnings =pack->hv_errors(i).warnings();
        instance.errors =pack->hv_errors(i).errors();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->hv_errors(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->HV_ERRORS.push(instance);
    }
    for(int i = 0; i < pack->hv_can_forward_size(); i++){
        static primary_message_HV_CAN_FORWARD instance;
        instance.can_forward_set =(primary_Toggle)pack->hv_can_forward(i).can_forward_set();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->hv_can_forward(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->HV_CAN_FORWARD.push(instance);
    }
    for(int i = 0; i < pack->hv_fans_override_size(); i++){
        static primary_message_HV_FANS_OVERRIDE_conversion instance;
        instance.fans_override =(primary_Toggle)pack->hv_fans_override(i).fans_override();
        instance.fans_speed =pack->hv_fans_override(i).fans_speed();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->hv_fans_override(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->HV_FANS_OVERRIDE.push(instance);
    }
    for(int i = 0; i < pack->hv_can_forward_status_size(); i++){
        static primary_message_HV_CAN_FORWARD_STATUS instance;
        instance.can_forward_status =(primary_Toggle)pack->hv_can_forward_status(i).can_forward_status();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->hv_can_forward_status(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->HV_CAN_FORWARD_STATUS.push(instance);
    }
    for(int i = 0; i < pack->hv_fans_override_status_size(); i++){
        static primary_message_HV_FANS_OVERRIDE_STATUS_conversion instance;
        instance.fans_override =(primary_Toggle)pack->hv_fans_override_status(i).fans_override();
        instance.fans_speed =pack->hv_fans_override_status(i).fans_speed();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->hv_fans_override_status(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->HV_FANS_OVERRIDE_STATUS.push(instance);
    }
    for(int i = 0; i < pack->hv_feedbacks_status_size(); i++){
        static primary_message_HV_FEEDBACKS_STATUS instance;
        instance.feedbacks_status =pack->hv_feedbacks_status(i).feedbacks_status();
        instance.is_circuitry_error =pack->hv_feedbacks_status(i).is_circuitry_error();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->hv_feedbacks_status(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->HV_FEEDBACKS_STATUS.push(instance);
    }
    for(int i = 0; i < pack->hv_imd_status_size(); i++){
        static primary_message_HV_IMD_STATUS instance;
        instance.imd_fault =pack->hv_imd_status(i).imd_fault();
        instance.imd_status =(primary_ImdStatus)pack->hv_imd_status(i).imd_status();
        instance.imd_info =pack->hv_imd_status(i).imd_info();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->hv_imd_status(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->HV_IMD_STATUS.push(instance);
    }
    for(int i = 0; i < pack->ts_status_size(); i++){
        static primary_message_TS_STATUS instance;
        instance.ts_status =(primary_TsStatus)pack->ts_status(i).ts_status();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->ts_status(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->TS_STATUS.push(instance);
    }
    for(int i = 0; i < pack->set_ts_status_das_size(); i++){
        static primary_message_SET_TS_STATUS instance;
        instance.ts_status_set =(primary_Toggle)pack->set_ts_status_das(i).ts_status_set();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->set_ts_status_das(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->SET_TS_STATUS_DAS.push(instance);
    }
    for(int i = 0; i < pack->set_ts_status_handcart_size(); i++){
        static primary_message_SET_TS_STATUS instance;
        instance.ts_status_set =(primary_Toggle)pack->set_ts_status_handcart(i).ts_status_set();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->set_ts_status_handcart(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->SET_TS_STATUS_HANDCART.push(instance);
    }
    for(int i = 0; i < pack->steer_status_size(); i++){
        static primary_message_STEER_STATUS instance;
        instance.traction_control =(primary_TractionControl)pack->steer_status(i).traction_control();
        instance.map =(primary_Map)pack->steer_status(i).map();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->steer_status(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->STEER_STATUS.push(instance);
    }
    for(int i = 0; i < pack->set_car_status_size(); i++){
        static primary_message_SET_CAR_STATUS instance;
        instance.car_status_set =(primary_SetCarStatus)pack->set_car_status(i).car_status_set();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->set_car_status(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->SET_CAR_STATUS.push(instance);
    }
    for(int i = 0; i < pack->set_pedals_range_size(); i++){
        static primary_message_SET_PEDALS_RANGE instance;
        instance.bound =(primary_Bound)pack->set_pedals_range(i).bound();
        instance.pedal =(primary_Pedal)pack->set_pedals_range(i).pedal();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->set_pedals_range(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->SET_PEDALS_RANGE.push(instance);
    }
    for(int i = 0; i < pack->set_steering_angle_range_size(); i++){
        static primary_message_SET_STEERING_ANGLE_RANGE instance;
        instance.bound =(primary_Bound)pack->set_steering_angle_range(i).bound();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->set_steering_angle_range(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->SET_STEERING_ANGLE_RANGE.push(instance);
    }
    for(int i = 0; i < pack->car_status_size(); i++){
        static primary_message_CAR_STATUS instance;
        instance.inverter_l =(primary_InverterStatus)pack->car_status(i).inverter_l();
        instance.inverter_r =(primary_InverterStatus)pack->car_status(i).inverter_r();
        instance.car_status =(primary_CarStatus)pack->car_status(i).car_status();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->car_status(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->CAR_STATUS.push(instance);
    }
    for(int i = 0; i < pack->das_errors_size(); i++){
        static primary_message_DAS_ERRORS instance;
        instance.das_error =pack->das_errors(i).das_error();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->das_errors(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->DAS_ERRORS.push(instance);
    }
    for(int i = 0; i < pack->lv_current_size(); i++){
        static primary_message_LV_CURRENT_conversion instance;
        instance.current =pack->lv_current(i).current();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->lv_current(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->LV_CURRENT.push(instance);
    }
    for(int i = 0; i < pack->lv_voltage_size(); i++){
        static primary_message_LV_VOLTAGE_conversion instance;
        instance.voltage_1 =pack->lv_voltage(i).voltage_1();
        instance.voltage_2 =pack->lv_voltage(i).voltage_2();
        instance.voltage_3 =pack->lv_voltage(i).voltage_3();
        instance.voltage_4 =pack->lv_voltage(i).voltage_4();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->lv_voltage(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->LV_VOLTAGE.push(instance);
    }
    for(int i = 0; i < pack->lv_total_voltage_size(); i++){
        static primary_message_LV_TOTAL_VOLTAGE_conversion instance;
        instance.total_voltage =pack->lv_total_voltage(i).total_voltage();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->lv_total_voltage(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->LV_TOTAL_VOLTAGE.push(instance);
    }
    for(int i = 0; i < pack->lv_temperature_size(); i++){
        static primary_message_LV_TEMPERATURE_conversion instance;
        instance.bp_temperature_1 =pack->lv_temperature(i).bp_temperature_1();
        instance.bp_temperature_2 =pack->lv_temperature(i).bp_temperature_2();
        instance.dcdc12_temperature =pack->lv_temperature(i).dcdc12_temperature();
        instance.dcdc24_temperature =pack->lv_temperature(i).dcdc24_temperature();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->lv_temperature(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->LV_TEMPERATURE.push(instance);
    }
    for(int i = 0; i < pack->cooling_status_size(); i++){
        static primary_message_COOLING_STATUS_conversion instance;
        instance.radiators_speed =pack->cooling_status(i).radiators_speed();
        instance.pumps_speed =pack->cooling_status(i).pumps_speed();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->cooling_status(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->COOLING_STATUS.push(instance);
    }
    for(int i = 0; i < pack->set_radiator_speed_size(); i++){
        static primary_message_SET_RADIATOR_SPEED_conversion instance;
        instance.radiators_speed =pack->set_radiator_speed(i).radiators_speed();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->set_radiator_speed(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->SET_RADIATOR_SPEED.push(instance);
    }
    for(int i = 0; i < pack->set_pumps_speed_size(); i++){
        static primary_message_SET_PUMPS_SPEED_conversion instance;
        instance.pumps_speed =pack->set_pumps_speed(i).pumps_speed();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->set_pumps_speed(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->SET_PUMPS_SPEED.push(instance);
    }
    for(int i = 0; i < pack->set_inverter_connection_status_size(); i++){
        static primary_message_SET_INVERTER_CONNECTION_STATUS instance;
        instance.status =(primary_Toggle)pack->set_inverter_connection_status(i).status();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->set_inverter_connection_status(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->SET_INVERTER_CONNECTION_STATUS.push(instance);
    }
    for(int i = 0; i < pack->inverter_connection_status_size(); i++){
        static primary_message_INVERTER_CONNECTION_STATUS instance;
        instance.status =(primary_Toggle)pack->inverter_connection_status(i).status();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->inverter_connection_status(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->INVERTER_CONNECTION_STATUS.push(instance);
    }
    for(int i = 0; i < pack->shutdown_status_size(); i++){
        static primary_message_SHUTDOWN_STATUS instance;
        instance.input =pack->shutdown_status(i).input();
        instance.output =pack->shutdown_status(i).output();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->shutdown_status(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->SHUTDOWN_STATUS.push(instance);
    }
    for(int i = 0; i < pack->marker_size(); i++){
        static primary_message_MARKER instance;
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->marker(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->MARKER.push(instance);
    }
    for(int i = 0; i < pack->hv_cells_voltage_size(); i++){
        static primary_message_HV_CELLS_VOLTAGE_conversion instance;
        instance.start_index =pack->hv_cells_voltage(i).start_index();
        instance.voltage_0 =pack->hv_cells_voltage(i).voltage_0();
        instance.voltage_1 =pack->hv_cells_voltage(i).voltage_1();
        instance.voltage_2 =pack->hv_cells_voltage(i).voltage_2();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->hv_cells_voltage(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->HV_CELLS_VOLTAGE.push(instance);
    }
    for(int i = 0; i < pack->hv_cells_temp_size(); i++){
        static primary_message_HV_CELLS_TEMP_conversion instance;
        instance.start_index =pack->hv_cells_temp(i).start_index();
        instance.temp_0 =pack->hv_cells_temp(i).temp_0();
        instance.temp_1 =pack->hv_cells_temp(i).temp_1();
        instance.temp_2 =pack->hv_cells_temp(i).temp_2();
        instance.temp_3 =pack->hv_cells_temp(i).temp_3();
        instance.temp_4 =pack->hv_cells_temp(i).temp_4();
        instance.temp_5 =pack->hv_cells_temp(i).temp_5();
        instance.temp_6 =pack->hv_cells_temp(i).temp_6();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->hv_cells_temp(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->HV_CELLS_TEMP.push(instance);
    }
    for(int i = 0; i < pack->hv_cell_balancing_status_size(); i++){
        static primary_message_HV_CELL_BALANCING_STATUS instance;
        instance.balancing_status =(primary_Toggle)pack->hv_cell_balancing_status(i).balancing_status();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->hv_cell_balancing_status(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->HV_CELL_BALANCING_STATUS.push(instance);
    }
    for(int i = 0; i < pack->set_cell_balancing_status_size(); i++){
        static primary_message_SET_CELL_BALANCING_STATUS instance;
        instance.set_balancing_status =(primary_Toggle)pack->set_cell_balancing_status(i).set_balancing_status();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->set_cell_balancing_status(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->SET_CELL_BALANCING_STATUS.push(instance);
    }
    for(int i = 0; i < pack->handcart_status_size(); i++){
        static primary_message_HANDCART_STATUS instance;
        instance.connected =pack->handcart_status(i).connected();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->handcart_status(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->HANDCART_STATUS.push(instance);
    }
    for(int i = 0; i < pack->speed_size(); i++){
        static primary_message_SPEED_conversion instance;
        instance.encoder_r =pack->speed(i).encoder_r();
        instance.encoder_l =pack->speed(i).encoder_l();
        instance.inverter_r =pack->speed(i).inverter_r();
        instance.inverter_l =pack->speed(i).inverter_l();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->speed(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->SPEED.push(instance);
    }
    for(int i = 0; i < pack->inv_l_request_size(); i++){
        static primary_message_INV_L_REQUEST instance;
        instance.data_0 =pack->inv_l_request(i).data_0();
        instance.data_1 =pack->inv_l_request(i).data_1();
        instance.data_2 =pack->inv_l_request(i).data_2();
        instance.data_3 =pack->inv_l_request(i).data_3();
        instance.data_4 =pack->inv_l_request(i).data_4();
        instance.data_5 =pack->inv_l_request(i).data_5();
        instance.data_6 =pack->inv_l_request(i).data_6();
        instance.data_7 =pack->inv_l_request(i).data_7();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->inv_l_request(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->INV_L_REQUEST.push(instance);
    }
    for(int i = 0; i < pack->inv_r_request_size(); i++){
        static primary_message_INV_R_REQUEST instance;
        instance.data_0 =pack->inv_r_request(i).data_0();
        instance.data_1 =pack->inv_r_request(i).data_1();
        instance.data_2 =pack->inv_r_request(i).data_2();
        instance.data_3 =pack->inv_r_request(i).data_3();
        instance.data_4 =pack->inv_r_request(i).data_4();
        instance.data_5 =pack->inv_r_request(i).data_5();
        instance.data_6 =pack->inv_r_request(i).data_6();
        instance.data_7 =pack->inv_r_request(i).data_7();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->inv_r_request(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->INV_R_REQUEST.push(instance);
    }
    for(int i = 0; i < pack->inv_l_response_size(); i++){
        static primary_message_INV_L_RESPONSE instance;
        instance.reg_id =pack->inv_l_response(i).reg_id();
        instance.data_0 =pack->inv_l_response(i).data_0();
        instance.data_1 =pack->inv_l_response(i).data_1();
        instance.data_2 =pack->inv_l_response(i).data_2();
        instance.data_3 =pack->inv_l_response(i).data_3();
        instance.data_4 =pack->inv_l_response(i).data_4();
        instance.data_5 =pack->inv_l_response(i).data_5();
        instance.data_6 =pack->inv_l_response(i).data_6();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->inv_l_response(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->INV_L_RESPONSE.push(instance);
    }
    for(int i = 0; i < pack->inv_r_response_size(); i++){
        static primary_message_INV_R_RESPONSE instance;
        instance.reg_id =pack->inv_r_response(i).reg_id();
        instance.data_0 =pack->inv_r_response(i).data_0();
        instance.data_1 =pack->inv_r_response(i).data_1();
        instance.data_2 =pack->inv_r_response(i).data_2();
        instance.data_3 =pack->inv_r_response(i).data_3();
        instance.data_4 =pack->inv_r_response(i).data_4();
        instance.data_5 =pack->inv_r_response(i).data_5();
        instance.data_6 =pack->inv_r_response(i).data_6();
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->inv_r_response(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->INV_R_RESPONSE.push(instance);
    }
    for(int i = 0; i < pack->flash_cellboard_0_tx_size(); i++){
        static primary_message_FLASH_CELLBOARD_0_TX instance;
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->flash_cellboard_0_tx(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->FLASH_CELLBOARD_0_TX.push(instance);
    }
    for(int i = 0; i < pack->flash_cellboard_0_rx_size(); i++){
        static primary_message_FLASH_CELLBOARD_0_RX instance;
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->flash_cellboard_0_rx(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->FLASH_CELLBOARD_0_RX.push(instance);
    }
    for(int i = 0; i < pack->flash_cellboard_1_tx_size(); i++){
        static primary_message_FLASH_CELLBOARD_1_TX instance;
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->flash_cellboard_1_tx(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->FLASH_CELLBOARD_1_TX.push(instance);
    }
    for(int i = 0; i < pack->flash_cellboard_1_rx_size(); i++){
        static primary_message_FLASH_CELLBOARD_1_RX instance;
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->flash_cellboard_1_rx(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->FLASH_CELLBOARD_1_RX.push(instance);
    }
    for(int i = 0; i < pack->flash_cellboard_2_tx_size(); i++){
        static primary_message_FLASH_CELLBOARD_2_TX instance;
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->flash_cellboard_2_tx(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->FLASH_CELLBOARD_2_TX.push(instance);
    }
    for(int i = 0; i < pack->flash_cellboard_2_rx_size(); i++){
        static primary_message_FLASH_CELLBOARD_2_RX instance;
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->flash_cellboard_2_rx(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->FLASH_CELLBOARD_2_RX.push(instance);
    }
    for(int i = 0; i < pack->flash_cellboard_3_tx_size(); i++){
        static primary_message_FLASH_CELLBOARD_3_TX instance;
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->flash_cellboard_3_tx(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->FLASH_CELLBOARD_3_TX.push(instance);
    }
    for(int i = 0; i < pack->flash_cellboard_3_rx_size(); i++){
        static primary_message_FLASH_CELLBOARD_3_RX instance;
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->flash_cellboard_3_rx(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->FLASH_CELLBOARD_3_RX.push(instance);
    }
    for(int i = 0; i < pack->flash_cellboard_4_tx_size(); i++){
        static primary_message_FLASH_CELLBOARD_4_TX instance;
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->flash_cellboard_4_tx(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->FLASH_CELLBOARD_4_TX.push(instance);
    }
    for(int i = 0; i < pack->flash_cellboard_4_rx_size(); i++){
        static primary_message_FLASH_CELLBOARD_4_RX instance;
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->flash_cellboard_4_rx(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->FLASH_CELLBOARD_4_RX.push(instance);
    }
    for(int i = 0; i < pack->flash_cellboard_5_tx_size(); i++){
        static primary_message_FLASH_CELLBOARD_5_TX instance;
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->flash_cellboard_5_tx(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->FLASH_CELLBOARD_5_TX.push(instance);
    }
    for(int i = 0; i < pack->flash_cellboard_5_rx_size(); i++){
        static primary_message_FLASH_CELLBOARD_5_RX instance;
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->flash_cellboard_5_rx(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->FLASH_CELLBOARD_5_RX.push(instance);
    }
    for(int i = 0; i < pack->flash_bms_hv_tx_size(); i++){
        static primary_message_FLASH_BMS_HV_TX instance;
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->flash_bms_hv_tx(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->FLASH_BMS_HV_TX.push(instance);
    }
    for(int i = 0; i < pack->flash_bms_hv_rx_size(); i++){
        static primary_message_FLASH_BMS_HV_RX instance;
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->flash_bms_hv_rx(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->FLASH_BMS_HV_RX.push(instance);
    }
    for(int i = 0; i < pack->flash_bms_lv_tx_size(); i++){
        static primary_message_FLASH_BMS_LV_TX instance;
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->flash_bms_lv_tx(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->FLASH_BMS_LV_TX.push(instance);
    }
    for(int i = 0; i < pack->flash_bms_lv_rx_size(); i++){
        static primary_message_FLASH_BMS_LV_RX instance;
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->flash_bms_lv_rx(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->FLASH_BMS_LV_RX.push(instance);
    }
    for(int i = 0; i < pack->brusa_nlg5_ctl_size(); i++){
        static primary_message_BRUSA_NLG5_CTL instance;
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->brusa_nlg5_ctl(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->BRUSA_NLG5_CTL.push(instance);
    }
    for(int i = 0; i < pack->brusa_st_size(); i++){
        static primary_message_BRUSA_ST instance;
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->brusa_st(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->BRUSA_ST.push(instance);
    }
    for(int i = 0; i < pack->brusa_act_i_size(); i++){
        static primary_message_BRUSA_ACT_I instance;
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->brusa_act_i(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->BRUSA_ACT_I.push(instance);
    }
    for(int i = 0; i < pack->brusa_act_ii_size(); i++){
        static primary_message_BRUSA_ACT_II instance;
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->brusa_act_ii(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->BRUSA_ACT_II.push(instance);
    }
    for(int i = 0; i < pack->brusa_temp_size(); i++){
        static primary_message_BRUSA_TEMP instance;
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->brusa_temp(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->BRUSA_TEMP.push(instance);
    }
    for(int i = 0; i < pack->brusa_err_size(); i++){
        static primary_message_BRUSA_ERR instance;
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->brusa_err(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->BRUSA_ERR.push(instance);
    }
    for(int i = 0; i < pack->bms_hv_chimera_size(); i++){
        static primary_message_BMS_HV_CHIMERA instance;
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->bms_hv_chimera(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->BMS_HV_CHIMERA.push(instance);
    }
    for(int i = 0; i < pack->ecu_chimera_size(); i++){
        static primary_message_ECU_CHIMERA instance;
#ifdef CANLIB_TIMESTAMP
        instance._timestamp = pack->ecu_chimera(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
        map->ECU_CHIMERA.push(instance);
    }
}

#endif // primary_MAPPING_IMPLEMENTATION

#endif // primary_MAPPING_H