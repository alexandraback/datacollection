#!/usr/bin/python

import sys

# borrowed from http://wiki.python.org/moin/PythonDecoratorLibrary#Memoize
class memoized(object):
    """Decorator that caches a function's return value each time it is called.
    If called later with the same arguments, the cached value is returned, and
    not re-evaluated.
    """
    def __init__(self, func):
        self.func = func
        self.cache = {}
    def __call__(self, *args):
        try:
            return self.cache[args]
        except KeyError:
            value = self.func(*args)
            self.cache[args] = value
            return value
        except TypeError:
            # uncachable -- for instance, passing a list as an argument.
            # Better to not cache than to blow up entirely.
            return self.func(*args)
    def __repr__(self):
        """Return the function's docstring."""
        return self.func.__doc__
    def __get__(self, obj, objtype):
        """Support instance methods."""
        return functools.partial(self.__call__, obj)

def nbrs(tab, c, r):
    C = len(tab)
    R = len(tab[0])
    occ = tab[c][r]
    diff = 0
    same = 0
    for (dc, dr) in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
        if 0 <= c + dc < C and 0 <= r + dr < R:
            if occ == tab[c + dc][r + dr]:
                same += 1
            else:
                diff += 1
    return (diff, same)

def score(tab):
    C = len(tab)
    R = len(tab[0])
    total = 0
    for c in range(C):
        for r in range(R):
            occ = tab[c][r]
            diff, same = nbrs(tab, c, r)
            if occ:
                total += same
    return total / 2


from itertools import *
def slow_solve(R, C, N):
    minscore = float('inf')
    for locs in combinations(product(range(C), range(R)), N):
        tab = [[False for r in range(R)] for c in range(C)]
        for (c, r) in locs:
            tab[c][r] = True
        minscore = min(score(tab), minscore)
    return minscore

def solve(R, C, N):
    if C > R: return solve(C, R, N)

    tab = [[False for r in range(R)] for c in range(C)]
    for n in range(N):
        tab[n // R][n % R] = True

    while True:
        maxbad = (0, 0)
        maxbadval = 0
        mingood = (0, 0)
        mingoodval = 9

        for c in range(C):
            for r in range(R):
                occ = tab[c][r]
                diff, same = nbrs(tab, c, r)
                if occ and same > maxbadval:
                    maxbad = (c, r)
                    maxbadval = same
                if not occ and diff < mingoodval:
                    mingood = (c, r)
                    mingoodval = diff


        if maxbadval <= mingoodval:
            break

        #assert tab[maxbad[0]][maxbad[1]]
        #assert not tab[mingood[0]][mingood[1]]

        tab[maxbad[0]][maxbad[1]] = False
        tab[mingood[0]][mingood[1]] = True

    return score(tab)

T = int(raw_input())
for i in range(T):
    R, C, N = map(int, raw_input().split())
    print "Case #%i: %s" % (i+1, slow_solve(R, C, N))
    sys.stdout.flush()
