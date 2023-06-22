#ifndef primary_WATCHDOG_H
#define primary_WATCHDOG_H

#include <inttypes.h>

#ifdef __cplusplus
extern "C" {
#endif

#define PRIMARY_INTERVAL_STEER_VERSION 1000
#define PRIMARY_INTERVAL_DAS_VERSION 1000
#define PRIMARY_INTERVAL_HV_VERSION 1000
#define PRIMARY_INTERVAL_LV_VERSION 1000
#define PRIMARY_INTERVAL_TLM_VERSION 1000
#define PRIMARY_INTERVAL_TIMESTAMP 1000
#define PRIMARY_INTERVAL_AMBIENT_TEMPERATURE 1000
#define PRIMARY_INTERVAL_DATA_LOGGER 1000
#define PRIMARY_INTERVAL_TLM_STATUS 1000
#define PRIMARY_INTERVAL_STEER_SYSTEM_STATUS 1000
#define PRIMARY_INTERVAL_HV_VOLTAGE 10
#define PRIMARY_INTERVAL_HV_CURRENT 10
#define PRIMARY_INTERVAL_HV_TEMP 100
#define PRIMARY_INTERVAL_HV_ERRORS 10
#define PRIMARY_INTERVAL_TS_STATUS 10
#define PRIMARY_INTERVAL_SET_TS_STATUS_DAS 100
#define PRIMARY_INTERVAL_SET_TS_STATUS_HANDCART 100
#define PRIMARY_INTERVAL_STEER_STATUS 100
#define PRIMARY_INTERVAL_CAR_STATUS 100
#define PRIMARY_INTERVAL_DAS_ERRORS 10
#define PRIMARY_INTERVAL_LV_CURRENTS 500
#define PRIMARY_INTERVAL_LV_CELLS_VOLTAGE 100
#define PRIMARY_INTERVAL_LV_TOTAL_VOLTAGE 100
#define PRIMARY_INTERVAL_LV_CELLS_TEMP 100
#define PRIMARY_INTERVAL_COOLING_STATUS 1000
#define PRIMARY_INTERVAL_SET_INVERTER_CONNECTION_STATUS 100
#define PRIMARY_INTERVAL_INVERTER_CONNECTION_STATUS 100
#define PRIMARY_INTERVAL_LV_ERRORS 10
#define PRIMARY_INTERVAL_LV_HEALTH_SIGNALS 300
#define PRIMARY_INTERVAL_LV_FEEDBACKS 10
#define PRIMARY_INTERVAL_SHUTDOWN_STATUS 500
#define PRIMARY_INTERVAL_LV_CAN_FLASH_ACK 50
#define PRIMARY_INTERVAL_HV_CELLS_VOLTAGE 100
#define PRIMARY_INTERVAL_HV_CELLS_TEMP 100
#define PRIMARY_INTERVAL_HV_CELL_BALANCING_STATUS 500
#define PRIMARY_INTERVAL_SPEED 10
#define PRIMARY_INTERVAL_INV_L_REQUEST 10
#define PRIMARY_INTERVAL_INV_R_REQUEST 10
#define PRIMARY_INTERVAL_INV_L_RESPONSE 100
#define PRIMARY_INTERVAL_INV_R_RESPONSE 100
#define PRIMARY_INTERVAL_CONTROL_OUTPUT 100
#define PRIMARY_INTERVAL_HANDCART_STATUS 500
#define PRIMARY_INTERVAL_HANDCART_SETTINGS 500
#define PRIMARY_INTERVAL_HANDCART_SETTINGS_SET 500

static int primary_watchdog_interval_from_id(uint16_t message_id) {
    switch (message_id) {
       case 1032: return PRIMARY_INTERVAL_STEER_VERSION;
       case 1064: return PRIMARY_INTERVAL_DAS_VERSION;
       case 1096: return PRIMARY_INTERVAL_HV_VERSION;
       case 1128: return PRIMARY_INTERVAL_LV_VERSION;
       case 1160: return PRIMARY_INTERVAL_TLM_VERSION;
       case 264: return PRIMARY_INTERVAL_TIMESTAMP;
       case 296: return PRIMARY_INTERVAL_AMBIENT_TEMPERATURE;
       case 1072: return PRIMARY_INTERVAL_DATA_LOGGER;
       case 256: return PRIMARY_INTERVAL_TLM_STATUS;
       case 1794: return PRIMARY_INTERVAL_STEER_SYSTEM_STATUS;
       case 769: return PRIMARY_INTERVAL_HV_VOLTAGE;
       case 801: return PRIMARY_INTERVAL_HV_CURRENT;
       case 833: return PRIMARY_INTERVAL_HV_TEMP;
       case 33: return PRIMARY_INTERVAL_HV_ERRORS;
       case 65: return PRIMARY_INTERVAL_TS_STATUS;
       case 69: return PRIMARY_INTERVAL_SET_TS_STATUS_DAS;
       case 101: return PRIMARY_INTERVAL_SET_TS_STATUS_HANDCART;
       case 260: return PRIMARY_INTERVAL_STEER_STATUS;
       case 512: return PRIMARY_INTERVAL_CAR_STATUS;
       case 32: return PRIMARY_INTERVAL_DAS_ERRORS;
       case 835: return PRIMARY_INTERVAL_LV_CURRENTS;
       case 867: return PRIMARY_INTERVAL_LV_CELLS_VOLTAGE;
       case 899: return PRIMARY_INTERVAL_LV_TOTAL_VOLTAGE;
       case 931: return PRIMARY_INTERVAL_LV_CELLS_TEMP;
       case 963: return PRIMARY_INTERVAL_COOLING_STATUS;
       case 263: return PRIMARY_INTERVAL_SET_INVERTER_CONNECTION_STATUS;
       case 259: return PRIMARY_INTERVAL_INVERTER_CONNECTION_STATUS;
       case 515: return PRIMARY_INTERVAL_LV_ERRORS;
       case 291: return PRIMARY_INTERVAL_LV_HEALTH_SIGNALS;
       case 323: return PRIMARY_INTERVAL_LV_FEEDBACKS;
       case 355: return PRIMARY_INTERVAL_SHUTDOWN_STATUS;
       case 1858: return PRIMARY_INTERVAL_LV_CAN_FLASH_ACK;
       case 518: return PRIMARY_INTERVAL_HV_CELLS_VOLTAGE;
       case 550: return PRIMARY_INTERVAL_HV_CELLS_TEMP;
       case 582: return PRIMARY_INTERVAL_HV_CELL_BALANCING_STATUS;
       case 544: return PRIMARY_INTERVAL_SPEED;
       case 513: return PRIMARY_INTERVAL_INV_L_REQUEST;
       case 514: return PRIMARY_INTERVAL_INV_R_REQUEST;
       case 385: return PRIMARY_INTERVAL_INV_L_RESPONSE;
       case 386: return PRIMARY_INTERVAL_INV_R_RESPONSE;
       case 288: return PRIMARY_INTERVAL_CONTROL_OUTPUT;
       case 773: return PRIMARY_INTERVAL_HANDCART_STATUS;
       case 805: return PRIMARY_INTERVAL_HANDCART_SETTINGS;
       case 837: return PRIMARY_INTERVAL_HANDCART_SETTINGS_SET;

    }
    return -1;
}


#ifdef __cplusplus
}
#endif

#endif // primary_NETWORK_H
