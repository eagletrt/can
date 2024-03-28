# E-Agle TRT CAN-bus messages standard

This is the complete list of all the devices in the car: `HV, LV, ECU, STEERING_WHEEL, TLM, ACQUISINATOR, HANDCART, INVERTER_L, INVERTER_R, IMU, IRTS_FL, IRTS_FR, IRTS_RR, IRTS_RL, ANY`. 

`STEERING_WHEEL` and `TLM` are considered always receiving all messages and so they are omitted in the `receving` field of the message definitions.

Each device in the car must have a version message and related messages for openblt and a message related to the status of the internal FSM (Finite State Machine). The name of the message must be formed like this: `DEVICE_[SET_]CONTENT`, e.g. `HV_BALANCING_STATUS, HV_SET_BALANCING_STATUS`.

As for the sensors, they must be divided by logical sector.  
The percentages range from 0 to 1, and not from 0 to 100.  
The units of measurement are specified in the message field type if necessary and then reported in the CSV.

```
Concept:
DEVICE_QUANTITY_OTHERS
DEVICE_QUANTITY_SPECIFICATIONS
```

## Rules

### Priorities assignement
**Mind that lower value means higher priority.**
- 0: critical messages and SET car states
- 1: car states
- 2: SET non critical messages
- 3: non critical messages and info

Example:

| Message | Priority | 
| -- | -- |
| ECU_SET_STATUS | 0 | 
| ECU_STATUS | 1 | 
| ECU_SET_PTT_STATUS | 2 | 
| ECU_PTT_STATUS | 3 | 

### Intervals assignment:
- 10ms      (100 Hz): sensors
- 20ms      (50 Hz) : states
- 50ms      (20 Hz) : currents / temps / feedbacks
- 200ms     (5 Hz)  : cooling status, non critical states in general
- 1000ms    (1 Hz)  : versions
