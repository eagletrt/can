#include "primary_utils.h"

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
	case 1320:
		if(7 > fields_size) return 1;
		snprintf(v[0], string_size, IVT_MSG_RESULT_WH_IVT_ID_RESULT_WH);
		snprintf(v[1], string_size, IVT_MSG_RESULT_WH_IVT_RESULT_WH_SYSTEM_ERROR);
		snprintf(v[2], string_size, IVT_MSG_RESULT_WH_IVT_RESULT_WH_MEASUREMENT_ERROR);
		snprintf(v[3], string_size, IVT_MSG_RESULT_WH_IVT_RESULT_WH_CHANNEL_ERROR);
		snprintf(v[4], string_size, IVT_MSG_RESULT_WH_IVT_RESULT_WH_OCS);
		snprintf(v[5], string_size, IVT_MSG_RESULT_WH_IVT_MSGCOUNT_RESULT_WH);
		snprintf(v[6], string_size, IVT_MSG_RESULT_WH_IVT_RESULT_WH);

		return 0;
	case 1319:
		if(7 > fields_size) return 1;
		snprintf(v[0], string_size, IVT_MSG_RESULT_AS_IVT_ID_RESULT_AS);
		snprintf(v[1], string_size, IVT_MSG_RESULT_AS_IVT_RESULT_AS_SYSTEM_ERROR);
		snprintf(v[2], string_size, IVT_MSG_RESULT_AS_IVT_RESULT_AS_MEASUREMENT_ERROR);
		snprintf(v[3], string_size, IVT_MSG_RESULT_AS_IVT_RESULT_AS_CHANNEL_ERROR);
		snprintf(v[4], string_size, IVT_MSG_RESULT_AS_IVT_RESULT_AS_OCS);
		snprintf(v[5], string_size, IVT_MSG_RESULT_AS_IVT_MSGCOUNT_RESULT_AS);
		snprintf(v[6], string_size, IVT_MSG_RESULT_AS_IVT_RESULT_AS);

		return 0;
	case 1318:
		if(7 > fields_size) return 1;
		snprintf(v[0], string_size, IVT_MSG_RESULT_W_IVT_ID_RESULT_W);
		snprintf(v[1], string_size, IVT_MSG_RESULT_W_IVT_RESULT_W_SYSTEM_ERROR);
		snprintf(v[2], string_size, IVT_MSG_RESULT_W_IVT_RESULT_W_MEASUREMENT_ERROR);
		snprintf(v[3], string_size, IVT_MSG_RESULT_W_IVT_RESULT_W_CHANNEL_ERROR);
		snprintf(v[4], string_size, IVT_MSG_RESULT_W_IVT_RESULT_W_OCS);
		snprintf(v[5], string_size, IVT_MSG_RESULT_W_IVT_MSGCOUNT_RESULT_W);
		snprintf(v[6], string_size, IVT_MSG_RESULT_W_IVT_RESULT_W);

		return 0;
	case 1297:
		if(100 > fields_size) return 1;
		snprintf(v[0], string_size, IVT_MSG_RESPONSE_IVT_ID_RESPONSE);
		snprintf(v[1], string_size, IVT_MSG_RESPONSE__B1_TRIGGER_SPARE);
		snprintf(v[2], string_size, IVT_MSG_RESPONSE__FF_WRONG_COMMAND);
		snprintf(v[3], string_size, IVT_MSG_RESPONSE__BF_RESTART_ALIVE_CMD_ID);
		snprintf(v[4], string_size, IVT_MSG_RESPONSE__80_RESP_MEASERROR_ITEM);
		snprintf(v[5], string_size, IVT_MSG_RESPONSE__81_RESP_SYSTEMERROR_ITEM);
		snprintf(v[6], string_size, IVT_MSG_RESPONSE__82_RESP_ALLLOGDATA_ITEM);
		snprintf(v[7], string_size, IVT_MSG_RESPONSE__83_RESP_LOGDATA_ITEM);
		snprintf(v[8], string_size, IVT_MSG_RESPONSE__90_RESP_CAN_ID_VAL_I);
		snprintf(v[9], string_size, IVT_MSG_RESPONSE__91_RESP_CAN_ID_VAL_U1);
		snprintf(v[10], string_size, IVT_MSG_RESPONSE__92_RESP_CAN_ID_VAL_U2);
		snprintf(v[11], string_size, IVT_MSG_RESPONSE__93_RESP_CAN_ID_VAL_U3);
		snprintf(v[12], string_size, IVT_MSG_RESPONSE__94_RESP_CAN_ID_VAL_T);
		snprintf(v[13], string_size, IVT_MSG_RESPONSE__95_RESP_CAN_ID_VAL_W);
		snprintf(v[14], string_size, IVT_MSG_RESPONSE__96_RESP_CAN_ID_VAL_AS);
		snprintf(v[15], string_size, IVT_MSG_RESPONSE__97_RESP_CAN_ID_VAL_WH);
		snprintf(v[16], string_size, IVT_MSG_RESPONSE__9D_RESP_CAN_ID_VAL_COMMAND);
		snprintf(v[17], string_size, IVT_MSG_RESPONSE__9F_RESP_CAN_ID_VAL_RESPONSE);
		snprintf(v[18], string_size, IVT_MSG_RESPONSE__A0_RESP_SIGN_I);
		snprintf(v[19], string_size, IVT_MSG_RESPONSE__A1_RESP_SIGN_U1);
		snprintf(v[20], string_size, IVT_MSG_RESPONSE__A2_RESP_SIGN_U2);
		snprintf(v[21], string_size, IVT_MSG_RESPONSE__A3_RESP_SIGN_U3);
		snprintf(v[22], string_size, IVT_MSG_RESPONSE__A4_RESP_SIGN_T);
		snprintf(v[23], string_size, IVT_MSG_RESPONSE__A5_RESP_SIGN_W);
		snprintf(v[24], string_size, IVT_MSG_RESPONSE__A6_RESP_SIGN_AS);
		snprintf(v[25], string_size, IVT_MSG_RESPONSE__A7_RESP_SIGN_WH);
		snprintf(v[26], string_size, IVT_MSG_RESPONSE__B0_RESP_RESET_ITEM);
		snprintf(v[27], string_size, IVT_MSG_RESPONSE__B2_RESP_STORE_DUMMY);
		snprintf(v[28], string_size, IVT_MSG_RESPONSE__B3_RESP_OC_TEST_TIME);
		snprintf(v[29], string_size, IVT_MSG_RESPONSE__B5_RESP_OC_POS_SET_THRESHOLD);
		snprintf(v[30], string_size, IVT_MSG_RESPONSE__B6_RESP_OC_NEG_SET_THRESHOLD);
		snprintf(v[31], string_size, IVT_MSG_RESPONSE__B9_RESP_DEVICE_TYPE);
		snprintf(v[32], string_size, IVT_MSG_RESPONSE__BA_RESP_SW_VER_MAJOR_HW);
		snprintf(v[33], string_size, IVT_MSG_RESPONSE__BB_RESP_SERIEN_NR);
		snprintf(v[34], string_size, IVT_MSG_RESPONSE__BC_RESP_ART_N);
		snprintf(v[35], string_size, IVT_MSG_RESPONSE__A0_RESP_ENDIANESS_I);
		snprintf(v[36], string_size, IVT_MSG_RESPONSE__A1_RESP_ENDIANESS_U1);
		snprintf(v[37], string_size, IVT_MSG_RESPONSE__A2_RESP_ENDIANESS_U2);
		snprintf(v[38], string_size, IVT_MSG_RESPONSE__A3_RESP_ENDIANESS_U3);
		snprintf(v[39], string_size, IVT_MSG_RESPONSE__A4_RESP_ENDIANESS_T);
		snprintf(v[40], string_size, IVT_MSG_RESPONSE__A5_RESP_ENDIANESS_W);
		snprintf(v[41], string_size, IVT_MSG_RESPONSE__A6_RESP_ENDIANESS_AS);
		snprintf(v[42], string_size, IVT_MSG_RESPONSE__A7_RESP_ENDIANESS_WH);
		snprintf(v[43], string_size, IVT_MSG_RESPONSE__A0_RESP_TRIGGERMODE_I);
		snprintf(v[44], string_size, IVT_MSG_RESPONSE__A1_RESP_TRIGGERMODE_U1);
		snprintf(v[45], string_size, IVT_MSG_RESPONSE__A2_RESP_TRIGGERMODE_U2);
		snprintf(v[46], string_size, IVT_MSG_RESPONSE__A3_RESP_TRIGGERMODE_U3);
		snprintf(v[47], string_size, IVT_MSG_RESPONSE__A4_RESP_TRIGGERMODE_T);
		snprintf(v[48], string_size, IVT_MSG_RESPONSE__A5_RESP_TRIGGERMODE_W);
		snprintf(v[49], string_size, IVT_MSG_RESPONSE__A6_RESP_TRIGGERMODE_AS);
		snprintf(v[50], string_size, IVT_MSG_RESPONSE__A7_RESP_TRIGGERMODE_WH);
		snprintf(v[51], string_size, IVT_MSG_RESPONSE__B4_RESP_ACTUAL_MODE);
		snprintf(v[52], string_size, IVT_MSG_RESPONSE__B1_07_TRIGGER_WH);
		snprintf(v[53], string_size, IVT_MSG_RESPONSE__B2_RESP_STORE_DEVICE_SN);
		snprintf(v[54], string_size, IVT_MSG_RESPONSE__BA_RESP_SW_VER_MINOR);
		snprintf(v[55], string_size, IVT_MSG_RESPONSE__B9_RESP_DEVICE_CURRENT);
		snprintf(v[56], string_size, IVT_MSG_RESPONSE__80_RESP_MEASERROR_COUNT_MASK);
		snprintf(v[57], string_size, IVT_MSG_RESPONSE__81_RESP_SYSTEMERROR_COUNT_MASK);
		snprintf(v[58], string_size, IVT_MSG_RESPONSE__82_RESP_ALLLOGDATA_COUNTER);
		snprintf(v[59], string_size, IVT_MSG_RESPONSE__83_RESP_LOGDATA_COUNTER);
		snprintf(v[60], string_size, IVT_MSG_RESPONSE__A0_RESP_CYCLETIME_I);
		snprintf(v[61], string_size, IVT_MSG_RESPONSE__A1_RESP_CYCLETIME_U1);
		snprintf(v[62], string_size, IVT_MSG_RESPONSE__A2_RESP_CYCLETIME_U2);
		snprintf(v[63], string_size, IVT_MSG_RESPONSE__A3_RESP_CYCLETIME_U3);
		snprintf(v[64], string_size, IVT_MSG_RESPONSE__A4_RESP_CYCLETIME_T);
		snprintf(v[65], string_size, IVT_MSG_RESPONSE__A5_RESP_CYCLETIME_W);
		snprintf(v[66], string_size, IVT_MSG_RESPONSE__A6_RESP_CYCLETIME_AS);
		snprintf(v[67], string_size, IVT_MSG_RESPONSE__A7_RESP_CYCLETIME_WH);
		snprintf(v[68], string_size, IVT_MSG_RESPONSE__B1_06_TRIGGER_AS);
		snprintf(v[69], string_size, IVT_MSG_RESPONSE__B1_05_TRIGGER_W);
		snprintf(v[70], string_size, IVT_MSG_RESPONSE__B1_04_TRIGGER_T);
		snprintf(v[71], string_size, IVT_MSG_RESPONSE__B1_03_TRIGGER_U3);
		snprintf(v[72], string_size, IVT_MSG_RESPONSE__B1_02_TRIGGER_U2);
		snprintf(v[73], string_size, IVT_MSG_RESPONSE__B1_01_TRIGGER_U1);
		snprintf(v[74], string_size, IVT_MSG_RESPONSE__B1_00_TRIGGER_I);
		snprintf(v[75], string_size, IVT_MSG_RESPONSE__B4_RESP_STARTUP_MODE);
		snprintf(v[76], string_size, IVT_MSG_RESPONSE__BF_RESTART_ALIVE_SN);
		snprintf(v[77], string_size, IVT_MSG_RESPONSE__BA_RESP_SW_VER_REVISION);
		snprintf(v[78], string_size, IVT_MSG_RESPONSE__90_RESP_CAN_ID_SN_I);
		snprintf(v[79], string_size, IVT_MSG_RESPONSE__91_RESP_CAN_ID_SN_U1);
		snprintf(v[80], string_size, IVT_MSG_RESPONSE__92_RESP_CAN_ID_SN_U2);
		snprintf(v[81], string_size, IVT_MSG_RESPONSE__93_RESP_CAN_ID_SN_U3);
		snprintf(v[82], string_size, IVT_MSG_RESPONSE__94_RESP_CAN_ID_SN_T);
		snprintf(v[83], string_size, IVT_MSG_RESPONSE__95_RESP_CAN_ID_SN_W);
		snprintf(v[84], string_size, IVT_MSG_RESPONSE__96_RESP_CAN_ID_SN_AS);
		snprintf(v[85], string_size, IVT_MSG_RESPONSE__97_RESP_CAN_ID_SN_WH);
		snprintf(v[86], string_size, IVT_MSG_RESPONSE__9D_RESP_CAN_ID_SN_COMMAND);
		snprintf(v[87], string_size, IVT_MSG_RESPONSE__9F_RESP_CAN_ID_SN_RESPONSE);
		snprintf(v[88], string_size, IVT_MSG_RESPONSE__B0_RESP_RESET_DEVICE_SN);
		snprintf(v[89], string_size, IVT_MSG_RESPONSE__B4_RESP_CODE_LEVEL);
		snprintf(v[90], string_size, IVT_MSG_RESPONSE__B5_RESP_OC_POS_RESET_THRESHOLD);
		snprintf(v[91], string_size, IVT_MSG_RESPONSE__B6_RESP_OC_NEG_RESET_THRESHOLD);
		snprintf(v[92], string_size, IVT_MSG_RESPONSE__B9_RESP_DEVICE_VOLTAGE_CHAN);
		snprintf(v[93], string_size, IVT_MSG_RESPONSE__BA_RESP_SW_VER_VEAR);
		snprintf(v[94], string_size, IVT_MSG_RESPONSE__B9_RESP_DEVICE_TOI);
		snprintf(v[95], string_size, IVT_MSG_RESPONSE__BA_RESP_SW_VER_MONTH);
		snprintf(v[96], string_size, IVT_MSG_RESPONSE__B9_RESP_DEVICE_COM);
		snprintf(v[97], string_size, IVT_MSG_RESPONSE__BA_RESP_SW_VER_DAY);
		snprintf(v[98], string_size, IVT_MSG_RESPONSE__B9_RESP_DEVICE_V_SUPPLY);
		snprintf(v[99], string_size, IVT_MSG_RESPONSE__BA_RESP_SW_VER_INTERNAL);

		return 0;
	case 1317:
		if(7 > fields_size) return 1;
		snprintf(v[0], string_size, IVT_MSG_RESULT_T_IVT_ID_RESULT_T);
		snprintf(v[1], string_size, IVT_MSG_RESULT_T_IVT_RESULT_T_SYSTEM_ERROR);
		snprintf(v[2], string_size, IVT_MSG_RESULT_T_IVT_RESULT_T_MEASUREMENT_ERROR);
		snprintf(v[3], string_size, IVT_MSG_RESULT_T_IVT_RESULT_T_CHANNEL_ERROR);
		snprintf(v[4], string_size, IVT_MSG_RESULT_T_IVT_RESULT_T_OCS);
		snprintf(v[5], string_size, IVT_MSG_RESULT_T_IVT_MSGCOUNT_RESULT_T);
		snprintf(v[6], string_size, IVT_MSG_RESULT_T_IVT_RESULT_T);

		return 0;
	case 1316:
		if(7 > fields_size) return 1;
		snprintf(v[0], string_size, IVT_MSG_RESULT_U3_IVT_ID_RESULT_U3);
		snprintf(v[1], string_size, IVT_MSG_RESULT_U3_IVT_RESULT_U3_SYSTEM_ERROR);
		snprintf(v[2], string_size, IVT_MSG_RESULT_U3_IVT_RESULT_U3_MEASUREMENT_ERROR);
		snprintf(v[3], string_size, IVT_MSG_RESULT_U3_IVT_RESULT_U3_CHANNEL_ERROR);
		snprintf(v[4], string_size, IVT_MSG_RESULT_U3_IVT_RESULT_U3_OCS);
		snprintf(v[5], string_size, IVT_MSG_RESULT_U3_IVT_MSGCOUNT_RESULT_U3);
		snprintf(v[6], string_size, IVT_MSG_RESULT_U3_IVT_RESULT_U3);

		return 0;
	case 1315:
		if(7 > fields_size) return 1;
		snprintf(v[0], string_size, IVT_MSG_RESULT_U2_IVT_ID_RESULT_U2);
		snprintf(v[1], string_size, IVT_MSG_RESULT_U2_IVT_RESULT_U2_SYSTEM_ERROR);
		snprintf(v[2], string_size, IVT_MSG_RESULT_U2_IVT_RESULT_U2_MEASUREMENT_ERROR);
		snprintf(v[3], string_size, IVT_MSG_RESULT_U2_IVT_RESULT_U2_CHANNEL_ERROR);
		snprintf(v[4], string_size, IVT_MSG_RESULT_U2_IVT_RESULT_U2_OCS);
		snprintf(v[5], string_size, IVT_MSG_RESULT_U2_IVT_MSGCOUNT_RESULT_U2);
		snprintf(v[6], string_size, IVT_MSG_RESULT_U2_IVT_RESULT_U2);

		return 0;
	case 1314:
		if(7 > fields_size) return 1;
		snprintf(v[0], string_size, IVT_MSG_RESULT_U1_IVT_ID_RESULT_U1);
		snprintf(v[1], string_size, IVT_MSG_RESULT_U1_IVT_RESULT_U1_SYSTEM_ERROR);
		snprintf(v[2], string_size, IVT_MSG_RESULT_U1_IVT_RESULT_U1_MEASUREMENT_ERROR);
		snprintf(v[3], string_size, IVT_MSG_RESULT_U1_IVT_RESULT_U1_CHANNEL_ERROR);
		snprintf(v[4], string_size, IVT_MSG_RESULT_U1_IVT_RESULT_U1_OCS);
		snprintf(v[5], string_size, IVT_MSG_RESULT_U1_IVT_MSGCOUNT_RESULT_U1);
		snprintf(v[6], string_size, IVT_MSG_RESULT_U1_IVT_RESULT_U1);

		return 0;
	case 1313:
		if(7 > fields_size) return 1;
		snprintf(v[0], string_size, IVT_MSG_RESULT_I_IVT_ID_RESULT_I);
		snprintf(v[1], string_size, IVT_MSG_RESULT_I_IVT_RESULT_I_SYSTEM_ERROR);
		snprintf(v[2], string_size, IVT_MSG_RESULT_I_IVT_RESULT_I_MEASUREMENT_ERROR);
		snprintf(v[3], string_size, IVT_MSG_RESULT_I_IVT_RESULT_I_CHANNEL_ERROR);
		snprintf(v[4], string_size, IVT_MSG_RESULT_I_IVT_RESULT_I_OCS);
		snprintf(v[5], string_size, IVT_MSG_RESULT_I_IVT_MSGCOUNT_RESULT_I);
		snprintf(v[6], string_size, IVT_MSG_RESULT_I_IVT_RESULT_I);

		return 0;
	case 1041:
		if(106 > fields_size) return 1;
		snprintf(v[0], string_size, IVT_MSG_CMD_IVT_ID_CMD);
		snprintf(v[1], string_size, IVT_MSG_CMD__31_TRIGGER_SPARE);
		snprintf(v[2], string_size, IVT_MSG_CMD__10_SET_CAN_ID_VAL_I);
		snprintf(v[3], string_size, IVT_MSG_CMD__11_SET_CAN_ID_VAL_U1);
		snprintf(v[4], string_size, IVT_MSG_CMD__12_SET_CAN_ID_VAL_U2);
		snprintf(v[5], string_size, IVT_MSG_CMD__13_SET_CAN_ID_VAL_U3);
		snprintf(v[6], string_size, IVT_MSG_CMD__14_SET_CAN_ID_VAL_T);
		snprintf(v[7], string_size, IVT_MSG_CMD__15_SET_CAN_ID_VAL_W);
		snprintf(v[8], string_size, IVT_MSG_CMD__16_SET_CAN_ID_VAL_AS);
		snprintf(v[9], string_size, IVT_MSG_CMD__17_SET_CAN_ID_VAL_WH);
		snprintf(v[10], string_size, IVT_MSG_CMD__1D_SET_CAN_ID_VAL_COMMAND);
		snprintf(v[11], string_size, IVT_MSG_CMD__1F_SET_CAN_ID_VAL_RESPONSE);
		snprintf(v[12], string_size, IVT_MSG_CMD__20_CONF_SIGN_I);
		snprintf(v[13], string_size, IVT_MSG_CMD__21_CONF_SIGN_U1);
		snprintf(v[14], string_size, IVT_MSG_CMD__22_CONF_SIGN_U2);
		snprintf(v[15], string_size, IVT_MSG_CMD__23_CONF_SIGN_U3);
		snprintf(v[16], string_size, IVT_MSG_CMD__24_CONF_SIGN_T);
		snprintf(v[17], string_size, IVT_MSG_CMD__25_CONF_SIGN_W);
		snprintf(v[18], string_size, IVT_MSG_CMD__26_CONF_SIGN_AS);
		snprintf(v[19], string_size, IVT_MSG_CMD__27_CONF_SIGN_WH);
		snprintf(v[20], string_size, IVT_MSG_CMD__30_RESET_ITEM);
		snprintf(v[21], string_size, IVT_MSG_CMD__32_STORE_DUMMY);
		snprintf(v[22], string_size, IVT_MSG_CMD__33_OC_TEST_TIME);
		snprintf(v[23], string_size, IVT_MSG_CMD__35_OC_POS_SET_THRESHOLD);
		snprintf(v[24], string_size, IVT_MSG_CMD__36_OC_NEG_SET_THRESHOLD);
		snprintf(v[25], string_size, IVT_MSG_CMD__3A_RESTART_TO_BITRATE);
		snprintf(v[26], string_size, IVT_MSG_CMD__3D_RESTART_DEFAULT_DUMMY);
		snprintf(v[27], string_size, IVT_MSG_CMD__3F_RESTART_DUMMY);
		snprintf(v[28], string_size, IVT_MSG_CMD__40_GET_MEASERROR_ITEM);
		snprintf(v[29], string_size, IVT_MSG_CMD__41_GET_SYSTEMERROR_ITEM);
		snprintf(v[30], string_size, IVT_MSG_CMD__42_GET_ALLLOGDATA_ITEM);
		snprintf(v[31], string_size, IVT_MSG_CMD__43_GET_LOGDATA_ITEM);
		snprintf(v[32], string_size, IVT_MSG_CMD__60_GET_RESULT_DUMMY_I);
		snprintf(v[33], string_size, IVT_MSG_CMD__61_GET_RESULT_DUMMY_U1);
		snprintf(v[34], string_size, IVT_MSG_CMD__62_GET_RESULT_DUMMY_U2);
		snprintf(v[35], string_size, IVT_MSG_CMD__63_GET_RESULT_DUMMY_U3);
		snprintf(v[36], string_size, IVT_MSG_CMD__64_GET_RESULT_DUMMY_T);
		snprintf(v[37], string_size, IVT_MSG_CMD__65_GET_RESULT_DUMMY_W);
		snprintf(v[38], string_size, IVT_MSG_CMD__66_GET_RESULT_DUMMY_AS);
		snprintf(v[39], string_size, IVT_MSG_CMD__67_GET_RESULT_DUMMY_WH);
		snprintf(v[40], string_size, IVT_MSG_CMD__73_GET_OC_TEST_DUMMY);
		snprintf(v[41], string_size, IVT_MSG_CMD__74_GET_MODE_DUMMY);
		snprintf(v[42], string_size, IVT_MSG_CMD__75_GET_OC_POS_DUMMY);
		snprintf(v[43], string_size, IVT_MSG_CMD__76_GET_OC_NEG_DUMMY);
		snprintf(v[44], string_size, IVT_MSG_CMD__79_GET_DEVICE_ID_DUMMY);
		snprintf(v[45], string_size, IVT_MSG_CMD__7A_GET_SW_VERSION_DUMMY);
		snprintf(v[46], string_size, IVT_MSG_CMD__7B_GET_SERIEN_NR_DUMMY);
		snprintf(v[47], string_size, IVT_MSG_CMD__7C_GET_ART_NR_DUMMY);
		snprintf(v[48], string_size, IVT_MSG_CMD__20_CONF_ENDIANESS_I);
		snprintf(v[49], string_size, IVT_MSG_CMD__21_CONF_ENDIANESS_U1);
		snprintf(v[50], string_size, IVT_MSG_CMD__22_CONF_ENDIANESS_U2);
		snprintf(v[51], string_size, IVT_MSG_CMD__23_CONF_ENDIANESS_U3);
		snprintf(v[52], string_size, IVT_MSG_CMD__24_CONF_ENDIANESS_T);
		snprintf(v[53], string_size, IVT_MSG_CMD__25_CONF_ENDIANESS_W);
		snprintf(v[54], string_size, IVT_MSG_CMD__26_CONF_ENDIANESS_AS);
		snprintf(v[55], string_size, IVT_MSG_CMD__27_CONF_ENDIANESS_WH);
		snprintf(v[56], string_size, IVT_MSG_CMD__20_CONF_TRIGGERMODE_I);
		snprintf(v[57], string_size, IVT_MSG_CMD__21_CONF_TRIGGERMODE_U1);
		snprintf(v[58], string_size, IVT_MSG_CMD__22_CONF_TRIGGERMODE_U2);
		snprintf(v[59], string_size, IVT_MSG_CMD__23_CONF_TRIGGERMODE_U3);
		snprintf(v[60], string_size, IVT_MSG_CMD__24_CONF_TRIGGERMODE_T);
		snprintf(v[61], string_size, IVT_MSG_CMD__25_CONF_TRIGGERMODE_W);
		snprintf(v[62], string_size, IVT_MSG_CMD__26_CONF_TRIGGERMODE_AS);
		snprintf(v[63], string_size, IVT_MSG_CMD__27_CONF_TRIGGERMODE_WH);
		snprintf(v[64], string_size, IVT_MSG_CMD__34_ACTUAL_MODE);
		snprintf(v[65], string_size, IVT_MSG_CMD__31_07_TRIGGER_WH);
		snprintf(v[66], string_size, IVT_MSG_CMD__20_CONF_CYCLETIME_I);
		snprintf(v[67], string_size, IVT_MSG_CMD__21_CONF_CYCLETIME_U1);
		snprintf(v[68], string_size, IVT_MSG_CMD__22_CONF_CYCLETIME_U2);
		snprintf(v[69], string_size, IVT_MSG_CMD__23_CONF_CYCLETIME_U3);
		snprintf(v[70], string_size, IVT_MSG_CMD__24_CONF_CYCLETIME_T);
		snprintf(v[71], string_size, IVT_MSG_CMD__25_CONF_CYCLETIME_W);
		snprintf(v[72], string_size, IVT_MSG_CMD__26_CONF_CYCLETIME_AS);
		snprintf(v[73], string_size, IVT_MSG_CMD__27_CONF_CYCLETIME_WH);
		snprintf(v[74], string_size, IVT_MSG_CMD__31_06_TRIGGER_AS);
		snprintf(v[75], string_size, IVT_MSG_CMD__31_05_TRIGGER_W);
		snprintf(v[76], string_size, IVT_MSG_CMD__31_04_TRIGGER_T);
		snprintf(v[77], string_size, IVT_MSG_CMD__31_03_TRIGGER_U3);
		snprintf(v[78], string_size, IVT_MSG_CMD__31_02_TRIGGER_U2);
		snprintf(v[79], string_size, IVT_MSG_CMD__31_01_TRIGGER_U1);
		snprintf(v[80], string_size, IVT_MSG_CMD__31_00_TRIGGER_I);
		snprintf(v[81], string_size, IVT_MSG_CMD__34_STARTUP_MODE);
		snprintf(v[82], string_size, IVT_MSG_CMD__10_SET_CAN_ID_SN_I);
		snprintf(v[83], string_size, IVT_MSG_CMD__11_SET_CAN_ID_SN_U1);
		snprintf(v[84], string_size, IVT_MSG_CMD__12_SET_CAN_ID_SN_U2);
		snprintf(v[85], string_size, IVT_MSG_CMD__13_SET_CAN_ID_SN_U3);
		snprintf(v[86], string_size, IVT_MSG_CMD__14_SET_CAN_ID_SN_T);
		snprintf(v[87], string_size, IVT_MSG_CMD__15_SET_CAN_ID_SN_W);
		snprintf(v[88], string_size, IVT_MSG_CMD__16_SET_CAN_ID_SN_AS);
		snprintf(v[89], string_size, IVT_MSG_CMD__17_SET_CAN_ID_SN_WH);
		snprintf(v[90], string_size, IVT_MSG_CMD__1D_SET_CAN_ID_SN_COMMAND);
		snprintf(v[91], string_size, IVT_MSG_CMD__1F_SET_CAN_ID_SN_RESPONSE);
		snprintf(v[92], string_size, IVT_MSG_CMD__30_RESET_DEVICE_SN);
		snprintf(v[93], string_size, IVT_MSG_CMD__34_CODE_LEVEL);
		snprintf(v[94], string_size, IVT_MSG_CMD__35_OC_POS_RESET_THRESHOLD);
		snprintf(v[95], string_size, IVT_MSG_CMD__36_OC_NEG_RESET_THRESHOLD);
		snprintf(v[96], string_size, IVT_MSG_CMD__50_GET_CAN_ID_SN_I);
		snprintf(v[97], string_size, IVT_MSG_CMD__51_GET_CAN_ID_SN_U1);
		snprintf(v[98], string_size, IVT_MSG_CMD__52_GET_CAN_ID_SN_U2);
		snprintf(v[99], string_size, IVT_MSG_CMD__53_GET_CAN_ID_SN_U3);
		snprintf(v[100], string_size, IVT_MSG_CMD__54_GET_CAN_ID_SN_T);
		snprintf(v[101], string_size, IVT_MSG_CMD__55_GET_CAN_ID_SN_W);
		snprintf(v[102], string_size, IVT_MSG_CMD__56_GET_CAN_ID_SN_AS);
		snprintf(v[103], string_size, IVT_MSG_CMD__57_GET_CAN_ID_SN_WH);
		snprintf(v[104], string_size, IVT_MSG_CMD__5D_GET_CAN_ID_SN_COMMAND);
		snprintf(v[105], string_size, IVT_MSG_CMD__5F_GET_CAN_ID_SN_RESPONSE);

		return 0;
	case 0:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, HV_FLASH_START);
		snprintf(v[1], string_size, HV_FLASH_FORWARD);
		snprintf(v[2], string_size, HV_FLASH_CELLBOARD_ID);

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
		snprintf(v[1], string_size, HV_CELLBOARD_VERSION_CANLIB_BUILD_TIME);
		snprintf(v[2], string_size, HV_CELLBOARD_VERSION_COMPONENT_BUILD_TIME);

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
		if(32 > fields_size) return 1;
		snprintf(v[0], string_size, HV_FEEDBACK_STATUS_AIRN_OPEN_COM);
		snprintf(v[1], string_size, HV_FEEDBACK_STATUS_PRECHARGE_OPEN_COM);
		snprintf(v[2], string_size, HV_FEEDBACK_STATUS_AIRP_OPEN_COM);
		snprintf(v[3], string_size, HV_FEEDBACK_STATUS_AIRN_OPEN_MEC);
		snprintf(v[4], string_size, HV_FEEDBACK_STATUS_PRECHARGE_OPEN_MEC);
		snprintf(v[5], string_size, HV_FEEDBACK_STATUS_AIRP_OPEN_MEC);
		snprintf(v[6], string_size, HV_FEEDBACK_STATUS_SD_IMD_FB);
		snprintf(v[7], string_size, HV_FEEDBACK_STATUS_SD_BMS_FB);
		snprintf(v[8], string_size, HV_FEEDBACK_STATUS_TS_LESS_THAN_60V);
		snprintf(v[9], string_size, HV_FEEDBACK_STATUS_PLAUSIBLE_STATE_PERSISTED);
		snprintf(v[10], string_size, HV_FEEDBACK_STATUS_PLAUSIBLE_STATE);
		snprintf(v[11], string_size, HV_FEEDBACK_STATUS_NOT_BMS_FAULT_COCKPIT_LED);
		snprintf(v[12], string_size, HV_FEEDBACK_STATUS_NOT_IMD_FAULT_COCKPIT_LED);
		snprintf(v[13], string_size, HV_FEEDBACK_STATUS_INDICATOR_CONNECTED);
		snprintf(v[14], string_size, HV_FEEDBACK_STATUS_NOT_LATCH_RESET);
		snprintf(v[15], string_size, HV_FEEDBACK_STATUS_PLAUSIBLE_STATE_LATCHED);
		snprintf(v[16], string_size, HV_FEEDBACK_STATUS_NOT_BMS_FAULT_LATCHED);
		snprintf(v[17], string_size, HV_FEEDBACK_STATUS_NOT_IMD_FAULT_LATCHED);
		snprintf(v[18], string_size, HV_FEEDBACK_STATUS_NOT_EXT_FAULT_LATCHED);
		snprintf(v[19], string_size, HV_FEEDBACK_STATUS_IMD_OK);
		snprintf(v[20], string_size, HV_FEEDBACK_STATUS_PLAUSIBLE_STATE_RC);
		snprintf(v[21], string_size, HV_FEEDBACK_STATUS_TSAL_GREEN);
		snprintf(v[22], string_size, HV_FEEDBACK_STATUS_PROBING_3V3);
		snprintf(v[23], string_size, HV_FEEDBACK_STATUS_SD_OUT);
		snprintf(v[24], string_size, HV_FEEDBACK_STATUS_SD_IN);
		snprintf(v[25], string_size, HV_FEEDBACK_STATUS_SD_END);
		snprintf(v[26], string_size, HV_FEEDBACK_STATUS_V5_MCU);
		snprintf(v[27], string_size, HV_FEEDBACK_STATUS_FEEDBACK_TSAL_GREEN_FAULT_LATCHED);
		snprintf(v[28], string_size, HV_FEEDBACK_STATUS_FEEDBACK_EXT_LATCHED);
		snprintf(v[29], string_size, HV_FEEDBACK_STATUS_FEEDBACK_PRECHARGE_STATUS);
		snprintf(v[30], string_size, HV_FEEDBACK_STATUS_FEEDBACK_TSP_OVER_60V_STATUS);
		snprintf(v[31], string_size, HV_FEEDBACK_STATUS_FEEDBACK_CHECK_MUX);

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
		if(8 > fields_size) return 1;
		snprintf(v[0], string_size, HV_IMD_STATUS_STATUS);
		snprintf(v[1], string_size, HV_IMD_STATUS_FREQUENCY);
		snprintf(v[2], string_size, HV_IMD_STATUS_DUTY_CYCLE);
		snprintf(v[3], string_size, HV_IMD_STATUS_FEEDBACK_NOT_IMD_FAULT_COCKPIT_LED);
		snprintf(v[4], string_size, HV_IMD_STATUS_FEEDBACK_NOT_IMD_FAULT_LATCHED);
		snprintf(v[5], string_size, HV_IMD_STATUS_IMD_FAULT);
		snprintf(v[6], string_size, HV_IMD_STATUS_IMD_DETAILS);
		snprintf(v[7], string_size, HV_IMD_STATUS_IMD_PERIOD);

		return 0;
	case 560:
		if(7 > fields_size) return 1;
		snprintf(v[0], string_size, HV_STATUS_STATUS);
		snprintf(v[1], string_size, HV_STATUS_CELLBOARD_0);
		snprintf(v[2], string_size, HV_STATUS_CELLBOARD_1);
		snprintf(v[3], string_size, HV_STATUS_CELLBOARD_2);
		snprintf(v[4], string_size, HV_STATUS_CELLBOARD_3);
		snprintf(v[5], string_size, HV_STATUS_CELLBOARD_4);
		snprintf(v[6], string_size, HV_STATUS_CELLBOARD_5);

		return 0;
	case 40:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, HV_SET_STATUS_ECU_STATUS);
		snprintf(v[1], string_size, HV_SET_STATUS_ECU_HV_STATUS_SET);

		return 0;
	case 48:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, HV_SET_STATUS_HANDCART_STATUS);
		snprintf(v[1], string_size, HV_SET_STATUS_HANDCART_HV_STATUS_SET);

		return 0;
	case 1544:
		if(54 > fields_size) return 1;
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
		snprintf(v[29], string_size, HV_BALANCING_STATUS_STATUS);
		snprintf(v[30], string_size, HV_BALANCING_STATUS_DISCHARGING_CELL_0);
		snprintf(v[31], string_size, HV_BALANCING_STATUS_DISCHARGING_CELL_1);
		snprintf(v[32], string_size, HV_BALANCING_STATUS_DISCHARGING_CELL_2);
		snprintf(v[33], string_size, HV_BALANCING_STATUS_DISCHARGING_CELL_3);
		snprintf(v[34], string_size, HV_BALANCING_STATUS_DISCHARGING_CELL_4);
		snprintf(v[35], string_size, HV_BALANCING_STATUS_DISCHARGING_CELL_5);
		snprintf(v[36], string_size, HV_BALANCING_STATUS_DISCHARGING_CELL_6);
		snprintf(v[37], string_size, HV_BALANCING_STATUS_DISCHARGING_CELL_7);
		snprintf(v[38], string_size, HV_BALANCING_STATUS_DISCHARGING_CELL_8);
		snprintf(v[39], string_size, HV_BALANCING_STATUS_DISCHARGING_CELL_9);
		snprintf(v[40], string_size, HV_BALANCING_STATUS_DISCHARGING_CELL_10);
		snprintf(v[41], string_size, HV_BALANCING_STATUS_DISCHARGING_CELL_11);
		snprintf(v[42], string_size, HV_BALANCING_STATUS_DISCHARGING_CELL_12);
		snprintf(v[43], string_size, HV_BALANCING_STATUS_DISCHARGING_CELL_13);
		snprintf(v[44], string_size, HV_BALANCING_STATUS_DISCHARGING_CELL_14);
		snprintf(v[45], string_size, HV_BALANCING_STATUS_DISCHARGING_CELL_15);
		snprintf(v[46], string_size, HV_BALANCING_STATUS_DISCHARGING_CELL_16);
		snprintf(v[47], string_size, HV_BALANCING_STATUS_DISCHARGING_CELL_17);
		snprintf(v[48], string_size, HV_BALANCING_STATUS_DISCHARGING_CELL_18);
		snprintf(v[49], string_size, HV_BALANCING_STATUS_DISCHARGING_CELL_19);
		snprintf(v[50], string_size, HV_BALANCING_STATUS_DISCHARGING_CELL_20);
		snprintf(v[51], string_size, HV_BALANCING_STATUS_DISCHARGING_CELL_21);
		snprintf(v[52], string_size, HV_BALANCING_STATUS_DISCHARGING_CELL_22);
		snprintf(v[53], string_size, HV_BALANCING_STATUS_DISCHARGING_CELL_23);

		return 0;
	case 1032:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, HV_SET_BALANCING_STATUS_STEERING_WHEEL_STATUS);
		snprintf(v[1], string_size, HV_SET_BALANCING_STATUS_STEERING_WHEEL_THRESHOLD);
		snprintf(v[2], string_size, HV_SET_BALANCING_STATUS_STEERING_WHEEL_SET_BALANCING_STATUS);
		snprintf(v[3], string_size, HV_SET_BALANCING_STATUS_STEERING_WHEEL_BALANCING_THRESHOLD);

		return 0;
	case 1040:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, HV_SET_BALANCING_STATUS_HANDCART_STATUS);
		snprintf(v[1], string_size, HV_SET_BALANCING_STATUS_HANDCART_THRESHOLD);
		snprintf(v[2], string_size, HV_SET_BALANCING_STATUS_HANDCART_SET_BALANCING_STATUS);
		snprintf(v[3], string_size, HV_SET_BALANCING_STATUS_HANDCART_BALANCING_THRESHOLD);

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
		snprintf(v[1], string_size, ECU_CONTROL_STATUS_CONTROL_ERRORS_DISABLED_FROM_ECU);
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
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, ECU_POWER_MAPS_MAP_POWER);
		snprintf(v[1], string_size, ECU_POWER_MAPS_SC_STATE);
		snprintf(v[2], string_size, ECU_POWER_MAPS_TV_STATE);
		snprintf(v[3], string_size, ECU_POWER_MAPS_REG_STATE);

		return 0;
	case 96:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, ECU_SET_POWER_MAPS_MAP_POWER);
		snprintf(v[1], string_size, ECU_SET_POWER_MAPS_SC_STATE);
		snprintf(v[2], string_size, ECU_SET_POWER_MAPS_TV_STATE);
		snprintf(v[3], string_size, ECU_SET_POWER_MAPS_REG_STATE);

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
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, CONTROL_STATUS_MAP_POWER);
		snprintf(v[1], string_size, CONTROL_STATUS_SC_STATE);
		snprintf(v[2], string_size, CONTROL_STATUS_TV_STATE);
		snprintf(v[3], string_size, CONTROL_STATUS_REG_STATE);

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
		if(5 > fields_size) return 1;
		snprintf(v[0], string_size, HV_CELLS_VOLTAGE_CELLBOARD_ID);
		snprintf(v[1], string_size, HV_CELLS_VOLTAGE_OFFSET);
		snprintf(v[2], string_size, HV_CELLS_VOLTAGE_VOLTAGE_0);
		snprintf(v[3], string_size, HV_CELLS_VOLTAGE_VOLTAGE_1);
		snprintf(v[4], string_size, HV_CELLS_VOLTAGE_VOLTAGE_2);

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
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, AS_COMMANDS_STATUS_STEERSTATUS);
		snprintf(v[1], string_size, AS_COMMANDS_STATUS_THROTTLESTATUS);
		snprintf(v[2], string_size, AS_COMMANDS_STATUS_BRAKESTATUS);

		return 0;
	case 1104:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, AS_COMMANDS_SET_STATUS_STEERSTATUS);
		snprintf(v[1], string_size, AS_COMMANDS_SET_STATUS_THROTTLESTATUS);
		snprintf(v[2], string_size, AS_COMMANDS_SET_STATUS_BRAKESTATUS);

		return 0;
	case 1760:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, AS_COMMANDS_SET_VALUE_STEERANGLE);
		snprintf(v[1], string_size, AS_COMMANDS_SET_VALUE_THROTTLE);
		snprintf(v[2], string_size, AS_COMMANDS_SET_VALUE_BRAKE);

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
	case 50:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, HV_FLASH_REQUEST_MAINBOARD);
		snprintf(v[1], string_size, HV_FLASH_REQUEST_CELLBOARD_ID);

		return 0;
	case 51:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, HV_FLASH_RESPONSE_READY);

		return 0;
	case 1112:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, HV_TS_VOLTAGE_TS);
		snprintf(v[1], string_size, HV_TS_VOLTAGE_PACK);
		snprintf(v[2], string_size, HV_TS_VOLTAGE_CELLS_SUM);

		return 0;
	case 1832:
		if(5 > fields_size) return 1;
		snprintf(v[0], string_size, HV_CELLS_TEMPERATURE_CELLBOARD_ID);
		snprintf(v[1], string_size, HV_CELLS_TEMPERATURE_TEMPERATURE_ID_0);
		snprintf(v[2], string_size, HV_CELLS_TEMPERATURE_TEMPERATURE_ID_1);
		snprintf(v[3], string_size, HV_CELLS_TEMPERATURE_TEMPERATURE_0);
		snprintf(v[4], string_size, HV_CELLS_TEMPERATURE_TEMPERATURE_1);

		return 0;
	case 1840:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, HV_DISCHARGE_TEMPERATURE_CELLBOARD_ID);
		snprintf(v[1], string_size, HV_DISCHARGE_TEMPERATURE_TEMPERATURE_0);
		snprintf(v[2], string_size, HV_DISCHARGE_TEMPERATURE_TEMPERATURE_1);
		snprintf(v[3], string_size, HV_DISCHARGE_TEMPERATURE_TEMPERATURE_2);
		snprintf(v[4], string_size, HV_DISCHARGE_TEMPERATURE_TEMPERATURE_3);
		snprintf(v[5], string_size, HV_DISCHARGE_TEMPERATURE_TEMPERATURE_4);

		return 0;
	case 1848:
		if(7 > fields_size) return 1;
		snprintf(v[0], string_size, HV_COOLING_TEMPERATURE_INLET);
		snprintf(v[1], string_size, HV_COOLING_TEMPERATURE_OUTLET_0);
		snprintf(v[2], string_size, HV_COOLING_TEMPERATURE_OUTLET_1);
		snprintf(v[3], string_size, HV_COOLING_TEMPERATURE_OUTLET_2);
		snprintf(v[4], string_size, HV_COOLING_TEMPERATURE_OUTLET_3);
		snprintf(v[5], string_size, HV_COOLING_TEMPERATURE_OUTLET_4);
		snprintf(v[6], string_size, HV_COOLING_TEMPERATURE_OUTLET_5);

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
	case 696:
		if(17 > fields_size) return 1;
		snprintf(v[0], string_size, HV_FEEDBACK_DIGITAL_DIGITAL_AIRN_OPEN_COM);
		snprintf(v[1], string_size, HV_FEEDBACK_DIGITAL_DIGITAL_AIRP_OPEN_COM);
		snprintf(v[2], string_size, HV_FEEDBACK_DIGITAL_DIGITAL_SD_IMD_FB);
		snprintf(v[3], string_size, HV_FEEDBACK_DIGITAL_DIGITAL_SD_BMS_FB);
		snprintf(v[4], string_size, HV_FEEDBACK_DIGITAL_DIGITAL_PRECHARGE_OPEN_COM);
		snprintf(v[5], string_size, HV_FEEDBACK_DIGITAL_DIGITAL_PRECHARGE_OPEN_MEC);
		snprintf(v[6], string_size, HV_FEEDBACK_DIGITAL_DIGITAL_TS_LESS_THAN_60V);
		snprintf(v[7], string_size, HV_FEEDBACK_DIGITAL_DIGITAL_PLAUSIBLE_STATE_PERSISTED);
		snprintf(v[8], string_size, HV_FEEDBACK_DIGITAL_DIGITAL_PLAUSIBLE_STATE);
		snprintf(v[9], string_size, HV_FEEDBACK_DIGITAL_DIGITAL_NOT_BMS_FAULT_COCKPIT_LED);
		snprintf(v[10], string_size, HV_FEEDBACK_DIGITAL_DIGITAL_NOT_IMD_FAULT_COCKPIT_LED);
		snprintf(v[11], string_size, HV_FEEDBACK_DIGITAL_DIGITAL_INDICATOR_CONNECTED);
		snprintf(v[12], string_size, HV_FEEDBACK_DIGITAL_DIGITAL_NOT_LATCH_RESET);
		snprintf(v[13], string_size, HV_FEEDBACK_DIGITAL_DIGITAL_PLAUSIBLE_STATE_LATCHED);
		snprintf(v[14], string_size, HV_FEEDBACK_DIGITAL_DIGITAL_NOT_BMS_FAULT_LATCHED);
		snprintf(v[15], string_size, HV_FEEDBACK_DIGITAL_DIGITAL_NOT_IMD_FAULT_LATCHED);
		snprintf(v[16], string_size, HV_FEEDBACK_DIGITAL_DIGITAL_NOT_EXT_FAULT_LATCHED);

		return 0;
	case 712:
		if(7 > fields_size) return 1;
		snprintf(v[0], string_size, HV_FEEDBACK_ANALOG_ANALOG_AIRN_OPEN_MEC);
		snprintf(v[1], string_size, HV_FEEDBACK_ANALOG_ANALOG_AIRP_OPEN_MEC);
		snprintf(v[2], string_size, HV_FEEDBACK_ANALOG_ANALOG_IMD_OK);
		snprintf(v[3], string_size, HV_FEEDBACK_ANALOG_ANALOG_PLAUSIBLE_STATE_RC);
		snprintf(v[4], string_size, HV_FEEDBACK_ANALOG_ANALOG_TSAL_GREEN);
		snprintf(v[5], string_size, HV_FEEDBACK_ANALOG_ANALOG_PROBING_3V3);
		snprintf(v[6], string_size, HV_FEEDBACK_ANALOG_ANALOG_V5_MCU);

		return 0;
	case 720:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, HV_FEEDBACK_ANALOG_SD_SD_OUT);
		snprintf(v[1], string_size, HV_FEEDBACK_ANALOG_SD_SD_IN);
		snprintf(v[2], string_size, HV_FEEDBACK_ANALOG_SD_SD_END);

		return 0;
	case 728:
		if(5 > fields_size) return 1;
		snprintf(v[0], string_size, HV_FEEDBACK_ENZOMMA_FEEDBACK);
		snprintf(v[1], string_size, HV_FEEDBACK_ENZOMMA_STATUS);
		snprintf(v[2], string_size, HV_FEEDBACK_ENZOMMA_IS_DIGITAL);
		snprintf(v[3], string_size, HV_FEEDBACK_ENZOMMA_DIGITAL);
		snprintf(v[4], string_size, HV_FEEDBACK_ENZOMMA_ANALOG);

		return 0;
	case 736:
		if(5 > fields_size) return 1;
		snprintf(v[0], string_size, HV_ERROR_GROUP);
		snprintf(v[1], string_size, HV_ERROR_INSTANCE);
		snprintf(v[2], string_size, HV_ERROR_CELLBOARD_ID);
		snprintf(v[3], string_size, HV_ERROR_CELLBOARD_GROUP);
		snprintf(v[4], string_size, HV_ERROR_CELLBOARD_INSTANCE);

		return 0;

    }
    return 0;
}
int primary_enum_fields(int enum_id, char **v, size_t fields_size, size_t string_size)
{
    switch(enum_id)
    {
	case 0:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ivt_msg_result_wh_ivt_id_result_wh_Vt_Result_Wh");

		return 0;
	case 1:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ivt_msg_result_as_ivt_id_result_as_Vt_Result_As");

		return 0;
	case 2:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ivt_msg_result_w_ivt_id_result_w_Vt_Result_W");

		return 0;
	case 3:
		if(35 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ivt_msg_response_ivt_id_response_Resp_Cmd_Wrong_Command");
		snprintf(v[1], string_size, "primary_ivt_msg_response_ivt_id_response_Resp_Get_Set_ALIVE");
		snprintf(v[2], string_size, "primary_ivt_msg_response_ivt_id_response_Resp_Get_Set_ArtNr");
		snprintf(v[3], string_size, "primary_ivt_msg_response_ivt_id_response_Resp_Get_Set_Serialnumber");
		snprintf(v[4], string_size, "primary_ivt_msg_response_ivt_id_response_Resp_Get_Set_SW_VERSION");
		snprintf(v[5], string_size, "primary_ivt_msg_response_ivt_id_response_Resp_Get_Set_DEVICE_ID");
		snprintf(v[6], string_size, "primary_ivt_msg_response_ivt_id_response_Resp_Get_Set_THRESHOLD_NEG");
		snprintf(v[7], string_size, "primary_ivt_msg_response_ivt_id_response_Resp_Get_Set_THRESHOLD_POS");
		snprintf(v[8], string_size, "primary_ivt_msg_response_ivt_id_response_Resp_Get_Set_MODE");
		snprintf(v[9], string_size, "primary_ivt_msg_response_ivt_id_response_Resp_Get_Set_OC_TEST_TIME");
		snprintf(v[10], string_size, "primary_ivt_msg_response_ivt_id_response_Resp_Get_Set_STORE");
		snprintf(v[11], string_size, "primary_ivt_msg_response_ivt_id_response_Resp_Get_Set_TRIGGER");
		snprintf(v[12], string_size, "primary_ivt_msg_response_ivt_id_response_Resp_Get_Set_Reset_Error_Logdata");
		snprintf(v[13], string_size, "primary_ivt_msg_response_ivt_id_response_Resp_Config_Result_Wh");
		snprintf(v[14], string_size, "primary_ivt_msg_response_ivt_id_response_Resp_Config_Result_As");
		snprintf(v[15], string_size, "primary_ivt_msg_response_ivt_id_response_Resp_Config_Result_W");
		snprintf(v[16], string_size, "primary_ivt_msg_response_ivt_id_response_Resp_Config_Result_T");
		snprintf(v[17], string_size, "primary_ivt_msg_response_ivt_id_response_Resp_Config_Result_U3");
		snprintf(v[18], string_size, "primary_ivt_msg_response_ivt_id_response_Resp_Config_Result_U2");
		snprintf(v[19], string_size, "primary_ivt_msg_response_ivt_id_response_Resp_Config_Result_U1");
		snprintf(v[20], string_size, "primary_ivt_msg_response_ivt_id_response_Resp_Config_Result_I");
		snprintf(v[21], string_size, "primary_ivt_msg_response_ivt_id_response_Resp_CAN_ID_Response");
		snprintf(v[22], string_size, "primary_ivt_msg_response_ivt_id_response_Resp_CAN_ID_Command");
		snprintf(v[23], string_size, "primary_ivt_msg_response_ivt_id_response_Resp_CAN_ID_Res_Wh");
		snprintf(v[24], string_size, "primary_ivt_msg_response_ivt_id_response_Resp_CAN_ID_Res_As");
		snprintf(v[25], string_size, "primary_ivt_msg_response_ivt_id_response_Resp_CAN_ID_Res_W");
		snprintf(v[26], string_size, "primary_ivt_msg_response_ivt_id_response_Resp_CAN_ID_Res_I");
		snprintf(v[27], string_size, "primary_ivt_msg_response_ivt_id_response_Resp_CAN_ID_Res_T");
		snprintf(v[28], string_size, "primary_ivt_msg_response_ivt_id_response_Resp_CAN_ID_Res_U3");
		snprintf(v[29], string_size, "primary_ivt_msg_response_ivt_id_response_Resp_CAN_ID_Res_U2");
		snprintf(v[30], string_size, "primary_ivt_msg_response_ivt_id_response_Resp_CAN_ID_Res_U1");
		snprintf(v[31], string_size, "primary_ivt_msg_response_ivt_id_response_Resp_Error_Log_Logdata_Since_Res");
		snprintf(v[32], string_size, "primary_ivt_msg_response_ivt_id_response_Resp_Error_Log_Overall_Logdata");
		snprintf(v[33], string_size, "primary_ivt_msg_response_ivt_id_response_Resp_Error_Log_System_Error");
		snprintf(v[34], string_size, "primary_ivt_msg_response_ivt_id_response_Resp_Error_Log_Measurement_Error");

		return 0;
	case 4:
		if(16 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ivt_msg_response__80_resp_measerror_item_Resp_error_calibration_data");
		snprintf(v[1], string_size, "primary_ivt_msg_response__80_resp_measerror_item_Resp_error_ntc_I_OpenCirc");
		snprintf(v[2], string_size, "primary_ivt_msg_response__80_resp_measerror_item_Resp_error_ntc_h_OpenCirc");
		snprintf(v[3], string_size, "primary_ivt_msg_response__80_resp_measerror_item_Resp_error_meas_U3_OpenCirc");
		snprintf(v[4], string_size, "primary_ivt_msg_response__80_resp_measerror_item_Resp_error_meas_U2_OpenCirc");
		snprintf(v[5], string_size, "primary_ivt_msg_response__80_resp_measerror_item_Resp_error_meas_U1_OpenCirc");
		snprintf(v[6], string_size, "primary_ivt_msg_response__80_resp_measerror_item_Resp_error_meas_I1_OpenCirc");
		snprintf(v[7], string_size, "primary_ivt_msg_response__80_resp_measerror_item_Resp__error_therm_EMF_correction");
		snprintf(v[8], string_size, "primary_ivt_msg_response__80_resp_measerror_item_Resp_error_cur_meas_implausible");
		snprintf(v[9], string_size, "primary_ivt_msg_response__80_resp_measerror_item_Resp_error_Vref");
		snprintf(v[10], string_size, "primary_ivt_msg_response__80_resp_measerror_item_Resp_error_Underflow_ADC_ch_2");
		snprintf(v[11], string_size, "primary_ivt_msg_response__80_resp_measerror_item_Resp_error_Overflow_ADC_ch_2");
		snprintf(v[12], string_size, "primary_ivt_msg_response__80_resp_measerror_item_Resp_error_Underflow_ADC_ch_1");
		snprintf(v[13], string_size, "primary_ivt_msg_response__80_resp_measerror_item_Reso_error_Overflow_ADC_ch_1");
		snprintf(v[14], string_size, "primary_ivt_msg_response__80_resp_measerror_item_Resp_error_ADC_interrupt");
		snprintf(v[15], string_size, "primary_ivt_msg_response__80_resp_measerror_item_Resonse_all_meas_errors");

		return 0;
	case 5:
		if(17 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ivt_msg_response__81_resp_systemerror_item_Resp_error_Reset_EMC");
		snprintf(v[1], string_size, "primary_ivt_msg_response__81_resp_systemerror_item_Resp_error_Reset_Watchdog");
		snprintf(v[2], string_size, "primary_ivt_msg_response__81_resp_systemerror_item_Resp_error_Reset_illegal_opcode");
		snprintf(v[3], string_size, "primary_ivt_msg_response__81_resp_systemerror_item_Resp_error_ADC_Clock");
		snprintf(v[4], string_size, "primary_ivt_msg_response__81_resp_systemerror_item_Resp_error_eeprom_rw");
		snprintf(v[5], string_size, "primary_ivt_msg_response__81_resp_systemerror_item_Resp_error_Overcurrent_detection");
		snprintf(v[6], string_size, "primary_ivt_msg_response__81_resp_systemerror_item_Resp_error_Configuration");
		snprintf(v[7], string_size, "primary_ivt_msg_response__81_resp_systemerror_item_Resp_error_System_Init");
		snprintf(v[8], string_size, "primary_ivt_msg_response__81_resp_systemerror_item_Resp_error_System_Clock");
		snprintf(v[9], string_size, "primary_ivt_msg_response__81_resp_systemerror_item_Resp_error_Power_failure");
		snprintf(v[10], string_size, "primary_ivt_msg_response__81_resp_systemerror_item_Resp_error_Undertemp");
		snprintf(v[11], string_size, "primary_ivt_msg_response__81_resp_systemerror_item_Resp_error_Overtemp");
		snprintf(v[12], string_size, "primary_ivt_msg_response__81_resp_systemerror_item_Resp_error_CAN_bus_transmit_Data");
		snprintf(v[13], string_size, "primary_ivt_msg_response__81_resp_systemerror_item_Resp_error_CAN_bus_receive_Data");
		snprintf(v[14], string_size, "primary_ivt_msg_response__81_resp_systemerror_item_Resp_error_Parameter_CRC");
		snprintf(v[15], string_size, "primary_ivt_msg_response__81_resp_systemerror_item_Resp_error_code_CRC");
		snprintf(v[16], string_size, "primary_ivt_msg_response__81_resp_systemerror_item_Resonse_all_SystemErrors");

		return 0;
	case 6:
		if(30 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ivt_msg_response__82_resp_alllogdata_item_Resp_temp_minimum");
		snprintf(v[1], string_size, "primary_ivt_msg_response__82_resp_alllogdata_item_Resp_temp_maxmimum");
		snprintf(v[2], string_size, "primary_ivt_msg_response__82_resp_alllogdata_item_Resp_U3_minimum");
		snprintf(v[3], string_size, "primary_ivt_msg_response__82_resp_alllogdata_item_Resp_U3_maximum");
		snprintf(v[4], string_size, "primary_ivt_msg_response__82_resp_alllogdata_item_Resp_U2_minimum");
		snprintf(v[5], string_size, "primary_ivt_msg_response__82_resp_alllogdata_item_Resp_U2_maxmimum");
		snprintf(v[6], string_size, "primary_ivt_msg_response__82_resp_alllogdata_item_Resp_U1_minimum");
		snprintf(v[7], string_size, "primary_ivt_msg_response__82_resp_alllogdata_item_Resp_U1_maximum");
		snprintf(v[8], string_size, "primary_ivt_msg_response__82_resp_alllogdata_item_Resp_current_minimum");
		snprintf(v[9], string_size, "primary_ivt_msg_response__82_resp_alllogdata_item_Resp_current_maximum");
		snprintf(v[10], string_size, "primary_ivt_msg_response__82_resp_alllogdata_item_Resp_oc_negative_activated");
		snprintf(v[11], string_size, "primary_ivt_msg_response__82_resp_alllogdata_item_Resp_oc_positive_activated");
		snprintf(v[12], string_size, "primary_ivt_msg_response__82_resp_alllogdata_item_Resp_run_temp_out_spec_limits");
		snprintf(v[13], string_size, "primary_ivt_msg_response__82_resp_alllogdata_item_Resp_run_temp_in_spec_limits");
		snprintf(v[14], string_size, "primary_ivt_msg_response__82_resp_alllogdata_item_Resp_run_volt_3_out_spec_limits");
		snprintf(v[15], string_size, "primary_ivt_msg_response__82_resp_alllogdata_item_Resp_run_volt_3_in_spec_limits");
		snprintf(v[16], string_size, "primary_ivt_msg_response__82_resp_alllogdata_item_Resp_run_volt_2_out_spec_limits");
		snprintf(v[17], string_size, "primary_ivt_msg_response__82_resp_alllogdata_item_Resp_run_volt_2_in_spec_limits");
		snprintf(v[18], string_size, "primary_ivt_msg_response__82_resp_alllogdata_item_Resp_run_volt_1_out_spec_limits");
		snprintf(v[19], string_size, "primary_ivt_msg_response__82_resp_alllogdata_item_Resp_run_volt_1_in_spec_limits");
		snprintf(v[20], string_size, "primary_ivt_msg_response__82_resp_alllogdata_item_Resp_run_cur_out_spec_limits");
		snprintf(v[21], string_size, "primary_ivt_msg_response__82_resp_alllogdata_item_Resp_run_cur_in_spec_limits");
		snprintf(v[22], string_size, "primary_ivt_msg_response__82_resp_alllogdata_item_Resp_run_overall");
		snprintf(v[23], string_size, "primary_ivt_msg_response__82_resp_alllogdata_item_Resp_energy_counter_discharging");
		snprintf(v[24], string_size, "primary_ivt_msg_response__82_resp_alllogdata_item_Resp_energy_counter_charging");
		snprintf(v[25], string_size, "primary_ivt_msg_response__82_resp_alllogdata_item_Resp_energy_counter_overall");
		snprintf(v[26], string_size, "primary_ivt_msg_response__82_resp_alllogdata_item_Resp_Ah_counter_discharging");
		snprintf(v[27], string_size, "primary_ivt_msg_response__82_resp_alllogdata_item_Resp_Ah_counter_charging");
		snprintf(v[28], string_size, "primary_ivt_msg_response__82_resp_alllogdata_item_Resp_Ah_counter_overall");
		snprintf(v[29], string_size, "primary_ivt_msg_response__82_resp_alllogdata_item_Response_on_Overall_Logdata");

		return 0;
	case 7:
		if(30 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ivt_msg_response__83_resp_logdata_item_Resp_temp_minimum");
		snprintf(v[1], string_size, "primary_ivt_msg_response__83_resp_logdata_item_Resp_temp_maxmimum");
		snprintf(v[2], string_size, "primary_ivt_msg_response__83_resp_logdata_item_Resp_U3_minimum");
		snprintf(v[3], string_size, "primary_ivt_msg_response__83_resp_logdata_item_Resp_U3_maximum");
		snprintf(v[4], string_size, "primary_ivt_msg_response__83_resp_logdata_item_Resp_U2_minimum");
		snprintf(v[5], string_size, "primary_ivt_msg_response__83_resp_logdata_item_Resp_U2_maxmimum");
		snprintf(v[6], string_size, "primary_ivt_msg_response__83_resp_logdata_item_Resp_U1_minimum");
		snprintf(v[7], string_size, "primary_ivt_msg_response__83_resp_logdata_item_Resp_U1_maximum");
		snprintf(v[8], string_size, "primary_ivt_msg_response__83_resp_logdata_item_Resp_current_minimum");
		snprintf(v[9], string_size, "primary_ivt_msg_response__83_resp_logdata_item_Resp_current_maximum");
		snprintf(v[10], string_size, "primary_ivt_msg_response__83_resp_logdata_item_Resp_oc_negative_activated");
		snprintf(v[11], string_size, "primary_ivt_msg_response__83_resp_logdata_item_Resp_oc_positive_activated");
		snprintf(v[12], string_size, "primary_ivt_msg_response__83_resp_logdata_item_Resp_run_temp_out_spec_limits");
		snprintf(v[13], string_size, "primary_ivt_msg_response__83_resp_logdata_item_Resp_run_temp_in_spec_limits");
		snprintf(v[14], string_size, "primary_ivt_msg_response__83_resp_logdata_item_Resp_run_volt_3_out_spec_limits");
		snprintf(v[15], string_size, "primary_ivt_msg_response__83_resp_logdata_item_Resp_run_volt_3_in_spec_limits");
		snprintf(v[16], string_size, "primary_ivt_msg_response__83_resp_logdata_item_Resp_run_volt_2_out_spec_limits");
		snprintf(v[17], string_size, "primary_ivt_msg_response__83_resp_logdata_item_Resp_run_volt_2_in_spec_limits");
		snprintf(v[18], string_size, "primary_ivt_msg_response__83_resp_logdata_item_Resp_run_volt_1_out_spec_limits");
		snprintf(v[19], string_size, "primary_ivt_msg_response__83_resp_logdata_item_Resp_run_volt_1_in_spec_limits");
		snprintf(v[20], string_size, "primary_ivt_msg_response__83_resp_logdata_item_Resp_run_cur_out_spec_limits");
		snprintf(v[21], string_size, "primary_ivt_msg_response__83_resp_logdata_item_Resp_run_cur_in_spec_limits");
		snprintf(v[22], string_size, "primary_ivt_msg_response__83_resp_logdata_item_Resp_run_overall");
		snprintf(v[23], string_size, "primary_ivt_msg_response__83_resp_logdata_item_Resp_energy_counter_discharging");
		snprintf(v[24], string_size, "primary_ivt_msg_response__83_resp_logdata_item_Resp_energy_counter_charging");
		snprintf(v[25], string_size, "primary_ivt_msg_response__83_resp_logdata_item_Resp_energy_counter_overall");
		snprintf(v[26], string_size, "primary_ivt_msg_response__83_resp_logdata_item_Resp_Ah_counter_discharging");
		snprintf(v[27], string_size, "primary_ivt_msg_response__83_resp_logdata_item_Resp_Ah_counter_charging");
		snprintf(v[28], string_size, "primary_ivt_msg_response__83_resp_logdata_item_Resp_Ah_counter_overall");
		snprintf(v[29], string_size, "primary_ivt_msg_response__83_resp_logdata_item_Response_all_Logdata_SinceReset");

		return 0;
	case 8:
		if(63 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ivt_msg_response__b0_resp_reset_item_Reset_temp_minimum");
		snprintf(v[1], string_size, "primary_ivt_msg_response__b0_resp_reset_item_Reset_temp_maximum");
		snprintf(v[2], string_size, "primary_ivt_msg_response__b0_resp_reset_item_Reset_U3_minimum");
		snprintf(v[3], string_size, "primary_ivt_msg_response__b0_resp_reset_item_Reset_U3_maximum");
		snprintf(v[4], string_size, "primary_ivt_msg_response__b0_resp_reset_item_Reset_U2_minimum");
		snprintf(v[5], string_size, "primary_ivt_msg_response__b0_resp_reset_item_Reset_U2_maximum");
		snprintf(v[6], string_size, "primary_ivt_msg_response__b0_resp_reset_item_Reset_U1_minimum");
		snprintf(v[7], string_size, "primary_ivt_msg_response__b0_resp_reset_item_Reset_U1_maximum");
		snprintf(v[8], string_size, "primary_ivt_msg_response__b0_resp_reset_item_Reset_Current_minimum");
		snprintf(v[9], string_size, "primary_ivt_msg_response__b0_resp_reset_item_Reset_Current_maximum");
		snprintf(v[10], string_size, "primary_ivt_msg_response__b0_resp_reset_item_Reset_Run_overcur_neg_activated");
		snprintf(v[11], string_size, "primary_ivt_msg_response__b0_resp_reset_item_Reset_Run_overcur_pos_activated");
		snprintf(v[12], string_size, "primary_ivt_msg_response__b0_resp_reset_item_Reset_Run_temp_out_spec_limits");
		snprintf(v[13], string_size, "primary_ivt_msg_response__b0_resp_reset_item_Reset_Run_temp_in_spec_limits");
		snprintf(v[14], string_size, "primary_ivt_msg_response__b0_resp_reset_item_Reset_Run_volt_3_out_spec_limits");
		snprintf(v[15], string_size, "primary_ivt_msg_response__b0_resp_reset_item_Reset_Run_volt_3_in_spec_limits");
		snprintf(v[16], string_size, "primary_ivt_msg_response__b0_resp_reset_item_Reset_Run_volt_2_out_spec_limits");
		snprintf(v[17], string_size, "primary_ivt_msg_response__b0_resp_reset_item_Reset_Run_volt_2_in_spec_limits");
		snprintf(v[18], string_size, "primary_ivt_msg_response__b0_resp_reset_item_Reset_Run_volt_1_out_spec_limits");
		snprintf(v[19], string_size, "primary_ivt_msg_response__b0_resp_reset_item_Reset_Run_volt_1_in_spec_limits");
		snprintf(v[20], string_size, "primary_ivt_msg_response__b0_resp_reset_item_Reset_Run_cur_out_spec_limits");
		snprintf(v[21], string_size, "primary_ivt_msg_response__b0_resp_reset_item_Reset_Run_cur_in_spec_limits");
		snprintf(v[22], string_size, "primary_ivt_msg_response__b0_resp_reset_item_Reset_Runtime_overall");
		snprintf(v[23], string_size, "primary_ivt_msg_response__b0_resp_reset_item_Reset_Energy_counter_discharging");
		snprintf(v[24], string_size, "primary_ivt_msg_response__b0_resp_reset_item_Reset_Energy_counter_charging");
		snprintf(v[25], string_size, "primary_ivt_msg_response__b0_resp_reset_item_Reset_Energy_counter_overall");
		snprintf(v[26], string_size, "primary_ivt_msg_response__b0_resp_reset_item_Reset_Ah_counter_discharging");
		snprintf(v[27], string_size, "primary_ivt_msg_response__b0_resp_reset_item_Reset_Ah_counter_charging");
		snprintf(v[28], string_size, "primary_ivt_msg_response__b0_resp_reset_item_Reset_Ah_counter_overall");
		snprintf(v[29], string_size, "primary_ivt_msg_response__b0_resp_reset_item_Reset_all_Logdata_Since_Reset");
		snprintf(v[30], string_size, "primary_ivt_msg_response__b0_resp_reset_item_Reset_Reset_EMC");
		snprintf(v[31], string_size, "primary_ivt_msg_response__b0_resp_reset_item_Reset_Reset_Watchdog");
		snprintf(v[32], string_size, "primary_ivt_msg_response__b0_resp_reset_item_Reset_illegal_opcode");
		snprintf(v[33], string_size, "primary_ivt_msg_response__b0_resp_reset_item_Reset_ADC_Clock");
		snprintf(v[34], string_size, "primary_ivt_msg_response__b0_resp_reset_item_Reset_eeprom_rw");
		snprintf(v[35], string_size, "primary_ivt_msg_response__b0_resp_reset_item_Reset_overcurrent_detection");
		snprintf(v[36], string_size, "primary_ivt_msg_response__b0_resp_reset_item_Reset_configuration");
		snprintf(v[37], string_size, "primary_ivt_msg_response__b0_resp_reset_item_Reset_system_init");
		snprintf(v[38], string_size, "primary_ivt_msg_response__b0_resp_reset_item_Reset_system_clock");
		snprintf(v[39], string_size, "primary_ivt_msg_response__b0_resp_reset_item_Reset_power_failure");
		snprintf(v[40], string_size, "primary_ivt_msg_response__b0_resp_reset_item_Reset_undertemp");
		snprintf(v[41], string_size, "primary_ivt_msg_response__b0_resp_reset_item_Reset_overtemp");
		snprintf(v[42], string_size, "primary_ivt_msg_response__b0_resp_reset_item_Reset_CAN_bus_transmit_Data");
		snprintf(v[43], string_size, "primary_ivt_msg_response__b0_resp_reset_item_Reset_CAN_bus_receive_Data");
		snprintf(v[44], string_size, "primary_ivt_msg_response__b0_resp_reset_item_Reset_Parameter_CRC");
		snprintf(v[45], string_size, "primary_ivt_msg_response__b0_resp_reset_item_Reset_Code_CRC");
		snprintf(v[46], string_size, "primary_ivt_msg_response__b0_resp_reset_item_Reset_all_System_errors");
		snprintf(v[47], string_size, "primary_ivt_msg_response__b0_resp_reset_item_Reset_calibration_data_");
		snprintf(v[48], string_size, "primary_ivt_msg_response__b0_resp_reset_item_Reset_ntc_I_OpenCircuit");
		snprintf(v[49], string_size, "primary_ivt_msg_response__b0_resp_reset_item_Reset_ntc_h_OpenCircuit");
		snprintf(v[50], string_size, "primary_ivt_msg_response__b0_resp_reset_item_Reset_voltage_measU3_OpenCircuit");
		snprintf(v[51], string_size, "primary_ivt_msg_response__b0_resp_reset_item_Reset_voltage_measU2_OpenCircuit");
		snprintf(v[52], string_size, "primary_ivt_msg_response__b0_resp_reset_item_Reset_voltage_measU1_OpenCircuit");
		snprintf(v[53], string_size, "primary_ivt_msg_response__b0_resp_reset_item_Reset_current_measI1_OpenCircuit");
		snprintf(v[54], string_size, "primary_ivt_msg_response__b0_resp_reset_item_Reset_thermal_EMF_correction");
		snprintf(v[55], string_size, "primary_ivt_msg_response__b0_resp_reset_item_Reset_error_current_implausible");
		snprintf(v[56], string_size, "primary_ivt_msg_response__b0_resp_reset_item_Reset_error_Vref");
		snprintf(v[57], string_size, "primary_ivt_msg_response__b0_resp_reset_item_Reset_error_Underflow_ADC_ch2");
		snprintf(v[58], string_size, "primary_ivt_msg_response__b0_resp_reset_item_Reset_error_Overflow_ADC_ch2");
		snprintf(v[59], string_size, "primary_ivt_msg_response__b0_resp_reset_item_Reset_error_Underflow_ADC_ch1");
		snprintf(v[60], string_size, "primary_ivt_msg_response__b0_resp_reset_item_Reset_error_Overflow_ADC_ch1");
		snprintf(v[61], string_size, "primary_ivt_msg_response__b0_resp_reset_item_Reset_error_ADC_interrupt");
		snprintf(v[62], string_size, "primary_ivt_msg_response__b0_resp_reset_item_Reset_all_measurement_errors");

		return 0;
	case 9:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ivt_msg_response__b9_resp_device_type_IVT_S");
		snprintf(v[1], string_size, "primary_ivt_msg_response__b9_resp_device_type_IVT_Mod");

		return 0;
	case 10:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ivt_msg_response__a0_resp_triggermode_i_CYCLIC");
		snprintf(v[1], string_size, "primary_ivt_msg_response__a0_resp_triggermode_i_TRIGGERED");
		snprintf(v[2], string_size, "primary_ivt_msg_response__a0_resp_triggermode_i_DISABLED");

		return 0;
	case 11:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ivt_msg_response__a1_resp_triggermode_u1_CYCLIC");
		snprintf(v[1], string_size, "primary_ivt_msg_response__a1_resp_triggermode_u1_TRIGGERED");
		snprintf(v[2], string_size, "primary_ivt_msg_response__a1_resp_triggermode_u1_DISABLED");

		return 0;
	case 12:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ivt_msg_response__a2_resp_triggermode_u2_CYCLIC");
		snprintf(v[1], string_size, "primary_ivt_msg_response__a2_resp_triggermode_u2_TRIGGERED");
		snprintf(v[2], string_size, "primary_ivt_msg_response__a2_resp_triggermode_u2_DISABLED");

		return 0;
	case 13:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ivt_msg_response__a3_resp_triggermode_u3_CYCLIC");
		snprintf(v[1], string_size, "primary_ivt_msg_response__a3_resp_triggermode_u3_TRIGGERED");
		snprintf(v[2], string_size, "primary_ivt_msg_response__a3_resp_triggermode_u3_DISABLED");

		return 0;
	case 14:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ivt_msg_response__a4_resp_triggermode_t_CYCLIC");
		snprintf(v[1], string_size, "primary_ivt_msg_response__a4_resp_triggermode_t_TRIGGERED");
		snprintf(v[2], string_size, "primary_ivt_msg_response__a4_resp_triggermode_t_DISABLED");

		return 0;
	case 15:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ivt_msg_response__a5_resp_triggermode_w_CYCLIC");
		snprintf(v[1], string_size, "primary_ivt_msg_response__a5_resp_triggermode_w_TRIGGERED");
		snprintf(v[2], string_size, "primary_ivt_msg_response__a5_resp_triggermode_w_DISABLED");

		return 0;
	case 16:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ivt_msg_response__a6_resp_triggermode_as_CYCLIC");
		snprintf(v[1], string_size, "primary_ivt_msg_response__a6_resp_triggermode_as_TRIGGERED");
		snprintf(v[2], string_size, "primary_ivt_msg_response__a6_resp_triggermode_as_DISABLED");

		return 0;
	case 17:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ivt_msg_response__a7_resp_triggermode_wh_CYCLIC");
		snprintf(v[1], string_size, "primary_ivt_msg_response__a7_resp_triggermode_wh_TRIGGERED");
		snprintf(v[2], string_size, "primary_ivt_msg_response__a7_resp_triggermode_wh_DISABLED");

		return 0;
	case 18:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ivt_msg_response__b4_resp_actual_mode_RUN");
		snprintf(v[1], string_size, "primary_ivt_msg_response__b4_resp_actual_mode_STOP");

		return 0;
	case 19:
		if(5 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ivt_msg_response__b9_resp_device_current_2500_A");
		snprintf(v[1], string_size, "primary_ivt_msg_response__b9_resp_device_current_1000_A");
		snprintf(v[2], string_size, "primary_ivt_msg_response__b9_resp_device_current_500_A");
		snprintf(v[3], string_size, "primary_ivt_msg_response__b9_resp_device_current_300_A");
		snprintf(v[4], string_size, "primary_ivt_msg_response__b9_resp_device_current_100_A");

		return 0;
	case 20:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ivt_msg_response__b4_resp_startup_mode_Run");
		snprintf(v[1], string_size, "primary_ivt_msg_response__b4_resp_startup_mode_Stop");

		return 0;
	case 21:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ivt_msg_response__b9_resp_device_voltage_chan_3_Channels");
		snprintf(v[1], string_size, "primary_ivt_msg_response__b9_resp_device_voltage_chan_0_Channels");

		return 0;
	case 22:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ivt_msg_response__b9_resp_device_toi_I");

		return 0;
	case 23:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ivt_msg_response__b9_resp_device_com_CAN_2___not_terminated");
		snprintf(v[1], string_size, "primary_ivt_msg_response__b9_resp_device_com_CAN_1___terminated");
		snprintf(v[2], string_size, "primary_ivt_msg_response__b9_resp_device_com_none");

		return 0;
	case 24:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ivt_msg_response__b9_resp_device_v_supply_12__24_V_nominal_supply_voltage");

		return 0;
	case 25:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ivt_msg_result_t_ivt_id_result_t_Vt_Result_T");

		return 0;
	case 26:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ivt_msg_result_u3_ivt_id_result_u3_Vt_Result_U3");

		return 0;
	case 27:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ivt_msg_result_u2_ivt_id_result_u2_Vt_Result_U2");

		return 0;
	case 28:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ivt_msg_result_u1_ivt_id_result_u1_Vt_Result_U1");

		return 0;
	case 29:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ivt_msg_result_i_ivt_id_result_i_Vt_Result_I");

		return 0;
	case 30:
		if(58 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ivt_msg_cmd_ivt_id_cmd_Get_cmd_and_info_ArtNr");
		snprintf(v[1], string_size, "primary_ivt_msg_cmd_ivt_id_cmd_Get_cmd_and_info_SN");
		snprintf(v[2], string_size, "primary_ivt_msg_cmd_ivt_id_cmd_Get_cmd_and_info_SW_Version");
		snprintf(v[3], string_size, "primary_ivt_msg_cmd_ivt_id_cmd_Get_cmd_and_info_DEVICE_ID");
		snprintf(v[4], string_size, "primary_ivt_msg_cmd_ivt_id_cmd_Get_cmd_and_info_THRESHOLD_NEG");
		snprintf(v[5], string_size, "primary_ivt_msg_cmd_ivt_id_cmd_Get_cmd_and_info_THRESHOLD_POS");
		snprintf(v[6], string_size, "primary_ivt_msg_cmd_ivt_id_cmd_Get_cmd_and_info_MODE");
		snprintf(v[7], string_size, "primary_ivt_msg_cmd_ivt_id_cmd_Get_cmd_and_info_OC_TEST_TIME");
		snprintf(v[8], string_size, "primary_ivt_msg_cmd_ivt_id_cmd_Get_Config_Res_Wh");
		snprintf(v[9], string_size, "primary_ivt_msg_cmd_ivt_id_cmd_Get_Config_Res_As");
		snprintf(v[10], string_size, "primary_ivt_msg_cmd_ivt_id_cmd_Get_Config_Res_W");
		snprintf(v[11], string_size, "primary_ivt_msg_cmd_ivt_id_cmd_Get_Config_Res_T");
		snprintf(v[12], string_size, "primary_ivt_msg_cmd_ivt_id_cmd_Get_Config_Res_U3");
		snprintf(v[13], string_size, "primary_ivt_msg_cmd_ivt_id_cmd_Get_Config_Res_U2");
		snprintf(v[14], string_size, "primary_ivt_msg_cmd_ivt_id_cmd_Get_Config_Res_U1");
		snprintf(v[15], string_size, "primary_ivt_msg_cmd_ivt_id_cmd_Get_Config_Res_I");
		snprintf(v[16], string_size, "primary_ivt_msg_cmd_ivt_id_cmd_Get_CAN_ID_Response");
		snprintf(v[17], string_size, "primary_ivt_msg_cmd_ivt_id_cmd_Get_CAN_ID_Command");
		snprintf(v[18], string_size, "primary_ivt_msg_cmd_ivt_id_cmd_Get_CAN_ID_Res_Wh");
		snprintf(v[19], string_size, "primary_ivt_msg_cmd_ivt_id_cmd_Get_CAN_ID_Res_As");
		snprintf(v[20], string_size, "primary_ivt_msg_cmd_ivt_id_cmd_Get_CAN_ID_Res_W");
		snprintf(v[21], string_size, "primary_ivt_msg_cmd_ivt_id_cmd_Get_CAN_ID_Res_T");
		snprintf(v[22], string_size, "primary_ivt_msg_cmd_ivt_id_cmd_Get_CAN_ID_Res_U3");
		snprintf(v[23], string_size, "primary_ivt_msg_cmd_ivt_id_cmd_Get_CAN_ID_Res_U2");
		snprintf(v[24], string_size, "primary_ivt_msg_cmd_ivt_id_cmd_Get_CAN_ID_Res_U1");
		snprintf(v[25], string_size, "primary_ivt_msg_cmd_ivt_id_cmd_Get_CAN_ID_Res_I");
		snprintf(v[26], string_size, "primary_ivt_msg_cmd_ivt_id_cmd_Get_Logdata_Since_Reset");
		snprintf(v[27], string_size, "primary_ivt_msg_cmd_ivt_id_cmd_Get_Overall_Logdata");
		snprintf(v[28], string_size, "primary_ivt_msg_cmd_ivt_id_cmd_Get_System_Errors");
		snprintf(v[29], string_size, "primary_ivt_msg_cmd_ivt_id_cmd_Get_Measurement_Errors");
		snprintf(v[30], string_size, "primary_ivt_msg_cmd_ivt_id_cmd_Set_RESTART");
		snprintf(v[31], string_size, "primary_ivt_msg_cmd_ivt_id_cmd_Set_RESTART_to_default");
		snprintf(v[32], string_size, "primary_ivt_msg_cmd_ivt_id_cmd_RESTART_to_Bitrate");
		snprintf(v[33], string_size, "primary_ivt_msg_cmd_ivt_id_cmd_Set_THRESHOLD_neg");
		snprintf(v[34], string_size, "primary_ivt_msg_cmd_ivt_id_cmd_Set_THRESHOLD_pos");
		snprintf(v[35], string_size, "primary_ivt_msg_cmd_ivt_id_cmd_Set_MODE_Result_I");
		snprintf(v[36], string_size, "primary_ivt_msg_cmd_ivt_id_cmd_Set_CAN_ID_Result_I");
		snprintf(v[37], string_size, "primary_ivt_msg_cmd_ivt_id_cmd_Set_MODE");
		snprintf(v[38], string_size, "primary_ivt_msg_cmd_ivt_id_cmd_START_OC_TEST");
		snprintf(v[39], string_size, "primary_ivt_msg_cmd_ivt_id_cmd_STORE");
		snprintf(v[40], string_size, "primary_ivt_msg_cmd_ivt_id_cmd_TRIGGER");
		snprintf(v[41], string_size, "primary_ivt_msg_cmd_ivt_id_cmd_Reset_Err_Log");
		snprintf(v[42], string_size, "primary_ivt_msg_cmd_ivt_id_cmd_Set_MODE_Result_Wh");
		snprintf(v[43], string_size, "primary_ivt_msg_cmd_ivt_id_cmd_Set_MODE_Result_As");
		snprintf(v[44], string_size, "primary_ivt_msg_cmd_ivt_id_cmd_Set_MODE_Result_W");
		snprintf(v[45], string_size, "primary_ivt_msg_cmd_ivt_id_cmd_Set_CAN_ID_Result_Wh");
		snprintf(v[46], string_size, "primary_ivt_msg_cmd_ivt_id_cmd_Set_CAN_ID_Result_As");
		snprintf(v[47], string_size, "primary_ivt_msg_cmd_ivt_id_cmd_Set_CAN_ID_Result_W");
		snprintf(v[48], string_size, "primary_ivt_msg_cmd_ivt_id_cmd_Set_CAN_ID_Result_T");
		snprintf(v[49], string_size, "primary_ivt_msg_cmd_ivt_id_cmd_Set_MODE_Result_U3");
		snprintf(v[50], string_size, "primary_ivt_msg_cmd_ivt_id_cmd_Set_CAN_ID_Response");
		snprintf(v[51], string_size, "primary_ivt_msg_cmd_ivt_id_cmd_Set_CAN_ID_Cmd");
		snprintf(v[52], string_size, "primary_ivt_msg_cmd_ivt_id_cmd_Set_CAN_ID_Result_U3");
		snprintf(v[53], string_size, "primary_ivt_msg_cmd_ivt_id_cmd_Set_CAN_ID_Result_U2");
		snprintf(v[54], string_size, "primary_ivt_msg_cmd_ivt_id_cmd_Set_MODE_Result_T");
		snprintf(v[55], string_size, "primary_ivt_msg_cmd_ivt_id_cmd_Set_MODE_Result_U2");
		snprintf(v[56], string_size, "primary_ivt_msg_cmd_ivt_id_cmd_Set_MODE_Result_U1");
		snprintf(v[57], string_size, "primary_ivt_msg_cmd_ivt_id_cmd_Set_CAN_ID_Result_U1");

		return 0;
	case 31:
		if(63 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ivt_msg_cmd__30_reset_item_Reset_temp_minimum");
		snprintf(v[1], string_size, "primary_ivt_msg_cmd__30_reset_item_Reset_temp_maximum");
		snprintf(v[2], string_size, "primary_ivt_msg_cmd__30_reset_item_Reset_U3_minimum");
		snprintf(v[3], string_size, "primary_ivt_msg_cmd__30_reset_item_Reset_U3_maximum");
		snprintf(v[4], string_size, "primary_ivt_msg_cmd__30_reset_item_Reset_U2_minimum");
		snprintf(v[5], string_size, "primary_ivt_msg_cmd__30_reset_item_Reset_U2_maximum");
		snprintf(v[6], string_size, "primary_ivt_msg_cmd__30_reset_item_Reset_U1_minimum");
		snprintf(v[7], string_size, "primary_ivt_msg_cmd__30_reset_item_Reset_U1_maximum");
		snprintf(v[8], string_size, "primary_ivt_msg_cmd__30_reset_item_Reset_Current_minimum");
		snprintf(v[9], string_size, "primary_ivt_msg_cmd__30_reset_item_Reset_Current_maximum");
		snprintf(v[10], string_size, "primary_ivt_msg_cmd__30_reset_item_Reset_Run_overcur_neg_activated");
		snprintf(v[11], string_size, "primary_ivt_msg_cmd__30_reset_item_Reset_Run_overcur_pos_activated");
		snprintf(v[12], string_size, "primary_ivt_msg_cmd__30_reset_item_Reset_Run_temp_out_spec_limits");
		snprintf(v[13], string_size, "primary_ivt_msg_cmd__30_reset_item_Reset_Run_temp_in_spec_limits");
		snprintf(v[14], string_size, "primary_ivt_msg_cmd__30_reset_item_Reset_Run_volt_3_out_spec_limits");
		snprintf(v[15], string_size, "primary_ivt_msg_cmd__30_reset_item_Reset_Run_volt_3_in_spec_limits");
		snprintf(v[16], string_size, "primary_ivt_msg_cmd__30_reset_item_Reset_Run_volt_2_out_spec_limits");
		snprintf(v[17], string_size, "primary_ivt_msg_cmd__30_reset_item_Reset_Run_volt_2_in_spec_limits");
		snprintf(v[18], string_size, "primary_ivt_msg_cmd__30_reset_item_Reset_Run_volt_1_out_spec_limits");
		snprintf(v[19], string_size, "primary_ivt_msg_cmd__30_reset_item_Reset_Run_volt_1_in_spec_limits");
		snprintf(v[20], string_size, "primary_ivt_msg_cmd__30_reset_item_Reset_Run_cur_out_spec_limits");
		snprintf(v[21], string_size, "primary_ivt_msg_cmd__30_reset_item_Reset_Run_cur_in_spec_limits");
		snprintf(v[22], string_size, "primary_ivt_msg_cmd__30_reset_item_Reset_Runtime_overall");
		snprintf(v[23], string_size, "primary_ivt_msg_cmd__30_reset_item_Reset_Energy_counter_discharging");
		snprintf(v[24], string_size, "primary_ivt_msg_cmd__30_reset_item_Reset_Energy_counter_charging");
		snprintf(v[25], string_size, "primary_ivt_msg_cmd__30_reset_item_Reset_Energy_counter_overall");
		snprintf(v[26], string_size, "primary_ivt_msg_cmd__30_reset_item_Reset_Ah_counter_discharging");
		snprintf(v[27], string_size, "primary_ivt_msg_cmd__30_reset_item_Reset_Ah_counter_charging");
		snprintf(v[28], string_size, "primary_ivt_msg_cmd__30_reset_item_Reset_Ah_counter_overall");
		snprintf(v[29], string_size, "primary_ivt_msg_cmd__30_reset_item_Reset_all_Logdata_Since_Reset");
		snprintf(v[30], string_size, "primary_ivt_msg_cmd__30_reset_item_Reset_Reset_EMC");
		snprintf(v[31], string_size, "primary_ivt_msg_cmd__30_reset_item_Reset_Reset_Watchdog");
		snprintf(v[32], string_size, "primary_ivt_msg_cmd__30_reset_item_Reset_illegal_opcode");
		snprintf(v[33], string_size, "primary_ivt_msg_cmd__30_reset_item_Reset_ADC_Clock");
		snprintf(v[34], string_size, "primary_ivt_msg_cmd__30_reset_item_Reset_eeprom_rw");
		snprintf(v[35], string_size, "primary_ivt_msg_cmd__30_reset_item_Reset_overcurrent_detection");
		snprintf(v[36], string_size, "primary_ivt_msg_cmd__30_reset_item_Reset_configuration");
		snprintf(v[37], string_size, "primary_ivt_msg_cmd__30_reset_item_Reset_system_init");
		snprintf(v[38], string_size, "primary_ivt_msg_cmd__30_reset_item_Reset_system_clock");
		snprintf(v[39], string_size, "primary_ivt_msg_cmd__30_reset_item_Reset_power_failure");
		snprintf(v[40], string_size, "primary_ivt_msg_cmd__30_reset_item_Reset_undertemp");
		snprintf(v[41], string_size, "primary_ivt_msg_cmd__30_reset_item_Reset_overtemp");
		snprintf(v[42], string_size, "primary_ivt_msg_cmd__30_reset_item_Reset_CAN_bus_transmit_Data");
		snprintf(v[43], string_size, "primary_ivt_msg_cmd__30_reset_item_Reset_CAN_bus_receive_Data");
		snprintf(v[44], string_size, "primary_ivt_msg_cmd__30_reset_item_Reset_Parameter_CRC");
		snprintf(v[45], string_size, "primary_ivt_msg_cmd__30_reset_item_Reset_Code_CRC");
		snprintf(v[46], string_size, "primary_ivt_msg_cmd__30_reset_item_Reset_all_System_errors");
		snprintf(v[47], string_size, "primary_ivt_msg_cmd__30_reset_item_Reset_calibration_data_");
		snprintf(v[48], string_size, "primary_ivt_msg_cmd__30_reset_item_Reset_ntc_I_OpenCircuit");
		snprintf(v[49], string_size, "primary_ivt_msg_cmd__30_reset_item_Reset_ntc_h_OpenCircuit");
		snprintf(v[50], string_size, "primary_ivt_msg_cmd__30_reset_item_Reset_voltage_measU3_OpenCircuit");
		snprintf(v[51], string_size, "primary_ivt_msg_cmd__30_reset_item_Reset_voltage_measU2_OpenCircuit");
		snprintf(v[52], string_size, "primary_ivt_msg_cmd__30_reset_item_Reset_voltage_measU1_OpenCircuit");
		snprintf(v[53], string_size, "primary_ivt_msg_cmd__30_reset_item_Reset_current_measI1_OpenCircuit");
		snprintf(v[54], string_size, "primary_ivt_msg_cmd__30_reset_item_Reset_thermal_EMF_correction");
		snprintf(v[55], string_size, "primary_ivt_msg_cmd__30_reset_item_Reset_error_current_implausible");
		snprintf(v[56], string_size, "primary_ivt_msg_cmd__30_reset_item_Reset_error_Vref");
		snprintf(v[57], string_size, "primary_ivt_msg_cmd__30_reset_item_Reset_error_Underflow_ADC_ch2");
		snprintf(v[58], string_size, "primary_ivt_msg_cmd__30_reset_item_Reset_error_Overflow_ADC_ch2");
		snprintf(v[59], string_size, "primary_ivt_msg_cmd__30_reset_item_Reset_error_Underflow_ADC_ch1");
		snprintf(v[60], string_size, "primary_ivt_msg_cmd__30_reset_item_Reset_error_Overflow_ADC_ch1");
		snprintf(v[61], string_size, "primary_ivt_msg_cmd__30_reset_item_Reset_error_ADC_interrupt");
		snprintf(v[62], string_size, "primary_ivt_msg_cmd__30_reset_item_Reset_all_measurement_errors");

		return 0;
	case 32:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ivt_msg_cmd__3a_restart_to_bitrate_250k");
		snprintf(v[1], string_size, "primary_ivt_msg_cmd__3a_restart_to_bitrate_500k");
		snprintf(v[2], string_size, "primary_ivt_msg_cmd__3a_restart_to_bitrate_1000k");

		return 0;
	case 33:
		if(16 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ivt_msg_cmd__40_get_measerror_item_Get_error_calibration_data");
		snprintf(v[1], string_size, "primary_ivt_msg_cmd__40_get_measerror_item_Get_error_ntc_I_OpenCirc");
		snprintf(v[2], string_size, "primary_ivt_msg_cmd__40_get_measerror_item_Get_error_ntc_h_OpenCirc");
		snprintf(v[3], string_size, "primary_ivt_msg_cmd__40_get_measerror_item_Get_error_volt_meas_U3_OpenCirc");
		snprintf(v[4], string_size, "primary_ivt_msg_cmd__40_get_measerror_item_Get_error_volt_meas_U2_OpenCirc");
		snprintf(v[5], string_size, "primary_ivt_msg_cmd__40_get_measerror_item_Get_error_volt_meas_U1_OpenCirc");
		snprintf(v[6], string_size, "primary_ivt_msg_cmd__40_get_measerror_item_Get_error_cur_meas_I1_OpenCirc");
		snprintf(v[7], string_size, "primary_ivt_msg_cmd__40_get_measerror_item_Get_error_thermal_EMF_correction");
		snprintf(v[8], string_size, "primary_ivt_msg_cmd__40_get_measerror_item_Get_error_cur_meas_implausible");
		snprintf(v[9], string_size, "primary_ivt_msg_cmd__40_get_measerror_item_Get_error_Vref");
		snprintf(v[10], string_size, "primary_ivt_msg_cmd__40_get_measerror_item_Get_error_Underflow_ADC_ch_2");
		snprintf(v[11], string_size, "primary_ivt_msg_cmd__40_get_measerror_item_Get_error_Overflow_ADC_ch_2");
		snprintf(v[12], string_size, "primary_ivt_msg_cmd__40_get_measerror_item_Get_error_Underflow_ADC_ch_1");
		snprintf(v[13], string_size, "primary_ivt_msg_cmd__40_get_measerror_item_Get_error_Overflow_ADC_ch_1");
		snprintf(v[14], string_size, "primary_ivt_msg_cmd__40_get_measerror_item_Get_error_ADC_interrupt");
		snprintf(v[15], string_size, "primary_ivt_msg_cmd__40_get_measerror_item_Get_all_meas_Errors");

		return 0;
	case 34:
		if(17 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ivt_msg_cmd__41_get_systemerror_item_Get_error_reset_EMC");
		snprintf(v[1], string_size, "primary_ivt_msg_cmd__41_get_systemerror_item_Get_error_reset_Watchdog");
		snprintf(v[2], string_size, "primary_ivt_msg_cmd__41_get_systemerror_item_Get_error_reset_illegal_opcode");
		snprintf(v[3], string_size, "primary_ivt_msg_cmd__41_get_systemerror_item_Get_error_ADC_clock");
		snprintf(v[4], string_size, "primary_ivt_msg_cmd__41_get_systemerror_item_Get_error_eeprom_rw");
		snprintf(v[5], string_size, "primary_ivt_msg_cmd__41_get_systemerror_item_Get_error_overcurrent_detection");
		snprintf(v[6], string_size, "primary_ivt_msg_cmd__41_get_systemerror_item_Get_error_configuration");
		snprintf(v[7], string_size, "primary_ivt_msg_cmd__41_get_systemerror_item_Get_error_system_init");
		snprintf(v[8], string_size, "primary_ivt_msg_cmd__41_get_systemerror_item_Get_error_system_clock");
		snprintf(v[9], string_size, "primary_ivt_msg_cmd__41_get_systemerror_item_Get_error_power_failure");
		snprintf(v[10], string_size, "primary_ivt_msg_cmd__41_get_systemerror_item_Get_error_undertemp");
		snprintf(v[11], string_size, "primary_ivt_msg_cmd__41_get_systemerror_item_Get_error_overtemp");
		snprintf(v[12], string_size, "primary_ivt_msg_cmd__41_get_systemerror_item_Get_error_CAN_bus_transmit_Data");
		snprintf(v[13], string_size, "primary_ivt_msg_cmd__41_get_systemerror_item_Get_error_CAN__bus_receive_Data");
		snprintf(v[14], string_size, "primary_ivt_msg_cmd__41_get_systemerror_item_Get_error_Code_Parameter_CRC");
		snprintf(v[15], string_size, "primary_ivt_msg_cmd__41_get_systemerror_item_Get_error_Code_CRC");
		snprintf(v[16], string_size, "primary_ivt_msg_cmd__41_get_systemerror_item_Get_all_System_errors");

		return 0;
	case 35:
		if(30 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ivt_msg_cmd__42_get_alllogdata_item_Get_Temperature_minimum");
		snprintf(v[1], string_size, "primary_ivt_msg_cmd__42_get_alllogdata_item_Get_Temperature_maximum");
		snprintf(v[2], string_size, "primary_ivt_msg_cmd__42_get_alllogdata_item_Get_U3_minimum");
		snprintf(v[3], string_size, "primary_ivt_msg_cmd__42_get_alllogdata_item_Get_U3_maxmimum_");
		snprintf(v[4], string_size, "primary_ivt_msg_cmd__42_get_alllogdata_item_Get_U2_minimum");
		snprintf(v[5], string_size, "primary_ivt_msg_cmd__42_get_alllogdata_item_Get_U2_maximum");
		snprintf(v[6], string_size, "primary_ivt_msg_cmd__42_get_alllogdata_item_Get_U1_minimum");
		snprintf(v[7], string_size, "primary_ivt_msg_cmd__42_get_alllogdata_item_Get_U1_maxmimum");
		snprintf(v[8], string_size, "primary_ivt_msg_cmd__42_get_alllogdata_item_Get_current_minimum");
		snprintf(v[9], string_size, "primary_ivt_msg_cmd__42_get_alllogdata_item_Get_current_maximum");
		snprintf(v[10], string_size, "primary_ivt_msg_cmd__42_get_alllogdata_item_Get_run_overcur_neg_activated");
		snprintf(v[11], string_size, "primary_ivt_msg_cmd__42_get_alllogdata_item_Get_run_overcur_pos_activated");
		snprintf(v[12], string_size, "primary_ivt_msg_cmd__42_get_alllogdata_item_Get_run_temp_out_spec_limits");
		snprintf(v[13], string_size, "primary_ivt_msg_cmd__42_get_alllogdata_item_Get_run_temp_in_spec_limits");
		snprintf(v[14], string_size, "primary_ivt_msg_cmd__42_get_alllogdata_item_Get_run_volt3_out_spec_limits");
		snprintf(v[15], string_size, "primary_ivt_msg_cmd__42_get_alllogdata_item_Get_run_volt3_in_spec_limits");
		snprintf(v[16], string_size, "primary_ivt_msg_cmd__42_get_alllogdata_item_Get_run_volt2_out_spec_limits");
		snprintf(v[17], string_size, "primary_ivt_msg_cmd__42_get_alllogdata_item_Get_run_volt2_in_spec_limits");
		snprintf(v[18], string_size, "primary_ivt_msg_cmd__42_get_alllogdata_item_Get_run_volt1_out_spec_limits");
		snprintf(v[19], string_size, "primary_ivt_msg_cmd__42_get_alllogdata_item_Get_run_volt1_in_spec_limits");
		snprintf(v[20], string_size, "primary_ivt_msg_cmd__42_get_alllogdata_item_Get_run_cur_out_spec_limits");
		snprintf(v[21], string_size, "primary_ivt_msg_cmd__42_get_alllogdata_item_Get_Run_cur_in_spec_limits");
		snprintf(v[22], string_size, "primary_ivt_msg_cmd__42_get_alllogdata_item_Get_Runtime_overall");
		snprintf(v[23], string_size, "primary_ivt_msg_cmd__42_get_alllogdata_item_Get_Energy_counter_discharging");
		snprintf(v[24], string_size, "primary_ivt_msg_cmd__42_get_alllogdata_item_Get_Energy_counter_charging");
		snprintf(v[25], string_size, "primary_ivt_msg_cmd__42_get_alllogdata_item_Get_Energy_counter_overall");
		snprintf(v[26], string_size, "primary_ivt_msg_cmd__42_get_alllogdata_item_Get_Ah_counter_discharging");
		snprintf(v[27], string_size, "primary_ivt_msg_cmd__42_get_alllogdata_item_Get_Ah_counter_charging");
		snprintf(v[28], string_size, "primary_ivt_msg_cmd__42_get_alllogdata_item_Get_Ah_counter_overall");
		snprintf(v[29], string_size, "primary_ivt_msg_cmd__42_get_alllogdata_item_Get_Overall_Logdata");

		return 0;
	case 36:
		if(30 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ivt_msg_cmd__43_get_logdata_item_Get_Temperature_minimum");
		snprintf(v[1], string_size, "primary_ivt_msg_cmd__43_get_logdata_item_Get_Temperature_maximum");
		snprintf(v[2], string_size, "primary_ivt_msg_cmd__43_get_logdata_item_Get_U3_minimum");
		snprintf(v[3], string_size, "primary_ivt_msg_cmd__43_get_logdata_item_Get_U3_maxmimum_");
		snprintf(v[4], string_size, "primary_ivt_msg_cmd__43_get_logdata_item_Get_U2_minimum");
		snprintf(v[5], string_size, "primary_ivt_msg_cmd__43_get_logdata_item_Get_U2_maximum");
		snprintf(v[6], string_size, "primary_ivt_msg_cmd__43_get_logdata_item_Get_U1_minimum");
		snprintf(v[7], string_size, "primary_ivt_msg_cmd__43_get_logdata_item_Get_U1_maxmimum");
		snprintf(v[8], string_size, "primary_ivt_msg_cmd__43_get_logdata_item_Get_current_minimum");
		snprintf(v[9], string_size, "primary_ivt_msg_cmd__43_get_logdata_item_Get_current_maximum");
		snprintf(v[10], string_size, "primary_ivt_msg_cmd__43_get_logdata_item_Get_run_overcur_neg_activated");
		snprintf(v[11], string_size, "primary_ivt_msg_cmd__43_get_logdata_item_Get_run_overcur_pos_activated");
		snprintf(v[12], string_size, "primary_ivt_msg_cmd__43_get_logdata_item_Get_run_temp_out_spec_limits");
		snprintf(v[13], string_size, "primary_ivt_msg_cmd__43_get_logdata_item_Get_run_temp_in_spec_limits");
		snprintf(v[14], string_size, "primary_ivt_msg_cmd__43_get_logdata_item_Get_run_volt3_out_spec_limits");
		snprintf(v[15], string_size, "primary_ivt_msg_cmd__43_get_logdata_item_Get_run_volt3_in_spec_limits");
		snprintf(v[16], string_size, "primary_ivt_msg_cmd__43_get_logdata_item_Get_run_volt2_out_spec_limits");
		snprintf(v[17], string_size, "primary_ivt_msg_cmd__43_get_logdata_item_Get_run_volt2_in_spec_limits");
		snprintf(v[18], string_size, "primary_ivt_msg_cmd__43_get_logdata_item_Get_run_volt1_out_spec_limits");
		snprintf(v[19], string_size, "primary_ivt_msg_cmd__43_get_logdata_item_Get_run_volt1_in_spec_limits");
		snprintf(v[20], string_size, "primary_ivt_msg_cmd__43_get_logdata_item_Get_run_cur_out_spec_limits");
		snprintf(v[21], string_size, "primary_ivt_msg_cmd__43_get_logdata_item_Get_Run_cur_in_spec_limits");
		snprintf(v[22], string_size, "primary_ivt_msg_cmd__43_get_logdata_item_Get_Runtime_overall");
		snprintf(v[23], string_size, "primary_ivt_msg_cmd__43_get_logdata_item_Get_Energy_counter_discharging");
		snprintf(v[24], string_size, "primary_ivt_msg_cmd__43_get_logdata_item_Get_Energy_counter_charging");
		snprintf(v[25], string_size, "primary_ivt_msg_cmd__43_get_logdata_item_Get_Energy_counter_overall");
		snprintf(v[26], string_size, "primary_ivt_msg_cmd__43_get_logdata_item_Get_Ah_counter_discharging");
		snprintf(v[27], string_size, "primary_ivt_msg_cmd__43_get_logdata_item_Get_Ah_counter_charging");
		snprintf(v[28], string_size, "primary_ivt_msg_cmd__43_get_logdata_item_Get_Ah_counter_overall");
		snprintf(v[29], string_size, "primary_ivt_msg_cmd__43_get_logdata_item_Get_Overall_Logdata");

		return 0;
	case 37:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ivt_msg_cmd__20_conf_triggermode_i_CYCLIC");
		snprintf(v[1], string_size, "primary_ivt_msg_cmd__20_conf_triggermode_i_TRIGGERED");
		snprintf(v[2], string_size, "primary_ivt_msg_cmd__20_conf_triggermode_i_DISABLED");

		return 0;
	case 38:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ivt_msg_cmd__21_conf_triggermode_u1_CYCLIC");
		snprintf(v[1], string_size, "primary_ivt_msg_cmd__21_conf_triggermode_u1_TRIGGERED");
		snprintf(v[2], string_size, "primary_ivt_msg_cmd__21_conf_triggermode_u1_DISABLED");

		return 0;
	case 39:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ivt_msg_cmd__22_conf_triggermode_u2_CYCLIC");
		snprintf(v[1], string_size, "primary_ivt_msg_cmd__22_conf_triggermode_u2_TRIGGERED");
		snprintf(v[2], string_size, "primary_ivt_msg_cmd__22_conf_triggermode_u2_DISABLED");

		return 0;
	case 40:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ivt_msg_cmd__23_conf_triggermode_u3_CYCLIC");
		snprintf(v[1], string_size, "primary_ivt_msg_cmd__23_conf_triggermode_u3_TRIGGERED");
		snprintf(v[2], string_size, "primary_ivt_msg_cmd__23_conf_triggermode_u3_DISABLED");

		return 0;
	case 41:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ivt_msg_cmd__24_conf_triggermode_t_CYCLIC");
		snprintf(v[1], string_size, "primary_ivt_msg_cmd__24_conf_triggermode_t_TRIGGERED");
		snprintf(v[2], string_size, "primary_ivt_msg_cmd__24_conf_triggermode_t_DISABLED");

		return 0;
	case 42:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ivt_msg_cmd__25_conf_triggermode_w_CYCLIC");
		snprintf(v[1], string_size, "primary_ivt_msg_cmd__25_conf_triggermode_w_TRIGGERED");
		snprintf(v[2], string_size, "primary_ivt_msg_cmd__25_conf_triggermode_w_DISABLED");

		return 0;
	case 43:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ivt_msg_cmd__26_conf_triggermode_as_CYCLIC");
		snprintf(v[1], string_size, "primary_ivt_msg_cmd__26_conf_triggermode_as_TRIGGERED");
		snprintf(v[2], string_size, "primary_ivt_msg_cmd__26_conf_triggermode_as_DISABLED");

		return 0;
	case 44:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ivt_msg_cmd__27_conf_triggermode_wh_CYCLIC");
		snprintf(v[1], string_size, "primary_ivt_msg_cmd__27_conf_triggermode_wh_TRIGGERED");
		snprintf(v[2], string_size, "primary_ivt_msg_cmd__27_conf_triggermode_wh_DISABLED");

		return 0;
	case 45:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ivt_msg_cmd__34_actual_mode_START");
		snprintf(v[1], string_size, "primary_ivt_msg_cmd__34_actual_mode_STOP");

		return 0;
	case 46:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ivt_msg_cmd__34_startup_mode_START");
		snprintf(v[1], string_size, "primary_ivt_msg_cmd__34_startup_mode_STOP");

		return 0;
	case 47:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_flash_forward_off");
		snprintf(v[1], string_size, "primary_hv_flash_forward_on");

		return 0;
	case 48:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_flash_cellboard_id_cellboard_0");
		snprintf(v[1], string_size, "primary_hv_flash_cellboard_id_cellboard_1");
		snprintf(v[2], string_size, "primary_hv_flash_cellboard_id_cellboard_2");
		snprintf(v[3], string_size, "primary_hv_flash_cellboard_id_cellboard_3");
		snprintf(v[4], string_size, "primary_hv_flash_cellboard_id_cellboard_4");
		snprintf(v[5], string_size, "primary_hv_flash_cellboard_id_cellboard_5");

		return 0;
	case 49:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_cellboard_version_cellboard_id_cellboard_0");
		snprintf(v[1], string_size, "primary_hv_cellboard_version_cellboard_id_cellboard_1");
		snprintf(v[2], string_size, "primary_hv_cellboard_version_cellboard_id_cellboard_2");
		snprintf(v[3], string_size, "primary_hv_cellboard_version_cellboard_id_cellboard_3");
		snprintf(v[4], string_size, "primary_hv_cellboard_version_cellboard_id_cellboard_4");
		snprintf(v[5], string_size, "primary_hv_cellboard_version_cellboard_id_cellboard_5");

		return 0;
	case 50:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_fans_status_fans_override_off");
		snprintf(v[1], string_size, "primary_hv_fans_status_fans_override_on");

		return 0;
	case 51:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_set_fans_status_fans_override_off");
		snprintf(v[1], string_size, "primary_hv_set_fans_status_fans_override_on");

		return 0;
	case 52:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_airn_open_com_low");
		snprintf(v[1], string_size, "primary_hv_feedback_status_airn_open_com_error");
		snprintf(v[2], string_size, "primary_hv_feedback_status_airn_open_com_high");

		return 0;
	case 53:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_precharge_open_com_low");
		snprintf(v[1], string_size, "primary_hv_feedback_status_precharge_open_com_error");
		snprintf(v[2], string_size, "primary_hv_feedback_status_precharge_open_com_high");

		return 0;
	case 54:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_airp_open_com_low");
		snprintf(v[1], string_size, "primary_hv_feedback_status_airp_open_com_error");
		snprintf(v[2], string_size, "primary_hv_feedback_status_airp_open_com_high");

		return 0;
	case 55:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_airn_open_mec_low");
		snprintf(v[1], string_size, "primary_hv_feedback_status_airn_open_mec_error");
		snprintf(v[2], string_size, "primary_hv_feedback_status_airn_open_mec_high");

		return 0;
	case 56:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_precharge_open_mec_low");
		snprintf(v[1], string_size, "primary_hv_feedback_status_precharge_open_mec_error");
		snprintf(v[2], string_size, "primary_hv_feedback_status_precharge_open_mec_high");

		return 0;
	case 57:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_airp_open_mec_low");
		snprintf(v[1], string_size, "primary_hv_feedback_status_airp_open_mec_error");
		snprintf(v[2], string_size, "primary_hv_feedback_status_airp_open_mec_high");

		return 0;
	case 58:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_sd_imd_fb_low");
		snprintf(v[1], string_size, "primary_hv_feedback_status_sd_imd_fb_error");
		snprintf(v[2], string_size, "primary_hv_feedback_status_sd_imd_fb_high");

		return 0;
	case 59:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_sd_bms_fb_low");
		snprintf(v[1], string_size, "primary_hv_feedback_status_sd_bms_fb_error");
		snprintf(v[2], string_size, "primary_hv_feedback_status_sd_bms_fb_high");

		return 0;
	case 60:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_ts_less_than_60v_low");
		snprintf(v[1], string_size, "primary_hv_feedback_status_ts_less_than_60v_error");
		snprintf(v[2], string_size, "primary_hv_feedback_status_ts_less_than_60v_high");

		return 0;
	case 61:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_plausible_state_persisted_low");
		snprintf(v[1], string_size, "primary_hv_feedback_status_plausible_state_persisted_error");
		snprintf(v[2], string_size, "primary_hv_feedback_status_plausible_state_persisted_high");

		return 0;
	case 62:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_plausible_state_low");
		snprintf(v[1], string_size, "primary_hv_feedback_status_plausible_state_error");
		snprintf(v[2], string_size, "primary_hv_feedback_status_plausible_state_high");

		return 0;
	case 63:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_not_bms_fault_cockpit_led_low");
		snprintf(v[1], string_size, "primary_hv_feedback_status_not_bms_fault_cockpit_led_error");
		snprintf(v[2], string_size, "primary_hv_feedback_status_not_bms_fault_cockpit_led_high");

		return 0;
	case 64:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_not_imd_fault_cockpit_led_low");
		snprintf(v[1], string_size, "primary_hv_feedback_status_not_imd_fault_cockpit_led_error");
		snprintf(v[2], string_size, "primary_hv_feedback_status_not_imd_fault_cockpit_led_high");

		return 0;
	case 65:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_indicator_connected_low");
		snprintf(v[1], string_size, "primary_hv_feedback_status_indicator_connected_error");
		snprintf(v[2], string_size, "primary_hv_feedback_status_indicator_connected_high");

		return 0;
	case 66:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_not_latch_reset_low");
		snprintf(v[1], string_size, "primary_hv_feedback_status_not_latch_reset_error");
		snprintf(v[2], string_size, "primary_hv_feedback_status_not_latch_reset_high");

		return 0;
	case 67:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_plausible_state_latched_low");
		snprintf(v[1], string_size, "primary_hv_feedback_status_plausible_state_latched_error");
		snprintf(v[2], string_size, "primary_hv_feedback_status_plausible_state_latched_high");

		return 0;
	case 68:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_not_bms_fault_latched_low");
		snprintf(v[1], string_size, "primary_hv_feedback_status_not_bms_fault_latched_error");
		snprintf(v[2], string_size, "primary_hv_feedback_status_not_bms_fault_latched_high");

		return 0;
	case 69:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_not_imd_fault_latched_low");
		snprintf(v[1], string_size, "primary_hv_feedback_status_not_imd_fault_latched_error");
		snprintf(v[2], string_size, "primary_hv_feedback_status_not_imd_fault_latched_high");

		return 0;
	case 70:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_not_ext_fault_latched_low");
		snprintf(v[1], string_size, "primary_hv_feedback_status_not_ext_fault_latched_error");
		snprintf(v[2], string_size, "primary_hv_feedback_status_not_ext_fault_latched_high");

		return 0;
	case 71:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_imd_ok_low");
		snprintf(v[1], string_size, "primary_hv_feedback_status_imd_ok_error");
		snprintf(v[2], string_size, "primary_hv_feedback_status_imd_ok_high");

		return 0;
	case 72:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_plausible_state_rc_low");
		snprintf(v[1], string_size, "primary_hv_feedback_status_plausible_state_rc_error");
		snprintf(v[2], string_size, "primary_hv_feedback_status_plausible_state_rc_high");

		return 0;
	case 73:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_tsal_green_low");
		snprintf(v[1], string_size, "primary_hv_feedback_status_tsal_green_error");
		snprintf(v[2], string_size, "primary_hv_feedback_status_tsal_green_high");

		return 0;
	case 74:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_probing_3v3_low");
		snprintf(v[1], string_size, "primary_hv_feedback_status_probing_3v3_error");
		snprintf(v[2], string_size, "primary_hv_feedback_status_probing_3v3_high");

		return 0;
	case 75:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_sd_out_low");
		snprintf(v[1], string_size, "primary_hv_feedback_status_sd_out_error");
		snprintf(v[2], string_size, "primary_hv_feedback_status_sd_out_high");

		return 0;
	case 76:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_sd_in_low");
		snprintf(v[1], string_size, "primary_hv_feedback_status_sd_in_error");
		snprintf(v[2], string_size, "primary_hv_feedback_status_sd_in_high");

		return 0;
	case 77:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_sd_end_low");
		snprintf(v[1], string_size, "primary_hv_feedback_status_sd_end_error");
		snprintf(v[2], string_size, "primary_hv_feedback_status_sd_end_high");

		return 0;
	case 78:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_v5_mcu_low");
		snprintf(v[1], string_size, "primary_hv_feedback_status_v5_mcu_error");
		snprintf(v[2], string_size, "primary_hv_feedback_status_v5_mcu_high");

		return 0;
	case 79:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_feedback_tsal_green_fault_latched_low");
		snprintf(v[1], string_size, "primary_hv_feedback_status_feedback_tsal_green_fault_latched_error");
		snprintf(v[2], string_size, "primary_hv_feedback_status_feedback_tsal_green_fault_latched_high");

		return 0;
	case 80:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_feedback_ext_latched_low");
		snprintf(v[1], string_size, "primary_hv_feedback_status_feedback_ext_latched_error");
		snprintf(v[2], string_size, "primary_hv_feedback_status_feedback_ext_latched_high");

		return 0;
	case 81:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_feedback_precharge_status_low");
		snprintf(v[1], string_size, "primary_hv_feedback_status_feedback_precharge_status_error");
		snprintf(v[2], string_size, "primary_hv_feedback_status_feedback_precharge_status_high");

		return 0;
	case 82:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_feedback_tsp_over_60v_status_low");
		snprintf(v[1], string_size, "primary_hv_feedback_status_feedback_tsp_over_60v_status_error");
		snprintf(v[2], string_size, "primary_hv_feedback_status_feedback_tsp_over_60v_status_high");

		return 0;
	case 83:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_feedback_check_mux_low");
		snprintf(v[1], string_size, "primary_hv_feedback_status_feedback_check_mux_error");
		snprintf(v[2], string_size, "primary_hv_feedback_status_feedback_check_mux_high");

		return 0;
	case 84:
		if(7 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_imd_status_status_unknown");
		snprintf(v[1], string_size, "primary_hv_imd_status_status_short_circuit");
		snprintf(v[2], string_size, "primary_hv_imd_status_status_normal");
		snprintf(v[3], string_size, "primary_hv_imd_status_status_under_voltage");
		snprintf(v[4], string_size, "primary_hv_imd_status_status_start_measure");
		snprintf(v[5], string_size, "primary_hv_imd_status_status_device_error");
		snprintf(v[6], string_size, "primary_hv_imd_status_status_earth_fault");

		return 0;
	case 85:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_imd_status_feedback_not_imd_fault_cockpit_led_low");
		snprintf(v[1], string_size, "primary_hv_imd_status_feedback_not_imd_fault_cockpit_led_error");
		snprintf(v[2], string_size, "primary_hv_imd_status_feedback_not_imd_fault_cockpit_led_high");

		return 0;
	case 86:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_imd_status_feedback_not_imd_fault_latched_low");
		snprintf(v[1], string_size, "primary_hv_imd_status_feedback_not_imd_fault_latched_error");
		snprintf(v[2], string_size, "primary_hv_imd_status_feedback_not_imd_fault_latched_high");

		return 0;
	case 87:
		if(9 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_status_status_init");
		snprintf(v[1], string_size, "primary_hv_status_status_idle");
		snprintf(v[2], string_size, "primary_hv_status_status_fatal");
		snprintf(v[3], string_size, "primary_hv_status_status_flash");
		snprintf(v[4], string_size, "primary_hv_status_status_balancing");
		snprintf(v[5], string_size, "primary_hv_status_status_airn_check");
		snprintf(v[6], string_size, "primary_hv_status_status_precharge_check");
		snprintf(v[7], string_size, "primary_hv_status_status_airp_check");
		snprintf(v[8], string_size, "primary_hv_status_status_ts_on");

		return 0;
	case 88:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_status_cellboard_0_init");
		snprintf(v[1], string_size, "primary_hv_status_cellboard_0_idle");
		snprintf(v[2], string_size, "primary_hv_status_cellboard_0_fatal");
		snprintf(v[3], string_size, "primary_hv_status_cellboard_0_flash");
		snprintf(v[4], string_size, "primary_hv_status_cellboard_0_discharge");
		snprintf(v[5], string_size, "primary_hv_status_cellboard_0_cooldown");

		return 0;
	case 89:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_status_cellboard_1_init");
		snprintf(v[1], string_size, "primary_hv_status_cellboard_1_idle");
		snprintf(v[2], string_size, "primary_hv_status_cellboard_1_fatal");
		snprintf(v[3], string_size, "primary_hv_status_cellboard_1_flash");
		snprintf(v[4], string_size, "primary_hv_status_cellboard_1_discharge");
		snprintf(v[5], string_size, "primary_hv_status_cellboard_1_cooldown");

		return 0;
	case 90:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_status_cellboard_2_init");
		snprintf(v[1], string_size, "primary_hv_status_cellboard_2_idle");
		snprintf(v[2], string_size, "primary_hv_status_cellboard_2_fatal");
		snprintf(v[3], string_size, "primary_hv_status_cellboard_2_flash");
		snprintf(v[4], string_size, "primary_hv_status_cellboard_2_discharge");
		snprintf(v[5], string_size, "primary_hv_status_cellboard_2_cooldown");

		return 0;
	case 91:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_status_cellboard_3_init");
		snprintf(v[1], string_size, "primary_hv_status_cellboard_3_idle");
		snprintf(v[2], string_size, "primary_hv_status_cellboard_3_fatal");
		snprintf(v[3], string_size, "primary_hv_status_cellboard_3_flash");
		snprintf(v[4], string_size, "primary_hv_status_cellboard_3_discharge");
		snprintf(v[5], string_size, "primary_hv_status_cellboard_3_cooldown");

		return 0;
	case 92:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_status_cellboard_4_init");
		snprintf(v[1], string_size, "primary_hv_status_cellboard_4_idle");
		snprintf(v[2], string_size, "primary_hv_status_cellboard_4_fatal");
		snprintf(v[3], string_size, "primary_hv_status_cellboard_4_flash");
		snprintf(v[4], string_size, "primary_hv_status_cellboard_4_discharge");
		snprintf(v[5], string_size, "primary_hv_status_cellboard_4_cooldown");

		return 0;
	case 93:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_status_cellboard_5_init");
		snprintf(v[1], string_size, "primary_hv_status_cellboard_5_idle");
		snprintf(v[2], string_size, "primary_hv_status_cellboard_5_fatal");
		snprintf(v[3], string_size, "primary_hv_status_cellboard_5_flash");
		snprintf(v[4], string_size, "primary_hv_status_cellboard_5_discharge");
		snprintf(v[5], string_size, "primary_hv_status_cellboard_5_cooldown");

		return 0;
	case 94:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_set_status_ecu_hv_status_set_off");
		snprintf(v[1], string_size, "primary_hv_set_status_ecu_hv_status_set_on");

		return 0;
	case 95:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_set_status_handcart_hv_status_set_off");
		snprintf(v[1], string_size, "primary_hv_set_status_handcart_hv_status_set_on");

		return 0;
	case 96:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_balancing_status_cellboard_id_cellboard_0");
		snprintf(v[1], string_size, "primary_hv_balancing_status_cellboard_id_cellboard_1");
		snprintf(v[2], string_size, "primary_hv_balancing_status_cellboard_id_cellboard_2");
		snprintf(v[3], string_size, "primary_hv_balancing_status_cellboard_id_cellboard_3");
		snprintf(v[4], string_size, "primary_hv_balancing_status_cellboard_id_cellboard_4");
		snprintf(v[5], string_size, "primary_hv_balancing_status_cellboard_id_cellboard_5");

		return 0;
	case 97:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_balancing_status_balancing_status_off");
		snprintf(v[1], string_size, "primary_hv_balancing_status_balancing_status_on");

		return 0;
	case 98:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_balancing_status_status_stopped");
		snprintf(v[1], string_size, "primary_hv_balancing_status_status_paused");
		snprintf(v[2], string_size, "primary_hv_balancing_status_status_running");

		return 0;
	case 99:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_set_balancing_status_steering_wheel_set_balancing_status_off");
		snprintf(v[1], string_size, "primary_hv_set_balancing_status_steering_wheel_set_balancing_status_on");

		return 0;
	case 100:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_set_balancing_status_handcart_set_balancing_status_off");
		snprintf(v[1], string_size, "primary_hv_set_balancing_status_handcart_set_balancing_status_on");

		return 0;
	case 101:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_lv_status_status_init");
		snprintf(v[1], string_size, "primary_lv_status_status_idle");
		snprintf(v[2], string_size, "primary_lv_status_status_tson");
		snprintf(v[3], string_size, "primary_lv_status_status_run");
		snprintf(v[4], string_size, "primary_lv_status_status_flashing");
		snprintf(v[5], string_size, "primary_lv_status_status_error");

		return 0;
	case 102:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_lv_charging_status_status_off");
		snprintf(v[1], string_size, "primary_lv_charging_status_status_on");

		return 0;
	case 103:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_lv_cooling_aggressiveness_status_weak");
		snprintf(v[1], string_size, "primary_lv_cooling_aggressiveness_status_normal");
		snprintf(v[2], string_size, "primary_lv_cooling_aggressiveness_status_aggressive");

		return 0;
	case 104:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_lv_set_cooling_aggressiveness_status_weak");
		snprintf(v[1], string_size, "primary_lv_set_cooling_aggressiveness_status_normal");
		snprintf(v[2], string_size, "primary_lv_set_cooling_aggressiveness_status_aggressive");

		return 0;
	case 105:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_lv_radiator_speed_status_off");
		snprintf(v[1], string_size, "primary_lv_radiator_speed_status_auto");
		snprintf(v[2], string_size, "primary_lv_radiator_speed_status_manual");

		return 0;
	case 106:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_lv_pumps_speed_status_off");
		snprintf(v[1], string_size, "primary_lv_pumps_speed_status_auto");
		snprintf(v[2], string_size, "primary_lv_pumps_speed_status_manual");

		return 0;
	case 107:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_lv_set_radiator_speed_status_off");
		snprintf(v[1], string_size, "primary_lv_set_radiator_speed_status_auto");
		snprintf(v[2], string_size, "primary_lv_set_radiator_speed_status_manual");

		return 0;
	case 108:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_lv_set_pumps_speed_status_off");
		snprintf(v[1], string_size, "primary_lv_set_pumps_speed_status_auto");
		snprintf(v[2], string_size, "primary_lv_set_pumps_speed_status_manual");

		return 0;
	case 109:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_lv_inverter_connection_status_status_off");
		snprintf(v[1], string_size, "primary_lv_inverter_connection_status_status_on");

		return 0;
	case 110:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_lv_set_inverter_connection_status_status_off");
		snprintf(v[1], string_size, "primary_lv_set_inverter_connection_status_status_on");

		return 0;
	case 111:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_tlm_status_status_off");
		snprintf(v[1], string_size, "primary_tlm_status_status_on");

		return 0;
	case 112:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_tlm_set_status_status_off");
		snprintf(v[1], string_size, "primary_tlm_set_status_status_on");

		return 0;
	case 113:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_handcart_status_connected_off");
		snprintf(v[1], string_size, "primary_handcart_status_connected_on");

		return 0;
	case 114:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_handcart_settings_fans_override_off");
		snprintf(v[1], string_size, "primary_handcart_settings_fans_override_on");

		return 0;
	case 115:
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
	case 116:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_handcart_set_settings_fans_override_off");
		snprintf(v[1], string_size, "primary_handcart_set_settings_fans_override_on");

		return 0;
	case 117:
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
	case 118:
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
	case 119:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ecu_set_status_status_idle");
		snprintf(v[1], string_size, "primary_ecu_set_status_status_ready");
		snprintf(v[2], string_size, "primary_ecu_set_status_status_drive");

		return 0;
	case 120:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ecu_inverter_status_rl_disabled");
		snprintf(v[1], string_size, "primary_ecu_inverter_status_rl_rfe_on");
		snprintf(v[2], string_size, "primary_ecu_inverter_status_rl_frg_on");
		snprintf(v[3], string_size, "primary_ecu_inverter_status_rl_enabled");

		return 0;
	case 121:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ecu_inverter_status_rr_disabled");
		snprintf(v[1], string_size, "primary_ecu_inverter_status_rr_rfe_on");
		snprintf(v[2], string_size, "primary_ecu_inverter_status_rr_frg_on");
		snprintf(v[3], string_size, "primary_ecu_inverter_status_rr_enabled");

		return 0;
	case 122:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ecu_power_maps_sc_state_off");
		snprintf(v[1], string_size, "primary_ecu_power_maps_sc_state_on");

		return 0;
	case 123:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ecu_power_maps_tv_state_off");
		snprintf(v[1], string_size, "primary_ecu_power_maps_tv_state_on");

		return 0;
	case 124:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ecu_power_maps_reg_state_off");
		snprintf(v[1], string_size, "primary_ecu_power_maps_reg_state_on");

		return 0;
	case 125:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ecu_set_power_maps_sc_state_off");
		snprintf(v[1], string_size, "primary_ecu_set_power_maps_sc_state_on");

		return 0;
	case 126:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ecu_set_power_maps_tv_state_off");
		snprintf(v[1], string_size, "primary_ecu_set_power_maps_tv_state_on");

		return 0;
	case 127:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ecu_set_power_maps_reg_state_off");
		snprintf(v[1], string_size, "primary_ecu_set_power_maps_reg_state_on");

		return 0;
	case 128:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ecu_ptt_status_status_off");
		snprintf(v[1], string_size, "primary_ecu_ptt_status_status_on");

		return 0;
	case 129:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ecu_set_ptt_status_status_off");
		snprintf(v[1], string_size, "primary_ecu_set_ptt_status_status_on");

		return 0;
	case 130:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_control_status_sc_state_off");
		snprintf(v[1], string_size, "primary_control_status_sc_state_on");

		return 0;
	case 131:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_control_status_tv_state_off");
		snprintf(v[1], string_size, "primary_control_status_tv_state_on");

		return 0;
	case 132:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_control_status_reg_state_off");
		snprintf(v[1], string_size, "primary_control_status_reg_state_on");

		return 0;
	case 133:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_cells_voltage_cellboard_id_cellboard_0");
		snprintf(v[1], string_size, "primary_hv_cells_voltage_cellboard_id_cellboard_1");
		snprintf(v[2], string_size, "primary_hv_cells_voltage_cellboard_id_cellboard_2");
		snprintf(v[3], string_size, "primary_hv_cells_voltage_cellboard_id_cellboard_3");
		snprintf(v[4], string_size, "primary_hv_cells_voltage_cellboard_id_cellboard_4");
		snprintf(v[5], string_size, "primary_hv_cells_voltage_cellboard_id_cellboard_5");

		return 0;
	case 134:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_as_commands_status_steerstatus_off");
		snprintf(v[1], string_size, "primary_as_commands_status_steerstatus_on");

		return 0;
	case 135:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_as_commands_status_throttlestatus_off");
		snprintf(v[1], string_size, "primary_as_commands_status_throttlestatus_on");

		return 0;
	case 136:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_as_commands_status_brakestatus_off");
		snprintf(v[1], string_size, "primary_as_commands_status_brakestatus_on");

		return 0;
	case 137:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_as_commands_set_status_steerstatus_off");
		snprintf(v[1], string_size, "primary_as_commands_set_status_steerstatus_on");

		return 0;
	case 138:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_as_commands_set_status_throttlestatus_off");
		snprintf(v[1], string_size, "primary_as_commands_set_status_throttlestatus_on");

		return 0;
	case 139:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_as_commands_set_status_brakestatus_off");
		snprintf(v[1], string_size, "primary_as_commands_set_status_brakestatus_on");

		return 0;
	case 140:
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
	case 141:
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
	case 142:
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
	case 143:
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
	case 144:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_flash_request_cellboard_id_cellboard_0");
		snprintf(v[1], string_size, "primary_hv_flash_request_cellboard_id_cellboard_1");
		snprintf(v[2], string_size, "primary_hv_flash_request_cellboard_id_cellboard_2");
		snprintf(v[3], string_size, "primary_hv_flash_request_cellboard_id_cellboard_3");
		snprintf(v[4], string_size, "primary_hv_flash_request_cellboard_id_cellboard_4");
		snprintf(v[5], string_size, "primary_hv_flash_request_cellboard_id_cellboard_5");

		return 0;
	case 145:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_cells_temperature_cellboard_id_cellboard_0");
		snprintf(v[1], string_size, "primary_hv_cells_temperature_cellboard_id_cellboard_1");
		snprintf(v[2], string_size, "primary_hv_cells_temperature_cellboard_id_cellboard_2");
		snprintf(v[3], string_size, "primary_hv_cells_temperature_cellboard_id_cellboard_3");
		snprintf(v[4], string_size, "primary_hv_cells_temperature_cellboard_id_cellboard_4");
		snprintf(v[5], string_size, "primary_hv_cells_temperature_cellboard_id_cellboard_5");

		return 0;
	case 146:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_discharge_temperature_cellboard_id_cellboard_0");
		snprintf(v[1], string_size, "primary_hv_discharge_temperature_cellboard_id_cellboard_1");
		snprintf(v[2], string_size, "primary_hv_discharge_temperature_cellboard_id_cellboard_2");
		snprintf(v[3], string_size, "primary_hv_discharge_temperature_cellboard_id_cellboard_3");
		snprintf(v[4], string_size, "primary_hv_discharge_temperature_cellboard_id_cellboard_4");
		snprintf(v[5], string_size, "primary_hv_discharge_temperature_cellboard_id_cellboard_5");

		return 0;
	case 147:
		if(28 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_enzomma_feedback_airn_open_com");
		snprintf(v[1], string_size, "primary_hv_feedback_enzomma_feedback_precharge_open_com");
		snprintf(v[2], string_size, "primary_hv_feedback_enzomma_feedback_airp_open_com");
		snprintf(v[3], string_size, "primary_hv_feedback_enzomma_feedback_airn_open_mec");
		snprintf(v[4], string_size, "primary_hv_feedback_enzomma_feedback_precharge_open_mec");
		snprintf(v[5], string_size, "primary_hv_feedback_enzomma_feedback_airp_open_mec");
		snprintf(v[6], string_size, "primary_hv_feedback_enzomma_feedback_sd_imd_fb");
		snprintf(v[7], string_size, "primary_hv_feedback_enzomma_feedback_sd_bms_fb");
		snprintf(v[8], string_size, "primary_hv_feedback_enzomma_feedback_ts_less_than_60v");
		snprintf(v[9], string_size, "primary_hv_feedback_enzomma_feedback_plausible_state_persisted");
		snprintf(v[10], string_size, "primary_hv_feedback_enzomma_feedback_plausible_state");
		snprintf(v[11], string_size, "primary_hv_feedback_enzomma_feedback_not_bms_fault_cockpit_led");
		snprintf(v[12], string_size, "primary_hv_feedback_enzomma_feedback_not_imd_fault_cockpit_led");
		snprintf(v[13], string_size, "primary_hv_feedback_enzomma_feedback_indicator_connected");
		snprintf(v[14], string_size, "primary_hv_feedback_enzomma_feedback_not_latch_reset");
		snprintf(v[15], string_size, "primary_hv_feedback_enzomma_feedback_plausible_state_latched");
		snprintf(v[16], string_size, "primary_hv_feedback_enzomma_feedback_not_bms_fault_latched");
		snprintf(v[17], string_size, "primary_hv_feedback_enzomma_feedback_not_imd_fault_latched");
		snprintf(v[18], string_size, "primary_hv_feedback_enzomma_feedback_not_ext_fault_latched");
		snprintf(v[19], string_size, "primary_hv_feedback_enzomma_feedback_imd_ok");
		snprintf(v[20], string_size, "primary_hv_feedback_enzomma_feedback_plausible_state_rc");
		snprintf(v[21], string_size, "primary_hv_feedback_enzomma_feedback_tsal_green");
		snprintf(v[22], string_size, "primary_hv_feedback_enzomma_feedback_probing_3v3");
		snprintf(v[23], string_size, "primary_hv_feedback_enzomma_feedback_sd_out");
		snprintf(v[24], string_size, "primary_hv_feedback_enzomma_feedback_sd_in");
		snprintf(v[25], string_size, "primary_hv_feedback_enzomma_feedback_sd_end");
		snprintf(v[26], string_size, "primary_hv_feedback_enzomma_feedback_v5_mcu");
		snprintf(v[27], string_size, "primary_hv_feedback_enzomma_feedback_unknown");

		return 0;
	case 148:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_enzomma_status_low");
		snprintf(v[1], string_size, "primary_hv_feedback_enzomma_status_error");
		snprintf(v[2], string_size, "primary_hv_feedback_enzomma_status_high");

		return 0;
	case 149:
		if(12 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_error_group_post");
		snprintf(v[1], string_size, "primary_hv_error_group_over_current");
		snprintf(v[2], string_size, "primary_hv_error_group_over_power");
		snprintf(v[3], string_size, "primary_hv_error_group_under_voltage");
		snprintf(v[4], string_size, "primary_hv_error_group_over_voltage");
		snprintf(v[5], string_size, "primary_hv_error_group_under_temperature");
		snprintf(v[6], string_size, "primary_hv_error_group_over_temperature");
		snprintf(v[7], string_size, "primary_hv_error_group_can_communication");
		snprintf(v[8], string_size, "primary_hv_error_group_current_sensor_communication");
		snprintf(v[9], string_size, "primary_hv_error_group_cooling_under_temperature");
		snprintf(v[10], string_size, "primary_hv_error_group_cooling_over_temperature");
		snprintf(v[11], string_size, "primary_hv_error_group_cellboard_error");

		return 0;
	case 150:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_error_cellboard_id_cellboard_0");
		snprintf(v[1], string_size, "primary_hv_error_cellboard_id_cellboard_1");
		snprintf(v[2], string_size, "primary_hv_error_cellboard_id_cellboard_2");
		snprintf(v[3], string_size, "primary_hv_error_cellboard_id_cellboard_3");
		snprintf(v[4], string_size, "primary_hv_error_cellboard_id_cellboard_4");
		snprintf(v[5], string_size, "primary_hv_error_cellboard_id_cellboard_5");

		return 0;
	case 151:
		if(11 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_error_cellboard_group_post");
		snprintf(v[1], string_size, "primary_hv_error_cellboard_group_under_voltage");
		snprintf(v[2], string_size, "primary_hv_error_cellboard_group_over_voltage");
		snprintf(v[3], string_size, "primary_hv_error_cellboard_group_under_temperature_cells");
		snprintf(v[4], string_size, "primary_hv_error_cellboard_group_over_temperature_cells");
		snprintf(v[5], string_size, "primary_hv_error_cellboard_group_under_temperature_discharge");
		snprintf(v[6], string_size, "primary_hv_error_cellboard_group_over_temperature_discharge");
		snprintf(v[7], string_size, "primary_hv_error_cellboard_group_can_communication");
		snprintf(v[8], string_size, "primary_hv_error_cellboard_group_flash");
		snprintf(v[9], string_size, "primary_hv_error_cellboard_group_bms_monitor_communication");
		snprintf(v[10], string_size, "primary_hv_error_cellboard_group_open_wire");

		return 0;

    }
    return 0;
}
int primary_serialize_from_string(int id, char *s, uint8_t *data, size_t *size)
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
	case 1320:
	{
		primary_ivt_msg_result_wh_t tmp;
		primary_ivt_msg_result_wh_converted_t tmp_converted;
		uint8_t r_ivt_id_result_wh;
		uint8_t r_ivt_result_wh_system_error;
		uint8_t r_ivt_result_wh_measurement_error;
		uint8_t r_ivt_result_wh_channel_error;
		uint8_t r_ivt_result_wh_ocs;
		uint8_t r_ivt_msgcount_result_wh;
		int32_t r_ivt_result_wh;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNi32 "," ,
			&r_ivt_id_result_wh,
			&r_ivt_result_wh_system_error,
			&r_ivt_result_wh_measurement_error,
			&r_ivt_result_wh_channel_error,
			&r_ivt_result_wh_ocs,
			&r_ivt_msgcount_result_wh,
			&r_ivt_result_wh);
		tmp_converted.ivt_id_result_wh = (primary_ivt_msg_result_wh_ivt_id_result_wh)r_ivt_id_result_wh;
		tmp_converted.ivt_result_wh_system_error = (uint8_t)r_ivt_result_wh_system_error;
		tmp_converted.ivt_result_wh_measurement_error = (uint8_t)r_ivt_result_wh_measurement_error;
		tmp_converted.ivt_result_wh_channel_error = (uint8_t)r_ivt_result_wh_channel_error;
		tmp_converted.ivt_result_wh_ocs = (uint8_t)r_ivt_result_wh_ocs;
		tmp_converted.ivt_msgcount_result_wh = (uint8_t)r_ivt_msgcount_result_wh;
		tmp_converted.ivt_result_wh = (int32_t)r_ivt_result_wh;

		primary_ivt_msg_result_wh_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_IVT_MSG_RESULT_WH_BYTE_SIZE;
		return primary_ivt_msg_result_wh_pack(data, &tmp, PRIMARY_IVT_MSG_RESULT_WH_BYTE_SIZE);
	}
	case 1319:
	{
		primary_ivt_msg_result_as_t tmp;
		primary_ivt_msg_result_as_converted_t tmp_converted;
		uint8_t r_ivt_id_result_as;
		uint8_t r_ivt_result_as_system_error;
		uint8_t r_ivt_result_as_measurement_error;
		uint8_t r_ivt_result_as_channel_error;
		uint8_t r_ivt_result_as_ocs;
		uint8_t r_ivt_msgcount_result_as;
		int32_t r_ivt_result_as;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNi32 "," ,
			&r_ivt_id_result_as,
			&r_ivt_result_as_system_error,
			&r_ivt_result_as_measurement_error,
			&r_ivt_result_as_channel_error,
			&r_ivt_result_as_ocs,
			&r_ivt_msgcount_result_as,
			&r_ivt_result_as);
		tmp_converted.ivt_id_result_as = (primary_ivt_msg_result_as_ivt_id_result_as)r_ivt_id_result_as;
		tmp_converted.ivt_result_as_system_error = (uint8_t)r_ivt_result_as_system_error;
		tmp_converted.ivt_result_as_measurement_error = (uint8_t)r_ivt_result_as_measurement_error;
		tmp_converted.ivt_result_as_channel_error = (uint8_t)r_ivt_result_as_channel_error;
		tmp_converted.ivt_result_as_ocs = (uint8_t)r_ivt_result_as_ocs;
		tmp_converted.ivt_msgcount_result_as = (uint8_t)r_ivt_msgcount_result_as;
		tmp_converted.ivt_result_as = (int32_t)r_ivt_result_as;

		primary_ivt_msg_result_as_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_IVT_MSG_RESULT_AS_BYTE_SIZE;
		return primary_ivt_msg_result_as_pack(data, &tmp, PRIMARY_IVT_MSG_RESULT_AS_BYTE_SIZE);
	}
	case 1318:
	{
		primary_ivt_msg_result_w_t tmp;
		primary_ivt_msg_result_w_converted_t tmp_converted;
		uint8_t r_ivt_id_result_w;
		uint8_t r_ivt_result_w_system_error;
		uint8_t r_ivt_result_w_measurement_error;
		uint8_t r_ivt_result_w_channel_error;
		uint8_t r_ivt_result_w_ocs;
		uint8_t r_ivt_msgcount_result_w;
		int32_t r_ivt_result_w;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNi32 "," ,
			&r_ivt_id_result_w,
			&r_ivt_result_w_system_error,
			&r_ivt_result_w_measurement_error,
			&r_ivt_result_w_channel_error,
			&r_ivt_result_w_ocs,
			&r_ivt_msgcount_result_w,
			&r_ivt_result_w);
		tmp_converted.ivt_id_result_w = (primary_ivt_msg_result_w_ivt_id_result_w)r_ivt_id_result_w;
		tmp_converted.ivt_result_w_system_error = (uint8_t)r_ivt_result_w_system_error;
		tmp_converted.ivt_result_w_measurement_error = (uint8_t)r_ivt_result_w_measurement_error;
		tmp_converted.ivt_result_w_channel_error = (uint8_t)r_ivt_result_w_channel_error;
		tmp_converted.ivt_result_w_ocs = (uint8_t)r_ivt_result_w_ocs;
		tmp_converted.ivt_msgcount_result_w = (uint8_t)r_ivt_msgcount_result_w;
		tmp_converted.ivt_result_w = (int32_t)r_ivt_result_w;

		primary_ivt_msg_result_w_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_IVT_MSG_RESULT_W_BYTE_SIZE;
		return primary_ivt_msg_result_w_pack(data, &tmp, PRIMARY_IVT_MSG_RESULT_W_BYTE_SIZE);
	}
	case 1297:
	{
		primary_ivt_msg_response_t tmp;
		primary_ivt_msg_response_converted_t tmp_converted;
		uint8_t r_ivt_id_response;
		uint8_t r__b1_trigger_spare;
		uint8_t r__ff_wrong_command;
		uint16_t r__bf_restart_alive_cmd_id;
		uint8_t r__80_resp_measerror_item;
		uint8_t r__81_resp_systemerror_item;
		uint8_t r__82_resp_alllogdata_item;
		uint8_t r__83_resp_logdata_item;
		uint16_t r__90_resp_can_id_val_i;
		uint16_t r__91_resp_can_id_val_u1;
		uint16_t r__92_resp_can_id_val_u2;
		uint16_t r__93_resp_can_id_val_u3;
		uint16_t r__94_resp_can_id_val_t;
		uint16_t r__95_resp_can_id_val_w;
		uint16_t r__96_resp_can_id_val_as;
		uint16_t r__97_resp_can_id_val_wh;
		uint16_t r__9d_resp_can_id_val_command;
		uint16_t r__9f_resp_can_id_val_response;
		uint8_t r__a0_resp_sign_i;
		uint8_t r__a1_resp_sign_u1;
		uint8_t r__a2_resp_sign_u2;
		uint8_t r__a3_resp_sign_u3;
		uint8_t r__a4_resp_sign_t;
		uint8_t r__a5_resp_sign_w;
		uint8_t r__a6_resp_sign_as;
		uint8_t r__a7_resp_sign_wh;
		uint16_t r__b0_resp_reset_item;
		uint8_t r__b2_resp_store_dummy;
		uint16_t r__b3_resp_oc_test_time;
		int16_t r__b5_resp_oc_pos_set_threshold;
		int16_t r__b6_resp_oc_neg_set_threshold;
		uint8_t r__b9_resp_device_type;
		uint8_t r__ba_resp_sw_ver_major_hw;
		uint32_t r__bb_resp_serien_nr;
		uint64_t r__bc_resp_art_n;
		uint8_t r__a0_resp_endianess_i;
		uint8_t r__a1_resp_endianess_u1;
		uint8_t r__a2_resp_endianess_u2;
		uint8_t r__a3_resp_endianess_u3;
		uint8_t r__a4_resp_endianess_t;
		uint8_t r__a5_resp_endianess_w;
		uint8_t r__a6_resp_endianess_as;
		uint8_t r__a7_resp_endianess_wh;
		uint8_t r__a0_resp_triggermode_i;
		uint8_t r__a1_resp_triggermode_u1;
		uint8_t r__a2_resp_triggermode_u2;
		uint8_t r__a3_resp_triggermode_u3;
		uint8_t r__a4_resp_triggermode_t;
		uint8_t r__a5_resp_triggermode_w;
		uint8_t r__a6_resp_triggermode_as;
		uint8_t r__a7_resp_triggermode_wh;
		uint8_t r__b4_resp_actual_mode;
		uint8_t r__b1_07_trigger_wh;
		uint32_t r__b2_resp_store_device_sn;
		uint8_t r__ba_resp_sw_ver_minor;
		uint16_t r__b9_resp_device_current;
		uint16_t r__80_resp_measerror_count_mask;
		uint16_t r__81_resp_systemerror_count_mask;
		uint64_t r__82_resp_alllogdata_counter;
		uint64_t r__83_resp_logdata_counter;
		uint16_t r__a0_resp_cycletime_i;
		uint16_t r__a1_resp_cycletime_u1;
		uint16_t r__a2_resp_cycletime_u2;
		uint16_t r__a3_resp_cycletime_u3;
		uint16_t r__a4_resp_cycletime_t;
		uint16_t r__a5_resp_cycletime_w;
		uint16_t r__a6_resp_cycletime_as;
		uint16_t r__a7_resp_cycletime_wh;
		uint8_t r__b1_06_trigger_as;
		uint8_t r__b1_05_trigger_w;
		uint8_t r__b1_04_trigger_t;
		uint8_t r__b1_03_trigger_u3;
		uint8_t r__b1_02_trigger_u2;
		uint8_t r__b1_01_trigger_u1;
		uint8_t r__b1_00_trigger_i;
		uint8_t r__b4_resp_startup_mode;
		uint32_t r__bf_restart_alive_sn;
		uint8_t r__ba_resp_sw_ver_revision;
		uint32_t r__90_resp_can_id_sn_i;
		uint32_t r__91_resp_can_id_sn_u1;
		uint32_t r__92_resp_can_id_sn_u2;
		uint32_t r__93_resp_can_id_sn_u3;
		uint32_t r__94_resp_can_id_sn_t;
		uint32_t r__95_resp_can_id_sn_w;
		uint32_t r__96_resp_can_id_sn_as;
		uint32_t r__97_resp_can_id_sn_wh;
		uint32_t r__9d_resp_can_id_sn_command;
		uint32_t r__9f_resp_can_id_sn_response;
		uint32_t r__b0_resp_reset_device_sn;
		uint16_t r__b4_resp_code_level;
		int16_t r__b5_resp_oc_pos_reset_threshold;
		int16_t r__b6_resp_oc_neg_reset_threshold;
		uint8_t r__b9_resp_device_voltage_chan;
		uint8_t r__ba_resp_sw_ver_vear;
		uint8_t r__b9_resp_device_toi;
		int8_t r__ba_resp_sw_ver_month;
		uint8_t r__b9_resp_device_com;
		uint8_t r__ba_resp_sw_ver_day;
		uint8_t r__b9_resp_device_v_supply;
		uint8_t r__ba_resp_sw_ver_internal;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu16 "," 
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu16 "," 
			"%" SCNu16 "," 
			"%" SCNu16 "," 
			"%" SCNu16 "," 
			"%" SCNu16 "," 
			"%" SCNu16 "," 
			"%" SCNu16 "," 
			"%" SCNu16 "," 
			"%" SCNu16 "," 
			"%" SCNu16 "," 
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu16 "," 
			"%" SCNu8 ","  
			"%" SCNu16 "," 
			"%" SCNi16 "," 
			"%" SCNi16 "," 
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu32 "," 
			"%" SCNu64 "," 
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
			"%" SCNu32 "," 
			"%" SCNu8 ","  
			"%" SCNu16 "," 
			"%" SCNu16 "," 
			"%" SCNu16 "," 
			"%" SCNu64 "," 
			"%" SCNu64 "," 
			"%" SCNu16 "," 
			"%" SCNu16 "," 
			"%" SCNu16 "," 
			"%" SCNu16 "," 
			"%" SCNu16 "," 
			"%" SCNu16 "," 
			"%" SCNu16 "," 
			"%" SCNu16 "," 
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu32 "," 
			"%" SCNu8 ","  
			"%" SCNu32 "," 
			"%" SCNu32 "," 
			"%" SCNu32 "," 
			"%" SCNu32 "," 
			"%" SCNu32 "," 
			"%" SCNu32 "," 
			"%" SCNu32 "," 
			"%" SCNu32 "," 
			"%" SCNu32 "," 
			"%" SCNu32 "," 
			"%" SCNu32 "," 
			"%" SCNu16 "," 
			"%" SCNi16 "," 
			"%" SCNi16 "," 
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNi8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  ,
			&r_ivt_id_response,
			&r__b1_trigger_spare,
			&r__ff_wrong_command,
			&r__bf_restart_alive_cmd_id,
			&r__80_resp_measerror_item,
			&r__81_resp_systemerror_item,
			&r__82_resp_alllogdata_item,
			&r__83_resp_logdata_item,
			&r__90_resp_can_id_val_i,
			&r__91_resp_can_id_val_u1,
			&r__92_resp_can_id_val_u2,
			&r__93_resp_can_id_val_u3,
			&r__94_resp_can_id_val_t,
			&r__95_resp_can_id_val_w,
			&r__96_resp_can_id_val_as,
			&r__97_resp_can_id_val_wh,
			&r__9d_resp_can_id_val_command,
			&r__9f_resp_can_id_val_response,
			&r__a0_resp_sign_i,
			&r__a1_resp_sign_u1,
			&r__a2_resp_sign_u2,
			&r__a3_resp_sign_u3,
			&r__a4_resp_sign_t,
			&r__a5_resp_sign_w,
			&r__a6_resp_sign_as,
			&r__a7_resp_sign_wh,
			&r__b0_resp_reset_item,
			&r__b2_resp_store_dummy,
			&r__b3_resp_oc_test_time,
			&r__b5_resp_oc_pos_set_threshold,
			&r__b6_resp_oc_neg_set_threshold,
			&r__b9_resp_device_type,
			&r__ba_resp_sw_ver_major_hw,
			&r__bb_resp_serien_nr,
			&r__bc_resp_art_n,
			&r__a0_resp_endianess_i,
			&r__a1_resp_endianess_u1,
			&r__a2_resp_endianess_u2,
			&r__a3_resp_endianess_u3,
			&r__a4_resp_endianess_t,
			&r__a5_resp_endianess_w,
			&r__a6_resp_endianess_as,
			&r__a7_resp_endianess_wh,
			&r__a0_resp_triggermode_i,
			&r__a1_resp_triggermode_u1,
			&r__a2_resp_triggermode_u2,
			&r__a3_resp_triggermode_u3,
			&r__a4_resp_triggermode_t,
			&r__a5_resp_triggermode_w,
			&r__a6_resp_triggermode_as,
			&r__a7_resp_triggermode_wh,
			&r__b4_resp_actual_mode,
			&r__b1_07_trigger_wh,
			&r__b2_resp_store_device_sn,
			&r__ba_resp_sw_ver_minor,
			&r__b9_resp_device_current,
			&r__80_resp_measerror_count_mask,
			&r__81_resp_systemerror_count_mask,
			&r__82_resp_alllogdata_counter,
			&r__83_resp_logdata_counter,
			&r__a0_resp_cycletime_i,
			&r__a1_resp_cycletime_u1,
			&r__a2_resp_cycletime_u2,
			&r__a3_resp_cycletime_u3,
			&r__a4_resp_cycletime_t,
			&r__a5_resp_cycletime_w,
			&r__a6_resp_cycletime_as,
			&r__a7_resp_cycletime_wh,
			&r__b1_06_trigger_as,
			&r__b1_05_trigger_w,
			&r__b1_04_trigger_t,
			&r__b1_03_trigger_u3,
			&r__b1_02_trigger_u2,
			&r__b1_01_trigger_u1,
			&r__b1_00_trigger_i,
			&r__b4_resp_startup_mode,
			&r__bf_restart_alive_sn,
			&r__ba_resp_sw_ver_revision,
			&r__90_resp_can_id_sn_i,
			&r__91_resp_can_id_sn_u1,
			&r__92_resp_can_id_sn_u2,
			&r__93_resp_can_id_sn_u3,
			&r__94_resp_can_id_sn_t,
			&r__95_resp_can_id_sn_w,
			&r__96_resp_can_id_sn_as,
			&r__97_resp_can_id_sn_wh,
			&r__9d_resp_can_id_sn_command,
			&r__9f_resp_can_id_sn_response,
			&r__b0_resp_reset_device_sn,
			&r__b4_resp_code_level,
			&r__b5_resp_oc_pos_reset_threshold,
			&r__b6_resp_oc_neg_reset_threshold,
			&r__b9_resp_device_voltage_chan,
			&r__ba_resp_sw_ver_vear,
			&r__b9_resp_device_toi,
			&r__ba_resp_sw_ver_month,
			&r__b9_resp_device_com,
			&r__ba_resp_sw_ver_day,
			&r__b9_resp_device_v_supply,
			&r__ba_resp_sw_ver_internal);
		tmp_converted.ivt_id_response = (primary_ivt_msg_response_ivt_id_response)r_ivt_id_response;
		tmp_converted._b1_trigger_spare = (uint8_t)r__b1_trigger_spare;
		tmp_converted._ff_wrong_command = (uint8_t)r__ff_wrong_command;
		tmp_converted._bf_restart_alive_cmd_id = (uint16_t)r__bf_restart_alive_cmd_id;
		tmp_converted._80_resp_measerror_item = (primary_ivt_msg_response__80_resp_measerror_item)r__80_resp_measerror_item;
		tmp_converted._81_resp_systemerror_item = (primary_ivt_msg_response__81_resp_systemerror_item)r__81_resp_systemerror_item;
		tmp_converted._82_resp_alllogdata_item = (primary_ivt_msg_response__82_resp_alllogdata_item)r__82_resp_alllogdata_item;
		tmp_converted._83_resp_logdata_item = (primary_ivt_msg_response__83_resp_logdata_item)r__83_resp_logdata_item;
		tmp_converted._90_resp_can_id_val_i = (uint16_t)r__90_resp_can_id_val_i;
		tmp_converted._91_resp_can_id_val_u1 = (uint16_t)r__91_resp_can_id_val_u1;
		tmp_converted._92_resp_can_id_val_u2 = (uint16_t)r__92_resp_can_id_val_u2;
		tmp_converted._93_resp_can_id_val_u3 = (uint16_t)r__93_resp_can_id_val_u3;
		tmp_converted._94_resp_can_id_val_t = (uint16_t)r__94_resp_can_id_val_t;
		tmp_converted._95_resp_can_id_val_w = (uint16_t)r__95_resp_can_id_val_w;
		tmp_converted._96_resp_can_id_val_as = (uint16_t)r__96_resp_can_id_val_as;
		tmp_converted._97_resp_can_id_val_wh = (uint16_t)r__97_resp_can_id_val_wh;
		tmp_converted._9d_resp_can_id_val_command = (uint16_t)r__9d_resp_can_id_val_command;
		tmp_converted._9f_resp_can_id_val_response = (uint16_t)r__9f_resp_can_id_val_response;
		tmp_converted._a0_resp_sign_i = (uint8_t)r__a0_resp_sign_i;
		tmp_converted._a1_resp_sign_u1 = (uint8_t)r__a1_resp_sign_u1;
		tmp_converted._a2_resp_sign_u2 = (uint8_t)r__a2_resp_sign_u2;
		tmp_converted._a3_resp_sign_u3 = (uint8_t)r__a3_resp_sign_u3;
		tmp_converted._a4_resp_sign_t = (uint8_t)r__a4_resp_sign_t;
		tmp_converted._a5_resp_sign_w = (uint8_t)r__a5_resp_sign_w;
		tmp_converted._a6_resp_sign_as = (uint8_t)r__a6_resp_sign_as;
		tmp_converted._a7_resp_sign_wh = (uint8_t)r__a7_resp_sign_wh;
		tmp_converted._b0_resp_reset_item = (primary_ivt_msg_response__b0_resp_reset_item)r__b0_resp_reset_item;
		tmp_converted._b2_resp_store_dummy = (uint8_t)r__b2_resp_store_dummy;
		tmp_converted._b3_resp_oc_test_time = (uint16_t)r__b3_resp_oc_test_time;
		tmp_converted._b5_resp_oc_pos_set_threshold = (int16_t)r__b5_resp_oc_pos_set_threshold;
		tmp_converted._b6_resp_oc_neg_set_threshold = (int16_t)r__b6_resp_oc_neg_set_threshold;
		tmp_converted._b9_resp_device_type = (primary_ivt_msg_response__b9_resp_device_type)r__b9_resp_device_type;
		tmp_converted._ba_resp_sw_ver_major_hw = (uint8_t)r__ba_resp_sw_ver_major_hw;
		tmp_converted._bb_resp_serien_nr = (uint32_t)r__bb_resp_serien_nr;
		tmp_converted._bc_resp_art_n = (uint64_t)r__bc_resp_art_n;
		tmp_converted._a0_resp_endianess_i = (uint8_t)r__a0_resp_endianess_i;
		tmp_converted._a1_resp_endianess_u1 = (uint8_t)r__a1_resp_endianess_u1;
		tmp_converted._a2_resp_endianess_u2 = (uint8_t)r__a2_resp_endianess_u2;
		tmp_converted._a3_resp_endianess_u3 = (uint8_t)r__a3_resp_endianess_u3;
		tmp_converted._a4_resp_endianess_t = (uint8_t)r__a4_resp_endianess_t;
		tmp_converted._a5_resp_endianess_w = (uint8_t)r__a5_resp_endianess_w;
		tmp_converted._a6_resp_endianess_as = (uint8_t)r__a6_resp_endianess_as;
		tmp_converted._a7_resp_endianess_wh = (uint8_t)r__a7_resp_endianess_wh;
		tmp_converted._a0_resp_triggermode_i = (primary_ivt_msg_response__a0_resp_triggermode_i)r__a0_resp_triggermode_i;
		tmp_converted._a1_resp_triggermode_u1 = (primary_ivt_msg_response__a1_resp_triggermode_u1)r__a1_resp_triggermode_u1;
		tmp_converted._a2_resp_triggermode_u2 = (primary_ivt_msg_response__a2_resp_triggermode_u2)r__a2_resp_triggermode_u2;
		tmp_converted._a3_resp_triggermode_u3 = (primary_ivt_msg_response__a3_resp_triggermode_u3)r__a3_resp_triggermode_u3;
		tmp_converted._a4_resp_triggermode_t = (primary_ivt_msg_response__a4_resp_triggermode_t)r__a4_resp_triggermode_t;
		tmp_converted._a5_resp_triggermode_w = (primary_ivt_msg_response__a5_resp_triggermode_w)r__a5_resp_triggermode_w;
		tmp_converted._a6_resp_triggermode_as = (primary_ivt_msg_response__a6_resp_triggermode_as)r__a6_resp_triggermode_as;
		tmp_converted._a7_resp_triggermode_wh = (primary_ivt_msg_response__a7_resp_triggermode_wh)r__a7_resp_triggermode_wh;
		tmp_converted._b4_resp_actual_mode = (primary_ivt_msg_response__b4_resp_actual_mode)r__b4_resp_actual_mode;
		tmp_converted._b1_07_trigger_wh = (uint8_t)r__b1_07_trigger_wh;
		tmp_converted._b2_resp_store_device_sn = (uint32_t)r__b2_resp_store_device_sn;
		tmp_converted._ba_resp_sw_ver_minor = (uint8_t)r__ba_resp_sw_ver_minor;
		tmp_converted._b9_resp_device_current = (primary_ivt_msg_response__b9_resp_device_current)r__b9_resp_device_current;
		tmp_converted._80_resp_measerror_count_mask = (uint16_t)r__80_resp_measerror_count_mask;
		tmp_converted._81_resp_systemerror_count_mask = (uint16_t)r__81_resp_systemerror_count_mask;
		tmp_converted._82_resp_alllogdata_counter = (uint64_t)r__82_resp_alllogdata_counter;
		tmp_converted._83_resp_logdata_counter = (uint64_t)r__83_resp_logdata_counter;
		tmp_converted._a0_resp_cycletime_i = (uint16_t)r__a0_resp_cycletime_i;
		tmp_converted._a1_resp_cycletime_u1 = (uint16_t)r__a1_resp_cycletime_u1;
		tmp_converted._a2_resp_cycletime_u2 = (uint16_t)r__a2_resp_cycletime_u2;
		tmp_converted._a3_resp_cycletime_u3 = (uint16_t)r__a3_resp_cycletime_u3;
		tmp_converted._a4_resp_cycletime_t = (uint16_t)r__a4_resp_cycletime_t;
		tmp_converted._a5_resp_cycletime_w = (uint16_t)r__a5_resp_cycletime_w;
		tmp_converted._a6_resp_cycletime_as = (uint16_t)r__a6_resp_cycletime_as;
		tmp_converted._a7_resp_cycletime_wh = (uint16_t)r__a7_resp_cycletime_wh;
		tmp_converted._b1_06_trigger_as = (uint8_t)r__b1_06_trigger_as;
		tmp_converted._b1_05_trigger_w = (uint8_t)r__b1_05_trigger_w;
		tmp_converted._b1_04_trigger_t = (uint8_t)r__b1_04_trigger_t;
		tmp_converted._b1_03_trigger_u3 = (uint8_t)r__b1_03_trigger_u3;
		tmp_converted._b1_02_trigger_u2 = (uint8_t)r__b1_02_trigger_u2;
		tmp_converted._b1_01_trigger_u1 = (uint8_t)r__b1_01_trigger_u1;
		tmp_converted._b1_00_trigger_i = (uint8_t)r__b1_00_trigger_i;
		tmp_converted._b4_resp_startup_mode = (primary_ivt_msg_response__b4_resp_startup_mode)r__b4_resp_startup_mode;
		tmp_converted._bf_restart_alive_sn = (uint32_t)r__bf_restart_alive_sn;
		tmp_converted._ba_resp_sw_ver_revision = (uint8_t)r__ba_resp_sw_ver_revision;
		tmp_converted._90_resp_can_id_sn_i = (uint32_t)r__90_resp_can_id_sn_i;
		tmp_converted._91_resp_can_id_sn_u1 = (uint32_t)r__91_resp_can_id_sn_u1;
		tmp_converted._92_resp_can_id_sn_u2 = (uint32_t)r__92_resp_can_id_sn_u2;
		tmp_converted._93_resp_can_id_sn_u3 = (uint32_t)r__93_resp_can_id_sn_u3;
		tmp_converted._94_resp_can_id_sn_t = (uint32_t)r__94_resp_can_id_sn_t;
		tmp_converted._95_resp_can_id_sn_w = (uint32_t)r__95_resp_can_id_sn_w;
		tmp_converted._96_resp_can_id_sn_as = (uint32_t)r__96_resp_can_id_sn_as;
		tmp_converted._97_resp_can_id_sn_wh = (uint32_t)r__97_resp_can_id_sn_wh;
		tmp_converted._9d_resp_can_id_sn_command = (uint32_t)r__9d_resp_can_id_sn_command;
		tmp_converted._9f_resp_can_id_sn_response = (uint32_t)r__9f_resp_can_id_sn_response;
		tmp_converted._b0_resp_reset_device_sn = (uint32_t)r__b0_resp_reset_device_sn;
		tmp_converted._b4_resp_code_level = (uint16_t)r__b4_resp_code_level;
		tmp_converted._b5_resp_oc_pos_reset_threshold = (int16_t)r__b5_resp_oc_pos_reset_threshold;
		tmp_converted._b6_resp_oc_neg_reset_threshold = (int16_t)r__b6_resp_oc_neg_reset_threshold;
		tmp_converted._b9_resp_device_voltage_chan = (primary_ivt_msg_response__b9_resp_device_voltage_chan)r__b9_resp_device_voltage_chan;
		tmp_converted._ba_resp_sw_ver_vear = (uint8_t)r__ba_resp_sw_ver_vear;
		tmp_converted._b9_resp_device_toi = (primary_ivt_msg_response__b9_resp_device_toi)r__b9_resp_device_toi;
		tmp_converted._ba_resp_sw_ver_month = (int8_t)r__ba_resp_sw_ver_month;
		tmp_converted._b9_resp_device_com = (primary_ivt_msg_response__b9_resp_device_com)r__b9_resp_device_com;
		tmp_converted._ba_resp_sw_ver_day = (uint8_t)r__ba_resp_sw_ver_day;
		tmp_converted._b9_resp_device_v_supply = (primary_ivt_msg_response__b9_resp_device_v_supply)r__b9_resp_device_v_supply;
		tmp_converted._ba_resp_sw_ver_internal = (uint8_t)r__ba_resp_sw_ver_internal;

		primary_ivt_msg_response_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_IVT_MSG_RESPONSE_BYTE_SIZE;
		return primary_ivt_msg_response_pack(data, &tmp, PRIMARY_IVT_MSG_RESPONSE_BYTE_SIZE);
	}
	case 1317:
	{
		primary_ivt_msg_result_t_t tmp;
		primary_ivt_msg_result_t_converted_t tmp_converted;
		uint8_t r_ivt_id_result_t;
		uint8_t r_ivt_result_t_system_error;
		uint8_t r_ivt_result_t_measurement_error;
		uint8_t r_ivt_result_t_channel_error;
		uint8_t r_ivt_result_t_ocs;
		uint8_t r_ivt_msgcount_result_t;
		float r_ivt_result_t;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%f,"       ,
			&r_ivt_id_result_t,
			&r_ivt_result_t_system_error,
			&r_ivt_result_t_measurement_error,
			&r_ivt_result_t_channel_error,
			&r_ivt_result_t_ocs,
			&r_ivt_msgcount_result_t,
			&r_ivt_result_t);
		tmp_converted.ivt_id_result_t = (primary_ivt_msg_result_t_ivt_id_result_t)r_ivt_id_result_t;
		tmp_converted.ivt_result_t_system_error = (uint8_t)r_ivt_result_t_system_error;
		tmp_converted.ivt_result_t_measurement_error = (uint8_t)r_ivt_result_t_measurement_error;
		tmp_converted.ivt_result_t_channel_error = (uint8_t)r_ivt_result_t_channel_error;
		tmp_converted.ivt_result_t_ocs = (uint8_t)r_ivt_result_t_ocs;
		tmp_converted.ivt_msgcount_result_t = (uint8_t)r_ivt_msgcount_result_t;
		tmp_converted.ivt_result_t = (float)r_ivt_result_t;

		primary_ivt_msg_result_t_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_IVT_MSG_RESULT_T_BYTE_SIZE;
		return primary_ivt_msg_result_t_pack(data, &tmp, PRIMARY_IVT_MSG_RESULT_T_BYTE_SIZE);
	}
	case 1316:
	{
		primary_ivt_msg_result_u3_t tmp;
		primary_ivt_msg_result_u3_converted_t tmp_converted;
		uint8_t r_ivt_id_result_u3;
		uint8_t r_ivt_result_u3_system_error;
		uint8_t r_ivt_result_u3_measurement_error;
		uint8_t r_ivt_result_u3_channel_error;
		uint8_t r_ivt_result_u3_ocs;
		uint8_t r_ivt_msgcount_result_u3;
		int32_t r_ivt_result_u3;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNi32 "," ,
			&r_ivt_id_result_u3,
			&r_ivt_result_u3_system_error,
			&r_ivt_result_u3_measurement_error,
			&r_ivt_result_u3_channel_error,
			&r_ivt_result_u3_ocs,
			&r_ivt_msgcount_result_u3,
			&r_ivt_result_u3);
		tmp_converted.ivt_id_result_u3 = (primary_ivt_msg_result_u3_ivt_id_result_u3)r_ivt_id_result_u3;
		tmp_converted.ivt_result_u3_system_error = (uint8_t)r_ivt_result_u3_system_error;
		tmp_converted.ivt_result_u3_measurement_error = (uint8_t)r_ivt_result_u3_measurement_error;
		tmp_converted.ivt_result_u3_channel_error = (uint8_t)r_ivt_result_u3_channel_error;
		tmp_converted.ivt_result_u3_ocs = (uint8_t)r_ivt_result_u3_ocs;
		tmp_converted.ivt_msgcount_result_u3 = (uint8_t)r_ivt_msgcount_result_u3;
		tmp_converted.ivt_result_u3 = (int32_t)r_ivt_result_u3;

		primary_ivt_msg_result_u3_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_IVT_MSG_RESULT_U3_BYTE_SIZE;
		return primary_ivt_msg_result_u3_pack(data, &tmp, PRIMARY_IVT_MSG_RESULT_U3_BYTE_SIZE);
	}
	case 1315:
	{
		primary_ivt_msg_result_u2_t tmp;
		primary_ivt_msg_result_u2_converted_t tmp_converted;
		uint8_t r_ivt_id_result_u2;
		uint8_t r_ivt_result_u2_system_error;
		uint8_t r_ivt_result_u2_measurement_error;
		uint8_t r_ivt_result_u2_channel_error;
		uint8_t r_ivt_result_u2_ocs;
		uint8_t r_ivt_msgcount_result_u2;
		int32_t r_ivt_result_u2;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNi32 "," ,
			&r_ivt_id_result_u2,
			&r_ivt_result_u2_system_error,
			&r_ivt_result_u2_measurement_error,
			&r_ivt_result_u2_channel_error,
			&r_ivt_result_u2_ocs,
			&r_ivt_msgcount_result_u2,
			&r_ivt_result_u2);
		tmp_converted.ivt_id_result_u2 = (primary_ivt_msg_result_u2_ivt_id_result_u2)r_ivt_id_result_u2;
		tmp_converted.ivt_result_u2_system_error = (uint8_t)r_ivt_result_u2_system_error;
		tmp_converted.ivt_result_u2_measurement_error = (uint8_t)r_ivt_result_u2_measurement_error;
		tmp_converted.ivt_result_u2_channel_error = (uint8_t)r_ivt_result_u2_channel_error;
		tmp_converted.ivt_result_u2_ocs = (uint8_t)r_ivt_result_u2_ocs;
		tmp_converted.ivt_msgcount_result_u2 = (uint8_t)r_ivt_msgcount_result_u2;
		tmp_converted.ivt_result_u2 = (int32_t)r_ivt_result_u2;

		primary_ivt_msg_result_u2_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_IVT_MSG_RESULT_U2_BYTE_SIZE;
		return primary_ivt_msg_result_u2_pack(data, &tmp, PRIMARY_IVT_MSG_RESULT_U2_BYTE_SIZE);
	}
	case 1314:
	{
		primary_ivt_msg_result_u1_t tmp;
		primary_ivt_msg_result_u1_converted_t tmp_converted;
		uint8_t r_ivt_id_result_u1;
		uint8_t r_ivt_result_u1_system_error;
		uint8_t r_ivt_result_u1_measurement_error;
		uint8_t r_ivt_result_u1_channel_error;
		uint8_t r_ivt_result_u1_ocs;
		uint8_t r_ivt_msgcount_result_u1;
		int32_t r_ivt_result_u1;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNi32 "," ,
			&r_ivt_id_result_u1,
			&r_ivt_result_u1_system_error,
			&r_ivt_result_u1_measurement_error,
			&r_ivt_result_u1_channel_error,
			&r_ivt_result_u1_ocs,
			&r_ivt_msgcount_result_u1,
			&r_ivt_result_u1);
		tmp_converted.ivt_id_result_u1 = (primary_ivt_msg_result_u1_ivt_id_result_u1)r_ivt_id_result_u1;
		tmp_converted.ivt_result_u1_system_error = (uint8_t)r_ivt_result_u1_system_error;
		tmp_converted.ivt_result_u1_measurement_error = (uint8_t)r_ivt_result_u1_measurement_error;
		tmp_converted.ivt_result_u1_channel_error = (uint8_t)r_ivt_result_u1_channel_error;
		tmp_converted.ivt_result_u1_ocs = (uint8_t)r_ivt_result_u1_ocs;
		tmp_converted.ivt_msgcount_result_u1 = (uint8_t)r_ivt_msgcount_result_u1;
		tmp_converted.ivt_result_u1 = (int32_t)r_ivt_result_u1;

		primary_ivt_msg_result_u1_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_IVT_MSG_RESULT_U1_BYTE_SIZE;
		return primary_ivt_msg_result_u1_pack(data, &tmp, PRIMARY_IVT_MSG_RESULT_U1_BYTE_SIZE);
	}
	case 1313:
	{
		primary_ivt_msg_result_i_t tmp;
		primary_ivt_msg_result_i_converted_t tmp_converted;
		uint8_t r_ivt_id_result_i;
		uint8_t r_ivt_result_i_system_error;
		uint8_t r_ivt_result_i_measurement_error;
		uint8_t r_ivt_result_i_channel_error;
		uint8_t r_ivt_result_i_ocs;
		uint8_t r_ivt_msgcount_result_i;
		int32_t r_ivt_result_i;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNi32 "," ,
			&r_ivt_id_result_i,
			&r_ivt_result_i_system_error,
			&r_ivt_result_i_measurement_error,
			&r_ivt_result_i_channel_error,
			&r_ivt_result_i_ocs,
			&r_ivt_msgcount_result_i,
			&r_ivt_result_i);
		tmp_converted.ivt_id_result_i = (primary_ivt_msg_result_i_ivt_id_result_i)r_ivt_id_result_i;
		tmp_converted.ivt_result_i_system_error = (uint8_t)r_ivt_result_i_system_error;
		tmp_converted.ivt_result_i_measurement_error = (uint8_t)r_ivt_result_i_measurement_error;
		tmp_converted.ivt_result_i_channel_error = (uint8_t)r_ivt_result_i_channel_error;
		tmp_converted.ivt_result_i_ocs = (uint8_t)r_ivt_result_i_ocs;
		tmp_converted.ivt_msgcount_result_i = (uint8_t)r_ivt_msgcount_result_i;
		tmp_converted.ivt_result_i = (int32_t)r_ivt_result_i;

		primary_ivt_msg_result_i_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_IVT_MSG_RESULT_I_BYTE_SIZE;
		return primary_ivt_msg_result_i_pack(data, &tmp, PRIMARY_IVT_MSG_RESULT_I_BYTE_SIZE);
	}
	case 1041:
	{
		primary_ivt_msg_cmd_t tmp;
		primary_ivt_msg_cmd_converted_t tmp_converted;
		uint8_t r_ivt_id_cmd;
		uint8_t r__31_trigger_spare;
		uint16_t r__10_set_can_id_val_i;
		uint16_t r__11_set_can_id_val_u1;
		uint16_t r__12_set_can_id_val_u2;
		uint16_t r__13_set_can_id_val_u3;
		uint16_t r__14_set_can_id_val_t;
		uint16_t r__15_set_can_id_val_w;
		uint16_t r__16_set_can_id_val_as;
		uint16_t r__17_set_can_id_val_wh;
		uint16_t r__1d_set_can_id_val_command;
		uint16_t r__1f_set_can_id_val_response;
		uint8_t r__20_conf_sign_i;
		uint8_t r__21_conf_sign_u1;
		uint8_t r__22_conf_sign_u2;
		uint8_t r__23_conf_sign_u3;
		uint8_t r__24_conf_sign_t;
		uint8_t r__25_conf_sign_w;
		uint8_t r__26_conf_sign_as;
		uint8_t r__27_conf_sign_wh;
		uint16_t r__30_reset_item;
		uint8_t r__32_store_dummy;
		uint16_t r__33_oc_test_time;
		int16_t r__35_oc_pos_set_threshold;
		int16_t r__36_oc_neg_set_threshold;
		uint8_t r__3a_restart_to_bitrate;
		uint8_t r__3d_restart_default_dummy;
		uint8_t r__3f_restart_dummy;
		uint8_t r__40_get_measerror_item;
		uint8_t r__41_get_systemerror_item;
		uint8_t r__42_get_alllogdata_item;
		uint8_t r__43_get_logdata_item;
		uint8_t r__60_get_result_dummy_i;
		uint8_t r__61_get_result_dummy_u1;
		uint8_t r__62_get_result_dummy_u2;
		uint8_t r__63_get_result_dummy_u3;
		uint8_t r__64_get_result_dummy_t;
		uint8_t r__65_get_result_dummy_w;
		uint8_t r__66_get_result_dummy_as;
		uint8_t r__67_get_result_dummy_wh;
		uint8_t r__73_get_oc_test_dummy;
		uint8_t r__74_get_mode_dummy;
		uint8_t r__75_get_oc_pos_dummy;
		uint8_t r__76_get_oc_neg_dummy;
		uint8_t r__79_get_device_id_dummy;
		uint8_t r__7a_get_sw_version_dummy;
		uint8_t r__7b_get_serien_nr_dummy;
		uint8_t r__7c_get_art_nr_dummy;
		uint8_t r__20_conf_endianess_i;
		uint8_t r__21_conf_endianess_u1;
		uint8_t r__22_conf_endianess_u2;
		uint8_t r__23_conf_endianess_u3;
		uint8_t r__24_conf_endianess_t;
		uint8_t r__25_conf_endianess_w;
		uint8_t r__26_conf_endianess_as;
		uint8_t r__27_conf_endianess_wh;
		uint8_t r__20_conf_triggermode_i;
		uint8_t r__21_conf_triggermode_u1;
		uint8_t r__22_conf_triggermode_u2;
		uint8_t r__23_conf_triggermode_u3;
		uint8_t r__24_conf_triggermode_t;
		uint8_t r__25_conf_triggermode_w;
		uint8_t r__26_conf_triggermode_as;
		uint8_t r__27_conf_triggermode_wh;
		uint8_t r__34_actual_mode;
		uint8_t r__31_07_trigger_wh;
		uint16_t r__20_conf_cycletime_i;
		uint16_t r__21_conf_cycletime_u1;
		uint16_t r__22_conf_cycletime_u2;
		uint16_t r__23_conf_cycletime_u3;
		uint16_t r__24_conf_cycletime_t;
		uint16_t r__25_conf_cycletime_w;
		uint16_t r__26_conf_cycletime_as;
		uint16_t r__27_conf_cycletime_wh;
		uint8_t r__31_06_trigger_as;
		uint8_t r__31_05_trigger_w;
		uint8_t r__31_04_trigger_t;
		uint8_t r__31_03_trigger_u3;
		uint8_t r__31_02_trigger_u2;
		uint8_t r__31_01_trigger_u1;
		uint8_t r__31_00_trigger_i;
		uint8_t r__34_startup_mode;
		uint32_t r__10_set_can_id_sn_i;
		uint32_t r__11_set_can_id_sn_u1;
		uint32_t r__12_set_can_id_sn_u2;
		uint32_t r__13_set_can_id_sn_u3;
		uint32_t r__14_set_can_id_sn_t;
		uint32_t r__15_set_can_id_sn_w;
		uint32_t r__16_set_can_id_sn_as;
		uint32_t r__17_set_can_id_sn_wh;
		uint32_t r__1d_set_can_id_sn_command;
		uint32_t r__1f_set_can_id_sn_response;
		uint32_t r__30_reset_device_sn;
		uint16_t r__34_code_level;
		int16_t r__35_oc_pos_reset_threshold;
		int16_t r__36_oc_neg_reset_threshold;
		uint32_t r__50_get_can_id_sn_i;
		uint32_t r__51_get_can_id_sn_u1;
		uint32_t r__52_get_can_id_sn_u2;
		uint32_t r__53_get_can_id_sn_u3;
		uint32_t r__54_get_can_id_sn_t;
		uint32_t r__55_get_can_id_sn_w;
		uint32_t r__56_get_can_id_sn_as;
		uint32_t r__57_get_can_id_sn_wh;
		uint32_t r__5d_get_can_id_sn_command;
		uint32_t r__5f_get_can_id_sn_response;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu16 "," 
			"%" SCNu16 "," 
			"%" SCNu16 "," 
			"%" SCNu16 "," 
			"%" SCNu16 "," 
			"%" SCNu16 "," 
			"%" SCNu16 "," 
			"%" SCNu16 "," 
			"%" SCNu16 "," 
			"%" SCNu16 "," 
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu16 "," 
			"%" SCNu8 ","  
			"%" SCNu16 "," 
			"%" SCNi16 "," 
			"%" SCNi16 "," 
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
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu16 "," 
			"%" SCNu16 "," 
			"%" SCNu16 "," 
			"%" SCNu16 "," 
			"%" SCNu16 "," 
			"%" SCNu16 "," 
			"%" SCNu16 "," 
			"%" SCNu16 "," 
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu32 "," 
			"%" SCNu32 "," 
			"%" SCNu32 "," 
			"%" SCNu32 "," 
			"%" SCNu32 "," 
			"%" SCNu32 "," 
			"%" SCNu32 "," 
			"%" SCNu32 "," 
			"%" SCNu32 "," 
			"%" SCNu32 "," 
			"%" SCNu32 "," 
			"%" SCNu16 "," 
			"%" SCNi16 "," 
			"%" SCNi16 "," 
			"%" SCNu32 "," 
			"%" SCNu32 "," 
			"%" SCNu32 "," 
			"%" SCNu32 "," 
			"%" SCNu32 "," 
			"%" SCNu32 "," 
			"%" SCNu32 "," 
			"%" SCNu32 "," 
			"%" SCNu32 "," 
			"%" SCNu32 "," ,
			&r_ivt_id_cmd,
			&r__31_trigger_spare,
			&r__10_set_can_id_val_i,
			&r__11_set_can_id_val_u1,
			&r__12_set_can_id_val_u2,
			&r__13_set_can_id_val_u3,
			&r__14_set_can_id_val_t,
			&r__15_set_can_id_val_w,
			&r__16_set_can_id_val_as,
			&r__17_set_can_id_val_wh,
			&r__1d_set_can_id_val_command,
			&r__1f_set_can_id_val_response,
			&r__20_conf_sign_i,
			&r__21_conf_sign_u1,
			&r__22_conf_sign_u2,
			&r__23_conf_sign_u3,
			&r__24_conf_sign_t,
			&r__25_conf_sign_w,
			&r__26_conf_sign_as,
			&r__27_conf_sign_wh,
			&r__30_reset_item,
			&r__32_store_dummy,
			&r__33_oc_test_time,
			&r__35_oc_pos_set_threshold,
			&r__36_oc_neg_set_threshold,
			&r__3a_restart_to_bitrate,
			&r__3d_restart_default_dummy,
			&r__3f_restart_dummy,
			&r__40_get_measerror_item,
			&r__41_get_systemerror_item,
			&r__42_get_alllogdata_item,
			&r__43_get_logdata_item,
			&r__60_get_result_dummy_i,
			&r__61_get_result_dummy_u1,
			&r__62_get_result_dummy_u2,
			&r__63_get_result_dummy_u3,
			&r__64_get_result_dummy_t,
			&r__65_get_result_dummy_w,
			&r__66_get_result_dummy_as,
			&r__67_get_result_dummy_wh,
			&r__73_get_oc_test_dummy,
			&r__74_get_mode_dummy,
			&r__75_get_oc_pos_dummy,
			&r__76_get_oc_neg_dummy,
			&r__79_get_device_id_dummy,
			&r__7a_get_sw_version_dummy,
			&r__7b_get_serien_nr_dummy,
			&r__7c_get_art_nr_dummy,
			&r__20_conf_endianess_i,
			&r__21_conf_endianess_u1,
			&r__22_conf_endianess_u2,
			&r__23_conf_endianess_u3,
			&r__24_conf_endianess_t,
			&r__25_conf_endianess_w,
			&r__26_conf_endianess_as,
			&r__27_conf_endianess_wh,
			&r__20_conf_triggermode_i,
			&r__21_conf_triggermode_u1,
			&r__22_conf_triggermode_u2,
			&r__23_conf_triggermode_u3,
			&r__24_conf_triggermode_t,
			&r__25_conf_triggermode_w,
			&r__26_conf_triggermode_as,
			&r__27_conf_triggermode_wh,
			&r__34_actual_mode,
			&r__31_07_trigger_wh,
			&r__20_conf_cycletime_i,
			&r__21_conf_cycletime_u1,
			&r__22_conf_cycletime_u2,
			&r__23_conf_cycletime_u3,
			&r__24_conf_cycletime_t,
			&r__25_conf_cycletime_w,
			&r__26_conf_cycletime_as,
			&r__27_conf_cycletime_wh,
			&r__31_06_trigger_as,
			&r__31_05_trigger_w,
			&r__31_04_trigger_t,
			&r__31_03_trigger_u3,
			&r__31_02_trigger_u2,
			&r__31_01_trigger_u1,
			&r__31_00_trigger_i,
			&r__34_startup_mode,
			&r__10_set_can_id_sn_i,
			&r__11_set_can_id_sn_u1,
			&r__12_set_can_id_sn_u2,
			&r__13_set_can_id_sn_u3,
			&r__14_set_can_id_sn_t,
			&r__15_set_can_id_sn_w,
			&r__16_set_can_id_sn_as,
			&r__17_set_can_id_sn_wh,
			&r__1d_set_can_id_sn_command,
			&r__1f_set_can_id_sn_response,
			&r__30_reset_device_sn,
			&r__34_code_level,
			&r__35_oc_pos_reset_threshold,
			&r__36_oc_neg_reset_threshold,
			&r__50_get_can_id_sn_i,
			&r__51_get_can_id_sn_u1,
			&r__52_get_can_id_sn_u2,
			&r__53_get_can_id_sn_u3,
			&r__54_get_can_id_sn_t,
			&r__55_get_can_id_sn_w,
			&r__56_get_can_id_sn_as,
			&r__57_get_can_id_sn_wh,
			&r__5d_get_can_id_sn_command,
			&r__5f_get_can_id_sn_response);
		tmp_converted.ivt_id_cmd = (primary_ivt_msg_cmd_ivt_id_cmd)r_ivt_id_cmd;
		tmp_converted._31_trigger_spare = (uint8_t)r__31_trigger_spare;
		tmp_converted._10_set_can_id_val_i = (uint16_t)r__10_set_can_id_val_i;
		tmp_converted._11_set_can_id_val_u1 = (uint16_t)r__11_set_can_id_val_u1;
		tmp_converted._12_set_can_id_val_u2 = (uint16_t)r__12_set_can_id_val_u2;
		tmp_converted._13_set_can_id_val_u3 = (uint16_t)r__13_set_can_id_val_u3;
		tmp_converted._14_set_can_id_val_t = (uint16_t)r__14_set_can_id_val_t;
		tmp_converted._15_set_can_id_val_w = (uint16_t)r__15_set_can_id_val_w;
		tmp_converted._16_set_can_id_val_as = (uint16_t)r__16_set_can_id_val_as;
		tmp_converted._17_set_can_id_val_wh = (uint16_t)r__17_set_can_id_val_wh;
		tmp_converted._1d_set_can_id_val_command = (uint16_t)r__1d_set_can_id_val_command;
		tmp_converted._1f_set_can_id_val_response = (uint16_t)r__1f_set_can_id_val_response;
		tmp_converted._20_conf_sign_i = (uint8_t)r__20_conf_sign_i;
		tmp_converted._21_conf_sign_u1 = (uint8_t)r__21_conf_sign_u1;
		tmp_converted._22_conf_sign_u2 = (uint8_t)r__22_conf_sign_u2;
		tmp_converted._23_conf_sign_u3 = (uint8_t)r__23_conf_sign_u3;
		tmp_converted._24_conf_sign_t = (uint8_t)r__24_conf_sign_t;
		tmp_converted._25_conf_sign_w = (uint8_t)r__25_conf_sign_w;
		tmp_converted._26_conf_sign_as = (uint8_t)r__26_conf_sign_as;
		tmp_converted._27_conf_sign_wh = (uint8_t)r__27_conf_sign_wh;
		tmp_converted._30_reset_item = (primary_ivt_msg_cmd__30_reset_item)r__30_reset_item;
		tmp_converted._32_store_dummy = (uint8_t)r__32_store_dummy;
		tmp_converted._33_oc_test_time = (uint16_t)r__33_oc_test_time;
		tmp_converted._35_oc_pos_set_threshold = (int16_t)r__35_oc_pos_set_threshold;
		tmp_converted._36_oc_neg_set_threshold = (int16_t)r__36_oc_neg_set_threshold;
		tmp_converted._3a_restart_to_bitrate = (primary_ivt_msg_cmd__3a_restart_to_bitrate)r__3a_restart_to_bitrate;
		tmp_converted._3d_restart_default_dummy = (uint8_t)r__3d_restart_default_dummy;
		tmp_converted._3f_restart_dummy = (uint8_t)r__3f_restart_dummy;
		tmp_converted._40_get_measerror_item = (primary_ivt_msg_cmd__40_get_measerror_item)r__40_get_measerror_item;
		tmp_converted._41_get_systemerror_item = (primary_ivt_msg_cmd__41_get_systemerror_item)r__41_get_systemerror_item;
		tmp_converted._42_get_alllogdata_item = (primary_ivt_msg_cmd__42_get_alllogdata_item)r__42_get_alllogdata_item;
		tmp_converted._43_get_logdata_item = (primary_ivt_msg_cmd__43_get_logdata_item)r__43_get_logdata_item;
		tmp_converted._60_get_result_dummy_i = (uint8_t)r__60_get_result_dummy_i;
		tmp_converted._61_get_result_dummy_u1 = (uint8_t)r__61_get_result_dummy_u1;
		tmp_converted._62_get_result_dummy_u2 = (uint8_t)r__62_get_result_dummy_u2;
		tmp_converted._63_get_result_dummy_u3 = (uint8_t)r__63_get_result_dummy_u3;
		tmp_converted._64_get_result_dummy_t = (uint8_t)r__64_get_result_dummy_t;
		tmp_converted._65_get_result_dummy_w = (uint8_t)r__65_get_result_dummy_w;
		tmp_converted._66_get_result_dummy_as = (uint8_t)r__66_get_result_dummy_as;
		tmp_converted._67_get_result_dummy_wh = (uint8_t)r__67_get_result_dummy_wh;
		tmp_converted._73_get_oc_test_dummy = (uint8_t)r__73_get_oc_test_dummy;
		tmp_converted._74_get_mode_dummy = (uint8_t)r__74_get_mode_dummy;
		tmp_converted._75_get_oc_pos_dummy = (uint8_t)r__75_get_oc_pos_dummy;
		tmp_converted._76_get_oc_neg_dummy = (uint8_t)r__76_get_oc_neg_dummy;
		tmp_converted._79_get_device_id_dummy = (uint8_t)r__79_get_device_id_dummy;
		tmp_converted._7a_get_sw_version_dummy = (uint8_t)r__7a_get_sw_version_dummy;
		tmp_converted._7b_get_serien_nr_dummy = (uint8_t)r__7b_get_serien_nr_dummy;
		tmp_converted._7c_get_art_nr_dummy = (uint8_t)r__7c_get_art_nr_dummy;
		tmp_converted._20_conf_endianess_i = (uint8_t)r__20_conf_endianess_i;
		tmp_converted._21_conf_endianess_u1 = (uint8_t)r__21_conf_endianess_u1;
		tmp_converted._22_conf_endianess_u2 = (uint8_t)r__22_conf_endianess_u2;
		tmp_converted._23_conf_endianess_u3 = (uint8_t)r__23_conf_endianess_u3;
		tmp_converted._24_conf_endianess_t = (uint8_t)r__24_conf_endianess_t;
		tmp_converted._25_conf_endianess_w = (uint8_t)r__25_conf_endianess_w;
		tmp_converted._26_conf_endianess_as = (uint8_t)r__26_conf_endianess_as;
		tmp_converted._27_conf_endianess_wh = (uint8_t)r__27_conf_endianess_wh;
		tmp_converted._20_conf_triggermode_i = (primary_ivt_msg_cmd__20_conf_triggermode_i)r__20_conf_triggermode_i;
		tmp_converted._21_conf_triggermode_u1 = (primary_ivt_msg_cmd__21_conf_triggermode_u1)r__21_conf_triggermode_u1;
		tmp_converted._22_conf_triggermode_u2 = (primary_ivt_msg_cmd__22_conf_triggermode_u2)r__22_conf_triggermode_u2;
		tmp_converted._23_conf_triggermode_u3 = (primary_ivt_msg_cmd__23_conf_triggermode_u3)r__23_conf_triggermode_u3;
		tmp_converted._24_conf_triggermode_t = (primary_ivt_msg_cmd__24_conf_triggermode_t)r__24_conf_triggermode_t;
		tmp_converted._25_conf_triggermode_w = (primary_ivt_msg_cmd__25_conf_triggermode_w)r__25_conf_triggermode_w;
		tmp_converted._26_conf_triggermode_as = (primary_ivt_msg_cmd__26_conf_triggermode_as)r__26_conf_triggermode_as;
		tmp_converted._27_conf_triggermode_wh = (primary_ivt_msg_cmd__27_conf_triggermode_wh)r__27_conf_triggermode_wh;
		tmp_converted._34_actual_mode = (primary_ivt_msg_cmd__34_actual_mode)r__34_actual_mode;
		tmp_converted._31_07_trigger_wh = (uint8_t)r__31_07_trigger_wh;
		tmp_converted._20_conf_cycletime_i = (uint16_t)r__20_conf_cycletime_i;
		tmp_converted._21_conf_cycletime_u1 = (uint16_t)r__21_conf_cycletime_u1;
		tmp_converted._22_conf_cycletime_u2 = (uint16_t)r__22_conf_cycletime_u2;
		tmp_converted._23_conf_cycletime_u3 = (uint16_t)r__23_conf_cycletime_u3;
		tmp_converted._24_conf_cycletime_t = (uint16_t)r__24_conf_cycletime_t;
		tmp_converted._25_conf_cycletime_w = (uint16_t)r__25_conf_cycletime_w;
		tmp_converted._26_conf_cycletime_as = (uint16_t)r__26_conf_cycletime_as;
		tmp_converted._27_conf_cycletime_wh = (uint16_t)r__27_conf_cycletime_wh;
		tmp_converted._31_06_trigger_as = (uint8_t)r__31_06_trigger_as;
		tmp_converted._31_05_trigger_w = (uint8_t)r__31_05_trigger_w;
		tmp_converted._31_04_trigger_t = (uint8_t)r__31_04_trigger_t;
		tmp_converted._31_03_trigger_u3 = (uint8_t)r__31_03_trigger_u3;
		tmp_converted._31_02_trigger_u2 = (uint8_t)r__31_02_trigger_u2;
		tmp_converted._31_01_trigger_u1 = (uint8_t)r__31_01_trigger_u1;
		tmp_converted._31_00_trigger_i = (uint8_t)r__31_00_trigger_i;
		tmp_converted._34_startup_mode = (primary_ivt_msg_cmd__34_startup_mode)r__34_startup_mode;
		tmp_converted._10_set_can_id_sn_i = (uint32_t)r__10_set_can_id_sn_i;
		tmp_converted._11_set_can_id_sn_u1 = (uint32_t)r__11_set_can_id_sn_u1;
		tmp_converted._12_set_can_id_sn_u2 = (uint32_t)r__12_set_can_id_sn_u2;
		tmp_converted._13_set_can_id_sn_u3 = (uint32_t)r__13_set_can_id_sn_u3;
		tmp_converted._14_set_can_id_sn_t = (uint32_t)r__14_set_can_id_sn_t;
		tmp_converted._15_set_can_id_sn_w = (uint32_t)r__15_set_can_id_sn_w;
		tmp_converted._16_set_can_id_sn_as = (uint32_t)r__16_set_can_id_sn_as;
		tmp_converted._17_set_can_id_sn_wh = (uint32_t)r__17_set_can_id_sn_wh;
		tmp_converted._1d_set_can_id_sn_command = (uint32_t)r__1d_set_can_id_sn_command;
		tmp_converted._1f_set_can_id_sn_response = (uint32_t)r__1f_set_can_id_sn_response;
		tmp_converted._30_reset_device_sn = (uint32_t)r__30_reset_device_sn;
		tmp_converted._34_code_level = (uint16_t)r__34_code_level;
		tmp_converted._35_oc_pos_reset_threshold = (int16_t)r__35_oc_pos_reset_threshold;
		tmp_converted._36_oc_neg_reset_threshold = (int16_t)r__36_oc_neg_reset_threshold;
		tmp_converted._50_get_can_id_sn_i = (uint32_t)r__50_get_can_id_sn_i;
		tmp_converted._51_get_can_id_sn_u1 = (uint32_t)r__51_get_can_id_sn_u1;
		tmp_converted._52_get_can_id_sn_u2 = (uint32_t)r__52_get_can_id_sn_u2;
		tmp_converted._53_get_can_id_sn_u3 = (uint32_t)r__53_get_can_id_sn_u3;
		tmp_converted._54_get_can_id_sn_t = (uint32_t)r__54_get_can_id_sn_t;
		tmp_converted._55_get_can_id_sn_w = (uint32_t)r__55_get_can_id_sn_w;
		tmp_converted._56_get_can_id_sn_as = (uint32_t)r__56_get_can_id_sn_as;
		tmp_converted._57_get_can_id_sn_wh = (uint32_t)r__57_get_can_id_sn_wh;
		tmp_converted._5d_get_can_id_sn_command = (uint32_t)r__5d_get_can_id_sn_command;
		tmp_converted._5f_get_can_id_sn_response = (uint32_t)r__5f_get_can_id_sn_response;

		primary_ivt_msg_cmd_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_IVT_MSG_CMD_BYTE_SIZE;
		return primary_ivt_msg_cmd_pack(data, &tmp, PRIMARY_IVT_MSG_CMD_BYTE_SIZE);
	}
	case 0:
	{
		primary_hv_flash_t tmp;
		primary_hv_flash_converted_t tmp_converted;
		uint8_t r_start;
		uint8_t r_forward;
		uint8_t r_cellboard_id;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  ,
			&r_start,
			&r_forward,
			&r_cellboard_id);
		tmp_converted.start = (uint8_t)r_start;
		tmp_converted.forward = (primary_hv_flash_forward)r_forward;
		tmp_converted.cellboard_id = (primary_hv_flash_cellboard_id)r_cellboard_id;

		primary_hv_flash_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_HV_FLASH_BYTE_SIZE;
		return primary_hv_flash_pack(data, &tmp, PRIMARY_HV_FLASH_BYTE_SIZE);
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
		uint32_t r_canlib_build_time;
		uint32_t r_component_build_time;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu32 "," 
			"%" SCNu32 "," ,
			&r_cellboard_id,
			&r_canlib_build_time,
			&r_component_build_time);
		tmp_converted.cellboard_id = (primary_hv_cellboard_version_cellboard_id)r_cellboard_id;
		tmp_converted.canlib_build_time = (uint32_t)r_canlib_build_time;
		tmp_converted.component_build_time = (uint32_t)r_component_build_time;

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
		uint8_t r_airn_open_com;
		uint8_t r_precharge_open_com;
		uint8_t r_airp_open_com;
		uint8_t r_airn_open_mec;
		uint8_t r_precharge_open_mec;
		uint8_t r_airp_open_mec;
		uint8_t r_sd_imd_fb;
		uint8_t r_sd_bms_fb;
		uint8_t r_ts_less_than_60v;
		uint8_t r_plausible_state_persisted;
		uint8_t r_plausible_state;
		uint8_t r_not_bms_fault_cockpit_led;
		uint8_t r_not_imd_fault_cockpit_led;
		uint8_t r_indicator_connected;
		uint8_t r_not_latch_reset;
		uint8_t r_plausible_state_latched;
		uint8_t r_not_bms_fault_latched;
		uint8_t r_not_imd_fault_latched;
		uint8_t r_not_ext_fault_latched;
		uint8_t r_imd_ok;
		uint8_t r_plausible_state_rc;
		uint8_t r_tsal_green;
		uint8_t r_probing_3v3;
		uint8_t r_sd_out;
		uint8_t r_sd_in;
		uint8_t r_sd_end;
		uint8_t r_v5_mcu;
		uint8_t r_feedback_tsal_green_fault_latched;
		uint8_t r_feedback_ext_latched;
		uint8_t r_feedback_precharge_status;
		uint8_t r_feedback_tsp_over_60v_status;
		uint8_t r_feedback_check_mux;

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
			"%" SCNu8 ","  ,
			&r_airn_open_com,
			&r_precharge_open_com,
			&r_airp_open_com,
			&r_airn_open_mec,
			&r_precharge_open_mec,
			&r_airp_open_mec,
			&r_sd_imd_fb,
			&r_sd_bms_fb,
			&r_ts_less_than_60v,
			&r_plausible_state_persisted,
			&r_plausible_state,
			&r_not_bms_fault_cockpit_led,
			&r_not_imd_fault_cockpit_led,
			&r_indicator_connected,
			&r_not_latch_reset,
			&r_plausible_state_latched,
			&r_not_bms_fault_latched,
			&r_not_imd_fault_latched,
			&r_not_ext_fault_latched,
			&r_imd_ok,
			&r_plausible_state_rc,
			&r_tsal_green,
			&r_probing_3v3,
			&r_sd_out,
			&r_sd_in,
			&r_sd_end,
			&r_v5_mcu,
			&r_feedback_tsal_green_fault_latched,
			&r_feedback_ext_latched,
			&r_feedback_precharge_status,
			&r_feedback_tsp_over_60v_status,
			&r_feedback_check_mux);
		tmp_converted.airn_open_com = (primary_hv_feedback_status_airn_open_com)r_airn_open_com;
		tmp_converted.precharge_open_com = (primary_hv_feedback_status_precharge_open_com)r_precharge_open_com;
		tmp_converted.airp_open_com = (primary_hv_feedback_status_airp_open_com)r_airp_open_com;
		tmp_converted.airn_open_mec = (primary_hv_feedback_status_airn_open_mec)r_airn_open_mec;
		tmp_converted.precharge_open_mec = (primary_hv_feedback_status_precharge_open_mec)r_precharge_open_mec;
		tmp_converted.airp_open_mec = (primary_hv_feedback_status_airp_open_mec)r_airp_open_mec;
		tmp_converted.sd_imd_fb = (primary_hv_feedback_status_sd_imd_fb)r_sd_imd_fb;
		tmp_converted.sd_bms_fb = (primary_hv_feedback_status_sd_bms_fb)r_sd_bms_fb;
		tmp_converted.ts_less_than_60v = (primary_hv_feedback_status_ts_less_than_60v)r_ts_less_than_60v;
		tmp_converted.plausible_state_persisted = (primary_hv_feedback_status_plausible_state_persisted)r_plausible_state_persisted;
		tmp_converted.plausible_state = (primary_hv_feedback_status_plausible_state)r_plausible_state;
		tmp_converted.not_bms_fault_cockpit_led = (primary_hv_feedback_status_not_bms_fault_cockpit_led)r_not_bms_fault_cockpit_led;
		tmp_converted.not_imd_fault_cockpit_led = (primary_hv_feedback_status_not_imd_fault_cockpit_led)r_not_imd_fault_cockpit_led;
		tmp_converted.indicator_connected = (primary_hv_feedback_status_indicator_connected)r_indicator_connected;
		tmp_converted.not_latch_reset = (primary_hv_feedback_status_not_latch_reset)r_not_latch_reset;
		tmp_converted.plausible_state_latched = (primary_hv_feedback_status_plausible_state_latched)r_plausible_state_latched;
		tmp_converted.not_bms_fault_latched = (primary_hv_feedback_status_not_bms_fault_latched)r_not_bms_fault_latched;
		tmp_converted.not_imd_fault_latched = (primary_hv_feedback_status_not_imd_fault_latched)r_not_imd_fault_latched;
		tmp_converted.not_ext_fault_latched = (primary_hv_feedback_status_not_ext_fault_latched)r_not_ext_fault_latched;
		tmp_converted.imd_ok = (primary_hv_feedback_status_imd_ok)r_imd_ok;
		tmp_converted.plausible_state_rc = (primary_hv_feedback_status_plausible_state_rc)r_plausible_state_rc;
		tmp_converted.tsal_green = (primary_hv_feedback_status_tsal_green)r_tsal_green;
		tmp_converted.probing_3v3 = (primary_hv_feedback_status_probing_3v3)r_probing_3v3;
		tmp_converted.sd_out = (primary_hv_feedback_status_sd_out)r_sd_out;
		tmp_converted.sd_in = (primary_hv_feedback_status_sd_in)r_sd_in;
		tmp_converted.sd_end = (primary_hv_feedback_status_sd_end)r_sd_end;
		tmp_converted.v5_mcu = (primary_hv_feedback_status_v5_mcu)r_v5_mcu;
		tmp_converted.feedback_tsal_green_fault_latched = (primary_hv_feedback_status_feedback_tsal_green_fault_latched)r_feedback_tsal_green_fault_latched;
		tmp_converted.feedback_ext_latched = (primary_hv_feedback_status_feedback_ext_latched)r_feedback_ext_latched;
		tmp_converted.feedback_precharge_status = (primary_hv_feedback_status_feedback_precharge_status)r_feedback_precharge_status;
		tmp_converted.feedback_tsp_over_60v_status = (primary_hv_feedback_status_feedback_tsp_over_60v_status)r_feedback_tsp_over_60v_status;
		tmp_converted.feedback_check_mux = (primary_hv_feedback_status_feedback_check_mux)r_feedback_check_mux;

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
		uint8_t r_status;
		float r_frequency;
		float r_duty_cycle;
		uint8_t r_feedback_not_imd_fault_cockpit_led;
		uint8_t r_feedback_not_imd_fault_latched;
		uint8_t r_imd_fault;
		uint16_t r_imd_details;
		uint8_t r_imd_period;

		sscanf(s, "%" SCNu8 ","  
			"%f,"       
			"%f,"       
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu16 "," 
			"%" SCNu8 ","  ,
			&r_status,
			&r_frequency,
			&r_duty_cycle,
			&r_feedback_not_imd_fault_cockpit_led,
			&r_feedback_not_imd_fault_latched,
			&r_imd_fault,
			&r_imd_details,
			&r_imd_period);
		tmp_converted.status = (primary_hv_imd_status_status)r_status;
		tmp_converted.frequency = (float)r_frequency;
		tmp_converted.duty_cycle = (float)r_duty_cycle;
		tmp_converted.feedback_not_imd_fault_cockpit_led = (primary_hv_imd_status_feedback_not_imd_fault_cockpit_led)r_feedback_not_imd_fault_cockpit_led;
		tmp_converted.feedback_not_imd_fault_latched = (primary_hv_imd_status_feedback_not_imd_fault_latched)r_feedback_not_imd_fault_latched;
		tmp_converted.imd_fault = (uint8_t)r_imd_fault;
		tmp_converted.imd_details = (uint16_t)r_imd_details;
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
		uint8_t r_cellboard_0;
		uint8_t r_cellboard_1;
		uint8_t r_cellboard_2;
		uint8_t r_cellboard_3;
		uint8_t r_cellboard_4;
		uint8_t r_cellboard_5;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  ,
			&r_status,
			&r_cellboard_0,
			&r_cellboard_1,
			&r_cellboard_2,
			&r_cellboard_3,
			&r_cellboard_4,
			&r_cellboard_5);
		tmp_converted.status = (primary_hv_status_status)r_status;
		tmp_converted.cellboard_0 = (primary_hv_status_cellboard_0)r_cellboard_0;
		tmp_converted.cellboard_1 = (primary_hv_status_cellboard_1)r_cellboard_1;
		tmp_converted.cellboard_2 = (primary_hv_status_cellboard_2)r_cellboard_2;
		tmp_converted.cellboard_3 = (primary_hv_status_cellboard_3)r_cellboard_3;
		tmp_converted.cellboard_4 = (primary_hv_status_cellboard_4)r_cellboard_4;
		tmp_converted.cellboard_5 = (primary_hv_status_cellboard_5)r_cellboard_5;

		primary_hv_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_HV_STATUS_BYTE_SIZE;
		return primary_hv_status_pack(data, &tmp, PRIMARY_HV_STATUS_BYTE_SIZE);
	}
	case 40:
	{
		primary_hv_set_status_ecu_t tmp;
		primary_hv_set_status_ecu_converted_t tmp_converted;
		uint8_t r_status;
		uint8_t r_hv_status_set;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  ,
			&r_status,
			&r_hv_status_set);
		tmp_converted.status = (uint8_t)r_status;
		tmp_converted.hv_status_set = (primary_hv_set_status_ecu_hv_status_set)r_hv_status_set;

		primary_hv_set_status_ecu_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_HV_SET_STATUS_ECU_BYTE_SIZE;
		return primary_hv_set_status_ecu_pack(data, &tmp, PRIMARY_HV_SET_STATUS_ECU_BYTE_SIZE);
	}
	case 48:
	{
		primary_hv_set_status_handcart_t tmp;
		primary_hv_set_status_handcart_converted_t tmp_converted;
		uint8_t r_status;
		uint8_t r_hv_status_set;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  ,
			&r_status,
			&r_hv_status_set);
		tmp_converted.status = (uint8_t)r_status;
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
		uint8_t r_status;
		uint8_t r_discharging_cell_0;
		uint8_t r_discharging_cell_1;
		uint8_t r_discharging_cell_2;
		uint8_t r_discharging_cell_3;
		uint8_t r_discharging_cell_4;
		uint8_t r_discharging_cell_5;
		uint8_t r_discharging_cell_6;
		uint8_t r_discharging_cell_7;
		uint8_t r_discharging_cell_8;
		uint8_t r_discharging_cell_9;
		uint8_t r_discharging_cell_10;
		uint8_t r_discharging_cell_11;
		uint8_t r_discharging_cell_12;
		uint8_t r_discharging_cell_13;
		uint8_t r_discharging_cell_14;
		uint8_t r_discharging_cell_15;
		uint8_t r_discharging_cell_16;
		uint8_t r_discharging_cell_17;
		uint8_t r_discharging_cell_18;
		uint8_t r_discharging_cell_19;
		uint8_t r_discharging_cell_20;
		uint8_t r_discharging_cell_21;
		uint8_t r_discharging_cell_22;
		uint8_t r_discharging_cell_23;

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
			&r_balancing_cells_cell17,
			&r_status,
			&r_discharging_cell_0,
			&r_discharging_cell_1,
			&r_discharging_cell_2,
			&r_discharging_cell_3,
			&r_discharging_cell_4,
			&r_discharging_cell_5,
			&r_discharging_cell_6,
			&r_discharging_cell_7,
			&r_discharging_cell_8,
			&r_discharging_cell_9,
			&r_discharging_cell_10,
			&r_discharging_cell_11,
			&r_discharging_cell_12,
			&r_discharging_cell_13,
			&r_discharging_cell_14,
			&r_discharging_cell_15,
			&r_discharging_cell_16,
			&r_discharging_cell_17,
			&r_discharging_cell_18,
			&r_discharging_cell_19,
			&r_discharging_cell_20,
			&r_discharging_cell_21,
			&r_discharging_cell_22,
			&r_discharging_cell_23);
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
		tmp_converted.status = (primary_hv_balancing_status_status)r_status;
		tmp_converted.discharging_cell_0 = (uint8_t)r_discharging_cell_0;
		tmp_converted.discharging_cell_1 = (uint8_t)r_discharging_cell_1;
		tmp_converted.discharging_cell_2 = (uint8_t)r_discharging_cell_2;
		tmp_converted.discharging_cell_3 = (uint8_t)r_discharging_cell_3;
		tmp_converted.discharging_cell_4 = (uint8_t)r_discharging_cell_4;
		tmp_converted.discharging_cell_5 = (uint8_t)r_discharging_cell_5;
		tmp_converted.discharging_cell_6 = (uint8_t)r_discharging_cell_6;
		tmp_converted.discharging_cell_7 = (uint8_t)r_discharging_cell_7;
		tmp_converted.discharging_cell_8 = (uint8_t)r_discharging_cell_8;
		tmp_converted.discharging_cell_9 = (uint8_t)r_discharging_cell_9;
		tmp_converted.discharging_cell_10 = (uint8_t)r_discharging_cell_10;
		tmp_converted.discharging_cell_11 = (uint8_t)r_discharging_cell_11;
		tmp_converted.discharging_cell_12 = (uint8_t)r_discharging_cell_12;
		tmp_converted.discharging_cell_13 = (uint8_t)r_discharging_cell_13;
		tmp_converted.discharging_cell_14 = (uint8_t)r_discharging_cell_14;
		tmp_converted.discharging_cell_15 = (uint8_t)r_discharging_cell_15;
		tmp_converted.discharging_cell_16 = (uint8_t)r_discharging_cell_16;
		tmp_converted.discharging_cell_17 = (uint8_t)r_discharging_cell_17;
		tmp_converted.discharging_cell_18 = (uint8_t)r_discharging_cell_18;
		tmp_converted.discharging_cell_19 = (uint8_t)r_discharging_cell_19;
		tmp_converted.discharging_cell_20 = (uint8_t)r_discharging_cell_20;
		tmp_converted.discharging_cell_21 = (uint8_t)r_discharging_cell_21;
		tmp_converted.discharging_cell_22 = (uint8_t)r_discharging_cell_22;
		tmp_converted.discharging_cell_23 = (uint8_t)r_discharging_cell_23;

		primary_hv_balancing_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_HV_BALANCING_STATUS_BYTE_SIZE;
		return primary_hv_balancing_status_pack(data, &tmp, PRIMARY_HV_BALANCING_STATUS_BYTE_SIZE);
	}
	case 1032:
	{
		primary_hv_set_balancing_status_steering_wheel_t tmp;
		primary_hv_set_balancing_status_steering_wheel_converted_t tmp_converted;
		uint8_t r_status;
		float r_threshold;
		uint8_t r_set_balancing_status;
		uint8_t r_balancing_threshold;

		sscanf(s, "%" SCNu8 ","  
			"%f,"       
			"%" SCNu8 ","  
			"%" SCNu8 ","  ,
			&r_status,
			&r_threshold,
			&r_set_balancing_status,
			&r_balancing_threshold);
		tmp_converted.status = (uint8_t)r_status;
		tmp_converted.threshold = (float)r_threshold;
		tmp_converted.set_balancing_status = (primary_hv_set_balancing_status_steering_wheel_set_balancing_status)r_set_balancing_status;
		tmp_converted.balancing_threshold = (uint8_t)r_balancing_threshold;

		primary_hv_set_balancing_status_steering_wheel_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_HV_SET_BALANCING_STATUS_STEERING_WHEEL_BYTE_SIZE;
		return primary_hv_set_balancing_status_steering_wheel_pack(data, &tmp, PRIMARY_HV_SET_BALANCING_STATUS_STEERING_WHEEL_BYTE_SIZE);
	}
	case 1040:
	{
		primary_hv_set_balancing_status_handcart_t tmp;
		primary_hv_set_balancing_status_handcart_converted_t tmp_converted;
		uint8_t r_status;
		float r_threshold;
		uint8_t r_set_balancing_status;
		uint8_t r_balancing_threshold;

		sscanf(s, "%" SCNu8 ","  
			"%f,"       
			"%" SCNu8 ","  
			"%" SCNu8 ","  ,
			&r_status,
			&r_threshold,
			&r_set_balancing_status,
			&r_balancing_threshold);
		tmp_converted.status = (uint8_t)r_status;
		tmp_converted.threshold = (float)r_threshold;
		tmp_converted.set_balancing_status = (primary_hv_set_balancing_status_handcart_set_balancing_status)r_set_balancing_status;
		tmp_converted.balancing_threshold = (uint8_t)r_balancing_threshold;

		primary_hv_set_balancing_status_handcart_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_HV_SET_BALANCING_STATUS_HANDCART_BYTE_SIZE;
		return primary_hv_set_balancing_status_handcart_pack(data, &tmp, PRIMARY_HV_SET_BALANCING_STATUS_HANDCART_BYTE_SIZE);
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
		uint8_t r_control_errors_disabled_from_ecu;
		uint8_t r_control_errors_wrong_maps;
		uint8_t r_control_errors_control_watchdog;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  ,
			&r_control_enabled,
			&r_control_errors_disabled_from_ecu,
			&r_control_errors_wrong_maps,
			&r_control_errors_control_watchdog);
		tmp_converted.control_enabled = (uint8_t)r_control_enabled;
		tmp_converted.control_errors_disabled_from_ecu = (uint8_t)r_control_errors_disabled_from_ecu;
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
		float r_map_power;
		uint8_t r_sc_state;
		uint8_t r_tv_state;
		uint8_t r_reg_state;

		sscanf(s, "%f,"       
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  ,
			&r_map_power,
			&r_sc_state,
			&r_tv_state,
			&r_reg_state);
		tmp_converted.map_power = (float)r_map_power;
		tmp_converted.sc_state = (primary_ecu_power_maps_sc_state)r_sc_state;
		tmp_converted.tv_state = (primary_ecu_power_maps_tv_state)r_tv_state;
		tmp_converted.reg_state = (primary_ecu_power_maps_reg_state)r_reg_state;

		primary_ecu_power_maps_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_ECU_POWER_MAPS_BYTE_SIZE;
		return primary_ecu_power_maps_pack(data, &tmp, PRIMARY_ECU_POWER_MAPS_BYTE_SIZE);
	}
	case 96:
	{
		primary_ecu_set_power_maps_t tmp;
		primary_ecu_set_power_maps_converted_t tmp_converted;
		float r_map_power;
		uint8_t r_sc_state;
		uint8_t r_tv_state;
		uint8_t r_reg_state;

		sscanf(s, "%f,"       
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  ,
			&r_map_power,
			&r_sc_state,
			&r_tv_state,
			&r_reg_state);
		tmp_converted.map_power = (float)r_map_power;
		tmp_converted.sc_state = (primary_ecu_set_power_maps_sc_state)r_sc_state;
		tmp_converted.tv_state = (primary_ecu_set_power_maps_tv_state)r_tv_state;
		tmp_converted.reg_state = (primary_ecu_set_power_maps_reg_state)r_reg_state;

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
		float r_map_power;
		uint8_t r_sc_state;
		uint8_t r_tv_state;
		uint8_t r_reg_state;

		sscanf(s, "%f,"       
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  ,
			&r_map_power,
			&r_sc_state,
			&r_tv_state,
			&r_reg_state);
		tmp_converted.map_power = (float)r_map_power;
		tmp_converted.sc_state = (primary_control_status_sc_state)r_sc_state;
		tmp_converted.tv_state = (primary_control_status_tv_state)r_tv_state;
		tmp_converted.reg_state = (primary_control_status_reg_state)r_reg_state;

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
		uint8_t r_cellboard_id;
		uint8_t r_offset;
		float r_voltage_0;
		float r_voltage_1;
		float r_voltage_2;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_cellboard_id,
			&r_offset,
			&r_voltage_0,
			&r_voltage_1,
			&r_voltage_2);
		tmp_converted.cellboard_id = (primary_hv_cells_voltage_cellboard_id)r_cellboard_id;
		tmp_converted.offset = (uint8_t)r_offset;
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
		primary_as_commands_status_t tmp;
		primary_as_commands_status_converted_t tmp_converted;
		uint8_t r_steerstatus;
		uint8_t r_throttlestatus;
		uint8_t r_brakestatus;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  ,
			&r_steerstatus,
			&r_throttlestatus,
			&r_brakestatus);
		tmp_converted.steerstatus = (primary_as_commands_status_steerstatus)r_steerstatus;
		tmp_converted.throttlestatus = (primary_as_commands_status_throttlestatus)r_throttlestatus;
		tmp_converted.brakestatus = (primary_as_commands_status_brakestatus)r_brakestatus;

		primary_as_commands_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_AS_COMMANDS_STATUS_BYTE_SIZE;
		return primary_as_commands_status_pack(data, &tmp, PRIMARY_AS_COMMANDS_STATUS_BYTE_SIZE);
	}
	case 1104:
	{
		primary_as_commands_set_status_t tmp;
		primary_as_commands_set_status_converted_t tmp_converted;
		uint8_t r_steerstatus;
		uint8_t r_throttlestatus;
		uint8_t r_brakestatus;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  ,
			&r_steerstatus,
			&r_throttlestatus,
			&r_brakestatus);
		tmp_converted.steerstatus = (primary_as_commands_set_status_steerstatus)r_steerstatus;
		tmp_converted.throttlestatus = (primary_as_commands_set_status_throttlestatus)r_throttlestatus;
		tmp_converted.brakestatus = (primary_as_commands_set_status_brakestatus)r_brakestatus;

		primary_as_commands_set_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_AS_COMMANDS_SET_STATUS_BYTE_SIZE;
		return primary_as_commands_set_status_pack(data, &tmp, PRIMARY_AS_COMMANDS_SET_STATUS_BYTE_SIZE);
	}
	case 1760:
	{
		primary_as_commands_set_value_t tmp;
		primary_as_commands_set_value_converted_t tmp_converted;
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

		primary_as_commands_set_value_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_AS_COMMANDS_SET_VALUE_BYTE_SIZE;
		return primary_as_commands_set_value_pack(data, &tmp, PRIMARY_AS_COMMANDS_SET_VALUE_BYTE_SIZE);
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
	case 50:
	{
		primary_hv_flash_request_t tmp;
		primary_hv_flash_request_converted_t tmp_converted;
		uint8_t r_mainboard;
		uint8_t r_cellboard_id;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  ,
			&r_mainboard,
			&r_cellboard_id);
		tmp_converted.mainboard = (uint8_t)r_mainboard;
		tmp_converted.cellboard_id = (primary_hv_flash_request_cellboard_id)r_cellboard_id;

		primary_hv_flash_request_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_HV_FLASH_REQUEST_BYTE_SIZE;
		return primary_hv_flash_request_pack(data, &tmp, PRIMARY_HV_FLASH_REQUEST_BYTE_SIZE);
	}
	case 51:
	{
		primary_hv_flash_response_t tmp;
		primary_hv_flash_response_converted_t tmp_converted;
		uint8_t r_ready;

		sscanf(s, "%" SCNu8 ","  ,
			&r_ready);
		tmp_converted.ready = (uint8_t)r_ready;

		primary_hv_flash_response_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_HV_FLASH_RESPONSE_BYTE_SIZE;
		return primary_hv_flash_response_pack(data, &tmp, PRIMARY_HV_FLASH_RESPONSE_BYTE_SIZE);
	}
	case 1112:
	{
		primary_hv_ts_voltage_t tmp;
		primary_hv_ts_voltage_converted_t tmp_converted;
		float r_ts;
		float r_pack;
		float r_cells_sum;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       ,
			&r_ts,
			&r_pack,
			&r_cells_sum);
		tmp_converted.ts = (float)r_ts;
		tmp_converted.pack = (float)r_pack;
		tmp_converted.cells_sum = (float)r_cells_sum;

		primary_hv_ts_voltage_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_HV_TS_VOLTAGE_BYTE_SIZE;
		return primary_hv_ts_voltage_pack(data, &tmp, PRIMARY_HV_TS_VOLTAGE_BYTE_SIZE);
	}
	case 1832:
	{
		primary_hv_cells_temperature_t tmp;
		primary_hv_cells_temperature_converted_t tmp_converted;
		uint8_t r_cellboard_id;
		uint8_t r_temperature_id_0;
		uint8_t r_temperature_id_1;
		float r_temperature_0;
		float r_temperature_1;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%f,"       
			"%f,"       ,
			&r_cellboard_id,
			&r_temperature_id_0,
			&r_temperature_id_1,
			&r_temperature_0,
			&r_temperature_1);
		tmp_converted.cellboard_id = (primary_hv_cells_temperature_cellboard_id)r_cellboard_id;
		tmp_converted.temperature_id_0 = (uint8_t)r_temperature_id_0;
		tmp_converted.temperature_id_1 = (uint8_t)r_temperature_id_1;
		tmp_converted.temperature_0 = (float)r_temperature_0;
		tmp_converted.temperature_1 = (float)r_temperature_1;

		primary_hv_cells_temperature_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_HV_CELLS_TEMPERATURE_BYTE_SIZE;
		return primary_hv_cells_temperature_pack(data, &tmp, PRIMARY_HV_CELLS_TEMPERATURE_BYTE_SIZE);
	}
	case 1840:
	{
		primary_hv_discharge_temperature_t tmp;
		primary_hv_discharge_temperature_converted_t tmp_converted;
		uint8_t r_cellboard_id;
		float r_temperature_0;
		float r_temperature_1;
		float r_temperature_2;
		float r_temperature_3;
		float r_temperature_4;

		sscanf(s, "%" SCNu8 ","  
			"%f,"       
			"%f,"       
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_cellboard_id,
			&r_temperature_0,
			&r_temperature_1,
			&r_temperature_2,
			&r_temperature_3,
			&r_temperature_4);
		tmp_converted.cellboard_id = (primary_hv_discharge_temperature_cellboard_id)r_cellboard_id;
		tmp_converted.temperature_0 = (float)r_temperature_0;
		tmp_converted.temperature_1 = (float)r_temperature_1;
		tmp_converted.temperature_2 = (float)r_temperature_2;
		tmp_converted.temperature_3 = (float)r_temperature_3;
		tmp_converted.temperature_4 = (float)r_temperature_4;

		primary_hv_discharge_temperature_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_HV_DISCHARGE_TEMPERATURE_BYTE_SIZE;
		return primary_hv_discharge_temperature_pack(data, &tmp, PRIMARY_HV_DISCHARGE_TEMPERATURE_BYTE_SIZE);
	}
	case 1848:
	{
		primary_hv_cooling_temperature_t tmp;
		primary_hv_cooling_temperature_converted_t tmp_converted;
		float r_inlet;
		float r_outlet_0;
		float r_outlet_1;
		float r_outlet_2;
		float r_outlet_3;
		float r_outlet_4;
		float r_outlet_5;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       
			"%f,"       
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_inlet,
			&r_outlet_0,
			&r_outlet_1,
			&r_outlet_2,
			&r_outlet_3,
			&r_outlet_4,
			&r_outlet_5);
		tmp_converted.inlet = (float)r_inlet;
		tmp_converted.outlet_0 = (float)r_outlet_0;
		tmp_converted.outlet_1 = (float)r_outlet_1;
		tmp_converted.outlet_2 = (float)r_outlet_2;
		tmp_converted.outlet_3 = (float)r_outlet_3;
		tmp_converted.outlet_4 = (float)r_outlet_4;
		tmp_converted.outlet_5 = (float)r_outlet_5;

		primary_hv_cooling_temperature_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_HV_COOLING_TEMPERATURE_BYTE_SIZE;
		return primary_hv_cooling_temperature_pack(data, &tmp, PRIMARY_HV_COOLING_TEMPERATURE_BYTE_SIZE);
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
	case 696:
	{
		primary_hv_feedback_digital_t tmp;
		primary_hv_feedback_digital_converted_t tmp_converted;
		uint8_t r_digital_airn_open_com;
		uint8_t r_digital_airp_open_com;
		uint8_t r_digital_sd_imd_fb;
		uint8_t r_digital_sd_bms_fb;
		uint8_t r_digital_precharge_open_com;
		uint8_t r_digital_precharge_open_mec;
		uint8_t r_digital_ts_less_than_60v;
		uint8_t r_digital_plausible_state_persisted;
		uint8_t r_digital_plausible_state;
		uint8_t r_digital_not_bms_fault_cockpit_led;
		uint8_t r_digital_not_imd_fault_cockpit_led;
		uint8_t r_digital_indicator_connected;
		uint8_t r_digital_not_latch_reset;
		uint8_t r_digital_plausible_state_latched;
		uint8_t r_digital_not_bms_fault_latched;
		uint8_t r_digital_not_imd_fault_latched;
		uint8_t r_digital_not_ext_fault_latched;

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
			"%" SCNu8 ","  ,
			&r_digital_airn_open_com,
			&r_digital_airp_open_com,
			&r_digital_sd_imd_fb,
			&r_digital_sd_bms_fb,
			&r_digital_precharge_open_com,
			&r_digital_precharge_open_mec,
			&r_digital_ts_less_than_60v,
			&r_digital_plausible_state_persisted,
			&r_digital_plausible_state,
			&r_digital_not_bms_fault_cockpit_led,
			&r_digital_not_imd_fault_cockpit_led,
			&r_digital_indicator_connected,
			&r_digital_not_latch_reset,
			&r_digital_plausible_state_latched,
			&r_digital_not_bms_fault_latched,
			&r_digital_not_imd_fault_latched,
			&r_digital_not_ext_fault_latched);
		tmp_converted.digital_airn_open_com = (uint8_t)r_digital_airn_open_com;
		tmp_converted.digital_airp_open_com = (uint8_t)r_digital_airp_open_com;
		tmp_converted.digital_sd_imd_fb = (uint8_t)r_digital_sd_imd_fb;
		tmp_converted.digital_sd_bms_fb = (uint8_t)r_digital_sd_bms_fb;
		tmp_converted.digital_precharge_open_com = (uint8_t)r_digital_precharge_open_com;
		tmp_converted.digital_precharge_open_mec = (uint8_t)r_digital_precharge_open_mec;
		tmp_converted.digital_ts_less_than_60v = (uint8_t)r_digital_ts_less_than_60v;
		tmp_converted.digital_plausible_state_persisted = (uint8_t)r_digital_plausible_state_persisted;
		tmp_converted.digital_plausible_state = (uint8_t)r_digital_plausible_state;
		tmp_converted.digital_not_bms_fault_cockpit_led = (uint8_t)r_digital_not_bms_fault_cockpit_led;
		tmp_converted.digital_not_imd_fault_cockpit_led = (uint8_t)r_digital_not_imd_fault_cockpit_led;
		tmp_converted.digital_indicator_connected = (uint8_t)r_digital_indicator_connected;
		tmp_converted.digital_not_latch_reset = (uint8_t)r_digital_not_latch_reset;
		tmp_converted.digital_plausible_state_latched = (uint8_t)r_digital_plausible_state_latched;
		tmp_converted.digital_not_bms_fault_latched = (uint8_t)r_digital_not_bms_fault_latched;
		tmp_converted.digital_not_imd_fault_latched = (uint8_t)r_digital_not_imd_fault_latched;
		tmp_converted.digital_not_ext_fault_latched = (uint8_t)r_digital_not_ext_fault_latched;

		primary_hv_feedback_digital_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_HV_FEEDBACK_DIGITAL_BYTE_SIZE;
		return primary_hv_feedback_digital_pack(data, &tmp, PRIMARY_HV_FEEDBACK_DIGITAL_BYTE_SIZE);
	}
	case 712:
	{
		primary_hv_feedback_analog_t tmp;
		primary_hv_feedback_analog_converted_t tmp_converted;
		float r_analog_airn_open_mec;
		float r_analog_airp_open_mec;
		float r_analog_imd_ok;
		float r_analog_plausible_state_rc;
		float r_analog_tsal_green;
		float r_analog_probing_3v3;
		float r_analog_v5_mcu;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       
			"%f,"       
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_analog_airn_open_mec,
			&r_analog_airp_open_mec,
			&r_analog_imd_ok,
			&r_analog_plausible_state_rc,
			&r_analog_tsal_green,
			&r_analog_probing_3v3,
			&r_analog_v5_mcu);
		tmp_converted.analog_airn_open_mec = (float)r_analog_airn_open_mec;
		tmp_converted.analog_airp_open_mec = (float)r_analog_airp_open_mec;
		tmp_converted.analog_imd_ok = (float)r_analog_imd_ok;
		tmp_converted.analog_plausible_state_rc = (float)r_analog_plausible_state_rc;
		tmp_converted.analog_tsal_green = (float)r_analog_tsal_green;
		tmp_converted.analog_probing_3v3 = (float)r_analog_probing_3v3;
		tmp_converted.analog_v5_mcu = (float)r_analog_v5_mcu;

		primary_hv_feedback_analog_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_HV_FEEDBACK_ANALOG_BYTE_SIZE;
		return primary_hv_feedback_analog_pack(data, &tmp, PRIMARY_HV_FEEDBACK_ANALOG_BYTE_SIZE);
	}
	case 720:
	{
		primary_hv_feedback_analog_sd_t tmp;
		primary_hv_feedback_analog_sd_converted_t tmp_converted;
		float r_sd_out;
		float r_sd_in;
		float r_sd_end;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       ,
			&r_sd_out,
			&r_sd_in,
			&r_sd_end);
		tmp_converted.sd_out = (float)r_sd_out;
		tmp_converted.sd_in = (float)r_sd_in;
		tmp_converted.sd_end = (float)r_sd_end;

		primary_hv_feedback_analog_sd_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_HV_FEEDBACK_ANALOG_SD_BYTE_SIZE;
		return primary_hv_feedback_analog_sd_pack(data, &tmp, PRIMARY_HV_FEEDBACK_ANALOG_SD_BYTE_SIZE);
	}
	case 728:
	{
		primary_hv_feedback_enzomma_t tmp;
		primary_hv_feedback_enzomma_converted_t tmp_converted;
		uint8_t r_feedback;
		uint8_t r_status;
		uint8_t r_is_digital;
		uint8_t r_digital;
		float r_analog;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%f,"       ,
			&r_feedback,
			&r_status,
			&r_is_digital,
			&r_digital,
			&r_analog);
		tmp_converted.feedback = (primary_hv_feedback_enzomma_feedback)r_feedback;
		tmp_converted.status = (primary_hv_feedback_enzomma_status)r_status;
		tmp_converted.is_digital = (uint8_t)r_is_digital;
		tmp_converted.digital = (uint8_t)r_digital;
		tmp_converted.analog = (float)r_analog;

		primary_hv_feedback_enzomma_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_HV_FEEDBACK_ENZOMMA_BYTE_SIZE;
		return primary_hv_feedback_enzomma_pack(data, &tmp, PRIMARY_HV_FEEDBACK_ENZOMMA_BYTE_SIZE);
	}
	case 736:
	{
		primary_hv_error_t tmp;
		primary_hv_error_converted_t tmp_converted;
		uint8_t r_group;
		uint16_t r_instance;
		uint8_t r_cellboard_id;
		uint8_t r_cellboard_group;
		uint16_t r_cellboard_instance;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu16 "," 
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu16 "," ,
			&r_group,
			&r_instance,
			&r_cellboard_id,
			&r_cellboard_group,
			&r_cellboard_instance);
		tmp_converted.group = (primary_hv_error_group)r_group;
		tmp_converted.instance = (uint16_t)r_instance;
		tmp_converted.cellboard_id = (primary_hv_error_cellboard_id)r_cellboard_id;
		tmp_converted.cellboard_group = (primary_hv_error_cellboard_group)r_cellboard_group;
		tmp_converted.cellboard_instance = (uint16_t)r_cellboard_instance;

		primary_hv_error_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_HV_ERROR_BYTE_SIZE;
		return primary_hv_error_pack(data, &tmp, PRIMARY_HV_ERROR_BYTE_SIZE);
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
		case 1320: return 7;
		case 1319: return 7;
		case 1318: return 7;
		case 1297: return 100;
		case 1317: return 7;
		case 1316: return 7;
		case 1315: return 7;
		case 1314: return 7;
		case 1313: return 7;
		case 1041: return 106;
		case 0: return 3;
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
		case 520: return 32;
		case 528: return 7;
		case 536: return 8;
		case 544: return 5;
		case 552: return 8;
		case 560: return 7;
		case 40: return 2;
		case 48: return 2;
		case 1544: return 54;
		case 1032: return 4;
		case 1040: return 4;
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
		case 672: return 4;
		case 96: return 4;
		case 1616: return 1;
		case 1096: return 1;
		case 513: return 8;
		case 680: return 5;
		case 688: return 4;
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
		case 1720: return 5;
		case 1728: return 4;
		case 1736: return 5;
		case 1744: return 3;
		case 1752: return 3;
		case 1104: return 3;
		case 1760: return 3;
		case 1768: return 1;
		case 1776: return 8;
		case 1784: return 1;
		case 1792: return 4;
		case 1800: return 4;
		case 1808: return 4;
		case 1824: return 4;
		case 50: return 2;
		case 51: return 1;
		case 1112: return 3;
		case 1832: return 5;
		case 1840: return 6;
		case 1848: return 7;
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
		case 696: return 17;
		case 712: return 7;
		case 720: return 3;
		case 728: return 5;
		case 736: return 5;
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
	case 1320:
		if(fields_types_size < 7) return 0;
		fields_types[0] = e_primary_ivt_msg_result_wh_ivt_id_result_wh;
		fields_types[1] = e_primary_uint8_t;
		fields_types[2] = e_primary_uint8_t;
		fields_types[3] = e_primary_uint8_t;
		fields_types[4] = e_primary_uint8_t;
		fields_types[5] = e_primary_uint8_t;
		fields_types[6] = e_primary_int32_t;
		return 7;
	case 1319:
		if(fields_types_size < 7) return 0;
		fields_types[0] = e_primary_ivt_msg_result_as_ivt_id_result_as;
		fields_types[1] = e_primary_uint8_t;
		fields_types[2] = e_primary_uint8_t;
		fields_types[3] = e_primary_uint8_t;
		fields_types[4] = e_primary_uint8_t;
		fields_types[5] = e_primary_uint8_t;
		fields_types[6] = e_primary_int32_t;
		return 7;
	case 1318:
		if(fields_types_size < 7) return 0;
		fields_types[0] = e_primary_ivt_msg_result_w_ivt_id_result_w;
		fields_types[1] = e_primary_uint8_t;
		fields_types[2] = e_primary_uint8_t;
		fields_types[3] = e_primary_uint8_t;
		fields_types[4] = e_primary_uint8_t;
		fields_types[5] = e_primary_uint8_t;
		fields_types[6] = e_primary_int32_t;
		return 7;
	case 1297:
		if(fields_types_size < 100) return 0;
		fields_types[0] = e_primary_ivt_msg_response_ivt_id_response;
		fields_types[1] = e_primary_uint8_t;
		fields_types[2] = e_primary_uint8_t;
		fields_types[3] = e_primary_uint16_t;
		fields_types[4] = e_primary_ivt_msg_response__80_resp_measerror_item;
		fields_types[5] = e_primary_ivt_msg_response__81_resp_systemerror_item;
		fields_types[6] = e_primary_ivt_msg_response__82_resp_alllogdata_item;
		fields_types[7] = e_primary_ivt_msg_response__83_resp_logdata_item;
		fields_types[8] = e_primary_uint16_t;
		fields_types[9] = e_primary_uint16_t;
		fields_types[10] = e_primary_uint16_t;
		fields_types[11] = e_primary_uint16_t;
		fields_types[12] = e_primary_uint16_t;
		fields_types[13] = e_primary_uint16_t;
		fields_types[14] = e_primary_uint16_t;
		fields_types[15] = e_primary_uint16_t;
		fields_types[16] = e_primary_uint16_t;
		fields_types[17] = e_primary_uint16_t;
		fields_types[18] = e_primary_uint8_t;
		fields_types[19] = e_primary_uint8_t;
		fields_types[20] = e_primary_uint8_t;
		fields_types[21] = e_primary_uint8_t;
		fields_types[22] = e_primary_uint8_t;
		fields_types[23] = e_primary_uint8_t;
		fields_types[24] = e_primary_uint8_t;
		fields_types[25] = e_primary_uint8_t;
		fields_types[26] = e_primary_ivt_msg_response__b0_resp_reset_item;
		fields_types[27] = e_primary_uint8_t;
		fields_types[28] = e_primary_uint16_t;
		fields_types[29] = e_primary_int16_t;
		fields_types[30] = e_primary_int16_t;
		fields_types[31] = e_primary_ivt_msg_response__b9_resp_device_type;
		fields_types[32] = e_primary_uint8_t;
		fields_types[33] = e_primary_uint32_t;
		fields_types[34] = e_primary_uint64_t;
		fields_types[35] = e_primary_uint8_t;
		fields_types[36] = e_primary_uint8_t;
		fields_types[37] = e_primary_uint8_t;
		fields_types[38] = e_primary_uint8_t;
		fields_types[39] = e_primary_uint8_t;
		fields_types[40] = e_primary_uint8_t;
		fields_types[41] = e_primary_uint8_t;
		fields_types[42] = e_primary_uint8_t;
		fields_types[43] = e_primary_ivt_msg_response__a0_resp_triggermode_i;
		fields_types[44] = e_primary_ivt_msg_response__a1_resp_triggermode_u1;
		fields_types[45] = e_primary_ivt_msg_response__a2_resp_triggermode_u2;
		fields_types[46] = e_primary_ivt_msg_response__a3_resp_triggermode_u3;
		fields_types[47] = e_primary_ivt_msg_response__a4_resp_triggermode_t;
		fields_types[48] = e_primary_ivt_msg_response__a5_resp_triggermode_w;
		fields_types[49] = e_primary_ivt_msg_response__a6_resp_triggermode_as;
		fields_types[50] = e_primary_ivt_msg_response__a7_resp_triggermode_wh;
		fields_types[51] = e_primary_ivt_msg_response__b4_resp_actual_mode;
		fields_types[52] = e_primary_uint8_t;
		fields_types[53] = e_primary_uint32_t;
		fields_types[54] = e_primary_uint8_t;
		fields_types[55] = e_primary_ivt_msg_response__b9_resp_device_current;
		fields_types[56] = e_primary_uint16_t;
		fields_types[57] = e_primary_uint16_t;
		fields_types[58] = e_primary_uint64_t;
		fields_types[59] = e_primary_uint64_t;
		fields_types[60] = e_primary_uint16_t;
		fields_types[61] = e_primary_uint16_t;
		fields_types[62] = e_primary_uint16_t;
		fields_types[63] = e_primary_uint16_t;
		fields_types[64] = e_primary_uint16_t;
		fields_types[65] = e_primary_uint16_t;
		fields_types[66] = e_primary_uint16_t;
		fields_types[67] = e_primary_uint16_t;
		fields_types[68] = e_primary_uint8_t;
		fields_types[69] = e_primary_uint8_t;
		fields_types[70] = e_primary_uint8_t;
		fields_types[71] = e_primary_uint8_t;
		fields_types[72] = e_primary_uint8_t;
		fields_types[73] = e_primary_uint8_t;
		fields_types[74] = e_primary_uint8_t;
		fields_types[75] = e_primary_ivt_msg_response__b4_resp_startup_mode;
		fields_types[76] = e_primary_uint32_t;
		fields_types[77] = e_primary_uint8_t;
		fields_types[78] = e_primary_uint32_t;
		fields_types[79] = e_primary_uint32_t;
		fields_types[80] = e_primary_uint32_t;
		fields_types[81] = e_primary_uint32_t;
		fields_types[82] = e_primary_uint32_t;
		fields_types[83] = e_primary_uint32_t;
		fields_types[84] = e_primary_uint32_t;
		fields_types[85] = e_primary_uint32_t;
		fields_types[86] = e_primary_uint32_t;
		fields_types[87] = e_primary_uint32_t;
		fields_types[88] = e_primary_uint32_t;
		fields_types[89] = e_primary_uint16_t;
		fields_types[90] = e_primary_int16_t;
		fields_types[91] = e_primary_int16_t;
		fields_types[92] = e_primary_ivt_msg_response__b9_resp_device_voltage_chan;
		fields_types[93] = e_primary_uint8_t;
		fields_types[94] = e_primary_ivt_msg_response__b9_resp_device_toi;
		fields_types[95] = e_primary_int8_t;
		fields_types[96] = e_primary_ivt_msg_response__b9_resp_device_com;
		fields_types[97] = e_primary_uint8_t;
		fields_types[98] = e_primary_ivt_msg_response__b9_resp_device_v_supply;
		fields_types[99] = e_primary_uint8_t;
		return 100;
	case 1317:
		if(fields_types_size < 7) return 0;
		fields_types[0] = e_primary_ivt_msg_result_t_ivt_id_result_t;
		fields_types[1] = e_primary_uint8_t;
		fields_types[2] = e_primary_uint8_t;
		fields_types[3] = e_primary_uint8_t;
		fields_types[4] = e_primary_uint8_t;
		fields_types[5] = e_primary_uint8_t;
		fields_types[6] = e_primary_float;
		return 7;
	case 1316:
		if(fields_types_size < 7) return 0;
		fields_types[0] = e_primary_ivt_msg_result_u3_ivt_id_result_u3;
		fields_types[1] = e_primary_uint8_t;
		fields_types[2] = e_primary_uint8_t;
		fields_types[3] = e_primary_uint8_t;
		fields_types[4] = e_primary_uint8_t;
		fields_types[5] = e_primary_uint8_t;
		fields_types[6] = e_primary_int32_t;
		return 7;
	case 1315:
		if(fields_types_size < 7) return 0;
		fields_types[0] = e_primary_ivt_msg_result_u2_ivt_id_result_u2;
		fields_types[1] = e_primary_uint8_t;
		fields_types[2] = e_primary_uint8_t;
		fields_types[3] = e_primary_uint8_t;
		fields_types[4] = e_primary_uint8_t;
		fields_types[5] = e_primary_uint8_t;
		fields_types[6] = e_primary_int32_t;
		return 7;
	case 1314:
		if(fields_types_size < 7) return 0;
		fields_types[0] = e_primary_ivt_msg_result_u1_ivt_id_result_u1;
		fields_types[1] = e_primary_uint8_t;
		fields_types[2] = e_primary_uint8_t;
		fields_types[3] = e_primary_uint8_t;
		fields_types[4] = e_primary_uint8_t;
		fields_types[5] = e_primary_uint8_t;
		fields_types[6] = e_primary_int32_t;
		return 7;
	case 1313:
		if(fields_types_size < 7) return 0;
		fields_types[0] = e_primary_ivt_msg_result_i_ivt_id_result_i;
		fields_types[1] = e_primary_uint8_t;
		fields_types[2] = e_primary_uint8_t;
		fields_types[3] = e_primary_uint8_t;
		fields_types[4] = e_primary_uint8_t;
		fields_types[5] = e_primary_uint8_t;
		fields_types[6] = e_primary_int32_t;
		return 7;
	case 1041:
		if(fields_types_size < 106) return 0;
		fields_types[0] = e_primary_ivt_msg_cmd_ivt_id_cmd;
		fields_types[1] = e_primary_uint8_t;
		fields_types[2] = e_primary_uint16_t;
		fields_types[3] = e_primary_uint16_t;
		fields_types[4] = e_primary_uint16_t;
		fields_types[5] = e_primary_uint16_t;
		fields_types[6] = e_primary_uint16_t;
		fields_types[7] = e_primary_uint16_t;
		fields_types[8] = e_primary_uint16_t;
		fields_types[9] = e_primary_uint16_t;
		fields_types[10] = e_primary_uint16_t;
		fields_types[11] = e_primary_uint16_t;
		fields_types[12] = e_primary_uint8_t;
		fields_types[13] = e_primary_uint8_t;
		fields_types[14] = e_primary_uint8_t;
		fields_types[15] = e_primary_uint8_t;
		fields_types[16] = e_primary_uint8_t;
		fields_types[17] = e_primary_uint8_t;
		fields_types[18] = e_primary_uint8_t;
		fields_types[19] = e_primary_uint8_t;
		fields_types[20] = e_primary_ivt_msg_cmd__30_reset_item;
		fields_types[21] = e_primary_uint8_t;
		fields_types[22] = e_primary_uint16_t;
		fields_types[23] = e_primary_int16_t;
		fields_types[24] = e_primary_int16_t;
		fields_types[25] = e_primary_ivt_msg_cmd__3a_restart_to_bitrate;
		fields_types[26] = e_primary_uint8_t;
		fields_types[27] = e_primary_uint8_t;
		fields_types[28] = e_primary_ivt_msg_cmd__40_get_measerror_item;
		fields_types[29] = e_primary_ivt_msg_cmd__41_get_systemerror_item;
		fields_types[30] = e_primary_ivt_msg_cmd__42_get_alllogdata_item;
		fields_types[31] = e_primary_ivt_msg_cmd__43_get_logdata_item;
		fields_types[32] = e_primary_uint8_t;
		fields_types[33] = e_primary_uint8_t;
		fields_types[34] = e_primary_uint8_t;
		fields_types[35] = e_primary_uint8_t;
		fields_types[36] = e_primary_uint8_t;
		fields_types[37] = e_primary_uint8_t;
		fields_types[38] = e_primary_uint8_t;
		fields_types[39] = e_primary_uint8_t;
		fields_types[40] = e_primary_uint8_t;
		fields_types[41] = e_primary_uint8_t;
		fields_types[42] = e_primary_uint8_t;
		fields_types[43] = e_primary_uint8_t;
		fields_types[44] = e_primary_uint8_t;
		fields_types[45] = e_primary_uint8_t;
		fields_types[46] = e_primary_uint8_t;
		fields_types[47] = e_primary_uint8_t;
		fields_types[48] = e_primary_uint8_t;
		fields_types[49] = e_primary_uint8_t;
		fields_types[50] = e_primary_uint8_t;
		fields_types[51] = e_primary_uint8_t;
		fields_types[52] = e_primary_uint8_t;
		fields_types[53] = e_primary_uint8_t;
		fields_types[54] = e_primary_uint8_t;
		fields_types[55] = e_primary_uint8_t;
		fields_types[56] = e_primary_ivt_msg_cmd__20_conf_triggermode_i;
		fields_types[57] = e_primary_ivt_msg_cmd__21_conf_triggermode_u1;
		fields_types[58] = e_primary_ivt_msg_cmd__22_conf_triggermode_u2;
		fields_types[59] = e_primary_ivt_msg_cmd__23_conf_triggermode_u3;
		fields_types[60] = e_primary_ivt_msg_cmd__24_conf_triggermode_t;
		fields_types[61] = e_primary_ivt_msg_cmd__25_conf_triggermode_w;
		fields_types[62] = e_primary_ivt_msg_cmd__26_conf_triggermode_as;
		fields_types[63] = e_primary_ivt_msg_cmd__27_conf_triggermode_wh;
		fields_types[64] = e_primary_ivt_msg_cmd__34_actual_mode;
		fields_types[65] = e_primary_uint8_t;
		fields_types[66] = e_primary_uint16_t;
		fields_types[67] = e_primary_uint16_t;
		fields_types[68] = e_primary_uint16_t;
		fields_types[69] = e_primary_uint16_t;
		fields_types[70] = e_primary_uint16_t;
		fields_types[71] = e_primary_uint16_t;
		fields_types[72] = e_primary_uint16_t;
		fields_types[73] = e_primary_uint16_t;
		fields_types[74] = e_primary_uint8_t;
		fields_types[75] = e_primary_uint8_t;
		fields_types[76] = e_primary_uint8_t;
		fields_types[77] = e_primary_uint8_t;
		fields_types[78] = e_primary_uint8_t;
		fields_types[79] = e_primary_uint8_t;
		fields_types[80] = e_primary_uint8_t;
		fields_types[81] = e_primary_ivt_msg_cmd__34_startup_mode;
		fields_types[82] = e_primary_uint32_t;
		fields_types[83] = e_primary_uint32_t;
		fields_types[84] = e_primary_uint32_t;
		fields_types[85] = e_primary_uint32_t;
		fields_types[86] = e_primary_uint32_t;
		fields_types[87] = e_primary_uint32_t;
		fields_types[88] = e_primary_uint32_t;
		fields_types[89] = e_primary_uint32_t;
		fields_types[90] = e_primary_uint32_t;
		fields_types[91] = e_primary_uint32_t;
		fields_types[92] = e_primary_uint32_t;
		fields_types[93] = e_primary_uint16_t;
		fields_types[94] = e_primary_int16_t;
		fields_types[95] = e_primary_int16_t;
		fields_types[96] = e_primary_uint32_t;
		fields_types[97] = e_primary_uint32_t;
		fields_types[98] = e_primary_uint32_t;
		fields_types[99] = e_primary_uint32_t;
		fields_types[100] = e_primary_uint32_t;
		fields_types[101] = e_primary_uint32_t;
		fields_types[102] = e_primary_uint32_t;
		fields_types[103] = e_primary_uint32_t;
		fields_types[104] = e_primary_uint32_t;
		fields_types[105] = e_primary_uint32_t;
		return 106;
	case 0:
		if(fields_types_size < 3) return 0;
		fields_types[0] = e_primary_uint8_t;
		fields_types[1] = e_primary_hv_flash_forward;
		fields_types[2] = e_primary_hv_flash_cellboard_id;
		return 3;
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
		fields_types[1] = e_primary_uint32_t;
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
		if(fields_types_size < 32) return 0;
		fields_types[0] = e_primary_hv_feedback_status_airn_open_com;
		fields_types[1] = e_primary_hv_feedback_status_precharge_open_com;
		fields_types[2] = e_primary_hv_feedback_status_airp_open_com;
		fields_types[3] = e_primary_hv_feedback_status_airn_open_mec;
		fields_types[4] = e_primary_hv_feedback_status_precharge_open_mec;
		fields_types[5] = e_primary_hv_feedback_status_airp_open_mec;
		fields_types[6] = e_primary_hv_feedback_status_sd_imd_fb;
		fields_types[7] = e_primary_hv_feedback_status_sd_bms_fb;
		fields_types[8] = e_primary_hv_feedback_status_ts_less_than_60v;
		fields_types[9] = e_primary_hv_feedback_status_plausible_state_persisted;
		fields_types[10] = e_primary_hv_feedback_status_plausible_state;
		fields_types[11] = e_primary_hv_feedback_status_not_bms_fault_cockpit_led;
		fields_types[12] = e_primary_hv_feedback_status_not_imd_fault_cockpit_led;
		fields_types[13] = e_primary_hv_feedback_status_indicator_connected;
		fields_types[14] = e_primary_hv_feedback_status_not_latch_reset;
		fields_types[15] = e_primary_hv_feedback_status_plausible_state_latched;
		fields_types[16] = e_primary_hv_feedback_status_not_bms_fault_latched;
		fields_types[17] = e_primary_hv_feedback_status_not_imd_fault_latched;
		fields_types[18] = e_primary_hv_feedback_status_not_ext_fault_latched;
		fields_types[19] = e_primary_hv_feedback_status_imd_ok;
		fields_types[20] = e_primary_hv_feedback_status_plausible_state_rc;
		fields_types[21] = e_primary_hv_feedback_status_tsal_green;
		fields_types[22] = e_primary_hv_feedback_status_probing_3v3;
		fields_types[23] = e_primary_hv_feedback_status_sd_out;
		fields_types[24] = e_primary_hv_feedback_status_sd_in;
		fields_types[25] = e_primary_hv_feedback_status_sd_end;
		fields_types[26] = e_primary_hv_feedback_status_v5_mcu;
		fields_types[27] = e_primary_hv_feedback_status_feedback_tsal_green_fault_latched;
		fields_types[28] = e_primary_hv_feedback_status_feedback_ext_latched;
		fields_types[29] = e_primary_hv_feedback_status_feedback_precharge_status;
		fields_types[30] = e_primary_hv_feedback_status_feedback_tsp_over_60v_status;
		fields_types[31] = e_primary_hv_feedback_status_feedback_check_mux;
		return 32;
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
		if(fields_types_size < 8) return 0;
		fields_types[0] = e_primary_hv_imd_status_status;
		fields_types[1] = e_primary_float;
		fields_types[2] = e_primary_float;
		fields_types[3] = e_primary_hv_imd_status_feedback_not_imd_fault_cockpit_led;
		fields_types[4] = e_primary_hv_imd_status_feedback_not_imd_fault_latched;
		fields_types[5] = e_primary_uint8_t;
		fields_types[6] = e_primary_uint16_t;
		fields_types[7] = e_primary_uint8_t;
		return 8;
	case 560:
		if(fields_types_size < 7) return 0;
		fields_types[0] = e_primary_hv_status_status;
		fields_types[1] = e_primary_hv_status_cellboard_0;
		fields_types[2] = e_primary_hv_status_cellboard_1;
		fields_types[3] = e_primary_hv_status_cellboard_2;
		fields_types[4] = e_primary_hv_status_cellboard_3;
		fields_types[5] = e_primary_hv_status_cellboard_4;
		fields_types[6] = e_primary_hv_status_cellboard_5;
		return 7;
	case 40:
		if(fields_types_size < 2) return 0;
		fields_types[0] = e_primary_uint8_t;
		fields_types[1] = e_primary_hv_set_status_ecu_hv_status_set;
		return 2;
	case 48:
		if(fields_types_size < 2) return 0;
		fields_types[0] = e_primary_uint8_t;
		fields_types[1] = e_primary_hv_set_status_handcart_hv_status_set;
		return 2;
	case 1544:
		if(fields_types_size < 54) return 0;
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
		fields_types[29] = e_primary_hv_balancing_status_status;
		fields_types[30] = e_primary_uint8_t;
		fields_types[31] = e_primary_uint8_t;
		fields_types[32] = e_primary_uint8_t;
		fields_types[33] = e_primary_uint8_t;
		fields_types[34] = e_primary_uint8_t;
		fields_types[35] = e_primary_uint8_t;
		fields_types[36] = e_primary_uint8_t;
		fields_types[37] = e_primary_uint8_t;
		fields_types[38] = e_primary_uint8_t;
		fields_types[39] = e_primary_uint8_t;
		fields_types[40] = e_primary_uint8_t;
		fields_types[41] = e_primary_uint8_t;
		fields_types[42] = e_primary_uint8_t;
		fields_types[43] = e_primary_uint8_t;
		fields_types[44] = e_primary_uint8_t;
		fields_types[45] = e_primary_uint8_t;
		fields_types[46] = e_primary_uint8_t;
		fields_types[47] = e_primary_uint8_t;
		fields_types[48] = e_primary_uint8_t;
		fields_types[49] = e_primary_uint8_t;
		fields_types[50] = e_primary_uint8_t;
		fields_types[51] = e_primary_uint8_t;
		fields_types[52] = e_primary_uint8_t;
		fields_types[53] = e_primary_uint8_t;
		return 54;
	case 1032:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_primary_uint8_t;
		fields_types[1] = e_primary_float;
		fields_types[2] = e_primary_hv_set_balancing_status_steering_wheel_set_balancing_status;
		fields_types[3] = e_primary_uint8_t;
		return 4;
	case 1040:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_primary_uint8_t;
		fields_types[1] = e_primary_float;
		fields_types[2] = e_primary_hv_set_balancing_status_handcart_set_balancing_status;
		fields_types[3] = e_primary_uint8_t;
		return 4;
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
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_primary_float;
		fields_types[1] = e_primary_ecu_power_maps_sc_state;
		fields_types[2] = e_primary_ecu_power_maps_tv_state;
		fields_types[3] = e_primary_ecu_power_maps_reg_state;
		return 4;
	case 96:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_primary_float;
		fields_types[1] = e_primary_ecu_set_power_maps_sc_state;
		fields_types[2] = e_primary_ecu_set_power_maps_tv_state;
		fields_types[3] = e_primary_ecu_set_power_maps_reg_state;
		return 4;
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
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_primary_float;
		fields_types[1] = e_primary_control_status_sc_state;
		fields_types[2] = e_primary_control_status_tv_state;
		fields_types[3] = e_primary_control_status_reg_state;
		return 4;
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
		if(fields_types_size < 5) return 0;
		fields_types[0] = e_primary_hv_cells_voltage_cellboard_id;
		fields_types[1] = e_primary_uint8_t;
		fields_types[2] = e_primary_float;
		fields_types[3] = e_primary_float;
		fields_types[4] = e_primary_float;
		return 5;
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
		if(fields_types_size < 3) return 0;
		fields_types[0] = e_primary_as_commands_status_steerstatus;
		fields_types[1] = e_primary_as_commands_status_throttlestatus;
		fields_types[2] = e_primary_as_commands_status_brakestatus;
		return 3;
	case 1104:
		if(fields_types_size < 3) return 0;
		fields_types[0] = e_primary_as_commands_set_status_steerstatus;
		fields_types[1] = e_primary_as_commands_set_status_throttlestatus;
		fields_types[2] = e_primary_as_commands_set_status_brakestatus;
		return 3;
	case 1760:
		if(fields_types_size < 3) return 0;
		fields_types[0] = e_primary_float;
		fields_types[1] = e_primary_float;
		fields_types[2] = e_primary_float;
		return 3;
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
	case 50:
		if(fields_types_size < 2) return 0;
		fields_types[0] = e_primary_uint8_t;
		fields_types[1] = e_primary_hv_flash_request_cellboard_id;
		return 2;
	case 51:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_uint8_t;
		return 1;
	case 1112:
		if(fields_types_size < 3) return 0;
		fields_types[0] = e_primary_float;
		fields_types[1] = e_primary_float;
		fields_types[2] = e_primary_float;
		return 3;
	case 1832:
		if(fields_types_size < 5) return 0;
		fields_types[0] = e_primary_hv_cells_temperature_cellboard_id;
		fields_types[1] = e_primary_uint8_t;
		fields_types[2] = e_primary_uint8_t;
		fields_types[3] = e_primary_float;
		fields_types[4] = e_primary_float;
		return 5;
	case 1840:
		if(fields_types_size < 6) return 0;
		fields_types[0] = e_primary_hv_discharge_temperature_cellboard_id;
		fields_types[1] = e_primary_float;
		fields_types[2] = e_primary_float;
		fields_types[3] = e_primary_float;
		fields_types[4] = e_primary_float;
		fields_types[5] = e_primary_float;
		return 6;
	case 1848:
		if(fields_types_size < 7) return 0;
		fields_types[0] = e_primary_float;
		fields_types[1] = e_primary_float;
		fields_types[2] = e_primary_float;
		fields_types[3] = e_primary_float;
		fields_types[4] = e_primary_float;
		fields_types[5] = e_primary_float;
		fields_types[6] = e_primary_float;
		return 7;
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
	case 696:
		if(fields_types_size < 17) return 0;
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
		return 17;
	case 712:
		if(fields_types_size < 7) return 0;
		fields_types[0] = e_primary_float;
		fields_types[1] = e_primary_float;
		fields_types[2] = e_primary_float;
		fields_types[3] = e_primary_float;
		fields_types[4] = e_primary_float;
		fields_types[5] = e_primary_float;
		fields_types[6] = e_primary_float;
		return 7;
	case 720:
		if(fields_types_size < 3) return 0;
		fields_types[0] = e_primary_float;
		fields_types[1] = e_primary_float;
		fields_types[2] = e_primary_float;
		return 3;
	case 728:
		if(fields_types_size < 5) return 0;
		fields_types[0] = e_primary_hv_feedback_enzomma_feedback;
		fields_types[1] = e_primary_hv_feedback_enzomma_status;
		fields_types[2] = e_primary_uint8_t;
		fields_types[3] = e_primary_uint8_t;
		fields_types[4] = e_primary_float;
		return 5;
	case 736:
		if(fields_types_size < 5) return 0;
		fields_types[0] = e_primary_hv_error_group;
		fields_types[1] = e_primary_uint16_t;
		fields_types[2] = e_primary_hv_error_cellboard_id;
		fields_types[3] = e_primary_hv_error_cellboard_group;
		fields_types[4] = e_primary_uint16_t;
		return 5;

    }
    return 0;
}
int primary_enum_fields_from_name(const char *msg_name, const char *sgn_name, char **v)
{
	if(!strcmp(msg_name, "IVT_MSG_RESULT_WH"))
	{
		if(!strcmp(sgn_name, "ivt_id_result_wh"))
		{
			sprintf(v[0], "Vt_Result_Wh");
			return 1;
		}
	}
	if(!strcmp(msg_name, "IVT_MSG_RESULT_AS"))
	{
		if(!strcmp(sgn_name, "ivt_id_result_as"))
		{
			sprintf(v[0], "Vt_Result_As");
			return 1;
		}
	}
	if(!strcmp(msg_name, "IVT_MSG_RESULT_W"))
	{
		if(!strcmp(sgn_name, "ivt_id_result_w"))
		{
			sprintf(v[0], "Vt_Result_W");
			return 1;
		}
	}
	if(!strcmp(msg_name, "IVT_MSG_RESPONSE"))
	{
		if(!strcmp(sgn_name, "ivt_id_response"))
		{
			sprintf(v[0], "Resp_Cmd_Wrong_Command");
			sprintf(v[1], "Resp_Get_Set_ALIVE");
			sprintf(v[2], "Resp_Get_Set_ArtNr");
			sprintf(v[3], "Resp_Get_Set_Serialnumber");
			sprintf(v[4], "Resp_Get_Set_SW_VERSION");
			sprintf(v[5], "Resp_Get_Set_DEVICE_ID");
			sprintf(v[6], "Resp_Get_Set_THRESHOLD_NEG");
			sprintf(v[7], "Resp_Get_Set_THRESHOLD_POS");
			sprintf(v[8], "Resp_Get_Set_MODE");
			sprintf(v[9], "Resp_Get_Set_OC_TEST_TIME");
			sprintf(v[10], "Resp_Get_Set_STORE");
			sprintf(v[11], "Resp_Get_Set_TRIGGER");
			sprintf(v[12], "Resp_Get_Set_Reset_Error_Logdata");
			sprintf(v[13], "Resp_Config_Result_Wh");
			sprintf(v[14], "Resp_Config_Result_As");
			sprintf(v[15], "Resp_Config_Result_W");
			sprintf(v[16], "Resp_Config_Result_T");
			sprintf(v[17], "Resp_Config_Result_U3");
			sprintf(v[18], "Resp_Config_Result_U2");
			sprintf(v[19], "Resp_Config_Result_U1");
			sprintf(v[20], "Resp_Config_Result_I");
			sprintf(v[21], "Resp_CAN_ID_Response");
			sprintf(v[22], "Resp_CAN_ID_Command");
			sprintf(v[23], "Resp_CAN_ID_Res_Wh");
			sprintf(v[24], "Resp_CAN_ID_Res_As");
			sprintf(v[25], "Resp_CAN_ID_Res_W");
			sprintf(v[26], "Resp_CAN_ID_Res_I");
			sprintf(v[27], "Resp_CAN_ID_Res_T");
			sprintf(v[28], "Resp_CAN_ID_Res_U3");
			sprintf(v[29], "Resp_CAN_ID_Res_U2");
			sprintf(v[30], "Resp_CAN_ID_Res_U1");
			sprintf(v[31], "Resp_Error_Log_Logdata_Since_Res");
			sprintf(v[32], "Resp_Error_Log_Overall_Logdata");
			sprintf(v[33], "Resp_Error_Log_System_Error");
			sprintf(v[34], "Resp_Error_Log_Measurement_Error");
			return 35;
		}
		if(!strcmp(sgn_name, "_80_resp_measerror_item"))
		{
			sprintf(v[0], "Resp_error_calibration_data");
			sprintf(v[1], "Resp_error_ntc_I_OpenCirc");
			sprintf(v[2], "Resp_error_ntc_h_OpenCirc");
			sprintf(v[3], "Resp_error_meas_U3_OpenCirc");
			sprintf(v[4], "Resp_error_meas_U2_OpenCirc");
			sprintf(v[5], "Resp_error_meas_U1_OpenCirc");
			sprintf(v[6], "Resp_error_meas_I1_OpenCirc");
			sprintf(v[7], "Resp__error_therm_EMF_correction");
			sprintf(v[8], "Resp_error_cur_meas_implausible");
			sprintf(v[9], "Resp_error_Vref");
			sprintf(v[10], "Resp_error_Underflow_ADC_ch_2");
			sprintf(v[11], "Resp_error_Overflow_ADC_ch_2");
			sprintf(v[12], "Resp_error_Underflow_ADC_ch_1");
			sprintf(v[13], "Reso_error_Overflow_ADC_ch_1");
			sprintf(v[14], "Resp_error_ADC_interrupt");
			sprintf(v[15], "Resonse_all_meas_errors");
			return 16;
		}
		if(!strcmp(sgn_name, "_81_resp_systemerror_item"))
		{
			sprintf(v[0], "Resp_error_Reset_EMC");
			sprintf(v[1], "Resp_error_Reset_Watchdog");
			sprintf(v[2], "Resp_error_Reset_illegal_opcode");
			sprintf(v[3], "Resp_error_ADC_Clock");
			sprintf(v[4], "Resp_error_eeprom_rw");
			sprintf(v[5], "Resp_error_Overcurrent_detection");
			sprintf(v[6], "Resp_error_Configuration");
			sprintf(v[7], "Resp_error_System_Init");
			sprintf(v[8], "Resp_error_System_Clock");
			sprintf(v[9], "Resp_error_Power_failure");
			sprintf(v[10], "Resp_error_Undertemp");
			sprintf(v[11], "Resp_error_Overtemp");
			sprintf(v[12], "Resp_error_CAN_bus_transmit_Data");
			sprintf(v[13], "Resp_error_CAN_bus_receive_Data");
			sprintf(v[14], "Resp_error_Parameter_CRC");
			sprintf(v[15], "Resp_error_code_CRC");
			sprintf(v[16], "Resonse_all_SystemErrors");
			return 17;
		}
		if(!strcmp(sgn_name, "_82_resp_alllogdata_item"))
		{
			sprintf(v[0], "Resp_temp_minimum");
			sprintf(v[1], "Resp_temp_maxmimum");
			sprintf(v[2], "Resp_U3_minimum");
			sprintf(v[3], "Resp_U3_maximum");
			sprintf(v[4], "Resp_U2_minimum");
			sprintf(v[5], "Resp_U2_maxmimum");
			sprintf(v[6], "Resp_U1_minimum");
			sprintf(v[7], "Resp_U1_maximum");
			sprintf(v[8], "Resp_current_minimum");
			sprintf(v[9], "Resp_current_maximum");
			sprintf(v[10], "Resp_oc_negative_activated");
			sprintf(v[11], "Resp_oc_positive_activated");
			sprintf(v[12], "Resp_run_temp_out_spec_limits");
			sprintf(v[13], "Resp_run_temp_in_spec_limits");
			sprintf(v[14], "Resp_run_volt_3_out_spec_limits");
			sprintf(v[15], "Resp_run_volt_3_in_spec_limits");
			sprintf(v[16], "Resp_run_volt_2_out_spec_limits");
			sprintf(v[17], "Resp_run_volt_2_in_spec_limits");
			sprintf(v[18], "Resp_run_volt_1_out_spec_limits");
			sprintf(v[19], "Resp_run_volt_1_in_spec_limits");
			sprintf(v[20], "Resp_run_cur_out_spec_limits");
			sprintf(v[21], "Resp_run_cur_in_spec_limits");
			sprintf(v[22], "Resp_run_overall");
			sprintf(v[23], "Resp_energy_counter_discharging");
			sprintf(v[24], "Resp_energy_counter_charging");
			sprintf(v[25], "Resp_energy_counter_overall");
			sprintf(v[26], "Resp_Ah_counter_discharging");
			sprintf(v[27], "Resp_Ah_counter_charging");
			sprintf(v[28], "Resp_Ah_counter_overall");
			sprintf(v[29], "Response_on_Overall_Logdata");
			return 30;
		}
		if(!strcmp(sgn_name, "_83_resp_logdata_item"))
		{
			sprintf(v[0], "Resp_temp_minimum");
			sprintf(v[1], "Resp_temp_maxmimum");
			sprintf(v[2], "Resp_U3_minimum");
			sprintf(v[3], "Resp_U3_maximum");
			sprintf(v[4], "Resp_U2_minimum");
			sprintf(v[5], "Resp_U2_maxmimum");
			sprintf(v[6], "Resp_U1_minimum");
			sprintf(v[7], "Resp_U1_maximum");
			sprintf(v[8], "Resp_current_minimum");
			sprintf(v[9], "Resp_current_maximum");
			sprintf(v[10], "Resp_oc_negative_activated");
			sprintf(v[11], "Resp_oc_positive_activated");
			sprintf(v[12], "Resp_run_temp_out_spec_limits");
			sprintf(v[13], "Resp_run_temp_in_spec_limits");
			sprintf(v[14], "Resp_run_volt_3_out_spec_limits");
			sprintf(v[15], "Resp_run_volt_3_in_spec_limits");
			sprintf(v[16], "Resp_run_volt_2_out_spec_limits");
			sprintf(v[17], "Resp_run_volt_2_in_spec_limits");
			sprintf(v[18], "Resp_run_volt_1_out_spec_limits");
			sprintf(v[19], "Resp_run_volt_1_in_spec_limits");
			sprintf(v[20], "Resp_run_cur_out_spec_limits");
			sprintf(v[21], "Resp_run_cur_in_spec_limits");
			sprintf(v[22], "Resp_run_overall");
			sprintf(v[23], "Resp_energy_counter_discharging");
			sprintf(v[24], "Resp_energy_counter_charging");
			sprintf(v[25], "Resp_energy_counter_overall");
			sprintf(v[26], "Resp_Ah_counter_discharging");
			sprintf(v[27], "Resp_Ah_counter_charging");
			sprintf(v[28], "Resp_Ah_counter_overall");
			sprintf(v[29], "Response_all_Logdata_SinceReset");
			return 30;
		}
		if(!strcmp(sgn_name, "_b0_resp_reset_item"))
		{
			sprintf(v[0], "Reset_temp_minimum");
			sprintf(v[1], "Reset_temp_maximum");
			sprintf(v[2], "Reset_U3_minimum");
			sprintf(v[3], "Reset_U3_maximum");
			sprintf(v[4], "Reset_U2_minimum");
			sprintf(v[5], "Reset_U2_maximum");
			sprintf(v[6], "Reset_U1_minimum");
			sprintf(v[7], "Reset_U1_maximum");
			sprintf(v[8], "Reset_Current_minimum");
			sprintf(v[9], "Reset_Current_maximum");
			sprintf(v[10], "Reset_Run_overcur_neg_activated");
			sprintf(v[11], "Reset_Run_overcur_pos_activated");
			sprintf(v[12], "Reset_Run_temp_out_spec_limits");
			sprintf(v[13], "Reset_Run_temp_in_spec_limits");
			sprintf(v[14], "Reset_Run_volt_3_out_spec_limits");
			sprintf(v[15], "Reset_Run_volt_3_in_spec_limits");
			sprintf(v[16], "Reset_Run_volt_2_out_spec_limits");
			sprintf(v[17], "Reset_Run_volt_2_in_spec_limits");
			sprintf(v[18], "Reset_Run_volt_1_out_spec_limits");
			sprintf(v[19], "Reset_Run_volt_1_in_spec_limits");
			sprintf(v[20], "Reset_Run_cur_out_spec_limits");
			sprintf(v[21], "Reset_Run_cur_in_spec_limits");
			sprintf(v[22], "Reset_Runtime_overall");
			sprintf(v[23], "Reset_Energy_counter_discharging");
			sprintf(v[24], "Reset_Energy_counter_charging");
			sprintf(v[25], "Reset_Energy_counter_overall");
			sprintf(v[26], "Reset_Ah_counter_discharging");
			sprintf(v[27], "Reset_Ah_counter_charging");
			sprintf(v[28], "Reset_Ah_counter_overall");
			sprintf(v[29], "Reset_all_Logdata_Since_Reset");
			sprintf(v[30], "Reset_Reset_EMC");
			sprintf(v[31], "Reset_Reset_Watchdog");
			sprintf(v[32], "Reset_illegal_opcode");
			sprintf(v[33], "Reset_ADC_Clock");
			sprintf(v[34], "Reset_eeprom_rw");
			sprintf(v[35], "Reset_overcurrent_detection");
			sprintf(v[36], "Reset_configuration");
			sprintf(v[37], "Reset_system_init");
			sprintf(v[38], "Reset_system_clock");
			sprintf(v[39], "Reset_power_failure");
			sprintf(v[40], "Reset_undertemp");
			sprintf(v[41], "Reset_overtemp");
			sprintf(v[42], "Reset_CAN_bus_transmit_Data");
			sprintf(v[43], "Reset_CAN_bus_receive_Data");
			sprintf(v[44], "Reset_Parameter_CRC");
			sprintf(v[45], "Reset_Code_CRC");
			sprintf(v[46], "Reset_all_System_errors");
			sprintf(v[47], "Reset_calibration_data_");
			sprintf(v[48], "Reset_ntc_I_OpenCircuit");
			sprintf(v[49], "Reset_ntc_h_OpenCircuit");
			sprintf(v[50], "Reset_voltage_measU3_OpenCircuit");
			sprintf(v[51], "Reset_voltage_measU2_OpenCircuit");
			sprintf(v[52], "Reset_voltage_measU1_OpenCircuit");
			sprintf(v[53], "Reset_current_measI1_OpenCircuit");
			sprintf(v[54], "Reset_thermal_EMF_correction");
			sprintf(v[55], "Reset_error_current_implausible");
			sprintf(v[56], "Reset_error_Vref");
			sprintf(v[57], "Reset_error_Underflow_ADC_ch2");
			sprintf(v[58], "Reset_error_Overflow_ADC_ch2");
			sprintf(v[59], "Reset_error_Underflow_ADC_ch1");
			sprintf(v[60], "Reset_error_Overflow_ADC_ch1");
			sprintf(v[61], "Reset_error_ADC_interrupt");
			sprintf(v[62], "Reset_all_measurement_errors");
			return 63;
		}
		if(!strcmp(sgn_name, "_b9_resp_device_type"))
		{
			sprintf(v[0], "IVT_S");
			sprintf(v[1], "IVT_Mod");
			return 2;
		}
		if(!strcmp(sgn_name, "_a0_resp_triggermode_i"))
		{
			sprintf(v[0], "CYCLIC");
			sprintf(v[1], "TRIGGERED");
			sprintf(v[2], "DISABLED");
			return 3;
		}
		if(!strcmp(sgn_name, "_a1_resp_triggermode_u1"))
		{
			sprintf(v[0], "CYCLIC");
			sprintf(v[1], "TRIGGERED");
			sprintf(v[2], "DISABLED");
			return 3;
		}
		if(!strcmp(sgn_name, "_a2_resp_triggermode_u2"))
		{
			sprintf(v[0], "CYCLIC");
			sprintf(v[1], "TRIGGERED");
			sprintf(v[2], "DISABLED");
			return 3;
		}
		if(!strcmp(sgn_name, "_a3_resp_triggermode_u3"))
		{
			sprintf(v[0], "CYCLIC");
			sprintf(v[1], "TRIGGERED");
			sprintf(v[2], "DISABLED");
			return 3;
		}
		if(!strcmp(sgn_name, "_a4_resp_triggermode_t"))
		{
			sprintf(v[0], "CYCLIC");
			sprintf(v[1], "TRIGGERED");
			sprintf(v[2], "DISABLED");
			return 3;
		}
		if(!strcmp(sgn_name, "_a5_resp_triggermode_w"))
		{
			sprintf(v[0], "CYCLIC");
			sprintf(v[1], "TRIGGERED");
			sprintf(v[2], "DISABLED");
			return 3;
		}
		if(!strcmp(sgn_name, "_a6_resp_triggermode_as"))
		{
			sprintf(v[0], "CYCLIC");
			sprintf(v[1], "TRIGGERED");
			sprintf(v[2], "DISABLED");
			return 3;
		}
		if(!strcmp(sgn_name, "_a7_resp_triggermode_wh"))
		{
			sprintf(v[0], "CYCLIC");
			sprintf(v[1], "TRIGGERED");
			sprintf(v[2], "DISABLED");
			return 3;
		}
		if(!strcmp(sgn_name, "_b4_resp_actual_mode"))
		{
			sprintf(v[0], "RUN");
			sprintf(v[1], "STOP");
			return 2;
		}
		if(!strcmp(sgn_name, "_b9_resp_device_current"))
		{
			sprintf(v[0], "2500_A");
			sprintf(v[1], "1000_A");
			sprintf(v[2], "500_A");
			sprintf(v[3], "300_A");
			sprintf(v[4], "100_A");
			return 5;
		}
		if(!strcmp(sgn_name, "_b4_resp_startup_mode"))
		{
			sprintf(v[0], "Run");
			sprintf(v[1], "Stop");
			return 2;
		}
		if(!strcmp(sgn_name, "_b9_resp_device_voltage_chan"))
		{
			sprintf(v[0], "3_Channels");
			sprintf(v[1], "0_Channels");
			return 2;
		}
		if(!strcmp(sgn_name, "_b9_resp_device_toi"))
		{
			sprintf(v[0], "I");
			return 1;
		}
		if(!strcmp(sgn_name, "_b9_resp_device_com"))
		{
			sprintf(v[0], "CAN_2___not_terminated");
			sprintf(v[1], "CAN_1___terminated");
			sprintf(v[2], "none");
			return 3;
		}
		if(!strcmp(sgn_name, "_b9_resp_device_v_supply"))
		{
			sprintf(v[0], "12__24_V_nominal_supply_voltage");
			return 1;
		}
	}
	if(!strcmp(msg_name, "IVT_MSG_RESULT_T"))
	{
		if(!strcmp(sgn_name, "ivt_id_result_t"))
		{
			sprintf(v[0], "Vt_Result_T");
			return 1;
		}
	}
	if(!strcmp(msg_name, "IVT_MSG_RESULT_U3"))
	{
		if(!strcmp(sgn_name, "ivt_id_result_u3"))
		{
			sprintf(v[0], "Vt_Result_U3");
			return 1;
		}
	}
	if(!strcmp(msg_name, "IVT_MSG_RESULT_U2"))
	{
		if(!strcmp(sgn_name, "ivt_id_result_u2"))
		{
			sprintf(v[0], "Vt_Result_U2");
			return 1;
		}
	}
	if(!strcmp(msg_name, "IVT_MSG_RESULT_U1"))
	{
		if(!strcmp(sgn_name, "ivt_id_result_u1"))
		{
			sprintf(v[0], "Vt_Result_U1");
			return 1;
		}
	}
	if(!strcmp(msg_name, "IVT_MSG_RESULT_I"))
	{
		if(!strcmp(sgn_name, "ivt_id_result_i"))
		{
			sprintf(v[0], "Vt_Result_I");
			return 1;
		}
	}
	if(!strcmp(msg_name, "IVT_MSG_CMD"))
	{
		if(!strcmp(sgn_name, "ivt_id_cmd"))
		{
			sprintf(v[0], "Get_cmd_and_info_ArtNr");
			sprintf(v[1], "Get_cmd_and_info_SN");
			sprintf(v[2], "Get_cmd_and_info_SW_Version");
			sprintf(v[3], "Get_cmd_and_info_DEVICE_ID");
			sprintf(v[4], "Get_cmd_and_info_THRESHOLD_NEG");
			sprintf(v[5], "Get_cmd_and_info_THRESHOLD_POS");
			sprintf(v[6], "Get_cmd_and_info_MODE");
			sprintf(v[7], "Get_cmd_and_info_OC_TEST_TIME");
			sprintf(v[8], "Get_Config_Res_Wh");
			sprintf(v[9], "Get_Config_Res_As");
			sprintf(v[10], "Get_Config_Res_W");
			sprintf(v[11], "Get_Config_Res_T");
			sprintf(v[12], "Get_Config_Res_U3");
			sprintf(v[13], "Get_Config_Res_U2");
			sprintf(v[14], "Get_Config_Res_U1");
			sprintf(v[15], "Get_Config_Res_I");
			sprintf(v[16], "Get_CAN_ID_Response");
			sprintf(v[17], "Get_CAN_ID_Command");
			sprintf(v[18], "Get_CAN_ID_Res_Wh");
			sprintf(v[19], "Get_CAN_ID_Res_As");
			sprintf(v[20], "Get_CAN_ID_Res_W");
			sprintf(v[21], "Get_CAN_ID_Res_T");
			sprintf(v[22], "Get_CAN_ID_Res_U3");
			sprintf(v[23], "Get_CAN_ID_Res_U2");
			sprintf(v[24], "Get_CAN_ID_Res_U1");
			sprintf(v[25], "Get_CAN_ID_Res_I");
			sprintf(v[26], "Get_Logdata_Since_Reset");
			sprintf(v[27], "Get_Overall_Logdata");
			sprintf(v[28], "Get_System_Errors");
			sprintf(v[29], "Get_Measurement_Errors");
			sprintf(v[30], "Set_RESTART");
			sprintf(v[31], "Set_RESTART_to_default");
			sprintf(v[32], "RESTART_to_Bitrate");
			sprintf(v[33], "Set_THRESHOLD_neg");
			sprintf(v[34], "Set_THRESHOLD_pos");
			sprintf(v[35], "Set_MODE_Result_I");
			sprintf(v[36], "Set_CAN_ID_Result_I");
			sprintf(v[37], "Set_MODE");
			sprintf(v[38], "START_OC_TEST");
			sprintf(v[39], "STORE");
			sprintf(v[40], "TRIGGER");
			sprintf(v[41], "Reset_Err_Log");
			sprintf(v[42], "Set_MODE_Result_Wh");
			sprintf(v[43], "Set_MODE_Result_As");
			sprintf(v[44], "Set_MODE_Result_W");
			sprintf(v[45], "Set_CAN_ID_Result_Wh");
			sprintf(v[46], "Set_CAN_ID_Result_As");
			sprintf(v[47], "Set_CAN_ID_Result_W");
			sprintf(v[48], "Set_CAN_ID_Result_T");
			sprintf(v[49], "Set_MODE_Result_U3");
			sprintf(v[50], "Set_CAN_ID_Response");
			sprintf(v[51], "Set_CAN_ID_Cmd");
			sprintf(v[52], "Set_CAN_ID_Result_U3");
			sprintf(v[53], "Set_CAN_ID_Result_U2");
			sprintf(v[54], "Set_MODE_Result_T");
			sprintf(v[55], "Set_MODE_Result_U2");
			sprintf(v[56], "Set_MODE_Result_U1");
			sprintf(v[57], "Set_CAN_ID_Result_U1");
			return 58;
		}
		if(!strcmp(sgn_name, "_30_reset_item"))
		{
			sprintf(v[0], "Reset_temp_minimum");
			sprintf(v[1], "Reset_temp_maximum");
			sprintf(v[2], "Reset_U3_minimum");
			sprintf(v[3], "Reset_U3_maximum");
			sprintf(v[4], "Reset_U2_minimum");
			sprintf(v[5], "Reset_U2_maximum");
			sprintf(v[6], "Reset_U1_minimum");
			sprintf(v[7], "Reset_U1_maximum");
			sprintf(v[8], "Reset_Current_minimum");
			sprintf(v[9], "Reset_Current_maximum");
			sprintf(v[10], "Reset_Run_overcur_neg_activated");
			sprintf(v[11], "Reset_Run_overcur_pos_activated");
			sprintf(v[12], "Reset_Run_temp_out_spec_limits");
			sprintf(v[13], "Reset_Run_temp_in_spec_limits");
			sprintf(v[14], "Reset_Run_volt_3_out_spec_limits");
			sprintf(v[15], "Reset_Run_volt_3_in_spec_limits");
			sprintf(v[16], "Reset_Run_volt_2_out_spec_limits");
			sprintf(v[17], "Reset_Run_volt_2_in_spec_limits");
			sprintf(v[18], "Reset_Run_volt_1_out_spec_limits");
			sprintf(v[19], "Reset_Run_volt_1_in_spec_limits");
			sprintf(v[20], "Reset_Run_cur_out_spec_limits");
			sprintf(v[21], "Reset_Run_cur_in_spec_limits");
			sprintf(v[22], "Reset_Runtime_overall");
			sprintf(v[23], "Reset_Energy_counter_discharging");
			sprintf(v[24], "Reset_Energy_counter_charging");
			sprintf(v[25], "Reset_Energy_counter_overall");
			sprintf(v[26], "Reset_Ah_counter_discharging");
			sprintf(v[27], "Reset_Ah_counter_charging");
			sprintf(v[28], "Reset_Ah_counter_overall");
			sprintf(v[29], "Reset_all_Logdata_Since_Reset");
			sprintf(v[30], "Reset_Reset_EMC");
			sprintf(v[31], "Reset_Reset_Watchdog");
			sprintf(v[32], "Reset_illegal_opcode");
			sprintf(v[33], "Reset_ADC_Clock");
			sprintf(v[34], "Reset_eeprom_rw");
			sprintf(v[35], "Reset_overcurrent_detection");
			sprintf(v[36], "Reset_configuration");
			sprintf(v[37], "Reset_system_init");
			sprintf(v[38], "Reset_system_clock");
			sprintf(v[39], "Reset_power_failure");
			sprintf(v[40], "Reset_undertemp");
			sprintf(v[41], "Reset_overtemp");
			sprintf(v[42], "Reset_CAN_bus_transmit_Data");
			sprintf(v[43], "Reset_CAN_bus_receive_Data");
			sprintf(v[44], "Reset_Parameter_CRC");
			sprintf(v[45], "Reset_Code_CRC");
			sprintf(v[46], "Reset_all_System_errors");
			sprintf(v[47], "Reset_calibration_data_");
			sprintf(v[48], "Reset_ntc_I_OpenCircuit");
			sprintf(v[49], "Reset_ntc_h_OpenCircuit");
			sprintf(v[50], "Reset_voltage_measU3_OpenCircuit");
			sprintf(v[51], "Reset_voltage_measU2_OpenCircuit");
			sprintf(v[52], "Reset_voltage_measU1_OpenCircuit");
			sprintf(v[53], "Reset_current_measI1_OpenCircuit");
			sprintf(v[54], "Reset_thermal_EMF_correction");
			sprintf(v[55], "Reset_error_current_implausible");
			sprintf(v[56], "Reset_error_Vref");
			sprintf(v[57], "Reset_error_Underflow_ADC_ch2");
			sprintf(v[58], "Reset_error_Overflow_ADC_ch2");
			sprintf(v[59], "Reset_error_Underflow_ADC_ch1");
			sprintf(v[60], "Reset_error_Overflow_ADC_ch1");
			sprintf(v[61], "Reset_error_ADC_interrupt");
			sprintf(v[62], "Reset_all_measurement_errors");
			return 63;
		}
		if(!strcmp(sgn_name, "_3a_restart_to_bitrate"))
		{
			sprintf(v[0], "250k");
			sprintf(v[1], "500k");
			sprintf(v[2], "1000k");
			return 3;
		}
		if(!strcmp(sgn_name, "_40_get_measerror_item"))
		{
			sprintf(v[0], "Get_error_calibration_data");
			sprintf(v[1], "Get_error_ntc_I_OpenCirc");
			sprintf(v[2], "Get_error_ntc_h_OpenCirc");
			sprintf(v[3], "Get_error_volt_meas_U3_OpenCirc");
			sprintf(v[4], "Get_error_volt_meas_U2_OpenCirc");
			sprintf(v[5], "Get_error_volt_meas_U1_OpenCirc");
			sprintf(v[6], "Get_error_cur_meas_I1_OpenCirc");
			sprintf(v[7], "Get_error_thermal_EMF_correction");
			sprintf(v[8], "Get_error_cur_meas_implausible");
			sprintf(v[9], "Get_error_Vref");
			sprintf(v[10], "Get_error_Underflow_ADC_ch_2");
			sprintf(v[11], "Get_error_Overflow_ADC_ch_2");
			sprintf(v[12], "Get_error_Underflow_ADC_ch_1");
			sprintf(v[13], "Get_error_Overflow_ADC_ch_1");
			sprintf(v[14], "Get_error_ADC_interrupt");
			sprintf(v[15], "Get_all_meas_Errors");
			return 16;
		}
		if(!strcmp(sgn_name, "_41_get_systemerror_item"))
		{
			sprintf(v[0], "Get_error_reset_EMC");
			sprintf(v[1], "Get_error_reset_Watchdog");
			sprintf(v[2], "Get_error_reset_illegal_opcode");
			sprintf(v[3], "Get_error_ADC_clock");
			sprintf(v[4], "Get_error_eeprom_rw");
			sprintf(v[5], "Get_error_overcurrent_detection");
			sprintf(v[6], "Get_error_configuration");
			sprintf(v[7], "Get_error_system_init");
			sprintf(v[8], "Get_error_system_clock");
			sprintf(v[9], "Get_error_power_failure");
			sprintf(v[10], "Get_error_undertemp");
			sprintf(v[11], "Get_error_overtemp");
			sprintf(v[12], "Get_error_CAN_bus_transmit_Data");
			sprintf(v[13], "Get_error_CAN__bus_receive_Data");
			sprintf(v[14], "Get_error_Code_Parameter_CRC");
			sprintf(v[15], "Get_error_Code_CRC");
			sprintf(v[16], "Get_all_System_errors");
			return 17;
		}
		if(!strcmp(sgn_name, "_42_get_alllogdata_item"))
		{
			sprintf(v[0], "Get_Temperature_minimum");
			sprintf(v[1], "Get_Temperature_maximum");
			sprintf(v[2], "Get_U3_minimum");
			sprintf(v[3], "Get_U3_maxmimum_");
			sprintf(v[4], "Get_U2_minimum");
			sprintf(v[5], "Get_U2_maximum");
			sprintf(v[6], "Get_U1_minimum");
			sprintf(v[7], "Get_U1_maxmimum");
			sprintf(v[8], "Get_current_minimum");
			sprintf(v[9], "Get_current_maximum");
			sprintf(v[10], "Get_run_overcur_neg_activated");
			sprintf(v[11], "Get_run_overcur_pos_activated");
			sprintf(v[12], "Get_run_temp_out_spec_limits");
			sprintf(v[13], "Get_run_temp_in_spec_limits");
			sprintf(v[14], "Get_run_volt3_out_spec_limits");
			sprintf(v[15], "Get_run_volt3_in_spec_limits");
			sprintf(v[16], "Get_run_volt2_out_spec_limits");
			sprintf(v[17], "Get_run_volt2_in_spec_limits");
			sprintf(v[18], "Get_run_volt1_out_spec_limits");
			sprintf(v[19], "Get_run_volt1_in_spec_limits");
			sprintf(v[20], "Get_run_cur_out_spec_limits");
			sprintf(v[21], "Get_Run_cur_in_spec_limits");
			sprintf(v[22], "Get_Runtime_overall");
			sprintf(v[23], "Get_Energy_counter_discharging");
			sprintf(v[24], "Get_Energy_counter_charging");
			sprintf(v[25], "Get_Energy_counter_overall");
			sprintf(v[26], "Get_Ah_counter_discharging");
			sprintf(v[27], "Get_Ah_counter_charging");
			sprintf(v[28], "Get_Ah_counter_overall");
			sprintf(v[29], "Get_Overall_Logdata");
			return 30;
		}
		if(!strcmp(sgn_name, "_43_get_logdata_item"))
		{
			sprintf(v[0], "Get_Temperature_minimum");
			sprintf(v[1], "Get_Temperature_maximum");
			sprintf(v[2], "Get_U3_minimum");
			sprintf(v[3], "Get_U3_maxmimum_");
			sprintf(v[4], "Get_U2_minimum");
			sprintf(v[5], "Get_U2_maximum");
			sprintf(v[6], "Get_U1_minimum");
			sprintf(v[7], "Get_U1_maxmimum");
			sprintf(v[8], "Get_current_minimum");
			sprintf(v[9], "Get_current_maximum");
			sprintf(v[10], "Get_run_overcur_neg_activated");
			sprintf(v[11], "Get_run_overcur_pos_activated");
			sprintf(v[12], "Get_run_temp_out_spec_limits");
			sprintf(v[13], "Get_run_temp_in_spec_limits");
			sprintf(v[14], "Get_run_volt3_out_spec_limits");
			sprintf(v[15], "Get_run_volt3_in_spec_limits");
			sprintf(v[16], "Get_run_volt2_out_spec_limits");
			sprintf(v[17], "Get_run_volt2_in_spec_limits");
			sprintf(v[18], "Get_run_volt1_out_spec_limits");
			sprintf(v[19], "Get_run_volt1_in_spec_limits");
			sprintf(v[20], "Get_run_cur_out_spec_limits");
			sprintf(v[21], "Get_Run_cur_in_spec_limits");
			sprintf(v[22], "Get_Runtime_overall");
			sprintf(v[23], "Get_Energy_counter_discharging");
			sprintf(v[24], "Get_Energy_counter_charging");
			sprintf(v[25], "Get_Energy_counter_overall");
			sprintf(v[26], "Get_Ah_counter_discharging");
			sprintf(v[27], "Get_Ah_counter_charging");
			sprintf(v[28], "Get_Ah_counter_overall");
			sprintf(v[29], "Get_Overall_Logdata");
			return 30;
		}
		if(!strcmp(sgn_name, "_20_conf_triggermode_i"))
		{
			sprintf(v[0], "CYCLIC");
			sprintf(v[1], "TRIGGERED");
			sprintf(v[2], "DISABLED");
			return 3;
		}
		if(!strcmp(sgn_name, "_21_conf_triggermode_u1"))
		{
			sprintf(v[0], "CYCLIC");
			sprintf(v[1], "TRIGGERED");
			sprintf(v[2], "DISABLED");
			return 3;
		}
		if(!strcmp(sgn_name, "_22_conf_triggermode_u2"))
		{
			sprintf(v[0], "CYCLIC");
			sprintf(v[1], "TRIGGERED");
			sprintf(v[2], "DISABLED");
			return 3;
		}
		if(!strcmp(sgn_name, "_23_conf_triggermode_u3"))
		{
			sprintf(v[0], "CYCLIC");
			sprintf(v[1], "TRIGGERED");
			sprintf(v[2], "DISABLED");
			return 3;
		}
		if(!strcmp(sgn_name, "_24_conf_triggermode_t"))
		{
			sprintf(v[0], "CYCLIC");
			sprintf(v[1], "TRIGGERED");
			sprintf(v[2], "DISABLED");
			return 3;
		}
		if(!strcmp(sgn_name, "_25_conf_triggermode_w"))
		{
			sprintf(v[0], "CYCLIC");
			sprintf(v[1], "TRIGGERED");
			sprintf(v[2], "DISABLED");
			return 3;
		}
		if(!strcmp(sgn_name, "_26_conf_triggermode_as"))
		{
			sprintf(v[0], "CYCLIC");
			sprintf(v[1], "TRIGGERED");
			sprintf(v[2], "DISABLED");
			return 3;
		}
		if(!strcmp(sgn_name, "_27_conf_triggermode_wh"))
		{
			sprintf(v[0], "CYCLIC");
			sprintf(v[1], "TRIGGERED");
			sprintf(v[2], "DISABLED");
			return 3;
		}
		if(!strcmp(sgn_name, "_34_actual_mode"))
		{
			sprintf(v[0], "START");
			sprintf(v[1], "STOP");
			return 2;
		}
		if(!strcmp(sgn_name, "_34_startup_mode"))
		{
			sprintf(v[0], "START");
			sprintf(v[1], "STOP");
			return 2;
		}
	}
	if(!strcmp(msg_name, "HV_FLASH"))
	{
		if(!strcmp(sgn_name, "forward"))
		{
			sprintf(v[0], "off");
			sprintf(v[1], "on");
			return 2;
		}
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
	if(!strcmp(msg_name, "HV_FEEDBACK_STATUS"))
	{
		if(!strcmp(sgn_name, "airn_open_com"))
		{
			sprintf(v[0], "low");
			sprintf(v[1], "error");
			sprintf(v[2], "high");
			return 3;
		}
		if(!strcmp(sgn_name, "precharge_open_com"))
		{
			sprintf(v[0], "low");
			sprintf(v[1], "error");
			sprintf(v[2], "high");
			return 3;
		}
		if(!strcmp(sgn_name, "airp_open_com"))
		{
			sprintf(v[0], "low");
			sprintf(v[1], "error");
			sprintf(v[2], "high");
			return 3;
		}
		if(!strcmp(sgn_name, "airn_open_mec"))
		{
			sprintf(v[0], "low");
			sprintf(v[1], "error");
			sprintf(v[2], "high");
			return 3;
		}
		if(!strcmp(sgn_name, "precharge_open_mec"))
		{
			sprintf(v[0], "low");
			sprintf(v[1], "error");
			sprintf(v[2], "high");
			return 3;
		}
		if(!strcmp(sgn_name, "airp_open_mec"))
		{
			sprintf(v[0], "low");
			sprintf(v[1], "error");
			sprintf(v[2], "high");
			return 3;
		}
		if(!strcmp(sgn_name, "sd_imd_fb"))
		{
			sprintf(v[0], "low");
			sprintf(v[1], "error");
			sprintf(v[2], "high");
			return 3;
		}
		if(!strcmp(sgn_name, "sd_bms_fb"))
		{
			sprintf(v[0], "low");
			sprintf(v[1], "error");
			sprintf(v[2], "high");
			return 3;
		}
		if(!strcmp(sgn_name, "ts_less_than_60v"))
		{
			sprintf(v[0], "low");
			sprintf(v[1], "error");
			sprintf(v[2], "high");
			return 3;
		}
		if(!strcmp(sgn_name, "plausible_state_persisted"))
		{
			sprintf(v[0], "low");
			sprintf(v[1], "error");
			sprintf(v[2], "high");
			return 3;
		}
		if(!strcmp(sgn_name, "plausible_state"))
		{
			sprintf(v[0], "low");
			sprintf(v[1], "error");
			sprintf(v[2], "high");
			return 3;
		}
		if(!strcmp(sgn_name, "not_bms_fault_cockpit_led"))
		{
			sprintf(v[0], "low");
			sprintf(v[1], "error");
			sprintf(v[2], "high");
			return 3;
		}
		if(!strcmp(sgn_name, "not_imd_fault_cockpit_led"))
		{
			sprintf(v[0], "low");
			sprintf(v[1], "error");
			sprintf(v[2], "high");
			return 3;
		}
		if(!strcmp(sgn_name, "indicator_connected"))
		{
			sprintf(v[0], "low");
			sprintf(v[1], "error");
			sprintf(v[2], "high");
			return 3;
		}
		if(!strcmp(sgn_name, "not_latch_reset"))
		{
			sprintf(v[0], "low");
			sprintf(v[1], "error");
			sprintf(v[2], "high");
			return 3;
		}
		if(!strcmp(sgn_name, "plausible_state_latched"))
		{
			sprintf(v[0], "low");
			sprintf(v[1], "error");
			sprintf(v[2], "high");
			return 3;
		}
		if(!strcmp(sgn_name, "not_bms_fault_latched"))
		{
			sprintf(v[0], "low");
			sprintf(v[1], "error");
			sprintf(v[2], "high");
			return 3;
		}
		if(!strcmp(sgn_name, "not_imd_fault_latched"))
		{
			sprintf(v[0], "low");
			sprintf(v[1], "error");
			sprintf(v[2], "high");
			return 3;
		}
		if(!strcmp(sgn_name, "not_ext_fault_latched"))
		{
			sprintf(v[0], "low");
			sprintf(v[1], "error");
			sprintf(v[2], "high");
			return 3;
		}
		if(!strcmp(sgn_name, "imd_ok"))
		{
			sprintf(v[0], "low");
			sprintf(v[1], "error");
			sprintf(v[2], "high");
			return 3;
		}
		if(!strcmp(sgn_name, "plausible_state_rc"))
		{
			sprintf(v[0], "low");
			sprintf(v[1], "error");
			sprintf(v[2], "high");
			return 3;
		}
		if(!strcmp(sgn_name, "tsal_green"))
		{
			sprintf(v[0], "low");
			sprintf(v[1], "error");
			sprintf(v[2], "high");
			return 3;
		}
		if(!strcmp(sgn_name, "probing_3v3"))
		{
			sprintf(v[0], "low");
			sprintf(v[1], "error");
			sprintf(v[2], "high");
			return 3;
		}
		if(!strcmp(sgn_name, "sd_out"))
		{
			sprintf(v[0], "low");
			sprintf(v[1], "error");
			sprintf(v[2], "high");
			return 3;
		}
		if(!strcmp(sgn_name, "sd_in"))
		{
			sprintf(v[0], "low");
			sprintf(v[1], "error");
			sprintf(v[2], "high");
			return 3;
		}
		if(!strcmp(sgn_name, "sd_end"))
		{
			sprintf(v[0], "low");
			sprintf(v[1], "error");
			sprintf(v[2], "high");
			return 3;
		}
		if(!strcmp(sgn_name, "v5_mcu"))
		{
			sprintf(v[0], "low");
			sprintf(v[1], "error");
			sprintf(v[2], "high");
			return 3;
		}
		if(!strcmp(sgn_name, "feedback_tsal_green_fault_latched"))
		{
			sprintf(v[0], "low");
			sprintf(v[1], "error");
			sprintf(v[2], "high");
			return 3;
		}
		if(!strcmp(sgn_name, "feedback_ext_latched"))
		{
			sprintf(v[0], "low");
			sprintf(v[1], "error");
			sprintf(v[2], "high");
			return 3;
		}
		if(!strcmp(sgn_name, "feedback_precharge_status"))
		{
			sprintf(v[0], "low");
			sprintf(v[1], "error");
			sprintf(v[2], "high");
			return 3;
		}
		if(!strcmp(sgn_name, "feedback_tsp_over_60v_status"))
		{
			sprintf(v[0], "low");
			sprintf(v[1], "error");
			sprintf(v[2], "high");
			return 3;
		}
		if(!strcmp(sgn_name, "feedback_check_mux"))
		{
			sprintf(v[0], "low");
			sprintf(v[1], "error");
			sprintf(v[2], "high");
			return 3;
		}
	}
	if(!strcmp(msg_name, "HV_IMD_STATUS"))
	{
		if(!strcmp(sgn_name, "status"))
		{
			sprintf(v[0], "unknown");
			sprintf(v[1], "short_circuit");
			sprintf(v[2], "normal");
			sprintf(v[3], "under_voltage");
			sprintf(v[4], "start_measure");
			sprintf(v[5], "device_error");
			sprintf(v[6], "earth_fault");
			return 7;
		}
		if(!strcmp(sgn_name, "feedback_not_imd_fault_cockpit_led"))
		{
			sprintf(v[0], "low");
			sprintf(v[1], "error");
			sprintf(v[2], "high");
			return 3;
		}
		if(!strcmp(sgn_name, "feedback_not_imd_fault_latched"))
		{
			sprintf(v[0], "low");
			sprintf(v[1], "error");
			sprintf(v[2], "high");
			return 3;
		}
	}
	if(!strcmp(msg_name, "HV_STATUS"))
	{
		if(!strcmp(sgn_name, "status"))
		{
			sprintf(v[0], "init");
			sprintf(v[1], "idle");
			sprintf(v[2], "fatal");
			sprintf(v[3], "flash");
			sprintf(v[4], "balancing");
			sprintf(v[5], "airn_check");
			sprintf(v[6], "precharge_check");
			sprintf(v[7], "airp_check");
			sprintf(v[8], "ts_on");
			return 9;
		}
		if(!strcmp(sgn_name, "cellboard_0"))
		{
			sprintf(v[0], "init");
			sprintf(v[1], "idle");
			sprintf(v[2], "fatal");
			sprintf(v[3], "flash");
			sprintf(v[4], "discharge");
			sprintf(v[5], "cooldown");
			return 6;
		}
		if(!strcmp(sgn_name, "cellboard_1"))
		{
			sprintf(v[0], "init");
			sprintf(v[1], "idle");
			sprintf(v[2], "fatal");
			sprintf(v[3], "flash");
			sprintf(v[4], "discharge");
			sprintf(v[5], "cooldown");
			return 6;
		}
		if(!strcmp(sgn_name, "cellboard_2"))
		{
			sprintf(v[0], "init");
			sprintf(v[1], "idle");
			sprintf(v[2], "fatal");
			sprintf(v[3], "flash");
			sprintf(v[4], "discharge");
			sprintf(v[5], "cooldown");
			return 6;
		}
		if(!strcmp(sgn_name, "cellboard_3"))
		{
			sprintf(v[0], "init");
			sprintf(v[1], "idle");
			sprintf(v[2], "fatal");
			sprintf(v[3], "flash");
			sprintf(v[4], "discharge");
			sprintf(v[5], "cooldown");
			return 6;
		}
		if(!strcmp(sgn_name, "cellboard_4"))
		{
			sprintf(v[0], "init");
			sprintf(v[1], "idle");
			sprintf(v[2], "fatal");
			sprintf(v[3], "flash");
			sprintf(v[4], "discharge");
			sprintf(v[5], "cooldown");
			return 6;
		}
		if(!strcmp(sgn_name, "cellboard_5"))
		{
			sprintf(v[0], "init");
			sprintf(v[1], "idle");
			sprintf(v[2], "fatal");
			sprintf(v[3], "flash");
			sprintf(v[4], "discharge");
			sprintf(v[5], "cooldown");
			return 6;
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
		if(!strcmp(sgn_name, "status"))
		{
			sprintf(v[0], "stopped");
			sprintf(v[1], "paused");
			sprintf(v[2], "running");
			return 3;
		}
	}
	if(!strcmp(msg_name, "HV_SET_BALANCING_STATUS_STEERING_WHEEL"))
	{
		if(!strcmp(sgn_name, "set_balancing_status"))
		{
			sprintf(v[0], "off");
			sprintf(v[1], "on");
			return 2;
		}
	}
	if(!strcmp(msg_name, "HV_SET_BALANCING_STATUS_HANDCART"))
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
	if(!strcmp(msg_name, "LV_CHARGING_STATUS"))
	{
		if(!strcmp(sgn_name, "status"))
		{
			sprintf(v[0], "off");
			sprintf(v[1], "on");
			return 2;
		}
	}
	if(!strcmp(msg_name, "LV_COOLING_AGGRESSIVENESS"))
	{
		if(!strcmp(sgn_name, "status"))
		{
			sprintf(v[0], "weak");
			sprintf(v[1], "normal");
			sprintf(v[2], "aggressive");
			return 3;
		}
	}
	if(!strcmp(msg_name, "LV_SET_COOLING_AGGRESSIVENESS"))
	{
		if(!strcmp(sgn_name, "status"))
		{
			sprintf(v[0], "weak");
			sprintf(v[1], "normal");
			sprintf(v[2], "aggressive");
			return 3;
		}
	}
	if(!strcmp(msg_name, "LV_RADIATOR_SPEED"))
	{
		if(!strcmp(sgn_name, "status"))
		{
			sprintf(v[0], "off");
			sprintf(v[1], "auto");
			sprintf(v[2], "manual");
			return 3;
		}
	}
	if(!strcmp(msg_name, "LV_PUMPS_SPEED"))
	{
		if(!strcmp(sgn_name, "status"))
		{
			sprintf(v[0], "off");
			sprintf(v[1], "auto");
			sprintf(v[2], "manual");
			return 3;
		}
	}
	if(!strcmp(msg_name, "LV_SET_RADIATOR_SPEED"))
	{
		if(!strcmp(sgn_name, "status"))
		{
			sprintf(v[0], "off");
			sprintf(v[1], "auto");
			sprintf(v[2], "manual");
			return 3;
		}
	}
	if(!strcmp(msg_name, "LV_SET_PUMPS_SPEED"))
	{
		if(!strcmp(sgn_name, "status"))
		{
			sprintf(v[0], "off");
			sprintf(v[1], "auto");
			sprintf(v[2], "manual");
			return 3;
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
			sprintf(v[11], "re_enable_inverter_drive");
			sprintf(v[12], "wait_ts_discharge");
			sprintf(v[13], "fatal_error");
			return 14;
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
	if(!strcmp(msg_name, "ECU_POWER_MAPS"))
	{
		if(!strcmp(sgn_name, "sc_state"))
		{
			sprintf(v[0], "off");
			sprintf(v[1], "on");
			return 2;
		}
		if(!strcmp(sgn_name, "tv_state"))
		{
			sprintf(v[0], "off");
			sprintf(v[1], "on");
			return 2;
		}
		if(!strcmp(sgn_name, "reg_state"))
		{
			sprintf(v[0], "off");
			sprintf(v[1], "on");
			return 2;
		}
	}
	if(!strcmp(msg_name, "ECU_SET_POWER_MAPS"))
	{
		if(!strcmp(sgn_name, "sc_state"))
		{
			sprintf(v[0], "off");
			sprintf(v[1], "on");
			return 2;
		}
		if(!strcmp(sgn_name, "tv_state"))
		{
			sprintf(v[0], "off");
			sprintf(v[1], "on");
			return 2;
		}
		if(!strcmp(sgn_name, "reg_state"))
		{
			sprintf(v[0], "off");
			sprintf(v[1], "on");
			return 2;
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
	if(!strcmp(msg_name, "CONTROL_STATUS"))
	{
		if(!strcmp(sgn_name, "sc_state"))
		{
			sprintf(v[0], "off");
			sprintf(v[1], "on");
			return 2;
		}
		if(!strcmp(sgn_name, "tv_state"))
		{
			sprintf(v[0], "off");
			sprintf(v[1], "on");
			return 2;
		}
		if(!strcmp(sgn_name, "reg_state"))
		{
			sprintf(v[0], "off");
			sprintf(v[1], "on");
			return 2;
		}
	}
	if(!strcmp(msg_name, "HV_CELLS_VOLTAGE"))
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
	if(!strcmp(msg_name, "AS_COMMANDS_STATUS"))
	{
		if(!strcmp(sgn_name, "steerstatus"))
		{
			sprintf(v[0], "off");
			sprintf(v[1], "on");
			return 2;
		}
		if(!strcmp(sgn_name, "throttlestatus"))
		{
			sprintf(v[0], "off");
			sprintf(v[1], "on");
			return 2;
		}
		if(!strcmp(sgn_name, "brakestatus"))
		{
			sprintf(v[0], "off");
			sprintf(v[1], "on");
			return 2;
		}
	}
	if(!strcmp(msg_name, "AS_COMMANDS_SET_STATUS"))
	{
		if(!strcmp(sgn_name, "steerstatus"))
		{
			sprintf(v[0], "off");
			sprintf(v[1], "on");
			return 2;
		}
		if(!strcmp(sgn_name, "throttlestatus"))
		{
			sprintf(v[0], "off");
			sprintf(v[1], "on");
			return 2;
		}
		if(!strcmp(sgn_name, "brakestatus"))
		{
			sprintf(v[0], "off");
			sprintf(v[1], "on");
			return 2;
		}
	}
	if(!strcmp(msg_name, "DEBUG_SIGNAL_1"))
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
	if(!strcmp(msg_name, "DEBUG_SIGNAL_2"))
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
	if(!strcmp(msg_name, "DEBUG_SIGNAL_3"))
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
	if(!strcmp(msg_name, "DEBUG_SIGNAL_4"))
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
	if(!strcmp(msg_name, "HV_FLASH_REQUEST"))
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
	if(!strcmp(msg_name, "HV_CELLS_TEMPERATURE"))
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
	if(!strcmp(msg_name, "HV_DISCHARGE_TEMPERATURE"))
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
	if(!strcmp(msg_name, "HV_FEEDBACK_ENZOMMA"))
	{
		if(!strcmp(sgn_name, "feedback"))
		{
			sprintf(v[0], "airn_open_com");
			sprintf(v[1], "precharge_open_com");
			sprintf(v[2], "airp_open_com");
			sprintf(v[3], "airn_open_mec");
			sprintf(v[4], "precharge_open_mec");
			sprintf(v[5], "airp_open_mec");
			sprintf(v[6], "sd_imd_fb");
			sprintf(v[7], "sd_bms_fb");
			sprintf(v[8], "ts_less_than_60v");
			sprintf(v[9], "plausible_state_persisted");
			sprintf(v[10], "plausible_state");
			sprintf(v[11], "not_bms_fault_cockpit_led");
			sprintf(v[12], "not_imd_fault_cockpit_led");
			sprintf(v[13], "indicator_connected");
			sprintf(v[14], "not_latch_reset");
			sprintf(v[15], "plausible_state_latched");
			sprintf(v[16], "not_bms_fault_latched");
			sprintf(v[17], "not_imd_fault_latched");
			sprintf(v[18], "not_ext_fault_latched");
			sprintf(v[19], "imd_ok");
			sprintf(v[20], "plausible_state_rc");
			sprintf(v[21], "tsal_green");
			sprintf(v[22], "probing_3v3");
			sprintf(v[23], "sd_out");
			sprintf(v[24], "sd_in");
			sprintf(v[25], "sd_end");
			sprintf(v[26], "v5_mcu");
			sprintf(v[27], "unknown");
			return 28;
		}
		if(!strcmp(sgn_name, "status"))
		{
			sprintf(v[0], "low");
			sprintf(v[1], "error");
			sprintf(v[2], "high");
			return 3;
		}
	}
	if(!strcmp(msg_name, "HV_ERROR"))
	{
		if(!strcmp(sgn_name, "group"))
		{
			sprintf(v[0], "post");
			sprintf(v[1], "over_current");
			sprintf(v[2], "over_power");
			sprintf(v[3], "under_voltage");
			sprintf(v[4], "over_voltage");
			sprintf(v[5], "under_temperature");
			sprintf(v[6], "over_temperature");
			sprintf(v[7], "can_communication");
			sprintf(v[8], "current_sensor_communication");
			sprintf(v[9], "cooling_under_temperature");
			sprintf(v[10], "cooling_over_temperature");
			sprintf(v[11], "cellboard_error");
			return 12;
		}
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
		if(!strcmp(sgn_name, "cellboard_group"))
		{
			sprintf(v[0], "post");
			sprintf(v[1], "under_voltage");
			sprintf(v[2], "over_voltage");
			sprintf(v[3], "under_temperature_cells");
			sprintf(v[4], "over_temperature_cells");
			sprintf(v[5], "under_temperature_discharge");
			sprintf(v[6], "over_temperature_discharge");
			sprintf(v[7], "can_communication");
			sprintf(v[8], "flash");
			sprintf(v[9], "bms_monitor_communication");
			sprintf(v[10], "open_wire");
			return 11;
		}
	}
	return 0;
}
