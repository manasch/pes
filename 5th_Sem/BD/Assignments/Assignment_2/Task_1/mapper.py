#!/usr/bin/env python3

import sys

for line in sys.stdin:
    if line[0] != '#':
        line_split = line.strip().split()
        src = int(line_split[0])
        dst = int(line_split[1])

        print(src, dst, sep=' ')
