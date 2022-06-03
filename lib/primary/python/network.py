from __future__ import annotations
from enum import IntEnum, IntFlag
from struct import pack, unpack
from typing import Any, Optional
from builtins import bool as Bool

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


class DasErrors(IntFlag):
    PEDAL_ADC = 1
    PEDAL_IMPLAUSIBILITY = 2
    IMU_TOUT = 4
    IRTS_TOUT = 8
    TS_TOUT = 16
    INVL_TOUT = 32
    INVR_TOUT = 64
    FSM = 128

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
    SETUP = 1
    RUN = 2

    @classmethod
    def _missing_(cls, _):
        return cls(0)


class Toggle(IntEnum):
    ON = 0
    OFF = 1

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


class Map(IntEnum):
    R = 0
    D20 = 1
    D40 = 2
    D60 = 3
    D80 = 4
    D100 = 5

    @classmethod
    def _missing_(cls, _):
        return cls(0)


class SetCarStatus(IntEnum):
    IDLE = 0
    RUN = 1

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


class Cooling(IntEnum):
    RADIATORS_MAX = 0
    RADIATORS_OFF = 1
    PUMPS_MAX = 2
    PUMPS_OFF = 3

    @classmethod
    def _missing_(cls, _):
        return cls(0)

# Messages


class message_STEER_VERSION:
    def __init__(
        self,
        component_version = None,
        cancicd_version = None
    ):
        self.component_version = uint8(component_version)
        self.cancicd_version = uint8(cancicd_version)
        self.size = 2
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
        data.extend(pack("<BB", self.component_version, self.cancicd_version))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.component_version = uint8(unpack("<B", data[0:1])[0])
        message.cancicd_version = uint8(unpack("<xB", data[0:2])[0])
        return message


class message_DAS_VERSION:
    def __init__(
        self,
        component_version = None,
        cancicd_version = None
    ):
        self.component_version = uint8(component_version)
        self.cancicd_version = uint8(cancicd_version)
        self.size = 2
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
        data.extend(pack("<BB", self.component_version, self.cancicd_version))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.component_version = uint8(unpack("<B", data[0:1])[0])
        message.cancicd_version = uint8(unpack("<xB", data[0:2])[0])
        return message


class message_HV_VERSION:
    def __init__(
        self,
        component_version = None,
        cancicd_version = None
    ):
        self.component_version = uint8(component_version)
        self.cancicd_version = uint8(cancicd_version)
        self.size = 2
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
        data.extend(pack("<BB", self.component_version, self.cancicd_version))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.component_version = uint8(unpack("<B", data[0:1])[0])
        message.cancicd_version = uint8(unpack("<xB", data[0:2])[0])
        return message


class message_LV_VERSION:
    def __init__(
        self,
        component_version = None,
        cancicd_version = None
    ):
        self.component_version = uint8(component_version)
        self.cancicd_version = uint8(cancicd_version)
        self.size = 2
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
        data.extend(pack("<BB", self.component_version, self.cancicd_version))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.component_version = uint8(unpack("<B", data[0:1])[0])
        message.cancicd_version = uint8(unpack("<xB", data[0:2])[0])
        return message


class message_TLM_VERSION:
    def __init__(
        self,
        component_version = None,
        cancicd_version = None
    ):
        self.component_version = uint8(component_version)
        self.cancicd_version = uint8(cancicd_version)
        self.size = 2
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
        data.extend(pack("<BB", self.component_version, self.cancicd_version))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.component_version = uint8(unpack("<B", data[0:1])[0])
        message.cancicd_version = uint8(unpack("<xB", data[0:2])[0])
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


