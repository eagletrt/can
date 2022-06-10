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
#define primary_topic_mask_FLASH 0b00000011111
#define primary_topic_filter_FLASH 0b00000000000 // dec: 0 hex: 0x0

#define primary_id_BMS_HV_JMP_TO_BLT 0b00000000000 // dec: 0 hex: 0x0

/* TOPIC BROADCAST */
#define primary_topic_mask_BROADCAST 0b00000011111
#define primary_topic_filter_BROADCAST 0b00000000001 // dec: 1 hex: 0x1

#define primary_id_STEER_VERSION 0b10000000001 // dec: 1025 hex: 0x401
#define primary_id_DAS_VERSION 0b10000100001 // dec: 1057 hex: 0x421
#define primary_id_HV_VERSION 0b10001000001 // dec: 1089 hex: 0x441
#define primary_id_LV_VERSION 0b10001100001 // dec: 1121 hex: 0x461
#define primary_id_TLM_VERSION 0b10010000001 // dec: 1153 hex: 0x481
#define primary_id_TIMESTAMP 0b00100000001 // dec: 257 hex: 0x101

/* TOPIC TLM */
#define primary_topic_mask_TLM 0b00000011111
#define primary_topic_filter_TLM 0b00000000010 // dec: 2 hex: 0x2

#define primary_id_SET_TLM_STATUS 0b00100000010 // dec: 258 hex: 0x102
#define primary_id_STEER_SYSTEM_STATUS 0b11100000010 // dec: 1794 hex: 0x702
#define primary_id_MARKER 0b00000000010 // dec: 2 hex: 0x2

/* TOPIC STEER */
#define primary_topic_mask_STEER 0b00000011111
#define primary_topic_filter_STEER 0b00000000011 // dec: 3 hex: 0x3

#define primary_id_TLM_STATUS 0b00100000011 // dec: 259 hex: 0x103
#define primary_id_CAR_STATUS 0b01000000011 // dec: 515 hex: 0x203
#define primary_id_DAS_ERRORS 0b00000000011 // dec: 3 hex: 0x3
#define primary_id_SPEED 0b01000100011 // dec: 547 hex: 0x223

/* TOPIC DASnSTEERnCART */
#define primary_topic_mask_DASnSTEERnCART 0b00000011111
#define primary_topic_filter_DASnSTEERnCART 0b00000000100 // dec: 4 hex: 0x4

#define primary_id_HV_VOLTAGE 0b01100000100 // dec: 772 hex: 0x304
#define primary_id_HV_CURRENT 0b01100100100 // dec: 804 hex: 0x324
#define primary_id_HV_TEMP 0b01101000100 // dec: 836 hex: 0x344
#define primary_id_HV_ERRORS 0b00000000100 // dec: 4 hex: 0x4
#define primary_id_TS_STATUS 0b00000100100 // dec: 36 hex: 0x24

/* TOPIC BMS_HV */
#define primary_topic_mask_BMS_HV 0b00000011111
#define primary_topic_filter_BMS_HV 0b00000000101 // dec: 5 hex: 0x5

#define primary_id_HV_CAN_FORWARD 0b00000000101 // dec: 5 hex: 0x5
#define primary_id_SET_TS_STATUS_DAS 0b00000100101 // dec: 37 hex: 0x25
#define primary_id_SET_TS_STATUS_HANDCART 0b00001000101 // dec: 69 hex: 0x45
#define primary_id_SET_CELL_BALANCING_STATUS 0b01000000101 // dec: 517 hex: 0x205
#define primary_id_HANDCART_STATUS 0b01100000101 // dec: 773 hex: 0x305

/* TOPIC HANDCART */
#define primary_topic_mask_HANDCART 0b00000011111
#define primary_topic_filter_HANDCART 0b00000000110 // dec: 6 hex: 0x6

