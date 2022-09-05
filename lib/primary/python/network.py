from __future__ import annotations
from enum import IntEnum, IntFlag
from struct import pack, unpack
from typing import Any, Optional
from builtins import bool as Bool

CANLIB_BUILD_TIME = 1662390793
CANLIB_BUILD_HASH = 0x1606c8cf

def int8(value: Any) -> Optional[int]:
    return int(value) if value is not None else None

def uint8(value: Any) -> Optional[int]:
    return int(value) if value is not None else None

def int16(value: Any) -> Optional[int]:
    return int(value) if value is not None else None

def uint16(value: Any) -> Optional[int]:
    return int(value) if value is not None else None

def int32(value: Any) -> Optional[int]:
    return int(value) if value is not None else None

def uint32(value: Any) -> Optional[int]:
    return int(value) if value is not None else None

def int64(value: Any) -> Optional[int]:
    return int(value) if value is not None else None

def uint64(value: Any) -> Optional[int]:
    return int(value) if value is not None else None

def float32(value: Any) -> Optional[float]:
    return float(value) if value is not None else None

def float64(value: Any) -> Optional[float]:
    return float(value) if value is not None else None

def bool(value: Any) -> Optional[Bool]:
    return Bool(value) if value is not None else None


# Bitsets


class HvErrors(IntFlag):
    CELL_LOW_VOLTAGE = 1
    CELL_UNDER_VOLTAGE = 2
    CELL_OVER_VOLTAGE = 4
    CELL_HIGH_TEMPERATURE = 8
    CELL_OVER_TEMPERATURE = 16
    OVER_CURRENT = 32
    CAN = 64
    INT_VOLTAGE_MISMATCH = 128
    CELLBOARD_COMM = 256
    CELLBOARD_INTERNAL = 512
    FEEDBACK = 1024
    FEEDBACK_CIRCUITRY = 2048
    EEPROM_COMM = 4096
    EEPROM_WRITE = 8192

    @classmethod
    def _missing_(cls, value):
        if value is None:
            return cls(0)
        return super(IntFlag, cls)._missing_(value)


class LvErrors(IntFlag):
    CELL_UNDERVOLTAGE = 1
    CELL_OVERVOLTAGE = 2
    OPEN_WIRE = 4
    CAN = 8
    SPI = 16
    OVER_CURRENT = 32
    DCDC12_UNDER_TEMPERATURE = 64
    DCDC12_OVER_TEMPERATURE = 128
    DCDC24_UNDER_TEMPERATURE = 256
    DCDC24_OVER_TEMPERATURE = 512
    CELL_UNDER_TEMPERATURE = 1024
    CELL_OVER_TEMPERATURE = 2048
    RELAY = 4096
    LTC6810 = 8192
    VOLTAGES_NOT_READY = 16384
    MCP23017 = 32768
    RADIATOR = 65536
    FAN = 131072
    PUMP = 262144
    ADC_INIT = 524288
    DCDC12 = 1048576
    DCDC24 = 2097152

    @classmethod
    def _missing_(cls, value):
        if value is None:
            return cls(0)
        return super(IntFlag, cls)._missing_(value)


class DasErrors(IntFlag):
    PEDAL_ADC = 1
    PEDAL_IMPLAUSIBILITY = 2
    IMU_TOUT = 4
    IRTS_TOUT = 8
    TS_TOUT = 16
    INVL_TOUT = 32
    INVR_TOUT = 64
    STEER_TOUT = 128
    FSM = 256

    @classmethod
    def _missing_(cls, value):
        if value is None:
            return cls(0)
        return super(IntFlag, cls)._missing_(value)


class InvStatus(IntFlag):
    DRIVE_ENABLE = 1
    NCR0 = 2
    LIMP = 4
    LIMM = 8
    DRIVE_OK = 16
    ICNS = 32
    T_NLIM = 64
    P_N = 128
    N_I = 256
    N0 = 512
    RSW = 1024
    CAL0 = 2048
    CAL = 4096
    TOL = 8192
    DRIVE_READY = 16384
    BRK = 32768
    SIGN_MAG = 65536
    NCLIP = 131072
    NCLIPP = 262144
    NCLIPM = 524288
    IRD_DIG = 1048576
    IUSE_RCHD = 2097152
    IRD_N = 4194304
    IRD_TI = 8388608
    IRD_TIR = 16777216
    HZ10 = 33554432
    IRD_TM = 67108864
    IRD_ANA = 134217728
    IWCNS = 268435456
    RFE_PULSE = 536870912
    MD = 1073741824
    HND_WHL = 2147483648

    @classmethod
    def _missing_(cls, value):
        if value is None:
            return cls(0)
        return super(IntFlag, cls)._missing_(value)


class InvErrors(IntFlag):
    BAD_PARAM = 1
    HW_FAULT = 2
    SAFETY_FAULT = 4
    CAN_TIMEOUT = 8
    ENCODER_ERR = 16
    NO_POWER_VOLTAGE = 32
    HI_MOTOR_TEMP = 64
    HI_DEVICE_TEMP = 128
    OVERVOLTAGE = 256
    OVERCURRENT = 512
    RACEAWAY = 1024
    USER_ERR = 2048
    UNKNOWN_ERR_12 = 4096
    UNKNOWN_ERR_13 = 8192
    CURRENT_ERR = 16384
    BALLAST_OVERLOAD = 32768
    DEVICE_ID_ERR = 65536
    RUN_SIG_FAULT = 131072
    UNKNOWN_ERR_19 = 262144
    UNKNOWN_ERR_20 = 524288
    POWERVOLTAGE_WARN = 1048576
    HI_MOTOR_TEMP_WARN = 2097152
    HI_DEVICE_TEMP_WARN = 4194304
    VOUT_LIMIT_WARN = 8388608
    OVERCURRENT_WARN = 16777216
    RACEAWAY_WARN = 33554432
    UNKNOWN_ERR_27 = 67108864
    UNKNOWN_ERR_28 = 134217728
    UNKNOWN_ERR_29 = 268435456
    UNKNOWN_ERR_30 = 536870912
    BALLAST_OVERLOAD_WARN = 1073741824

    @classmethod
    def _missing_(cls, value):
        if value is None:
            return cls(0)
        return super(IntFlag, cls)._missing_(value)


class Inv_IOInfo(IntFlag):
    LMT1 = 1
    LMT2 = 2
    IN2 = 4
    IN1 = 8
    FRG = 16
    RFE = 32
    UNK6 = 64
    UNK7 = 128
    OUT1 = 256
    OUT2 = 512
    BTB = 1024
    GO = 2048
    OUT3 = 4096
    OUT4 = 8192
    G_OFF = 16384
    BRK1 = 32768

    @classmethod
    def _missing_(cls, value):
        if value is None:
            return cls(0)
        return super(IntFlag, cls)._missing_(value)


class HvFeedbacks(IntFlag):
    FEEDBACK_TSAL_GREEN_FAULT = 1
    FEEDBACK_IMD_LATCHED = 2
    FEEDBACK_TSAL_GREEN_FAULT_LATCHED = 4
    FEEDBACK_BMS_LATCHED = 8
    FEEDBACK_EXT_LATCHED = 16
    FEEDBACK_TSAL_GREEN = 32
    FEEDBACK_TS_OVER_60V_STATUS = 64
    FEEDBACK_AIRN_STATUS = 128
    FEEDBACK_AIRP_STATUS = 256
    FEEDBACK_AIRP_GATE = 512
    FEEDBACK_AIRN_GATE = 1024
    FEEDBACK_PRECHARGE_STATUS = 2048
    FEEDBACK_TSP_OVER_60V_STATUS = 4096
    FEEDBACK_CHECK_MUX = 8192
    FEEDBACK_SD_IN = 16384
    FEEDBACK_SD_OUT = 32768
    FEEDBACK_RELAY_SD = 65536
    FEEDBACK_IMD_FAULT = 131072
    FEEDBACK_SD_END = 262144

    @classmethod
    def _missing_(cls, value):
        if value is None:
            return cls(0)
        return super(IntFlag, cls)._missing_(value)

# Enums


class RaceType(IntEnum):
    ACCELERATION = 0
    SKIDPAD = 1
    AUTOCROSS = 2
    ENDURANCE = 3

    @classmethod
    def _missing_(cls, _):
        return cls(0)


class InverterStatus(IntEnum):
    OFF = 0
    IDLE = 1
    ON = 2

    @classmethod
    def _missing_(cls, _):
        return cls(0)


class CarStatus(IntEnum):
    IDLE = 0
    PRE_SETUP = 1
    TS_ON = 2
    POST_SETUP = 3
    DRIVE = 4
    TEARDOWN = 5

    @classmethod
    def _missing_(cls, _):
        return cls(0)


class Toggle(IntEnum):
    OFF = 0
    ON = 1

    @classmethod
    def _missing_(cls, _):
        return cls(0)


class TractionControl(IntEnum):
    OFF = 0
    SLIP_CONTROL = 1
    TORQUE_VECTORING = 2
    COMPLETE = 3

    @classmethod
    def _missing_(cls, _):
        return cls(0)


class TsStatus(IntEnum):
    OFF = 0
    PRECHARGE = 1
    ON = 2
    FATAL = 3

    @classmethod
    def _missing_(cls, _):
        return cls(0)


class SetCarStatus(IntEnum):
    IDLE = 0
    READY = 1
    DRIVE = 2

    @classmethod
    def _missing_(cls, _):
        return cls(0)


class Bound(IntEnum):
    SET_MAX = 0
    SET_MIN = 1

    @classmethod
    def _missing_(cls, _):
        return cls(0)


