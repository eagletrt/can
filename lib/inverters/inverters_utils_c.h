#ifndef INVERTERS_UTILS_C_H

#define INVERTERS_UTILS_C_H

#include <stddef.h>
#include "inverters_network.h"

/* START */
#define inverters_inv_l_send_string "INVERTERS_INV_L_SEND"

#define inverters_inv_l_send_send_mux_string "INVERTERS_INV_L_SEND_SEND_MUX"
#define inverters_inv_l_send_read_id_string "INVERTERS_INV_L_SEND_READ_ID"
#define inverters_inv_l_send_km_rsvd_0_string "INVERTERS_INV_L_SEND_KM_RSVD_0"
#define inverters_inv_l_send_m_setdig__iq_string "INVERTERS_INV_L_SEND_M_SETDIG__IQ"
#define inverters_inv_l_send_def_din_1_string "INVERTERS_INV_L_SEND_DEF_DIN_1"
#define inverters_inv_l_send_def_end_1_string "INVERTERS_INV_L_SEND_DEF_END_1"
#define inverters_inv_l_send_i_max_pk_string "INVERTERS_INV_L_SEND_I_MAX_PK"
#define inverters_inv_l_send_i_con_eff_string "INVERTERS_INV_L_SEND_I_CON_EFF"
#define inverters_inv_l_send_i_device_string "INVERTERS_INV_L_SEND_I_DEVICE"
#define inverters_inv_l_send_n_r_lim_string "INVERTERS_INV_L_SEND_N_R_LIM"
#define inverters_inv_l_send_nmax100perc_string "INVERTERS_INV_L_SEND_NMAX100PERC"
#define inverters_inv_l_send_km_speed_0_string "INVERTERS_INV_L_SEND_KM_SPEED_0"
#define inverters_inv_l_send_km_frg_off_string "INVERTERS_INV_L_SEND_KM_FRG_OFF"
#define inverters_inv_l_send_km_cal_off_string "INVERTERS_INV_L_SEND_KM_CAL_OFF"
#define inverters_inv_l_send_km_tx_tog_stat_string "INVERTERS_INV_L_SEND_KM_TX_TOG_STAT"
#define inverters_inv_l_send_km_i_limit_string "INVERTERS_INV_L_SEND_KM_I_LIMIT"
#define inverters_inv_l_send_km_n_clip_string "INVERTERS_INV_L_SEND_KM_N_CLIP"
#define inverters_inv_l_send_km_mix_ana_on_string "INVERTERS_INV_L_SEND_KM_MIX_ANA_ON"
#define inverters_inv_l_send_ret_interval_string "INVERTERS_INV_L_SEND_RET_INTERVAL"
#define inverters_inv_l_send_km_allow_sync_string "INVERTERS_INV_L_SEND_KM_ALLOW_SYNC"
#define inverters_inv_l_send_km_handwheel_string "INVERTERS_INV_L_SEND_KM_HANDWHEEL"
#define inverters_inv_l_send_km_phasing_extend_string "INVERTERS_INV_L_SEND_KM_PHASING_EXTEND"
#define inverters_inv_l_send_km_rsvd_11_string "INVERTERS_INV_L_SEND_KM_RSVD_11"
#define inverters_inv_l_send_km_rsvd_12_string "INVERTERS_INV_L_SEND_KM_RSVD_12"
#define inverters_inv_l_send_km_rsvd_13_string "INVERTERS_INV_L_SEND_KM_RSVD_13"
#define inverters_inv_l_send_km_pseudo_enable_string "INVERTERS_INV_L_SEND_KM_PSEUDO_ENABLE"
#define inverters_inv_l_send_km_debug_test_string "INVERTERS_INV_L_SEND_KM_DEBUG_TEST"
#define inverters_inv_l_send_active192_string "INVERTERS_INV_L_SEND_ACTIVE192"
#define inverters_inv_l_send_active190_string "INVERTERS_INV_L_SEND_ACTIVE190"
#define inverters_inv_l_send_m_r_rcp_string "INVERTERS_INV_L_SEND_M_R_RCP"
/* END */

/* START */
#define inverters_inv_l_rcv_string "INVERTERS_INV_L_RCV"

