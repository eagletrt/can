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
        errors,
        balancing_status
    ):
        self.errors = Errors(errors) if errors is not None else None
        self.balancing_status = BalancingStatus(balancing_status) if balancing_status is not None else None
        self.size = 2

    def serialize(self):
        data = bytearray()
        data.extend(pack("<BB", (int(self.errors) >> 0) & 255, self.balancing_status << 7 & 255))
        return data

    def deserialize(self, data):
        self.errors = Errors(int((unpack("<B", data[0:1])[0] << 0)))
        self.balancing_status = BalancingStatus((unpack("<xB", data[0:2])[0] & 128) >> 7)

    def __eq__(self, other):
        if not isinstance(other, message_BOARD_STATUS):
            return False
        if self.errors != other.errors:
            return False
        if self.balancing_status != other.balancing_status:
            return False
        return True


class message_TEMPERATURES:
    def __init__(
        self,
        start_index,
        temp0,
        temp1,
        temp2,
        temp3,
        temp4,
        temp5
    ):
        self.start_index = uint8(start_index) if start_index is not None else None
        self.temp0 = uint8(temp0) if temp0 is not None else None
        self.temp1 = uint8(temp1) if temp1 is not None else None
        self.temp2 = uint8(temp2) if temp2 is not None else None
        self.temp3 = uint8(temp3) if temp3 is not None else None
        self.temp4 = uint8(temp4) if temp4 is not None else None
        self.temp5 = uint8(temp5) if temp5 is not None else None
        self.size = 7

    def serialize(self):
        data = bytearray()
        data.extend(pack("<BBBBBBB", self.start_index, self.temp0, self.temp1, self.temp2, self.temp3, self.temp4, self.temp5))
        return data

    def deserialize(self, data):
        self.start_index = uint8(unpack("<B", data[0:1])[0])
        self.temp0 = uint8(unpack("<xB", data[0:2])[0])
        self.temp1 = uint8(unpack("<xxB", data[0:3])[0])
        self.temp2 = uint8(unpack("<xxxB", data[0:4])[0])
        self.temp3 = uint8(unpack("<xxxxB", data[0:5])[0])
        self.temp4 = uint8(unpack("<xxxxxB", data[0:6])[0])
        self.temp5 = uint8(unpack("<xxxxxxB", data[0:7])[0])

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


class message_VOLTAGES:
    def __init__(
        self,
        voltage0,
        voltage1,
        voltage2,
        start_index
    ):
        self.voltage0 = uint16(voltage0) if voltage0 is not None else None
        self.voltage1 = uint16(voltage1) if voltage1 is not None else None
        self.voltage2 = uint16(voltage2) if voltage2 is not None else None
        self.start_index = uint8(start_index) if start_index is not None else None
        self.size = 7

    def serialize(self):
        data = bytearray()
        data.extend(pack("<HHHB", self.voltage0, self.voltage1, self.voltage2, self.start_index))
        return data

    def deserialize(self, data):
        self.voltage0 = uint16(unpack("<H", data[0:2])[0])
        self.voltage1 = uint16(unpack("<xxH", data[0:4])[0])
        self.voltage2 = uint16(unpack("<xxxxH", data[0:6])[0])
        self.start_index = uint8(unpack("<xxxxxxB", data[0:7])[0])

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


class message_BALANCING:
    def __init__(
        self,
        cells,
        board_index
    ):
        self.cells = BalancingCells(cells) if cells is not None else None
        self.board_index = uint8(board_index) if board_index is not None else None
        self.size = 5

    def serialize(self):
        data = bytearray()
        data.extend(pack("<BBBBB", (int(self.cells) >> 24) & 255, (int(self.cells) >> 16) & 255, (int(self.cells) >> 8) & 255, (int(self.cells) >> 0) & 255, self.board_index))
        return data

    def deserialize(self, data):
        self.cells = BalancingCells(int((unpack("<BBBB", data[0:4])[0] << 24) | (unpack("<BBBB", data[0:4])[1] << 16) | (unpack("<BBBB", data[0:4])[2] << 8) | (unpack("<BBBB", data[0:4])[3] << 0)))
        self.board_index = uint8(unpack("<xxxxB", data[0:5])[0])

    def __eq__(self, other):
        if not isinstance(other, message_BALANCING):
            return False
        if self.cells != other.cells:
            return False
        if self.board_index != other.board_index:
            return False
        return True


class message_FW_UPDATE:
    def __init__(
        self,
        board_index
    ):
        self.board_index = uint8(board_index) if board_index is not None else None
        self.size = 1

    def serialize(self):
        data = bytearray()
        data.extend(pack("<B", self.board_index))
        return data

    def deserialize(self, data):
        self.board_index = uint8(unpack("<B", data[0:1])[0])

    def __eq__(self, other):
        if not isinstance(other, message_FW_UPDATE):
            return False
        if self.board_index != other.board_index:
            return False
        return True

