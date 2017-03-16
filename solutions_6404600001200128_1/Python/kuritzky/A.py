# -*- coding: utf-8 -*-
"""
Problem A. 
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
    nintv, = readints(f)
    mush = readints(f)
    assert len(mush) == nintv
    return mush

def solvecase(mush):
    ans1 = sum(max(old - new, 0) for old, new in zip(mush, mush[1:]))
    rate = max(old - new for old, new in zip(mush, mush[1:]))
    ans2 = sum(min(old, rate) for old, new in zip(mush, mush[1:]))
    return '%d %d' % (ans1, ans2)
	
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
    with open('A-large.in') as f, open('out', 'w') as out:
        cases = int(f.readline())
        for ncase in range(1, cases+1):
            case = readcase(f)
            soln = solvecase(case)
            print('Case #%d: %s' % (ncase, soln))
            print('Case #%d: %s' % (ncase, soln), file=out)

from datetime import datetime

if __name__ == '__main__':
    start = datetime.now()
    print(str(start))
    main()
    stop = datetime.now()
    print(str(stop-start))
