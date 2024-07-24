#include "secondary_utils.h"

int secondary_fields_string_from_id(int id, char **v, size_t fields_size, size_t string_size)
{
	switch(id)
    {
	case 0:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, ACQUISINATOR_JMP_TO_BLT_ACQUISINATORE_ID);

		return 0;
	case 700:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, ACQUISINATOR_VERSION_ACQUISINATOR_ID);
		snprintf(v[1], string_size, ACQUISINATOR_VERSION_CANLIB_BUILD_TIME);

		return 0;
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
	case 1456:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, IRTS_FL_0_CHANNEL1);
		snprintf(v[1], string_size, IRTS_FL_0_CHANNEL2);
		snprintf(v[2], string_size, IRTS_FL_0_CHANNEL3);
		snprintf(v[3], string_size, IRTS_FL_0_CHANNEL4);

		return 0;
	case 1457:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, IRTS_FL_1_CHANNEL5);
		snprintf(v[1], string_size, IRTS_FL_1_CHANNEL6);
		snprintf(v[2], string_size, IRTS_FL_1_CHANNEL7);
		snprintf(v[3], string_size, IRTS_FL_1_CHANNEL8);

		return 0;
	case 1458:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, IRTS_FL_2_CHANNEL9);
		snprintf(v[1], string_size, IRTS_FL_2_CHANNEL10);
		snprintf(v[2], string_size, IRTS_FL_2_CHANNEL11);
		snprintf(v[3], string_size, IRTS_FL_2_CHANNEL12);

		return 0;
	case 1459:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, IRTS_FL_3_CHANNEL13);
		snprintf(v[1], string_size, IRTS_FL_3_CHANNEL14);
		snprintf(v[2], string_size, IRTS_FL_3_CHANNEL15);
		snprintf(v[3], string_size, IRTS_FL_3_CHANNEL16);

		return 0;
	case 1464:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, IRTS_FR_0_CHANNEL1);
		snprintf(v[1], string_size, IRTS_FR_0_CHANNEL2);
		snprintf(v[2], string_size, IRTS_FR_0_CHANNEL3);
		snprintf(v[3], string_size, IRTS_FR_0_CHANNEL4);

		return 0;
	case 1465:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, IRTS_FR_1_CHANNEL5);
		snprintf(v[1], string_size, IRTS_FR_1_CHANNEL6);
		snprintf(v[2], string_size, IRTS_FR_1_CHANNEL7);
		snprintf(v[3], string_size, IRTS_FR_1_CHANNEL8);

		return 0;
	case 1466:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, IRTS_FR_2_CHANNEL9);
		snprintf(v[1], string_size, IRTS_FR_2_CHANNEL10);
		snprintf(v[2], string_size, IRTS_FR_2_CHANNEL11);
		snprintf(v[3], string_size, IRTS_FR_2_CHANNEL12);

		return 0;
	case 1467:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, IRTS_FR_3_CHANNEL13);
		snprintf(v[1], string_size, IRTS_FR_3_CHANNEL14);
		snprintf(v[2], string_size, IRTS_FR_3_CHANNEL15);
		snprintf(v[3], string_size, IRTS_FR_3_CHANNEL16);

		return 0;
	case 1468:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, IRTS_RL_0_CHANNEL1);
		snprintf(v[1], string_size, IRTS_RL_0_CHANNEL2);
		snprintf(v[2], string_size, IRTS_RL_0_CHANNEL3);
		snprintf(v[3], string_size, IRTS_RL_0_CHANNEL4);

		return 0;
	case 1469:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, IRTS_RL_1_CHANNEL5);
		snprintf(v[1], string_size, IRTS_RL_1_CHANNEL6);
		snprintf(v[2], string_size, IRTS_RL_1_CHANNEL7);
		snprintf(v[3], string_size, IRTS_RL_1_CHANNEL8);

		return 0;
	case 1470:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, IRTS_RL_2_CHANNEL9);
		snprintf(v[1], string_size, IRTS_RL_2_CHANNEL10);
		snprintf(v[2], string_size, IRTS_RL_2_CHANNEL11);
		snprintf(v[3], string_size, IRTS_RL_2_CHANNEL12);

		return 0;
	case 1471:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, IRTS_RL_3_CHANNEL13);
		snprintf(v[1], string_size, IRTS_RL_3_CHANNEL14);
		snprintf(v[2], string_size, IRTS_RL_3_CHANNEL15);
		snprintf(v[3], string_size, IRTS_RL_3_CHANNEL16);

		return 0;
	case 1200:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, IRTS_RR_0_CHANNEL1);
		snprintf(v[1], string_size, IRTS_RR_0_CHANNEL2);
		snprintf(v[2], string_size, IRTS_RR_0_CHANNEL3);
		snprintf(v[3], string_size, IRTS_RR_0_CHANNEL4);

		return 0;
	case 1201:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, IRTS_RR_1_CHANNEL5);
		snprintf(v[1], string_size, IRTS_RR_1_CHANNEL6);
		snprintf(v[2], string_size, IRTS_RR_1_CHANNEL7);
		snprintf(v[3], string_size, IRTS_RR_1_CHANNEL8);

		return 0;
	case 1202:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, IRTS_RR_2_CHANNEL9);
		snprintf(v[1], string_size, IRTS_RR_2_CHANNEL10);
		snprintf(v[2], string_size, IRTS_RR_2_CHANNEL11);
		snprintf(v[3], string_size, IRTS_RR_2_CHANNEL12);

		return 0;
	case 1203:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, IRTS_RR_3_CHANNEL13);
		snprintf(v[1], string_size, IRTS_RR_3_CHANNEL14);
		snprintf(v[2], string_size, IRTS_RR_3_CHANNEL15);
		snprintf(v[3], string_size, IRTS_RR_3_CHANNEL16);

		return 0;
	case 1536:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, VEHICLE_POSITION_X);
		snprintf(v[1], string_size, VEHICLE_POSITION_Y);
		snprintf(v[2], string_size, VEHICLE_POSITION_HEADING);

		return 0;
	case 1544:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, VEHICLE_SPEED_U);
		snprintf(v[1], string_size, VEHICLE_SPEED_V);

		return 0;
	case 1552:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, VEHICLE_CURVILINEAR_COORDINATES_S);
		snprintf(v[1], string_size, VEHICLE_CURVILINEAR_COORDINATES_N);

		return 0;
	case 1560:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, FRONT_ANGULAR_VELOCITY_FL);
		snprintf(v[1], string_size, FRONT_ANGULAR_VELOCITY_FR);

		return 0;
	case 1568:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, REAR_ANGULAR_VELOCITY_RL);
		snprintf(v[1], string_size, REAR_ANGULAR_VELOCITY_RR);

		return 0;
	case 1576:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, HV_SOC_ESTIMATION_STATE_SOC);
		snprintf(v[1], string_size, HV_SOC_ESTIMATION_STATE_RC1);
		snprintf(v[2], string_size, HV_SOC_ESTIMATION_STATE_RC2);

		return 0;
	case 1584:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, HV_SOC_ESTIMATION_COVARIANCE_SOC);
		snprintf(v[1], string_size, HV_SOC_ESTIMATION_COVARIANCE_RC1);
		snprintf(v[2], string_size, HV_SOC_ESTIMATION_COVARIANCE_RC2);

		return 0;
	case 1592:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, LV_SOC_ESTIMATION_STATE_SOC);
		snprintf(v[1], string_size, LV_SOC_ESTIMATION_STATE_RC1);
		snprintf(v[2], string_size, LV_SOC_ESTIMATION_STATE_RC2);

		return 0;
	case 1600:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, LV_SOC_ESTIMATION_COVARIANCE_SOC);
		snprintf(v[1], string_size, LV_SOC_ESTIMATION_COVARIANCE_RC1);
		snprintf(v[2], string_size, LV_SOC_ESTIMATION_COVARIANCE_RC2);

		return 0;
	case 1608:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, PEDAL_THROTTLE_THROTTLE);

		return 0;
	case 1616:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, PEDAL_BRAKES_PRESSURE_FRONT);
		snprintf(v[1], string_size, PEDAL_BRAKES_PRESSURE_REAR);

		return 0;
	case 1624:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, STEER_ANGLE_ANGLE);

		return 0;
	case 1632:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, ODOMETER_KILOMETERS);

		return 0;
	case 1640:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, TPMS_PRESSURE_FL);
		snprintf(v[1], string_size, TPMS_PRESSURE_FR);
		snprintf(v[2], string_size, TPMS_PRESSURE_RL);
		snprintf(v[3], string_size, TPMS_PRESSURE_RR);

		return 0;
	case 1648:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, TPMS_TEMPERATURE_FL);
		snprintf(v[1], string_size, TPMS_TEMPERATURE_FR);
		snprintf(v[2], string_size, TPMS_TEMPERATURE_RL);
		snprintf(v[3], string_size, TPMS_TEMPERATURE_RR);

		return 0;
	case 1656:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, TLM_UNIX_TIMESTAMP_TIMESTAMP);

		return 0;
	case 1664:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, TLM_LAP_TIME_LAP_COUNT);
		snprintf(v[1], string_size, TLM_LAP_TIME_LAP_TIME);

		return 0;
	case 1672:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, TLM_LAPS_STATS_LAP_NUMBER);
		snprintf(v[1], string_size, TLM_LAPS_STATS_BEST_TIME);
		snprintf(v[2], string_size, TLM_LAPS_STATS_LAST_TIME);

		return 0;
	case 1680:
		if(5 > fields_size) return 1;
		snprintf(v[0], string_size, TLM_NETWORK_INTERFACE_INAME_0);
		snprintf(v[1], string_size, TLM_NETWORK_INTERFACE_INAME_1);
		snprintf(v[2], string_size, TLM_NETWORK_INTERFACE_INAME_2);
		snprintf(v[3], string_size, TLM_NETWORK_INTERFACE_INAME_3);
		snprintf(v[4], string_size, TLM_NETWORK_INTERFACE_IP_ADDRESS);

		return 0;
	case 1688:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, AMMO_COMPRESSION_RL);
		snprintf(v[1], string_size, AMMO_COMPRESSION_RR);
		snprintf(v[2], string_size, AMMO_COMPRESSION_FL);
		snprintf(v[3], string_size, AMMO_COMPRESSION_FR);

		return 0;
	case 1696:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, ACQUISINATOR_CALIBRATIONS_OFFSETS_ACQUISINATOR_ID);
		snprintf(v[1], string_size, ACQUISINATOR_CALIBRATIONS_OFFSETS_OFFSET1);
		snprintf(v[2], string_size, ACQUISINATOR_CALIBRATIONS_OFFSETS_OFFSET2);

		return 0;
	case 1704:
		if(5 > fields_size) return 1;
		snprintf(v[0], string_size, ACQUISINATOR_ERRORS_ACQUISINATOR_ID);
		snprintf(v[1], string_size, ACQUISINATOR_ERRORS_ACQUISINATOR_ERRORS_ACQUISINATORE_LED_CODE_CAN_NOT_WORKING);
		snprintf(v[2], string_size, ACQUISINATOR_ERRORS_ACQUISINATOR_ERRORS_ACQUISINATORE_LED_CODE_SPI_ERROR);
		snprintf(v[3], string_size, ACQUISINATOR_ERRORS_ACQUISINATOR_ERRORS_ACQUISINATORE_LED_CODE_READ_WRITE_FLASH);
		snprintf(v[4], string_size, ACQUISINATOR_ERRORS_ACQUISINATOR_ERRORS_ACQUISINATORE_LED_CODE_FLASHED_FIRMWARE_WITH_WRONG_ID);

		return 0;
	case 1712:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, LINK_DEFORMATION_DEBUG_VOLTAGES_WHEEL_ID);
		snprintf(v[1], string_size, LINK_DEFORMATION_DEBUG_VOLTAGES_ROD_ID);
		snprintf(v[2], string_size, LINK_DEFORMATION_DEBUG_VOLTAGES_RAW_VOLTAGE);

		return 0;
	case 1720:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, LINK_DEFORMATION_FL_WHEEL_ROD_ID);
		snprintf(v[1], string_size, LINK_DEFORMATION_FL_WHEEL_DEFORMATION);

		return 0;
	case 1728:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, LINK_DEFORMATION_FR_WHEEL_ROD_ID);
		snprintf(v[1], string_size, LINK_DEFORMATION_FR_WHEEL_DEFORMATION);

		return 0;
	case 1736:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, LINK_DEFORMATION_RL_WHEEL_ROD_ID);
		snprintf(v[1], string_size, LINK_DEFORMATION_RL_WHEEL_DEFORMATION);

		return 0;
	case 1744:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, LINK_DEFORMATION_RR_WHEEL_ROD_ID);
		snprintf(v[1], string_size, LINK_DEFORMATION_RR_WHEEL_DEFORMATION);

		return 0;
	case 1752:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, DEBUG_SIGNAL_5_DEVICE_ID);
		snprintf(v[1], string_size, DEBUG_SIGNAL_5_FIELD_1);
		snprintf(v[2], string_size, DEBUG_SIGNAL_5_FIELD_2);
		snprintf(v[3], string_size, DEBUG_SIGNAL_5_FIELD_3);

		return 0;
	case 1760:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, DEBUG_SIGNAL_6_DEVICE_ID);
		snprintf(v[1], string_size, DEBUG_SIGNAL_6_FIELD_1);
		snprintf(v[2], string_size, DEBUG_SIGNAL_6_FIELD_2);
		snprintf(v[3], string_size, DEBUG_SIGNAL_6_FIELD_3);

		return 0;
	case 1768:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, DEBUG_SIGNAL_7_DEVICE_ID);
		snprintf(v[1], string_size, DEBUG_SIGNAL_7_FIELD_1);
		snprintf(v[2], string_size, DEBUG_SIGNAL_7_FIELD_2);
		snprintf(v[3], string_size, DEBUG_SIGNAL_7_FIELD_3);

		return 0;
	case 1776:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, DEBUG_SIGNAL_8_DEVICE_ID);
		snprintf(v[1], string_size, DEBUG_SIGNAL_8_FIELD_1);
		snprintf(v[2], string_size, DEBUG_SIGNAL_8_FIELD_2);
		snprintf(v[3], string_size, DEBUG_SIGNAL_8_FIELD_3);

		return 0;
	case 1784:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, COOLING_TEMP_PUMPS_INPUT);
		snprintf(v[1], string_size, COOLING_TEMP_PUMPS_OUTPUT);

		return 0;
	case 1792:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, COOLING_TEMP_RADIATORS_AIR_TEMP);

		return 0;

    }
    return 0;
}
int secondary_enum_fields(int enum_id, char **v, size_t fields_size, size_t string_size)
{
    switch(enum_id)
    {
	case 0:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, "secondary_link_deformation_debug_voltages_wheel_id_fl");
		snprintf(v[1], string_size, "secondary_link_deformation_debug_voltages_wheel_id_fr");
		snprintf(v[2], string_size, "secondary_link_deformation_debug_voltages_wheel_id_rl");
		snprintf(v[3], string_size, "secondary_link_deformation_debug_voltages_wheel_id_rr");

		return 0;
	case 1:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, "secondary_link_deformation_debug_voltages_rod_id_F1011");
		snprintf(v[1], string_size, "secondary_link_deformation_debug_voltages_rod_id_F36");
		snprintf(v[2], string_size, "secondary_link_deformation_debug_voltages_rod_id_F46");
		snprintf(v[3], string_size, "secondary_link_deformation_debug_voltages_rod_id_F27");
		snprintf(v[4], string_size, "secondary_link_deformation_debug_voltages_rod_id_F17");
		snprintf(v[5], string_size, "secondary_link_deformation_debug_voltages_rod_id_F58");

		return 0;
	case 2:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, "secondary_link_deformation_fl_wheel_rod_id_F1011");
		snprintf(v[1], string_size, "secondary_link_deformation_fl_wheel_rod_id_F36");
		snprintf(v[2], string_size, "secondary_link_deformation_fl_wheel_rod_id_F46");
		snprintf(v[3], string_size, "secondary_link_deformation_fl_wheel_rod_id_F27");
		snprintf(v[4], string_size, "secondary_link_deformation_fl_wheel_rod_id_F17");
		snprintf(v[5], string_size, "secondary_link_deformation_fl_wheel_rod_id_F58");

		return 0;
	case 3:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, "secondary_link_deformation_fr_wheel_rod_id_F1011");
		snprintf(v[1], string_size, "secondary_link_deformation_fr_wheel_rod_id_F36");
		snprintf(v[2], string_size, "secondary_link_deformation_fr_wheel_rod_id_F46");
		snprintf(v[3], string_size, "secondary_link_deformation_fr_wheel_rod_id_F27");
		snprintf(v[4], string_size, "secondary_link_deformation_fr_wheel_rod_id_F17");
		snprintf(v[5], string_size, "secondary_link_deformation_fr_wheel_rod_id_F58");

		return 0;
	case 4:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, "secondary_link_deformation_rl_wheel_rod_id_F1011");
		snprintf(v[1], string_size, "secondary_link_deformation_rl_wheel_rod_id_F36");
		snprintf(v[2], string_size, "secondary_link_deformation_rl_wheel_rod_id_F46");
		snprintf(v[3], string_size, "secondary_link_deformation_rl_wheel_rod_id_F27");
		snprintf(v[4], string_size, "secondary_link_deformation_rl_wheel_rod_id_F17");
		snprintf(v[5], string_size, "secondary_link_deformation_rl_wheel_rod_id_F58");

		return 0;
	case 5:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, "secondary_link_deformation_rr_wheel_rod_id_F1011");
		snprintf(v[1], string_size, "secondary_link_deformation_rr_wheel_rod_id_F36");
		snprintf(v[2], string_size, "secondary_link_deformation_rr_wheel_rod_id_F46");
		snprintf(v[3], string_size, "secondary_link_deformation_rr_wheel_rod_id_F27");
		snprintf(v[4], string_size, "secondary_link_deformation_rr_wheel_rod_id_F17");
		snprintf(v[5], string_size, "secondary_link_deformation_rr_wheel_rod_id_F58");

		return 0;
	case 6:
		if(9 > fields_size) return 1;
		snprintf(v[0], string_size, "secondary_debug_signal_5_device_id_hv_mainboard");
		snprintf(v[1], string_size, "secondary_debug_signal_5_device_id_hv_cellboard");
		snprintf(v[2], string_size, "secondary_debug_signal_5_device_id_lv");
		snprintf(v[3], string_size, "secondary_debug_signal_5_device_id_ecu");
		snprintf(v[4], string_size, "secondary_debug_signal_5_device_id_tlm");
		snprintf(v[5], string_size, "secondary_debug_signal_5_device_id_traction_control");
		snprintf(v[6], string_size, "secondary_debug_signal_5_device_id_steeering_wheel");
		snprintf(v[7], string_size, "secondary_debug_signal_5_device_id_handcart");
		snprintf(v[8], string_size, "secondary_debug_signal_5_device_id_acquisinator");

		return 0;
	case 7:
		if(9 > fields_size) return 1;
		snprintf(v[0], string_size, "secondary_debug_signal_6_device_id_hv_mainboard");
		snprintf(v[1], string_size, "secondary_debug_signal_6_device_id_hv_cellboard");
		snprintf(v[2], string_size, "secondary_debug_signal_6_device_id_lv");
		snprintf(v[3], string_size, "secondary_debug_signal_6_device_id_ecu");
		snprintf(v[4], string_size, "secondary_debug_signal_6_device_id_tlm");
		snprintf(v[5], string_size, "secondary_debug_signal_6_device_id_traction_control");
		snprintf(v[6], string_size, "secondary_debug_signal_6_device_id_steeering_wheel");
		snprintf(v[7], string_size, "secondary_debug_signal_6_device_id_handcart");
		snprintf(v[8], string_size, "secondary_debug_signal_6_device_id_acquisinator");

		return 0;
	case 8:
		if(9 > fields_size) return 1;
		snprintf(v[0], string_size, "secondary_debug_signal_7_device_id_hv_mainboard");
		snprintf(v[1], string_size, "secondary_debug_signal_7_device_id_hv_cellboard");
		snprintf(v[2], string_size, "secondary_debug_signal_7_device_id_lv");
		snprintf(v[3], string_size, "secondary_debug_signal_7_device_id_ecu");
		snprintf(v[4], string_size, "secondary_debug_signal_7_device_id_tlm");
		snprintf(v[5], string_size, "secondary_debug_signal_7_device_id_traction_control");
		snprintf(v[6], string_size, "secondary_debug_signal_7_device_id_steeering_wheel");
		snprintf(v[7], string_size, "secondary_debug_signal_7_device_id_handcart");
		snprintf(v[8], string_size, "secondary_debug_signal_7_device_id_acquisinator");

		return 0;
	case 9:
		if(9 > fields_size) return 1;
		snprintf(v[0], string_size, "secondary_debug_signal_8_device_id_hv_mainboard");
		snprintf(v[1], string_size, "secondary_debug_signal_8_device_id_hv_cellboard");
		snprintf(v[2], string_size, "secondary_debug_signal_8_device_id_lv");
		snprintf(v[3], string_size, "secondary_debug_signal_8_device_id_ecu");
		snprintf(v[4], string_size, "secondary_debug_signal_8_device_id_tlm");
		snprintf(v[5], string_size, "secondary_debug_signal_8_device_id_traction_control");
		snprintf(v[6], string_size, "secondary_debug_signal_8_device_id_steeering_wheel");
		snprintf(v[7], string_size, "secondary_debug_signal_8_device_id_handcart");
		snprintf(v[8], string_size, "secondary_debug_signal_8_device_id_acquisinator");

		return 0;

    }
    return 0;
}
int secondary_serialize_from_string(int id, char *s, uint8_t *data, size_t *size)
{
    switch(id)
    {
	case 0:
	{
		secondary_acquisinator_jmp_to_blt_t tmp;
		secondary_acquisinator_jmp_to_blt_converted_t tmp_converted;
		uint8_t r_acquisinatore_id;

		sscanf(s, "%" SCNu8 ","  ,
			&r_acquisinatore_id);
		tmp_converted.acquisinatore_id = (uint8_t)r_acquisinatore_id;

		secondary_acquisinator_jmp_to_blt_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_ACQUISINATOR_JMP_TO_BLT_BYTE_SIZE;
		return secondary_acquisinator_jmp_to_blt_pack(data, &tmp, SECONDARY_ACQUISINATOR_JMP_TO_BLT_BYTE_SIZE);
	}
	case 700:
	{
		secondary_acquisinator_version_t tmp;
		secondary_acquisinator_version_converted_t tmp_converted;
		uint8_t r_acquisinator_id;
		uint32_t r_canlib_build_time;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu32 "," ,
			&r_acquisinator_id,
			&r_canlib_build_time);
		tmp_converted.acquisinator_id = (uint8_t)r_acquisinator_id;
		tmp_converted.canlib_build_time = (uint32_t)r_canlib_build_time;

		secondary_acquisinator_version_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_ACQUISINATOR_VERSION_BYTE_SIZE;
		return secondary_acquisinator_version_pack(data, &tmp, SECONDARY_ACQUISINATOR_VERSION_BYTE_SIZE);
	}
	case 1260:
	{
		secondary_imu_angular_rate_t tmp;
		secondary_imu_angular_rate_converted_t tmp_converted;
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

		secondary_imu_angular_rate_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_IMU_ANGULAR_RATE_BYTE_SIZE;
		return secondary_imu_angular_rate_pack(data, &tmp, SECONDARY_IMU_ANGULAR_RATE_BYTE_SIZE);
	}
	case 1261:
	{
		secondary_imu_acceleration_t tmp;
		secondary_imu_acceleration_converted_t tmp_converted;
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

		secondary_imu_acceleration_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_IMU_ACCELERATION_BYTE_SIZE;
		return secondary_imu_acceleration_pack(data, &tmp, SECONDARY_IMU_ACCELERATION_BYTE_SIZE);
	}
	case 1456:
	{
		secondary_irts_fl_0_t tmp;
		secondary_irts_fl_0_converted_t tmp_converted;
		float r_channel1;
		float r_channel2;
		float r_channel3;
		float r_channel4;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_channel1,
			&r_channel2,
			&r_channel3,
			&r_channel4);
		tmp_converted.channel1 = (float)r_channel1;
		tmp_converted.channel2 = (float)r_channel2;
		tmp_converted.channel3 = (float)r_channel3;
		tmp_converted.channel4 = (float)r_channel4;

		secondary_irts_fl_0_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_IRTS_FL_0_BYTE_SIZE;
		return secondary_irts_fl_0_pack(data, &tmp, SECONDARY_IRTS_FL_0_BYTE_SIZE);
	}
	case 1457:
	{
		secondary_irts_fl_1_t tmp;
		secondary_irts_fl_1_converted_t tmp_converted;
		float r_channel5;
		float r_channel6;
		float r_channel7;
		float r_channel8;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_channel5,
			&r_channel6,
			&r_channel7,
			&r_channel8);
		tmp_converted.channel5 = (float)r_channel5;
		tmp_converted.channel6 = (float)r_channel6;
		tmp_converted.channel7 = (float)r_channel7;
		tmp_converted.channel8 = (float)r_channel8;

		secondary_irts_fl_1_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_IRTS_FL_1_BYTE_SIZE;
		return secondary_irts_fl_1_pack(data, &tmp, SECONDARY_IRTS_FL_1_BYTE_SIZE);
	}
	case 1458:
	{
		secondary_irts_fl_2_t tmp;
		secondary_irts_fl_2_converted_t tmp_converted;
		float r_channel9;
		float r_channel10;
		float r_channel11;
		float r_channel12;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_channel9,
			&r_channel10,
			&r_channel11,
			&r_channel12);
		tmp_converted.channel9 = (float)r_channel9;
		tmp_converted.channel10 = (float)r_channel10;
		tmp_converted.channel11 = (float)r_channel11;
		tmp_converted.channel12 = (float)r_channel12;

		secondary_irts_fl_2_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_IRTS_FL_2_BYTE_SIZE;
		return secondary_irts_fl_2_pack(data, &tmp, SECONDARY_IRTS_FL_2_BYTE_SIZE);
	}
	case 1459:
	{
		secondary_irts_fl_3_t tmp;
		secondary_irts_fl_3_converted_t tmp_converted;
		float r_channel13;
		float r_channel14;
		float r_channel15;
		float r_channel16;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_channel13,
			&r_channel14,
			&r_channel15,
			&r_channel16);
		tmp_converted.channel13 = (float)r_channel13;
		tmp_converted.channel14 = (float)r_channel14;
		tmp_converted.channel15 = (float)r_channel15;
		tmp_converted.channel16 = (float)r_channel16;

		secondary_irts_fl_3_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_IRTS_FL_3_BYTE_SIZE;
		return secondary_irts_fl_3_pack(data, &tmp, SECONDARY_IRTS_FL_3_BYTE_SIZE);
	}
	case 1464:
	{
		secondary_irts_fr_0_t tmp;
		secondary_irts_fr_0_converted_t tmp_converted;
		float r_channel1;
		float r_channel2;
		float r_channel3;
		float r_channel4;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_channel1,
			&r_channel2,
			&r_channel3,
			&r_channel4);
		tmp_converted.channel1 = (float)r_channel1;
		tmp_converted.channel2 = (float)r_channel2;
		tmp_converted.channel3 = (float)r_channel3;
		tmp_converted.channel4 = (float)r_channel4;

		secondary_irts_fr_0_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_IRTS_FR_0_BYTE_SIZE;
		return secondary_irts_fr_0_pack(data, &tmp, SECONDARY_IRTS_FR_0_BYTE_SIZE);
	}
	case 1465:
	{
		secondary_irts_fr_1_t tmp;
		secondary_irts_fr_1_converted_t tmp_converted;
		float r_channel5;
		float r_channel6;
		float r_channel7;
		float r_channel8;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_channel5,
			&r_channel6,
			&r_channel7,
			&r_channel8);
		tmp_converted.channel5 = (float)r_channel5;
		tmp_converted.channel6 = (float)r_channel6;
		tmp_converted.channel7 = (float)r_channel7;
		tmp_converted.channel8 = (float)r_channel8;

		secondary_irts_fr_1_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_IRTS_FR_1_BYTE_SIZE;
		return secondary_irts_fr_1_pack(data, &tmp, SECONDARY_IRTS_FR_1_BYTE_SIZE);
	}
	case 1466:
	{
		secondary_irts_fr_2_t tmp;
		secondary_irts_fr_2_converted_t tmp_converted;
		float r_channel9;
		float r_channel10;
		float r_channel11;
		float r_channel12;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_channel9,
			&r_channel10,
			&r_channel11,
			&r_channel12);
		tmp_converted.channel9 = (float)r_channel9;
		tmp_converted.channel10 = (float)r_channel10;
		tmp_converted.channel11 = (float)r_channel11;
		tmp_converted.channel12 = (float)r_channel12;

		secondary_irts_fr_2_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_IRTS_FR_2_BYTE_SIZE;
		return secondary_irts_fr_2_pack(data, &tmp, SECONDARY_IRTS_FR_2_BYTE_SIZE);
	}
	case 1467:
	{
		secondary_irts_fr_3_t tmp;
		secondary_irts_fr_3_converted_t tmp_converted;
		float r_channel13;
		float r_channel14;
		float r_channel15;
		float r_channel16;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_channel13,
			&r_channel14,
			&r_channel15,
			&r_channel16);
		tmp_converted.channel13 = (float)r_channel13;
		tmp_converted.channel14 = (float)r_channel14;
		tmp_converted.channel15 = (float)r_channel15;
		tmp_converted.channel16 = (float)r_channel16;

		secondary_irts_fr_3_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_IRTS_FR_3_BYTE_SIZE;
		return secondary_irts_fr_3_pack(data, &tmp, SECONDARY_IRTS_FR_3_BYTE_SIZE);
	}
	case 1468:
	{
		secondary_irts_rl_0_t tmp;
		secondary_irts_rl_0_converted_t tmp_converted;
		float r_channel1;
		float r_channel2;
		float r_channel3;
		float r_channel4;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_channel1,
			&r_channel2,
			&r_channel3,
			&r_channel4);
		tmp_converted.channel1 = (float)r_channel1;
		tmp_converted.channel2 = (float)r_channel2;
		tmp_converted.channel3 = (float)r_channel3;
		tmp_converted.channel4 = (float)r_channel4;

		secondary_irts_rl_0_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_IRTS_RL_0_BYTE_SIZE;
		return secondary_irts_rl_0_pack(data, &tmp, SECONDARY_IRTS_RL_0_BYTE_SIZE);
	}
	case 1469:
	{
		secondary_irts_rl_1_t tmp;
		secondary_irts_rl_1_converted_t tmp_converted;
		float r_channel5;
		float r_channel6;
		float r_channel7;
		float r_channel8;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_channel5,
			&r_channel6,
			&r_channel7,
			&r_channel8);
		tmp_converted.channel5 = (float)r_channel5;
		tmp_converted.channel6 = (float)r_channel6;
		tmp_converted.channel7 = (float)r_channel7;
		tmp_converted.channel8 = (float)r_channel8;

		secondary_irts_rl_1_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_IRTS_RL_1_BYTE_SIZE;
		return secondary_irts_rl_1_pack(data, &tmp, SECONDARY_IRTS_RL_1_BYTE_SIZE);
	}
	case 1470:
	{
		secondary_irts_rl_2_t tmp;
		secondary_irts_rl_2_converted_t tmp_converted;
		float r_channel9;
		float r_channel10;
		float r_channel11;
		float r_channel12;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_channel9,
			&r_channel10,
			&r_channel11,
			&r_channel12);
		tmp_converted.channel9 = (float)r_channel9;
		tmp_converted.channel10 = (float)r_channel10;
		tmp_converted.channel11 = (float)r_channel11;
		tmp_converted.channel12 = (float)r_channel12;

		secondary_irts_rl_2_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_IRTS_RL_2_BYTE_SIZE;
		return secondary_irts_rl_2_pack(data, &tmp, SECONDARY_IRTS_RL_2_BYTE_SIZE);
	}
	case 1471:
	{
		secondary_irts_rl_3_t tmp;
		secondary_irts_rl_3_converted_t tmp_converted;
		float r_channel13;
		float r_channel14;
		float r_channel15;
		float r_channel16;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_channel13,
			&r_channel14,
			&r_channel15,
			&r_channel16);
		tmp_converted.channel13 = (float)r_channel13;
		tmp_converted.channel14 = (float)r_channel14;
		tmp_converted.channel15 = (float)r_channel15;
		tmp_converted.channel16 = (float)r_channel16;

		secondary_irts_rl_3_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_IRTS_RL_3_BYTE_SIZE;
		return secondary_irts_rl_3_pack(data, &tmp, SECONDARY_IRTS_RL_3_BYTE_SIZE);
	}
	case 1200:
	{
		secondary_irts_rr_0_t tmp;
		secondary_irts_rr_0_converted_t tmp_converted;
		float r_channel1;
		float r_channel2;
		float r_channel3;
		float r_channel4;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_channel1,
			&r_channel2,
			&r_channel3,
			&r_channel4);
		tmp_converted.channel1 = (float)r_channel1;
		tmp_converted.channel2 = (float)r_channel2;
		tmp_converted.channel3 = (float)r_channel3;
		tmp_converted.channel4 = (float)r_channel4;

		secondary_irts_rr_0_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_IRTS_RR_0_BYTE_SIZE;
		return secondary_irts_rr_0_pack(data, &tmp, SECONDARY_IRTS_RR_0_BYTE_SIZE);
	}
	case 1201:
	{
		secondary_irts_rr_1_t tmp;
		secondary_irts_rr_1_converted_t tmp_converted;
		float r_channel5;
		float r_channel6;
		float r_channel7;
		float r_channel8;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_channel5,
			&r_channel6,
			&r_channel7,
			&r_channel8);
		tmp_converted.channel5 = (float)r_channel5;
		tmp_converted.channel6 = (float)r_channel6;
		tmp_converted.channel7 = (float)r_channel7;
		tmp_converted.channel8 = (float)r_channel8;

		secondary_irts_rr_1_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_IRTS_RR_1_BYTE_SIZE;
		return secondary_irts_rr_1_pack(data, &tmp, SECONDARY_IRTS_RR_1_BYTE_SIZE);
	}
	case 1202:
	{
		secondary_irts_rr_2_t tmp;
		secondary_irts_rr_2_converted_t tmp_converted;
		float r_channel9;
		float r_channel10;
		float r_channel11;
		float r_channel12;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_channel9,
			&r_channel10,
			&r_channel11,
			&r_channel12);
		tmp_converted.channel9 = (float)r_channel9;
		tmp_converted.channel10 = (float)r_channel10;
		tmp_converted.channel11 = (float)r_channel11;
		tmp_converted.channel12 = (float)r_channel12;

		secondary_irts_rr_2_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_IRTS_RR_2_BYTE_SIZE;
		return secondary_irts_rr_2_pack(data, &tmp, SECONDARY_IRTS_RR_2_BYTE_SIZE);
	}
	case 1203:
	{
		secondary_irts_rr_3_t tmp;
		secondary_irts_rr_3_converted_t tmp_converted;
		float r_channel13;
		float r_channel14;
		float r_channel15;
		float r_channel16;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_channel13,
			&r_channel14,
			&r_channel15,
			&r_channel16);
		tmp_converted.channel13 = (float)r_channel13;
		tmp_converted.channel14 = (float)r_channel14;
		tmp_converted.channel15 = (float)r_channel15;
		tmp_converted.channel16 = (float)r_channel16;

		secondary_irts_rr_3_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_IRTS_RR_3_BYTE_SIZE;
		return secondary_irts_rr_3_pack(data, &tmp, SECONDARY_IRTS_RR_3_BYTE_SIZE);
	}
	case 1536:
	{
		secondary_vehicle_position_t tmp;
		secondary_vehicle_position_converted_t tmp_converted;
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

		secondary_vehicle_position_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_VEHICLE_POSITION_BYTE_SIZE;
		return secondary_vehicle_position_pack(data, &tmp, SECONDARY_VEHICLE_POSITION_BYTE_SIZE);
	}
	case 1544:
	{
		secondary_vehicle_speed_t tmp;
		secondary_vehicle_speed_converted_t tmp_converted;
		float r_u;
		float r_v;

		sscanf(s, "%f,"       
			"%f,"       ,
			&r_u,
			&r_v);
		tmp_converted.u = (float)r_u;
		tmp_converted.v = (float)r_v;

		secondary_vehicle_speed_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_VEHICLE_SPEED_BYTE_SIZE;
		return secondary_vehicle_speed_pack(data, &tmp, SECONDARY_VEHICLE_SPEED_BYTE_SIZE);
	}
	case 1552:
	{
		secondary_vehicle_curvilinear_coordinates_t tmp;
		secondary_vehicle_curvilinear_coordinates_converted_t tmp_converted;
		float r_s;
		float r_n;

		sscanf(s, "%f,"       
			"%f,"       ,
			&r_s,
			&r_n);
		tmp_converted.s = (float)r_s;
		tmp_converted.n = (float)r_n;

		secondary_vehicle_curvilinear_coordinates_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_VEHICLE_CURVILINEAR_COORDINATES_BYTE_SIZE;
		return secondary_vehicle_curvilinear_coordinates_pack(data, &tmp, SECONDARY_VEHICLE_CURVILINEAR_COORDINATES_BYTE_SIZE);
	}
	case 1560:
	{
		secondary_front_angular_velocity_t tmp;
		secondary_front_angular_velocity_converted_t tmp_converted;
		float r_fl;
		float r_fr;

		sscanf(s, "%f,"       
			"%f,"       ,
			&r_fl,
			&r_fr);
		tmp_converted.fl = (float)r_fl;
		tmp_converted.fr = (float)r_fr;

		secondary_front_angular_velocity_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_FRONT_ANGULAR_VELOCITY_BYTE_SIZE;
		return secondary_front_angular_velocity_pack(data, &tmp, SECONDARY_FRONT_ANGULAR_VELOCITY_BYTE_SIZE);
	}
	case 1568:
	{
		secondary_rear_angular_velocity_t tmp;
		secondary_rear_angular_velocity_converted_t tmp_converted;
		float r_rl;
		float r_rr;

		sscanf(s, "%f,"       
			"%f,"       ,
			&r_rl,
			&r_rr);
		tmp_converted.rl = (float)r_rl;
		tmp_converted.rr = (float)r_rr;

		secondary_rear_angular_velocity_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_REAR_ANGULAR_VELOCITY_BYTE_SIZE;
		return secondary_rear_angular_velocity_pack(data, &tmp, SECONDARY_REAR_ANGULAR_VELOCITY_BYTE_SIZE);
	}
	case 1576:
	{
		secondary_hv_soc_estimation_state_t tmp;
		secondary_hv_soc_estimation_state_converted_t tmp_converted;
		float r_soc;
		float r_rc1;
		float r_rc2;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       ,
			&r_soc,
			&r_rc1,
			&r_rc2);
		tmp_converted.soc = (float)r_soc;
		tmp_converted.rc1 = (float)r_rc1;
		tmp_converted.rc2 = (float)r_rc2;

		secondary_hv_soc_estimation_state_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_HV_SOC_ESTIMATION_STATE_BYTE_SIZE;
		return secondary_hv_soc_estimation_state_pack(data, &tmp, SECONDARY_HV_SOC_ESTIMATION_STATE_BYTE_SIZE);
	}
	case 1584:
	{
		secondary_hv_soc_estimation_covariance_t tmp;
		secondary_hv_soc_estimation_covariance_converted_t tmp_converted;
		float r_soc;
		float r_rc1;
		float r_rc2;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       ,
			&r_soc,
			&r_rc1,
			&r_rc2);
		tmp_converted.soc = (float)r_soc;
		tmp_converted.rc1 = (float)r_rc1;
		tmp_converted.rc2 = (float)r_rc2;

		secondary_hv_soc_estimation_covariance_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_HV_SOC_ESTIMATION_COVARIANCE_BYTE_SIZE;
		return secondary_hv_soc_estimation_covariance_pack(data, &tmp, SECONDARY_HV_SOC_ESTIMATION_COVARIANCE_BYTE_SIZE);
	}
	case 1592:
	{
		secondary_lv_soc_estimation_state_t tmp;
		secondary_lv_soc_estimation_state_converted_t tmp_converted;
		float r_soc;
		float r_rc1;
		float r_rc2;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       ,
			&r_soc,
			&r_rc1,
			&r_rc2);
		tmp_converted.soc = (float)r_soc;
		tmp_converted.rc1 = (float)r_rc1;
		tmp_converted.rc2 = (float)r_rc2;

		secondary_lv_soc_estimation_state_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_LV_SOC_ESTIMATION_STATE_BYTE_SIZE;
		return secondary_lv_soc_estimation_state_pack(data, &tmp, SECONDARY_LV_SOC_ESTIMATION_STATE_BYTE_SIZE);
	}
	case 1600:
	{
		secondary_lv_soc_estimation_covariance_t tmp;
		secondary_lv_soc_estimation_covariance_converted_t tmp_converted;
		float r_soc;
		float r_rc1;
		float r_rc2;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       ,
			&r_soc,
			&r_rc1,
			&r_rc2);
		tmp_converted.soc = (float)r_soc;
		tmp_converted.rc1 = (float)r_rc1;
		tmp_converted.rc2 = (float)r_rc2;

		secondary_lv_soc_estimation_covariance_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_LV_SOC_ESTIMATION_COVARIANCE_BYTE_SIZE;
		return secondary_lv_soc_estimation_covariance_pack(data, &tmp, SECONDARY_LV_SOC_ESTIMATION_COVARIANCE_BYTE_SIZE);
	}
	case 1608:
	{
		secondary_pedal_throttle_t tmp;
		secondary_pedal_throttle_converted_t tmp_converted;
		float r_throttle;

		sscanf(s, "%f,"       ,
			&r_throttle);
		tmp_converted.throttle = (float)r_throttle;

		secondary_pedal_throttle_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_PEDAL_THROTTLE_BYTE_SIZE;
		return secondary_pedal_throttle_pack(data, &tmp, SECONDARY_PEDAL_THROTTLE_BYTE_SIZE);
	}
	case 1616:
	{
		secondary_pedal_brakes_pressure_t tmp;
		secondary_pedal_brakes_pressure_converted_t tmp_converted;
		float r_front;
		float r_rear;

		sscanf(s, "%f,"       
			"%f,"       ,
			&r_front,
			&r_rear);
		tmp_converted.front = (float)r_front;
		tmp_converted.rear = (float)r_rear;

		secondary_pedal_brakes_pressure_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_PEDAL_BRAKES_PRESSURE_BYTE_SIZE;
		return secondary_pedal_brakes_pressure_pack(data, &tmp, SECONDARY_PEDAL_BRAKES_PRESSURE_BYTE_SIZE);
	}
	case 1624:
	{
		secondary_steer_angle_t tmp;
		secondary_steer_angle_converted_t tmp_converted;
		float r_angle;

		sscanf(s, "%f,"       ,
			&r_angle);
		tmp_converted.angle = (float)r_angle;

		secondary_steer_angle_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_STEER_ANGLE_BYTE_SIZE;
		return secondary_steer_angle_pack(data, &tmp, SECONDARY_STEER_ANGLE_BYTE_SIZE);
	}
	case 1632:
	{
		secondary_odometer_t tmp;
		secondary_odometer_converted_t tmp_converted;
		float r_kilometers;

		sscanf(s, "%f,"       ,
			&r_kilometers);
		tmp_converted.kilometers = (float)r_kilometers;

		secondary_odometer_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_ODOMETER_BYTE_SIZE;
		return secondary_odometer_pack(data, &tmp, SECONDARY_ODOMETER_BYTE_SIZE);
	}
	case 1640:
	{
		secondary_tpms_pressure_t tmp;
		secondary_tpms_pressure_converted_t tmp_converted;
		uint8_t r_fl;
		uint8_t r_fr;
		uint8_t r_rl;
		uint8_t r_rr;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  ,
			&r_fl,
			&r_fr,
			&r_rl,
			&r_rr);
		tmp_converted.fl = (uint8_t)r_fl;
		tmp_converted.fr = (uint8_t)r_fr;
		tmp_converted.rl = (uint8_t)r_rl;
		tmp_converted.rr = (uint8_t)r_rr;

		secondary_tpms_pressure_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_TPMS_PRESSURE_BYTE_SIZE;
		return secondary_tpms_pressure_pack(data, &tmp, SECONDARY_TPMS_PRESSURE_BYTE_SIZE);
	}
	case 1648:
	{
		secondary_tpms_temperature_t tmp;
		secondary_tpms_temperature_converted_t tmp_converted;
		uint8_t r_fl;
		uint8_t r_fr;
		uint8_t r_rl;
		uint8_t r_rr;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  ,
			&r_fl,
			&r_fr,
			&r_rl,
			&r_rr);
		tmp_converted.fl = (uint8_t)r_fl;
		tmp_converted.fr = (uint8_t)r_fr;
		tmp_converted.rl = (uint8_t)r_rl;
		tmp_converted.rr = (uint8_t)r_rr;

		secondary_tpms_temperature_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_TPMS_TEMPERATURE_BYTE_SIZE;
		return secondary_tpms_temperature_pack(data, &tmp, SECONDARY_TPMS_TEMPERATURE_BYTE_SIZE);
	}
	case 1656:
	{
		secondary_tlm_unix_timestamp_t tmp;
		secondary_tlm_unix_timestamp_converted_t tmp_converted;
		uint64_t r_timestamp;

		sscanf(s, "%" SCNu64 "," ,
			&r_timestamp);
		tmp_converted.timestamp = (uint64_t)r_timestamp;

		secondary_tlm_unix_timestamp_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_TLM_UNIX_TIMESTAMP_BYTE_SIZE;
		return secondary_tlm_unix_timestamp_pack(data, &tmp, SECONDARY_TLM_UNIX_TIMESTAMP_BYTE_SIZE);
	}
	case 1664:
	{
		secondary_tlm_lap_time_t tmp;
		secondary_tlm_lap_time_converted_t tmp_converted;
		uint16_t r_lap_count;
		float r_lap_time;

		sscanf(s, "%" SCNu16 "," 
			"%f,"       ,
			&r_lap_count,
			&r_lap_time);
		tmp_converted.lap_count = (uint16_t)r_lap_count;
		tmp_converted.lap_time = (float)r_lap_time;

		secondary_tlm_lap_time_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_TLM_LAP_TIME_BYTE_SIZE;
		return secondary_tlm_lap_time_pack(data, &tmp, SECONDARY_TLM_LAP_TIME_BYTE_SIZE);
	}
	case 1672:
	{
		secondary_tlm_laps_stats_t tmp;
		secondary_tlm_laps_stats_converted_t tmp_converted;
		uint16_t r_lap_number;
		float r_best_time;
		float r_last_time;

		sscanf(s, "%" SCNu16 "," 
			"%f,"       
			"%f,"       ,
			&r_lap_number,
			&r_best_time,
			&r_last_time);
		tmp_converted.lap_number = (uint16_t)r_lap_number;
		tmp_converted.best_time = (float)r_best_time;
		tmp_converted.last_time = (float)r_last_time;

		secondary_tlm_laps_stats_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_TLM_LAPS_STATS_BYTE_SIZE;
		return secondary_tlm_laps_stats_pack(data, &tmp, SECONDARY_TLM_LAPS_STATS_BYTE_SIZE);
	}
	case 1680:
	{
		secondary_tlm_network_interface_t tmp;
		secondary_tlm_network_interface_converted_t tmp_converted;
		uint8_t r_iname_0;
		uint8_t r_iname_1;
		uint8_t r_iname_2;
		uint8_t r_iname_3;
		uint32_t r_ip_address;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu32 "," ,
			&r_iname_0,
			&r_iname_1,
			&r_iname_2,
			&r_iname_3,
			&r_ip_address);
		tmp_converted.iname_0 = (uint8_t)r_iname_0;
		tmp_converted.iname_1 = (uint8_t)r_iname_1;
		tmp_converted.iname_2 = (uint8_t)r_iname_2;
		tmp_converted.iname_3 = (uint8_t)r_iname_3;
		tmp_converted.ip_address = (uint32_t)r_ip_address;

		secondary_tlm_network_interface_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_TLM_NETWORK_INTERFACE_BYTE_SIZE;
		return secondary_tlm_network_interface_pack(data, &tmp, SECONDARY_TLM_NETWORK_INTERFACE_BYTE_SIZE);
	}
	case 1688:
	{
		secondary_ammo_compression_t tmp;
		secondary_ammo_compression_converted_t tmp_converted;
		float r_rl;
		float r_rr;
		float r_fl;
		float r_fr;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_rl,
			&r_rr,
			&r_fl,
			&r_fr);
		tmp_converted.rl = (float)r_rl;
		tmp_converted.rr = (float)r_rr;
		tmp_converted.fl = (float)r_fl;
		tmp_converted.fr = (float)r_fr;

		secondary_ammo_compression_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_AMMO_COMPRESSION_BYTE_SIZE;
		return secondary_ammo_compression_pack(data, &tmp, SECONDARY_AMMO_COMPRESSION_BYTE_SIZE);
	}
	case 1696:
	{
		secondary_acquisinator_calibrations_offsets_t tmp;
		secondary_acquisinator_calibrations_offsets_converted_t tmp_converted;
		uint8_t r_acquisinator_id;
		float r_offset1;
		float r_offset2;

		sscanf(s, "%" SCNu8 ","  
			"%f,"       
			"%f,"       ,
			&r_acquisinator_id,
			&r_offset1,
			&r_offset2);
		tmp_converted.acquisinator_id = (uint8_t)r_acquisinator_id;
		tmp_converted.offset1 = (float)r_offset1;
		tmp_converted.offset2 = (float)r_offset2;

		secondary_acquisinator_calibrations_offsets_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_ACQUISINATOR_CALIBRATIONS_OFFSETS_BYTE_SIZE;
		return secondary_acquisinator_calibrations_offsets_pack(data, &tmp, SECONDARY_ACQUISINATOR_CALIBRATIONS_OFFSETS_BYTE_SIZE);
	}
	case 1704:
	{
		secondary_acquisinator_errors_t tmp;
		secondary_acquisinator_errors_converted_t tmp_converted;
		uint8_t r_acquisinator_id;
		uint8_t r_acquisinator_errors_acquisinatore_led_code_can_not_working;
		uint8_t r_acquisinator_errors_acquisinatore_led_code_spi_error;
		uint8_t r_acquisinator_errors_acquisinatore_led_code_read_write_flash;
		uint8_t r_acquisinator_errors_acquisinatore_led_code_flashed_firmware_with_wrong_id;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  ,
			&r_acquisinator_id,
			&r_acquisinator_errors_acquisinatore_led_code_can_not_working,
			&r_acquisinator_errors_acquisinatore_led_code_spi_error,
			&r_acquisinator_errors_acquisinatore_led_code_read_write_flash,
			&r_acquisinator_errors_acquisinatore_led_code_flashed_firmware_with_wrong_id);
		tmp_converted.acquisinator_id = (uint8_t)r_acquisinator_id;
		tmp_converted.acquisinator_errors_acquisinatore_led_code_can_not_working = (uint8_t)r_acquisinator_errors_acquisinatore_led_code_can_not_working;
		tmp_converted.acquisinator_errors_acquisinatore_led_code_spi_error = (uint8_t)r_acquisinator_errors_acquisinatore_led_code_spi_error;
		tmp_converted.acquisinator_errors_acquisinatore_led_code_read_write_flash = (uint8_t)r_acquisinator_errors_acquisinatore_led_code_read_write_flash;
		tmp_converted.acquisinator_errors_acquisinatore_led_code_flashed_firmware_with_wrong_id = (uint8_t)r_acquisinator_errors_acquisinatore_led_code_flashed_firmware_with_wrong_id;

		secondary_acquisinator_errors_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_ACQUISINATOR_ERRORS_BYTE_SIZE;
		return secondary_acquisinator_errors_pack(data, &tmp, SECONDARY_ACQUISINATOR_ERRORS_BYTE_SIZE);
	}
	case 1712:
	{
		secondary_link_deformation_debug_voltages_t tmp;
		secondary_link_deformation_debug_voltages_converted_t tmp_converted;
		uint8_t r_wheel_id;
		uint8_t r_rod_id;
		float r_raw_voltage;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  
			"%f,"       ,
			&r_wheel_id,
			&r_rod_id,
			&r_raw_voltage);
		tmp_converted.wheel_id = (secondary_link_deformation_debug_voltages_wheel_id)r_wheel_id;
		tmp_converted.rod_id = (secondary_link_deformation_debug_voltages_rod_id)r_rod_id;
		tmp_converted.raw_voltage = (float)r_raw_voltage;

		secondary_link_deformation_debug_voltages_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_LINK_DEFORMATION_DEBUG_VOLTAGES_BYTE_SIZE;
		return secondary_link_deformation_debug_voltages_pack(data, &tmp, SECONDARY_LINK_DEFORMATION_DEBUG_VOLTAGES_BYTE_SIZE);
	}
	case 1720:
	{
		secondary_link_deformation_fl_wheel_t tmp;
		secondary_link_deformation_fl_wheel_converted_t tmp_converted;
		uint8_t r_rod_id;
		float r_deformation;

		sscanf(s, "%" SCNu8 ","  
			"%f,"       ,
			&r_rod_id,
			&r_deformation);
		tmp_converted.rod_id = (secondary_link_deformation_fl_wheel_rod_id)r_rod_id;
		tmp_converted.deformation = (float)r_deformation;

		secondary_link_deformation_fl_wheel_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_LINK_DEFORMATION_FL_WHEEL_BYTE_SIZE;
		return secondary_link_deformation_fl_wheel_pack(data, &tmp, SECONDARY_LINK_DEFORMATION_FL_WHEEL_BYTE_SIZE);
	}
	case 1728:
	{
		secondary_link_deformation_fr_wheel_t tmp;
		secondary_link_deformation_fr_wheel_converted_t tmp_converted;
		uint8_t r_rod_id;
		float r_deformation;

		sscanf(s, "%" SCNu8 ","  
			"%f,"       ,
			&r_rod_id,
			&r_deformation);
		tmp_converted.rod_id = (secondary_link_deformation_fr_wheel_rod_id)r_rod_id;
		tmp_converted.deformation = (float)r_deformation;

		secondary_link_deformation_fr_wheel_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_LINK_DEFORMATION_FR_WHEEL_BYTE_SIZE;
		return secondary_link_deformation_fr_wheel_pack(data, &tmp, SECONDARY_LINK_DEFORMATION_FR_WHEEL_BYTE_SIZE);
	}
	case 1736:
	{
		secondary_link_deformation_rl_wheel_t tmp;
		secondary_link_deformation_rl_wheel_converted_t tmp_converted;
		uint8_t r_rod_id;
		float r_deformation;

		sscanf(s, "%" SCNu8 ","  
			"%f,"       ,
			&r_rod_id,
			&r_deformation);
		tmp_converted.rod_id = (secondary_link_deformation_rl_wheel_rod_id)r_rod_id;
		tmp_converted.deformation = (float)r_deformation;

		secondary_link_deformation_rl_wheel_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_LINK_DEFORMATION_RL_WHEEL_BYTE_SIZE;
		return secondary_link_deformation_rl_wheel_pack(data, &tmp, SECONDARY_LINK_DEFORMATION_RL_WHEEL_BYTE_SIZE);
	}
	case 1744:
	{
		secondary_link_deformation_rr_wheel_t tmp;
		secondary_link_deformation_rr_wheel_converted_t tmp_converted;
		uint8_t r_rod_id;
		float r_deformation;

		sscanf(s, "%" SCNu8 ","  
			"%f,"       ,
			&r_rod_id,
			&r_deformation);
		tmp_converted.rod_id = (secondary_link_deformation_rr_wheel_rod_id)r_rod_id;
		tmp_converted.deformation = (float)r_deformation;

		secondary_link_deformation_rr_wheel_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_LINK_DEFORMATION_RR_WHEEL_BYTE_SIZE;
		return secondary_link_deformation_rr_wheel_pack(data, &tmp, SECONDARY_LINK_DEFORMATION_RR_WHEEL_BYTE_SIZE);
	}
	case 1752:
	{
		secondary_debug_signal_5_t tmp;
		secondary_debug_signal_5_converted_t tmp_converted;
		uint8_t r_device_id;
		float r_field_1;
		float r_field_2;
		float r_field_3;

		sscanf(s, "%" SCNu8 ","  
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_device_id,
			&r_field_1,
			&r_field_2,
			&r_field_3);
		tmp_converted.device_id = (secondary_debug_signal_5_device_id)r_device_id;
		tmp_converted.field_1 = (float)r_field_1;
		tmp_converted.field_2 = (float)r_field_2;
		tmp_converted.field_3 = (float)r_field_3;

		secondary_debug_signal_5_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_DEBUG_SIGNAL_5_BYTE_SIZE;
		return secondary_debug_signal_5_pack(data, &tmp, SECONDARY_DEBUG_SIGNAL_5_BYTE_SIZE);
	}
	case 1760:
	{
		secondary_debug_signal_6_t tmp;
		secondary_debug_signal_6_converted_t tmp_converted;
		uint8_t r_device_id;
		float r_field_1;
		float r_field_2;
		float r_field_3;

		sscanf(s, "%" SCNu8 ","  
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_device_id,
			&r_field_1,
			&r_field_2,
			&r_field_3);
		tmp_converted.device_id = (secondary_debug_signal_6_device_id)r_device_id;
		tmp_converted.field_1 = (float)r_field_1;
		tmp_converted.field_2 = (float)r_field_2;
		tmp_converted.field_3 = (float)r_field_3;

		secondary_debug_signal_6_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_DEBUG_SIGNAL_6_BYTE_SIZE;
		return secondary_debug_signal_6_pack(data, &tmp, SECONDARY_DEBUG_SIGNAL_6_BYTE_SIZE);
	}
	case 1768:
	{
		secondary_debug_signal_7_t tmp;
		secondary_debug_signal_7_converted_t tmp_converted;
		uint8_t r_device_id;
		float r_field_1;
		float r_field_2;
		float r_field_3;

		sscanf(s, "%" SCNu8 ","  
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_device_id,
			&r_field_1,
			&r_field_2,
			&r_field_3);
		tmp_converted.device_id = (secondary_debug_signal_7_device_id)r_device_id;
		tmp_converted.field_1 = (float)r_field_1;
		tmp_converted.field_2 = (float)r_field_2;
		tmp_converted.field_3 = (float)r_field_3;

		secondary_debug_signal_7_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_DEBUG_SIGNAL_7_BYTE_SIZE;
		return secondary_debug_signal_7_pack(data, &tmp, SECONDARY_DEBUG_SIGNAL_7_BYTE_SIZE);
	}
	case 1776:
	{
		secondary_debug_signal_8_t tmp;
		secondary_debug_signal_8_converted_t tmp_converted;
		uint8_t r_device_id;
		float r_field_1;
		float r_field_2;
		float r_field_3;

		sscanf(s, "%" SCNu8 ","  
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_device_id,
			&r_field_1,
			&r_field_2,
			&r_field_3);
		tmp_converted.device_id = (secondary_debug_signal_8_device_id)r_device_id;
		tmp_converted.field_1 = (float)r_field_1;
		tmp_converted.field_2 = (float)r_field_2;
		tmp_converted.field_3 = (float)r_field_3;

		secondary_debug_signal_8_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_DEBUG_SIGNAL_8_BYTE_SIZE;
		return secondary_debug_signal_8_pack(data, &tmp, SECONDARY_DEBUG_SIGNAL_8_BYTE_SIZE);
	}
	case 1784:
	{
		secondary_cooling_temp_pumps_t tmp;
		secondary_cooling_temp_pumps_converted_t tmp_converted;
		float r_input;
		float r_output;

		sscanf(s, "%f,"       
			"%f,"       ,
			&r_input,
			&r_output);
		tmp_converted.input = (float)r_input;
		tmp_converted.output = (float)r_output;

		secondary_cooling_temp_pumps_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_COOLING_TEMP_PUMPS_BYTE_SIZE;
		return secondary_cooling_temp_pumps_pack(data, &tmp, SECONDARY_COOLING_TEMP_PUMPS_BYTE_SIZE);
	}
	case 1792:
	{
		secondary_cooling_temp_radiators_t tmp;
		secondary_cooling_temp_radiators_converted_t tmp_converted;
		float r_air_temp;

		sscanf(s, "%f,"       ,
			&r_air_temp);
		tmp_converted.air_temp = (float)r_air_temp;

		secondary_cooling_temp_radiators_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = SECONDARY_COOLING_TEMP_RADIATORS_BYTE_SIZE;
		return secondary_cooling_temp_radiators_pack(data, &tmp, SECONDARY_COOLING_TEMP_RADIATORS_BYTE_SIZE);
	}

    }
    return 0;
}
int secondary_n_fields_from_id(int id)
{
	switch(id)
    {
		case 0: return 1;
		case 1: return 0;
		case 2: return 0;
		case 3: return 0;
		case 4: return 0;
		case 5: return 0;
		case 6: return 0;
		case 7: return 0;
		case 8: return 0;
		case 9: return 0;
		case 10: return 0;
		case 11: return 0;
		case 12: return 0;
		case 13: return 0;
		case 14: return 0;
		case 15: return 0;
		case 16: return 0;
		case 17: return 0;
		case 18: return 0;
		case 19: return 0;
		case 20: return 0;
		case 21: return 0;
		case 22: return 0;
		case 23: return 0;
		case 24: return 0;
		case 25: return 0;
		case 26: return 0;
		case 27: return 0;
		case 28: return 0;
		case 29: return 0;
		case 30: return 0;
		case 31: return 0;
		case 32: return 0;
		case 33: return 0;
		case 34: return 0;
		case 35: return 0;
		case 36: return 0;
		case 37: return 0;
		case 38: return 0;
		case 39: return 0;
		case 40: return 0;
		case 41: return 0;
		case 42: return 0;
		case 43: return 0;
		case 44: return 0;
		case 45: return 0;
		case 46: return 0;
		case 47: return 0;
		case 48: return 0;
		case 49: return 0;
		case 50: return 0;
		case 51: return 0;
		case 52: return 0;
		case 53: return 0;
		case 54: return 0;
		case 55: return 0;
		case 56: return 0;
		case 57: return 0;
		case 58: return 0;
		case 59: return 0;
		case 60: return 0;
		case 61: return 0;
		case 62: return 0;
		case 63: return 0;
		case 64: return 0;
		case 700: return 2;
		case 1260: return 3;
		case 1261: return 4;
		case 1456: return 4;
		case 1457: return 4;
		case 1458: return 4;
		case 1459: return 4;
		case 1464: return 4;
		case 1465: return 4;
		case 1466: return 4;
		case 1467: return 4;
		case 1468: return 4;
		case 1469: return 4;
		case 1470: return 4;
		case 1471: return 4;
		case 1200: return 4;
		case 1201: return 4;
		case 1202: return 4;
		case 1203: return 4;
		case 1536: return 3;
		case 1544: return 2;
		case 1552: return 2;
		case 1560: return 2;
		case 1568: return 2;
		case 1576: return 3;
		case 1584: return 3;
		case 1592: return 3;
		case 1600: return 3;
		case 1608: return 1;
		case 1616: return 2;
		case 1624: return 1;
		case 1632: return 1;
		case 1640: return 4;
		case 1648: return 4;
		case 1656: return 1;
		case 1664: return 2;
		case 1672: return 3;
		case 1680: return 5;
		case 1688: return 4;
		case 1696: return 3;
		case 1704: return 5;
		case 1712: return 3;
		case 1720: return 2;
		case 1728: return 2;
		case 1736: return 2;
		case 1744: return 2;
		case 72: return 0;
		case 80: return 0;
		case 1752: return 4;
		case 1760: return 4;
		case 1768: return 4;
		case 1776: return 4;
		case 1784: return 2;
		case 1792: return 1;
    }
    return 0;
}
int secondary_fields_types_from_id(int id, int* fields_types, int fields_types_size)
{
    switch(id)
    {
	case 0:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_secondary_uint8_t;
		return 1;
	case 700:
		if(fields_types_size < 2) return 0;
		fields_types[0] = e_secondary_uint8_t;
		fields_types[1] = e_secondary_uint32_t;
		return 2;
	case 1260:
		if(fields_types_size < 3) return 0;
		fields_types[0] = e_secondary_float;
		fields_types[1] = e_secondary_float;
		fields_types[2] = e_secondary_float;
		return 3;
	case 1261:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_secondary_float;
		fields_types[1] = e_secondary_float;
		fields_types[2] = e_secondary_float;
		fields_types[3] = e_secondary_int16_t;
		return 4;
	case 1456:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_secondary_float;
		fields_types[1] = e_secondary_float;
		fields_types[2] = e_secondary_float;
		fields_types[3] = e_secondary_float;
		return 4;
	case 1457:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_secondary_float;
		fields_types[1] = e_secondary_float;
		fields_types[2] = e_secondary_float;
		fields_types[3] = e_secondary_float;
		return 4;
	case 1458:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_secondary_float;
		fields_types[1] = e_secondary_float;
		fields_types[2] = e_secondary_float;
		fields_types[3] = e_secondary_float;
		return 4;
	case 1459:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_secondary_float;
		fields_types[1] = e_secondary_float;
		fields_types[2] = e_secondary_float;
		fields_types[3] = e_secondary_float;
		return 4;
	case 1464:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_secondary_float;
		fields_types[1] = e_secondary_float;
		fields_types[2] = e_secondary_float;
		fields_types[3] = e_secondary_float;
		return 4;
	case 1465:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_secondary_float;
		fields_types[1] = e_secondary_float;
		fields_types[2] = e_secondary_float;
		fields_types[3] = e_secondary_float;
		return 4;
	case 1466:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_secondary_float;
		fields_types[1] = e_secondary_float;
		fields_types[2] = e_secondary_float;
		fields_types[3] = e_secondary_float;
		return 4;
	case 1467:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_secondary_float;
		fields_types[1] = e_secondary_float;
		fields_types[2] = e_secondary_float;
		fields_types[3] = e_secondary_float;
		return 4;
	case 1468:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_secondary_float;
		fields_types[1] = e_secondary_float;
		fields_types[2] = e_secondary_float;
		fields_types[3] = e_secondary_float;
		return 4;
	case 1469:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_secondary_float;
		fields_types[1] = e_secondary_float;
		fields_types[2] = e_secondary_float;
		fields_types[3] = e_secondary_float;
		return 4;
	case 1470:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_secondary_float;
		fields_types[1] = e_secondary_float;
		fields_types[2] = e_secondary_float;
		fields_types[3] = e_secondary_float;
		return 4;
	case 1471:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_secondary_float;
		fields_types[1] = e_secondary_float;
		fields_types[2] = e_secondary_float;
		fields_types[3] = e_secondary_float;
		return 4;
	case 1200:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_secondary_float;
		fields_types[1] = e_secondary_float;
		fields_types[2] = e_secondary_float;
		fields_types[3] = e_secondary_float;
		return 4;
	case 1201:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_secondary_float;
		fields_types[1] = e_secondary_float;
		fields_types[2] = e_secondary_float;
		fields_types[3] = e_secondary_float;
		return 4;
	case 1202:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_secondary_float;
		fields_types[1] = e_secondary_float;
		fields_types[2] = e_secondary_float;
		fields_types[3] = e_secondary_float;
		return 4;
	case 1203:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_secondary_float;
		fields_types[1] = e_secondary_float;
		fields_types[2] = e_secondary_float;
		fields_types[3] = e_secondary_float;
		return 4;
	case 1536:
		if(fields_types_size < 3) return 0;
		fields_types[0] = e_secondary_float;
		fields_types[1] = e_secondary_float;
		fields_types[2] = e_secondary_float;
		return 3;
	case 1544:
		if(fields_types_size < 2) return 0;
		fields_types[0] = e_secondary_float;
		fields_types[1] = e_secondary_float;
		return 2;
	case 1552:
		if(fields_types_size < 2) return 0;
		fields_types[0] = e_secondary_float;
		fields_types[1] = e_secondary_float;
		return 2;
	case 1560:
		if(fields_types_size < 2) return 0;
		fields_types[0] = e_secondary_float;
		fields_types[1] = e_secondary_float;
		return 2;
	case 1568:
		if(fields_types_size < 2) return 0;
		fields_types[0] = e_secondary_float;
		fields_types[1] = e_secondary_float;
		return 2;
	case 1576:
		if(fields_types_size < 3) return 0;
		fields_types[0] = e_secondary_float;
		fields_types[1] = e_secondary_float;
		fields_types[2] = e_secondary_float;
		return 3;
	case 1584:
		if(fields_types_size < 3) return 0;
		fields_types[0] = e_secondary_float;
		fields_types[1] = e_secondary_float;
		fields_types[2] = e_secondary_float;
		return 3;
	case 1592:
		if(fields_types_size < 3) return 0;
		fields_types[0] = e_secondary_float;
		fields_types[1] = e_secondary_float;
		fields_types[2] = e_secondary_float;
		return 3;
	case 1600:
		if(fields_types_size < 3) return 0;
		fields_types[0] = e_secondary_float;
		fields_types[1] = e_secondary_float;
		fields_types[2] = e_secondary_float;
		return 3;
	case 1608:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_secondary_float;
		return 1;
	case 1616:
		if(fields_types_size < 2) return 0;
		fields_types[0] = e_secondary_float;
		fields_types[1] = e_secondary_float;
		return 2;
	case 1624:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_secondary_float;
		return 1;
	case 1632:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_secondary_float;
		return 1;
	case 1640:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_secondary_uint8_t;
		fields_types[1] = e_secondary_uint8_t;
		fields_types[2] = e_secondary_uint8_t;
		fields_types[3] = e_secondary_uint8_t;
		return 4;
	case 1648:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_secondary_uint8_t;
		fields_types[1] = e_secondary_uint8_t;
		fields_types[2] = e_secondary_uint8_t;
		fields_types[3] = e_secondary_uint8_t;
		return 4;
	case 1656:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_secondary_uint64_t;
		return 1;
	case 1664:
		if(fields_types_size < 2) return 0;
		fields_types[0] = e_secondary_uint16_t;
		fields_types[1] = e_secondary_float;
		return 2;
	case 1672:
		if(fields_types_size < 3) return 0;
		fields_types[0] = e_secondary_uint16_t;
		fields_types[1] = e_secondary_float;
		fields_types[2] = e_secondary_float;
		return 3;
	case 1680:
		if(fields_types_size < 5) return 0;
		fields_types[0] = e_secondary_uint8_t;
		fields_types[1] = e_secondary_uint8_t;
		fields_types[2] = e_secondary_uint8_t;
		fields_types[3] = e_secondary_uint8_t;
		fields_types[4] = e_secondary_uint32_t;
		return 5;
	case 1688:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_secondary_float;
		fields_types[1] = e_secondary_float;
		fields_types[2] = e_secondary_float;
		fields_types[3] = e_secondary_float;
		return 4;
	case 1696:
		if(fields_types_size < 3) return 0;
		fields_types[0] = e_secondary_uint8_t;
		fields_types[1] = e_secondary_float;
		fields_types[2] = e_secondary_float;
		return 3;
	case 1704:
		if(fields_types_size < 5) return 0;
		fields_types[0] = e_secondary_uint8_t;
		fields_types[1] = e_secondary_uint8_t;
		fields_types[2] = e_secondary_uint8_t;
		fields_types[3] = e_secondary_uint8_t;
		fields_types[4] = e_secondary_uint8_t;
		return 5;
	case 1712:
		if(fields_types_size < 3) return 0;
		fields_types[0] = e_secondary_link_deformation_debug_voltages_wheel_id;
		fields_types[1] = e_secondary_link_deformation_debug_voltages_rod_id;
		fields_types[2] = e_secondary_float;
		return 3;
	case 1720:
		if(fields_types_size < 2) return 0;
		fields_types[0] = e_secondary_link_deformation_fl_wheel_rod_id;
		fields_types[1] = e_secondary_float;
		return 2;
	case 1728:
		if(fields_types_size < 2) return 0;
		fields_types[0] = e_secondary_link_deformation_fr_wheel_rod_id;
		fields_types[1] = e_secondary_float;
		return 2;
	case 1736:
		if(fields_types_size < 2) return 0;
		fields_types[0] = e_secondary_link_deformation_rl_wheel_rod_id;
		fields_types[1] = e_secondary_float;
		return 2;
	case 1744:
		if(fields_types_size < 2) return 0;
		fields_types[0] = e_secondary_link_deformation_rr_wheel_rod_id;
		fields_types[1] = e_secondary_float;
		return 2;
	case 1752:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_secondary_debug_signal_5_device_id;
		fields_types[1] = e_secondary_float;
		fields_types[2] = e_secondary_float;
		fields_types[3] = e_secondary_float;
		return 4;
	case 1760:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_secondary_debug_signal_6_device_id;
		fields_types[1] = e_secondary_float;
		fields_types[2] = e_secondary_float;
		fields_types[3] = e_secondary_float;
		return 4;
	case 1768:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_secondary_debug_signal_7_device_id;
		fields_types[1] = e_secondary_float;
		fields_types[2] = e_secondary_float;
		fields_types[3] = e_secondary_float;
		return 4;
	case 1776:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_secondary_debug_signal_8_device_id;
		fields_types[1] = e_secondary_float;
		fields_types[2] = e_secondary_float;
		fields_types[3] = e_secondary_float;
		return 4;
	case 1784:
		if(fields_types_size < 2) return 0;
		fields_types[0] = e_secondary_float;
		fields_types[1] = e_secondary_float;
		return 2;
	case 1792:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_secondary_float;
		return 1;

    }
    return 0;
}
int secondary_enum_fields_from_name(const char *msg_name, const char *sgn_name, char **v)
{
	if(!strcmp(msg_name, "LINK_DEFORMATION_DEBUG_VOLTAGES"))
	{
		if(!strcmp(sgn_name, "wheel_id"))
		{
			sprintf(v[0], "fl");
			sprintf(v[1], "fr");
			sprintf(v[2], "rl");
			sprintf(v[3], "rr");
			return 4;
		}
		if(!strcmp(sgn_name, "rod_id"))
		{
			sprintf(v[0], "F1011");
			sprintf(v[1], "F36");
			sprintf(v[2], "F46");
			sprintf(v[3], "F27");
			sprintf(v[4], "F17");
			sprintf(v[5], "F58");
			return 6;
		}
	}
	if(!strcmp(msg_name, "LINK_DEFORMATION_FL_WHEEL"))
	{
		if(!strcmp(sgn_name, "rod_id"))
		{
			sprintf(v[0], "F1011");
			sprintf(v[1], "F36");
			sprintf(v[2], "F46");
			sprintf(v[3], "F27");
			sprintf(v[4], "F17");
			sprintf(v[5], "F58");
			return 6;
		}
	}
	if(!strcmp(msg_name, "LINK_DEFORMATION_FR_WHEEL"))
	{
		if(!strcmp(sgn_name, "rod_id"))
		{
			sprintf(v[0], "F1011");
			sprintf(v[1], "F36");
			sprintf(v[2], "F46");
			sprintf(v[3], "F27");
			sprintf(v[4], "F17");
			sprintf(v[5], "F58");
			return 6;
		}
	}
	if(!strcmp(msg_name, "LINK_DEFORMATION_RL_WHEEL"))
	{
		if(!strcmp(sgn_name, "rod_id"))
		{
			sprintf(v[0], "F1011");
			sprintf(v[1], "F36");
			sprintf(v[2], "F46");
			sprintf(v[3], "F27");
			sprintf(v[4], "F17");
			sprintf(v[5], "F58");
			return 6;
		}
	}
	if(!strcmp(msg_name, "LINK_DEFORMATION_RR_WHEEL"))
	{
		if(!strcmp(sgn_name, "rod_id"))
		{
			sprintf(v[0], "F1011");
			sprintf(v[1], "F36");
			sprintf(v[2], "F46");
			sprintf(v[3], "F27");
			sprintf(v[4], "F17");
			sprintf(v[5], "F58");
			return 6;
		}
	}
	if(!strcmp(msg_name, "DEBUG_SIGNAL_5"))
	{
		if(!strcmp(sgn_name, "device_id"))
		{
			sprintf(v[0], "hv_mainboard");
			sprintf(v[1], "hv_cellboard");
			sprintf(v[2], "lv");
			sprintf(v[3], "ecu");
			sprintf(v[4], "tlm");
			sprintf(v[5], "traction_control");
			sprintf(v[6], "steeering_wheel");
			sprintf(v[7], "handcart");
			sprintf(v[8], "acquisinator");
			return 9;
		}
	}
	if(!strcmp(msg_name, "DEBUG_SIGNAL_6"))
	{
		if(!strcmp(sgn_name, "device_id"))
		{
			sprintf(v[0], "hv_mainboard");
			sprintf(v[1], "hv_cellboard");
			sprintf(v[2], "lv");
			sprintf(v[3], "ecu");
			sprintf(v[4], "tlm");
			sprintf(v[5], "traction_control");
			sprintf(v[6], "steeering_wheel");
			sprintf(v[7], "handcart");
			sprintf(v[8], "acquisinator");
			return 9;
		}
	}
	if(!strcmp(msg_name, "DEBUG_SIGNAL_7"))
	{
		if(!strcmp(sgn_name, "device_id"))
		{
			sprintf(v[0], "hv_mainboard");
			sprintf(v[1], "hv_cellboard");
			sprintf(v[2], "lv");
			sprintf(v[3], "ecu");
			sprintf(v[4], "tlm");
			sprintf(v[5], "traction_control");
			sprintf(v[6], "steeering_wheel");
			sprintf(v[7], "handcart");
			sprintf(v[8], "acquisinator");
			return 9;
		}
	}
	if(!strcmp(msg_name, "DEBUG_SIGNAL_8"))
	{
		if(!strcmp(sgn_name, "device_id"))
		{
			sprintf(v[0], "hv_mainboard");
			sprintf(v[1], "hv_cellboard");
			sprintf(v[2], "lv");
			sprintf(v[3], "ecu");
			sprintf(v[4], "tlm");
			sprintf(v[5], "traction_control");
			sprintf(v[6], "steeering_wheel");
			sprintf(v[7], "handcart");
			sprintf(v[8], "acquisinator");
			return 9;
		}
	}
	return 0;
}
