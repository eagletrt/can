#ifndef HV_CURRENT_UTILS_C_H

#define HV_CURRENT_UTILS_C_H

#include <stddef.h>
#include "hv_current_network.h"

/* START */
#define hv_current_ivt_msg_result_wh_string "HV_CURRENT_IVT_MSG_RESULT_WH"

#define hv_current_ivt_msg_result_wh_ivt_id_result_wh_string "HV_CURRENT_IVT_MSG_RESULT_WH_IVT_ID_RESULT_WH"
#define hv_current_ivt_msg_result_wh_ivt_result_wh_system_error_string "HV_CURRENT_IVT_MSG_RESULT_WH_IVT_RESULT_WH_SYSTEM_ERROR"
#define hv_current_ivt_msg_result_wh_ivt_result_wh_measurement_error_string "HV_CURRENT_IVT_MSG_RESULT_WH_IVT_RESULT_WH_MEASUREMENT_ERROR"
#define hv_current_ivt_msg_result_wh_ivt_result_wh_channel_error_string "HV_CURRENT_IVT_MSG_RESULT_WH_IVT_RESULT_WH_CHANNEL_ERROR"
#define hv_current_ivt_msg_result_wh_ivt_result_wh_ocs_string "HV_CURRENT_IVT_MSG_RESULT_WH_IVT_RESULT_WH_OCS"
#define hv_current_ivt_msg_result_wh_ivt_msgcount_result_wh_string "HV_CURRENT_IVT_MSG_RESULT_WH_IVT_MSGCOUNT_RESULT_WH"
#define hv_current_ivt_msg_result_wh_ivt_result_wh_string "HV_CURRENT_IVT_MSG_RESULT_WH_IVT_RESULT_WH"
/* END */

/* START */
#define hv_current_ivt_msg_result_as_string "HV_CURRENT_IVT_MSG_RESULT_AS"

#define hv_current_ivt_msg_result_as_ivt_id_result_as_string "HV_CURRENT_IVT_MSG_RESULT_AS_IVT_ID_RESULT_AS"
#define hv_current_ivt_msg_result_as_ivt_result_as_system_error_string "HV_CURRENT_IVT_MSG_RESULT_AS_IVT_RESULT_AS_SYSTEM_ERROR"
#define hv_current_ivt_msg_result_as_ivt_result_as_measurement_error_string "HV_CURRENT_IVT_MSG_RESULT_AS_IVT_RESULT_AS_MEASUREMENT_ERROR"
#define hv_current_ivt_msg_result_as_ivt_result_as_channel_error_string "HV_CURRENT_IVT_MSG_RESULT_AS_IVT_RESULT_AS_CHANNEL_ERROR"
#define hv_current_ivt_msg_result_as_ivt_result_as_ocs_string "HV_CURRENT_IVT_MSG_RESULT_AS_IVT_RESULT_AS_OCS"
#define hv_current_ivt_msg_result_as_ivt_msgcount_result_as_string "HV_CURRENT_IVT_MSG_RESULT_AS_IVT_MSGCOUNT_RESULT_AS"
#define hv_current_ivt_msg_result_as_ivt_result_as_string "HV_CURRENT_IVT_MSG_RESULT_AS_IVT_RESULT_AS"
/* END */

/* START */
#define hv_current_ivt_msg_result_w_string "HV_CURRENT_IVT_MSG_RESULT_W"

#define hv_current_ivt_msg_result_w_ivt_id_result_w_string "HV_CURRENT_IVT_MSG_RESULT_W_IVT_ID_RESULT_W"
#define hv_current_ivt_msg_result_w_ivt_result_w_system_error_string "HV_CURRENT_IVT_MSG_RESULT_W_IVT_RESULT_W_SYSTEM_ERROR"
#define hv_current_ivt_msg_result_w_ivt_result_w_measurement_error_string "HV_CURRENT_IVT_MSG_RESULT_W_IVT_RESULT_W_MEASUREMENT_ERROR"
#define hv_current_ivt_msg_result_w_ivt_result_w_channel_error_string "HV_CURRENT_IVT_MSG_RESULT_W_IVT_RESULT_W_CHANNEL_ERROR"
#define hv_current_ivt_msg_result_w_ivt_result_w_ocs_string "HV_CURRENT_IVT_MSG_RESULT_W_IVT_RESULT_W_OCS"
#define hv_current_ivt_msg_result_w_ivt_msgcount_result_w_string "HV_CURRENT_IVT_MSG_RESULT_W_IVT_MSGCOUNT_RESULT_W"
#define hv_current_ivt_msg_result_w_ivt_result_w_string "HV_CURRENT_IVT_MSG_RESULT_W_IVT_RESULT_W"
/* END */

/* START */
#define hv_current_ivt_msg_response_string "HV_CURRENT_IVT_MSG_RESPONSE"

