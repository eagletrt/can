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
    LTC_PEC_ERROR = 1
    CELL_UNDER_VOLTAGE = 2
    CELL_OVER_VOLTAGE = 4
    CELL_OVER_TEMPERATURE = 8
    OVER_CURRENT = 16
    ADC_INIT = 32
    ADC_TIMEOUT = 64
    INT_VOLTAGE_MISMATCH = 128
    FEEDBACK_HARD = 256
    FEEDBACK_SOFT = 512

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
        component_version,
        cancicd_version
    ):
        self.component_version = uint8(component_version) if component_version is not None else None
        self.cancicd_version = uint8(cancicd_version) if cancicd_version is not None else None
        self.size = 2
        self.millis = 1000

    def serialize(self):
        data = bytearray()
        data.extend(pack("<BB", self.component_version, self.cancicd_version))
        return data

    def deserialize(self, data):
        self.component_version = uint8(unpack("<B", data[0:1])[0])
        self.cancicd_version = uint8(unpack("<xB", data[0:2])[0])

    def __eq__(self, other):
        if not isinstance(other, message_STEER_VERSION):
            return False
        if self.component_version != other.component_version:
            return False
        if self.cancicd_version != other.cancicd_version:
            return False
        return True


class message_DAS_VERSION:
    def __init__(
        self,
        component_version,
        cancicd_version
    ):
        self.component_version = uint8(component_version) if component_version is not None else None
        self.cancicd_version = uint8(cancicd_version) if cancicd_version is not None else None
        self.size = 2
        self.millis = 1000

    def serialize(self):
        data = bytearray()
        data.extend(pack("<BB", self.component_version, self.cancicd_version))
        return data

    def deserialize(self, data):
        self.component_version = uint8(unpack("<B", data[0:1])[0])
        self.cancicd_version = uint8(unpack("<xB", data[0:2])[0])

    def __eq__(self, other):
        if not isinstance(other, message_DAS_VERSION):
            return False
        if self.component_version != other.component_version:
            return False
        if self.cancicd_version != other.cancicd_version:
            return False
        return True


class message_HV_VERSION:
    def __init__(
        self,
        component_version,
        cancicd_version
    ):
        self.component_version = uint8(component_version) if component_version is not None else None
        self.cancicd_version = uint8(cancicd_version) if cancicd_version is not None else None
        self.size = 2
        self.millis = 1000

    def serialize(self):
        data = bytearray()
        data.extend(pack("<BB", self.component_version, self.cancicd_version))
        return data

    def deserialize(self, data):
        self.component_version = uint8(unpack("<B", data[0:1])[0])
        self.cancicd_version = uint8(unpack("<xB", data[0:2])[0])

    def __eq__(self, other):
        if not isinstance(other, message_HV_VERSION):
            return False
        if self.component_version != other.component_version:
            return False
        if self.cancicd_version != other.cancicd_version:
            return False
        return True


class message_LV_VERSION:
    def __init__(
        self,
        component_version,
        cancicd_version
    ):
        self.component_version = uint8(component_version) if component_version is not None else None
        self.cancicd_version = uint8(cancicd_version) if cancicd_version is not None else None
        self.size = 2
        self.millis = 1000

    def serialize(self):
        data = bytearray()
        data.extend(pack("<BB", self.component_version, self.cancicd_version))
        return data

    def deserialize(self, data):
        self.component_version = uint8(unpack("<B", data[0:1])[0])
        self.cancicd_version = uint8(unpack("<xB", data[0:2])[0])

    def __eq__(self, other):
        if not isinstance(other, message_LV_VERSION):
            return False
        if self.component_version != other.component_version:
            return False
        if self.cancicd_version != other.cancicd_version:
            return False
        return True


class message_TLM_VERSION:
    def __init__(
        self,
        component_version,
        cancicd_version
    ):
        self.component_version = uint8(component_version) if component_version is not None else None
        self.cancicd_version = uint8(cancicd_version) if cancicd_version is not None else None
        self.size = 2
        self.millis = 1000

    def serialize(self):
        data = bytearray()
        data.extend(pack("<BB", self.component_version, self.cancicd_version))
        return data

    def deserialize(self, data):
        self.component_version = uint8(unpack("<B", data[0:1])[0])
        self.cancicd_version = uint8(unpack("<xB", data[0:2])[0])

    def __eq__(self, other):
        if not isinstance(other, message_TLM_VERSION):
            return False
        if self.component_version != other.component_version:
            return False
        if self.cancicd_version != other.cancicd_version:
            return False
        return True


