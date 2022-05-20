import network

PrimaryHvErrors_s = network.primary_message_HV_ERRORS(21230, 9717)

print(f"Before: {PrimaryHvErrors_s.warnings} {PrimaryHvErrors_s.errors}")

data = PrimaryHvErrors_s.serialize()

PrimaryHvErrors_d = network.primary_message_HV_ERRORS(0, 0)
PrimaryHvErrors_d.deserialize(data)

print(f"After:  {PrimaryHvErrors_d.warnings} {PrimaryHvErrors_d.errors}")
