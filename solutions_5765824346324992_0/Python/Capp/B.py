#!/usr/bin/env python

from sys import stdin, stderr
from math import floor

T = int(stdin.readline())

def solve(n, barbar):
    while True:
        print >>stderr, n, barbar
        if len(barbar) >= n and barbar[n-1][0] == barbar[0][0]:
            return barbar[n-1][1]
        if len(barbar) > n: barbar = barbar[:n]
        n, barbar = simple(n, barbar)
        if n < 1: raise
        pass
    pass

def simple(n, barbar):
    for b in barbar:
        if b[0] != 0: break
        b[0] = b[2]
        n -= 1
        pass
    barbar.sort()
    #wait = barbar[0][0]
    #if n > len(barbar):
    wait = int(floor((n-len(barbar)-1) / sum(1./b[2] for b in barbar)))
    wait = max(wait, barbar[0][0])
    print >>stderr, "mite", n, barbar, wait
    if wait < 1: raise
    for b in barbar:
        b[0] -= wait
        n += b[0] / b[2]
        b[0] %= b[2]
        pass
    barbar.sort()
    return n, barbar

for t in range(T):
    B, N = [int(c) for c in stdin.readline().split()]
    M = [int(c) for c in stdin.readline().split()]

    print >>stderr, "###", t+1
    print >>stderr, B, N, M

    n = N
    barbar = [[0, i+1, m] for i, m in enumerate(M)]
    ret = solve(n, barbar)
    print >>stderr, ret

    print "Case #%d:" % (t+1),
    print ret
