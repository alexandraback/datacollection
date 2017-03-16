#!/usr/bin/python
import sys
import numpy as np     # http://www.numpy.org/
import scipy           # http://scipy.org/
import networkx as nx  # https://networkx.github.io/
import sympy           # http://www.sympy.org
import itertools
import operator
import string

T = int(sys.stdin.readline())


def reverse(x):
    return int(str(x)[::-1])

def calc(array):
    s = 0
    for i in range(0,array.shape[0]):
        for j in range(0,array.shape[1]):
            if array[i,j] == False: continue
            if i+1< array.shape[0] and array[i+1,j]: s+=1
            if j+1< array.shape[1] and array[i,j+1]: s+=1
    return s


class GridIterator(object):

    def __init__(self,*args,**kwargs):
        if 'grid' in kwargs:
            self.grid = kwargs['grid']
        else:
            self.grid = args[0]
        self.ranges=[]
        for dim in self.grid.shape:
            self.ranges.append(tuple(xrange(0,dim) ))
        self.ranges = tuple(self.ranges)
        self.enabled = np.ones_like(self.grid).astype(np.bool)
        self.dimensions = len(self.grid.shape)

    def set(self,idx,val):
        self.enabled[tuple(idx)] = val
        
    def _add(self,a,b):
        return map(operator.add,a,b)

    def test(self,idx):
        for i in xrange(0,self.dimensions):
            if idx[i]<0 or idx[i]>=self.grid.shape[i]: return False
        return self.enabled[tuple(idx)]

    def _null(self,indices):
        for i in indices:
            if i!=0: return False
        return True

    def neighbours(self,indices):
        for idx in itertools.product( (-1,0,1), repeat = len(self.grid.shape) ):
            if abs(idx[0]+idx[1])!=1: continue
            candidate = self._add(indices,idx)
            if self.test(candidate):
                yield tuple(candidate)

    def count_neighbours(self,indices):
        return len(list(self.neighbours(indices)))

    def items(self):
        for i in itertools.product(*self.ranges):
            if self.test(i): yield i

def calcpos(array,idx,git):
    if array[idx] == False: return
    c=0
    for nidx in git.neighbours(idx):
        if array[nidx]: c+=1
    return c


def solve(R,C,N):
    array = np.ones ( (R,C),dtype=np.bool )
    RC = R*C
    NC = RC-N
    git = GridIterator(array)

    #4
    cnt = 0
    for options in (4,3,2,1):
        if cnt<NC:
            for idx in git.items():
                if calcpos(array,idx,git) == options:
                    array[idx] = False
                    cnt +=1
                    if cnt==NC: break
    
    r= min(calc(array),calc( np.roll(array.flatten(),1).reshape(R,C)))
    return r

solutions = []
for case in range(0, T):
    R,C,N = map(int,map(string.strip,sys.stdin.readline().split()))
    R,C = min(R,C),max(R,C)
    solution = solve(R,C,N)
    solutions.append(solution)

for case in range(0, T):
    print "Case #%i: %s" % (case + 1, solutions[case])
    
