#ifndef bms_UTILS_H
#define bms_UTILS_H

#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "bms_network.h"

#ifdef __cplusplus
extern "C" {
#endif

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
#define JMP_TO_BLT "JMP_TO_BLT"

#define JMP_TO_BLT_CELLBOARD_ID "jmp_to_blt_cellboard_id"
#define JMP_TO_BLT_BOARD_INDEX "jmp_to_blt_board_index"
/* END */

/* START */
#define FLASH_CELLBOARD_0_TX "FLASH_CELLBOARD_0_TX"

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
#define CELLBOARD_VERSION "CELLBOARD_VERSION"

#define CELLBOARD_VERSION_CELLBOARD_ID "cellboard_version_cellboard_id"
#define CELLBOARD_VERSION_COMPONENT_VERSION "cellboard_version_component_version"
#define CELLBOARD_VERSION_CANLIB_BUILD_TIME "cellboard_version_canlib_build_time"
/* END */

enum bms_types_id{
	e_bms_uint8_t = -4,
	e_bms_uint32_t,
	e_bms_float,
	e_bms_uint16_t,

	e_bms_board_status_cellboard_id,
	e_bms_board_status_balancing_status,
	e_bms_temperatures_info_cellboard_id,
	e_bms_temperatures_cellboard_id,
	e_bms_voltages_info_cellboard_id,
	e_bms_voltages_cellboard_id,
	e_bms_set_balancing_status_balancing_status,
	e_bms_jmp_to_blt_cellboard_id,
	e_bms_cellboard_version_cellboard_id
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
int bms_fields_types_from_id(int id, int* fields_types, int fields_types_size);

/**
 * @brief get the fields of an enum given the name of the message and the name of the signal
 * 
 * @param[in] msg_name name of the message to find
 * @param[in] sgn_name name of the signal to find
 * @param[out] v array of strings containing the enum fields
 * 
 * @return the number of fields or 0 if the signal is not an enum
*/
int bms_enum_fields_from_name(const char *msg_name, const char *sgn_name, char **v);


#ifdef __cplusplus
}
#endif

#endif
