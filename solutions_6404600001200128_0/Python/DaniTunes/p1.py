#!/bin/env python

# google code jam 2015 problem 1

def solve(ms):
    a = 0
    n = len(ms)
    md = 0
    for i in range(1, n):
	d = ms[i-1] - ms[i]
	md = max(d, md)
	if d > 0:
	    a += d
    b = 0
    for i in range(0, n-1):
	b += min(ms[i], md)
    return a, b

tests = int(raw_input())
for k in range(tests):
    n = int(raw_input())
    ms = [int(x) for x in raw_input().split()]
    #print n, len(ms), ms
    a, b = solve(ms)
    print "Case #%d: %d %d" % (k+1, a, b)
