'''

TODO: generatore invertire le priorita', abbassare priorita' INV_R_REQUEST e INV_L_RESPONSE

GESTIONE PRIORITA'
0: messaggi critici e set stati della macchina
1: stati della macchina
2: set non critici
3: non critici

Interval:
10      (100 Hz)    - SENSORI
20      (50 Hz)     - Stati
50      (20 Hz)     - Currents / Temps / Feedback
200     (5 Hz)      - COOLING status, stati non critici in generale
1000    (1 Hz)      - VERSIONI ecc...

Categories:

- HV, hv
- LV, lv
- ECU, ecu & controls
- TLM, telemetry
- STEERING_WHEEL, steering wheel
- HANDCART, handcart
- sensors

Each device in the car must have a version message and related messages for openblt and a message related to the status of the internal fms. The name of the message must be formed like this: DEVICE_[SET_]CONTENT, e.g. HV_SET_BALANCING_STATUS.

As for the sensors, they must be divided by logical sector. The percentages range from 0 to 1, and not from 0 to 100.

The units of measurement are specified in the message field type if necessary and then reported in the csv.
#####
# Concept:
# DEVICE_QUANTITY_OTHERS
# DEVICE_QUANTITY_SPECIFICATIONS
#####

Devices:
HV, LV, ECU, STEERING_WHEEL, TLM, ACQUISINATORE

Tuttavia TLM e STEERING_WHEEL ascoltano sempre tutto

HV, LV, ECU, ACQUISINATORE, HANDCART, INVERTER_L, INVERTER_R

'''


# ++++++++++++++++++++++++++++
# OPENBLT
# ++++++++++++++++++++++++++++

HV_JMP_TO_BLT, content = []
HV_FLASH_MAINBOARD_TX, content = []
HV_FLASH_MAINBOARD_RX, content = []
HV_FLASH_CELLBOARD_0_TX, content = []
HV_FLASH_CELLBOARD_0_RX, content = []
HV_FLASH_CELLBOARD_1_TX, content = []
HV_FLASH_CELLBOARD_1_RX, content = []
HV_FLASH_CELLBOARD_2_TX, content = []
HV_FLASH_CELLBOARD_2_RX, content = []
HV_FLASH_CELLBOARD_3_TX, content = []
HV_FLASH_CELLBOARD_3_RX, content = []
HV_FLASH_CELLBOARD_4_TX, content = []
HV_FLASH_CELLBOARD_4_RX, content = []
HV_FLASH_CELLBOARD_5_TX, content = []
HV_FLASH_CELLBOARD_5_RX, content = []
LV_JMP_TO_BLT, content = []
LV_FLASH_BMS_TX, content = []
LV_FLASH_BMS_RX, content = []
ECU_JMP_TO_BLT, content = []
ECU_FLASH_TX, content = []
ECU_FLASH_RX, content = []
STEERING_WHEEL_JMP_TO_BLT, content = []
STEERING_WHEEL_FLASH_TX, content = []
STEERING_WHEEL_FLASH_RX, content = []

# ++++++++++++++++++++++++++++
# VERSIONS
# ++++++++++++++++++++++++++++

STEERING_WHEEL_VERSION, content = ['component_build_time', 'canlib_build_time']
ECU_VERSION, content = ['component_build_time', 'canlib_build_time']
LV_VERSION, content = ['component_build_time', 'canlib_build_time']
TLM_VERSION, content = ['component_build_time', 'canlib_build_time']
HV_MAINBOARD_VERSION, content = ['component_build_time', 'canlib_build_time']
HV_CELLBOARD_0_VERSION, content = ['component_build_time', 'canlib_build_time']
HV_CELLBOARD_1_VERSION, content = ['component_build_time', 'canlib_build_time']
HV_CELLBOARD_2_VERSION, content = ['component_build_time', 'canlib_build_time']
HV_CELLBOARD_3_VERSION, content = ['component_build_time', 'canlib_build_time']
HV_CELLBOARD_4_VERSION, content = ['component_build_time', 'canlib_build_time']
HV_CELLBOARD_5_VERSION, content = ['component_build_time', 'canlib_build_time']

# ++++++++++++++++++++++++++++
# MAINBOARD
# ++++++++++++++++++++++++++++

HV_ERRORS, content = ['errors']
HV_DEBUG_SIGNALS, content = ['debug_signals']
HV_FANS_OVERRIDE, content = ['fans_override', 'fans_speed']
HV_FANS_OVERRIDE_STATUS, content = ['fans_override', 'fans_speed']