class Pedal(IntEnum):
    ACCELERATOR = 0
    BRAKE = 1

    @classmethod
    def _missing_(cls, _):
        return cls(0)


class ImdStatus(IntEnum):
    IMD_SC = 0
    IMD_NORMAL = 1
    IMD_UNDER_VOLTAGE = 2
    IMD_START_MEASURE = 3
    IMD_DEVICE_ERROR = 4
    IMD_EARTH_FAULT = 5

    @classmethod
    def _missing_(cls, _):
        return cls(0)

# Messages


class message_BMS_HV_JMP_TO_BLT:
    def __init__(
        self
    ):
        self.size = 0

    def __eq__(self, other):
        if not isinstance(other, message_BMS_HV_JMP_TO_BLT):
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend()
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        return message


class message_BMS_LV_JMP_TO_BLT:
    def __init__(
        self
    ):
        self.size = 0

    def __eq__(self, other):
        if not isinstance(other, message_BMS_LV_JMP_TO_BLT):
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend()
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        return message


class message_STEER_VERSION:
    def __init__(
        self,
        component_version = None,
        cancicd_version = None
    ):
        self.component_version = uint8(component_version)
        self.cancicd_version = uint32(cancicd_version)
        self.size = 5
        self.interval = 1000

    def __eq__(self, other):
        if not isinstance(other, message_STEER_VERSION):
            return False
        if self.component_version != other.component_version:
            return False
        if self.cancicd_version != other.cancicd_version:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<IB", self.cancicd_version, self.component_version))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.component_version = uint8(unpack("<xxxxB", data[0:5])[0])
        message.cancicd_version = uint32(unpack("<I", data[0:4])[0])
        return message


class message_DAS_VERSION:
    def __init__(
        self,
        component_version = None,
        cancicd_version = None
    ):
        self.component_version = uint8(component_version)
        self.cancicd_version = uint32(cancicd_version)
        self.size = 5
        self.interval = 1000

    def __eq__(self, other):
        if not isinstance(other, message_DAS_VERSION):
            return False
        if self.component_version != other.component_version:
            return False
        if self.cancicd_version != other.cancicd_version:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<IB", self.cancicd_version, self.component_version))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.component_version = uint8(unpack("<xxxxB", data[0:5])[0])
        message.cancicd_version = uint32(unpack("<I", data[0:4])[0])
        return message


class message_HV_VERSION:
    def __init__(
        self,
        component_version = None,
        cancicd_version = None
    ):
        self.component_version = uint8(component_version)
        self.cancicd_version = uint32(cancicd_version)
        self.size = 5
        self.interval = 1000

    def __eq__(self, other):
        if not isinstance(other, message_HV_VERSION):
            return False
        if self.component_version != other.component_version:
            return False
        if self.cancicd_version != other.cancicd_version:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<IB", self.cancicd_version, self.component_version))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.component_version = uint8(unpack("<xxxxB", data[0:5])[0])
        message.cancicd_version = uint32(unpack("<I", data[0:4])[0])
        return message


class message_LV_VERSION:
    def __init__(
        self,
        component_version = None,
        cancicd_version = None
    ):
        self.component_version = uint8(component_version)
        self.cancicd_version = uint32(cancicd_version)
        self.size = 5
        self.interval = 1000

    def __eq__(self, other):
        if not isinstance(other, message_LV_VERSION):
            return False
        if self.component_version != other.component_version:
            return False
        if self.cancicd_version != other.cancicd_version:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<IB", self.cancicd_version, self.component_version))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.component_version = uint8(unpack("<xxxxB", data[0:5])[0])
        message.cancicd_version = uint32(unpack("<I", data[0:4])[0])
        return message


class message_TLM_VERSION:
    def __init__(
        self,
        component_version = None,
        cancicd_version = None
    ):
        self.component_version = uint8(component_version)
        self.cancicd_version = uint32(cancicd_version)
        self.size = 5
        self.interval = 1000

    def __eq__(self, other):
        if not isinstance(other, message_TLM_VERSION):
            return False
        if self.component_version != other.component_version:
            return False
        if self.cancicd_version != other.cancicd_version:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<IB", self.cancicd_version, self.component_version))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.component_version = uint8(unpack("<xxxxB", data[0:5])[0])
        message.cancicd_version = uint32(unpack("<I", data[0:4])[0])
        return message


class message_TIMESTAMP:
    def __init__(
        self,
        timestamp = None
    ):
        self.timestamp = uint32(timestamp)
        self.size = 4
        self.interval = 1000

    def __eq__(self, other):
        if not isinstance(other, message_TIMESTAMP):
            return False
        if self.timestamp != other.timestamp:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<I", self.timestamp))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.timestamp = uint32(unpack("<I", data[0:4])[0])
        return message


class message_AMBIENT_TEMPERATURE:
    def __init__(
        self,
        temp = None
    ):
        self.temp = int16(temp)
        self.size = 2
        self.interval = 1000

    def __eq__(self, other):
        if not isinstance(other, message_AMBIENT_TEMPERATURE):
            return False
        if self.temp != other.temp:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<h", self.temp))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.temp = int16(unpack("<h", data[0:2])[0])
        return message


class message_DATA_LOGGER:
    def __init__(
        self,
        placeholder1 = None,
        placeholder2 = None
    ):
        self.placeholder1 = uint32(placeholder1)
        self.placeholder2 = uint32(placeholder2)
        self.size = 8
        self.interval = 1000

    def __eq__(self, other):
        if not isinstance(other, message_DATA_LOGGER):
            return False
        if self.placeholder1 != other.placeholder1:
            return False
        if self.placeholder2 != other.placeholder2:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<II", self.placeholder1, self.placeholder2))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.placeholder1 = uint32(unpack("<I", data[0:4])[0])
        message.placeholder2 = uint32(unpack("<xxxxI", data[0:8])[0])
        return message


class message_SET_TLM_STATUS:
    def __init__(
        self,
        tlm_status = None
    ):
        self.tlm_status = Toggle(tlm_status)
        self.size = 1

    def __eq__(self, other):
        if not isinstance(other, message_SET_TLM_STATUS):
            return False
        if self.tlm_status != other.tlm_status:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<B", self.tlm_status << 7 & 255))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.tlm_status = Toggle((unpack("<B", data[0:1])[0] & 128) >> 7)
        return message


class message_TLM_STATUS:
    def __init__(
        self,
        tlm_status = None
    ):
        self.tlm_status = Toggle(tlm_status)
        self.size = 1
        self.interval = 1000

    def __eq__(self, other):
        if not isinstance(other, message_TLM_STATUS):
            return False
        if self.tlm_status != other.tlm_status:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<B", self.tlm_status << 7 & 255))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.tlm_status = Toggle((unpack("<B", data[0:1])[0] & 128) >> 7)
        return message


class message_STEER_SYSTEM_STATUS:
    def __init__(
        self,
        soc_temp = None
    ):
        self.soc_temp = uint8(soc_temp)
        self.size = 1
        self.interval = 1000

    def __eq__(self, other):
        if not isinstance(other, message_STEER_SYSTEM_STATUS):
            return False
        if self.soc_temp != other.soc_temp:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<B", self.soc_temp))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.soc_temp = uint8(unpack("<B", data[0:1])[0])
        return message


class message_HV_VOLTAGE:
    def __init__(
        self,
        pack_voltage = None,
        bus_voltage = None,
        max_cell_voltage = None,
        min_cell_voltage = None
    ):
        self.pack_voltage = uint16(pack_voltage)
        self.bus_voltage = uint16(bus_voltage)
        self.max_cell_voltage = uint16(max_cell_voltage)
        self.min_cell_voltage = uint16(min_cell_voltage)
        self.size = 8
        self.interval = 10

    def __eq__(self, other):
        if not isinstance(other, message_HV_VOLTAGE):
            return False
        if self.pack_voltage != other.pack_voltage:
            return False
        if self.bus_voltage != other.bus_voltage:
            return False
        if self.max_cell_voltage != other.max_cell_voltage:
            return False
        if self.min_cell_voltage != other.min_cell_voltage:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<HHHH", self.pack_voltage, self.bus_voltage, self.max_cell_voltage, self.min_cell_voltage))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.pack_voltage = uint16(unpack("<H", data[0:2])[0])
        message.bus_voltage = uint16(unpack("<xxH", data[0:4])[0])
        message.max_cell_voltage = uint16(unpack("<xxxxH", data[0:6])[0])
        message.min_cell_voltage = uint16(unpack("<xxxxxxH", data[0:8])[0])
        return message


    def convert(self) -> message_HV_VOLTAGE_conversion:
        conversion = message_HV_VOLTAGE_conversion()
        conversion.pack_voltage = ((float32(self.pack_voltage)) / 142.467391) + 0
        conversion.bus_voltage = ((float32(self.bus_voltage)) / 142.467391) + 0
        conversion.max_cell_voltage = ((float32(self.max_cell_voltage)) / 10000.0) + 0
        conversion.min_cell_voltage = ((float32(self.min_cell_voltage)) / 10000.0) + 0
        return conversion


class message_HV_VOLTAGE_conversion:
    def __init__(
        self,
        pack_voltage = None,
        bus_voltage = None,
        max_cell_voltage = None,
        min_cell_voltage = None
    ):
        self.pack_voltage = float32(pack_voltage)
        self.bus_voltage = float32(bus_voltage)
        self.max_cell_voltage = float32(max_cell_voltage)
        self.min_cell_voltage = float32(min_cell_voltage)
        self.size = 8
        self.interval = 10

    def __eq__(self, other):
        if not isinstance(other, message_HV_VOLTAGE):
            return False
        if self.pack_voltage != other.pack_voltage:
            return False
        if self.bus_voltage != other.bus_voltage:
            return False
        if self.max_cell_voltage != other.max_cell_voltage:
            return False
        if self.min_cell_voltage != other.min_cell_voltage:
            return False
        return True

    def convert_to_raw(self) -> message_HV_VOLTAGE:
        raw = message_HV_VOLTAGE()
        raw.pack_voltage = uint16((self.pack_voltage + 0) * 142.467391)
        raw.bus_voltage = uint16((self.bus_voltage + 0) * 142.467391)
        raw.max_cell_voltage = uint16((self.max_cell_voltage + 0) * 10000.0)
        raw.min_cell_voltage = uint16((self.min_cell_voltage + 0) * 10000.0)
        return raw

