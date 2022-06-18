#ifndef bms_IDS_H
#define bms_IDS_H

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

#define bms_IDS_VERSION 1.2


/* TOPIC STATUS */
#define bms_TOPIC_MASK_STATUS 0b00000011111
#define bms_TOPIC_FILTER_STATUS 0x0 // dec: 0 bin: 0b00000000000

#define bms_ID_BOARD_STATUS_CELLBOARD0 0x600 // dec: 1536 bin: 0b11000000000
#define bms_ID_BOARD_STATUS_CELLBOARD1 0x620 // dec: 1568 bin: 0b11000100000
#define bms_ID_BOARD_STATUS_CELLBOARD2 0x640 // dec: 1600 bin: 0b11001000000
#define bms_ID_BOARD_STATUS_CELLBOARD3 0x660 // dec: 1632 bin: 0b11001100000
#define bms_ID_BOARD_STATUS_CELLBOARD4 0x680 // dec: 1664 bin: 0b11010000000
#define bms_ID_BOARD_STATUS_CELLBOARD5 0x6A0 // dec: 1696 bin: 0b11010100000

/* TOPIC TEMPERATURE_INFO */
#define bms_TOPIC_MASK_TEMPERATURE_INFO 0b00000011111
#define bms_TOPIC_FILTER_TEMPERATURE_INFO 0x1 // dec: 1 bin: 0b00000000001

#define bms_ID_TEMPERATURES_CELLBOARD0 0x501 // dec: 1281 bin: 0b10100000001
#define bms_ID_TEMPERATURES_CELLBOARD1 0x521 // dec: 1313 bin: 0b10100100001
#define bms_ID_TEMPERATURES_CELLBOARD2 0x541 // dec: 1345 bin: 0b10101000001
#define bms_ID_TEMPERATURES_CELLBOARD3 0x561 // dec: 1377 bin: 0b10101100001
#define bms_ID_TEMPERATURES_CELLBOARD4 0x581 // dec: 1409 bin: 0b10110000001
#define bms_ID_TEMPERATURES_CELLBOARD5 0x5A1 // dec: 1441 bin: 0b10110100001

/* TOPIC VOLTAGE_INFO */
#define bms_TOPIC_MASK_VOLTAGE_INFO 0b00000011111
#define bms_TOPIC_FILTER_VOLTAGE_INFO 0x2 // dec: 2 bin: 0b00000000010

#define bms_ID_VOLTAGES_CELLBOARD0 0x202 // dec: 514 bin: 0b01000000010
#define bms_ID_VOLTAGES_CELLBOARD1 0x222 // dec: 546 bin: 0b01000100010
#define bms_ID_VOLTAGES_CELLBOARD2 0x242 // dec: 578 bin: 0b01001000010
#define bms_ID_VOLTAGES_CELLBOARD3 0x262 // dec: 610 bin: 0b01001100010
#define bms_ID_VOLTAGES_CELLBOARD4 0x282 // dec: 642 bin: 0b01010000010
#define bms_ID_VOLTAGES_CELLBOARD5 0x2A2 // dec: 674 bin: 0b01010100010

/* TOPIC BALANCING */
#define bms_TOPIC_MASK_BALANCING 0b00000011111
#define bms_TOPIC_FILTER_BALANCING 0x3 // dec: 3 bin: 0b00000000011

#define bms_ID_BALANCING 0x203 // dec: 515 bin: 0b01000000011

/* TOPIC FIXED_IDS */
#define bms_TOPIC_MASK_FIXED_IDS 0b00000011111

#define bms_ID_FW_UPDATE 0xA // dec: 10 bin: 0b00000001010
#define bms_ID_FLASH_CELLBOARD_0_TX 0x10 // dec: 16 bin: 0b00000010000
#define bms_ID_FLASH_CELLBOARD_0_RX 0x11 // dec: 17 bin: 0b00000010001
#define bms_ID_FLASH_CELLBOARD_1_TX 0x12 // dec: 18 bin: 0b00000010010
#define bms_ID_FLASH_CELLBOARD_1_RX 0x13 // dec: 19 bin: 0b00000010011
#define bms_ID_FLASH_CELLBOARD_2_TX 0x14 // dec: 20 bin: 0b00000010100
#define bms_ID_FLASH_CELLBOARD_2_RX 0x15 // dec: 21 bin: 0b00000010101
#define bms_ID_FLASH_CELLBOARD_3_TX 0x16 // dec: 22 bin: 0b00000010110
#define bms_ID_FLASH_CELLBOARD_3_RX 0x17 // dec: 23 bin: 0b00000010111
#define bms_ID_FLASH_CELLBOARD_4_TX 0x18 // dec: 24 bin: 0b00000011000
#define bms_ID_FLASH_CELLBOARD_4_RX 0x19 // dec: 25 bin: 0b00000011001
#define bms_ID_FLASH_CELLBOARD_5_TX 0x1A // dec: 26 bin: 0b00000011010
#define bms_ID_FLASH_CELLBOARD_5_RX 0x1B // dec: 27 bin: 0b00000011011


#define bms_MAX_MESSAGE_NAME_LENGTH 24

// ============== UTILS ============== //

