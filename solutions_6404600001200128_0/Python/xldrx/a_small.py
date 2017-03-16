#! /usr/bin/env python -u
# coding=utf-8

import sys

__author__ = 'xl'

if __name__ == "__main__":
    fp = open("A.in")
    sys.stdout = open("A.out", "w")
    # fp = sys.stdin

    T = int(fp.readline())
    for t in range(T):
        N = int(fp.readline())
        M = map(int, fp.readline().split())

        ret_1 = 0
        min_rate = 0
        for i in range(N - 1):
            rate = M[i] - M[i + 1]
            if rate > 0:
                ret_1 += rate
                min_rate = max(min_rate, rate)

        ret_2 = 0
        for i in range(N - 1):
            if M[i] >= min_rate:
                ret_2 += min_rate
            else:
                ret_2 += M[i]

        print "Case #%s: %s %s" % (t + 1, ret_1, ret_2 )


