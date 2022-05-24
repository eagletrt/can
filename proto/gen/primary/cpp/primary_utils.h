#include <string>
#include "primary.pb.h"
extern "C" {
#include "../../../../naked_generator/primary/c/primary.h"
}
#define BITSET_VALUE(bitset, size) \
bitset_value=0; \
current_value=0; \
for(short i = 0; i < size*8; i++){ \
current_value += getBit(bitset, i); \
if(i%8 == 7){ \
short shift_amount = i/8; \
current_value <<= 8*shift_amount; \
bitset_value += current_value; \
current_value = 0; \
} \
}
std::string primary_naked2protobuf(uint32_t id, uint8_t* payload){
uint64_t bitset_value, current_value;
switch(id) {


case {'STEER_VERSION': 1024}:
{
PrimarySteerVersionMsg* primary_steer_version_d = (PrimarySteerVersionMsg*)malloc(PRIMARY_STEER_VERSION_SIZE);
deserialize_PrimarySteerVersion(payload, primary_steer_version_d);

primary::SteerVersion primary_steer_version_p;
primary_steer_version_p.set_component_version(primary_steer_version_d->);
primary_steer_version_p.set_cancicd_version(primary_steer_version_d->);
primary_steer_version_p.set_timestamp(primary_steer_version_d->);
free(primary_steer_version_d);
std::string serialized;
primary_steer_version_p.SerializeToString(&serialized);
return serialized;
}


case {'DAS_VERSION': 1056}:
{
PrimaryDasVersionMsg* primary_das_version_d = (PrimaryDasVersionMsg*)malloc(PRIMARY_DAS_VERSION_SIZE);
deserialize_PrimaryDasVersion(payload, primary_das_version_d);

primary::DasVersion primary_das_version_p;
primary_das_version_p.set_component_version(primary_das_version_d->);
primary_das_version_p.set_cancicd_version(primary_das_version_d->);
primary_das_version_p.set_timestamp(primary_das_version_d->);
free(primary_das_version_d);
std::string serialized;
primary_das_version_p.SerializeToString(&serialized);
return serialized;
}


case {'HV_VERSION': 1088}:
{
PrimaryHvVersionMsg* primary_hv_version_d = (PrimaryHvVersionMsg*)malloc(PRIMARY_HV_VERSION_SIZE);
deserialize_PrimaryHvVersion(payload, primary_hv_version_d);

primary::HvVersion primary_hv_version_p;
primary_hv_version_p.set_component_version(primary_hv_version_d->);
primary_hv_version_p.set_cancicd_version(primary_hv_version_d->);
primary_hv_version_p.set_timestamp(primary_hv_version_d->);
free(primary_hv_version_d);
std::string serialized;
primary_hv_version_p.SerializeToString(&serialized);
return serialized;
}


case {'LV_VERSION': 1120}:
{
PrimaryLvVersionMsg* primary_lv_version_d = (PrimaryLvVersionMsg*)malloc(PRIMARY_LV_VERSION_SIZE);
deserialize_PrimaryLvVersion(payload, primary_lv_version_d);

primary::LvVersion primary_lv_version_p;
primary_lv_version_p.set_component_version(primary_lv_version_d->);
primary_lv_version_p.set_cancicd_version(primary_lv_version_d->);
primary_lv_version_p.set_timestamp(primary_lv_version_d->);
free(primary_lv_version_d);
std::string serialized;
primary_lv_version_p.SerializeToString(&serialized);
return serialized;
}


case {'TLM_VERSION': 1152}:
{
PrimaryTlmVersionMsg* primary_tlm_version_d = (PrimaryTlmVersionMsg*)malloc(PRIMARY_TLM_VERSION_SIZE);
deserialize_PrimaryTlmVersion(payload, primary_tlm_version_d);

primary::TlmVersion primary_tlm_version_p;
primary_tlm_version_p.set_component_version(primary_tlm_version_d->);
primary_tlm_version_p.set_cancicd_version(primary_tlm_version_d->);
primary_tlm_version_p.set_timestamp(primary_tlm_version_d->);
free(primary_tlm_version_d);
std::string serialized;
primary_tlm_version_p.SerializeToString(&serialized);
return serialized;
}


case {'TIMESTAMP': 256}:
{
PrimaryTimestampMsg* primary_timestamp_d = (PrimaryTimestampMsg*)malloc(PRIMARY_TIMESTAMP_SIZE);
deserialize_PrimaryTimestamp(payload, primary_timestamp_d);

primary::Timestamp primary_timestamp_p;
primary_timestamp_p.set_timestamp(primary_timestamp_d->);
free(primary_timestamp_d);
std::string serialized;
primary_timestamp_p.SerializeToString(&serialized);
return serialized;
}


case {'SET_TLM_STATUS': 257}:
{
PrimarySetTlmStatusMsg* primary_set_tlm_status_d = (PrimarySetTlmStatusMsg*)malloc(PRIMARY_SET_TLM_STATUS_SIZE);
deserialize_PrimarySetTlmStatus(payload, primary_set_tlm_status_d);

primary::SetTlmStatus primary_set_tlm_status_p;
primary_set_tlm_status_p.set_tlm_status(primary_set_tlm_status_d->);
primary_set_tlm_status_p.set_race_type(primary_set_tlm_status_d->);
primary_set_tlm_status_p.set_driver(primary_set_tlm_status_d->);
primary_set_tlm_status_p.set_circuit(primary_set_tlm_status_d->);
primary_set_tlm_status_p.set_timestamp(primary_set_tlm_status_d->);
free(primary_set_tlm_status_d);
std::string serialized;
primary_set_tlm_status_p.SerializeToString(&serialized);
return serialized;
}


case {'TLM_STATUS': 258}:
{
PrimaryTlmStatusMsg* primary_tlm_status_d = (PrimaryTlmStatusMsg*)malloc(PRIMARY_TLM_STATUS_SIZE);
deserialize_PrimaryTlmStatus(payload, primary_tlm_status_d);

primary::TlmStatus primary_tlm_status_p;
primary_tlm_status_p.set_tlm_status(primary_tlm_status_d->);
primary_tlm_status_p.set_race_type(primary_tlm_status_d->);
primary_tlm_status_p.set_driver(primary_tlm_status_d->);
primary_tlm_status_p.set_circuit(primary_tlm_status_d->);
primary_tlm_status_p.set_timestamp(primary_tlm_status_d->);
free(primary_tlm_status_d);
std::string serialized;
primary_tlm_status_p.SerializeToString(&serialized);
return serialized;
}


case {'STEER_SYSTEM_STATUS': 1793}:
{
PrimarySteerSystemStatusMsg* primary_steer_system_status_d = (PrimarySteerSystemStatusMsg*)malloc(PRIMARY_STEER_SYSTEM_STATUS_SIZE);
deserialize_PrimarySteerSystemStatus(payload, primary_steer_system_status_d);

primary::SteerSystemStatus primary_steer_system_status_p;
primary_steer_system_status_p.set_soc_temp(primary_steer_system_status_d->);
primary_steer_system_status_p.set_timestamp(primary_steer_system_status_d->);
free(primary_steer_system_status_d);
std::string serialized;
primary_steer_system_status_p.SerializeToString(&serialized);
return serialized;
}


case {'HV_VOLTAGE': 771}:
{
PrimaryHvVoltageMsg* primary_hv_voltage_d = (PrimaryHvVoltageMsg*)malloc(PRIMARY_HV_VOLTAGE_SIZE);
deserialize_PrimaryHvVoltage(payload, primary_hv_voltage_d);

primary::HvVoltage primary_hv_voltage_p;
primary_hv_voltage_p.set_pack_voltage(primary_hv_voltage_d->);
primary_hv_voltage_p.set_bus_voltage(primary_hv_voltage_d->);
primary_hv_voltage_p.set_max_cell_voltage(primary_hv_voltage_d->);
primary_hv_voltage_p.set_min_cell_voltage(primary_hv_voltage_d->);
primary_hv_voltage_p.set_timestamp(primary_hv_voltage_d->);
free(primary_hv_voltage_d);
std::string serialized;
primary_hv_voltage_p.SerializeToString(&serialized);
return serialized;
}


case {'HV_CURRENT': 803}:
{
PrimaryHvCurrentMsg* primary_hv_current_d = (PrimaryHvCurrentMsg*)malloc(PRIMARY_HV_CURRENT_SIZE);
deserialize_PrimaryHvCurrent(payload, primary_hv_current_d);

primary::HvCurrent primary_hv_current_p;
primary_hv_current_p.set_current(primary_hv_current_d->);
primary_hv_current_p.set_power(primary_hv_current_d->);
primary_hv_current_p.set_timestamp(primary_hv_current_d->);
free(primary_hv_current_d);
std::string serialized;
primary_hv_current_p.SerializeToString(&serialized);
return serialized;
}


case {'HV_TEMP': 835}:
{
PrimaryHvTempMsg* primary_hv_temp_d = (PrimaryHvTempMsg*)malloc(PRIMARY_HV_TEMP_SIZE);
deserialize_PrimaryHvTemp(payload, primary_hv_temp_d);

primary::HvTemp primary_hv_temp_p;
primary_hv_temp_p.set_average_temp(primary_hv_temp_d->);
primary_hv_temp_p.set_max_temp(primary_hv_temp_d->);
primary_hv_temp_p.set_min_temp(primary_hv_temp_d->);
primary_hv_temp_p.set_timestamp(primary_hv_temp_d->);
free(primary_hv_temp_d);
std::string serialized;
primary_hv_temp_p.SerializeToString(&serialized);
return serialized;
}


case {'HV_ERRORS': 3}:
{
PrimaryHvErrorsMsg* primary_hv_errors_d = (PrimaryHvErrorsMsg*)malloc(PRIMARY_HV_ERRORS_SIZE);
deserialize_PrimaryHvErrors(payload, primary_hv_errors_d);

primary::HvErrors primary_hv_errors_p;
primary_hv_errors_p.set_warnings(primary_hv_errors_d->);
primary_hv_errors_p.set_errors(primary_hv_errors_d->);
primary_hv_errors_p.set_timestamp(primary_hv_errors_d->);
free(primary_hv_errors_d);
std::string serialized;
primary_hv_errors_p.SerializeToString(&serialized);
return serialized;
}


case {'TS_STATUS': 35}:
{
PrimaryTsStatusMsg* primary_ts_status_d = (PrimaryTsStatusMsg*)malloc(PRIMARY_TS_STATUS_SIZE);
deserialize_PrimaryTsStatus(payload, primary_ts_status_d);

primary::TsStatus primary_ts_status_p;
primary_ts_status_p.set_ts_status(primary_ts_status_d->);
primary_ts_status_p.set_timestamp(primary_ts_status_d->);
free(primary_ts_status_d);
std::string serialized;
primary_ts_status_p.SerializeToString(&serialized);
return serialized;
}


case {'SET_TS_STATUS_DAS': 4, 'SET_TS_STATUS_HANDCART': 36}:
{
PrimarySetTsStatusMsg* primary_set_ts_status_d = (PrimarySetTsStatusMsg*)malloc(PRIMARY_SET_TS_STATUS_SIZE);
deserialize_PrimarySetTsStatus(payload, primary_set_ts_status_d);

primary::SetTsStatus primary_set_ts_status_p;
primary_set_ts_status_p.set_ts_status_set(primary_set_ts_status_d->);
primary_set_ts_status_p.set_timestamp(primary_set_ts_status_d->);
free(primary_set_ts_status_d);
std::string serialized;
primary_set_ts_status_p.SerializeToString(&serialized);
return serialized;
}


case {'STEER_STATUS': 261}:
{
PrimarySteerStatusMsg* primary_steer_status_d = (PrimarySteerStatusMsg*)malloc(PRIMARY_STEER_STATUS_SIZE);
deserialize_PrimarySteerStatus(payload, primary_steer_status_d);

primary::SteerStatus primary_steer_status_p;
primary_steer_status_p.set_traction_control(primary_steer_status_d->);
primary_steer_status_p.set_map(primary_steer_status_d->);
primary_steer_status_p.set_timestamp(primary_steer_status_d->);
free(primary_steer_status_d);
std::string serialized;
primary_steer_status_p.SerializeToString(&serialized);
return serialized;
}


case {'SET_CAR_STATUS': 773}:
{
PrimarySetCarStatusMsg* primary_set_car_status_d = (PrimarySetCarStatusMsg*)malloc(PRIMARY_SET_CAR_STATUS_SIZE);
deserialize_PrimarySetCarStatus(payload, primary_set_car_status_d);

primary::SetCarStatus primary_set_car_status_p;
primary_set_car_status_p.set_car_status_set(primary_set_car_status_d->);
primary_set_car_status_p.set_timestamp(primary_set_car_status_d->);
free(primary_set_car_status_d);
std::string serialized;
primary_set_car_status_p.SerializeToString(&serialized);
return serialized;
}


case {'SET_PEDALS_RANGE': 1029}:
{
PrimarySetPedalsRangeMsg* primary_set_pedals_range_d = (PrimarySetPedalsRangeMsg*)malloc(PRIMARY_SET_PEDALS_RANGE_SIZE);
deserialize_PrimarySetPedalsRange(payload, primary_set_pedals_range_d);

primary::SetPedalsRange primary_set_pedals_range_p;
primary_set_pedals_range_p.set_bound(primary_set_pedals_range_d->);
primary_set_pedals_range_p.set_pedal(primary_set_pedals_range_d->);
primary_set_pedals_range_p.set_timestamp(primary_set_pedals_range_d->);
free(primary_set_pedals_range_d);
std::string serialized;
primary_set_pedals_range_p.SerializeToString(&serialized);
return serialized;
}


case {'CAR_STATUS': 514}:
{
PrimaryCarStatusMsg* primary_car_status_d = (PrimaryCarStatusMsg*)malloc(PRIMARY_CAR_STATUS_SIZE);
deserialize_PrimaryCarStatus(payload, primary_car_status_d);

primary::CarStatus primary_car_status_p;
primary_car_status_p.set_inverter_l(primary_car_status_d->);
primary_car_status_p.set_inverter_r(primary_car_status_d->);
primary_car_status_p.set_car_status(primary_car_status_d->);
primary_car_status_p.set_timestamp(primary_car_status_d->);
free(primary_car_status_d);
std::string serialized;
primary_car_status_p.SerializeToString(&serialized);
return serialized;
}


case {'DAS_ERRORS': 2}:
{
PrimaryDasErrorsMsg* primary_das_errors_d = (PrimaryDasErrorsMsg*)malloc(PRIMARY_DAS_ERRORS_SIZE);
deserialize_PrimaryDasErrors(payload, primary_das_errors_d);

primary::DasErrors primary_das_errors_p;
primary_das_errors_p.set_das_error(primary_das_errors_d->);
primary_das_errors_p.set_timestamp(primary_das_errors_d->);
free(primary_das_errors_d);
std::string serialized;
primary_das_errors_p.SerializeToString(&serialized);
return serialized;
}


case {'LV_CURRENT': 774}:
{
PrimaryLvCurrentMsg* primary_lv_current_d = (PrimaryLvCurrentMsg*)malloc(PRIMARY_LV_CURRENT_SIZE);
deserialize_PrimaryLvCurrent(payload, primary_lv_current_d);

primary::LvCurrent primary_lv_current_p;
primary_lv_current_p.set_current(primary_lv_current_d->);
primary_lv_current_p.set_timestamp(primary_lv_current_d->);
free(primary_lv_current_d);
std::string serialized;
primary_lv_current_p.SerializeToString(&serialized);
return serialized;
}


case {'LV_VOLTAGE': 806}:
{
PrimaryLvVoltageMsg* primary_lv_voltage_d = (PrimaryLvVoltageMsg*)malloc(PRIMARY_LV_VOLTAGE_SIZE);
deserialize_PrimaryLvVoltage(payload, primary_lv_voltage_d);

primary::LvVoltage primary_lv_voltage_p;
primary_lv_voltage_p.set_voltage_1(primary_lv_voltage_d->);
primary_lv_voltage_p.set_voltage_2(primary_lv_voltage_d->);
primary_lv_voltage_p.set_voltage_3(primary_lv_voltage_d->);
primary_lv_voltage_p.set_voltage_4(primary_lv_voltage_d->);
primary_lv_voltage_p.set_timestamp(primary_lv_voltage_d->);
free(primary_lv_voltage_d);
std::string serialized;
primary_lv_voltage_p.SerializeToString(&serialized);
return serialized;
}


case {'LV_TOTAL_VOLTAGE': 838}:
{
PrimaryLvTotalVoltageMsg* primary_lv_total_voltage_d = (PrimaryLvTotalVoltageMsg*)malloc(PRIMARY_LV_TOTAL_VOLTAGE_SIZE);
deserialize_PrimaryLvTotalVoltage(payload, primary_lv_total_voltage_d);

primary::LvTotalVoltage primary_lv_total_voltage_p;
primary_lv_total_voltage_p.set_total_voltage(primary_lv_total_voltage_d->);
primary_lv_total_voltage_p.set_timestamp(primary_lv_total_voltage_d->);
free(primary_lv_total_voltage_d);
std::string serialized;
primary_lv_total_voltage_p.SerializeToString(&serialized);
return serialized;
}


case {'LV_TEMPERATURE': 870}:
{
PrimaryLvTemperatureMsg* primary_lv_temperature_d = (PrimaryLvTemperatureMsg*)malloc(PRIMARY_LV_TEMPERATURE_SIZE);
deserialize_PrimaryLvTemperature(payload, primary_lv_temperature_d);

primary::LvTemperature primary_lv_temperature_p;
primary_lv_temperature_p.set_bp_temperature(primary_lv_temperature_d->);
primary_lv_temperature_p.set_dcdc_temperature(primary_lv_temperature_d->);
primary_lv_temperature_p.set_timestamp(primary_lv_temperature_d->);
free(primary_lv_temperature_d);
std::string serialized;
primary_lv_temperature_p.SerializeToString(&serialized);
return serialized;
}


case {'COOLING_STATUS': 902}:
{
PrimaryCoolingStatusMsg* primary_cooling_status_d = (PrimaryCoolingStatusMsg*)malloc(PRIMARY_COOLING_STATUS_SIZE);
deserialize_PrimaryCoolingStatus(payload, primary_cooling_status_d);

primary::CoolingStatus primary_cooling_status_p;
primary_cooling_status_p.set_hv_fan_speed(primary_cooling_status_d->);
primary_cooling_status_p.set_lv_fan_speed(primary_cooling_status_d->);
primary_cooling_status_p.set_pump_speed(primary_cooling_status_d->);
primary_cooling_status_p.set_timestamp(primary_cooling_status_d->);
free(primary_cooling_status_d);
std::string serialized;
primary_cooling_status_p.SerializeToString(&serialized);
return serialized;
}


case {'MARKER': 1}:
{
PrimaryMarkerMsg* primary_marker_d = (PrimaryMarkerMsg*)malloc(PRIMARY_MARKER_SIZE);
deserialize_PrimaryMarker(payload, primary_marker_d);

primary::Marker primary_marker_p;
primary_marker_p.set_timestamp(primary_marker_d->);
free(primary_marker_d);
std::string serialized;
primary_marker_p.SerializeToString(&serialized);
return serialized;
}


case {'HV_CELLS_VOLTAGE': 519}:
{
PrimaryHvCellsVoltageMsg* primary_hv_cells_voltage_d = (PrimaryHvCellsVoltageMsg*)malloc(PRIMARY_HV_CELLS_VOLTAGE_SIZE);
deserialize_PrimaryHvCellsVoltage(payload, primary_hv_cells_voltage_d);

primary::HvCellsVoltage primary_hv_cells_voltage_p;
primary_hv_cells_voltage_p.set_cell_index(primary_hv_cells_voltage_d->);
primary_hv_cells_voltage_p.set_voltage_0(primary_hv_cells_voltage_d->);
primary_hv_cells_voltage_p.set_voltage_1(primary_hv_cells_voltage_d->);
primary_hv_cells_voltage_p.set_voltage_2(primary_hv_cells_voltage_d->);
primary_hv_cells_voltage_p.set_timestamp(primary_hv_cells_voltage_d->);
free(primary_hv_cells_voltage_d);
std::string serialized;
primary_hv_cells_voltage_p.SerializeToString(&serialized);
return serialized;
}


case {'HV_CELLS_TEMP': 551}:
{
PrimaryHvCellsTempMsg* primary_hv_cells_temp_d = (PrimaryHvCellsTempMsg*)malloc(PRIMARY_HV_CELLS_TEMP_SIZE);
deserialize_PrimaryHvCellsTemp(payload, primary_hv_cells_temp_d);

primary::HvCellsTemp primary_hv_cells_temp_p;
primary_hv_cells_temp_p.set_cell_index(primary_hv_cells_temp_d->);
primary_hv_cells_temp_p.set_temp_0(primary_hv_cells_temp_d->);
primary_hv_cells_temp_p.set_temp_1(primary_hv_cells_temp_d->);
primary_hv_cells_temp_p.set_temp_2(primary_hv_cells_temp_d->);
primary_hv_cells_temp_p.set_temp_3(primary_hv_cells_temp_d->);
primary_hv_cells_temp_p.set_temp_4(primary_hv_cells_temp_d->);
primary_hv_cells_temp_p.set_temp_5(primary_hv_cells_temp_d->);
primary_hv_cells_temp_p.set_temp_6(primary_hv_cells_temp_d->);
primary_hv_cells_temp_p.set_timestamp(primary_hv_cells_temp_d->);
free(primary_hv_cells_temp_d);
std::string serialized;
primary_hv_cells_temp_p.SerializeToString(&serialized);
return serialized;
}


case {'HV_CELL_BALANCING_STATUS': 583}:
{
PrimaryHvCellBalancingStatusMsg* primary_hv_cell_balancing_status_d = (PrimaryHvCellBalancingStatusMsg*)malloc(PRIMARY_HV_CELL_BALANCING_STATUS_SIZE);
deserialize_PrimaryHvCellBalancingStatus(payload, primary_hv_cell_balancing_status_d);

primary::HvCellBalancingStatus primary_hv_cell_balancing_status_p;
primary_hv_cell_balancing_status_p.set_balancing_status(primary_hv_cell_balancing_status_d->);
primary_hv_cell_balancing_status_p.set_timestamp(primary_hv_cell_balancing_status_d->);
free(primary_hv_cell_balancing_status_d);
std::string serialized;
primary_hv_cell_balancing_status_p.SerializeToString(&serialized);
return serialized;
}


case {'SET_CELL_BALANCING_STATUS': 516}:
{
PrimarySetCellBalancingStatusMsg* primary_set_cell_balancing_status_d = (PrimarySetCellBalancingStatusMsg*)malloc(PRIMARY_SET_CELL_BALANCING_STATUS_SIZE);
deserialize_PrimarySetCellBalancingStatus(payload, primary_set_cell_balancing_status_d);

primary::SetCellBalancingStatus primary_set_cell_balancing_status_p;
primary_set_cell_balancing_status_p.set_set_balancing_status(primary_set_cell_balancing_status_d->);
primary_set_cell_balancing_status_p.set_timestamp(primary_set_cell_balancing_status_d->);
free(primary_set_cell_balancing_status_d);
std::string serialized;
primary_set_cell_balancing_status_p.SerializeToString(&serialized);
return serialized;
}


case {'HANDCART_STATUS': 772}:
{
PrimaryHandcartStatusMsg* primary_handcart_status_d = (PrimaryHandcartStatusMsg*)malloc(PRIMARY_HANDCART_STATUS_SIZE);
deserialize_PrimaryHandcartStatus(payload, primary_handcart_status_d);

primary::HandcartStatus primary_handcart_status_p;
primary_handcart_status_p.set_connected(primary_handcart_status_d->);
primary_handcart_status_p.set_timestamp(primary_handcart_status_d->);
free(primary_handcart_status_d);
std::string serialized;
primary_handcart_status_p.SerializeToString(&serialized);
return serialized;
}


case {'SPEED': 546}:
{
PrimarySpeedMsg* primary_speed_d = (PrimarySpeedMsg*)malloc(PRIMARY_SPEED_SIZE);
deserialize_PrimarySpeed(payload, primary_speed_d);

primary::Speed primary_speed_p;
primary_speed_p.set_encoder_r(primary_speed_d->);
primary_speed_p.set_encoder_l(primary_speed_d->);
primary_speed_p.set_inverter_r(primary_speed_d->);
primary_speed_p.set_inverter_l(primary_speed_d->);
primary_speed_p.set_timestamp(primary_speed_d->);
free(primary_speed_d);
std::string serialized;
primary_speed_p.SerializeToString(&serialized);
return serialized;
}


case {'INV_L_SET_TORQUE': 513}:
{
PrimaryInvLSetTorqueMsg* primary_inv_l_set_torque_d = (PrimaryInvLSetTorqueMsg*)malloc(PRIMARY_INV_L_SET_TORQUE_SIZE);
deserialize_PrimaryInvLSetTorque(payload, primary_inv_l_set_torque_d);

primary::InvLSetTorque primary_inv_l_set_torque_p;
primary_inv_l_set_torque_p.set_reg_id(primary_inv_l_set_torque_d->);
primary_inv_l_set_torque_p.set_lsb(primary_inv_l_set_torque_d->);
primary_inv_l_set_torque_p.set_msb(primary_inv_l_set_torque_d->);
primary_inv_l_set_torque_p.set_timestamp(primary_inv_l_set_torque_d->);
free(primary_inv_l_set_torque_d);
std::string serialized;
primary_inv_l_set_torque_p.SerializeToString(&serialized);
return serialized;
}


case {'INV_L_RESPONSE': 385}:
{
PrimaryInvLResponseMsg* primary_inv_l_response_d = (PrimaryInvLResponseMsg*)malloc(PRIMARY_INV_L_RESPONSE_SIZE);
deserialize_PrimaryInvLResponse(payload, primary_inv_l_response_d);

primary::InvLResponse primary_inv_l_response_p;
primary_inv_l_response_p.set_reg_id(primary_inv_l_response_d->);
primary_inv_l_response_p.set_data_0(primary_inv_l_response_d->);
primary_inv_l_response_p.set_data_1(primary_inv_l_response_d->);
primary_inv_l_response_p.set_data_2(primary_inv_l_response_d->);
primary_inv_l_response_p.set_data_3(primary_inv_l_response_d->);
primary_inv_l_response_p.set_data_4(primary_inv_l_response_d->);
primary_inv_l_response_p.set_data_5(primary_inv_l_response_d->);
primary_inv_l_response_p.set_data_6(primary_inv_l_response_d->);
primary_inv_l_response_p.set_timestamp(primary_inv_l_response_d->);
free(primary_inv_l_response_d);
std::string serialized;
primary_inv_l_response_p.SerializeToString(&serialized);
return serialized;
}

}
throw std::runtime_error("Unknown message id");
}