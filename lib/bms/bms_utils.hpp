#ifndef bms_UTILS_HPP
#define bms_UTILS_HPP

#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <vector>
#include <string>
#include "bms_network.h"

/* START */
#define BOARD_STATUS "BOARD_STATUS"

#define BOARD_STATUS_CELLBOARD_ID "board_status_cellboard_id"
#define BOARD_STATUS_ERRORS_CAN_COMM "board_status_errors_can_comm"
#define BOARD_STATUS_ERRORS_LTC_COMM "board_status_errors_ltc_comm"
#define BOARD_STATUS_ERRORS_TEMP_COMM_0 "board_status_errors_temp_comm_0"
#define BOARD_STATUS_ERRORS_TEMP_COMM_1 "board_status_errors_temp_comm_1"
#define BOARD_STATUS_ERRORS_TEMP_COMM_2 "board_status_errors_temp_comm_2"
#define BOARD_STATUS_ERRORS_TEMP_COMM_3 "board_status_errors_temp_comm_3"
#define BOARD_STATUS_ERRORS_TEMP_COMM_4 "board_status_errors_temp_comm_4"
#define BOARD_STATUS_ERRORS_TEMP_COMM_5 "board_status_errors_temp_comm_5"
#define BOARD_STATUS_ERRORS_OPEN_WIRE "board_status_errors_open_wire"
#define BOARD_STATUS_BALANCING_STATUS "board_status_balancing_status"
#define BOARD_STATUS_BALANCING_CELLS_CELL0 "board_status_balancing_cells_cell0"
#define BOARD_STATUS_BALANCING_CELLS_CELL1 "board_status_balancing_cells_cell1"
#define BOARD_STATUS_BALANCING_CELLS_CELL2 "board_status_balancing_cells_cell2"
#define BOARD_STATUS_BALANCING_CELLS_CELL3 "board_status_balancing_cells_cell3"
#define BOARD_STATUS_BALANCING_CELLS_CELL4 "board_status_balancing_cells_cell4"
#define BOARD_STATUS_BALANCING_CELLS_CELL5 "board_status_balancing_cells_cell5"
#define BOARD_STATUS_BALANCING_CELLS_CELL6 "board_status_balancing_cells_cell6"
#define BOARD_STATUS_BALANCING_CELLS_CELL7 "board_status_balancing_cells_cell7"
#define BOARD_STATUS_BALANCING_CELLS_CELL8 "board_status_balancing_cells_cell8"
#define BOARD_STATUS_BALANCING_CELLS_CELL9 "board_status_balancing_cells_cell9"
#define BOARD_STATUS_BALANCING_CELLS_CELL10 "board_status_balancing_cells_cell10"
#define BOARD_STATUS_BALANCING_CELLS_CELL11 "board_status_balancing_cells_cell11"
#define BOARD_STATUS_BALANCING_CELLS_CELL12 "board_status_balancing_cells_cell12"
#define BOARD_STATUS_BALANCING_CELLS_CELL13 "board_status_balancing_cells_cell13"
#define BOARD_STATUS_BALANCING_CELLS_CELL14 "board_status_balancing_cells_cell14"
#define BOARD_STATUS_BALANCING_CELLS_CELL15 "board_status_balancing_cells_cell15"
#define BOARD_STATUS_BALANCING_CELLS_CELL16 "board_status_balancing_cells_cell16"
#define BOARD_STATUS_BALANCING_CELLS_CELL17 "board_status_balancing_cells_cell17"
/* END */

/* START */
#define TEMPERATURES_INFO "TEMPERATURES_INFO"

#define TEMPERATURES_INFO_CELLBOARD_ID "temperatures_info_cellboard_id"
#define TEMPERATURES_INFO_MIN_TEMP "temperatures_info_min_temp"
#define TEMPERATURES_INFO_MAX_TEMP "temperatures_info_max_temp"
#define TEMPERATURES_INFO_AVG_TEMP "temperatures_info_avg_temp"
/* END */

/* START */
#define TEMPERATURES "TEMPERATURES"

#define TEMPERATURES_CELLBOARD_ID "temperatures_cellboard_id"
#define TEMPERATURES_START_INDEX "temperatures_start_index"
#define TEMPERATURES_TEMP0 "temperatures_temp0"
#define TEMPERATURES_TEMP1 "temperatures_temp1"
#define TEMPERATURES_TEMP2 "temperatures_temp2"
#define TEMPERATURES_TEMP3 "temperatures_temp3"
/* END */

/* START */
#define VOLTAGES_INFO "VOLTAGES_INFO"

