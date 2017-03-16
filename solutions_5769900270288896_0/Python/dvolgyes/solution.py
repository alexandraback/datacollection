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

def solve(R,C,N):
    array = np.zeros ( (R,C),dtype=np.bool )
    m = R*C*4
    for option in itertools.combinations(range(0,R*C),N):
        array.fill(False)
        array=array.flatten()
        array[list(option)] = True
        array = array.reshape(R,C)
        m = min(m,calc(array))
    return m

solutions = []
for case in range(0, T):
    R,C,N = map(int,map(string.strip,sys.stdin.readline().split()))
    solution = solve(R,C,N)
    solutions.append(solution)

for case in range(0, T):
    print "Case #%i: %s" % (case + 1, solutions[case])
    
