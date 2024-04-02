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

#define PRIMARY_INTERVAL_STEERING_WHEEL_VERSION 1000
#define PRIMARY_INTERVAL_ECU_VERSION 1000
#define PRIMARY_INTERVAL_LV_VERSION 1000
#define PRIMARY_INTERVAL_HV_MAINBOARD_VERSION 1000
#define PRIMARY_INTERVAL_HV_CELLBOARD_VERSION 1000
#define PRIMARY_INTERVAL_HV_ERRORS 20
#define PRIMARY_INTERVAL_HV_DEBUG_SIGNALS 500
#define PRIMARY_INTERVAL_HV_FANS_STATUS 200
#define PRIMARY_INTERVAL_HV_SET_FANS_STATUS 200
#define PRIMARY_INTERVAL_HV_FEEDBACK_STATUS 50
#define PRIMARY_INTERVAL_HV_FEEDBACK_TS_VOLTAGE 50
#define PRIMARY_INTERVAL_HV_FEEDBACK_MISC_VOLTAGE 50
#define PRIMARY_INTERVAL_HV_FEEDBACK_SD_VOLTAGE 50
#define PRIMARY_INTERVAL_HV_IMD_STATUS 20
#define PRIMARY_INTERVAL_HV_STATUS 20
#define PRIMARY_INTERVAL_HV_BALANCING_STATUS 50
#define PRIMARY_INTERVAL_LV_STATUS 20
#define PRIMARY_INTERVAL_LV_RADIATOR_SPEED 200
#define PRIMARY_INTERVAL_LV_PUMPS_SPEED 200
#define PRIMARY_INTERVAL_LV_ERRORS 20
#define PRIMARY_INTERVAL_LV_FEEDBACK_TS_VOLTAGE 50
#define PRIMARY_INTERVAL_LV_FEEDBACK_SD_VOLTAGE 50
#define PRIMARY_INTERVAL_LV_FEEDBACK_ENCLOSURE_VOLTAGE 50
#define PRIMARY_INTERVAL_LV_FEEDBACK_GPIO_EXTENDER 50
#define PRIMARY_INTERVAL_LV_INVERTER_CONNECTION_STATUS 20
#define PRIMARY_INTERVAL_TLM_STATUS 200
#define PRIMARY_INTERVAL_HANDCART_STATUS 20
#define PRIMARY_INTERVAL_HANDCART_SETTINGS 200
#define PRIMARY_INTERVAL_ECU_STATUS 20
#define PRIMARY_INTERVAL_ECU_INVERTER_STATUS 50
#define PRIMARY_INTERVAL_ECU_CONTROL_STATUS 50
#define PRIMARY_INTERVAL_ECU_ERRORS 20
#define PRIMARY_INTERVAL_ECU_FEEDBACKS 50
#define PRIMARY_INTERVAL_ECU_POWER_MAPS 200
#define PRIMARY_INTERVAL_ECU_SET_POWER_MAPS 200
#define PRIMARY_INTERVAL_ECU_PTT_STATUS 200
#define PRIMARY_INTERVAL_ECU_SET_PTT_STATUS 200
#define PRIMARY_INTERVAL_INV_L_REQUEST 10
#define PRIMARY_INTERVAL_CONTROL_OUTPUT 20
#define PRIMARY_INTERVAL_CONTROL_STATUS 20
#define PRIMARY_INTERVAL_INV_R_REQUEST 10
#define PRIMARY_INTERVAL_INV_L_RESPONSE 100
#define PRIMARY_INTERVAL_INV_R_RESPONSE 100
#define PRIMARY_INTERVAL_LV_CURRENT_BATTERY 50
#define PRIMARY_INTERVAL_LV_CURRENT_CHARGER 50
#define PRIMARY_INTERVAL_LV_TOTAL_VOLTAGE 50
#define PRIMARY_INTERVAL_LV_CELLS_VOLTAGE 50
#define PRIMARY_INTERVAL_LV_CELLS_VOLTAGE_STATS 50
#define PRIMARY_INTERVAL_LV_CELLS_TEMP 50
#define PRIMARY_INTERVAL_LV_CELLS_TEMP_STATS 50
#define PRIMARY_INTERVAL_HV_CURRENT 50
#define PRIMARY_INTERVAL_HV_POWER 50
#define PRIMARY_INTERVAL_HV_ENERGY 50
#define PRIMARY_INTERVAL_HV_SOC 50
#define PRIMARY_INTERVAL_HV_TOTAL_VOLTAGE 50
#define PRIMARY_INTERVAL_HV_CELLS_VOLTAGE 50
#define PRIMARY_INTERVAL_HV_CELLS_VOLTAGE_STATS 50
#define PRIMARY_INTERVAL_HV_CELLS_TEMP 50
#define PRIMARY_INTERVAL_HV_CELLS_TEMP_STATS 50
#define PRIMARY_INTERVAL_DEBUG_SIGNAL_1 20