#define primary_id_HV_CAN_FORWARD_STATUS 0b00000000110 // dec: 6 hex: 0x6
#define primary_id_HV_CELLS_VOLTAGE 0b01000000110 // dec: 518 hex: 0x206
#define primary_id_HV_CELLS_TEMP 0b01000100110 // dec: 550 hex: 0x226
#define primary_id_HV_CELL_BALANCING_STATUS 0b01001000110 // dec: 582 hex: 0x246

/* TOPIC DAS */
#define primary_topic_mask_DAS 0b00000011111
#define primary_topic_filter_DAS 0b00000000111 // dec: 7 hex: 0x7

#define primary_id_STEER_STATUS 0b00100000111 // dec: 263 hex: 0x107
#define primary_id_SET_CAR_STATUS 0b01100000111 // dec: 775 hex: 0x307
#define primary_id_SET_PEDALS_RANGE 0b10000000111 // dec: 1031 hex: 0x407
#define primary_id_SET_STEERING_ANGLE_RANGE 0b10000100111 // dec: 1063 hex: 0x427

/* TOPIC DASnSTEER */
#define primary_topic_mask_DASnSTEER 0b00000011111
#define primary_topic_filter_DASnSTEER 0b00000001000 // dec: 8 hex: 0x8

#define primary_id_LV_CURRENT 0b01100001000 // dec: 776 hex: 0x308
#define primary_id_LV_VOLTAGE 0b01100101000 // dec: 808 hex: 0x328
#define primary_id_LV_TOTAL_VOLTAGE 0b01101001000 // dec: 840 hex: 0x348
#define primary_id_LV_TEMPERATURE 0b01101101000 // dec: 872 hex: 0x368
#define primary_id_COOLING_STATUS 0b01110001000 // dec: 904 hex: 0x388

/* TOPIC DASnLV */
#define primary_topic_mask_DASnLV 0b00000011111
#define primary_topic_filter_DASnLV 0b00000001001 // dec: 9 hex: 0x9

#define primary_id_SET_RADIATOR_SPEED 0b01100001001 // dec: 777 hex: 0x309
#define primary_id_SET_PUMPS_POWER 0b01100101001 // dec: 809 hex: 0x329

/* TOPIC FIXED_IDS */
#define primary_topic_mask_FIXED_IDS 0b00000011111

#define primary_id_INV_L_SET_TORQUE 0b01000000001 // dec: 513 hex: 0x201
#define primary_id_INV_L_RESPONSE 0b00110000001 // dec: 385 hex: 0x181
#define primary_id_FLASH_CELLBOARD_0_TX 0b00000010000 // dec: 16 hex: 0x10
#define primary_id_FLASH_CELLBOARD_0_RX 0b00000010001 // dec: 17 hex: 0x11
#define primary_id_FLASH_CELLBOARD_1_TX 0b00000010010 // dec: 18 hex: 0x12
#define primary_id_FLASH_CELLBOARD_1_RX 0b00000010011 // dec: 19 hex: 0x13
#define primary_id_FLASH_CELLBOARD_2_TX 0b00000010100 // dec: 20 hex: 0x14
#define primary_id_FLASH_CELLBOARD_2_RX 0b00000010101 // dec: 21 hex: 0x15
#define primary_id_FLASH_CELLBOARD_3_TX 0b00000010110 // dec: 22 hex: 0x16
#define primary_id_FLASH_CELLBOARD_3_RX 0b00000010111 // dec: 23 hex: 0x17
#define primary_id_FLASH_CELLBOARD_4_TX 0b00000011000 // dec: 24 hex: 0x18
#define primary_id_FLASH_CELLBOARD_4_RX 0b00000011001 // dec: 25 hex: 0x19
#define primary_id_FLASH_CELLBOARD_5_TX 0b00000011010 // dec: 26 hex: 0x1A
#define primary_id_FLASH_CELLBOARD_5_RX 0b00000011011 // dec: 27 hex: 0x1B


// ============== UTILS ============== //

