#include "simulator_utils.hpp"

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
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, CONTROL_STATUS_MAP_PW);
		snprintf(v[1], string_size, CONTROL_STATUS_SC_STATE);
		snprintf(v[2], string_size, CONTROL_STATUS_TV_STATE);
		snprintf(v[3], string_size, CONTROL_STATUS_REG_STATE);

		return 0;
	case 1560:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, FRONT_ANGULAR_VELOCITY_FL);
		snprintf(v[1], string_size, FRONT_ANGULAR_VELOCITY_FR);

		return 0;
	case 1568:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, DEBUG_SIGNAL_2_FIELD_1);
		snprintf(v[1], string_size, DEBUG_SIGNAL_2_FIELD_2);
		snprintf(v[2], string_size, DEBUG_SIGNAL_2_FIELD_3);
		snprintf(v[3], string_size, DEBUG_SIGNAL_2_FIELD_4);

		return 0;
	case 1576:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, INV_L_RCV_N_ACTUAL_FILT);
		snprintf(v[1], string_size, INV_L_RCV_M_SETDIG__IQ);

		return 0;
	case 1584:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, INV_R_RCV_N_ACTUAL_FILT);
		snprintf(v[1], string_size, INV_R_RCV_M_SETDIG__IQ);

		return 0;
	case 1592:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, AS_COMMANDS_STATUS_STEERSTATUS);
		snprintf(v[1], string_size, AS_COMMANDS_STATUS_THROTTLESTATUS);
		snprintf(v[2], string_size, AS_COMMANDS_STATUS_BRAKESTATUS);

		return 0;
	case 1024:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, AS_COMMANDS_SET_STATUS_STEERSTATUS);
		snprintf(v[1], string_size, AS_COMMANDS_SET_STATUS_THROTTLESTATUS);
		snprintf(v[2], string_size, AS_COMMANDS_SET_STATUS_BRAKESTATUS);

		return 0;
	case 1600:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, AS_COMMANDS_SET_VALUE_STEERANGLE);
		snprintf(v[1], string_size, AS_COMMANDS_SET_VALUE_THROTTLE);
		snprintf(v[2], string_size, AS_COMMANDS_SET_VALUE_BRAKE);

		return 0;
	case 1608:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, VEHICLE_POSITION_X);
		snprintf(v[1], string_size, VEHICLE_POSITION_Y);
		snprintf(v[2], string_size, VEHICLE_POSITION_HEADING);

		return 0;
	case 1616:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, VEHICLE_SPEED_U);
		snprintf(v[1], string_size, VEHICLE_SPEED_V);

		return 0;

    }
    return 0;
}
int simulator_enum_fields(int enum_id, char **v, size_t fields_size, size_t string_size)
{
    switch(enum_id)
    {
	case 0:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "simulator_control_status_sc_state_off");
		snprintf(v[1], string_size, "simulator_control_status_sc_state_on");

		return 0;
	case 1:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "simulator_control_status_tv_state_off");
		snprintf(v[1], string_size, "simulator_control_status_tv_state_on");

		return 0;
	case 2:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "simulator_control_status_reg_state_off");
		snprintf(v[1], string_size, "simulator_control_status_reg_state_on");

		return 0;
	case 3:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "simulator_as_commands_status_steerstatus_off");
		snprintf(v[1], string_size, "simulator_as_commands_status_steerstatus_on");

		return 0;
	case 4:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "simulator_as_commands_status_throttlestatus_off");
		snprintf(v[1], string_size, "simulator_as_commands_status_throttlestatus_on");

		return 0;
	case 5:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "simulator_as_commands_status_brakestatus_off");
		snprintf(v[1], string_size, "simulator_as_commands_status_brakestatus_on");

		return 0;
	case 6:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "simulator_as_commands_set_status_steerstatus_off");
		snprintf(v[1], string_size, "simulator_as_commands_set_status_steerstatus_on");

		return 0;
	case 7:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "simulator_as_commands_set_status_throttlestatus_off");
		snprintf(v[1], string_size, "simulator_as_commands_set_status_throttlestatus_on");

		return 0;
	case 8:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "simulator_as_commands_set_status_brakestatus_off");
		snprintf(v[1], string_size, "simulator_as_commands_set_status_brakestatus_on");

		return 0;

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
		uint8_t r_sc_state;
		uint8_t r_tv_state;
		uint8_t r_reg_state;

		sscanf(s, "%f,"       
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  ,
			&r_map_pw,
			&r_sc_state,
			&r_tv_state,
			&r_reg_state);
		tmp_converted.map_pw = (float)r_map_pw;
		tmp_converted.sc_state = (simulator_control_status_sc_state)r_sc_state;
		tmp_converted.tv_state = (simulator_control_status_tv_state)r_tv_state;
		tmp_converted.reg_state = (simulator_control_status_reg_state)r_reg_state;

		simulator_control_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SIMULATOR_CONTROL_STATUS_BYTE_SIZE;
		return simulator_control_status_pack(data, &tmp, SIMULATOR_CONTROL_STATUS_BYTE_SIZE);
	}
	case 1560:
	{
		simulator_front_angular_velocity_t tmp;
		simulator_front_angular_velocity_converted_t tmp_converted;
		float r_fl;
		float r_fr;

		sscanf(s, "%f,"       
			"%f,"       ,
			&r_fl,
			&r_fr);
		tmp_converted.fl = (float)r_fl;
		tmp_converted.fr = (float)r_fr;

		simulator_front_angular_velocity_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SIMULATOR_FRONT_ANGULAR_VELOCITY_BYTE_SIZE;
		return simulator_front_angular_velocity_pack(data, &tmp, SIMULATOR_FRONT_ANGULAR_VELOCITY_BYTE_SIZE);
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
	case 1576:
	{
		simulator_inv_l_rcv_t tmp;
		simulator_inv_l_rcv_converted_t tmp_converted;
		float r_n_actual_filt;
		float r_m_setdig__iq;

		sscanf(s, "%f,"       
			"%f,"       ,
			&r_n_actual_filt,
			&r_m_setdig__iq);
		tmp_converted.n_actual_filt = (float)r_n_actual_filt;
		tmp_converted.m_setdig__iq = (float)r_m_setdig__iq;

		simulator_inv_l_rcv_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SIMULATOR_INV_L_RCV_BYTE_SIZE;
		return simulator_inv_l_rcv_pack(data, &tmp, SIMULATOR_INV_L_RCV_BYTE_SIZE);
	}
	case 1584:
	{
		simulator_inv_r_rcv_t tmp;
		simulator_inv_r_rcv_converted_t tmp_converted;
		float r_n_actual_filt;
		float r_m_setdig__iq;

		sscanf(s, "%f,"       
			"%f,"       ,
			&r_n_actual_filt,
			&r_m_setdig__iq);
		tmp_converted.n_actual_filt = (float)r_n_actual_filt;
		tmp_converted.m_setdig__iq = (float)r_m_setdig__iq;

		simulator_inv_r_rcv_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SIMULATOR_INV_R_RCV_BYTE_SIZE;
		return simulator_inv_r_rcv_pack(data, &tmp, SIMULATOR_INV_R_RCV_BYTE_SIZE);
	}
	case 1592:
	{
		simulator_as_commands_status_t tmp;
		simulator_as_commands_status_converted_t tmp_converted;
		uint8_t r_steerstatus;
		uint8_t r_throttlestatus;
		uint8_t r_brakestatus;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  ,
			&r_steerstatus,
			&r_throttlestatus,
			&r_brakestatus);
		tmp_converted.steerstatus = (simulator_as_commands_status_steerstatus)r_steerstatus;
		tmp_converted.throttlestatus = (simulator_as_commands_status_throttlestatus)r_throttlestatus;
		tmp_converted.brakestatus = (simulator_as_commands_status_brakestatus)r_brakestatus;

		simulator_as_commands_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SIMULATOR_AS_COMMANDS_STATUS_BYTE_SIZE;
		return simulator_as_commands_status_pack(data, &tmp, SIMULATOR_AS_COMMANDS_STATUS_BYTE_SIZE);
	}
	case 1024:
	{
		simulator_as_commands_set_status_t tmp;
		simulator_as_commands_set_status_converted_t tmp_converted;
		uint8_t r_steerstatus;
		uint8_t r_throttlestatus;
		uint8_t r_brakestatus;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  ,
			&r_steerstatus,
			&r_throttlestatus,
			&r_brakestatus);
		tmp_converted.steerstatus = (simulator_as_commands_set_status_steerstatus)r_steerstatus;
		tmp_converted.throttlestatus = (simulator_as_commands_set_status_throttlestatus)r_throttlestatus;
		tmp_converted.brakestatus = (simulator_as_commands_set_status_brakestatus)r_brakestatus;

		simulator_as_commands_set_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SIMULATOR_AS_COMMANDS_SET_STATUS_BYTE_SIZE;
		return simulator_as_commands_set_status_pack(data, &tmp, SIMULATOR_AS_COMMANDS_SET_STATUS_BYTE_SIZE);
	}
	case 1600:
	{
		simulator_as_commands_set_value_t tmp;
		simulator_as_commands_set_value_converted_t tmp_converted;
		float r_steerangle;
		float r_throttle;
		float r_brake;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       ,
			&r_steerangle,
			&r_throttle,
			&r_brake);
		tmp_converted.steerangle = (float)r_steerangle;
		tmp_converted.throttle = (float)r_throttle;
		tmp_converted.brake = (float)r_brake;

		simulator_as_commands_set_value_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SIMULATOR_AS_COMMANDS_SET_VALUE_BYTE_SIZE;
		return simulator_as_commands_set_value_pack(data, &tmp, SIMULATOR_AS_COMMANDS_SET_VALUE_BYTE_SIZE);
	}
	case 1608:
	{
		simulator_vehicle_position_t tmp;
		simulator_vehicle_position_converted_t tmp_converted;
		float r_x;
		float r_y;
		float r_heading;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       ,
			&r_x,
			&r_y,
			&r_heading);
		tmp_converted.x = (float)r_x;
		tmp_converted.y = (float)r_y;
		tmp_converted.heading = (float)r_heading;

		simulator_vehicle_position_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SIMULATOR_VEHICLE_POSITION_BYTE_SIZE;
		return simulator_vehicle_position_pack(data, &tmp, SIMULATOR_VEHICLE_POSITION_BYTE_SIZE);
	}
	case 1616:
	{
		simulator_vehicle_speed_t tmp;
		simulator_vehicle_speed_converted_t tmp_converted;
		float r_u;
		float r_v;

		sscanf(s, "%f,"       
			"%f,"       ,
			&r_u,
			&r_v);
		tmp_converted.u = (float)r_u;
		tmp_converted.v = (float)r_v;

		simulator_vehicle_speed_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SIMULATOR_VEHICLE_SPEED_BYTE_SIZE;
		return simulator_vehicle_speed_pack(data, &tmp, SIMULATOR_VEHICLE_SPEED_BYTE_SIZE);
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
		case 520: return 4;
		case 1560: return 2;
		case 1568: return 4;
		case 1576: return 2;
		case 1584: return 2;
		case 1592: return 3;
		case 1024: return 3;
		case 1600: return 3;
		case 1608: return 3;
		case 1616: return 2;
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
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_simulator_float;
		fields_types[1] = e_simulator_control_status_sc_state;
		fields_types[2] = e_simulator_control_status_tv_state;
		fields_types[3] = e_simulator_control_status_reg_state;
		return 4;
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
	case 1576:
		if(fields_types_size < 2) return 0;
		fields_types[0] = e_simulator_float;
		fields_types[1] = e_simulator_float;
		return 2;
	case 1584:
		if(fields_types_size < 2) return 0;
		fields_types[0] = e_simulator_float;
		fields_types[1] = e_simulator_float;
		return 2;
	case 1592:
		if(fields_types_size < 3) return 0;
		fields_types[0] = e_simulator_as_commands_status_steerstatus;
		fields_types[1] = e_simulator_as_commands_status_throttlestatus;
		fields_types[2] = e_simulator_as_commands_status_brakestatus;
		return 3;
	case 1024:
		if(fields_types_size < 3) return 0;
		fields_types[0] = e_simulator_as_commands_set_status_steerstatus;
		fields_types[1] = e_simulator_as_commands_set_status_throttlestatus;
		fields_types[2] = e_simulator_as_commands_set_status_brakestatus;
		return 3;
	case 1600:
		if(fields_types_size < 3) return 0;
		fields_types[0] = e_simulator_float;
		fields_types[1] = e_simulator_float;
		fields_types[2] = e_simulator_float;
		return 3;
	case 1608:
		if(fields_types_size < 3) return 0;
		fields_types[0] = e_simulator_float;
		fields_types[1] = e_simulator_float;
		fields_types[2] = e_simulator_float;
		return 3;
	case 1616:
		if(fields_types_size < 2) return 0;
		fields_types[0] = e_simulator_float;
		fields_types[1] = e_simulator_float;
		return 2;

    }
    return 0;
}
std::vector<std::string> simulator_enum_fields_from_message(const std::string& msg_name)
{
	std::vector<std::string> ret;

	if(msg_name == CONTROL_STATUS) {
		ret.push_back("sc_state");
		ret.push_back("tv_state");
		ret.push_back("reg_state");
	}
	if(msg_name == AS_COMMANDS_STATUS) {
		ret.push_back("steerstatus");
		ret.push_back("throttlestatus");
		ret.push_back("brakestatus");
	}
	if(msg_name == AS_COMMANDS_SET_STATUS) {
		ret.push_back("steerstatus");
		ret.push_back("throttlestatus");
		ret.push_back("brakestatus");
	}

	return ret;
}
std::vector<std::string> simulator_enum_names_from_fields(const std::string& msg_name, const std::string& sgn_name)
{
	std::vector<std::string> ret;

	if(msg_name == CONTROL_STATUS)
	{
		if(sgn_name == "sc_state")
		{
			ret.push_back("off");
			ret.push_back("on");
			return ret;
		}
		if(sgn_name == "tv_state")
		{
			ret.push_back("off");
			ret.push_back("on");
			return ret;
		}
		if(sgn_name == "reg_state")
		{
			ret.push_back("off");
			ret.push_back("on");
			return ret;
		}
	}
	if(msg_name == AS_COMMANDS_STATUS)
	{
		if(sgn_name == "steerstatus")
		{
			ret.push_back("off");
			ret.push_back("on");
			return ret;
		}
		if(sgn_name == "throttlestatus")
		{
			ret.push_back("off");
			ret.push_back("on");
			return ret;
		}
		if(sgn_name == "brakestatus")
		{
			ret.push_back("off");
			ret.push_back("on");
			return ret;
		}
	}
	if(msg_name == AS_COMMANDS_SET_STATUS)
	{
		if(sgn_name == "steerstatus")
		{
			ret.push_back("off");
			ret.push_back("on");
			return ret;
		}
		if(sgn_name == "throttlestatus")
		{
			ret.push_back("off");
			ret.push_back("on");
			return ret;
		}
		if(sgn_name == "brakestatus")
		{
			ret.push_back("off");
			ret.push_back("on");
			return ret;
		}
	}

	return ret;
}
