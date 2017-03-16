#!/usr/bin/python
from __future__ import division,print_function
import sys
import numpy as np     # http://www.numpy.org/
import scipy           # http://scipy.org/
import networkx as nx  # https://networkx.github.io/
import sympy           # http://www.sympy.org
import itertools
import operator
import string

range = xrange

sys.setrecursionlimit(5000)

def max2(l):
    return


def check(Pi):
    P = sum(Pi)
    N = len(Pi)
    for i in range(N):
        if Pi[i]*2>P: return False
    return True

def find_all(l,value):
    return [i for i, x in enumerate(l) if x == value]

def solve(Pi):
    N = len(Pi)
    P = sum(Pi)
    if P==0: return ""
    Pmax = max(Pi)
    indices = find_all(Pi,Pmax)
    idx = indices[0]
    Pnew = list(tuple(Pi))
    Pnew[idx] -= 1
    if check(Pnew):
        return chr(idx+ord('A')) +' '+solve(Pnew)
    else:
        Pnew = list(tuple(Pi))
        Pnew[indices[0]] -= 1
        Pnew[indices[1]] -= 1
        assert(check(Pnew))
        return chr(indices[0]+ord('A'))+chr(indices[1]+ord('A')) +' '+solve(Pnew)

T = int(sys.stdin.readline())
for t in range(1,T+1):
    N = sys.stdin.readline().strip()
    Pi = list(map(int,sys.stdin.readline().strip().split()))
    print("Case #%i: %s" % (t,solve(Pi)))
