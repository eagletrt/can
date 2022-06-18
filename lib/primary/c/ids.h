#ifndef primary_IDS_H
#define primary_IDS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#ifndef CANLIB_MESSAGE_ID_TYPE
#define CANLIB_MESSAGE_ID_TYPE
typedef uint16_t canlib_message_id;
#endif // CANLIB_MESSAGE_ID_TYPE

#define primary_IDS_VERSION 1.3


/* TOPIC FLASH */
#define primary_TOPIC_MASK_FLASH 0b00000011111
#define primary_TOPIC_FILTER_FLASH 0x0 // dec: 0 bin: 0b00000000000

#define primary_ID_BMS_HV_JMP_TO_BLT 0x0 // dec: 0 bin: 0b00000000000

/* TOPIC BROADCAST */
#define primary_TOPIC_MASK_BROADCAST 0b00000011111
#define primary_TOPIC_FILTER_BROADCAST 0x1 // dec: 1 bin: 0b00000000001

#define primary_ID_STEER_VERSION 0x401 // dec: 1025 bin: 0b10000000001
#define primary_ID_DAS_VERSION 0x421 // dec: 1057 bin: 0b10000100001
#define primary_ID_HV_VERSION 0x441 // dec: 1089 bin: 0b10001000001
#define primary_ID_LV_VERSION 0x461 // dec: 1121 bin: 0b10001100001
#define primary_ID_TLM_VERSION 0x481 // dec: 1153 bin: 0b10010000001
#define primary_ID_TIMESTAMP 0x101 // dec: 257 bin: 0b00100000001

/* TOPIC TLM */
#define primary_TOPIC_MASK_TLM 0b00000011111
#define primary_TOPIC_FILTER_TLM 0x2 // dec: 2 bin: 0b00000000010

#define primary_ID_SET_TLM_STATUS 0x102 // dec: 258 bin: 0b00100000010
#define primary_ID_STEER_SYSTEM_STATUS 0x702 // dec: 1794 bin: 0b11100000010
#define primary_ID_MARKER 0x2 // dec: 2 bin: 0b00000000010

/* TOPIC STEER */
#define primary_TOPIC_MASK_STEER 0b00000011111
#define primary_TOPIC_FILTER_STEER 0x3 // dec: 3 bin: 0b00000000011

#define primary_ID_TLM_STATUS 0x103 // dec: 259 bin: 0b00100000011
#define primary_ID_CAR_STATUS 0x203 // dec: 515 bin: 0b01000000011
#define primary_ID_DAS_ERRORS 0x3 // dec: 3 bin: 0b00000000011
#define primary_ID_SPEED 0x223 // dec: 547 bin: 0b01000100011

/* TOPIC DASnSTEERnCART */
#define primary_TOPIC_MASK_DASnSTEERnCART 0b00000011111
#define primary_TOPIC_FILTER_DASnSTEERnCART 0x4 // dec: 4 bin: 0b00000000100

#define primary_ID_HV_VOLTAGE 0x304 // dec: 772 bin: 0b01100000100
#define primary_ID_HV_CURRENT 0x324 // dec: 804 bin: 0b01100100100
#define primary_ID_HV_TEMP 0x344 // dec: 836 bin: 0b01101000100
#define primary_ID_HV_ERRORS 0x4 // dec: 4 bin: 0b00000000100
#define primary_ID_TS_STATUS 0x24 // dec: 36 bin: 0b00000100100

/* TOPIC BMS_HV */
#define primary_TOPIC_MASK_BMS_HV 0b00000011111
#define primary_TOPIC_FILTER_BMS_HV 0x5 // dec: 5 bin: 0b00000000101

#define primary_ID_HV_CAN_FORWARD 0x5 // dec: 5 bin: 0b00000000101
#define primary_ID_SET_TS_STATUS_DAS 0x25 // dec: 37 bin: 0b00000100101
#define primary_ID_SET_TS_STATUS_HANDCART 0x45 // dec: 69 bin: 0b00001000101
#define primary_ID_SET_CELL_BALANCING_STATUS 0x205 // dec: 517 bin: 0b01000000101
#define primary_ID_HANDCART_STATUS 0x305 // dec: 773 bin: 0b01100000101

/* TOPIC HANDCART */
#define primary_TOPIC_MASK_HANDCART 0b00000011111
#define primary_TOPIC_FILTER_HANDCART 0x6 // dec: 6 bin: 0b00000000110

#define primary_ID_HV_CAN_FORWARD_STATUS 0x6 // dec: 6 bin: 0b00000000110
#define primary_ID_HV_CELLS_VOLTAGE 0x206 // dec: 518 bin: 0b01000000110
#define primary_ID_HV_CELLS_TEMP 0x226 // dec: 550 bin: 0b01000100110
#define primary_ID_HV_CELL_BALANCING_STATUS 0x246 // dec: 582 bin: 0b01001000110