#define inverters_inv_l_rcv_rcv_mux_string "INVERTERS_INV_L_RCV_RCV_MUX"
#define inverters_inv_l_rcv_n_actual_filt_string "INVERTERS_INV_L_RCV_N_ACTUAL_FILT"
#define inverters_inv_l_rcv_ena64_string "INVERTERS_INV_L_RCV_ENA64"
#define inverters_inv_l_rcv_err_badparas_string "INVERTERS_INV_L_RCV_ERR_BADPARAS"
#define inverters_inv_l_rcv_def_end_1_string "INVERTERS_INV_L_RCV_DEF_END_1"
#define inverters_inv_l_rcv_lmt_active_1_string "INVERTERS_INV_L_RCV_LMT_ACTIVE_1"
#define inverters_inv_l_rcv_i_cmd_string "INVERTERS_INV_L_RCV_I_CMD"
#define inverters_inv_l_rcv_i_cmd_ramp_string "INVERTERS_INV_L_RCV_I_CMD_RAMP"
#define inverters_inv_l_rcv_iq_actual_string "INVERTERS_INV_L_RCV_IQ_ACTUAL"
#define inverters_inv_l_rcv_t_motor_string "INVERTERS_INV_L_RCV_T_MOTOR"
#define inverters_inv_l_rcv_t_igbt_string "INVERTERS_INV_L_RCV_T_IGBT"
#define inverters_inv_l_rcv_vdc_bus_filt_string "INVERTERS_INV_L_RCV_VDC_BUS_FILT"
#define inverters_inv_l_rcv_km_rsvd_0_string "INVERTERS_INV_L_RCV_KM_RSVD_0"
#define inverters_inv_l_rcv_ena82_string "INVERTERS_INV_L_RCV_ENA82"
#define inverters_inv_l_rcv_def_din_1_string "INVERTERS_INV_L_RCV_DEF_DIN_1"
#define inverters_inv_l_rcv_m_cmd_ramp_string "INVERTERS_INV_L_RCV_M_CMD_RAMP"
#define inverters_inv_l_rcv_i_max_pk_string "INVERTERS_INV_L_RCV_I_MAX_PK"
#define inverters_inv_l_rcv_i_con_eff_string "INVERTERS_INV_L_RCV_I_CON_EFF"
#define inverters_inv_l_rcv_i_device_string "INVERTERS_INV_L_RCV_I_DEVICE"
#define inverters_inv_l_rcv_n_r_lim_string "INVERTERS_INV_L_RCV_N_R_LIM"
#define inverters_inv_l_rcv_nmax100perc_string "INVERTERS_INV_L_RCV_NMAX100PERC"
#define inverters_inv_l_rcv_ncr064_string "INVERTERS_INV_L_RCV_NCR064"
#define inverters_inv_l_rcv_err_powerfault_string "INVERTERS_INV_L_RCV_ERR_POWERFAULT"
#define inverters_inv_l_rcv_lmt_active_2_string "INVERTERS_INV_L_RCV_LMT_ACTIVE_2"
#define inverters_inv_l_rcv_km_speed_0_string "INVERTERS_INV_L_RCV_KM_SPEED_0"
#define inverters_inv_l_rcv_ncr082_string "INVERTERS_INV_L_RCV_NCR082"
#define inverters_inv_l_rcv_lim_plus64_string "INVERTERS_INV_L_RCV_LIM_PLUS64"
#define inverters_inv_l_rcv_err_rfe_fault_string "INVERTERS_INV_L_RCV_ERR_RFE_FAULT"
#define inverters_inv_l_rcv_in_active_2_string "INVERTERS_INV_L_RCV_IN_ACTIVE_2"
#define inverters_inv_l_rcv_km_frg_off_string "INVERTERS_INV_L_RCV_KM_FRG_OFF"
#define inverters_inv_l_rcv_lim_plus82_string "INVERTERS_INV_L_RCV_LIM_PLUS82"
#define inverters_inv_l_rcv_lim_minus64_string "INVERTERS_INV_L_RCV_LIM_MINUS64"
#define inverters_inv_l_rcv_err_bustimeout_string "INVERTERS_INV_L_RCV_ERR_BUSTIMEOUT"
#define inverters_inv_l_rcv_in_active_1_string "INVERTERS_INV_L_RCV_IN_ACTIVE_1"
#define inverters_inv_l_rcv_km_cal_off_string "INVERTERS_INV_L_RCV_KM_CAL_OFF"
#define inverters_inv_l_rcv_lim_minus82_string "INVERTERS_INV_L_RCV_LIM_MINUS82"
#define inverters_inv_l_rcv_ok64_string "INVERTERS_INV_L_RCV_OK64"
#define inverters_inv_l_rcv_err_feedbacksignal_string "INVERTERS_INV_L_RCV_ERR_FEEDBACKSIGNAL"
#define inverters_inv_l_rcv_frgrun_string "INVERTERS_INV_L_RCV_FRGRUN"
#define inverters_inv_l_rcv_km_tx_tog_stat_string "INVERTERS_INV_L_RCV_KM_TX_TOG_STAT"
#define inverters_inv_l_rcv_ok82_string "INVERTERS_INV_L_RCV_OK82"
#define inverters_inv_l_rcv_icns64_string "INVERTERS_INV_L_RCV_ICNS64"
#define inverters_inv_l_rcv_err_powervoltage_low_string "INVERTERS_INV_L_RCV_ERR_POWERVOLTAGE_LOW"
#define inverters_inv_l_rcv_rfe216_string "INVERTERS_INV_L_RCV_RFE216"
#define inverters_inv_l_rcv_km_i_limit_string "INVERTERS_INV_L_RCV_KM_I_LIMIT"
#define inverters_inv_l_rcv_icns82_string "INVERTERS_INV_L_RCV_ICNS82"
#define inverters_inv_l_rcv_tnlim64_string "INVERTERS_INV_L_RCV_TNLIM64"
#define inverters_inv_l_rcv_err_motortemp_string "INVERTERS_INV_L_RCV_ERR_MOTORTEMP"
#define inverters_inv_l_rcv_km_n_clip_string "INVERTERS_INV_L_RCV_KM_N_CLIP"
#define inverters_inv_l_rcv_tnlim82_string "INVERTERS_INV_L_RCV_TNLIM82"
#define inverters_inv_l_rcv_pn64_string "INVERTERS_INV_L_RCV_PN64"
#define inverters_inv_l_rcv_err_devicetemp_string "INVERTERS_INV_L_RCV_ERR_DEVICETEMP"
#define inverters_inv_l_rcv_km_mix_ana_on_string "INVERTERS_INV_L_RCV_KM_MIX_ANA_ON"
#define inverters_inv_l_rcv_pn82_string "INVERTERS_INV_L_RCV_PN82"
#define inverters_inv_l_rcv_ni64_string "INVERTERS_INV_L_RCV_NI64"
#define inverters_inv_l_rcv_err_overvoltage_string "INVERTERS_INV_L_RCV_ERR_OVERVOLTAGE"
#define inverters_inv_l_rcv_d_out_1_on_string "INVERTERS_INV_L_RCV_D_OUT_1_ON"
#define inverters_inv_l_rcv_km_allow_sync_string "INVERTERS_INV_L_RCV_KM_ALLOW_SYNC"
#define inverters_inv_l_rcv_ni82_string "INVERTERS_INV_L_RCV_NI82"
#define inverters_inv_l_rcv__n064_string "INVERTERS_INV_L_RCV__N064"
#define inverters_inv_l_rcv_err_ipeak_string "INVERTERS_INV_L_RCV_ERR_IPEAK"
#define inverters_inv_l_rcv_d_out_2_on_string "INVERTERS_INV_L_RCV_D_OUT_2_ON"
#define inverters_inv_l_rcv_km_handwheel_string "INVERTERS_INV_L_RCV_KM_HANDWHEEL"
#define inverters_inv_l_rcv__n082_string "INVERTERS_INV_L_RCV__N082"
#define inverters_inv_l_rcv_rsw64_string "INVERTERS_INV_L_RCV_RSW64"
#define inverters_inv_l_rcv_err_raceaway_string "INVERTERS_INV_L_RCV_ERR_RACEAWAY"
#define inverters_inv_l_rcv_btbrdy_string "INVERTERS_INV_L_RCV_BTBRDY"
#define inverters_inv_l_rcv_km_phasing_extend_string "INVERTERS_INV_L_RCV_KM_PHASING_EXTEND"
#define inverters_inv_l_rcv_rsw82_string "INVERTERS_INV_L_RCV_RSW82"
#define inverters_inv_l_rcv_cal064_string "INVERTERS_INV_L_RCV_CAL064"
#define inverters_inv_l_rcv_err_user_string "INVERTERS_INV_L_RCV_ERR_USER"
#define inverters_inv_l_rcv_go216_string "INVERTERS_INV_L_RCV_GO216"
#define inverters_inv_l_rcv_km_rsvd_11_string "INVERTERS_INV_L_RCV_KM_RSVD_11"
#define inverters_inv_l_rcv_cal082_string "INVERTERS_INV_L_RCV_CAL082"
#define inverters_inv_l_rcv_cal64_string "INVERTERS_INV_L_RCV_CAL64"
#define inverters_inv_l_rcv_d_out_3_on_string "INVERTERS_INV_L_RCV_D_OUT_3_ON"
#define inverters_inv_l_rcv_km_rsvd_12_string "INVERTERS_INV_L_RCV_KM_RSVD_12"
#define inverters_inv_l_rcv_cal82_string "INVERTERS_INV_L_RCV_CAL82"
#define inverters_inv_l_rcv_tol64_string "INVERTERS_INV_L_RCV_TOL64"
#define inverters_inv_l_rcv_d_out_4_on_string "INVERTERS_INV_L_RCV_D_OUT_4_ON"
#define inverters_inv_l_rcv_km_rsvd_13_string "INVERTERS_INV_L_RCV_KM_RSVD_13"
#define inverters_inv_l_rcv_tol82_string "INVERTERS_INV_L_RCV_TOL82"
#define inverters_inv_l_rcv_rdy64_string "INVERTERS_INV_L_RCV_RDY64"
#define inverters_inv_l_rcv_err_hwerr_string "INVERTERS_INV_L_RCV_ERR_HWERR"
#define inverters_inv_l_rcv_goff_string "INVERTERS_INV_L_RCV_GOFF"
#define inverters_inv_l_rcv_km_pseudo_enable_string "INVERTERS_INV_L_RCV_KM_PSEUDO_ENABLE"
#define inverters_inv_l_rcv_rdy82_string "INVERTERS_INV_L_RCV_RDY82"
#define inverters_inv_l_rcv_brk064_string "INVERTERS_INV_L_RCV_BRK064"
#define inverters_inv_l_rcv_err_ballast_string "INVERTERS_INV_L_RCV_ERR_BALLAST"
#define inverters_inv_l_rcv_active190_string "INVERTERS_INV_L_RCV_ACTIVE190"
#define inverters_inv_l_rcv_brk1216_string "INVERTERS_INV_L_RCV_BRK1216"
#define inverters_inv_l_rcv_km_debug_test_string "INVERTERS_INV_L_RCV_KM_DEBUG_TEST"
#define inverters_inv_l_rcv_brk082_string "INVERTERS_INV_L_RCV_BRK082"
#define inverters_inv_l_rcv_active192_string "INVERTERS_INV_L_RCV_ACTIVE192"
#define inverters_inv_l_rcv_signmag64_string "INVERTERS_INV_L_RCV_SIGNMAG64"
#define inverters_inv_l_rcv_warn_warning_0_string "INVERTERS_INV_L_RCV_WARN_WARNING_0"
#define inverters_inv_l_rcv_signmag82_string "INVERTERS_INV_L_RCV_SIGNMAG82"
#define inverters_inv_l_rcv_free_string "INVERTERS_INV_L_RCV_FREE"
#define inverters_inv_l_rcv_m_r_rcp_string "INVERTERS_INV_L_RCV_M_R_RCP"
#define inverters_inv_l_rcv_nclip64_string "INVERTERS_INV_L_RCV_NCLIP64"
#define inverters_inv_l_rcv_warn_illegal_status_string "INVERTERS_INV_L_RCV_WARN_ILLEGAL_STATUS"
#define inverters_inv_l_rcv_nclip82_string "INVERTERS_INV_L_RCV_NCLIP82"
#define inverters_inv_l_rcv_nclip_minus64_string "INVERTERS_INV_L_RCV_NCLIP_MINUS64"
#define inverters_inv_l_rcv_warn_safe_in_string "INVERTERS_INV_L_RCV_WARN_SAFE_IN"
#define inverters_inv_l_rcv_nclip_minus82_string "INVERTERS_INV_L_RCV_NCLIP_MINUS82"
#define inverters_inv_l_rcv_nclip_plus64_string "INVERTERS_INV_L_RCV_NCLIP_PLUS64"
#define inverters_inv_l_rcv_nclip_plus82_string "INVERTERS_INV_L_RCV_NCLIP_PLUS82"
#define inverters_inv_l_rcv_irddig64_string "INVERTERS_INV_L_RCV_IRDDIG64"
#define inverters_inv_l_rcv_irddig82_string "INVERTERS_INV_L_RCV_IRDDIG82"
#define inverters_inv_l_rcv_iuserchd64_string "INVERTERS_INV_L_RCV_IUSERCHD64"
#define inverters_inv_l_rcv_iuserchd82_string "INVERTERS_INV_L_RCV_IUSERCHD82"
#define inverters_inv_l_rcv_irdn64_string "INVERTERS_INV_L_RCV_IRDN64"
#define inverters_inv_l_rcv_warn_motortemp_string "INVERTERS_INV_L_RCV_WARN_MOTORTEMP"
#define inverters_inv_l_rcv_irdn82_string "INVERTERS_INV_L_RCV_IRDN82"
#define inverters_inv_l_rcv_irdti64_string "INVERTERS_INV_L_RCV_IRDTI64"
#define inverters_inv_l_rcv_warn_devicetemp_string "INVERTERS_INV_L_RCV_WARN_DEVICETEMP"
#define inverters_inv_l_rcv_irdti82_string "INVERTERS_INV_L_RCV_IRDTI82"
#define inverters_inv_l_rcv_irdtir64_string "INVERTERS_INV_L_RCV_IRDTIR64"
#define inverters_inv_l_rcv_warn_vout_sat_string "INVERTERS_INV_L_RCV_WARN_VOUT_SAT"
#define inverters_inv_l_rcv_irdtir82_string "INVERTERS_INV_L_RCV_IRDTIR82"
#define inverters_inv_l_rcv__10hz64_string "INVERTERS_INV_L_RCV__10HZ64"
#define inverters_inv_l_rcv_warn_ipeak_string "INVERTERS_INV_L_RCV_WARN_IPEAK"
#define inverters_inv_l_rcv__10hz82_string "INVERTERS_INV_L_RCV__10HZ82"
#define inverters_inv_l_rcv_irdtm64_string "INVERTERS_INV_L_RCV_IRDTM64"
#define inverters_inv_l_rcv_warn_raceaway_string "INVERTERS_INV_L_RCV_WARN_RACEAWAY"
#define inverters_inv_l_rcv_irdtm82_string "INVERTERS_INV_L_RCV_IRDTM82"
#define inverters_inv_l_rcv_irdana64_string "INVERTERS_INV_L_RCV_IRDANA64"
#define inverters_inv_l_rcv_irdana82_string "INVERTERS_INV_L_RCV_IRDANA82"
#define inverters_inv_l_rcv_iwcns64_string "INVERTERS_INV_L_RCV_IWCNS64"
#define inverters_inv_l_rcv_iwcns82_string "INVERTERS_INV_L_RCV_IWCNS82"
#define inverters_inv_l_rcv_rfepulse64_string "INVERTERS_INV_L_RCV_RFEPULSE64"
#define inverters_inv_l_rcv_rfepulse82_string "INVERTERS_INV_L_RCV_RFEPULSE82"
#define inverters_inv_l_rcv_md64_string "INVERTERS_INV_L_RCV_MD64"
#define inverters_inv_l_rcv_md82_string "INVERTERS_INV_L_RCV_MD82"
#define inverters_inv_l_rcv_hndwhl64_string "INVERTERS_INV_L_RCV_HNDWHL64"
#define inverters_inv_l_rcv_warn_ballast_string "INVERTERS_INV_L_RCV_WARN_BALLAST"
#define inverters_inv_l_rcv_hndwhl82_string "INVERTERS_INV_L_RCV_HNDWHL82"
/* END */

