#include "bms_utils_c.h"


int bms_fields_string_from_id(int id, char **v, size_t fields_size, size_t string_size)
{
	switch(id)
    {
	case 1025:
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
	case 514:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, TEMPERATURES_INFO_CELLBOARD_ID);
		snprintf(v[1], string_size, TEMPERATURES_INFO_MIN_TEMP);
		snprintf(v[2], string_size, TEMPERATURES_INFO_MAX_TEMP);
		snprintf(v[3], string_size, TEMPERATURES_INFO_AVG_TEMP);

		return 0;
	case 1538:
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
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, JMP_TO_BLT_CELLBOARD_ID);
		snprintf(v[1], string_size, JMP_TO_BLT_BOARD_INDEX);

		return 0;
	case 1539:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, CELLBOARD_VERSION_CELLBOARD_ID);
		snprintf(v[1], string_size, CELLBOARD_VERSION_COMPONENT_VERSION);
		snprintf(v[2], string_size, CELLBOARD_VERSION_CANLIB_BUILD_TIME);

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
		snprintf(v[0], string_size, "bms_jmp_to_blt_cellboard_id_CELLBOARD_0");
		snprintf(v[1], string_size, "bms_jmp_to_blt_cellboard_id_CELLBOARD_1");
		snprintf(v[2], string_size, "bms_jmp_to_blt_cellboard_id_CELLBOARD_2");
		snprintf(v[3], string_size, "bms_jmp_to_blt_cellboard_id_CELLBOARD_3");
		snprintf(v[4], string_size, "bms_jmp_to_blt_cellboard_id_CELLBOARD_4");
		snprintf(v[5], string_size, "bms_jmp_to_blt_cellboard_id_CELLBOARD_5");

		return 0;
	case 8:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_cellboard_version_cellboard_id_CELLBOARD_0");
		snprintf(v[1], string_size, "bms_cellboard_version_cellboard_id_CELLBOARD_1");
		snprintf(v[2], string_size, "bms_cellboard_version_cellboard_id_CELLBOARD_2");
		snprintf(v[3], string_size, "bms_cellboard_version_cellboard_id_CELLBOARD_3");
		snprintf(v[4], string_size, "bms_cellboard_version_cellboard_id_CELLBOARD_4");
		snprintf(v[5], string_size, "bms_cellboard_version_cellboard_id_CELLBOARD_5");

		return 0;

    }
    return 0;
}
int bms_serialize_from_id(int id, char *s, uint8_t *data, size_t *size)
{
    switch(id)
    {
	case 1025:
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
	case 514:
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
	case 1538:
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
		bms_jmp_to_blt_t tmp;
		bms_jmp_to_blt_converted_t tmp_converted;
		uint8_t r_cellboard_id;
		uint8_t r_board_index;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  ,
			&r_cellboard_id,
			&r_board_index);
		tmp_converted.cellboard_id = (bms_jmp_to_blt_cellboard_id)r_cellboard_id;
		tmp_converted.board_index = (uint8_t)r_board_index;

		bms_jmp_to_blt_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = BMS_JMP_TO_BLT_BYTE_SIZE;
		return bms_jmp_to_blt_pack(data, &tmp, BMS_JMP_TO_BLT_BYTE_SIZE);
	}
	case 1539:
	{
		bms_cellboard_version_t tmp;
		bms_cellboard_version_converted_t tmp_converted;
		uint8_t r_cellboard_id;
		uint16_t r_component_version;
		uint32_t r_canlib_build_time;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu16 "," 
			"%" SCNu32 "," ,
			&r_cellboard_id,
			&r_component_version,
			&r_canlib_build_time);
		tmp_converted.cellboard_id = (bms_cellboard_version_cellboard_id)r_cellboard_id;
		tmp_converted.component_version = (uint16_t)r_component_version;
		tmp_converted.canlib_build_time = (uint32_t)r_canlib_build_time;

		bms_cellboard_version_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = BMS_CELLBOARD_VERSION_BYTE_SIZE;
		return bms_cellboard_version_pack(data, &tmp, BMS_CELLBOARD_VERSION_BYTE_SIZE);
	}

    }
    return 0;
}
int bms_n_fields_from_id(int id)
{
	switch(id)
    {
		case 1025: return 29;
		case 514: return 4;
		case 1538: return 6;
		case 516: return 4;
		case 1540: return 5;
		case 16: return 3;
		case 0: return 2;
		case 4: return 0;
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
		case 1539: return 3;
    }
    return 0;
}
int bms_fields_types_from_id(int id, int* fields_types, int fields_types_size)
{
    switch(id)
    {
	case 1025:
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
	case 514:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_bms_temperatures_info_cellboard_id;
		fields_types[1] = e_bms_float;
		fields_types[2] = e_bms_float;
		fields_types[3] = e_bms_float;
		return 4;
	case 1538:
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
		if(fields_types_size < 2) return 0;
		fields_types[0] = e_bms_jmp_to_blt_cellboard_id;
		fields_types[1] = e_bms_uint8_t;
		return 2;
	case 1539:
		if(fields_types_size < 3) return 0;
		fields_types[0] = e_bms_cellboard_version_cellboard_id;
		fields_types[1] = e_bms_uint16_t;
		fields_types[2] = e_bms_uint32_t;
		return 3;

    }
    return 0;
}
int bms_enum_fields_from_name(const char *msg_name, const char *sgn_name, char **v)
{
	if(!strcmp(msg_name, "BOARD_STATUS"))
	{
		if(!strcmp(sgn_name, "cellboard_id"))
		{
			sprintf(v[0], "CELLBOARD_0");
			sprintf(v[1], "CELLBOARD_1");
			sprintf(v[2], "CELLBOARD_2");
			sprintf(v[3], "CELLBOARD_3");
			sprintf(v[4], "CELLBOARD_4");
			sprintf(v[5], "CELLBOARD_5");
			return 6;
		}
		if(!strcmp(sgn_name, "balancing_status"))
		{
			sprintf(v[0], "OFF");
			sprintf(v[1], "DISCHARGE");
			return 2;
		}
	}
	if(!strcmp(msg_name, "TEMPERATURES_INFO"))
	{
		if(!strcmp(sgn_name, "cellboard_id"))
		{
			sprintf(v[0], "CELLBOARD_0");
			sprintf(v[1], "CELLBOARD_1");
			sprintf(v[2], "CELLBOARD_2");
			sprintf(v[3], "CELLBOARD_3");
			sprintf(v[4], "CELLBOARD_4");
			sprintf(v[5], "CELLBOARD_5");
			return 6;
		}
	}
	if(!strcmp(msg_name, "TEMPERATURES"))
	{
		if(!strcmp(sgn_name, "cellboard_id"))
		{
			sprintf(v[0], "CELLBOARD_0");
			sprintf(v[1], "CELLBOARD_1");
			sprintf(v[2], "CELLBOARD_2");
			sprintf(v[3], "CELLBOARD_3");
			sprintf(v[4], "CELLBOARD_4");
			sprintf(v[5], "CELLBOARD_5");
			return 6;
		}
	}
	if(!strcmp(msg_name, "VOLTAGES_INFO"))
	{
		if(!strcmp(sgn_name, "cellboard_id"))
		{
			sprintf(v[0], "CELLBOARD_0");
			sprintf(v[1], "CELLBOARD_1");
			sprintf(v[2], "CELLBOARD_2");
			sprintf(v[3], "CELLBOARD_3");
			sprintf(v[4], "CELLBOARD_4");
			sprintf(v[5], "CELLBOARD_5");
			return 6;
		}
	}
	if(!strcmp(msg_name, "VOLTAGES"))
	{
		if(!strcmp(sgn_name, "cellboard_id"))
		{
			sprintf(v[0], "CELLBOARD_0");
			sprintf(v[1], "CELLBOARD_1");
			sprintf(v[2], "CELLBOARD_2");
			sprintf(v[3], "CELLBOARD_3");
			sprintf(v[4], "CELLBOARD_4");
			sprintf(v[5], "CELLBOARD_5");
			return 6;
		}
	}
	if(!strcmp(msg_name, "SET_BALANCING_STATUS"))
	{
		if(!strcmp(sgn_name, "balancing_status"))
		{
			sprintf(v[0], "OFF");
			sprintf(v[1], "DISCHARGE");
			return 2;
		}
	}
	if(!strcmp(msg_name, "JMP_TO_BLT"))
	{
		if(!strcmp(sgn_name, "cellboard_id"))
		{
			sprintf(v[0], "CELLBOARD_0");
			sprintf(v[1], "CELLBOARD_1");
			sprintf(v[2], "CELLBOARD_2");
			sprintf(v[3], "CELLBOARD_3");
			sprintf(v[4], "CELLBOARD_4");
			sprintf(v[5], "CELLBOARD_5");
			return 6;
		}
	}
	if(!strcmp(msg_name, "CELLBOARD_VERSION"))
	{
		if(!strcmp(sgn_name, "cellboard_id"))
		{
			sprintf(v[0], "CELLBOARD_0");
			sprintf(v[1], "CELLBOARD_1");
			sprintf(v[2], "CELLBOARD_2");
			sprintf(v[3], "CELLBOARD_3");
			sprintf(v[4], "CELLBOARD_4");
			sprintf(v[5], "CELLBOARD_5");
			return 6;
		}
	}
	return 0;
}
