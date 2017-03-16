#!/usr/bin/env python

import os
import sys


def solve(P):
    plan = []
    while any(P):
        m = max(P)

        parties = [i for (i, n) in enumerate(P) if n == m]
        if len(parties) == 2:
            plan += [chr(ord('A') + parties[0]) + chr(ord('A') + parties[1])]
            P[parties[0]] -= 1
            P[parties[1]] -= 1
        else:
            plan += chr(ord('A') + parties[0])
            P[parties[0]] -= 1

    return plan

def main():
    T = int(sys.stdin.readline().strip())
    for t in range(T):
        N = int(sys.stdin.readline().strip())
        P = map(int, sys.stdin.readline().strip().split())
        result = solve(P)
        print 'Case #%d: %s' % (t + 1, ' '.join(result))

if __name__ == '__main__':
    main()