class message_TIMESTAMP:
    def __init__(
        self,
        timestamp
    ):
        self.timestamp = uint32(timestamp) if timestamp is not None else None
        self.size = 4
        self.millis = 1000

    def serialize(self):
        data = bytearray()
        data.extend(pack("<I", self.timestamp))
        return data

    def deserialize(self, data):
        self.timestamp = uint32(unpack("<I", data[0:4])[0])

    def __eq__(self, other):
        if not isinstance(other, message_TIMESTAMP):
            return False
        if self.timestamp != other.timestamp:
            return False
        return True


class message_SET_TLM_STATUS:
    def __init__(
        self,
        driver,
        circuit,
        race_type,
        tlm_status
    ):
        self.driver = uint8(driver) if driver is not None else None
        self.circuit = uint8(circuit) if circuit is not None else None
        self.race_type = RaceType(race_type) if race_type is not None else None
        self.tlm_status = Toggle(tlm_status) if tlm_status is not None else None
        self.size = 3

    def serialize(self):
        data = bytearray()
        data.extend(pack("<BBB", self.driver, self.circuit, self.race_type << 6 & 255 | self.tlm_status << 5 & 255))
        return data

    def deserialize(self, data):
        self.driver = uint8(unpack("<B", data[0:1])[0])
        self.circuit = uint8(unpack("<xB", data[0:2])[0])
        self.race_type = RaceType((unpack("<xxB", data[0:3])[0] & 192) >> 6)
        self.tlm_status = Toggle((unpack("<xxB", data[0:3])[0] & 32) >> 5)

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


class message_TLM_STATUS:
    def __init__(
        self,
        driver,
        circuit,
        race_type,
        tlm_status
    ):
        self.driver = uint8(driver) if driver is not None else None
        self.circuit = uint8(circuit) if circuit is not None else None
        self.race_type = RaceType(race_type) if race_type is not None else None
        self.tlm_status = Toggle(tlm_status) if tlm_status is not None else None
        self.size = 3
        self.millis = 1000

    def serialize(self):
        data = bytearray()
        data.extend(pack("<BBB", self.driver, self.circuit, self.race_type << 6 & 255 | self.tlm_status << 5 & 255))
        return data

    def deserialize(self, data):
        self.driver = uint8(unpack("<B", data[0:1])[0])
        self.circuit = uint8(unpack("<xB", data[0:2])[0])
        self.race_type = RaceType((unpack("<xxB", data[0:3])[0] & 192) >> 6)
        self.tlm_status = Toggle((unpack("<xxB", data[0:3])[0] & 32) >> 5)

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


class message_STEER_SYSTEM_STATUS:
    def __init__(
        self,
        soc_temp
    ):
        self.soc_temp = uint8(soc_temp) if soc_temp is not None else None
        self.size = 1
        self.millis = 2000

    def serialize(self):
        data = bytearray()
        data.extend(pack("<B", self.soc_temp))
        return data

    def deserialize(self, data):
        self.soc_temp = uint8(unpack("<B", data[0:1])[0])

    def __eq__(self, other):
        if not isinstance(other, message_STEER_SYSTEM_STATUS):
            return False
        if self.soc_temp != other.soc_temp:
            return False
        return True


