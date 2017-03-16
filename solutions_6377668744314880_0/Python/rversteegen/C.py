#!/usr/bin/python



"""
On actually running this, it's obvious there was a simpler method that doesn't use 3 arrays,
but it's only about 10x faster, so not going to bother
"""

import sys
import math
import numpy as np
import time

def readline():
    return sys.stdin.readline().strip().split()

def readints():
    return [int(x) for x in readline()]


tstart = time.clock()

T, = readints()
for testcase in range(T):
    N, = readints()
    trees = []
    for n in range(N):
        trees.append(readints())
    trees = np.array(trees)

    dists = []  # N*N array

    print "Case #%d:" % ( testcase+1,)

    if N == 1:
        print 0
        continue

    for t1 in range(N):
        x = trees - trees[t1]  # length N
        #print t1, x
        x = np.delete(x, t1, 0)  # delete t1 = 0,0
        #print t1, x

        normals = np.c_[(x[:,1], -x[:,0])]
        #print normals
        #exit()

        least = 1e99

        for normal in normals:
            #print "norm",normal
            #print normal[None,:]
            prods = np.inner(x,normal[None,:])
            #print "prod", prods
            #exit()
            allnz = np.count_nonzero(prods)
            more = (prods > 0).sum()
            less = allnz - more
            #print "l,m", less, more
            least = min(least,less,more)
            #exit()
            
            #q = trees[None,:] - trees[t1]

        print least
        



#print "done in ",  time.clock() - tstart