class message_HV_CURRENT:
    def __init__(
        self,
        current = None,
        power = None,
        energy = None,
        soc = None
    ):
        self.current = uint16(current)
        self.power = uint16(power)
        self.energy = uint16(energy)
        self.soc = uint8(soc)
        self.size = 7
        self.interval = 10

    def __eq__(self, other):
        if not isinstance(other, message_HV_CURRENT):
            return False
        if self.current != other.current:
            return False
        if self.power != other.power:
            return False
        if self.energy != other.energy:
            return False
        if self.soc != other.soc:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<HHHB", self.current, self.power, self.energy, self.soc))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.current = uint16(unpack("<H", data[0:2])[0])
        message.power = uint16(unpack("<xxH", data[0:4])[0])
        message.energy = uint16(unpack("<xxxxH", data[0:6])[0])
        message.soc = uint8(unpack("<xxxxxxB", data[0:7])[0])
        return message


    def convert(self) -> message_HV_CURRENT_conversion:
        conversion = message_HV_CURRENT_conversion()
        conversion.current = ((float32(self.current)) / 312.071429) - 10
        conversion.power = ((float32(self.power)) / 655.35) + 0
        conversion.energy = ((float32(self.energy)) / 9.362143) + 0
        conversion.soc = ((float32(self.soc)) / 2.55) + 0
        return conversion


class message_HV_CURRENT_conversion:
    def __init__(
        self,
        current = None,
        power = None,
        energy = None,
        soc = None
    ):
        self.current = float32(current)
        self.power = float32(power)
        self.energy = float32(energy)
        self.soc = float32(soc)
        self.size = 7
        self.interval = 10

    def __eq__(self, other):
        if not isinstance(other, message_HV_CURRENT):
            return False
        if self.current != other.current:
            return False
        if self.power != other.power:
            return False
        if self.energy != other.energy:
            return False
        if self.soc != other.soc:
            return False
        return True

    def convert_to_raw(self) -> message_HV_CURRENT:
        raw = message_HV_CURRENT()
        raw.current = uint16((self.current + 10) * 312.071429)
        raw.power = uint16((self.power + 0) * 655.35)
        raw.energy = uint16((self.energy + 0) * 9.362143)
        raw.soc = uint8((self.soc + 0) * 2.55)
        return raw

class message_HV_TEMP:
    def __init__(
        self,
        average_temp = None,
        max_temp = None,
        min_temp = None
    ):
        self.average_temp = uint8(average_temp)
        self.max_temp = uint8(max_temp)
        self.min_temp = uint8(min_temp)
        self.size = 3
        self.interval = 100

    def __eq__(self, other):
        if not isinstance(other, message_HV_TEMP):
            return False
        if self.average_temp != other.average_temp:
            return False
        if self.max_temp != other.max_temp:
            return False
        if self.min_temp != other.min_temp:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<BBB", self.average_temp, self.max_temp, self.min_temp))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.average_temp = uint8(unpack("<B", data[0:1])[0])
        message.max_temp = uint8(unpack("<xB", data[0:2])[0])
        message.min_temp = uint8(unpack("<xxB", data[0:3])[0])
        return message


    def convert(self) -> message_HV_TEMP_conversion:
        conversion = message_HV_TEMP_conversion()
        conversion.average_temp = ((float32(self.average_temp)) / 2.55) - 20
        conversion.max_temp = ((float32(self.max_temp)) / 2.55) - 20
        conversion.min_temp = ((float32(self.min_temp)) / 2.55) - 20
        return conversion


class message_HV_TEMP_conversion:
    def __init__(
        self,
        average_temp = None,
        max_temp = None,
        min_temp = None
    ):
        self.average_temp = float32(average_temp)
        self.max_temp = float32(max_temp)
        self.min_temp = float32(min_temp)
        self.size = 3
        self.interval = 100

    def __eq__(self, other):
        if not isinstance(other, message_HV_TEMP):
            return False
        if self.average_temp != other.average_temp:
            return False
        if self.max_temp != other.max_temp:
            return False
        if self.min_temp != other.min_temp:
            return False
        return True

    def convert_to_raw(self) -> message_HV_TEMP:
        raw = message_HV_TEMP()
        raw.average_temp = uint8((self.average_temp + 20) * 2.55)
        raw.max_temp = uint8((self.max_temp + 20) * 2.55)
        raw.min_temp = uint8((self.min_temp + 20) * 2.55)
        return raw

class message_HV_ERRORS:
    def __init__(
        self,
        warnings = None,
        errors = None
    ):
        self.warnings = HvErrors(warnings)
        self.errors = HvErrors(errors)
        self.size = 4
        self.interval = 10

    def __eq__(self, other):
        if not isinstance(other, message_HV_ERRORS):
            return False
        if self.warnings != other.warnings:
            return False
        if self.errors != other.errors:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<BBBB", (int(self.warnings) >> 8) & 255, (int(self.warnings) >> 0) & 255, (int(self.errors) >> 8) & 255, (int(self.errors) >> 0) & 255))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.warnings = HvErrors(int((unpack("<BB", data[0:2])[0] << 8) | (unpack("<BB", data[0:2])[1] << 0)))
        message.errors = HvErrors(int((unpack("<xxBB", data[0:4])[0] << 8) | (unpack("<xxBB", data[0:4])[1] << 0)))
        return message


class message_HV_CAN_FORWARD:
    def __init__(
        self,
        can_forward_set = None
    ):
        self.can_forward_set = Toggle(can_forward_set)
        self.size = 1

    def __eq__(self, other):
        if not isinstance(other, message_HV_CAN_FORWARD):
            return False
        if self.can_forward_set != other.can_forward_set:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<B", self.can_forward_set << 7 & 255))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.can_forward_set = Toggle((unpack("<B", data[0:1])[0] & 128) >> 7)
        return message


class message_HV_FANS_OVERRIDE:
    def __init__(
        self,
        fans_override = None,
        fans_speed = None
    ):
        self.fans_override = Toggle(fans_override)
        self.fans_speed = uint16(fans_speed)
        self.size = 3

    def __eq__(self, other):
        if not isinstance(other, message_HV_FANS_OVERRIDE):
            return False
        if self.fans_override != other.fans_override:
            return False
        if self.fans_speed != other.fans_speed:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<HB", self.fans_speed, self.fans_override << 7 & 255))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.fans_override = Toggle((unpack("<xxB", data[0:3])[0] & 128) >> 7)
        message.fans_speed = uint16(unpack("<H", data[0:2])[0])
        return message


    def convert(self) -> message_HV_FANS_OVERRIDE_conversion:
        conversion = message_HV_FANS_OVERRIDE_conversion()
        conversion.fans_override = self.fans_override
        conversion.fans_speed = ((float32(self.fans_speed)) / 65535.0) + 0
        return conversion


class message_HV_FANS_OVERRIDE_conversion:
    def __init__(
        self,
        fans_override = None,
        fans_speed = None
    ):
        self.fans_override = Toggle(fans_override)
        self.fans_speed = float32(fans_speed)
        self.size = 3

    def __eq__(self, other):
        if not isinstance(other, message_HV_FANS_OVERRIDE):
            return False
        if self.fans_override != other.fans_override:
            return False
        if self.fans_speed != other.fans_speed:
            return False
        return True

    def convert_to_raw(self) -> message_HV_FANS_OVERRIDE:
        raw = message_HV_FANS_OVERRIDE()
        raw.fans_override = self.fans_override
        raw.fans_speed = uint16((self.fans_speed + 0) * 65535.0)
        return raw

class message_HV_CAN_FORWARD_STATUS:
    def __init__(
        self,
        can_forward_status = None
    ):
        self.can_forward_status = Toggle(can_forward_status)
        self.size = 1

    def __eq__(self, other):
        if not isinstance(other, message_HV_CAN_FORWARD_STATUS):
            return False
        if self.can_forward_status != other.can_forward_status:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<B", self.can_forward_status << 7 & 255))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.can_forward_status = Toggle((unpack("<B", data[0:1])[0] & 128) >> 7)
        return message


class message_HV_FANS_OVERRIDE_STATUS:
    def __init__(
        self,
        fans_override = None,
        fans_speed = None
    ):
        self.fans_override = Toggle(fans_override)
        self.fans_speed = uint16(fans_speed)
        self.size = 3

    def __eq__(self, other):
        if not isinstance(other, message_HV_FANS_OVERRIDE_STATUS):
            return False
        if self.fans_override != other.fans_override:
            return False
        if self.fans_speed != other.fans_speed:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<HB", self.fans_speed, self.fans_override << 7 & 255))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.fans_override = Toggle((unpack("<xxB", data[0:3])[0] & 128) >> 7)
        message.fans_speed = uint16(unpack("<H", data[0:2])[0])
        return message


    def convert(self) -> message_HV_FANS_OVERRIDE_STATUS_conversion:
        conversion = message_HV_FANS_OVERRIDE_STATUS_conversion()
        conversion.fans_override = self.fans_override
        conversion.fans_speed = ((float32(self.fans_speed)) / 65535.0) + 0
        return conversion


