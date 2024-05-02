#ifndef ivts_UTILS_HPP
#define ivts_UTILS_HPP

#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <vector>
#include <string>
#include "ivts_network.h"

/* START */
#define IVT_MSG_RESULT_WH "IVT_MSG_RESULT_WH"

#define IVT_MSG_RESULT_WH_IVT_ID_RESULT_WH "ivt_msg_result_wh_ivt_id_result_wh"
#define IVT_MSG_RESULT_WH_IVT_RESULT_WH_SYSTEM_ERROR "ivt_msg_result_wh_ivt_result_wh_system_error"
#define IVT_MSG_RESULT_WH_IVT_RESULT_WH_MEASUREMENT_ERROR "ivt_msg_result_wh_ivt_result_wh_measurement_error"
#define IVT_MSG_RESULT_WH_IVT_RESULT_WH_CHANNEL_ERROR "ivt_msg_result_wh_ivt_result_wh_channel_error"
#define IVT_MSG_RESULT_WH_IVT_RESULT_WH_OCS "ivt_msg_result_wh_ivt_result_wh_ocs"
#define IVT_MSG_RESULT_WH_IVT_MSGCOUNT_RESULT_WH "ivt_msg_result_wh_ivt_msgcount_result_wh"
#define IVT_MSG_RESULT_WH_IVT_RESULT_WH "ivt_msg_result_wh_ivt_result_wh"
/* END */

/* START */
#define IVT_MSG_RESULT_AS "IVT_MSG_RESULT_AS"

#define IVT_MSG_RESULT_AS_IVT_ID_RESULT_AS "ivt_msg_result_as_ivt_id_result_as"
#define IVT_MSG_RESULT_AS_IVT_RESULT_AS_SYSTEM_ERROR "ivt_msg_result_as_ivt_result_as_system_error"
#define IVT_MSG_RESULT_AS_IVT_RESULT_AS_MEASUREMENT_ERROR "ivt_msg_result_as_ivt_result_as_measurement_error"
#define IVT_MSG_RESULT_AS_IVT_RESULT_AS_CHANNEL_ERROR "ivt_msg_result_as_ivt_result_as_channel_error"
#define IVT_MSG_RESULT_AS_IVT_RESULT_AS_OCS "ivt_msg_result_as_ivt_result_as_ocs"
#define IVT_MSG_RESULT_AS_IVT_MSGCOUNT_RESULT_AS "ivt_msg_result_as_ivt_msgcount_result_as"
#define IVT_MSG_RESULT_AS_IVT_RESULT_AS "ivt_msg_result_as_ivt_result_as"
/* END */

/* START */
#define IVT_MSG_RESULT_W "IVT_MSG_RESULT_W"

#define IVT_MSG_RESULT_W_IVT_ID_RESULT_W "ivt_msg_result_w_ivt_id_result_w"
#define IVT_MSG_RESULT_W_IVT_RESULT_W_SYSTEM_ERROR "ivt_msg_result_w_ivt_result_w_system_error"
#define IVT_MSG_RESULT_W_IVT_RESULT_W_MEASUREMENT_ERROR "ivt_msg_result_w_ivt_result_w_measurement_error"
#define IVT_MSG_RESULT_W_IVT_RESULT_W_CHANNEL_ERROR "ivt_msg_result_w_ivt_result_w_channel_error"
#define IVT_MSG_RESULT_W_IVT_RESULT_W_OCS "ivt_msg_result_w_ivt_result_w_ocs"
#define IVT_MSG_RESULT_W_IVT_MSGCOUNT_RESULT_W "ivt_msg_result_w_ivt_msgcount_result_w"
#define IVT_MSG_RESULT_W_IVT_RESULT_W "ivt_msg_result_w_ivt_result_w"
/* END */

/* START */
#define IVT_MSG_RESPONSE "IVT_MSG_RESPONSE"

