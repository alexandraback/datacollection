#!/usr/bin/python

import sys
from sympy import *

def find_mincut(angles, start):
    end = (start + pi) % (2*pi)
    start, end = min(start, end), max(start, end)
    side1 = len([i for i in angles if start < i < end])
    equal = len([i for i in angles if start == i or end == i])
    side2 = len(angles) - equal - side1
    return min(side1, side2)
    

def hullnum(trees, tree):
    relative = []
    angles = []
    for i in trees:
        if i != tree:
            relative.append((i[0] - tree[0], i[1] - tree[1]))

    for r in relative:
        angles.append(atan2(r[1], r[0]) % (2*pi))
    
    mincut = len(trees) - 1
    for start in angles:
        mincut = min(mincut, find_mincut(angles, start))
        if mincut == 0:
            break
    return mincut
        

cases = int(sys.stdin.readline())

for casenum in range(1, cases+1):
    treenum = int(sys.stdin.readline())
    trees = [tuple(map(int, sys.stdin.readline().split())) for _ in range(treenum)]
    
    print "Case #%s:" % (casenum)
    print >> sys.stderr, casenum

    for tree in trees:
        print(hullnum(trees, tree))