class message_SET_TLM_STATUS:
    def __init__(
        self,
        driver = None,
        circuit = None,
        race_type = None,
        tlm_status = None
    ):
        self.driver = uint8(driver)
        self.circuit = uint8(circuit)
        self.race_type = RaceType(race_type)
        self.tlm_status = Toggle(tlm_status)
        self.size = 3

    def __eq__(self, other):
        if not isinstance(other, message_SET_TLM_STATUS):
            return False
        if self.driver != other.driver:
            return False
        if self.circuit != other.circuit:
            return False
        if self.race_type != other.race_type:
            return False
        if self.tlm_status != other.tlm_status:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<BBB", self.driver, self.circuit, self.race_type << 6 & 255 | self.tlm_status << 5 & 255))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.driver = uint8(unpack("<B", data[0:1])[0])
        message.circuit = uint8(unpack("<xB", data[0:2])[0])
        message.race_type = RaceType((unpack("<xxB", data[0:3])[0] & 192) >> 6)
        message.tlm_status = Toggle((unpack("<xxB", data[0:3])[0] & 32) >> 5)
        return message


class message_TLM_STATUS:
    def __init__(
        self,
        driver = None,
        circuit = None,
        race_type = None,
        tlm_status = None
    ):
        self.driver = uint8(driver)
        self.circuit = uint8(circuit)
        self.race_type = RaceType(race_type)
        self.tlm_status = Toggle(tlm_status)
        self.size = 3
        self.interval = 1000

    def __eq__(self, other):
        if not isinstance(other, message_TLM_STATUS):
            return False
        if self.driver != other.driver:
            return False
        if self.circuit != other.circuit:
            return False
        if self.race_type != other.race_type:
            return False
        if self.tlm_status != other.tlm_status:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<BBB", self.driver, self.circuit, self.race_type << 6 & 255 | self.tlm_status << 5 & 255))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.driver = uint8(unpack("<B", data[0:1])[0])
        message.circuit = uint8(unpack("<xB", data[0:2])[0])
        message.race_type = RaceType((unpack("<xxB", data[0:3])[0] & 192) >> 6)
        message.tlm_status = Toggle((unpack("<xxB", data[0:3])[0] & 32) >> 5)
        return message


class message_STEER_SYSTEM_STATUS:
    def __init__(
        self,
        soc_temp = None
    ):
        self.soc_temp = uint8(soc_temp)
        self.size = 1
        self.interval = 2000

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
        self.interval = 20

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
        conversion.pack_voltage = ((float32(self.pack_voltage)) / 142.469565) + 0
        conversion.bus_voltage = ((float32(self.bus_voltage)) / 142.469565) + 0
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
        self.interval = 20

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
        raw.pack_voltage = uint16((self.pack_voltage + 0) * 142.469565)
        raw.bus_voltage = uint16((self.bus_voltage + 0) * 142.469565)
        raw.max_cell_voltage = uint16((self.max_cell_voltage + 0) * 10000.0)
        raw.min_cell_voltage = uint16((self.min_cell_voltage + 0) * 10000.0)
        return raw

class message_HV_CURRENT:
    def __init__(
        self,
        current = None,
        power = None
    ):
        self.current = uint16(current)
        self.power = uint16(power)
        self.size = 4
        self.interval = 20

    def __eq__(self, other):
        if not isinstance(other, message_HV_CURRENT):
            return False
        if self.current != other.current:
            return False
        if self.power != other.power:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<HH", self.current, self.power))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.current = uint16(unpack("<H", data[0:2])[0])
        message.power = uint16(unpack("<xxH", data[0:4])[0])
        return message


    def convert(self) -> message_HV_CURRENT_conversion:
        conversion = message_HV_CURRENT_conversion()
        conversion.current = ((float32(self.current)) / 327.68) + 0
        conversion.power = ((float32(self.power)) / 655.36) + 0
        return conversion


class message_HV_CURRENT_conversion:
    def __init__(
        self,
        current = None,
        power = None
    ):
        self.current = float32(current)
        self.power = float32(power)
        self.size = 4
        self.interval = 20

    def __eq__(self, other):
        if not isinstance(other, message_HV_CURRENT):
            return False
        if self.current != other.current:
            return False
        if self.power != other.power:
            return False
        return True

    def convert_to_raw(self) -> message_HV_CURRENT:
        raw = message_HV_CURRENT()
        raw.current = uint16((self.current + 0) * 327.68)
        raw.power = uint16((self.power + 0) * 655.36)
        return raw