#define IVT_MSG_RESPONSE_IVT_ID_RESPONSE "ivt_msg_response_ivt_id_response"
#define IVT_MSG_RESPONSE__B1_TRIGGER_SPARE "ivt_msg_response__b1_trigger_spare"
#define IVT_MSG_RESPONSE__FF_WRONG_COMMAND "ivt_msg_response__ff_wrong_command"
#define IVT_MSG_RESPONSE__BF_RESTART_ALIVE_CMD_ID "ivt_msg_response__bf_restart_alive_cmd_id"
#define IVT_MSG_RESPONSE__80_RESP_MEASERROR_ITEM "ivt_msg_response__80_resp_measerror_item"
#define IVT_MSG_RESPONSE__81_RESP_SYSTEMERROR_ITEM "ivt_msg_response__81_resp_systemerror_item"
#define IVT_MSG_RESPONSE__82_RESP_ALLLOGDATA_ITEM "ivt_msg_response__82_resp_alllogdata_item"
#define IVT_MSG_RESPONSE__83_RESP_LOGDATA_ITEM "ivt_msg_response__83_resp_logdata_item"
#define IVT_MSG_RESPONSE__90_RESP_CAN_ID_VAL_I "ivt_msg_response__90_resp_can_id_val_i"
#define IVT_MSG_RESPONSE__91_RESP_CAN_ID_VAL_U1 "ivt_msg_response__91_resp_can_id_val_u1"
#define IVT_MSG_RESPONSE__92_RESP_CAN_ID_VAL_U2 "ivt_msg_response__92_resp_can_id_val_u2"
#define IVT_MSG_RESPONSE__93_RESP_CAN_ID_VAL_U3 "ivt_msg_response__93_resp_can_id_val_u3"
#define IVT_MSG_RESPONSE__94_RESP_CAN_ID_VAL_T "ivt_msg_response__94_resp_can_id_val_t"
#define IVT_MSG_RESPONSE__95_RESP_CAN_ID_VAL_W "ivt_msg_response__95_resp_can_id_val_w"
#define IVT_MSG_RESPONSE__96_RESP_CAN_ID_VAL_AS "ivt_msg_response__96_resp_can_id_val_as"
#define IVT_MSG_RESPONSE__97_RESP_CAN_ID_VAL_WH "ivt_msg_response__97_resp_can_id_val_wh"
#define IVT_MSG_RESPONSE__9D_RESP_CAN_ID_VAL_COMMAND "ivt_msg_response__9d_resp_can_id_val_command"
#define IVT_MSG_RESPONSE__9F_RESP_CAN_ID_VAL_RESPONSE "ivt_msg_response__9f_resp_can_id_val_response"
#define IVT_MSG_RESPONSE__A0_RESP_SIGN_I "ivt_msg_response__a0_resp_sign_i"
#define IVT_MSG_RESPONSE__A1_RESP_SIGN_U1 "ivt_msg_response__a1_resp_sign_u1"
#define IVT_MSG_RESPONSE__A2_RESP_SIGN_U2 "ivt_msg_response__a2_resp_sign_u2"
#define IVT_MSG_RESPONSE__A3_RESP_SIGN_U3 "ivt_msg_response__a3_resp_sign_u3"
#define IVT_MSG_RESPONSE__A4_RESP_SIGN_T "ivt_msg_response__a4_resp_sign_t"
#define IVT_MSG_RESPONSE__A5_RESP_SIGN_W "ivt_msg_response__a5_resp_sign_w"
#define IVT_MSG_RESPONSE__A6_RESP_SIGN_AS "ivt_msg_response__a6_resp_sign_as"
#define IVT_MSG_RESPONSE__A7_RESP_SIGN_WH "ivt_msg_response__a7_resp_sign_wh"
#define IVT_MSG_RESPONSE__B0_RESP_RESET_ITEM "ivt_msg_response__b0_resp_reset_item"
#define IVT_MSG_RESPONSE__B2_RESP_STORE_DUMMY "ivt_msg_response__b2_resp_store_dummy"
#define IVT_MSG_RESPONSE__B3_RESP_OC_TEST_TIME "ivt_msg_response__b3_resp_oc_test_time"
#define IVT_MSG_RESPONSE__B5_RESP_OC_POS_SET_THRESHOLD "ivt_msg_response__b5_resp_oc_pos_set_threshold"
#define IVT_MSG_RESPONSE__B6_RESP_OC_NEG_SET_THRESHOLD "ivt_msg_response__b6_resp_oc_neg_set_threshold"
#define IVT_MSG_RESPONSE__B9_RESP_DEVICE_TYPE "ivt_msg_response__b9_resp_device_type"
#define IVT_MSG_RESPONSE__BA_RESP_SW_VER_MAJOR_HW "ivt_msg_response__ba_resp_sw_ver_major_hw"
#define IVT_MSG_RESPONSE__BB_RESP_SERIEN_NR "ivt_msg_response__bb_resp_serien_nr"
#define IVT_MSG_RESPONSE__BC_RESP_ART_N "ivt_msg_response__bc_resp_art_n"
#define IVT_MSG_RESPONSE__A0_RESP_ENDIANESS_I "ivt_msg_response__a0_resp_endianess_i"
#define IVT_MSG_RESPONSE__A1_RESP_ENDIANESS_U1 "ivt_msg_response__a1_resp_endianess_u1"
#define IVT_MSG_RESPONSE__A2_RESP_ENDIANESS_U2 "ivt_msg_response__a2_resp_endianess_u2"
#define IVT_MSG_RESPONSE__A3_RESP_ENDIANESS_U3 "ivt_msg_response__a3_resp_endianess_u3"
#define IVT_MSG_RESPONSE__A4_RESP_ENDIANESS_T "ivt_msg_response__a4_resp_endianess_t"
#define IVT_MSG_RESPONSE__A5_RESP_ENDIANESS_W "ivt_msg_response__a5_resp_endianess_w"
#define IVT_MSG_RESPONSE__A6_RESP_ENDIANESS_AS "ivt_msg_response__a6_resp_endianess_as"
#define IVT_MSG_RESPONSE__A7_RESP_ENDIANESS_WH "ivt_msg_response__a7_resp_endianess_wh"
#define IVT_MSG_RESPONSE__A0_RESP_TRIGGERMODE_I "ivt_msg_response__a0_resp_triggermode_i"
#define IVT_MSG_RESPONSE__A1_RESP_TRIGGERMODE_U1 "ivt_msg_response__a1_resp_triggermode_u1"
#define IVT_MSG_RESPONSE__A2_RESP_TRIGGERMODE_U2 "ivt_msg_response__a2_resp_triggermode_u2"
#define IVT_MSG_RESPONSE__A3_RESP_TRIGGERMODE_U3 "ivt_msg_response__a3_resp_triggermode_u3"
#define IVT_MSG_RESPONSE__A4_RESP_TRIGGERMODE_T "ivt_msg_response__a4_resp_triggermode_t"
#define IVT_MSG_RESPONSE__A5_RESP_TRIGGERMODE_W "ivt_msg_response__a5_resp_triggermode_w"
#define IVT_MSG_RESPONSE__A6_RESP_TRIGGERMODE_AS "ivt_msg_response__a6_resp_triggermode_as"
#define IVT_MSG_RESPONSE__A7_RESP_TRIGGERMODE_WH "ivt_msg_response__a7_resp_triggermode_wh"
#define IVT_MSG_RESPONSE__B4_RESP_ACTUAL_MODE "ivt_msg_response__b4_resp_actual_mode"
#define IVT_MSG_RESPONSE__B1_07_TRIGGER_WH "ivt_msg_response__b1_07_trigger_wh"
#define IVT_MSG_RESPONSE__B2_RESP_STORE_DEVICE_SN "ivt_msg_response__b2_resp_store_device_sn"
#define IVT_MSG_RESPONSE__BA_RESP_SW_VER_MINOR "ivt_msg_response__ba_resp_sw_ver_minor"
#define IVT_MSG_RESPONSE__B9_RESP_DEVICE_CURRENT "ivt_msg_response__b9_resp_device_current"
#define IVT_MSG_RESPONSE__80_RESP_MEASERROR_COUNT_MASK "ivt_msg_response__80_resp_measerror_count_mask"
#define IVT_MSG_RESPONSE__81_RESP_SYSTEMERROR_COUNT_MASK "ivt_msg_response__81_resp_systemerror_count_mask"
#define IVT_MSG_RESPONSE__82_RESP_ALLLOGDATA_COUNTER "ivt_msg_response__82_resp_alllogdata_counter"
#define IVT_MSG_RESPONSE__83_RESP_LOGDATA_COUNTER "ivt_msg_response__83_resp_logdata_counter"
#define IVT_MSG_RESPONSE__A0_RESP_CYCLETIME_I "ivt_msg_response__a0_resp_cycletime_i"
#define IVT_MSG_RESPONSE__A1_RESP_CYCLETIME_U1 "ivt_msg_response__a1_resp_cycletime_u1"
#define IVT_MSG_RESPONSE__A2_RESP_CYCLETIME_U2 "ivt_msg_response__a2_resp_cycletime_u2"
#define IVT_MSG_RESPONSE__A3_RESP_CYCLETIME_U3 "ivt_msg_response__a3_resp_cycletime_u3"
#define IVT_MSG_RESPONSE__A4_RESP_CYCLETIME_T "ivt_msg_response__a4_resp_cycletime_t"
#define IVT_MSG_RESPONSE__A5_RESP_CYCLETIME_W "ivt_msg_response__a5_resp_cycletime_w"
#define IVT_MSG_RESPONSE__A6_RESP_CYCLETIME_AS "ivt_msg_response__a6_resp_cycletime_as"
#define IVT_MSG_RESPONSE__A7_RESP_CYCLETIME_WH "ivt_msg_response__a7_resp_cycletime_wh"
#define IVT_MSG_RESPONSE__B1_06_TRIGGER_AS "ivt_msg_response__b1_06_trigger_as"
#define IVT_MSG_RESPONSE__B1_05_TRIGGER_W "ivt_msg_response__b1_05_trigger_w"
#define IVT_MSG_RESPONSE__B1_04_TRIGGER_T "ivt_msg_response__b1_04_trigger_t"
#define IVT_MSG_RESPONSE__B1_03_TRIGGER_U3 "ivt_msg_response__b1_03_trigger_u3"
#define IVT_MSG_RESPONSE__B1_02_TRIGGER_U2 "ivt_msg_response__b1_02_trigger_u2"
#define IVT_MSG_RESPONSE__B1_01_TRIGGER_U1 "ivt_msg_response__b1_01_trigger_u1"
#define IVT_MSG_RESPONSE__B1_00_TRIGGER_I "ivt_msg_response__b1_00_trigger_i"
#define IVT_MSG_RESPONSE__B4_RESP_STARTUP_MODE "ivt_msg_response__b4_resp_startup_mode"
#define IVT_MSG_RESPONSE__BF_RESTART_ALIVE_SN "ivt_msg_response__bf_restart_alive_sn"
#define IVT_MSG_RESPONSE__BA_RESP_SW_VER_REVISION "ivt_msg_response__ba_resp_sw_ver_revision"
#define IVT_MSG_RESPONSE__90_RESP_CAN_ID_SN_I "ivt_msg_response__90_resp_can_id_sn_i"
#define IVT_MSG_RESPONSE__91_RESP_CAN_ID_SN_U1 "ivt_msg_response__91_resp_can_id_sn_u1"
#define IVT_MSG_RESPONSE__92_RESP_CAN_ID_SN_U2 "ivt_msg_response__92_resp_can_id_sn_u2"
#define IVT_MSG_RESPONSE__93_RESP_CAN_ID_SN_U3 "ivt_msg_response__93_resp_can_id_sn_u3"
#define IVT_MSG_RESPONSE__94_RESP_CAN_ID_SN_T "ivt_msg_response__94_resp_can_id_sn_t"
#define IVT_MSG_RESPONSE__95_RESP_CAN_ID_SN_W "ivt_msg_response__95_resp_can_id_sn_w"
#define IVT_MSG_RESPONSE__96_RESP_CAN_ID_SN_AS "ivt_msg_response__96_resp_can_id_sn_as"
#define IVT_MSG_RESPONSE__97_RESP_CAN_ID_SN_WH "ivt_msg_response__97_resp_can_id_sn_wh"
#define IVT_MSG_RESPONSE__9D_RESP_CAN_ID_SN_COMMAND "ivt_msg_response__9d_resp_can_id_sn_command"
#define IVT_MSG_RESPONSE__9F_RESP_CAN_ID_SN_RESPONSE "ivt_msg_response__9f_resp_can_id_sn_response"
#define IVT_MSG_RESPONSE__B0_RESP_RESET_DEVICE_SN "ivt_msg_response__b0_resp_reset_device_sn"
#define IVT_MSG_RESPONSE__B4_RESP_CODE_LEVEL "ivt_msg_response__b4_resp_code_level"
#define IVT_MSG_RESPONSE__B5_RESP_OC_POS_RESET_THRESHOLD "ivt_msg_response__b5_resp_oc_pos_reset_threshold"
#define IVT_MSG_RESPONSE__B6_RESP_OC_NEG_RESET_THRESHOLD "ivt_msg_response__b6_resp_oc_neg_reset_threshold"
#define IVT_MSG_RESPONSE__B9_RESP_DEVICE_VOLTAGE_CHAN "ivt_msg_response__b9_resp_device_voltage_chan"
#define IVT_MSG_RESPONSE__BA_RESP_SW_VER_VEAR "ivt_msg_response__ba_resp_sw_ver_vear"
#define IVT_MSG_RESPONSE__B9_RESP_DEVICE_TOI "ivt_msg_response__b9_resp_device_toi"
#define IVT_MSG_RESPONSE__BA_RESP_SW_VER_MONTH "ivt_msg_response__ba_resp_sw_ver_month"
#define IVT_MSG_RESPONSE__B9_RESP_DEVICE_COM "ivt_msg_response__b9_resp_device_com"
#define IVT_MSG_RESPONSE__BA_RESP_SW_VER_DAY "ivt_msg_response__ba_resp_sw_ver_day"
#define IVT_MSG_RESPONSE__B9_RESP_DEVICE_V_SUPPLY "ivt_msg_response__b9_resp_device_v_supply"
#define IVT_MSG_RESPONSE__BA_RESP_SW_VER_INTERNAL "ivt_msg_response__ba_resp_sw_ver_internal"
/* END */

