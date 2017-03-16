#!/usr/bin/python

def solve(ms):
    maxslope = 0
    for m, m2 in zip(ms, ms[1:]):
        maxslope = max(maxslope, m - m2)
    meth1 = 0
    meth2 = 0
    for m, m2 in zip(ms, ms[1:]):
        meth1 += max(m - m2, 0)
        meth2 += min(m, maxslope)
    return "%s %s" % (meth1, meth2)

T = int(raw_input())
for i in range(T):
    N = int(raw_input())
    ms = map(int, raw_input().split())
    print "Case #%i: %s" % (i+1, solve(ms))
