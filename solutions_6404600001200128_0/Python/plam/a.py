#!/usr/bin/python

import sys

data = file(sys.argv[1]).read().splitlines()

T = int(data.pop(0))

def brute1(M):
    cur = M[0]
    eat = 0
    for i in xrange(1,len(M)):
        te = cur - M[i]
        cur = M[i]
        diff = max(0,te)
        eat = eat + diff
    return eat

def brute2(M):
    cur = M[0]
    eat = 0
    for i in xrange(1,len(M)):
        te = cur - M[i]
        cur = M[i]
        eat = max(eat,te)


    e = 0    
    for i in xrange(0,len(M)-1):
        e = e + min(M[i],eat)
    return e

for CASE in xrange(1,T+1):
    print 'Case #%d:' % (CASE),
    N = int(data.pop(0))
    M = [int(x) for x in data.pop(0).split()]
    print brute1(M), brute2(M)


