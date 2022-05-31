from enum import IntEnum, IntFlag
from struct import pack, unpack
from typing import Any

def int8(value: Any) -> int:
    return int(value)

def uint8(value: Any) -> int:
    return int(value)

def int16(value: Any) -> int:
    return int(value)

def uint16(value: Any) -> int:
    return int(value)

def int32(value: Any) -> int:
    return int(value)

def uint32(value: Any) -> int:
    return int(value)

def int64(value: Any) -> int:
    return int(value)

def uint64(value: Any) -> int:
    return int(value)

def float32(value: Any) -> float:
    return float(value)

def float64(value: Any) -> float:
    return float(value)

def bool(value: Any) -> bool:
    return bool(value)


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

class DasErrors(IntFlag):
    PEDAL_ADC = 1
    PEDAL_IMPLAUSIBILITY = 2
    IMU_TOUT = 4
    IRTS_TOUT = 8
    TS_TOUT = 16
    INVL_TOUT = 32
    INVR_TOUT = 64
    FSM = 128

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

# Enums

class RaceType(IntEnum):
    ACCELERATION = 0
    SKIDPAD = 1
    AUTOCROSS = 2
    ENDURANCE = 3

class InverterStatus(IntEnum):
    OFF = 0
    IDLE = 1
    ON = 2

class CarStatus(IntEnum):
    IDLE = 0
    SETUP = 1
    RUN = 2

class Toggle(IntEnum):
    ON = 0
    OFF = 1

class TractionControl(IntEnum):
    OFF = 0
    SLIP_CONTROL = 1
    TORQUE_VECTORING = 2
    COMPLETE = 3

class TsStatus(IntEnum):
    OFF = 0
    PRECHARGE = 1
    ON = 2
    FATAL = 3

class Map(IntEnum):
    R = 0
    D20 = 1
    D40 = 2
    D60 = 3
    D80 = 4
    D100 = 5

class SetCarStatus(IntEnum):
    IDLE = 0
    RUN = 1

class Bound(IntEnum):
    SET_MAX = 0
    SET_MIN = 1

class Pedal(IntEnum):
    ACCELERATOR = 0
    BRAKE = 1

# Messages


class message_STEER_VERSION:
    def __init__(
        self,
        component_version = None,
        cancicd_version = None
    ):
        self.component_version = uint8(component_version) if component_version is not None else None
        self.cancicd_version = uint8(cancicd_version) if cancicd_version is not None else None
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



def serialize_STEER_VERSION(message: message_STEER_VERSION) -> bytearray:
    data = bytearray()
    data.extend(pack("<BB", message.component_version, message.cancicd_version))
    return data

def deserialize_STEER_VERSION(data: bytearray) -> message_STEER_VERSION:
    message = message_STEER_VERSION()
    message.component_version = uint8(unpack("<B", data[0:1])[0])
    message.cancicd_version = uint8(unpack("<xB", data[0:2])[0])
    return message


class message_DAS_VERSION:
    def __init__(
        self,
        component_version = None,
        cancicd_version = None
    ):
        self.component_version = uint8(component_version) if component_version is not None else None
        self.cancicd_version = uint8(cancicd_version) if cancicd_version is not None else None
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



def serialize_DAS_VERSION(message: message_DAS_VERSION) -> bytearray:
    data = bytearray()
    data.extend(pack("<BB", message.component_version, message.cancicd_version))
    return data

def deserialize_DAS_VERSION(data: bytearray) -> message_DAS_VERSION:
    message = message_DAS_VERSION()
    message.component_version = uint8(unpack("<B", data[0:1])[0])
    message.cancicd_version = uint8(unpack("<xB", data[0:2])[0])
    return message


class message_HV_VERSION:
    def __init__(
        self,
        component_version = None,
        cancicd_version = None
    ):
        self.component_version = uint8(component_version) if component_version is not None else None
        self.cancicd_version = uint8(cancicd_version) if cancicd_version is not None else None
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



def serialize_HV_VERSION(message: message_HV_VERSION) -> bytearray:
    data = bytearray()
    data.extend(pack("<BB", message.component_version, message.cancicd_version))
    return data

def deserialize_HV_VERSION(data: bytearray) -> message_HV_VERSION:
    message = message_HV_VERSION()
    message.component_version = uint8(unpack("<B", data[0:1])[0])
    message.cancicd_version = uint8(unpack("<xB", data[0:2])[0])
    return message


class message_LV_VERSION:
    def __init__(
        self,
        component_version = None,
        cancicd_version = None
    ):
        self.component_version = uint8(component_version) if component_version is not None else None
        self.cancicd_version = uint8(cancicd_version) if cancicd_version is not None else None
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



def serialize_LV_VERSION(message: message_LV_VERSION) -> bytearray:
    data = bytearray()
    data.extend(pack("<BB", message.component_version, message.cancicd_version))
    return data

