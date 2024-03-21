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
#define BMS_HV_JMP_TO_BLT "BMS_HV_JMP_TO_BLT"

/* END */

/* START */
#define FLASH_BMS_HV_TX "FLASH_BMS_HV_TX"

/* END */

/* START */
#define FLASH_BMS_HV_RX "FLASH_BMS_HV_RX"

/* END */

/* START */
#define HV_CAN_FORWARD "HV_CAN_FORWARD"

#define HV_CAN_FORWARD_CAN_FORWARD_SET "hv_can_forward_can_forward_set"
/* END */

/* START */
#define FLASH_CELLBOARD_0_TX "FLASH_CELLBOARD_0_TX"

/* END */

/* START */
#define FLASH_CELLBOARD_0_RX "FLASH_CELLBOARD_0_RX"

/* END */

/* START */
#define FLASH_CELLBOARD_1_TX "FLASH_CELLBOARD_1_TX"

/* END */

/* START */
#define FLASH_CELLBOARD_1_RX "FLASH_CELLBOARD_1_RX"

/* END */

/* START */
#define FLASH_CELLBOARD_2_TX "FLASH_CELLBOARD_2_TX"

/* END */

/* START */
#define FLASH_CELLBOARD_2_RX "FLASH_CELLBOARD_2_RX"

/* END */

/* START */
#define FLASH_CELLBOARD_3_TX "FLASH_CELLBOARD_3_TX"

/* END */

/* START */
#define FLASH_CELLBOARD_3_RX "FLASH_CELLBOARD_3_RX"

/* END */

/* START */
#define FLASH_CELLBOARD_4_TX "FLASH_CELLBOARD_4_TX"

/* END */

/* START */
#define FLASH_CELLBOARD_4_RX "FLASH_CELLBOARD_4_RX"

/* END */

/* START */
#define FLASH_CELLBOARD_5_TX "FLASH_CELLBOARD_5_TX"

/* END */

/* START */
#define FLASH_CELLBOARD_5_RX "FLASH_CELLBOARD_5_RX"

/* END */

/* START */
#define BMS_LV_JMP_TO_BLT "BMS_LV_JMP_TO_BLT"

/* END */

/* START */
#define FLASH_BMS_LV_TX "FLASH_BMS_LV_TX"

/* END */

/* START */
#define FLASH_BMS_LV_RX "FLASH_BMS_LV_RX"

/* END */

/* START */
#define ECU_JMP_TO_BLT "ECU_JMP_TO_BLT"

/* END */

/* START */
#define FLASH_ECU_TX "FLASH_ECU_TX"

/* END */

/* START */
#define FLASH_ECU_RX "FLASH_ECU_RX"

/* END */

/* START */
#define STEERING_JMP_TO_BLT "STEERING_JMP_TO_BLT"

/* END */

/* START */
#define FLASH_STEERING_TX "FLASH_STEERING_TX"

/* END */

/* START */
#define FLASH_STEERING_RX "FLASH_STEERING_RX"

/* END */

/* START */
#define STEER_VERSION "STEER_VERSION"

#define STEER_VERSION_COMPONENT_BUILD_TIME "steer_version_component_build_time"
#define STEER_VERSION_CANLIB_BUILD_TIME "steer_version_canlib_build_time"
/* END */

/* START */
#define DAS_VERSION "DAS_VERSION"

#define DAS_VERSION_COMPONENT_BUILD_TIME "das_version_component_build_time"
#define DAS_VERSION_CANLIB_BUILD_TIME "das_version_canlib_build_time"
/* END */

/* START */
#define MAINBOARD_VERSION "MAINBOARD_VERSION"

#define MAINBOARD_VERSION_COMPONENT_BUILD_TIME "mainboard_version_component_build_time"
#define MAINBOARD_VERSION_CANLIB_BUILD_TIME "mainboard_version_canlib_build_time"
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
#define CELLBOARD_VERSION "CELLBOARD_VERSION"

#define CELLBOARD_VERSION_CELLBOARD_ID "cellboard_version_cellboard_id"
#define CELLBOARD_VERSION_COMPONENT_VERSION "cellboard_version_component_version"
#define CELLBOARD_VERSION_CANLIB_BUILD_TIME "cellboard_version_canlib_build_time"
/* END */

/* START */
#define AMBIENT_TEMPERATURE "AMBIENT_TEMPERATURE"

#define AMBIENT_TEMPERATURE_TEMP "ambient_temperature_temp"
/* END */

/* START */
#define DATA_LOGGER "DATA_LOGGER"

#define DATA_LOGGER_PLACEHOLDER1 "data_logger_placeholder1"
#define DATA_LOGGER_PLACEHOLDER2 "data_logger_placeholder2"
/* END */

/* START */
#define SET_TLM_STATUS "SET_TLM_STATUS"

#define SET_TLM_STATUS_TLM_STATUS "set_tlm_status_tlm_status"
/* END */

/* START */
#define TLM_STATUS "TLM_STATUS"

#define TLM_STATUS_TLM_STATUS "tlm_status_tlm_status"
/* END */

/* START */
#define STEER_SYSTEM_STATUS "STEER_SYSTEM_STATUS"

#define STEER_SYSTEM_STATUS_SOC_TEMP "steer_system_status_soc_temp"
/* END */

/* START */
#define HV_VOLTAGE "HV_VOLTAGE"

#define HV_VOLTAGE_PACK_VOLTAGE "hv_voltage_pack_voltage"
#define HV_VOLTAGE_BUS_VOLTAGE "hv_voltage_bus_voltage"
/* END */

/* START */
#define HV_CELL_VOLTAGE "HV_CELL_VOLTAGE"