class message_HV_FANS_OVERRIDE_STATUS_conversion:
    def __init__(
        self,
        fans_override = None,
        fans_speed = None
    ):
        self.fans_override = Toggle(fans_override)
        self.fans_speed = float32(fans_speed)
        self.size = 3

    def __eq__(self, other):
        if not isinstance(other, message_HV_FANS_OVERRIDE_STATUS):
            return False
        if self.fans_override != other.fans_override:
            return False
        if self.fans_speed != other.fans_speed:
            return False
        return True

    def convert_to_raw(self) -> message_HV_FANS_OVERRIDE_STATUS:
        raw = message_HV_FANS_OVERRIDE_STATUS()
        raw.fans_override = self.fans_override
        raw.fans_speed = uint16((self.fans_speed + 0) * 65535.0)
        return raw

class message_HV_FEEDBACKS_STATUS:
    def __init__(
        self,
        feedbacks_status = None,
        is_circuitry_error = None
    ):
        self.feedbacks_status = HvFeedbacks(feedbacks_status)
        self.is_circuitry_error = HvFeedbacks(is_circuitry_error)
        self.size = 6

    def __eq__(self, other):
        if not isinstance(other, message_HV_FEEDBACKS_STATUS):
            return False
        if self.feedbacks_status != other.feedbacks_status:
            return False
        if self.is_circuitry_error != other.is_circuitry_error:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<BBBBBB", (int(self.feedbacks_status) >> 16) & 255, (int(self.feedbacks_status) >> 8) & 255, (int(self.feedbacks_status) >> 0) & 255, (int(self.is_circuitry_error) >> 16) & 255, (int(self.is_circuitry_error) >> 8) & 255, (int(self.is_circuitry_error) >> 0) & 255))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.feedbacks_status = HvFeedbacks(int((unpack("<BBB", data[0:3])[0] << 16) | (unpack("<BBB", data[0:3])[1] << 8) | (unpack("<BBB", data[0:3])[2] << 0)))
        message.is_circuitry_error = HvFeedbacks(int((unpack("<xxxBBB", data[0:6])[0] << 16) | (unpack("<xxxBBB", data[0:6])[1] << 8) | (unpack("<xxxBBB", data[0:6])[2] << 0)))
        return message


class message_HV_IMD_STATUS:
    def __init__(
        self,
        imd_fault = None,
        imd_status = None,
        imd_info = None
    ):
        self.imd_fault = bool(imd_fault)
        self.imd_status = ImdStatus(imd_status)
        self.imd_info = int32(imd_info)
        self.size = 5

    def __eq__(self, other):
        if not isinstance(other, message_HV_IMD_STATUS):
            return False
        if self.imd_fault != other.imd_fault:
            return False
        if self.imd_status != other.imd_status:
            return False
        if self.imd_info != other.imd_info:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<iB", self.imd_info, self.imd_status << 5 & 255 | self.imd_fault << 4 & 255))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.imd_fault = bool((unpack("<xxxxB", data[0:5])[0] & 16) >> 4)
        message.imd_status = ImdStatus((unpack("<xxxxB", data[0:5])[0] & 224) >> 5)
        message.imd_info = int32(unpack("<i", data[0:4])[0])
        return message


class message_TS_STATUS:
    def __init__(
        self,
        ts_status = None
    ):
        self.ts_status = TsStatus(ts_status)
        self.size = 1
        self.interval = 10

    def __eq__(self, other):
        if not isinstance(other, message_TS_STATUS):
            return False
        if self.ts_status != other.ts_status:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<B", self.ts_status << 6 & 255))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.ts_status = TsStatus((unpack("<B", data[0:1])[0] & 192) >> 6)
        return message


class message_SET_TS_STATUS:
    def __init__(
        self,
        ts_status_set = None
    ):
        self.ts_status_set = Toggle(ts_status_set)
        self.size = 1
        self.interval = 100

    def __eq__(self, other):
        if not isinstance(other, message_SET_TS_STATUS):
            return False
        if self.ts_status_set != other.ts_status_set:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<B", self.ts_status_set << 7 & 255))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.ts_status_set = Toggle((unpack("<B", data[0:1])[0] & 128) >> 7)
        return message


class message_STEER_STATUS:
    def __init__(
        self,
        traction_control = None,
        map = None
    ):
        self.traction_control = TractionControl(traction_control)
        self.map = int8(map)
        self.size = 2
        self.interval = 100

    def __eq__(self, other):
        if not isinstance(other, message_STEER_STATUS):
            return False
        if self.traction_control != other.traction_control:
            return False
        if self.map != other.map:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<bB", self.map, self.traction_control << 6 & 255))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.traction_control = TractionControl((unpack("<xB", data[0:2])[0] & 192) >> 6)
        message.map = int8(unpack("<b", data[0:1])[0])
        return message


class message_SET_CAR_STATUS:
    def __init__(
        self,
        car_status_set = None
    ):
        self.car_status_set = SetCarStatus(car_status_set)
        self.size = 1

    def __eq__(self, other):
        if not isinstance(other, message_SET_CAR_STATUS):
            return False
        if self.car_status_set != other.car_status_set:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<B", self.car_status_set << 6 & 255))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.car_status_set = SetCarStatus((unpack("<B", data[0:1])[0] & 192) >> 6)
        return message


class message_SET_PEDALS_RANGE:
    def __init__(
        self,
        bound = None,
        pedal = None
    ):
        self.bound = Bound(bound)
        self.pedal = Pedal(pedal)
        self.size = 1

    def __eq__(self, other):
        if not isinstance(other, message_SET_PEDALS_RANGE):
            return False
        if self.bound != other.bound:
            return False
        if self.pedal != other.pedal:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<B", self.bound << 7 & 255 | self.pedal << 6 & 255))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.bound = Bound((unpack("<B", data[0:1])[0] & 128) >> 7)
        message.pedal = Pedal((unpack("<B", data[0:1])[0] & 64) >> 6)
        return message


class message_SET_STEERING_ANGLE_RANGE:
    def __init__(
        self,
        bound = None
    ):
        self.bound = Bound(bound)
        self.size = 1

    def __eq__(self, other):
        if not isinstance(other, message_SET_STEERING_ANGLE_RANGE):
            return False
        if self.bound != other.bound:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<B", self.bound << 7 & 255))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.bound = Bound((unpack("<B", data[0:1])[0] & 128) >> 7)
        return message


class message_CAR_STATUS:
    def __init__(
        self,
        inverter_l = None,
        inverter_r = None,
        car_status = None
    ):
        self.inverter_l = InverterStatus(inverter_l)
        self.inverter_r = InverterStatus(inverter_r)
        self.car_status = CarStatus(car_status)
        self.size = 1
        self.interval = 100

    def __eq__(self, other):
        if not isinstance(other, message_CAR_STATUS):
            return False
        if self.inverter_l != other.inverter_l:
            return False
        if self.inverter_r != other.inverter_r:
            return False
        if self.car_status != other.car_status:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<B", self.car_status << 5 & 255 | self.inverter_l << 3 & 255 | self.inverter_r << 1 & 255))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.inverter_l = InverterStatus((unpack("<B", data[0:1])[0] & 24) >> 3)
        message.inverter_r = InverterStatus((unpack("<B", data[0:1])[0] & 6) >> 1)
        message.car_status = CarStatus((unpack("<B", data[0:1])[0] & 224) >> 5)
        return message


class message_DAS_ERRORS:
    def __init__(
        self,
        das_error = None
    ):
        self.das_error = DasErrors(das_error)
        self.size = 2
        self.interval = 10

    def __eq__(self, other):
        if not isinstance(other, message_DAS_ERRORS):
            return False
        if self.das_error != other.das_error:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<BB", (int(self.das_error) >> 8) & 255, (int(self.das_error) >> 0) & 255))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.das_error = DasErrors(int((unpack("<BB", data[0:2])[0] << 8) | (unpack("<BB", data[0:2])[1] << 0)))
        return message


class message_LV_CURRENT:
    def __init__(
        self,
        current = None
    ):
        self.current = uint16(current)
        self.size = 2
        self.interval = 500

    def __eq__(self, other):
        if not isinstance(other, message_LV_CURRENT):
            return False
        if self.current != other.current:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<H", self.current))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.current = uint16(unpack("<H", data[0:2])[0])
        return message


    def convert(self) -> message_LV_CURRENT_conversion:
        conversion = message_LV_CURRENT_conversion()
        conversion.current = ((float32(self.current)) / 1092.25) - 10
        return conversion


class message_LV_CURRENT_conversion:
    def __init__(
        self,
        current = None
    ):
        self.current = float32(current)
        self.size = 2
        self.interval = 500

    def __eq__(self, other):
        if not isinstance(other, message_LV_CURRENT):
            return False
        if self.current != other.current:
            return False
        return True

    def convert_to_raw(self) -> message_LV_CURRENT:
        raw = message_LV_CURRENT()
        raw.current = uint16((self.current + 10) * 1092.25)
        return raw