class message_HV_VOLTAGE:
    def __init__(
        self,
        pack_voltage,
        bus_voltage,
        max_cell_voltage,
        min_cell_voltage
    ):
        self.pack_voltage = uint16(pack_voltage) if pack_voltage is not None else None
        self.bus_voltage = uint16(bus_voltage) if bus_voltage is not None else None
        self.max_cell_voltage = uint16(max_cell_voltage) if max_cell_voltage is not None else None
        self.min_cell_voltage = uint16(min_cell_voltage) if min_cell_voltage is not None else None
        self.size = 8
        self.millis = 20

    def serialize(self):
        data = bytearray()
        data.extend(pack("<HHHH", self.pack_voltage, self.bus_voltage, self.max_cell_voltage, self.min_cell_voltage))
        return data

    def deserialize(self, data):
        self.pack_voltage = uint16(unpack("<H", data[0:2])[0])
        self.bus_voltage = uint16(unpack("<xxH", data[0:4])[0])
        self.max_cell_voltage = uint16(unpack("<xxxxH", data[0:6])[0])
        self.min_cell_voltage = uint16(unpack("<xxxxxxH", data[0:8])[0])

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


class message_HV_CURRENT:
    def __init__(
        self,
        current,
        power
    ):
        self.current = uint16(current) if current is not None else None
        self.power = int16(power) if power is not None else None
        self.size = 4
        self.millis = 20

    def serialize(self):
        data = bytearray()
        data.extend(pack("<Hh", self.current, self.power))
        return data

    def deserialize(self, data):
        self.current = uint16(unpack("<H", data[0:2])[0])
        self.power = int16(unpack("<xxh", data[0:4])[0])

    def __eq__(self, other):
        if not isinstance(other, message_HV_CURRENT):
            return False
        if self.current != other.current:
            return False
        if self.power != other.power:
            return False
        return True


class message_HV_TEMP:
    def __init__(
        self,
        average_temp,
        max_temp,
        min_temp
    ):
        self.average_temp = uint16(average_temp) if average_temp is not None else None
        self.max_temp = uint16(max_temp) if max_temp is not None else None
        self.min_temp = uint16(min_temp) if min_temp is not None else None
        self.size = 6
        self.millis = 200

    def serialize(self):
        data = bytearray()
        data.extend(pack("<HHH", self.average_temp, self.max_temp, self.min_temp))
        return data

    def deserialize(self, data):
        self.average_temp = uint16(unpack("<H", data[0:2])[0])
        self.max_temp = uint16(unpack("<xxH", data[0:4])[0])
        self.min_temp = uint16(unpack("<xxxxH", data[0:6])[0])

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


class message_HV_ERRORS:
    def __init__(
        self,
        warnings,
        errors
    ):
        self.warnings = HvErrors(warnings) if warnings is not None else None
        self.errors = HvErrors(errors) if errors is not None else None
        self.size = 4
        self.millis = 20

    def serialize(self):
        data = bytearray()
        data.extend(pack("<BBBB", (int(self.warnings) >> 8) & 255, (int(self.warnings) >> 0) & 255, (int(self.errors) >> 8) & 255, (int(self.errors) >> 0) & 255))
        return data

    def deserialize(self, data):
        self.warnings = HvErrors(int((unpack("<BB", data[0:2])[0] << 8) | (unpack("<BB", data[0:2])[1] << 0)))
        self.errors = HvErrors(int((unpack("<xxBB", data[0:4])[0] << 8) | (unpack("<xxBB", data[0:4])[1] << 0)))

    def __eq__(self, other):
        if not isinstance(other, message_HV_ERRORS):
            return False
        if self.warnings != other.warnings:
            return False
        if self.errors != other.errors:
            return False
        return True


class message_TS_STATUS:
    def __init__(
        self,
        ts_status
    ):
        self.ts_status = TsStatus(ts_status) if ts_status is not None else None
        self.size = 1
        self.millis = 20

    def serialize(self):
        data = bytearray()
        data.extend(pack("<B", self.ts_status << 6 & 255))
        return data

    def deserialize(self, data):
        self.ts_status = TsStatus((unpack("<B", data[0:1])[0] & 192) >> 6)

    def __eq__(self, other):
        if not isinstance(other, message_TS_STATUS):
            return False
        if self.ts_status != other.ts_status:
            return False
        return True