#define VOLTAGES_INFO_CELLBOARD_ID "voltages_info_cellboard_id"
#define VOLTAGES_INFO_MIN_VOLTAGE "voltages_info_min_voltage"
#define VOLTAGES_INFO_MAX_VOLTAGE "voltages_info_max_voltage"
#define VOLTAGES_INFO_AVG_VOLTAGE "voltages_info_avg_voltage"
/* END */

/* START */
#define VOLTAGES "VOLTAGES"

#define VOLTAGES_CELLBOARD_ID "voltages_cellboard_id"
#define VOLTAGES_START_INDEX "voltages_start_index"
#define VOLTAGES_VOLTAGE0 "voltages_voltage0"
#define VOLTAGES_VOLTAGE1 "voltages_voltage1"
#define VOLTAGES_VOLTAGE2 "voltages_voltage2"
/* END */

/* START */
#define SET_BALANCING_STATUS "SET_BALANCING_STATUS"

#define SET_BALANCING_STATUS_THRESHOLD "set_balancing_status_threshold"
#define SET_BALANCING_STATUS_TARGET "set_balancing_status_target"
#define SET_BALANCING_STATUS_BALANCING_STATUS "set_balancing_status_balancing_status"
/* END */

/* START */
#define FLASH_CELLBOARD_0_RX "FLASH_CELLBOARD_0_RX"

/* END */

/* START */
#define FLASH_CELLBOARD_1_TX "FLASH_CELLBOARD_1_TX"

/* END */

/* START */
#define FLASH_CELLBOARD_1_RX "FLASH_CELLBOARD_1_RX"

/* END */

/* START */
#define FLASH_CELLBOARD_2_TX "FLASH_CELLBOARD_2_TX"

/* END */

/* START */
#define FLASH_CELLBOARD_2_RX "FLASH_CELLBOARD_2_RX"

/* END */

/* START */
#define FLASH_CELLBOARD_3_TX "FLASH_CELLBOARD_3_TX"

/* END */

/* START */
#define FLASH_CELLBOARD_3_RX "FLASH_CELLBOARD_3_RX"

/* END */

/* START */
#define FLASH_CELLBOARD_4_TX "FLASH_CELLBOARD_4_TX"

/* END */

/* START */
#define FLASH_CELLBOARD_4_RX "FLASH_CELLBOARD_4_RX"

/* END */

/* START */
#define FLASH_CELLBOARD_5_TX "FLASH_CELLBOARD_5_TX"

/* END */

/* START */
#define FLASH_CELLBOARD_5_RX "FLASH_CELLBOARD_5_RX"

/* END */

/* START */
#define CELLBOARD_FLASH "CELLBOARD_FLASH"

#define CELLBOARD_FLASH_START "cellboard_flash_start"
#define CELLBOARD_FLASH_CELLBOARD_ID "cellboard_flash_cellboard_id"
#define CELLBOARD_FLASH_BOARD_INDEX "cellboard_flash_board_index"
/* END */

/* START */
#define CELLBOARD_FLASH_TX "CELLBOARD_FLASH_TX"

/* END */

/* START */
#define CELLBOARD_FLASH_RX "CELLBOARD_FLASH_RX"

/* END */

/* START */
#define CELLBOARD_FLASH_REQUEST "CELLBOARD_FLASH_REQUEST"

#define CELLBOARD_FLASH_REQUEST_MAINBOARD "cellboard_flash_request_mainboard"
#define CELLBOARD_FLASH_REQUEST_CELLBOARD_ID "cellboard_flash_request_cellboard_id"
/* END */

/* START */
#define CELLBOARD_FLASH_RESPONSE "CELLBOARD_FLASH_RESPONSE"

#define CELLBOARD_FLASH_RESPONSE_CELLBOARD_ID "cellboard_flash_response_cellboard_id"
#define CELLBOARD_FLASH_RESPONSE_READY "cellboard_flash_response_ready"
/* END */

/* START */
#define CELLBOARD_DISCOVERY "CELLBOARD_DISCOVERY"

#define CELLBOARD_DISCOVERY_CELLBOARD_ID "cellboard_discovery_cellboard_id"
/* END */

/* START */
#define CELLBOARD_VERSION "CELLBOARD_VERSION"

#define CELLBOARD_VERSION_CELLBOARD_ID "cellboard_version_cellboard_id"
#define CELLBOARD_VERSION_CANLIB_BUILD_TIME "cellboard_version_canlib_build_time"
#define CELLBOARD_VERSION_COMPONENT_BUILD_TIME "cellboard_version_component_build_time"
/* END */

/* START */
#define CELLBOARD_STATUS "CELLBOARD_STATUS"

#define CELLBOARD_STATUS_CELLBOARD_ID "cellboard_status_cellboard_id"
#define CELLBOARD_STATUS_STATUS "cellboard_status_status"
/* END */

