#!/usr/bin/env python

import sys

class Pt(object):
    def __init__(self, x, y):
        self.x = x
        self.y = y

def cross(i, j, k):
    ax = j.x - i.x
    ay = j.y - i.y
    bx = k.x - i.x
    by = k.y - i.y
    return ax * by - bx * ay

ls = sys.stdin.readlines()
ls = ls[1:]
nc = 1

while len(ls) > 0:
    n = int(ls[0])
    pls = ls[1:1+n]
    ls = ls[1+n:]
    xys = [p.split() for p in pls]
    ps = [Pt(int(x), int(y)) for (x, y) in xys]
    print "Case #%d:" % nc
    nc += 1
    if len(ps) == 1:
        print 0
        continue

    for i in xrange(len(ps)):
        best = 100000000000
        for j in xrange(len(ps)):
            if i == j:
                continue
            pos = 0
            neg = 0
            for k in xrange(len(ps)):
                if k == i or k == j:
                    continue
                x = cross(ps[i], ps[j], ps[k])
                if x > 0:
                    pos += 1
                elif x < 0:
                    neg += 1
            best = min(best, pos, neg)
        print best
