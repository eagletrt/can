#ifndef inverters_UTILS_H
#define inverters_UTILS_H

#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "inverters_network.h"

#ifdef __cplusplus
extern "C" {
#endif

/* START */
#define INV_L_SEND "INV_L_SEND"

#define INV_L_SEND_SEND_MUX "inv_l_send_send_mux"
#define INV_L_SEND_READ_ID "inv_l_send_read_id"
#define INV_L_SEND_KM_RSVD_0 "inv_l_send_km_rsvd_0"
#define INV_L_SEND_M_SETDIG__IQ "inv_l_send_m_setdig__iq"
#define INV_L_SEND_DEF_DIN_1 "inv_l_send_def_din_1"
#define INV_L_SEND_DEF_END_1 "inv_l_send_def_end_1"
#define INV_L_SEND_I_MAX_PK "inv_l_send_i_max_pk"
#define INV_L_SEND_I_CON_EFF "inv_l_send_i_con_eff"
#define INV_L_SEND_I_DEVICE "inv_l_send_i_device"
#define INV_L_SEND_N_R_LIM "inv_l_send_n_r_lim"
#define INV_L_SEND_NMAX100PERC "inv_l_send_nmax100perc"
#define INV_L_SEND_KM_SPEED_0 "inv_l_send_km_speed_0"
#define INV_L_SEND_KM_FRG_OFF "inv_l_send_km_frg_off"
#define INV_L_SEND_KM_CAL_OFF "inv_l_send_km_cal_off"
#define INV_L_SEND_KM_TX_TOG_STAT "inv_l_send_km_tx_tog_stat"
#define INV_L_SEND_KM_I_LIMIT "inv_l_send_km_i_limit"
#define INV_L_SEND_KM_N_CLIP "inv_l_send_km_n_clip"
#define INV_L_SEND_KM_MIX_ANA_ON "inv_l_send_km_mix_ana_on"
#define INV_L_SEND_RET_INTERVAL "inv_l_send_ret_interval"
#define INV_L_SEND_KM_ALLOW_SYNC "inv_l_send_km_allow_sync"
#define INV_L_SEND_KM_HANDWHEEL "inv_l_send_km_handwheel"
#define INV_L_SEND_KM_PHASING_EXTEND "inv_l_send_km_phasing_extend"
#define INV_L_SEND_KM_RSVD_11 "inv_l_send_km_rsvd_11"
#define INV_L_SEND_KM_RSVD_12 "inv_l_send_km_rsvd_12"
#define INV_L_SEND_KM_RSVD_13 "inv_l_send_km_rsvd_13"
#define INV_L_SEND_KM_PSEUDO_ENABLE "inv_l_send_km_pseudo_enable"
#define INV_L_SEND_KM_DEBUG_TEST "inv_l_send_km_debug_test"
#define INV_L_SEND_ACTIVE192 "inv_l_send_active192"
#define INV_L_SEND_ACTIVE190 "inv_l_send_active190"
#define INV_L_SEND_M_R_RCP "inv_l_send_m_r_rcp"
/* END */

/* START */
#define INV_L_RCV "INV_L_RCV"

#define INV_L_RCV_RCV_MUX "inv_l_rcv_rcv_mux"
#define INV_L_RCV_N_ACTUAL_FILT "inv_l_rcv_n_actual_filt"
#define INV_L_RCV_ENA64 "inv_l_rcv_ena64"
#define INV_L_RCV_ERR_BADPARAS "inv_l_rcv_err_badparas"
#define INV_L_RCV_DEF_END_1 "inv_l_rcv_def_end_1"
#define INV_L_RCV_LMT_ACTIVE_1 "inv_l_rcv_lmt_active_1"
#define INV_L_RCV_I_CMD "inv_l_rcv_i_cmd"
#define INV_L_RCV_I_CMD_RAMP "inv_l_rcv_i_cmd_ramp"
#define INV_L_RCV_IQ_ACTUAL "inv_l_rcv_iq_actual"
#define INV_L_RCV_T_MOTOR "inv_l_rcv_t_motor"
#define INV_L_RCV_T_IGBT "inv_l_rcv_t_igbt"
#define INV_L_RCV_VDC_BUS_FILT "inv_l_rcv_vdc_bus_filt"
#define INV_L_RCV_KM_RSVD_0 "inv_l_rcv_km_rsvd_0"
#define INV_L_RCV_ENA82 "inv_l_rcv_ena82"
#define INV_L_RCV_DEF_DIN_1 "inv_l_rcv_def_din_1"
#define INV_L_RCV_M_CMD_RAMP "inv_l_rcv_m_cmd_ramp"
#define INV_L_RCV_I_MAX_PK "inv_l_rcv_i_max_pk"
#define INV_L_RCV_I_CON_EFF "inv_l_rcv_i_con_eff"
#define INV_L_RCV_I_DEVICE "inv_l_rcv_i_device"
#define INV_L_RCV_N_R_LIM "inv_l_rcv_n_r_lim"
#define INV_L_RCV_NMAX100PERC "inv_l_rcv_nmax100perc"
#define INV_L_RCV_NCR064 "inv_l_rcv_ncr064"
#define INV_L_RCV_ERR_POWERFAULT "inv_l_rcv_err_powerfault"
#define INV_L_RCV_LMT_ACTIVE_2 "inv_l_rcv_lmt_active_2"
#define INV_L_RCV_KM_SPEED_0 "inv_l_rcv_km_speed_0"
#define INV_L_RCV_NCR082 "inv_l_rcv_ncr082"
#define INV_L_RCV_LIM_PLUS64 "inv_l_rcv_lim_plus64"
#define INV_L_RCV_ERR_RFE_FAULT "inv_l_rcv_err_rfe_fault"
#define INV_L_RCV_IN_ACTIVE_2 "inv_l_rcv_in_active_2"
#define INV_L_RCV_KM_FRG_OFF "inv_l_rcv_km_frg_off"
#define INV_L_RCV_LIM_PLUS82 "inv_l_rcv_lim_plus82"
#define INV_L_RCV_LIM_MINUS64 "inv_l_rcv_lim_minus64"
#define INV_L_RCV_ERR_BUSTIMEOUT "inv_l_rcv_err_bustimeout"
#define INV_L_RCV_IN_ACTIVE_1 "inv_l_rcv_in_active_1"
#define INV_L_RCV_KM_CAL_OFF "inv_l_rcv_km_cal_off"
#define INV_L_RCV_LIM_MINUS82 "inv_l_rcv_lim_minus82"
#define INV_L_RCV_OK64 "inv_l_rcv_ok64"
#define INV_L_RCV_ERR_FEEDBACKSIGNAL "inv_l_rcv_err_feedbacksignal"
#define INV_L_RCV_FRGRUN "inv_l_rcv_frgrun"
#define INV_L_RCV_KM_TX_TOG_STAT "inv_l_rcv_km_tx_tog_stat"
#define INV_L_RCV_OK82 "inv_l_rcv_ok82"
#define INV_L_RCV_ICNS64 "inv_l_rcv_icns64"
#define INV_L_RCV_ERR_POWERVOLTAGE_LOW "inv_l_rcv_err_powervoltage_low"
#define INV_L_RCV_RFE216 "inv_l_rcv_rfe216"
#define INV_L_RCV_KM_I_LIMIT "inv_l_rcv_km_i_limit"
#define INV_L_RCV_ICNS82 "inv_l_rcv_icns82"
#define INV_L_RCV_TNLIM64 "inv_l_rcv_tnlim64"
#define INV_L_RCV_ERR_MOTORTEMP "inv_l_rcv_err_motortemp"
#define INV_L_RCV_KM_N_CLIP "inv_l_rcv_km_n_clip"
#define INV_L_RCV_TNLIM82 "inv_l_rcv_tnlim82"
#define INV_L_RCV_PN64 "inv_l_rcv_pn64"
#define INV_L_RCV_ERR_DEVICETEMP "inv_l_rcv_err_devicetemp"
#define INV_L_RCV_KM_MIX_ANA_ON "inv_l_rcv_km_mix_ana_on"
#define INV_L_RCV_PN82 "inv_l_rcv_pn82"
#define INV_L_RCV_NI64 "inv_l_rcv_ni64"
#define INV_L_RCV_ERR_OVERVOLTAGE "inv_l_rcv_err_overvoltage"
#define INV_L_RCV_D_OUT_1_ON "inv_l_rcv_d_out_1_on"
#define INV_L_RCV_KM_ALLOW_SYNC "inv_l_rcv_km_allow_sync"
#define INV_L_RCV_NI82 "inv_l_rcv_ni82"
#define INV_L_RCV__N064 "inv_l_rcv__n064"
#define INV_L_RCV_ERR_IPEAK "inv_l_rcv_err_ipeak"
#define INV_L_RCV_D_OUT_2_ON "inv_l_rcv_d_out_2_on"
#define INV_L_RCV_KM_HANDWHEEL "inv_l_rcv_km_handwheel"
#define INV_L_RCV__N082 "inv_l_rcv__n082"
#define INV_L_RCV_RSW64 "inv_l_rcv_rsw64"
#define INV_L_RCV_ERR_RACEAWAY "inv_l_rcv_err_raceaway"
#define INV_L_RCV_BTBRDY "inv_l_rcv_btbrdy"
#define INV_L_RCV_KM_PHASING_EXTEND "inv_l_rcv_km_phasing_extend"
#define INV_L_RCV_RSW82 "inv_l_rcv_rsw82"
#define INV_L_RCV_CAL064 "inv_l_rcv_cal064"
#define INV_L_RCV_ERR_USER "inv_l_rcv_err_user"
#define INV_L_RCV_GO216 "inv_l_rcv_go216"
#define INV_L_RCV_KM_RSVD_11 "inv_l_rcv_km_rsvd_11"
#define INV_L_RCV_CAL082 "inv_l_rcv_cal082"
#define INV_L_RCV_CAL64 "inv_l_rcv_cal64"
#define INV_L_RCV_D_OUT_3_ON "inv_l_rcv_d_out_3_on"
#define INV_L_RCV_KM_RSVD_12 "inv_l_rcv_km_rsvd_12"
#define INV_L_RCV_CAL82 "inv_l_rcv_cal82"
#define INV_L_RCV_TOL64 "inv_l_rcv_tol64"
#define INV_L_RCV_D_OUT_4_ON "inv_l_rcv_d_out_4_on"
#define INV_L_RCV_KM_RSVD_13 "inv_l_rcv_km_rsvd_13"
#define INV_L_RCV_TOL82 "inv_l_rcv_tol82"
#define INV_L_RCV_RDY64 "inv_l_rcv_rdy64"
#define INV_L_RCV_ERR_HWERR "inv_l_rcv_err_hwerr"
#define INV_L_RCV_GOFF "inv_l_rcv_goff"
#define INV_L_RCV_KM_PSEUDO_ENABLE "inv_l_rcv_km_pseudo_enable"
#define INV_L_RCV_RDY82 "inv_l_rcv_rdy82"
#define INV_L_RCV_BRK064 "inv_l_rcv_brk064"
#define INV_L_RCV_ERR_BALLAST "inv_l_rcv_err_ballast"
#define INV_L_RCV_ACTIVE190 "inv_l_rcv_active190"
#define INV_L_RCV_BRK1216 "inv_l_rcv_brk1216"
#define INV_L_RCV_KM_DEBUG_TEST "inv_l_rcv_km_debug_test"
#define INV_L_RCV_BRK082 "inv_l_rcv_brk082"
#define INV_L_RCV_ACTIVE192 "inv_l_rcv_active192"
#define INV_L_RCV_SIGNMAG64 "inv_l_rcv_signmag64"
#define INV_L_RCV_WARN_WARNING_0 "inv_l_rcv_warn_warning_0"
#define INV_L_RCV_SIGNMAG82 "inv_l_rcv_signmag82"
#define INV_L_RCV_FREE "inv_l_rcv_free"
#define INV_L_RCV_M_R_RCP "inv_l_rcv_m_r_rcp"
#define INV_L_RCV_NCLIP64 "inv_l_rcv_nclip64"
#define INV_L_RCV_WARN_ILLEGAL_STATUS "inv_l_rcv_warn_illegal_status"
#define INV_L_RCV_NCLIP82 "inv_l_rcv_nclip82"
#define INV_L_RCV_NCLIP_MINUS64 "inv_l_rcv_nclip_minus64"
#define INV_L_RCV_WARN_SAFE_IN "inv_l_rcv_warn_safe_in"
#define INV_L_RCV_NCLIP_MINUS82 "inv_l_rcv_nclip_minus82"
#define INV_L_RCV_NCLIP_PLUS64 "inv_l_rcv_nclip_plus64"
#define INV_L_RCV_NCLIP_PLUS82 "inv_l_rcv_nclip_plus82"
#define INV_L_RCV_IRDDIG64 "inv_l_rcv_irddig64"
#define INV_L_RCV_IRDDIG82 "inv_l_rcv_irddig82"
#define INV_L_RCV_IUSERCHD64 "inv_l_rcv_iuserchd64"
#define INV_L_RCV_IUSERCHD82 "inv_l_rcv_iuserchd82"
#define INV_L_RCV_IRDN64 "inv_l_rcv_irdn64"
#define INV_L_RCV_WARN_MOTORTEMP "inv_l_rcv_warn_motortemp"
#define INV_L_RCV_IRDN82 "inv_l_rcv_irdn82"
#define INV_L_RCV_IRDTI64 "inv_l_rcv_irdti64"
#define INV_L_RCV_WARN_DEVICETEMP "inv_l_rcv_warn_devicetemp"
#define INV_L_RCV_IRDTI82 "inv_l_rcv_irdti82"
#define INV_L_RCV_IRDTIR64 "inv_l_rcv_irdtir64"
#define INV_L_RCV_WARN_VOUT_SAT "inv_l_rcv_warn_vout_sat"
#define INV_L_RCV_IRDTIR82 "inv_l_rcv_irdtir82"
#define INV_L_RCV__10HZ64 "inv_l_rcv__10hz64"
#define INV_L_RCV_WARN_IPEAK "inv_l_rcv_warn_ipeak"
#define INV_L_RCV__10HZ82 "inv_l_rcv__10hz82"
#define INV_L_RCV_IRDTM64 "inv_l_rcv_irdtm64"
#define INV_L_RCV_WARN_RACEAWAY "inv_l_rcv_warn_raceaway"
#define INV_L_RCV_IRDTM82 "inv_l_rcv_irdtm82"
#define INV_L_RCV_IRDANA64 "inv_l_rcv_irdana64"
#define INV_L_RCV_IRDANA82 "inv_l_rcv_irdana82"
#define INV_L_RCV_IWCNS64 "inv_l_rcv_iwcns64"
#define INV_L_RCV_IWCNS82 "inv_l_rcv_iwcns82"
#define INV_L_RCV_RFEPULSE64 "inv_l_rcv_rfepulse64"
#define INV_L_RCV_RFEPULSE82 "inv_l_rcv_rfepulse82"
#define INV_L_RCV_MD64 "inv_l_rcv_md64"
#define INV_L_RCV_MD82 "inv_l_rcv_md82"
#define INV_L_RCV_HNDWHL64 "inv_l_rcv_hndwhl64"
#define INV_L_RCV_WARN_BALLAST "inv_l_rcv_warn_ballast"
#define INV_L_RCV_HNDWHL82 "inv_l_rcv_hndwhl82"
/* END */

/* START */
#define INV_R_SEND "INV_R_SEND"

#define INV_R_SEND_SEND_MUX "inv_r_send_send_mux"
#define INV_R_SEND_READ_ID "inv_r_send_read_id"
#define INV_R_SEND_KM_RSVD_0 "inv_r_send_km_rsvd_0"
#define INV_R_SEND_M_SETDIG__IQ "inv_r_send_m_setdig__iq"
#define INV_R_SEND_DEF_DIN_1 "inv_r_send_def_din_1"
#define INV_R_SEND_DEF_END_1 "inv_r_send_def_end_1"
#define INV_R_SEND_I_MAX_PK "inv_r_send_i_max_pk"
#define INV_R_SEND_I_CON_EFF "inv_r_send_i_con_eff"
#define INV_R_SEND_I_DEVICE "inv_r_send_i_device"
#define INV_R_SEND_N_R_LIM "inv_r_send_n_r_lim"
#define INV_R_SEND_NMAX100PERC "inv_r_send_nmax100perc"
#define INV_R_SEND_KM_SPEED_0 "inv_r_send_km_speed_0"
#define INV_R_SEND_KM_FRG_OFF "inv_r_send_km_frg_off"
#define INV_R_SEND_KM_CAL_OFF "inv_r_send_km_cal_off"
#define INV_R_SEND_KM_TX_TOG_STAT "inv_r_send_km_tx_tog_stat"
#define INV_R_SEND_KM_I_LIMIT "inv_r_send_km_i_limit"
#define INV_R_SEND_KM_N_CLIP "inv_r_send_km_n_clip"
#define INV_R_SEND_KM_MIX_ANA_ON "inv_r_send_km_mix_ana_on"
#define INV_R_SEND_RET_INTERVAL "inv_r_send_ret_interval"
#define INV_R_SEND_KM_ALLOW_SYNC "inv_r_send_km_allow_sync"
#define INV_R_SEND_KM_HANDWHEEL "inv_r_send_km_handwheel"
#define INV_R_SEND_KM_PHASING_EXTEND "inv_r_send_km_phasing_extend"
#define INV_R_SEND_KM_RSVD_11 "inv_r_send_km_rsvd_11"
#define INV_R_SEND_KM_RSVD_12 "inv_r_send_km_rsvd_12"
#define INV_R_SEND_KM_RSVD_13 "inv_r_send_km_rsvd_13"
#define INV_R_SEND_KM_PSEUDO_ENABLE "inv_r_send_km_pseudo_enable"
#define INV_R_SEND_KM_DEBUG_TEST "inv_r_send_km_debug_test"
#define INV_R_SEND_ACTIVE192 "inv_r_send_active192"
#define INV_R_SEND_ACTIVE190 "inv_r_send_active190"
#define INV_R_SEND_M_R_RCP "inv_r_send_m_r_rcp"
/* END */

/* START */
#define INV_R_RCV "INV_R_RCV"

#define INV_R_RCV_RCV_MUX "inv_r_rcv_rcv_mux"
#define INV_R_RCV_N_ACTUAL_FILT "inv_r_rcv_n_actual_filt"
#define INV_R_RCV_ENA64 "inv_r_rcv_ena64"
#define INV_R_RCV_ERR_BADPARAS "inv_r_rcv_err_badparas"
#define INV_R_RCV_DEF_END_1 "inv_r_rcv_def_end_1"
#define INV_R_RCV_LMT_ACTIVE_1 "inv_r_rcv_lmt_active_1"
#define INV_R_RCV_I_CMD "inv_r_rcv_i_cmd"
#define INV_R_RCV_I_CMD_RAMP "inv_r_rcv_i_cmd_ramp"
#define INV_R_RCV_IQ_ACTUAL "inv_r_rcv_iq_actual"
#define INV_R_RCV_T_MOTOR "inv_r_rcv_t_motor"
#define INV_R_RCV_T_IGBT "inv_r_rcv_t_igbt"
#define INV_R_RCV_VDC_BUS_FILT "inv_r_rcv_vdc_bus_filt"
#define INV_R_RCV_KM_RSVD_0 "inv_r_rcv_km_rsvd_0"
#define INV_R_RCV_ENA82 "inv_r_rcv_ena82"
#define INV_R_RCV_DEF_DIN_1 "inv_r_rcv_def_din_1"
#define INV_R_RCV_M_CMD_RAMP "inv_r_rcv_m_cmd_ramp"
#define INV_R_RCV_I_MAX_PK "inv_r_rcv_i_max_pk"
#define INV_R_RCV_I_CON_EFF "inv_r_rcv_i_con_eff"
#define INV_R_RCV_I_DEVICE "inv_r_rcv_i_device"
#define INV_R_RCV_N_R_LIM "inv_r_rcv_n_r_lim"
#define INV_R_RCV_NMAX100PERC "inv_r_rcv_nmax100perc"
#define INV_R_RCV_NCR064 "inv_r_rcv_ncr064"
#define INV_R_RCV_ERR_POWERFAULT "inv_r_rcv_err_powerfault"
#define INV_R_RCV_LMT_ACTIVE_2 "inv_r_rcv_lmt_active_2"
#define INV_R_RCV_KM_SPEED_0 "inv_r_rcv_km_speed_0"
#define INV_R_RCV_NCR082 "inv_r_rcv_ncr082"
#define INV_R_RCV_LIM_PLUS64 "inv_r_rcv_lim_plus64"
#define INV_R_RCV_ERR_RFE_FAULT "inv_r_rcv_err_rfe_fault"
#define INV_R_RCV_IN_ACTIVE_2 "inv_r_rcv_in_active_2"
#define INV_R_RCV_KM_FRG_OFF "inv_r_rcv_km_frg_off"
#define INV_R_RCV_LIM_PLUS82 "inv_r_rcv_lim_plus82"
#define INV_R_RCV_LIM_MINUS64 "inv_r_rcv_lim_minus64"
#define INV_R_RCV_ERR_BUSTIMEOUT "inv_r_rcv_err_bustimeout"
#define INV_R_RCV_IN_ACTIVE_1 "inv_r_rcv_in_active_1"
#define INV_R_RCV_KM_CAL_OFF "inv_r_rcv_km_cal_off"
#define INV_R_RCV_LIM_MINUS82 "inv_r_rcv_lim_minus82"
#define INV_R_RCV_OK64 "inv_r_rcv_ok64"
#define INV_R_RCV_ERR_FEEDBACKSIGNAL "inv_r_rcv_err_feedbacksignal"
#define INV_R_RCV_FRGRUN "inv_r_rcv_frgrun"
#define INV_R_RCV_KM_TX_TOG_STAT "inv_r_rcv_km_tx_tog_stat"
#define INV_R_RCV_OK82 "inv_r_rcv_ok82"
#define INV_R_RCV_ICNS64 "inv_r_rcv_icns64"
#define INV_R_RCV_ERR_POWERVOLTAGE_LOW "inv_r_rcv_err_powervoltage_low"
#define INV_R_RCV_RFE216 "inv_r_rcv_rfe216"
#define INV_R_RCV_KM_I_LIMIT "inv_r_rcv_km_i_limit"
#define INV_R_RCV_ICNS82 "inv_r_rcv_icns82"
#define INV_R_RCV_TNLIM64 "inv_r_rcv_tnlim64"
#define INV_R_RCV_ERR_MOTORTEMP "inv_r_rcv_err_motortemp"
#define INV_R_RCV_KM_N_CLIP "inv_r_rcv_km_n_clip"
#define INV_R_RCV_TNLIM82 "inv_r_rcv_tnlim82"
#define INV_R_RCV_PN64 "inv_r_rcv_pn64"
#define INV_R_RCV_ERR_DEVICETEMP "inv_r_rcv_err_devicetemp"
#define INV_R_RCV_KM_MIX_ANA_ON "inv_r_rcv_km_mix_ana_on"
#define INV_R_RCV_PN82 "inv_r_rcv_pn82"
#define INV_R_RCV_NI64 "inv_r_rcv_ni64"
#define INV_R_RCV_ERR_OVERVOLTAGE "inv_r_rcv_err_overvoltage"
#define INV_R_RCV_D_OUT_1_ON "inv_r_rcv_d_out_1_on"
#define INV_R_RCV_KM_ALLOW_SYNC "inv_r_rcv_km_allow_sync"
#define INV_R_RCV_NI82 "inv_r_rcv_ni82"
#define INV_R_RCV__N064 "inv_r_rcv__n064"
#define INV_R_RCV_ERR_IPEAK "inv_r_rcv_err_ipeak"
#define INV_R_RCV_D_OUT_2_ON "inv_r_rcv_d_out_2_on"
#define INV_R_RCV_KM_HANDWHEEL "inv_r_rcv_km_handwheel"
#define INV_R_RCV__N082 "inv_r_rcv__n082"
#define INV_R_RCV_RSW64 "inv_r_rcv_rsw64"
#define INV_R_RCV_ERR_RACEAWAY "inv_r_rcv_err_raceaway"
#define INV_R_RCV_BTBRDY "inv_r_rcv_btbrdy"
#define INV_R_RCV_KM_PHASING_EXTEND "inv_r_rcv_km_phasing_extend"
#define INV_R_RCV_RSW82 "inv_r_rcv_rsw82"
#define INV_R_RCV_CAL064 "inv_r_rcv_cal064"
#define INV_R_RCV_ERR_USER "inv_r_rcv_err_user"
#define INV_R_RCV_GO216 "inv_r_rcv_go216"
#define INV_R_RCV_KM_RSVD_11 "inv_r_rcv_km_rsvd_11"
#define INV_R_RCV_CAL082 "inv_r_rcv_cal082"
#define INV_R_RCV_CAL64 "inv_r_rcv_cal64"
#define INV_R_RCV_D_OUT_3_ON "inv_r_rcv_d_out_3_on"
#define INV_R_RCV_KM_RSVD_12 "inv_r_rcv_km_rsvd_12"
#define INV_R_RCV_CAL82 "inv_r_rcv_cal82"
#define INV_R_RCV_TOL64 "inv_r_rcv_tol64"
#define INV_R_RCV_D_OUT_4_ON "inv_r_rcv_d_out_4_on"
#define INV_R_RCV_KM_RSVD_13 "inv_r_rcv_km_rsvd_13"
#define INV_R_RCV_TOL82 "inv_r_rcv_tol82"
#define INV_R_RCV_RDY64 "inv_r_rcv_rdy64"
#define INV_R_RCV_ERR_HWERR "inv_r_rcv_err_hwerr"
#define INV_R_RCV_GOFF "inv_r_rcv_goff"
#define INV_R_RCV_KM_PSEUDO_ENABLE "inv_r_rcv_km_pseudo_enable"
#define INV_R_RCV_RDY82 "inv_r_rcv_rdy82"
#define INV_R_RCV_BRK064 "inv_r_rcv_brk064"
#define INV_R_RCV_ERR_BALLAST "inv_r_rcv_err_ballast"
#define INV_R_RCV_ACTIVE190 "inv_r_rcv_active190"
#define INV_R_RCV_BRK1216 "inv_r_rcv_brk1216"
#define INV_R_RCV_KM_DEBUG_TEST "inv_r_rcv_km_debug_test"
#define INV_R_RCV_BRK082 "inv_r_rcv_brk082"
#define INV_R_RCV_ACTIVE192 "inv_r_rcv_active192"
#define INV_R_RCV_SIGNMAG64 "inv_r_rcv_signmag64"
#define INV_R_RCV_WARN_WARNING_0 "inv_r_rcv_warn_warning_0"
#define INV_R_RCV_SIGNMAG82 "inv_r_rcv_signmag82"
#define INV_R_RCV_FREE "inv_r_rcv_free"
#define INV_R_RCV_M_R_RCP "inv_r_rcv_m_r_rcp"
#define INV_R_RCV_NCLIP64 "inv_r_rcv_nclip64"
#define INV_R_RCV_WARN_ILLEGAL_STATUS "inv_r_rcv_warn_illegal_status"
#define INV_R_RCV_NCLIP82 "inv_r_rcv_nclip82"
#define INV_R_RCV_NCLIP_MINUS64 "inv_r_rcv_nclip_minus64"
#define INV_R_RCV_WARN_SAFE_IN "inv_r_rcv_warn_safe_in"
#define INV_R_RCV_NCLIP_MINUS82 "inv_r_rcv_nclip_minus82"
#define INV_R_RCV_NCLIP_PLUS64 "inv_r_rcv_nclip_plus64"
#define INV_R_RCV_NCLIP_PLUS82 "inv_r_rcv_nclip_plus82"
#define INV_R_RCV_IRDDIG64 "inv_r_rcv_irddig64"
#define INV_R_RCV_IRDDIG82 "inv_r_rcv_irddig82"
#define INV_R_RCV_IUSERCHD64 "inv_r_rcv_iuserchd64"
#define INV_R_RCV_IUSERCHD82 "inv_r_rcv_iuserchd82"
#define INV_R_RCV_IRDN64 "inv_r_rcv_irdn64"
#define INV_R_RCV_WARN_MOTORTEMP "inv_r_rcv_warn_motortemp"
#define INV_R_RCV_IRDN82 "inv_r_rcv_irdn82"
#define INV_R_RCV_IRDTI64 "inv_r_rcv_irdti64"
#define INV_R_RCV_WARN_DEVICETEMP "inv_r_rcv_warn_devicetemp"
#define INV_R_RCV_IRDTI82 "inv_r_rcv_irdti82"
#define INV_R_RCV_IRDTIR64 "inv_r_rcv_irdtir64"
#define INV_R_RCV_WARN_VOUT_SAT "inv_r_rcv_warn_vout_sat"
#define INV_R_RCV_IRDTIR82 "inv_r_rcv_irdtir82"
#define INV_R_RCV__10HZ64 "inv_r_rcv__10hz64"
#define INV_R_RCV_WARN_IPEAK "inv_r_rcv_warn_ipeak"
#define INV_R_RCV__10HZ82 "inv_r_rcv__10hz82"
#define INV_R_RCV_IRDTM64 "inv_r_rcv_irdtm64"
#define INV_R_RCV_WARN_RACEAWAY "inv_r_rcv_warn_raceaway"
#define INV_R_RCV_IRDTM82 "inv_r_rcv_irdtm82"
#define INV_R_RCV_IRDANA64 "inv_r_rcv_irdana64"
#define INV_R_RCV_IRDANA82 "inv_r_rcv_irdana82"
#define INV_R_RCV_IWCNS64 "inv_r_rcv_iwcns64"
#define INV_R_RCV_IWCNS82 "inv_r_rcv_iwcns82"
#define INV_R_RCV_RFEPULSE64 "inv_r_rcv_rfepulse64"
#define INV_R_RCV_RFEPULSE82 "inv_r_rcv_rfepulse82"
#define INV_R_RCV_MD64 "inv_r_rcv_md64"
#define INV_R_RCV_MD82 "inv_r_rcv_md82"
#define INV_R_RCV_HNDWHL64 "inv_r_rcv_hndwhl64"
#define INV_R_RCV_WARN_BALLAST "inv_r_rcv_warn_ballast"
#define INV_R_RCV_HNDWHL82 "inv_r_rcv_hndwhl82"
/* END */

enum inverters_types_id{
	e_inverters_uint8_t = -4,
	e_inverters_uint16_t,
	e_inverters_float,
	e_inverters_int16_t,

	e_inverters_inv_l_send_send_mux,
	e_inverters_inv_l_send_read_id,
	e_inverters_inv_l_send_def_din_1,
	e_inverters_inv_l_send_def_end_1,
	e_inverters_inv_l_send_ret_interval,
	e_inverters_inv_l_send_active192,
	e_inverters_inv_l_send_active190,
	e_inverters_inv_l_rcv_rcv_mux,
	e_inverters_inv_l_rcv_def_end_1,
	e_inverters_inv_l_rcv_def_din_1,
	e_inverters_inv_l_rcv_active190,
	e_inverters_inv_l_rcv_active192,
	e_inverters_inv_r_send_send_mux,
	e_inverters_inv_r_send_read_id,
	e_inverters_inv_r_send_def_din_1,
	e_inverters_inv_r_send_def_end_1,
	e_inverters_inv_r_send_ret_interval,
	e_inverters_inv_r_send_active192,
	e_inverters_inv_r_send_active190,
	e_inverters_inv_r_rcv_rcv_mux,
	e_inverters_inv_r_rcv_def_end_1,
	e_inverters_inv_r_rcv_def_din_1,
	e_inverters_inv_r_rcv_active190,
	e_inverters_inv_r_rcv_active192
};

/**
 * @brief get the name of the signals in the message
 * 
 * @param[in] id message id
 * @param[out] v array of strings containing the name of the signals
 * @param[in] fields_size maximum size of v
 * @param[in] string_size maximum size of v[i]
 * 
 * @return 0 if ok 1 otherwise
*/
int inverters_fields_string_from_id(int id, char **v, size_t fields_size, size_t string_size);

/**
 * @brief get the fields of an enum given the id of the enum (get the id from fields_types_from_id)
 * 
 * @param[in] enum_id the id of the enum, you can get it from fields_types_from_id
 * @param[out] v array of strings containing the enum fields
 * @param[in] fields_size maximum size of v
 * @param[in] string_size maximum size of v[i]
 * 
 * @return 0 if ok 1 otherwise
*/
int inverters_enum_fields(int enum_id, char **v, size_t fields_size, size_t string_size);

/**
 * @brief serialize to a data pointer from a message id
 * 
 * @param[in] id message id
 * @param[in] s string containing the data to serialize (comma separated)
 * @param[out] data pointer to the serialized data
 * @param[out] size size of the message
 * 
 * @return Size of packed data, or negative error code.
*/
int inverters_serialize_from_string(int id, char *s, uint8_t *data, size_t *size);

/**
 * @brief get the number of signals in the message
 * 
 * @param[in] id the id of the message
 * 
 * @return return the number of the signals
*/
int inverters_n_fields_from_id(int id);

/**
 * @brief get the types of the signals in the message
 * 
 * @param[in] id the id of the message
 * @param[out] fields_types fields_types[i] contains the type id of the signal i (must be already allocated)
 * @param[in] fields_types_size max size of fields_types
 * 
 * @return the number of types set, 0 if the id is invalid or fields_types_size is too small
*/
int inverters_fields_types_from_id(int id, int* fields_types, int fields_types_size);

/**
 * @brief get the fields of an enum given the name of the message and the name of the signal
 * 
 * @param[in] msg_name name of the message to find
 * @param[in] sgn_name name of the signal to find
 * @param[out] v array of strings containing the enum fields
 * 
 * @return the number of fields or 0 if the signal is not an enum
*/
int inverters_enum_fields_from_name(const char *msg_name, const char *sgn_name, char **v);


#ifdef __cplusplus
}
#endif

#endif