/* START */
#define IVT_MSG_RESULT_T "IVT_MSG_RESULT_T"

#define IVT_MSG_RESULT_T_IVT_ID_RESULT_T "ivt_msg_result_t_ivt_id_result_t"
#define IVT_MSG_RESULT_T_IVT_RESULT_T_SYSTEM_ERROR "ivt_msg_result_t_ivt_result_t_system_error"
#define IVT_MSG_RESULT_T_IVT_RESULT_T_MEASUREMENT_ERROR "ivt_msg_result_t_ivt_result_t_measurement_error"
#define IVT_MSG_RESULT_T_IVT_RESULT_T_CHANNEL_ERROR "ivt_msg_result_t_ivt_result_t_channel_error"
#define IVT_MSG_RESULT_T_IVT_RESULT_T_OCS "ivt_msg_result_t_ivt_result_t_ocs"
#define IVT_MSG_RESULT_T_IVT_MSGCOUNT_RESULT_T "ivt_msg_result_t_ivt_msgcount_result_t"
#define IVT_MSG_RESULT_T_IVT_RESULT_T "ivt_msg_result_t_ivt_result_t"
/* END */

/* START */
#define IVT_MSG_RESULT_U3 "IVT_MSG_RESULT_U3"

#define IVT_MSG_RESULT_U3_IVT_ID_RESULT_U3 "ivt_msg_result_u3_ivt_id_result_u3"
#define IVT_MSG_RESULT_U3_IVT_RESULT_U3_SYSTEM_ERROR "ivt_msg_result_u3_ivt_result_u3_system_error"
#define IVT_MSG_RESULT_U3_IVT_RESULT_U3_MEASUREMENT_ERROR "ivt_msg_result_u3_ivt_result_u3_measurement_error"
#define IVT_MSG_RESULT_U3_IVT_RESULT_U3_CHANNEL_ERROR "ivt_msg_result_u3_ivt_result_u3_channel_error"
#define IVT_MSG_RESULT_U3_IVT_RESULT_U3_OCS "ivt_msg_result_u3_ivt_result_u3_ocs"
#define IVT_MSG_RESULT_U3_IVT_MSGCOUNT_RESULT_U3 "ivt_msg_result_u3_ivt_msgcount_result_u3"
#define IVT_MSG_RESULT_U3_IVT_RESULT_U3 "ivt_msg_result_u3_ivt_result_u3"
/* END */

