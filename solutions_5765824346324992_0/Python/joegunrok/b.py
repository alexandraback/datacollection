#!/usr/bin/python

import sys
VERBOSE = True

sin = sys.stdin
line = lambda : sin.readline().strip()

class case(object):
    def __init__(self, number):
        self.number = number
        self.r = ""

    def __enter__(self):
        return self

    def __exit__(self, *arg):
        print "Case #%s: %s" % (self.number, self.r)


def parse_result(out):
    return out.readline().strip()


def main():
    TEST_CASES = int(line())
    for CASE_NUMBER in range(1, TEST_CASES+1):
        with case(CASE_NUMBER) as CASE:
            _run(CASE, **parse())


def parse():
    B, N = map(int, sin.readline().strip().split(" "))
    M = map(int, sin.readline().strip().split(" "))
    return dict(B=B, N=N, M=M)


def bsearch(M, N, a, b):
    mid = (a + b) / 2
    if mid == a:
        cuta = sum(a/m for m in M)
        cutb = sum(b/m for m in M)
        if cuta < N:
            return b
        else:
            return a

    cut = sum(mid/m for m in M)
    if N > cut:
        return bsearch(M, N, mid, b)
    else:
        return bsearch(M, N, a, mid)

def _run(CASE, B=None, N=None, M=None):
    worst = 10**9 * 10**5
    time = bsearch(M, N-B, 0, worst)
    CASE.r = 0
    if N <= B:
        CASE.r = N
        return
    x = B
    for i in range(B):
        m = M[i]
        x += (time-1)/m
    for i in range(B):
        m = M[i]
        if time % m == 0:
            x += 1
            if x == N:
                CASE.r = i+1

if __name__ == "__main__":
    main()