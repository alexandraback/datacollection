#!/usr/bin/env python

import sys

def solve1(M):
    res = 0
    L = len(M)
    for i in range(L-1):
        res += max(M[i] - M[i+1], 0)
    return res

def solve2(M):
    res = 0
    L = len(M)
    deltas = [max(M[i] - M[i+1], 0) for i in range(L-1)]
    d = max(deltas)
    for i in range(L-1):
        res += min(M[i], d)
    return res

def solve(M):
    return str(solve1(M))+" "+str(solve2(M))

case = 1
inp = open(sys.argv[1], 'r').readlines()
T = int(inp[0].strip())
while case <= T:
    M = map(int, inp[case*2].strip().split())
    print "Case #%d: %s" % (case, solve(M))
    case += 1
