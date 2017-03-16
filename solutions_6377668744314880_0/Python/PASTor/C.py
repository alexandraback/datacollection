#!/usr/bin/python

import sys, decimal as d, collections as coll, itertools as it, fractions as f

def line(a, b, c):
    if a[0] == b[0]:
        # X equal
        res = 1 if c[0] > a[0] else -1
        res = 0 if c[0] == a[0] else res
        # print >>sys.stderr, 'res: ', res, c[0] > a[0], b[0] - a[0]
    else:
        res = c[1] - ((float(b[1]) - a[1]) / (float(b[0]) - a[0]) * float(c[0]) + a[1] - (float(b[1]) - a[1])/(float(b[0]) - a[0])*a[0] )
        # print >>sys.stderr, 'res: ', res
        if abs(res) < 0.000000000001:
            res = 0
        elif res > 0:
            res = 1
        else: 
            res = -1
    return res

T = int(raw_input())
tt = max(T/10, 1)

for c in xrange(T):
    print 'Case #{}:'.format(c+1),
    if c % tt == 0:
        print >>sys.stderr, 'Solving: ', (c+1)*100/T, '%'
    
    N = int(raw_input())
    
    points = []
    for i in xrange(N):
        points.append( map(int, raw_input().split()) )
    
    
    minn_res = []
    for a in points:
        # print >>sys.stderr, '==========================: '
        # print >>sys.stderr, 'a: ', a
        minn = 3000
        for b in points:           
            if a != b:
                # print >>sys.stderr, 'b: ', b
                left = 0
                right = 0
                for c in points:
                    if c != a and c != b:
                        # print >>sys.stderr, 'c: ', c, line(a, b, c)
                        if line(a, b, c) == 1:
                            left += 1
                        elif  line(a, b, c) == -1:
                            right += 1
                # print >>sys.stderr, 'Left, Right: ', left, right
                minn = min(minn, left, right)    
        minn_res.append(minn)
                
    print ''
    for res in minn_res:
        print res
            
    