def deserialize_LV_VERSION(data: bytearray) -> message_LV_VERSION:
    message = message_LV_VERSION()
    message.component_version = uint8(unpack("<B", data[0:1])[0])
    message.cancicd_version = uint8(unpack("<xB", data[0:2])[0])
    return message


class message_TLM_VERSION:
    def __init__(
        self,
        component_version = None,
        cancicd_version = None
    ):
        self.component_version = uint8(component_version) if component_version is not None else None
        self.cancicd_version = uint8(cancicd_version) if cancicd_version is not None else None
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



def serialize_TLM_VERSION(message: message_TLM_VERSION) -> bytearray:
    data = bytearray()
    data.extend(pack("<BB", message.component_version, message.cancicd_version))
    return data

def deserialize_TLM_VERSION(data: bytearray) -> message_TLM_VERSION:
    message = message_TLM_VERSION()
    message.component_version = uint8(unpack("<B", data[0:1])[0])
    message.cancicd_version = uint8(unpack("<xB", data[0:2])[0])
    return message


class message_TIMESTAMP:
    def __init__(
        self,
        timestamp = None
    ):
        self.timestamp = uint32(timestamp) if timestamp is not None else None
        self.size = 4
        self.interval = 1000

    def __eq__(self, other):
        if not isinstance(other, message_TIMESTAMP):
            return False
        if self.timestamp != other.timestamp:
            return False
        return True



def serialize_TIMESTAMP(message: message_TIMESTAMP) -> bytearray:
    data = bytearray()
    data.extend(pack("<I", message.timestamp))
    return data

def deserialize_TIMESTAMP(data: bytearray) -> message_TIMESTAMP:
    message = message_TIMESTAMP()
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
        self.driver = uint8(driver) if driver is not None else None
        self.circuit = uint8(circuit) if circuit is not None else None
        self.race_type = RaceType(race_type) if race_type is not None else None
        self.tlm_status = Toggle(tlm_status) if tlm_status is not None else None
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



def serialize_SET_TLM_STATUS(message: message_SET_TLM_STATUS) -> bytearray:
    data = bytearray()
    data.extend(pack("<BBB", message.driver, message.circuit, message.race_type << 6 & 255 | message.tlm_status << 5 & 255))
    return data

def deserialize_SET_TLM_STATUS(data: bytearray) -> message_SET_TLM_STATUS:
    message = message_SET_TLM_STATUS()
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
        self.driver = uint8(driver) if driver is not None else None
        self.circuit = uint8(circuit) if circuit is not None else None
        self.race_type = RaceType(race_type) if race_type is not None else None
        self.tlm_status = Toggle(tlm_status) if tlm_status is not None else None
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



def serialize_TLM_STATUS(message: message_TLM_STATUS) -> bytearray:
    data = bytearray()
    data.extend(pack("<BBB", message.driver, message.circuit, message.race_type << 6 & 255 | message.tlm_status << 5 & 255))
    return data

def deserialize_TLM_STATUS(data: bytearray) -> message_TLM_STATUS:
    message = message_TLM_STATUS()
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
        self.soc_temp = uint8(soc_temp) if soc_temp is not None else None
        self.size = 1
        self.interval = 2000

    def __eq__(self, other):
        if not isinstance(other, message_STEER_SYSTEM_STATUS):
            return False
        if self.soc_temp != other.soc_temp:
            return False
        return True



def serialize_STEER_SYSTEM_STATUS(message: message_STEER_SYSTEM_STATUS) -> bytearray:
    data = bytearray()
    data.extend(pack("<B", message.soc_temp))
    return data

def deserialize_STEER_SYSTEM_STATUS(data: bytearray) -> message_STEER_SYSTEM_STATUS:
    message = message_STEER_SYSTEM_STATUS()
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
        self.pack_voltage = uint16(pack_voltage) if pack_voltage is not None else None
        self.bus_voltage = uint16(bus_voltage) if bus_voltage is not None else None
        self.max_cell_voltage = uint16(max_cell_voltage) if max_cell_voltage is not None else None
        self.min_cell_voltage = uint16(min_cell_voltage) if min_cell_voltage is not None else None
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

class message_HV_VOLTAGE_conversion(message_HV_VOLTAGE):
    pass

def raw_to_conversion_HV_VOLTAGE(raw: message_HV_VOLTAGE) -> message_HV_VOLTAGE_conversion:
    conversion = message_HV_VOLTAGE_conversion()
    conversion.pack_voltage = ((float32(raw.pack_voltage)) / 142.469565) + 0
    conversion.bus_voltage = ((float32(raw.bus_voltage)) / 142.469565) + 0
    conversion.max_cell_voltage = ((float32(raw.max_cell_voltage)) / 10000.0) + 0
    conversion.min_cell_voltage = ((float32(raw.min_cell_voltage)) / 10000.0) + 0
    return conversion

