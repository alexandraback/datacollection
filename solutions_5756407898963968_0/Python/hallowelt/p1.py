#!/usr/bin/python

import sys

cases = int(sys.stdin.readline())
for casenum in range(1, cases+1):
    poss = set([])
    row = int(sys.stdin.readline())
    for i in range(1, 5):
        rowset = set([int(z) for z in sys.stdin.readline().split()])
        if i == row:
            poss = rowset
    row = int(sys.stdin.readline())
    for i in range(1, 5):
        rowset = set([int(z) for z in sys.stdin.readline().split()])
        if i == row:
            poss &= rowset
    if len(poss) == 1:
        print "Case #{}: {}".format(casenum, list(poss)[0])
    elif len(poss) == 0:
        print "Case #{}: Volunteer cheated!".format(casenum)
    else:
        print "Case #{}: Bad magician!" .format(casenum)