class message_LV_VOLTAGE:
    def __init__(
        self,
        voltage_1 = None,
        voltage_2 = None,
        voltage_3 = None,
        voltage_4 = None
    ):
        self.voltage_1 = uint16(voltage_1)
        self.voltage_2 = uint16(voltage_2)
        self.voltage_3 = uint16(voltage_3)
        self.voltage_4 = uint16(voltage_4)
        self.size = 8
        self.interval = 100

    def __eq__(self, other):
        if not isinstance(other, message_LV_VOLTAGE):
            return False
        if self.voltage_1 != other.voltage_1:
            return False
        if self.voltage_2 != other.voltage_2:
            return False
        if self.voltage_3 != other.voltage_3:
            return False
        if self.voltage_4 != other.voltage_4:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<HHHH", self.voltage_1, self.voltage_2, self.voltage_3, self.voltage_4))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.voltage_1 = uint16(unpack("<H", data[0:2])[0])
        message.voltage_2 = uint16(unpack("<xxH", data[0:4])[0])
        message.voltage_3 = uint16(unpack("<xxxxH", data[0:6])[0])
        message.voltage_4 = uint16(unpack("<xxxxxxH", data[0:8])[0])
        return message


    def convert(self) -> message_LV_VOLTAGE_conversion:
        conversion = message_LV_VOLTAGE_conversion()
        conversion.voltage_1 = ((float32(self.voltage_1)) / 10000.0) + 0
        conversion.voltage_2 = ((float32(self.voltage_2)) / 10000.0) + 0
        conversion.voltage_3 = ((float32(self.voltage_3)) / 10000.0) + 0
        conversion.voltage_4 = ((float32(self.voltage_4)) / 10000.0) + 0
        return conversion


class message_LV_VOLTAGE_conversion:
    def __init__(
        self,
        voltage_1 = None,
        voltage_2 = None,
        voltage_3 = None,
        voltage_4 = None
    ):
        self.voltage_1 = float32(voltage_1)
        self.voltage_2 = float32(voltage_2)
        self.voltage_3 = float32(voltage_3)
        self.voltage_4 = float32(voltage_4)
        self.size = 8
        self.interval = 100

    def __eq__(self, other):
        if not isinstance(other, message_LV_VOLTAGE):
            return False
        if self.voltage_1 != other.voltage_1:
            return False
        if self.voltage_2 != other.voltage_2:
            return False
        if self.voltage_3 != other.voltage_3:
            return False
        if self.voltage_4 != other.voltage_4:
            return False
        return True

    def convert_to_raw(self) -> message_LV_VOLTAGE:
        raw = message_LV_VOLTAGE()
        raw.voltage_1 = uint16((self.voltage_1 + 0) * 10000.0)
        raw.voltage_2 = uint16((self.voltage_2 + 0) * 10000.0)
        raw.voltage_3 = uint16((self.voltage_3 + 0) * 10000.0)
        raw.voltage_4 = uint16((self.voltage_4 + 0) * 10000.0)
        return raw

class message_LV_TOTAL_VOLTAGE:
    def __init__(
        self,
        total_voltage = None
    ):
        self.total_voltage = uint32(total_voltage)
        self.size = 4
        self.interval = 100

    def __eq__(self, other):
        if not isinstance(other, message_LV_TOTAL_VOLTAGE):
            return False
        if self.total_voltage != other.total_voltage:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<I", self.total_voltage))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.total_voltage = uint32(unpack("<I", data[0:4])[0])
        return message


    def convert(self) -> message_LV_TOTAL_VOLTAGE_conversion:
        conversion = message_LV_TOTAL_VOLTAGE_conversion()
        conversion.total_voltage = ((float32(self.total_voltage)) / 10000.0) + 0
        return conversion


class message_LV_TOTAL_VOLTAGE_conversion:
    def __init__(
        self,
        total_voltage = None
    ):
        self.total_voltage = float32(total_voltage)
        self.size = 4
        self.interval = 100

    def __eq__(self, other):
        if not isinstance(other, message_LV_TOTAL_VOLTAGE):
            return False
        if self.total_voltage != other.total_voltage:
            return False
        return True

    def convert_to_raw(self) -> message_LV_TOTAL_VOLTAGE:
        raw = message_LV_TOTAL_VOLTAGE()
        raw.total_voltage = uint32((self.total_voltage + 0) * 10000.0)
        return raw

class message_LV_TEMPERATURE:
    def __init__(
        self,
        bp_temperature_1 = None,
        bp_temperature_2 = None,
        dcdc12_temperature = None,
        dcdc24_temperature = None
    ):
        self.bp_temperature_1 = uint16(bp_temperature_1)
        self.bp_temperature_2 = uint16(bp_temperature_2)
        self.dcdc12_temperature = uint16(dcdc12_temperature)
        self.dcdc24_temperature = uint16(dcdc24_temperature)
        self.size = 8
        self.interval = 100

    def __eq__(self, other):
        if not isinstance(other, message_LV_TEMPERATURE):
            return False
        if self.bp_temperature_1 != other.bp_temperature_1:
            return False
        if self.bp_temperature_2 != other.bp_temperature_2:
            return False
        if self.dcdc12_temperature != other.dcdc12_temperature:
            return False
        if self.dcdc24_temperature != other.dcdc24_temperature:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<HHHH", self.bp_temperature_1, self.bp_temperature_2, self.dcdc12_temperature, self.dcdc24_temperature))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.bp_temperature_1 = uint16(unpack("<H", data[0:2])[0])
        message.bp_temperature_2 = uint16(unpack("<xxH", data[0:4])[0])
        message.dcdc12_temperature = uint16(unpack("<xxxxH", data[0:6])[0])
        message.dcdc24_temperature = uint16(unpack("<xxxxxxH", data[0:8])[0])
        return message


    def convert(self) -> message_LV_TEMPERATURE_conversion:
        conversion = message_LV_TEMPERATURE_conversion()
        conversion.bp_temperature_1 = ((float32(self.bp_temperature_1)) / 655.35) - 20
        conversion.bp_temperature_2 = ((float32(self.bp_temperature_2)) / 655.35) - 20
        conversion.dcdc12_temperature = ((float32(self.dcdc12_temperature)) / 655.35) - 20
        conversion.dcdc24_temperature = ((float32(self.dcdc24_temperature)) / 655.35) - 20
        return conversion


class message_LV_TEMPERATURE_conversion:
    def __init__(
        self,
        bp_temperature_1 = None,
        bp_temperature_2 = None,
        dcdc12_temperature = None,
        dcdc24_temperature = None
    ):
        self.bp_temperature_1 = float32(bp_temperature_1)
        self.bp_temperature_2 = float32(bp_temperature_2)
        self.dcdc12_temperature = float32(dcdc12_temperature)
        self.dcdc24_temperature = float32(dcdc24_temperature)
        self.size = 8
        self.interval = 100

    def __eq__(self, other):
        if not isinstance(other, message_LV_TEMPERATURE):
            return False
        if self.bp_temperature_1 != other.bp_temperature_1:
            return False
        if self.bp_temperature_2 != other.bp_temperature_2:
            return False
        if self.dcdc12_temperature != other.dcdc12_temperature:
            return False
        if self.dcdc24_temperature != other.dcdc24_temperature:
            return False
        return True

    def convert_to_raw(self) -> message_LV_TEMPERATURE:
        raw = message_LV_TEMPERATURE()
        raw.bp_temperature_1 = uint16((self.bp_temperature_1 + 20) * 655.35)
        raw.bp_temperature_2 = uint16((self.bp_temperature_2 + 20) * 655.35)
        raw.dcdc12_temperature = uint16((self.dcdc12_temperature + 20) * 655.35)
        raw.dcdc24_temperature = uint16((self.dcdc24_temperature + 20) * 655.35)
        return raw

class message_COOLING_STATUS:
    def __init__(
        self,
        radiators_speed = None,
        pumps_speed = None
    ):
        self.radiators_speed = uint16(radiators_speed)
        self.pumps_speed = uint16(pumps_speed)
        self.size = 4
        self.interval = 1000

    def __eq__(self, other):
        if not isinstance(other, message_COOLING_STATUS):
            return False
        if self.radiators_speed != other.radiators_speed:
            return False
        if self.pumps_speed != other.pumps_speed:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<HH", self.radiators_speed, self.pumps_speed))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.radiators_speed = uint16(unpack("<H", data[0:2])[0])
        message.pumps_speed = uint16(unpack("<xxH", data[0:4])[0])
        return message


    def convert(self) -> message_COOLING_STATUS_conversion:
        conversion = message_COOLING_STATUS_conversion()
        conversion.radiators_speed = ((float32(self.radiators_speed)) / 32767.5) - 1
        conversion.pumps_speed = ((float32(self.pumps_speed)) / 32767.5) - 1
        return conversion


class message_COOLING_STATUS_conversion:
    def __init__(
        self,
        radiators_speed = None,
        pumps_speed = None
    ):
        self.radiators_speed = float32(radiators_speed)
        self.pumps_speed = float32(pumps_speed)
        self.size = 4
        self.interval = 1000

    def __eq__(self, other):
        if not isinstance(other, message_COOLING_STATUS):
            return False
        if self.radiators_speed != other.radiators_speed:
            return False
        if self.pumps_speed != other.pumps_speed:
            return False
        return True

    def convert_to_raw(self) -> message_COOLING_STATUS:
        raw = message_COOLING_STATUS()
        raw.radiators_speed = uint16((self.radiators_speed + 1) * 32767.5)
        raw.pumps_speed = uint16((self.pumps_speed + 1) * 32767.5)
        return raw

class message_SET_RADIATOR_SPEED:
    def __init__(
        self,
        radiators_speed = None
    ):
        self.radiators_speed = uint16(radiators_speed)
        self.size = 2

    def __eq__(self, other):
        if not isinstance(other, message_SET_RADIATOR_SPEED):
            return False
        if self.radiators_speed != other.radiators_speed:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<H", self.radiators_speed))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.radiators_speed = uint16(unpack("<H", data[0:2])[0])
        return message


    def convert(self) -> message_SET_RADIATOR_SPEED_conversion:
        conversion = message_SET_RADIATOR_SPEED_conversion()
        conversion.radiators_speed = ((float32(self.radiators_speed)) / 32767.5) - 1
        return conversion


