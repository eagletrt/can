#ifndef primary_IDS_H
#define primary_IDS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
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
#define primary_ID_BMS_LV_JMP_TO_BLT 0x20 // dec: 32 bin: 0b00000100000

/* TOPIC BROADCAST */
#define primary_TOPIC_MASK_BROADCAST 0b00000011111
#define primary_TOPIC_FILTER_BROADCAST 0x1 // dec: 1 bin: 0b00000000001

#define primary_ID_STEER_VERSION 0x401 // dec: 1025 bin: 0b10000000001
#define primary_ID_DAS_VERSION 0x421 // dec: 1057 bin: 0b10000100001
#define primary_ID_HV_VERSION 0x441 // dec: 1089 bin: 0b10001000001
#define primary_ID_LV_VERSION 0x461 // dec: 1121 bin: 0b10001100001
#define primary_ID_TLM_VERSION 0x481 // dec: 1153 bin: 0b10010000001
#define primary_ID_TIMESTAMP 0x101 // dec: 257 bin: 0b00100000001
#define primary_ID_AMBIENT_TEMPERATURE 0x121 // dec: 289 bin: 0b00100100001

/* TOPIC FIXED_IDS */
#define primary_TOPIC_MASK_FIXED_IDS 0b00000011111

#define primary_ID_DATA_LOGGER 0x430 // dec: 1072 bin: 0b10000110000
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
#define primary_ID_FLASH_BMS_HV_TX 0x7E1 // dec: 2017 bin: 0b11111100001
#define primary_ID_FLASH_BMS_HV_RX 0x667 // dec: 1639 bin: 0b11001100111
#define primary_ID_FLASH_BMS_LV_TX 0x7F1 // dec: 2033 bin: 0b11111110001
#define primary_ID_FLASH_BMS_LV_RX 0x677 // dec: 1655 bin: 0b11001110111
#define primary_ID_BRUSA_NLG5_CTL 0x26A // dec: 618 bin: 0b01001101010
#define primary_ID_BRUSA_ST 0x262 // dec: 610 bin: 0b01001100010
#define primary_ID_BRUSA_ACT_I 0x263 // dec: 611 bin: 0b01001100011
#define primary_ID_BRUSA_ACT_II 0x264 // dec: 612 bin: 0b01001100100
#define primary_ID_BRUSA_TEMP 0x265 // dec: 613 bin: 0b01001100101
#define primary_ID_BRUSA_ERR 0x266 // dec: 614 bin: 0b01001100110

/* TOPIC TLM */
#define primary_TOPIC_MASK_TLM 0b00000011111
#define primary_TOPIC_FILTER_TLM 0x3 // dec: 3 bin: 0b00000000011

#define primary_ID_SET_TLM_STATUS 0x103 // dec: 259 bin: 0b00100000011
#define primary_ID_STEER_SYSTEM_STATUS 0x703 // dec: 1795 bin: 0b11100000011
#define primary_ID_MARKER 0x3 // dec: 3 bin: 0b00000000011

/* TOPIC STEER */
#define primary_TOPIC_MASK_STEER 0b00000011111
#define primary_TOPIC_FILTER_STEER 0x4 // dec: 4 bin: 0b00000000100

#define primary_ID_TLM_STATUS 0x104 // dec: 260 bin: 0b00100000100
#define primary_ID_CAR_STATUS 0x204 // dec: 516 bin: 0b01000000100
#define primary_ID_DAS_ERRORS 0x4 // dec: 4 bin: 0b00000000100
#define primary_ID_SPEED 0x224 // dec: 548 bin: 0b01000100100
#define primary_ID_CONTROL_OUTPUT 0x504 // dec: 1284 bin: 0b10100000100

/* TOPIC DASnSTEERnCART */
#define primary_TOPIC_MASK_DASnSTEERnCART 0b00000011111
#define primary_TOPIC_FILTER_DASnSTEERnCART 0x5 // dec: 5 bin: 0b00000000101

#define primary_ID_HV_VOLTAGE 0x305 // dec: 773 bin: 0b01100000101
#define primary_ID_HV_CURRENT 0x325 // dec: 805 bin: 0b01100100101
#define primary_ID_HV_TEMP 0x345 // dec: 837 bin: 0b01101000101
#define primary_ID_HV_ERRORS 0x5 // dec: 5 bin: 0b00000000101
#define primary_ID_TS_STATUS 0x25 // dec: 37 bin: 0b00000100101

/* TOPIC BMS_HV */
#define primary_TOPIC_MASK_BMS_HV 0b00000011111
#define primary_TOPIC_FILTER_BMS_HV 0x6 // dec: 6 bin: 0b00000000110

