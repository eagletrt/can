#include "inverters_utils_c.h"


int inverters_fields_string_from_id(int id, char **v, size_t fields_size, size_t string_size)
{
	switch(id)
    {
	case 513:
		if(30 > fields_size) return 1;
		snprintf(v[0], string_size, inverters_inv_l_send_send_mux_string);
		snprintf(v[1], string_size, inverters_inv_l_send_read_id_string);
		snprintf(v[2], string_size, inverters_inv_l_send_km_rsvd_0_string);
		snprintf(v[3], string_size, inverters_inv_l_send_m_setdig__iq_string);
		snprintf(v[4], string_size, inverters_inv_l_send_def_din_1_string);
		snprintf(v[5], string_size, inverters_inv_l_send_def_end_1_string);
		snprintf(v[6], string_size, inverters_inv_l_send_i_max_pk_string);
		snprintf(v[7], string_size, inverters_inv_l_send_i_con_eff_string);
		snprintf(v[8], string_size, inverters_inv_l_send_i_device_string);
		snprintf(v[9], string_size, inverters_inv_l_send_n_r_lim_string);
		snprintf(v[10], string_size, inverters_inv_l_send_nmax100perc_string);
		snprintf(v[11], string_size, inverters_inv_l_send_km_speed_0_string);
		snprintf(v[12], string_size, inverters_inv_l_send_km_frg_off_string);
		snprintf(v[13], string_size, inverters_inv_l_send_km_cal_off_string);
		snprintf(v[14], string_size, inverters_inv_l_send_km_tx_tog_stat_string);
		snprintf(v[15], string_size, inverters_inv_l_send_km_i_limit_string);
		snprintf(v[16], string_size, inverters_inv_l_send_km_n_clip_string);
		snprintf(v[17], string_size, inverters_inv_l_send_km_mix_ana_on_string);
		snprintf(v[18], string_size, inverters_inv_l_send_ret_interval_string);
		snprintf(v[19], string_size, inverters_inv_l_send_km_allow_sync_string);
		snprintf(v[20], string_size, inverters_inv_l_send_km_handwheel_string);
		snprintf(v[21], string_size, inverters_inv_l_send_km_phasing_extend_string);
		snprintf(v[22], string_size, inverters_inv_l_send_km_rsvd_11_string);
		snprintf(v[23], string_size, inverters_inv_l_send_km_rsvd_12_string);
		snprintf(v[24], string_size, inverters_inv_l_send_km_rsvd_13_string);
		snprintf(v[25], string_size, inverters_inv_l_send_km_pseudo_enable_string);
		snprintf(v[26], string_size, inverters_inv_l_send_km_debug_test_string);
		snprintf(v[27], string_size, inverters_inv_l_send_active192_string);
		snprintf(v[28], string_size, inverters_inv_l_send_active190_string);
		snprintf(v[29], string_size, inverters_inv_l_send_m_r_rcp_string);

		return 0;
	case 385:
		if(137 > fields_size) return 1;
		snprintf(v[0], string_size, inverters_inv_l_rcv_rcv_mux_string);
		snprintf(v[1], string_size, inverters_inv_l_rcv_n_actual_filt_string);
		snprintf(v[2], string_size, inverters_inv_l_rcv_ena64_string);
		snprintf(v[3], string_size, inverters_inv_l_rcv_err_badparas_string);
		snprintf(v[4], string_size, inverters_inv_l_rcv_def_end_1_string);
		snprintf(v[5], string_size, inverters_inv_l_rcv_lmt_active_1_string);
		snprintf(v[6], string_size, inverters_inv_l_rcv_i_cmd_string);
		snprintf(v[7], string_size, inverters_inv_l_rcv_i_cmd_ramp_string);
		snprintf(v[8], string_size, inverters_inv_l_rcv_iq_actual_string);
		snprintf(v[9], string_size, inverters_inv_l_rcv_t_motor_string);
		snprintf(v[10], string_size, inverters_inv_l_rcv_t_igbt_string);
		snprintf(v[11], string_size, inverters_inv_l_rcv_vdc_bus_filt_string);
		snprintf(v[12], string_size, inverters_inv_l_rcv_km_rsvd_0_string);
		snprintf(v[13], string_size, inverters_inv_l_rcv_ena82_string);
		snprintf(v[14], string_size, inverters_inv_l_rcv_def_din_1_string);
		snprintf(v[15], string_size, inverters_inv_l_rcv_m_cmd_ramp_string);
		snprintf(v[16], string_size, inverters_inv_l_rcv_i_max_pk_string);
		snprintf(v[17], string_size, inverters_inv_l_rcv_i_con_eff_string);
		snprintf(v[18], string_size, inverters_inv_l_rcv_i_device_string);
		snprintf(v[19], string_size, inverters_inv_l_rcv_n_r_lim_string);
		snprintf(v[20], string_size, inverters_inv_l_rcv_nmax100perc_string);
		snprintf(v[21], string_size, inverters_inv_l_rcv_ncr064_string);
		snprintf(v[22], string_size, inverters_inv_l_rcv_err_powerfault_string);
		snprintf(v[23], string_size, inverters_inv_l_rcv_lmt_active_2_string);
		snprintf(v[24], string_size, inverters_inv_l_rcv_km_speed_0_string);
		snprintf(v[25], string_size, inverters_inv_l_rcv_ncr082_string);
		snprintf(v[26], string_size, inverters_inv_l_rcv_lim_plus64_string);
		snprintf(v[27], string_size, inverters_inv_l_rcv_err_rfe_fault_string);
		snprintf(v[28], string_size, inverters_inv_l_rcv_in_active_2_string);
		snprintf(v[29], string_size, inverters_inv_l_rcv_km_frg_off_string);
		snprintf(v[30], string_size, inverters_inv_l_rcv_lim_plus82_string);
		snprintf(v[31], string_size, inverters_inv_l_rcv_lim_minus64_string);
		snprintf(v[32], string_size, inverters_inv_l_rcv_err_bustimeout_string);
		snprintf(v[33], string_size, inverters_inv_l_rcv_in_active_1_string);
		snprintf(v[34], string_size, inverters_inv_l_rcv_km_cal_off_string);
		snprintf(v[35], string_size, inverters_inv_l_rcv_lim_minus82_string);
		snprintf(v[36], string_size, inverters_inv_l_rcv_ok64_string);
		snprintf(v[37], string_size, inverters_inv_l_rcv_err_feedbacksignal_string);
		snprintf(v[38], string_size, inverters_inv_l_rcv_frgrun_string);
		snprintf(v[39], string_size, inverters_inv_l_rcv_km_tx_tog_stat_string);
		snprintf(v[40], string_size, inverters_inv_l_rcv_ok82_string);
		snprintf(v[41], string_size, inverters_inv_l_rcv_icns64_string);
		snprintf(v[42], string_size, inverters_inv_l_rcv_err_powervoltage_low_string);
		snprintf(v[43], string_size, inverters_inv_l_rcv_rfe216_string);
		snprintf(v[44], string_size, inverters_inv_l_rcv_km_i_limit_string);
		snprintf(v[45], string_size, inverters_inv_l_rcv_icns82_string);
		snprintf(v[46], string_size, inverters_inv_l_rcv_tnlim64_string);
		snprintf(v[47], string_size, inverters_inv_l_rcv_err_motortemp_string);
		snprintf(v[48], string_size, inverters_inv_l_rcv_km_n_clip_string);
		snprintf(v[49], string_size, inverters_inv_l_rcv_tnlim82_string);
		snprintf(v[50], string_size, inverters_inv_l_rcv_pn64_string);
		snprintf(v[51], string_size, inverters_inv_l_rcv_err_devicetemp_string);
		snprintf(v[52], string_size, inverters_inv_l_rcv_km_mix_ana_on_string);
		snprintf(v[53], string_size, inverters_inv_l_rcv_pn82_string);
		snprintf(v[54], string_size, inverters_inv_l_rcv_ni64_string);
		snprintf(v[55], string_size, inverters_inv_l_rcv_err_overvoltage_string);
		snprintf(v[56], string_size, inverters_inv_l_rcv_d_out_1_on_string);
		snprintf(v[57], string_size, inverters_inv_l_rcv_km_allow_sync_string);
		snprintf(v[58], string_size, inverters_inv_l_rcv_ni82_string);
		snprintf(v[59], string_size, inverters_inv_l_rcv__n064_string);
		snprintf(v[60], string_size, inverters_inv_l_rcv_err_ipeak_string);
		snprintf(v[61], string_size, inverters_inv_l_rcv_d_out_2_on_string);
		snprintf(v[62], string_size, inverters_inv_l_rcv_km_handwheel_string);
		snprintf(v[63], string_size, inverters_inv_l_rcv__n082_string);
		snprintf(v[64], string_size, inverters_inv_l_rcv_rsw64_string);
		snprintf(v[65], string_size, inverters_inv_l_rcv_err_raceaway_string);
		snprintf(v[66], string_size, inverters_inv_l_rcv_btbrdy_string);
		snprintf(v[67], string_size, inverters_inv_l_rcv_km_phasing_extend_string);
		snprintf(v[68], string_size, inverters_inv_l_rcv_rsw82_string);
		snprintf(v[69], string_size, inverters_inv_l_rcv_cal064_string);
		snprintf(v[70], string_size, inverters_inv_l_rcv_err_user_string);
		snprintf(v[71], string_size, inverters_inv_l_rcv_go216_string);
		snprintf(v[72], string_size, inverters_inv_l_rcv_km_rsvd_11_string);
		snprintf(v[73], string_size, inverters_inv_l_rcv_cal082_string);
		snprintf(v[74], string_size, inverters_inv_l_rcv_cal64_string);
		snprintf(v[75], string_size, inverters_inv_l_rcv_d_out_3_on_string);
		snprintf(v[76], string_size, inverters_inv_l_rcv_km_rsvd_12_string);
		snprintf(v[77], string_size, inverters_inv_l_rcv_cal82_string);
		snprintf(v[78], string_size, inverters_inv_l_rcv_tol64_string);
		snprintf(v[79], string_size, inverters_inv_l_rcv_d_out_4_on_string);
		snprintf(v[80], string_size, inverters_inv_l_rcv_km_rsvd_13_string);
		snprintf(v[81], string_size, inverters_inv_l_rcv_tol82_string);
		snprintf(v[82], string_size, inverters_inv_l_rcv_rdy64_string);
		snprintf(v[83], string_size, inverters_inv_l_rcv_err_hwerr_string);
		snprintf(v[84], string_size, inverters_inv_l_rcv_goff_string);
		snprintf(v[85], string_size, inverters_inv_l_rcv_km_pseudo_enable_string);
		snprintf(v[86], string_size, inverters_inv_l_rcv_rdy82_string);
		snprintf(v[87], string_size, inverters_inv_l_rcv_brk064_string);
		snprintf(v[88], string_size, inverters_inv_l_rcv_err_ballast_string);
		snprintf(v[89], string_size, inverters_inv_l_rcv_active190_string);
		snprintf(v[90], string_size, inverters_inv_l_rcv_brk1216_string);
		snprintf(v[91], string_size, inverters_inv_l_rcv_km_debug_test_string);
		snprintf(v[92], string_size, inverters_inv_l_rcv_brk082_string);
		snprintf(v[93], string_size, inverters_inv_l_rcv_active192_string);
		snprintf(v[94], string_size, inverters_inv_l_rcv_signmag64_string);
		snprintf(v[95], string_size, inverters_inv_l_rcv_warn_warning_0_string);
		snprintf(v[96], string_size, inverters_inv_l_rcv_signmag82_string);
		snprintf(v[97], string_size, inverters_inv_l_rcv_free_string);
		snprintf(v[98], string_size, inverters_inv_l_rcv_m_r_rcp_string);
		snprintf(v[99], string_size, inverters_inv_l_rcv_nclip64_string);
		snprintf(v[100], string_size, inverters_inv_l_rcv_warn_illegal_status_string);
		snprintf(v[101], string_size, inverters_inv_l_rcv_nclip82_string);
		snprintf(v[102], string_size, inverters_inv_l_rcv_nclip_minus64_string);
		snprintf(v[103], string_size, inverters_inv_l_rcv_warn_safe_in_string);
		snprintf(v[104], string_size, inverters_inv_l_rcv_nclip_minus82_string);
		snprintf(v[105], string_size, inverters_inv_l_rcv_nclip_plus64_string);
		snprintf(v[106], string_size, inverters_inv_l_rcv_nclip_plus82_string);
		snprintf(v[107], string_size, inverters_inv_l_rcv_irddig64_string);
		snprintf(v[108], string_size, inverters_inv_l_rcv_irddig82_string);
		snprintf(v[109], string_size, inverters_inv_l_rcv_iuserchd64_string);
		snprintf(v[110], string_size, inverters_inv_l_rcv_iuserchd82_string);
		snprintf(v[111], string_size, inverters_inv_l_rcv_irdn64_string);
		snprintf(v[112], string_size, inverters_inv_l_rcv_warn_motortemp_string);
		snprintf(v[113], string_size, inverters_inv_l_rcv_irdn82_string);
		snprintf(v[114], string_size, inverters_inv_l_rcv_irdti64_string);
		snprintf(v[115], string_size, inverters_inv_l_rcv_warn_devicetemp_string);
		snprintf(v[116], string_size, inverters_inv_l_rcv_irdti82_string);
		snprintf(v[117], string_size, inverters_inv_l_rcv_irdtir64_string);
		snprintf(v[118], string_size, inverters_inv_l_rcv_warn_vout_sat_string);
		snprintf(v[119], string_size, inverters_inv_l_rcv_irdtir82_string);
		snprintf(v[120], string_size, inverters_inv_l_rcv__10hz64_string);
		snprintf(v[121], string_size, inverters_inv_l_rcv_warn_ipeak_string);
		snprintf(v[122], string_size, inverters_inv_l_rcv__10hz82_string);
		snprintf(v[123], string_size, inverters_inv_l_rcv_irdtm64_string);
		snprintf(v[124], string_size, inverters_inv_l_rcv_warn_raceaway_string);
		snprintf(v[125], string_size, inverters_inv_l_rcv_irdtm82_string);
		snprintf(v[126], string_size, inverters_inv_l_rcv_irdana64_string);
		snprintf(v[127], string_size, inverters_inv_l_rcv_irdana82_string);
		snprintf(v[128], string_size, inverters_inv_l_rcv_iwcns64_string);
		snprintf(v[129], string_size, inverters_inv_l_rcv_iwcns82_string);
		snprintf(v[130], string_size, inverters_inv_l_rcv_rfepulse64_string);
		snprintf(v[131], string_size, inverters_inv_l_rcv_rfepulse82_string);
		snprintf(v[132], string_size, inverters_inv_l_rcv_md64_string);
		snprintf(v[133], string_size, inverters_inv_l_rcv_md82_string);
		snprintf(v[134], string_size, inverters_inv_l_rcv_hndwhl64_string);
		snprintf(v[135], string_size, inverters_inv_l_rcv_warn_ballast_string);
		snprintf(v[136], string_size, inverters_inv_l_rcv_hndwhl82_string);

		return 0;
	case 514:
		if(30 > fields_size) return 1;
		snprintf(v[0], string_size, inverters_inv_r_send_send_mux_string);
		snprintf(v[1], string_size, inverters_inv_r_send_read_id_string);
		snprintf(v[2], string_size, inverters_inv_r_send_km_rsvd_0_string);
		snprintf(v[3], string_size, inverters_inv_r_send_m_setdig__iq_string);
		snprintf(v[4], string_size, inverters_inv_r_send_def_din_1_string);
		snprintf(v[5], string_size, inverters_inv_r_send_def_end_1_string);
		snprintf(v[6], string_size, inverters_inv_r_send_i_max_pk_string);
		snprintf(v[7], string_size, inverters_inv_r_send_i_con_eff_string);
		snprintf(v[8], string_size, inverters_inv_r_send_i_device_string);
		snprintf(v[9], string_size, inverters_inv_r_send_n_r_lim_string);
		snprintf(v[10], string_size, inverters_inv_r_send_nmax100perc_string);
		snprintf(v[11], string_size, inverters_inv_r_send_km_speed_0_string);
		snprintf(v[12], string_size, inverters_inv_r_send_km_frg_off_string);
		snprintf(v[13], string_size, inverters_inv_r_send_km_cal_off_string);
		snprintf(v[14], string_size, inverters_inv_r_send_km_tx_tog_stat_string);
		snprintf(v[15], string_size, inverters_inv_r_send_km_i_limit_string);
		snprintf(v[16], string_size, inverters_inv_r_send_km_n_clip_string);
		snprintf(v[17], string_size, inverters_inv_r_send_km_mix_ana_on_string);
		snprintf(v[18], string_size, inverters_inv_r_send_ret_interval_string);
		snprintf(v[19], string_size, inverters_inv_r_send_km_allow_sync_string);
		snprintf(v[20], string_size, inverters_inv_r_send_km_handwheel_string);
		snprintf(v[21], string_size, inverters_inv_r_send_km_phasing_extend_string);
		snprintf(v[22], string_size, inverters_inv_r_send_km_rsvd_11_string);
		snprintf(v[23], string_size, inverters_inv_r_send_km_rsvd_12_string);
		snprintf(v[24], string_size, inverters_inv_r_send_km_rsvd_13_string);
		snprintf(v[25], string_size, inverters_inv_r_send_km_pseudo_enable_string);
		snprintf(v[26], string_size, inverters_inv_r_send_km_debug_test_string);
		snprintf(v[27], string_size, inverters_inv_r_send_active192_string);
		snprintf(v[28], string_size, inverters_inv_r_send_active190_string);
		snprintf(v[29], string_size, inverters_inv_r_send_m_r_rcp_string);

		return 0;
	case 386:
		if(137 > fields_size) return 1;
		snprintf(v[0], string_size, inverters_inv_r_rcv_rcv_mux_string);
		snprintf(v[1], string_size, inverters_inv_r_rcv_n_actual_filt_string);
		snprintf(v[2], string_size, inverters_inv_r_rcv_ena64_string);
		snprintf(v[3], string_size, inverters_inv_r_rcv_err_badparas_string);
		snprintf(v[4], string_size, inverters_inv_r_rcv_def_end_1_string);
		snprintf(v[5], string_size, inverters_inv_r_rcv_lmt_active_1_string);
		snprintf(v[6], string_size, inverters_inv_r_rcv_i_cmd_string);
		snprintf(v[7], string_size, inverters_inv_r_rcv_i_cmd_ramp_string);
		snprintf(v[8], string_size, inverters_inv_r_rcv_iq_actual_string);
		snprintf(v[9], string_size, inverters_inv_r_rcv_t_motor_string);
		snprintf(v[10], string_size, inverters_inv_r_rcv_t_igbt_string);
		snprintf(v[11], string_size, inverters_inv_r_rcv_vdc_bus_filt_string);
		snprintf(v[12], string_size, inverters_inv_r_rcv_km_rsvd_0_string);
		snprintf(v[13], string_size, inverters_inv_r_rcv_ena82_string);
		snprintf(v[14], string_size, inverters_inv_r_rcv_def_din_1_string);
		snprintf(v[15], string_size, inverters_inv_r_rcv_m_cmd_ramp_string);
		snprintf(v[16], string_size, inverters_inv_r_rcv_i_max_pk_string);
		snprintf(v[17], string_size, inverters_inv_r_rcv_i_con_eff_string);
		snprintf(v[18], string_size, inverters_inv_r_rcv_i_device_string);
		snprintf(v[19], string_size, inverters_inv_r_rcv_n_r_lim_string);
		snprintf(v[20], string_size, inverters_inv_r_rcv_nmax100perc_string);
		snprintf(v[21], string_size, inverters_inv_r_rcv_ncr064_string);
		snprintf(v[22], string_size, inverters_inv_r_rcv_err_powerfault_string);
		snprintf(v[23], string_size, inverters_inv_r_rcv_lmt_active_2_string);
		snprintf(v[24], string_size, inverters_inv_r_rcv_km_speed_0_string);
		snprintf(v[25], string_size, inverters_inv_r_rcv_ncr082_string);
		snprintf(v[26], string_size, inverters_inv_r_rcv_lim_plus64_string);
		snprintf(v[27], string_size, inverters_inv_r_rcv_err_rfe_fault_string);
		snprintf(v[28], string_size, inverters_inv_r_rcv_in_active_2_string);
		snprintf(v[29], string_size, inverters_inv_r_rcv_km_frg_off_string);
		snprintf(v[30], string_size, inverters_inv_r_rcv_lim_plus82_string);
		snprintf(v[31], string_size, inverters_inv_r_rcv_lim_minus64_string);
		snprintf(v[32], string_size, inverters_inv_r_rcv_err_bustimeout_string);
		snprintf(v[33], string_size, inverters_inv_r_rcv_in_active_1_string);
		snprintf(v[34], string_size, inverters_inv_r_rcv_km_cal_off_string);
		snprintf(v[35], string_size, inverters_inv_r_rcv_lim_minus82_string);
		snprintf(v[36], string_size, inverters_inv_r_rcv_ok64_string);
		snprintf(v[37], string_size, inverters_inv_r_rcv_err_feedbacksignal_string);
		snprintf(v[38], string_size, inverters_inv_r_rcv_frgrun_string);
		snprintf(v[39], string_size, inverters_inv_r_rcv_km_tx_tog_stat_string);
		snprintf(v[40], string_size, inverters_inv_r_rcv_ok82_string);
		snprintf(v[41], string_size, inverters_inv_r_rcv_icns64_string);
		snprintf(v[42], string_size, inverters_inv_r_rcv_err_powervoltage_low_string);
		snprintf(v[43], string_size, inverters_inv_r_rcv_rfe216_string);
		snprintf(v[44], string_size, inverters_inv_r_rcv_km_i_limit_string);
		snprintf(v[45], string_size, inverters_inv_r_rcv_icns82_string);
		snprintf(v[46], string_size, inverters_inv_r_rcv_tnlim64_string);
		snprintf(v[47], string_size, inverters_inv_r_rcv_err_motortemp_string);
		snprintf(v[48], string_size, inverters_inv_r_rcv_km_n_clip_string);
		snprintf(v[49], string_size, inverters_inv_r_rcv_tnlim82_string);
		snprintf(v[50], string_size, inverters_inv_r_rcv_pn64_string);
		snprintf(v[51], string_size, inverters_inv_r_rcv_err_devicetemp_string);
		snprintf(v[52], string_size, inverters_inv_r_rcv_km_mix_ana_on_string);
		snprintf(v[53], string_size, inverters_inv_r_rcv_pn82_string);
		snprintf(v[54], string_size, inverters_inv_r_rcv_ni64_string);
		snprintf(v[55], string_size, inverters_inv_r_rcv_err_overvoltage_string);
		snprintf(v[56], string_size, inverters_inv_r_rcv_d_out_1_on_string);
		snprintf(v[57], string_size, inverters_inv_r_rcv_km_allow_sync_string);
		snprintf(v[58], string_size, inverters_inv_r_rcv_ni82_string);
		snprintf(v[59], string_size, inverters_inv_r_rcv__n064_string);
		snprintf(v[60], string_size, inverters_inv_r_rcv_err_ipeak_string);
		snprintf(v[61], string_size, inverters_inv_r_rcv_d_out_2_on_string);
		snprintf(v[62], string_size, inverters_inv_r_rcv_km_handwheel_string);
		snprintf(v[63], string_size, inverters_inv_r_rcv__n082_string);
		snprintf(v[64], string_size, inverters_inv_r_rcv_rsw64_string);
		snprintf(v[65], string_size, inverters_inv_r_rcv_err_raceaway_string);
		snprintf(v[66], string_size, inverters_inv_r_rcv_btbrdy_string);
		snprintf(v[67], string_size, inverters_inv_r_rcv_km_phasing_extend_string);
		snprintf(v[68], string_size, inverters_inv_r_rcv_rsw82_string);
		snprintf(v[69], string_size, inverters_inv_r_rcv_cal064_string);
		snprintf(v[70], string_size, inverters_inv_r_rcv_err_user_string);
		snprintf(v[71], string_size, inverters_inv_r_rcv_go216_string);
		snprintf(v[72], string_size, inverters_inv_r_rcv_km_rsvd_11_string);
		snprintf(v[73], string_size, inverters_inv_r_rcv_cal082_string);
		snprintf(v[74], string_size, inverters_inv_r_rcv_cal64_string);
		snprintf(v[75], string_size, inverters_inv_r_rcv_d_out_3_on_string);
		snprintf(v[76], string_size, inverters_inv_r_rcv_km_rsvd_12_string);
		snprintf(v[77], string_size, inverters_inv_r_rcv_cal82_string);
		snprintf(v[78], string_size, inverters_inv_r_rcv_tol64_string);
		snprintf(v[79], string_size, inverters_inv_r_rcv_d_out_4_on_string);
		snprintf(v[80], string_size, inverters_inv_r_rcv_km_rsvd_13_string);
		snprintf(v[81], string_size, inverters_inv_r_rcv_tol82_string);
		snprintf(v[82], string_size, inverters_inv_r_rcv_rdy64_string);
		snprintf(v[83], string_size, inverters_inv_r_rcv_err_hwerr_string);
		snprintf(v[84], string_size, inverters_inv_r_rcv_goff_string);
		snprintf(v[85], string_size, inverters_inv_r_rcv_km_pseudo_enable_string);
		snprintf(v[86], string_size, inverters_inv_r_rcv_rdy82_string);
		snprintf(v[87], string_size, inverters_inv_r_rcv_brk064_string);
		snprintf(v[88], string_size, inverters_inv_r_rcv_err_ballast_string);
		snprintf(v[89], string_size, inverters_inv_r_rcv_active190_string);
		snprintf(v[90], string_size, inverters_inv_r_rcv_brk1216_string);
		snprintf(v[91], string_size, inverters_inv_r_rcv_km_debug_test_string);
		snprintf(v[92], string_size, inverters_inv_r_rcv_brk082_string);
		snprintf(v[93], string_size, inverters_inv_r_rcv_active192_string);
		snprintf(v[94], string_size, inverters_inv_r_rcv_signmag64_string);
		snprintf(v[95], string_size, inverters_inv_r_rcv_warn_warning_0_string);
		snprintf(v[96], string_size, inverters_inv_r_rcv_signmag82_string);
		snprintf(v[97], string_size, inverters_inv_r_rcv_free_string);
		snprintf(v[98], string_size, inverters_inv_r_rcv_m_r_rcp_string);
		snprintf(v[99], string_size, inverters_inv_r_rcv_nclip64_string);
		snprintf(v[100], string_size, inverters_inv_r_rcv_warn_illegal_status_string);
		snprintf(v[101], string_size, inverters_inv_r_rcv_nclip82_string);
		snprintf(v[102], string_size, inverters_inv_r_rcv_nclip_minus64_string);
		snprintf(v[103], string_size, inverters_inv_r_rcv_warn_safe_in_string);
		snprintf(v[104], string_size, inverters_inv_r_rcv_nclip_minus82_string);
		snprintf(v[105], string_size, inverters_inv_r_rcv_nclip_plus64_string);
		snprintf(v[106], string_size, inverters_inv_r_rcv_nclip_plus82_string);
		snprintf(v[107], string_size, inverters_inv_r_rcv_irddig64_string);
		snprintf(v[108], string_size, inverters_inv_r_rcv_irddig82_string);
		snprintf(v[109], string_size, inverters_inv_r_rcv_iuserchd64_string);
		snprintf(v[110], string_size, inverters_inv_r_rcv_iuserchd82_string);
		snprintf(v[111], string_size, inverters_inv_r_rcv_irdn64_string);
		snprintf(v[112], string_size, inverters_inv_r_rcv_warn_motortemp_string);
		snprintf(v[113], string_size, inverters_inv_r_rcv_irdn82_string);
		snprintf(v[114], string_size, inverters_inv_r_rcv_irdti64_string);
		snprintf(v[115], string_size, inverters_inv_r_rcv_warn_devicetemp_string);
		snprintf(v[116], string_size, inverters_inv_r_rcv_irdti82_string);
		snprintf(v[117], string_size, inverters_inv_r_rcv_irdtir64_string);
		snprintf(v[118], string_size, inverters_inv_r_rcv_warn_vout_sat_string);
		snprintf(v[119], string_size, inverters_inv_r_rcv_irdtir82_string);
		snprintf(v[120], string_size, inverters_inv_r_rcv__10hz64_string);
		snprintf(v[121], string_size, inverters_inv_r_rcv_warn_ipeak_string);
		snprintf(v[122], string_size, inverters_inv_r_rcv__10hz82_string);
		snprintf(v[123], string_size, inverters_inv_r_rcv_irdtm64_string);
		snprintf(v[124], string_size, inverters_inv_r_rcv_warn_raceaway_string);
		snprintf(v[125], string_size, inverters_inv_r_rcv_irdtm82_string);
		snprintf(v[126], string_size, inverters_inv_r_rcv_irdana64_string);
		snprintf(v[127], string_size, inverters_inv_r_rcv_irdana82_string);
		snprintf(v[128], string_size, inverters_inv_r_rcv_iwcns64_string);
		snprintf(v[129], string_size, inverters_inv_r_rcv_iwcns82_string);
		snprintf(v[130], string_size, inverters_inv_r_rcv_rfepulse64_string);
		snprintf(v[131], string_size, inverters_inv_r_rcv_rfepulse82_string);
		snprintf(v[132], string_size, inverters_inv_r_rcv_md64_string);
		snprintf(v[133], string_size, inverters_inv_r_rcv_md82_string);
		snprintf(v[134], string_size, inverters_inv_r_rcv_hndwhl64_string);
		snprintf(v[135], string_size, inverters_inv_r_rcv_warn_ballast_string);
		snprintf(v[136], string_size, inverters_inv_r_rcv_hndwhl82_string);

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
int inverters_serialize_from_id(int id, char *s, uint8_t *data, size_t size)
{
    switch(id)
    {
	case 513:
	{
		inverters_inv_l_send_t tmp;
		inverters_inv_l_send_converted_t tmp_converted;
		sscanf(s, "%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIi16 
			"%" PRIu16 
			"%" PRIu16 
			"""%f"
			"""%f"
			"""%f"
			"%" PRIu16 
			"%" PRIi16 
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu16 
			"",
			tmp.send_mux,
			tmp.read_id,
			tmp.km_rsvd_0,
			tmp.m_setdig__iq,
			tmp.def_din_1,
			tmp.def_end_1,
			tmp.i_max_pk,
			tmp.i_con_eff,
			tmp.i_device,
			tmp.n_r_lim,
			tmp.nmax100perc,
			tmp.km_speed_0,
			tmp.km_frg_off,
			tmp.km_cal_off,
			tmp.km_tx_tog_stat,
			tmp.km_i_limit,
			tmp.km_n_clip,
			tmp.km_mix_ana_on,
			tmp.ret_interval,
			tmp.km_allow_sync,
			tmp.km_handwheel,
			tmp.km_phasing_extend,
			tmp.km_rsvd_11,
			tmp.km_rsvd_12,
			tmp.km_rsvd_13,
			tmp.km_pseudo_enable,
			tmp.km_debug_test,
			tmp.active192,
			tmp.active190,
			tmp.m_r_rcp);
		inverters_inv_l_send_conversion_to_raw_struct(&tmp, &tmp_converted);
		return inverters_inv_l_send_pack(data, &tmp, size);
	}
	case 385:
	{
		inverters_inv_l_rcv_t tmp;
		inverters_inv_l_rcv_converted_t tmp_converted;
		sscanf(s, "%" PRIu8  
			"""%f"
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu16 
			"%" PRIu8  
			"""%f"
			"""%f"
			"""%f"
			"%" PRIu16 
			"%" PRIu16 
			"""%f"
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu16 
			"%" PRIi16 
			"""%f"
			"""%f"
			"""%f"
			"%" PRIu16 
			"%" PRIi16 
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIi16 
			"%" PRIu16 
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"",
			tmp.rcv_mux,
			tmp.n_actual_filt,
			tmp.ena64,
			tmp.err_badparas,
			tmp.def_end_1,
			tmp.lmt_active_1,
			tmp.i_cmd,
			tmp.i_cmd_ramp,
			tmp.iq_actual,
			tmp.t_motor,
			tmp.t_igbt,
			tmp.vdc_bus_filt,
			tmp.km_rsvd_0,
			tmp.ena82,
			tmp.def_din_1,
			tmp.m_cmd_ramp,
			tmp.i_max_pk,
			tmp.i_con_eff,
			tmp.i_device,
			tmp.n_r_lim,
			tmp.nmax100perc,
			tmp.ncr064,
			tmp.err_powerfault,
			tmp.lmt_active_2,
			tmp.km_speed_0,
			tmp.ncr082,
			tmp.lim_plus64,
			tmp.err_rfe_fault,
			tmp.in_active_2,
			tmp.km_frg_off,
			tmp.lim_plus82,
			tmp.lim_minus64,
			tmp.err_bustimeout,
			tmp.in_active_1,
			tmp.km_cal_off,
			tmp.lim_minus82,
			tmp.ok64,
			tmp.err_feedbacksignal,
			tmp.frgrun,
			tmp.km_tx_tog_stat,
			tmp.ok82,
			tmp.icns64,
			tmp.err_powervoltage_low,
			tmp.rfe216,
			tmp.km_i_limit,
			tmp.icns82,
			tmp.tnlim64,
			tmp.err_motortemp,
			tmp.km_n_clip,
			tmp.tnlim82,
			tmp.pn64,
			tmp.err_devicetemp,
			tmp.km_mix_ana_on,
			tmp.pn82,
			tmp.ni64,
			tmp.err_overvoltage,
			tmp.d_out_1_on,
			tmp.km_allow_sync,
			tmp.ni82,
			tmp._n064,
			tmp.err_ipeak,
			tmp.d_out_2_on,
			tmp.km_handwheel,
			tmp._n082,
			tmp.rsw64,
			tmp.err_raceaway,
			tmp.btbrdy,
			tmp.km_phasing_extend,
			tmp.rsw82,
			tmp.cal064,
			tmp.err_user,
			tmp.go216,
			tmp.km_rsvd_11,
			tmp.cal082,
			tmp.cal64,
			tmp.d_out_3_on,
			tmp.km_rsvd_12,
			tmp.cal82,
			tmp.tol64,
			tmp.d_out_4_on,
			tmp.km_rsvd_13,
			tmp.tol82,
			tmp.rdy64,
			tmp.err_hwerr,
			tmp.goff,
			tmp.km_pseudo_enable,
			tmp.rdy82,
			tmp.brk064,
			tmp.err_ballast,
			tmp.active190,
			tmp.brk1216,
			tmp.km_debug_test,
			tmp.brk082,
			tmp.active192,
			tmp.signmag64,
			tmp.warn_warning_0,
			tmp.signmag82,
			tmp.free,
			tmp.m_r_rcp,
			tmp.nclip64,
			tmp.warn_illegal_status,
			tmp.nclip82,
			tmp.nclip_minus64,
			tmp.warn_safe_in,
			tmp.nclip_minus82,
			tmp.nclip_plus64,
			tmp.nclip_plus82,
			tmp.irddig64,
			tmp.irddig82,
			tmp.iuserchd64,
			tmp.iuserchd82,
			tmp.irdn64,
			tmp.warn_motortemp,
			tmp.irdn82,
			tmp.irdti64,
			tmp.warn_devicetemp,
			tmp.irdti82,
			tmp.irdtir64,
			tmp.warn_vout_sat,
			tmp.irdtir82,
			tmp._10hz64,
			tmp.warn_ipeak,
			tmp._10hz82,
			tmp.irdtm64,
			tmp.warn_raceaway,
			tmp.irdtm82,
			tmp.irdana64,
			tmp.irdana82,
			tmp.iwcns64,
			tmp.iwcns82,
			tmp.rfepulse64,
			tmp.rfepulse82,
			tmp.md64,
			tmp.md82,
			tmp.hndwhl64,
			tmp.warn_ballast,
			tmp.hndwhl82);
		inverters_inv_l_rcv_conversion_to_raw_struct(&tmp, &tmp_converted);
		return inverters_inv_l_rcv_pack(data, &tmp, size);
	}
	case 514:
	{
		inverters_inv_r_send_t tmp;
		inverters_inv_r_send_converted_t tmp_converted;
		sscanf(s, "%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIi16 
			"%" PRIu16 
			"%" PRIu16 
			"""%f"
			"""%f"
			"""%f"
			"%" PRIu16 
			"%" PRIi16 
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu16 
			"",
			tmp.send_mux,
			tmp.read_id,
			tmp.km_rsvd_0,
			tmp.m_setdig__iq,
			tmp.def_din_1,
			tmp.def_end_1,
			tmp.i_max_pk,
			tmp.i_con_eff,
			tmp.i_device,
			tmp.n_r_lim,
			tmp.nmax100perc,
			tmp.km_speed_0,
			tmp.km_frg_off,
			tmp.km_cal_off,
			tmp.km_tx_tog_stat,
			tmp.km_i_limit,
			tmp.km_n_clip,
			tmp.km_mix_ana_on,
			tmp.ret_interval,
			tmp.km_allow_sync,
			tmp.km_handwheel,
			tmp.km_phasing_extend,
			tmp.km_rsvd_11,
			tmp.km_rsvd_12,
			tmp.km_rsvd_13,
			tmp.km_pseudo_enable,
			tmp.km_debug_test,
			tmp.active192,
			tmp.active190,
			tmp.m_r_rcp);
		inverters_inv_r_send_conversion_to_raw_struct(&tmp, &tmp_converted);
		return inverters_inv_r_send_pack(data, &tmp, size);
	}
	case 386:
	{
		inverters_inv_r_rcv_t tmp;
		inverters_inv_r_rcv_converted_t tmp_converted;
		sscanf(s, "%" PRIu8  
			"""%f"
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu16 
			"%" PRIu8  
			"""%f"
			"""%f"
			"""%f"
			"%" PRIu16 
			"%" PRIu16 
			"""%f"
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu16 
			"%" PRIi16 
			"""%f"
			"""%f"
			"""%f"
			"%" PRIu16 
			"%" PRIi16 
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIi16 
			"%" PRIu16 
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"",
			tmp.rcv_mux,
			tmp.n_actual_filt,
			tmp.ena64,
			tmp.err_badparas,
			tmp.def_end_1,
			tmp.lmt_active_1,
			tmp.i_cmd,
			tmp.i_cmd_ramp,
			tmp.iq_actual,
			tmp.t_motor,
			tmp.t_igbt,
			tmp.vdc_bus_filt,
			tmp.km_rsvd_0,
			tmp.ena82,
			tmp.def_din_1,
			tmp.m_cmd_ramp,
			tmp.i_max_pk,
			tmp.i_con_eff,
			tmp.i_device,
			tmp.n_r_lim,
			tmp.nmax100perc,
			tmp.ncr064,
			tmp.err_powerfault,
			tmp.lmt_active_2,
			tmp.km_speed_0,
			tmp.ncr082,
			tmp.lim_plus64,
			tmp.err_rfe_fault,
			tmp.in_active_2,
			tmp.km_frg_off,
			tmp.lim_plus82,
			tmp.lim_minus64,
			tmp.err_bustimeout,
			tmp.in_active_1,
			tmp.km_cal_off,
			tmp.lim_minus82,
			tmp.ok64,
			tmp.err_feedbacksignal,
			tmp.frgrun,
			tmp.km_tx_tog_stat,
			tmp.ok82,
			tmp.icns64,
			tmp.err_powervoltage_low,
			tmp.rfe216,
			tmp.km_i_limit,
			tmp.icns82,
			tmp.tnlim64,
			tmp.err_motortemp,
			tmp.km_n_clip,
			tmp.tnlim82,
			tmp.pn64,
			tmp.err_devicetemp,
			tmp.km_mix_ana_on,
			tmp.pn82,
			tmp.ni64,
			tmp.err_overvoltage,
			tmp.d_out_1_on,
			tmp.km_allow_sync,
			tmp.ni82,
			tmp._n064,
			tmp.err_ipeak,
			tmp.d_out_2_on,
			tmp.km_handwheel,
			tmp._n082,
			tmp.rsw64,
			tmp.err_raceaway,
			tmp.btbrdy,
			tmp.km_phasing_extend,
			tmp.rsw82,
			tmp.cal064,
			tmp.err_user,
			tmp.go216,
			tmp.km_rsvd_11,
			tmp.cal082,
			tmp.cal64,
			tmp.d_out_3_on,
			tmp.km_rsvd_12,
			tmp.cal82,
			tmp.tol64,
			tmp.d_out_4_on,
			tmp.km_rsvd_13,
			tmp.tol82,
			tmp.rdy64,
			tmp.err_hwerr,
			tmp.goff,
			tmp.km_pseudo_enable,
			tmp.rdy82,
			tmp.brk064,
			tmp.err_ballast,
			tmp.active190,
			tmp.brk1216,
			tmp.km_debug_test,
			tmp.brk082,
			tmp.active192,
			tmp.signmag64,
			tmp.warn_warning_0,
			tmp.signmag82,
			tmp.free,
			tmp.m_r_rcp,
			tmp.nclip64,
			tmp.warn_illegal_status,
			tmp.nclip82,
			tmp.nclip_minus64,
			tmp.warn_safe_in,
			tmp.nclip_minus82,
			tmp.nclip_plus64,
			tmp.nclip_plus82,
			tmp.irddig64,
			tmp.irddig82,
			tmp.iuserchd64,
			tmp.iuserchd82,
			tmp.irdn64,
			tmp.warn_motortemp,
			tmp.irdn82,
			tmp.irdti64,
			tmp.warn_devicetemp,
			tmp.irdti82,
			tmp.irdtir64,
			tmp.warn_vout_sat,
			tmp.irdtir82,
			tmp._10hz64,
			tmp.warn_ipeak,
			tmp._10hz82,
			tmp.irdtm64,
			tmp.warn_raceaway,
			tmp.irdtm82,
			tmp.irdana64,
			tmp.irdana82,
			tmp.iwcns64,
			tmp.iwcns82,
			tmp.rfepulse64,
			tmp.rfepulse82,
			tmp.md64,
			tmp.md82,
			tmp.hndwhl64,
			tmp.warn_ballast,
			tmp.hndwhl82);
		inverters_inv_r_rcv_conversion_to_raw_struct(&tmp, &tmp_converted);
		return inverters_inv_r_rcv_pack(data, &tmp, size);
	}

    }
    return 0;
}