/* START */
#define IVT_MSG_RESULT_U2 "IVT_MSG_RESULT_U2"

#define IVT_MSG_RESULT_U2_IVT_ID_RESULT_U2 "ivt_msg_result_u2_ivt_id_result_u2"
#define IVT_MSG_RESULT_U2_IVT_RESULT_U2_SYSTEM_ERROR "ivt_msg_result_u2_ivt_result_u2_system_error"
#define IVT_MSG_RESULT_U2_IVT_RESULT_U2_MEASUREMENT_ERROR "ivt_msg_result_u2_ivt_result_u2_measurement_error"
#define IVT_MSG_RESULT_U2_IVT_RESULT_U2_CHANNEL_ERROR "ivt_msg_result_u2_ivt_result_u2_channel_error"
#define IVT_MSG_RESULT_U2_IVT_RESULT_U2_OCS "ivt_msg_result_u2_ivt_result_u2_ocs"
#define IVT_MSG_RESULT_U2_IVT_MSGCOUNT_RESULT_U2 "ivt_msg_result_u2_ivt_msgcount_result_u2"
#define IVT_MSG_RESULT_U2_IVT_RESULT_U2 "ivt_msg_result_u2_ivt_result_u2"
/* END */

/* START */
#define IVT_MSG_RESULT_U1 "IVT_MSG_RESULT_U1"

