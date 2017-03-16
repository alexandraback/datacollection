#!/usr/bin/python

import sys

def method1(plates):
    return sum(max(one - two, 0) for one, two in zip(plates, plates[1:]))


def method2(plates):
    maxrate = max([one - two for one,two in zip(plates, plates[1:])])
    eaten = [min(plate, maxrate) for plate in plates[:-1]]
    return sum(eaten)

cases = int(sys.stdin.readline())

for casenum in range(1, cases+1):
    sys.stdin.readline()
    plates = list(map(int, sys.stdin.readline().split()))
    print "Case #%s: %s %s" % (casenum, method1(plates), method2(plates))
