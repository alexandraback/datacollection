#!/usr/bin/env python

import collections
import itertools

import math
import re
import sys

#sys.setrecursionlimit(50)

INPUT = "tiny"
INPUT = "B-small-attempt0.in"

def debug(*args):
    return
    sys.stderr.write(str(args) + "\n")

class Memoize:
    def __init__(self,function):
        self._cache = {}
        self._callable = function
            
    def __call__(self, *args, **kwds):
        cache = self._cache
        key = self._getKey(*args,**kwds)
        try: return cache[key]
        except KeyError:
            cachedValue = cache[key] = self._callable(*args,**kwds)
            return cachedValue
    
    def _getKey(self,*args,**kwds):
        return kwds and (args, ImmutableDict(kwds)) or args    

def unhappiness_score(C, R, oa):
    s = 0
    for x in range(C-1):
        for y in range(R):
            if (x,y) in oa and (x+1,y) in oa:
                s += 1
    for x in range(C):
        for y in range(R-1):
            if (x,y) in oa and (x,y+1) in oa:
                s += 1
    return s


def do_trial(C, R, N):
    pairs = list(itertools.product(range(C), range(R)))
    us = int(1e9)
    for oa in itertools.combinations(pairs, N):
        us = min(us, unhappiness_score(C, R, set(oa)))
    return us

f = file(INPUT)
T = int(f.readline()[:-1])
for i in range(T):
    C, R, N = [int(x) for x in f.readline().split()]
    v = do_trial(C, R, N)
    print "Case #%d: %s" % (i+1, v)
