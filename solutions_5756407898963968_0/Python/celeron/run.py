#!/usr/bin/env python

with open('input') as fin:
    N = int(fin.readline())
    for i in xrange(N):
        n = int(fin.readline())
        for j in xrange(4):
            if j + 1 == n:
                row1 = set(fin.readline().split())
            else:
                fin.readline()
        n = int(fin.readline())
        for j in xrange(4):
            if j + 1 == n:
                row2 = set(fin.readline().split())
            else:
                fin.readline()
        n = len(set.intersection(row1, row2))
        print 'Case #%d:' % (i+1),
        if n == 0:
            print 'Volunteer cheated!'
        elif n == 1:
            print list(set.intersection(row1, row2))[0]
        else:
            print 'Bad magician!'
