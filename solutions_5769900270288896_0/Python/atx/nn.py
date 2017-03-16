#! /usr/bin/python3

import sys
from itertools import combinations

tests = []

with open(sys.argv[1]) as f:
    for l in f.readlines():
        spl = l.split(" ")
        if len(spl) < 3:
            continue
        tests.append([int(spl[0]), int(spl[1]), int(spl[2])])

for n, test in enumerate(tests):
    R = test[0]
    C = test[1]
    N = test[2]

    best = R * C * 10
    for c in combinations(range(R * C), N):
        at = 0
        grid = []
        for _ in range(R):
            grid.append([False] * C)

        for h in c:
            x = int(h / C)
            y = h - (x * C)
            grid[x][y] = True

        for x in range(R):
            for y in range(C):
                if not grid[x][y]:
                    continue

                try:
                    if grid[x + 1][y]:
                        at += 1
                except:
                    pass
                try:
                    if grid[x][y + 1]:
                        at += 1
                except:
                    pass
        if at < best:
            best = at
    print("Case #%d: %d" % (n + 1, best))


