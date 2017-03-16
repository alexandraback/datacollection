#!/usr/bin/python

import sys

def isLast( A, B ):
    for i in xrange(0,len(A)):
        if A[i] > B[i]:
            return A
        if A[i] < B[i]:
            return B
    return A

def cm(PARTIES):
    total = 0
    for i in xrange(0,len(PARTIES)):
        total = total + PARTIES[i]
    mv = 0
    for i in xrange(0,len(PARTIES)):
        if PARTIES[i] > mv:
            mv = PARTIES[i]
    if  mv > total - mv:
        print total, mv
        assert False
#    print 'total',total, 'maj', mv, 'opp', total - mv
    

def brute( PARTIES ):
    while True:
        mi = 0;
        mv = -10000;
        nv = 0;
        ni = 0;
        left = 0
        for i in xrange(0,len(PARTIES)):
            if PARTIES[i] > 0:
                left = left + 1
            if PARTIES[i] > mv:
                if mv >= nv:
                    nv = mv
                    ni = mi
                mv = PARTIES[i]
                mi = i
            else:
                if PARTIES[i] > nv:
                    nv = PARTIES[i]
                    ni = i
        if mv == 0:
            print
            return
        if mv - nv >= 2:
            print '%c%c' % (mi + 0x41,mi+0x41),
            PARTIES[mi] = PARTIES[mi] - 2
        elif mv == nv and mv == 1 and left == 3:
            print '%c' % (mi + 0x41,),
            PARTIES[mi] = PARTIES[mi] - 1
        elif mv == nv:
            print '%c%c' % (mi + 0x41,ni+0x41),
            PARTIES[mi] = PARTIES[mi] - 1
            PARTIES[ni] = PARTIES[ni] - 1
        else:
            print '%c' % (mi + 0x41,),
            PARTIES[mi] = PARTIES[mi] - 1
        cm(PARTIES)


data = file(sys.argv[1]).read().splitlines()

NUMCASE = int(data.pop(0))

for CASE in xrange( 1, NUMCASE + 1 ):
    print 'Case #%d:' % ( CASE, ),
    N = int(data.pop(0))
    PARTIES = [int(x) for x in data.pop(0).split()]
    brute(PARTIES)



        