/* TOPIC DAS */
#define primary_TOPIC_MASK_DAS 0b00000011111
#define primary_TOPIC_FILTER_DAS 0x7 // dec: 7 bin: 0b00000000111

#define primary_ID_STEER_STATUS 0x107 // dec: 263 bin: 0b00100000111
#define primary_ID_SET_CAR_STATUS 0x307 // dec: 775 bin: 0b01100000111
#define primary_ID_SET_PEDALS_RANGE 0x407 // dec: 1031 bin: 0b10000000111
#define primary_ID_SET_STEERING_ANGLE_RANGE 0x427 // dec: 1063 bin: 0b10000100111

/* TOPIC DASnSTEER */
#define primary_TOPIC_MASK_DASnSTEER 0b00000011111
#define primary_TOPIC_FILTER_DASnSTEER 0x8 // dec: 8 bin: 0b00000001000

#define primary_ID_LV_CURRENT 0x308 // dec: 776 bin: 0b01100001000
#define primary_ID_LV_VOLTAGE 0x328 // dec: 808 bin: 0b01100101000
#define primary_ID_LV_TOTAL_VOLTAGE 0x348 // dec: 840 bin: 0b01101001000
#define primary_ID_LV_TEMPERATURE 0x368 // dec: 872 bin: 0b01101101000
#define primary_ID_COOLING_STATUS 0x388 // dec: 904 bin: 0b01110001000
#define primary_ID_INVERTER_CONNECTION_STATUS 0x108 // dec: 264 bin: 0b00100001000
#define primary_ID_SHUTDOWN_STATUS 0x128 // dec: 296 bin: 0b00100101000

/* TOPIC LV */
#define primary_TOPIC_MASK_LV 0b00000011111
#define primary_TOPIC_FILTER_LV 0x9 // dec: 9 bin: 0b00000001001

#define primary_ID_SET_RADIATOR_SPEED 0x309 // dec: 777 bin: 0b01100001001
#define primary_ID_SET_PUMPS_SPEED 0x329 // dec: 809 bin: 0b01100101001
#define primary_ID_SET_INVERTER_CONNECTION_STATUS 0x109 // dec: 265 bin: 0b00100001001

/* TOPIC FIXED_IDS */
#define primary_TOPIC_MASK_FIXED_IDS 0b00000011111

#define primary_ID_INV_L_REQUEST 0x201 // dec: 513 bin: 0b01000000001
#define primary_ID_INV_R_REQUEST 0x202 // dec: 514 bin: 0b01000000010
#define primary_ID_INV_L_RESPONSE 0x181 // dec: 385 bin: 0b00110000001
#define primary_ID_INV_R_RESPONSE 0x182 // dec: 386 bin: 0b00110000010
#define primary_ID_FLASH_CELLBOARD_0_TX 0x10 // dec: 16 bin: 0b00000010000
#define primary_ID_FLASH_CELLBOARD_0_RX 0x11 // dec: 17 bin: 0b00000010001
#define primary_ID_FLASH_CELLBOARD_1_TX 0x12 // dec: 18 bin: 0b00000010010
#define primary_ID_FLASH_CELLBOARD_1_RX 0x13 // dec: 19 bin: 0b00000010011
#define primary_ID_FLASH_CELLBOARD_2_TX 0x14 // dec: 20 bin: 0b00000010100
#define primary_ID_FLASH_CELLBOARD_2_RX 0x15 // dec: 21 bin: 0b00000010101
#define primary_ID_FLASH_CELLBOARD_3_TX 0x16 // dec: 22 bin: 0b00000010110
#define primary_ID_FLASH_CELLBOARD_3_RX 0x17 // dec: 23 bin: 0b00000010111
#define primary_ID_FLASH_CELLBOARD_4_TX 0x18 // dec: 24 bin: 0b00000011000
#define primary_ID_FLASH_CELLBOARD_4_RX 0x19 // dec: 25 bin: 0b00000011001
#define primary_ID_FLASH_CELLBOARD_5_TX 0x1A // dec: 26 bin: 0b00000011010
#define primary_ID_FLASH_CELLBOARD_5_RX 0x1B // dec: 27 bin: 0b00000011011


#define primary_MAX_MESSAGE_NAME_LENGTH 31

// ============== UTILS ============== //

