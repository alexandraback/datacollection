#!/bin/env python

# google code jam 2015 problem 3
import math

def angle(p, q):
    px, py = p
    qx, qy = q
    dx = qx - px
    dy = qy - py
    a = math.atan2(dy, dx)
    a += math.pi
    a *= 180.0 / math.pi
    return a
    
def solve(p, qs):
    n = len(qs)
    a = []
    for q in qs:
	a.append(angle(p, q))
    a.sort()
    #print p, qs
    #print a
    b = [x + 360.0 for x in a]
    a += b
    #print a
    for d in range(n-1, 0, -1):
	minda = 1000
	for j in range(n):
	    da = a[j+d] - a[j]
	    minda = min(minda, da)
	nt = n-1 - d
	#print "nt=", nt, "minda=", minda
	if minda - 180.0 <= 1e-8:
	    return nt
    return 0

tests = int(raw_input())
for k in range(tests):
    n = int(raw_input())
    p = []
    for i in range(n):
	x, y = [int(x) for x in raw_input().split()]
	p.append((x, y))
    print "Case #%d:" % (k+1)
    for i in range(n):
	print solve(p[i], p[:i]+p[i+1:])
