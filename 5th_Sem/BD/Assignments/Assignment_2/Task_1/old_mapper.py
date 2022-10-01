#!/usr/bin/env python3

import sys

paths = {}

for line in sys.stdin:
    if line[0] != '#':
        line_split = line.strip().split()

        source = int(line_split[0])
        dest = int(line_split[1])
        if source not in paths:
            paths[source] = [dest]
        else:
            paths[source].append(dest)

for src, dst in paths.items():
    print(src, dst)
