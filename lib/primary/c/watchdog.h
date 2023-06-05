#ifndef primary_WATCHDOG_H
#define primary_WATCHDOG_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdlib.h>
#include <memory.h>

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


#define primary_WATCHDOG_INDEX_BMS_HV_JMP_TO_BLT 0
#define primary_WATCHDOG_INDEX_BMS_LV_JMP_TO_BLT 1
#define primary_WATCHDOG_INDEX_STEER_VERSION 2
#define primary_WATCHDOG_INDEX_DAS_VERSION 3
#define primary_WATCHDOG_INDEX_HV_VERSION 4
#define primary_WATCHDOG_INDEX_LV_VERSION 5
#define primary_WATCHDOG_INDEX_TLM_VERSION 6
#define primary_WATCHDOG_INDEX_TIMESTAMP 7
#define primary_WATCHDOG_INDEX_AMBIENT_TEMPERATURE 8
#define primary_WATCHDOG_INDEX_DATA_LOGGER 9
#define primary_WATCHDOG_INDEX_SET_TLM_STATUS 10
#define primary_WATCHDOG_INDEX_TLM_STATUS 11
#define primary_WATCHDOG_INDEX_STEER_SYSTEM_STATUS 12
#define primary_WATCHDOG_INDEX_HV_VOLTAGE 13
#define primary_WATCHDOG_INDEX_HV_CURRENT 14
#define primary_WATCHDOG_INDEX_HV_TEMP 15
#define primary_WATCHDOG_INDEX_HV_ERRORS 16
#define primary_WATCHDOG_INDEX_HV_CAN_FORWARD 17
#define primary_WATCHDOG_INDEX_HV_FANS_OVERRIDE 18
#define primary_WATCHDOG_INDEX_HV_CAN_FORWARD_STATUS 19
#define primary_WATCHDOG_INDEX_HV_FANS_OVERRIDE_STATUS 20
#define primary_WATCHDOG_INDEX_HV_FEEDBACKS_STATUS 21
#define primary_WATCHDOG_INDEX_HV_IMD_STATUS 22
#define primary_WATCHDOG_INDEX_TS_STATUS_DAS 23
#define primary_WATCHDOG_INDEX_TS_STATUS_STEER 24
#define primary_WATCHDOG_INDEX_TS_STATUS_HANDCART 25
#define primary_WATCHDOG_INDEX_SET_TS_STATUS_DAS 26
#define primary_WATCHDOG_INDEX_SET_TS_STATUS_HANDCART 27
#define primary_WATCHDOG_INDEX_STEER_STATUS 28
#define primary_WATCHDOG_INDEX_SET_CAR_STATUS 29
#define primary_WATCHDOG_INDEX_SET_PEDALS_RANGE 30
#define primary_WATCHDOG_INDEX_SET_STEERING_ANGLE_RANGE 31
#define primary_WATCHDOG_INDEX_CAR_STATUS 32
#define primary_WATCHDOG_INDEX_DAS_ERRORS 33
#define primary_WATCHDOG_INDEX_LV_CURRENT 34
#define primary_WATCHDOG_INDEX_LV_VOLTAGE 35
#define primary_WATCHDOG_INDEX_LV_TOTAL_VOLTAGE 36
#define primary_WATCHDOG_INDEX_LV_TEMPERATURE 37
#define primary_WATCHDOG_INDEX_COOLING_STATUS 38
#define primary_WATCHDOG_INDEX_SET_RADIATOR_SPEED 39
#define primary_WATCHDOG_INDEX_SET_PUMPS_SPEED 40
#define primary_WATCHDOG_INDEX_SET_INVERTER_CONNECTION_STATUS 41
#define primary_WATCHDOG_INDEX_INVERTER_CONNECTION_STATUS 42
#define primary_WATCHDOG_INDEX_LV_ERRORS 43
#define primary_WATCHDOG_INDEX_SHUTDOWN_STATUS 44
#define primary_WATCHDOG_INDEX_MARKER 45
#define primary_WATCHDOG_INDEX_HV_CELLS_VOLTAGE 46
#define primary_WATCHDOG_INDEX_HV_CELLS_TEMP 47
#define primary_WATCHDOG_INDEX_HV_CELL_BALANCING_STATUS 48
#define primary_WATCHDOG_INDEX_SET_CELL_BALANCING_STATUS 49
#define primary_WATCHDOG_INDEX_HANDCART_STATUS 50
#define primary_WATCHDOG_INDEX_SPEED 51
#define primary_WATCHDOG_INDEX_INV_L_REQUEST 52
#define primary_WATCHDOG_INDEX_INV_R_REQUEST 53
#define primary_WATCHDOG_INDEX_INV_L_RESPONSE 54
#define primary_WATCHDOG_INDEX_INV_R_RESPONSE 55
#define primary_WATCHDOG_INDEX_FLASH_CELLBOARD_0_TX 56
#define primary_WATCHDOG_INDEX_FLASH_CELLBOARD_0_RX 57
#define primary_WATCHDOG_INDEX_FLASH_CELLBOARD_1_TX 58
#define primary_WATCHDOG_INDEX_FLASH_CELLBOARD_1_RX 59
#define primary_WATCHDOG_INDEX_FLASH_CELLBOARD_2_TX 60
#define primary_WATCHDOG_INDEX_FLASH_CELLBOARD_2_RX 61
#define primary_WATCHDOG_INDEX_FLASH_CELLBOARD_3_TX 62
#define primary_WATCHDOG_INDEX_FLASH_CELLBOARD_3_RX 63
#define primary_WATCHDOG_INDEX_FLASH_CELLBOARD_4_TX 64
#define primary_WATCHDOG_INDEX_FLASH_CELLBOARD_4_RX 65
#define primary_WATCHDOG_INDEX_FLASH_CELLBOARD_5_TX 66
#define primary_WATCHDOG_INDEX_FLASH_CELLBOARD_5_RX 67
#define primary_WATCHDOG_INDEX_FLASH_BMS_HV_TX 68
#define primary_WATCHDOG_INDEX_FLASH_BMS_HV_RX 69
#define primary_WATCHDOG_INDEX_FLASH_BMS_LV_TX 70
#define primary_WATCHDOG_INDEX_FLASH_BMS_LV_RX 71
#define primary_WATCHDOG_INDEX_BRUSA_NLG5_CTL 72
#define primary_WATCHDOG_INDEX_BRUSA_ST 73
#define primary_WATCHDOG_INDEX_BRUSA_ACT_I 74
#define primary_WATCHDOG_INDEX_BRUSA_ACT_II 75
#define primary_WATCHDOG_INDEX_BRUSA_TEMP 76
#define primary_WATCHDOG_INDEX_BRUSA_ERR 77
#define primary_WATCHDOG_INDEX_CONTROL_OUTPUT 78
#define primary_WATCHDOG_INDEX_LC_RESET 79

