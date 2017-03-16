#!/usr/bin/env python3

import sys

rl = lambda: sys.stdin.readline()
T = int(rl())

def makedata(N, M, B):
    data = []
    for k in range(B):
        for j in range(N):
            # begin, end, k-number
            x = [j*M[k], (j+1)*M[k]-1, k+1]
            data.append(x)
    return data


def solve_sub(B, N, M):
    data = makedata(N, M, B)
    data.sort(key=lambda t: t[2]) 
    data.sort(key=lambda t: t[0]) 
    #print("DEBUG:", data)
    return data[N-1][2]

def solve(casei):
    B, N = rl().split()
    B = int(B)
    N = int(N)
    #print("DEBUG:", B, N)
    M = rl().split()
    for x in range(len(M)):
        M[x] = int(M[x])
    #print("DEBUG:", M)
    MM = 1
    for k in range(B):
        MM *= M[k]
    MS = 0
    for k in range(B):
        MS += MM // M[k]
    N = N % MS
    if N == 0:
        N += MS
    ans = solve_sub(B, N, M) 
    print("Case #{}: {}".format(casei, ans))

for i in range(1, T+1):
    solve(i)