#define HV_CELL_VOLTAGE_MAX_CELL_VOLTAGE "hv_cell_voltage_max_cell_voltage"
#define HV_CELL_VOLTAGE_MIN_CELL_VOLTAGE "hv_cell_voltage_min_cell_voltage"
#define HV_CELL_VOLTAGE_SUM_CELL_VOLTAGE "hv_cell_voltage_sum_cell_voltage"
#define HV_CELL_VOLTAGE_AVG_CELL_VOLTAGE "hv_cell_voltage_avg_cell_voltage"
/* END */

/* START */
#define HV_CURRENT "HV_CURRENT"

#define HV_CURRENT_CURRENT "hv_current_current"
#define HV_CURRENT_POWER "hv_current_power"
#define HV_CURRENT_ENERGY "hv_current_energy"
#define HV_CURRENT_SOC "hv_current_soc"
/* END */

/* START */
#define HV_TEMP "HV_TEMP"

#define HV_TEMP_AVERAGE_TEMP "hv_temp_average_temp"
#define HV_TEMP_MAX_TEMP "hv_temp_max_temp"
#define HV_TEMP_MIN_TEMP "hv_temp_min_temp"
/* END */

/* START */
#define HV_ERRORS "HV_ERRORS"

#define HV_ERRORS_WARNINGS_CELL_LOW_VOLTAGE "hv_errors_warnings_cell_low_voltage"
#define HV_ERRORS_WARNINGS_CELL_UNDER_VOLTAGE "hv_errors_warnings_cell_under_voltage"
#define HV_ERRORS_WARNINGS_CELL_OVER_VOLTAGE "hv_errors_warnings_cell_over_voltage"
#define HV_ERRORS_WARNINGS_CELL_HIGH_TEMPERATURE "hv_errors_warnings_cell_high_temperature"
#define HV_ERRORS_WARNINGS_CELL_OVER_TEMPERATURE "hv_errors_warnings_cell_over_temperature"
#define HV_ERRORS_WARNINGS_OVER_CURRENT "hv_errors_warnings_over_current"
#define HV_ERRORS_WARNINGS_CAN "hv_errors_warnings_can"
#define HV_ERRORS_WARNINGS_INT_VOLTAGE_MISMATCH "hv_errors_warnings_int_voltage_mismatch"
#define HV_ERRORS_WARNINGS_CELLBOARD_COMM "hv_errors_warnings_cellboard_comm"
#define HV_ERRORS_WARNINGS_CELLBOARD_INTERNAL "hv_errors_warnings_cellboard_internal"
#define HV_ERRORS_WARNINGS_CONNECTOR_DISCONNECTED "hv_errors_warnings_connector_disconnected"
#define HV_ERRORS_WARNINGS_FANS_DISCONNECTED "hv_errors_warnings_fans_disconnected"
#define HV_ERRORS_WARNINGS_FEEDBACK "hv_errors_warnings_feedback"
#define HV_ERRORS_WARNINGS_FEEDBACK_CIRCUITRY "hv_errors_warnings_feedback_circuitry"
#define HV_ERRORS_WARNINGS_EEPROM_COMM "hv_errors_warnings_eeprom_comm"
#define HV_ERRORS_WARNINGS_EEPROM_WRITE "hv_errors_warnings_eeprom_write"
#define HV_ERRORS_ERRORS_CELL_LOW_VOLTAGE "hv_errors_errors_cell_low_voltage"
#define HV_ERRORS_ERRORS_CELL_UNDER_VOLTAGE "hv_errors_errors_cell_under_voltage"
#define HV_ERRORS_ERRORS_CELL_OVER_VOLTAGE "hv_errors_errors_cell_over_voltage"
#define HV_ERRORS_ERRORS_CELL_HIGH_TEMPERATURE "hv_errors_errors_cell_high_temperature"
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

