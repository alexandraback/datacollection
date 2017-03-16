#!/usr/bin/env python

import itertools

def share_wall(x, y):
    dx = abs(x[0] - y[0])
    dy = abs(x[1] - y[1])

    return (dx == 1 and dy == 0) or (dx == 0 and dy == 1)

def unhappy(c):
    h = 0
    for k in itertools.combinations(c, 2):
        if share_wall(k[0], k[1]):
            h += 1
    return h

def solve(R, C, N):
    coords = itertools.product(range(R), range(C))

    min_happy = 99999
    for sel in itertools.combinations(coords, N):
        min_happy = min(unhappy(sel), min_happy)

    return min_happy

T = int(raw_input())
for t in xrange(T):
    R, C, N = [int(x) for x in raw_input().rstrip().split()]
    print "Case #%d: %d" % (t+1, solve(R, C, N))
