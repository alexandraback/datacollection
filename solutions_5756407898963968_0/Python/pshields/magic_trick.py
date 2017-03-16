#!/usr/bin/python3.4
import sys


Z = int(sys.stdin.readline().strip())

for test in range(Z):
    row_a = int(sys.stdin.readline().strip())
    grid_a = [[int(x) for x in sys.stdin.readline().strip().split()] for i in range(4)]
    possibilities = set(grid_a[row_a - 1])
    row_b = int(sys.stdin.readline().strip())
    grid_b = [[int(x) for x in sys.stdin.readline().strip().split()] for i in range(4)]
    possibilities &= set(grid_b[row_b - 1])
    if len(possibilities) == 0:
        o = "Volunteer cheated!"
    elif len(possibilities) == 1:
        o = "%d" % possibilities.pop()
    else:
        o = "Bad magician!"
    print("Case #%d: %s" % (test + 1, o))