class message_HV_TEMP:
    def __init__(
        self,
        average_temp = None,
        max_temp = None,
        min_temp = None
    ):
        self.average_temp = uint16(average_temp)
        self.max_temp = uint16(max_temp)
        self.min_temp = uint16(min_temp)
        self.size = 6
        self.interval = 200

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
        data.extend(pack("<HHH", self.average_temp, self.max_temp, self.min_temp))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.average_temp = uint16(unpack("<H", data[0:2])[0])
        message.max_temp = uint16(unpack("<xxH", data[0:4])[0])
        message.min_temp = uint16(unpack("<xxxxH", data[0:6])[0])
        return message


    def convert(self) -> message_HV_TEMP_conversion:
        conversion = message_HV_TEMP_conversion()
        conversion.average_temp = ((float32(self.average_temp)) / 655.36) - 20
        conversion.max_temp = ((float32(self.max_temp)) / 655.36) - 20
        conversion.min_temp = ((float32(self.min_temp)) / 655.36) - 20
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
        self.size = 6
        self.interval = 200

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
        raw.average_temp = uint16((self.average_temp + 20) * 655.36)
        raw.max_temp = uint16((self.max_temp + 20) * 655.36)
        raw.min_temp = uint16((self.min_temp + 20) * 655.36)
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
        self.interval = 20

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


class message_TS_STATUS:
    def __init__(
        self,
        ts_status = None
    ):
        self.ts_status = TsStatus(ts_status)
        self.size = 1
        self.interval = 20

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
        map = None,
        traction_control = None
    ):
        self.map = Map(map)
        self.traction_control = TractionControl(traction_control)
        self.size = 1
        self.interval = 100

    def __eq__(self, other):
        if not isinstance(other, message_STEER_STATUS):
            return False
        if self.map != other.map:
            return False
        if self.traction_control != other.traction_control:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<B", self.map << 5 & 255 | self.traction_control << 3 & 255))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.map = Map((unpack("<B", data[0:1])[0] & 224) >> 5)
        message.traction_control = TractionControl((unpack("<B", data[0:1])[0] & 24) >> 3)
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
        data.extend(pack("<B", self.car_status_set << 7 & 255))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.car_status_set = SetCarStatus((unpack("<B", data[0:1])[0] & 128) >> 7)
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
        data.extend(pack("<B", self.inverter_l << 6 & 255 | self.inverter_r << 4 & 255 | self.car_status << 2 & 255))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.inverter_l = InverterStatus((unpack("<B", data[0:1])[0] & 192) >> 6)
        message.inverter_r = InverterStatus((unpack("<B", data[0:1])[0] & 48) >> 4)
        message.car_status = CarStatus((unpack("<B", data[0:1])[0] & 12) >> 2)
        return message


class message_DAS_ERRORS:
    def __init__(
        self,
        das_error = None
    ):
        self.das_error = DasErrors(das_error)
        self.size = 1
        self.interval = 20

    def __eq__(self, other):
        if not isinstance(other, message_DAS_ERRORS):
            return False
        if self.das_error != other.das_error:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<B", (int(self.das_error) >> 0) & 255))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.das_error = DasErrors(int((unpack("<B", data[0:1])[0] << 0)))
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
        conversion.current = ((float32(self.current)) / 1310.72) + 0
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
        raw.current = uint16((self.current + 0) * 1310.72)
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
        self.interval = 200

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
        self.interval = 200

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
        self.interval = 200

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
        self.interval = 200

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
        conversion.bp_temperature_1 = ((float32(self.bp_temperature_1)) / 655.36) - 20
        conversion.bp_temperature_2 = ((float32(self.bp_temperature_2)) / 655.36) - 20
        conversion.dcdc12_temperature = ((float32(self.dcdc12_temperature)) / 655.36) - 20
        conversion.dcdc24_temperature = ((float32(self.dcdc24_temperature)) / 655.36) - 20
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
        raw.bp_temperature_1 = uint16((self.bp_temperature_1 + 20) * 655.36)
        raw.bp_temperature_2 = uint16((self.bp_temperature_2 + 20) * 655.36)
        raw.dcdc12_temperature = uint16((self.dcdc12_temperature + 20) * 655.36)
        raw.dcdc24_temperature = uint16((self.dcdc24_temperature + 20) * 655.36)
        return raw

