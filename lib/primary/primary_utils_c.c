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
int primary_serialize_from_id(int id, char *s, uint8_t *data, size_t size)
{
    switch(id)
    {
	case 1818:
	{
		primary_nlg5_diag_tx_t tmp;
		primary_nlg5_diag_tx_converted_t tmp_converted;
		sscanf(s, "%" PRIu64 
			"",
			tmp.lad_d_paramrp);
		primary_nlg5_diag_tx_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_nlg5_diag_tx_pack(data, &tmp, size);
	}
	case 1816:
	{
		primary_nlg5_diag_rx_t tmp;
		primary_nlg5_diag_rx_converted_t tmp_converted;
		sscanf(s, "%" PRIu64 
			"",
			tmp.lad_d_paramrq);
		primary_nlg5_diag_rx_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_nlg5_diag_rx_pack(data, &tmp, size);
	}
	case 1556:
	{
		primary_nlg5_err_t tmp;
		primary_nlg5_err_converted_t tmp_converted;
		sscanf(s, "%" PRIu8  
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
			tmp.nlg5_e_oov,
			tmp.nlg5_e_mov_ii,
			tmp.nlg5_e_mov_i,
			tmp.nlg5_e_sc,
			tmp.nlg5_e_p_om,
			tmp.nlg5_e_p_mv,
			tmp.nlg5_e_of,
			tmp.nlg5_e_mf,
			tmp.nlg5_e_b_p,
			tmp.nlg5_e_t_c,
			tmp.nlg5_e_t_pow,
			tmp.nlg5_e_t_dio,
			tmp.nlg5_e_t_tr,
			tmp.nlg5_e_t_ext1,
			tmp.nlg5_e_t_ext2,
			tmp.nlg5_e_t_ext3,
			tmp.nlg5_e_f_crc,
			tmp.nlg5_e_nv_crc,
			tmp.nlg5_e_es_crc,
			tmp.nlg5_e_ep_crc,
			tmp.nlg5_e_wdt,
			tmp.nlg5_e_init,
			tmp.nlg5_e_c_to,
			tmp.nlg5_e_c_off,
			tmp.nlg5_e_c_tx,
			tmp.nlg5_e_c_rx,
			tmp.nlg5_e_sdt_bt,
			tmp.nlg5_e_sdt_bv,
			tmp.nlg5_e_sdt_ah,
			tmp.nlg5_e_sdt_ct,
			tmp.nlg5_w_pl_mv,
			tmp.nlg5_w_pl_bv,
			tmp.nlg5_w_pl_it,
			tmp.nlg5_w_c_vor,
			tmp.nlg5_w_cm_na,
			tmp.nlg5_w_od,
			tmp.nlg5_w_sc_m);
		primary_nlg5_err_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_nlg5_err_pack(data, &tmp, size);
	}
	case 1555:
	{
		primary_nlg5_temp_t tmp;
		primary_nlg5_temp_converted_t tmp_converted;
		sscanf(s, """%f"
			"""%f"
			"""%f"
			"""%f"
			"",
			tmp.nlg5_p_tmp,
			tmp.nlg5_tmp_ext1,
			tmp.nlg5_temp_ext2,
			tmp.nlg5_tmp_ext3);
		primary_nlg5_temp_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_nlg5_temp_pack(data, &tmp, size);
	}
	case 1554:
	{
		primary_nlg5_act_ii_t tmp;
		primary_nlg5_act_ii_converted_t tmp_converted;
		sscanf(s, """%f"
			"""%f"
			"""%f"
			"""%f"
			"""%f"
			"",
			tmp.nlg5_s_mc_m_cp,
			tmp.nlg5_s_mc_m_pi,
			tmp.nlg5_abv,
			tmp.nlg5_ahc_ext,
			tmp.nlg5_oc_bo);
		primary_nlg5_act_ii_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_nlg5_act_ii_pack(data, &tmp, size);
	}
	case 1553:
	{
		primary_nlg5_act_i_t tmp;
		primary_nlg5_act_i_converted_t tmp_converted;
		sscanf(s, """%f"
			"""%f"
			"""%f"
			"""%f"
			"",
			tmp.nlg5_mc_act,
			tmp.nlg5_mv_act,
			tmp.nlg5_ov_act,
			tmp.nlg5_oc_act);
		primary_nlg5_act_i_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_nlg5_act_i_pack(data, &tmp, size);
	}
	case 1552:
	{
		primary_nlg5_st_t tmp;
		primary_nlg5_st_converted_t tmp_converted;
		sscanf(s, "%" PRIu8  
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
			tmp.nlg5_s_he,
			tmp.nlg5_s_err,
			tmp.nlg5_s_war,
			tmp.nlg5_s_fan,
			tmp.nlg5_s_eum,
			tmp.nlg5_s_um_i,
			tmp.nlg5_s_um_ii,
			tmp.nlg5_s_cp_dt,
			tmp.nlg5_s_bpd_i,
			tmp.nlg5_s_bpd_ii,
			tmp.nlg5_s_l_ov,
			tmp.nlg5_s_l_oc,
			tmp.nlg5_s_l_mc,
			tmp.nlg5_s_l_pi,
			tmp.nlg5_s_l_cp,
			tmp.nlg5_s_l_pmax,
			tmp.nlg5_s_l_mc_max,
			tmp.nlg5_s_l_oc_max,
			tmp.nlg5_s_l_mo_max,
			tmp.nlg5_s_l_t_cprim,
			tmp.nlg5_s_l_t_pow,
			tmp.nlg5_s_l_t_dio,
			tmp.nlg5_s_l_t_tr,
			tmp.nlg5_s_l_t_batt,
			tmp.nlg5_s_aac);
		primary_nlg5_st_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_nlg5_st_pack(data, &tmp, size);
	}
	case 1560:
	{
		primary_nlg5_ctl_t tmp;
		primary_nlg5_ctl_converted_t tmp_converted;
		sscanf(s, "%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"""%f"
			"""%f"
			"""%f"
			"",
			tmp.nlg5_c_c_en,
			tmp.nlg5_c_c_el,
			tmp.nlg5_c_cp_v,
			tmp.nlg5_c_mr,
			tmp.nlg5_mc_max,
			tmp.nlg5_ov_com,
			tmp.nlg5_oc_com);
		primary_nlg5_ctl_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_nlg5_ctl_pack(data, &tmp, size);
	}
	case 3:
	{
		primary_hv_can_forward_t tmp;
		primary_hv_can_forward_converted_t tmp_converted;
		sscanf(s, "%" PRIu8  
			"",
			tmp.can_forward_set);
		primary_hv_can_forward_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_hv_can_forward_pack(data, &tmp, size);
	}
	case 700:
	{
		primary_steer_version_t tmp;
		primary_steer_version_converted_t tmp_converted;
		sscanf(s, "%" PRIu32 
			"%" PRIu32 
			"",
			tmp.component_build_time,
			tmp.canlib_build_time);
		primary_steer_version_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_steer_version_pack(data, &tmp, size);
	}
	case 701:
	{
		primary_das_version_t tmp;
		primary_das_version_converted_t tmp_converted;
		sscanf(s, "%" PRIu32 
			"%" PRIu32 
			"",
			tmp.component_build_time,
			tmp.canlib_build_time);
		primary_das_version_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_das_version_pack(data, &tmp, size);
	}
	case 702:
	{
		primary_mainboard_version_t tmp;
		primary_mainboard_version_converted_t tmp_converted;
		sscanf(s, "%" PRIu32 
			"%" PRIu32 
			"",
			tmp.component_build_time,
			tmp.canlib_build_time);
		primary_mainboard_version_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_mainboard_version_pack(data, &tmp, size);
	}
	case 703:
	{
		primary_lv_version_t tmp;
		primary_lv_version_converted_t tmp_converted;
		sscanf(s, "%" PRIu32 
			"%" PRIu32 
			"",
			tmp.component_build_time,
			tmp.canlib_build_time);
		primary_lv_version_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_lv_version_pack(data, &tmp, size);
	}
	case 704:
	{
		primary_tlm_version_t tmp;
		primary_tlm_version_converted_t tmp_converted;
		sscanf(s, "%" PRIu32 
			"%" PRIu32 
			"",
			tmp.component_build_time,
			tmp.canlib_build_time);
		primary_tlm_version_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_tlm_version_pack(data, &tmp, size);
	}
	case 705:
	{
		primary_cellboard_version_t tmp;
		primary_cellboard_version_converted_t tmp_converted;
		sscanf(s, "%" PRIu8  
			"%" PRIu16 
			"%" PRIu32 
			"",
			tmp.cellboard_id,
			tmp.component_version,
			tmp.canlib_build_time);
		primary_cellboard_version_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_cellboard_version_pack(data, &tmp, size);
	}
	case 257:
	{
		primary_ambient_temperature_t tmp;
		primary_ambient_temperature_converted_t tmp_converted;
		sscanf(s, "%" PRIi16 
			"",
			tmp.temp);
		primary_ambient_temperature_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_ambient_temperature_pack(data, &tmp, size);
	}
	case 1072:
	{
		primary_data_logger_t tmp;
		primary_data_logger_converted_t tmp_converted;
		sscanf(s, "%" PRIu32 
			"%" PRIu32 
			"",
			tmp.placeholder1,
			tmp.placeholder2);
		primary_data_logger_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_data_logger_pack(data, &tmp, size);
	}
	case 265:
	{
		primary_set_tlm_status_t tmp;
		primary_set_tlm_status_converted_t tmp_converted;
		sscanf(s, "%" PRIu8  
			"",
			tmp.tlm_status);
		primary_set_tlm_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_set_tlm_status_pack(data, &tmp, size);
	}
	case 264:
	{
		primary_tlm_status_t tmp;
		primary_tlm_status_converted_t tmp_converted;
		sscanf(s, "%" PRIu8  
			"",
			tmp.tlm_status);
		primary_tlm_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_tlm_status_pack(data, &tmp, size);
	}
	case 1801:
	{
		primary_steer_system_status_t tmp;
		primary_steer_system_status_converted_t tmp_converted;
		sscanf(s, "%" PRIu8  
			"",
			tmp.soc_temp);
		primary_steer_system_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_steer_system_status_pack(data, &tmp, size);
	}
	case 772:
	{
		primary_hv_voltage_t tmp;
		primary_hv_voltage_converted_t tmp_converted;
		sscanf(s, """%f"
			"""%f"
			"",
			tmp.pack_voltage,
			tmp.bus_voltage);
		primary_hv_voltage_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_hv_voltage_pack(data, &tmp, size);
	}
	case 804:
	{
		primary_hv_cell_voltage_t tmp;
		primary_hv_cell_voltage_converted_t tmp_converted;
		sscanf(s, """%f"
			"""%f"
			"""%f"
			"""%f"
			"",
			tmp.max_cell_voltage,
			tmp.min_cell_voltage,
			tmp.sum_cell_voltage,
			tmp.avg_cell_voltage);
		primary_hv_cell_voltage_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_hv_cell_voltage_pack(data, &tmp, size);
	}
	case 836:
	{
		primary_hv_current_t tmp;
		primary_hv_current_converted_t tmp_converted;
		sscanf(s, """%f"
			"""%f"
			"""%f"
			"""%f"
			"",
			tmp.current,
			tmp.power,
			tmp.energy,
			tmp.soc);
		primary_hv_current_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_hv_current_pack(data, &tmp, size);
	}
	case 868:
	{
		primary_hv_temp_t tmp;
		primary_hv_temp_converted_t tmp_converted;
		sscanf(s, """%f"
			"""%f"
			"""%f"
			"",
			tmp.average_temp,
			tmp.max_temp,
			tmp.min_temp);
		primary_hv_temp_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_hv_temp_pack(data, &tmp, size);
	}
	case 36:
	{
		primary_hv_errors_t tmp;
		primary_hv_errors_converted_t tmp_converted;
		sscanf(s, "%" PRIu8  
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
			tmp.warnings_cell_low_voltage,
			tmp.warnings_cell_under_voltage,
			tmp.warnings_cell_over_voltage,
			tmp.warnings_cell_high_temperature,
			tmp.warnings_cell_over_temperature,
			tmp.warnings_over_current,
			tmp.warnings_can,
			tmp.warnings_int_voltage_mismatch,
			tmp.warnings_cellboard_comm,
			tmp.warnings_cellboard_internal,
			tmp.warnings_connector_disconnected,
			tmp.warnings_fans_disconnected,
			tmp.warnings_feedback,
			tmp.warnings_feedback_circuitry,
			tmp.warnings_eeprom_comm,
			tmp.warnings_eeprom_write,
			tmp.errors_cell_low_voltage,
			tmp.errors_cell_under_voltage,
			tmp.errors_cell_over_voltage,
			tmp.errors_cell_high_temperature,
			tmp.errors_cell_over_temperature,
			tmp.errors_over_current,
			tmp.errors_can,
			tmp.errors_int_voltage_mismatch,
			tmp.errors_cellboard_comm,
			tmp.errors_cellboard_internal,
			tmp.errors_connector_disconnected,
			tmp.errors_fans_disconnected,
			tmp.errors_feedback,
			tmp.errors_feedback_circuitry,
			tmp.errors_eeprom_comm,
			tmp.errors_eeprom_write);
		primary_hv_errors_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_hv_errors_pack(data, &tmp, size);
	}
	case 32:
	{
		primary_hv_fans_override_t tmp;
		primary_hv_fans_override_converted_t tmp_converted;
		sscanf(s, "%" PRIu8  
			"""%f"
			"",
			tmp.fans_override,
			tmp.fans_speed);
		primary_hv_fans_override_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_hv_fans_override_pack(data, &tmp, size);
	}
	case 37:
	{
		primary_hv_can_forward_status_t tmp;
		primary_hv_can_forward_status_converted_t tmp_converted;
		sscanf(s, "%" PRIu8  
			"",
			tmp.can_forward_status);
		primary_hv_can_forward_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_hv_can_forward_status_pack(data, &tmp, size);
	}
	case 773:
	{
		primary_hv_fans_override_status_t tmp;
		primary_hv_fans_override_status_converted_t tmp_converted;
		sscanf(s, "%" PRIu8  
			"""%f"
			"",
			tmp.fans_override,
			tmp.fans_speed);
		primary_hv_fans_override_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_hv_fans_override_status_pack(data, &tmp, size);
	}
	case 771:
	{
		primary_hv_feedback_status_t tmp;
		primary_hv_feedback_status_converted_t tmp_converted;
		sscanf(s, "%" PRIu8  
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
			tmp.feedback_implausibility_detected,
			tmp.feedback_imd_cockpit,
			tmp.feedback_tsal_green_fault_latched,
			tmp.feedback_bms_cockpit,
			tmp.feedback_ext_latched,
			tmp.feedback_tsal_green,
			tmp.feedback_ts_over_60v_status,
			tmp.feedback_airn_status,
			tmp.feedback_airp_status,
			tmp.feedback_airp_gate,
			tmp.feedback_airn_gate,
			tmp.feedback_precharge_status,
			tmp.feedback_tsp_over_60v_status,
			tmp.feedback_imd_fault,
			tmp.feedback_check_mux,
			tmp.feedback_sd_end,
			tmp.feedback_sd_out,
			tmp.feedback_sd_in,
			tmp.feedback_sd_bms,
			tmp.feedback_sd_imd);
		primary_hv_feedback_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_hv_feedback_status_pack(data, &tmp, size);
	}
	case 516:
	{
		primary_hv_feedback_ts_voltage_t tmp;
		primary_hv_feedback_ts_voltage_converted_t tmp_converted;
		sscanf(s, """%f"
			"""%f"
			"""%f"
			"""%f"
			"""%f"
			"""%f"
			"""%f"
			"",
			tmp.feedback_ts_over_60v_status,
			tmp.feedback_airn_status,
			tmp.feedback_airp_status,
			tmp.feedback_airp_gate,
			tmp.feedback_airn_gate,
			tmp.feedback_precharge_status,
			tmp.feedback_tsp_over_60v_status);
		primary_hv_feedback_ts_voltage_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_hv_feedback_ts_voltage_pack(data, &tmp, size);
	}
	case 548:
	{
		primary_hv_feedback_misc_voltage_t tmp;
		primary_hv_feedback_misc_voltage_converted_t tmp_converted;
		sscanf(s, """%f"
			"""%f"
			"""%f"
			"""%f"
			"""%f"
			"""%f"
			"""%f"
			"""%f"
			"",
			tmp.feedback_implausibility_detected,
			tmp.feedback_imd_cockpit,
			tmp.feedback_tsal_green_fault_latched,
			tmp.feedback_bms_cockpit,
			tmp.feedback_ext_latched,
			tmp.feedback_tsal_green,
			tmp.imd_fault,
			tmp.feedback_check_mux);
		primary_hv_feedback_misc_voltage_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_hv_feedback_misc_voltage_pack(data, &tmp, size);
	}
	case 580:
	{
		primary_hv_feedback_sd_voltage_t tmp;
		primary_hv_feedback_sd_voltage_converted_t tmp_converted;
		sscanf(s, """%f"
			"""%f"
			"""%f"
			"""%f"
			"""%f"
			"",
			tmp.feedback_sd_end,
			tmp.feedback_sd_out,
			tmp.feedback_sd_in,
			tmp.feedback_sd_bms,
			tmp.feedback_sd_imd);
		primary_hv_feedback_sd_voltage_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_hv_feedback_sd_voltage_pack(data, &tmp, size);
	}
	case 803:
	{
		primary_hv_imd_status_t tmp;
		primary_hv_imd_status_converted_t tmp_converted;
		sscanf(s, "%" PRIu8  
			"%" PRIu8  
			"%" PRIu16 
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"",
			tmp.imd_fault,
			tmp.imd_status,
			tmp.imd_details,
			tmp.imd_duty_cycle,
			tmp.imd_freq,
			tmp.imd_period);
		primary_hv_imd_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_hv_imd_status_pack(data, &tmp, size);
	}
	case 84:
	{
		primary_ts_status_t tmp;
		primary_ts_status_converted_t tmp_converted;
		sscanf(s, "%" PRIu8  
			"",
			tmp.ts_status);
		primary_ts_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_ts_status_pack(data, &tmp, size);
	}
	case 82:
	{
		primary_set_ts_status_das_t tmp;
		primary_set_ts_status_das_converted_t tmp_converted;
		sscanf(s, "%" PRIu8  
			"",
			tmp.ts_status_set);
		primary_set_ts_status_das_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_set_ts_status_das_pack(data, &tmp, size);
	}
	case 83:
	{
		primary_set_ts_status_handcart_t tmp;
		primary_set_ts_status_handcart_converted_t tmp_converted;
		sscanf(s, "%" PRIu8  
			"",
			tmp.ts_status_set);
		primary_set_ts_status_handcart_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_set_ts_status_handcart_pack(data, &tmp, size);
	}
	case 258:
	{
		primary_steer_status_t tmp;
		primary_steer_status_converted_t tmp_converted;
		sscanf(s, """%f"
			"""%f"
			"""%f"
			"",
			tmp.map_pw,
			tmp.map_sc,
			tmp.map_tv);
		primary_steer_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_steer_status_pack(data, &tmp, size);
	}
	case 80:
	{
		primary_set_car_status_t tmp;
		primary_set_car_status_converted_t tmp_converted;
		sscanf(s, "%" PRIu8  
			"",
			tmp.car_status_set);
		primary_set_car_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_set_car_status_pack(data, &tmp, size);
	}
	case 1026:
	{
		primary_set_pedal_calibration_t tmp;
		primary_set_pedal_calibration_converted_t tmp_converted;
		sscanf(s, "%" PRIu8  
			"%" PRIu8  
			"",
			tmp.pedal,
			tmp.bound);
		primary_set_pedal_calibration_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_set_pedal_calibration_pack(data, &tmp, size);
	}
	case 1032:
	{
		primary_pedal_calibration_ack_t tmp;
		primary_pedal_calibration_ack_converted_t tmp_converted;
		sscanf(s, "%" PRIu8  
			"%" PRIu8  
			"",
			tmp.pedal,
			tmp.bound);
		primary_pedal_calibration_ack_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_pedal_calibration_ack_pack(data, &tmp, size);
	}
	case 81:
	{
		primary_car_status_t tmp;
		primary_car_status_converted_t tmp_converted;
		sscanf(s, "%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"",
			tmp.inverter_l,
			tmp.inverter_r,
			tmp.car_status);
		primary_car_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_car_status_pack(data, &tmp, size);
	}
	case 40:
	{
		primary_das_errors_t tmp;
		primary_das_errors_converted_t tmp_converted;
		sscanf(s, "%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"",
			tmp.das_error_pedal_adc,
			tmp.das_error_pedal_implausibility,
			tmp.das_error_imu_tout,
			tmp.das_error_irts_tout,
			tmp.das_error_ts_tout,
			tmp.das_error_invl_tout,
			tmp.das_error_invr_tout,
			tmp.das_error_steer_tout,
			tmp.das_error_fsm);
		primary_das_errors_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_das_errors_pack(data, &tmp, size);
	}
	case 777:
	{
		primary_ecu_feedbacks_t tmp;
		primary_ecu_feedbacks_converted_t tmp_converted;
		sscanf(s, "%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"",
			tmp.ecu_feedbacks_sd_cock_fb,
			tmp.ecu_feedbacks_sd_fb1,
			tmp.ecu_feedbacks_sd_bots_fb,
			tmp.ecu_feedbacks_sd_interial_fb,
			tmp.ecu_feedbacks_sd_fb4,
			tmp.ecu_feedbacks_sd_in,
			tmp.ecu_feedbacks_sd_out,
			tmp.ecu_feedbacks_sd_ctrl_pin);
		primary_ecu_feedbacks_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_ecu_feedbacks_pack(data, &tmp, size);
	}
	case 809:
	{
		primary_lv_status_t tmp;
		primary_lv_status_converted_t tmp_converted;
		sscanf(s, "%" PRIu8  
			"",
			tmp.status);
		primary_lv_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_lv_status_pack(data, &tmp, size);
	}
	case 835:
	{
		primary_lv_currents_t tmp;
		primary_lv_currents_converted_t tmp_converted;
		sscanf(s, """%f"
			"""%f"
			"""%f"
			"",
			tmp.current_as_battery,
			tmp.current_lv_battery,
			tmp.current_charger);
		primary_lv_currents_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_lv_currents_pack(data, &tmp, size);
	}
	case 867:
	{
		primary_lv_cells_voltage_t tmp;
		primary_lv_cells_voltage_converted_t tmp_converted;
		sscanf(s, "%" PRIu8  
			"""%f"
			"""%f"
			"""%f"
			"",
			tmp.start_index,
			tmp.voltage_0,
			tmp.voltage_1,
			tmp.voltage_2);
		primary_lv_cells_voltage_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_lv_cells_voltage_pack(data, &tmp, size);
	}
	case 899:
	{
		primary_lv_total_voltage_t tmp;
		primary_lv_total_voltage_converted_t tmp_converted;
		sscanf(s, """%f"
			"",
			tmp.total_voltage);
		primary_lv_total_voltage_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_lv_total_voltage_pack(data, &tmp, size);
	}
	case 931:
	{
		primary_lv_cells_temp_t tmp;
		primary_lv_cells_temp_converted_t tmp_converted;
		sscanf(s, "%" PRIu8  
			"""%f"
			"""%f"
			"""%f"
			"",
			tmp.start_index,
			tmp.temp_0,
			tmp.temp_1,
			tmp.temp_2);
		primary_lv_cells_temp_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_lv_cells_temp_pack(data, &tmp, size);
	}
	case 963:
	{
		primary_cooling_status_t tmp;
		primary_cooling_status_converted_t tmp_converted;
		sscanf(s, """%f"
			"""%f"
			"",
			tmp.radiators_speed,
			tmp.pumps_speed);
		primary_cooling_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_cooling_status_pack(data, &tmp, size);
	}
	case 775:
	{
		primary_set_radiator_speed_t tmp;
		primary_set_radiator_speed_converted_t tmp_converted;
		sscanf(s, """%f"
			"",
			tmp.radiators_speed);
		primary_set_radiator_speed_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_set_radiator_speed_pack(data, &tmp, size);
	}
	case 807:
	{
		primary_set_pumps_speed_t tmp;
		primary_set_pumps_speed_converted_t tmp_converted;
		sscanf(s, """%f"
			"",
			tmp.pumps_speed);
		primary_set_pumps_speed_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_set_pumps_speed_pack(data, &tmp, size);
	}
	case 263:
	{
		primary_set_inverter_connection_status_t tmp;
		primary_set_inverter_connection_status_converted_t tmp_converted;
		sscanf(s, "%" PRIu8  
			"",
			tmp.status);
		primary_set_inverter_connection_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_set_inverter_connection_status_pack(data, &tmp, size);
	}
	case 259:
	{
		primary_inverter_connection_status_t tmp;
		primary_inverter_connection_status_converted_t tmp_converted;
		sscanf(s, "%" PRIu8  
			"",
			tmp.status);
		primary_inverter_connection_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_inverter_connection_status_pack(data, &tmp, size);
	}
	case 515:
	{
		primary_lv_errors_t tmp;
		primary_lv_errors_converted_t tmp_converted;
		sscanf(s, "%" PRIu8  
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
			tmp.warnings_cell_undervoltage,
			tmp.warnings_cell_overvoltage,
			tmp.warnings_battery_open_wire,
			tmp.warnings_can,
			tmp.warnings_spi,
			tmp.warnings_over_current,
			tmp.warnings_cell_under_temperature,
			tmp.warnings_cell_over_temperature,
			tmp.warnings_relay,
			tmp.warnings_bms_monitor,
			tmp.warnings_voltages_not_ready,
			tmp.warnings_mcp23017,
			tmp.warnings_radiator,
			tmp.warnings_fan,
			tmp.warnings_pump,
			tmp.warnings_adc_init,
			tmp.warnings_mux,
			tmp.errors_cell_undervoltage,
			tmp.errors_cell_overvoltage,
			tmp.errors_battery_open_wire,
			tmp.errors_can,
			tmp.errors_spi,
			tmp.errors_over_current,
			tmp.errors_cell_under_temperature,
			tmp.errors_cell_over_temperature,
			tmp.errors_relay,
			tmp.errors_bms_monitor,
			tmp.errors_voltages_not_ready,
			tmp.errors_mcp23017,
			tmp.errors_radiator,
			tmp.errors_fan,
			tmp.errors_pump,
			tmp.errors_adc_init,
			tmp.errors_mux);
		primary_lv_errors_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_lv_errors_pack(data, &tmp, size);
	}
	case 291:
	{
		primary_lv_health_signals_t tmp;
		primary_lv_health_signals_converted_t tmp_converted;
		sscanf(s, "%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"",
			tmp.health_signals_lvms_out,
			tmp.health_signals_relay_out,
			tmp.health_signals_battery_voltage_out,
			tmp.health_signals_charger_current,
			tmp.health_signals_battery_current,
			tmp.health_signals_sign_battery_current,
			tmp.health_code);
		primary_lv_health_signals_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_lv_health_signals_pack(data, &tmp, size);
	}
	case 323:
	{
		primary_lv_feedbacks_t tmp;
		primary_lv_feedbacks_converted_t tmp_converted;
		sscanf(s, "%" PRIu8  
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
			"""%f"
			"""%f"
			"",
			tmp.feedbacks_bspd_fb,
			tmp.feedbacks_hvd_fb,
			tmp.feedbacks_lvms_fb,
			tmp.feedbacks_res_fb,
			tmp.feedbacks_lv_encl,
			tmp.feedbacks_invc_lid_fb,
			tmp.feedbacks_hv_encl_2_fb,
			tmp.feedbacks_back_plate_fb,
			tmp.feedbacks_invc_interlock_fb,
			tmp.feedbacks_ams_fb,
			tmp.feedbacks_asms_fb,
			tmp.feedbacks_interlock_fb,
			tmp.feedbacks_inverters_fb,
			tmp.feedbacks_pcbs_fb,
			tmp.feedbacks_pumps_fb,
			tmp.feedbacks_shutdown_fb,
			tmp.feedbacks_radiators_fb,
			tmp.feedbacks_fan_fb,
			tmp.feedbacks_as_actuation_fb,
			tmp.sd_start,
			tmp.sd_end);
		primary_lv_feedbacks_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_lv_feedbacks_pack(data, &tmp, size);
	}
	case 355:
	{
		primary_shutdown_status_t tmp;
		primary_shutdown_status_converted_t tmp_converted;
		sscanf(s, "%" PRIu8  
			"%" PRIu8  
			"",
			tmp.input,
			tmp.output);
		primary_shutdown_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_shutdown_status_pack(data, &tmp, size);
	}
	case 1865:
	{
		primary_lv_can_flash_ack_t tmp;
		primary_lv_can_flash_ack_converted_t tmp_converted;
		sscanf(s, "%" PRIu8  
			"",
			tmp.response);
		primary_lv_can_flash_ack_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_lv_can_flash_ack_pack(data, &tmp, size);
	}
	case 517:
	{
		primary_hv_cells_voltage_t tmp;
		primary_hv_cells_voltage_converted_t tmp_converted;
		sscanf(s, "%" PRIu8  
			"""%f"
			"""%f"
			"""%f"
			"",
			tmp.start_index,
			tmp.voltage_0,
			tmp.voltage_1,
			tmp.voltage_2);
		primary_hv_cells_voltage_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_hv_cells_voltage_pack(data, &tmp, size);
	}
	case 549:
	{
		primary_hv_cells_temp_t tmp;
		primary_hv_cells_temp_converted_t tmp_converted;
		sscanf(s, "%" PRIu8  
			"""%f"
			"""%f"
			"""%f"
			"""%f"
			"",
			tmp.start_index,
			tmp.temp_0,
			tmp.temp_1,
			tmp.temp_2,
			tmp.temp_3);
		primary_hv_cells_temp_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_hv_cells_temp_pack(data, &tmp, size);
	}
	case 581:
	{
		primary_hv_cell_balancing_status_t tmp;
		primary_hv_cell_balancing_status_converted_t tmp_converted;
		sscanf(s, "%" PRIu8  
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
			tmp.cellboard_id,
			tmp.balancing_status,
			tmp.errors_can_comm,
			tmp.errors_ltc_comm,
			tmp.errors_temp_comm_0,
			tmp.errors_temp_comm_1,
			tmp.errors_temp_comm_2,
			tmp.errors_temp_comm_3,
			tmp.errors_temp_comm_4,
			tmp.errors_temp_comm_5,
			tmp.errors_open_wire,
			tmp.balancing_cells_cell0,
			tmp.balancing_cells_cell1,
			tmp.balancing_cells_cell2,
			tmp.balancing_cells_cell3,
			tmp.balancing_cells_cell4,
			tmp.balancing_cells_cell5,
			tmp.balancing_cells_cell6,
			tmp.balancing_cells_cell7,
			tmp.balancing_cells_cell8,
			tmp.balancing_cells_cell9,
			tmp.balancing_cells_cell10,
			tmp.balancing_cells_cell11,
			tmp.balancing_cells_cell12,
			tmp.balancing_cells_cell13,
			tmp.balancing_cells_cell14,
			tmp.balancing_cells_cell15,
			tmp.balancing_cells_cell16,
			tmp.balancing_cells_cell17);
		primary_hv_cell_balancing_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_hv_cell_balancing_status_pack(data, &tmp, size);
	}
	case 512:
	{
		primary_set_cell_balancing_status_t tmp;
		primary_set_cell_balancing_status_converted_t tmp_converted;
		sscanf(s, "%" PRIu8  
			"%" PRIu8  
			"",
			tmp.set_balancing_status,
			tmp.balancing_threshold);
		primary_set_cell_balancing_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_set_cell_balancing_status_pack(data, &tmp, size);
	}
	case 520:
	{
		primary_speed_t tmp;
		primary_speed_converted_t tmp_converted;
		sscanf(s, """%f"
			"""%f"
			"""%f"
			"""%f"
			"",
			tmp.encoder_r,
			tmp.encoder_l,
			tmp.inverter_r,
			tmp.inverter_l);
		primary_speed_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_speed_pack(data, &tmp, size);
	}
	case 513:
	{
		primary_inv_l_request_t tmp;
		primary_inv_l_request_converted_t tmp_converted;
		sscanf(s, "%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"",
			tmp.data_0,
			tmp.data_1,
			tmp.data_2,
			tmp.data_3,
			tmp.data_4,
			tmp.data_5,
			tmp.data_6,
			tmp.data_7);
		primary_inv_l_request_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_inv_l_request_pack(data, &tmp, size);
	}
	case 514:
	{
		primary_inv_r_request_t tmp;
		primary_inv_r_request_converted_t tmp_converted;
		sscanf(s, "%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"",
			tmp.data_0,
			tmp.data_1,
			tmp.data_2,
			tmp.data_3,
			tmp.data_4,
			tmp.data_5,
			tmp.data_6,
			tmp.data_7);
		primary_inv_r_request_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_inv_r_request_pack(data, &tmp, size);
	}
	case 385:
	{
		primary_inv_l_response_t tmp;
		primary_inv_l_response_converted_t tmp_converted;
		sscanf(s, "%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"",
			tmp.reg_id,
			tmp.data_0,
			tmp.data_1,
			tmp.data_2,
			tmp.data_3,
			tmp.data_4,
			tmp.data_5,
			tmp.data_6);
		primary_inv_l_response_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_inv_l_response_pack(data, &tmp, size);
	}
	case 386:
	{
		primary_inv_r_response_t tmp;
		primary_inv_r_response_converted_t tmp_converted;
		sscanf(s, "%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"%" PRIu8  
			"",
			tmp.reg_id,
			tmp.data_0,
			tmp.data_1,
			tmp.data_2,
			tmp.data_3,
			tmp.data_4,
			tmp.data_5,
			tmp.data_6);
		primary_inv_r_response_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_inv_r_response_pack(data, &tmp, size);
	}
	case 296:
	{
		primary_control_output_t tmp;
		primary_control_output_converted_t tmp_converted;
		sscanf(s, """%f"
			"""%f"
			"""%f"
			"""%f"
			"""%f"
			"",
			tmp.estimated_velocity,
			tmp.tmax_r,
			tmp.tmax_l,
			tmp.torque_l,
			tmp.torque_r);
		primary_control_output_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_control_output_pack(data, &tmp, size);
	}
	case 768:
	{
		primary_handcart_status_t tmp;
		primary_handcart_status_converted_t tmp_converted;
		sscanf(s, "%" PRIu8  
			"",
			tmp.connected);
		primary_handcart_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_handcart_status_pack(data, &tmp, size);
	}
	case 800:
	{
		primary_handcart_settings_t tmp;
		primary_handcart_settings_converted_t tmp_converted;
		sscanf(s, """%f"
			"%" PRIu8  
			"""%f"
			"""%f"
			"""%f"
			"%" PRIu8  
			"",
			tmp.target_voltage,
			tmp.fans_override,
			tmp.fans_speed,
			tmp.acc_charge_current,
			tmp.grid_max_current,
			tmp.status);
		primary_handcart_settings_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_handcart_settings_pack(data, &tmp, size);
	}
	case 832:
	{
		primary_handcart_settings_set_t tmp;
		primary_handcart_settings_set_converted_t tmp_converted;
		sscanf(s, """%f"
			"%" PRIu8  
			"""%f"
			"""%f"
			"""%f"
			"%" PRIu8  
			"",
			tmp.target_voltage,
			tmp.fans_override,
			tmp.fans_speed,
			tmp.acc_charge_current,
			tmp.grid_max_current,
			tmp.status);
		primary_handcart_settings_set_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_handcart_settings_set_pack(data, &tmp, size);
	}
	case 547:
	{
		primary_set_ptt_status_t tmp;
		primary_set_ptt_status_converted_t tmp_converted;
		sscanf(s, "%" PRIu8  
			"",
			tmp.status);
		primary_set_ptt_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_set_ptt_status_pack(data, &tmp, size);
	}
	case 579:
	{
		primary_ptt_status_t tmp;
		primary_ptt_status_converted_t tmp_converted;
		sscanf(s, "%" PRIu8  
			"",
			tmp.status);
		primary_ptt_status_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_ptt_status_pack(data, &tmp, size);
	}
	case 1027:
	{
		primary_regen_manual_command_t tmp;
		primary_regen_manual_command_converted_t tmp_converted;
		sscanf(s, "%" PRIu8  
			"""%f"
			"",
			tmp.status,
			tmp.target);
		primary_regen_manual_command_conversion_to_raw_struct(&tmp, &tmp_converted);
		return primary_regen_manual_command_pack(data, &tmp, size);
	}

    }
    return 0;
}