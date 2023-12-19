#ifndef SECONDARY_UTILS_C_H

#define SECONDARY_UTILS_C_H

#include <stddef.h>
#include "secondary_network.h"

/* START */
#define secondary_imu_angular_rate_string "SECONDARY_IMU_ANGULAR_RATE"

#define secondary_imu_angular_rate_ang_rate_x_string "SECONDARY_IMU_ANGULAR_RATE_ANG_RATE_X"
#define secondary_imu_angular_rate_ang_rate_y_string "SECONDARY_IMU_ANGULAR_RATE_ANG_RATE_Y"
#define secondary_imu_angular_rate_ang_rate_z_string "SECONDARY_IMU_ANGULAR_RATE_ANG_RATE_Z"
/* END */

/* START */
#define secondary_imu_acceleration_string "SECONDARY_IMU_ACCELERATION"

#define secondary_imu_acceleration_accel_x_string "SECONDARY_IMU_ACCELERATION_ACCEL_X"
#define secondary_imu_acceleration_accel_y_string "SECONDARY_IMU_ACCELERATION_ACCEL_Y"
#define secondary_imu_acceleration_accel_z_string "SECONDARY_IMU_ACCELERATION_ACCEL_Z"
#define secondary_imu_acceleration_temperature_string "SECONDARY_IMU_ACCELERATION_TEMPERATURE"
/* END */

/* START */
#define secondary_irts_fl_0_string "SECONDARY_IRTS_FL_0"

#define secondary_irts_fl_0_channel1_string "SECONDARY_IRTS_FL_0_CHANNEL1"
#define secondary_irts_fl_0_channel2_string "SECONDARY_IRTS_FL_0_CHANNEL2"
#define secondary_irts_fl_0_channel3_string "SECONDARY_IRTS_FL_0_CHANNEL3"
#define secondary_irts_fl_0_channel4_string "SECONDARY_IRTS_FL_0_CHANNEL4"
/* END */

/* START */
#define secondary_irts_fl_1_string "SECONDARY_IRTS_FL_1"

#define secondary_irts_fl_1_channel5_string "SECONDARY_IRTS_FL_1_CHANNEL5"
#define secondary_irts_fl_1_channel6_string "SECONDARY_IRTS_FL_1_CHANNEL6"
#define secondary_irts_fl_1_channel7_string "SECONDARY_IRTS_FL_1_CHANNEL7"
#define secondary_irts_fl_1_channel8_string "SECONDARY_IRTS_FL_1_CHANNEL8"
/* END */

/* START */
#define secondary_irts_fl_2_string "SECONDARY_IRTS_FL_2"

#define secondary_irts_fl_2_channel9_string "SECONDARY_IRTS_FL_2_CHANNEL9"
#define secondary_irts_fl_2_channel10_string "SECONDARY_IRTS_FL_2_CHANNEL10"
#define secondary_irts_fl_2_channel11_string "SECONDARY_IRTS_FL_2_CHANNEL11"
#define secondary_irts_fl_2_channel12_string "SECONDARY_IRTS_FL_2_CHANNEL12"
/* END */

/* START */
#define secondary_irts_fl_3_string "SECONDARY_IRTS_FL_3"

#define secondary_irts_fl_3_channel13_string "SECONDARY_IRTS_FL_3_CHANNEL13"
#define secondary_irts_fl_3_channel14_string "SECONDARY_IRTS_FL_3_CHANNEL14"
#define secondary_irts_fl_3_channel15_string "SECONDARY_IRTS_FL_3_CHANNEL15"
#define secondary_irts_fl_3_channel16_string "SECONDARY_IRTS_FL_3_CHANNEL16"
/* END */

/* START */
#define secondary_irts_fr_0_string "SECONDARY_IRTS_FR_0"

#define secondary_irts_fr_0_channel1_string "SECONDARY_IRTS_FR_0_CHANNEL1"
#define secondary_irts_fr_0_channel2_string "SECONDARY_IRTS_FR_0_CHANNEL2"
#define secondary_irts_fr_0_channel3_string "SECONDARY_IRTS_FR_0_CHANNEL3"
#define secondary_irts_fr_0_channel4_string "SECONDARY_IRTS_FR_0_CHANNEL4"
/* END */

