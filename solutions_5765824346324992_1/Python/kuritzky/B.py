# -*- coding: utf-8 -*-
"""
Problem B. 
uses python 3.4.1

@author: Eric Kuritzky
"""
from collections import *
import itertools as ito
import operator as op
import functools as ft
from sys import argv, stdin, stdout, stderr, setrecursionlimit
from math import floor
from heapq import *

#setrecursionlimit(1000000)

errprt = ft.partial(print, file=stderr)    
    
def readcase(f):
    b, n = readints(f)
    rate = readints(f)
    assert b == len(rate)
    return (n, rate)

def solvecase(case):
    n, rate = case
    totalcps = sum(1/r for r in rate)
    t1 =  floor((n-1)/totalcps)
    while True:
        done = sum(t1//r + (t1%r > 0) for r in rate)
        if done < n:
            break
        t1 = floor(t1 + (n-1-done)/totalcps)
    heap = [t1 % r for r in rate]
    heap = [(r - h, i) if h > 0 else (0, i)
            for i, (r, h) in enumerate(zip(rate, heap))]
    heapify(heap)
    while done < n:
        (t, b) = heappop(heap)
        done += 1
        heappush(heap, (t + rate[b], b))
    return str(b+1)
        
	
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
    with open('B-large.in') as f, open('out', 'w') as out:
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
