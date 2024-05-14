#include "simulator_utils.h"

int simulator_fields_string_from_id(int id, char **v, size_t fields_size, size_t string_size)
{
	switch(id)
    {
	case 1260:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, IMU_ANGULAR_RATE_X);
		snprintf(v[1], string_size, IMU_ANGULAR_RATE_Y);
		snprintf(v[2], string_size, IMU_ANGULAR_RATE_Z);

		return 0;
	case 1261:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, IMU_ACCELERATION_X);
		snprintf(v[1], string_size, IMU_ACCELERATION_Y);
		snprintf(v[2], string_size, IMU_ACCELERATION_Z);
		snprintf(v[3], string_size, IMU_ACCELERATION_IMU_TEMPERATURE);

		return 0;
	case 1536:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, PEDAL_THROTTLE_THROTTLE);

		return 0;
	case 1544:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, PEDAL_BRAKES_PRESSURE_FRONT);
		snprintf(v[1], string_size, PEDAL_BRAKES_PRESSURE_REAR);

		return 0;
	case 1552:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, STEER_ANGLE_ANGLE);

		return 0;
	case 512:
		if(5 > fields_size) return 1;
		snprintf(v[0], string_size, CONTROL_OUTPUT_ESTIMATED_VELOCITY);
		snprintf(v[1], string_size, CONTROL_OUTPUT_TORQUE_MAX_L);
		snprintf(v[2], string_size, CONTROL_OUTPUT_TORQUE_MAX_R);
		snprintf(v[3], string_size, CONTROL_OUTPUT_TORQUE_L);
		snprintf(v[4], string_size, CONTROL_OUTPUT_TORQUE_R);

		return 0;
	case 520:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, CONTROL_STATUS_MAP_PW);
		snprintf(v[1], string_size, CONTROL_STATUS_MAP_SC);
		snprintf(v[2], string_size, CONTROL_STATUS_MAP_TV);

		return 0;
	case 1560:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, SPEED_FL);
		snprintf(v[1], string_size, SPEED_FR);

		return 0;
	case 1568:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, DEBUG_SIGNAL_2_FIELD_1);
		snprintf(v[1], string_size, DEBUG_SIGNAL_2_FIELD_2);
		snprintf(v[2], string_size, DEBUG_SIGNAL_2_FIELD_3);
		snprintf(v[3], string_size, DEBUG_SIGNAL_2_FIELD_4);

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
int simulator_serialize_from_string(int id, char *s, uint8_t *data, size_t *size)
{
    switch(id)
    {
	case 1260:
	{
		simulator_imu_angular_rate_t tmp;
		simulator_imu_angular_rate_converted_t tmp_converted;
		float r_x;
		float r_y;
		float r_z;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       ,
			&r_x,
			&r_y,
			&r_z);
		tmp_converted.x = (float)r_x;
		tmp_converted.y = (float)r_y;
		tmp_converted.z = (float)r_z;

		simulator_imu_angular_rate_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SIMULATOR_IMU_ANGULAR_RATE_BYTE_SIZE;
		return simulator_imu_angular_rate_pack(data, &tmp, SIMULATOR_IMU_ANGULAR_RATE_BYTE_SIZE);
	}
	case 1261:
	{
		simulator_imu_acceleration_t tmp;
		simulator_imu_acceleration_converted_t tmp_converted;
		float r_x;
		float r_y;
		float r_z;
		int16_t r_imu_temperature;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       
			"%" SCNi16 "," ,
			&r_x,
			&r_y,
			&r_z,
			&r_imu_temperature);
		tmp_converted.x = (float)r_x;
		tmp_converted.y = (float)r_y;
		tmp_converted.z = (float)r_z;
		tmp_converted.imu_temperature = (int16_t)r_imu_temperature;

		simulator_imu_acceleration_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SIMULATOR_IMU_ACCELERATION_BYTE_SIZE;
		return simulator_imu_acceleration_pack(data, &tmp, SIMULATOR_IMU_ACCELERATION_BYTE_SIZE);
	}
	case 1536:
	{
		simulator_pedal_throttle_t tmp;
		simulator_pedal_throttle_converted_t tmp_converted;
		float r_throttle;

		sscanf(s, "%f,"       ,
			&r_throttle);
		tmp_converted.throttle = (float)r_throttle;

		simulator_pedal_throttle_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SIMULATOR_PEDAL_THROTTLE_BYTE_SIZE;
		return simulator_pedal_throttle_pack(data, &tmp, SIMULATOR_PEDAL_THROTTLE_BYTE_SIZE);
	}
	case 1544:
	{
		simulator_pedal_brakes_pressure_t tmp;
		simulator_pedal_brakes_pressure_converted_t tmp_converted;
		float r_front;
		float r_rear;

		sscanf(s, "%f,"       
			"%f,"       ,
			&r_front,
			&r_rear);
		tmp_converted.front = (float)r_front;
		tmp_converted.rear = (float)r_rear;

		simulator_pedal_brakes_pressure_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SIMULATOR_PEDAL_BRAKES_PRESSURE_BYTE_SIZE;
		return simulator_pedal_brakes_pressure_pack(data, &tmp, SIMULATOR_PEDAL_BRAKES_PRESSURE_BYTE_SIZE);
	}
	case 1552:
	{
		simulator_steer_angle_t tmp;
		simulator_steer_angle_converted_t tmp_converted;
		float r_angle;

		sscanf(s, "%f,"       ,
			&r_angle);
		tmp_converted.angle = (float)r_angle;

		simulator_steer_angle_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SIMULATOR_STEER_ANGLE_BYTE_SIZE;
		return simulator_steer_angle_pack(data, &tmp, SIMULATOR_STEER_ANGLE_BYTE_SIZE);
	}
	case 512:
	{
		simulator_control_output_t tmp;
		simulator_control_output_converted_t tmp_converted;
		float r_estimated_velocity;
		float r_torque_max_l;
		float r_torque_max_r;
		float r_torque_l;
		float r_torque_r;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_estimated_velocity,
			&r_torque_max_l,
			&r_torque_max_r,
			&r_torque_l,
			&r_torque_r);
		tmp_converted.estimated_velocity = (float)r_estimated_velocity;
		tmp_converted.torque_max_l = (float)r_torque_max_l;
		tmp_converted.torque_max_r = (float)r_torque_max_r;
		tmp_converted.torque_l = (float)r_torque_l;
		tmp_converted.torque_r = (float)r_torque_r;

		simulator_control_output_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SIMULATOR_CONTROL_OUTPUT_BYTE_SIZE;
		return simulator_control_output_pack(data, &tmp, SIMULATOR_CONTROL_OUTPUT_BYTE_SIZE);
	}
	case 520:
	{
		simulator_control_status_t tmp;
		simulator_control_status_converted_t tmp_converted;
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

		simulator_control_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SIMULATOR_CONTROL_STATUS_BYTE_SIZE;
		return simulator_control_status_pack(data, &tmp, SIMULATOR_CONTROL_STATUS_BYTE_SIZE);
	}
	case 1560:
	{
		simulator_speed_t tmp;
		simulator_speed_converted_t tmp_converted;
		float r_fl;
		float r_fr;

		sscanf(s, "%f,"       
			"%f,"       ,
			&r_fl,
			&r_fr);
		tmp_converted.fl = (float)r_fl;
		tmp_converted.fr = (float)r_fr;

		simulator_speed_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SIMULATOR_SPEED_BYTE_SIZE;
		return simulator_speed_pack(data, &tmp, SIMULATOR_SPEED_BYTE_SIZE);
	}
	case 1568:
	{
		simulator_debug_signal_2_t tmp;
		simulator_debug_signal_2_converted_t tmp_converted;
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

		simulator_debug_signal_2_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SIMULATOR_DEBUG_SIGNAL_2_BYTE_SIZE;
		return simulator_debug_signal_2_pack(data, &tmp, SIMULATOR_DEBUG_SIGNAL_2_BYTE_SIZE);
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
		case 1536: return 1;
		case 1544: return 2;
		case 1552: return 1;
		case 512: return 5;
		case 520: return 3;
		case 1560: return 2;
		case 1568: return 4;
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
	case 1536:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_simulator_float;
		return 1;
	case 1544:
		if(fields_types_size < 2) return 0;
		fields_types[0] = e_simulator_float;
		fields_types[1] = e_simulator_float;
		return 2;
	case 1552:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_simulator_float;
		return 1;
	case 512:
		if(fields_types_size < 5) return 0;
		fields_types[0] = e_simulator_float;
		fields_types[1] = e_simulator_float;
		fields_types[2] = e_simulator_float;
		fields_types[3] = e_simulator_float;
		fields_types[4] = e_simulator_float;
		return 5;
	case 520:
		if(fields_types_size < 3) return 0;
		fields_types[0] = e_simulator_float;
		fields_types[1] = e_simulator_float;
		fields_types[2] = e_simulator_float;
		return 3;
	case 1560:
		if(fields_types_size < 2) return 0;
		fields_types[0] = e_simulator_float;
		fields_types[1] = e_simulator_float;
		return 2;
	case 1568:
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
