#!/usr/bin/env python3
import sys
import json

for line in sys.stdin:
    record = json.loads(line)

    if (float(record["location"]) < 2500 and float(record["location"]) > 1700 \
        and float(record["sensor_id"]) < 5000 \
        and float(record["pressure"]) >= 93500.00 \
        and float(record["humidity"]) >= 72.00 \
        and float(record["temperature"]) >= 12.00):

        print(record["timestamp"])
