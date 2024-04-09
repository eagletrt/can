#ifndef secondary_UTILS_H
#define secondary_UTILS_H

#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "secondary_network.h"

#ifdef __cplusplus
extern "C" {
#endif

/* START */
#define IMU_ANGULAR_RATE "IMU_ANGULAR_RATE"

#define IMU_ANGULAR_RATE_X "imu_angular_rate_x"
#define IMU_ANGULAR_RATE_Y "imu_angular_rate_y"
#define IMU_ANGULAR_RATE_Z "imu_angular_rate_z"
/* END */

/* START */
#define IMU_ACCELERATION "IMU_ACCELERATION"

#define IMU_ACCELERATION_X "imu_acceleration_x"
#define IMU_ACCELERATION_Y "imu_acceleration_y"
#define IMU_ACCELERATION_Z "imu_acceleration_z"
#define IMU_ACCELERATION_IMU_TEMPERATURE "imu_acceleration_imu_temperature"
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
#define ANGULAR_VELOCITY "ANGULAR_VELOCITY"

#define ANGULAR_VELOCITY_FL "angular_velocity_fl"
#define ANGULAR_VELOCITY_FR "angular_velocity_fr"
/* END */

/* START */
#define PEDAL_THROTTLE "PEDAL_THROTTLE"

#define PEDAL_THROTTLE_THROTTLE "pedal_throttle_throttle"
/* END */

/* START */
#define PEDAL_BRAKES_PRESSURE "PEDAL_BRAKES_PRESSURE"

#define PEDAL_BRAKES_PRESSURE_FRONT "pedal_brakes_pressure_front"
#define PEDAL_BRAKES_PRESSURE_REAR "pedal_brakes_pressure_rear"
/* END */

/* START */
#define STEER_ANGLE "STEER_ANGLE"

#define STEER_ANGLE_ANGLE "steer_angle_angle"
/* END */

/* START */
#define TPMS_PRESSURE "TPMS_PRESSURE"

#define TPMS_PRESSURE_FL "tpms_pressure_fl"
#define TPMS_PRESSURE_FR "tpms_pressure_fr"
#define TPMS_PRESSURE_RL "tpms_pressure_rl"
#define TPMS_PRESSURE_RR "tpms_pressure_rr"
/* END */

/* START */
#define TPMS_TEMPERATURE "TPMS_TEMPERATURE"

#define TPMS_TEMPERATURE_FL "tpms_temperature_fl"
#define TPMS_TEMPERATURE_FR "tpms_temperature_fr"
#define TPMS_TEMPERATURE_RL "tpms_temperature_rl"
#define TPMS_TEMPERATURE_RR "tpms_temperature_rr"
/* END */

/* START */
#define TLM_UNIX_TIMESTAMP "TLM_UNIX_TIMESTAMP"

#define TLM_UNIX_TIMESTAMP_TIMESTAMP "tlm_unix_timestamp_timestamp"
/* END */

/* START */
#define TLM_LAP_TIME "TLM_LAP_TIME"

#define TLM_LAP_TIME_LAP_COUNT "tlm_lap_time_lap_count"
#define TLM_LAP_TIME_LAP_TIME "tlm_lap_time_lap_time"
/* END */

/* START */
#define TLM_LAPS_STATS "TLM_LAPS_STATS"

#define TLM_LAPS_STATS_LAP_NUMBER "tlm_laps_stats_lap_number"
#define TLM_LAPS_STATS_BEST_TIME "tlm_laps_stats_best_time"
#define TLM_LAPS_STATS_LAST_TIME "tlm_laps_stats_last_time"
/* END */

/* START */
#define AMMO_COMPRESSION "AMMO_COMPRESSION"

#define AMMO_COMPRESSION_RL "ammo_compression_rl"
#define AMMO_COMPRESSION_RR "ammo_compression_rr"
#define AMMO_COMPRESSION_FL "ammo_compression_fl"
#define AMMO_COMPRESSION_FR "ammo_compression_fr"
/* END */

/* START */
#define LINK_DEFORMATION "LINK_DEFORMATION"

#define LINK_DEFORMATION_ROD_ID "link_deformation_rod_id"
#define LINK_DEFORMATION_DEFORMATION "link_deformation_deformation"
/* END */

/* START */
#define LINK_DEFORMATION_SET_CALIBRATION "LINK_DEFORMATION_SET_CALIBRATION"

#define LINK_DEFORMATION_SET_CALIBRATION_ROD_ID "link_deformation_set_calibration_rod_id"
#define LINK_DEFORMATION_SET_CALIBRATION_DEFORMATION "link_deformation_set_calibration_deformation"
/* END */

/* START */
#define DEBUG_SIGNAL_1 "DEBUG_SIGNAL_1"

#define DEBUG_SIGNAL_1_FIELD_1 "debug_signal_1_field_1"
#define DEBUG_SIGNAL_1_FIELD_2 "debug_signal_1_field_2"
#define DEBUG_SIGNAL_1_FIELD_3 "debug_signal_1_field_3"
#define DEBUG_SIGNAL_1_FIELD_4 "debug_signal_1_field_4"
/* END */

/* START */
#define DEBUG_SIGNAL_2 "DEBUG_SIGNAL_2"

#define DEBUG_SIGNAL_2_FIELD_1 "debug_signal_2_field_1"
#define DEBUG_SIGNAL_2_FIELD_2 "debug_signal_2_field_2"
#define DEBUG_SIGNAL_2_FIELD_3 "debug_signal_2_field_3"
#define DEBUG_SIGNAL_2_FIELD_4 "debug_signal_2_field_4"
/* END */

/* START */
#define COOLING_TEMP "COOLING_TEMP"

#define COOLING_TEMP_TOP_LEFT "cooling_temp_top_left"
#define COOLING_TEMP_BOTTOM_LEFT "cooling_temp_bottom_left"
#define COOLING_TEMP_TOP_RIGHT "cooling_temp_top_right"
#define COOLING_TEMP_BOTTOM_RIGHT "cooling_temp_bottom_right"
/* END */

enum secondary_types_id{
	e_secondary_uint64_t = -6,
	e_secondary_uint16_t,
	e_secondary_uint8_t,
	e_secondary_uint32_t,
	e_secondary_int16_t,
	e_secondary_float,

	
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
