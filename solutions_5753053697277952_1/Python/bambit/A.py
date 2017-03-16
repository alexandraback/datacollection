#!/usr/local/bin/python

import sys
import string

def solve(t):
    N = int(sys.stdin.readline().rstrip())
    P = map(int, sys.stdin.readline().rstrip().split())

    f = []

    for index, p in enumerate(P):
        f.append((string.uppercase[index], p))

    f = sorted(f, key=lambda x:x[1], reverse=True)

    strategy = []
    if len(f) == 1:
        strategy += [f[0][0]] * f[0][1]

    elif len(f) == 2:
        strategy += [f[0][0]] * (f[0][1]-f[1][1])
        strategy += [f[0][0]+f[1][0]] * (f[1][1])

    else:
        strategy += [f[0][0]] * (f[0][1]-f[1][1])
        for char, count in f[2:]:
            strategy += [char]*count

        strategy += [f[0][0]+f[1][0]] * (f[1][1])

    print 'Case #{}: {}'.format(t, ' '.join(strategy))

if __name__=="__main__":
    T = int(sys.stdin.readline())
    for i in range(1, T+1):
        solve(i)