/* START */
#define inverters_inv_r_send_string "INVERTERS_INV_R_SEND"

#define inverters_inv_r_send_send_mux_string "INVERTERS_INV_R_SEND_SEND_MUX"
#define inverters_inv_r_send_read_id_string "INVERTERS_INV_R_SEND_READ_ID"
#define inverters_inv_r_send_km_rsvd_0_string "INVERTERS_INV_R_SEND_KM_RSVD_0"
#define inverters_inv_r_send_m_setdig__iq_string "INVERTERS_INV_R_SEND_M_SETDIG__IQ"
#define inverters_inv_r_send_def_din_1_string "INVERTERS_INV_R_SEND_DEF_DIN_1"
#define inverters_inv_r_send_def_end_1_string "INVERTERS_INV_R_SEND_DEF_END_1"
#define inverters_inv_r_send_i_max_pk_string "INVERTERS_INV_R_SEND_I_MAX_PK"
#define inverters_inv_r_send_i_con_eff_string "INVERTERS_INV_R_SEND_I_CON_EFF"
#define inverters_inv_r_send_i_device_string "INVERTERS_INV_R_SEND_I_DEVICE"
#define inverters_inv_r_send_n_r_lim_string "INVERTERS_INV_R_SEND_N_R_LIM"
#define inverters_inv_r_send_nmax100perc_string "INVERTERS_INV_R_SEND_NMAX100PERC"
#define inverters_inv_r_send_km_speed_0_string "INVERTERS_INV_R_SEND_KM_SPEED_0"
#define inverters_inv_r_send_km_frg_off_string "INVERTERS_INV_R_SEND_KM_FRG_OFF"
#define inverters_inv_r_send_km_cal_off_string "INVERTERS_INV_R_SEND_KM_CAL_OFF"
#define inverters_inv_r_send_km_tx_tog_stat_string "INVERTERS_INV_R_SEND_KM_TX_TOG_STAT"
#define inverters_inv_r_send_km_i_limit_string "INVERTERS_INV_R_SEND_KM_I_LIMIT"
#define inverters_inv_r_send_km_n_clip_string "INVERTERS_INV_R_SEND_KM_N_CLIP"
#define inverters_inv_r_send_km_mix_ana_on_string "INVERTERS_INV_R_SEND_KM_MIX_ANA_ON"
#define inverters_inv_r_send_ret_interval_string "INVERTERS_INV_R_SEND_RET_INTERVAL"
#define inverters_inv_r_send_km_allow_sync_string "INVERTERS_INV_R_SEND_KM_ALLOW_SYNC"
#define inverters_inv_r_send_km_handwheel_string "INVERTERS_INV_R_SEND_KM_HANDWHEEL"
#define inverters_inv_r_send_km_phasing_extend_string "INVERTERS_INV_R_SEND_KM_PHASING_EXTEND"
#define inverters_inv_r_send_km_rsvd_11_string "INVERTERS_INV_R_SEND_KM_RSVD_11"
#define inverters_inv_r_send_km_rsvd_12_string "INVERTERS_INV_R_SEND_KM_RSVD_12"
#define inverters_inv_r_send_km_rsvd_13_string "INVERTERS_INV_R_SEND_KM_RSVD_13"
#define inverters_inv_r_send_km_pseudo_enable_string "INVERTERS_INV_R_SEND_KM_PSEUDO_ENABLE"
#define inverters_inv_r_send_km_debug_test_string "INVERTERS_INV_R_SEND_KM_DEBUG_TEST"
#define inverters_inv_r_send_active192_string "INVERTERS_INV_R_SEND_ACTIVE192"
#define inverters_inv_r_send_active190_string "INVERTERS_INV_R_SEND_ACTIVE190"
#define inverters_inv_r_send_m_r_rcp_string "INVERTERS_INV_R_SEND_M_R_RCP"
/* END */

