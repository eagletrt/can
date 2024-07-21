#ifndef secondary_UTILS_HPP
#define secondary_UTILS_HPP

#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <vector>
#include <string>
#include "secondary_network.h"

/* START */
#define ACQUISINATOR_JMP_TO_BLT "ACQUISINATOR_JMP_TO_BLT"

#define ACQUISINATOR_JMP_TO_BLT_ACQUISINATORE_ID "acquisinator_jmp_to_blt_acquisinatore_id"
/* END */

/* START */
#define ACQUISINATOR_FLASH_0_TX "ACQUISINATOR_FLASH_0_TX"

/* END */

/* START */
#define ACQUISINATOR_FLASH_0_RX "ACQUISINATOR_FLASH_0_RX"

/* END */

/* START */
#define ACQUISINATOR_FLASH_1_TX "ACQUISINATOR_FLASH_1_TX"

/* END */

/* START */
#define ACQUISINATOR_FLASH_1_RX "ACQUISINATOR_FLASH_1_RX"

/* END */

/* START */
#define ACQUISINATOR_FLASH_2_TX "ACQUISINATOR_FLASH_2_TX"

/* END */

/* START */
#define ACQUISINATOR_FLASH_2_RX "ACQUISINATOR_FLASH_2_RX"

/* END */

/* START */
#define ACQUISINATOR_FLASH_3_TX "ACQUISINATOR_FLASH_3_TX"

/* END */

/* START */
#define ACQUISINATOR_FLASH_3_RX "ACQUISINATOR_FLASH_3_RX"

/* END */

/* START */
#define ACQUISINATOR_FLASH_4_TX "ACQUISINATOR_FLASH_4_TX"

/* END */

/* START */
#define ACQUISINATOR_FLASH_4_RX "ACQUISINATOR_FLASH_4_RX"

/* END */

/* START */
#define ACQUISINATOR_FLASH_5_TX "ACQUISINATOR_FLASH_5_TX"

/* END */

/* START */
#define ACQUISINATOR_FLASH_5_RX "ACQUISINATOR_FLASH_5_RX"

/* END */

/* START */
#define ACQUISINATOR_FLASH_6_TX "ACQUISINATOR_FLASH_6_TX"

/* END */

/* START */
#define ACQUISINATOR_FLASH_6_RX "ACQUISINATOR_FLASH_6_RX"

/* END */

/* START */
#define ACQUISINATOR_FLASH_7_TX "ACQUISINATOR_FLASH_7_TX"

/* END */

/* START */
#define ACQUISINATOR_FLASH_7_RX "ACQUISINATOR_FLASH_7_RX"

/* END */

/* START */
#define ACQUISINATOR_FLASH_8_TX "ACQUISINATOR_FLASH_8_TX"

/* END */

/* START */
#define ACQUISINATOR_FLASH_8_RX "ACQUISINATOR_FLASH_8_RX"

/* END */

/* START */
#define ACQUISINATOR_FLASH_9_TX "ACQUISINATOR_FLASH_9_TX"

/* END */

/* START */
#define ACQUISINATOR_FLASH_9_RX "ACQUISINATOR_FLASH_9_RX"

/* END */

/* START */
#define ACQUISINATOR_FLASH_10_TX "ACQUISINATOR_FLASH_10_TX"

/* END */

/* START */
#define ACQUISINATOR_FLASH_10_RX "ACQUISINATOR_FLASH_10_RX"

/* END */

/* START */
#define ACQUISINATOR_FLASH_11_TX "ACQUISINATOR_FLASH_11_TX"

/* END */

/* START */
#define ACQUISINATOR_FLASH_11_RX "ACQUISINATOR_FLASH_11_RX"

/* END */

/* START */
#define ACQUISINATOR_FLASH_12_TX "ACQUISINATOR_FLASH_12_TX"

/* END */

/* START */
#define ACQUISINATOR_FLASH_12_RX "ACQUISINATOR_FLASH_12_RX"

/* END */

/* START */
#define ACQUISINATOR_FLASH_13_TX "ACQUISINATOR_FLASH_13_TX"

/* END */

/* START */
#define ACQUISINATOR_FLASH_13_RX "ACQUISINATOR_FLASH_13_RX"

/* END */

/* START */
#define ACQUISINATOR_FLASH_14_TX "ACQUISINATOR_FLASH_14_TX"

/* END */

/* START */
#define ACQUISINATOR_FLASH_14_RX "ACQUISINATOR_FLASH_14_RX"

/* END */

/* START */
#define ACQUISINATOR_FLASH_15_TX "ACQUISINATOR_FLASH_15_TX"

/* END */

/* START */
#define ACQUISINATOR_FLASH_15_RX "ACQUISINATOR_FLASH_15_RX"

