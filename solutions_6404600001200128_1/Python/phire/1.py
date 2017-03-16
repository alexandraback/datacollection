#!/usr/bin/python2
# -*- coding: utf-8 -*-

import sys
import os

def solve1(m):
    prev = 0
    ret = 0
    for x in m:
        if x < prev:
            ret += prev - x
        prev = x
    return ret

def solve2(m):
    rate = 0
    for i in xrange(len(m)-1):
        rate = max(rate, m[i] - m[i+1])

    ret = 0
    for i in xrange(len(m)-1):
        ret += min(rate, m[i])
    return ret

def main():
    T = int(sys.stdin.readline())
    for t in xrange(1, T+1):
        N = int(sys.stdin.readline())
        m = map(int, sys.stdin.readline().split())
        assert len(m) == N
        print "Case #%d: %s %s" % (t, solve1(m), solve2(m))
        


if __name__ == '__main__':
    main()