#ifndef CANLIB_INTERVAL_THRESHOLD
#define CANLIB_INTERVAL_THRESHOLD 500
#endif // CANLIB_INTERVAL_THRESHOLD

#define primary_INTERVAL_BMS_HV_JMP_TO_BLT -1
#define primary_INTERVAL_WITH_THRESHOLD_BMS_HV_JMP_TO_BLT (-1 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_BMS_LV_JMP_TO_BLT -1
#define primary_INTERVAL_WITH_THRESHOLD_BMS_LV_JMP_TO_BLT (-1 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_STEER_VERSION 1000
#define primary_INTERVAL_WITH_THRESHOLD_STEER_VERSION (1000 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_DAS_VERSION 1000
#define primary_INTERVAL_WITH_THRESHOLD_DAS_VERSION (1000 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_HV_VERSION 1000
#define primary_INTERVAL_WITH_THRESHOLD_HV_VERSION (1000 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_LV_VERSION 1000
#define primary_INTERVAL_WITH_THRESHOLD_LV_VERSION (1000 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_TLM_VERSION 1000
#define primary_INTERVAL_WITH_THRESHOLD_TLM_VERSION (1000 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_TIMESTAMP 1000
#define primary_INTERVAL_WITH_THRESHOLD_TIMESTAMP (1000 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_AMBIENT_TEMPERATURE 1000
#define primary_INTERVAL_WITH_THRESHOLD_AMBIENT_TEMPERATURE (1000 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_DATA_LOGGER 1000
#define primary_INTERVAL_WITH_THRESHOLD_DATA_LOGGER (1000 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_SET_TLM_STATUS -1
#define primary_INTERVAL_WITH_THRESHOLD_SET_TLM_STATUS (-1 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_TLM_STATUS 1000
#define primary_INTERVAL_WITH_THRESHOLD_TLM_STATUS (1000 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_STEER_SYSTEM_STATUS 1000
#define primary_INTERVAL_WITH_THRESHOLD_STEER_SYSTEM_STATUS (1000 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_HV_VOLTAGE 10
#define primary_INTERVAL_WITH_THRESHOLD_HV_VOLTAGE (10 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_HV_CURRENT 10
#define primary_INTERVAL_WITH_THRESHOLD_HV_CURRENT (10 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_HV_TEMP 100
#define primary_INTERVAL_WITH_THRESHOLD_HV_TEMP (100 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_HV_ERRORS 10
#define primary_INTERVAL_WITH_THRESHOLD_HV_ERRORS (10 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_HV_CAN_FORWARD -1
#define primary_INTERVAL_WITH_THRESHOLD_HV_CAN_FORWARD (-1 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_HV_FANS_OVERRIDE -1
#define primary_INTERVAL_WITH_THRESHOLD_HV_FANS_OVERRIDE (-1 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_HV_CAN_FORWARD_STATUS -1
#define primary_INTERVAL_WITH_THRESHOLD_HV_CAN_FORWARD_STATUS (-1 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_HV_FANS_OVERRIDE_STATUS -1
#define primary_INTERVAL_WITH_THRESHOLD_HV_FANS_OVERRIDE_STATUS (-1 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_HV_FEEDBACKS_STATUS -1
#define primary_INTERVAL_WITH_THRESHOLD_HV_FEEDBACKS_STATUS (-1 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_HV_IMD_STATUS -1
#define primary_INTERVAL_WITH_THRESHOLD_HV_IMD_STATUS (-1 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_TS_STATUS_DAS 10
#define primary_INTERVAL_WITH_THRESHOLD_TS_STATUS_DAS (10 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_TS_STATUS_STEER 10
#define primary_INTERVAL_WITH_THRESHOLD_TS_STATUS_STEER (10 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_TS_STATUS_HANDCART 10
#define primary_INTERVAL_WITH_THRESHOLD_TS_STATUS_HANDCART (10 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_SET_TS_STATUS_DAS 100
#define primary_INTERVAL_WITH_THRESHOLD_SET_TS_STATUS_DAS (100 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_SET_TS_STATUS_HANDCART 100
#define primary_INTERVAL_WITH_THRESHOLD_SET_TS_STATUS_HANDCART (100 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_STEER_STATUS 100
#define primary_INTERVAL_WITH_THRESHOLD_STEER_STATUS (100 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_SET_CAR_STATUS -1
#define primary_INTERVAL_WITH_THRESHOLD_SET_CAR_STATUS (-1 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_SET_PEDALS_RANGE -1
#define primary_INTERVAL_WITH_THRESHOLD_SET_PEDALS_RANGE (-1 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_SET_STEERING_ANGLE_RANGE -1
#define primary_INTERVAL_WITH_THRESHOLD_SET_STEERING_ANGLE_RANGE (-1 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_CAR_STATUS 100
#define primary_INTERVAL_WITH_THRESHOLD_CAR_STATUS (100 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_DAS_ERRORS 10
#define primary_INTERVAL_WITH_THRESHOLD_DAS_ERRORS (10 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_LV_CURRENT 500
#define primary_INTERVAL_WITH_THRESHOLD_LV_CURRENT (500 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_LV_VOLTAGE 100
#define primary_INTERVAL_WITH_THRESHOLD_LV_VOLTAGE (100 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_LV_TOTAL_VOLTAGE 100
#define primary_INTERVAL_WITH_THRESHOLD_LV_TOTAL_VOLTAGE (100 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_LV_TEMPERATURE 100
#define primary_INTERVAL_WITH_THRESHOLD_LV_TEMPERATURE (100 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_COOLING_STATUS 1000
#define primary_INTERVAL_WITH_THRESHOLD_COOLING_STATUS (1000 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_SET_RADIATOR_SPEED -1
#define primary_INTERVAL_WITH_THRESHOLD_SET_RADIATOR_SPEED (-1 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_SET_PUMPS_SPEED -1
#define primary_INTERVAL_WITH_THRESHOLD_SET_PUMPS_SPEED (-1 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_SET_INVERTER_CONNECTION_STATUS 100
#define primary_INTERVAL_WITH_THRESHOLD_SET_INVERTER_CONNECTION_STATUS (100 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_INVERTER_CONNECTION_STATUS 100
#define primary_INTERVAL_WITH_THRESHOLD_INVERTER_CONNECTION_STATUS (100 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_LV_ERRORS 10
#define primary_INTERVAL_WITH_THRESHOLD_LV_ERRORS (10 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_SHUTDOWN_STATUS 500
#define primary_INTERVAL_WITH_THRESHOLD_SHUTDOWN_STATUS (500 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_MARKER -1
#define primary_INTERVAL_WITH_THRESHOLD_MARKER (-1 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_HV_CELLS_VOLTAGE 100
#define primary_INTERVAL_WITH_THRESHOLD_HV_CELLS_VOLTAGE (100 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_HV_CELLS_TEMP 100
#define primary_INTERVAL_WITH_THRESHOLD_HV_CELLS_TEMP (100 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_HV_CELL_BALANCING_STATUS 500
#define primary_INTERVAL_WITH_THRESHOLD_HV_CELL_BALANCING_STATUS (500 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_SET_CELL_BALANCING_STATUS -1
#define primary_INTERVAL_WITH_THRESHOLD_SET_CELL_BALANCING_STATUS (-1 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_HANDCART_STATUS 500
#define primary_INTERVAL_WITH_THRESHOLD_HANDCART_STATUS (500 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_SPEED 10
#define primary_INTERVAL_WITH_THRESHOLD_SPEED (10 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_INV_L_REQUEST 10
#define primary_INTERVAL_WITH_THRESHOLD_INV_L_REQUEST (10 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_INV_R_REQUEST 10
#define primary_INTERVAL_WITH_THRESHOLD_INV_R_REQUEST (10 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_INV_L_RESPONSE 100
#define primary_INTERVAL_WITH_THRESHOLD_INV_L_RESPONSE (100 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_INV_R_RESPONSE 100
#define primary_INTERVAL_WITH_THRESHOLD_INV_R_RESPONSE (100 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_FLASH_CELLBOARD_0_TX -1
#define primary_INTERVAL_WITH_THRESHOLD_FLASH_CELLBOARD_0_TX (-1 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_FLASH_CELLBOARD_0_RX -1
#define primary_INTERVAL_WITH_THRESHOLD_FLASH_CELLBOARD_0_RX (-1 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_FLASH_CELLBOARD_1_TX -1
#define primary_INTERVAL_WITH_THRESHOLD_FLASH_CELLBOARD_1_TX (-1 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_FLASH_CELLBOARD_1_RX -1
#define primary_INTERVAL_WITH_THRESHOLD_FLASH_CELLBOARD_1_RX (-1 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_FLASH_CELLBOARD_2_TX -1
#define primary_INTERVAL_WITH_THRESHOLD_FLASH_CELLBOARD_2_TX (-1 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_FLASH_CELLBOARD_2_RX -1
#define primary_INTERVAL_WITH_THRESHOLD_FLASH_CELLBOARD_2_RX (-1 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_FLASH_CELLBOARD_3_TX -1
#define primary_INTERVAL_WITH_THRESHOLD_FLASH_CELLBOARD_3_TX (-1 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_FLASH_CELLBOARD_3_RX -1
#define primary_INTERVAL_WITH_THRESHOLD_FLASH_CELLBOARD_3_RX (-1 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_FLASH_CELLBOARD_4_TX -1
#define primary_INTERVAL_WITH_THRESHOLD_FLASH_CELLBOARD_4_TX (-1 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_FLASH_CELLBOARD_4_RX -1
#define primary_INTERVAL_WITH_THRESHOLD_FLASH_CELLBOARD_4_RX (-1 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_FLASH_CELLBOARD_5_TX -1
#define primary_INTERVAL_WITH_THRESHOLD_FLASH_CELLBOARD_5_TX (-1 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_FLASH_CELLBOARD_5_RX -1
#define primary_INTERVAL_WITH_THRESHOLD_FLASH_CELLBOARD_5_RX (-1 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_FLASH_BMS_HV_TX -1
#define primary_INTERVAL_WITH_THRESHOLD_FLASH_BMS_HV_TX (-1 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_FLASH_BMS_HV_RX -1
#define primary_INTERVAL_WITH_THRESHOLD_FLASH_BMS_HV_RX (-1 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_FLASH_BMS_LV_TX -1
#define primary_INTERVAL_WITH_THRESHOLD_FLASH_BMS_LV_TX (-1 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_FLASH_BMS_LV_RX -1
#define primary_INTERVAL_WITH_THRESHOLD_FLASH_BMS_LV_RX (-1 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_BRUSA_NLG5_CTL -1
#define primary_INTERVAL_WITH_THRESHOLD_BRUSA_NLG5_CTL (-1 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_BRUSA_ST -1
#define primary_INTERVAL_WITH_THRESHOLD_BRUSA_ST (-1 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_BRUSA_ACT_I -1
#define primary_INTERVAL_WITH_THRESHOLD_BRUSA_ACT_I (-1 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_BRUSA_ACT_II -1
#define primary_INTERVAL_WITH_THRESHOLD_BRUSA_ACT_II (-1 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_BRUSA_TEMP -1
#define primary_INTERVAL_WITH_THRESHOLD_BRUSA_TEMP (-1 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_BRUSA_ERR -1
#define primary_INTERVAL_WITH_THRESHOLD_BRUSA_ERR (-1 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_CONTROL_OUTPUT 100
#define primary_INTERVAL_WITH_THRESHOLD_CONTROL_OUTPUT (100 + CANLIB_INTERVAL_THRESHOLD)
#define primary_INTERVAL_LC_RESET -1
#define primary_INTERVAL_WITH_THRESHOLD_LC_RESET (-1 + CANLIB_INTERVAL_THRESHOLD)


