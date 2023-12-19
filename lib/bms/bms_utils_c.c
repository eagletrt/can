#include "bms_utils_c.h"


int bms_fields_string_from_id(int id, char **v, size_t fields_size, size_t string_size)
{
	switch(id)
    {
	case 1537:
		if(29 > fields_size) return 1;
		snprintf(v[0], string_size, bms_board_status_cellboard_id_string);
		snprintf(v[1], string_size, bms_board_status_errors_can_comm_string);
		snprintf(v[2], string_size, bms_board_status_errors_ltc_comm_string);
		snprintf(v[3], string_size, bms_board_status_errors_temp_comm_0_string);
		snprintf(v[4], string_size, bms_board_status_errors_temp_comm_1_string);
		snprintf(v[5], string_size, bms_board_status_errors_temp_comm_2_string);
		snprintf(v[6], string_size, bms_board_status_errors_temp_comm_3_string);
		snprintf(v[7], string_size, bms_board_status_errors_temp_comm_4_string);
		snprintf(v[8], string_size, bms_board_status_errors_temp_comm_5_string);
		snprintf(v[9], string_size, bms_board_status_errors_open_wire_string);
		snprintf(v[10], string_size, bms_board_status_balancing_status_string);
		snprintf(v[11], string_size, bms_board_status_balancing_cells_cell0_string);
		snprintf(v[12], string_size, bms_board_status_balancing_cells_cell1_string);
		snprintf(v[13], string_size, bms_board_status_balancing_cells_cell2_string);
		snprintf(v[14], string_size, bms_board_status_balancing_cells_cell3_string);
		snprintf(v[15], string_size, bms_board_status_balancing_cells_cell4_string);
		snprintf(v[16], string_size, bms_board_status_balancing_cells_cell5_string);
		snprintf(v[17], string_size, bms_board_status_balancing_cells_cell6_string);
		snprintf(v[18], string_size, bms_board_status_balancing_cells_cell7_string);
		snprintf(v[19], string_size, bms_board_status_balancing_cells_cell8_string);
		snprintf(v[20], string_size, bms_board_status_balancing_cells_cell9_string);
		snprintf(v[21], string_size, bms_board_status_balancing_cells_cell10_string);
		snprintf(v[22], string_size, bms_board_status_balancing_cells_cell11_string);
		snprintf(v[23], string_size, bms_board_status_balancing_cells_cell12_string);
		snprintf(v[24], string_size, bms_board_status_balancing_cells_cell13_string);
		snprintf(v[25], string_size, bms_board_status_balancing_cells_cell14_string);
		snprintf(v[26], string_size, bms_board_status_balancing_cells_cell15_string);
		snprintf(v[27], string_size, bms_board_status_balancing_cells_cell16_string);
		snprintf(v[28], string_size, bms_board_status_balancing_cells_cell17_string);

		return 0;
	case 514:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, bms_temperatures_info_cellboard_id_string);
		snprintf(v[1], string_size, bms_temperatures_info_min_temp_string);
		snprintf(v[2], string_size, bms_temperatures_info_max_temp_string);
		snprintf(v[3], string_size, bms_temperatures_info_avg_temp_string);

		return 0;
	case 1282:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, bms_temperatures_cellboard_id_string);
		snprintf(v[1], string_size, bms_temperatures_start_index_string);
		snprintf(v[2], string_size, bms_temperatures_temp0_string);
		snprintf(v[3], string_size, bms_temperatures_temp1_string);
		snprintf(v[4], string_size, bms_temperatures_temp2_string);
		snprintf(v[5], string_size, bms_temperatures_temp3_string);

		return 0;
	case 516:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, bms_voltages_info_cellboard_id_string);
		snprintf(v[1], string_size, bms_voltages_info_min_voltage_string);
		snprintf(v[2], string_size, bms_voltages_info_max_voltage_string);
		snprintf(v[3], string_size, bms_voltages_info_avg_voltage_string);

		return 0;
	case 548:
		if(5 > fields_size) return 1;
		snprintf(v[0], string_size, bms_voltages_cellboard_id_string);
		snprintf(v[1], string_size, bms_voltages_start_index_string);
		snprintf(v[2], string_size, bms_voltages_voltage0_string);
		snprintf(v[3], string_size, bms_voltages_voltage1_string);
		snprintf(v[4], string_size, bms_voltages_voltage2_string);

		return 0;
	case 512:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, bms_set_balancing_status_threshold_string);
		snprintf(v[1], string_size, bms_set_balancing_status_target_string);
		snprintf(v[2], string_size, bms_set_balancing_status_balancing_status_string);

		return 0;
	case 0:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, bms_jmp_to_blt_cellboard_id_string);
		snprintf(v[1], string_size, bms_jmp_to_blt_board_index_string);

		return 0;
	case 259:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, bms_cellboard_version_cellboard_id_string);
		snprintf(v[1], string_size, bms_cellboard_version_component_version_string);
		snprintf(v[2], string_size, bms_cellboard_version_canlib_build_time_string);

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
	case 1537:
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
	case 1282:
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
	case 548:
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
	case 512:
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
	case 259:
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
		case 1537: return 29;
		case 514: return 4;
		case 1282: return 6;
		case 516: return 4;
		case 548: return 5;
		case 512: return 3;
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
		case 259: return 3;
    }
    return 0;
}
int bms_fields_types_from_id(int id, int* fields_types, int fields_types_size)
{
    switch(id)
    {
	case 1537:
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
	case 1282:
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
	case 548:
		if(fields_types_size < 5) return 0;
		fields_types[0] = e_bms_voltages_cellboard_id;
		fields_types[1] = e_bms_uint8_t;
		fields_types[2] = e_bms_float;
		fields_types[3] = e_bms_float;
		fields_types[4] = e_bms_float;
		return 5;
	case 512:
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
	case 259:
		if(fields_types_size < 3) return 0;
		fields_types[0] = e_bms_cellboard_version_cellboard_id;
		fields_types[1] = e_bms_uint16_t;
		fields_types[2] = e_bms_uint32_t;
		return 3;

    }
    return 0;
}
