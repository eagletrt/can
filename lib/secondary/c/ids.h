#ifndef secondary_IDS_H
#define secondary_IDS_H

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

#define secondary_IDS_VERSION 1.0


/* TOPIC FIXED_IDS */
#define secondary_topic_mask_FIXED_IDS 0b00000011111

#define secondary_id_IMU_ANGULAR_RATE 0b10011101100 // dec: 1260 hex: 0x4EC
#define secondary_id_IMU_ACCELERATION 0b10011101101 // dec: 1261 hex: 0x4ED
#define secondary_id_IRTS_FL_0 0b10110110100 // dec: 1460 hex: 0x5B4
#define secondary_id_IRTS_FL_1 0b10110110101 // dec: 1461 hex: 0x5B5
#define secondary_id_IRTS_FL_2 0b10110110110 // dec: 1462 hex: 0x5B6
#define secondary_id_IRTS_FL_3 0b10110110111 // dec: 1463 hex: 0x5B7
#define secondary_id_IRTS_FR_0 0b10110111000 // dec: 1464 hex: 0x5B8
#define secondary_id_IRTS_FR_1 0b10110111001 // dec: 1465 hex: 0x5B9
#define secondary_id_IRTS_FR_2 0b10110111010 // dec: 1466 hex: 0x5BA
#define secondary_id_IRTS_FR_3 0b10110111011 // dec: 1467 hex: 0x5BB
#define secondary_id_IRTS_RL_0 0b10110111100 // dec: 1468 hex: 0x5BC
#define secondary_id_IRTS_RL_1 0b10110111101 // dec: 1469 hex: 0x5BD
#define secondary_id_IRTS_RL_2 0b10110111110 // dec: 1470 hex: 0x5BE
#define secondary_id_IRTS_RL_3 0b10110111111 // dec: 1471 hex: 0x5BF
#define secondary_id_IRTS_RR_0 0b10111000000 // dec: 1472 hex: 0x5C0
#define secondary_id_IRTS_RR_1 0b10111000001 // dec: 1473 hex: 0x5C1
#define secondary_id_IRTS_RR_2 0b10111000010 // dec: 1474 hex: 0x5C2
#define secondary_id_IRTS_RR_3 0b10111000011 // dec: 1475 hex: 0x5C3

/* TOPIC STEER */
#define secondary_topic_mask_STEER 0b00000011111
#define secondary_topic_filter_STEER 0b00000000001 // dec: 1 hex: 0x1

#define secondary_id_GPS_COORDS 0b10000000001 // dec: 1025 hex: 0x401
#define secondary_id_GPS_SPEED 0b10000100001 // dec: 1057 hex: 0x421
#define secondary_id_LAP_COUNT 0b10001000001 // dec: 1089 hex: 0x441
#define secondary_id_PEDALS_OUTPUT 0b01100000001 // dec: 769 hex: 0x301
#define secondary_id_CONTROL_OUTPUT 0b01100100001 // dec: 801 hex: 0x321

/* TOPIC TELEMETRY */
#define secondary_topic_mask_TELEMETRY 0b00000011111
#define secondary_topic_filter_TELEMETRY 0b00000000010 // dec: 2 hex: 0x2

#define secondary_id_STEERING_ANGLE 0b00100000010 // dec: 258 hex: 0x102


// ============== UTILS ============== //

int secondary_message_name_from_id(canlib_message_id id, char *buffer);
bool secondary_is_message_id(canlib_message_id message_id);

#define secondary_MAX_MESSAGE_LENGTH 17

#ifdef secondary_IDS_IMPLEMENTATION

int secondary_message_name_from_id(canlib_message_id id, char *buffer) {
    switch (id) {
        case secondary_id_IMU_ANGULAR_RATE:
            strcpy(buffer, "IMU_ANGULAR_RATE");
            return 0;
        case secondary_id_IMU_ACCELERATION:
            strcpy(buffer, "IMU_ACCELERATION");
            return 0;
        case secondary_id_IRTS_FL_0:
            strcpy(buffer, "IRTS_FL_0");
            return 0;
        case secondary_id_IRTS_FL_1:
            strcpy(buffer, "IRTS_FL_1");
            return 0;
        case secondary_id_IRTS_FL_2:
            strcpy(buffer, "IRTS_FL_2");
            return 0;
        case secondary_id_IRTS_FL_3:
            strcpy(buffer, "IRTS_FL_3");
            return 0;
        case secondary_id_IRTS_FR_0:
            strcpy(buffer, "IRTS_FR_0");
            return 0;
        case secondary_id_IRTS_FR_1:
            strcpy(buffer, "IRTS_FR_1");
            return 0;
        case secondary_id_IRTS_FR_2:
            strcpy(buffer, "IRTS_FR_2");
            return 0;
        case secondary_id_IRTS_FR_3:
            strcpy(buffer, "IRTS_FR_3");
            return 0;
        case secondary_id_IRTS_RL_0:
            strcpy(buffer, "IRTS_RL_0");
            return 0;
        case secondary_id_IRTS_RL_1:
            strcpy(buffer, "IRTS_RL_1");
            return 0;
        case secondary_id_IRTS_RL_2:
            strcpy(buffer, "IRTS_RL_2");
            return 0;
        case secondary_id_IRTS_RL_3:
            strcpy(buffer, "IRTS_RL_3");
            return 0;
        case secondary_id_IRTS_RR_0:
            strcpy(buffer, "IRTS_RR_0");
            return 0;
        case secondary_id_IRTS_RR_1:
            strcpy(buffer, "IRTS_RR_1");
            return 0;
        case secondary_id_IRTS_RR_2:
            strcpy(buffer, "IRTS_RR_2");
            return 0;
        case secondary_id_IRTS_RR_3:
            strcpy(buffer, "IRTS_RR_3");
            return 0;
        case secondary_id_GPS_COORDS:
            strcpy(buffer, "GPS_COORDS");
            return 0;
        case secondary_id_GPS_SPEED:
            strcpy(buffer, "GPS_SPEED");
            return 0;
        case secondary_id_LAP_COUNT:
            strcpy(buffer, "LAP_COUNT");
            return 0;
        case secondary_id_PEDALS_OUTPUT:
            strcpy(buffer, "PEDALS_OUTPUT");
            return 0;
        case secondary_id_CONTROL_OUTPUT:
            strcpy(buffer, "CONTROL_OUTPUT");
            return 0;
        case secondary_id_STEERING_ANGLE:
            strcpy(buffer, "STEERING_ANGLE");
            return 0;
        default:
            strcpy(buffer, ""); // Unknown message
    }
    return 1;
}

bool secondary_is_message_id(canlib_message_id message_id) {
    switch (message_id) {
        case 1260: return true; break;
        case 1261: return true; break;
        case 1460: return true; break;
        case 1461: return true; break;
        case 1462: return true; break;
        case 1463: return true; break;
        case 1464: return true; break;
        case 1465: return true; break;
        case 1466: return true; break;
        case 1467: return true; break;
        case 1468: return true; break;
        case 1469: return true; break;
        case 1470: return true; break;
        case 1471: return true; break;
        case 1472: return true; break;
        case 1473: return true; break;
        case 1474: return true; break;
        case 1475: return true; break;
        case 1025: return true; break;
        case 1057: return true; break;
        case 1089: return true; break;
        case 769: return true; break;
        case 801: return true; break;
        case 258: return true; break;
    }
    return false;
}

#endif // secondary_IDS_IMPLEMENTATION

#ifdef __cplusplus
}
#endif

#endif // secondary_IDS_H