# per gli HV_FEEDBACK tonino dice di tenere questi qua per intanto che dopo quando c'e' il porco nuovo vanno cambiati in ogni caso
# tenere come standard che i valori dello shutdown vanno messi al valore scelto
HV_FEEDBACK_STATUS, content = ['implausibility_detected', 'imd_cockpit', 'tsal_green_fault_latched', 'bms_cockpit', 'ext_latched', 'tsal_green', 'ts_over_60v_status', 'airn_status', 'airp_status', 'airp_gate', 'airn_gate', 'precharge_status', 'tsp_over_60v_status', 'imd_fault', 'check_mux', 'sd_end', 'sd_out', 'sd_in', 'sd_bms', 'sd_imd']
HV_FEEDBACK_TS_VOLTAGE, content = ['ts_over_60v_status', 'airn_status', 'airp_status', 'airp_gate', 'airn_gate', 'precharge_status', 'tsp_over_60v_status']
HV_FEEDBACK_MISC_VOLTAGE, content = ['implausibility_detected', 'imd_cockpit', 'tsal_green_fault_latched', 'bms_cockpit', 'ext_latched', 'tsal_green', 'imd_fault', 'check_mux']
HV_FEEDBACK_SD_VOLTAGE, content = ['sd_end', 'sd_out', 'sd_in', 'sd_bms', 'sd_imd']
HV_IMD_STATUS, content = ['imd_fault', 'imd_status', 'imd_details', 'imd_duty_cycle', 'imd_freq', 'imd_period']

HV_STATUS, content = ['hv_status']
HV_SET_STATUS_ECU, content = ['hv_status_set']
HV_SET_STATUS_HANDCART, content = ['hv_status_set']
HV_BALANCING_STATUS, content = ['cellboard_id', 'balancing_status', 'errors', 'balancing_cells']
HV_SET_BALANCING_STATUS, content = ['set_balancing_status', 'balancing_threshold']

# ++++++++++++++++++++++++++++
# LV
# ++++++++++++++++++++++++++++

LV_STATUS, content = ['status']
LV_RADIATOR_SPEED, content = ['radiators_speed'] # al posto di COOLING_STATUS
LV_PUMPS_SPEED, content = ['pumps_speed'] # al posto di COOLING_STATUS
LV_SET_RADIATOR_SPEED, content = ['radiators_speed']
LV_SET_PUMPS_SPEED, content = ['pumps_speed']
LV_ERRORS, content = ['errors']
LV_HEALTH_SIGNALS, content = ['lv_health_signal_status']
# i feedback li ho riscritti io in base anche a come li vuole aris
LV_FEEDBACK_TS_VOLTAGE, content = ['bspd', 'imd', 'hvd', 'ams']
LV_FEEDBACK_SD_VOLTAGE, content = ['sd_end', 'lvms', 'interlock', 'sd_start']
LV_FEEDBACK_ECLOSURE_VOLTAGE, content = ['lv_encl', 'hv_encl_1', 'hv_encl_2', 'backplate']
LV_FEEDBACK_GPIO_EXTENDER, content = ['inverters', 'pcbs', 'pumps', 'radiators', 'shutdown', 'hv_fans', 'autonomous_system_actuation']
LV_CAN_FLASH_REQ, content = []
LV_CAN_FLASH_ACK, content = ['response']
LV_SET_INVERTER_CONNECTION_STATUS, content = ['status']
LV_INVERTER_CONNECTION_STATUS, content = ['status']

# ++++++++++++++++++++++++++++
# TELEMETRY
# ++++++++++++++++++++++++++++

TLM_SET_STATUS, content = ['tlm_status']
TLM_STATUS, content = ['tlm_status']
TLM_UNIX_TIMESTAMP, content = ['timestamp']
# TODO: cambiare questi due valori qua con qualcosa di piu' comprensibile
TLM_LAP_TIME, content = ['lap_count', 'lap_time']
TLM_LAPS_STATS, content = ['lap_number', 'best_time', 'last_time']

# ++++++++++++++++++++++++++++
# HANDCART
# ++++++++++++++++++++++++++++

HANDCART_STATUS, content = ['connected']
HANDCART_SETTINGS, content = ['target_voltage', 'fans_override', 'fans_speed', 'acc_charge_current', 'grid_max_current', 'status']
HANDCART_SET_SETTINGS, content = ['target_voltage', 'fans_override', 'fans_speed', 'acc_charge_current', 'grid_max_current', 'status']

# ++++++++++++++++++++++++++++
# ECU & CONTROLS
# ++++++++++++++++++++++++++++

ECU_STATUS, content = ['car_status']
ECU_SET_STATUS, content = ['car_status_set']
ECU_INVERTER_STATUS, content = ['inverter_l', 'inverter_r']
ECU_CONTROL_STATUS, content = ['control_state']
ECU_ERRORS, content = ['das_error']
ECU_FEEDBACKS, content = ['ecu_feedbacks']
ECU_POWER_MAPS, content = ['map_pw', 'map_sc', 'map_tv']
ECU_SET_POWER_MAPS, content = ['map_pw', 'map_sc', 'map_tv']

ECU_SET_PTT_STATUS, content = ['status']
ECU_PTT_STATUS, content = ['status']

ECU_REGEN_MANUAL_COMMAND, content = ['status', 'target']

