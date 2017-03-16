import sys
import itertools
import math
import collections
import functools

sys.setrecursionlimit(10000)

class memoized(object):
    def __init__(self, func):
        self.func = func
        self.cache = {}
    def __call__(self, *args):
        if args in self.cache:
            return self.cache[args]
        else:
            value = self.func(*args)
            self.cache[args] = value
            return value
    def __repr__(self):
        '''Return the function's docstring.'''
        return self.func.__doc__
    def __get__(self, obj, objtype):
        '''Support instance methods.'''
        return functools.partial(self.__call__, obj)
    def clear(self):
        self.cache = {}

def inputInts():
    return map(int, raw_input().split())

def solve1(v):
    prev = 0
    tot = 0

    for i in v:
        if i < prev:
            tot += prev - i
        prev = i

    return tot

def solve2(v):
    topSpeed = 0
    prev = 0

    for i in v:
        if i < prev:
            topSpeed = max(topSpeed, prev - i)
        prev = i

    tot = 0
    prev = 0
    for i in v:
        if prev < topSpeed:
            tot += prev
        else:
            tot += topSpeed
        prev = i

    return tot

T = int(raw_input())
for testId in range(T):
    input()
    v = inputInts()
    print "Case #{:d}: {:d} {:d}".format(testId+1, solve1(v), solve2(v))
