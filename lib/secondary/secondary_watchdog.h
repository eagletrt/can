#ifndef primary_WATCHDOG_H
#define primary_WATCHDOG_H

#ifdef __cplusplus
extern "C" {
#endif

#define secondary_INTERVAL_PEDALS_OUTPUT 10
#define secondary_INTERVAL_STEERING_ANGLE 10
#define secondary_INTERVAL_CONTROL_STATE 100

static int primary_watchdog_interval_from_id(uint16_t message_id) {
    switch (message_id) {
       case 771: return secondary_INTERVAL_PEDALS_OUTPUT;
       case 256: return secondary_INTERVAL_STEERING_ANGLE;
       case 1281: return secondary_INTERVAL_CONTROL_STATE;

    }
    return -1;
}


#ifdef __cplusplus
}
#endif

#endif // primary_NETWORK_H