/* START */
#define secondary_irts_fr_1_string "SECONDARY_IRTS_FR_1"

#define secondary_irts_fr_1_channel5_string "SECONDARY_IRTS_FR_1_CHANNEL5"
#define secondary_irts_fr_1_channel6_string "SECONDARY_IRTS_FR_1_CHANNEL6"
#define secondary_irts_fr_1_channel7_string "SECONDARY_IRTS_FR_1_CHANNEL7"
#define secondary_irts_fr_1_channel8_string "SECONDARY_IRTS_FR_1_CHANNEL8"
/* END */

/* START */
#define secondary_irts_fr_2_string "SECONDARY_IRTS_FR_2"

#define secondary_irts_fr_2_channel9_string "SECONDARY_IRTS_FR_2_CHANNEL9"
#define secondary_irts_fr_2_channel10_string "SECONDARY_IRTS_FR_2_CHANNEL10"
#define secondary_irts_fr_2_channel11_string "SECONDARY_IRTS_FR_2_CHANNEL11"
#define secondary_irts_fr_2_channel12_string "SECONDARY_IRTS_FR_2_CHANNEL12"
/* END */

/* START */
#define secondary_irts_fr_3_string "SECONDARY_IRTS_FR_3"

#define secondary_irts_fr_3_channel13_string "SECONDARY_IRTS_FR_3_CHANNEL13"
#define secondary_irts_fr_3_channel14_string "SECONDARY_IRTS_FR_3_CHANNEL14"
#define secondary_irts_fr_3_channel15_string "SECONDARY_IRTS_FR_3_CHANNEL15"
#define secondary_irts_fr_3_channel16_string "SECONDARY_IRTS_FR_3_CHANNEL16"
/* END */

/* START */
#define secondary_irts_rl_0_string "SECONDARY_IRTS_RL_0"

#define secondary_irts_rl_0_channel1_string "SECONDARY_IRTS_RL_0_CHANNEL1"
#define secondary_irts_rl_0_channel2_string "SECONDARY_IRTS_RL_0_CHANNEL2"
#define secondary_irts_rl_0_channel3_string "SECONDARY_IRTS_RL_0_CHANNEL3"
#define secondary_irts_rl_0_channel4_string "SECONDARY_IRTS_RL_0_CHANNEL4"
/* END */

/* START */
#define secondary_irts_rl_1_string "SECONDARY_IRTS_RL_1"

#define secondary_irts_rl_1_channel5_string "SECONDARY_IRTS_RL_1_CHANNEL5"
#define secondary_irts_rl_1_channel6_string "SECONDARY_IRTS_RL_1_CHANNEL6"
#define secondary_irts_rl_1_channel7_string "SECONDARY_IRTS_RL_1_CHANNEL7"
#define secondary_irts_rl_1_channel8_string "SECONDARY_IRTS_RL_1_CHANNEL8"
/* END */

/* START */
#define secondary_irts_rl_2_string "SECONDARY_IRTS_RL_2"

#define secondary_irts_rl_2_channel9_string "SECONDARY_IRTS_RL_2_CHANNEL9"
#define secondary_irts_rl_2_channel10_string "SECONDARY_IRTS_RL_2_CHANNEL10"
#define secondary_irts_rl_2_channel11_string "SECONDARY_IRTS_RL_2_CHANNEL11"
#define secondary_irts_rl_2_channel12_string "SECONDARY_IRTS_RL_2_CHANNEL12"
/* END */

/* START */
#define secondary_irts_rl_3_string "SECONDARY_IRTS_RL_3"

#define secondary_irts_rl_3_channel13_string "SECONDARY_IRTS_RL_3_CHANNEL13"
#define secondary_irts_rl_3_channel14_string "SECONDARY_IRTS_RL_3_CHANNEL14"
#define secondary_irts_rl_3_channel15_string "SECONDARY_IRTS_RL_3_CHANNEL15"
#define secondary_irts_rl_3_channel16_string "SECONDARY_IRTS_RL_3_CHANNEL16"
/* END */