#define hv_current_ivt_msg_response_ivt_id_response_string "HV_CURRENT_IVT_MSG_RESPONSE_IVT_ID_RESPONSE"
#define hv_current_ivt_msg_response__b1_trigger_spare_string "HV_CURRENT_IVT_MSG_RESPONSE__B1_TRIGGER_SPARE"
#define hv_current_ivt_msg_response__ff_wrong_command_string "HV_CURRENT_IVT_MSG_RESPONSE__FF_WRONG_COMMAND"
#define hv_current_ivt_msg_response__bf_restart_alive_cmd_id_string "HV_CURRENT_IVT_MSG_RESPONSE__BF_RESTART_ALIVE_CMD_ID"
#define hv_current_ivt_msg_response__80_resp_measerror_item_string "HV_CURRENT_IVT_MSG_RESPONSE__80_RESP_MEASERROR_ITEM"
#define hv_current_ivt_msg_response__81_resp_systemerror_item_string "HV_CURRENT_IVT_MSG_RESPONSE__81_RESP_SYSTEMERROR_ITEM"
#define hv_current_ivt_msg_response__82_resp_alllogdata_item_string "HV_CURRENT_IVT_MSG_RESPONSE__82_RESP_ALLLOGDATA_ITEM"
#define hv_current_ivt_msg_response__83_resp_logdata_item_string "HV_CURRENT_IVT_MSG_RESPONSE__83_RESP_LOGDATA_ITEM"
#define hv_current_ivt_msg_response__90_resp_can_id_val_i_string "HV_CURRENT_IVT_MSG_RESPONSE__90_RESP_CAN_ID_VAL_I"
#define hv_current_ivt_msg_response__91_resp_can_id_val_u1_string "HV_CURRENT_IVT_MSG_RESPONSE__91_RESP_CAN_ID_VAL_U1"
#define hv_current_ivt_msg_response__92_resp_can_id_val_u2_string "HV_CURRENT_IVT_MSG_RESPONSE__92_RESP_CAN_ID_VAL_U2"
#define hv_current_ivt_msg_response__93_resp_can_id_val_u3_string "HV_CURRENT_IVT_MSG_RESPONSE__93_RESP_CAN_ID_VAL_U3"
#define hv_current_ivt_msg_response__94_resp_can_id_val_t_string "HV_CURRENT_IVT_MSG_RESPONSE__94_RESP_CAN_ID_VAL_T"
#define hv_current_ivt_msg_response__95_resp_can_id_val_w_string "HV_CURRENT_IVT_MSG_RESPONSE__95_RESP_CAN_ID_VAL_W"
#define hv_current_ivt_msg_response__96_resp_can_id_val_as_string "HV_CURRENT_IVT_MSG_RESPONSE__96_RESP_CAN_ID_VAL_AS"
#define hv_current_ivt_msg_response__97_resp_can_id_val_wh_string "HV_CURRENT_IVT_MSG_RESPONSE__97_RESP_CAN_ID_VAL_WH"
#define hv_current_ivt_msg_response__9d_resp_can_id_val_command_string "HV_CURRENT_IVT_MSG_RESPONSE__9D_RESP_CAN_ID_VAL_COMMAND"
#define hv_current_ivt_msg_response__9f_resp_can_id_val_response_string "HV_CURRENT_IVT_MSG_RESPONSE__9F_RESP_CAN_ID_VAL_RESPONSE"
#define hv_current_ivt_msg_response__a0_resp_sign_i_string "HV_CURRENT_IVT_MSG_RESPONSE__A0_RESP_SIGN_I"
#define hv_current_ivt_msg_response__a1_resp_sign_u1_string "HV_CURRENT_IVT_MSG_RESPONSE__A1_RESP_SIGN_U1"
#define hv_current_ivt_msg_response__a2_resp_sign_u2_string "HV_CURRENT_IVT_MSG_RESPONSE__A2_RESP_SIGN_U2"
#define hv_current_ivt_msg_response__a3_resp_sign_u3_string "HV_CURRENT_IVT_MSG_RESPONSE__A3_RESP_SIGN_U3"
#define hv_current_ivt_msg_response__a4_resp_sign_t_string "HV_CURRENT_IVT_MSG_RESPONSE__A4_RESP_SIGN_T"
#define hv_current_ivt_msg_response__a5_resp_sign_w_string "HV_CURRENT_IVT_MSG_RESPONSE__A5_RESP_SIGN_W"
#define hv_current_ivt_msg_response__a6_resp_sign_as_string "HV_CURRENT_IVT_MSG_RESPONSE__A6_RESP_SIGN_AS"
#define hv_current_ivt_msg_response__a7_resp_sign_wh_string "HV_CURRENT_IVT_MSG_RESPONSE__A7_RESP_SIGN_WH"
#define hv_current_ivt_msg_response__b0_resp_reset_item_string "HV_CURRENT_IVT_MSG_RESPONSE__B0_RESP_RESET_ITEM"
#define hv_current_ivt_msg_response__b2_resp_store_dummy_string "HV_CURRENT_IVT_MSG_RESPONSE__B2_RESP_STORE_DUMMY"
#define hv_current_ivt_msg_response__b3_resp_oc_test_time_string "HV_CURRENT_IVT_MSG_RESPONSE__B3_RESP_OC_TEST_TIME"
#define hv_current_ivt_msg_response__b5_resp_oc_pos_set_threshold_string "HV_CURRENT_IVT_MSG_RESPONSE__B5_RESP_OC_POS_SET_THRESHOLD"
#define hv_current_ivt_msg_response__b6_resp_oc_neg_set_threshold_string "HV_CURRENT_IVT_MSG_RESPONSE__B6_RESP_OC_NEG_SET_THRESHOLD"
#define hv_current_ivt_msg_response__b9_resp_device_type_string "HV_CURRENT_IVT_MSG_RESPONSE__B9_RESP_DEVICE_TYPE"
#define hv_current_ivt_msg_response__ba_resp_sw_ver_major_hw_string "HV_CURRENT_IVT_MSG_RESPONSE__BA_RESP_SW_VER_MAJOR_HW"
#define hv_current_ivt_msg_response__bb_resp_serien_nr_string "HV_CURRENT_IVT_MSG_RESPONSE__BB_RESP_SERIEN_NR"
#define hv_current_ivt_msg_response__bc_resp_art_n_string "HV_CURRENT_IVT_MSG_RESPONSE__BC_RESP_ART_N"
#define hv_current_ivt_msg_response__a0_resp_endianess_i_string "HV_CURRENT_IVT_MSG_RESPONSE__A0_RESP_ENDIANESS_I"
#define hv_current_ivt_msg_response__a1_resp_endianess_u1_string "HV_CURRENT_IVT_MSG_RESPONSE__A1_RESP_ENDIANESS_U1"
#define hv_current_ivt_msg_response__a2_resp_endianess_u2_string "HV_CURRENT_IVT_MSG_RESPONSE__A2_RESP_ENDIANESS_U2"
#define hv_current_ivt_msg_response__a3_resp_endianess_u3_string "HV_CURRENT_IVT_MSG_RESPONSE__A3_RESP_ENDIANESS_U3"
#define hv_current_ivt_msg_response__a4_resp_endianess_t_string "HV_CURRENT_IVT_MSG_RESPONSE__A4_RESP_ENDIANESS_T"
#define hv_current_ivt_msg_response__a5_resp_endianess_w_string "HV_CURRENT_IVT_MSG_RESPONSE__A5_RESP_ENDIANESS_W"
#define hv_current_ivt_msg_response__a6_resp_endianess_as_string "HV_CURRENT_IVT_MSG_RESPONSE__A6_RESP_ENDIANESS_AS"
#define hv_current_ivt_msg_response__a7_resp_endianess_wh_string "HV_CURRENT_IVT_MSG_RESPONSE__A7_RESP_ENDIANESS_WH"
#define hv_current_ivt_msg_response__a0_resp_triggermode_i_string "HV_CURRENT_IVT_MSG_RESPONSE__A0_RESP_TRIGGERMODE_I"
#define hv_current_ivt_msg_response__a1_resp_triggermode_u1_string "HV_CURRENT_IVT_MSG_RESPONSE__A1_RESP_TRIGGERMODE_U1"
#define hv_current_ivt_msg_response__a2_resp_triggermode_u2_string "HV_CURRENT_IVT_MSG_RESPONSE__A2_RESP_TRIGGERMODE_U2"
#define hv_current_ivt_msg_response__a3_resp_triggermode_u3_string "HV_CURRENT_IVT_MSG_RESPONSE__A3_RESP_TRIGGERMODE_U3"
#define hv_current_ivt_msg_response__a4_resp_triggermode_t_string "HV_CURRENT_IVT_MSG_RESPONSE__A4_RESP_TRIGGERMODE_T"
#define hv_current_ivt_msg_response__a5_resp_triggermode_w_string "HV_CURRENT_IVT_MSG_RESPONSE__A5_RESP_TRIGGERMODE_W"
#define hv_current_ivt_msg_response__a6_resp_triggermode_as_string "HV_CURRENT_IVT_MSG_RESPONSE__A6_RESP_TRIGGERMODE_AS"
#define hv_current_ivt_msg_response__a7_resp_triggermode_wh_string "HV_CURRENT_IVT_MSG_RESPONSE__A7_RESP_TRIGGERMODE_WH"
#define hv_current_ivt_msg_response__b4_resp_actual_mode_string "HV_CURRENT_IVT_MSG_RESPONSE__B4_RESP_ACTUAL_MODE"
#define hv_current_ivt_msg_response__b1_07_trigger_wh_string "HV_CURRENT_IVT_MSG_RESPONSE__B1_07_TRIGGER_WH"
#define hv_current_ivt_msg_response__b2_resp_store_device_sn_string "HV_CURRENT_IVT_MSG_RESPONSE__B2_RESP_STORE_DEVICE_SN"
#define hv_current_ivt_msg_response__ba_resp_sw_ver_minor_string "HV_CURRENT_IVT_MSG_RESPONSE__BA_RESP_SW_VER_MINOR"
#define hv_current_ivt_msg_response__b9_resp_device_current_string "HV_CURRENT_IVT_MSG_RESPONSE__B9_RESP_DEVICE_CURRENT"
#define hv_current_ivt_msg_response__80_resp_measerror_count_mask_string "HV_CURRENT_IVT_MSG_RESPONSE__80_RESP_MEASERROR_COUNT_MASK"
#define hv_current_ivt_msg_response__81_resp_systemerror_count_mask_string "HV_CURRENT_IVT_MSG_RESPONSE__81_RESP_SYSTEMERROR_COUNT_MASK"
#define hv_current_ivt_msg_response__82_resp_alllogdata_counter_string "HV_CURRENT_IVT_MSG_RESPONSE__82_RESP_ALLLOGDATA_COUNTER"
#define hv_current_ivt_msg_response__83_resp_logdata_counter_string "HV_CURRENT_IVT_MSG_RESPONSE__83_RESP_LOGDATA_COUNTER"
#define hv_current_ivt_msg_response__a0_resp_cycletime_i_string "HV_CURRENT_IVT_MSG_RESPONSE__A0_RESP_CYCLETIME_I"
#define hv_current_ivt_msg_response__a1_resp_cycletime_u1_string "HV_CURRENT_IVT_MSG_RESPONSE__A1_RESP_CYCLETIME_U1"
#define hv_current_ivt_msg_response__a2_resp_cycletime_u2_string "HV_CURRENT_IVT_MSG_RESPONSE__A2_RESP_CYCLETIME_U2"
#define hv_current_ivt_msg_response__a3_resp_cycletime_u3_string "HV_CURRENT_IVT_MSG_RESPONSE__A3_RESP_CYCLETIME_U3"
#define hv_current_ivt_msg_response__a4_resp_cycletime_t_string "HV_CURRENT_IVT_MSG_RESPONSE__A4_RESP_CYCLETIME_T"
#define hv_current_ivt_msg_response__a5_resp_cycletime_w_string "HV_CURRENT_IVT_MSG_RESPONSE__A5_RESP_CYCLETIME_W"
#define hv_current_ivt_msg_response__a6_resp_cycletime_as_string "HV_CURRENT_IVT_MSG_RESPONSE__A6_RESP_CYCLETIME_AS"
#define hv_current_ivt_msg_response__a7_resp_cycletime_wh_string "HV_CURRENT_IVT_MSG_RESPONSE__A7_RESP_CYCLETIME_WH"
#define hv_current_ivt_msg_response__b1_06_trigger_as_string "HV_CURRENT_IVT_MSG_RESPONSE__B1_06_TRIGGER_AS"
#define hv_current_ivt_msg_response__b1_05_trigger_w_string "HV_CURRENT_IVT_MSG_RESPONSE__B1_05_TRIGGER_W"
#define hv_current_ivt_msg_response__b1_04_trigger_t_string "HV_CURRENT_IVT_MSG_RESPONSE__B1_04_TRIGGER_T"
#define hv_current_ivt_msg_response__b1_03_trigger_u3_string "HV_CURRENT_IVT_MSG_RESPONSE__B1_03_TRIGGER_U3"
#define hv_current_ivt_msg_response__b1_02_trigger_u2_string "HV_CURRENT_IVT_MSG_RESPONSE__B1_02_TRIGGER_U2"
#define hv_current_ivt_msg_response__b1_01_trigger_u1_string "HV_CURRENT_IVT_MSG_RESPONSE__B1_01_TRIGGER_U1"
#define hv_current_ivt_msg_response__b1_00_trigger_i_string "HV_CURRENT_IVT_MSG_RESPONSE__B1_00_TRIGGER_I"
#define hv_current_ivt_msg_response__b4_resp_startup_mode_string "HV_CURRENT_IVT_MSG_RESPONSE__B4_RESP_STARTUP_MODE"
#define hv_current_ivt_msg_response__bf_restart_alive_sn_string "HV_CURRENT_IVT_MSG_RESPONSE__BF_RESTART_ALIVE_SN"
#define hv_current_ivt_msg_response__ba_resp_sw_ver_revision_string "HV_CURRENT_IVT_MSG_RESPONSE__BA_RESP_SW_VER_REVISION"
#define hv_current_ivt_msg_response__90_resp_can_id_sn_i_string "HV_CURRENT_IVT_MSG_RESPONSE__90_RESP_CAN_ID_SN_I"
#define hv_current_ivt_msg_response__91_resp_can_id_sn_u1_string "HV_CURRENT_IVT_MSG_RESPONSE__91_RESP_CAN_ID_SN_U1"
#define hv_current_ivt_msg_response__92_resp_can_id_sn_u2_string "HV_CURRENT_IVT_MSG_RESPONSE__92_RESP_CAN_ID_SN_U2"
#define hv_current_ivt_msg_response__93_resp_can_id_sn_u3_string "HV_CURRENT_IVT_MSG_RESPONSE__93_RESP_CAN_ID_SN_U3"
#define hv_current_ivt_msg_response__94_resp_can_id_sn_t_string "HV_CURRENT_IVT_MSG_RESPONSE__94_RESP_CAN_ID_SN_T"
#define hv_current_ivt_msg_response__95_resp_can_id_sn_w_string "HV_CURRENT_IVT_MSG_RESPONSE__95_RESP_CAN_ID_SN_W"
#define hv_current_ivt_msg_response__96_resp_can_id_sn_as_string "HV_CURRENT_IVT_MSG_RESPONSE__96_RESP_CAN_ID_SN_AS"
#define hv_current_ivt_msg_response__97_resp_can_id_sn_wh_string "HV_CURRENT_IVT_MSG_RESPONSE__97_RESP_CAN_ID_SN_WH"
#define hv_current_ivt_msg_response__9d_resp_can_id_sn_command_string "HV_CURRENT_IVT_MSG_RESPONSE__9D_RESP_CAN_ID_SN_COMMAND"
#define hv_current_ivt_msg_response__9f_resp_can_id_sn_response_string "HV_CURRENT_IVT_MSG_RESPONSE__9F_RESP_CAN_ID_SN_RESPONSE"
#define hv_current_ivt_msg_response__b0_resp_reset_device_sn_string "HV_CURRENT_IVT_MSG_RESPONSE__B0_RESP_RESET_DEVICE_SN"
#define hv_current_ivt_msg_response__b4_resp_code_level_string "HV_CURRENT_IVT_MSG_RESPONSE__B4_RESP_CODE_LEVEL"
#define hv_current_ivt_msg_response__b5_resp_oc_pos_reset_threshold_string "HV_CURRENT_IVT_MSG_RESPONSE__B5_RESP_OC_POS_RESET_THRESHOLD"
#define hv_current_ivt_msg_response__b6_resp_oc_neg_reset_threshold_string "HV_CURRENT_IVT_MSG_RESPONSE__B6_RESP_OC_NEG_RESET_THRESHOLD"
#define hv_current_ivt_msg_response__b9_resp_device_voltage_chan_string "HV_CURRENT_IVT_MSG_RESPONSE__B9_RESP_DEVICE_VOLTAGE_CHAN"
#define hv_current_ivt_msg_response__ba_resp_sw_ver_vear_string "HV_CURRENT_IVT_MSG_RESPONSE__BA_RESP_SW_VER_VEAR"
#define hv_current_ivt_msg_response__b9_resp_device_toi_string "HV_CURRENT_IVT_MSG_RESPONSE__B9_RESP_DEVICE_TOI"
#define hv_current_ivt_msg_response__ba_resp_sw_ver_month_string "HV_CURRENT_IVT_MSG_RESPONSE__BA_RESP_SW_VER_MONTH"
#define hv_current_ivt_msg_response__b9_resp_device_com_string "HV_CURRENT_IVT_MSG_RESPONSE__B9_RESP_DEVICE_COM"
#define hv_current_ivt_msg_response__ba_resp_sw_ver_day_string "HV_CURRENT_IVT_MSG_RESPONSE__BA_RESP_SW_VER_DAY"
#define hv_current_ivt_msg_response__b9_resp_device_v_supply_string "HV_CURRENT_IVT_MSG_RESPONSE__B9_RESP_DEVICE_V_SUPPLY"
#define hv_current_ivt_msg_response__ba_resp_sw_ver_internal_string "HV_CURRENT_IVT_MSG_RESPONSE__BA_RESP_SW_VER_INTERNAL"
/* END */