#define primary_ID_HV_CAN_FORWARD 0x6 // dec: 6 bin: 0b00000000110
#define primary_ID_HV_FANS_OVERRIDE 0x26 // dec: 38 bin: 0b00000100110
#define primary_ID_SET_TS_STATUS_DAS 0x46 // dec: 70 bin: 0b00001000110
#define primary_ID_SET_TS_STATUS_HANDCART 0x66 // dec: 102 bin: 0b00001100110
#define primary_ID_SET_CELL_BALANCING_STATUS 0x206 // dec: 518 bin: 0b01000000110
#define primary_ID_HANDCART_STATUS 0x306 // dec: 774 bin: 0b01100000110

/* TOPIC HANDCART */
#define primary_TOPIC_MASK_HANDCART 0b00000011111
#define primary_TOPIC_FILTER_HANDCART 0x7 // dec: 7 bin: 0b00000000111

#define primary_ID_HV_CAN_FORWARD_STATUS 0x7 // dec: 7 bin: 0b00000000111
#define primary_ID_HV_FANS_OVERRIDE_STATUS 0x307 // dec: 775 bin: 0b01100000111
#define primary_ID_HV_CELLS_VOLTAGE 0x207 // dec: 519 bin: 0b01000000111
#define primary_ID_HV_CELLS_TEMP 0x227 // dec: 551 bin: 0b01000100111
#define primary_ID_HV_CELL_BALANCING_STATUS 0x247 // dec: 583 bin: 0b01001000111

/* TOPIC DASnSTEER */
#define primary_TOPIC_MASK_DASnSTEER 0b00000011111
#define primary_TOPIC_FILTER_DASnSTEER 0x8 // dec: 8 bin: 0b00000001000

#define primary_ID_HV_FEEDBACKS_STATUS 0x308 // dec: 776 bin: 0b01100001000
#define primary_ID_HV_IMD_STATUS 0x328 // dec: 808 bin: 0b01100101000
#define primary_ID_LV_CURRENT 0x348 // dec: 840 bin: 0b01101001000
#define primary_ID_LV_VOLTAGE 0x368 // dec: 872 bin: 0b01101101000
#define primary_ID_LV_TOTAL_VOLTAGE 0x388 // dec: 904 bin: 0b01110001000
#define primary_ID_LV_TEMPERATURE 0x3A8 // dec: 936 bin: 0b01110101000
#define primary_ID_COOLING_STATUS 0x3C8 // dec: 968 bin: 0b01111001000
#define primary_ID_INVERTER_CONNECTION_STATUS 0x108 // dec: 264 bin: 0b00100001000
#define primary_ID_LV_ERRORS 0x8 // dec: 8 bin: 0b00000001000
#define primary_ID_SHUTDOWN_STATUS 0x128 // dec: 296 bin: 0b00100101000

/* TOPIC DAS */
#define primary_TOPIC_MASK_DAS 0b00000011111
#define primary_TOPIC_FILTER_DAS 0x9 // dec: 9 bin: 0b00000001001

#define primary_ID_STEER_STATUS 0x109 // dec: 265 bin: 0b00100001001
#define primary_ID_SET_CAR_STATUS 0x309 // dec: 777 bin: 0b01100001001
#define primary_ID_SET_PEDALS_RANGE 0x409 // dec: 1033 bin: 0b10000001001
#define primary_ID_SET_STEERING_ANGLE_RANGE 0x429 // dec: 1065 bin: 0b10000101001

/* TOPIC LV */
#define primary_TOPIC_MASK_LV 0b00000011111
#define primary_TOPIC_FILTER_LV 0xA // dec: 10 bin: 0b00000001010

#define primary_ID_SET_RADIATOR_SPEED 0x30A // dec: 778 bin: 0b01100001010
#define primary_ID_SET_PUMPS_SPEED 0x32A // dec: 810 bin: 0b01100101010
#define primary_ID_SET_INVERTER_CONNECTION_STATUS 0x10A // dec: 266 bin: 0b00100001010

/* TOPIC LAPCOUNTER */
#define primary_TOPIC_MASK_LAPCOUNTER 0b00000011111
#define primary_TOPIC_FILTER_LAPCOUNTER 0xB // dec: 11 bin: 0b00000001011

#define primary_ID_LC_RESET 0x20B // dec: 523 bin: 0b01000001011


#define primary_MAX_MESSAGE_NAME_LENGTH 31

// ============== UTILS ============== //