/* START */
#define secondary_irts_rr_0_string "SECONDARY_IRTS_RR_0"

#define secondary_irts_rr_0_channel1_string "SECONDARY_IRTS_RR_0_CHANNEL1"
#define secondary_irts_rr_0_channel2_string "SECONDARY_IRTS_RR_0_CHANNEL2"
#define secondary_irts_rr_0_channel3_string "SECONDARY_IRTS_RR_0_CHANNEL3"
#define secondary_irts_rr_0_channel4_string "SECONDARY_IRTS_RR_0_CHANNEL4"
/* END */

/* START */
#define secondary_irts_rr_1_string "SECONDARY_IRTS_RR_1"

#define secondary_irts_rr_1_channel5_string "SECONDARY_IRTS_RR_1_CHANNEL5"
#define secondary_irts_rr_1_channel6_string "SECONDARY_IRTS_RR_1_CHANNEL6"
#define secondary_irts_rr_1_channel7_string "SECONDARY_IRTS_RR_1_CHANNEL7"
#define secondary_irts_rr_1_channel8_string "SECONDARY_IRTS_RR_1_CHANNEL8"
/* END */

/* START */
#define secondary_irts_rr_2_string "SECONDARY_IRTS_RR_2"

#define secondary_irts_rr_2_channel9_string "SECONDARY_IRTS_RR_2_CHANNEL9"
#define secondary_irts_rr_2_channel10_string "SECONDARY_IRTS_RR_2_CHANNEL10"
#define secondary_irts_rr_2_channel11_string "SECONDARY_IRTS_RR_2_CHANNEL11"
#define secondary_irts_rr_2_channel12_string "SECONDARY_IRTS_RR_2_CHANNEL12"
/* END */

/* START */
#define secondary_irts_rr_3_string "SECONDARY_IRTS_RR_3"

#define secondary_irts_rr_3_channel13_string "SECONDARY_IRTS_RR_3_CHANNEL13"
#define secondary_irts_rr_3_channel14_string "SECONDARY_IRTS_RR_3_CHANNEL14"
#define secondary_irts_rr_3_channel15_string "SECONDARY_IRTS_RR_3_CHANNEL15"
#define secondary_irts_rr_3_channel16_string "SECONDARY_IRTS_RR_3_CHANNEL16"
/* END */

/* START */
#define secondary_gps_coords_string "SECONDARY_GPS_COORDS"

#define secondary_gps_coords_latitude_string "SECONDARY_GPS_COORDS_LATITUDE"
#define secondary_gps_coords_longitude_string "SECONDARY_GPS_COORDS_LONGITUDE"
/* END */

/* START */
#define secondary_gps_speed_string "SECONDARY_GPS_SPEED"

#define secondary_gps_speed_speed_string "SECONDARY_GPS_SPEED_SPEED"
/* END */

/* START */
#define secondary_pedals_output_string "SECONDARY_PEDALS_OUTPUT"

#define secondary_pedals_output_apps_string "SECONDARY_PEDALS_OUTPUT_APPS"
#define secondary_pedals_output_bse_front_string "SECONDARY_PEDALS_OUTPUT_BSE_FRONT"
#define secondary_pedals_output_bse_rear_string "SECONDARY_PEDALS_OUTPUT_BSE_REAR"
/* END */

/* START */
#define secondary_steering_angle_string "SECONDARY_STEERING_ANGLE"

#define secondary_steering_angle_angle_string "SECONDARY_STEERING_ANGLE_ANGLE"
/* END */

/* START */
#define secondary_control_state_string "SECONDARY_CONTROL_STATE"

#define secondary_control_state_map_pw_string "SECONDARY_CONTROL_STATE_MAP_PW"
#define secondary_control_state_map_sc_string "SECONDARY_CONTROL_STATE_MAP_SC"
#define secondary_control_state_map_tv_string "SECONDARY_CONTROL_STATE_MAP_TV"
/* END */

/* START */
#define secondary_tpms_string "SECONDARY_TPMS"

