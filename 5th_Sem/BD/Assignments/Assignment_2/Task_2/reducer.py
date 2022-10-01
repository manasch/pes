#!/usr/bin/env python3

import sys

prev_node = -1
contributions = 0

for line in sys.stdin:
    line_split = line.strip().split(maxsplit=1)

    node = int(line_split[0])
    contribution = float(line_split[1])

    if node != prev_node:
        if prev_node != -1:
            print(prev_node, "{:.2f}".format(round(0.34 + 0.57*contributions, 2)), sep=',')
            contributions = 0
        prev_node = node
    
    contributions += contribution

print(prev_node, "{:.2f}".format(round(0.34 + 0.57*contributions, 2)), sep=',')
