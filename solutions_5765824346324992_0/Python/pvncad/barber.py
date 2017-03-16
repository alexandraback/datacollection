#!/usr/local/bin/python

import sys
import math
import operator

T = int(sys.stdin.readline())

for caseno in xrange(T):
    B, N   = [int(x) for x in sys.stdin.readline().split()]
    times  = [int(x) for x in sys.stdin.readline().split()]

    low = 0
    high = N * min(times)

    while low < high:
        mid = (low + high) / 2

        #print low, high, mid
        count = 0
        for x in times:
            count += mid / x + 1

        if count >= N:
            #print "Yes"
            high = mid
        else:
            #print "No"
            low  = mid + 1

    #print "Time ", low
    if low == 0:
        cur = [0] * B
        total = 0
    else:
        cur = [ (b - (low- 1) % b) for b in times]

        total = sum([ (low- 1) / b for b in times]) + B


    #print cur, total
    idx = 0
    for x in xrange(total, N):
        idx, value = min(enumerate(cur), key=operator.itemgetter(1))
        cur[idx] += times[idx] 
        #print idx, cur

    print "Case #%d: %d" % (caseno + 1, idx + 1)


