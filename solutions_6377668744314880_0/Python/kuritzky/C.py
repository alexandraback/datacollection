# -*- coding: utf-8 -*-
"""
Problem C. 
uses python 3.4.1

@author: Eric Kuritzky
"""
from collections import *
import itertools as ito
import operator as op
import functools as ft
from sys import argv, stdin, stdout, stderr, setrecursionlimit

#setrecursionlimit(1000000)

errprt = ft.partial(print, file=stderr)    
    
def readcase(f):
    ntrees, = readints(f)
    tree = []
    for i in range(ntrees):
        tree.append(readints(f))
    return tree

def solvecase(tree):
    if len(tree)==1:
        return '0'
    bestlst = []
    for tree0 in tree:
        best = len(tree)
        for tree1 in tree:
            if tree0 == tree1:
                continue
            perp = [tree0[1]-tree1[1], tree1[0]-tree0[0]]
            npos = nneg = 0
            for tree2 in tree:
                dot = sum(p*(t2-t0) for p, t2, t0 in zip(perp, tree2, tree0))
                if dot > 0:
                    npos += 1
                elif dot < 0:
                    nneg += 1
            best = min(best, npos, nneg)
        bestlst.append(best)
    return '\n'.join(str(best) for best in bestlst)
	
def readints(f):
    return list(map(int, f.readline().strip().split(' ')))

def readflds(f, types):
    if isinstance(types, tuple):
        return [typ(fld) for fld, typ
                in zip(f.readline().strip().split(),
                       ito.chain(types, ito.repeat(types[-1])))]
    else:
        return [types(fld) for fld in f.readline().strip().split()]

def main():
    with open('C-small-attempt1.in') as f, open('out', 'w') as out:
        cases = int(f.readline())
        for ncase in range(1, cases+1):
            case = readcase(f)
            soln = solvecase(case)
            print('Case #%d:\n%s' % (ncase, soln))
            print('Case #%d:\n%s' % (ncase, soln), file=out)

from datetime import datetime

start = datetime.now()
print(str(start))
main()
stop = datetime.now()
print(str(stop-start))
