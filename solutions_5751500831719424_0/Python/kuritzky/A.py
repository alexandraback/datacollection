# -*- coding: utf-8 -*-
"""
Problem A. 
uses python 3.3

@author: Eric Kuritzky
"""
from collections import *
import itertools as itool
import operator as op
import functools as ft
from sys import argv, stdin, stdout, stderr
    
def errprt(*args, **kw):
    print(*args, file=stderr, **kw) 
    
def readcase(f):
    n, = readints(f)
    s = [f.readline().strip() for _ in range(n)]
    return s

def solvecase(ss):
    uniq = getuniq(ss[0])
    for s in ss[1:]:
        if uniq != getuniq(s):
            return"Fegla Won"
    c = [dupcnt(s) for s in ss]
    ans = 0
    for i in range(len(uniq)):
        m = median([cc[i] for cc in c])
        ans += sum(abs(m-cc[i]) for cc in c)
    return ans

def getuniq(s):
    return ''.join(a for a, b in zip(s,s[1:]+' ') if a != b)

def dupcnt(s):
    ans = []
    cur = s[0]
    cnt = 1
    for c in s[1:]:
        if c == cur:
            cnt += 1
        else:
            ans.append(cnt)
            cur = c
            cnt = 1
    ans.append(cnt)
    assert len(s) == sum(ans)
    return ans

def median(a):
    s = sorted(a)
    return s[len(s)//2]
	
def readints(f):
    return list(map(int, f.readline().strip().split(' ')))

def main():
    with open('A-small-attempt0.in') as f, open('out', 'w') as out:
        cases = int(f.readline())
        for ncase in range(1, cases+1):
            case = readcase(f)
            soln = solvecase(case)
            print('Case #%d: %s' % (ncase, soln))
            print('Case #%d: %s' % (ncase, soln), file=out)

from datetime import datetime

start = datetime.now()
print(str(start))
main()
stop = datetime.now()
print(str(stop))
print(str(stop-start))