// Messages with this interval will be ignored by the watchdog as they are not
// expected to be sent regularly.
#define primary_INTERVAL_ONCE -1

typedef struct {
    uint8_t activated[10];
    uint8_t timeout[10];
    canlib_watchdog_timestamp last_reset[80];
} primary_watchdog;

static inline int primary_watchdog_interval_from_id(uint16_t message_id) {
    switch (message_id) {
        case 0: return primary_INTERVAL_BMS_HV_JMP_TO_BLT;
        case 32: return primary_INTERVAL_BMS_LV_JMP_TO_BLT;
        case 1025: return primary_INTERVAL_STEER_VERSION;
        case 1057: return primary_INTERVAL_DAS_VERSION;
        case 1089: return primary_INTERVAL_HV_VERSION;
        case 1121: return primary_INTERVAL_LV_VERSION;
        case 1153: return primary_INTERVAL_TLM_VERSION;
        case 257: return primary_INTERVAL_TIMESTAMP;
        case 289: return primary_INTERVAL_AMBIENT_TEMPERATURE;
        case 1072: return primary_INTERVAL_DATA_LOGGER;
        case 259: return primary_INTERVAL_SET_TLM_STATUS;
        case 260: return primary_INTERVAL_TLM_STATUS;
        case 1795: return primary_INTERVAL_STEER_SYSTEM_STATUS;
        case 773: return primary_INTERVAL_HV_VOLTAGE;
        case 805: return primary_INTERVAL_HV_CURRENT;
        case 837: return primary_INTERVAL_HV_TEMP;
        case 5: return primary_INTERVAL_HV_ERRORS;
        case 6: return primary_INTERVAL_HV_CAN_FORWARD;
        case 38: return primary_INTERVAL_HV_FANS_OVERRIDE;
        case 7: return primary_INTERVAL_HV_CAN_FORWARD_STATUS;
        case 775: return primary_INTERVAL_HV_FANS_OVERRIDE_STATUS;
        case 776: return primary_INTERVAL_HV_FEEDBACKS_STATUS;
        case 808: return primary_INTERVAL_HV_IMD_STATUS;
        case 37: return primary_INTERVAL_TS_STATUS_DAS;
        case 69: return primary_INTERVAL_TS_STATUS_STEER;
        case 101: return primary_INTERVAL_TS_STATUS_HANDCART;
        case 70: return primary_INTERVAL_SET_TS_STATUS_DAS;
        case 102: return primary_INTERVAL_SET_TS_STATUS_HANDCART;
        case 265: return primary_INTERVAL_STEER_STATUS;
        case 777: return primary_INTERVAL_SET_CAR_STATUS;
        case 1033: return primary_INTERVAL_SET_PEDALS_RANGE;
        case 1065: return primary_INTERVAL_SET_STEERING_ANGLE_RANGE;
        case 516: return primary_INTERVAL_CAR_STATUS;
        case 4: return primary_INTERVAL_DAS_ERRORS;
        case 840: return primary_INTERVAL_LV_CURRENT;
        case 872: return primary_INTERVAL_LV_VOLTAGE;
        case 904: return primary_INTERVAL_LV_TOTAL_VOLTAGE;
        case 936: return primary_INTERVAL_LV_TEMPERATURE;
        case 968: return primary_INTERVAL_COOLING_STATUS;
        case 778: return primary_INTERVAL_SET_RADIATOR_SPEED;
        case 810: return primary_INTERVAL_SET_PUMPS_SPEED;
        case 266: return primary_INTERVAL_SET_INVERTER_CONNECTION_STATUS;
        case 264: return primary_INTERVAL_INVERTER_CONNECTION_STATUS;
        case 8: return primary_INTERVAL_LV_ERRORS;
        case 296: return primary_INTERVAL_SHUTDOWN_STATUS;
        case 3: return primary_INTERVAL_MARKER;
        case 519: return primary_INTERVAL_HV_CELLS_VOLTAGE;
        case 551: return primary_INTERVAL_HV_CELLS_TEMP;
        case 583: return primary_INTERVAL_HV_CELL_BALANCING_STATUS;
        case 518: return primary_INTERVAL_SET_CELL_BALANCING_STATUS;
        case 774: return primary_INTERVAL_HANDCART_STATUS;
        case 548: return primary_INTERVAL_SPEED;
        case 513: return primary_INTERVAL_INV_L_REQUEST;
        case 514: return primary_INTERVAL_INV_R_REQUEST;
        case 385: return primary_INTERVAL_INV_L_RESPONSE;
        case 386: return primary_INTERVAL_INV_R_RESPONSE;
        case 16: return primary_INTERVAL_FLASH_CELLBOARD_0_TX;
        case 17: return primary_INTERVAL_FLASH_CELLBOARD_0_RX;
        case 18: return primary_INTERVAL_FLASH_CELLBOARD_1_TX;
        case 19: return primary_INTERVAL_FLASH_CELLBOARD_1_RX;
        case 20: return primary_INTERVAL_FLASH_CELLBOARD_2_TX;
        case 21: return primary_INTERVAL_FLASH_CELLBOARD_2_RX;
        case 22: return primary_INTERVAL_FLASH_CELLBOARD_3_TX;
        case 23: return primary_INTERVAL_FLASH_CELLBOARD_3_RX;
        case 24: return primary_INTERVAL_FLASH_CELLBOARD_4_TX;
        case 25: return primary_INTERVAL_FLASH_CELLBOARD_4_RX;
        case 26: return primary_INTERVAL_FLASH_CELLBOARD_5_TX;
        case 27: return primary_INTERVAL_FLASH_CELLBOARD_5_RX;
        case 2017: return primary_INTERVAL_FLASH_BMS_HV_TX;
        case 1639: return primary_INTERVAL_FLASH_BMS_HV_RX;
        case 2033: return primary_INTERVAL_FLASH_BMS_LV_TX;
        case 1655: return primary_INTERVAL_FLASH_BMS_LV_RX;
        case 618: return primary_INTERVAL_BRUSA_NLG5_CTL;
        case 610: return primary_INTERVAL_BRUSA_ST;
        case 611: return primary_INTERVAL_BRUSA_ACT_I;
        case 612: return primary_INTERVAL_BRUSA_ACT_II;
        case 613: return primary_INTERVAL_BRUSA_TEMP;
        case 614: return primary_INTERVAL_BRUSA_ERR;
        case 292: return primary_INTERVAL_CONTROL_OUTPUT;
        case 523: return primary_INTERVAL_LC_RESET;
    }
    return -1;
}