class message_SET_TS_STATUS:
    def __init__(
        self,
        ts_status_set
    ):
        self.ts_status_set = Toggle(ts_status_set) if ts_status_set is not None else None
        self.size = 1

    def serialize(self):
        data = bytearray()
        data.extend(pack("<B", self.ts_status_set << 7 & 255))
        return data

    def deserialize(self, data):
        self.ts_status_set = Toggle((unpack("<B", data[0:1])[0] & 128) >> 7)

    def __eq__(self, other):
        if not isinstance(other, message_SET_TS_STATUS):
            return False
        if self.ts_status_set != other.ts_status_set:
            return False
        return True


class message_STEER_STATUS:
    def __init__(
        self,
        map,
        traction_control
    ):
        self.map = Map(map) if map is not None else None
        self.traction_control = TractionControl(traction_control) if traction_control is not None else None
        self.size = 1
        self.millis = 100

    def serialize(self):
        data = bytearray()
        data.extend(pack("<B", self.map << 5 & 255 | self.traction_control << 3 & 255))
        return data

    def deserialize(self, data):
        self.map = Map((unpack("<B", data[0:1])[0] & 224) >> 5)
        self.traction_control = TractionControl((unpack("<B", data[0:1])[0] & 24) >> 3)

    def __eq__(self, other):
        if not isinstance(other, message_STEER_STATUS):
            return False
        if self.map != other.map:
            return False
        if self.traction_control != other.traction_control:
            return False
        return True


class message_SET_CAR_STATUS:
    def __init__(
        self,
        car_status_set
    ):
        self.car_status_set = SetCarStatus(car_status_set) if car_status_set is not None else None
        self.size = 1

    def serialize(self):
        data = bytearray()
        data.extend(pack("<B", self.car_status_set << 7 & 255))
        return data

    def deserialize(self, data):
        self.car_status_set = SetCarStatus((unpack("<B", data[0:1])[0] & 128) >> 7)

    def __eq__(self, other):
        if not isinstance(other, message_SET_CAR_STATUS):
            return False
        if self.car_status_set != other.car_status_set:
            return False
        return True


class message_SET_PEDALS_RANGE:
    def __init__(
        self,
        bound,
        pedal
    ):
        self.bound = Bound(bound) if bound is not None else None
        self.pedal = Pedal(pedal) if pedal is not None else None
        self.size = 1

    def serialize(self):
        data = bytearray()
        data.extend(pack("<B", self.bound << 7 & 255 | self.pedal << 6 & 255))
        return data

    def deserialize(self, data):
        self.bound = Bound((unpack("<B", data[0:1])[0] & 128) >> 7)
        self.pedal = Pedal((unpack("<B", data[0:1])[0] & 64) >> 6)

    def __eq__(self, other):
        if not isinstance(other, message_SET_PEDALS_RANGE):
            return False
        if self.bound != other.bound:
            return False
        if self.pedal != other.pedal:
            return False
        return True


class message_CAR_STATUS:
    def __init__(
        self,
        inverter_l,
        inverter_r,
        car_status
    ):
        self.inverter_l = InverterStatus(inverter_l) if inverter_l is not None else None
        self.inverter_r = InverterStatus(inverter_r) if inverter_r is not None else None
        self.car_status = CarStatus(car_status) if car_status is not None else None
        self.size = 1
        self.millis = 100

    def serialize(self):
        data = bytearray()
        data.extend(pack("<B", self.inverter_l << 6 & 255 | self.inverter_r << 4 & 255 | self.car_status << 2 & 255))
        return data

    def deserialize(self, data):
        self.inverter_l = InverterStatus((unpack("<B", data[0:1])[0] & 192) >> 6)
        self.inverter_r = InverterStatus((unpack("<B", data[0:1])[0] & 48) >> 4)
        self.car_status = CarStatus((unpack("<B", data[0:1])[0] & 12) >> 2)

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


class message_DAS_ERRORS:
    def __init__(
        self,
        das_error
    ):
        self.das_error = DasErrors(das_error) if das_error is not None else None
        self.size = 1
        self.millis = 20

    def serialize(self):
        data = bytearray()
        data.extend(pack("<B", (int(self.das_error) >> 0) & 255))
        return data

    def deserialize(self, data):
        self.das_error = DasErrors(int((unpack("<B", data[0:1])[0] << 0)))

    def __eq__(self, other):
        if not isinstance(other, message_DAS_ERRORS):
            return False
        if self.das_error != other.das_error:
            return False
        return True


