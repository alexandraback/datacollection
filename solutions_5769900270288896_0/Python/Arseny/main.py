#!/usr/bin/python

import sys
from heapq import *
from itertools import *


def solve(R, C, N):
    Q = []
    unhappiness = {}

    total_unhappiness = 0
    for i in xrange(1, R + 1):
        for j in xrange(1, C + 1):
            unhappy = 0
            if i > 1:
                unhappy+= 1
            if i < R:
                unhappy+= 1
            if j > 1:
                unhappy+= 1
            if j < C:
                unhappy+= 1
            unhappiness[(i, j)] = unhappy
            total_unhappiness+= unhappy
            heappush(Q, (-unhappy, i, j))

    total_unhappiness/= 2

    to_free = R * C - N
    while to_free:
        unhappy, i, j = heappop(Q)
        unhappy = -unhappy
        if (unhappiness[(i,j)] != unhappy):
            continue
        total_unhappiness-= unhappy
        if total_unhappiness <= 0:
            total_unhappiness = 0
            break
        if i > 1:
            unhappiness[(i-1,j)]-= 1
            heappush(Q, (-unhappiness[(i-1,j)], i-1, j))
        if i < R:
            unhappiness[(i+1,j)]-= 1
            heappush(Q, (-unhappiness[(i+1,j)], i+1, j))
        if j > 1:
            unhappiness[(i,j-1)]-= 1
            heappush(Q, (-unhappiness[(i,j-1)], i, j-1))
        if j < C:
            unhappiness[(i,j+1)]-= 1
            heappush(Q, (-unhappiness[(i,j+1)], i, j+1))
        #print 'z', unhappy
        to_free-= 1

    return total_unhappiness


def count_unhappiness(R, C, pos):
    occupied = set()
    for k in pos:
        occupied.add((k/C, k%C))
    result = 0
    for i in xrange(R):
        for j in xrange(C):
            if not (i,j) in occupied:
                continue
            if (i-1,j) in occupied:
                result+= 1
            if (i+1,j) in occupied:
                result+= 1
            if (i,j-1) in occupied:
                result+= 1
            if (i,j+1) in occupied:
                result+= 1
    return result / 2


def solve2(R, C, N):
    result = R * C * 4
    for pos in combinations(range(R*C), N):
        #print pos, count_unhappiness(R, C, pos)
        result = min(result, count_unhappiness(R, C, pos))
    return result


if __name__ == '__main__':
    T = int(raw_input())
    for t in range(T):
        R, C, N = map(int, raw_input().strip().split())
        answer = solve(R, C, N)
        print "Case #{0}:".format(t + 1), solve2(R, C, N)
