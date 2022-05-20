#ifndef secondary_UTILS_H
#define secondary_UTILS_H

#define secondary_MAX_MESSAGE_LENGTH 17

void secondary_message_name_from_id(uint16_t id, char *buffer) {
    switch (id) {
        case 1260: strcpy(buffer, "IMU_ANGULAR_RATE"); break;
        case 1261: strcpy(buffer, "IMU_ACCELERATION"); break;
        case 1460: strcpy(buffer, "IRTS_FL_0"); break;
        case 1461: strcpy(buffer, "IRTS_FL_1"); break;
        case 1462: strcpy(buffer, "IRTS_FL_2"); break;
        case 1463: strcpy(buffer, "IRTS_FL_3"); break;
        case 1464: strcpy(buffer, "IRTS_FR_0"); break;
        case 1465: strcpy(buffer, "IRTS_FR_1"); break;
        case 1466: strcpy(buffer, "IRTS_FR_2"); break;
        case 1467: strcpy(buffer, "IRTS_FR_3"); break;
        case 1468: strcpy(buffer, "IRTS_RL_0"); break;
        case 1469: strcpy(buffer, "IRTS_RL_1"); break;
        case 1470: strcpy(buffer, "IRTS_RL_2"); break;
        case 1471: strcpy(buffer, "IRTS_RL_3"); break;
        case 1472: strcpy(buffer, "IRTS_RR_0"); break;
        case 1473: strcpy(buffer, "IRTS_RR_1"); break;
        case 1474: strcpy(buffer, "IRTS_RR_2"); break;
        case 1475: strcpy(buffer, "IRTS_RR_3"); break;
        case 1025: strcpy(buffer, "GPS_COORDS"); break;
        case 1057: strcpy(buffer, "GPS_SPEED"); break;
        case 1089: strcpy(buffer, "LAP_COUNT"); break;
        default: strcpy(buffer, ""); // Unknown message
    }
}

#endif // secondary_UTILS_H