#ifndef primary_WATCHDOG_H
#define primary_WATCHDOG_H

#ifdef __cplusplus
extern "C" {
#endif

#define primary_INTERVAL_STEER_VERSION 1000
#define primary_INTERVAL_DAS_VERSION 1000
#define primary_INTERVAL_HV_VERSION 1000
#define primary_INTERVAL_LV_VERSION 1000
#define primary_INTERVAL_TLM_VERSION 1000
#define primary_INTERVAL_TIMESTAMP 1000
#define primary_INTERVAL_AMBIENT_TEMPERATURE 1000
#define primary_INTERVAL_DATA_LOGGER 1000
#define primary_INTERVAL_TLM_STATUS 1000
#define primary_INTERVAL_STEER_SYSTEM_STATUS 1000
#define primary_INTERVAL_HV_VOLTAGE 10
#define primary_INTERVAL_HV_CURRENT 10
#define primary_INTERVAL_HV_TEMP 100
#define primary_INTERVAL_HV_ERRORS 10
#define primary_INTERVAL_TS_STATUS 10
#define primary_INTERVAL_SET_TS_STATUS_DAS 100
#define primary_INTERVAL_SET_TS_STATUS_HANDCART 100
#define primary_INTERVAL_STEER_STATUS 100
#define primary_INTERVAL_CAR_STATUS 100
#define primary_INTERVAL_DAS_ERRORS 10
#define primary_INTERVAL_LV_CURRENTS 500
#define primary_INTERVAL_LV_CELLS_VOLTAGE 100
#define primary_INTERVAL_LV_TOTAL_VOLTAGE 100
#define primary_INTERVAL_LV_CELLS_TEMP 100
#define primary_INTERVAL_COOLING_STATUS 1000
#define primary_INTERVAL_SET_INVERTER_CONNECTION_STATUS 100
#define primary_INTERVAL_INVERTER_CONNECTION_STATUS 100
#define primary_INTERVAL_LV_ERRORS 10
#define primary_INTERVAL_LV_FEEDBACKS 10
#define primary_INTERVAL_SHUTDOWN_STATUS 500
#define primary_INTERVAL_HV_CELLS_VOLTAGE 100
#define primary_INTERVAL_HV_CELLS_TEMP 100
#define primary_INTERVAL_HV_CELL_BALANCING_STATUS 500
#define primary_INTERVAL_SPEED 10
#define primary_INTERVAL_INV_L_REQUEST 10
#define primary_INTERVAL_INV_R_REQUEST 10
#define primary_INTERVAL_INV_L_RESPONSE 100
#define primary_INTERVAL_INV_R_RESPONSE 100
#define primary_INTERVAL_CONTROL_OUTPUT 100
#define primary_INTERVAL_HANDCART_STATUS 500
#define primary_INTERVAL_HANDCART_SETTINGS 500
#define primary_INTERVAL_HANDCART_SETTINGS_SET 500

static int primary_watchdog_interval_from_id(uint16_t message_id) {
    switch (message_id) {
       case 1028: return primary_INTERVAL_STEER_VERSION;
       case 1060: return primary_INTERVAL_DAS_VERSION;
       case 1092: return primary_INTERVAL_HV_VERSION;
       case 1124: return primary_INTERVAL_LV_VERSION;
       case 1156: return primary_INTERVAL_TLM_VERSION;
       case 260: return primary_INTERVAL_TIMESTAMP;
       case 292: return primary_INTERVAL_AMBIENT_TEMPERATURE;
       case 1072: return primary_INTERVAL_DATA_LOGGER;
       case 258: return primary_INTERVAL_TLM_STATUS;
       case 1799: return primary_INTERVAL_STEER_SYSTEM_STATUS;
       case 769: return primary_INTERVAL_HV_VOLTAGE;
       case 801: return primary_INTERVAL_HV_CURRENT;
       case 833: return primary_INTERVAL_HV_TEMP;
       case 1: return primary_INTERVAL_HV_ERRORS;
       case 65: return primary_INTERVAL_TS_STATUS;
       case 69: return primary_INTERVAL_SET_TS_STATUS_DAS;
       case 101: return primary_INTERVAL_SET_TS_STATUS_HANDCART;
       case 264: return primary_INTERVAL_STEER_STATUS;
       case 546: return primary_INTERVAL_CAR_STATUS;
       case 2: return primary_INTERVAL_DAS_ERRORS;
       case 841: return primary_INTERVAL_LV_CURRENTS;
       case 873: return primary_INTERVAL_LV_CELLS_VOLTAGE;
       case 905: return primary_INTERVAL_LV_TOTAL_VOLTAGE;
       case 937: return primary_INTERVAL_LV_CELLS_TEMP;
       case 969: return primary_INTERVAL_COOLING_STATUS;
       case 259: return primary_INTERVAL_SET_INVERTER_CONNECTION_STATUS;
       case 265: return primary_INTERVAL_INVERTER_CONNECTION_STATUS;
       case 521: return primary_INTERVAL_LV_ERRORS;
       case 297: return primary_INTERVAL_LV_FEEDBACKS;
       case 329: return primary_INTERVAL_SHUTDOWN_STATUS;
       case 512: return primary_INTERVAL_HV_CELLS_VOLTAGE;
       case 544: return primary_INTERVAL_HV_CELLS_TEMP;
       case 576: return primary_INTERVAL_HV_CELL_BALANCING_STATUS;
       case 578: return primary_INTERVAL_SPEED;
       case 513: return primary_INTERVAL_INV_L_REQUEST;
       case 514: return primary_INTERVAL_INV_R_REQUEST;
       case 385: return primary_INTERVAL_INV_L_RESPONSE;
       case 386: return primary_INTERVAL_INV_R_RESPONSE;
       case 290: return primary_INTERVAL_CONTROL_OUTPUT;
       case 773: return primary_INTERVAL_HANDCART_STATUS;
       case 805: return primary_INTERVAL_HANDCART_SETTINGS;
       case 837: return primary_INTERVAL_HANDCART_SETTINGS_SET;

    }
    return -1;
}


#ifdef __cplusplus
}
#endif

#endif // primary_NETWORK_H