/* START */
#define inverters_inv_r_rcv_string "INVERTERS_INV_R_RCV"

#define inverters_inv_r_rcv_rcv_mux_string "INVERTERS_INV_R_RCV_RCV_MUX"
#define inverters_inv_r_rcv_n_actual_filt_string "INVERTERS_INV_R_RCV_N_ACTUAL_FILT"
#define inverters_inv_r_rcv_ena64_string "INVERTERS_INV_R_RCV_ENA64"
#define inverters_inv_r_rcv_err_badparas_string "INVERTERS_INV_R_RCV_ERR_BADPARAS"
#define inverters_inv_r_rcv_def_end_1_string "INVERTERS_INV_R_RCV_DEF_END_1"
#define inverters_inv_r_rcv_lmt_active_1_string "INVERTERS_INV_R_RCV_LMT_ACTIVE_1"
#define inverters_inv_r_rcv_i_cmd_string "INVERTERS_INV_R_RCV_I_CMD"
#define inverters_inv_r_rcv_i_cmd_ramp_string "INVERTERS_INV_R_RCV_I_CMD_RAMP"
#define inverters_inv_r_rcv_iq_actual_string "INVERTERS_INV_R_RCV_IQ_ACTUAL"
#define inverters_inv_r_rcv_t_motor_string "INVERTERS_INV_R_RCV_T_MOTOR"
#define inverters_inv_r_rcv_t_igbt_string "INVERTERS_INV_R_RCV_T_IGBT"
#define inverters_inv_r_rcv_vdc_bus_filt_string "INVERTERS_INV_R_RCV_VDC_BUS_FILT"
#define inverters_inv_r_rcv_km_rsvd_0_string "INVERTERS_INV_R_RCV_KM_RSVD_0"
#define inverters_inv_r_rcv_ena82_string "INVERTERS_INV_R_RCV_ENA82"
#define inverters_inv_r_rcv_def_din_1_string "INVERTERS_INV_R_RCV_DEF_DIN_1"
#define inverters_inv_r_rcv_m_cmd_ramp_string "INVERTERS_INV_R_RCV_M_CMD_RAMP"
#define inverters_inv_r_rcv_i_max_pk_string "INVERTERS_INV_R_RCV_I_MAX_PK"
#define inverters_inv_r_rcv_i_con_eff_string "INVERTERS_INV_R_RCV_I_CON_EFF"
#define inverters_inv_r_rcv_i_device_string "INVERTERS_INV_R_RCV_I_DEVICE"
#define inverters_inv_r_rcv_n_r_lim_string "INVERTERS_INV_R_RCV_N_R_LIM"
#define inverters_inv_r_rcv_nmax100perc_string "INVERTERS_INV_R_RCV_NMAX100PERC"
#define inverters_inv_r_rcv_ncr064_string "INVERTERS_INV_R_RCV_NCR064"
#define inverters_inv_r_rcv_err_powerfault_string "INVERTERS_INV_R_RCV_ERR_POWERFAULT"
#define inverters_inv_r_rcv_lmt_active_2_string "INVERTERS_INV_R_RCV_LMT_ACTIVE_2"
#define inverters_inv_r_rcv_km_speed_0_string "INVERTERS_INV_R_RCV_KM_SPEED_0"
#define inverters_inv_r_rcv_ncr082_string "INVERTERS_INV_R_RCV_NCR082"
#define inverters_inv_r_rcv_lim_plus64_string "INVERTERS_INV_R_RCV_LIM_PLUS64"
#define inverters_inv_r_rcv_err_rfe_fault_string "INVERTERS_INV_R_RCV_ERR_RFE_FAULT"
#define inverters_inv_r_rcv_in_active_2_string "INVERTERS_INV_R_RCV_IN_ACTIVE_2"
#define inverters_inv_r_rcv_km_frg_off_string "INVERTERS_INV_R_RCV_KM_FRG_OFF"
#define inverters_inv_r_rcv_lim_plus82_string "INVERTERS_INV_R_RCV_LIM_PLUS82"
#define inverters_inv_r_rcv_lim_minus64_string "INVERTERS_INV_R_RCV_LIM_MINUS64"
#define inverters_inv_r_rcv_err_bustimeout_string "INVERTERS_INV_R_RCV_ERR_BUSTIMEOUT"
#define inverters_inv_r_rcv_in_active_1_string "INVERTERS_INV_R_RCV_IN_ACTIVE_1"
#define inverters_inv_r_rcv_km_cal_off_string "INVERTERS_INV_R_RCV_KM_CAL_OFF"
#define inverters_inv_r_rcv_lim_minus82_string "INVERTERS_INV_R_RCV_LIM_MINUS82"
#define inverters_inv_r_rcv_ok64_string "INVERTERS_INV_R_RCV_OK64"
#define inverters_inv_r_rcv_err_feedbacksignal_string "INVERTERS_INV_R_RCV_ERR_FEEDBACKSIGNAL"
#define inverters_inv_r_rcv_frgrun_string "INVERTERS_INV_R_RCV_FRGRUN"
#define inverters_inv_r_rcv_km_tx_tog_stat_string "INVERTERS_INV_R_RCV_KM_TX_TOG_STAT"
#define inverters_inv_r_rcv_ok82_string "INVERTERS_INV_R_RCV_OK82"
#define inverters_inv_r_rcv_icns64_string "INVERTERS_INV_R_RCV_ICNS64"
#define inverters_inv_r_rcv_err_powervoltage_low_string "INVERTERS_INV_R_RCV_ERR_POWERVOLTAGE_LOW"
#define inverters_inv_r_rcv_rfe216_string "INVERTERS_INV_R_RCV_RFE216"
#define inverters_inv_r_rcv_km_i_limit_string "INVERTERS_INV_R_RCV_KM_I_LIMIT"
#define inverters_inv_r_rcv_icns82_string "INVERTERS_INV_R_RCV_ICNS82"
#define inverters_inv_r_rcv_tnlim64_string "INVERTERS_INV_R_RCV_TNLIM64"
#define inverters_inv_r_rcv_err_motortemp_string "INVERTERS_INV_R_RCV_ERR_MOTORTEMP"
#define inverters_inv_r_rcv_km_n_clip_string "INVERTERS_INV_R_RCV_KM_N_CLIP"
#define inverters_inv_r_rcv_tnlim82_string "INVERTERS_INV_R_RCV_TNLIM82"
#define inverters_inv_r_rcv_pn64_string "INVERTERS_INV_R_RCV_PN64"
#define inverters_inv_r_rcv_err_devicetemp_string "INVERTERS_INV_R_RCV_ERR_DEVICETEMP"
#define inverters_inv_r_rcv_km_mix_ana_on_string "INVERTERS_INV_R_RCV_KM_MIX_ANA_ON"
#define inverters_inv_r_rcv_pn82_string "INVERTERS_INV_R_RCV_PN82"
#define inverters_inv_r_rcv_ni64_string "INVERTERS_INV_R_RCV_NI64"
#define inverters_inv_r_rcv_err_overvoltage_string "INVERTERS_INV_R_RCV_ERR_OVERVOLTAGE"
#define inverters_inv_r_rcv_d_out_1_on_string "INVERTERS_INV_R_RCV_D_OUT_1_ON"
#define inverters_inv_r_rcv_km_allow_sync_string "INVERTERS_INV_R_RCV_KM_ALLOW_SYNC"
#define inverters_inv_r_rcv_ni82_string "INVERTERS_INV_R_RCV_NI82"
#define inverters_inv_r_rcv__n064_string "INVERTERS_INV_R_RCV__N064"
#define inverters_inv_r_rcv_err_ipeak_string "INVERTERS_INV_R_RCV_ERR_IPEAK"
#define inverters_inv_r_rcv_d_out_2_on_string "INVERTERS_INV_R_RCV_D_OUT_2_ON"
#define inverters_inv_r_rcv_km_handwheel_string "INVERTERS_INV_R_RCV_KM_HANDWHEEL"
#define inverters_inv_r_rcv__n082_string "INVERTERS_INV_R_RCV__N082"
#define inverters_inv_r_rcv_rsw64_string "INVERTERS_INV_R_RCV_RSW64"
#define inverters_inv_r_rcv_err_raceaway_string "INVERTERS_INV_R_RCV_ERR_RACEAWAY"
#define inverters_inv_r_rcv_btbrdy_string "INVERTERS_INV_R_RCV_BTBRDY"
#define inverters_inv_r_rcv_km_phasing_extend_string "INVERTERS_INV_R_RCV_KM_PHASING_EXTEND"
#define inverters_inv_r_rcv_rsw82_string "INVERTERS_INV_R_RCV_RSW82"
#define inverters_inv_r_rcv_cal064_string "INVERTERS_INV_R_RCV_CAL064"
#define inverters_inv_r_rcv_err_user_string "INVERTERS_INV_R_RCV_ERR_USER"
#define inverters_inv_r_rcv_go216_string "INVERTERS_INV_R_RCV_GO216"
#define inverters_inv_r_rcv_km_rsvd_11_string "INVERTERS_INV_R_RCV_KM_RSVD_11"
#define inverters_inv_r_rcv_cal082_string "INVERTERS_INV_R_RCV_CAL082"
#define inverters_inv_r_rcv_cal64_string "INVERTERS_INV_R_RCV_CAL64"
#define inverters_inv_r_rcv_d_out_3_on_string "INVERTERS_INV_R_RCV_D_OUT_3_ON"
#define inverters_inv_r_rcv_km_rsvd_12_string "INVERTERS_INV_R_RCV_KM_RSVD_12"
#define inverters_inv_r_rcv_cal82_string "INVERTERS_INV_R_RCV_CAL82"
#define inverters_inv_r_rcv_tol64_string "INVERTERS_INV_R_RCV_TOL64"
#define inverters_inv_r_rcv_d_out_4_on_string "INVERTERS_INV_R_RCV_D_OUT_4_ON"
#define inverters_inv_r_rcv_km_rsvd_13_string "INVERTERS_INV_R_RCV_KM_RSVD_13"
#define inverters_inv_r_rcv_tol82_string "INVERTERS_INV_R_RCV_TOL82"
#define inverters_inv_r_rcv_rdy64_string "INVERTERS_INV_R_RCV_RDY64"
#define inverters_inv_r_rcv_err_hwerr_string "INVERTERS_INV_R_RCV_ERR_HWERR"
#define inverters_inv_r_rcv_goff_string "INVERTERS_INV_R_RCV_GOFF"
#define inverters_inv_r_rcv_km_pseudo_enable_string "INVERTERS_INV_R_RCV_KM_PSEUDO_ENABLE"
#define inverters_inv_r_rcv_rdy82_string "INVERTERS_INV_R_RCV_RDY82"
#define inverters_inv_r_rcv_brk064_string "INVERTERS_INV_R_RCV_BRK064"
#define inverters_inv_r_rcv_err_ballast_string "INVERTERS_INV_R_RCV_ERR_BALLAST"
#define inverters_inv_r_rcv_active190_string "INVERTERS_INV_R_RCV_ACTIVE190"
#define inverters_inv_r_rcv_brk1216_string "INVERTERS_INV_R_RCV_BRK1216"
#define inverters_inv_r_rcv_km_debug_test_string "INVERTERS_INV_R_RCV_KM_DEBUG_TEST"
#define inverters_inv_r_rcv_brk082_string "INVERTERS_INV_R_RCV_BRK082"
#define inverters_inv_r_rcv_active192_string "INVERTERS_INV_R_RCV_ACTIVE192"
#define inverters_inv_r_rcv_signmag64_string "INVERTERS_INV_R_RCV_SIGNMAG64"
#define inverters_inv_r_rcv_warn_warning_0_string "INVERTERS_INV_R_RCV_WARN_WARNING_0"
#define inverters_inv_r_rcv_signmag82_string "INVERTERS_INV_R_RCV_SIGNMAG82"
#define inverters_inv_r_rcv_free_string "INVERTERS_INV_R_RCV_FREE"
#define inverters_inv_r_rcv_m_r_rcp_string "INVERTERS_INV_R_RCV_M_R_RCP"
#define inverters_inv_r_rcv_nclip64_string "INVERTERS_INV_R_RCV_NCLIP64"
#define inverters_inv_r_rcv_warn_illegal_status_string "INVERTERS_INV_R_RCV_WARN_ILLEGAL_STATUS"
#define inverters_inv_r_rcv_nclip82_string "INVERTERS_INV_R_RCV_NCLIP82"
#define inverters_inv_r_rcv_nclip_minus64_string "INVERTERS_INV_R_RCV_NCLIP_MINUS64"
#define inverters_inv_r_rcv_warn_safe_in_string "INVERTERS_INV_R_RCV_WARN_SAFE_IN"
#define inverters_inv_r_rcv_nclip_minus82_string "INVERTERS_INV_R_RCV_NCLIP_MINUS82"
#define inverters_inv_r_rcv_nclip_plus64_string "INVERTERS_INV_R_RCV_NCLIP_PLUS64"
#define inverters_inv_r_rcv_nclip_plus82_string "INVERTERS_INV_R_RCV_NCLIP_PLUS82"
#define inverters_inv_r_rcv_irddig64_string "INVERTERS_INV_R_RCV_IRDDIG64"
#define inverters_inv_r_rcv_irddig82_string "INVERTERS_INV_R_RCV_IRDDIG82"
#define inverters_inv_r_rcv_iuserchd64_string "INVERTERS_INV_R_RCV_IUSERCHD64"
#define inverters_inv_r_rcv_iuserchd82_string "INVERTERS_INV_R_RCV_IUSERCHD82"
#define inverters_inv_r_rcv_irdn64_string "INVERTERS_INV_R_RCV_IRDN64"
#define inverters_inv_r_rcv_warn_motortemp_string "INVERTERS_INV_R_RCV_WARN_MOTORTEMP"
#define inverters_inv_r_rcv_irdn82_string "INVERTERS_INV_R_RCV_IRDN82"
#define inverters_inv_r_rcv_irdti64_string "INVERTERS_INV_R_RCV_IRDTI64"
#define inverters_inv_r_rcv_warn_devicetemp_string "INVERTERS_INV_R_RCV_WARN_DEVICETEMP"
#define inverters_inv_r_rcv_irdti82_string "INVERTERS_INV_R_RCV_IRDTI82"
#define inverters_inv_r_rcv_irdtir64_string "INVERTERS_INV_R_RCV_IRDTIR64"
#define inverters_inv_r_rcv_warn_vout_sat_string "INVERTERS_INV_R_RCV_WARN_VOUT_SAT"
#define inverters_inv_r_rcv_irdtir82_string "INVERTERS_INV_R_RCV_IRDTIR82"
#define inverters_inv_r_rcv__10hz64_string "INVERTERS_INV_R_RCV__10HZ64"
#define inverters_inv_r_rcv_warn_ipeak_string "INVERTERS_INV_R_RCV_WARN_IPEAK"
#define inverters_inv_r_rcv__10hz82_string "INVERTERS_INV_R_RCV__10HZ82"
#define inverters_inv_r_rcv_irdtm64_string "INVERTERS_INV_R_RCV_IRDTM64"
#define inverters_inv_r_rcv_warn_raceaway_string "INVERTERS_INV_R_RCV_WARN_RACEAWAY"
#define inverters_inv_r_rcv_irdtm82_string "INVERTERS_INV_R_RCV_IRDTM82"
#define inverters_inv_r_rcv_irdana64_string "INVERTERS_INV_R_RCV_IRDANA64"
#define inverters_inv_r_rcv_irdana82_string "INVERTERS_INV_R_RCV_IRDANA82"
#define inverters_inv_r_rcv_iwcns64_string "INVERTERS_INV_R_RCV_IWCNS64"
#define inverters_inv_r_rcv_iwcns82_string "INVERTERS_INV_R_RCV_IWCNS82"
#define inverters_inv_r_rcv_rfepulse64_string "INVERTERS_INV_R_RCV_RFEPULSE64"
#define inverters_inv_r_rcv_rfepulse82_string "INVERTERS_INV_R_RCV_RFEPULSE82"
#define inverters_inv_r_rcv_md64_string "INVERTERS_INV_R_RCV_MD64"
#define inverters_inv_r_rcv_md82_string "INVERTERS_INV_R_RCV_MD82"
#define inverters_inv_r_rcv_hndwhl64_string "INVERTERS_INV_R_RCV_HNDWHL64"
#define inverters_inv_r_rcv_warn_ballast_string "INVERTERS_INV_R_RCV_WARN_BALLAST"
#define inverters_inv_r_rcv_hndwhl82_string "INVERTERS_INV_R_RCV_HNDWHL82"
/* END */

