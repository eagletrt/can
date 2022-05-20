from enum import IntEnum, IntFlag
from struct import pack, unpack

def bms_int8(value):
    return int(value)

def bms_uint8(value):
    return int(value)

def bms_int16(value):
    return int(value)

def bms_uint16(value):
    return int(value)

def bms_int32(value):
    return int(value)

def bms_uint32(value):
    return int(value)

def bms_int64(value):
    return int(value)

def bms_uint64(value):
    return int(value)

def bms_float32(value):
    return float(value)

def bms_float64(value):
    return float(value)

def bms_bool(value):
    return bool(value)


# Bitsets

class bms_Errors(IntFlag):
    CAN_COMM = 2
    LTC_COMM = 4
    TEMP_COMM_0 = 8
    TEMP_COMM_1 = 16
    TEMP_COMM_2 = 32
    TEMP_COMM_3 = 64
    TEMP_COMM_4 = 128
    TEMP_COMM_5 = 256

class bms_BalancingCells(IntFlag):
    CELL0 = 2
    CELL1 = 4
    CELL2 = 8
    CELL3 = 16
    CELL4 = 32
    CELL5 = 64
    CELL6 = 128
    CELL7 = 256
    CELL8 = 512
    CELL9 = 1024
    CELL10 = 2048
    CELL11 = 4096
    CELL12 = 8192
    CELL13 = 16384
    CELL14 = 32768
    CELL15 = 65536
    CELL16 = 131072
    CELL17 = 262144

# Enums

class bms_BalancingStatus(IntEnum):
    OFF = 1
    DISCHARGE = 2

# Messages


class bms_message_BOARD_STATUS:
    def __init__(
        self,
        errors,
        balancing_status
    ):
        self.errors = bms_Errors(errors) if errors is not None else None
        self.balancing_status = bms_BalancingStatus(balancing_status) if balancing_status is not None else None
        self.size = 2

    def serialize(self):
        data = bytearray()
        data.extend(pack("<BB", (int(self.errors) >> 0) & 255, self.balancing_status << 7 & 255))
        return data

    def deserialize(self, data):
        self.errors = bms_Errors(int((unpack("<B", data[0:1])[0] << 0)))
        self.balancing_status = bms_BalancingStatus((unpack("<xB", data[0:2])[0] & 128) >> 7)

    def __eq__(self, other):
        if not isinstance(other, bms_message_BOARD_STATUS):
            return False
        if self.errors != other.errors:
            return False
        if self.balancing_status != other.balancing_status:
            return False
        return True


class bms_message_TEMPERATURES:
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
        self.start_index = bms_uint8(start_index) if start_index is not None else None
        self.temp0 = bms_uint8(temp0) if temp0 is not None else None
        self.temp1 = bms_uint8(temp1) if temp1 is not None else None
        self.temp2 = bms_uint8(temp2) if temp2 is not None else None
        self.temp3 = bms_uint8(temp3) if temp3 is not None else None
        self.temp4 = bms_uint8(temp4) if temp4 is not None else None
        self.temp5 = bms_uint8(temp5) if temp5 is not None else None
        self.size = 7

    def serialize(self):
        data = bytearray()
        data.extend(pack("<BBBBBBB", self.start_index, self.temp0, self.temp1, self.temp2, self.temp3, self.temp4, self.temp5))
        return data

    def deserialize(self, data):
        self.start_index = bms_uint8(unpack("<B", data[0:1])[0])
        self.temp0 = bms_uint8(unpack("<xB", data[0:2])[0])
        self.temp1 = bms_uint8(unpack("<xxB", data[0:3])[0])
        self.temp2 = bms_uint8(unpack("<xxxB", data[0:4])[0])
        self.temp3 = bms_uint8(unpack("<xxxxB", data[0:5])[0])
        self.temp4 = bms_uint8(unpack("<xxxxxB", data[0:6])[0])
        self.temp5 = bms_uint8(unpack("<xxxxxxB", data[0:7])[0])

    def __eq__(self, other):
        if not isinstance(other, bms_message_TEMPERATURES):
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


class bms_message_VOLTAGES:
    def __init__(
        self,
        voltage0,
        voltage1,
        voltage2,
        start_index
    ):
        self.voltage0 = bms_uint16(voltage0) if voltage0 is not None else None
        self.voltage1 = bms_uint16(voltage1) if voltage1 is not None else None
        self.voltage2 = bms_uint16(voltage2) if voltage2 is not None else None
        self.start_index = bms_uint8(start_index) if start_index is not None else None
        self.size = 7

    def serialize(self):
        data = bytearray()
        data.extend(pack("<HHHB", self.voltage0, self.voltage1, self.voltage2, self.start_index))
        return data

    def deserialize(self, data):
        self.voltage0 = bms_uint16(unpack("<H", data[0:2])[0])
        self.voltage1 = bms_uint16(unpack("<xxH", data[0:4])[0])
        self.voltage2 = bms_uint16(unpack("<xxxxH", data[0:6])[0])
        self.start_index = bms_uint8(unpack("<xxxxxxB", data[0:7])[0])

    def __eq__(self, other):
        if not isinstance(other, bms_message_VOLTAGES):
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


class bms_message_BALANCING:
    def __init__(
        self,
        cells,
        board_index
    ):
        self.cells = bms_BalancingCells(cells) if cells is not None else None
        self.board_index = bms_uint8(board_index) if board_index is not None else None
        self.size = 5

    def serialize(self):
        data = bytearray()
        data.extend(pack("<BBBB", (int(self.cells) >> 24) & 255, (int(self.cells) >> 16) & 255, (int(self.cells) >> 8) & 255, (int(self.cells) >> 0) & 255, self.board_index))
        return data

    def deserialize(self, data):
        self.cells = bms_BalancingCells(int((unpack("<BBB", data[0:4])[0] << 24) | (unpack("<BBB", data[0:4])[1] << 16) | (unpack("<BBB", data[0:4])[2] << 8) | (unpack("<BBB", data[0:4])[3] << 0)))
        self.board_index = bms_uint8(unpack("<xxxxB", data[0:5])[0])

    def __eq__(self, other):
        if not isinstance(other, bms_message_BALANCING):
            return False
        if self.cells != other.cells:
            return False
        if self.board_index != other.board_index:
            return False
        return True


class bms_message_FW_UPDATE:
    def __init__(
        self,
        board_index
    ):
        self.board_index = bms_uint8(board_index) if board_index is not None else None
        self.size = 1

    def serialize(self):
        data = bytearray()
        data.extend(pack("<B", self.board_index))
        return data

    def deserialize(self, data):
        self.board_index = bms_uint8(unpack("<B", data[0:1])[0])

    def __eq__(self, other):
        if not isinstance(other, bms_message_FW_UPDATE):
            return False
        if self.board_index != other.board_index:
            return False
        return True

