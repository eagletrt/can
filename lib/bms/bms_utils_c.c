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
int bms_serialize_from_id(int id, char *s, uint8_t *data, size_t size)
{
    switch(id)
    {
	case 1537:
	{
		bms_board_status_t tmp;
		bms_board_status_converted_t tmp_converted;
		sscanf(s, "%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"",
			tmp.cellboard_id,
			tmp.errors_can_comm,
			tmp.errors_ltc_comm,
			tmp.errors_temp_comm_0,
			tmp.errors_temp_comm_1,
			tmp.errors_temp_comm_2,
			tmp.errors_temp_comm_3,
			tmp.errors_temp_comm_4,
			tmp.errors_temp_comm_5,
			tmp.errors_open_wire,
			tmp.balancing_status,
			tmp.balancing_cells_cell0,
			tmp.balancing_cells_cell1,
			tmp.balancing_cells_cell2,
			tmp.balancing_cells_cell3,
			tmp.balancing_cells_cell4,
			tmp.balancing_cells_cell5,
			tmp.balancing_cells_cell6,
			tmp.balancing_cells_cell7,
			tmp.balancing_cells_cell8,
			tmp.balancing_cells_cell9,
			tmp.balancing_cells_cell10,
			tmp.balancing_cells_cell11,
			tmp.balancing_cells_cell12,
			tmp.balancing_cells_cell13,
			tmp.balancing_cells_cell14,
			tmp.balancing_cells_cell15,
			tmp.balancing_cells_cell16,
			tmp.balancing_cells_cell17);
		bms_board_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		return bms_board_status_pack(data, &tmp, size);
	}
	case 514:
	{
		bms_temperatures_info_t tmp;
		bms_temperatures_info_converted_t tmp_converted;
		sscanf(s, "%" PRIu8  
			"""%f"
			"""%f"
			"""%f"
			"",
			tmp.cellboard_id,
			tmp.min_temp,
			tmp.max_temp,
			tmp.avg_temp);
		bms_temperatures_info_conversion_to_raw_struct(&tmp, &tmp_converted);
		return bms_temperatures_info_pack(data, &tmp, size);
	}
	case 1282:
	{
		bms_temperatures_t tmp;
		bms_temperatures_converted_t tmp_converted;
		sscanf(s, "%" PRIu8  
			"%" PRIu8  
			"""%f"
			"""%f"
			"""%f"
			"""%f"
			"",
			tmp.cellboard_id,
			tmp.start_index,
			tmp.temp0,
			tmp.temp1,
			tmp.temp2,
			tmp.temp3);
		bms_temperatures_conversion_to_raw_struct(&tmp, &tmp_converted);
		return bms_temperatures_pack(data, &tmp, size);
	}
	case 516:
	{
		bms_voltages_info_t tmp;
		bms_voltages_info_converted_t tmp_converted;
		sscanf(s, "%" PRIu8  
			"""%f"
			"""%f"
			"""%f"
			"",
			tmp.cellboard_id,
			tmp.min_voltage,
			tmp.max_voltage,
			tmp.avg_voltage);
		bms_voltages_info_conversion_to_raw_struct(&tmp, &tmp_converted);
		return bms_voltages_info_pack(data, &tmp, size);
	}
	case 548:
	{
		bms_voltages_t tmp;
		bms_voltages_converted_t tmp_converted;
		sscanf(s, "%" PRIu8  
			"%" PRIu8  
			"""%f"
			"""%f"
			"""%f"
			"",
			tmp.cellboard_id,
			tmp.start_index,
			tmp.voltage0,
			tmp.voltage1,
			tmp.voltage2);
		bms_voltages_conversion_to_raw_struct(&tmp, &tmp_converted);
		return bms_voltages_pack(data, &tmp, size);
	}
	case 512:
	{
		bms_set_balancing_status_t tmp;
		bms_set_balancing_status_converted_t tmp_converted;
		sscanf(s, "%" PRIu16 
			"%" PRIu16 
			"%" PRIu8  
			"",
			tmp.threshold,
			tmp.target,
			tmp.balancing_status);
		bms_set_balancing_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		return bms_set_balancing_status_pack(data, &tmp, size);
	}
	case 0:
	{
		bms_jmp_to_blt_t tmp;
		bms_jmp_to_blt_converted_t tmp_converted;
		sscanf(s, "%" PRIu8  
			"%" PRIu8  
			"",
			tmp.cellboard_id,
			tmp.board_index);
		bms_jmp_to_blt_conversion_to_raw_struct(&tmp, &tmp_converted);
		return bms_jmp_to_blt_pack(data, &tmp, size);
	}
	case 259:
	{
		bms_cellboard_version_t tmp;
		bms_cellboard_version_converted_t tmp_converted;
		sscanf(s, "%" PRIu8  
			"%" PRIu16 
			"%" PRIu32 
			"",
			tmp.cellboard_id,
			tmp.component_version,
			tmp.canlib_build_time);
		bms_cellboard_version_conversion_to_raw_struct(&tmp, &tmp_converted);
		return bms_cellboard_version_pack(data, &tmp, size);
	}

    }
    return 0;
}