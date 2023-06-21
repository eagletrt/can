#ifndef secondary_WATCHDOG_H
#define secondary_WATCHDOG_H

#include <inttypes.h>

#ifdef __cplusplus
extern "C" {
#endif

#define SECONDARY_INTERVAL_PEDALS_OUTPUT 10
#define SECONDARY_INTERVAL_STEERING_ANGLE 10
#define SECONDARY_INTERVAL_CONTROL_STATE 100

static int secondary_watchdog_interval_from_id(uint16_t message_id) {
    switch (message_id) {
       case 770: return SECONDARY_INTERVAL_PEDALS_OUTPUT;
       case 256: return SECONDARY_INTERVAL_STEERING_ANGLE;
       case 1281: return SECONDARY_INTERVAL_CONTROL_STATE;

    }
    return -1;
}


#ifdef __cplusplus
}
#endif

#endif // secondary_NETWORK_H