/* END */

/* START */
#define ACQUISINATOR_FLASH_16_TX "ACQUISINATOR_FLASH_16_TX"

/* END */

/* START */
#define ACQUISINATOR_FLASH_16_RX "ACQUISINATOR_FLASH_16_RX"

/* END */

/* START */
#define ACQUISINATOR_FLASH_17_TX "ACQUISINATOR_FLASH_17_TX"

/* END */

/* START */
#define ACQUISINATOR_FLASH_17_RX "ACQUISINATOR_FLASH_17_RX"

/* END */

/* START */
#define ACQUISINATOR_FLASH_18_TX "ACQUISINATOR_FLASH_18_TX"

/* END */

/* START */
#define ACQUISINATOR_FLASH_18_RX "ACQUISINATOR_FLASH_18_RX"

/* END */

/* START */
#define ACQUISINATOR_FLASH_19_TX "ACQUISINATOR_FLASH_19_TX"

/* END */

/* START */
#define ACQUISINATOR_FLASH_19_RX "ACQUISINATOR_FLASH_19_RX"

/* END */

/* START */
#define ACQUISINATOR_FLASH_20_TX "ACQUISINATOR_FLASH_20_TX"

/* END */

/* START */
#define ACQUISINATOR_FLASH_20_RX "ACQUISINATOR_FLASH_20_RX"

/* END */

/* START */
#define ACQUISINATOR_FLASH_21_TX "ACQUISINATOR_FLASH_21_TX"

/* END */

/* START */
#define ACQUISINATOR_FLASH_21_RX "ACQUISINATOR_FLASH_21_RX"

/* END */

/* START */
#define ACQUISINATOR_FLASH_22_TX "ACQUISINATOR_FLASH_22_TX"

/* END */

/* START */
#define ACQUISINATOR_FLASH_22_RX "ACQUISINATOR_FLASH_22_RX"

/* END */

/* START */
#define ACQUISINATOR_FLASH_23_TX "ACQUISINATOR_FLASH_23_TX"

/* END */

/* START */
#define ACQUISINATOR_FLASH_23_RX "ACQUISINATOR_FLASH_23_RX"

/* END */

/* START */
#define ACQUISINATOR_FLASH_24_TX "ACQUISINATOR_FLASH_24_TX"

/* END */

/* START */
#define ACQUISINATOR_FLASH_24_RX "ACQUISINATOR_FLASH_24_RX"

/* END */

/* START */
#define ACQUISINATOR_FLASH_25_TX "ACQUISINATOR_FLASH_25_TX"

/* END */

/* START */
#define ACQUISINATOR_FLASH_25_RX "ACQUISINATOR_FLASH_25_RX"

/* END */

/* START */
#define ACQUISINATOR_FLASH_26_TX "ACQUISINATOR_FLASH_26_TX"

/* END */

/* START */
#define ACQUISINATOR_FLASH_26_RX "ACQUISINATOR_FLASH_26_RX"

/* END */

/* START */
#define ACQUISINATOR_FLASH_27_TX "ACQUISINATOR_FLASH_27_TX"

/* END */

/* START */
#define ACQUISINATOR_FLASH_27_RX "ACQUISINATOR_FLASH_27_RX"

/* END */

/* START */
#define ACQUISINATOR_FLASH_28_TX "ACQUISINATOR_FLASH_28_TX"

/* END */

/* START */
#define ACQUISINATOR_FLASH_28_RX "ACQUISINATOR_FLASH_28_RX"

/* END */

/* START */
#define ACQUISINATOR_FLASH_29_TX "ACQUISINATOR_FLASH_29_TX"

/* END */

/* START */
#define ACQUISINATOR_FLASH_29_RX "ACQUISINATOR_FLASH_29_RX"

/* END */

/* START */
#define ACQUISINATOR_FLASH_30_TX "ACQUISINATOR_FLASH_30_TX"

/* END */

/* START */
#define ACQUISINATOR_FLASH_30_RX "ACQUISINATOR_FLASH_30_RX"

/* END */

/* START */
#define ACQUISINATOR_FLASH_31_TX "ACQUISINATOR_FLASH_31_TX"

/* END */

/* START */
#define ACQUISINATOR_FLASH_31_RX "ACQUISINATOR_FLASH_31_RX"

/* END */

/* START */
#define ACQUISINATOR_VERSION "ACQUISINATOR_VERSION"

#define ACQUISINATOR_VERSION_ACQUISINATOR_ID "acquisinator_version_acquisinator_id"
#define ACQUISINATOR_VERSION_CANLIB_BUILD_TIME "acquisinator_version_canlib_build_time"
/* END */

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
#define VEHICLE_POSITION "VEHICLE_POSITION"