#define IVT_MSG_RESULT_U1_IVT_ID_RESULT_U1 "ivt_msg_result_u1_ivt_id_result_u1"
#define IVT_MSG_RESULT_U1_IVT_RESULT_U1_SYSTEM_ERROR "ivt_msg_result_u1_ivt_result_u1_system_error"
#define IVT_MSG_RESULT_U1_IVT_RESULT_U1_MEASUREMENT_ERROR "ivt_msg_result_u1_ivt_result_u1_measurement_error"
#define IVT_MSG_RESULT_U1_IVT_RESULT_U1_CHANNEL_ERROR "ivt_msg_result_u1_ivt_result_u1_channel_error"
#define IVT_MSG_RESULT_U1_IVT_RESULT_U1_OCS "ivt_msg_result_u1_ivt_result_u1_ocs"
#define IVT_MSG_RESULT_U1_IVT_MSGCOUNT_RESULT_U1 "ivt_msg_result_u1_ivt_msgcount_result_u1"
#define IVT_MSG_RESULT_U1_IVT_RESULT_U1 "ivt_msg_result_u1_ivt_result_u1"
/* END */

/* START */
#define IVT_MSG_RESULT_I "IVT_MSG_RESULT_I"

#define IVT_MSG_RESULT_I_IVT_ID_RESULT_I "ivt_msg_result_i_ivt_id_result_i"
#define IVT_MSG_RESULT_I_IVT_RESULT_I_SYSTEM_ERROR "ivt_msg_result_i_ivt_result_i_system_error"
#define IVT_MSG_RESULT_I_IVT_RESULT_I_MEASUREMENT_ERROR "ivt_msg_result_i_ivt_result_i_measurement_error"
#define IVT_MSG_RESULT_I_IVT_RESULT_I_CHANNEL_ERROR "ivt_msg_result_i_ivt_result_i_channel_error"
#define IVT_MSG_RESULT_I_IVT_RESULT_I_OCS "ivt_msg_result_i_ivt_result_i_ocs"
#define IVT_MSG_RESULT_I_IVT_MSGCOUNT_RESULT_I "ivt_msg_result_i_ivt_msgcount_result_i"
#define IVT_MSG_RESULT_I_IVT_RESULT_I "ivt_msg_result_i_ivt_result_i"
/* END */

/* START */
#define IVT_MSG_CMD "IVT_MSG_CMD"

