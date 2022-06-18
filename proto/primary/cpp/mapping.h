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

typedef struct {
    std::vector<primary_message_BMS_HV_JMP_TO_BLT> BMS_HV_JMP_TO_BLT;
    std::vector<primary_message_STEER_VERSION> STEER_VERSION;
    std::vector<primary_message_DAS_VERSION> DAS_VERSION;
    std::vector<primary_message_HV_VERSION> HV_VERSION;
    std::vector<primary_message_LV_VERSION> LV_VERSION;
    std::vector<primary_message_TLM_VERSION> TLM_VERSION;
    std::vector<primary_message_TIMESTAMP> TIMESTAMP;
    std::vector<primary_message_SET_TLM_STATUS> SET_TLM_STATUS;
    std::vector<primary_message_TLM_STATUS> TLM_STATUS;
    std::vector<primary_message_STEER_SYSTEM_STATUS> STEER_SYSTEM_STATUS;
    std::vector<primary_message_HV_VOLTAGE_conversion> HV_VOLTAGE;
    std::vector<primary_message_HV_CURRENT_conversion> HV_CURRENT;
    std::vector<primary_message_HV_TEMP_conversion> HV_TEMP;
    std::vector<primary_message_HV_ERRORS> HV_ERRORS;
    std::vector<primary_message_HV_CAN_FORWARD> HV_CAN_FORWARD;
    std::vector<primary_message_HV_CAN_FORWARD_STATUS> HV_CAN_FORWARD_STATUS;
    std::vector<primary_message_TS_STATUS> TS_STATUS;
    std::vector<primary_message_SET_TS_STATUS> SET_TS_STATUS_DAS;
    std::vector<primary_message_SET_TS_STATUS> SET_TS_STATUS_HANDCART;
    std::vector<primary_message_STEER_STATUS> STEER_STATUS;
    std::vector<primary_message_SET_CAR_STATUS> SET_CAR_STATUS;
    std::vector<primary_message_SET_PEDALS_RANGE> SET_PEDALS_RANGE;
    std::vector<primary_message_SET_STEERING_ANGLE_RANGE> SET_STEERING_ANGLE_RANGE;
    std::vector<primary_message_CAR_STATUS> CAR_STATUS;
    std::vector<primary_message_DAS_ERRORS> DAS_ERRORS;
    std::vector<primary_message_LV_CURRENT_conversion> LV_CURRENT;
    std::vector<primary_message_LV_VOLTAGE_conversion> LV_VOLTAGE;
    std::vector<primary_message_LV_TOTAL_VOLTAGE_conversion> LV_TOTAL_VOLTAGE;
    std::vector<primary_message_LV_TEMPERATURE_conversion> LV_TEMPERATURE;
    std::vector<primary_message_COOLING_STATUS_conversion> COOLING_STATUS;
    std::vector<primary_message_SET_RADIATOR_SPEED> SET_RADIATOR_SPEED;
    std::vector<primary_message_SET_PUMPS_SPEED> SET_PUMPS_SPEED;
    std::vector<primary_message_SET_INVERTER_CONNECTION_STATUS> SET_INVERTER_CONNECTION_STATUS;
    std::vector<primary_message_INVERTER_CONNECTION_STATUS> INVERTER_CONNECTION_STATUS;
    std::vector<primary_message_SHUTDOWN_STATUS> SHUTDOWN_STATUS;
    std::vector<primary_message_MARKER> MARKER;
    std::vector<primary_message_HV_CELLS_VOLTAGE_conversion> HV_CELLS_VOLTAGE;
    std::vector<primary_message_HV_CELLS_TEMP_conversion> HV_CELLS_TEMP;
    std::vector<primary_message_HV_CELL_BALANCING_STATUS> HV_CELL_BALANCING_STATUS;
    std::vector<primary_message_SET_CELL_BALANCING_STATUS> SET_CELL_BALANCING_STATUS;
    std::vector<primary_message_HANDCART_STATUS> HANDCART_STATUS;
    std::vector<primary_message_SPEED_conversion> SPEED;
    std::vector<primary_message_INV_L_REQUEST> INV_L_REQUEST;
    std::vector<primary_message_INV_R_REQUEST> INV_R_REQUEST;
    std::vector<primary_message_INV_L_RESPONSE> INV_L_RESPONSE;
    std::vector<primary_message_INV_R_RESPONSE> INV_R_RESPONSE;
    std::vector<primary_message_FLASH_CELLBOARD_0_TX> FLASH_CELLBOARD_0_TX;
    std::vector<primary_message_FLASH_CELLBOARD_0_RX> FLASH_CELLBOARD_0_RX;
    std::vector<primary_message_FLASH_CELLBOARD_1_TX> FLASH_CELLBOARD_1_TX;
    std::vector<primary_message_FLASH_CELLBOARD_1_RX> FLASH_CELLBOARD_1_RX;
    std::vector<primary_message_FLASH_CELLBOARD_2_TX> FLASH_CELLBOARD_2_TX;
    std::vector<primary_message_FLASH_CELLBOARD_2_RX> FLASH_CELLBOARD_2_RX;
    std::vector<primary_message_FLASH_CELLBOARD_3_TX> FLASH_CELLBOARD_3_TX;
    std::vector<primary_message_FLASH_CELLBOARD_3_RX> FLASH_CELLBOARD_3_RX;
    std::vector<primary_message_FLASH_CELLBOARD_4_TX> FLASH_CELLBOARD_4_TX;
    std::vector<primary_message_FLASH_CELLBOARD_4_RX> FLASH_CELLBOARD_4_RX;
    std::vector<primary_message_FLASH_CELLBOARD_5_TX> FLASH_CELLBOARD_5_TX;
    std::vector<primary_message_FLASH_CELLBOARD_5_RX> FLASH_CELLBOARD_5_RX;
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
            proto_msg->set_driver(msg->driver);
            proto_msg->set_circuit(msg->circuit);
            proto_msg->set_race_type((primary::RaceType)msg->race_type);
            proto_msg->set_tlm_status((primary::Toggle)msg->tlm_status);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 259: {
            primary_message_TLM_STATUS* msg = (primary_message_TLM_STATUS*) (*map)[index].message_raw;
            primary::TLM_STATUS* proto_msg = pack->add_tlm_status();
            proto_msg->set_driver(msg->driver);
            proto_msg->set_circuit(msg->circuit);
            proto_msg->set_race_type((primary::RaceType)msg->race_type);
            proto_msg->set_tlm_status((primary::Toggle)msg->tlm_status);
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

        case 6: {
            primary_message_HV_CAN_FORWARD_STATUS* msg = (primary_message_HV_CAN_FORWARD_STATUS*) (*map)[index].message_raw;
            primary::HV_CAN_FORWARD_STATUS* proto_msg = pack->add_hv_can_forward_status();
            proto_msg->set_can_forward_status((primary::Toggle)msg->can_forward_status);
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

        case 37: {
            primary_message_SET_TS_STATUS* msg = (primary_message_SET_TS_STATUS*) (*map)[index].message_raw;
            primary::SET_TS_STATUS_DAS* proto_msg = pack->add_set_ts_status_das();
            proto_msg->set_ts_status_set((primary::Toggle)msg->ts_status_set);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 69: {
            primary_message_SET_TS_STATUS* msg = (primary_message_SET_TS_STATUS*) (*map)[index].message_raw;
            primary::SET_TS_STATUS_HANDCART* proto_msg = pack->add_set_ts_status_handcart();
            proto_msg->set_ts_status_set((primary::Toggle)msg->ts_status_set);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 263: {
            primary_message_STEER_STATUS* msg = (primary_message_STEER_STATUS*) (*map)[index].message_raw;
            primary::STEER_STATUS* proto_msg = pack->add_steer_status();
            proto_msg->set_map((primary::Map)msg->map);
            proto_msg->set_traction_control((primary::TractionControl)msg->traction_control);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 775: {
            primary_message_SET_CAR_STATUS* msg = (primary_message_SET_CAR_STATUS*) (*map)[index].message_raw;
            primary::SET_CAR_STATUS* proto_msg = pack->add_set_car_status();
            proto_msg->set_car_status_set((primary::SetCarStatus)msg->car_status_set);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1031: {
            primary_message_SET_PEDALS_RANGE* msg = (primary_message_SET_PEDALS_RANGE*) (*map)[index].message_raw;
            primary::SET_PEDALS_RANGE* proto_msg = pack->add_set_pedals_range();
            proto_msg->set_bound((primary::Bound)msg->bound);
            proto_msg->set_pedal((primary::Pedal)msg->pedal);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1063: {
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

        case 776: {
            primary_message_LV_CURRENT_conversion* msg = (primary_message_LV_CURRENT_conversion*) (*map)[index].message_conversion;
            primary::LV_CURRENT* proto_msg = pack->add_lv_current();
            proto_msg->set_current(msg->current);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 808: {
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

        case 840: {
            primary_message_LV_TOTAL_VOLTAGE_conversion* msg = (primary_message_LV_TOTAL_VOLTAGE_conversion*) (*map)[index].message_conversion;
            primary::LV_TOTAL_VOLTAGE* proto_msg = pack->add_lv_total_voltage();
            proto_msg->set_total_voltage(msg->total_voltage);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 872: {
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

        case 904: {
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
            primary_message_SET_RADIATOR_SPEED* msg = (primary_message_SET_RADIATOR_SPEED*) (*map)[index].message_raw;
            primary::SET_RADIATOR_SPEED* proto_msg = pack->add_set_radiator_speed();
            proto_msg->set_radiator_speed((primary::Cooling)msg->radiator_speed);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 809: {
            primary_message_SET_PUMPS_SPEED* msg = (primary_message_SET_PUMPS_SPEED*) (*map)[index].message_raw;
            primary::SET_PUMPS_SPEED* proto_msg = pack->add_set_pumps_speed();
            proto_msg->set_pumps_speed((primary::Cooling)msg->pumps_speed);
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

        case 264: {
            primary_message_INVERTER_CONNECTION_STATUS* msg = (primary_message_INVERTER_CONNECTION_STATUS*) (*map)[index].message_raw;
            primary::INVERTER_CONNECTION_STATUS* proto_msg = pack->add_inverter_connection_status();
            proto_msg->set_status((primary::Toggle)msg->status);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 296: {
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
            proto_msg->set_voltage_0(msg->voltage_0);
            proto_msg->set_voltage_1(msg->voltage_1);
            proto_msg->set_voltage_2(msg->voltage_2);
            proto_msg->set_start_index(msg->start_index);
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

    }
}

void primary_proto_deserialize(primary::Pack* pack, primary_proto_pack* map) {
    map->BMS_HV_JMP_TO_BLT.resize(pack->bms_hv_jmp_to_blt_size());
    for(int i = 0; i < pack->bms_hv_jmp_to_blt_size(); i++){
#ifdef CANLIB_TIMESTAMP
        map->BMS_HV_JMP_TO_BLT[i]._timestamp = pack->bms_hv_jmp_to_blt(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->STEER_VERSION.resize(pack->steer_version_size());
    for(int i = 0; i < pack->steer_version_size(); i++){
        map->STEER_VERSION[i].component_version =pack->steer_version(i).component_version();
        map->STEER_VERSION[i].cancicd_version =pack->steer_version(i).cancicd_version();
#ifdef CANLIB_TIMESTAMP
        map->STEER_VERSION[i]._timestamp = pack->steer_version(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->DAS_VERSION.resize(pack->das_version_size());
    for(int i = 0; i < pack->das_version_size(); i++){
        map->DAS_VERSION[i].component_version =pack->das_version(i).component_version();
        map->DAS_VERSION[i].cancicd_version =pack->das_version(i).cancicd_version();
#ifdef CANLIB_TIMESTAMP
        map->DAS_VERSION[i]._timestamp = pack->das_version(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->HV_VERSION.resize(pack->hv_version_size());
    for(int i = 0; i < pack->hv_version_size(); i++){
        map->HV_VERSION[i].component_version =pack->hv_version(i).component_version();
        map->HV_VERSION[i].cancicd_version =pack->hv_version(i).cancicd_version();
#ifdef CANLIB_TIMESTAMP
        map->HV_VERSION[i]._timestamp = pack->hv_version(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->LV_VERSION.resize(pack->lv_version_size());
    for(int i = 0; i < pack->lv_version_size(); i++){
        map->LV_VERSION[i].component_version =pack->lv_version(i).component_version();
        map->LV_VERSION[i].cancicd_version =pack->lv_version(i).cancicd_version();
#ifdef CANLIB_TIMESTAMP
        map->LV_VERSION[i]._timestamp = pack->lv_version(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->TLM_VERSION.resize(pack->tlm_version_size());
    for(int i = 0; i < pack->tlm_version_size(); i++){
        map->TLM_VERSION[i].component_version =pack->tlm_version(i).component_version();
        map->TLM_VERSION[i].cancicd_version =pack->tlm_version(i).cancicd_version();
#ifdef CANLIB_TIMESTAMP
        map->TLM_VERSION[i]._timestamp = pack->tlm_version(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->TIMESTAMP.resize(pack->timestamp_size());
    for(int i = 0; i < pack->timestamp_size(); i++){
        map->TIMESTAMP[i].timestamp =pack->timestamp(i).timestamp();
#ifdef CANLIB_TIMESTAMP
        map->TIMESTAMP[i]._timestamp = pack->timestamp(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->SET_TLM_STATUS.resize(pack->set_tlm_status_size());
    for(int i = 0; i < pack->set_tlm_status_size(); i++){
        map->SET_TLM_STATUS[i].driver =pack->set_tlm_status(i).driver();
        map->SET_TLM_STATUS[i].circuit =pack->set_tlm_status(i).circuit();
        map->SET_TLM_STATUS[i].race_type =(primary_RaceType)pack->set_tlm_status(i).race_type();
        map->SET_TLM_STATUS[i].tlm_status =(primary_Toggle)pack->set_tlm_status(i).tlm_status();
#ifdef CANLIB_TIMESTAMP
        map->SET_TLM_STATUS[i]._timestamp = pack->set_tlm_status(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->TLM_STATUS.resize(pack->tlm_status_size());
    for(int i = 0; i < pack->tlm_status_size(); i++){
        map->TLM_STATUS[i].driver =pack->tlm_status(i).driver();
        map->TLM_STATUS[i].circuit =pack->tlm_status(i).circuit();
        map->TLM_STATUS[i].race_type =(primary_RaceType)pack->tlm_status(i).race_type();
        map->TLM_STATUS[i].tlm_status =(primary_Toggle)pack->tlm_status(i).tlm_status();
#ifdef CANLIB_TIMESTAMP
        map->TLM_STATUS[i]._timestamp = pack->tlm_status(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->STEER_SYSTEM_STATUS.resize(pack->steer_system_status_size());
    for(int i = 0; i < pack->steer_system_status_size(); i++){
        map->STEER_SYSTEM_STATUS[i].soc_temp =pack->steer_system_status(i).soc_temp();
#ifdef CANLIB_TIMESTAMP
        map->STEER_SYSTEM_STATUS[i]._timestamp = pack->steer_system_status(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->HV_VOLTAGE.resize(pack->hv_voltage_size());
    for(int i = 0; i < pack->hv_voltage_size(); i++){
        map->HV_VOLTAGE[i].pack_voltage =pack->hv_voltage(i).pack_voltage();
        map->HV_VOLTAGE[i].bus_voltage =pack->hv_voltage(i).bus_voltage();
        map->HV_VOLTAGE[i].max_cell_voltage =pack->hv_voltage(i).max_cell_voltage();
        map->HV_VOLTAGE[i].min_cell_voltage =pack->hv_voltage(i).min_cell_voltage();
#ifdef CANLIB_TIMESTAMP
        map->HV_VOLTAGE[i]._timestamp = pack->hv_voltage(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->HV_CURRENT.resize(pack->hv_current_size());
    for(int i = 0; i < pack->hv_current_size(); i++){
        map->HV_CURRENT[i].current =pack->hv_current(i).current();
        map->HV_CURRENT[i].power =pack->hv_current(i).power();
#ifdef CANLIB_TIMESTAMP
        map->HV_CURRENT[i]._timestamp = pack->hv_current(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->HV_TEMP.resize(pack->hv_temp_size());
    for(int i = 0; i < pack->hv_temp_size(); i++){
        map->HV_TEMP[i].average_temp =pack->hv_temp(i).average_temp();
        map->HV_TEMP[i].max_temp =pack->hv_temp(i).max_temp();
        map->HV_TEMP[i].min_temp =pack->hv_temp(i).min_temp();
#ifdef CANLIB_TIMESTAMP
        map->HV_TEMP[i]._timestamp = pack->hv_temp(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->HV_ERRORS.resize(pack->hv_errors_size());
    for(int i = 0; i < pack->hv_errors_size(); i++){
        map->HV_ERRORS[i].warnings =pack->hv_errors(i).warnings();
        map->HV_ERRORS[i].errors =pack->hv_errors(i).errors();
#ifdef CANLIB_TIMESTAMP
        map->HV_ERRORS[i]._timestamp = pack->hv_errors(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->HV_CAN_FORWARD.resize(pack->hv_can_forward_size());
    for(int i = 0; i < pack->hv_can_forward_size(); i++){
        map->HV_CAN_FORWARD[i].can_forward_set =(primary_Toggle)pack->hv_can_forward(i).can_forward_set();
#ifdef CANLIB_TIMESTAMP
        map->HV_CAN_FORWARD[i]._timestamp = pack->hv_can_forward(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->HV_CAN_FORWARD_STATUS.resize(pack->hv_can_forward_status_size());
    for(int i = 0; i < pack->hv_can_forward_status_size(); i++){
        map->HV_CAN_FORWARD_STATUS[i].can_forward_status =(primary_Toggle)pack->hv_can_forward_status(i).can_forward_status();
#ifdef CANLIB_TIMESTAMP
        map->HV_CAN_FORWARD_STATUS[i]._timestamp = pack->hv_can_forward_status(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->TS_STATUS.resize(pack->ts_status_size());
    for(int i = 0; i < pack->ts_status_size(); i++){
        map->TS_STATUS[i].ts_status =(primary_TsStatus)pack->ts_status(i).ts_status();
#ifdef CANLIB_TIMESTAMP
        map->TS_STATUS[i]._timestamp = pack->ts_status(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->SET_TS_STATUS_DAS.resize(pack->set_ts_status_das_size());
    for(int i = 0; i < pack->set_ts_status_das_size(); i++){
        map->SET_TS_STATUS_DAS[i].ts_status_set =(primary_Toggle)pack->set_ts_status_das(i).ts_status_set();
#ifdef CANLIB_TIMESTAMP
        map->SET_TS_STATUS_DAS[i]._timestamp = pack->set_ts_status_das(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->SET_TS_STATUS_HANDCART.resize(pack->set_ts_status_handcart_size());
    for(int i = 0; i < pack->set_ts_status_handcart_size(); i++){
        map->SET_TS_STATUS_HANDCART[i].ts_status_set =(primary_Toggle)pack->set_ts_status_handcart(i).ts_status_set();
#ifdef CANLIB_TIMESTAMP
        map->SET_TS_STATUS_HANDCART[i]._timestamp = pack->set_ts_status_handcart(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->STEER_STATUS.resize(pack->steer_status_size());
    for(int i = 0; i < pack->steer_status_size(); i++){
        map->STEER_STATUS[i].map =(primary_Map)pack->steer_status(i).map();
        map->STEER_STATUS[i].traction_control =(primary_TractionControl)pack->steer_status(i).traction_control();
#ifdef CANLIB_TIMESTAMP
        map->STEER_STATUS[i]._timestamp = pack->steer_status(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->SET_CAR_STATUS.resize(pack->set_car_status_size());
    for(int i = 0; i < pack->set_car_status_size(); i++){
        map->SET_CAR_STATUS[i].car_status_set =(primary_SetCarStatus)pack->set_car_status(i).car_status_set();
#ifdef CANLIB_TIMESTAMP
        map->SET_CAR_STATUS[i]._timestamp = pack->set_car_status(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->SET_PEDALS_RANGE.resize(pack->set_pedals_range_size());
    for(int i = 0; i < pack->set_pedals_range_size(); i++){
        map->SET_PEDALS_RANGE[i].bound =(primary_Bound)pack->set_pedals_range(i).bound();
        map->SET_PEDALS_RANGE[i].pedal =(primary_Pedal)pack->set_pedals_range(i).pedal();
#ifdef CANLIB_TIMESTAMP
        map->SET_PEDALS_RANGE[i]._timestamp = pack->set_pedals_range(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->SET_STEERING_ANGLE_RANGE.resize(pack->set_steering_angle_range_size());
    for(int i = 0; i < pack->set_steering_angle_range_size(); i++){
        map->SET_STEERING_ANGLE_RANGE[i].bound =(primary_Bound)pack->set_steering_angle_range(i).bound();
#ifdef CANLIB_TIMESTAMP
        map->SET_STEERING_ANGLE_RANGE[i]._timestamp = pack->set_steering_angle_range(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->CAR_STATUS.resize(pack->car_status_size());
    for(int i = 0; i < pack->car_status_size(); i++){
        map->CAR_STATUS[i].inverter_l =(primary_InverterStatus)pack->car_status(i).inverter_l();
        map->CAR_STATUS[i].inverter_r =(primary_InverterStatus)pack->car_status(i).inverter_r();
        map->CAR_STATUS[i].car_status =(primary_CarStatus)pack->car_status(i).car_status();
#ifdef CANLIB_TIMESTAMP
        map->CAR_STATUS[i]._timestamp = pack->car_status(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->DAS_ERRORS.resize(pack->das_errors_size());
    for(int i = 0; i < pack->das_errors_size(); i++){
        map->DAS_ERRORS[i].das_error =pack->das_errors(i).das_error();
#ifdef CANLIB_TIMESTAMP
        map->DAS_ERRORS[i]._timestamp = pack->das_errors(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->LV_CURRENT.resize(pack->lv_current_size());
    for(int i = 0; i < pack->lv_current_size(); i++){
        map->LV_CURRENT[i].current =pack->lv_current(i).current();
#ifdef CANLIB_TIMESTAMP
        map->LV_CURRENT[i]._timestamp = pack->lv_current(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->LV_VOLTAGE.resize(pack->lv_voltage_size());
    for(int i = 0; i < pack->lv_voltage_size(); i++){
        map->LV_VOLTAGE[i].voltage_1 =pack->lv_voltage(i).voltage_1();
        map->LV_VOLTAGE[i].voltage_2 =pack->lv_voltage(i).voltage_2();
        map->LV_VOLTAGE[i].voltage_3 =pack->lv_voltage(i).voltage_3();
        map->LV_VOLTAGE[i].voltage_4 =pack->lv_voltage(i).voltage_4();
#ifdef CANLIB_TIMESTAMP
        map->LV_VOLTAGE[i]._timestamp = pack->lv_voltage(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->LV_TOTAL_VOLTAGE.resize(pack->lv_total_voltage_size());
    for(int i = 0; i < pack->lv_total_voltage_size(); i++){
        map->LV_TOTAL_VOLTAGE[i].total_voltage =pack->lv_total_voltage(i).total_voltage();
#ifdef CANLIB_TIMESTAMP
        map->LV_TOTAL_VOLTAGE[i]._timestamp = pack->lv_total_voltage(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->LV_TEMPERATURE.resize(pack->lv_temperature_size());
    for(int i = 0; i < pack->lv_temperature_size(); i++){
        map->LV_TEMPERATURE[i].bp_temperature_1 =pack->lv_temperature(i).bp_temperature_1();
        map->LV_TEMPERATURE[i].bp_temperature_2 =pack->lv_temperature(i).bp_temperature_2();
        map->LV_TEMPERATURE[i].dcdc12_temperature =pack->lv_temperature(i).dcdc12_temperature();
        map->LV_TEMPERATURE[i].dcdc24_temperature =pack->lv_temperature(i).dcdc24_temperature();
#ifdef CANLIB_TIMESTAMP
        map->LV_TEMPERATURE[i]._timestamp = pack->lv_temperature(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->COOLING_STATUS.resize(pack->cooling_status_size());
    for(int i = 0; i < pack->cooling_status_size(); i++){
        map->COOLING_STATUS[i].radiators_speed =pack->cooling_status(i).radiators_speed();
        map->COOLING_STATUS[i].pumps_speed =pack->cooling_status(i).pumps_speed();
#ifdef CANLIB_TIMESTAMP
        map->COOLING_STATUS[i]._timestamp = pack->cooling_status(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->SET_RADIATOR_SPEED.resize(pack->set_radiator_speed_size());
    for(int i = 0; i < pack->set_radiator_speed_size(); i++){
        map->SET_RADIATOR_SPEED[i].radiator_speed =(primary_Cooling)pack->set_radiator_speed(i).radiator_speed();
#ifdef CANLIB_TIMESTAMP
        map->SET_RADIATOR_SPEED[i]._timestamp = pack->set_radiator_speed(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->SET_PUMPS_SPEED.resize(pack->set_pumps_speed_size());
    for(int i = 0; i < pack->set_pumps_speed_size(); i++){
        map->SET_PUMPS_SPEED[i].pumps_speed =(primary_Cooling)pack->set_pumps_speed(i).pumps_speed();
#ifdef CANLIB_TIMESTAMP
        map->SET_PUMPS_SPEED[i]._timestamp = pack->set_pumps_speed(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->SET_INVERTER_CONNECTION_STATUS.resize(pack->set_inverter_connection_status_size());
    for(int i = 0; i < pack->set_inverter_connection_status_size(); i++){
        map->SET_INVERTER_CONNECTION_STATUS[i].status =(primary_Toggle)pack->set_inverter_connection_status(i).status();
#ifdef CANLIB_TIMESTAMP
        map->SET_INVERTER_CONNECTION_STATUS[i]._timestamp = pack->set_inverter_connection_status(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->INVERTER_CONNECTION_STATUS.resize(pack->inverter_connection_status_size());
    for(int i = 0; i < pack->inverter_connection_status_size(); i++){
        map->INVERTER_CONNECTION_STATUS[i].status =(primary_Toggle)pack->inverter_connection_status(i).status();
#ifdef CANLIB_TIMESTAMP
        map->INVERTER_CONNECTION_STATUS[i]._timestamp = pack->inverter_connection_status(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->SHUTDOWN_STATUS.resize(pack->shutdown_status_size());
    for(int i = 0; i < pack->shutdown_status_size(); i++){
        map->SHUTDOWN_STATUS[i].input =pack->shutdown_status(i).input();
        map->SHUTDOWN_STATUS[i].output =pack->shutdown_status(i).output();
#ifdef CANLIB_TIMESTAMP
        map->SHUTDOWN_STATUS[i]._timestamp = pack->shutdown_status(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->MARKER.resize(pack->marker_size());
    for(int i = 0; i < pack->marker_size(); i++){
#ifdef CANLIB_TIMESTAMP
        map->MARKER[i]._timestamp = pack->marker(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->HV_CELLS_VOLTAGE.resize(pack->hv_cells_voltage_size());
    for(int i = 0; i < pack->hv_cells_voltage_size(); i++){
        map->HV_CELLS_VOLTAGE[i].voltage_0 =pack->hv_cells_voltage(i).voltage_0();
        map->HV_CELLS_VOLTAGE[i].voltage_1 =pack->hv_cells_voltage(i).voltage_1();
        map->HV_CELLS_VOLTAGE[i].voltage_2 =pack->hv_cells_voltage(i).voltage_2();
        map->HV_CELLS_VOLTAGE[i].start_index =pack->hv_cells_voltage(i).start_index();
#ifdef CANLIB_TIMESTAMP
        map->HV_CELLS_VOLTAGE[i]._timestamp = pack->hv_cells_voltage(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->HV_CELLS_TEMP.resize(pack->hv_cells_temp_size());
    for(int i = 0; i < pack->hv_cells_temp_size(); i++){
        map->HV_CELLS_TEMP[i].start_index =pack->hv_cells_temp(i).start_index();
        map->HV_CELLS_TEMP[i].temp_0 =pack->hv_cells_temp(i).temp_0();
        map->HV_CELLS_TEMP[i].temp_1 =pack->hv_cells_temp(i).temp_1();
        map->HV_CELLS_TEMP[i].temp_2 =pack->hv_cells_temp(i).temp_2();
        map->HV_CELLS_TEMP[i].temp_3 =pack->hv_cells_temp(i).temp_3();
        map->HV_CELLS_TEMP[i].temp_4 =pack->hv_cells_temp(i).temp_4();
        map->HV_CELLS_TEMP[i].temp_5 =pack->hv_cells_temp(i).temp_5();
        map->HV_CELLS_TEMP[i].temp_6 =pack->hv_cells_temp(i).temp_6();
#ifdef CANLIB_TIMESTAMP
        map->HV_CELLS_TEMP[i]._timestamp = pack->hv_cells_temp(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->HV_CELL_BALANCING_STATUS.resize(pack->hv_cell_balancing_status_size());
    for(int i = 0; i < pack->hv_cell_balancing_status_size(); i++){
        map->HV_CELL_BALANCING_STATUS[i].balancing_status =(primary_Toggle)pack->hv_cell_balancing_status(i).balancing_status();
#ifdef CANLIB_TIMESTAMP
        map->HV_CELL_BALANCING_STATUS[i]._timestamp = pack->hv_cell_balancing_status(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->SET_CELL_BALANCING_STATUS.resize(pack->set_cell_balancing_status_size());
    for(int i = 0; i < pack->set_cell_balancing_status_size(); i++){
        map->SET_CELL_BALANCING_STATUS[i].set_balancing_status =(primary_Toggle)pack->set_cell_balancing_status(i).set_balancing_status();
#ifdef CANLIB_TIMESTAMP
        map->SET_CELL_BALANCING_STATUS[i]._timestamp = pack->set_cell_balancing_status(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->HANDCART_STATUS.resize(pack->handcart_status_size());
    for(int i = 0; i < pack->handcart_status_size(); i++){
        map->HANDCART_STATUS[i].connected =pack->handcart_status(i).connected();
#ifdef CANLIB_TIMESTAMP
        map->HANDCART_STATUS[i]._timestamp = pack->handcart_status(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->SPEED.resize(pack->speed_size());
    for(int i = 0; i < pack->speed_size(); i++){
        map->SPEED[i].encoder_r =pack->speed(i).encoder_r();
        map->SPEED[i].encoder_l =pack->speed(i).encoder_l();
        map->SPEED[i].inverter_r =pack->speed(i).inverter_r();
        map->SPEED[i].inverter_l =pack->speed(i).inverter_l();
#ifdef CANLIB_TIMESTAMP
        map->SPEED[i]._timestamp = pack->speed(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->INV_L_REQUEST.resize(pack->inv_l_request_size());
    for(int i = 0; i < pack->inv_l_request_size(); i++){
        map->INV_L_REQUEST[i].data_0 =pack->inv_l_request(i).data_0();
        map->INV_L_REQUEST[i].data_1 =pack->inv_l_request(i).data_1();
        map->INV_L_REQUEST[i].data_2 =pack->inv_l_request(i).data_2();
        map->INV_L_REQUEST[i].data_3 =pack->inv_l_request(i).data_3();
        map->INV_L_REQUEST[i].data_4 =pack->inv_l_request(i).data_4();
        map->INV_L_REQUEST[i].data_5 =pack->inv_l_request(i).data_5();
        map->INV_L_REQUEST[i].data_6 =pack->inv_l_request(i).data_6();
        map->INV_L_REQUEST[i].data_7 =pack->inv_l_request(i).data_7();
#ifdef CANLIB_TIMESTAMP
        map->INV_L_REQUEST[i]._timestamp = pack->inv_l_request(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->INV_R_REQUEST.resize(pack->inv_r_request_size());
    for(int i = 0; i < pack->inv_r_request_size(); i++){
        map->INV_R_REQUEST[i].data_0 =pack->inv_r_request(i).data_0();
        map->INV_R_REQUEST[i].data_1 =pack->inv_r_request(i).data_1();
        map->INV_R_REQUEST[i].data_2 =pack->inv_r_request(i).data_2();
        map->INV_R_REQUEST[i].data_3 =pack->inv_r_request(i).data_3();
        map->INV_R_REQUEST[i].data_4 =pack->inv_r_request(i).data_4();
        map->INV_R_REQUEST[i].data_5 =pack->inv_r_request(i).data_5();
        map->INV_R_REQUEST[i].data_6 =pack->inv_r_request(i).data_6();
        map->INV_R_REQUEST[i].data_7 =pack->inv_r_request(i).data_7();
#ifdef CANLIB_TIMESTAMP
        map->INV_R_REQUEST[i]._timestamp = pack->inv_r_request(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->INV_L_RESPONSE.resize(pack->inv_l_response_size());
    for(int i = 0; i < pack->inv_l_response_size(); i++){
        map->INV_L_RESPONSE[i].reg_id =pack->inv_l_response(i).reg_id();
        map->INV_L_RESPONSE[i].data_0 =pack->inv_l_response(i).data_0();
        map->INV_L_RESPONSE[i].data_1 =pack->inv_l_response(i).data_1();
        map->INV_L_RESPONSE[i].data_2 =pack->inv_l_response(i).data_2();
        map->INV_L_RESPONSE[i].data_3 =pack->inv_l_response(i).data_3();
        map->INV_L_RESPONSE[i].data_4 =pack->inv_l_response(i).data_4();
        map->INV_L_RESPONSE[i].data_5 =pack->inv_l_response(i).data_5();
        map->INV_L_RESPONSE[i].data_6 =pack->inv_l_response(i).data_6();
#ifdef CANLIB_TIMESTAMP
        map->INV_L_RESPONSE[i]._timestamp = pack->inv_l_response(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->INV_R_RESPONSE.resize(pack->inv_r_response_size());
    for(int i = 0; i < pack->inv_r_response_size(); i++){
        map->INV_R_RESPONSE[i].reg_id =pack->inv_r_response(i).reg_id();
        map->INV_R_RESPONSE[i].data_0 =pack->inv_r_response(i).data_0();
        map->INV_R_RESPONSE[i].data_1 =pack->inv_r_response(i).data_1();
        map->INV_R_RESPONSE[i].data_2 =pack->inv_r_response(i).data_2();
        map->INV_R_RESPONSE[i].data_3 =pack->inv_r_response(i).data_3();
        map->INV_R_RESPONSE[i].data_4 =pack->inv_r_response(i).data_4();
        map->INV_R_RESPONSE[i].data_5 =pack->inv_r_response(i).data_5();
        map->INV_R_RESPONSE[i].data_6 =pack->inv_r_response(i).data_6();
#ifdef CANLIB_TIMESTAMP
        map->INV_R_RESPONSE[i]._timestamp = pack->inv_r_response(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->FLASH_CELLBOARD_0_TX.resize(pack->flash_cellboard_0_tx_size());
    for(int i = 0; i < pack->flash_cellboard_0_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        map->FLASH_CELLBOARD_0_TX[i]._timestamp = pack->flash_cellboard_0_tx(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->FLASH_CELLBOARD_0_RX.resize(pack->flash_cellboard_0_rx_size());
    for(int i = 0; i < pack->flash_cellboard_0_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        map->FLASH_CELLBOARD_0_RX[i]._timestamp = pack->flash_cellboard_0_rx(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->FLASH_CELLBOARD_1_TX.resize(pack->flash_cellboard_1_tx_size());
    for(int i = 0; i < pack->flash_cellboard_1_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        map->FLASH_CELLBOARD_1_TX[i]._timestamp = pack->flash_cellboard_1_tx(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->FLASH_CELLBOARD_1_RX.resize(pack->flash_cellboard_1_rx_size());
    for(int i = 0; i < pack->flash_cellboard_1_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        map->FLASH_CELLBOARD_1_RX[i]._timestamp = pack->flash_cellboard_1_rx(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->FLASH_CELLBOARD_2_TX.resize(pack->flash_cellboard_2_tx_size());
    for(int i = 0; i < pack->flash_cellboard_2_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        map->FLASH_CELLBOARD_2_TX[i]._timestamp = pack->flash_cellboard_2_tx(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->FLASH_CELLBOARD_2_RX.resize(pack->flash_cellboard_2_rx_size());
    for(int i = 0; i < pack->flash_cellboard_2_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        map->FLASH_CELLBOARD_2_RX[i]._timestamp = pack->flash_cellboard_2_rx(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->FLASH_CELLBOARD_3_TX.resize(pack->flash_cellboard_3_tx_size());
    for(int i = 0; i < pack->flash_cellboard_3_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        map->FLASH_CELLBOARD_3_TX[i]._timestamp = pack->flash_cellboard_3_tx(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->FLASH_CELLBOARD_3_RX.resize(pack->flash_cellboard_3_rx_size());
    for(int i = 0; i < pack->flash_cellboard_3_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        map->FLASH_CELLBOARD_3_RX[i]._timestamp = pack->flash_cellboard_3_rx(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->FLASH_CELLBOARD_4_TX.resize(pack->flash_cellboard_4_tx_size());
    for(int i = 0; i < pack->flash_cellboard_4_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        map->FLASH_CELLBOARD_4_TX[i]._timestamp = pack->flash_cellboard_4_tx(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->FLASH_CELLBOARD_4_RX.resize(pack->flash_cellboard_4_rx_size());
    for(int i = 0; i < pack->flash_cellboard_4_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        map->FLASH_CELLBOARD_4_RX[i]._timestamp = pack->flash_cellboard_4_rx(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->FLASH_CELLBOARD_5_TX.resize(pack->flash_cellboard_5_tx_size());
    for(int i = 0; i < pack->flash_cellboard_5_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        map->FLASH_CELLBOARD_5_TX[i]._timestamp = pack->flash_cellboard_5_tx(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->FLASH_CELLBOARD_5_RX.resize(pack->flash_cellboard_5_rx_size());
    for(int i = 0; i < pack->flash_cellboard_5_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        map->FLASH_CELLBOARD_5_RX[i]._timestamp = pack->flash_cellboard_5_rx(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
}

#endif // primary_MAPPING_IMPLEMENTATION

#endif // primary_MAPPING_H