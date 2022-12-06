#ifndef secondary_IDS_H
#define secondary_IDS_H

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

#define secondary_IDS_VERSION 1.0


/* TOPIC FIXED_IDS */
#define secondary_TOPIC_MASK_FIXED_IDS 0b00000011111

#define secondary_ID_IMU_ANGULAR_RATE 0x4EC // dec: 1260 bin: 0b10011101100
#define secondary_ID_IMU_ACCELERATION 0x4ED // dec: 1261 bin: 0b10011101101
#define secondary_ID_IRTS_FL_0 0x5B4 // dec: 1460 bin: 0b10110110100
#define secondary_ID_IRTS_FL_1 0x5B5 // dec: 1461 bin: 0b10110110101
#define secondary_ID_IRTS_FL_2 0x5B6 // dec: 1462 bin: 0b10110110110
#define secondary_ID_IRTS_FL_3 0x5B7 // dec: 1463 bin: 0b10110110111
#define secondary_ID_IRTS_FR_0 0x5B8 // dec: 1464 bin: 0b10110111000
#define secondary_ID_IRTS_FR_1 0x5B9 // dec: 1465 bin: 0b10110111001
#define secondary_ID_IRTS_FR_2 0x5BA // dec: 1466 bin: 0b10110111010
#define secondary_ID_IRTS_FR_3 0x5BB // dec: 1467 bin: 0b10110111011
#define secondary_ID_IRTS_RL_0 0x5BC // dec: 1468 bin: 0b10110111100
#define secondary_ID_IRTS_RL_1 0x5BD // dec: 1469 bin: 0b10110111101
#define secondary_ID_IRTS_RL_2 0x5BE // dec: 1470 bin: 0b10110111110
#define secondary_ID_IRTS_RL_3 0x5BF // dec: 1471 bin: 0b10110111111
#define secondary_ID_IRTS_RR_0 0x5C0 // dec: 1472 bin: 0b10111000000
#define secondary_ID_IRTS_RR_1 0x5C1 // dec: 1473 bin: 0b10111000001
#define secondary_ID_IRTS_RR_2 0x5C2 // dec: 1474 bin: 0b10111000010
#define secondary_ID_IRTS_RR_3 0x5C3 // dec: 1475 bin: 0b10111000011

/* TOPIC STEER */
#define secondary_TOPIC_MASK_STEER 0b00000011111
#define secondary_TOPIC_FILTER_STEER 0x1 // dec: 1 bin: 0b00000000001

#define secondary_ID_GPS_COORDS 0x401 // dec: 1025 bin: 0b10000000001
#define secondary_ID_GPS_SPEED 0x421 // dec: 1057 bin: 0b10000100001
#define secondary_ID_LAP_COUNT 0x441 // dec: 1089 bin: 0b10001000001
#define secondary_ID_PEDALS_OUTPUT 0x301 // dec: 769 bin: 0b01100000001
#define secondary_ID_CONTROL_OUTPUT 0x321 // dec: 801 bin: 0b01100100001
#define secondary_ID_TPMS 0x1 // dec: 1 bin: 0b00000000001

/* TOPIC TELEMETRY */
#define secondary_TOPIC_MASK_TELEMETRY 0b00000011111
#define secondary_TOPIC_FILTER_TELEMETRY 0x2 // dec: 2 bin: 0b00000000010

#define secondary_ID_STEERING_ANGLE 0x102 // dec: 258 bin: 0b00100000010


#define secondary_MAX_MESSAGE_NAME_LENGTH 17

// ============== UTILS ============== //

static inline int secondary_message_name_from_id(canlib_message_id id, char *buffer) {
    switch (id) {
        case secondary_ID_IMU_ANGULAR_RATE:
            return sprintf(buffer, "%s", "IMU_ANGULAR_RATE");;
        case secondary_ID_IMU_ACCELERATION:
            return sprintf(buffer, "%s", "IMU_ACCELERATION");;
        case secondary_ID_IRTS_FL_0:
            return sprintf(buffer, "%s", "IRTS_FL_0");;
        case secondary_ID_IRTS_FL_1:
            return sprintf(buffer, "%s", "IRTS_FL_1");;
        case secondary_ID_IRTS_FL_2:
            return sprintf(buffer, "%s", "IRTS_FL_2");;
        case secondary_ID_IRTS_FL_3:
            return sprintf(buffer, "%s", "IRTS_FL_3");;
        case secondary_ID_IRTS_FR_0:
            return sprintf(buffer, "%s", "IRTS_FR_0");;
        case secondary_ID_IRTS_FR_1:
            return sprintf(buffer, "%s", "IRTS_FR_1");;
        case secondary_ID_IRTS_FR_2:
            return sprintf(buffer, "%s", "IRTS_FR_2");;
        case secondary_ID_IRTS_FR_3:
            return sprintf(buffer, "%s", "IRTS_FR_3");;
        case secondary_ID_IRTS_RL_0:
            return sprintf(buffer, "%s", "IRTS_RL_0");;
        case secondary_ID_IRTS_RL_1:
            return sprintf(buffer, "%s", "IRTS_RL_1");;
        case secondary_ID_IRTS_RL_2:
            return sprintf(buffer, "%s", "IRTS_RL_2");;
        case secondary_ID_IRTS_RL_3:
            return sprintf(buffer, "%s", "IRTS_RL_3");;
        case secondary_ID_IRTS_RR_0:
            return sprintf(buffer, "%s", "IRTS_RR_0");;
        case secondary_ID_IRTS_RR_1:
            return sprintf(buffer, "%s", "IRTS_RR_1");;
        case secondary_ID_IRTS_RR_2:
            return sprintf(buffer, "%s", "IRTS_RR_2");;
        case secondary_ID_IRTS_RR_3:
            return sprintf(buffer, "%s", "IRTS_RR_3");;
        case secondary_ID_GPS_COORDS:
            return sprintf(buffer, "%s", "GPS_COORDS");;
        case secondary_ID_GPS_SPEED:
            return sprintf(buffer, "%s", "GPS_SPEED");;
        case secondary_ID_LAP_COUNT:
            return sprintf(buffer, "%s", "LAP_COUNT");;
        case secondary_ID_PEDALS_OUTPUT:
            return sprintf(buffer, "%s", "PEDALS_OUTPUT");;
        case secondary_ID_CONTROL_OUTPUT:
            return sprintf(buffer, "%s", "CONTROL_OUTPUT");;
        case secondary_ID_STEERING_ANGLE:
            return sprintf(buffer, "%s", "STEERING_ANGLE");;
        case secondary_ID_TPMS:
            return sprintf(buffer, "%s", "TPMS");;
        default:
            return 0; // Unknown message
    }
}

static inline bool secondary_is_message_id(canlib_message_id message_id) {
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
        case 1: return true; break;
    }
    return false;
}

#ifdef secondary_IDS_IMPLEMENTATION
#endif // secondary_IDS_IMPLEMENTATION

#ifdef __cplusplus
}
#endif

#endif // secondary_IDS_H