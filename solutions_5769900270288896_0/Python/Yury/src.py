#!/usr/bin/python3

import sys
from itertools import *
from functools import *
from pprint import pprint

def solve(R, C, N):
    mi = N*N
    for comb in combinations(range(R*C), N):
        m = set((idx//C, idx%C) for idx in comb)
        assert len(m) == N
        #perr(m)
        su = 0
        for i,j in m:
            if (i+1,j) in m:
                #perr((i,j,1))
                su += 1
            if (i,j+1) in m:
                #perr((i,j,2))
                su += 1
        mi = min(mi, su)
    #perr(mi)
    return mi

def parse(ist):
    return tuple(int(x) for x in ist.readline().split())

def main():
    T = int(sys.stdin.readline())
    for i in range(T):
        #err('Case {}'.format(i))
        res = solve(*parse(sys.stdin))
        print('Case #{}: {}'.format(i+1, res))

def err(*m):
    print(*m, file=sys.stderr)

def perr(*m):
    pprint(m, stream=sys.stderr)

if __name__ == '__main__':
    sys.exit(main())
