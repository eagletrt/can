#ifndef BMS_UTILS_C_H

#define BMS_UTILS_C_H

#include <cstddef>
#include "bms_network.h"

/* START */
#define bms_board_status_string "BMS_BOARD_STATUS"

#define bms_board_status_cellboard_id_string "BMS_BOARD_STATUS_CELLBOARD_ID"
#define bms_board_status_errors_can_comm_string "BMS_BOARD_STATUS_ERRORS_CAN_COMM"
#define bms_board_status_errors_ltc_comm_string "BMS_BOARD_STATUS_ERRORS_LTC_COMM"
#define bms_board_status_errors_temp_comm_0_string "BMS_BOARD_STATUS_ERRORS_TEMP_COMM_0"
#define bms_board_status_errors_temp_comm_1_string "BMS_BOARD_STATUS_ERRORS_TEMP_COMM_1"
#define bms_board_status_errors_temp_comm_2_string "BMS_BOARD_STATUS_ERRORS_TEMP_COMM_2"
#define bms_board_status_errors_temp_comm_3_string "BMS_BOARD_STATUS_ERRORS_TEMP_COMM_3"
#define bms_board_status_errors_temp_comm_4_string "BMS_BOARD_STATUS_ERRORS_TEMP_COMM_4"
#define bms_board_status_errors_temp_comm_5_string "BMS_BOARD_STATUS_ERRORS_TEMP_COMM_5"
#define bms_board_status_errors_open_wire_string "BMS_BOARD_STATUS_ERRORS_OPEN_WIRE"
#define bms_board_status_balancing_status_string "BMS_BOARD_STATUS_BALANCING_STATUS"
#define bms_board_status_balancing_cells_cell0_string "BMS_BOARD_STATUS_BALANCING_CELLS_CELL0"
#define bms_board_status_balancing_cells_cell1_string "BMS_BOARD_STATUS_BALANCING_CELLS_CELL1"
#define bms_board_status_balancing_cells_cell2_string "BMS_BOARD_STATUS_BALANCING_CELLS_CELL2"
#define bms_board_status_balancing_cells_cell3_string "BMS_BOARD_STATUS_BALANCING_CELLS_CELL3"
#define bms_board_status_balancing_cells_cell4_string "BMS_BOARD_STATUS_BALANCING_CELLS_CELL4"
#define bms_board_status_balancing_cells_cell5_string "BMS_BOARD_STATUS_BALANCING_CELLS_CELL5"
#define bms_board_status_balancing_cells_cell6_string "BMS_BOARD_STATUS_BALANCING_CELLS_CELL6"
#define bms_board_status_balancing_cells_cell7_string "BMS_BOARD_STATUS_BALANCING_CELLS_CELL7"
#define bms_board_status_balancing_cells_cell8_string "BMS_BOARD_STATUS_BALANCING_CELLS_CELL8"
#define bms_board_status_balancing_cells_cell9_string "BMS_BOARD_STATUS_BALANCING_CELLS_CELL9"
#define bms_board_status_balancing_cells_cell10_string "BMS_BOARD_STATUS_BALANCING_CELLS_CELL10"
#define bms_board_status_balancing_cells_cell11_string "BMS_BOARD_STATUS_BALANCING_CELLS_CELL11"
#define bms_board_status_balancing_cells_cell12_string "BMS_BOARD_STATUS_BALANCING_CELLS_CELL12"
#define bms_board_status_balancing_cells_cell13_string "BMS_BOARD_STATUS_BALANCING_CELLS_CELL13"
#define bms_board_status_balancing_cells_cell14_string "BMS_BOARD_STATUS_BALANCING_CELLS_CELL14"
#define bms_board_status_balancing_cells_cell15_string "BMS_BOARD_STATUS_BALANCING_CELLS_CELL15"
#define bms_board_status_balancing_cells_cell16_string "BMS_BOARD_STATUS_BALANCING_CELLS_CELL16"
#define bms_board_status_balancing_cells_cell17_string "BMS_BOARD_STATUS_BALANCING_CELLS_CELL17"
/* END */

/* START */
#define bms_temperatures_info_string "BMS_TEMPERATURES_INFO"

#define bms_temperatures_info_cellboard_id_string "BMS_TEMPERATURES_INFO_CELLBOARD_ID"
#define bms_temperatures_info_min_temp_string "BMS_TEMPERATURES_INFO_MIN_TEMP"
#define bms_temperatures_info_max_temp_string "BMS_TEMPERATURES_INFO_MAX_TEMP"
#define bms_temperatures_info_avg_temp_string "BMS_TEMPERATURES_INFO_AVG_TEMP"
/* END */

/* START */
#define bms_temperatures_string "BMS_TEMPERATURES"

#define bms_temperatures_cellboard_id_string "BMS_TEMPERATURES_CELLBOARD_ID"
#define bms_temperatures_start_index_string "BMS_TEMPERATURES_START_INDEX"
#define bms_temperatures_temp0_string "BMS_TEMPERATURES_TEMP0"
#define bms_temperatures_temp1_string "BMS_TEMPERATURES_TEMP1"
#define bms_temperatures_temp2_string "BMS_TEMPERATURES_TEMP2"
#define bms_temperatures_temp3_string "BMS_TEMPERATURES_TEMP3"
/* END */

