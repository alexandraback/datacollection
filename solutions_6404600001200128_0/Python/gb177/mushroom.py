#!/usr/bin/python

from fractions import Fraction as F
import sys

def NN(): return list(map(int, sys.stdin.readline().split()))

T = NN()[0]
for t in range(1, T + 1):
    N = NN()[0]
    m = NN()
    a1 = 0
    for i in range(len(m)-1):
        if m[i] > m[i+1]:
            a1 += m[i] - m[i+1]
        
    maxdown = max(m[i]-m[i+1] for i in range(len(m)-1))
    minrate = F(maxdown, 10)
    #print "m=", m
    #print "maxdown", maxdown
    #print "minrate", minrate
    a2 = 0
    for _m in m[:-1]:
        a2 += min(minrate * 10, _m)

    print "Case #%d: %d %d" % (t, a1, a2)