class message_SET_RADIATOR_SPEED_conversion:
    def __init__(
        self,
        radiators_speed = None
    ):
        self.radiators_speed = float32(radiators_speed)
        self.size = 2

    def __eq__(self, other):
        if not isinstance(other, message_SET_RADIATOR_SPEED):
            return False
        if self.radiators_speed != other.radiators_speed:
            return False
        return True

    def convert_to_raw(self) -> message_SET_RADIATOR_SPEED:
        raw = message_SET_RADIATOR_SPEED()
        raw.radiators_speed = uint16((self.radiators_speed + 1) * 32767.5)
        return raw

class message_SET_PUMPS_SPEED:
    def __init__(
        self,
        pumps_speed = None
    ):
        self.pumps_speed = uint16(pumps_speed)
        self.size = 2

    def __eq__(self, other):
        if not isinstance(other, message_SET_PUMPS_SPEED):
            return False
        if self.pumps_speed != other.pumps_speed:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<H", self.pumps_speed))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.pumps_speed = uint16(unpack("<H", data[0:2])[0])
        return message


    def convert(self) -> message_SET_PUMPS_SPEED_conversion:
        conversion = message_SET_PUMPS_SPEED_conversion()
        conversion.pumps_speed = ((float32(self.pumps_speed)) / 32767.5) - 1
        return conversion


class message_SET_PUMPS_SPEED_conversion:
    def __init__(
        self,
        pumps_speed = None
    ):
        self.pumps_speed = float32(pumps_speed)
        self.size = 2

    def __eq__(self, other):
        if not isinstance(other, message_SET_PUMPS_SPEED):
            return False
        if self.pumps_speed != other.pumps_speed:
            return False
        return True

    def convert_to_raw(self) -> message_SET_PUMPS_SPEED:
        raw = message_SET_PUMPS_SPEED()
        raw.pumps_speed = uint16((self.pumps_speed + 1) * 32767.5)
        return raw

class message_SET_INVERTER_CONNECTION_STATUS:
    def __init__(
        self,
        status = None
    ):
        self.status = Toggle(status)
        self.size = 1
        self.interval = 100

    def __eq__(self, other):
        if not isinstance(other, message_SET_INVERTER_CONNECTION_STATUS):
            return False
        if self.status != other.status:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<B", self.status << 7 & 255))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.status = Toggle((unpack("<B", data[0:1])[0] & 128) >> 7)
        return message


class message_INVERTER_CONNECTION_STATUS:
    def __init__(
        self,
        status = None
    ):
        self.status = Toggle(status)
        self.size = 1
        self.interval = 100

    def __eq__(self, other):
        if not isinstance(other, message_INVERTER_CONNECTION_STATUS):
            return False
        if self.status != other.status:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<B", self.status << 7 & 255))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.status = Toggle((unpack("<B", data[0:1])[0] & 128) >> 7)
        return message


class message_LV_ERRORS:
    def __init__(
        self,
        warnings = None,
        errors = None
    ):
        self.warnings = LvErrors(warnings)
        self.errors = LvErrors(errors)
        self.size = 6
        self.interval = 10

    def __eq__(self, other):
        if not isinstance(other, message_LV_ERRORS):
            return False
        if self.warnings != other.warnings:
            return False
        if self.errors != other.errors:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<BBBBBB", (int(self.warnings) >> 16) & 255, (int(self.warnings) >> 8) & 255, (int(self.warnings) >> 0) & 255, (int(self.errors) >> 16) & 255, (int(self.errors) >> 8) & 255, (int(self.errors) >> 0) & 255))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.warnings = LvErrors(int((unpack("<BBB", data[0:3])[0] << 16) | (unpack("<BBB", data[0:3])[1] << 8) | (unpack("<BBB", data[0:3])[2] << 0)))
        message.errors = LvErrors(int((unpack("<xxxBBB", data[0:6])[0] << 16) | (unpack("<xxxBBB", data[0:6])[1] << 8) | (unpack("<xxxBBB", data[0:6])[2] << 0)))
        return message


class message_SHUTDOWN_STATUS:
    def __init__(
        self,
        input = None,
        output = None
    ):
        self.input = bool(input)
        self.output = bool(output)
        self.size = 1
        self.interval = 500

    def __eq__(self, other):
        if not isinstance(other, message_SHUTDOWN_STATUS):
            return False
        if self.input != other.input:
            return False
        if self.output != other.output:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<B", self.input << 7 & 255 | self.output << 6 & 255))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.input = bool((unpack("<B", data[0:1])[0] & 128) >> 7)
        message.output = bool((unpack("<B", data[0:1])[0] & 64) >> 6)
        return message


class message_MARKER:
    def __init__(
        self
    ):
        self.size = 0

    def __eq__(self, other):
        if not isinstance(other, message_MARKER):
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend()
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        return message


class message_HV_CELLS_VOLTAGE:
    def __init__(
        self,
        start_index = None,
        voltage_0 = None,
        voltage_1 = None,
        voltage_2 = None
    ):
        self.start_index = uint8(start_index)
        self.voltage_0 = uint16(voltage_0)
        self.voltage_1 = uint16(voltage_1)
        self.voltage_2 = uint16(voltage_2)
        self.size = 7
        self.interval = 100

    def __eq__(self, other):
        if not isinstance(other, message_HV_CELLS_VOLTAGE):
            return False
        if self.start_index != other.start_index:
            return False
        if self.voltage_0 != other.voltage_0:
            return False
        if self.voltage_1 != other.voltage_1:
            return False
        if self.voltage_2 != other.voltage_2:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<HHHB", self.voltage_0, self.voltage_1, self.voltage_2, self.start_index))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.start_index = uint8(unpack("<xxxxxxB", data[0:7])[0])
        message.voltage_0 = uint16(unpack("<H", data[0:2])[0])
        message.voltage_1 = uint16(unpack("<xxH", data[0:4])[0])
        message.voltage_2 = uint16(unpack("<xxxxH", data[0:6])[0])
        return message


    def convert(self) -> message_HV_CELLS_VOLTAGE_conversion:
        conversion = message_HV_CELLS_VOLTAGE_conversion()
        conversion.start_index = self.start_index
        conversion.voltage_0 = ((float32(self.voltage_0)) / 10000.0) + 0
        conversion.voltage_1 = ((float32(self.voltage_1)) / 10000.0) + 0
        conversion.voltage_2 = ((float32(self.voltage_2)) / 10000.0) + 0
        return conversion


class message_HV_CELLS_VOLTAGE_conversion:
    def __init__(
        self,
        start_index = None,
        voltage_0 = None,
        voltage_1 = None,
        voltage_2 = None
    ):
        self.start_index = uint8(start_index)
        self.voltage_0 = float32(voltage_0)
        self.voltage_1 = float32(voltage_1)
        self.voltage_2 = float32(voltage_2)
        self.size = 7
        self.interval = 100

    def __eq__(self, other):
        if not isinstance(other, message_HV_CELLS_VOLTAGE):
            return False
        if self.start_index != other.start_index:
            return False
        if self.voltage_0 != other.voltage_0:
            return False
        if self.voltage_1 != other.voltage_1:
            return False
        if self.voltage_2 != other.voltage_2:
            return False
        return True

    def convert_to_raw(self) -> message_HV_CELLS_VOLTAGE:
        raw = message_HV_CELLS_VOLTAGE()
        raw.start_index = self.start_index
        raw.voltage_0 = uint16((self.voltage_0 + 0) * 10000.0)
        raw.voltage_1 = uint16((self.voltage_1 + 0) * 10000.0)
        raw.voltage_2 = uint16((self.voltage_2 + 0) * 10000.0)
        return raw

class message_HV_CELLS_TEMP:
    def __init__(
        self,
        start_index = None,
        temp_0 = None,
        temp_1 = None,
        temp_2 = None,
        temp_3 = None,
        temp_4 = None,
        temp_5 = None
    ):
        self.start_index = uint8(start_index)
        self.temp_0 = uint8(temp_0)
        self.temp_1 = uint8(temp_1)
        self.temp_2 = uint8(temp_2)
        self.temp_3 = uint8(temp_3)
        self.temp_4 = uint8(temp_4)
        self.temp_5 = uint8(temp_5)
        self.size = 7
        self.interval = 100

    def __eq__(self, other):
        if not isinstance(other, message_HV_CELLS_TEMP):
            return False
        if self.start_index != other.start_index:
            return False
        if self.temp_0 != other.temp_0:
            return False
        if self.temp_1 != other.temp_1:
            return False
        if self.temp_2 != other.temp_2:
            return False
        if self.temp_3 != other.temp_3:
            return False
        if self.temp_4 != other.temp_4:
            return False
        if self.temp_5 != other.temp_5:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<BBBBBBB", self.start_index, self.temp_0, self.temp_1, self.temp_2, self.temp_3, self.temp_4, self.temp_5))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.start_index = uint8(unpack("<B", data[0:1])[0])
        message.temp_0 = uint8(unpack("<xB", data[0:2])[0])
        message.temp_1 = uint8(unpack("<xxB", data[0:3])[0])
        message.temp_2 = uint8(unpack("<xxxB", data[0:4])[0])
        message.temp_3 = uint8(unpack("<xxxxB", data[0:5])[0])
        message.temp_4 = uint8(unpack("<xxxxxB", data[0:6])[0])
        message.temp_5 = uint8(unpack("<xxxxxxB", data[0:7])[0])
        return message


    def convert(self) -> message_HV_CELLS_TEMP_conversion:
        conversion = message_HV_CELLS_TEMP_conversion()
        conversion.start_index = self.start_index
        conversion.temp_0 = ((float32(self.temp_0)) / 2.55) - 20
        conversion.temp_1 = ((float32(self.temp_1)) / 2.55) - 20
        conversion.temp_2 = ((float32(self.temp_2)) / 2.55) - 20
        conversion.temp_3 = ((float32(self.temp_3)) / 2.55) - 20
        conversion.temp_4 = ((float32(self.temp_4)) / 2.55) - 20
        conversion.temp_5 = ((float32(self.temp_5)) / 2.55) - 20
        return conversion


