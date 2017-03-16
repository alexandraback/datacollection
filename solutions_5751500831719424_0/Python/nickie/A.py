#!/usr/bin/env python3

from itertools import groupby

def single(s):
    return tuple(zip(*[(k, len(list(g))) for k, g in groupby(s)]))

def moves(ns):
    l = min(ns)
    r = max(ns)
    return min(sum(abs(n-i) for n in ns) for i in range(l, r+1))
    
def solve(S):
    U, R = zip(*map(single, S))
    if any(u != U[0] for u in U):
        return "Fegla Won"
    nums = zip(*R)
    return sum(moves(ns) for ns in nums)

tests = int(input())
for test in range(tests):
    N = int(input())
    S = []
    for i in range(N):
        S.append(input().strip())
    result = solve(S)
    print("Case #{}: {}".format(1+test, result))