ECU_INV_L_REQUEST, content = ['data_0', 'data_1', 'data_2', 'data_3', 'data_4', 'data_5', 'data_6', 'data_7']
ECU_INV_R_REQUEST, content = ['data_0', 'data_1', 'data_2', 'data_3', 'data_4', 'data_5', 'data_6', 'data_7']
ECU_INV_L_RESPONSE, content = ['reg_id', 'data_0', 'data_1', 'data_2', 'data_3', 'data_4', 'data_5', 'data_6']
ECU_INV_R_RESPONSE, content = ['reg_id', 'data_0', 'data_1', 'data_2', 'data_3', 'data_4', 'data_5', 'data_6']

# ++++++++++++++++++++++++++++
# SENSORS
# ++++++++++++++++++++++++++++

LV_CURRENT_BATTERY, content = ['lv_battery']
LV_CURRENT_CHARGER, content = ['charger']

LV_TOTAL_VOLTAGE, content = ['total']
LV_CELLS_VOLTAGE, content = ['start_index', 'voltage_0', 'voltage_1', 'voltage_2']
LV_CELLS_VOLTAGE_STATS, content = ['max', 'min', 'delta', 'avg']

LV_CELLS_TEMP, content = ['start_index', 'temp_0', 'temp_1', 'temp_2']
LV_CELLS_TEMP_STATS, content = ['max', 'min', 'avg']

HV_CURRENT, content = ['current']
HV_POWER, content = ['power']
HV_ENERGY,  content = ['energy']
HV_SOC, content = ['soc']

HV_TOTAL_VOLTAGE, content = ['pack', 'sum_cell', 'bus'] # da HV_VOLTAGE, content = ['pack_voltage', 'bus_voltage']
HV_CELLS_VOLTAGE, content = ['start_index', 'voltage_0', 'voltage_1', 'voltage_2'] # da HV_CELLS_VOLTAGE, content = ['start_index', 'voltage_0', 'voltage_1', 'voltage_2']
HV_CELLS_VOLTAGE_STATS, content = ['max', 'min', 'delta', 'avg']

HV_CELLS_TEMP, content = ['start_index', 'temp_0', 'temp_1', 'temp_2', 'temp_3']
HV_CELLS_TEMP_STATS, content = ['max', 'min', 'avg']

SPEED, content = ["fl", "fr"]
STEER_ANGLE, content = ['angle']
COOLING_TEMP, content = ['top_left', 'bottom_left', 'top_right', 'bottom_right']
AMMO_COMPRESSION, content = ['fl', 'fr', 'rl', 'rr']
TPMS_PRESSURE, content = ['fl', 'fr', 'rl', 'rr']
TPMS_TEMPERATURE, content = ['fl', 'fr', 'rl', 'rr']
GPS_COORDS, content = ['latitude', 'longitude']
GPS_SPEED, content = ['speed']
IMU_ANGULAR_RATE, content = ['x', 'y', 'z']
IMU_ACCELERATION, content = ['x', 'y', 'z', 'imu_temperature']

## rod_id è un enum con i valori che sono i nomi che usano in DMT per definire i braccetti
LINK_DEFORMATION_FL, content = ['rod_id', 'deformation']

CONTROL_OUTPUT, content = ['u_bar', 'tmax_rr', 'tmax_rl', 'torque_rl', 'torque_rr'] # questo sistematelo come vuoi

IRTS_FL_0, content = ['channel_1', 'channel_2', 'channel_3', 'channel_4']
IRTS_FL_1, content = ['channel_5', 'channel_6', 'channel_7', 'channel_8']
IRTS_FL_2, content = ['channel_9', 'channel_10', 'channel_11', 'channel_12']
IRTS_FL_3, content = ['channel_13', 'channel_14', 'channel_15', 'channel_16']
IRTS_FR_0, content = ['channel_1', 'channel_2', 'channel_3', 'channel_4']
IRTS_FR_1, content = ['channel_5', 'channel_6', 'channel_7', 'channel_8']
IRTS_FR_2, content = ['channel_9', 'channel_10', 'channel_11', 'channel_12']
IRTS_FR_3, content = ['channel_13', 'channel_14', 'channel_15', 'channel_16']
IRTS_RL_0, content = ['channel_1', 'channel_2', 'channel_3', 'channel_4']
IRTS_RL_1, content = ['channel_5', 'channel_6', 'channel_7', 'channel_8']
IRTS_RL_2, content = ['channel_9', 'channel_10', 'channel_11', 'channel_12']
IRTS_RL_3, content = ['channel_13', 'channel_14', 'channel_15', 'channel_16']
IRTS_RR_0, content = ['channel_1', 'channel_2', 'channel_3', 'channel_4']
IRTS_RR_1, content = ['channel_5', 'channel_6', 'channel_7', 'channel_8']
IRTS_RR_2, content = ['channel_9', 'channel_10', 'channel_11', 'channel_12']
IRTS_RR_3, content = ['channel_13', 'channel_14', 'channel_15', 'channel_16']

PEDAL_THROTTLE, content = ['percentage'] # al posto di PEDALS_OUTPUT (?)
PEDAL_BRAKES_PRESSURE, content = ['front', 'rear']

DEBUG_SIGNAL, content = ['field_1', 'field_2', 'field_3', 'field_4'] # su ogni rete del can, primary, secondary e bms

