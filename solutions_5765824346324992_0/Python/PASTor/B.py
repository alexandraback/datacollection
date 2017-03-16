#!/usr/bin/python

import sys, decimal as d, collections as coll, itertools as it, fractions as f


def gcd(a, b):
    while b:      
        a, b = b, a % b
    return a
    
def lcm(a, b):
    return a * b / gcd(a, b)


T = int(raw_input())
tt = max(T/10, 1)

for c in xrange(T):
    print 'Case #{}:'.format(c+1),
    if c % tt == 0:
        print >>sys.stderr, 'Solving: ', (c+1)*100/T, '%'
    
    B, N = map(int, raw_input().split())
    
    N -= 1
    
    m = map(int, raw_input().split())
    
    #Calc the period
    maxtime = reduce(lcm, m)
    period_people = sum([ (maxtime / i) for i in m])
    
    # print >>sys.stderr, 'Period people: ', period_people
    
    if N >= period_people:
        N = N % period_people
        
        
    # print >>sys.stderr, 'N: ', N
    
    minn = 0
    n = [0 for i in xrange(B)]
    while N >= 0:
        N -= 1
        
        minn = 0
        for i in xrange(1, B):
            if n[minn] > n[i]:
                minn = i
                
        n[minn] += m[minn]
        # print >>sys.stderr, 'n: ', n
    
    
    print minn+1
            
    
