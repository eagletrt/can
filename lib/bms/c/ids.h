#ifndef bms_IDS_H
#define bms_IDS_H

#include <stdint.h>
#include <string.h>

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

#define bms_MAX_MESSAGE_LENGTH 24

#ifdef bms_IDS_IMPLEMENTATION

int bms_message_name_from_id(uint16_t id, char *buffer) {
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

#endif // bms_IDS_IMPLEMENTATION

#endif // bms_IDS_H