static inline int primary_message_name_from_id(canlib_message_id id, char *buffer) {
    switch (id) {
        case primary_ID_BMS_HV_JMP_TO_BLT:
            return sprintf(buffer, "%s", "BMS_HV_JMP_TO_BLT");;
        case primary_ID_BMS_LV_JMP_TO_BLT:
            return sprintf(buffer, "%s", "BMS_LV_JMP_TO_BLT");;
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
        case primary_ID_AMBIENT_TEMPERATURE:
            return sprintf(buffer, "%s", "AMBIENT_TEMPERATURE");;
        case primary_ID_DATA_LOGGER:
            return sprintf(buffer, "%s", "DATA_LOGGER");;
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
        case primary_ID_HV_FANS_OVERRIDE:
            return sprintf(buffer, "%s", "HV_FANS_OVERRIDE");;
        case primary_ID_HV_CAN_FORWARD_STATUS:
            return sprintf(buffer, "%s", "HV_CAN_FORWARD_STATUS");;
        case primary_ID_HV_FANS_OVERRIDE_STATUS:
            return sprintf(buffer, "%s", "HV_FANS_OVERRIDE_STATUS");;
        case primary_ID_HV_FEEDBACKS_STATUS:
            return sprintf(buffer, "%s", "HV_FEEDBACKS_STATUS");;
        case primary_ID_HV_IMD_STATUS:
            return sprintf(buffer, "%s", "HV_IMD_STATUS");;
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
        case primary_ID_LV_ERRORS:
            return sprintf(buffer, "%s", "LV_ERRORS");;
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
        case primary_ID_FLASH_BMS_HV_TX:
            return sprintf(buffer, "%s", "FLASH_BMS_HV_TX");;
        case primary_ID_FLASH_BMS_HV_RX:
            return sprintf(buffer, "%s", "FLASH_BMS_HV_RX");;
        case primary_ID_FLASH_BMS_LV_TX:
            return sprintf(buffer, "%s", "FLASH_BMS_LV_TX");;
        case primary_ID_FLASH_BMS_LV_RX:
            return sprintf(buffer, "%s", "FLASH_BMS_LV_RX");;
        case primary_ID_BRUSA_NLG5_CTL:
            return sprintf(buffer, "%s", "BRUSA_NLG5_CTL");;
        case primary_ID_BRUSA_ST:
            return sprintf(buffer, "%s", "BRUSA_ST");;
        case primary_ID_BRUSA_ACT_I:
            return sprintf(buffer, "%s", "BRUSA_ACT_I");;
        case primary_ID_BRUSA_ACT_II:
            return sprintf(buffer, "%s", "BRUSA_ACT_II");;
        case primary_ID_BRUSA_TEMP:
            return sprintf(buffer, "%s", "BRUSA_TEMP");;
        case primary_ID_BRUSA_ERR:
            return sprintf(buffer, "%s", "BRUSA_ERR");;
        case primary_ID_CONTROL_OUTPUT:
            return sprintf(buffer, "%s", "CONTROL_OUTPUT");;
        case primary_ID_LC_RESET:
            return sprintf(buffer, "%s", "LC_RESET");;
        default:
            return 0; // Unknown message
    }
}

static inline bool primary_is_message_id(canlib_message_id message_id) {
    switch (message_id) {
        case 0: return true; break;
        case 32: return true; break;
        case 1025: return true; break;
        case 1057: return true; break;
        case 1089: return true; break;
        case 1121: return true; break;
        case 1153: return true; break;
        case 257: return true; break;
        case 289: return true; break;
        case 1072: return true; break;
        case 259: return true; break;
        case 260: return true; break;
        case 1795: return true; break;
        case 773: return true; break;
        case 805: return true; break;
        case 837: return true; break;
        case 5: return true; break;
        case 6: return true; break;
        case 38: return true; break;
        case 7: return true; break;
        case 775: return true; break;
        case 776: return true; break;
        case 808: return true; break;
        case 37: return true; break;
        case 70: return true; break;
        case 102: return true; break;
        case 265: return true; break;
        case 777: return true; break;
        case 1033: return true; break;
        case 1065: return true; break;
        case 516: return true; break;
        case 4: return true; break;
        case 840: return true; break;
        case 872: return true; break;
        case 904: return true; break;
        case 936: return true; break;
        case 968: return true; break;
        case 778: return true; break;
        case 810: return true; break;
        case 266: return true; break;
        case 264: return true; break;
        case 8: return true; break;
        case 296: return true; break;
        case 3: return true; break;
        case 519: return true; break;
        case 551: return true; break;
        case 583: return true; break;
        case 518: return true; break;
        case 774: return true; break;
        case 548: return true; break;
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
        case 2017: return true; break;
        case 1639: return true; break;
        case 2033: return true; break;
        case 1655: return true; break;
        case 618: return true; break;
        case 610: return true; break;
        case 611: return true; break;
        case 612: return true; break;
        case 613: return true; break;
        case 614: return true; break;
        case 1284: return true; break;
        case 523: return true; break;
    }
    return false;
}

#ifdef primary_IDS_IMPLEMENTATION
#endif // primary_IDS_IMPLEMENTATION

#ifdef __cplusplus
}
#endif

#endif // primary_IDS_H