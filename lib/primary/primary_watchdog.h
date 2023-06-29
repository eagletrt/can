#ifndef primary_WATCHDOG_H
#define primary_WATCHDOG_H

#include <inttypes.h>

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
#define PRIMARY_INTERVAL_HV_VERSION 1000
#define PRIMARY_INTERVAL_LV_VERSION 1000
#define PRIMARY_INTERVAL_TLM_VERSION 1000
#define PRIMARY_INTERVAL_TIMESTAMP 1000
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
#define PRIMARY_INTERVAL_LV_CURRENTS 500
#define PRIMARY_INTERVAL_LV_CELLS_VOLTAGE 100
#define PRIMARY_INTERVAL_LV_TOTAL_VOLTAGE 100
#define PRIMARY_INTERVAL_LV_CELLS_TEMP 100
#define PRIMARY_INTERVAL_COOLING_STATUS 1000
#define PRIMARY_INTERVAL_SET_INVERTER_CONNECTION_STATUS 100
#define PRIMARY_INTERVAL_INVERTER_CONNECTION_STATUS 100
#define PRIMARY_INTERVAL_LV_ERRORS 10
#define PRIMARY_INTERVAL_LV_HEALTH_SIGNALS 300
#define PRIMARY_INTERVAL_LV_FEEDBACKS 10
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
#define PRIMARY_INDEX_HV_VERSION 35
#define PRIMARY_INDEX_LV_VERSION 36
#define PRIMARY_INDEX_TLM_VERSION 37
#define PRIMARY_INDEX_TIMESTAMP 38
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
#define PRIMARY_INDEX_HV_FEEDBACKS_STATUS 51
#define PRIMARY_INDEX_HV_IMD_STATUS 52
#define PRIMARY_INDEX_TS_STATUS 53
#define PRIMARY_INDEX_SET_TS_STATUS_DAS 54
#define PRIMARY_INDEX_SET_TS_STATUS_HANDCART 55
#define PRIMARY_INDEX_STEER_STATUS 56
#define PRIMARY_INDEX_SET_CAR_STATUS 57
#define PRIMARY_INDEX_SET_PEDAL_CALIBRATION 58
#define PRIMARY_INDEX_PEDAL_CALIBRATION_ACK 59
#define PRIMARY_INDEX_CAR_STATUS 60
#define PRIMARY_INDEX_DAS_ERRORS 61
#define PRIMARY_INDEX_LV_CURRENTS 62
#define PRIMARY_INDEX_LV_CELLS_VOLTAGE 63
#define PRIMARY_INDEX_LV_TOTAL_VOLTAGE 64
#define PRIMARY_INDEX_LV_CELLS_TEMP 65
#define PRIMARY_INDEX_COOLING_STATUS 66
#define PRIMARY_INDEX_SET_RADIATOR_SPEED 67
#define PRIMARY_INDEX_SET_PUMPS_SPEED 68
#define PRIMARY_INDEX_SET_INVERTER_CONNECTION_STATUS 69
#define PRIMARY_INDEX_INVERTER_CONNECTION_STATUS 70
#define PRIMARY_INDEX_LV_ERRORS 71
#define PRIMARY_INDEX_LV_HEALTH_SIGNALS 72
#define PRIMARY_INDEX_LV_FEEDBACKS 73
#define PRIMARY_INDEX_SHUTDOWN_STATUS 74
#define PRIMARY_INDEX_LV_CAN_FLASH_REQ 75
#define PRIMARY_INDEX_LV_CAN_FLASH_ACK 76
#define PRIMARY_INDEX_MARKER 77
#define PRIMARY_INDEX_HV_CELLS_VOLTAGE 78
#define PRIMARY_INDEX_HV_CELLS_TEMP 79
#define PRIMARY_INDEX_HV_CELL_BALANCING_STATUS 80
#define PRIMARY_INDEX_SET_CELL_BALANCING_STATUS 81
#define PRIMARY_INDEX_SPEED 82
#define PRIMARY_INDEX_INV_L_REQUEST 83
#define PRIMARY_INDEX_INV_R_REQUEST 84
#define PRIMARY_INDEX_INV_L_RESPONSE 85
#define PRIMARY_INDEX_INV_R_RESPONSE 86
#define PRIMARY_INDEX_CONTROL_OUTPUT 87
#define PRIMARY_INDEX_LC_RESET 88
#define PRIMARY_INDEX_HANDCART_STATUS 89
#define PRIMARY_INDEX_HANDCART_SETTINGS 90
#define PRIMARY_INDEX_HANDCART_SETTINGS_SET 91
#define PRIMARY_INDEX_SET_PTT_STATUS 92
#define PRIMARY_INDEX_PTT_STATUS 93



