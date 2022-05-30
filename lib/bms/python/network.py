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

class Errors(IntFlag):
    CAN_COMM = 1
    LTC_COMM = 2
    TEMP_COMM_0 = 4
    TEMP_COMM_1 = 8
    TEMP_COMM_2 = 16
    TEMP_COMM_3 = 32
    TEMP_COMM_4 = 64
    TEMP_COMM_5 = 128
    OPEN_WIRE = 256

class BalancingCells(IntFlag):
    CELL0 = 1
    CELL1 = 2
    CELL2 = 4
    CELL3 = 8
    CELL4 = 16
    CELL5 = 32
    CELL6 = 64
    CELL7 = 128
    CELL8 = 256
    CELL9 = 512
    CELL10 = 1024
    CELL11 = 2048
    CELL12 = 4096
    CELL13 = 8192
    CELL14 = 16384
    CELL15 = 32768
    CELL16 = 65536
    CELL17 = 131072

# Enums

class BalancingStatus(IntEnum):
    OFF = 0
    DISCHARGE = 1

# Messages


class message_BOARD_STATUS:
    def __init__(
        self,
        errors = None,
        balancing_status = None
    ):
        self.errors = Errors(errors) if errors is not None else None
        self.balancing_status = BalancingStatus(balancing_status) if balancing_status is not None else None
        self.size = 3

    def __eq__(self, other):
        if not isinstance(other, message_BOARD_STATUS):
            return False
        if self.errors != other.errors:
            return False
        if self.balancing_status != other.balancing_status:
            return False
        return True



def serialize_BOARD_STATUS(message: message_BOARD_STATUS) -> bytearray:
    data = bytearray()
    data.extend(pack("<BBB", (int(message.errors) >> 8) & 255, (int(message.errors) >> 0) & 255, message.balancing_status << 7 & 255))
    return data

def deserialize_BOARD_STATUS(data: bytearray) -> message_BOARD_STATUS:
    message = message_BOARD_STATUS()
    message.errors = Errors(int((unpack("<BB", data[0:2])[0] << 8) | (unpack("<BB", data[0:2])[1] << 0)))
    message.balancing_status = BalancingStatus((unpack("<xxB", data[0:3])[0] & 128) >> 7)
    return message


class message_TEMPERATURES:
    def __init__(
        self,
        start_index = None,
        temp0 = None,
        temp1 = None,
        temp2 = None,
        temp3 = None,
        temp4 = None,
        temp5 = None
    ):
        self.start_index = uint8(start_index) if start_index is not None else None
        self.temp0 = uint8(temp0) if temp0 is not None else None
        self.temp1 = uint8(temp1) if temp1 is not None else None
        self.temp2 = uint8(temp2) if temp2 is not None else None
        self.temp3 = uint8(temp3) if temp3 is not None else None
        self.temp4 = uint8(temp4) if temp4 is not None else None
        self.temp5 = uint8(temp5) if temp5 is not None else None
        self.size = 7

    def __eq__(self, other):
        if not isinstance(other, message_TEMPERATURES):
            return False
        if self.start_index != other.start_index:
            return False
        if self.temp0 != other.temp0:
            return False
        if self.temp1 != other.temp1:
            return False
        if self.temp2 != other.temp2:
            return False
        if self.temp3 != other.temp3:
            return False
        if self.temp4 != other.temp4:
            return False
        if self.temp5 != other.temp5:
            return False
        return True

class message_TEMPERATURES_conversion:
    pass

def raw_to_conversion_TEMPERATURES(raw: message_TEMPERATURES) -> message_TEMPERATURES_conversion:
    conversion = message_TEMPERATURES_conversion()
    conversion.start_index = raw.start_index
    conversion.temp0 = ((float32(raw.temp0)) / 2.56) - 20
    conversion.temp1 = ((float32(raw.temp1)) / 2.56) - 20
    conversion.temp2 = ((float32(raw.temp2)) / 2.56) - 20
    conversion.temp3 = ((float32(raw.temp3)) / 2.56) - 20
    conversion.temp4 = ((float32(raw.temp4)) / 2.56) - 20
    conversion.temp5 = ((float32(raw.temp5)) / 2.56) - 20
    return conversion

def conversion_to_raw_TEMPERATURES(conversion: message_TEMPERATURES_conversion) -> message_TEMPERATURES:
    raw = message_TEMPERATURES()
    raw.start_index = conversion.start_index
    raw.temp0 = uint8((conversion.temp0 + 20) * 2.56)
    raw.temp1 = uint8((conversion.temp1 + 20) * 2.56)
    raw.temp2 = uint8((conversion.temp2 + 20) * 2.56)
    raw.temp3 = uint8((conversion.temp3 + 20) * 2.56)
    raw.temp4 = uint8((conversion.temp4 + 20) * 2.56)
    raw.temp5 = uint8((conversion.temp5 + 20) * 2.56)
    return raw

def serialize_TEMPERATURES(message: message_TEMPERATURES) -> bytearray:
    data = bytearray()
    data.extend(pack("<BBBBBBB", message.start_index, message.temp0, message.temp1, message.temp2, message.temp3, message.temp4, message.temp5))
    return data

