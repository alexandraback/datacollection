#!/usr/bin/python


import sys, io

T = int(sys.stdin.readline())
for t in range(T):
    aa = int(sys.stdin.readline())
    a = []
    for i in xrange(4):
        a.append(map(int, sys.stdin.readline().split()))
    ba = int(sys.stdin.readline())
    b = []
    for i in xrange(4):
        b.append(map(int, sys.stdin.readline().split()))
        
    a = a[aa-1]
    b = b[ba-1]
    #print a, b
    
    c = 0
    for i in xrange(4):
        for j in xrange(4):
            #print i,a[i], j, b[j]
            if a[i] == b[j]: 
                c += 1
                k = i
    
    print 'Case #%d:' % (t+1),
    if c == 0: print 'Volunteer cheated!'
    elif c == 1: print a[k]
    else: print 'Bad magician!'
    
    
