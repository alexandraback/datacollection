#!/usr/bin/env python

from __future__ import print_function
from sys import argv,stdin

with open(argv[1]) if len(argv)>1 else stdin as f:
    num_cases = int(f.readline())
    for i in xrange(num_cases):
        row_idx1 = int(f.readline())
        arrangement1 = [f.readline() for j in xrange(4)]
        set1 = set(arrangement1[row_idx1-1].split())
        row_idx2 = int(f.readline())
        arrangement2 = [f.readline() for j in xrange(4)]
        set2 = set(arrangement2[row_idx2-1].split())
        sol = set1.intersection(set2)
        print('Case #%d: '%(i+1),end='')
        if len(sol) == 0:
            print('Volunteer cheated!')
        elif len(sol) == 1:
            print(sol.pop())
        else:
            print('Bad magician!')

