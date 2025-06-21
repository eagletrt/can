#include "bms_utils.hpp"

int bms_fields_string_from_id(int id, char **v, size_t fields_size, size_t string_size)
{
	switch(id)
    {
	case 1026:
		if(29 > fields_size) return 1;
		snprintf(v[0], string_size, BOARD_STATUS_CELLBOARD_ID);
		snprintf(v[1], string_size, BOARD_STATUS_ERRORS_CAN_COMM);
		snprintf(v[2], string_size, BOARD_STATUS_ERRORS_LTC_COMM);
		snprintf(v[3], string_size, BOARD_STATUS_ERRORS_TEMP_COMM_0);
		snprintf(v[4], string_size, BOARD_STATUS_ERRORS_TEMP_COMM_1);
		snprintf(v[5], string_size, BOARD_STATUS_ERRORS_TEMP_COMM_2);
		snprintf(v[6], string_size, BOARD_STATUS_ERRORS_TEMP_COMM_3);
		snprintf(v[7], string_size, BOARD_STATUS_ERRORS_TEMP_COMM_4);
		snprintf(v[8], string_size, BOARD_STATUS_ERRORS_TEMP_COMM_5);
		snprintf(v[9], string_size, BOARD_STATUS_ERRORS_OPEN_WIRE);
		snprintf(v[10], string_size, BOARD_STATUS_BALANCING_STATUS);
		snprintf(v[11], string_size, BOARD_STATUS_BALANCING_CELLS_CELL0);
		snprintf(v[12], string_size, BOARD_STATUS_BALANCING_CELLS_CELL1);
		snprintf(v[13], string_size, BOARD_STATUS_BALANCING_CELLS_CELL2);
		snprintf(v[14], string_size, BOARD_STATUS_BALANCING_CELLS_CELL3);
		snprintf(v[15], string_size, BOARD_STATUS_BALANCING_CELLS_CELL4);
		snprintf(v[16], string_size, BOARD_STATUS_BALANCING_CELLS_CELL5);
		snprintf(v[17], string_size, BOARD_STATUS_BALANCING_CELLS_CELL6);
		snprintf(v[18], string_size, BOARD_STATUS_BALANCING_CELLS_CELL7);
		snprintf(v[19], string_size, BOARD_STATUS_BALANCING_CELLS_CELL8);
		snprintf(v[20], string_size, BOARD_STATUS_BALANCING_CELLS_CELL9);
		snprintf(v[21], string_size, BOARD_STATUS_BALANCING_CELLS_CELL10);
		snprintf(v[22], string_size, BOARD_STATUS_BALANCING_CELLS_CELL11);
		snprintf(v[23], string_size, BOARD_STATUS_BALANCING_CELLS_CELL12);
		snprintf(v[24], string_size, BOARD_STATUS_BALANCING_CELLS_CELL13);
		snprintf(v[25], string_size, BOARD_STATUS_BALANCING_CELLS_CELL14);
		snprintf(v[26], string_size, BOARD_STATUS_BALANCING_CELLS_CELL15);
		snprintf(v[27], string_size, BOARD_STATUS_BALANCING_CELLS_CELL16);
		snprintf(v[28], string_size, BOARD_STATUS_BALANCING_CELLS_CELL17);

		return 0;
	case 515:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, TEMPERATURES_INFO_CELLBOARD_ID);
		snprintf(v[1], string_size, TEMPERATURES_INFO_MIN_TEMP);
		snprintf(v[2], string_size, TEMPERATURES_INFO_MAX_TEMP);
		snprintf(v[3], string_size, TEMPERATURES_INFO_AVG_TEMP);

		return 0;
	case 1539:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, TEMPERATURES_CELLBOARD_ID);
		snprintf(v[1], string_size, TEMPERATURES_START_INDEX);
		snprintf(v[2], string_size, TEMPERATURES_TEMP0);
		snprintf(v[3], string_size, TEMPERATURES_TEMP1);
		snprintf(v[4], string_size, TEMPERATURES_TEMP2);
		snprintf(v[5], string_size, TEMPERATURES_TEMP3);

		return 0;
	case 516:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, VOLTAGES_INFO_CELLBOARD_ID);
		snprintf(v[1], string_size, VOLTAGES_INFO_MIN_VOLTAGE);
		snprintf(v[2], string_size, VOLTAGES_INFO_MAX_VOLTAGE);
		snprintf(v[3], string_size, VOLTAGES_INFO_AVG_VOLTAGE);

		return 0;
	case 1540:
		if(5 > fields_size) return 1;
		snprintf(v[0], string_size, VOLTAGES_CELLBOARD_ID);
		snprintf(v[1], string_size, VOLTAGES_START_INDEX);
		snprintf(v[2], string_size, VOLTAGES_VOLTAGE0);
		snprintf(v[3], string_size, VOLTAGES_VOLTAGE1);
		snprintf(v[4], string_size, VOLTAGES_VOLTAGE2);

		return 0;
	case 16:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, SET_BALANCING_STATUS_THRESHOLD);
		snprintf(v[1], string_size, SET_BALANCING_STATUS_TARGET);
		snprintf(v[2], string_size, SET_BALANCING_STATUS_BALANCING_STATUS);

		return 0;
	case 0:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, CELLBOARD_FLASH_START);
		snprintf(v[1], string_size, CELLBOARD_FLASH_CELLBOARD_ID);
		snprintf(v[2], string_size, CELLBOARD_FLASH_BOARD_INDEX);

		return 0;
	case 3:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, CELLBOARD_FLASH_REQUEST_MAINBOARD);
		snprintf(v[1], string_size, CELLBOARD_FLASH_REQUEST_CELLBOARD_ID);

		return 0;
	case 4:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, CELLBOARD_FLASH_RESPONSE_CELLBOARD_ID);
		snprintf(v[1], string_size, CELLBOARD_FLASH_RESPONSE_READY);

		return 0;
	case 1537:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, CELLBOARD_DISCOVERY_CELLBOARD_ID);

		return 0;
	case 1545:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, CELLBOARD_VERSION_CELLBOARD_ID);
		snprintf(v[1], string_size, CELLBOARD_VERSION_CANLIB_BUILD_TIME);
		snprintf(v[2], string_size, CELLBOARD_VERSION_COMPONENT_BUILD_TIME);

		return 0;
	case 513:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, CELLBOARD_STATUS_CELLBOARD_ID);
		snprintf(v[1], string_size, CELLBOARD_STATUS_STATUS);

		return 0;
	case 1553:
		if(5 > fields_size) return 1;
		snprintf(v[0], string_size, CELLBOARD_CELLS_VOLTAGE_CELLBOARD_ID);
		snprintf(v[1], string_size, CELLBOARD_CELLS_VOLTAGE_OFFSET);
		snprintf(v[2], string_size, CELLBOARD_CELLS_VOLTAGE_VOLTAGE_0);
		snprintf(v[3], string_size, CELLBOARD_CELLS_VOLTAGE_VOLTAGE_1);
		snprintf(v[4], string_size, CELLBOARD_CELLS_VOLTAGE_VOLTAGE_2);

		return 0;
	case 1561:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, CELLBOARD_CELLS_TEMPERATURE_CELLBOARD_ID);
		snprintf(v[1], string_size, CELLBOARD_CELLS_TEMPERATURE_OFFSET);
		snprintf(v[2], string_size, CELLBOARD_CELLS_TEMPERATURE_TEMPERATURE_0);
		snprintf(v[3], string_size, CELLBOARD_CELLS_TEMPERATURE_TEMPERATURE_1);
		snprintf(v[4], string_size, CELLBOARD_CELLS_TEMPERATURE_TEMPERATURE_2);
		snprintf(v[5], string_size, CELLBOARD_CELLS_TEMPERATURE_TEMPERATURE_3);

		return 0;
	case 1569:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, CELLBOARD_DISCHARGE_TEMPERATURE_CELLBOARD_ID);
		snprintf(v[1], string_size, CELLBOARD_DISCHARGE_TEMPERATURE_TEMPERATURE_0);
		snprintf(v[2], string_size, CELLBOARD_DISCHARGE_TEMPERATURE_TEMPERATURE_1);
		snprintf(v[3], string_size, CELLBOARD_DISCHARGE_TEMPERATURE_TEMPERATURE_2);
		snprintf(v[4], string_size, CELLBOARD_DISCHARGE_TEMPERATURE_TEMPERATURE_3);
		snprintf(v[5], string_size, CELLBOARD_DISCHARGE_TEMPERATURE_TEMPERATURE_4);

		return 0;
	case 1025:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, CELLBOARD_SET_BALANCING_STATUS_START);
		snprintf(v[1], string_size, CELLBOARD_SET_BALANCING_STATUS_TARGET);
		snprintf(v[2], string_size, CELLBOARD_SET_BALANCING_STATUS_THRESHOLD);

		return 0;
	case 1577:
		if(26 > fields_size) return 1;
		snprintf(v[0], string_size, CELLBOARD_BALANCING_STATUS_STATUS);
		snprintf(v[1], string_size, CELLBOARD_BALANCING_STATUS_CELLBOARD_ID);
		snprintf(v[2], string_size, CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_0);
		snprintf(v[3], string_size, CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_1);
		snprintf(v[4], string_size, CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_2);
		snprintf(v[5], string_size, CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_3);
		snprintf(v[6], string_size, CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_4);
		snprintf(v[7], string_size, CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_5);
		snprintf(v[8], string_size, CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_6);
		snprintf(v[9], string_size, CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_7);
		snprintf(v[10], string_size, CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_8);
		snprintf(v[11], string_size, CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_9);
		snprintf(v[12], string_size, CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_10);
		snprintf(v[13], string_size, CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_11);
		snprintf(v[14], string_size, CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_12);
		snprintf(v[15], string_size, CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_13);
		snprintf(v[16], string_size, CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_14);
		snprintf(v[17], string_size, CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_15);
		snprintf(v[18], string_size, CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_16);
		snprintf(v[19], string_size, CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_17);
		snprintf(v[20], string_size, CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_18);
		snprintf(v[21], string_size, CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_19);
		snprintf(v[22], string_size, CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_20);
		snprintf(v[23], string_size, CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_21);
		snprintf(v[24], string_size, CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_22);
		snprintf(v[25], string_size, CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_23);

		return 0;
	case 521:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, CELLBOARD_ERROR_CELLBOARD_ID);
		snprintf(v[1], string_size, CELLBOARD_ERROR_GROUP);
		snprintf(v[2], string_size, CELLBOARD_ERROR_INSTANCE);

		return 0;

    }
    return 0;
}
int bms_enum_fields(int enum_id, char **v, size_t fields_size, size_t string_size)
{
    switch(enum_id)
    {
	case 0:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_board_status_cellboard_id_CELLBOARD_0");
		snprintf(v[1], string_size, "bms_board_status_cellboard_id_CELLBOARD_1");
		snprintf(v[2], string_size, "bms_board_status_cellboard_id_CELLBOARD_2");
		snprintf(v[3], string_size, "bms_board_status_cellboard_id_CELLBOARD_3");
		snprintf(v[4], string_size, "bms_board_status_cellboard_id_CELLBOARD_4");
		snprintf(v[5], string_size, "bms_board_status_cellboard_id_CELLBOARD_5");

		return 0;
	case 1:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_board_status_balancing_status_OFF");
		snprintf(v[1], string_size, "bms_board_status_balancing_status_DISCHARGE");

		return 0;
	case 2:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_temperatures_info_cellboard_id_CELLBOARD_0");
		snprintf(v[1], string_size, "bms_temperatures_info_cellboard_id_CELLBOARD_1");
		snprintf(v[2], string_size, "bms_temperatures_info_cellboard_id_CELLBOARD_2");
		snprintf(v[3], string_size, "bms_temperatures_info_cellboard_id_CELLBOARD_3");
		snprintf(v[4], string_size, "bms_temperatures_info_cellboard_id_CELLBOARD_4");
		snprintf(v[5], string_size, "bms_temperatures_info_cellboard_id_CELLBOARD_5");

		return 0;
	case 3:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_temperatures_cellboard_id_CELLBOARD_0");
		snprintf(v[1], string_size, "bms_temperatures_cellboard_id_CELLBOARD_1");
		snprintf(v[2], string_size, "bms_temperatures_cellboard_id_CELLBOARD_2");
		snprintf(v[3], string_size, "bms_temperatures_cellboard_id_CELLBOARD_3");
		snprintf(v[4], string_size, "bms_temperatures_cellboard_id_CELLBOARD_4");
		snprintf(v[5], string_size, "bms_temperatures_cellboard_id_CELLBOARD_5");

		return 0;
	case 4:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_voltages_info_cellboard_id_CELLBOARD_0");
		snprintf(v[1], string_size, "bms_voltages_info_cellboard_id_CELLBOARD_1");
		snprintf(v[2], string_size, "bms_voltages_info_cellboard_id_CELLBOARD_2");
		snprintf(v[3], string_size, "bms_voltages_info_cellboard_id_CELLBOARD_3");
		snprintf(v[4], string_size, "bms_voltages_info_cellboard_id_CELLBOARD_4");
		snprintf(v[5], string_size, "bms_voltages_info_cellboard_id_CELLBOARD_5");

		return 0;
	case 5:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_voltages_cellboard_id_CELLBOARD_0");
		snprintf(v[1], string_size, "bms_voltages_cellboard_id_CELLBOARD_1");
		snprintf(v[2], string_size, "bms_voltages_cellboard_id_CELLBOARD_2");
		snprintf(v[3], string_size, "bms_voltages_cellboard_id_CELLBOARD_3");
		snprintf(v[4], string_size, "bms_voltages_cellboard_id_CELLBOARD_4");
		snprintf(v[5], string_size, "bms_voltages_cellboard_id_CELLBOARD_5");

		return 0;
	case 6:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_set_balancing_status_balancing_status_OFF");
		snprintf(v[1], string_size, "bms_set_balancing_status_balancing_status_DISCHARGE");

		return 0;
	case 7:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_cellboard_flash_cellboard_id_CELLBOARD_0");
		snprintf(v[1], string_size, "bms_cellboard_flash_cellboard_id_CELLBOARD_1");
		snprintf(v[2], string_size, "bms_cellboard_flash_cellboard_id_CELLBOARD_2");
		snprintf(v[3], string_size, "bms_cellboard_flash_cellboard_id_CELLBOARD_3");
		snprintf(v[4], string_size, "bms_cellboard_flash_cellboard_id_CELLBOARD_4");
		snprintf(v[5], string_size, "bms_cellboard_flash_cellboard_id_CELLBOARD_5");

		return 0;
	case 8:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_cellboard_flash_request_cellboard_id_cellboard_0");
		snprintf(v[1], string_size, "bms_cellboard_flash_request_cellboard_id_cellboard_1");
		snprintf(v[2], string_size, "bms_cellboard_flash_request_cellboard_id_cellboard_2");
		snprintf(v[3], string_size, "bms_cellboard_flash_request_cellboard_id_cellboard_3");
		snprintf(v[4], string_size, "bms_cellboard_flash_request_cellboard_id_cellboard_4");
		snprintf(v[5], string_size, "bms_cellboard_flash_request_cellboard_id_cellboard_5");

		return 0;
	case 9:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_cellboard_flash_response_cellboard_id_cellboard_0");
		snprintf(v[1], string_size, "bms_cellboard_flash_response_cellboard_id_cellboard_1");
		snprintf(v[2], string_size, "bms_cellboard_flash_response_cellboard_id_cellboard_2");
		snprintf(v[3], string_size, "bms_cellboard_flash_response_cellboard_id_cellboard_3");
		snprintf(v[4], string_size, "bms_cellboard_flash_response_cellboard_id_cellboard_4");
		snprintf(v[5], string_size, "bms_cellboard_flash_response_cellboard_id_cellboard_5");

		return 0;
	case 10:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_cellboard_discovery_cellboard_id_cellboard_0");
		snprintf(v[1], string_size, "bms_cellboard_discovery_cellboard_id_cellboard_1");
		snprintf(v[2], string_size, "bms_cellboard_discovery_cellboard_id_cellboard_2");
		snprintf(v[3], string_size, "bms_cellboard_discovery_cellboard_id_cellboard_3");
		snprintf(v[4], string_size, "bms_cellboard_discovery_cellboard_id_cellboard_4");
		snprintf(v[5], string_size, "bms_cellboard_discovery_cellboard_id_cellboard_5");

		return 0;
	case 11:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_cellboard_version_cellboard_id_cellboard_0");
		snprintf(v[1], string_size, "bms_cellboard_version_cellboard_id_cellboard_1");
		snprintf(v[2], string_size, "bms_cellboard_version_cellboard_id_cellboard_2");
		snprintf(v[3], string_size, "bms_cellboard_version_cellboard_id_cellboard_3");
		snprintf(v[4], string_size, "bms_cellboard_version_cellboard_id_cellboard_4");
		snprintf(v[5], string_size, "bms_cellboard_version_cellboard_id_cellboard_5");

		return 0;
	case 12:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_cellboard_status_cellboard_id_cellboard_0");
		snprintf(v[1], string_size, "bms_cellboard_status_cellboard_id_cellboard_1");
		snprintf(v[2], string_size, "bms_cellboard_status_cellboard_id_cellboard_2");
		snprintf(v[3], string_size, "bms_cellboard_status_cellboard_id_cellboard_3");
		snprintf(v[4], string_size, "bms_cellboard_status_cellboard_id_cellboard_4");
		snprintf(v[5], string_size, "bms_cellboard_status_cellboard_id_cellboard_5");

		return 0;
	case 13:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_cellboard_status_status_init");
		snprintf(v[1], string_size, "bms_cellboard_status_status_idle");
		snprintf(v[2], string_size, "bms_cellboard_status_status_fatal");
		snprintf(v[3], string_size, "bms_cellboard_status_status_flash");
		snprintf(v[4], string_size, "bms_cellboard_status_status_discharge");
		snprintf(v[5], string_size, "bms_cellboard_status_status_cooldown");

		return 0;
	case 14:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_cellboard_cells_voltage_cellboard_id_cellboard_0");
		snprintf(v[1], string_size, "bms_cellboard_cells_voltage_cellboard_id_cellboard_1");
		snprintf(v[2], string_size, "bms_cellboard_cells_voltage_cellboard_id_cellboard_2");
		snprintf(v[3], string_size, "bms_cellboard_cells_voltage_cellboard_id_cellboard_3");
		snprintf(v[4], string_size, "bms_cellboard_cells_voltage_cellboard_id_cellboard_4");
		snprintf(v[5], string_size, "bms_cellboard_cells_voltage_cellboard_id_cellboard_5");

		return 0;
	case 15:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_cellboard_cells_temperature_cellboard_id_cellboard_0");
		snprintf(v[1], string_size, "bms_cellboard_cells_temperature_cellboard_id_cellboard_1");
		snprintf(v[2], string_size, "bms_cellboard_cells_temperature_cellboard_id_cellboard_2");
		snprintf(v[3], string_size, "bms_cellboard_cells_temperature_cellboard_id_cellboard_3");
		snprintf(v[4], string_size, "bms_cellboard_cells_temperature_cellboard_id_cellboard_4");
		snprintf(v[5], string_size, "bms_cellboard_cells_temperature_cellboard_id_cellboard_5");

		return 0;
	case 16:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_cellboard_discharge_temperature_cellboard_id_cellboard_0");
		snprintf(v[1], string_size, "bms_cellboard_discharge_temperature_cellboard_id_cellboard_1");
		snprintf(v[2], string_size, "bms_cellboard_discharge_temperature_cellboard_id_cellboard_2");
		snprintf(v[3], string_size, "bms_cellboard_discharge_temperature_cellboard_id_cellboard_3");
		snprintf(v[4], string_size, "bms_cellboard_discharge_temperature_cellboard_id_cellboard_4");
		snprintf(v[5], string_size, "bms_cellboard_discharge_temperature_cellboard_id_cellboard_5");

		return 0;
	case 17:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_cellboard_balancing_status_status_stopped");
		snprintf(v[1], string_size, "bms_cellboard_balancing_status_status_paused");
		snprintf(v[2], string_size, "bms_cellboard_balancing_status_status_running");

		return 0;
	case 18:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_cellboard_balancing_status_cellboard_id_cellboard_0");
		snprintf(v[1], string_size, "bms_cellboard_balancing_status_cellboard_id_cellboard_1");
		snprintf(v[2], string_size, "bms_cellboard_balancing_status_cellboard_id_cellboard_2");
		snprintf(v[3], string_size, "bms_cellboard_balancing_status_cellboard_id_cellboard_3");
		snprintf(v[4], string_size, "bms_cellboard_balancing_status_cellboard_id_cellboard_4");
		snprintf(v[5], string_size, "bms_cellboard_balancing_status_cellboard_id_cellboard_5");

		return 0;
	case 19:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_cellboard_error_cellboard_id_cellboard_0");
		snprintf(v[1], string_size, "bms_cellboard_error_cellboard_id_cellboard_1");
		snprintf(v[2], string_size, "bms_cellboard_error_cellboard_id_cellboard_2");
		snprintf(v[3], string_size, "bms_cellboard_error_cellboard_id_cellboard_3");
		snprintf(v[4], string_size, "bms_cellboard_error_cellboard_id_cellboard_4");
		snprintf(v[5], string_size, "bms_cellboard_error_cellboard_id_cellboard_5");

		return 0;
	case 20:
		if(11 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_cellboard_error_group_post");
		snprintf(v[1], string_size, "bms_cellboard_error_group_under_voltage");
		snprintf(v[2], string_size, "bms_cellboard_error_group_over_voltage");
		snprintf(v[3], string_size, "bms_cellboard_error_group_under_temperature_cells");
		snprintf(v[4], string_size, "bms_cellboard_error_group_over_temperature_cells");
		snprintf(v[5], string_size, "bms_cellboard_error_group_under_temperature_discharge");
		snprintf(v[6], string_size, "bms_cellboard_error_group_over_temperature_discharge");
		snprintf(v[7], string_size, "bms_cellboard_error_group_can_communication");
		snprintf(v[8], string_size, "bms_cellboard_error_group_flash");
		snprintf(v[9], string_size, "bms_cellboard_error_group_bms_monitor_communication");
		snprintf(v[10], string_size, "bms_cellboard_error_group_open_wire");

		return 0;

    }
    return 0;
}
int bms_serialize_from_id(int id, char *s, uint8_t *data, size_t *size)
{
    switch(id)
    {
	case 1026:
	{
		bms_board_status_t tmp;
		bms_board_status_converted_t tmp_converted;
		uint8_t r_cellboard_id;
		uint8_t r_errors_can_comm;
		uint8_t r_errors_ltc_comm;
		uint8_t r_errors_temp_comm_0;
		uint8_t r_errors_temp_comm_1;
		uint8_t r_errors_temp_comm_2;
		uint8_t r_errors_temp_comm_3;
		uint8_t r_errors_temp_comm_4;
		uint8_t r_errors_temp_comm_5;
		uint8_t r_errors_open_wire;
		uint8_t r_balancing_status;
		uint8_t r_balancing_cells_cell0;
		uint8_t r_balancing_cells_cell1;
		uint8_t r_balancing_cells_cell2;
		uint8_t r_balancing_cells_cell3;
		uint8_t r_balancing_cells_cell4;
		uint8_t r_balancing_cells_cell5;
		uint8_t r_balancing_cells_cell6;
		uint8_t r_balancing_cells_cell7;
		uint8_t r_balancing_cells_cell8;
		uint8_t r_balancing_cells_cell9;
		uint8_t r_balancing_cells_cell10;
		uint8_t r_balancing_cells_cell11;
		uint8_t r_balancing_cells_cell12;
		uint8_t r_balancing_cells_cell13;
		uint8_t r_balancing_cells_cell14;
		uint8_t r_balancing_cells_cell15;
		uint8_t r_balancing_cells_cell16;
		uint8_t r_balancing_cells_cell17;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  ,
			&r_cellboard_id,
			&r_errors_can_comm,
			&r_errors_ltc_comm,
			&r_errors_temp_comm_0,
			&r_errors_temp_comm_1,
			&r_errors_temp_comm_2,
			&r_errors_temp_comm_3,
			&r_errors_temp_comm_4,
			&r_errors_temp_comm_5,
			&r_errors_open_wire,
			&r_balancing_status,
			&r_balancing_cells_cell0,
			&r_balancing_cells_cell1,
			&r_balancing_cells_cell2,
			&r_balancing_cells_cell3,
			&r_balancing_cells_cell4,
			&r_balancing_cells_cell5,
			&r_balancing_cells_cell6,
			&r_balancing_cells_cell7,
			&r_balancing_cells_cell8,
			&r_balancing_cells_cell9,
			&r_balancing_cells_cell10,
			&r_balancing_cells_cell11,
			&r_balancing_cells_cell12,
			&r_balancing_cells_cell13,
			&r_balancing_cells_cell14,
			&r_balancing_cells_cell15,
			&r_balancing_cells_cell16,
			&r_balancing_cells_cell17);
		tmp_converted.cellboard_id = (bms_board_status_cellboard_id)r_cellboard_id;
		tmp_converted.errors_can_comm = (uint8_t)r_errors_can_comm;
		tmp_converted.errors_ltc_comm = (uint8_t)r_errors_ltc_comm;
		tmp_converted.errors_temp_comm_0 = (uint8_t)r_errors_temp_comm_0;
		tmp_converted.errors_temp_comm_1 = (uint8_t)r_errors_temp_comm_1;
		tmp_converted.errors_temp_comm_2 = (uint8_t)r_errors_temp_comm_2;
		tmp_converted.errors_temp_comm_3 = (uint8_t)r_errors_temp_comm_3;
		tmp_converted.errors_temp_comm_4 = (uint8_t)r_errors_temp_comm_4;
		tmp_converted.errors_temp_comm_5 = (uint8_t)r_errors_temp_comm_5;
		tmp_converted.errors_open_wire = (uint8_t)r_errors_open_wire;
		tmp_converted.balancing_status = (bms_board_status_balancing_status)r_balancing_status;
		tmp_converted.balancing_cells_cell0 = (uint8_t)r_balancing_cells_cell0;
		tmp_converted.balancing_cells_cell1 = (uint8_t)r_balancing_cells_cell1;
		tmp_converted.balancing_cells_cell2 = (uint8_t)r_balancing_cells_cell2;
		tmp_converted.balancing_cells_cell3 = (uint8_t)r_balancing_cells_cell3;
		tmp_converted.balancing_cells_cell4 = (uint8_t)r_balancing_cells_cell4;
		tmp_converted.balancing_cells_cell5 = (uint8_t)r_balancing_cells_cell5;
		tmp_converted.balancing_cells_cell6 = (uint8_t)r_balancing_cells_cell6;
		tmp_converted.balancing_cells_cell7 = (uint8_t)r_balancing_cells_cell7;
		tmp_converted.balancing_cells_cell8 = (uint8_t)r_balancing_cells_cell8;
		tmp_converted.balancing_cells_cell9 = (uint8_t)r_balancing_cells_cell9;
		tmp_converted.balancing_cells_cell10 = (uint8_t)r_balancing_cells_cell10;
		tmp_converted.balancing_cells_cell11 = (uint8_t)r_balancing_cells_cell11;
		tmp_converted.balancing_cells_cell12 = (uint8_t)r_balancing_cells_cell12;
		tmp_converted.balancing_cells_cell13 = (uint8_t)r_balancing_cells_cell13;
		tmp_converted.balancing_cells_cell14 = (uint8_t)r_balancing_cells_cell14;
		tmp_converted.balancing_cells_cell15 = (uint8_t)r_balancing_cells_cell15;
		tmp_converted.balancing_cells_cell16 = (uint8_t)r_balancing_cells_cell16;
		tmp_converted.balancing_cells_cell17 = (uint8_t)r_balancing_cells_cell17;

		bms_board_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = BMS_BOARD_STATUS_BYTE_SIZE;
		return bms_board_status_pack(data, &tmp, BMS_BOARD_STATUS_BYTE_SIZE);
	}
	case 515:
	{
		bms_temperatures_info_t tmp;
		bms_temperatures_info_converted_t tmp_converted;
		uint8_t r_cellboard_id;
		float r_min_temp;
		float r_max_temp;
		float r_avg_temp;

		sscanf(s, "%" SCNu8 ","  
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_cellboard_id,
			&r_min_temp,
			&r_max_temp,
			&r_avg_temp);
		tmp_converted.cellboard_id = (bms_temperatures_info_cellboard_id)r_cellboard_id;
		tmp_converted.min_temp = (float)r_min_temp;
		tmp_converted.max_temp = (float)r_max_temp;
		tmp_converted.avg_temp = (float)r_avg_temp;

		bms_temperatures_info_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = BMS_TEMPERATURES_INFO_BYTE_SIZE;
		return bms_temperatures_info_pack(data, &tmp, BMS_TEMPERATURES_INFO_BYTE_SIZE);
	}
	case 1539:
	{
		bms_temperatures_t tmp;
		bms_temperatures_converted_t tmp_converted;
		uint8_t r_cellboard_id;
		uint8_t r_start_index;
		float r_temp0;
		float r_temp1;
		float r_temp2;
		float r_temp3;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  
			"%f,"       
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_cellboard_id,
			&r_start_index,
			&r_temp0,
			&r_temp1,
			&r_temp2,
			&r_temp3);
		tmp_converted.cellboard_id = (bms_temperatures_cellboard_id)r_cellboard_id;
		tmp_converted.start_index = (uint8_t)r_start_index;
		tmp_converted.temp0 = (float)r_temp0;
		tmp_converted.temp1 = (float)r_temp1;
		tmp_converted.temp2 = (float)r_temp2;
		tmp_converted.temp3 = (float)r_temp3;

		bms_temperatures_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = BMS_TEMPERATURES_BYTE_SIZE;
		return bms_temperatures_pack(data, &tmp, BMS_TEMPERATURES_BYTE_SIZE);
	}
	case 516:
	{
		bms_voltages_info_t tmp;
		bms_voltages_info_converted_t tmp_converted;
		uint8_t r_cellboard_id;
		float r_min_voltage;
		float r_max_voltage;
		float r_avg_voltage;

		sscanf(s, "%" SCNu8 ","  
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_cellboard_id,
			&r_min_voltage,
			&r_max_voltage,
			&r_avg_voltage);
		tmp_converted.cellboard_id = (bms_voltages_info_cellboard_id)r_cellboard_id;
		tmp_converted.min_voltage = (float)r_min_voltage;
		tmp_converted.max_voltage = (float)r_max_voltage;
		tmp_converted.avg_voltage = (float)r_avg_voltage;

		bms_voltages_info_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = BMS_VOLTAGES_INFO_BYTE_SIZE;
		return bms_voltages_info_pack(data, &tmp, BMS_VOLTAGES_INFO_BYTE_SIZE);
	}
	case 1540:
	{
		bms_voltages_t tmp;
		bms_voltages_converted_t tmp_converted;
		uint8_t r_cellboard_id;
		uint8_t r_start_index;
		float r_voltage0;
		float r_voltage1;
		float r_voltage2;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_cellboard_id,
			&r_start_index,
			&r_voltage0,
			&r_voltage1,
			&r_voltage2);
		tmp_converted.cellboard_id = (bms_voltages_cellboard_id)r_cellboard_id;
		tmp_converted.start_index = (uint8_t)r_start_index;
		tmp_converted.voltage0 = (float)r_voltage0;
		tmp_converted.voltage1 = (float)r_voltage1;
		tmp_converted.voltage2 = (float)r_voltage2;

		bms_voltages_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = BMS_VOLTAGES_BYTE_SIZE;
		return bms_voltages_pack(data, &tmp, BMS_VOLTAGES_BYTE_SIZE);
	}
	case 16:
	{
		bms_set_balancing_status_t tmp;
		bms_set_balancing_status_converted_t tmp_converted;
		uint16_t r_threshold;
		uint16_t r_target;
		uint8_t r_balancing_status;

		sscanf(s, "%" SCNu16 "," 
			"%" SCNu16 "," 
			"%" SCNu8 ","  ,
			&r_threshold,
			&r_target,
			&r_balancing_status);
		tmp_converted.threshold = (uint16_t)r_threshold;
		tmp_converted.target = (uint16_t)r_target;
		tmp_converted.balancing_status = (bms_set_balancing_status_balancing_status)r_balancing_status;

		bms_set_balancing_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = BMS_SET_BALANCING_STATUS_BYTE_SIZE;
		return bms_set_balancing_status_pack(data, &tmp, BMS_SET_BALANCING_STATUS_BYTE_SIZE);
	}
	case 0:
	{
		bms_cellboard_flash_t tmp;
		bms_cellboard_flash_converted_t tmp_converted;
		uint8_t r_start;
		uint8_t r_cellboard_id;
		uint8_t r_board_index;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  ,
			&r_start,
			&r_cellboard_id,
			&r_board_index);
		tmp_converted.start = (uint8_t)r_start;
		tmp_converted.cellboard_id = (bms_cellboard_flash_cellboard_id)r_cellboard_id;
		tmp_converted.board_index = (uint8_t)r_board_index;

		bms_cellboard_flash_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = BMS_CELLBOARD_FLASH_BYTE_SIZE;
		return bms_cellboard_flash_pack(data, &tmp, BMS_CELLBOARD_FLASH_BYTE_SIZE);
	}
	case 3:
	{
		bms_cellboard_flash_request_t tmp;
		bms_cellboard_flash_request_converted_t tmp_converted;
		uint8_t r_mainboard;
		uint8_t r_cellboard_id;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  ,
			&r_mainboard,
			&r_cellboard_id);
		tmp_converted.mainboard = (uint8_t)r_mainboard;
		tmp_converted.cellboard_id = (bms_cellboard_flash_request_cellboard_id)r_cellboard_id;

		bms_cellboard_flash_request_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = BMS_CELLBOARD_FLASH_REQUEST_BYTE_SIZE;
		return bms_cellboard_flash_request_pack(data, &tmp, BMS_CELLBOARD_FLASH_REQUEST_BYTE_SIZE);
	}
	case 4:
	{
		bms_cellboard_flash_response_t tmp;
		bms_cellboard_flash_response_converted_t tmp_converted;
		uint8_t r_cellboard_id;
		uint8_t r_ready;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  ,
			&r_cellboard_id,
			&r_ready);
		tmp_converted.cellboard_id = (bms_cellboard_flash_response_cellboard_id)r_cellboard_id;
		tmp_converted.ready = (uint8_t)r_ready;

		bms_cellboard_flash_response_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = BMS_CELLBOARD_FLASH_RESPONSE_BYTE_SIZE;
		return bms_cellboard_flash_response_pack(data, &tmp, BMS_CELLBOARD_FLASH_RESPONSE_BYTE_SIZE);
	}
	case 1537:
	{
		bms_cellboard_discovery_t tmp;
		bms_cellboard_discovery_converted_t tmp_converted;
		uint8_t r_cellboard_id;

		sscanf(s, "%" SCNu8 ","  ,
			&r_cellboard_id);
		tmp_converted.cellboard_id = (bms_cellboard_discovery_cellboard_id)r_cellboard_id;

		bms_cellboard_discovery_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = BMS_CELLBOARD_DISCOVERY_BYTE_SIZE;
		return bms_cellboard_discovery_pack(data, &tmp, BMS_CELLBOARD_DISCOVERY_BYTE_SIZE);
	}
	case 1545:
	{
		bms_cellboard_version_t tmp;
		bms_cellboard_version_converted_t tmp_converted;
		uint8_t r_cellboard_id;
		uint32_t r_canlib_build_time;
		uint32_t r_component_build_time;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu32 "," 
			"%" SCNu32 "," ,
			&r_cellboard_id,
			&r_canlib_build_time,
			&r_component_build_time);
		tmp_converted.cellboard_id = (bms_cellboard_version_cellboard_id)r_cellboard_id;
		tmp_converted.canlib_build_time = (uint32_t)r_canlib_build_time;
		tmp_converted.component_build_time = (uint32_t)r_component_build_time;

		bms_cellboard_version_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = BMS_CELLBOARD_VERSION_BYTE_SIZE;
		return bms_cellboard_version_pack(data, &tmp, BMS_CELLBOARD_VERSION_BYTE_SIZE);
	}
	case 513:
	{
		bms_cellboard_status_t tmp;
		bms_cellboard_status_converted_t tmp_converted;
		uint8_t r_cellboard_id;
		uint8_t r_status;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  ,
			&r_cellboard_id,
			&r_status);
		tmp_converted.cellboard_id = (bms_cellboard_status_cellboard_id)r_cellboard_id;
		tmp_converted.status = (bms_cellboard_status_status)r_status;

		bms_cellboard_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = BMS_CELLBOARD_STATUS_BYTE_SIZE;
		return bms_cellboard_status_pack(data, &tmp, BMS_CELLBOARD_STATUS_BYTE_SIZE);
	}
	case 1553:
	{
		bms_cellboard_cells_voltage_t tmp;
		bms_cellboard_cells_voltage_converted_t tmp_converted;
		uint8_t r_cellboard_id;
		uint8_t r_offset;
		float r_voltage_0;
		float r_voltage_1;
		float r_voltage_2;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_cellboard_id,
			&r_offset,
			&r_voltage_0,
			&r_voltage_1,
			&r_voltage_2);
		tmp_converted.cellboard_id = (bms_cellboard_cells_voltage_cellboard_id)r_cellboard_id;
		tmp_converted.offset = (uint8_t)r_offset;
		tmp_converted.voltage_0 = (float)r_voltage_0;
		tmp_converted.voltage_1 = (float)r_voltage_1;
		tmp_converted.voltage_2 = (float)r_voltage_2;

		bms_cellboard_cells_voltage_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = BMS_CELLBOARD_CELLS_VOLTAGE_BYTE_SIZE;
		return bms_cellboard_cells_voltage_pack(data, &tmp, BMS_CELLBOARD_CELLS_VOLTAGE_BYTE_SIZE);
	}
	case 1561:
	{
		bms_cellboard_cells_temperature_t tmp;
		bms_cellboard_cells_temperature_converted_t tmp_converted;
		uint8_t r_cellboard_id;
		uint8_t r_offset;
		float r_temperature_0;
		float r_temperature_1;
		float r_temperature_2;
		float r_temperature_3;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  
			"%f,"       
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_cellboard_id,
			&r_offset,
			&r_temperature_0,
			&r_temperature_1,
			&r_temperature_2,
			&r_temperature_3);
		tmp_converted.cellboard_id = (bms_cellboard_cells_temperature_cellboard_id)r_cellboard_id;
		tmp_converted.offset = (uint8_t)r_offset;
		tmp_converted.temperature_0 = (float)r_temperature_0;
		tmp_converted.temperature_1 = (float)r_temperature_1;
		tmp_converted.temperature_2 = (float)r_temperature_2;
		tmp_converted.temperature_3 = (float)r_temperature_3;

		bms_cellboard_cells_temperature_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = BMS_CELLBOARD_CELLS_TEMPERATURE_BYTE_SIZE;
		return bms_cellboard_cells_temperature_pack(data, &tmp, BMS_CELLBOARD_CELLS_TEMPERATURE_BYTE_SIZE);
	}
	case 1569:
	{
		bms_cellboard_discharge_temperature_t tmp;
		bms_cellboard_discharge_temperature_converted_t tmp_converted;
		uint8_t r_cellboard_id;
		float r_temperature_0;
		float r_temperature_1;
		float r_temperature_2;
		float r_temperature_3;
		float r_temperature_4;

		sscanf(s, "%" SCNu8 ","  
			"%f,"       
			"%f,"       
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_cellboard_id,
			&r_temperature_0,
			&r_temperature_1,
			&r_temperature_2,
			&r_temperature_3,
			&r_temperature_4);
		tmp_converted.cellboard_id = (bms_cellboard_discharge_temperature_cellboard_id)r_cellboard_id;
		tmp_converted.temperature_0 = (float)r_temperature_0;
		tmp_converted.temperature_1 = (float)r_temperature_1;
		tmp_converted.temperature_2 = (float)r_temperature_2;
		tmp_converted.temperature_3 = (float)r_temperature_3;
		tmp_converted.temperature_4 = (float)r_temperature_4;

		bms_cellboard_discharge_temperature_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = BMS_CELLBOARD_DISCHARGE_TEMPERATURE_BYTE_SIZE;
		return bms_cellboard_discharge_temperature_pack(data, &tmp, BMS_CELLBOARD_DISCHARGE_TEMPERATURE_BYTE_SIZE);
	}
	case 1025:
	{
		bms_cellboard_set_balancing_status_t tmp;
		bms_cellboard_set_balancing_status_converted_t tmp_converted;
		uint8_t r_start;
		float r_target;
		float r_threshold;

		sscanf(s, "%" SCNu8 ","  
			"%f,"       
			"%f,"       ,
			&r_start,
			&r_target,
			&r_threshold);
		tmp_converted.start = (uint8_t)r_start;
		tmp_converted.target = (float)r_target;
		tmp_converted.threshold = (float)r_threshold;

		bms_cellboard_set_balancing_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = BMS_CELLBOARD_SET_BALANCING_STATUS_BYTE_SIZE;
		return bms_cellboard_set_balancing_status_pack(data, &tmp, BMS_CELLBOARD_SET_BALANCING_STATUS_BYTE_SIZE);
	}
	case 1577:
	{
		bms_cellboard_balancing_status_t tmp;
		bms_cellboard_balancing_status_converted_t tmp_converted;
		uint8_t r_status;
		uint8_t r_cellboard_id;
		uint8_t r_discharging_cell_0;
		uint8_t r_discharging_cell_1;
		uint8_t r_discharging_cell_2;
		uint8_t r_discharging_cell_3;
		uint8_t r_discharging_cell_4;
		uint8_t r_discharging_cell_5;
		uint8_t r_discharging_cell_6;
		uint8_t r_discharging_cell_7;
		uint8_t r_discharging_cell_8;
		uint8_t r_discharging_cell_9;
		uint8_t r_discharging_cell_10;
		uint8_t r_discharging_cell_11;
		uint8_t r_discharging_cell_12;
		uint8_t r_discharging_cell_13;
		uint8_t r_discharging_cell_14;
		uint8_t r_discharging_cell_15;
		uint8_t r_discharging_cell_16;
		uint8_t r_discharging_cell_17;
		uint8_t r_discharging_cell_18;
		uint8_t r_discharging_cell_19;
		uint8_t r_discharging_cell_20;
		uint8_t r_discharging_cell_21;
		uint8_t r_discharging_cell_22;
		uint8_t r_discharging_cell_23;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  ,
			&r_status,
			&r_cellboard_id,
			&r_discharging_cell_0,
			&r_discharging_cell_1,
			&r_discharging_cell_2,
			&r_discharging_cell_3,
			&r_discharging_cell_4,
			&r_discharging_cell_5,
			&r_discharging_cell_6,
			&r_discharging_cell_7,
			&r_discharging_cell_8,
			&r_discharging_cell_9,
			&r_discharging_cell_10,
			&r_discharging_cell_11,
			&r_discharging_cell_12,
			&r_discharging_cell_13,
			&r_discharging_cell_14,
			&r_discharging_cell_15,
			&r_discharging_cell_16,
			&r_discharging_cell_17,
			&r_discharging_cell_18,
			&r_discharging_cell_19,
			&r_discharging_cell_20,
			&r_discharging_cell_21,
			&r_discharging_cell_22,
			&r_discharging_cell_23);
		tmp_converted.status = (bms_cellboard_balancing_status_status)r_status;
		tmp_converted.cellboard_id = (bms_cellboard_balancing_status_cellboard_id)r_cellboard_id;
		tmp_converted.discharging_cell_0 = (uint8_t)r_discharging_cell_0;
		tmp_converted.discharging_cell_1 = (uint8_t)r_discharging_cell_1;
		tmp_converted.discharging_cell_2 = (uint8_t)r_discharging_cell_2;
		tmp_converted.discharging_cell_3 = (uint8_t)r_discharging_cell_3;
		tmp_converted.discharging_cell_4 = (uint8_t)r_discharging_cell_4;
		tmp_converted.discharging_cell_5 = (uint8_t)r_discharging_cell_5;
		tmp_converted.discharging_cell_6 = (uint8_t)r_discharging_cell_6;
		tmp_converted.discharging_cell_7 = (uint8_t)r_discharging_cell_7;
		tmp_converted.discharging_cell_8 = (uint8_t)r_discharging_cell_8;
		tmp_converted.discharging_cell_9 = (uint8_t)r_discharging_cell_9;
		tmp_converted.discharging_cell_10 = (uint8_t)r_discharging_cell_10;
		tmp_converted.discharging_cell_11 = (uint8_t)r_discharging_cell_11;
		tmp_converted.discharging_cell_12 = (uint8_t)r_discharging_cell_12;
		tmp_converted.discharging_cell_13 = (uint8_t)r_discharging_cell_13;
		tmp_converted.discharging_cell_14 = (uint8_t)r_discharging_cell_14;
		tmp_converted.discharging_cell_15 = (uint8_t)r_discharging_cell_15;
		tmp_converted.discharging_cell_16 = (uint8_t)r_discharging_cell_16;
		tmp_converted.discharging_cell_17 = (uint8_t)r_discharging_cell_17;
		tmp_converted.discharging_cell_18 = (uint8_t)r_discharging_cell_18;
		tmp_converted.discharging_cell_19 = (uint8_t)r_discharging_cell_19;
		tmp_converted.discharging_cell_20 = (uint8_t)r_discharging_cell_20;
		tmp_converted.discharging_cell_21 = (uint8_t)r_discharging_cell_21;
		tmp_converted.discharging_cell_22 = (uint8_t)r_discharging_cell_22;
		tmp_converted.discharging_cell_23 = (uint8_t)r_discharging_cell_23;

		bms_cellboard_balancing_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = BMS_CELLBOARD_BALANCING_STATUS_BYTE_SIZE;
		return bms_cellboard_balancing_status_pack(data, &tmp, BMS_CELLBOARD_BALANCING_STATUS_BYTE_SIZE);
	}
	case 521:
	{
		bms_cellboard_error_t tmp;
		bms_cellboard_error_converted_t tmp_converted;
		uint8_t r_cellboard_id;
		uint8_t r_group;
		uint16_t r_instance;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu16 "," ,
			&r_cellboard_id,
			&r_group,
			&r_instance);
		tmp_converted.cellboard_id = (bms_cellboard_error_cellboard_id)r_cellboard_id;
		tmp_converted.group = (bms_cellboard_error_group)r_group;
		tmp_converted.instance = (uint16_t)r_instance;

		bms_cellboard_error_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = BMS_CELLBOARD_ERROR_BYTE_SIZE;
		return bms_cellboard_error_pack(data, &tmp, BMS_CELLBOARD_ERROR_BYTE_SIZE);
	}

    }
    return 0;
}
int bms_n_fields_from_id(int id)
{
	switch(id)
    {
		case 1026: return 29;
		case 515: return 4;
		case 1539: return 6;
		case 516: return 4;
		case 1540: return 5;
		case 16: return 3;
		case 5: return 0;
		case 6: return 0;
		case 7: return 0;
		case 8: return 0;
		case 9: return 0;
		case 10: return 0;
		case 11: return 0;
		case 12: return 0;
		case 13: return 0;
		case 14: return 0;
		case 15: return 0;
		case 0: return 3;
		case 1: return 0;
		case 2: return 0;
		case 3: return 2;
		case 4: return 2;
		case 1537: return 1;
		case 1545: return 3;
		case 513: return 2;
		case 1553: return 5;
		case 1561: return 6;
		case 1569: return 6;
		case 1025: return 3;
		case 1577: return 26;
		case 521: return 3;
    }
    return 0;
}
int bms_fields_types_from_id(int id, int* fields_types, int fields_types_size)
{
    switch(id)
    {
	case 1026:
		if(fields_types_size < 29) return 0;
		fields_types[0] = e_bms_board_status_cellboard_id;
		fields_types[1] = e_bms_uint8_t;
		fields_types[2] = e_bms_uint8_t;
		fields_types[3] = e_bms_uint8_t;
		fields_types[4] = e_bms_uint8_t;
		fields_types[5] = e_bms_uint8_t;
		fields_types[6] = e_bms_uint8_t;
		fields_types[7] = e_bms_uint8_t;
		fields_types[8] = e_bms_uint8_t;
		fields_types[9] = e_bms_uint8_t;
		fields_types[10] = e_bms_board_status_balancing_status;
		fields_types[11] = e_bms_uint8_t;
		fields_types[12] = e_bms_uint8_t;
		fields_types[13] = e_bms_uint8_t;
		fields_types[14] = e_bms_uint8_t;
		fields_types[15] = e_bms_uint8_t;
		fields_types[16] = e_bms_uint8_t;
		fields_types[17] = e_bms_uint8_t;
		fields_types[18] = e_bms_uint8_t;
		fields_types[19] = e_bms_uint8_t;
		fields_types[20] = e_bms_uint8_t;
		fields_types[21] = e_bms_uint8_t;
		fields_types[22] = e_bms_uint8_t;
		fields_types[23] = e_bms_uint8_t;
		fields_types[24] = e_bms_uint8_t;
		fields_types[25] = e_bms_uint8_t;
		fields_types[26] = e_bms_uint8_t;
		fields_types[27] = e_bms_uint8_t;
		fields_types[28] = e_bms_uint8_t;
		return 29;
	case 515:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_bms_temperatures_info_cellboard_id;
		fields_types[1] = e_bms_float;
		fields_types[2] = e_bms_float;
		fields_types[3] = e_bms_float;
		return 4;
	case 1539:
		if(fields_types_size < 6) return 0;
		fields_types[0] = e_bms_temperatures_cellboard_id;
		fields_types[1] = e_bms_uint8_t;
		fields_types[2] = e_bms_float;
		fields_types[3] = e_bms_float;
		fields_types[4] = e_bms_float;
		fields_types[5] = e_bms_float;
		return 6;
	case 516:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_bms_voltages_info_cellboard_id;
		fields_types[1] = e_bms_float;
		fields_types[2] = e_bms_float;
		fields_types[3] = e_bms_float;
		return 4;
	case 1540:
		if(fields_types_size < 5) return 0;
		fields_types[0] = e_bms_voltages_cellboard_id;
		fields_types[1] = e_bms_uint8_t;
		fields_types[2] = e_bms_float;
		fields_types[3] = e_bms_float;
		fields_types[4] = e_bms_float;
		return 5;
	case 16:
		if(fields_types_size < 3) return 0;
		fields_types[0] = e_bms_uint16_t;
		fields_types[1] = e_bms_uint16_t;
		fields_types[2] = e_bms_set_balancing_status_balancing_status;
		return 3;
	case 0:
		if(fields_types_size < 3) return 0;
		fields_types[0] = e_bms_uint8_t;
		fields_types[1] = e_bms_cellboard_flash_cellboard_id;
		fields_types[2] = e_bms_uint8_t;
		return 3;
	case 3:
		if(fields_types_size < 2) return 0;
		fields_types[0] = e_bms_uint8_t;
		fields_types[1] = e_bms_cellboard_flash_request_cellboard_id;
		return 2;
	case 4:
		if(fields_types_size < 2) return 0;
		fields_types[0] = e_bms_cellboard_flash_response_cellboard_id;
		fields_types[1] = e_bms_uint8_t;
		return 2;
	case 1537:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_bms_cellboard_discovery_cellboard_id;
		return 1;
	case 1545:
		if(fields_types_size < 3) return 0;
		fields_types[0] = e_bms_cellboard_version_cellboard_id;
		fields_types[1] = e_bms_uint32_t;
		fields_types[2] = e_bms_uint32_t;
		return 3;
	case 513:
		if(fields_types_size < 2) return 0;
		fields_types[0] = e_bms_cellboard_status_cellboard_id;
		fields_types[1] = e_bms_cellboard_status_status;
		return 2;
	case 1553:
		if(fields_types_size < 5) return 0;
		fields_types[0] = e_bms_cellboard_cells_voltage_cellboard_id;
		fields_types[1] = e_bms_uint8_t;
		fields_types[2] = e_bms_float;
		fields_types[3] = e_bms_float;
		fields_types[4] = e_bms_float;
		return 5;
	case 1561:
		if(fields_types_size < 6) return 0;
		fields_types[0] = e_bms_cellboard_cells_temperature_cellboard_id;
		fields_types[1] = e_bms_uint8_t;
		fields_types[2] = e_bms_float;
		fields_types[3] = e_bms_float;
		fields_types[4] = e_bms_float;
		fields_types[5] = e_bms_float;
		return 6;
	case 1569:
		if(fields_types_size < 6) return 0;
		fields_types[0] = e_bms_cellboard_discharge_temperature_cellboard_id;
		fields_types[1] = e_bms_float;
		fields_types[2] = e_bms_float;
		fields_types[3] = e_bms_float;
		fields_types[4] = e_bms_float;
		fields_types[5] = e_bms_float;
		return 6;
	case 1025:
		if(fields_types_size < 3) return 0;
		fields_types[0] = e_bms_uint8_t;
		fields_types[1] = e_bms_float;
		fields_types[2] = e_bms_float;
		return 3;
	case 1577:
		if(fields_types_size < 26) return 0;
		fields_types[0] = e_bms_cellboard_balancing_status_status;
		fields_types[1] = e_bms_cellboard_balancing_status_cellboard_id;
		fields_types[2] = e_bms_uint8_t;
		fields_types[3] = e_bms_uint8_t;
		fields_types[4] = e_bms_uint8_t;
		fields_types[5] = e_bms_uint8_t;
		fields_types[6] = e_bms_uint8_t;
		fields_types[7] = e_bms_uint8_t;
		fields_types[8] = e_bms_uint8_t;
		fields_types[9] = e_bms_uint8_t;
		fields_types[10] = e_bms_uint8_t;
		fields_types[11] = e_bms_uint8_t;
		fields_types[12] = e_bms_uint8_t;
		fields_types[13] = e_bms_uint8_t;
		fields_types[14] = e_bms_uint8_t;
		fields_types[15] = e_bms_uint8_t;
		fields_types[16] = e_bms_uint8_t;
		fields_types[17] = e_bms_uint8_t;
		fields_types[18] = e_bms_uint8_t;
		fields_types[19] = e_bms_uint8_t;
		fields_types[20] = e_bms_uint8_t;
		fields_types[21] = e_bms_uint8_t;
		fields_types[22] = e_bms_uint8_t;
		fields_types[23] = e_bms_uint8_t;
		fields_types[24] = e_bms_uint8_t;
		fields_types[25] = e_bms_uint8_t;
		return 26;
	case 521:
		if(fields_types_size < 3) return 0;
		fields_types[0] = e_bms_cellboard_error_cellboard_id;
		fields_types[1] = e_bms_cellboard_error_group;
		fields_types[2] = e_bms_uint16_t;
		return 3;

    }
    return 0;
}
std::vector<std::string> bms_enum_fields_from_message(const std::string& msg_name)
{
	std::vector<std::string> ret;

	if(msg_name == BOARD_STATUS) {
		ret.push_back("cellboard_id");
		ret.push_back("errors_can_comm");
		ret.push_back("errors_ltc_comm");
		ret.push_back("errors_temp_comm_0");
		ret.push_back("errors_temp_comm_1");
		ret.push_back("errors_temp_comm_2");
		ret.push_back("errors_temp_comm_3");
		ret.push_back("errors_temp_comm_4");
		ret.push_back("errors_temp_comm_5");
		ret.push_back("errors_open_wire");
		ret.push_back("balancing_status");
		ret.push_back("balancing_cells_cell0");
		ret.push_back("balancing_cells_cell1");
		ret.push_back("balancing_cells_cell2");
		ret.push_back("balancing_cells_cell3");
		ret.push_back("balancing_cells_cell4");
		ret.push_back("balancing_cells_cell5");
		ret.push_back("balancing_cells_cell6");
		ret.push_back("balancing_cells_cell7");
		ret.push_back("balancing_cells_cell8");
		ret.push_back("balancing_cells_cell9");
		ret.push_back("balancing_cells_cell10");
		ret.push_back("balancing_cells_cell11");
		ret.push_back("balancing_cells_cell12");
		ret.push_back("balancing_cells_cell13");
		ret.push_back("balancing_cells_cell14");
		ret.push_back("balancing_cells_cell15");
		ret.push_back("balancing_cells_cell16");
		ret.push_back("balancing_cells_cell17");
	}
	if(msg_name == TEMPERATURES_INFO) {
		ret.push_back("cellboard_id");
	}
	if(msg_name == TEMPERATURES) {
		ret.push_back("cellboard_id");
	}
	if(msg_name == VOLTAGES_INFO) {
		ret.push_back("cellboard_id");
	}
	if(msg_name == VOLTAGES) {
		ret.push_back("cellboard_id");
	}
	if(msg_name == SET_BALANCING_STATUS) {
		ret.push_back("balancing_status");
	}
	if(msg_name == CELLBOARD_FLASH) {
		ret.push_back("start");
		ret.push_back("cellboard_id");
	}
	if(msg_name == CELLBOARD_FLASH_REQUEST) {
		ret.push_back("mainboard");
		ret.push_back("cellboard_id");
	}
	if(msg_name == CELLBOARD_FLASH_RESPONSE) {
		ret.push_back("cellboard_id");
		ret.push_back("ready");
	}
	if(msg_name == CELLBOARD_DISCOVERY) {
		ret.push_back("cellboard_id");
	}
	if(msg_name == CELLBOARD_VERSION) {
		ret.push_back("cellboard_id");
	}
	if(msg_name == CELLBOARD_STATUS) {
		ret.push_back("cellboard_id");
		ret.push_back("status");
	}
	if(msg_name == CELLBOARD_CELLS_VOLTAGE) {
		ret.push_back("cellboard_id");
	}
	if(msg_name == CELLBOARD_CELLS_TEMPERATURE) {
		ret.push_back("cellboard_id");
	}
	if(msg_name == CELLBOARD_DISCHARGE_TEMPERATURE) {
		ret.push_back("cellboard_id");
	}
	if(msg_name == CELLBOARD_SET_BALANCING_STATUS) {
		ret.push_back("start");
	}
	if(msg_name == CELLBOARD_BALANCING_STATUS) {
		ret.push_back("status");
		ret.push_back("cellboard_id");
		ret.push_back("discharging_cell_0");
		ret.push_back("discharging_cell_1");
		ret.push_back("discharging_cell_2");
		ret.push_back("discharging_cell_3");
		ret.push_back("discharging_cell_4");
		ret.push_back("discharging_cell_5");
		ret.push_back("discharging_cell_6");
		ret.push_back("discharging_cell_7");
		ret.push_back("discharging_cell_8");
		ret.push_back("discharging_cell_9");
		ret.push_back("discharging_cell_10");
		ret.push_back("discharging_cell_11");
		ret.push_back("discharging_cell_12");
		ret.push_back("discharging_cell_13");
		ret.push_back("discharging_cell_14");
		ret.push_back("discharging_cell_15");
		ret.push_back("discharging_cell_16");
		ret.push_back("discharging_cell_17");
		ret.push_back("discharging_cell_18");
		ret.push_back("discharging_cell_19");
		ret.push_back("discharging_cell_20");
		ret.push_back("discharging_cell_21");
		ret.push_back("discharging_cell_22");
		ret.push_back("discharging_cell_23");
	}
	if(msg_name == CELLBOARD_ERROR) {
		ret.push_back("cellboard_id");
		ret.push_back("group");
	}

	return ret;
}
std::vector<std::string> bms_enum_names_from_fields(const std::string& msg_name, const std::string& sgn_name)
{
	std::vector<std::string> ret;

	if(msg_name == BOARD_STATUS)
	{
		if(sgn_name == "cellboard_id")
		{
			ret.push_back("CELLBOARD_0");
			ret.push_back("CELLBOARD_1");
			ret.push_back("CELLBOARD_2");
			ret.push_back("CELLBOARD_3");
			ret.push_back("CELLBOARD_4");
			ret.push_back("CELLBOARD_5");
			return ret;
		}
		if(sgn_name == "balancing_status")
		{
			ret.push_back("OFF");
			ret.push_back("DISCHARGE");
			return ret;
		}
	}
	if(msg_name == TEMPERATURES_INFO)
	{
		if(sgn_name == "cellboard_id")
		{
			ret.push_back("CELLBOARD_0");
			ret.push_back("CELLBOARD_1");
			ret.push_back("CELLBOARD_2");
			ret.push_back("CELLBOARD_3");
			ret.push_back("CELLBOARD_4");
			ret.push_back("CELLBOARD_5");
			return ret;
		}
	}
	if(msg_name == TEMPERATURES)
	{
		if(sgn_name == "cellboard_id")
		{
			ret.push_back("CELLBOARD_0");
			ret.push_back("CELLBOARD_1");
			ret.push_back("CELLBOARD_2");
			ret.push_back("CELLBOARD_3");
			ret.push_back("CELLBOARD_4");
			ret.push_back("CELLBOARD_5");
			return ret;
		}
	}
	if(msg_name == VOLTAGES_INFO)
	{
		if(sgn_name == "cellboard_id")
		{
			ret.push_back("CELLBOARD_0");
			ret.push_back("CELLBOARD_1");
			ret.push_back("CELLBOARD_2");
			ret.push_back("CELLBOARD_3");
			ret.push_back("CELLBOARD_4");
			ret.push_back("CELLBOARD_5");
			return ret;
		}
	}
	if(msg_name == VOLTAGES)
	{
		if(sgn_name == "cellboard_id")
		{
			ret.push_back("CELLBOARD_0");
			ret.push_back("CELLBOARD_1");
			ret.push_back("CELLBOARD_2");
			ret.push_back("CELLBOARD_3");
			ret.push_back("CELLBOARD_4");
			ret.push_back("CELLBOARD_5");
			return ret;
		}
	}
	if(msg_name == SET_BALANCING_STATUS)
	{
		if(sgn_name == "balancing_status")
		{
			ret.push_back("OFF");
			ret.push_back("DISCHARGE");
			return ret;
		}
	}
	if(msg_name == CELLBOARD_FLASH)
	{
		if(sgn_name == "cellboard_id")
		{
			ret.push_back("CELLBOARD_0");
			ret.push_back("CELLBOARD_1");
			ret.push_back("CELLBOARD_2");
			ret.push_back("CELLBOARD_3");
			ret.push_back("CELLBOARD_4");
			ret.push_back("CELLBOARD_5");
			return ret;
		}
	}
	if(msg_name == CELLBOARD_FLASH_REQUEST)
	{
		if(sgn_name == "cellboard_id")
		{
			ret.push_back("cellboard_0");
			ret.push_back("cellboard_1");
			ret.push_back("cellboard_2");
			ret.push_back("cellboard_3");
			ret.push_back("cellboard_4");
			ret.push_back("cellboard_5");
			return ret;
		}
	}
	if(msg_name == CELLBOARD_FLASH_RESPONSE)
	{
		if(sgn_name == "cellboard_id")
		{
			ret.push_back("cellboard_0");
			ret.push_back("cellboard_1");
			ret.push_back("cellboard_2");
			ret.push_back("cellboard_3");
			ret.push_back("cellboard_4");
			ret.push_back("cellboard_5");
			return ret;
		}
	}
	if(msg_name == CELLBOARD_DISCOVERY)
	{
		if(sgn_name == "cellboard_id")
		{
			ret.push_back("cellboard_0");
			ret.push_back("cellboard_1");
			ret.push_back("cellboard_2");
			ret.push_back("cellboard_3");
			ret.push_back("cellboard_4");
			ret.push_back("cellboard_5");
			return ret;
		}
	}
	if(msg_name == CELLBOARD_VERSION)
	{
		if(sgn_name == "cellboard_id")
		{
			ret.push_back("cellboard_0");
			ret.push_back("cellboard_1");
			ret.push_back("cellboard_2");
			ret.push_back("cellboard_3");
			ret.push_back("cellboard_4");
			ret.push_back("cellboard_5");
			return ret;
		}
	}
	if(msg_name == CELLBOARD_STATUS)
	{
		if(sgn_name == "cellboard_id")
		{
			ret.push_back("cellboard_0");
			ret.push_back("cellboard_1");
			ret.push_back("cellboard_2");
			ret.push_back("cellboard_3");
			ret.push_back("cellboard_4");
			ret.push_back("cellboard_5");
			return ret;
		}
		if(sgn_name == "status")
		{
			ret.push_back("init");
			ret.push_back("idle");
			ret.push_back("fatal");
			ret.push_back("flash");
			ret.push_back("discharge");
			ret.push_back("cooldown");
			return ret;
		}
	}
	if(msg_name == CELLBOARD_CELLS_VOLTAGE)
	{
		if(sgn_name == "cellboard_id")
		{
			ret.push_back("cellboard_0");
			ret.push_back("cellboard_1");
			ret.push_back("cellboard_2");
			ret.push_back("cellboard_3");
			ret.push_back("cellboard_4");
			ret.push_back("cellboard_5");
			return ret;
		}
	}
	if(msg_name == CELLBOARD_CELLS_TEMPERATURE)
	{
		if(sgn_name == "cellboard_id")
		{
			ret.push_back("cellboard_0");
			ret.push_back("cellboard_1");
			ret.push_back("cellboard_2");
			ret.push_back("cellboard_3");
			ret.push_back("cellboard_4");
			ret.push_back("cellboard_5");
			return ret;
		}
	}
	if(msg_name == CELLBOARD_DISCHARGE_TEMPERATURE)
	{
		if(sgn_name == "cellboard_id")
		{
			ret.push_back("cellboard_0");
			ret.push_back("cellboard_1");
			ret.push_back("cellboard_2");
			ret.push_back("cellboard_3");
			ret.push_back("cellboard_4");
			ret.push_back("cellboard_5");
			return ret;
		}
	}
	if(msg_name == CELLBOARD_BALANCING_STATUS)
	{
		if(sgn_name == "status")
		{
			ret.push_back("stopped");
			ret.push_back("paused");
			ret.push_back("running");
			return ret;
		}
		if(sgn_name == "cellboard_id")
		{
			ret.push_back("cellboard_0");
			ret.push_back("cellboard_1");
			ret.push_back("cellboard_2");
			ret.push_back("cellboard_3");
			ret.push_back("cellboard_4");
			ret.push_back("cellboard_5");
			return ret;
		}
	}
	if(msg_name == CELLBOARD_ERROR)
	{
		if(sgn_name == "cellboard_id")
		{
			ret.push_back("cellboard_0");
			ret.push_back("cellboard_1");
			ret.push_back("cellboard_2");
			ret.push_back("cellboard_3");
			ret.push_back("cellboard_4");
			ret.push_back("cellboard_5");
			return ret;
		}
		if(sgn_name == "group")
		{
			ret.push_back("post");
			ret.push_back("under_voltage");
			ret.push_back("over_voltage");
			ret.push_back("under_temperature_cells");
			ret.push_back("over_temperature_cells");
			ret.push_back("under_temperature_discharge");
			ret.push_back("over_temperature_discharge");
			ret.push_back("can_communication");
			ret.push_back("flash");
			ret.push_back("bms_monitor_communication");
			ret.push_back("open_wire");
			return ret;
		}
	}

	return ret;
}