/* START */
#define hv_current_ivt_msg_result_t_string "HV_CURRENT_IVT_MSG_RESULT_T"

#define hv_current_ivt_msg_result_t_ivt_id_result_t_string "HV_CURRENT_IVT_MSG_RESULT_T_IVT_ID_RESULT_T"
#define hv_current_ivt_msg_result_t_ivt_result_t_system_error_string "HV_CURRENT_IVT_MSG_RESULT_T_IVT_RESULT_T_SYSTEM_ERROR"
#define hv_current_ivt_msg_result_t_ivt_result_t_measurement_error_string "HV_CURRENT_IVT_MSG_RESULT_T_IVT_RESULT_T_MEASUREMENT_ERROR"
#define hv_current_ivt_msg_result_t_ivt_result_t_channel_error_string "HV_CURRENT_IVT_MSG_RESULT_T_IVT_RESULT_T_CHANNEL_ERROR"
#define hv_current_ivt_msg_result_t_ivt_result_t_ocs_string "HV_CURRENT_IVT_MSG_RESULT_T_IVT_RESULT_T_OCS"
#define hv_current_ivt_msg_result_t_ivt_msgcount_result_t_string "HV_CURRENT_IVT_MSG_RESULT_T_IVT_MSGCOUNT_RESULT_T"
#define hv_current_ivt_msg_result_t_ivt_result_t_string "HV_CURRENT_IVT_MSG_RESULT_T_IVT_RESULT_T"
/* END */