class message_COOLING_STATUS:
    def __init__(
        self,
        hv_fan_speed = None,
        lv_fan_speed = None,
        pump_speed = None
    ):
        self.hv_fan_speed = uint16(hv_fan_speed)
        self.lv_fan_speed = uint16(lv_fan_speed)
        self.pump_speed = uint16(pump_speed)
        self.size = 6
        self.interval = 1000

    def __eq__(self, other):
        if not isinstance(other, message_COOLING_STATUS):
            return False
        if self.hv_fan_speed != other.hv_fan_speed:
            return False
        if self.lv_fan_speed != other.lv_fan_speed:
            return False
        if self.pump_speed != other.pump_speed:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<HHH", self.hv_fan_speed, self.lv_fan_speed, self.pump_speed))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.hv_fan_speed = uint16(unpack("<H", data[0:2])[0])
        message.lv_fan_speed = uint16(unpack("<xxH", data[0:4])[0])
        message.pump_speed = uint16(unpack("<xxxxH", data[0:6])[0])
        return message


    def convert(self) -> message_COOLING_STATUS_conversion:
        conversion = message_COOLING_STATUS_conversion()
        conversion.hv_fan_speed = ((float32(self.hv_fan_speed)) / 65536.0) + 0
        conversion.lv_fan_speed = ((float32(self.lv_fan_speed)) / 65536.0) + 0
        conversion.pump_speed = ((float32(self.pump_speed)) / 65536.0) + 0
        return conversion


class message_COOLING_STATUS_conversion:
    def __init__(
        self,
        hv_fan_speed = None,
        lv_fan_speed = None,
        pump_speed = None
    ):
        self.hv_fan_speed = float32(hv_fan_speed)
        self.lv_fan_speed = float32(lv_fan_speed)
        self.pump_speed = float32(pump_speed)
        self.size = 6
        self.interval = 1000

    def __eq__(self, other):
        if not isinstance(other, message_COOLING_STATUS):
            return False
        if self.hv_fan_speed != other.hv_fan_speed:
            return False
        if self.lv_fan_speed != other.lv_fan_speed:
            return False
        if self.pump_speed != other.pump_speed:
            return False
        return True

    def convert_to_raw(self) -> message_COOLING_STATUS:
        raw = message_COOLING_STATUS()
        raw.hv_fan_speed = uint16((self.hv_fan_speed + 0) * 65536.0)
        raw.lv_fan_speed = uint16((self.lv_fan_speed + 0) * 65536.0)
        raw.pump_speed = uint16((self.pump_speed + 0) * 65536.0)
        return raw

class message_SET_RADIATOR_SPEED:
    def __init__(
        self,
        car_radiators_speed = None
    ):
        self.car_radiators_speed = Cooling(car_radiators_speed)
        self.size = 1

    def __eq__(self, other):
        if not isinstance(other, message_SET_RADIATOR_SPEED):
            return False
        if self.car_radiators_speed != other.car_radiators_speed:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<B", self.car_radiators_speed << 6 & 255))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.car_radiators_speed = Cooling((unpack("<B", data[0:1])[0] & 192) >> 6)
        return message