#define secondary_tpms_fl_pressure_string "SECONDARY_TPMS_FL_PRESSURE"
#define secondary_tpms_fr_pressure_string "SECONDARY_TPMS_FR_PRESSURE"
#define secondary_tpms_rl_pressure_string "SECONDARY_TPMS_RL_PRESSURE"
#define secondary_tpms_rr_pressure_string "SECONDARY_TPMS_RR_PRESSURE"
#define secondary_tpms_fl_temperature_string "SECONDARY_TPMS_FL_TEMPERATURE"
#define secondary_tpms_fr_temperature_string "SECONDARY_TPMS_FR_TEMPERATURE"
#define secondary_tpms_rl_temperature_string "SECONDARY_TPMS_RL_TEMPERATURE"
#define secondary_tpms_rr_temperature_string "SECONDARY_TPMS_RR_TEMPERATURE"
/* END */

/* START */
#define secondary_lap_count_string "SECONDARY_LAP_COUNT"

#define secondary_lap_count_lap_count_string "SECONDARY_LAP_COUNT_LAP_COUNT"
#define secondary_lap_count_lap_time_string "SECONDARY_LAP_COUNT_LAP_TIME"
/* END */

/* START */
#define secondary_lc_status_string "SECONDARY_LC_STATUS"

#define secondary_lc_status_lap_number_string "SECONDARY_LC_STATUS_LAP_NUMBER"
#define secondary_lc_status_best_time_string "SECONDARY_LC_STATUS_BEST_TIME"
#define secondary_lc_status_last_time_string "SECONDARY_LC_STATUS_LAST_TIME"
/* END */

/* START */
#define secondary_timestamp_string "SECONDARY_TIMESTAMP"

#define secondary_timestamp_timestamp_string "SECONDARY_TIMESTAMP_TIMESTAMP"
/* END */

/* START */
#define secondary_rear_ammo_pos_string "SECONDARY_REAR_AMMO_POS"

#define secondary_rear_ammo_pos_rl_string "SECONDARY_REAR_AMMO_POS_RL"
#define secondary_rear_ammo_pos_rr_string "SECONDARY_REAR_AMMO_POS_RR"
/* END */

/* START */
#define secondary_front_ammo_pos_string "SECONDARY_FRONT_AMMO_POS"

#define secondary_front_ammo_pos_fl_string "SECONDARY_FRONT_AMMO_POS_FL"
#define secondary_front_ammo_pos_fr_string "SECONDARY_FRONT_AMMO_POS_FR"
/* END */

/* START */
#define secondary_debug_signal_string "SECONDARY_DEBUG_SIGNAL"

#define secondary_debug_signal_field_1_string "SECONDARY_DEBUG_SIGNAL_FIELD_1"
#define secondary_debug_signal_field_2_string "SECONDARY_DEBUG_SIGNAL_FIELD_2"
#define secondary_debug_signal_field_3_string "SECONDARY_DEBUG_SIGNAL_FIELD_3"
#define secondary_debug_signal_field_4_string "SECONDARY_DEBUG_SIGNAL_FIELD_4"
/* END */

/* START */
#define secondary_cooling_temp_string "SECONDARY_COOLING_TEMP"

#define secondary_cooling_temp_top_left_string "SECONDARY_COOLING_TEMP_TOP_LEFT"
#define secondary_cooling_temp_bottom_left_string "SECONDARY_COOLING_TEMP_BOTTOM_LEFT"
#define secondary_cooling_temp_top_right_string "SECONDARY_COOLING_TEMP_TOP_RIGHT"
#define secondary_cooling_temp_bottom_right_string "SECONDARY_COOLING_TEMP_BOTTOM_RIGHT"
/* END */

enum secondary_types_id{
	e_secondary_float = -6,
	e_secondary_int16_t,
	e_secondary_uint64_t,
	e_secondary_uint32_t,
	e_secondary_uint8_t,
	e_secondary_uint16_t,

	
};
int secondary_fields_string_from_id(int id, char **v, size_t fields_size, size_t string_size);
int secondary_enum_fields(int enum_id, char **v, size_t fields_size, size_t string_size);
int secondary_serialize_from_id(int id, char *s, uint8_t *data, size_t *size);
int secondary_n_fields_from_id(int id);
int secondary_fields_types_from_id(int id, int* fields_types, int fields_types_size);


#endif