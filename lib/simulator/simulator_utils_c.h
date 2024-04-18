#ifndef simulator_UTILS_H
#define simulator_UTILS_H

#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "simulator_network.h"

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
#define CONTROL_OUTPUT "CONTROL_OUTPUT"

#define CONTROL_OUTPUT_ESTIMATED_VELOCITY "control_output_estimated_velocity"
#define CONTROL_OUTPUT_TORQUE_MAX_L "control_output_torque_max_l"
#define CONTROL_OUTPUT_TORQUE_MAX_R "control_output_torque_max_r"
#define CONTROL_OUTPUT_TORQUE_L "control_output_torque_l"
#define CONTROL_OUTPUT_TORQUE_R "control_output_torque_r"
/* END */

/* START */
#define CONTROL_STATUS "CONTROL_STATUS"

#define CONTROL_STATUS_MAP_PW "control_status_map_pw"
#define CONTROL_STATUS_MAP_SC "control_status_map_sc"
#define CONTROL_STATUS_MAP_TV "control_status_map_tv"
/* END */

/* START */
#define SPEED "SPEED"

#define SPEED_FL "speed_fl"
#define SPEED_FR "speed_fr"
/* END */

/* START */
#define DEBUG_SIGNAL_2 "DEBUG_SIGNAL_2"

#define DEBUG_SIGNAL_2_FIELD_1 "debug_signal_2_field_1"
#define DEBUG_SIGNAL_2_FIELD_2 "debug_signal_2_field_2"
#define DEBUG_SIGNAL_2_FIELD_3 "debug_signal_2_field_3"
#define DEBUG_SIGNAL_2_FIELD_4 "debug_signal_2_field_4"
/* END */

enum simulator_types_id{
	e_simulator_int16_t = -2,
	e_simulator_float,

	
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
int simulator_fields_string_from_id(int id, char **v, size_t fields_size, size_t string_size);

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
int simulator_enum_fields(int enum_id, char **v, size_t fields_size, size_t string_size);

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
int simulator_serialize_from_id(int id, char *s, uint8_t *data, size_t *size);

/**
 * @brief get the number of signals in the message
 * 
 * @param[in] id the id of the message
 * 
 * @return return the number of the signals
*/
int simulator_n_fields_from_id(int id);

/**
 * @brief get the types of the signals in the message
 * 
 * @param[in] id the id of the message
 * @param[out] fields_types fields_types[i] contains the type id of the signal i (must be already allocated)
 * @param[in] fields_types_size max size of fields_types
 * 
 * @return the number of types set, 0 if the id is invalid or fields_types_size is too small
*/
int simulator_fields_types_from_id(int id, int* fields_types, int fields_types_size);

/**
 * @brief get the fields of an enum given the name of the message and the name of the signal
 * 
 * @param[in] msg_name name of the message to find
 * @param[in] sgn_name name of the signal to find
 * @param[out] v array of strings containing the enum fields
 * 
 * @return the number of fields or 0 if the signal is not an enum
*/
int simulator_enum_fields_from_name(const char *msg_name, const char *sgn_name, char **v);


#ifdef __cplusplus
}
#endif

#endif