class message_HV_CELLS_TEMP_conversion:
    def __init__(
        self,
        start_index = None,
        temp_0 = None,
        temp_1 = None,
        temp_2 = None,
        temp_3 = None,
        temp_4 = None,
        temp_5 = None
    ):
        self.start_index = uint8(start_index)
        self.temp_0 = float32(temp_0)
        self.temp_1 = float32(temp_1)
        self.temp_2 = float32(temp_2)
        self.temp_3 = float32(temp_3)
        self.temp_4 = float32(temp_4)
        self.temp_5 = float32(temp_5)
        self.size = 7
        self.interval = 100

    def __eq__(self, other):
        if not isinstance(other, message_HV_CELLS_TEMP):
            return False
        if self.start_index != other.start_index:
            return False
        if self.temp_0 != other.temp_0:
            return False
        if self.temp_1 != other.temp_1:
            return False
        if self.temp_2 != other.temp_2:
            return False
        if self.temp_3 != other.temp_3:
            return False
        if self.temp_4 != other.temp_4:
            return False
        if self.temp_5 != other.temp_5:
            return False
        return True

    def convert_to_raw(self) -> message_HV_CELLS_TEMP:
        raw = message_HV_CELLS_TEMP()
        raw.start_index = self.start_index
        raw.temp_0 = uint8((self.temp_0 + 20) * 2.55)
        raw.temp_1 = uint8((self.temp_1 + 20) * 2.55)
        raw.temp_2 = uint8((self.temp_2 + 20) * 2.55)
        raw.temp_3 = uint8((self.temp_3 + 20) * 2.55)
        raw.temp_4 = uint8((self.temp_4 + 20) * 2.55)
        raw.temp_5 = uint8((self.temp_5 + 20) * 2.55)
        return raw

class message_HV_CELL_BALANCING_STATUS:
    def __init__(
        self,
        balancing_status = None
    ):
        self.balancing_status = Toggle(balancing_status)
        self.size = 1
        self.interval = 500

    def __eq__(self, other):
        if not isinstance(other, message_HV_CELL_BALANCING_STATUS):
            return False
        if self.balancing_status != other.balancing_status:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<B", self.balancing_status << 7 & 255))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.balancing_status = Toggle((unpack("<B", data[0:1])[0] & 128) >> 7)
        return message


class message_SET_CELL_BALANCING_STATUS:
    def __init__(
        self,
        set_balancing_status = None
    ):
        self.set_balancing_status = Toggle(set_balancing_status)
        self.size = 1

    def __eq__(self, other):
        if not isinstance(other, message_SET_CELL_BALANCING_STATUS):
            return False
        if self.set_balancing_status != other.set_balancing_status:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<B", self.set_balancing_status << 7 & 255))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.set_balancing_status = Toggle((unpack("<B", data[0:1])[0] & 128) >> 7)
        return message


class message_HANDCART_STATUS:
    def __init__(
        self,
        connected = None
    ):
        self.connected = bool(connected)
        self.size = 1
        self.interval = 500

    def __eq__(self, other):
        if not isinstance(other, message_HANDCART_STATUS):
            return False
        if self.connected != other.connected:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<B", self.connected << 7 & 255))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.connected = bool((unpack("<B", data[0:1])[0] & 128) >> 7)
        return message


class message_SPEED:
    def __init__(
        self,
        encoder_r = None,
        encoder_l = None,
        inverter_r = None,
        inverter_l = None
    ):
        self.encoder_r = uint16(encoder_r)
        self.encoder_l = uint16(encoder_l)
        self.inverter_r = uint16(inverter_r)
        self.inverter_l = uint16(inverter_l)
        self.size = 8
        self.interval = 10

    def __eq__(self, other):
        if not isinstance(other, message_SPEED):
            return False
        if self.encoder_r != other.encoder_r:
            return False
        if self.encoder_l != other.encoder_l:
            return False
        if self.inverter_r != other.inverter_r:
            return False
        if self.inverter_l != other.inverter_l:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<HHHH", self.encoder_r, self.encoder_l, self.inverter_r, self.inverter_l))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.encoder_r = uint16(unpack("<H", data[0:2])[0])
        message.encoder_l = uint16(unpack("<xxH", data[0:4])[0])
        message.inverter_r = uint16(unpack("<xxxxH", data[0:6])[0])
        message.inverter_l = uint16(unpack("<xxxxxxH", data[0:8])[0])
        return message


    def convert(self) -> message_SPEED_conversion:
        conversion = message_SPEED_conversion()
        conversion.encoder_r = ((float32(self.encoder_r)) / 163.8375) - 200
        conversion.encoder_l = ((float32(self.encoder_l)) / 163.8375) - 200
        conversion.inverter_r = ((float32(self.inverter_r)) / 163.8375) - 200
        conversion.inverter_l = ((float32(self.inverter_l)) / 163.8375) - 200
        return conversion


class message_SPEED_conversion:
    def __init__(
        self,
        encoder_r = None,
        encoder_l = None,
        inverter_r = None,
        inverter_l = None
    ):
        self.encoder_r = float32(encoder_r)
        self.encoder_l = float32(encoder_l)
        self.inverter_r = float32(inverter_r)
        self.inverter_l = float32(inverter_l)
        self.size = 8
        self.interval = 10

    def __eq__(self, other):
        if not isinstance(other, message_SPEED):
            return False
        if self.encoder_r != other.encoder_r:
            return False
        if self.encoder_l != other.encoder_l:
            return False
        if self.inverter_r != other.inverter_r:
            return False
        if self.inverter_l != other.inverter_l:
            return False
        return True

    def convert_to_raw(self) -> message_SPEED:
        raw = message_SPEED()
        raw.encoder_r = uint16((self.encoder_r + 200) * 163.8375)
        raw.encoder_l = uint16((self.encoder_l + 200) * 163.8375)
        raw.inverter_r = uint16((self.inverter_r + 200) * 163.8375)
        raw.inverter_l = uint16((self.inverter_l + 200) * 163.8375)
        return raw

class message_INV_L_REQUEST:
    def __init__(
        self,
        data_0 = None,
        data_1 = None,
        data_2 = None,
        data_3 = None,
        data_4 = None,
        data_5 = None,
        data_6 = None,
        data_7 = None
    ):
        self.data_0 = uint8(data_0)
        self.data_1 = uint8(data_1)
        self.data_2 = uint8(data_2)
        self.data_3 = uint8(data_3)
        self.data_4 = uint8(data_4)
        self.data_5 = uint8(data_5)
        self.data_6 = uint8(data_6)
        self.data_7 = uint8(data_7)
        self.size = 8
        self.interval = 10

    def __eq__(self, other):
        if not isinstance(other, message_INV_L_REQUEST):
            return False
        if self.data_0 != other.data_0:
            return False
        if self.data_1 != other.data_1:
            return False
        if self.data_2 != other.data_2:
            return False
        if self.data_3 != other.data_3:
            return False
        if self.data_4 != other.data_4:
            return False
        if self.data_5 != other.data_5:
            return False
        if self.data_6 != other.data_6:
            return False
        if self.data_7 != other.data_7:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<BBBBBBBB", self.data_0, self.data_1, self.data_2, self.data_3, self.data_4, self.data_5, self.data_6, self.data_7))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.data_0 = uint8(unpack("<B", data[0:1])[0])
        message.data_1 = uint8(unpack("<xB", data[0:2])[0])
        message.data_2 = uint8(unpack("<xxB", data[0:3])[0])
        message.data_3 = uint8(unpack("<xxxB", data[0:4])[0])
        message.data_4 = uint8(unpack("<xxxxB", data[0:5])[0])
        message.data_5 = uint8(unpack("<xxxxxB", data[0:6])[0])
        message.data_6 = uint8(unpack("<xxxxxxB", data[0:7])[0])
        message.data_7 = uint8(unpack("<xxxxxxxB", data[0:8])[0])
        return message


class message_INV_R_REQUEST:
    def __init__(
        self,
        data_0 = None,
        data_1 = None,
        data_2 = None,
        data_3 = None,
        data_4 = None,
        data_5 = None,
        data_6 = None,
        data_7 = None
    ):
        self.data_0 = uint8(data_0)
        self.data_1 = uint8(data_1)
        self.data_2 = uint8(data_2)
        self.data_3 = uint8(data_3)
        self.data_4 = uint8(data_4)
        self.data_5 = uint8(data_5)
        self.data_6 = uint8(data_6)
        self.data_7 = uint8(data_7)
        self.size = 8
        self.interval = 10

    def __eq__(self, other):
        if not isinstance(other, message_INV_R_REQUEST):
            return False
        if self.data_0 != other.data_0:
            return False
        if self.data_1 != other.data_1:
            return False
        if self.data_2 != other.data_2:
            return False
        if self.data_3 != other.data_3:
            return False
        if self.data_4 != other.data_4:
            return False
        if self.data_5 != other.data_5:
            return False
        if self.data_6 != other.data_6:
            return False
        if self.data_7 != other.data_7:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<BBBBBBBB", self.data_0, self.data_1, self.data_2, self.data_3, self.data_4, self.data_5, self.data_6, self.data_7))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.data_0 = uint8(unpack("<B", data[0:1])[0])
        message.data_1 = uint8(unpack("<xB", data[0:2])[0])
        message.data_2 = uint8(unpack("<xxB", data[0:3])[0])
        message.data_3 = uint8(unpack("<xxxB", data[0:4])[0])
        message.data_4 = uint8(unpack("<xxxxB", data[0:5])[0])
        message.data_5 = uint8(unpack("<xxxxxB", data[0:6])[0])
        message.data_6 = uint8(unpack("<xxxxxxB", data[0:7])[0])
        message.data_7 = uint8(unpack("<xxxxxxxB", data[0:8])[0])
        return message