static inline int primary_message_name_from_id(canlib_message_id id, char *buffer) {
    switch (id) {
        case primary_ID_BMS_HV_JMP_TO_BLT:
            return sprintf(buffer, "%s", "BMS_HV_JMP_TO_BLT");;
        case primary_ID_STEER_VERSION:
            return sprintf(buffer, "%s", "STEER_VERSION");;
        case primary_ID_DAS_VERSION:
            return sprintf(buffer, "%s", "DAS_VERSION");;
        case primary_ID_HV_VERSION:
            return sprintf(buffer, "%s", "HV_VERSION");;
        case primary_ID_LV_VERSION:
            return sprintf(buffer, "%s", "LV_VERSION");;
        case primary_ID_TLM_VERSION:
            return sprintf(buffer, "%s", "TLM_VERSION");;
        case primary_ID_TIMESTAMP:
            return sprintf(buffer, "%s", "TIMESTAMP");;
        case primary_ID_SET_TLM_STATUS:
            return sprintf(buffer, "%s", "SET_TLM_STATUS");;
        case primary_ID_TLM_STATUS:
            return sprintf(buffer, "%s", "TLM_STATUS");;
        case primary_ID_STEER_SYSTEM_STATUS:
            return sprintf(buffer, "%s", "STEER_SYSTEM_STATUS");;
        case primary_ID_HV_VOLTAGE:
            return sprintf(buffer, "%s", "HV_VOLTAGE");;
        case primary_ID_HV_CURRENT:
            return sprintf(buffer, "%s", "HV_CURRENT");;
        case primary_ID_HV_TEMP:
            return sprintf(buffer, "%s", "HV_TEMP");;
        case primary_ID_HV_ERRORS:
            return sprintf(buffer, "%s", "HV_ERRORS");;
        case primary_ID_HV_CAN_FORWARD:
            return sprintf(buffer, "%s", "HV_CAN_FORWARD");;
        case primary_ID_HV_CAN_FORWARD_STATUS:
            return sprintf(buffer, "%s", "HV_CAN_FORWARD_STATUS");;
        case primary_ID_TS_STATUS:
            return sprintf(buffer, "%s", "TS_STATUS");;
        case primary_ID_SET_TS_STATUS_DAS:
            return sprintf(buffer, "%s", "SET_TS_STATUS_DAS");;
        case primary_ID_SET_TS_STATUS_HANDCART:
            return sprintf(buffer, "%s", "SET_TS_STATUS_HANDCART");;
        case primary_ID_STEER_STATUS:
            return sprintf(buffer, "%s", "STEER_STATUS");;
        case primary_ID_SET_CAR_STATUS:
            return sprintf(buffer, "%s", "SET_CAR_STATUS");;
        case primary_ID_SET_PEDALS_RANGE:
            return sprintf(buffer, "%s", "SET_PEDALS_RANGE");;
        case primary_ID_SET_STEERING_ANGLE_RANGE:
            return sprintf(buffer, "%s", "SET_STEERING_ANGLE_RANGE");;
        case primary_ID_CAR_STATUS:
            return sprintf(buffer, "%s", "CAR_STATUS");;
        case primary_ID_DAS_ERRORS:
            return sprintf(buffer, "%s", "DAS_ERRORS");;
        case primary_ID_LV_CURRENT:
            return sprintf(buffer, "%s", "LV_CURRENT");;
        case primary_ID_LV_VOLTAGE:
            return sprintf(buffer, "%s", "LV_VOLTAGE");;
        case primary_ID_LV_TOTAL_VOLTAGE:
            return sprintf(buffer, "%s", "LV_TOTAL_VOLTAGE");;
        case primary_ID_LV_TEMPERATURE:
            return sprintf(buffer, "%s", "LV_TEMPERATURE");;
        case primary_ID_COOLING_STATUS:
            return sprintf(buffer, "%s", "COOLING_STATUS");;
        case primary_ID_SET_RADIATOR_SPEED:
            return sprintf(buffer, "%s", "SET_RADIATOR_SPEED");;
        case primary_ID_SET_PUMPS_SPEED:
            return sprintf(buffer, "%s", "SET_PUMPS_SPEED");;
        case primary_ID_SET_INVERTER_CONNECTION_STATUS:
            return sprintf(buffer, "%s", "SET_INVERTER_CONNECTION_STATUS");;
        case primary_ID_INVERTER_CONNECTION_STATUS:
            return sprintf(buffer, "%s", "INVERTER_CONNECTION_STATUS");;
        case primary_ID_SHUTDOWN_STATUS:
            return sprintf(buffer, "%s", "SHUTDOWN_STATUS");;
        case primary_ID_MARKER:
            return sprintf(buffer, "%s", "MARKER");;
        case primary_ID_HV_CELLS_VOLTAGE:
            return sprintf(buffer, "%s", "HV_CELLS_VOLTAGE");;
        case primary_ID_HV_CELLS_TEMP:
            return sprintf(buffer, "%s", "HV_CELLS_TEMP");;
        case primary_ID_HV_CELL_BALANCING_STATUS:
            return sprintf(buffer, "%s", "HV_CELL_BALANCING_STATUS");;
        case primary_ID_SET_CELL_BALANCING_STATUS:
            return sprintf(buffer, "%s", "SET_CELL_BALANCING_STATUS");;
        case primary_ID_HANDCART_STATUS:
            return sprintf(buffer, "%s", "HANDCART_STATUS");;
        case primary_ID_SPEED:
            return sprintf(buffer, "%s", "SPEED");;
        case primary_ID_INV_L_REQUEST:
            return sprintf(buffer, "%s", "INV_L_REQUEST");;
        case primary_ID_INV_R_REQUEST:
            return sprintf(buffer, "%s", "INV_R_REQUEST");;
        case primary_ID_INV_L_RESPONSE:
            return sprintf(buffer, "%s", "INV_L_RESPONSE");;
        case primary_ID_INV_R_RESPONSE:
            return sprintf(buffer, "%s", "INV_R_RESPONSE");;
        case primary_ID_FLASH_CELLBOARD_0_TX:
            return sprintf(buffer, "%s", "FLASH_CELLBOARD_0_TX");;
        case primary_ID_FLASH_CELLBOARD_0_RX:
            return sprintf(buffer, "%s", "FLASH_CELLBOARD_0_RX");;
        case primary_ID_FLASH_CELLBOARD_1_TX:
            return sprintf(buffer, "%s", "FLASH_CELLBOARD_1_TX");;
        case primary_ID_FLASH_CELLBOARD_1_RX:
            return sprintf(buffer, "%s", "FLASH_CELLBOARD_1_RX");;
        case primary_ID_FLASH_CELLBOARD_2_TX:
            return sprintf(buffer, "%s", "FLASH_CELLBOARD_2_TX");;
        case primary_ID_FLASH_CELLBOARD_2_RX:
            return sprintf(buffer, "%s", "FLASH_CELLBOARD_2_RX");;
        case primary_ID_FLASH_CELLBOARD_3_TX:
            return sprintf(buffer, "%s", "FLASH_CELLBOARD_3_TX");;
        case primary_ID_FLASH_CELLBOARD_3_RX:
            return sprintf(buffer, "%s", "FLASH_CELLBOARD_3_RX");;
        case primary_ID_FLASH_CELLBOARD_4_TX:
            return sprintf(buffer, "%s", "FLASH_CELLBOARD_4_TX");;
        case primary_ID_FLASH_CELLBOARD_4_RX:
            return sprintf(buffer, "%s", "FLASH_CELLBOARD_4_RX");;
        case primary_ID_FLASH_CELLBOARD_5_TX:
            return sprintf(buffer, "%s", "FLASH_CELLBOARD_5_TX");;
        case primary_ID_FLASH_CELLBOARD_5_RX:
            return sprintf(buffer, "%s", "FLASH_CELLBOARD_5_RX");;
        default:
            return 0; // Unknown message
    }
}

