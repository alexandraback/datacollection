#!/usr/bin/env python
import math
def solve(line):
    n = int(line)
    line = raw_input()
    mushrooms = line.split()

    count1, count2 = 0, 0
    speed = 0
    for i in xrange(n):
        mushrooms[i] = int(mushrooms[i])
    for i in xrange(1, n):
        if mushrooms[i] < mushrooms[i-1]:
            count1 += mushrooms[i-1] - mushrooms[i]
            speed = max((mushrooms[i-1] - mushrooms[i]) / 10.0, speed)
    if count1 > 0:
        for i in xrange(1, n):
            count2 += min(mushrooms[i-1], int(speed * 10))
    return count1, count2

case_num = input()
for case in range(1, case_num + 1):
    line = raw_input()
    a1, a2 = solve(line)
    print("Case #%i: %i %i" % (case, a1, a2))