def conversion_to_raw_HV_VOLTAGE(conversion: message_HV_VOLTAGE_conversion) -> message_HV_VOLTAGE:
    raw = message_HV_VOLTAGE()
    raw.pack_voltage = uint16((conversion.pack_voltage + 0) * 142.469565)
    raw.bus_voltage = uint16((conversion.bus_voltage + 0) * 142.469565)
    raw.max_cell_voltage = uint16((conversion.max_cell_voltage + 0) * 10000.0)
    raw.min_cell_voltage = uint16((conversion.min_cell_voltage + 0) * 10000.0)
    return raw

def serialize_HV_VOLTAGE(message: message_HV_VOLTAGE) -> bytearray:
    data = bytearray()
    data.extend(pack("<HHHH", message.pack_voltage, message.bus_voltage, message.max_cell_voltage, message.min_cell_voltage))
    return data

def deserialize_HV_VOLTAGE(data: bytearray) -> message_HV_VOLTAGE:
    message = message_HV_VOLTAGE()
    message.pack_voltage = uint16(unpack("<H", data[0:2])[0])
    message.bus_voltage = uint16(unpack("<xxH", data[0:4])[0])
    message.max_cell_voltage = uint16(unpack("<xxxxH", data[0:6])[0])
    message.min_cell_voltage = uint16(unpack("<xxxxxxH", data[0:8])[0])
    return message


class message_HV_CURRENT:
    def __init__(
        self,
        current = None,
        power = None
    ):
        self.current = uint16(current) if current is not None else None
        self.power = uint16(power) if power is not None else None
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

class message_HV_CURRENT_conversion(message_HV_CURRENT):
    pass

def raw_to_conversion_HV_CURRENT(raw: message_HV_CURRENT) -> message_HV_CURRENT_conversion:
    conversion = message_HV_CURRENT_conversion()
    conversion.current = ((float32(raw.current)) / 327.68) + 0
    conversion.power = ((float32(raw.power)) / 655.36) + 0
    return conversion

def conversion_to_raw_HV_CURRENT(conversion: message_HV_CURRENT_conversion) -> message_HV_CURRENT:
    raw = message_HV_CURRENT()
    raw.current = uint16((conversion.current + 0) * 327.68)
    raw.power = uint16((conversion.power + 0) * 655.36)
    return raw

def serialize_HV_CURRENT(message: message_HV_CURRENT) -> bytearray:
    data = bytearray()
    data.extend(pack("<HH", message.current, message.power))
    return data

def deserialize_HV_CURRENT(data: bytearray) -> message_HV_CURRENT:
    message = message_HV_CURRENT()
    message.current = uint16(unpack("<H", data[0:2])[0])
    message.power = uint16(unpack("<xxH", data[0:4])[0])
    return message


class message_HV_TEMP:
    def __init__(
        self,
        average_temp = None,
        max_temp = None,
        min_temp = None
    ):
        self.average_temp = uint16(average_temp) if average_temp is not None else None
        self.max_temp = uint16(max_temp) if max_temp is not None else None
        self.min_temp = uint16(min_temp) if min_temp is not None else None
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

class message_HV_TEMP_conversion(message_HV_TEMP):
    pass

def raw_to_conversion_HV_TEMP(raw: message_HV_TEMP) -> message_HV_TEMP_conversion:
    conversion = message_HV_TEMP_conversion()
    conversion.average_temp = ((float32(raw.average_temp)) / 655.36) - 20
    conversion.max_temp = ((float32(raw.max_temp)) / 655.36) - 20
    conversion.min_temp = ((float32(raw.min_temp)) / 655.36) - 20
    return conversion

def conversion_to_raw_HV_TEMP(conversion: message_HV_TEMP_conversion) -> message_HV_TEMP:
    raw = message_HV_TEMP()
    raw.average_temp = uint16((conversion.average_temp + 20) * 655.36)
    raw.max_temp = uint16((conversion.max_temp + 20) * 655.36)
    raw.min_temp = uint16((conversion.min_temp + 20) * 655.36)
    return raw

def serialize_HV_TEMP(message: message_HV_TEMP) -> bytearray:
    data = bytearray()
    data.extend(pack("<HHH", message.average_temp, message.max_temp, message.min_temp))
    return data

def deserialize_HV_TEMP(data: bytearray) -> message_HV_TEMP:
    message = message_HV_TEMP()
    message.average_temp = uint16(unpack("<H", data[0:2])[0])
    message.max_temp = uint16(unpack("<xxH", data[0:4])[0])
    message.min_temp = uint16(unpack("<xxxxH", data[0:6])[0])
    return message


class message_HV_ERRORS:
    def __init__(
        self,
        warnings = None,
        errors = None
    ):
        self.warnings = HvErrors(warnings) if warnings is not None else None
        self.errors = HvErrors(errors) if errors is not None else None
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



