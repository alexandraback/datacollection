#!/usr/bin/env python

import sys

ls = sys.stdin.readlines()
ls = ls[1:]
nc = 1
while len(ls) >= 2:
    n = int(ls[0])
    xs = [int(x) for x in ls[1].split()]
    ls = ls[2:]

    a = 0
    mr = 0
    for i in xrange(n - 1):
        a += max(0, xs[i] - xs[i+1])
        mr = max(mr, xs[i] - xs[i+1])

    b = 0
    for i in xrange(n - 1):
        b += min(xs[i], mr)
    print "Case #%d: %d %d" % (nc, a, b)
    nc += 1