int primary_message_name_from_id(canlib_message_id id, char *buffer);
bool primary_is_message_id(canlib_message_id message_id);

#define primary_MAX_MESSAGE_LENGTH 26

#ifdef primary_IDS_IMPLEMENTATION

int primary_message_name_from_id(canlib_message_id id, char *buffer) {
    switch (id) {
        case primary_id_BMS_HV_JMP_TO_BLT:
            strcpy(buffer, "BMS_HV_JMP_TO_BLT");
            return 0;
        case primary_id_STEER_VERSION:
            strcpy(buffer, "STEER_VERSION");
            return 0;
        case primary_id_DAS_VERSION:
            strcpy(buffer, "DAS_VERSION");
            return 0;
        case primary_id_HV_VERSION:
            strcpy(buffer, "HV_VERSION");
            return 0;
        case primary_id_LV_VERSION:
            strcpy(buffer, "LV_VERSION");
            return 0;
        case primary_id_TLM_VERSION:
            strcpy(buffer, "TLM_VERSION");
            return 0;
        case primary_id_TIMESTAMP:
            strcpy(buffer, "TIMESTAMP");
            return 0;
        case primary_id_SET_TLM_STATUS:
            strcpy(buffer, "SET_TLM_STATUS");
            return 0;
        case primary_id_TLM_STATUS:
            strcpy(buffer, "TLM_STATUS");
            return 0;
        case primary_id_STEER_SYSTEM_STATUS:
            strcpy(buffer, "STEER_SYSTEM_STATUS");
            return 0;
        case primary_id_HV_VOLTAGE:
            strcpy(buffer, "HV_VOLTAGE");
            return 0;
        case primary_id_HV_CURRENT:
            strcpy(buffer, "HV_CURRENT");
            return 0;
        case primary_id_HV_TEMP:
            strcpy(buffer, "HV_TEMP");
            return 0;
        case primary_id_HV_ERRORS:
            strcpy(buffer, "HV_ERRORS");
            return 0;
        case primary_id_HV_CAN_FORWARD:
            strcpy(buffer, "HV_CAN_FORWARD");
            return 0;
        case primary_id_HV_CAN_FORWARD_STATUS:
            strcpy(buffer, "HV_CAN_FORWARD_STATUS");
            return 0;
        case primary_id_TS_STATUS:
            strcpy(buffer, "TS_STATUS");
            return 0;
        case primary_id_SET_TS_STATUS_DAS:
            strcpy(buffer, "SET_TS_STATUS_DAS");
            return 0;
        case primary_id_SET_TS_STATUS_HANDCART:
            strcpy(buffer, "SET_TS_STATUS_HANDCART");
            return 0;
        case primary_id_STEER_STATUS:
            strcpy(buffer, "STEER_STATUS");
            return 0;
        case primary_id_SET_CAR_STATUS:
            strcpy(buffer, "SET_CAR_STATUS");
            return 0;
        case primary_id_SET_PEDALS_RANGE:
            strcpy(buffer, "SET_PEDALS_RANGE");
            return 0;
        case primary_id_SET_STEERING_ANGLE_RANGE:
            strcpy(buffer, "SET_STEERING_ANGLE_RANGE");
            return 0;
        case primary_id_CAR_STATUS:
            strcpy(buffer, "CAR_STATUS");
            return 0;
        case primary_id_DAS_ERRORS:
            strcpy(buffer, "DAS_ERRORS");
            return 0;
        case primary_id_LV_CURRENT:
            strcpy(buffer, "LV_CURRENT");
            return 0;
        case primary_id_LV_VOLTAGE:
            strcpy(buffer, "LV_VOLTAGE");
            return 0;
        case primary_id_LV_TOTAL_VOLTAGE:
            strcpy(buffer, "LV_TOTAL_VOLTAGE");
            return 0;
        case primary_id_LV_TEMPERATURE:
            strcpy(buffer, "LV_TEMPERATURE");
            return 0;
        case primary_id_COOLING_STATUS:
            strcpy(buffer, "COOLING_STATUS");
            return 0;
        case primary_id_SET_RADIATOR_SPEED:
            strcpy(buffer, "SET_RADIATOR_SPEED");
            return 0;
        case primary_id_SET_PUMPS_POWER:
            strcpy(buffer, "SET_PUMPS_POWER");
            return 0;
        case primary_id_MARKER:
            strcpy(buffer, "MARKER");
            return 0;
        case primary_id_HV_CELLS_VOLTAGE:
            strcpy(buffer, "HV_CELLS_VOLTAGE");
            return 0;
        case primary_id_HV_CELLS_TEMP:
            strcpy(buffer, "HV_CELLS_TEMP");
            return 0;
        case primary_id_HV_CELL_BALANCING_STATUS:
            strcpy(buffer, "HV_CELL_BALANCING_STATUS");
            return 0;
        case primary_id_SET_CELL_BALANCING_STATUS:
            strcpy(buffer, "SET_CELL_BALANCING_STATUS");
            return 0;
        case primary_id_HANDCART_STATUS:
            strcpy(buffer, "HANDCART_STATUS");
            return 0;
        case primary_id_SPEED:
            strcpy(buffer, "SPEED");
            return 0;
        case primary_id_INV_L_SET_TORQUE:
            strcpy(buffer, "INV_L_SET_TORQUE");
            return 0;
        case primary_id_INV_L_RESPONSE:
            strcpy(buffer, "INV_L_RESPONSE");
            return 0;
        case primary_id_FLASH_CELLBOARD_0_TX:
            strcpy(buffer, "FLASH_CELLBOARD_0_TX");
            return 0;
        case primary_id_FLASH_CELLBOARD_0_RX:
            strcpy(buffer, "FLASH_CELLBOARD_0_RX");
            return 0;
        case primary_id_FLASH_CELLBOARD_1_TX:
            strcpy(buffer, "FLASH_CELLBOARD_1_TX");
            return 0;
        case primary_id_FLASH_CELLBOARD_1_RX:
            strcpy(buffer, "FLASH_CELLBOARD_1_RX");
            return 0;
        case primary_id_FLASH_CELLBOARD_2_TX:
            strcpy(buffer, "FLASH_CELLBOARD_2_TX");
            return 0;
        case primary_id_FLASH_CELLBOARD_2_RX:
            strcpy(buffer, "FLASH_CELLBOARD_2_RX");
            return 0;
        case primary_id_FLASH_CELLBOARD_3_TX:
            strcpy(buffer, "FLASH_CELLBOARD_3_TX");
            return 0;
        case primary_id_FLASH_CELLBOARD_3_RX:
            strcpy(buffer, "FLASH_CELLBOARD_3_RX");
            return 0;
        case primary_id_FLASH_CELLBOARD_4_TX:
            strcpy(buffer, "FLASH_CELLBOARD_4_TX");
            return 0;
        case primary_id_FLASH_CELLBOARD_4_RX:
            strcpy(buffer, "FLASH_CELLBOARD_4_RX");
            return 0;
        case primary_id_FLASH_CELLBOARD_5_TX:
            strcpy(buffer, "FLASH_CELLBOARD_5_TX");
            return 0;
        case primary_id_FLASH_CELLBOARD_5_RX:
            strcpy(buffer, "FLASH_CELLBOARD_5_RX");
            return 0;
        default:
            strcpy(buffer, ""); // Unknown message
    }
    return 1;
}

bool primary_is_message_id(canlib_message_id message_id) {
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
        case 2: return true; break;
        case 518: return true; break;
        case 550: return true; break;
        case 582: return true; break;
        case 517: return true; break;
        case 773: return true; break;
        case 547: return true; break;
        case 513: return true; break;
        case 385: return true; break;
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

#endif // primary_IDS_IMPLEMENTATION

#ifdef __cplusplus
}
#endif

#endif // primary_IDS_H