static inline bool primary_is_message_id(canlib_message_id message_id) {
    switch (message_id) {
        case 0: return true; break;
        case 1025: return true; break;
        case 1057: return true; break;
        case 1089: return true; break;
        case 1121: return true; break;
        case 1153: return true; break;
        case 257: return true; break;
        case 258: return true; break;
        case 259: return true; break;
        case 1794: return true; break;
        case 772: return true; break;
        case 804: return true; break;
        case 836: return true; break;
        case 4: return true; break;
        case 5: return true; break;
        case 6: return true; break;
        case 36: return true; break;
        case 37: return true; break;
        case 69: return true; break;
        case 263: return true; break;
        case 775: return true; break;
        case 1031: return true; break;
        case 1063: return true; break;
        case 515: return true; break;
        case 3: return true; break;
        case 776: return true; break;
        case 808: return true; break;
        case 840: return true; break;
        case 872: return true; break;
        case 904: return true; break;
        case 777: return true; break;
        case 809: return true; break;
        case 265: return true; break;
        case 264: return true; break;
        case 296: return true; break;
        case 2: return true; break;
        case 518: return true; break;
        case 550: return true; break;
        case 582: return true; break;
        case 517: return true; break;
        case 773: return true; break;
        case 547: return true; break;
        case 513: return true; break;
        case 514: return true; break;
        case 385: return true; break;
        case 386: return true; break;
        case 16: return true; break;
        case 17: return true; break;
        case 18: return true; break;
        case 19: return true; break;
        case 20: return true; break;
        case 21: return true; break;
        case 22: return true; break;
        case 23: return true; break;
        case 24: return true; break;
        case 25: return true; break;
        case 26: return true; break;
        case 27: return true; break;
    }
    return false;
}

#ifdef primary_IDS_IMPLEMENTATION
#endif // primary_IDS_IMPLEMENTATION

#ifdef __cplusplus
}
#endif

#endif // primary_IDS_H