/* START */
#define hv_current_ivt_msg_result_u3_string "HV_CURRENT_IVT_MSG_RESULT_U3"

#define hv_current_ivt_msg_result_u3_ivt_id_result_u3_string "HV_CURRENT_IVT_MSG_RESULT_U3_IVT_ID_RESULT_U3"
#define hv_current_ivt_msg_result_u3_ivt_result_u3_system_error_string "HV_CURRENT_IVT_MSG_RESULT_U3_IVT_RESULT_U3_SYSTEM_ERROR"
#define hv_current_ivt_msg_result_u3_ivt_result_u3_measurement_error_string "HV_CURRENT_IVT_MSG_RESULT_U3_IVT_RESULT_U3_MEASUREMENT_ERROR"
#define hv_current_ivt_msg_result_u3_ivt_result_u3_channel_error_string "HV_CURRENT_IVT_MSG_RESULT_U3_IVT_RESULT_U3_CHANNEL_ERROR"
#define hv_current_ivt_msg_result_u3_ivt_result_u3_ocs_string "HV_CURRENT_IVT_MSG_RESULT_U3_IVT_RESULT_U3_OCS"
#define hv_current_ivt_msg_result_u3_ivt_msgcount_result_u3_string "HV_CURRENT_IVT_MSG_RESULT_U3_IVT_MSGCOUNT_RESULT_U3"
#define hv_current_ivt_msg_result_u3_ivt_result_u3_string "HV_CURRENT_IVT_MSG_RESULT_U3_IVT_RESULT_U3"
/* END */

/* START */
#define hv_current_ivt_msg_result_u2_string "HV_CURRENT_IVT_MSG_RESULT_U2"

