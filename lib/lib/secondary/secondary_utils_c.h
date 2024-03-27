#ifndef secondary_UTILS_H
#define secondary_UTILS_H

#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "primary_network.h"

#ifdef __cplusplus
extern "C" {
#endif

/* START */
#define IMU_ANGULAR_RATE "IMU_ANGULAR_RATE"

#define IMU_ANGULAR_RATE_ANG_RATE_X "imu_angular_rate_ang_rate_x"
#define IMU_ANGULAR_RATE_ANG_RATE_Y "imu_angular_rate_ang_rate_y"
#define IMU_ANGULAR_RATE_ANG_RATE_Z "imu_angular_rate_ang_rate_z"
/* END */

/* START */
#define IMU_ACCELERATION "IMU_ACCELERATION"

#define IMU_ACCELERATION_ACCEL_X "imu_acceleration_accel_x"
#define IMU_ACCELERATION_ACCEL_Y "imu_acceleration_accel_y"
#define IMU_ACCELERATION_ACCEL_Z "imu_acceleration_accel_z"
#define IMU_ACCELERATION_TEMPERATURE "imu_acceleration_temperature"
/* END */

/* START */
#define IRTS_FL_0 "IRTS_FL_0"

#define IRTS_FL_0_CHANNEL1 "irts_fl_0_channel1"
#define IRTS_FL_0_CHANNEL2 "irts_fl_0_channel2"
#define IRTS_FL_0_CHANNEL3 "irts_fl_0_channel3"
#define IRTS_FL_0_CHANNEL4 "irts_fl_0_channel4"
/* END */

/* START */
#define IRTS_FL_1 "IRTS_FL_1"

#define IRTS_FL_1_CHANNEL5 "irts_fl_1_channel5"
#define IRTS_FL_1_CHANNEL6 "irts_fl_1_channel6"
#define IRTS_FL_1_CHANNEL7 "irts_fl_1_channel7"
#define IRTS_FL_1_CHANNEL8 "irts_fl_1_channel8"
/* END */

/* START */
#define IRTS_FL_2 "IRTS_FL_2"

#define IRTS_FL_2_CHANNEL9 "irts_fl_2_channel9"
#define IRTS_FL_2_CHANNEL10 "irts_fl_2_channel10"
#define IRTS_FL_2_CHANNEL11 "irts_fl_2_channel11"
#define IRTS_FL_2_CHANNEL12 "irts_fl_2_channel12"
/* END */

/* START */
#define IRTS_FL_3 "IRTS_FL_3"

#define IRTS_FL_3_CHANNEL13 "irts_fl_3_channel13"
#define IRTS_FL_3_CHANNEL14 "irts_fl_3_channel14"
#define IRTS_FL_3_CHANNEL15 "irts_fl_3_channel15"
#define IRTS_FL_3_CHANNEL16 "irts_fl_3_channel16"
/* END */

/* START */
#define IRTS_FR_0 "IRTS_FR_0"

#define IRTS_FR_0_CHANNEL1 "irts_fr_0_channel1"
#define IRTS_FR_0_CHANNEL2 "irts_fr_0_channel2"
#define IRTS_FR_0_CHANNEL3 "irts_fr_0_channel3"
#define IRTS_FR_0_CHANNEL4 "irts_fr_0_channel4"
/* END */

/* START */
#define IRTS_FR_1 "IRTS_FR_1"

#define IRTS_FR_1_CHANNEL5 "irts_fr_1_channel5"
#define IRTS_FR_1_CHANNEL6 "irts_fr_1_channel6"
#define IRTS_FR_1_CHANNEL7 "irts_fr_1_channel7"
#define IRTS_FR_1_CHANNEL8 "irts_fr_1_channel8"
/* END */

/* START */
#define IRTS_FR_2 "IRTS_FR_2"

#define IRTS_FR_2_CHANNEL9 "irts_fr_2_channel9"
#define IRTS_FR_2_CHANNEL10 "irts_fr_2_channel10"
#define IRTS_FR_2_CHANNEL11 "irts_fr_2_channel11"
#define IRTS_FR_2_CHANNEL12 "irts_fr_2_channel12"
/* END */

/* START */
#define IRTS_FR_3 "IRTS_FR_3"

#define IRTS_FR_3_CHANNEL13 "irts_fr_3_channel13"
#define IRTS_FR_3_CHANNEL14 "irts_fr_3_channel14"
#define IRTS_FR_3_CHANNEL15 "irts_fr_3_channel15"
#define IRTS_FR_3_CHANNEL16 "irts_fr_3_channel16"
/* END */

/* START */
#define IRTS_RL_0 "IRTS_RL_0"

#define IRTS_RL_0_CHANNEL1 "irts_rl_0_channel1"
#define IRTS_RL_0_CHANNEL2 "irts_rl_0_channel2"
#define IRTS_RL_0_CHANNEL3 "irts_rl_0_channel3"
#define IRTS_RL_0_CHANNEL4 "irts_rl_0_channel4"
/* END */

/* START */
#define IRTS_RL_1 "IRTS_RL_1"

#define IRTS_RL_1_CHANNEL5 "irts_rl_1_channel5"
#define IRTS_RL_1_CHANNEL6 "irts_rl_1_channel6"
#define IRTS_RL_1_CHANNEL7 "irts_rl_1_channel7"
#define IRTS_RL_1_CHANNEL8 "irts_rl_1_channel8"
/* END */

/* START */
#define IRTS_RL_2 "IRTS_RL_2"

#define IRTS_RL_2_CHANNEL9 "irts_rl_2_channel9"
#define IRTS_RL_2_CHANNEL10 "irts_rl_2_channel10"
#define IRTS_RL_2_CHANNEL11 "irts_rl_2_channel11"
#define IRTS_RL_2_CHANNEL12 "irts_rl_2_channel12"
/* END */

/* START */
#define IRTS_RL_3 "IRTS_RL_3"

#define IRTS_RL_3_CHANNEL13 "irts_rl_3_channel13"
#define IRTS_RL_3_CHANNEL14 "irts_rl_3_channel14"
#define IRTS_RL_3_CHANNEL15 "irts_rl_3_channel15"
#define IRTS_RL_3_CHANNEL16 "irts_rl_3_channel16"
/* END */

/* START */
#define IRTS_RR_0 "IRTS_RR_0"

#define IRTS_RR_0_CHANNEL1 "irts_rr_0_channel1"
#define IRTS_RR_0_CHANNEL2 "irts_rr_0_channel2"
#define IRTS_RR_0_CHANNEL3 "irts_rr_0_channel3"
#define IRTS_RR_0_CHANNEL4 "irts_rr_0_channel4"
/* END */

/* START */
#define IRTS_RR_1 "IRTS_RR_1"

#define IRTS_RR_1_CHANNEL5 "irts_rr_1_channel5"
#define IRTS_RR_1_CHANNEL6 "irts_rr_1_channel6"
#define IRTS_RR_1_CHANNEL7 "irts_rr_1_channel7"
#define IRTS_RR_1_CHANNEL8 "irts_rr_1_channel8"
/* END */

/* START */
#define IRTS_RR_2 "IRTS_RR_2"

#define IRTS_RR_2_CHANNEL9 "irts_rr_2_channel9"
#define IRTS_RR_2_CHANNEL10 "irts_rr_2_channel10"
#define IRTS_RR_2_CHANNEL11 "irts_rr_2_channel11"
#define IRTS_RR_2_CHANNEL12 "irts_rr_2_channel12"
/* END */

/* START */
#define IRTS_RR_3 "IRTS_RR_3"

#define IRTS_RR_3_CHANNEL13 "irts_rr_3_channel13"
#define IRTS_RR_3_CHANNEL14 "irts_rr_3_channel14"
#define IRTS_RR_3_CHANNEL15 "irts_rr_3_channel15"
#define IRTS_RR_3_CHANNEL16 "irts_rr_3_channel16"
/* END */

/* START */
#define GPS_COORDS "GPS_COORDS"

#define GPS_COORDS_LATITUDE "gps_coords_latitude"
#define GPS_COORDS_LONGITUDE "gps_coords_longitude"
/* END */

/* START */
#define GPS_SPEED "GPS_SPEED"

#define GPS_SPEED_SPEED "gps_speed_speed"
/* END */

/* START */
#define PEDALS_OUTPUT "PEDALS_OUTPUT"

#define PEDALS_OUTPUT_APPS "pedals_output_apps"
#define PEDALS_OUTPUT_BSE_FRONT "pedals_output_bse_front"
#define PEDALS_OUTPUT_BSE_REAR "pedals_output_bse_rear"
/* END */

/* START */
#define STEERING_ANGLE "STEERING_ANGLE"

#define STEERING_ANGLE_ANGLE "steering_angle_angle"
/* END */

/* START */
#define CONTROL_STATE "CONTROL_STATE"

#define CONTROL_STATE_MAP_PW "control_state_map_pw"
#define CONTROL_STATE_MAP_SC "control_state_map_sc"
#define CONTROL_STATE_MAP_TV "control_state_map_tv"
/* END */

/* START */
#define TPMS "TPMS"

#define TPMS_FL_PRESSURE "tpms_fl_pressure"
#define TPMS_FR_PRESSURE "tpms_fr_pressure"
#define TPMS_RL_PRESSURE "tpms_rl_pressure"
#define TPMS_RR_PRESSURE "tpms_rr_pressure"
#define TPMS_FL_TEMPERATURE "tpms_fl_temperature"
#define TPMS_FR_TEMPERATURE "tpms_fr_temperature"
#define TPMS_RL_TEMPERATURE "tpms_rl_temperature"
#define TPMS_RR_TEMPERATURE "tpms_rr_temperature"
/* END */

/* START */
#define LAP_COUNT "LAP_COUNT"

#define LAP_COUNT_LAP_COUNT "lap_count_lap_count"
#define LAP_COUNT_LAP_TIME "lap_count_lap_time"
/* END */

/* START */
#define LC_STATUS "LC_STATUS"

#define LC_STATUS_LAP_NUMBER "lc_status_lap_number"
#define LC_STATUS_BEST_TIME "lc_status_best_time"
#define LC_STATUS_LAST_TIME "lc_status_last_time"
/* END */

/* START */
#define TIMESTAMP "TIMESTAMP"

#define TIMESTAMP_TIMESTAMP "timestamp_timestamp"
/* END */

/* START */
#define REAR_AMMO_POS "REAR_AMMO_POS"

#define REAR_AMMO_POS_RL "rear_ammo_pos_rl"
#define REAR_AMMO_POS_RR "rear_ammo_pos_rr"
/* END */

/* START */
#define FRONT_AMMO_POS "FRONT_AMMO_POS"

#define FRONT_AMMO_POS_FL "front_ammo_pos_fl"
#define FRONT_AMMO_POS_FR "front_ammo_pos_fr"
/* END */

/* START */
#define ROD_ELONGATION "ROD_ELONGATION"

#define ROD_ELONGATION_DEFORMATION "rod_elongation_deformation"
/* END */

/* START */
#define DEBUG_SIGNAL "DEBUG_SIGNAL"

#define DEBUG_SIGNAL_FIELD_1 "debug_signal_field_1"
#define DEBUG_SIGNAL_FIELD_2 "debug_signal_field_2"
#define DEBUG_SIGNAL_FIELD_3 "debug_signal_field_3"
#define DEBUG_SIGNAL_FIELD_4 "debug_signal_field_4"
/* END */

/* START */
#define COOLING_TEMP "COOLING_TEMP"

#define COOLING_TEMP_TOP_LEFT "cooling_temp_top_left"
#define COOLING_TEMP_BOTTOM_LEFT "cooling_temp_bottom_left"
#define COOLING_TEMP_TOP_RIGHT "cooling_temp_top_right"
#define COOLING_TEMP_BOTTOM_RIGHT "cooling_temp_bottom_right"
/* END */

enum secondary_types_id{
	e_secondary_uint32_t = -6,
	e_secondary_float,
	e_secondary_int16_t,
	e_secondary_uint16_t,
	e_secondary_uint8_t,
	e_secondary_uint64_t,

	
};

/**
 * @brief get the name of the signals in the message
 * 
 * @param[in] id message id
 * @param[out] v array of strings containing the name of the signals
 * @param[in] fields_size maximum size of v
 * @param[in] string_size maximum size of v[i]
 * 
 * @return 0 if ok 1 otherwise
*/
int secondary_fields_string_from_id(int id, char **v, size_t fields_size, size_t string_size);

/**
 * @brief get the fields of an enum given the id of the enum (get the id from fields_types_from_id)
 * 
 * @param[in] enum_id the id of the enum, you can get it from fields_types_from_id
 * @param[out] v array of strings containing the enum fields
 * @param[in] fields_size maximum size of v
 * @param[in] string_size maximum size of v[i]
 * 
 * @return 0 if ok 1 otherwise
*/
int secondary_enum_fields(int enum_id, char **v, size_t fields_size, size_t string_size);

/**
 * @brief serialize to a data pointer from a message id
 * 
 * @param[in] id message id
 * @param[in] s string containing the data to serialize (comma separated)
 * @param[out] data pointer to the serialized data
 * @param[out] size size of the message
 * 
 * @return Size of packed data, or negative error code.
*/
int secondary_serialize_from_id(int id, char *s, uint8_t *data, size_t *size);

/**
 * @brief get the number of signals in the message
 * 
 * @param[in] id the id of the message
 * 
 * @return return the number of the signals
*/
int secondary_n_fields_from_id(int id);

/**
 * @brief get the types of the signals in the message
 * 
 * @param[in] id the id of the message
 * @param[out] fields_types fields_types[i] contains the type id of the signal i (must be already allocated)
 * @param[in] fields_types_size max size of fields_types
 * 
 * @return the number of types set, 0 if the id is invalid or fields_types_size is too small
*/
int secondary_fields_types_from_id(int id, int* fields_types, int fields_types_size);

/**
 * @brief get the fields of an enum given the name of the message and the name of the signal
 * 
 * @param[in] msg_name name of the message to find
 * @param[in] sgn_name name of the signal to find
 * @param[out] v array of strings containing the enum fields
 * 
 * @return the number of fields or 0 if the signal is not an enum
*/
int secondary_enum_fields_from_name(const char *msg_name, const char *sgn_name, char **v);


#ifdef __cplusplus
}
#endif

#endif
