#ifndef primary_WATCHDOG_H
#define primary_WATCHDOG_H

#include <inttypes.h>
#include <string.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef CANLIB_WATCHDOG_TIMESTAMP_TYPE
#define CANLIB_WATCHDOG_TIMESTAMP_TYPE
typedef uint32_t canlib_watchdog_timestamp;
#endif // CANLIB_WATCHDOG_TIMESTAMP_TYPE

#ifndef CANLIB_MESSAGE_ID_TYPE
#define CANLIB_MESSAGE_ID_TYPE
typedef uint16_t canlib_message_id;
#endif // CANLIB_MESSAGE_ID_TYPE

#ifndef CANLIB_WATCHDOG_CALLBACK
#define CANLIB_WATCHDOG_CALLBACK
typedef void (*canlib_watchdog_callback)(int);
#endif // CANLIB_WATCHDOG_CALLBACK

#ifndef CANLIB_BITMASK_UTILS
#define CANLIB_BITMASK_UTILS

#define CANLIB_BITMASK_TYPE uint8_t
#define CANLIB_BITMASK_TYPE_BITS 8

#define CANLIB_BITMASK_ARRAY(b) (1 << ((b) % CANLIB_BITMASK_TYPE_BITS))
#define CANLIB_BITSLOT_ARRAY(b) ((b) / CANLIB_BITMASK_TYPE_BITS)
#define CANLIB_BITSET_ARRAY(a, b) ((a)[CANLIB_BITSLOT_ARRAY(b)] |= CANLIB_BITMASK_ARRAY(b))
#define CANLIB_BITCLEAR_ARRAY(a, b) ((a)[CANLIB_BITSLOT_ARRAY(b)] &= ~CANLIB_BITMASK_ARRAY(b))
#define CANLIB_BITTEST_ARRAY(a, b) ((a)[CANLIB_BITSLOT_ARRAY(b)] & CANLIB_BITMASK_ARRAY(b))
#define CANLIB_BITNSLOTS_ARRAY(nb) ((nb + CANLIB_BITMASK_TYPE_BITS - 1) / CANLIB_BITMASK_TYPE_BITS)

#define CANLIB_BITMASK(b) (1 << (b))
#define CANLIB_BITSET(a, b) ((a) |= CANLIB_BITMASK(b))
#define CANLIB_BITCLEAR(a, b) ((a) &= ~CANLIB_BITMASK(b))
#define CANLIB_BITTEST(a, b) ((a) & CANLIB_BITMASK(b))

#endif // CANLIB_BITMASK_UTILS

#ifndef CANLIB_UNUSED
#define CANLIB_UNUSED(expr) do { (void)(expr); } while (0)
#endif // CANLIB_UNUSED

#ifndef CANLIB_INTERVAL_THRESHOLD
#define CANLIB_INTERVAL_THRESHOLD 500
#endif // CANLIB_INTERVAL_THRESHOLD

#define PRIMARY_INTERVAL_STEER_VERSION 1000
#define PRIMARY_INTERVAL_DAS_VERSION 1000
#define PRIMARY_INTERVAL_MAINBOARD_VERSION 1000
#define PRIMARY_INTERVAL_LV_VERSION 1000
#define PRIMARY_INTERVAL_TLM_VERSION 1000
#define PRIMARY_INTERVAL_CELLBOARD_VERSION 1000
#define PRIMARY_INTERVAL_AMBIENT_TEMPERATURE 1000
#define PRIMARY_INTERVAL_DATA_LOGGER 1000
#define PRIMARY_INTERVAL_TLM_STATUS 1000
#define PRIMARY_INTERVAL_STEER_SYSTEM_STATUS 1000
#define PRIMARY_INTERVAL_HV_VOLTAGE 10
#define PRIMARY_INTERVAL_HV_CURRENT 10
#define PRIMARY_INTERVAL_HV_TEMP 100
#define PRIMARY_INTERVAL_HV_ERRORS 10
#define PRIMARY_INTERVAL_TS_STATUS 10
#define PRIMARY_INTERVAL_SET_TS_STATUS_DAS 100
#define PRIMARY_INTERVAL_SET_TS_STATUS_HANDCART 100
#define PRIMARY_INTERVAL_STEER_STATUS 100
#define PRIMARY_INTERVAL_CAR_STATUS 100
#define PRIMARY_INTERVAL_DAS_ERRORS 10
#define PRIMARY_INTERVAL_ECU_FEEDBACKS 300
#define PRIMARY_INTERVAL_LV_STATUS 200
#define PRIMARY_INTERVAL_LV_CURRENTS 300
#define PRIMARY_INTERVAL_LV_CELLS_VOLTAGE 200
#define PRIMARY_INTERVAL_LV_TOTAL_VOLTAGE 200
#define PRIMARY_INTERVAL_LV_CELLS_TEMP 200
#define PRIMARY_INTERVAL_COOLING_STATUS 1000
#define PRIMARY_INTERVAL_SET_INVERTER_CONNECTION_STATUS 100
#define PRIMARY_INTERVAL_INVERTER_CONNECTION_STATUS 300
#define PRIMARY_INTERVAL_LV_ERRORS 300
#define PRIMARY_INTERVAL_LV_HEALTH_SIGNALS 300
#define PRIMARY_INTERVAL_LV_FEEDBACKS 300
#define PRIMARY_INTERVAL_SHUTDOWN_STATUS 500
#define PRIMARY_INTERVAL_LV_CAN_FLASH_ACK 50
#define PRIMARY_INTERVAL_HV_CELLS_VOLTAGE 100
#define PRIMARY_INTERVAL_HV_CELLS_TEMP 100
#define PRIMARY_INTERVAL_HV_CELL_BALANCING_STATUS 500
#define PRIMARY_INTERVAL_SPEED 10
#define PRIMARY_INTERVAL_INV_L_REQUEST 10
#define PRIMARY_INTERVAL_INV_R_REQUEST 10
#define PRIMARY_INTERVAL_INV_L_RESPONSE 100
#define PRIMARY_INTERVAL_INV_R_RESPONSE 100
#define PRIMARY_INTERVAL_CONTROL_OUTPUT 100
#define PRIMARY_INTERVAL_HANDCART_STATUS 500
#define PRIMARY_INTERVAL_HANDCART_SETTINGS 500
#define PRIMARY_INTERVAL_HANDCART_SETTINGS_SET 500
#define PRIMARY_INTERVAL_REGEN_MANUAL_COMMAND 100


