#include "simulator_utils_c.h"


int simulator_fields_string_from_id(int id, char **v, size_t fields_size, size_t string_size)
{
	switch(id)
    {
	case 1260:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, IMU_ANGULAR_RATE_ANG_RATE_X);
		snprintf(v[1], string_size, IMU_ANGULAR_RATE_ANG_RATE_Y);
		snprintf(v[2], string_size, IMU_ANGULAR_RATE_ANG_RATE_Z);

		return 0;
	case 1261:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, IMU_ACCELERATION_ACCEL_X);
		snprintf(v[1], string_size, IMU_ACCELERATION_ACCEL_Y);
		snprintf(v[2], string_size, IMU_ACCELERATION_ACCEL_Z);
		snprintf(v[3], string_size, IMU_ACCELERATION_TEMPERATURE);

		return 0;
	case 770:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, PEDALS_OUTPUT_APPS);
		snprintf(v[1], string_size, PEDALS_OUTPUT_BSE_FRONT);
		snprintf(v[2], string_size, PEDALS_OUTPUT_BSE_REAR);

		return 0;
	case 259:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, STEERING_ANGLE_ANGLE);

		return 0;
	case 1281:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, CONTROL_STATE_MAP_PW);
		snprintf(v[1], string_size, CONTROL_STATE_MAP_SC);
		snprintf(v[2], string_size, CONTROL_STATE_MAP_TV);

		return 0;
	case 258:
		if(5 > fields_size) return 1;
		snprintf(v[0], string_size, CONTROL_OUTPUT_ESTIMATED_VELOCITY);
		snprintf(v[1], string_size, CONTROL_OUTPUT_TMAX_R);
		snprintf(v[2], string_size, CONTROL_OUTPUT_TMAX_L);
		snprintf(v[3], string_size, CONTROL_OUTPUT_TORQUE_L);
		snprintf(v[4], string_size, CONTROL_OUTPUT_TORQUE_R);

		return 0;
	case 514:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, SPEED_ENCODER_L);
		snprintf(v[1], string_size, SPEED_ENCODER_R);
		snprintf(v[2], string_size, SPEED_INVERTER_L);
		snprintf(v[3], string_size, SPEED_INVERTER_R);

		return 0;
	case 1024:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, DEBUG_SIGNAL_FIELD_1);
		snprintf(v[1], string_size, DEBUG_SIGNAL_FIELD_2);
		snprintf(v[2], string_size, DEBUG_SIGNAL_FIELD_3);
		snprintf(v[3], string_size, DEBUG_SIGNAL_FIELD_4);

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
int simulator_serialize_from_id(int id, char *s, uint8_t *data, size_t *size)
{
    switch(id)
    {
	case 1260:
	{
		simulator_imu_angular_rate_t tmp;
		simulator_imu_angular_rate_converted_t tmp_converted;
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

		simulator_imu_angular_rate_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SIMULATOR_IMU_ANGULAR_RATE_BYTE_SIZE;
		return simulator_imu_angular_rate_pack(data, &tmp, SIMULATOR_IMU_ANGULAR_RATE_BYTE_SIZE);
	}
	case 1261:
	{
		simulator_imu_acceleration_t tmp;
		simulator_imu_acceleration_converted_t tmp_converted;
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

		simulator_imu_acceleration_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SIMULATOR_IMU_ACCELERATION_BYTE_SIZE;
		return simulator_imu_acceleration_pack(data, &tmp, SIMULATOR_IMU_ACCELERATION_BYTE_SIZE);
	}
	case 770:
	{
		simulator_pedals_output_t tmp;
		simulator_pedals_output_converted_t tmp_converted;
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

		simulator_pedals_output_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SIMULATOR_PEDALS_OUTPUT_BYTE_SIZE;
		return simulator_pedals_output_pack(data, &tmp, SIMULATOR_PEDALS_OUTPUT_BYTE_SIZE);
	}
	case 259:
	{
		simulator_steering_angle_t tmp;
		simulator_steering_angle_converted_t tmp_converted;
		float r_angle;

		sscanf(s, "%f,"       ,
			&r_angle);
		tmp_converted.angle = (float)r_angle;

		simulator_steering_angle_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SIMULATOR_STEERING_ANGLE_BYTE_SIZE;
		return simulator_steering_angle_pack(data, &tmp, SIMULATOR_STEERING_ANGLE_BYTE_SIZE);
	}
	case 1281:
	{
		simulator_control_state_t tmp;
		simulator_control_state_converted_t tmp_converted;
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

		simulator_control_state_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SIMULATOR_CONTROL_STATE_BYTE_SIZE;
		return simulator_control_state_pack(data, &tmp, SIMULATOR_CONTROL_STATE_BYTE_SIZE);
	}
	case 258:
	{
		simulator_control_output_t tmp;
		simulator_control_output_converted_t tmp_converted;
		float r_estimated_velocity;
		float r_tmax_r;
		float r_tmax_l;
		float r_torque_l;
		float r_torque_r;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_estimated_velocity,
			&r_tmax_r,
			&r_tmax_l,
			&r_torque_l,
			&r_torque_r);
		tmp_converted.estimated_velocity = (float)r_estimated_velocity;
		tmp_converted.tmax_r = (float)r_tmax_r;
		tmp_converted.tmax_l = (float)r_tmax_l;
		tmp_converted.torque_l = (float)r_torque_l;
		tmp_converted.torque_r = (float)r_torque_r;

		simulator_control_output_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SIMULATOR_CONTROL_OUTPUT_BYTE_SIZE;
		return simulator_control_output_pack(data, &tmp, SIMULATOR_CONTROL_OUTPUT_BYTE_SIZE);
	}
	case 514:
	{
		simulator_speed_t tmp;
		simulator_speed_converted_t tmp_converted;
		float r_encoder_l;
		float r_encoder_r;
		float r_inverter_l;
		float r_inverter_r;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_encoder_l,
			&r_encoder_r,
			&r_inverter_l,
			&r_inverter_r);
		tmp_converted.encoder_l = (float)r_encoder_l;
		tmp_converted.encoder_r = (float)r_encoder_r;
		tmp_converted.inverter_l = (float)r_inverter_l;
		tmp_converted.inverter_r = (float)r_inverter_r;

		simulator_speed_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SIMULATOR_SPEED_BYTE_SIZE;
		return simulator_speed_pack(data, &tmp, SIMULATOR_SPEED_BYTE_SIZE);
	}
	case 1024:
	{
		simulator_debug_signal_t tmp;
		simulator_debug_signal_converted_t tmp_converted;
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

		simulator_debug_signal_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SIMULATOR_DEBUG_SIGNAL_BYTE_SIZE;
		return simulator_debug_signal_pack(data, &tmp, SIMULATOR_DEBUG_SIGNAL_BYTE_SIZE);
	}

    }
    return 0;
}
int simulator_n_fields_from_id(int id)
{
	switch(id)
    {
		case 1260: return 3;
		case 1261: return 4;
		case 770: return 3;
		case 259: return 1;
		case 1281: return 3;
		case 258: return 5;
		case 514: return 4;
		case 1024: return 4;
    }
    return 0;
}
int simulator_fields_types_from_id(int id, int* fields_types, int fields_types_size)
{
    switch(id)
    {
	case 1260:
		if(fields_types_size < 3) return 0;
		fields_types[0] = e_simulator_float;
		fields_types[1] = e_simulator_float;
		fields_types[2] = e_simulator_float;
		return 3;
	case 1261:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_simulator_float;
		fields_types[1] = e_simulator_float;
		fields_types[2] = e_simulator_float;
		fields_types[3] = e_simulator_int16_t;
		return 4;
	case 770:
		if(fields_types_size < 3) return 0;
		fields_types[0] = e_simulator_float;
		fields_types[1] = e_simulator_float;
		fields_types[2] = e_simulator_float;
		return 3;
	case 259:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_simulator_float;
		return 1;
	case 1281:
		if(fields_types_size < 3) return 0;
		fields_types[0] = e_simulator_float;
		fields_types[1] = e_simulator_float;
		fields_types[2] = e_simulator_float;
		return 3;
	case 258:
		if(fields_types_size < 5) return 0;
		fields_types[0] = e_simulator_float;
		fields_types[1] = e_simulator_float;
		fields_types[2] = e_simulator_float;
		fields_types[3] = e_simulator_float;
		fields_types[4] = e_simulator_float;
		return 5;
	case 514:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_simulator_float;
		fields_types[1] = e_simulator_float;
		fields_types[2] = e_simulator_float;
		fields_types[3] = e_simulator_float;
		return 4;
	case 1024:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_simulator_float;
		fields_types[1] = e_simulator_float;
		fields_types[2] = e_simulator_float;
		fields_types[3] = e_simulator_float;
		return 4;

    }
    return 0;
}
int simulator_enum_fields_from_name(const char *msg_name, const char *sgn_name, char **v)
{
	return 0;
}
