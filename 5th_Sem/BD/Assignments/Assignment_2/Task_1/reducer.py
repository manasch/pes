#!/usr/bin/env python3

import sys

prev_node = -1
w_output = sys.argv[1]

with open(w_output, 'w') as w:
    for line in sys.stdin:
        line_split = line.strip().split()

        src = int(line_split[0])
        dst = int(line_split[1])

        if src != prev_node:
            w.write(f'{src},1\n')

            if prev_node != -1:
                print(']')

            print(f'{src}\t[{dst}', end='')
            prev_node = src
        else:
            print(f', {dst}', end='')
print(']')