/* START */
#define bms_voltages_info_string "BMS_VOLTAGES_INFO"

#define bms_voltages_info_cellboard_id_string "BMS_VOLTAGES_INFO_CELLBOARD_ID"
#define bms_voltages_info_min_voltage_string "BMS_VOLTAGES_INFO_MIN_VOLTAGE"
#define bms_voltages_info_max_voltage_string "BMS_VOLTAGES_INFO_MAX_VOLTAGE"
#define bms_voltages_info_avg_voltage_string "BMS_VOLTAGES_INFO_AVG_VOLTAGE"
/* END */

/* START */
#define bms_voltages_string "BMS_VOLTAGES"

#define bms_voltages_cellboard_id_string "BMS_VOLTAGES_CELLBOARD_ID"
#define bms_voltages_start_index_string "BMS_VOLTAGES_START_INDEX"
#define bms_voltages_voltage0_string "BMS_VOLTAGES_VOLTAGE0"
#define bms_voltages_voltage1_string "BMS_VOLTAGES_VOLTAGE1"
#define bms_voltages_voltage2_string "BMS_VOLTAGES_VOLTAGE2"
/* END */

/* START */
#define bms_set_balancing_status_string "BMS_SET_BALANCING_STATUS"

#define bms_set_balancing_status_threshold_string "BMS_SET_BALANCING_STATUS_THRESHOLD"
#define bms_set_balancing_status_target_string "BMS_SET_BALANCING_STATUS_TARGET"
#define bms_set_balancing_status_balancing_status_string "BMS_SET_BALANCING_STATUS_BALANCING_STATUS"
/* END */

/* START */
#define bms_jmp_to_blt_string "BMS_JMP_TO_BLT"

#define bms_jmp_to_blt_cellboard_id_string "BMS_JMP_TO_BLT_CELLBOARD_ID"
#define bms_jmp_to_blt_board_index_string "BMS_JMP_TO_BLT_BOARD_INDEX"
/* END */

/* START */
#define bms_flash_cellboard_0_tx_string "BMS_FLASH_CELLBOARD_0_TX"

/* END */

/* START */
#define bms_flash_cellboard_0_rx_string "BMS_FLASH_CELLBOARD_0_RX"

/* END */

/* START */
#define bms_flash_cellboard_1_tx_string "BMS_FLASH_CELLBOARD_1_TX"

/* END */

/* START */
#define bms_flash_cellboard_1_rx_string "BMS_FLASH_CELLBOARD_1_RX"

/* END */

/* START */
#define bms_flash_cellboard_2_tx_string "BMS_FLASH_CELLBOARD_2_TX"

/* END */

/* START */
#define bms_flash_cellboard_2_rx_string "BMS_FLASH_CELLBOARD_2_RX"

/* END */

/* START */
#define bms_flash_cellboard_3_tx_string "BMS_FLASH_CELLBOARD_3_TX"

/* END */

/* START */
#define bms_flash_cellboard_3_rx_string "BMS_FLASH_CELLBOARD_3_RX"

/* END */

/* START */
#define bms_flash_cellboard_4_tx_string "BMS_FLASH_CELLBOARD_4_TX"

/* END */

/* START */
#define bms_flash_cellboard_4_rx_string "BMS_FLASH_CELLBOARD_4_RX"

/* END */

/* START */
#define bms_flash_cellboard_5_tx_string "BMS_FLASH_CELLBOARD_5_TX"

/* END */

/* START */
#define bms_flash_cellboard_5_rx_string "BMS_FLASH_CELLBOARD_5_RX"

/* END */

/* START */
#define bms_cellboard_version_string "BMS_CELLBOARD_VERSION"

#define bms_cellboard_version_cellboard_id_string "BMS_CELLBOARD_VERSION_CELLBOARD_ID"
#define bms_cellboard_version_component_version_string "BMS_CELLBOARD_VERSION_COMPONENT_VERSION"
#define bms_cellboard_version_canlib_build_time_string "BMS_CELLBOARD_VERSION_CANLIB_BUILD_TIME"
/* END */

enum bms_types_id{
	e_uint16_t = -4,
	e_uint32_t,
	e_double,
	e_uint8_t,

	e_bms_temperatures_info_cellboard_id,
	e_bms_temperatures_cellboard_id,
	e_bms_voltages_cellboard_id,
	e_bms_board_status_cellboard_id,
	e_bms_board_status_balancing_status,
	e_bms_jmp_to_blt_cellboard_id,
	e_bms_set_balancing_status_balancing_status,
	e_bms_voltages_info_cellboard_id,
	e_bms_cellboard_version_cellboard_id
};
int bms_fields_string_from_id(int id, char **v, size_t fields_size, size_t string_size);
int bms_enum_fields(int enum_id, char **v, size_t fields_size, size_t string_size);
int bms_serialize_from_id(int id, char *s, uint8_t *data, size_t size);


#endif