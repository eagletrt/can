#include "simulator_utils_c.h"


int simulator_fields_string_from_id(int id, char **v, size_t fields_size, size_t string_size)
{
	switch(id)
    {
	case 1260:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, simulator_imu_angular_rate_ang_rate_x_string);
		snprintf(v[1], string_size, simulator_imu_angular_rate_ang_rate_y_string);
		snprintf(v[2], string_size, simulator_imu_angular_rate_ang_rate_z_string);

		return 0;
	case 1261:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, simulator_imu_acceleration_accel_x_string);
		snprintf(v[1], string_size, simulator_imu_acceleration_accel_y_string);
		snprintf(v[2], string_size, simulator_imu_acceleration_accel_z_string);
		snprintf(v[3], string_size, simulator_imu_acceleration_temperature_string);

		return 0;
	case 770:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, simulator_pedals_output_apps_string);
		snprintf(v[1], string_size, simulator_pedals_output_bse_front_string);
		snprintf(v[2], string_size, simulator_pedals_output_bse_rear_string);

		return 0;
	case 259:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, simulator_steering_angle_angle_string);

		return 0;
	case 1281:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, simulator_control_state_map_pw_string);
		snprintf(v[1], string_size, simulator_control_state_map_sc_string);
		snprintf(v[2], string_size, simulator_control_state_map_tv_string);

		return 0;
	case 258:
		if(5 > fields_size) return 1;
		snprintf(v[0], string_size, simulator_control_output_estimated_velocity_string);
		snprintf(v[1], string_size, simulator_control_output_tmax_r_string);
		snprintf(v[2], string_size, simulator_control_output_tmax_l_string);
		snprintf(v[3], string_size, simulator_control_output_torque_l_string);
		snprintf(v[4], string_size, simulator_control_output_torque_r_string);

		return 0;
	case 514:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, simulator_speed_encoder_l_string);
		snprintf(v[1], string_size, simulator_speed_encoder_r_string);
		snprintf(v[2], string_size, simulator_speed_inverter_l_string);
		snprintf(v[3], string_size, simulator_speed_inverter_r_string);

		return 0;
	case 1024:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, simulator_debug_signal_field_1_string);
		snprintf(v[1], string_size, simulator_debug_signal_field_2_string);
		snprintf(v[2], string_size, simulator_debug_signal_field_3_string);
		snprintf(v[3], string_size, simulator_debug_signal_field_4_string);

		return 0;

    }
    return 0;
}
int simulator_enum_fields(int enum_id, char **v, size_t fields_size, size_t string_size)
{
    switch(enum_id)
    {

    }
    return 0;
}
int simulator_serialize_from_id(int id, char *s, uint8_t *data, size_t size)
{
    switch(id)
    {
	case 1260:
	{
		simulator_imu_angular_rate_t tmp;
		simulator_imu_angular_rate_converted_t tmp_converted;
		sscanf(s, """%f"
			"""%f"
			"""%f"
			"",
			tmp.ang_rate_x,
			tmp.ang_rate_y,
			tmp.ang_rate_z);
		simulator_imu_angular_rate_conversion_to_raw_struct(&tmp, &tmp_converted);
		return simulator_imu_angular_rate_pack(data, &tmp, size);
	}
	case 1261:
	{
		simulator_imu_acceleration_t tmp;
		simulator_imu_acceleration_converted_t tmp_converted;
		sscanf(s, """%f"
			"""%f"
			"""%f"
			"%" PRIi16 
			"",
			tmp.accel_x,
			tmp.accel_y,
			tmp.accel_z,
			tmp.temperature);
		simulator_imu_acceleration_conversion_to_raw_struct(&tmp, &tmp_converted);
		return simulator_imu_acceleration_pack(data, &tmp, size);
	}
	case 770:
	{
		simulator_pedals_output_t tmp;
		simulator_pedals_output_converted_t tmp_converted;
		sscanf(s, """%f"
			"""%f"
			"""%f"
			"",
			tmp.apps,
			tmp.bse_front,
			tmp.bse_rear);
		simulator_pedals_output_conversion_to_raw_struct(&tmp, &tmp_converted);
		return simulator_pedals_output_pack(data, &tmp, size);
	}
	case 259:
	{
		simulator_steering_angle_t tmp;
		simulator_steering_angle_converted_t tmp_converted;
		sscanf(s, """%f"
			"",
			tmp.angle);
		simulator_steering_angle_conversion_to_raw_struct(&tmp, &tmp_converted);
		return simulator_steering_angle_pack(data, &tmp, size);
	}
	case 1281:
	{
		simulator_control_state_t tmp;
		simulator_control_state_converted_t tmp_converted;
		sscanf(s, """%f"
			"""%f"
			"""%f"
			"",
			tmp.map_pw,
			tmp.map_sc,
			tmp.map_tv);
		simulator_control_state_conversion_to_raw_struct(&tmp, &tmp_converted);
		return simulator_control_state_pack(data, &tmp, size);
	}
	case 258:
	{
		simulator_control_output_t tmp;
		simulator_control_output_converted_t tmp_converted;
		sscanf(s, """%f"
			"""%f"
			"""%f"
			"""%f"
			"""%f"
			"",
			tmp.estimated_velocity,
			tmp.tmax_r,
			tmp.tmax_l,
			tmp.torque_l,
			tmp.torque_r);
		simulator_control_output_conversion_to_raw_struct(&tmp, &tmp_converted);
		return simulator_control_output_pack(data, &tmp, size);
	}
	case 514:
	{
		simulator_speed_t tmp;
		simulator_speed_converted_t tmp_converted;
		sscanf(s, """%f"
			"""%f"
			"""%f"
			"""%f"
			"",
			tmp.encoder_l,
			tmp.encoder_r,
			tmp.inverter_l,
			tmp.inverter_r);
		simulator_speed_conversion_to_raw_struct(&tmp, &tmp_converted);
		return simulator_speed_pack(data, &tmp, size);
	}
	case 1024:
	{
		simulator_debug_signal_t tmp;
		simulator_debug_signal_converted_t tmp_converted;
		sscanf(s, """%f"
			"""%f"
			"""%f"
			"""%f"
			"",
			tmp.field_1,
			tmp.field_2,
			tmp.field_3,
			tmp.field_4);
		simulator_debug_signal_conversion_to_raw_struct(&tmp, &tmp_converted);
		return simulator_debug_signal_pack(data, &tmp, size);
	}

    }
    return 0;
}