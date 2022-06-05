VERSION = 1.3

# TOPIC BROADCAST
primary_TOPIC_BROADCAST_MASK = 0b00000011111

primary_ID_STEER_VERSION = 0b10000000000
primary_ID_DAS_VERSION = 0b10000100000
primary_ID_HV_VERSION = 0b10001000000
primary_ID_LV_VERSION = 0b10001100000
primary_ID_TLM_VERSION = 0b10010000000
primary_ID_TIMESTAMP = 0b00100000000

# TOPIC TLM
primary_TOPIC_TLM_MASK = 0b00000011111
primary_TOPIC_TLM_FILTER = 0b00000000001

primary_ID_SET_TLM_STATUS = 0b00100000001
primary_ID_STEER_SYSTEM_STATUS = 0b11100000001
primary_ID_MARKER = 0b00000000001

# TOPIC STEER
primary_TOPIC_STEER_MASK = 0b00000011111
primary_TOPIC_STEER_FILTER = 0b00000000010

primary_ID_TLM_STATUS = 0b00100000010
primary_ID_CAR_STATUS = 0b01000000010
primary_ID_DAS_ERRORS = 0b00000000010
primary_ID_SPEED = 0b01000100010

# TOPIC DASnSTEERnCART
primary_TOPIC_DASnSTEERnCART_MASK = 0b00000011111
primary_TOPIC_DASnSTEERnCART_FILTER = 0b00000000011

primary_ID_HV_VOLTAGE = 0b01100000011
primary_ID_HV_CURRENT = 0b01100100011
primary_ID_HV_TEMP = 0b01101000011
primary_ID_HV_ERRORS = 0b00000000011
primary_ID_TS_STATUS = 0b00000100011

# TOPIC BMS_HV
primary_TOPIC_BMS_HV_MASK = 0b00000011111
primary_TOPIC_BMS_HV_FILTER = 0b00000000100

primary_ID_SET_TS_STATUS_DAS = 0b00000000100
primary_ID_SET_TS_STATUS_HANDCART = 0b00000100100
primary_ID_SET_CELL_BALANCING_STATUS = 0b01000000100
primary_ID_HANDCART_STATUS = 0b01100000100

# TOPIC DAS
primary_TOPIC_DAS_MASK = 0b00000011111
primary_TOPIC_DAS_FILTER = 0b00000000101

primary_ID_STEER_STATUS = 0b00100000101
primary_ID_SET_CAR_STATUS = 0b01100000101
primary_ID_SET_PEDALS_RANGE = 0b10000000101
primary_ID_SET_STEERING_ANGLE_RANGE = 0b10000100101

# TOPIC DASnSTEER
primary_TOPIC_DASnSTEER_MASK = 0b00000011111
primary_TOPIC_DASnSTEER_FILTER = 0b00000000110

primary_ID_LV_CURRENT = 0b01100000110
primary_ID_LV_VOLTAGE = 0b01100100110
primary_ID_LV_TOTAL_VOLTAGE = 0b01101000110
primary_ID_LV_TEMPERATURE = 0b01101100110
primary_ID_COOLING_STATUS = 0b01110000110

# TOPIC DASnLV
primary_TOPIC_DASnLV_MASK = 0b00000011111
primary_TOPIC_DASnLV_FILTER = 0b00000000111

primary_ID_SET_RADIATOR_SPEED = 0b01100000111
primary_ID_SET_PUMPS_POWER = 0b01100100111

# TOPIC HANDCART
primary_TOPIC_HANDCART_MASK = 0b00000011111
primary_TOPIC_HANDCART_FILTER = 0b00000001000

primary_ID_HV_CELLS_VOLTAGE = 0b01000001000
primary_ID_HV_CELLS_TEMP = 0b01000101000
primary_ID_HV_CELL_BALANCING_STATUS = 0b01001001000

# TOPIC FIXED_IDS
primary_TOPIC_FIXED_IDS_MASK = 0b00000011111

primary_ID_INV_L_SET_TORQUE = 0b01000000001
primary_ID_INV_L_RESPONSE = 0b00110000001