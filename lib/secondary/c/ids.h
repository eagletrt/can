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

#define secondary_id_IMU_ANGULAR_RATE 0b10011101100
#define secondary_id_IMU_ACCELERATION 0b10011101101
#define secondary_id_IRTS_FL_0 0b10110110100
#define secondary_id_IRTS_FL_1 0b10110110101
#define secondary_id_IRTS_FL_2 0b10110110110
#define secondary_id_IRTS_FL_3 0b10110110111
#define secondary_id_IRTS_FR_0 0b10110111000
#define secondary_id_IRTS_FR_1 0b10110111001
#define secondary_id_IRTS_FR_2 0b10110111010
#define secondary_id_IRTS_FR_3 0b10110111011
#define secondary_id_IRTS_RL_0 0b10110111100
#define secondary_id_IRTS_RL_1 0b10110111101
#define secondary_id_IRTS_RL_2 0b10110111110
#define secondary_id_IRTS_RL_3 0b10110111111
#define secondary_id_IRTS_RR_0 0b10111000000
#define secondary_id_IRTS_RR_1 0b10111000001
#define secondary_id_IRTS_RR_2 0b10111000010
#define secondary_id_IRTS_RR_3 0b10111000011

/* TOPIC STEER */
#define secondary_topic_mask_STEER 0b00000011111
#define secondary_topic_filter_STEER 0b00000000001

#define secondary_id_GPS_COORDS 0b10000000001
#define secondary_id_GPS_SPEED 0b10000100001
#define secondary_id_LAP_COUNT 0b10001000001
#define secondary_id_PEDALS_OUTPUT 0b01100000001
#define secondary_id_CONTROL_OUTPUT 0b01100100001

/* TOPIC TELEMETRY */
#define secondary_topic_mask_TELEMETRY 0b00000011111
#define secondary_topic_filter_TELEMETRY 0b00000000010

#define secondary_id_STEERING_ANGLE 0b00100000010


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