#define IVT_MSG_CMD_IVT_ID_CMD "ivt_msg_cmd_ivt_id_cmd"
#define IVT_MSG_CMD__31_TRIGGER_SPARE "ivt_msg_cmd__31_trigger_spare"
#define IVT_MSG_CMD__10_SET_CAN_ID_VAL_I "ivt_msg_cmd__10_set_can_id_val_i"
#define IVT_MSG_CMD__11_SET_CAN_ID_VAL_U1 "ivt_msg_cmd__11_set_can_id_val_u1"
#define IVT_MSG_CMD__12_SET_CAN_ID_VAL_U2 "ivt_msg_cmd__12_set_can_id_val_u2"
#define IVT_MSG_CMD__13_SET_CAN_ID_VAL_U3 "ivt_msg_cmd__13_set_can_id_val_u3"
#define IVT_MSG_CMD__14_SET_CAN_ID_VAL_T "ivt_msg_cmd__14_set_can_id_val_t"
#define IVT_MSG_CMD__15_SET_CAN_ID_VAL_W "ivt_msg_cmd__15_set_can_id_val_w"
#define IVT_MSG_CMD__16_SET_CAN_ID_VAL_AS "ivt_msg_cmd__16_set_can_id_val_as"
#define IVT_MSG_CMD__17_SET_CAN_ID_VAL_WH "ivt_msg_cmd__17_set_can_id_val_wh"
#define IVT_MSG_CMD__1D_SET_CAN_ID_VAL_COMMAND "ivt_msg_cmd__1d_set_can_id_val_command"
#define IVT_MSG_CMD__1F_SET_CAN_ID_VAL_RESPONSE "ivt_msg_cmd__1f_set_can_id_val_response"
#define IVT_MSG_CMD__20_CONF_SIGN_I "ivt_msg_cmd__20_conf_sign_i"
#define IVT_MSG_CMD__21_CONF_SIGN_U1 "ivt_msg_cmd__21_conf_sign_u1"
#define IVT_MSG_CMD__22_CONF_SIGN_U2 "ivt_msg_cmd__22_conf_sign_u2"
#define IVT_MSG_CMD__23_CONF_SIGN_U3 "ivt_msg_cmd__23_conf_sign_u3"
#define IVT_MSG_CMD__24_CONF_SIGN_T "ivt_msg_cmd__24_conf_sign_t"
#define IVT_MSG_CMD__25_CONF_SIGN_W "ivt_msg_cmd__25_conf_sign_w"
#define IVT_MSG_CMD__26_CONF_SIGN_AS "ivt_msg_cmd__26_conf_sign_as"
#define IVT_MSG_CMD__27_CONF_SIGN_WH "ivt_msg_cmd__27_conf_sign_wh"
#define IVT_MSG_CMD__30_RESET_ITEM "ivt_msg_cmd__30_reset_item"
#define IVT_MSG_CMD__32_STORE_DUMMY "ivt_msg_cmd__32_store_dummy"
#define IVT_MSG_CMD__33_OC_TEST_TIME "ivt_msg_cmd__33_oc_test_time"
#define IVT_MSG_CMD__35_OC_POS_SET_THRESHOLD "ivt_msg_cmd__35_oc_pos_set_threshold"
#define IVT_MSG_CMD__36_OC_NEG_SET_THRESHOLD "ivt_msg_cmd__36_oc_neg_set_threshold"
#define IVT_MSG_CMD__3A_RESTART_TO_BITRATE "ivt_msg_cmd__3a_restart_to_bitrate"
#define IVT_MSG_CMD__3D_RESTART_DEFAULT_DUMMY "ivt_msg_cmd__3d_restart_default_dummy"
#define IVT_MSG_CMD__3F_RESTART_DUMMY "ivt_msg_cmd__3f_restart_dummy"
#define IVT_MSG_CMD__40_GET_MEASERROR_ITEM "ivt_msg_cmd__40_get_measerror_item"
#define IVT_MSG_CMD__41_GET_SYSTEMERROR_ITEM "ivt_msg_cmd__41_get_systemerror_item"
#define IVT_MSG_CMD__42_GET_ALLLOGDATA_ITEM "ivt_msg_cmd__42_get_alllogdata_item"
#define IVT_MSG_CMD__43_GET_LOGDATA_ITEM "ivt_msg_cmd__43_get_logdata_item"
#define IVT_MSG_CMD__60_GET_RESULT_DUMMY_I "ivt_msg_cmd__60_get_result_dummy_i"
#define IVT_MSG_CMD__61_GET_RESULT_DUMMY_U1 "ivt_msg_cmd__61_get_result_dummy_u1"
#define IVT_MSG_CMD__62_GET_RESULT_DUMMY_U2 "ivt_msg_cmd__62_get_result_dummy_u2"
#define IVT_MSG_CMD__63_GET_RESULT_DUMMY_U3 "ivt_msg_cmd__63_get_result_dummy_u3"
#define IVT_MSG_CMD__64_GET_RESULT_DUMMY_T "ivt_msg_cmd__64_get_result_dummy_t"
#define IVT_MSG_CMD__65_GET_RESULT_DUMMY_W "ivt_msg_cmd__65_get_result_dummy_w"
#define IVT_MSG_CMD__66_GET_RESULT_DUMMY_AS "ivt_msg_cmd__66_get_result_dummy_as"
#define IVT_MSG_CMD__67_GET_RESULT_DUMMY_WH "ivt_msg_cmd__67_get_result_dummy_wh"
#define IVT_MSG_CMD__73_GET_OC_TEST_DUMMY "ivt_msg_cmd__73_get_oc_test_dummy"
#define IVT_MSG_CMD__74_GET_MODE_DUMMY "ivt_msg_cmd__74_get_mode_dummy"
#define IVT_MSG_CMD__75_GET_OC_POS_DUMMY "ivt_msg_cmd__75_get_oc_pos_dummy"
#define IVT_MSG_CMD__76_GET_OC_NEG_DUMMY "ivt_msg_cmd__76_get_oc_neg_dummy"
#define IVT_MSG_CMD__79_GET_DEVICE_ID_DUMMY "ivt_msg_cmd__79_get_device_id_dummy"
#define IVT_MSG_CMD__7A_GET_SW_VERSION_DUMMY "ivt_msg_cmd__7a_get_sw_version_dummy"
#define IVT_MSG_CMD__7B_GET_SERIEN_NR_DUMMY "ivt_msg_cmd__7b_get_serien_nr_dummy"
#define IVT_MSG_CMD__7C_GET_ART_NR_DUMMY "ivt_msg_cmd__7c_get_art_nr_dummy"
#define IVT_MSG_CMD__20_CONF_ENDIANESS_I "ivt_msg_cmd__20_conf_endianess_i"
#define IVT_MSG_CMD__21_CONF_ENDIANESS_U1 "ivt_msg_cmd__21_conf_endianess_u1"
#define IVT_MSG_CMD__22_CONF_ENDIANESS_U2 "ivt_msg_cmd__22_conf_endianess_u2"
#define IVT_MSG_CMD__23_CONF_ENDIANESS_U3 "ivt_msg_cmd__23_conf_endianess_u3"
#define IVT_MSG_CMD__24_CONF_ENDIANESS_T "ivt_msg_cmd__24_conf_endianess_t"
#define IVT_MSG_CMD__25_CONF_ENDIANESS_W "ivt_msg_cmd__25_conf_endianess_w"
#define IVT_MSG_CMD__26_CONF_ENDIANESS_AS "ivt_msg_cmd__26_conf_endianess_as"
#define IVT_MSG_CMD__27_CONF_ENDIANESS_WH "ivt_msg_cmd__27_conf_endianess_wh"
#define IVT_MSG_CMD__20_CONF_TRIGGERMODE_I "ivt_msg_cmd__20_conf_triggermode_i"
#define IVT_MSG_CMD__21_CONF_TRIGGERMODE_U1 "ivt_msg_cmd__21_conf_triggermode_u1"
#define IVT_MSG_CMD__22_CONF_TRIGGERMODE_U2 "ivt_msg_cmd__22_conf_triggermode_u2"
#define IVT_MSG_CMD__23_CONF_TRIGGERMODE_U3 "ivt_msg_cmd__23_conf_triggermode_u3"
#define IVT_MSG_CMD__24_CONF_TRIGGERMODE_T "ivt_msg_cmd__24_conf_triggermode_t"
#define IVT_MSG_CMD__25_CONF_TRIGGERMODE_W "ivt_msg_cmd__25_conf_triggermode_w"
#define IVT_MSG_CMD__26_CONF_TRIGGERMODE_AS "ivt_msg_cmd__26_conf_triggermode_as"
#define IVT_MSG_CMD__27_CONF_TRIGGERMODE_WH "ivt_msg_cmd__27_conf_triggermode_wh"
#define IVT_MSG_CMD__34_ACTUAL_MODE "ivt_msg_cmd__34_actual_mode"
#define IVT_MSG_CMD__31_07_TRIGGER_WH "ivt_msg_cmd__31_07_trigger_wh"
#define IVT_MSG_CMD__20_CONF_CYCLETIME_I "ivt_msg_cmd__20_conf_cycletime_i"
#define IVT_MSG_CMD__21_CONF_CYCLETIME_U1 "ivt_msg_cmd__21_conf_cycletime_u1"
#define IVT_MSG_CMD__22_CONF_CYCLETIME_U2 "ivt_msg_cmd__22_conf_cycletime_u2"
#define IVT_MSG_CMD__23_CONF_CYCLETIME_U3 "ivt_msg_cmd__23_conf_cycletime_u3"
#define IVT_MSG_CMD__24_CONF_CYCLETIME_T "ivt_msg_cmd__24_conf_cycletime_t"
#define IVT_MSG_CMD__25_CONF_CYCLETIME_W "ivt_msg_cmd__25_conf_cycletime_w"
#define IVT_MSG_CMD__26_CONF_CYCLETIME_AS "ivt_msg_cmd__26_conf_cycletime_as"
#define IVT_MSG_CMD__27_CONF_CYCLETIME_WH "ivt_msg_cmd__27_conf_cycletime_wh"
#define IVT_MSG_CMD__31_06_TRIGGER_AS "ivt_msg_cmd__31_06_trigger_as"
#define IVT_MSG_CMD__31_05_TRIGGER_W "ivt_msg_cmd__31_05_trigger_w"
#define IVT_MSG_CMD__31_04_TRIGGER_T "ivt_msg_cmd__31_04_trigger_t"
#define IVT_MSG_CMD__31_03_TRIGGER_U3 "ivt_msg_cmd__31_03_trigger_u3"
#define IVT_MSG_CMD__31_02_TRIGGER_U2 "ivt_msg_cmd__31_02_trigger_u2"
#define IVT_MSG_CMD__31_01_TRIGGER_U1 "ivt_msg_cmd__31_01_trigger_u1"
#define IVT_MSG_CMD__31_00_TRIGGER_I "ivt_msg_cmd__31_00_trigger_i"
#define IVT_MSG_CMD__34_STARTUP_MODE "ivt_msg_cmd__34_startup_mode"
#define IVT_MSG_CMD__10_SET_CAN_ID_SN_I "ivt_msg_cmd__10_set_can_id_sn_i"
#define IVT_MSG_CMD__11_SET_CAN_ID_SN_U1 "ivt_msg_cmd__11_set_can_id_sn_u1"
#define IVT_MSG_CMD__12_SET_CAN_ID_SN_U2 "ivt_msg_cmd__12_set_can_id_sn_u2"
#define IVT_MSG_CMD__13_SET_CAN_ID_SN_U3 "ivt_msg_cmd__13_set_can_id_sn_u3"
#define IVT_MSG_CMD__14_SET_CAN_ID_SN_T "ivt_msg_cmd__14_set_can_id_sn_t"
#define IVT_MSG_CMD__15_SET_CAN_ID_SN_W "ivt_msg_cmd__15_set_can_id_sn_w"
#define IVT_MSG_CMD__16_SET_CAN_ID_SN_AS "ivt_msg_cmd__16_set_can_id_sn_as"
#define IVT_MSG_CMD__17_SET_CAN_ID_SN_WH "ivt_msg_cmd__17_set_can_id_sn_wh"
#define IVT_MSG_CMD__1D_SET_CAN_ID_SN_COMMAND "ivt_msg_cmd__1d_set_can_id_sn_command"
#define IVT_MSG_CMD__1F_SET_CAN_ID_SN_RESPONSE "ivt_msg_cmd__1f_set_can_id_sn_response"
#define IVT_MSG_CMD__30_RESET_DEVICE_SN "ivt_msg_cmd__30_reset_device_sn"
#define IVT_MSG_CMD__34_CODE_LEVEL "ivt_msg_cmd__34_code_level"
#define IVT_MSG_CMD__35_OC_POS_RESET_THRESHOLD "ivt_msg_cmd__35_oc_pos_reset_threshold"
#define IVT_MSG_CMD__36_OC_NEG_RESET_THRESHOLD "ivt_msg_cmd__36_oc_neg_reset_threshold"
#define IVT_MSG_CMD__50_GET_CAN_ID_SN_I "ivt_msg_cmd__50_get_can_id_sn_i"
#define IVT_MSG_CMD__51_GET_CAN_ID_SN_U1 "ivt_msg_cmd__51_get_can_id_sn_u1"
#define IVT_MSG_CMD__52_GET_CAN_ID_SN_U2 "ivt_msg_cmd__52_get_can_id_sn_u2"
#define IVT_MSG_CMD__53_GET_CAN_ID_SN_U3 "ivt_msg_cmd__53_get_can_id_sn_u3"
#define IVT_MSG_CMD__54_GET_CAN_ID_SN_T "ivt_msg_cmd__54_get_can_id_sn_t"
#define IVT_MSG_CMD__55_GET_CAN_ID_SN_W "ivt_msg_cmd__55_get_can_id_sn_w"
#define IVT_MSG_CMD__56_GET_CAN_ID_SN_AS "ivt_msg_cmd__56_get_can_id_sn_as"
#define IVT_MSG_CMD__57_GET_CAN_ID_SN_WH "ivt_msg_cmd__57_get_can_id_sn_wh"
#define IVT_MSG_CMD__5D_GET_CAN_ID_SN_COMMAND "ivt_msg_cmd__5d_get_can_id_sn_command"
#define IVT_MSG_CMD__5F_GET_CAN_ID_SN_RESPONSE "ivt_msg_cmd__5f_get_can_id_sn_response"
/* END */

