#!/usr/bin/env python

import sys


def solve(r1, r2):
    common = set(r1).intersection(r2)
    if len(common) == 1:
        return str(common.pop())
    elif len(common) == 0:
        return "Volunteer cheated!"
    else:
        return "Bad magician!"


def __main__():
    cases_no = int(sys.stdin.readline())
    for case_no in xrange(cases_no):
        g1 = int(sys.stdin.readline())
        a1 = [map(int, sys.stdin.readline().split()),
              map(int, sys.stdin.readline().split()),
              map(int, sys.stdin.readline().split()),
              map(int, sys.stdin.readline().split())]
        g2 = int(sys.stdin.readline())
        a2 = [map(int, sys.stdin.readline().split()),
              map(int, sys.stdin.readline().split()),
              map(int, sys.stdin.readline().split()),
              map(int, sys.stdin.readline().split())]

        print "Case #%d: %s" % (case_no + 1, solve(a1[g1-1], a2[g2-1]))

__main__()
