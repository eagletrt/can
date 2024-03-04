#ifndef SIMULATOR_UTILS_C_H

#define SIMULATOR_UTILS_C_H

#include <stddef.h>
#include "simulator_network.h"

/* START */
#define simulator_imu_angular_rate_string "SIMULATOR_IMU_ANGULAR_RATE"

#define simulator_imu_angular_rate_ang_rate_x_string "SIMULATOR_IMU_ANGULAR_RATE_ANG_RATE_X"
#define simulator_imu_angular_rate_ang_rate_y_string "SIMULATOR_IMU_ANGULAR_RATE_ANG_RATE_Y"
#define simulator_imu_angular_rate_ang_rate_z_string "SIMULATOR_IMU_ANGULAR_RATE_ANG_RATE_Z"
/* END */

/* START */
#define simulator_imu_acceleration_string "SIMULATOR_IMU_ACCELERATION"

#define simulator_imu_acceleration_accel_x_string "SIMULATOR_IMU_ACCELERATION_ACCEL_X"
#define simulator_imu_acceleration_accel_y_string "SIMULATOR_IMU_ACCELERATION_ACCEL_Y"
#define simulator_imu_acceleration_accel_z_string "SIMULATOR_IMU_ACCELERATION_ACCEL_Z"
#define simulator_imu_acceleration_temperature_string "SIMULATOR_IMU_ACCELERATION_TEMPERATURE"
/* END */

/* START */
#define simulator_pedals_output_string "SIMULATOR_PEDALS_OUTPUT"

#define simulator_pedals_output_apps_string "SIMULATOR_PEDALS_OUTPUT_APPS"
#define simulator_pedals_output_bse_front_string "SIMULATOR_PEDALS_OUTPUT_BSE_FRONT"
#define simulator_pedals_output_bse_rear_string "SIMULATOR_PEDALS_OUTPUT_BSE_REAR"
/* END */

/* START */
#define simulator_steering_angle_string "SIMULATOR_STEERING_ANGLE"

#define simulator_steering_angle_angle_string "SIMULATOR_STEERING_ANGLE_ANGLE"
/* END */

/* START */
#define simulator_control_state_string "SIMULATOR_CONTROL_STATE"

#define simulator_control_state_map_pw_string "SIMULATOR_CONTROL_STATE_MAP_PW"
#define simulator_control_state_map_sc_string "SIMULATOR_CONTROL_STATE_MAP_SC"
#define simulator_control_state_map_tv_string "SIMULATOR_CONTROL_STATE_MAP_TV"
/* END */

/* START */
#define simulator_control_output_string "SIMULATOR_CONTROL_OUTPUT"

#define simulator_control_output_estimated_velocity_string "SIMULATOR_CONTROL_OUTPUT_ESTIMATED_VELOCITY"
#define simulator_control_output_tmax_r_string "SIMULATOR_CONTROL_OUTPUT_TMAX_R"
#define simulator_control_output_tmax_l_string "SIMULATOR_CONTROL_OUTPUT_TMAX_L"
#define simulator_control_output_torque_l_string "SIMULATOR_CONTROL_OUTPUT_TORQUE_L"
#define simulator_control_output_torque_r_string "SIMULATOR_CONTROL_OUTPUT_TORQUE_R"
/* END */

/* START */
#define simulator_speed_string "SIMULATOR_SPEED"

#define simulator_speed_encoder_l_string "SIMULATOR_SPEED_ENCODER_L"
#define simulator_speed_encoder_r_string "SIMULATOR_SPEED_ENCODER_R"
#define simulator_speed_inverter_l_string "SIMULATOR_SPEED_INVERTER_L"
#define simulator_speed_inverter_r_string "SIMULATOR_SPEED_INVERTER_R"
/* END */

/* START */
#define simulator_debug_signal_string "SIMULATOR_DEBUG_SIGNAL"

#define simulator_debug_signal_field_1_string "SIMULATOR_DEBUG_SIGNAL_FIELD_1"
#define simulator_debug_signal_field_2_string "SIMULATOR_DEBUG_SIGNAL_FIELD_2"
#define simulator_debug_signal_field_3_string "SIMULATOR_DEBUG_SIGNAL_FIELD_3"
#define simulator_debug_signal_field_4_string "SIMULATOR_DEBUG_SIGNAL_FIELD_4"
/* END */

enum simulator_types_id{
	e_simulator_int16_t = -2,
	e_simulator_float,

	
};
int simulator_fields_string_from_id(int id, char **v, size_t fields_size, size_t string_size);
int simulator_enum_fields(int enum_id, char **v, size_t fields_size, size_t string_size);
int simulator_serialize_from_id(int id, char *s, uint8_t *data, size_t *size);
int simulator_n_fields_from_id(int id);
int simulator_fields_types_from_id(int id, int* fields_types, int fields_types_size);


#endif