#define VEHICLE_POSITION_X "vehicle_position_x"
#define VEHICLE_POSITION_Y "vehicle_position_y"
#define VEHICLE_POSITION_HEADING "vehicle_position_heading"
/* END */

/* START */
#define VEHICLE_SPEED "VEHICLE_SPEED"

#define VEHICLE_SPEED_U "vehicle_speed_u"
#define VEHICLE_SPEED_V "vehicle_speed_v"
/* END */

/* START */
#define VEHICLE_CURVILINEAR_COORDINATES "VEHICLE_CURVILINEAR_COORDINATES"

#define VEHICLE_CURVILINEAR_COORDINATES_S "vehicle_curvilinear_coordinates_s"
#define VEHICLE_CURVILINEAR_COORDINATES_N "vehicle_curvilinear_coordinates_n"
/* END */

/* START */
#define ANGULAR_VELOCITY "ANGULAR_VELOCITY"

#define ANGULAR_VELOCITY_FL "angular_velocity_fl"
#define ANGULAR_VELOCITY_FR "angular_velocity_fr"
/* END */

/* START */
#define REAR_ANGULAR_VELOCITY "REAR_ANGULAR_VELOCITY"

#define REAR_ANGULAR_VELOCITY_RL "rear_angular_velocity_rl"
#define REAR_ANGULAR_VELOCITY_RR "rear_angular_velocity_rr"
/* END */

/* START */
#define HV_SOC_ESTIMATION_STATE "HV_SOC_ESTIMATION_STATE"

#define HV_SOC_ESTIMATION_STATE_SOC "hv_soc_estimation_state_soc"
#define HV_SOC_ESTIMATION_STATE_RC1 "hv_soc_estimation_state_rc1"
#define HV_SOC_ESTIMATION_STATE_RC2 "hv_soc_estimation_state_rc2"
/* END */

/* START */
#define HV_SOC_ESTIMATION_COVARIANCE "HV_SOC_ESTIMATION_COVARIANCE"

#define HV_SOC_ESTIMATION_COVARIANCE_SOC "hv_soc_estimation_covariance_soc"
#define HV_SOC_ESTIMATION_COVARIANCE_RC1 "hv_soc_estimation_covariance_rc1"
#define HV_SOC_ESTIMATION_COVARIANCE_RC2 "hv_soc_estimation_covariance_rc2"
/* END */

/* START */
#define LV_SOC_ESTIMATION_STATE "LV_SOC_ESTIMATION_STATE"

#define LV_SOC_ESTIMATION_STATE_SOC "lv_soc_estimation_state_soc"
#define LV_SOC_ESTIMATION_STATE_RC1 "lv_soc_estimation_state_rc1"
#define LV_SOC_ESTIMATION_STATE_RC2 "lv_soc_estimation_state_rc2"
/* END */

/* START */
#define LV_SOC_ESTIMATION_COVARIANCE "LV_SOC_ESTIMATION_COVARIANCE"

#define LV_SOC_ESTIMATION_COVARIANCE_SOC "lv_soc_estimation_covariance_soc"
#define LV_SOC_ESTIMATION_COVARIANCE_RC1 "lv_soc_estimation_covariance_rc1"
#define LV_SOC_ESTIMATION_COVARIANCE_RC2 "lv_soc_estimation_covariance_rc2"
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
#define ODOMETER "ODOMETER"

#define ODOMETER_KILOMETERS "odometer_kilometers"
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
#define TLM_NETWORK_INTERFACE "TLM_NETWORK_INTERFACE"

#define TLM_NETWORK_INTERFACE_INAME_0 "tlm_network_interface_iname_0"
#define TLM_NETWORK_INTERFACE_INAME_1 "tlm_network_interface_iname_1"
#define TLM_NETWORK_INTERFACE_INAME_2 "tlm_network_interface_iname_2"
#define TLM_NETWORK_INTERFACE_INAME_3 "tlm_network_interface_iname_3"
#define TLM_NETWORK_INTERFACE_IP_ADDRESS "tlm_network_interface_ip_address"
/* END */

/* START */
#define AMMO_COMPRESSION "AMMO_COMPRESSION"

#define AMMO_COMPRESSION_RL "ammo_compression_rl"
#define AMMO_COMPRESSION_RR "ammo_compression_rr"
#define AMMO_COMPRESSION_FL "ammo_compression_fl"
#define AMMO_COMPRESSION_FR "ammo_compression_fr"
/* END */

/* START */
#define ACQUISINATOR_CALIBRATIONS_OFFSETS "ACQUISINATOR_CALIBRATIONS_OFFSETS"