class message_LV_CURRENT:
    def __init__(
        self,
        current
    ):
        self.current = uint8(current) if current is not None else None
        self.size = 1
        self.millis = 500

    def serialize(self):
        data = bytearray()
        data.extend(pack("<B", self.current))
        return data

    def deserialize(self, data):
        self.current = uint8(unpack("<B", data[0:1])[0])

    def __eq__(self, other):
        if not isinstance(other, message_LV_CURRENT):
            return False
        if self.current != other.current:
            return False
        return True


class message_LV_VOLTAGE:
    def __init__(
        self,
        total_voltage,
        voltage_1,
        voltage_2,
        voltage_3,
        voltage_4
    ):
        self.total_voltage = uint16(total_voltage) if total_voltage is not None else None
        self.voltage_1 = uint8(voltage_1) if voltage_1 is not None else None
        self.voltage_2 = uint8(voltage_2) if voltage_2 is not None else None
        self.voltage_3 = uint8(voltage_3) if voltage_3 is not None else None
        self.voltage_4 = uint8(voltage_4) if voltage_4 is not None else None
        self.size = 6
        self.millis = 200

    def serialize(self):
        data = bytearray()
        data.extend(pack("<HBBBB", self.total_voltage, self.voltage_1, self.voltage_2, self.voltage_3, self.voltage_4))
        return data

    def deserialize(self, data):
        self.total_voltage = uint16(unpack("<H", data[0:2])[0])
        self.voltage_1 = uint8(unpack("<xxB", data[0:3])[0])
        self.voltage_2 = uint8(unpack("<xxxB", data[0:4])[0])
        self.voltage_3 = uint8(unpack("<xxxxB", data[0:5])[0])
        self.voltage_4 = uint8(unpack("<xxxxxB", data[0:6])[0])

    def __eq__(self, other):
        if not isinstance(other, message_LV_VOLTAGE):
            return False
        if self.total_voltage != other.total_voltage:
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


class message_LV_TEMPERATURE:
    def __init__(
        self,
        bp_temperature,
        dcdc_temperature
    ):
        self.bp_temperature = uint8(bp_temperature) if bp_temperature is not None else None
        self.dcdc_temperature = uint8(dcdc_temperature) if dcdc_temperature is not None else None
        self.size = 2
        self.millis = 200

    def serialize(self):
        data = bytearray()
        data.extend(pack("<BB", self.bp_temperature, self.dcdc_temperature))
        return data

    def deserialize(self, data):
        self.bp_temperature = uint8(unpack("<B", data[0:1])[0])
        self.dcdc_temperature = uint8(unpack("<xB", data[0:2])[0])

    def __eq__(self, other):
        if not isinstance(other, message_LV_TEMPERATURE):
            return False
        if self.bp_temperature != other.bp_temperature:
            return False
        if self.dcdc_temperature != other.dcdc_temperature:
            return False
        return True


class message_COOLING_STATUS:
    def __init__(
        self,
        hv_fan_speed,
        lv_fan_speed,
        pump_speed
    ):
        self.hv_fan_speed = uint8(hv_fan_speed) if hv_fan_speed is not None else None
        self.lv_fan_speed = uint8(lv_fan_speed) if lv_fan_speed is not None else None
        self.pump_speed = uint8(pump_speed) if pump_speed is not None else None
        self.size = 3
        self.millis = 1000

    def serialize(self):
        data = bytearray()
        data.extend(pack("<BBB", self.hv_fan_speed, self.lv_fan_speed, self.pump_speed))
        return data

    def deserialize(self, data):
        self.hv_fan_speed = uint8(unpack("<B", data[0:1])[0])
        self.lv_fan_speed = uint8(unpack("<xB", data[0:2])[0])
        self.pump_speed = uint8(unpack("<xxB", data[0:3])[0])

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


class message_MARKER:
    def __init__(
        self
    ):
        self.size = 0

    def serialize(self):
        data = bytearray()
        data.extend()
        return data

    def deserialize(self, data):
        pass

    def __eq__(self, other):
        if not isinstance(other, message_MARKER):
            return False
        return True


