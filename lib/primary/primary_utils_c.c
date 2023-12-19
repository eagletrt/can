#include "primary_utils_c.h"


int primary_fields_string_from_id(int id, char **v, size_t fields_size, size_t string_size)
{
	switch(id)
    {
	case 1818:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, primary_nlg5_diag_tx_lad_d_paramrp_string);

		return 0;
	case 1816:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, primary_nlg5_diag_rx_lad_d_paramrq_string);

		return 0;
	case 1556:
		if(37 > fields_size) return 1;
		snprintf(v[0], string_size, primary_nlg5_err_nlg5_e_oov_string);
		snprintf(v[1], string_size, primary_nlg5_err_nlg5_e_mov_ii_string);
		snprintf(v[2], string_size, primary_nlg5_err_nlg5_e_mov_i_string);
		snprintf(v[3], string_size, primary_nlg5_err_nlg5_e_sc_string);
		snprintf(v[4], string_size, primary_nlg5_err_nlg5_e_p_om_string);
		snprintf(v[5], string_size, primary_nlg5_err_nlg5_e_p_mv_string);
		snprintf(v[6], string_size, primary_nlg5_err_nlg5_e_of_string);
		snprintf(v[7], string_size, primary_nlg5_err_nlg5_e_mf_string);
		snprintf(v[8], string_size, primary_nlg5_err_nlg5_e_b_p_string);
		snprintf(v[9], string_size, primary_nlg5_err_nlg5_e_t_c_string);
		snprintf(v[10], string_size, primary_nlg5_err_nlg5_e_t_pow_string);
		snprintf(v[11], string_size, primary_nlg5_err_nlg5_e_t_dio_string);
		snprintf(v[12], string_size, primary_nlg5_err_nlg5_e_t_tr_string);
		snprintf(v[13], string_size, primary_nlg5_err_nlg5_e_t_ext1_string);
		snprintf(v[14], string_size, primary_nlg5_err_nlg5_e_t_ext2_string);
		snprintf(v[15], string_size, primary_nlg5_err_nlg5_e_t_ext3_string);
		snprintf(v[16], string_size, primary_nlg5_err_nlg5_e_f_crc_string);
		snprintf(v[17], string_size, primary_nlg5_err_nlg5_e_nv_crc_string);
		snprintf(v[18], string_size, primary_nlg5_err_nlg5_e_es_crc_string);
		snprintf(v[19], string_size, primary_nlg5_err_nlg5_e_ep_crc_string);
		snprintf(v[20], string_size, primary_nlg5_err_nlg5_e_wdt_string);
		snprintf(v[21], string_size, primary_nlg5_err_nlg5_e_init_string);
		snprintf(v[22], string_size, primary_nlg5_err_nlg5_e_c_to_string);
		snprintf(v[23], string_size, primary_nlg5_err_nlg5_e_c_off_string);
		snprintf(v[24], string_size, primary_nlg5_err_nlg5_e_c_tx_string);
		snprintf(v[25], string_size, primary_nlg5_err_nlg5_e_c_rx_string);
		snprintf(v[26], string_size, primary_nlg5_err_nlg5_e_sdt_bt_string);
		snprintf(v[27], string_size, primary_nlg5_err_nlg5_e_sdt_bv_string);
		snprintf(v[28], string_size, primary_nlg5_err_nlg5_e_sdt_ah_string);
		snprintf(v[29], string_size, primary_nlg5_err_nlg5_e_sdt_ct_string);
		snprintf(v[30], string_size, primary_nlg5_err_nlg5_w_pl_mv_string);
		snprintf(v[31], string_size, primary_nlg5_err_nlg5_w_pl_bv_string);
		snprintf(v[32], string_size, primary_nlg5_err_nlg5_w_pl_it_string);
		snprintf(v[33], string_size, primary_nlg5_err_nlg5_w_c_vor_string);
		snprintf(v[34], string_size, primary_nlg5_err_nlg5_w_cm_na_string);
		snprintf(v[35], string_size, primary_nlg5_err_nlg5_w_od_string);
		snprintf(v[36], string_size, primary_nlg5_err_nlg5_w_sc_m_string);

		return 0;
	case 1555:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, primary_nlg5_temp_nlg5_p_tmp_string);
		snprintf(v[1], string_size, primary_nlg5_temp_nlg5_tmp_ext1_string);
		snprintf(v[2], string_size, primary_nlg5_temp_nlg5_temp_ext2_string);
		snprintf(v[3], string_size, primary_nlg5_temp_nlg5_tmp_ext3_string);

		return 0;
	case 1554:
		if(5 > fields_size) return 1;
		snprintf(v[0], string_size, primary_nlg5_act_ii_nlg5_s_mc_m_cp_string);
		snprintf(v[1], string_size, primary_nlg5_act_ii_nlg5_s_mc_m_pi_string);
		snprintf(v[2], string_size, primary_nlg5_act_ii_nlg5_abv_string);
		snprintf(v[3], string_size, primary_nlg5_act_ii_nlg5_ahc_ext_string);
		snprintf(v[4], string_size, primary_nlg5_act_ii_nlg5_oc_bo_string);

		return 0;
	case 1553:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, primary_nlg5_act_i_nlg5_mc_act_string);
		snprintf(v[1], string_size, primary_nlg5_act_i_nlg5_mv_act_string);
		snprintf(v[2], string_size, primary_nlg5_act_i_nlg5_ov_act_string);
		snprintf(v[3], string_size, primary_nlg5_act_i_nlg5_oc_act_string);

		return 0;
	case 1552:
		if(25 > fields_size) return 1;
		snprintf(v[0], string_size, primary_nlg5_st_nlg5_s_he_string);
		snprintf(v[1], string_size, primary_nlg5_st_nlg5_s_err_string);
		snprintf(v[2], string_size, primary_nlg5_st_nlg5_s_war_string);
		snprintf(v[3], string_size, primary_nlg5_st_nlg5_s_fan_string);
		snprintf(v[4], string_size, primary_nlg5_st_nlg5_s_eum_string);
		snprintf(v[5], string_size, primary_nlg5_st_nlg5_s_um_i_string);
		snprintf(v[6], string_size, primary_nlg5_st_nlg5_s_um_ii_string);
		snprintf(v[7], string_size, primary_nlg5_st_nlg5_s_cp_dt_string);
		snprintf(v[8], string_size, primary_nlg5_st_nlg5_s_bpd_i_string);
		snprintf(v[9], string_size, primary_nlg5_st_nlg5_s_bpd_ii_string);
		snprintf(v[10], string_size, primary_nlg5_st_nlg5_s_l_ov_string);
		snprintf(v[11], string_size, primary_nlg5_st_nlg5_s_l_oc_string);
		snprintf(v[12], string_size, primary_nlg5_st_nlg5_s_l_mc_string);
		snprintf(v[13], string_size, primary_nlg5_st_nlg5_s_l_pi_string);
		snprintf(v[14], string_size, primary_nlg5_st_nlg5_s_l_cp_string);
		snprintf(v[15], string_size, primary_nlg5_st_nlg5_s_l_pmax_string);
		snprintf(v[16], string_size, primary_nlg5_st_nlg5_s_l_mc_max_string);
		snprintf(v[17], string_size, primary_nlg5_st_nlg5_s_l_oc_max_string);
		snprintf(v[18], string_size, primary_nlg5_st_nlg5_s_l_mo_max_string);
		snprintf(v[19], string_size, primary_nlg5_st_nlg5_s_l_t_cprim_string);
		snprintf(v[20], string_size, primary_nlg5_st_nlg5_s_l_t_pow_string);
		snprintf(v[21], string_size, primary_nlg5_st_nlg5_s_l_t_dio_string);
		snprintf(v[22], string_size, primary_nlg5_st_nlg5_s_l_t_tr_string);
		snprintf(v[23], string_size, primary_nlg5_st_nlg5_s_l_t_batt_string);
		snprintf(v[24], string_size, primary_nlg5_st_nlg5_s_aac_string);

		return 0;
	case 1560:
		if(7 > fields_size) return 1;
		snprintf(v[0], string_size, primary_nlg5_ctl_nlg5_c_c_en_string);
		snprintf(v[1], string_size, primary_nlg5_ctl_nlg5_c_c_el_string);
		snprintf(v[2], string_size, primary_nlg5_ctl_nlg5_c_cp_v_string);
		snprintf(v[3], string_size, primary_nlg5_ctl_nlg5_c_mr_string);
		snprintf(v[4], string_size, primary_nlg5_ctl_nlg5_mc_max_string);
		snprintf(v[5], string_size, primary_nlg5_ctl_nlg5_ov_com_string);
		snprintf(v[6], string_size, primary_nlg5_ctl_nlg5_oc_com_string);

		return 0;
	case 3:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, primary_hv_can_forward_can_forward_set_string);

		return 0;
	case 700:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, primary_steer_version_component_build_time_string);
		snprintf(v[1], string_size, primary_steer_version_canlib_build_time_string);

		return 0;
	case 701:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, primary_das_version_component_build_time_string);
		snprintf(v[1], string_size, primary_das_version_canlib_build_time_string);

		return 0;
	case 702:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, primary_mainboard_version_component_build_time_string);
		snprintf(v[1], string_size, primary_mainboard_version_canlib_build_time_string);

		return 0;
	case 703:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, primary_lv_version_component_build_time_string);
		snprintf(v[1], string_size, primary_lv_version_canlib_build_time_string);

		return 0;
	case 704:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, primary_tlm_version_component_build_time_string);
		snprintf(v[1], string_size, primary_tlm_version_canlib_build_time_string);

		return 0;
	case 705:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, primary_cellboard_version_cellboard_id_string);
		snprintf(v[1], string_size, primary_cellboard_version_component_version_string);
		snprintf(v[2], string_size, primary_cellboard_version_canlib_build_time_string);

		return 0;
	case 257:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, primary_ambient_temperature_temp_string);

		return 0;
	case 1072:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, primary_data_logger_placeholder1_string);
		snprintf(v[1], string_size, primary_data_logger_placeholder2_string);

		return 0;
	case 265:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, primary_set_tlm_status_tlm_status_string);

		return 0;
	case 264:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, primary_tlm_status_tlm_status_string);

		return 0;
	case 1801:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, primary_steer_system_status_soc_temp_string);

		return 0;
	case 772:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, primary_hv_voltage_pack_voltage_string);
		snprintf(v[1], string_size, primary_hv_voltage_bus_voltage_string);

		return 0;
	case 804:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, primary_hv_cell_voltage_max_cell_voltage_string);
		snprintf(v[1], string_size, primary_hv_cell_voltage_min_cell_voltage_string);
		snprintf(v[2], string_size, primary_hv_cell_voltage_sum_cell_voltage_string);
		snprintf(v[3], string_size, primary_hv_cell_voltage_avg_cell_voltage_string);

		return 0;
	case 836:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, primary_hv_current_current_string);
		snprintf(v[1], string_size, primary_hv_current_power_string);
		snprintf(v[2], string_size, primary_hv_current_energy_string);
		snprintf(v[3], string_size, primary_hv_current_soc_string);

		return 0;
	case 868:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, primary_hv_temp_average_temp_string);
		snprintf(v[1], string_size, primary_hv_temp_max_temp_string);
		snprintf(v[2], string_size, primary_hv_temp_min_temp_string);

		return 0;
	case 36:
		if(32 > fields_size) return 1;
		snprintf(v[0], string_size, primary_hv_errors_warnings_cell_low_voltage_string);
		snprintf(v[1], string_size, primary_hv_errors_warnings_cell_under_voltage_string);
		snprintf(v[2], string_size, primary_hv_errors_warnings_cell_over_voltage_string);
		snprintf(v[3], string_size, primary_hv_errors_warnings_cell_high_temperature_string);
		snprintf(v[4], string_size, primary_hv_errors_warnings_cell_over_temperature_string);
		snprintf(v[5], string_size, primary_hv_errors_warnings_over_current_string);
		snprintf(v[6], string_size, primary_hv_errors_warnings_can_string);
		snprintf(v[7], string_size, primary_hv_errors_warnings_int_voltage_mismatch_string);
		snprintf(v[8], string_size, primary_hv_errors_warnings_cellboard_comm_string);
		snprintf(v[9], string_size, primary_hv_errors_warnings_cellboard_internal_string);
		snprintf(v[10], string_size, primary_hv_errors_warnings_connector_disconnected_string);
		snprintf(v[11], string_size, primary_hv_errors_warnings_fans_disconnected_string);
		snprintf(v[12], string_size, primary_hv_errors_warnings_feedback_string);
		snprintf(v[13], string_size, primary_hv_errors_warnings_feedback_circuitry_string);
		snprintf(v[14], string_size, primary_hv_errors_warnings_eeprom_comm_string);
		snprintf(v[15], string_size, primary_hv_errors_warnings_eeprom_write_string);
		snprintf(v[16], string_size, primary_hv_errors_errors_cell_low_voltage_string);
		snprintf(v[17], string_size, primary_hv_errors_errors_cell_under_voltage_string);
		snprintf(v[18], string_size, primary_hv_errors_errors_cell_over_voltage_string);
		snprintf(v[19], string_size, primary_hv_errors_errors_cell_high_temperature_string);
		snprintf(v[20], string_size, primary_hv_errors_errors_cell_over_temperature_string);
		snprintf(v[21], string_size, primary_hv_errors_errors_over_current_string);
		snprintf(v[22], string_size, primary_hv_errors_errors_can_string);
		snprintf(v[23], string_size, primary_hv_errors_errors_int_voltage_mismatch_string);
		snprintf(v[24], string_size, primary_hv_errors_errors_cellboard_comm_string);
		snprintf(v[25], string_size, primary_hv_errors_errors_cellboard_internal_string);
		snprintf(v[26], string_size, primary_hv_errors_errors_connector_disconnected_string);
		snprintf(v[27], string_size, primary_hv_errors_errors_fans_disconnected_string);
		snprintf(v[28], string_size, primary_hv_errors_errors_feedback_string);
		snprintf(v[29], string_size, primary_hv_errors_errors_feedback_circuitry_string);
		snprintf(v[30], string_size, primary_hv_errors_errors_eeprom_comm_string);
		snprintf(v[31], string_size, primary_hv_errors_errors_eeprom_write_string);

		return 0;
	case 32:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, primary_hv_fans_override_fans_override_string);
		snprintf(v[1], string_size, primary_hv_fans_override_fans_speed_string);

		return 0;
	case 37:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, primary_hv_can_forward_status_can_forward_status_string);

		return 0;
	case 773:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, primary_hv_fans_override_status_fans_override_string);
		snprintf(v[1], string_size, primary_hv_fans_override_status_fans_speed_string);

		return 0;
	case 771:
		if(20 > fields_size) return 1;
		snprintf(v[0], string_size, primary_hv_feedback_status_feedback_implausibility_detected_string);
		snprintf(v[1], string_size, primary_hv_feedback_status_feedback_imd_cockpit_string);
		snprintf(v[2], string_size, primary_hv_feedback_status_feedback_tsal_green_fault_latched_string);
		snprintf(v[3], string_size, primary_hv_feedback_status_feedback_bms_cockpit_string);
		snprintf(v[4], string_size, primary_hv_feedback_status_feedback_ext_latched_string);
		snprintf(v[5], string_size, primary_hv_feedback_status_feedback_tsal_green_string);
		snprintf(v[6], string_size, primary_hv_feedback_status_feedback_ts_over_60v_status_string);
		snprintf(v[7], string_size, primary_hv_feedback_status_feedback_airn_status_string);
		snprintf(v[8], string_size, primary_hv_feedback_status_feedback_airp_status_string);
		snprintf(v[9], string_size, primary_hv_feedback_status_feedback_airp_gate_string);
		snprintf(v[10], string_size, primary_hv_feedback_status_feedback_airn_gate_string);
		snprintf(v[11], string_size, primary_hv_feedback_status_feedback_precharge_status_string);
		snprintf(v[12], string_size, primary_hv_feedback_status_feedback_tsp_over_60v_status_string);
		snprintf(v[13], string_size, primary_hv_feedback_status_feedback_imd_fault_string);
		snprintf(v[14], string_size, primary_hv_feedback_status_feedback_check_mux_string);
		snprintf(v[15], string_size, primary_hv_feedback_status_feedback_sd_end_string);
		snprintf(v[16], string_size, primary_hv_feedback_status_feedback_sd_out_string);
		snprintf(v[17], string_size, primary_hv_feedback_status_feedback_sd_in_string);
		snprintf(v[18], string_size, primary_hv_feedback_status_feedback_sd_bms_string);
		snprintf(v[19], string_size, primary_hv_feedback_status_feedback_sd_imd_string);

		return 0;
	case 516:
		if(7 > fields_size) return 1;
		snprintf(v[0], string_size, primary_hv_feedback_ts_voltage_feedback_ts_over_60v_status_string);
		snprintf(v[1], string_size, primary_hv_feedback_ts_voltage_feedback_airn_status_string);
		snprintf(v[2], string_size, primary_hv_feedback_ts_voltage_feedback_airp_status_string);
		snprintf(v[3], string_size, primary_hv_feedback_ts_voltage_feedback_airp_gate_string);
		snprintf(v[4], string_size, primary_hv_feedback_ts_voltage_feedback_airn_gate_string);
		snprintf(v[5], string_size, primary_hv_feedback_ts_voltage_feedback_precharge_status_string);
		snprintf(v[6], string_size, primary_hv_feedback_ts_voltage_feedback_tsp_over_60v_status_string);

		return 0;
	case 548:
		if(8 > fields_size) return 1;
		snprintf(v[0], string_size, primary_hv_feedback_misc_voltage_feedback_implausibility_detected_string);
		snprintf(v[1], string_size, primary_hv_feedback_misc_voltage_feedback_imd_cockpit_string);
		snprintf(v[2], string_size, primary_hv_feedback_misc_voltage_feedback_tsal_green_fault_latched_string);
		snprintf(v[3], string_size, primary_hv_feedback_misc_voltage_feedback_bms_cockpit_string);
		snprintf(v[4], string_size, primary_hv_feedback_misc_voltage_feedback_ext_latched_string);
		snprintf(v[5], string_size, primary_hv_feedback_misc_voltage_feedback_tsal_green_string);
		snprintf(v[6], string_size, primary_hv_feedback_misc_voltage_imd_fault_string);
		snprintf(v[7], string_size, primary_hv_feedback_misc_voltage_feedback_check_mux_string);

		return 0;
	case 580:
		if(5 > fields_size) return 1;
		snprintf(v[0], string_size, primary_hv_feedback_sd_voltage_feedback_sd_end_string);
		snprintf(v[1], string_size, primary_hv_feedback_sd_voltage_feedback_sd_out_string);
		snprintf(v[2], string_size, primary_hv_feedback_sd_voltage_feedback_sd_in_string);
		snprintf(v[3], string_size, primary_hv_feedback_sd_voltage_feedback_sd_bms_string);
		snprintf(v[4], string_size, primary_hv_feedback_sd_voltage_feedback_sd_imd_string);

		return 0;
	case 803:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, primary_hv_imd_status_imd_fault_string);
		snprintf(v[1], string_size, primary_hv_imd_status_imd_status_string);
		snprintf(v[2], string_size, primary_hv_imd_status_imd_details_string);
		snprintf(v[3], string_size, primary_hv_imd_status_imd_duty_cycle_string);
		snprintf(v[4], string_size, primary_hv_imd_status_imd_freq_string);
		snprintf(v[5], string_size, primary_hv_imd_status_imd_period_string);

		return 0;
	case 84:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, primary_ts_status_ts_status_string);

		return 0;
	case 82:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, primary_set_ts_status_das_ts_status_set_string);

		return 0;
	case 83:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, primary_set_ts_status_handcart_ts_status_set_string);

		return 0;
	case 258:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, primary_steer_status_map_pw_string);
		snprintf(v[1], string_size, primary_steer_status_map_sc_string);
		snprintf(v[2], string_size, primary_steer_status_map_tv_string);

		return 0;
	case 80:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, primary_set_car_status_car_status_set_string);

		return 0;
	case 1026:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, primary_set_pedal_calibration_pedal_string);
		snprintf(v[1], string_size, primary_set_pedal_calibration_bound_string);

		return 0;
	case 1032:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, primary_pedal_calibration_ack_pedal_string);
		snprintf(v[1], string_size, primary_pedal_calibration_ack_bound_string);

		return 0;
	case 81:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, primary_car_status_inverter_l_string);
		snprintf(v[1], string_size, primary_car_status_inverter_r_string);
		snprintf(v[2], string_size, primary_car_status_car_status_string);

		return 0;
	case 40:
		if(9 > fields_size) return 1;
		snprintf(v[0], string_size, primary_das_errors_das_error_pedal_adc_string);
		snprintf(v[1], string_size, primary_das_errors_das_error_pedal_implausibility_string);
		snprintf(v[2], string_size, primary_das_errors_das_error_imu_tout_string);
		snprintf(v[3], string_size, primary_das_errors_das_error_irts_tout_string);
		snprintf(v[4], string_size, primary_das_errors_das_error_ts_tout_string);
		snprintf(v[5], string_size, primary_das_errors_das_error_invl_tout_string);
		snprintf(v[6], string_size, primary_das_errors_das_error_invr_tout_string);
		snprintf(v[7], string_size, primary_das_errors_das_error_steer_tout_string);
		snprintf(v[8], string_size, primary_das_errors_das_error_fsm_string);

		return 0;
	case 777:
		if(8 > fields_size) return 1;
		snprintf(v[0], string_size, primary_ecu_feedbacks_ecu_feedbacks_sd_cock_fb_string);
		snprintf(v[1], string_size, primary_ecu_feedbacks_ecu_feedbacks_sd_fb1_string);
		snprintf(v[2], string_size, primary_ecu_feedbacks_ecu_feedbacks_sd_bots_fb_string);
		snprintf(v[3], string_size, primary_ecu_feedbacks_ecu_feedbacks_sd_interial_fb_string);
		snprintf(v[4], string_size, primary_ecu_feedbacks_ecu_feedbacks_sd_fb4_string);
		snprintf(v[5], string_size, primary_ecu_feedbacks_ecu_feedbacks_sd_in_string);
		snprintf(v[6], string_size, primary_ecu_feedbacks_ecu_feedbacks_sd_out_string);
		snprintf(v[7], string_size, primary_ecu_feedbacks_ecu_feedbacks_sd_ctrl_pin_string);

		return 0;
	case 809:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, primary_lv_status_status_string);

		return 0;
	case 835:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, primary_lv_currents_current_as_battery_string);
		snprintf(v[1], string_size, primary_lv_currents_current_lv_battery_string);
		snprintf(v[2], string_size, primary_lv_currents_current_charger_string);

		return 0;
	case 867:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, primary_lv_cells_voltage_start_index_string);
		snprintf(v[1], string_size, primary_lv_cells_voltage_voltage_0_string);
		snprintf(v[2], string_size, primary_lv_cells_voltage_voltage_1_string);
		snprintf(v[3], string_size, primary_lv_cells_voltage_voltage_2_string);

		return 0;
	case 899:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, primary_lv_total_voltage_total_voltage_string);

		return 0;
	case 931:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, primary_lv_cells_temp_start_index_string);
		snprintf(v[1], string_size, primary_lv_cells_temp_temp_0_string);
		snprintf(v[2], string_size, primary_lv_cells_temp_temp_1_string);
		snprintf(v[3], string_size, primary_lv_cells_temp_temp_2_string);

		return 0;
	case 963:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, primary_cooling_status_radiators_speed_string);
		snprintf(v[1], string_size, primary_cooling_status_pumps_speed_string);

		return 0;
	case 775:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, primary_set_radiator_speed_radiators_speed_string);

		return 0;
	case 807:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, primary_set_pumps_speed_pumps_speed_string);

		return 0;
	case 263:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, primary_set_inverter_connection_status_status_string);

		return 0;
	case 259:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, primary_inverter_connection_status_status_string);

		return 0;
	case 515:
		if(34 > fields_size) return 1;
		snprintf(v[0], string_size, primary_lv_errors_warnings_cell_undervoltage_string);
		snprintf(v[1], string_size, primary_lv_errors_warnings_cell_overvoltage_string);
		snprintf(v[2], string_size, primary_lv_errors_warnings_battery_open_wire_string);
		snprintf(v[3], string_size, primary_lv_errors_warnings_can_string);
		snprintf(v[4], string_size, primary_lv_errors_warnings_spi_string);
		snprintf(v[5], string_size, primary_lv_errors_warnings_over_current_string);
		snprintf(v[6], string_size, primary_lv_errors_warnings_cell_under_temperature_string);
		snprintf(v[7], string_size, primary_lv_errors_warnings_cell_over_temperature_string);
		snprintf(v[8], string_size, primary_lv_errors_warnings_relay_string);
		snprintf(v[9], string_size, primary_lv_errors_warnings_bms_monitor_string);
		snprintf(v[10], string_size, primary_lv_errors_warnings_voltages_not_ready_string);
		snprintf(v[11], string_size, primary_lv_errors_warnings_mcp23017_string);
		snprintf(v[12], string_size, primary_lv_errors_warnings_radiator_string);
		snprintf(v[13], string_size, primary_lv_errors_warnings_fan_string);
		snprintf(v[14], string_size, primary_lv_errors_warnings_pump_string);
		snprintf(v[15], string_size, primary_lv_errors_warnings_adc_init_string);
		snprintf(v[16], string_size, primary_lv_errors_warnings_mux_string);
		snprintf(v[17], string_size, primary_lv_errors_errors_cell_undervoltage_string);
		snprintf(v[18], string_size, primary_lv_errors_errors_cell_overvoltage_string);
		snprintf(v[19], string_size, primary_lv_errors_errors_battery_open_wire_string);
		snprintf(v[20], string_size, primary_lv_errors_errors_can_string);
		snprintf(v[21], string_size, primary_lv_errors_errors_spi_string);
		snprintf(v[22], string_size, primary_lv_errors_errors_over_current_string);
		snprintf(v[23], string_size, primary_lv_errors_errors_cell_under_temperature_string);
		snprintf(v[24], string_size, primary_lv_errors_errors_cell_over_temperature_string);
		snprintf(v[25], string_size, primary_lv_errors_errors_relay_string);
		snprintf(v[26], string_size, primary_lv_errors_errors_bms_monitor_string);
		snprintf(v[27], string_size, primary_lv_errors_errors_voltages_not_ready_string);
		snprintf(v[28], string_size, primary_lv_errors_errors_mcp23017_string);
		snprintf(v[29], string_size, primary_lv_errors_errors_radiator_string);
		snprintf(v[30], string_size, primary_lv_errors_errors_fan_string);
		snprintf(v[31], string_size, primary_lv_errors_errors_pump_string);
		snprintf(v[32], string_size, primary_lv_errors_errors_adc_init_string);
		snprintf(v[33], string_size, primary_lv_errors_errors_mux_string);

		return 0;
	case 291:
		if(7 > fields_size) return 1;
		snprintf(v[0], string_size, primary_lv_health_signals_health_signals_lvms_out_string);
		snprintf(v[1], string_size, primary_lv_health_signals_health_signals_relay_out_string);
		snprintf(v[2], string_size, primary_lv_health_signals_health_signals_battery_voltage_out_string);
		snprintf(v[3], string_size, primary_lv_health_signals_health_signals_charger_current_string);
		snprintf(v[4], string_size, primary_lv_health_signals_health_signals_battery_current_string);
		snprintf(v[5], string_size, primary_lv_health_signals_health_signals_sign_battery_current_string);
		snprintf(v[6], string_size, primary_lv_health_signals_health_code_string);

		return 0;
	case 323:
		if(21 > fields_size) return 1;
		snprintf(v[0], string_size, primary_lv_feedbacks_feedbacks_bspd_fb_string);
		snprintf(v[1], string_size, primary_lv_feedbacks_feedbacks_hvd_fb_string);
		snprintf(v[2], string_size, primary_lv_feedbacks_feedbacks_lvms_fb_string);
		snprintf(v[3], string_size, primary_lv_feedbacks_feedbacks_res_fb_string);
		snprintf(v[4], string_size, primary_lv_feedbacks_feedbacks_lv_encl_string);
		snprintf(v[5], string_size, primary_lv_feedbacks_feedbacks_invc_lid_fb_string);
		snprintf(v[6], string_size, primary_lv_feedbacks_feedbacks_hv_encl_2_fb_string);
		snprintf(v[7], string_size, primary_lv_feedbacks_feedbacks_back_plate_fb_string);
		snprintf(v[8], string_size, primary_lv_feedbacks_feedbacks_invc_interlock_fb_string);
		snprintf(v[9], string_size, primary_lv_feedbacks_feedbacks_ams_fb_string);
		snprintf(v[10], string_size, primary_lv_feedbacks_feedbacks_asms_fb_string);
		snprintf(v[11], string_size, primary_lv_feedbacks_feedbacks_interlock_fb_string);
		snprintf(v[12], string_size, primary_lv_feedbacks_feedbacks_inverters_fb_string);
		snprintf(v[13], string_size, primary_lv_feedbacks_feedbacks_pcbs_fb_string);
		snprintf(v[14], string_size, primary_lv_feedbacks_feedbacks_pumps_fb_string);
		snprintf(v[15], string_size, primary_lv_feedbacks_feedbacks_shutdown_fb_string);
		snprintf(v[16], string_size, primary_lv_feedbacks_feedbacks_radiators_fb_string);
		snprintf(v[17], string_size, primary_lv_feedbacks_feedbacks_fan_fb_string);
		snprintf(v[18], string_size, primary_lv_feedbacks_feedbacks_as_actuation_fb_string);
		snprintf(v[19], string_size, primary_lv_feedbacks_sd_start_string);
		snprintf(v[20], string_size, primary_lv_feedbacks_sd_end_string);

		return 0;
	case 355:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, primary_shutdown_status_input_string);
		snprintf(v[1], string_size, primary_shutdown_status_output_string);

		return 0;
	case 1865:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, primary_lv_can_flash_ack_response_string);

		return 0;
	case 517:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, primary_hv_cells_voltage_start_index_string);
		snprintf(v[1], string_size, primary_hv_cells_voltage_voltage_0_string);
		snprintf(v[2], string_size, primary_hv_cells_voltage_voltage_1_string);
		snprintf(v[3], string_size, primary_hv_cells_voltage_voltage_2_string);

		return 0;
	case 549:
		if(5 > fields_size) return 1;
		snprintf(v[0], string_size, primary_hv_cells_temp_start_index_string);
		snprintf(v[1], string_size, primary_hv_cells_temp_temp_0_string);
		snprintf(v[2], string_size, primary_hv_cells_temp_temp_1_string);
		snprintf(v[3], string_size, primary_hv_cells_temp_temp_2_string);
		snprintf(v[4], string_size, primary_hv_cells_temp_temp_3_string);

		return 0;
	case 581:
		if(29 > fields_size) return 1;
		snprintf(v[0], string_size, primary_hv_cell_balancing_status_cellboard_id_string);
		snprintf(v[1], string_size, primary_hv_cell_balancing_status_balancing_status_string);
		snprintf(v[2], string_size, primary_hv_cell_balancing_status_errors_can_comm_string);
		snprintf(v[3], string_size, primary_hv_cell_balancing_status_errors_ltc_comm_string);
		snprintf(v[4], string_size, primary_hv_cell_balancing_status_errors_temp_comm_0_string);
		snprintf(v[5], string_size, primary_hv_cell_balancing_status_errors_temp_comm_1_string);
		snprintf(v[6], string_size, primary_hv_cell_balancing_status_errors_temp_comm_2_string);
		snprintf(v[7], string_size, primary_hv_cell_balancing_status_errors_temp_comm_3_string);
		snprintf(v[8], string_size, primary_hv_cell_balancing_status_errors_temp_comm_4_string);
		snprintf(v[9], string_size, primary_hv_cell_balancing_status_errors_temp_comm_5_string);
		snprintf(v[10], string_size, primary_hv_cell_balancing_status_errors_open_wire_string);
		snprintf(v[11], string_size, primary_hv_cell_balancing_status_balancing_cells_cell0_string);
		snprintf(v[12], string_size, primary_hv_cell_balancing_status_balancing_cells_cell1_string);
		snprintf(v[13], string_size, primary_hv_cell_balancing_status_balancing_cells_cell2_string);
		snprintf(v[14], string_size, primary_hv_cell_balancing_status_balancing_cells_cell3_string);
		snprintf(v[15], string_size, primary_hv_cell_balancing_status_balancing_cells_cell4_string);
		snprintf(v[16], string_size, primary_hv_cell_balancing_status_balancing_cells_cell5_string);
		snprintf(v[17], string_size, primary_hv_cell_balancing_status_balancing_cells_cell6_string);
		snprintf(v[18], string_size, primary_hv_cell_balancing_status_balancing_cells_cell7_string);
		snprintf(v[19], string_size, primary_hv_cell_balancing_status_balancing_cells_cell8_string);
		snprintf(v[20], string_size, primary_hv_cell_balancing_status_balancing_cells_cell9_string);
		snprintf(v[21], string_size, primary_hv_cell_balancing_status_balancing_cells_cell10_string);
		snprintf(v[22], string_size, primary_hv_cell_balancing_status_balancing_cells_cell11_string);
		snprintf(v[23], string_size, primary_hv_cell_balancing_status_balancing_cells_cell12_string);
		snprintf(v[24], string_size, primary_hv_cell_balancing_status_balancing_cells_cell13_string);
		snprintf(v[25], string_size, primary_hv_cell_balancing_status_balancing_cells_cell14_string);
		snprintf(v[26], string_size, primary_hv_cell_balancing_status_balancing_cells_cell15_string);
		snprintf(v[27], string_size, primary_hv_cell_balancing_status_balancing_cells_cell16_string);
		snprintf(v[28], string_size, primary_hv_cell_balancing_status_balancing_cells_cell17_string);

		return 0;
	case 512:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, primary_set_cell_balancing_status_set_balancing_status_string);
		snprintf(v[1], string_size, primary_set_cell_balancing_status_balancing_threshold_string);

		return 0;
	case 520:
		if(4 > fields_size) return 1;
		snprintf(v[0], string_size, primary_speed_encoder_r_string);
		snprintf(v[1], string_size, primary_speed_encoder_l_string);
		snprintf(v[2], string_size, primary_speed_inverter_r_string);
		snprintf(v[3], string_size, primary_speed_inverter_l_string);

		return 0;
	case 513:
		if(8 > fields_size) return 1;
		snprintf(v[0], string_size, primary_inv_l_request_data_0_string);
		snprintf(v[1], string_size, primary_inv_l_request_data_1_string);
		snprintf(v[2], string_size, primary_inv_l_request_data_2_string);
		snprintf(v[3], string_size, primary_inv_l_request_data_3_string);
		snprintf(v[4], string_size, primary_inv_l_request_data_4_string);
		snprintf(v[5], string_size, primary_inv_l_request_data_5_string);
		snprintf(v[6], string_size, primary_inv_l_request_data_6_string);
		snprintf(v[7], string_size, primary_inv_l_request_data_7_string);

		return 0;
	case 514:
		if(8 > fields_size) return 1;
		snprintf(v[0], string_size, primary_inv_r_request_data_0_string);
		snprintf(v[1], string_size, primary_inv_r_request_data_1_string);
		snprintf(v[2], string_size, primary_inv_r_request_data_2_string);
		snprintf(v[3], string_size, primary_inv_r_request_data_3_string);
		snprintf(v[4], string_size, primary_inv_r_request_data_4_string);
		snprintf(v[5], string_size, primary_inv_r_request_data_5_string);
		snprintf(v[6], string_size, primary_inv_r_request_data_6_string);
		snprintf(v[7], string_size, primary_inv_r_request_data_7_string);

		return 0;
	case 385:
		if(8 > fields_size) return 1;
		snprintf(v[0], string_size, primary_inv_l_response_reg_id_string);
		snprintf(v[1], string_size, primary_inv_l_response_data_0_string);
		snprintf(v[2], string_size, primary_inv_l_response_data_1_string);
		snprintf(v[3], string_size, primary_inv_l_response_data_2_string);
		snprintf(v[4], string_size, primary_inv_l_response_data_3_string);
		snprintf(v[5], string_size, primary_inv_l_response_data_4_string);
		snprintf(v[6], string_size, primary_inv_l_response_data_5_string);
		snprintf(v[7], string_size, primary_inv_l_response_data_6_string);

		return 0;
	case 386:
		if(8 > fields_size) return 1;
		snprintf(v[0], string_size, primary_inv_r_response_reg_id_string);
		snprintf(v[1], string_size, primary_inv_r_response_data_0_string);
		snprintf(v[2], string_size, primary_inv_r_response_data_1_string);
		snprintf(v[3], string_size, primary_inv_r_response_data_2_string);
		snprintf(v[4], string_size, primary_inv_r_response_data_3_string);
		snprintf(v[5], string_size, primary_inv_r_response_data_4_string);
		snprintf(v[6], string_size, primary_inv_r_response_data_5_string);
		snprintf(v[7], string_size, primary_inv_r_response_data_6_string);

		return 0;
	case 296:
		if(5 > fields_size) return 1;
		snprintf(v[0], string_size, primary_control_output_estimated_velocity_string);
		snprintf(v[1], string_size, primary_control_output_tmax_r_string);
		snprintf(v[2], string_size, primary_control_output_tmax_l_string);
		snprintf(v[3], string_size, primary_control_output_torque_l_string);
		snprintf(v[4], string_size, primary_control_output_torque_r_string);

		return 0;
	case 768:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, primary_handcart_status_connected_string);

		return 0;
	case 800:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, primary_handcart_settings_target_voltage_string);
		snprintf(v[1], string_size, primary_handcart_settings_fans_override_string);
		snprintf(v[2], string_size, primary_handcart_settings_fans_speed_string);
		snprintf(v[3], string_size, primary_handcart_settings_acc_charge_current_string);
		snprintf(v[4], string_size, primary_handcart_settings_grid_max_current_string);
		snprintf(v[5], string_size, primary_handcart_settings_status_string);

		return 0;
	case 832:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, primary_handcart_settings_set_target_voltage_string);
		snprintf(v[1], string_size, primary_handcart_settings_set_fans_override_string);
		snprintf(v[2], string_size, primary_handcart_settings_set_fans_speed_string);
		snprintf(v[3], string_size, primary_handcart_settings_set_acc_charge_current_string);
		snprintf(v[4], string_size, primary_handcart_settings_set_grid_max_current_string);
		snprintf(v[5], string_size, primary_handcart_settings_set_status_string);

		return 0;
	case 547:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, primary_set_ptt_status_status_string);

		return 0;
	case 579:
		if(1 > fields_size) return 1;
		snprintf(v[0], string_size, primary_ptt_status_status_string);

		return 0;
	case 1027:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, primary_regen_manual_command_status_string);
		snprintf(v[1], string_size, primary_regen_manual_command_target_string);

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
		snprintf(v[0], string_size, "primary_hv_can_forward_can_forward_set_OFF");
		snprintf(v[1], string_size, "primary_hv_can_forward_can_forward_set_ON");

		return 0;
	case 1:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_cellboard_version_cellboard_id_CELLBOARD_0");
		snprintf(v[1], string_size, "primary_cellboard_version_cellboard_id_CELLBOARD_1");
		snprintf(v[2], string_size, "primary_cellboard_version_cellboard_id_CELLBOARD_2");
		snprintf(v[3], string_size, "primary_cellboard_version_cellboard_id_CELLBOARD_3");
		snprintf(v[4], string_size, "primary_cellboard_version_cellboard_id_CELLBOARD_4");
		snprintf(v[5], string_size, "primary_cellboard_version_cellboard_id_CELLBOARD_5");

		return 0;
	case 2:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_set_tlm_status_tlm_status_OFF");
		snprintf(v[1], string_size, "primary_set_tlm_status_tlm_status_ON");

		return 0;
	case 3:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_tlm_status_tlm_status_OFF");
		snprintf(v[1], string_size, "primary_tlm_status_tlm_status_ON");

		return 0;
	case 4:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_fans_override_fans_override_OFF");
		snprintf(v[1], string_size, "primary_hv_fans_override_fans_override_ON");

		return 0;
	case 5:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_can_forward_status_can_forward_status_OFF");
		snprintf(v[1], string_size, "primary_hv_can_forward_status_can_forward_status_ON");

		return 0;
	case 6:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_fans_override_status_fans_override_OFF");
		snprintf(v[1], string_size, "primary_hv_fans_override_status_fans_override_ON");

		return 0;
	case 7:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_feedback_implausibility_detected_FEEDBACK_STATE_LOW");
		snprintf(v[1], string_size, "primary_hv_feedback_status_feedback_implausibility_detected_FEEDBACK_STATE_ERROR");
		snprintf(v[2], string_size, "primary_hv_feedback_status_feedback_implausibility_detected_FEEDBACK_STATE_HIGH");

		return 0;
	case 8:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_feedback_imd_cockpit_FEEDBACK_STATE_LOW");
		snprintf(v[1], string_size, "primary_hv_feedback_status_feedback_imd_cockpit_FEEDBACK_STATE_ERROR");
		snprintf(v[2], string_size, "primary_hv_feedback_status_feedback_imd_cockpit_FEEDBACK_STATE_HIGH");

		return 0;
	case 9:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_feedback_tsal_green_fault_latched_FEEDBACK_STATE_LOW");
		snprintf(v[1], string_size, "primary_hv_feedback_status_feedback_tsal_green_fault_latched_FEEDBACK_STATE_ERROR");
		snprintf(v[2], string_size, "primary_hv_feedback_status_feedback_tsal_green_fault_latched_FEEDBACK_STATE_HIGH");

		return 0;
	case 10:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_feedback_bms_cockpit_FEEDBACK_STATE_LOW");
		snprintf(v[1], string_size, "primary_hv_feedback_status_feedback_bms_cockpit_FEEDBACK_STATE_ERROR");
		snprintf(v[2], string_size, "primary_hv_feedback_status_feedback_bms_cockpit_FEEDBACK_STATE_HIGH");

		return 0;
	case 11:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_feedback_ext_latched_FEEDBACK_STATE_LOW");
		snprintf(v[1], string_size, "primary_hv_feedback_status_feedback_ext_latched_FEEDBACK_STATE_ERROR");
		snprintf(v[2], string_size, "primary_hv_feedback_status_feedback_ext_latched_FEEDBACK_STATE_HIGH");

		return 0;
	case 12:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_feedback_tsal_green_FEEDBACK_STATE_LOW");
		snprintf(v[1], string_size, "primary_hv_feedback_status_feedback_tsal_green_FEEDBACK_STATE_ERROR");
		snprintf(v[2], string_size, "primary_hv_feedback_status_feedback_tsal_green_FEEDBACK_STATE_HIGH");

		return 0;
	case 13:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_feedback_ts_over_60v_status_FEEDBACK_STATE_LOW");
		snprintf(v[1], string_size, "primary_hv_feedback_status_feedback_ts_over_60v_status_FEEDBACK_STATE_ERROR");
		snprintf(v[2], string_size, "primary_hv_feedback_status_feedback_ts_over_60v_status_FEEDBACK_STATE_HIGH");

		return 0;
	case 14:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_feedback_airn_status_FEEDBACK_STATE_LOW");
		snprintf(v[1], string_size, "primary_hv_feedback_status_feedback_airn_status_FEEDBACK_STATE_ERROR");
		snprintf(v[2], string_size, "primary_hv_feedback_status_feedback_airn_status_FEEDBACK_STATE_HIGH");

		return 0;
	case 15:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_feedback_airp_status_FEEDBACK_STATE_LOW");
		snprintf(v[1], string_size, "primary_hv_feedback_status_feedback_airp_status_FEEDBACK_STATE_ERROR");
		snprintf(v[2], string_size, "primary_hv_feedback_status_feedback_airp_status_FEEDBACK_STATE_HIGH");

		return 0;
	case 16:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_feedback_airp_gate_FEEDBACK_STATE_LOW");
		snprintf(v[1], string_size, "primary_hv_feedback_status_feedback_airp_gate_FEEDBACK_STATE_ERROR");
		snprintf(v[2], string_size, "primary_hv_feedback_status_feedback_airp_gate_FEEDBACK_STATE_HIGH");

		return 0;
	case 17:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_feedback_airn_gate_FEEDBACK_STATE_LOW");
		snprintf(v[1], string_size, "primary_hv_feedback_status_feedback_airn_gate_FEEDBACK_STATE_ERROR");
		snprintf(v[2], string_size, "primary_hv_feedback_status_feedback_airn_gate_FEEDBACK_STATE_HIGH");

		return 0;
	case 18:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_feedback_precharge_status_FEEDBACK_STATE_LOW");
		snprintf(v[1], string_size, "primary_hv_feedback_status_feedback_precharge_status_FEEDBACK_STATE_ERROR");
		snprintf(v[2], string_size, "primary_hv_feedback_status_feedback_precharge_status_FEEDBACK_STATE_HIGH");

		return 0;
	case 19:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_feedback_tsp_over_60v_status_FEEDBACK_STATE_LOW");
		snprintf(v[1], string_size, "primary_hv_feedback_status_feedback_tsp_over_60v_status_FEEDBACK_STATE_ERROR");
		snprintf(v[2], string_size, "primary_hv_feedback_status_feedback_tsp_over_60v_status_FEEDBACK_STATE_HIGH");

		return 0;
	case 20:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_feedback_imd_fault_FEEDBACK_STATE_LOW");
		snprintf(v[1], string_size, "primary_hv_feedback_status_feedback_imd_fault_FEEDBACK_STATE_ERROR");
		snprintf(v[2], string_size, "primary_hv_feedback_status_feedback_imd_fault_FEEDBACK_STATE_HIGH");

		return 0;
	case 21:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_feedback_check_mux_FEEDBACK_STATE_LOW");
		snprintf(v[1], string_size, "primary_hv_feedback_status_feedback_check_mux_FEEDBACK_STATE_ERROR");
		snprintf(v[2], string_size, "primary_hv_feedback_status_feedback_check_mux_FEEDBACK_STATE_HIGH");

		return 0;
	case 22:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_feedback_sd_end_FEEDBACK_STATE_LOW");
		snprintf(v[1], string_size, "primary_hv_feedback_status_feedback_sd_end_FEEDBACK_STATE_ERROR");
		snprintf(v[2], string_size, "primary_hv_feedback_status_feedback_sd_end_FEEDBACK_STATE_HIGH");

		return 0;
	case 23:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_feedback_sd_out_FEEDBACK_STATE_LOW");
		snprintf(v[1], string_size, "primary_hv_feedback_status_feedback_sd_out_FEEDBACK_STATE_ERROR");
		snprintf(v[2], string_size, "primary_hv_feedback_status_feedback_sd_out_FEEDBACK_STATE_HIGH");

		return 0;
	case 24:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_feedback_sd_in_FEEDBACK_STATE_LOW");
		snprintf(v[1], string_size, "primary_hv_feedback_status_feedback_sd_in_FEEDBACK_STATE_ERROR");
		snprintf(v[2], string_size, "primary_hv_feedback_status_feedback_sd_in_FEEDBACK_STATE_HIGH");

		return 0;
	case 25:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_feedback_sd_bms_FEEDBACK_STATE_LOW");
		snprintf(v[1], string_size, "primary_hv_feedback_status_feedback_sd_bms_FEEDBACK_STATE_ERROR");
		snprintf(v[2], string_size, "primary_hv_feedback_status_feedback_sd_bms_FEEDBACK_STATE_HIGH");

		return 0;
	case 26:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_feedback_status_feedback_sd_imd_FEEDBACK_STATE_LOW");
		snprintf(v[1], string_size, "primary_hv_feedback_status_feedback_sd_imd_FEEDBACK_STATE_ERROR");
		snprintf(v[2], string_size, "primary_hv_feedback_status_feedback_sd_imd_FEEDBACK_STATE_HIGH");

		return 0;
	case 27:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_imd_status_imd_status_IMD_SC");
		snprintf(v[1], string_size, "primary_hv_imd_status_imd_status_IMD_NORMAL");
		snprintf(v[2], string_size, "primary_hv_imd_status_imd_status_IMD_UNDER_VOLTAGE");
		snprintf(v[3], string_size, "primary_hv_imd_status_imd_status_IMD_START_MEASURE");
		snprintf(v[4], string_size, "primary_hv_imd_status_imd_status_IMD_DEVICE_ERROR");
		snprintf(v[5], string_size, "primary_hv_imd_status_imd_status_IMD_EARTH_FAULT");

		return 0;
	case 28:
		if(7 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ts_status_ts_status_INIT");
		snprintf(v[1], string_size, "primary_ts_status_ts_status_IDLE");
		snprintf(v[2], string_size, "primary_ts_status_ts_status_AIRN_CLOSE");
		snprintf(v[3], string_size, "primary_ts_status_ts_status_PRECHARGE");
		snprintf(v[4], string_size, "primary_ts_status_ts_status_AIRP_CLOSE");
		snprintf(v[5], string_size, "primary_ts_status_ts_status_TS_ON");
		snprintf(v[6], string_size, "primary_ts_status_ts_status_FATAL_ERROR");

		return 0;
	case 29:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_set_ts_status_das_ts_status_set_OFF");
		snprintf(v[1], string_size, "primary_set_ts_status_das_ts_status_set_ON");

		return 0;
	case 30:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_set_ts_status_handcart_ts_status_set_OFF");
		snprintf(v[1], string_size, "primary_set_ts_status_handcart_ts_status_set_ON");

		return 0;
	case 31:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_set_car_status_car_status_set_IDLE");
		snprintf(v[1], string_size, "primary_set_car_status_car_status_set_READY");
		snprintf(v[2], string_size, "primary_set_car_status_car_status_set_DRIVE");

		return 0;
	case 32:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_set_pedal_calibration_pedal_ACCELERATOR");
		snprintf(v[1], string_size, "primary_set_pedal_calibration_pedal_BRAKE");

		return 0;
	case 33:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_set_pedal_calibration_bound_SET_MAX");
		snprintf(v[1], string_size, "primary_set_pedal_calibration_bound_SET_MIN");

		return 0;
	case 34:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_pedal_calibration_ack_pedal_ACCELERATOR");
		snprintf(v[1], string_size, "primary_pedal_calibration_ack_pedal_BRAKE");

		return 0;
	case 35:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_pedal_calibration_ack_bound_SET_MAX");
		snprintf(v[1], string_size, "primary_pedal_calibration_ack_bound_SET_MIN");

		return 0;
	case 36:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_car_status_inverter_l_OFF");
		snprintf(v[1], string_size, "primary_car_status_inverter_l_IDLE");
		snprintf(v[2], string_size, "primary_car_status_inverter_l_ON");

		return 0;
	case 37:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_car_status_inverter_r_OFF");
		snprintf(v[1], string_size, "primary_car_status_inverter_r_IDLE");
		snprintf(v[2], string_size, "primary_car_status_inverter_r_ON");

		return 0;
	case 38:
		if(13 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_car_status_car_status_INIT");
		snprintf(v[1], string_size, "primary_car_status_car_status_ENABLE_INV_UPDATES");
		snprintf(v[2], string_size, "primary_car_status_car_status_CHECK_INV_SETTINGS");
		snprintf(v[3], string_size, "primary_car_status_car_status_IDLE");
		snprintf(v[4], string_size, "primary_car_status_car_status_START_TS_PRECHARGE");
		snprintf(v[5], string_size, "primary_car_status_car_status_WAIT_TS_PRECHARGE");
		snprintf(v[6], string_size, "primary_car_status_car_status_WAIT_DRIVER");
		snprintf(v[7], string_size, "primary_car_status_car_status_ENABLE_INV_DRIVE");
		snprintf(v[8], string_size, "primary_car_status_car_status_DRIVE");
		snprintf(v[9], string_size, "primary_car_status_car_status_DISABLE_INV_DRIVE");
		snprintf(v[10], string_size, "primary_car_status_car_status_START_TS_DISCHARGE");
		snprintf(v[11], string_size, "primary_car_status_car_status_WAIT_TS_DISCHARGE");
		snprintf(v[12], string_size, "primary_car_status_car_status_FATAL_ERROR");

		return 0;
	case 39:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_lv_status_status_INIT");
		snprintf(v[1], string_size, "primary_lv_status_status_RUN");
		snprintf(v[2], string_size, "primary_lv_status_status_ERROR");

		return 0;
	case 40:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_set_inverter_connection_status_status_OFF");
		snprintf(v[1], string_size, "primary_set_inverter_connection_status_status_ON");

		return 0;
	case 41:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_inverter_connection_status_status_OFF");
		snprintf(v[1], string_size, "primary_inverter_connection_status_status_ON");

		return 0;
	case 42:
		if(3 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_lv_can_flash_ack_response_NO_FLASH");
		snprintf(v[1], string_size, "primary_lv_can_flash_ack_response_FLASH");
		snprintf(v[2], string_size, "primary_lv_can_flash_ack_response_PREPARING_TO_FLASH");

		return 0;
	case 43:
		if(6 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_cell_balancing_status_cellboard_id_CELLBOARD_0");
		snprintf(v[1], string_size, "primary_hv_cell_balancing_status_cellboard_id_CELLBOARD_1");
		snprintf(v[2], string_size, "primary_hv_cell_balancing_status_cellboard_id_CELLBOARD_2");
		snprintf(v[3], string_size, "primary_hv_cell_balancing_status_cellboard_id_CELLBOARD_3");
		snprintf(v[4], string_size, "primary_hv_cell_balancing_status_cellboard_id_CELLBOARD_4");
		snprintf(v[5], string_size, "primary_hv_cell_balancing_status_cellboard_id_CELLBOARD_5");

		return 0;
	case 44:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_hv_cell_balancing_status_balancing_status_OFF");
		snprintf(v[1], string_size, "primary_hv_cell_balancing_status_balancing_status_ON");

		return 0;
	case 45:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_set_cell_balancing_status_set_balancing_status_OFF");
		snprintf(v[1], string_size, "primary_set_cell_balancing_status_set_balancing_status_ON");

		return 0;
	case 46:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_handcart_settings_fans_override_OFF");
		snprintf(v[1], string_size, "primary_handcart_settings_fans_override_ON");

		return 0;
	case 47:
		if(9 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_handcart_settings_status_NONE");
		snprintf(v[1], string_size, "primary_handcart_settings_status_CHECK");
		snprintf(v[2], string_size, "primary_handcart_settings_status_IDLE");
		snprintf(v[3], string_size, "primary_handcart_settings_status_PRECHARGE");
		snprintf(v[4], string_size, "primary_handcart_settings_status_READY");
		snprintf(v[5], string_size, "primary_handcart_settings_status_CHARGE");
		snprintf(v[6], string_size, "primary_handcart_settings_status_CHARGE_DONE");
		snprintf(v[7], string_size, "primary_handcart_settings_status_BALANCING");
		snprintf(v[8], string_size, "primary_handcart_settings_status_ERROR");

		return 0;
	case 48:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_handcart_settings_set_fans_override_OFF");
		snprintf(v[1], string_size, "primary_handcart_settings_set_fans_override_ON");

		return 0;
	case 49:
		if(9 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_handcart_settings_set_status_NONE");
		snprintf(v[1], string_size, "primary_handcart_settings_set_status_CHECK");
		snprintf(v[2], string_size, "primary_handcart_settings_set_status_IDLE");
		snprintf(v[3], string_size, "primary_handcart_settings_set_status_PRECHARGE");
		snprintf(v[4], string_size, "primary_handcart_settings_set_status_READY");
		snprintf(v[5], string_size, "primary_handcart_settings_set_status_CHARGE");
		snprintf(v[6], string_size, "primary_handcart_settings_set_status_CHARGE_DONE");
		snprintf(v[7], string_size, "primary_handcart_settings_set_status_BALANCING");
		snprintf(v[8], string_size, "primary_handcart_settings_set_status_ERROR");

		return 0;
	case 50:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_set_ptt_status_status_OFF");
		snprintf(v[1], string_size, "primary_set_ptt_status_status_ON");

		return 0;
	case 51:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_ptt_status_status_OFF");
		snprintf(v[1], string_size, "primary_ptt_status_status_ON");

		return 0;
	case 52:
		if(2 > fields_size) return 1;
		snprintf(v[0], string_size, "primary_regen_manual_command_status_OFF");
		snprintf(v[1], string_size, "primary_regen_manual_command_status_ON");

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
	case 3:
	{
		primary_hv_can_forward_t tmp;
		primary_hv_can_forward_converted_t tmp_converted;
		uint8_t r_can_forward_set;

		sscanf(s, "%" SCNu8 ","  ,
			&r_can_forward_set);
		tmp_converted.can_forward_set = (primary_hv_can_forward_can_forward_set)r_can_forward_set;

		primary_hv_can_forward_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_HV_CAN_FORWARD_BYTE_SIZE;
		return primary_hv_can_forward_pack(data, &tmp, PRIMARY_HV_CAN_FORWARD_BYTE_SIZE);
	}
	case 700:
	{
		primary_steer_version_t tmp;
		primary_steer_version_converted_t tmp_converted;
		uint32_t r_component_build_time;
		uint32_t r_canlib_build_time;

		sscanf(s, "%" SCNu32 "," 
			"%" SCNu32 "," ,
			&r_component_build_time,
			&r_canlib_build_time);
		tmp_converted.component_build_time = (uint32_t)r_component_build_time;
		tmp_converted.canlib_build_time = (uint32_t)r_canlib_build_time;

		primary_steer_version_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_STEER_VERSION_BYTE_SIZE;
		return primary_steer_version_pack(data, &tmp, PRIMARY_STEER_VERSION_BYTE_SIZE);
	}
	case 701:
	{
		primary_das_version_t tmp;
		primary_das_version_converted_t tmp_converted;
		uint32_t r_component_build_time;
		uint32_t r_canlib_build_time;

		sscanf(s, "%" SCNu32 "," 
			"%" SCNu32 "," ,
			&r_component_build_time,
			&r_canlib_build_time);
		tmp_converted.component_build_time = (uint32_t)r_component_build_time;
		tmp_converted.canlib_build_time = (uint32_t)r_canlib_build_time;

		primary_das_version_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_DAS_VERSION_BYTE_SIZE;
		return primary_das_version_pack(data, &tmp, PRIMARY_DAS_VERSION_BYTE_SIZE);
	}
	case 702:
	{
		primary_mainboard_version_t tmp;
		primary_mainboard_version_converted_t tmp_converted;
		uint32_t r_component_build_time;
		uint32_t r_canlib_build_time;

		sscanf(s, "%" SCNu32 "," 
			"%" SCNu32 "," ,
			&r_component_build_time,
			&r_canlib_build_time);
		tmp_converted.component_build_time = (uint32_t)r_component_build_time;
		tmp_converted.canlib_build_time = (uint32_t)r_canlib_build_time;

		primary_mainboard_version_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_MAINBOARD_VERSION_BYTE_SIZE;
		return primary_mainboard_version_pack(data, &tmp, PRIMARY_MAINBOARD_VERSION_BYTE_SIZE);
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
	case 705:
	{
		primary_cellboard_version_t tmp;
		primary_cellboard_version_converted_t tmp_converted;
		uint8_t r_cellboard_id;
		uint16_t r_component_version;
		uint32_t r_canlib_build_time;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu16 "," 
			"%" SCNu32 "," ,
			&r_cellboard_id,
			&r_component_version,
			&r_canlib_build_time);
		tmp_converted.cellboard_id = (primary_cellboard_version_cellboard_id)r_cellboard_id;
		tmp_converted.component_version = (uint16_t)r_component_version;
		tmp_converted.canlib_build_time = (uint32_t)r_canlib_build_time;

		primary_cellboard_version_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_CELLBOARD_VERSION_BYTE_SIZE;
		return primary_cellboard_version_pack(data, &tmp, PRIMARY_CELLBOARD_VERSION_BYTE_SIZE);
	}
	case 257:
	{
		primary_ambient_temperature_t tmp;
		primary_ambient_temperature_converted_t tmp_converted;
		int16_t r_temp;

		sscanf(s, "%" SCNi16 "," ,
			&r_temp);
		tmp_converted.temp = (int16_t)r_temp;

		primary_ambient_temperature_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_AMBIENT_TEMPERATURE_BYTE_SIZE;
		return primary_ambient_temperature_pack(data, &tmp, PRIMARY_AMBIENT_TEMPERATURE_BYTE_SIZE);
	}
	case 1072:
	{
		primary_data_logger_t tmp;
		primary_data_logger_converted_t tmp_converted;
		uint32_t r_placeholder1;
		uint32_t r_placeholder2;

		sscanf(s, "%" SCNu32 "," 
			"%" SCNu32 "," ,
			&r_placeholder1,
			&r_placeholder2);
		tmp_converted.placeholder1 = (uint32_t)r_placeholder1;
		tmp_converted.placeholder2 = (uint32_t)r_placeholder2;

		primary_data_logger_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_DATA_LOGGER_BYTE_SIZE;
		return primary_data_logger_pack(data, &tmp, PRIMARY_DATA_LOGGER_BYTE_SIZE);
	}
	case 265:
	{
		primary_set_tlm_status_t tmp;
		primary_set_tlm_status_converted_t tmp_converted;
		uint8_t r_tlm_status;

		sscanf(s, "%" SCNu8 ","  ,
			&r_tlm_status);
		tmp_converted.tlm_status = (primary_set_tlm_status_tlm_status)r_tlm_status;

		primary_set_tlm_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_SET_TLM_STATUS_BYTE_SIZE;
		return primary_set_tlm_status_pack(data, &tmp, PRIMARY_SET_TLM_STATUS_BYTE_SIZE);
	}
	case 264:
	{
		primary_tlm_status_t tmp;
		primary_tlm_status_converted_t tmp_converted;
		uint8_t r_tlm_status;

		sscanf(s, "%" SCNu8 ","  ,
			&r_tlm_status);
		tmp_converted.tlm_status = (primary_tlm_status_tlm_status)r_tlm_status;

		primary_tlm_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_TLM_STATUS_BYTE_SIZE;
		return primary_tlm_status_pack(data, &tmp, PRIMARY_TLM_STATUS_BYTE_SIZE);
	}
	case 1801:
	{
		primary_steer_system_status_t tmp;
		primary_steer_system_status_converted_t tmp_converted;
		uint8_t r_soc_temp;

		sscanf(s, "%" SCNu8 ","  ,
			&r_soc_temp);
		tmp_converted.soc_temp = (uint8_t)r_soc_temp;

		primary_steer_system_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_STEER_SYSTEM_STATUS_BYTE_SIZE;
		return primary_steer_system_status_pack(data, &tmp, PRIMARY_STEER_SYSTEM_STATUS_BYTE_SIZE);
	}
	case 772:
	{
		primary_hv_voltage_t tmp;
		primary_hv_voltage_converted_t tmp_converted;
		float r_pack_voltage;
		float r_bus_voltage;

		sscanf(s, "%f,"       
			"%f,"       ,
			&r_pack_voltage,
			&r_bus_voltage);
		tmp_converted.pack_voltage = (float)r_pack_voltage;
		tmp_converted.bus_voltage = (float)r_bus_voltage;

		primary_hv_voltage_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_HV_VOLTAGE_BYTE_SIZE;
		return primary_hv_voltage_pack(data, &tmp, PRIMARY_HV_VOLTAGE_BYTE_SIZE);
	}
	case 804:
	{
		primary_hv_cell_voltage_t tmp;
		primary_hv_cell_voltage_converted_t tmp_converted;
		float r_max_cell_voltage;
		float r_min_cell_voltage;
		float r_sum_cell_voltage;
		float r_avg_cell_voltage;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_max_cell_voltage,
			&r_min_cell_voltage,
			&r_sum_cell_voltage,
			&r_avg_cell_voltage);
		tmp_converted.max_cell_voltage = (float)r_max_cell_voltage;
		tmp_converted.min_cell_voltage = (float)r_min_cell_voltage;
		tmp_converted.sum_cell_voltage = (float)r_sum_cell_voltage;
		tmp_converted.avg_cell_voltage = (float)r_avg_cell_voltage;

		primary_hv_cell_voltage_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_HV_CELL_VOLTAGE_BYTE_SIZE;
		return primary_hv_cell_voltage_pack(data, &tmp, PRIMARY_HV_CELL_VOLTAGE_BYTE_SIZE);
	}
	case 836:
	{
		primary_hv_current_t tmp;
		primary_hv_current_converted_t tmp_converted;
		float r_current;
		float r_power;
		float r_energy;
		float r_soc;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_current,
			&r_power,
			&r_energy,
			&r_soc);
		tmp_converted.current = (float)r_current;
		tmp_converted.power = (float)r_power;
		tmp_converted.energy = (float)r_energy;
		tmp_converted.soc = (float)r_soc;

		primary_hv_current_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_HV_CURRENT_BYTE_SIZE;
		return primary_hv_current_pack(data, &tmp, PRIMARY_HV_CURRENT_BYTE_SIZE);
	}
	case 868:
	{
		primary_hv_temp_t tmp;
		primary_hv_temp_converted_t tmp_converted;
		float r_average_temp;
		float r_max_temp;
		float r_min_temp;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       ,
			&r_average_temp,
			&r_max_temp,
			&r_min_temp);
		tmp_converted.average_temp = (float)r_average_temp;
		tmp_converted.max_temp = (float)r_max_temp;
		tmp_converted.min_temp = (float)r_min_temp;

		primary_hv_temp_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_HV_TEMP_BYTE_SIZE;
		return primary_hv_temp_pack(data, &tmp, PRIMARY_HV_TEMP_BYTE_SIZE);
	}
	case 36:
	{
		primary_hv_errors_t tmp;
		primary_hv_errors_converted_t tmp_converted;
		uint8_t r_warnings_cell_low_voltage;
		uint8_t r_warnings_cell_under_voltage;
		uint8_t r_warnings_cell_over_voltage;
		uint8_t r_warnings_cell_high_temperature;
		uint8_t r_warnings_cell_over_temperature;
		uint8_t r_warnings_over_current;
		uint8_t r_warnings_can;
		uint8_t r_warnings_int_voltage_mismatch;
		uint8_t r_warnings_cellboard_comm;
		uint8_t r_warnings_cellboard_internal;
		uint8_t r_warnings_connector_disconnected;
		uint8_t r_warnings_fans_disconnected;
		uint8_t r_warnings_feedback;
		uint8_t r_warnings_feedback_circuitry;
		uint8_t r_warnings_eeprom_comm;
		uint8_t r_warnings_eeprom_write;
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
			"%" SCNu8 ","  ,
			&r_warnings_cell_low_voltage,
			&r_warnings_cell_under_voltage,
			&r_warnings_cell_over_voltage,
			&r_warnings_cell_high_temperature,
			&r_warnings_cell_over_temperature,
			&r_warnings_over_current,
			&r_warnings_can,
			&r_warnings_int_voltage_mismatch,
			&r_warnings_cellboard_comm,
			&r_warnings_cellboard_internal,
			&r_warnings_connector_disconnected,
			&r_warnings_fans_disconnected,
			&r_warnings_feedback,
			&r_warnings_feedback_circuitry,
			&r_warnings_eeprom_comm,
			&r_warnings_eeprom_write,
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
		tmp_converted.warnings_cell_low_voltage = (uint8_t)r_warnings_cell_low_voltage;
		tmp_converted.warnings_cell_under_voltage = (uint8_t)r_warnings_cell_under_voltage;
		tmp_converted.warnings_cell_over_voltage = (uint8_t)r_warnings_cell_over_voltage;
		tmp_converted.warnings_cell_high_temperature = (uint8_t)r_warnings_cell_high_temperature;
		tmp_converted.warnings_cell_over_temperature = (uint8_t)r_warnings_cell_over_temperature;
		tmp_converted.warnings_over_current = (uint8_t)r_warnings_over_current;
		tmp_converted.warnings_can = (uint8_t)r_warnings_can;
		tmp_converted.warnings_int_voltage_mismatch = (uint8_t)r_warnings_int_voltage_mismatch;
		tmp_converted.warnings_cellboard_comm = (uint8_t)r_warnings_cellboard_comm;
		tmp_converted.warnings_cellboard_internal = (uint8_t)r_warnings_cellboard_internal;
		tmp_converted.warnings_connector_disconnected = (uint8_t)r_warnings_connector_disconnected;
		tmp_converted.warnings_fans_disconnected = (uint8_t)r_warnings_fans_disconnected;
		tmp_converted.warnings_feedback = (uint8_t)r_warnings_feedback;
		tmp_converted.warnings_feedback_circuitry = (uint8_t)r_warnings_feedback_circuitry;
		tmp_converted.warnings_eeprom_comm = (uint8_t)r_warnings_eeprom_comm;
		tmp_converted.warnings_eeprom_write = (uint8_t)r_warnings_eeprom_write;
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
	case 32:
	{
		primary_hv_fans_override_t tmp;
		primary_hv_fans_override_converted_t tmp_converted;
		uint8_t r_fans_override;
		float r_fans_speed;

		sscanf(s, "%" SCNu8 ","  
			"%f,"       ,
			&r_fans_override,
			&r_fans_speed);
		tmp_converted.fans_override = (primary_hv_fans_override_fans_override)r_fans_override;
		tmp_converted.fans_speed = (float)r_fans_speed;

		primary_hv_fans_override_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_HV_FANS_OVERRIDE_BYTE_SIZE;
		return primary_hv_fans_override_pack(data, &tmp, PRIMARY_HV_FANS_OVERRIDE_BYTE_SIZE);
	}
	case 37:
	{
		primary_hv_can_forward_status_t tmp;
		primary_hv_can_forward_status_converted_t tmp_converted;
		uint8_t r_can_forward_status;

		sscanf(s, "%" SCNu8 ","  ,
			&r_can_forward_status);
		tmp_converted.can_forward_status = (primary_hv_can_forward_status_can_forward_status)r_can_forward_status;

		primary_hv_can_forward_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_HV_CAN_FORWARD_STATUS_BYTE_SIZE;
		return primary_hv_can_forward_status_pack(data, &tmp, PRIMARY_HV_CAN_FORWARD_STATUS_BYTE_SIZE);
	}
	case 773:
	{
		primary_hv_fans_override_status_t tmp;
		primary_hv_fans_override_status_converted_t tmp_converted;
		uint8_t r_fans_override;
		float r_fans_speed;

		sscanf(s, "%" SCNu8 ","  
			"%f,"       ,
			&r_fans_override,
			&r_fans_speed);
		tmp_converted.fans_override = (primary_hv_fans_override_status_fans_override)r_fans_override;
		tmp_converted.fans_speed = (float)r_fans_speed;

		primary_hv_fans_override_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_HV_FANS_OVERRIDE_STATUS_BYTE_SIZE;
		return primary_hv_fans_override_status_pack(data, &tmp, PRIMARY_HV_FANS_OVERRIDE_STATUS_BYTE_SIZE);
	}
	case 771:
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
	case 516:
	{
		primary_hv_feedback_ts_voltage_t tmp;
		primary_hv_feedback_ts_voltage_converted_t tmp_converted;
		float r_feedback_ts_over_60v_status;
		float r_feedback_airn_status;
		float r_feedback_airp_status;
		float r_feedback_airp_gate;
		float r_feedback_airn_gate;
		float r_feedback_precharge_status;
		float r_feedback_tsp_over_60v_status;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       
			"%f,"       
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_feedback_ts_over_60v_status,
			&r_feedback_airn_status,
			&r_feedback_airp_status,
			&r_feedback_airp_gate,
			&r_feedback_airn_gate,
			&r_feedback_precharge_status,
			&r_feedback_tsp_over_60v_status);
		tmp_converted.feedback_ts_over_60v_status = (float)r_feedback_ts_over_60v_status;
		tmp_converted.feedback_airn_status = (float)r_feedback_airn_status;
		tmp_converted.feedback_airp_status = (float)r_feedback_airp_status;
		tmp_converted.feedback_airp_gate = (float)r_feedback_airp_gate;
		tmp_converted.feedback_airn_gate = (float)r_feedback_airn_gate;
		tmp_converted.feedback_precharge_status = (float)r_feedback_precharge_status;
		tmp_converted.feedback_tsp_over_60v_status = (float)r_feedback_tsp_over_60v_status;

		primary_hv_feedback_ts_voltage_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_HV_FEEDBACK_TS_VOLTAGE_BYTE_SIZE;
		return primary_hv_feedback_ts_voltage_pack(data, &tmp, PRIMARY_HV_FEEDBACK_TS_VOLTAGE_BYTE_SIZE);
	}
	case 548:
	{
		primary_hv_feedback_misc_voltage_t tmp;
		primary_hv_feedback_misc_voltage_converted_t tmp_converted;
		float r_feedback_implausibility_detected;
		float r_feedback_imd_cockpit;
		float r_feedback_tsal_green_fault_latched;
		float r_feedback_bms_cockpit;
		float r_feedback_ext_latched;
		float r_feedback_tsal_green;
		float r_imd_fault;
		float r_feedback_check_mux;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       
			"%f,"       
			"%f,"       
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_feedback_implausibility_detected,
			&r_feedback_imd_cockpit,
			&r_feedback_tsal_green_fault_latched,
			&r_feedback_bms_cockpit,
			&r_feedback_ext_latched,
			&r_feedback_tsal_green,
			&r_imd_fault,
			&r_feedback_check_mux);
		tmp_converted.feedback_implausibility_detected = (float)r_feedback_implausibility_detected;
		tmp_converted.feedback_imd_cockpit = (float)r_feedback_imd_cockpit;
		tmp_converted.feedback_tsal_green_fault_latched = (float)r_feedback_tsal_green_fault_latched;
		tmp_converted.feedback_bms_cockpit = (float)r_feedback_bms_cockpit;
		tmp_converted.feedback_ext_latched = (float)r_feedback_ext_latched;
		tmp_converted.feedback_tsal_green = (float)r_feedback_tsal_green;
		tmp_converted.imd_fault = (float)r_imd_fault;
		tmp_converted.feedback_check_mux = (float)r_feedback_check_mux;

		primary_hv_feedback_misc_voltage_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_HV_FEEDBACK_MISC_VOLTAGE_BYTE_SIZE;
		return primary_hv_feedback_misc_voltage_pack(data, &tmp, PRIMARY_HV_FEEDBACK_MISC_VOLTAGE_BYTE_SIZE);
	}
	case 580:
	{
		primary_hv_feedback_sd_voltage_t tmp;
		primary_hv_feedback_sd_voltage_converted_t tmp_converted;
		float r_feedback_sd_end;
		float r_feedback_sd_out;
		float r_feedback_sd_in;
		float r_feedback_sd_bms;
		float r_feedback_sd_imd;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_feedback_sd_end,
			&r_feedback_sd_out,
			&r_feedback_sd_in,
			&r_feedback_sd_bms,
			&r_feedback_sd_imd);
		tmp_converted.feedback_sd_end = (float)r_feedback_sd_end;
		tmp_converted.feedback_sd_out = (float)r_feedback_sd_out;
		tmp_converted.feedback_sd_in = (float)r_feedback_sd_in;
		tmp_converted.feedback_sd_bms = (float)r_feedback_sd_bms;
		tmp_converted.feedback_sd_imd = (float)r_feedback_sd_imd;

		primary_hv_feedback_sd_voltage_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_HV_FEEDBACK_SD_VOLTAGE_BYTE_SIZE;
		return primary_hv_feedback_sd_voltage_pack(data, &tmp, PRIMARY_HV_FEEDBACK_SD_VOLTAGE_BYTE_SIZE);
	}
	case 803:
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
	case 84:
	{
		primary_ts_status_t tmp;
		primary_ts_status_converted_t tmp_converted;
		uint8_t r_ts_status;

		sscanf(s, "%" SCNu8 ","  ,
			&r_ts_status);
		tmp_converted.ts_status = (primary_ts_status_ts_status)r_ts_status;

		primary_ts_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_TS_STATUS_BYTE_SIZE;
		return primary_ts_status_pack(data, &tmp, PRIMARY_TS_STATUS_BYTE_SIZE);
	}
	case 82:
	{
		primary_set_ts_status_das_t tmp;
		primary_set_ts_status_das_converted_t tmp_converted;
		uint8_t r_ts_status_set;

		sscanf(s, "%" SCNu8 ","  ,
			&r_ts_status_set);
		tmp_converted.ts_status_set = (primary_set_ts_status_das_ts_status_set)r_ts_status_set;

		primary_set_ts_status_das_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_SET_TS_STATUS_DAS_BYTE_SIZE;
		return primary_set_ts_status_das_pack(data, &tmp, PRIMARY_SET_TS_STATUS_DAS_BYTE_SIZE);
	}
	case 83:
	{
		primary_set_ts_status_handcart_t tmp;
		primary_set_ts_status_handcart_converted_t tmp_converted;
		uint8_t r_ts_status_set;

		sscanf(s, "%" SCNu8 ","  ,
			&r_ts_status_set);
		tmp_converted.ts_status_set = (primary_set_ts_status_handcart_ts_status_set)r_ts_status_set;

		primary_set_ts_status_handcart_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_SET_TS_STATUS_HANDCART_BYTE_SIZE;
		return primary_set_ts_status_handcart_pack(data, &tmp, PRIMARY_SET_TS_STATUS_HANDCART_BYTE_SIZE);
	}
	case 258:
	{
		primary_steer_status_t tmp;
		primary_steer_status_converted_t tmp_converted;
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

		primary_steer_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_STEER_STATUS_BYTE_SIZE;
		return primary_steer_status_pack(data, &tmp, PRIMARY_STEER_STATUS_BYTE_SIZE);
	}
	case 80:
	{
		primary_set_car_status_t tmp;
		primary_set_car_status_converted_t tmp_converted;
		uint8_t r_car_status_set;

		sscanf(s, "%" SCNu8 ","  ,
			&r_car_status_set);
		tmp_converted.car_status_set = (primary_set_car_status_car_status_set)r_car_status_set;

		primary_set_car_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_SET_CAR_STATUS_BYTE_SIZE;
		return primary_set_car_status_pack(data, &tmp, PRIMARY_SET_CAR_STATUS_BYTE_SIZE);
	}
	case 1026:
	{
		primary_set_pedal_calibration_t tmp;
		primary_set_pedal_calibration_converted_t tmp_converted;
		uint8_t r_pedal;
		uint8_t r_bound;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  ,
			&r_pedal,
			&r_bound);
		tmp_converted.pedal = (primary_set_pedal_calibration_pedal)r_pedal;
		tmp_converted.bound = (primary_set_pedal_calibration_bound)r_bound;

		primary_set_pedal_calibration_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_SET_PEDAL_CALIBRATION_BYTE_SIZE;
		return primary_set_pedal_calibration_pack(data, &tmp, PRIMARY_SET_PEDAL_CALIBRATION_BYTE_SIZE);
	}
	case 1032:
	{
		primary_pedal_calibration_ack_t tmp;
		primary_pedal_calibration_ack_converted_t tmp_converted;
		uint8_t r_pedal;
		uint8_t r_bound;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  ,
			&r_pedal,
			&r_bound);
		tmp_converted.pedal = (primary_pedal_calibration_ack_pedal)r_pedal;
		tmp_converted.bound = (primary_pedal_calibration_ack_bound)r_bound;

		primary_pedal_calibration_ack_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_PEDAL_CALIBRATION_ACK_BYTE_SIZE;
		return primary_pedal_calibration_ack_pack(data, &tmp, PRIMARY_PEDAL_CALIBRATION_ACK_BYTE_SIZE);
	}
	case 81:
	{
		primary_car_status_t tmp;
		primary_car_status_converted_t tmp_converted;
		uint8_t r_inverter_l;
		uint8_t r_inverter_r;
		uint8_t r_car_status;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  ,
			&r_inverter_l,
			&r_inverter_r,
			&r_car_status);
		tmp_converted.inverter_l = (primary_car_status_inverter_l)r_inverter_l;
		tmp_converted.inverter_r = (primary_car_status_inverter_r)r_inverter_r;
		tmp_converted.car_status = (primary_car_status_car_status)r_car_status;

		primary_car_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_CAR_STATUS_BYTE_SIZE;
		return primary_car_status_pack(data, &tmp, PRIMARY_CAR_STATUS_BYTE_SIZE);
	}
	case 40:
	{
		primary_das_errors_t tmp;
		primary_das_errors_converted_t tmp_converted;
		uint8_t r_das_error_pedal_adc;
		uint8_t r_das_error_pedal_implausibility;
		uint8_t r_das_error_imu_tout;
		uint8_t r_das_error_irts_tout;
		uint8_t r_das_error_ts_tout;
		uint8_t r_das_error_invl_tout;
		uint8_t r_das_error_invr_tout;
		uint8_t r_das_error_steer_tout;
		uint8_t r_das_error_fsm;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  ,
			&r_das_error_pedal_adc,
			&r_das_error_pedal_implausibility,
			&r_das_error_imu_tout,
			&r_das_error_irts_tout,
			&r_das_error_ts_tout,
			&r_das_error_invl_tout,
			&r_das_error_invr_tout,
			&r_das_error_steer_tout,
			&r_das_error_fsm);
		tmp_converted.das_error_pedal_adc = (uint8_t)r_das_error_pedal_adc;
		tmp_converted.das_error_pedal_implausibility = (uint8_t)r_das_error_pedal_implausibility;
		tmp_converted.das_error_imu_tout = (uint8_t)r_das_error_imu_tout;
		tmp_converted.das_error_irts_tout = (uint8_t)r_das_error_irts_tout;
		tmp_converted.das_error_ts_tout = (uint8_t)r_das_error_ts_tout;
		tmp_converted.das_error_invl_tout = (uint8_t)r_das_error_invl_tout;
		tmp_converted.das_error_invr_tout = (uint8_t)r_das_error_invr_tout;
		tmp_converted.das_error_steer_tout = (uint8_t)r_das_error_steer_tout;
		tmp_converted.das_error_fsm = (uint8_t)r_das_error_fsm;

		primary_das_errors_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_DAS_ERRORS_BYTE_SIZE;
		return primary_das_errors_pack(data, &tmp, PRIMARY_DAS_ERRORS_BYTE_SIZE);
	}
	case 777:
	{
		primary_ecu_feedbacks_t tmp;
		primary_ecu_feedbacks_converted_t tmp_converted;
		uint8_t r_ecu_feedbacks_sd_cock_fb;
		uint8_t r_ecu_feedbacks_sd_fb1;
		uint8_t r_ecu_feedbacks_sd_bots_fb;
		uint8_t r_ecu_feedbacks_sd_interial_fb;
		uint8_t r_ecu_feedbacks_sd_fb4;
		uint8_t r_ecu_feedbacks_sd_in;
		uint8_t r_ecu_feedbacks_sd_out;
		uint8_t r_ecu_feedbacks_sd_ctrl_pin;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  ,
			&r_ecu_feedbacks_sd_cock_fb,
			&r_ecu_feedbacks_sd_fb1,
			&r_ecu_feedbacks_sd_bots_fb,
			&r_ecu_feedbacks_sd_interial_fb,
			&r_ecu_feedbacks_sd_fb4,
			&r_ecu_feedbacks_sd_in,
			&r_ecu_feedbacks_sd_out,
			&r_ecu_feedbacks_sd_ctrl_pin);
		tmp_converted.ecu_feedbacks_sd_cock_fb = (uint8_t)r_ecu_feedbacks_sd_cock_fb;
		tmp_converted.ecu_feedbacks_sd_fb1 = (uint8_t)r_ecu_feedbacks_sd_fb1;
		tmp_converted.ecu_feedbacks_sd_bots_fb = (uint8_t)r_ecu_feedbacks_sd_bots_fb;
		tmp_converted.ecu_feedbacks_sd_interial_fb = (uint8_t)r_ecu_feedbacks_sd_interial_fb;
		tmp_converted.ecu_feedbacks_sd_fb4 = (uint8_t)r_ecu_feedbacks_sd_fb4;
		tmp_converted.ecu_feedbacks_sd_in = (uint8_t)r_ecu_feedbacks_sd_in;
		tmp_converted.ecu_feedbacks_sd_out = (uint8_t)r_ecu_feedbacks_sd_out;
		tmp_converted.ecu_feedbacks_sd_ctrl_pin = (uint8_t)r_ecu_feedbacks_sd_ctrl_pin;

		primary_ecu_feedbacks_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_ECU_FEEDBACKS_BYTE_SIZE;
		return primary_ecu_feedbacks_pack(data, &tmp, PRIMARY_ECU_FEEDBACKS_BYTE_SIZE);
	}
	case 809:
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
	case 835:
	{
		primary_lv_currents_t tmp;
		primary_lv_currents_converted_t tmp_converted;
		float r_current_as_battery;
		float r_current_lv_battery;
		float r_current_charger;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       ,
			&r_current_as_battery,
			&r_current_lv_battery,
			&r_current_charger);
		tmp_converted.current_as_battery = (float)r_current_as_battery;
		tmp_converted.current_lv_battery = (float)r_current_lv_battery;
		tmp_converted.current_charger = (float)r_current_charger;

		primary_lv_currents_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_LV_CURRENTS_BYTE_SIZE;
		return primary_lv_currents_pack(data, &tmp, PRIMARY_LV_CURRENTS_BYTE_SIZE);
	}
	case 867:
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
	case 899:
	{
		primary_lv_total_voltage_t tmp;
		primary_lv_total_voltage_converted_t tmp_converted;
		float r_total_voltage;

		sscanf(s, "%f,"       ,
			&r_total_voltage);
		tmp_converted.total_voltage = (float)r_total_voltage;

		primary_lv_total_voltage_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_LV_TOTAL_VOLTAGE_BYTE_SIZE;
		return primary_lv_total_voltage_pack(data, &tmp, PRIMARY_LV_TOTAL_VOLTAGE_BYTE_SIZE);
	}
	case 931:
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
	case 963:
	{
		primary_cooling_status_t tmp;
		primary_cooling_status_converted_t tmp_converted;
		float r_radiators_speed;
		float r_pumps_speed;

		sscanf(s, "%f,"       
			"%f,"       ,
			&r_radiators_speed,
			&r_pumps_speed);
		tmp_converted.radiators_speed = (float)r_radiators_speed;
		tmp_converted.pumps_speed = (float)r_pumps_speed;

		primary_cooling_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_COOLING_STATUS_BYTE_SIZE;
		return primary_cooling_status_pack(data, &tmp, PRIMARY_COOLING_STATUS_BYTE_SIZE);
	}
	case 775:
	{
		primary_set_radiator_speed_t tmp;
		primary_set_radiator_speed_converted_t tmp_converted;
		float r_radiators_speed;

		sscanf(s, "%f,"       ,
			&r_radiators_speed);
		tmp_converted.radiators_speed = (float)r_radiators_speed;

		primary_set_radiator_speed_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_SET_RADIATOR_SPEED_BYTE_SIZE;
		return primary_set_radiator_speed_pack(data, &tmp, PRIMARY_SET_RADIATOR_SPEED_BYTE_SIZE);
	}
	case 807:
	{
		primary_set_pumps_speed_t tmp;
		primary_set_pumps_speed_converted_t tmp_converted;
		float r_pumps_speed;

		sscanf(s, "%f,"       ,
			&r_pumps_speed);
		tmp_converted.pumps_speed = (float)r_pumps_speed;

		primary_set_pumps_speed_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_SET_PUMPS_SPEED_BYTE_SIZE;
		return primary_set_pumps_speed_pack(data, &tmp, PRIMARY_SET_PUMPS_SPEED_BYTE_SIZE);
	}
	case 263:
	{
		primary_set_inverter_connection_status_t tmp;
		primary_set_inverter_connection_status_converted_t tmp_converted;
		uint8_t r_status;

		sscanf(s, "%" SCNu8 ","  ,
			&r_status);
		tmp_converted.status = (primary_set_inverter_connection_status_status)r_status;

		primary_set_inverter_connection_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_SET_INVERTER_CONNECTION_STATUS_BYTE_SIZE;
		return primary_set_inverter_connection_status_pack(data, &tmp, PRIMARY_SET_INVERTER_CONNECTION_STATUS_BYTE_SIZE);
	}
	case 259:
	{
		primary_inverter_connection_status_t tmp;
		primary_inverter_connection_status_converted_t tmp_converted;
		uint8_t r_status;

		sscanf(s, "%" SCNu8 ","  ,
			&r_status);
		tmp_converted.status = (primary_inverter_connection_status_status)r_status;

		primary_inverter_connection_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_INVERTER_CONNECTION_STATUS_BYTE_SIZE;
		return primary_inverter_connection_status_pack(data, &tmp, PRIMARY_INVERTER_CONNECTION_STATUS_BYTE_SIZE);
	}
	case 515:
	{
		primary_lv_errors_t tmp;
		primary_lv_errors_converted_t tmp_converted;
		uint8_t r_warnings_cell_undervoltage;
		uint8_t r_warnings_cell_overvoltage;
		uint8_t r_warnings_battery_open_wire;
		uint8_t r_warnings_can;
		uint8_t r_warnings_spi;
		uint8_t r_warnings_over_current;
		uint8_t r_warnings_cell_under_temperature;
		uint8_t r_warnings_cell_over_temperature;
		uint8_t r_warnings_relay;
		uint8_t r_warnings_bms_monitor;
		uint8_t r_warnings_voltages_not_ready;
		uint8_t r_warnings_mcp23017;
		uint8_t r_warnings_radiator;
		uint8_t r_warnings_fan;
		uint8_t r_warnings_pump;
		uint8_t r_warnings_adc_init;
		uint8_t r_warnings_mux;
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
			"%" SCNu8 ","  ,
			&r_warnings_cell_undervoltage,
			&r_warnings_cell_overvoltage,
			&r_warnings_battery_open_wire,
			&r_warnings_can,
			&r_warnings_spi,
			&r_warnings_over_current,
			&r_warnings_cell_under_temperature,
			&r_warnings_cell_over_temperature,
			&r_warnings_relay,
			&r_warnings_bms_monitor,
			&r_warnings_voltages_not_ready,
			&r_warnings_mcp23017,
			&r_warnings_radiator,
			&r_warnings_fan,
			&r_warnings_pump,
			&r_warnings_adc_init,
			&r_warnings_mux,
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
			&r_errors_mux);
		tmp_converted.warnings_cell_undervoltage = (uint8_t)r_warnings_cell_undervoltage;
		tmp_converted.warnings_cell_overvoltage = (uint8_t)r_warnings_cell_overvoltage;
		tmp_converted.warnings_battery_open_wire = (uint8_t)r_warnings_battery_open_wire;
		tmp_converted.warnings_can = (uint8_t)r_warnings_can;
		tmp_converted.warnings_spi = (uint8_t)r_warnings_spi;
		tmp_converted.warnings_over_current = (uint8_t)r_warnings_over_current;
		tmp_converted.warnings_cell_under_temperature = (uint8_t)r_warnings_cell_under_temperature;
		tmp_converted.warnings_cell_over_temperature = (uint8_t)r_warnings_cell_over_temperature;
		tmp_converted.warnings_relay = (uint8_t)r_warnings_relay;
		tmp_converted.warnings_bms_monitor = (uint8_t)r_warnings_bms_monitor;
		tmp_converted.warnings_voltages_not_ready = (uint8_t)r_warnings_voltages_not_ready;
		tmp_converted.warnings_mcp23017 = (uint8_t)r_warnings_mcp23017;
		tmp_converted.warnings_radiator = (uint8_t)r_warnings_radiator;
		tmp_converted.warnings_fan = (uint8_t)r_warnings_fan;
		tmp_converted.warnings_pump = (uint8_t)r_warnings_pump;
		tmp_converted.warnings_adc_init = (uint8_t)r_warnings_adc_init;
		tmp_converted.warnings_mux = (uint8_t)r_warnings_mux;
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

		primary_lv_errors_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_LV_ERRORS_BYTE_SIZE;
		return primary_lv_errors_pack(data, &tmp, PRIMARY_LV_ERRORS_BYTE_SIZE);
	}
	case 291:
	{
		primary_lv_health_signals_t tmp;
		primary_lv_health_signals_converted_t tmp_converted;
		uint8_t r_health_signals_lvms_out;
		uint8_t r_health_signals_relay_out;
		uint8_t r_health_signals_battery_voltage_out;
		uint8_t r_health_signals_charger_current;
		uint8_t r_health_signals_battery_current;
		uint8_t r_health_signals_sign_battery_current;
		uint8_t r_health_code;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  
			"%" SCNu8 ","  ,
			&r_health_signals_lvms_out,
			&r_health_signals_relay_out,
			&r_health_signals_battery_voltage_out,
			&r_health_signals_charger_current,
			&r_health_signals_battery_current,
			&r_health_signals_sign_battery_current,
			&r_health_code);
		tmp_converted.health_signals_lvms_out = (uint8_t)r_health_signals_lvms_out;
		tmp_converted.health_signals_relay_out = (uint8_t)r_health_signals_relay_out;
		tmp_converted.health_signals_battery_voltage_out = (uint8_t)r_health_signals_battery_voltage_out;
		tmp_converted.health_signals_charger_current = (uint8_t)r_health_signals_charger_current;
		tmp_converted.health_signals_battery_current = (uint8_t)r_health_signals_battery_current;
		tmp_converted.health_signals_sign_battery_current = (uint8_t)r_health_signals_sign_battery_current;
		tmp_converted.health_code = (uint8_t)r_health_code;

		primary_lv_health_signals_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_LV_HEALTH_SIGNALS_BYTE_SIZE;
		return primary_lv_health_signals_pack(data, &tmp, PRIMARY_LV_HEALTH_SIGNALS_BYTE_SIZE);
	}
	case 323:
	{
		primary_lv_feedbacks_t tmp;
		primary_lv_feedbacks_converted_t tmp_converted;
		uint8_t r_feedbacks_bspd_fb;
		uint8_t r_feedbacks_hvd_fb;
		uint8_t r_feedbacks_lvms_fb;
		uint8_t r_feedbacks_res_fb;
		uint8_t r_feedbacks_lv_encl;
		uint8_t r_feedbacks_invc_lid_fb;
		uint8_t r_feedbacks_hv_encl_2_fb;
		uint8_t r_feedbacks_back_plate_fb;
		uint8_t r_feedbacks_invc_interlock_fb;
		uint8_t r_feedbacks_ams_fb;
		uint8_t r_feedbacks_asms_fb;
		uint8_t r_feedbacks_interlock_fb;
		uint8_t r_feedbacks_inverters_fb;
		uint8_t r_feedbacks_pcbs_fb;
		uint8_t r_feedbacks_pumps_fb;
		uint8_t r_feedbacks_shutdown_fb;
		uint8_t r_feedbacks_radiators_fb;
		uint8_t r_feedbacks_fan_fb;
		uint8_t r_feedbacks_as_actuation_fb;
		float r_sd_start;
		float r_sd_end;

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
			"%f,"       
			"%f,"       ,
			&r_feedbacks_bspd_fb,
			&r_feedbacks_hvd_fb,
			&r_feedbacks_lvms_fb,
			&r_feedbacks_res_fb,
			&r_feedbacks_lv_encl,
			&r_feedbacks_invc_lid_fb,
			&r_feedbacks_hv_encl_2_fb,
			&r_feedbacks_back_plate_fb,
			&r_feedbacks_invc_interlock_fb,
			&r_feedbacks_ams_fb,
			&r_feedbacks_asms_fb,
			&r_feedbacks_interlock_fb,
			&r_feedbacks_inverters_fb,
			&r_feedbacks_pcbs_fb,
			&r_feedbacks_pumps_fb,
			&r_feedbacks_shutdown_fb,
			&r_feedbacks_radiators_fb,
			&r_feedbacks_fan_fb,
			&r_feedbacks_as_actuation_fb,
			&r_sd_start,
			&r_sd_end);
		tmp_converted.feedbacks_bspd_fb = (uint8_t)r_feedbacks_bspd_fb;
		tmp_converted.feedbacks_hvd_fb = (uint8_t)r_feedbacks_hvd_fb;
		tmp_converted.feedbacks_lvms_fb = (uint8_t)r_feedbacks_lvms_fb;
		tmp_converted.feedbacks_res_fb = (uint8_t)r_feedbacks_res_fb;
		tmp_converted.feedbacks_lv_encl = (uint8_t)r_feedbacks_lv_encl;
		tmp_converted.feedbacks_invc_lid_fb = (uint8_t)r_feedbacks_invc_lid_fb;
		tmp_converted.feedbacks_hv_encl_2_fb = (uint8_t)r_feedbacks_hv_encl_2_fb;
		tmp_converted.feedbacks_back_plate_fb = (uint8_t)r_feedbacks_back_plate_fb;
		tmp_converted.feedbacks_invc_interlock_fb = (uint8_t)r_feedbacks_invc_interlock_fb;
		tmp_converted.feedbacks_ams_fb = (uint8_t)r_feedbacks_ams_fb;
		tmp_converted.feedbacks_asms_fb = (uint8_t)r_feedbacks_asms_fb;
		tmp_converted.feedbacks_interlock_fb = (uint8_t)r_feedbacks_interlock_fb;
		tmp_converted.feedbacks_inverters_fb = (uint8_t)r_feedbacks_inverters_fb;
		tmp_converted.feedbacks_pcbs_fb = (uint8_t)r_feedbacks_pcbs_fb;
		tmp_converted.feedbacks_pumps_fb = (uint8_t)r_feedbacks_pumps_fb;
		tmp_converted.feedbacks_shutdown_fb = (uint8_t)r_feedbacks_shutdown_fb;
		tmp_converted.feedbacks_radiators_fb = (uint8_t)r_feedbacks_radiators_fb;
		tmp_converted.feedbacks_fan_fb = (uint8_t)r_feedbacks_fan_fb;
		tmp_converted.feedbacks_as_actuation_fb = (uint8_t)r_feedbacks_as_actuation_fb;
		tmp_converted.sd_start = (float)r_sd_start;
		tmp_converted.sd_end = (float)r_sd_end;

		primary_lv_feedbacks_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_LV_FEEDBACKS_BYTE_SIZE;
		return primary_lv_feedbacks_pack(data, &tmp, PRIMARY_LV_FEEDBACKS_BYTE_SIZE);
	}
	case 355:
	{
		primary_shutdown_status_t tmp;
		primary_shutdown_status_converted_t tmp_converted;
		uint8_t r_input;
		uint8_t r_output;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  ,
			&r_input,
			&r_output);
		tmp_converted.input = (uint8_t)r_input;
		tmp_converted.output = (uint8_t)r_output;

		primary_shutdown_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_SHUTDOWN_STATUS_BYTE_SIZE;
		return primary_shutdown_status_pack(data, &tmp, PRIMARY_SHUTDOWN_STATUS_BYTE_SIZE);
	}
	case 1865:
	{
		primary_lv_can_flash_ack_t tmp;
		primary_lv_can_flash_ack_converted_t tmp_converted;
		uint8_t r_response;

		sscanf(s, "%" SCNu8 ","  ,
			&r_response);
		tmp_converted.response = (primary_lv_can_flash_ack_response)r_response;

		primary_lv_can_flash_ack_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_LV_CAN_FLASH_ACK_BYTE_SIZE;
		return primary_lv_can_flash_ack_pack(data, &tmp, PRIMARY_LV_CAN_FLASH_ACK_BYTE_SIZE);
	}
	case 517:
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
	case 549:
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
	case 581:
	{
		primary_hv_cell_balancing_status_t tmp;
		primary_hv_cell_balancing_status_converted_t tmp_converted;
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
		tmp_converted.cellboard_id = (primary_hv_cell_balancing_status_cellboard_id)r_cellboard_id;
		tmp_converted.balancing_status = (primary_hv_cell_balancing_status_balancing_status)r_balancing_status;
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

		primary_hv_cell_balancing_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_HV_CELL_BALANCING_STATUS_BYTE_SIZE;
		return primary_hv_cell_balancing_status_pack(data, &tmp, PRIMARY_HV_CELL_BALANCING_STATUS_BYTE_SIZE);
	}
	case 512:
	{
		primary_set_cell_balancing_status_t tmp;
		primary_set_cell_balancing_status_converted_t tmp_converted;
		uint8_t r_set_balancing_status;
		uint8_t r_balancing_threshold;

		sscanf(s, "%" SCNu8 ","  
			"%" SCNu8 ","  ,
			&r_set_balancing_status,
			&r_balancing_threshold);
		tmp_converted.set_balancing_status = (primary_set_cell_balancing_status_set_balancing_status)r_set_balancing_status;
		tmp_converted.balancing_threshold = (uint8_t)r_balancing_threshold;

		primary_set_cell_balancing_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_SET_CELL_BALANCING_STATUS_BYTE_SIZE;
		return primary_set_cell_balancing_status_pack(data, &tmp, PRIMARY_SET_CELL_BALANCING_STATUS_BYTE_SIZE);
	}
	case 520:
	{
		primary_speed_t tmp;
		primary_speed_converted_t tmp_converted;
		float r_encoder_r;
		float r_encoder_l;
		float r_inverter_r;
		float r_inverter_l;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_encoder_r,
			&r_encoder_l,
			&r_inverter_r,
			&r_inverter_l);
		tmp_converted.encoder_r = (float)r_encoder_r;
		tmp_converted.encoder_l = (float)r_encoder_l;
		tmp_converted.inverter_r = (float)r_inverter_r;
		tmp_converted.inverter_l = (float)r_inverter_l;

		primary_speed_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_SPEED_BYTE_SIZE;
		return primary_speed_pack(data, &tmp, PRIMARY_SPEED_BYTE_SIZE);
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
	case 296:
	{
		primary_control_output_t tmp;
		primary_control_output_converted_t tmp_converted;
		float r_estimated_velocity;
		float r_tmax_r;
		float r_tmax_l;
		float r_torque_l;
		float r_torque_r;

		sscanf(s, "%f,"       
			"%f,"       
			"%f,"       
			"%f,"       
			"%f,"       ,
			&r_estimated_velocity,
			&r_tmax_r,
			&r_tmax_l,
			&r_torque_l,
			&r_torque_r);
		tmp_converted.estimated_velocity = (float)r_estimated_velocity;
		tmp_converted.tmax_r = (float)r_tmax_r;
		tmp_converted.tmax_l = (float)r_tmax_l;
		tmp_converted.torque_l = (float)r_torque_l;
		tmp_converted.torque_r = (float)r_torque_r;

		primary_control_output_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_CONTROL_OUTPUT_BYTE_SIZE;
		return primary_control_output_pack(data, &tmp, PRIMARY_CONTROL_OUTPUT_BYTE_SIZE);
	}
	case 768:
	{
		primary_handcart_status_t tmp;
		primary_handcart_status_converted_t tmp_converted;
		uint8_t r_connected;

		sscanf(s, "%" SCNu8 ","  ,
			&r_connected);
		tmp_converted.connected = (uint8_t)r_connected;

		primary_handcart_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_HANDCART_STATUS_BYTE_SIZE;
		return primary_handcart_status_pack(data, &tmp, PRIMARY_HANDCART_STATUS_BYTE_SIZE);
	}
	case 800:
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
	case 832:
	{
		primary_handcart_settings_set_t tmp;
		primary_handcart_settings_set_converted_t tmp_converted;
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
		tmp_converted.fans_override = (primary_handcart_settings_set_fans_override)r_fans_override;
		tmp_converted.fans_speed = (float)r_fans_speed;
		tmp_converted.acc_charge_current = (float)r_acc_charge_current;
		tmp_converted.grid_max_current = (float)r_grid_max_current;
		tmp_converted.status = (primary_handcart_settings_set_status)r_status;

		primary_handcart_settings_set_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_HANDCART_SETTINGS_SET_BYTE_SIZE;
		return primary_handcart_settings_set_pack(data, &tmp, PRIMARY_HANDCART_SETTINGS_SET_BYTE_SIZE);
	}
	case 547:
	{
		primary_set_ptt_status_t tmp;
		primary_set_ptt_status_converted_t tmp_converted;
		uint8_t r_status;

		sscanf(s, "%" SCNu8 ","  ,
			&r_status);
		tmp_converted.status = (primary_set_ptt_status_status)r_status;

		primary_set_ptt_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_SET_PTT_STATUS_BYTE_SIZE;
		return primary_set_ptt_status_pack(data, &tmp, PRIMARY_SET_PTT_STATUS_BYTE_SIZE);
	}
	case 579:
	{
		primary_ptt_status_t tmp;
		primary_ptt_status_converted_t tmp_converted;
		uint8_t r_status;

		sscanf(s, "%" SCNu8 ","  ,
			&r_status);
		tmp_converted.status = (primary_ptt_status_status)r_status;

		primary_ptt_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_PTT_STATUS_BYTE_SIZE;
		return primary_ptt_status_pack(data, &tmp, PRIMARY_PTT_STATUS_BYTE_SIZE);
	}
	case 1027:
	{
		primary_regen_manual_command_t tmp;
		primary_regen_manual_command_converted_t tmp_converted;
		uint8_t r_status;
		float r_target;

		sscanf(s, "%" SCNu8 ","  
			"%f,"       ,
			&r_status,
			&r_target);
		tmp_converted.status = (primary_regen_manual_command_status)r_status;
		tmp_converted.target = (float)r_target;

		primary_regen_manual_command_conversion_to_raw_struct(&tmp, &tmp_converted);
		*size = PRIMARY_REGEN_MANUAL_COMMAND_BYTE_SIZE;
		return primary_regen_manual_command_pack(data, &tmp, PRIMARY_REGEN_MANUAL_COMMAND_BYTE_SIZE);
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
		case 3: return 1;
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
		case 702: return 2;
		case 703: return 2;
		case 704: return 2;
		case 705: return 3;
		case 257: return 1;
		case 1072: return 2;
		case 265: return 1;
		case 264: return 1;
		case 1801: return 1;
		case 772: return 2;
		case 804: return 4;
		case 836: return 4;
		case 868: return 3;
		case 36: return 32;
		case 32: return 2;
		case 37: return 1;
		case 773: return 2;
		case 771: return 20;
		case 516: return 7;
		case 548: return 8;
		case 580: return 5;
		case 803: return 6;
		case 84: return 1;
		case 82: return 1;
		case 83: return 1;
		case 258: return 3;
		case 80: return 1;
		case 1026: return 2;
		case 1032: return 2;
		case 81: return 3;
		case 40: return 9;
		case 777: return 8;
		case 809: return 1;
		case 835: return 3;
		case 867: return 4;
		case 899: return 1;
		case 931: return 4;
		case 963: return 2;
		case 775: return 1;
		case 807: return 1;
		case 263: return 1;
		case 259: return 1;
		case 515: return 34;
		case 291: return 7;
		case 323: return 21;
		case 355: return 2;
		case 1833: return 0;
		case 1865: return 1;
		case 41: return 0;
		case 517: return 4;
		case 549: return 5;
		case 581: return 29;
		case 512: return 2;
		case 520: return 4;
		case 513: return 8;
		case 514: return 8;
		case 385: return 8;
		case 386: return 8;
		case 296: return 5;
		case 518: return 0;
		case 768: return 1;
		case 800: return 6;
		case 832: return 6;
		case 547: return 1;
		case 579: return 1;
		case 1027: return 2;
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
	case 3:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_hv_can_forward_can_forward_set;
		return 1;
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
	case 702:
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
	case 705:
		if(fields_types_size < 3) return 0;
		fields_types[0] = e_primary_cellboard_version_cellboard_id;
		fields_types[1] = e_primary_uint16_t;
		fields_types[2] = e_primary_uint32_t;
		return 3;
	case 257:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_int16_t;
		return 1;
	case 1072:
		if(fields_types_size < 2) return 0;
		fields_types[0] = e_primary_uint32_t;
		fields_types[1] = e_primary_uint32_t;
		return 2;
	case 265:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_set_tlm_status_tlm_status;
		return 1;
	case 264:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_tlm_status_tlm_status;
		return 1;
	case 1801:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_uint8_t;
		return 1;
	case 772:
		if(fields_types_size < 2) return 0;
		fields_types[0] = e_primary_float;
		fields_types[1] = e_primary_float;
		return 2;
	case 804:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_primary_float;
		fields_types[1] = e_primary_float;
		fields_types[2] = e_primary_float;
		fields_types[3] = e_primary_float;
		return 4;
	case 836:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_primary_float;
		fields_types[1] = e_primary_float;
		fields_types[2] = e_primary_float;
		fields_types[3] = e_primary_float;
		return 4;
	case 868:
		if(fields_types_size < 3) return 0;
		fields_types[0] = e_primary_float;
		fields_types[1] = e_primary_float;
		fields_types[2] = e_primary_float;
		return 3;
	case 36:
		if(fields_types_size < 32) return 0;
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
		return 32;
	case 32:
		if(fields_types_size < 2) return 0;
		fields_types[0] = e_primary_hv_fans_override_fans_override;
		fields_types[1] = e_primary_float;
		return 2;
	case 37:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_hv_can_forward_status_can_forward_status;
		return 1;
	case 773:
		if(fields_types_size < 2) return 0;
		fields_types[0] = e_primary_hv_fans_override_status_fans_override;
		fields_types[1] = e_primary_float;
		return 2;
	case 771:
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
	case 516:
		if(fields_types_size < 7) return 0;
		fields_types[0] = e_primary_float;
		fields_types[1] = e_primary_float;
		fields_types[2] = e_primary_float;
		fields_types[3] = e_primary_float;
		fields_types[4] = e_primary_float;
		fields_types[5] = e_primary_float;
		fields_types[6] = e_primary_float;
		return 7;
	case 548:
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
	case 580:
		if(fields_types_size < 5) return 0;
		fields_types[0] = e_primary_float;
		fields_types[1] = e_primary_float;
		fields_types[2] = e_primary_float;
		fields_types[3] = e_primary_float;
		fields_types[4] = e_primary_float;
		return 5;
	case 803:
		if(fields_types_size < 6) return 0;
		fields_types[0] = e_primary_uint8_t;
		fields_types[1] = e_primary_hv_imd_status_imd_status;
		fields_types[2] = e_primary_uint16_t;
		fields_types[3] = e_primary_uint8_t;
		fields_types[4] = e_primary_uint8_t;
		fields_types[5] = e_primary_uint8_t;
		return 6;
	case 84:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_ts_status_ts_status;
		return 1;
	case 82:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_set_ts_status_das_ts_status_set;
		return 1;
	case 83:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_set_ts_status_handcart_ts_status_set;
		return 1;
	case 258:
		if(fields_types_size < 3) return 0;
		fields_types[0] = e_primary_float;
		fields_types[1] = e_primary_float;
		fields_types[2] = e_primary_float;
		return 3;
	case 80:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_set_car_status_car_status_set;
		return 1;
	case 1026:
		if(fields_types_size < 2) return 0;
		fields_types[0] = e_primary_set_pedal_calibration_pedal;
		fields_types[1] = e_primary_set_pedal_calibration_bound;
		return 2;
	case 1032:
		if(fields_types_size < 2) return 0;
		fields_types[0] = e_primary_pedal_calibration_ack_pedal;
		fields_types[1] = e_primary_pedal_calibration_ack_bound;
		return 2;
	case 81:
		if(fields_types_size < 3) return 0;
		fields_types[0] = e_primary_car_status_inverter_l;
		fields_types[1] = e_primary_car_status_inverter_r;
		fields_types[2] = e_primary_car_status_car_status;
		return 3;
	case 40:
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
	case 777:
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
	case 809:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_lv_status_status;
		return 1;
	case 835:
		if(fields_types_size < 3) return 0;
		fields_types[0] = e_primary_float;
		fields_types[1] = e_primary_float;
		fields_types[2] = e_primary_float;
		return 3;
	case 867:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_primary_uint8_t;
		fields_types[1] = e_primary_float;
		fields_types[2] = e_primary_float;
		fields_types[3] = e_primary_float;
		return 4;
	case 899:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_float;
		return 1;
	case 931:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_primary_uint8_t;
		fields_types[1] = e_primary_float;
		fields_types[2] = e_primary_float;
		fields_types[3] = e_primary_float;
		return 4;
	case 963:
		if(fields_types_size < 2) return 0;
		fields_types[0] = e_primary_float;
		fields_types[1] = e_primary_float;
		return 2;
	case 775:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_float;
		return 1;
	case 807:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_float;
		return 1;
	case 263:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_set_inverter_connection_status_status;
		return 1;
	case 259:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_inverter_connection_status_status;
		return 1;
	case 515:
		if(fields_types_size < 34) return 0;
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
		return 34;
	case 291:
		if(fields_types_size < 7) return 0;
		fields_types[0] = e_primary_uint8_t;
		fields_types[1] = e_primary_uint8_t;
		fields_types[2] = e_primary_uint8_t;
		fields_types[3] = e_primary_uint8_t;
		fields_types[4] = e_primary_uint8_t;
		fields_types[5] = e_primary_uint8_t;
		fields_types[6] = e_primary_uint8_t;
		return 7;
	case 323:
		if(fields_types_size < 21) return 0;
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
		fields_types[19] = e_primary_float;
		fields_types[20] = e_primary_float;
		return 21;
	case 355:
		if(fields_types_size < 2) return 0;
		fields_types[0] = e_primary_uint8_t;
		fields_types[1] = e_primary_uint8_t;
		return 2;
	case 1865:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_lv_can_flash_ack_response;
		return 1;
	case 517:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_primary_uint8_t;
		fields_types[1] = e_primary_float;
		fields_types[2] = e_primary_float;
		fields_types[3] = e_primary_float;
		return 4;
	case 549:
		if(fields_types_size < 5) return 0;
		fields_types[0] = e_primary_uint8_t;
		fields_types[1] = e_primary_float;
		fields_types[2] = e_primary_float;
		fields_types[3] = e_primary_float;
		fields_types[4] = e_primary_float;
		return 5;
	case 581:
		if(fields_types_size < 29) return 0;
		fields_types[0] = e_primary_hv_cell_balancing_status_cellboard_id;
		fields_types[1] = e_primary_hv_cell_balancing_status_balancing_status;
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
	case 512:
		if(fields_types_size < 2) return 0;
		fields_types[0] = e_primary_set_cell_balancing_status_set_balancing_status;
		fields_types[1] = e_primary_uint8_t;
		return 2;
	case 520:
		if(fields_types_size < 4) return 0;
		fields_types[0] = e_primary_float;
		fields_types[1] = e_primary_float;
		fields_types[2] = e_primary_float;
		fields_types[3] = e_primary_float;
		return 4;
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
	case 296:
		if(fields_types_size < 5) return 0;
		fields_types[0] = e_primary_float;
		fields_types[1] = e_primary_float;
		fields_types[2] = e_primary_float;
		fields_types[3] = e_primary_float;
		fields_types[4] = e_primary_float;
		return 5;
	case 768:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_uint8_t;
		return 1;
	case 800:
		if(fields_types_size < 6) return 0;
		fields_types[0] = e_primary_float;
		fields_types[1] = e_primary_handcart_settings_fans_override;
		fields_types[2] = e_primary_float;
		fields_types[3] = e_primary_float;
		fields_types[4] = e_primary_float;
		fields_types[5] = e_primary_handcart_settings_status;
		return 6;
	case 832:
		if(fields_types_size < 6) return 0;
		fields_types[0] = e_primary_float;
		fields_types[1] = e_primary_handcart_settings_set_fans_override;
		fields_types[2] = e_primary_float;
		fields_types[3] = e_primary_float;
		fields_types[4] = e_primary_float;
		fields_types[5] = e_primary_handcart_settings_set_status;
		return 6;
	case 547:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_set_ptt_status_status;
		return 1;
	case 579:
		if(fields_types_size < 1) return 0;
		fields_types[0] = e_primary_ptt_status_status;
		return 1;
	case 1027:
		if(fields_types_size < 2) return 0;
		fields_types[0] = e_primary_regen_manual_command_status;
		fields_types[1] = e_primary_float;
		return 2;

    }
    return 0;
}