def serialize_HV_ERRORS(message: message_HV_ERRORS) -> bytearray:
    data = bytearray()
    data.extend(pack("<BBBB", (int(message.warnings) >> 8) & 255, (int(message.warnings) >> 0) & 255, (int(message.errors) >> 8) & 255, (int(message.errors) >> 0) & 255))
    return data

def deserialize_HV_ERRORS(data: bytearray) -> message_HV_ERRORS:
    message = message_HV_ERRORS()
    message.warnings = HvErrors(int((unpack("<BB", data[0:2])[0] << 8) | (unpack("<BB", data[0:2])[1] << 0)))
    message.errors = HvErrors(int((unpack("<xxBB", data[0:4])[0] << 8) | (unpack("<xxBB", data[0:4])[1] << 0)))
    return message


class message_TS_STATUS:
    def __init__(
        self,
        ts_status = None
    ):
        self.ts_status = TsStatus(ts_status) if ts_status is not None else None
        self.size = 1
        self.interval = 20

    def __eq__(self, other):
        if not isinstance(other, message_TS_STATUS):
            return False
        if self.ts_status != other.ts_status:
            return False
        return True



def serialize_TS_STATUS(message: message_TS_STATUS) -> bytearray:
    data = bytearray()
    data.extend(pack("<B", message.ts_status << 6 & 255))
    return data

def deserialize_TS_STATUS(data: bytearray) -> message_TS_STATUS:
    message = message_TS_STATUS()
    message.ts_status = TsStatus((unpack("<B", data[0:1])[0] & 192) >> 6)
    return message


class message_SET_TS_STATUS:
    def __init__(
        self,
        ts_status_set = None
    ):
        self.ts_status_set = Toggle(ts_status_set) if ts_status_set is not None else None
        self.size = 1

    def __eq__(self, other):
        if not isinstance(other, message_SET_TS_STATUS):
            return False
        if self.ts_status_set != other.ts_status_set:
            return False
        return True



def serialize_SET_TS_STATUS(message: message_SET_TS_STATUS) -> bytearray:
    data = bytearray()
    data.extend(pack("<B", message.ts_status_set << 7 & 255))
    return data

def deserialize_SET_TS_STATUS(data: bytearray) -> message_SET_TS_STATUS:
    message = message_SET_TS_STATUS()
    message.ts_status_set = Toggle((unpack("<B", data[0:1])[0] & 128) >> 7)
    return message


class message_STEER_STATUS:
    def __init__(
        self,
        map = None,
        traction_control = None
    ):
        self.map = Map(map) if map is not None else None
        self.traction_control = TractionControl(traction_control) if traction_control is not None else None
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



def serialize_STEER_STATUS(message: message_STEER_STATUS) -> bytearray:
    data = bytearray()
    data.extend(pack("<B", message.map << 5 & 255 | message.traction_control << 3 & 255))
    return data

def deserialize_STEER_STATUS(data: bytearray) -> message_STEER_STATUS:
    message = message_STEER_STATUS()
    message.map = Map((unpack("<B", data[0:1])[0] & 224) >> 5)
    message.traction_control = TractionControl((unpack("<B", data[0:1])[0] & 24) >> 3)
    return message


class message_SET_CAR_STATUS:
    def __init__(
        self,
        car_status_set = None
    ):
        self.car_status_set = SetCarStatus(car_status_set) if car_status_set is not None else None
        self.size = 1

    def __eq__(self, other):
        if not isinstance(other, message_SET_CAR_STATUS):
            return False
        if self.car_status_set != other.car_status_set:
            return False
        return True



def serialize_SET_CAR_STATUS(message: message_SET_CAR_STATUS) -> bytearray:
    data = bytearray()
    data.extend(pack("<B", message.car_status_set << 7 & 255))
    return data

def deserialize_SET_CAR_STATUS(data: bytearray) -> message_SET_CAR_STATUS:
    message = message_SET_CAR_STATUS()
    message.car_status_set = SetCarStatus((unpack("<B", data[0:1])[0] & 128) >> 7)
    return message


class message_SET_PEDALS_RANGE:
    def __init__(
        self,
        bound = None,
        pedal = None
    ):
        self.bound = Bound(bound) if bound is not None else None
        self.pedal = Pedal(pedal) if pedal is not None else None
        self.size = 1

    def __eq__(self, other):
        if not isinstance(other, message_SET_PEDALS_RANGE):
            return False
        if self.bound != other.bound:
            return False
        if self.pedal != other.pedal:
            return False
        return True



def serialize_SET_PEDALS_RANGE(message: message_SET_PEDALS_RANGE) -> bytearray:
    data = bytearray()
    data.extend(pack("<B", message.bound << 7 & 255 | message.pedal << 6 & 255))
    return data