class message_SET_PUMPS_POWER:
    def __init__(
        self,
        car_pumps_power = None
    ):
        self.car_pumps_power = Cooling(car_pumps_power)
        self.size = 1

    def __eq__(self, other):
        if not isinstance(other, message_SET_PUMPS_POWER):
            return False
        if self.car_pumps_power != other.car_pumps_power:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<B", self.car_pumps_power << 6 & 255))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.car_pumps_power = Cooling((unpack("<B", data[0:1])[0] & 192) >> 6)
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
        voltage_0 = None,
        voltage_1 = None,
        voltage_2 = None,
        start_index = None
    ):
        self.voltage_0 = uint16(voltage_0)
        self.voltage_1 = uint16(voltage_1)
        self.voltage_2 = uint16(voltage_2)
        self.start_index = uint8(start_index)
        self.size = 7
        self.interval = 200

    def __eq__(self, other):
        if not isinstance(other, message_HV_CELLS_VOLTAGE):
            return False
        if self.voltage_0 != other.voltage_0:
            return False
        if self.voltage_1 != other.voltage_1:
            return False
        if self.voltage_2 != other.voltage_2:
            return False
        if self.start_index != other.start_index:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<HHHB", self.voltage_0, self.voltage_1, self.voltage_2, self.start_index))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.voltage_0 = uint16(unpack("<H", data[0:2])[0])
        message.voltage_1 = uint16(unpack("<xxH", data[0:4])[0])
        message.voltage_2 = uint16(unpack("<xxxxH", data[0:6])[0])
        message.start_index = uint8(unpack("<xxxxxxB", data[0:7])[0])
        return message


    def convert(self) -> message_HV_CELLS_VOLTAGE_conversion:
        conversion = message_HV_CELLS_VOLTAGE_conversion()
        conversion.voltage_0 = ((float32(self.voltage_0)) / 10000.0) + 0
        conversion.voltage_1 = ((float32(self.voltage_1)) / 10000.0) + 0
        conversion.voltage_2 = ((float32(self.voltage_2)) / 10000.0) + 0
        conversion.start_index = self.start_index
        return conversion