#define hv_current_ivt_msg_result_u2_ivt_id_result_u2_string "HV_CURRENT_IVT_MSG_RESULT_U2_IVT_ID_RESULT_U2"
#define hv_current_ivt_msg_result_u2_ivt_result_u2_system_error_string "HV_CURRENT_IVT_MSG_RESULT_U2_IVT_RESULT_U2_SYSTEM_ERROR"
#define hv_current_ivt_msg_result_u2_ivt_result_u2_measurement_error_string "HV_CURRENT_IVT_MSG_RESULT_U2_IVT_RESULT_U2_MEASUREMENT_ERROR"
#define hv_current_ivt_msg_result_u2_ivt_result_u2_channel_error_string "HV_CURRENT_IVT_MSG_RESULT_U2_IVT_RESULT_U2_CHANNEL_ERROR"
#define hv_current_ivt_msg_result_u2_ivt_result_u2_ocs_string "HV_CURRENT_IVT_MSG_RESULT_U2_IVT_RESULT_U2_OCS"
#define hv_current_ivt_msg_result_u2_ivt_msgcount_result_u2_string "HV_CURRENT_IVT_MSG_RESULT_U2_IVT_MSGCOUNT_RESULT_U2"
#define hv_current_ivt_msg_result_u2_ivt_result_u2_string "HV_CURRENT_IVT_MSG_RESULT_U2_IVT_RESULT_U2"
/* END */

/* START */
#define hv_current_ivt_msg_result_u1_string "HV_CURRENT_IVT_MSG_RESULT_U1"

#define hv_current_ivt_msg_result_u1_ivt_id_result_u1_string "HV_CURRENT_IVT_MSG_RESULT_U1_IVT_ID_RESULT_U1"
#define hv_current_ivt_msg_result_u1_ivt_result_u1_system_error_string "HV_CURRENT_IVT_MSG_RESULT_U1_IVT_RESULT_U1_SYSTEM_ERROR"
#define hv_current_ivt_msg_result_u1_ivt_result_u1_measurement_error_string "HV_CURRENT_IVT_MSG_RESULT_U1_IVT_RESULT_U1_MEASUREMENT_ERROR"
#define hv_current_ivt_msg_result_u1_ivt_result_u1_channel_error_string "HV_CURRENT_IVT_MSG_RESULT_U1_IVT_RESULT_U1_CHANNEL_ERROR"
#define hv_current_ivt_msg_result_u1_ivt_result_u1_ocs_string "HV_CURRENT_IVT_MSG_RESULT_U1_IVT_RESULT_U1_OCS"
#define hv_current_ivt_msg_result_u1_ivt_msgcount_result_u1_string "HV_CURRENT_IVT_MSG_RESULT_U1_IVT_MSGCOUNT_RESULT_U1"
#define hv_current_ivt_msg_result_u1_ivt_result_u1_string "HV_CURRENT_IVT_MSG_RESULT_U1_IVT_RESULT_U1"
/* END */

/* START */
#define hv_current_ivt_msg_result_i_string "HV_CURRENT_IVT_MSG_RESULT_I"

#define hv_current_ivt_msg_result_i_ivt_id_result_i_string "HV_CURRENT_IVT_MSG_RESULT_I_IVT_ID_RESULT_I"
#define hv_current_ivt_msg_result_i_ivt_result_i_system_error_string "HV_CURRENT_IVT_MSG_RESULT_I_IVT_RESULT_I_SYSTEM_ERROR"
#define hv_current_ivt_msg_result_i_ivt_result_i_measurement_error_string "HV_CURRENT_IVT_MSG_RESULT_I_IVT_RESULT_I_MEASUREMENT_ERROR"
#define hv_current_ivt_msg_result_i_ivt_result_i_channel_error_string "HV_CURRENT_IVT_MSG_RESULT_I_IVT_RESULT_I_CHANNEL_ERROR"
#define hv_current_ivt_msg_result_i_ivt_result_i_ocs_string "HV_CURRENT_IVT_MSG_RESULT_I_IVT_RESULT_I_OCS"
#define hv_current_ivt_msg_result_i_ivt_msgcount_result_i_string "HV_CURRENT_IVT_MSG_RESULT_I_IVT_MSGCOUNT_RESULT_I"
#define hv_current_ivt_msg_result_i_ivt_result_i_string "HV_CURRENT_IVT_MSG_RESULT_I_IVT_RESULT_I"
/* END */

/* START */
#define hv_current_ivt_msg_cmd_string "HV_CURRENT_IVT_MSG_CMD"

