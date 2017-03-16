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


tstart = time.clock()

T, = readints()
for testcase in range(T):
    N, = readints()
    M = np.array(readints())
    diffs = M[1:] - M[:-1]

    min1, min2 = 0,0
    minrate = max(-diffs)
    min1 = -diffs[diffs < 0].sum()
    last = M[0]
    # print "diffs", diffs
    # print "minrate", minrate
    # print "np.minimum(M[:-1], minrate)", np.minimum(M[:-1], minrate)
    min2 = np.minimum(M[:-1], minrate).sum()
    print "Case #%d: %d %d" % ( testcase+1,min1,min2)

#print "done in ",  time.clock() - tstart
