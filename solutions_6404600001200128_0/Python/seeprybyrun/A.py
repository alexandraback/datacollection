#!/usr/local/Cellar/python/2.7.9/Frameworks/Python.framework/Versions/2.7/bin/python2.7

import sys
from decimal import *
import itertools as it
from math import sqrt
from math import floor
from math import ceil
from math import log
from math import log10
import time
import random

def solve(M):
    N = len(M)
    m1 = sum( [max(M[i] - M[i+1],0) for i in range(N-1)] )

    rate = max( [M[i]-M[i+1] for i in range(N-1)] )
    m2 = sum( [min(rate,M[i]) for i in range(N-1)] )
    
    return '{} {}'.format(m1,m2)

##f = open('temp','w')
##f.write('blah\n')
##for i in range(1,8):
##    f.write('blah\n')
##    f.write(' '.join(map(str,[random.randint(-1000,1000) for x in range(i)]))+'\n')
##    f.write(' '.join(map(str,[random.randint(-1000,1000) for x in range(i)]))+'\n')
##f.close()

infile = sys.argv[1]
f = open(infile,'r')
for i,line in enumerate(f.readlines()):
    line = line.strip()
    if not line:
        break # avoids problems with blank lines at eof

    if i == 0: # first line tells us # of test cases
        pass
    elif i%2 == 1: # tells us # of time intervals
        pass
    elif i%2 == 0: # tells us # of mushrooms at each time interval
        M = map(int,line.split())
        print 'Case #{}: {}'.format(i/2,solve(M))
f.close()
