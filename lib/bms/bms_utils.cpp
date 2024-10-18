#include "bms_utils.hpp"

int bms_fields_string_from_id(int id, char **v, size_t fields_size, size_t string_size)
{
	switch(id)
    {
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
	case 1026:
		if(29 > fields_size) return 1;
		snprintf(v[0], string_size, BOARD_STATUS_CELLBOARD_ID);
		snprintf(v[1], string_size, BOARD_STATUS_ERRORS_CAN_COMM);
		snprintf(v[2], string_size, BOARD_STATUS_ERRORS_LTC_COMM);
		snprintf(v[3], string_size, BOARD_STATUS_ERRORS_TEMP_COMM_0);
		snprintf(v[4], string_size, BOARD_STATUS_ERRORS_TEMP_COMM_1);
		snprintf(v[5], string_size, BOARD_STATUS_ERRORS_TEMP_COMM_2);
		snprintf(v[6], string_size, BOARD_STATUS_ERRORS_TEMP_COMM_3);
		snprintf(v[7], string_size, BOARD_STATUS_ERRORS_TEMP_COMM_4);
		snprintf(v[8], string_size, BOARD_STATUS_ERRORS_TEMP_COMM_5);
		snprintf(v[9], string_size, BOARD_STATUS_ERRORS_OPEN_WIRE);
		snprintf(v[10], string_size, BOARD_STATUS_BALANCING_STATUS);
		snprintf(v[11], string_size, BOARD_STATUS_BALANCING_CELLS_CELL0);
		snprintf(v[12], string_size, BOARD_STATUS_BALANCING_CELLS_CELL1);
		snprintf(v[13], string_size, BOARD_STATUS_BALANCING_CELLS_CELL2);
		snprintf(v[14], string_size, BOARD_STATUS_BALANCING_CELLS_CELL3);
		snprintf(v[15], string_size, BOARD_STATUS_BALANCING_CELLS_CELL4);
		snprintf(v[16], string_size, BOARD_STATUS_BALANCING_CELLS_CELL5);
		snprintf(v[17], string_size, BOARD_STATUS_BALANCING_CELLS_CELL6);
		snprintf(v[18], string_size, BOARD_STATUS_BALANCING_CELLS_CELL7);
		snprintf(v[19], string_size, BOARD_STATUS_BALANCING_CELLS_CELL8);
		snprintf(v[20], string_size, BOARD_STATUS_BALANCING_CELLS_CELL9);
		snprintf(v[21], string_size, BOARD_STATUS_BALANCING_CELLS_CELL10);
		snprintf(v[22], string_size, BOARD_STATUS_BALANCING_CELLS_CELL11);
		snprintf(v[23], string_size, BOARD_STATUS_BALANCING_CELLS_CELL12);
		snprintf(v[24], string_size, BOARD_STATUS_BALANCING_CELLS_CELL13);
		snprintf(v[25], string_size, BOARD_STATUS_BALANCING_CELLS_CELL14);
		snprintf(v[26], string_size, BOARD_STATUS_BALANCING_CELLS_CELL15);
		snprintf(v[27], string_size, BOARD_STATUS_BALANCING_CELLS_CELL16);
		snprintf(v[28], string_size, BOARD_STATUS_BALANCING_CELLS_CELL17);

		return 0;
	case 515:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, TEMPERATURES_INFO_CELLBOARD_ID);
		snprintf(v[1], string_size, TEMPERATURES_INFO_MIN_TEMP);
		snprintf(v[2], string_size, TEMPERATURES_INFO_MAX_TEMP);
		snprintf(v[3], string_size, TEMPERATURES_INFO_AVG_TEMP);

		return 0;
	case 1539:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, TEMPERATURES_CELLBOARD_ID);
		snprintf(v[1], string_size, TEMPERATURES_START_INDEX);
		snprintf(v[2], string_size, TEMPERATURES_TEMP0);
		snprintf(v[3], string_size, TEMPERATURES_TEMP1);
		snprintf(v[4], string_size, TEMPERATURES_TEMP2);
		snprintf(v[5], string_size, TEMPERATURES_TEMP3);

		return 0;
	case 516:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, VOLTAGES_INFO_CELLBOARD_ID);
		snprintf(v[1], string_size, VOLTAGES_INFO_MIN_VOLTAGE);
		snprintf(v[2], string_size, VOLTAGES_INFO_MAX_VOLTAGE);
		snprintf(v[3], string_size, VOLTAGES_INFO_AVG_VOLTAGE);

		return 0;
	case 1540:
		if(5 > fields_size) return 1;
		snprintf(v[0], string_size, VOLTAGES_CELLBOARD_ID);
		snprintf(v[1], string_size, VOLTAGES_START_INDEX);
		snprintf(v[2], string_size, VOLTAGES_VOLTAGE0);
		snprintf(v[3], string_size, VOLTAGES_VOLTAGE1);
		snprintf(v[4], string_size, VOLTAGES_VOLTAGE2);

		return 0;
	case 16:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, SET_BALANCING_STATUS_THRESHOLD);
		snprintf(v[1], string_size, SET_BALANCING_STATUS_TARGET);
		snprintf(v[2], string_size, SET_BALANCING_STATUS_BALANCING_STATUS);

		return 0;
	case 0:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, CELLBOARD_FLASH_START);
		snprintf(v[1], string_size, CELLBOARD_FLASH_CELLBOARD_ID);
		snprintf(v[2], string_size, CELLBOARD_FLASH_BOARD_INDEX);

		return 0;
	case 3:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, CELLBOARD_FLASH_REQUEST_MAINBOARD);
		snprintf(v[1], string_size, CELLBOARD_FLASH_REQUEST_CELLBOARD_ID);

		return 0;
	case 4:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, CELLBOARD_FLASH_RESPONSE_CELLBOARD_ID);
		snprintf(v[1], string_size, CELLBOARD_FLASH_RESPONSE_READY);

		return 0;
	case 1537:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, CELLBOARD_DISCOVERY_CELLBOARD_ID);

		return 0;
	case 1545:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, CELLBOARD_VERSION_CELLBOARD_ID);
		snprintf(v[1], string_size, CELLBOARD_VERSION_CANLIB_BUILD_TIME);
		snprintf(v[2], string_size, CELLBOARD_VERSION_COMPONENT_BUILD_TIME);

		return 0;
	case 513:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, CELLBOARD_STATUS_CELLBOARD_ID);
		snprintf(v[1], string_size, CELLBOARD_STATUS_STATUS);

		return 0;
	case 1553:
		if(5 > fields_size) return 1;
		snprintf(v[0], string_size, CELLBOARD_CELLS_VOLTAGE_CELLBOARD_ID);
		snprintf(v[1], string_size, CELLBOARD_CELLS_VOLTAGE_OFFSET);
		snprintf(v[2], string_size, CELLBOARD_CELLS_VOLTAGE_VOLTAGE_0);
		snprintf(v[3], string_size, CELLBOARD_CELLS_VOLTAGE_VOLTAGE_1);
		snprintf(v[4], string_size, CELLBOARD_CELLS_VOLTAGE_VOLTAGE_2);

		return 0;
	case 1561:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, CELLBOARD_CELLS_TEMPERATURE_CELLBOARD_ID);
		snprintf(v[1], string_size, CELLBOARD_CELLS_TEMPERATURE_OFFSET);
		snprintf(v[2], string_size, CELLBOARD_CELLS_TEMPERATURE_TEMPERATURE_0);
		snprintf(v[3], string_size, CELLBOARD_CELLS_TEMPERATURE_TEMPERATURE_1);
		snprintf(v[4], string_size, CELLBOARD_CELLS_TEMPERATURE_TEMPERATURE_2);
		snprintf(v[5], string_size, CELLBOARD_CELLS_TEMPERATURE_TEMPERATURE_3);

		return 0;
	case 1025:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, CELLBOARD_SET_BALANCING_STATUS_START);
		snprintf(v[1], string_size, CELLBOARD_SET_BALANCING_STATUS_TARGET);
		snprintf(v[2], string_size, CELLBOARD_SET_BALANCING_STATUS_THRESHOLD);

		return 0;
	case 1569:
		if(26 > fields_size) return 1;
		snprintf(v[0], string_size, CELLBOARD_BALANCING_STATUS_STATUS);
		snprintf(v[1], string_size, CELLBOARD_BALANCING_STATUS_CELLBOARD_ID);
		snprintf(v[2], string_size, CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_0);
		snprintf(v[3], string_size, CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_1);
		snprintf(v[4], string_size, CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_2);
		snprintf(v[5], string_size, CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_3);
		snprintf(v[6], string_size, CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_4);
		snprintf(v[7], string_size, CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_5);
		snprintf(v[8], string_size, CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_6);
		snprintf(v[9], string_size, CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_7);
		snprintf(v[10], string_size, CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_8);
		snprintf(v[11], string_size, CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_9);
		snprintf(v[12], string_size, CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_10);
		snprintf(v[13], string_size, CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_11);
		snprintf(v[14], string_size, CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_12);
		snprintf(v[15], string_size, CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_13);
		snprintf(v[16], string_size, CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_14);
		snprintf(v[17], string_size, CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_15);
		snprintf(v[18], string_size, CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_16);
		snprintf(v[19], string_size, CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_17);
		snprintf(v[20], string_size, CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_18);
		snprintf(v[21], string_size, CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_19);
		snprintf(v[22], string_size, CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_20);
		snprintf(v[23], string_size, CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_21);
		snprintf(v[24], string_size, CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_22);
		snprintf(v[25], string_size, CELLBOARD_BALANCING_STATUS_DISCHARGING_CELL_23);

		return 0;
	case 521:
		if(11 > fields_size) return 1;
		snprintf(v[0], string_size, CELLBOARD_ERRORS_POST);
		snprintf(v[1], string_size, CELLBOARD_ERRORS_UNDERVOLTAGE);
		snprintf(v[2], string_size, CELLBOARD_ERRORS_OVERVOLTAGE);
		snprintf(v[3], string_size, CELLBOARD_ERRORS_UNDERTEMPERATURE_CELLS);
		snprintf(v[4], string_size, CELLBOARD_ERRORS_UNDERTEMPERATURE_DISCHARGE);
		snprintf(v[5], string_size, CELLBOARD_ERRORS_OVERTEMPERATURE_CELLS);
		snprintf(v[6], string_size, CELLBOARD_ERRORS_OVERTEMPERATURE_DISCHARGE);
		snprintf(v[7], string_size, CELLBOARD_ERRORS_CAN);
		snprintf(v[8], string_size, CELLBOARD_ERRORS_FLASH);
		snprintf(v[9], string_size, CELLBOARD_ERRORS_BMS_MONITOR);
		snprintf(v[10], string_size, CELLBOARD_ERRORS_OPEN_WIRE);

		return 0;

    }
    return 0;
}
int bms_enum_fields(int enum_id, char **v, size_t fields_size, size_t string_size)
{
    switch(enum_id)
    {
	case 0:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_ivt_msg_result_wh_ivt_id_result_wh_Vt_Result_Wh");

		return 0;
	case 1:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_ivt_msg_result_as_ivt_id_result_as_Vt_Result_As");

		return 0;
	case 2:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_ivt_msg_result_w_ivt_id_result_w_Vt_Result_W");

		return 0;
	case 3:
		if(35 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_ivt_msg_response_ivt_id_response_Resp_Cmd_Wrong_Command");
		snprintf(v[1], string_size, "bms_ivt_msg_response_ivt_id_response_Resp_Get_Set_ALIVE");
		snprintf(v[2], string_size, "bms_ivt_msg_response_ivt_id_response_Resp_Get_Set_ArtNr");
		snprintf(v[3], string_size, "bms_ivt_msg_response_ivt_id_response_Resp_Get_Set_Serialnumber");
		snprintf(v[4], string_size, "bms_ivt_msg_response_ivt_id_response_Resp_Get_Set_SW_VERSION");
		snprintf(v[5], string_size, "bms_ivt_msg_response_ivt_id_response_Resp_Get_Set_DEVICE_ID");
		snprintf(v[6], string_size, "bms_ivt_msg_response_ivt_id_response_Resp_Get_Set_THRESHOLD_NEG");
		snprintf(v[7], string_size, "bms_ivt_msg_response_ivt_id_response_Resp_Get_Set_THRESHOLD_POS");
		snprintf(v[8], string_size, "bms_ivt_msg_response_ivt_id_response_Resp_Get_Set_MODE");
		snprintf(v[9], string_size, "bms_ivt_msg_response_ivt_id_response_Resp_Get_Set_OC_TEST_TIME");
		snprintf(v[10], string_size, "bms_ivt_msg_response_ivt_id_response_Resp_Get_Set_STORE");
		snprintf(v[11], string_size, "bms_ivt_msg_response_ivt_id_response_Resp_Get_Set_TRIGGER");
		snprintf(v[12], string_size, "bms_ivt_msg_response_ivt_id_response_Resp_Get_Set_Reset_Error_Logdata");
		snprintf(v[13], string_size, "bms_ivt_msg_response_ivt_id_response_Resp_Config_Result_Wh");
		snprintf(v[14], string_size, "bms_ivt_msg_response_ivt_id_response_Resp_Config_Result_As");
		snprintf(v[15], string_size, "bms_ivt_msg_response_ivt_id_response_Resp_Config_Result_W");
		snprintf(v[16], string_size, "bms_ivt_msg_response_ivt_id_response_Resp_Config_Result_T");
		snprintf(v[17], string_size, "bms_ivt_msg_response_ivt_id_response_Resp_Config_Result_U3");
		snprintf(v[18], string_size, "bms_ivt_msg_response_ivt_id_response_Resp_Config_Result_U2");
		snprintf(v[19], string_size, "bms_ivt_msg_response_ivt_id_response_Resp_Config_Result_U1");
		snprintf(v[20], string_size, "bms_ivt_msg_response_ivt_id_response_Resp_Config_Result_I");
		snprintf(v[21], string_size, "bms_ivt_msg_response_ivt_id_response_Resp_CAN_ID_Response");
		snprintf(v[22], string_size, "bms_ivt_msg_response_ivt_id_response_Resp_CAN_ID_Command");
		snprintf(v[23], string_size, "bms_ivt_msg_response_ivt_id_response_Resp_CAN_ID_Res_Wh");
		snprintf(v[24], string_size, "bms_ivt_msg_response_ivt_id_response_Resp_CAN_ID_Res_As");
		snprintf(v[25], string_size, "bms_ivt_msg_response_ivt_id_response_Resp_CAN_ID_Res_W");
		snprintf(v[26], string_size, "bms_ivt_msg_response_ivt_id_response_Resp_CAN_ID_Res_I");
		snprintf(v[27], string_size, "bms_ivt_msg_response_ivt_id_response_Resp_CAN_ID_Res_T");
		snprintf(v[28], string_size, "bms_ivt_msg_response_ivt_id_response_Resp_CAN_ID_Res_U3");
		snprintf(v[29], string_size, "bms_ivt_msg_response_ivt_id_response_Resp_CAN_ID_Res_U2");
		snprintf(v[30], string_size, "bms_ivt_msg_response_ivt_id_response_Resp_CAN_ID_Res_U1");
		snprintf(v[31], string_size, "bms_ivt_msg_response_ivt_id_response_Resp_Error_Log_Logdata_Since_Res");
		snprintf(v[32], string_size, "bms_ivt_msg_response_ivt_id_response_Resp_Error_Log_Overall_Logdata");
		snprintf(v[33], string_size, "bms_ivt_msg_response_ivt_id_response_Resp_Error_Log_System_Error");
		snprintf(v[34], string_size, "bms_ivt_msg_response_ivt_id_response_Resp_Error_Log_Measurement_Error");

		return 0;
	case 4:
		if(16 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_ivt_msg_response__80_resp_measerror_item_Resp_error_calibration_data");
		snprintf(v[1], string_size, "bms_ivt_msg_response__80_resp_measerror_item_Resp_error_ntc_I_OpenCirc");
		snprintf(v[2], string_size, "bms_ivt_msg_response__80_resp_measerror_item_Resp_error_ntc_h_OpenCirc");
		snprintf(v[3], string_size, "bms_ivt_msg_response__80_resp_measerror_item_Resp_error_meas_U3_OpenCirc");
		snprintf(v[4], string_size, "bms_ivt_msg_response__80_resp_measerror_item_Resp_error_meas_U2_OpenCirc");
		snprintf(v[5], string_size, "bms_ivt_msg_response__80_resp_measerror_item_Resp_error_meas_U1_OpenCirc");
		snprintf(v[6], string_size, "bms_ivt_msg_response__80_resp_measerror_item_Resp_error_meas_I1_OpenCirc");
		snprintf(v[7], string_size, "bms_ivt_msg_response__80_resp_measerror_item_Resp__error_therm_EMF_correction");
		snprintf(v[8], string_size, "bms_ivt_msg_response__80_resp_measerror_item_Resp_error_cur_meas_implausible");
		snprintf(v[9], string_size, "bms_ivt_msg_response__80_resp_measerror_item_Resp_error_Vref");
		snprintf(v[10], string_size, "bms_ivt_msg_response__80_resp_measerror_item_Resp_error_Underflow_ADC_ch_2");
		snprintf(v[11], string_size, "bms_ivt_msg_response__80_resp_measerror_item_Resp_error_Overflow_ADC_ch_2");
		snprintf(v[12], string_size, "bms_ivt_msg_response__80_resp_measerror_item_Resp_error_Underflow_ADC_ch_1");
		snprintf(v[13], string_size, "bms_ivt_msg_response__80_resp_measerror_item_Reso_error_Overflow_ADC_ch_1");
		snprintf(v[14], string_size, "bms_ivt_msg_response__80_resp_measerror_item_Resp_error_ADC_interrupt");
		snprintf(v[15], string_size, "bms_ivt_msg_response__80_resp_measerror_item_Resonse_all_meas_errors");

		return 0;
	case 5:
		if(17 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_ivt_msg_response__81_resp_systemerror_item_Resp_error_Reset_EMC");
		snprintf(v[1], string_size, "bms_ivt_msg_response__81_resp_systemerror_item_Resp_error_Reset_Watchdog");
		snprintf(v[2], string_size, "bms_ivt_msg_response__81_resp_systemerror_item_Resp_error_Reset_illegal_opcode");
		snprintf(v[3], string_size, "bms_ivt_msg_response__81_resp_systemerror_item_Resp_error_ADC_Clock");
		snprintf(v[4], string_size, "bms_ivt_msg_response__81_resp_systemerror_item_Resp_error_eeprom_rw");
		snprintf(v[5], string_size, "bms_ivt_msg_response__81_resp_systemerror_item_Resp_error_Overcurrent_detection");
		snprintf(v[6], string_size, "bms_ivt_msg_response__81_resp_systemerror_item_Resp_error_Configuration");
		snprintf(v[7], string_size, "bms_ivt_msg_response__81_resp_systemerror_item_Resp_error_System_Init");
		snprintf(v[8], string_size, "bms_ivt_msg_response__81_resp_systemerror_item_Resp_error_System_Clock");
		snprintf(v[9], string_size, "bms_ivt_msg_response__81_resp_systemerror_item_Resp_error_Power_failure");
		snprintf(v[10], string_size, "bms_ivt_msg_response__81_resp_systemerror_item_Resp_error_Undertemp");
		snprintf(v[11], string_size, "bms_ivt_msg_response__81_resp_systemerror_item_Resp_error_Overtemp");
		snprintf(v[12], string_size, "bms_ivt_msg_response__81_resp_systemerror_item_Resp_error_CAN_bus_transmit_Data");
		snprintf(v[13], string_size, "bms_ivt_msg_response__81_resp_systemerror_item_Resp_error_CAN_bus_receive_Data");
		snprintf(v[14], string_size, "bms_ivt_msg_response__81_resp_systemerror_item_Resp_error_Parameter_CRC");
		snprintf(v[15], string_size, "bms_ivt_msg_response__81_resp_systemerror_item_Resp_error_code_CRC");
		snprintf(v[16], string_size, "bms_ivt_msg_response__81_resp_systemerror_item_Resonse_all_SystemErrors");

		return 0;
	case 6:
		if(30 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_ivt_msg_response__82_resp_alllogdata_item_Resp_temp_minimum");
		snprintf(v[1], string_size, "bms_ivt_msg_response__82_resp_alllogdata_item_Resp_temp_maxmimum");
		snprintf(v[2], string_size, "bms_ivt_msg_response__82_resp_alllogdata_item_Resp_U3_minimum");
		snprintf(v[3], string_size, "bms_ivt_msg_response__82_resp_alllogdata_item_Resp_U3_maximum");
		snprintf(v[4], string_size, "bms_ivt_msg_response__82_resp_alllogdata_item_Resp_U2_minimum");
		snprintf(v[5], string_size, "bms_ivt_msg_response__82_resp_alllogdata_item_Resp_U2_maxmimum");
		snprintf(v[6], string_size, "bms_ivt_msg_response__82_resp_alllogdata_item_Resp_U1_minimum");
		snprintf(v[7], string_size, "bms_ivt_msg_response__82_resp_alllogdata_item_Resp_U1_maximum");
		snprintf(v[8], string_size, "bms_ivt_msg_response__82_resp_alllogdata_item_Resp_current_minimum");
		snprintf(v[9], string_size, "bms_ivt_msg_response__82_resp_alllogdata_item_Resp_current_maximum");
		snprintf(v[10], string_size, "bms_ivt_msg_response__82_resp_alllogdata_item_Resp_oc_negative_activated");
		snprintf(v[11], string_size, "bms_ivt_msg_response__82_resp_alllogdata_item_Resp_oc_positive_activated");
		snprintf(v[12], string_size, "bms_ivt_msg_response__82_resp_alllogdata_item_Resp_run_temp_out_spec_limits");
		snprintf(v[13], string_size, "bms_ivt_msg_response__82_resp_alllogdata_item_Resp_run_temp_in_spec_limits");
		snprintf(v[14], string_size, "bms_ivt_msg_response__82_resp_alllogdata_item_Resp_run_volt_3_out_spec_limits");
		snprintf(v[15], string_size, "bms_ivt_msg_response__82_resp_alllogdata_item_Resp_run_volt_3_in_spec_limits");
		snprintf(v[16], string_size, "bms_ivt_msg_response__82_resp_alllogdata_item_Resp_run_volt_2_out_spec_limits");
		snprintf(v[17], string_size, "bms_ivt_msg_response__82_resp_alllogdata_item_Resp_run_volt_2_in_spec_limits");
		snprintf(v[18], string_size, "bms_ivt_msg_response__82_resp_alllogdata_item_Resp_run_volt_1_out_spec_limits");
		snprintf(v[19], string_size, "bms_ivt_msg_response__82_resp_alllogdata_item_Resp_run_volt_1_in_spec_limits");
		snprintf(v[20], string_size, "bms_ivt_msg_response__82_resp_alllogdata_item_Resp_run_cur_out_spec_limits");
		snprintf(v[21], string_size, "bms_ivt_msg_response__82_resp_alllogdata_item_Resp_run_cur_in_spec_limits");
		snprintf(v[22], string_size, "bms_ivt_msg_response__82_resp_alllogdata_item_Resp_run_overall");
		snprintf(v[23], string_size, "bms_ivt_msg_response__82_resp_alllogdata_item_Resp_energy_counter_discharging");
		snprintf(v[24], string_size, "bms_ivt_msg_response__82_resp_alllogdata_item_Resp_energy_counter_charging");
		snprintf(v[25], string_size, "bms_ivt_msg_response__82_resp_alllogdata_item_Resp_energy_counter_overall");
		snprintf(v[26], string_size, "bms_ivt_msg_response__82_resp_alllogdata_item_Resp_Ah_counter_discharging");
		snprintf(v[27], string_size, "bms_ivt_msg_response__82_resp_alllogdata_item_Resp_Ah_counter_charging");
		snprintf(v[28], string_size, "bms_ivt_msg_response__82_resp_alllogdata_item_Resp_Ah_counter_overall");
		snprintf(v[29], string_size, "bms_ivt_msg_response__82_resp_alllogdata_item_Response_on_Overall_Logdata");

		return 0;
	case 7:
		if(30 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_ivt_msg_response__83_resp_logdata_item_Resp_temp_minimum");
		snprintf(v[1], string_size, "bms_ivt_msg_response__83_resp_logdata_item_Resp_temp_maxmimum");
		snprintf(v[2], string_size, "bms_ivt_msg_response__83_resp_logdata_item_Resp_U3_minimum");
		snprintf(v[3], string_size, "bms_ivt_msg_response__83_resp_logdata_item_Resp_U3_maximum");
		snprintf(v[4], string_size, "bms_ivt_msg_response__83_resp_logdata_item_Resp_U2_minimum");
		snprintf(v[5], string_size, "bms_ivt_msg_response__83_resp_logdata_item_Resp_U2_maxmimum");
		snprintf(v[6], string_size, "bms_ivt_msg_response__83_resp_logdata_item_Resp_U1_minimum");
		snprintf(v[7], string_size, "bms_ivt_msg_response__83_resp_logdata_item_Resp_U1_maximum");
		snprintf(v[8], string_size, "bms_ivt_msg_response__83_resp_logdata_item_Resp_current_minimum");
		snprintf(v[9], string_size, "bms_ivt_msg_response__83_resp_logdata_item_Resp_current_maximum");
		snprintf(v[10], string_size, "bms_ivt_msg_response__83_resp_logdata_item_Resp_oc_negative_activated");
		snprintf(v[11], string_size, "bms_ivt_msg_response__83_resp_logdata_item_Resp_oc_positive_activated");
		snprintf(v[12], string_size, "bms_ivt_msg_response__83_resp_logdata_item_Resp_run_temp_out_spec_limits");
		snprintf(v[13], string_size, "bms_ivt_msg_response__83_resp_logdata_item_Resp_run_temp_in_spec_limits");
		snprintf(v[14], string_size, "bms_ivt_msg_response__83_resp_logdata_item_Resp_run_volt_3_out_spec_limits");
		snprintf(v[15], string_size, "bms_ivt_msg_response__83_resp_logdata_item_Resp_run_volt_3_in_spec_limits");
		snprintf(v[16], string_size, "bms_ivt_msg_response__83_resp_logdata_item_Resp_run_volt_2_out_spec_limits");
		snprintf(v[17], string_size, "bms_ivt_msg_response__83_resp_logdata_item_Resp_run_volt_2_in_spec_limits");
		snprintf(v[18], string_size, "bms_ivt_msg_response__83_resp_logdata_item_Resp_run_volt_1_out_spec_limits");
		snprintf(v[19], string_size, "bms_ivt_msg_response__83_resp_logdata_item_Resp_run_volt_1_in_spec_limits");
		snprintf(v[20], string_size, "bms_ivt_msg_response__83_resp_logdata_item_Resp_run_cur_out_spec_limits");
		snprintf(v[21], string_size, "bms_ivt_msg_response__83_resp_logdata_item_Resp_run_cur_in_spec_limits");
		snprintf(v[22], string_size, "bms_ivt_msg_response__83_resp_logdata_item_Resp_run_overall");
		snprintf(v[23], string_size, "bms_ivt_msg_response__83_resp_logdata_item_Resp_energy_counter_discharging");
		snprintf(v[24], string_size, "bms_ivt_msg_response__83_resp_logdata_item_Resp_energy_counter_charging");
		snprintf(v[25], string_size, "bms_ivt_msg_response__83_resp_logdata_item_Resp_energy_counter_overall");
		snprintf(v[26], string_size, "bms_ivt_msg_response__83_resp_logdata_item_Resp_Ah_counter_discharging");
		snprintf(v[27], string_size, "bms_ivt_msg_response__83_resp_logdata_item_Resp_Ah_counter_charging");
		snprintf(v[28], string_size, "bms_ivt_msg_response__83_resp_logdata_item_Resp_Ah_counter_overall");
		snprintf(v[29], string_size, "bms_ivt_msg_response__83_resp_logdata_item_Response_all_Logdata_SinceReset");

		return 0;
	case 8:
		if(63 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_ivt_msg_response__b0_resp_reset_item_Reset_temp_minimum");
		snprintf(v[1], string_size, "bms_ivt_msg_response__b0_resp_reset_item_Reset_temp_maximum");
		snprintf(v[2], string_size, "bms_ivt_msg_response__b0_resp_reset_item_Reset_U3_minimum");
		snprintf(v[3], string_size, "bms_ivt_msg_response__b0_resp_reset_item_Reset_U3_maximum");
		snprintf(v[4], string_size, "bms_ivt_msg_response__b0_resp_reset_item_Reset_U2_minimum");
		snprintf(v[5], string_size, "bms_ivt_msg_response__b0_resp_reset_item_Reset_U2_maximum");
		snprintf(v[6], string_size, "bms_ivt_msg_response__b0_resp_reset_item_Reset_U1_minimum");
		snprintf(v[7], string_size, "bms_ivt_msg_response__b0_resp_reset_item_Reset_U1_maximum");
		snprintf(v[8], string_size, "bms_ivt_msg_response__b0_resp_reset_item_Reset_Current_minimum");
		snprintf(v[9], string_size, "bms_ivt_msg_response__b0_resp_reset_item_Reset_Current_maximum");
		snprintf(v[10], string_size, "bms_ivt_msg_response__b0_resp_reset_item_Reset_Run_overcur_neg_activated");
		snprintf(v[11], string_size, "bms_ivt_msg_response__b0_resp_reset_item_Reset_Run_overcur_pos_activated");
		snprintf(v[12], string_size, "bms_ivt_msg_response__b0_resp_reset_item_Reset_Run_temp_out_spec_limits");
		snprintf(v[13], string_size, "bms_ivt_msg_response__b0_resp_reset_item_Reset_Run_temp_in_spec_limits");
		snprintf(v[14], string_size, "bms_ivt_msg_response__b0_resp_reset_item_Reset_Run_volt_3_out_spec_limits");
		snprintf(v[15], string_size, "bms_ivt_msg_response__b0_resp_reset_item_Reset_Run_volt_3_in_spec_limits");
		snprintf(v[16], string_size, "bms_ivt_msg_response__b0_resp_reset_item_Reset_Run_volt_2_out_spec_limits");
		snprintf(v[17], string_size, "bms_ivt_msg_response__b0_resp_reset_item_Reset_Run_volt_2_in_spec_limits");
		snprintf(v[18], string_size, "bms_ivt_msg_response__b0_resp_reset_item_Reset_Run_volt_1_out_spec_limits");
		snprintf(v[19], string_size, "bms_ivt_msg_response__b0_resp_reset_item_Reset_Run_volt_1_in_spec_limits");
		snprintf(v[20], string_size, "bms_ivt_msg_response__b0_resp_reset_item_Reset_Run_cur_out_spec_limits");
		snprintf(v[21], string_size, "bms_ivt_msg_response__b0_resp_reset_item_Reset_Run_cur_in_spec_limits");
		snprintf(v[22], string_size, "bms_ivt_msg_response__b0_resp_reset_item_Reset_Runtime_overall");
		snprintf(v[23], string_size, "bms_ivt_msg_response__b0_resp_reset_item_Reset_Energy_counter_discharging");
		snprintf(v[24], string_size, "bms_ivt_msg_response__b0_resp_reset_item_Reset_Energy_counter_charging");
		snprintf(v[25], string_size, "bms_ivt_msg_response__b0_resp_reset_item_Reset_Energy_counter_overall");
		snprintf(v[26], string_size, "bms_ivt_msg_response__b0_resp_reset_item_Reset_Ah_counter_discharging");
		snprintf(v[27], string_size, "bms_ivt_msg_response__b0_resp_reset_item_Reset_Ah_counter_charging");
		snprintf(v[28], string_size, "bms_ivt_msg_response__b0_resp_reset_item_Reset_Ah_counter_overall");
		snprintf(v[29], string_size, "bms_ivt_msg_response__b0_resp_reset_item_Reset_all_Logdata_Since_Reset");
		snprintf(v[30], string_size, "bms_ivt_msg_response__b0_resp_reset_item_Reset_Reset_EMC");
		snprintf(v[31], string_size, "bms_ivt_msg_response__b0_resp_reset_item_Reset_Reset_Watchdog");
		snprintf(v[32], string_size, "bms_ivt_msg_response__b0_resp_reset_item_Reset_illegal_opcode");
		snprintf(v[33], string_size, "bms_ivt_msg_response__b0_resp_reset_item_Reset_ADC_Clock");
		snprintf(v[34], string_size, "bms_ivt_msg_response__b0_resp_reset_item_Reset_eeprom_rw");
		snprintf(v[35], string_size, "bms_ivt_msg_response__b0_resp_reset_item_Reset_overcurrent_detection");
		snprintf(v[36], string_size, "bms_ivt_msg_response__b0_resp_reset_item_Reset_configuration");
		snprintf(v[37], string_size, "bms_ivt_msg_response__b0_resp_reset_item_Reset_system_init");
		snprintf(v[38], string_size, "bms_ivt_msg_response__b0_resp_reset_item_Reset_system_clock");
		snprintf(v[39], string_size, "bms_ivt_msg_response__b0_resp_reset_item_Reset_power_failure");
		snprintf(v[40], string_size, "bms_ivt_msg_response__b0_resp_reset_item_Reset_undertemp");
		snprintf(v[41], string_size, "bms_ivt_msg_response__b0_resp_reset_item_Reset_overtemp");
		snprintf(v[42], string_size, "bms_ivt_msg_response__b0_resp_reset_item_Reset_CAN_bus_transmit_Data");
		snprintf(v[43], string_size, "bms_ivt_msg_response__b0_resp_reset_item_Reset_CAN_bus_receive_Data");
		snprintf(v[44], string_size, "bms_ivt_msg_response__b0_resp_reset_item_Reset_Parameter_CRC");
		snprintf(v[45], string_size, "bms_ivt_msg_response__b0_resp_reset_item_Reset_Code_CRC");
		snprintf(v[46], string_size, "bms_ivt_msg_response__b0_resp_reset_item_Reset_all_System_errors");
		snprintf(v[47], string_size, "bms_ivt_msg_response__b0_resp_reset_item_Reset_calibration_data_");
		snprintf(v[48], string_size, "bms_ivt_msg_response__b0_resp_reset_item_Reset_ntc_I_OpenCircuit");
		snprintf(v[49], string_size, "bms_ivt_msg_response__b0_resp_reset_item_Reset_ntc_h_OpenCircuit");
		snprintf(v[50], string_size, "bms_ivt_msg_response__b0_resp_reset_item_Reset_voltage_measU3_OpenCircuit");
		snprintf(v[51], string_size, "bms_ivt_msg_response__b0_resp_reset_item_Reset_voltage_measU2_OpenCircuit");
		snprintf(v[52], string_size, "bms_ivt_msg_response__b0_resp_reset_item_Reset_voltage_measU1_OpenCircuit");
		snprintf(v[53], string_size, "bms_ivt_msg_response__b0_resp_reset_item_Reset_current_measI1_OpenCircuit");
		snprintf(v[54], string_size, "bms_ivt_msg_response__b0_resp_reset_item_Reset_thermal_EMF_correction");
		snprintf(v[55], string_size, "bms_ivt_msg_response__b0_resp_reset_item_Reset_error_current_implausible");
		snprintf(v[56], string_size, "bms_ivt_msg_response__b0_resp_reset_item_Reset_error_Vref");
		snprintf(v[57], string_size, "bms_ivt_msg_response__b0_resp_reset_item_Reset_error_Underflow_ADC_ch2");
		snprintf(v[58], string_size, "bms_ivt_msg_response__b0_resp_reset_item_Reset_error_Overflow_ADC_ch2");
		snprintf(v[59], string_size, "bms_ivt_msg_response__b0_resp_reset_item_Reset_error_Underflow_ADC_ch1");
		snprintf(v[60], string_size, "bms_ivt_msg_response__b0_resp_reset_item_Reset_error_Overflow_ADC_ch1");
		snprintf(v[61], string_size, "bms_ivt_msg_response__b0_resp_reset_item_Reset_error_ADC_interrupt");
		snprintf(v[62], string_size, "bms_ivt_msg_response__b0_resp_reset_item_Reset_all_measurement_errors");

		return 0;
	case 9:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_ivt_msg_response__b9_resp_device_type_IVT_S");
		snprintf(v[1], string_size, "bms_ivt_msg_response__b9_resp_device_type_IVT_Mod");

		return 0;
	case 10:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_ivt_msg_response__a0_resp_triggermode_i_CYCLIC");
		snprintf(v[1], string_size, "bms_ivt_msg_response__a0_resp_triggermode_i_TRIGGERED");
		snprintf(v[2], string_size, "bms_ivt_msg_response__a0_resp_triggermode_i_DISABLED");

		return 0;
	case 11:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_ivt_msg_response__a1_resp_triggermode_u1_CYCLIC");
		snprintf(v[1], string_size, "bms_ivt_msg_response__a1_resp_triggermode_u1_TRIGGERED");
		snprintf(v[2], string_size, "bms_ivt_msg_response__a1_resp_triggermode_u1_DISABLED");

		return 0;
	case 12:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_ivt_msg_response__a2_resp_triggermode_u2_CYCLIC");
		snprintf(v[1], string_size, "bms_ivt_msg_response__a2_resp_triggermode_u2_TRIGGERED");
		snprintf(v[2], string_size, "bms_ivt_msg_response__a2_resp_triggermode_u2_DISABLED");

		return 0;
	case 13:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_ivt_msg_response__a3_resp_triggermode_u3_CYCLIC");
		snprintf(v[1], string_size, "bms_ivt_msg_response__a3_resp_triggermode_u3_TRIGGERED");
		snprintf(v[2], string_size, "bms_ivt_msg_response__a3_resp_triggermode_u3_DISABLED");

		return 0;
	case 14:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_ivt_msg_response__a4_resp_triggermode_t_CYCLIC");
		snprintf(v[1], string_size, "bms_ivt_msg_response__a4_resp_triggermode_t_TRIGGERED");
		snprintf(v[2], string_size, "bms_ivt_msg_response__a4_resp_triggermode_t_DISABLED");

		return 0;
	case 15:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_ivt_msg_response__a5_resp_triggermode_w_CYCLIC");
		snprintf(v[1], string_size, "bms_ivt_msg_response__a5_resp_triggermode_w_TRIGGERED");
		snprintf(v[2], string_size, "bms_ivt_msg_response__a5_resp_triggermode_w_DISABLED");

		return 0;
	case 16:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_ivt_msg_response__a6_resp_triggermode_as_CYCLIC");
		snprintf(v[1], string_size, "bms_ivt_msg_response__a6_resp_triggermode_as_TRIGGERED");
		snprintf(v[2], string_size, "bms_ivt_msg_response__a6_resp_triggermode_as_DISABLED");

		return 0;
	case 17:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_ivt_msg_response__a7_resp_triggermode_wh_CYCLIC");
		snprintf(v[1], string_size, "bms_ivt_msg_response__a7_resp_triggermode_wh_TRIGGERED");
		snprintf(v[2], string_size, "bms_ivt_msg_response__a7_resp_triggermode_wh_DISABLED");

		return 0;
	case 18:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_ivt_msg_response__b4_resp_actual_mode_RUN");
		snprintf(v[1], string_size, "bms_ivt_msg_response__b4_resp_actual_mode_STOP");

		return 0;
	case 19:
		if(5 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_ivt_msg_response__b9_resp_device_current_2500_A");
		snprintf(v[1], string_size, "bms_ivt_msg_response__b9_resp_device_current_1000_A");
		snprintf(v[2], string_size, "bms_ivt_msg_response__b9_resp_device_current_500_A");
		snprintf(v[3], string_size, "bms_ivt_msg_response__b9_resp_device_current_300_A");
		snprintf(v[4], string_size, "bms_ivt_msg_response__b9_resp_device_current_100_A");

		return 0;
	case 20:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_ivt_msg_response__b4_resp_startup_mode_Run");
		snprintf(v[1], string_size, "bms_ivt_msg_response__b4_resp_startup_mode_Stop");

		return 0;
	case 21:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_ivt_msg_response__b9_resp_device_voltage_chan_3_Channels");
		snprintf(v[1], string_size, "bms_ivt_msg_response__b9_resp_device_voltage_chan_0_Channels");

		return 0;
	case 22:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_ivt_msg_response__b9_resp_device_toi_I");

		return 0;
	case 23:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_ivt_msg_response__b9_resp_device_com_CAN_2___not_terminated");
		snprintf(v[1], string_size, "bms_ivt_msg_response__b9_resp_device_com_CAN_1___terminated");
		snprintf(v[2], string_size, "bms_ivt_msg_response__b9_resp_device_com_none");

		return 0;
	case 24:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_ivt_msg_response__b9_resp_device_v_supply_12__24_V_nominal_supply_voltage");

		return 0;
	case 25:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_ivt_msg_result_t_ivt_id_result_t_Vt_Result_T");

		return 0;
	case 26:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_ivt_msg_result_u3_ivt_id_result_u3_Vt_Result_U3");

		return 0;
	case 27:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_ivt_msg_result_u2_ivt_id_result_u2_Vt_Result_U2");

		return 0;
	case 28:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_ivt_msg_result_u1_ivt_id_result_u1_Vt_Result_U1");

		return 0;
	case 29:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_ivt_msg_result_i_ivt_id_result_i_Vt_Result_I");

		return 0;
	case 30:
		if(58 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_ivt_msg_cmd_ivt_id_cmd_Get_cmd_and_info_ArtNr");
		snprintf(v[1], string_size, "bms_ivt_msg_cmd_ivt_id_cmd_Get_cmd_and_info_SN");
		snprintf(v[2], string_size, "bms_ivt_msg_cmd_ivt_id_cmd_Get_cmd_and_info_SW_Version");
		snprintf(v[3], string_size, "bms_ivt_msg_cmd_ivt_id_cmd_Get_cmd_and_info_DEVICE_ID");
		snprintf(v[4], string_size, "bms_ivt_msg_cmd_ivt_id_cmd_Get_cmd_and_info_THRESHOLD_NEG");
		snprintf(v[5], string_size, "bms_ivt_msg_cmd_ivt_id_cmd_Get_cmd_and_info_THRESHOLD_POS");
		snprintf(v[6], string_size, "bms_ivt_msg_cmd_ivt_id_cmd_Get_cmd_and_info_MODE");
		snprintf(v[7], string_size, "bms_ivt_msg_cmd_ivt_id_cmd_Get_cmd_and_info_OC_TEST_TIME");
		snprintf(v[8], string_size, "bms_ivt_msg_cmd_ivt_id_cmd_Get_Config_Res_Wh");
		snprintf(v[9], string_size, "bms_ivt_msg_cmd_ivt_id_cmd_Get_Config_Res_As");
		snprintf(v[10], string_size, "bms_ivt_msg_cmd_ivt_id_cmd_Get_Config_Res_W");
		snprintf(v[11], string_size, "bms_ivt_msg_cmd_ivt_id_cmd_Get_Config_Res_T");
		snprintf(v[12], string_size, "bms_ivt_msg_cmd_ivt_id_cmd_Get_Config_Res_U3");
		snprintf(v[13], string_size, "bms_ivt_msg_cmd_ivt_id_cmd_Get_Config_Res_U2");
		snprintf(v[14], string_size, "bms_ivt_msg_cmd_ivt_id_cmd_Get_Config_Res_U1");
		snprintf(v[15], string_size, "bms_ivt_msg_cmd_ivt_id_cmd_Get_Config_Res_I");
		snprintf(v[16], string_size, "bms_ivt_msg_cmd_ivt_id_cmd_Get_CAN_ID_Response");
		snprintf(v[17], string_size, "bms_ivt_msg_cmd_ivt_id_cmd_Get_CAN_ID_Command");
		snprintf(v[18], string_size, "bms_ivt_msg_cmd_ivt_id_cmd_Get_CAN_ID_Res_Wh");
		snprintf(v[19], string_size, "bms_ivt_msg_cmd_ivt_id_cmd_Get_CAN_ID_Res_As");
		snprintf(v[20], string_size, "bms_ivt_msg_cmd_ivt_id_cmd_Get_CAN_ID_Res_W");
		snprintf(v[21], string_size, "bms_ivt_msg_cmd_ivt_id_cmd_Get_CAN_ID_Res_T");
		snprintf(v[22], string_size, "bms_ivt_msg_cmd_ivt_id_cmd_Get_CAN_ID_Res_U3");
		snprintf(v[23], string_size, "bms_ivt_msg_cmd_ivt_id_cmd_Get_CAN_ID_Res_U2");
		snprintf(v[24], string_size, "bms_ivt_msg_cmd_ivt_id_cmd_Get_CAN_ID_Res_U1");
		snprintf(v[25], string_size, "bms_ivt_msg_cmd_ivt_id_cmd_Get_CAN_ID_Res_I");
		snprintf(v[26], string_size, "bms_ivt_msg_cmd_ivt_id_cmd_Get_Logdata_Since_Reset");
		snprintf(v[27], string_size, "bms_ivt_msg_cmd_ivt_id_cmd_Get_Overall_Logdata");
		snprintf(v[28], string_size, "bms_ivt_msg_cmd_ivt_id_cmd_Get_System_Errors");
		snprintf(v[29], string_size, "bms_ivt_msg_cmd_ivt_id_cmd_Get_Measurement_Errors");
		snprintf(v[30], string_size, "bms_ivt_msg_cmd_ivt_id_cmd_Set_RESTART");
		snprintf(v[31], string_size, "bms_ivt_msg_cmd_ivt_id_cmd_Set_RESTART_to_default");
		snprintf(v[32], string_size, "bms_ivt_msg_cmd_ivt_id_cmd_RESTART_to_Bitrate");
		snprintf(v[33], string_size, "bms_ivt_msg_cmd_ivt_id_cmd_Set_THRESHOLD_neg");
		snprintf(v[34], string_size, "bms_ivt_msg_cmd_ivt_id_cmd_Set_THRESHOLD_pos");
		snprintf(v[35], string_size, "bms_ivt_msg_cmd_ivt_id_cmd_Set_MODE_Result_I");
		snprintf(v[36], string_size, "bms_ivt_msg_cmd_ivt_id_cmd_Set_CAN_ID_Result_I");
		snprintf(v[37], string_size, "bms_ivt_msg_cmd_ivt_id_cmd_Set_MODE");
		snprintf(v[38], string_size, "bms_ivt_msg_cmd_ivt_id_cmd_START_OC_TEST");
		snprintf(v[39], string_size, "bms_ivt_msg_cmd_ivt_id_cmd_STORE");
		snprintf(v[40], string_size, "bms_ivt_msg_cmd_ivt_id_cmd_TRIGGER");
		snprintf(v[41], string_size, "bms_ivt_msg_cmd_ivt_id_cmd_Reset_Err_Log");
		snprintf(v[42], string_size, "bms_ivt_msg_cmd_ivt_id_cmd_Set_MODE_Result_Wh");
		snprintf(v[43], string_size, "bms_ivt_msg_cmd_ivt_id_cmd_Set_MODE_Result_As");
		snprintf(v[44], string_size, "bms_ivt_msg_cmd_ivt_id_cmd_Set_MODE_Result_W");
		snprintf(v[45], string_size, "bms_ivt_msg_cmd_ivt_id_cmd_Set_CAN_ID_Result_Wh");
		snprintf(v[46], string_size, "bms_ivt_msg_cmd_ivt_id_cmd_Set_CAN_ID_Result_As");
		snprintf(v[47], string_size, "bms_ivt_msg_cmd_ivt_id_cmd_Set_CAN_ID_Result_W");
		snprintf(v[48], string_size, "bms_ivt_msg_cmd_ivt_id_cmd_Set_CAN_ID_Result_T");
		snprintf(v[49], string_size, "bms_ivt_msg_cmd_ivt_id_cmd_Set_MODE_Result_U3");
		snprintf(v[50], string_size, "bms_ivt_msg_cmd_ivt_id_cmd_Set_CAN_ID_Response");
		snprintf(v[51], string_size, "bms_ivt_msg_cmd_ivt_id_cmd_Set_CAN_ID_Cmd");
		snprintf(v[52], string_size, "bms_ivt_msg_cmd_ivt_id_cmd_Set_CAN_ID_Result_U3");
		snprintf(v[53], string_size, "bms_ivt_msg_cmd_ivt_id_cmd_Set_CAN_ID_Result_U2");
		snprintf(v[54], string_size, "bms_ivt_msg_cmd_ivt_id_cmd_Set_MODE_Result_T");
		snprintf(v[55], string_size, "bms_ivt_msg_cmd_ivt_id_cmd_Set_MODE_Result_U2");
		snprintf(v[56], string_size, "bms_ivt_msg_cmd_ivt_id_cmd_Set_MODE_Result_U1");
		snprintf(v[57], string_size, "bms_ivt_msg_cmd_ivt_id_cmd_Set_CAN_ID_Result_U1");

		return 0;
	case 31:
		if(63 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_ivt_msg_cmd__30_reset_item_Reset_temp_minimum");
		snprintf(v[1], string_size, "bms_ivt_msg_cmd__30_reset_item_Reset_temp_maximum");
		snprintf(v[2], string_size, "bms_ivt_msg_cmd__30_reset_item_Reset_U3_minimum");
		snprintf(v[3], string_size, "bms_ivt_msg_cmd__30_reset_item_Reset_U3_maximum");
		snprintf(v[4], string_size, "bms_ivt_msg_cmd__30_reset_item_Reset_U2_minimum");
		snprintf(v[5], string_size, "bms_ivt_msg_cmd__30_reset_item_Reset_U2_maximum");
		snprintf(v[6], string_size, "bms_ivt_msg_cmd__30_reset_item_Reset_U1_minimum");
		snprintf(v[7], string_size, "bms_ivt_msg_cmd__30_reset_item_Reset_U1_maximum");
		snprintf(v[8], string_size, "bms_ivt_msg_cmd__30_reset_item_Reset_Current_minimum");
		snprintf(v[9], string_size, "bms_ivt_msg_cmd__30_reset_item_Reset_Current_maximum");
		snprintf(v[10], string_size, "bms_ivt_msg_cmd__30_reset_item_Reset_Run_overcur_neg_activated");
		snprintf(v[11], string_size, "bms_ivt_msg_cmd__30_reset_item_Reset_Run_overcur_pos_activated");
		snprintf(v[12], string_size, "bms_ivt_msg_cmd__30_reset_item_Reset_Run_temp_out_spec_limits");
		snprintf(v[13], string_size, "bms_ivt_msg_cmd__30_reset_item_Reset_Run_temp_in_spec_limits");
		snprintf(v[14], string_size, "bms_ivt_msg_cmd__30_reset_item_Reset_Run_volt_3_out_spec_limits");
		snprintf(v[15], string_size, "bms_ivt_msg_cmd__30_reset_item_Reset_Run_volt_3_in_spec_limits");
		snprintf(v[16], string_size, "bms_ivt_msg_cmd__30_reset_item_Reset_Run_volt_2_out_spec_limits");
		snprintf(v[17], string_size, "bms_ivt_msg_cmd__30_reset_item_Reset_Run_volt_2_in_spec_limits");
		snprintf(v[18], string_size, "bms_ivt_msg_cmd__30_reset_item_Reset_Run_volt_1_out_spec_limits");
		snprintf(v[19], string_size, "bms_ivt_msg_cmd__30_reset_item_Reset_Run_volt_1_in_spec_limits");
		snprintf(v[20], string_size, "bms_ivt_msg_cmd__30_reset_item_Reset_Run_cur_out_spec_limits");
		snprintf(v[21], string_size, "bms_ivt_msg_cmd__30_reset_item_Reset_Run_cur_in_spec_limits");
		snprintf(v[22], string_size, "bms_ivt_msg_cmd__30_reset_item_Reset_Runtime_overall");
		snprintf(v[23], string_size, "bms_ivt_msg_cmd__30_reset_item_Reset_Energy_counter_discharging");
		snprintf(v[24], string_size, "bms_ivt_msg_cmd__30_reset_item_Reset_Energy_counter_charging");
		snprintf(v[25], string_size, "bms_ivt_msg_cmd__30_reset_item_Reset_Energy_counter_overall");
		snprintf(v[26], string_size, "bms_ivt_msg_cmd__30_reset_item_Reset_Ah_counter_discharging");
		snprintf(v[27], string_size, "bms_ivt_msg_cmd__30_reset_item_Reset_Ah_counter_charging");
		snprintf(v[28], string_size, "bms_ivt_msg_cmd__30_reset_item_Reset_Ah_counter_overall");
		snprintf(v[29], string_size, "bms_ivt_msg_cmd__30_reset_item_Reset_all_Logdata_Since_Reset");
		snprintf(v[30], string_size, "bms_ivt_msg_cmd__30_reset_item_Reset_Reset_EMC");
		snprintf(v[31], string_size, "bms_ivt_msg_cmd__30_reset_item_Reset_Reset_Watchdog");
		snprintf(v[32], string_size, "bms_ivt_msg_cmd__30_reset_item_Reset_illegal_opcode");
		snprintf(v[33], string_size, "bms_ivt_msg_cmd__30_reset_item_Reset_ADC_Clock");
		snprintf(v[34], string_size, "bms_ivt_msg_cmd__30_reset_item_Reset_eeprom_rw");
		snprintf(v[35], string_size, "bms_ivt_msg_cmd__30_reset_item_Reset_overcurrent_detection");
		snprintf(v[36], string_size, "bms_ivt_msg_cmd__30_reset_item_Reset_configuration");
		snprintf(v[37], string_size, "bms_ivt_msg_cmd__30_reset_item_Reset_system_init");
		snprintf(v[38], string_size, "bms_ivt_msg_cmd__30_reset_item_Reset_system_clock");
		snprintf(v[39], string_size, "bms_ivt_msg_cmd__30_reset_item_Reset_power_failure");
		snprintf(v[40], string_size, "bms_ivt_msg_cmd__30_reset_item_Reset_undertemp");
		snprintf(v[41], string_size, "bms_ivt_msg_cmd__30_reset_item_Reset_overtemp");
		snprintf(v[42], string_size, "bms_ivt_msg_cmd__30_reset_item_Reset_CAN_bus_transmit_Data");
		snprintf(v[43], string_size, "bms_ivt_msg_cmd__30_reset_item_Reset_CAN_bus_receive_Data");
		snprintf(v[44], string_size, "bms_ivt_msg_cmd__30_reset_item_Reset_Parameter_CRC");
		snprintf(v[45], string_size, "bms_ivt_msg_cmd__30_reset_item_Reset_Code_CRC");
		snprintf(v[46], string_size, "bms_ivt_msg_cmd__30_reset_item_Reset_all_System_errors");
		snprintf(v[47], string_size, "bms_ivt_msg_cmd__30_reset_item_Reset_calibration_data_");
		snprintf(v[48], string_size, "bms_ivt_msg_cmd__30_reset_item_Reset_ntc_I_OpenCircuit");
		snprintf(v[49], string_size, "bms_ivt_msg_cmd__30_reset_item_Reset_ntc_h_OpenCircuit");
		snprintf(v[50], string_size, "bms_ivt_msg_cmd__30_reset_item_Reset_voltage_measU3_OpenCircuit");
		snprintf(v[51], string_size, "bms_ivt_msg_cmd__30_reset_item_Reset_voltage_measU2_OpenCircuit");
		snprintf(v[52], string_size, "bms_ivt_msg_cmd__30_reset_item_Reset_voltage_measU1_OpenCircuit");
		snprintf(v[53], string_size, "bms_ivt_msg_cmd__30_reset_item_Reset_current_measI1_OpenCircuit");
		snprintf(v[54], string_size, "bms_ivt_msg_cmd__30_reset_item_Reset_thermal_EMF_correction");
		snprintf(v[55], string_size, "bms_ivt_msg_cmd__30_reset_item_Reset_error_current_implausible");
		snprintf(v[56], string_size, "bms_ivt_msg_cmd__30_reset_item_Reset_error_Vref");
		snprintf(v[57], string_size, "bms_ivt_msg_cmd__30_reset_item_Reset_error_Underflow_ADC_ch2");
		snprintf(v[58], string_size, "bms_ivt_msg_cmd__30_reset_item_Reset_error_Overflow_ADC_ch2");
		snprintf(v[59], string_size, "bms_ivt_msg_cmd__30_reset_item_Reset_error_Underflow_ADC_ch1");
		snprintf(v[60], string_size, "bms_ivt_msg_cmd__30_reset_item_Reset_error_Overflow_ADC_ch1");
		snprintf(v[61], string_size, "bms_ivt_msg_cmd__30_reset_item_Reset_error_ADC_interrupt");
		snprintf(v[62], string_size, "bms_ivt_msg_cmd__30_reset_item_Reset_all_measurement_errors");

		return 0;
	case 32:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_ivt_msg_cmd__3a_restart_to_bitrate_250k");
		snprintf(v[1], string_size, "bms_ivt_msg_cmd__3a_restart_to_bitrate_500k");
		snprintf(v[2], string_size, "bms_ivt_msg_cmd__3a_restart_to_bitrate_1000k");

		return 0;
	case 33:
		if(16 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_ivt_msg_cmd__40_get_measerror_item_Get_error_calibration_data");
		snprintf(v[1], string_size, "bms_ivt_msg_cmd__40_get_measerror_item_Get_error_ntc_I_OpenCirc");
		snprintf(v[2], string_size, "bms_ivt_msg_cmd__40_get_measerror_item_Get_error_ntc_h_OpenCirc");
		snprintf(v[3], string_size, "bms_ivt_msg_cmd__40_get_measerror_item_Get_error_volt_meas_U3_OpenCirc");
		snprintf(v[4], string_size, "bms_ivt_msg_cmd__40_get_measerror_item_Get_error_volt_meas_U2_OpenCirc");
		snprintf(v[5], string_size, "bms_ivt_msg_cmd__40_get_measerror_item_Get_error_volt_meas_U1_OpenCirc");
		snprintf(v[6], string_size, "bms_ivt_msg_cmd__40_get_measerror_item_Get_error_cur_meas_I1_OpenCirc");
		snprintf(v[7], string_size, "bms_ivt_msg_cmd__40_get_measerror_item_Get_error_thermal_EMF_correction");
		snprintf(v[8], string_size, "bms_ivt_msg_cmd__40_get_measerror_item_Get_error_cur_meas_implausible");
		snprintf(v[9], string_size, "bms_ivt_msg_cmd__40_get_measerror_item_Get_error_Vref");
		snprintf(v[10], string_size, "bms_ivt_msg_cmd__40_get_measerror_item_Get_error_Underflow_ADC_ch_2");
		snprintf(v[11], string_size, "bms_ivt_msg_cmd__40_get_measerror_item_Get_error_Overflow_ADC_ch_2");
		snprintf(v[12], string_size, "bms_ivt_msg_cmd__40_get_measerror_item_Get_error_Underflow_ADC_ch_1");
		snprintf(v[13], string_size, "bms_ivt_msg_cmd__40_get_measerror_item_Get_error_Overflow_ADC_ch_1");
		snprintf(v[14], string_size, "bms_ivt_msg_cmd__40_get_measerror_item_Get_error_ADC_interrupt");
		snprintf(v[15], string_size, "bms_ivt_msg_cmd__40_get_measerror_item_Get_all_meas_Errors");

		return 0;
	case 34:
		if(17 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_ivt_msg_cmd__41_get_systemerror_item_Get_error_reset_EMC");
		snprintf(v[1], string_size, "bms_ivt_msg_cmd__41_get_systemerror_item_Get_error_reset_Watchdog");
		snprintf(v[2], string_size, "bms_ivt_msg_cmd__41_get_systemerror_item_Get_error_reset_illegal_opcode");
		snprintf(v[3], string_size, "bms_ivt_msg_cmd__41_get_systemerror_item_Get_error_ADC_clock");
		snprintf(v[4], string_size, "bms_ivt_msg_cmd__41_get_systemerror_item_Get_error_eeprom_rw");
		snprintf(v[5], string_size, "bms_ivt_msg_cmd__41_get_systemerror_item_Get_error_overcurrent_detection");
		snprintf(v[6], string_size, "bms_ivt_msg_cmd__41_get_systemerror_item_Get_error_configuration");
		snprintf(v[7], string_size, "bms_ivt_msg_cmd__41_get_systemerror_item_Get_error_system_init");
		snprintf(v[8], string_size, "bms_ivt_msg_cmd__41_get_systemerror_item_Get_error_system_clock");
		snprintf(v[9], string_size, "bms_ivt_msg_cmd__41_get_systemerror_item_Get_error_power_failure");
		snprintf(v[10], string_size, "bms_ivt_msg_cmd__41_get_systemerror_item_Get_error_undertemp");
		snprintf(v[11], string_size, "bms_ivt_msg_cmd__41_get_systemerror_item_Get_error_overtemp");
		snprintf(v[12], string_size, "bms_ivt_msg_cmd__41_get_systemerror_item_Get_error_CAN_bus_transmit_Data");
		snprintf(v[13], string_size, "bms_ivt_msg_cmd__41_get_systemerror_item_Get_error_CAN__bus_receive_Data");
		snprintf(v[14], string_size, "bms_ivt_msg_cmd__41_get_systemerror_item_Get_error_Code_Parameter_CRC");
		snprintf(v[15], string_size, "bms_ivt_msg_cmd__41_get_systemerror_item_Get_error_Code_CRC");
		snprintf(v[16], string_size, "bms_ivt_msg_cmd__41_get_systemerror_item_Get_all_System_errors");

		return 0;
	case 35:
		if(30 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_ivt_msg_cmd__42_get_alllogdata_item_Get_Temperature_minimum");
		snprintf(v[1], string_size, "bms_ivt_msg_cmd__42_get_alllogdata_item_Get_Temperature_maximum");
		snprintf(v[2], string_size, "bms_ivt_msg_cmd__42_get_alllogdata_item_Get_U3_minimum");
		snprintf(v[3], string_size, "bms_ivt_msg_cmd__42_get_alllogdata_item_Get_U3_maxmimum_");
		snprintf(v[4], string_size, "bms_ivt_msg_cmd__42_get_alllogdata_item_Get_U2_minimum");
		snprintf(v[5], string_size, "bms_ivt_msg_cmd__42_get_alllogdata_item_Get_U2_maximum");
		snprintf(v[6], string_size, "bms_ivt_msg_cmd__42_get_alllogdata_item_Get_U1_minimum");
		snprintf(v[7], string_size, "bms_ivt_msg_cmd__42_get_alllogdata_item_Get_U1_maxmimum");
		snprintf(v[8], string_size, "bms_ivt_msg_cmd__42_get_alllogdata_item_Get_current_minimum");
		snprintf(v[9], string_size, "bms_ivt_msg_cmd__42_get_alllogdata_item_Get_current_maximum");
		snprintf(v[10], string_size, "bms_ivt_msg_cmd__42_get_alllogdata_item_Get_run_overcur_neg_activated");
		snprintf(v[11], string_size, "bms_ivt_msg_cmd__42_get_alllogdata_item_Get_run_overcur_pos_activated");
		snprintf(v[12], string_size, "bms_ivt_msg_cmd__42_get_alllogdata_item_Get_run_temp_out_spec_limits");
		snprintf(v[13], string_size, "bms_ivt_msg_cmd__42_get_alllogdata_item_Get_run_temp_in_spec_limits");
		snprintf(v[14], string_size, "bms_ivt_msg_cmd__42_get_alllogdata_item_Get_run_volt3_out_spec_limits");
		snprintf(v[15], string_size, "bms_ivt_msg_cmd__42_get_alllogdata_item_Get_run_volt3_in_spec_limits");
		snprintf(v[16], string_size, "bms_ivt_msg_cmd__42_get_alllogdata_item_Get_run_volt2_out_spec_limits");
		snprintf(v[17], string_size, "bms_ivt_msg_cmd__42_get_alllogdata_item_Get_run_volt2_in_spec_limits");
		snprintf(v[18], string_size, "bms_ivt_msg_cmd__42_get_alllogdata_item_Get_run_volt1_out_spec_limits");
		snprintf(v[19], string_size, "bms_ivt_msg_cmd__42_get_alllogdata_item_Get_run_volt1_in_spec_limits");
		snprintf(v[20], string_size, "bms_ivt_msg_cmd__42_get_alllogdata_item_Get_run_cur_out_spec_limits");
		snprintf(v[21], string_size, "bms_ivt_msg_cmd__42_get_alllogdata_item_Get_Run_cur_in_spec_limits");
		snprintf(v[22], string_size, "bms_ivt_msg_cmd__42_get_alllogdata_item_Get_Runtime_overall");
		snprintf(v[23], string_size, "bms_ivt_msg_cmd__42_get_alllogdata_item_Get_Energy_counter_discharging");
		snprintf(v[24], string_size, "bms_ivt_msg_cmd__42_get_alllogdata_item_Get_Energy_counter_charging");
		snprintf(v[25], string_size, "bms_ivt_msg_cmd__42_get_alllogdata_item_Get_Energy_counter_overall");
		snprintf(v[26], string_size, "bms_ivt_msg_cmd__42_get_alllogdata_item_Get_Ah_counter_discharging");
		snprintf(v[27], string_size, "bms_ivt_msg_cmd__42_get_alllogdata_item_Get_Ah_counter_charging");
		snprintf(v[28], string_size, "bms_ivt_msg_cmd__42_get_alllogdata_item_Get_Ah_counter_overall");
		snprintf(v[29], string_size, "bms_ivt_msg_cmd__42_get_alllogdata_item_Get_Overall_Logdata");

		return 0;
	case 36:
		if(30 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_ivt_msg_cmd__43_get_logdata_item_Get_Temperature_minimum");
		snprintf(v[1], string_size, "bms_ivt_msg_cmd__43_get_logdata_item_Get_Temperature_maximum");
		snprintf(v[2], string_size, "bms_ivt_msg_cmd__43_get_logdata_item_Get_U3_minimum");
		snprintf(v[3], string_size, "bms_ivt_msg_cmd__43_get_logdata_item_Get_U3_maxmimum_");
		snprintf(v[4], string_size, "bms_ivt_msg_cmd__43_get_logdata_item_Get_U2_minimum");
		snprintf(v[5], string_size, "bms_ivt_msg_cmd__43_get_logdata_item_Get_U2_maximum");
		snprintf(v[6], string_size, "bms_ivt_msg_cmd__43_get_logdata_item_Get_U1_minimum");
		snprintf(v[7], string_size, "bms_ivt_msg_cmd__43_get_logdata_item_Get_U1_maxmimum");
		snprintf(v[8], string_size, "bms_ivt_msg_cmd__43_get_logdata_item_Get_current_minimum");
		snprintf(v[9], string_size, "bms_ivt_msg_cmd__43_get_logdata_item_Get_current_maximum");
		snprintf(v[10], string_size, "bms_ivt_msg_cmd__43_get_logdata_item_Get_run_overcur_neg_activated");
		snprintf(v[11], string_size, "bms_ivt_msg_cmd__43_get_logdata_item_Get_run_overcur_pos_activated");
		snprintf(v[12], string_size, "bms_ivt_msg_cmd__43_get_logdata_item_Get_run_temp_out_spec_limits");
		snprintf(v[13], string_size, "bms_ivt_msg_cmd__43_get_logdata_item_Get_run_temp_in_spec_limits");
		snprintf(v[14], string_size, "bms_ivt_msg_cmd__43_get_logdata_item_Get_run_volt3_out_spec_limits");
		snprintf(v[15], string_size, "bms_ivt_msg_cmd__43_get_logdata_item_Get_run_volt3_in_spec_limits");
		snprintf(v[16], string_size, "bms_ivt_msg_cmd__43_get_logdata_item_Get_run_volt2_out_spec_limits");
		snprintf(v[17], string_size, "bms_ivt_msg_cmd__43_get_logdata_item_Get_run_volt2_in_spec_limits");
		snprintf(v[18], string_size, "bms_ivt_msg_cmd__43_get_logdata_item_Get_run_volt1_out_spec_limits");
		snprintf(v[19], string_size, "bms_ivt_msg_cmd__43_get_logdata_item_Get_run_volt1_in_spec_limits");
		snprintf(v[20], string_size, "bms_ivt_msg_cmd__43_get_logdata_item_Get_run_cur_out_spec_limits");
		snprintf(v[21], string_size, "bms_ivt_msg_cmd__43_get_logdata_item_Get_Run_cur_in_spec_limits");
		snprintf(v[22], string_size, "bms_ivt_msg_cmd__43_get_logdata_item_Get_Runtime_overall");
		snprintf(v[23], string_size, "bms_ivt_msg_cmd__43_get_logdata_item_Get_Energy_counter_discharging");
		snprintf(v[24], string_size, "bms_ivt_msg_cmd__43_get_logdata_item_Get_Energy_counter_charging");
		snprintf(v[25], string_size, "bms_ivt_msg_cmd__43_get_logdata_item_Get_Energy_counter_overall");
		snprintf(v[26], string_size, "bms_ivt_msg_cmd__43_get_logdata_item_Get_Ah_counter_discharging");
		snprintf(v[27], string_size, "bms_ivt_msg_cmd__43_get_logdata_item_Get_Ah_counter_charging");
		snprintf(v[28], string_size, "bms_ivt_msg_cmd__43_get_logdata_item_Get_Ah_counter_overall");
		snprintf(v[29], string_size, "bms_ivt_msg_cmd__43_get_logdata_item_Get_Overall_Logdata");

		return 0;
	case 37:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_ivt_msg_cmd__20_conf_triggermode_i_CYCLIC");
		snprintf(v[1], string_size, "bms_ivt_msg_cmd__20_conf_triggermode_i_TRIGGERED");
		snprintf(v[2], string_size, "bms_ivt_msg_cmd__20_conf_triggermode_i_DISABLED");

		return 0;
	case 38:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_ivt_msg_cmd__21_conf_triggermode_u1_CYCLIC");
		snprintf(v[1], string_size, "bms_ivt_msg_cmd__21_conf_triggermode_u1_TRIGGERED");
		snprintf(v[2], string_size, "bms_ivt_msg_cmd__21_conf_triggermode_u1_DISABLED");

		return 0;
	case 39:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_ivt_msg_cmd__22_conf_triggermode_u2_CYCLIC");
		snprintf(v[1], string_size, "bms_ivt_msg_cmd__22_conf_triggermode_u2_TRIGGERED");
		snprintf(v[2], string_size, "bms_ivt_msg_cmd__22_conf_triggermode_u2_DISABLED");

		return 0;
	case 40:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_ivt_msg_cmd__23_conf_triggermode_u3_CYCLIC");
		snprintf(v[1], string_size, "bms_ivt_msg_cmd__23_conf_triggermode_u3_TRIGGERED");
		snprintf(v[2], string_size, "bms_ivt_msg_cmd__23_conf_triggermode_u3_DISABLED");

		return 0;
	case 41:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_ivt_msg_cmd__24_conf_triggermode_t_CYCLIC");
		snprintf(v[1], string_size, "bms_ivt_msg_cmd__24_conf_triggermode_t_TRIGGERED");
		snprintf(v[2], string_size, "bms_ivt_msg_cmd__24_conf_triggermode_t_DISABLED");

		return 0;
	case 42:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_ivt_msg_cmd__25_conf_triggermode_w_CYCLIC");
		snprintf(v[1], string_size, "bms_ivt_msg_cmd__25_conf_triggermode_w_TRIGGERED");
		snprintf(v[2], string_size, "bms_ivt_msg_cmd__25_conf_triggermode_w_DISABLED");

		return 0;
	case 43:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_ivt_msg_cmd__26_conf_triggermode_as_CYCLIC");
		snprintf(v[1], string_size, "bms_ivt_msg_cmd__26_conf_triggermode_as_TRIGGERED");
		snprintf(v[2], string_size, "bms_ivt_msg_cmd__26_conf_triggermode_as_DISABLED");

		return 0;
	case 44:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_ivt_msg_cmd__27_conf_triggermode_wh_CYCLIC");
		snprintf(v[1], string_size, "bms_ivt_msg_cmd__27_conf_triggermode_wh_TRIGGERED");
		snprintf(v[2], string_size, "bms_ivt_msg_cmd__27_conf_triggermode_wh_DISABLED");

		return 0;
	case 45:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_ivt_msg_cmd__34_actual_mode_START");
		snprintf(v[1], string_size, "bms_ivt_msg_cmd__34_actual_mode_STOP");

		return 0;
	case 46:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_ivt_msg_cmd__34_startup_mode_START");
		snprintf(v[1], string_size, "bms_ivt_msg_cmd__34_startup_mode_STOP");

		return 0;
	case 47:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_board_status_cellboard_id_CELLBOARD_0");
		snprintf(v[1], string_size, "bms_board_status_cellboard_id_CELLBOARD_1");
		snprintf(v[2], string_size, "bms_board_status_cellboard_id_CELLBOARD_2");
		snprintf(v[3], string_size, "bms_board_status_cellboard_id_CELLBOARD_3");
		snprintf(v[4], string_size, "bms_board_status_cellboard_id_CELLBOARD_4");
		snprintf(v[5], string_size, "bms_board_status_cellboard_id_CELLBOARD_5");

		return 0;
	case 48:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_board_status_balancing_status_OFF");
		snprintf(v[1], string_size, "bms_board_status_balancing_status_DISCHARGE");

		return 0;
	case 49:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_temperatures_info_cellboard_id_CELLBOARD_0");
		snprintf(v[1], string_size, "bms_temperatures_info_cellboard_id_CELLBOARD_1");
		snprintf(v[2], string_size, "bms_temperatures_info_cellboard_id_CELLBOARD_2");
		snprintf(v[3], string_size, "bms_temperatures_info_cellboard_id_CELLBOARD_3");
		snprintf(v[4], string_size, "bms_temperatures_info_cellboard_id_CELLBOARD_4");
		snprintf(v[5], string_size, "bms_temperatures_info_cellboard_id_CELLBOARD_5");

		return 0;
	case 50:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_temperatures_cellboard_id_CELLBOARD_0");
		snprintf(v[1], string_size, "bms_temperatures_cellboard_id_CELLBOARD_1");
		snprintf(v[2], string_size, "bms_temperatures_cellboard_id_CELLBOARD_2");
		snprintf(v[3], string_size, "bms_temperatures_cellboard_id_CELLBOARD_3");
		snprintf(v[4], string_size, "bms_temperatures_cellboard_id_CELLBOARD_4");
		snprintf(v[5], string_size, "bms_temperatures_cellboard_id_CELLBOARD_5");

		return 0;
	case 51:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_voltages_info_cellboard_id_CELLBOARD_0");
		snprintf(v[1], string_size, "bms_voltages_info_cellboard_id_CELLBOARD_1");
		snprintf(v[2], string_size, "bms_voltages_info_cellboard_id_CELLBOARD_2");
		snprintf(v[3], string_size, "bms_voltages_info_cellboard_id_CELLBOARD_3");
		snprintf(v[4], string_size, "bms_voltages_info_cellboard_id_CELLBOARD_4");
		snprintf(v[5], string_size, "bms_voltages_info_cellboard_id_CELLBOARD_5");

		return 0;
	case 52:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_voltages_cellboard_id_CELLBOARD_0");
		snprintf(v[1], string_size, "bms_voltages_cellboard_id_CELLBOARD_1");
		snprintf(v[2], string_size, "bms_voltages_cellboard_id_CELLBOARD_2");
		snprintf(v[3], string_size, "bms_voltages_cellboard_id_CELLBOARD_3");
		snprintf(v[4], string_size, "bms_voltages_cellboard_id_CELLBOARD_4");
		snprintf(v[5], string_size, "bms_voltages_cellboard_id_CELLBOARD_5");

		return 0;
	case 53:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_set_balancing_status_balancing_status_OFF");
		snprintf(v[1], string_size, "bms_set_balancing_status_balancing_status_DISCHARGE");

		return 0;
	case 54:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_cellboard_flash_cellboard_id_CELLBOARD_0");
		snprintf(v[1], string_size, "bms_cellboard_flash_cellboard_id_CELLBOARD_1");
		snprintf(v[2], string_size, "bms_cellboard_flash_cellboard_id_CELLBOARD_2");
		snprintf(v[3], string_size, "bms_cellboard_flash_cellboard_id_CELLBOARD_3");
		snprintf(v[4], string_size, "bms_cellboard_flash_cellboard_id_CELLBOARD_4");
		snprintf(v[5], string_size, "bms_cellboard_flash_cellboard_id_CELLBOARD_5");

		return 0;
	case 55:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_cellboard_flash_request_cellboard_id_cellboard_0");
		snprintf(v[1], string_size, "bms_cellboard_flash_request_cellboard_id_cellboard_1");
		snprintf(v[2], string_size, "bms_cellboard_flash_request_cellboard_id_cellboard_2");
		snprintf(v[3], string_size, "bms_cellboard_flash_request_cellboard_id_cellboard_3");
		snprintf(v[4], string_size, "bms_cellboard_flash_request_cellboard_id_cellboard_4");
		snprintf(v[5], string_size, "bms_cellboard_flash_request_cellboard_id_cellboard_5");

		return 0;
	case 56:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_cellboard_flash_response_cellboard_id_cellboard_0");
		snprintf(v[1], string_size, "bms_cellboard_flash_response_cellboard_id_cellboard_1");
		snprintf(v[2], string_size, "bms_cellboard_flash_response_cellboard_id_cellboard_2");
		snprintf(v[3], string_size, "bms_cellboard_flash_response_cellboard_id_cellboard_3");
		snprintf(v[4], string_size, "bms_cellboard_flash_response_cellboard_id_cellboard_4");
		snprintf(v[5], string_size, "bms_cellboard_flash_response_cellboard_id_cellboard_5");

		return 0;
	case 57:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_cellboard_discovery_cellboard_id_cellboard_0");
		snprintf(v[1], string_size, "bms_cellboard_discovery_cellboard_id_cellboard_1");
		snprintf(v[2], string_size, "bms_cellboard_discovery_cellboard_id_cellboard_2");
		snprintf(v[3], string_size, "bms_cellboard_discovery_cellboard_id_cellboard_3");
		snprintf(v[4], string_size, "bms_cellboard_discovery_cellboard_id_cellboard_4");
		snprintf(v[5], string_size, "bms_cellboard_discovery_cellboard_id_cellboard_5");

		return 0;
	case 58:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_cellboard_version_cellboard_id_cellboard_0");
		snprintf(v[1], string_size, "bms_cellboard_version_cellboard_id_cellboard_1");
		snprintf(v[2], string_size, "bms_cellboard_version_cellboard_id_cellboard_2");
		snprintf(v[3], string_size, "bms_cellboard_version_cellboard_id_cellboard_3");
		snprintf(v[4], string_size, "bms_cellboard_version_cellboard_id_cellboard_4");
		snprintf(v[5], string_size, "bms_cellboard_version_cellboard_id_cellboard_5");

		return 0;
	case 59:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_cellboard_status_cellboard_id_cellboard_0");
		snprintf(v[1], string_size, "bms_cellboard_status_cellboard_id_cellboard_1");
		snprintf(v[2], string_size, "bms_cellboard_status_cellboard_id_cellboard_2");
		snprintf(v[3], string_size, "bms_cellboard_status_cellboard_id_cellboard_3");
		snprintf(v[4], string_size, "bms_cellboard_status_cellboard_id_cellboard_4");
		snprintf(v[5], string_size, "bms_cellboard_status_cellboard_id_cellboard_5");

		return 0;
	case 60:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_cellboard_status_status_init");
		snprintf(v[1], string_size, "bms_cellboard_status_status_idle");
		snprintf(v[2], string_size, "bms_cellboard_status_status_fatal");
		snprintf(v[3], string_size, "bms_cellboard_status_status_flash");
		snprintf(v[4], string_size, "bms_cellboard_status_status_discharge");
		snprintf(v[5], string_size, "bms_cellboard_status_status_cooldown");

		return 0;
	case 61:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_cellboard_cells_voltage_cellboard_id_cellboard_0");
		snprintf(v[1], string_size, "bms_cellboard_cells_voltage_cellboard_id_cellboard_1");
		snprintf(v[2], string_size, "bms_cellboard_cells_voltage_cellboard_id_cellboard_2");
		snprintf(v[3], string_size, "bms_cellboard_cells_voltage_cellboard_id_cellboard_3");
		snprintf(v[4], string_size, "bms_cellboard_cells_voltage_cellboard_id_cellboard_4");
		snprintf(v[5], string_size, "bms_cellboard_cells_voltage_cellboard_id_cellboard_5");

		return 0;
	case 62:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_cellboard_cells_temperature_cellboard_id_cellboard_0");
		snprintf(v[1], string_size, "bms_cellboard_cells_temperature_cellboard_id_cellboard_1");
		snprintf(v[2], string_size, "bms_cellboard_cells_temperature_cellboard_id_cellboard_2");
		snprintf(v[3], string_size, "bms_cellboard_cells_temperature_cellboard_id_cellboard_3");
		snprintf(v[4], string_size, "bms_cellboard_cells_temperature_cellboard_id_cellboard_4");
		snprintf(v[5], string_size, "bms_cellboard_cells_temperature_cellboard_id_cellboard_5");

		return 0;
	case 63:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_cellboard_balancing_status_status_stopped");
		snprintf(v[1], string_size, "bms_cellboard_balancing_status_status_paused");
		snprintf(v[2], string_size, "bms_cellboard_balancing_status_status_running");

		return 0;
	case 64:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_cellboard_balancing_status_cellboard_id_cellboard_0");
		snprintf(v[1], string_size, "bms_cellboard_balancing_status_cellboard_id_cellboard_1");
		snprintf(v[2], string_size, "bms_cellboard_balancing_status_cellboard_id_cellboard_2");
		snprintf(v[3], string_size, "bms_cellboard_balancing_status_cellboard_id_cellboard_3");
		snprintf(v[4], string_size, "bms_cellboard_balancing_status_cellboard_id_cellboard_4");
		snprintf(v[5], string_size, "bms_cellboard_balancing_status_cellboard_id_cellboard_5");

		return 0;
	case 65:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_cellboard_errors_post_unset");
		snprintf(v[1], string_size, "bms_cellboard_errors_post_running");
		snprintf(v[2], string_size, "bms_cellboard_errors_post_expired");

		return 0;
	case 66:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_cellboard_errors_undervoltage_unset");
		snprintf(v[1], string_size, "bms_cellboard_errors_undervoltage_running");
		snprintf(v[2], string_size, "bms_cellboard_errors_undervoltage_expired");

		return 0;
	case 67:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_cellboard_errors_overvoltage_unset");
		snprintf(v[1], string_size, "bms_cellboard_errors_overvoltage_running");
		snprintf(v[2], string_size, "bms_cellboard_errors_overvoltage_expired");

		return 0;
	case 68:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_cellboard_errors_undertemperature_cells_unset");
		snprintf(v[1], string_size, "bms_cellboard_errors_undertemperature_cells_running");
		snprintf(v[2], string_size, "bms_cellboard_errors_undertemperature_cells_expired");

		return 0;
	case 69:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_cellboard_errors_undertemperature_discharge_unset");
		snprintf(v[1], string_size, "bms_cellboard_errors_undertemperature_discharge_running");
		snprintf(v[2], string_size, "bms_cellboard_errors_undertemperature_discharge_expired");

		return 0;
	case 70:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_cellboard_errors_overtemperature_cells_unset");
		snprintf(v[1], string_size, "bms_cellboard_errors_overtemperature_cells_running");
		snprintf(v[2], string_size, "bms_cellboard_errors_overtemperature_cells_expired");

		return 0;
	case 71:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_cellboard_errors_overtemperature_discharge_unset");
		snprintf(v[1], string_size, "bms_cellboard_errors_overtemperature_discharge_running");
		snprintf(v[2], string_size, "bms_cellboard_errors_overtemperature_discharge_expired");

		return 0;
	case 72:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_cellboard_errors_can_unset");
		snprintf(v[1], string_size, "bms_cellboard_errors_can_running");
		snprintf(v[2], string_size, "bms_cellboard_errors_can_expired");

		return 0;
	case 73:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_cellboard_errors_flash_unset");
		snprintf(v[1], string_size, "bms_cellboard_errors_flash_running");
		snprintf(v[2], string_size, "bms_cellboard_errors_flash_expired");

		return 0;
	case 74:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_cellboard_errors_bms_monitor_unset");
		snprintf(v[1], string_size, "bms_cellboard_errors_bms_monitor_running");
		snprintf(v[2], string_size, "bms_cellboard_errors_bms_monitor_expired");

		return 0;
	case 75:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "bms_cellboard_errors_open_wire_unset");
		snprintf(v[1], string_size, "bms_cellboard_errors_open_wire_running");
		snprintf(v[2], string_size, "bms_cellboard_errors_open_wire_expired");

		return 0;

    }
    return 0;
}
int bms_serialize_from_id(int id, char *s, uint8_t *data, size_t *size)
{
    switch(id)
    {
	case 1320:
	{
		bms_ivt_msg_result_wh_t tmp;
		bms_ivt_msg_result_wh_converted_t tmp_converted;
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
		tmp_converted.ivt_id_result_wh = (bms_ivt_msg_result_wh_ivt_id_result_wh)r_ivt_id_result_wh;
		tmp_converted.ivt_result_wh_system_error = (uint8_t)r_ivt_result_wh_system_error;
		tmp_converted.ivt_result_wh_measurement_error = (uint8_t)r_ivt_result_wh_measurement_error;
		tmp_converted.ivt_result_wh_channel_error = (uint8_t)r_ivt_result_wh_channel_error;
		tmp_converted.ivt_result_wh_ocs = (uint8_t)r_ivt_result_wh_ocs;
		tmp_converted.ivt_msgcount_result_wh = (uint8_t)r_ivt_msgcount_result_wh;
		tmp_converted.ivt_result_wh = (int32_t)r_ivt_result_wh;

		bms_ivt_msg_result_wh_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = BMS_IVT_MSG_RESULT_WH_BYTE_SIZE;
		return bms_ivt_msg_result_wh_pack(data, &tmp, BMS_IVT_MSG_RESULT_WH_BYTE_SIZE);
	}
	case 1319:
	{
		bms_ivt_msg_result_as_t tmp;
		bms_ivt_msg_result_as_converted_t tmp_converted;
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
		tmp_converted.ivt_id_result_as = (bms_ivt_msg_result_as_ivt_id_result_as)r_ivt_id_result_as;
		tmp_converted.ivt_result_as_system_error = (uint8_t)r_ivt_result_as_system_error;
		tmp_converted.ivt_result_as_measurement_error = (uint8_t)r_ivt_result_as_measurement_error;
		tmp_converted.ivt_result_as_channel_error = (uint8_t)r_ivt_result_as_channel_error;
		tmp_converted.ivt_result_as_ocs = (uint8_t)r_ivt_result_as_ocs;
		tmp_converted.ivt_msgcount_result_as = (uint8_t)r_ivt_msgcount_result_as;
		tmp_converted.ivt_result_as = (int32_t)r_ivt_result_as;

		bms_ivt_msg_result_as_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = BMS_IVT_MSG_RESULT_AS_BYTE_SIZE;
		return bms_ivt_msg_result_as_pack(data, &tmp, BMS_IVT_MSG_RESULT_AS_BYTE_SIZE);
	}
	case 1318:
	{
		bms_ivt_msg_result_w_t tmp;
		bms_ivt_msg_result_w_converted_t tmp_converted;
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
		tmp_converted.ivt_id_result_w = (bms_ivt_msg_result_w_ivt_id_result_w)r_ivt_id_result_w;
		tmp_converted.ivt_result_w_system_error = (uint8_t)r_ivt_result_w_system_error;
		tmp_converted.ivt_result_w_measurement_error = (uint8_t)r_ivt_result_w_measurement_error;
		tmp_converted.ivt_result_w_channel_error = (uint8_t)r_ivt_result_w_channel_error;
		tmp_converted.ivt_result_w_ocs = (uint8_t)r_ivt_result_w_ocs;
		tmp_converted.ivt_msgcount_result_w = (uint8_t)r_ivt_msgcount_result_w;
		tmp_converted.ivt_result_w = (int32_t)r_ivt_result_w;

		bms_ivt_msg_result_w_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = BMS_IVT_MSG_RESULT_W_BYTE_SIZE;
		return bms_ivt_msg_result_w_pack(data, &tmp, BMS_IVT_MSG_RESULT_W_BYTE_SIZE);
	}
	case 1297:
	{
		bms_ivt_msg_response_t tmp;
		bms_ivt_msg_response_converted_t tmp_converted;
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
		tmp_converted.ivt_id_response = (bms_ivt_msg_response_ivt_id_response)r_ivt_id_response;
		tmp_converted._b1_trigger_spare = (uint8_t)r__b1_trigger_spare;
		tmp_converted._ff_wrong_command = (uint8_t)r__ff_wrong_command;
		tmp_converted._bf_restart_alive_cmd_id = (uint16_t)r__bf_restart_alive_cmd_id;
		tmp_converted._80_resp_measerror_item = (bms_ivt_msg_response__80_resp_measerror_item)r__80_resp_measerror_item;
		tmp_converted._81_resp_systemerror_item = (bms_ivt_msg_response__81_resp_systemerror_item)r__81_resp_systemerror_item;
		tmp_converted._82_resp_alllogdata_item = (bms_ivt_msg_response__82_resp_alllogdata_item)r__82_resp_alllogdata_item;
		tmp_converted._83_resp_logdata_item = (bms_ivt_msg_response__83_resp_logdata_item)r__83_resp_logdata_item;
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
		tmp_converted._b0_resp_reset_item = (bms_ivt_msg_response__b0_resp_reset_item)r__b0_resp_reset_item;
		tmp_converted._b2_resp_store_dummy = (uint8_t)r__b2_resp_store_dummy;
		tmp_converted._b3_resp_oc_test_time = (uint16_t)r__b3_resp_oc_test_time;
		tmp_converted._b5_resp_oc_pos_set_threshold = (int16_t)r__b5_resp_oc_pos_set_threshold;
		tmp_converted._b6_resp_oc_neg_set_threshold = (int16_t)r__b6_resp_oc_neg_set_threshold;
		tmp_converted._b9_resp_device_type = (bms_ivt_msg_response__b9_resp_device_type)r__b9_resp_device_type;
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
		tmp_converted._a0_resp_triggermode_i = (bms_ivt_msg_response__a0_resp_triggermode_i)r__a0_resp_triggermode_i;
		tmp_converted._a1_resp_triggermode_u1 = (bms_ivt_msg_response__a1_resp_triggermode_u1)r__a1_resp_triggermode_u1;
		tmp_converted._a2_resp_triggermode_u2 = (bms_ivt_msg_response__a2_resp_triggermode_u2)r__a2_resp_triggermode_u2;
		tmp_converted._a3_resp_triggermode_u3 = (bms_ivt_msg_response__a3_resp_triggermode_u3)r__a3_resp_triggermode_u3;
		tmp_converted._a4_resp_triggermode_t = (bms_ivt_msg_response__a4_resp_triggermode_t)r__a4_resp_triggermode_t;
		tmp_converted._a5_resp_triggermode_w = (bms_ivt_msg_response__a5_resp_triggermode_w)r__a5_resp_triggermode_w;
		tmp_converted._a6_resp_triggermode_as = (bms_ivt_msg_response__a6_resp_triggermode_as)r__a6_resp_triggermode_as;
		tmp_converted._a7_resp_triggermode_wh = (bms_ivt_msg_response__a7_resp_triggermode_wh)r__a7_resp_triggermode_wh;
		tmp_converted._b4_resp_actual_mode = (bms_ivt_msg_response__b4_resp_actual_mode)r__b4_resp_actual_mode;
		tmp_converted._b1_07_trigger_wh = (uint8_t)r__b1_07_trigger_wh;
		tmp_converted._b2_resp_store_device_sn = (uint32_t)r__b2_resp_store_device_sn;
		tmp_converted._ba_resp_sw_ver_minor = (uint8_t)r__ba_resp_sw_ver_minor;
		tmp_converted._b9_resp_device_current = (bms_ivt_msg_response__b9_resp_device_current)r__b9_resp_device_current;
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
		tmp_converted._b4_resp_startup_mode = (bms_ivt_msg_response__b4_resp_startup_mode)r__b4_resp_startup_mode;
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
		tmp_converted._b9_resp_device_voltage_chan = (bms_ivt_msg_response__b9_resp_device_voltage_chan)r__b9_resp_device_voltage_chan;
		tmp_converted._ba_resp_sw_ver_vear = (uint8_t)r__ba_resp_sw_ver_vear;
		tmp_converted._b9_resp_device_toi = (bms_ivt_msg_response__b9_resp_device_toi)r__b9_resp_device_toi;
		tmp_converted._ba_resp_sw_ver_month = (int8_t)r__ba_resp_sw_ver_month;
		tmp_converted._b9_resp_device_com = (bms_ivt_msg_response__b9_resp_device_com)r__b9_resp_device_com;
		tmp_converted._ba_resp_sw_ver_day = (uint8_t)r__ba_resp_sw_ver_day;
		tmp_converted._b9_resp_device_v_supply = (bms_ivt_msg_response__b9_resp_device_v_supply)r__b9_resp_device_v_supply;
		tmp_converted._ba_resp_sw_ver_internal = (uint8_t)r__ba_resp_sw_ver_internal;

		bms_ivt_msg_response_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = BMS_IVT_MSG_RESPONSE_BYTE_SIZE;
		return bms_ivt_msg_response_pack(data, &tmp, BMS_IVT_MSG_RESPONSE_BYTE_SIZE);
	}
	case 1317:
	{
		bms_ivt_msg_result_t_t tmp;
		bms_ivt_msg_result_t_converted_t tmp_converted;
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
		tmp_converted.ivt_id_result_t = (bms_ivt_msg_result_t_ivt_id_result_t)r_ivt_id_result_t;
		tmp_converted.ivt_result_t_system_error = (uint8_t)r_ivt_result_t_system_error;
		tmp_converted.ivt_result_t_measurement_error = (uint8_t)r_ivt_result_t_measurement_error;
		tmp_converted.ivt_result_t_channel_error = (uint8_t)r_ivt_result_t_channel_error;
		tmp_converted.ivt_result_t_ocs = (uint8_t)r_ivt_result_t_ocs;
		tmp_converted.ivt_msgcount_result_t = (uint8_t)r_ivt_msgcount_result_t;
		tmp_converted.ivt_result_t = (float)r_ivt_result_t;

		bms_ivt_msg_result_t_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = BMS_IVT_MSG_RESULT_T_BYTE_SIZE;
		return bms_ivt_msg_result_t_pack(data, &tmp, BMS_IVT_MSG_RESULT_T_BYTE_SIZE);
	}
	case 1316:
	{
		bms_ivt_msg_result_u3_t tmp;
		bms_ivt_msg_result_u3_converted_t tmp_converted;
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
		tmp_converted.ivt_id_result_u3 = (bms_ivt_msg_result_u3_ivt_id_result_u3)r_ivt_id_result_u3;
		tmp_converted.ivt_result_u3_system_error = (uint8_t)r_ivt_result_u3_system_error;
		tmp_converted.ivt_result_u3_measurement_error = (uint8_t)r_ivt_result_u3_measurement_error;
		tmp_converted.ivt_result_u3_channel_error = (uint8_t)r_ivt_result_u3_channel_error;
		tmp_converted.ivt_result_u3_ocs = (uint8_t)r_ivt_result_u3_ocs;
		tmp_converted.ivt_msgcount_result_u3 = (uint8_t)r_ivt_msgcount_result_u3;
		tmp_converted.ivt_result_u3 = (int32_t)r_ivt_result_u3;

		bms_ivt_msg_result_u3_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = BMS_IVT_MSG_RESULT_U3_BYTE_SIZE;
		return bms_ivt_msg_result_u3_pack(data, &tmp, BMS_IVT_MSG_RESULT_U3_BYTE_SIZE);
	}
	case 1315:
	{
		bms_ivt_msg_result_u2_t tmp;
		bms_ivt_msg_result_u2_converted_t tmp_converted;
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
		tmp_converted.ivt_id_result_u2 = (bms_ivt_msg_result_u2_ivt_id_result_u2)r_ivt_id_result_u2;
		tmp_converted.ivt_result_u2_system_error = (uint8_t)r_ivt_result_u2_system_error;
		tmp_converted.ivt_result_u2_measurement_error = (uint8_t)r_ivt_result_u2_measurement_error;
		tmp_converted.ivt_result_u2_channel_error = (uint8_t)r_ivt_result_u2_channel_error;
		tmp_converted.ivt_result_u2_ocs = (uint8_t)r_ivt_result_u2_ocs;
		tmp_converted.ivt_msgcount_result_u2 = (uint8_t)r_ivt_msgcount_result_u2;
		tmp_converted.ivt_result_u2 = (int32_t)r_ivt_result_u2;

		bms_ivt_msg_result_u2_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = BMS_IVT_MSG_RESULT_U2_BYTE_SIZE;
		return bms_ivt_msg_result_u2_pack(data, &tmp, BMS_IVT_MSG_RESULT_U2_BYTE_SIZE);
	}
	case 1314:
	{
		bms_ivt_msg_result_u1_t tmp;
		bms_ivt_msg_result_u1_converted_t tmp_converted;
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
		tmp_converted.ivt_id_result_u1 = (bms_ivt_msg_result_u1_ivt_id_result_u1)r_ivt_id_result_u1;
		tmp_converted.ivt_result_u1_system_error = (uint8_t)r_ivt_result_u1_system_error;
		tmp_converted.ivt_result_u1_measurement_error = (uint8_t)r_ivt_result_u1_measurement_error;
		tmp_converted.ivt_result_u1_channel_error = (uint8_t)r_ivt_result_u1_channel_error;
		tmp_converted.ivt_result_u1_ocs = (uint8_t)r_ivt_result_u1_ocs;
		tmp_converted.ivt_msgcount_result_u1 = (uint8_t)r_ivt_msgcount_result_u1;
		tmp_converted.ivt_result_u1 = (int32_t)r_ivt_result_u1;

		bms_ivt_msg_result_u1_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = BMS_IVT_MSG_RESULT_U1_BYTE_SIZE;
		return bms_ivt_msg_result_u1_pack(data, &tmp, BMS_IVT_MSG_RESULT_U1_BYTE_SIZE);
	}
	case 1313:
	{
		bms_ivt_msg_result_i_t tmp;
		bms_ivt_msg_result_i_converted_t tmp_converted;
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
		tmp_converted.ivt_id_result_i = (bms_ivt_msg_result_i_ivt_id_result_i)r_ivt_id_result_i;
		tmp_converted.ivt_result_i_system_error = (uint8_t)r_ivt_result_i_system_error;
		tmp_converted.ivt_result_i_measurement_error = (uint8_t)r_ivt_result_i_measurement_error;
		tmp_converted.ivt_result_i_channel_error = (uint8_t)r_ivt_result_i_channel_error;
		tmp_converted.ivt_result_i_ocs = (uint8_t)r_ivt_result_i_ocs;
		tmp_converted.ivt_msgcount_result_i = (uint8_t)r_ivt_msgcount_result_i;
		tmp_converted.ivt_result_i = (int32_t)r_ivt_result_i;

		bms_ivt_msg_result_i_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = BMS_IVT_MSG_RESULT_I_BYTE_SIZE;
		return bms_ivt_msg_result_i_pack(data, &tmp, BMS_IVT_MSG_RESULT_I_BYTE_SIZE);
	}
	case 1041:
	{
		bms_ivt_msg_cmd_t tmp;
		bms_ivt_msg_cmd_converted_t tmp_converted;
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
		tmp_converted.ivt_id_cmd = (bms_ivt_msg_cmd_ivt_id_cmd)r_ivt_id_cmd;
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
		tmp_converted._30_reset_item = (bms_ivt_msg_cmd__30_reset_item)r__30_reset_item;
		tmp_converted._32_store_dummy = (uint8_t)r__32_store_dummy;
		tmp_converted._33_oc_test_time = (uint16_t)r__33_oc_test_time;
		tmp_converted._35_oc_pos_set_threshold = (int16_t)r__35_oc_pos_set_threshold;
		tmp_converted._36_oc_neg_set_threshold = (int16_t)r__36_oc_neg_set_threshold;
		tmp_converted._3a_restart_to_bitrate = (bms_ivt_msg_cmd__3a_restart_to_bitrate)r__3a_restart_to_bitrate;
		tmp_converted._3d_restart_default_dummy = (uint8_t)r__3d_restart_default_dummy;
		tmp_converted._3f_restart_dummy = (uint8_t)r__3f_restart_dummy;
		tmp_converted._40_get_measerror_item = (bms_ivt_msg_cmd__40_get_measerror_item)r__40_get_measerror_item;
		tmp_converted._41_get_systemerror_item = (bms_ivt_msg_cmd__41_get_systemerror_item)r__41_get_systemerror_item;
		tmp_converted._42_get_alllogdata_item = (bms_ivt_msg_cmd__42_get_alllogdata_item)r__42_get_alllogdata_item;
		tmp_converted._43_get_logdata_item = (bms_ivt_msg_cmd__43_get_logdata_item)r__43_get_logdata_item;
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
		tmp_converted._20_conf_triggermode_i = (bms_ivt_msg_cmd__20_conf_triggermode_i)r__20_conf_triggermode_i;
		tmp_converted._21_conf_triggermode_u1 = (bms_ivt_msg_cmd__21_conf_triggermode_u1)r__21_conf_triggermode_u1;
		tmp_converted._22_conf_triggermode_u2 = (bms_ivt_msg_cmd__22_conf_triggermode_u2)r__22_conf_triggermode_u2;
		tmp_converted._23_conf_triggermode_u3 = (bms_ivt_msg_cmd__23_conf_triggermode_u3)r__23_conf_triggermode_u3;
		tmp_converted._24_conf_triggermode_t = (bms_ivt_msg_cmd__24_conf_triggermode_t)r__24_conf_triggermode_t;
		tmp_converted._25_conf_triggermode_w = (bms_ivt_msg_cmd__25_conf_triggermode_w)r__25_conf_triggermode_w;
		tmp_converted._26_conf_triggermode_as = (bms_ivt_msg_cmd__26_conf_triggermode_as)r__26_conf_triggermode_as;
		tmp_converted._27_conf_triggermode_wh = (bms_ivt_msg_cmd__27_conf_triggermode_wh)r__27_conf_triggermode_wh;
		tmp_converted._34_actual_mode = (bms_ivt_msg_cmd__34_actual_mode)r__34_actual_mode;
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
		tmp_converted._34_startup_mode = (bms_ivt_msg_cmd__34_startup_mode)r__34_startup_mode;
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

		bms_ivt_msg_cmd_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = BMS_IVT_MSG_CMD_BYTE_SIZE;
		return bms_ivt_msg_cmd_pack(data, &tmp, BMS_IVT_MSG_CMD_BYTE_SIZE);
	}
	case 1026:
	{
		bms_board_status_t tmp;
		bms_board_status_converted_t tmp_converted;
		uint8_t r_cellboard_id;
		uint8_t r_errors_can_comm;
		uint8_t r_errors_ltc_comm;
		uint8_t r_errors_temp_comm_0;
		uint8_t r_errors_temp_comm_1;
		uint8_t r_errors_temp_comm_2;
		uint8_t r_errors_temp_comm_3;
		uint8_t r_errors_temp_comm_4;
		uint8_t r_errors_temp_comm_5;
		uint8_t r_errors_open_wire;
		uint8_t r_balancing_status;
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
			&r_errors_can_comm,
			&r_errors_ltc_comm,
			&r_errors_temp_comm_0,
			&r_errors_temp_comm_1,
			&r_errors_temp_comm_2,
			&r_errors_temp_comm_3,
			&r_errors_temp_comm_4,
			&r_errors_temp_comm_5,
			&r_errors_open_wire,
			&r_balancing_status,
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
		tmp_converted.cellboard_id = (bms_board_status_cellboard_id)r_cellboard_id;
		tmp_converted.errors_can_comm = (uint8_t)r_errors_can_comm;
		tmp_converted.errors_ltc_comm = (uint8_t)r_errors_ltc_comm;
		tmp_converted.errors_temp_comm_0 = (uint8_t)r_errors_temp_comm_0;
		tmp_converted.errors_temp_comm_1 = (uint8_t)r_errors_temp_comm_1;
		tmp_converted.errors_temp_comm_2 = (uint8_t)r_errors_temp_comm_2;
		tmp_converted.errors_temp_comm_3 = (uint8_t)r_errors_temp_comm_3;
		tmp_converted.errors_temp_comm_4 = (uint8_t)r_errors_temp_comm_4;
		tmp_converted.errors_temp_comm_5 = (uint8_t)r_errors_temp_comm_5;
		tmp_converted.errors_open_wire = (uint8_t)r_errors_open_wire;
		tmp_converted.balancing_status = (bms_board_status_balancing_status)r_balancing_status;
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

		bms_board_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = BMS_BOARD_STATUS_BYTE_SIZE;
		return bms_board_status_pack(data, &tmp, BMS_BOARD_STATUS_BYTE_SIZE);
	}
	case 515:
	{
		bms_temperatures_info_t tmp;
		bms_temperatures_info_converted_t tmp_converted;
		uint8_t r_cellboard_id;
		float r_min_temp;
		float r_max_temp;
		float r_avg_temp;

		sscanf(s, "%" SCNu8 ","  
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_cellboard_id,
			&r_min_temp,
			&r_max_temp,
			&r_avg_temp);
		tmp_converted.cellboard_id = (bms_temperatures_info_cellboard_id)r_cellboard_id;
		tmp_converted.min_temp = (float)r_min_temp;
		tmp_converted.max_temp = (float)r_max_temp;
		tmp_converted.avg_temp = (float)r_avg_temp;

		bms_temperatures_info_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = BMS_TEMPERATURES_INFO_BYTE_SIZE;
		return bms_temperatures_info_pack(data, &tmp, BMS_TEMPERATURES_INFO_BYTE_SIZE);
	}
	case 1539:
	{
		bms_temperatures_t tmp;
		bms_temperatures_converted_t tmp_converted;
		uint8_t r_cellboard_id;
		uint8_t r_start_index;
		float r_temp0;
		float r_temp1;
		float r_temp2;
		float r_temp3;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  
			"%f,"       
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_cellboard_id,
			&r_start_index,
			&r_temp0,
			&r_temp1,
			&r_temp2,
			&r_temp3);
		tmp_converted.cellboard_id = (bms_temperatures_cellboard_id)r_cellboard_id;
		tmp_converted.start_index = (uint8_t)r_start_index;
		tmp_converted.temp0 = (float)r_temp0;
		tmp_converted.temp1 = (float)r_temp1;
		tmp_converted.temp2 = (float)r_temp2;
		tmp_converted.temp3 = (float)r_temp3;

		bms_temperatures_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = BMS_TEMPERATURES_BYTE_SIZE;
		return bms_temperatures_pack(data, &tmp, BMS_TEMPERATURES_BYTE_SIZE);
	}
	case 516:
	{
		bms_voltages_info_t tmp;
		bms_voltages_info_converted_t tmp_converted;
		uint8_t r_cellboard_id;
		float r_min_voltage;
		float r_max_voltage;
		float r_avg_voltage;

		sscanf(s, "%" SCNu8 ","  
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_cellboard_id,
			&r_min_voltage,
			&r_max_voltage,
			&r_avg_voltage);
		tmp_converted.cellboard_id = (bms_voltages_info_cellboard_id)r_cellboard_id;
		tmp_converted.min_voltage = (float)r_min_voltage;
		tmp_converted.max_voltage = (float)r_max_voltage;
		tmp_converted.avg_voltage = (float)r_avg_voltage;

		bms_voltages_info_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = BMS_VOLTAGES_INFO_BYTE_SIZE;
		return bms_voltages_info_pack(data, &tmp, BMS_VOLTAGES_INFO_BYTE_SIZE);
	}
	case 1540:
	{
		bms_voltages_t tmp;
		bms_voltages_converted_t tmp_converted;
		uint8_t r_cellboard_id;
		uint8_t r_start_index;
		float r_voltage0;
		float r_voltage1;
		float r_voltage2;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_cellboard_id,
			&r_start_index,
			&r_voltage0,
			&r_voltage1,
			&r_voltage2);
		tmp_converted.cellboard_id = (bms_voltages_cellboard_id)r_cellboard_id;
		tmp_converted.start_index = (uint8_t)r_start_index;
		tmp_converted.voltage0 = (float)r_voltage0;
		tmp_converted.voltage1 = (float)r_voltage1;
		tmp_converted.voltage2 = (float)r_voltage2;

		bms_voltages_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = BMS_VOLTAGES_BYTE_SIZE;
		return bms_voltages_pack(data, &tmp, BMS_VOLTAGES_BYTE_SIZE);
	}
	case 16:
	{
		bms_set_balancing_status_t tmp;
		bms_set_balancing_status_converted_t tmp_converted;
		uint16_t r_threshold;
		uint16_t r_target;
		uint8_t r_balancing_status;

		sscanf(s, "%" SCNu16 "," 
			"%" SCNu16 "," 
			"%" SCNu8 ","  ,
			&r_threshold,
			&r_target,
			&r_balancing_status);
		tmp_converted.threshold = (uint16_t)r_threshold;
		tmp_converted.target = (uint16_t)r_target;
		tmp_converted.balancing_status = (bms_set_balancing_status_balancing_status)r_balancing_status;

		bms_set_balancing_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = BMS_SET_BALANCING_STATUS_BYTE_SIZE;
		return bms_set_balancing_status_pack(data, &tmp, BMS_SET_BALANCING_STATUS_BYTE_SIZE);
	}
	case 0:
	{
		bms_cellboard_flash_t tmp;
		bms_cellboard_flash_converted_t tmp_converted;
		uint8_t r_start;
		uint8_t r_cellboard_id;
		uint8_t r_board_index;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  ,
			&r_start,
			&r_cellboard_id,
			&r_board_index);
		tmp_converted.start = (uint8_t)r_start;
		tmp_converted.cellboard_id = (bms_cellboard_flash_cellboard_id)r_cellboard_id;
		tmp_converted.board_index = (uint8_t)r_board_index;

		bms_cellboard_flash_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = BMS_CELLBOARD_FLASH_BYTE_SIZE;
		return bms_cellboard_flash_pack(data, &tmp, BMS_CELLBOARD_FLASH_BYTE_SIZE);
	}
	case 3:
	{
		bms_cellboard_flash_request_t tmp;
		bms_cellboard_flash_request_converted_t tmp_converted;
		uint8_t r_mainboard;
		uint8_t r_cellboard_id;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  ,
			&r_mainboard,
			&r_cellboard_id);
		tmp_converted.mainboard = (uint8_t)r_mainboard;
		tmp_converted.cellboard_id = (bms_cellboard_flash_request_cellboard_id)r_cellboard_id;

		bms_cellboard_flash_request_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = BMS_CELLBOARD_FLASH_REQUEST_BYTE_SIZE;
		return bms_cellboard_flash_request_pack(data, &tmp, BMS_CELLBOARD_FLASH_REQUEST_BYTE_SIZE);
	}
	case 4:
	{
		bms_cellboard_flash_response_t tmp;
		bms_cellboard_flash_response_converted_t tmp_converted;
		uint8_t r_cellboard_id;
		uint8_t r_ready;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  ,
			&r_cellboard_id,
			&r_ready);
		tmp_converted.cellboard_id = (bms_cellboard_flash_response_cellboard_id)r_cellboard_id;
		tmp_converted.ready = (uint8_t)r_ready;

		bms_cellboard_flash_response_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = BMS_CELLBOARD_FLASH_RESPONSE_BYTE_SIZE;
		return bms_cellboard_flash_response_pack(data, &tmp, BMS_CELLBOARD_FLASH_RESPONSE_BYTE_SIZE);
	}
	case 1537:
	{
		bms_cellboard_discovery_t tmp;
		bms_cellboard_discovery_converted_t tmp_converted;
		uint8_t r_cellboard_id;

		sscanf(s, "%" SCNu8 ","  ,
			&r_cellboard_id);
		tmp_converted.cellboard_id = (bms_cellboard_discovery_cellboard_id)r_cellboard_id;

		bms_cellboard_discovery_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = BMS_CELLBOARD_DISCOVERY_BYTE_SIZE;
		return bms_cellboard_discovery_pack(data, &tmp, BMS_CELLBOARD_DISCOVERY_BYTE_SIZE);
	}
	case 1545:
	{
		bms_cellboard_version_t tmp;
		bms_cellboard_version_converted_t tmp_converted;
		uint8_t r_cellboard_id;
		uint32_t r_canlib_build_time;
		uint32_t r_component_build_time;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu32 "," 
			"%" SCNu32 "," ,
			&r_cellboard_id,
			&r_canlib_build_time,
			&r_component_build_time);
		tmp_converted.cellboard_id = (bms_cellboard_version_cellboard_id)r_cellboard_id;
		tmp_converted.canlib_build_time = (uint32_t)r_canlib_build_time;
		tmp_converted.component_build_time = (uint32_t)r_component_build_time;

		bms_cellboard_version_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = BMS_CELLBOARD_VERSION_BYTE_SIZE;
		return bms_cellboard_version_pack(data, &tmp, BMS_CELLBOARD_VERSION_BYTE_SIZE);
	}
	case 513:
	{
		bms_cellboard_status_t tmp;
		bms_cellboard_status_converted_t tmp_converted;
		uint8_t r_cellboard_id;
		uint8_t r_status;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  ,
			&r_cellboard_id,
			&r_status);
		tmp_converted.cellboard_id = (bms_cellboard_status_cellboard_id)r_cellboard_id;
		tmp_converted.status = (bms_cellboard_status_status)r_status;

		bms_cellboard_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = BMS_CELLBOARD_STATUS_BYTE_SIZE;
		return bms_cellboard_status_pack(data, &tmp, BMS_CELLBOARD_STATUS_BYTE_SIZE);
	}
	case 1553:
	{
		bms_cellboard_cells_voltage_t tmp;
		bms_cellboard_cells_voltage_converted_t tmp_converted;
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
		tmp_converted.cellboard_id = (bms_cellboard_cells_voltage_cellboard_id)r_cellboard_id;
		tmp_converted.offset = (uint8_t)r_offset;
		tmp_converted.voltage_0 = (float)r_voltage_0;
		tmp_converted.voltage_1 = (float)r_voltage_1;
		tmp_converted.voltage_2 = (float)r_voltage_2;

		bms_cellboard_cells_voltage_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = BMS_CELLBOARD_CELLS_VOLTAGE_BYTE_SIZE;
		return bms_cellboard_cells_voltage_pack(data, &tmp, BMS_CELLBOARD_CELLS_VOLTAGE_BYTE_SIZE);
	}
	case 1561:
	{
		bms_cellboard_cells_temperature_t tmp;
		bms_cellboard_cells_temperature_converted_t tmp_converted;
		uint8_t r_cellboard_id;
		uint8_t r_offset;
		float r_temperature_0;
		float r_temperature_1;
		float r_temperature_2;
		float r_temperature_3;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  
			"%f,"       
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_cellboard_id,
			&r_offset,
			&r_temperature_0,
			&r_temperature_1,
			&r_temperature_2,
			&r_temperature_3);
		tmp_converted.cellboard_id = (bms_cellboard_cells_temperature_cellboard_id)r_cellboard_id;
		tmp_converted.offset = (uint8_t)r_offset;
		tmp_converted.temperature_0 = (float)r_temperature_0;
		tmp_converted.temperature_1 = (float)r_temperature_1;
		tmp_converted.temperature_2 = (float)r_temperature_2;
		tmp_converted.temperature_3 = (float)r_temperature_3;

		bms_cellboard_cells_temperature_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = BMS_CELLBOARD_CELLS_TEMPERATURE_BYTE_SIZE;
		return bms_cellboard_cells_temperature_pack(data, &tmp, BMS_CELLBOARD_CELLS_TEMPERATURE_BYTE_SIZE);
	}
	case 1025:
	{
		bms_cellboard_set_balancing_status_t tmp;
		bms_cellboard_set_balancing_status_converted_t tmp_converted;
		uint8_t r_start;
		float r_target;
		float r_threshold;

		sscanf(s, "%" SCNu8 ","  
			"%f,"       
			"%f,"       ,
			&r_start,
			&r_target,
			&r_threshold);
		tmp_converted.start = (uint8_t)r_start;
		tmp_converted.target = (float)r_target;
		tmp_converted.threshold = (float)r_threshold;

		bms_cellboard_set_balancing_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = BMS_CELLBOARD_SET_BALANCING_STATUS_BYTE_SIZE;
		return bms_cellboard_set_balancing_status_pack(data, &tmp, BMS_CELLBOARD_SET_BALANCING_STATUS_BYTE_SIZE);
	}
	case 1569:
	{
		bms_cellboard_balancing_status_t tmp;
		bms_cellboard_balancing_status_converted_t tmp_converted;
		uint8_t r_status;
		uint8_t r_cellboard_id;
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
			"%" SCNu8 ","  ,
			&r_status,
			&r_cellboard_id,
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
		tmp_converted.status = (bms_cellboard_balancing_status_status)r_status;
		tmp_converted.cellboard_id = (bms_cellboard_balancing_status_cellboard_id)r_cellboard_id;
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

		bms_cellboard_balancing_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = BMS_CELLBOARD_BALANCING_STATUS_BYTE_SIZE;
		return bms_cellboard_balancing_status_pack(data, &tmp, BMS_CELLBOARD_BALANCING_STATUS_BYTE_SIZE);
	}
	case 521:
	{
		bms_cellboard_errors_t tmp;
		bms_cellboard_errors_converted_t tmp_converted;
		uint8_t r_post;
		uint8_t r_undervoltage;
		uint8_t r_overvoltage;
		uint8_t r_undertemperature_cells;
		uint8_t r_undertemperature_discharge;
		uint8_t r_overtemperature_cells;
		uint8_t r_overtemperature_discharge;
		uint8_t r_can;
		uint8_t r_flash;
		uint8_t r_bms_monitor;
		uint8_t r_open_wire;

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
			&r_post,
			&r_undervoltage,
			&r_overvoltage,
			&r_undertemperature_cells,
			&r_undertemperature_discharge,
			&r_overtemperature_cells,
			&r_overtemperature_discharge,
			&r_can,
			&r_flash,
			&r_bms_monitor,
			&r_open_wire);
		tmp_converted.post = (bms_cellboard_errors_post)r_post;
		tmp_converted.undervoltage = (bms_cellboard_errors_undervoltage)r_undervoltage;
		tmp_converted.overvoltage = (bms_cellboard_errors_overvoltage)r_overvoltage;
		tmp_converted.undertemperature_cells = (bms_cellboard_errors_undertemperature_cells)r_undertemperature_cells;
		tmp_converted.undertemperature_discharge = (bms_cellboard_errors_undertemperature_discharge)r_undertemperature_discharge;
		tmp_converted.overtemperature_cells = (bms_cellboard_errors_overtemperature_cells)r_overtemperature_cells;
		tmp_converted.overtemperature_discharge = (bms_cellboard_errors_overtemperature_discharge)r_overtemperature_discharge;
		tmp_converted.can = (bms_cellboard_errors_can)r_can;
		tmp_converted.flash = (bms_cellboard_errors_flash)r_flash;
		tmp_converted.bms_monitor = (bms_cellboard_errors_bms_monitor)r_bms_monitor;
		tmp_converted.open_wire = (bms_cellboard_errors_open_wire)r_open_wire;

		bms_cellboard_errors_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = BMS_CELLBOARD_ERRORS_BYTE_SIZE;
		return bms_cellboard_errors_pack(data, &tmp, BMS_CELLBOARD_ERRORS_BYTE_SIZE);
	}

    }
    return 0;
}
int bms_n_fields_from_id(int id)
{
	switch(id)
    {
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
		case 1026: return 29;
		case 515: return 4;
		case 1539: return 6;
		case 516: return 4;
		case 1540: return 5;
		case 16: return 3;
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
		case 0: return 3;
		case 1: return 0;
		case 2: return 0;
		case 3: return 2;
		case 4: return 2;
		case 1537: return 1;
		case 1545: return 3;
		case 513: return 2;
		case 1553: return 5;
		case 1561: return 6;
		case 1025: return 3;
		case 1569: return 26;
		case 521: return 11;
    }
    return 0;
}
int bms_fields_types_from_id(int id, int* fields_types, int fields_types_size)
{
    switch(id)
    {
	case 1320:
		if(fields_types_size < 7) return 0;
		fields_types[0] = e_bms_ivt_msg_result_wh_ivt_id_result_wh;
		fields_types[1] = e_bms_uint8_t;
		fields_types[2] = e_bms_uint8_t;
		fields_types[3] = e_bms_uint8_t;
		fields_types[4] = e_bms_uint8_t;
		fields_types[5] = e_bms_uint8_t;
		fields_types[6] = e_bms_int32_t;
		return 7;
	case 1319:
		if(fields_types_size < 7) return 0;
		fields_types[0] = e_bms_ivt_msg_result_as_ivt_id_result_as;
		fields_types[1] = e_bms_uint8_t;
		fields_types[2] = e_bms_uint8_t;
		fields_types[3] = e_bms_uint8_t;
		fields_types[4] = e_bms_uint8_t;
		fields_types[5] = e_bms_uint8_t;
		fields_types[6] = e_bms_int32_t;
		return 7;
	case 1318:
		if(fields_types_size < 7) return 0;
		fields_types[0] = e_bms_ivt_msg_result_w_ivt_id_result_w;
		fields_types[1] = e_bms_uint8_t;
		fields_types[2] = e_bms_uint8_t;
		fields_types[3] = e_bms_uint8_t;
		fields_types[4] = e_bms_uint8_t;
		fields_types[5] = e_bms_uint8_t;
		fields_types[6] = e_bms_int32_t;
		return 7;
	case 1297:
		if(fields_types_size < 100) return 0;
		fields_types[0] = e_bms_ivt_msg_response_ivt_id_response;
		fields_types[1] = e_bms_uint8_t;
		fields_types[2] = e_bms_uint8_t;
		fields_types[3] = e_bms_uint16_t;
		fields_types[4] = e_bms_ivt_msg_response__80_resp_measerror_item;
		fields_types[5] = e_bms_ivt_msg_response__81_resp_systemerror_item;
		fields_types[6] = e_bms_ivt_msg_response__82_resp_alllogdata_item;
		fields_types[7] = e_bms_ivt_msg_response__83_resp_logdata_item;
		fields_types[8] = e_bms_uint16_t;
		fields_types[9] = e_bms_uint16_t;
		fields_types[10] = e_bms_uint16_t;
		fields_types[11] = e_bms_uint16_t;
		fields_types[12] = e_bms_uint16_t;
		fields_types[13] = e_bms_uint16_t;
		fields_types[14] = e_bms_uint16_t;
		fields_types[15] = e_bms_uint16_t;
		fields_types[16] = e_bms_uint16_t;
		fields_types[17] = e_bms_uint16_t;
		fields_types[18] = e_bms_uint8_t;
		fields_types[19] = e_bms_uint8_t;
		fields_types[20] = e_bms_uint8_t;
		fields_types[21] = e_bms_uint8_t;
		fields_types[22] = e_bms_uint8_t;
		fields_types[23] = e_bms_uint8_t;
		fields_types[24] = e_bms_uint8_t;
		fields_types[25] = e_bms_uint8_t;
		fields_types[26] = e_bms_ivt_msg_response__b0_resp_reset_item;
		fields_types[27] = e_bms_uint8_t;
		fields_types[28] = e_bms_uint16_t;
		fields_types[29] = e_bms_int16_t;
		fields_types[30] = e_bms_int16_t;
		fields_types[31] = e_bms_ivt_msg_response__b9_resp_device_type;
		fields_types[32] = e_bms_uint8_t;
		fields_types[33] = e_bms_uint32_t;
		fields_types[34] = e_bms_uint64_t;
		fields_types[35] = e_bms_uint8_t;
		fields_types[36] = e_bms_uint8_t;
		fields_types[37] = e_bms_uint8_t;
		fields_types[38] = e_bms_uint8_t;
		fields_types[39] = e_bms_uint8_t;
		fields_types[40] = e_bms_uint8_t;
		fields_types[41] = e_bms_uint8_t;
		fields_types[42] = e_bms_uint8_t;
		fields_types[43] = e_bms_ivt_msg_response__a0_resp_triggermode_i;
		fields_types[44] = e_bms_ivt_msg_response__a1_resp_triggermode_u1;
		fields_types[45] = e_bms_ivt_msg_response__a2_resp_triggermode_u2;
		fields_types[46] = e_bms_ivt_msg_response__a3_resp_triggermode_u3;
		fields_types[47] = e_bms_ivt_msg_response__a4_resp_triggermode_t;
		fields_types[48] = e_bms_ivt_msg_response__a5_resp_triggermode_w;
		fields_types[49] = e_bms_ivt_msg_response__a6_resp_triggermode_as;
		fields_types[50] = e_bms_ivt_msg_response__a7_resp_triggermode_wh;
		fields_types[51] = e_bms_ivt_msg_response__b4_resp_actual_mode;
		fields_types[52] = e_bms_uint8_t;
		fields_types[53] = e_bms_uint32_t;
		fields_types[54] = e_bms_uint8_t;
		fields_types[55] = e_bms_ivt_msg_response__b9_resp_device_current;
		fields_types[56] = e_bms_uint16_t;
		fields_types[57] = e_bms_uint16_t;
		fields_types[58] = e_bms_uint64_t;
		fields_types[59] = e_bms_uint64_t;
		fields_types[60] = e_bms_uint16_t;
		fields_types[61] = e_bms_uint16_t;
		fields_types[62] = e_bms_uint16_t;
		fields_types[63] = e_bms_uint16_t;
		fields_types[64] = e_bms_uint16_t;
		fields_types[65] = e_bms_uint16_t;
		fields_types[66] = e_bms_uint16_t;
		fields_types[67] = e_bms_uint16_t;
		fields_types[68] = e_bms_uint8_t;
		fields_types[69] = e_bms_uint8_t;
		fields_types[70] = e_bms_uint8_t;
		fields_types[71] = e_bms_uint8_t;
		fields_types[72] = e_bms_uint8_t;
		fields_types[73] = e_bms_uint8_t;
		fields_types[74] = e_bms_uint8_t;
		fields_types[75] = e_bms_ivt_msg_response__b4_resp_startup_mode;
		fields_types[76] = e_bms_uint32_t;
		fields_types[77] = e_bms_uint8_t;
		fields_types[78] = e_bms_uint32_t;
		fields_types[79] = e_bms_uint32_t;
		fields_types[80] = e_bms_uint32_t;
		fields_types[81] = e_bms_uint32_t;
		fields_types[82] = e_bms_uint32_t;
		fields_types[83] = e_bms_uint32_t;
		fields_types[84] = e_bms_uint32_t;
		fields_types[85] = e_bms_uint32_t;
		fields_types[86] = e_bms_uint32_t;
		fields_types[87] = e_bms_uint32_t;
		fields_types[88] = e_bms_uint32_t;
		fields_types[89] = e_bms_uint16_t;
		fields_types[90] = e_bms_int16_t;
		fields_types[91] = e_bms_int16_t;
		fields_types[92] = e_bms_ivt_msg_response__b9_resp_device_voltage_chan;
		fields_types[93] = e_bms_uint8_t;
		fields_types[94] = e_bms_ivt_msg_response__b9_resp_device_toi;
		fields_types[95] = e_bms_int8_t;
		fields_types[96] = e_bms_ivt_msg_response__b9_resp_device_com;
		fields_types[97] = e_bms_uint8_t;
		fields_types[98] = e_bms_ivt_msg_response__b9_resp_device_v_supply;
		fields_types[99] = e_bms_uint8_t;
		return 100;
	case 1317:
		if(fields_types_size < 7) return 0;
		fields_types[0] = e_bms_ivt_msg_result_t_ivt_id_result_t;
		fields_types[1] = e_bms_uint8_t;
		fields_types[2] = e_bms_uint8_t;
		fields_types[3] = e_bms_uint8_t;
		fields_types[4] = e_bms_uint8_t;
		fields_types[5] = e_bms_uint8_t;
		fields_types[6] = e_bms_float;
		return 7;
	case 1316:
		if(fields_types_size < 7) return 0;
		fields_types[0] = e_bms_ivt_msg_result_u3_ivt_id_result_u3;
		fields_types[1] = e_bms_uint8_t;
		fields_types[2] = e_bms_uint8_t;
		fields_types[3] = e_bms_uint8_t;
		fields_types[4] = e_bms_uint8_t;
		fields_types[5] = e_bms_uint8_t;
		fields_types[6] = e_bms_int32_t;
		return 7;
	case 1315:
		if(fields_types_size < 7) return 0;
		fields_types[0] = e_bms_ivt_msg_result_u2_ivt_id_result_u2;
		fields_types[1] = e_bms_uint8_t;
		fields_types[2] = e_bms_uint8_t;
		fields_types[3] = e_bms_uint8_t;
		fields_types[4] = e_bms_uint8_t;
		fields_types[5] = e_bms_uint8_t;
		fields_types[6] = e_bms_int32_t;
		return 7;
	case 1314:
		if(fields_types_size < 7) return 0;
		fields_types[0] = e_bms_ivt_msg_result_u1_ivt_id_result_u1;
		fields_types[1] = e_bms_uint8_t;
		fields_types[2] = e_bms_uint8_t;
		fields_types[3] = e_bms_uint8_t;
		fields_types[4] = e_bms_uint8_t;
		fields_types[5] = e_bms_uint8_t;
		fields_types[6] = e_bms_int32_t;
		return 7;
	case 1313:
		if(fields_types_size < 7) return 0;
		fields_types[0] = e_bms_ivt_msg_result_i_ivt_id_result_i;
		fields_types[1] = e_bms_uint8_t;
		fields_types[2] = e_bms_uint8_t;
		fields_types[3] = e_bms_uint8_t;
		fields_types[4] = e_bms_uint8_t;
		fields_types[5] = e_bms_uint8_t;
		fields_types[6] = e_bms_int32_t;
		return 7;
	case 1041:
		if(fields_types_size < 106) return 0;
		fields_types[0] = e_bms_ivt_msg_cmd_ivt_id_cmd;
		fields_types[1] = e_bms_uint8_t;
		fields_types[2] = e_bms_uint16_t;
		fields_types[3] = e_bms_uint16_t;
		fields_types[4] = e_bms_uint16_t;
		fields_types[5] = e_bms_uint16_t;
		fields_types[6] = e_bms_uint16_t;
		fields_types[7] = e_bms_uint16_t;
		fields_types[8] = e_bms_uint16_t;
		fields_types[9] = e_bms_uint16_t;
		fields_types[10] = e_bms_uint16_t;
		fields_types[11] = e_bms_uint16_t;
		fields_types[12] = e_bms_uint8_t;
		fields_types[13] = e_bms_uint8_t;
		fields_types[14] = e_bms_uint8_t;
		fields_types[15] = e_bms_uint8_t;
		fields_types[16] = e_bms_uint8_t;
		fields_types[17] = e_bms_uint8_t;
		fields_types[18] = e_bms_uint8_t;
		fields_types[19] = e_bms_uint8_t;
		fields_types[20] = e_bms_ivt_msg_cmd__30_reset_item;
		fields_types[21] = e_bms_uint8_t;
		fields_types[22] = e_bms_uint16_t;
		fields_types[23] = e_bms_int16_t;
		fields_types[24] = e_bms_int16_t;
		fields_types[25] = e_bms_ivt_msg_cmd__3a_restart_to_bitrate;
		fields_types[26] = e_bms_uint8_t;
		fields_types[27] = e_bms_uint8_t;
		fields_types[28] = e_bms_ivt_msg_cmd__40_get_measerror_item;
		fields_types[29] = e_bms_ivt_msg_cmd__41_get_systemerror_item;
		fields_types[30] = e_bms_ivt_msg_cmd__42_get_alllogdata_item;
		fields_types[31] = e_bms_ivt_msg_cmd__43_get_logdata_item;
		fields_types[32] = e_bms_uint8_t;
		fields_types[33] = e_bms_uint8_t;
		fields_types[34] = e_bms_uint8_t;
		fields_types[35] = e_bms_uint8_t;
		fields_types[36] = e_bms_uint8_t;
		fields_types[37] = e_bms_uint8_t;
		fields_types[38] = e_bms_uint8_t;
		fields_types[39] = e_bms_uint8_t;
		fields_types[40] = e_bms_uint8_t;
		fields_types[41] = e_bms_uint8_t;
		fields_types[42] = e_bms_uint8_t;
		fields_types[43] = e_bms_uint8_t;
		fields_types[44] = e_bms_uint8_t;
		fields_types[45] = e_bms_uint8_t;
		fields_types[46] = e_bms_uint8_t;
		fields_types[47] = e_bms_uint8_t;
		fields_types[48] = e_bms_uint8_t;
		fields_types[49] = e_bms_uint8_t;
		fields_types[50] = e_bms_uint8_t;
		fields_types[51] = e_bms_uint8_t;
		fields_types[52] = e_bms_uint8_t;
		fields_types[53] = e_bms_uint8_t;
		fields_types[54] = e_bms_uint8_t;
		fields_types[55] = e_bms_uint8_t;
		fields_types[56] = e_bms_ivt_msg_cmd__20_conf_triggermode_i;
		fields_types[57] = e_bms_ivt_msg_cmd__21_conf_triggermode_u1;
		fields_types[58] = e_bms_ivt_msg_cmd__22_conf_triggermode_u2;
		fields_types[59] = e_bms_ivt_msg_cmd__23_conf_triggermode_u3;
		fields_types[60] = e_bms_ivt_msg_cmd__24_conf_triggermode_t;
		fields_types[61] = e_bms_ivt_msg_cmd__25_conf_triggermode_w;
		fields_types[62] = e_bms_ivt_msg_cmd__26_conf_triggermode_as;
		fields_types[63] = e_bms_ivt_msg_cmd__27_conf_triggermode_wh;
		fields_types[64] = e_bms_ivt_msg_cmd__34_actual_mode;
		fields_types[65] = e_bms_uint8_t;
		fields_types[66] = e_bms_uint16_t;
		fields_types[67] = e_bms_uint16_t;
		fields_types[68] = e_bms_uint16_t;
		fields_types[69] = e_bms_uint16_t;
		fields_types[70] = e_bms_uint16_t;
		fields_types[71] = e_bms_uint16_t;
		fields_types[72] = e_bms_uint16_t;
		fields_types[73] = e_bms_uint16_t;
		fields_types[74] = e_bms_uint8_t;
		fields_types[75] = e_bms_uint8_t;
		fields_types[76] = e_bms_uint8_t;
		fields_types[77] = e_bms_uint8_t;
		fields_types[78] = e_bms_uint8_t;
		fields_types[79] = e_bms_uint8_t;
		fields_types[80] = e_bms_uint8_t;
		fields_types[81] = e_bms_ivt_msg_cmd__34_startup_mode;
		fields_types[82] = e_bms_uint32_t;
		fields_types[83] = e_bms_uint32_t;
		fields_types[84] = e_bms_uint32_t;
		fields_types[85] = e_bms_uint32_t;
		fields_types[86] = e_bms_uint32_t;
		fields_types[87] = e_bms_uint32_t;
		fields_types[88] = e_bms_uint32_t;
		fields_types[89] = e_bms_uint32_t;
		fields_types[90] = e_bms_uint32_t;
		fields_types[91] = e_bms_uint32_t;
		fields_types[92] = e_bms_uint32_t;
		fields_types[93] = e_bms_uint16_t;
		fields_types[94] = e_bms_int16_t;
		fields_types[95] = e_bms_int16_t;
		fields_types[96] = e_bms_uint32_t;
		fields_types[97] = e_bms_uint32_t;
		fields_types[98] = e_bms_uint32_t;
		fields_types[99] = e_bms_uint32_t;
		fields_types[100] = e_bms_uint32_t;
		fields_types[101] = e_bms_uint32_t;
		fields_types[102] = e_bms_uint32_t;
		fields_types[103] = e_bms_uint32_t;
		fields_types[104] = e_bms_uint32_t;
		fields_types[105] = e_bms_uint32_t;
		return 106;
	case 1026:
		if(fields_types_size < 29) return 0;
		fields_types[0] = e_bms_board_status_cellboard_id;
		fields_types[1] = e_bms_uint8_t;
		fields_types[2] = e_bms_uint8_t;
		fields_types[3] = e_bms_uint8_t;
		fields_types[4] = e_bms_uint8_t;
		fields_types[5] = e_bms_uint8_t;
		fields_types[6] = e_bms_uint8_t;
		fields_types[7] = e_bms_uint8_t;
		fields_types[8] = e_bms_uint8_t;
		fields_types[9] = e_bms_uint8_t;
		fields_types[10] = e_bms_board_status_balancing_status;
		fields_types[11] = e_bms_uint8_t;
		fields_types[12] = e_bms_uint8_t;
		fields_types[13] = e_bms_uint8_t;
		fields_types[14] = e_bms_uint8_t;
		fields_types[15] = e_bms_uint8_t;
		fields_types[16] = e_bms_uint8_t;
		fields_types[17] = e_bms_uint8_t;
		fields_types[18] = e_bms_uint8_t;
		fields_types[19] = e_bms_uint8_t;
		fields_types[20] = e_bms_uint8_t;
		fields_types[21] = e_bms_uint8_t;
		fields_types[22] = e_bms_uint8_t;
		fields_types[23] = e_bms_uint8_t;
		fields_types[24] = e_bms_uint8_t;
		fields_types[25] = e_bms_uint8_t;
		fields_types[26] = e_bms_uint8_t;
		fields_types[27] = e_bms_uint8_t;
		fields_types[28] = e_bms_uint8_t;
		return 29;
	case 515:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_bms_temperatures_info_cellboard_id;
		fields_types[1] = e_bms_float;
		fields_types[2] = e_bms_float;
		fields_types[3] = e_bms_float;
		return 4;
	case 1539:
		if(fields_types_size < 6) return 0;
		fields_types[0] = e_bms_temperatures_cellboard_id;
		fields_types[1] = e_bms_uint8_t;
		fields_types[2] = e_bms_float;
		fields_types[3] = e_bms_float;
		fields_types[4] = e_bms_float;
		fields_types[5] = e_bms_float;
		return 6;
	case 516:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_bms_voltages_info_cellboard_id;
		fields_types[1] = e_bms_float;
		fields_types[2] = e_bms_float;
		fields_types[3] = e_bms_float;
		return 4;
	case 1540:
		if(fields_types_size < 5) return 0;
		fields_types[0] = e_bms_voltages_cellboard_id;
		fields_types[1] = e_bms_uint8_t;
		fields_types[2] = e_bms_float;
		fields_types[3] = e_bms_float;
		fields_types[4] = e_bms_float;
		return 5;
	case 16:
		if(fields_types_size < 3) return 0;
		fields_types[0] = e_bms_uint16_t;
		fields_types[1] = e_bms_uint16_t;
		fields_types[2] = e_bms_set_balancing_status_balancing_status;
		return 3;
	case 0:
		if(fields_types_size < 3) return 0;
		fields_types[0] = e_bms_uint8_t;
		fields_types[1] = e_bms_cellboard_flash_cellboard_id;
		fields_types[2] = e_bms_uint8_t;
		return 3;
	case 3:
		if(fields_types_size < 2) return 0;
		fields_types[0] = e_bms_uint8_t;
		fields_types[1] = e_bms_cellboard_flash_request_cellboard_id;
		return 2;
	case 4:
		if(fields_types_size < 2) return 0;
		fields_types[0] = e_bms_cellboard_flash_response_cellboard_id;
		fields_types[1] = e_bms_uint8_t;
		return 2;
	case 1537:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_bms_cellboard_discovery_cellboard_id;
		return 1;
	case 1545:
		if(fields_types_size < 3) return 0;
		fields_types[0] = e_bms_cellboard_version_cellboard_id;
		fields_types[1] = e_bms_uint32_t;
		fields_types[2] = e_bms_uint32_t;
		return 3;
	case 513:
		if(fields_types_size < 2) return 0;
		fields_types[0] = e_bms_cellboard_status_cellboard_id;
		fields_types[1] = e_bms_cellboard_status_status;
		return 2;
	case 1553:
		if(fields_types_size < 5) return 0;
		fields_types[0] = e_bms_cellboard_cells_voltage_cellboard_id;
		fields_types[1] = e_bms_uint8_t;
		fields_types[2] = e_bms_float;
		fields_types[3] = e_bms_float;
		fields_types[4] = e_bms_float;
		return 5;
	case 1561:
		if(fields_types_size < 6) return 0;
		fields_types[0] = e_bms_cellboard_cells_temperature_cellboard_id;
		fields_types[1] = e_bms_uint8_t;
		fields_types[2] = e_bms_float;
		fields_types[3] = e_bms_float;
		fields_types[4] = e_bms_float;
		fields_types[5] = e_bms_float;
		return 6;
	case 1025:
		if(fields_types_size < 3) return 0;
		fields_types[0] = e_bms_uint8_t;
		fields_types[1] = e_bms_float;
		fields_types[2] = e_bms_float;
		return 3;
	case 1569:
		if(fields_types_size < 26) return 0;
		fields_types[0] = e_bms_cellboard_balancing_status_status;
		fields_types[1] = e_bms_cellboard_balancing_status_cellboard_id;
		fields_types[2] = e_bms_uint8_t;
		fields_types[3] = e_bms_uint8_t;
		fields_types[4] = e_bms_uint8_t;
		fields_types[5] = e_bms_uint8_t;
		fields_types[6] = e_bms_uint8_t;
		fields_types[7] = e_bms_uint8_t;
		fields_types[8] = e_bms_uint8_t;
		fields_types[9] = e_bms_uint8_t;
		fields_types[10] = e_bms_uint8_t;
		fields_types[11] = e_bms_uint8_t;
		fields_types[12] = e_bms_uint8_t;
		fields_types[13] = e_bms_uint8_t;
		fields_types[14] = e_bms_uint8_t;
		fields_types[15] = e_bms_uint8_t;
		fields_types[16] = e_bms_uint8_t;
		fields_types[17] = e_bms_uint8_t;
		fields_types[18] = e_bms_uint8_t;
		fields_types[19] = e_bms_uint8_t;
		fields_types[20] = e_bms_uint8_t;
		fields_types[21] = e_bms_uint8_t;
		fields_types[22] = e_bms_uint8_t;
		fields_types[23] = e_bms_uint8_t;
		fields_types[24] = e_bms_uint8_t;
		fields_types[25] = e_bms_uint8_t;
		return 26;
	case 521:
		if(fields_types_size < 11) return 0;
		fields_types[0] = e_bms_cellboard_errors_post;
		fields_types[1] = e_bms_cellboard_errors_undervoltage;
		fields_types[2] = e_bms_cellboard_errors_overvoltage;
		fields_types[3] = e_bms_cellboard_errors_undertemperature_cells;
		fields_types[4] = e_bms_cellboard_errors_undertemperature_discharge;
		fields_types[5] = e_bms_cellboard_errors_overtemperature_cells;
		fields_types[6] = e_bms_cellboard_errors_overtemperature_discharge;
		fields_types[7] = e_bms_cellboard_errors_can;
		fields_types[8] = e_bms_cellboard_errors_flash;
		fields_types[9] = e_bms_cellboard_errors_bms_monitor;
		fields_types[10] = e_bms_cellboard_errors_open_wire;
		return 11;

    }
    return 0;
}
std::vector<std::string> bms_enum_fields_from_message(const std::string& msg_name)
{
	std::vector<std::string> ret;

	if(msg_name == IVT_MSG_RESULT_WH) {
		ret.push_back("ivt_id_result_wh");
	}
	if(msg_name == IVT_MSG_RESULT_AS) {
		ret.push_back("ivt_id_result_as");
	}
	if(msg_name == IVT_MSG_RESULT_W) {
		ret.push_back("ivt_id_result_w");
	}
	if(msg_name == IVT_MSG_RESPONSE) {
		ret.push_back("ivt_id_response");
		ret.push_back("_80_resp_measerror_item");
		ret.push_back("_81_resp_systemerror_item");
		ret.push_back("_82_resp_alllogdata_item");
		ret.push_back("_83_resp_logdata_item");
		ret.push_back("_b0_resp_reset_item");
		ret.push_back("_b9_resp_device_type");
		ret.push_back("_a0_resp_triggermode_i");
		ret.push_back("_a1_resp_triggermode_u1");
		ret.push_back("_a2_resp_triggermode_u2");
		ret.push_back("_a3_resp_triggermode_u3");
		ret.push_back("_a4_resp_triggermode_t");
		ret.push_back("_a5_resp_triggermode_w");
		ret.push_back("_a6_resp_triggermode_as");
		ret.push_back("_a7_resp_triggermode_wh");
		ret.push_back("_b4_resp_actual_mode");
		ret.push_back("_b9_resp_device_current");
		ret.push_back("_b4_resp_startup_mode");
		ret.push_back("_b9_resp_device_voltage_chan");
		ret.push_back("_b9_resp_device_toi");
		ret.push_back("_b9_resp_device_com");
		ret.push_back("_b9_resp_device_v_supply");
	}
	if(msg_name == IVT_MSG_RESULT_T) {
		ret.push_back("ivt_id_result_t");
	}
	if(msg_name == IVT_MSG_RESULT_U3) {
		ret.push_back("ivt_id_result_u3");
	}
	if(msg_name == IVT_MSG_RESULT_U2) {
		ret.push_back("ivt_id_result_u2");
	}
	if(msg_name == IVT_MSG_RESULT_U1) {
		ret.push_back("ivt_id_result_u1");
	}
	if(msg_name == IVT_MSG_RESULT_I) {
		ret.push_back("ivt_id_result_i");
	}
	if(msg_name == IVT_MSG_CMD) {
		ret.push_back("ivt_id_cmd");
		ret.push_back("_30_reset_item");
		ret.push_back("_3a_restart_to_bitrate");
		ret.push_back("_40_get_measerror_item");
		ret.push_back("_41_get_systemerror_item");
		ret.push_back("_42_get_alllogdata_item");
		ret.push_back("_43_get_logdata_item");
		ret.push_back("_20_conf_triggermode_i");
		ret.push_back("_21_conf_triggermode_u1");
		ret.push_back("_22_conf_triggermode_u2");
		ret.push_back("_23_conf_triggermode_u3");
		ret.push_back("_24_conf_triggermode_t");
		ret.push_back("_25_conf_triggermode_w");
		ret.push_back("_26_conf_triggermode_as");
		ret.push_back("_27_conf_triggermode_wh");
		ret.push_back("_34_actual_mode");
		ret.push_back("_34_startup_mode");
	}
	if(msg_name == BOARD_STATUS) {
		ret.push_back("cellboard_id");
		ret.push_back("errors_can_comm");
		ret.push_back("errors_ltc_comm");
		ret.push_back("errors_temp_comm_0");
		ret.push_back("errors_temp_comm_1");
		ret.push_back("errors_temp_comm_2");
		ret.push_back("errors_temp_comm_3");
		ret.push_back("errors_temp_comm_4");
		ret.push_back("errors_temp_comm_5");
		ret.push_back("errors_open_wire");
		ret.push_back("balancing_status");
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
	if(msg_name == TEMPERATURES_INFO) {
		ret.push_back("cellboard_id");
	}
	if(msg_name == TEMPERATURES) {
		ret.push_back("cellboard_id");
	}
	if(msg_name == VOLTAGES_INFO) {
		ret.push_back("cellboard_id");
	}
	if(msg_name == VOLTAGES) {
		ret.push_back("cellboard_id");
	}
	if(msg_name == SET_BALANCING_STATUS) {
		ret.push_back("balancing_status");
	}
	if(msg_name == CELLBOARD_FLASH) {
		ret.push_back("start");
		ret.push_back("cellboard_id");
	}
	if(msg_name == CELLBOARD_FLASH_REQUEST) {
		ret.push_back("mainboard");
		ret.push_back("cellboard_id");
	}
	if(msg_name == CELLBOARD_FLASH_RESPONSE) {
		ret.push_back("cellboard_id");
		ret.push_back("ready");
	}
	if(msg_name == CELLBOARD_DISCOVERY) {
		ret.push_back("cellboard_id");
	}
	if(msg_name == CELLBOARD_VERSION) {
		ret.push_back("cellboard_id");
	}
	if(msg_name == CELLBOARD_STATUS) {
		ret.push_back("cellboard_id");
		ret.push_back("status");
	}
	if(msg_name == CELLBOARD_CELLS_VOLTAGE) {
		ret.push_back("cellboard_id");
	}
	if(msg_name == CELLBOARD_CELLS_TEMPERATURE) {
		ret.push_back("cellboard_id");
	}
	if(msg_name == CELLBOARD_SET_BALANCING_STATUS) {
		ret.push_back("start");
	}
	if(msg_name == CELLBOARD_BALANCING_STATUS) {
		ret.push_back("status");
		ret.push_back("cellboard_id");
		ret.push_back("discharging_cell_0");
		ret.push_back("discharging_cell_1");
		ret.push_back("discharging_cell_2");
		ret.push_back("discharging_cell_3");
		ret.push_back("discharging_cell_4");
		ret.push_back("discharging_cell_5");
		ret.push_back("discharging_cell_6");
		ret.push_back("discharging_cell_7");
		ret.push_back("discharging_cell_8");
		ret.push_back("discharging_cell_9");
		ret.push_back("discharging_cell_10");
		ret.push_back("discharging_cell_11");
		ret.push_back("discharging_cell_12");
		ret.push_back("discharging_cell_13");
		ret.push_back("discharging_cell_14");
		ret.push_back("discharging_cell_15");
		ret.push_back("discharging_cell_16");
		ret.push_back("discharging_cell_17");
		ret.push_back("discharging_cell_18");
		ret.push_back("discharging_cell_19");
		ret.push_back("discharging_cell_20");
		ret.push_back("discharging_cell_21");
		ret.push_back("discharging_cell_22");
		ret.push_back("discharging_cell_23");
	}
	if(msg_name == CELLBOARD_ERRORS) {
		ret.push_back("post");
		ret.push_back("undervoltage");
		ret.push_back("overvoltage");
		ret.push_back("undertemperature_cells");
		ret.push_back("undertemperature_discharge");
		ret.push_back("overtemperature_cells");
		ret.push_back("overtemperature_discharge");
		ret.push_back("can");
		ret.push_back("flash");
		ret.push_back("bms_monitor");
		ret.push_back("open_wire");
	}

	return ret;
}
std::vector<std::string> bms_enum_names_from_fields(const std::string& msg_name, const std::string& sgn_name)
{
	std::vector<std::string> ret;

	if(msg_name == IVT_MSG_RESULT_WH)
	{
		if(sgn_name == "ivt_id_result_wh")
		{
			ret.push_back("Vt_Result_Wh");
			return ret;
		}
	}
	if(msg_name == IVT_MSG_RESULT_AS)
	{
		if(sgn_name == "ivt_id_result_as")
		{
			ret.push_back("Vt_Result_As");
			return ret;
		}
	}
	if(msg_name == IVT_MSG_RESULT_W)
	{
		if(sgn_name == "ivt_id_result_w")
		{
			ret.push_back("Vt_Result_W");
			return ret;
		}
	}
	if(msg_name == IVT_MSG_RESPONSE)
	{
		if(sgn_name == "ivt_id_response")
		{
			ret.push_back("Resp_Cmd_Wrong_Command");
			ret.push_back("Resp_Get_Set_ALIVE");
			ret.push_back("Resp_Get_Set_ArtNr");
			ret.push_back("Resp_Get_Set_Serialnumber");
			ret.push_back("Resp_Get_Set_SW_VERSION");
			ret.push_back("Resp_Get_Set_DEVICE_ID");
			ret.push_back("Resp_Get_Set_THRESHOLD_NEG");
			ret.push_back("Resp_Get_Set_THRESHOLD_POS");
			ret.push_back("Resp_Get_Set_MODE");
			ret.push_back("Resp_Get_Set_OC_TEST_TIME");
			ret.push_back("Resp_Get_Set_STORE");
			ret.push_back("Resp_Get_Set_TRIGGER");
			ret.push_back("Resp_Get_Set_Reset_Error_Logdata");
			ret.push_back("Resp_Config_Result_Wh");
			ret.push_back("Resp_Config_Result_As");
			ret.push_back("Resp_Config_Result_W");
			ret.push_back("Resp_Config_Result_T");
			ret.push_back("Resp_Config_Result_U3");
			ret.push_back("Resp_Config_Result_U2");
			ret.push_back("Resp_Config_Result_U1");
			ret.push_back("Resp_Config_Result_I");
			ret.push_back("Resp_CAN_ID_Response");
			ret.push_back("Resp_CAN_ID_Command");
			ret.push_back("Resp_CAN_ID_Res_Wh");
			ret.push_back("Resp_CAN_ID_Res_As");
			ret.push_back("Resp_CAN_ID_Res_W");
			ret.push_back("Resp_CAN_ID_Res_I");
			ret.push_back("Resp_CAN_ID_Res_T");
			ret.push_back("Resp_CAN_ID_Res_U3");
			ret.push_back("Resp_CAN_ID_Res_U2");
			ret.push_back("Resp_CAN_ID_Res_U1");
			ret.push_back("Resp_Error_Log_Logdata_Since_Res");
			ret.push_back("Resp_Error_Log_Overall_Logdata");
			ret.push_back("Resp_Error_Log_System_Error");
			ret.push_back("Resp_Error_Log_Measurement_Error");
			return ret;
		}
		if(sgn_name == "_80_resp_measerror_item")
		{
			ret.push_back("Resp_error_calibration_data");
			ret.push_back("Resp_error_ntc_I_OpenCirc");
			ret.push_back("Resp_error_ntc_h_OpenCirc");
			ret.push_back("Resp_error_meas_U3_OpenCirc");
			ret.push_back("Resp_error_meas_U2_OpenCirc");
			ret.push_back("Resp_error_meas_U1_OpenCirc");
			ret.push_back("Resp_error_meas_I1_OpenCirc");
			ret.push_back("Resp__error_therm_EMF_correction");
			ret.push_back("Resp_error_cur_meas_implausible");
			ret.push_back("Resp_error_Vref");
			ret.push_back("Resp_error_Underflow_ADC_ch_2");
			ret.push_back("Resp_error_Overflow_ADC_ch_2");
			ret.push_back("Resp_error_Underflow_ADC_ch_1");
			ret.push_back("Reso_error_Overflow_ADC_ch_1");
			ret.push_back("Resp_error_ADC_interrupt");
			ret.push_back("Resonse_all_meas_errors");
			return ret;
		}
		if(sgn_name == "_81_resp_systemerror_item")
		{
			ret.push_back("Resp_error_Reset_EMC");
			ret.push_back("Resp_error_Reset_Watchdog");
			ret.push_back("Resp_error_Reset_illegal_opcode");
			ret.push_back("Resp_error_ADC_Clock");
			ret.push_back("Resp_error_eeprom_rw");
			ret.push_back("Resp_error_Overcurrent_detection");
			ret.push_back("Resp_error_Configuration");
			ret.push_back("Resp_error_System_Init");
			ret.push_back("Resp_error_System_Clock");
			ret.push_back("Resp_error_Power_failure");
			ret.push_back("Resp_error_Undertemp");
			ret.push_back("Resp_error_Overtemp");
			ret.push_back("Resp_error_CAN_bus_transmit_Data");
			ret.push_back("Resp_error_CAN_bus_receive_Data");
			ret.push_back("Resp_error_Parameter_CRC");
			ret.push_back("Resp_error_code_CRC");
			ret.push_back("Resonse_all_SystemErrors");
			return ret;
		}
		if(sgn_name == "_82_resp_alllogdata_item")
		{
			ret.push_back("Resp_temp_minimum");
			ret.push_back("Resp_temp_maxmimum");
			ret.push_back("Resp_U3_minimum");
			ret.push_back("Resp_U3_maximum");
			ret.push_back("Resp_U2_minimum");
			ret.push_back("Resp_U2_maxmimum");
			ret.push_back("Resp_U1_minimum");
			ret.push_back("Resp_U1_maximum");
			ret.push_back("Resp_current_minimum");
			ret.push_back("Resp_current_maximum");
			ret.push_back("Resp_oc_negative_activated");
			ret.push_back("Resp_oc_positive_activated");
			ret.push_back("Resp_run_temp_out_spec_limits");
			ret.push_back("Resp_run_temp_in_spec_limits");
			ret.push_back("Resp_run_volt_3_out_spec_limits");
			ret.push_back("Resp_run_volt_3_in_spec_limits");
			ret.push_back("Resp_run_volt_2_out_spec_limits");
			ret.push_back("Resp_run_volt_2_in_spec_limits");
			ret.push_back("Resp_run_volt_1_out_spec_limits");
			ret.push_back("Resp_run_volt_1_in_spec_limits");
			ret.push_back("Resp_run_cur_out_spec_limits");
			ret.push_back("Resp_run_cur_in_spec_limits");
			ret.push_back("Resp_run_overall");
			ret.push_back("Resp_energy_counter_discharging");
			ret.push_back("Resp_energy_counter_charging");
			ret.push_back("Resp_energy_counter_overall");
			ret.push_back("Resp_Ah_counter_discharging");
			ret.push_back("Resp_Ah_counter_charging");
			ret.push_back("Resp_Ah_counter_overall");
			ret.push_back("Response_on_Overall_Logdata");
			return ret;
		}
		if(sgn_name == "_83_resp_logdata_item")
		{
			ret.push_back("Resp_temp_minimum");
			ret.push_back("Resp_temp_maxmimum");
			ret.push_back("Resp_U3_minimum");
			ret.push_back("Resp_U3_maximum");
			ret.push_back("Resp_U2_minimum");
			ret.push_back("Resp_U2_maxmimum");
			ret.push_back("Resp_U1_minimum");
			ret.push_back("Resp_U1_maximum");
			ret.push_back("Resp_current_minimum");
			ret.push_back("Resp_current_maximum");
			ret.push_back("Resp_oc_negative_activated");
			ret.push_back("Resp_oc_positive_activated");
			ret.push_back("Resp_run_temp_out_spec_limits");
			ret.push_back("Resp_run_temp_in_spec_limits");
			ret.push_back("Resp_run_volt_3_out_spec_limits");
			ret.push_back("Resp_run_volt_3_in_spec_limits");
			ret.push_back("Resp_run_volt_2_out_spec_limits");
			ret.push_back("Resp_run_volt_2_in_spec_limits");
			ret.push_back("Resp_run_volt_1_out_spec_limits");
			ret.push_back("Resp_run_volt_1_in_spec_limits");
			ret.push_back("Resp_run_cur_out_spec_limits");
			ret.push_back("Resp_run_cur_in_spec_limits");
			ret.push_back("Resp_run_overall");
			ret.push_back("Resp_energy_counter_discharging");
			ret.push_back("Resp_energy_counter_charging");
			ret.push_back("Resp_energy_counter_overall");
			ret.push_back("Resp_Ah_counter_discharging");
			ret.push_back("Resp_Ah_counter_charging");
			ret.push_back("Resp_Ah_counter_overall");
			ret.push_back("Response_all_Logdata_SinceReset");
			return ret;
		}
		if(sgn_name == "_b0_resp_reset_item")
		{
			ret.push_back("Reset_temp_minimum");
			ret.push_back("Reset_temp_maximum");
			ret.push_back("Reset_U3_minimum");
			ret.push_back("Reset_U3_maximum");
			ret.push_back("Reset_U2_minimum");
			ret.push_back("Reset_U2_maximum");
			ret.push_back("Reset_U1_minimum");
			ret.push_back("Reset_U1_maximum");
			ret.push_back("Reset_Current_minimum");
			ret.push_back("Reset_Current_maximum");
			ret.push_back("Reset_Run_overcur_neg_activated");
			ret.push_back("Reset_Run_overcur_pos_activated");
			ret.push_back("Reset_Run_temp_out_spec_limits");
			ret.push_back("Reset_Run_temp_in_spec_limits");
			ret.push_back("Reset_Run_volt_3_out_spec_limits");
			ret.push_back("Reset_Run_volt_3_in_spec_limits");
			ret.push_back("Reset_Run_volt_2_out_spec_limits");
			ret.push_back("Reset_Run_volt_2_in_spec_limits");
			ret.push_back("Reset_Run_volt_1_out_spec_limits");
			ret.push_back("Reset_Run_volt_1_in_spec_limits");
			ret.push_back("Reset_Run_cur_out_spec_limits");
			ret.push_back("Reset_Run_cur_in_spec_limits");
			ret.push_back("Reset_Runtime_overall");
			ret.push_back("Reset_Energy_counter_discharging");
			ret.push_back("Reset_Energy_counter_charging");
			ret.push_back("Reset_Energy_counter_overall");
			ret.push_back("Reset_Ah_counter_discharging");
			ret.push_back("Reset_Ah_counter_charging");
			ret.push_back("Reset_Ah_counter_overall");
			ret.push_back("Reset_all_Logdata_Since_Reset");
			ret.push_back("Reset_Reset_EMC");
			ret.push_back("Reset_Reset_Watchdog");
			ret.push_back("Reset_illegal_opcode");
			ret.push_back("Reset_ADC_Clock");
			ret.push_back("Reset_eeprom_rw");
			ret.push_back("Reset_overcurrent_detection");
			ret.push_back("Reset_configuration");
			ret.push_back("Reset_system_init");
			ret.push_back("Reset_system_clock");
			ret.push_back("Reset_power_failure");
			ret.push_back("Reset_undertemp");
			ret.push_back("Reset_overtemp");
			ret.push_back("Reset_CAN_bus_transmit_Data");
			ret.push_back("Reset_CAN_bus_receive_Data");
			ret.push_back("Reset_Parameter_CRC");
			ret.push_back("Reset_Code_CRC");
			ret.push_back("Reset_all_System_errors");
			ret.push_back("Reset_calibration_data_");
			ret.push_back("Reset_ntc_I_OpenCircuit");
			ret.push_back("Reset_ntc_h_OpenCircuit");
			ret.push_back("Reset_voltage_measU3_OpenCircuit");
			ret.push_back("Reset_voltage_measU2_OpenCircuit");
			ret.push_back("Reset_voltage_measU1_OpenCircuit");
			ret.push_back("Reset_current_measI1_OpenCircuit");
			ret.push_back("Reset_thermal_EMF_correction");
			ret.push_back("Reset_error_current_implausible");
			ret.push_back("Reset_error_Vref");
			ret.push_back("Reset_error_Underflow_ADC_ch2");
			ret.push_back("Reset_error_Overflow_ADC_ch2");
			ret.push_back("Reset_error_Underflow_ADC_ch1");
			ret.push_back("Reset_error_Overflow_ADC_ch1");
			ret.push_back("Reset_error_ADC_interrupt");
			ret.push_back("Reset_all_measurement_errors");
			return ret;
		}
		if(sgn_name == "_b9_resp_device_type")
		{
			ret.push_back("IVT_S");
			ret.push_back("IVT_Mod");
			return ret;
		}
		if(sgn_name == "_a0_resp_triggermode_i")
		{
			ret.push_back("CYCLIC");
			ret.push_back("TRIGGERED");
			ret.push_back("DISABLED");
			return ret;
		}
		if(sgn_name == "_a1_resp_triggermode_u1")
		{
			ret.push_back("CYCLIC");
			ret.push_back("TRIGGERED");
			ret.push_back("DISABLED");
			return ret;
		}
		if(sgn_name == "_a2_resp_triggermode_u2")
		{
			ret.push_back("CYCLIC");
			ret.push_back("TRIGGERED");
			ret.push_back("DISABLED");
			return ret;
		}
		if(sgn_name == "_a3_resp_triggermode_u3")
		{
			ret.push_back("CYCLIC");
			ret.push_back("TRIGGERED");
			ret.push_back("DISABLED");
			return ret;
		}
		if(sgn_name == "_a4_resp_triggermode_t")
		{
			ret.push_back("CYCLIC");
			ret.push_back("TRIGGERED");
			ret.push_back("DISABLED");
			return ret;
		}
		if(sgn_name == "_a5_resp_triggermode_w")
		{
			ret.push_back("CYCLIC");
			ret.push_back("TRIGGERED");
			ret.push_back("DISABLED");
			return ret;
		}
		if(sgn_name == "_a6_resp_triggermode_as")
		{
			ret.push_back("CYCLIC");
			ret.push_back("TRIGGERED");
			ret.push_back("DISABLED");
			return ret;
		}
		if(sgn_name == "_a7_resp_triggermode_wh")
		{
			ret.push_back("CYCLIC");
			ret.push_back("TRIGGERED");
			ret.push_back("DISABLED");
			return ret;
		}
		if(sgn_name == "_b4_resp_actual_mode")
		{
			ret.push_back("RUN");
			ret.push_back("STOP");
			return ret;
		}
		if(sgn_name == "_b9_resp_device_current")
		{
			ret.push_back("2500_A");
			ret.push_back("1000_A");
			ret.push_back("500_A");
			ret.push_back("300_A");
			ret.push_back("100_A");
			return ret;
		}
		if(sgn_name == "_b4_resp_startup_mode")
		{
			ret.push_back("Run");
			ret.push_back("Stop");
			return ret;
		}
		if(sgn_name == "_b9_resp_device_voltage_chan")
		{
			ret.push_back("3_Channels");
			ret.push_back("0_Channels");
			return ret;
		}
		if(sgn_name == "_b9_resp_device_toi")
		{
			ret.push_back("I");
			return ret;
		}
		if(sgn_name == "_b9_resp_device_com")
		{
			ret.push_back("CAN_2___not_terminated");
			ret.push_back("CAN_1___terminated");
			ret.push_back("none");
			return ret;
		}
		if(sgn_name == "_b9_resp_device_v_supply")
		{
			ret.push_back("12__24_V_nominal_supply_voltage");
			return ret;
		}
	}
	if(msg_name == IVT_MSG_RESULT_T)
	{
		if(sgn_name == "ivt_id_result_t")
		{
			ret.push_back("Vt_Result_T");
			return ret;
		}
	}
	if(msg_name == IVT_MSG_RESULT_U3)
	{
		if(sgn_name == "ivt_id_result_u3")
		{
			ret.push_back("Vt_Result_U3");
			return ret;
		}
	}
	if(msg_name == IVT_MSG_RESULT_U2)
	{
		if(sgn_name == "ivt_id_result_u2")
		{
			ret.push_back("Vt_Result_U2");
			return ret;
		}
	}
	if(msg_name == IVT_MSG_RESULT_U1)
	{
		if(sgn_name == "ivt_id_result_u1")
		{
			ret.push_back("Vt_Result_U1");
			return ret;
		}
	}
	if(msg_name == IVT_MSG_RESULT_I)
	{
		if(sgn_name == "ivt_id_result_i")
		{
			ret.push_back("Vt_Result_I");
			return ret;
		}
	}
	if(msg_name == IVT_MSG_CMD)
	{
		if(sgn_name == "ivt_id_cmd")
		{
			ret.push_back("Get_cmd_and_info_ArtNr");
			ret.push_back("Get_cmd_and_info_SN");
			ret.push_back("Get_cmd_and_info_SW_Version");
			ret.push_back("Get_cmd_and_info_DEVICE_ID");
			ret.push_back("Get_cmd_and_info_THRESHOLD_NEG");
			ret.push_back("Get_cmd_and_info_THRESHOLD_POS");
			ret.push_back("Get_cmd_and_info_MODE");
			ret.push_back("Get_cmd_and_info_OC_TEST_TIME");
			ret.push_back("Get_Config_Res_Wh");
			ret.push_back("Get_Config_Res_As");
			ret.push_back("Get_Config_Res_W");
			ret.push_back("Get_Config_Res_T");
			ret.push_back("Get_Config_Res_U3");
			ret.push_back("Get_Config_Res_U2");
			ret.push_back("Get_Config_Res_U1");
			ret.push_back("Get_Config_Res_I");
			ret.push_back("Get_CAN_ID_Response");
			ret.push_back("Get_CAN_ID_Command");
			ret.push_back("Get_CAN_ID_Res_Wh");
			ret.push_back("Get_CAN_ID_Res_As");
			ret.push_back("Get_CAN_ID_Res_W");
			ret.push_back("Get_CAN_ID_Res_T");
			ret.push_back("Get_CAN_ID_Res_U3");
			ret.push_back("Get_CAN_ID_Res_U2");
			ret.push_back("Get_CAN_ID_Res_U1");
			ret.push_back("Get_CAN_ID_Res_I");
			ret.push_back("Get_Logdata_Since_Reset");
			ret.push_back("Get_Overall_Logdata");
			ret.push_back("Get_System_Errors");
			ret.push_back("Get_Measurement_Errors");
			ret.push_back("Set_RESTART");
			ret.push_back("Set_RESTART_to_default");
			ret.push_back("RESTART_to_Bitrate");
			ret.push_back("Set_THRESHOLD_neg");
			ret.push_back("Set_THRESHOLD_pos");
			ret.push_back("Set_MODE_Result_I");
			ret.push_back("Set_CAN_ID_Result_I");
			ret.push_back("Set_MODE");
			ret.push_back("START_OC_TEST");
			ret.push_back("STORE");
			ret.push_back("TRIGGER");
			ret.push_back("Reset_Err_Log");
			ret.push_back("Set_MODE_Result_Wh");
			ret.push_back("Set_MODE_Result_As");
			ret.push_back("Set_MODE_Result_W");
			ret.push_back("Set_CAN_ID_Result_Wh");
			ret.push_back("Set_CAN_ID_Result_As");
			ret.push_back("Set_CAN_ID_Result_W");
			ret.push_back("Set_CAN_ID_Result_T");
			ret.push_back("Set_MODE_Result_U3");
			ret.push_back("Set_CAN_ID_Response");
			ret.push_back("Set_CAN_ID_Cmd");
			ret.push_back("Set_CAN_ID_Result_U3");
			ret.push_back("Set_CAN_ID_Result_U2");
			ret.push_back("Set_MODE_Result_T");
			ret.push_back("Set_MODE_Result_U2");
			ret.push_back("Set_MODE_Result_U1");
			ret.push_back("Set_CAN_ID_Result_U1");
			return ret;
		}
		if(sgn_name == "_30_reset_item")
		{
			ret.push_back("Reset_temp_minimum");
			ret.push_back("Reset_temp_maximum");
			ret.push_back("Reset_U3_minimum");
			ret.push_back("Reset_U3_maximum");
			ret.push_back("Reset_U2_minimum");
			ret.push_back("Reset_U2_maximum");
			ret.push_back("Reset_U1_minimum");
			ret.push_back("Reset_U1_maximum");
			ret.push_back("Reset_Current_minimum");
			ret.push_back("Reset_Current_maximum");
			ret.push_back("Reset_Run_overcur_neg_activated");
			ret.push_back("Reset_Run_overcur_pos_activated");
			ret.push_back("Reset_Run_temp_out_spec_limits");
			ret.push_back("Reset_Run_temp_in_spec_limits");
			ret.push_back("Reset_Run_volt_3_out_spec_limits");
			ret.push_back("Reset_Run_volt_3_in_spec_limits");
			ret.push_back("Reset_Run_volt_2_out_spec_limits");
			ret.push_back("Reset_Run_volt_2_in_spec_limits");
			ret.push_back("Reset_Run_volt_1_out_spec_limits");
			ret.push_back("Reset_Run_volt_1_in_spec_limits");
			ret.push_back("Reset_Run_cur_out_spec_limits");
			ret.push_back("Reset_Run_cur_in_spec_limits");
			ret.push_back("Reset_Runtime_overall");
			ret.push_back("Reset_Energy_counter_discharging");
			ret.push_back("Reset_Energy_counter_charging");
			ret.push_back("Reset_Energy_counter_overall");
			ret.push_back("Reset_Ah_counter_discharging");
			ret.push_back("Reset_Ah_counter_charging");
			ret.push_back("Reset_Ah_counter_overall");
			ret.push_back("Reset_all_Logdata_Since_Reset");
			ret.push_back("Reset_Reset_EMC");
			ret.push_back("Reset_Reset_Watchdog");
			ret.push_back("Reset_illegal_opcode");
			ret.push_back("Reset_ADC_Clock");
			ret.push_back("Reset_eeprom_rw");
			ret.push_back("Reset_overcurrent_detection");
			ret.push_back("Reset_configuration");
			ret.push_back("Reset_system_init");
			ret.push_back("Reset_system_clock");
			ret.push_back("Reset_power_failure");
			ret.push_back("Reset_undertemp");
			ret.push_back("Reset_overtemp");
			ret.push_back("Reset_CAN_bus_transmit_Data");
			ret.push_back("Reset_CAN_bus_receive_Data");
			ret.push_back("Reset_Parameter_CRC");
			ret.push_back("Reset_Code_CRC");
			ret.push_back("Reset_all_System_errors");
			ret.push_back("Reset_calibration_data_");
			ret.push_back("Reset_ntc_I_OpenCircuit");
			ret.push_back("Reset_ntc_h_OpenCircuit");
			ret.push_back("Reset_voltage_measU3_OpenCircuit");
			ret.push_back("Reset_voltage_measU2_OpenCircuit");
			ret.push_back("Reset_voltage_measU1_OpenCircuit");
			ret.push_back("Reset_current_measI1_OpenCircuit");
			ret.push_back("Reset_thermal_EMF_correction");
			ret.push_back("Reset_error_current_implausible");
			ret.push_back("Reset_error_Vref");
			ret.push_back("Reset_error_Underflow_ADC_ch2");
			ret.push_back("Reset_error_Overflow_ADC_ch2");
			ret.push_back("Reset_error_Underflow_ADC_ch1");
			ret.push_back("Reset_error_Overflow_ADC_ch1");
			ret.push_back("Reset_error_ADC_interrupt");
			ret.push_back("Reset_all_measurement_errors");
			return ret;
		}
		if(sgn_name == "_3a_restart_to_bitrate")
		{
			ret.push_back("250k");
			ret.push_back("500k");
			ret.push_back("1000k");
			return ret;
		}
		if(sgn_name == "_40_get_measerror_item")
		{
			ret.push_back("Get_error_calibration_data");
			ret.push_back("Get_error_ntc_I_OpenCirc");
			ret.push_back("Get_error_ntc_h_OpenCirc");
			ret.push_back("Get_error_volt_meas_U3_OpenCirc");
			ret.push_back("Get_error_volt_meas_U2_OpenCirc");
			ret.push_back("Get_error_volt_meas_U1_OpenCirc");
			ret.push_back("Get_error_cur_meas_I1_OpenCirc");
			ret.push_back("Get_error_thermal_EMF_correction");
			ret.push_back("Get_error_cur_meas_implausible");
			ret.push_back("Get_error_Vref");
			ret.push_back("Get_error_Underflow_ADC_ch_2");
			ret.push_back("Get_error_Overflow_ADC_ch_2");
			ret.push_back("Get_error_Underflow_ADC_ch_1");
			ret.push_back("Get_error_Overflow_ADC_ch_1");
			ret.push_back("Get_error_ADC_interrupt");
			ret.push_back("Get_all_meas_Errors");
			return ret;
		}
		if(sgn_name == "_41_get_systemerror_item")
		{
			ret.push_back("Get_error_reset_EMC");
			ret.push_back("Get_error_reset_Watchdog");
			ret.push_back("Get_error_reset_illegal_opcode");
			ret.push_back("Get_error_ADC_clock");
			ret.push_back("Get_error_eeprom_rw");
			ret.push_back("Get_error_overcurrent_detection");
			ret.push_back("Get_error_configuration");
			ret.push_back("Get_error_system_init");
			ret.push_back("Get_error_system_clock");
			ret.push_back("Get_error_power_failure");
			ret.push_back("Get_error_undertemp");
			ret.push_back("Get_error_overtemp");
			ret.push_back("Get_error_CAN_bus_transmit_Data");
			ret.push_back("Get_error_CAN__bus_receive_Data");
			ret.push_back("Get_error_Code_Parameter_CRC");
			ret.push_back("Get_error_Code_CRC");
			ret.push_back("Get_all_System_errors");
			return ret;
		}
		if(sgn_name == "_42_get_alllogdata_item")
		{
			ret.push_back("Get_Temperature_minimum");
			ret.push_back("Get_Temperature_maximum");
			ret.push_back("Get_U3_minimum");
			ret.push_back("Get_U3_maxmimum_");
			ret.push_back("Get_U2_minimum");
			ret.push_back("Get_U2_maximum");
			ret.push_back("Get_U1_minimum");
			ret.push_back("Get_U1_maxmimum");
			ret.push_back("Get_current_minimum");
			ret.push_back("Get_current_maximum");
			ret.push_back("Get_run_overcur_neg_activated");
			ret.push_back("Get_run_overcur_pos_activated");
			ret.push_back("Get_run_temp_out_spec_limits");
			ret.push_back("Get_run_temp_in_spec_limits");
			ret.push_back("Get_run_volt3_out_spec_limits");
			ret.push_back("Get_run_volt3_in_spec_limits");
			ret.push_back("Get_run_volt2_out_spec_limits");
			ret.push_back("Get_run_volt2_in_spec_limits");
			ret.push_back("Get_run_volt1_out_spec_limits");
			ret.push_back("Get_run_volt1_in_spec_limits");
			ret.push_back("Get_run_cur_out_spec_limits");
			ret.push_back("Get_Run_cur_in_spec_limits");
			ret.push_back("Get_Runtime_overall");
			ret.push_back("Get_Energy_counter_discharging");
			ret.push_back("Get_Energy_counter_charging");
			ret.push_back("Get_Energy_counter_overall");
			ret.push_back("Get_Ah_counter_discharging");
			ret.push_back("Get_Ah_counter_charging");
			ret.push_back("Get_Ah_counter_overall");
			ret.push_back("Get_Overall_Logdata");
			return ret;
		}
		if(sgn_name == "_43_get_logdata_item")
		{
			ret.push_back("Get_Temperature_minimum");
			ret.push_back("Get_Temperature_maximum");
			ret.push_back("Get_U3_minimum");
			ret.push_back("Get_U3_maxmimum_");
			ret.push_back("Get_U2_minimum");
			ret.push_back("Get_U2_maximum");
			ret.push_back("Get_U1_minimum");
			ret.push_back("Get_U1_maxmimum");
			ret.push_back("Get_current_minimum");
			ret.push_back("Get_current_maximum");
			ret.push_back("Get_run_overcur_neg_activated");
			ret.push_back("Get_run_overcur_pos_activated");
			ret.push_back("Get_run_temp_out_spec_limits");
			ret.push_back("Get_run_temp_in_spec_limits");
			ret.push_back("Get_run_volt3_out_spec_limits");
			ret.push_back("Get_run_volt3_in_spec_limits");
			ret.push_back("Get_run_volt2_out_spec_limits");
			ret.push_back("Get_run_volt2_in_spec_limits");
			ret.push_back("Get_run_volt1_out_spec_limits");
			ret.push_back("Get_run_volt1_in_spec_limits");
			ret.push_back("Get_run_cur_out_spec_limits");
			ret.push_back("Get_Run_cur_in_spec_limits");
			ret.push_back("Get_Runtime_overall");
			ret.push_back("Get_Energy_counter_discharging");
			ret.push_back("Get_Energy_counter_charging");
			ret.push_back("Get_Energy_counter_overall");
			ret.push_back("Get_Ah_counter_discharging");
			ret.push_back("Get_Ah_counter_charging");
			ret.push_back("Get_Ah_counter_overall");
			ret.push_back("Get_Overall_Logdata");
			return ret;
		}
		if(sgn_name == "_20_conf_triggermode_i")
		{
			ret.push_back("CYCLIC");
			ret.push_back("TRIGGERED");
			ret.push_back("DISABLED");
			return ret;
		}
		if(sgn_name == "_21_conf_triggermode_u1")
		{
			ret.push_back("CYCLIC");
			ret.push_back("TRIGGERED");
			ret.push_back("DISABLED");
			return ret;
		}
		if(sgn_name == "_22_conf_triggermode_u2")
		{
			ret.push_back("CYCLIC");
			ret.push_back("TRIGGERED");
			ret.push_back("DISABLED");
			return ret;
		}
		if(sgn_name == "_23_conf_triggermode_u3")
		{
			ret.push_back("CYCLIC");
			ret.push_back("TRIGGERED");
			ret.push_back("DISABLED");
			return ret;
		}
		if(sgn_name == "_24_conf_triggermode_t")
		{
			ret.push_back("CYCLIC");
			ret.push_back("TRIGGERED");
			ret.push_back("DISABLED");
			return ret;
		}
		if(sgn_name == "_25_conf_triggermode_w")
		{
			ret.push_back("CYCLIC");
			ret.push_back("TRIGGERED");
			ret.push_back("DISABLED");
			return ret;
		}
		if(sgn_name == "_26_conf_triggermode_as")
		{
			ret.push_back("CYCLIC");
			ret.push_back("TRIGGERED");
			ret.push_back("DISABLED");
			return ret;
		}
		if(sgn_name == "_27_conf_triggermode_wh")
		{
			ret.push_back("CYCLIC");
			ret.push_back("TRIGGERED");
			ret.push_back("DISABLED");
			return ret;
		}
		if(sgn_name == "_34_actual_mode")
		{
			ret.push_back("START");
			ret.push_back("STOP");
			return ret;
		}
		if(sgn_name == "_34_startup_mode")
		{
			ret.push_back("START");
			ret.push_back("STOP");
			return ret;
		}
	}
	if(msg_name == BOARD_STATUS)
	{
		if(sgn_name == "cellboard_id")
		{
			ret.push_back("CELLBOARD_0");
			ret.push_back("CELLBOARD_1");
			ret.push_back("CELLBOARD_2");
			ret.push_back("CELLBOARD_3");
			ret.push_back("CELLBOARD_4");
			ret.push_back("CELLBOARD_5");
			return ret;
		}
		if(sgn_name == "balancing_status")
		{
			ret.push_back("OFF");
			ret.push_back("DISCHARGE");
			return ret;
		}
	}
	if(msg_name == TEMPERATURES_INFO)
	{
		if(sgn_name == "cellboard_id")
		{
			ret.push_back("CELLBOARD_0");
			ret.push_back("CELLBOARD_1");
			ret.push_back("CELLBOARD_2");
			ret.push_back("CELLBOARD_3");
			ret.push_back("CELLBOARD_4");
			ret.push_back("CELLBOARD_5");
			return ret;
		}
	}
	if(msg_name == TEMPERATURES)
	{
		if(sgn_name == "cellboard_id")
		{
			ret.push_back("CELLBOARD_0");
			ret.push_back("CELLBOARD_1");
			ret.push_back("CELLBOARD_2");
			ret.push_back("CELLBOARD_3");
			ret.push_back("CELLBOARD_4");
			ret.push_back("CELLBOARD_5");
			return ret;
		}
	}
	if(msg_name == VOLTAGES_INFO)
	{
		if(sgn_name == "cellboard_id")
		{
			ret.push_back("CELLBOARD_0");
			ret.push_back("CELLBOARD_1");
			ret.push_back("CELLBOARD_2");
			ret.push_back("CELLBOARD_3");
			ret.push_back("CELLBOARD_4");
			ret.push_back("CELLBOARD_5");
			return ret;
		}
	}
	if(msg_name == VOLTAGES)
	{
		if(sgn_name == "cellboard_id")
		{
			ret.push_back("CELLBOARD_0");
			ret.push_back("CELLBOARD_1");
			ret.push_back("CELLBOARD_2");
			ret.push_back("CELLBOARD_3");
			ret.push_back("CELLBOARD_4");
			ret.push_back("CELLBOARD_5");
			return ret;
		}
	}
	if(msg_name == SET_BALANCING_STATUS)
	{
		if(sgn_name == "balancing_status")
		{
			ret.push_back("OFF");
			ret.push_back("DISCHARGE");
			return ret;
		}
	}
	if(msg_name == CELLBOARD_FLASH)
	{
		if(sgn_name == "cellboard_id")
		{
			ret.push_back("CELLBOARD_0");
			ret.push_back("CELLBOARD_1");
			ret.push_back("CELLBOARD_2");
			ret.push_back("CELLBOARD_3");
			ret.push_back("CELLBOARD_4");
			ret.push_back("CELLBOARD_5");
			return ret;
		}
	}
	if(msg_name == CELLBOARD_FLASH_REQUEST)
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
	if(msg_name == CELLBOARD_FLASH_RESPONSE)
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
	if(msg_name == CELLBOARD_DISCOVERY)
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
	if(msg_name == CELLBOARD_VERSION)
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
	if(msg_name == CELLBOARD_STATUS)
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
		if(sgn_name == "status")
		{
			ret.push_back("init");
			ret.push_back("idle");
			ret.push_back("fatal");
			ret.push_back("flash");
			ret.push_back("discharge");
			ret.push_back("cooldown");
			return ret;
		}
	}
	if(msg_name == CELLBOARD_CELLS_VOLTAGE)
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
	if(msg_name == CELLBOARD_CELLS_TEMPERATURE)
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
	if(msg_name == CELLBOARD_BALANCING_STATUS)
	{
		if(sgn_name == "status")
		{
			ret.push_back("stopped");
			ret.push_back("paused");
			ret.push_back("running");
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
	if(msg_name == CELLBOARD_ERRORS)
	{
		if(sgn_name == "post")
		{
			ret.push_back("unset");
			ret.push_back("running");
			ret.push_back("expired");
			return ret;
		}
		if(sgn_name == "undervoltage")
		{
			ret.push_back("unset");
			ret.push_back("running");
			ret.push_back("expired");
			return ret;
		}
		if(sgn_name == "overvoltage")
		{
			ret.push_back("unset");
			ret.push_back("running");
			ret.push_back("expired");
			return ret;
		}
		if(sgn_name == "undertemperature_cells")
		{
			ret.push_back("unset");
			ret.push_back("running");
			ret.push_back("expired");
			return ret;
		}
		if(sgn_name == "undertemperature_discharge")
		{
			ret.push_back("unset");
			ret.push_back("running");
			ret.push_back("expired");
			return ret;
		}
		if(sgn_name == "overtemperature_cells")
		{
			ret.push_back("unset");
			ret.push_back("running");
			ret.push_back("expired");
			return ret;
		}
		if(sgn_name == "overtemperature_discharge")
		{
			ret.push_back("unset");
			ret.push_back("running");
			ret.push_back("expired");
			return ret;
		}
		if(sgn_name == "can")
		{
			ret.push_back("unset");
			ret.push_back("running");
			ret.push_back("expired");
			return ret;
		}
		if(sgn_name == "flash")
		{
			ret.push_back("unset");
			ret.push_back("running");
			ret.push_back("expired");
			return ret;
		}
		if(sgn_name == "bms_monitor")
		{
			ret.push_back("unset");
			ret.push_back("running");
			ret.push_back("expired");
			return ret;
		}
		if(sgn_name == "open_wire")
		{
			ret.push_back("unset");
			ret.push_back("running");
			ret.push_back("expired");
			return ret;
		}
	}

	return ret;
}