static inline int primary_watchdog_index_from_id(canlib_message_id id) {
    switch (id) {
        case 0: return primary_WATCHDOG_INDEX_BMS_HV_JMP_TO_BLT;
        case 32: return primary_WATCHDOG_INDEX_BMS_LV_JMP_TO_BLT;
        case 1025: return primary_WATCHDOG_INDEX_STEER_VERSION;
        case 1057: return primary_WATCHDOG_INDEX_DAS_VERSION;
        case 1089: return primary_WATCHDOG_INDEX_HV_VERSION;
        case 1121: return primary_WATCHDOG_INDEX_LV_VERSION;
        case 1153: return primary_WATCHDOG_INDEX_TLM_VERSION;
        case 257: return primary_WATCHDOG_INDEX_TIMESTAMP;
        case 289: return primary_WATCHDOG_INDEX_AMBIENT_TEMPERATURE;
        case 1072: return primary_WATCHDOG_INDEX_DATA_LOGGER;
        case 259: return primary_WATCHDOG_INDEX_SET_TLM_STATUS;
        case 260: return primary_WATCHDOG_INDEX_TLM_STATUS;
        case 1795: return primary_WATCHDOG_INDEX_STEER_SYSTEM_STATUS;
        case 773: return primary_WATCHDOG_INDEX_HV_VOLTAGE;
        case 805: return primary_WATCHDOG_INDEX_HV_CURRENT;
        case 837: return primary_WATCHDOG_INDEX_HV_TEMP;
        case 5: return primary_WATCHDOG_INDEX_HV_ERRORS;
        case 6: return primary_WATCHDOG_INDEX_HV_CAN_FORWARD;
        case 38: return primary_WATCHDOG_INDEX_HV_FANS_OVERRIDE;
        case 7: return primary_WATCHDOG_INDEX_HV_CAN_FORWARD_STATUS;
        case 775: return primary_WATCHDOG_INDEX_HV_FANS_OVERRIDE_STATUS;
        case 776: return primary_WATCHDOG_INDEX_HV_FEEDBACKS_STATUS;
        case 808: return primary_WATCHDOG_INDEX_HV_IMD_STATUS;
        case 37: return primary_WATCHDOG_INDEX_TS_STATUS_DAS;
        case 69: return primary_WATCHDOG_INDEX_TS_STATUS_STEER;
        case 101: return primary_WATCHDOG_INDEX_TS_STATUS_HANDCART;
        case 70: return primary_WATCHDOG_INDEX_SET_TS_STATUS_DAS;
        case 102: return primary_WATCHDOG_INDEX_SET_TS_STATUS_HANDCART;
        case 265: return primary_WATCHDOG_INDEX_STEER_STATUS;
        case 777: return primary_WATCHDOG_INDEX_SET_CAR_STATUS;
        case 1033: return primary_WATCHDOG_INDEX_SET_PEDALS_RANGE;
        case 1065: return primary_WATCHDOG_INDEX_SET_STEERING_ANGLE_RANGE;
        case 516: return primary_WATCHDOG_INDEX_CAR_STATUS;
        case 4: return primary_WATCHDOG_INDEX_DAS_ERRORS;
        case 840: return primary_WATCHDOG_INDEX_LV_CURRENT;
        case 872: return primary_WATCHDOG_INDEX_LV_VOLTAGE;
        case 904: return primary_WATCHDOG_INDEX_LV_TOTAL_VOLTAGE;
        case 936: return primary_WATCHDOG_INDEX_LV_TEMPERATURE;
        case 968: return primary_WATCHDOG_INDEX_COOLING_STATUS;
        case 778: return primary_WATCHDOG_INDEX_SET_RADIATOR_SPEED;
        case 810: return primary_WATCHDOG_INDEX_SET_PUMPS_SPEED;
        case 266: return primary_WATCHDOG_INDEX_SET_INVERTER_CONNECTION_STATUS;
        case 264: return primary_WATCHDOG_INDEX_INVERTER_CONNECTION_STATUS;
        case 8: return primary_WATCHDOG_INDEX_LV_ERRORS;
        case 296: return primary_WATCHDOG_INDEX_SHUTDOWN_STATUS;
        case 3: return primary_WATCHDOG_INDEX_MARKER;
        case 519: return primary_WATCHDOG_INDEX_HV_CELLS_VOLTAGE;
        case 551: return primary_WATCHDOG_INDEX_HV_CELLS_TEMP;
        case 583: return primary_WATCHDOG_INDEX_HV_CELL_BALANCING_STATUS;
        case 518: return primary_WATCHDOG_INDEX_SET_CELL_BALANCING_STATUS;
        case 774: return primary_WATCHDOG_INDEX_HANDCART_STATUS;
        case 548: return primary_WATCHDOG_INDEX_SPEED;
        case 513: return primary_WATCHDOG_INDEX_INV_L_REQUEST;
        case 514: return primary_WATCHDOG_INDEX_INV_R_REQUEST;
        case 385: return primary_WATCHDOG_INDEX_INV_L_RESPONSE;
        case 386: return primary_WATCHDOG_INDEX_INV_R_RESPONSE;
        case 16: return primary_WATCHDOG_INDEX_FLASH_CELLBOARD_0_TX;
        case 17: return primary_WATCHDOG_INDEX_FLASH_CELLBOARD_0_RX;
        case 18: return primary_WATCHDOG_INDEX_FLASH_CELLBOARD_1_TX;
        case 19: return primary_WATCHDOG_INDEX_FLASH_CELLBOARD_1_RX;
        case 20: return primary_WATCHDOG_INDEX_FLASH_CELLBOARD_2_TX;
        case 21: return primary_WATCHDOG_INDEX_FLASH_CELLBOARD_2_RX;
        case 22: return primary_WATCHDOG_INDEX_FLASH_CELLBOARD_3_TX;
        case 23: return primary_WATCHDOG_INDEX_FLASH_CELLBOARD_3_RX;
        case 24: return primary_WATCHDOG_INDEX_FLASH_CELLBOARD_4_TX;
        case 25: return primary_WATCHDOG_INDEX_FLASH_CELLBOARD_4_RX;
        case 26: return primary_WATCHDOG_INDEX_FLASH_CELLBOARD_5_TX;
        case 27: return primary_WATCHDOG_INDEX_FLASH_CELLBOARD_5_RX;
        case 2017: return primary_WATCHDOG_INDEX_FLASH_BMS_HV_TX;
        case 1639: return primary_WATCHDOG_INDEX_FLASH_BMS_HV_RX;
        case 2033: return primary_WATCHDOG_INDEX_FLASH_BMS_LV_TX;
        case 1655: return primary_WATCHDOG_INDEX_FLASH_BMS_LV_RX;
        case 618: return primary_WATCHDOG_INDEX_BRUSA_NLG5_CTL;
        case 610: return primary_WATCHDOG_INDEX_BRUSA_ST;
        case 611: return primary_WATCHDOG_INDEX_BRUSA_ACT_I;
        case 612: return primary_WATCHDOG_INDEX_BRUSA_ACT_II;
        case 613: return primary_WATCHDOG_INDEX_BRUSA_TEMP;
        case 614: return primary_WATCHDOG_INDEX_BRUSA_ERR;
        case 292: return primary_WATCHDOG_INDEX_CONTROL_OUTPUT;
        case 523: return primary_WATCHDOG_INDEX_LC_RESET;
    }
    return 80; // invalid
}

