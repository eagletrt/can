#include "primary_utils.hpp"

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
	case 0:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, HV_JMP_TO_BLT_FORWARD);
		snprintf(v[1], string_size, HV_JMP_TO_BLT_CELLBOARD_ID);

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
	case 32:
		if(15 > fields_size) return 1;
		snprintf(v[0], string_size, HV_ERRORS_ERRORS_CELL_UNDER_VOLTAGE);
		snprintf(v[1], string_size, HV_ERRORS_ERRORS_CELL_OVER_VOLTAGE);
		snprintf(v[2], string_size, HV_ERRORS_ERRORS_CELL_UNDER_TEMPERATURE);
		snprintf(v[3], string_size, HV_ERRORS_ERRORS_CELL_OVER_TEMPERATURE);
		snprintf(v[4], string_size, HV_ERRORS_ERRORS_OVER_CURRENT);
		snprintf(v[5], string_size, HV_ERRORS_ERRORS_CAN);
		snprintf(v[6], string_size, HV_ERRORS_ERRORS_INT_VOLTAGE_MISMATCH);
		snprintf(v[7], string_size, HV_ERRORS_ERRORS_CELLBOARD_COMM);
		snprintf(v[8], string_size, HV_ERRORS_ERRORS_CELLBOARD_INTERNAL);
		snprintf(v[9], string_size, HV_ERRORS_ERRORS_CONNECTOR_DISCONNECTED);
		snprintf(v[10], string_size, HV_ERRORS_ERRORS_FANS_DISCONNECTED);
		snprintf(v[11], string_size, HV_ERRORS_ERRORS_FEEDBACK);
		snprintf(v[12], string_size, HV_ERRORS_ERRORS_FEEDBACK_CIRCUITRY);
		snprintf(v[13], string_size, HV_ERRORS_ERRORS_EEPROM_COMM);
		snprintf(v[14], string_size, HV_ERRORS_ERRORS_EEPROM_WRITE);

		return 0;
	case 512:
		if(35 > fields_size) return 1;
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
		snprintf(v[20], string_size, HV_DEBUG_SIGNALS_ERRORS_CELL_UNDER_VOLTAGE);
		snprintf(v[21], string_size, HV_DEBUG_SIGNALS_ERRORS_CELL_OVER_VOLTAGE);
		snprintf(v[22], string_size, HV_DEBUG_SIGNALS_ERRORS_CELL_UNDER_TEMPERATURE);
		snprintf(v[23], string_size, HV_DEBUG_SIGNALS_ERRORS_CELL_OVER_TEMPERATURE);
		snprintf(v[24], string_size, HV_DEBUG_SIGNALS_ERRORS_OVER_CURRENT);
		snprintf(v[25], string_size, HV_DEBUG_SIGNALS_ERRORS_CAN);
		snprintf(v[26], string_size, HV_DEBUG_SIGNALS_ERRORS_INT_VOLTAGE_MISMATCH);
		snprintf(v[27], string_size, HV_DEBUG_SIGNALS_ERRORS_CELLBOARD_COMM);
		snprintf(v[28], string_size, HV_DEBUG_SIGNALS_ERRORS_CELLBOARD_INTERNAL);
		snprintf(v[29], string_size, HV_DEBUG_SIGNALS_ERRORS_CONNECTOR_DISCONNECTED);
		snprintf(v[30], string_size, HV_DEBUG_SIGNALS_ERRORS_FANS_DISCONNECTED);
		snprintf(v[31], string_size, HV_DEBUG_SIGNALS_ERRORS_FEEDBACK);
		snprintf(v[32], string_size, HV_DEBUG_SIGNALS_ERRORS_FEEDBACK_CIRCUITRY);
		snprintf(v[33], string_size, HV_DEBUG_SIGNALS_ERRORS_EEPROM_COMM);
		snprintf(v[34], string_size, HV_DEBUG_SIGNALS_ERRORS_EEPROM_WRITE);

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
		snprintf(v[0], string_size, HV_FEEDBACK_STATUS_FEEDBACK_IMPLAUSIBILITY_DETECTED);
		snprintf(v[1], string_size, HV_FEEDBACK_STATUS_FEEDBACK_IMD_COCKPIT);
		snprintf(v[2], string_size, HV_FEEDBACK_STATUS_FEEDBACK_TSAL_GREEN_FAULT_LATCHED);
		snprintf(v[3], string_size, HV_FEEDBACK_STATUS_FEEDBACK_BMS_COCKPIT);
		snprintf(v[4], string_size, HV_FEEDBACK_STATUS_FEEDBACK_EXT_LATCHED);
		snprintf(v[5], string_size, HV_FEEDBACK_STATUS_FEEDBACK_TSAL_GREEN);
		snprintf(v[6], string_size, HV_FEEDBACK_STATUS_FEEDBACK_TS_OVER_60V_STATUS);
		snprintf(v[7], string_size, HV_FEEDBACK_STATUS_FEEDBACK_AIRN_STATUS);
		snprintf(v[8], string_size, HV_FEEDBACK_STATUS_FEEDBACK_AIRP_STATUS);
		snprintf(v[9], string_size, HV_FEEDBACK_STATUS_FEEDBACK_AIRP_GATE);
		snprintf(v[10], string_size, HV_FEEDBACK_STATUS_FEEDBACK_AIRN_GATE);
		snprintf(v[11], string_size, HV_FEEDBACK_STATUS_FEEDBACK_PRECHARGE_STATUS);
		snprintf(v[12], string_size, HV_FEEDBACK_STATUS_FEEDBACK_TSP_OVER_60V_STATUS);
		snprintf(v[13], string_size, HV_FEEDBACK_STATUS_FEEDBACK_IMD_FAULT);
		snprintf(v[14], string_size, HV_FEEDBACK_STATUS_FEEDBACK_CHECK_MUX);
		snprintf(v[15], string_size, HV_FEEDBACK_STATUS_FEEDBACK_SD_END);
		snprintf(v[16], string_size, HV_FEEDBACK_STATUS_FEEDBACK_SD_OUT);
		snprintf(v[17], string_size, HV_FEEDBACK_STATUS_FEEDBACK_SD_IN);
		snprintf(v[18], string_size, HV_FEEDBACK_STATUS_FEEDBACK_SD_BMS);
		snprintf(v[19], string_size, HV_FEEDBACK_STATUS_FEEDBACK_SD_IMD);

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
	case 40:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, HV_SET_STATUS_ECU_HV_STATUS_SET);

		return 0;
	case 48:
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
		snprintf(v[0], string_size, HV_SET_BALANCING_STATUS_HANDCART_SET_BALANCING_STATUS);
		snprintf(v[1], string_size, HV_SET_BALANCING_STATUS_HANDCART_BALANCING_THRESHOLD);

		return 0;
	case 1040:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, HV_SET_BALANCING_STATUS_STEERING_WHEEL_SET_BALANCING_STATUS);
		snprintf(v[1], string_size, HV_SET_BALANCING_STATUS_STEERING_WHEEL_BALANCING_THRESHOLD);

		return 0;
	case 568:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, LV_STATUS_STATUS);

		return 0;
	case 1568:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, LV_CHARGING_STATUS_STATUS);

		return 0;
	case 1576:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, LV_COOLING_AGGRESSIVENESS_STATUS);

		return 0;
	case 1048:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, LV_SET_COOLING_AGGRESSIVENESS_STATUS);

		return 0;
	case 1584:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, LV_RADIATOR_SPEED_STATUS);
		snprintf(v[1], string_size, LV_RADIATOR_SPEED_RADIATOR_SPEED);

		return 0;
	case 1592:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, LV_PUMPS_SPEED_STATUS);
		snprintf(v[1], string_size, LV_PUMPS_SPEED_PUMPS_SPEED);

		return 0;
	case 1056:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, LV_SET_RADIATOR_SPEED_STATUS);
		snprintf(v[1], string_size, LV_SET_RADIATOR_SPEED_RADIATOR_SPEED);

		return 0;
	case 1064:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, LV_SET_PUMPS_SPEED_STATUS);
		snprintf(v[1], string_size, LV_SET_PUMPS_SPEED_PUMPS_SPEED);

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
		if(8 > fields_size) return 1;
		snprintf(v[0], string_size, LV_FEEDBACK_FEEDBACKS_BSPD);
		snprintf(v[1], string_size, LV_FEEDBACK_FEEDBACKS_HVD);
		snprintf(v[2], string_size, LV_FEEDBACK_FEEDBACKS_INVC_INTERLOCK);
		snprintf(v[3], string_size, LV_FEEDBACK_FEEDBACKS_AMS);
		snprintf(v[4], string_size, LV_FEEDBACK_FEEDBACKS_SD_END);
		snprintf(v[5], string_size, LV_FEEDBACK_FEEDBACKS_LVMS);
		snprintf(v[6], string_size, LV_FEEDBACK_FEEDBACKS_INTERLOCK);
		snprintf(v[7], string_size, LV_FEEDBACK_FEEDBACKS_SD_START);

		return 0;
	case 592:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, LV_FEEDBACK_TS_VOLTAGE_BSPD);
		snprintf(v[1], string_size, LV_FEEDBACK_TS_VOLTAGE_HVD);
		snprintf(v[2], string_size, LV_FEEDBACK_TS_VOLTAGE_INVC_INTERLOCK);
		snprintf(v[3], string_size, LV_FEEDBACK_TS_VOLTAGE_AMS);

		return 0;
	case 600:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, LV_FEEDBACK_SD_VOLTAGE_SD_END);
		snprintf(v[1], string_size, LV_FEEDBACK_SD_VOLTAGE_LVMS);
		snprintf(v[2], string_size, LV_FEEDBACK_SD_VOLTAGE_INTERLOCK);
		snprintf(v[3], string_size, LV_FEEDBACK_SD_VOLTAGE_SD_START);

		return 0;
	case 608:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, LV_FEEDBACK_ENCLOSURE_VOLTAGE_LV_ENCL);
		snprintf(v[1], string_size, LV_FEEDBACK_ENCLOSURE_VOLTAGE_INVC_LID);
		snprintf(v[2], string_size, LV_FEEDBACK_ENCLOSURE_VOLTAGE_HV_ENCL_2);
		snprintf(v[3], string_size, LV_FEEDBACK_ENCLOSURE_VOLTAGE_BACKPLATE);

		return 0;
	case 616:
		if(10 > fields_size) return 1;
		snprintf(v[0], string_size, LV_FEEDBACK_GPIO_EXTENDER_FEEDBACK_INVERTERS);
		snprintf(v[1], string_size, LV_FEEDBACK_GPIO_EXTENDER_FEEDBACK_PCBS);
		snprintf(v[2], string_size, LV_FEEDBACK_GPIO_EXTENDER_FEEDBACK_PUMPS);
		snprintf(v[3], string_size, LV_FEEDBACK_GPIO_EXTENDER_FEEDBACK_RADIATORS);
		snprintf(v[4], string_size, LV_FEEDBACK_GPIO_EXTENDER_FEEDBACK_SHUTDOWN);
		snprintf(v[5], string_size, LV_FEEDBACK_GPIO_EXTENDER_FEEDBACK_HV_FANS);
		snprintf(v[6], string_size, LV_FEEDBACK_GPIO_EXTENDER_FEEDBACK_AUTONOMOUS_SYSTEM_ACTUATION);
		snprintf(v[7], string_size, LV_FEEDBACK_GPIO_EXTENDER_FEEDBACK_RFE);
		snprintf(v[8], string_size, LV_FEEDBACK_GPIO_EXTENDER_FEEDBACK_FRG);
		snprintf(v[9], string_size, LV_FEEDBACK_GPIO_EXTENDER_FEEDBACK_DISCHARGE);

		return 0;
	case 624:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, LV_INVERTER_CONNECTION_STATUS_STATUS);

		return 0;
	case 80:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, LV_SET_INVERTER_CONNECTION_STATUS_STATUS);

		return 0;
	case 1600:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, TLM_STATUS_STATUS);

		return 0;
	case 1072:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, TLM_SET_STATUS_STATUS);

		return 0;
	case 632:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, HANDCART_STATUS_CONNECTED);

		return 0;
	case 1608:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, HANDCART_SETTINGS_TARGET_VOLTAGE);
		snprintf(v[1], string_size, HANDCART_SETTINGS_FANS_OVERRIDE);
		snprintf(v[2], string_size, HANDCART_SETTINGS_FANS_SPEED);
		snprintf(v[3], string_size, HANDCART_SETTINGS_ACC_CHARGE_CURRENT);
		snprintf(v[4], string_size, HANDCART_SETTINGS_GRID_MAX_CURRENT);
		snprintf(v[5], string_size, HANDCART_SETTINGS_STATUS);

		return 0;
	case 1080:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, HANDCART_SET_SETTINGS_TARGET_VOLTAGE);
		snprintf(v[1], string_size, HANDCART_SET_SETTINGS_FANS_OVERRIDE);
		snprintf(v[2], string_size, HANDCART_SET_SETTINGS_FANS_SPEED);
		snprintf(v[3], string_size, HANDCART_SET_SETTINGS_ACC_CHARGE_CURRENT);
		snprintf(v[4], string_size, HANDCART_SET_SETTINGS_GRID_MAX_CURRENT);
		snprintf(v[5], string_size, HANDCART_SET_SETTINGS_STATUS);

		return 0;
	case 640:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, ECU_STATUS_STATUS);

		return 0;
	case 88:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, ECU_SET_STATUS_STATUS);

		return 0;
	case 1088:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, ECU_INVERTER_STATUS_RL);
		snprintf(v[1], string_size, ECU_INVERTER_STATUS_RR);

		return 0;
	case 648:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, ECU_CONTROL_STATUS_CONTROL_ENABLED);
		snprintf(v[1], string_size, ECU_CONTROL_STATUS_CONTROL_ERRORS_FORCED_OFF);
		snprintf(v[2], string_size, ECU_CONTROL_STATUS_CONTROL_ERRORS_WRONG_MAPS);
		snprintf(v[3], string_size, ECU_CONTROL_STATUS_CONTROL_ERRORS_CONTROL_WATCHDOG);

		return 0;
	case 656:
		if(11 > fields_size) return 1;
		snprintf(v[0], string_size, ECU_ERRORS_ERROR_PEDAL_ADC);
		snprintf(v[1], string_size, ECU_ERRORS_ERROR_PEDAL_IMPLAUSIBILITY);
		snprintf(v[2], string_size, ECU_ERRORS_ERROR_IMU_TOUT);
		snprintf(v[3], string_size, ECU_ERRORS_ERROR_IRTS_TOUT);
		snprintf(v[4], string_size, ECU_ERRORS_ERROR_TS_TOUT);
		snprintf(v[5], string_size, ECU_ERRORS_ERROR_INVL_TOUT);
		snprintf(v[6], string_size, ECU_ERRORS_ERROR_INVR_TOUT);
		snprintf(v[7], string_size, ECU_ERRORS_ERROR_STEER_TOUT);
		snprintf(v[8], string_size, ECU_ERRORS_ERROR_FSM);
		snprintf(v[9], string_size, ECU_ERRORS_ERROR_BSPD_LIMITS);
		snprintf(v[10], string_size, ECU_ERRORS_ERROR_NO_BRAKE_TO_RTD);

		return 0;
	case 664:
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
	case 672:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, ECU_POWER_MAPS_MAP_PW);
		snprintf(v[1], string_size, ECU_POWER_MAPS_MAP_SC);
		snprintf(v[2], string_size, ECU_POWER_MAPS_MAP_TV);

		return 0;
	case 96:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, ECU_SET_POWER_MAPS_MAP_PW);
		snprintf(v[1], string_size, ECU_SET_POWER_MAPS_MAP_SC);
		snprintf(v[2], string_size, ECU_SET_POWER_MAPS_MAP_TV);

		return 0;
	case 1616:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, ECU_PTT_STATUS_STATUS);

		return 0;
	case 1096:
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
	case 680:
		if(5 > fields_size) return 1;
		snprintf(v[0], string_size, CONTROL_OUTPUT_ESTIMATED_VELOCITY);
		snprintf(v[1], string_size, CONTROL_OUTPUT_TORQUE_MAX_L);
		snprintf(v[2], string_size, CONTROL_OUTPUT_TORQUE_MAX_R);
		snprintf(v[3], string_size, CONTROL_OUTPUT_TORQUE_L);
		snprintf(v[4], string_size, CONTROL_OUTPUT_TORQUE_R);

		return 0;
	case 688:
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
	case 1624:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, LV_CURRENT_BATTERY_LV_CURRENT);

		return 0;
	case 1632:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, LV_CURRENT_CHARGER_CHARGER_CURRENT);

		return 0;
	case 1640:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, LV_TOTAL_VOLTAGE_TOTAL);

		return 0;
	case 1648:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, LV_CELLS_VOLTAGE_START_INDEX);
		snprintf(v[1], string_size, LV_CELLS_VOLTAGE_VOLTAGE_0);
		snprintf(v[2], string_size, LV_CELLS_VOLTAGE_VOLTAGE_1);
		snprintf(v[3], string_size, LV_CELLS_VOLTAGE_VOLTAGE_2);

		return 0;
	case 1656:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, LV_CELLS_VOLTAGE_STATS_MAX);
		snprintf(v[1], string_size, LV_CELLS_VOLTAGE_STATS_MIN);
		snprintf(v[2], string_size, LV_CELLS_VOLTAGE_STATS_DELTA);
		snprintf(v[3], string_size, LV_CELLS_VOLTAGE_STATS_AVG);

		return 0;
	case 1664:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, LV_CELLS_TEMP_START_INDEX);
		snprintf(v[1], string_size, LV_CELLS_TEMP_TEMP_0);
		snprintf(v[2], string_size, LV_CELLS_TEMP_TEMP_1);
		snprintf(v[3], string_size, LV_CELLS_TEMP_TEMP_2);

		return 0;
	case 1672:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, LV_CELLS_TEMP_STATS_MAX);
		snprintf(v[1], string_size, LV_CELLS_TEMP_STATS_MIN);
		snprintf(v[2], string_size, LV_CELLS_TEMP_STATS_AVG);

		return 0;
	case 1680:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, HV_CURRENT_CURRENT);

		return 0;
	case 1688:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, HV_POWER_POWER);

		return 0;
	case 1696:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, HV_ENERGY_ENERGY);

		return 0;
	case 1704:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, HV_SOC_SOC);

		return 0;
	case 1712:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, HV_TOTAL_VOLTAGE_PACK);
		snprintf(v[1], string_size, HV_TOTAL_VOLTAGE_SUM_CELL);
		snprintf(v[2], string_size, HV_TOTAL_VOLTAGE_BUS);

		return 0;
	case 1720:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, HV_CELLS_VOLTAGE_START_INDEX);
		snprintf(v[1], string_size, HV_CELLS_VOLTAGE_VOLTAGE_0);
		snprintf(v[2], string_size, HV_CELLS_VOLTAGE_VOLTAGE_1);
		snprintf(v[3], string_size, HV_CELLS_VOLTAGE_VOLTAGE_2);

		return 0;
	case 1728:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, HV_CELLS_VOLTAGE_STATS_MAX);
		snprintf(v[1], string_size, HV_CELLS_VOLTAGE_STATS_MIN);
		snprintf(v[2], string_size, HV_CELLS_VOLTAGE_STATS_DELTA);
		snprintf(v[3], string_size, HV_CELLS_VOLTAGE_STATS_AVG);

		return 0;
	case 1736:
		if(5 > fields_size) return 1;
		snprintf(v[0], string_size, HV_CELLS_TEMP_START_INDEX);
		snprintf(v[1], string_size, HV_CELLS_TEMP_TEMP_0);
		snprintf(v[2], string_size, HV_CELLS_TEMP_TEMP_1);
		snprintf(v[3], string_size, HV_CELLS_TEMP_TEMP_2);
		snprintf(v[4], string_size, HV_CELLS_TEMP_TEMP_3);

		return 0;
	case 1744:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, HV_CELLS_TEMP_STATS_MAX);
		snprintf(v[1], string_size, HV_CELLS_TEMP_STATS_MIN);
		snprintf(v[2], string_size, HV_CELLS_TEMP_STATS_AVG);

		return 0;
	case 1752:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, ECU_STEER_ACTUATOR_STATUS_STATUS);

		return 0;
	case 1104:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, ECU_SET_STEER_ACTUATOR_STATUS_STEERING_WHEEL_STATUS);

		return 0;
	case 1112:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, ECU_SET_STEER_ACTUATOR_STATUS_TLM_STATUS);

		return 0;
	case 1760:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, ECU_SET_STEER_ACTUATOR_ANGLE_ANGLE);

		return 0;
	case 1768:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, ECU_STEER_ACTUATOR_CURRENT_CURRENT);

		return 0;
	case 1776:
		if(8 > fields_size) return 1;
		snprintf(v[0], string_size, DEBUG_SIGNAL_CRASH_DEBUG_SEQ_NUMBER);
		snprintf(v[1], string_size, DEBUG_SIGNAL_CRASH_DEBUG_BYTE_1);
		snprintf(v[2], string_size, DEBUG_SIGNAL_CRASH_DEBUG_BYTE_2);
		snprintf(v[3], string_size, DEBUG_SIGNAL_CRASH_DEBUG_BYTE_3);
		snprintf(v[4], string_size, DEBUG_SIGNAL_CRASH_DEBUG_BYTE_4);
		snprintf(v[5], string_size, DEBUG_SIGNAL_CRASH_DEBUG_BYTE_5);
		snprintf(v[6], string_size, DEBUG_SIGNAL_CRASH_DEBUG_BYTE_6);
		snprintf(v[7], string_size, DEBUG_SIGNAL_CRASH_DEBUG_BYTE_7);

		return 0;
	case 1784:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, DEBUG_SIGNAL_CRASH_DEBUG_ACK_SEQ_NUMBER);

		return 0;
	case 1792:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, DEBUG_SIGNAL_1_DEVICE_ID);
		snprintf(v[1], string_size, DEBUG_SIGNAL_1_FIELD_1);
		snprintf(v[2], string_size, DEBUG_SIGNAL_1_FIELD_2);
		snprintf(v[3], string_size, DEBUG_SIGNAL_1_FIELD_3);

		return 0;
	case 1800:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, DEBUG_SIGNAL_2_DEVICE_ID);
		snprintf(v[1], string_size, DEBUG_SIGNAL_2_FIELD_1);
		snprintf(v[2], string_size, DEBUG_SIGNAL_2_FIELD_2);
		snprintf(v[3], string_size, DEBUG_SIGNAL_2_FIELD_3);

		return 0;
	case 1808:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, DEBUG_SIGNAL_3_DEVICE_ID);
		snprintf(v[1], string_size, DEBUG_SIGNAL_3_FIELD_1);
		snprintf(v[2], string_size, DEBUG_SIGNAL_3_FIELD_2);
		snprintf(v[3], string_size, DEBUG_SIGNAL_3_FIELD_3);

		return 0;
	case 1824:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, DEBUG_SIGNAL_4_DEVICE_ID);
		snprintf(v[1], string_size, DEBUG_SIGNAL_4_FIELD_1);
		snprintf(v[2], string_size, DEBUG_SIGNAL_4_FIELD_2);
		snprintf(v[3], string_size, DEBUG_SIGNAL_4_FIELD_3);

		return 0;
	case 256:
		if(8 > fields_size) return 1;
		snprintf(v[0], string_size, CHARGER_1_DATA_0);
		snprintf(v[1], string_size, CHARGER_1_DATA_1);
		snprintf(v[2], string_size, CHARGER_1_DATA_2);
		snprintf(v[3], string_size, CHARGER_1_DATA_3);
		snprintf(v[4], string_size, CHARGER_1_DATA_4);
		snprintf(v[5], string_size, CHARGER_1_DATA_5);
		snprintf(v[6], string_size, CHARGER_1_DATA_6);
		snprintf(v[7], string_size, CHARGER_1_DATA_7);

		return 0;
	case 272:
		if(8 > fields_size) return 1;
		snprintf(v[0], string_size, CHARGER_2_DATA_0);
		snprintf(v[1], string_size, CHARGER_2_DATA_1);
		snprintf(v[2], string_size, CHARGER_2_DATA_2);
		snprintf(v[3], string_size, CHARGER_2_DATA_3);
		snprintf(v[4], string_size, CHARGER_2_DATA_4);
		snprintf(v[5], string_size, CHARGER_2_DATA_5);
		snprintf(v[6], string_size, CHARGER_2_DATA_6);
		snprintf(v[7], string_size, CHARGER_2_DATA_7);

		return 0;
	case 288:
		if(8 > fields_size) return 1;
		snprintf(v[0], string_size, CHARGER_3_DATA_0);
		snprintf(v[1], string_size, CHARGER_3_DATA_1);
		snprintf(v[2], string_size, CHARGER_3_DATA_2);
		snprintf(v[3], string_size, CHARGER_3_DATA_3);
		snprintf(v[4], string_size, CHARGER_3_DATA_4);
		snprintf(v[5], string_size, CHARGER_3_DATA_5);
		snprintf(v[6], string_size, CHARGER_3_DATA_6);
		snprintf(v[7], string_size, CHARGER_3_DATA_7);

		return 0;
	case 304:
		if(8 > fields_size) return 1;
		snprintf(v[0], string_size, CHARGER_4_DATA_0);
		snprintf(v[1], string_size, CHARGER_4_DATA_1);
		snprintf(v[2], string_size, CHARGER_4_DATA_2);
		snprintf(v[3], string_size, CHARGER_4_DATA_3);
		snprintf(v[4], string_size, CHARGER_4_DATA_4);
		snprintf(v[5], string_size, CHARGER_4_DATA_5);
		snprintf(v[6], string_size, CHARGER_4_DATA_6);
		snprintf(v[7], string_size, CHARGER_4_DATA_7);

		return 0;
	case 320:
		if(8 > fields_size) return 1;
		snprintf(v[0], string_size, CHARGER_5_DATA_0);
		snprintf(v[1], string_size, CHARGER_5_DATA_1);
		snprintf(v[2], string_size, CHARGER_5_DATA_2);
		snprintf(v[3], string_size, CHARGER_5_DATA_3);
		snprintf(v[4], string_size, CHARGER_5_DATA_4);
		snprintf(v[5], string_size, CHARGER_5_DATA_5);
		snprintf(v[6], string_size, CHARGER_5_DATA_6);
		snprintf(v[7], string_size, CHARGER_5_DATA_7);

		return 0;
	case 336:
		if(8 > fields_size) return 1;
		snprintf(v[0], string_size, CHARGER_6_DATA_0);
		snprintf(v[1], string_size, CHARGER_6_DATA_1);
		snprintf(v[2], string_size, CHARGER_6_DATA_2);
		snprintf(v[3], string_size, CHARGER_6_DATA_3);
		snprintf(v[4], string_size, CHARGER_6_DATA_4);
		snprintf(v[5], string_size, CHARGER_6_DATA_5);
		snprintf(v[6], string_size, CHARGER_6_DATA_6);
		snprintf(v[7], string_size, CHARGER_6_DATA_7);

		return 0;
	case 344:
		if(8 > fields_size) return 1;
		snprintf(v[0], string_size, CHARGER_7_DATA_0);
		snprintf(v[1], string_size, CHARGER_7_DATA_1);
		snprintf(v[2], string_size, CHARGER_7_DATA_2);
		snprintf(v[3], string_size, CHARGER_7_DATA_3);
		snprintf(v[4], string_size, CHARGER_7_DATA_4);
		snprintf(v[5], string_size, CHARGER_7_DATA_5);
		snprintf(v[6], string_size, CHARGER_7_DATA_6);
		snprintf(v[7], string_size, CHARGER_7_DATA_7);

		return 0;
	case 352:
		if(8 > fields_size) return 1;
		snprintf(v[0], string_size, CHARGER_8_DATA_0);
		snprintf(v[1], string_size, CHARGER_8_DATA_1);
		snprintf(v[2], string_size, CHARGER_8_DATA_2);
		snprintf(v[3], string_size, CHARGER_8_DATA_3);
		snprintf(v[4], string_size, CHARGER_8_DATA_4);
		snprintf(v[5], string_size, CHARGER_8_DATA_5);
		snprintf(v[6], string_size, CHARGER_8_DATA_6);
		snprintf(v[7], string_size, CHARGER_8_DATA_7);

		return 0;
	case 368:
		if(8 > fields_size) return 1;
		snprintf(v[0], string_size, CHARGER_9_DATA_0);
		snprintf(v[1], string_size, CHARGER_9_DATA_1);
		snprintf(v[2], string_size, CHARGER_9_DATA_2);
		snprintf(v[3], string_size, CHARGER_9_DATA_3);
		snprintf(v[4], string_size, CHARGER_9_DATA_4);
		snprintf(v[5], string_size, CHARGER_9_DATA_5);
		snprintf(v[6], string_size, CHARGER_9_DATA_6);
		snprintf(v[7], string_size, CHARGER_9_DATA_7);

		return 0;
	case 384:
		if(8 > fields_size) return 1;
		snprintf(v[0], string_size, CHARGER_10_DATA_0);
		snprintf(v[1], string_size, CHARGER_10_DATA_1);
		snprintf(v[2], string_size, CHARGER_10_DATA_2);
		snprintf(v[3], string_size, CHARGER_10_DATA_3);
		snprintf(v[4], string_size, CHARGER_10_DATA_4);
		snprintf(v[5], string_size, CHARGER_10_DATA_5);
		snprintf(v[6], string_size, CHARGER_10_DATA_6);
		snprintf(v[7], string_size, CHARGER_10_DATA_7);

		return 0;
	case 392:
		if(8 > fields_size) return 1;
		snprintf(v[0], string_size, CHARGER_11_DATA_0);
		snprintf(v[1], string_size, CHARGER_11_DATA_1);
		snprintf(v[2], string_size, CHARGER_11_DATA_2);
		snprintf(v[3], string_size, CHARGER_11_DATA_3);
		snprintf(v[4], string_size, CHARGER_11_DATA_4);
		snprintf(v[5], string_size, CHARGER_11_DATA_5);
		snprintf(v[6], string_size, CHARGER_11_DATA_6);
		snprintf(v[7], string_size, CHARGER_11_DATA_7);

		return 0;
	case 400:
		if(8 > fields_size) return 1;
		snprintf(v[0], string_size, CHARGER_12_DATA_0);
		snprintf(v[1], string_size, CHARGER_12_DATA_1);
		snprintf(v[2], string_size, CHARGER_12_DATA_2);
		snprintf(v[3], string_size, CHARGER_12_DATA_3);
		snprintf(v[4], string_size, CHARGER_12_DATA_4);
		snprintf(v[5], string_size, CHARGER_12_DATA_5);
		snprintf(v[6], string_size, CHARGER_12_DATA_6);
		snprintf(v[7], string_size, CHARGER_12_DATA_7);

		return 0;
	case 408:
		if(8 > fields_size) return 1;
		snprintf(v[0], string_size, CHARGER_13_DATA_0);
		snprintf(v[1], string_size, CHARGER_13_DATA_1);
		snprintf(v[2], string_size, CHARGER_13_DATA_2);
		snprintf(v[3], string_size, CHARGER_13_DATA_3);
		snprintf(v[4], string_size, CHARGER_13_DATA_4);
		snprintf(v[5], string_size, CHARGER_13_DATA_5);
		snprintf(v[6], string_size, CHARGER_13_DATA_6);
		snprintf(v[7], string_size, CHARGER_13_DATA_7);

		return 0;
	case 416:
		if(8 > fields_size) return 1;
		snprintf(v[0], string_size, CHARGER_14_DATA_0);
		snprintf(v[1], string_size, CHARGER_14_DATA_1);
		snprintf(v[2], string_size, CHARGER_14_DATA_2);
		snprintf(v[3], string_size, CHARGER_14_DATA_3);
		snprintf(v[4], string_size, CHARGER_14_DATA_4);
		snprintf(v[5], string_size, CHARGER_14_DATA_5);
		snprintf(v[6], string_size, CHARGER_14_DATA_6);
		snprintf(v[7], string_size, CHARGER_14_DATA_7);

		return 0;
	case 432:
		if(8 > fields_size) return 1;
		snprintf(v[0], string_size, CHARGER_15_DATA_0);
		snprintf(v[1], string_size, CHARGER_15_DATA_1);
		snprintf(v[2], string_size, CHARGER_15_DATA_2);
		snprintf(v[3], string_size, CHARGER_15_DATA_3);
		snprintf(v[4], string_size, CHARGER_15_DATA_4);
		snprintf(v[5], string_size, CHARGER_15_DATA_5);
		snprintf(v[6], string_size, CHARGER_15_DATA_6);
		snprintf(v[7], string_size, CHARGER_15_DATA_7);

		return 0;
	case 448:
		if(8 > fields_size) return 1;
		snprintf(v[0], string_size, CHARGER_16_DATA_0);
		snprintf(v[1], string_size, CHARGER_16_DATA_1);
		snprintf(v[2], string_size, CHARGER_16_DATA_2);
		snprintf(v[3], string_size, CHARGER_16_DATA_3);
		snprintf(v[4], string_size, CHARGER_16_DATA_4);
		snprintf(v[5], string_size, CHARGER_16_DATA_5);
		snprintf(v[6], string_size, CHARGER_16_DATA_6);
		snprintf(v[7], string_size, CHARGER_16_DATA_7);

		return 0;
	case 464:
		if(8 > fields_size) return 1;
		snprintf(v[0], string_size, CHARGER_17_DATA_0);
		snprintf(v[1], string_size, CHARGER_17_DATA_1);
		snprintf(v[2], string_size, CHARGER_17_DATA_2);
		snprintf(v[3], string_size, CHARGER_17_DATA_3);
		snprintf(v[4], string_size, CHARGER_17_DATA_4);
		snprintf(v[5], string_size, CHARGER_17_DATA_5);
		snprintf(v[6], string_size, CHARGER_17_DATA_6);
		snprintf(v[7], string_size, CHARGER_17_DATA_7);

		return 0;
	case 480:
		if(8 > fields_size) return 1;
		snprintf(v[0], string_size, CHARGER_18_DATA_0);
		snprintf(v[1], string_size, CHARGER_18_DATA_1);
		snprintf(v[2], string_size, CHARGER_18_DATA_2);
		snprintf(v[3], string_size, CHARGER_18_DATA_3);
		snprintf(v[4], string_size, CHARGER_18_DATA_4);
		snprintf(v[5], string_size, CHARGER_18_DATA_5);
		snprintf(v[6], string_size, CHARGER_18_DATA_6);
		snprintf(v[7], string_size, CHARGER_18_DATA_7);

		return 0;
	case 496:
		if(8 > fields_size) return 1;
		snprintf(v[0], string_size, CHARGER_19_DATA_0);
		snprintf(v[1], string_size, CHARGER_19_DATA_1);
		snprintf(v[2], string_size, CHARGER_19_DATA_2);
		snprintf(v[3], string_size, CHARGER_19_DATA_3);
		snprintf(v[4], string_size, CHARGER_19_DATA_4);
		snprintf(v[5], string_size, CHARGER_19_DATA_5);
		snprintf(v[6], string_size, CHARGER_19_DATA_6);
		snprintf(v[7], string_size, CHARGER_19_DATA_7);

		return 0;

    }
    return 0;
}
int primary_enum_fields(int enum_id, char **v, size_t fields_size, size_t string_size)
{
    switch(enum_id)
    {
	case 0:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_jmp_to_blt_forward_off");
		snprintf(v[1], string_size, "primary_hv_jmp_to_blt_forward_on");

		return 0;
	case 1:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_jmp_to_blt_cellboard_id_cellboard_0");
		snprintf(v[1], string_size, "primary_hv_jmp_to_blt_cellboard_id_cellboard_1");
		snprintf(v[2], string_size, "primary_hv_jmp_to_blt_cellboard_id_cellboard_2");
		snprintf(v[3], string_size, "primary_hv_jmp_to_blt_cellboard_id_cellboard_3");
		snprintf(v[4], string_size, "primary_hv_jmp_to_blt_cellboard_id_cellboard_4");
		snprintf(v[5], string_size, "primary_hv_jmp_to_blt_cellboard_id_cellboard_5");

		return 0;
	case 2:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_cellboard_version_cellboard_id_cellboard_0");
		snprintf(v[1], string_size, "primary_hv_cellboard_version_cellboard_id_cellboard_1");
		snprintf(v[2], string_size, "primary_hv_cellboard_version_cellboard_id_cellboard_2");
		snprintf(v[3], string_size, "primary_hv_cellboard_version_cellboard_id_cellboard_3");
		snprintf(v[4], string_size, "primary_hv_cellboard_version_cellboard_id_cellboard_4");
		snprintf(v[5], string_size, "primary_hv_cellboard_version_cellboard_id_cellboard_5");

		return 0;
	case 3:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_fans_status_fans_override_off");
		snprintf(v[1], string_size, "primary_hv_fans_status_fans_override_on");

		return 0;
	case 4:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_set_fans_status_fans_override_off");
		snprintf(v[1], string_size, "primary_hv_set_fans_status_fans_override_on");

		return 0;
	case 5:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_feedback_implausibility_detected_feedback_state_low");
		snprintf(v[1], string_size, "primary_hv_feedback_status_feedback_implausibility_detected_feedback_state_error");
		snprintf(v[2], string_size, "primary_hv_feedback_status_feedback_implausibility_detected_feedback_state_high");

		return 0;
	case 6:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_feedback_imd_cockpit_feedback_state_low");
		snprintf(v[1], string_size, "primary_hv_feedback_status_feedback_imd_cockpit_feedback_state_error");
		snprintf(v[2], string_size, "primary_hv_feedback_status_feedback_imd_cockpit_feedback_state_high");

		return 0;
	case 7:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_feedback_tsal_green_fault_latched_feedback_state_low");
		snprintf(v[1], string_size, "primary_hv_feedback_status_feedback_tsal_green_fault_latched_feedback_state_error");
		snprintf(v[2], string_size, "primary_hv_feedback_status_feedback_tsal_green_fault_latched_feedback_state_high");

		return 0;
	case 8:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_feedback_bms_cockpit_feedback_state_low");
		snprintf(v[1], string_size, "primary_hv_feedback_status_feedback_bms_cockpit_feedback_state_error");
		snprintf(v[2], string_size, "primary_hv_feedback_status_feedback_bms_cockpit_feedback_state_high");

		return 0;
	case 9:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_feedback_ext_latched_feedback_state_low");
		snprintf(v[1], string_size, "primary_hv_feedback_status_feedback_ext_latched_feedback_state_error");
		snprintf(v[2], string_size, "primary_hv_feedback_status_feedback_ext_latched_feedback_state_high");

		return 0;
	case 10:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_feedback_tsal_green_feedback_state_low");
		snprintf(v[1], string_size, "primary_hv_feedback_status_feedback_tsal_green_feedback_state_error");
		snprintf(v[2], string_size, "primary_hv_feedback_status_feedback_tsal_green_feedback_state_high");

		return 0;
	case 11:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_feedback_ts_over_60v_status_feedback_state_low");
		snprintf(v[1], string_size, "primary_hv_feedback_status_feedback_ts_over_60v_status_feedback_state_error");
		snprintf(v[2], string_size, "primary_hv_feedback_status_feedback_ts_over_60v_status_feedback_state_high");

		return 0;
	case 12:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_feedback_airn_status_feedback_state_low");
		snprintf(v[1], string_size, "primary_hv_feedback_status_feedback_airn_status_feedback_state_error");
		snprintf(v[2], string_size, "primary_hv_feedback_status_feedback_airn_status_feedback_state_high");

		return 0;
	case 13:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_feedback_airp_status_feedback_state_low");
		snprintf(v[1], string_size, "primary_hv_feedback_status_feedback_airp_status_feedback_state_error");
		snprintf(v[2], string_size, "primary_hv_feedback_status_feedback_airp_status_feedback_state_high");

		return 0;
	case 14:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_feedback_airp_gate_feedback_state_low");
		snprintf(v[1], string_size, "primary_hv_feedback_status_feedback_airp_gate_feedback_state_error");
		snprintf(v[2], string_size, "primary_hv_feedback_status_feedback_airp_gate_feedback_state_high");

		return 0;
	case 15:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_feedback_airn_gate_feedback_state_low");
		snprintf(v[1], string_size, "primary_hv_feedback_status_feedback_airn_gate_feedback_state_error");
		snprintf(v[2], string_size, "primary_hv_feedback_status_feedback_airn_gate_feedback_state_high");

		return 0;
	case 16:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_feedback_precharge_status_feedback_state_low");
		snprintf(v[1], string_size, "primary_hv_feedback_status_feedback_precharge_status_feedback_state_error");
		snprintf(v[2], string_size, "primary_hv_feedback_status_feedback_precharge_status_feedback_state_high");

		return 0;
	case 17:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_feedback_tsp_over_60v_status_feedback_state_low");
		snprintf(v[1], string_size, "primary_hv_feedback_status_feedback_tsp_over_60v_status_feedback_state_error");
		snprintf(v[2], string_size, "primary_hv_feedback_status_feedback_tsp_over_60v_status_feedback_state_high");

		return 0;
	case 18:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_feedback_imd_fault_feedback_state_low");
		snprintf(v[1], string_size, "primary_hv_feedback_status_feedback_imd_fault_feedback_state_error");
		snprintf(v[2], string_size, "primary_hv_feedback_status_feedback_imd_fault_feedback_state_high");

		return 0;
	case 19:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_feedback_check_mux_feedback_state_low");
		snprintf(v[1], string_size, "primary_hv_feedback_status_feedback_check_mux_feedback_state_error");
		snprintf(v[2], string_size, "primary_hv_feedback_status_feedback_check_mux_feedback_state_high");

		return 0;
	case 20:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_feedback_sd_end_feedback_state_low");
		snprintf(v[1], string_size, "primary_hv_feedback_status_feedback_sd_end_feedback_state_error");
		snprintf(v[2], string_size, "primary_hv_feedback_status_feedback_sd_end_feedback_state_high");

		return 0;
	case 21:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_feedback_sd_out_feedback_state_low");
		snprintf(v[1], string_size, "primary_hv_feedback_status_feedback_sd_out_feedback_state_error");
		snprintf(v[2], string_size, "primary_hv_feedback_status_feedback_sd_out_feedback_state_high");

		return 0;
	case 22:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_feedback_sd_in_feedback_state_low");
		snprintf(v[1], string_size, "primary_hv_feedback_status_feedback_sd_in_feedback_state_error");
		snprintf(v[2], string_size, "primary_hv_feedback_status_feedback_sd_in_feedback_state_high");

		return 0;
	case 23:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_feedback_sd_bms_feedback_state_low");
		snprintf(v[1], string_size, "primary_hv_feedback_status_feedback_sd_bms_feedback_state_error");
		snprintf(v[2], string_size, "primary_hv_feedback_status_feedback_sd_bms_feedback_state_high");

		return 0;
	case 24:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_feedback_sd_imd_feedback_state_low");
		snprintf(v[1], string_size, "primary_hv_feedback_status_feedback_sd_imd_feedback_state_error");
		snprintf(v[2], string_size, "primary_hv_feedback_status_feedback_sd_imd_feedback_state_high");

		return 0;
	case 25:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_imd_status_imd_status_sc");
		snprintf(v[1], string_size, "primary_hv_imd_status_imd_status_normal");
		snprintf(v[2], string_size, "primary_hv_imd_status_imd_status_under_voltage");
		snprintf(v[3], string_size, "primary_hv_imd_status_imd_status_start_measure");
		snprintf(v[4], string_size, "primary_hv_imd_status_imd_status_device_error");
		snprintf(v[5], string_size, "primary_hv_imd_status_imd_status_earth_fault");

		return 0;
	case 26:
		if(7 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_status_status_init");
		snprintf(v[1], string_size, "primary_hv_status_status_idle");
		snprintf(v[2], string_size, "primary_hv_status_status_airn_close");
		snprintf(v[3], string_size, "primary_hv_status_status_precharge");
		snprintf(v[4], string_size, "primary_hv_status_status_airp_close");
		snprintf(v[5], string_size, "primary_hv_status_status_ts_on");
		snprintf(v[6], string_size, "primary_hv_status_status_fatal_error");

		return 0;
	case 27:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_set_status_ecu_hv_status_set_off");
		snprintf(v[1], string_size, "primary_hv_set_status_ecu_hv_status_set_on");

		return 0;
	case 28:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_set_status_handcart_hv_status_set_off");
		snprintf(v[1], string_size, "primary_hv_set_status_handcart_hv_status_set_on");

		return 0;
	case 29:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_balancing_status_cellboard_id_cellboard_0");
		snprintf(v[1], string_size, "primary_hv_balancing_status_cellboard_id_cellboard_1");
		snprintf(v[2], string_size, "primary_hv_balancing_status_cellboard_id_cellboard_2");
		snprintf(v[3], string_size, "primary_hv_balancing_status_cellboard_id_cellboard_3");
		snprintf(v[4], string_size, "primary_hv_balancing_status_cellboard_id_cellboard_4");
		snprintf(v[5], string_size, "primary_hv_balancing_status_cellboard_id_cellboard_5");

		return 0;
	case 30:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_balancing_status_balancing_status_off");
		snprintf(v[1], string_size, "primary_hv_balancing_status_balancing_status_on");

		return 0;
	case 31:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_set_balancing_status_handcart_set_balancing_status_off");
		snprintf(v[1], string_size, "primary_hv_set_balancing_status_handcart_set_balancing_status_on");

		return 0;
	case 32:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_set_balancing_status_steering_wheel_set_balancing_status_off");
		snprintf(v[1], string_size, "primary_hv_set_balancing_status_steering_wheel_set_balancing_status_on");

		return 0;
	case 33:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_lv_status_status_init");
		snprintf(v[1], string_size, "primary_lv_status_status_idle");
		snprintf(v[2], string_size, "primary_lv_status_status_tson");
		snprintf(v[3], string_size, "primary_lv_status_status_run");
		snprintf(v[4], string_size, "primary_lv_status_status_flashing");
		snprintf(v[5], string_size, "primary_lv_status_status_error");

		return 0;
	case 34:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_lv_charging_status_status_off");
		snprintf(v[1], string_size, "primary_lv_charging_status_status_on");

		return 0;
	case 35:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_lv_cooling_aggressiveness_status_weak");
		snprintf(v[1], string_size, "primary_lv_cooling_aggressiveness_status_normal");
		snprintf(v[2], string_size, "primary_lv_cooling_aggressiveness_status_aggressive");

		return 0;
	case 36:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_lv_set_cooling_aggressiveness_status_weak");
		snprintf(v[1], string_size, "primary_lv_set_cooling_aggressiveness_status_normal");
		snprintf(v[2], string_size, "primary_lv_set_cooling_aggressiveness_status_aggressive");

		return 0;
	case 37:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_lv_radiator_speed_status_off");
		snprintf(v[1], string_size, "primary_lv_radiator_speed_status_auto");
		snprintf(v[2], string_size, "primary_lv_radiator_speed_status_manual");

		return 0;
	case 38:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_lv_pumps_speed_status_off");
		snprintf(v[1], string_size, "primary_lv_pumps_speed_status_auto");
		snprintf(v[2], string_size, "primary_lv_pumps_speed_status_manual");

		return 0;
	case 39:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_lv_set_radiator_speed_status_off");
		snprintf(v[1], string_size, "primary_lv_set_radiator_speed_status_auto");
		snprintf(v[2], string_size, "primary_lv_set_radiator_speed_status_manual");

		return 0;
	case 40:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_lv_set_pumps_speed_status_off");
		snprintf(v[1], string_size, "primary_lv_set_pumps_speed_status_auto");
		snprintf(v[2], string_size, "primary_lv_set_pumps_speed_status_manual");

		return 0;
	case 41:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_lv_inverter_connection_status_status_off");
		snprintf(v[1], string_size, "primary_lv_inverter_connection_status_status_on");

		return 0;
	case 42:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_lv_set_inverter_connection_status_status_off");
		snprintf(v[1], string_size, "primary_lv_set_inverter_connection_status_status_on");

		return 0;
	case 43:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_tlm_status_status_off");
		snprintf(v[1], string_size, "primary_tlm_status_status_on");

		return 0;
	case 44:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_tlm_set_status_status_off");
		snprintf(v[1], string_size, "primary_tlm_set_status_status_on");

		return 0;
	case 45:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_handcart_status_connected_off");
		snprintf(v[1], string_size, "primary_handcart_status_connected_on");

		return 0;
	case 46:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_handcart_settings_fans_override_off");
		snprintf(v[1], string_size, "primary_handcart_settings_fans_override_on");

		return 0;
	case 47:
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
	case 48:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_handcart_set_settings_fans_override_off");
		snprintf(v[1], string_size, "primary_handcart_set_settings_fans_override_on");

		return 0;
	case 49:
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
	case 50:
		if(14 > fields_size) return 1;
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
		snprintf(v[11], string_size, "primary_ecu_status_status_re_enable_inverter_drive");
		snprintf(v[12], string_size, "primary_ecu_status_status_wait_ts_discharge");
		snprintf(v[13], string_size, "primary_ecu_status_status_fatal_error");

		return 0;
	case 51:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ecu_set_status_status_idle");
		snprintf(v[1], string_size, "primary_ecu_set_status_status_ready");
		snprintf(v[2], string_size, "primary_ecu_set_status_status_drive");

		return 0;
	case 52:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ecu_inverter_status_rl_disabled");
		snprintf(v[1], string_size, "primary_ecu_inverter_status_rl_rfe_on");
		snprintf(v[2], string_size, "primary_ecu_inverter_status_rl_frg_on");
		snprintf(v[3], string_size, "primary_ecu_inverter_status_rl_enabled");

		return 0;
	case 53:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ecu_inverter_status_rr_disabled");
		snprintf(v[1], string_size, "primary_ecu_inverter_status_rr_rfe_on");
		snprintf(v[2], string_size, "primary_ecu_inverter_status_rr_frg_on");
		snprintf(v[3], string_size, "primary_ecu_inverter_status_rr_enabled");

		return 0;
	case 54:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ecu_ptt_status_status_off");
		snprintf(v[1], string_size, "primary_ecu_ptt_status_status_on");

		return 0;
	case 55:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ecu_set_ptt_status_status_off");
		snprintf(v[1], string_size, "primary_ecu_set_ptt_status_status_on");

		return 0;
	case 56:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ecu_steer_actuator_status_status_off");
		snprintf(v[1], string_size, "primary_ecu_steer_actuator_status_status_on");

		return 0;
	case 57:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ecu_set_steer_actuator_status_steering_wheel_status_off");
		snprintf(v[1], string_size, "primary_ecu_set_steer_actuator_status_steering_wheel_status_on");

		return 0;
	case 58:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ecu_set_steer_actuator_status_tlm_status_off");
		snprintf(v[1], string_size, "primary_ecu_set_steer_actuator_status_tlm_status_on");

		return 0;
	case 59:
		if(9 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_debug_signal_1_device_id_hv_mainboard");
		snprintf(v[1], string_size, "primary_debug_signal_1_device_id_hv_cellboard");
		snprintf(v[2], string_size, "primary_debug_signal_1_device_id_lv");
		snprintf(v[3], string_size, "primary_debug_signal_1_device_id_ecu");
		snprintf(v[4], string_size, "primary_debug_signal_1_device_id_tlm");
		snprintf(v[5], string_size, "primary_debug_signal_1_device_id_traction_control");
		snprintf(v[6], string_size, "primary_debug_signal_1_device_id_steeering_wheel");
		snprintf(v[7], string_size, "primary_debug_signal_1_device_id_handcart");
		snprintf(v[8], string_size, "primary_debug_signal_1_device_id_acquisinator");

		return 0;
	case 60:
		if(9 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_debug_signal_2_device_id_hv_mainboard");
		snprintf(v[1], string_size, "primary_debug_signal_2_device_id_hv_cellboard");
		snprintf(v[2], string_size, "primary_debug_signal_2_device_id_lv");
		snprintf(v[3], string_size, "primary_debug_signal_2_device_id_ecu");
		snprintf(v[4], string_size, "primary_debug_signal_2_device_id_tlm");
		snprintf(v[5], string_size, "primary_debug_signal_2_device_id_traction_control");
		snprintf(v[6], string_size, "primary_debug_signal_2_device_id_steeering_wheel");
		snprintf(v[7], string_size, "primary_debug_signal_2_device_id_handcart");
		snprintf(v[8], string_size, "primary_debug_signal_2_device_id_acquisinator");

		return 0;
	case 61:
		if(9 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_debug_signal_3_device_id_hv_mainboard");
		snprintf(v[1], string_size, "primary_debug_signal_3_device_id_hv_cellboard");
		snprintf(v[2], string_size, "primary_debug_signal_3_device_id_lv");
		snprintf(v[3], string_size, "primary_debug_signal_3_device_id_ecu");
		snprintf(v[4], string_size, "primary_debug_signal_3_device_id_tlm");
		snprintf(v[5], string_size, "primary_debug_signal_3_device_id_traction_control");
		snprintf(v[6], string_size, "primary_debug_signal_3_device_id_steeering_wheel");
		snprintf(v[7], string_size, "primary_debug_signal_3_device_id_handcart");
		snprintf(v[8], string_size, "primary_debug_signal_3_device_id_acquisinator");

		return 0;
	case 62:
		if(9 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_debug_signal_4_device_id_hv_mainboard");
		snprintf(v[1], string_size, "primary_debug_signal_4_device_id_hv_cellboard");
		snprintf(v[2], string_size, "primary_debug_signal_4_device_id_lv");
		snprintf(v[3], string_size, "primary_debug_signal_4_device_id_ecu");
		snprintf(v[4], string_size, "primary_debug_signal_4_device_id_tlm");
		snprintf(v[5], string_size, "primary_debug_signal_4_device_id_traction_control");
		snprintf(v[6], string_size, "primary_debug_signal_4_device_id_steeering_wheel");
		snprintf(v[7], string_size, "primary_debug_signal_4_device_id_handcart");
		snprintf(v[8], string_size, "primary_debug_signal_4_device_id_acquisinator");

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
	case 0:
	{
		primary_hv_jmp_to_blt_t tmp;
		primary_hv_jmp_to_blt_converted_t tmp_converted;
		uint8_t r_forward;
		uint8_t r_cellboard_id;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  ,
			&r_forward,
			&r_cellboard_id);
		tmp_converted.forward = (primary_hv_jmp_to_blt_forward)r_forward;
		tmp_converted.cellboard_id = (primary_hv_jmp_to_blt_cellboard_id)r_cellboard_id;

		primary_hv_jmp_to_blt_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_HV_JMP_TO_BLT_BYTE_SIZE;
		return primary_hv_jmp_to_blt_pack(data, &tmp, PRIMARY_HV_JMP_TO_BLT_BYTE_SIZE);
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
	case 32:
	{
		primary_hv_errors_t tmp;
		primary_hv_errors_converted_t tmp_converted;
		uint8_t r_errors_cell_under_voltage;
		uint8_t r_errors_cell_over_voltage;
		uint8_t r_errors_cell_under_temperature;
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
			"%" SCNu8 ","  ,
			&r_errors_cell_under_voltage,
			&r_errors_cell_over_voltage,
			&r_errors_cell_under_temperature,
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
		tmp_converted.errors_cell_under_voltage = (uint8_t)r_errors_cell_under_voltage;
		tmp_converted.errors_cell_over_voltage = (uint8_t)r_errors_cell_over_voltage;
		tmp_converted.errors_cell_under_temperature = (uint8_t)r_errors_cell_under_temperature;
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
		uint8_t r_errors_cell_under_voltage;
		uint8_t r_errors_cell_over_voltage;
		uint8_t r_errors_cell_under_temperature;
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
			&r_errors_cell_under_voltage,
			&r_errors_cell_over_voltage,
			&r_errors_cell_under_temperature,
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
		tmp_converted.errors_cell_under_voltage = (uint8_t)r_errors_cell_under_voltage;
		tmp_converted.errors_cell_over_voltage = (uint8_t)r_errors_cell_over_voltage;
		tmp_converted.errors_cell_under_temperature = (uint8_t)r_errors_cell_under_temperature;
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
		uint8_t r_feedback_implausibility_detected;
		uint8_t r_feedback_imd_cockpit;
		uint8_t r_feedback_tsal_green_fault_latched;
		uint8_t r_feedback_bms_cockpit;
		uint8_t r_feedback_ext_latched;
		uint8_t r_feedback_tsal_green;
		uint8_t r_feedback_ts_over_60v_status;
		uint8_t r_feedback_airn_status;
		uint8_t r_feedback_airp_status;
		uint8_t r_feedback_airp_gate;
		uint8_t r_feedback_airn_gate;
		uint8_t r_feedback_precharge_status;
		uint8_t r_feedback_tsp_over_60v_status;
		uint8_t r_feedback_imd_fault;
		uint8_t r_feedback_check_mux;
		uint8_t r_feedback_sd_end;
		uint8_t r_feedback_sd_out;
		uint8_t r_feedback_sd_in;
		uint8_t r_feedback_sd_bms;
		uint8_t r_feedback_sd_imd;

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
			&r_feedback_implausibility_detected,
			&r_feedback_imd_cockpit,
			&r_feedback_tsal_green_fault_latched,
			&r_feedback_bms_cockpit,
			&r_feedback_ext_latched,
			&r_feedback_tsal_green,
			&r_feedback_ts_over_60v_status,
			&r_feedback_airn_status,
			&r_feedback_airp_status,
			&r_feedback_airp_gate,
			&r_feedback_airn_gate,
			&r_feedback_precharge_status,
			&r_feedback_tsp_over_60v_status,
			&r_feedback_imd_fault,
			&r_feedback_check_mux,
			&r_feedback_sd_end,
			&r_feedback_sd_out,
			&r_feedback_sd_in,
			&r_feedback_sd_bms,
			&r_feedback_sd_imd);
		tmp_converted.feedback_implausibility_detected = (primary_hv_feedback_status_feedback_implausibility_detected)r_feedback_implausibility_detected;
		tmp_converted.feedback_imd_cockpit = (primary_hv_feedback_status_feedback_imd_cockpit)r_feedback_imd_cockpit;
		tmp_converted.feedback_tsal_green_fault_latched = (primary_hv_feedback_status_feedback_tsal_green_fault_latched)r_feedback_tsal_green_fault_latched;
		tmp_converted.feedback_bms_cockpit = (primary_hv_feedback_status_feedback_bms_cockpit)r_feedback_bms_cockpit;
		tmp_converted.feedback_ext_latched = (primary_hv_feedback_status_feedback_ext_latched)r_feedback_ext_latched;
		tmp_converted.feedback_tsal_green = (primary_hv_feedback_status_feedback_tsal_green)r_feedback_tsal_green;
		tmp_converted.feedback_ts_over_60v_status = (primary_hv_feedback_status_feedback_ts_over_60v_status)r_feedback_ts_over_60v_status;
		tmp_converted.feedback_airn_status = (primary_hv_feedback_status_feedback_airn_status)r_feedback_airn_status;
		tmp_converted.feedback_airp_status = (primary_hv_feedback_status_feedback_airp_status)r_feedback_airp_status;
		tmp_converted.feedback_airp_gate = (primary_hv_feedback_status_feedback_airp_gate)r_feedback_airp_gate;
		tmp_converted.feedback_airn_gate = (primary_hv_feedback_status_feedback_airn_gate)r_feedback_airn_gate;
		tmp_converted.feedback_precharge_status = (primary_hv_feedback_status_feedback_precharge_status)r_feedback_precharge_status;
		tmp_converted.feedback_tsp_over_60v_status = (primary_hv_feedback_status_feedback_tsp_over_60v_status)r_feedback_tsp_over_60v_status;
		tmp_converted.feedback_imd_fault = (primary_hv_feedback_status_feedback_imd_fault)r_feedback_imd_fault;
		tmp_converted.feedback_check_mux = (primary_hv_feedback_status_feedback_check_mux)r_feedback_check_mux;
		tmp_converted.feedback_sd_end = (primary_hv_feedback_status_feedback_sd_end)r_feedback_sd_end;
		tmp_converted.feedback_sd_out = (primary_hv_feedback_status_feedback_sd_out)r_feedback_sd_out;
		tmp_converted.feedback_sd_in = (primary_hv_feedback_status_feedback_sd_in)r_feedback_sd_in;
		tmp_converted.feedback_sd_bms = (primary_hv_feedback_status_feedback_sd_bms)r_feedback_sd_bms;
		tmp_converted.feedback_sd_imd = (primary_hv_feedback_status_feedback_sd_imd)r_feedback_sd_imd;

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
		float r_implausibility_detected;
		float r_imd_cockpit;
		float r_tsal_green_fault_latched;
		float r_bms_cockpit;
		float r_ext_latched;
		float r_tsal_green;
		float r_imd_fault;
		float r_check_mux;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       
			"%f,"       
			"%f,"       
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_implausibility_detected,
			&r_imd_cockpit,
			&r_tsal_green_fault_latched,
			&r_bms_cockpit,
			&r_ext_latched,
			&r_tsal_green,
			&r_imd_fault,
			&r_check_mux);
		tmp_converted.implausibility_detected = (float)r_implausibility_detected;
		tmp_converted.imd_cockpit = (float)r_imd_cockpit;
		tmp_converted.tsal_green_fault_latched = (float)r_tsal_green_fault_latched;
		tmp_converted.bms_cockpit = (float)r_bms_cockpit;
		tmp_converted.ext_latched = (float)r_ext_latched;
		tmp_converted.tsal_green = (float)r_tsal_green;
		tmp_converted.imd_fault = (float)r_imd_fault;
		tmp_converted.check_mux = (float)r_check_mux;

		primary_hv_feedback_misc_voltage_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_HV_FEEDBACK_MISC_VOLTAGE_BYTE_SIZE;
		return primary_hv_feedback_misc_voltage_pack(data, &tmp, PRIMARY_HV_FEEDBACK_MISC_VOLTAGE_BYTE_SIZE);
	}
	case 544:
	{
		primary_hv_feedback_sd_voltage_t tmp;
		primary_hv_feedback_sd_voltage_converted_t tmp_converted;
		float r_sd_end;
		float r_sd_out;
		float r_sd_in;
		float r_sd_bms;
		float r_sd_imd;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_sd_end,
			&r_sd_out,
			&r_sd_in,
			&r_sd_bms,
			&r_sd_imd);
		tmp_converted.sd_end = (float)r_sd_end;
		tmp_converted.sd_out = (float)r_sd_out;
		tmp_converted.sd_in = (float)r_sd_in;
		tmp_converted.sd_bms = (float)r_sd_bms;
		tmp_converted.sd_imd = (float)r_sd_imd;

		primary_hv_feedback_sd_voltage_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_HV_FEEDBACK_SD_VOLTAGE_BYTE_SIZE;
		return primary_hv_feedback_sd_voltage_pack(data, &tmp, PRIMARY_HV_FEEDBACK_SD_VOLTAGE_BYTE_SIZE);
	}
	case 552:
	{
		primary_hv_imd_status_t tmp;
		primary_hv_imd_status_converted_t tmp_converted;
		uint8_t r_imd_fault;
		uint8_t r_imd_status;
		uint16_t r_imd_details;
		uint8_t r_imd_duty_cycle;
		uint8_t r_imd_freq;
		uint8_t r_imd_period;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu16 "," 
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  ,
			&r_imd_fault,
			&r_imd_status,
			&r_imd_details,
			&r_imd_duty_cycle,
			&r_imd_freq,
			&r_imd_period);
		tmp_converted.imd_fault = (uint8_t)r_imd_fault;
		tmp_converted.imd_status = (primary_hv_imd_status_imd_status)r_imd_status;
		tmp_converted.imd_details = (uint16_t)r_imd_details;
		tmp_converted.imd_duty_cycle = (uint8_t)r_imd_duty_cycle;
		tmp_converted.imd_freq = (uint8_t)r_imd_freq;
		tmp_converted.imd_period = (uint8_t)r_imd_period;

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
	case 40:
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
	case 48:
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
		primary_hv_set_balancing_status_handcart_t tmp;
		primary_hv_set_balancing_status_handcart_converted_t tmp_converted;
		uint8_t r_set_balancing_status;
		uint8_t r_balancing_threshold;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  ,
			&r_set_balancing_status,
			&r_balancing_threshold);
		tmp_converted.set_balancing_status = (primary_hv_set_balancing_status_handcart_set_balancing_status)r_set_balancing_status;
		tmp_converted.balancing_threshold = (uint8_t)r_balancing_threshold;

		primary_hv_set_balancing_status_handcart_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_HV_SET_BALANCING_STATUS_HANDCART_BYTE_SIZE;
		return primary_hv_set_balancing_status_handcart_pack(data, &tmp, PRIMARY_HV_SET_BALANCING_STATUS_HANDCART_BYTE_SIZE);
	}
	case 1040:
	{
		primary_hv_set_balancing_status_steering_wheel_t tmp;
		primary_hv_set_balancing_status_steering_wheel_converted_t tmp_converted;
		uint8_t r_set_balancing_status;
		uint8_t r_balancing_threshold;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  ,
			&r_set_balancing_status,
			&r_balancing_threshold);
		tmp_converted.set_balancing_status = (primary_hv_set_balancing_status_steering_wheel_set_balancing_status)r_set_balancing_status;
		tmp_converted.balancing_threshold = (uint8_t)r_balancing_threshold;

		primary_hv_set_balancing_status_steering_wheel_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_HV_SET_BALANCING_STATUS_STEERING_WHEEL_BYTE_SIZE;
		return primary_hv_set_balancing_status_steering_wheel_pack(data, &tmp, PRIMARY_HV_SET_BALANCING_STATUS_STEERING_WHEEL_BYTE_SIZE);
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
		primary_lv_charging_status_t tmp;
		primary_lv_charging_status_converted_t tmp_converted;
		uint8_t r_status;

		sscanf(s, "%" SCNu8 ","  ,
			&r_status);
		tmp_converted.status = (primary_lv_charging_status_status)r_status;

		primary_lv_charging_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_LV_CHARGING_STATUS_BYTE_SIZE;
		return primary_lv_charging_status_pack(data, &tmp, PRIMARY_LV_CHARGING_STATUS_BYTE_SIZE);
	}
	case 1576:
	{
		primary_lv_cooling_aggressiveness_t tmp;
		primary_lv_cooling_aggressiveness_converted_t tmp_converted;
		uint8_t r_status;

		sscanf(s, "%" SCNu8 ","  ,
			&r_status);
		tmp_converted.status = (primary_lv_cooling_aggressiveness_status)r_status;

		primary_lv_cooling_aggressiveness_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_LV_COOLING_AGGRESSIVENESS_BYTE_SIZE;
		return primary_lv_cooling_aggressiveness_pack(data, &tmp, PRIMARY_LV_COOLING_AGGRESSIVENESS_BYTE_SIZE);
	}
	case 1048:
	{
		primary_lv_set_cooling_aggressiveness_t tmp;
		primary_lv_set_cooling_aggressiveness_converted_t tmp_converted;
		uint8_t r_status;

		sscanf(s, "%" SCNu8 ","  ,
			&r_status);
		tmp_converted.status = (primary_lv_set_cooling_aggressiveness_status)r_status;

		primary_lv_set_cooling_aggressiveness_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_LV_SET_COOLING_AGGRESSIVENESS_BYTE_SIZE;
		return primary_lv_set_cooling_aggressiveness_pack(data, &tmp, PRIMARY_LV_SET_COOLING_AGGRESSIVENESS_BYTE_SIZE);
	}
	case 1584:
	{
		primary_lv_radiator_speed_t tmp;
		primary_lv_radiator_speed_converted_t tmp_converted;
		uint8_t r_status;
		float r_radiator_speed;

		sscanf(s, "%" SCNu8 ","  
			"%f,"       ,
			&r_status,
			&r_radiator_speed);
		tmp_converted.status = (primary_lv_radiator_speed_status)r_status;
		tmp_converted.radiator_speed = (float)r_radiator_speed;

		primary_lv_radiator_speed_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_LV_RADIATOR_SPEED_BYTE_SIZE;
		return primary_lv_radiator_speed_pack(data, &tmp, PRIMARY_LV_RADIATOR_SPEED_BYTE_SIZE);
	}
	case 1592:
	{
		primary_lv_pumps_speed_t tmp;
		primary_lv_pumps_speed_converted_t tmp_converted;
		uint8_t r_status;
		float r_pumps_speed;

		sscanf(s, "%" SCNu8 ","  
			"%f,"       ,
			&r_status,
			&r_pumps_speed);
		tmp_converted.status = (primary_lv_pumps_speed_status)r_status;
		tmp_converted.pumps_speed = (float)r_pumps_speed;

		primary_lv_pumps_speed_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_LV_PUMPS_SPEED_BYTE_SIZE;
		return primary_lv_pumps_speed_pack(data, &tmp, PRIMARY_LV_PUMPS_SPEED_BYTE_SIZE);
	}
	case 1056:
	{
		primary_lv_set_radiator_speed_t tmp;
		primary_lv_set_radiator_speed_converted_t tmp_converted;
		uint8_t r_status;
		float r_radiator_speed;

		sscanf(s, "%" SCNu8 ","  
			"%f,"       ,
			&r_status,
			&r_radiator_speed);
		tmp_converted.status = (primary_lv_set_radiator_speed_status)r_status;
		tmp_converted.radiator_speed = (float)r_radiator_speed;

		primary_lv_set_radiator_speed_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_LV_SET_RADIATOR_SPEED_BYTE_SIZE;
		return primary_lv_set_radiator_speed_pack(data, &tmp, PRIMARY_LV_SET_RADIATOR_SPEED_BYTE_SIZE);
	}
	case 1064:
	{
		primary_lv_set_pumps_speed_t tmp;
		primary_lv_set_pumps_speed_converted_t tmp_converted;
		uint8_t r_status;
		float r_pumps_speed;

		sscanf(s, "%" SCNu8 ","  
			"%f,"       ,
			&r_status,
			&r_pumps_speed);
		tmp_converted.status = (primary_lv_set_pumps_speed_status)r_status;
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
		primary_lv_feedback_t tmp;
		primary_lv_feedback_converted_t tmp_converted;
		uint8_t r_feedbacks_bspd;
		uint8_t r_feedbacks_hvd;
		uint8_t r_feedbacks_invc_interlock;
		uint8_t r_feedbacks_ams;
		uint8_t r_feedbacks_sd_end;
		uint8_t r_feedbacks_lvms;
		uint8_t r_feedbacks_interlock;
		uint8_t r_feedbacks_sd_start;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  ,
			&r_feedbacks_bspd,
			&r_feedbacks_hvd,
			&r_feedbacks_invc_interlock,
			&r_feedbacks_ams,
			&r_feedbacks_sd_end,
			&r_feedbacks_lvms,
			&r_feedbacks_interlock,
			&r_feedbacks_sd_start);
		tmp_converted.feedbacks_bspd = (uint8_t)r_feedbacks_bspd;
		tmp_converted.feedbacks_hvd = (uint8_t)r_feedbacks_hvd;
		tmp_converted.feedbacks_invc_interlock = (uint8_t)r_feedbacks_invc_interlock;
		tmp_converted.feedbacks_ams = (uint8_t)r_feedbacks_ams;
		tmp_converted.feedbacks_sd_end = (uint8_t)r_feedbacks_sd_end;
		tmp_converted.feedbacks_lvms = (uint8_t)r_feedbacks_lvms;
		tmp_converted.feedbacks_interlock = (uint8_t)r_feedbacks_interlock;
		tmp_converted.feedbacks_sd_start = (uint8_t)r_feedbacks_sd_start;

		primary_lv_feedback_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_LV_FEEDBACK_BYTE_SIZE;
		return primary_lv_feedback_pack(data, &tmp, PRIMARY_LV_FEEDBACK_BYTE_SIZE);
	}
	case 592:
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
	case 600:
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
	case 608:
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
	case 616:
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
		uint8_t r_feedback_rfe;
		uint8_t r_feedback_frg;
		uint8_t r_feedback_discharge;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
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
			&r_feedback_autonomous_system_actuation,
			&r_feedback_rfe,
			&r_feedback_frg,
			&r_feedback_discharge);
		tmp_converted.feedback_inverters = (uint8_t)r_feedback_inverters;
		tmp_converted.feedback_pcbs = (uint8_t)r_feedback_pcbs;
		tmp_converted.feedback_pumps = (uint8_t)r_feedback_pumps;
		tmp_converted.feedback_radiators = (uint8_t)r_feedback_radiators;
		tmp_converted.feedback_shutdown = (uint8_t)r_feedback_shutdown;
		tmp_converted.feedback_hv_fans = (uint8_t)r_feedback_hv_fans;
		tmp_converted.feedback_autonomous_system_actuation = (uint8_t)r_feedback_autonomous_system_actuation;
		tmp_converted.feedback_rfe = (uint8_t)r_feedback_rfe;
		tmp_converted.feedback_frg = (uint8_t)r_feedback_frg;
		tmp_converted.feedback_discharge = (uint8_t)r_feedback_discharge;

		primary_lv_feedback_gpio_extender_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_LV_FEEDBACK_GPIO_EXTENDER_BYTE_SIZE;
		return primary_lv_feedback_gpio_extender_pack(data, &tmp, PRIMARY_LV_FEEDBACK_GPIO_EXTENDER_BYTE_SIZE);
	}
	case 624:
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
	case 80:
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
	case 1600:
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
	case 1072:
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
	case 632:
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
	case 1608:
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
	case 1080:
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
	case 640:
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
	case 88:
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
	case 1088:
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
	case 648:
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
	case 656:
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
		uint8_t r_error_bspd_limits;
		uint8_t r_error_no_brake_to_rtd;

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
			"%" SCNu8 ","  ,
			&r_error_pedal_adc,
			&r_error_pedal_implausibility,
			&r_error_imu_tout,
			&r_error_irts_tout,
			&r_error_ts_tout,
			&r_error_invl_tout,
			&r_error_invr_tout,
			&r_error_steer_tout,
			&r_error_fsm,
			&r_error_bspd_limits,
			&r_error_no_brake_to_rtd);
		tmp_converted.error_pedal_adc = (uint8_t)r_error_pedal_adc;
		tmp_converted.error_pedal_implausibility = (uint8_t)r_error_pedal_implausibility;
		tmp_converted.error_imu_tout = (uint8_t)r_error_imu_tout;
		tmp_converted.error_irts_tout = (uint8_t)r_error_irts_tout;
		tmp_converted.error_ts_tout = (uint8_t)r_error_ts_tout;
		tmp_converted.error_invl_tout = (uint8_t)r_error_invl_tout;
		tmp_converted.error_invr_tout = (uint8_t)r_error_invr_tout;
		tmp_converted.error_steer_tout = (uint8_t)r_error_steer_tout;
		tmp_converted.error_fsm = (uint8_t)r_error_fsm;
		tmp_converted.error_bspd_limits = (uint8_t)r_error_bspd_limits;
		tmp_converted.error_no_brake_to_rtd = (uint8_t)r_error_no_brake_to_rtd;

		primary_ecu_errors_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_ECU_ERRORS_BYTE_SIZE;
		return primary_ecu_errors_pack(data, &tmp, PRIMARY_ECU_ERRORS_BYTE_SIZE);
	}
	case 664:
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
	case 672:
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
	case 96:
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
	case 1616:
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
	case 1096:
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
	case 680:
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
	case 688:
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
	case 1624:
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
	case 1632:
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
	case 1640:
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
	case 1648:
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
	case 1656:
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
	case 1664:
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
	case 1672:
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
	case 1680:
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
	case 1688:
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
	case 1696:
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
	case 1704:
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
	case 1712:
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
	case 1720:
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
	case 1728:
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
	case 1736:
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
	case 1744:
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
	case 1752:
	{
		primary_ecu_steer_actuator_status_t tmp;
		primary_ecu_steer_actuator_status_converted_t tmp_converted;
		uint8_t r_status;

		sscanf(s, "%" SCNu8 ","  ,
			&r_status);
		tmp_converted.status = (primary_ecu_steer_actuator_status_status)r_status;

		primary_ecu_steer_actuator_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_ECU_STEER_ACTUATOR_STATUS_BYTE_SIZE;
		return primary_ecu_steer_actuator_status_pack(data, &tmp, PRIMARY_ECU_STEER_ACTUATOR_STATUS_BYTE_SIZE);
	}
	case 1104:
	{
		primary_ecu_set_steer_actuator_status_steering_wheel_t tmp;
		primary_ecu_set_steer_actuator_status_steering_wheel_converted_t tmp_converted;
		uint8_t r_status;

		sscanf(s, "%" SCNu8 ","  ,
			&r_status);
		tmp_converted.status = (primary_ecu_set_steer_actuator_status_steering_wheel_status)r_status;

		primary_ecu_set_steer_actuator_status_steering_wheel_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_ECU_SET_STEER_ACTUATOR_STATUS_STEERING_WHEEL_BYTE_SIZE;
		return primary_ecu_set_steer_actuator_status_steering_wheel_pack(data, &tmp, PRIMARY_ECU_SET_STEER_ACTUATOR_STATUS_STEERING_WHEEL_BYTE_SIZE);
	}
	case 1112:
	{
		primary_ecu_set_steer_actuator_status_tlm_t tmp;
		primary_ecu_set_steer_actuator_status_tlm_converted_t tmp_converted;
		uint8_t r_status;

		sscanf(s, "%" SCNu8 ","  ,
			&r_status);
		tmp_converted.status = (primary_ecu_set_steer_actuator_status_tlm_status)r_status;

		primary_ecu_set_steer_actuator_status_tlm_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_ECU_SET_STEER_ACTUATOR_STATUS_TLM_BYTE_SIZE;
		return primary_ecu_set_steer_actuator_status_tlm_pack(data, &tmp, PRIMARY_ECU_SET_STEER_ACTUATOR_STATUS_TLM_BYTE_SIZE);
	}
	case 1760:
	{
		primary_ecu_set_steer_actuator_angle_t tmp;
		primary_ecu_set_steer_actuator_angle_converted_t tmp_converted;
		float r_angle;

		sscanf(s, "%f,"       ,
			&r_angle);
		tmp_converted.angle = (float)r_angle;

		primary_ecu_set_steer_actuator_angle_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_ECU_SET_STEER_ACTUATOR_ANGLE_BYTE_SIZE;
		return primary_ecu_set_steer_actuator_angle_pack(data, &tmp, PRIMARY_ECU_SET_STEER_ACTUATOR_ANGLE_BYTE_SIZE);
	}
	case 1768:
	{
		primary_ecu_steer_actuator_current_t tmp;
		primary_ecu_steer_actuator_current_converted_t tmp_converted;
		float r_current;

		sscanf(s, "%f,"       ,
			&r_current);
		tmp_converted.current = (float)r_current;

		primary_ecu_steer_actuator_current_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_ECU_STEER_ACTUATOR_CURRENT_BYTE_SIZE;
		return primary_ecu_steer_actuator_current_pack(data, &tmp, PRIMARY_ECU_STEER_ACTUATOR_CURRENT_BYTE_SIZE);
	}
	case 1776:
	{
		primary_debug_signal_crash_debug_t tmp;
		primary_debug_signal_crash_debug_converted_t tmp_converted;
		uint8_t r_seq_number;
		uint8_t r_byte_1;
		uint8_t r_byte_2;
		uint8_t r_byte_3;
		uint8_t r_byte_4;
		uint8_t r_byte_5;
		uint8_t r_byte_6;
		uint8_t r_byte_7;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  ,
			&r_seq_number,
			&r_byte_1,
			&r_byte_2,
			&r_byte_3,
			&r_byte_4,
			&r_byte_5,
			&r_byte_6,
			&r_byte_7);
		tmp_converted.seq_number = (uint8_t)r_seq_number;
		tmp_converted.byte_1 = (uint8_t)r_byte_1;
		tmp_converted.byte_2 = (uint8_t)r_byte_2;
		tmp_converted.byte_3 = (uint8_t)r_byte_3;
		tmp_converted.byte_4 = (uint8_t)r_byte_4;
		tmp_converted.byte_5 = (uint8_t)r_byte_5;
		tmp_converted.byte_6 = (uint8_t)r_byte_6;
		tmp_converted.byte_7 = (uint8_t)r_byte_7;

		primary_debug_signal_crash_debug_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_DEBUG_SIGNAL_CRASH_DEBUG_BYTE_SIZE;
		return primary_debug_signal_crash_debug_pack(data, &tmp, PRIMARY_DEBUG_SIGNAL_CRASH_DEBUG_BYTE_SIZE);
	}
	case 1784:
	{
		primary_debug_signal_crash_debug_ack_t tmp;
		primary_debug_signal_crash_debug_ack_converted_t tmp_converted;
		uint8_t r_seq_number;

		sscanf(s, "%" SCNu8 ","  ,
			&r_seq_number);
		tmp_converted.seq_number = (uint8_t)r_seq_number;

		primary_debug_signal_crash_debug_ack_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_DEBUG_SIGNAL_CRASH_DEBUG_ACK_BYTE_SIZE;
		return primary_debug_signal_crash_debug_ack_pack(data, &tmp, PRIMARY_DEBUG_SIGNAL_CRASH_DEBUG_ACK_BYTE_SIZE);
	}
	case 1792:
	{
		primary_debug_signal_1_t tmp;
		primary_debug_signal_1_converted_t tmp_converted;
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
		tmp_converted.device_id = (primary_debug_signal_1_device_id)r_device_id;
		tmp_converted.field_1 = (float)r_field_1;
		tmp_converted.field_2 = (float)r_field_2;
		tmp_converted.field_3 = (float)r_field_3;

		primary_debug_signal_1_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_DEBUG_SIGNAL_1_BYTE_SIZE;
		return primary_debug_signal_1_pack(data, &tmp, PRIMARY_DEBUG_SIGNAL_1_BYTE_SIZE);
	}
	case 1800:
	{
		primary_debug_signal_2_t tmp;
		primary_debug_signal_2_converted_t tmp_converted;
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
		tmp_converted.device_id = (primary_debug_signal_2_device_id)r_device_id;
		tmp_converted.field_1 = (float)r_field_1;
		tmp_converted.field_2 = (float)r_field_2;
		tmp_converted.field_3 = (float)r_field_3;

		primary_debug_signal_2_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_DEBUG_SIGNAL_2_BYTE_SIZE;
		return primary_debug_signal_2_pack(data, &tmp, PRIMARY_DEBUG_SIGNAL_2_BYTE_SIZE);
	}
	case 1808:
	{
		primary_debug_signal_3_t tmp;
		primary_debug_signal_3_converted_t tmp_converted;
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
		tmp_converted.device_id = (primary_debug_signal_3_device_id)r_device_id;
		tmp_converted.field_1 = (float)r_field_1;
		tmp_converted.field_2 = (float)r_field_2;
		tmp_converted.field_3 = (float)r_field_3;

		primary_debug_signal_3_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_DEBUG_SIGNAL_3_BYTE_SIZE;
		return primary_debug_signal_3_pack(data, &tmp, PRIMARY_DEBUG_SIGNAL_3_BYTE_SIZE);
	}
	case 1824:
	{
		primary_debug_signal_4_t tmp;
		primary_debug_signal_4_converted_t tmp_converted;
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
		tmp_converted.device_id = (primary_debug_signal_4_device_id)r_device_id;
		tmp_converted.field_1 = (float)r_field_1;
		tmp_converted.field_2 = (float)r_field_2;
		tmp_converted.field_3 = (float)r_field_3;

		primary_debug_signal_4_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_DEBUG_SIGNAL_4_BYTE_SIZE;
		return primary_debug_signal_4_pack(data, &tmp, PRIMARY_DEBUG_SIGNAL_4_BYTE_SIZE);
	}
	case 256:
	{
		primary_charger_1_t tmp;
		primary_charger_1_converted_t tmp_converted;
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

		primary_charger_1_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_CHARGER_1_BYTE_SIZE;
		return primary_charger_1_pack(data, &tmp, PRIMARY_CHARGER_1_BYTE_SIZE);
	}
	case 272:
	{
		primary_charger_2_t tmp;
		primary_charger_2_converted_t tmp_converted;
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

		primary_charger_2_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_CHARGER_2_BYTE_SIZE;
		return primary_charger_2_pack(data, &tmp, PRIMARY_CHARGER_2_BYTE_SIZE);
	}
	case 288:
	{
		primary_charger_3_t tmp;
		primary_charger_3_converted_t tmp_converted;
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

		primary_charger_3_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_CHARGER_3_BYTE_SIZE;
		return primary_charger_3_pack(data, &tmp, PRIMARY_CHARGER_3_BYTE_SIZE);
	}
	case 304:
	{
		primary_charger_4_t tmp;
		primary_charger_4_converted_t tmp_converted;
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

		primary_charger_4_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_CHARGER_4_BYTE_SIZE;
		return primary_charger_4_pack(data, &tmp, PRIMARY_CHARGER_4_BYTE_SIZE);
	}
	case 320:
	{
		primary_charger_5_t tmp;
		primary_charger_5_converted_t tmp_converted;
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

		primary_charger_5_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_CHARGER_5_BYTE_SIZE;
		return primary_charger_5_pack(data, &tmp, PRIMARY_CHARGER_5_BYTE_SIZE);
	}
	case 336:
	{
		primary_charger_6_t tmp;
		primary_charger_6_converted_t tmp_converted;
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

		primary_charger_6_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_CHARGER_6_BYTE_SIZE;
		return primary_charger_6_pack(data, &tmp, PRIMARY_CHARGER_6_BYTE_SIZE);
	}
	case 344:
	{
		primary_charger_7_t tmp;
		primary_charger_7_converted_t tmp_converted;
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

		primary_charger_7_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_CHARGER_7_BYTE_SIZE;
		return primary_charger_7_pack(data, &tmp, PRIMARY_CHARGER_7_BYTE_SIZE);
	}
	case 352:
	{
		primary_charger_8_t tmp;
		primary_charger_8_converted_t tmp_converted;
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

		primary_charger_8_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_CHARGER_8_BYTE_SIZE;
		return primary_charger_8_pack(data, &tmp, PRIMARY_CHARGER_8_BYTE_SIZE);
	}
	case 368:
	{
		primary_charger_9_t tmp;
		primary_charger_9_converted_t tmp_converted;
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

		primary_charger_9_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_CHARGER_9_BYTE_SIZE;
		return primary_charger_9_pack(data, &tmp, PRIMARY_CHARGER_9_BYTE_SIZE);
	}
	case 384:
	{
		primary_charger_10_t tmp;
		primary_charger_10_converted_t tmp_converted;
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

		primary_charger_10_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_CHARGER_10_BYTE_SIZE;
		return primary_charger_10_pack(data, &tmp, PRIMARY_CHARGER_10_BYTE_SIZE);
	}
	case 392:
	{
		primary_charger_11_t tmp;
		primary_charger_11_converted_t tmp_converted;
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

		primary_charger_11_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_CHARGER_11_BYTE_SIZE;
		return primary_charger_11_pack(data, &tmp, PRIMARY_CHARGER_11_BYTE_SIZE);
	}
	case 400:
	{
		primary_charger_12_t tmp;
		primary_charger_12_converted_t tmp_converted;
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

		primary_charger_12_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_CHARGER_12_BYTE_SIZE;
		return primary_charger_12_pack(data, &tmp, PRIMARY_CHARGER_12_BYTE_SIZE);
	}
	case 408:
	{
		primary_charger_13_t tmp;
		primary_charger_13_converted_t tmp_converted;
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

		primary_charger_13_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_CHARGER_13_BYTE_SIZE;
		return primary_charger_13_pack(data, &tmp, PRIMARY_CHARGER_13_BYTE_SIZE);
	}
	case 416:
	{
		primary_charger_14_t tmp;
		primary_charger_14_converted_t tmp_converted;
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

		primary_charger_14_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_CHARGER_14_BYTE_SIZE;
		return primary_charger_14_pack(data, &tmp, PRIMARY_CHARGER_14_BYTE_SIZE);
	}
	case 432:
	{
		primary_charger_15_t tmp;
		primary_charger_15_converted_t tmp_converted;
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

		primary_charger_15_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_CHARGER_15_BYTE_SIZE;
		return primary_charger_15_pack(data, &tmp, PRIMARY_CHARGER_15_BYTE_SIZE);
	}
	case 448:
	{
		primary_charger_16_t tmp;
		primary_charger_16_converted_t tmp_converted;
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

		primary_charger_16_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_CHARGER_16_BYTE_SIZE;
		return primary_charger_16_pack(data, &tmp, PRIMARY_CHARGER_16_BYTE_SIZE);
	}
	case 464:
	{
		primary_charger_17_t tmp;
		primary_charger_17_converted_t tmp_converted;
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

		primary_charger_17_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_CHARGER_17_BYTE_SIZE;
		return primary_charger_17_pack(data, &tmp, PRIMARY_CHARGER_17_BYTE_SIZE);
	}
	case 480:
	{
		primary_charger_18_t tmp;
		primary_charger_18_converted_t tmp_converted;
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

		primary_charger_18_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_CHARGER_18_BYTE_SIZE;
		return primary_charger_18_pack(data, &tmp, PRIMARY_CHARGER_18_BYTE_SIZE);
	}
	case 496:
	{
		primary_charger_19_t tmp;
		primary_charger_19_converted_t tmp_converted;
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

		primary_charger_19_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_CHARGER_19_BYTE_SIZE;
		return primary_charger_19_pack(data, &tmp, PRIMARY_CHARGER_19_BYTE_SIZE);
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
		case 0: return 2;
		case 1: return 0;
		case 2: return 0;
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
		case 700: return 2;
		case 701: return 2;
		case 703: return 2;
		case 704: return 2;
		case 702: return 2;
		case 705: return 3;
		case 32: return 15;
		case 512: return 35;
		case 1536: return 2;
		case 1024: return 2;
		case 520: return 20;
		case 528: return 7;
		case 536: return 8;
		case 544: return 5;
		case 552: return 6;
		case 560: return 1;
		case 40: return 1;
		case 48: return 1;
		case 1544: return 29;
		case 1032: return 2;
		case 1040: return 2;
		case 568: return 1;
		case 1568: return 1;
		case 1576: return 1;
		case 1048: return 1;
		case 1584: return 2;
		case 1592: return 2;
		case 1056: return 2;
		case 1064: return 2;
		case 576: return 23;
		case 584: return 8;
		case 592: return 4;
		case 600: return 4;
		case 608: return 4;
		case 616: return 10;
		case 56: return 0;
		case 64: return 0;
		case 72: return 0;
		case 624: return 1;
		case 80: return 1;
		case 1600: return 1;
		case 1072: return 1;
		case 632: return 1;
		case 1608: return 6;
		case 1080: return 6;
		case 640: return 1;
		case 88: return 1;
		case 1088: return 2;
		case 648: return 4;
		case 656: return 11;
		case 664: return 8;
		case 672: return 3;
		case 96: return 3;
		case 1616: return 1;
		case 1096: return 1;
		case 513: return 8;
		case 680: return 5;
		case 688: return 3;
		case 514: return 8;
		case 385: return 8;
		case 386: return 8;
		case 1624: return 1;
		case 1632: return 1;
		case 1640: return 1;
		case 1648: return 4;
		case 1656: return 4;
		case 1664: return 4;
		case 1672: return 3;
		case 1680: return 1;
		case 1688: return 1;
		case 1696: return 1;
		case 1704: return 1;
		case 1712: return 3;
		case 1720: return 4;
		case 1728: return 4;
		case 1736: return 5;
		case 1744: return 3;
		case 1752: return 1;
		case 1104: return 1;
		case 1112: return 1;
		case 1760: return 1;
		case 1768: return 1;
		case 1776: return 8;
		case 1784: return 1;
		case 1792: return 4;
		case 1800: return 4;
		case 1808: return 4;
		case 1824: return 4;
		case 256: return 8;
		case 272: return 8;
		case 288: return 8;
		case 304: return 8;
		case 320: return 8;
		case 336: return 8;
		case 344: return 8;
		case 352: return 8;
		case 368: return 8;
		case 384: return 8;
		case 392: return 8;
		case 400: return 8;
		case 408: return 8;
		case 416: return 8;
		case 432: return 8;
		case 448: return 8;
		case 464: return 8;
		case 480: return 8;
		case 496: return 8;
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
	case 0:
		if(fields_types_size < 2) return 0;
		fields_types[0] = e_primary_hv_jmp_to_blt_forward;
		fields_types[1] = e_primary_hv_jmp_to_blt_cellboard_id;
		return 2;
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
	case 32:
		if(fields_types_size < 15) return 0;
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
		return 15;
	case 512:
		if(fields_types_size < 35) return 0;
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
		return 35;
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
		fields_types[0] = e_primary_hv_feedback_status_feedback_implausibility_detected;
		fields_types[1] = e_primary_hv_feedback_status_feedback_imd_cockpit;
		fields_types[2] = e_primary_hv_feedback_status_feedback_tsal_green_fault_latched;
		fields_types[3] = e_primary_hv_feedback_status_feedback_bms_cockpit;
		fields_types[4] = e_primary_hv_feedback_status_feedback_ext_latched;
		fields_types[5] = e_primary_hv_feedback_status_feedback_tsal_green;
		fields_types[6] = e_primary_hv_feedback_status_feedback_ts_over_60v_status;
		fields_types[7] = e_primary_hv_feedback_status_feedback_airn_status;
		fields_types[8] = e_primary_hv_feedback_status_feedback_airp_status;
		fields_types[9] = e_primary_hv_feedback_status_feedback_airp_gate;
		fields_types[10] = e_primary_hv_feedback_status_feedback_airn_gate;
		fields_types[11] = e_primary_hv_feedback_status_feedback_precharge_status;
		fields_types[12] = e_primary_hv_feedback_status_feedback_tsp_over_60v_status;
		fields_types[13] = e_primary_hv_feedback_status_feedback_imd_fault;
		fields_types[14] = e_primary_hv_feedback_status_feedback_check_mux;
		fields_types[15] = e_primary_hv_feedback_status_feedback_sd_end;
		fields_types[16] = e_primary_hv_feedback_status_feedback_sd_out;
		fields_types[17] = e_primary_hv_feedback_status_feedback_sd_in;
		fields_types[18] = e_primary_hv_feedback_status_feedback_sd_bms;
		fields_types[19] = e_primary_hv_feedback_status_feedback_sd_imd;
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
		fields_types[0] = e_primary_float;
		fields_types[1] = e_primary_float;
		fields_types[2] = e_primary_float;
		fields_types[3] = e_primary_float;
		fields_types[4] = e_primary_float;
		fields_types[5] = e_primary_float;
		fields_types[6] = e_primary_float;
		fields_types[7] = e_primary_float;
		return 8;
	case 544:
		if(fields_types_size < 5) return 0;
		fields_types[0] = e_primary_float;
		fields_types[1] = e_primary_float;
		fields_types[2] = e_primary_float;
		fields_types[3] = e_primary_float;
		fields_types[4] = e_primary_float;
		return 5;
	case 552:
		if(fields_types_size < 6) return 0;
		fields_types[0] = e_primary_uint8_t;
		fields_types[1] = e_primary_hv_imd_status_imd_status;
		fields_types[2] = e_primary_uint16_t;
		fields_types[3] = e_primary_uint8_t;
		fields_types[4] = e_primary_uint8_t;
		fields_types[5] = e_primary_uint8_t;
		return 6;
	case 560:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_hv_status_status;
		return 1;
	case 40:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_hv_set_status_ecu_hv_status_set;
		return 1;
	case 48:
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
		fields_types[0] = e_primary_hv_set_balancing_status_handcart_set_balancing_status;
		fields_types[1] = e_primary_uint8_t;
		return 2;
	case 1040:
		if(fields_types_size < 2) return 0;
		fields_types[0] = e_primary_hv_set_balancing_status_steering_wheel_set_balancing_status;
		fields_types[1] = e_primary_uint8_t;
		return 2;
	case 568:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_lv_status_status;
		return 1;
	case 1568:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_lv_charging_status_status;
		return 1;
	case 1576:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_lv_cooling_aggressiveness_status;
		return 1;
	case 1048:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_lv_set_cooling_aggressiveness_status;
		return 1;
	case 1584:
		if(fields_types_size < 2) return 0;
		fields_types[0] = e_primary_lv_radiator_speed_status;
		fields_types[1] = e_primary_float;
		return 2;
	case 1592:
		if(fields_types_size < 2) return 0;
		fields_types[0] = e_primary_lv_pumps_speed_status;
		fields_types[1] = e_primary_float;
		return 2;
	case 1056:
		if(fields_types_size < 2) return 0;
		fields_types[0] = e_primary_lv_set_radiator_speed_status;
		fields_types[1] = e_primary_float;
		return 2;
	case 1064:
		if(fields_types_size < 2) return 0;
		fields_types[0] = e_primary_lv_set_pumps_speed_status;
		fields_types[1] = e_primary_float;
		return 2;
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
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_primary_float;
		fields_types[1] = e_primary_float;
		fields_types[2] = e_primary_float;
		fields_types[3] = e_primary_float;
		return 4;
	case 616:
		if(fields_types_size < 10) return 0;
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
		return 10;
	case 624:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_lv_inverter_connection_status_status;
		return 1;
	case 80:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_lv_set_inverter_connection_status_status;
		return 1;
	case 1600:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_tlm_status_status;
		return 1;
	case 1072:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_tlm_set_status_status;
		return 1;
	case 632:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_handcart_status_connected;
		return 1;
	case 1608:
		if(fields_types_size < 6) return 0;
		fields_types[0] = e_primary_float;
		fields_types[1] = e_primary_handcart_settings_fans_override;
		fields_types[2] = e_primary_float;
		fields_types[3] = e_primary_float;
		fields_types[4] = e_primary_float;
		fields_types[5] = e_primary_handcart_settings_status;
		return 6;
	case 1080:
		if(fields_types_size < 6) return 0;
		fields_types[0] = e_primary_float;
		fields_types[1] = e_primary_handcart_set_settings_fans_override;
		fields_types[2] = e_primary_float;
		fields_types[3] = e_primary_float;
		fields_types[4] = e_primary_float;
		fields_types[5] = e_primary_handcart_set_settings_status;
		return 6;
	case 640:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_ecu_status_status;
		return 1;
	case 88:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_ecu_set_status_status;
		return 1;
	case 1088:
		if(fields_types_size < 2) return 0;
		fields_types[0] = e_primary_ecu_inverter_status_rl;
		fields_types[1] = e_primary_ecu_inverter_status_rr;
		return 2;
	case 648:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_primary_uint8_t;
		fields_types[1] = e_primary_uint8_t;
		fields_types[2] = e_primary_uint8_t;
		fields_types[3] = e_primary_uint8_t;
		return 4;
	case 656:
		if(fields_types_size < 11) return 0;
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
		return 11;
	case 664:
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
		if(fields_types_size < 3) return 0;
		fields_types[0] = e_primary_float;
		fields_types[1] = e_primary_float;
		fields_types[2] = e_primary_float;
		return 3;
	case 96:
		if(fields_types_size < 3) return 0;
		fields_types[0] = e_primary_float;
		fields_types[1] = e_primary_float;
		fields_types[2] = e_primary_float;
		return 3;
	case 1616:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_ecu_ptt_status_status;
		return 1;
	case 1096:
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
	case 680:
		if(fields_types_size < 5) return 0;
		fields_types[0] = e_primary_float;
		fields_types[1] = e_primary_float;
		fields_types[2] = e_primary_float;
		fields_types[3] = e_primary_float;
		fields_types[4] = e_primary_float;
		return 5;
	case 688:
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
	case 1624:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_float;
		return 1;
	case 1632:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_float;
		return 1;
	case 1640:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_float;
		return 1;
	case 1648:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_primary_uint8_t;
		fields_types[1] = e_primary_float;
		fields_types[2] = e_primary_float;
		fields_types[3] = e_primary_float;
		return 4;
	case 1656:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_primary_float;
		fields_types[1] = e_primary_float;
		fields_types[2] = e_primary_float;
		fields_types[3] = e_primary_float;
		return 4;
	case 1664:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_primary_uint8_t;
		fields_types[1] = e_primary_float;
		fields_types[2] = e_primary_float;
		fields_types[3] = e_primary_float;
		return 4;
	case 1672:
		if(fields_types_size < 3) return 0;
		fields_types[0] = e_primary_float;
		fields_types[1] = e_primary_float;
		fields_types[2] = e_primary_float;
		return 3;
	case 1680:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_float;
		return 1;
	case 1688:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_float;
		return 1;
	case 1696:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_float;
		return 1;
	case 1704:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_float;
		return 1;
	case 1712:
		if(fields_types_size < 3) return 0;
		fields_types[0] = e_primary_float;
		fields_types[1] = e_primary_float;
		fields_types[2] = e_primary_float;
		return 3;
	case 1720:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_primary_uint8_t;
		fields_types[1] = e_primary_float;
		fields_types[2] = e_primary_float;
		fields_types[3] = e_primary_float;
		return 4;
	case 1728:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_primary_float;
		fields_types[1] = e_primary_float;
		fields_types[2] = e_primary_float;
		fields_types[3] = e_primary_float;
		return 4;
	case 1736:
		if(fields_types_size < 5) return 0;
		fields_types[0] = e_primary_uint8_t;
		fields_types[1] = e_primary_float;
		fields_types[2] = e_primary_float;
		fields_types[3] = e_primary_float;
		fields_types[4] = e_primary_float;
		return 5;
	case 1744:
		if(fields_types_size < 3) return 0;
		fields_types[0] = e_primary_float;
		fields_types[1] = e_primary_float;
		fields_types[2] = e_primary_float;
		return 3;
	case 1752:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_ecu_steer_actuator_status_status;
		return 1;
	case 1104:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_ecu_set_steer_actuator_status_steering_wheel_status;
		return 1;
	case 1112:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_ecu_set_steer_actuator_status_tlm_status;
		return 1;
	case 1760:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_float;
		return 1;
	case 1768:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_float;
		return 1;
	case 1776:
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
	case 1784:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_uint8_t;
		return 1;
	case 1792:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_primary_debug_signal_1_device_id;
		fields_types[1] = e_primary_float;
		fields_types[2] = e_primary_float;
		fields_types[3] = e_primary_float;
		return 4;
	case 1800:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_primary_debug_signal_2_device_id;
		fields_types[1] = e_primary_float;
		fields_types[2] = e_primary_float;
		fields_types[3] = e_primary_float;
		return 4;
	case 1808:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_primary_debug_signal_3_device_id;
		fields_types[1] = e_primary_float;
		fields_types[2] = e_primary_float;
		fields_types[3] = e_primary_float;
		return 4;
	case 1824:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_primary_debug_signal_4_device_id;
		fields_types[1] = e_primary_float;
		fields_types[2] = e_primary_float;
		fields_types[3] = e_primary_float;
		return 4;
	case 256:
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
	case 272:
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
	case 288:
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
	case 304:
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
	case 320:
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
	case 336:
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
	case 344:
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
	case 352:
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
	case 368:
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
	case 384:
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
	case 392:
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
	case 400:
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
	case 408:
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
	case 416:
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
	case 432:
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
	case 448:
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
	case 464:
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
	case 480:
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
	case 496:
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

    }
    return 0;
}
std::vector<std::string> primary_enum_fields_from_message(const std::string& msg_name)
{
	std::vector<std::string> ret;

	if(msg_name == NLG5_ERR) {
		ret.push_back("nlg5_e_oov");
		ret.push_back("nlg5_e_mov_ii");
		ret.push_back("nlg5_e_mov_i");
		ret.push_back("nlg5_e_sc");
		ret.push_back("nlg5_e_p_om");
		ret.push_back("nlg5_e_p_mv");
		ret.push_back("nlg5_e_of");
		ret.push_back("nlg5_e_mf");
		ret.push_back("nlg5_e_b_p");
		ret.push_back("nlg5_e_t_c");
		ret.push_back("nlg5_e_t_pow");
		ret.push_back("nlg5_e_t_dio");
		ret.push_back("nlg5_e_t_tr");
		ret.push_back("nlg5_e_t_ext1");
		ret.push_back("nlg5_e_t_ext2");
		ret.push_back("nlg5_e_t_ext3");
		ret.push_back("nlg5_e_f_crc");
		ret.push_back("nlg5_e_nv_crc");
		ret.push_back("nlg5_e_es_crc");
		ret.push_back("nlg5_e_ep_crc");
		ret.push_back("nlg5_e_wdt");
		ret.push_back("nlg5_e_init");
		ret.push_back("nlg5_e_c_to");
		ret.push_back("nlg5_e_c_off");
		ret.push_back("nlg5_e_c_tx");
		ret.push_back("nlg5_e_c_rx");
		ret.push_back("nlg5_e_sdt_bt");
		ret.push_back("nlg5_e_sdt_bv");
		ret.push_back("nlg5_e_sdt_ah");
		ret.push_back("nlg5_e_sdt_ct");
		ret.push_back("nlg5_w_pl_mv");
		ret.push_back("nlg5_w_pl_bv");
		ret.push_back("nlg5_w_pl_it");
		ret.push_back("nlg5_w_c_vor");
	}
	if(msg_name == NLG5_ST) {
		ret.push_back("nlg5_s_he");
		ret.push_back("nlg5_s_err");
		ret.push_back("nlg5_s_war");
		ret.push_back("nlg5_s_fan");
		ret.push_back("nlg5_s_eum");
		ret.push_back("nlg5_s_um_i");
		ret.push_back("nlg5_s_um_ii");
		ret.push_back("nlg5_s_cp_dt");
		ret.push_back("nlg5_s_bpd_i");
		ret.push_back("nlg5_s_bpd_ii");
		ret.push_back("nlg5_s_l_ov");
		ret.push_back("nlg5_s_l_oc");
		ret.push_back("nlg5_s_l_mc");
		ret.push_back("nlg5_s_l_pi");
		ret.push_back("nlg5_s_l_cp");
		ret.push_back("nlg5_s_l_pmax");
		ret.push_back("nlg5_s_l_mc_max");
		ret.push_back("nlg5_s_l_oc_max");
		ret.push_back("nlg5_s_l_mo_max");
		ret.push_back("nlg5_s_l_t_cprim");
		ret.push_back("nlg5_s_l_t_pow");
		ret.push_back("nlg5_s_l_t_dio");
		ret.push_back("nlg5_s_l_t_tr");
		ret.push_back("nlg5_s_l_t_batt");
		ret.push_back("nlg5_s_aac");
	}
	if(msg_name == NLG5_CTL) {
		ret.push_back("nlg5_c_c_en");
		ret.push_back("nlg5_c_c_el");
		ret.push_back("nlg5_c_cp_v");
		ret.push_back("nlg5_c_mr");
	}
	if(msg_name == HV_JMP_TO_BLT) {
		ret.push_back("forward");
		ret.push_back("cellboard_id");
	}
	if(msg_name == HV_CELLBOARD_VERSION) {
		ret.push_back("cellboard_id");
	}
	if(msg_name == HV_ERRORS) {
		ret.push_back("errors_cell_under_voltage");
		ret.push_back("errors_cell_over_voltage");
		ret.push_back("errors_cell_under_temperature");
		ret.push_back("errors_cell_over_temperature");
		ret.push_back("errors_over_current");
		ret.push_back("errors_can");
		ret.push_back("errors_int_voltage_mismatch");
		ret.push_back("errors_cellboard_comm");
		ret.push_back("errors_cellboard_internal");
		ret.push_back("errors_connector_disconnected");
		ret.push_back("errors_fans_disconnected");
		ret.push_back("errors_feedback");
		ret.push_back("errors_feedback_circuitry");
		ret.push_back("errors_eeprom_comm");
		ret.push_back("errors_eeprom_write");
	}
	if(msg_name == HV_DEBUG_SIGNALS) {
		ret.push_back("feedbacks_implausibility_detected");
		ret.push_back("feedbacks_imd_cockpit");
		ret.push_back("feedbacks_tsal_green_fault_latched");
		ret.push_back("feedbacks_bms_cockpit");
		ret.push_back("feedbacks_ext_latched");
		ret.push_back("feedbacks_tsal_green");
		ret.push_back("feedbacks_ts_over_60v_status");
		ret.push_back("feedbacks_airn_status");
		ret.push_back("feedbacks_airp_status");
		ret.push_back("feedbacks_airp_gate");
		ret.push_back("feedbacks_airn_gate");
		ret.push_back("feedbacks_precharge_status");
		ret.push_back("feedbacks_tsp_over_60v_status");
		ret.push_back("feedbacks_imd_fault");
		ret.push_back("feedbacks_check_mux");
		ret.push_back("feedbacks_sd_end");
		ret.push_back("feedbacks_sd_out");
		ret.push_back("feedbacks_sd_in");
		ret.push_back("feedbacks_sd_bms");
		ret.push_back("feedbacks_sd_imd");
		ret.push_back("errors_cell_under_voltage");
		ret.push_back("errors_cell_over_voltage");
		ret.push_back("errors_cell_under_temperature");
		ret.push_back("errors_cell_over_temperature");
		ret.push_back("errors_over_current");
		ret.push_back("errors_can");
		ret.push_back("errors_int_voltage_mismatch");
		ret.push_back("errors_cellboard_comm");
		ret.push_back("errors_cellboard_internal");
		ret.push_back("errors_connector_disconnected");
		ret.push_back("errors_fans_disconnected");
		ret.push_back("errors_feedback");
		ret.push_back("errors_feedback_circuitry");
		ret.push_back("errors_eeprom_comm");
		ret.push_back("errors_eeprom_write");
	}
	if(msg_name == HV_FANS_STATUS) {
		ret.push_back("fans_override");
	}
	if(msg_name == HV_SET_FANS_STATUS) {
		ret.push_back("fans_override");
	}
	if(msg_name == HV_FEEDBACK_STATUS) {
		ret.push_back("feedback_implausibility_detected");
		ret.push_back("feedback_imd_cockpit");
		ret.push_back("feedback_tsal_green_fault_latched");
		ret.push_back("feedback_bms_cockpit");
		ret.push_back("feedback_ext_latched");
		ret.push_back("feedback_tsal_green");
		ret.push_back("feedback_ts_over_60v_status");
		ret.push_back("feedback_airn_status");
		ret.push_back("feedback_airp_status");
		ret.push_back("feedback_airp_gate");
		ret.push_back("feedback_airn_gate");
		ret.push_back("feedback_precharge_status");
		ret.push_back("feedback_tsp_over_60v_status");
		ret.push_back("feedback_imd_fault");
		ret.push_back("feedback_check_mux");
		ret.push_back("feedback_sd_end");
		ret.push_back("feedback_sd_out");
		ret.push_back("feedback_sd_in");
		ret.push_back("feedback_sd_bms");
		ret.push_back("feedback_sd_imd");
	}
	if(msg_name == HV_IMD_STATUS) {
		ret.push_back("imd_fault");
		ret.push_back("imd_status");
	}
	if(msg_name == HV_STATUS) {
		ret.push_back("status");
	}
	if(msg_name == HV_SET_STATUS_ECU) {
		ret.push_back("hv_status_set");
	}
	if(msg_name == HV_SET_STATUS_HANDCART) {
		ret.push_back("hv_status_set");
	}
	if(msg_name == HV_BALANCING_STATUS) {
		ret.push_back("cellboard_id");
		ret.push_back("balancing_status");
		ret.push_back("errors_can_comm");
		ret.push_back("errors_ltc_comm");
		ret.push_back("errors_temp_comm_0");
		ret.push_back("errors_temp_comm_1");
		ret.push_back("errors_temp_comm_2");
		ret.push_back("errors_temp_comm_3");
		ret.push_back("errors_temp_comm_4");
		ret.push_back("errors_temp_comm_5");
		ret.push_back("errors_open_wire");
		ret.push_back("balancing_cells_cell0");
		ret.push_back("balancing_cells_cell1");
		ret.push_back("balancing_cells_cell2");
		ret.push_back("balancing_cells_cell3");
		ret.push_back("balancing_cells_cell4");
		ret.push_back("balancing_cells_cell5");
		ret.push_back("balancing_cells_cell6");
		ret.push_back("balancing_cells_cell7");
		ret.push_back("balancing_cells_cell8");
		ret.push_back("balancing_cells_cell9");
		ret.push_back("balancing_cells_cell10");
		ret.push_back("balancing_cells_cell11");
		ret.push_back("balancing_cells_cell12");
		ret.push_back("balancing_cells_cell13");
		ret.push_back("balancing_cells_cell14");
		ret.push_back("balancing_cells_cell15");
		ret.push_back("balancing_cells_cell16");
		ret.push_back("balancing_cells_cell17");
	}
	if(msg_name == HV_SET_BALANCING_STATUS_HANDCART) {
		ret.push_back("set_balancing_status");
	}
	if(msg_name == HV_SET_BALANCING_STATUS_STEERING_WHEEL) {
		ret.push_back("set_balancing_status");
	}
	if(msg_name == LV_STATUS) {
		ret.push_back("status");
	}
	if(msg_name == LV_CHARGING_STATUS) {
		ret.push_back("status");
	}
	if(msg_name == LV_COOLING_AGGRESSIVENESS) {
		ret.push_back("status");
	}
	if(msg_name == LV_SET_COOLING_AGGRESSIVENESS) {
		ret.push_back("status");
	}
	if(msg_name == LV_RADIATOR_SPEED) {
		ret.push_back("status");
	}
	if(msg_name == LV_PUMPS_SPEED) {
		ret.push_back("status");
	}
	if(msg_name == LV_SET_RADIATOR_SPEED) {
		ret.push_back("status");
	}
	if(msg_name == LV_SET_PUMPS_SPEED) {
		ret.push_back("status");
	}
	if(msg_name == LV_ERRORS) {
		ret.push_back("errors_cell_undervoltage");
		ret.push_back("errors_cell_overvoltage");
		ret.push_back("errors_battery_open_wire");
		ret.push_back("errors_can");
		ret.push_back("errors_spi");
		ret.push_back("errors_over_current");
		ret.push_back("errors_cell_under_temperature");
		ret.push_back("errors_cell_over_temperature");
		ret.push_back("errors_relay");
		ret.push_back("errors_bms_monitor");
		ret.push_back("errors_voltages_not_ready");
		ret.push_back("errors_mcp23017");
		ret.push_back("errors_radiator");
		ret.push_back("errors_fan");
		ret.push_back("errors_pump");
		ret.push_back("errors_adc_init");
		ret.push_back("errors_mux");
		ret.push_back("health_signals_lvms_out");
		ret.push_back("health_signals_relay_out");
		ret.push_back("health_signals_battery_voltage_out");
		ret.push_back("health_signals_charger_current");
		ret.push_back("health_signals_battery_current");
		ret.push_back("health_signals_sign_battery_current");
	}
	if(msg_name == LV_FEEDBACK) {
		ret.push_back("feedbacks_bspd");
		ret.push_back("feedbacks_hvd");
		ret.push_back("feedbacks_invc_interlock");
		ret.push_back("feedbacks_ams");
		ret.push_back("feedbacks_sd_end");
		ret.push_back("feedbacks_lvms");
		ret.push_back("feedbacks_interlock");
		ret.push_back("feedbacks_sd_start");
	}
	if(msg_name == LV_FEEDBACK_GPIO_EXTENDER) {
		ret.push_back("feedback_inverters");
		ret.push_back("feedback_pcbs");
		ret.push_back("feedback_pumps");
		ret.push_back("feedback_radiators");
		ret.push_back("feedback_shutdown");
		ret.push_back("feedback_hv_fans");
		ret.push_back("feedback_autonomous_system_actuation");
		ret.push_back("feedback_rfe");
		ret.push_back("feedback_frg");
		ret.push_back("feedback_discharge");
	}
	if(msg_name == LV_INVERTER_CONNECTION_STATUS) {
		ret.push_back("status");
	}
	if(msg_name == LV_SET_INVERTER_CONNECTION_STATUS) {
		ret.push_back("status");
	}
	if(msg_name == TLM_STATUS) {
		ret.push_back("status");
	}
	if(msg_name == TLM_SET_STATUS) {
		ret.push_back("status");
	}
	if(msg_name == HANDCART_STATUS) {
		ret.push_back("connected");
	}
	if(msg_name == HANDCART_SETTINGS) {
		ret.push_back("fans_override");
		ret.push_back("status");
	}
	if(msg_name == HANDCART_SET_SETTINGS) {
		ret.push_back("fans_override");
		ret.push_back("status");
	}
	if(msg_name == ECU_STATUS) {
		ret.push_back("status");
	}
	if(msg_name == ECU_SET_STATUS) {
		ret.push_back("status");
	}
	if(msg_name == ECU_INVERTER_STATUS) {
		ret.push_back("rl");
		ret.push_back("rr");
	}
	if(msg_name == ECU_CONTROL_STATUS) {
		ret.push_back("control_enabled");
		ret.push_back("control_errors_forced_off");
		ret.push_back("control_errors_wrong_maps");
		ret.push_back("control_errors_control_watchdog");
	}
	if(msg_name == ECU_ERRORS) {
		ret.push_back("error_pedal_adc");
		ret.push_back("error_pedal_implausibility");
		ret.push_back("error_imu_tout");
		ret.push_back("error_irts_tout");
		ret.push_back("error_ts_tout");
		ret.push_back("error_invl_tout");
		ret.push_back("error_invr_tout");
		ret.push_back("error_steer_tout");
		ret.push_back("error_fsm");
		ret.push_back("error_bspd_limits");
		ret.push_back("error_no_brake_to_rtd");
	}
	if(msg_name == ECU_FEEDBACKS) {
		ret.push_back("feedbacks_sd_cock_fb");
		ret.push_back("feedbacks_sd_fb1");
		ret.push_back("feedbacks_sd_bots_fb");
		ret.push_back("feedbacks_sd_interial_fb");
		ret.push_back("feedbacks_sd_fb4");
		ret.push_back("feedbacks_sd_in");
		ret.push_back("feedbacks_sd_out");
		ret.push_back("feedbacks_sd_ctrl_pin");
	}
	if(msg_name == ECU_PTT_STATUS) {
		ret.push_back("status");
	}
	if(msg_name == ECU_SET_PTT_STATUS) {
		ret.push_back("status");
	}
	if(msg_name == ECU_STEER_ACTUATOR_STATUS) {
		ret.push_back("status");
	}
	if(msg_name == ECU_SET_STEER_ACTUATOR_STATUS_STEERING_WHEEL) {
		ret.push_back("status");
	}
	if(msg_name == ECU_SET_STEER_ACTUATOR_STATUS_TLM) {
		ret.push_back("status");
	}
	if(msg_name == DEBUG_SIGNAL_1) {
		ret.push_back("device_id");
	}
	if(msg_name == DEBUG_SIGNAL_2) {
		ret.push_back("device_id");
	}
	if(msg_name == DEBUG_SIGNAL_3) {
		ret.push_back("device_id");
	}
	if(msg_name == DEBUG_SIGNAL_4) {
		ret.push_back("device_id");
	}

	return ret;
}
std::vector<std::string> primary_enum_names_from_fields(const std::string& msg_name, const std::string& sgn_name)
{
	std::vector<std::string> ret;

	if(msg_name == HV_JMP_TO_BLT)
	{
		if(sgn_name == "forward")
		{
			ret.push_back("off");
			ret.push_back("on");
			return ret;
		}
		if(sgn_name == "cellboard_id")
		{
			ret.push_back("cellboard_0");
			ret.push_back("cellboard_1");
			ret.push_back("cellboard_2");
			ret.push_back("cellboard_3");
			ret.push_back("cellboard_4");
			ret.push_back("cellboard_5");
			return ret;
		}
	}
	if(msg_name == HV_CELLBOARD_VERSION)
	{
		if(sgn_name == "cellboard_id")
		{
			ret.push_back("cellboard_0");
			ret.push_back("cellboard_1");
			ret.push_back("cellboard_2");
			ret.push_back("cellboard_3");
			ret.push_back("cellboard_4");
			ret.push_back("cellboard_5");
			return ret;
		}
	}
	if(msg_name == HV_FANS_STATUS)
	{
		if(sgn_name == "fans_override")
		{
			ret.push_back("off");
			ret.push_back("on");
			return ret;
		}
	}
	if(msg_name == HV_SET_FANS_STATUS)
	{
		if(sgn_name == "fans_override")
		{
			ret.push_back("off");
			ret.push_back("on");
			return ret;
		}
	}
	if(msg_name == HV_FEEDBACK_STATUS)
	{
		if(sgn_name == "feedback_implausibility_detected")
		{
			ret.push_back("feedback_state_low");
			ret.push_back("feedback_state_error");
			ret.push_back("feedback_state_high");
			return ret;
		}
		if(sgn_name == "feedback_imd_cockpit")
		{
			ret.push_back("feedback_state_low");
			ret.push_back("feedback_state_error");
			ret.push_back("feedback_state_high");
			return ret;
		}
		if(sgn_name == "feedback_tsal_green_fault_latched")
		{
			ret.push_back("feedback_state_low");
			ret.push_back("feedback_state_error");
			ret.push_back("feedback_state_high");
			return ret;
		}
		if(sgn_name == "feedback_bms_cockpit")
		{
			ret.push_back("feedback_state_low");
			ret.push_back("feedback_state_error");
			ret.push_back("feedback_state_high");
			return ret;
		}
		if(sgn_name == "feedback_ext_latched")
		{
			ret.push_back("feedback_state_low");
			ret.push_back("feedback_state_error");
			ret.push_back("feedback_state_high");
			return ret;
		}
		if(sgn_name == "feedback_tsal_green")
		{
			ret.push_back("feedback_state_low");
			ret.push_back("feedback_state_error");
			ret.push_back("feedback_state_high");
			return ret;
		}
		if(sgn_name == "feedback_ts_over_60v_status")
		{
			ret.push_back("feedback_state_low");
			ret.push_back("feedback_state_error");
			ret.push_back("feedback_state_high");
			return ret;
		}
		if(sgn_name == "feedback_airn_status")
		{
			ret.push_back("feedback_state_low");
			ret.push_back("feedback_state_error");
			ret.push_back("feedback_state_high");
			return ret;
		}
		if(sgn_name == "feedback_airp_status")
		{
			ret.push_back("feedback_state_low");
			ret.push_back("feedback_state_error");
			ret.push_back("feedback_state_high");
			return ret;
		}
		if(sgn_name == "feedback_airp_gate")
		{
			ret.push_back("feedback_state_low");
			ret.push_back("feedback_state_error");
			ret.push_back("feedback_state_high");
			return ret;
		}
		if(sgn_name == "feedback_airn_gate")
		{
			ret.push_back("feedback_state_low");
			ret.push_back("feedback_state_error");
			ret.push_back("feedback_state_high");
			return ret;
		}
		if(sgn_name == "feedback_precharge_status")
		{
			ret.push_back("feedback_state_low");
			ret.push_back("feedback_state_error");
			ret.push_back("feedback_state_high");
			return ret;
		}
		if(sgn_name == "feedback_tsp_over_60v_status")
		{
			ret.push_back("feedback_state_low");
			ret.push_back("feedback_state_error");
			ret.push_back("feedback_state_high");
			return ret;
		}
		if(sgn_name == "feedback_imd_fault")
		{
			ret.push_back("feedback_state_low");
			ret.push_back("feedback_state_error");
			ret.push_back("feedback_state_high");
			return ret;
		}
		if(sgn_name == "feedback_check_mux")
		{
			ret.push_back("feedback_state_low");
			ret.push_back("feedback_state_error");
			ret.push_back("feedback_state_high");
			return ret;
		}
		if(sgn_name == "feedback_sd_end")
		{
			ret.push_back("feedback_state_low");
			ret.push_back("feedback_state_error");
			ret.push_back("feedback_state_high");
			return ret;
		}
		if(sgn_name == "feedback_sd_out")
		{
			ret.push_back("feedback_state_low");
			ret.push_back("feedback_state_error");
			ret.push_back("feedback_state_high");
			return ret;
		}
		if(sgn_name == "feedback_sd_in")
		{
			ret.push_back("feedback_state_low");
			ret.push_back("feedback_state_error");
			ret.push_back("feedback_state_high");
			return ret;
		}
		if(sgn_name == "feedback_sd_bms")
		{
			ret.push_back("feedback_state_low");
			ret.push_back("feedback_state_error");
			ret.push_back("feedback_state_high");
			return ret;
		}
		if(sgn_name == "feedback_sd_imd")
		{
			ret.push_back("feedback_state_low");
			ret.push_back("feedback_state_error");
			ret.push_back("feedback_state_high");
			return ret;
		}
	}
	if(msg_name == HV_IMD_STATUS)
	{
		if(sgn_name == "imd_status")
		{
			ret.push_back("sc");
			ret.push_back("normal");
			ret.push_back("under_voltage");
			ret.push_back("start_measure");
			ret.push_back("device_error");
			ret.push_back("earth_fault");
			return ret;
		}
	}
	if(msg_name == HV_STATUS)
	{
		if(sgn_name == "status")
		{
			ret.push_back("init");
			ret.push_back("idle");
			ret.push_back("airn_close");
			ret.push_back("precharge");
			ret.push_back("airp_close");
			ret.push_back("ts_on");
			ret.push_back("fatal_error");
			return ret;
		}
	}
	if(msg_name == HV_SET_STATUS_ECU)
	{
		if(sgn_name == "hv_status_set")
		{
			ret.push_back("off");
			ret.push_back("on");
			return ret;
		}
	}
	if(msg_name == HV_SET_STATUS_HANDCART)
	{
		if(sgn_name == "hv_status_set")
		{
			ret.push_back("off");
			ret.push_back("on");
			return ret;
		}
	}
	if(msg_name == HV_BALANCING_STATUS)
	{
		if(sgn_name == "cellboard_id")
		{
			ret.push_back("cellboard_0");
			ret.push_back("cellboard_1");
			ret.push_back("cellboard_2");
			ret.push_back("cellboard_3");
			ret.push_back("cellboard_4");
			ret.push_back("cellboard_5");
			return ret;
		}
		if(sgn_name == "balancing_status")
		{
			ret.push_back("off");
			ret.push_back("on");
			return ret;
		}
	}
	if(msg_name == HV_SET_BALANCING_STATUS_HANDCART)
	{
		if(sgn_name == "set_balancing_status")
		{
			ret.push_back("off");
			ret.push_back("on");
			return ret;
		}
	}
	if(msg_name == HV_SET_BALANCING_STATUS_STEERING_WHEEL)
	{
		if(sgn_name == "set_balancing_status")
		{
			ret.push_back("off");
			ret.push_back("on");
			return ret;
		}
	}
	if(msg_name == LV_STATUS)
	{
		if(sgn_name == "status")
		{
			ret.push_back("init");
			ret.push_back("idle");
			ret.push_back("tson");
			ret.push_back("run");
			ret.push_back("flashing");
			ret.push_back("error");
			return ret;
		}
	}
	if(msg_name == LV_CHARGING_STATUS)
	{
		if(sgn_name == "status")
		{
			ret.push_back("off");
			ret.push_back("on");
			return ret;
		}
	}
	if(msg_name == LV_COOLING_AGGRESSIVENESS)
	{
		if(sgn_name == "status")
		{
			ret.push_back("weak");
			ret.push_back("normal");
			ret.push_back("aggressive");
			return ret;
		}
	}
	if(msg_name == LV_SET_COOLING_AGGRESSIVENESS)
	{
		if(sgn_name == "status")
		{
			ret.push_back("weak");
			ret.push_back("normal");
			ret.push_back("aggressive");
			return ret;
		}
	}
	if(msg_name == LV_RADIATOR_SPEED)
	{
		if(sgn_name == "status")
		{
			ret.push_back("off");
			ret.push_back("auto");
			ret.push_back("manual");
			return ret;
		}
	}
	if(msg_name == LV_PUMPS_SPEED)
	{
		if(sgn_name == "status")
		{
			ret.push_back("off");
			ret.push_back("auto");
			ret.push_back("manual");
			return ret;
		}
	}
	if(msg_name == LV_SET_RADIATOR_SPEED)
	{
		if(sgn_name == "status")
		{
			ret.push_back("off");
			ret.push_back("auto");
			ret.push_back("manual");
			return ret;
		}
	}
	if(msg_name == LV_SET_PUMPS_SPEED)
	{
		if(sgn_name == "status")
		{
			ret.push_back("off");
			ret.push_back("auto");
			ret.push_back("manual");
			return ret;
		}
	}
	if(msg_name == LV_INVERTER_CONNECTION_STATUS)
	{
		if(sgn_name == "status")
		{
			ret.push_back("off");
			ret.push_back("on");
			return ret;
		}
	}
	if(msg_name == LV_SET_INVERTER_CONNECTION_STATUS)
	{
		if(sgn_name == "status")
		{
			ret.push_back("off");
			ret.push_back("on");
			return ret;
		}
	}
	if(msg_name == TLM_STATUS)
	{
		if(sgn_name == "status")
		{
			ret.push_back("off");
			ret.push_back("on");
			return ret;
		}
	}
	if(msg_name == TLM_SET_STATUS)
	{
		if(sgn_name == "status")
		{
			ret.push_back("off");
			ret.push_back("on");
			return ret;
		}
	}
	if(msg_name == HANDCART_STATUS)
	{
		if(sgn_name == "connected")
		{
			ret.push_back("off");
			ret.push_back("on");
			return ret;
		}
	}
	if(msg_name == HANDCART_SETTINGS)
	{
		if(sgn_name == "fans_override")
		{
			ret.push_back("off");
			ret.push_back("on");
			return ret;
		}
		if(sgn_name == "status")
		{
			ret.push_back("none");
			ret.push_back("check");
			ret.push_back("idle");
			ret.push_back("precharge");
			ret.push_back("ready");
			ret.push_back("charge");
			ret.push_back("charge_done");
			ret.push_back("balancing");
			ret.push_back("error");
			return ret;
		}
	}
	if(msg_name == HANDCART_SET_SETTINGS)
	{
		if(sgn_name == "fans_override")
		{
			ret.push_back("off");
			ret.push_back("on");
			return ret;
		}
		if(sgn_name == "status")
		{
			ret.push_back("none");
			ret.push_back("check");
			ret.push_back("idle");
			ret.push_back("precharge");
			ret.push_back("ready");
			ret.push_back("charge");
			ret.push_back("charge_done");
			ret.push_back("balancing");
			ret.push_back("error");
			return ret;
		}
	}
	if(msg_name == ECU_STATUS)
	{
		if(sgn_name == "status")
		{
			ret.push_back("init");
			ret.push_back("enable_inv_updates");
			ret.push_back("check_inv_settings");
			ret.push_back("idle");
			ret.push_back("start_ts_precharge");
			ret.push_back("wait_ts_precharge");
			ret.push_back("wait_driver");
			ret.push_back("enable_inv_drive");
			ret.push_back("drive");
			ret.push_back("disable_inv_drive");
			ret.push_back("start_ts_discharge");
			ret.push_back("re_enable_inverter_drive");
			ret.push_back("wait_ts_discharge");
			ret.push_back("fatal_error");
			return ret;
		}
	}
	if(msg_name == ECU_SET_STATUS)
	{
		if(sgn_name == "status")
		{
			ret.push_back("idle");
			ret.push_back("ready");
			ret.push_back("drive");
			return ret;
		}
	}
	if(msg_name == ECU_INVERTER_STATUS)
	{
		if(sgn_name == "rl")
		{
			ret.push_back("disabled");
			ret.push_back("rfe_on");
			ret.push_back("frg_on");
			ret.push_back("enabled");
			return ret;
		}
		if(sgn_name == "rr")
		{
			ret.push_back("disabled");
			ret.push_back("rfe_on");
			ret.push_back("frg_on");
			ret.push_back("enabled");
			return ret;
		}
	}
	if(msg_name == ECU_PTT_STATUS)
	{
		if(sgn_name == "status")
		{
			ret.push_back("off");
			ret.push_back("on");
			return ret;
		}
	}
	if(msg_name == ECU_SET_PTT_STATUS)
	{
		if(sgn_name == "status")
		{
			ret.push_back("off");
			ret.push_back("on");
			return ret;
		}
	}
	if(msg_name == ECU_STEER_ACTUATOR_STATUS)
	{
		if(sgn_name == "status")
		{
			ret.push_back("off");
			ret.push_back("on");
			return ret;
		}
	}
	if(msg_name == ECU_SET_STEER_ACTUATOR_STATUS_STEERING_WHEEL)
	{
		if(sgn_name == "status")
		{
			ret.push_back("off");
			ret.push_back("on");
			return ret;
		}
	}
	if(msg_name == ECU_SET_STEER_ACTUATOR_STATUS_TLM)
	{
		if(sgn_name == "status")
		{
			ret.push_back("off");
			ret.push_back("on");
			return ret;
		}
	}
	if(msg_name == DEBUG_SIGNAL_1)
	{
		if(sgn_name == "device_id")
		{
			ret.push_back("hv_mainboard");
			ret.push_back("hv_cellboard");
			ret.push_back("lv");
			ret.push_back("ecu");
			ret.push_back("tlm");
			ret.push_back("traction_control");
			ret.push_back("steeering_wheel");
			ret.push_back("handcart");
			ret.push_back("acquisinator");
			return ret;
		}
	}
	if(msg_name == DEBUG_SIGNAL_2)
	{
		if(sgn_name == "device_id")
		{
			ret.push_back("hv_mainboard");
			ret.push_back("hv_cellboard");
			ret.push_back("lv");
			ret.push_back("ecu");
			ret.push_back("tlm");
			ret.push_back("traction_control");
			ret.push_back("steeering_wheel");
			ret.push_back("handcart");
			ret.push_back("acquisinator");
			return ret;
		}
	}
	if(msg_name == DEBUG_SIGNAL_3)
	{
		if(sgn_name == "device_id")
		{
			ret.push_back("hv_mainboard");
			ret.push_back("hv_cellboard");
			ret.push_back("lv");
			ret.push_back("ecu");
			ret.push_back("tlm");
			ret.push_back("traction_control");
			ret.push_back("steeering_wheel");
			ret.push_back("handcart");
			ret.push_back("acquisinator");
			return ret;
		}
	}
	if(msg_name == DEBUG_SIGNAL_4)
	{
		if(sgn_name == "device_id")
		{
			ret.push_back("hv_mainboard");
			ret.push_back("hv_cellboard");
			ret.push_back("lv");
			ret.push_back("ecu");
			ret.push_back("tlm");
			ret.push_back("traction_control");
			ret.push_back("steeering_wheel");
			ret.push_back("handcart");
			ret.push_back("acquisinator");
			return ret;
		}
	}

	return ret;
}