def deserialize_SET_PEDALS_RANGE(data: bytearray) -> message_SET_PEDALS_RANGE:
    message = message_SET_PEDALS_RANGE()
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
        self.inverter_l = InverterStatus(inverter_l) if inverter_l is not None else None
        self.inverter_r = InverterStatus(inverter_r) if inverter_r is not None else None
        self.car_status = CarStatus(car_status) if car_status is not None else None
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



def serialize_CAR_STATUS(message: message_CAR_STATUS) -> bytearray:
    data = bytearray()
    data.extend(pack("<B", message.inverter_l << 6 & 255 | message.inverter_r << 4 & 255 | message.car_status << 2 & 255))
    return data

def deserialize_CAR_STATUS(data: bytearray) -> message_CAR_STATUS:
    message = message_CAR_STATUS()
    message.inverter_l = InverterStatus((unpack("<B", data[0:1])[0] & 192) >> 6)
    message.inverter_r = InverterStatus((unpack("<B", data[0:1])[0] & 48) >> 4)
    message.car_status = CarStatus((unpack("<B", data[0:1])[0] & 12) >> 2)
    return message


class message_DAS_ERRORS:
    def __init__(
        self,
        das_error = None
    ):
        self.das_error = DasErrors(das_error) if das_error is not None else None
        self.size = 1
        self.interval = 20

    def __eq__(self, other):
        if not isinstance(other, message_DAS_ERRORS):
            return False
        if self.das_error != other.das_error:
            return False
        return True



def serialize_DAS_ERRORS(message: message_DAS_ERRORS) -> bytearray:
    data = bytearray()
    data.extend(pack("<B", (int(message.das_error) >> 0) & 255))
    return data

def deserialize_DAS_ERRORS(data: bytearray) -> message_DAS_ERRORS:
    message = message_DAS_ERRORS()
    message.das_error = DasErrors(int((unpack("<B", data[0:1])[0] << 0)))
    return message


class message_LV_CURRENT:
    def __init__(
        self,
        current = None
    ):
        self.current = uint8(current) if current is not None else None
        self.size = 1
        self.interval = 500

    def __eq__(self, other):
        if not isinstance(other, message_LV_CURRENT):
            return False
        if self.current != other.current:
            return False
        return True



def serialize_LV_CURRENT(message: message_LV_CURRENT) -> bytearray:
    data = bytearray()
    data.extend(pack("<B", message.current))
    return data

def deserialize_LV_CURRENT(data: bytearray) -> message_LV_CURRENT:
    message = message_LV_CURRENT()
    message.current = uint8(unpack("<B", data[0:1])[0])
    return message


class message_LV_VOLTAGE:
    def __init__(
        self,
        voltage_1 = None,
        voltage_2 = None,
        voltage_3 = None,
        voltage_4 = None
    ):
        self.voltage_1 = uint8(voltage_1) if voltage_1 is not None else None
        self.voltage_2 = uint8(voltage_2) if voltage_2 is not None else None
        self.voltage_3 = uint8(voltage_3) if voltage_3 is not None else None
        self.voltage_4 = uint8(voltage_4) if voltage_4 is not None else None
        self.size = 4
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



def serialize_LV_VOLTAGE(message: message_LV_VOLTAGE) -> bytearray:
    data = bytearray()
    data.extend(pack("<BBBB", message.voltage_1, message.voltage_2, message.voltage_3, message.voltage_4))
    return data

def deserialize_LV_VOLTAGE(data: bytearray) -> message_LV_VOLTAGE:
    message = message_LV_VOLTAGE()
    message.voltage_1 = uint8(unpack("<B", data[0:1])[0])
    message.voltage_2 = uint8(unpack("<xB", data[0:2])[0])
    message.voltage_3 = uint8(unpack("<xxB", data[0:3])[0])
    message.voltage_4 = uint8(unpack("<xxxB", data[0:4])[0])
    return message


class message_LV_TOTAL_VOLTAGE:
    def __init__(
        self,
        total_voltage = None
    ):
        self.total_voltage = uint16(total_voltage) if total_voltage is not None else None
        self.size = 2
        self.interval = 200

    def __eq__(self, other):
        if not isinstance(other, message_LV_TOTAL_VOLTAGE):
            return False
        if self.total_voltage != other.total_voltage:
            return False
        return True



def serialize_LV_TOTAL_VOLTAGE(message: message_LV_TOTAL_VOLTAGE) -> bytearray:
    data = bytearray()
    data.extend(pack("<H", message.total_voltage))
    return data

def deserialize_LV_TOTAL_VOLTAGE(data: bytearray) -> message_LV_TOTAL_VOLTAGE:
    message = message_LV_TOTAL_VOLTAGE()
    message.total_voltage = uint16(unpack("<H", data[0:2])[0])
    return message