class message_HV_CELLS_VOLTAGE:
    def __init__(
        self,
        voltage_0,
        voltage_1,
        voltage_2,
        cell_index
    ):
        self.voltage_0 = uint16(voltage_0) if voltage_0 is not None else None
        self.voltage_1 = uint16(voltage_1) if voltage_1 is not None else None
        self.voltage_2 = uint16(voltage_2) if voltage_2 is not None else None
        self.cell_index = uint8(cell_index) if cell_index is not None else None
        self.size = 7
        self.millis = 200

    def serialize(self):
        data = bytearray()
        data.extend(pack("<HHHB", self.voltage_0, self.voltage_1, self.voltage_2, self.cell_index))
        return data

    def deserialize(self, data):
        self.voltage_0 = uint16(unpack("<H", data[0:2])[0])
        self.voltage_1 = uint16(unpack("<xxH", data[0:4])[0])
        self.voltage_2 = uint16(unpack("<xxxxH", data[0:6])[0])
        self.cell_index = uint8(unpack("<xxxxxxB", data[0:7])[0])

    def __eq__(self, other):
        if not isinstance(other, message_HV_CELLS_VOLTAGE):
            return False
        if self.voltage_0 != other.voltage_0:
            return False
        if self.voltage_1 != other.voltage_1:
            return False
        if self.voltage_2 != other.voltage_2:
            return False
        if self.cell_index != other.cell_index:
            return False
        return True


class message_HV_CELLS_TEMP:
    def __init__(
        self,
        cell_index,
        temp_0,
        temp_1,
        temp_2,
        temp_3,
        temp_4,
        temp_5,
        temp_6
    ):
        self.cell_index = uint8(cell_index) if cell_index is not None else None
        self.temp_0 = uint8(temp_0) if temp_0 is not None else None
        self.temp_1 = uint8(temp_1) if temp_1 is not None else None
        self.temp_2 = uint8(temp_2) if temp_2 is not None else None
        self.temp_3 = uint8(temp_3) if temp_3 is not None else None
        self.temp_4 = uint8(temp_4) if temp_4 is not None else None
        self.temp_5 = uint8(temp_5) if temp_5 is not None else None
        self.temp_6 = uint8(temp_6) if temp_6 is not None else None
        self.size = 8
        self.millis = 100

    def serialize(self):
        data = bytearray()
        data.extend(pack("<BBBBBBBB", self.cell_index, self.temp_0, self.temp_1, self.temp_2, self.temp_3, self.temp_4, self.temp_5, self.temp_6))
        return data

    def deserialize(self, data):
        self.cell_index = uint8(unpack("<B", data[0:1])[0])
        self.temp_0 = uint8(unpack("<xB", data[0:2])[0])
        self.temp_1 = uint8(unpack("<xxB", data[0:3])[0])
        self.temp_2 = uint8(unpack("<xxxB", data[0:4])[0])
        self.temp_3 = uint8(unpack("<xxxxB", data[0:5])[0])
        self.temp_4 = uint8(unpack("<xxxxxB", data[0:6])[0])
        self.temp_5 = uint8(unpack("<xxxxxxB", data[0:7])[0])
        self.temp_6 = uint8(unpack("<xxxxxxxB", data[0:8])[0])

    def __eq__(self, other):
        if not isinstance(other, message_HV_CELLS_TEMP):
            return False
        if self.cell_index != other.cell_index:
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


class message_HV_CELL_BALANCING_STATUS:
    def __init__(
        self,
        balancing_status
    ):
        self.balancing_status = Toggle(balancing_status) if balancing_status is not None else None
        self.size = 1
        self.millis = 500

    def serialize(self):
        data = bytearray()
        data.extend(pack("<B", self.balancing_status << 7 & 255))
        return data

    def deserialize(self, data):
        self.balancing_status = Toggle((unpack("<B", data[0:1])[0] & 128) >> 7)

    def __eq__(self, other):
        if not isinstance(other, message_HV_CELL_BALANCING_STATUS):
            return False
        if self.balancing_status != other.balancing_status:
            return False
        return True


