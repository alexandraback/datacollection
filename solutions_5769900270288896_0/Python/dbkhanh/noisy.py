#!/usr/bin/env python

import os, sys
import numpy as np

def unhappiness(a, R, C):
    u = 0
    for i in xrange(R):
        for j in xrange(C-1):
            if a[i][j] == 1 and a[i][j+1] == 1:
                u += 1
    for i in xrange(R-1):
        for j in xrange(C):
            if a[i][j] == 1 and a[i+1][j] == 1:
                u += 1
    return u

def solve(R, C, N):
    best = 1000000
    for n in xrange(2 ** (R*C)):
        b = bin(n)[2:].zfill(R*C)
        if sum(map(int, b)) != N: continue
        a = np.empty([R, C])
        for i in xrange(R):
            for j in xrange(C):
                if b[C*i + j] == "1": a[i][j] = 1
                else: a[i][j] = 0
        best = min(best, unhappiness(a, R, C))
    return best

def main():
    lines = open(sys.argv[1]).read().rstrip().splitlines()
    T = int(lines[0])
    for case in range(1, T+1):
        answer = solve(*map(int, lines[case].split()))
        print("Case #{}: {}".format(case, answer))

if __name__ == "__main__":
    main()
