#!/usr/bin/env python

import sys

def gcd(a, b):
    while b: a, b = b, a % b
    return a

def lcm(a, b):
    return a * b / gcd(a, b)

def lcmm(*args):
    return reduce(lcm, args)

def lgcd(*args):
    return reduce(gcd, args)

def solve(B, N):
    b = len(B)
    LCMM = lcmm(*B)
    period = sum([LCMM / bb for bb in B])
    #print B, LCMM, period
    if N > period: N = N % period
    if N == 0: N = period
    busy = [0]*b
    for i in range(N):
        wait = min(busy)
        my = None
        for j,bb in enumerate(busy): 
            busy[j] -= wait
            if my == None and busy[j] == 0:
                busy[j] = B[j]
                my = j
    return my+1 # 1-based numbering

case = 1
inp = open(sys.argv[1], 'r').readlines()
T = int(inp[0].strip())
while case <= T:
    _, N = map(int, inp[case*2-1].strip().split())
    B = map(int, inp[case*2].strip().split())
    print "Case #%d: %s" % (case, solve(B, N))
    case += 1
