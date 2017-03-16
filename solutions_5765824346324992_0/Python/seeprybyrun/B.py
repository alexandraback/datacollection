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

# the following code is from
# http://stackoverflow.com/questions/147515/least-common-multiple-for-3-or-more-numbers
######
def gcd(a, b):
    """Return greatest common divisor using Euclid's Algorithm."""
    while b:      
        a, b = b, a % b
    return a

def lcm(a, b):
    """Return lowest common multiple."""
    return a * b // gcd(a, b)

def lcmm(*args):
    """Return lcm of args."""   
    return reduce(lcm, args)
######


def solve(N,M):
    # first attempt: brute-force
    B = len(M)

##    # how long until first sync-up? LCM elements of M
    syncTime = lcmm(*M)
    numCustomersPerSync = sum( [syncTime/m for m in M] )
##    print syncTime,numCustomersPerSync
    N %= numCustomersPerSync
    if N == 0:
        N = numCustomersPerSync

    # after a sync-up, simulate remaining customers
    minLeft = [0 for m in M] # number of minutes left until barber is free
    n = 1 # customer at head of line
    while n <= N:
        # check for free barbers
        for k in range(B):
            if minLeft[k] == 0:
                minLeft[k] = M[k]
                n += 1
                if n == N+1:
                    return k+1 # +1 since the barbers are 1-indexed
        # decrement each barber by 1
        minLeft = [m-1 for m in minLeft]

    return 'FAIL' # never get here!

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
    elif i%2 == 1: # tells us #barbers and place in line
        B,N = map(int,line.split())
    elif i%2 == 0: # tells us M_1,...,M_B
        M = map(int,line.split())
        print 'Case #{}: {}'.format(i/2,solve(N,M))
f.close()