class message_SET_CELL_BALANCING_STATUS:
    def __init__(
        self,
        set_balancing_status
    ):
        self.set_balancing_status = Toggle(set_balancing_status) if set_balancing_status is not None else None
        self.size = 1

    def serialize(self):
        data = bytearray()
        data.extend(pack("<B", self.set_balancing_status << 7 & 255))
        return data

    def deserialize(self, data):
        self.set_balancing_status = Toggle((unpack("<B", data[0:1])[0] & 128) >> 7)

    def __eq__(self, other):
        if not isinstance(other, message_SET_CELL_BALANCING_STATUS):
            return False
        if self.set_balancing_status != other.set_balancing_status:
            return False
        return True


class message_HANDCART_STATUS:
    def __init__(
        self,
        connected
    ):
        self.connected = bool(connected) if connected is not None else None
        self.size = 1
        self.millis = 500

    def serialize(self):
        data = bytearray()
        data.extend(pack("<B", self.connected << 7 & 255))
        return data

    def deserialize(self, data):
        self.connected = bool((unpack("<B", data[0:1])[0] & 128) >> 7)

    def __eq__(self, other):
        if not isinstance(other, message_HANDCART_STATUS):
            return False
        if self.connected != other.connected:
            return False
        return True


class message_SPEED:
    def __init__(
        self,
        encoder_r,
        encoder_l,
        inverter_r,
        inverter_l
    ):
        self.encoder_r = uint16(encoder_r) if encoder_r is not None else None
        self.encoder_l = uint16(encoder_l) if encoder_l is not None else None
        self.inverter_r = uint16(inverter_r) if inverter_r is not None else None
        self.inverter_l = uint16(inverter_l) if inverter_l is not None else None
        self.size = 8
        self.millis = 100

    def serialize(self):
        data = bytearray()
        data.extend(pack("<HHHH", self.encoder_r, self.encoder_l, self.inverter_r, self.inverter_l))
        return data

    def deserialize(self, data):
        self.encoder_r = uint16(unpack("<H", data[0:2])[0])
        self.encoder_l = uint16(unpack("<xxH", data[0:4])[0])
        self.inverter_r = uint16(unpack("<xxxxH", data[0:6])[0])
        self.inverter_l = uint16(unpack("<xxxxxxH", data[0:8])[0])

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


class message_INV_L_SET_TORQUE:
    def __init__(
        self,
        reg_id,
        lsb,
        msb
    ):
        self.reg_id = uint8(reg_id) if reg_id is not None else None
        self.lsb = uint8(lsb) if lsb is not None else None
        self.msb = uint8(msb) if msb is not None else None
        self.size = 3
        self.millis = 20

    def serialize(self):
        data = bytearray()
        data.extend(pack("<BBB", self.reg_id, self.lsb, self.msb))
        return data

    def deserialize(self, data):
        self.reg_id = uint8(unpack("<B", data[0:1])[0])
        self.lsb = uint8(unpack("<xB", data[0:2])[0])
        self.msb = uint8(unpack("<xxB", data[0:3])[0])

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


class message_INV_L_RESPONSE:
    def __init__(
        self,
        reg_id,
        data_0,
        data_1,
        data_2,
        data_3,
        data_4,
        data_5,
        data_6
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
        self.millis = 100

    def serialize(self):
        data = bytearray()
        data.extend(pack("<BBBBBBBB", self.reg_id, self.data_0, self.data_1, self.data_2, self.data_3, self.data_4, self.data_5, self.data_6))
        return data

    def deserialize(self, data):
        self.reg_id = uint8(unpack("<B", data[0:1])[0])
        self.data_0 = uint8(unpack("<xB", data[0:2])[0])
        self.data_1 = uint8(unpack("<xxB", data[0:3])[0])
        self.data_2 = uint8(unpack("<xxxB", data[0:4])[0])
        self.data_3 = uint8(unpack("<xxxxB", data[0:5])[0])
        self.data_4 = uint8(unpack("<xxxxxB", data[0:6])[0])
        self.data_5 = uint8(unpack("<xxxxxxB", data[0:7])[0])
        self.data_6 = uint8(unpack("<xxxxxxxB", data[0:8])[0])

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

