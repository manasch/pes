#!usr/bin/env python3

import sys
import json
from kafka import KafkaConsumer

topic_name = sys.argv[1]

consumer = KafkaConsumer(topic_name, bootstrap_servers=['localhost:9092'], value_deserializer=lambda x: json.loads(x.decode('utf8')))
avg_min_max = dict()
entry = dict()
for msg in consumer:
    entry = msg.value
    if entry["state"] == "EOF":
        break
    
    if entry["state"] not in avg_min_max.keys():
        avg_min_max[entry["state"]] = {
            "max": [float(entry["max"])],
            "min": [float(entry["min"])]
        }
    else:
        avg_min_max[entry["state"]]["max"].append(float(entry["max"]))
        avg_min_max[entry["state"]]["min"].append(float(entry["min"]))

out = dict()
for state, min_max in sorted(avg_min_max.items()):
    out[state] = {
        "Min": round(sum(min_max["min"]) / len(min_max["min"]), 2),
        "Max": round(sum(min_max["max"]) / len(min_max["max"]), 2)
    }

print(json.dumps(out, indent=4))
consumer.close()
