"""Usage:
    pypy -u X.py < X-test.in > X-test.out
or sometimes:
    python -u X.py < X-test.in > X-test.out
may be python 2 or 3.
"""
from __future__ import print_function

import os
import sys


def common_setup():
    #import memcache as mc
    #C = mc.Client(['127.0.0.1:11211'])
    pass


def case_reader(tc, infile):
    N = int(next(infile))
    P = map(int, next(infile).split())
    del infile
    return locals()


def case_solver(tc, N=None, P=None, I=None, T=None, S=None, **kwargs):

    P = dict(zip('ABCDEFGHIJKLMNOPQRSTUVWXYZ', P))
    res = ''
    while P:
        S = sorted(P.items(), key=lambda i: i[1], reverse=True)
        if S[0][1] == S[1][1] and len(P) == 2:
            res += S[0][0] + S[1][0] + ' '
            P[S[0][0]] -= 1
            P[S[1][0]] -= 1
            if P[S[0][0]] == 0:
                P.pop(S[0][0])
                P.pop(S[1][0])
        else:
            res += S[0][0] + ' '
            P[S[0][0]] -= 1
            if P[S[0][0]] == 0:
                P.pop(S[0][0])
    return 'Case #{:d}: {}'.format(tc, res)


if __name__ == '__main__':
    common_setup()
    cases = [case_reader(tc, sys.stdin) for tc in range(1, int(next(sys.stdin)) + 1)]
    for case in cases:
        print(case_solver(**case))