class message_LV_TEMPERATURE:
    def __init__(
        self,
        bp_temperature = None,
        dcdc_temperature = None
    ):
        self.bp_temperature = uint8(bp_temperature) if bp_temperature is not None else None
        self.dcdc_temperature = uint8(dcdc_temperature) if dcdc_temperature is not None else None
        self.size = 2
        self.interval = 200

    def __eq__(self, other):
        if not isinstance(other, message_LV_TEMPERATURE):
            return False
        if self.bp_temperature != other.bp_temperature:
            return False
        if self.dcdc_temperature != other.dcdc_temperature:
            return False
        return True



def serialize_LV_TEMPERATURE(message: message_LV_TEMPERATURE) -> bytearray:
    data = bytearray()
    data.extend(pack("<BB", message.bp_temperature, message.dcdc_temperature))
    return data

def deserialize_LV_TEMPERATURE(data: bytearray) -> message_LV_TEMPERATURE:
    message = message_LV_TEMPERATURE()
    message.bp_temperature = uint8(unpack("<B", data[0:1])[0])
    message.dcdc_temperature = uint8(unpack("<xB", data[0:2])[0])
    return message


class message_COOLING_STATUS:
    def __init__(
        self,
        hv_fan_speed = None,
        lv_fan_speed = None,
        pump_speed = None
    ):
        self.hv_fan_speed = uint8(hv_fan_speed) if hv_fan_speed is not None else None
        self.lv_fan_speed = uint8(lv_fan_speed) if lv_fan_speed is not None else None
        self.pump_speed = uint8(pump_speed) if pump_speed is not None else None
        self.size = 3
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



def serialize_COOLING_STATUS(message: message_COOLING_STATUS) -> bytearray:
    data = bytearray()
    data.extend(pack("<BBB", message.hv_fan_speed, message.lv_fan_speed, message.pump_speed))
    return data

def deserialize_COOLING_STATUS(data: bytearray) -> message_COOLING_STATUS:
    message = message_COOLING_STATUS()
    message.hv_fan_speed = uint8(unpack("<B", data[0:1])[0])
    message.lv_fan_speed = uint8(unpack("<xB", data[0:2])[0])
    message.pump_speed = uint8(unpack("<xxB", data[0:3])[0])
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



def serialize_MARKER(message: message_MARKER) -> bytearray:
    data = bytearray()
    data.extend()
    return data

def deserialize_MARKER(data: bytearray) -> message_MARKER:
    message = message_MARKER()
    return message


class message_HV_CELLS_VOLTAGE:
    def __init__(
        self,
        voltage_0 = None,
        voltage_1 = None,
        voltage_2 = None,
        start_index = None
    ):
        self.voltage_0 = uint16(voltage_0) if voltage_0 is not None else None
        self.voltage_1 = uint16(voltage_1) if voltage_1 is not None else None
        self.voltage_2 = uint16(voltage_2) if voltage_2 is not None else None
        self.start_index = uint8(start_index) if start_index is not None else None
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

class message_HV_CELLS_VOLTAGE_conversion(message_HV_CELLS_VOLTAGE):
    pass

def raw_to_conversion_HV_CELLS_VOLTAGE(raw: message_HV_CELLS_VOLTAGE) -> message_HV_CELLS_VOLTAGE_conversion:
    conversion = message_HV_CELLS_VOLTAGE_conversion()
    conversion.voltage_0 = ((float32(raw.voltage_0)) / 13107.2) + 0
    conversion.voltage_1 = ((float32(raw.voltage_1)) / 13107.2) + 0
    conversion.voltage_2 = ((float32(raw.voltage_2)) / 13107.2) + 0
    conversion.start_index = raw.start_index
    return conversion

def conversion_to_raw_HV_CELLS_VOLTAGE(conversion: message_HV_CELLS_VOLTAGE_conversion) -> message_HV_CELLS_VOLTAGE:
    raw = message_HV_CELLS_VOLTAGE()
    raw.voltage_0 = uint16((conversion.voltage_0 + 0) * 13107.2)
    raw.voltage_1 = uint16((conversion.voltage_1 + 0) * 13107.2)
    raw.voltage_2 = uint16((conversion.voltage_2 + 0) * 13107.2)
    raw.start_index = conversion.start_index
    return raw

def serialize_HV_CELLS_VOLTAGE(message: message_HV_CELLS_VOLTAGE) -> bytearray:
    data = bytearray()
    data.extend(pack("<HHHB", message.voltage_0, message.voltage_1, message.voltage_2, message.start_index))
    return data

