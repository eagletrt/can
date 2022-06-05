#ifndef bms_IDS_H
#define bms_IDS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <string.h>

#ifndef CANLIB_MESSAGE_ID_TYPE
#define CANLIB_MESSAGE_ID_TYPE
typedef uint16_t canlib_message_id;
#endif // CANLIB_MESSAGE_ID_TYPE

#define bms_IDS_VERSION 1.2


/* TOPIC STATUS */
#define bms_topic_mask_STATUS 0b00000011111
#define bms_topic_filter_STATUS 0b00000000000

#define bms_id_BOARD_STATUS_CELLBOARD0 0b11000000000
#define bms_id_BOARD_STATUS_CELLBOARD1 0b11000100000
#define bms_id_BOARD_STATUS_CELLBOARD2 0b11001000000
#define bms_id_BOARD_STATUS_CELLBOARD3 0b11001100000
#define bms_id_BOARD_STATUS_CELLBOARD4 0b11010000000
#define bms_id_BOARD_STATUS_CELLBOARD5 0b11010100000

/* TOPIC TEMPERATURE_INFO */
#define bms_topic_mask_TEMPERATURE_INFO 0b00000011111
#define bms_topic_filter_TEMPERATURE_INFO 0b00000000001

#define bms_id_TEMPERATURES_CELLBOARD0 0b10100000001
#define bms_id_TEMPERATURES_CELLBOARD1 0b10100100001
#define bms_id_TEMPERATURES_CELLBOARD2 0b10101000001
#define bms_id_TEMPERATURES_CELLBOARD3 0b10101100001
#define bms_id_TEMPERATURES_CELLBOARD4 0b10110000001
#define bms_id_TEMPERATURES_CELLBOARD5 0b10110100001

/* TOPIC VOLTAGE_INFO */
#define bms_topic_mask_VOLTAGE_INFO 0b00000011111
#define bms_topic_filter_VOLTAGE_INFO 0b00000000010

#define bms_id_VOLTAGES_CELLBOARD0 0b01000000010
#define bms_id_VOLTAGES_CELLBOARD1 0b01000100010
#define bms_id_VOLTAGES_CELLBOARD2 0b01001000010
#define bms_id_VOLTAGES_CELLBOARD3 0b01001100010
#define bms_id_VOLTAGES_CELLBOARD4 0b01010000010
#define bms_id_VOLTAGES_CELLBOARD5 0b01010100010

/* TOPIC BALANCING */
#define bms_topic_mask_BALANCING 0b00000011111
#define bms_topic_filter_BALANCING 0b00000000011

#define bms_id_BALANCING 0b01000000011

/* TOPIC FW_UPDATE */
#define bms_topic_mask_FW_UPDATE 0b00000011111
#define bms_topic_filter_FW_UPDATE 0b00000000100

#define bms_id_FW_UPDATE 0b00100000100


// ============== UTILS ============== //

int bms_message_name_from_id(canlib_message_id id, char *buffer);
bool bms_is_message_id(canlib_message_id message_id);

#define bms_MAX_MESSAGE_LENGTH 24

#ifdef bms_IDS_IMPLEMENTATION

int bms_message_name_from_id(canlib_message_id id, char *buffer) {
    switch (id) {
        case bms_id_BOARD_STATUS_CELLBOARD0:
            strcpy(buffer, "BOARD_STATUS_CELLBOARD0");
            return 0;
        case bms_id_BOARD_STATUS_CELLBOARD1:
            strcpy(buffer, "BOARD_STATUS_CELLBOARD1");
            return 0;
        case bms_id_BOARD_STATUS_CELLBOARD2:
            strcpy(buffer, "BOARD_STATUS_CELLBOARD2");
            return 0;
        case bms_id_BOARD_STATUS_CELLBOARD3:
            strcpy(buffer, "BOARD_STATUS_CELLBOARD3");
            return 0;
        case bms_id_BOARD_STATUS_CELLBOARD4:
            strcpy(buffer, "BOARD_STATUS_CELLBOARD4");
            return 0;
        case bms_id_BOARD_STATUS_CELLBOARD5:
            strcpy(buffer, "BOARD_STATUS_CELLBOARD5");
            return 0;
        case bms_id_TEMPERATURES_CELLBOARD0:
            strcpy(buffer, "TEMPERATURES_CELLBOARD0");
            return 0;
        case bms_id_TEMPERATURES_CELLBOARD1:
            strcpy(buffer, "TEMPERATURES_CELLBOARD1");
            return 0;
        case bms_id_TEMPERATURES_CELLBOARD2:
            strcpy(buffer, "TEMPERATURES_CELLBOARD2");
            return 0;
        case bms_id_TEMPERATURES_CELLBOARD3:
            strcpy(buffer, "TEMPERATURES_CELLBOARD3");
            return 0;
        case bms_id_TEMPERATURES_CELLBOARD4:
            strcpy(buffer, "TEMPERATURES_CELLBOARD4");
            return 0;
        case bms_id_TEMPERATURES_CELLBOARD5:
            strcpy(buffer, "TEMPERATURES_CELLBOARD5");
            return 0;
        case bms_id_VOLTAGES_CELLBOARD0:
            strcpy(buffer, "VOLTAGES_CELLBOARD0");
            return 0;
        case bms_id_VOLTAGES_CELLBOARD1:
            strcpy(buffer, "VOLTAGES_CELLBOARD1");
            return 0;
        case bms_id_VOLTAGES_CELLBOARD2:
            strcpy(buffer, "VOLTAGES_CELLBOARD2");
            return 0;
        case bms_id_VOLTAGES_CELLBOARD3:
            strcpy(buffer, "VOLTAGES_CELLBOARD3");
            return 0;
        case bms_id_VOLTAGES_CELLBOARD4:
            strcpy(buffer, "VOLTAGES_CELLBOARD4");
            return 0;
        case bms_id_VOLTAGES_CELLBOARD5:
            strcpy(buffer, "VOLTAGES_CELLBOARD5");
            return 0;
        case bms_id_BALANCING:
            strcpy(buffer, "BALANCING");
            return 0;
        case bms_id_FW_UPDATE:
            strcpy(buffer, "FW_UPDATE");
            return 0;
        default:
            strcpy(buffer, ""); // Unknown message
    }
    return 1;
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
        case 260: return true; break;
    }
    return false;
}

#endif // bms_IDS_IMPLEMENTATION

#ifdef __cplusplus
}
#endif

#endif // bms_IDS_H