#!/usr/bin/env python3
import sys

# Dictionary to map timestamp to frequency
timestamps = {}

for timestamp in sys.stdin:
    if timestamp.strip() not in timestamps.keys():
        timestamps[timestamp.strip()] = 1
    else:
        timestamps[timestamp.strip()] += 1

for t, v in sorted(timestamps.items()):
    print(t, v)