#define HV_DEBUG_SIGNALS_DEBUG_SIGNALS_FEEDBACK_IMPLAUSIBILITY_DETECTED "hv_debug_signals_debug_signals_feedback_implausibility_detected"
#define HV_DEBUG_SIGNALS_DEBUG_SIGNALS_FEEDBACK_IMD_COCKPIT "hv_debug_signals_debug_signals_feedback_imd_cockpit"
#define HV_DEBUG_SIGNALS_DEBUG_SIGNALS_FEEDBACK_TSAL_GREEN_FAULT_LATCHED "hv_debug_signals_debug_signals_feedback_tsal_green_fault_latched"
#define HV_DEBUG_SIGNALS_DEBUG_SIGNALS_FEEDBACK_BMS_COCKPIT "hv_debug_signals_debug_signals_feedback_bms_cockpit"
#define HV_DEBUG_SIGNALS_DEBUG_SIGNALS_FEEDBACK_EXT_LATCHED "hv_debug_signals_debug_signals_feedback_ext_latched"
#define HV_DEBUG_SIGNALS_DEBUG_SIGNALS_FEEDBACK_TSAL_GREEN "hv_debug_signals_debug_signals_feedback_tsal_green"
#define HV_DEBUG_SIGNALS_DEBUG_SIGNALS_FEEDBACK_TS_OVER_60V_STATUS "hv_debug_signals_debug_signals_feedback_ts_over_60v_status"
#define HV_DEBUG_SIGNALS_DEBUG_SIGNALS_FEEDBACK_AIRN_STATUS "hv_debug_signals_debug_signals_feedback_airn_status"
#define HV_DEBUG_SIGNALS_DEBUG_SIGNALS_FEEDBACK_AIRP_STATUS "hv_debug_signals_debug_signals_feedback_airp_status"
#define HV_DEBUG_SIGNALS_DEBUG_SIGNALS_FEEDBACK_AIRP_GATE "hv_debug_signals_debug_signals_feedback_airp_gate"
#define HV_DEBUG_SIGNALS_DEBUG_SIGNALS_FEEDBACK_AIRN_GATE "hv_debug_signals_debug_signals_feedback_airn_gate"
#define HV_DEBUG_SIGNALS_DEBUG_SIGNALS_FEEDBACK_PRECHARGE_STATUS "hv_debug_signals_debug_signals_feedback_precharge_status"
#define HV_DEBUG_SIGNALS_DEBUG_SIGNALS_FEEDBACK_TSP_OVER_60V_STATUS "hv_debug_signals_debug_signals_feedback_tsp_over_60v_status"
#define HV_DEBUG_SIGNALS_DEBUG_SIGNALS_FEEDBACK_IMD_FAULT "hv_debug_signals_debug_signals_feedback_imd_fault"
#define HV_DEBUG_SIGNALS_DEBUG_SIGNALS_FEEDBACK_CHECK_MUX "hv_debug_signals_debug_signals_feedback_check_mux"
#define HV_DEBUG_SIGNALS_DEBUG_SIGNALS_FEEDBACK_SD_END "hv_debug_signals_debug_signals_feedback_sd_end"
#define HV_DEBUG_SIGNALS_DEBUG_SIGNALS_FEEDBACK_SD_OUT "hv_debug_signals_debug_signals_feedback_sd_out"
#define HV_DEBUG_SIGNALS_DEBUG_SIGNALS_FEEDBACK_SD_IN "hv_debug_signals_debug_signals_feedback_sd_in"
#define HV_DEBUG_SIGNALS_DEBUG_SIGNALS_FEEDBACK_SD_BMS "hv_debug_signals_debug_signals_feedback_sd_bms"
#define HV_DEBUG_SIGNALS_DEBUG_SIGNALS_FEEDBACK_SD_IMD "hv_debug_signals_debug_signals_feedback_sd_imd"
#define HV_DEBUG_SIGNALS_DEBUG_SIGNALS_ERROR_CELL_LOW_VOLTAGE "hv_debug_signals_debug_signals_error_cell_low_voltage"
#define HV_DEBUG_SIGNALS_DEBUG_SIGNALS_ERROR_CELL_UNDER_VOLTAGE "hv_debug_signals_debug_signals_error_cell_under_voltage"
#define HV_DEBUG_SIGNALS_DEBUG_SIGNALS_ERROR_CELL_OVER_VOLTAGE "hv_debug_signals_debug_signals_error_cell_over_voltage"
#define HV_DEBUG_SIGNALS_DEBUG_SIGNALS_ERROR_CELL_HIGH_TEMPERATURE "hv_debug_signals_debug_signals_error_cell_high_temperature"
#define HV_DEBUG_SIGNALS_DEBUG_SIGNALS_ERROR_CELL_OVER_TEMPERATURE "hv_debug_signals_debug_signals_error_cell_over_temperature"
#define HV_DEBUG_SIGNALS_DEBUG_SIGNALS_ERROR_OVER_CURRENT "hv_debug_signals_debug_signals_error_over_current"
#define HV_DEBUG_SIGNALS_DEBUG_SIGNALS_ERROR_CAN "hv_debug_signals_debug_signals_error_can"
#define HV_DEBUG_SIGNALS_DEBUG_SIGNALS_ERROR_INT_VOLTAGE_MISMATCH "hv_debug_signals_debug_signals_error_int_voltage_mismatch"
#define HV_DEBUG_SIGNALS_DEBUG_SIGNALS_ERROR_CELLBOARD_COMM "hv_debug_signals_debug_signals_error_cellboard_comm"
#define HV_DEBUG_SIGNALS_DEBUG_SIGNALS_ERROR_CELLBOARD_INTERNAL "hv_debug_signals_debug_signals_error_cellboard_internal"
#define HV_DEBUG_SIGNALS_DEBUG_SIGNALS_ERROR_CONNECTOR_DISCONNECTED "hv_debug_signals_debug_signals_error_connector_disconnected"
#define HV_DEBUG_SIGNALS_DEBUG_SIGNALS_ERROR_FANS_DISCONNECTED "hv_debug_signals_debug_signals_error_fans_disconnected"
#define HV_DEBUG_SIGNALS_DEBUG_SIGNALS_ERROR_FEEDBACK "hv_debug_signals_debug_signals_error_feedback"
#define HV_DEBUG_SIGNALS_DEBUG_SIGNALS_ERROR_FEEDBACK_CIRCUITRY "hv_debug_signals_debug_signals_error_feedback_circuitry"
#define HV_DEBUG_SIGNALS_DEBUG_SIGNALS_ERROR_EEPROM_COMM "hv_debug_signals_debug_signals_error_eeprom_comm"
#define HV_DEBUG_SIGNALS_DEBUG_SIGNALS_ERROR_EEPROM_WRITE "hv_debug_signals_debug_signals_error_eeprom_write"
/* END */

/* START */
#define HV_FANS_OVERRIDE "HV_FANS_OVERRIDE"

#define HV_FANS_OVERRIDE_FANS_OVERRIDE "hv_fans_override_fans_override"
#define HV_FANS_OVERRIDE_FANS_SPEED "hv_fans_override_fans_speed"
/* END */

/* START */
#define HV_CAN_FORWARD_STATUS "HV_CAN_FORWARD_STATUS"

#define HV_CAN_FORWARD_STATUS_CAN_FORWARD_STATUS "hv_can_forward_status_can_forward_status"
/* END */

