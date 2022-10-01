#!/usr/bin/env python3
import sys
import json
import math

dist = float(sys.argv[1].strip())
lat = float(sys.argv[2].strip())
lon = float(sys.argv[3].strip())

for line in sys.stdin:
    record = json.loads(line)

    if record["lat"] == None or record["lon"] == None:
        continue

    dlat = float(record["lat"]) - lat
    dlon = float(record["lon"]) - lon
    dist_range = math.sqrt(dlat**2 + dlon**2)
    
    if (dist_range <= dist \
        and float(record["humidity"]) > 48.00 and float(record["humidity"]) < 54.00 \
        and float(record["temperature"]) > 20.00 and float(record["temperature"]) < 24.00):

        print(record["timestamp"])