def deserialize_HV_CELLS_VOLTAGE(data: bytearray) -> message_HV_CELLS_VOLTAGE:
    message = message_HV_CELLS_VOLTAGE()
    message.voltage_0 = uint16(unpack("<H", data[0:2])[0])
    message.voltage_1 = uint16(unpack("<xxH", data[0:4])[0])
    message.voltage_2 = uint16(unpack("<xxxxH", data[0:6])[0])
    message.start_index = uint8(unpack("<xxxxxxB", data[0:7])[0])
    return message


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
        self.start_index = uint8(start_index) if start_index is not None else None
        self.temp_0 = uint8(temp_0) if temp_0 is not None else None
        self.temp_1 = uint8(temp_1) if temp_1 is not None else None
        self.temp_2 = uint8(temp_2) if temp_2 is not None else None
        self.temp_3 = uint8(temp_3) if temp_3 is not None else None
        self.temp_4 = uint8(temp_4) if temp_4 is not None else None
        self.temp_5 = uint8(temp_5) if temp_5 is not None else None
        self.temp_6 = uint8(temp_6) if temp_6 is not None else None
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

class message_HV_CELLS_TEMP_conversion(message_HV_CELLS_TEMP):
    pass

def raw_to_conversion_HV_CELLS_TEMP(raw: message_HV_CELLS_TEMP) -> message_HV_CELLS_TEMP_conversion:
    conversion = message_HV_CELLS_TEMP_conversion()
    conversion.start_index = raw.start_index
    conversion.temp_0 = ((float32(raw.temp_0)) / 2.56) - 20
    conversion.temp_1 = ((float32(raw.temp_1)) / 2.56) - 20
    conversion.temp_2 = ((float32(raw.temp_2)) / 2.56) - 20
    conversion.temp_3 = ((float32(raw.temp_3)) / 2.56) - 20
    conversion.temp_4 = ((float32(raw.temp_4)) / 2.56) - 20
    conversion.temp_5 = ((float32(raw.temp_5)) / 2.56) - 20
    conversion.temp_6 = ((float32(raw.temp_6)) / 2.56) - 20
    return conversion

def conversion_to_raw_HV_CELLS_TEMP(conversion: message_HV_CELLS_TEMP_conversion) -> message_HV_CELLS_TEMP:
    raw = message_HV_CELLS_TEMP()
    raw.start_index = conversion.start_index
    raw.temp_0 = uint8((conversion.temp_0 + 20) * 2.56)
    raw.temp_1 = uint8((conversion.temp_1 + 20) * 2.56)
    raw.temp_2 = uint8((conversion.temp_2 + 20) * 2.56)
    raw.temp_3 = uint8((conversion.temp_3 + 20) * 2.56)
    raw.temp_4 = uint8((conversion.temp_4 + 20) * 2.56)
    raw.temp_5 = uint8((conversion.temp_5 + 20) * 2.56)
    raw.temp_6 = uint8((conversion.temp_6 + 20) * 2.56)
    return raw

def serialize_HV_CELLS_TEMP(message: message_HV_CELLS_TEMP) -> bytearray:
    data = bytearray()
    data.extend(pack("<BBBBBBBB", message.start_index, message.temp_0, message.temp_1, message.temp_2, message.temp_3, message.temp_4, message.temp_5, message.temp_6))
    return data

def deserialize_HV_CELLS_TEMP(data: bytearray) -> message_HV_CELLS_TEMP:
    message = message_HV_CELLS_TEMP()
    message.start_index = uint8(unpack("<B", data[0:1])[0])
    message.temp_0 = uint8(unpack("<xB", data[0:2])[0])
    message.temp_1 = uint8(unpack("<xxB", data[0:3])[0])
    message.temp_2 = uint8(unpack("<xxxB", data[0:4])[0])
    message.temp_3 = uint8(unpack("<xxxxB", data[0:5])[0])
    message.temp_4 = uint8(unpack("<xxxxxB", data[0:6])[0])
    message.temp_5 = uint8(unpack("<xxxxxxB", data[0:7])[0])
    message.temp_6 = uint8(unpack("<xxxxxxxB", data[0:8])[0])
    return message


class message_HV_CELL_BALANCING_STATUS:
    def __init__(
        self,
        balancing_status = None
    ):
        self.balancing_status = Toggle(balancing_status) if balancing_status is not None else None
        self.size = 1
        self.interval = 500

    def __eq__(self, other):
        if not isinstance(other, message_HV_CELL_BALANCING_STATUS):
            return False
        if self.balancing_status != other.balancing_status:
            return False
        return True



def serialize_HV_CELL_BALANCING_STATUS(message: message_HV_CELL_BALANCING_STATUS) -> bytearray:
    data = bytearray()
    data.extend(pack("<B", message.balancing_status << 7 & 255))
    return data

def deserialize_HV_CELL_BALANCING_STATUS(data: bytearray) -> message_HV_CELL_BALANCING_STATUS:
    message = message_HV_CELL_BALANCING_STATUS()
    message.balancing_status = Toggle((unpack("<B", data[0:1])[0] & 128) >> 7)
    return message


class message_SET_CELL_BALANCING_STATUS:
    def __init__(
        self,
        set_balancing_status = None
    ):
        self.set_balancing_status = Toggle(set_balancing_status) if set_balancing_status is not None else None
        self.size = 1

    def __eq__(self, other):
        if not isinstance(other, message_SET_CELL_BALANCING_STATUS):
            return False
        if self.set_balancing_status != other.set_balancing_status:
            return False
        return True