static inline int bms_message_name_from_id(canlib_message_id id, char *buffer) {
    switch (id) {
        case bms_ID_BOARD_STATUS_CELLBOARD0:
            return sprintf(buffer, "%s", "BOARD_STATUS_CELLBOARD0");;
        case bms_ID_BOARD_STATUS_CELLBOARD1:
            return sprintf(buffer, "%s", "BOARD_STATUS_CELLBOARD1");;
        case bms_ID_BOARD_STATUS_CELLBOARD2:
            return sprintf(buffer, "%s", "BOARD_STATUS_CELLBOARD2");;
        case bms_ID_BOARD_STATUS_CELLBOARD3:
            return sprintf(buffer, "%s", "BOARD_STATUS_CELLBOARD3");;
        case bms_ID_BOARD_STATUS_CELLBOARD4:
            return sprintf(buffer, "%s", "BOARD_STATUS_CELLBOARD4");;
        case bms_ID_BOARD_STATUS_CELLBOARD5:
            return sprintf(buffer, "%s", "BOARD_STATUS_CELLBOARD5");;
        case bms_ID_TEMPERATURES_CELLBOARD0:
            return sprintf(buffer, "%s", "TEMPERATURES_CELLBOARD0");;
        case bms_ID_TEMPERATURES_CELLBOARD1:
            return sprintf(buffer, "%s", "TEMPERATURES_CELLBOARD1");;
        case bms_ID_TEMPERATURES_CELLBOARD2:
            return sprintf(buffer, "%s", "TEMPERATURES_CELLBOARD2");;
        case bms_ID_TEMPERATURES_CELLBOARD3:
            return sprintf(buffer, "%s", "TEMPERATURES_CELLBOARD3");;
        case bms_ID_TEMPERATURES_CELLBOARD4:
            return sprintf(buffer, "%s", "TEMPERATURES_CELLBOARD4");;
        case bms_ID_TEMPERATURES_CELLBOARD5:
            return sprintf(buffer, "%s", "TEMPERATURES_CELLBOARD5");;
        case bms_ID_VOLTAGES_CELLBOARD0:
            return sprintf(buffer, "%s", "VOLTAGES_CELLBOARD0");;
        case bms_ID_VOLTAGES_CELLBOARD1:
            return sprintf(buffer, "%s", "VOLTAGES_CELLBOARD1");;
        case bms_ID_VOLTAGES_CELLBOARD2:
            return sprintf(buffer, "%s", "VOLTAGES_CELLBOARD2");;
        case bms_ID_VOLTAGES_CELLBOARD3:
            return sprintf(buffer, "%s", "VOLTAGES_CELLBOARD3");;
        case bms_ID_VOLTAGES_CELLBOARD4:
            return sprintf(buffer, "%s", "VOLTAGES_CELLBOARD4");;
        case bms_ID_VOLTAGES_CELLBOARD5:
            return sprintf(buffer, "%s", "VOLTAGES_CELLBOARD5");;
        case bms_ID_BALANCING:
            return sprintf(buffer, "%s", "BALANCING");;
        case bms_ID_FW_UPDATE:
            return sprintf(buffer, "%s", "FW_UPDATE");;
        case bms_ID_FLASH_CELLBOARD_0_TX:
            return sprintf(buffer, "%s", "FLASH_CELLBOARD_0_TX");;
        case bms_ID_FLASH_CELLBOARD_0_RX:
            return sprintf(buffer, "%s", "FLASH_CELLBOARD_0_RX");;
        case bms_ID_FLASH_CELLBOARD_1_TX:
            return sprintf(buffer, "%s", "FLASH_CELLBOARD_1_TX");;
        case bms_ID_FLASH_CELLBOARD_1_RX:
            return sprintf(buffer, "%s", "FLASH_CELLBOARD_1_RX");;
        case bms_ID_FLASH_CELLBOARD_2_TX:
            return sprintf(buffer, "%s", "FLASH_CELLBOARD_2_TX");;
        case bms_ID_FLASH_CELLBOARD_2_RX:
            return sprintf(buffer, "%s", "FLASH_CELLBOARD_2_RX");;
        case bms_ID_FLASH_CELLBOARD_3_TX:
            return sprintf(buffer, "%s", "FLASH_CELLBOARD_3_TX");;
        case bms_ID_FLASH_CELLBOARD_3_RX:
            return sprintf(buffer, "%s", "FLASH_CELLBOARD_3_RX");;
        case bms_ID_FLASH_CELLBOARD_4_TX:
            return sprintf(buffer, "%s", "FLASH_CELLBOARD_4_TX");;
        case bms_ID_FLASH_CELLBOARD_4_RX:
            return sprintf(buffer, "%s", "FLASH_CELLBOARD_4_RX");;
        case bms_ID_FLASH_CELLBOARD_5_TX:
            return sprintf(buffer, "%s", "FLASH_CELLBOARD_5_TX");;
        case bms_ID_FLASH_CELLBOARD_5_RX:
            return sprintf(buffer, "%s", "FLASH_CELLBOARD_5_RX");;
        default:
            return 0; // Unknown message
    }
}

static inline bool bms_is_message_id(canlib_message_id message_id) {
    switch (message_id) {
        case 1536: return true; break;
        case 1568: return true; break;
        case 1600: return true; break;
        case 1632: return true; break;
        case 1664: return true; break;
        case 1696: return true; break;
        case 1281: return true; break;
        case 1313: return true; break;
        case 1345: return true; break;
        case 1377: return true; break;
        case 1409: return true; break;
        case 1441: return true; break;
        case 514: return true; break;
        case 546: return true; break;
        case 578: return true; break;
        case 610: return true; break;
        case 642: return true; break;
        case 674: return true; break;
        case 515: return true; break;
        case 10: return true; break;
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

#ifdef bms_IDS_IMPLEMENTATION
#endif // bms_IDS_IMPLEMENTATION

#ifdef __cplusplus
}
#endif

#endif // bms_IDS_H