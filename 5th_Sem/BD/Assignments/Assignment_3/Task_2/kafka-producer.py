#!usr/bin/env python3

import sys
import csv
import json
from kafka import KafkaProducer

topic_name = sys.argv[1]

producer = KafkaProducer(bootstrap_servers=['localhost:9092'], value_serializer=lambda x: json.dumps(x).encode('utf8'))
for line in csv.reader(sys.stdin):
    if line[0] == "EOF":
        producer.send(topic_name, {
                "state": "EOF"
                })
        break

    producer.send(topic_name, {
        "state": line[0],
        "max": line[7],
        "min": line[6]
    })

producer.flush()
producer.close()
