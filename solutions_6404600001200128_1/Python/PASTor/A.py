#!/usr/bin/python

import sys, decimal as d, collections as coll, itertools as it, fractions as f, math



T = int(raw_input())
tt = max(T/10, 1)

for c in xrange(T):
    print 'Case #{}:'.format(c+1),
    if c % tt == 0:
        print >>sys.stderr, 'Solving: ', (c+1)*100/T, '%'
    
    N = int(raw_input())
    a = map(int, raw_input().split())
    
    res1, res2 = 0, 0
    
    prev = a[0]
    maxx = 0
    
    for i in xrange(1,N):
        if a[i] < prev:
            res1 += prev - a[i]
            maxx = max(maxx, prev - a[i])
        prev = a[i]
    
    
    rest = a[0]
    speed = maxx
    
    for i in xrange(1,N):
        if rest >= maxx:
            res2 += maxx
        else:
            res2 += rest
        rest = a[i]
           
    
    print res1, res2
            
    