primary_watchdog* primary_watchdog_new();
void primary_watchdog_free(primary_watchdog *watchdog);
void primary_watchdog_reset(primary_watchdog *watchdog, canlib_message_id id, canlib_watchdog_timestamp timestamp);
void primary_watchdog_reset_all(primary_watchdog *watchdog, canlib_watchdog_timestamp timestamp);
void primary_watchdog_timeout(primary_watchdog *watchdog, canlib_watchdog_timestamp timestamp);
void primary_watchdog_timeout_100(primary_watchdog *watchdog, canlib_watchdog_timestamp timestamp);
void primary_watchdog_timeout_1000(primary_watchdog *watchdog, canlib_watchdog_timestamp timestamp);
void primary_watchdog_timeout_5000(primary_watchdog *watchdog, canlib_watchdog_timestamp timestamp);
void primary_watchdog_timeout_10(primary_watchdog *watchdog, canlib_watchdog_timestamp timestamp);
void primary_watchdog_timeout_50(primary_watchdog *watchdog, canlib_watchdog_timestamp timestamp);
void primary_watchdog_timeout_500(primary_watchdog *watchdog, canlib_watchdog_timestamp timestamp);

#ifdef primary_WATCHDOG_IMPLEMENTATION

primary_watchdog* primary_watchdog_new() {
    primary_watchdog *watchdog = (primary_watchdog*)malloc(sizeof(primary_watchdog));
    if (watchdog == NULL) {
        return NULL;
    }
    memset(watchdog->activated, 0, sizeof(watchdog->activated));
    memset(watchdog->timeout, 0, sizeof(watchdog->timeout));
    memset(watchdog->last_reset, 0, sizeof(watchdog->last_reset));
    return watchdog;
}