/* START */
#define HV_FANS_OVERRIDE_STATUS "HV_FANS_OVERRIDE_STATUS"

#define HV_FANS_OVERRIDE_STATUS_FANS_OVERRIDE "hv_fans_override_status_fans_override"
#define HV_FANS_OVERRIDE_STATUS_FANS_SPEED "hv_fans_override_status_fans_speed"
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

#define HV_FEEDBACK_TS_VOLTAGE_FEEDBACK_TS_OVER_60V_STATUS "hv_feedback_ts_voltage_feedback_ts_over_60v_status"
#define HV_FEEDBACK_TS_VOLTAGE_FEEDBACK_AIRN_STATUS "hv_feedback_ts_voltage_feedback_airn_status"
#define HV_FEEDBACK_TS_VOLTAGE_FEEDBACK_AIRP_STATUS "hv_feedback_ts_voltage_feedback_airp_status"
#define HV_FEEDBACK_TS_VOLTAGE_FEEDBACK_AIRP_GATE "hv_feedback_ts_voltage_feedback_airp_gate"
#define HV_FEEDBACK_TS_VOLTAGE_FEEDBACK_AIRN_GATE "hv_feedback_ts_voltage_feedback_airn_gate"
#define HV_FEEDBACK_TS_VOLTAGE_FEEDBACK_PRECHARGE_STATUS "hv_feedback_ts_voltage_feedback_precharge_status"
#define HV_FEEDBACK_TS_VOLTAGE_FEEDBACK_TSP_OVER_60V_STATUS "hv_feedback_ts_voltage_feedback_tsp_over_60v_status"
/* END */

/* START */
#define HV_FEEDBACK_MISC_VOLTAGE "HV_FEEDBACK_MISC_VOLTAGE"

#define HV_FEEDBACK_MISC_VOLTAGE_FEEDBACK_IMPLAUSIBILITY_DETECTED "hv_feedback_misc_voltage_feedback_implausibility_detected"
#define HV_FEEDBACK_MISC_VOLTAGE_FEEDBACK_IMD_COCKPIT "hv_feedback_misc_voltage_feedback_imd_cockpit"
#define HV_FEEDBACK_MISC_VOLTAGE_FEEDBACK_TSAL_GREEN_FAULT_LATCHED "hv_feedback_misc_voltage_feedback_tsal_green_fault_latched"
#define HV_FEEDBACK_MISC_VOLTAGE_FEEDBACK_BMS_COCKPIT "hv_feedback_misc_voltage_feedback_bms_cockpit"
#define HV_FEEDBACK_MISC_VOLTAGE_FEEDBACK_EXT_LATCHED "hv_feedback_misc_voltage_feedback_ext_latched"
#define HV_FEEDBACK_MISC_VOLTAGE_FEEDBACK_TSAL_GREEN "hv_feedback_misc_voltage_feedback_tsal_green"
#define HV_FEEDBACK_MISC_VOLTAGE_IMD_FAULT "hv_feedback_misc_voltage_imd_fault"
#define HV_FEEDBACK_MISC_VOLTAGE_FEEDBACK_CHECK_MUX "hv_feedback_misc_voltage_feedback_check_mux"
/* END */

/* START */
#define HV_FEEDBACK_SD_VOLTAGE "HV_FEEDBACK_SD_VOLTAGE"

#define HV_FEEDBACK_SD_VOLTAGE_FEEDBACK_SD_END "hv_feedback_sd_voltage_feedback_sd_end"
#define HV_FEEDBACK_SD_VOLTAGE_FEEDBACK_SD_OUT "hv_feedback_sd_voltage_feedback_sd_out"
#define HV_FEEDBACK_SD_VOLTAGE_FEEDBACK_SD_IN "hv_feedback_sd_voltage_feedback_sd_in"
#define HV_FEEDBACK_SD_VOLTAGE_FEEDBACK_SD_BMS "hv_feedback_sd_voltage_feedback_sd_bms"
#define HV_FEEDBACK_SD_VOLTAGE_FEEDBACK_SD_IMD "hv_feedback_sd_voltage_feedback_sd_imd"
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
#define TS_STATUS "TS_STATUS"

#define TS_STATUS_TS_STATUS "ts_status_ts_status"
/* END */

/* START */
#define SET_TS_STATUS_DAS "SET_TS_STATUS_DAS"

#define SET_TS_STATUS_DAS_TS_STATUS_SET "set_ts_status_das_ts_status_set"
/* END */

/* START */
#define SET_TS_STATUS_HANDCART "SET_TS_STATUS_HANDCART"

#define SET_TS_STATUS_HANDCART_TS_STATUS_SET "set_ts_status_handcart_ts_status_set"
/* END */

/* START */
#define STEER_STATUS "STEER_STATUS"

#define STEER_STATUS_MAP_PW "steer_status_map_pw"
#define STEER_STATUS_MAP_SC "steer_status_map_sc"
#define STEER_STATUS_MAP_TV "steer_status_map_tv"
/* END */

/* START */
#define SET_CAR_STATUS "SET_CAR_STATUS"

#define SET_CAR_STATUS_CAR_STATUS_SET "set_car_status_car_status_set"
/* END */

/* START */
#define SET_PEDAL_CALIBRATION "SET_PEDAL_CALIBRATION"

#define SET_PEDAL_CALIBRATION_PEDAL "set_pedal_calibration_pedal"
#define SET_PEDAL_CALIBRATION_BOUND "set_pedal_calibration_bound"
/* END */

/* START */
#define PEDAL_CALIBRATION_ACK "PEDAL_CALIBRATION_ACK"