def serialize_SET_CELL_BALANCING_STATUS(message: message_SET_CELL_BALANCING_STATUS) -> bytearray:
    data = bytearray()
    data.extend(pack("<B", message.set_balancing_status << 7 & 255))
    return data

def deserialize_SET_CELL_BALANCING_STATUS(data: bytearray) -> message_SET_CELL_BALANCING_STATUS:
    message = message_SET_CELL_BALANCING_STATUS()
    message.set_balancing_status = Toggle((unpack("<B", data[0:1])[0] & 128) >> 7)
    return message


class message_HANDCART_STATUS:
    def __init__(
        self,
        connected = None
    ):
        self.connected = bool(connected) if connected is not None else None
        self.size = 1
        self.interval = 500

    def __eq__(self, other):
        if not isinstance(other, message_HANDCART_STATUS):
            return False
        if self.connected != other.connected:
            return False
        return True



def serialize_HANDCART_STATUS(message: message_HANDCART_STATUS) -> bytearray:
    data = bytearray()
    data.extend(pack("<B", message.connected << 7 & 255))
    return data

def deserialize_HANDCART_STATUS(data: bytearray) -> message_HANDCART_STATUS:
    message = message_HANDCART_STATUS()
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
        self.encoder_r = uint16(encoder_r) if encoder_r is not None else None
        self.encoder_l = uint16(encoder_l) if encoder_l is not None else None
        self.inverter_r = uint16(inverter_r) if inverter_r is not None else None
        self.inverter_l = uint16(inverter_l) if inverter_l is not None else None
        self.size = 8
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



def serialize_SPEED(message: message_SPEED) -> bytearray:
    data = bytearray()
    data.extend(pack("<HHHH", message.encoder_r, message.encoder_l, message.inverter_r, message.inverter_l))
    return data

def deserialize_SPEED(data: bytearray) -> message_SPEED:
    message = message_SPEED()
    message.encoder_r = uint16(unpack("<H", data[0:2])[0])
    message.encoder_l = uint16(unpack("<xxH", data[0:4])[0])
    message.inverter_r = uint16(unpack("<xxxxH", data[0:6])[0])
    message.inverter_l = uint16(unpack("<xxxxxxH", data[0:8])[0])
    return message


class message_INV_L_SET_TORQUE:
    def __init__(
        self,
        reg_id = None,
        lsb = None,
        msb = None
    ):
        self.reg_id = uint8(reg_id) if reg_id is not None else None
        self.lsb = uint8(lsb) if lsb is not None else None
        self.msb = uint8(msb) if msb is not None else None
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



def serialize_INV_L_SET_TORQUE(message: message_INV_L_SET_TORQUE) -> bytearray:
    data = bytearray()
    data.extend(pack("<BBB", message.reg_id, message.lsb, message.msb))
    return data

def deserialize_INV_L_SET_TORQUE(data: bytearray) -> message_INV_L_SET_TORQUE:
    message = message_INV_L_SET_TORQUE()
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
        self.reg_id = uint8(reg_id) if reg_id is not None else None
        self.data_0 = uint8(data_0) if data_0 is not None else None
        self.data_1 = uint8(data_1) if data_1 is not None else None
        self.data_2 = uint8(data_2) if data_2 is not None else None
        self.data_3 = uint8(data_3) if data_3 is not None else None
        self.data_4 = uint8(data_4) if data_4 is not None else None
        self.data_5 = uint8(data_5) if data_5 is not None else None
        self.data_6 = uint8(data_6) if data_6 is not None else None
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



def serialize_INV_L_RESPONSE(message: message_INV_L_RESPONSE) -> bytearray:
    data = bytearray()
    data.extend(pack("<BBBBBBBB", message.reg_id, message.data_0, message.data_1, message.data_2, message.data_3, message.data_4, message.data_5, message.data_6))
    return data

def deserialize_INV_L_RESPONSE(data: bytearray) -> message_INV_L_RESPONSE:
    message = message_INV_L_RESPONSE()
    message.reg_id = uint8(unpack("<B", data[0:1])[0])
    message.data_0 = uint8(unpack("<xB", data[0:2])[0])
    message.data_1 = uint8(unpack("<xxB", data[0:3])[0])
    message.data_2 = uint8(unpack("<xxxB", data[0:4])[0])
    message.data_3 = uint8(unpack("<xxxxB", data[0:5])[0])
    message.data_4 = uint8(unpack("<xxxxxB", data[0:6])[0])
    message.data_5 = uint8(unpack("<xxxxxxB", data[0:7])[0])
    message.data_6 = uint8(unpack("<xxxxxxxB", data[0:8])[0])
    return message