/* START */
#define CELLBOARD_CELLS_VOLTAGE "CELLBOARD_CELLS_VOLTAGE"

#define CELLBOARD_CELLS_VOLTAGE_CELLBOARD_ID "cellboard_cells_voltage_cellboard_id"
#define CELLBOARD_CELLS_VOLTAGE_OFFSET "cellboard_cells_voltage_offset"
#define CELLBOARD_CELLS_VOLTAGE_VOLTAGE_0 "cellboard_cells_voltage_voltage_0"
#define CELLBOARD_CELLS_VOLTAGE_VOLTAGE_1 "cellboard_cells_voltage_voltage_1"
#define CELLBOARD_CELLS_VOLTAGE_VOLTAGE_2 "cellboard_cells_voltage_voltage_2"
/* END */

/* START */
#define CELLBOARD_CELLS_TEMPERATURE "CELLBOARD_CELLS_TEMPERATURE"

#define CELLBOARD_CELLS_TEMPERATURE_CELLBOARD_ID "cellboard_cells_temperature_cellboard_id"
#define CELLBOARD_CELLS_TEMPERATURE_OFFSET "cellboard_cells_temperature_offset"
#define CELLBOARD_CELLS_TEMPERATURE_TEMPERATURE_0 "cellboard_cells_temperature_temperature_0"
#define CELLBOARD_CELLS_TEMPERATURE_TEMPERATURE_1 "cellboard_cells_temperature_temperature_1"
#define CELLBOARD_CELLS_TEMPERATURE_TEMPERATURE_2 "cellboard_cells_temperature_temperature_2"
#define CELLBOARD_CELLS_TEMPERATURE_TEMPERATURE_3 "cellboard_cells_temperature_temperature_3"
/* END */

/* START */
#define CELLBOARD_DISCHARGE_TEMPERATURE "CELLBOARD_DISCHARGE_TEMPERATURE"

#define CELLBOARD_DISCHARGE_TEMPERATURE_CELLBOARD_ID "cellboard_discharge_temperature_cellboard_id"
#define CELLBOARD_DISCHARGE_TEMPERATURE_TEMPERATURE_0 "cellboard_discharge_temperature_temperature_0"
#define CELLBOARD_DISCHARGE_TEMPERATURE_TEMPERATURE_1 "cellboard_discharge_temperature_temperature_1"
#define CELLBOARD_DISCHARGE_TEMPERATURE_TEMPERATURE_2 "cellboard_discharge_temperature_temperature_2"
#define CELLBOARD_DISCHARGE_TEMPERATURE_TEMPERATURE_3 "cellboard_discharge_temperature_temperature_3"
#define CELLBOARD_DISCHARGE_TEMPERATURE_TEMPERATURE_4 "cellboard_discharge_temperature_temperature_4"
/* END */

/* START */
#define CELLBOARD_SET_BALANCING_STATUS "CELLBOARD_SET_BALANCING_STATUS"

#define CELLBOARD_SET_BALANCING_STATUS_START "cellboard_set_balancing_status_start"
#define CELLBOARD_SET_BALANCING_STATUS_TARGET "cellboard_set_balancing_status_target"
#define CELLBOARD_SET_BALANCING_STATUS_THRESHOLD "cellboard_set_balancing_status_threshold"
/* END */

/* START */
#define CELLBOARD_BALANCING_STATUS "CELLBOARD_BALANCING_STATUS"

#define CELLBOARD_BALANCING_STATUS_STATUS "cellboard_balancing_status_status"
#define CELLBOARD_BALANCING_STATUS_CELLBOARD_ID "cellboard_balancing_status_cellboard_id"
#define CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_0 "cellboard_balancing_status_discharging_cell_0"
#define CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_1 "cellboard_balancing_status_discharging_cell_1"
#define CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_2 "cellboard_balancing_status_discharging_cell_2"
#define CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_3 "cellboard_balancing_status_discharging_cell_3"
#define CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_4 "cellboard_balancing_status_discharging_cell_4"
#define CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_5 "cellboard_balancing_status_discharging_cell_5"
#define CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_6 "cellboard_balancing_status_discharging_cell_6"
#define CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_7 "cellboard_balancing_status_discharging_cell_7"
#define CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_8 "cellboard_balancing_status_discharging_cell_8"
#define CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_9 "cellboard_balancing_status_discharging_cell_9"
#define CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_10 "cellboard_balancing_status_discharging_cell_10"
#define CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_11 "cellboard_balancing_status_discharging_cell_11"
#define CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_12 "cellboard_balancing_status_discharging_cell_12"
#define CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_13 "cellboard_balancing_status_discharging_cell_13"
#define CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_14 "cellboard_balancing_status_discharging_cell_14"
#define CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_15 "cellboard_balancing_status_discharging_cell_15"
#define CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_16 "cellboard_balancing_status_discharging_cell_16"
#define CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_17 "cellboard_balancing_status_discharging_cell_17"
#define CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_18 "cellboard_balancing_status_discharging_cell_18"
#define CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_19 "cellboard_balancing_status_discharging_cell_19"
#define CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_20 "cellboard_balancing_status_discharging_cell_20"
#define CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_21 "cellboard_balancing_status_discharging_cell_21"
#define CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_22 "cellboard_balancing_status_discharging_cell_22"
#define CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_23 "cellboard_balancing_status_discharging_cell_23"
/* END */