#define PEDAL_CALIBRATION_ACK_PEDAL "pedal_calibration_ack_pedal"
#define PEDAL_CALIBRATION_ACK_BOUND "pedal_calibration_ack_bound"
/* END */

/* START */
#define CAR_STATUS "CAR_STATUS"

#define CAR_STATUS_INVERTER_L "car_status_inverter_l"
#define CAR_STATUS_INVERTER_R "car_status_inverter_r"
#define CAR_STATUS_CAR_STATUS "car_status_car_status"
#define CAR_STATUS_CONTROLS_SLIP "car_status_controls_slip"
#define CAR_STATUS_CONTROLS_TORQUE_VECTORING "car_status_controls_torque_vectoring"
#define CAR_STATUS_CONTROLS_REGEN "car_status_controls_regen"
/* END */

/* START */
#define DAS_ERRORS "DAS_ERRORS"

#define DAS_ERRORS_DAS_ERROR_PEDAL_ADC "das_errors_das_error_pedal_adc"
#define DAS_ERRORS_DAS_ERROR_PEDAL_IMPLAUSIBILITY "das_errors_das_error_pedal_implausibility"
#define DAS_ERRORS_DAS_ERROR_IMU_TOUT "das_errors_das_error_imu_tout"
#define DAS_ERRORS_DAS_ERROR_IRTS_TOUT "das_errors_das_error_irts_tout"
#define DAS_ERRORS_DAS_ERROR_TS_TOUT "das_errors_das_error_ts_tout"
#define DAS_ERRORS_DAS_ERROR_INVL_TOUT "das_errors_das_error_invl_tout"
#define DAS_ERRORS_DAS_ERROR_INVR_TOUT "das_errors_das_error_invr_tout"
#define DAS_ERRORS_DAS_ERROR_STEER_TOUT "das_errors_das_error_steer_tout"
#define DAS_ERRORS_DAS_ERROR_FSM "das_errors_das_error_fsm"
/* END */

/* START */
#define ECU_FEEDBACKS "ECU_FEEDBACKS"

#define ECU_FEEDBACKS_ECU_FEEDBACKS_SD_COCK_FB "ecu_feedbacks_ecu_feedbacks_sd_cock_fb"
#define ECU_FEEDBACKS_ECU_FEEDBACKS_SD_FB1 "ecu_feedbacks_ecu_feedbacks_sd_fb1"
#define ECU_FEEDBACKS_ECU_FEEDBACKS_SD_BOTS_FB "ecu_feedbacks_ecu_feedbacks_sd_bots_fb"
#define ECU_FEEDBACKS_ECU_FEEDBACKS_SD_INTERIAL_FB "ecu_feedbacks_ecu_feedbacks_sd_interial_fb"
#define ECU_FEEDBACKS_ECU_FEEDBACKS_SD_FB4 "ecu_feedbacks_ecu_feedbacks_sd_fb4"
#define ECU_FEEDBACKS_ECU_FEEDBACKS_SD_IN "ecu_feedbacks_ecu_feedbacks_sd_in"
#define ECU_FEEDBACKS_ECU_FEEDBACKS_SD_OUT "ecu_feedbacks_ecu_feedbacks_sd_out"
#define ECU_FEEDBACKS_ECU_FEEDBACKS_SD_CTRL_PIN "ecu_feedbacks_ecu_feedbacks_sd_ctrl_pin"
/* END */

/* START */
#define LV_STATUS "LV_STATUS"

#define LV_STATUS_STATUS "lv_status_status"
/* END */

/* START */
#define LV_CURRENTS "LV_CURRENTS"

#define LV_CURRENTS_CURRENT_AS_BATTERY "lv_currents_current_as_battery"
#define LV_CURRENTS_CURRENT_LV_BATTERY "lv_currents_current_lv_battery"
#define LV_CURRENTS_CURRENT_CHARGER "lv_currents_current_charger"
/* END */

/* START */
#define LV_CELLS_VOLTAGE "LV_CELLS_VOLTAGE"

#define LV_CELLS_VOLTAGE_START_INDEX "lv_cells_voltage_start_index"
#define LV_CELLS_VOLTAGE_VOLTAGE_0 "lv_cells_voltage_voltage_0"
#define LV_CELLS_VOLTAGE_VOLTAGE_1 "lv_cells_voltage_voltage_1"
#define LV_CELLS_VOLTAGE_VOLTAGE_2 "lv_cells_voltage_voltage_2"
/* END */

/* START */
#define LV_TOTAL_VOLTAGE "LV_TOTAL_VOLTAGE"

#define LV_TOTAL_VOLTAGE_TOTAL_VOLTAGE "lv_total_voltage_total_voltage"
/* END */

/* START */
#define LV_CELLS_TEMP "LV_CELLS_TEMP"

#define LV_CELLS_TEMP_START_INDEX "lv_cells_temp_start_index"
#define LV_CELLS_TEMP_TEMP_0 "lv_cells_temp_temp_0"
#define LV_CELLS_TEMP_TEMP_1 "lv_cells_temp_temp_1"
#define LV_CELLS_TEMP_TEMP_2 "lv_cells_temp_temp_2"
/* END */

/* START */
#define COOLING_STATUS "COOLING_STATUS"

#define COOLING_STATUS_RADIATORS_SPEED "cooling_status_radiators_speed"
#define COOLING_STATUS_PUMPS_SPEED "cooling_status_pumps_speed"
/* END */

/* START */
#define SET_RADIATOR_SPEED "SET_RADIATOR_SPEED"

#define SET_RADIATOR_SPEED_RADIATORS_SPEED "set_radiator_speed_radiators_speed"
/* END */

