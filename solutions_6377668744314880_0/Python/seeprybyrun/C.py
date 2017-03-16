#!/usr/local/Cellar/python/2.7.9/Frameworks/Python.framework/Versions/2.7/bin/python2.7

import sys
from decimal import *
import itertools as it
from math import sqrt
from math import floor
from math import ceil
from math import log
from math import log10
from math import atan2
import math
import time
import random
import copy
import matplotlib.pyplot as plt

def solve(trees):
    
    numToRemove = [-1 for t in trees]
    #print trees
    N = len(trees)
    for t in range(N):
        r = trees[t]
        otherTrees = trees[:t] + trees[t+1:]
        otherTreeDirs = [atan2(s[1]-r[1],s[0]-r[0]) for s in otherTrees]
        currMin = N
        # for each pair of other trees:
        for i,j in it.combinations(range(len(otherTrees)),2):
            theta1 = min(otherTreeDirs[i],otherTreeDirs[j])
            theta2 = max(otherTreeDirs[i],otherTreeDirs[j])
            # find the smaller angle of intersection
            if theta2-theta1 == 0:
                currMin = min(currMin,len([theta for theta in otherTreeDirs if theta != theta1]))
            if theta2-theta1 <= math.pi:
                currMin = min(currMin,len([theta for theta in otherTreeDirs if theta < theta1 or theta > theta2]))
            if theta2-theta1 >= math.pi:
                currMin = min(currMin,len([theta for theta in otherTreeDirs if theta1 < theta < theta2]))
            if currMin == 0:
                break
        if currMin == N:
            currMin = 0
        numToRemove[t] = currMin
        
    return numToRemove

##f = open('temp','w')
##f.write('blah\n')
##for i in range(1,8):
##    f.write('blah\n')
##    f.write(' '.join(map(str,[random.randint(-1000,1000) for x in range(i)]))+'\n')
##    f.write(' '.join(map(str,[random.randint(-1000,1000) for x in range(i)]))+'\n')
##f.close()

infile = sys.argv[1]
f = open(infile,'r')
N = 0
trees = []
forestNum = 1
for i,line in enumerate(f.readlines()):
    line = line.strip()
    if not line:
        break # avoids problems with blank lines at eof

    if i == 0: # first line tells us # of test cases
        pass
    else:
        # end of previous forest
        if len(line.split()) == 1:
            if trees:
                print 'Case #{}:'.format(forestNum)
                for numToRemove in solve(trees):
                    print numToRemove
                forestNum += 1
##                xpts = [t[0] for t in trees]
##                ypts = [t[1] for t in trees]
##                plt.plot(xpts, ypts, 'ro')
##                plt.axis([min(xpts), 2*max(xpts), min(ypts), 2*max(ypts)])
##                plt.show()
                trees = []
        else: # continuation of current forest
            trees.append( map(int,line.split()) )
if trees:
    print 'Case #{}:'.format(forestNum)
    for numToRemove in solve(trees):
        print numToRemove
    forestNum += 1
    trees = []

f.close()