typedef struct {
    uint8_t activated[12];
    uint8_t timeout[12];
    canlib_watchdog_timestamp last_reset[94];
} primary_watchdog;


primary_watchdog* primary_watchdog_new();
void primary_watchdog_free(primary_watchdog *watchdog);
void primary_watchdog_reset(primary_watchdog *watchdog, canlib_message_id id, canlib_watchdog_timestamp timestamp);
void primary_watchdog_reset_all(primary_watchdog *watchdog, canlib_watchdog_timestamp timestamp);
void primary_watchdog_timeout(primary_watchdog *watchdog, canlib_watchdog_timestamp timestamp);

static int primary_watchdog_interval_from_id(uint16_t message_id) {
    switch (message_id) {
       case 700: return PRIMARY_INTERVAL_STEER_VERSION;
       case 701: return PRIMARY_INTERVAL_DAS_VERSION;
       case 702: return PRIMARY_INTERVAL_HV_VERSION;
       case 703: return PRIMARY_INTERVAL_LV_VERSION;
       case 704: return PRIMARY_INTERVAL_TLM_VERSION;
       case 257: return PRIMARY_INTERVAL_TIMESTAMP;
       case 289: return PRIMARY_INTERVAL_AMBIENT_TEMPERATURE;
       case 1072: return PRIMARY_INTERVAL_DATA_LOGGER;
       case 260: return PRIMARY_INTERVAL_TLM_STATUS;
       case 1799: return PRIMARY_INTERVAL_STEER_SYSTEM_STATUS;
       case 773: return PRIMARY_INTERVAL_HV_VOLTAGE;
       case 805: return PRIMARY_INTERVAL_HV_CURRENT;
       case 837: return PRIMARY_INTERVAL_HV_TEMP;
       case 37: return PRIMARY_INTERVAL_HV_ERRORS;
       case 84: return PRIMARY_INTERVAL_TS_STATUS;
       case 82: return PRIMARY_INTERVAL_SET_TS_STATUS_DAS;
       case 83: return PRIMARY_INTERVAL_SET_TS_STATUS_HANDCART;
       case 256: return PRIMARY_INTERVAL_STEER_STATUS;
       case 81: return PRIMARY_INTERVAL_CAR_STATUS;
       case 36: return PRIMARY_INTERVAL_DAS_ERRORS;
       case 835: return PRIMARY_INTERVAL_LV_CURRENTS;
       case 867: return PRIMARY_INTERVAL_LV_CELLS_VOLTAGE;
       case 899: return PRIMARY_INTERVAL_LV_TOTAL_VOLTAGE;
       case 931: return PRIMARY_INTERVAL_LV_CELLS_TEMP;
       case 963: return PRIMARY_INTERVAL_COOLING_STATUS;
       case 258: return PRIMARY_INTERVAL_SET_INVERTER_CONNECTION_STATUS;
       case 259: return PRIMARY_INTERVAL_INVERTER_CONNECTION_STATUS;
       case 515: return PRIMARY_INTERVAL_LV_ERRORS;
       case 291: return PRIMARY_INTERVAL_LV_HEALTH_SIGNALS;
       case 323: return PRIMARY_INTERVAL_LV_FEEDBACKS;
       case 355: return PRIMARY_INTERVAL_SHUTDOWN_STATUS;
       case 1863: return PRIMARY_INTERVAL_LV_CAN_FLASH_ACK;
       case 518: return PRIMARY_INTERVAL_HV_CELLS_VOLTAGE;
       case 550: return PRIMARY_INTERVAL_HV_CELLS_TEMP;
       case 582: return PRIMARY_INTERVAL_HV_CELL_BALANCING_STATUS;
       case 516: return PRIMARY_INTERVAL_SPEED;
       case 513: return PRIMARY_INTERVAL_INV_L_REQUEST;
       case 514: return PRIMARY_INTERVAL_INV_R_REQUEST;
       case 385: return PRIMARY_INTERVAL_INV_L_RESPONSE;
       case 386: return PRIMARY_INTERVAL_INV_R_RESPONSE;
       case 292: return PRIMARY_INTERVAL_CONTROL_OUTPUT;
       case 776: return PRIMARY_INTERVAL_HANDCART_STATUS;
       case 808: return PRIMARY_INTERVAL_HANDCART_SETTINGS;
       case 840: return PRIMARY_INTERVAL_HANDCART_SETTINGS_SET;

    }
    return -1;
}