/* START */
#define SET_PUMPS_SPEED "SET_PUMPS_SPEED"

#define SET_PUMPS_SPEED_PUMPS_SPEED "set_pumps_speed_pumps_speed"
/* END */

/* START */
#define SET_INVERTER_CONNECTION_STATUS "SET_INVERTER_CONNECTION_STATUS"

#define SET_INVERTER_CONNECTION_STATUS_STATUS "set_inverter_connection_status_status"
/* END */

/* START */
#define INVERTER_CONNECTION_STATUS "INVERTER_CONNECTION_STATUS"

#define INVERTER_CONNECTION_STATUS_STATUS "inverter_connection_status_status"
/* END */

/* START */
#define LV_ERRORS "LV_ERRORS"

#define LV_ERRORS_WARNINGS_CELL_UNDERVOLTAGE "lv_errors_warnings_cell_undervoltage"
#define LV_ERRORS_WARNINGS_CELL_OVERVOLTAGE "lv_errors_warnings_cell_overvoltage"
#define LV_ERRORS_WARNINGS_BATTERY_OPEN_WIRE "lv_errors_warnings_battery_open_wire"
#define LV_ERRORS_WARNINGS_CAN "lv_errors_warnings_can"
#define LV_ERRORS_WARNINGS_SPI "lv_errors_warnings_spi"
#define LV_ERRORS_WARNINGS_OVER_CURRENT "lv_errors_warnings_over_current"
#define LV_ERRORS_WARNINGS_CELL_UNDER_TEMPERATURE "lv_errors_warnings_cell_under_temperature"
#define LV_ERRORS_WARNINGS_CELL_OVER_TEMPERATURE "lv_errors_warnings_cell_over_temperature"
#define LV_ERRORS_WARNINGS_RELAY "lv_errors_warnings_relay"
#define LV_ERRORS_WARNINGS_BMS_MONITOR "lv_errors_warnings_bms_monitor"
#define LV_ERRORS_WARNINGS_VOLTAGES_NOT_READY "lv_errors_warnings_voltages_not_ready"
#define LV_ERRORS_WARNINGS_MCP23017 "lv_errors_warnings_mcp23017"
#define LV_ERRORS_WARNINGS_RADIATOR "lv_errors_warnings_radiator"
#define LV_ERRORS_WARNINGS_FAN "lv_errors_warnings_fan"
#define LV_ERRORS_WARNINGS_PUMP "lv_errors_warnings_pump"
#define LV_ERRORS_WARNINGS_ADC_INIT "lv_errors_warnings_adc_init"
#define LV_ERRORS_WARNINGS_MUX "lv_errors_warnings_mux"
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
/* END */

/* START */
#define LV_HEALTH_SIGNALS "LV_HEALTH_SIGNALS"

#define LV_HEALTH_SIGNALS_HEALTH_SIGNALS_LVMS_OUT "lv_health_signals_health_signals_lvms_out"
#define LV_HEALTH_SIGNALS_HEALTH_SIGNALS_RELAY_OUT "lv_health_signals_health_signals_relay_out"
#define LV_HEALTH_SIGNALS_HEALTH_SIGNALS_BATTERY_VOLTAGE_OUT "lv_health_signals_health_signals_battery_voltage_out"
#define LV_HEALTH_SIGNALS_HEALTH_SIGNALS_CHARGER_CURRENT "lv_health_signals_health_signals_charger_current"
#define LV_HEALTH_SIGNALS_HEALTH_SIGNALS_BATTERY_CURRENT "lv_health_signals_health_signals_battery_current"
#define LV_HEALTH_SIGNALS_HEALTH_SIGNALS_SIGN_BATTERY_CURRENT "lv_health_signals_health_signals_sign_battery_current"
#define LV_HEALTH_SIGNALS_HEALTH_CODE "lv_health_signals_health_code"
/* END */

/* START */
#define LV_FEEDBACKS "LV_FEEDBACKS"

#define LV_FEEDBACKS_FEEDBACKS_BSPD_FB "lv_feedbacks_feedbacks_bspd_fb"
#define LV_FEEDBACKS_FEEDBACKS_HVD_FB "lv_feedbacks_feedbacks_hvd_fb"
#define LV_FEEDBACKS_FEEDBACKS_LVMS_FB "lv_feedbacks_feedbacks_lvms_fb"
#define LV_FEEDBACKS_FEEDBACKS_RES_FB "lv_feedbacks_feedbacks_res_fb"
#define LV_FEEDBACKS_FEEDBACKS_LV_ENCL "lv_feedbacks_feedbacks_lv_encl"
#define LV_FEEDBACKS_FEEDBACKS_INVC_LID_FB "lv_feedbacks_feedbacks_invc_lid_fb"
#define LV_FEEDBACKS_FEEDBACKS_HV_ENCL_2_FB "lv_feedbacks_feedbacks_hv_encl_2_fb"
#define LV_FEEDBACKS_FEEDBACKS_BACK_PLATE_FB "lv_feedbacks_feedbacks_back_plate_fb"
#define LV_FEEDBACKS_FEEDBACKS_INVC_INTERLOCK_FB "lv_feedbacks_feedbacks_invc_interlock_fb"
#define LV_FEEDBACKS_FEEDBACKS_AMS_FB "lv_feedbacks_feedbacks_ams_fb"
#define LV_FEEDBACKS_FEEDBACKS_ASMS_FB "lv_feedbacks_feedbacks_asms_fb"
#define LV_FEEDBACKS_FEEDBACKS_INTERLOCK_FB "lv_feedbacks_feedbacks_interlock_fb"
#define LV_FEEDBACKS_FEEDBACKS_INVERTERS_FB "lv_feedbacks_feedbacks_inverters_fb"
#define LV_FEEDBACKS_FEEDBACKS_PCBS_FB "lv_feedbacks_feedbacks_pcbs_fb"
#define LV_FEEDBACKS_FEEDBACKS_PUMPS_FB "lv_feedbacks_feedbacks_pumps_fb"
#define LV_FEEDBACKS_FEEDBACKS_SHUTDOWN_FB "lv_feedbacks_feedbacks_shutdown_fb"
#define LV_FEEDBACKS_FEEDBACKS_RADIATORS_FB "lv_feedbacks_feedbacks_radiators_fb"
#define LV_FEEDBACKS_FEEDBACKS_FAN_FB "lv_feedbacks_feedbacks_fan_fb"
#define LV_FEEDBACKS_FEEDBACKS_AS_ACTUATION_FB "lv_feedbacks_feedbacks_as_actuation_fb"
#define LV_FEEDBACKS_SD_START "lv_feedbacks_sd_start"
#define LV_FEEDBACKS_SD_END "lv_feedbacks_sd_end"
/* END */