def deserialize_TEMPERATURES(data: bytearray) -> message_TEMPERATURES:
    message = message_TEMPERATURES()
    message.start_index = uint8(unpack("<B", data[0:1])[0])
    message.temp0 = uint8(unpack("<xB", data[0:2])[0])
    message.temp1 = uint8(unpack("<xxB", data[0:3])[0])
    message.temp2 = uint8(unpack("<xxxB", data[0:4])[0])
    message.temp3 = uint8(unpack("<xxxxB", data[0:5])[0])
    message.temp4 = uint8(unpack("<xxxxxB", data[0:6])[0])
    message.temp5 = uint8(unpack("<xxxxxxB", data[0:7])[0])
    return message


class message_VOLTAGES:
    def __init__(
        self,
        voltage0 = None,
        voltage1 = None,
        voltage2 = None,
        start_index = None
    ):
        self.voltage0 = uint16(voltage0) if voltage0 is not None else None
        self.voltage1 = uint16(voltage1) if voltage1 is not None else None
        self.voltage2 = uint16(voltage2) if voltage2 is not None else None
        self.start_index = uint8(start_index) if start_index is not None else None
        self.size = 7

    def __eq__(self, other):
        if not isinstance(other, message_VOLTAGES):
            return False
        if self.voltage0 != other.voltage0:
            return False
        if self.voltage1 != other.voltage1:
            return False
        if self.voltage2 != other.voltage2:
            return False
        if self.start_index != other.start_index:
            return False
        return True

class message_VOLTAGES_conversion:
    pass

def raw_to_conversion_VOLTAGES(raw: message_VOLTAGES) -> message_VOLTAGES_conversion:
    conversion = message_VOLTAGES_conversion()
    conversion.voltage0 = ((float32(raw.voltage0)) / 13107.2) + 0
    conversion.voltage1 = ((float32(raw.voltage1)) / 13107.2) + 0
    conversion.voltage2 = ((float32(raw.voltage2)) / 13107.2) + 0
    conversion.start_index = raw.start_index
    return conversion

def conversion_to_raw_VOLTAGES(conversion: message_VOLTAGES_conversion) -> message_VOLTAGES:
    raw = message_VOLTAGES()
    raw.voltage0 = uint16((conversion.voltage0 + 0) * 13107.2)
    raw.voltage1 = uint16((conversion.voltage1 + 0) * 13107.2)
    raw.voltage2 = uint16((conversion.voltage2 + 0) * 13107.2)
    raw.start_index = conversion.start_index
    return raw

def serialize_VOLTAGES(message: message_VOLTAGES) -> bytearray:
    data = bytearray()
    data.extend(pack("<HHHB", message.voltage0, message.voltage1, message.voltage2, message.start_index))
    return data

def deserialize_VOLTAGES(data: bytearray) -> message_VOLTAGES:
    message = message_VOLTAGES()
    message.voltage0 = uint16(unpack("<H", data[0:2])[0])
    message.voltage1 = uint16(unpack("<xxH", data[0:4])[0])
    message.voltage2 = uint16(unpack("<xxxxH", data[0:6])[0])
    message.start_index = uint8(unpack("<xxxxxxB", data[0:7])[0])
    return message


class message_BALANCING:
    def __init__(
        self,
        cells = None,
        board_index = None
    ):
        self.cells = BalancingCells(cells) if cells is not None else None
        self.board_index = uint8(board_index) if board_index is not None else None
        self.size = 5

    def __eq__(self, other):
        if not isinstance(other, message_BALANCING):
            return False
        if self.cells != other.cells:
            return False
        if self.board_index != other.board_index:
            return False
        return True



def serialize_BALANCING(message: message_BALANCING) -> bytearray:
    data = bytearray()
    data.extend(pack("<BBBBB", (int(message.cells) >> 24) & 255, (int(message.cells) >> 16) & 255, (int(message.cells) >> 8) & 255, (int(message.cells) >> 0) & 255, message.board_index))
    return data

def deserialize_BALANCING(data: bytearray) -> message_BALANCING:
    message = message_BALANCING()
    message.cells = BalancingCells(int((unpack("<BBBB", data[0:4])[0] << 24) | (unpack("<BBBB", data[0:4])[1] << 16) | (unpack("<BBBB", data[0:4])[2] << 8) | (unpack("<BBBB", data[0:4])[3] << 0)))
    message.board_index = uint8(unpack("<xxxxB", data[0:5])[0])
    return message


class message_FW_UPDATE:
    def __init__(
        self,
        board_index = None
    ):
        self.board_index = uint8(board_index) if board_index is not None else None
        self.size = 1

    def __eq__(self, other):
        if not isinstance(other, message_FW_UPDATE):
            return False
        if self.board_index != other.board_index:
            return False
        return True



def serialize_FW_UPDATE(message: message_FW_UPDATE) -> bytearray:
    data = bytearray()
    data.extend(pack("<B", message.board_index))
    return data

def deserialize_FW_UPDATE(data: bytearray) -> message_FW_UPDATE:
    message = message_FW_UPDATE()
    message.board_index = uint8(unpack("<B", data[0:1])[0])
    return message