static int primary_watchdog_index_from_id(uint16_t message_id) {
    switch (message_id) {
       case 1818: return PRIMARY_INDEX_NLG5_DIAG_TX;
       case 1816: return PRIMARY_INDEX_NLG5_DIAG_RX;
       case 1556: return PRIMARY_INDEX_NLG5_ERR;
       case 1555: return PRIMARY_INDEX_NLG5_TEMP;
       case 1554: return PRIMARY_INDEX_NLG5_ACT_II;
       case 1553: return PRIMARY_INDEX_NLG5_ACT_I;
       case 1552: return PRIMARY_INDEX_NLG5_ST;
       case 1560: return PRIMARY_INDEX_NLG5_CTL;
       case 0: return PRIMARY_INDEX_BMS_HV_JMP_TO_BLT;
       case 1: return PRIMARY_INDEX_FLASH_BMS_HV_TX;
       case 2: return PRIMARY_INDEX_FLASH_BMS_HV_RX;
       case 3: return PRIMARY_INDEX_HV_CAN_FORWARD;
       case 4: return PRIMARY_INDEX_FLASH_CELLBOARD_0_TX;
       case 5: return PRIMARY_INDEX_FLASH_CELLBOARD_0_RX;
       case 6: return PRIMARY_INDEX_FLASH_CELLBOARD_1_TX;
       case 7: return PRIMARY_INDEX_FLASH_CELLBOARD_1_RX;
       case 8: return PRIMARY_INDEX_FLASH_CELLBOARD_2_TX;
       case 9: return PRIMARY_INDEX_FLASH_CELLBOARD_2_RX;
       case 10: return PRIMARY_INDEX_FLASH_CELLBOARD_3_TX;
       case 11: return PRIMARY_INDEX_FLASH_CELLBOARD_3_RX;
       case 12: return PRIMARY_INDEX_FLASH_CELLBOARD_4_TX;
       case 13: return PRIMARY_INDEX_FLASH_CELLBOARD_4_RX;
       case 14: return PRIMARY_INDEX_FLASH_CELLBOARD_5_TX;
       case 15: return PRIMARY_INDEX_FLASH_CELLBOARD_5_RX;
       case 16: return PRIMARY_INDEX_BMS_LV_JMP_TO_BLT;
       case 17: return PRIMARY_INDEX_FLASH_BMS_LV_TX;
       case 18: return PRIMARY_INDEX_FLASH_BMS_LV_RX;
       case 19: return PRIMARY_INDEX_ECU_JMP_TO_BLT;
       case 20: return PRIMARY_INDEX_FLASH_ECU_TX;
       case 21: return PRIMARY_INDEX_FLASH_ECU_RX;
       case 22: return PRIMARY_INDEX_STEERING_JMP_TO_BLT;
       case 23: return PRIMARY_INDEX_FLASH_STEERING_TX;
       case 24: return PRIMARY_INDEX_FLASH_STEERING_RX;
       case 700: return PRIMARY_INDEX_STEER_VERSION;
       case 701: return PRIMARY_INDEX_DAS_VERSION;
       case 702: return PRIMARY_INDEX_HV_VERSION;
       case 703: return PRIMARY_INDEX_LV_VERSION;
       case 704: return PRIMARY_INDEX_TLM_VERSION;
       case 257: return PRIMARY_INDEX_TIMESTAMP;
       case 289: return PRIMARY_INDEX_AMBIENT_TEMPERATURE;
       case 1072: return PRIMARY_INDEX_DATA_LOGGER;
       case 263: return PRIMARY_INDEX_SET_TLM_STATUS;
       case 260: return PRIMARY_INDEX_TLM_STATUS;
       case 1799: return PRIMARY_INDEX_STEER_SYSTEM_STATUS;
       case 773: return PRIMARY_INDEX_HV_VOLTAGE;
       case 805: return PRIMARY_INDEX_HV_CURRENT;
       case 837: return PRIMARY_INDEX_HV_TEMP;
       case 37: return PRIMARY_INDEX_HV_ERRORS;
       case 40: return PRIMARY_INDEX_HV_FANS_OVERRIDE;
       case 38: return PRIMARY_INDEX_HV_CAN_FORWARD_STATUS;
       case 774: return PRIMARY_INDEX_HV_FANS_OVERRIDE_STATUS;
       case 771: return PRIMARY_INDEX_HV_FEEDBACKS_STATUS;
       case 803: return PRIMARY_INDEX_HV_IMD_STATUS;
       case 84: return PRIMARY_INDEX_TS_STATUS;
       case 82: return PRIMARY_INDEX_SET_TS_STATUS_DAS;
       case 83: return PRIMARY_INDEX_SET_TS_STATUS_HANDCART;
       case 256: return PRIMARY_INDEX_STEER_STATUS;
       case 80: return PRIMARY_INDEX_SET_CAR_STATUS;
       case 1024: return PRIMARY_INDEX_SET_PEDAL_CALIBRATION;
       case 1028: return PRIMARY_INDEX_PEDAL_CALIBRATION_ACK;
       case 81: return PRIMARY_INDEX_CAR_STATUS;
       case 36: return PRIMARY_INDEX_DAS_ERRORS;
       case 835: return PRIMARY_INDEX_LV_CURRENTS;
       case 867: return PRIMARY_INDEX_LV_CELLS_VOLTAGE;
       case 899: return PRIMARY_INDEX_LV_TOTAL_VOLTAGE;
       case 931: return PRIMARY_INDEX_LV_CELLS_TEMP;
       case 963: return PRIMARY_INDEX_COOLING_STATUS;
       case 770: return PRIMARY_INDEX_SET_RADIATOR_SPEED;
       case 802: return PRIMARY_INDEX_SET_PUMPS_SPEED;
       case 258: return PRIMARY_INDEX_SET_INVERTER_CONNECTION_STATUS;
       case 259: return PRIMARY_INDEX_INVERTER_CONNECTION_STATUS;
       case 515: return PRIMARY_INDEX_LV_ERRORS;
       case 291: return PRIMARY_INDEX_LV_HEALTH_SIGNALS;
       case 323: return PRIMARY_INDEX_LV_FEEDBACKS;
       case 355: return PRIMARY_INDEX_SHUTDOWN_STATUS;
       case 1831: return PRIMARY_INDEX_LV_CAN_FLASH_REQ;
       case 1863: return PRIMARY_INDEX_LV_CAN_FLASH_ACK;
       case 39: return PRIMARY_INDEX_MARKER;
       case 518: return PRIMARY_INDEX_HV_CELLS_VOLTAGE;
       case 550: return PRIMARY_INDEX_HV_CELLS_TEMP;
       case 582: return PRIMARY_INDEX_HV_CELL_BALANCING_STATUS;
       case 520: return PRIMARY_INDEX_SET_CELL_BALANCING_STATUS;
       case 516: return PRIMARY_INDEX_SPEED;
       case 513: return PRIMARY_INDEX_INV_L_REQUEST;
       case 514: return PRIMARY_INDEX_INV_R_REQUEST;
       case 385: return PRIMARY_INDEX_INV_L_RESPONSE;
       case 386: return PRIMARY_INDEX_INV_R_RESPONSE;
       case 292: return PRIMARY_INDEX_CONTROL_OUTPUT;
       case 521: return PRIMARY_INDEX_LC_RESET;
       case 776: return PRIMARY_INDEX_HANDCART_STATUS;
       case 808: return PRIMARY_INDEX_HANDCART_SETTINGS;
       case 840: return PRIMARY_INDEX_HANDCART_SETTINGS_SET;
       case 547: return PRIMARY_INDEX_SET_PTT_STATUS;
       case 579: return PRIMARY_INDEX_PTT_STATUS;

    }
    return -1;
}
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
    if (index < 94 && CANLIB_BITTEST_ARRAY(watchdog->activated, index)) {
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
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_STEER_VERSION)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_STEER_VERSION] > PRIMARY_INTERVAL_STEER_VERSION * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_STEER_VERSION);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_DAS_VERSION)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_DAS_VERSION] > PRIMARY_INTERVAL_DAS_VERSION * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_DAS_VERSION);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_HV_VERSION)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_HV_VERSION] > PRIMARY_INTERVAL_HV_VERSION * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_HV_VERSION);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_LV_VERSION)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_LV_VERSION] > PRIMARY_INTERVAL_LV_VERSION * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_LV_VERSION);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_TLM_VERSION)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_TLM_VERSION] > PRIMARY_INTERVAL_TLM_VERSION * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_TLM_VERSION);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_TIMESTAMP)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_TIMESTAMP] > PRIMARY_INTERVAL_TIMESTAMP * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_TIMESTAMP);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_AMBIENT_TEMPERATURE)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_AMBIENT_TEMPERATURE] > PRIMARY_INTERVAL_AMBIENT_TEMPERATURE * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_AMBIENT_TEMPERATURE);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_DATA_LOGGER)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_DATA_LOGGER] > PRIMARY_INTERVAL_DATA_LOGGER * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_DATA_LOGGER);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_TLM_STATUS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_TLM_STATUS] > PRIMARY_INTERVAL_TLM_STATUS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_TLM_STATUS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_STEER_SYSTEM_STATUS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_STEER_SYSTEM_STATUS] > PRIMARY_INTERVAL_STEER_SYSTEM_STATUS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_STEER_SYSTEM_STATUS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_HV_VOLTAGE)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_HV_VOLTAGE] > PRIMARY_INTERVAL_HV_VOLTAGE * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_HV_VOLTAGE);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_HV_CURRENT)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_HV_CURRENT] > PRIMARY_INTERVAL_HV_CURRENT * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_HV_CURRENT);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_HV_TEMP)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_HV_TEMP] > PRIMARY_INTERVAL_HV_TEMP * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_HV_TEMP);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_HV_ERRORS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_HV_ERRORS] > PRIMARY_INTERVAL_HV_ERRORS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_HV_ERRORS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_TS_STATUS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_TS_STATUS] > PRIMARY_INTERVAL_TS_STATUS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_TS_STATUS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_SET_TS_STATUS_DAS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_SET_TS_STATUS_DAS] > PRIMARY_INTERVAL_SET_TS_STATUS_DAS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_SET_TS_STATUS_DAS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_SET_TS_STATUS_HANDCART)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_SET_TS_STATUS_HANDCART] > PRIMARY_INTERVAL_SET_TS_STATUS_HANDCART * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_SET_TS_STATUS_HANDCART);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_STEER_STATUS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_STEER_STATUS] > PRIMARY_INTERVAL_STEER_STATUS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_STEER_STATUS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_CAR_STATUS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_CAR_STATUS] > PRIMARY_INTERVAL_CAR_STATUS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_CAR_STATUS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_DAS_ERRORS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_DAS_ERRORS] > PRIMARY_INTERVAL_DAS_ERRORS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_DAS_ERRORS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_LV_CURRENTS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_LV_CURRENTS] > PRIMARY_INTERVAL_LV_CURRENTS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_LV_CURRENTS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_LV_CELLS_VOLTAGE)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_LV_CELLS_VOLTAGE] > PRIMARY_INTERVAL_LV_CELLS_VOLTAGE * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_LV_CELLS_VOLTAGE);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_LV_TOTAL_VOLTAGE)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_LV_TOTAL_VOLTAGE] > PRIMARY_INTERVAL_LV_TOTAL_VOLTAGE * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_LV_TOTAL_VOLTAGE);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_LV_CELLS_TEMP)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_LV_CELLS_TEMP] > PRIMARY_INTERVAL_LV_CELLS_TEMP * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_LV_CELLS_TEMP);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_COOLING_STATUS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_COOLING_STATUS] > PRIMARY_INTERVAL_COOLING_STATUS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_COOLING_STATUS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_SET_INVERTER_CONNECTION_STATUS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_SET_INVERTER_CONNECTION_STATUS] > PRIMARY_INTERVAL_SET_INVERTER_CONNECTION_STATUS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_SET_INVERTER_CONNECTION_STATUS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_INVERTER_CONNECTION_STATUS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_INVERTER_CONNECTION_STATUS] > PRIMARY_INTERVAL_INVERTER_CONNECTION_STATUS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_INVERTER_CONNECTION_STATUS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_LV_ERRORS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_LV_ERRORS] > PRIMARY_INTERVAL_LV_ERRORS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_LV_ERRORS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_LV_HEALTH_SIGNALS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_LV_HEALTH_SIGNALS] > PRIMARY_INTERVAL_LV_HEALTH_SIGNALS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_LV_HEALTH_SIGNALS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_LV_FEEDBACKS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_LV_FEEDBACKS] > PRIMARY_INTERVAL_LV_FEEDBACKS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_LV_FEEDBACKS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_SHUTDOWN_STATUS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_SHUTDOWN_STATUS] > PRIMARY_INTERVAL_SHUTDOWN_STATUS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_SHUTDOWN_STATUS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_LV_CAN_FLASH_ACK)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_LV_CAN_FLASH_ACK] > PRIMARY_INTERVAL_LV_CAN_FLASH_ACK * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_LV_CAN_FLASH_ACK);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_HV_CELLS_VOLTAGE)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_HV_CELLS_VOLTAGE] > PRIMARY_INTERVAL_HV_CELLS_VOLTAGE * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_HV_CELLS_VOLTAGE);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_HV_CELLS_TEMP)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_HV_CELLS_TEMP] > PRIMARY_INTERVAL_HV_CELLS_TEMP * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_HV_CELLS_TEMP);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_HV_CELL_BALANCING_STATUS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_HV_CELL_BALANCING_STATUS] > PRIMARY_INTERVAL_HV_CELL_BALANCING_STATUS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_HV_CELL_BALANCING_STATUS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_SPEED)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_SPEED] > PRIMARY_INTERVAL_SPEED * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_SPEED);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_INV_L_REQUEST)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_INV_L_REQUEST] > PRIMARY_INTERVAL_INV_L_REQUEST * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_INV_L_REQUEST);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_INV_R_REQUEST)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_INV_R_REQUEST] > PRIMARY_INTERVAL_INV_R_REQUEST * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_INV_R_REQUEST);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_INV_L_RESPONSE)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_INV_L_RESPONSE] > PRIMARY_INTERVAL_INV_L_RESPONSE * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_INV_L_RESPONSE);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_INV_R_RESPONSE)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_INV_R_RESPONSE] > PRIMARY_INTERVAL_INV_R_RESPONSE * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_INV_R_RESPONSE);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_CONTROL_OUTPUT)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_CONTROL_OUTPUT] > PRIMARY_INTERVAL_CONTROL_OUTPUT * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_CONTROL_OUTPUT);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_HANDCART_STATUS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_HANDCART_STATUS] > PRIMARY_INTERVAL_HANDCART_STATUS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_HANDCART_STATUS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_HANDCART_SETTINGS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_HANDCART_SETTINGS] > PRIMARY_INTERVAL_HANDCART_SETTINGS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_HANDCART_SETTINGS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_HANDCART_SETTINGS_SET)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_HANDCART_SETTINGS_SET] > PRIMARY_INTERVAL_HANDCART_SETTINGS_SET * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_HANDCART_SETTINGS_SET);
    }

}
#endif // primary_WATCHDOG_IMPLEMENTATION



#ifdef __cplusplus
}
#endif

#endif // primary_NETWORK_H
