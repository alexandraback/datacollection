#!/usr/bin/env python

import sys, operator as op, itertools as itt, math


F = sys.stdin
T = int( F.next() )

for case in xrange ( 1, T+1 ):
    R = int( F.next() )
    for i in xrange(1, 5):
        row = F.next()
        if i == R:
            row1 = map ( int, row.strip().split() )
    R = int( F.next() )
    for i in xrange(1, 5):
        row = F.next()
        if i == R:
            row2 = map ( int, row.strip().split() )
    x = set(row1).intersection( set(row2) )
    if len(x) == 1:
        print "Case #{0}: {1}".format( case, x.pop() )
    elif x:
        print "Case #{0}: {1}".format( case, "Bad magician!" )
    else:
        print "Case #{0}: {1}".format( case, "Volunteer cheated!" )