#define PRIMARY_INDEX_NLG5_DIAG_TX 0
#define PRIMARY_INDEX_NLG5_DIAG_RX 1
#define PRIMARY_INDEX_NLG5_ERR 2
#define PRIMARY_INDEX_NLG5_TEMP 3
#define PRIMARY_INDEX_NLG5_ACT_II 4
#define PRIMARY_INDEX_NLG5_ACT_I 5
#define PRIMARY_INDEX_NLG5_ST 6
#define PRIMARY_INDEX_NLG5_CTL 7
#define PRIMARY_INDEX_HV_JMP_TO_BLT 8
#define PRIMARY_INDEX_HV_FLASH_MAINBOARD_TX 9
#define PRIMARY_INDEX_HV_FLASH_MAINBOARD_RX 10
#define PRIMARY_INDEX_HV_FLASH_CELLBOARD_0_TX 11
#define PRIMARY_INDEX_HV_FLASH_CELLBOARD_0_RX 12
#define PRIMARY_INDEX_HV_FLASH_CELLBOARD_1_TX 13
#define PRIMARY_INDEX_HV_FLASH_CELLBOARD_1_RX 14
#define PRIMARY_INDEX_HV_FLASH_CELLBOARD_2_TX 15
#define PRIMARY_INDEX_HV_FLASH_CELLBOARD_2_RX 16
#define PRIMARY_INDEX_HV_FLASH_CELLBOARD_3_TX 17
#define PRIMARY_INDEX_HV_FLASH_CELLBOARD_3_RX 18
#define PRIMARY_INDEX_HV_FLASH_CELLBOARD_4_TX 19
#define PRIMARY_INDEX_HV_FLASH_CELLBOARD_4_RX 20
#define PRIMARY_INDEX_HV_FLASH_CELLBOARD_5_TX 21
#define PRIMARY_INDEX_HV_FLASH_CELLBOARD_5_RX 22
#define PRIMARY_INDEX_LV_JMP_TO_BLT 23
#define PRIMARY_INDEX_LV_FLASH_BMS_TX 24
#define PRIMARY_INDEX_LV_FLASH_BMS_RX 25
#define PRIMARY_INDEX_ECU_JMP_TO_BLT 26
#define PRIMARY_INDEX_ECU_FLASH_TX 27
#define PRIMARY_INDEX_ECU_FLASH_RX 28
#define PRIMARY_INDEX_STEERING_WHEEL_JMP_TO_BLT 29
#define PRIMARY_INDEX_STEERING_WHEEL_FLASH_TX 30
#define PRIMARY_INDEX_STEERING_WHEEL_FLASH_RX 31
#define PRIMARY_INDEX_STEERING_WHEEL_VERSION 32
#define PRIMARY_INDEX_ECU_VERSION 33
#define PRIMARY_INDEX_LV_VERSION 34
#define PRIMARY_INDEX_TLM_VERSION 35
#define PRIMARY_INDEX_HV_MAINBOARD_VERSION 36
#define PRIMARY_INDEX_HV_CELLBOARD_VERSION 37
#define PRIMARY_INDEX_HV_ERRORS 38
#define PRIMARY_INDEX_HV_DEBUG_SIGNALS 39
#define PRIMARY_INDEX_HV_FANS_STATUS 40
#define PRIMARY_INDEX_HV_SET_FANS_STATUS 41
#define PRIMARY_INDEX_HV_FEEDBACK_STATUS 42
#define PRIMARY_INDEX_HV_FEEDBACK_TS_VOLTAGE 43
#define PRIMARY_INDEX_HV_FEEDBACK_MISC_VOLTAGE 44
#define PRIMARY_INDEX_HV_FEEDBACK_SD_VOLTAGE 45
#define PRIMARY_INDEX_HV_IMD_STATUS 46
#define PRIMARY_INDEX_HV_STATUS 47
#define PRIMARY_INDEX_HV_SET_STATUS_ECU 48
#define PRIMARY_INDEX_HV_SET_STATUS_HANDCART 49
#define PRIMARY_INDEX_HV_BALANCING_STATUS 50
#define PRIMARY_INDEX_HV_SET_BALANCING_STATUS 51
#define PRIMARY_INDEX_LV_STATUS 52
#define PRIMARY_INDEX_LV_RADIATOR_SPEED 53
#define PRIMARY_INDEX_LV_PUMPS_SPEED 54
#define PRIMARY_INDEX_LV_SET_RADIATOR_SPEED 55
#define PRIMARY_INDEX_LV_SET_PUMPS_SPEED 56
#define PRIMARY_INDEX_LV_ERRORS 57
#define PRIMARY_INDEX_LV_FEEDBACK_TS_VOLTAGE 58
#define PRIMARY_INDEX_LV_FEEDBACK_SD_VOLTAGE 59
#define PRIMARY_INDEX_LV_FEEDBACK_ENCLOSURE_VOLTAGE 60
#define PRIMARY_INDEX_LV_FEEDBACK_GPIO_EXTENDER 61
#define PRIMARY_INDEX_LV_CAN_FLASH_REQ 62
#define PRIMARY_INDEX_LV_CAN_FLASH_ACK 63
#define PRIMARY_INDEX_LV_INVERTER_CONNECTION_STATUS 64
#define PRIMARY_INDEX_LV_SET_INVERTER_CONNECTION_STATUS 65
#define PRIMARY_INDEX_TLM_STATUS 66
#define PRIMARY_INDEX_TLM_SET_STATUS 67
#define PRIMARY_INDEX_HANDCART_STATUS 68
#define PRIMARY_INDEX_HANDCART_SETTINGS 69
#define PRIMARY_INDEX_HANDCART_SET_SETTINGS 70
#define PRIMARY_INDEX_ECU_STATUS 71
#define PRIMARY_INDEX_ECU_SET_STATUS 72
#define PRIMARY_INDEX_ECU_INVERTER_STATUS 73
#define PRIMARY_INDEX_ECU_CONTROL_STATUS 74
#define PRIMARY_INDEX_ECU_ERRORS 75
#define PRIMARY_INDEX_ECU_FEEDBACKS 76
#define PRIMARY_INDEX_ECU_POWER_MAPS 77
#define PRIMARY_INDEX_ECU_SET_POWER_MAPS 78
#define PRIMARY_INDEX_ECU_PTT_STATUS 79
#define PRIMARY_INDEX_ECU_SET_PTT_STATUS 80
#define PRIMARY_INDEX_INV_L_REQUEST 81
#define PRIMARY_INDEX_CONTROL_OUTPUT 82
#define PRIMARY_INDEX_CONTROL_STATUS 83
#define PRIMARY_INDEX_INV_R_REQUEST 84
#define PRIMARY_INDEX_INV_L_RESPONSE 85
#define PRIMARY_INDEX_INV_R_RESPONSE 86
#define PRIMARY_INDEX_LV_CURRENT_BATTERY 87
#define PRIMARY_INDEX_LV_CURRENT_CHARGER 88
#define PRIMARY_INDEX_LV_TOTAL_VOLTAGE 89
#define PRIMARY_INDEX_LV_CELLS_VOLTAGE 90
#define PRIMARY_INDEX_LV_CELLS_VOLTAGE_STATS 91
#define PRIMARY_INDEX_LV_CELLS_TEMP 92
#define PRIMARY_INDEX_LV_CELLS_TEMP_STATS 93
#define PRIMARY_INDEX_HV_CURRENT 94
#define PRIMARY_INDEX_HV_POWER 95
#define PRIMARY_INDEX_HV_ENERGY 96
#define PRIMARY_INDEX_HV_SOC 97
#define PRIMARY_INDEX_HV_TOTAL_VOLTAGE 98
#define PRIMARY_INDEX_HV_CELLS_VOLTAGE 99
#define PRIMARY_INDEX_HV_CELLS_VOLTAGE_STATS 100
#define PRIMARY_INDEX_HV_CELLS_TEMP 101
#define PRIMARY_INDEX_HV_CELLS_TEMP_STATS 102
#define PRIMARY_INDEX_DEBUG_SIGNAL_1 103



typedef struct {
    uint8_t activated[13];
    uint8_t timeout[13];
    canlib_watchdog_timestamp last_reset[104];
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
