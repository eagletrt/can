#include "hv_current_utils_c.h"


int hv_current_fields_string_from_id(int id, char **v, size_t fields_size, size_t string_size)
{
	switch(id)
    {
	case 1320:
		if(7 > fields_size) return 1;
		snprintf(v[0], string_size, hv_current_ivt_msg_result_wh_ivt_id_result_wh_string);
		snprintf(v[1], string_size, hv_current_ivt_msg_result_wh_ivt_result_wh_system_error_string);
		snprintf(v[2], string_size, hv_current_ivt_msg_result_wh_ivt_result_wh_measurement_error_string);
		snprintf(v[3], string_size, hv_current_ivt_msg_result_wh_ivt_result_wh_channel_error_string);
		snprintf(v[4], string_size, hv_current_ivt_msg_result_wh_ivt_result_wh_ocs_string);
		snprintf(v[5], string_size, hv_current_ivt_msg_result_wh_ivt_msgcount_result_wh_string);
		snprintf(v[6], string_size, hv_current_ivt_msg_result_wh_ivt_result_wh_string);

		return 0;
	case 1319:
		if(7 > fields_size) return 1;
		snprintf(v[0], string_size, hv_current_ivt_msg_result_as_ivt_id_result_as_string);
		snprintf(v[1], string_size, hv_current_ivt_msg_result_as_ivt_result_as_system_error_string);
		snprintf(v[2], string_size, hv_current_ivt_msg_result_as_ivt_result_as_measurement_error_string);
		snprintf(v[3], string_size, hv_current_ivt_msg_result_as_ivt_result_as_channel_error_string);
		snprintf(v[4], string_size, hv_current_ivt_msg_result_as_ivt_result_as_ocs_string);
		snprintf(v[5], string_size, hv_current_ivt_msg_result_as_ivt_msgcount_result_as_string);
		snprintf(v[6], string_size, hv_current_ivt_msg_result_as_ivt_result_as_string);

		return 0;
	case 1318:
		if(7 > fields_size) return 1;
		snprintf(v[0], string_size, hv_current_ivt_msg_result_w_ivt_id_result_w_string);
		snprintf(v[1], string_size, hv_current_ivt_msg_result_w_ivt_result_w_system_error_string);
		snprintf(v[2], string_size, hv_current_ivt_msg_result_w_ivt_result_w_measurement_error_string);
		snprintf(v[3], string_size, hv_current_ivt_msg_result_w_ivt_result_w_channel_error_string);
		snprintf(v[4], string_size, hv_current_ivt_msg_result_w_ivt_result_w_ocs_string);
		snprintf(v[5], string_size, hv_current_ivt_msg_result_w_ivt_msgcount_result_w_string);
		snprintf(v[6], string_size, hv_current_ivt_msg_result_w_ivt_result_w_string);

		return 0;
	case 1297:
		if(100 > fields_size) return 1;
		snprintf(v[0], string_size, hv_current_ivt_msg_response_ivt_id_response_string);
		snprintf(v[1], string_size, hv_current_ivt_msg_response__b1_trigger_spare_string);
		snprintf(v[2], string_size, hv_current_ivt_msg_response__ff_wrong_command_string);
		snprintf(v[3], string_size, hv_current_ivt_msg_response__bf_restart_alive_cmd_id_string);
		snprintf(v[4], string_size, hv_current_ivt_msg_response__80_resp_measerror_item_string);
		snprintf(v[5], string_size, hv_current_ivt_msg_response__81_resp_systemerror_item_string);
		snprintf(v[6], string_size, hv_current_ivt_msg_response__82_resp_alllogdata_item_string);
		snprintf(v[7], string_size, hv_current_ivt_msg_response__83_resp_logdata_item_string);
		snprintf(v[8], string_size, hv_current_ivt_msg_response__90_resp_can_id_val_i_string);
		snprintf(v[9], string_size, hv_current_ivt_msg_response__91_resp_can_id_val_u1_string);
		snprintf(v[10], string_size, hv_current_ivt_msg_response__92_resp_can_id_val_u2_string);
		snprintf(v[11], string_size, hv_current_ivt_msg_response__93_resp_can_id_val_u3_string);
		snprintf(v[12], string_size, hv_current_ivt_msg_response__94_resp_can_id_val_t_string);
		snprintf(v[13], string_size, hv_current_ivt_msg_response__95_resp_can_id_val_w_string);
		snprintf(v[14], string_size, hv_current_ivt_msg_response__96_resp_can_id_val_as_string);
		snprintf(v[15], string_size, hv_current_ivt_msg_response__97_resp_can_id_val_wh_string);
		snprintf(v[16], string_size, hv_current_ivt_msg_response__9d_resp_can_id_val_command_string);
		snprintf(v[17], string_size, hv_current_ivt_msg_response__9f_resp_can_id_val_response_string);
		snprintf(v[18], string_size, hv_current_ivt_msg_response__a0_resp_sign_i_string);
		snprintf(v[19], string_size, hv_current_ivt_msg_response__a1_resp_sign_u1_string);
		snprintf(v[20], string_size, hv_current_ivt_msg_response__a2_resp_sign_u2_string);
		snprintf(v[21], string_size, hv_current_ivt_msg_response__a3_resp_sign_u3_string);
		snprintf(v[22], string_size, hv_current_ivt_msg_response__a4_resp_sign_t_string);
		snprintf(v[23], string_size, hv_current_ivt_msg_response__a5_resp_sign_w_string);
		snprintf(v[24], string_size, hv_current_ivt_msg_response__a6_resp_sign_as_string);
		snprintf(v[25], string_size, hv_current_ivt_msg_response__a7_resp_sign_wh_string);
		snprintf(v[26], string_size, hv_current_ivt_msg_response__b0_resp_reset_item_string);
		snprintf(v[27], string_size, hv_current_ivt_msg_response__b2_resp_store_dummy_string);
		snprintf(v[28], string_size, hv_current_ivt_msg_response__b3_resp_oc_test_time_string);
		snprintf(v[29], string_size, hv_current_ivt_msg_response__b5_resp_oc_pos_set_threshold_string);
		snprintf(v[30], string_size, hv_current_ivt_msg_response__b6_resp_oc_neg_set_threshold_string);
		snprintf(v[31], string_size, hv_current_ivt_msg_response__b9_resp_device_type_string);
		snprintf(v[32], string_size, hv_current_ivt_msg_response__ba_resp_sw_ver_major_hw_string);
		snprintf(v[33], string_size, hv_current_ivt_msg_response__bb_resp_serien_nr_string);
		snprintf(v[34], string_size, hv_current_ivt_msg_response__bc_resp_art_n_string);
		snprintf(v[35], string_size, hv_current_ivt_msg_response__a0_resp_endianess_i_string);
		snprintf(v[36], string_size, hv_current_ivt_msg_response__a1_resp_endianess_u1_string);
		snprintf(v[37], string_size, hv_current_ivt_msg_response__a2_resp_endianess_u2_string);
		snprintf(v[38], string_size, hv_current_ivt_msg_response__a3_resp_endianess_u3_string);
		snprintf(v[39], string_size, hv_current_ivt_msg_response__a4_resp_endianess_t_string);
		snprintf(v[40], string_size, hv_current_ivt_msg_response__a5_resp_endianess_w_string);
		snprintf(v[41], string_size, hv_current_ivt_msg_response__a6_resp_endianess_as_string);
		snprintf(v[42], string_size, hv_current_ivt_msg_response__a7_resp_endianess_wh_string);
		snprintf(v[43], string_size, hv_current_ivt_msg_response__a0_resp_triggermode_i_string);
		snprintf(v[44], string_size, hv_current_ivt_msg_response__a1_resp_triggermode_u1_string);
		snprintf(v[45], string_size, hv_current_ivt_msg_response__a2_resp_triggermode_u2_string);
		snprintf(v[46], string_size, hv_current_ivt_msg_response__a3_resp_triggermode_u3_string);
		snprintf(v[47], string_size, hv_current_ivt_msg_response__a4_resp_triggermode_t_string);
		snprintf(v[48], string_size, hv_current_ivt_msg_response__a5_resp_triggermode_w_string);
		snprintf(v[49], string_size, hv_current_ivt_msg_response__a6_resp_triggermode_as_string);
		snprintf(v[50], string_size, hv_current_ivt_msg_response__a7_resp_triggermode_wh_string);
		snprintf(v[51], string_size, hv_current_ivt_msg_response__b4_resp_actual_mode_string);
		snprintf(v[52], string_size, hv_current_ivt_msg_response__b1_07_trigger_wh_string);
		snprintf(v[53], string_size, hv_current_ivt_msg_response__b2_resp_store_device_sn_string);
		snprintf(v[54], string_size, hv_current_ivt_msg_response__ba_resp_sw_ver_minor_string);
		snprintf(v[55], string_size, hv_current_ivt_msg_response__b9_resp_device_current_string);
		snprintf(v[56], string_size, hv_current_ivt_msg_response__80_resp_measerror_count_mask_string);
		snprintf(v[57], string_size, hv_current_ivt_msg_response__81_resp_systemerror_count_mask_string);
		snprintf(v[58], string_size, hv_current_ivt_msg_response__82_resp_alllogdata_counter_string);
		snprintf(v[59], string_size, hv_current_ivt_msg_response__83_resp_logdata_counter_string);
		snprintf(v[60], string_size, hv_current_ivt_msg_response__a0_resp_cycletime_i_string);
		snprintf(v[61], string_size, hv_current_ivt_msg_response__a1_resp_cycletime_u1_string);
		snprintf(v[62], string_size, hv_current_ivt_msg_response__a2_resp_cycletime_u2_string);
		snprintf(v[63], string_size, hv_current_ivt_msg_response__a3_resp_cycletime_u3_string);
		snprintf(v[64], string_size, hv_current_ivt_msg_response__a4_resp_cycletime_t_string);
		snprintf(v[65], string_size, hv_current_ivt_msg_response__a5_resp_cycletime_w_string);
		snprintf(v[66], string_size, hv_current_ivt_msg_response__a6_resp_cycletime_as_string);
		snprintf(v[67], string_size, hv_current_ivt_msg_response__a7_resp_cycletime_wh_string);
		snprintf(v[68], string_size, hv_current_ivt_msg_response__b1_06_trigger_as_string);
		snprintf(v[69], string_size, hv_current_ivt_msg_response__b1_05_trigger_w_string);
		snprintf(v[70], string_size, hv_current_ivt_msg_response__b1_04_trigger_t_string);
		snprintf(v[71], string_size, hv_current_ivt_msg_response__b1_03_trigger_u3_string);
		snprintf(v[72], string_size, hv_current_ivt_msg_response__b1_02_trigger_u2_string);
		snprintf(v[73], string_size, hv_current_ivt_msg_response__b1_01_trigger_u1_string);
		snprintf(v[74], string_size, hv_current_ivt_msg_response__b1_00_trigger_i_string);
		snprintf(v[75], string_size, hv_current_ivt_msg_response__b4_resp_startup_mode_string);
		snprintf(v[76], string_size, hv_current_ivt_msg_response__bf_restart_alive_sn_string);
		snprintf(v[77], string_size, hv_current_ivt_msg_response__ba_resp_sw_ver_revision_string);
		snprintf(v[78], string_size, hv_current_ivt_msg_response__90_resp_can_id_sn_i_string);
		snprintf(v[79], string_size, hv_current_ivt_msg_response__91_resp_can_id_sn_u1_string);
		snprintf(v[80], string_size, hv_current_ivt_msg_response__92_resp_can_id_sn_u2_string);
		snprintf(v[81], string_size, hv_current_ivt_msg_response__93_resp_can_id_sn_u3_string);
		snprintf(v[82], string_size, hv_current_ivt_msg_response__94_resp_can_id_sn_t_string);
		snprintf(v[83], string_size, hv_current_ivt_msg_response__95_resp_can_id_sn_w_string);
		snprintf(v[84], string_size, hv_current_ivt_msg_response__96_resp_can_id_sn_as_string);
		snprintf(v[85], string_size, hv_current_ivt_msg_response__97_resp_can_id_sn_wh_string);
		snprintf(v[86], string_size, hv_current_ivt_msg_response__9d_resp_can_id_sn_command_string);
		snprintf(v[87], string_size, hv_current_ivt_msg_response__9f_resp_can_id_sn_response_string);
		snprintf(v[88], string_size, hv_current_ivt_msg_response__b0_resp_reset_device_sn_string);
		snprintf(v[89], string_size, hv_current_ivt_msg_response__b4_resp_code_level_string);
		snprintf(v[90], string_size, hv_current_ivt_msg_response__b5_resp_oc_pos_reset_threshold_string);
		snprintf(v[91], string_size, hv_current_ivt_msg_response__b6_resp_oc_neg_reset_threshold_string);
		snprintf(v[92], string_size, hv_current_ivt_msg_response__b9_resp_device_voltage_chan_string);
		snprintf(v[93], string_size, hv_current_ivt_msg_response__ba_resp_sw_ver_vear_string);
		snprintf(v[94], string_size, hv_current_ivt_msg_response__b9_resp_device_toi_string);
		snprintf(v[95], string_size, hv_current_ivt_msg_response__ba_resp_sw_ver_month_string);
		snprintf(v[96], string_size, hv_current_ivt_msg_response__b9_resp_device_com_string);
		snprintf(v[97], string_size, hv_current_ivt_msg_response__ba_resp_sw_ver_day_string);
		snprintf(v[98], string_size, hv_current_ivt_msg_response__b9_resp_device_v_supply_string);
		snprintf(v[99], string_size, hv_current_ivt_msg_response__ba_resp_sw_ver_internal_string);

		return 0;
	case 1317:
		if(7 > fields_size) return 1;
		snprintf(v[0], string_size, hv_current_ivt_msg_result_t_ivt_id_result_t_string);
		snprintf(v[1], string_size, hv_current_ivt_msg_result_t_ivt_result_t_system_error_string);
		snprintf(v[2], string_size, hv_current_ivt_msg_result_t_ivt_result_t_measurement_error_string);
		snprintf(v[3], string_size, hv_current_ivt_msg_result_t_ivt_result_t_channel_error_string);
		snprintf(v[4], string_size, hv_current_ivt_msg_result_t_ivt_result_t_ocs_string);
		snprintf(v[5], string_size, hv_current_ivt_msg_result_t_ivt_msgcount_result_t_string);
		snprintf(v[6], string_size, hv_current_ivt_msg_result_t_ivt_result_t_string);

		return 0;
	case 1316:
		if(7 > fields_size) return 1;
		snprintf(v[0], string_size, hv_current_ivt_msg_result_u3_ivt_id_result_u3_string);
		snprintf(v[1], string_size, hv_current_ivt_msg_result_u3_ivt_result_u3_system_error_string);
		snprintf(v[2], string_size, hv_current_ivt_msg_result_u3_ivt_result_u3_measurement_error_string);
		snprintf(v[3], string_size, hv_current_ivt_msg_result_u3_ivt_result_u3_channel_error_string);
		snprintf(v[4], string_size, hv_current_ivt_msg_result_u3_ivt_result_u3_ocs_string);
		snprintf(v[5], string_size, hv_current_ivt_msg_result_u3_ivt_msgcount_result_u3_string);
		snprintf(v[6], string_size, hv_current_ivt_msg_result_u3_ivt_result_u3_string);

		return 0;
	case 1315:
		if(7 > fields_size) return 1;
		snprintf(v[0], string_size, hv_current_ivt_msg_result_u2_ivt_id_result_u2_string);
		snprintf(v[1], string_size, hv_current_ivt_msg_result_u2_ivt_result_u2_system_error_string);
		snprintf(v[2], string_size, hv_current_ivt_msg_result_u2_ivt_result_u2_measurement_error_string);
		snprintf(v[3], string_size, hv_current_ivt_msg_result_u2_ivt_result_u2_channel_error_string);
		snprintf(v[4], string_size, hv_current_ivt_msg_result_u2_ivt_result_u2_ocs_string);
		snprintf(v[5], string_size, hv_current_ivt_msg_result_u2_ivt_msgcount_result_u2_string);
		snprintf(v[6], string_size, hv_current_ivt_msg_result_u2_ivt_result_u2_string);

		return 0;
	case 1314:
		if(7 > fields_size) return 1;
		snprintf(v[0], string_size, hv_current_ivt_msg_result_u1_ivt_id_result_u1_string);
		snprintf(v[1], string_size, hv_current_ivt_msg_result_u1_ivt_result_u1_system_error_string);
		snprintf(v[2], string_size, hv_current_ivt_msg_result_u1_ivt_result_u1_measurement_error_string);
		snprintf(v[3], string_size, hv_current_ivt_msg_result_u1_ivt_result_u1_channel_error_string);
		snprintf(v[4], string_size, hv_current_ivt_msg_result_u1_ivt_result_u1_ocs_string);
		snprintf(v[5], string_size, hv_current_ivt_msg_result_u1_ivt_msgcount_result_u1_string);
		snprintf(v[6], string_size, hv_current_ivt_msg_result_u1_ivt_result_u1_string);

		return 0;
	case 1313:
		if(7 > fields_size) return 1;
		snprintf(v[0], string_size, hv_current_ivt_msg_result_i_ivt_id_result_i_string);
		snprintf(v[1], string_size, hv_current_ivt_msg_result_i_ivt_result_i_system_error_string);
		snprintf(v[2], string_size, hv_current_ivt_msg_result_i_ivt_result_i_measurement_error_string);
		snprintf(v[3], string_size, hv_current_ivt_msg_result_i_ivt_result_i_channel_error_string);
		snprintf(v[4], string_size, hv_current_ivt_msg_result_i_ivt_result_i_ocs_string);
		snprintf(v[5], string_size, hv_current_ivt_msg_result_i_ivt_msgcount_result_i_string);
		snprintf(v[6], string_size, hv_current_ivt_msg_result_i_ivt_result_i_string);

		return 0;
	case 1041:
		if(106 > fields_size) return 1;
		snprintf(v[0], string_size, hv_current_ivt_msg_cmd_ivt_id_cmd_string);
		snprintf(v[1], string_size, hv_current_ivt_msg_cmd__31_trigger_spare_string);
		snprintf(v[2], string_size, hv_current_ivt_msg_cmd__10_set_can_id_val_i_string);
		snprintf(v[3], string_size, hv_current_ivt_msg_cmd__11_set_can_id_val_u1_string);
		snprintf(v[4], string_size, hv_current_ivt_msg_cmd__12_set_can_id_val_u2_string);
		snprintf(v[5], string_size, hv_current_ivt_msg_cmd__13_set_can_id_val_u3_string);
		snprintf(v[6], string_size, hv_current_ivt_msg_cmd__14_set_can_id_val_t_string);
		snprintf(v[7], string_size, hv_current_ivt_msg_cmd__15_set_can_id_val_w_string);
		snprintf(v[8], string_size, hv_current_ivt_msg_cmd__16_set_can_id_val_as_string);
		snprintf(v[9], string_size, hv_current_ivt_msg_cmd__17_set_can_id_val_wh_string);
		snprintf(v[10], string_size, hv_current_ivt_msg_cmd__1d_set_can_id_val_command_string);
		snprintf(v[11], string_size, hv_current_ivt_msg_cmd__1f_set_can_id_val_response_string);
		snprintf(v[12], string_size, hv_current_ivt_msg_cmd__20_conf_sign_i_string);
		snprintf(v[13], string_size, hv_current_ivt_msg_cmd__21_conf_sign_u1_string);
		snprintf(v[14], string_size, hv_current_ivt_msg_cmd__22_conf_sign_u2_string);
		snprintf(v[15], string_size, hv_current_ivt_msg_cmd__23_conf_sign_u3_string);
		snprintf(v[16], string_size, hv_current_ivt_msg_cmd__24_conf_sign_t_string);
		snprintf(v[17], string_size, hv_current_ivt_msg_cmd__25_conf_sign_w_string);
		snprintf(v[18], string_size, hv_current_ivt_msg_cmd__26_conf_sign_as_string);
		snprintf(v[19], string_size, hv_current_ivt_msg_cmd__27_conf_sign_wh_string);
		snprintf(v[20], string_size, hv_current_ivt_msg_cmd__30_reset_item_string);
		snprintf(v[21], string_size, hv_current_ivt_msg_cmd__32_store_dummy_string);
		snprintf(v[22], string_size, hv_current_ivt_msg_cmd__33_oc_test_time_string);
		snprintf(v[23], string_size, hv_current_ivt_msg_cmd__35_oc_pos_set_threshold_string);
		snprintf(v[24], string_size, hv_current_ivt_msg_cmd__36_oc_neg_set_threshold_string);
		snprintf(v[25], string_size, hv_current_ivt_msg_cmd__3a_restart_to_bitrate_string);
		snprintf(v[26], string_size, hv_current_ivt_msg_cmd__3d_restart_default_dummy_string);
		snprintf(v[27], string_size, hv_current_ivt_msg_cmd__3f_restart_dummy_string);
		snprintf(v[28], string_size, hv_current_ivt_msg_cmd__40_get_measerror_item_string);
		snprintf(v[29], string_size, hv_current_ivt_msg_cmd__41_get_systemerror_item_string);
		snprintf(v[30], string_size, hv_current_ivt_msg_cmd__42_get_alllogdata_item_string);
		snprintf(v[31], string_size, hv_current_ivt_msg_cmd__43_get_logdata_item_string);
		snprintf(v[32], string_size, hv_current_ivt_msg_cmd__60_get_result_dummy_i_string);
		snprintf(v[33], string_size, hv_current_ivt_msg_cmd__61_get_result_dummy_u1_string);
		snprintf(v[34], string_size, hv_current_ivt_msg_cmd__62_get_result_dummy_u2_string);
		snprintf(v[35], string_size, hv_current_ivt_msg_cmd__63_get_result_dummy_u3_string);
		snprintf(v[36], string_size, hv_current_ivt_msg_cmd__64_get_result_dummy_t_string);
		snprintf(v[37], string_size, hv_current_ivt_msg_cmd__65_get_result_dummy_w_string);
		snprintf(v[38], string_size, hv_current_ivt_msg_cmd__66_get_result_dummy_as_string);
		snprintf(v[39], string_size, hv_current_ivt_msg_cmd__67_get_result_dummy_wh_string);
		snprintf(v[40], string_size, hv_current_ivt_msg_cmd__73_get_oc_test_dummy_string);
		snprintf(v[41], string_size, hv_current_ivt_msg_cmd__74_get_mode_dummy_string);
		snprintf(v[42], string_size, hv_current_ivt_msg_cmd__75_get_oc_pos_dummy_string);
		snprintf(v[43], string_size, hv_current_ivt_msg_cmd__76_get_oc_neg_dummy_string);
		snprintf(v[44], string_size, hv_current_ivt_msg_cmd__79_get_device_id_dummy_string);
		snprintf(v[45], string_size, hv_current_ivt_msg_cmd__7a_get_sw_version_dummy_string);
		snprintf(v[46], string_size, hv_current_ivt_msg_cmd__7b_get_serien_nr_dummy_string);
		snprintf(v[47], string_size, hv_current_ivt_msg_cmd__7c_get_art_nr_dummy_string);
		snprintf(v[48], string_size, hv_current_ivt_msg_cmd__20_conf_endianess_i_string);
		snprintf(v[49], string_size, hv_current_ivt_msg_cmd__21_conf_endianess_u1_string);
		snprintf(v[50], string_size, hv_current_ivt_msg_cmd__22_conf_endianess_u2_string);
		snprintf(v[51], string_size, hv_current_ivt_msg_cmd__23_conf_endianess_u3_string);
		snprintf(v[52], string_size, hv_current_ivt_msg_cmd__24_conf_endianess_t_string);
		snprintf(v[53], string_size, hv_current_ivt_msg_cmd__25_conf_endianess_w_string);
		snprintf(v[54], string_size, hv_current_ivt_msg_cmd__26_conf_endianess_as_string);
		snprintf(v[55], string_size, hv_current_ivt_msg_cmd__27_conf_endianess_wh_string);
		snprintf(v[56], string_size, hv_current_ivt_msg_cmd__20_conf_triggermode_i_string);
		snprintf(v[57], string_size, hv_current_ivt_msg_cmd__21_conf_triggermode_u1_string);
		snprintf(v[58], string_size, hv_current_ivt_msg_cmd__22_conf_triggermode_u2_string);
		snprintf(v[59], string_size, hv_current_ivt_msg_cmd__23_conf_triggermode_u3_string);
		snprintf(v[60], string_size, hv_current_ivt_msg_cmd__24_conf_triggermode_t_string);
		snprintf(v[61], string_size, hv_current_ivt_msg_cmd__25_conf_triggermode_w_string);
		snprintf(v[62], string_size, hv_current_ivt_msg_cmd__26_conf_triggermode_as_string);
		snprintf(v[63], string_size, hv_current_ivt_msg_cmd__27_conf_triggermode_wh_string);
		snprintf(v[64], string_size, hv_current_ivt_msg_cmd__34_actual_mode_string);
		snprintf(v[65], string_size, hv_current_ivt_msg_cmd__31_07_trigger_wh_string);
		snprintf(v[66], string_size, hv_current_ivt_msg_cmd__20_conf_cycletime_i_string);
		snprintf(v[67], string_size, hv_current_ivt_msg_cmd__21_conf_cycletime_u1_string);
		snprintf(v[68], string_size, hv_current_ivt_msg_cmd__22_conf_cycletime_u2_string);
		snprintf(v[69], string_size, hv_current_ivt_msg_cmd__23_conf_cycletime_u3_string);
		snprintf(v[70], string_size, hv_current_ivt_msg_cmd__24_conf_cycletime_t_string);
		snprintf(v[71], string_size, hv_current_ivt_msg_cmd__25_conf_cycletime_w_string);
		snprintf(v[72], string_size, hv_current_ivt_msg_cmd__26_conf_cycletime_as_string);
		snprintf(v[73], string_size, hv_current_ivt_msg_cmd__27_conf_cycletime_wh_string);
		snprintf(v[74], string_size, hv_current_ivt_msg_cmd__31_06_trigger_as_string);
		snprintf(v[75], string_size, hv_current_ivt_msg_cmd__31_05_trigger_w_string);
		snprintf(v[76], string_size, hv_current_ivt_msg_cmd__31_04_trigger_t_string);
		snprintf(v[77], string_size, hv_current_ivt_msg_cmd__31_03_trigger_u3_string);
		snprintf(v[78], string_size, hv_current_ivt_msg_cmd__31_02_trigger_u2_string);
		snprintf(v[79], string_size, hv_current_ivt_msg_cmd__31_01_trigger_u1_string);
		snprintf(v[80], string_size, hv_current_ivt_msg_cmd__31_00_trigger_i_string);
		snprintf(v[81], string_size, hv_current_ivt_msg_cmd__34_startup_mode_string);
		snprintf(v[82], string_size, hv_current_ivt_msg_cmd__10_set_can_id_sn_i_string);
		snprintf(v[83], string_size, hv_current_ivt_msg_cmd__11_set_can_id_sn_u1_string);
		snprintf(v[84], string_size, hv_current_ivt_msg_cmd__12_set_can_id_sn_u2_string);
		snprintf(v[85], string_size, hv_current_ivt_msg_cmd__13_set_can_id_sn_u3_string);
		snprintf(v[86], string_size, hv_current_ivt_msg_cmd__14_set_can_id_sn_t_string);
		snprintf(v[87], string_size, hv_current_ivt_msg_cmd__15_set_can_id_sn_w_string);
		snprintf(v[88], string_size, hv_current_ivt_msg_cmd__16_set_can_id_sn_as_string);
		snprintf(v[89], string_size, hv_current_ivt_msg_cmd__17_set_can_id_sn_wh_string);
		snprintf(v[90], string_size, hv_current_ivt_msg_cmd__1d_set_can_id_sn_command_string);
		snprintf(v[91], string_size, hv_current_ivt_msg_cmd__1f_set_can_id_sn_response_string);
		snprintf(v[92], string_size, hv_current_ivt_msg_cmd__30_reset_device_sn_string);
		snprintf(v[93], string_size, hv_current_ivt_msg_cmd__34_code_level_string);
		snprintf(v[94], string_size, hv_current_ivt_msg_cmd__35_oc_pos_reset_threshold_string);
		snprintf(v[95], string_size, hv_current_ivt_msg_cmd__36_oc_neg_reset_threshold_string);
		snprintf(v[96], string_size, hv_current_ivt_msg_cmd__50_get_can_id_sn_i_string);
		snprintf(v[97], string_size, hv_current_ivt_msg_cmd__51_get_can_id_sn_u1_string);
		snprintf(v[98], string_size, hv_current_ivt_msg_cmd__52_get_can_id_sn_u2_string);
		snprintf(v[99], string_size, hv_current_ivt_msg_cmd__53_get_can_id_sn_u3_string);
		snprintf(v[100], string_size, hv_current_ivt_msg_cmd__54_get_can_id_sn_t_string);
		snprintf(v[101], string_size, hv_current_ivt_msg_cmd__55_get_can_id_sn_w_string);
		snprintf(v[102], string_size, hv_current_ivt_msg_cmd__56_get_can_id_sn_as_string);
		snprintf(v[103], string_size, hv_current_ivt_msg_cmd__57_get_can_id_sn_wh_string);
		snprintf(v[104], string_size, hv_current_ivt_msg_cmd__5d_get_can_id_sn_command_string);
		snprintf(v[105], string_size, hv_current_ivt_msg_cmd__5f_get_can_id_sn_response_string);

		return 0;

    }
    return 0;
}
int hv_current_enum_fields(int enum_id, char **v, size_t fields_size, size_t string_size)
{
    switch(enum_id)
    {
	case 0:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, "hv_current_ivt_msg_result_wh_ivt_id_result_wh_Vt_Result_Wh");

		return 0;
	case 1:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, "hv_current_ivt_msg_result_as_ivt_id_result_as_Vt_Result_As");

		return 0;
	case 2:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, "hv_current_ivt_msg_result_w_ivt_id_result_w_Vt_Result_W");

		return 0;
	case 3:
		if(35 > fields_size) return 1;
		snprintf(v[0], string_size, "hv_current_ivt_msg_response_ivt_id_response_Resp_Cmd_Wrong_Command");
		snprintf(v[1], string_size, "hv_current_ivt_msg_response_ivt_id_response_Resp_Get_Set_ALIVE");
		snprintf(v[2], string_size, "hv_current_ivt_msg_response_ivt_id_response_Resp_Get_Set_ArtNr");
		snprintf(v[3], string_size, "hv_current_ivt_msg_response_ivt_id_response_Resp_Get_Set_Serialnumber");
		snprintf(v[4], string_size, "hv_current_ivt_msg_response_ivt_id_response_Resp_Get_Set_SW_VERSION");
		snprintf(v[5], string_size, "hv_current_ivt_msg_response_ivt_id_response_Resp_Get_Set_DEVICE_ID");
		snprintf(v[6], string_size, "hv_current_ivt_msg_response_ivt_id_response_Resp_Get_Set_THRESHOLD_NEG");
		snprintf(v[7], string_size, "hv_current_ivt_msg_response_ivt_id_response_Resp_Get_Set_THRESHOLD_POS");
		snprintf(v[8], string_size, "hv_current_ivt_msg_response_ivt_id_response_Resp_Get_Set_MODE");
		snprintf(v[9], string_size, "hv_current_ivt_msg_response_ivt_id_response_Resp_Get_Set_OC_TEST_TIME");
		snprintf(v[10], string_size, "hv_current_ivt_msg_response_ivt_id_response_Resp_Get_Set_STORE");
		snprintf(v[11], string_size, "hv_current_ivt_msg_response_ivt_id_response_Resp_Get_Set_TRIGGER");
		snprintf(v[12], string_size, "hv_current_ivt_msg_response_ivt_id_response_Resp_Get_Set_Reset_Error_Logdata");
		snprintf(v[13], string_size, "hv_current_ivt_msg_response_ivt_id_response_Resp_Config_Result_Wh");
		snprintf(v[14], string_size, "hv_current_ivt_msg_response_ivt_id_response_Resp_Config_Result_As");
		snprintf(v[15], string_size, "hv_current_ivt_msg_response_ivt_id_response_Resp_Config_Result_W");
		snprintf(v[16], string_size, "hv_current_ivt_msg_response_ivt_id_response_Resp_Config_Result_T");
		snprintf(v[17], string_size, "hv_current_ivt_msg_response_ivt_id_response_Resp_Config_Result_U3");
		snprintf(v[18], string_size, "hv_current_ivt_msg_response_ivt_id_response_Resp_Config_Result_U2");
		snprintf(v[19], string_size, "hv_current_ivt_msg_response_ivt_id_response_Resp_Config_Result_U1");
		snprintf(v[20], string_size, "hv_current_ivt_msg_response_ivt_id_response_Resp_Config_Result_I");
		snprintf(v[21], string_size, "hv_current_ivt_msg_response_ivt_id_response_Resp_CAN_ID_Response");
		snprintf(v[22], string_size, "hv_current_ivt_msg_response_ivt_id_response_Resp_CAN_ID_Command");
		snprintf(v[23], string_size, "hv_current_ivt_msg_response_ivt_id_response_Resp_CAN_ID_Res_Wh");
		snprintf(v[24], string_size, "hv_current_ivt_msg_response_ivt_id_response_Resp_CAN_ID_Res_As");
		snprintf(v[25], string_size, "hv_current_ivt_msg_response_ivt_id_response_Resp_CAN_ID_Res_W");
		snprintf(v[26], string_size, "hv_current_ivt_msg_response_ivt_id_response_Resp_CAN_ID_Res_I");
		snprintf(v[27], string_size, "hv_current_ivt_msg_response_ivt_id_response_Resp_CAN_ID_Res_T");
		snprintf(v[28], string_size, "hv_current_ivt_msg_response_ivt_id_response_Resp_CAN_ID_Res_U3");
		snprintf(v[29], string_size, "hv_current_ivt_msg_response_ivt_id_response_Resp_CAN_ID_Res_U2");
		snprintf(v[30], string_size, "hv_current_ivt_msg_response_ivt_id_response_Resp_CAN_ID_Res_U1");
		snprintf(v[31], string_size, "hv_current_ivt_msg_response_ivt_id_response_Resp_Error_Log_Logdata_Since_Res");
		snprintf(v[32], string_size, "hv_current_ivt_msg_response_ivt_id_response_Resp_Error_Log_Overall_Logdata");
		snprintf(v[33], string_size, "hv_current_ivt_msg_response_ivt_id_response_Resp_Error_Log_System_Error");
		snprintf(v[34], string_size, "hv_current_ivt_msg_response_ivt_id_response_Resp_Error_Log_Measurement_Error");

		return 0;
	case 4:
		if(16 > fields_size) return 1;
		snprintf(v[0], string_size, "hv_current_ivt_msg_response__80_resp_measerror_item_Resp_error_calibration_data");
		snprintf(v[1], string_size, "hv_current_ivt_msg_response__80_resp_measerror_item_Resp_error_ntc_I_OpenCirc");
		snprintf(v[2], string_size, "hv_current_ivt_msg_response__80_resp_measerror_item_Resp_error_ntc_h_OpenCirc");
		snprintf(v[3], string_size, "hv_current_ivt_msg_response__80_resp_measerror_item_Resp_error_meas_U3_OpenCirc");
		snprintf(v[4], string_size, "hv_current_ivt_msg_response__80_resp_measerror_item_Resp_error_meas_U2_OpenCirc");
		snprintf(v[5], string_size, "hv_current_ivt_msg_response__80_resp_measerror_item_Resp_error_meas_U1_OpenCirc");
		snprintf(v[6], string_size, "hv_current_ivt_msg_response__80_resp_measerror_item_Resp_error_meas_I1_OpenCirc");
		snprintf(v[7], string_size, "hv_current_ivt_msg_response__80_resp_measerror_item_Resp__error_therm_EMF_correction");
		snprintf(v[8], string_size, "hv_current_ivt_msg_response__80_resp_measerror_item_Resp_error_cur_meas_implausible");
		snprintf(v[9], string_size, "hv_current_ivt_msg_response__80_resp_measerror_item_Resp_error_Vref");
		snprintf(v[10], string_size, "hv_current_ivt_msg_response__80_resp_measerror_item_Resp_error_Underflow_ADC_ch_2");
		snprintf(v[11], string_size, "hv_current_ivt_msg_response__80_resp_measerror_item_Resp_error_Overflow_ADC_ch_2");
		snprintf(v[12], string_size, "hv_current_ivt_msg_response__80_resp_measerror_item_Resp_error_Underflow_ADC_ch_1");
		snprintf(v[13], string_size, "hv_current_ivt_msg_response__80_resp_measerror_item_Reso_error_Overflow_ADC_ch_1");
		snprintf(v[14], string_size, "hv_current_ivt_msg_response__80_resp_measerror_item_Resp_error_ADC_interrupt");
		snprintf(v[15], string_size, "hv_current_ivt_msg_response__80_resp_measerror_item_Resonse_all_meas_errors");

		return 0;
	case 5:
		if(17 > fields_size) return 1;
		snprintf(v[0], string_size, "hv_current_ivt_msg_response__81_resp_systemerror_item_Resp_error_Reset_EMC");
		snprintf(v[1], string_size, "hv_current_ivt_msg_response__81_resp_systemerror_item_Resp_error_Reset_Watchdog");
		snprintf(v[2], string_size, "hv_current_ivt_msg_response__81_resp_systemerror_item_Resp_error_Reset_illegal_opcode");
		snprintf(v[3], string_size, "hv_current_ivt_msg_response__81_resp_systemerror_item_Resp_error_ADC_Clock");
		snprintf(v[4], string_size, "hv_current_ivt_msg_response__81_resp_systemerror_item_Resp_error_eeprom_rw");
		snprintf(v[5], string_size, "hv_current_ivt_msg_response__81_resp_systemerror_item_Resp_error_Overcurrent_detection");
		snprintf(v[6], string_size, "hv_current_ivt_msg_response__81_resp_systemerror_item_Resp_error_Configuration");
		snprintf(v[7], string_size, "hv_current_ivt_msg_response__81_resp_systemerror_item_Resp_error_System_Init");
		snprintf(v[8], string_size, "hv_current_ivt_msg_response__81_resp_systemerror_item_Resp_error_System_Clock");
		snprintf(v[9], string_size, "hv_current_ivt_msg_response__81_resp_systemerror_item_Resp_error_Power_failure");
		snprintf(v[10], string_size, "hv_current_ivt_msg_response__81_resp_systemerror_item_Resp_error_Undertemp");
		snprintf(v[11], string_size, "hv_current_ivt_msg_response__81_resp_systemerror_item_Resp_error_Overtemp");
		snprintf(v[12], string_size, "hv_current_ivt_msg_response__81_resp_systemerror_item_Resp_error_CAN_bus_transmit_Data");
		snprintf(v[13], string_size, "hv_current_ivt_msg_response__81_resp_systemerror_item_Resp_error_CAN_bus_receive_Data");
		snprintf(v[14], string_size, "hv_current_ivt_msg_response__81_resp_systemerror_item_Resp_error_Parameter_CRC");
		snprintf(v[15], string_size, "hv_current_ivt_msg_response__81_resp_systemerror_item_Resp_error_code_CRC");
		snprintf(v[16], string_size, "hv_current_ivt_msg_response__81_resp_systemerror_item_Resonse_all_SystemErrors");

		return 0;
	case 6:
		if(30 > fields_size) return 1;
		snprintf(v[0], string_size, "hv_current_ivt_msg_response__82_resp_alllogdata_item_Resp_temp_minimum");
		snprintf(v[1], string_size, "hv_current_ivt_msg_response__82_resp_alllogdata_item_Resp_temp_maxmimum");
		snprintf(v[2], string_size, "hv_current_ivt_msg_response__82_resp_alllogdata_item_Resp_U3_minimum");
		snprintf(v[3], string_size, "hv_current_ivt_msg_response__82_resp_alllogdata_item_Resp_U3_maximum");
		snprintf(v[4], string_size, "hv_current_ivt_msg_response__82_resp_alllogdata_item_Resp_U2_minimum");
		snprintf(v[5], string_size, "hv_current_ivt_msg_response__82_resp_alllogdata_item_Resp_U2_maxmimum");
		snprintf(v[6], string_size, "hv_current_ivt_msg_response__82_resp_alllogdata_item_Resp_U1_minimum");
		snprintf(v[7], string_size, "hv_current_ivt_msg_response__82_resp_alllogdata_item_Resp_U1_maximum");
		snprintf(v[8], string_size, "hv_current_ivt_msg_response__82_resp_alllogdata_item_Resp_current_minimum");
		snprintf(v[9], string_size, "hv_current_ivt_msg_response__82_resp_alllogdata_item_Resp_current_maximum");
		snprintf(v[10], string_size, "hv_current_ivt_msg_response__82_resp_alllogdata_item_Resp_oc_negative_activated");
		snprintf(v[11], string_size, "hv_current_ivt_msg_response__82_resp_alllogdata_item_Resp_oc_positive_activated");
		snprintf(v[12], string_size, "hv_current_ivt_msg_response__82_resp_alllogdata_item_Resp_run_temp_out_spec_limits");
		snprintf(v[13], string_size, "hv_current_ivt_msg_response__82_resp_alllogdata_item_Resp_run_temp_in_spec_limits");
		snprintf(v[14], string_size, "hv_current_ivt_msg_response__82_resp_alllogdata_item_Resp_run_volt_3_out_spec_limits");
		snprintf(v[15], string_size, "hv_current_ivt_msg_response__82_resp_alllogdata_item_Resp_run_volt_3_in_spec_limits");
		snprintf(v[16], string_size, "hv_current_ivt_msg_response__82_resp_alllogdata_item_Resp_run_volt_2_out_spec_limits");
		snprintf(v[17], string_size, "hv_current_ivt_msg_response__82_resp_alllogdata_item_Resp_run_volt_2_in_spec_limits");
		snprintf(v[18], string_size, "hv_current_ivt_msg_response__82_resp_alllogdata_item_Resp_run_volt_1_out_spec_limits");
		snprintf(v[19], string_size, "hv_current_ivt_msg_response__82_resp_alllogdata_item_Resp_run_volt_1_in_spec_limits");
		snprintf(v[20], string_size, "hv_current_ivt_msg_response__82_resp_alllogdata_item_Resp_run_cur_out_spec_limits");
		snprintf(v[21], string_size, "hv_current_ivt_msg_response__82_resp_alllogdata_item_Resp_run_cur_in_spec_limits");
		snprintf(v[22], string_size, "hv_current_ivt_msg_response__82_resp_alllogdata_item_Resp_run_overall");
		snprintf(v[23], string_size, "hv_current_ivt_msg_response__82_resp_alllogdata_item_Resp_energy_counter_discharging");
		snprintf(v[24], string_size, "hv_current_ivt_msg_response__82_resp_alllogdata_item_Resp_energy_counter_charging");
		snprintf(v[25], string_size, "hv_current_ivt_msg_response__82_resp_alllogdata_item_Resp_energy_counter_overall");
		snprintf(v[26], string_size, "hv_current_ivt_msg_response__82_resp_alllogdata_item_Resp_Ah_counter_discharging");
		snprintf(v[27], string_size, "hv_current_ivt_msg_response__82_resp_alllogdata_item_Resp_Ah_counter_charging");
		snprintf(v[28], string_size, "hv_current_ivt_msg_response__82_resp_alllogdata_item_Resp_Ah_counter_overall");
		snprintf(v[29], string_size, "hv_current_ivt_msg_response__82_resp_alllogdata_item_Response_on_Overall_Logdata");

		return 0;
	case 7:
		if(30 > fields_size) return 1;
		snprintf(v[0], string_size, "hv_current_ivt_msg_response__83_resp_logdata_item_Resp_temp_minimum");
		snprintf(v[1], string_size, "hv_current_ivt_msg_response__83_resp_logdata_item_Resp_temp_maxmimum");
		snprintf(v[2], string_size, "hv_current_ivt_msg_response__83_resp_logdata_item_Resp_U3_minimum");
		snprintf(v[3], string_size, "hv_current_ivt_msg_response__83_resp_logdata_item_Resp_U3_maximum");
		snprintf(v[4], string_size, "hv_current_ivt_msg_response__83_resp_logdata_item_Resp_U2_minimum");
		snprintf(v[5], string_size, "hv_current_ivt_msg_response__83_resp_logdata_item_Resp_U2_maxmimum");
		snprintf(v[6], string_size, "hv_current_ivt_msg_response__83_resp_logdata_item_Resp_U1_minimum");
		snprintf(v[7], string_size, "hv_current_ivt_msg_response__83_resp_logdata_item_Resp_U1_maximum");
		snprintf(v[8], string_size, "hv_current_ivt_msg_response__83_resp_logdata_item_Resp_current_minimum");
		snprintf(v[9], string_size, "hv_current_ivt_msg_response__83_resp_logdata_item_Resp_current_maximum");
		snprintf(v[10], string_size, "hv_current_ivt_msg_response__83_resp_logdata_item_Resp_oc_negative_activated");
		snprintf(v[11], string_size, "hv_current_ivt_msg_response__83_resp_logdata_item_Resp_oc_positive_activated");
		snprintf(v[12], string_size, "hv_current_ivt_msg_response__83_resp_logdata_item_Resp_run_temp_out_spec_limits");
		snprintf(v[13], string_size, "hv_current_ivt_msg_response__83_resp_logdata_item_Resp_run_temp_in_spec_limits");
		snprintf(v[14], string_size, "hv_current_ivt_msg_response__83_resp_logdata_item_Resp_run_volt_3_out_spec_limits");
		snprintf(v[15], string_size, "hv_current_ivt_msg_response__83_resp_logdata_item_Resp_run_volt_3_in_spec_limits");
		snprintf(v[16], string_size, "hv_current_ivt_msg_response__83_resp_logdata_item_Resp_run_volt_2_out_spec_limits");
		snprintf(v[17], string_size, "hv_current_ivt_msg_response__83_resp_logdata_item_Resp_run_volt_2_in_spec_limits");
		snprintf(v[18], string_size, "hv_current_ivt_msg_response__83_resp_logdata_item_Resp_run_volt_1_out_spec_limits");
		snprintf(v[19], string_size, "hv_current_ivt_msg_response__83_resp_logdata_item_Resp_run_volt_1_in_spec_limits");
		snprintf(v[20], string_size, "hv_current_ivt_msg_response__83_resp_logdata_item_Resp_run_cur_out_spec_limits");
		snprintf(v[21], string_size, "hv_current_ivt_msg_response__83_resp_logdata_item_Resp_run_cur_in_spec_limits");
		snprintf(v[22], string_size, "hv_current_ivt_msg_response__83_resp_logdata_item_Resp_run_overall");
		snprintf(v[23], string_size, "hv_current_ivt_msg_response__83_resp_logdata_item_Resp_energy_counter_discharging");
		snprintf(v[24], string_size, "hv_current_ivt_msg_response__83_resp_logdata_item_Resp_energy_counter_charging");
		snprintf(v[25], string_size, "hv_current_ivt_msg_response__83_resp_logdata_item_Resp_energy_counter_overall");
		snprintf(v[26], string_size, "hv_current_ivt_msg_response__83_resp_logdata_item_Resp_Ah_counter_discharging");
		snprintf(v[27], string_size, "hv_current_ivt_msg_response__83_resp_logdata_item_Resp_Ah_counter_charging");
		snprintf(v[28], string_size, "hv_current_ivt_msg_response__83_resp_logdata_item_Resp_Ah_counter_overall");
		snprintf(v[29], string_size, "hv_current_ivt_msg_response__83_resp_logdata_item_Response_all_Logdata_SinceReset");

		return 0;
	case 8:
		if(63 > fields_size) return 1;
		snprintf(v[0], string_size, "hv_current_ivt_msg_response__b0_resp_reset_item_Reset_temp_minimum");
		snprintf(v[1], string_size, "hv_current_ivt_msg_response__b0_resp_reset_item_Reset_temp_maximum");
		snprintf(v[2], string_size, "hv_current_ivt_msg_response__b0_resp_reset_item_Reset_U3_minimum");
		snprintf(v[3], string_size, "hv_current_ivt_msg_response__b0_resp_reset_item_Reset_U3_maximum");
		snprintf(v[4], string_size, "hv_current_ivt_msg_response__b0_resp_reset_item_Reset_U2_minimum");
		snprintf(v[5], string_size, "hv_current_ivt_msg_response__b0_resp_reset_item_Reset_U2_maximum");
		snprintf(v[6], string_size, "hv_current_ivt_msg_response__b0_resp_reset_item_Reset_U1_minimum");
		snprintf(v[7], string_size, "hv_current_ivt_msg_response__b0_resp_reset_item_Reset_U1_maximum");
		snprintf(v[8], string_size, "hv_current_ivt_msg_response__b0_resp_reset_item_Reset_Current_minimum");
		snprintf(v[9], string_size, "hv_current_ivt_msg_response__b0_resp_reset_item_Reset_Current_maximum");
		snprintf(v[10], string_size, "hv_current_ivt_msg_response__b0_resp_reset_item_Reset_Run_overcur_neg_activated");
		snprintf(v[11], string_size, "hv_current_ivt_msg_response__b0_resp_reset_item_Reset_Run_overcur_pos_activated");
		snprintf(v[12], string_size, "hv_current_ivt_msg_response__b0_resp_reset_item_Reset_Run_temp_out_spec_limits");
		snprintf(v[13], string_size, "hv_current_ivt_msg_response__b0_resp_reset_item_Reset_Run_temp_in_spec_limits");
		snprintf(v[14], string_size, "hv_current_ivt_msg_response__b0_resp_reset_item_Reset_Run_volt_3_out_spec_limits");
		snprintf(v[15], string_size, "hv_current_ivt_msg_response__b0_resp_reset_item_Reset_Run_volt_3_in_spec_limits");
		snprintf(v[16], string_size, "hv_current_ivt_msg_response__b0_resp_reset_item_Reset_Run_volt_2_out_spec_limits");
		snprintf(v[17], string_size, "hv_current_ivt_msg_response__b0_resp_reset_item_Reset_Run_volt_2_in_spec_limits");
		snprintf(v[18], string_size, "hv_current_ivt_msg_response__b0_resp_reset_item_Reset_Run_volt_1_out_spec_limits");
		snprintf(v[19], string_size, "hv_current_ivt_msg_response__b0_resp_reset_item_Reset_Run_volt_1_in_spec_limits");
		snprintf(v[20], string_size, "hv_current_ivt_msg_response__b0_resp_reset_item_Reset_Run_cur_out_spec_limits");
		snprintf(v[21], string_size, "hv_current_ivt_msg_response__b0_resp_reset_item_Reset_Run_cur_in_spec_limits");
		snprintf(v[22], string_size, "hv_current_ivt_msg_response__b0_resp_reset_item_Reset_Runtime_overall");
		snprintf(v[23], string_size, "hv_current_ivt_msg_response__b0_resp_reset_item_Reset_Energy_counter_discharging");
		snprintf(v[24], string_size, "hv_current_ivt_msg_response__b0_resp_reset_item_Reset_Energy_counter_charging");
		snprintf(v[25], string_size, "hv_current_ivt_msg_response__b0_resp_reset_item_Reset_Energy_counter_overall");
		snprintf(v[26], string_size, "hv_current_ivt_msg_response__b0_resp_reset_item_Reset_Ah_counter_discharging");
		snprintf(v[27], string_size, "hv_current_ivt_msg_response__b0_resp_reset_item_Reset_Ah_counter_charging");
		snprintf(v[28], string_size, "hv_current_ivt_msg_response__b0_resp_reset_item_Reset_Ah_counter_overall");
		snprintf(v[29], string_size, "hv_current_ivt_msg_response__b0_resp_reset_item_Reset_all_Logdata_Since_Reset");
		snprintf(v[30], string_size, "hv_current_ivt_msg_response__b0_resp_reset_item_Reset_Reset_EMC");
		snprintf(v[31], string_size, "hv_current_ivt_msg_response__b0_resp_reset_item_Reset_Reset_Watchdog");
		snprintf(v[32], string_size, "hv_current_ivt_msg_response__b0_resp_reset_item_Reset_illegal_opcode");
		snprintf(v[33], string_size, "hv_current_ivt_msg_response__b0_resp_reset_item_Reset_ADC_Clock");
		snprintf(v[34], string_size, "hv_current_ivt_msg_response__b0_resp_reset_item_Reset_eeprom_rw");
		snprintf(v[35], string_size, "hv_current_ivt_msg_response__b0_resp_reset_item_Reset_overcurrent_detection");
		snprintf(v[36], string_size, "hv_current_ivt_msg_response__b0_resp_reset_item_Reset_configuration");
		snprintf(v[37], string_size, "hv_current_ivt_msg_response__b0_resp_reset_item_Reset_system_init");
		snprintf(v[38], string_size, "hv_current_ivt_msg_response__b0_resp_reset_item_Reset_system_clock");
		snprintf(v[39], string_size, "hv_current_ivt_msg_response__b0_resp_reset_item_Reset_power_failure");
		snprintf(v[40], string_size, "hv_current_ivt_msg_response__b0_resp_reset_item_Reset_undertemp");
		snprintf(v[41], string_size, "hv_current_ivt_msg_response__b0_resp_reset_item_Reset_overtemp");
		snprintf(v[42], string_size, "hv_current_ivt_msg_response__b0_resp_reset_item_Reset_CAN_bus_transmit_Data");
		snprintf(v[43], string_size, "hv_current_ivt_msg_response__b0_resp_reset_item_Reset_CAN_bus_receive_Data");
		snprintf(v[44], string_size, "hv_current_ivt_msg_response__b0_resp_reset_item_Reset_Parameter_CRC");
		snprintf(v[45], string_size, "hv_current_ivt_msg_response__b0_resp_reset_item_Reset_Code_CRC");
		snprintf(v[46], string_size, "hv_current_ivt_msg_response__b0_resp_reset_item_Reset_all_System_errors");
		snprintf(v[47], string_size, "hv_current_ivt_msg_response__b0_resp_reset_item_Reset_calibration_data_");
		snprintf(v[48], string_size, "hv_current_ivt_msg_response__b0_resp_reset_item_Reset_ntc_I_OpenCircuit");
		snprintf(v[49], string_size, "hv_current_ivt_msg_response__b0_resp_reset_item_Reset_ntc_h_OpenCircuit");
		snprintf(v[50], string_size, "hv_current_ivt_msg_response__b0_resp_reset_item_Reset_voltage_measU3_OpenCircuit");
		snprintf(v[51], string_size, "hv_current_ivt_msg_response__b0_resp_reset_item_Reset_voltage_measU2_OpenCircuit");
		snprintf(v[52], string_size, "hv_current_ivt_msg_response__b0_resp_reset_item_Reset_voltage_measU1_OpenCircuit");
		snprintf(v[53], string_size, "hv_current_ivt_msg_response__b0_resp_reset_item_Reset_current_measI1_OpenCircuit");
		snprintf(v[54], string_size, "hv_current_ivt_msg_response__b0_resp_reset_item_Reset_thermal_EMF_correction");
		snprintf(v[55], string_size, "hv_current_ivt_msg_response__b0_resp_reset_item_Reset_error_current_implausible");
		snprintf(v[56], string_size, "hv_current_ivt_msg_response__b0_resp_reset_item_Reset_error_Vref");
		snprintf(v[57], string_size, "hv_current_ivt_msg_response__b0_resp_reset_item_Reset_error_Underflow_ADC_ch2");
		snprintf(v[58], string_size, "hv_current_ivt_msg_response__b0_resp_reset_item_Reset_error_Overflow_ADC_ch2");
		snprintf(v[59], string_size, "hv_current_ivt_msg_response__b0_resp_reset_item_Reset_error_Underflow_ADC_ch1");
		snprintf(v[60], string_size, "hv_current_ivt_msg_response__b0_resp_reset_item_Reset_error_Overflow_ADC_ch1");
		snprintf(v[61], string_size, "hv_current_ivt_msg_response__b0_resp_reset_item_Reset_error_ADC_interrupt");
		snprintf(v[62], string_size, "hv_current_ivt_msg_response__b0_resp_reset_item_Reset_all_measurement_errors");

		return 0;
	case 9:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "hv_current_ivt_msg_response__b9_resp_device_type_IVT_S");
		snprintf(v[1], string_size, "hv_current_ivt_msg_response__b9_resp_device_type_IVT_Mod");

		return 0;
	case 10:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "hv_current_ivt_msg_response__a0_resp_triggermode_i_CYCLIC");
		snprintf(v[1], string_size, "hv_current_ivt_msg_response__a0_resp_triggermode_i_TRIGGERED");
		snprintf(v[2], string_size, "hv_current_ivt_msg_response__a0_resp_triggermode_i_DISABLED");

		return 0;
	case 11:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "hv_current_ivt_msg_response__a1_resp_triggermode_u1_CYCLIC");
		snprintf(v[1], string_size, "hv_current_ivt_msg_response__a1_resp_triggermode_u1_TRIGGERED");
		snprintf(v[2], string_size, "hv_current_ivt_msg_response__a1_resp_triggermode_u1_DISABLED");

		return 0;
	case 12:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "hv_current_ivt_msg_response__a2_resp_triggermode_u2_CYCLIC");
		snprintf(v[1], string_size, "hv_current_ivt_msg_response__a2_resp_triggermode_u2_TRIGGERED");
		snprintf(v[2], string_size, "hv_current_ivt_msg_response__a2_resp_triggermode_u2_DISABLED");

		return 0;
	case 13:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "hv_current_ivt_msg_response__a3_resp_triggermode_u3_CYCLIC");
		snprintf(v[1], string_size, "hv_current_ivt_msg_response__a3_resp_triggermode_u3_TRIGGERED");
		snprintf(v[2], string_size, "hv_current_ivt_msg_response__a3_resp_triggermode_u3_DISABLED");

		return 0;
	case 14:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "hv_current_ivt_msg_response__a4_resp_triggermode_t_CYCLIC");
		snprintf(v[1], string_size, "hv_current_ivt_msg_response__a4_resp_triggermode_t_TRIGGERED");
		snprintf(v[2], string_size, "hv_current_ivt_msg_response__a4_resp_triggermode_t_DISABLED");

		return 0;
	case 15:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "hv_current_ivt_msg_response__a5_resp_triggermode_w_CYCLIC");
		snprintf(v[1], string_size, "hv_current_ivt_msg_response__a5_resp_triggermode_w_TRIGGERED");
		snprintf(v[2], string_size, "hv_current_ivt_msg_response__a5_resp_triggermode_w_DISABLED");

		return 0;
	case 16:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "hv_current_ivt_msg_response__a6_resp_triggermode_as_CYCLIC");
		snprintf(v[1], string_size, "hv_current_ivt_msg_response__a6_resp_triggermode_as_TRIGGERED");
		snprintf(v[2], string_size, "hv_current_ivt_msg_response__a6_resp_triggermode_as_DISABLED");

		return 0;
	case 17:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "hv_current_ivt_msg_response__a7_resp_triggermode_wh_CYCLIC");
		snprintf(v[1], string_size, "hv_current_ivt_msg_response__a7_resp_triggermode_wh_TRIGGERED");
		snprintf(v[2], string_size, "hv_current_ivt_msg_response__a7_resp_triggermode_wh_DISABLED");

		return 0;
	case 18:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "hv_current_ivt_msg_response__b4_resp_actual_mode_RUN");
		snprintf(v[1], string_size, "hv_current_ivt_msg_response__b4_resp_actual_mode_STOP");

		return 0;
	case 19:
		if(5 > fields_size) return 1;
		snprintf(v[0], string_size, "hv_current_ivt_msg_response__b9_resp_device_current_2500_A");
		snprintf(v[1], string_size, "hv_current_ivt_msg_response__b9_resp_device_current_1000_A");
		snprintf(v[2], string_size, "hv_current_ivt_msg_response__b9_resp_device_current_500_A");
		snprintf(v[3], string_size, "hv_current_ivt_msg_response__b9_resp_device_current_300_A");
		snprintf(v[4], string_size, "hv_current_ivt_msg_response__b9_resp_device_current_100_A");

		return 0;
	case 20:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "hv_current_ivt_msg_response__b4_resp_startup_mode_Run");
		snprintf(v[1], string_size, "hv_current_ivt_msg_response__b4_resp_startup_mode_Stop");

		return 0;
	case 21:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "hv_current_ivt_msg_response__b9_resp_device_voltage_chan_3_Channels");
		snprintf(v[1], string_size, "hv_current_ivt_msg_response__b9_resp_device_voltage_chan_0_Channels");

		return 0;
	case 22:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, "hv_current_ivt_msg_response__b9_resp_device_toi_I");

		return 0;
	case 23:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "hv_current_ivt_msg_response__b9_resp_device_com_CAN_2___not_terminated");
		snprintf(v[1], string_size, "hv_current_ivt_msg_response__b9_resp_device_com_CAN_1___terminated");
		snprintf(v[2], string_size, "hv_current_ivt_msg_response__b9_resp_device_com_none");

		return 0;
	case 24:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, "hv_current_ivt_msg_response__b9_resp_device_v_supply_12__24_V_nominal_supply_voltage");

		return 0;
	case 25:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, "hv_current_ivt_msg_result_t_ivt_id_result_t_Vt_Result_T");

		return 0;
	case 26:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, "hv_current_ivt_msg_result_u3_ivt_id_result_u3_Vt_Result_U3");

		return 0;
	case 27:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, "hv_current_ivt_msg_result_u2_ivt_id_result_u2_Vt_Result_U2");

		return 0;
	case 28:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, "hv_current_ivt_msg_result_u1_ivt_id_result_u1_Vt_Result_U1");

		return 0;
	case 29:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, "hv_current_ivt_msg_result_i_ivt_id_result_i_Vt_Result_I");

		return 0;
	case 30:
		if(58 > fields_size) return 1;
		snprintf(v[0], string_size, "hv_current_ivt_msg_cmd_ivt_id_cmd_Get_cmd_and_info_ArtNr");
		snprintf(v[1], string_size, "hv_current_ivt_msg_cmd_ivt_id_cmd_Get_cmd_and_info_SN");
		snprintf(v[2], string_size, "hv_current_ivt_msg_cmd_ivt_id_cmd_Get_cmd_and_info_SW_Version");
		snprintf(v[3], string_size, "hv_current_ivt_msg_cmd_ivt_id_cmd_Get_cmd_and_info_DEVICE_ID");
		snprintf(v[4], string_size, "hv_current_ivt_msg_cmd_ivt_id_cmd_Get_cmd_and_info_THRESHOLD_NEG");
		snprintf(v[5], string_size, "hv_current_ivt_msg_cmd_ivt_id_cmd_Get_cmd_and_info_THRESHOLD_POS");
		snprintf(v[6], string_size, "hv_current_ivt_msg_cmd_ivt_id_cmd_Get_cmd_and_info_MODE");
		snprintf(v[7], string_size, "hv_current_ivt_msg_cmd_ivt_id_cmd_Get_cmd_and_info_OC_TEST_TIME");
		snprintf(v[8], string_size, "hv_current_ivt_msg_cmd_ivt_id_cmd_Get_Config_Res_Wh");
		snprintf(v[9], string_size, "hv_current_ivt_msg_cmd_ivt_id_cmd_Get_Config_Res_As");
		snprintf(v[10], string_size, "hv_current_ivt_msg_cmd_ivt_id_cmd_Get_Config_Res_W");
		snprintf(v[11], string_size, "hv_current_ivt_msg_cmd_ivt_id_cmd_Get_Config_Res_T");
		snprintf(v[12], string_size, "hv_current_ivt_msg_cmd_ivt_id_cmd_Get_Config_Res_U3");
		snprintf(v[13], string_size, "hv_current_ivt_msg_cmd_ivt_id_cmd_Get_Config_Res_U2");
		snprintf(v[14], string_size, "hv_current_ivt_msg_cmd_ivt_id_cmd_Get_Config_Res_U1");
		snprintf(v[15], string_size, "hv_current_ivt_msg_cmd_ivt_id_cmd_Get_Config_Res_I");
		snprintf(v[16], string_size, "hv_current_ivt_msg_cmd_ivt_id_cmd_Get_CAN_ID_Response");
		snprintf(v[17], string_size, "hv_current_ivt_msg_cmd_ivt_id_cmd_Get_CAN_ID_Command");
		snprintf(v[18], string_size, "hv_current_ivt_msg_cmd_ivt_id_cmd_Get_CAN_ID_Res_Wh");
		snprintf(v[19], string_size, "hv_current_ivt_msg_cmd_ivt_id_cmd_Get_CAN_ID_Res_As");
		snprintf(v[20], string_size, "hv_current_ivt_msg_cmd_ivt_id_cmd_Get_CAN_ID_Res_W");
		snprintf(v[21], string_size, "hv_current_ivt_msg_cmd_ivt_id_cmd_Get_CAN_ID_Res_T");
		snprintf(v[22], string_size, "hv_current_ivt_msg_cmd_ivt_id_cmd_Get_CAN_ID_Res_U3");
		snprintf(v[23], string_size, "hv_current_ivt_msg_cmd_ivt_id_cmd_Get_CAN_ID_Res_U2");
		snprintf(v[24], string_size, "hv_current_ivt_msg_cmd_ivt_id_cmd_Get_CAN_ID_Res_U1");
		snprintf(v[25], string_size, "hv_current_ivt_msg_cmd_ivt_id_cmd_Get_CAN_ID_Res_I");
		snprintf(v[26], string_size, "hv_current_ivt_msg_cmd_ivt_id_cmd_Get_Logdata_Since_Reset");
		snprintf(v[27], string_size, "hv_current_ivt_msg_cmd_ivt_id_cmd_Get_Overall_Logdata");
		snprintf(v[28], string_size, "hv_current_ivt_msg_cmd_ivt_id_cmd_Get_System_Errors");
		snprintf(v[29], string_size, "hv_current_ivt_msg_cmd_ivt_id_cmd_Get_Measurement_Errors");
		snprintf(v[30], string_size, "hv_current_ivt_msg_cmd_ivt_id_cmd_Set_RESTART");
		snprintf(v[31], string_size, "hv_current_ivt_msg_cmd_ivt_id_cmd_Set_RESTART_to_default");
		snprintf(v[32], string_size, "hv_current_ivt_msg_cmd_ivt_id_cmd_RESTART_to_Bitrate");
		snprintf(v[33], string_size, "hv_current_ivt_msg_cmd_ivt_id_cmd_Set_THRESHOLD_neg");
		snprintf(v[34], string_size, "hv_current_ivt_msg_cmd_ivt_id_cmd_Set_THRESHOLD_pos");
		snprintf(v[35], string_size, "hv_current_ivt_msg_cmd_ivt_id_cmd_Set_MODE_Result_I");
		snprintf(v[36], string_size, "hv_current_ivt_msg_cmd_ivt_id_cmd_Set_CAN_ID_Result_I");
		snprintf(v[37], string_size, "hv_current_ivt_msg_cmd_ivt_id_cmd_Set_MODE");
		snprintf(v[38], string_size, "hv_current_ivt_msg_cmd_ivt_id_cmd_START_OC_TEST");
		snprintf(v[39], string_size, "hv_current_ivt_msg_cmd_ivt_id_cmd_STORE");
		snprintf(v[40], string_size, "hv_current_ivt_msg_cmd_ivt_id_cmd_TRIGGER");
		snprintf(v[41], string_size, "hv_current_ivt_msg_cmd_ivt_id_cmd_Reset_Err_Log");
		snprintf(v[42], string_size, "hv_current_ivt_msg_cmd_ivt_id_cmd_Set_MODE_Result_Wh");
		snprintf(v[43], string_size, "hv_current_ivt_msg_cmd_ivt_id_cmd_Set_MODE_Result_As");
		snprintf(v[44], string_size, "hv_current_ivt_msg_cmd_ivt_id_cmd_Set_MODE_Result_W");
		snprintf(v[45], string_size, "hv_current_ivt_msg_cmd_ivt_id_cmd_Set_CAN_ID_Result_Wh");
		snprintf(v[46], string_size, "hv_current_ivt_msg_cmd_ivt_id_cmd_Set_CAN_ID_Result_As");
		snprintf(v[47], string_size, "hv_current_ivt_msg_cmd_ivt_id_cmd_Set_CAN_ID_Result_W");
		snprintf(v[48], string_size, "hv_current_ivt_msg_cmd_ivt_id_cmd_Set_CAN_ID_Result_T");
		snprintf(v[49], string_size, "hv_current_ivt_msg_cmd_ivt_id_cmd_Set_MODE_Result_U3");
		snprintf(v[50], string_size, "hv_current_ivt_msg_cmd_ivt_id_cmd_Set_CAN_ID_Response");
		snprintf(v[51], string_size, "hv_current_ivt_msg_cmd_ivt_id_cmd_Set_CAN_ID_Cmd");
		snprintf(v[52], string_size, "hv_current_ivt_msg_cmd_ivt_id_cmd_Set_CAN_ID_Result_U3");
		snprintf(v[53], string_size, "hv_current_ivt_msg_cmd_ivt_id_cmd_Set_CAN_ID_Result_U2");
		snprintf(v[54], string_size, "hv_current_ivt_msg_cmd_ivt_id_cmd_Set_MODE_Result_T");
		snprintf(v[55], string_size, "hv_current_ivt_msg_cmd_ivt_id_cmd_Set_MODE_Result_U2");
		snprintf(v[56], string_size, "hv_current_ivt_msg_cmd_ivt_id_cmd_Set_MODE_Result_U1");
		snprintf(v[57], string_size, "hv_current_ivt_msg_cmd_ivt_id_cmd_Set_CAN_ID_Result_U1");

		return 0;
	case 31:
		if(63 > fields_size) return 1;
		snprintf(v[0], string_size, "hv_current_ivt_msg_cmd__30_reset_item_Reset_temp_minimum");
		snprintf(v[1], string_size, "hv_current_ivt_msg_cmd__30_reset_item_Reset_temp_maximum");
		snprintf(v[2], string_size, "hv_current_ivt_msg_cmd__30_reset_item_Reset_U3_minimum");
		snprintf(v[3], string_size, "hv_current_ivt_msg_cmd__30_reset_item_Reset_U3_maximum");
		snprintf(v[4], string_size, "hv_current_ivt_msg_cmd__30_reset_item_Reset_U2_minimum");
		snprintf(v[5], string_size, "hv_current_ivt_msg_cmd__30_reset_item_Reset_U2_maximum");
		snprintf(v[6], string_size, "hv_current_ivt_msg_cmd__30_reset_item_Reset_U1_minimum");
		snprintf(v[7], string_size, "hv_current_ivt_msg_cmd__30_reset_item_Reset_U1_maximum");
		snprintf(v[8], string_size, "hv_current_ivt_msg_cmd__30_reset_item_Reset_Current_minimum");
		snprintf(v[9], string_size, "hv_current_ivt_msg_cmd__30_reset_item_Reset_Current_maximum");
		snprintf(v[10], string_size, "hv_current_ivt_msg_cmd__30_reset_item_Reset_Run_overcur_neg_activated");
		snprintf(v[11], string_size, "hv_current_ivt_msg_cmd__30_reset_item_Reset_Run_overcur_pos_activated");
		snprintf(v[12], string_size, "hv_current_ivt_msg_cmd__30_reset_item_Reset_Run_temp_out_spec_limits");
		snprintf(v[13], string_size, "hv_current_ivt_msg_cmd__30_reset_item_Reset_Run_temp_in_spec_limits");
		snprintf(v[14], string_size, "hv_current_ivt_msg_cmd__30_reset_item_Reset_Run_volt_3_out_spec_limits");
		snprintf(v[15], string_size, "hv_current_ivt_msg_cmd__30_reset_item_Reset_Run_volt_3_in_spec_limits");
		snprintf(v[16], string_size, "hv_current_ivt_msg_cmd__30_reset_item_Reset_Run_volt_2_out_spec_limits");
		snprintf(v[17], string_size, "hv_current_ivt_msg_cmd__30_reset_item_Reset_Run_volt_2_in_spec_limits");
		snprintf(v[18], string_size, "hv_current_ivt_msg_cmd__30_reset_item_Reset_Run_volt_1_out_spec_limits");
		snprintf(v[19], string_size, "hv_current_ivt_msg_cmd__30_reset_item_Reset_Run_volt_1_in_spec_limits");
		snprintf(v[20], string_size, "hv_current_ivt_msg_cmd__30_reset_item_Reset_Run_cur_out_spec_limits");
		snprintf(v[21], string_size, "hv_current_ivt_msg_cmd__30_reset_item_Reset_Run_cur_in_spec_limits");
		snprintf(v[22], string_size, "hv_current_ivt_msg_cmd__30_reset_item_Reset_Runtime_overall");
		snprintf(v[23], string_size, "hv_current_ivt_msg_cmd__30_reset_item_Reset_Energy_counter_discharging");
		snprintf(v[24], string_size, "hv_current_ivt_msg_cmd__30_reset_item_Reset_Energy_counter_charging");
		snprintf(v[25], string_size, "hv_current_ivt_msg_cmd__30_reset_item_Reset_Energy_counter_overall");
		snprintf(v[26], string_size, "hv_current_ivt_msg_cmd__30_reset_item_Reset_Ah_counter_discharging");
		snprintf(v[27], string_size, "hv_current_ivt_msg_cmd__30_reset_item_Reset_Ah_counter_charging");
		snprintf(v[28], string_size, "hv_current_ivt_msg_cmd__30_reset_item_Reset_Ah_counter_overall");
		snprintf(v[29], string_size, "hv_current_ivt_msg_cmd__30_reset_item_Reset_all_Logdata_Since_Reset");
		snprintf(v[30], string_size, "hv_current_ivt_msg_cmd__30_reset_item_Reset_Reset_EMC");
		snprintf(v[31], string_size, "hv_current_ivt_msg_cmd__30_reset_item_Reset_Reset_Watchdog");
		snprintf(v[32], string_size, "hv_current_ivt_msg_cmd__30_reset_item_Reset_illegal_opcode");
		snprintf(v[33], string_size, "hv_current_ivt_msg_cmd__30_reset_item_Reset_ADC_Clock");
		snprintf(v[34], string_size, "hv_current_ivt_msg_cmd__30_reset_item_Reset_eeprom_rw");
		snprintf(v[35], string_size, "hv_current_ivt_msg_cmd__30_reset_item_Reset_overcurrent_detection");
		snprintf(v[36], string_size, "hv_current_ivt_msg_cmd__30_reset_item_Reset_configuration");
		snprintf(v[37], string_size, "hv_current_ivt_msg_cmd__30_reset_item_Reset_system_init");
		snprintf(v[38], string_size, "hv_current_ivt_msg_cmd__30_reset_item_Reset_system_clock");
		snprintf(v[39], string_size, "hv_current_ivt_msg_cmd__30_reset_item_Reset_power_failure");
		snprintf(v[40], string_size, "hv_current_ivt_msg_cmd__30_reset_item_Reset_undertemp");
		snprintf(v[41], string_size, "hv_current_ivt_msg_cmd__30_reset_item_Reset_overtemp");
		snprintf(v[42], string_size, "hv_current_ivt_msg_cmd__30_reset_item_Reset_CAN_bus_transmit_Data");
		snprintf(v[43], string_size, "hv_current_ivt_msg_cmd__30_reset_item_Reset_CAN_bus_receive_Data");
		snprintf(v[44], string_size, "hv_current_ivt_msg_cmd__30_reset_item_Reset_Parameter_CRC");
		snprintf(v[45], string_size, "hv_current_ivt_msg_cmd__30_reset_item_Reset_Code_CRC");
		snprintf(v[46], string_size, "hv_current_ivt_msg_cmd__30_reset_item_Reset_all_System_errors");
		snprintf(v[47], string_size, "hv_current_ivt_msg_cmd__30_reset_item_Reset_calibration_data_");
		snprintf(v[48], string_size, "hv_current_ivt_msg_cmd__30_reset_item_Reset_ntc_I_OpenCircuit");
		snprintf(v[49], string_size, "hv_current_ivt_msg_cmd__30_reset_item_Reset_ntc_h_OpenCircuit");
		snprintf(v[50], string_size, "hv_current_ivt_msg_cmd__30_reset_item_Reset_voltage_measU3_OpenCircuit");
		snprintf(v[51], string_size, "hv_current_ivt_msg_cmd__30_reset_item_Reset_voltage_measU2_OpenCircuit");
		snprintf(v[52], string_size, "hv_current_ivt_msg_cmd__30_reset_item_Reset_voltage_measU1_OpenCircuit");
		snprintf(v[53], string_size, "hv_current_ivt_msg_cmd__30_reset_item_Reset_current_measI1_OpenCircuit");
		snprintf(v[54], string_size, "hv_current_ivt_msg_cmd__30_reset_item_Reset_thermal_EMF_correction");
		snprintf(v[55], string_size, "hv_current_ivt_msg_cmd__30_reset_item_Reset_error_current_implausible");
		snprintf(v[56], string_size, "hv_current_ivt_msg_cmd__30_reset_item_Reset_error_Vref");
		snprintf(v[57], string_size, "hv_current_ivt_msg_cmd__30_reset_item_Reset_error_Underflow_ADC_ch2");
		snprintf(v[58], string_size, "hv_current_ivt_msg_cmd__30_reset_item_Reset_error_Overflow_ADC_ch2");
		snprintf(v[59], string_size, "hv_current_ivt_msg_cmd__30_reset_item_Reset_error_Underflow_ADC_ch1");
		snprintf(v[60], string_size, "hv_current_ivt_msg_cmd__30_reset_item_Reset_error_Overflow_ADC_ch1");
		snprintf(v[61], string_size, "hv_current_ivt_msg_cmd__30_reset_item_Reset_error_ADC_interrupt");
		snprintf(v[62], string_size, "hv_current_ivt_msg_cmd__30_reset_item_Reset_all_measurement_errors");

		return 0;
	case 32:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "hv_current_ivt_msg_cmd__3a_restart_to_bitrate_250k");
		snprintf(v[1], string_size, "hv_current_ivt_msg_cmd__3a_restart_to_bitrate_500k");
		snprintf(v[2], string_size, "hv_current_ivt_msg_cmd__3a_restart_to_bitrate_1000k");

		return 0;
	case 33:
		if(16 > fields_size) return 1;
		snprintf(v[0], string_size, "hv_current_ivt_msg_cmd__40_get_measerror_item_Get_error_calibration_data");
		snprintf(v[1], string_size, "hv_current_ivt_msg_cmd__40_get_measerror_item_Get_error_ntc_I_OpenCirc");
		snprintf(v[2], string_size, "hv_current_ivt_msg_cmd__40_get_measerror_item_Get_error_ntc_h_OpenCirc");
		snprintf(v[3], string_size, "hv_current_ivt_msg_cmd__40_get_measerror_item_Get_error_volt_meas_U3_OpenCirc");
		snprintf(v[4], string_size, "hv_current_ivt_msg_cmd__40_get_measerror_item_Get_error_volt_meas_U2_OpenCirc");
		snprintf(v[5], string_size, "hv_current_ivt_msg_cmd__40_get_measerror_item_Get_error_volt_meas_U1_OpenCirc");
		snprintf(v[6], string_size, "hv_current_ivt_msg_cmd__40_get_measerror_item_Get_error_cur_meas_I1_OpenCirc");
		snprintf(v[7], string_size, "hv_current_ivt_msg_cmd__40_get_measerror_item_Get_error_thermal_EMF_correction");
		snprintf(v[8], string_size, "hv_current_ivt_msg_cmd__40_get_measerror_item_Get_error_cur_meas_implausible");
		snprintf(v[9], string_size, "hv_current_ivt_msg_cmd__40_get_measerror_item_Get_error_Vref");
		snprintf(v[10], string_size, "hv_current_ivt_msg_cmd__40_get_measerror_item_Get_error_Underflow_ADC_ch_2");
		snprintf(v[11], string_size, "hv_current_ivt_msg_cmd__40_get_measerror_item_Get_error_Overflow_ADC_ch_2");
		snprintf(v[12], string_size, "hv_current_ivt_msg_cmd__40_get_measerror_item_Get_error_Underflow_ADC_ch_1");
		snprintf(v[13], string_size, "hv_current_ivt_msg_cmd__40_get_measerror_item_Get_error_Overflow_ADC_ch_1");
		snprintf(v[14], string_size, "hv_current_ivt_msg_cmd__40_get_measerror_item_Get_error_ADC_interrupt");
		snprintf(v[15], string_size, "hv_current_ivt_msg_cmd__40_get_measerror_item_Get_all_meas_Errors");

		return 0;
	case 34:
		if(17 > fields_size) return 1;
		snprintf(v[0], string_size, "hv_current_ivt_msg_cmd__41_get_systemerror_item_Get_error_reset_EMC");
		snprintf(v[1], string_size, "hv_current_ivt_msg_cmd__41_get_systemerror_item_Get_error_reset_Watchdog");
		snprintf(v[2], string_size, "hv_current_ivt_msg_cmd__41_get_systemerror_item_Get_error_reset_illegal_opcode");
		snprintf(v[3], string_size, "hv_current_ivt_msg_cmd__41_get_systemerror_item_Get_error_ADC_clock");
		snprintf(v[4], string_size, "hv_current_ivt_msg_cmd__41_get_systemerror_item_Get_error_eeprom_rw");
		snprintf(v[5], string_size, "hv_current_ivt_msg_cmd__41_get_systemerror_item_Get_error_overcurrent_detection");
		snprintf(v[6], string_size, "hv_current_ivt_msg_cmd__41_get_systemerror_item_Get_error_configuration");
		snprintf(v[7], string_size, "hv_current_ivt_msg_cmd__41_get_systemerror_item_Get_error_system_init");
		snprintf(v[8], string_size, "hv_current_ivt_msg_cmd__41_get_systemerror_item_Get_error_system_clock");
		snprintf(v[9], string_size, "hv_current_ivt_msg_cmd__41_get_systemerror_item_Get_error_power_failure");
		snprintf(v[10], string_size, "hv_current_ivt_msg_cmd__41_get_systemerror_item_Get_error_undertemp");
		snprintf(v[11], string_size, "hv_current_ivt_msg_cmd__41_get_systemerror_item_Get_error_overtemp");
		snprintf(v[12], string_size, "hv_current_ivt_msg_cmd__41_get_systemerror_item_Get_error_CAN_bus_transmit_Data");
		snprintf(v[13], string_size, "hv_current_ivt_msg_cmd__41_get_systemerror_item_Get_error_CAN__bus_receive_Data");
		snprintf(v[14], string_size, "hv_current_ivt_msg_cmd__41_get_systemerror_item_Get_error_Code_Parameter_CRC");
		snprintf(v[15], string_size, "hv_current_ivt_msg_cmd__41_get_systemerror_item_Get_error_Code_CRC");
		snprintf(v[16], string_size, "hv_current_ivt_msg_cmd__41_get_systemerror_item_Get_all_System_errors");

		return 0;
	case 35:
		if(30 > fields_size) return 1;
		snprintf(v[0], string_size, "hv_current_ivt_msg_cmd__42_get_alllogdata_item_Get_Temperature_minimum");
		snprintf(v[1], string_size, "hv_current_ivt_msg_cmd__42_get_alllogdata_item_Get_Temperature_maximum");
		snprintf(v[2], string_size, "hv_current_ivt_msg_cmd__42_get_alllogdata_item_Get_U3_minimum");
		snprintf(v[3], string_size, "hv_current_ivt_msg_cmd__42_get_alllogdata_item_Get_U3_maxmimum_");
		snprintf(v[4], string_size, "hv_current_ivt_msg_cmd__42_get_alllogdata_item_Get_U2_minimum");
		snprintf(v[5], string_size, "hv_current_ivt_msg_cmd__42_get_alllogdata_item_Get_U2_maximum");
		snprintf(v[6], string_size, "hv_current_ivt_msg_cmd__42_get_alllogdata_item_Get_U1_minimum");
		snprintf(v[7], string_size, "hv_current_ivt_msg_cmd__42_get_alllogdata_item_Get_U1_maxmimum");
		snprintf(v[8], string_size, "hv_current_ivt_msg_cmd__42_get_alllogdata_item_Get_current_minimum");
		snprintf(v[9], string_size, "hv_current_ivt_msg_cmd__42_get_alllogdata_item_Get_current_maximum");
		snprintf(v[10], string_size, "hv_current_ivt_msg_cmd__42_get_alllogdata_item_Get_run_overcur_neg_activated");
		snprintf(v[11], string_size, "hv_current_ivt_msg_cmd__42_get_alllogdata_item_Get_run_overcur_pos_activated");
		snprintf(v[12], string_size, "hv_current_ivt_msg_cmd__42_get_alllogdata_item_Get_run_temp_out_spec_limits");
		snprintf(v[13], string_size, "hv_current_ivt_msg_cmd__42_get_alllogdata_item_Get_run_temp_in_spec_limits");
		snprintf(v[14], string_size, "hv_current_ivt_msg_cmd__42_get_alllogdata_item_Get_run_volt3_out_spec_limits");
		snprintf(v[15], string_size, "hv_current_ivt_msg_cmd__42_get_alllogdata_item_Get_run_volt3_in_spec_limits");
		snprintf(v[16], string_size, "hv_current_ivt_msg_cmd__42_get_alllogdata_item_Get_run_volt2_out_spec_limits");
		snprintf(v[17], string_size, "hv_current_ivt_msg_cmd__42_get_alllogdata_item_Get_run_volt2_in_spec_limits");
		snprintf(v[18], string_size, "hv_current_ivt_msg_cmd__42_get_alllogdata_item_Get_run_volt1_out_spec_limits");
		snprintf(v[19], string_size, "hv_current_ivt_msg_cmd__42_get_alllogdata_item_Get_run_volt1_in_spec_limits");
		snprintf(v[20], string_size, "hv_current_ivt_msg_cmd__42_get_alllogdata_item_Get_run_cur_out_spec_limits");
		snprintf(v[21], string_size, "hv_current_ivt_msg_cmd__42_get_alllogdata_item_Get_Run_cur_in_spec_limits");
		snprintf(v[22], string_size, "hv_current_ivt_msg_cmd__42_get_alllogdata_item_Get_Runtime_overall");
		snprintf(v[23], string_size, "hv_current_ivt_msg_cmd__42_get_alllogdata_item_Get_Energy_counter_discharging");
		snprintf(v[24], string_size, "hv_current_ivt_msg_cmd__42_get_alllogdata_item_Get_Energy_counter_charging");
		snprintf(v[25], string_size, "hv_current_ivt_msg_cmd__42_get_alllogdata_item_Get_Energy_counter_overall");
		snprintf(v[26], string_size, "hv_current_ivt_msg_cmd__42_get_alllogdata_item_Get_Ah_counter_discharging");
		snprintf(v[27], string_size, "hv_current_ivt_msg_cmd__42_get_alllogdata_item_Get_Ah_counter_charging");
		snprintf(v[28], string_size, "hv_current_ivt_msg_cmd__42_get_alllogdata_item_Get_Ah_counter_overall");
		snprintf(v[29], string_size, "hv_current_ivt_msg_cmd__42_get_alllogdata_item_Get_Overall_Logdata");

		return 0;
	case 36:
		if(30 > fields_size) return 1;
		snprintf(v[0], string_size, "hv_current_ivt_msg_cmd__43_get_logdata_item_Get_Temperature_minimum");
		snprintf(v[1], string_size, "hv_current_ivt_msg_cmd__43_get_logdata_item_Get_Temperature_maximum");
		snprintf(v[2], string_size, "hv_current_ivt_msg_cmd__43_get_logdata_item_Get_U3_minimum");
		snprintf(v[3], string_size, "hv_current_ivt_msg_cmd__43_get_logdata_item_Get_U3_maxmimum_");
		snprintf(v[4], string_size, "hv_current_ivt_msg_cmd__43_get_logdata_item_Get_U2_minimum");
		snprintf(v[5], string_size, "hv_current_ivt_msg_cmd__43_get_logdata_item_Get_U2_maximum");
		snprintf(v[6], string_size, "hv_current_ivt_msg_cmd__43_get_logdata_item_Get_U1_minimum");
		snprintf(v[7], string_size, "hv_current_ivt_msg_cmd__43_get_logdata_item_Get_U1_maxmimum");
		snprintf(v[8], string_size, "hv_current_ivt_msg_cmd__43_get_logdata_item_Get_current_minimum");
		snprintf(v[9], string_size, "hv_current_ivt_msg_cmd__43_get_logdata_item_Get_current_maximum");
		snprintf(v[10], string_size, "hv_current_ivt_msg_cmd__43_get_logdata_item_Get_run_overcur_neg_activated");
		snprintf(v[11], string_size, "hv_current_ivt_msg_cmd__43_get_logdata_item_Get_run_overcur_pos_activated");
		snprintf(v[12], string_size, "hv_current_ivt_msg_cmd__43_get_logdata_item_Get_run_temp_out_spec_limits");
		snprintf(v[13], string_size, "hv_current_ivt_msg_cmd__43_get_logdata_item_Get_run_temp_in_spec_limits");
		snprintf(v[14], string_size, "hv_current_ivt_msg_cmd__43_get_logdata_item_Get_run_volt3_out_spec_limits");
		snprintf(v[15], string_size, "hv_current_ivt_msg_cmd__43_get_logdata_item_Get_run_volt3_in_spec_limits");
		snprintf(v[16], string_size, "hv_current_ivt_msg_cmd__43_get_logdata_item_Get_run_volt2_out_spec_limits");
		snprintf(v[17], string_size, "hv_current_ivt_msg_cmd__43_get_logdata_item_Get_run_volt2_in_spec_limits");
		snprintf(v[18], string_size, "hv_current_ivt_msg_cmd__43_get_logdata_item_Get_run_volt1_out_spec_limits");
		snprintf(v[19], string_size, "hv_current_ivt_msg_cmd__43_get_logdata_item_Get_run_volt1_in_spec_limits");
		snprintf(v[20], string_size, "hv_current_ivt_msg_cmd__43_get_logdata_item_Get_run_cur_out_spec_limits");
		snprintf(v[21], string_size, "hv_current_ivt_msg_cmd__43_get_logdata_item_Get_Run_cur_in_spec_limits");
		snprintf(v[22], string_size, "hv_current_ivt_msg_cmd__43_get_logdata_item_Get_Runtime_overall");
		snprintf(v[23], string_size, "hv_current_ivt_msg_cmd__43_get_logdata_item_Get_Energy_counter_discharging");
		snprintf(v[24], string_size, "hv_current_ivt_msg_cmd__43_get_logdata_item_Get_Energy_counter_charging");
		snprintf(v[25], string_size, "hv_current_ivt_msg_cmd__43_get_logdata_item_Get_Energy_counter_overall");
		snprintf(v[26], string_size, "hv_current_ivt_msg_cmd__43_get_logdata_item_Get_Ah_counter_discharging");
		snprintf(v[27], string_size, "hv_current_ivt_msg_cmd__43_get_logdata_item_Get_Ah_counter_charging");
		snprintf(v[28], string_size, "hv_current_ivt_msg_cmd__43_get_logdata_item_Get_Ah_counter_overall");
		snprintf(v[29], string_size, "hv_current_ivt_msg_cmd__43_get_logdata_item_Get_Overall_Logdata");

		return 0;
	case 37:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "hv_current_ivt_msg_cmd__20_conf_triggermode_i_CYCLIC");
		snprintf(v[1], string_size, "hv_current_ivt_msg_cmd__20_conf_triggermode_i_TRIGGERED");
		snprintf(v[2], string_size, "hv_current_ivt_msg_cmd__20_conf_triggermode_i_DISABLED");

		return 0;
	case 38:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "hv_current_ivt_msg_cmd__21_conf_triggermode_u1_CYCLIC");
		snprintf(v[1], string_size, "hv_current_ivt_msg_cmd__21_conf_triggermode_u1_TRIGGERED");
		snprintf(v[2], string_size, "hv_current_ivt_msg_cmd__21_conf_triggermode_u1_DISABLED");

		return 0;
	case 39:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "hv_current_ivt_msg_cmd__22_conf_triggermode_u2_CYCLIC");
		snprintf(v[1], string_size, "hv_current_ivt_msg_cmd__22_conf_triggermode_u2_TRIGGERED");
		snprintf(v[2], string_size, "hv_current_ivt_msg_cmd__22_conf_triggermode_u2_DISABLED");

		return 0;
	case 40:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "hv_current_ivt_msg_cmd__23_conf_triggermode_u3_CYCLIC");
		snprintf(v[1], string_size, "hv_current_ivt_msg_cmd__23_conf_triggermode_u3_TRIGGERED");
		snprintf(v[2], string_size, "hv_current_ivt_msg_cmd__23_conf_triggermode_u3_DISABLED");

		return 0;
	case 41:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "hv_current_ivt_msg_cmd__24_conf_triggermode_t_CYCLIC");
		snprintf(v[1], string_size, "hv_current_ivt_msg_cmd__24_conf_triggermode_t_TRIGGERED");
		snprintf(v[2], string_size, "hv_current_ivt_msg_cmd__24_conf_triggermode_t_DISABLED");

		return 0;
	case 42:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "hv_current_ivt_msg_cmd__25_conf_triggermode_w_CYCLIC");
		snprintf(v[1], string_size, "hv_current_ivt_msg_cmd__25_conf_triggermode_w_TRIGGERED");
		snprintf(v[2], string_size, "hv_current_ivt_msg_cmd__25_conf_triggermode_w_DISABLED");

		return 0;
	case 43:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "hv_current_ivt_msg_cmd__26_conf_triggermode_as_CYCLIC");
		snprintf(v[1], string_size, "hv_current_ivt_msg_cmd__26_conf_triggermode_as_TRIGGERED");
		snprintf(v[2], string_size, "hv_current_ivt_msg_cmd__26_conf_triggermode_as_DISABLED");

		return 0;
	case 44:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "hv_current_ivt_msg_cmd__27_conf_triggermode_wh_CYCLIC");
		snprintf(v[1], string_size, "hv_current_ivt_msg_cmd__27_conf_triggermode_wh_TRIGGERED");
		snprintf(v[2], string_size, "hv_current_ivt_msg_cmd__27_conf_triggermode_wh_DISABLED");

		return 0;
	case 45:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "hv_current_ivt_msg_cmd__34_actual_mode_START");
		snprintf(v[1], string_size, "hv_current_ivt_msg_cmd__34_actual_mode_STOP");

		return 0;
	case 46:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "hv_current_ivt_msg_cmd__34_startup_mode_START");
		snprintf(v[1], string_size, "hv_current_ivt_msg_cmd__34_startup_mode_STOP");

		return 0;

    }
    return 0;
}
int hv_current_serialize_from_id(int id, char *s, uint8_t *data, size_t *size)
{
    switch(id)
    {
	case 1320:
	{
		hv_current_ivt_msg_result_wh_t tmp;
		hv_current_ivt_msg_result_wh_converted_t tmp_converted;
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
		tmp_converted.ivt_id_result_wh = (hv_current_ivt_msg_result_wh_ivt_id_result_wh)r_ivt_id_result_wh;
		tmp_converted.ivt_result_wh_system_error = (uint8_t)r_ivt_result_wh_system_error;
		tmp_converted.ivt_result_wh_measurement_error = (uint8_t)r_ivt_result_wh_measurement_error;
		tmp_converted.ivt_result_wh_channel_error = (uint8_t)r_ivt_result_wh_channel_error;
		tmp_converted.ivt_result_wh_ocs = (uint8_t)r_ivt_result_wh_ocs;
		tmp_converted.ivt_msgcount_result_wh = (uint8_t)r_ivt_msgcount_result_wh;
		tmp_converted.ivt_result_wh = (int32_t)r_ivt_result_wh;

		hv_current_ivt_msg_result_wh_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = HV_CURRENT_IVT_MSG_RESULT_WH_BYTE_SIZE;
		return hv_current_ivt_msg_result_wh_pack(data, &tmp, HV_CURRENT_IVT_MSG_RESULT_WH_BYTE_SIZE);
	}
	case 1319:
	{
		hv_current_ivt_msg_result_as_t tmp;
		hv_current_ivt_msg_result_as_converted_t tmp_converted;
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
		tmp_converted.ivt_id_result_as = (hv_current_ivt_msg_result_as_ivt_id_result_as)r_ivt_id_result_as;
		tmp_converted.ivt_result_as_system_error = (uint8_t)r_ivt_result_as_system_error;
		tmp_converted.ivt_result_as_measurement_error = (uint8_t)r_ivt_result_as_measurement_error;
		tmp_converted.ivt_result_as_channel_error = (uint8_t)r_ivt_result_as_channel_error;
		tmp_converted.ivt_result_as_ocs = (uint8_t)r_ivt_result_as_ocs;
		tmp_converted.ivt_msgcount_result_as = (uint8_t)r_ivt_msgcount_result_as;
		tmp_converted.ivt_result_as = (int32_t)r_ivt_result_as;

		hv_current_ivt_msg_result_as_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = HV_CURRENT_IVT_MSG_RESULT_AS_BYTE_SIZE;
		return hv_current_ivt_msg_result_as_pack(data, &tmp, HV_CURRENT_IVT_MSG_RESULT_AS_BYTE_SIZE);
	}
	case 1318:
	{
		hv_current_ivt_msg_result_w_t tmp;
		hv_current_ivt_msg_result_w_converted_t tmp_converted;
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
		tmp_converted.ivt_id_result_w = (hv_current_ivt_msg_result_w_ivt_id_result_w)r_ivt_id_result_w;
		tmp_converted.ivt_result_w_system_error = (uint8_t)r_ivt_result_w_system_error;
		tmp_converted.ivt_result_w_measurement_error = (uint8_t)r_ivt_result_w_measurement_error;
		tmp_converted.ivt_result_w_channel_error = (uint8_t)r_ivt_result_w_channel_error;
		tmp_converted.ivt_result_w_ocs = (uint8_t)r_ivt_result_w_ocs;
		tmp_converted.ivt_msgcount_result_w = (uint8_t)r_ivt_msgcount_result_w;
		tmp_converted.ivt_result_w = (int32_t)r_ivt_result_w;

		hv_current_ivt_msg_result_w_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = HV_CURRENT_IVT_MSG_RESULT_W_BYTE_SIZE;
		return hv_current_ivt_msg_result_w_pack(data, &tmp, HV_CURRENT_IVT_MSG_RESULT_W_BYTE_SIZE);
	}
	case 1297:
	{
		hv_current_ivt_msg_response_t tmp;
		hv_current_ivt_msg_response_converted_t tmp_converted;
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
		tmp_converted.ivt_id_response = (hv_current_ivt_msg_response_ivt_id_response)r_ivt_id_response;
		tmp_converted._b1_trigger_spare = (uint8_t)r__b1_trigger_spare;
		tmp_converted._ff_wrong_command = (uint8_t)r__ff_wrong_command;
		tmp_converted._bf_restart_alive_cmd_id = (uint16_t)r__bf_restart_alive_cmd_id;
		tmp_converted._80_resp_measerror_item = (hv_current_ivt_msg_response__80_resp_measerror_item)r__80_resp_measerror_item;
		tmp_converted._81_resp_systemerror_item = (hv_current_ivt_msg_response__81_resp_systemerror_item)r__81_resp_systemerror_item;
		tmp_converted._82_resp_alllogdata_item = (hv_current_ivt_msg_response__82_resp_alllogdata_item)r__82_resp_alllogdata_item;
		tmp_converted._83_resp_logdata_item = (hv_current_ivt_msg_response__83_resp_logdata_item)r__83_resp_logdata_item;
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
		tmp_converted._b0_resp_reset_item = (hv_current_ivt_msg_response__b0_resp_reset_item)r__b0_resp_reset_item;
		tmp_converted._b2_resp_store_dummy = (uint8_t)r__b2_resp_store_dummy;
		tmp_converted._b3_resp_oc_test_time = (uint16_t)r__b3_resp_oc_test_time;
		tmp_converted._b5_resp_oc_pos_set_threshold = (int16_t)r__b5_resp_oc_pos_set_threshold;
		tmp_converted._b6_resp_oc_neg_set_threshold = (int16_t)r__b6_resp_oc_neg_set_threshold;
		tmp_converted._b9_resp_device_type = (hv_current_ivt_msg_response__b9_resp_device_type)r__b9_resp_device_type;
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
		tmp_converted._a0_resp_triggermode_i = (hv_current_ivt_msg_response__a0_resp_triggermode_i)r__a0_resp_triggermode_i;
		tmp_converted._a1_resp_triggermode_u1 = (hv_current_ivt_msg_response__a1_resp_triggermode_u1)r__a1_resp_triggermode_u1;
		tmp_converted._a2_resp_triggermode_u2 = (hv_current_ivt_msg_response__a2_resp_triggermode_u2)r__a2_resp_triggermode_u2;
		tmp_converted._a3_resp_triggermode_u3 = (hv_current_ivt_msg_response__a3_resp_triggermode_u3)r__a3_resp_triggermode_u3;
		tmp_converted._a4_resp_triggermode_t = (hv_current_ivt_msg_response__a4_resp_triggermode_t)r__a4_resp_triggermode_t;
		tmp_converted._a5_resp_triggermode_w = (hv_current_ivt_msg_response__a5_resp_triggermode_w)r__a5_resp_triggermode_w;
		tmp_converted._a6_resp_triggermode_as = (hv_current_ivt_msg_response__a6_resp_triggermode_as)r__a6_resp_triggermode_as;
		tmp_converted._a7_resp_triggermode_wh = (hv_current_ivt_msg_response__a7_resp_triggermode_wh)r__a7_resp_triggermode_wh;
		tmp_converted._b4_resp_actual_mode = (hv_current_ivt_msg_response__b4_resp_actual_mode)r__b4_resp_actual_mode;
		tmp_converted._b1_07_trigger_wh = (uint8_t)r__b1_07_trigger_wh;
		tmp_converted._b2_resp_store_device_sn = (uint32_t)r__b2_resp_store_device_sn;
		tmp_converted._ba_resp_sw_ver_minor = (uint8_t)r__ba_resp_sw_ver_minor;
		tmp_converted._b9_resp_device_current = (hv_current_ivt_msg_response__b9_resp_device_current)r__b9_resp_device_current;
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
		tmp_converted._b4_resp_startup_mode = (hv_current_ivt_msg_response__b4_resp_startup_mode)r__b4_resp_startup_mode;
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
		tmp_converted._b9_resp_device_voltage_chan = (hv_current_ivt_msg_response__b9_resp_device_voltage_chan)r__b9_resp_device_voltage_chan;
		tmp_converted._ba_resp_sw_ver_vear = (uint8_t)r__ba_resp_sw_ver_vear;
		tmp_converted._b9_resp_device_toi = (hv_current_ivt_msg_response__b9_resp_device_toi)r__b9_resp_device_toi;
		tmp_converted._ba_resp_sw_ver_month = (int8_t)r__ba_resp_sw_ver_month;
		tmp_converted._b9_resp_device_com = (hv_current_ivt_msg_response__b9_resp_device_com)r__b9_resp_device_com;
		tmp_converted._ba_resp_sw_ver_day = (uint8_t)r__ba_resp_sw_ver_day;
		tmp_converted._b9_resp_device_v_supply = (hv_current_ivt_msg_response__b9_resp_device_v_supply)r__b9_resp_device_v_supply;
		tmp_converted._ba_resp_sw_ver_internal = (uint8_t)r__ba_resp_sw_ver_internal;

		hv_current_ivt_msg_response_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = HV_CURRENT_IVT_MSG_RESPONSE_BYTE_SIZE;
		return hv_current_ivt_msg_response_pack(data, &tmp, HV_CURRENT_IVT_MSG_RESPONSE_BYTE_SIZE);
	}
	case 1317:
	{
		hv_current_ivt_msg_result_t_t tmp;
		hv_current_ivt_msg_result_t_converted_t tmp_converted;
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
		tmp_converted.ivt_id_result_t = (hv_current_ivt_msg_result_t_ivt_id_result_t)r_ivt_id_result_t;
		tmp_converted.ivt_result_t_system_error = (uint8_t)r_ivt_result_t_system_error;
		tmp_converted.ivt_result_t_measurement_error = (uint8_t)r_ivt_result_t_measurement_error;
		tmp_converted.ivt_result_t_channel_error = (uint8_t)r_ivt_result_t_channel_error;
		tmp_converted.ivt_result_t_ocs = (uint8_t)r_ivt_result_t_ocs;
		tmp_converted.ivt_msgcount_result_t = (uint8_t)r_ivt_msgcount_result_t;
		tmp_converted.ivt_result_t = (float)r_ivt_result_t;

		hv_current_ivt_msg_result_t_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = HV_CURRENT_IVT_MSG_RESULT_T_BYTE_SIZE;
		return hv_current_ivt_msg_result_t_pack(data, &tmp, HV_CURRENT_IVT_MSG_RESULT_T_BYTE_SIZE);
	}
	case 1316:
	{
		hv_current_ivt_msg_result_u3_t tmp;
		hv_current_ivt_msg_result_u3_converted_t tmp_converted;
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
		tmp_converted.ivt_id_result_u3 = (hv_current_ivt_msg_result_u3_ivt_id_result_u3)r_ivt_id_result_u3;
		tmp_converted.ivt_result_u3_system_error = (uint8_t)r_ivt_result_u3_system_error;
		tmp_converted.ivt_result_u3_measurement_error = (uint8_t)r_ivt_result_u3_measurement_error;
		tmp_converted.ivt_result_u3_channel_error = (uint8_t)r_ivt_result_u3_channel_error;
		tmp_converted.ivt_result_u3_ocs = (uint8_t)r_ivt_result_u3_ocs;
		tmp_converted.ivt_msgcount_result_u3 = (uint8_t)r_ivt_msgcount_result_u3;
		tmp_converted.ivt_result_u3 = (int32_t)r_ivt_result_u3;

		hv_current_ivt_msg_result_u3_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = HV_CURRENT_IVT_MSG_RESULT_U3_BYTE_SIZE;
		return hv_current_ivt_msg_result_u3_pack(data, &tmp, HV_CURRENT_IVT_MSG_RESULT_U3_BYTE_SIZE);
	}
	case 1315:
	{
		hv_current_ivt_msg_result_u2_t tmp;
		hv_current_ivt_msg_result_u2_converted_t tmp_converted;
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
		tmp_converted.ivt_id_result_u2 = (hv_current_ivt_msg_result_u2_ivt_id_result_u2)r_ivt_id_result_u2;
		tmp_converted.ivt_result_u2_system_error = (uint8_t)r_ivt_result_u2_system_error;
		tmp_converted.ivt_result_u2_measurement_error = (uint8_t)r_ivt_result_u2_measurement_error;
		tmp_converted.ivt_result_u2_channel_error = (uint8_t)r_ivt_result_u2_channel_error;
		tmp_converted.ivt_result_u2_ocs = (uint8_t)r_ivt_result_u2_ocs;
		tmp_converted.ivt_msgcount_result_u2 = (uint8_t)r_ivt_msgcount_result_u2;
		tmp_converted.ivt_result_u2 = (int32_t)r_ivt_result_u2;

		hv_current_ivt_msg_result_u2_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = HV_CURRENT_IVT_MSG_RESULT_U2_BYTE_SIZE;
		return hv_current_ivt_msg_result_u2_pack(data, &tmp, HV_CURRENT_IVT_MSG_RESULT_U2_BYTE_SIZE);
	}
	case 1314:
	{
		hv_current_ivt_msg_result_u1_t tmp;
		hv_current_ivt_msg_result_u1_converted_t tmp_converted;
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
		tmp_converted.ivt_id_result_u1 = (hv_current_ivt_msg_result_u1_ivt_id_result_u1)r_ivt_id_result_u1;
		tmp_converted.ivt_result_u1_system_error = (uint8_t)r_ivt_result_u1_system_error;
		tmp_converted.ivt_result_u1_measurement_error = (uint8_t)r_ivt_result_u1_measurement_error;
		tmp_converted.ivt_result_u1_channel_error = (uint8_t)r_ivt_result_u1_channel_error;
		tmp_converted.ivt_result_u1_ocs = (uint8_t)r_ivt_result_u1_ocs;
		tmp_converted.ivt_msgcount_result_u1 = (uint8_t)r_ivt_msgcount_result_u1;
		tmp_converted.ivt_result_u1 = (int32_t)r_ivt_result_u1;

		hv_current_ivt_msg_result_u1_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = HV_CURRENT_IVT_MSG_RESULT_U1_BYTE_SIZE;
		return hv_current_ivt_msg_result_u1_pack(data, &tmp, HV_CURRENT_IVT_MSG_RESULT_U1_BYTE_SIZE);
	}
	case 1313:
	{
		hv_current_ivt_msg_result_i_t tmp;
		hv_current_ivt_msg_result_i_converted_t tmp_converted;
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
		tmp_converted.ivt_id_result_i = (hv_current_ivt_msg_result_i_ivt_id_result_i)r_ivt_id_result_i;
		tmp_converted.ivt_result_i_system_error = (uint8_t)r_ivt_result_i_system_error;
		tmp_converted.ivt_result_i_measurement_error = (uint8_t)r_ivt_result_i_measurement_error;
		tmp_converted.ivt_result_i_channel_error = (uint8_t)r_ivt_result_i_channel_error;
		tmp_converted.ivt_result_i_ocs = (uint8_t)r_ivt_result_i_ocs;
		tmp_converted.ivt_msgcount_result_i = (uint8_t)r_ivt_msgcount_result_i;
		tmp_converted.ivt_result_i = (int32_t)r_ivt_result_i;

		hv_current_ivt_msg_result_i_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = HV_CURRENT_IVT_MSG_RESULT_I_BYTE_SIZE;
		return hv_current_ivt_msg_result_i_pack(data, &tmp, HV_CURRENT_IVT_MSG_RESULT_I_BYTE_SIZE);
	}
	case 1041:
	{
		hv_current_ivt_msg_cmd_t tmp;
		hv_current_ivt_msg_cmd_converted_t tmp_converted;
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
		tmp_converted.ivt_id_cmd = (hv_current_ivt_msg_cmd_ivt_id_cmd)r_ivt_id_cmd;
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
		tmp_converted._30_reset_item = (hv_current_ivt_msg_cmd__30_reset_item)r__30_reset_item;
		tmp_converted._32_store_dummy = (uint8_t)r__32_store_dummy;
		tmp_converted._33_oc_test_time = (uint16_t)r__33_oc_test_time;
		tmp_converted._35_oc_pos_set_threshold = (int16_t)r__35_oc_pos_set_threshold;
		tmp_converted._36_oc_neg_set_threshold = (int16_t)r__36_oc_neg_set_threshold;
		tmp_converted._3a_restart_to_bitrate = (hv_current_ivt_msg_cmd__3a_restart_to_bitrate)r__3a_restart_to_bitrate;
		tmp_converted._3d_restart_default_dummy = (uint8_t)r__3d_restart_default_dummy;
		tmp_converted._3f_restart_dummy = (uint8_t)r__3f_restart_dummy;
		tmp_converted._40_get_measerror_item = (hv_current_ivt_msg_cmd__40_get_measerror_item)r__40_get_measerror_item;
		tmp_converted._41_get_systemerror_item = (hv_current_ivt_msg_cmd__41_get_systemerror_item)r__41_get_systemerror_item;
		tmp_converted._42_get_alllogdata_item = (hv_current_ivt_msg_cmd__42_get_alllogdata_item)r__42_get_alllogdata_item;
		tmp_converted._43_get_logdata_item = (hv_current_ivt_msg_cmd__43_get_logdata_item)r__43_get_logdata_item;
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
		tmp_converted._20_conf_triggermode_i = (hv_current_ivt_msg_cmd__20_conf_triggermode_i)r__20_conf_triggermode_i;
		tmp_converted._21_conf_triggermode_u1 = (hv_current_ivt_msg_cmd__21_conf_triggermode_u1)r__21_conf_triggermode_u1;
		tmp_converted._22_conf_triggermode_u2 = (hv_current_ivt_msg_cmd__22_conf_triggermode_u2)r__22_conf_triggermode_u2;
		tmp_converted._23_conf_triggermode_u3 = (hv_current_ivt_msg_cmd__23_conf_triggermode_u3)r__23_conf_triggermode_u3;
		tmp_converted._24_conf_triggermode_t = (hv_current_ivt_msg_cmd__24_conf_triggermode_t)r__24_conf_triggermode_t;
		tmp_converted._25_conf_triggermode_w = (hv_current_ivt_msg_cmd__25_conf_triggermode_w)r__25_conf_triggermode_w;
		tmp_converted._26_conf_triggermode_as = (hv_current_ivt_msg_cmd__26_conf_triggermode_as)r__26_conf_triggermode_as;
		tmp_converted._27_conf_triggermode_wh = (hv_current_ivt_msg_cmd__27_conf_triggermode_wh)r__27_conf_triggermode_wh;
		tmp_converted._34_actual_mode = (hv_current_ivt_msg_cmd__34_actual_mode)r__34_actual_mode;
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
		tmp_converted._34_startup_mode = (hv_current_ivt_msg_cmd__34_startup_mode)r__34_startup_mode;
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

		hv_current_ivt_msg_cmd_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = HV_CURRENT_IVT_MSG_CMD_BYTE_SIZE;
		return hv_current_ivt_msg_cmd_pack(data, &tmp, HV_CURRENT_IVT_MSG_CMD_BYTE_SIZE);
	}

    }
    return 0;
}
int hv_current_n_fields_from_id(int id)
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
    }
    return 0;
}
int hv_current_fields_types_from_id(int id, int* fields_types, int fields_types_size)
{
    switch(id)
    {
	case 1320:
		if(fields_types_size < 7) return 0;
		fields_types[0] = e_hv_current_ivt_msg_result_wh_ivt_id_result_wh;
		fields_types[1] = e_hv_current_uint8_t;
		fields_types[2] = e_hv_current_uint8_t;
		fields_types[3] = e_hv_current_uint8_t;
		fields_types[4] = e_hv_current_uint8_t;
		fields_types[5] = e_hv_current_uint8_t;
		fields_types[6] = e_hv_current_int32_t;
		return 7;
	case 1319:
		if(fields_types_size < 7) return 0;
		fields_types[0] = e_hv_current_ivt_msg_result_as_ivt_id_result_as;
		fields_types[1] = e_hv_current_uint8_t;
		fields_types[2] = e_hv_current_uint8_t;
		fields_types[3] = e_hv_current_uint8_t;
		fields_types[4] = e_hv_current_uint8_t;
		fields_types[5] = e_hv_current_uint8_t;
		fields_types[6] = e_hv_current_int32_t;
		return 7;
	case 1318:
		if(fields_types_size < 7) return 0;
		fields_types[0] = e_hv_current_ivt_msg_result_w_ivt_id_result_w;
		fields_types[1] = e_hv_current_uint8_t;
		fields_types[2] = e_hv_current_uint8_t;
		fields_types[3] = e_hv_current_uint8_t;
		fields_types[4] = e_hv_current_uint8_t;
		fields_types[5] = e_hv_current_uint8_t;
		fields_types[6] = e_hv_current_int32_t;
		return 7;
	case 1297:
		if(fields_types_size < 100) return 0;
		fields_types[0] = e_hv_current_ivt_msg_response_ivt_id_response;
		fields_types[1] = e_hv_current_uint8_t;
		fields_types[2] = e_hv_current_uint8_t;
		fields_types[3] = e_hv_current_uint16_t;
		fields_types[4] = e_hv_current_ivt_msg_response__80_resp_measerror_item;
		fields_types[5] = e_hv_current_ivt_msg_response__81_resp_systemerror_item;
		fields_types[6] = e_hv_current_ivt_msg_response__82_resp_alllogdata_item;
		fields_types[7] = e_hv_current_ivt_msg_response__83_resp_logdata_item;
		fields_types[8] = e_hv_current_uint16_t;
		fields_types[9] = e_hv_current_uint16_t;
		fields_types[10] = e_hv_current_uint16_t;
		fields_types[11] = e_hv_current_uint16_t;
		fields_types[12] = e_hv_current_uint16_t;
		fields_types[13] = e_hv_current_uint16_t;
		fields_types[14] = e_hv_current_uint16_t;
		fields_types[15] = e_hv_current_uint16_t;
		fields_types[16] = e_hv_current_uint16_t;
		fields_types[17] = e_hv_current_uint16_t;
		fields_types[18] = e_hv_current_uint8_t;
		fields_types[19] = e_hv_current_uint8_t;
		fields_types[20] = e_hv_current_uint8_t;
		fields_types[21] = e_hv_current_uint8_t;
		fields_types[22] = e_hv_current_uint8_t;
		fields_types[23] = e_hv_current_uint8_t;
		fields_types[24] = e_hv_current_uint8_t;
		fields_types[25] = e_hv_current_uint8_t;
		fields_types[26] = e_hv_current_ivt_msg_response__b0_resp_reset_item;
		fields_types[27] = e_hv_current_uint8_t;
		fields_types[28] = e_hv_current_uint16_t;
		fields_types[29] = e_hv_current_int16_t;
		fields_types[30] = e_hv_current_int16_t;
		fields_types[31] = e_hv_current_ivt_msg_response__b9_resp_device_type;
		fields_types[32] = e_hv_current_uint8_t;
		fields_types[33] = e_hv_current_uint32_t;
		fields_types[34] = e_hv_current_uint64_t;
		fields_types[35] = e_hv_current_uint8_t;
		fields_types[36] = e_hv_current_uint8_t;
		fields_types[37] = e_hv_current_uint8_t;
		fields_types[38] = e_hv_current_uint8_t;
		fields_types[39] = e_hv_current_uint8_t;
		fields_types[40] = e_hv_current_uint8_t;
		fields_types[41] = e_hv_current_uint8_t;
		fields_types[42] = e_hv_current_uint8_t;
		fields_types[43] = e_hv_current_ivt_msg_response__a0_resp_triggermode_i;
		fields_types[44] = e_hv_current_ivt_msg_response__a1_resp_triggermode_u1;
		fields_types[45] = e_hv_current_ivt_msg_response__a2_resp_triggermode_u2;
		fields_types[46] = e_hv_current_ivt_msg_response__a3_resp_triggermode_u3;
		fields_types[47] = e_hv_current_ivt_msg_response__a4_resp_triggermode_t;
		fields_types[48] = e_hv_current_ivt_msg_response__a5_resp_triggermode_w;
		fields_types[49] = e_hv_current_ivt_msg_response__a6_resp_triggermode_as;
		fields_types[50] = e_hv_current_ivt_msg_response__a7_resp_triggermode_wh;
		fields_types[51] = e_hv_current_ivt_msg_response__b4_resp_actual_mode;
		fields_types[52] = e_hv_current_uint8_t;
		fields_types[53] = e_hv_current_uint32_t;
		fields_types[54] = e_hv_current_uint8_t;
		fields_types[55] = e_hv_current_ivt_msg_response__b9_resp_device_current;
		fields_types[56] = e_hv_current_uint16_t;
		fields_types[57] = e_hv_current_uint16_t;
		fields_types[58] = e_hv_current_uint64_t;
		fields_types[59] = e_hv_current_uint64_t;
		fields_types[60] = e_hv_current_uint16_t;
		fields_types[61] = e_hv_current_uint16_t;
		fields_types[62] = e_hv_current_uint16_t;
		fields_types[63] = e_hv_current_uint16_t;
		fields_types[64] = e_hv_current_uint16_t;
		fields_types[65] = e_hv_current_uint16_t;
		fields_types[66] = e_hv_current_uint16_t;
		fields_types[67] = e_hv_current_uint16_t;
		fields_types[68] = e_hv_current_uint8_t;
		fields_types[69] = e_hv_current_uint8_t;
		fields_types[70] = e_hv_current_uint8_t;
		fields_types[71] = e_hv_current_uint8_t;
		fields_types[72] = e_hv_current_uint8_t;
		fields_types[73] = e_hv_current_uint8_t;
		fields_types[74] = e_hv_current_uint8_t;
		fields_types[75] = e_hv_current_ivt_msg_response__b4_resp_startup_mode;
		fields_types[76] = e_hv_current_uint32_t;
		fields_types[77] = e_hv_current_uint8_t;
		fields_types[78] = e_hv_current_uint32_t;
		fields_types[79] = e_hv_current_uint32_t;
		fields_types[80] = e_hv_current_uint32_t;
		fields_types[81] = e_hv_current_uint32_t;
		fields_types[82] = e_hv_current_uint32_t;
		fields_types[83] = e_hv_current_uint32_t;
		fields_types[84] = e_hv_current_uint32_t;
		fields_types[85] = e_hv_current_uint32_t;
		fields_types[86] = e_hv_current_uint32_t;
		fields_types[87] = e_hv_current_uint32_t;
		fields_types[88] = e_hv_current_uint32_t;
		fields_types[89] = e_hv_current_uint16_t;
		fields_types[90] = e_hv_current_int16_t;
		fields_types[91] = e_hv_current_int16_t;
		fields_types[92] = e_hv_current_ivt_msg_response__b9_resp_device_voltage_chan;
		fields_types[93] = e_hv_current_uint8_t;
		fields_types[94] = e_hv_current_ivt_msg_response__b9_resp_device_toi;
		fields_types[95] = e_hv_current_int8_t;
		fields_types[96] = e_hv_current_ivt_msg_response__b9_resp_device_com;
		fields_types[97] = e_hv_current_uint8_t;
		fields_types[98] = e_hv_current_ivt_msg_response__b9_resp_device_v_supply;
		fields_types[99] = e_hv_current_uint8_t;
		return 100;
	case 1317:
		if(fields_types_size < 7) return 0;
		fields_types[0] = e_hv_current_ivt_msg_result_t_ivt_id_result_t;
		fields_types[1] = e_hv_current_uint8_t;
		fields_types[2] = e_hv_current_uint8_t;
		fields_types[3] = e_hv_current_uint8_t;
		fields_types[4] = e_hv_current_uint8_t;
		fields_types[5] = e_hv_current_uint8_t;
		fields_types[6] = e_hv_current_float;
		return 7;
	case 1316:
		if(fields_types_size < 7) return 0;
		fields_types[0] = e_hv_current_ivt_msg_result_u3_ivt_id_result_u3;
		fields_types[1] = e_hv_current_uint8_t;
		fields_types[2] = e_hv_current_uint8_t;
		fields_types[3] = e_hv_current_uint8_t;
		fields_types[4] = e_hv_current_uint8_t;
		fields_types[5] = e_hv_current_uint8_t;
		fields_types[6] = e_hv_current_int32_t;
		return 7;
	case 1315:
		if(fields_types_size < 7) return 0;
		fields_types[0] = e_hv_current_ivt_msg_result_u2_ivt_id_result_u2;
		fields_types[1] = e_hv_current_uint8_t;
		fields_types[2] = e_hv_current_uint8_t;
		fields_types[3] = e_hv_current_uint8_t;
		fields_types[4] = e_hv_current_uint8_t;
		fields_types[5] = e_hv_current_uint8_t;
		fields_types[6] = e_hv_current_int32_t;
		return 7;
	case 1314:
		if(fields_types_size < 7) return 0;
		fields_types[0] = e_hv_current_ivt_msg_result_u1_ivt_id_result_u1;
		fields_types[1] = e_hv_current_uint8_t;
		fields_types[2] = e_hv_current_uint8_t;
		fields_types[3] = e_hv_current_uint8_t;
		fields_types[4] = e_hv_current_uint8_t;
		fields_types[5] = e_hv_current_uint8_t;
		fields_types[6] = e_hv_current_int32_t;
		return 7;
	case 1313:
		if(fields_types_size < 7) return 0;
		fields_types[0] = e_hv_current_ivt_msg_result_i_ivt_id_result_i;
		fields_types[1] = e_hv_current_uint8_t;
		fields_types[2] = e_hv_current_uint8_t;
		fields_types[3] = e_hv_current_uint8_t;
		fields_types[4] = e_hv_current_uint8_t;
		fields_types[5] = e_hv_current_uint8_t;
		fields_types[6] = e_hv_current_int32_t;
		return 7;
	case 1041:
		if(fields_types_size < 106) return 0;
		fields_types[0] = e_hv_current_ivt_msg_cmd_ivt_id_cmd;
		fields_types[1] = e_hv_current_uint8_t;
		fields_types[2] = e_hv_current_uint16_t;
		fields_types[3] = e_hv_current_uint16_t;
		fields_types[4] = e_hv_current_uint16_t;
		fields_types[5] = e_hv_current_uint16_t;
		fields_types[6] = e_hv_current_uint16_t;
		fields_types[7] = e_hv_current_uint16_t;
		fields_types[8] = e_hv_current_uint16_t;
		fields_types[9] = e_hv_current_uint16_t;
		fields_types[10] = e_hv_current_uint16_t;
		fields_types[11] = e_hv_current_uint16_t;
		fields_types[12] = e_hv_current_uint8_t;
		fields_types[13] = e_hv_current_uint8_t;
		fields_types[14] = e_hv_current_uint8_t;
		fields_types[15] = e_hv_current_uint8_t;
		fields_types[16] = e_hv_current_uint8_t;
		fields_types[17] = e_hv_current_uint8_t;
		fields_types[18] = e_hv_current_uint8_t;
		fields_types[19] = e_hv_current_uint8_t;
		fields_types[20] = e_hv_current_ivt_msg_cmd__30_reset_item;
		fields_types[21] = e_hv_current_uint8_t;
		fields_types[22] = e_hv_current_uint16_t;
		fields_types[23] = e_hv_current_int16_t;
		fields_types[24] = e_hv_current_int16_t;
		fields_types[25] = e_hv_current_ivt_msg_cmd__3a_restart_to_bitrate;
		fields_types[26] = e_hv_current_uint8_t;
		fields_types[27] = e_hv_current_uint8_t;
		fields_types[28] = e_hv_current_ivt_msg_cmd__40_get_measerror_item;
		fields_types[29] = e_hv_current_ivt_msg_cmd__41_get_systemerror_item;
		fields_types[30] = e_hv_current_ivt_msg_cmd__42_get_alllogdata_item;
		fields_types[31] = e_hv_current_ivt_msg_cmd__43_get_logdata_item;
		fields_types[32] = e_hv_current_uint8_t;
		fields_types[33] = e_hv_current_uint8_t;
		fields_types[34] = e_hv_current_uint8_t;
		fields_types[35] = e_hv_current_uint8_t;
		fields_types[36] = e_hv_current_uint8_t;
		fields_types[37] = e_hv_current_uint8_t;
		fields_types[38] = e_hv_current_uint8_t;
		fields_types[39] = e_hv_current_uint8_t;
		fields_types[40] = e_hv_current_uint8_t;
		fields_types[41] = e_hv_current_uint8_t;
		fields_types[42] = e_hv_current_uint8_t;
		fields_types[43] = e_hv_current_uint8_t;
		fields_types[44] = e_hv_current_uint8_t;
		fields_types[45] = e_hv_current_uint8_t;
		fields_types[46] = e_hv_current_uint8_t;
		fields_types[47] = e_hv_current_uint8_t;
		fields_types[48] = e_hv_current_uint8_t;
		fields_types[49] = e_hv_current_uint8_t;
		fields_types[50] = e_hv_current_uint8_t;
		fields_types[51] = e_hv_current_uint8_t;
		fields_types[52] = e_hv_current_uint8_t;
		fields_types[53] = e_hv_current_uint8_t;
		fields_types[54] = e_hv_current_uint8_t;
		fields_types[55] = e_hv_current_uint8_t;
		fields_types[56] = e_hv_current_ivt_msg_cmd__20_conf_triggermode_i;
		fields_types[57] = e_hv_current_ivt_msg_cmd__21_conf_triggermode_u1;
		fields_types[58] = e_hv_current_ivt_msg_cmd__22_conf_triggermode_u2;
		fields_types[59] = e_hv_current_ivt_msg_cmd__23_conf_triggermode_u3;
		fields_types[60] = e_hv_current_ivt_msg_cmd__24_conf_triggermode_t;
		fields_types[61] = e_hv_current_ivt_msg_cmd__25_conf_triggermode_w;
		fields_types[62] = e_hv_current_ivt_msg_cmd__26_conf_triggermode_as;
		fields_types[63] = e_hv_current_ivt_msg_cmd__27_conf_triggermode_wh;
		fields_types[64] = e_hv_current_ivt_msg_cmd__34_actual_mode;
		fields_types[65] = e_hv_current_uint8_t;
		fields_types[66] = e_hv_current_uint16_t;
		fields_types[67] = e_hv_current_uint16_t;
		fields_types[68] = e_hv_current_uint16_t;
		fields_types[69] = e_hv_current_uint16_t;
		fields_types[70] = e_hv_current_uint16_t;
		fields_types[71] = e_hv_current_uint16_t;
		fields_types[72] = e_hv_current_uint16_t;
		fields_types[73] = e_hv_current_uint16_t;
		fields_types[74] = e_hv_current_uint8_t;
		fields_types[75] = e_hv_current_uint8_t;
		fields_types[76] = e_hv_current_uint8_t;
		fields_types[77] = e_hv_current_uint8_t;
		fields_types[78] = e_hv_current_uint8_t;
		fields_types[79] = e_hv_current_uint8_t;
		fields_types[80] = e_hv_current_uint8_t;
		fields_types[81] = e_hv_current_ivt_msg_cmd__34_startup_mode;
		fields_types[82] = e_hv_current_uint32_t;
		fields_types[83] = e_hv_current_uint32_t;
		fields_types[84] = e_hv_current_uint32_t;
		fields_types[85] = e_hv_current_uint32_t;
		fields_types[86] = e_hv_current_uint32_t;
		fields_types[87] = e_hv_current_uint32_t;
		fields_types[88] = e_hv_current_uint32_t;
		fields_types[89] = e_hv_current_uint32_t;
		fields_types[90] = e_hv_current_uint32_t;
		fields_types[91] = e_hv_current_uint32_t;
		fields_types[92] = e_hv_current_uint32_t;
		fields_types[93] = e_hv_current_uint16_t;
		fields_types[94] = e_hv_current_int16_t;
		fields_types[95] = e_hv_current_int16_t;
		fields_types[96] = e_hv_current_uint32_t;
		fields_types[97] = e_hv_current_uint32_t;
		fields_types[98] = e_hv_current_uint32_t;
		fields_types[99] = e_hv_current_uint32_t;
		fields_types[100] = e_hv_current_uint32_t;
		fields_types[101] = e_hv_current_uint32_t;
		fields_types[102] = e_hv_current_uint32_t;
		fields_types[103] = e_hv_current_uint32_t;
		fields_types[104] = e_hv_current_uint32_t;
		fields_types[105] = e_hv_current_uint32_t;
		return 106;

    }
    return 0;
}
