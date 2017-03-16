#!/usr/bin/python

"""
On actually running this, it's obvious there was a simpler method that doesn't use 3 arrays,
but it's only about 10x faster, so not going to bother
"""

import sys
import math
import numpy as np
import time

def readline():
    return sys.stdin.readline().strip().split()

def readints():
    return [int(x) for x in readline()]


def exp(a,n):
    if n == 1:
        return a
    return mult(exp(a,n/2), exp(a,n - n/2))

tstart = time.clock()

def up_to_time(n):
    return sum(max(0,1+n/mi) for mi in M)

def which_at_time(n):
    return [i for i,mi in enumerate(M) if n%mi == 0]

T, = readints()
for testcase in range(T):
    B,N = readints()
    M = readints()
    #N -= 1

    low = -1
    high = 100
    while up_to_time(high) < N:
        low = high
        high *= 2

    while low < high - 1:
        mid = (low + high) / 2
        if up_to_time(mid) < N:
            low = mid
        else:
            high = mid
    #low += 1

    lown = up_to_time(high)
    #print "M", M
    #print "N", N, "up_to_time(high-1)", up_to_time(high-1), "low", low, "high", high, "up_to(low)", up_to_time(low), "up_to(high)", lown
    assert lown >= N and up_to_time(high - 1) < N
    which = which_at_time(high)
    #print "which", which
    ret = which[N - up_to_time(high-1) - 1] + 1

    print "Case #%d: %d" % ( testcase+1,ret)
    

#print "done in ",  time.clock() - tstart
