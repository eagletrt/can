#include "inverters_utils.hpp"

int inverters_fields_string_from_id(int id, char **v, size_t fields_size, size_t string_size)
{
	switch(id)
    {
	case 513:
		if(30 > fields_size) return 1;
		snprintf(v[0], string_size, INV_L_SEND_SEND_MUX);
		snprintf(v[1], string_size, INV_L_SEND_READ_ID);
		snprintf(v[2], string_size, INV_L_SEND_KM_RSVD_0);
		snprintf(v[3], string_size, INV_L_SEND_M_SETDIG__IQ);
		snprintf(v[4], string_size, INV_L_SEND_DEF_DIN_1);
		snprintf(v[5], string_size, INV_L_SEND_DEF_END_1);
		snprintf(v[6], string_size, INV_L_SEND_I_MAX_PK);
		snprintf(v[7], string_size, INV_L_SEND_I_CON_EFF);
		snprintf(v[8], string_size, INV_L_SEND_I_DEVICE);
		snprintf(v[9], string_size, INV_L_SEND_N_R_LIM);
		snprintf(v[10], string_size, INV_L_SEND_NMAX100PERC);
		snprintf(v[11], string_size, INV_L_SEND_KM_SPEED_0);
		snprintf(v[12], string_size, INV_L_SEND_KM_FRG_OFF);
		snprintf(v[13], string_size, INV_L_SEND_KM_CAL_OFF);
		snprintf(v[14], string_size, INV_L_SEND_KM_TX_TOG_STAT);
		snprintf(v[15], string_size, INV_L_SEND_KM_I_LIMIT);
		snprintf(v[16], string_size, INV_L_SEND_KM_N_CLIP);
		snprintf(v[17], string_size, INV_L_SEND_KM_MIX_ANA_ON);
		snprintf(v[18], string_size, INV_L_SEND_RET_INTERVAL);
		snprintf(v[19], string_size, INV_L_SEND_KM_ALLOW_SYNC);
		snprintf(v[20], string_size, INV_L_SEND_KM_HANDWHEEL);
		snprintf(v[21], string_size, INV_L_SEND_KM_PHASING_EXTEND);
		snprintf(v[22], string_size, INV_L_SEND_KM_RSVD_11);
		snprintf(v[23], string_size, INV_L_SEND_KM_RSVD_12);
		snprintf(v[24], string_size, INV_L_SEND_KM_RSVD_13);
		snprintf(v[25], string_size, INV_L_SEND_KM_PSEUDO_ENABLE);
		snprintf(v[26], string_size, INV_L_SEND_KM_DEBUG_TEST);
		snprintf(v[27], string_size, INV_L_SEND_ACTIVE192);
		snprintf(v[28], string_size, INV_L_SEND_ACTIVE190);
		snprintf(v[29], string_size, INV_L_SEND_M_R_RCP);

		return 0;
	case 385:
		if(137 > fields_size) return 1;
		snprintf(v[0], string_size, INV_L_RCV_RCV_MUX);
		snprintf(v[1], string_size, INV_L_RCV_N_ACTUAL_FILT);
		snprintf(v[2], string_size, INV_L_RCV_ENA64);
		snprintf(v[3], string_size, INV_L_RCV_ERR_BADPARAS);
		snprintf(v[4], string_size, INV_L_RCV_DEF_END_1);
		snprintf(v[5], string_size, INV_L_RCV_LMT_ACTIVE_1);
		snprintf(v[6], string_size, INV_L_RCV_I_CMD);
		snprintf(v[7], string_size, INV_L_RCV_I_CMD_RAMP);
		snprintf(v[8], string_size, INV_L_RCV_IQ_ACTUAL);
		snprintf(v[9], string_size, INV_L_RCV_T_MOTOR);
		snprintf(v[10], string_size, INV_L_RCV_T_IGBT);
		snprintf(v[11], string_size, INV_L_RCV_VDC_BUS_FILT);
		snprintf(v[12], string_size, INV_L_RCV_KM_RSVD_0);
		snprintf(v[13], string_size, INV_L_RCV_ENA82);
		snprintf(v[14], string_size, INV_L_RCV_DEF_DIN_1);
		snprintf(v[15], string_size, INV_L_RCV_M_CMD_RAMP);
		snprintf(v[16], string_size, INV_L_RCV_I_MAX_PK);
		snprintf(v[17], string_size, INV_L_RCV_I_CON_EFF);
		snprintf(v[18], string_size, INV_L_RCV_I_DEVICE);
		snprintf(v[19], string_size, INV_L_RCV_N_R_LIM);
		snprintf(v[20], string_size, INV_L_RCV_NMAX100PERC);
		snprintf(v[21], string_size, INV_L_RCV_NCR064);
		snprintf(v[22], string_size, INV_L_RCV_ERR_POWERFAULT);
		snprintf(v[23], string_size, INV_L_RCV_LMT_ACTIVE_2);
		snprintf(v[24], string_size, INV_L_RCV_KM_SPEED_0);
		snprintf(v[25], string_size, INV_L_RCV_NCR082);
		snprintf(v[26], string_size, INV_L_RCV_LIM_PLUS64);
		snprintf(v[27], string_size, INV_L_RCV_ERR_RFE_FAULT);
		snprintf(v[28], string_size, INV_L_RCV_IN_ACTIVE_2);
		snprintf(v[29], string_size, INV_L_RCV_KM_FRG_OFF);
		snprintf(v[30], string_size, INV_L_RCV_LIM_PLUS82);
		snprintf(v[31], string_size, INV_L_RCV_LIM_MINUS64);
		snprintf(v[32], string_size, INV_L_RCV_ERR_BUSTIMEOUT);
		snprintf(v[33], string_size, INV_L_RCV_IN_ACTIVE_1);
		snprintf(v[34], string_size, INV_L_RCV_KM_CAL_OFF);
		snprintf(v[35], string_size, INV_L_RCV_LIM_MINUS82);
		snprintf(v[36], string_size, INV_L_RCV_OK64);
		snprintf(v[37], string_size, INV_L_RCV_ERR_FEEDBACKSIGNAL);
		snprintf(v[38], string_size, INV_L_RCV_FRGRUN);
		snprintf(v[39], string_size, INV_L_RCV_KM_TX_TOG_STAT);
		snprintf(v[40], string_size, INV_L_RCV_OK82);
		snprintf(v[41], string_size, INV_L_RCV_ICNS64);
		snprintf(v[42], string_size, INV_L_RCV_ERR_POWERVOLTAGE_LOW);
		snprintf(v[43], string_size, INV_L_RCV_RFE216);
		snprintf(v[44], string_size, INV_L_RCV_KM_I_LIMIT);
		snprintf(v[45], string_size, INV_L_RCV_ICNS82);
		snprintf(v[46], string_size, INV_L_RCV_TNLIM64);
		snprintf(v[47], string_size, INV_L_RCV_ERR_MOTORTEMP);
		snprintf(v[48], string_size, INV_L_RCV_KM_N_CLIP);
		snprintf(v[49], string_size, INV_L_RCV_TNLIM82);
		snprintf(v[50], string_size, INV_L_RCV_PN64);
		snprintf(v[51], string_size, INV_L_RCV_ERR_DEVICETEMP);
		snprintf(v[52], string_size, INV_L_RCV_KM_MIX_ANA_ON);
		snprintf(v[53], string_size, INV_L_RCV_PN82);
		snprintf(v[54], string_size, INV_L_RCV_NI64);
		snprintf(v[55], string_size, INV_L_RCV_ERR_OVERVOLTAGE);
		snprintf(v[56], string_size, INV_L_RCV_D_OUT_1_ON);
		snprintf(v[57], string_size, INV_L_RCV_KM_ALLOW_SYNC);
		snprintf(v[58], string_size, INV_L_RCV_NI82);
		snprintf(v[59], string_size, INV_L_RCV__N064);
		snprintf(v[60], string_size, INV_L_RCV_ERR_IPEAK);
		snprintf(v[61], string_size, INV_L_RCV_D_OUT_2_ON);
		snprintf(v[62], string_size, INV_L_RCV_KM_HANDWHEEL);
		snprintf(v[63], string_size, INV_L_RCV__N082);
		snprintf(v[64], string_size, INV_L_RCV_RSW64);
		snprintf(v[65], string_size, INV_L_RCV_ERR_RACEAWAY);
		snprintf(v[66], string_size, INV_L_RCV_BTBRDY);
		snprintf(v[67], string_size, INV_L_RCV_KM_PHASING_EXTEND);
		snprintf(v[68], string_size, INV_L_RCV_RSW82);
		snprintf(v[69], string_size, INV_L_RCV_CAL064);
		snprintf(v[70], string_size, INV_L_RCV_ERR_USER);
		snprintf(v[71], string_size, INV_L_RCV_GO216);
		snprintf(v[72], string_size, INV_L_RCV_KM_RSVD_11);
		snprintf(v[73], string_size, INV_L_RCV_CAL082);
		snprintf(v[74], string_size, INV_L_RCV_CAL64);
		snprintf(v[75], string_size, INV_L_RCV_D_OUT_3_ON);
		snprintf(v[76], string_size, INV_L_RCV_KM_RSVD_12);
		snprintf(v[77], string_size, INV_L_RCV_CAL82);
		snprintf(v[78], string_size, INV_L_RCV_TOL64);
		snprintf(v[79], string_size, INV_L_RCV_D_OUT_4_ON);
		snprintf(v[80], string_size, INV_L_RCV_KM_RSVD_13);
		snprintf(v[81], string_size, INV_L_RCV_TOL82);
		snprintf(v[82], string_size, INV_L_RCV_RDY64);
		snprintf(v[83], string_size, INV_L_RCV_ERR_HWERR);
		snprintf(v[84], string_size, INV_L_RCV_GOFF);
		snprintf(v[85], string_size, INV_L_RCV_KM_PSEUDO_ENABLE);
		snprintf(v[86], string_size, INV_L_RCV_RDY82);
		snprintf(v[87], string_size, INV_L_RCV_BRK064);
		snprintf(v[88], string_size, INV_L_RCV_ERR_BALLAST);
		snprintf(v[89], string_size, INV_L_RCV_ACTIVE190);
		snprintf(v[90], string_size, INV_L_RCV_BRK1216);
		snprintf(v[91], string_size, INV_L_RCV_KM_DEBUG_TEST);
		snprintf(v[92], string_size, INV_L_RCV_BRK082);
		snprintf(v[93], string_size, INV_L_RCV_ACTIVE192);
		snprintf(v[94], string_size, INV_L_RCV_SIGNMAG64);
		snprintf(v[95], string_size, INV_L_RCV_WARN_WARNING_0);
		snprintf(v[96], string_size, INV_L_RCV_SIGNMAG82);
		snprintf(v[97], string_size, INV_L_RCV_FREE);
		snprintf(v[98], string_size, INV_L_RCV_M_R_RCP);
		snprintf(v[99], string_size, INV_L_RCV_NCLIP64);
		snprintf(v[100], string_size, INV_L_RCV_WARN_ILLEGAL_STATUS);
		snprintf(v[101], string_size, INV_L_RCV_NCLIP82);
		snprintf(v[102], string_size, INV_L_RCV_NCLIP_MINUS64);
		snprintf(v[103], string_size, INV_L_RCV_WARN_SAFE_IN);
		snprintf(v[104], string_size, INV_L_RCV_NCLIP_MINUS82);
		snprintf(v[105], string_size, INV_L_RCV_NCLIP_PLUS64);
		snprintf(v[106], string_size, INV_L_RCV_NCLIP_PLUS82);
		snprintf(v[107], string_size, INV_L_RCV_IRDDIG64);
		snprintf(v[108], string_size, INV_L_RCV_IRDDIG82);
		snprintf(v[109], string_size, INV_L_RCV_IUSERCHD64);
		snprintf(v[110], string_size, INV_L_RCV_IUSERCHD82);
		snprintf(v[111], string_size, INV_L_RCV_IRDN64);
		snprintf(v[112], string_size, INV_L_RCV_WARN_MOTORTEMP);
		snprintf(v[113], string_size, INV_L_RCV_IRDN82);
		snprintf(v[114], string_size, INV_L_RCV_IRDTI64);
		snprintf(v[115], string_size, INV_L_RCV_WARN_DEVICETEMP);
		snprintf(v[116], string_size, INV_L_RCV_IRDTI82);
		snprintf(v[117], string_size, INV_L_RCV_IRDTIR64);
		snprintf(v[118], string_size, INV_L_RCV_WARN_VOUT_SAT);
		snprintf(v[119], string_size, INV_L_RCV_IRDTIR82);
		snprintf(v[120], string_size, INV_L_RCV__10HZ64);
		snprintf(v[121], string_size, INV_L_RCV_WARN_IPEAK);
		snprintf(v[122], string_size, INV_L_RCV__10HZ82);
		snprintf(v[123], string_size, INV_L_RCV_IRDTM64);
		snprintf(v[124], string_size, INV_L_RCV_WARN_RACEAWAY);
		snprintf(v[125], string_size, INV_L_RCV_IRDTM82);
		snprintf(v[126], string_size, INV_L_RCV_IRDANA64);
		snprintf(v[127], string_size, INV_L_RCV_IRDANA82);
		snprintf(v[128], string_size, INV_L_RCV_IWCNS64);
		snprintf(v[129], string_size, INV_L_RCV_IWCNS82);
		snprintf(v[130], string_size, INV_L_RCV_RFEPULSE64);
		snprintf(v[131], string_size, INV_L_RCV_RFEPULSE82);
		snprintf(v[132], string_size, INV_L_RCV_MD64);
		snprintf(v[133], string_size, INV_L_RCV_MD82);
		snprintf(v[134], string_size, INV_L_RCV_HNDWHL64);
		snprintf(v[135], string_size, INV_L_RCV_WARN_BALLAST);
		snprintf(v[136], string_size, INV_L_RCV_HNDWHL82);

		return 0;
	case 514:
		if(30 > fields_size) return 1;
		snprintf(v[0], string_size, INV_R_SEND_SEND_MUX);
		snprintf(v[1], string_size, INV_R_SEND_READ_ID);
		snprintf(v[2], string_size, INV_R_SEND_KM_RSVD_0);
		snprintf(v[3], string_size, INV_R_SEND_M_SETDIG__IQ);
		snprintf(v[4], string_size, INV_R_SEND_DEF_DIN_1);
		snprintf(v[5], string_size, INV_R_SEND_DEF_END_1);
		snprintf(v[6], string_size, INV_R_SEND_I_MAX_PK);
		snprintf(v[7], string_size, INV_R_SEND_I_CON_EFF);
		snprintf(v[8], string_size, INV_R_SEND_I_DEVICE);
		snprintf(v[9], string_size, INV_R_SEND_N_R_LIM);
		snprintf(v[10], string_size, INV_R_SEND_NMAX100PERC);
		snprintf(v[11], string_size, INV_R_SEND_KM_SPEED_0);
		snprintf(v[12], string_size, INV_R_SEND_KM_FRG_OFF);
		snprintf(v[13], string_size, INV_R_SEND_KM_CAL_OFF);
		snprintf(v[14], string_size, INV_R_SEND_KM_TX_TOG_STAT);
		snprintf(v[15], string_size, INV_R_SEND_KM_I_LIMIT);
		snprintf(v[16], string_size, INV_R_SEND_KM_N_CLIP);
		snprintf(v[17], string_size, INV_R_SEND_KM_MIX_ANA_ON);
		snprintf(v[18], string_size, INV_R_SEND_RET_INTERVAL);
		snprintf(v[19], string_size, INV_R_SEND_KM_ALLOW_SYNC);
		snprintf(v[20], string_size, INV_R_SEND_KM_HANDWHEEL);
		snprintf(v[21], string_size, INV_R_SEND_KM_PHASING_EXTEND);
		snprintf(v[22], string_size, INV_R_SEND_KM_RSVD_11);
		snprintf(v[23], string_size, INV_R_SEND_KM_RSVD_12);
		snprintf(v[24], string_size, INV_R_SEND_KM_RSVD_13);
		snprintf(v[25], string_size, INV_R_SEND_KM_PSEUDO_ENABLE);
		snprintf(v[26], string_size, INV_R_SEND_KM_DEBUG_TEST);
		snprintf(v[27], string_size, INV_R_SEND_ACTIVE192);
		snprintf(v[28], string_size, INV_R_SEND_ACTIVE190);
		snprintf(v[29], string_size, INV_R_SEND_M_R_RCP);

		return 0;
	case 386:
		if(137 > fields_size) return 1;
		snprintf(v[0], string_size, INV_R_RCV_RCV_MUX);
		snprintf(v[1], string_size, INV_R_RCV_N_ACTUAL_FILT);
		snprintf(v[2], string_size, INV_R_RCV_ENA64);
		snprintf(v[3], string_size, INV_R_RCV_ERR_BADPARAS);
		snprintf(v[4], string_size, INV_R_RCV_DEF_END_1);
		snprintf(v[5], string_size, INV_R_RCV_LMT_ACTIVE_1);
		snprintf(v[6], string_size, INV_R_RCV_I_CMD);
		snprintf(v[7], string_size, INV_R_RCV_I_CMD_RAMP);
		snprintf(v[8], string_size, INV_R_RCV_IQ_ACTUAL);
		snprintf(v[9], string_size, INV_R_RCV_T_MOTOR);
		snprintf(v[10], string_size, INV_R_RCV_T_IGBT);
		snprintf(v[11], string_size, INV_R_RCV_VDC_BUS_FILT);
		snprintf(v[12], string_size, INV_R_RCV_KM_RSVD_0);
		snprintf(v[13], string_size, INV_R_RCV_ENA82);
		snprintf(v[14], string_size, INV_R_RCV_DEF_DIN_1);
		snprintf(v[15], string_size, INV_R_RCV_M_CMD_RAMP);
		snprintf(v[16], string_size, INV_R_RCV_I_MAX_PK);
		snprintf(v[17], string_size, INV_R_RCV_I_CON_EFF);
		snprintf(v[18], string_size, INV_R_RCV_I_DEVICE);
		snprintf(v[19], string_size, INV_R_RCV_N_R_LIM);
		snprintf(v[20], string_size, INV_R_RCV_NMAX100PERC);
		snprintf(v[21], string_size, INV_R_RCV_NCR064);
		snprintf(v[22], string_size, INV_R_RCV_ERR_POWERFAULT);
		snprintf(v[23], string_size, INV_R_RCV_LMT_ACTIVE_2);
		snprintf(v[24], string_size, INV_R_RCV_KM_SPEED_0);
		snprintf(v[25], string_size, INV_R_RCV_NCR082);
		snprintf(v[26], string_size, INV_R_RCV_LIM_PLUS64);
		snprintf(v[27], string_size, INV_R_RCV_ERR_RFE_FAULT);
		snprintf(v[28], string_size, INV_R_RCV_IN_ACTIVE_2);
		snprintf(v[29], string_size, INV_R_RCV_KM_FRG_OFF);
		snprintf(v[30], string_size, INV_R_RCV_LIM_PLUS82);
		snprintf(v[31], string_size, INV_R_RCV_LIM_MINUS64);
		snprintf(v[32], string_size, INV_R_RCV_ERR_BUSTIMEOUT);
		snprintf(v[33], string_size, INV_R_RCV_IN_ACTIVE_1);
		snprintf(v[34], string_size, INV_R_RCV_KM_CAL_OFF);
		snprintf(v[35], string_size, INV_R_RCV_LIM_MINUS82);
		snprintf(v[36], string_size, INV_R_RCV_OK64);
		snprintf(v[37], string_size, INV_R_RCV_ERR_FEEDBACKSIGNAL);
		snprintf(v[38], string_size, INV_R_RCV_FRGRUN);
		snprintf(v[39], string_size, INV_R_RCV_KM_TX_TOG_STAT);
		snprintf(v[40], string_size, INV_R_RCV_OK82);
		snprintf(v[41], string_size, INV_R_RCV_ICNS64);
		snprintf(v[42], string_size, INV_R_RCV_ERR_POWERVOLTAGE_LOW);
		snprintf(v[43], string_size, INV_R_RCV_RFE216);
		snprintf(v[44], string_size, INV_R_RCV_KM_I_LIMIT);
		snprintf(v[45], string_size, INV_R_RCV_ICNS82);
		snprintf(v[46], string_size, INV_R_RCV_TNLIM64);
		snprintf(v[47], string_size, INV_R_RCV_ERR_MOTORTEMP);
		snprintf(v[48], string_size, INV_R_RCV_KM_N_CLIP);
		snprintf(v[49], string_size, INV_R_RCV_TNLIM82);
		snprintf(v[50], string_size, INV_R_RCV_PN64);
		snprintf(v[51], string_size, INV_R_RCV_ERR_DEVICETEMP);
		snprintf(v[52], string_size, INV_R_RCV_KM_MIX_ANA_ON);
		snprintf(v[53], string_size, INV_R_RCV_PN82);
		snprintf(v[54], string_size, INV_R_RCV_NI64);
		snprintf(v[55], string_size, INV_R_RCV_ERR_OVERVOLTAGE);
		snprintf(v[56], string_size, INV_R_RCV_D_OUT_1_ON);
		snprintf(v[57], string_size, INV_R_RCV_KM_ALLOW_SYNC);
		snprintf(v[58], string_size, INV_R_RCV_NI82);
		snprintf(v[59], string_size, INV_R_RCV__N064);
		snprintf(v[60], string_size, INV_R_RCV_ERR_IPEAK);
		snprintf(v[61], string_size, INV_R_RCV_D_OUT_2_ON);
		snprintf(v[62], string_size, INV_R_RCV_KM_HANDWHEEL);
		snprintf(v[63], string_size, INV_R_RCV__N082);
		snprintf(v[64], string_size, INV_R_RCV_RSW64);
		snprintf(v[65], string_size, INV_R_RCV_ERR_RACEAWAY);
		snprintf(v[66], string_size, INV_R_RCV_BTBRDY);
		snprintf(v[67], string_size, INV_R_RCV_KM_PHASING_EXTEND);
		snprintf(v[68], string_size, INV_R_RCV_RSW82);
		snprintf(v[69], string_size, INV_R_RCV_CAL064);
		snprintf(v[70], string_size, INV_R_RCV_ERR_USER);
		snprintf(v[71], string_size, INV_R_RCV_GO216);
		snprintf(v[72], string_size, INV_R_RCV_KM_RSVD_11);
		snprintf(v[73], string_size, INV_R_RCV_CAL082);
		snprintf(v[74], string_size, INV_R_RCV_CAL64);
		snprintf(v[75], string_size, INV_R_RCV_D_OUT_3_ON);
		snprintf(v[76], string_size, INV_R_RCV_KM_RSVD_12);
		snprintf(v[77], string_size, INV_R_RCV_CAL82);
		snprintf(v[78], string_size, INV_R_RCV_TOL64);
		snprintf(v[79], string_size, INV_R_RCV_D_OUT_4_ON);
		snprintf(v[80], string_size, INV_R_RCV_KM_RSVD_13);
		snprintf(v[81], string_size, INV_R_RCV_TOL82);
		snprintf(v[82], string_size, INV_R_RCV_RDY64);
		snprintf(v[83], string_size, INV_R_RCV_ERR_HWERR);
		snprintf(v[84], string_size, INV_R_RCV_GOFF);
		snprintf(v[85], string_size, INV_R_RCV_KM_PSEUDO_ENABLE);
		snprintf(v[86], string_size, INV_R_RCV_RDY82);
		snprintf(v[87], string_size, INV_R_RCV_BRK064);
		snprintf(v[88], string_size, INV_R_RCV_ERR_BALLAST);
		snprintf(v[89], string_size, INV_R_RCV_ACTIVE190);
		snprintf(v[90], string_size, INV_R_RCV_BRK1216);
		snprintf(v[91], string_size, INV_R_RCV_KM_DEBUG_TEST);
		snprintf(v[92], string_size, INV_R_RCV_BRK082);
		snprintf(v[93], string_size, INV_R_RCV_ACTIVE192);
		snprintf(v[94], string_size, INV_R_RCV_SIGNMAG64);
		snprintf(v[95], string_size, INV_R_RCV_WARN_WARNING_0);
		snprintf(v[96], string_size, INV_R_RCV_SIGNMAG82);
		snprintf(v[97], string_size, INV_R_RCV_FREE);
		snprintf(v[98], string_size, INV_R_RCV_M_R_RCP);
		snprintf(v[99], string_size, INV_R_RCV_NCLIP64);
		snprintf(v[100], string_size, INV_R_RCV_WARN_ILLEGAL_STATUS);
		snprintf(v[101], string_size, INV_R_RCV_NCLIP82);
		snprintf(v[102], string_size, INV_R_RCV_NCLIP_MINUS64);
		snprintf(v[103], string_size, INV_R_RCV_WARN_SAFE_IN);
		snprintf(v[104], string_size, INV_R_RCV_NCLIP_MINUS82);
		snprintf(v[105], string_size, INV_R_RCV_NCLIP_PLUS64);
		snprintf(v[106], string_size, INV_R_RCV_NCLIP_PLUS82);
		snprintf(v[107], string_size, INV_R_RCV_IRDDIG64);
		snprintf(v[108], string_size, INV_R_RCV_IRDDIG82);
		snprintf(v[109], string_size, INV_R_RCV_IUSERCHD64);
		snprintf(v[110], string_size, INV_R_RCV_IUSERCHD82);
		snprintf(v[111], string_size, INV_R_RCV_IRDN64);
		snprintf(v[112], string_size, INV_R_RCV_WARN_MOTORTEMP);
		snprintf(v[113], string_size, INV_R_RCV_IRDN82);
		snprintf(v[114], string_size, INV_R_RCV_IRDTI64);
		snprintf(v[115], string_size, INV_R_RCV_WARN_DEVICETEMP);
		snprintf(v[116], string_size, INV_R_RCV_IRDTI82);
		snprintf(v[117], string_size, INV_R_RCV_IRDTIR64);
		snprintf(v[118], string_size, INV_R_RCV_WARN_VOUT_SAT);
		snprintf(v[119], string_size, INV_R_RCV_IRDTIR82);
		snprintf(v[120], string_size, INV_R_RCV__10HZ64);
		snprintf(v[121], string_size, INV_R_RCV_WARN_IPEAK);
		snprintf(v[122], string_size, INV_R_RCV__10HZ82);
		snprintf(v[123], string_size, INV_R_RCV_IRDTM64);
		snprintf(v[124], string_size, INV_R_RCV_WARN_RACEAWAY);
		snprintf(v[125], string_size, INV_R_RCV_IRDTM82);
		snprintf(v[126], string_size, INV_R_RCV_IRDANA64);
		snprintf(v[127], string_size, INV_R_RCV_IRDANA82);
		snprintf(v[128], string_size, INV_R_RCV_IWCNS64);
		snprintf(v[129], string_size, INV_R_RCV_IWCNS82);
		snprintf(v[130], string_size, INV_R_RCV_RFEPULSE64);
		snprintf(v[131], string_size, INV_R_RCV_RFEPULSE82);
		snprintf(v[132], string_size, INV_R_RCV_MD64);
		snprintf(v[133], string_size, INV_R_RCV_MD82);
		snprintf(v[134], string_size, INV_R_RCV_HNDWHL64);
		snprintf(v[135], string_size, INV_R_RCV_WARN_BALLAST);
		snprintf(v[136], string_size, INV_R_RCV_HNDWHL82);

		return 0;

    }
    return 0;
}
int inverters_enum_fields(int enum_id, char **v, size_t fields_size, size_t string_size)
{
    switch(enum_id)
    {
	case 0:
		if(131 > fields_size) return 1;
		snprintf(v[0], string_size, "inverters_inv_l_send_send_mux_ID_04_USER_Key");
		snprintf(v[1], string_size, "inverters_inv_l_send_send_mux_ID_05_Motor_F_nom");
		snprintf(v[2], string_size, "inverters_inv_l_send_send_mux_ID_07_FU_T_dc");
		snprintf(v[3], string_size, "inverters_inv_l_send_send_mux_ID_08_FU_V_dc");
		snprintf(v[4], string_size, "inverters_inv_l_send_send_mux_ID_09_FU_Special");
		snprintf(v[5], string_size, "inverters_inv_l_send_send_mux_ID_0A_FU_U_min");
		snprintf(v[6], string_size, "inverters_inv_l_send_send_mux_ID_0B_FU_F_min");
		snprintf(v[7], string_size, "inverters_inv_l_send_send_mux_ID_0C_FU_V_corner");
		snprintf(v[8], string_size, "inverters_inv_l_send_send_mux_ID_0D_FU_F_corner");
		snprintf(v[9], string_size, "inverters_inv_l_send_send_mux_ID_0E_Motor_Cos_Phi");
		snprintf(v[10], string_size, "inverters_inv_l_send_send_mux_ID_0F_FU_Extra");
		snprintf(v[11], string_size, "inverters_inv_l_send_send_mux_ID_10_Oszi_Channel");
		snprintf(v[12], string_size, "inverters_inv_l_send_send_mux_ID_12_Oszi_Triger_Level");
		snprintf(v[13], string_size, "inverters_inv_l_send_send_mux_ID_13_Oszi_Triger_Edge");
		snprintf(v[14], string_size, "inverters_inv_l_send_send_mux_ID_14_Oszi_Triger_Source");
		snprintf(v[15], string_size, "inverters_inv_l_send_send_mux_ID_15_Oszi_Source");
		snprintf(v[16], string_size, "inverters_inv_l_send_send_mux_ID_16_Oszi_Skip");
		snprintf(v[17], string_size, "inverters_inv_l_send_send_mux_ID_17_Oszi_Read_cmd");
		snprintf(v[18], string_size, "inverters_inv_l_send_send_mux_ID_18_Oszi_Run_cmd");
		snprintf(v[19], string_size, "inverters_inv_l_send_send_mux_ID_1A_Calib_Ref_Value");
		snprintf(v[20], string_size, "inverters_inv_l_send_send_mux_ID_1C_PID_I_Kp");
		snprintf(v[21], string_size, "inverters_inv_l_send_send_mux_ID_1D_PID_I_Ti");
		snprintf(v[22], string_size, "inverters_inv_l_send_send_mux_ID_1E_Cutoffdig");
		snprintf(v[23], string_size, "inverters_inv_l_send_send_mux_ID_21_Id_setdig");
		snprintf(v[24], string_size, "inverters_inv_l_send_send_mux_ID_25_I_Delta_Ramp");
		snprintf(v[25], string_size, "inverters_inv_l_send_send_mux_ID_2B_PID_I_TiM");
		snprintf(v[26], string_size, "inverters_inv_l_send_send_mux_ID_2C_PID_n_Kp");
		snprintf(v[27], string_size, "inverters_inv_l_send_send_mux_ID_2D_PID_n_Ti");
		snprintf(v[28], string_size, "inverters_inv_l_send_send_mux_ID_2E_PID_n_Td");
		snprintf(v[29], string_size, "inverters_inv_l_send_send_mux_ID_2F_Ain_in_1_OffsScale");
		snprintf(v[30], string_size, "inverters_inv_l_send_send_mux_ID_31_N_setdig");
		snprintf(v[31], string_size, "inverters_inv_l_send_send_mux_ID_34_N_Lim");
		snprintf(v[32], string_size, "inverters_inv_l_send_send_mux_ID_35_Acc_Ramps");
		snprintf(v[33], string_size, "inverters_inv_l_send_send_mux_ID_36_CommandSource");
		snprintf(v[34], string_size, "inverters_inv_l_send_send_mux_ID_3B_PID_n_TiM");
		snprintf(v[35], string_size, "inverters_inv_l_send_send_mux_ID_3C_I_Derating_N_perc");
		snprintf(v[36], string_size, "inverters_inv_l_send_send_mux_ID_3E_N_Lim_minus");
		snprintf(v[37], string_size, "inverters_inv_l_send_send_mux_ID_3F_N_Lim_plus");
		snprintf(v[38], string_size, "inverters_inv_l_send_send_mux_ID_44_FeedBack_Offset_Angle");
		snprintf(v[39], string_size, "inverters_inv_l_send_send_mux_ID_3D_Read_Cmd");
		snprintf(v[40], string_size, "inverters_inv_l_send_send_mux_ID_46_I_lim_dig_perc");
		snprintf(v[41], string_size, "inverters_inv_l_send_send_mux_ID_4C_I_Derating_TE");
		snprintf(v[42], string_size, "inverters_inv_l_send_send_mux_ID_4D_Motor_I_max_eff_Arms");
		snprintf(v[43], string_size, "inverters_inv_l_send_send_mux_ID_4E_Motor_I_nom_eff_Arms");
		snprintf(v[44], string_size, "inverters_inv_l_send_send_mux_ID_4F_Motor_Pole_Number");
		snprintf(v[45], string_size, "inverters_inv_l_send_send_mux_ID_50_Ain_in_1_Cutoff");
		snprintf(v[46], string_size, "inverters_inv_l_send_send_mux_ID_51_Kern_Mode_State");
		snprintf(v[47], string_size, "inverters_inv_l_send_send_mux_ID_53_Ain_in_2_Cutoff");
		snprintf(v[48], string_size, "inverters_inv_l_send_send_mux_ID_58_I_Derating_TD");
		snprintf(v[49], string_size, "inverters_inv_l_send_send_mux_ID_59_Motor_Nominal_Speed");
		snprintf(v[50], string_size, "inverters_inv_l_send_send_mux_ID_5A_Device_Options");
		snprintf(v[51], string_size, "inverters_inv_l_send_send_mux_ID_5B_PID_n_Kacc");
		snprintf(v[52], string_size, "inverters_inv_l_send_send_mux_ID_5E_Speed_Filter");
		snprintf(v[53], string_size, "inverters_inv_l_send_send_mux_ID_60_Ain_in_X_Filter");
		snprintf(v[54], string_size, "inverters_inv_l_send_send_mux_ID_62_SerialNumber");
		snprintf(v[55], string_size, "inverters_inv_l_send_send_mux_ID_64_Device_Mains_Supply_V");
		snprintf(v[56], string_size, "inverters_inv_l_send_send_mux_ID_65_Regen_Resistor_P_and_R");
		snprintf(v[57], string_size, "inverters_inv_l_send_send_mux_ID_67_Device_Type");
		snprintf(v[58], string_size, "inverters_inv_l_send_send_mux_ID_68_CAN_ID_Rx");
		snprintf(v[59], string_size, "inverters_inv_l_send_send_mux_ID_69_CAN_ID_Tx");
		snprintf(v[60], string_size, "inverters_inv_l_send_send_mux_ID_6A_Pos_PID_Kp");
		snprintf(v[61], string_size, "inverters_inv_l_send_send_mux_ID_6B_Pos_PID_Ti");
		snprintf(v[62], string_size, "inverters_inv_l_send_send_mux_ID_6C_Pos_PID_Td");
		snprintf(v[63], string_size, "inverters_inv_l_send_send_mux_ID_6E_Pos_Destination");
		snprintf(v[64], string_size, "inverters_inv_l_send_send_mux_ID_71_Pos_PID_TiM");
		snprintf(v[65], string_size, "inverters_inv_l_send_send_mux_ID_72_Pos_OffsetReference");
		snprintf(v[66], string_size, "inverters_inv_l_send_send_mux_ID_73_CAN_NBT");
		snprintf(v[67], string_size, "inverters_inv_l_send_send_mux_ID_75_Pos_Ref_Reso_Edge");
		snprintf(v[68], string_size, "inverters_inv_l_send_send_mux_ID_76_Pos_Calib_Speed_1");
		snprintf(v[69], string_size, "inverters_inv_l_send_send_mux_ID_77_Pos_Calib_Speed_2");
		snprintf(v[70], string_size, "inverters_inv_l_send_send_mux_ID_79_Pos_Tol_Window");
		snprintf(v[71], string_size, "inverters_inv_l_send_send_mux_ID_7A_Pos_Preset_Value");
		snprintf(v[72], string_size, "inverters_inv_l_send_send_mux_ID_7C_Pos_NDrive_Scale");
		snprintf(v[73], string_size, "inverters_inv_l_send_send_mux_ID_7D_Pos_NDrive_Offset");
		snprintf(v[74], string_size, "inverters_inv_l_send_send_mux_ID_7E_Pos_FB2_Scale_Fac_Ext");
		snprintf(v[75], string_size, "inverters_inv_l_send_send_mux_ID_7F_Pos_Offset_Slack");
		snprintf(v[76], string_size, "inverters_inv_l_send_send_mux_ID_80_Pos_Diff_Slack");
		snprintf(v[77], string_size, "inverters_inv_l_send_send_mux_ID_83_Function_Parameter_Read");
		snprintf(v[78], string_size, "inverters_inv_l_send_send_mux_ID_84_Function_Parameter_Write");
		snprintf(v[79], string_size, "inverters_inv_l_send_send_mux_ID_85_Function_Special");
		snprintf(v[80], string_size, "inverters_inv_l_send_send_mux_ID_88_CAN_ID_2_Rx");
		snprintf(v[81], string_size, "inverters_inv_l_send_send_mux_ID_89_CAN_ID_2_Tx");
		snprintf(v[82], string_size, "inverters_inv_l_send_send_mux_ID_8B_VoltageControl_Ref");
		snprintf(v[83], string_size, "inverters_inv_l_send_send_mux_ID_8C_VoltageControl_Kp");
		snprintf(v[84], string_size, "inverters_inv_l_send_send_mux_ID_8D_VoltageControl_Ti");
		snprintf(v[85], string_size, "inverters_inv_l_send_send_mux_ID_8E_Clear_Error_List");
		snprintf(v[86], string_size, "inverters_inv_l_send_send_mux_ID_90_M_setdig");
		snprintf(v[87], string_size, "inverters_inv_l_send_send_mux_ID_A2_I_Derating_TM");
		snprintf(v[88], string_size, "inverters_inv_l_send_send_mux_ID_A3_Motor_Temp_Error_Lim");
		snprintf(v[89], string_size, "inverters_inv_l_send_send_mux_ID_A4_Motor_Options");
		snprintf(v[90], string_size, "inverters_inv_l_send_send_mux_ID_A5_Device_DC_Bus_MinMax_Lim");
		snprintf(v[91], string_size, "inverters_inv_l_send_send_mux_ID_A6_FB_IncrementsPerRot");
		snprintf(v[92], string_size, "inverters_inv_l_send_send_mux_ID_A7_FB_Pole_Number");
		snprintf(v[93], string_size, "inverters_inv_l_send_send_mux_ID_B1_Motor_L_Sigma_Q");
		snprintf(v[94], string_size, "inverters_inv_l_send_send_mux_ID_B2_Id_Nominal");
		snprintf(v[95], string_size, "inverters_inv_l_send_send_mux_ID_B3_Motor_Magn_Inductance");
		snprintf(v[96], string_size, "inverters_inv_l_send_send_mux_ID_B4_Motor_Rotor_Resistance");
		snprintf(v[97], string_size, "inverters_inv_l_send_send_mux_ID_B5_Id_Minimum");
		snprintf(v[98], string_size, "inverters_inv_l_send_send_mux_ID_B6_Time_Constant_Rotor");
		snprintf(v[99], string_size, "inverters_inv_l_send_send_mux_ID_BB_Motor_L_Sigma_D");
		snprintf(v[100], string_size, "inverters_inv_l_send_send_mux_ID_BC_Motor_Stator_Resistance");
		snprintf(v[101], string_size, "inverters_inv_l_send_send_mux_ID_BD_Time_Constant_Stator");
		snprintf(v[102], string_size, "inverters_inv_l_send_send_mux_ID_BE_LogicDefine_of_END_1");
		snprintf(v[103], string_size, "inverters_inv_l_send_send_mux_ID_BF_LogicDefine_of_END_2");
		snprintf(v[104], string_size, "inverters_inv_l_send_send_mux_ID_C0_LogicDefine_of_DIN_1");
		snprintf(v[105], string_size, "inverters_inv_l_send_send_mux_ID_C1_LogicDefine_of_DIN_2");
		snprintf(v[106], string_size, "inverters_inv_l_send_send_mux_ID_C2_LogicDefine_of_OUT_1");
		snprintf(v[107], string_size, "inverters_inv_l_send_send_mux_ID_C3_LogicDefine_of_OUT_2");
		snprintf(v[108], string_size, "inverters_inv_l_send_send_mux_ID_DA_LogicDefine_of_OUT_3");
		snprintf(v[109], string_size, "inverters_inv_l_send_send_mux_ID_DB_LogicDefine_of_OUT_4");
		snprintf(v[110], string_size, "inverters_inv_l_send_send_mux_ID_C4_I_max_pk_perc");
		snprintf(v[111], string_size, "inverters_inv_l_send_send_mux_ID_C5_I_con_eff_perc");
		snprintf(v[112], string_size, "inverters_inv_l_send_send_mux_ID_C6_I_device");
		snprintf(v[113], string_size, "inverters_inv_l_send_send_mux_ID_C7_RLim_MRcp_Ramp");
		snprintf(v[114], string_size, "inverters_inv_l_send_send_mux_ID_C8_Nmax100perc");
		snprintf(v[115], string_size, "inverters_inv_l_send_send_mux_ID_C9_CurrentControl_xKp");
		snprintf(v[116], string_size, "inverters_inv_l_send_send_mux_ID_CA_Bat_Opr_Limits");
		snprintf(v[117], string_size, "inverters_inv_l_send_send_mux_ID_CB_PID_I_Kf");
		snprintf(v[118], string_size, "inverters_inv_l_send_send_mux_ID_CD_Car_Mode_Config");
		snprintf(v[119], string_size, "inverters_inv_l_send_send_mux_ID_D0_CAN_Timeout");
		snprintf(v[120], string_size, "inverters_inv_l_send_send_mux_ID_D1_Var_1");
		snprintf(v[121], string_size, "inverters_inv_l_send_send_mux_ID_D2_Var_2");
		snprintf(v[122], string_size, "inverters_inv_l_send_send_mux_ID_D3_Var_3");
		snprintf(v[123], string_size, "inverters_inv_l_send_send_mux_ID_D4_Var_4");
		snprintf(v[124], string_size, "inverters_inv_l_send_send_mux_ID_D7_Ain_in_2_OffsScale");
		snprintf(v[125], string_size, "inverters_inv_l_send_send_mux_ID_DC_DAC_Source_ID");
		snprintf(v[126], string_size, "inverters_inv_l_send_send_mux_ID_ED_Dec_Ramps");
		snprintf(v[127], string_size, "inverters_inv_l_send_send_mux_ID_EE_V_Shunt");
		snprintf(v[128], string_size, "inverters_inv_l_send_send_mux_ID_F0_Time_I_Peak");
		snprintf(v[129], string_size, "inverters_inv_l_send_send_mux_ID_F1_Brake_Delay");
		snprintf(v[130], string_size, "inverters_inv_l_send_send_mux_ID_F8_Axis_Label");

		return 0;
	case 1:
		if(229 > fields_size) return 1;
		snprintf(v[0], string_size, "inverters_inv_l_send_read_id_05h_Motor_F_nom");
		snprintf(v[1], string_size, "inverters_inv_l_send_read_id_06h_Motor_V_nom");
		snprintf(v[2], string_size, "inverters_inv_l_send_read_id_07h_FU_T_dc");
		snprintf(v[3], string_size, "inverters_inv_l_send_read_id_08h_FU_V_dc");
		snprintf(v[4], string_size, "inverters_inv_l_send_read_id_09h_FU_Special");
		snprintf(v[5], string_size, "inverters_inv_l_send_read_id_0Ah_FU_U_min");
		snprintf(v[6], string_size, "inverters_inv_l_send_read_id_0Bh_FU_F_min");
		snprintf(v[7], string_size, "inverters_inv_l_send_read_id_0Ch_FU_V_corner");
		snprintf(v[8], string_size, "inverters_inv_l_send_read_id_0Dh_FU_F_corner");
		snprintf(v[9], string_size, "inverters_inv_l_send_read_id_0Eh_Motor_Cos_Phi");
		snprintf(v[10], string_size, "inverters_inv_l_send_read_id_0Fh_FU_Extra");
		snprintf(v[11], string_size, "inverters_inv_l_send_read_id_10h_Oszi_Channel");
		snprintf(v[12], string_size, "inverters_inv_l_send_read_id_11h_Control_Status");
		snprintf(v[13], string_size, "inverters_inv_l_send_read_id_12h_Oszi_Triger_Level");
		snprintf(v[14], string_size, "inverters_inv_l_send_read_id_13h_Oszi_Triger_Edge");
		snprintf(v[15], string_size, "inverters_inv_l_send_read_id_14h_Oszi_Triger_Source");
		snprintf(v[16], string_size, "inverters_inv_l_send_read_id_15h_Oszi_Source");
		snprintf(v[17], string_size, "inverters_inv_l_send_read_id_16h_Oszi_Skip");
		snprintf(v[18], string_size, "inverters_inv_l_send_read_id_17h_Oszi_Read_cmd");
		snprintf(v[19], string_size, "inverters_inv_l_send_read_id_18h_Oszi_Run_cmd");
		snprintf(v[20], string_size, "inverters_inv_l_send_read_id_19h_PWM_Enum");
		snprintf(v[21], string_size, "inverters_inv_l_send_read_id_1Ah_Calib_Ref_Value");
		snprintf(v[22], string_size, "inverters_inv_l_send_read_id_1Bh_FW_Nr");
		snprintf(v[23], string_size, "inverters_inv_l_send_read_id_1Ch_I_Kp");
		snprintf(v[24], string_size, "inverters_inv_l_send_read_id_1Dh_I_Ti");
		snprintf(v[25], string_size, "inverters_inv_l_send_read_id_1Eh_Cutoffdig");
		snprintf(v[26], string_size, "inverters_inv_l_send_read_id_1Fh_I3_Offset");
		snprintf(v[27], string_size, "inverters_inv_l_send_read_id_20h_I_Actual");
		snprintf(v[28], string_size, "inverters_inv_l_send_read_id_21h_Id_setdig");
		snprintf(v[29], string_size, "inverters_inv_l_send_read_id_22h_I_cmd_ramp");
		snprintf(v[30], string_size, "inverters_inv_l_send_read_id_23h_Id_Ref");
		snprintf(v[31], string_size, "inverters_inv_l_send_read_id_24h_I_Max_Inuse");
		snprintf(v[32], string_size, "inverters_inv_l_send_read_id_25h_I_Delta_Ramp");
		snprintf(v[33], string_size, "inverters_inv_l_send_read_id_26h_I_cmd");
		snprintf(v[34], string_size, "inverters_inv_l_send_read_id_27h_Iq_Actual");
		snprintf(v[35], string_size, "inverters_inv_l_send_read_id_28h_Id_Actual");
		snprintf(v[36], string_size, "inverters_inv_l_send_read_id_29h_Vq_Output");
		snprintf(v[37], string_size, "inverters_inv_l_send_read_id_2Ah_Vd_Output");
		snprintf(v[38], string_size, "inverters_inv_l_send_read_id_2Bh_I_TiM");
		snprintf(v[39], string_size, "inverters_inv_l_send_read_id_2Ch_n_Kp");
		snprintf(v[40], string_size, "inverters_inv_l_send_read_id_2Dh_n_Ti");
		snprintf(v[41], string_size, "inverters_inv_l_send_read_id_2Eh_n_Td");
		snprintf(v[42], string_size, "inverters_inv_l_send_read_id_2Fh_Ain_in_1_OffsScale");
		snprintf(v[43], string_size, "inverters_inv_l_send_read_id_30h_N_Actual");
		snprintf(v[44], string_size, "inverters_inv_l_send_read_id_31h_N_setdig");
		snprintf(v[45], string_size, "inverters_inv_l_send_read_id_32h_N_cmd_ramp");
		snprintf(v[46], string_size, "inverters_inv_l_send_read_id_33h_N_Error");
		snprintf(v[47], string_size, "inverters_inv_l_send_read_id_34h_N_Lim");
		snprintf(v[48], string_size, "inverters_inv_l_send_read_id_35h_Acc_Ramps");
		snprintf(v[49], string_size, "inverters_inv_l_send_read_id_36h_CommandSource");
		snprintf(v[50], string_size, "inverters_inv_l_send_read_id_37h_DZR_Sequencer_Value");
		snprintf(v[51], string_size, "inverters_inv_l_send_read_id_38h_Iq_Error");
		snprintf(v[52], string_size, "inverters_inv_l_send_read_id_39h_Id_Error");
		snprintf(v[53], string_size, "inverters_inv_l_send_read_id_3Bh_n_TiM");
		snprintf(v[54], string_size, "inverters_inv_l_send_read_id_3Ch_I_Derating_N_perc");
		snprintf(v[55], string_size, "inverters_inv_l_send_read_id_3Eh_N_Lim_minus");
		snprintf(v[56], string_size, "inverters_inv_l_send_read_id_3Fh_N_Lim_plus");
		snprintf(v[57], string_size, "inverters_inv_l_send_read_id_40h_Status_Map");
		snprintf(v[58], string_size, "inverters_inv_l_send_read_id_41h_Incr_Delta");
		snprintf(v[59], string_size, "inverters_inv_l_send_read_id_42h_MotorPosition_Mech");
		snprintf(v[60], string_size, "inverters_inv_l_send_read_id_43h_MotorPosition_Elec");
		snprintf(v[61], string_size, "inverters_inv_l_send_read_id_44h_FeedBack_Offset_Angle");
		snprintf(v[62], string_size, "inverters_inv_l_send_read_id_45h_Ixt_and_RegenE_Monitor");
		snprintf(v[63], string_size, "inverters_inv_l_send_read_id_46h_I_lim_dig_perc");
		snprintf(v[64], string_size, "inverters_inv_l_send_read_id_48h_I_Limit_Inuse");
		snprintf(v[65], string_size, "inverters_inv_l_send_read_id_49h_T_Motor");
		snprintf(v[66], string_size, "inverters_inv_l_send_read_id_4Ah_T_Igbt");
		snprintf(v[67], string_size, "inverters_inv_l_send_read_id_4Bh_T_Air_Inside");
		snprintf(v[68], string_size, "inverters_inv_l_send_read_id_4Ch_I_Derating_TE");
		snprintf(v[69], string_size, "inverters_inv_l_send_read_id_4Dh_Motor_I_max_eff");
		snprintf(v[70], string_size, "inverters_inv_l_send_read_id_4Eh_Motor_I_nom_eff");
		snprintf(v[71], string_size, "inverters_inv_l_send_read_id_4Fh_Motor_Pole");
		snprintf(v[72], string_size, "inverters_inv_l_send_read_id_50h_Ain_in_1_Cutoff");
		snprintf(v[73], string_size, "inverters_inv_l_send_read_id_51h_Kern_Mode_State");
		snprintf(v[74], string_size, "inverters_inv_l_send_read_id_52h_Status_Mask");
		snprintf(v[75], string_size, "inverters_inv_l_send_read_id_53h_Ain_in_2_Cutoff");
		snprintf(v[76], string_size, "inverters_inv_l_send_read_id_54h_I1_Actual");
		snprintf(v[77], string_size, "inverters_inv_l_send_read_id_55h_I2_Actual");
		snprintf(v[78], string_size, "inverters_inv_l_send_read_id_56h_I3_Actual");
		snprintf(v[79], string_size, "inverters_inv_l_send_read_id_57h_I_Limit_Inuse_ramp");
		snprintf(v[80], string_size, "inverters_inv_l_send_read_id_58h_I_Derating_TD");
		snprintf(v[81], string_size, "inverters_inv_l_send_read_id_59h_Motor_Nom");
		snprintf(v[82], string_size, "inverters_inv_l_send_read_id_5Ah_Device_Options");
		snprintf(v[83], string_size, "inverters_inv_l_send_read_id_5Bh_SpeedControl_Kacc");
		snprintf(v[84], string_size, "inverters_inv_l_send_read_id_5Ch_Rotor_Signals");
		snprintf(v[85], string_size, "inverters_inv_l_send_read_id_5Dh_N_cmd");
		snprintf(v[86], string_size, "inverters_inv_l_send_read_id_5Eh_Speed_Filter");
		snprintf(v[87], string_size, "inverters_inv_l_send_read_id_5Fh_I_Actual_Filt");
		snprintf(v[88], string_size, "inverters_inv_l_send_read_id_60h_Ain_in_X_Filter");
		snprintf(v[89], string_size, "inverters_inv_l_send_read_id_61h_Ixt_Monitor");
		snprintf(v[90], string_size, "inverters_inv_l_send_read_id_62h_SerialNumber");
		snprintf(v[91], string_size, "inverters_inv_l_send_read_id_63h_FPGA_Status");
		snprintf(v[92], string_size, "inverters_inv_l_send_read_id_64h_Device_Mains");
		snprintf(v[93], string_size, "inverters_inv_l_send_read_id_65h_Regen_P_R");
		snprintf(v[94], string_size, "inverters_inv_l_send_read_id_67h_Device_Type");
		snprintf(v[95], string_size, "inverters_inv_l_send_read_id_68h_CAN_ID_Rx");
		snprintf(v[96], string_size, "inverters_inv_l_send_read_id_69h_CAN_ID_Tx");
		snprintf(v[97], string_size, "inverters_inv_l_send_read_id_6Ah_Pos_Kp");
		snprintf(v[98], string_size, "inverters_inv_l_send_read_id_6Bh_Pos_Ti");
		snprintf(v[99], string_size, "inverters_inv_l_send_read_id_6Ch_Pos_Td");
		snprintf(v[100], string_size, "inverters_inv_l_send_read_id_6Dh_Pos_Actual");
		snprintf(v[101], string_size, "inverters_inv_l_send_read_id_6Eh_Pos_Dest");
		snprintf(v[102], string_size, "inverters_inv_l_send_read_id_6Fh_Pos_Actual_2");
		snprintf(v[103], string_size, "inverters_inv_l_send_read_id_70h_Pos_Err");
		snprintf(v[104], string_size, "inverters_inv_l_send_read_id_71h_Pos_TiM");
		snprintf(v[105], string_size, "inverters_inv_l_send_read_id_72h_Pos_OffsetRef");
		snprintf(v[106], string_size, "inverters_inv_l_send_read_id_73h_CAN_NBT");
		snprintf(v[107], string_size, "inverters_inv_l_send_read_id_74h_Pos_Zero_Capture");
		snprintf(v[108], string_size, "inverters_inv_l_send_read_id_75h_Pos_Ref_Reso_Edge");
		snprintf(v[109], string_size, "inverters_inv_l_send_read_id_76h_Pos_Speed_1");
		snprintf(v[110], string_size, "inverters_inv_l_send_read_id_77h_Pos_Speed_2");
		snprintf(v[111], string_size, "inverters_inv_l_send_read_id_78h_Pos_Ref_Start");
		snprintf(v[112], string_size, "inverters_inv_l_send_read_id_79h_Pos_Tol_Win");
		snprintf(v[113], string_size, "inverters_inv_l_send_read_id_7Ah_Pos_Preset");
		snprintf(v[114], string_size, "inverters_inv_l_send_read_id_7Bh_Pos_Zero_Offset");
		snprintf(v[115], string_size, "inverters_inv_l_send_read_id_7Ch_Pos_ND_Scale");
		snprintf(v[116], string_size, "inverters_inv_l_send_read_id_7Dh_Pos_ND_Offset");
		snprintf(v[117], string_size, "inverters_inv_l_send_read_id_7Eh_Pos_FB2_Scale_Fac_Ext");
		snprintf(v[118], string_size, "inverters_inv_l_send_read_id_7Fh_Pos_Offset_Slack");
		snprintf(v[119], string_size, "inverters_inv_l_send_read_id_80h_Pos_Diff_Slack");
		snprintf(v[120], string_size, "inverters_inv_l_send_read_id_83h_Func_Para_Read");
		snprintf(v[121], string_size, "inverters_inv_l_send_read_id_84h_Func_Para_Write");
		snprintf(v[122], string_size, "inverters_inv_l_send_read_id_85h_Func_Special");
		snprintf(v[123], string_size, "inverters_inv_l_send_read_id_88h_CAN_ID_2_Rx");
		snprintf(v[124], string_size, "inverters_inv_l_send_read_id_89h_CAN_ID_2_Tx");
		snprintf(v[125], string_size, "inverters_inv_l_send_read_id_8Ah_Vout");
		snprintf(v[126], string_size, "inverters_inv_l_send_read_id_8Bh_V_Ref");
		snprintf(v[127], string_size, "inverters_inv_l_send_read_id_8Ch_V_Kp");
		snprintf(v[128], string_size, "inverters_inv_l_send_read_id_8Dh_V_Ti");
		snprintf(v[129], string_size, "inverters_inv_l_send_read_id_8Eh_Clear_Error_List");
		snprintf(v[130], string_size, "inverters_inv_l_send_read_id_8Fh_ErrorWarning_Map");
		snprintf(v[131], string_size, "inverters_inv_l_send_read_id_90h_M_setdig");
		snprintf(v[132], string_size, "inverters_inv_l_send_read_id_91h_Pos_cmd_int");
		snprintf(v[133], string_size, "inverters_inv_l_send_read_id_92h_CAN_Error_BusOff_cntr");
		snprintf(v[134], string_size, "inverters_inv_l_send_read_id_93h_CAN_Error_WriteTime_cntr");
		snprintf(v[135], string_size, "inverters_inv_l_send_read_id_94h_CAN_Error_RxMsgLost_cntr");
		snprintf(v[136], string_size, "inverters_inv_l_send_read_id_95h_CAN_Error_NoAck_cntr");
		snprintf(v[137], string_size, "inverters_inv_l_send_read_id_96h_CAN_Error_CRC_Check_cntr");
		snprintf(v[138], string_size, "inverters_inv_l_send_read_id_97h_CAN_Error_Bit_cntr");
		snprintf(v[139], string_size, "inverters_inv_l_send_read_id_99h_Info_Timer_Diff");
		snprintf(v[140], string_size, "inverters_inv_l_send_read_id_9Ah_Temp_DEBUG");
		snprintf(v[141], string_size, "inverters_inv_l_send_read_id_A0h_Mout");
		snprintf(v[142], string_size, "inverters_inv_l_send_read_id_A1h_Ballast_cntr");
		snprintf(v[143], string_size, "inverters_inv_l_send_read_id_A2h_I_Derating_TM");
		snprintf(v[144], string_size, "inverters_inv_l_send_read_id_A3h_M_Temp");
		snprintf(v[145], string_size, "inverters_inv_l_send_read_id_A4h_Motor_Options");
		snprintf(v[146], string_size, "inverters_inv_l_send_read_id_A5h_DC_Bus_MinMax_Lim");
		snprintf(v[147], string_size, "inverters_inv_l_send_read_id_A6h_FB_IncPerRot");
		snprintf(v[148], string_size, "inverters_inv_l_send_read_id_A7h_FB_Pole");
		snprintf(v[149], string_size, "inverters_inv_l_send_read_id_A8h_N_Actual_Filt");
		snprintf(v[150], string_size, "inverters_inv_l_send_read_id_A9h_I3_ADC");
		snprintf(v[151], string_size, "inverters_inv_l_send_read_id_AAh_I2_ADC");
		snprintf(v[152], string_size, "inverters_inv_l_send_read_id_ABh_Logic_Freq");
		snprintf(v[153], string_size, "inverters_inv_l_send_read_id_ACh_PWM_1_56");
		snprintf(v[154], string_size, "inverters_inv_l_send_read_id_ADh_PWM_2_34");
		snprintf(v[155], string_size, "inverters_inv_l_send_read_id_AEh_PWM_3_12");
		snprintf(v[156], string_size, "inverters_inv_l_send_read_id_AFh_Timer_Delta");
		snprintf(v[157], string_size, "inverters_inv_l_send_read_id_B1h_Motor_Lsq");
		snprintf(v[158], string_size, "inverters_inv_l_send_read_id_B2h_Id_Nom");
		snprintf(v[159], string_size, "inverters_inv_l_send_read_id_B3h_Motor_Lm");
		snprintf(v[160], string_size, "inverters_inv_l_send_read_id_B4h_Motor_Rr");
		snprintf(v[161], string_size, "inverters_inv_l_send_read_id_B5h_Id_Min");
		snprintf(v[162], string_size, "inverters_inv_l_send_read_id_B6h_Motor_Tr");
		snprintf(v[163], string_size, "inverters_inv_l_send_read_id_B8h_Ptr_1_DEBUG");
		snprintf(v[164], string_size, "inverters_inv_l_send_read_id_BAh_Ptr_2_DEBUG");
		snprintf(v[165], string_size, "inverters_inv_l_send_read_id_BBh_Motor_Lsd");
		snprintf(v[166], string_size, "inverters_inv_l_send_read_id_BCh_Motor_Rs");
		snprintf(v[167], string_size, "inverters_inv_l_send_read_id_BDh_Motor_Ts");
		snprintf(v[168], string_size, "inverters_inv_l_send_read_id_BEh_def_END_1");
		snprintf(v[169], string_size, "inverters_inv_l_send_read_id_BFh_def_END_2");
		snprintf(v[170], string_size, "inverters_inv_l_send_read_id_C0h_def_DIN_1");
		snprintf(v[171], string_size, "inverters_inv_l_send_read_id_C1h_def_DIN_2");
		snprintf(v[172], string_size, "inverters_inv_l_send_read_id_C2h_def_OUT_1");
		snprintf(v[173], string_size, "inverters_inv_l_send_read_id_C3h_def_OUT_2");
		snprintf(v[174], string_size, "inverters_inv_l_send_read_id_C4h_I_max_pk");
		snprintf(v[175], string_size, "inverters_inv_l_send_read_id_C5h_I_con_eff");
		snprintf(v[176], string_size, "inverters_inv_l_send_read_id_C6h_I_device");
		snprintf(v[177], string_size, "inverters_inv_l_send_read_id_C7h_RLim_MRcp_Ramp");
		snprintf(v[178], string_size, "inverters_inv_l_send_read_id_C8h_Nmax100perc");
		snprintf(v[179], string_size, "inverters_inv_l_send_read_id_C9h_I_xKp");
		snprintf(v[180], string_size, "inverters_inv_l_send_read_id_CAh_Bat_Opr_Limits");
		snprintf(v[181], string_size, "inverters_inv_l_send_read_id_CBh_I_Kf");
		snprintf(v[182], string_size, "inverters_inv_l_send_read_id_CCh_Car_Mode_Status");
		snprintf(v[183], string_size, "inverters_inv_l_send_read_id_CDh_Car_Mode_Config");
		snprintf(v[184], string_size, "inverters_inv_l_send_read_id_CEh_N_Rpm_MaxInt");
		snprintf(v[185], string_size, "inverters_inv_l_send_read_id_D0h_CAN_Timeout");
		snprintf(v[186], string_size, "inverters_inv_l_send_read_id_D1h_Var_1");
		snprintf(v[187], string_size, "inverters_inv_l_send_read_id_D2h_Var_2");
		snprintf(v[188], string_size, "inverters_inv_l_send_read_id_D3h_Var_3");
		snprintf(v[189], string_size, "inverters_inv_l_send_read_id_D4h_Var_4");
		snprintf(v[190], string_size, "inverters_inv_l_send_read_id_D5h_Ain_in_1");
		snprintf(v[191], string_size, "inverters_inv_l_send_read_id_D6h_Ain_in_2");
		snprintf(v[192], string_size, "inverters_inv_l_send_read_id_D7h_Ain_in_2_OffsScale");
		snprintf(v[193], string_size, "inverters_inv_l_send_read_id_D8h_LogicReadBitsIN_OUT");
		snprintf(v[194], string_size, "inverters_inv_l_send_read_id_D9h_I_200perc");
		snprintf(v[195], string_size, "inverters_inv_l_send_read_id_DAh_def_OUT_3");
		snprintf(v[196], string_size, "inverters_inv_l_send_read_id_DBh_def_OUT_4");
		snprintf(v[197], string_size, "inverters_inv_l_send_read_id_DCh_DAC_Source_ID");
		snprintf(v[198], string_size, "inverters_inv_l_send_read_id_DEh_DS_DOUT_3");
		snprintf(v[199], string_size, "inverters_inv_l_send_read_id_DFh_DS_DOUT_4");
		snprintf(v[200], string_size, "inverters_inv_l_send_read_id_E0h_DS_DOUT_1");
		snprintf(v[201], string_size, "inverters_inv_l_send_read_id_E1h_DS_DOUT_2");
		snprintf(v[202], string_size, "inverters_inv_l_send_read_id_E2h_DS_Rdy_BTB");
		snprintf(v[203], string_size, "inverters_inv_l_send_read_id_E3h_DS_GO");
		snprintf(v[204], string_size, "inverters_inv_l_send_read_id_E4h_DS_END_1");
		snprintf(v[205], string_size, "inverters_inv_l_send_read_id_E5h_DS_END_2");
		snprintf(v[206], string_size, "inverters_inv_l_send_read_id_E6h_DS_DIN_1");
		snprintf(v[207], string_size, "inverters_inv_l_send_read_id_E7h_DS_DIN_2");
		snprintf(v[208], string_size, "inverters_inv_l_send_read_id_E8h_DS_RUN");
		snprintf(v[209], string_size, "inverters_inv_l_send_read_id_E9h_DS_I_Fault");
		snprintf(v[210], string_size, "inverters_inv_l_send_read_id_EBh_Vdc_Bus");
		snprintf(v[211], string_size, "inverters_inv_l_send_read_id_ECh_DS_FB_LossOfSignal");
		snprintf(v[212], string_size, "inverters_inv_l_send_read_id_EDh_Dec_Ramps");
		snprintf(v[213], string_size, "inverters_inv_l_send_read_id_EEh_V_Shunt");
		snprintf(v[214], string_size, "inverters_inv_l_send_read_id_EFh_DS_NoHWFault");
		snprintf(v[215], string_size, "inverters_inv_l_send_read_id_F0h_T_peak");
		snprintf(v[216], string_size, "inverters_inv_l_send_read_id_F1h_Brake_Delay");
		snprintf(v[217], string_size, "inverters_inv_l_send_read_id_F2h_DS_Brake");
		snprintf(v[218], string_size, "inverters_inv_l_send_read_id_F3h_DS_Icns");
		snprintf(v[219], string_size, "inverters_inv_l_send_read_id_F4h_DS_PosTolerance");
		snprintf(v[220], string_size, "inverters_inv_l_send_read_id_F5h_DS_LessN0");
		snprintf(v[221], string_size, "inverters_inv_l_send_read_id_F6h_Inverter_Power");
		snprintf(v[222], string_size, "inverters_inv_l_send_read_id_F7h_Inverter_Work");
		snprintf(v[223], string_size, "inverters_inv_l_send_read_id_F8h_Axis");
		snprintf(v[224], string_size, "inverters_inv_l_send_read_id_FBh_Ain_in_1_Calc");
		snprintf(v[225], string_size, "inverters_inv_l_send_read_id_FCh_Ain_in_2_Calc");
		snprintf(v[226], string_size, "inverters_inv_l_send_read_id_66h_DC_Bus_Voltage");
		snprintf(v[227], string_size, "inverters_inv_l_send_read_id_3Ah_M_cmd_ramp");
		snprintf(v[228], string_size, "inverters_inv_l_send_read_id_FEh_Subv_SVNRev_Nr");

		return 0;
	case 2:
		if(29 > fields_size) return 1;
		snprintf(v[0], string_size, "inverters_inv_l_send_def_din_1__Off_");
		snprintf(v[1], string_size, "inverters_inv_l_send_def_din_1_Ref_and_Limit_Plus");
		snprintf(v[2], string_size, "inverters_inv_l_send_def_din_1_Ref_and_Limit_Minus");
		snprintf(v[3], string_size, "inverters_inv_l_send_def_din_1_Ref_Plus");
		snprintf(v[4], string_size, "inverters_inv_l_send_def_din_1_Limit_Plus");
		snprintf(v[5], string_size, "inverters_inv_l_send_def_din_1_Limit_Minus");
		snprintf(v[6], string_size, "inverters_inv_l_send_def_din_1_Limit_Plus_and_Minus");
		snprintf(v[7], string_size, "inverters_inv_l_send_def_din_1_Cancel_Error_s_");
		snprintf(v[8], string_size, "inverters_inv_l_send_def_din_1__Start_Ref_Drive");
		snprintf(v[9], string_size, "inverters_inv_l_send_def_din_1_Speed_Ramp_0");
		snprintf(v[10], string_size, "inverters_inv_l_send_def_din_1__Start_Dest_eq_Var_1");
		snprintf(v[11], string_size, "inverters_inv_l_send_def_din_1__Start_Dest_eq_Var_2");
		snprintf(v[12], string_size, "inverters_inv_l_send_def_din_1_N_cmd_Reverse");
		snprintf(v[13], string_size, "inverters_inv_l_send_def_din_1__Preset_Pos_eq_Var_3");
		snprintf(v[14], string_size, "inverters_inv_l_send_def_din_1__Capture_Var_3_eq_Pos");
		snprintf(v[15], string_size, "inverters_inv_l_send_def_din_1__Capture_Var_4_eq_Pos");
		snprintf(v[16], string_size, "inverters_inv_l_send_def_din_1__Switch_Spd_eq_notAin1_Ain2");
		snprintf(v[17], string_size, "inverters_inv_l_send_def_din_1__Switch_Spd_eq_notVar1_Var2");
		snprintf(v[18], string_size, "inverters_inv_l_send_def_din_1_I_limit_dig_");
		snprintf(v[19], string_size, "inverters_inv_l_send_def_din_1_N_clip_neg_pos_");
		snprintf(v[20], string_size, "inverters_inv_l_send_def_din_1__Switch_Cmd_eq_notDig_Ana");
		snprintf(v[21], string_size, "inverters_inv_l_send_def_din_1_Speed_Ramp_0_Pos");
		snprintf(v[22], string_size, "inverters_inv_l_send_def_din_1_Handwheel");
		snprintf(v[23], string_size, "inverters_inv_l_send_def_din_1_Brake_Car");
		snprintf(v[24], string_size, "inverters_inv_l_send_def_din_1_Recup_Disabled");
		snprintf(v[25], string_size, "inverters_inv_l_send_def_din_1_Rising_Bank_1_Falling_Bank_0");
		snprintf(v[26], string_size, "inverters_inv_l_send_def_din_1__Start_Dest_eq_Var_1_2_3_4");
		snprintf(v[27], string_size, "inverters_inv_l_send_def_din_1__Start_CW_eq_Var_1_2_3_4");
		snprintf(v[28], string_size, "inverters_inv_l_send_def_din_1_Brake_Car_Nr2");

		return 0;
	case 3:
		if(29 > fields_size) return 1;
		snprintf(v[0], string_size, "inverters_inv_l_send_def_end_1__Off_");
		snprintf(v[1], string_size, "inverters_inv_l_send_def_end_1_Ref_and_Limit_Plus");
		snprintf(v[2], string_size, "inverters_inv_l_send_def_end_1_Ref_and_Limit_Minus");
		snprintf(v[3], string_size, "inverters_inv_l_send_def_end_1_Ref_Plus");
		snprintf(v[4], string_size, "inverters_inv_l_send_def_end_1_Limit_Plus");
		snprintf(v[5], string_size, "inverters_inv_l_send_def_end_1_Limit_Minus");
		snprintf(v[6], string_size, "inverters_inv_l_send_def_end_1_Limit_Plus_and_Minus");
		snprintf(v[7], string_size, "inverters_inv_l_send_def_end_1_Cancel_Error_s_");
		snprintf(v[8], string_size, "inverters_inv_l_send_def_end_1__Start_Ref_Drive");
		snprintf(v[9], string_size, "inverters_inv_l_send_def_end_1_Speed_Ramp_0");
		snprintf(v[10], string_size, "inverters_inv_l_send_def_end_1__Start_Dest_eq_Var_1");
		snprintf(v[11], string_size, "inverters_inv_l_send_def_end_1__Start_Dest_eq_Var_2");
		snprintf(v[12], string_size, "inverters_inv_l_send_def_end_1_N_cmd_Reverse");
		snprintf(v[13], string_size, "inverters_inv_l_send_def_end_1__Preset_Pos_eq_Var_3");
		snprintf(v[14], string_size, "inverters_inv_l_send_def_end_1__Capture_Var_3_eq_Pos");
		snprintf(v[15], string_size, "inverters_inv_l_send_def_end_1__Capture_Var_4_eq_Pos");
		snprintf(v[16], string_size, "inverters_inv_l_send_def_end_1__Switch_Spd_eq_notAin1_Ain2");
		snprintf(v[17], string_size, "inverters_inv_l_send_def_end_1__Switch_Spd_eq_notVar1_Var2");
		snprintf(v[18], string_size, "inverters_inv_l_send_def_end_1_I_limit_dig_");
		snprintf(v[19], string_size, "inverters_inv_l_send_def_end_1_N_clip_neg_pos_");
		snprintf(v[20], string_size, "inverters_inv_l_send_def_end_1__Switch_Cmd_eq_notDig_Ana");
		snprintf(v[21], string_size, "inverters_inv_l_send_def_end_1_Speed_Ramp_0_Pos");
		snprintf(v[22], string_size, "inverters_inv_l_send_def_end_1_Handwheel");
		snprintf(v[23], string_size, "inverters_inv_l_send_def_end_1_Brake_Car");
		snprintf(v[24], string_size, "inverters_inv_l_send_def_end_1_Recup_Disabled");
		snprintf(v[25], string_size, "inverters_inv_l_send_def_end_1_Rising_Bank_1_Falling_Bank_0");
		snprintf(v[26], string_size, "inverters_inv_l_send_def_end_1__Start_Dest_eq_Var_1_2_3_4");
		snprintf(v[27], string_size, "inverters_inv_l_send_def_end_1__Start_CW_eq_Var_1_2_3_4");
		snprintf(v[28], string_size, "inverters_inv_l_send_def_end_1_Brake_Car_Nr2");

		return 0;
	case 4:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "inverters_inv_l_send_ret_interval_Stop");
		snprintf(v[1], string_size, "inverters_inv_l_send_ret_interval_Single");

		return 0;
	case 5:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "inverters_inv_l_send_active192_Low");
		snprintf(v[1], string_size, "inverters_inv_l_send_active192_High");

		return 0;
	case 6:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "inverters_inv_l_send_active190_Low");
		snprintf(v[1], string_size, "inverters_inv_l_send_active190_High");

		return 0;
	case 7:
		if(230 > fields_size) return 1;
		snprintf(v[0], string_size, "inverters_inv_l_rcv_rcv_mux_ID_30_N_Actual");
		snprintf(v[1], string_size, "inverters_inv_l_rcv_rcv_mux_ID_35_Acc_Ramps");
		snprintf(v[2], string_size, "inverters_inv_l_rcv_rcv_mux_ID_ED_Dec_Ramps");
		snprintf(v[3], string_size, "inverters_inv_l_rcv_rcv_mux_ID_C7_RLim_MRcp_Ramp");
		snprintf(v[4], string_size, "inverters_inv_l_rcv_rcv_mux_ID_A8_N_Actual_Filt");
		snprintf(v[5], string_size, "inverters_inv_l_rcv_rcv_mux_ID_1B_FW_Nr");
		snprintf(v[6], string_size, "inverters_inv_l_rcv_rcv_mux_ID_67_Device_Type");
		snprintf(v[7], string_size, "inverters_inv_l_rcv_rcv_mux_ID_62_SerialNumber");
		snprintf(v[8], string_size, "inverters_inv_l_rcv_rcv_mux_ID_F8_Axis_Label");
		snprintf(v[9], string_size, "inverters_inv_l_rcv_rcv_mux_ID_C6_I_device");
		snprintf(v[10], string_size, "inverters_inv_l_rcv_rcv_mux_ID_EE_V_Shunt");
		snprintf(v[11], string_size, "inverters_inv_l_rcv_rcv_mux_ID_D9_I_200perc");
		snprintf(v[12], string_size, "inverters_inv_l_rcv_rcv_mux_ID_5A_Device_Options");
		snprintf(v[13], string_size, "inverters_inv_l_rcv_rcv_mux_ID_40_Status_Map");
		snprintf(v[14], string_size, "inverters_inv_l_rcv_rcv_mux_ID_8F_ErrorWarning_Map");
		snprintf(v[15], string_size, "inverters_inv_l_rcv_rcv_mux_ID_D8_LogicReadBitsIN_OUT");
		snprintf(v[16], string_size, "inverters_inv_l_rcv_rcv_mux_ID_D5_Ain_in_1");
		snprintf(v[17], string_size, "inverters_inv_l_rcv_rcv_mux_ID_D6_Ain_in_2");
		snprintf(v[18], string_size, "inverters_inv_l_rcv_rcv_mux_ID_C8_Nmax100perc");
		snprintf(v[19], string_size, "inverters_inv_l_rcv_rcv_mux_ID_31_N_setdig");
		snprintf(v[20], string_size, "inverters_inv_l_rcv_rcv_mux_ID_5D_N_cmd");
		snprintf(v[21], string_size, "inverters_inv_l_rcv_rcv_mux_ID_32_N_cmd_ramp");
		snprintf(v[22], string_size, "inverters_inv_l_rcv_rcv_mux_ID_34_N_Lim");
		snprintf(v[23], string_size, "inverters_inv_l_rcv_rcv_mux_ID_33_N_Error");
		snprintf(v[24], string_size, "inverters_inv_l_rcv_rcv_mux_ID_90_M_setdig");
		snprintf(v[25], string_size, "inverters_inv_l_rcv_rcv_mux_ID_21_Id_setdig");
		snprintf(v[26], string_size, "inverters_inv_l_rcv_rcv_mux_ID_C4_I_max_pk_perc");
		snprintf(v[27], string_size, "inverters_inv_l_rcv_rcv_mux_ID_C5_I_con_eff_perc");
		snprintf(v[28], string_size, "inverters_inv_l_rcv_rcv_mux_ID_4D_Motor_I_max_eff_Arms");
		snprintf(v[29], string_size, "inverters_inv_l_rcv_rcv_mux_ID_4E_Motor_I_nom_eff_Arms");
		snprintf(v[30], string_size, "inverters_inv_l_rcv_rcv_mux_ID_48_I_Limit_Inuse");
		snprintf(v[31], string_size, "inverters_inv_l_rcv_rcv_mux_ID_26_I_cmd");
		snprintf(v[32], string_size, "inverters_inv_l_rcv_rcv_mux_ID_22_I_cmd_ramp");
		snprintf(v[33], string_size, "inverters_inv_l_rcv_rcv_mux_ID_20_I_Actual");
		snprintf(v[34], string_size, "inverters_inv_l_rcv_rcv_mux_ID_5F_I_Actual_Filt");
		snprintf(v[35], string_size, "inverters_inv_l_rcv_rcv_mux_ID_27_Iq_Actual");
		snprintf(v[36], string_size, "inverters_inv_l_rcv_rcv_mux_ID_28_Id_Actual");
		snprintf(v[37], string_size, "inverters_inv_l_rcv_rcv_mux_ID_38_Iq_Error");
		snprintf(v[38], string_size, "inverters_inv_l_rcv_rcv_mux_ID_39_Id_Error");
		snprintf(v[39], string_size, "inverters_inv_l_rcv_rcv_mux_ID_54_I1_Actual");
		snprintf(v[40], string_size, "inverters_inv_l_rcv_rcv_mux_ID_55_I2_Actual");
		snprintf(v[41], string_size, "inverters_inv_l_rcv_rcv_mux_ID_56_I3_Actual");
		snprintf(v[42], string_size, "inverters_inv_l_rcv_rcv_mux_ID_A9_I3_ADC_Value");
		snprintf(v[43], string_size, "inverters_inv_l_rcv_rcv_mux_ID_AA_I2_ADC_Value");
		snprintf(v[44], string_size, "inverters_inv_l_rcv_rcv_mux_ID_29_Vq_Output");
		snprintf(v[45], string_size, "inverters_inv_l_rcv_rcv_mux_ID_2A_Vd_Output");
		snprintf(v[46], string_size, "inverters_inv_l_rcv_rcv_mux_ID_8A_V_Output");
		snprintf(v[47], string_size, "inverters_inv_l_rcv_rcv_mux_ID_49_T_Motor");
		snprintf(v[48], string_size, "inverters_inv_l_rcv_rcv_mux_ID_4A_T_Igbt");
		snprintf(v[49], string_size, "inverters_inv_l_rcv_rcv_mux_ID_4B_T_Air_Inside");
		snprintf(v[50], string_size, "inverters_inv_l_rcv_rcv_mux_ID_EB_DC_Bus_Voltage_Filt");
		snprintf(v[51], string_size, "inverters_inv_l_rcv_rcv_mux_ID_E4_DigInput_END_1");
		snprintf(v[52], string_size, "inverters_inv_l_rcv_rcv_mux_ID_E6_DigInput_DIN_1");
		snprintf(v[53], string_size, "inverters_inv_l_rcv_rcv_mux_ID_E5_DigInput_END_2");
		snprintf(v[54], string_size, "inverters_inv_l_rcv_rcv_mux_ID_E7_DigInput_DIN_2");
		snprintf(v[55], string_size, "inverters_inv_l_rcv_rcv_mux_ID_E8_DigInput_RUN");
		snprintf(v[56], string_size, "inverters_inv_l_rcv_rcv_mux_ID_E0_DigOutput_DOUT_1");
		snprintf(v[57], string_size, "inverters_inv_l_rcv_rcv_mux_ID_E1_DigOutput_DOUT_2");
		snprintf(v[58], string_size, "inverters_inv_l_rcv_rcv_mux_ID_DE_DigOutput_DOUT_3");
		snprintf(v[59], string_size, "inverters_inv_l_rcv_rcv_mux_ID_E2_DigOutput_Rdy_BTB");
		snprintf(v[60], string_size, "inverters_inv_l_rcv_rcv_mux_ID_E9_Error_I_Fault");
		snprintf(v[61], string_size, "inverters_inv_l_rcv_rcv_mux_ID_DF_DigOutput_DOUT_4");
		snprintf(v[62], string_size, "inverters_inv_l_rcv_rcv_mux_ID_46_I_lim_dig_perc");
		snprintf(v[63], string_size, "inverters_inv_l_rcv_rcv_mux_ID_3C_I_Derating_N_perc");
		snprintf(v[64], string_size, "inverters_inv_l_rcv_rcv_mux_ID_58_I_Derating_TD");
		snprintf(v[65], string_size, "inverters_inv_l_rcv_rcv_mux_ID_4C_I_Derating_TE");
		snprintf(v[66], string_size, "inverters_inv_l_rcv_rcv_mux_ID_A2_I_Derating_TM");
		snprintf(v[67], string_size, "inverters_inv_l_rcv_rcv_mux_ID_36_CommandSource");
		snprintf(v[68], string_size, "inverters_inv_l_rcv_rcv_mux_ID_23_Id_Ref");
		snprintf(v[69], string_size, "inverters_inv_l_rcv_rcv_mux_ID_A0_M_outdig");
		snprintf(v[70], string_size, "inverters_inv_l_rcv_rcv_mux_ID_B8_Ptr_1_DEBUG");
		snprintf(v[71], string_size, "inverters_inv_l_rcv_rcv_mux_ID_BA_Ptr_2_DEBUG");
		snprintf(v[72], string_size, "inverters_inv_l_rcv_rcv_mux_ID_9A_Temp_DEBUG");
		snprintf(v[73], string_size, "inverters_inv_l_rcv_rcv_mux_ID_05_Motor_F_nom");
		snprintf(v[74], string_size, "inverters_inv_l_rcv_rcv_mux_ID_06_Motor_V_nom");
		snprintf(v[75], string_size, "inverters_inv_l_rcv_rcv_mux_ID_07_FU_T_dc");
		snprintf(v[76], string_size, "inverters_inv_l_rcv_rcv_mux_ID_08_FU_V_dc");
		snprintf(v[77], string_size, "inverters_inv_l_rcv_rcv_mux_ID_0A_FU_U_min");
		snprintf(v[78], string_size, "inverters_inv_l_rcv_rcv_mux_ID_0B_FU_F_min");
		snprintf(v[79], string_size, "inverters_inv_l_rcv_rcv_mux_ID_0C_FU_V_corner");
		snprintf(v[80], string_size, "inverters_inv_l_rcv_rcv_mux_ID_0D_FU_F_corner");
		snprintf(v[81], string_size, "inverters_inv_l_rcv_rcv_mux_ID_0E_Motor_Cos_Phi");
		snprintf(v[82], string_size, "inverters_inv_l_rcv_rcv_mux_ID_19_PWM_Enum");
		snprintf(v[83], string_size, "inverters_inv_l_rcv_rcv_mux_ID_1A_Calib_Ref_Value");
		snprintf(v[84], string_size, "inverters_inv_l_rcv_rcv_mux_ID_1C_PID_I_Kp");
		snprintf(v[85], string_size, "inverters_inv_l_rcv_rcv_mux_ID_1D_PID_I_Ti");
		snprintf(v[86], string_size, "inverters_inv_l_rcv_rcv_mux_ID_1E_Cutoffdig");
		snprintf(v[87], string_size, "inverters_inv_l_rcv_rcv_mux_ID_1F_I3_Offset");
		snprintf(v[88], string_size, "inverters_inv_l_rcv_rcv_mux_ID_25_I_Delta_Ramp");
		snprintf(v[89], string_size, "inverters_inv_l_rcv_rcv_mux_ID_2B_PID_I_TiM");
		snprintf(v[90], string_size, "inverters_inv_l_rcv_rcv_mux_ID_2C_PID_n_Kp");
		snprintf(v[91], string_size, "inverters_inv_l_rcv_rcv_mux_ID_8D_VoltageControl_Ti");
		snprintf(v[92], string_size, "inverters_inv_l_rcv_rcv_mux_ID_2E_PID_n_Td");
		snprintf(v[93], string_size, "inverters_inv_l_rcv_rcv_mux_ID_2F_Ain_in_1_OffsScale");
		snprintf(v[94], string_size, "inverters_inv_l_rcv_rcv_mux_ID_D7_Ain_in_2_OffsScale");
		snprintf(v[95], string_size, "inverters_inv_l_rcv_rcv_mux_ID_37_DZR_Sequencer_Value");
		snprintf(v[96], string_size, "inverters_inv_l_rcv_rcv_mux_ID_3B_PID_n_TiM");
		snprintf(v[97], string_size, "inverters_inv_l_rcv_rcv_mux_ID_3F_N_Lim_plus");
		snprintf(v[98], string_size, "inverters_inv_l_rcv_rcv_mux_ID_3E_N_Lim_minus");
		snprintf(v[99], string_size, "inverters_inv_l_rcv_rcv_mux_ID_41_Incr_Delta");
		snprintf(v[100], string_size, "inverters_inv_l_rcv_rcv_mux_ID_42_MotorPosition_Mech");
		snprintf(v[101], string_size, "inverters_inv_l_rcv_rcv_mux_ID_43_MotorPosition_Elec");
		snprintf(v[102], string_size, "inverters_inv_l_rcv_rcv_mux_ID_44_FeedBack_Offset_Angle");
		snprintf(v[103], string_size, "inverters_inv_l_rcv_rcv_mux_ID_45_Ixt_and_RegenE_Monitor");
		snprintf(v[104], string_size, "inverters_inv_l_rcv_rcv_mux_ID_4F_Motor_Pole_Number");
		snprintf(v[105], string_size, "inverters_inv_l_rcv_rcv_mux_ID_50_Ain_in_1_Cutoff");
		snprintf(v[106], string_size, "inverters_inv_l_rcv_rcv_mux_ID_11_Control_Status");
		snprintf(v[107], string_size, "inverters_inv_l_rcv_rcv_mux_ID_51_Kern_Mode_State");
		snprintf(v[108], string_size, "inverters_inv_l_rcv_rcv_mux_ID_52_Status_Mask");
		snprintf(v[109], string_size, "inverters_inv_l_rcv_rcv_mux_ID_53_Ain_in_2_Cutoff");
		snprintf(v[110], string_size, "inverters_inv_l_rcv_rcv_mux_ID_57_I_Limit_Inuse_ramp");
		snprintf(v[111], string_size, "inverters_inv_l_rcv_rcv_mux_ID_59_Motor_Nominal_Speed");
		snprintf(v[112], string_size, "inverters_inv_l_rcv_rcv_mux_ID_5B_SpeedControl_Kacc");
		snprintf(v[113], string_size, "inverters_inv_l_rcv_rcv_mux_ID_5C_Rotor_Signals");
		snprintf(v[114], string_size, "inverters_inv_l_rcv_rcv_mux_ID_5E_Speed_Filter");
		snprintf(v[115], string_size, "inverters_inv_l_rcv_rcv_mux_ID_60_Ain_in_X_Filter");
		snprintf(v[116], string_size, "inverters_inv_l_rcv_rcv_mux_ID_61_Ixt_Monitor");
		snprintf(v[117], string_size, "inverters_inv_l_rcv_rcv_mux_ID_63_ECODE_Status");
		snprintf(v[118], string_size, "inverters_inv_l_rcv_rcv_mux_ID_64_Device_Mains_Supply_V");
		snprintf(v[119], string_size, "inverters_inv_l_rcv_rcv_mux_ID_65_Regen_Resistor_P_and_R");
		snprintf(v[120], string_size, "inverters_inv_l_rcv_rcv_mux_ID_68_CAN_ID_Rx");
		snprintf(v[121], string_size, "inverters_inv_l_rcv_rcv_mux_ID_69_CAN_ID_Tx");
		snprintf(v[122], string_size, "inverters_inv_l_rcv_rcv_mux_ID_6A_Pos_PID_Kp");
		snprintf(v[123], string_size, "inverters_inv_l_rcv_rcv_mux_ID_6B_Pos_PID_Ti");
		snprintf(v[124], string_size, "inverters_inv_l_rcv_rcv_mux_ID_6C_Pos_PID_Td");
		snprintf(v[125], string_size, "inverters_inv_l_rcv_rcv_mux_ID_6D_Pos_Actual");
		snprintf(v[126], string_size, "inverters_inv_l_rcv_rcv_mux_ID_6E_Pos_Destination");
		snprintf(v[127], string_size, "inverters_inv_l_rcv_rcv_mux_ID_6F_Pos_Actual_2");
		snprintf(v[128], string_size, "inverters_inv_l_rcv_rcv_mux_ID_70_Pos_Error");
		snprintf(v[129], string_size, "inverters_inv_l_rcv_rcv_mux_ID_71_Pos_PID_TiM");
		snprintf(v[130], string_size, "inverters_inv_l_rcv_rcv_mux_ID_72_Pos_OffsetReference");
		snprintf(v[131], string_size, "inverters_inv_l_rcv_rcv_mux_ID_73_CAN_NBT");
		snprintf(v[132], string_size, "inverters_inv_l_rcv_rcv_mux_ID_74_Pos_Zero_Capture");
		snprintf(v[133], string_size, "inverters_inv_l_rcv_rcv_mux_ID_75_Pos_Ref_Reso_Edge");
		snprintf(v[134], string_size, "inverters_inv_l_rcv_rcv_mux_ID_76_Pos_Calib_Speed_1");
		snprintf(v[135], string_size, "inverters_inv_l_rcv_rcv_mux_ID_77_Pos_Calib_Speed_2");
		snprintf(v[136], string_size, "inverters_inv_l_rcv_rcv_mux_ID_79_Pos_Tol_Window");
		snprintf(v[137], string_size, "inverters_inv_l_rcv_rcv_mux_ID_7A_Pos_Preset_Value");
		snprintf(v[138], string_size, "inverters_inv_l_rcv_rcv_mux_ID_7B_Pos_Zero_Offset");
		snprintf(v[139], string_size, "inverters_inv_l_rcv_rcv_mux_ID_7C_Pos_NDrive_Scale");
		snprintf(v[140], string_size, "inverters_inv_l_rcv_rcv_mux_ID_7D_Pos_NDrive_Offset");
		snprintf(v[141], string_size, "inverters_inv_l_rcv_rcv_mux_ID_7E_Pos_FB2_Scale_Fac_Ext");
		snprintf(v[142], string_size, "inverters_inv_l_rcv_rcv_mux_ID_7F_Pos_Offset_Slack");
		snprintf(v[143], string_size, "inverters_inv_l_rcv_rcv_mux_ID_80_Pos_Diff_Slack");
		snprintf(v[144], string_size, "inverters_inv_l_rcv_rcv_mux_ID_83_Function_Parameter_Read");
		snprintf(v[145], string_size, "inverters_inv_l_rcv_rcv_mux_ID_84_Function_Parameter_Write");
		snprintf(v[146], string_size, "inverters_inv_l_rcv_rcv_mux_ID_85_Function_Special");
		snprintf(v[147], string_size, "inverters_inv_l_rcv_rcv_mux_ID_88_CAN_ID_2_Rx");
		snprintf(v[148], string_size, "inverters_inv_l_rcv_rcv_mux_ID_89_CAN_ID_2_Tx");
		snprintf(v[149], string_size, "inverters_inv_l_rcv_rcv_mux_ID_8B_VoltageControl_Ref");
		snprintf(v[150], string_size, "inverters_inv_l_rcv_rcv_mux_ID_8C_VoltageControl_Kp");
		snprintf(v[151], string_size, "inverters_inv_l_rcv_rcv_mux_ID_2D_PID_n_Ti");
		snprintf(v[152], string_size, "inverters_inv_l_rcv_rcv_mux_ID_8E_Clear_Error_List");
		snprintf(v[153], string_size, "inverters_inv_l_rcv_rcv_mux_ID_91_Pos_cmd_int");
		snprintf(v[154], string_size, "inverters_inv_l_rcv_rcv_mux_ID_92_CAN_Error_BusOff_cntr");
		snprintf(v[155], string_size, "inverters_inv_l_rcv_rcv_mux_ID_93_CAN_Error_WriteTime_cntr");
		snprintf(v[156], string_size, "inverters_inv_l_rcv_rcv_mux_ID_94_ECODE_1stError");
		snprintf(v[157], string_size, "inverters_inv_l_rcv_rcv_mux_ID_95_CAN_Error_NoAck_cntr");
		snprintf(v[158], string_size, "inverters_inv_l_rcv_rcv_mux_ID_96_CAN_Error_CRC_Check_cntr");
		snprintf(v[159], string_size, "inverters_inv_l_rcv_rcv_mux_ID_97_CAN_Error_Bit_cntr");
		snprintf(v[160], string_size, "inverters_inv_l_rcv_rcv_mux_ID_99_Info_Timer_Diff");
		snprintf(v[161], string_size, "inverters_inv_l_rcv_rcv_mux_ID_A1_Ballast_cntr");
		snprintf(v[162], string_size, "inverters_inv_l_rcv_rcv_mux_ID_A3_Motor_Temp_Error_Lim");
		snprintf(v[163], string_size, "inverters_inv_l_rcv_rcv_mux_ID_A4_Motor_Options");
		snprintf(v[164], string_size, "inverters_inv_l_rcv_rcv_mux_ID_A5_Device_DC_Bus_MinMax_Lim");
		snprintf(v[165], string_size, "inverters_inv_l_rcv_rcv_mux_ID_A6_FB_IncrementsPerRot");
		snprintf(v[166], string_size, "inverters_inv_l_rcv_rcv_mux_ID_A7_FB_Pole_Number");
		snprintf(v[167], string_size, "inverters_inv_l_rcv_rcv_mux_ID_AB_Logic_Frequency");
		snprintf(v[168], string_size, "inverters_inv_l_rcv_rcv_mux_ID_AC_PWM_1_56");
		snprintf(v[169], string_size, "inverters_inv_l_rcv_rcv_mux_ID_AD_PWM_2_34");
		snprintf(v[170], string_size, "inverters_inv_l_rcv_rcv_mux_ID_AE_PWM_3_12");
		snprintf(v[171], string_size, "inverters_inv_l_rcv_rcv_mux_ID_AF_Timer_Delta");
		snprintf(v[172], string_size, "inverters_inv_l_rcv_rcv_mux_ID_B1_Motor_L_Sigma_Q");
		snprintf(v[173], string_size, "inverters_inv_l_rcv_rcv_mux_ID_BB_Motor_L_Sigma_D");
		snprintf(v[174], string_size, "inverters_inv_l_rcv_rcv_mux_ID_B2_Id_Nominal");
		snprintf(v[175], string_size, "inverters_inv_l_rcv_rcv_mux_ID_B3_Motor_Magn_Inductance");
		snprintf(v[176], string_size, "inverters_inv_l_rcv_rcv_mux_ID_B4_Motor_Rotor_Resistance");
		snprintf(v[177], string_size, "inverters_inv_l_rcv_rcv_mux_ID_B5_Id_Minimum");
		snprintf(v[178], string_size, "inverters_inv_l_rcv_rcv_mux_ID_B6_Time_Constant_Rotor");
		snprintf(v[179], string_size, "inverters_inv_l_rcv_rcv_mux_ID_BC_Motor_Stator_Resistance");
		snprintf(v[180], string_size, "inverters_inv_l_rcv_rcv_mux_ID_BD_Time_Constant_Stator");
		snprintf(v[181], string_size, "inverters_inv_l_rcv_rcv_mux_ID_BE_LogicDefine_of_END_1");
		snprintf(v[182], string_size, "inverters_inv_l_rcv_rcv_mux_ID_BF_LogicDefine_of_END_2");
		snprintf(v[183], string_size, "inverters_inv_l_rcv_rcv_mux_ID_C0_LogicDefine_of_DIN_1");
		snprintf(v[184], string_size, "inverters_inv_l_rcv_rcv_mux_ID_C1_LogicDefine_of_DIN_2");
		snprintf(v[185], string_size, "inverters_inv_l_rcv_rcv_mux_ID_C2_LogicDefine_of_OUT_1");
		snprintf(v[186], string_size, "inverters_inv_l_rcv_rcv_mux_ID_24_I_Max_Inuse");
		snprintf(v[187], string_size, "inverters_inv_l_rcv_rcv_mux_ID_E3_DigSignal_GO");
		snprintf(v[188], string_size, "inverters_inv_l_rcv_rcv_mux_ID_F2_DigSignal_Brake");
		snprintf(v[189], string_size, "inverters_inv_l_rcv_rcv_mux_ID_F3_DigSignal_Icns");
		snprintf(v[190], string_size, "inverters_inv_l_rcv_rcv_mux_ID_F5_DigSignal_LessN0");
		snprintf(v[191], string_size, "inverters_inv_l_rcv_rcv_mux_ID_F4_DigSignal_Pos_Tolerance");
		snprintf(v[192], string_size, "inverters_inv_l_rcv_rcv_mux_ID_FB_Ain_in_1_Calc");
		snprintf(v[193], string_size, "inverters_inv_l_rcv_rcv_mux_ID_FC_Ain_in_2_Calc");
		snprintf(v[194], string_size, "inverters_inv_l_rcv_rcv_mux_ID_C3_LogicDefine_of_OUT_2");
		snprintf(v[195], string_size, "inverters_inv_l_rcv_rcv_mux_ID_DA_LogicDefine_of_OUT_3");
		snprintf(v[196], string_size, "inverters_inv_l_rcv_rcv_mux_ID_DB_LogicDefine_of_OUT_4");
		snprintf(v[197], string_size, "inverters_inv_l_rcv_rcv_mux_ID_C9_PID_I_xKp");
		snprintf(v[198], string_size, "inverters_inv_l_rcv_rcv_mux_ID_CA_Bat_Opr_Limits");
		snprintf(v[199], string_size, "inverters_inv_l_rcv_rcv_mux_ID_CB_PID_I_Kf");
		snprintf(v[200], string_size, "inverters_inv_l_rcv_rcv_mux_ID_CC_Car_Mode_Status");
		snprintf(v[201], string_size, "inverters_inv_l_rcv_rcv_mux_ID_CD_Car_Mode_Config");
		snprintf(v[202], string_size, "inverters_inv_l_rcv_rcv_mux_ID_CE_N_Rpm_MaxInt");
		snprintf(v[203], string_size, "inverters_inv_l_rcv_rcv_mux_ID_D1_Var_1");
		snprintf(v[204], string_size, "inverters_inv_l_rcv_rcv_mux_ID_D0_CAN_Timeout");
		snprintf(v[205], string_size, "inverters_inv_l_rcv_rcv_mux_ID_D2_Var_2");
		snprintf(v[206], string_size, "inverters_inv_l_rcv_rcv_mux_ID_D3_Var_3");
		snprintf(v[207], string_size, "inverters_inv_l_rcv_rcv_mux_ID_D4_Var_4");
		snprintf(v[208], string_size, "inverters_inv_l_rcv_rcv_mux_ID_DC_DAC_Source_ID");
		snprintf(v[209], string_size, "inverters_inv_l_rcv_rcv_mux_ID_EC_DigSignal_FB_LossOfSig");
		snprintf(v[210], string_size, "inverters_inv_l_rcv_rcv_mux_ID_EF_DigSignal_NoHWFault");
		snprintf(v[211], string_size, "inverters_inv_l_rcv_rcv_mux_ID_F0_Time_I_Peak");
		snprintf(v[212], string_size, "inverters_inv_l_rcv_rcv_mux_ID_F1_Brake_Delay");
		snprintf(v[213], string_size, "inverters_inv_l_rcv_rcv_mux_ID_F6_Inverter_Output_Power");
		snprintf(v[214], string_size, "inverters_inv_l_rcv_rcv_mux_ID_F7_Inverter_Output_Work");
		snprintf(v[215], string_size, "inverters_inv_l_rcv_rcv_mux_ID_0F_FU_Extra");
		snprintf(v[216], string_size, "inverters_inv_l_rcv_rcv_mux_ID_10_Oszi_Channel");
		snprintf(v[217], string_size, "inverters_inv_l_rcv_rcv_mux_ID_12_Oszi_Triger_Level");
		snprintf(v[218], string_size, "inverters_inv_l_rcv_rcv_mux_ID_13_Oszi_Triger_Edge");
		snprintf(v[219], string_size, "inverters_inv_l_rcv_rcv_mux_ID_14_Oszi_Triger_Source");
		snprintf(v[220], string_size, "inverters_inv_l_rcv_rcv_mux_ID_15_Oszi_Source");
		snprintf(v[221], string_size, "inverters_inv_l_rcv_rcv_mux_ID_16_Oszi_Skip");
		snprintf(v[222], string_size, "inverters_inv_l_rcv_rcv_mux_ID_18_Oszi_Run_cmd");
		snprintf(v[223], string_size, "inverters_inv_l_rcv_rcv_mux_ID_17_Oszi_Read_cmd");
		snprintf(v[224], string_size, "inverters_inv_l_rcv_rcv_mux_ID_78_Pos_Ref_Start");
		snprintf(v[225], string_size, "inverters_inv_l_rcv_rcv_mux_ID_66_DC_Bus_Voltage");
		snprintf(v[226], string_size, "inverters_inv_l_rcv_rcv_mux_ID_3A_M_cmd_ramp");
		snprintf(v[227], string_size, "inverters_inv_l_rcv_rcv_mux_ID_97_LogicOutBlock");
		snprintf(v[228], string_size, "inverters_inv_l_rcv_rcv_mux_ID_9B_LogicInBlock");
		snprintf(v[229], string_size, "inverters_inv_l_rcv_rcv_mux_ID_FE_FW_Subv_Revis_Nr");

		return 0;
	case 8:
		if(29 > fields_size) return 1;
		snprintf(v[0], string_size, "inverters_inv_l_rcv_def_end_1__Off_");
		snprintf(v[1], string_size, "inverters_inv_l_rcv_def_end_1_Ref_and_Limit_Plus");
		snprintf(v[2], string_size, "inverters_inv_l_rcv_def_end_1_Ref_and_Limit_Minus");
		snprintf(v[3], string_size, "inverters_inv_l_rcv_def_end_1_Ref_Plus");
		snprintf(v[4], string_size, "inverters_inv_l_rcv_def_end_1_Limit_Plus");
		snprintf(v[5], string_size, "inverters_inv_l_rcv_def_end_1_Limit_Minus");
		snprintf(v[6], string_size, "inverters_inv_l_rcv_def_end_1_Limit_Plus_and_Minus");
		snprintf(v[7], string_size, "inverters_inv_l_rcv_def_end_1_Cancel_Error_s_");
		snprintf(v[8], string_size, "inverters_inv_l_rcv_def_end_1__Start_Ref_Drive");
		snprintf(v[9], string_size, "inverters_inv_l_rcv_def_end_1_Speed_Ramp_0");
		snprintf(v[10], string_size, "inverters_inv_l_rcv_def_end_1__Start_Dest_eq_Var_1");
		snprintf(v[11], string_size, "inverters_inv_l_rcv_def_end_1__Start_Dest_eq_Var_2");
		snprintf(v[12], string_size, "inverters_inv_l_rcv_def_end_1_N_cmd_Reverse");
		snprintf(v[13], string_size, "inverters_inv_l_rcv_def_end_1__Preset_Pos_eq_Var_3");
		snprintf(v[14], string_size, "inverters_inv_l_rcv_def_end_1__Capture_Var_3_eq_Pos");
		snprintf(v[15], string_size, "inverters_inv_l_rcv_def_end_1__Capture_Var_4_eq_Pos");
		snprintf(v[16], string_size, "inverters_inv_l_rcv_def_end_1__Switch_Spd_eq_notAin1_Ain2");
		snprintf(v[17], string_size, "inverters_inv_l_rcv_def_end_1__Switch_Spd_eq_notVar1_Var2");
		snprintf(v[18], string_size, "inverters_inv_l_rcv_def_end_1_I_limit_dig_");
		snprintf(v[19], string_size, "inverters_inv_l_rcv_def_end_1_N_clip_neg_pos_");
		snprintf(v[20], string_size, "inverters_inv_l_rcv_def_end_1__Switch_Cmd_eq_notDig_Ana");
		snprintf(v[21], string_size, "inverters_inv_l_rcv_def_end_1_Speed_Ramp_0_Pos");
		snprintf(v[22], string_size, "inverters_inv_l_rcv_def_end_1_Handwheel");
		snprintf(v[23], string_size, "inverters_inv_l_rcv_def_end_1_Brake_Car");
		snprintf(v[24], string_size, "inverters_inv_l_rcv_def_end_1_Recup_Disabled");
		snprintf(v[25], string_size, "inverters_inv_l_rcv_def_end_1_Rising_Bank_1_Falling_Bank_0");
		snprintf(v[26], string_size, "inverters_inv_l_rcv_def_end_1__Start_Dest_eq_Var_1_2_3_4");
		snprintf(v[27], string_size, "inverters_inv_l_rcv_def_end_1__Start_CW_eq_Var_1_2_3_4");
		snprintf(v[28], string_size, "inverters_inv_l_rcv_def_end_1_Brake_Car_Nr2");

		return 0;
	case 9:
		if(29 > fields_size) return 1;
		snprintf(v[0], string_size, "inverters_inv_l_rcv_def_din_1__Off_");
		snprintf(v[1], string_size, "inverters_inv_l_rcv_def_din_1_Ref_and_Limit_Plus");
		snprintf(v[2], string_size, "inverters_inv_l_rcv_def_din_1_Ref_and_Limit_Minus");
		snprintf(v[3], string_size, "inverters_inv_l_rcv_def_din_1_Ref_Plus");
		snprintf(v[4], string_size, "inverters_inv_l_rcv_def_din_1_Limit_Plus");
		snprintf(v[5], string_size, "inverters_inv_l_rcv_def_din_1_Limit_Minus");
		snprintf(v[6], string_size, "inverters_inv_l_rcv_def_din_1_Limit_Plus_and_Minus");
		snprintf(v[7], string_size, "inverters_inv_l_rcv_def_din_1_Cancel_Error_s_");
		snprintf(v[8], string_size, "inverters_inv_l_rcv_def_din_1__Start_Ref_Drive");
		snprintf(v[9], string_size, "inverters_inv_l_rcv_def_din_1_Speed_Ramp_0");
		snprintf(v[10], string_size, "inverters_inv_l_rcv_def_din_1__Start_Dest_eq_Var_1");
		snprintf(v[11], string_size, "inverters_inv_l_rcv_def_din_1__Start_Dest_eq_Var_2");
		snprintf(v[12], string_size, "inverters_inv_l_rcv_def_din_1_N_cmd_Reverse");
		snprintf(v[13], string_size, "inverters_inv_l_rcv_def_din_1__Preset_Pos_eq_Var_3");
		snprintf(v[14], string_size, "inverters_inv_l_rcv_def_din_1__Capture_Var_3_eq_Pos");
		snprintf(v[15], string_size, "inverters_inv_l_rcv_def_din_1__Capture_Var_4_eq_Pos");
		snprintf(v[16], string_size, "inverters_inv_l_rcv_def_din_1__Switch_Spd_eq_notAin1_Ain2");
		snprintf(v[17], string_size, "inverters_inv_l_rcv_def_din_1__Switch_Spd_eq_notVar1_Var2");
		snprintf(v[18], string_size, "inverters_inv_l_rcv_def_din_1_I_limit_dig_");
		snprintf(v[19], string_size, "inverters_inv_l_rcv_def_din_1_N_clip_neg_pos_");
		snprintf(v[20], string_size, "inverters_inv_l_rcv_def_din_1__Switch_Cmd_eq_notDig_Ana");
		snprintf(v[21], string_size, "inverters_inv_l_rcv_def_din_1_Speed_Ramp_0_Pos");
		snprintf(v[22], string_size, "inverters_inv_l_rcv_def_din_1_Handwheel");
		snprintf(v[23], string_size, "inverters_inv_l_rcv_def_din_1_Brake_Car");
		snprintf(v[24], string_size, "inverters_inv_l_rcv_def_din_1_Recup_Disabled");
		snprintf(v[25], string_size, "inverters_inv_l_rcv_def_din_1_Rising_Bank_1_Falling_Bank_0");
		snprintf(v[26], string_size, "inverters_inv_l_rcv_def_din_1__Start_Dest_eq_Var_1_2_3_4");
		snprintf(v[27], string_size, "inverters_inv_l_rcv_def_din_1__Start_CW_eq_Var_1_2_3_4");
		snprintf(v[28], string_size, "inverters_inv_l_rcv_def_din_1_Brake_Car_Nr2");

		return 0;
	case 10:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "inverters_inv_l_rcv_active190_Low");
		snprintf(v[1], string_size, "inverters_inv_l_rcv_active190_High");

		return 0;
	case 11:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "inverters_inv_l_rcv_active192_Low");
		snprintf(v[1], string_size, "inverters_inv_l_rcv_active192_High");

		return 0;
	case 12:
		if(131 > fields_size) return 1;
		snprintf(v[0], string_size, "inverters_inv_r_send_send_mux_ID_04_USER_Key");
		snprintf(v[1], string_size, "inverters_inv_r_send_send_mux_ID_05_Motor_F_nom");
		snprintf(v[2], string_size, "inverters_inv_r_send_send_mux_ID_07_FU_T_dc");
		snprintf(v[3], string_size, "inverters_inv_r_send_send_mux_ID_08_FU_V_dc");
		snprintf(v[4], string_size, "inverters_inv_r_send_send_mux_ID_09_FU_Special");
		snprintf(v[5], string_size, "inverters_inv_r_send_send_mux_ID_0A_FU_U_min");
		snprintf(v[6], string_size, "inverters_inv_r_send_send_mux_ID_0B_FU_F_min");
		snprintf(v[7], string_size, "inverters_inv_r_send_send_mux_ID_0C_FU_V_corner");
		snprintf(v[8], string_size, "inverters_inv_r_send_send_mux_ID_0D_FU_F_corner");
		snprintf(v[9], string_size, "inverters_inv_r_send_send_mux_ID_0E_Motor_Cos_Phi");
		snprintf(v[10], string_size, "inverters_inv_r_send_send_mux_ID_0F_FU_Extra");
		snprintf(v[11], string_size, "inverters_inv_r_send_send_mux_ID_10_Oszi_Channel");
		snprintf(v[12], string_size, "inverters_inv_r_send_send_mux_ID_12_Oszi_Triger_Level");
		snprintf(v[13], string_size, "inverters_inv_r_send_send_mux_ID_13_Oszi_Triger_Edge");
		snprintf(v[14], string_size, "inverters_inv_r_send_send_mux_ID_14_Oszi_Triger_Source");
		snprintf(v[15], string_size, "inverters_inv_r_send_send_mux_ID_15_Oszi_Source");
		snprintf(v[16], string_size, "inverters_inv_r_send_send_mux_ID_16_Oszi_Skip");
		snprintf(v[17], string_size, "inverters_inv_r_send_send_mux_ID_17_Oszi_Read_cmd");
		snprintf(v[18], string_size, "inverters_inv_r_send_send_mux_ID_18_Oszi_Run_cmd");
		snprintf(v[19], string_size, "inverters_inv_r_send_send_mux_ID_1A_Calib_Ref_Value");
		snprintf(v[20], string_size, "inverters_inv_r_send_send_mux_ID_1C_PID_I_Kp");
		snprintf(v[21], string_size, "inverters_inv_r_send_send_mux_ID_1D_PID_I_Ti");
		snprintf(v[22], string_size, "inverters_inv_r_send_send_mux_ID_1E_Cutoffdig");
		snprintf(v[23], string_size, "inverters_inv_r_send_send_mux_ID_21_Id_setdig");
		snprintf(v[24], string_size, "inverters_inv_r_send_send_mux_ID_25_I_Delta_Ramp");
		snprintf(v[25], string_size, "inverters_inv_r_send_send_mux_ID_2B_PID_I_TiM");
		snprintf(v[26], string_size, "inverters_inv_r_send_send_mux_ID_2C_PID_n_Kp");
		snprintf(v[27], string_size, "inverters_inv_r_send_send_mux_ID_2D_PID_n_Ti");
		snprintf(v[28], string_size, "inverters_inv_r_send_send_mux_ID_2E_PID_n_Td");
		snprintf(v[29], string_size, "inverters_inv_r_send_send_mux_ID_2F_Ain_in_1_OffsScale");
		snprintf(v[30], string_size, "inverters_inv_r_send_send_mux_ID_31_N_setdig");
		snprintf(v[31], string_size, "inverters_inv_r_send_send_mux_ID_34_N_Lim");
		snprintf(v[32], string_size, "inverters_inv_r_send_send_mux_ID_35_Acc_Ramps");
		snprintf(v[33], string_size, "inverters_inv_r_send_send_mux_ID_36_CommandSource");
		snprintf(v[34], string_size, "inverters_inv_r_send_send_mux_ID_3B_PID_n_TiM");
		snprintf(v[35], string_size, "inverters_inv_r_send_send_mux_ID_3C_I_Derating_N_perc");
		snprintf(v[36], string_size, "inverters_inv_r_send_send_mux_ID_3E_N_Lim_minus");
		snprintf(v[37], string_size, "inverters_inv_r_send_send_mux_ID_3F_N_Lim_plus");
		snprintf(v[38], string_size, "inverters_inv_r_send_send_mux_ID_44_FeedBack_Offset_Angle");
		snprintf(v[39], string_size, "inverters_inv_r_send_send_mux_ID_3D_Read_Cmd");
		snprintf(v[40], string_size, "inverters_inv_r_send_send_mux_ID_46_I_lim_dig_perc");
		snprintf(v[41], string_size, "inverters_inv_r_send_send_mux_ID_4C_I_Derating_TE");
		snprintf(v[42], string_size, "inverters_inv_r_send_send_mux_ID_4D_Motor_I_max_eff_Arms");
		snprintf(v[43], string_size, "inverters_inv_r_send_send_mux_ID_4E_Motor_I_nom_eff_Arms");
		snprintf(v[44], string_size, "inverters_inv_r_send_send_mux_ID_4F_Motor_Pole_Number");
		snprintf(v[45], string_size, "inverters_inv_r_send_send_mux_ID_50_Ain_in_1_Cutoff");
		snprintf(v[46], string_size, "inverters_inv_r_send_send_mux_ID_51_Kern_Mode_State");
		snprintf(v[47], string_size, "inverters_inv_r_send_send_mux_ID_53_Ain_in_2_Cutoff");
		snprintf(v[48], string_size, "inverters_inv_r_send_send_mux_ID_58_I_Derating_TD");
		snprintf(v[49], string_size, "inverters_inv_r_send_send_mux_ID_59_Motor_Nominal_Speed");
		snprintf(v[50], string_size, "inverters_inv_r_send_send_mux_ID_5A_Device_Options");
		snprintf(v[51], string_size, "inverters_inv_r_send_send_mux_ID_5B_PID_n_Kacc");
		snprintf(v[52], string_size, "inverters_inv_r_send_send_mux_ID_5E_Speed_Filter");
		snprintf(v[53], string_size, "inverters_inv_r_send_send_mux_ID_60_Ain_in_X_Filter");
		snprintf(v[54], string_size, "inverters_inv_r_send_send_mux_ID_62_SerialNumber");
		snprintf(v[55], string_size, "inverters_inv_r_send_send_mux_ID_64_Device_Mains_Supply_V");
		snprintf(v[56], string_size, "inverters_inv_r_send_send_mux_ID_65_Regen_Resistor_P_and_R");
		snprintf(v[57], string_size, "inverters_inv_r_send_send_mux_ID_67_Device_Type");
		snprintf(v[58], string_size, "inverters_inv_r_send_send_mux_ID_68_CAN_ID_Rx");
		snprintf(v[59], string_size, "inverters_inv_r_send_send_mux_ID_69_CAN_ID_Tx");
		snprintf(v[60], string_size, "inverters_inv_r_send_send_mux_ID_6A_Pos_PID_Kp");
		snprintf(v[61], string_size, "inverters_inv_r_send_send_mux_ID_6B_Pos_PID_Ti");
		snprintf(v[62], string_size, "inverters_inv_r_send_send_mux_ID_6C_Pos_PID_Td");
		snprintf(v[63], string_size, "inverters_inv_r_send_send_mux_ID_6E_Pos_Destination");
		snprintf(v[64], string_size, "inverters_inv_r_send_send_mux_ID_71_Pos_PID_TiM");
		snprintf(v[65], string_size, "inverters_inv_r_send_send_mux_ID_72_Pos_OffsetReference");
		snprintf(v[66], string_size, "inverters_inv_r_send_send_mux_ID_73_CAN_NBT");
		snprintf(v[67], string_size, "inverters_inv_r_send_send_mux_ID_75_Pos_Ref_Reso_Edge");
		snprintf(v[68], string_size, "inverters_inv_r_send_send_mux_ID_76_Pos_Calib_Speed_1");
		snprintf(v[69], string_size, "inverters_inv_r_send_send_mux_ID_77_Pos_Calib_Speed_2");
		snprintf(v[70], string_size, "inverters_inv_r_send_send_mux_ID_79_Pos_Tol_Window");
		snprintf(v[71], string_size, "inverters_inv_r_send_send_mux_ID_7A_Pos_Preset_Value");
		snprintf(v[72], string_size, "inverters_inv_r_send_send_mux_ID_7C_Pos_NDrive_Scale");
		snprintf(v[73], string_size, "inverters_inv_r_send_send_mux_ID_7D_Pos_NDrive_Offset");
		snprintf(v[74], string_size, "inverters_inv_r_send_send_mux_ID_7E_Pos_FB2_Scale_Fac_Ext");
		snprintf(v[75], string_size, "inverters_inv_r_send_send_mux_ID_7F_Pos_Offset_Slack");
		snprintf(v[76], string_size, "inverters_inv_r_send_send_mux_ID_80_Pos_Diff_Slack");
		snprintf(v[77], string_size, "inverters_inv_r_send_send_mux_ID_83_Function_Parameter_Read");
		snprintf(v[78], string_size, "inverters_inv_r_send_send_mux_ID_84_Function_Parameter_Write");
		snprintf(v[79], string_size, "inverters_inv_r_send_send_mux_ID_85_Function_Special");
		snprintf(v[80], string_size, "inverters_inv_r_send_send_mux_ID_88_CAN_ID_2_Rx");
		snprintf(v[81], string_size, "inverters_inv_r_send_send_mux_ID_89_CAN_ID_2_Tx");
		snprintf(v[82], string_size, "inverters_inv_r_send_send_mux_ID_8B_VoltageControl_Ref");
		snprintf(v[83], string_size, "inverters_inv_r_send_send_mux_ID_8C_VoltageControl_Kp");
		snprintf(v[84], string_size, "inverters_inv_r_send_send_mux_ID_8D_VoltageControl_Ti");
		snprintf(v[85], string_size, "inverters_inv_r_send_send_mux_ID_8E_Clear_Error_List");
		snprintf(v[86], string_size, "inverters_inv_r_send_send_mux_ID_90_M_setdig");
		snprintf(v[87], string_size, "inverters_inv_r_send_send_mux_ID_A2_I_Derating_TM");
		snprintf(v[88], string_size, "inverters_inv_r_send_send_mux_ID_A3_Motor_Temp_Error_Lim");
		snprintf(v[89], string_size, "inverters_inv_r_send_send_mux_ID_A4_Motor_Options");
		snprintf(v[90], string_size, "inverters_inv_r_send_send_mux_ID_A5_Device_DC_Bus_MinMax_Lim");
		snprintf(v[91], string_size, "inverters_inv_r_send_send_mux_ID_A6_FB_IncrementsPerRot");
		snprintf(v[92], string_size, "inverters_inv_r_send_send_mux_ID_A7_FB_Pole_Number");
		snprintf(v[93], string_size, "inverters_inv_r_send_send_mux_ID_B1_Motor_L_Sigma_Q");
		snprintf(v[94], string_size, "inverters_inv_r_send_send_mux_ID_B2_Id_Nominal");
		snprintf(v[95], string_size, "inverters_inv_r_send_send_mux_ID_B3_Motor_Magn_Inductance");
		snprintf(v[96], string_size, "inverters_inv_r_send_send_mux_ID_B4_Motor_Rotor_Resistance");
		snprintf(v[97], string_size, "inverters_inv_r_send_send_mux_ID_B5_Id_Minimum");
		snprintf(v[98], string_size, "inverters_inv_r_send_send_mux_ID_B6_Time_Constant_Rotor");
		snprintf(v[99], string_size, "inverters_inv_r_send_send_mux_ID_BB_Motor_L_Sigma_D");
		snprintf(v[100], string_size, "inverters_inv_r_send_send_mux_ID_BC_Motor_Stator_Resistance");
		snprintf(v[101], string_size, "inverters_inv_r_send_send_mux_ID_BD_Time_Constant_Stator");
		snprintf(v[102], string_size, "inverters_inv_r_send_send_mux_ID_BE_LogicDefine_of_END_1");
		snprintf(v[103], string_size, "inverters_inv_r_send_send_mux_ID_BF_LogicDefine_of_END_2");
		snprintf(v[104], string_size, "inverters_inv_r_send_send_mux_ID_C0_LogicDefine_of_DIN_1");
		snprintf(v[105], string_size, "inverters_inv_r_send_send_mux_ID_C1_LogicDefine_of_DIN_2");
		snprintf(v[106], string_size, "inverters_inv_r_send_send_mux_ID_C2_LogicDefine_of_OUT_1");
		snprintf(v[107], string_size, "inverters_inv_r_send_send_mux_ID_C3_LogicDefine_of_OUT_2");
		snprintf(v[108], string_size, "inverters_inv_r_send_send_mux_ID_DA_LogicDefine_of_OUT_3");
		snprintf(v[109], string_size, "inverters_inv_r_send_send_mux_ID_DB_LogicDefine_of_OUT_4");
		snprintf(v[110], string_size, "inverters_inv_r_send_send_mux_ID_C4_I_max_pk_perc");
		snprintf(v[111], string_size, "inverters_inv_r_send_send_mux_ID_C5_I_con_eff_perc");
		snprintf(v[112], string_size, "inverters_inv_r_send_send_mux_ID_C6_I_device");
		snprintf(v[113], string_size, "inverters_inv_r_send_send_mux_ID_C7_RLim_MRcp_Ramp");
		snprintf(v[114], string_size, "inverters_inv_r_send_send_mux_ID_C8_Nmax100perc");
		snprintf(v[115], string_size, "inverters_inv_r_send_send_mux_ID_C9_CurrentControl_xKp");
		snprintf(v[116], string_size, "inverters_inv_r_send_send_mux_ID_CA_Bat_Opr_Limits");
		snprintf(v[117], string_size, "inverters_inv_r_send_send_mux_ID_CB_PID_I_Kf");
		snprintf(v[118], string_size, "inverters_inv_r_send_send_mux_ID_CD_Car_Mode_Config");
		snprintf(v[119], string_size, "inverters_inv_r_send_send_mux_ID_D0_CAN_Timeout");
		snprintf(v[120], string_size, "inverters_inv_r_send_send_mux_ID_D1_Var_1");
		snprintf(v[121], string_size, "inverters_inv_r_send_send_mux_ID_D2_Var_2");
		snprintf(v[122], string_size, "inverters_inv_r_send_send_mux_ID_D3_Var_3");
		snprintf(v[123], string_size, "inverters_inv_r_send_send_mux_ID_D4_Var_4");
		snprintf(v[124], string_size, "inverters_inv_r_send_send_mux_ID_D7_Ain_in_2_OffsScale");
		snprintf(v[125], string_size, "inverters_inv_r_send_send_mux_ID_DC_DAC_Source_ID");
		snprintf(v[126], string_size, "inverters_inv_r_send_send_mux_ID_ED_Dec_Ramps");
		snprintf(v[127], string_size, "inverters_inv_r_send_send_mux_ID_EE_V_Shunt");
		snprintf(v[128], string_size, "inverters_inv_r_send_send_mux_ID_F0_Time_I_Peak");
		snprintf(v[129], string_size, "inverters_inv_r_send_send_mux_ID_F1_Brake_Delay");
		snprintf(v[130], string_size, "inverters_inv_r_send_send_mux_ID_F8_Axis_Label");

		return 0;
	case 13:
		if(229 > fields_size) return 1;
		snprintf(v[0], string_size, "inverters_inv_r_send_read_id_05h_Motor_F_nom");
		snprintf(v[1], string_size, "inverters_inv_r_send_read_id_06h_Motor_V_nom");
		snprintf(v[2], string_size, "inverters_inv_r_send_read_id_07h_FU_T_dc");
		snprintf(v[3], string_size, "inverters_inv_r_send_read_id_08h_FU_V_dc");
		snprintf(v[4], string_size, "inverters_inv_r_send_read_id_09h_FU_Special");
		snprintf(v[5], string_size, "inverters_inv_r_send_read_id_0Ah_FU_U_min");
		snprintf(v[6], string_size, "inverters_inv_r_send_read_id_0Bh_FU_F_min");
		snprintf(v[7], string_size, "inverters_inv_r_send_read_id_0Ch_FU_V_corner");
		snprintf(v[8], string_size, "inverters_inv_r_send_read_id_0Dh_FU_F_corner");
		snprintf(v[9], string_size, "inverters_inv_r_send_read_id_0Eh_Motor_Cos_Phi");
		snprintf(v[10], string_size, "inverters_inv_r_send_read_id_0Fh_FU_Extra");
		snprintf(v[11], string_size, "inverters_inv_r_send_read_id_10h_Oszi_Channel");
		snprintf(v[12], string_size, "inverters_inv_r_send_read_id_11h_Control_Status");
		snprintf(v[13], string_size, "inverters_inv_r_send_read_id_12h_Oszi_Triger_Level");
		snprintf(v[14], string_size, "inverters_inv_r_send_read_id_13h_Oszi_Triger_Edge");
		snprintf(v[15], string_size, "inverters_inv_r_send_read_id_14h_Oszi_Triger_Source");
		snprintf(v[16], string_size, "inverters_inv_r_send_read_id_15h_Oszi_Source");
		snprintf(v[17], string_size, "inverters_inv_r_send_read_id_16h_Oszi_Skip");
		snprintf(v[18], string_size, "inverters_inv_r_send_read_id_17h_Oszi_Read_cmd");
		snprintf(v[19], string_size, "inverters_inv_r_send_read_id_18h_Oszi_Run_cmd");
		snprintf(v[20], string_size, "inverters_inv_r_send_read_id_19h_PWM_Enum");
		snprintf(v[21], string_size, "inverters_inv_r_send_read_id_1Ah_Calib_Ref_Value");
		snprintf(v[22], string_size, "inverters_inv_r_send_read_id_1Bh_FW_Nr");
		snprintf(v[23], string_size, "inverters_inv_r_send_read_id_1Ch_I_Kp");
		snprintf(v[24], string_size, "inverters_inv_r_send_read_id_1Dh_I_Ti");
		snprintf(v[25], string_size, "inverters_inv_r_send_read_id_1Eh_Cutoffdig");
		snprintf(v[26], string_size, "inverters_inv_r_send_read_id_1Fh_I3_Offset");
		snprintf(v[27], string_size, "inverters_inv_r_send_read_id_20h_I_Actual");
		snprintf(v[28], string_size, "inverters_inv_r_send_read_id_21h_Id_setdig");
		snprintf(v[29], string_size, "inverters_inv_r_send_read_id_22h_I_cmd_ramp");
		snprintf(v[30], string_size, "inverters_inv_r_send_read_id_23h_Id_Ref");
		snprintf(v[31], string_size, "inverters_inv_r_send_read_id_24h_I_Max_Inuse");
		snprintf(v[32], string_size, "inverters_inv_r_send_read_id_25h_I_Delta_Ramp");
		snprintf(v[33], string_size, "inverters_inv_r_send_read_id_26h_I_cmd");
		snprintf(v[34], string_size, "inverters_inv_r_send_read_id_27h_Iq_Actual");
		snprintf(v[35], string_size, "inverters_inv_r_send_read_id_28h_Id_Actual");
		snprintf(v[36], string_size, "inverters_inv_r_send_read_id_29h_Vq_Output");
		snprintf(v[37], string_size, "inverters_inv_r_send_read_id_2Ah_Vd_Output");
		snprintf(v[38], string_size, "inverters_inv_r_send_read_id_2Bh_I_TiM");
		snprintf(v[39], string_size, "inverters_inv_r_send_read_id_2Ch_n_Kp");
		snprintf(v[40], string_size, "inverters_inv_r_send_read_id_2Dh_n_Ti");
		snprintf(v[41], string_size, "inverters_inv_r_send_read_id_2Eh_n_Td");
		snprintf(v[42], string_size, "inverters_inv_r_send_read_id_2Fh_Ain_in_1_OffsScale");
		snprintf(v[43], string_size, "inverters_inv_r_send_read_id_30h_N_Actual");
		snprintf(v[44], string_size, "inverters_inv_r_send_read_id_31h_N_setdig");
		snprintf(v[45], string_size, "inverters_inv_r_send_read_id_32h_N_cmd_ramp");
		snprintf(v[46], string_size, "inverters_inv_r_send_read_id_33h_N_Error");
		snprintf(v[47], string_size, "inverters_inv_r_send_read_id_34h_N_Lim");
		snprintf(v[48], string_size, "inverters_inv_r_send_read_id_35h_Acc_Ramps");
		snprintf(v[49], string_size, "inverters_inv_r_send_read_id_36h_CommandSource");
		snprintf(v[50], string_size, "inverters_inv_r_send_read_id_37h_DZR_Sequencer_Value");
		snprintf(v[51], string_size, "inverters_inv_r_send_read_id_38h_Iq_Error");
		snprintf(v[52], string_size, "inverters_inv_r_send_read_id_39h_Id_Error");
		snprintf(v[53], string_size, "inverters_inv_r_send_read_id_3Bh_n_TiM");
		snprintf(v[54], string_size, "inverters_inv_r_send_read_id_3Ch_I_Derating_N_perc");
		snprintf(v[55], string_size, "inverters_inv_r_send_read_id_3Eh_N_Lim_minus");
		snprintf(v[56], string_size, "inverters_inv_r_send_read_id_3Fh_N_Lim_plus");
		snprintf(v[57], string_size, "inverters_inv_r_send_read_id_40h_Status_Map");
		snprintf(v[58], string_size, "inverters_inv_r_send_read_id_41h_Incr_Delta");
		snprintf(v[59], string_size, "inverters_inv_r_send_read_id_42h_MotorPosition_Mech");
		snprintf(v[60], string_size, "inverters_inv_r_send_read_id_43h_MotorPosition_Elec");
		snprintf(v[61], string_size, "inverters_inv_r_send_read_id_44h_FeedBack_Offset_Angle");
		snprintf(v[62], string_size, "inverters_inv_r_send_read_id_45h_Ixt_and_RegenE_Monitor");
		snprintf(v[63], string_size, "inverters_inv_r_send_read_id_46h_I_lim_dig_perc");
		snprintf(v[64], string_size, "inverters_inv_r_send_read_id_48h_I_Limit_Inuse");
		snprintf(v[65], string_size, "inverters_inv_r_send_read_id_49h_T_Motor");
		snprintf(v[66], string_size, "inverters_inv_r_send_read_id_4Ah_T_Igbt");
		snprintf(v[67], string_size, "inverters_inv_r_send_read_id_4Bh_T_Air_Inside");
		snprintf(v[68], string_size, "inverters_inv_r_send_read_id_4Ch_I_Derating_TE");
		snprintf(v[69], string_size, "inverters_inv_r_send_read_id_4Dh_Motor_I_max_eff");
		snprintf(v[70], string_size, "inverters_inv_r_send_read_id_4Eh_Motor_I_nom_eff");
		snprintf(v[71], string_size, "inverters_inv_r_send_read_id_4Fh_Motor_Pole");
		snprintf(v[72], string_size, "inverters_inv_r_send_read_id_50h_Ain_in_1_Cutoff");
		snprintf(v[73], string_size, "inverters_inv_r_send_read_id_51h_Kern_Mode_State");
		snprintf(v[74], string_size, "inverters_inv_r_send_read_id_52h_Status_Mask");
		snprintf(v[75], string_size, "inverters_inv_r_send_read_id_53h_Ain_in_2_Cutoff");
		snprintf(v[76], string_size, "inverters_inv_r_send_read_id_54h_I1_Actual");
		snprintf(v[77], string_size, "inverters_inv_r_send_read_id_55h_I2_Actual");
		snprintf(v[78], string_size, "inverters_inv_r_send_read_id_56h_I3_Actual");
		snprintf(v[79], string_size, "inverters_inv_r_send_read_id_57h_I_Limit_Inuse_ramp");
		snprintf(v[80], string_size, "inverters_inv_r_send_read_id_58h_I_Derating_TD");
		snprintf(v[81], string_size, "inverters_inv_r_send_read_id_59h_Motor_Nom");
		snprintf(v[82], string_size, "inverters_inv_r_send_read_id_5Ah_Device_Options");
		snprintf(v[83], string_size, "inverters_inv_r_send_read_id_5Bh_SpeedControl_Kacc");
		snprintf(v[84], string_size, "inverters_inv_r_send_read_id_5Ch_Rotor_Signals");
		snprintf(v[85], string_size, "inverters_inv_r_send_read_id_5Dh_N_cmd");
		snprintf(v[86], string_size, "inverters_inv_r_send_read_id_5Eh_Speed_Filter");
		snprintf(v[87], string_size, "inverters_inv_r_send_read_id_5Fh_I_Actual_Filt");
		snprintf(v[88], string_size, "inverters_inv_r_send_read_id_60h_Ain_in_X_Filter");
		snprintf(v[89], string_size, "inverters_inv_r_send_read_id_61h_Ixt_Monitor");
		snprintf(v[90], string_size, "inverters_inv_r_send_read_id_62h_SerialNumber");
		snprintf(v[91], string_size, "inverters_inv_r_send_read_id_63h_FPGA_Status");
		snprintf(v[92], string_size, "inverters_inv_r_send_read_id_64h_Device_Mains");
		snprintf(v[93], string_size, "inverters_inv_r_send_read_id_65h_Regen_P_R");
		snprintf(v[94], string_size, "inverters_inv_r_send_read_id_67h_Device_Type");
		snprintf(v[95], string_size, "inverters_inv_r_send_read_id_68h_CAN_ID_Rx");
		snprintf(v[96], string_size, "inverters_inv_r_send_read_id_69h_CAN_ID_Tx");
		snprintf(v[97], string_size, "inverters_inv_r_send_read_id_6Ah_Pos_Kp");
		snprintf(v[98], string_size, "inverters_inv_r_send_read_id_6Bh_Pos_Ti");
		snprintf(v[99], string_size, "inverters_inv_r_send_read_id_6Ch_Pos_Td");
		snprintf(v[100], string_size, "inverters_inv_r_send_read_id_6Dh_Pos_Actual");
		snprintf(v[101], string_size, "inverters_inv_r_send_read_id_6Eh_Pos_Dest");
		snprintf(v[102], string_size, "inverters_inv_r_send_read_id_6Fh_Pos_Actual_2");
		snprintf(v[103], string_size, "inverters_inv_r_send_read_id_70h_Pos_Err");
		snprintf(v[104], string_size, "inverters_inv_r_send_read_id_71h_Pos_TiM");
		snprintf(v[105], string_size, "inverters_inv_r_send_read_id_72h_Pos_OffsetRef");
		snprintf(v[106], string_size, "inverters_inv_r_send_read_id_73h_CAN_NBT");
		snprintf(v[107], string_size, "inverters_inv_r_send_read_id_74h_Pos_Zero_Capture");
		snprintf(v[108], string_size, "inverters_inv_r_send_read_id_75h_Pos_Ref_Reso_Edge");
		snprintf(v[109], string_size, "inverters_inv_r_send_read_id_76h_Pos_Speed_1");
		snprintf(v[110], string_size, "inverters_inv_r_send_read_id_77h_Pos_Speed_2");
		snprintf(v[111], string_size, "inverters_inv_r_send_read_id_78h_Pos_Ref_Start");
		snprintf(v[112], string_size, "inverters_inv_r_send_read_id_79h_Pos_Tol_Win");
		snprintf(v[113], string_size, "inverters_inv_r_send_read_id_7Ah_Pos_Preset");
		snprintf(v[114], string_size, "inverters_inv_r_send_read_id_7Bh_Pos_Zero_Offset");
		snprintf(v[115], string_size, "inverters_inv_r_send_read_id_7Ch_Pos_ND_Scale");
		snprintf(v[116], string_size, "inverters_inv_r_send_read_id_7Dh_Pos_ND_Offset");
		snprintf(v[117], string_size, "inverters_inv_r_send_read_id_7Eh_Pos_FB2_Scale_Fac_Ext");
		snprintf(v[118], string_size, "inverters_inv_r_send_read_id_7Fh_Pos_Offset_Slack");
		snprintf(v[119], string_size, "inverters_inv_r_send_read_id_80h_Pos_Diff_Slack");
		snprintf(v[120], string_size, "inverters_inv_r_send_read_id_83h_Func_Para_Read");
		snprintf(v[121], string_size, "inverters_inv_r_send_read_id_84h_Func_Para_Write");
		snprintf(v[122], string_size, "inverters_inv_r_send_read_id_85h_Func_Special");
		snprintf(v[123], string_size, "inverters_inv_r_send_read_id_88h_CAN_ID_2_Rx");
		snprintf(v[124], string_size, "inverters_inv_r_send_read_id_89h_CAN_ID_2_Tx");
		snprintf(v[125], string_size, "inverters_inv_r_send_read_id_8Ah_Vout");
		snprintf(v[126], string_size, "inverters_inv_r_send_read_id_8Bh_V_Ref");
		snprintf(v[127], string_size, "inverters_inv_r_send_read_id_8Ch_V_Kp");
		snprintf(v[128], string_size, "inverters_inv_r_send_read_id_8Dh_V_Ti");
		snprintf(v[129], string_size, "inverters_inv_r_send_read_id_8Eh_Clear_Error_List");
		snprintf(v[130], string_size, "inverters_inv_r_send_read_id_8Fh_ErrorWarning_Map");
		snprintf(v[131], string_size, "inverters_inv_r_send_read_id_90h_M_setdig");
		snprintf(v[132], string_size, "inverters_inv_r_send_read_id_91h_Pos_cmd_int");
		snprintf(v[133], string_size, "inverters_inv_r_send_read_id_92h_CAN_Error_BusOff_cntr");
		snprintf(v[134], string_size, "inverters_inv_r_send_read_id_93h_CAN_Error_WriteTime_cntr");
		snprintf(v[135], string_size, "inverters_inv_r_send_read_id_94h_CAN_Error_RxMsgLost_cntr");
		snprintf(v[136], string_size, "inverters_inv_r_send_read_id_95h_CAN_Error_NoAck_cntr");
		snprintf(v[137], string_size, "inverters_inv_r_send_read_id_96h_CAN_Error_CRC_Check_cntr");
		snprintf(v[138], string_size, "inverters_inv_r_send_read_id_97h_CAN_Error_Bit_cntr");
		snprintf(v[139], string_size, "inverters_inv_r_send_read_id_99h_Info_Timer_Diff");
		snprintf(v[140], string_size, "inverters_inv_r_send_read_id_9Ah_Temp_DEBUG");
		snprintf(v[141], string_size, "inverters_inv_r_send_read_id_A0h_Mout");
		snprintf(v[142], string_size, "inverters_inv_r_send_read_id_A1h_Ballast_cntr");
		snprintf(v[143], string_size, "inverters_inv_r_send_read_id_A2h_I_Derating_TM");
		snprintf(v[144], string_size, "inverters_inv_r_send_read_id_A3h_M_Temp");
		snprintf(v[145], string_size, "inverters_inv_r_send_read_id_A4h_Motor_Options");
		snprintf(v[146], string_size, "inverters_inv_r_send_read_id_A5h_DC_Bus_MinMax_Lim");
		snprintf(v[147], string_size, "inverters_inv_r_send_read_id_A6h_FB_IncPerRot");
		snprintf(v[148], string_size, "inverters_inv_r_send_read_id_A7h_FB_Pole");
		snprintf(v[149], string_size, "inverters_inv_r_send_read_id_A8h_N_Actual_Filt");
		snprintf(v[150], string_size, "inverters_inv_r_send_read_id_A9h_I3_ADC");
		snprintf(v[151], string_size, "inverters_inv_r_send_read_id_AAh_I2_ADC");
		snprintf(v[152], string_size, "inverters_inv_r_send_read_id_ABh_Logic_Freq");
		snprintf(v[153], string_size, "inverters_inv_r_send_read_id_ACh_PWM_1_56");
		snprintf(v[154], string_size, "inverters_inv_r_send_read_id_ADh_PWM_2_34");
		snprintf(v[155], string_size, "inverters_inv_r_send_read_id_AEh_PWM_3_12");
		snprintf(v[156], string_size, "inverters_inv_r_send_read_id_AFh_Timer_Delta");
		snprintf(v[157], string_size, "inverters_inv_r_send_read_id_B1h_Motor_Lsq");
		snprintf(v[158], string_size, "inverters_inv_r_send_read_id_B2h_Id_Nom");
		snprintf(v[159], string_size, "inverters_inv_r_send_read_id_B3h_Motor_Lm");
		snprintf(v[160], string_size, "inverters_inv_r_send_read_id_B4h_Motor_Rr");
		snprintf(v[161], string_size, "inverters_inv_r_send_read_id_B5h_Id_Min");
		snprintf(v[162], string_size, "inverters_inv_r_send_read_id_B6h_Motor_Tr");
		snprintf(v[163], string_size, "inverters_inv_r_send_read_id_B8h_Ptr_1_DEBUG");
		snprintf(v[164], string_size, "inverters_inv_r_send_read_id_BAh_Ptr_2_DEBUG");
		snprintf(v[165], string_size, "inverters_inv_r_send_read_id_BBh_Motor_Lsd");
		snprintf(v[166], string_size, "inverters_inv_r_send_read_id_BCh_Motor_Rs");
		snprintf(v[167], string_size, "inverters_inv_r_send_read_id_BDh_Motor_Ts");
		snprintf(v[168], string_size, "inverters_inv_r_send_read_id_BEh_def_END_1");
		snprintf(v[169], string_size, "inverters_inv_r_send_read_id_BFh_def_END_2");
		snprintf(v[170], string_size, "inverters_inv_r_send_read_id_C0h_def_DIN_1");
		snprintf(v[171], string_size, "inverters_inv_r_send_read_id_C1h_def_DIN_2");
		snprintf(v[172], string_size, "inverters_inv_r_send_read_id_C2h_def_OUT_1");
		snprintf(v[173], string_size, "inverters_inv_r_send_read_id_C3h_def_OUT_2");
		snprintf(v[174], string_size, "inverters_inv_r_send_read_id_C4h_I_max_pk");
		snprintf(v[175], string_size, "inverters_inv_r_send_read_id_C5h_I_con_eff");
		snprintf(v[176], string_size, "inverters_inv_r_send_read_id_C6h_I_device");
		snprintf(v[177], string_size, "inverters_inv_r_send_read_id_C7h_RLim_MRcp_Ramp");
		snprintf(v[178], string_size, "inverters_inv_r_send_read_id_C8h_Nmax100perc");
		snprintf(v[179], string_size, "inverters_inv_r_send_read_id_C9h_I_xKp");
		snprintf(v[180], string_size, "inverters_inv_r_send_read_id_CAh_Bat_Opr_Limits");
		snprintf(v[181], string_size, "inverters_inv_r_send_read_id_CBh_I_Kf");
		snprintf(v[182], string_size, "inverters_inv_r_send_read_id_CCh_Car_Mode_Status");
		snprintf(v[183], string_size, "inverters_inv_r_send_read_id_CDh_Car_Mode_Config");
		snprintf(v[184], string_size, "inverters_inv_r_send_read_id_CEh_N_Rpm_MaxInt");
		snprintf(v[185], string_size, "inverters_inv_r_send_read_id_D0h_CAN_Timeout");
		snprintf(v[186], string_size, "inverters_inv_r_send_read_id_D1h_Var_1");
		snprintf(v[187], string_size, "inverters_inv_r_send_read_id_D2h_Var_2");
		snprintf(v[188], string_size, "inverters_inv_r_send_read_id_D3h_Var_3");
		snprintf(v[189], string_size, "inverters_inv_r_send_read_id_D4h_Var_4");
		snprintf(v[190], string_size, "inverters_inv_r_send_read_id_D5h_Ain_in_1");
		snprintf(v[191], string_size, "inverters_inv_r_send_read_id_D6h_Ain_in_2");
		snprintf(v[192], string_size, "inverters_inv_r_send_read_id_D7h_Ain_in_2_OffsScale");
		snprintf(v[193], string_size, "inverters_inv_r_send_read_id_D8h_LogicReadBitsIN_OUT");
		snprintf(v[194], string_size, "inverters_inv_r_send_read_id_D9h_I_200perc");
		snprintf(v[195], string_size, "inverters_inv_r_send_read_id_DAh_def_OUT_3");
		snprintf(v[196], string_size, "inverters_inv_r_send_read_id_DBh_def_OUT_4");
		snprintf(v[197], string_size, "inverters_inv_r_send_read_id_DCh_DAC_Source_ID");
		snprintf(v[198], string_size, "inverters_inv_r_send_read_id_DEh_DS_DOUT_3");
		snprintf(v[199], string_size, "inverters_inv_r_send_read_id_DFh_DS_DOUT_4");
		snprintf(v[200], string_size, "inverters_inv_r_send_read_id_E0h_DS_DOUT_1");
		snprintf(v[201], string_size, "inverters_inv_r_send_read_id_E1h_DS_DOUT_2");
		snprintf(v[202], string_size, "inverters_inv_r_send_read_id_E2h_DS_Rdy_BTB");
		snprintf(v[203], string_size, "inverters_inv_r_send_read_id_E3h_DS_GO");
		snprintf(v[204], string_size, "inverters_inv_r_send_read_id_E4h_DS_END_1");
		snprintf(v[205], string_size, "inverters_inv_r_send_read_id_E5h_DS_END_2");
		snprintf(v[206], string_size, "inverters_inv_r_send_read_id_E6h_DS_DIN_1");
		snprintf(v[207], string_size, "inverters_inv_r_send_read_id_E7h_DS_DIN_2");
		snprintf(v[208], string_size, "inverters_inv_r_send_read_id_E8h_DS_RUN");
		snprintf(v[209], string_size, "inverters_inv_r_send_read_id_E9h_DS_I_Fault");
		snprintf(v[210], string_size, "inverters_inv_r_send_read_id_EBh_Vdc_Bus");
		snprintf(v[211], string_size, "inverters_inv_r_send_read_id_ECh_DS_FB_LossOfSignal");
		snprintf(v[212], string_size, "inverters_inv_r_send_read_id_EDh_Dec_Ramps");
		snprintf(v[213], string_size, "inverters_inv_r_send_read_id_EEh_V_Shunt");
		snprintf(v[214], string_size, "inverters_inv_r_send_read_id_EFh_DS_NoHWFault");
		snprintf(v[215], string_size, "inverters_inv_r_send_read_id_F0h_T_peak");
		snprintf(v[216], string_size, "inverters_inv_r_send_read_id_F1h_Brake_Delay");
		snprintf(v[217], string_size, "inverters_inv_r_send_read_id_F2h_DS_Brake");
		snprintf(v[218], string_size, "inverters_inv_r_send_read_id_F3h_DS_Icns");
		snprintf(v[219], string_size, "inverters_inv_r_send_read_id_F4h_DS_PosTolerance");
		snprintf(v[220], string_size, "inverters_inv_r_send_read_id_F5h_DS_LessN0");
		snprintf(v[221], string_size, "inverters_inv_r_send_read_id_F6h_Inverter_Power");
		snprintf(v[222], string_size, "inverters_inv_r_send_read_id_F7h_Inverter_Work");
		snprintf(v[223], string_size, "inverters_inv_r_send_read_id_F8h_Axis");
		snprintf(v[224], string_size, "inverters_inv_r_send_read_id_FBh_Ain_in_1_Calc");
		snprintf(v[225], string_size, "inverters_inv_r_send_read_id_FCh_Ain_in_2_Calc");
		snprintf(v[226], string_size, "inverters_inv_r_send_read_id_66h_DC_Bus_Voltage");
		snprintf(v[227], string_size, "inverters_inv_r_send_read_id_3Ah_M_cmd_ramp");
		snprintf(v[228], string_size, "inverters_inv_r_send_read_id_FEh_Subv_SVNRev_Nr");

		return 0;
	case 14:
		if(29 > fields_size) return 1;
		snprintf(v[0], string_size, "inverters_inv_r_send_def_din_1__Off_");
		snprintf(v[1], string_size, "inverters_inv_r_send_def_din_1_Ref_and_Limit_Plus");
		snprintf(v[2], string_size, "inverters_inv_r_send_def_din_1_Ref_and_Limit_Minus");
		snprintf(v[3], string_size, "inverters_inv_r_send_def_din_1_Ref_Plus");
		snprintf(v[4], string_size, "inverters_inv_r_send_def_din_1_Limit_Plus");
		snprintf(v[5], string_size, "inverters_inv_r_send_def_din_1_Limit_Minus");
		snprintf(v[6], string_size, "inverters_inv_r_send_def_din_1_Limit_Plus_and_Minus");
		snprintf(v[7], string_size, "inverters_inv_r_send_def_din_1_Cancel_Error_s_");
		snprintf(v[8], string_size, "inverters_inv_r_send_def_din_1__Start_Ref_Drive");
		snprintf(v[9], string_size, "inverters_inv_r_send_def_din_1_Speed_Ramp_0");
		snprintf(v[10], string_size, "inverters_inv_r_send_def_din_1__Start_Dest_eq_Var_1");
		snprintf(v[11], string_size, "inverters_inv_r_send_def_din_1__Start_Dest_eq_Var_2");
		snprintf(v[12], string_size, "inverters_inv_r_send_def_din_1_N_cmd_Reverse");
		snprintf(v[13], string_size, "inverters_inv_r_send_def_din_1__Preset_Pos_eq_Var_3");
		snprintf(v[14], string_size, "inverters_inv_r_send_def_din_1__Capture_Var_3_eq_Pos");
		snprintf(v[15], string_size, "inverters_inv_r_send_def_din_1__Capture_Var_4_eq_Pos");
		snprintf(v[16], string_size, "inverters_inv_r_send_def_din_1__Switch_Spd_eq_notAin1_Ain2");
		snprintf(v[17], string_size, "inverters_inv_r_send_def_din_1__Switch_Spd_eq_notVar1_Var2");
		snprintf(v[18], string_size, "inverters_inv_r_send_def_din_1_I_limit_dig_");
		snprintf(v[19], string_size, "inverters_inv_r_send_def_din_1_N_clip_neg_pos_");
		snprintf(v[20], string_size, "inverters_inv_r_send_def_din_1__Switch_Cmd_eq_notDig_Ana");
		snprintf(v[21], string_size, "inverters_inv_r_send_def_din_1_Speed_Ramp_0_Pos");
		snprintf(v[22], string_size, "inverters_inv_r_send_def_din_1_Handwheel");
		snprintf(v[23], string_size, "inverters_inv_r_send_def_din_1_Brake_Car");
		snprintf(v[24], string_size, "inverters_inv_r_send_def_din_1_Recup_Disabled");
		snprintf(v[25], string_size, "inverters_inv_r_send_def_din_1_Rising_Bank_1_Falling_Bank_0");
		snprintf(v[26], string_size, "inverters_inv_r_send_def_din_1__Start_Dest_eq_Var_1_2_3_4");
		snprintf(v[27], string_size, "inverters_inv_r_send_def_din_1__Start_CW_eq_Var_1_2_3_4");
		snprintf(v[28], string_size, "inverters_inv_r_send_def_din_1_Brake_Car_Nr2");

		return 0;
	case 15:
		if(29 > fields_size) return 1;
		snprintf(v[0], string_size, "inverters_inv_r_send_def_end_1__Off_");
		snprintf(v[1], string_size, "inverters_inv_r_send_def_end_1_Ref_and_Limit_Plus");
		snprintf(v[2], string_size, "inverters_inv_r_send_def_end_1_Ref_and_Limit_Minus");
		snprintf(v[3], string_size, "inverters_inv_r_send_def_end_1_Ref_Plus");
		snprintf(v[4], string_size, "inverters_inv_r_send_def_end_1_Limit_Plus");
		snprintf(v[5], string_size, "inverters_inv_r_send_def_end_1_Limit_Minus");
		snprintf(v[6], string_size, "inverters_inv_r_send_def_end_1_Limit_Plus_and_Minus");
		snprintf(v[7], string_size, "inverters_inv_r_send_def_end_1_Cancel_Error_s_");
		snprintf(v[8], string_size, "inverters_inv_r_send_def_end_1__Start_Ref_Drive");
		snprintf(v[9], string_size, "inverters_inv_r_send_def_end_1_Speed_Ramp_0");
		snprintf(v[10], string_size, "inverters_inv_r_send_def_end_1__Start_Dest_eq_Var_1");
		snprintf(v[11], string_size, "inverters_inv_r_send_def_end_1__Start_Dest_eq_Var_2");
		snprintf(v[12], string_size, "inverters_inv_r_send_def_end_1_N_cmd_Reverse");
		snprintf(v[13], string_size, "inverters_inv_r_send_def_end_1__Preset_Pos_eq_Var_3");
		snprintf(v[14], string_size, "inverters_inv_r_send_def_end_1__Capture_Var_3_eq_Pos");
		snprintf(v[15], string_size, "inverters_inv_r_send_def_end_1__Capture_Var_4_eq_Pos");
		snprintf(v[16], string_size, "inverters_inv_r_send_def_end_1__Switch_Spd_eq_notAin1_Ain2");
		snprintf(v[17], string_size, "inverters_inv_r_send_def_end_1__Switch_Spd_eq_notVar1_Var2");
		snprintf(v[18], string_size, "inverters_inv_r_send_def_end_1_I_limit_dig_");
		snprintf(v[19], string_size, "inverters_inv_r_send_def_end_1_N_clip_neg_pos_");
		snprintf(v[20], string_size, "inverters_inv_r_send_def_end_1__Switch_Cmd_eq_notDig_Ana");
		snprintf(v[21], string_size, "inverters_inv_r_send_def_end_1_Speed_Ramp_0_Pos");
		snprintf(v[22], string_size, "inverters_inv_r_send_def_end_1_Handwheel");
		snprintf(v[23], string_size, "inverters_inv_r_send_def_end_1_Brake_Car");
		snprintf(v[24], string_size, "inverters_inv_r_send_def_end_1_Recup_Disabled");
		snprintf(v[25], string_size, "inverters_inv_r_send_def_end_1_Rising_Bank_1_Falling_Bank_0");
		snprintf(v[26], string_size, "inverters_inv_r_send_def_end_1__Start_Dest_eq_Var_1_2_3_4");
		snprintf(v[27], string_size, "inverters_inv_r_send_def_end_1__Start_CW_eq_Var_1_2_3_4");
		snprintf(v[28], string_size, "inverters_inv_r_send_def_end_1_Brake_Car_Nr2");

		return 0;
	case 16:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "inverters_inv_r_send_ret_interval_Stop");
		snprintf(v[1], string_size, "inverters_inv_r_send_ret_interval_Single");

		return 0;
	case 17:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "inverters_inv_r_send_active192_Low");
		snprintf(v[1], string_size, "inverters_inv_r_send_active192_High");

		return 0;
	case 18:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "inverters_inv_r_send_active190_Low");
		snprintf(v[1], string_size, "inverters_inv_r_send_active190_High");

		return 0;
	case 19:
		if(230 > fields_size) return 1;
		snprintf(v[0], string_size, "inverters_inv_r_rcv_rcv_mux_ID_30_N_Actual");
		snprintf(v[1], string_size, "inverters_inv_r_rcv_rcv_mux_ID_35_Acc_Ramps");
		snprintf(v[2], string_size, "inverters_inv_r_rcv_rcv_mux_ID_ED_Dec_Ramps");
		snprintf(v[3], string_size, "inverters_inv_r_rcv_rcv_mux_ID_C7_RLim_MRcp_Ramp");
		snprintf(v[4], string_size, "inverters_inv_r_rcv_rcv_mux_ID_A8_N_Actual_Filt");
		snprintf(v[5], string_size, "inverters_inv_r_rcv_rcv_mux_ID_1B_FW_Nr");
		snprintf(v[6], string_size, "inverters_inv_r_rcv_rcv_mux_ID_67_Device_Type");
		snprintf(v[7], string_size, "inverters_inv_r_rcv_rcv_mux_ID_62_SerialNumber");
		snprintf(v[8], string_size, "inverters_inv_r_rcv_rcv_mux_ID_F8_Axis_Label");
		snprintf(v[9], string_size, "inverters_inv_r_rcv_rcv_mux_ID_C6_I_device");
		snprintf(v[10], string_size, "inverters_inv_r_rcv_rcv_mux_ID_EE_V_Shunt");
		snprintf(v[11], string_size, "inverters_inv_r_rcv_rcv_mux_ID_D9_I_200perc");
		snprintf(v[12], string_size, "inverters_inv_r_rcv_rcv_mux_ID_5A_Device_Options");
		snprintf(v[13], string_size, "inverters_inv_r_rcv_rcv_mux_ID_40_Status_Map");
		snprintf(v[14], string_size, "inverters_inv_r_rcv_rcv_mux_ID_8F_ErrorWarning_Map");
		snprintf(v[15], string_size, "inverters_inv_r_rcv_rcv_mux_ID_D8_LogicReadBitsIN_OUT");
		snprintf(v[16], string_size, "inverters_inv_r_rcv_rcv_mux_ID_D5_Ain_in_1");
		snprintf(v[17], string_size, "inverters_inv_r_rcv_rcv_mux_ID_D6_Ain_in_2");
		snprintf(v[18], string_size, "inverters_inv_r_rcv_rcv_mux_ID_C8_Nmax100perc");
		snprintf(v[19], string_size, "inverters_inv_r_rcv_rcv_mux_ID_31_N_setdig");
		snprintf(v[20], string_size, "inverters_inv_r_rcv_rcv_mux_ID_5D_N_cmd");
		snprintf(v[21], string_size, "inverters_inv_r_rcv_rcv_mux_ID_32_N_cmd_ramp");
		snprintf(v[22], string_size, "inverters_inv_r_rcv_rcv_mux_ID_34_N_Lim");
		snprintf(v[23], string_size, "inverters_inv_r_rcv_rcv_mux_ID_33_N_Error");
		snprintf(v[24], string_size, "inverters_inv_r_rcv_rcv_mux_ID_90_M_setdig");
		snprintf(v[25], string_size, "inverters_inv_r_rcv_rcv_mux_ID_21_Id_setdig");
		snprintf(v[26], string_size, "inverters_inv_r_rcv_rcv_mux_ID_C4_I_max_pk_perc");
		snprintf(v[27], string_size, "inverters_inv_r_rcv_rcv_mux_ID_C5_I_con_eff_perc");
		snprintf(v[28], string_size, "inverters_inv_r_rcv_rcv_mux_ID_4D_Motor_I_max_eff_Arms");
		snprintf(v[29], string_size, "inverters_inv_r_rcv_rcv_mux_ID_4E_Motor_I_nom_eff_Arms");
		snprintf(v[30], string_size, "inverters_inv_r_rcv_rcv_mux_ID_48_I_Limit_Inuse");
		snprintf(v[31], string_size, "inverters_inv_r_rcv_rcv_mux_ID_26_I_cmd");
		snprintf(v[32], string_size, "inverters_inv_r_rcv_rcv_mux_ID_22_I_cmd_ramp");
		snprintf(v[33], string_size, "inverters_inv_r_rcv_rcv_mux_ID_20_I_Actual");
		snprintf(v[34], string_size, "inverters_inv_r_rcv_rcv_mux_ID_5F_I_Actual_Filt");
		snprintf(v[35], string_size, "inverters_inv_r_rcv_rcv_mux_ID_27_Iq_Actual");
		snprintf(v[36], string_size, "inverters_inv_r_rcv_rcv_mux_ID_28_Id_Actual");
		snprintf(v[37], string_size, "inverters_inv_r_rcv_rcv_mux_ID_38_Iq_Error");
		snprintf(v[38], string_size, "inverters_inv_r_rcv_rcv_mux_ID_39_Id_Error");
		snprintf(v[39], string_size, "inverters_inv_r_rcv_rcv_mux_ID_54_I1_Actual");
		snprintf(v[40], string_size, "inverters_inv_r_rcv_rcv_mux_ID_55_I2_Actual");
		snprintf(v[41], string_size, "inverters_inv_r_rcv_rcv_mux_ID_56_I3_Actual");
		snprintf(v[42], string_size, "inverters_inv_r_rcv_rcv_mux_ID_A9_I3_ADC_Value");
		snprintf(v[43], string_size, "inverters_inv_r_rcv_rcv_mux_ID_AA_I2_ADC_Value");
		snprintf(v[44], string_size, "inverters_inv_r_rcv_rcv_mux_ID_29_Vq_Output");
		snprintf(v[45], string_size, "inverters_inv_r_rcv_rcv_mux_ID_2A_Vd_Output");
		snprintf(v[46], string_size, "inverters_inv_r_rcv_rcv_mux_ID_8A_V_Output");
		snprintf(v[47], string_size, "inverters_inv_r_rcv_rcv_mux_ID_49_T_Motor");
		snprintf(v[48], string_size, "inverters_inv_r_rcv_rcv_mux_ID_4A_T_Igbt");
		snprintf(v[49], string_size, "inverters_inv_r_rcv_rcv_mux_ID_4B_T_Air_Inside");
		snprintf(v[50], string_size, "inverters_inv_r_rcv_rcv_mux_ID_EB_DC_Bus_Voltage_Filt");
		snprintf(v[51], string_size, "inverters_inv_r_rcv_rcv_mux_ID_E4_DigInput_END_1");
		snprintf(v[52], string_size, "inverters_inv_r_rcv_rcv_mux_ID_E6_DigInput_DIN_1");
		snprintf(v[53], string_size, "inverters_inv_r_rcv_rcv_mux_ID_E5_DigInput_END_2");
		snprintf(v[54], string_size, "inverters_inv_r_rcv_rcv_mux_ID_E7_DigInput_DIN_2");
		snprintf(v[55], string_size, "inverters_inv_r_rcv_rcv_mux_ID_E8_DigInput_RUN");
		snprintf(v[56], string_size, "inverters_inv_r_rcv_rcv_mux_ID_E0_DigOutput_DOUT_1");
		snprintf(v[57], string_size, "inverters_inv_r_rcv_rcv_mux_ID_E1_DigOutput_DOUT_2");
		snprintf(v[58], string_size, "inverters_inv_r_rcv_rcv_mux_ID_DE_DigOutput_DOUT_3");
		snprintf(v[59], string_size, "inverters_inv_r_rcv_rcv_mux_ID_E2_DigOutput_Rdy_BTB");
		snprintf(v[60], string_size, "inverters_inv_r_rcv_rcv_mux_ID_E9_Error_I_Fault");
		snprintf(v[61], string_size, "inverters_inv_r_rcv_rcv_mux_ID_DF_DigOutput_DOUT_4");
		snprintf(v[62], string_size, "inverters_inv_r_rcv_rcv_mux_ID_46_I_lim_dig_perc");
		snprintf(v[63], string_size, "inverters_inv_r_rcv_rcv_mux_ID_3C_I_Derating_N_perc");
		snprintf(v[64], string_size, "inverters_inv_r_rcv_rcv_mux_ID_58_I_Derating_TD");
		snprintf(v[65], string_size, "inverters_inv_r_rcv_rcv_mux_ID_4C_I_Derating_TE");
		snprintf(v[66], string_size, "inverters_inv_r_rcv_rcv_mux_ID_A2_I_Derating_TM");
		snprintf(v[67], string_size, "inverters_inv_r_rcv_rcv_mux_ID_36_CommandSource");
		snprintf(v[68], string_size, "inverters_inv_r_rcv_rcv_mux_ID_23_Id_Ref");
		snprintf(v[69], string_size, "inverters_inv_r_rcv_rcv_mux_ID_A0_M_outdig");
		snprintf(v[70], string_size, "inverters_inv_r_rcv_rcv_mux_ID_B8_Ptr_1_DEBUG");
		snprintf(v[71], string_size, "inverters_inv_r_rcv_rcv_mux_ID_BA_Ptr_2_DEBUG");
		snprintf(v[72], string_size, "inverters_inv_r_rcv_rcv_mux_ID_9A_Temp_DEBUG");
		snprintf(v[73], string_size, "inverters_inv_r_rcv_rcv_mux_ID_05_Motor_F_nom");
		snprintf(v[74], string_size, "inverters_inv_r_rcv_rcv_mux_ID_06_Motor_V_nom");
		snprintf(v[75], string_size, "inverters_inv_r_rcv_rcv_mux_ID_07_FU_T_dc");
		snprintf(v[76], string_size, "inverters_inv_r_rcv_rcv_mux_ID_08_FU_V_dc");
		snprintf(v[77], string_size, "inverters_inv_r_rcv_rcv_mux_ID_0A_FU_U_min");
		snprintf(v[78], string_size, "inverters_inv_r_rcv_rcv_mux_ID_0B_FU_F_min");
		snprintf(v[79], string_size, "inverters_inv_r_rcv_rcv_mux_ID_0C_FU_V_corner");
		snprintf(v[80], string_size, "inverters_inv_r_rcv_rcv_mux_ID_0D_FU_F_corner");
		snprintf(v[81], string_size, "inverters_inv_r_rcv_rcv_mux_ID_0E_Motor_Cos_Phi");
		snprintf(v[82], string_size, "inverters_inv_r_rcv_rcv_mux_ID_19_PWM_Enum");
		snprintf(v[83], string_size, "inverters_inv_r_rcv_rcv_mux_ID_1A_Calib_Ref_Value");
		snprintf(v[84], string_size, "inverters_inv_r_rcv_rcv_mux_ID_1C_PID_I_Kp");
		snprintf(v[85], string_size, "inverters_inv_r_rcv_rcv_mux_ID_1D_PID_I_Ti");
		snprintf(v[86], string_size, "inverters_inv_r_rcv_rcv_mux_ID_1E_Cutoffdig");
		snprintf(v[87], string_size, "inverters_inv_r_rcv_rcv_mux_ID_1F_I3_Offset");
		snprintf(v[88], string_size, "inverters_inv_r_rcv_rcv_mux_ID_25_I_Delta_Ramp");
		snprintf(v[89], string_size, "inverters_inv_r_rcv_rcv_mux_ID_2B_PID_I_TiM");
		snprintf(v[90], string_size, "inverters_inv_r_rcv_rcv_mux_ID_2C_PID_n_Kp");
		snprintf(v[91], string_size, "inverters_inv_r_rcv_rcv_mux_ID_8D_VoltageControl_Ti");
		snprintf(v[92], string_size, "inverters_inv_r_rcv_rcv_mux_ID_2E_PID_n_Td");
		snprintf(v[93], string_size, "inverters_inv_r_rcv_rcv_mux_ID_2F_Ain_in_1_OffsScale");
		snprintf(v[94], string_size, "inverters_inv_r_rcv_rcv_mux_ID_D7_Ain_in_2_OffsScale");
		snprintf(v[95], string_size, "inverters_inv_r_rcv_rcv_mux_ID_37_DZR_Sequencer_Value");
		snprintf(v[96], string_size, "inverters_inv_r_rcv_rcv_mux_ID_3B_PID_n_TiM");
		snprintf(v[97], string_size, "inverters_inv_r_rcv_rcv_mux_ID_3F_N_Lim_plus");
		snprintf(v[98], string_size, "inverters_inv_r_rcv_rcv_mux_ID_3E_N_Lim_minus");
		snprintf(v[99], string_size, "inverters_inv_r_rcv_rcv_mux_ID_41_Incr_Delta");
		snprintf(v[100], string_size, "inverters_inv_r_rcv_rcv_mux_ID_42_MotorPosition_Mech");
		snprintf(v[101], string_size, "inverters_inv_r_rcv_rcv_mux_ID_43_MotorPosition_Elec");
		snprintf(v[102], string_size, "inverters_inv_r_rcv_rcv_mux_ID_44_FeedBack_Offset_Angle");
		snprintf(v[103], string_size, "inverters_inv_r_rcv_rcv_mux_ID_45_Ixt_and_RegenE_Monitor");
		snprintf(v[104], string_size, "inverters_inv_r_rcv_rcv_mux_ID_4F_Motor_Pole_Number");
		snprintf(v[105], string_size, "inverters_inv_r_rcv_rcv_mux_ID_50_Ain_in_1_Cutoff");
		snprintf(v[106], string_size, "inverters_inv_r_rcv_rcv_mux_ID_11_Control_Status");
		snprintf(v[107], string_size, "inverters_inv_r_rcv_rcv_mux_ID_51_Kern_Mode_State");
		snprintf(v[108], string_size, "inverters_inv_r_rcv_rcv_mux_ID_52_Status_Mask");
		snprintf(v[109], string_size, "inverters_inv_r_rcv_rcv_mux_ID_53_Ain_in_2_Cutoff");
		snprintf(v[110], string_size, "inverters_inv_r_rcv_rcv_mux_ID_57_I_Limit_Inuse_ramp");
		snprintf(v[111], string_size, "inverters_inv_r_rcv_rcv_mux_ID_59_Motor_Nominal_Speed");
		snprintf(v[112], string_size, "inverters_inv_r_rcv_rcv_mux_ID_5B_SpeedControl_Kacc");
		snprintf(v[113], string_size, "inverters_inv_r_rcv_rcv_mux_ID_5C_Rotor_Signals");
		snprintf(v[114], string_size, "inverters_inv_r_rcv_rcv_mux_ID_5E_Speed_Filter");
		snprintf(v[115], string_size, "inverters_inv_r_rcv_rcv_mux_ID_60_Ain_in_X_Filter");
		snprintf(v[116], string_size, "inverters_inv_r_rcv_rcv_mux_ID_61_Ixt_Monitor");
		snprintf(v[117], string_size, "inverters_inv_r_rcv_rcv_mux_ID_63_ECODE_Status");
		snprintf(v[118], string_size, "inverters_inv_r_rcv_rcv_mux_ID_64_Device_Mains_Supply_V");
		snprintf(v[119], string_size, "inverters_inv_r_rcv_rcv_mux_ID_65_Regen_Resistor_P_and_R");
		snprintf(v[120], string_size, "inverters_inv_r_rcv_rcv_mux_ID_68_CAN_ID_Rx");
		snprintf(v[121], string_size, "inverters_inv_r_rcv_rcv_mux_ID_69_CAN_ID_Tx");
		snprintf(v[122], string_size, "inverters_inv_r_rcv_rcv_mux_ID_6A_Pos_PID_Kp");
		snprintf(v[123], string_size, "inverters_inv_r_rcv_rcv_mux_ID_6B_Pos_PID_Ti");
		snprintf(v[124], string_size, "inverters_inv_r_rcv_rcv_mux_ID_6C_Pos_PID_Td");
		snprintf(v[125], string_size, "inverters_inv_r_rcv_rcv_mux_ID_6D_Pos_Actual");
		snprintf(v[126], string_size, "inverters_inv_r_rcv_rcv_mux_ID_6E_Pos_Destination");
		snprintf(v[127], string_size, "inverters_inv_r_rcv_rcv_mux_ID_6F_Pos_Actual_2");
		snprintf(v[128], string_size, "inverters_inv_r_rcv_rcv_mux_ID_70_Pos_Error");
		snprintf(v[129], string_size, "inverters_inv_r_rcv_rcv_mux_ID_71_Pos_PID_TiM");
		snprintf(v[130], string_size, "inverters_inv_r_rcv_rcv_mux_ID_72_Pos_OffsetReference");
		snprintf(v[131], string_size, "inverters_inv_r_rcv_rcv_mux_ID_73_CAN_NBT");
		snprintf(v[132], string_size, "inverters_inv_r_rcv_rcv_mux_ID_74_Pos_Zero_Capture");
		snprintf(v[133], string_size, "inverters_inv_r_rcv_rcv_mux_ID_75_Pos_Ref_Reso_Edge");
		snprintf(v[134], string_size, "inverters_inv_r_rcv_rcv_mux_ID_76_Pos_Calib_Speed_1");
		snprintf(v[135], string_size, "inverters_inv_r_rcv_rcv_mux_ID_77_Pos_Calib_Speed_2");
		snprintf(v[136], string_size, "inverters_inv_r_rcv_rcv_mux_ID_79_Pos_Tol_Window");
		snprintf(v[137], string_size, "inverters_inv_r_rcv_rcv_mux_ID_7A_Pos_Preset_Value");
		snprintf(v[138], string_size, "inverters_inv_r_rcv_rcv_mux_ID_7B_Pos_Zero_Offset");
		snprintf(v[139], string_size, "inverters_inv_r_rcv_rcv_mux_ID_7C_Pos_NDrive_Scale");
		snprintf(v[140], string_size, "inverters_inv_r_rcv_rcv_mux_ID_7D_Pos_NDrive_Offset");
		snprintf(v[141], string_size, "inverters_inv_r_rcv_rcv_mux_ID_7E_Pos_FB2_Scale_Fac_Ext");
		snprintf(v[142], string_size, "inverters_inv_r_rcv_rcv_mux_ID_7F_Pos_Offset_Slack");
		snprintf(v[143], string_size, "inverters_inv_r_rcv_rcv_mux_ID_80_Pos_Diff_Slack");
		snprintf(v[144], string_size, "inverters_inv_r_rcv_rcv_mux_ID_83_Function_Parameter_Read");
		snprintf(v[145], string_size, "inverters_inv_r_rcv_rcv_mux_ID_84_Function_Parameter_Write");
		snprintf(v[146], string_size, "inverters_inv_r_rcv_rcv_mux_ID_85_Function_Special");
		snprintf(v[147], string_size, "inverters_inv_r_rcv_rcv_mux_ID_88_CAN_ID_2_Rx");
		snprintf(v[148], string_size, "inverters_inv_r_rcv_rcv_mux_ID_89_CAN_ID_2_Tx");
		snprintf(v[149], string_size, "inverters_inv_r_rcv_rcv_mux_ID_8B_VoltageControl_Ref");
		snprintf(v[150], string_size, "inverters_inv_r_rcv_rcv_mux_ID_8C_VoltageControl_Kp");
		snprintf(v[151], string_size, "inverters_inv_r_rcv_rcv_mux_ID_2D_PID_n_Ti");
		snprintf(v[152], string_size, "inverters_inv_r_rcv_rcv_mux_ID_8E_Clear_Error_List");
		snprintf(v[153], string_size, "inverters_inv_r_rcv_rcv_mux_ID_91_Pos_cmd_int");
		snprintf(v[154], string_size, "inverters_inv_r_rcv_rcv_mux_ID_92_CAN_Error_BusOff_cntr");
		snprintf(v[155], string_size, "inverters_inv_r_rcv_rcv_mux_ID_93_CAN_Error_WriteTime_cntr");
		snprintf(v[156], string_size, "inverters_inv_r_rcv_rcv_mux_ID_94_ECODE_1stError");
		snprintf(v[157], string_size, "inverters_inv_r_rcv_rcv_mux_ID_95_CAN_Error_NoAck_cntr");
		snprintf(v[158], string_size, "inverters_inv_r_rcv_rcv_mux_ID_96_CAN_Error_CRC_Check_cntr");
		snprintf(v[159], string_size, "inverters_inv_r_rcv_rcv_mux_ID_97_CAN_Error_Bit_cntr");
		snprintf(v[160], string_size, "inverters_inv_r_rcv_rcv_mux_ID_99_Info_Timer_Diff");
		snprintf(v[161], string_size, "inverters_inv_r_rcv_rcv_mux_ID_A1_Ballast_cntr");
		snprintf(v[162], string_size, "inverters_inv_r_rcv_rcv_mux_ID_A3_Motor_Temp_Error_Lim");
		snprintf(v[163], string_size, "inverters_inv_r_rcv_rcv_mux_ID_A4_Motor_Options");
		snprintf(v[164], string_size, "inverters_inv_r_rcv_rcv_mux_ID_A5_Device_DC_Bus_MinMax_Lim");
		snprintf(v[165], string_size, "inverters_inv_r_rcv_rcv_mux_ID_A6_FB_IncrementsPerRot");
		snprintf(v[166], string_size, "inverters_inv_r_rcv_rcv_mux_ID_A7_FB_Pole_Number");
		snprintf(v[167], string_size, "inverters_inv_r_rcv_rcv_mux_ID_AB_Logic_Frequency");
		snprintf(v[168], string_size, "inverters_inv_r_rcv_rcv_mux_ID_AC_PWM_1_56");
		snprintf(v[169], string_size, "inverters_inv_r_rcv_rcv_mux_ID_AD_PWM_2_34");
		snprintf(v[170], string_size, "inverters_inv_r_rcv_rcv_mux_ID_AE_PWM_3_12");
		snprintf(v[171], string_size, "inverters_inv_r_rcv_rcv_mux_ID_AF_Timer_Delta");
		snprintf(v[172], string_size, "inverters_inv_r_rcv_rcv_mux_ID_B1_Motor_L_Sigma_Q");
		snprintf(v[173], string_size, "inverters_inv_r_rcv_rcv_mux_ID_BB_Motor_L_Sigma_D");
		snprintf(v[174], string_size, "inverters_inv_r_rcv_rcv_mux_ID_B2_Id_Nominal");
		snprintf(v[175], string_size, "inverters_inv_r_rcv_rcv_mux_ID_B3_Motor_Magn_Inductance");
		snprintf(v[176], string_size, "inverters_inv_r_rcv_rcv_mux_ID_B4_Motor_Rotor_Resistance");
		snprintf(v[177], string_size, "inverters_inv_r_rcv_rcv_mux_ID_B5_Id_Minimum");
		snprintf(v[178], string_size, "inverters_inv_r_rcv_rcv_mux_ID_B6_Time_Constant_Rotor");
		snprintf(v[179], string_size, "inverters_inv_r_rcv_rcv_mux_ID_BC_Motor_Stator_Resistance");
		snprintf(v[180], string_size, "inverters_inv_r_rcv_rcv_mux_ID_BD_Time_Constant_Stator");
		snprintf(v[181], string_size, "inverters_inv_r_rcv_rcv_mux_ID_BE_LogicDefine_of_END_1");
		snprintf(v[182], string_size, "inverters_inv_r_rcv_rcv_mux_ID_BF_LogicDefine_of_END_2");
		snprintf(v[183], string_size, "inverters_inv_r_rcv_rcv_mux_ID_C0_LogicDefine_of_DIN_1");
		snprintf(v[184], string_size, "inverters_inv_r_rcv_rcv_mux_ID_C1_LogicDefine_of_DIN_2");
		snprintf(v[185], string_size, "inverters_inv_r_rcv_rcv_mux_ID_C2_LogicDefine_of_OUT_1");
		snprintf(v[186], string_size, "inverters_inv_r_rcv_rcv_mux_ID_24_I_Max_Inuse");
		snprintf(v[187], string_size, "inverters_inv_r_rcv_rcv_mux_ID_E3_DigSignal_GO");
		snprintf(v[188], string_size, "inverters_inv_r_rcv_rcv_mux_ID_F2_DigSignal_Brake");
		snprintf(v[189], string_size, "inverters_inv_r_rcv_rcv_mux_ID_F3_DigSignal_Icns");
		snprintf(v[190], string_size, "inverters_inv_r_rcv_rcv_mux_ID_F5_DigSignal_LessN0");
		snprintf(v[191], string_size, "inverters_inv_r_rcv_rcv_mux_ID_F4_DigSignal_Pos_Tolerance");
		snprintf(v[192], string_size, "inverters_inv_r_rcv_rcv_mux_ID_FB_Ain_in_1_Calc");
		snprintf(v[193], string_size, "inverters_inv_r_rcv_rcv_mux_ID_FC_Ain_in_2_Calc");
		snprintf(v[194], string_size, "inverters_inv_r_rcv_rcv_mux_ID_C3_LogicDefine_of_OUT_2");
		snprintf(v[195], string_size, "inverters_inv_r_rcv_rcv_mux_ID_DA_LogicDefine_of_OUT_3");
		snprintf(v[196], string_size, "inverters_inv_r_rcv_rcv_mux_ID_DB_LogicDefine_of_OUT_4");
		snprintf(v[197], string_size, "inverters_inv_r_rcv_rcv_mux_ID_C9_PID_I_xKp");
		snprintf(v[198], string_size, "inverters_inv_r_rcv_rcv_mux_ID_CA_Bat_Opr_Limits");
		snprintf(v[199], string_size, "inverters_inv_r_rcv_rcv_mux_ID_CB_PID_I_Kf");
		snprintf(v[200], string_size, "inverters_inv_r_rcv_rcv_mux_ID_CC_Car_Mode_Status");
		snprintf(v[201], string_size, "inverters_inv_r_rcv_rcv_mux_ID_CD_Car_Mode_Config");
		snprintf(v[202], string_size, "inverters_inv_r_rcv_rcv_mux_ID_CE_N_Rpm_MaxInt");
		snprintf(v[203], string_size, "inverters_inv_r_rcv_rcv_mux_ID_D1_Var_1");
		snprintf(v[204], string_size, "inverters_inv_r_rcv_rcv_mux_ID_D0_CAN_Timeout");
		snprintf(v[205], string_size, "inverters_inv_r_rcv_rcv_mux_ID_D2_Var_2");
		snprintf(v[206], string_size, "inverters_inv_r_rcv_rcv_mux_ID_D3_Var_3");
		snprintf(v[207], string_size, "inverters_inv_r_rcv_rcv_mux_ID_D4_Var_4");
		snprintf(v[208], string_size, "inverters_inv_r_rcv_rcv_mux_ID_DC_DAC_Source_ID");
		snprintf(v[209], string_size, "inverters_inv_r_rcv_rcv_mux_ID_EC_DigSignal_FB_LossOfSig");
		snprintf(v[210], string_size, "inverters_inv_r_rcv_rcv_mux_ID_EF_DigSignal_NoHWFault");
		snprintf(v[211], string_size, "inverters_inv_r_rcv_rcv_mux_ID_F0_Time_I_Peak");
		snprintf(v[212], string_size, "inverters_inv_r_rcv_rcv_mux_ID_F1_Brake_Delay");
		snprintf(v[213], string_size, "inverters_inv_r_rcv_rcv_mux_ID_F6_Inverter_Output_Power");
		snprintf(v[214], string_size, "inverters_inv_r_rcv_rcv_mux_ID_F7_Inverter_Output_Work");
		snprintf(v[215], string_size, "inverters_inv_r_rcv_rcv_mux_ID_0F_FU_Extra");
		snprintf(v[216], string_size, "inverters_inv_r_rcv_rcv_mux_ID_10_Oszi_Channel");
		snprintf(v[217], string_size, "inverters_inv_r_rcv_rcv_mux_ID_12_Oszi_Triger_Level");
		snprintf(v[218], string_size, "inverters_inv_r_rcv_rcv_mux_ID_13_Oszi_Triger_Edge");
		snprintf(v[219], string_size, "inverters_inv_r_rcv_rcv_mux_ID_14_Oszi_Triger_Source");
		snprintf(v[220], string_size, "inverters_inv_r_rcv_rcv_mux_ID_15_Oszi_Source");
		snprintf(v[221], string_size, "inverters_inv_r_rcv_rcv_mux_ID_16_Oszi_Skip");
		snprintf(v[222], string_size, "inverters_inv_r_rcv_rcv_mux_ID_18_Oszi_Run_cmd");
		snprintf(v[223], string_size, "inverters_inv_r_rcv_rcv_mux_ID_17_Oszi_Read_cmd");
		snprintf(v[224], string_size, "inverters_inv_r_rcv_rcv_mux_ID_78_Pos_Ref_Start");
		snprintf(v[225], string_size, "inverters_inv_r_rcv_rcv_mux_ID_66_DC_Bus_Voltage");
		snprintf(v[226], string_size, "inverters_inv_r_rcv_rcv_mux_ID_3A_M_cmd_ramp");
		snprintf(v[227], string_size, "inverters_inv_r_rcv_rcv_mux_ID_97_LogicOutBlock");
		snprintf(v[228], string_size, "inverters_inv_r_rcv_rcv_mux_ID_9B_LogicInBlock");
		snprintf(v[229], string_size, "inverters_inv_r_rcv_rcv_mux_ID_FE_FW_Subv_Revis_Nr");

		return 0;
	case 20:
		if(29 > fields_size) return 1;
		snprintf(v[0], string_size, "inverters_inv_r_rcv_def_end_1__Off_");
		snprintf(v[1], string_size, "inverters_inv_r_rcv_def_end_1_Ref_and_Limit_Plus");
		snprintf(v[2], string_size, "inverters_inv_r_rcv_def_end_1_Ref_and_Limit_Minus");
		snprintf(v[3], string_size, "inverters_inv_r_rcv_def_end_1_Ref_Plus");
		snprintf(v[4], string_size, "inverters_inv_r_rcv_def_end_1_Limit_Plus");
		snprintf(v[5], string_size, "inverters_inv_r_rcv_def_end_1_Limit_Minus");
		snprintf(v[6], string_size, "inverters_inv_r_rcv_def_end_1_Limit_Plus_and_Minus");
		snprintf(v[7], string_size, "inverters_inv_r_rcv_def_end_1_Cancel_Error_s_");
		snprintf(v[8], string_size, "inverters_inv_r_rcv_def_end_1__Start_Ref_Drive");
		snprintf(v[9], string_size, "inverters_inv_r_rcv_def_end_1_Speed_Ramp_0");
		snprintf(v[10], string_size, "inverters_inv_r_rcv_def_end_1__Start_Dest_eq_Var_1");
		snprintf(v[11], string_size, "inverters_inv_r_rcv_def_end_1__Start_Dest_eq_Var_2");
		snprintf(v[12], string_size, "inverters_inv_r_rcv_def_end_1_N_cmd_Reverse");
		snprintf(v[13], string_size, "inverters_inv_r_rcv_def_end_1__Preset_Pos_eq_Var_3");
		snprintf(v[14], string_size, "inverters_inv_r_rcv_def_end_1__Capture_Var_3_eq_Pos");
		snprintf(v[15], string_size, "inverters_inv_r_rcv_def_end_1__Capture_Var_4_eq_Pos");
		snprintf(v[16], string_size, "inverters_inv_r_rcv_def_end_1__Switch_Spd_eq_notAin1_Ain2");
		snprintf(v[17], string_size, "inverters_inv_r_rcv_def_end_1__Switch_Spd_eq_notVar1_Var2");
		snprintf(v[18], string_size, "inverters_inv_r_rcv_def_end_1_I_limit_dig_");
		snprintf(v[19], string_size, "inverters_inv_r_rcv_def_end_1_N_clip_neg_pos_");
		snprintf(v[20], string_size, "inverters_inv_r_rcv_def_end_1__Switch_Cmd_eq_notDig_Ana");
		snprintf(v[21], string_size, "inverters_inv_r_rcv_def_end_1_Speed_Ramp_0_Pos");
		snprintf(v[22], string_size, "inverters_inv_r_rcv_def_end_1_Handwheel");
		snprintf(v[23], string_size, "inverters_inv_r_rcv_def_end_1_Brake_Car");
		snprintf(v[24], string_size, "inverters_inv_r_rcv_def_end_1_Recup_Disabled");
		snprintf(v[25], string_size, "inverters_inv_r_rcv_def_end_1_Rising_Bank_1_Falling_Bank_0");
		snprintf(v[26], string_size, "inverters_inv_r_rcv_def_end_1__Start_Dest_eq_Var_1_2_3_4");
		snprintf(v[27], string_size, "inverters_inv_r_rcv_def_end_1__Start_CW_eq_Var_1_2_3_4");
		snprintf(v[28], string_size, "inverters_inv_r_rcv_def_end_1_Brake_Car_Nr2");

		return 0;
	case 21:
		if(29 > fields_size) return 1;
		snprintf(v[0], string_size, "inverters_inv_r_rcv_def_din_1__Off_");
		snprintf(v[1], string_size, "inverters_inv_r_rcv_def_din_1_Ref_and_Limit_Plus");
		snprintf(v[2], string_size, "inverters_inv_r_rcv_def_din_1_Ref_and_Limit_Minus");
		snprintf(v[3], string_size, "inverters_inv_r_rcv_def_din_1_Ref_Plus");
		snprintf(v[4], string_size, "inverters_inv_r_rcv_def_din_1_Limit_Plus");
		snprintf(v[5], string_size, "inverters_inv_r_rcv_def_din_1_Limit_Minus");
		snprintf(v[6], string_size, "inverters_inv_r_rcv_def_din_1_Limit_Plus_and_Minus");
		snprintf(v[7], string_size, "inverters_inv_r_rcv_def_din_1_Cancel_Error_s_");
		snprintf(v[8], string_size, "inverters_inv_r_rcv_def_din_1__Start_Ref_Drive");
		snprintf(v[9], string_size, "inverters_inv_r_rcv_def_din_1_Speed_Ramp_0");
		snprintf(v[10], string_size, "inverters_inv_r_rcv_def_din_1__Start_Dest_eq_Var_1");
		snprintf(v[11], string_size, "inverters_inv_r_rcv_def_din_1__Start_Dest_eq_Var_2");
		snprintf(v[12], string_size, "inverters_inv_r_rcv_def_din_1_N_cmd_Reverse");
		snprintf(v[13], string_size, "inverters_inv_r_rcv_def_din_1__Preset_Pos_eq_Var_3");
		snprintf(v[14], string_size, "inverters_inv_r_rcv_def_din_1__Capture_Var_3_eq_Pos");
		snprintf(v[15], string_size, "inverters_inv_r_rcv_def_din_1__Capture_Var_4_eq_Pos");
		snprintf(v[16], string_size, "inverters_inv_r_rcv_def_din_1__Switch_Spd_eq_notAin1_Ain2");
		snprintf(v[17], string_size, "inverters_inv_r_rcv_def_din_1__Switch_Spd_eq_notVar1_Var2");
		snprintf(v[18], string_size, "inverters_inv_r_rcv_def_din_1_I_limit_dig_");
		snprintf(v[19], string_size, "inverters_inv_r_rcv_def_din_1_N_clip_neg_pos_");
		snprintf(v[20], string_size, "inverters_inv_r_rcv_def_din_1__Switch_Cmd_eq_notDig_Ana");
		snprintf(v[21], string_size, "inverters_inv_r_rcv_def_din_1_Speed_Ramp_0_Pos");
		snprintf(v[22], string_size, "inverters_inv_r_rcv_def_din_1_Handwheel");
		snprintf(v[23], string_size, "inverters_inv_r_rcv_def_din_1_Brake_Car");
		snprintf(v[24], string_size, "inverters_inv_r_rcv_def_din_1_Recup_Disabled");
		snprintf(v[25], string_size, "inverters_inv_r_rcv_def_din_1_Rising_Bank_1_Falling_Bank_0");
		snprintf(v[26], string_size, "inverters_inv_r_rcv_def_din_1__Start_Dest_eq_Var_1_2_3_4");
		snprintf(v[27], string_size, "inverters_inv_r_rcv_def_din_1__Start_CW_eq_Var_1_2_3_4");
		snprintf(v[28], string_size, "inverters_inv_r_rcv_def_din_1_Brake_Car_Nr2");

		return 0;
	case 22:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "inverters_inv_r_rcv_active190_Low");
		snprintf(v[1], string_size, "inverters_inv_r_rcv_active190_High");

		return 0;
	case 23:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "inverters_inv_r_rcv_active192_Low");
		snprintf(v[1], string_size, "inverters_inv_r_rcv_active192_High");

		return 0;

    }
    return 0;
}
int inverters_serialize_from_id(int id, char *s, uint8_t *data, size_t *size)
{
    switch(id)
    {
	case 513:
	{
		inverters_inv_l_send_t tmp;
		inverters_inv_l_send_converted_t tmp_converted;
		uint8_t r_send_mux;
		uint8_t r_read_id;
		uint8_t r_km_rsvd_0;
		float r_m_setdig__iq;
		uint16_t r_def_din_1;
		uint16_t r_def_end_1;
		float r_i_max_pk;
		float r_i_con_eff;
		float r_i_device;
		uint16_t r_n_r_lim;
		int16_t r_nmax100perc;
		uint8_t r_km_speed_0;
		uint8_t r_km_frg_off;
		uint8_t r_km_cal_off;
		uint8_t r_km_tx_tog_stat;
		uint8_t r_km_i_limit;
		uint8_t r_km_n_clip;
		uint8_t r_km_mix_ana_on;
		uint8_t r_ret_interval;
		uint8_t r_km_allow_sync;
		uint8_t r_km_handwheel;
		uint8_t r_km_phasing_extend;
		uint8_t r_km_rsvd_11;
		uint8_t r_km_rsvd_12;
		uint8_t r_km_rsvd_13;
		uint8_t r_km_pseudo_enable;
		uint8_t r_km_debug_test;
		uint8_t r_active192;
		uint8_t r_active190;
		uint16_t r_m_r_rcp;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%f,"       
			"%" SCNu16 "," 
			"%" SCNu16 "," 
			"%f,"       
			"%f,"       
			"%f,"       
			"%" SCNu16 "," 
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
			"%" SCNu16 "," ,
			&r_send_mux,
			&r_read_id,
			&r_km_rsvd_0,
			&r_m_setdig__iq,
			&r_def_din_1,
			&r_def_end_1,
			&r_i_max_pk,
			&r_i_con_eff,
			&r_i_device,
			&r_n_r_lim,
			&r_nmax100perc,
			&r_km_speed_0,
			&r_km_frg_off,
			&r_km_cal_off,
			&r_km_tx_tog_stat,
			&r_km_i_limit,
			&r_km_n_clip,
			&r_km_mix_ana_on,
			&r_ret_interval,
			&r_km_allow_sync,
			&r_km_handwheel,
			&r_km_phasing_extend,
			&r_km_rsvd_11,
			&r_km_rsvd_12,
			&r_km_rsvd_13,
			&r_km_pseudo_enable,
			&r_km_debug_test,
			&r_active192,
			&r_active190,
			&r_m_r_rcp);
		tmp_converted.send_mux = (inverters_inv_l_send_send_mux)r_send_mux;
		tmp_converted.read_id = (inverters_inv_l_send_read_id)r_read_id;
		tmp_converted.km_rsvd_0 = (uint8_t)r_km_rsvd_0;
		tmp_converted.m_setdig__iq = (float)r_m_setdig__iq;
		tmp_converted.def_din_1 = (inverters_inv_l_send_def_din_1)r_def_din_1;
		tmp_converted.def_end_1 = (inverters_inv_l_send_def_end_1)r_def_end_1;
		tmp_converted.i_max_pk = (float)r_i_max_pk;
		tmp_converted.i_con_eff = (float)r_i_con_eff;
		tmp_converted.i_device = (float)r_i_device;
		tmp_converted.n_r_lim = (uint16_t)r_n_r_lim;
		tmp_converted.nmax100perc = (int16_t)r_nmax100perc;
		tmp_converted.km_speed_0 = (uint8_t)r_km_speed_0;
		tmp_converted.km_frg_off = (uint8_t)r_km_frg_off;
		tmp_converted.km_cal_off = (uint8_t)r_km_cal_off;
		tmp_converted.km_tx_tog_stat = (uint8_t)r_km_tx_tog_stat;
		tmp_converted.km_i_limit = (uint8_t)r_km_i_limit;
		tmp_converted.km_n_clip = (uint8_t)r_km_n_clip;
		tmp_converted.km_mix_ana_on = (uint8_t)r_km_mix_ana_on;
		tmp_converted.ret_interval = (inverters_inv_l_send_ret_interval)r_ret_interval;
		tmp_converted.km_allow_sync = (uint8_t)r_km_allow_sync;
		tmp_converted.km_handwheel = (uint8_t)r_km_handwheel;
		tmp_converted.km_phasing_extend = (uint8_t)r_km_phasing_extend;
		tmp_converted.km_rsvd_11 = (uint8_t)r_km_rsvd_11;
		tmp_converted.km_rsvd_12 = (uint8_t)r_km_rsvd_12;
		tmp_converted.km_rsvd_13 = (uint8_t)r_km_rsvd_13;
		tmp_converted.km_pseudo_enable = (uint8_t)r_km_pseudo_enable;
		tmp_converted.km_debug_test = (uint8_t)r_km_debug_test;
		tmp_converted.active192 = (inverters_inv_l_send_active192)r_active192;
		tmp_converted.active190 = (inverters_inv_l_send_active190)r_active190;
		tmp_converted.m_r_rcp = (uint16_t)r_m_r_rcp;

		inverters_inv_l_send_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = INVERTERS_INV_L_SEND_BYTE_SIZE;
		return inverters_inv_l_send_pack(data, &tmp, INVERTERS_INV_L_SEND_BYTE_SIZE);
	}
	case 385:
	{
		inverters_inv_l_rcv_t tmp;
		inverters_inv_l_rcv_converted_t tmp_converted;
		uint8_t r_rcv_mux;
		float r_n_actual_filt;
		uint8_t r_ena64;
		uint8_t r_err_badparas;
		uint16_t r_def_end_1;
		uint8_t r_lmt_active_1;
		float r_i_cmd;
		float r_i_cmd_ramp;
		float r_iq_actual;
		uint16_t r_t_motor;
		uint16_t r_t_igbt;
		float r_vdc_bus_filt;
		uint8_t r_km_rsvd_0;
		uint8_t r_ena82;
		uint16_t r_def_din_1;
		int16_t r_m_cmd_ramp;
		float r_i_max_pk;
		float r_i_con_eff;
		float r_i_device;
		uint16_t r_n_r_lim;
		int16_t r_nmax100perc;
		uint8_t r_ncr064;
		uint8_t r_err_powerfault;
		uint8_t r_lmt_active_2;
		uint8_t r_km_speed_0;
		uint8_t r_ncr082;
		uint8_t r_lim_plus64;
		uint8_t r_err_rfe_fault;
		uint8_t r_in_active_2;
		uint8_t r_km_frg_off;
		uint8_t r_lim_plus82;
		uint8_t r_lim_minus64;
		uint8_t r_err_bustimeout;
		uint8_t r_in_active_1;
		uint8_t r_km_cal_off;
		uint8_t r_lim_minus82;
		uint8_t r_ok64;
		uint8_t r_err_feedbacksignal;
		uint8_t r_frgrun;
		uint8_t r_km_tx_tog_stat;
		uint8_t r_ok82;
		uint8_t r_icns64;
		uint8_t r_err_powervoltage_low;
		uint8_t r_rfe216;
		uint8_t r_km_i_limit;
		uint8_t r_icns82;
		uint8_t r_tnlim64;
		uint8_t r_err_motortemp;
		uint8_t r_km_n_clip;
		uint8_t r_tnlim82;
		uint8_t r_pn64;
		uint8_t r_err_devicetemp;
		uint8_t r_km_mix_ana_on;
		uint8_t r_pn82;
		uint8_t r_ni64;
		uint8_t r_err_overvoltage;
		uint8_t r_d_out_1_on;
		uint8_t r_km_allow_sync;
		uint8_t r_ni82;
		uint8_t r__n064;
		uint8_t r_err_ipeak;
		uint8_t r_d_out_2_on;
		uint8_t r_km_handwheel;
		uint8_t r__n082;
		uint8_t r_rsw64;
		uint8_t r_err_raceaway;
		uint8_t r_btbrdy;
		uint8_t r_km_phasing_extend;
		uint8_t r_rsw82;
		uint8_t r_cal064;
		uint8_t r_err_user;
		uint8_t r_go216;
		uint8_t r_km_rsvd_11;
		uint8_t r_cal082;
		uint8_t r_cal64;
		uint8_t r_d_out_3_on;
		uint8_t r_km_rsvd_12;
		uint8_t r_cal82;
		uint8_t r_tol64;
		uint8_t r_d_out_4_on;
		uint8_t r_km_rsvd_13;
		uint8_t r_tol82;
		uint8_t r_rdy64;
		uint8_t r_err_hwerr;
		uint8_t r_goff;
		uint8_t r_km_pseudo_enable;
		uint8_t r_rdy82;
		uint8_t r_brk064;
		uint8_t r_err_ballast;
		uint8_t r_active190;
		uint8_t r_brk1216;
		uint8_t r_km_debug_test;
		uint8_t r_brk082;
		uint8_t r_active192;
		uint8_t r_signmag64;
		uint8_t r_warn_warning_0;
		uint8_t r_signmag82;
		int16_t r_free;
		uint16_t r_m_r_rcp;
		uint8_t r_nclip64;
		uint8_t r_warn_illegal_status;
		uint8_t r_nclip82;
		uint8_t r_nclip_minus64;
		uint8_t r_warn_safe_in;
		uint8_t r_nclip_minus82;
		uint8_t r_nclip_plus64;
		uint8_t r_nclip_plus82;
		uint8_t r_irddig64;
		uint8_t r_irddig82;
		uint8_t r_iuserchd64;
		uint8_t r_iuserchd82;
		uint8_t r_irdn64;
		uint8_t r_warn_motortemp;
		uint8_t r_irdn82;
		uint8_t r_irdti64;
		uint8_t r_warn_devicetemp;
		uint8_t r_irdti82;
		uint8_t r_irdtir64;
		uint8_t r_warn_vout_sat;
		uint8_t r_irdtir82;
		uint8_t r__10hz64;
		uint8_t r_warn_ipeak;
		uint8_t r__10hz82;
		uint8_t r_irdtm64;
		uint8_t r_warn_raceaway;
		uint8_t r_irdtm82;
		uint8_t r_irdana64;
		uint8_t r_irdana82;
		uint8_t r_iwcns64;
		uint8_t r_iwcns82;
		uint8_t r_rfepulse64;
		uint8_t r_rfepulse82;
		uint8_t r_md64;
		uint8_t r_md82;
		uint8_t r_hndwhl64;
		uint8_t r_warn_ballast;
		uint8_t r_hndwhl82;

		sscanf(s, "%" SCNu8 ","  
			"%f,"       
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu16 "," 
			"%" SCNu8 ","  
			"%f,"       
			"%f,"       
			"%f,"       
			"%" SCNu16 "," 
			"%" SCNu16 "," 
			"%f,"       
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu16 "," 
			"%" SCNi16 "," 
			"%f,"       
			"%f,"       
			"%f,"       
			"%" SCNu16 "," 
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
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNi16 "," 
			"%" SCNu16 "," 
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
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
			&r_rcv_mux,
			&r_n_actual_filt,
			&r_ena64,
			&r_err_badparas,
			&r_def_end_1,
			&r_lmt_active_1,
			&r_i_cmd,
			&r_i_cmd_ramp,
			&r_iq_actual,
			&r_t_motor,
			&r_t_igbt,
			&r_vdc_bus_filt,
			&r_km_rsvd_0,
			&r_ena82,
			&r_def_din_1,
			&r_m_cmd_ramp,
			&r_i_max_pk,
			&r_i_con_eff,
			&r_i_device,
			&r_n_r_lim,
			&r_nmax100perc,
			&r_ncr064,
			&r_err_powerfault,
			&r_lmt_active_2,
			&r_km_speed_0,
			&r_ncr082,
			&r_lim_plus64,
			&r_err_rfe_fault,
			&r_in_active_2,
			&r_km_frg_off,
			&r_lim_plus82,
			&r_lim_minus64,
			&r_err_bustimeout,
			&r_in_active_1,
			&r_km_cal_off,
			&r_lim_minus82,
			&r_ok64,
			&r_err_feedbacksignal,
			&r_frgrun,
			&r_km_tx_tog_stat,
			&r_ok82,
			&r_icns64,
			&r_err_powervoltage_low,
			&r_rfe216,
			&r_km_i_limit,
			&r_icns82,
			&r_tnlim64,
			&r_err_motortemp,
			&r_km_n_clip,
			&r_tnlim82,
			&r_pn64,
			&r_err_devicetemp,
			&r_km_mix_ana_on,
			&r_pn82,
			&r_ni64,
			&r_err_overvoltage,
			&r_d_out_1_on,
			&r_km_allow_sync,
			&r_ni82,
			&r__n064,
			&r_err_ipeak,
			&r_d_out_2_on,
			&r_km_handwheel,
			&r__n082,
			&r_rsw64,
			&r_err_raceaway,
			&r_btbrdy,
			&r_km_phasing_extend,
			&r_rsw82,
			&r_cal064,
			&r_err_user,
			&r_go216,
			&r_km_rsvd_11,
			&r_cal082,
			&r_cal64,
			&r_d_out_3_on,
			&r_km_rsvd_12,
			&r_cal82,
			&r_tol64,
			&r_d_out_4_on,
			&r_km_rsvd_13,
			&r_tol82,
			&r_rdy64,
			&r_err_hwerr,
			&r_goff,
			&r_km_pseudo_enable,
			&r_rdy82,
			&r_brk064,
			&r_err_ballast,
			&r_active190,
			&r_brk1216,
			&r_km_debug_test,
			&r_brk082,
			&r_active192,
			&r_signmag64,
			&r_warn_warning_0,
			&r_signmag82,
			&r_free,
			&r_m_r_rcp,
			&r_nclip64,
			&r_warn_illegal_status,
			&r_nclip82,
			&r_nclip_minus64,
			&r_warn_safe_in,
			&r_nclip_minus82,
			&r_nclip_plus64,
			&r_nclip_plus82,
			&r_irddig64,
			&r_irddig82,
			&r_iuserchd64,
			&r_iuserchd82,
			&r_irdn64,
			&r_warn_motortemp,
			&r_irdn82,
			&r_irdti64,
			&r_warn_devicetemp,
			&r_irdti82,
			&r_irdtir64,
			&r_warn_vout_sat,
			&r_irdtir82,
			&r__10hz64,
			&r_warn_ipeak,
			&r__10hz82,
			&r_irdtm64,
			&r_warn_raceaway,
			&r_irdtm82,
			&r_irdana64,
			&r_irdana82,
			&r_iwcns64,
			&r_iwcns82,
			&r_rfepulse64,
			&r_rfepulse82,
			&r_md64,
			&r_md82,
			&r_hndwhl64,
			&r_warn_ballast,
			&r_hndwhl82);
		tmp_converted.rcv_mux = (inverters_inv_l_rcv_rcv_mux)r_rcv_mux;
		tmp_converted.n_actual_filt = (float)r_n_actual_filt;
		tmp_converted.ena64 = (uint8_t)r_ena64;
		tmp_converted.err_badparas = (uint8_t)r_err_badparas;
		tmp_converted.def_end_1 = (inverters_inv_l_rcv_def_end_1)r_def_end_1;
		tmp_converted.lmt_active_1 = (uint8_t)r_lmt_active_1;
		tmp_converted.i_cmd = (float)r_i_cmd;
		tmp_converted.i_cmd_ramp = (float)r_i_cmd_ramp;
		tmp_converted.iq_actual = (float)r_iq_actual;
		tmp_converted.t_motor = (uint16_t)r_t_motor;
		tmp_converted.t_igbt = (uint16_t)r_t_igbt;
		tmp_converted.vdc_bus_filt = (float)r_vdc_bus_filt;
		tmp_converted.km_rsvd_0 = (uint8_t)r_km_rsvd_0;
		tmp_converted.ena82 = (uint8_t)r_ena82;
		tmp_converted.def_din_1 = (inverters_inv_l_rcv_def_din_1)r_def_din_1;
		tmp_converted.m_cmd_ramp = (int16_t)r_m_cmd_ramp;
		tmp_converted.i_max_pk = (float)r_i_max_pk;
		tmp_converted.i_con_eff = (float)r_i_con_eff;
		tmp_converted.i_device = (float)r_i_device;
		tmp_converted.n_r_lim = (uint16_t)r_n_r_lim;
		tmp_converted.nmax100perc = (int16_t)r_nmax100perc;
		tmp_converted.ncr064 = (uint8_t)r_ncr064;
		tmp_converted.err_powerfault = (uint8_t)r_err_powerfault;
		tmp_converted.lmt_active_2 = (uint8_t)r_lmt_active_2;
		tmp_converted.km_speed_0 = (uint8_t)r_km_speed_0;
		tmp_converted.ncr082 = (uint8_t)r_ncr082;
		tmp_converted.lim_plus64 = (uint8_t)r_lim_plus64;
		tmp_converted.err_rfe_fault = (uint8_t)r_err_rfe_fault;
		tmp_converted.in_active_2 = (uint8_t)r_in_active_2;
		tmp_converted.km_frg_off = (uint8_t)r_km_frg_off;
		tmp_converted.lim_plus82 = (uint8_t)r_lim_plus82;
		tmp_converted.lim_minus64 = (uint8_t)r_lim_minus64;
		tmp_converted.err_bustimeout = (uint8_t)r_err_bustimeout;
		tmp_converted.in_active_1 = (uint8_t)r_in_active_1;
		tmp_converted.km_cal_off = (uint8_t)r_km_cal_off;
		tmp_converted.lim_minus82 = (uint8_t)r_lim_minus82;
		tmp_converted.ok64 = (uint8_t)r_ok64;
		tmp_converted.err_feedbacksignal = (uint8_t)r_err_feedbacksignal;
		tmp_converted.frgrun = (uint8_t)r_frgrun;
		tmp_converted.km_tx_tog_stat = (uint8_t)r_km_tx_tog_stat;
		tmp_converted.ok82 = (uint8_t)r_ok82;
		tmp_converted.icns64 = (uint8_t)r_icns64;
		tmp_converted.err_powervoltage_low = (uint8_t)r_err_powervoltage_low;
		tmp_converted.rfe216 = (uint8_t)r_rfe216;
		tmp_converted.km_i_limit = (uint8_t)r_km_i_limit;
		tmp_converted.icns82 = (uint8_t)r_icns82;
		tmp_converted.tnlim64 = (uint8_t)r_tnlim64;
		tmp_converted.err_motortemp = (uint8_t)r_err_motortemp;
		tmp_converted.km_n_clip = (uint8_t)r_km_n_clip;
		tmp_converted.tnlim82 = (uint8_t)r_tnlim82;
		tmp_converted.pn64 = (uint8_t)r_pn64;
		tmp_converted.err_devicetemp = (uint8_t)r_err_devicetemp;
		tmp_converted.km_mix_ana_on = (uint8_t)r_km_mix_ana_on;
		tmp_converted.pn82 = (uint8_t)r_pn82;
		tmp_converted.ni64 = (uint8_t)r_ni64;
		tmp_converted.err_overvoltage = (uint8_t)r_err_overvoltage;
		tmp_converted.d_out_1_on = (uint8_t)r_d_out_1_on;
		tmp_converted.km_allow_sync = (uint8_t)r_km_allow_sync;
		tmp_converted.ni82 = (uint8_t)r_ni82;
		tmp_converted._n064 = (uint8_t)r__n064;
		tmp_converted.err_ipeak = (uint8_t)r_err_ipeak;
		tmp_converted.d_out_2_on = (uint8_t)r_d_out_2_on;
		tmp_converted.km_handwheel = (uint8_t)r_km_handwheel;
		tmp_converted._n082 = (uint8_t)r__n082;
		tmp_converted.rsw64 = (uint8_t)r_rsw64;
		tmp_converted.err_raceaway = (uint8_t)r_err_raceaway;
		tmp_converted.btbrdy = (uint8_t)r_btbrdy;
		tmp_converted.km_phasing_extend = (uint8_t)r_km_phasing_extend;
		tmp_converted.rsw82 = (uint8_t)r_rsw82;
		tmp_converted.cal064 = (uint8_t)r_cal064;
		tmp_converted.err_user = (uint8_t)r_err_user;
		tmp_converted.go216 = (uint8_t)r_go216;
		tmp_converted.km_rsvd_11 = (uint8_t)r_km_rsvd_11;
		tmp_converted.cal082 = (uint8_t)r_cal082;
		tmp_converted.cal64 = (uint8_t)r_cal64;
		tmp_converted.d_out_3_on = (uint8_t)r_d_out_3_on;
		tmp_converted.km_rsvd_12 = (uint8_t)r_km_rsvd_12;
		tmp_converted.cal82 = (uint8_t)r_cal82;
		tmp_converted.tol64 = (uint8_t)r_tol64;
		tmp_converted.d_out_4_on = (uint8_t)r_d_out_4_on;
		tmp_converted.km_rsvd_13 = (uint8_t)r_km_rsvd_13;
		tmp_converted.tol82 = (uint8_t)r_tol82;
		tmp_converted.rdy64 = (uint8_t)r_rdy64;
		tmp_converted.err_hwerr = (uint8_t)r_err_hwerr;
		tmp_converted.goff = (uint8_t)r_goff;
		tmp_converted.km_pseudo_enable = (uint8_t)r_km_pseudo_enable;
		tmp_converted.rdy82 = (uint8_t)r_rdy82;
		tmp_converted.brk064 = (uint8_t)r_brk064;
		tmp_converted.err_ballast = (uint8_t)r_err_ballast;
		tmp_converted.active190 = (inverters_inv_l_rcv_active190)r_active190;
		tmp_converted.brk1216 = (uint8_t)r_brk1216;
		tmp_converted.km_debug_test = (uint8_t)r_km_debug_test;
		tmp_converted.brk082 = (uint8_t)r_brk082;
		tmp_converted.active192 = (inverters_inv_l_rcv_active192)r_active192;
		tmp_converted.signmag64 = (uint8_t)r_signmag64;
		tmp_converted.warn_warning_0 = (uint8_t)r_warn_warning_0;
		tmp_converted.signmag82 = (uint8_t)r_signmag82;
		tmp_converted.free = (int16_t)r_free;
		tmp_converted.m_r_rcp = (uint16_t)r_m_r_rcp;
		tmp_converted.nclip64 = (uint8_t)r_nclip64;
		tmp_converted.warn_illegal_status = (uint8_t)r_warn_illegal_status;
		tmp_converted.nclip82 = (uint8_t)r_nclip82;
		tmp_converted.nclip_minus64 = (uint8_t)r_nclip_minus64;
		tmp_converted.warn_safe_in = (uint8_t)r_warn_safe_in;
		tmp_converted.nclip_minus82 = (uint8_t)r_nclip_minus82;
		tmp_converted.nclip_plus64 = (uint8_t)r_nclip_plus64;
		tmp_converted.nclip_plus82 = (uint8_t)r_nclip_plus82;
		tmp_converted.irddig64 = (uint8_t)r_irddig64;
		tmp_converted.irddig82 = (uint8_t)r_irddig82;
		tmp_converted.iuserchd64 = (uint8_t)r_iuserchd64;
		tmp_converted.iuserchd82 = (uint8_t)r_iuserchd82;
		tmp_converted.irdn64 = (uint8_t)r_irdn64;
		tmp_converted.warn_motortemp = (uint8_t)r_warn_motortemp;
		tmp_converted.irdn82 = (uint8_t)r_irdn82;
		tmp_converted.irdti64 = (uint8_t)r_irdti64;
		tmp_converted.warn_devicetemp = (uint8_t)r_warn_devicetemp;
		tmp_converted.irdti82 = (uint8_t)r_irdti82;
		tmp_converted.irdtir64 = (uint8_t)r_irdtir64;
		tmp_converted.warn_vout_sat = (uint8_t)r_warn_vout_sat;
		tmp_converted.irdtir82 = (uint8_t)r_irdtir82;
		tmp_converted._10hz64 = (uint8_t)r__10hz64;
		tmp_converted.warn_ipeak = (uint8_t)r_warn_ipeak;
		tmp_converted._10hz82 = (uint8_t)r__10hz82;
		tmp_converted.irdtm64 = (uint8_t)r_irdtm64;
		tmp_converted.warn_raceaway = (uint8_t)r_warn_raceaway;
		tmp_converted.irdtm82 = (uint8_t)r_irdtm82;
		tmp_converted.irdana64 = (uint8_t)r_irdana64;
		tmp_converted.irdana82 = (uint8_t)r_irdana82;
		tmp_converted.iwcns64 = (uint8_t)r_iwcns64;
		tmp_converted.iwcns82 = (uint8_t)r_iwcns82;
		tmp_converted.rfepulse64 = (uint8_t)r_rfepulse64;
		tmp_converted.rfepulse82 = (uint8_t)r_rfepulse82;
		tmp_converted.md64 = (uint8_t)r_md64;
		tmp_converted.md82 = (uint8_t)r_md82;
		tmp_converted.hndwhl64 = (uint8_t)r_hndwhl64;
		tmp_converted.warn_ballast = (uint8_t)r_warn_ballast;
		tmp_converted.hndwhl82 = (uint8_t)r_hndwhl82;

		inverters_inv_l_rcv_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = INVERTERS_INV_L_RCV_BYTE_SIZE;
		return inverters_inv_l_rcv_pack(data, &tmp, INVERTERS_INV_L_RCV_BYTE_SIZE);
	}
	case 514:
	{
		inverters_inv_r_send_t tmp;
		inverters_inv_r_send_converted_t tmp_converted;
		uint8_t r_send_mux;
		uint8_t r_read_id;
		uint8_t r_km_rsvd_0;
		float r_m_setdig__iq;
		uint16_t r_def_din_1;
		uint16_t r_def_end_1;
		float r_i_max_pk;
		float r_i_con_eff;
		float r_i_device;
		uint16_t r_n_r_lim;
		int16_t r_nmax100perc;
		uint8_t r_km_speed_0;
		uint8_t r_km_frg_off;
		uint8_t r_km_cal_off;
		uint8_t r_km_tx_tog_stat;
		uint8_t r_km_i_limit;
		uint8_t r_km_n_clip;
		uint8_t r_km_mix_ana_on;
		uint8_t r_ret_interval;
		uint8_t r_km_allow_sync;
		uint8_t r_km_handwheel;
		uint8_t r_km_phasing_extend;
		uint8_t r_km_rsvd_11;
		uint8_t r_km_rsvd_12;
		uint8_t r_km_rsvd_13;
		uint8_t r_km_pseudo_enable;
		uint8_t r_km_debug_test;
		uint8_t r_active192;
		uint8_t r_active190;
		uint16_t r_m_r_rcp;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%f,"       
			"%" SCNu16 "," 
			"%" SCNu16 "," 
			"%f,"       
			"%f,"       
			"%f,"       
			"%" SCNu16 "," 
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
			"%" SCNu16 "," ,
			&r_send_mux,
			&r_read_id,
			&r_km_rsvd_0,
			&r_m_setdig__iq,
			&r_def_din_1,
			&r_def_end_1,
			&r_i_max_pk,
			&r_i_con_eff,
			&r_i_device,
			&r_n_r_lim,
			&r_nmax100perc,
			&r_km_speed_0,
			&r_km_frg_off,
			&r_km_cal_off,
			&r_km_tx_tog_stat,
			&r_km_i_limit,
			&r_km_n_clip,
			&r_km_mix_ana_on,
			&r_ret_interval,
			&r_km_allow_sync,
			&r_km_handwheel,
			&r_km_phasing_extend,
			&r_km_rsvd_11,
			&r_km_rsvd_12,
			&r_km_rsvd_13,
			&r_km_pseudo_enable,
			&r_km_debug_test,
			&r_active192,
			&r_active190,
			&r_m_r_rcp);
		tmp_converted.send_mux = (inverters_inv_r_send_send_mux)r_send_mux;
		tmp_converted.read_id = (inverters_inv_r_send_read_id)r_read_id;
		tmp_converted.km_rsvd_0 = (uint8_t)r_km_rsvd_0;
		tmp_converted.m_setdig__iq = (float)r_m_setdig__iq;
		tmp_converted.def_din_1 = (inverters_inv_r_send_def_din_1)r_def_din_1;
		tmp_converted.def_end_1 = (inverters_inv_r_send_def_end_1)r_def_end_1;
		tmp_converted.i_max_pk = (float)r_i_max_pk;
		tmp_converted.i_con_eff = (float)r_i_con_eff;
		tmp_converted.i_device = (float)r_i_device;
		tmp_converted.n_r_lim = (uint16_t)r_n_r_lim;
		tmp_converted.nmax100perc = (int16_t)r_nmax100perc;
		tmp_converted.km_speed_0 = (uint8_t)r_km_speed_0;
		tmp_converted.km_frg_off = (uint8_t)r_km_frg_off;
		tmp_converted.km_cal_off = (uint8_t)r_km_cal_off;
		tmp_converted.km_tx_tog_stat = (uint8_t)r_km_tx_tog_stat;
		tmp_converted.km_i_limit = (uint8_t)r_km_i_limit;
		tmp_converted.km_n_clip = (uint8_t)r_km_n_clip;
		tmp_converted.km_mix_ana_on = (uint8_t)r_km_mix_ana_on;
		tmp_converted.ret_interval = (inverters_inv_r_send_ret_interval)r_ret_interval;
		tmp_converted.km_allow_sync = (uint8_t)r_km_allow_sync;
		tmp_converted.km_handwheel = (uint8_t)r_km_handwheel;
		tmp_converted.km_phasing_extend = (uint8_t)r_km_phasing_extend;
		tmp_converted.km_rsvd_11 = (uint8_t)r_km_rsvd_11;
		tmp_converted.km_rsvd_12 = (uint8_t)r_km_rsvd_12;
		tmp_converted.km_rsvd_13 = (uint8_t)r_km_rsvd_13;
		tmp_converted.km_pseudo_enable = (uint8_t)r_km_pseudo_enable;
		tmp_converted.km_debug_test = (uint8_t)r_km_debug_test;
		tmp_converted.active192 = (inverters_inv_r_send_active192)r_active192;
		tmp_converted.active190 = (inverters_inv_r_send_active190)r_active190;
		tmp_converted.m_r_rcp = (uint16_t)r_m_r_rcp;

		inverters_inv_r_send_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = INVERTERS_INV_R_SEND_BYTE_SIZE;
		return inverters_inv_r_send_pack(data, &tmp, INVERTERS_INV_R_SEND_BYTE_SIZE);
	}
	case 386:
	{
		inverters_inv_r_rcv_t tmp;
		inverters_inv_r_rcv_converted_t tmp_converted;
		uint8_t r_rcv_mux;
		float r_n_actual_filt;
		uint8_t r_ena64;
		uint8_t r_err_badparas;
		uint16_t r_def_end_1;
		uint8_t r_lmt_active_1;
		float r_i_cmd;
		float r_i_cmd_ramp;
		float r_iq_actual;
		uint16_t r_t_motor;
		uint16_t r_t_igbt;
		float r_vdc_bus_filt;
		uint8_t r_km_rsvd_0;
		uint8_t r_ena82;
		uint16_t r_def_din_1;
		int16_t r_m_cmd_ramp;
		float r_i_max_pk;
		float r_i_con_eff;
		float r_i_device;
		uint16_t r_n_r_lim;
		int16_t r_nmax100perc;
		uint8_t r_ncr064;
		uint8_t r_err_powerfault;
		uint8_t r_lmt_active_2;
		uint8_t r_km_speed_0;
		uint8_t r_ncr082;
		uint8_t r_lim_plus64;
		uint8_t r_err_rfe_fault;
		uint8_t r_in_active_2;
		uint8_t r_km_frg_off;
		uint8_t r_lim_plus82;
		uint8_t r_lim_minus64;
		uint8_t r_err_bustimeout;
		uint8_t r_in_active_1;
		uint8_t r_km_cal_off;
		uint8_t r_lim_minus82;
		uint8_t r_ok64;
		uint8_t r_err_feedbacksignal;
		uint8_t r_frgrun;
		uint8_t r_km_tx_tog_stat;
		uint8_t r_ok82;
		uint8_t r_icns64;
		uint8_t r_err_powervoltage_low;
		uint8_t r_rfe216;
		uint8_t r_km_i_limit;
		uint8_t r_icns82;
		uint8_t r_tnlim64;
		uint8_t r_err_motortemp;
		uint8_t r_km_n_clip;
		uint8_t r_tnlim82;
		uint8_t r_pn64;
		uint8_t r_err_devicetemp;
		uint8_t r_km_mix_ana_on;
		uint8_t r_pn82;
		uint8_t r_ni64;
		uint8_t r_err_overvoltage;
		uint8_t r_d_out_1_on;
		uint8_t r_km_allow_sync;
		uint8_t r_ni82;
		uint8_t r__n064;
		uint8_t r_err_ipeak;
		uint8_t r_d_out_2_on;
		uint8_t r_km_handwheel;
		uint8_t r__n082;
		uint8_t r_rsw64;
		uint8_t r_err_raceaway;
		uint8_t r_btbrdy;
		uint8_t r_km_phasing_extend;
		uint8_t r_rsw82;
		uint8_t r_cal064;
		uint8_t r_err_user;
		uint8_t r_go216;
		uint8_t r_km_rsvd_11;
		uint8_t r_cal082;
		uint8_t r_cal64;
		uint8_t r_d_out_3_on;
		uint8_t r_km_rsvd_12;
		uint8_t r_cal82;
		uint8_t r_tol64;
		uint8_t r_d_out_4_on;
		uint8_t r_km_rsvd_13;
		uint8_t r_tol82;
		uint8_t r_rdy64;
		uint8_t r_err_hwerr;
		uint8_t r_goff;
		uint8_t r_km_pseudo_enable;
		uint8_t r_rdy82;
		uint8_t r_brk064;
		uint8_t r_err_ballast;
		uint8_t r_active190;
		uint8_t r_brk1216;
		uint8_t r_km_debug_test;
		uint8_t r_brk082;
		uint8_t r_active192;
		uint8_t r_signmag64;
		uint8_t r_warn_warning_0;
		uint8_t r_signmag82;
		int16_t r_free;
		uint16_t r_m_r_rcp;
		uint8_t r_nclip64;
		uint8_t r_warn_illegal_status;
		uint8_t r_nclip82;
		uint8_t r_nclip_minus64;
		uint8_t r_warn_safe_in;
		uint8_t r_nclip_minus82;
		uint8_t r_nclip_plus64;
		uint8_t r_nclip_plus82;
		uint8_t r_irddig64;
		uint8_t r_irddig82;
		uint8_t r_iuserchd64;
		uint8_t r_iuserchd82;
		uint8_t r_irdn64;
		uint8_t r_warn_motortemp;
		uint8_t r_irdn82;
		uint8_t r_irdti64;
		uint8_t r_warn_devicetemp;
		uint8_t r_irdti82;
		uint8_t r_irdtir64;
		uint8_t r_warn_vout_sat;
		uint8_t r_irdtir82;
		uint8_t r__10hz64;
		uint8_t r_warn_ipeak;
		uint8_t r__10hz82;
		uint8_t r_irdtm64;
		uint8_t r_warn_raceaway;
		uint8_t r_irdtm82;
		uint8_t r_irdana64;
		uint8_t r_irdana82;
		uint8_t r_iwcns64;
		uint8_t r_iwcns82;
		uint8_t r_rfepulse64;
		uint8_t r_rfepulse82;
		uint8_t r_md64;
		uint8_t r_md82;
		uint8_t r_hndwhl64;
		uint8_t r_warn_ballast;
		uint8_t r_hndwhl82;

		sscanf(s, "%" SCNu8 ","  
			"%f,"       
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu16 "," 
			"%" SCNu8 ","  
			"%f,"       
			"%f,"       
			"%f,"       
			"%" SCNu16 "," 
			"%" SCNu16 "," 
			"%f,"       
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu16 "," 
			"%" SCNi16 "," 
			"%f,"       
			"%f,"       
			"%f,"       
			"%" SCNu16 "," 
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
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNi16 "," 
			"%" SCNu16 "," 
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
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
			&r_rcv_mux,
			&r_n_actual_filt,
			&r_ena64,
			&r_err_badparas,
			&r_def_end_1,
			&r_lmt_active_1,
			&r_i_cmd,
			&r_i_cmd_ramp,
			&r_iq_actual,
			&r_t_motor,
			&r_t_igbt,
			&r_vdc_bus_filt,
			&r_km_rsvd_0,
			&r_ena82,
			&r_def_din_1,
			&r_m_cmd_ramp,
			&r_i_max_pk,
			&r_i_con_eff,
			&r_i_device,
			&r_n_r_lim,
			&r_nmax100perc,
			&r_ncr064,
			&r_err_powerfault,
			&r_lmt_active_2,
			&r_km_speed_0,
			&r_ncr082,
			&r_lim_plus64,
			&r_err_rfe_fault,
			&r_in_active_2,
			&r_km_frg_off,
			&r_lim_plus82,
			&r_lim_minus64,
			&r_err_bustimeout,
			&r_in_active_1,
			&r_km_cal_off,
			&r_lim_minus82,
			&r_ok64,
			&r_err_feedbacksignal,
			&r_frgrun,
			&r_km_tx_tog_stat,
			&r_ok82,
			&r_icns64,
			&r_err_powervoltage_low,
			&r_rfe216,
			&r_km_i_limit,
			&r_icns82,
			&r_tnlim64,
			&r_err_motortemp,
			&r_km_n_clip,
			&r_tnlim82,
			&r_pn64,
			&r_err_devicetemp,
			&r_km_mix_ana_on,
			&r_pn82,
			&r_ni64,
			&r_err_overvoltage,
			&r_d_out_1_on,
			&r_km_allow_sync,
			&r_ni82,
			&r__n064,
			&r_err_ipeak,
			&r_d_out_2_on,
			&r_km_handwheel,
			&r__n082,
			&r_rsw64,
			&r_err_raceaway,
			&r_btbrdy,
			&r_km_phasing_extend,
			&r_rsw82,
			&r_cal064,
			&r_err_user,
			&r_go216,
			&r_km_rsvd_11,
			&r_cal082,
			&r_cal64,
			&r_d_out_3_on,
			&r_km_rsvd_12,
			&r_cal82,
			&r_tol64,
			&r_d_out_4_on,
			&r_km_rsvd_13,
			&r_tol82,
			&r_rdy64,
			&r_err_hwerr,
			&r_goff,
			&r_km_pseudo_enable,
			&r_rdy82,
			&r_brk064,
			&r_err_ballast,
			&r_active190,
			&r_brk1216,
			&r_km_debug_test,
			&r_brk082,
			&r_active192,
			&r_signmag64,
			&r_warn_warning_0,
			&r_signmag82,
			&r_free,
			&r_m_r_rcp,
			&r_nclip64,
			&r_warn_illegal_status,
			&r_nclip82,
			&r_nclip_minus64,
			&r_warn_safe_in,
			&r_nclip_minus82,
			&r_nclip_plus64,
			&r_nclip_plus82,
			&r_irddig64,
			&r_irddig82,
			&r_iuserchd64,
			&r_iuserchd82,
			&r_irdn64,
			&r_warn_motortemp,
			&r_irdn82,
			&r_irdti64,
			&r_warn_devicetemp,
			&r_irdti82,
			&r_irdtir64,
			&r_warn_vout_sat,
			&r_irdtir82,
			&r__10hz64,
			&r_warn_ipeak,
			&r__10hz82,
			&r_irdtm64,
			&r_warn_raceaway,
			&r_irdtm82,
			&r_irdana64,
			&r_irdana82,
			&r_iwcns64,
			&r_iwcns82,
			&r_rfepulse64,
			&r_rfepulse82,
			&r_md64,
			&r_md82,
			&r_hndwhl64,
			&r_warn_ballast,
			&r_hndwhl82);
		tmp_converted.rcv_mux = (inverters_inv_r_rcv_rcv_mux)r_rcv_mux;
		tmp_converted.n_actual_filt = (float)r_n_actual_filt;
		tmp_converted.ena64 = (uint8_t)r_ena64;
		tmp_converted.err_badparas = (uint8_t)r_err_badparas;
		tmp_converted.def_end_1 = (inverters_inv_r_rcv_def_end_1)r_def_end_1;
		tmp_converted.lmt_active_1 = (uint8_t)r_lmt_active_1;
		tmp_converted.i_cmd = (float)r_i_cmd;
		tmp_converted.i_cmd_ramp = (float)r_i_cmd_ramp;
		tmp_converted.iq_actual = (float)r_iq_actual;
		tmp_converted.t_motor = (uint16_t)r_t_motor;
		tmp_converted.t_igbt = (uint16_t)r_t_igbt;
		tmp_converted.vdc_bus_filt = (float)r_vdc_bus_filt;
		tmp_converted.km_rsvd_0 = (uint8_t)r_km_rsvd_0;
		tmp_converted.ena82 = (uint8_t)r_ena82;
		tmp_converted.def_din_1 = (inverters_inv_r_rcv_def_din_1)r_def_din_1;
		tmp_converted.m_cmd_ramp = (int16_t)r_m_cmd_ramp;
		tmp_converted.i_max_pk = (float)r_i_max_pk;
		tmp_converted.i_con_eff = (float)r_i_con_eff;
		tmp_converted.i_device = (float)r_i_device;
		tmp_converted.n_r_lim = (uint16_t)r_n_r_lim;
		tmp_converted.nmax100perc = (int16_t)r_nmax100perc;
		tmp_converted.ncr064 = (uint8_t)r_ncr064;
		tmp_converted.err_powerfault = (uint8_t)r_err_powerfault;
		tmp_converted.lmt_active_2 = (uint8_t)r_lmt_active_2;
		tmp_converted.km_speed_0 = (uint8_t)r_km_speed_0;
		tmp_converted.ncr082 = (uint8_t)r_ncr082;
		tmp_converted.lim_plus64 = (uint8_t)r_lim_plus64;
		tmp_converted.err_rfe_fault = (uint8_t)r_err_rfe_fault;
		tmp_converted.in_active_2 = (uint8_t)r_in_active_2;
		tmp_converted.km_frg_off = (uint8_t)r_km_frg_off;
		tmp_converted.lim_plus82 = (uint8_t)r_lim_plus82;
		tmp_converted.lim_minus64 = (uint8_t)r_lim_minus64;
		tmp_converted.err_bustimeout = (uint8_t)r_err_bustimeout;
		tmp_converted.in_active_1 = (uint8_t)r_in_active_1;
		tmp_converted.km_cal_off = (uint8_t)r_km_cal_off;
		tmp_converted.lim_minus82 = (uint8_t)r_lim_minus82;
		tmp_converted.ok64 = (uint8_t)r_ok64;
		tmp_converted.err_feedbacksignal = (uint8_t)r_err_feedbacksignal;
		tmp_converted.frgrun = (uint8_t)r_frgrun;
		tmp_converted.km_tx_tog_stat = (uint8_t)r_km_tx_tog_stat;
		tmp_converted.ok82 = (uint8_t)r_ok82;
		tmp_converted.icns64 = (uint8_t)r_icns64;
		tmp_converted.err_powervoltage_low = (uint8_t)r_err_powervoltage_low;
		tmp_converted.rfe216 = (uint8_t)r_rfe216;
		tmp_converted.km_i_limit = (uint8_t)r_km_i_limit;
		tmp_converted.icns82 = (uint8_t)r_icns82;
		tmp_converted.tnlim64 = (uint8_t)r_tnlim64;
		tmp_converted.err_motortemp = (uint8_t)r_err_motortemp;
		tmp_converted.km_n_clip = (uint8_t)r_km_n_clip;
		tmp_converted.tnlim82 = (uint8_t)r_tnlim82;
		tmp_converted.pn64 = (uint8_t)r_pn64;
		tmp_converted.err_devicetemp = (uint8_t)r_err_devicetemp;
		tmp_converted.km_mix_ana_on = (uint8_t)r_km_mix_ana_on;
		tmp_converted.pn82 = (uint8_t)r_pn82;
		tmp_converted.ni64 = (uint8_t)r_ni64;
		tmp_converted.err_overvoltage = (uint8_t)r_err_overvoltage;
		tmp_converted.d_out_1_on = (uint8_t)r_d_out_1_on;
		tmp_converted.km_allow_sync = (uint8_t)r_km_allow_sync;
		tmp_converted.ni82 = (uint8_t)r_ni82;
		tmp_converted._n064 = (uint8_t)r__n064;
		tmp_converted.err_ipeak = (uint8_t)r_err_ipeak;
		tmp_converted.d_out_2_on = (uint8_t)r_d_out_2_on;
		tmp_converted.km_handwheel = (uint8_t)r_km_handwheel;
		tmp_converted._n082 = (uint8_t)r__n082;
		tmp_converted.rsw64 = (uint8_t)r_rsw64;
		tmp_converted.err_raceaway = (uint8_t)r_err_raceaway;
		tmp_converted.btbrdy = (uint8_t)r_btbrdy;
		tmp_converted.km_phasing_extend = (uint8_t)r_km_phasing_extend;
		tmp_converted.rsw82 = (uint8_t)r_rsw82;
		tmp_converted.cal064 = (uint8_t)r_cal064;
		tmp_converted.err_user = (uint8_t)r_err_user;
		tmp_converted.go216 = (uint8_t)r_go216;
		tmp_converted.km_rsvd_11 = (uint8_t)r_km_rsvd_11;
		tmp_converted.cal082 = (uint8_t)r_cal082;
		tmp_converted.cal64 = (uint8_t)r_cal64;
		tmp_converted.d_out_3_on = (uint8_t)r_d_out_3_on;
		tmp_converted.km_rsvd_12 = (uint8_t)r_km_rsvd_12;
		tmp_converted.cal82 = (uint8_t)r_cal82;
		tmp_converted.tol64 = (uint8_t)r_tol64;
		tmp_converted.d_out_4_on = (uint8_t)r_d_out_4_on;
		tmp_converted.km_rsvd_13 = (uint8_t)r_km_rsvd_13;
		tmp_converted.tol82 = (uint8_t)r_tol82;
		tmp_converted.rdy64 = (uint8_t)r_rdy64;
		tmp_converted.err_hwerr = (uint8_t)r_err_hwerr;
		tmp_converted.goff = (uint8_t)r_goff;
		tmp_converted.km_pseudo_enable = (uint8_t)r_km_pseudo_enable;
		tmp_converted.rdy82 = (uint8_t)r_rdy82;
		tmp_converted.brk064 = (uint8_t)r_brk064;
		tmp_converted.err_ballast = (uint8_t)r_err_ballast;
		tmp_converted.active190 = (inverters_inv_r_rcv_active190)r_active190;
		tmp_converted.brk1216 = (uint8_t)r_brk1216;
		tmp_converted.km_debug_test = (uint8_t)r_km_debug_test;
		tmp_converted.brk082 = (uint8_t)r_brk082;
		tmp_converted.active192 = (inverters_inv_r_rcv_active192)r_active192;
		tmp_converted.signmag64 = (uint8_t)r_signmag64;
		tmp_converted.warn_warning_0 = (uint8_t)r_warn_warning_0;
		tmp_converted.signmag82 = (uint8_t)r_signmag82;
		tmp_converted.free = (int16_t)r_free;
		tmp_converted.m_r_rcp = (uint16_t)r_m_r_rcp;
		tmp_converted.nclip64 = (uint8_t)r_nclip64;
		tmp_converted.warn_illegal_status = (uint8_t)r_warn_illegal_status;
		tmp_converted.nclip82 = (uint8_t)r_nclip82;
		tmp_converted.nclip_minus64 = (uint8_t)r_nclip_minus64;
		tmp_converted.warn_safe_in = (uint8_t)r_warn_safe_in;
		tmp_converted.nclip_minus82 = (uint8_t)r_nclip_minus82;
		tmp_converted.nclip_plus64 = (uint8_t)r_nclip_plus64;
		tmp_converted.nclip_plus82 = (uint8_t)r_nclip_plus82;
		tmp_converted.irddig64 = (uint8_t)r_irddig64;
		tmp_converted.irddig82 = (uint8_t)r_irddig82;
		tmp_converted.iuserchd64 = (uint8_t)r_iuserchd64;
		tmp_converted.iuserchd82 = (uint8_t)r_iuserchd82;
		tmp_converted.irdn64 = (uint8_t)r_irdn64;
		tmp_converted.warn_motortemp = (uint8_t)r_warn_motortemp;
		tmp_converted.irdn82 = (uint8_t)r_irdn82;
		tmp_converted.irdti64 = (uint8_t)r_irdti64;
		tmp_converted.warn_devicetemp = (uint8_t)r_warn_devicetemp;
		tmp_converted.irdti82 = (uint8_t)r_irdti82;
		tmp_converted.irdtir64 = (uint8_t)r_irdtir64;
		tmp_converted.warn_vout_sat = (uint8_t)r_warn_vout_sat;
		tmp_converted.irdtir82 = (uint8_t)r_irdtir82;
		tmp_converted._10hz64 = (uint8_t)r__10hz64;
		tmp_converted.warn_ipeak = (uint8_t)r_warn_ipeak;
		tmp_converted._10hz82 = (uint8_t)r__10hz82;
		tmp_converted.irdtm64 = (uint8_t)r_irdtm64;
		tmp_converted.warn_raceaway = (uint8_t)r_warn_raceaway;
		tmp_converted.irdtm82 = (uint8_t)r_irdtm82;
		tmp_converted.irdana64 = (uint8_t)r_irdana64;
		tmp_converted.irdana82 = (uint8_t)r_irdana82;
		tmp_converted.iwcns64 = (uint8_t)r_iwcns64;
		tmp_converted.iwcns82 = (uint8_t)r_iwcns82;
		tmp_converted.rfepulse64 = (uint8_t)r_rfepulse64;
		tmp_converted.rfepulse82 = (uint8_t)r_rfepulse82;
		tmp_converted.md64 = (uint8_t)r_md64;
		tmp_converted.md82 = (uint8_t)r_md82;
		tmp_converted.hndwhl64 = (uint8_t)r_hndwhl64;
		tmp_converted.warn_ballast = (uint8_t)r_warn_ballast;
		tmp_converted.hndwhl82 = (uint8_t)r_hndwhl82;

		inverters_inv_r_rcv_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = INVERTERS_INV_R_RCV_BYTE_SIZE;
		return inverters_inv_r_rcv_pack(data, &tmp, INVERTERS_INV_R_RCV_BYTE_SIZE);
	}

    }
    return 0;
}
int inverters_n_fields_from_id(int id)
{
	switch(id)
    {
		case 513: return 30;
		case 385: return 137;
		case 514: return 30;
		case 386: return 137;
    }
    return 0;
}
int inverters_fields_types_from_id(int id, int* fields_types, int fields_types_size)
{
    switch(id)
    {
	case 513:
		if(fields_types_size < 30) return 0;
		fields_types[0] = e_inverters_inv_l_send_send_mux;
		fields_types[1] = e_inverters_inv_l_send_read_id;
		fields_types[2] = e_inverters_uint8_t;
		fields_types[3] = e_inverters_float;
		fields_types[4] = e_inverters_inv_l_send_def_din_1;
		fields_types[5] = e_inverters_inv_l_send_def_end_1;
		fields_types[6] = e_inverters_float;
		fields_types[7] = e_inverters_float;
		fields_types[8] = e_inverters_float;
		fields_types[9] = e_inverters_uint16_t;
		fields_types[10] = e_inverters_int16_t;
		fields_types[11] = e_inverters_uint8_t;
		fields_types[12] = e_inverters_uint8_t;
		fields_types[13] = e_inverters_uint8_t;
		fields_types[14] = e_inverters_uint8_t;
		fields_types[15] = e_inverters_uint8_t;
		fields_types[16] = e_inverters_uint8_t;
		fields_types[17] = e_inverters_uint8_t;
		fields_types[18] = e_inverters_inv_l_send_ret_interval;
		fields_types[19] = e_inverters_uint8_t;
		fields_types[20] = e_inverters_uint8_t;
		fields_types[21] = e_inverters_uint8_t;
		fields_types[22] = e_inverters_uint8_t;
		fields_types[23] = e_inverters_uint8_t;
		fields_types[24] = e_inverters_uint8_t;
		fields_types[25] = e_inverters_uint8_t;
		fields_types[26] = e_inverters_uint8_t;
		fields_types[27] = e_inverters_inv_l_send_active192;
		fields_types[28] = e_inverters_inv_l_send_active190;
		fields_types[29] = e_inverters_uint16_t;
		return 30;
	case 385:
		if(fields_types_size < 137) return 0;
		fields_types[0] = e_inverters_inv_l_rcv_rcv_mux;
		fields_types[1] = e_inverters_float;
		fields_types[2] = e_inverters_uint8_t;
		fields_types[3] = e_inverters_uint8_t;
		fields_types[4] = e_inverters_inv_l_rcv_def_end_1;
		fields_types[5] = e_inverters_uint8_t;
		fields_types[6] = e_inverters_float;
		fields_types[7] = e_inverters_float;
		fields_types[8] = e_inverters_float;
		fields_types[9] = e_inverters_uint16_t;
		fields_types[10] = e_inverters_uint16_t;
		fields_types[11] = e_inverters_float;
		fields_types[12] = e_inverters_uint8_t;
		fields_types[13] = e_inverters_uint8_t;
		fields_types[14] = e_inverters_inv_l_rcv_def_din_1;
		fields_types[15] = e_inverters_int16_t;
		fields_types[16] = e_inverters_float;
		fields_types[17] = e_inverters_float;
		fields_types[18] = e_inverters_float;
		fields_types[19] = e_inverters_uint16_t;
		fields_types[20] = e_inverters_int16_t;
		fields_types[21] = e_inverters_uint8_t;
		fields_types[22] = e_inverters_uint8_t;
		fields_types[23] = e_inverters_uint8_t;
		fields_types[24] = e_inverters_uint8_t;
		fields_types[25] = e_inverters_uint8_t;
		fields_types[26] = e_inverters_uint8_t;
		fields_types[27] = e_inverters_uint8_t;
		fields_types[28] = e_inverters_uint8_t;
		fields_types[29] = e_inverters_uint8_t;
		fields_types[30] = e_inverters_uint8_t;
		fields_types[31] = e_inverters_uint8_t;
		fields_types[32] = e_inverters_uint8_t;
		fields_types[33] = e_inverters_uint8_t;
		fields_types[34] = e_inverters_uint8_t;
		fields_types[35] = e_inverters_uint8_t;
		fields_types[36] = e_inverters_uint8_t;
		fields_types[37] = e_inverters_uint8_t;
		fields_types[38] = e_inverters_uint8_t;
		fields_types[39] = e_inverters_uint8_t;
		fields_types[40] = e_inverters_uint8_t;
		fields_types[41] = e_inverters_uint8_t;
		fields_types[42] = e_inverters_uint8_t;
		fields_types[43] = e_inverters_uint8_t;
		fields_types[44] = e_inverters_uint8_t;
		fields_types[45] = e_inverters_uint8_t;
		fields_types[46] = e_inverters_uint8_t;
		fields_types[47] = e_inverters_uint8_t;
		fields_types[48] = e_inverters_uint8_t;
		fields_types[49] = e_inverters_uint8_t;
		fields_types[50] = e_inverters_uint8_t;
		fields_types[51] = e_inverters_uint8_t;
		fields_types[52] = e_inverters_uint8_t;
		fields_types[53] = e_inverters_uint8_t;
		fields_types[54] = e_inverters_uint8_t;
		fields_types[55] = e_inverters_uint8_t;
		fields_types[56] = e_inverters_uint8_t;
		fields_types[57] = e_inverters_uint8_t;
		fields_types[58] = e_inverters_uint8_t;
		fields_types[59] = e_inverters_uint8_t;
		fields_types[60] = e_inverters_uint8_t;
		fields_types[61] = e_inverters_uint8_t;
		fields_types[62] = e_inverters_uint8_t;
		fields_types[63] = e_inverters_uint8_t;
		fields_types[64] = e_inverters_uint8_t;
		fields_types[65] = e_inverters_uint8_t;
		fields_types[66] = e_inverters_uint8_t;
		fields_types[67] = e_inverters_uint8_t;
		fields_types[68] = e_inverters_uint8_t;
		fields_types[69] = e_inverters_uint8_t;
		fields_types[70] = e_inverters_uint8_t;
		fields_types[71] = e_inverters_uint8_t;
		fields_types[72] = e_inverters_uint8_t;
		fields_types[73] = e_inverters_uint8_t;
		fields_types[74] = e_inverters_uint8_t;
		fields_types[75] = e_inverters_uint8_t;
		fields_types[76] = e_inverters_uint8_t;
		fields_types[77] = e_inverters_uint8_t;
		fields_types[78] = e_inverters_uint8_t;
		fields_types[79] = e_inverters_uint8_t;
		fields_types[80] = e_inverters_uint8_t;
		fields_types[81] = e_inverters_uint8_t;
		fields_types[82] = e_inverters_uint8_t;
		fields_types[83] = e_inverters_uint8_t;
		fields_types[84] = e_inverters_uint8_t;
		fields_types[85] = e_inverters_uint8_t;
		fields_types[86] = e_inverters_uint8_t;
		fields_types[87] = e_inverters_uint8_t;
		fields_types[88] = e_inverters_uint8_t;
		fields_types[89] = e_inverters_inv_l_rcv_active190;
		fields_types[90] = e_inverters_uint8_t;
		fields_types[91] = e_inverters_uint8_t;
		fields_types[92] = e_inverters_uint8_t;
		fields_types[93] = e_inverters_inv_l_rcv_active192;
		fields_types[94] = e_inverters_uint8_t;
		fields_types[95] = e_inverters_uint8_t;
		fields_types[96] = e_inverters_uint8_t;
		fields_types[97] = e_inverters_int16_t;
		fields_types[98] = e_inverters_uint16_t;
		fields_types[99] = e_inverters_uint8_t;
		fields_types[100] = e_inverters_uint8_t;
		fields_types[101] = e_inverters_uint8_t;
		fields_types[102] = e_inverters_uint8_t;
		fields_types[103] = e_inverters_uint8_t;
		fields_types[104] = e_inverters_uint8_t;
		fields_types[105] = e_inverters_uint8_t;
		fields_types[106] = e_inverters_uint8_t;
		fields_types[107] = e_inverters_uint8_t;
		fields_types[108] = e_inverters_uint8_t;
		fields_types[109] = e_inverters_uint8_t;
		fields_types[110] = e_inverters_uint8_t;
		fields_types[111] = e_inverters_uint8_t;
		fields_types[112] = e_inverters_uint8_t;
		fields_types[113] = e_inverters_uint8_t;
		fields_types[114] = e_inverters_uint8_t;
		fields_types[115] = e_inverters_uint8_t;
		fields_types[116] = e_inverters_uint8_t;
		fields_types[117] = e_inverters_uint8_t;
		fields_types[118] = e_inverters_uint8_t;
		fields_types[119] = e_inverters_uint8_t;
		fields_types[120] = e_inverters_uint8_t;
		fields_types[121] = e_inverters_uint8_t;
		fields_types[122] = e_inverters_uint8_t;
		fields_types[123] = e_inverters_uint8_t;
		fields_types[124] = e_inverters_uint8_t;
		fields_types[125] = e_inverters_uint8_t;
		fields_types[126] = e_inverters_uint8_t;
		fields_types[127] = e_inverters_uint8_t;
		fields_types[128] = e_inverters_uint8_t;
		fields_types[129] = e_inverters_uint8_t;
		fields_types[130] = e_inverters_uint8_t;
		fields_types[131] = e_inverters_uint8_t;
		fields_types[132] = e_inverters_uint8_t;
		fields_types[133] = e_inverters_uint8_t;
		fields_types[134] = e_inverters_uint8_t;
		fields_types[135] = e_inverters_uint8_t;
		fields_types[136] = e_inverters_uint8_t;
		return 137;
	case 514:
		if(fields_types_size < 30) return 0;
		fields_types[0] = e_inverters_inv_r_send_send_mux;
		fields_types[1] = e_inverters_inv_r_send_read_id;
		fields_types[2] = e_inverters_uint8_t;
		fields_types[3] = e_inverters_float;
		fields_types[4] = e_inverters_inv_r_send_def_din_1;
		fields_types[5] = e_inverters_inv_r_send_def_end_1;
		fields_types[6] = e_inverters_float;
		fields_types[7] = e_inverters_float;
		fields_types[8] = e_inverters_float;
		fields_types[9] = e_inverters_uint16_t;
		fields_types[10] = e_inverters_int16_t;
		fields_types[11] = e_inverters_uint8_t;
		fields_types[12] = e_inverters_uint8_t;
		fields_types[13] = e_inverters_uint8_t;
		fields_types[14] = e_inverters_uint8_t;
		fields_types[15] = e_inverters_uint8_t;
		fields_types[16] = e_inverters_uint8_t;
		fields_types[17] = e_inverters_uint8_t;
		fields_types[18] = e_inverters_inv_r_send_ret_interval;
		fields_types[19] = e_inverters_uint8_t;
		fields_types[20] = e_inverters_uint8_t;
		fields_types[21] = e_inverters_uint8_t;
		fields_types[22] = e_inverters_uint8_t;
		fields_types[23] = e_inverters_uint8_t;
		fields_types[24] = e_inverters_uint8_t;
		fields_types[25] = e_inverters_uint8_t;
		fields_types[26] = e_inverters_uint8_t;
		fields_types[27] = e_inverters_inv_r_send_active192;
		fields_types[28] = e_inverters_inv_r_send_active190;
		fields_types[29] = e_inverters_uint16_t;
		return 30;
	case 386:
		if(fields_types_size < 137) return 0;
		fields_types[0] = e_inverters_inv_r_rcv_rcv_mux;
		fields_types[1] = e_inverters_float;
		fields_types[2] = e_inverters_uint8_t;
		fields_types[3] = e_inverters_uint8_t;
		fields_types[4] = e_inverters_inv_r_rcv_def_end_1;
		fields_types[5] = e_inverters_uint8_t;
		fields_types[6] = e_inverters_float;
		fields_types[7] = e_inverters_float;
		fields_types[8] = e_inverters_float;
		fields_types[9] = e_inverters_uint16_t;
		fields_types[10] = e_inverters_uint16_t;
		fields_types[11] = e_inverters_float;
		fields_types[12] = e_inverters_uint8_t;
		fields_types[13] = e_inverters_uint8_t;
		fields_types[14] = e_inverters_inv_r_rcv_def_din_1;
		fields_types[15] = e_inverters_int16_t;
		fields_types[16] = e_inverters_float;
		fields_types[17] = e_inverters_float;
		fields_types[18] = e_inverters_float;
		fields_types[19] = e_inverters_uint16_t;
		fields_types[20] = e_inverters_int16_t;
		fields_types[21] = e_inverters_uint8_t;
		fields_types[22] = e_inverters_uint8_t;
		fields_types[23] = e_inverters_uint8_t;
		fields_types[24] = e_inverters_uint8_t;
		fields_types[25] = e_inverters_uint8_t;
		fields_types[26] = e_inverters_uint8_t;
		fields_types[27] = e_inverters_uint8_t;
		fields_types[28] = e_inverters_uint8_t;
		fields_types[29] = e_inverters_uint8_t;
		fields_types[30] = e_inverters_uint8_t;
		fields_types[31] = e_inverters_uint8_t;
		fields_types[32] = e_inverters_uint8_t;
		fields_types[33] = e_inverters_uint8_t;
		fields_types[34] = e_inverters_uint8_t;
		fields_types[35] = e_inverters_uint8_t;
		fields_types[36] = e_inverters_uint8_t;
		fields_types[37] = e_inverters_uint8_t;
		fields_types[38] = e_inverters_uint8_t;
		fields_types[39] = e_inverters_uint8_t;
		fields_types[40] = e_inverters_uint8_t;
		fields_types[41] = e_inverters_uint8_t;
		fields_types[42] = e_inverters_uint8_t;
		fields_types[43] = e_inverters_uint8_t;
		fields_types[44] = e_inverters_uint8_t;
		fields_types[45] = e_inverters_uint8_t;
		fields_types[46] = e_inverters_uint8_t;
		fields_types[47] = e_inverters_uint8_t;
		fields_types[48] = e_inverters_uint8_t;
		fields_types[49] = e_inverters_uint8_t;
		fields_types[50] = e_inverters_uint8_t;
		fields_types[51] = e_inverters_uint8_t;
		fields_types[52] = e_inverters_uint8_t;
		fields_types[53] = e_inverters_uint8_t;
		fields_types[54] = e_inverters_uint8_t;
		fields_types[55] = e_inverters_uint8_t;
		fields_types[56] = e_inverters_uint8_t;
		fields_types[57] = e_inverters_uint8_t;
		fields_types[58] = e_inverters_uint8_t;
		fields_types[59] = e_inverters_uint8_t;
		fields_types[60] = e_inverters_uint8_t;
		fields_types[61] = e_inverters_uint8_t;
		fields_types[62] = e_inverters_uint8_t;
		fields_types[63] = e_inverters_uint8_t;
		fields_types[64] = e_inverters_uint8_t;
		fields_types[65] = e_inverters_uint8_t;
		fields_types[66] = e_inverters_uint8_t;
		fields_types[67] = e_inverters_uint8_t;
		fields_types[68] = e_inverters_uint8_t;
		fields_types[69] = e_inverters_uint8_t;
		fields_types[70] = e_inverters_uint8_t;
		fields_types[71] = e_inverters_uint8_t;
		fields_types[72] = e_inverters_uint8_t;
		fields_types[73] = e_inverters_uint8_t;
		fields_types[74] = e_inverters_uint8_t;
		fields_types[75] = e_inverters_uint8_t;
		fields_types[76] = e_inverters_uint8_t;
		fields_types[77] = e_inverters_uint8_t;
		fields_types[78] = e_inverters_uint8_t;
		fields_types[79] = e_inverters_uint8_t;
		fields_types[80] = e_inverters_uint8_t;
		fields_types[81] = e_inverters_uint8_t;
		fields_types[82] = e_inverters_uint8_t;
		fields_types[83] = e_inverters_uint8_t;
		fields_types[84] = e_inverters_uint8_t;
		fields_types[85] = e_inverters_uint8_t;
		fields_types[86] = e_inverters_uint8_t;
		fields_types[87] = e_inverters_uint8_t;
		fields_types[88] = e_inverters_uint8_t;
		fields_types[89] = e_inverters_inv_r_rcv_active190;
		fields_types[90] = e_inverters_uint8_t;
		fields_types[91] = e_inverters_uint8_t;
		fields_types[92] = e_inverters_uint8_t;
		fields_types[93] = e_inverters_inv_r_rcv_active192;
		fields_types[94] = e_inverters_uint8_t;
		fields_types[95] = e_inverters_uint8_t;
		fields_types[96] = e_inverters_uint8_t;
		fields_types[97] = e_inverters_int16_t;
		fields_types[98] = e_inverters_uint16_t;
		fields_types[99] = e_inverters_uint8_t;
		fields_types[100] = e_inverters_uint8_t;
		fields_types[101] = e_inverters_uint8_t;
		fields_types[102] = e_inverters_uint8_t;
		fields_types[103] = e_inverters_uint8_t;
		fields_types[104] = e_inverters_uint8_t;
		fields_types[105] = e_inverters_uint8_t;
		fields_types[106] = e_inverters_uint8_t;
		fields_types[107] = e_inverters_uint8_t;
		fields_types[108] = e_inverters_uint8_t;
		fields_types[109] = e_inverters_uint8_t;
		fields_types[110] = e_inverters_uint8_t;
		fields_types[111] = e_inverters_uint8_t;
		fields_types[112] = e_inverters_uint8_t;
		fields_types[113] = e_inverters_uint8_t;
		fields_types[114] = e_inverters_uint8_t;
		fields_types[115] = e_inverters_uint8_t;
		fields_types[116] = e_inverters_uint8_t;
		fields_types[117] = e_inverters_uint8_t;
		fields_types[118] = e_inverters_uint8_t;
		fields_types[119] = e_inverters_uint8_t;
		fields_types[120] = e_inverters_uint8_t;
		fields_types[121] = e_inverters_uint8_t;
		fields_types[122] = e_inverters_uint8_t;
		fields_types[123] = e_inverters_uint8_t;
		fields_types[124] = e_inverters_uint8_t;
		fields_types[125] = e_inverters_uint8_t;
		fields_types[126] = e_inverters_uint8_t;
		fields_types[127] = e_inverters_uint8_t;
		fields_types[128] = e_inverters_uint8_t;
		fields_types[129] = e_inverters_uint8_t;
		fields_types[130] = e_inverters_uint8_t;
		fields_types[131] = e_inverters_uint8_t;
		fields_types[132] = e_inverters_uint8_t;
		fields_types[133] = e_inverters_uint8_t;
		fields_types[134] = e_inverters_uint8_t;
		fields_types[135] = e_inverters_uint8_t;
		fields_types[136] = e_inverters_uint8_t;
		return 137;

    }
    return 0;
}
std::vector<std::string> inverters_enum_fields_from_name(const std::string& msg_name, const std::string& sgn_name)
{
	std::vector<std::string> ret;

	if(msg_name == INV_L_SEND)
	{
		if(sgn_name == "send_mux")
		{
			ret.push_back("ID_04_USER_Key");
			ret.push_back("ID_05_Motor_F_nom");
			ret.push_back("ID_07_FU_T_dc");
			ret.push_back("ID_08_FU_V_dc");
			ret.push_back("ID_09_FU_Special");
			ret.push_back("ID_0A_FU_U_min");
			ret.push_back("ID_0B_FU_F_min");
			ret.push_back("ID_0C_FU_V_corner");
			ret.push_back("ID_0D_FU_F_corner");
			ret.push_back("ID_0E_Motor_Cos_Phi");
			ret.push_back("ID_0F_FU_Extra");
			ret.push_back("ID_10_Oszi_Channel");
			ret.push_back("ID_12_Oszi_Triger_Level");
			ret.push_back("ID_13_Oszi_Triger_Edge");
			ret.push_back("ID_14_Oszi_Triger_Source");
			ret.push_back("ID_15_Oszi_Source");
			ret.push_back("ID_16_Oszi_Skip");
			ret.push_back("ID_17_Oszi_Read_cmd");
			ret.push_back("ID_18_Oszi_Run_cmd");
			ret.push_back("ID_1A_Calib_Ref_Value");
			ret.push_back("ID_1C_PID_I_Kp");
			ret.push_back("ID_1D_PID_I_Ti");
			ret.push_back("ID_1E_Cutoffdig");
			ret.push_back("ID_21_Id_setdig");
			ret.push_back("ID_25_I_Delta_Ramp");
			ret.push_back("ID_2B_PID_I_TiM");
			ret.push_back("ID_2C_PID_n_Kp");
			ret.push_back("ID_2D_PID_n_Ti");
			ret.push_back("ID_2E_PID_n_Td");
			ret.push_back("ID_2F_Ain_in_1_OffsScale");
			ret.push_back("ID_31_N_setdig");
			ret.push_back("ID_34_N_Lim");
			ret.push_back("ID_35_Acc_Ramps");
			ret.push_back("ID_36_CommandSource");
			ret.push_back("ID_3B_PID_n_TiM");
			ret.push_back("ID_3C_I_Derating_N_perc");
			ret.push_back("ID_3E_N_Lim_minus");
			ret.push_back("ID_3F_N_Lim_plus");
			ret.push_back("ID_44_FeedBack_Offset_Angle");
			ret.push_back("ID_3D_Read_Cmd");
			ret.push_back("ID_46_I_lim_dig_perc");
			ret.push_back("ID_4C_I_Derating_TE");
			ret.push_back("ID_4D_Motor_I_max_eff_Arms");
			ret.push_back("ID_4E_Motor_I_nom_eff_Arms");
			ret.push_back("ID_4F_Motor_Pole_Number");
			ret.push_back("ID_50_Ain_in_1_Cutoff");
			ret.push_back("ID_51_Kern_Mode_State");
			ret.push_back("ID_53_Ain_in_2_Cutoff");
			ret.push_back("ID_58_I_Derating_TD");
			ret.push_back("ID_59_Motor_Nominal_Speed");
			ret.push_back("ID_5A_Device_Options");
			ret.push_back("ID_5B_PID_n_Kacc");
			ret.push_back("ID_5E_Speed_Filter");
			ret.push_back("ID_60_Ain_in_X_Filter");
			ret.push_back("ID_62_SerialNumber");
			ret.push_back("ID_64_Device_Mains_Supply_V");
			ret.push_back("ID_65_Regen_Resistor_P_and_R");
			ret.push_back("ID_67_Device_Type");
			ret.push_back("ID_68_CAN_ID_Rx");
			ret.push_back("ID_69_CAN_ID_Tx");
			ret.push_back("ID_6A_Pos_PID_Kp");
			ret.push_back("ID_6B_Pos_PID_Ti");
			ret.push_back("ID_6C_Pos_PID_Td");
			ret.push_back("ID_6E_Pos_Destination");
			ret.push_back("ID_71_Pos_PID_TiM");
			ret.push_back("ID_72_Pos_OffsetReference");
			ret.push_back("ID_73_CAN_NBT");
			ret.push_back("ID_75_Pos_Ref_Reso_Edge");
			ret.push_back("ID_76_Pos_Calib_Speed_1");
			ret.push_back("ID_77_Pos_Calib_Speed_2");
			ret.push_back("ID_79_Pos_Tol_Window");
			ret.push_back("ID_7A_Pos_Preset_Value");
			ret.push_back("ID_7C_Pos_NDrive_Scale");
			ret.push_back("ID_7D_Pos_NDrive_Offset");
			ret.push_back("ID_7E_Pos_FB2_Scale_Fac_Ext");
			ret.push_back("ID_7F_Pos_Offset_Slack");
			ret.push_back("ID_80_Pos_Diff_Slack");
			ret.push_back("ID_83_Function_Parameter_Read");
			ret.push_back("ID_84_Function_Parameter_Write");
			ret.push_back("ID_85_Function_Special");
			ret.push_back("ID_88_CAN_ID_2_Rx");
			ret.push_back("ID_89_CAN_ID_2_Tx");
			ret.push_back("ID_8B_VoltageControl_Ref");
			ret.push_back("ID_8C_VoltageControl_Kp");
			ret.push_back("ID_8D_VoltageControl_Ti");
			ret.push_back("ID_8E_Clear_Error_List");
			ret.push_back("ID_90_M_setdig");
			ret.push_back("ID_A2_I_Derating_TM");
			ret.push_back("ID_A3_Motor_Temp_Error_Lim");
			ret.push_back("ID_A4_Motor_Options");
			ret.push_back("ID_A5_Device_DC_Bus_MinMax_Lim");
			ret.push_back("ID_A6_FB_IncrementsPerRot");
			ret.push_back("ID_A7_FB_Pole_Number");
			ret.push_back("ID_B1_Motor_L_Sigma_Q");
			ret.push_back("ID_B2_Id_Nominal");
			ret.push_back("ID_B3_Motor_Magn_Inductance");
			ret.push_back("ID_B4_Motor_Rotor_Resistance");
			ret.push_back("ID_B5_Id_Minimum");
			ret.push_back("ID_B6_Time_Constant_Rotor");
			ret.push_back("ID_BB_Motor_L_Sigma_D");
			ret.push_back("ID_BC_Motor_Stator_Resistance");
			ret.push_back("ID_BD_Time_Constant_Stator");
			ret.push_back("ID_BE_LogicDefine_of_END_1");
			ret.push_back("ID_BF_LogicDefine_of_END_2");
			ret.push_back("ID_C0_LogicDefine_of_DIN_1");
			ret.push_back("ID_C1_LogicDefine_of_DIN_2");
			ret.push_back("ID_C2_LogicDefine_of_OUT_1");
			ret.push_back("ID_C3_LogicDefine_of_OUT_2");
			ret.push_back("ID_DA_LogicDefine_of_OUT_3");
			ret.push_back("ID_DB_LogicDefine_of_OUT_4");
			ret.push_back("ID_C4_I_max_pk_perc");
			ret.push_back("ID_C5_I_con_eff_perc");
			ret.push_back("ID_C6_I_device");
			ret.push_back("ID_C7_RLim_MRcp_Ramp");
			ret.push_back("ID_C8_Nmax100perc");
			ret.push_back("ID_C9_CurrentControl_xKp");
			ret.push_back("ID_CA_Bat_Opr_Limits");
			ret.push_back("ID_CB_PID_I_Kf");
			ret.push_back("ID_CD_Car_Mode_Config");
			ret.push_back("ID_D0_CAN_Timeout");
			ret.push_back("ID_D1_Var_1");
			ret.push_back("ID_D2_Var_2");
			ret.push_back("ID_D3_Var_3");
			ret.push_back("ID_D4_Var_4");
			ret.push_back("ID_D7_Ain_in_2_OffsScale");
			ret.push_back("ID_DC_DAC_Source_ID");
			ret.push_back("ID_ED_Dec_Ramps");
			ret.push_back("ID_EE_V_Shunt");
			ret.push_back("ID_F0_Time_I_Peak");
			ret.push_back("ID_F1_Brake_Delay");
			ret.push_back("ID_F8_Axis_Label");
			return ret;
		}
		if(sgn_name == "read_id")
		{
			ret.push_back("05h_Motor_F_nom");
			ret.push_back("06h_Motor_V_nom");
			ret.push_back("07h_FU_T_dc");
			ret.push_back("08h_FU_V_dc");
			ret.push_back("09h_FU_Special");
			ret.push_back("0Ah_FU_U_min");
			ret.push_back("0Bh_FU_F_min");
			ret.push_back("0Ch_FU_V_corner");
			ret.push_back("0Dh_FU_F_corner");
			ret.push_back("0Eh_Motor_Cos_Phi");
			ret.push_back("0Fh_FU_Extra");
			ret.push_back("10h_Oszi_Channel");
			ret.push_back("11h_Control_Status");
			ret.push_back("12h_Oszi_Triger_Level");
			ret.push_back("13h_Oszi_Triger_Edge");
			ret.push_back("14h_Oszi_Triger_Source");
			ret.push_back("15h_Oszi_Source");
			ret.push_back("16h_Oszi_Skip");
			ret.push_back("17h_Oszi_Read_cmd");
			ret.push_back("18h_Oszi_Run_cmd");
			ret.push_back("19h_PWM_Enum");
			ret.push_back("1Ah_Calib_Ref_Value");
			ret.push_back("1Bh_FW_Nr");
			ret.push_back("1Ch_I_Kp");
			ret.push_back("1Dh_I_Ti");
			ret.push_back("1Eh_Cutoffdig");
			ret.push_back("1Fh_I3_Offset");
			ret.push_back("20h_I_Actual");
			ret.push_back("21h_Id_setdig");
			ret.push_back("22h_I_cmd_ramp");
			ret.push_back("23h_Id_Ref");
			ret.push_back("24h_I_Max_Inuse");
			ret.push_back("25h_I_Delta_Ramp");
			ret.push_back("26h_I_cmd");
			ret.push_back("27h_Iq_Actual");
			ret.push_back("28h_Id_Actual");
			ret.push_back("29h_Vq_Output");
			ret.push_back("2Ah_Vd_Output");
			ret.push_back("2Bh_I_TiM");
			ret.push_back("2Ch_n_Kp");
			ret.push_back("2Dh_n_Ti");
			ret.push_back("2Eh_n_Td");
			ret.push_back("2Fh_Ain_in_1_OffsScale");
			ret.push_back("30h_N_Actual");
			ret.push_back("31h_N_setdig");
			ret.push_back("32h_N_cmd_ramp");
			ret.push_back("33h_N_Error");
			ret.push_back("34h_N_Lim");
			ret.push_back("35h_Acc_Ramps");
			ret.push_back("36h_CommandSource");
			ret.push_back("37h_DZR_Sequencer_Value");
			ret.push_back("38h_Iq_Error");
			ret.push_back("39h_Id_Error");
			ret.push_back("3Bh_n_TiM");
			ret.push_back("3Ch_I_Derating_N_perc");
			ret.push_back("3Eh_N_Lim_minus");
			ret.push_back("3Fh_N_Lim_plus");
			ret.push_back("40h_Status_Map");
			ret.push_back("41h_Incr_Delta");
			ret.push_back("42h_MotorPosition_Mech");
			ret.push_back("43h_MotorPosition_Elec");
			ret.push_back("44h_FeedBack_Offset_Angle");
			ret.push_back("45h_Ixt_and_RegenE_Monitor");
			ret.push_back("46h_I_lim_dig_perc");
			ret.push_back("48h_I_Limit_Inuse");
			ret.push_back("49h_T_Motor");
			ret.push_back("4Ah_T_Igbt");
			ret.push_back("4Bh_T_Air_Inside");
			ret.push_back("4Ch_I_Derating_TE");
			ret.push_back("4Dh_Motor_I_max_eff");
			ret.push_back("4Eh_Motor_I_nom_eff");
			ret.push_back("4Fh_Motor_Pole");
			ret.push_back("50h_Ain_in_1_Cutoff");
			ret.push_back("51h_Kern_Mode_State");
			ret.push_back("52h_Status_Mask");
			ret.push_back("53h_Ain_in_2_Cutoff");
			ret.push_back("54h_I1_Actual");
			ret.push_back("55h_I2_Actual");
			ret.push_back("56h_I3_Actual");
			ret.push_back("57h_I_Limit_Inuse_ramp");
			ret.push_back("58h_I_Derating_TD");
			ret.push_back("59h_Motor_Nom");
			ret.push_back("5Ah_Device_Options");
			ret.push_back("5Bh_SpeedControl_Kacc");
			ret.push_back("5Ch_Rotor_Signals");
			ret.push_back("5Dh_N_cmd");
			ret.push_back("5Eh_Speed_Filter");
			ret.push_back("5Fh_I_Actual_Filt");
			ret.push_back("60h_Ain_in_X_Filter");
			ret.push_back("61h_Ixt_Monitor");
			ret.push_back("62h_SerialNumber");
			ret.push_back("63h_FPGA_Status");
			ret.push_back("64h_Device_Mains");
			ret.push_back("65h_Regen_P_R");
			ret.push_back("67h_Device_Type");
			ret.push_back("68h_CAN_ID_Rx");
			ret.push_back("69h_CAN_ID_Tx");
			ret.push_back("6Ah_Pos_Kp");
			ret.push_back("6Bh_Pos_Ti");
			ret.push_back("6Ch_Pos_Td");
			ret.push_back("6Dh_Pos_Actual");
			ret.push_back("6Eh_Pos_Dest");
			ret.push_back("6Fh_Pos_Actual_2");
			ret.push_back("70h_Pos_Err");
			ret.push_back("71h_Pos_TiM");
			ret.push_back("72h_Pos_OffsetRef");
			ret.push_back("73h_CAN_NBT");
			ret.push_back("74h_Pos_Zero_Capture");
			ret.push_back("75h_Pos_Ref_Reso_Edge");
			ret.push_back("76h_Pos_Speed_1");
			ret.push_back("77h_Pos_Speed_2");
			ret.push_back("78h_Pos_Ref_Start");
			ret.push_back("79h_Pos_Tol_Win");
			ret.push_back("7Ah_Pos_Preset");
			ret.push_back("7Bh_Pos_Zero_Offset");
			ret.push_back("7Ch_Pos_ND_Scale");
			ret.push_back("7Dh_Pos_ND_Offset");
			ret.push_back("7Eh_Pos_FB2_Scale_Fac_Ext");
			ret.push_back("7Fh_Pos_Offset_Slack");
			ret.push_back("80h_Pos_Diff_Slack");
			ret.push_back("83h_Func_Para_Read");
			ret.push_back("84h_Func_Para_Write");
			ret.push_back("85h_Func_Special");
			ret.push_back("88h_CAN_ID_2_Rx");
			ret.push_back("89h_CAN_ID_2_Tx");
			ret.push_back("8Ah_Vout");
			ret.push_back("8Bh_V_Ref");
			ret.push_back("8Ch_V_Kp");
			ret.push_back("8Dh_V_Ti");
			ret.push_back("8Eh_Clear_Error_List");
			ret.push_back("8Fh_ErrorWarning_Map");
			ret.push_back("90h_M_setdig");
			ret.push_back("91h_Pos_cmd_int");
			ret.push_back("92h_CAN_Error_BusOff_cntr");
			ret.push_back("93h_CAN_Error_WriteTime_cntr");
			ret.push_back("94h_CAN_Error_RxMsgLost_cntr");
			ret.push_back("95h_CAN_Error_NoAck_cntr");
			ret.push_back("96h_CAN_Error_CRC_Check_cntr");
			ret.push_back("97h_CAN_Error_Bit_cntr");
			ret.push_back("99h_Info_Timer_Diff");
			ret.push_back("9Ah_Temp_DEBUG");
			ret.push_back("A0h_Mout");
			ret.push_back("A1h_Ballast_cntr");
			ret.push_back("A2h_I_Derating_TM");
			ret.push_back("A3h_M_Temp");
			ret.push_back("A4h_Motor_Options");
			ret.push_back("A5h_DC_Bus_MinMax_Lim");
			ret.push_back("A6h_FB_IncPerRot");
			ret.push_back("A7h_FB_Pole");
			ret.push_back("A8h_N_Actual_Filt");
			ret.push_back("A9h_I3_ADC");
			ret.push_back("AAh_I2_ADC");
			ret.push_back("ABh_Logic_Freq");
			ret.push_back("ACh_PWM_1_56");
			ret.push_back("ADh_PWM_2_34");
			ret.push_back("AEh_PWM_3_12");
			ret.push_back("AFh_Timer_Delta");
			ret.push_back("B1h_Motor_Lsq");
			ret.push_back("B2h_Id_Nom");
			ret.push_back("B3h_Motor_Lm");
			ret.push_back("B4h_Motor_Rr");
			ret.push_back("B5h_Id_Min");
			ret.push_back("B6h_Motor_Tr");
			ret.push_back("B8h_Ptr_1_DEBUG");
			ret.push_back("BAh_Ptr_2_DEBUG");
			ret.push_back("BBh_Motor_Lsd");
			ret.push_back("BCh_Motor_Rs");
			ret.push_back("BDh_Motor_Ts");
			ret.push_back("BEh_def_END_1");
			ret.push_back("BFh_def_END_2");
			ret.push_back("C0h_def_DIN_1");
			ret.push_back("C1h_def_DIN_2");
			ret.push_back("C2h_def_OUT_1");
			ret.push_back("C3h_def_OUT_2");
			ret.push_back("C4h_I_max_pk");
			ret.push_back("C5h_I_con_eff");
			ret.push_back("C6h_I_device");
			ret.push_back("C7h_RLim_MRcp_Ramp");
			ret.push_back("C8h_Nmax100perc");
			ret.push_back("C9h_I_xKp");
			ret.push_back("CAh_Bat_Opr_Limits");
			ret.push_back("CBh_I_Kf");
			ret.push_back("CCh_Car_Mode_Status");
			ret.push_back("CDh_Car_Mode_Config");
			ret.push_back("CEh_N_Rpm_MaxInt");
			ret.push_back("D0h_CAN_Timeout");
			ret.push_back("D1h_Var_1");
			ret.push_back("D2h_Var_2");
			ret.push_back("D3h_Var_3");
			ret.push_back("D4h_Var_4");
			ret.push_back("D5h_Ain_in_1");
			ret.push_back("D6h_Ain_in_2");
			ret.push_back("D7h_Ain_in_2_OffsScale");
			ret.push_back("D8h_LogicReadBitsIN_OUT");
			ret.push_back("D9h_I_200perc");
			ret.push_back("DAh_def_OUT_3");
			ret.push_back("DBh_def_OUT_4");
			ret.push_back("DCh_DAC_Source_ID");
			ret.push_back("DEh_DS_DOUT_3");
			ret.push_back("DFh_DS_DOUT_4");
			ret.push_back("E0h_DS_DOUT_1");
			ret.push_back("E1h_DS_DOUT_2");
			ret.push_back("E2h_DS_Rdy_BTB");
			ret.push_back("E3h_DS_GO");
			ret.push_back("E4h_DS_END_1");
			ret.push_back("E5h_DS_END_2");
			ret.push_back("E6h_DS_DIN_1");
			ret.push_back("E7h_DS_DIN_2");
			ret.push_back("E8h_DS_RUN");
			ret.push_back("E9h_DS_I_Fault");
			ret.push_back("EBh_Vdc_Bus");
			ret.push_back("ECh_DS_FB_LossOfSignal");
			ret.push_back("EDh_Dec_Ramps");
			ret.push_back("EEh_V_Shunt");
			ret.push_back("EFh_DS_NoHWFault");
			ret.push_back("F0h_T_peak");
			ret.push_back("F1h_Brake_Delay");
			ret.push_back("F2h_DS_Brake");
			ret.push_back("F3h_DS_Icns");
			ret.push_back("F4h_DS_PosTolerance");
			ret.push_back("F5h_DS_LessN0");
			ret.push_back("F6h_Inverter_Power");
			ret.push_back("F7h_Inverter_Work");
			ret.push_back("F8h_Axis");
			ret.push_back("FBh_Ain_in_1_Calc");
			ret.push_back("FCh_Ain_in_2_Calc");
			ret.push_back("66h_DC_Bus_Voltage");
			ret.push_back("3Ah_M_cmd_ramp");
			ret.push_back("FEh_Subv_SVNRev_Nr");
			return ret;
		}
		if(sgn_name == "def_din_1")
		{
			ret.push_back("_Off_");
			ret.push_back("Ref_and_Limit_Plus");
			ret.push_back("Ref_and_Limit_Minus");
			ret.push_back("Ref_Plus");
			ret.push_back("Limit_Plus");
			ret.push_back("Limit_Minus");
			ret.push_back("Limit_Plus_and_Minus");
			ret.push_back("Cancel_Error_s_");
			ret.push_back("_Start_Ref_Drive");
			ret.push_back("Speed_Ramp_0");
			ret.push_back("_Start_Dest_eq_Var_1");
			ret.push_back("_Start_Dest_eq_Var_2");
			ret.push_back("N_cmd_Reverse");
			ret.push_back("_Preset_Pos_eq_Var_3");
			ret.push_back("_Capture_Var_3_eq_Pos");
			ret.push_back("_Capture_Var_4_eq_Pos");
			ret.push_back("_Switch_Spd_eq_notAin1_Ain2");
			ret.push_back("_Switch_Spd_eq_notVar1_Var2");
			ret.push_back("I_limit_dig_");
			ret.push_back("N_clip_neg_pos_");
			ret.push_back("_Switch_Cmd_eq_notDig_Ana");
			ret.push_back("Speed_Ramp_0_Pos");
			ret.push_back("Handwheel");
			ret.push_back("Brake_Car");
			ret.push_back("Recup_Disabled");
			ret.push_back("Rising_Bank_1_Falling_Bank_0");
			ret.push_back("_Start_Dest_eq_Var_1_2_3_4");
			ret.push_back("_Start_CW_eq_Var_1_2_3_4");
			ret.push_back("Brake_Car_Nr2");
			return ret;
		}
		if(sgn_name == "def_end_1")
		{
			ret.push_back("_Off_");
			ret.push_back("Ref_and_Limit_Plus");
			ret.push_back("Ref_and_Limit_Minus");
			ret.push_back("Ref_Plus");
			ret.push_back("Limit_Plus");
			ret.push_back("Limit_Minus");
			ret.push_back("Limit_Plus_and_Minus");
			ret.push_back("Cancel_Error_s_");
			ret.push_back("_Start_Ref_Drive");
			ret.push_back("Speed_Ramp_0");
			ret.push_back("_Start_Dest_eq_Var_1");
			ret.push_back("_Start_Dest_eq_Var_2");
			ret.push_back("N_cmd_Reverse");
			ret.push_back("_Preset_Pos_eq_Var_3");
			ret.push_back("_Capture_Var_3_eq_Pos");
			ret.push_back("_Capture_Var_4_eq_Pos");
			ret.push_back("_Switch_Spd_eq_notAin1_Ain2");
			ret.push_back("_Switch_Spd_eq_notVar1_Var2");
			ret.push_back("I_limit_dig_");
			ret.push_back("N_clip_neg_pos_");
			ret.push_back("_Switch_Cmd_eq_notDig_Ana");
			ret.push_back("Speed_Ramp_0_Pos");
			ret.push_back("Handwheel");
			ret.push_back("Brake_Car");
			ret.push_back("Recup_Disabled");
			ret.push_back("Rising_Bank_1_Falling_Bank_0");
			ret.push_back("_Start_Dest_eq_Var_1_2_3_4");
			ret.push_back("_Start_CW_eq_Var_1_2_3_4");
			ret.push_back("Brake_Car_Nr2");
			return ret;
		}
		if(sgn_name == "ret_interval")
		{
			ret.push_back("Stop");
			ret.push_back("Single");
			return ret;
		}
		if(sgn_name == "active192")
		{
			ret.push_back("Low");
			ret.push_back("High");
			return ret;
		}
		if(sgn_name == "active190")
		{
			ret.push_back("Low");
			ret.push_back("High");
			return ret;
		}
	}
	if(msg_name == INV_L_RCV)
	{
		if(sgn_name == "rcv_mux")
		{
			ret.push_back("ID_30_N_Actual");
			ret.push_back("ID_35_Acc_Ramps");
			ret.push_back("ID_ED_Dec_Ramps");
			ret.push_back("ID_C7_RLim_MRcp_Ramp");
			ret.push_back("ID_A8_N_Actual_Filt");
			ret.push_back("ID_1B_FW_Nr");
			ret.push_back("ID_67_Device_Type");
			ret.push_back("ID_62_SerialNumber");
			ret.push_back("ID_F8_Axis_Label");
			ret.push_back("ID_C6_I_device");
			ret.push_back("ID_EE_V_Shunt");
			ret.push_back("ID_D9_I_200perc");
			ret.push_back("ID_5A_Device_Options");
			ret.push_back("ID_40_Status_Map");
			ret.push_back("ID_8F_ErrorWarning_Map");
			ret.push_back("ID_D8_LogicReadBitsIN_OUT");
			ret.push_back("ID_D5_Ain_in_1");
			ret.push_back("ID_D6_Ain_in_2");
			ret.push_back("ID_C8_Nmax100perc");
			ret.push_back("ID_31_N_setdig");
			ret.push_back("ID_5D_N_cmd");
			ret.push_back("ID_32_N_cmd_ramp");
			ret.push_back("ID_34_N_Lim");
			ret.push_back("ID_33_N_Error");
			ret.push_back("ID_90_M_setdig");
			ret.push_back("ID_21_Id_setdig");
			ret.push_back("ID_C4_I_max_pk_perc");
			ret.push_back("ID_C5_I_con_eff_perc");
			ret.push_back("ID_4D_Motor_I_max_eff_Arms");
			ret.push_back("ID_4E_Motor_I_nom_eff_Arms");
			ret.push_back("ID_48_I_Limit_Inuse");
			ret.push_back("ID_26_I_cmd");
			ret.push_back("ID_22_I_cmd_ramp");
			ret.push_back("ID_20_I_Actual");
			ret.push_back("ID_5F_I_Actual_Filt");
			ret.push_back("ID_27_Iq_Actual");
			ret.push_back("ID_28_Id_Actual");
			ret.push_back("ID_38_Iq_Error");
			ret.push_back("ID_39_Id_Error");
			ret.push_back("ID_54_I1_Actual");
			ret.push_back("ID_55_I2_Actual");
			ret.push_back("ID_56_I3_Actual");
			ret.push_back("ID_A9_I3_ADC_Value");
			ret.push_back("ID_AA_I2_ADC_Value");
			ret.push_back("ID_29_Vq_Output");
			ret.push_back("ID_2A_Vd_Output");
			ret.push_back("ID_8A_V_Output");
			ret.push_back("ID_49_T_Motor");
			ret.push_back("ID_4A_T_Igbt");
			ret.push_back("ID_4B_T_Air_Inside");
			ret.push_back("ID_EB_DC_Bus_Voltage_Filt");
			ret.push_back("ID_E4_DigInput_END_1");
			ret.push_back("ID_E6_DigInput_DIN_1");
			ret.push_back("ID_E5_DigInput_END_2");
			ret.push_back("ID_E7_DigInput_DIN_2");
			ret.push_back("ID_E8_DigInput_RUN");
			ret.push_back("ID_E0_DigOutput_DOUT_1");
			ret.push_back("ID_E1_DigOutput_DOUT_2");
			ret.push_back("ID_DE_DigOutput_DOUT_3");
			ret.push_back("ID_E2_DigOutput_Rdy_BTB");
			ret.push_back("ID_E9_Error_I_Fault");
			ret.push_back("ID_DF_DigOutput_DOUT_4");
			ret.push_back("ID_46_I_lim_dig_perc");
			ret.push_back("ID_3C_I_Derating_N_perc");
			ret.push_back("ID_58_I_Derating_TD");
			ret.push_back("ID_4C_I_Derating_TE");
			ret.push_back("ID_A2_I_Derating_TM");
			ret.push_back("ID_36_CommandSource");
			ret.push_back("ID_23_Id_Ref");
			ret.push_back("ID_A0_M_outdig");
			ret.push_back("ID_B8_Ptr_1_DEBUG");
			ret.push_back("ID_BA_Ptr_2_DEBUG");
			ret.push_back("ID_9A_Temp_DEBUG");
			ret.push_back("ID_05_Motor_F_nom");
			ret.push_back("ID_06_Motor_V_nom");
			ret.push_back("ID_07_FU_T_dc");
			ret.push_back("ID_08_FU_V_dc");
			ret.push_back("ID_0A_FU_U_min");
			ret.push_back("ID_0B_FU_F_min");
			ret.push_back("ID_0C_FU_V_corner");
			ret.push_back("ID_0D_FU_F_corner");
			ret.push_back("ID_0E_Motor_Cos_Phi");
			ret.push_back("ID_19_PWM_Enum");
			ret.push_back("ID_1A_Calib_Ref_Value");
			ret.push_back("ID_1C_PID_I_Kp");
			ret.push_back("ID_1D_PID_I_Ti");
			ret.push_back("ID_1E_Cutoffdig");
			ret.push_back("ID_1F_I3_Offset");
			ret.push_back("ID_25_I_Delta_Ramp");
			ret.push_back("ID_2B_PID_I_TiM");
			ret.push_back("ID_2C_PID_n_Kp");
			ret.push_back("ID_8D_VoltageControl_Ti");
			ret.push_back("ID_2E_PID_n_Td");
			ret.push_back("ID_2F_Ain_in_1_OffsScale");
			ret.push_back("ID_D7_Ain_in_2_OffsScale");
			ret.push_back("ID_37_DZR_Sequencer_Value");
			ret.push_back("ID_3B_PID_n_TiM");
			ret.push_back("ID_3F_N_Lim_plus");
			ret.push_back("ID_3E_N_Lim_minus");
			ret.push_back("ID_41_Incr_Delta");
			ret.push_back("ID_42_MotorPosition_Mech");
			ret.push_back("ID_43_MotorPosition_Elec");
			ret.push_back("ID_44_FeedBack_Offset_Angle");
			ret.push_back("ID_45_Ixt_and_RegenE_Monitor");
			ret.push_back("ID_4F_Motor_Pole_Number");
			ret.push_back("ID_50_Ain_in_1_Cutoff");
			ret.push_back("ID_11_Control_Status");
			ret.push_back("ID_51_Kern_Mode_State");
			ret.push_back("ID_52_Status_Mask");
			ret.push_back("ID_53_Ain_in_2_Cutoff");
			ret.push_back("ID_57_I_Limit_Inuse_ramp");
			ret.push_back("ID_59_Motor_Nominal_Speed");
			ret.push_back("ID_5B_SpeedControl_Kacc");
			ret.push_back("ID_5C_Rotor_Signals");
			ret.push_back("ID_5E_Speed_Filter");
			ret.push_back("ID_60_Ain_in_X_Filter");
			ret.push_back("ID_61_Ixt_Monitor");
			ret.push_back("ID_63_ECODE_Status");
			ret.push_back("ID_64_Device_Mains_Supply_V");
			ret.push_back("ID_65_Regen_Resistor_P_and_R");
			ret.push_back("ID_68_CAN_ID_Rx");
			ret.push_back("ID_69_CAN_ID_Tx");
			ret.push_back("ID_6A_Pos_PID_Kp");
			ret.push_back("ID_6B_Pos_PID_Ti");
			ret.push_back("ID_6C_Pos_PID_Td");
			ret.push_back("ID_6D_Pos_Actual");
			ret.push_back("ID_6E_Pos_Destination");
			ret.push_back("ID_6F_Pos_Actual_2");
			ret.push_back("ID_70_Pos_Error");
			ret.push_back("ID_71_Pos_PID_TiM");
			ret.push_back("ID_72_Pos_OffsetReference");
			ret.push_back("ID_73_CAN_NBT");
			ret.push_back("ID_74_Pos_Zero_Capture");
			ret.push_back("ID_75_Pos_Ref_Reso_Edge");
			ret.push_back("ID_76_Pos_Calib_Speed_1");
			ret.push_back("ID_77_Pos_Calib_Speed_2");
			ret.push_back("ID_79_Pos_Tol_Window");
			ret.push_back("ID_7A_Pos_Preset_Value");
			ret.push_back("ID_7B_Pos_Zero_Offset");
			ret.push_back("ID_7C_Pos_NDrive_Scale");
			ret.push_back("ID_7D_Pos_NDrive_Offset");
			ret.push_back("ID_7E_Pos_FB2_Scale_Fac_Ext");
			ret.push_back("ID_7F_Pos_Offset_Slack");
			ret.push_back("ID_80_Pos_Diff_Slack");
			ret.push_back("ID_83_Function_Parameter_Read");
			ret.push_back("ID_84_Function_Parameter_Write");
			ret.push_back("ID_85_Function_Special");
			ret.push_back("ID_88_CAN_ID_2_Rx");
			ret.push_back("ID_89_CAN_ID_2_Tx");
			ret.push_back("ID_8B_VoltageControl_Ref");
			ret.push_back("ID_8C_VoltageControl_Kp");
			ret.push_back("ID_2D_PID_n_Ti");
			ret.push_back("ID_8E_Clear_Error_List");
			ret.push_back("ID_91_Pos_cmd_int");
			ret.push_back("ID_92_CAN_Error_BusOff_cntr");
			ret.push_back("ID_93_CAN_Error_WriteTime_cntr");
			ret.push_back("ID_94_ECODE_1stError");
			ret.push_back("ID_95_CAN_Error_NoAck_cntr");
			ret.push_back("ID_96_CAN_Error_CRC_Check_cntr");
			ret.push_back("ID_97_CAN_Error_Bit_cntr");
			ret.push_back("ID_99_Info_Timer_Diff");
			ret.push_back("ID_A1_Ballast_cntr");
			ret.push_back("ID_A3_Motor_Temp_Error_Lim");
			ret.push_back("ID_A4_Motor_Options");
			ret.push_back("ID_A5_Device_DC_Bus_MinMax_Lim");
			ret.push_back("ID_A6_FB_IncrementsPerRot");
			ret.push_back("ID_A7_FB_Pole_Number");
			ret.push_back("ID_AB_Logic_Frequency");
			ret.push_back("ID_AC_PWM_1_56");
			ret.push_back("ID_AD_PWM_2_34");
			ret.push_back("ID_AE_PWM_3_12");
			ret.push_back("ID_AF_Timer_Delta");
			ret.push_back("ID_B1_Motor_L_Sigma_Q");
			ret.push_back("ID_BB_Motor_L_Sigma_D");
			ret.push_back("ID_B2_Id_Nominal");
			ret.push_back("ID_B3_Motor_Magn_Inductance");
			ret.push_back("ID_B4_Motor_Rotor_Resistance");
			ret.push_back("ID_B5_Id_Minimum");
			ret.push_back("ID_B6_Time_Constant_Rotor");
			ret.push_back("ID_BC_Motor_Stator_Resistance");
			ret.push_back("ID_BD_Time_Constant_Stator");
			ret.push_back("ID_BE_LogicDefine_of_END_1");
			ret.push_back("ID_BF_LogicDefine_of_END_2");
			ret.push_back("ID_C0_LogicDefine_of_DIN_1");
			ret.push_back("ID_C1_LogicDefine_of_DIN_2");
			ret.push_back("ID_C2_LogicDefine_of_OUT_1");
			ret.push_back("ID_24_I_Max_Inuse");
			ret.push_back("ID_E3_DigSignal_GO");
			ret.push_back("ID_F2_DigSignal_Brake");
			ret.push_back("ID_F3_DigSignal_Icns");
			ret.push_back("ID_F5_DigSignal_LessN0");
			ret.push_back("ID_F4_DigSignal_Pos_Tolerance");
			ret.push_back("ID_FB_Ain_in_1_Calc");
			ret.push_back("ID_FC_Ain_in_2_Calc");
			ret.push_back("ID_C3_LogicDefine_of_OUT_2");
			ret.push_back("ID_DA_LogicDefine_of_OUT_3");
			ret.push_back("ID_DB_LogicDefine_of_OUT_4");
			ret.push_back("ID_C9_PID_I_xKp");
			ret.push_back("ID_CA_Bat_Opr_Limits");
			ret.push_back("ID_CB_PID_I_Kf");
			ret.push_back("ID_CC_Car_Mode_Status");
			ret.push_back("ID_CD_Car_Mode_Config");
			ret.push_back("ID_CE_N_Rpm_MaxInt");
			ret.push_back("ID_D1_Var_1");
			ret.push_back("ID_D0_CAN_Timeout");
			ret.push_back("ID_D2_Var_2");
			ret.push_back("ID_D3_Var_3");
			ret.push_back("ID_D4_Var_4");
			ret.push_back("ID_DC_DAC_Source_ID");
			ret.push_back("ID_EC_DigSignal_FB_LossOfSig");
			ret.push_back("ID_EF_DigSignal_NoHWFault");
			ret.push_back("ID_F0_Time_I_Peak");
			ret.push_back("ID_F1_Brake_Delay");
			ret.push_back("ID_F6_Inverter_Output_Power");
			ret.push_back("ID_F7_Inverter_Output_Work");
			ret.push_back("ID_0F_FU_Extra");
			ret.push_back("ID_10_Oszi_Channel");
			ret.push_back("ID_12_Oszi_Triger_Level");
			ret.push_back("ID_13_Oszi_Triger_Edge");
			ret.push_back("ID_14_Oszi_Triger_Source");
			ret.push_back("ID_15_Oszi_Source");
			ret.push_back("ID_16_Oszi_Skip");
			ret.push_back("ID_18_Oszi_Run_cmd");
			ret.push_back("ID_17_Oszi_Read_cmd");
			ret.push_back("ID_78_Pos_Ref_Start");
			ret.push_back("ID_66_DC_Bus_Voltage");
			ret.push_back("ID_3A_M_cmd_ramp");
			ret.push_back("ID_97_LogicOutBlock");
			ret.push_back("ID_9B_LogicInBlock");
			ret.push_back("ID_FE_FW_Subv_Revis_Nr");
			return ret;
		}
		if(sgn_name == "def_end_1")
		{
			ret.push_back("_Off_");
			ret.push_back("Ref_and_Limit_Plus");
			ret.push_back("Ref_and_Limit_Minus");
			ret.push_back("Ref_Plus");
			ret.push_back("Limit_Plus");
			ret.push_back("Limit_Minus");
			ret.push_back("Limit_Plus_and_Minus");
			ret.push_back("Cancel_Error_s_");
			ret.push_back("_Start_Ref_Drive");
			ret.push_back("Speed_Ramp_0");
			ret.push_back("_Start_Dest_eq_Var_1");
			ret.push_back("_Start_Dest_eq_Var_2");
			ret.push_back("N_cmd_Reverse");
			ret.push_back("_Preset_Pos_eq_Var_3");
			ret.push_back("_Capture_Var_3_eq_Pos");
			ret.push_back("_Capture_Var_4_eq_Pos");
			ret.push_back("_Switch_Spd_eq_notAin1_Ain2");
			ret.push_back("_Switch_Spd_eq_notVar1_Var2");
			ret.push_back("I_limit_dig_");
			ret.push_back("N_clip_neg_pos_");
			ret.push_back("_Switch_Cmd_eq_notDig_Ana");
			ret.push_back("Speed_Ramp_0_Pos");
			ret.push_back("Handwheel");
			ret.push_back("Brake_Car");
			ret.push_back("Recup_Disabled");
			ret.push_back("Rising_Bank_1_Falling_Bank_0");
			ret.push_back("_Start_Dest_eq_Var_1_2_3_4");
			ret.push_back("_Start_CW_eq_Var_1_2_3_4");
			ret.push_back("Brake_Car_Nr2");
			return ret;
		}
		if(sgn_name == "def_din_1")
		{
			ret.push_back("_Off_");
			ret.push_back("Ref_and_Limit_Plus");
			ret.push_back("Ref_and_Limit_Minus");
			ret.push_back("Ref_Plus");
			ret.push_back("Limit_Plus");
			ret.push_back("Limit_Minus");
			ret.push_back("Limit_Plus_and_Minus");
			ret.push_back("Cancel_Error_s_");
			ret.push_back("_Start_Ref_Drive");
			ret.push_back("Speed_Ramp_0");
			ret.push_back("_Start_Dest_eq_Var_1");
			ret.push_back("_Start_Dest_eq_Var_2");
			ret.push_back("N_cmd_Reverse");
			ret.push_back("_Preset_Pos_eq_Var_3");
			ret.push_back("_Capture_Var_3_eq_Pos");
			ret.push_back("_Capture_Var_4_eq_Pos");
			ret.push_back("_Switch_Spd_eq_notAin1_Ain2");
			ret.push_back("_Switch_Spd_eq_notVar1_Var2");
			ret.push_back("I_limit_dig_");
			ret.push_back("N_clip_neg_pos_");
			ret.push_back("_Switch_Cmd_eq_notDig_Ana");
			ret.push_back("Speed_Ramp_0_Pos");
			ret.push_back("Handwheel");
			ret.push_back("Brake_Car");
			ret.push_back("Recup_Disabled");
			ret.push_back("Rising_Bank_1_Falling_Bank_0");
			ret.push_back("_Start_Dest_eq_Var_1_2_3_4");
			ret.push_back("_Start_CW_eq_Var_1_2_3_4");
			ret.push_back("Brake_Car_Nr2");
			return ret;
		}
		if(sgn_name == "active190")
		{
			ret.push_back("Low");
			ret.push_back("High");
			return ret;
		}
		if(sgn_name == "active192")
		{
			ret.push_back("Low");
			ret.push_back("High");
			return ret;
		}
	}
	if(msg_name == INV_R_SEND)
	{
		if(sgn_name == "send_mux")
		{
			ret.push_back("ID_04_USER_Key");
			ret.push_back("ID_05_Motor_F_nom");
			ret.push_back("ID_07_FU_T_dc");
			ret.push_back("ID_08_FU_V_dc");
			ret.push_back("ID_09_FU_Special");
			ret.push_back("ID_0A_FU_U_min");
			ret.push_back("ID_0B_FU_F_min");
			ret.push_back("ID_0C_FU_V_corner");
			ret.push_back("ID_0D_FU_F_corner");
			ret.push_back("ID_0E_Motor_Cos_Phi");
			ret.push_back("ID_0F_FU_Extra");
			ret.push_back("ID_10_Oszi_Channel");
			ret.push_back("ID_12_Oszi_Triger_Level");
			ret.push_back("ID_13_Oszi_Triger_Edge");
			ret.push_back("ID_14_Oszi_Triger_Source");
			ret.push_back("ID_15_Oszi_Source");
			ret.push_back("ID_16_Oszi_Skip");
			ret.push_back("ID_17_Oszi_Read_cmd");
			ret.push_back("ID_18_Oszi_Run_cmd");
			ret.push_back("ID_1A_Calib_Ref_Value");
			ret.push_back("ID_1C_PID_I_Kp");
			ret.push_back("ID_1D_PID_I_Ti");
			ret.push_back("ID_1E_Cutoffdig");
			ret.push_back("ID_21_Id_setdig");
			ret.push_back("ID_25_I_Delta_Ramp");
			ret.push_back("ID_2B_PID_I_TiM");
			ret.push_back("ID_2C_PID_n_Kp");
			ret.push_back("ID_2D_PID_n_Ti");
			ret.push_back("ID_2E_PID_n_Td");
			ret.push_back("ID_2F_Ain_in_1_OffsScale");
			ret.push_back("ID_31_N_setdig");
			ret.push_back("ID_34_N_Lim");
			ret.push_back("ID_35_Acc_Ramps");
			ret.push_back("ID_36_CommandSource");
			ret.push_back("ID_3B_PID_n_TiM");
			ret.push_back("ID_3C_I_Derating_N_perc");
			ret.push_back("ID_3E_N_Lim_minus");
			ret.push_back("ID_3F_N_Lim_plus");
			ret.push_back("ID_44_FeedBack_Offset_Angle");
			ret.push_back("ID_3D_Read_Cmd");
			ret.push_back("ID_46_I_lim_dig_perc");
			ret.push_back("ID_4C_I_Derating_TE");
			ret.push_back("ID_4D_Motor_I_max_eff_Arms");
			ret.push_back("ID_4E_Motor_I_nom_eff_Arms");
			ret.push_back("ID_4F_Motor_Pole_Number");
			ret.push_back("ID_50_Ain_in_1_Cutoff");
			ret.push_back("ID_51_Kern_Mode_State");
			ret.push_back("ID_53_Ain_in_2_Cutoff");
			ret.push_back("ID_58_I_Derating_TD");
			ret.push_back("ID_59_Motor_Nominal_Speed");
			ret.push_back("ID_5A_Device_Options");
			ret.push_back("ID_5B_PID_n_Kacc");
			ret.push_back("ID_5E_Speed_Filter");
			ret.push_back("ID_60_Ain_in_X_Filter");
			ret.push_back("ID_62_SerialNumber");
			ret.push_back("ID_64_Device_Mains_Supply_V");
			ret.push_back("ID_65_Regen_Resistor_P_and_R");
			ret.push_back("ID_67_Device_Type");
			ret.push_back("ID_68_CAN_ID_Rx");
			ret.push_back("ID_69_CAN_ID_Tx");
			ret.push_back("ID_6A_Pos_PID_Kp");
			ret.push_back("ID_6B_Pos_PID_Ti");
			ret.push_back("ID_6C_Pos_PID_Td");
			ret.push_back("ID_6E_Pos_Destination");
			ret.push_back("ID_71_Pos_PID_TiM");
			ret.push_back("ID_72_Pos_OffsetReference");
			ret.push_back("ID_73_CAN_NBT");
			ret.push_back("ID_75_Pos_Ref_Reso_Edge");
			ret.push_back("ID_76_Pos_Calib_Speed_1");
			ret.push_back("ID_77_Pos_Calib_Speed_2");
			ret.push_back("ID_79_Pos_Tol_Window");
			ret.push_back("ID_7A_Pos_Preset_Value");
			ret.push_back("ID_7C_Pos_NDrive_Scale");
			ret.push_back("ID_7D_Pos_NDrive_Offset");
			ret.push_back("ID_7E_Pos_FB2_Scale_Fac_Ext");
			ret.push_back("ID_7F_Pos_Offset_Slack");
			ret.push_back("ID_80_Pos_Diff_Slack");
			ret.push_back("ID_83_Function_Parameter_Read");
			ret.push_back("ID_84_Function_Parameter_Write");
			ret.push_back("ID_85_Function_Special");
			ret.push_back("ID_88_CAN_ID_2_Rx");
			ret.push_back("ID_89_CAN_ID_2_Tx");
			ret.push_back("ID_8B_VoltageControl_Ref");
			ret.push_back("ID_8C_VoltageControl_Kp");
			ret.push_back("ID_8D_VoltageControl_Ti");
			ret.push_back("ID_8E_Clear_Error_List");
			ret.push_back("ID_90_M_setdig");
			ret.push_back("ID_A2_I_Derating_TM");
			ret.push_back("ID_A3_Motor_Temp_Error_Lim");
			ret.push_back("ID_A4_Motor_Options");
			ret.push_back("ID_A5_Device_DC_Bus_MinMax_Lim");
			ret.push_back("ID_A6_FB_IncrementsPerRot");
			ret.push_back("ID_A7_FB_Pole_Number");
			ret.push_back("ID_B1_Motor_L_Sigma_Q");
			ret.push_back("ID_B2_Id_Nominal");
			ret.push_back("ID_B3_Motor_Magn_Inductance");
			ret.push_back("ID_B4_Motor_Rotor_Resistance");
			ret.push_back("ID_B5_Id_Minimum");
			ret.push_back("ID_B6_Time_Constant_Rotor");
			ret.push_back("ID_BB_Motor_L_Sigma_D");
			ret.push_back("ID_BC_Motor_Stator_Resistance");
			ret.push_back("ID_BD_Time_Constant_Stator");
			ret.push_back("ID_BE_LogicDefine_of_END_1");
			ret.push_back("ID_BF_LogicDefine_of_END_2");
			ret.push_back("ID_C0_LogicDefine_of_DIN_1");
			ret.push_back("ID_C1_LogicDefine_of_DIN_2");
			ret.push_back("ID_C2_LogicDefine_of_OUT_1");
			ret.push_back("ID_C3_LogicDefine_of_OUT_2");
			ret.push_back("ID_DA_LogicDefine_of_OUT_3");
			ret.push_back("ID_DB_LogicDefine_of_OUT_4");
			ret.push_back("ID_C4_I_max_pk_perc");
			ret.push_back("ID_C5_I_con_eff_perc");
			ret.push_back("ID_C6_I_device");
			ret.push_back("ID_C7_RLim_MRcp_Ramp");
			ret.push_back("ID_C8_Nmax100perc");
			ret.push_back("ID_C9_CurrentControl_xKp");
			ret.push_back("ID_CA_Bat_Opr_Limits");
			ret.push_back("ID_CB_PID_I_Kf");
			ret.push_back("ID_CD_Car_Mode_Config");
			ret.push_back("ID_D0_CAN_Timeout");
			ret.push_back("ID_D1_Var_1");
			ret.push_back("ID_D2_Var_2");
			ret.push_back("ID_D3_Var_3");
			ret.push_back("ID_D4_Var_4");
			ret.push_back("ID_D7_Ain_in_2_OffsScale");
			ret.push_back("ID_DC_DAC_Source_ID");
			ret.push_back("ID_ED_Dec_Ramps");
			ret.push_back("ID_EE_V_Shunt");
			ret.push_back("ID_F0_Time_I_Peak");
			ret.push_back("ID_F1_Brake_Delay");
			ret.push_back("ID_F8_Axis_Label");
			return ret;
		}
		if(sgn_name == "read_id")
		{
			ret.push_back("05h_Motor_F_nom");
			ret.push_back("06h_Motor_V_nom");
			ret.push_back("07h_FU_T_dc");
			ret.push_back("08h_FU_V_dc");
			ret.push_back("09h_FU_Special");
			ret.push_back("0Ah_FU_U_min");
			ret.push_back("0Bh_FU_F_min");
			ret.push_back("0Ch_FU_V_corner");
			ret.push_back("0Dh_FU_F_corner");
			ret.push_back("0Eh_Motor_Cos_Phi");
			ret.push_back("0Fh_FU_Extra");
			ret.push_back("10h_Oszi_Channel");
			ret.push_back("11h_Control_Status");
			ret.push_back("12h_Oszi_Triger_Level");
			ret.push_back("13h_Oszi_Triger_Edge");
			ret.push_back("14h_Oszi_Triger_Source");
			ret.push_back("15h_Oszi_Source");
			ret.push_back("16h_Oszi_Skip");
			ret.push_back("17h_Oszi_Read_cmd");
			ret.push_back("18h_Oszi_Run_cmd");
			ret.push_back("19h_PWM_Enum");
			ret.push_back("1Ah_Calib_Ref_Value");
			ret.push_back("1Bh_FW_Nr");
			ret.push_back("1Ch_I_Kp");
			ret.push_back("1Dh_I_Ti");
			ret.push_back("1Eh_Cutoffdig");
			ret.push_back("1Fh_I3_Offset");
			ret.push_back("20h_I_Actual");
			ret.push_back("21h_Id_setdig");
			ret.push_back("22h_I_cmd_ramp");
			ret.push_back("23h_Id_Ref");
			ret.push_back("24h_I_Max_Inuse");
			ret.push_back("25h_I_Delta_Ramp");
			ret.push_back("26h_I_cmd");
			ret.push_back("27h_Iq_Actual");
			ret.push_back("28h_Id_Actual");
			ret.push_back("29h_Vq_Output");
			ret.push_back("2Ah_Vd_Output");
			ret.push_back("2Bh_I_TiM");
			ret.push_back("2Ch_n_Kp");
			ret.push_back("2Dh_n_Ti");
			ret.push_back("2Eh_n_Td");
			ret.push_back("2Fh_Ain_in_1_OffsScale");
			ret.push_back("30h_N_Actual");
			ret.push_back("31h_N_setdig");
			ret.push_back("32h_N_cmd_ramp");
			ret.push_back("33h_N_Error");
			ret.push_back("34h_N_Lim");
			ret.push_back("35h_Acc_Ramps");
			ret.push_back("36h_CommandSource");
			ret.push_back("37h_DZR_Sequencer_Value");
			ret.push_back("38h_Iq_Error");
			ret.push_back("39h_Id_Error");
			ret.push_back("3Bh_n_TiM");
			ret.push_back("3Ch_I_Derating_N_perc");
			ret.push_back("3Eh_N_Lim_minus");
			ret.push_back("3Fh_N_Lim_plus");
			ret.push_back("40h_Status_Map");
			ret.push_back("41h_Incr_Delta");
			ret.push_back("42h_MotorPosition_Mech");
			ret.push_back("43h_MotorPosition_Elec");
			ret.push_back("44h_FeedBack_Offset_Angle");
			ret.push_back("45h_Ixt_and_RegenE_Monitor");
			ret.push_back("46h_I_lim_dig_perc");
			ret.push_back("48h_I_Limit_Inuse");
			ret.push_back("49h_T_Motor");
			ret.push_back("4Ah_T_Igbt");
			ret.push_back("4Bh_T_Air_Inside");
			ret.push_back("4Ch_I_Derating_TE");
			ret.push_back("4Dh_Motor_I_max_eff");
			ret.push_back("4Eh_Motor_I_nom_eff");
			ret.push_back("4Fh_Motor_Pole");
			ret.push_back("50h_Ain_in_1_Cutoff");
			ret.push_back("51h_Kern_Mode_State");
			ret.push_back("52h_Status_Mask");
			ret.push_back("53h_Ain_in_2_Cutoff");
			ret.push_back("54h_I1_Actual");
			ret.push_back("55h_I2_Actual");
			ret.push_back("56h_I3_Actual");
			ret.push_back("57h_I_Limit_Inuse_ramp");
			ret.push_back("58h_I_Derating_TD");
			ret.push_back("59h_Motor_Nom");
			ret.push_back("5Ah_Device_Options");
			ret.push_back("5Bh_SpeedControl_Kacc");
			ret.push_back("5Ch_Rotor_Signals");
			ret.push_back("5Dh_N_cmd");
			ret.push_back("5Eh_Speed_Filter");
			ret.push_back("5Fh_I_Actual_Filt");
			ret.push_back("60h_Ain_in_X_Filter");
			ret.push_back("61h_Ixt_Monitor");
			ret.push_back("62h_SerialNumber");
			ret.push_back("63h_FPGA_Status");
			ret.push_back("64h_Device_Mains");
			ret.push_back("65h_Regen_P_R");
			ret.push_back("67h_Device_Type");
			ret.push_back("68h_CAN_ID_Rx");
			ret.push_back("69h_CAN_ID_Tx");
			ret.push_back("6Ah_Pos_Kp");
			ret.push_back("6Bh_Pos_Ti");
			ret.push_back("6Ch_Pos_Td");
			ret.push_back("6Dh_Pos_Actual");
			ret.push_back("6Eh_Pos_Dest");
			ret.push_back("6Fh_Pos_Actual_2");
			ret.push_back("70h_Pos_Err");
			ret.push_back("71h_Pos_TiM");
			ret.push_back("72h_Pos_OffsetRef");
			ret.push_back("73h_CAN_NBT");
			ret.push_back("74h_Pos_Zero_Capture");
			ret.push_back("75h_Pos_Ref_Reso_Edge");
			ret.push_back("76h_Pos_Speed_1");
			ret.push_back("77h_Pos_Speed_2");
			ret.push_back("78h_Pos_Ref_Start");
			ret.push_back("79h_Pos_Tol_Win");
			ret.push_back("7Ah_Pos_Preset");
			ret.push_back("7Bh_Pos_Zero_Offset");
			ret.push_back("7Ch_Pos_ND_Scale");
			ret.push_back("7Dh_Pos_ND_Offset");
			ret.push_back("7Eh_Pos_FB2_Scale_Fac_Ext");
			ret.push_back("7Fh_Pos_Offset_Slack");
			ret.push_back("80h_Pos_Diff_Slack");
			ret.push_back("83h_Func_Para_Read");
			ret.push_back("84h_Func_Para_Write");
			ret.push_back("85h_Func_Special");
			ret.push_back("88h_CAN_ID_2_Rx");
			ret.push_back("89h_CAN_ID_2_Tx");
			ret.push_back("8Ah_Vout");
			ret.push_back("8Bh_V_Ref");
			ret.push_back("8Ch_V_Kp");
			ret.push_back("8Dh_V_Ti");
			ret.push_back("8Eh_Clear_Error_List");
			ret.push_back("8Fh_ErrorWarning_Map");
			ret.push_back("90h_M_setdig");
			ret.push_back("91h_Pos_cmd_int");
			ret.push_back("92h_CAN_Error_BusOff_cntr");
			ret.push_back("93h_CAN_Error_WriteTime_cntr");
			ret.push_back("94h_CAN_Error_RxMsgLost_cntr");
			ret.push_back("95h_CAN_Error_NoAck_cntr");
			ret.push_back("96h_CAN_Error_CRC_Check_cntr");
			ret.push_back("97h_CAN_Error_Bit_cntr");
			ret.push_back("99h_Info_Timer_Diff");
			ret.push_back("9Ah_Temp_DEBUG");
			ret.push_back("A0h_Mout");
			ret.push_back("A1h_Ballast_cntr");
			ret.push_back("A2h_I_Derating_TM");
			ret.push_back("A3h_M_Temp");
			ret.push_back("A4h_Motor_Options");
			ret.push_back("A5h_DC_Bus_MinMax_Lim");
			ret.push_back("A6h_FB_IncPerRot");
			ret.push_back("A7h_FB_Pole");
			ret.push_back("A8h_N_Actual_Filt");
			ret.push_back("A9h_I3_ADC");
			ret.push_back("AAh_I2_ADC");
			ret.push_back("ABh_Logic_Freq");
			ret.push_back("ACh_PWM_1_56");
			ret.push_back("ADh_PWM_2_34");
			ret.push_back("AEh_PWM_3_12");
			ret.push_back("AFh_Timer_Delta");
			ret.push_back("B1h_Motor_Lsq");
			ret.push_back("B2h_Id_Nom");
			ret.push_back("B3h_Motor_Lm");
			ret.push_back("B4h_Motor_Rr");
			ret.push_back("B5h_Id_Min");
			ret.push_back("B6h_Motor_Tr");
			ret.push_back("B8h_Ptr_1_DEBUG");
			ret.push_back("BAh_Ptr_2_DEBUG");
			ret.push_back("BBh_Motor_Lsd");
			ret.push_back("BCh_Motor_Rs");
			ret.push_back("BDh_Motor_Ts");
			ret.push_back("BEh_def_END_1");
			ret.push_back("BFh_def_END_2");
			ret.push_back("C0h_def_DIN_1");
			ret.push_back("C1h_def_DIN_2");
			ret.push_back("C2h_def_OUT_1");
			ret.push_back("C3h_def_OUT_2");
			ret.push_back("C4h_I_max_pk");
			ret.push_back("C5h_I_con_eff");
			ret.push_back("C6h_I_device");
			ret.push_back("C7h_RLim_MRcp_Ramp");
			ret.push_back("C8h_Nmax100perc");
			ret.push_back("C9h_I_xKp");
			ret.push_back("CAh_Bat_Opr_Limits");
			ret.push_back("CBh_I_Kf");
			ret.push_back("CCh_Car_Mode_Status");
			ret.push_back("CDh_Car_Mode_Config");
			ret.push_back("CEh_N_Rpm_MaxInt");
			ret.push_back("D0h_CAN_Timeout");
			ret.push_back("D1h_Var_1");
			ret.push_back("D2h_Var_2");
			ret.push_back("D3h_Var_3");
			ret.push_back("D4h_Var_4");
			ret.push_back("D5h_Ain_in_1");
			ret.push_back("D6h_Ain_in_2");
			ret.push_back("D7h_Ain_in_2_OffsScale");
			ret.push_back("D8h_LogicReadBitsIN_OUT");
			ret.push_back("D9h_I_200perc");
			ret.push_back("DAh_def_OUT_3");
			ret.push_back("DBh_def_OUT_4");
			ret.push_back("DCh_DAC_Source_ID");
			ret.push_back("DEh_DS_DOUT_3");
			ret.push_back("DFh_DS_DOUT_4");
			ret.push_back("E0h_DS_DOUT_1");
			ret.push_back("E1h_DS_DOUT_2");
			ret.push_back("E2h_DS_Rdy_BTB");
			ret.push_back("E3h_DS_GO");
			ret.push_back("E4h_DS_END_1");
			ret.push_back("E5h_DS_END_2");
			ret.push_back("E6h_DS_DIN_1");
			ret.push_back("E7h_DS_DIN_2");
			ret.push_back("E8h_DS_RUN");
			ret.push_back("E9h_DS_I_Fault");
			ret.push_back("EBh_Vdc_Bus");
			ret.push_back("ECh_DS_FB_LossOfSignal");
			ret.push_back("EDh_Dec_Ramps");
			ret.push_back("EEh_V_Shunt");
			ret.push_back("EFh_DS_NoHWFault");
			ret.push_back("F0h_T_peak");
			ret.push_back("F1h_Brake_Delay");
			ret.push_back("F2h_DS_Brake");
			ret.push_back("F3h_DS_Icns");
			ret.push_back("F4h_DS_PosTolerance");
			ret.push_back("F5h_DS_LessN0");
			ret.push_back("F6h_Inverter_Power");
			ret.push_back("F7h_Inverter_Work");
			ret.push_back("F8h_Axis");
			ret.push_back("FBh_Ain_in_1_Calc");
			ret.push_back("FCh_Ain_in_2_Calc");
			ret.push_back("66h_DC_Bus_Voltage");
			ret.push_back("3Ah_M_cmd_ramp");
			ret.push_back("FEh_Subv_SVNRev_Nr");
			return ret;
		}
		if(sgn_name == "def_din_1")
		{
			ret.push_back("_Off_");
			ret.push_back("Ref_and_Limit_Plus");
			ret.push_back("Ref_and_Limit_Minus");
			ret.push_back("Ref_Plus");
			ret.push_back("Limit_Plus");
			ret.push_back("Limit_Minus");
			ret.push_back("Limit_Plus_and_Minus");
			ret.push_back("Cancel_Error_s_");
			ret.push_back("_Start_Ref_Drive");
			ret.push_back("Speed_Ramp_0");
			ret.push_back("_Start_Dest_eq_Var_1");
			ret.push_back("_Start_Dest_eq_Var_2");
			ret.push_back("N_cmd_Reverse");
			ret.push_back("_Preset_Pos_eq_Var_3");
			ret.push_back("_Capture_Var_3_eq_Pos");
			ret.push_back("_Capture_Var_4_eq_Pos");
			ret.push_back("_Switch_Spd_eq_notAin1_Ain2");
			ret.push_back("_Switch_Spd_eq_notVar1_Var2");
			ret.push_back("I_limit_dig_");
			ret.push_back("N_clip_neg_pos_");
			ret.push_back("_Switch_Cmd_eq_notDig_Ana");
			ret.push_back("Speed_Ramp_0_Pos");
			ret.push_back("Handwheel");
			ret.push_back("Brake_Car");
			ret.push_back("Recup_Disabled");
			ret.push_back("Rising_Bank_1_Falling_Bank_0");
			ret.push_back("_Start_Dest_eq_Var_1_2_3_4");
			ret.push_back("_Start_CW_eq_Var_1_2_3_4");
			ret.push_back("Brake_Car_Nr2");
			return ret;
		}
		if(sgn_name == "def_end_1")
		{
			ret.push_back("_Off_");
			ret.push_back("Ref_and_Limit_Plus");
			ret.push_back("Ref_and_Limit_Minus");
			ret.push_back("Ref_Plus");
			ret.push_back("Limit_Plus");
			ret.push_back("Limit_Minus");
			ret.push_back("Limit_Plus_and_Minus");
			ret.push_back("Cancel_Error_s_");
			ret.push_back("_Start_Ref_Drive");
			ret.push_back("Speed_Ramp_0");
			ret.push_back("_Start_Dest_eq_Var_1");
			ret.push_back("_Start_Dest_eq_Var_2");
			ret.push_back("N_cmd_Reverse");
			ret.push_back("_Preset_Pos_eq_Var_3");
			ret.push_back("_Capture_Var_3_eq_Pos");
			ret.push_back("_Capture_Var_4_eq_Pos");
			ret.push_back("_Switch_Spd_eq_notAin1_Ain2");
			ret.push_back("_Switch_Spd_eq_notVar1_Var2");
			ret.push_back("I_limit_dig_");
			ret.push_back("N_clip_neg_pos_");
			ret.push_back("_Switch_Cmd_eq_notDig_Ana");
			ret.push_back("Speed_Ramp_0_Pos");
			ret.push_back("Handwheel");
			ret.push_back("Brake_Car");
			ret.push_back("Recup_Disabled");
			ret.push_back("Rising_Bank_1_Falling_Bank_0");
			ret.push_back("_Start_Dest_eq_Var_1_2_3_4");
			ret.push_back("_Start_CW_eq_Var_1_2_3_4");
			ret.push_back("Brake_Car_Nr2");
			return ret;
		}
		if(sgn_name == "ret_interval")
		{
			ret.push_back("Stop");
			ret.push_back("Single");
			return ret;
		}
		if(sgn_name == "active192")
		{
			ret.push_back("Low");
			ret.push_back("High");
			return ret;
		}
		if(sgn_name == "active190")
		{
			ret.push_back("Low");
			ret.push_back("High");
			return ret;
		}
	}
	if(msg_name == INV_R_RCV)
	{
		if(sgn_name == "rcv_mux")
		{
			ret.push_back("ID_30_N_Actual");
			ret.push_back("ID_35_Acc_Ramps");
			ret.push_back("ID_ED_Dec_Ramps");
			ret.push_back("ID_C7_RLim_MRcp_Ramp");
			ret.push_back("ID_A8_N_Actual_Filt");
			ret.push_back("ID_1B_FW_Nr");
			ret.push_back("ID_67_Device_Type");
			ret.push_back("ID_62_SerialNumber");
			ret.push_back("ID_F8_Axis_Label");
			ret.push_back("ID_C6_I_device");
			ret.push_back("ID_EE_V_Shunt");
			ret.push_back("ID_D9_I_200perc");
			ret.push_back("ID_5A_Device_Options");
			ret.push_back("ID_40_Status_Map");
			ret.push_back("ID_8F_ErrorWarning_Map");
			ret.push_back("ID_D8_LogicReadBitsIN_OUT");
			ret.push_back("ID_D5_Ain_in_1");
			ret.push_back("ID_D6_Ain_in_2");
			ret.push_back("ID_C8_Nmax100perc");
			ret.push_back("ID_31_N_setdig");
			ret.push_back("ID_5D_N_cmd");
			ret.push_back("ID_32_N_cmd_ramp");
			ret.push_back("ID_34_N_Lim");
			ret.push_back("ID_33_N_Error");
			ret.push_back("ID_90_M_setdig");
			ret.push_back("ID_21_Id_setdig");
			ret.push_back("ID_C4_I_max_pk_perc");
			ret.push_back("ID_C5_I_con_eff_perc");
			ret.push_back("ID_4D_Motor_I_max_eff_Arms");
			ret.push_back("ID_4E_Motor_I_nom_eff_Arms");
			ret.push_back("ID_48_I_Limit_Inuse");
			ret.push_back("ID_26_I_cmd");
			ret.push_back("ID_22_I_cmd_ramp");
			ret.push_back("ID_20_I_Actual");
			ret.push_back("ID_5F_I_Actual_Filt");
			ret.push_back("ID_27_Iq_Actual");
			ret.push_back("ID_28_Id_Actual");
			ret.push_back("ID_38_Iq_Error");
			ret.push_back("ID_39_Id_Error");
			ret.push_back("ID_54_I1_Actual");
			ret.push_back("ID_55_I2_Actual");
			ret.push_back("ID_56_I3_Actual");
			ret.push_back("ID_A9_I3_ADC_Value");
			ret.push_back("ID_AA_I2_ADC_Value");
			ret.push_back("ID_29_Vq_Output");
			ret.push_back("ID_2A_Vd_Output");
			ret.push_back("ID_8A_V_Output");
			ret.push_back("ID_49_T_Motor");
			ret.push_back("ID_4A_T_Igbt");
			ret.push_back("ID_4B_T_Air_Inside");
			ret.push_back("ID_EB_DC_Bus_Voltage_Filt");
			ret.push_back("ID_E4_DigInput_END_1");
			ret.push_back("ID_E6_DigInput_DIN_1");
			ret.push_back("ID_E5_DigInput_END_2");
			ret.push_back("ID_E7_DigInput_DIN_2");
			ret.push_back("ID_E8_DigInput_RUN");
			ret.push_back("ID_E0_DigOutput_DOUT_1");
			ret.push_back("ID_E1_DigOutput_DOUT_2");
			ret.push_back("ID_DE_DigOutput_DOUT_3");
			ret.push_back("ID_E2_DigOutput_Rdy_BTB");
			ret.push_back("ID_E9_Error_I_Fault");
			ret.push_back("ID_DF_DigOutput_DOUT_4");
			ret.push_back("ID_46_I_lim_dig_perc");
			ret.push_back("ID_3C_I_Derating_N_perc");
			ret.push_back("ID_58_I_Derating_TD");
			ret.push_back("ID_4C_I_Derating_TE");
			ret.push_back("ID_A2_I_Derating_TM");
			ret.push_back("ID_36_CommandSource");
			ret.push_back("ID_23_Id_Ref");
			ret.push_back("ID_A0_M_outdig");
			ret.push_back("ID_B8_Ptr_1_DEBUG");
			ret.push_back("ID_BA_Ptr_2_DEBUG");
			ret.push_back("ID_9A_Temp_DEBUG");
			ret.push_back("ID_05_Motor_F_nom");
			ret.push_back("ID_06_Motor_V_nom");
			ret.push_back("ID_07_FU_T_dc");
			ret.push_back("ID_08_FU_V_dc");
			ret.push_back("ID_0A_FU_U_min");
			ret.push_back("ID_0B_FU_F_min");
			ret.push_back("ID_0C_FU_V_corner");
			ret.push_back("ID_0D_FU_F_corner");
			ret.push_back("ID_0E_Motor_Cos_Phi");
			ret.push_back("ID_19_PWM_Enum");
			ret.push_back("ID_1A_Calib_Ref_Value");
			ret.push_back("ID_1C_PID_I_Kp");
			ret.push_back("ID_1D_PID_I_Ti");
			ret.push_back("ID_1E_Cutoffdig");
			ret.push_back("ID_1F_I3_Offset");
			ret.push_back("ID_25_I_Delta_Ramp");
			ret.push_back("ID_2B_PID_I_TiM");
			ret.push_back("ID_2C_PID_n_Kp");
			ret.push_back("ID_8D_VoltageControl_Ti");
			ret.push_back("ID_2E_PID_n_Td");
			ret.push_back("ID_2F_Ain_in_1_OffsScale");
			ret.push_back("ID_D7_Ain_in_2_OffsScale");
			ret.push_back("ID_37_DZR_Sequencer_Value");
			ret.push_back("ID_3B_PID_n_TiM");
			ret.push_back("ID_3F_N_Lim_plus");
			ret.push_back("ID_3E_N_Lim_minus");
			ret.push_back("ID_41_Incr_Delta");
			ret.push_back("ID_42_MotorPosition_Mech");
			ret.push_back("ID_43_MotorPosition_Elec");
			ret.push_back("ID_44_FeedBack_Offset_Angle");
			ret.push_back("ID_45_Ixt_and_RegenE_Monitor");
			ret.push_back("ID_4F_Motor_Pole_Number");
			ret.push_back("ID_50_Ain_in_1_Cutoff");
			ret.push_back("ID_11_Control_Status");
			ret.push_back("ID_51_Kern_Mode_State");
			ret.push_back("ID_52_Status_Mask");
			ret.push_back("ID_53_Ain_in_2_Cutoff");
			ret.push_back("ID_57_I_Limit_Inuse_ramp");
			ret.push_back("ID_59_Motor_Nominal_Speed");
			ret.push_back("ID_5B_SpeedControl_Kacc");
			ret.push_back("ID_5C_Rotor_Signals");
			ret.push_back("ID_5E_Speed_Filter");
			ret.push_back("ID_60_Ain_in_X_Filter");
			ret.push_back("ID_61_Ixt_Monitor");
			ret.push_back("ID_63_ECODE_Status");
			ret.push_back("ID_64_Device_Mains_Supply_V");
			ret.push_back("ID_65_Regen_Resistor_P_and_R");
			ret.push_back("ID_68_CAN_ID_Rx");
			ret.push_back("ID_69_CAN_ID_Tx");
			ret.push_back("ID_6A_Pos_PID_Kp");
			ret.push_back("ID_6B_Pos_PID_Ti");
			ret.push_back("ID_6C_Pos_PID_Td");
			ret.push_back("ID_6D_Pos_Actual");
			ret.push_back("ID_6E_Pos_Destination");
			ret.push_back("ID_6F_Pos_Actual_2");
			ret.push_back("ID_70_Pos_Error");
			ret.push_back("ID_71_Pos_PID_TiM");
			ret.push_back("ID_72_Pos_OffsetReference");
			ret.push_back("ID_73_CAN_NBT");
			ret.push_back("ID_74_Pos_Zero_Capture");
			ret.push_back("ID_75_Pos_Ref_Reso_Edge");
			ret.push_back("ID_76_Pos_Calib_Speed_1");
			ret.push_back("ID_77_Pos_Calib_Speed_2");
			ret.push_back("ID_79_Pos_Tol_Window");
			ret.push_back("ID_7A_Pos_Preset_Value");
			ret.push_back("ID_7B_Pos_Zero_Offset");
			ret.push_back("ID_7C_Pos_NDrive_Scale");
			ret.push_back("ID_7D_Pos_NDrive_Offset");
			ret.push_back("ID_7E_Pos_FB2_Scale_Fac_Ext");
			ret.push_back("ID_7F_Pos_Offset_Slack");
			ret.push_back("ID_80_Pos_Diff_Slack");
			ret.push_back("ID_83_Function_Parameter_Read");
			ret.push_back("ID_84_Function_Parameter_Write");
			ret.push_back("ID_85_Function_Special");
			ret.push_back("ID_88_CAN_ID_2_Rx");
			ret.push_back("ID_89_CAN_ID_2_Tx");
			ret.push_back("ID_8B_VoltageControl_Ref");
			ret.push_back("ID_8C_VoltageControl_Kp");
			ret.push_back("ID_2D_PID_n_Ti");
			ret.push_back("ID_8E_Clear_Error_List");
			ret.push_back("ID_91_Pos_cmd_int");
			ret.push_back("ID_92_CAN_Error_BusOff_cntr");
			ret.push_back("ID_93_CAN_Error_WriteTime_cntr");
			ret.push_back("ID_94_ECODE_1stError");
			ret.push_back("ID_95_CAN_Error_NoAck_cntr");
			ret.push_back("ID_96_CAN_Error_CRC_Check_cntr");
			ret.push_back("ID_97_CAN_Error_Bit_cntr");
			ret.push_back("ID_99_Info_Timer_Diff");
			ret.push_back("ID_A1_Ballast_cntr");
			ret.push_back("ID_A3_Motor_Temp_Error_Lim");
			ret.push_back("ID_A4_Motor_Options");
			ret.push_back("ID_A5_Device_DC_Bus_MinMax_Lim");
			ret.push_back("ID_A6_FB_IncrementsPerRot");
			ret.push_back("ID_A7_FB_Pole_Number");
			ret.push_back("ID_AB_Logic_Frequency");
			ret.push_back("ID_AC_PWM_1_56");
			ret.push_back("ID_AD_PWM_2_34");
			ret.push_back("ID_AE_PWM_3_12");
			ret.push_back("ID_AF_Timer_Delta");
			ret.push_back("ID_B1_Motor_L_Sigma_Q");
			ret.push_back("ID_BB_Motor_L_Sigma_D");
			ret.push_back("ID_B2_Id_Nominal");
			ret.push_back("ID_B3_Motor_Magn_Inductance");
			ret.push_back("ID_B4_Motor_Rotor_Resistance");
			ret.push_back("ID_B5_Id_Minimum");
			ret.push_back("ID_B6_Time_Constant_Rotor");
			ret.push_back("ID_BC_Motor_Stator_Resistance");
			ret.push_back("ID_BD_Time_Constant_Stator");
			ret.push_back("ID_BE_LogicDefine_of_END_1");
			ret.push_back("ID_BF_LogicDefine_of_END_2");
			ret.push_back("ID_C0_LogicDefine_of_DIN_1");
			ret.push_back("ID_C1_LogicDefine_of_DIN_2");
			ret.push_back("ID_C2_LogicDefine_of_OUT_1");
			ret.push_back("ID_24_I_Max_Inuse");
			ret.push_back("ID_E3_DigSignal_GO");
			ret.push_back("ID_F2_DigSignal_Brake");
			ret.push_back("ID_F3_DigSignal_Icns");
			ret.push_back("ID_F5_DigSignal_LessN0");
			ret.push_back("ID_F4_DigSignal_Pos_Tolerance");
			ret.push_back("ID_FB_Ain_in_1_Calc");
			ret.push_back("ID_FC_Ain_in_2_Calc");
			ret.push_back("ID_C3_LogicDefine_of_OUT_2");
			ret.push_back("ID_DA_LogicDefine_of_OUT_3");
			ret.push_back("ID_DB_LogicDefine_of_OUT_4");
			ret.push_back("ID_C9_PID_I_xKp");
			ret.push_back("ID_CA_Bat_Opr_Limits");
			ret.push_back("ID_CB_PID_I_Kf");
			ret.push_back("ID_CC_Car_Mode_Status");
			ret.push_back("ID_CD_Car_Mode_Config");
			ret.push_back("ID_CE_N_Rpm_MaxInt");
			ret.push_back("ID_D1_Var_1");
			ret.push_back("ID_D0_CAN_Timeout");
			ret.push_back("ID_D2_Var_2");
			ret.push_back("ID_D3_Var_3");
			ret.push_back("ID_D4_Var_4");
			ret.push_back("ID_DC_DAC_Source_ID");
			ret.push_back("ID_EC_DigSignal_FB_LossOfSig");
			ret.push_back("ID_EF_DigSignal_NoHWFault");
			ret.push_back("ID_F0_Time_I_Peak");
			ret.push_back("ID_F1_Brake_Delay");
			ret.push_back("ID_F6_Inverter_Output_Power");
			ret.push_back("ID_F7_Inverter_Output_Work");
			ret.push_back("ID_0F_FU_Extra");
			ret.push_back("ID_10_Oszi_Channel");
			ret.push_back("ID_12_Oszi_Triger_Level");
			ret.push_back("ID_13_Oszi_Triger_Edge");
			ret.push_back("ID_14_Oszi_Triger_Source");
			ret.push_back("ID_15_Oszi_Source");
			ret.push_back("ID_16_Oszi_Skip");
			ret.push_back("ID_18_Oszi_Run_cmd");
			ret.push_back("ID_17_Oszi_Read_cmd");
			ret.push_back("ID_78_Pos_Ref_Start");
			ret.push_back("ID_66_DC_Bus_Voltage");
			ret.push_back("ID_3A_M_cmd_ramp");
			ret.push_back("ID_97_LogicOutBlock");
			ret.push_back("ID_9B_LogicInBlock");
			ret.push_back("ID_FE_FW_Subv_Revis_Nr");
			return ret;
		}
		if(sgn_name == "def_end_1")
		{
			ret.push_back("_Off_");
			ret.push_back("Ref_and_Limit_Plus");
			ret.push_back("Ref_and_Limit_Minus");
			ret.push_back("Ref_Plus");
			ret.push_back("Limit_Plus");
			ret.push_back("Limit_Minus");
			ret.push_back("Limit_Plus_and_Minus");
			ret.push_back("Cancel_Error_s_");
			ret.push_back("_Start_Ref_Drive");
			ret.push_back("Speed_Ramp_0");
			ret.push_back("_Start_Dest_eq_Var_1");
			ret.push_back("_Start_Dest_eq_Var_2");
			ret.push_back("N_cmd_Reverse");
			ret.push_back("_Preset_Pos_eq_Var_3");
			ret.push_back("_Capture_Var_3_eq_Pos");
			ret.push_back("_Capture_Var_4_eq_Pos");
			ret.push_back("_Switch_Spd_eq_notAin1_Ain2");
			ret.push_back("_Switch_Spd_eq_notVar1_Var2");
			ret.push_back("I_limit_dig_");
			ret.push_back("N_clip_neg_pos_");
			ret.push_back("_Switch_Cmd_eq_notDig_Ana");
			ret.push_back("Speed_Ramp_0_Pos");
			ret.push_back("Handwheel");
			ret.push_back("Brake_Car");
			ret.push_back("Recup_Disabled");
			ret.push_back("Rising_Bank_1_Falling_Bank_0");
			ret.push_back("_Start_Dest_eq_Var_1_2_3_4");
			ret.push_back("_Start_CW_eq_Var_1_2_3_4");
			ret.push_back("Brake_Car_Nr2");
			return ret;
		}
		if(sgn_name == "def_din_1")
		{
			ret.push_back("_Off_");
			ret.push_back("Ref_and_Limit_Plus");
			ret.push_back("Ref_and_Limit_Minus");
			ret.push_back("Ref_Plus");
			ret.push_back("Limit_Plus");
			ret.push_back("Limit_Minus");
			ret.push_back("Limit_Plus_and_Minus");
			ret.push_back("Cancel_Error_s_");
			ret.push_back("_Start_Ref_Drive");
			ret.push_back("Speed_Ramp_0");
			ret.push_back("_Start_Dest_eq_Var_1");
			ret.push_back("_Start_Dest_eq_Var_2");
			ret.push_back("N_cmd_Reverse");
			ret.push_back("_Preset_Pos_eq_Var_3");
			ret.push_back("_Capture_Var_3_eq_Pos");
			ret.push_back("_Capture_Var_4_eq_Pos");
			ret.push_back("_Switch_Spd_eq_notAin1_Ain2");
			ret.push_back("_Switch_Spd_eq_notVar1_Var2");
			ret.push_back("I_limit_dig_");
			ret.push_back("N_clip_neg_pos_");
			ret.push_back("_Switch_Cmd_eq_notDig_Ana");
			ret.push_back("Speed_Ramp_0_Pos");
			ret.push_back("Handwheel");
			ret.push_back("Brake_Car");
			ret.push_back("Recup_Disabled");
			ret.push_back("Rising_Bank_1_Falling_Bank_0");
			ret.push_back("_Start_Dest_eq_Var_1_2_3_4");
			ret.push_back("_Start_CW_eq_Var_1_2_3_4");
			ret.push_back("Brake_Car_Nr2");
			return ret;
		}
		if(sgn_name == "active190")
		{
			ret.push_back("Low");
			ret.push_back("High");
			return ret;
		}
		if(sgn_name == "active192")
		{
			ret.push_back("Low");
			ret.push_back("High");
			return ret;
		}
	}

	return ret;
}