void primary_watchdog_free(primary_watchdog *watchdog) {
    free(watchdog);
}

void primary_watchdog_reset(primary_watchdog *watchdog, canlib_message_id id, canlib_watchdog_timestamp timestamp) {
    int index = primary_watchdog_index_from_id(id);
    if (index < 80 && CANLIB_BITTEST_ARRAY(watchdog->activated, index)) {
        CANLIB_BITCLEAR_ARRAY(watchdog->timeout, index);
        watchdog->last_reset[index] = timestamp;
    }
}

void primary_watchdog_reset_all(primary_watchdog *watchdog, canlib_watchdog_timestamp timestamp) {
    memset(watchdog->timeout, 0, sizeof(watchdog->timeout));
    memset(watchdog->last_reset, timestamp, sizeof(watchdog->last_reset));
}

void primary_watchdog_timeout(primary_watchdog *watchdog, canlib_watchdog_timestamp timestamp) {
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_STEER_VERSION)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_STEER_VERSION] > primary_INTERVAL_WITH_THRESHOLD_STEER_VERSION
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_STEER_VERSION);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_DAS_VERSION)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_DAS_VERSION] > primary_INTERVAL_WITH_THRESHOLD_DAS_VERSION
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_DAS_VERSION);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_HV_VERSION)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_HV_VERSION] > primary_INTERVAL_WITH_THRESHOLD_HV_VERSION
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_HV_VERSION);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_LV_VERSION)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_LV_VERSION] > primary_INTERVAL_WITH_THRESHOLD_LV_VERSION
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_LV_VERSION);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_TLM_VERSION)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_TLM_VERSION] > primary_INTERVAL_WITH_THRESHOLD_TLM_VERSION
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_TLM_VERSION);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_TIMESTAMP)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_TIMESTAMP] > primary_INTERVAL_WITH_THRESHOLD_TIMESTAMP
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_TIMESTAMP);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_AMBIENT_TEMPERATURE)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_AMBIENT_TEMPERATURE] > primary_INTERVAL_WITH_THRESHOLD_AMBIENT_TEMPERATURE
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_AMBIENT_TEMPERATURE);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_DATA_LOGGER)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_DATA_LOGGER] > primary_INTERVAL_WITH_THRESHOLD_DATA_LOGGER
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_DATA_LOGGER);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_TLM_STATUS)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_TLM_STATUS] > primary_INTERVAL_WITH_THRESHOLD_TLM_STATUS
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_TLM_STATUS);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_STEER_SYSTEM_STATUS)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_STEER_SYSTEM_STATUS] > primary_INTERVAL_WITH_THRESHOLD_STEER_SYSTEM_STATUS
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_STEER_SYSTEM_STATUS);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_HV_VOLTAGE)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_HV_VOLTAGE] > primary_INTERVAL_WITH_THRESHOLD_HV_VOLTAGE
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_HV_VOLTAGE);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_HV_CURRENT)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_HV_CURRENT] > primary_INTERVAL_WITH_THRESHOLD_HV_CURRENT
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_HV_CURRENT);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_HV_TEMP)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_HV_TEMP] > primary_INTERVAL_WITH_THRESHOLD_HV_TEMP
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_HV_TEMP);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_HV_ERRORS)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_HV_ERRORS] > primary_INTERVAL_WITH_THRESHOLD_HV_ERRORS
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_HV_ERRORS);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_TS_STATUS_DAS)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_TS_STATUS_DAS] > primary_INTERVAL_WITH_THRESHOLD_TS_STATUS_DAS
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_TS_STATUS_DAS);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_TS_STATUS_STEER)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_TS_STATUS_STEER] > primary_INTERVAL_WITH_THRESHOLD_TS_STATUS_STEER
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_TS_STATUS_STEER);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_TS_STATUS_HANDCART)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_TS_STATUS_HANDCART] > primary_INTERVAL_WITH_THRESHOLD_TS_STATUS_HANDCART
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_TS_STATUS_HANDCART);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_SET_TS_STATUS_DAS)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_SET_TS_STATUS_DAS] > primary_INTERVAL_WITH_THRESHOLD_SET_TS_STATUS_DAS
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_SET_TS_STATUS_DAS);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_SET_TS_STATUS_HANDCART)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_SET_TS_STATUS_HANDCART] > primary_INTERVAL_WITH_THRESHOLD_SET_TS_STATUS_HANDCART
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_SET_TS_STATUS_HANDCART);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_STEER_STATUS)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_STEER_STATUS] > primary_INTERVAL_WITH_THRESHOLD_STEER_STATUS
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_STEER_STATUS);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_CAR_STATUS)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_CAR_STATUS] > primary_INTERVAL_WITH_THRESHOLD_CAR_STATUS
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_CAR_STATUS);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_DAS_ERRORS)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_DAS_ERRORS] > primary_INTERVAL_WITH_THRESHOLD_DAS_ERRORS
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_DAS_ERRORS);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_LV_CURRENT)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_LV_CURRENT] > primary_INTERVAL_WITH_THRESHOLD_LV_CURRENT
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_LV_CURRENT);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_LV_VOLTAGE)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_LV_VOLTAGE] > primary_INTERVAL_WITH_THRESHOLD_LV_VOLTAGE
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_LV_VOLTAGE);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_LV_TOTAL_VOLTAGE)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_LV_TOTAL_VOLTAGE] > primary_INTERVAL_WITH_THRESHOLD_LV_TOTAL_VOLTAGE
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_LV_TOTAL_VOLTAGE);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_LV_TEMPERATURE)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_LV_TEMPERATURE] > primary_INTERVAL_WITH_THRESHOLD_LV_TEMPERATURE
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_LV_TEMPERATURE);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_COOLING_STATUS)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_COOLING_STATUS] > primary_INTERVAL_WITH_THRESHOLD_COOLING_STATUS
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_COOLING_STATUS);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_SET_INVERTER_CONNECTION_STATUS)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_SET_INVERTER_CONNECTION_STATUS] > primary_INTERVAL_WITH_THRESHOLD_SET_INVERTER_CONNECTION_STATUS
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_SET_INVERTER_CONNECTION_STATUS);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_INVERTER_CONNECTION_STATUS)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_INVERTER_CONNECTION_STATUS] > primary_INTERVAL_WITH_THRESHOLD_INVERTER_CONNECTION_STATUS
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_INVERTER_CONNECTION_STATUS);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_LV_ERRORS)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_LV_ERRORS] > primary_INTERVAL_WITH_THRESHOLD_LV_ERRORS
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_LV_ERRORS);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_SHUTDOWN_STATUS)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_SHUTDOWN_STATUS] > primary_INTERVAL_WITH_THRESHOLD_SHUTDOWN_STATUS
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_SHUTDOWN_STATUS);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_HV_CELLS_VOLTAGE)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_HV_CELLS_VOLTAGE] > primary_INTERVAL_WITH_THRESHOLD_HV_CELLS_VOLTAGE
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_HV_CELLS_VOLTAGE);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_HV_CELLS_TEMP)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_HV_CELLS_TEMP] > primary_INTERVAL_WITH_THRESHOLD_HV_CELLS_TEMP
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_HV_CELLS_TEMP);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_HV_CELL_BALANCING_STATUS)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_HV_CELL_BALANCING_STATUS] > primary_INTERVAL_WITH_THRESHOLD_HV_CELL_BALANCING_STATUS
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_HV_CELL_BALANCING_STATUS);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_HANDCART_STATUS)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_HANDCART_STATUS] > primary_INTERVAL_WITH_THRESHOLD_HANDCART_STATUS
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_HANDCART_STATUS);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_SPEED)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_SPEED] > primary_INTERVAL_WITH_THRESHOLD_SPEED
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_SPEED);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_INV_L_REQUEST)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_INV_L_REQUEST] > primary_INTERVAL_WITH_THRESHOLD_INV_L_REQUEST
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_INV_L_REQUEST);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_INV_R_REQUEST)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_INV_R_REQUEST] > primary_INTERVAL_WITH_THRESHOLD_INV_R_REQUEST
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_INV_R_REQUEST);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_INV_L_RESPONSE)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_INV_L_RESPONSE] > primary_INTERVAL_WITH_THRESHOLD_INV_L_RESPONSE
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_INV_L_RESPONSE);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_INV_R_RESPONSE)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_INV_R_RESPONSE] > primary_INTERVAL_WITH_THRESHOLD_INV_R_RESPONSE
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_INV_R_RESPONSE);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_CONTROL_OUTPUT)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_CONTROL_OUTPUT] > primary_INTERVAL_WITH_THRESHOLD_CONTROL_OUTPUT
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_CONTROL_OUTPUT);
    }
}

