#ifndef primary_UTILS_H
#define primary_UTILS_H

#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "primary_network.h"

#ifdef __cplusplus
extern "C" {
#endif

/* START */
#define NLG5_DIAG_TX "NLG5_DIAG_TX"

#define NLG5_DIAG_TX_LAD_D_PARAMRP "nlg5_diag_tx_lad_d_paramrp"
/* END */

/* START */
#define NLG5_DIAG_RX "NLG5_DIAG_RX"

#define NLG5_DIAG_RX_LAD_D_PARAMRQ "nlg5_diag_rx_lad_d_paramrq"
/* END */

/* START */
#define NLG5_ERR "NLG5_ERR"

#define NLG5_ERR_NLG5_E_OOV "nlg5_err_nlg5_e_oov"
#define NLG5_ERR_NLG5_E_MOV_II "nlg5_err_nlg5_e_mov_ii"
#define NLG5_ERR_NLG5_E_MOV_I "nlg5_err_nlg5_e_mov_i"
#define NLG5_ERR_NLG5_E_SC "nlg5_err_nlg5_e_sc"
#define NLG5_ERR_NLG5_E_P_OM "nlg5_err_nlg5_e_p_om"
#define NLG5_ERR_NLG5_E_P_MV "nlg5_err_nlg5_e_p_mv"
#define NLG5_ERR_NLG5_E_OF "nlg5_err_nlg5_e_of"
#define NLG5_ERR_NLG5_E_MF "nlg5_err_nlg5_e_mf"
#define NLG5_ERR_NLG5_E_B_P "nlg5_err_nlg5_e_b_p"
#define NLG5_ERR_NLG5_E_T_C "nlg5_err_nlg5_e_t_c"
#define NLG5_ERR_NLG5_E_T_POW "nlg5_err_nlg5_e_t_pow"
#define NLG5_ERR_NLG5_E_T_DIO "nlg5_err_nlg5_e_t_dio"
#define NLG5_ERR_NLG5_E_T_TR "nlg5_err_nlg5_e_t_tr"
#define NLG5_ERR_NLG5_E_T_EXT1 "nlg5_err_nlg5_e_t_ext1"
#define NLG5_ERR_NLG5_E_T_EXT2 "nlg5_err_nlg5_e_t_ext2"
#define NLG5_ERR_NLG5_E_T_EXT3 "nlg5_err_nlg5_e_t_ext3"
#define NLG5_ERR_NLG5_E_F_CRC "nlg5_err_nlg5_e_f_crc"
#define NLG5_ERR_NLG5_E_NV_CRC "nlg5_err_nlg5_e_nv_crc"
#define NLG5_ERR_NLG5_E_ES_CRC "nlg5_err_nlg5_e_es_crc"
#define NLG5_ERR_NLG5_E_EP_CRC "nlg5_err_nlg5_e_ep_crc"
#define NLG5_ERR_NLG5_E_WDT "nlg5_err_nlg5_e_wdt"
#define NLG5_ERR_NLG5_E_INIT "nlg5_err_nlg5_e_init"
#define NLG5_ERR_NLG5_E_C_TO "nlg5_err_nlg5_e_c_to"
#define NLG5_ERR_NLG5_E_C_OFF "nlg5_err_nlg5_e_c_off"
#define NLG5_ERR_NLG5_E_C_TX "nlg5_err_nlg5_e_c_tx"
#define NLG5_ERR_NLG5_E_C_RX "nlg5_err_nlg5_e_c_rx"
#define NLG5_ERR_NLG5_E_SDT_BT "nlg5_err_nlg5_e_sdt_bt"
#define NLG5_ERR_NLG5_E_SDT_BV "nlg5_err_nlg5_e_sdt_bv"
#define NLG5_ERR_NLG5_E_SDT_AH "nlg5_err_nlg5_e_sdt_ah"
#define NLG5_ERR_NLG5_E_SDT_CT "nlg5_err_nlg5_e_sdt_ct"
#define NLG5_ERR_NLG5_W_PL_MV "nlg5_err_nlg5_w_pl_mv"
#define NLG5_ERR_NLG5_W_PL_BV "nlg5_err_nlg5_w_pl_bv"
#define NLG5_ERR_NLG5_W_PL_IT "nlg5_err_nlg5_w_pl_it"
#define NLG5_ERR_NLG5_W_C_VOR "nlg5_err_nlg5_w_c_vor"
#define NLG5_ERR_NLG5_W_CM_NA "nlg5_err_nlg5_w_cm_na"
#define NLG5_ERR_NLG5_W_OD "nlg5_err_nlg5_w_od"
#define NLG5_ERR_NLG5_W_SC_M "nlg5_err_nlg5_w_sc_m"
/* END */

/* START */
#define NLG5_TEMP "NLG5_TEMP"

#define NLG5_TEMP_NLG5_P_TMP "nlg5_temp_nlg5_p_tmp"
#define NLG5_TEMP_NLG5_TMP_EXT1 "nlg5_temp_nlg5_tmp_ext1"
#define NLG5_TEMP_NLG5_TEMP_EXT2 "nlg5_temp_nlg5_temp_ext2"
#define NLG5_TEMP_NLG5_TMP_EXT3 "nlg5_temp_nlg5_tmp_ext3"
/* END */

/* START */
#define NLG5_ACT_II "NLG5_ACT_II"

#define NLG5_ACT_II_NLG5_S_MC_M_CP "nlg5_act_ii_nlg5_s_mc_m_cp"
#define NLG5_ACT_II_NLG5_S_MC_M_PI "nlg5_act_ii_nlg5_s_mc_m_pi"
#define NLG5_ACT_II_NLG5_ABV "nlg5_act_ii_nlg5_abv"
#define NLG5_ACT_II_NLG5_AHC_EXT "nlg5_act_ii_nlg5_ahc_ext"
#define NLG5_ACT_II_NLG5_OC_BO "nlg5_act_ii_nlg5_oc_bo"
/* END */

/* START */
#define NLG5_ACT_I "NLG5_ACT_I"

#define NLG5_ACT_I_NLG5_MC_ACT "nlg5_act_i_nlg5_mc_act"
#define NLG5_ACT_I_NLG5_MV_ACT "nlg5_act_i_nlg5_mv_act"
#define NLG5_ACT_I_NLG5_OV_ACT "nlg5_act_i_nlg5_ov_act"
#define NLG5_ACT_I_NLG5_OC_ACT "nlg5_act_i_nlg5_oc_act"
/* END */

/* START */
#define NLG5_ST "NLG5_ST"

#define NLG5_ST_NLG5_S_HE "nlg5_st_nlg5_s_he"
#define NLG5_ST_NLG5_S_ERR "nlg5_st_nlg5_s_err"
#define NLG5_ST_NLG5_S_WAR "nlg5_st_nlg5_s_war"
#define NLG5_ST_NLG5_S_FAN "nlg5_st_nlg5_s_fan"
#define NLG5_ST_NLG5_S_EUM "nlg5_st_nlg5_s_eum"
#define NLG5_ST_NLG5_S_UM_I "nlg5_st_nlg5_s_um_i"
#define NLG5_ST_NLG5_S_UM_II "nlg5_st_nlg5_s_um_ii"
#define NLG5_ST_NLG5_S_CP_DT "nlg5_st_nlg5_s_cp_dt"
#define NLG5_ST_NLG5_S_BPD_I "nlg5_st_nlg5_s_bpd_i"
#define NLG5_ST_NLG5_S_BPD_II "nlg5_st_nlg5_s_bpd_ii"
#define NLG5_ST_NLG5_S_L_OV "nlg5_st_nlg5_s_l_ov"
#define NLG5_ST_NLG5_S_L_OC "nlg5_st_nlg5_s_l_oc"
#define NLG5_ST_NLG5_S_L_MC "nlg5_st_nlg5_s_l_mc"
#define NLG5_ST_NLG5_S_L_PI "nlg5_st_nlg5_s_l_pi"
#define NLG5_ST_NLG5_S_L_CP "nlg5_st_nlg5_s_l_cp"
#define NLG5_ST_NLG5_S_L_PMAX "nlg5_st_nlg5_s_l_pmax"
#define NLG5_ST_NLG5_S_L_MC_MAX "nlg5_st_nlg5_s_l_mc_max"
#define NLG5_ST_NLG5_S_L_OC_MAX "nlg5_st_nlg5_s_l_oc_max"
#define NLG5_ST_NLG5_S_L_MO_MAX "nlg5_st_nlg5_s_l_mo_max"
#define NLG5_ST_NLG5_S_L_T_CPRIM "nlg5_st_nlg5_s_l_t_cprim"
#define NLG5_ST_NLG5_S_L_T_POW "nlg5_st_nlg5_s_l_t_pow"
#define NLG5_ST_NLG5_S_L_T_DIO "nlg5_st_nlg5_s_l_t_dio"
#define NLG5_ST_NLG5_S_L_T_TR "nlg5_st_nlg5_s_l_t_tr"
#define NLG5_ST_NLG5_S_L_T_BATT "nlg5_st_nlg5_s_l_t_batt"
#define NLG5_ST_NLG5_S_AAC "nlg5_st_nlg5_s_aac"
/* END */

/* START */
#define NLG5_CTL "NLG5_CTL"

#define NLG5_CTL_NLG5_C_C_EN "nlg5_ctl_nlg5_c_c_en"
#define NLG5_CTL_NLG5_C_C_EL "nlg5_ctl_nlg5_c_c_el"
#define NLG5_CTL_NLG5_C_CP_V "nlg5_ctl_nlg5_c_cp_v"
#define NLG5_CTL_NLG5_C_MR "nlg5_ctl_nlg5_c_mr"
#define NLG5_CTL_NLG5_MC_MAX "nlg5_ctl_nlg5_mc_max"
#define NLG5_CTL_NLG5_OV_COM "nlg5_ctl_nlg5_ov_com"
#define NLG5_CTL_NLG5_OC_COM "nlg5_ctl_nlg5_oc_com"
/* END */

/* START */
#define HV_JMP_TO_BLT "HV_JMP_TO_BLT"

#define HV_JMP_TO_BLT_FORWARD "hv_jmp_to_blt_forward"
#define HV_JMP_TO_BLT_CELLBOARD_ID "hv_jmp_to_blt_cellboard_id"
/* END */

/* START */
#define HV_FLASH_MAINBOARD_TX "HV_FLASH_MAINBOARD_TX"

/* END */

/* START */
#define HV_FLASH_MAINBOARD_RX "HV_FLASH_MAINBOARD_RX"

/* END */

/* START */
#define HV_FLASH_CELLBOARD_0_TX "HV_FLASH_CELLBOARD_0_TX"

/* END */

/* START */
#define HV_FLASH_CELLBOARD_0_RX "HV_FLASH_CELLBOARD_0_RX"

/* END */

/* START */
#define HV_FLASH_CELLBOARD_1_TX "HV_FLASH_CELLBOARD_1_TX"

/* END */

/* START */
#define HV_FLASH_CELLBOARD_1_RX "HV_FLASH_CELLBOARD_1_RX"

/* END */

/* START */
#define HV_FLASH_CELLBOARD_2_TX "HV_FLASH_CELLBOARD_2_TX"

/* END */

/* START */
#define HV_FLASH_CELLBOARD_2_RX "HV_FLASH_CELLBOARD_2_RX"

/* END */

/* START */
#define HV_FLASH_CELLBOARD_3_TX "HV_FLASH_CELLBOARD_3_TX"

/* END */

/* START */
#define HV_FLASH_CELLBOARD_3_RX "HV_FLASH_CELLBOARD_3_RX"

/* END */

/* START */
#define HV_FLASH_CELLBOARD_4_TX "HV_FLASH_CELLBOARD_4_TX"

/* END */

/* START */
#define HV_FLASH_CELLBOARD_4_RX "HV_FLASH_CELLBOARD_4_RX"

/* END */

/* START */
#define HV_FLASH_CELLBOARD_5_TX "HV_FLASH_CELLBOARD_5_TX"

/* END */

/* START */
#define HV_FLASH_CELLBOARD_5_RX "HV_FLASH_CELLBOARD_5_RX"

/* END */

/* START */
#define LV_JMP_TO_BLT "LV_JMP_TO_BLT"

/* END */

/* START */
#define LV_FLASH_TX "LV_FLASH_TX"

/* END */

/* START */
#define LV_FLASH_RX "LV_FLASH_RX"

/* END */

/* START */
#define ECU_JMP_TO_BLT "ECU_JMP_TO_BLT"

/* END */

/* START */
#define ECU_FLASH_TX "ECU_FLASH_TX"

/* END */

/* START */
#define ECU_FLASH_RX "ECU_FLASH_RX"

/* END */

/* START */
#define STEERING_WHEEL_JMP_TO_BLT "STEERING_WHEEL_JMP_TO_BLT"

/* END */

/* START */
#define STEERING_WHEEL_FLASH_TX "STEERING_WHEEL_FLASH_TX"

/* END */

/* START */
#define STEERING_WHEEL_FLASH_RX "STEERING_WHEEL_FLASH_RX"

/* END */

/* START */
#define STEERING_WHEEL_VERSION "STEERING_WHEEL_VERSION"

#define STEERING_WHEEL_VERSION_COMPONENT_BUILD_TIME "steering_wheel_version_component_build_time"
#define STEERING_WHEEL_VERSION_CANLIB_BUILD_TIME "steering_wheel_version_canlib_build_time"
/* END */

/* START */
#define ECU_VERSION "ECU_VERSION"

#define ECU_VERSION_COMPONENT_BUILD_TIME "ecu_version_component_build_time"
#define ECU_VERSION_CANLIB_BUILD_TIME "ecu_version_canlib_build_time"
/* END */

/* START */
#define LV_VERSION "LV_VERSION"

#define LV_VERSION_COMPONENT_BUILD_TIME "lv_version_component_build_time"
#define LV_VERSION_CANLIB_BUILD_TIME "lv_version_canlib_build_time"
/* END */

/* START */
#define TLM_VERSION "TLM_VERSION"

#define TLM_VERSION_COMPONENT_BUILD_TIME "tlm_version_component_build_time"
#define TLM_VERSION_CANLIB_BUILD_TIME "tlm_version_canlib_build_time"
/* END */

/* START */
#define HV_MAINBOARD_VERSION "HV_MAINBOARD_VERSION"

#define HV_MAINBOARD_VERSION_COMPONENT_BUILD_TIME "hv_mainboard_version_component_build_time"
#define HV_MAINBOARD_VERSION_CANLIB_BUILD_TIME "hv_mainboard_version_canlib_build_time"
/* END */

/* START */
#define HV_CELLBOARD_VERSION "HV_CELLBOARD_VERSION"

#define HV_CELLBOARD_VERSION_CELLBOARD_ID "hv_cellboard_version_cellboard_id"
#define HV_CELLBOARD_VERSION_COMPONENT_VERSION "hv_cellboard_version_component_version"
#define HV_CELLBOARD_VERSION_CANLIB_BUILD_TIME "hv_cellboard_version_canlib_build_time"
/* END */

/* START */
#define HV_ERRORS "HV_ERRORS"

#define HV_ERRORS_ERRORS_CELL_UNDER_VOLTAGE "hv_errors_errors_cell_under_voltage"
#define HV_ERRORS_ERRORS_CELL_OVER_VOLTAGE "hv_errors_errors_cell_over_voltage"
#define HV_ERRORS_ERRORS_CELL_UNDER_TEMPERATURE "hv_errors_errors_cell_under_temperature"
#define HV_ERRORS_ERRORS_CELL_OVER_TEMPERATURE "hv_errors_errors_cell_over_temperature"
#define HV_ERRORS_ERRORS_OVER_CURRENT "hv_errors_errors_over_current"
#define HV_ERRORS_ERRORS_CAN "hv_errors_errors_can"
#define HV_ERRORS_ERRORS_INT_VOLTAGE_MISMATCH "hv_errors_errors_int_voltage_mismatch"
#define HV_ERRORS_ERRORS_CELLBOARD_COMM "hv_errors_errors_cellboard_comm"
#define HV_ERRORS_ERRORS_CELLBOARD_INTERNAL "hv_errors_errors_cellboard_internal"
#define HV_ERRORS_ERRORS_CONNECTOR_DISCONNECTED "hv_errors_errors_connector_disconnected"
#define HV_ERRORS_ERRORS_FANS_DISCONNECTED "hv_errors_errors_fans_disconnected"
#define HV_ERRORS_ERRORS_FEEDBACK "hv_errors_errors_feedback"
#define HV_ERRORS_ERRORS_FEEDBACK_CIRCUITRY "hv_errors_errors_feedback_circuitry"
#define HV_ERRORS_ERRORS_EEPROM_COMM "hv_errors_errors_eeprom_comm"
#define HV_ERRORS_ERRORS_EEPROM_WRITE "hv_errors_errors_eeprom_write"
/* END */

/* START */
#define HV_DEBUG_SIGNALS "HV_DEBUG_SIGNALS"

#define HV_DEBUG_SIGNALS_FEEDBACKS_IMPLAUSIBILITY_DETECTED "hv_debug_signals_feedbacks_implausibility_detected"
#define HV_DEBUG_SIGNALS_FEEDBACKS_IMD_COCKPIT "hv_debug_signals_feedbacks_imd_cockpit"
#define HV_DEBUG_SIGNALS_FEEDBACKS_TSAL_GREEN_FAULT_LATCHED "hv_debug_signals_feedbacks_tsal_green_fault_latched"
#define HV_DEBUG_SIGNALS_FEEDBACKS_BMS_COCKPIT "hv_debug_signals_feedbacks_bms_cockpit"
#define HV_DEBUG_SIGNALS_FEEDBACKS_EXT_LATCHED "hv_debug_signals_feedbacks_ext_latched"
#define HV_DEBUG_SIGNALS_FEEDBACKS_TSAL_GREEN "hv_debug_signals_feedbacks_tsal_green"
#define HV_DEBUG_SIGNALS_FEEDBACKS_TS_OVER_60V_STATUS "hv_debug_signals_feedbacks_ts_over_60v_status"
#define HV_DEBUG_SIGNALS_FEEDBACKS_AIRN_STATUS "hv_debug_signals_feedbacks_airn_status"
#define HV_DEBUG_SIGNALS_FEEDBACKS_AIRP_STATUS "hv_debug_signals_feedbacks_airp_status"
#define HV_DEBUG_SIGNALS_FEEDBACKS_AIRP_GATE "hv_debug_signals_feedbacks_airp_gate"
#define HV_DEBUG_SIGNALS_FEEDBACKS_AIRN_GATE "hv_debug_signals_feedbacks_airn_gate"
#define HV_DEBUG_SIGNALS_FEEDBACKS_PRECHARGE_STATUS "hv_debug_signals_feedbacks_precharge_status"
#define HV_DEBUG_SIGNALS_FEEDBACKS_TSP_OVER_60V_STATUS "hv_debug_signals_feedbacks_tsp_over_60v_status"
#define HV_DEBUG_SIGNALS_FEEDBACKS_IMD_FAULT "hv_debug_signals_feedbacks_imd_fault"
#define HV_DEBUG_SIGNALS_FEEDBACKS_CHECK_MUX "hv_debug_signals_feedbacks_check_mux"
#define HV_DEBUG_SIGNALS_FEEDBACKS_SD_END "hv_debug_signals_feedbacks_sd_end"
#define HV_DEBUG_SIGNALS_FEEDBACKS_SD_OUT "hv_debug_signals_feedbacks_sd_out"
#define HV_DEBUG_SIGNALS_FEEDBACKS_SD_IN "hv_debug_signals_feedbacks_sd_in"
#define HV_DEBUG_SIGNALS_FEEDBACKS_SD_BMS "hv_debug_signals_feedbacks_sd_bms"
#define HV_DEBUG_SIGNALS_FEEDBACKS_SD_IMD "hv_debug_signals_feedbacks_sd_imd"
#define HV_DEBUG_SIGNALS_ERRORS_CELL_UNDER_VOLTAGE "hv_debug_signals_errors_cell_under_voltage"
#define HV_DEBUG_SIGNALS_ERRORS_CELL_OVER_VOLTAGE "hv_debug_signals_errors_cell_over_voltage"
#define HV_DEBUG_SIGNALS_ERRORS_CELL_UNDER_TEMPERATURE "hv_debug_signals_errors_cell_under_temperature"
#define HV_DEBUG_SIGNALS_ERRORS_CELL_OVER_TEMPERATURE "hv_debug_signals_errors_cell_over_temperature"
#define HV_DEBUG_SIGNALS_ERRORS_OVER_CURRENT "hv_debug_signals_errors_over_current"
#define HV_DEBUG_SIGNALS_ERRORS_CAN "hv_debug_signals_errors_can"
#define HV_DEBUG_SIGNALS_ERRORS_INT_VOLTAGE_MISMATCH "hv_debug_signals_errors_int_voltage_mismatch"
#define HV_DEBUG_SIGNALS_ERRORS_CELLBOARD_COMM "hv_debug_signals_errors_cellboard_comm"
#define HV_DEBUG_SIGNALS_ERRORS_CELLBOARD_INTERNAL "hv_debug_signals_errors_cellboard_internal"
#define HV_DEBUG_SIGNALS_ERRORS_CONNECTOR_DISCONNECTED "hv_debug_signals_errors_connector_disconnected"
#define HV_DEBUG_SIGNALS_ERRORS_FANS_DISCONNECTED "hv_debug_signals_errors_fans_disconnected"
#define HV_DEBUG_SIGNALS_ERRORS_FEEDBACK "hv_debug_signals_errors_feedback"
#define HV_DEBUG_SIGNALS_ERRORS_FEEDBACK_CIRCUITRY "hv_debug_signals_errors_feedback_circuitry"
#define HV_DEBUG_SIGNALS_ERRORS_EEPROM_COMM "hv_debug_signals_errors_eeprom_comm"
#define HV_DEBUG_SIGNALS_ERRORS_EEPROM_WRITE "hv_debug_signals_errors_eeprom_write"
/* END */

/* START */
#define HV_FANS_STATUS "HV_FANS_STATUS"

#define HV_FANS_STATUS_FANS_OVERRIDE "hv_fans_status_fans_override"
#define HV_FANS_STATUS_FANS_SPEED "hv_fans_status_fans_speed"
/* END */

/* START */
#define HV_SET_FANS_STATUS "HV_SET_FANS_STATUS"

#define HV_SET_FANS_STATUS_FANS_OVERRIDE "hv_set_fans_status_fans_override"
#define HV_SET_FANS_STATUS_FANS_SPEED "hv_set_fans_status_fans_speed"
/* END */

/* START */
#define HV_FEEDBACK_STATUS "HV_FEEDBACK_STATUS"

#define HV_FEEDBACK_STATUS_FEEDBACK_IMPLAUSIBILITY_DETECTED "hv_feedback_status_feedback_implausibility_detected"
#define HV_FEEDBACK_STATUS_FEEDBACK_IMD_COCKPIT "hv_feedback_status_feedback_imd_cockpit"
#define HV_FEEDBACK_STATUS_FEEDBACK_TSAL_GREEN_FAULT_LATCHED "hv_feedback_status_feedback_tsal_green_fault_latched"
#define HV_FEEDBACK_STATUS_FEEDBACK_BMS_COCKPIT "hv_feedback_status_feedback_bms_cockpit"
#define HV_FEEDBACK_STATUS_FEEDBACK_EXT_LATCHED "hv_feedback_status_feedback_ext_latched"
#define HV_FEEDBACK_STATUS_FEEDBACK_TSAL_GREEN "hv_feedback_status_feedback_tsal_green"
#define HV_FEEDBACK_STATUS_FEEDBACK_TS_OVER_60V_STATUS "hv_feedback_status_feedback_ts_over_60v_status"
#define HV_FEEDBACK_STATUS_FEEDBACK_AIRN_STATUS "hv_feedback_status_feedback_airn_status"
#define HV_FEEDBACK_STATUS_FEEDBACK_AIRP_STATUS "hv_feedback_status_feedback_airp_status"
#define HV_FEEDBACK_STATUS_FEEDBACK_AIRP_GATE "hv_feedback_status_feedback_airp_gate"
#define HV_FEEDBACK_STATUS_FEEDBACK_AIRN_GATE "hv_feedback_status_feedback_airn_gate"
#define HV_FEEDBACK_STATUS_FEEDBACK_PRECHARGE_STATUS "hv_feedback_status_feedback_precharge_status"
#define HV_FEEDBACK_STATUS_FEEDBACK_TSP_OVER_60V_STATUS "hv_feedback_status_feedback_tsp_over_60v_status"
#define HV_FEEDBACK_STATUS_FEEDBACK_IMD_FAULT "hv_feedback_status_feedback_imd_fault"
#define HV_FEEDBACK_STATUS_FEEDBACK_CHECK_MUX "hv_feedback_status_feedback_check_mux"
#define HV_FEEDBACK_STATUS_FEEDBACK_SD_END "hv_feedback_status_feedback_sd_end"
#define HV_FEEDBACK_STATUS_FEEDBACK_SD_OUT "hv_feedback_status_feedback_sd_out"
#define HV_FEEDBACK_STATUS_FEEDBACK_SD_IN "hv_feedback_status_feedback_sd_in"
#define HV_FEEDBACK_STATUS_FEEDBACK_SD_BMS "hv_feedback_status_feedback_sd_bms"
#define HV_FEEDBACK_STATUS_FEEDBACK_SD_IMD "hv_feedback_status_feedback_sd_imd"
/* END */

/* START */
#define HV_FEEDBACK_TS_VOLTAGE "HV_FEEDBACK_TS_VOLTAGE"

#define HV_FEEDBACK_TS_VOLTAGE_TS_OVER_60V_STATUS "hv_feedback_ts_voltage_ts_over_60v_status"
#define HV_FEEDBACK_TS_VOLTAGE_AIRN_STATUS "hv_feedback_ts_voltage_airn_status"
#define HV_FEEDBACK_TS_VOLTAGE_AIRP_STATUS "hv_feedback_ts_voltage_airp_status"
#define HV_FEEDBACK_TS_VOLTAGE_AIRP_GATE "hv_feedback_ts_voltage_airp_gate"
#define HV_FEEDBACK_TS_VOLTAGE_AIRN_GATE "hv_feedback_ts_voltage_airn_gate"
#define HV_FEEDBACK_TS_VOLTAGE_PRECHARGE_STATUS "hv_feedback_ts_voltage_precharge_status"
#define HV_FEEDBACK_TS_VOLTAGE_TSP_OVER_60V_STATUS "hv_feedback_ts_voltage_tsp_over_60v_status"
/* END */

/* START */
#define HV_FEEDBACK_MISC_VOLTAGE "HV_FEEDBACK_MISC_VOLTAGE"

#define HV_FEEDBACK_MISC_VOLTAGE_IMPLAUSIBILITY_DETECTED "hv_feedback_misc_voltage_implausibility_detected"
#define HV_FEEDBACK_MISC_VOLTAGE_IMD_COCKPIT "hv_feedback_misc_voltage_imd_cockpit"
#define HV_FEEDBACK_MISC_VOLTAGE_TSAL_GREEN_FAULT_LATCHED "hv_feedback_misc_voltage_tsal_green_fault_latched"
#define HV_FEEDBACK_MISC_VOLTAGE_BMS_COCKPIT "hv_feedback_misc_voltage_bms_cockpit"
#define HV_FEEDBACK_MISC_VOLTAGE_EXT_LATCHED "hv_feedback_misc_voltage_ext_latched"
#define HV_FEEDBACK_MISC_VOLTAGE_TSAL_GREEN "hv_feedback_misc_voltage_tsal_green"
#define HV_FEEDBACK_MISC_VOLTAGE_IMD_FAULT "hv_feedback_misc_voltage_imd_fault"
#define HV_FEEDBACK_MISC_VOLTAGE_CHECK_MUX "hv_feedback_misc_voltage_check_mux"
/* END */

/* START */
#define HV_FEEDBACK_SD_VOLTAGE "HV_FEEDBACK_SD_VOLTAGE"

#define HV_FEEDBACK_SD_VOLTAGE_SD_END "hv_feedback_sd_voltage_sd_end"
#define HV_FEEDBACK_SD_VOLTAGE_SD_OUT "hv_feedback_sd_voltage_sd_out"
#define HV_FEEDBACK_SD_VOLTAGE_SD_IN "hv_feedback_sd_voltage_sd_in"
#define HV_FEEDBACK_SD_VOLTAGE_SD_BMS "hv_feedback_sd_voltage_sd_bms"
#define HV_FEEDBACK_SD_VOLTAGE_SD_IMD "hv_feedback_sd_voltage_sd_imd"
/* END */

/* START */
#define HV_IMD_STATUS "HV_IMD_STATUS"

#define HV_IMD_STATUS_IMD_FAULT "hv_imd_status_imd_fault"
#define HV_IMD_STATUS_IMD_STATUS "hv_imd_status_imd_status"
#define HV_IMD_STATUS_IMD_DETAILS "hv_imd_status_imd_details"
#define HV_IMD_STATUS_IMD_DUTY_CYCLE "hv_imd_status_imd_duty_cycle"
#define HV_IMD_STATUS_IMD_FREQ "hv_imd_status_imd_freq"
#define HV_IMD_STATUS_IMD_PERIOD "hv_imd_status_imd_period"
/* END */

/* START */
#define HV_STATUS "HV_STATUS"

#define HV_STATUS_STATUS "hv_status_status"
/* END */

/* START */
#define HV_SET_STATUS_ECU "HV_SET_STATUS_ECU"

#define HV_SET_STATUS_ECU_HV_STATUS_SET "hv_set_status_ecu_hv_status_set"
/* END */

/* START */
#define HV_SET_STATUS_HANDCART "HV_SET_STATUS_HANDCART"

#define HV_SET_STATUS_HANDCART_HV_STATUS_SET "hv_set_status_handcart_hv_status_set"
/* END */

/* START */
#define HV_BALANCING_STATUS "HV_BALANCING_STATUS"

#define HV_BALANCING_STATUS_CELLBOARD_ID "hv_balancing_status_cellboard_id"
#define HV_BALANCING_STATUS_BALANCING_STATUS "hv_balancing_status_balancing_status"
#define HV_BALANCING_STATUS_ERRORS_CAN_COMM "hv_balancing_status_errors_can_comm"
#define HV_BALANCING_STATUS_ERRORS_LTC_COMM "hv_balancing_status_errors_ltc_comm"
#define HV_BALANCING_STATUS_ERRORS_TEMP_COMM_0 "hv_balancing_status_errors_temp_comm_0"
#define HV_BALANCING_STATUS_ERRORS_TEMP_COMM_1 "hv_balancing_status_errors_temp_comm_1"
#define HV_BALANCING_STATUS_ERRORS_TEMP_COMM_2 "hv_balancing_status_errors_temp_comm_2"
#define HV_BALANCING_STATUS_ERRORS_TEMP_COMM_3 "hv_balancing_status_errors_temp_comm_3"
#define HV_BALANCING_STATUS_ERRORS_TEMP_COMM_4 "hv_balancing_status_errors_temp_comm_4"
#define HV_BALANCING_STATUS_ERRORS_TEMP_COMM_5 "hv_balancing_status_errors_temp_comm_5"
#define HV_BALANCING_STATUS_ERRORS_OPEN_WIRE "hv_balancing_status_errors_open_wire"
#define HV_BALANCING_STATUS_BALANCING_CELLS_CELL0 "hv_balancing_status_balancing_cells_cell0"
#define HV_BALANCING_STATUS_BALANCING_CELLS_CELL1 "hv_balancing_status_balancing_cells_cell1"
#define HV_BALANCING_STATUS_BALANCING_CELLS_CELL2 "hv_balancing_status_balancing_cells_cell2"
#define HV_BALANCING_STATUS_BALANCING_CELLS_CELL3 "hv_balancing_status_balancing_cells_cell3"
#define HV_BALANCING_STATUS_BALANCING_CELLS_CELL4 "hv_balancing_status_balancing_cells_cell4"
#define HV_BALANCING_STATUS_BALANCING_CELLS_CELL5 "hv_balancing_status_balancing_cells_cell5"
#define HV_BALANCING_STATUS_BALANCING_CELLS_CELL6 "hv_balancing_status_balancing_cells_cell6"
#define HV_BALANCING_STATUS_BALANCING_CELLS_CELL7 "hv_balancing_status_balancing_cells_cell7"
#define HV_BALANCING_STATUS_BALANCING_CELLS_CELL8 "hv_balancing_status_balancing_cells_cell8"
#define HV_BALANCING_STATUS_BALANCING_CELLS_CELL9 "hv_balancing_status_balancing_cells_cell9"
#define HV_BALANCING_STATUS_BALANCING_CELLS_CELL10 "hv_balancing_status_balancing_cells_cell10"
#define HV_BALANCING_STATUS_BALANCING_CELLS_CELL11 "hv_balancing_status_balancing_cells_cell11"
#define HV_BALANCING_STATUS_BALANCING_CELLS_CELL12 "hv_balancing_status_balancing_cells_cell12"
#define HV_BALANCING_STATUS_BALANCING_CELLS_CELL13 "hv_balancing_status_balancing_cells_cell13"
#define HV_BALANCING_STATUS_BALANCING_CELLS_CELL14 "hv_balancing_status_balancing_cells_cell14"
#define HV_BALANCING_STATUS_BALANCING_CELLS_CELL15 "hv_balancing_status_balancing_cells_cell15"
#define HV_BALANCING_STATUS_BALANCING_CELLS_CELL16 "hv_balancing_status_balancing_cells_cell16"
#define HV_BALANCING_STATUS_BALANCING_CELLS_CELL17 "hv_balancing_status_balancing_cells_cell17"
/* END */

/* START */
#define HV_SET_BALANCING_STATUS_HANDCART "HV_SET_BALANCING_STATUS_HANDCART"

#define HV_SET_BALANCING_STATUS_HANDCART_SET_BALANCING_STATUS "hv_set_balancing_status_handcart_set_balancing_status"
#define HV_SET_BALANCING_STATUS_HANDCART_BALANCING_THRESHOLD "hv_set_balancing_status_handcart_balancing_threshold"
/* END */

/* START */
#define HV_SET_BALANCING_STATUS_STEERING_WHEEL "HV_SET_BALANCING_STATUS_STEERING_WHEEL"

#define HV_SET_BALANCING_STATUS_STEERING_WHEEL_SET_BALANCING_STATUS "hv_set_balancing_status_steering_wheel_set_balancing_status"
#define HV_SET_BALANCING_STATUS_STEERING_WHEEL_BALANCING_THRESHOLD "hv_set_balancing_status_steering_wheel_balancing_threshold"
/* END */

/* START */
#define LV_STATUS "LV_STATUS"

#define LV_STATUS_STATUS "lv_status_status"
/* END */

/* START */
#define LV_RADIATOR_SPEED "LV_RADIATOR_SPEED"

#define LV_RADIATOR_SPEED_STATUS "lv_radiator_speed_status"
#define LV_RADIATOR_SPEED_RADIATOR_SPEED "lv_radiator_speed_radiator_speed"
/* END */

/* START */
#define LV_PUMPS_SPEED "LV_PUMPS_SPEED"

#define LV_PUMPS_SPEED_STATUS "lv_pumps_speed_status"
#define LV_PUMPS_SPEED_PUMPS_SPEED "lv_pumps_speed_pumps_speed"
/* END */

/* START */
#define LV_SET_RADIATOR_SPEED "LV_SET_RADIATOR_SPEED"

#define LV_SET_RADIATOR_SPEED_STATUS "lv_set_radiator_speed_status"
#define LV_SET_RADIATOR_SPEED_RADIATOR_SPEED "lv_set_radiator_speed_radiator_speed"
/* END */

/* START */
#define LV_SET_PUMPS_SPEED "LV_SET_PUMPS_SPEED"

#define LV_SET_PUMPS_SPEED_STATUS "lv_set_pumps_speed_status"
#define LV_SET_PUMPS_SPEED_PUMPS_SPEED "lv_set_pumps_speed_pumps_speed"
/* END */

/* START */
#define LV_ERRORS "LV_ERRORS"

#define LV_ERRORS_ERRORS_CELL_UNDERVOLTAGE "lv_errors_errors_cell_undervoltage"
#define LV_ERRORS_ERRORS_CELL_OVERVOLTAGE "lv_errors_errors_cell_overvoltage"
#define LV_ERRORS_ERRORS_BATTERY_OPEN_WIRE "lv_errors_errors_battery_open_wire"
#define LV_ERRORS_ERRORS_CAN "lv_errors_errors_can"
#define LV_ERRORS_ERRORS_SPI "lv_errors_errors_spi"
#define LV_ERRORS_ERRORS_OVER_CURRENT "lv_errors_errors_over_current"
#define LV_ERRORS_ERRORS_CELL_UNDER_TEMPERATURE "lv_errors_errors_cell_under_temperature"
#define LV_ERRORS_ERRORS_CELL_OVER_TEMPERATURE "lv_errors_errors_cell_over_temperature"
#define LV_ERRORS_ERRORS_RELAY "lv_errors_errors_relay"
#define LV_ERRORS_ERRORS_BMS_MONITOR "lv_errors_errors_bms_monitor"
#define LV_ERRORS_ERRORS_VOLTAGES_NOT_READY "lv_errors_errors_voltages_not_ready"
#define LV_ERRORS_ERRORS_MCP23017 "lv_errors_errors_mcp23017"
#define LV_ERRORS_ERRORS_RADIATOR "lv_errors_errors_radiator"
#define LV_ERRORS_ERRORS_FAN "lv_errors_errors_fan"
#define LV_ERRORS_ERRORS_PUMP "lv_errors_errors_pump"
#define LV_ERRORS_ERRORS_ADC_INIT "lv_errors_errors_adc_init"
#define LV_ERRORS_ERRORS_MUX "lv_errors_errors_mux"
#define LV_ERRORS_HEALTH_SIGNALS_LVMS_OUT "lv_errors_health_signals_lvms_out"
#define LV_ERRORS_HEALTH_SIGNALS_RELAY_OUT "lv_errors_health_signals_relay_out"
#define LV_ERRORS_HEALTH_SIGNALS_BATTERY_VOLTAGE_OUT "lv_errors_health_signals_battery_voltage_out"
#define LV_ERRORS_HEALTH_SIGNALS_CHARGER_CURRENT "lv_errors_health_signals_charger_current"
#define LV_ERRORS_HEALTH_SIGNALS_BATTERY_CURRENT "lv_errors_health_signals_battery_current"
#define LV_ERRORS_HEALTH_SIGNALS_SIGN_BATTERY_CURRENT "lv_errors_health_signals_sign_battery_current"
/* END */

/* START */
#define LV_FEEDBACK_TS_VOLTAGE "LV_FEEDBACK_TS_VOLTAGE"

#define LV_FEEDBACK_TS_VOLTAGE_BSPD "lv_feedback_ts_voltage_bspd"
#define LV_FEEDBACK_TS_VOLTAGE_HVD "lv_feedback_ts_voltage_hvd"
#define LV_FEEDBACK_TS_VOLTAGE_INVC_INTERLOCK "lv_feedback_ts_voltage_invc_interlock"
#define LV_FEEDBACK_TS_VOLTAGE_AMS "lv_feedback_ts_voltage_ams"
/* END */

/* START */
#define LV_FEEDBACK_SD_VOLTAGE "LV_FEEDBACK_SD_VOLTAGE"

#define LV_FEEDBACK_SD_VOLTAGE_SD_END "lv_feedback_sd_voltage_sd_end"
#define LV_FEEDBACK_SD_VOLTAGE_LVMS "lv_feedback_sd_voltage_lvms"
#define LV_FEEDBACK_SD_VOLTAGE_INTERLOCK "lv_feedback_sd_voltage_interlock"
#define LV_FEEDBACK_SD_VOLTAGE_SD_START "lv_feedback_sd_voltage_sd_start"
/* END */

/* START */
#define LV_FEEDBACK_ENCLOSURE_VOLTAGE "LV_FEEDBACK_ENCLOSURE_VOLTAGE"

#define LV_FEEDBACK_ENCLOSURE_VOLTAGE_LV_ENCL "lv_feedback_enclosure_voltage_lv_encl"
#define LV_FEEDBACK_ENCLOSURE_VOLTAGE_INVC_LID "lv_feedback_enclosure_voltage_invc_lid"
#define LV_FEEDBACK_ENCLOSURE_VOLTAGE_HV_ENCL_2 "lv_feedback_enclosure_voltage_hv_encl_2"
#define LV_FEEDBACK_ENCLOSURE_VOLTAGE_BACKPLATE "lv_feedback_enclosure_voltage_backplate"
/* END */

/* START */
#define LV_FEEDBACK_GPIO_EXTENDER "LV_FEEDBACK_GPIO_EXTENDER"

#define LV_FEEDBACK_GPIO_EXTENDER_FEEDBACK_INVERTERS "lv_feedback_gpio_extender_feedback_inverters"
#define LV_FEEDBACK_GPIO_EXTENDER_FEEDBACK_PCBS "lv_feedback_gpio_extender_feedback_pcbs"
#define LV_FEEDBACK_GPIO_EXTENDER_FEEDBACK_PUMPS "lv_feedback_gpio_extender_feedback_pumps"
#define LV_FEEDBACK_GPIO_EXTENDER_FEEDBACK_RADIATORS "lv_feedback_gpio_extender_feedback_radiators"
#define LV_FEEDBACK_GPIO_EXTENDER_FEEDBACK_SHUTDOWN "lv_feedback_gpio_extender_feedback_shutdown"
#define LV_FEEDBACK_GPIO_EXTENDER_FEEDBACK_HV_FANS "lv_feedback_gpio_extender_feedback_hv_fans"
#define LV_FEEDBACK_GPIO_EXTENDER_FEEDBACK_AUTONOMOUS_SYSTEM_ACTUATION "lv_feedback_gpio_extender_feedback_autonomous_system_actuation"
/* END */

/* START */
#define LV_CAN_FLASH_REQ_TLM "LV_CAN_FLASH_REQ_TLM"

/* END */

/* START */
#define LV_CAN_FLASH_REQ_STEERING_WHEEL "LV_CAN_FLASH_REQ_STEERING_WHEEL"

/* END */

/* START */
#define LV_CAN_FLASH_ACK "LV_CAN_FLASH_ACK"

/* END */

/* START */
#define LV_INVERTER_CONNECTION_STATUS "LV_INVERTER_CONNECTION_STATUS"

#define LV_INVERTER_CONNECTION_STATUS_STATUS "lv_inverter_connection_status_status"
/* END */

/* START */
#define LV_SET_INVERTER_CONNECTION_STATUS "LV_SET_INVERTER_CONNECTION_STATUS"

#define LV_SET_INVERTER_CONNECTION_STATUS_STATUS "lv_set_inverter_connection_status_status"
/* END */

/* START */
#define TLM_STATUS "TLM_STATUS"

#define TLM_STATUS_STATUS "tlm_status_status"
/* END */

/* START */
#define TLM_SET_STATUS "TLM_SET_STATUS"

#define TLM_SET_STATUS_STATUS "tlm_set_status_status"
/* END */

/* START */
#define HANDCART_STATUS "HANDCART_STATUS"

#define HANDCART_STATUS_CONNECTED "handcart_status_connected"
/* END */

/* START */
#define HANDCART_SETTINGS "HANDCART_SETTINGS"

#define HANDCART_SETTINGS_TARGET_VOLTAGE "handcart_settings_target_voltage"
#define HANDCART_SETTINGS_FANS_OVERRIDE "handcart_settings_fans_override"
#define HANDCART_SETTINGS_FANS_SPEED "handcart_settings_fans_speed"
#define HANDCART_SETTINGS_ACC_CHARGE_CURRENT "handcart_settings_acc_charge_current"
#define HANDCART_SETTINGS_GRID_MAX_CURRENT "handcart_settings_grid_max_current"
#define HANDCART_SETTINGS_STATUS "handcart_settings_status"
/* END */

/* START */
#define HANDCART_SET_SETTINGS "HANDCART_SET_SETTINGS"

#define HANDCART_SET_SETTINGS_TARGET_VOLTAGE "handcart_set_settings_target_voltage"
#define HANDCART_SET_SETTINGS_FANS_OVERRIDE "handcart_set_settings_fans_override"
#define HANDCART_SET_SETTINGS_FANS_SPEED "handcart_set_settings_fans_speed"
#define HANDCART_SET_SETTINGS_ACC_CHARGE_CURRENT "handcart_set_settings_acc_charge_current"
#define HANDCART_SET_SETTINGS_GRID_MAX_CURRENT "handcart_set_settings_grid_max_current"
#define HANDCART_SET_SETTINGS_STATUS "handcart_set_settings_status"
/* END */

/* START */
#define ECU_STATUS "ECU_STATUS"

#define ECU_STATUS_STATUS "ecu_status_status"
/* END */

/* START */
#define ECU_SET_STATUS "ECU_SET_STATUS"

#define ECU_SET_STATUS_STATUS "ecu_set_status_status"
/* END */

/* START */
#define ECU_INVERTER_STATUS "ECU_INVERTER_STATUS"

#define ECU_INVERTER_STATUS_RL "ecu_inverter_status_rl"
#define ECU_INVERTER_STATUS_RR "ecu_inverter_status_rr"
/* END */

/* START */
#define ECU_CONTROL_STATUS "ECU_CONTROL_STATUS"

#define ECU_CONTROL_STATUS_CONTROL_ENABLED "ecu_control_status_control_enabled"
#define ECU_CONTROL_STATUS_CONTROL_ERRORS_FORCED_OFF "ecu_control_status_control_errors_forced_off"
#define ECU_CONTROL_STATUS_CONTROL_ERRORS_WRONG_MAPS "ecu_control_status_control_errors_wrong_maps"
#define ECU_CONTROL_STATUS_CONTROL_ERRORS_CONTROL_WATCHDOG "ecu_control_status_control_errors_control_watchdog"
/* END */

/* START */
#define ECU_ERRORS "ECU_ERRORS"

#define ECU_ERRORS_ERROR_PEDAL_ADC "ecu_errors_error_pedal_adc"
#define ECU_ERRORS_ERROR_PEDAL_IMPLAUSIBILITY "ecu_errors_error_pedal_implausibility"
#define ECU_ERRORS_ERROR_IMU_TOUT "ecu_errors_error_imu_tout"
#define ECU_ERRORS_ERROR_IRTS_TOUT "ecu_errors_error_irts_tout"
#define ECU_ERRORS_ERROR_TS_TOUT "ecu_errors_error_ts_tout"
#define ECU_ERRORS_ERROR_INVL_TOUT "ecu_errors_error_invl_tout"
#define ECU_ERRORS_ERROR_INVR_TOUT "ecu_errors_error_invr_tout"
#define ECU_ERRORS_ERROR_STEER_TOUT "ecu_errors_error_steer_tout"
#define ECU_ERRORS_ERROR_FSM "ecu_errors_error_fsm"
/* END */

/* START */
#define ECU_FEEDBACKS "ECU_FEEDBACKS"

#define ECU_FEEDBACKS_FEEDBACKS_SD_COCK_FB "ecu_feedbacks_feedbacks_sd_cock_fb"
#define ECU_FEEDBACKS_FEEDBACKS_SD_FB1 "ecu_feedbacks_feedbacks_sd_fb1"
#define ECU_FEEDBACKS_FEEDBACKS_SD_BOTS_FB "ecu_feedbacks_feedbacks_sd_bots_fb"
#define ECU_FEEDBACKS_FEEDBACKS_SD_INTERIAL_FB "ecu_feedbacks_feedbacks_sd_interial_fb"
#define ECU_FEEDBACKS_FEEDBACKS_SD_FB4 "ecu_feedbacks_feedbacks_sd_fb4"
#define ECU_FEEDBACKS_FEEDBACKS_SD_IN "ecu_feedbacks_feedbacks_sd_in"
#define ECU_FEEDBACKS_FEEDBACKS_SD_OUT "ecu_feedbacks_feedbacks_sd_out"
#define ECU_FEEDBACKS_FEEDBACKS_SD_CTRL_PIN "ecu_feedbacks_feedbacks_sd_ctrl_pin"
/* END */

/* START */
#define ECU_POWER_MAPS "ECU_POWER_MAPS"

#define ECU_POWER_MAPS_MAP_PW "ecu_power_maps_map_pw"
#define ECU_POWER_MAPS_MAP_SC "ecu_power_maps_map_sc"
#define ECU_POWER_MAPS_MAP_TV "ecu_power_maps_map_tv"
/* END */

/* START */
#define ECU_SET_POWER_MAPS "ECU_SET_POWER_MAPS"

#define ECU_SET_POWER_MAPS_MAP_PW "ecu_set_power_maps_map_pw"
#define ECU_SET_POWER_MAPS_MAP_SC "ecu_set_power_maps_map_sc"
#define ECU_SET_POWER_MAPS_MAP_TV "ecu_set_power_maps_map_tv"
/* END */

/* START */
#define ECU_PTT_STATUS "ECU_PTT_STATUS"

#define ECU_PTT_STATUS_STATUS "ecu_ptt_status_status"
/* END */

/* START */
#define ECU_SET_PTT_STATUS "ECU_SET_PTT_STATUS"

#define ECU_SET_PTT_STATUS_STATUS "ecu_set_ptt_status_status"
/* END */

/* START */
#define INV_L_REQUEST "INV_L_REQUEST"

#define INV_L_REQUEST_DATA_0 "inv_l_request_data_0"
#define INV_L_REQUEST_DATA_1 "inv_l_request_data_1"
#define INV_L_REQUEST_DATA_2 "inv_l_request_data_2"
#define INV_L_REQUEST_DATA_3 "inv_l_request_data_3"
#define INV_L_REQUEST_DATA_4 "inv_l_request_data_4"
#define INV_L_REQUEST_DATA_5 "inv_l_request_data_5"
#define INV_L_REQUEST_DATA_6 "inv_l_request_data_6"
#define INV_L_REQUEST_DATA_7 "inv_l_request_data_7"
/* END */

/* START */
#define CONTROL_OUTPUT "CONTROL_OUTPUT"

#define CONTROL_OUTPUT_ESTIMATED_VELOCITY "control_output_estimated_velocity"
#define CONTROL_OUTPUT_TORQUE_MAX_L "control_output_torque_max_l"
#define CONTROL_OUTPUT_TORQUE_MAX_R "control_output_torque_max_r"
#define CONTROL_OUTPUT_TORQUE_L "control_output_torque_l"
#define CONTROL_OUTPUT_TORQUE_R "control_output_torque_r"
/* END */

/* START */
#define CONTROL_STATUS "CONTROL_STATUS"

#define CONTROL_STATUS_MAP_PW "control_status_map_pw"
#define CONTROL_STATUS_MAP_SC "control_status_map_sc"
#define CONTROL_STATUS_MAP_TV "control_status_map_tv"
/* END */

/* START */
#define INV_R_REQUEST "INV_R_REQUEST"

#define INV_R_REQUEST_DATA_0 "inv_r_request_data_0"
#define INV_R_REQUEST_DATA_1 "inv_r_request_data_1"
#define INV_R_REQUEST_DATA_2 "inv_r_request_data_2"
#define INV_R_REQUEST_DATA_3 "inv_r_request_data_3"
#define INV_R_REQUEST_DATA_4 "inv_r_request_data_4"
#define INV_R_REQUEST_DATA_5 "inv_r_request_data_5"
#define INV_R_REQUEST_DATA_6 "inv_r_request_data_6"
#define INV_R_REQUEST_DATA_7 "inv_r_request_data_7"
/* END */

/* START */
#define INV_L_RESPONSE "INV_L_RESPONSE"

#define INV_L_RESPONSE_REG_ID "inv_l_response_reg_id"
#define INV_L_RESPONSE_DATA_0 "inv_l_response_data_0"
#define INV_L_RESPONSE_DATA_1 "inv_l_response_data_1"
#define INV_L_RESPONSE_DATA_2 "inv_l_response_data_2"
#define INV_L_RESPONSE_DATA_3 "inv_l_response_data_3"
#define INV_L_RESPONSE_DATA_4 "inv_l_response_data_4"
#define INV_L_RESPONSE_DATA_5 "inv_l_response_data_5"
#define INV_L_RESPONSE_DATA_6 "inv_l_response_data_6"
/* END */

/* START */
#define INV_R_RESPONSE "INV_R_RESPONSE"

#define INV_R_RESPONSE_REG_ID "inv_r_response_reg_id"
#define INV_R_RESPONSE_DATA_0 "inv_r_response_data_0"
#define INV_R_RESPONSE_DATA_1 "inv_r_response_data_1"
#define INV_R_RESPONSE_DATA_2 "inv_r_response_data_2"
#define INV_R_RESPONSE_DATA_3 "inv_r_response_data_3"
#define INV_R_RESPONSE_DATA_4 "inv_r_response_data_4"
#define INV_R_RESPONSE_DATA_5 "inv_r_response_data_5"
#define INV_R_RESPONSE_DATA_6 "inv_r_response_data_6"
/* END */

/* START */
#define LV_CURRENT_BATTERY "LV_CURRENT_BATTERY"

#define LV_CURRENT_BATTERY_LV_CURRENT "lv_current_battery_lv_current"
/* END */

/* START */
#define LV_CURRENT_CHARGER "LV_CURRENT_CHARGER"

#define LV_CURRENT_CHARGER_CHARGER_CURRENT "lv_current_charger_charger_current"
/* END */

/* START */
#define LV_TOTAL_VOLTAGE "LV_TOTAL_VOLTAGE"

#define LV_TOTAL_VOLTAGE_TOTAL "lv_total_voltage_total"
/* END */

/* START */
#define LV_CELLS_VOLTAGE "LV_CELLS_VOLTAGE"

#define LV_CELLS_VOLTAGE_START_INDEX "lv_cells_voltage_start_index"
#define LV_CELLS_VOLTAGE_VOLTAGE_0 "lv_cells_voltage_voltage_0"
#define LV_CELLS_VOLTAGE_VOLTAGE_1 "lv_cells_voltage_voltage_1"
#define LV_CELLS_VOLTAGE_VOLTAGE_2 "lv_cells_voltage_voltage_2"
/* END */

/* START */
#define LV_CELLS_VOLTAGE_STATS "LV_CELLS_VOLTAGE_STATS"

#define LV_CELLS_VOLTAGE_STATS_MAX "lv_cells_voltage_stats_max"
#define LV_CELLS_VOLTAGE_STATS_MIN "lv_cells_voltage_stats_min"
#define LV_CELLS_VOLTAGE_STATS_DELTA "lv_cells_voltage_stats_delta"
#define LV_CELLS_VOLTAGE_STATS_AVG "lv_cells_voltage_stats_avg"
/* END */

/* START */
#define LV_CELLS_TEMP "LV_CELLS_TEMP"

#define LV_CELLS_TEMP_START_INDEX "lv_cells_temp_start_index"
#define LV_CELLS_TEMP_TEMP_0 "lv_cells_temp_temp_0"
#define LV_CELLS_TEMP_TEMP_1 "lv_cells_temp_temp_1"
#define LV_CELLS_TEMP_TEMP_2 "lv_cells_temp_temp_2"
/* END */

/* START */
#define LV_CELLS_TEMP_STATS "LV_CELLS_TEMP_STATS"

#define LV_CELLS_TEMP_STATS_MAX "lv_cells_temp_stats_max"
#define LV_CELLS_TEMP_STATS_MIN "lv_cells_temp_stats_min"
#define LV_CELLS_TEMP_STATS_AVG "lv_cells_temp_stats_avg"
/* END */

/* START */
#define HV_CURRENT "HV_CURRENT"

#define HV_CURRENT_CURRENT "hv_current_current"
/* END */

/* START */
#define HV_POWER "HV_POWER"

#define HV_POWER_POWER "hv_power_power"
/* END */

/* START */
#define HV_ENERGY "HV_ENERGY"

#define HV_ENERGY_ENERGY "hv_energy_energy"
/* END */

/* START */
#define HV_SOC "HV_SOC"

#define HV_SOC_SOC "hv_soc_soc"
/* END */

/* START */
#define HV_TOTAL_VOLTAGE "HV_TOTAL_VOLTAGE"

#define HV_TOTAL_VOLTAGE_PACK "hv_total_voltage_pack"
#define HV_TOTAL_VOLTAGE_SUM_CELL "hv_total_voltage_sum_cell"
#define HV_TOTAL_VOLTAGE_BUS "hv_total_voltage_bus"
/* END */

/* START */
#define HV_CELLS_VOLTAGE "HV_CELLS_VOLTAGE"

#define HV_CELLS_VOLTAGE_START_INDEX "hv_cells_voltage_start_index"
#define HV_CELLS_VOLTAGE_VOLTAGE_0 "hv_cells_voltage_voltage_0"
#define HV_CELLS_VOLTAGE_VOLTAGE_1 "hv_cells_voltage_voltage_1"
#define HV_CELLS_VOLTAGE_VOLTAGE_2 "hv_cells_voltage_voltage_2"
/* END */

/* START */
#define HV_CELLS_VOLTAGE_STATS "HV_CELLS_VOLTAGE_STATS"

#define HV_CELLS_VOLTAGE_STATS_MAX "hv_cells_voltage_stats_max"
#define HV_CELLS_VOLTAGE_STATS_MIN "hv_cells_voltage_stats_min"
#define HV_CELLS_VOLTAGE_STATS_DELTA "hv_cells_voltage_stats_delta"
#define HV_CELLS_VOLTAGE_STATS_AVG "hv_cells_voltage_stats_avg"
/* END */

/* START */
#define HV_CELLS_TEMP "HV_CELLS_TEMP"

#define HV_CELLS_TEMP_START_INDEX "hv_cells_temp_start_index"
#define HV_CELLS_TEMP_TEMP_0 "hv_cells_temp_temp_0"
#define HV_CELLS_TEMP_TEMP_1 "hv_cells_temp_temp_1"
#define HV_CELLS_TEMP_TEMP_2 "hv_cells_temp_temp_2"
#define HV_CELLS_TEMP_TEMP_3 "hv_cells_temp_temp_3"
/* END */

/* START */
#define HV_CELLS_TEMP_STATS "HV_CELLS_TEMP_STATS"

#define HV_CELLS_TEMP_STATS_MAX "hv_cells_temp_stats_max"
#define HV_CELLS_TEMP_STATS_MIN "hv_cells_temp_stats_min"
#define HV_CELLS_TEMP_STATS_AVG "hv_cells_temp_stats_avg"
/* END */

/* START */
#define ECU_STEER_ACTUATOR_STATUS "ECU_STEER_ACTUATOR_STATUS"

#define ECU_STEER_ACTUATOR_STATUS_STATUS "ecu_steer_actuator_status_status"
/* END */

/* START */
#define ECU_SET_STEER_ACTUATOR_STATUS_STEERING_WHEEL "ECU_SET_STEER_ACTUATOR_STATUS_STEERING_WHEEL"

#define ECU_SET_STEER_ACTUATOR_STATUS_STEERING_WHEEL_STATUS "ecu_set_steer_actuator_status_steering_wheel_status"
#define ECU_SET_STEER_ACTUATOR_STATUS_STEERING_WHEEL_TARGET "ecu_set_steer_actuator_status_steering_wheel_target"
/* END */

/* START */
#define ECU_SET_STEER_ACTUATOR_STATUS_TLM "ECU_SET_STEER_ACTUATOR_STATUS_TLM"

#define ECU_SET_STEER_ACTUATOR_STATUS_TLM_STATUS "ecu_set_steer_actuator_status_tlm_status"
#define ECU_SET_STEER_ACTUATOR_STATUS_TLM_TARGET "ecu_set_steer_actuator_status_tlm_target"
/* END */

/* START */
#define ECU_STEER_ACTUATOR_CURRENT "ECU_STEER_ACTUATOR_CURRENT"

#define ECU_STEER_ACTUATOR_CURRENT_CURRENT "ecu_steer_actuator_current_current"
/* END */

/* START */
#define DEBUG_SIGNAL_CRASH_DEBUG "DEBUG_SIGNAL_CRASH_DEBUG"

#define DEBUG_SIGNAL_CRASH_DEBUG_SEQ_NUMBER "debug_signal_crash_debug_seq_number"
#define DEBUG_SIGNAL_CRASH_DEBUG_BYTE_1 "debug_signal_crash_debug_byte_1"
#define DEBUG_SIGNAL_CRASH_DEBUG_BYTE_2 "debug_signal_crash_debug_byte_2"
#define DEBUG_SIGNAL_CRASH_DEBUG_BYTE_3 "debug_signal_crash_debug_byte_3"
#define DEBUG_SIGNAL_CRASH_DEBUG_BYTE_4 "debug_signal_crash_debug_byte_4"
#define DEBUG_SIGNAL_CRASH_DEBUG_BYTE_5 "debug_signal_crash_debug_byte_5"
#define DEBUG_SIGNAL_CRASH_DEBUG_BYTE_6 "debug_signal_crash_debug_byte_6"
#define DEBUG_SIGNAL_CRASH_DEBUG_BYTE_7 "debug_signal_crash_debug_byte_7"
/* END */

/* START */
#define DEBUG_SIGNAL_CRASH_DEBUG_ACK "DEBUG_SIGNAL_CRASH_DEBUG_ACK"

#define DEBUG_SIGNAL_CRASH_DEBUG_ACK_SEQ_NUMBER "debug_signal_crash_debug_ack_seq_number"
/* END */

/* START */
#define DEBUG_SIGNAL_1 "DEBUG_SIGNAL_1"

#define DEBUG_SIGNAL_1_FIELD_1 "debug_signal_1_field_1"
#define DEBUG_SIGNAL_1_FIELD_2 "debug_signal_1_field_2"
#define DEBUG_SIGNAL_1_FIELD_3 "debug_signal_1_field_3"
#define DEBUG_SIGNAL_1_FIELD_4 "debug_signal_1_field_4"
/* END */

/* START */
#define DEBUG_SIGNAL_2 "DEBUG_SIGNAL_2"

#define DEBUG_SIGNAL_2_FIELD_1 "debug_signal_2_field_1"
#define DEBUG_SIGNAL_2_FIELD_2 "debug_signal_2_field_2"
#define DEBUG_SIGNAL_2_FIELD_3 "debug_signal_2_field_3"
#define DEBUG_SIGNAL_2_FIELD_4 "debug_signal_2_field_4"
/* END */

enum primary_types_id{
	e_primary_uint16_t = -5,
	e_primary_uint8_t,
	e_primary_uint64_t,
	e_primary_float,
	e_primary_uint32_t,

	e_primary_hv_jmp_to_blt_forward,
	e_primary_hv_jmp_to_blt_cellboard_id,
	e_primary_hv_cellboard_version_cellboard_id,
	e_primary_hv_fans_status_fans_override,
	e_primary_hv_set_fans_status_fans_override,
	e_primary_hv_feedback_status_feedback_implausibility_detected,
	e_primary_hv_feedback_status_feedback_imd_cockpit,
	e_primary_hv_feedback_status_feedback_tsal_green_fault_latched,
	e_primary_hv_feedback_status_feedback_bms_cockpit,
	e_primary_hv_feedback_status_feedback_ext_latched,
	e_primary_hv_feedback_status_feedback_tsal_green,
	e_primary_hv_feedback_status_feedback_ts_over_60v_status,
	e_primary_hv_feedback_status_feedback_airn_status,
	e_primary_hv_feedback_status_feedback_airp_status,
	e_primary_hv_feedback_status_feedback_airp_gate,
	e_primary_hv_feedback_status_feedback_airn_gate,
	e_primary_hv_feedback_status_feedback_precharge_status,
	e_primary_hv_feedback_status_feedback_tsp_over_60v_status,
	e_primary_hv_feedback_status_feedback_imd_fault,
	e_primary_hv_feedback_status_feedback_check_mux,
	e_primary_hv_feedback_status_feedback_sd_end,
	e_primary_hv_feedback_status_feedback_sd_out,
	e_primary_hv_feedback_status_feedback_sd_in,
	e_primary_hv_feedback_status_feedback_sd_bms,
	e_primary_hv_feedback_status_feedback_sd_imd,
	e_primary_hv_imd_status_imd_status,
	e_primary_hv_status_status,
	e_primary_hv_set_status_ecu_hv_status_set,
	e_primary_hv_set_status_handcart_hv_status_set,
	e_primary_hv_balancing_status_cellboard_id,
	e_primary_hv_balancing_status_balancing_status,
	e_primary_hv_set_balancing_status_handcart_set_balancing_status,
	e_primary_hv_set_balancing_status_steering_wheel_set_balancing_status,
	e_primary_lv_status_status,
	e_primary_lv_radiator_speed_status,
	e_primary_lv_pumps_speed_status,
	e_primary_lv_set_radiator_speed_status,
	e_primary_lv_set_pumps_speed_status,
	e_primary_lv_inverter_connection_status_status,
	e_primary_lv_set_inverter_connection_status_status,
	e_primary_tlm_status_status,
	e_primary_tlm_set_status_status,
	e_primary_handcart_status_connected,
	e_primary_handcart_settings_fans_override,
	e_primary_handcart_settings_status,
	e_primary_handcart_set_settings_fans_override,
	e_primary_handcart_set_settings_status,
	e_primary_ecu_status_status,
	e_primary_ecu_set_status_status,
	e_primary_ecu_inverter_status_rl,
	e_primary_ecu_inverter_status_rr,
	e_primary_ecu_ptt_status_status,
	e_primary_ecu_set_ptt_status_status,
	e_primary_ecu_steer_actuator_status_status,
	e_primary_ecu_set_steer_actuator_status_steering_wheel_status,
	e_primary_ecu_set_steer_actuator_status_tlm_status
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
int primary_fields_string_from_id(int id, char **v, size_t fields_size, size_t string_size);

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
int primary_enum_fields(int enum_id, char **v, size_t fields_size, size_t string_size);

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
int primary_serialize_from_id(int id, char *s, uint8_t *data, size_t *size);

/**
 * @brief get the number of signals in the message
 * 
 * @param[in] id the id of the message
 * 
 * @return return the number of the signals
*/
int primary_n_fields_from_id(int id);

/**
 * @brief get the types of the signals in the message
 * 
 * @param[in] id the id of the message
 * @param[out] fields_types fields_types[i] contains the type id of the signal i (must be already allocated)
 * @param[in] fields_types_size max size of fields_types
 * 
 * @return the number of types set, 0 if the id is invalid or fields_types_size is too small
*/
int primary_fields_types_from_id(int id, int* fields_types, int fields_types_size);

/**
 * @brief get the fields of an enum given the name of the message and the name of the signal
 * 
 * @param[in] msg_name name of the message to find
 * @param[in] sgn_name name of the signal to find
 * @param[out] v array of strings containing the enum fields
 * 
 * @return the number of fields or 0 if the signal is not an enum
*/
int primary_enum_fields_from_name(const char *msg_name, const char *sgn_name, char **v);


#ifdef __cplusplus
}
#endif

#endif