#define hv_current_ivt_msg_cmd_ivt_id_cmd_string "HV_CURRENT_IVT_MSG_CMD_IVT_ID_CMD"
#define hv_current_ivt_msg_cmd__31_trigger_spare_string "HV_CURRENT_IVT_MSG_CMD__31_TRIGGER_SPARE"
#define hv_current_ivt_msg_cmd__10_set_can_id_val_i_string "HV_CURRENT_IVT_MSG_CMD__10_SET_CAN_ID_VAL_I"
#define hv_current_ivt_msg_cmd__11_set_can_id_val_u1_string "HV_CURRENT_IVT_MSG_CMD__11_SET_CAN_ID_VAL_U1"
#define hv_current_ivt_msg_cmd__12_set_can_id_val_u2_string "HV_CURRENT_IVT_MSG_CMD__12_SET_CAN_ID_VAL_U2"
#define hv_current_ivt_msg_cmd__13_set_can_id_val_u3_string "HV_CURRENT_IVT_MSG_CMD__13_SET_CAN_ID_VAL_U3"
#define hv_current_ivt_msg_cmd__14_set_can_id_val_t_string "HV_CURRENT_IVT_MSG_CMD__14_SET_CAN_ID_VAL_T"
#define hv_current_ivt_msg_cmd__15_set_can_id_val_w_string "HV_CURRENT_IVT_MSG_CMD__15_SET_CAN_ID_VAL_W"
#define hv_current_ivt_msg_cmd__16_set_can_id_val_as_string "HV_CURRENT_IVT_MSG_CMD__16_SET_CAN_ID_VAL_AS"
#define hv_current_ivt_msg_cmd__17_set_can_id_val_wh_string "HV_CURRENT_IVT_MSG_CMD__17_SET_CAN_ID_VAL_WH"
#define hv_current_ivt_msg_cmd__1d_set_can_id_val_command_string "HV_CURRENT_IVT_MSG_CMD__1D_SET_CAN_ID_VAL_COMMAND"
#define hv_current_ivt_msg_cmd__1f_set_can_id_val_response_string "HV_CURRENT_IVT_MSG_CMD__1F_SET_CAN_ID_VAL_RESPONSE"
#define hv_current_ivt_msg_cmd__20_conf_sign_i_string "HV_CURRENT_IVT_MSG_CMD__20_CONF_SIGN_I"
#define hv_current_ivt_msg_cmd__21_conf_sign_u1_string "HV_CURRENT_IVT_MSG_CMD__21_CONF_SIGN_U1"
#define hv_current_ivt_msg_cmd__22_conf_sign_u2_string "HV_CURRENT_IVT_MSG_CMD__22_CONF_SIGN_U2"
#define hv_current_ivt_msg_cmd__23_conf_sign_u3_string "HV_CURRENT_IVT_MSG_CMD__23_CONF_SIGN_U3"
#define hv_current_ivt_msg_cmd__24_conf_sign_t_string "HV_CURRENT_IVT_MSG_CMD__24_CONF_SIGN_T"
#define hv_current_ivt_msg_cmd__25_conf_sign_w_string "HV_CURRENT_IVT_MSG_CMD__25_CONF_SIGN_W"
#define hv_current_ivt_msg_cmd__26_conf_sign_as_string "HV_CURRENT_IVT_MSG_CMD__26_CONF_SIGN_AS"
#define hv_current_ivt_msg_cmd__27_conf_sign_wh_string "HV_CURRENT_IVT_MSG_CMD__27_CONF_SIGN_WH"
#define hv_current_ivt_msg_cmd__30_reset_item_string "HV_CURRENT_IVT_MSG_CMD__30_RESET_ITEM"
#define hv_current_ivt_msg_cmd__32_store_dummy_string "HV_CURRENT_IVT_MSG_CMD__32_STORE_DUMMY"
#define hv_current_ivt_msg_cmd__33_oc_test_time_string "HV_CURRENT_IVT_MSG_CMD__33_OC_TEST_TIME"
#define hv_current_ivt_msg_cmd__35_oc_pos_set_threshold_string "HV_CURRENT_IVT_MSG_CMD__35_OC_POS_SET_THRESHOLD"
#define hv_current_ivt_msg_cmd__36_oc_neg_set_threshold_string "HV_CURRENT_IVT_MSG_CMD__36_OC_NEG_SET_THRESHOLD"
#define hv_current_ivt_msg_cmd__3a_restart_to_bitrate_string "HV_CURRENT_IVT_MSG_CMD__3A_RESTART_TO_BITRATE"
#define hv_current_ivt_msg_cmd__3d_restart_default_dummy_string "HV_CURRENT_IVT_MSG_CMD__3D_RESTART_DEFAULT_DUMMY"
#define hv_current_ivt_msg_cmd__3f_restart_dummy_string "HV_CURRENT_IVT_MSG_CMD__3F_RESTART_DUMMY"
#define hv_current_ivt_msg_cmd__40_get_measerror_item_string "HV_CURRENT_IVT_MSG_CMD__40_GET_MEASERROR_ITEM"
#define hv_current_ivt_msg_cmd__41_get_systemerror_item_string "HV_CURRENT_IVT_MSG_CMD__41_GET_SYSTEMERROR_ITEM"
#define hv_current_ivt_msg_cmd__42_get_alllogdata_item_string "HV_CURRENT_IVT_MSG_CMD__42_GET_ALLLOGDATA_ITEM"
#define hv_current_ivt_msg_cmd__43_get_logdata_item_string "HV_CURRENT_IVT_MSG_CMD__43_GET_LOGDATA_ITEM"
#define hv_current_ivt_msg_cmd__60_get_result_dummy_i_string "HV_CURRENT_IVT_MSG_CMD__60_GET_RESULT_DUMMY_I"
#define hv_current_ivt_msg_cmd__61_get_result_dummy_u1_string "HV_CURRENT_IVT_MSG_CMD__61_GET_RESULT_DUMMY_U1"
#define hv_current_ivt_msg_cmd__62_get_result_dummy_u2_string "HV_CURRENT_IVT_MSG_CMD__62_GET_RESULT_DUMMY_U2"
#define hv_current_ivt_msg_cmd__63_get_result_dummy_u3_string "HV_CURRENT_IVT_MSG_CMD__63_GET_RESULT_DUMMY_U3"
#define hv_current_ivt_msg_cmd__64_get_result_dummy_t_string "HV_CURRENT_IVT_MSG_CMD__64_GET_RESULT_DUMMY_T"
#define hv_current_ivt_msg_cmd__65_get_result_dummy_w_string "HV_CURRENT_IVT_MSG_CMD__65_GET_RESULT_DUMMY_W"
#define hv_current_ivt_msg_cmd__66_get_result_dummy_as_string "HV_CURRENT_IVT_MSG_CMD__66_GET_RESULT_DUMMY_AS"
#define hv_current_ivt_msg_cmd__67_get_result_dummy_wh_string "HV_CURRENT_IVT_MSG_CMD__67_GET_RESULT_DUMMY_WH"
#define hv_current_ivt_msg_cmd__73_get_oc_test_dummy_string "HV_CURRENT_IVT_MSG_CMD__73_GET_OC_TEST_DUMMY"
#define hv_current_ivt_msg_cmd__74_get_mode_dummy_string "HV_CURRENT_IVT_MSG_CMD__74_GET_MODE_DUMMY"
#define hv_current_ivt_msg_cmd__75_get_oc_pos_dummy_string "HV_CURRENT_IVT_MSG_CMD__75_GET_OC_POS_DUMMY"
#define hv_current_ivt_msg_cmd__76_get_oc_neg_dummy_string "HV_CURRENT_IVT_MSG_CMD__76_GET_OC_NEG_DUMMY"
#define hv_current_ivt_msg_cmd__79_get_device_id_dummy_string "HV_CURRENT_IVT_MSG_CMD__79_GET_DEVICE_ID_DUMMY"
#define hv_current_ivt_msg_cmd__7a_get_sw_version_dummy_string "HV_CURRENT_IVT_MSG_CMD__7A_GET_SW_VERSION_DUMMY"
#define hv_current_ivt_msg_cmd__7b_get_serien_nr_dummy_string "HV_CURRENT_IVT_MSG_CMD__7B_GET_SERIEN_NR_DUMMY"
#define hv_current_ivt_msg_cmd__7c_get_art_nr_dummy_string "HV_CURRENT_IVT_MSG_CMD__7C_GET_ART_NR_DUMMY"
#define hv_current_ivt_msg_cmd__20_conf_endianess_i_string "HV_CURRENT_IVT_MSG_CMD__20_CONF_ENDIANESS_I"
#define hv_current_ivt_msg_cmd__21_conf_endianess_u1_string "HV_CURRENT_IVT_MSG_CMD__21_CONF_ENDIANESS_U1"
#define hv_current_ivt_msg_cmd__22_conf_endianess_u2_string "HV_CURRENT_IVT_MSG_CMD__22_CONF_ENDIANESS_U2"
#define hv_current_ivt_msg_cmd__23_conf_endianess_u3_string "HV_CURRENT_IVT_MSG_CMD__23_CONF_ENDIANESS_U3"
#define hv_current_ivt_msg_cmd__24_conf_endianess_t_string "HV_CURRENT_IVT_MSG_CMD__24_CONF_ENDIANESS_T"
#define hv_current_ivt_msg_cmd__25_conf_endianess_w_string "HV_CURRENT_IVT_MSG_CMD__25_CONF_ENDIANESS_W"
#define hv_current_ivt_msg_cmd__26_conf_endianess_as_string "HV_CURRENT_IVT_MSG_CMD__26_CONF_ENDIANESS_AS"
#define hv_current_ivt_msg_cmd__27_conf_endianess_wh_string "HV_CURRENT_IVT_MSG_CMD__27_CONF_ENDIANESS_WH"
#define hv_current_ivt_msg_cmd__20_conf_triggermode_i_string "HV_CURRENT_IVT_MSG_CMD__20_CONF_TRIGGERMODE_I"
#define hv_current_ivt_msg_cmd__21_conf_triggermode_u1_string "HV_CURRENT_IVT_MSG_CMD__21_CONF_TRIGGERMODE_U1"
#define hv_current_ivt_msg_cmd__22_conf_triggermode_u2_string "HV_CURRENT_IVT_MSG_CMD__22_CONF_TRIGGERMODE_U2"
#define hv_current_ivt_msg_cmd__23_conf_triggermode_u3_string "HV_CURRENT_IVT_MSG_CMD__23_CONF_TRIGGERMODE_U3"
#define hv_current_ivt_msg_cmd__24_conf_triggermode_t_string "HV_CURRENT_IVT_MSG_CMD__24_CONF_TRIGGERMODE_T"
#define hv_current_ivt_msg_cmd__25_conf_triggermode_w_string "HV_CURRENT_IVT_MSG_CMD__25_CONF_TRIGGERMODE_W"
#define hv_current_ivt_msg_cmd__26_conf_triggermode_as_string "HV_CURRENT_IVT_MSG_CMD__26_CONF_TRIGGERMODE_AS"
#define hv_current_ivt_msg_cmd__27_conf_triggermode_wh_string "HV_CURRENT_IVT_MSG_CMD__27_CONF_TRIGGERMODE_WH"
#define hv_current_ivt_msg_cmd__34_actual_mode_string "HV_CURRENT_IVT_MSG_CMD__34_ACTUAL_MODE"
#define hv_current_ivt_msg_cmd__31_07_trigger_wh_string "HV_CURRENT_IVT_MSG_CMD__31_07_TRIGGER_WH"
#define hv_current_ivt_msg_cmd__20_conf_cycletime_i_string "HV_CURRENT_IVT_MSG_CMD__20_CONF_CYCLETIME_I"
#define hv_current_ivt_msg_cmd__21_conf_cycletime_u1_string "HV_CURRENT_IVT_MSG_CMD__21_CONF_CYCLETIME_U1"
#define hv_current_ivt_msg_cmd__22_conf_cycletime_u2_string "HV_CURRENT_IVT_MSG_CMD__22_CONF_CYCLETIME_U2"
#define hv_current_ivt_msg_cmd__23_conf_cycletime_u3_string "HV_CURRENT_IVT_MSG_CMD__23_CONF_CYCLETIME_U3"
#define hv_current_ivt_msg_cmd__24_conf_cycletime_t_string "HV_CURRENT_IVT_MSG_CMD__24_CONF_CYCLETIME_T"
#define hv_current_ivt_msg_cmd__25_conf_cycletime_w_string "HV_CURRENT_IVT_MSG_CMD__25_CONF_CYCLETIME_W"
#define hv_current_ivt_msg_cmd__26_conf_cycletime_as_string "HV_CURRENT_IVT_MSG_CMD__26_CONF_CYCLETIME_AS"
#define hv_current_ivt_msg_cmd__27_conf_cycletime_wh_string "HV_CURRENT_IVT_MSG_CMD__27_CONF_CYCLETIME_WH"
#define hv_current_ivt_msg_cmd__31_06_trigger_as_string "HV_CURRENT_IVT_MSG_CMD__31_06_TRIGGER_AS"
#define hv_current_ivt_msg_cmd__31_05_trigger_w_string "HV_CURRENT_IVT_MSG_CMD__31_05_TRIGGER_W"
#define hv_current_ivt_msg_cmd__31_04_trigger_t_string "HV_CURRENT_IVT_MSG_CMD__31_04_TRIGGER_T"
#define hv_current_ivt_msg_cmd__31_03_trigger_u3_string "HV_CURRENT_IVT_MSG_CMD__31_03_TRIGGER_U3"
#define hv_current_ivt_msg_cmd__31_02_trigger_u2_string "HV_CURRENT_IVT_MSG_CMD__31_02_TRIGGER_U2"
#define hv_current_ivt_msg_cmd__31_01_trigger_u1_string "HV_CURRENT_IVT_MSG_CMD__31_01_TRIGGER_U1"
#define hv_current_ivt_msg_cmd__31_00_trigger_i_string "HV_CURRENT_IVT_MSG_CMD__31_00_TRIGGER_I"
#define hv_current_ivt_msg_cmd__34_startup_mode_string "HV_CURRENT_IVT_MSG_CMD__34_STARTUP_MODE"
#define hv_current_ivt_msg_cmd__10_set_can_id_sn_i_string "HV_CURRENT_IVT_MSG_CMD__10_SET_CAN_ID_SN_I"
#define hv_current_ivt_msg_cmd__11_set_can_id_sn_u1_string "HV_CURRENT_IVT_MSG_CMD__11_SET_CAN_ID_SN_U1"
#define hv_current_ivt_msg_cmd__12_set_can_id_sn_u2_string "HV_CURRENT_IVT_MSG_CMD__12_SET_CAN_ID_SN_U2"
#define hv_current_ivt_msg_cmd__13_set_can_id_sn_u3_string "HV_CURRENT_IVT_MSG_CMD__13_SET_CAN_ID_SN_U3"
#define hv_current_ivt_msg_cmd__14_set_can_id_sn_t_string "HV_CURRENT_IVT_MSG_CMD__14_SET_CAN_ID_SN_T"
#define hv_current_ivt_msg_cmd__15_set_can_id_sn_w_string "HV_CURRENT_IVT_MSG_CMD__15_SET_CAN_ID_SN_W"
#define hv_current_ivt_msg_cmd__16_set_can_id_sn_as_string "HV_CURRENT_IVT_MSG_CMD__16_SET_CAN_ID_SN_AS"
#define hv_current_ivt_msg_cmd__17_set_can_id_sn_wh_string "HV_CURRENT_IVT_MSG_CMD__17_SET_CAN_ID_SN_WH"
#define hv_current_ivt_msg_cmd__1d_set_can_id_sn_command_string "HV_CURRENT_IVT_MSG_CMD__1D_SET_CAN_ID_SN_COMMAND"
#define hv_current_ivt_msg_cmd__1f_set_can_id_sn_response_string "HV_CURRENT_IVT_MSG_CMD__1F_SET_CAN_ID_SN_RESPONSE"
#define hv_current_ivt_msg_cmd__30_reset_device_sn_string "HV_CURRENT_IVT_MSG_CMD__30_RESET_DEVICE_SN"
#define hv_current_ivt_msg_cmd__34_code_level_string "HV_CURRENT_IVT_MSG_CMD__34_CODE_LEVEL"
#define hv_current_ivt_msg_cmd__35_oc_pos_reset_threshold_string "HV_CURRENT_IVT_MSG_CMD__35_OC_POS_RESET_THRESHOLD"
#define hv_current_ivt_msg_cmd__36_oc_neg_reset_threshold_string "HV_CURRENT_IVT_MSG_CMD__36_OC_NEG_RESET_THRESHOLD"
#define hv_current_ivt_msg_cmd__50_get_can_id_sn_i_string "HV_CURRENT_IVT_MSG_CMD__50_GET_CAN_ID_SN_I"
#define hv_current_ivt_msg_cmd__51_get_can_id_sn_u1_string "HV_CURRENT_IVT_MSG_CMD__51_GET_CAN_ID_SN_U1"
#define hv_current_ivt_msg_cmd__52_get_can_id_sn_u2_string "HV_CURRENT_IVT_MSG_CMD__52_GET_CAN_ID_SN_U2"
#define hv_current_ivt_msg_cmd__53_get_can_id_sn_u3_string "HV_CURRENT_IVT_MSG_CMD__53_GET_CAN_ID_SN_U3"
#define hv_current_ivt_msg_cmd__54_get_can_id_sn_t_string "HV_CURRENT_IVT_MSG_CMD__54_GET_CAN_ID_SN_T"
#define hv_current_ivt_msg_cmd__55_get_can_id_sn_w_string "HV_CURRENT_IVT_MSG_CMD__55_GET_CAN_ID_SN_W"
#define hv_current_ivt_msg_cmd__56_get_can_id_sn_as_string "HV_CURRENT_IVT_MSG_CMD__56_GET_CAN_ID_SN_AS"
#define hv_current_ivt_msg_cmd__57_get_can_id_sn_wh_string "HV_CURRENT_IVT_MSG_CMD__57_GET_CAN_ID_SN_WH"
#define hv_current_ivt_msg_cmd__5d_get_can_id_sn_command_string "HV_CURRENT_IVT_MSG_CMD__5D_GET_CAN_ID_SN_COMMAND"
#define hv_current_ivt_msg_cmd__5f_get_can_id_sn_response_string "HV_CURRENT_IVT_MSG_CMD__5F_GET_CAN_ID_SN_RESPONSE"
/* END */