class message_HV_CELLS_VOLTAGE_conversion:
    def __init__(
        self,
        voltage_0 = None,
        voltage_1 = None,
        voltage_2 = None,
        start_index = None
    ):
        self.voltage_0 = float32(voltage_0)
        self.voltage_1 = float32(voltage_1)
        self.voltage_2 = float32(voltage_2)
        self.start_index = uint8(start_index)
        self.size = 7
        self.interval = 200

    def __eq__(self, other):
        if not isinstance(other, message_HV_CELLS_VOLTAGE):
            return False
        if self.voltage_0 != other.voltage_0:
            return False
        if self.voltage_1 != other.voltage_1:
            return False
        if self.voltage_2 != other.voltage_2:
            return False
        if self.start_index != other.start_index:
            return False
        return True

    def convert_to_raw(self) -> message_HV_CELLS_VOLTAGE:
        raw = message_HV_CELLS_VOLTAGE()
        raw.voltage_0 = uint16((self.voltage_0 + 0) * 10000.0)
        raw.voltage_1 = uint16((self.voltage_1 + 0) * 10000.0)
        raw.voltage_2 = uint16((self.voltage_2 + 0) * 10000.0)
        raw.start_index = self.start_index
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
        temp_5 = None,
        temp_6 = None
    ):
        self.start_index = uint8(start_index)
        self.temp_0 = uint8(temp_0)
        self.temp_1 = uint8(temp_1)
        self.temp_2 = uint8(temp_2)
        self.temp_3 = uint8(temp_3)
        self.temp_4 = uint8(temp_4)
        self.temp_5 = uint8(temp_5)
        self.temp_6 = uint8(temp_6)
        self.size = 8
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
        if self.temp_6 != other.temp_6:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<BBBBBBBB", self.start_index, self.temp_0, self.temp_1, self.temp_2, self.temp_3, self.temp_4, self.temp_5, self.temp_6))
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
        message.temp_6 = uint8(unpack("<xxxxxxxB", data[0:8])[0])
        return message


    def convert(self) -> message_HV_CELLS_TEMP_conversion:
        conversion = message_HV_CELLS_TEMP_conversion()
        conversion.start_index = self.start_index
        conversion.temp_0 = ((float32(self.temp_0)) / 2.56) - 20
        conversion.temp_1 = ((float32(self.temp_1)) / 2.56) - 20
        conversion.temp_2 = ((float32(self.temp_2)) / 2.56) - 20
        conversion.temp_3 = ((float32(self.temp_3)) / 2.56) - 20
        conversion.temp_4 = ((float32(self.temp_4)) / 2.56) - 20
        conversion.temp_5 = ((float32(self.temp_5)) / 2.56) - 20
        conversion.temp_6 = ((float32(self.temp_6)) / 2.56) - 20
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
        temp_5 = None,
        temp_6 = None
    ):
        self.start_index = uint8(start_index)
        self.temp_0 = float32(temp_0)
        self.temp_1 = float32(temp_1)
        self.temp_2 = float32(temp_2)
        self.temp_3 = float32(temp_3)
        self.temp_4 = float32(temp_4)
        self.temp_5 = float32(temp_5)
        self.temp_6 = float32(temp_6)
        self.size = 8
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
        if self.temp_6 != other.temp_6:
            return False
        return True

    def convert_to_raw(self) -> message_HV_CELLS_TEMP:
        raw = message_HV_CELLS_TEMP()
        raw.start_index = self.start_index
        raw.temp_0 = uint8((self.temp_0 + 20) * 2.56)
        raw.temp_1 = uint8((self.temp_1 + 20) * 2.56)
        raw.temp_2 = uint8((self.temp_2 + 20) * 2.56)
        raw.temp_3 = uint8((self.temp_3 + 20) * 2.56)
        raw.temp_4 = uint8((self.temp_4 + 20) * 2.56)
        raw.temp_5 = uint8((self.temp_5 + 20) * 2.56)
        raw.temp_6 = uint8((self.temp_6 + 20) * 2.56)
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
        self.encoder_r = uint8(encoder_r)
        self.encoder_l = uint8(encoder_l)
        self.inverter_r = uint8(inverter_r)
        self.inverter_l = uint8(inverter_l)
        self.size = 4
        self.interval = 100

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
        data.extend(pack("<BBBB", self.encoder_r, self.encoder_l, self.inverter_r, self.inverter_l))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.encoder_r = uint8(unpack("<B", data[0:1])[0])
        message.encoder_l = uint8(unpack("<xB", data[0:2])[0])
        message.inverter_r = uint8(unpack("<xxB", data[0:3])[0])
        message.inverter_l = uint8(unpack("<xxxB", data[0:4])[0])
        return message


    def convert(self) -> message_SPEED_conversion:
        conversion = message_SPEED_conversion()
        conversion.encoder_r = ((float32(self.encoder_r)) / 0.731429) - 70
        conversion.encoder_l = ((float32(self.encoder_l)) / 0.731429) - 70
        conversion.inverter_r = ((float32(self.inverter_r)) / 0.731429) - 70
        conversion.inverter_l = ((float32(self.inverter_l)) / 0.731429) - 70
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
        self.size = 4
        self.interval = 100

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
        raw.encoder_r = uint8((self.encoder_r + 70) * 0.731429)
        raw.encoder_l = uint8((self.encoder_l + 70) * 0.731429)
        raw.inverter_r = uint8((self.inverter_r + 70) * 0.731429)
        raw.inverter_l = uint8((self.inverter_l + 70) * 0.731429)
        return raw

class message_INV_L_SET_TORQUE:
    def __init__(
        self,
        reg_id = None,
        lsb = None,
        msb = None
    ):
        self.reg_id = uint8(reg_id)
        self.lsb = uint8(lsb)
        self.msb = uint8(msb)
        self.size = 3
        self.interval = 20

    def __eq__(self, other):
        if not isinstance(other, message_INV_L_SET_TORQUE):
            return False
        if self.reg_id != other.reg_id:
            return False
        if self.lsb != other.lsb:
            return False
        if self.msb != other.msb:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<BBB", self.reg_id, self.lsb, self.msb))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.reg_id = uint8(unpack("<B", data[0:1])[0])
        message.lsb = uint8(unpack("<xB", data[0:2])[0])
        message.msb = uint8(unpack("<xxB", data[0:3])[0])
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