class message_INV_L_RESPONSE:
    def __init__(
        self,
        reg_id = None,
        data_0 = None,
        data_1 = None,
        data_2 = None,
        data_3 = None,
        data_4 = None,
        data_5 = None,
        data_6 = None
    ):
        self.reg_id = uint8(reg_id)
        self.data_0 = uint8(data_0)
        self.data_1 = uint8(data_1)
        self.data_2 = uint8(data_2)
        self.data_3 = uint8(data_3)
        self.data_4 = uint8(data_4)
        self.data_5 = uint8(data_5)
        self.data_6 = uint8(data_6)
        self.size = 8
        self.interval = 100

    def __eq__(self, other):
        if not isinstance(other, message_INV_L_RESPONSE):
            return False
        if self.reg_id != other.reg_id:
            return False
        if self.data_0 != other.data_0:
            return False
        if self.data_1 != other.data_1:
            return False
        if self.data_2 != other.data_2:
            return False
        if self.data_3 != other.data_3:
            return False
        if self.data_4 != other.data_4:
            return False
        if self.data_5 != other.data_5:
            return False
        if self.data_6 != other.data_6:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<BBBBBBBB", self.reg_id, self.data_0, self.data_1, self.data_2, self.data_3, self.data_4, self.data_5, self.data_6))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.reg_id = uint8(unpack("<B", data[0:1])[0])
        message.data_0 = uint8(unpack("<xB", data[0:2])[0])
        message.data_1 = uint8(unpack("<xxB", data[0:3])[0])
        message.data_2 = uint8(unpack("<xxxB", data[0:4])[0])
        message.data_3 = uint8(unpack("<xxxxB", data[0:5])[0])
        message.data_4 = uint8(unpack("<xxxxxB", data[0:6])[0])
        message.data_5 = uint8(unpack("<xxxxxxB", data[0:7])[0])
        message.data_6 = uint8(unpack("<xxxxxxxB", data[0:8])[0])
        return message


class message_INV_R_RESPONSE:
    def __init__(
        self,
        reg_id = None,
        data_0 = None,
        data_1 = None,
        data_2 = None,
        data_3 = None,
        data_4 = None,
        data_5 = None,
        data_6 = None
    ):
        self.reg_id = uint8(reg_id)
        self.data_0 = uint8(data_0)
        self.data_1 = uint8(data_1)
        self.data_2 = uint8(data_2)
        self.data_3 = uint8(data_3)
        self.data_4 = uint8(data_4)
        self.data_5 = uint8(data_5)
        self.data_6 = uint8(data_6)
        self.size = 8
        self.interval = 100

    def __eq__(self, other):
        if not isinstance(other, message_INV_R_RESPONSE):
            return False
        if self.reg_id != other.reg_id:
            return False
        if self.data_0 != other.data_0:
            return False
        if self.data_1 != other.data_1:
            return False
        if self.data_2 != other.data_2:
            return False
        if self.data_3 != other.data_3:
            return False
        if self.data_4 != other.data_4:
            return False
        if self.data_5 != other.data_5:
            return False
        if self.data_6 != other.data_6:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<BBBBBBBB", self.reg_id, self.data_0, self.data_1, self.data_2, self.data_3, self.data_4, self.data_5, self.data_6))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.reg_id = uint8(unpack("<B", data[0:1])[0])
        message.data_0 = uint8(unpack("<xB", data[0:2])[0])
        message.data_1 = uint8(unpack("<xxB", data[0:3])[0])
        message.data_2 = uint8(unpack("<xxxB", data[0:4])[0])
        message.data_3 = uint8(unpack("<xxxxB", data[0:5])[0])
        message.data_4 = uint8(unpack("<xxxxxB", data[0:6])[0])
        message.data_5 = uint8(unpack("<xxxxxxB", data[0:7])[0])
        message.data_6 = uint8(unpack("<xxxxxxxB", data[0:8])[0])
        return message


class message_FLASH_CELLBOARD_0_TX:
    def __init__(
        self
    ):
        self.size = 0

    def __eq__(self, other):
        if not isinstance(other, message_FLASH_CELLBOARD_0_TX):
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend()
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        return message


class message_FLASH_CELLBOARD_0_RX:
    def __init__(
        self
    ):
        self.size = 0

    def __eq__(self, other):
        if not isinstance(other, message_FLASH_CELLBOARD_0_RX):
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend()
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        return message


class message_FLASH_CELLBOARD_1_TX:
    def __init__(
        self
    ):
        self.size = 0

    def __eq__(self, other):
        if not isinstance(other, message_FLASH_CELLBOARD_1_TX):
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend()
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        return message


class message_FLASH_CELLBOARD_1_RX:
    def __init__(
        self
    ):
        self.size = 0

    def __eq__(self, other):
        if not isinstance(other, message_FLASH_CELLBOARD_1_RX):
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend()
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        return message


class message_FLASH_CELLBOARD_2_TX:
    def __init__(
        self
    ):
        self.size = 0

    def __eq__(self, other):
        if not isinstance(other, message_FLASH_CELLBOARD_2_TX):
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend()
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        return message


class message_FLASH_CELLBOARD_2_RX:
    def __init__(
        self
    ):
        self.size = 0

    def __eq__(self, other):
        if not isinstance(other, message_FLASH_CELLBOARD_2_RX):
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend()
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        return message


class message_FLASH_CELLBOARD_3_TX:
    def __init__(
        self
    ):
        self.size = 0

    def __eq__(self, other):
        if not isinstance(other, message_FLASH_CELLBOARD_3_TX):
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend()
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        return message


class message_FLASH_CELLBOARD_3_RX:
    def __init__(
        self
    ):
        self.size = 0

    def __eq__(self, other):
        if not isinstance(other, message_FLASH_CELLBOARD_3_RX):
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend()
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        return message


class message_FLASH_CELLBOARD_4_TX:
    def __init__(
        self
    ):
        self.size = 0

    def __eq__(self, other):
        if not isinstance(other, message_FLASH_CELLBOARD_4_TX):
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend()
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        return message


class message_FLASH_CELLBOARD_4_RX:
    def __init__(
        self
    ):
        self.size = 0

    def __eq__(self, other):
        if not isinstance(other, message_FLASH_CELLBOARD_4_RX):
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend()
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        return message


class message_FLASH_CELLBOARD_5_TX:
    def __init__(
        self
    ):
        self.size = 0

    def __eq__(self, other):
        if not isinstance(other, message_FLASH_CELLBOARD_5_TX):
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend()
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        return message


class message_FLASH_CELLBOARD_5_RX:
    def __init__(
        self
    ):
        self.size = 0

    def __eq__(self, other):
        if not isinstance(other, message_FLASH_CELLBOARD_5_RX):
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend()
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        return message


class message_FLASH_BMS_HV_TX:
    def __init__(
        self
    ):
        self.size = 0

    def __eq__(self, other):
        if not isinstance(other, message_FLASH_BMS_HV_TX):
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend()
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        return message


class message_FLASH_BMS_HV_RX:
    def __init__(
        self
    ):
        self.size = 0

    def __eq__(self, other):
        if not isinstance(other, message_FLASH_BMS_HV_RX):
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend()
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        return message


class message_FLASH_BMS_LV_TX:
    def __init__(
        self
    ):
        self.size = 0

    def __eq__(self, other):
        if not isinstance(other, message_FLASH_BMS_LV_TX):
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend()
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        return message


class message_FLASH_BMS_LV_RX:
    def __init__(
        self
    ):
        self.size = 0

    def __eq__(self, other):
        if not isinstance(other, message_FLASH_BMS_LV_RX):
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend()
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        return message


class message_BRUSA_NLG5_CTL:
    def __init__(
        self
    ):
        self.size = 0

    def __eq__(self, other):
        if not isinstance(other, message_BRUSA_NLG5_CTL):
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend()
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        return message


class message_BRUSA_ST:
    def __init__(
        self
    ):
        self.size = 0

    def __eq__(self, other):
        if not isinstance(other, message_BRUSA_ST):
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend()
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        return message


class message_BRUSA_ACT_I:
    def __init__(
        self
    ):
        self.size = 0

    def __eq__(self, other):
        if not isinstance(other, message_BRUSA_ACT_I):
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend()
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        return message


class message_BRUSA_ACT_II:
    def __init__(
        self
    ):
        self.size = 0

    def __eq__(self, other):
        if not isinstance(other, message_BRUSA_ACT_II):
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend()
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        return message


class message_BRUSA_TEMP:
    def __init__(
        self
    ):
        self.size = 0

    def __eq__(self, other):
        if not isinstance(other, message_BRUSA_TEMP):
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend()
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        return message


class message_BRUSA_ERR:
    def __init__(
        self
    ):
        self.size = 0

    def __eq__(self, other):
        if not isinstance(other, message_BRUSA_ERR):
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend()
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        return message


class message_BMS_HV_CHIMERA:
    def __init__(
        self
    ):
        self.size = 0

    def __eq__(self, other):
        if not isinstance(other, message_BMS_HV_CHIMERA):
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend()
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        return message


class message_ECU_CHIMERA:
    def __init__(
        self
    ):
        self.size = 0

    def __eq__(self, other):
        if not isinstance(other, message_ECU_CHIMERA):
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend()
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        return message