/* START */
#define SHUTDOWN_STATUS "SHUTDOWN_STATUS"

#define SHUTDOWN_STATUS_INPUT "shutdown_status_input"
#define SHUTDOWN_STATUS_OUTPUT "shutdown_status_output"
/* END */

/* START */
#define LV_CAN_FLASH_REQ "LV_CAN_FLASH_REQ"

/* END */

/* START */
#define LV_CAN_FLASH_ACK "LV_CAN_FLASH_ACK"

#define LV_CAN_FLASH_ACK_RESPONSE "lv_can_flash_ack_response"
/* END */

/* START */
#define MARKER "MARKER"

/* END */

/* START */
#define HV_CELLS_VOLTAGE "HV_CELLS_VOLTAGE"

#define HV_CELLS_VOLTAGE_START_INDEX "hv_cells_voltage_start_index"
#define HV_CELLS_VOLTAGE_VOLTAGE_0 "hv_cells_voltage_voltage_0"
#define HV_CELLS_VOLTAGE_VOLTAGE_1 "hv_cells_voltage_voltage_1"
#define HV_CELLS_VOLTAGE_VOLTAGE_2 "hv_cells_voltage_voltage_2"
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
#define HV_CELL_BALANCING_STATUS "HV_CELL_BALANCING_STATUS"

#define HV_CELL_BALANCING_STATUS_CELLBOARD_ID "hv_cell_balancing_status_cellboard_id"
#define HV_CELL_BALANCING_STATUS_BALANCING_STATUS "hv_cell_balancing_status_balancing_status"
#define HV_CELL_BALANCING_STATUS_ERRORS_CAN_COMM "hv_cell_balancing_status_errors_can_comm"
#define HV_CELL_BALANCING_STATUS_ERRORS_LTC_COMM "hv_cell_balancing_status_errors_ltc_comm"
#define HV_CELL_BALANCING_STATUS_ERRORS_TEMP_COMM_0 "hv_cell_balancing_status_errors_temp_comm_0"
#define HV_CELL_BALANCING_STATUS_ERRORS_TEMP_COMM_1 "hv_cell_balancing_status_errors_temp_comm_1"
#define HV_CELL_BALANCING_STATUS_ERRORS_TEMP_COMM_2 "hv_cell_balancing_status_errors_temp_comm_2"
#define HV_CELL_BALANCING_STATUS_ERRORS_TEMP_COMM_3 "hv_cell_balancing_status_errors_temp_comm_3"
#define HV_CELL_BALANCING_STATUS_ERRORS_TEMP_COMM_4 "hv_cell_balancing_status_errors_temp_comm_4"
#define HV_CELL_BALANCING_STATUS_ERRORS_TEMP_COMM_5 "hv_cell_balancing_status_errors_temp_comm_5"
#define HV_CELL_BALANCING_STATUS_ERRORS_OPEN_WIRE "hv_cell_balancing_status_errors_open_wire"
#define HV_CELL_BALANCING_STATUS_BALANCING_CELLS_CELL0 "hv_cell_balancing_status_balancing_cells_cell0"
#define HV_CELL_BALANCING_STATUS_BALANCING_CELLS_CELL1 "hv_cell_balancing_status_balancing_cells_cell1"
#define HV_CELL_BALANCING_STATUS_BALANCING_CELLS_CELL2 "hv_cell_balancing_status_balancing_cells_cell2"
#define HV_CELL_BALANCING_STATUS_BALANCING_CELLS_CELL3 "hv_cell_balancing_status_balancing_cells_cell3"
#define HV_CELL_BALANCING_STATUS_BALANCING_CELLS_CELL4 "hv_cell_balancing_status_balancing_cells_cell4"
#define HV_CELL_BALANCING_STATUS_BALANCING_CELLS_CELL5 "hv_cell_balancing_status_balancing_cells_cell5"
#define HV_CELL_BALANCING_STATUS_BALANCING_CELLS_CELL6 "hv_cell_balancing_status_balancing_cells_cell6"
#define HV_CELL_BALANCING_STATUS_BALANCING_CELLS_CELL7 "hv_cell_balancing_status_balancing_cells_cell7"
#define HV_CELL_BALANCING_STATUS_BALANCING_CELLS_CELL8 "hv_cell_balancing_status_balancing_cells_cell8"
#define HV_CELL_BALANCING_STATUS_BALANCING_CELLS_CELL9 "hv_cell_balancing_status_balancing_cells_cell9"
#define HV_CELL_BALANCING_STATUS_BALANCING_CELLS_CELL10 "hv_cell_balancing_status_balancing_cells_cell10"
#define HV_CELL_BALANCING_STATUS_BALANCING_CELLS_CELL11 "hv_cell_balancing_status_balancing_cells_cell11"
#define HV_CELL_BALANCING_STATUS_BALANCING_CELLS_CELL12 "hv_cell_balancing_status_balancing_cells_cell12"
#define HV_CELL_BALANCING_STATUS_BALANCING_CELLS_CELL13 "hv_cell_balancing_status_balancing_cells_cell13"
#define HV_CELL_BALANCING_STATUS_BALANCING_CELLS_CELL14 "hv_cell_balancing_status_balancing_cells_cell14"
#define HV_CELL_BALANCING_STATUS_BALANCING_CELLS_CELL15 "hv_cell_balancing_status_balancing_cells_cell15"
#define HV_CELL_BALANCING_STATUS_BALANCING_CELLS_CELL16 "hv_cell_balancing_status_balancing_cells_cell16"
#define HV_CELL_BALANCING_STATUS_BALANCING_CELLS_CELL17 "hv_cell_balancing_status_balancing_cells_cell17"
/* END */

