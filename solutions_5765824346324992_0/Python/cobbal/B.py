#!/usr/bin/python

import operator

def solve_slow(B, Ms, N):
    remaining = [0] * B
    while True:
        for b, M in enumerate(Ms):
            if not remaining[b]:
                if N == 0:
                    return b + 1
                N -= 1
                remaining[b] = M
        wait = min(remaining)
        for i in range(B):
            remaining[i] -= wait

def solve_medium(B, Ms, N):
    g = reduce(gcd, Ms)
    for M in Ms: assert (not (M % g))
    Ms = [M // g for M in Ms]
    sync = reduce(operator.mul, Ms)
    processed_per_sync = sum(sync // M for M in Ms)
    #print processed_per_sync
    #print (B, Ms, N % processed_per_sync)
    return solve_slow(B, Ms, N % processed_per_sync)

def gcd(a, b):
    while a:
        a, b = b % a, a
    return b

T = int(raw_input())
for i in range(T):
    B, N = map(int, raw_input().split())
    Ms = map(int, raw_input().split())
    print "Case #%i: %s" % (i+1, solve_medium(B, Ms, N - 1))
