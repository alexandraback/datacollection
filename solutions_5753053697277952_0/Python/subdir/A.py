#!/usr/bin/python

import sys
from heapq import heapify, heappop, heappush


def solve(P):
    '''
    >>> list(solve([1]))
    [[0]]
    >>> list(solve([3]))
    [[0], [0], [0]]
    >>> list(solve([1, 1]))
    [[0, 1]]
    >>> list(solve([3, 3]))
    [[0, 1], [0, 1], [0, 1]]
    >>> list(solve([2, 3]))
    [[1], [0, 1], [0, 1]]
    >>> list(solve([2, 3, 5]))
    [[2], [2], [1], [2], [0], [1], [2], [0], [1, 2]]
    '''
    pheap = [(-s, i) for i, s in enumerate(P)]
    heapify(pheap)
    while not (len(pheap) <= 2 and len(set(s for s, p in pheap)) <= 1):
        half = sum(-s for s, p in pheap) // 2
        assert all(-s <= half for s, p in pheap)

        minus_senators, party = heappop(pheap)
        senators = -minus_senators
        senators_left = senators - 1
        yield [party]
        if senators_left > 0:
            heappush(pheap, (-senators_left, party))

    for x in xrange(-pheap[0][0]):
        yield [p for s, p in pheap]


def fmt(res):
    r = []
    for ss in res:
        r.append("".join(chr(ord('A') + s) for s in ss))
    return " ".join(r)


def main():
    N = int(next(sys.stdin))
    for i in xrange(1, N+1):
        N = int(next(sys.stdin))
        P = map(int, next(sys.stdin).split())
        print "Case #{}:".format(i), fmt(solve(P))


if __name__ == '__main__':
    main()

