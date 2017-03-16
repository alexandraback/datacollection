#!/usr/bin/env python
#-*-coding: utf-8 -*-
import sys
import string

def readint(): return int(raw_input())
def readarray(f): return map(f, raw_input().split())

ab = list(string.ascii_uppercase)
T = readint()

def majority(nb):
    return nb / 2 + 1

for t in xrange(1, T + 1):
    N = readint()
    P = readarray(int)
    mps = sum(P)
    res = list()
    while mps > 0:
        pair = list()
        # First MP
        i0 = 0
        for i in xrange(N):
            if P[i] > P[i0]:
                i0 = i
        pair.append(ab[i0])
        mps -= 1
        if mps == 0:
            res.append(''.join(pair))
            break
        P[i0] -= 1
        # Second MP
        one = 0
        two = 0
        for i in xrange(N):
            if P[i] >= P[one]:
                two = one
                one = i
            elif P[i] > P[two]:
                two = i
        if majority(mps - 1) > max(P[one] - 1, P[two]):
            pair.append(ab[one])
            P[one] -= 1
            mps -= 1
            res.append(''.join(pair))
        else:
            res.append(''.join(pair))
    print "Case #%d: %s" % (t, ' '.join(res))
