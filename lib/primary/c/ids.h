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
#define primary_topic_filter_FLASH 0b00000000000

#define primary_id_BMS_HV_JMP_TO_BLT 0b00000000000

/* TOPIC BROADCAST */
#define primary_topic_mask_BROADCAST 0b00000011111
#define primary_topic_filter_BROADCAST 0b00000000001

#define primary_id_STEER_VERSION 0b10000000001
#define primary_id_DAS_VERSION 0b10000100001
#define primary_id_HV_VERSION 0b10001000001
#define primary_id_LV_VERSION 0b10001100001
#define primary_id_TLM_VERSION 0b10010000001
#define primary_id_TIMESTAMP 0b00100000001

/* TOPIC TLM */
#define primary_topic_mask_TLM 0b00000011111
#define primary_topic_filter_TLM 0b00000000010

#define primary_id_SET_TLM_STATUS 0b00100000010
#define primary_id_STEER_SYSTEM_STATUS 0b11100000010
#define primary_id_MARKER 0b00000000010

/* TOPIC STEER */
#define primary_topic_mask_STEER 0b00000011111
#define primary_topic_filter_STEER 0b00000000011

#define primary_id_TLM_STATUS 0b00100000011
#define primary_id_CAR_STATUS 0b01000000011
#define primary_id_DAS_ERRORS 0b00000000011
#define primary_id_SPEED 0b01000100011

/* TOPIC DASnSTEERnCART */
#define primary_topic_mask_DASnSTEERnCART 0b00000011111
#define primary_topic_filter_DASnSTEERnCART 0b00000000100

#define primary_id_HV_VOLTAGE 0b01100000100
#define primary_id_HV_CURRENT 0b01100100100
#define primary_id_HV_TEMP 0b01101000100
#define primary_id_HV_ERRORS 0b00000000100
#define primary_id_TS_STATUS 0b00000100100

/* TOPIC BMS_HV */
#define primary_topic_mask_BMS_HV 0b00000011111
#define primary_topic_filter_BMS_HV 0b00000000101

#define primary_id_HV_CAN_FORWARD 0b00000000101
#define primary_id_SET_TS_STATUS_DAS 0b00000100101
#define primary_id_SET_TS_STATUS_HANDCART 0b00001000101
#define primary_id_SET_CELL_BALANCING_STATUS 0b01000000101
#define primary_id_HANDCART_STATUS 0b01100000101

/* TOPIC HANDCART */
#define primary_topic_mask_HANDCART 0b00000011111
#define primary_topic_filter_HANDCART 0b00000000110

#define primary_id_HV_CAN_FORWARD_STATUS 0b00000000110
#define primary_id_HV_CELLS_VOLTAGE 0b01000000110
#define primary_id_HV_CELLS_TEMP 0b01000100110
#define primary_id_HV_CELL_BALANCING_STATUS 0b01001000110

/* TOPIC DAS */
#define primary_topic_mask_DAS 0b00000011111
#define primary_topic_filter_DAS 0b00000000111

#define primary_id_STEER_STATUS 0b00100000111
#define primary_id_SET_CAR_STATUS 0b01100000111
#define primary_id_SET_PEDALS_RANGE 0b10000000111
#define primary_id_SET_STEERING_ANGLE_RANGE 0b10000100111

/* TOPIC DASnSTEER */
#define primary_topic_mask_DASnSTEER 0b00000011111
#define primary_topic_filter_DASnSTEER 0b00000001000

#define primary_id_LV_CURRENT 0b01100001000
#define primary_id_LV_VOLTAGE 0b01100101000
#define primary_id_LV_TOTAL_VOLTAGE 0b01101001000
#define primary_id_LV_TEMPERATURE 0b01101101000
#define primary_id_COOLING_STATUS 0b01110001000

/* TOPIC DASnLV */
#define primary_topic_mask_DASnLV 0b00000011111
#define primary_topic_filter_DASnLV 0b00000001001

#define primary_id_SET_RADIATOR_SPEED 0b01100001001
#define primary_id_SET_PUMPS_POWER 0b01100101001

/* TOPIC FIXED_IDS */
#define primary_topic_mask_FIXED_IDS 0b00000011111

#define primary_id_INV_L_SET_TORQUE 0b01000000001
#define primary_id_INV_L_RESPONSE 0b00110000001
#define primary_id_FLASH_CELLBOARD_0_TX 0b00000010000
#define primary_id_FLASH_CELLBOARD_0_RX 0b00000010001
#define primary_id_FLASH_CELLBOARD_1_TX 0b00000010010
#define primary_id_FLASH_CELLBOARD_1_RX 0b00000010011
#define primary_id_FLASH_CELLBOARD_2_TX 0b00000010100
#define primary_id_FLASH_CELLBOARD_2_RX 0b00000010101
#define primary_id_FLASH_CELLBOARD_3_TX 0b00000010110
#define primary_id_FLASH_CELLBOARD_3_RX 0b00000010111
#define primary_id_FLASH_CELLBOARD_4_TX 0b00000011000
#define primary_id_FLASH_CELLBOARD_4_RX 0b00000011001
#define primary_id_FLASH_CELLBOARD_5_TX 0b00000011010
#define primary_id_FLASH_CELLBOARD_5_RX 0b00000011011


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