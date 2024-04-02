#include "primary_utils_c.h"


int primary_fields_string_from_id(int id, char **v, size_t fields_size, size_t string_size)
{
	switch(id)
    {
	case 1818:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, NLG5_DIAG_TX_LAD_D_PARAMRP);

		return 0;
	case 1816:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, NLG5_DIAG_RX_LAD_D_PARAMRQ);

		return 0;
	case 1556:
		if(37 > fields_size) return 1;
		snprintf(v[0], string_size, NLG5_ERR_NLG5_E_OOV);
		snprintf(v[1], string_size, NLG5_ERR_NLG5_E_MOV_II);
		snprintf(v[2], string_size, NLG5_ERR_NLG5_E_MOV_I);
		snprintf(v[3], string_size, NLG5_ERR_NLG5_E_SC);
		snprintf(v[4], string_size, NLG5_ERR_NLG5_E_P_OM);
		snprintf(v[5], string_size, NLG5_ERR_NLG5_E_P_MV);
		snprintf(v[6], string_size, NLG5_ERR_NLG5_E_OF);
		snprintf(v[7], string_size, NLG5_ERR_NLG5_E_MF);
		snprintf(v[8], string_size, NLG5_ERR_NLG5_E_B_P);
		snprintf(v[9], string_size, NLG5_ERR_NLG5_E_T_C);
		snprintf(v[10], string_size, NLG5_ERR_NLG5_E_T_POW);
		snprintf(v[11], string_size, NLG5_ERR_NLG5_E_T_DIO);
		snprintf(v[12], string_size, NLG5_ERR_NLG5_E_T_TR);
		snprintf(v[13], string_size, NLG5_ERR_NLG5_E_T_EXT1);
		snprintf(v[14], string_size, NLG5_ERR_NLG5_E_T_EXT2);
		snprintf(v[15], string_size, NLG5_ERR_NLG5_E_T_EXT3);
		snprintf(v[16], string_size, NLG5_ERR_NLG5_E_F_CRC);
		snprintf(v[17], string_size, NLG5_ERR_NLG5_E_NV_CRC);
		snprintf(v[18], string_size, NLG5_ERR_NLG5_E_ES_CRC);
		snprintf(v[19], string_size, NLG5_ERR_NLG5_E_EP_CRC);
		snprintf(v[20], string_size, NLG5_ERR_NLG5_E_WDT);
		snprintf(v[21], string_size, NLG5_ERR_NLG5_E_INIT);
		snprintf(v[22], string_size, NLG5_ERR_NLG5_E_C_TO);
		snprintf(v[23], string_size, NLG5_ERR_NLG5_E_C_OFF);
		snprintf(v[24], string_size, NLG5_ERR_NLG5_E_C_TX);
		snprintf(v[25], string_size, NLG5_ERR_NLG5_E_C_RX);
		snprintf(v[26], string_size, NLG5_ERR_NLG5_E_SDT_BT);
		snprintf(v[27], string_size, NLG5_ERR_NLG5_E_SDT_BV);
		snprintf(v[28], string_size, NLG5_ERR_NLG5_E_SDT_AH);
		snprintf(v[29], string_size, NLG5_ERR_NLG5_E_SDT_CT);
		snprintf(v[30], string_size, NLG5_ERR_NLG5_W_PL_MV);
		snprintf(v[31], string_size, NLG5_ERR_NLG5_W_PL_BV);
		snprintf(v[32], string_size, NLG5_ERR_NLG5_W_PL_IT);
		snprintf(v[33], string_size, NLG5_ERR_NLG5_W_C_VOR);
		snprintf(v[34], string_size, NLG5_ERR_NLG5_W_CM_NA);
		snprintf(v[35], string_size, NLG5_ERR_NLG5_W_OD);
		snprintf(v[36], string_size, NLG5_ERR_NLG5_W_SC_M);

		return 0;
	case 1555:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, NLG5_TEMP_NLG5_P_TMP);
		snprintf(v[1], string_size, NLG5_TEMP_NLG5_TMP_EXT1);
		snprintf(v[2], string_size, NLG5_TEMP_NLG5_TEMP_EXT2);
		snprintf(v[3], string_size, NLG5_TEMP_NLG5_TMP_EXT3);

		return 0;
	case 1554:
		if(5 > fields_size) return 1;
		snprintf(v[0], string_size, NLG5_ACT_II_NLG5_S_MC_M_CP);
		snprintf(v[1], string_size, NLG5_ACT_II_NLG5_S_MC_M_PI);
		snprintf(v[2], string_size, NLG5_ACT_II_NLG5_ABV);
		snprintf(v[3], string_size, NLG5_ACT_II_NLG5_AHC_EXT);
		snprintf(v[4], string_size, NLG5_ACT_II_NLG5_OC_BO);

		return 0;
	case 1553:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, NLG5_ACT_I_NLG5_MC_ACT);
		snprintf(v[1], string_size, NLG5_ACT_I_NLG5_MV_ACT);
		snprintf(v[2], string_size, NLG5_ACT_I_NLG5_OV_ACT);
		snprintf(v[3], string_size, NLG5_ACT_I_NLG5_OC_ACT);

		return 0;
	case 1552:
		if(25 > fields_size) return 1;
		snprintf(v[0], string_size, NLG5_ST_NLG5_S_HE);
		snprintf(v[1], string_size, NLG5_ST_NLG5_S_ERR);
		snprintf(v[2], string_size, NLG5_ST_NLG5_S_WAR);
		snprintf(v[3], string_size, NLG5_ST_NLG5_S_FAN);
		snprintf(v[4], string_size, NLG5_ST_NLG5_S_EUM);
		snprintf(v[5], string_size, NLG5_ST_NLG5_S_UM_I);
		snprintf(v[6], string_size, NLG5_ST_NLG5_S_UM_II);
		snprintf(v[7], string_size, NLG5_ST_NLG5_S_CP_DT);
		snprintf(v[8], string_size, NLG5_ST_NLG5_S_BPD_I);
		snprintf(v[9], string_size, NLG5_ST_NLG5_S_BPD_II);
		snprintf(v[10], string_size, NLG5_ST_NLG5_S_L_OV);
		snprintf(v[11], string_size, NLG5_ST_NLG5_S_L_OC);
		snprintf(v[12], string_size, NLG5_ST_NLG5_S_L_MC);
		snprintf(v[13], string_size, NLG5_ST_NLG5_S_L_PI);
		snprintf(v[14], string_size, NLG5_ST_NLG5_S_L_CP);
		snprintf(v[15], string_size, NLG5_ST_NLG5_S_L_PMAX);
		snprintf(v[16], string_size, NLG5_ST_NLG5_S_L_MC_MAX);
		snprintf(v[17], string_size, NLG5_ST_NLG5_S_L_OC_MAX);
		snprintf(v[18], string_size, NLG5_ST_NLG5_S_L_MO_MAX);
		snprintf(v[19], string_size, NLG5_ST_NLG5_S_L_T_CPRIM);
		snprintf(v[20], string_size, NLG5_ST_NLG5_S_L_T_POW);
		snprintf(v[21], string_size, NLG5_ST_NLG5_S_L_T_DIO);
		snprintf(v[22], string_size, NLG5_ST_NLG5_S_L_T_TR);
		snprintf(v[23], string_size, NLG5_ST_NLG5_S_L_T_BATT);
		snprintf(v[24], string_size, NLG5_ST_NLG5_S_AAC);

		return 0;
	case 1560:
		if(7 > fields_size) return 1;
		snprintf(v[0], string_size, NLG5_CTL_NLG5_C_C_EN);
		snprintf(v[1], string_size, NLG5_CTL_NLG5_C_C_EL);
		snprintf(v[2], string_size, NLG5_CTL_NLG5_C_CP_V);
		snprintf(v[3], string_size, NLG5_CTL_NLG5_C_MR);
		snprintf(v[4], string_size, NLG5_CTL_NLG5_MC_MAX);
		snprintf(v[5], string_size, NLG5_CTL_NLG5_OV_COM);
		snprintf(v[6], string_size, NLG5_CTL_NLG5_OC_COM);

		return 0;
	case 700:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, STEERING_WHEEL_VERSION_COMPONENT_BUILD_TIME);
		snprintf(v[1], string_size, STEERING_WHEEL_VERSION_CANLIB_BUILD_TIME);

		return 0;
	case 701:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, ECU_VERSION_COMPONENT_BUILD_TIME);
		snprintf(v[1], string_size, ECU_VERSION_CANLIB_BUILD_TIME);

		return 0;
	case 703:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, LV_VERSION_COMPONENT_BUILD_TIME);
		snprintf(v[1], string_size, LV_VERSION_CANLIB_BUILD_TIME);

		return 0;
	case 704:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, TLM_VERSION_COMPONENT_BUILD_TIME);
		snprintf(v[1], string_size, TLM_VERSION_CANLIB_BUILD_TIME);

		return 0;
	case 702:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, HV_MAINBOARD_VERSION_COMPONENT_BUILD_TIME);
		snprintf(v[1], string_size, HV_MAINBOARD_VERSION_CANLIB_BUILD_TIME);

		return 0;
	case 705:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, HV_CELLBOARD_VERSION_CELLBOARD_ID);
		snprintf(v[1], string_size, HV_CELLBOARD_VERSION_COMPONENT_VERSION);
		snprintf(v[2], string_size, HV_CELLBOARD_VERSION_CANLIB_BUILD_TIME);

		return 0;
	case 24:
		if(16 > fields_size) return 1;
		snprintf(v[0], string_size, HV_ERRORS_ERRORS_CELL_LOW_VOLTAGE);
		snprintf(v[1], string_size, HV_ERRORS_ERRORS_CELL_UNDER_VOLTAGE);
		snprintf(v[2], string_size, HV_ERRORS_ERRORS_CELL_OVER_VOLTAGE);
		snprintf(v[3], string_size, HV_ERRORS_ERRORS_CELL_HIGH_TEMPERATURE);
		snprintf(v[4], string_size, HV_ERRORS_ERRORS_CELL_OVER_TEMPERATURE);
		snprintf(v[5], string_size, HV_ERRORS_ERRORS_OVER_CURRENT);
		snprintf(v[6], string_size, HV_ERRORS_ERRORS_CAN);
		snprintf(v[7], string_size, HV_ERRORS_ERRORS_INT_VOLTAGE_MISMATCH);
		snprintf(v[8], string_size, HV_ERRORS_ERRORS_CELLBOARD_COMM);
		snprintf(v[9], string_size, HV_ERRORS_ERRORS_CELLBOARD_INTERNAL);
		snprintf(v[10], string_size, HV_ERRORS_ERRORS_CONNECTOR_DISCONNECTED);
		snprintf(v[11], string_size, HV_ERRORS_ERRORS_FANS_DISCONNECTED);
		snprintf(v[12], string_size, HV_ERRORS_ERRORS_FEEDBACK);
		snprintf(v[13], string_size, HV_ERRORS_ERRORS_FEEDBACK_CIRCUITRY);
		snprintf(v[14], string_size, HV_ERRORS_ERRORS_EEPROM_COMM);
		snprintf(v[15], string_size, HV_ERRORS_ERRORS_EEPROM_WRITE);

		return 0;
	case 512:
		if(36 > fields_size) return 1;
		snprintf(v[0], string_size, HV_DEBUG_SIGNALS_FEEDBACKS_IMPLAUSIBILITY_DETECTED);
		snprintf(v[1], string_size, HV_DEBUG_SIGNALS_FEEDBACKS_IMD_COCKPIT);
		snprintf(v[2], string_size, HV_DEBUG_SIGNALS_FEEDBACKS_TSAL_GREEN_FAULT_LATCHED);
		snprintf(v[3], string_size, HV_DEBUG_SIGNALS_FEEDBACKS_BMS_COCKPIT);
		snprintf(v[4], string_size, HV_DEBUG_SIGNALS_FEEDBACKS_EXT_LATCHED);
		snprintf(v[5], string_size, HV_DEBUG_SIGNALS_FEEDBACKS_TSAL_GREEN);
		snprintf(v[6], string_size, HV_DEBUG_SIGNALS_FEEDBACKS_TS_OVER_60V_STATUS);
		snprintf(v[7], string_size, HV_DEBUG_SIGNALS_FEEDBACKS_AIRN_STATUS);
		snprintf(v[8], string_size, HV_DEBUG_SIGNALS_FEEDBACKS_AIRP_STATUS);
		snprintf(v[9], string_size, HV_DEBUG_SIGNALS_FEEDBACKS_AIRP_GATE);
		snprintf(v[10], string_size, HV_DEBUG_SIGNALS_FEEDBACKS_AIRN_GATE);
		snprintf(v[11], string_size, HV_DEBUG_SIGNALS_FEEDBACKS_PRECHARGE_STATUS);
		snprintf(v[12], string_size, HV_DEBUG_SIGNALS_FEEDBACKS_TSP_OVER_60V_STATUS);
		snprintf(v[13], string_size, HV_DEBUG_SIGNALS_FEEDBACKS_IMD_FAULT);
		snprintf(v[14], string_size, HV_DEBUG_SIGNALS_FEEDBACKS_CHECK_MUX);
		snprintf(v[15], string_size, HV_DEBUG_SIGNALS_FEEDBACKS_SD_END);
		snprintf(v[16], string_size, HV_DEBUG_SIGNALS_FEEDBACKS_SD_OUT);
		snprintf(v[17], string_size, HV_DEBUG_SIGNALS_FEEDBACKS_SD_IN);
		snprintf(v[18], string_size, HV_DEBUG_SIGNALS_FEEDBACKS_SD_BMS);
		snprintf(v[19], string_size, HV_DEBUG_SIGNALS_FEEDBACKS_SD_IMD);
		snprintf(v[20], string_size, HV_DEBUG_SIGNALS_ERRORS_CELL_LOW_VOLTAGE);
		snprintf(v[21], string_size, HV_DEBUG_SIGNALS_ERRORS_CELL_UNDER_VOLTAGE);
		snprintf(v[22], string_size, HV_DEBUG_SIGNALS_ERRORS_CELL_OVER_VOLTAGE);
		snprintf(v[23], string_size, HV_DEBUG_SIGNALS_ERRORS_CELL_HIGH_TEMPERATURE);
		snprintf(v[24], string_size, HV_DEBUG_SIGNALS_ERRORS_CELL_OVER_TEMPERATURE);
		snprintf(v[25], string_size, HV_DEBUG_SIGNALS_ERRORS_OVER_CURRENT);
		snprintf(v[26], string_size, HV_DEBUG_SIGNALS_ERRORS_CAN);
		snprintf(v[27], string_size, HV_DEBUG_SIGNALS_ERRORS_INT_VOLTAGE_MISMATCH);
		snprintf(v[28], string_size, HV_DEBUG_SIGNALS_ERRORS_CELLBOARD_COMM);
		snprintf(v[29], string_size, HV_DEBUG_SIGNALS_ERRORS_CELLBOARD_INTERNAL);
		snprintf(v[30], string_size, HV_DEBUG_SIGNALS_ERRORS_CONNECTOR_DISCONNECTED);
		snprintf(v[31], string_size, HV_DEBUG_SIGNALS_ERRORS_FANS_DISCONNECTED);
		snprintf(v[32], string_size, HV_DEBUG_SIGNALS_ERRORS_FEEDBACK);
		snprintf(v[33], string_size, HV_DEBUG_SIGNALS_ERRORS_FEEDBACK_CIRCUITRY);
		snprintf(v[34], string_size, HV_DEBUG_SIGNALS_ERRORS_EEPROM_COMM);
		snprintf(v[35], string_size, HV_DEBUG_SIGNALS_ERRORS_EEPROM_WRITE);

		return 0;
	case 1536:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, HV_FANS_STATUS_FANS_OVERRIDE);
		snprintf(v[1], string_size, HV_FANS_STATUS_FANS_SPEED);

		return 0;
	case 1024:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, HV_SET_FANS_STATUS_FANS_OVERRIDE);
		snprintf(v[1], string_size, HV_SET_FANS_STATUS_FANS_SPEED);

		return 0;
	case 520:
		if(20 > fields_size) return 1;
		snprintf(v[0], string_size, HV_FEEDBACK_STATUS_FEEDBACKS_IMPLAUSIBILITY_DETECTED);
		snprintf(v[1], string_size, HV_FEEDBACK_STATUS_FEEDBACKS_IMD_COCKPIT);
		snprintf(v[2], string_size, HV_FEEDBACK_STATUS_FEEDBACKS_TSAL_GREEN_FAULT_LATCHED);
		snprintf(v[3], string_size, HV_FEEDBACK_STATUS_FEEDBACKS_BMS_COCKPIT);
		snprintf(v[4], string_size, HV_FEEDBACK_STATUS_FEEDBACKS_EXT_LATCHED);
		snprintf(v[5], string_size, HV_FEEDBACK_STATUS_FEEDBACKS_TSAL_GREEN);
		snprintf(v[6], string_size, HV_FEEDBACK_STATUS_FEEDBACKS_TS_OVER_60V_STATUS);
		snprintf(v[7], string_size, HV_FEEDBACK_STATUS_FEEDBACKS_AIRN_STATUS);
		snprintf(v[8], string_size, HV_FEEDBACK_STATUS_FEEDBACKS_AIRP_STATUS);
		snprintf(v[9], string_size, HV_FEEDBACK_STATUS_FEEDBACKS_AIRP_GATE);
		snprintf(v[10], string_size, HV_FEEDBACK_STATUS_FEEDBACKS_AIRN_GATE);
		snprintf(v[11], string_size, HV_FEEDBACK_STATUS_FEEDBACKS_PRECHARGE_STATUS);
		snprintf(v[12], string_size, HV_FEEDBACK_STATUS_FEEDBACKS_TSP_OVER_60V_STATUS);
		snprintf(v[13], string_size, HV_FEEDBACK_STATUS_FEEDBACKS_IMD_FAULT);
		snprintf(v[14], string_size, HV_FEEDBACK_STATUS_FEEDBACKS_CHECK_MUX);
		snprintf(v[15], string_size, HV_FEEDBACK_STATUS_FEEDBACKS_SD_END);
		snprintf(v[16], string_size, HV_FEEDBACK_STATUS_FEEDBACKS_SD_OUT);
		snprintf(v[17], string_size, HV_FEEDBACK_STATUS_FEEDBACKS_SD_IN);
		snprintf(v[18], string_size, HV_FEEDBACK_STATUS_FEEDBACKS_SD_BMS);
		snprintf(v[19], string_size, HV_FEEDBACK_STATUS_FEEDBACKS_SD_IMD);

		return 0;
	case 528:
		if(7 > fields_size) return 1;
		snprintf(v[0], string_size, HV_FEEDBACK_TS_VOLTAGE_TS_OVER_60V_STATUS);
		snprintf(v[1], string_size, HV_FEEDBACK_TS_VOLTAGE_AIRN_STATUS);
		snprintf(v[2], string_size, HV_FEEDBACK_TS_VOLTAGE_AIRP_STATUS);
		snprintf(v[3], string_size, HV_FEEDBACK_TS_VOLTAGE_AIRP_GATE);
		snprintf(v[4], string_size, HV_FEEDBACK_TS_VOLTAGE_AIRN_GATE);
		snprintf(v[5], string_size, HV_FEEDBACK_TS_VOLTAGE_PRECHARGE_STATUS);
		snprintf(v[6], string_size, HV_FEEDBACK_TS_VOLTAGE_TSP_OVER_60V_STATUS);

		return 0;
	case 536:
		if(8 > fields_size) return 1;
		snprintf(v[0], string_size, HV_FEEDBACK_MISC_VOLTAGE_IMPLAUSIBILITY_DETECTED);
		snprintf(v[1], string_size, HV_FEEDBACK_MISC_VOLTAGE_IMD_COCKPIT);
		snprintf(v[2], string_size, HV_FEEDBACK_MISC_VOLTAGE_TSAL_GREEN_FAULT_LATCHED);
		snprintf(v[3], string_size, HV_FEEDBACK_MISC_VOLTAGE_BMS_COCKPIT);
		snprintf(v[4], string_size, HV_FEEDBACK_MISC_VOLTAGE_EXT_LATCHED);
		snprintf(v[5], string_size, HV_FEEDBACK_MISC_VOLTAGE_TSAL_GREEN);
		snprintf(v[6], string_size, HV_FEEDBACK_MISC_VOLTAGE_IMD_FAULT);
		snprintf(v[7], string_size, HV_FEEDBACK_MISC_VOLTAGE_CHECK_MUX);

		return 0;
	case 544:
		if(5 > fields_size) return 1;
		snprintf(v[0], string_size, HV_FEEDBACK_SD_VOLTAGE_SD_END);
		snprintf(v[1], string_size, HV_FEEDBACK_SD_VOLTAGE_SD_OUT);
		snprintf(v[2], string_size, HV_FEEDBACK_SD_VOLTAGE_SD_IN);
		snprintf(v[3], string_size, HV_FEEDBACK_SD_VOLTAGE_SD_BMS);
		snprintf(v[4], string_size, HV_FEEDBACK_SD_VOLTAGE_SD_IMD);

		return 0;
	case 552:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, HV_IMD_STATUS_IMD_FAULT);
		snprintf(v[1], string_size, HV_IMD_STATUS_IMD_STATUS);
		snprintf(v[2], string_size, HV_IMD_STATUS_IMD_DETAILS);
		snprintf(v[3], string_size, HV_IMD_STATUS_IMD_DUTY_CYCLE);
		snprintf(v[4], string_size, HV_IMD_STATUS_IMD_FREQ);
		snprintf(v[5], string_size, HV_IMD_STATUS_IMD_PERIOD);

		return 0;
	case 560:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, HV_STATUS_STATUS);

		return 0;
	case 32:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, HV_SET_STATUS_ECU_HV_STATUS_SET);

		return 0;
	case 40:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, HV_SET_STATUS_HANDCART_HV_STATUS_SET);

		return 0;
	case 1544:
		if(29 > fields_size) return 1;
		snprintf(v[0], string_size, HV_BALANCING_STATUS_CELLBOARD_ID);
		snprintf(v[1], string_size, HV_BALANCING_STATUS_BALANCING_STATUS);
		snprintf(v[2], string_size, HV_BALANCING_STATUS_ERRORS_CAN_COMM);
		snprintf(v[3], string_size, HV_BALANCING_STATUS_ERRORS_LTC_COMM);
		snprintf(v[4], string_size, HV_BALANCING_STATUS_ERRORS_TEMP_COMM_0);
		snprintf(v[5], string_size, HV_BALANCING_STATUS_ERRORS_TEMP_COMM_1);
		snprintf(v[6], string_size, HV_BALANCING_STATUS_ERRORS_TEMP_COMM_2);
		snprintf(v[7], string_size, HV_BALANCING_STATUS_ERRORS_TEMP_COMM_3);
		snprintf(v[8], string_size, HV_BALANCING_STATUS_ERRORS_TEMP_COMM_4);
		snprintf(v[9], string_size, HV_BALANCING_STATUS_ERRORS_TEMP_COMM_5);
		snprintf(v[10], string_size, HV_BALANCING_STATUS_ERRORS_OPEN_WIRE);
		snprintf(v[11], string_size, HV_BALANCING_STATUS_BALANCING_CELLS_CELL0);
		snprintf(v[12], string_size, HV_BALANCING_STATUS_BALANCING_CELLS_CELL1);
		snprintf(v[13], string_size, HV_BALANCING_STATUS_BALANCING_CELLS_CELL2);
		snprintf(v[14], string_size, HV_BALANCING_STATUS_BALANCING_CELLS_CELL3);
		snprintf(v[15], string_size, HV_BALANCING_STATUS_BALANCING_CELLS_CELL4);
		snprintf(v[16], string_size, HV_BALANCING_STATUS_BALANCING_CELLS_CELL5);
		snprintf(v[17], string_size, HV_BALANCING_STATUS_BALANCING_CELLS_CELL6);
		snprintf(v[18], string_size, HV_BALANCING_STATUS_BALANCING_CELLS_CELL7);
		snprintf(v[19], string_size, HV_BALANCING_STATUS_BALANCING_CELLS_CELL8);
		snprintf(v[20], string_size, HV_BALANCING_STATUS_BALANCING_CELLS_CELL9);
		snprintf(v[21], string_size, HV_BALANCING_STATUS_BALANCING_CELLS_CELL10);
		snprintf(v[22], string_size, HV_BALANCING_STATUS_BALANCING_CELLS_CELL11);
		snprintf(v[23], string_size, HV_BALANCING_STATUS_BALANCING_CELLS_CELL12);
		snprintf(v[24], string_size, HV_BALANCING_STATUS_BALANCING_CELLS_CELL13);
		snprintf(v[25], string_size, HV_BALANCING_STATUS_BALANCING_CELLS_CELL14);
		snprintf(v[26], string_size, HV_BALANCING_STATUS_BALANCING_CELLS_CELL15);
		snprintf(v[27], string_size, HV_BALANCING_STATUS_BALANCING_CELLS_CELL16);
		snprintf(v[28], string_size, HV_BALANCING_STATUS_BALANCING_CELLS_CELL17);

		return 0;
	case 1032:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, HV_SET_BALANCING_STATUS_SET_BALANCING_STATUS);
		snprintf(v[1], string_size, HV_SET_BALANCING_STATUS_BALANCING_THRESHOLD);

		return 0;
	case 568:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, LV_STATUS_STATUS);

		return 0;
	case 1568:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, LV_RADIATOR_SPEED_RADIATOR_SPEED);

		return 0;
	case 1576:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, LV_PUMPS_SPEED_PUMPS_SPEED);

		return 0;
	case 1040:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, LV_SET_RADIATOR_SPEED_RADIATOR_SPEED);

		return 0;
	case 1048:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, LV_SET_PUMPS_SPEED_PUMPS_SPEED);

		return 0;
	case 576:
		if(23 > fields_size) return 1;
		snprintf(v[0], string_size, LV_ERRORS_ERRORS_CELL_UNDERVOLTAGE);
		snprintf(v[1], string_size, LV_ERRORS_ERRORS_CELL_OVERVOLTAGE);
		snprintf(v[2], string_size, LV_ERRORS_ERRORS_BATTERY_OPEN_WIRE);
		snprintf(v[3], string_size, LV_ERRORS_ERRORS_CAN);
		snprintf(v[4], string_size, LV_ERRORS_ERRORS_SPI);
		snprintf(v[5], string_size, LV_ERRORS_ERRORS_OVER_CURRENT);
		snprintf(v[6], string_size, LV_ERRORS_ERRORS_CELL_UNDER_TEMPERATURE);
		snprintf(v[7], string_size, LV_ERRORS_ERRORS_CELL_OVER_TEMPERATURE);
		snprintf(v[8], string_size, LV_ERRORS_ERRORS_RELAY);
		snprintf(v[9], string_size, LV_ERRORS_ERRORS_BMS_MONITOR);
		snprintf(v[10], string_size, LV_ERRORS_ERRORS_VOLTAGES_NOT_READY);
		snprintf(v[11], string_size, LV_ERRORS_ERRORS_MCP23017);
		snprintf(v[12], string_size, LV_ERRORS_ERRORS_RADIATOR);
		snprintf(v[13], string_size, LV_ERRORS_ERRORS_FAN);
		snprintf(v[14], string_size, LV_ERRORS_ERRORS_PUMP);
		snprintf(v[15], string_size, LV_ERRORS_ERRORS_ADC_INIT);
		snprintf(v[16], string_size, LV_ERRORS_ERRORS_MUX);
		snprintf(v[17], string_size, LV_ERRORS_HEALTH_SIGNALS_LVMS_OUT);
		snprintf(v[18], string_size, LV_ERRORS_HEALTH_SIGNALS_RELAY_OUT);
		snprintf(v[19], string_size, LV_ERRORS_HEALTH_SIGNALS_BATTERY_VOLTAGE_OUT);
		snprintf(v[20], string_size, LV_ERRORS_HEALTH_SIGNALS_CHARGER_CURRENT);
		snprintf(v[21], string_size, LV_ERRORS_HEALTH_SIGNALS_BATTERY_CURRENT);
		snprintf(v[22], string_size, LV_ERRORS_HEALTH_SIGNALS_SIGN_BATTERY_CURRENT);

		return 0;
	case 584:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, LV_FEEDBACK_TS_VOLTAGE_BSPD);
		snprintf(v[1], string_size, LV_FEEDBACK_TS_VOLTAGE_HVD);
		snprintf(v[2], string_size, LV_FEEDBACK_TS_VOLTAGE_INVC_INTERLOCK);
		snprintf(v[3], string_size, LV_FEEDBACK_TS_VOLTAGE_AMS);

		return 0;
	case 592:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, LV_FEEDBACK_SD_VOLTAGE_SD_END);
		snprintf(v[1], string_size, LV_FEEDBACK_SD_VOLTAGE_LVMS);
		snprintf(v[2], string_size, LV_FEEDBACK_SD_VOLTAGE_INTERLOCK);
		snprintf(v[3], string_size, LV_FEEDBACK_SD_VOLTAGE_SD_START);

		return 0;
	case 600:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, LV_FEEDBACK_ENCLOSURE_VOLTAGE_LV_ENCL);
		snprintf(v[1], string_size, LV_FEEDBACK_ENCLOSURE_VOLTAGE_INVC_LID);
		snprintf(v[2], string_size, LV_FEEDBACK_ENCLOSURE_VOLTAGE_HV_ENCL_2);
		snprintf(v[3], string_size, LV_FEEDBACK_ENCLOSURE_VOLTAGE_BACKPLATE);

		return 0;
	case 608:
		if(7 > fields_size) return 1;
		snprintf(v[0], string_size, LV_FEEDBACK_GPIO_EXTENDER_FEEDBACK_INVERTERS);
		snprintf(v[1], string_size, LV_FEEDBACK_GPIO_EXTENDER_FEEDBACK_PCBS);
		snprintf(v[2], string_size, LV_FEEDBACK_GPIO_EXTENDER_FEEDBACK_PUMPS);
		snprintf(v[3], string_size, LV_FEEDBACK_GPIO_EXTENDER_FEEDBACK_RADIATORS);
		snprintf(v[4], string_size, LV_FEEDBACK_GPIO_EXTENDER_FEEDBACK_SHUTDOWN);
		snprintf(v[5], string_size, LV_FEEDBACK_GPIO_EXTENDER_FEEDBACK_HV_FANS);
		snprintf(v[6], string_size, LV_FEEDBACK_GPIO_EXTENDER_FEEDBACK_AUTONOMOUS_SYSTEM_ACTUATION);

		return 0;
	case 616:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, LV_INVERTER_CONNECTION_STATUS_STATUS);

		return 0;
	case 64:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, LV_SET_INVERTER_CONNECTION_STATUS_STATUS);

		return 0;
	case 1584:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, TLM_STATUS_STATUS);

		return 0;
	case 1056:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, TLM_SET_STATUS_STATUS);

		return 0;
	case 624:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, HANDCART_STATUS_CONNECTED);

		return 0;
	case 1592:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, HANDCART_SETTINGS_TARGET_VOLTAGE);
		snprintf(v[1], string_size, HANDCART_SETTINGS_FANS_OVERRIDE);
		snprintf(v[2], string_size, HANDCART_SETTINGS_FANS_SPEED);
		snprintf(v[3], string_size, HANDCART_SETTINGS_ACC_CHARGE_CURRENT);
		snprintf(v[4], string_size, HANDCART_SETTINGS_GRID_MAX_CURRENT);
		snprintf(v[5], string_size, HANDCART_SETTINGS_STATUS);

		return 0;
	case 1064:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, HANDCART_SET_SETTINGS_TARGET_VOLTAGE);
		snprintf(v[1], string_size, HANDCART_SET_SETTINGS_FANS_OVERRIDE);
		snprintf(v[2], string_size, HANDCART_SET_SETTINGS_FANS_SPEED);
		snprintf(v[3], string_size, HANDCART_SET_SETTINGS_ACC_CHARGE_CURRENT);
		snprintf(v[4], string_size, HANDCART_SET_SETTINGS_GRID_MAX_CURRENT);
		snprintf(v[5], string_size, HANDCART_SET_SETTINGS_STATUS);

		return 0;
	case 632:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, ECU_STATUS_STATUS);

		return 0;
	case 72:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, ECU_SET_STATUS_STATUS);

		return 0;
	case 1072:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, ECU_INVERTER_STATUS_RL);
		snprintf(v[1], string_size, ECU_INVERTER_STATUS_RR);

		return 0;
	case 640:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, ECU_CONTROL_STATUS_CONTROL_ENABLED);
		snprintf(v[1], string_size, ECU_CONTROL_STATUS_CONTROL_ERRORS_FORCED_OFF);
		snprintf(v[2], string_size, ECU_CONTROL_STATUS_CONTROL_ERRORS_WRONG_MAPS);
		snprintf(v[3], string_size, ECU_CONTROL_STATUS_CONTROL_ERRORS_CONTROL_WATCHDOG);

		return 0;
	case 648:
		if(9 > fields_size) return 1;
		snprintf(v[0], string_size, ECU_ERRORS_ERROR_PEDAL_ADC);
		snprintf(v[1], string_size, ECU_ERRORS_ERROR_PEDAL_IMPLAUSIBILITY);
		snprintf(v[2], string_size, ECU_ERRORS_ERROR_IMU_TOUT);
		snprintf(v[3], string_size, ECU_ERRORS_ERROR_IRTS_TOUT);
		snprintf(v[4], string_size, ECU_ERRORS_ERROR_TS_TOUT);
		snprintf(v[5], string_size, ECU_ERRORS_ERROR_INVL_TOUT);
		snprintf(v[6], string_size, ECU_ERRORS_ERROR_INVR_TOUT);
		snprintf(v[7], string_size, ECU_ERRORS_ERROR_STEER_TOUT);
		snprintf(v[8], string_size, ECU_ERRORS_ERROR_FSM);

		return 0;
	case 656:
		if(8 > fields_size) return 1;
		snprintf(v[0], string_size, ECU_FEEDBACKS_FEEDBACKS_SD_COCK_FB);
		snprintf(v[1], string_size, ECU_FEEDBACKS_FEEDBACKS_SD_FB1);
		snprintf(v[2], string_size, ECU_FEEDBACKS_FEEDBACKS_SD_BOTS_FB);
		snprintf(v[3], string_size, ECU_FEEDBACKS_FEEDBACKS_SD_INTERIAL_FB);
		snprintf(v[4], string_size, ECU_FEEDBACKS_FEEDBACKS_SD_FB4);
		snprintf(v[5], string_size, ECU_FEEDBACKS_FEEDBACKS_SD_IN);
		snprintf(v[6], string_size, ECU_FEEDBACKS_FEEDBACKS_SD_OUT);
		snprintf(v[7], string_size, ECU_FEEDBACKS_FEEDBACKS_SD_CTRL_PIN);

		return 0;
	case 664:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, ECU_POWER_MAPS_MAP_PW);
		snprintf(v[1], string_size, ECU_POWER_MAPS_MAP_SC);
		snprintf(v[2], string_size, ECU_POWER_MAPS_MAP_TV);

		return 0;
	case 80:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, ECU_SET_POWER_MAPS_MAP_PW);
		snprintf(v[1], string_size, ECU_SET_POWER_MAPS_MAP_SC);
		snprintf(v[2], string_size, ECU_SET_POWER_MAPS_MAP_TV);

		return 0;
	case 1600:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, ECU_PTT_STATUS_STATUS);

		return 0;
	case 1080:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, ECU_SET_PTT_STATUS_STATUS);

		return 0;
	case 513:
		if(8 > fields_size) return 1;
		snprintf(v[0], string_size, INV_L_REQUEST_DATA_0);
		snprintf(v[1], string_size, INV_L_REQUEST_DATA_1);
		snprintf(v[2], string_size, INV_L_REQUEST_DATA_2);
		snprintf(v[3], string_size, INV_L_REQUEST_DATA_3);
		snprintf(v[4], string_size, INV_L_REQUEST_DATA_4);
		snprintf(v[5], string_size, INV_L_REQUEST_DATA_5);
		snprintf(v[6], string_size, INV_L_REQUEST_DATA_6);
		snprintf(v[7], string_size, INV_L_REQUEST_DATA_7);

		return 0;
	case 672:
		if(5 > fields_size) return 1;
		snprintf(v[0], string_size, CONTROL_OUTPUT_ESTIMATED_VELOCITY);
		snprintf(v[1], string_size, CONTROL_OUTPUT_TORQUE_MAX_L);
		snprintf(v[2], string_size, CONTROL_OUTPUT_TORQUE_MAX_R);
		snprintf(v[3], string_size, CONTROL_OUTPUT_TORQUE_L);
		snprintf(v[4], string_size, CONTROL_OUTPUT_TORQUE_R);

		return 0;
	case 680:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, CONTROL_STATUS_MAP_PW);
		snprintf(v[1], string_size, CONTROL_STATUS_MAP_SC);
		snprintf(v[2], string_size, CONTROL_STATUS_MAP_TV);

		return 0;
	case 514:
		if(8 > fields_size) return 1;
		snprintf(v[0], string_size, INV_R_REQUEST_DATA_0);
		snprintf(v[1], string_size, INV_R_REQUEST_DATA_1);
		snprintf(v[2], string_size, INV_R_REQUEST_DATA_2);
		snprintf(v[3], string_size, INV_R_REQUEST_DATA_3);
		snprintf(v[4], string_size, INV_R_REQUEST_DATA_4);
		snprintf(v[5], string_size, INV_R_REQUEST_DATA_5);
		snprintf(v[6], string_size, INV_R_REQUEST_DATA_6);
		snprintf(v[7], string_size, INV_R_REQUEST_DATA_7);

		return 0;
	case 385:
		if(8 > fields_size) return 1;
		snprintf(v[0], string_size, INV_L_RESPONSE_REG_ID);
		snprintf(v[1], string_size, INV_L_RESPONSE_DATA_0);
		snprintf(v[2], string_size, INV_L_RESPONSE_DATA_1);
		snprintf(v[3], string_size, INV_L_RESPONSE_DATA_2);
		snprintf(v[4], string_size, INV_L_RESPONSE_DATA_3);
		snprintf(v[5], string_size, INV_L_RESPONSE_DATA_4);
		snprintf(v[6], string_size, INV_L_RESPONSE_DATA_5);
		snprintf(v[7], string_size, INV_L_RESPONSE_DATA_6);

		return 0;
	case 386:
		if(8 > fields_size) return 1;
		snprintf(v[0], string_size, INV_R_RESPONSE_REG_ID);
		snprintf(v[1], string_size, INV_R_RESPONSE_DATA_0);
		snprintf(v[2], string_size, INV_R_RESPONSE_DATA_1);
		snprintf(v[3], string_size, INV_R_RESPONSE_DATA_2);
		snprintf(v[4], string_size, INV_R_RESPONSE_DATA_3);
		snprintf(v[5], string_size, INV_R_RESPONSE_DATA_4);
		snprintf(v[6], string_size, INV_R_RESPONSE_DATA_5);
		snprintf(v[7], string_size, INV_R_RESPONSE_DATA_6);

		return 0;
	case 1608:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, LV_CURRENT_BATTERY_LV_CURRENT);

		return 0;
	case 1616:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, LV_CURRENT_CHARGER_CHARGER_CURRENT);

		return 0;
	case 1624:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, LV_TOTAL_VOLTAGE_TOTAL);

		return 0;
	case 1632:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, LV_CELLS_VOLTAGE_START_INDEX);
		snprintf(v[1], string_size, LV_CELLS_VOLTAGE_VOLTAGE_0);
		snprintf(v[2], string_size, LV_CELLS_VOLTAGE_VOLTAGE_1);
		snprintf(v[3], string_size, LV_CELLS_VOLTAGE_VOLTAGE_2);

		return 0;
	case 1640:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, LV_CELLS_VOLTAGE_STATS_MAX);
		snprintf(v[1], string_size, LV_CELLS_VOLTAGE_STATS_MIN);
		snprintf(v[2], string_size, LV_CELLS_VOLTAGE_STATS_DELTA);
		snprintf(v[3], string_size, LV_CELLS_VOLTAGE_STATS_AVG);

		return 0;
	case 1648:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, LV_CELLS_TEMP_START_INDEX);
		snprintf(v[1], string_size, LV_CELLS_TEMP_TEMP_0);
		snprintf(v[2], string_size, LV_CELLS_TEMP_TEMP_1);
		snprintf(v[3], string_size, LV_CELLS_TEMP_TEMP_2);

		return 0;
	case 1656:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, LV_CELLS_TEMP_STATS_MAX);
		snprintf(v[1], string_size, LV_CELLS_TEMP_STATS_MIN);
		snprintf(v[2], string_size, LV_CELLS_TEMP_STATS_AVG);

		return 0;
	case 1664:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, HV_CURRENT_CURRENT);

		return 0;
	case 1672:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, HV_POWER_POWER);

		return 0;
	case 1680:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, HV_ENERGY_ENERGY);

		return 0;
	case 1688:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, HV_SOC_SOC);

		return 0;
	case 1696:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, HV_TOTAL_VOLTAGE_PACK);
		snprintf(v[1], string_size, HV_TOTAL_VOLTAGE_SUM_CELL);
		snprintf(v[2], string_size, HV_TOTAL_VOLTAGE_BUS);

		return 0;
	case 1704:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, HV_CELLS_VOLTAGE_START_INDEX);
		snprintf(v[1], string_size, HV_CELLS_VOLTAGE_VOLTAGE_0);
		snprintf(v[2], string_size, HV_CELLS_VOLTAGE_VOLTAGE_1);
		snprintf(v[3], string_size, HV_CELLS_VOLTAGE_VOLTAGE_2);

		return 0;
	case 1712:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, HV_CELLS_VOLTAGE_STATS_MAX);
		snprintf(v[1], string_size, HV_CELLS_VOLTAGE_STATS_MIN);
		snprintf(v[2], string_size, HV_CELLS_VOLTAGE_STATS_DELTA);
		snprintf(v[3], string_size, HV_CELLS_VOLTAGE_STATS_AVG);

		return 0;
	case 1720:
		if(5 > fields_size) return 1;
		snprintf(v[0], string_size, HV_CELLS_TEMP_START_INDEX);
		snprintf(v[1], string_size, HV_CELLS_TEMP_TEMP_0);
		snprintf(v[2], string_size, HV_CELLS_TEMP_TEMP_1);
		snprintf(v[3], string_size, HV_CELLS_TEMP_TEMP_2);
		snprintf(v[4], string_size, HV_CELLS_TEMP_TEMP_3);

		return 0;
	case 1728:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, HV_CELLS_TEMP_STATS_MAX);
		snprintf(v[1], string_size, HV_CELLS_TEMP_STATS_MIN);
		snprintf(v[2], string_size, HV_CELLS_TEMP_STATS_AVG);

		return 0;
	case 1736:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, DEBUG_SIGNAL_1_FIELD_1);
		snprintf(v[1], string_size, DEBUG_SIGNAL_1_FIELD_2);
		snprintf(v[2], string_size, DEBUG_SIGNAL_1_FIELD_3);
		snprintf(v[3], string_size, DEBUG_SIGNAL_1_FIELD_4);

		return 0;

    }
    return 0;
}
int primary_enum_fields(int enum_id, char **v, size_t fields_size, size_t string_size)
{
    switch(enum_id)
    {
	case 0:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_cellboard_version_cellboard_id_cellboard_0");
		snprintf(v[1], string_size, "primary_hv_cellboard_version_cellboard_id_cellboard_1");
		snprintf(v[2], string_size, "primary_hv_cellboard_version_cellboard_id_cellboard_2");
		snprintf(v[3], string_size, "primary_hv_cellboard_version_cellboard_id_cellboard_3");
		snprintf(v[4], string_size, "primary_hv_cellboard_version_cellboard_id_cellboard_4");
		snprintf(v[5], string_size, "primary_hv_cellboard_version_cellboard_id_cellboard_5");

		return 0;
	case 1:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_fans_status_fans_override_off");
		snprintf(v[1], string_size, "primary_hv_fans_status_fans_override_on");

		return 0;
	case 2:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_set_fans_status_fans_override_off");
		snprintf(v[1], string_size, "primary_hv_set_fans_status_fans_override_on");

		return 0;
	case 3:
		if(7 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_status_status_init");
		snprintf(v[1], string_size, "primary_hv_status_status_idle");
		snprintf(v[2], string_size, "primary_hv_status_status_airn_close");
		snprintf(v[3], string_size, "primary_hv_status_status_precharge");
		snprintf(v[4], string_size, "primary_hv_status_status_airp_close");
		snprintf(v[5], string_size, "primary_hv_status_status_ts_on");
		snprintf(v[6], string_size, "primary_hv_status_status_fatal_error");

		return 0;
	case 4:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_set_status_ecu_hv_status_set_off");
		snprintf(v[1], string_size, "primary_hv_set_status_ecu_hv_status_set_on");

		return 0;
	case 5:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_set_status_handcart_hv_status_set_off");
		snprintf(v[1], string_size, "primary_hv_set_status_handcart_hv_status_set_on");

		return 0;
	case 6:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_balancing_status_cellboard_id_cellboard_0");
		snprintf(v[1], string_size, "primary_hv_balancing_status_cellboard_id_cellboard_1");
		snprintf(v[2], string_size, "primary_hv_balancing_status_cellboard_id_cellboard_2");
		snprintf(v[3], string_size, "primary_hv_balancing_status_cellboard_id_cellboard_3");
		snprintf(v[4], string_size, "primary_hv_balancing_status_cellboard_id_cellboard_4");
		snprintf(v[5], string_size, "primary_hv_balancing_status_cellboard_id_cellboard_5");

		return 0;
	case 7:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_balancing_status_balancing_status_off");
		snprintf(v[1], string_size, "primary_hv_balancing_status_balancing_status_on");

		return 0;
	case 8:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_set_balancing_status_set_balancing_status_off");
		snprintf(v[1], string_size, "primary_hv_set_balancing_status_set_balancing_status_on");

		return 0;
	case 9:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_lv_status_status_init");
		snprintf(v[1], string_size, "primary_lv_status_status_idle");
		snprintf(v[2], string_size, "primary_lv_status_status_tson");
		snprintf(v[3], string_size, "primary_lv_status_status_run");
		snprintf(v[4], string_size, "primary_lv_status_status_flashing");
		snprintf(v[5], string_size, "primary_lv_status_status_error");

		return 0;
	case 10:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_lv_inverter_connection_status_status_off");
		snprintf(v[1], string_size, "primary_lv_inverter_connection_status_status_on");

		return 0;
	case 11:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_lv_set_inverter_connection_status_status_off");
		snprintf(v[1], string_size, "primary_lv_set_inverter_connection_status_status_on");

		return 0;
	case 12:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_tlm_status_status_off");
		snprintf(v[1], string_size, "primary_tlm_status_status_on");

		return 0;
	case 13:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_tlm_set_status_status_off");
		snprintf(v[1], string_size, "primary_tlm_set_status_status_on");

		return 0;
	case 14:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_handcart_status_connected_off");
		snprintf(v[1], string_size, "primary_handcart_status_connected_on");

		return 0;
	case 15:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_handcart_settings_fans_override_off");
		snprintf(v[1], string_size, "primary_handcart_settings_fans_override_on");

		return 0;
	case 16:
		if(9 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_handcart_settings_status_none");
		snprintf(v[1], string_size, "primary_handcart_settings_status_check");
		snprintf(v[2], string_size, "primary_handcart_settings_status_idle");
		snprintf(v[3], string_size, "primary_handcart_settings_status_precharge");
		snprintf(v[4], string_size, "primary_handcart_settings_status_ready");
		snprintf(v[5], string_size, "primary_handcart_settings_status_charge");
		snprintf(v[6], string_size, "primary_handcart_settings_status_charge_done");
		snprintf(v[7], string_size, "primary_handcart_settings_status_balancing");
		snprintf(v[8], string_size, "primary_handcart_settings_status_error");

		return 0;
	case 17:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_handcart_set_settings_fans_override_off");
		snprintf(v[1], string_size, "primary_handcart_set_settings_fans_override_on");

		return 0;
	case 18:
		if(9 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_handcart_set_settings_status_none");
		snprintf(v[1], string_size, "primary_handcart_set_settings_status_check");
		snprintf(v[2], string_size, "primary_handcart_set_settings_status_idle");
		snprintf(v[3], string_size, "primary_handcart_set_settings_status_precharge");
		snprintf(v[4], string_size, "primary_handcart_set_settings_status_ready");
		snprintf(v[5], string_size, "primary_handcart_set_settings_status_charge");
		snprintf(v[6], string_size, "primary_handcart_set_settings_status_charge_done");
		snprintf(v[7], string_size, "primary_handcart_set_settings_status_balancing");
		snprintf(v[8], string_size, "primary_handcart_set_settings_status_error");

		return 0;
	case 19:
		if(13 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ecu_status_status_init");
		snprintf(v[1], string_size, "primary_ecu_status_status_enable_inv_updates");
		snprintf(v[2], string_size, "primary_ecu_status_status_check_inv_settings");
		snprintf(v[3], string_size, "primary_ecu_status_status_idle");
		snprintf(v[4], string_size, "primary_ecu_status_status_start_ts_precharge");
		snprintf(v[5], string_size, "primary_ecu_status_status_wait_ts_precharge");
		snprintf(v[6], string_size, "primary_ecu_status_status_wait_driver");
		snprintf(v[7], string_size, "primary_ecu_status_status_enable_inv_drive");
		snprintf(v[8], string_size, "primary_ecu_status_status_drive");
		snprintf(v[9], string_size, "primary_ecu_status_status_disable_inv_drive");
		snprintf(v[10], string_size, "primary_ecu_status_status_start_ts_discharge");
		snprintf(v[11], string_size, "primary_ecu_status_status_wait_ts_discharge");
		snprintf(v[12], string_size, "primary_ecu_status_status_fatal_error");

		return 0;
	case 20:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ecu_set_status_status_idle");
		snprintf(v[1], string_size, "primary_ecu_set_status_status_ready");
		snprintf(v[2], string_size, "primary_ecu_set_status_status_drive");

		return 0;
	case 21:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ecu_inverter_status_rl_disabled");
		snprintf(v[1], string_size, "primary_ecu_inverter_status_rl_rfe_on");
		snprintf(v[2], string_size, "primary_ecu_inverter_status_rl_frg_on");
		snprintf(v[3], string_size, "primary_ecu_inverter_status_rl_enabled");

		return 0;
	case 22:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ecu_inverter_status_rr_disabled");
		snprintf(v[1], string_size, "primary_ecu_inverter_status_rr_rfe_on");
		snprintf(v[2], string_size, "primary_ecu_inverter_status_rr_frg_on");
		snprintf(v[3], string_size, "primary_ecu_inverter_status_rr_enabled");

		return 0;
	case 23:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ecu_ptt_status_status_off");
		snprintf(v[1], string_size, "primary_ecu_ptt_status_status_on");

		return 0;
	case 24:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ecu_set_ptt_status_status_off");
		snprintf(v[1], string_size, "primary_ecu_set_ptt_status_status_on");

		return 0;

    }
    return 0;
}
int primary_serialize_from_id(int id, char *s, uint8_t *data, size_t *size)
{
    switch(id)
    {
	case 1818:
	{
		primary_nlg5_diag_tx_t tmp;
		primary_nlg5_diag_tx_converted_t tmp_converted;
		uint64_t r_lad_d_paramrp;

		sscanf(s, "%" SCNu64 "," ,
			&r_lad_d_paramrp);
		tmp_converted.lad_d_paramrp = (uint64_t)r_lad_d_paramrp;

		primary_nlg5_diag_tx_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_NLG5_DIAG_TX_BYTE_SIZE;
		return primary_nlg5_diag_tx_pack(data, &tmp, PRIMARY_NLG5_DIAG_TX_BYTE_SIZE);
	}
	case 1816:
	{
		primary_nlg5_diag_rx_t tmp;
		primary_nlg5_diag_rx_converted_t tmp_converted;
		uint64_t r_lad_d_paramrq;

		sscanf(s, "%" SCNu64 "," ,
			&r_lad_d_paramrq);
		tmp_converted.lad_d_paramrq = (uint64_t)r_lad_d_paramrq;

		primary_nlg5_diag_rx_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_NLG5_DIAG_RX_BYTE_SIZE;
		return primary_nlg5_diag_rx_pack(data, &tmp, PRIMARY_NLG5_DIAG_RX_BYTE_SIZE);
	}
	case 1556:
	{
		primary_nlg5_err_t tmp;
		primary_nlg5_err_converted_t tmp_converted;
		uint8_t r_nlg5_e_oov;
		uint8_t r_nlg5_e_mov_ii;
		uint8_t r_nlg5_e_mov_i;
		uint8_t r_nlg5_e_sc;
		uint8_t r_nlg5_e_p_om;
		uint8_t r_nlg5_e_p_mv;
		uint8_t r_nlg5_e_of;
		uint8_t r_nlg5_e_mf;
		uint8_t r_nlg5_e_b_p;
		uint8_t r_nlg5_e_t_c;
		uint8_t r_nlg5_e_t_pow;
		uint8_t r_nlg5_e_t_dio;
		uint8_t r_nlg5_e_t_tr;
		uint8_t r_nlg5_e_t_ext1;
		uint8_t r_nlg5_e_t_ext2;
		uint8_t r_nlg5_e_t_ext3;
		uint8_t r_nlg5_e_f_crc;
		uint8_t r_nlg5_e_nv_crc;
		uint8_t r_nlg5_e_es_crc;
		uint8_t r_nlg5_e_ep_crc;
		uint8_t r_nlg5_e_wdt;
		uint8_t r_nlg5_e_init;
		uint8_t r_nlg5_e_c_to;
		uint8_t r_nlg5_e_c_off;
		uint8_t r_nlg5_e_c_tx;
		uint8_t r_nlg5_e_c_rx;
		uint8_t r_nlg5_e_sdt_bt;
		uint8_t r_nlg5_e_sdt_bv;
		uint8_t r_nlg5_e_sdt_ah;
		uint8_t r_nlg5_e_sdt_ct;
		uint8_t r_nlg5_w_pl_mv;
		uint8_t r_nlg5_w_pl_bv;
		uint8_t r_nlg5_w_pl_it;
		uint8_t r_nlg5_w_c_vor;
		uint8_t r_nlg5_w_cm_na;
		uint8_t r_nlg5_w_od;
		uint8_t r_nlg5_w_sc_m;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  ,
			&r_nlg5_e_oov,
			&r_nlg5_e_mov_ii,
			&r_nlg5_e_mov_i,
			&r_nlg5_e_sc,
			&r_nlg5_e_p_om,
			&r_nlg5_e_p_mv,
			&r_nlg5_e_of,
			&r_nlg5_e_mf,
			&r_nlg5_e_b_p,
			&r_nlg5_e_t_c,
			&r_nlg5_e_t_pow,
			&r_nlg5_e_t_dio,
			&r_nlg5_e_t_tr,
			&r_nlg5_e_t_ext1,
			&r_nlg5_e_t_ext2,
			&r_nlg5_e_t_ext3,
			&r_nlg5_e_f_crc,
			&r_nlg5_e_nv_crc,
			&r_nlg5_e_es_crc,
			&r_nlg5_e_ep_crc,
			&r_nlg5_e_wdt,
			&r_nlg5_e_init,
			&r_nlg5_e_c_to,
			&r_nlg5_e_c_off,
			&r_nlg5_e_c_tx,
			&r_nlg5_e_c_rx,
			&r_nlg5_e_sdt_bt,
			&r_nlg5_e_sdt_bv,
			&r_nlg5_e_sdt_ah,
			&r_nlg5_e_sdt_ct,
			&r_nlg5_w_pl_mv,
			&r_nlg5_w_pl_bv,
			&r_nlg5_w_pl_it,
			&r_nlg5_w_c_vor,
			&r_nlg5_w_cm_na,
			&r_nlg5_w_od,
			&r_nlg5_w_sc_m);
		tmp_converted.nlg5_e_oov = (uint8_t)r_nlg5_e_oov;
		tmp_converted.nlg5_e_mov_ii = (uint8_t)r_nlg5_e_mov_ii;
		tmp_converted.nlg5_e_mov_i = (uint8_t)r_nlg5_e_mov_i;
		tmp_converted.nlg5_e_sc = (uint8_t)r_nlg5_e_sc;
		tmp_converted.nlg5_e_p_om = (uint8_t)r_nlg5_e_p_om;
		tmp_converted.nlg5_e_p_mv = (uint8_t)r_nlg5_e_p_mv;
		tmp_converted.nlg5_e_of = (uint8_t)r_nlg5_e_of;
		tmp_converted.nlg5_e_mf = (uint8_t)r_nlg5_e_mf;
		tmp_converted.nlg5_e_b_p = (uint8_t)r_nlg5_e_b_p;
		tmp_converted.nlg5_e_t_c = (uint8_t)r_nlg5_e_t_c;
		tmp_converted.nlg5_e_t_pow = (uint8_t)r_nlg5_e_t_pow;
		tmp_converted.nlg5_e_t_dio = (uint8_t)r_nlg5_e_t_dio;
		tmp_converted.nlg5_e_t_tr = (uint8_t)r_nlg5_e_t_tr;
		tmp_converted.nlg5_e_t_ext1 = (uint8_t)r_nlg5_e_t_ext1;
		tmp_converted.nlg5_e_t_ext2 = (uint8_t)r_nlg5_e_t_ext2;
		tmp_converted.nlg5_e_t_ext3 = (uint8_t)r_nlg5_e_t_ext3;
		tmp_converted.nlg5_e_f_crc = (uint8_t)r_nlg5_e_f_crc;
		tmp_converted.nlg5_e_nv_crc = (uint8_t)r_nlg5_e_nv_crc;
		tmp_converted.nlg5_e_es_crc = (uint8_t)r_nlg5_e_es_crc;
		tmp_converted.nlg5_e_ep_crc = (uint8_t)r_nlg5_e_ep_crc;
		tmp_converted.nlg5_e_wdt = (uint8_t)r_nlg5_e_wdt;
		tmp_converted.nlg5_e_init = (uint8_t)r_nlg5_e_init;
		tmp_converted.nlg5_e_c_to = (uint8_t)r_nlg5_e_c_to;
		tmp_converted.nlg5_e_c_off = (uint8_t)r_nlg5_e_c_off;
		tmp_converted.nlg5_e_c_tx = (uint8_t)r_nlg5_e_c_tx;
		tmp_converted.nlg5_e_c_rx = (uint8_t)r_nlg5_e_c_rx;
		tmp_converted.nlg5_e_sdt_bt = (uint8_t)r_nlg5_e_sdt_bt;
		tmp_converted.nlg5_e_sdt_bv = (uint8_t)r_nlg5_e_sdt_bv;
		tmp_converted.nlg5_e_sdt_ah = (uint8_t)r_nlg5_e_sdt_ah;
		tmp_converted.nlg5_e_sdt_ct = (uint8_t)r_nlg5_e_sdt_ct;
		tmp_converted.nlg5_w_pl_mv = (uint8_t)r_nlg5_w_pl_mv;
		tmp_converted.nlg5_w_pl_bv = (uint8_t)r_nlg5_w_pl_bv;
		tmp_converted.nlg5_w_pl_it = (uint8_t)r_nlg5_w_pl_it;
		tmp_converted.nlg5_w_c_vor = (uint8_t)r_nlg5_w_c_vor;
		tmp_converted.nlg5_w_cm_na = (uint8_t)r_nlg5_w_cm_na;
		tmp_converted.nlg5_w_od = (uint8_t)r_nlg5_w_od;
		tmp_converted.nlg5_w_sc_m = (uint8_t)r_nlg5_w_sc_m;

		primary_nlg5_err_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_NLG5_ERR_BYTE_SIZE;
		return primary_nlg5_err_pack(data, &tmp, PRIMARY_NLG5_ERR_BYTE_SIZE);
	}
	case 1555:
	{
		primary_nlg5_temp_t tmp;
		primary_nlg5_temp_converted_t tmp_converted;
		float r_nlg5_p_tmp;
		float r_nlg5_tmp_ext1;
		float r_nlg5_temp_ext2;
		float r_nlg5_tmp_ext3;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_nlg5_p_tmp,
			&r_nlg5_tmp_ext1,
			&r_nlg5_temp_ext2,
			&r_nlg5_tmp_ext3);
		tmp_converted.nlg5_p_tmp = (float)r_nlg5_p_tmp;
		tmp_converted.nlg5_tmp_ext1 = (float)r_nlg5_tmp_ext1;
		tmp_converted.nlg5_temp_ext2 = (float)r_nlg5_temp_ext2;
		tmp_converted.nlg5_tmp_ext3 = (float)r_nlg5_tmp_ext3;

		primary_nlg5_temp_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_NLG5_TEMP_BYTE_SIZE;
		return primary_nlg5_temp_pack(data, &tmp, PRIMARY_NLG5_TEMP_BYTE_SIZE);
	}
	case 1554:
	{
		primary_nlg5_act_ii_t tmp;
		primary_nlg5_act_ii_converted_t tmp_converted;
		float r_nlg5_s_mc_m_cp;
		float r_nlg5_s_mc_m_pi;
		float r_nlg5_abv;
		float r_nlg5_ahc_ext;
		float r_nlg5_oc_bo;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_nlg5_s_mc_m_cp,
			&r_nlg5_s_mc_m_pi,
			&r_nlg5_abv,
			&r_nlg5_ahc_ext,
			&r_nlg5_oc_bo);
		tmp_converted.nlg5_s_mc_m_cp = (float)r_nlg5_s_mc_m_cp;
		tmp_converted.nlg5_s_mc_m_pi = (float)r_nlg5_s_mc_m_pi;
		tmp_converted.nlg5_abv = (float)r_nlg5_abv;
		tmp_converted.nlg5_ahc_ext = (float)r_nlg5_ahc_ext;
		tmp_converted.nlg5_oc_bo = (float)r_nlg5_oc_bo;

		primary_nlg5_act_ii_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_NLG5_ACT_II_BYTE_SIZE;
		return primary_nlg5_act_ii_pack(data, &tmp, PRIMARY_NLG5_ACT_II_BYTE_SIZE);
	}
	case 1553:
	{
		primary_nlg5_act_i_t tmp;
		primary_nlg5_act_i_converted_t tmp_converted;
		float r_nlg5_mc_act;
		float r_nlg5_mv_act;
		float r_nlg5_ov_act;
		float r_nlg5_oc_act;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_nlg5_mc_act,
			&r_nlg5_mv_act,
			&r_nlg5_ov_act,
			&r_nlg5_oc_act);
		tmp_converted.nlg5_mc_act = (float)r_nlg5_mc_act;
		tmp_converted.nlg5_mv_act = (float)r_nlg5_mv_act;
		tmp_converted.nlg5_ov_act = (float)r_nlg5_ov_act;
		tmp_converted.nlg5_oc_act = (float)r_nlg5_oc_act;

		primary_nlg5_act_i_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_NLG5_ACT_I_BYTE_SIZE;
		return primary_nlg5_act_i_pack(data, &tmp, PRIMARY_NLG5_ACT_I_BYTE_SIZE);
	}
	case 1552:
	{
		primary_nlg5_st_t tmp;
		primary_nlg5_st_converted_t tmp_converted;
		uint8_t r_nlg5_s_he;
		uint8_t r_nlg5_s_err;
		uint8_t r_nlg5_s_war;
		uint8_t r_nlg5_s_fan;
		uint8_t r_nlg5_s_eum;
		uint8_t r_nlg5_s_um_i;
		uint8_t r_nlg5_s_um_ii;
		uint8_t r_nlg5_s_cp_dt;
		uint8_t r_nlg5_s_bpd_i;
		uint8_t r_nlg5_s_bpd_ii;
		uint8_t r_nlg5_s_l_ov;
		uint8_t r_nlg5_s_l_oc;
		uint8_t r_nlg5_s_l_mc;
		uint8_t r_nlg5_s_l_pi;
		uint8_t r_nlg5_s_l_cp;
		uint8_t r_nlg5_s_l_pmax;
		uint8_t r_nlg5_s_l_mc_max;
		uint8_t r_nlg5_s_l_oc_max;
		uint8_t r_nlg5_s_l_mo_max;
		uint8_t r_nlg5_s_l_t_cprim;
		uint8_t r_nlg5_s_l_t_pow;
		uint8_t r_nlg5_s_l_t_dio;
		uint8_t r_nlg5_s_l_t_tr;
		uint8_t r_nlg5_s_l_t_batt;
		uint8_t r_nlg5_s_aac;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  ,
			&r_nlg5_s_he,
			&r_nlg5_s_err,
			&r_nlg5_s_war,
			&r_nlg5_s_fan,
			&r_nlg5_s_eum,
			&r_nlg5_s_um_i,
			&r_nlg5_s_um_ii,
			&r_nlg5_s_cp_dt,
			&r_nlg5_s_bpd_i,
			&r_nlg5_s_bpd_ii,
			&r_nlg5_s_l_ov,
			&r_nlg5_s_l_oc,
			&r_nlg5_s_l_mc,
			&r_nlg5_s_l_pi,
			&r_nlg5_s_l_cp,
			&r_nlg5_s_l_pmax,
			&r_nlg5_s_l_mc_max,
			&r_nlg5_s_l_oc_max,
			&r_nlg5_s_l_mo_max,
			&r_nlg5_s_l_t_cprim,
			&r_nlg5_s_l_t_pow,
			&r_nlg5_s_l_t_dio,
			&r_nlg5_s_l_t_tr,
			&r_nlg5_s_l_t_batt,
			&r_nlg5_s_aac);
		tmp_converted.nlg5_s_he = (uint8_t)r_nlg5_s_he;
		tmp_converted.nlg5_s_err = (uint8_t)r_nlg5_s_err;
		tmp_converted.nlg5_s_war = (uint8_t)r_nlg5_s_war;
		tmp_converted.nlg5_s_fan = (uint8_t)r_nlg5_s_fan;
		tmp_converted.nlg5_s_eum = (uint8_t)r_nlg5_s_eum;
		tmp_converted.nlg5_s_um_i = (uint8_t)r_nlg5_s_um_i;
		tmp_converted.nlg5_s_um_ii = (uint8_t)r_nlg5_s_um_ii;
		tmp_converted.nlg5_s_cp_dt = (uint8_t)r_nlg5_s_cp_dt;
		tmp_converted.nlg5_s_bpd_i = (uint8_t)r_nlg5_s_bpd_i;
		tmp_converted.nlg5_s_bpd_ii = (uint8_t)r_nlg5_s_bpd_ii;
		tmp_converted.nlg5_s_l_ov = (uint8_t)r_nlg5_s_l_ov;
		tmp_converted.nlg5_s_l_oc = (uint8_t)r_nlg5_s_l_oc;
		tmp_converted.nlg5_s_l_mc = (uint8_t)r_nlg5_s_l_mc;
		tmp_converted.nlg5_s_l_pi = (uint8_t)r_nlg5_s_l_pi;
		tmp_converted.nlg5_s_l_cp = (uint8_t)r_nlg5_s_l_cp;
		tmp_converted.nlg5_s_l_pmax = (uint8_t)r_nlg5_s_l_pmax;
		tmp_converted.nlg5_s_l_mc_max = (uint8_t)r_nlg5_s_l_mc_max;
		tmp_converted.nlg5_s_l_oc_max = (uint8_t)r_nlg5_s_l_oc_max;
		tmp_converted.nlg5_s_l_mo_max = (uint8_t)r_nlg5_s_l_mo_max;
		tmp_converted.nlg5_s_l_t_cprim = (uint8_t)r_nlg5_s_l_t_cprim;
		tmp_converted.nlg5_s_l_t_pow = (uint8_t)r_nlg5_s_l_t_pow;
		tmp_converted.nlg5_s_l_t_dio = (uint8_t)r_nlg5_s_l_t_dio;
		tmp_converted.nlg5_s_l_t_tr = (uint8_t)r_nlg5_s_l_t_tr;
		tmp_converted.nlg5_s_l_t_batt = (uint8_t)r_nlg5_s_l_t_batt;
		tmp_converted.nlg5_s_aac = (uint8_t)r_nlg5_s_aac;

		primary_nlg5_st_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_NLG5_ST_BYTE_SIZE;
		return primary_nlg5_st_pack(data, &tmp, PRIMARY_NLG5_ST_BYTE_SIZE);
	}
	case 1560:
	{
		primary_nlg5_ctl_t tmp;
		primary_nlg5_ctl_converted_t tmp_converted;
		uint8_t r_nlg5_c_c_en;
		uint8_t r_nlg5_c_c_el;
		uint8_t r_nlg5_c_cp_v;
		uint8_t r_nlg5_c_mr;
		float r_nlg5_mc_max;
		float r_nlg5_ov_com;
		float r_nlg5_oc_com;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_nlg5_c_c_en,
			&r_nlg5_c_c_el,
			&r_nlg5_c_cp_v,
			&r_nlg5_c_mr,
			&r_nlg5_mc_max,
			&r_nlg5_ov_com,
			&r_nlg5_oc_com);
		tmp_converted.nlg5_c_c_en = (uint8_t)r_nlg5_c_c_en;
		tmp_converted.nlg5_c_c_el = (uint8_t)r_nlg5_c_c_el;
		tmp_converted.nlg5_c_cp_v = (uint8_t)r_nlg5_c_cp_v;
		tmp_converted.nlg5_c_mr = (uint8_t)r_nlg5_c_mr;
		tmp_converted.nlg5_mc_max = (float)r_nlg5_mc_max;
		tmp_converted.nlg5_ov_com = (float)r_nlg5_ov_com;
		tmp_converted.nlg5_oc_com = (float)r_nlg5_oc_com;

		primary_nlg5_ctl_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_NLG5_CTL_BYTE_SIZE;
		return primary_nlg5_ctl_pack(data, &tmp, PRIMARY_NLG5_CTL_BYTE_SIZE);
	}
	case 700:
	{
		primary_steering_wheel_version_t tmp;
		primary_steering_wheel_version_converted_t tmp_converted;
		uint32_t r_component_build_time;
		uint32_t r_canlib_build_time;

		sscanf(s, "%" SCNu32 "," 
			"%" SCNu32 "," ,
			&r_component_build_time,
			&r_canlib_build_time);
		tmp_converted.component_build_time = (uint32_t)r_component_build_time;
		tmp_converted.canlib_build_time = (uint32_t)r_canlib_build_time;

		primary_steering_wheel_version_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_STEERING_WHEEL_VERSION_BYTE_SIZE;
		return primary_steering_wheel_version_pack(data, &tmp, PRIMARY_STEERING_WHEEL_VERSION_BYTE_SIZE);
	}
	case 701:
	{
		primary_ecu_version_t tmp;
		primary_ecu_version_converted_t tmp_converted;
		uint32_t r_component_build_time;
		uint32_t r_canlib_build_time;

		sscanf(s, "%" SCNu32 "," 
			"%" SCNu32 "," ,
			&r_component_build_time,
			&r_canlib_build_time);
		tmp_converted.component_build_time = (uint32_t)r_component_build_time;
		tmp_converted.canlib_build_time = (uint32_t)r_canlib_build_time;

		primary_ecu_version_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_ECU_VERSION_BYTE_SIZE;
		return primary_ecu_version_pack(data, &tmp, PRIMARY_ECU_VERSION_BYTE_SIZE);
	}
	case 703:
	{
		primary_lv_version_t tmp;
		primary_lv_version_converted_t tmp_converted;
		uint32_t r_component_build_time;
		uint32_t r_canlib_build_time;

		sscanf(s, "%" SCNu32 "," 
			"%" SCNu32 "," ,
			&r_component_build_time,
			&r_canlib_build_time);
		tmp_converted.component_build_time = (uint32_t)r_component_build_time;
		tmp_converted.canlib_build_time = (uint32_t)r_canlib_build_time;

		primary_lv_version_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_LV_VERSION_BYTE_SIZE;
		return primary_lv_version_pack(data, &tmp, PRIMARY_LV_VERSION_BYTE_SIZE);
	}
	case 704:
	{
		primary_tlm_version_t tmp;
		primary_tlm_version_converted_t tmp_converted;
		uint32_t r_component_build_time;
		uint32_t r_canlib_build_time;

		sscanf(s, "%" SCNu32 "," 
			"%" SCNu32 "," ,
			&r_component_build_time,
			&r_canlib_build_time);
		tmp_converted.component_build_time = (uint32_t)r_component_build_time;
		tmp_converted.canlib_build_time = (uint32_t)r_canlib_build_time;

		primary_tlm_version_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_TLM_VERSION_BYTE_SIZE;
		return primary_tlm_version_pack(data, &tmp, PRIMARY_TLM_VERSION_BYTE_SIZE);
	}
	case 702:
	{
		primary_hv_mainboard_version_t tmp;
		primary_hv_mainboard_version_converted_t tmp_converted;
		uint32_t r_component_build_time;
		uint32_t r_canlib_build_time;

		sscanf(s, "%" SCNu32 "," 
			"%" SCNu32 "," ,
			&r_component_build_time,
			&r_canlib_build_time);
		tmp_converted.component_build_time = (uint32_t)r_component_build_time;
		tmp_converted.canlib_build_time = (uint32_t)r_canlib_build_time;

		primary_hv_mainboard_version_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_HV_MAINBOARD_VERSION_BYTE_SIZE;
		return primary_hv_mainboard_version_pack(data, &tmp, PRIMARY_HV_MAINBOARD_VERSION_BYTE_SIZE);
	}
	case 705:
	{
		primary_hv_cellboard_version_t tmp;
		primary_hv_cellboard_version_converted_t tmp_converted;
		uint8_t r_cellboard_id;
		uint16_t r_component_version;
		uint32_t r_canlib_build_time;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu16 "," 
			"%" SCNu32 "," ,
			&r_cellboard_id,
			&r_component_version,
			&r_canlib_build_time);
		tmp_converted.cellboard_id = (primary_hv_cellboard_version_cellboard_id)r_cellboard_id;
		tmp_converted.component_version = (uint16_t)r_component_version;
		tmp_converted.canlib_build_time = (uint32_t)r_canlib_build_time;

		primary_hv_cellboard_version_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_HV_CELLBOARD_VERSION_BYTE_SIZE;
		return primary_hv_cellboard_version_pack(data, &tmp, PRIMARY_HV_CELLBOARD_VERSION_BYTE_SIZE);
	}
	case 24:
	{
		primary_hv_errors_t tmp;
		primary_hv_errors_converted_t tmp_converted;
		uint8_t r_errors_cell_low_voltage;
		uint8_t r_errors_cell_under_voltage;
		uint8_t r_errors_cell_over_voltage;
		uint8_t r_errors_cell_high_temperature;
		uint8_t r_errors_cell_over_temperature;
		uint8_t r_errors_over_current;
		uint8_t r_errors_can;
		uint8_t r_errors_int_voltage_mismatch;
		uint8_t r_errors_cellboard_comm;
		uint8_t r_errors_cellboard_internal;
		uint8_t r_errors_connector_disconnected;
		uint8_t r_errors_fans_disconnected;
		uint8_t r_errors_feedback;
		uint8_t r_errors_feedback_circuitry;
		uint8_t r_errors_eeprom_comm;
		uint8_t r_errors_eeprom_write;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  ,
			&r_errors_cell_low_voltage,
			&r_errors_cell_under_voltage,
			&r_errors_cell_over_voltage,
			&r_errors_cell_high_temperature,
			&r_errors_cell_over_temperature,
			&r_errors_over_current,
			&r_errors_can,
			&r_errors_int_voltage_mismatch,
			&r_errors_cellboard_comm,
			&r_errors_cellboard_internal,
			&r_errors_connector_disconnected,
			&r_errors_fans_disconnected,
			&r_errors_feedback,
			&r_errors_feedback_circuitry,
			&r_errors_eeprom_comm,
			&r_errors_eeprom_write);
		tmp_converted.errors_cell_low_voltage = (uint8_t)r_errors_cell_low_voltage;
		tmp_converted.errors_cell_under_voltage = (uint8_t)r_errors_cell_under_voltage;
		tmp_converted.errors_cell_over_voltage = (uint8_t)r_errors_cell_over_voltage;
		tmp_converted.errors_cell_high_temperature = (uint8_t)r_errors_cell_high_temperature;
		tmp_converted.errors_cell_over_temperature = (uint8_t)r_errors_cell_over_temperature;
		tmp_converted.errors_over_current = (uint8_t)r_errors_over_current;
		tmp_converted.errors_can = (uint8_t)r_errors_can;
		tmp_converted.errors_int_voltage_mismatch = (uint8_t)r_errors_int_voltage_mismatch;
		tmp_converted.errors_cellboard_comm = (uint8_t)r_errors_cellboard_comm;
		tmp_converted.errors_cellboard_internal = (uint8_t)r_errors_cellboard_internal;
		tmp_converted.errors_connector_disconnected = (uint8_t)r_errors_connector_disconnected;
		tmp_converted.errors_fans_disconnected = (uint8_t)r_errors_fans_disconnected;
		tmp_converted.errors_feedback = (uint8_t)r_errors_feedback;
		tmp_converted.errors_feedback_circuitry = (uint8_t)r_errors_feedback_circuitry;
		tmp_converted.errors_eeprom_comm = (uint8_t)r_errors_eeprom_comm;
		tmp_converted.errors_eeprom_write = (uint8_t)r_errors_eeprom_write;

		primary_hv_errors_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_HV_ERRORS_BYTE_SIZE;
		return primary_hv_errors_pack(data, &tmp, PRIMARY_HV_ERRORS_BYTE_SIZE);
	}
	case 512:
	{
		primary_hv_debug_signals_t tmp;
		primary_hv_debug_signals_converted_t tmp_converted;
		uint8_t r_feedbacks_implausibility_detected;
		uint8_t r_feedbacks_imd_cockpit;
		uint8_t r_feedbacks_tsal_green_fault_latched;
		uint8_t r_feedbacks_bms_cockpit;
		uint8_t r_feedbacks_ext_latched;
		uint8_t r_feedbacks_tsal_green;
		uint8_t r_feedbacks_ts_over_60v_status;
		uint8_t r_feedbacks_airn_status;
		uint8_t r_feedbacks_airp_status;
		uint8_t r_feedbacks_airp_gate;
		uint8_t r_feedbacks_airn_gate;
		uint8_t r_feedbacks_precharge_status;
		uint8_t r_feedbacks_tsp_over_60v_status;
		uint8_t r_feedbacks_imd_fault;
		uint8_t r_feedbacks_check_mux;
		uint8_t r_feedbacks_sd_end;
		uint8_t r_feedbacks_sd_out;
		uint8_t r_feedbacks_sd_in;
		uint8_t r_feedbacks_sd_bms;
		uint8_t r_feedbacks_sd_imd;
		uint8_t r_errors_cell_low_voltage;
		uint8_t r_errors_cell_under_voltage;
		uint8_t r_errors_cell_over_voltage;
		uint8_t r_errors_cell_high_temperature;
		uint8_t r_errors_cell_over_temperature;
		uint8_t r_errors_over_current;
		uint8_t r_errors_can;
		uint8_t r_errors_int_voltage_mismatch;
		uint8_t r_errors_cellboard_comm;
		uint8_t r_errors_cellboard_internal;
		uint8_t r_errors_connector_disconnected;
		uint8_t r_errors_fans_disconnected;
		uint8_t r_errors_feedback;
		uint8_t r_errors_feedback_circuitry;
		uint8_t r_errors_eeprom_comm;
		uint8_t r_errors_eeprom_write;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  ,
			&r_feedbacks_implausibility_detected,
			&r_feedbacks_imd_cockpit,
			&r_feedbacks_tsal_green_fault_latched,
			&r_feedbacks_bms_cockpit,
			&r_feedbacks_ext_latched,
			&r_feedbacks_tsal_green,
			&r_feedbacks_ts_over_60v_status,
			&r_feedbacks_airn_status,
			&r_feedbacks_airp_status,
			&r_feedbacks_airp_gate,
			&r_feedbacks_airn_gate,
			&r_feedbacks_precharge_status,
			&r_feedbacks_tsp_over_60v_status,
			&r_feedbacks_imd_fault,
			&r_feedbacks_check_mux,
			&r_feedbacks_sd_end,
			&r_feedbacks_sd_out,
			&r_feedbacks_sd_in,
			&r_feedbacks_sd_bms,
			&r_feedbacks_sd_imd,
			&r_errors_cell_low_voltage,
			&r_errors_cell_under_voltage,
			&r_errors_cell_over_voltage,
			&r_errors_cell_high_temperature,
			&r_errors_cell_over_temperature,
			&r_errors_over_current,
			&r_errors_can,
			&r_errors_int_voltage_mismatch,
			&r_errors_cellboard_comm,
			&r_errors_cellboard_internal,
			&r_errors_connector_disconnected,
			&r_errors_fans_disconnected,
			&r_errors_feedback,
			&r_errors_feedback_circuitry,
			&r_errors_eeprom_comm,
			&r_errors_eeprom_write);
		tmp_converted.feedbacks_implausibility_detected = (uint8_t)r_feedbacks_implausibility_detected;
		tmp_converted.feedbacks_imd_cockpit = (uint8_t)r_feedbacks_imd_cockpit;
		tmp_converted.feedbacks_tsal_green_fault_latched = (uint8_t)r_feedbacks_tsal_green_fault_latched;
		tmp_converted.feedbacks_bms_cockpit = (uint8_t)r_feedbacks_bms_cockpit;
		tmp_converted.feedbacks_ext_latched = (uint8_t)r_feedbacks_ext_latched;
		tmp_converted.feedbacks_tsal_green = (uint8_t)r_feedbacks_tsal_green;
		tmp_converted.feedbacks_ts_over_60v_status = (uint8_t)r_feedbacks_ts_over_60v_status;
		tmp_converted.feedbacks_airn_status = (uint8_t)r_feedbacks_airn_status;
		tmp_converted.feedbacks_airp_status = (uint8_t)r_feedbacks_airp_status;
		tmp_converted.feedbacks_airp_gate = (uint8_t)r_feedbacks_airp_gate;
		tmp_converted.feedbacks_airn_gate = (uint8_t)r_feedbacks_airn_gate;
		tmp_converted.feedbacks_precharge_status = (uint8_t)r_feedbacks_precharge_status;
		tmp_converted.feedbacks_tsp_over_60v_status = (uint8_t)r_feedbacks_tsp_over_60v_status;
		tmp_converted.feedbacks_imd_fault = (uint8_t)r_feedbacks_imd_fault;
		tmp_converted.feedbacks_check_mux = (uint8_t)r_feedbacks_check_mux;
		tmp_converted.feedbacks_sd_end = (uint8_t)r_feedbacks_sd_end;
		tmp_converted.feedbacks_sd_out = (uint8_t)r_feedbacks_sd_out;
		tmp_converted.feedbacks_sd_in = (uint8_t)r_feedbacks_sd_in;
		tmp_converted.feedbacks_sd_bms = (uint8_t)r_feedbacks_sd_bms;
		tmp_converted.feedbacks_sd_imd = (uint8_t)r_feedbacks_sd_imd;
		tmp_converted.errors_cell_low_voltage = (uint8_t)r_errors_cell_low_voltage;
		tmp_converted.errors_cell_under_voltage = (uint8_t)r_errors_cell_under_voltage;
		tmp_converted.errors_cell_over_voltage = (uint8_t)r_errors_cell_over_voltage;
		tmp_converted.errors_cell_high_temperature = (uint8_t)r_errors_cell_high_temperature;
		tmp_converted.errors_cell_over_temperature = (uint8_t)r_errors_cell_over_temperature;
		tmp_converted.errors_over_current = (uint8_t)r_errors_over_current;
		tmp_converted.errors_can = (uint8_t)r_errors_can;
		tmp_converted.errors_int_voltage_mismatch = (uint8_t)r_errors_int_voltage_mismatch;
		tmp_converted.errors_cellboard_comm = (uint8_t)r_errors_cellboard_comm;
		tmp_converted.errors_cellboard_internal = (uint8_t)r_errors_cellboard_internal;
		tmp_converted.errors_connector_disconnected = (uint8_t)r_errors_connector_disconnected;
		tmp_converted.errors_fans_disconnected = (uint8_t)r_errors_fans_disconnected;
		tmp_converted.errors_feedback = (uint8_t)r_errors_feedback;
		tmp_converted.errors_feedback_circuitry = (uint8_t)r_errors_feedback_circuitry;
		tmp_converted.errors_eeprom_comm = (uint8_t)r_errors_eeprom_comm;
		tmp_converted.errors_eeprom_write = (uint8_t)r_errors_eeprom_write;

		primary_hv_debug_signals_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_HV_DEBUG_SIGNALS_BYTE_SIZE;
		return primary_hv_debug_signals_pack(data, &tmp, PRIMARY_HV_DEBUG_SIGNALS_BYTE_SIZE);
	}
	case 1536:
	{
		primary_hv_fans_status_t tmp;
		primary_hv_fans_status_converted_t tmp_converted;
		uint8_t r_fans_override;
		float r_fans_speed;

		sscanf(s, "%" SCNu8 ","  
			"%f,"       ,
			&r_fans_override,
			&r_fans_speed);
		tmp_converted.fans_override = (primary_hv_fans_status_fans_override)r_fans_override;
		tmp_converted.fans_speed = (float)r_fans_speed;

		primary_hv_fans_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_HV_FANS_STATUS_BYTE_SIZE;
		return primary_hv_fans_status_pack(data, &tmp, PRIMARY_HV_FANS_STATUS_BYTE_SIZE);
	}
	case 1024:
	{
		primary_hv_set_fans_status_t tmp;
		primary_hv_set_fans_status_converted_t tmp_converted;
		uint8_t r_fans_override;
		float r_fans_speed;

		sscanf(s, "%" SCNu8 ","  
			"%f,"       ,
			&r_fans_override,
			&r_fans_speed);
		tmp_converted.fans_override = (primary_hv_set_fans_status_fans_override)r_fans_override;
		tmp_converted.fans_speed = (float)r_fans_speed;

		primary_hv_set_fans_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_HV_SET_FANS_STATUS_BYTE_SIZE;
		return primary_hv_set_fans_status_pack(data, &tmp, PRIMARY_HV_SET_FANS_STATUS_BYTE_SIZE);
	}
	case 520:
	{
		primary_hv_feedback_status_t tmp;
		primary_hv_feedback_status_converted_t tmp_converted;
		uint8_t r_feedbacks_implausibility_detected;
		uint8_t r_feedbacks_imd_cockpit;
		uint8_t r_feedbacks_tsal_green_fault_latched;
		uint8_t r_feedbacks_bms_cockpit;
		uint8_t r_feedbacks_ext_latched;
		uint8_t r_feedbacks_tsal_green;
		uint8_t r_feedbacks_ts_over_60v_status;
		uint8_t r_feedbacks_airn_status;
		uint8_t r_feedbacks_airp_status;
		uint8_t r_feedbacks_airp_gate;
		uint8_t r_feedbacks_airn_gate;
		uint8_t r_feedbacks_precharge_status;
		uint8_t r_feedbacks_tsp_over_60v_status;
		uint8_t r_feedbacks_imd_fault;
		uint8_t r_feedbacks_check_mux;
		uint8_t r_feedbacks_sd_end;
		uint8_t r_feedbacks_sd_out;
		uint8_t r_feedbacks_sd_in;
		uint8_t r_feedbacks_sd_bms;
		uint8_t r_feedbacks_sd_imd;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  ,
			&r_feedbacks_implausibility_detected,
			&r_feedbacks_imd_cockpit,
			&r_feedbacks_tsal_green_fault_latched,
			&r_feedbacks_bms_cockpit,
			&r_feedbacks_ext_latched,
			&r_feedbacks_tsal_green,
			&r_feedbacks_ts_over_60v_status,
			&r_feedbacks_airn_status,
			&r_feedbacks_airp_status,
			&r_feedbacks_airp_gate,
			&r_feedbacks_airn_gate,
			&r_feedbacks_precharge_status,
			&r_feedbacks_tsp_over_60v_status,
			&r_feedbacks_imd_fault,
			&r_feedbacks_check_mux,
			&r_feedbacks_sd_end,
			&r_feedbacks_sd_out,
			&r_feedbacks_sd_in,
			&r_feedbacks_sd_bms,
			&r_feedbacks_sd_imd);
		tmp_converted.feedbacks_implausibility_detected = (uint8_t)r_feedbacks_implausibility_detected;
		tmp_converted.feedbacks_imd_cockpit = (uint8_t)r_feedbacks_imd_cockpit;
		tmp_converted.feedbacks_tsal_green_fault_latched = (uint8_t)r_feedbacks_tsal_green_fault_latched;
		tmp_converted.feedbacks_bms_cockpit = (uint8_t)r_feedbacks_bms_cockpit;
		tmp_converted.feedbacks_ext_latched = (uint8_t)r_feedbacks_ext_latched;
		tmp_converted.feedbacks_tsal_green = (uint8_t)r_feedbacks_tsal_green;
		tmp_converted.feedbacks_ts_over_60v_status = (uint8_t)r_feedbacks_ts_over_60v_status;
		tmp_converted.feedbacks_airn_status = (uint8_t)r_feedbacks_airn_status;
		tmp_converted.feedbacks_airp_status = (uint8_t)r_feedbacks_airp_status;
		tmp_converted.feedbacks_airp_gate = (uint8_t)r_feedbacks_airp_gate;
		tmp_converted.feedbacks_airn_gate = (uint8_t)r_feedbacks_airn_gate;
		tmp_converted.feedbacks_precharge_status = (uint8_t)r_feedbacks_precharge_status;
		tmp_converted.feedbacks_tsp_over_60v_status = (uint8_t)r_feedbacks_tsp_over_60v_status;
		tmp_converted.feedbacks_imd_fault = (uint8_t)r_feedbacks_imd_fault;
		tmp_converted.feedbacks_check_mux = (uint8_t)r_feedbacks_check_mux;
		tmp_converted.feedbacks_sd_end = (uint8_t)r_feedbacks_sd_end;
		tmp_converted.feedbacks_sd_out = (uint8_t)r_feedbacks_sd_out;
		tmp_converted.feedbacks_sd_in = (uint8_t)r_feedbacks_sd_in;
		tmp_converted.feedbacks_sd_bms = (uint8_t)r_feedbacks_sd_bms;
		tmp_converted.feedbacks_sd_imd = (uint8_t)r_feedbacks_sd_imd;

		primary_hv_feedback_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_HV_FEEDBACK_STATUS_BYTE_SIZE;
		return primary_hv_feedback_status_pack(data, &tmp, PRIMARY_HV_FEEDBACK_STATUS_BYTE_SIZE);
	}
	case 528:
	{
		primary_hv_feedback_ts_voltage_t tmp;
		primary_hv_feedback_ts_voltage_converted_t tmp_converted;
		float r_ts_over_60v_status;
		float r_airn_status;
		float r_airp_status;
		float r_airp_gate;
		float r_airn_gate;
		float r_precharge_status;
		float r_tsp_over_60v_status;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       
			"%f,"       
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_ts_over_60v_status,
			&r_airn_status,
			&r_airp_status,
			&r_airp_gate,
			&r_airn_gate,
			&r_precharge_status,
			&r_tsp_over_60v_status);
		tmp_converted.ts_over_60v_status = (float)r_ts_over_60v_status;
		tmp_converted.airn_status = (float)r_airn_status;
		tmp_converted.airp_status = (float)r_airp_status;
		tmp_converted.airp_gate = (float)r_airp_gate;
		tmp_converted.airn_gate = (float)r_airn_gate;
		tmp_converted.precharge_status = (float)r_precharge_status;
		tmp_converted.tsp_over_60v_status = (float)r_tsp_over_60v_status;

		primary_hv_feedback_ts_voltage_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_HV_FEEDBACK_TS_VOLTAGE_BYTE_SIZE;
		return primary_hv_feedback_ts_voltage_pack(data, &tmp, PRIMARY_HV_FEEDBACK_TS_VOLTAGE_BYTE_SIZE);
	}
	case 536:
	{
		primary_hv_feedback_misc_voltage_t tmp;
		primary_hv_feedback_misc_voltage_converted_t tmp_converted;
		uint32_t r_implausibility_detected;
		uint32_t r_imd_cockpit;
		uint32_t r_tsal_green_fault_latched;
		uint32_t r_bms_cockpit;
		uint32_t r_ext_latched;
		uint32_t r_tsal_green;
		uint32_t r_imd_fault;
		uint32_t r_check_mux;

		sscanf(s, "%" SCNu32 "," 
			"%" SCNu32 "," 
			"%" SCNu32 "," 
			"%" SCNu32 "," 
			"%" SCNu32 "," 
			"%" SCNu32 "," 
			"%" SCNu32 "," 
			"%" SCNu32 "," ,
			&r_implausibility_detected,
			&r_imd_cockpit,
			&r_tsal_green_fault_latched,
			&r_bms_cockpit,
			&r_ext_latched,
			&r_tsal_green,
			&r_imd_fault,
			&r_check_mux);
		tmp_converted.implausibility_detected = (uint32_t)r_implausibility_detected;
		tmp_converted.imd_cockpit = (uint32_t)r_imd_cockpit;
		tmp_converted.tsal_green_fault_latched = (uint32_t)r_tsal_green_fault_latched;
		tmp_converted.bms_cockpit = (uint32_t)r_bms_cockpit;
		tmp_converted.ext_latched = (uint32_t)r_ext_latched;
		tmp_converted.tsal_green = (uint32_t)r_tsal_green;
		tmp_converted.imd_fault = (uint32_t)r_imd_fault;
		tmp_converted.check_mux = (uint32_t)r_check_mux;

		primary_hv_feedback_misc_voltage_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_HV_FEEDBACK_MISC_VOLTAGE_BYTE_SIZE;
		return primary_hv_feedback_misc_voltage_pack(data, &tmp, PRIMARY_HV_FEEDBACK_MISC_VOLTAGE_BYTE_SIZE);
	}
	case 544:
	{
		primary_hv_feedback_sd_voltage_t tmp;
		primary_hv_feedback_sd_voltage_converted_t tmp_converted;
		uint32_t r_sd_end;
		uint32_t r_sd_out;
		uint32_t r_sd_in;
		uint32_t r_sd_bms;
		uint32_t r_sd_imd;

		sscanf(s, "%" SCNu32 "," 
			"%" SCNu32 "," 
			"%" SCNu32 "," 
			"%" SCNu32 "," 
			"%" SCNu32 "," ,
			&r_sd_end,
			&r_sd_out,
			&r_sd_in,
			&r_sd_bms,
			&r_sd_imd);
		tmp_converted.sd_end = (uint32_t)r_sd_end;
		tmp_converted.sd_out = (uint32_t)r_sd_out;
		tmp_converted.sd_in = (uint32_t)r_sd_in;
		tmp_converted.sd_bms = (uint32_t)r_sd_bms;
		tmp_converted.sd_imd = (uint32_t)r_sd_imd;

		primary_hv_feedback_sd_voltage_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_HV_FEEDBACK_SD_VOLTAGE_BYTE_SIZE;
		return primary_hv_feedback_sd_voltage_pack(data, &tmp, PRIMARY_HV_FEEDBACK_SD_VOLTAGE_BYTE_SIZE);
	}
	case 552:
	{
		primary_hv_imd_status_t tmp;
		primary_hv_imd_status_converted_t tmp_converted;
		uint32_t r_imd_fault;
		uint32_t r_imd_status;
		uint32_t r_imd_details;
		uint32_t r_imd_duty_cycle;
		uint32_t r_imd_freq;
		uint32_t r_imd_period;

		sscanf(s, "%" SCNu32 "," 
			"%" SCNu32 "," 
			"%" SCNu32 "," 
			"%" SCNu32 "," 
			"%" SCNu32 "," 
			"%" SCNu32 "," ,
			&r_imd_fault,
			&r_imd_status,
			&r_imd_details,
			&r_imd_duty_cycle,
			&r_imd_freq,
			&r_imd_period);
		tmp_converted.imd_fault = (uint32_t)r_imd_fault;
		tmp_converted.imd_status = (uint32_t)r_imd_status;
		tmp_converted.imd_details = (uint32_t)r_imd_details;
		tmp_converted.imd_duty_cycle = (uint32_t)r_imd_duty_cycle;
		tmp_converted.imd_freq = (uint32_t)r_imd_freq;
		tmp_converted.imd_period = (uint32_t)r_imd_period;

		primary_hv_imd_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_HV_IMD_STATUS_BYTE_SIZE;
		return primary_hv_imd_status_pack(data, &tmp, PRIMARY_HV_IMD_STATUS_BYTE_SIZE);
	}
	case 560:
	{
		primary_hv_status_t tmp;
		primary_hv_status_converted_t tmp_converted;
		uint8_t r_status;

		sscanf(s, "%" SCNu8 ","  ,
			&r_status);
		tmp_converted.status = (primary_hv_status_status)r_status;

		primary_hv_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_HV_STATUS_BYTE_SIZE;
		return primary_hv_status_pack(data, &tmp, PRIMARY_HV_STATUS_BYTE_SIZE);
	}
	case 32:
	{
		primary_hv_set_status_ecu_t tmp;
		primary_hv_set_status_ecu_converted_t tmp_converted;
		uint8_t r_hv_status_set;

		sscanf(s, "%" SCNu8 ","  ,
			&r_hv_status_set);
		tmp_converted.hv_status_set = (primary_hv_set_status_ecu_hv_status_set)r_hv_status_set;

		primary_hv_set_status_ecu_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_HV_SET_STATUS_ECU_BYTE_SIZE;
		return primary_hv_set_status_ecu_pack(data, &tmp, PRIMARY_HV_SET_STATUS_ECU_BYTE_SIZE);
	}
	case 40:
	{
		primary_hv_set_status_handcart_t tmp;
		primary_hv_set_status_handcart_converted_t tmp_converted;
		uint8_t r_hv_status_set;

		sscanf(s, "%" SCNu8 ","  ,
			&r_hv_status_set);
		tmp_converted.hv_status_set = (primary_hv_set_status_handcart_hv_status_set)r_hv_status_set;

		primary_hv_set_status_handcart_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_HV_SET_STATUS_HANDCART_BYTE_SIZE;
		return primary_hv_set_status_handcart_pack(data, &tmp, PRIMARY_HV_SET_STATUS_HANDCART_BYTE_SIZE);
	}
	case 1544:
	{
		primary_hv_balancing_status_t tmp;
		primary_hv_balancing_status_converted_t tmp_converted;
		uint8_t r_cellboard_id;
		uint8_t r_balancing_status;
		uint8_t r_errors_can_comm;
		uint8_t r_errors_ltc_comm;
		uint8_t r_errors_temp_comm_0;
		uint8_t r_errors_temp_comm_1;
		uint8_t r_errors_temp_comm_2;
		uint8_t r_errors_temp_comm_3;
		uint8_t r_errors_temp_comm_4;
		uint8_t r_errors_temp_comm_5;
		uint8_t r_errors_open_wire;
		uint8_t r_balancing_cells_cell0;
		uint8_t r_balancing_cells_cell1;
		uint8_t r_balancing_cells_cell2;
		uint8_t r_balancing_cells_cell3;
		uint8_t r_balancing_cells_cell4;
		uint8_t r_balancing_cells_cell5;
		uint8_t r_balancing_cells_cell6;
		uint8_t r_balancing_cells_cell7;
		uint8_t r_balancing_cells_cell8;
		uint8_t r_balancing_cells_cell9;
		uint8_t r_balancing_cells_cell10;
		uint8_t r_balancing_cells_cell11;
		uint8_t r_balancing_cells_cell12;
		uint8_t r_balancing_cells_cell13;
		uint8_t r_balancing_cells_cell14;
		uint8_t r_balancing_cells_cell15;
		uint8_t r_balancing_cells_cell16;
		uint8_t r_balancing_cells_cell17;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  ,
			&r_cellboard_id,
			&r_balancing_status,
			&r_errors_can_comm,
			&r_errors_ltc_comm,
			&r_errors_temp_comm_0,
			&r_errors_temp_comm_1,
			&r_errors_temp_comm_2,
			&r_errors_temp_comm_3,
			&r_errors_temp_comm_4,
			&r_errors_temp_comm_5,
			&r_errors_open_wire,
			&r_balancing_cells_cell0,
			&r_balancing_cells_cell1,
			&r_balancing_cells_cell2,
			&r_balancing_cells_cell3,
			&r_balancing_cells_cell4,
			&r_balancing_cells_cell5,
			&r_balancing_cells_cell6,
			&r_balancing_cells_cell7,
			&r_balancing_cells_cell8,
			&r_balancing_cells_cell9,
			&r_balancing_cells_cell10,
			&r_balancing_cells_cell11,
			&r_balancing_cells_cell12,
			&r_balancing_cells_cell13,
			&r_balancing_cells_cell14,
			&r_balancing_cells_cell15,
			&r_balancing_cells_cell16,
			&r_balancing_cells_cell17);
		tmp_converted.cellboard_id = (primary_hv_balancing_status_cellboard_id)r_cellboard_id;
		tmp_converted.balancing_status = (primary_hv_balancing_status_balancing_status)r_balancing_status;
		tmp_converted.errors_can_comm = (uint8_t)r_errors_can_comm;
		tmp_converted.errors_ltc_comm = (uint8_t)r_errors_ltc_comm;
		tmp_converted.errors_temp_comm_0 = (uint8_t)r_errors_temp_comm_0;
		tmp_converted.errors_temp_comm_1 = (uint8_t)r_errors_temp_comm_1;
		tmp_converted.errors_temp_comm_2 = (uint8_t)r_errors_temp_comm_2;
		tmp_converted.errors_temp_comm_3 = (uint8_t)r_errors_temp_comm_3;
		tmp_converted.errors_temp_comm_4 = (uint8_t)r_errors_temp_comm_4;
		tmp_converted.errors_temp_comm_5 = (uint8_t)r_errors_temp_comm_5;
		tmp_converted.errors_open_wire = (uint8_t)r_errors_open_wire;
		tmp_converted.balancing_cells_cell0 = (uint8_t)r_balancing_cells_cell0;
		tmp_converted.balancing_cells_cell1 = (uint8_t)r_balancing_cells_cell1;
		tmp_converted.balancing_cells_cell2 = (uint8_t)r_balancing_cells_cell2;
		tmp_converted.balancing_cells_cell3 = (uint8_t)r_balancing_cells_cell3;
		tmp_converted.balancing_cells_cell4 = (uint8_t)r_balancing_cells_cell4;
		tmp_converted.balancing_cells_cell5 = (uint8_t)r_balancing_cells_cell5;
		tmp_converted.balancing_cells_cell6 = (uint8_t)r_balancing_cells_cell6;
		tmp_converted.balancing_cells_cell7 = (uint8_t)r_balancing_cells_cell7;
		tmp_converted.balancing_cells_cell8 = (uint8_t)r_balancing_cells_cell8;
		tmp_converted.balancing_cells_cell9 = (uint8_t)r_balancing_cells_cell9;
		tmp_converted.balancing_cells_cell10 = (uint8_t)r_balancing_cells_cell10;
		tmp_converted.balancing_cells_cell11 = (uint8_t)r_balancing_cells_cell11;
		tmp_converted.balancing_cells_cell12 = (uint8_t)r_balancing_cells_cell12;
		tmp_converted.balancing_cells_cell13 = (uint8_t)r_balancing_cells_cell13;
		tmp_converted.balancing_cells_cell14 = (uint8_t)r_balancing_cells_cell14;
		tmp_converted.balancing_cells_cell15 = (uint8_t)r_balancing_cells_cell15;
		tmp_converted.balancing_cells_cell16 = (uint8_t)r_balancing_cells_cell16;
		tmp_converted.balancing_cells_cell17 = (uint8_t)r_balancing_cells_cell17;

		primary_hv_balancing_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_HV_BALANCING_STATUS_BYTE_SIZE;
		return primary_hv_balancing_status_pack(data, &tmp, PRIMARY_HV_BALANCING_STATUS_BYTE_SIZE);
	}
	case 1032:
	{
		primary_hv_set_balancing_status_t tmp;
		primary_hv_set_balancing_status_converted_t tmp_converted;
		uint8_t r_set_balancing_status;
		uint8_t r_balancing_threshold;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  ,
			&r_set_balancing_status,
			&r_balancing_threshold);
		tmp_converted.set_balancing_status = (primary_hv_set_balancing_status_set_balancing_status)r_set_balancing_status;
		tmp_converted.balancing_threshold = (uint8_t)r_balancing_threshold;

		primary_hv_set_balancing_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_HV_SET_BALANCING_STATUS_BYTE_SIZE;
		return primary_hv_set_balancing_status_pack(data, &tmp, PRIMARY_HV_SET_BALANCING_STATUS_BYTE_SIZE);
	}
	case 568:
	{
		primary_lv_status_t tmp;
		primary_lv_status_converted_t tmp_converted;
		uint8_t r_status;

		sscanf(s, "%" SCNu8 ","  ,
			&r_status);
		tmp_converted.status = (primary_lv_status_status)r_status;

		primary_lv_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_LV_STATUS_BYTE_SIZE;
		return primary_lv_status_pack(data, &tmp, PRIMARY_LV_STATUS_BYTE_SIZE);
	}
	case 1568:
	{
		primary_lv_radiator_speed_t tmp;
		primary_lv_radiator_speed_converted_t tmp_converted;
		float r_radiator_speed;

		sscanf(s, "%f,"       ,
			&r_radiator_speed);
		tmp_converted.radiator_speed = (float)r_radiator_speed;

		primary_lv_radiator_speed_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_LV_RADIATOR_SPEED_BYTE_SIZE;
		return primary_lv_radiator_speed_pack(data, &tmp, PRIMARY_LV_RADIATOR_SPEED_BYTE_SIZE);
	}
	case 1576:
	{
		primary_lv_pumps_speed_t tmp;
		primary_lv_pumps_speed_converted_t tmp_converted;
		float r_pumps_speed;

		sscanf(s, "%f,"       ,
			&r_pumps_speed);
		tmp_converted.pumps_speed = (float)r_pumps_speed;

		primary_lv_pumps_speed_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_LV_PUMPS_SPEED_BYTE_SIZE;
		return primary_lv_pumps_speed_pack(data, &tmp, PRIMARY_LV_PUMPS_SPEED_BYTE_SIZE);
	}
	case 1040:
	{
		primary_lv_set_radiator_speed_t tmp;
		primary_lv_set_radiator_speed_converted_t tmp_converted;
		float r_radiator_speed;

		sscanf(s, "%f,"       ,
			&r_radiator_speed);
		tmp_converted.radiator_speed = (float)r_radiator_speed;

		primary_lv_set_radiator_speed_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_LV_SET_RADIATOR_SPEED_BYTE_SIZE;
		return primary_lv_set_radiator_speed_pack(data, &tmp, PRIMARY_LV_SET_RADIATOR_SPEED_BYTE_SIZE);
	}
	case 1048:
	{
		primary_lv_set_pumps_speed_t tmp;
		primary_lv_set_pumps_speed_converted_t tmp_converted;
		float r_pumps_speed;

		sscanf(s, "%f,"       ,
			&r_pumps_speed);
		tmp_converted.pumps_speed = (float)r_pumps_speed;

		primary_lv_set_pumps_speed_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_LV_SET_PUMPS_SPEED_BYTE_SIZE;
		return primary_lv_set_pumps_speed_pack(data, &tmp, PRIMARY_LV_SET_PUMPS_SPEED_BYTE_SIZE);
	}
	case 576:
	{
		primary_lv_errors_t tmp;
		primary_lv_errors_converted_t tmp_converted;
		uint8_t r_errors_cell_undervoltage;
		uint8_t r_errors_cell_overvoltage;
		uint8_t r_errors_battery_open_wire;
		uint8_t r_errors_can;
		uint8_t r_errors_spi;
		uint8_t r_errors_over_current;
		uint8_t r_errors_cell_under_temperature;
		uint8_t r_errors_cell_over_temperature;
		uint8_t r_errors_relay;
		uint8_t r_errors_bms_monitor;
		uint8_t r_errors_voltages_not_ready;
		uint8_t r_errors_mcp23017;
		uint8_t r_errors_radiator;
		uint8_t r_errors_fan;
		uint8_t r_errors_pump;
		uint8_t r_errors_adc_init;
		uint8_t r_errors_mux;
		uint8_t r_health_signals_lvms_out;
		uint8_t r_health_signals_relay_out;
		uint8_t r_health_signals_battery_voltage_out;
		uint8_t r_health_signals_charger_current;
		uint8_t r_health_signals_battery_current;
		uint8_t r_health_signals_sign_battery_current;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  ,
			&r_errors_cell_undervoltage,
			&r_errors_cell_overvoltage,
			&r_errors_battery_open_wire,
			&r_errors_can,
			&r_errors_spi,
			&r_errors_over_current,
			&r_errors_cell_under_temperature,
			&r_errors_cell_over_temperature,
			&r_errors_relay,
			&r_errors_bms_monitor,
			&r_errors_voltages_not_ready,
			&r_errors_mcp23017,
			&r_errors_radiator,
			&r_errors_fan,
			&r_errors_pump,
			&r_errors_adc_init,
			&r_errors_mux,
			&r_health_signals_lvms_out,
			&r_health_signals_relay_out,
			&r_health_signals_battery_voltage_out,
			&r_health_signals_charger_current,
			&r_health_signals_battery_current,
			&r_health_signals_sign_battery_current);
		tmp_converted.errors_cell_undervoltage = (uint8_t)r_errors_cell_undervoltage;
		tmp_converted.errors_cell_overvoltage = (uint8_t)r_errors_cell_overvoltage;
		tmp_converted.errors_battery_open_wire = (uint8_t)r_errors_battery_open_wire;
		tmp_converted.errors_can = (uint8_t)r_errors_can;
		tmp_converted.errors_spi = (uint8_t)r_errors_spi;
		tmp_converted.errors_over_current = (uint8_t)r_errors_over_current;
		tmp_converted.errors_cell_under_temperature = (uint8_t)r_errors_cell_under_temperature;
		tmp_converted.errors_cell_over_temperature = (uint8_t)r_errors_cell_over_temperature;
		tmp_converted.errors_relay = (uint8_t)r_errors_relay;
		tmp_converted.errors_bms_monitor = (uint8_t)r_errors_bms_monitor;
		tmp_converted.errors_voltages_not_ready = (uint8_t)r_errors_voltages_not_ready;
		tmp_converted.errors_mcp23017 = (uint8_t)r_errors_mcp23017;
		tmp_converted.errors_radiator = (uint8_t)r_errors_radiator;
		tmp_converted.errors_fan = (uint8_t)r_errors_fan;
		tmp_converted.errors_pump = (uint8_t)r_errors_pump;
		tmp_converted.errors_adc_init = (uint8_t)r_errors_adc_init;
		tmp_converted.errors_mux = (uint8_t)r_errors_mux;
		tmp_converted.health_signals_lvms_out = (uint8_t)r_health_signals_lvms_out;
		tmp_converted.health_signals_relay_out = (uint8_t)r_health_signals_relay_out;
		tmp_converted.health_signals_battery_voltage_out = (uint8_t)r_health_signals_battery_voltage_out;
		tmp_converted.health_signals_charger_current = (uint8_t)r_health_signals_charger_current;
		tmp_converted.health_signals_battery_current = (uint8_t)r_health_signals_battery_current;
		tmp_converted.health_signals_sign_battery_current = (uint8_t)r_health_signals_sign_battery_current;

		primary_lv_errors_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_LV_ERRORS_BYTE_SIZE;
		return primary_lv_errors_pack(data, &tmp, PRIMARY_LV_ERRORS_BYTE_SIZE);
	}
	case 584:
	{
		primary_lv_feedback_ts_voltage_t tmp;
		primary_lv_feedback_ts_voltage_converted_t tmp_converted;
		float r_bspd;
		float r_hvd;
		float r_invc_interlock;
		float r_ams;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_bspd,
			&r_hvd,
			&r_invc_interlock,
			&r_ams);
		tmp_converted.bspd = (float)r_bspd;
		tmp_converted.hvd = (float)r_hvd;
		tmp_converted.invc_interlock = (float)r_invc_interlock;
		tmp_converted.ams = (float)r_ams;

		primary_lv_feedback_ts_voltage_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_LV_FEEDBACK_TS_VOLTAGE_BYTE_SIZE;
		return primary_lv_feedback_ts_voltage_pack(data, &tmp, PRIMARY_LV_FEEDBACK_TS_VOLTAGE_BYTE_SIZE);
	}
	case 592:
	{
		primary_lv_feedback_sd_voltage_t tmp;
		primary_lv_feedback_sd_voltage_converted_t tmp_converted;
		float r_sd_end;
		float r_lvms;
		float r_interlock;
		float r_sd_start;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_sd_end,
			&r_lvms,
			&r_interlock,
			&r_sd_start);
		tmp_converted.sd_end = (float)r_sd_end;
		tmp_converted.lvms = (float)r_lvms;
		tmp_converted.interlock = (float)r_interlock;
		tmp_converted.sd_start = (float)r_sd_start;

		primary_lv_feedback_sd_voltage_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_LV_FEEDBACK_SD_VOLTAGE_BYTE_SIZE;
		return primary_lv_feedback_sd_voltage_pack(data, &tmp, PRIMARY_LV_FEEDBACK_SD_VOLTAGE_BYTE_SIZE);
	}
	case 600:
	{
		primary_lv_feedback_enclosure_voltage_t tmp;
		primary_lv_feedback_enclosure_voltage_converted_t tmp_converted;
		float r_lv_encl;
		float r_invc_lid;
		float r_hv_encl_2;
		float r_backplate;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_lv_encl,
			&r_invc_lid,
			&r_hv_encl_2,
			&r_backplate);
		tmp_converted.lv_encl = (float)r_lv_encl;
		tmp_converted.invc_lid = (float)r_invc_lid;
		tmp_converted.hv_encl_2 = (float)r_hv_encl_2;
		tmp_converted.backplate = (float)r_backplate;

		primary_lv_feedback_enclosure_voltage_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_LV_FEEDBACK_ENCLOSURE_VOLTAGE_BYTE_SIZE;
		return primary_lv_feedback_enclosure_voltage_pack(data, &tmp, PRIMARY_LV_FEEDBACK_ENCLOSURE_VOLTAGE_BYTE_SIZE);
	}
	case 608:
	{
		primary_lv_feedback_gpio_extender_t tmp;
		primary_lv_feedback_gpio_extender_converted_t tmp_converted;
		uint8_t r_feedback_inverters;
		uint8_t r_feedback_pcbs;
		uint8_t r_feedback_pumps;
		uint8_t r_feedback_radiators;
		uint8_t r_feedback_shutdown;
		uint8_t r_feedback_hv_fans;
		uint8_t r_feedback_autonomous_system_actuation;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  ,
			&r_feedback_inverters,
			&r_feedback_pcbs,
			&r_feedback_pumps,
			&r_feedback_radiators,
			&r_feedback_shutdown,
			&r_feedback_hv_fans,
			&r_feedback_autonomous_system_actuation);
		tmp_converted.feedback_inverters = (uint8_t)r_feedback_inverters;
		tmp_converted.feedback_pcbs = (uint8_t)r_feedback_pcbs;
		tmp_converted.feedback_pumps = (uint8_t)r_feedback_pumps;
		tmp_converted.feedback_radiators = (uint8_t)r_feedback_radiators;
		tmp_converted.feedback_shutdown = (uint8_t)r_feedback_shutdown;
		tmp_converted.feedback_hv_fans = (uint8_t)r_feedback_hv_fans;
		tmp_converted.feedback_autonomous_system_actuation = (uint8_t)r_feedback_autonomous_system_actuation;

		primary_lv_feedback_gpio_extender_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_LV_FEEDBACK_GPIO_EXTENDER_BYTE_SIZE;
		return primary_lv_feedback_gpio_extender_pack(data, &tmp, PRIMARY_LV_FEEDBACK_GPIO_EXTENDER_BYTE_SIZE);
	}
	case 616:
	{
		primary_lv_inverter_connection_status_t tmp;
		primary_lv_inverter_connection_status_converted_t tmp_converted;
		uint8_t r_status;

		sscanf(s, "%" SCNu8 ","  ,
			&r_status);
		tmp_converted.status = (primary_lv_inverter_connection_status_status)r_status;

		primary_lv_inverter_connection_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_LV_INVERTER_CONNECTION_STATUS_BYTE_SIZE;
		return primary_lv_inverter_connection_status_pack(data, &tmp, PRIMARY_LV_INVERTER_CONNECTION_STATUS_BYTE_SIZE);
	}
	case 64:
	{
		primary_lv_set_inverter_connection_status_t tmp;
		primary_lv_set_inverter_connection_status_converted_t tmp_converted;
		uint8_t r_status;

		sscanf(s, "%" SCNu8 ","  ,
			&r_status);
		tmp_converted.status = (primary_lv_set_inverter_connection_status_status)r_status;

		primary_lv_set_inverter_connection_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_LV_SET_INVERTER_CONNECTION_STATUS_BYTE_SIZE;
		return primary_lv_set_inverter_connection_status_pack(data, &tmp, PRIMARY_LV_SET_INVERTER_CONNECTION_STATUS_BYTE_SIZE);
	}
	case 1584:
	{
		primary_tlm_status_t tmp;
		primary_tlm_status_converted_t tmp_converted;
		uint8_t r_status;

		sscanf(s, "%" SCNu8 ","  ,
			&r_status);
		tmp_converted.status = (primary_tlm_status_status)r_status;

		primary_tlm_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_TLM_STATUS_BYTE_SIZE;
		return primary_tlm_status_pack(data, &tmp, PRIMARY_TLM_STATUS_BYTE_SIZE);
	}
	case 1056:
	{
		primary_tlm_set_status_t tmp;
		primary_tlm_set_status_converted_t tmp_converted;
		uint8_t r_status;

		sscanf(s, "%" SCNu8 ","  ,
			&r_status);
		tmp_converted.status = (primary_tlm_set_status_status)r_status;

		primary_tlm_set_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_TLM_SET_STATUS_BYTE_SIZE;
		return primary_tlm_set_status_pack(data, &tmp, PRIMARY_TLM_SET_STATUS_BYTE_SIZE);
	}
	case 624:
	{
		primary_handcart_status_t tmp;
		primary_handcart_status_converted_t tmp_converted;
		uint8_t r_connected;

		sscanf(s, "%" SCNu8 ","  ,
			&r_connected);
		tmp_converted.connected = (primary_handcart_status_connected)r_connected;

		primary_handcart_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_HANDCART_STATUS_BYTE_SIZE;
		return primary_handcart_status_pack(data, &tmp, PRIMARY_HANDCART_STATUS_BYTE_SIZE);
	}
	case 1592:
	{
		primary_handcart_settings_t tmp;
		primary_handcart_settings_converted_t tmp_converted;
		float r_target_voltage;
		uint8_t r_fans_override;
		float r_fans_speed;
		float r_acc_charge_current;
		float r_grid_max_current;
		uint8_t r_status;

		sscanf(s, "%f,"       
			"%" SCNu8 ","  
			"%f,"       
			"%f,"       
			"%f,"       
			"%" SCNu8 ","  ,
			&r_target_voltage,
			&r_fans_override,
			&r_fans_speed,
			&r_acc_charge_current,
			&r_grid_max_current,
			&r_status);
		tmp_converted.target_voltage = (float)r_target_voltage;
		tmp_converted.fans_override = (primary_handcart_settings_fans_override)r_fans_override;
		tmp_converted.fans_speed = (float)r_fans_speed;
		tmp_converted.acc_charge_current = (float)r_acc_charge_current;
		tmp_converted.grid_max_current = (float)r_grid_max_current;
		tmp_converted.status = (primary_handcart_settings_status)r_status;

		primary_handcart_settings_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_HANDCART_SETTINGS_BYTE_SIZE;
		return primary_handcart_settings_pack(data, &tmp, PRIMARY_HANDCART_SETTINGS_BYTE_SIZE);
	}
	case 1064:
	{
		primary_handcart_set_settings_t tmp;
		primary_handcart_set_settings_converted_t tmp_converted;
		float r_target_voltage;
		uint8_t r_fans_override;
		float r_fans_speed;
		float r_acc_charge_current;
		float r_grid_max_current;
		uint8_t r_status;

		sscanf(s, "%f,"       
			"%" SCNu8 ","  
			"%f,"       
			"%f,"       
			"%f,"       
			"%" SCNu8 ","  ,
			&r_target_voltage,
			&r_fans_override,
			&r_fans_speed,
			&r_acc_charge_current,
			&r_grid_max_current,
			&r_status);
		tmp_converted.target_voltage = (float)r_target_voltage;
		tmp_converted.fans_override = (primary_handcart_set_settings_fans_override)r_fans_override;
		tmp_converted.fans_speed = (float)r_fans_speed;
		tmp_converted.acc_charge_current = (float)r_acc_charge_current;
		tmp_converted.grid_max_current = (float)r_grid_max_current;
		tmp_converted.status = (primary_handcart_set_settings_status)r_status;

		primary_handcart_set_settings_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_HANDCART_SET_SETTINGS_BYTE_SIZE;
		return primary_handcart_set_settings_pack(data, &tmp, PRIMARY_HANDCART_SET_SETTINGS_BYTE_SIZE);
	}
	case 632:
	{
		primary_ecu_status_t tmp;
		primary_ecu_status_converted_t tmp_converted;
		uint8_t r_status;

		sscanf(s, "%" SCNu8 ","  ,
			&r_status);
		tmp_converted.status = (primary_ecu_status_status)r_status;

		primary_ecu_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_ECU_STATUS_BYTE_SIZE;
		return primary_ecu_status_pack(data, &tmp, PRIMARY_ECU_STATUS_BYTE_SIZE);
	}
	case 72:
	{
		primary_ecu_set_status_t tmp;
		primary_ecu_set_status_converted_t tmp_converted;
		uint8_t r_status;

		sscanf(s, "%" SCNu8 ","  ,
			&r_status);
		tmp_converted.status = (primary_ecu_set_status_status)r_status;

		primary_ecu_set_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_ECU_SET_STATUS_BYTE_SIZE;
		return primary_ecu_set_status_pack(data, &tmp, PRIMARY_ECU_SET_STATUS_BYTE_SIZE);
	}
	case 1072:
	{
		primary_ecu_inverter_status_t tmp;
		primary_ecu_inverter_status_converted_t tmp_converted;
		uint8_t r_rl;
		uint8_t r_rr;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  ,
			&r_rl,
			&r_rr);
		tmp_converted.rl = (primary_ecu_inverter_status_rl)r_rl;
		tmp_converted.rr = (primary_ecu_inverter_status_rr)r_rr;

		primary_ecu_inverter_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_ECU_INVERTER_STATUS_BYTE_SIZE;
		return primary_ecu_inverter_status_pack(data, &tmp, PRIMARY_ECU_INVERTER_STATUS_BYTE_SIZE);
	}
	case 640:
	{
		primary_ecu_control_status_t tmp;
		primary_ecu_control_status_converted_t tmp_converted;
		uint8_t r_control_enabled;
		uint8_t r_control_errors_forced_off;
		uint8_t r_control_errors_wrong_maps;
		uint8_t r_control_errors_control_watchdog;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  ,
			&r_control_enabled,
			&r_control_errors_forced_off,
			&r_control_errors_wrong_maps,
			&r_control_errors_control_watchdog);
		tmp_converted.control_enabled = (uint8_t)r_control_enabled;
		tmp_converted.control_errors_forced_off = (uint8_t)r_control_errors_forced_off;
		tmp_converted.control_errors_wrong_maps = (uint8_t)r_control_errors_wrong_maps;
		tmp_converted.control_errors_control_watchdog = (uint8_t)r_control_errors_control_watchdog;

		primary_ecu_control_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_ECU_CONTROL_STATUS_BYTE_SIZE;
		return primary_ecu_control_status_pack(data, &tmp, PRIMARY_ECU_CONTROL_STATUS_BYTE_SIZE);
	}
	case 648:
	{
		primary_ecu_errors_t tmp;
		primary_ecu_errors_converted_t tmp_converted;
		uint8_t r_error_pedal_adc;
		uint8_t r_error_pedal_implausibility;
		uint8_t r_error_imu_tout;
		uint8_t r_error_irts_tout;
		uint8_t r_error_ts_tout;
		uint8_t r_error_invl_tout;
		uint8_t r_error_invr_tout;
		uint8_t r_error_steer_tout;
		uint8_t r_error_fsm;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  ,
			&r_error_pedal_adc,
			&r_error_pedal_implausibility,
			&r_error_imu_tout,
			&r_error_irts_tout,
			&r_error_ts_tout,
			&r_error_invl_tout,
			&r_error_invr_tout,
			&r_error_steer_tout,
			&r_error_fsm);
		tmp_converted.error_pedal_adc = (uint8_t)r_error_pedal_adc;
		tmp_converted.error_pedal_implausibility = (uint8_t)r_error_pedal_implausibility;
		tmp_converted.error_imu_tout = (uint8_t)r_error_imu_tout;
		tmp_converted.error_irts_tout = (uint8_t)r_error_irts_tout;
		tmp_converted.error_ts_tout = (uint8_t)r_error_ts_tout;
		tmp_converted.error_invl_tout = (uint8_t)r_error_invl_tout;
		tmp_converted.error_invr_tout = (uint8_t)r_error_invr_tout;
		tmp_converted.error_steer_tout = (uint8_t)r_error_steer_tout;
		tmp_converted.error_fsm = (uint8_t)r_error_fsm;

		primary_ecu_errors_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_ECU_ERRORS_BYTE_SIZE;
		return primary_ecu_errors_pack(data, &tmp, PRIMARY_ECU_ERRORS_BYTE_SIZE);
	}
	case 656:
	{
		primary_ecu_feedbacks_t tmp;
		primary_ecu_feedbacks_converted_t tmp_converted;
		uint8_t r_feedbacks_sd_cock_fb;
		uint8_t r_feedbacks_sd_fb1;
		uint8_t r_feedbacks_sd_bots_fb;
		uint8_t r_feedbacks_sd_interial_fb;
		uint8_t r_feedbacks_sd_fb4;
		uint8_t r_feedbacks_sd_in;
		uint8_t r_feedbacks_sd_out;
		uint8_t r_feedbacks_sd_ctrl_pin;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  ,
			&r_feedbacks_sd_cock_fb,
			&r_feedbacks_sd_fb1,
			&r_feedbacks_sd_bots_fb,
			&r_feedbacks_sd_interial_fb,
			&r_feedbacks_sd_fb4,
			&r_feedbacks_sd_in,
			&r_feedbacks_sd_out,
			&r_feedbacks_sd_ctrl_pin);
		tmp_converted.feedbacks_sd_cock_fb = (uint8_t)r_feedbacks_sd_cock_fb;
		tmp_converted.feedbacks_sd_fb1 = (uint8_t)r_feedbacks_sd_fb1;
		tmp_converted.feedbacks_sd_bots_fb = (uint8_t)r_feedbacks_sd_bots_fb;
		tmp_converted.feedbacks_sd_interial_fb = (uint8_t)r_feedbacks_sd_interial_fb;
		tmp_converted.feedbacks_sd_fb4 = (uint8_t)r_feedbacks_sd_fb4;
		tmp_converted.feedbacks_sd_in = (uint8_t)r_feedbacks_sd_in;
		tmp_converted.feedbacks_sd_out = (uint8_t)r_feedbacks_sd_out;
		tmp_converted.feedbacks_sd_ctrl_pin = (uint8_t)r_feedbacks_sd_ctrl_pin;

		primary_ecu_feedbacks_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_ECU_FEEDBACKS_BYTE_SIZE;
		return primary_ecu_feedbacks_pack(data, &tmp, PRIMARY_ECU_FEEDBACKS_BYTE_SIZE);
	}
	case 664:
	{
		primary_ecu_power_maps_t tmp;
		primary_ecu_power_maps_converted_t tmp_converted;
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

		primary_ecu_power_maps_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_ECU_POWER_MAPS_BYTE_SIZE;
		return primary_ecu_power_maps_pack(data, &tmp, PRIMARY_ECU_POWER_MAPS_BYTE_SIZE);
	}
	case 80:
	{
		primary_ecu_set_power_maps_t tmp;
		primary_ecu_set_power_maps_converted_t tmp_converted;
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

		primary_ecu_set_power_maps_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_ECU_SET_POWER_MAPS_BYTE_SIZE;
		return primary_ecu_set_power_maps_pack(data, &tmp, PRIMARY_ECU_SET_POWER_MAPS_BYTE_SIZE);
	}
	case 1600:
	{
		primary_ecu_ptt_status_t tmp;
		primary_ecu_ptt_status_converted_t tmp_converted;
		uint8_t r_status;

		sscanf(s, "%" SCNu8 ","  ,
			&r_status);
		tmp_converted.status = (primary_ecu_ptt_status_status)r_status;

		primary_ecu_ptt_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_ECU_PTT_STATUS_BYTE_SIZE;
		return primary_ecu_ptt_status_pack(data, &tmp, PRIMARY_ECU_PTT_STATUS_BYTE_SIZE);
	}
	case 1080:
	{
		primary_ecu_set_ptt_status_t tmp;
		primary_ecu_set_ptt_status_converted_t tmp_converted;
		uint8_t r_status;

		sscanf(s, "%" SCNu8 ","  ,
			&r_status);
		tmp_converted.status = (primary_ecu_set_ptt_status_status)r_status;

		primary_ecu_set_ptt_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_ECU_SET_PTT_STATUS_BYTE_SIZE;
		return primary_ecu_set_ptt_status_pack(data, &tmp, PRIMARY_ECU_SET_PTT_STATUS_BYTE_SIZE);
	}
	case 513:
	{
		primary_inv_l_request_t tmp;
		primary_inv_l_request_converted_t tmp_converted;
		uint8_t r_data_0;
		uint8_t r_data_1;
		uint8_t r_data_2;
		uint8_t r_data_3;
		uint8_t r_data_4;
		uint8_t r_data_5;
		uint8_t r_data_6;
		uint8_t r_data_7;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  ,
			&r_data_0,
			&r_data_1,
			&r_data_2,
			&r_data_3,
			&r_data_4,
			&r_data_5,
			&r_data_6,
			&r_data_7);
		tmp_converted.data_0 = (uint8_t)r_data_0;
		tmp_converted.data_1 = (uint8_t)r_data_1;
		tmp_converted.data_2 = (uint8_t)r_data_2;
		tmp_converted.data_3 = (uint8_t)r_data_3;
		tmp_converted.data_4 = (uint8_t)r_data_4;
		tmp_converted.data_5 = (uint8_t)r_data_5;
		tmp_converted.data_6 = (uint8_t)r_data_6;
		tmp_converted.data_7 = (uint8_t)r_data_7;

		primary_inv_l_request_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_INV_L_REQUEST_BYTE_SIZE;
		return primary_inv_l_request_pack(data, &tmp, PRIMARY_INV_L_REQUEST_BYTE_SIZE);
	}
	case 672:
	{
		primary_control_output_t tmp;
		primary_control_output_converted_t tmp_converted;
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

		primary_control_output_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_CONTROL_OUTPUT_BYTE_SIZE;
		return primary_control_output_pack(data, &tmp, PRIMARY_CONTROL_OUTPUT_BYTE_SIZE);
	}
	case 680:
	{
		primary_control_status_t tmp;
		primary_control_status_converted_t tmp_converted;
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

		primary_control_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_CONTROL_STATUS_BYTE_SIZE;
		return primary_control_status_pack(data, &tmp, PRIMARY_CONTROL_STATUS_BYTE_SIZE);
	}
	case 514:
	{
		primary_inv_r_request_t tmp;
		primary_inv_r_request_converted_t tmp_converted;
		uint8_t r_data_0;
		uint8_t r_data_1;
		uint8_t r_data_2;
		uint8_t r_data_3;
		uint8_t r_data_4;
		uint8_t r_data_5;
		uint8_t r_data_6;
		uint8_t r_data_7;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  ,
			&r_data_0,
			&r_data_1,
			&r_data_2,
			&r_data_3,
			&r_data_4,
			&r_data_5,
			&r_data_6,
			&r_data_7);
		tmp_converted.data_0 = (uint8_t)r_data_0;
		tmp_converted.data_1 = (uint8_t)r_data_1;
		tmp_converted.data_2 = (uint8_t)r_data_2;
		tmp_converted.data_3 = (uint8_t)r_data_3;
		tmp_converted.data_4 = (uint8_t)r_data_4;
		tmp_converted.data_5 = (uint8_t)r_data_5;
		tmp_converted.data_6 = (uint8_t)r_data_6;
		tmp_converted.data_7 = (uint8_t)r_data_7;

		primary_inv_r_request_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_INV_R_REQUEST_BYTE_SIZE;
		return primary_inv_r_request_pack(data, &tmp, PRIMARY_INV_R_REQUEST_BYTE_SIZE);
	}
	case 385:
	{
		primary_inv_l_response_t tmp;
		primary_inv_l_response_converted_t tmp_converted;
		uint8_t r_reg_id;
		uint8_t r_data_0;
		uint8_t r_data_1;
		uint8_t r_data_2;
		uint8_t r_data_3;
		uint8_t r_data_4;
		uint8_t r_data_5;
		uint8_t r_data_6;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  ,
			&r_reg_id,
			&r_data_0,
			&r_data_1,
			&r_data_2,
			&r_data_3,
			&r_data_4,
			&r_data_5,
			&r_data_6);
		tmp_converted.reg_id = (uint8_t)r_reg_id;
		tmp_converted.data_0 = (uint8_t)r_data_0;
		tmp_converted.data_1 = (uint8_t)r_data_1;
		tmp_converted.data_2 = (uint8_t)r_data_2;
		tmp_converted.data_3 = (uint8_t)r_data_3;
		tmp_converted.data_4 = (uint8_t)r_data_4;
		tmp_converted.data_5 = (uint8_t)r_data_5;
		tmp_converted.data_6 = (uint8_t)r_data_6;

		primary_inv_l_response_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_INV_L_RESPONSE_BYTE_SIZE;
		return primary_inv_l_response_pack(data, &tmp, PRIMARY_INV_L_RESPONSE_BYTE_SIZE);
	}
	case 386:
	{
		primary_inv_r_response_t tmp;
		primary_inv_r_response_converted_t tmp_converted;
		uint8_t r_reg_id;
		uint8_t r_data_0;
		uint8_t r_data_1;
		uint8_t r_data_2;
		uint8_t r_data_3;
		uint8_t r_data_4;
		uint8_t r_data_5;
		uint8_t r_data_6;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  ,
			&r_reg_id,
			&r_data_0,
			&r_data_1,
			&r_data_2,
			&r_data_3,
			&r_data_4,
			&r_data_5,
			&r_data_6);
		tmp_converted.reg_id = (uint8_t)r_reg_id;
		tmp_converted.data_0 = (uint8_t)r_data_0;
		tmp_converted.data_1 = (uint8_t)r_data_1;
		tmp_converted.data_2 = (uint8_t)r_data_2;
		tmp_converted.data_3 = (uint8_t)r_data_3;
		tmp_converted.data_4 = (uint8_t)r_data_4;
		tmp_converted.data_5 = (uint8_t)r_data_5;
		tmp_converted.data_6 = (uint8_t)r_data_6;

		primary_inv_r_response_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_INV_R_RESPONSE_BYTE_SIZE;
		return primary_inv_r_response_pack(data, &tmp, PRIMARY_INV_R_RESPONSE_BYTE_SIZE);
	}
	case 1608:
	{
		primary_lv_current_battery_t tmp;
		primary_lv_current_battery_converted_t tmp_converted;
		float r_lv_current;

		sscanf(s, "%f,"       ,
			&r_lv_current);
		tmp_converted.lv_current = (float)r_lv_current;

		primary_lv_current_battery_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_LV_CURRENT_BATTERY_BYTE_SIZE;
		return primary_lv_current_battery_pack(data, &tmp, PRIMARY_LV_CURRENT_BATTERY_BYTE_SIZE);
	}
	case 1616:
	{
		primary_lv_current_charger_t tmp;
		primary_lv_current_charger_converted_t tmp_converted;
		float r_charger_current;

		sscanf(s, "%f,"       ,
			&r_charger_current);
		tmp_converted.charger_current = (float)r_charger_current;

		primary_lv_current_charger_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_LV_CURRENT_CHARGER_BYTE_SIZE;
		return primary_lv_current_charger_pack(data, &tmp, PRIMARY_LV_CURRENT_CHARGER_BYTE_SIZE);
	}
	case 1624:
	{
		primary_lv_total_voltage_t tmp;
		primary_lv_total_voltage_converted_t tmp_converted;
		float r_total;

		sscanf(s, "%f,"       ,
			&r_total);
		tmp_converted.total = (float)r_total;

		primary_lv_total_voltage_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_LV_TOTAL_VOLTAGE_BYTE_SIZE;
		return primary_lv_total_voltage_pack(data, &tmp, PRIMARY_LV_TOTAL_VOLTAGE_BYTE_SIZE);
	}
	case 1632:
	{
		primary_lv_cells_voltage_t tmp;
		primary_lv_cells_voltage_converted_t tmp_converted;
		uint8_t r_start_index;
		float r_voltage_0;
		float r_voltage_1;
		float r_voltage_2;

		sscanf(s, "%" SCNu8 ","  
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_start_index,
			&r_voltage_0,
			&r_voltage_1,
			&r_voltage_2);
		tmp_converted.start_index = (uint8_t)r_start_index;
		tmp_converted.voltage_0 = (float)r_voltage_0;
		tmp_converted.voltage_1 = (float)r_voltage_1;
		tmp_converted.voltage_2 = (float)r_voltage_2;

		primary_lv_cells_voltage_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_LV_CELLS_VOLTAGE_BYTE_SIZE;
		return primary_lv_cells_voltage_pack(data, &tmp, PRIMARY_LV_CELLS_VOLTAGE_BYTE_SIZE);
	}
	case 1640:
	{
		primary_lv_cells_voltage_stats_t tmp;
		primary_lv_cells_voltage_stats_converted_t tmp_converted;
		float r_max;
		float r_min;
		float r_delta;
		float r_avg;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_max,
			&r_min,
			&r_delta,
			&r_avg);
		tmp_converted.max = (float)r_max;
		tmp_converted.min = (float)r_min;
		tmp_converted.delta = (float)r_delta;
		tmp_converted.avg = (float)r_avg;

		primary_lv_cells_voltage_stats_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_LV_CELLS_VOLTAGE_STATS_BYTE_SIZE;
		return primary_lv_cells_voltage_stats_pack(data, &tmp, PRIMARY_LV_CELLS_VOLTAGE_STATS_BYTE_SIZE);
	}
	case 1648:
	{
		primary_lv_cells_temp_t tmp;
		primary_lv_cells_temp_converted_t tmp_converted;
		uint8_t r_start_index;
		float r_temp_0;
		float r_temp_1;
		float r_temp_2;

		sscanf(s, "%" SCNu8 ","  
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_start_index,
			&r_temp_0,
			&r_temp_1,
			&r_temp_2);
		tmp_converted.start_index = (uint8_t)r_start_index;
		tmp_converted.temp_0 = (float)r_temp_0;
		tmp_converted.temp_1 = (float)r_temp_1;
		tmp_converted.temp_2 = (float)r_temp_2;

		primary_lv_cells_temp_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_LV_CELLS_TEMP_BYTE_SIZE;
		return primary_lv_cells_temp_pack(data, &tmp, PRIMARY_LV_CELLS_TEMP_BYTE_SIZE);
	}
	case 1656:
	{
		primary_lv_cells_temp_stats_t tmp;
		primary_lv_cells_temp_stats_converted_t tmp_converted;
		float r_max;
		float r_min;
		float r_avg;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       ,
			&r_max,
			&r_min,
			&r_avg);
		tmp_converted.max = (float)r_max;
		tmp_converted.min = (float)r_min;
		tmp_converted.avg = (float)r_avg;

		primary_lv_cells_temp_stats_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_LV_CELLS_TEMP_STATS_BYTE_SIZE;
		return primary_lv_cells_temp_stats_pack(data, &tmp, PRIMARY_LV_CELLS_TEMP_STATS_BYTE_SIZE);
	}
	case 1664:
	{
		primary_hv_current_t tmp;
		primary_hv_current_converted_t tmp_converted;
		float r_current;

		sscanf(s, "%f,"       ,
			&r_current);
		tmp_converted.current = (float)r_current;

		primary_hv_current_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_HV_CURRENT_BYTE_SIZE;
		return primary_hv_current_pack(data, &tmp, PRIMARY_HV_CURRENT_BYTE_SIZE);
	}
	case 1672:
	{
		primary_hv_power_t tmp;
		primary_hv_power_converted_t tmp_converted;
		float r_power;

		sscanf(s, "%f,"       ,
			&r_power);
		tmp_converted.power = (float)r_power;

		primary_hv_power_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_HV_POWER_BYTE_SIZE;
		return primary_hv_power_pack(data, &tmp, PRIMARY_HV_POWER_BYTE_SIZE);
	}
	case 1680:
	{
		primary_hv_energy_t tmp;
		primary_hv_energy_converted_t tmp_converted;
		float r_energy;

		sscanf(s, "%f,"       ,
			&r_energy);
		tmp_converted.energy = (float)r_energy;

		primary_hv_energy_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_HV_ENERGY_BYTE_SIZE;
		return primary_hv_energy_pack(data, &tmp, PRIMARY_HV_ENERGY_BYTE_SIZE);
	}
	case 1688:
	{
		primary_hv_soc_t tmp;
		primary_hv_soc_converted_t tmp_converted;
		float r_soc;

		sscanf(s, "%f,"       ,
			&r_soc);
		tmp_converted.soc = (float)r_soc;

		primary_hv_soc_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_HV_SOC_BYTE_SIZE;
		return primary_hv_soc_pack(data, &tmp, PRIMARY_HV_SOC_BYTE_SIZE);
	}
	case 1696:
	{
		primary_hv_total_voltage_t tmp;
		primary_hv_total_voltage_converted_t tmp_converted;
		float r_pack;
		float r_sum_cell;
		float r_bus;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       ,
			&r_pack,
			&r_sum_cell,
			&r_bus);
		tmp_converted.pack = (float)r_pack;
		tmp_converted.sum_cell = (float)r_sum_cell;
		tmp_converted.bus = (float)r_bus;

		primary_hv_total_voltage_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_HV_TOTAL_VOLTAGE_BYTE_SIZE;
		return primary_hv_total_voltage_pack(data, &tmp, PRIMARY_HV_TOTAL_VOLTAGE_BYTE_SIZE);
	}
	case 1704:
	{
		primary_hv_cells_voltage_t tmp;
		primary_hv_cells_voltage_converted_t tmp_converted;
		uint8_t r_start_index;
		float r_voltage_0;
		float r_voltage_1;
		float r_voltage_2;

		sscanf(s, "%" SCNu8 ","  
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_start_index,
			&r_voltage_0,
			&r_voltage_1,
			&r_voltage_2);
		tmp_converted.start_index = (uint8_t)r_start_index;
		tmp_converted.voltage_0 = (float)r_voltage_0;
		tmp_converted.voltage_1 = (float)r_voltage_1;
		tmp_converted.voltage_2 = (float)r_voltage_2;

		primary_hv_cells_voltage_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_HV_CELLS_VOLTAGE_BYTE_SIZE;
		return primary_hv_cells_voltage_pack(data, &tmp, PRIMARY_HV_CELLS_VOLTAGE_BYTE_SIZE);
	}
	case 1712:
	{
		primary_hv_cells_voltage_stats_t tmp;
		primary_hv_cells_voltage_stats_converted_t tmp_converted;
		float r_max;
		float r_min;
		float r_delta;
		float r_avg;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_max,
			&r_min,
			&r_delta,
			&r_avg);
		tmp_converted.max = (float)r_max;
		tmp_converted.min = (float)r_min;
		tmp_converted.delta = (float)r_delta;
		tmp_converted.avg = (float)r_avg;

		primary_hv_cells_voltage_stats_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_HV_CELLS_VOLTAGE_STATS_BYTE_SIZE;
		return primary_hv_cells_voltage_stats_pack(data, &tmp, PRIMARY_HV_CELLS_VOLTAGE_STATS_BYTE_SIZE);
	}
	case 1720:
	{
		primary_hv_cells_temp_t tmp;
		primary_hv_cells_temp_converted_t tmp_converted;
		uint8_t r_start_index;
		float r_temp_0;
		float r_temp_1;
		float r_temp_2;
		float r_temp_3;

		sscanf(s, "%" SCNu8 ","  
			"%f,"       
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_start_index,
			&r_temp_0,
			&r_temp_1,
			&r_temp_2,
			&r_temp_3);
		tmp_converted.start_index = (uint8_t)r_start_index;
		tmp_converted.temp_0 = (float)r_temp_0;
		tmp_converted.temp_1 = (float)r_temp_1;
		tmp_converted.temp_2 = (float)r_temp_2;
		tmp_converted.temp_3 = (float)r_temp_3;

		primary_hv_cells_temp_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_HV_CELLS_TEMP_BYTE_SIZE;
		return primary_hv_cells_temp_pack(data, &tmp, PRIMARY_HV_CELLS_TEMP_BYTE_SIZE);
	}
	case 1728:
	{
		primary_hv_cells_temp_stats_t tmp;
		primary_hv_cells_temp_stats_converted_t tmp_converted;
		float r_max;
		float r_min;
		float r_avg;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       ,
			&r_max,
			&r_min,
			&r_avg);
		tmp_converted.max = (float)r_max;
		tmp_converted.min = (float)r_min;
		tmp_converted.avg = (float)r_avg;

		primary_hv_cells_temp_stats_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_HV_CELLS_TEMP_STATS_BYTE_SIZE;
		return primary_hv_cells_temp_stats_pack(data, &tmp, PRIMARY_HV_CELLS_TEMP_STATS_BYTE_SIZE);
	}
	case 1736:
	{
		primary_debug_signal_1_t tmp;
		primary_debug_signal_1_converted_t tmp_converted;
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

		primary_debug_signal_1_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_DEBUG_SIGNAL_1_BYTE_SIZE;
		return primary_debug_signal_1_pack(data, &tmp, PRIMARY_DEBUG_SIGNAL_1_BYTE_SIZE);
	}

    }
    return 0;
}
int primary_n_fields_from_id(int id)
{
	switch(id)
    {
		case 1818: return 1;
		case 1816: return 1;
		case 1556: return 37;
		case 1555: return 4;
		case 1554: return 5;
		case 1553: return 4;
		case 1552: return 25;
		case 1560: return 7;
		case 0: return 0;
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
		case 700: return 2;
		case 701: return 2;
		case 703: return 2;
		case 704: return 2;
		case 702: return 2;
		case 705: return 3;
		case 24: return 16;
		case 512: return 36;
		case 1536: return 2;
		case 1024: return 2;
		case 520: return 20;
		case 528: return 7;
		case 536: return 8;
		case 544: return 5;
		case 552: return 6;
		case 560: return 1;
		case 32: return 1;
		case 40: return 1;
		case 1544: return 29;
		case 1032: return 2;
		case 568: return 1;
		case 1568: return 1;
		case 1576: return 1;
		case 1040: return 1;
		case 1048: return 1;
		case 576: return 23;
		case 584: return 4;
		case 592: return 4;
		case 600: return 4;
		case 608: return 7;
		case 48: return 0;
		case 56: return 0;
		case 616: return 1;
		case 64: return 1;
		case 1584: return 1;
		case 1056: return 1;
		case 624: return 1;
		case 1592: return 6;
		case 1064: return 6;
		case 632: return 1;
		case 72: return 1;
		case 1072: return 2;
		case 640: return 4;
		case 648: return 9;
		case 656: return 8;
		case 664: return 3;
		case 80: return 3;
		case 1600: return 1;
		case 1080: return 1;
		case 513: return 8;
		case 672: return 5;
		case 680: return 3;
		case 514: return 8;
		case 385: return 8;
		case 386: return 8;
		case 1608: return 1;
		case 1616: return 1;
		case 1624: return 1;
		case 1632: return 4;
		case 1640: return 4;
		case 1648: return 4;
		case 1656: return 3;
		case 1664: return 1;
		case 1672: return 1;
		case 1680: return 1;
		case 1688: return 1;
		case 1696: return 3;
		case 1704: return 4;
		case 1712: return 4;
		case 1720: return 5;
		case 1728: return 3;
		case 1736: return 4;
    }
    return 0;
}
int primary_fields_types_from_id(int id, int* fields_types, int fields_types_size)
{
    switch(id)
    {
	case 1818:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_uint64_t;
		return 1;
	case 1816:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_uint64_t;
		return 1;
	case 1556:
		if(fields_types_size < 37) return 0;
		fields_types[0] = e_primary_uint8_t;
		fields_types[1] = e_primary_uint8_t;
		fields_types[2] = e_primary_uint8_t;
		fields_types[3] = e_primary_uint8_t;
		fields_types[4] = e_primary_uint8_t;
		fields_types[5] = e_primary_uint8_t;
		fields_types[6] = e_primary_uint8_t;
		fields_types[7] = e_primary_uint8_t;
		fields_types[8] = e_primary_uint8_t;
		fields_types[9] = e_primary_uint8_t;
		fields_types[10] = e_primary_uint8_t;
		fields_types[11] = e_primary_uint8_t;
		fields_types[12] = e_primary_uint8_t;
		fields_types[13] = e_primary_uint8_t;
		fields_types[14] = e_primary_uint8_t;
		fields_types[15] = e_primary_uint8_t;
		fields_types[16] = e_primary_uint8_t;
		fields_types[17] = e_primary_uint8_t;
		fields_types[18] = e_primary_uint8_t;
		fields_types[19] = e_primary_uint8_t;
		fields_types[20] = e_primary_uint8_t;
		fields_types[21] = e_primary_uint8_t;
		fields_types[22] = e_primary_uint8_t;
		fields_types[23] = e_primary_uint8_t;
		fields_types[24] = e_primary_uint8_t;
		fields_types[25] = e_primary_uint8_t;
		fields_types[26] = e_primary_uint8_t;
		fields_types[27] = e_primary_uint8_t;
		fields_types[28] = e_primary_uint8_t;
		fields_types[29] = e_primary_uint8_t;
		fields_types[30] = e_primary_uint8_t;
		fields_types[31] = e_primary_uint8_t;
		fields_types[32] = e_primary_uint8_t;
		fields_types[33] = e_primary_uint8_t;
		fields_types[34] = e_primary_uint8_t;
		fields_types[35] = e_primary_uint8_t;
		fields_types[36] = e_primary_uint8_t;
		return 37;
	case 1555:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_primary_float;
		fields_types[1] = e_primary_float;
		fields_types[2] = e_primary_float;
		fields_types[3] = e_primary_float;
		return 4;
	case 1554:
		if(fields_types_size < 5) return 0;
		fields_types[0] = e_primary_float;
		fields_types[1] = e_primary_float;
		fields_types[2] = e_primary_float;
		fields_types[3] = e_primary_float;
		fields_types[4] = e_primary_float;
		return 5;
	case 1553:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_primary_float;
		fields_types[1] = e_primary_float;
		fields_types[2] = e_primary_float;
		fields_types[3] = e_primary_float;
		return 4;
	case 1552:
		if(fields_types_size < 25) return 0;
		fields_types[0] = e_primary_uint8_t;
		fields_types[1] = e_primary_uint8_t;
		fields_types[2] = e_primary_uint8_t;
		fields_types[3] = e_primary_uint8_t;
		fields_types[4] = e_primary_uint8_t;
		fields_types[5] = e_primary_uint8_t;
		fields_types[6] = e_primary_uint8_t;
		fields_types[7] = e_primary_uint8_t;
		fields_types[8] = e_primary_uint8_t;
		fields_types[9] = e_primary_uint8_t;
		fields_types[10] = e_primary_uint8_t;
		fields_types[11] = e_primary_uint8_t;
		fields_types[12] = e_primary_uint8_t;
		fields_types[13] = e_primary_uint8_t;
		fields_types[14] = e_primary_uint8_t;
		fields_types[15] = e_primary_uint8_t;
		fields_types[16] = e_primary_uint8_t;
		fields_types[17] = e_primary_uint8_t;
		fields_types[18] = e_primary_uint8_t;
		fields_types[19] = e_primary_uint8_t;
		fields_types[20] = e_primary_uint8_t;
		fields_types[21] = e_primary_uint8_t;
		fields_types[22] = e_primary_uint8_t;
		fields_types[23] = e_primary_uint8_t;
		fields_types[24] = e_primary_uint8_t;
		return 25;
	case 1560:
		if(fields_types_size < 7) return 0;
		fields_types[0] = e_primary_uint8_t;
		fields_types[1] = e_primary_uint8_t;
		fields_types[2] = e_primary_uint8_t;
		fields_types[3] = e_primary_uint8_t;
		fields_types[4] = e_primary_float;
		fields_types[5] = e_primary_float;
		fields_types[6] = e_primary_float;
		return 7;
	case 700:
		if(fields_types_size < 2) return 0;
		fields_types[0] = e_primary_uint32_t;
		fields_types[1] = e_primary_uint32_t;
		return 2;
	case 701:
		if(fields_types_size < 2) return 0;
		fields_types[0] = e_primary_uint32_t;
		fields_types[1] = e_primary_uint32_t;
		return 2;
	case 703:
		if(fields_types_size < 2) return 0;
		fields_types[0] = e_primary_uint32_t;
		fields_types[1] = e_primary_uint32_t;
		return 2;
	case 704:
		if(fields_types_size < 2) return 0;
		fields_types[0] = e_primary_uint32_t;
		fields_types[1] = e_primary_uint32_t;
		return 2;
	case 702:
		if(fields_types_size < 2) return 0;
		fields_types[0] = e_primary_uint32_t;
		fields_types[1] = e_primary_uint32_t;
		return 2;
	case 705:
		if(fields_types_size < 3) return 0;
		fields_types[0] = e_primary_hv_cellboard_version_cellboard_id;
		fields_types[1] = e_primary_uint16_t;
		fields_types[2] = e_primary_uint32_t;
		return 3;
	case 24:
		if(fields_types_size < 16) return 0;
		fields_types[0] = e_primary_uint8_t;
		fields_types[1] = e_primary_uint8_t;
		fields_types[2] = e_primary_uint8_t;
		fields_types[3] = e_primary_uint8_t;
		fields_types[4] = e_primary_uint8_t;
		fields_types[5] = e_primary_uint8_t;
		fields_types[6] = e_primary_uint8_t;
		fields_types[7] = e_primary_uint8_t;
		fields_types[8] = e_primary_uint8_t;
		fields_types[9] = e_primary_uint8_t;
		fields_types[10] = e_primary_uint8_t;
		fields_types[11] = e_primary_uint8_t;
		fields_types[12] = e_primary_uint8_t;
		fields_types[13] = e_primary_uint8_t;
		fields_types[14] = e_primary_uint8_t;
		fields_types[15] = e_primary_uint8_t;
		return 16;
	case 512:
		if(fields_types_size < 36) return 0;
		fields_types[0] = e_primary_uint8_t;
		fields_types[1] = e_primary_uint8_t;
		fields_types[2] = e_primary_uint8_t;
		fields_types[3] = e_primary_uint8_t;
		fields_types[4] = e_primary_uint8_t;
		fields_types[5] = e_primary_uint8_t;
		fields_types[6] = e_primary_uint8_t;
		fields_types[7] = e_primary_uint8_t;
		fields_types[8] = e_primary_uint8_t;
		fields_types[9] = e_primary_uint8_t;
		fields_types[10] = e_primary_uint8_t;
		fields_types[11] = e_primary_uint8_t;
		fields_types[12] = e_primary_uint8_t;
		fields_types[13] = e_primary_uint8_t;
		fields_types[14] = e_primary_uint8_t;
		fields_types[15] = e_primary_uint8_t;
		fields_types[16] = e_primary_uint8_t;
		fields_types[17] = e_primary_uint8_t;
		fields_types[18] = e_primary_uint8_t;
		fields_types[19] = e_primary_uint8_t;
		fields_types[20] = e_primary_uint8_t;
		fields_types[21] = e_primary_uint8_t;
		fields_types[22] = e_primary_uint8_t;
		fields_types[23] = e_primary_uint8_t;
		fields_types[24] = e_primary_uint8_t;
		fields_types[25] = e_primary_uint8_t;
		fields_types[26] = e_primary_uint8_t;
		fields_types[27] = e_primary_uint8_t;
		fields_types[28] = e_primary_uint8_t;
		fields_types[29] = e_primary_uint8_t;
		fields_types[30] = e_primary_uint8_t;
		fields_types[31] = e_primary_uint8_t;
		fields_types[32] = e_primary_uint8_t;
		fields_types[33] = e_primary_uint8_t;
		fields_types[34] = e_primary_uint8_t;
		fields_types[35] = e_primary_uint8_t;
		return 36;
	case 1536:
		if(fields_types_size < 2) return 0;
		fields_types[0] = e_primary_hv_fans_status_fans_override;
		fields_types[1] = e_primary_float;
		return 2;
	case 1024:
		if(fields_types_size < 2) return 0;
		fields_types[0] = e_primary_hv_set_fans_status_fans_override;
		fields_types[1] = e_primary_float;
		return 2;
	case 520:
		if(fields_types_size < 20) return 0;
		fields_types[0] = e_primary_uint8_t;
		fields_types[1] = e_primary_uint8_t;
		fields_types[2] = e_primary_uint8_t;
		fields_types[3] = e_primary_uint8_t;
		fields_types[4] = e_primary_uint8_t;
		fields_types[5] = e_primary_uint8_t;
		fields_types[6] = e_primary_uint8_t;
		fields_types[7] = e_primary_uint8_t;
		fields_types[8] = e_primary_uint8_t;
		fields_types[9] = e_primary_uint8_t;
		fields_types[10] = e_primary_uint8_t;
		fields_types[11] = e_primary_uint8_t;
		fields_types[12] = e_primary_uint8_t;
		fields_types[13] = e_primary_uint8_t;
		fields_types[14] = e_primary_uint8_t;
		fields_types[15] = e_primary_uint8_t;
		fields_types[16] = e_primary_uint8_t;
		fields_types[17] = e_primary_uint8_t;
		fields_types[18] = e_primary_uint8_t;
		fields_types[19] = e_primary_uint8_t;
		return 20;
	case 528:
		if(fields_types_size < 7) return 0;
		fields_types[0] = e_primary_float;
		fields_types[1] = e_primary_float;
		fields_types[2] = e_primary_float;
		fields_types[3] = e_primary_float;
		fields_types[4] = e_primary_float;
		fields_types[5] = e_primary_float;
		fields_types[6] = e_primary_float;
		return 7;
	case 536:
		if(fields_types_size < 8) return 0;
		fields_types[0] = e_primary_uint32_t;
		fields_types[1] = e_primary_uint32_t;
		fields_types[2] = e_primary_uint32_t;
		fields_types[3] = e_primary_uint32_t;
		fields_types[4] = e_primary_uint32_t;
		fields_types[5] = e_primary_uint32_t;
		fields_types[6] = e_primary_uint32_t;
		fields_types[7] = e_primary_uint32_t;
		return 8;
	case 544:
		if(fields_types_size < 5) return 0;
		fields_types[0] = e_primary_uint32_t;
		fields_types[1] = e_primary_uint32_t;
		fields_types[2] = e_primary_uint32_t;
		fields_types[3] = e_primary_uint32_t;
		fields_types[4] = e_primary_uint32_t;
		return 5;
	case 552:
		if(fields_types_size < 6) return 0;
		fields_types[0] = e_primary_uint32_t;
		fields_types[1] = e_primary_uint32_t;
		fields_types[2] = e_primary_uint32_t;
		fields_types[3] = e_primary_uint32_t;
		fields_types[4] = e_primary_uint32_t;
		fields_types[5] = e_primary_uint32_t;
		return 6;
	case 560:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_hv_status_status;
		return 1;
	case 32:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_hv_set_status_ecu_hv_status_set;
		return 1;
	case 40:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_hv_set_status_handcart_hv_status_set;
		return 1;
	case 1544:
		if(fields_types_size < 29) return 0;
		fields_types[0] = e_primary_hv_balancing_status_cellboard_id;
		fields_types[1] = e_primary_hv_balancing_status_balancing_status;
		fields_types[2] = e_primary_uint8_t;
		fields_types[3] = e_primary_uint8_t;
		fields_types[4] = e_primary_uint8_t;
		fields_types[5] = e_primary_uint8_t;
		fields_types[6] = e_primary_uint8_t;
		fields_types[7] = e_primary_uint8_t;
		fields_types[8] = e_primary_uint8_t;
		fields_types[9] = e_primary_uint8_t;
		fields_types[10] = e_primary_uint8_t;
		fields_types[11] = e_primary_uint8_t;
		fields_types[12] = e_primary_uint8_t;
		fields_types[13] = e_primary_uint8_t;
		fields_types[14] = e_primary_uint8_t;
		fields_types[15] = e_primary_uint8_t;
		fields_types[16] = e_primary_uint8_t;
		fields_types[17] = e_primary_uint8_t;
		fields_types[18] = e_primary_uint8_t;
		fields_types[19] = e_primary_uint8_t;
		fields_types[20] = e_primary_uint8_t;
		fields_types[21] = e_primary_uint8_t;
		fields_types[22] = e_primary_uint8_t;
		fields_types[23] = e_primary_uint8_t;
		fields_types[24] = e_primary_uint8_t;
		fields_types[25] = e_primary_uint8_t;
		fields_types[26] = e_primary_uint8_t;
		fields_types[27] = e_primary_uint8_t;
		fields_types[28] = e_primary_uint8_t;
		return 29;
	case 1032:
		if(fields_types_size < 2) return 0;
		fields_types[0] = e_primary_hv_set_balancing_status_set_balancing_status;
		fields_types[1] = e_primary_uint8_t;
		return 2;
	case 568:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_lv_status_status;
		return 1;
	case 1568:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_float;
		return 1;
	case 1576:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_float;
		return 1;
	case 1040:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_float;
		return 1;
	case 1048:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_float;
		return 1;
	case 576:
		if(fields_types_size < 23) return 0;
		fields_types[0] = e_primary_uint8_t;
		fields_types[1] = e_primary_uint8_t;
		fields_types[2] = e_primary_uint8_t;
		fields_types[3] = e_primary_uint8_t;
		fields_types[4] = e_primary_uint8_t;
		fields_types[5] = e_primary_uint8_t;
		fields_types[6] = e_primary_uint8_t;
		fields_types[7] = e_primary_uint8_t;
		fields_types[8] = e_primary_uint8_t;
		fields_types[9] = e_primary_uint8_t;
		fields_types[10] = e_primary_uint8_t;
		fields_types[11] = e_primary_uint8_t;
		fields_types[12] = e_primary_uint8_t;
		fields_types[13] = e_primary_uint8_t;
		fields_types[14] = e_primary_uint8_t;
		fields_types[15] = e_primary_uint8_t;
		fields_types[16] = e_primary_uint8_t;
		fields_types[17] = e_primary_uint8_t;
		fields_types[18] = e_primary_uint8_t;
		fields_types[19] = e_primary_uint8_t;
		fields_types[20] = e_primary_uint8_t;
		fields_types[21] = e_primary_uint8_t;
		fields_types[22] = e_primary_uint8_t;
		return 23;
	case 584:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_primary_float;
		fields_types[1] = e_primary_float;
		fields_types[2] = e_primary_float;
		fields_types[3] = e_primary_float;
		return 4;
	case 592:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_primary_float;
		fields_types[1] = e_primary_float;
		fields_types[2] = e_primary_float;
		fields_types[3] = e_primary_float;
		return 4;
	case 600:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_primary_float;
		fields_types[1] = e_primary_float;
		fields_types[2] = e_primary_float;
		fields_types[3] = e_primary_float;
		return 4;
	case 608:
		if(fields_types_size < 7) return 0;
		fields_types[0] = e_primary_uint8_t;
		fields_types[1] = e_primary_uint8_t;
		fields_types[2] = e_primary_uint8_t;
		fields_types[3] = e_primary_uint8_t;
		fields_types[4] = e_primary_uint8_t;
		fields_types[5] = e_primary_uint8_t;
		fields_types[6] = e_primary_uint8_t;
		return 7;
	case 616:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_lv_inverter_connection_status_status;
		return 1;
	case 64:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_lv_set_inverter_connection_status_status;
		return 1;
	case 1584:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_tlm_status_status;
		return 1;
	case 1056:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_tlm_set_status_status;
		return 1;
	case 624:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_handcart_status_connected;
		return 1;
	case 1592:
		if(fields_types_size < 6) return 0;
		fields_types[0] = e_primary_float;
		fields_types[1] = e_primary_handcart_settings_fans_override;
		fields_types[2] = e_primary_float;
		fields_types[3] = e_primary_float;
		fields_types[4] = e_primary_float;
		fields_types[5] = e_primary_handcart_settings_status;
		return 6;
	case 1064:
		if(fields_types_size < 6) return 0;
		fields_types[0] = e_primary_float;
		fields_types[1] = e_primary_handcart_set_settings_fans_override;
		fields_types[2] = e_primary_float;
		fields_types[3] = e_primary_float;
		fields_types[4] = e_primary_float;
		fields_types[5] = e_primary_handcart_set_settings_status;
		return 6;
	case 632:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_ecu_status_status;
		return 1;
	case 72:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_ecu_set_status_status;
		return 1;
	case 1072:
		if(fields_types_size < 2) return 0;
		fields_types[0] = e_primary_ecu_inverter_status_rl;
		fields_types[1] = e_primary_ecu_inverter_status_rr;
		return 2;
	case 640:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_primary_uint8_t;
		fields_types[1] = e_primary_uint8_t;
		fields_types[2] = e_primary_uint8_t;
		fields_types[3] = e_primary_uint8_t;
		return 4;
	case 648:
		if(fields_types_size < 9) return 0;
		fields_types[0] = e_primary_uint8_t;
		fields_types[1] = e_primary_uint8_t;
		fields_types[2] = e_primary_uint8_t;
		fields_types[3] = e_primary_uint8_t;
		fields_types[4] = e_primary_uint8_t;
		fields_types[5] = e_primary_uint8_t;
		fields_types[6] = e_primary_uint8_t;
		fields_types[7] = e_primary_uint8_t;
		fields_types[8] = e_primary_uint8_t;
		return 9;
	case 656:
		if(fields_types_size < 8) return 0;
		fields_types[0] = e_primary_uint8_t;
		fields_types[1] = e_primary_uint8_t;
		fields_types[2] = e_primary_uint8_t;
		fields_types[3] = e_primary_uint8_t;
		fields_types[4] = e_primary_uint8_t;
		fields_types[5] = e_primary_uint8_t;
		fields_types[6] = e_primary_uint8_t;
		fields_types[7] = e_primary_uint8_t;
		return 8;
	case 664:
		if(fields_types_size < 3) return 0;
		fields_types[0] = e_primary_float;
		fields_types[1] = e_primary_float;
		fields_types[2] = e_primary_float;
		return 3;
	case 80:
		if(fields_types_size < 3) return 0;
		fields_types[0] = e_primary_float;
		fields_types[1] = e_primary_float;
		fields_types[2] = e_primary_float;
		return 3;
	case 1600:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_ecu_ptt_status_status;
		return 1;
	case 1080:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_ecu_set_ptt_status_status;
		return 1;
	case 513:
		if(fields_types_size < 8) return 0;
		fields_types[0] = e_primary_uint8_t;
		fields_types[1] = e_primary_uint8_t;
		fields_types[2] = e_primary_uint8_t;
		fields_types[3] = e_primary_uint8_t;
		fields_types[4] = e_primary_uint8_t;
		fields_types[5] = e_primary_uint8_t;
		fields_types[6] = e_primary_uint8_t;
		fields_types[7] = e_primary_uint8_t;
		return 8;
	case 672:
		if(fields_types_size < 5) return 0;
		fields_types[0] = e_primary_float;
		fields_types[1] = e_primary_float;
		fields_types[2] = e_primary_float;
		fields_types[3] = e_primary_float;
		fields_types[4] = e_primary_float;
		return 5;
	case 680:
		if(fields_types_size < 3) return 0;
		fields_types[0] = e_primary_float;
		fields_types[1] = e_primary_float;
		fields_types[2] = e_primary_float;
		return 3;
	case 514:
		if(fields_types_size < 8) return 0;
		fields_types[0] = e_primary_uint8_t;
		fields_types[1] = e_primary_uint8_t;
		fields_types[2] = e_primary_uint8_t;
		fields_types[3] = e_primary_uint8_t;
		fields_types[4] = e_primary_uint8_t;
		fields_types[5] = e_primary_uint8_t;
		fields_types[6] = e_primary_uint8_t;
		fields_types[7] = e_primary_uint8_t;
		return 8;
	case 385:
		if(fields_types_size < 8) return 0;
		fields_types[0] = e_primary_uint8_t;
		fields_types[1] = e_primary_uint8_t;
		fields_types[2] = e_primary_uint8_t;
		fields_types[3] = e_primary_uint8_t;
		fields_types[4] = e_primary_uint8_t;
		fields_types[5] = e_primary_uint8_t;
		fields_types[6] = e_primary_uint8_t;
		fields_types[7] = e_primary_uint8_t;
		return 8;
	case 386:
		if(fields_types_size < 8) return 0;
		fields_types[0] = e_primary_uint8_t;
		fields_types[1] = e_primary_uint8_t;
		fields_types[2] = e_primary_uint8_t;
		fields_types[3] = e_primary_uint8_t;
		fields_types[4] = e_primary_uint8_t;
		fields_types[5] = e_primary_uint8_t;
		fields_types[6] = e_primary_uint8_t;
		fields_types[7] = e_primary_uint8_t;
		return 8;
	case 1608:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_float;
		return 1;
	case 1616:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_float;
		return 1;
	case 1624:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_float;
		return 1;
	case 1632:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_primary_uint8_t;
		fields_types[1] = e_primary_float;
		fields_types[2] = e_primary_float;
		fields_types[3] = e_primary_float;
		return 4;
	case 1640:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_primary_float;
		fields_types[1] = e_primary_float;
		fields_types[2] = e_primary_float;
		fields_types[3] = e_primary_float;
		return 4;
	case 1648:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_primary_uint8_t;
		fields_types[1] = e_primary_float;
		fields_types[2] = e_primary_float;
		fields_types[3] = e_primary_float;
		return 4;
	case 1656:
		if(fields_types_size < 3) return 0;
		fields_types[0] = e_primary_float;
		fields_types[1] = e_primary_float;
		fields_types[2] = e_primary_float;
		return 3;
	case 1664:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_float;
		return 1;
	case 1672:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_float;
		return 1;
	case 1680:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_float;
		return 1;
	case 1688:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_float;
		return 1;
	case 1696:
		if(fields_types_size < 3) return 0;
		fields_types[0] = e_primary_float;
		fields_types[1] = e_primary_float;
		fields_types[2] = e_primary_float;
		return 3;
	case 1704:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_primary_uint8_t;
		fields_types[1] = e_primary_float;
		fields_types[2] = e_primary_float;
		fields_types[3] = e_primary_float;
		return 4;
	case 1712:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_primary_float;
		fields_types[1] = e_primary_float;
		fields_types[2] = e_primary_float;
		fields_types[3] = e_primary_float;
		return 4;
	case 1720:
		if(fields_types_size < 5) return 0;
		fields_types[0] = e_primary_uint8_t;
		fields_types[1] = e_primary_float;
		fields_types[2] = e_primary_float;
		fields_types[3] = e_primary_float;
		fields_types[4] = e_primary_float;
		return 5;
	case 1728:
		if(fields_types_size < 3) return 0;
		fields_types[0] = e_primary_float;
		fields_types[1] = e_primary_float;
		fields_types[2] = e_primary_float;
		return 3;
	case 1736:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_primary_float;
		fields_types[1] = e_primary_float;
		fields_types[2] = e_primary_float;
		fields_types[3] = e_primary_float;
		return 4;

    }
    return 0;
}
int primary_enum_fields_from_name(const char *msg_name, const char *sgn_name, char **v)
{
	if(!strcmp(msg_name, "HV_CELLBOARD_VERSION"))
	{
		if(!strcmp(sgn_name, "cellboard_id"))
		{
			sprintf(v[0], "cellboard_0");
			sprintf(v[1], "cellboard_1");
			sprintf(v[2], "cellboard_2");
			sprintf(v[3], "cellboard_3");
			sprintf(v[4], "cellboard_4");
			sprintf(v[5], "cellboard_5");
			return 6;
		}
	}
	if(!strcmp(msg_name, "HV_FANS_STATUS"))
	{
		if(!strcmp(sgn_name, "fans_override"))
		{
			sprintf(v[0], "off");
			sprintf(v[1], "on");
			return 2;
		}
	}
	if(!strcmp(msg_name, "HV_SET_FANS_STATUS"))
	{
		if(!strcmp(sgn_name, "fans_override"))
		{
			sprintf(v[0], "off");
			sprintf(v[1], "on");
			return 2;
		}
	}
	if(!strcmp(msg_name, "HV_STATUS"))
	{
		if(!strcmp(sgn_name, "status"))
		{
			sprintf(v[0], "init");
			sprintf(v[1], "idle");
			sprintf(v[2], "airn_close");
			sprintf(v[3], "precharge");
			sprintf(v[4], "airp_close");
			sprintf(v[5], "ts_on");
			sprintf(v[6], "fatal_error");
			return 7;
		}
	}
	if(!strcmp(msg_name, "HV_SET_STATUS_ECU"))
	{
		if(!strcmp(sgn_name, "hv_status_set"))
		{
			sprintf(v[0], "off");
			sprintf(v[1], "on");
			return 2;
		}
	}
	if(!strcmp(msg_name, "HV_SET_STATUS_HANDCART"))
	{
		if(!strcmp(sgn_name, "hv_status_set"))
		{
			sprintf(v[0], "off");
			sprintf(v[1], "on");
			return 2;
		}
	}
	if(!strcmp(msg_name, "HV_BALANCING_STATUS"))
	{
		if(!strcmp(sgn_name, "cellboard_id"))
		{
			sprintf(v[0], "cellboard_0");
			sprintf(v[1], "cellboard_1");
			sprintf(v[2], "cellboard_2");
			sprintf(v[3], "cellboard_3");
			sprintf(v[4], "cellboard_4");
			sprintf(v[5], "cellboard_5");
			return 6;
		}
		if(!strcmp(sgn_name, "balancing_status"))
		{
			sprintf(v[0], "off");
			sprintf(v[1], "on");
			return 2;
		}
	}
	if(!strcmp(msg_name, "HV_SET_BALANCING_STATUS"))
	{
		if(!strcmp(sgn_name, "set_balancing_status"))
		{
			sprintf(v[0], "off");
			sprintf(v[1], "on");
			return 2;
		}
	}
	if(!strcmp(msg_name, "LV_STATUS"))
	{
		if(!strcmp(sgn_name, "status"))
		{
			sprintf(v[0], "init");
			sprintf(v[1], "idle");
			sprintf(v[2], "tson");
			sprintf(v[3], "run");
			sprintf(v[4], "flashing");
			sprintf(v[5], "error");
			return 6;
		}
	}
	if(!strcmp(msg_name, "LV_INVERTER_CONNECTION_STATUS"))
	{
		if(!strcmp(sgn_name, "status"))
		{
			sprintf(v[0], "off");
			sprintf(v[1], "on");
			return 2;
		}
	}
	if(!strcmp(msg_name, "LV_SET_INVERTER_CONNECTION_STATUS"))
	{
		if(!strcmp(sgn_name, "status"))
		{
			sprintf(v[0], "off");
			sprintf(v[1], "on");
			return 2;
		}
	}
	if(!strcmp(msg_name, "TLM_STATUS"))
	{
		if(!strcmp(sgn_name, "status"))
		{
			sprintf(v[0], "off");
			sprintf(v[1], "on");
			return 2;
		}
	}
	if(!strcmp(msg_name, "TLM_SET_STATUS"))
	{
		if(!strcmp(sgn_name, "status"))
		{
			sprintf(v[0], "off");
			sprintf(v[1], "on");
			return 2;
		}
	}
	if(!strcmp(msg_name, "HANDCART_STATUS"))
	{
		if(!strcmp(sgn_name, "connected"))
		{
			sprintf(v[0], "off");
			sprintf(v[1], "on");
			return 2;
		}
	}
	if(!strcmp(msg_name, "HANDCART_SETTINGS"))
	{
		if(!strcmp(sgn_name, "fans_override"))
		{
			sprintf(v[0], "off");
			sprintf(v[1], "on");
			return 2;
		}
		if(!strcmp(sgn_name, "status"))
		{
			sprintf(v[0], "none");
			sprintf(v[1], "check");
			sprintf(v[2], "idle");
			sprintf(v[3], "precharge");
			sprintf(v[4], "ready");
			sprintf(v[5], "charge");
			sprintf(v[6], "charge_done");
			sprintf(v[7], "balancing");
			sprintf(v[8], "error");
			return 9;
		}
	}
	if(!strcmp(msg_name, "HANDCART_SET_SETTINGS"))
	{
		if(!strcmp(sgn_name, "fans_override"))
		{
			sprintf(v[0], "off");
			sprintf(v[1], "on");
			return 2;
		}
		if(!strcmp(sgn_name, "status"))
		{
			sprintf(v[0], "none");
			sprintf(v[1], "check");
			sprintf(v[2], "idle");
			sprintf(v[3], "precharge");
			sprintf(v[4], "ready");
			sprintf(v[5], "charge");
			sprintf(v[6], "charge_done");
			sprintf(v[7], "balancing");
			sprintf(v[8], "error");
			return 9;
		}
	}
	if(!strcmp(msg_name, "ECU_STATUS"))
	{
		if(!strcmp(sgn_name, "status"))
		{
			sprintf(v[0], "init");
			sprintf(v[1], "enable_inv_updates");
			sprintf(v[2], "check_inv_settings");
			sprintf(v[3], "idle");
			sprintf(v[4], "start_ts_precharge");
			sprintf(v[5], "wait_ts_precharge");
			sprintf(v[6], "wait_driver");
			sprintf(v[7], "enable_inv_drive");
			sprintf(v[8], "drive");
			sprintf(v[9], "disable_inv_drive");
			sprintf(v[10], "start_ts_discharge");
			sprintf(v[11], "wait_ts_discharge");
			sprintf(v[12], "fatal_error");
			return 13;
		}
	}
	if(!strcmp(msg_name, "ECU_SET_STATUS"))
	{
		if(!strcmp(sgn_name, "status"))
		{
			sprintf(v[0], "idle");
			sprintf(v[1], "ready");
			sprintf(v[2], "drive");
			return 3;
		}
	}
	if(!strcmp(msg_name, "ECU_INVERTER_STATUS"))
	{
		if(!strcmp(sgn_name, "rl"))
		{
			sprintf(v[0], "disabled");
			sprintf(v[1], "rfe_on");
			sprintf(v[2], "frg_on");
			sprintf(v[3], "enabled");
			return 4;
		}
		if(!strcmp(sgn_name, "rr"))
		{
			sprintf(v[0], "disabled");
			sprintf(v[1], "rfe_on");
			sprintf(v[2], "frg_on");
			sprintf(v[3], "enabled");
			return 4;
		}
	}
	if(!strcmp(msg_name, "ECU_PTT_STATUS"))
	{
		if(!strcmp(sgn_name, "status"))
		{
			sprintf(v[0], "off");
			sprintf(v[1], "on");
			return 2;
		}
	}
	if(!strcmp(msg_name, "ECU_SET_PTT_STATUS"))
	{
		if(!strcmp(sgn_name, "status"))
		{
			sprintf(v[0], "off");
			sprintf(v[1], "on");
			return 2;
		}
	}
	return 0;
}