#define PRIMARY_INDEX_NLG5_DIAG_TX 0
#define PRIMARY_INDEX_NLG5_DIAG_RX 1
#define PRIMARY_INDEX_NLG5_ERR 2
#define PRIMARY_INDEX_NLG5_TEMP 3
#define PRIMARY_INDEX_NLG5_ACT_II 4
#define PRIMARY_INDEX_NLG5_ACT_I 5
#define PRIMARY_INDEX_NLG5_ST 6
#define PRIMARY_INDEX_NLG5_CTL 7
#define PRIMARY_INDEX_BMS_HV_JMP_TO_BLT 8
#define PRIMARY_INDEX_FLASH_BMS_HV_TX 9
#define PRIMARY_INDEX_FLASH_BMS_HV_RX 10
#define PRIMARY_INDEX_HV_CAN_FORWARD 11
#define PRIMARY_INDEX_FLASH_CELLBOARD_0_TX 12
#define PRIMARY_INDEX_FLASH_CELLBOARD_0_RX 13
#define PRIMARY_INDEX_FLASH_CELLBOARD_1_TX 14
#define PRIMARY_INDEX_FLASH_CELLBOARD_1_RX 15
#define PRIMARY_INDEX_FLASH_CELLBOARD_2_TX 16
#define PRIMARY_INDEX_FLASH_CELLBOARD_2_RX 17
#define PRIMARY_INDEX_FLASH_CELLBOARD_3_TX 18
#define PRIMARY_INDEX_FLASH_CELLBOARD_3_RX 19
#define PRIMARY_INDEX_FLASH_CELLBOARD_4_TX 20
#define PRIMARY_INDEX_FLASH_CELLBOARD_4_RX 21
#define PRIMARY_INDEX_FLASH_CELLBOARD_5_TX 22
#define PRIMARY_INDEX_FLASH_CELLBOARD_5_RX 23
#define PRIMARY_INDEX_BMS_LV_JMP_TO_BLT 24
#define PRIMARY_INDEX_FLASH_BMS_LV_TX 25
#define PRIMARY_INDEX_FLASH_BMS_LV_RX 26
#define PRIMARY_INDEX_ECU_JMP_TO_BLT 27
#define PRIMARY_INDEX_FLASH_ECU_TX 28
#define PRIMARY_INDEX_FLASH_ECU_RX 29
#define PRIMARY_INDEX_STEERING_JMP_TO_BLT 30
#define PRIMARY_INDEX_FLASH_STEERING_TX 31
#define PRIMARY_INDEX_FLASH_STEERING_RX 32
#define PRIMARY_INDEX_STEER_VERSION 33
#define PRIMARY_INDEX_DAS_VERSION 34
#define PRIMARY_INDEX_MAINBOARD_VERSION 35
#define PRIMARY_INDEX_LV_VERSION 36
#define PRIMARY_INDEX_TLM_VERSION 37
#define PRIMARY_INDEX_CELLBOARD_VERSION 38
#define PRIMARY_INDEX_AMBIENT_TEMPERATURE 39
#define PRIMARY_INDEX_DATA_LOGGER 40
#define PRIMARY_INDEX_SET_TLM_STATUS 41
#define PRIMARY_INDEX_TLM_STATUS 42
#define PRIMARY_INDEX_STEER_SYSTEM_STATUS 43
#define PRIMARY_INDEX_HV_VOLTAGE 44
#define PRIMARY_INDEX_HV_CURRENT 45
#define PRIMARY_INDEX_HV_TEMP 46
#define PRIMARY_INDEX_HV_ERRORS 47
#define PRIMARY_INDEX_HV_FANS_OVERRIDE 48
#define PRIMARY_INDEX_HV_CAN_FORWARD_STATUS 49
#define PRIMARY_INDEX_HV_FANS_OVERRIDE_STATUS 50
#define PRIMARY_INDEX_HV_FEEDBACK_STATUS 51
#define PRIMARY_INDEX_HV_FEEDBACK_TS_VOLTAGE 52
#define PRIMARY_INDEX_HV_FEEDBACK_MISC_VOLTAGE 53
#define PRIMARY_INDEX_HV_FEEDBACK_SD_VOLTAGE 54
#define PRIMARY_INDEX_HV_IMD_STATUS 55
#define PRIMARY_INDEX_TS_STATUS 56
#define PRIMARY_INDEX_SET_TS_STATUS_DAS 57
#define PRIMARY_INDEX_SET_TS_STATUS_HANDCART 58
#define PRIMARY_INDEX_STEER_STATUS 59
#define PRIMARY_INDEX_SET_CAR_STATUS 60
#define PRIMARY_INDEX_SET_PEDAL_CALIBRATION 61
#define PRIMARY_INDEX_PEDAL_CALIBRATION_ACK 62
#define PRIMARY_INDEX_CAR_STATUS 63
#define PRIMARY_INDEX_DAS_ERRORS 64
#define PRIMARY_INDEX_ECU_FEEDBACKS 65
#define PRIMARY_INDEX_LV_STATUS 66
#define PRIMARY_INDEX_LV_CURRENTS 67
#define PRIMARY_INDEX_LV_CELLS_VOLTAGE 68
#define PRIMARY_INDEX_LV_TOTAL_VOLTAGE 69
#define PRIMARY_INDEX_LV_CELLS_TEMP 70
#define PRIMARY_INDEX_COOLING_STATUS 71
#define PRIMARY_INDEX_SET_RADIATOR_SPEED 72
#define PRIMARY_INDEX_SET_PUMPS_SPEED 73
#define PRIMARY_INDEX_SET_INVERTER_CONNECTION_STATUS 74
#define PRIMARY_INDEX_INVERTER_CONNECTION_STATUS 75
#define PRIMARY_INDEX_LV_ERRORS 76
#define PRIMARY_INDEX_LV_HEALTH_SIGNALS 77
#define PRIMARY_INDEX_LV_FEEDBACKS 78
#define PRIMARY_INDEX_SHUTDOWN_STATUS 79
#define PRIMARY_INDEX_LV_CAN_FLASH_REQ 80
#define PRIMARY_INDEX_LV_CAN_FLASH_ACK 81
#define PRIMARY_INDEX_MARKER 82
#define PRIMARY_INDEX_HV_CELLS_VOLTAGE 83
#define PRIMARY_INDEX_HV_CELLS_TEMP 84
#define PRIMARY_INDEX_HV_CELL_BALANCING_STATUS 85
#define PRIMARY_INDEX_SET_CELL_BALANCING_STATUS 86
#define PRIMARY_INDEX_SPEED 87
#define PRIMARY_INDEX_INV_L_REQUEST 88
#define PRIMARY_INDEX_INV_R_REQUEST 89
#define PRIMARY_INDEX_INV_L_RESPONSE 90
#define PRIMARY_INDEX_INV_R_RESPONSE 91
#define PRIMARY_INDEX_CONTROL_OUTPUT 92
#define PRIMARY_INDEX_LC_RESET 93
#define PRIMARY_INDEX_HANDCART_STATUS 94
#define PRIMARY_INDEX_HANDCART_SETTINGS 95
#define PRIMARY_INDEX_HANDCART_SETTINGS_SET 96
#define PRIMARY_INDEX_SET_PTT_STATUS 97
#define PRIMARY_INDEX_PTT_STATUS 98
#define PRIMARY_INDEX_REGEN_MANUAL_COMMAND 99



typedef struct {
    uint8_t activated[13];
    uint8_t timeout[13];
    canlib_watchdog_timestamp last_reset[100];
} primary_watchdog;

int primary_watchdog_interval_from_id(uint16_t message_id);
int primary_watchdog_index_from_id(uint16_t message_id);
void primary_watchdog_free(primary_watchdog *watchdog);
void primary_watchdog_reset(primary_watchdog *watchdog, canlib_message_id id, canlib_watchdog_timestamp timestamp);
void primary_watchdog_reset_all(primary_watchdog *watchdog, canlib_watchdog_timestamp timestamp);
void primary_watchdog_timeout(primary_watchdog *watchdog, canlib_watchdog_timestamp timestamp);



#ifdef __cplusplus
}
#endif

#endif // primary_NETWORK_H
