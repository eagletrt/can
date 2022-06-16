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
#define bms_topic_mask_STATUS 0b00000011111
#define bms_topic_filter_STATUS 0b00000000000 // dec: 0 hex: 0x0

#define bms_id_BOARD_STATUS_CELLBOARD0 0b11000000000 // dec: 1536 hex: 0x600
#define bms_id_BOARD_STATUS_CELLBOARD1 0b11000100000 // dec: 1568 hex: 0x620
#define bms_id_BOARD_STATUS_CELLBOARD2 0b11001000000 // dec: 1600 hex: 0x640
#define bms_id_BOARD_STATUS_CELLBOARD3 0b11001100000 // dec: 1632 hex: 0x660
#define bms_id_BOARD_STATUS_CELLBOARD4 0b11010000000 // dec: 1664 hex: 0x680
#define bms_id_BOARD_STATUS_CELLBOARD5 0b11010100000 // dec: 1696 hex: 0x6A0

/* TOPIC TEMPERATURE_INFO */
#define bms_topic_mask_TEMPERATURE_INFO 0b00000011111
#define bms_topic_filter_TEMPERATURE_INFO 0b00000000001 // dec: 1 hex: 0x1

#define bms_id_TEMPERATURES_CELLBOARD0 0b10100000001 // dec: 1281 hex: 0x501
#define bms_id_TEMPERATURES_CELLBOARD1 0b10100100001 // dec: 1313 hex: 0x521
#define bms_id_TEMPERATURES_CELLBOARD2 0b10101000001 // dec: 1345 hex: 0x541
#define bms_id_TEMPERATURES_CELLBOARD3 0b10101100001 // dec: 1377 hex: 0x561
#define bms_id_TEMPERATURES_CELLBOARD4 0b10110000001 // dec: 1409 hex: 0x581
#define bms_id_TEMPERATURES_CELLBOARD5 0b10110100001 // dec: 1441 hex: 0x5A1

/* TOPIC VOLTAGE_INFO */
#define bms_topic_mask_VOLTAGE_INFO 0b00000011111
#define bms_topic_filter_VOLTAGE_INFO 0b00000000010 // dec: 2 hex: 0x2

#define bms_id_VOLTAGES_CELLBOARD0 0b01000000010 // dec: 514 hex: 0x202
#define bms_id_VOLTAGES_CELLBOARD1 0b01000100010 // dec: 546 hex: 0x222
#define bms_id_VOLTAGES_CELLBOARD2 0b01001000010 // dec: 578 hex: 0x242
#define bms_id_VOLTAGES_CELLBOARD3 0b01001100010 // dec: 610 hex: 0x262
#define bms_id_VOLTAGES_CELLBOARD4 0b01010000010 // dec: 642 hex: 0x282
#define bms_id_VOLTAGES_CELLBOARD5 0b01010100010 // dec: 674 hex: 0x2A2

/* TOPIC BALANCING */
#define bms_topic_mask_BALANCING 0b00000011111
#define bms_topic_filter_BALANCING 0b00000000011 // dec: 3 hex: 0x3

#define bms_id_BALANCING 0b01000000011 // dec: 515 hex: 0x203

/* TOPIC FIXED_IDS */
#define bms_topic_mask_FIXED_IDS 0b00000011111

#define bms_id_FW_UPDATE 0b00000001010 // dec: 10 hex: 0xA
#define bms_id_FLASH_CELLBOARD_0_TX 0b00000010000 // dec: 16 hex: 0x10
#define bms_id_FLASH_CELLBOARD_0_RX 0b00000010001 // dec: 17 hex: 0x11
#define bms_id_FLASH_CELLBOARD_1_TX 0b00000010010 // dec: 18 hex: 0x12
#define bms_id_FLASH_CELLBOARD_1_RX 0b00000010011 // dec: 19 hex: 0x13
#define bms_id_FLASH_CELLBOARD_2_TX 0b00000010100 // dec: 20 hex: 0x14
#define bms_id_FLASH_CELLBOARD_2_RX 0b00000010101 // dec: 21 hex: 0x15
#define bms_id_FLASH_CELLBOARD_3_TX 0b00000010110 // dec: 22 hex: 0x16
#define bms_id_FLASH_CELLBOARD_3_RX 0b00000010111 // dec: 23 hex: 0x17
#define bms_id_FLASH_CELLBOARD_4_TX 0b00000011000 // dec: 24 hex: 0x18
#define bms_id_FLASH_CELLBOARD_4_RX 0b00000011001 // dec: 25 hex: 0x19
#define bms_id_FLASH_CELLBOARD_5_TX 0b00000011010 // dec: 26 hex: 0x1A
#define bms_id_FLASH_CELLBOARD_5_RX 0b00000011011 // dec: 27 hex: 0x1B


// ============== UTILS ============== //

int bms_message_name_from_id(canlib_message_id id, char *buffer);
bool bms_is_message_id(canlib_message_id message_id);

#define bms_MAX_MESSAGE_LENGTH 24

#ifdef bms_IDS_IMPLEMENTATION

