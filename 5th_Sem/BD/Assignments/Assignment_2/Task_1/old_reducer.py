#!/usr/bin/env python3

import sys

prev_node = -1
w_output = sys.argv[1]

with open(w_output, 'w') as w:
    for line in sys.stdin:
        line_split = line.strip().split(maxsplit=1)

        src = int(line_split[0])
        dests = [int(x) for x in line_split[1].strip('[]').split(',')]

        if src != prev_node:
            w.write(f'{src},1\n')
            if prev_node != -1:
                print('\b\b]')

            print(src, '[', sep='\t', end='')
            for dst in dests:
                print(dst, end=', ')

            prev_node = src
        else:
            for dst in dests:
                print(dst, end=' ')

print('\b\b]')
