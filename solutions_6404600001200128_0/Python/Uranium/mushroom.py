#!/usr/bin/env python

def solve_1(N, m):
    eat = 0
    for i in xrange(1, N):
        if m[i] < m[i-1]:
            eat += m[i-1] - m[i]
    return eat

def solve_2(N, m):
    max_interval = 0
    for i in xrange(1, N):
        ival = m[i-1] - m[i]
        max_interval = max(max_interval, ival)
    eat = 0
    for i in xrange(1, N):
        eat += min(max_interval, m[i-1])
    return eat

T = int(raw_input())
for t in xrange(T):
    N = int(raw_input())
    m = [int(x) for x in raw_input().rstrip().split()]
    print "Case #%d: %d %d" % (t+1, solve_1(N, m), solve_2(N, m))