enum hv_current_types_id{
	e_hv_current_uint8_t = -8,
	e_hv_current_uint32_t,
	e_hv_current_uint64_t,
	e_hv_current_float,
	e_hv_current_int16_t,
	e_hv_current_uint16_t,
	e_hv_current_int8_t,
	e_hv_current_int32_t,

	e_hv_current_ivt_msg_response__b9_resp_device_voltage_chan,
	e_hv_current_ivt_msg_cmd_ivt_id_cmd,
	e_hv_current_ivt_msg_response__81_resp_systemerror_item,
	e_hv_current_ivt_msg_cmd__21_conf_triggermode_u1,
	e_hv_current_ivt_msg_response_ivt_id_response,
	e_hv_current_ivt_msg_result_t_ivt_id_result_t,
	e_hv_current_ivt_msg_response__a4_resp_triggermode_t,
	e_hv_current_ivt_msg_cmd__34_actual_mode,
	e_hv_current_ivt_msg_cmd__24_conf_triggermode_t,
	e_hv_current_ivt_msg_result_u3_ivt_id_result_u3,
	e_hv_current_ivt_msg_response__80_resp_measerror_item,
	e_hv_current_ivt_msg_response__a0_resp_triggermode_i,
	e_hv_current_ivt_msg_result_i_ivt_id_result_i,
	e_hv_current_ivt_msg_result_w_ivt_id_result_w,
	e_hv_current_ivt_msg_result_as_ivt_id_result_as,
	e_hv_current_ivt_msg_cmd__41_get_systemerror_item,
	e_hv_current_ivt_msg_cmd__26_conf_triggermode_as,
	e_hv_current_ivt_msg_response__a2_resp_triggermode_u2,
	e_hv_current_ivt_msg_result_u2_ivt_id_result_u2,
	e_hv_current_ivt_msg_cmd__30_reset_item,
	e_hv_current_ivt_msg_response__a6_resp_triggermode_as,
	e_hv_current_ivt_msg_response__83_resp_logdata_item,
	e_hv_current_ivt_msg_response__a7_resp_triggermode_wh,
	e_hv_current_ivt_msg_response__b0_resp_reset_item,
	e_hv_current_ivt_msg_cmd__27_conf_triggermode_wh,
	e_hv_current_ivt_msg_result_wh_ivt_id_result_wh,
	e_hv_current_ivt_msg_response__b9_resp_device_com,
	e_hv_current_ivt_msg_cmd__22_conf_triggermode_u2,
	e_hv_current_ivt_msg_response__a1_resp_triggermode_u1,
	e_hv_current_ivt_msg_cmd__42_get_alllogdata_item,
	e_hv_current_ivt_msg_response__b9_resp_device_type,
	e_hv_current_ivt_msg_cmd__40_get_measerror_item,
	e_hv_current_ivt_msg_cmd__43_get_logdata_item,
	e_hv_current_ivt_msg_cmd__3a_restart_to_bitrate,
	e_hv_current_ivt_msg_cmd__23_conf_triggermode_u3,
	e_hv_current_ivt_msg_response__b9_resp_device_current,
	e_hv_current_ivt_msg_cmd__20_conf_triggermode_i,
	e_hv_current_ivt_msg_cmd__25_conf_triggermode_w,
	e_hv_current_ivt_msg_response__82_resp_alllogdata_item,
	e_hv_current_ivt_msg_cmd__34_startup_mode,
	e_hv_current_ivt_msg_response__b4_resp_startup_mode,
	e_hv_current_ivt_msg_response__a3_resp_triggermode_u3,
	e_hv_current_ivt_msg_response__b9_resp_device_toi,
	e_hv_current_ivt_msg_response__b4_resp_actual_mode,
	e_hv_current_ivt_msg_result_u1_ivt_id_result_u1,
	e_hv_current_ivt_msg_response__b9_resp_device_v_supply,
	e_hv_current_ivt_msg_response__a5_resp_triggermode_w
};
int hv_current_fields_string_from_id(int id, char **v, size_t fields_size, size_t string_size);
int hv_current_enum_fields(int enum_id, char **v, size_t fields_size, size_t string_size);
int hv_current_serialize_from_id(int id, char *s, uint8_t *data, size_t *size);
int hv_current_n_fields_from_id(int id);
int hv_current_fields_types_from_id(int id, int* fields_types, int fields_types_size);


#endif