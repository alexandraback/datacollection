#!/usr/bin/env python

import collections

import math
import re
import sys

#sys.setrecursionlimit(50)

INPUT = "tiny"
INPUT = "B-small-attempt1.in"
INPUT = "B-large.in"

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

def gcd(a, b):
    while 1:
        if a > b: b,a = a,b
        if a == 0: return b
        b %= a

def gcdm(*args):
    return reduce(gcd, args)

def lcm(a, b):
    return (a*b) / gcd(a,b)

def lcmm(*args):
    return reduce(lcm, args)

def view_at_time(M, T):
    mods = [divmod(T, b) for b in M]
    q = tuple(m[0] for m in mods)
    r = tuple(m[1] for m in mods)
    return q, r

def do_trial(B, N, M):
    haircuts_per_minute = 1/(sum(1.0/m for m in M))
    biggest_m = max(M)
    early_time = int(N * haircuts_per_minute) - biggest_m
    late_time = early_time + biggest_m * 4

    while early_time < late_time:
        t = (early_time + late_time) // 2
        debug("early, t, late_time = %d %d %d" % (early_time, t, late_time))
        q, r = view_at_time(M, t)
        finished = sum(q)
        if finished >= N:
            late_time = t
        else:
            early_time = t + 1

    t -= 1000
    q, r = view_at_time(M, t)
    busy_table = [t - r1 for r1 in r]
    N -= sum(q)
    debug(busy_table, N)
    assert B == len(M)
    while 1:
        smallest_busy = min(busy_table)
        debug("%s %d %d" % (busy_table, smallest_busy, N))
        for idx, b in enumerate(busy_table):
            if b == smallest_busy:
                if N == 1:
                    return idx + 1
                N -= 1
                busy_table[idx] += M[idx]


f = file(INPUT)
T = int(f.readline()[:-1])
for i in range(T):
    B, N = [int(x) for x in f.readline().split()]
    M = [int(x) for x in f.readline().split()]
    v = do_trial(B, N, M)
    print "Case #%d: %s" % (i+1, v)