enum inverters_types_id{
	e_inverters_uint8_t = -4,
	e_inverters_uint16_t,
	e_inverters_float,
	e_inverters_int16_t,

	e_inverters_inv_r_send_def_end_1,
	e_inverters_inv_r_rcv_def_end_1,
	e_inverters_inv_r_send_def_din_1,
	e_inverters_inv_l_rcv_active192,
	e_inverters_inv_l_send_active190,
	e_inverters_inv_l_send_read_id,
	e_inverters_inv_l_send_ret_interval,
	e_inverters_inv_r_send_send_mux,
	e_inverters_inv_l_send_def_end_1,
	e_inverters_inv_r_send_active190,
	e_inverters_inv_r_rcv_active190,
	e_inverters_inv_l_rcv_active190,
	e_inverters_inv_r_rcv_rcv_mux,
	e_inverters_inv_r_send_active192,
	e_inverters_inv_r_rcv_def_din_1,
	e_inverters_inv_l_send_def_din_1,
	e_inverters_inv_r_send_read_id,
	e_inverters_inv_l_rcv_def_din_1,
	e_inverters_inv_l_rcv_def_end_1,
	e_inverters_inv_l_send_send_mux,
	e_inverters_inv_r_send_ret_interval,
	e_inverters_inv_r_rcv_active192,
	e_inverters_inv_l_send_active192,
	e_inverters_inv_l_rcv_rcv_mux
};
int inverters_fields_string_from_id(int id, char **v, size_t fields_size, size_t string_size);
int inverters_enum_fields(int enum_id, char **v, size_t fields_size, size_t string_size);
int inverters_serialize_from_id(int id, char *s, uint8_t *data, size_t *size);
int inverters_n_fields_from_id(int id);
int inverters_fields_types_from_id(int id, int* fields_types, int fields_types_size);


#endif