/* START */
#define CELLBOARD_ERROR "CELLBOARD_ERROR"

#define CELLBOARD_ERROR_CELLBOARD_ID "cellboard_error_cellboard_id"
#define CELLBOARD_ERROR_GROUP "cellboard_error_group"
#define CELLBOARD_ERROR_INSTANCE "cellboard_error_instance"
/* END */

enum bms_types_id{
	e_bms_uint8_t = -4,
	e_bms_float,
	e_bms_uint32_t,
	e_bms_uint16_t,

	e_bms_board_status_cellboard_id,
	e_bms_board_status_balancing_status,
	e_bms_temperatures_info_cellboard_id,
	e_bms_temperatures_cellboard_id,
	e_bms_voltages_info_cellboard_id,
	e_bms_voltages_cellboard_id,
	e_bms_set_balancing_status_balancing_status,
	e_bms_cellboard_flash_cellboard_id,
	e_bms_cellboard_flash_request_cellboard_id,
	e_bms_cellboard_flash_response_cellboard_id,
	e_bms_cellboard_discovery_cellboard_id,
	e_bms_cellboard_version_cellboard_id,
	e_bms_cellboard_status_cellboard_id,
	e_bms_cellboard_status_status,
	e_bms_cellboard_cells_voltage_cellboard_id,
	e_bms_cellboard_cells_temperature_cellboard_id,
	e_bms_cellboard_discharge_temperature_cellboard_id,
	e_bms_cellboard_balancing_status_status,
	e_bms_cellboard_balancing_status_cellboard_id,
	e_bms_cellboard_error_cellboard_id,
	e_bms_cellboard_error_group
};

/**
 * @brief get the name of the signals in the message
 * 
 * @param[in] id message id
 * @param[out] v array of strings containing the name of the signals
 * @param[in] fields_size maximum size of v
 * @param[in] string_size maximum size of v[i]
 * 
 * @return 0 if ok 1 otherwise
*/
int bms_fields_string_from_id(int id, char **v, size_t fields_size, size_t string_size);

/**
 * @brief get the fields of an enum given the id of the enum (get the id from fields_types_from_id)
 * 
 * @param[in] enum_id the id of the enum, you can get it from fields_types_from_id
 * @param[out] v array of strings containing the enum fields
 * @param[in] fields_size maximum size of v
 * @param[in] string_size maximum size of v[i]
 * 
 * @return 0 if ok 1 otherwise
*/
int bms_enum_fields(int enum_id, char **v, size_t fields_size, size_t string_size);

/**
 * @brief serialize to a data pointer from a message id
 * 
 * @param[in] id message id
 * @param[in] s string containing the data to serialize (comma separated)
 * @param[out] data pointer to the serialized data
 * @param[out] size size of the message
 * 
 * @return Size of packed data, or negative error code.
*/
int bms_serialize_from_id(int id, char *s, uint8_t *data, size_t *size);

/**
 * @brief get the number of signals in the message
 * 
 * @param[in] id the id of the message
 * 
 * @return return the number of the signals
*/
int bms_n_fields_from_id(int id);

/**
 * @brief get the types of the signals in the message
 * 
 * @param[in] id the id of the message
 * @param[out] fields_types fields_types[i] contains the type id of the signal i (must be already allocated)
 * @param[in] fields_types_size max size of fields_types
 * 
 * @return the number of types set, 0 if the id is invalid or fields_types_size is too small
*/
int bms_fields_types_from_id(int id, int *fields_types, int fields_types_size);

/**
 * @brief get the fields of a message that are enums
 * 
 * @param[in] msg_name name of the message to find
 * @param[in] sgn_name name of the signal to find
 * 
 * @return fields' strings vector
*/
std::vector<std::string> bms_enum_fields_from_message(const std::string& msg_name);

/**
 * @brief get the fields of an enum given the name of the message and the name of the signal
 * 
 * @param[in] msg_name name of the message to find
 * @param[in] sgn_name name of the signal to find
 * 
 * @return fields' strings vector
*/
std::vector<std::string> bms_enum_names_from_fields(const std::string& msg_name, const std::string& sgn_name);


#endif
