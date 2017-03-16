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
    N = map(int, sin.readline().strip().split(" "))
    s = map(int, sin.readline().strip().split(" "))
    return dict(N=N, s=s)


def _run(CASE, N=None, s=None):
    max_delta = -1
    tot = 0
    for n in range(1, len(s)):
        tot += max(0, s[n-1]-s[n])
        if s[n-1] > s[n]:
            max_delta = max(max_delta, s[n-1]-s[n])
    dtot = 0
    if max_delta == -1:
        max_delta = 0
    for n in range(1, len(s)):
        if s[n-1] < max_delta:
            dtot += s[n-1]
        else:
            dtot += max_delta

    CASE.r = "%s %s" % (tot, dtot)

if __name__ == "__main__":
    main()