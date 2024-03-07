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
	case 1200:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, secondary_irts_rr_0_channel1_string);
		snprintf(v[1], string_size, secondary_irts_rr_0_channel2_string);
		snprintf(v[2], string_size, secondary_irts_rr_0_channel3_string);
		snprintf(v[3], string_size, secondary_irts_rr_0_channel4_string);

		return 0;
	case 1201:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, secondary_irts_rr_1_channel5_string);
		snprintf(v[1], string_size, secondary_irts_rr_1_channel6_string);
		snprintf(v[2], string_size, secondary_irts_rr_1_channel7_string);
		snprintf(v[3], string_size, secondary_irts_rr_1_channel8_string);

		return 0;
	case 1202:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, secondary_irts_rr_2_channel9_string);
		snprintf(v[1], string_size, secondary_irts_rr_2_channel10_string);
		snprintf(v[2], string_size, secondary_irts_rr_2_channel11_string);
		snprintf(v[3], string_size, secondary_irts_rr_2_channel12_string);

		return 0;
	case 1203:
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
	case 1092:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, secondary_rod_elongation_deformation_string);

		return 0;
	case 1024:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, secondary_debug_signal_field_1_string);
		snprintf(v[1], string_size, secondary_debug_signal_field_2_string);
		snprintf(v[2], string_size, secondary_debug_signal_field_3_string);
		snprintf(v[3], string_size, secondary_debug_signal_field_4_string);

		return 0;
	case 1124:
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
int secondary_serialize_from_id(int id, char *s, uint8_t *data, size_t *size)
{
    switch(id)
    {
	case 1260:
	{
		secondary_imu_angular_rate_t tmp;
		secondary_imu_angular_rate_converted_t tmp_converted;
		float r_ang_rate_x;
		float r_ang_rate_y;
		float r_ang_rate_z;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       ,
			&r_ang_rate_x,
			&r_ang_rate_y,
			&r_ang_rate_z);
		tmp_converted.ang_rate_x = (float)r_ang_rate_x;
		tmp_converted.ang_rate_y = (float)r_ang_rate_y;
		tmp_converted.ang_rate_z = (float)r_ang_rate_z;

		secondary_imu_angular_rate_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_IMU_ANGULAR_RATE_BYTE_SIZE;
		return secondary_imu_angular_rate_pack(data, &tmp, SECONDARY_IMU_ANGULAR_RATE_BYTE_SIZE);
	}
	case 1261:
	{
		secondary_imu_acceleration_t tmp;
		secondary_imu_acceleration_converted_t tmp_converted;
		float r_accel_x;
		float r_accel_y;
		float r_accel_z;
		int16_t r_temperature;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       
			"%" SCNi16 "," ,
			&r_accel_x,
			&r_accel_y,
			&r_accel_z,
			&r_temperature);
		tmp_converted.accel_x = (float)r_accel_x;
		tmp_converted.accel_y = (float)r_accel_y;
		tmp_converted.accel_z = (float)r_accel_z;
		tmp_converted.temperature = (int16_t)r_temperature;

		secondary_imu_acceleration_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_IMU_ACCELERATION_BYTE_SIZE;
		return secondary_imu_acceleration_pack(data, &tmp, SECONDARY_IMU_ACCELERATION_BYTE_SIZE);
	}
	case 1456:
	{
		secondary_irts_fl_0_t tmp;
		secondary_irts_fl_0_converted_t tmp_converted;
		float r_channel1;
		float r_channel2;
		float r_channel3;
		float r_channel4;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_channel1,
			&r_channel2,
			&r_channel3,
			&r_channel4);
		tmp_converted.channel1 = (float)r_channel1;
		tmp_converted.channel2 = (float)r_channel2;
		tmp_converted.channel3 = (float)r_channel3;
		tmp_converted.channel4 = (float)r_channel4;

		secondary_irts_fl_0_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_IRTS_FL_0_BYTE_SIZE;
		return secondary_irts_fl_0_pack(data, &tmp, SECONDARY_IRTS_FL_0_BYTE_SIZE);
	}
	case 1457:
	{
		secondary_irts_fl_1_t tmp;
		secondary_irts_fl_1_converted_t tmp_converted;
		float r_channel5;
		float r_channel6;
		float r_channel7;
		float r_channel8;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_channel5,
			&r_channel6,
			&r_channel7,
			&r_channel8);
		tmp_converted.channel5 = (float)r_channel5;
		tmp_converted.channel6 = (float)r_channel6;
		tmp_converted.channel7 = (float)r_channel7;
		tmp_converted.channel8 = (float)r_channel8;

		secondary_irts_fl_1_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_IRTS_FL_1_BYTE_SIZE;
		return secondary_irts_fl_1_pack(data, &tmp, SECONDARY_IRTS_FL_1_BYTE_SIZE);
	}
	case 1458:
	{
		secondary_irts_fl_2_t tmp;
		secondary_irts_fl_2_converted_t tmp_converted;
		float r_channel9;
		float r_channel10;
		float r_channel11;
		float r_channel12;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_channel9,
			&r_channel10,
			&r_channel11,
			&r_channel12);
		tmp_converted.channel9 = (float)r_channel9;
		tmp_converted.channel10 = (float)r_channel10;
		tmp_converted.channel11 = (float)r_channel11;
		tmp_converted.channel12 = (float)r_channel12;

		secondary_irts_fl_2_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_IRTS_FL_2_BYTE_SIZE;
		return secondary_irts_fl_2_pack(data, &tmp, SECONDARY_IRTS_FL_2_BYTE_SIZE);
	}
	case 1459:
	{
		secondary_irts_fl_3_t tmp;
		secondary_irts_fl_3_converted_t tmp_converted;
		float r_channel13;
		float r_channel14;
		float r_channel15;
		float r_channel16;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_channel13,
			&r_channel14,
			&r_channel15,
			&r_channel16);
		tmp_converted.channel13 = (float)r_channel13;
		tmp_converted.channel14 = (float)r_channel14;
		tmp_converted.channel15 = (float)r_channel15;
		tmp_converted.channel16 = (float)r_channel16;

		secondary_irts_fl_3_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_IRTS_FL_3_BYTE_SIZE;
		return secondary_irts_fl_3_pack(data, &tmp, SECONDARY_IRTS_FL_3_BYTE_SIZE);
	}
	case 1464:
	{
		secondary_irts_fr_0_t tmp;
		secondary_irts_fr_0_converted_t tmp_converted;
		float r_channel1;
		float r_channel2;
		float r_channel3;
		float r_channel4;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_channel1,
			&r_channel2,
			&r_channel3,
			&r_channel4);
		tmp_converted.channel1 = (float)r_channel1;
		tmp_converted.channel2 = (float)r_channel2;
		tmp_converted.channel3 = (float)r_channel3;
		tmp_converted.channel4 = (float)r_channel4;

		secondary_irts_fr_0_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_IRTS_FR_0_BYTE_SIZE;
		return secondary_irts_fr_0_pack(data, &tmp, SECONDARY_IRTS_FR_0_BYTE_SIZE);
	}
	case 1465:
	{
		secondary_irts_fr_1_t tmp;
		secondary_irts_fr_1_converted_t tmp_converted;
		float r_channel5;
		float r_channel6;
		float r_channel7;
		float r_channel8;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_channel5,
			&r_channel6,
			&r_channel7,
			&r_channel8);
		tmp_converted.channel5 = (float)r_channel5;
		tmp_converted.channel6 = (float)r_channel6;
		tmp_converted.channel7 = (float)r_channel7;
		tmp_converted.channel8 = (float)r_channel8;

		secondary_irts_fr_1_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_IRTS_FR_1_BYTE_SIZE;
		return secondary_irts_fr_1_pack(data, &tmp, SECONDARY_IRTS_FR_1_BYTE_SIZE);
	}
	case 1466:
	{
		secondary_irts_fr_2_t tmp;
		secondary_irts_fr_2_converted_t tmp_converted;
		float r_channel9;
		float r_channel10;
		float r_channel11;
		float r_channel12;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_channel9,
			&r_channel10,
			&r_channel11,
			&r_channel12);
		tmp_converted.channel9 = (float)r_channel9;
		tmp_converted.channel10 = (float)r_channel10;
		tmp_converted.channel11 = (float)r_channel11;
		tmp_converted.channel12 = (float)r_channel12;

		secondary_irts_fr_2_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_IRTS_FR_2_BYTE_SIZE;
		return secondary_irts_fr_2_pack(data, &tmp, SECONDARY_IRTS_FR_2_BYTE_SIZE);
	}
	case 1467:
	{
		secondary_irts_fr_3_t tmp;
		secondary_irts_fr_3_converted_t tmp_converted;
		float r_channel13;
		float r_channel14;
		float r_channel15;
		float r_channel16;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_channel13,
			&r_channel14,
			&r_channel15,
			&r_channel16);
		tmp_converted.channel13 = (float)r_channel13;
		tmp_converted.channel14 = (float)r_channel14;
		tmp_converted.channel15 = (float)r_channel15;
		tmp_converted.channel16 = (float)r_channel16;

		secondary_irts_fr_3_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_IRTS_FR_3_BYTE_SIZE;
		return secondary_irts_fr_3_pack(data, &tmp, SECONDARY_IRTS_FR_3_BYTE_SIZE);
	}
	case 1468:
	{
		secondary_irts_rl_0_t tmp;
		secondary_irts_rl_0_converted_t tmp_converted;
		float r_channel1;
		float r_channel2;
		float r_channel3;
		float r_channel4;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_channel1,
			&r_channel2,
			&r_channel3,
			&r_channel4);
		tmp_converted.channel1 = (float)r_channel1;
		tmp_converted.channel2 = (float)r_channel2;
		tmp_converted.channel3 = (float)r_channel3;
		tmp_converted.channel4 = (float)r_channel4;

		secondary_irts_rl_0_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_IRTS_RL_0_BYTE_SIZE;
		return secondary_irts_rl_0_pack(data, &tmp, SECONDARY_IRTS_RL_0_BYTE_SIZE);
	}
	case 1469:
	{
		secondary_irts_rl_1_t tmp;
		secondary_irts_rl_1_converted_t tmp_converted;
		float r_channel5;
		float r_channel6;
		float r_channel7;
		float r_channel8;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_channel5,
			&r_channel6,
			&r_channel7,
			&r_channel8);
		tmp_converted.channel5 = (float)r_channel5;
		tmp_converted.channel6 = (float)r_channel6;
		tmp_converted.channel7 = (float)r_channel7;
		tmp_converted.channel8 = (float)r_channel8;

		secondary_irts_rl_1_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_IRTS_RL_1_BYTE_SIZE;
		return secondary_irts_rl_1_pack(data, &tmp, SECONDARY_IRTS_RL_1_BYTE_SIZE);
	}
	case 1470:
	{
		secondary_irts_rl_2_t tmp;
		secondary_irts_rl_2_converted_t tmp_converted;
		float r_channel9;
		float r_channel10;
		float r_channel11;
		float r_channel12;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_channel9,
			&r_channel10,
			&r_channel11,
			&r_channel12);
		tmp_converted.channel9 = (float)r_channel9;
		tmp_converted.channel10 = (float)r_channel10;
		tmp_converted.channel11 = (float)r_channel11;
		tmp_converted.channel12 = (float)r_channel12;

		secondary_irts_rl_2_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_IRTS_RL_2_BYTE_SIZE;
		return secondary_irts_rl_2_pack(data, &tmp, SECONDARY_IRTS_RL_2_BYTE_SIZE);
	}
	case 1471:
	{
		secondary_irts_rl_3_t tmp;
		secondary_irts_rl_3_converted_t tmp_converted;
		float r_channel13;
		float r_channel14;
		float r_channel15;
		float r_channel16;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_channel13,
			&r_channel14,
			&r_channel15,
			&r_channel16);
		tmp_converted.channel13 = (float)r_channel13;
		tmp_converted.channel14 = (float)r_channel14;
		tmp_converted.channel15 = (float)r_channel15;
		tmp_converted.channel16 = (float)r_channel16;

		secondary_irts_rl_3_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_IRTS_RL_3_BYTE_SIZE;
		return secondary_irts_rl_3_pack(data, &tmp, SECONDARY_IRTS_RL_3_BYTE_SIZE);
	}
	case 1200:
	{
		secondary_irts_rr_0_t tmp;
		secondary_irts_rr_0_converted_t tmp_converted;
		float r_channel1;
		float r_channel2;
		float r_channel3;
		float r_channel4;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_channel1,
			&r_channel2,
			&r_channel3,
			&r_channel4);
		tmp_converted.channel1 = (float)r_channel1;
		tmp_converted.channel2 = (float)r_channel2;
		tmp_converted.channel3 = (float)r_channel3;
		tmp_converted.channel4 = (float)r_channel4;

		secondary_irts_rr_0_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_IRTS_RR_0_BYTE_SIZE;
		return secondary_irts_rr_0_pack(data, &tmp, SECONDARY_IRTS_RR_0_BYTE_SIZE);
	}
	case 1201:
	{
		secondary_irts_rr_1_t tmp;
		secondary_irts_rr_1_converted_t tmp_converted;
		float r_channel5;
		float r_channel6;
		float r_channel7;
		float r_channel8;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_channel5,
			&r_channel6,
			&r_channel7,
			&r_channel8);
		tmp_converted.channel5 = (float)r_channel5;
		tmp_converted.channel6 = (float)r_channel6;
		tmp_converted.channel7 = (float)r_channel7;
		tmp_converted.channel8 = (float)r_channel8;

		secondary_irts_rr_1_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_IRTS_RR_1_BYTE_SIZE;
		return secondary_irts_rr_1_pack(data, &tmp, SECONDARY_IRTS_RR_1_BYTE_SIZE);
	}
	case 1202:
	{
		secondary_irts_rr_2_t tmp;
		secondary_irts_rr_2_converted_t tmp_converted;
		float r_channel9;
		float r_channel10;
		float r_channel11;
		float r_channel12;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_channel9,
			&r_channel10,
			&r_channel11,
			&r_channel12);
		tmp_converted.channel9 = (float)r_channel9;
		tmp_converted.channel10 = (float)r_channel10;
		tmp_converted.channel11 = (float)r_channel11;
		tmp_converted.channel12 = (float)r_channel12;

		secondary_irts_rr_2_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_IRTS_RR_2_BYTE_SIZE;
		return secondary_irts_rr_2_pack(data, &tmp, SECONDARY_IRTS_RR_2_BYTE_SIZE);
	}
	case 1203:
	{
		secondary_irts_rr_3_t tmp;
		secondary_irts_rr_3_converted_t tmp_converted;
		float r_channel13;
		float r_channel14;
		float r_channel15;
		float r_channel16;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_channel13,
			&r_channel14,
			&r_channel15,
			&r_channel16);
		tmp_converted.channel13 = (float)r_channel13;
		tmp_converted.channel14 = (float)r_channel14;
		tmp_converted.channel15 = (float)r_channel15;
		tmp_converted.channel16 = (float)r_channel16;

		secondary_irts_rr_3_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_IRTS_RR_3_BYTE_SIZE;
		return secondary_irts_rr_3_pack(data, &tmp, SECONDARY_IRTS_RR_3_BYTE_SIZE);
	}
	case 1027:
	{
		secondary_gps_coords_t tmp;
		secondary_gps_coords_converted_t tmp_converted;
		uint32_t r_latitude;
		uint32_t r_longitude;

		sscanf(s, "%" SCNu32 "," 
			"%" SCNu32 "," ,
			&r_latitude,
			&r_longitude);
		tmp_converted.latitude = (uint32_t)r_latitude;
		tmp_converted.longitude = (uint32_t)r_longitude;

		secondary_gps_coords_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_GPS_COORDS_BYTE_SIZE;
		return secondary_gps_coords_pack(data, &tmp, SECONDARY_GPS_COORDS_BYTE_SIZE);
	}
	case 1059:
	{
		secondary_gps_speed_t tmp;
		secondary_gps_speed_converted_t tmp_converted;
		uint16_t r_speed;

		sscanf(s, "%" SCNu16 "," ,
			&r_speed);
		tmp_converted.speed = (uint16_t)r_speed;

		secondary_gps_speed_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_GPS_SPEED_BYTE_SIZE;
		return secondary_gps_speed_pack(data, &tmp, SECONDARY_GPS_SPEED_BYTE_SIZE);
	}
	case 771:
	{
		secondary_pedals_output_t tmp;
		secondary_pedals_output_converted_t tmp_converted;
		float r_apps;
		float r_bse_front;
		float r_bse_rear;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       ,
			&r_apps,
			&r_bse_front,
			&r_bse_rear);
		tmp_converted.apps = (float)r_apps;
		tmp_converted.bse_front = (float)r_bse_front;
		tmp_converted.bse_rear = (float)r_bse_rear;

		secondary_pedals_output_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_PEDALS_OUTPUT_BYTE_SIZE;
		return secondary_pedals_output_pack(data, &tmp, SECONDARY_PEDALS_OUTPUT_BYTE_SIZE);
	}
	case 260:
	{
		secondary_steering_angle_t tmp;
		secondary_steering_angle_converted_t tmp_converted;
		float r_angle;

		sscanf(s, "%f,"       ,
			&r_angle);
		tmp_converted.angle = (float)r_angle;

		secondary_steering_angle_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_STEERING_ANGLE_BYTE_SIZE;
		return secondary_steering_angle_pack(data, &tmp, SECONDARY_STEERING_ANGLE_BYTE_SIZE);
	}
	case 1281:
	{
		secondary_control_state_t tmp;
		secondary_control_state_converted_t tmp_converted;
		float r_map_pw;
		float r_map_sc;
		float r_map_tv;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       ,
			&r_map_pw,
			&r_map_sc,
			&r_map_tv);
		tmp_converted.map_pw = (float)r_map_pw;
		tmp_converted.map_sc = (float)r_map_sc;
		tmp_converted.map_tv = (float)r_map_tv;

		secondary_control_state_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_CONTROL_STATE_BYTE_SIZE;
		return secondary_control_state_pack(data, &tmp, SECONDARY_CONTROL_STATE_BYTE_SIZE);
	}
	case 515:
	{
		secondary_tpms_t tmp;
		secondary_tpms_converted_t tmp_converted;
		uint8_t r_fl_pressure;
		uint8_t r_fr_pressure;
		uint8_t r_rl_pressure;
		uint8_t r_rr_pressure;
		uint8_t r_fl_temperature;
		uint8_t r_fr_temperature;
		uint8_t r_rl_temperature;
		uint8_t r_rr_temperature;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  ,
			&r_fl_pressure,
			&r_fr_pressure,
			&r_rl_pressure,
			&r_rr_pressure,
			&r_fl_temperature,
			&r_fr_temperature,
			&r_rl_temperature,
			&r_rr_temperature);
		tmp_converted.fl_pressure = (uint8_t)r_fl_pressure;
		tmp_converted.fr_pressure = (uint8_t)r_fr_pressure;
		tmp_converted.rl_pressure = (uint8_t)r_rl_pressure;
		tmp_converted.rr_pressure = (uint8_t)r_rr_pressure;
		tmp_converted.fl_temperature = (uint8_t)r_fl_temperature;
		tmp_converted.fr_temperature = (uint8_t)r_fr_temperature;
		tmp_converted.rl_temperature = (uint8_t)r_rl_temperature;
		tmp_converted.rr_temperature = (uint8_t)r_rr_temperature;

		secondary_tpms_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_TPMS_BYTE_SIZE;
		return secondary_tpms_pack(data, &tmp, SECONDARY_TPMS_BYTE_SIZE);
	}
	case 1091:
	{
		secondary_lap_count_t tmp;
		secondary_lap_count_converted_t tmp_converted;
		uint16_t r_lap_count;
		float r_lap_time;

		sscanf(s, "%" SCNu16 "," 
			"%f,"       ,
			&r_lap_count,
			&r_lap_time);
		tmp_converted.lap_count = (uint16_t)r_lap_count;
		tmp_converted.lap_time = (float)r_lap_time;

		secondary_lap_count_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_LAP_COUNT_BYTE_SIZE;
		return secondary_lap_count_pack(data, &tmp, SECONDARY_LAP_COUNT_BYTE_SIZE);
	}
	case 770:
	{
		secondary_lc_status_t tmp;
		secondary_lc_status_converted_t tmp_converted;
		uint16_t r_lap_number;
		float r_best_time;
		float r_last_time;

		sscanf(s, "%" SCNu16 "," 
			"%f,"       
			"%f,"       ,
			&r_lap_number,
			&r_best_time,
			&r_last_time);
		tmp_converted.lap_number = (uint16_t)r_lap_number;
		tmp_converted.best_time = (float)r_best_time;
		tmp_converted.last_time = (float)r_last_time;

		secondary_lc_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_LC_STATUS_BYTE_SIZE;
		return secondary_lc_status_pack(data, &tmp, SECONDARY_LC_STATUS_BYTE_SIZE);
	}
	case 256:
	{
		secondary_timestamp_t tmp;
		secondary_timestamp_converted_t tmp_converted;
		uint64_t r_timestamp;

		sscanf(s, "%" SCNu64 "," ,
			&r_timestamp);
		tmp_converted.timestamp = (uint64_t)r_timestamp;

		secondary_timestamp_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_TIMESTAMP_BYTE_SIZE;
		return secondary_timestamp_pack(data, &tmp, SECONDARY_TIMESTAMP_BYTE_SIZE);
	}
	case 1028:
	{
		secondary_rear_ammo_pos_t tmp;
		secondary_rear_ammo_pos_converted_t tmp_converted;
		float r_rl;
		float r_rr;

		sscanf(s, "%f,"       
			"%f,"       ,
			&r_rl,
			&r_rr);
		tmp_converted.rl = (float)r_rl;
		tmp_converted.rr = (float)r_rr;

		secondary_rear_ammo_pos_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_REAR_AMMO_POS_BYTE_SIZE;
		return secondary_rear_ammo_pos_pack(data, &tmp, SECONDARY_REAR_AMMO_POS_BYTE_SIZE);
	}
	case 1060:
	{
		secondary_front_ammo_pos_t tmp;
		secondary_front_ammo_pos_converted_t tmp_converted;
		float r_fl;
		float r_fr;

		sscanf(s, "%f,"       
			"%f,"       ,
			&r_fl,
			&r_fr);
		tmp_converted.fl = (float)r_fl;
		tmp_converted.fr = (float)r_fr;

		secondary_front_ammo_pos_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_FRONT_AMMO_POS_BYTE_SIZE;
		return secondary_front_ammo_pos_pack(data, &tmp, SECONDARY_FRONT_AMMO_POS_BYTE_SIZE);
	}
	case 1092:
	{
		secondary_rod_elongation_t tmp;
		secondary_rod_elongation_converted_t tmp_converted;
		float r_deformation;

		sscanf(s, "%f,"       ,
			&r_deformation);
		tmp_converted.deformation = (float)r_deformation;

		secondary_rod_elongation_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_ROD_ELONGATION_BYTE_SIZE;
		return secondary_rod_elongation_pack(data, &tmp, SECONDARY_ROD_ELONGATION_BYTE_SIZE);
	}
	case 1024:
	{
		secondary_debug_signal_t tmp;
		secondary_debug_signal_converted_t tmp_converted;
		float r_field_1;
		float r_field_2;
		float r_field_3;
		float r_field_4;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_field_1,
			&r_field_2,
			&r_field_3,
			&r_field_4);
		tmp_converted.field_1 = (float)r_field_1;
		tmp_converted.field_2 = (float)r_field_2;
		tmp_converted.field_3 = (float)r_field_3;
		tmp_converted.field_4 = (float)r_field_4;

		secondary_debug_signal_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_DEBUG_SIGNAL_BYTE_SIZE;
		return secondary_debug_signal_pack(data, &tmp, SECONDARY_DEBUG_SIGNAL_BYTE_SIZE);
	}
	case 1124:
	{
		secondary_cooling_temp_t tmp;
		secondary_cooling_temp_converted_t tmp_converted;
		float r_top_left;
		float r_bottom_left;
		float r_top_right;
		float r_bottom_right;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_top_left,
			&r_bottom_left,
			&r_top_right,
			&r_bottom_right);
		tmp_converted.top_left = (float)r_top_left;
		tmp_converted.bottom_left = (float)r_bottom_left;
		tmp_converted.top_right = (float)r_top_right;
		tmp_converted.bottom_right = (float)r_bottom_right;

		secondary_cooling_temp_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_COOLING_TEMP_BYTE_SIZE;
		return secondary_cooling_temp_pack(data, &tmp, SECONDARY_COOLING_TEMP_BYTE_SIZE);
	}

    }
    return 0;
}
int secondary_n_fields_from_id(int id)
{
	switch(id)
    {
		case 1260: return 3;
		case 1261: return 4;
		case 1456: return 4;
		case 1457: return 4;
		case 1458: return 4;
		case 1459: return 4;
		case 1464: return 4;
		case 1465: return 4;
		case 1466: return 4;
		case 1467: return 4;
		case 1468: return 4;
		case 1469: return 4;
		case 1470: return 4;
		case 1471: return 4;
		case 1200: return 4;
		case 1201: return 4;
		case 1202: return 4;
		case 1203: return 4;
		case 1027: return 2;
		case 1059: return 1;
		case 771: return 3;
		case 260: return 1;
		case 1281: return 3;
		case 515: return 8;
		case 1091: return 2;
		case 770: return 3;
		case 256: return 1;
		case 1028: return 2;
		case 1060: return 2;
		case 1092: return 1;
		case 1024: return 4;
		case 1124: return 4;
    }
    return 0;
}
int secondary_fields_types_from_id(int id, int* fields_types, int fields_types_size)
{
    switch(id)
    {
	case 1260:
		if(fields_types_size < 3) return 0;
		fields_types[0] = e_secondary_float;
		fields_types[1] = e_secondary_float;
		fields_types[2] = e_secondary_float;
		return 3;
	case 1261:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_secondary_float;
		fields_types[1] = e_secondary_float;
		fields_types[2] = e_secondary_float;
		fields_types[3] = e_secondary_int16_t;
		return 4;
	case 1456:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_secondary_float;
		fields_types[1] = e_secondary_float;
		fields_types[2] = e_secondary_float;
		fields_types[3] = e_secondary_float;
		return 4;
	case 1457:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_secondary_float;
		fields_types[1] = e_secondary_float;
		fields_types[2] = e_secondary_float;
		fields_types[3] = e_secondary_float;
		return 4;
	case 1458:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_secondary_float;
		fields_types[1] = e_secondary_float;
		fields_types[2] = e_secondary_float;
		fields_types[3] = e_secondary_float;
		return 4;
	case 1459:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_secondary_float;
		fields_types[1] = e_secondary_float;
		fields_types[2] = e_secondary_float;
		fields_types[3] = e_secondary_float;
		return 4;
	case 1464:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_secondary_float;
		fields_types[1] = e_secondary_float;
		fields_types[2] = e_secondary_float;
		fields_types[3] = e_secondary_float;
		return 4;
	case 1465:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_secondary_float;
		fields_types[1] = e_secondary_float;
		fields_types[2] = e_secondary_float;
		fields_types[3] = e_secondary_float;
		return 4;
	case 1466:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_secondary_float;
		fields_types[1] = e_secondary_float;
		fields_types[2] = e_secondary_float;
		fields_types[3] = e_secondary_float;
		return 4;
	case 1467:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_secondary_float;
		fields_types[1] = e_secondary_float;
		fields_types[2] = e_secondary_float;
		fields_types[3] = e_secondary_float;
		return 4;
	case 1468:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_secondary_float;
		fields_types[1] = e_secondary_float;
		fields_types[2] = e_secondary_float;
		fields_types[3] = e_secondary_float;
		return 4;
	case 1469:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_secondary_float;
		fields_types[1] = e_secondary_float;
		fields_types[2] = e_secondary_float;
		fields_types[3] = e_secondary_float;
		return 4;
	case 1470:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_secondary_float;
		fields_types[1] = e_secondary_float;
		fields_types[2] = e_secondary_float;
		fields_types[3] = e_secondary_float;
		return 4;
	case 1471:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_secondary_float;
		fields_types[1] = e_secondary_float;
		fields_types[2] = e_secondary_float;
		fields_types[3] = e_secondary_float;
		return 4;
	case 1200:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_secondary_float;
		fields_types[1] = e_secondary_float;
		fields_types[2] = e_secondary_float;
		fields_types[3] = e_secondary_float;
		return 4;
	case 1201:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_secondary_float;
		fields_types[1] = e_secondary_float;
		fields_types[2] = e_secondary_float;
		fields_types[3] = e_secondary_float;
		return 4;
	case 1202:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_secondary_float;
		fields_types[1] = e_secondary_float;
		fields_types[2] = e_secondary_float;
		fields_types[3] = e_secondary_float;
		return 4;
	case 1203:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_secondary_float;
		fields_types[1] = e_secondary_float;
		fields_types[2] = e_secondary_float;
		fields_types[3] = e_secondary_float;
		return 4;
	case 1027:
		if(fields_types_size < 2) return 0;
		fields_types[0] = e_secondary_uint32_t;
		fields_types[1] = e_secondary_uint32_t;
		return 2;
	case 1059:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_secondary_uint16_t;
		return 1;
	case 771:
		if(fields_types_size < 3) return 0;
		fields_types[0] = e_secondary_float;
		fields_types[1] = e_secondary_float;
		fields_types[2] = e_secondary_float;
		return 3;
	case 260:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_secondary_float;
		return 1;
	case 1281:
		if(fields_types_size < 3) return 0;
		fields_types[0] = e_secondary_float;
		fields_types[1] = e_secondary_float;
		fields_types[2] = e_secondary_float;
		return 3;
	case 515:
		if(fields_types_size < 8) return 0;
		fields_types[0] = e_secondary_uint8_t;
		fields_types[1] = e_secondary_uint8_t;
		fields_types[2] = e_secondary_uint8_t;
		fields_types[3] = e_secondary_uint8_t;
		fields_types[4] = e_secondary_uint8_t;
		fields_types[5] = e_secondary_uint8_t;
		fields_types[6] = e_secondary_uint8_t;
		fields_types[7] = e_secondary_uint8_t;
		return 8;
	case 1091:
		if(fields_types_size < 2) return 0;
		fields_types[0] = e_secondary_uint16_t;
		fields_types[1] = e_secondary_float;
		return 2;
	case 770:
		if(fields_types_size < 3) return 0;
		fields_types[0] = e_secondary_uint16_t;
		fields_types[1] = e_secondary_float;
		fields_types[2] = e_secondary_float;
		return 3;
	case 256:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_secondary_uint64_t;
		return 1;
	case 1028:
		if(fields_types_size < 2) return 0;
		fields_types[0] = e_secondary_float;
		fields_types[1] = e_secondary_float;
		return 2;
	case 1060:
		if(fields_types_size < 2) return 0;
		fields_types[0] = e_secondary_float;
		fields_types[1] = e_secondary_float;
		return 2;
	case 1092:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_secondary_float;
		return 1;
	case 1024:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_secondary_float;
		fields_types[1] = e_secondary_float;
		fields_types[2] = e_secondary_float;
		fields_types[3] = e_secondary_float;
		return 4;
	case 1124:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_secondary_float;
		fields_types[1] = e_secondary_float;
		fields_types[2] = e_secondary_float;
		fields_types[3] = e_secondary_float;
		return 4;

    }
    return 0;
}
