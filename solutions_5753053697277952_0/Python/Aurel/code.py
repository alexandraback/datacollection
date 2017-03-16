import sys
import itertools
import math
import collections
import functools

sys.setrecursionlimit(10000)

def inputInts():
    return map(int, raw_input().split())


T = int(raw_input())
for testId in range(T):
    N, = inputInts()
    v = inputInts()

    d = {}
    total = 0
    for i in xrange(N):
        d[str(unichr(65+i))] = v[i]
        total += v[i]

    res = []
    while total > 0:
        order = sorted(d, key=d.__getitem__, reverse=True)
        if d[order[1]] <= (total - 1) / 2:
            res.append(order[0])
            d[order[0]] -= 1
            total -= 1
        else:
            res.append(order[0] + order[1])
            d[order[0]] -= 1
            d[order[1]] -= 1
            total -= 2

    print "Case #{:d}: {:s}".format(testId+1, ' '.join(res))
