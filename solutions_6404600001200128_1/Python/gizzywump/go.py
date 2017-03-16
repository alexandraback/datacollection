#!/usr/bin/env python

import collections

import math
import re
import sys

#sys.setrecursionlimit(50)

INPUT = "tiny"
INPUT = "A-large.in"

def debug(*args):
    sys.stderr.write(str(args) + "\n")

#debug = lambda *args: None

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

def do_trial(N, M):
    debug(M)
    assert N == len(M)
    best_rate = 0
    min_eaten = 0
    last_m = M[0]
    for m in M[1:]:
        diff = max(0, last_m - m)
        best_rate = max(best_rate, diff)
        min_eaten += diff
        debug("%d %d => %d, total now %d, best_rate now %d" % (last_m, m, diff, min_eaten, best_rate))
        last_m = m
    debug("******** best_rate is %d" % best_rate)

    eaten_fixed_rate = 0
    last_m = M[0]
    for m in M[1:]:
        eaten = min(last_m, best_rate)
        eaten_fixed_rate += eaten
        debug("%d %d => %d total now %d" % (last_m, m, eaten, eaten_fixed_rate))
        last_m = m
    return min_eaten, eaten_fixed_rate


f = file(INPUT)
T = int(f.readline()[:-1])
for i in range(T):
    N, = [int(x) for x in f.readline().split()]
    M = [int(x) for x in f.readline().split()]
    v = do_trial(N, M)
    print "Case #%d: %d %d" % (i+1, v[0], v[1])