void primary_watchdog_timeout_100(primary_watchdog *watchdog, canlib_watchdog_timestamp timestamp) {
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_HV_TEMP)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_HV_TEMP] > primary_INTERVAL_WITH_THRESHOLD_HV_TEMP
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_HV_TEMP);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_SET_TS_STATUS_DAS)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_SET_TS_STATUS_DAS] > primary_INTERVAL_WITH_THRESHOLD_SET_TS_STATUS_DAS
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_SET_TS_STATUS_DAS);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_SET_TS_STATUS_HANDCART)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_SET_TS_STATUS_HANDCART] > primary_INTERVAL_WITH_THRESHOLD_SET_TS_STATUS_HANDCART
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_SET_TS_STATUS_HANDCART);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_STEER_STATUS)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_STEER_STATUS] > primary_INTERVAL_WITH_THRESHOLD_STEER_STATUS
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_STEER_STATUS);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_CAR_STATUS)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_CAR_STATUS] > primary_INTERVAL_WITH_THRESHOLD_CAR_STATUS
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_CAR_STATUS);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_LV_VOLTAGE)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_LV_VOLTAGE] > primary_INTERVAL_WITH_THRESHOLD_LV_VOLTAGE
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_LV_VOLTAGE);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_LV_TOTAL_VOLTAGE)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_LV_TOTAL_VOLTAGE] > primary_INTERVAL_WITH_THRESHOLD_LV_TOTAL_VOLTAGE
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_LV_TOTAL_VOLTAGE);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_LV_TEMPERATURE)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_LV_TEMPERATURE] > primary_INTERVAL_WITH_THRESHOLD_LV_TEMPERATURE
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_LV_TEMPERATURE);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_SET_INVERTER_CONNECTION_STATUS)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_SET_INVERTER_CONNECTION_STATUS] > primary_INTERVAL_WITH_THRESHOLD_SET_INVERTER_CONNECTION_STATUS
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_SET_INVERTER_CONNECTION_STATUS);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_INVERTER_CONNECTION_STATUS)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_INVERTER_CONNECTION_STATUS] > primary_INTERVAL_WITH_THRESHOLD_INVERTER_CONNECTION_STATUS
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_INVERTER_CONNECTION_STATUS);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_HV_CELLS_VOLTAGE)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_HV_CELLS_VOLTAGE] > primary_INTERVAL_WITH_THRESHOLD_HV_CELLS_VOLTAGE
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_HV_CELLS_VOLTAGE);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_HV_CELLS_TEMP)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_HV_CELLS_TEMP] > primary_INTERVAL_WITH_THRESHOLD_HV_CELLS_TEMP
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_HV_CELLS_TEMP);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_INV_L_RESPONSE)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_INV_L_RESPONSE] > primary_INTERVAL_WITH_THRESHOLD_INV_L_RESPONSE
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_INV_L_RESPONSE);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_INV_R_RESPONSE)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_INV_R_RESPONSE] > primary_INTERVAL_WITH_THRESHOLD_INV_R_RESPONSE
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_INV_R_RESPONSE);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_CONTROL_OUTPUT)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_CONTROL_OUTPUT] > primary_INTERVAL_WITH_THRESHOLD_CONTROL_OUTPUT
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_CONTROL_OUTPUT);
    }
}