enum ivts_types_id{
	e_ivts_int16_t = -8,
	e_ivts_uint16_t,
	e_ivts_uint64_t,
	e_ivts_float,
	e_ivts_uint8_t,
	e_ivts_int32_t,
	e_ivts_uint32_t,
	e_ivts_int8_t,

	e_ivts_ivt_msg_result_wh_ivt_id_result_wh,
	e_ivts_ivt_msg_result_as_ivt_id_result_as,
	e_ivts_ivt_msg_result_w_ivt_id_result_w,
	e_ivts_ivt_msg_response_ivt_id_response,
	e_ivts_ivt_msg_response__80_resp_measerror_item,
	e_ivts_ivt_msg_response__81_resp_systemerror_item,
	e_ivts_ivt_msg_response__82_resp_alllogdata_item,
	e_ivts_ivt_msg_response__83_resp_logdata_item,
	e_ivts_ivt_msg_response__b0_resp_reset_item,
	e_ivts_ivt_msg_response__b9_resp_device_type,
	e_ivts_ivt_msg_response__a0_resp_triggermode_i,
	e_ivts_ivt_msg_response__a1_resp_triggermode_u1,
	e_ivts_ivt_msg_response__a2_resp_triggermode_u2,
	e_ivts_ivt_msg_response__a3_resp_triggermode_u3,
	e_ivts_ivt_msg_response__a4_resp_triggermode_t,
	e_ivts_ivt_msg_response__a5_resp_triggermode_w,
	e_ivts_ivt_msg_response__a6_resp_triggermode_as,
	e_ivts_ivt_msg_response__a7_resp_triggermode_wh,
	e_ivts_ivt_msg_response__b4_resp_actual_mode,
	e_ivts_ivt_msg_response__b9_resp_device_current,
	e_ivts_ivt_msg_response__b4_resp_startup_mode,
	e_ivts_ivt_msg_response__b9_resp_device_voltage_chan,
	e_ivts_ivt_msg_response__b9_resp_device_toi,
	e_ivts_ivt_msg_response__b9_resp_device_com,
	e_ivts_ivt_msg_response__b9_resp_device_v_supply,
	e_ivts_ivt_msg_result_t_ivt_id_result_t,
	e_ivts_ivt_msg_result_u3_ivt_id_result_u3,
	e_ivts_ivt_msg_result_u2_ivt_id_result_u2,
	e_ivts_ivt_msg_result_u1_ivt_id_result_u1,
	e_ivts_ivt_msg_result_i_ivt_id_result_i,
	e_ivts_ivt_msg_cmd_ivt_id_cmd,
	e_ivts_ivt_msg_cmd__30_reset_item,
	e_ivts_ivt_msg_cmd__3a_restart_to_bitrate,
	e_ivts_ivt_msg_cmd__40_get_measerror_item,
	e_ivts_ivt_msg_cmd__41_get_systemerror_item,
	e_ivts_ivt_msg_cmd__42_get_alllogdata_item,
	e_ivts_ivt_msg_cmd__43_get_logdata_item,
	e_ivts_ivt_msg_cmd__20_conf_triggermode_i,
	e_ivts_ivt_msg_cmd__21_conf_triggermode_u1,
	e_ivts_ivt_msg_cmd__22_conf_triggermode_u2,
	e_ivts_ivt_msg_cmd__23_conf_triggermode_u3,
	e_ivts_ivt_msg_cmd__24_conf_triggermode_t,
	e_ivts_ivt_msg_cmd__25_conf_triggermode_w,
	e_ivts_ivt_msg_cmd__26_conf_triggermode_as,
	e_ivts_ivt_msg_cmd__27_conf_triggermode_wh,
	e_ivts_ivt_msg_cmd__34_actual_mode,
	e_ivts_ivt_msg_cmd__34_startup_mode
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
int ivts_fields_string_from_id(int id, char **v, size_t fields_size, size_t string_size);

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
int ivts_enum_fields(int enum_id, char **v, size_t fields_size, size_t string_size);

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
int ivts_serialize_from_id(int id, char *s, uint8_t *data, size_t *size);

/**
 * @brief get the number of signals in the message
 * 
 * @param[in] id the id of the message
 * 
 * @return return the number of the signals
*/
int ivts_n_fields_from_id(int id);

/**
 * @brief get the types of the signals in the message
 * 
 * @param[in] id the id of the message
 * @param[out] fields_types fields_types[i] contains the type id of the signal i (must be already allocated)
 * @param[in] fields_types_size max size of fields_types
 * 
 * @return the number of types set, 0 if the id is invalid or fields_types_size is too small
*/
int ivts_fields_types_from_id(int id, int *fields_types, int fields_types_size);

/**
 * @brief get the fields of an enum given the name of the message and the name of the signal
 * 
 * @param[in] msg_name name of the message to find
 * @param[in] sgn_name name of the signal to find
 * 
 * @return fields' strings vector
*/
std::vector<std::string> ivts_enum_fields_from_name(const std::string& msg_name, const std::string& sgn_name);


#endif
