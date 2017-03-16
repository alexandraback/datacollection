#!/usr/local/bin/python

import sys
import math

T = int(sys.stdin.readline())

for caseno in xrange(T):
    N = int(sys.stdin.readline())
    snap = [int(x) for x in sys.stdin.readline().split()]

    ans1 = 0
    speed = 0
    for idx, x in enumerate(snap):
        if idx == 0:
            prev = x
            continue

        if prev > x:
            ans1 += prev - x
            speed = max(speed, (prev - x) / 10.0)

        prev = x

    ans2 = 0
    for idx, x in enumerate(snap):
        if idx != len(snap) - 1:
            ans2 += min(x, int(speed * 10))

    print "Case #%d: %d %d" % (caseno + 1, ans1, ans2)


