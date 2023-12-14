#include "secondary_utils_c.h"


int secondary_fields_string_from_id(int id, char **v, size_t fields_size, size_t string_size)
{
	switch(id)
    {
	case 1260:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, secondary_imu_angular_rate_ang_rate_x_string);
		snprintf(v[1], string_size, secondary_imu_angular_rate_ang_rate_y_string);
		snprintf(v[2], string_size, secondary_imu_angular_rate_ang_rate_z_string);

		return 0;
	case 1261:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, secondary_imu_acceleration_accel_x_string);
		snprintf(v[1], string_size, secondary_imu_acceleration_accel_y_string);
		snprintf(v[2], string_size, secondary_imu_acceleration_accel_z_string);
		snprintf(v[3], string_size, secondary_imu_acceleration_temperature_string);

		return 0;
	case 1456:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, secondary_irts_fl_0_channel1_string);
		snprintf(v[1], string_size, secondary_irts_fl_0_channel2_string);
		snprintf(v[2], string_size, secondary_irts_fl_0_channel3_string);
		snprintf(v[3], string_size, secondary_irts_fl_0_channel4_string);

		return 0;
	case 1457:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, secondary_irts_fl_1_channel5_string);
		snprintf(v[1], string_size, secondary_irts_fl_1_channel6_string);
		snprintf(v[2], string_size, secondary_irts_fl_1_channel7_string);
		snprintf(v[3], string_size, secondary_irts_fl_1_channel8_string);

		return 0;
	case 1458:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, secondary_irts_fl_2_channel9_string);
		snprintf(v[1], string_size, secondary_irts_fl_2_channel10_string);
		snprintf(v[2], string_size, secondary_irts_fl_2_channel11_string);
		snprintf(v[3], string_size, secondary_irts_fl_2_channel12_string);

		return 0;
	case 1459:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, secondary_irts_fl_3_channel13_string);
		snprintf(v[1], string_size, secondary_irts_fl_3_channel14_string);
		snprintf(v[2], string_size, secondary_irts_fl_3_channel15_string);
		snprintf(v[3], string_size, secondary_irts_fl_3_channel16_string);

		return 0;
	case 1464:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, secondary_irts_fr_0_channel1_string);
		snprintf(v[1], string_size, secondary_irts_fr_0_channel2_string);
		snprintf(v[2], string_size, secondary_irts_fr_0_channel3_string);
		snprintf(v[3], string_size, secondary_irts_fr_0_channel4_string);

		return 0;
	case 1465:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, secondary_irts_fr_1_channel5_string);
		snprintf(v[1], string_size, secondary_irts_fr_1_channel6_string);
		snprintf(v[2], string_size, secondary_irts_fr_1_channel7_string);
		snprintf(v[3], string_size, secondary_irts_fr_1_channel8_string);

		return 0;
	case 1466:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, secondary_irts_fr_2_channel9_string);
		snprintf(v[1], string_size, secondary_irts_fr_2_channel10_string);
		snprintf(v[2], string_size, secondary_irts_fr_2_channel11_string);
		snprintf(v[3], string_size, secondary_irts_fr_2_channel12_string);

		return 0;
	case 1467:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, secondary_irts_fr_3_channel13_string);
		snprintf(v[1], string_size, secondary_irts_fr_3_channel14_string);
		snprintf(v[2], string_size, secondary_irts_fr_3_channel15_string);
		snprintf(v[3], string_size, secondary_irts_fr_3_channel16_string);

		return 0;
	case 1468:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, secondary_irts_rl_0_channel1_string);
		snprintf(v[1], string_size, secondary_irts_rl_0_channel2_string);
		snprintf(v[2], string_size, secondary_irts_rl_0_channel3_string);
		snprintf(v[3], string_size, secondary_irts_rl_0_channel4_string);

		return 0;
	case 1469:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, secondary_irts_rl_1_channel5_string);
		snprintf(v[1], string_size, secondary_irts_rl_1_channel6_string);
		snprintf(v[2], string_size, secondary_irts_rl_1_channel7_string);
		snprintf(v[3], string_size, secondary_irts_rl_1_channel8_string);

		return 0;
	case 1470:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, secondary_irts_rl_2_channel9_string);
		snprintf(v[1], string_size, secondary_irts_rl_2_channel10_string);
		snprintf(v[2], string_size, secondary_irts_rl_2_channel11_string);
		snprintf(v[3], string_size, secondary_irts_rl_2_channel12_string);

		return 0;
	case 1471:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, secondary_irts_rl_3_channel13_string);
		snprintf(v[1], string_size, secondary_irts_rl_3_channel14_string);
		snprintf(v[2], string_size, secondary_irts_rl_3_channel15_string);
		snprintf(v[3], string_size, secondary_irts_rl_3_channel16_string);

		return 0;
	case 1472:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, secondary_irts_rr_0_channel1_string);
		snprintf(v[1], string_size, secondary_irts_rr_0_channel2_string);
		snprintf(v[2], string_size, secondary_irts_rr_0_channel3_string);
		snprintf(v[3], string_size, secondary_irts_rr_0_channel4_string);

		return 0;
	case 1473:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, secondary_irts_rr_1_channel5_string);
		snprintf(v[1], string_size, secondary_irts_rr_1_channel6_string);
		snprintf(v[2], string_size, secondary_irts_rr_1_channel7_string);
		snprintf(v[3], string_size, secondary_irts_rr_1_channel8_string);

		return 0;
	case 1474:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, secondary_irts_rr_2_channel9_string);
		snprintf(v[1], string_size, secondary_irts_rr_2_channel10_string);
		snprintf(v[2], string_size, secondary_irts_rr_2_channel11_string);
		snprintf(v[3], string_size, secondary_irts_rr_2_channel12_string);

		return 0;
	case 1475:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, secondary_irts_rr_3_channel13_string);
		snprintf(v[1], string_size, secondary_irts_rr_3_channel14_string);
		snprintf(v[2], string_size, secondary_irts_rr_3_channel15_string);
		snprintf(v[3], string_size, secondary_irts_rr_3_channel16_string);

		return 0;
	case 1027:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, secondary_gps_coords_latitude_string);
		snprintf(v[1], string_size, secondary_gps_coords_longitude_string);

		return 0;
	case 1059:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, secondary_gps_speed_speed_string);

		return 0;
	case 771:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, secondary_pedals_output_apps_string);
		snprintf(v[1], string_size, secondary_pedals_output_bse_front_string);
		snprintf(v[2], string_size, secondary_pedals_output_bse_rear_string);

		return 0;
	case 260:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, secondary_steering_angle_angle_string);

		return 0;
	case 1281:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, secondary_control_state_map_pw_string);
		snprintf(v[1], string_size, secondary_control_state_map_sc_string);
		snprintf(v[2], string_size, secondary_control_state_map_tv_string);

		return 0;
	case 515:
		if(8 > fields_size) return 1;
		snprintf(v[0], string_size, secondary_tpms_fl_pressure_string);
		snprintf(v[1], string_size, secondary_tpms_fr_pressure_string);
		snprintf(v[2], string_size, secondary_tpms_rl_pressure_string);
		snprintf(v[3], string_size, secondary_tpms_rr_pressure_string);
		snprintf(v[4], string_size, secondary_tpms_fl_temperature_string);
		snprintf(v[5], string_size, secondary_tpms_fr_temperature_string);
		snprintf(v[6], string_size, secondary_tpms_rl_temperature_string);
		snprintf(v[7], string_size, secondary_tpms_rr_temperature_string);

		return 0;
	case 1091:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, secondary_lap_count_lap_count_string);
		snprintf(v[1], string_size, secondary_lap_count_lap_time_string);

		return 0;
	case 770:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, secondary_lc_status_lap_number_string);
		snprintf(v[1], string_size, secondary_lc_status_best_time_string);
		snprintf(v[2], string_size, secondary_lc_status_last_time_string);

		return 0;
	case 256:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, secondary_timestamp_timestamp_string);

		return 0;
	case 1028:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, secondary_rear_ammo_pos_rl_string);
		snprintf(v[1], string_size, secondary_rear_ammo_pos_rr_string);

		return 0;
	case 1060:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, secondary_front_ammo_pos_fl_string);
		snprintf(v[1], string_size, secondary_front_ammo_pos_fr_string);

		return 0;
	case 1024:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, secondary_debug_signal_field_1_string);
		snprintf(v[1], string_size, secondary_debug_signal_field_2_string);
		snprintf(v[2], string_size, secondary_debug_signal_field_3_string);
		snprintf(v[3], string_size, secondary_debug_signal_field_4_string);

		return 0;
	case 1092:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, secondary_cooling_temp_top_left_string);
		snprintf(v[1], string_size, secondary_cooling_temp_bottom_left_string);
		snprintf(v[2], string_size, secondary_cooling_temp_top_right_string);
		snprintf(v[3], string_size, secondary_cooling_temp_bottom_right_string);

		return 0;

    }
    return 0;
}
int secondary_enum_fields(int enum_id, char **v, size_t fields_size, size_t string_size)
{
    switch(enum_id)
    {

    }
    return 0;
}
int secondary_serialize_from_id(int id, char *s, uint8_t *data, size_t size)
{
    switch(id)
    {
	case 1260:
	{
		secondary_imu_angular_rate_t tmp;
		secondary_imu_angular_rate_converted_t tmp_converted;
		sscanf(s, """%f"
			"""%f"
			"""%f"
			"",
			tmp.ang_rate_x,
			tmp.ang_rate_y,
			tmp.ang_rate_z);
		secondary_imu_angular_rate_conversion_to_raw_struct(&tmp, &tmp_converted);
		return secondary_imu_angular_rate_pack(data, &tmp, size);
	}
	case 1261:
	{
		secondary_imu_acceleration_t tmp;
		secondary_imu_acceleration_converted_t tmp_converted;
		sscanf(s, """%f"
			"""%f"
			"""%f"
			"%" PRIi16 
			"",
			tmp.accel_x,
			tmp.accel_y,
			tmp.accel_z,
			tmp.temperature);
		secondary_imu_acceleration_conversion_to_raw_struct(&tmp, &tmp_converted);
		return secondary_imu_acceleration_pack(data, &tmp, size);
	}
	case 1456:
	{
		secondary_irts_fl_0_t tmp;
		secondary_irts_fl_0_converted_t tmp_converted;
		sscanf(s, """%f"
			"""%f"
			"""%f"
			"""%f"
			"",
			tmp.channel1,
			tmp.channel2,
			tmp.channel3,
			tmp.channel4);
		secondary_irts_fl_0_conversion_to_raw_struct(&tmp, &tmp_converted);
		return secondary_irts_fl_0_pack(data, &tmp, size);
	}
	case 1457:
	{
		secondary_irts_fl_1_t tmp;
		secondary_irts_fl_1_converted_t tmp_converted;
		sscanf(s, """%f"
			"""%f"
			"""%f"
			"""%f"
			"",
			tmp.channel5,
			tmp.channel6,
			tmp.channel7,
			tmp.channel8);
		secondary_irts_fl_1_conversion_to_raw_struct(&tmp, &tmp_converted);
		return secondary_irts_fl_1_pack(data, &tmp, size);
	}
	case 1458:
	{
		secondary_irts_fl_2_t tmp;
		secondary_irts_fl_2_converted_t tmp_converted;
		sscanf(s, """%f"
			"""%f"
			"""%f"
			"""%f"
			"",
			tmp.channel9,
			tmp.channel10,
			tmp.channel11,
			tmp.channel12);
		secondary_irts_fl_2_conversion_to_raw_struct(&tmp, &tmp_converted);
		return secondary_irts_fl_2_pack(data, &tmp, size);
	}
	case 1459:
	{
		secondary_irts_fl_3_t tmp;
		secondary_irts_fl_3_converted_t tmp_converted;
		sscanf(s, """%f"
			"""%f"
			"""%f"
			"""%f"
			"",
			tmp.channel13,
			tmp.channel14,
			tmp.channel15,
			tmp.channel16);
		secondary_irts_fl_3_conversion_to_raw_struct(&tmp, &tmp_converted);
		return secondary_irts_fl_3_pack(data, &tmp, size);
	}
	case 1464:
	{
		secondary_irts_fr_0_t tmp;
		secondary_irts_fr_0_converted_t tmp_converted;
		sscanf(s, """%f"
			"""%f"
			"""%f"
			"""%f"
			"",
			tmp.channel1,
			tmp.channel2,
			tmp.channel3,
			tmp.channel4);
		secondary_irts_fr_0_conversion_to_raw_struct(&tmp, &tmp_converted);
		return secondary_irts_fr_0_pack(data, &tmp, size);
	}
	case 1465:
	{
		secondary_irts_fr_1_t tmp;
		secondary_irts_fr_1_converted_t tmp_converted;
		sscanf(s, """%f"
			"""%f"
			"""%f"
			"""%f"
			"",
			tmp.channel5,
			tmp.channel6,
			tmp.channel7,
			tmp.channel8);
		secondary_irts_fr_1_conversion_to_raw_struct(&tmp, &tmp_converted);
		return secondary_irts_fr_1_pack(data, &tmp, size);
	}
	case 1466:
	{
		secondary_irts_fr_2_t tmp;
		secondary_irts_fr_2_converted_t tmp_converted;
		sscanf(s, """%f"
			"""%f"
			"""%f"
			"""%f"
			"",
			tmp.channel9,
			tmp.channel10,
			tmp.channel11,
			tmp.channel12);
		secondary_irts_fr_2_conversion_to_raw_struct(&tmp, &tmp_converted);
		return secondary_irts_fr_2_pack(data, &tmp, size);
	}
	case 1467:
	{
		secondary_irts_fr_3_t tmp;
		secondary_irts_fr_3_converted_t tmp_converted;
		sscanf(s, """%f"
			"""%f"
			"""%f"
			"""%f"
			"",
			tmp.channel13,
			tmp.channel14,
			tmp.channel15,
			tmp.channel16);
		secondary_irts_fr_3_conversion_to_raw_struct(&tmp, &tmp_converted);
		return secondary_irts_fr_3_pack(data, &tmp, size);
	}
	case 1468:
	{
		secondary_irts_rl_0_t tmp;
		secondary_irts_rl_0_converted_t tmp_converted;
		sscanf(s, """%f"
			"""%f"
			"""%f"
			"""%f"
			"",
			tmp.channel1,
			tmp.channel2,
			tmp.channel3,
			tmp.channel4);
		secondary_irts_rl_0_conversion_to_raw_struct(&tmp, &tmp_converted);
		return secondary_irts_rl_0_pack(data, &tmp, size);
	}
	case 1469:
	{
		secondary_irts_rl_1_t tmp;
		secondary_irts_rl_1_converted_t tmp_converted;
		sscanf(s, """%f"
			"""%f"
			"""%f"
			"""%f"
			"",
			tmp.channel5,
			tmp.channel6,
			tmp.channel7,
			tmp.channel8);
		secondary_irts_rl_1_conversion_to_raw_struct(&tmp, &tmp_converted);
		return secondary_irts_rl_1_pack(data, &tmp, size);
	}
	case 1470:
	{
		secondary_irts_rl_2_t tmp;
		secondary_irts_rl_2_converted_t tmp_converted;
		sscanf(s, """%f"
			"""%f"
			"""%f"
			"""%f"
			"",
			tmp.channel9,
			tmp.channel10,
			tmp.channel11,
			tmp.channel12);
		secondary_irts_rl_2_conversion_to_raw_struct(&tmp, &tmp_converted);
		return secondary_irts_rl_2_pack(data, &tmp, size);
	}
	case 1471:
	{
		secondary_irts_rl_3_t tmp;
		secondary_irts_rl_3_converted_t tmp_converted;
		sscanf(s, """%f"
			"""%f"
			"""%f"
			"""%f"
			"",
			tmp.channel13,
			tmp.channel14,
			tmp.channel15,
			tmp.channel16);
		secondary_irts_rl_3_conversion_to_raw_struct(&tmp, &tmp_converted);
		return secondary_irts_rl_3_pack(data, &tmp, size);
	}
	case 1472:
	{
		secondary_irts_rr_0_t tmp;
		secondary_irts_rr_0_converted_t tmp_converted;
		sscanf(s, """%f"
			"""%f"
			"""%f"
			"""%f"
			"",
			tmp.channel1,
			tmp.channel2,
			tmp.channel3,
			tmp.channel4);
		secondary_irts_rr_0_conversion_to_raw_struct(&tmp, &tmp_converted);
		return secondary_irts_rr_0_pack(data, &tmp, size);
	}
	case 1473:
	{
		secondary_irts_rr_1_t tmp;
		secondary_irts_rr_1_converted_t tmp_converted;
		sscanf(s, """%f"
			"""%f"
			"""%f"
			"""%f"
			"",
			tmp.channel5,
			tmp.channel6,
			tmp.channel7,
			tmp.channel8);
		secondary_irts_rr_1_conversion_to_raw_struct(&tmp, &tmp_converted);
		return secondary_irts_rr_1_pack(data, &tmp, size);
	}
	case 1474:
	{
		secondary_irts_rr_2_t tmp;
		secondary_irts_rr_2_converted_t tmp_converted;
		sscanf(s, """%f"
			"""%f"
			"""%f"
			"""%f"
			"",
			tmp.channel9,
			tmp.channel10,
			tmp.channel11,
			tmp.channel12);
		secondary_irts_rr_2_conversion_to_raw_struct(&tmp, &tmp_converted);
		return secondary_irts_rr_2_pack(data, &tmp, size);
	}
	case 1475:
	{
		secondary_irts_rr_3_t tmp;
		secondary_irts_rr_3_converted_t tmp_converted;
		sscanf(s, """%f"
			"""%f"
			"""%f"
			"""%f"
			"",
			tmp.channel13,
			tmp.channel14,
			tmp.channel15,
			tmp.channel16);
		secondary_irts_rr_3_conversion_to_raw_struct(&tmp, &tmp_converted);
		return secondary_irts_rr_3_pack(data, &tmp, size);
	}
	case 1027:
	{
		secondary_gps_coords_t tmp;
		secondary_gps_coords_converted_t tmp_converted;
		sscanf(s, "%" PRIu32 
			"%" PRIu32 
			"",
			tmp.latitude,
			tmp.longitude);
		secondary_gps_coords_conversion_to_raw_struct(&tmp, &tmp_converted);
		return secondary_gps_coords_pack(data, &tmp, size);
	}
	case 1059:
	{
		secondary_gps_speed_t tmp;
		secondary_gps_speed_converted_t tmp_converted;
		sscanf(s, "%" PRIu16 
			"",
			tmp.speed);
		secondary_gps_speed_conversion_to_raw_struct(&tmp, &tmp_converted);
		return secondary_gps_speed_pack(data, &tmp, size);
	}
	case 771:
	{
		secondary_pedals_output_t tmp;
		secondary_pedals_output_converted_t tmp_converted;
		sscanf(s, """%f"
			"""%f"
			"""%f"
			"",
			tmp.apps,
			tmp.bse_front,
			tmp.bse_rear);
		secondary_pedals_output_conversion_to_raw_struct(&tmp, &tmp_converted);
		return secondary_pedals_output_pack(data, &tmp, size);
	}
	case 260:
	{
		secondary_steering_angle_t tmp;
		secondary_steering_angle_converted_t tmp_converted;
		sscanf(s, """%f"
			"",
			tmp.angle);
		secondary_steering_angle_conversion_to_raw_struct(&tmp, &tmp_converted);
		return secondary_steering_angle_pack(data, &tmp, size);
	}
	case 1281:
	{
		secondary_control_state_t tmp;
		secondary_control_state_converted_t tmp_converted;
		sscanf(s, """%f"
			"""%f"
			"""%f"
			"",
			tmp.map_pw,
			tmp.map_sc,
			tmp.map_tv);
		secondary_control_state_conversion_to_raw_struct(&tmp, &tmp_converted);
		return secondary_control_state_pack(data, &tmp, size);
	}
	case 515:
	{
		secondary_tpms_t tmp;
		secondary_tpms_converted_t tmp_converted;
		sscanf(s, "%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"",
			tmp.fl_pressure,
			tmp.fr_pressure,
			tmp.rl_pressure,
			tmp.rr_pressure,
			tmp.fl_temperature,
			tmp.fr_temperature,
			tmp.rl_temperature,
			tmp.rr_temperature);
		secondary_tpms_conversion_to_raw_struct(&tmp, &tmp_converted);
		return secondary_tpms_pack(data, &tmp, size);
	}
	case 1091:
	{
		secondary_lap_count_t tmp;
		secondary_lap_count_converted_t tmp_converted;
		sscanf(s, "%" PRIu16 
			"""%f"
			"",
			tmp.lap_count,
			tmp.lap_time);
		secondary_lap_count_conversion_to_raw_struct(&tmp, &tmp_converted);
		return secondary_lap_count_pack(data, &tmp, size);
	}
	case 770:
	{
		secondary_lc_status_t tmp;
		secondary_lc_status_converted_t tmp_converted;
		sscanf(s, "%" PRIu16 
			"""%f"
			"""%f"
			"",
			tmp.lap_number,
			tmp.best_time,
			tmp.last_time);
		secondary_lc_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		return secondary_lc_status_pack(data, &tmp, size);
	}
	case 256:
	{
		secondary_timestamp_t tmp;
		secondary_timestamp_converted_t tmp_converted;
		sscanf(s, "%" PRIu64 
			"",
			tmp.timestamp);
		secondary_timestamp_conversion_to_raw_struct(&tmp, &tmp_converted);
		return secondary_timestamp_pack(data, &tmp, size);
	}
	case 1028:
	{
		secondary_rear_ammo_pos_t tmp;
		secondary_rear_ammo_pos_converted_t tmp_converted;
		sscanf(s, """%f"
			"""%f"
			"",
			tmp.rl,
			tmp.rr);
		secondary_rear_ammo_pos_conversion_to_raw_struct(&tmp, &tmp_converted);
		return secondary_rear_ammo_pos_pack(data, &tmp, size);
	}
	case 1060:
	{
		secondary_front_ammo_pos_t tmp;
		secondary_front_ammo_pos_converted_t tmp_converted;
		sscanf(s, """%f"
			"""%f"
			"",
			tmp.fl,
			tmp.fr);
		secondary_front_ammo_pos_conversion_to_raw_struct(&tmp, &tmp_converted);
		return secondary_front_ammo_pos_pack(data, &tmp, size);
	}
	case 1024:
	{
		secondary_debug_signal_t tmp;
		secondary_debug_signal_converted_t tmp_converted;
		sscanf(s, """%f"
			"""%f"
			"""%f"
			"""%f"
			"",
			tmp.field_1,
			tmp.field_2,
			tmp.field_3,
			tmp.field_4);
		secondary_debug_signal_conversion_to_raw_struct(&tmp, &tmp_converted);
		return secondary_debug_signal_pack(data, &tmp, size);
	}
	case 1092:
	{
		secondary_cooling_temp_t tmp;
		secondary_cooling_temp_converted_t tmp_converted;
		sscanf(s, """%f"
			"""%f"
			"""%f"
			"""%f"
			"",
			tmp.top_left,
			tmp.bottom_left,
			tmp.top_right,
			tmp.bottom_right);
		secondary_cooling_temp_conversion_to_raw_struct(&tmp, &tmp_converted);
		return secondary_cooling_temp_pack(data, &tmp, size);
	}

    }
    return 0;
}