void primary_watchdog_timeout_1000(primary_watchdog *watchdog, canlib_watchdog_timestamp timestamp) {
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_STEER_VERSION)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_STEER_VERSION] > primary_INTERVAL_WITH_THRESHOLD_STEER_VERSION
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_STEER_VERSION);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_DAS_VERSION)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_DAS_VERSION] > primary_INTERVAL_WITH_THRESHOLD_DAS_VERSION
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_DAS_VERSION);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_HV_VERSION)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_HV_VERSION] > primary_INTERVAL_WITH_THRESHOLD_HV_VERSION
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_HV_VERSION);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_LV_VERSION)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_LV_VERSION] > primary_INTERVAL_WITH_THRESHOLD_LV_VERSION
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_LV_VERSION);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_TLM_VERSION)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_TLM_VERSION] > primary_INTERVAL_WITH_THRESHOLD_TLM_VERSION
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_TLM_VERSION);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_TIMESTAMP)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_TIMESTAMP] > primary_INTERVAL_WITH_THRESHOLD_TIMESTAMP
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_TIMESTAMP);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_AMBIENT_TEMPERATURE)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_AMBIENT_TEMPERATURE] > primary_INTERVAL_WITH_THRESHOLD_AMBIENT_TEMPERATURE
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_AMBIENT_TEMPERATURE);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_DATA_LOGGER)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_DATA_LOGGER] > primary_INTERVAL_WITH_THRESHOLD_DATA_LOGGER
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_DATA_LOGGER);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_TLM_STATUS)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_TLM_STATUS] > primary_INTERVAL_WITH_THRESHOLD_TLM_STATUS
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_TLM_STATUS);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_STEER_SYSTEM_STATUS)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_STEER_SYSTEM_STATUS] > primary_INTERVAL_WITH_THRESHOLD_STEER_SYSTEM_STATUS
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_STEER_SYSTEM_STATUS);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_COOLING_STATUS)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_COOLING_STATUS] > primary_INTERVAL_WITH_THRESHOLD_COOLING_STATUS
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_COOLING_STATUS);
    }
}

void primary_watchdog_timeout_5000(primary_watchdog *watchdog, canlib_watchdog_timestamp timestamp) {
    // no messages in this interval
    CANLIB_UNUSED(watchdog);
    CANLIB_UNUSED(timestamp);
}

void primary_watchdog_timeout_10(primary_watchdog *watchdog, canlib_watchdog_timestamp timestamp) {
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_HV_VOLTAGE)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_HV_VOLTAGE] > primary_INTERVAL_WITH_THRESHOLD_HV_VOLTAGE
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_HV_VOLTAGE);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_HV_CURRENT)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_HV_CURRENT] > primary_INTERVAL_WITH_THRESHOLD_HV_CURRENT
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_HV_CURRENT);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_HV_ERRORS)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_HV_ERRORS] > primary_INTERVAL_WITH_THRESHOLD_HV_ERRORS
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_HV_ERRORS);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_TS_STATUS_DAS)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_TS_STATUS_DAS] > primary_INTERVAL_WITH_THRESHOLD_TS_STATUS_DAS
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_TS_STATUS_DAS);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_TS_STATUS_STEER)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_TS_STATUS_STEER] > primary_INTERVAL_WITH_THRESHOLD_TS_STATUS_STEER
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_TS_STATUS_STEER);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_TS_STATUS_HANDCART)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_TS_STATUS_HANDCART] > primary_INTERVAL_WITH_THRESHOLD_TS_STATUS_HANDCART
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_TS_STATUS_HANDCART);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_DAS_ERRORS)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_DAS_ERRORS] > primary_INTERVAL_WITH_THRESHOLD_DAS_ERRORS
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_DAS_ERRORS);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_LV_ERRORS)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_LV_ERRORS] > primary_INTERVAL_WITH_THRESHOLD_LV_ERRORS
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_LV_ERRORS);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_SPEED)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_SPEED] > primary_INTERVAL_WITH_THRESHOLD_SPEED
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_SPEED);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_INV_L_REQUEST)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_INV_L_REQUEST] > primary_INTERVAL_WITH_THRESHOLD_INV_L_REQUEST
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_INV_L_REQUEST);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_INV_R_REQUEST)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_INV_R_REQUEST] > primary_INTERVAL_WITH_THRESHOLD_INV_R_REQUEST
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_INV_R_REQUEST);
    }
}

void primary_watchdog_timeout_50(primary_watchdog *watchdog, canlib_watchdog_timestamp timestamp) {
    // no messages in this interval
    CANLIB_UNUSED(watchdog);
    CANLIB_UNUSED(timestamp);
}

void primary_watchdog_timeout_500(primary_watchdog *watchdog, canlib_watchdog_timestamp timestamp) {
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_LV_CURRENT)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_LV_CURRENT] > primary_INTERVAL_WITH_THRESHOLD_LV_CURRENT
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_LV_CURRENT);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_SHUTDOWN_STATUS)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_SHUTDOWN_STATUS] > primary_INTERVAL_WITH_THRESHOLD_SHUTDOWN_STATUS
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_SHUTDOWN_STATUS);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_HV_CELL_BALANCING_STATUS)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_HV_CELL_BALANCING_STATUS] > primary_INTERVAL_WITH_THRESHOLD_HV_CELL_BALANCING_STATUS
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_HV_CELL_BALANCING_STATUS);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_WATCHDOG_INDEX_HANDCART_STATUS)
        && timestamp - watchdog->last_reset[primary_WATCHDOG_INDEX_HANDCART_STATUS] > primary_INTERVAL_WITH_THRESHOLD_HANDCART_STATUS
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_WATCHDOG_INDEX_HANDCART_STATUS);
    }
}



#endif // primary_WATCHDOG_IMPLEMENTATION

#ifdef __cplusplus
}
#endif

#endif // primary_NETWORK_H