/* START */
#define SET_CELL_BALANCING_STATUS "SET_CELL_BALANCING_STATUS"

#define SET_CELL_BALANCING_STATUS_SET_BALANCING_STATUS "set_cell_balancing_status_set_balancing_status"
#define SET_CELL_BALANCING_STATUS_BALANCING_THRESHOLD "set_cell_balancing_status_balancing_threshold"
/* END */

/* START */
#define SPEED "SPEED"

#define SPEED_ENCODER_R "speed_encoder_r"
#define SPEED_ENCODER_L "speed_encoder_l"
#define SPEED_INVERTER_R "speed_inverter_r"
#define SPEED_INVERTER_L "speed_inverter_l"
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
#define CONTROL_OUTPUT "CONTROL_OUTPUT"

#define CONTROL_OUTPUT_ESTIMATED_VELOCITY "control_output_estimated_velocity"
#define CONTROL_OUTPUT_TMAX_R "control_output_tmax_r"
#define CONTROL_OUTPUT_TMAX_L "control_output_tmax_l"
#define CONTROL_OUTPUT_TORQUE_L "control_output_torque_l"
#define CONTROL_OUTPUT_TORQUE_R "control_output_torque_r"
/* END */

/* START */
#define LC_RESET "LC_RESET"

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
#define HANDCART_SETTINGS_SET "HANDCART_SETTINGS_SET"

#define HANDCART_SETTINGS_SET_TARGET_VOLTAGE "handcart_settings_set_target_voltage"
#define HANDCART_SETTINGS_SET_FANS_OVERRIDE "handcart_settings_set_fans_override"
#define HANDCART_SETTINGS_SET_FANS_SPEED "handcart_settings_set_fans_speed"
#define HANDCART_SETTINGS_SET_ACC_CHARGE_CURRENT "handcart_settings_set_acc_charge_current"
#define HANDCART_SETTINGS_SET_GRID_MAX_CURRENT "handcart_settings_set_grid_max_current"
#define HANDCART_SETTINGS_SET_STATUS "handcart_settings_set_status"
/* END */

/* START */
#define SET_PTT_STATUS "SET_PTT_STATUS"

#define SET_PTT_STATUS_STATUS "set_ptt_status_status"
/* END */

/* START */
#define PTT_STATUS "PTT_STATUS"

#define PTT_STATUS_STATUS "ptt_status_status"
/* END */

/* START */
#define REGEN_MANUAL_COMMAND "REGEN_MANUAL_COMMAND"

#define REGEN_MANUAL_COMMAND_STATUS "regen_manual_command_status"
#define REGEN_MANUAL_COMMAND_TARGET "regen_manual_command_target"
/* END */

enum primary_types_id{
	e_primary_uint64_t = -6,
	e_primary_float,
	e_primary_uint32_t,
	e_primary_uint8_t,
	e_primary_int16_t,
	e_primary_uint16_t,

	e_primary_hv_can_forward_can_forward_set,
	e_primary_cellboard_version_cellboard_id,
	e_primary_set_tlm_status_tlm_status,
	e_primary_tlm_status_tlm_status,
	e_primary_hv_fans_override_fans_override,
	e_primary_hv_can_forward_status_can_forward_status,
	e_primary_hv_fans_override_status_fans_override,
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
	e_primary_ts_status_ts_status,
	e_primary_set_ts_status_das_ts_status_set,
	e_primary_set_ts_status_handcart_ts_status_set,
	e_primary_set_car_status_car_status_set,
	e_primary_set_pedal_calibration_pedal,
	e_primary_set_pedal_calibration_bound,
	e_primary_pedal_calibration_ack_pedal,
	e_primary_pedal_calibration_ack_bound,
	e_primary_car_status_inverter_l,
	e_primary_car_status_inverter_r,
	e_primary_car_status_car_status,
	e_primary_lv_status_status,
	e_primary_set_inverter_connection_status_status,
	e_primary_inverter_connection_status_status,
	e_primary_lv_can_flash_ack_response,
	e_primary_hv_cell_balancing_status_cellboard_id,
	e_primary_hv_cell_balancing_status_balancing_status,
	e_primary_set_cell_balancing_status_set_balancing_status,
	e_primary_handcart_settings_fans_override,
	e_primary_handcart_settings_status,
	e_primary_handcart_settings_set_fans_override,
	e_primary_handcart_settings_set_status,
	e_primary_set_ptt_status_status,
	e_primary_ptt_status_status,
	e_primary_regen_manual_command_status
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
