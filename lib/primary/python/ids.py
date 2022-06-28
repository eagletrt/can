VERSION = 1.3

# TOPIC FLASH
primary_TOPIC_FLASH_MASK = 0b00000011111

primary_ID_BMS_HV_JMP_TO_BLT = 0b00000000000
primary_ID_BMS_LV_JMP_TO_BLT = 0b00000100000

# TOPIC BROADCAST
primary_TOPIC_BROADCAST_MASK = 0b00000011111
primary_TOPIC_BROADCAST_FILTER = 0b00000000001

primary_ID_STEER_VERSION = 0b10000000001
primary_ID_DAS_VERSION = 0b10000100001
primary_ID_HV_VERSION = 0b10001000001
primary_ID_LV_VERSION = 0b10001100001
primary_ID_TLM_VERSION = 0b10010000001
primary_ID_TIMESTAMP = 0b00100000001

# TOPIC TLM
primary_TOPIC_TLM_MASK = 0b00000011111
primary_TOPIC_TLM_FILTER = 0b00000000010

primary_ID_SET_TLM_STATUS = 0b00100000010
primary_ID_STEER_SYSTEM_STATUS = 0b11100000010
primary_ID_MARKER = 0b00000000010

# TOPIC STEER
primary_TOPIC_STEER_MASK = 0b00000011111
primary_TOPIC_STEER_FILTER = 0b00000000011

primary_ID_TLM_STATUS = 0b00100000011
primary_ID_CAR_STATUS = 0b01000000011
primary_ID_DAS_ERRORS = 0b00000000011
primary_ID_SPEED = 0b01000100011

# TOPIC DASnSTEERnCART
primary_TOPIC_DASnSTEERnCART_MASK = 0b00000011111
primary_TOPIC_DASnSTEERnCART_FILTER = 0b00000000100

primary_ID_HV_VOLTAGE = 0b01100000100
primary_ID_HV_CURRENT = 0b01100100100
primary_ID_HV_TEMP = 0b01101000100
primary_ID_HV_ERRORS = 0b00000000100
primary_ID_TS_STATUS = 0b00000100100

# TOPIC BMS_HV
primary_TOPIC_BMS_HV_MASK = 0b00000011111
primary_TOPIC_BMS_HV_FILTER = 0b00000000101

primary_ID_HV_CAN_FORWARD = 0b00000000101
primary_ID_HV_FANS_OVERRIDE = 0b00000100101
primary_ID_SET_TS_STATUS_DAS = 0b00001000101
primary_ID_SET_TS_STATUS_HANDCART = 0b00001100101
primary_ID_SET_CELL_BALANCING_STATUS = 0b01000000101
primary_ID_HANDCART_STATUS = 0b01100000101

# TOPIC HANDCART
primary_TOPIC_HANDCART_MASK = 0b00000011111
primary_TOPIC_HANDCART_FILTER = 0b00000000110

primary_ID_HV_CAN_FORWARD_STATUS = 0b00000000110
primary_ID_HV_FANS_OVERRIDE_STATUS = 0b01100000110
primary_ID_HV_CELLS_VOLTAGE = 0b01000000110
primary_ID_HV_CELLS_TEMP = 0b01000100110
primary_ID_HV_CELL_BALANCING_STATUS = 0b01001000110

# TOPIC DASnSTEER
primary_TOPIC_DASnSTEER_MASK = 0b00000011111
primary_TOPIC_DASnSTEER_FILTER = 0b00000000111

primary_ID_HV_FEEDBACKS_STATUS = 0b01100000111
primary_ID_HV_IMD_STATUS = 0b01100100111
primary_ID_LV_CURRENT = 0b01101000111
primary_ID_LV_VOLTAGE = 0b01101100111
primary_ID_LV_TOTAL_VOLTAGE = 0b01110000111
primary_ID_LV_TEMPERATURE = 0b01110100111
primary_ID_COOLING_STATUS = 0b01111000111
primary_ID_INVERTER_CONNECTION_STATUS = 0b00100000111
primary_ID_SHUTDOWN_STATUS = 0b00100100111

# TOPIC DAS
primary_TOPIC_DAS_MASK = 0b00000011111
primary_TOPIC_DAS_FILTER = 0b00000001000

primary_ID_STEER_STATUS = 0b00100001000
primary_ID_SET_CAR_STATUS = 0b01100001000
primary_ID_SET_PEDALS_RANGE = 0b10000001000
primary_ID_SET_STEERING_ANGLE_RANGE = 0b10000101000

# TOPIC LV
primary_TOPIC_LV_MASK = 0b00000011111
primary_TOPIC_LV_FILTER = 0b00000001001

primary_ID_SET_RADIATOR_SPEED = 0b01100001001
primary_ID_SET_PUMPS_SPEED = 0b01100101001
primary_ID_SET_INVERTER_CONNECTION_STATUS = 0b00100001001

# TOPIC FIXED_IDS
primary_TOPIC_FIXED_IDS_MASK = 0b00000011111

primary_ID_INV_L_REQUEST = 0b01000000001
primary_ID_INV_R_REQUEST = 0b01000000010
primary_ID_INV_L_RESPONSE = 0b00110000001
primary_ID_INV_R_RESPONSE = 0b00110000010
primary_ID_FLASH_CELLBOARD_0_TX = 0b00000010000
primary_ID_FLASH_CELLBOARD_0_RX = 0b00000010001
primary_ID_FLASH_CELLBOARD_1_TX = 0b00000010010
primary_ID_FLASH_CELLBOARD_1_RX = 0b00000010011
primary_ID_FLASH_CELLBOARD_2_TX = 0b00000010100
primary_ID_FLASH_CELLBOARD_2_RX = 0b00000010101
primary_ID_FLASH_CELLBOARD_3_TX = 0b00000010110
primary_ID_FLASH_CELLBOARD_3_RX = 0b00000010111
primary_ID_FLASH_CELLBOARD_4_TX = 0b00000011000
primary_ID_FLASH_CELLBOARD_4_RX = 0b00000011001
primary_ID_FLASH_CELLBOARD_5_TX = 0b00000011010
primary_ID_FLASH_CELLBOARD_5_RX = 0b00000011011
primary_ID_FLASH_BMS_HV_TX = 0b11111100001
primary_ID_FLASH_BMS_HV_RX = 0b11001100111
primary_ID_FLASH_BMS_LV_TX = 0b11111110001
primary_ID_FLASH_BMS_LV_RX = 0b11001110111
primary_ID_BRUSA_NLG5_CTL = 0b01001101010
primary_ID_BRUSA_ST = 0b01001100010
primary_ID_BRUSA_ACT_I = 0b01001100011
primary_ID_BRUSA_ACT_II = 0b01001100100
primary_ID_BRUSA_TEMP = 0b01001100101
primary_ID_BRUSA_ERR = 0b01001100110
primary_ID_BMS_HV_CHIMERA = 0b00010101010
primary_ID_ECU_CHIMERA = 0b00001010101
