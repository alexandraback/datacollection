#!/usr/bin/env python
# -*- coding: utf-8 -*-


def readint():
    return int(raw_input())


def readarray(f):
    return map(f, raw_input().split())

T = readint()

for t in xrange(T):
    n = readint()
    a = readarray(int)
    now = None
    pre = None
    x1 = 0
    maxDis = 0
    for i, e in enumerate(a):
        now = a[i]
        if i != 0:
            if pre >= now:
                x1 += (pre - now)
            if pre - now > maxDis:
                maxDis = pre - now
        pre = now
    x2 = 0
    for i, e in enumerate(a):
        if i == len(a) - 1:
            break
        else:
            x2 += min(maxDis, a[i])
    print "Case #%d: %d %d" % (t+1, x1, x2)