int bms_message_name_from_id(canlib_message_id id, char *buffer) {
    switch (id) {
        case bms_id_BOARD_STATUS_CELLBOARD0:
            strcpy(buffer, "BOARD_STATUS_CELLBOARD0");
            return 23;
        case bms_id_BOARD_STATUS_CELLBOARD1:
            strcpy(buffer, "BOARD_STATUS_CELLBOARD1");
            return 23;
        case bms_id_BOARD_STATUS_CELLBOARD2:
            strcpy(buffer, "BOARD_STATUS_CELLBOARD2");
            return 23;
        case bms_id_BOARD_STATUS_CELLBOARD3:
            strcpy(buffer, "BOARD_STATUS_CELLBOARD3");
            return 23;
        case bms_id_BOARD_STATUS_CELLBOARD4:
            strcpy(buffer, "BOARD_STATUS_CELLBOARD4");
            return 23;
        case bms_id_BOARD_STATUS_CELLBOARD5:
            strcpy(buffer, "BOARD_STATUS_CELLBOARD5");
            return 23;
        case bms_id_TEMPERATURES_CELLBOARD0:
            strcpy(buffer, "TEMPERATURES_CELLBOARD0");
            return 23;
        case bms_id_TEMPERATURES_CELLBOARD1:
            strcpy(buffer, "TEMPERATURES_CELLBOARD1");
            return 23;
        case bms_id_TEMPERATURES_CELLBOARD2:
            strcpy(buffer, "TEMPERATURES_CELLBOARD2");
            return 23;
        case bms_id_TEMPERATURES_CELLBOARD3:
            strcpy(buffer, "TEMPERATURES_CELLBOARD3");
            return 23;
        case bms_id_TEMPERATURES_CELLBOARD4:
            strcpy(buffer, "TEMPERATURES_CELLBOARD4");
            return 23;
        case bms_id_TEMPERATURES_CELLBOARD5:
            strcpy(buffer, "TEMPERATURES_CELLBOARD5");
            return 23;
        case bms_id_VOLTAGES_CELLBOARD0:
            strcpy(buffer, "VOLTAGES_CELLBOARD0");
            return 19;
        case bms_id_VOLTAGES_CELLBOARD1:
            strcpy(buffer, "VOLTAGES_CELLBOARD1");
            return 19;
        case bms_id_VOLTAGES_CELLBOARD2:
            strcpy(buffer, "VOLTAGES_CELLBOARD2");
            return 19;
        case bms_id_VOLTAGES_CELLBOARD3:
            strcpy(buffer, "VOLTAGES_CELLBOARD3");
            return 19;
        case bms_id_VOLTAGES_CELLBOARD4:
            strcpy(buffer, "VOLTAGES_CELLBOARD4");
            return 19;
        case bms_id_VOLTAGES_CELLBOARD5:
            strcpy(buffer, "VOLTAGES_CELLBOARD5");
            return 19;
        case bms_id_BALANCING:
            strcpy(buffer, "BALANCING");
            return 9;
        case bms_id_FW_UPDATE:
            strcpy(buffer, "FW_UPDATE");
            return 9;
        case bms_id_FLASH_CELLBOARD_0_TX:
            strcpy(buffer, "FLASH_CELLBOARD_0_TX");
            return 20;
        case bms_id_FLASH_CELLBOARD_0_RX:
            strcpy(buffer, "FLASH_CELLBOARD_0_RX");
            return 20;
        case bms_id_FLASH_CELLBOARD_1_TX:
            strcpy(buffer, "FLASH_CELLBOARD_1_TX");
            return 20;
        case bms_id_FLASH_CELLBOARD_1_RX:
            strcpy(buffer, "FLASH_CELLBOARD_1_RX");
            return 20;
        case bms_id_FLASH_CELLBOARD_2_TX:
            strcpy(buffer, "FLASH_CELLBOARD_2_TX");
            return 20;
        case bms_id_FLASH_CELLBOARD_2_RX:
            strcpy(buffer, "FLASH_CELLBOARD_2_RX");
            return 20;
        case bms_id_FLASH_CELLBOARD_3_TX:
            strcpy(buffer, "FLASH_CELLBOARD_3_TX");
            return 20;
        case bms_id_FLASH_CELLBOARD_3_RX:
            strcpy(buffer, "FLASH_CELLBOARD_3_RX");
            return 20;
        case bms_id_FLASH_CELLBOARD_4_TX:
            strcpy(buffer, "FLASH_CELLBOARD_4_TX");
            return 20;
        case bms_id_FLASH_CELLBOARD_4_RX:
            strcpy(buffer, "FLASH_CELLBOARD_4_RX");
            return 20;
        case bms_id_FLASH_CELLBOARD_5_TX:
            strcpy(buffer, "FLASH_CELLBOARD_5_TX");
            return 20;
        case bms_id_FLASH_CELLBOARD_5_RX:
            strcpy(buffer, "FLASH_CELLBOARD_5_RX");
            return 20;
        default:
            strcpy(buffer, ""); // Unknown message
    }
    return 0;
}

bool bms_is_message_id(canlib_message_id message_id) {
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

#endif // bms_IDS_IMPLEMENTATION

#ifdef __cplusplus
}
#endif

#endif // bms_IDS_H