#define ACQUISINATOR_CALIBRATIONS_OFFSETS_ACQUISINATOR_ID "acquisinator_calibrations_offsets_acquisinator_id"
#define ACQUISINATOR_CALIBRATIONS_OFFSETS_OFFSET1 "acquisinator_calibrations_offsets_offset1"
#define ACQUISINATOR_CALIBRATIONS_OFFSETS_OFFSET2 "acquisinator_calibrations_offsets_offset2"
/* END */

/* START */
#define LINK_DEFORMATION_DEBUG_VOLTAGES "LINK_DEFORMATION_DEBUG_VOLTAGES"

#define LINK_DEFORMATION_DEBUG_VOLTAGES_WHEEL_ID "link_deformation_debug_voltages_wheel_id"
#define LINK_DEFORMATION_DEBUG_VOLTAGES_ROD_ID "link_deformation_debug_voltages_rod_id"
#define LINK_DEFORMATION_DEBUG_VOLTAGES_RAW_VOLTAGE "link_deformation_debug_voltages_raw_voltage"
/* END */

/* START */
#define LINK_DEFORMATION_FL_WHEEL "LINK_DEFORMATION_FL_WHEEL"

#define LINK_DEFORMATION_FL_WHEEL_ROD_ID "link_deformation_fl_wheel_rod_id"
#define LINK_DEFORMATION_FL_WHEEL_DEFORMATION "link_deformation_fl_wheel_deformation"
/* END */

/* START */
#define LINK_DEFORMATION_FR_WHEEL "LINK_DEFORMATION_FR_WHEEL"

#define LINK_DEFORMATION_FR_WHEEL_ROD_ID "link_deformation_fr_wheel_rod_id"
#define LINK_DEFORMATION_FR_WHEEL_DEFORMATION "link_deformation_fr_wheel_deformation"
/* END */

/* START */
#define LINK_DEFORMATION_RL_WHEEL "LINK_DEFORMATION_RL_WHEEL"

#define LINK_DEFORMATION_RL_WHEEL_ROD_ID "link_deformation_rl_wheel_rod_id"
#define LINK_DEFORMATION_RL_WHEEL_DEFORMATION "link_deformation_rl_wheel_deformation"
/* END */

/* START */
#define LINK_DEFORMATION_RR_WHEEL "LINK_DEFORMATION_RR_WHEEL"

#define LINK_DEFORMATION_RR_WHEEL_ROD_ID "link_deformation_rr_wheel_rod_id"
#define LINK_DEFORMATION_RR_WHEEL_DEFORMATION "link_deformation_rr_wheel_deformation"
/* END */

/* START */
#define LINK_DEFORMATION_SET_CALIBRATION "LINK_DEFORMATION_SET_CALIBRATION"

/* END */

/* START */
#define AMMO_COMPRESSION_SET_CALIBRATION "AMMO_COMPRESSION_SET_CALIBRATION"

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
#define COOLING_TEMP_PUMPS "COOLING_TEMP_PUMPS"

#define COOLING_TEMP_PUMPS_INPUT "cooling_temp_pumps_input"
#define COOLING_TEMP_PUMPS_OUTPUT "cooling_temp_pumps_output"
/* END */

/* START */
#define COOLING_TEMP_RADIATORS "COOLING_TEMP_RADIATORS"

#define COOLING_TEMP_RADIATORS_AIR_TEMP "cooling_temp_radiators_air_temp"
/* END */

enum secondary_types_id{
	e_secondary_uint16_t = -6,
	e_secondary_float,
	e_secondary_uint32_t,
	e_secondary_uint8_t,
	e_secondary_int16_t,
	e_secondary_uint64_t,

	e_secondary_link_deformation_debug_voltages_wheel_id,
	e_secondary_link_deformation_debug_voltages_rod_id,
	e_secondary_link_deformation_fl_wheel_rod_id,
	e_secondary_link_deformation_fr_wheel_rod_id,
	e_secondary_link_deformation_rl_wheel_rod_id,
	e_secondary_link_deformation_rr_wheel_rod_id
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
int secondary_fields_types_from_id(int id, int *fields_types, int fields_types_size);

/**
 * @brief get the fields of a message that are enums
 * 
 * @param[in] msg_name name of the message to find
 * @param[in] sgn_name name of the signal to find
 * 
 * @return fields' strings vector
*/
std::vector<std::string> secondary_enum_fields_from_message(const std::string& msg_name);

/**
 * @brief get the fields of an enum given the name of the message and the name of the signal
 * 
 * @param[in] msg_name name of the message to find
 * @param[in] sgn_name name of the signal to find
 * 
 * @return fields' strings vector
*/
std::vector<std::string> secondary_enum_names_from_fields(const std::string& msg_name, const std::string& sgn_name);


#endif
