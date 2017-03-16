#!/usr/bin/python2
# -*- coding: utf-8 -*-

import sys
import os

def compress(s):
    r = []
    c = ''
    count = 0
    for x in s + " ":
        if x == c:
            count += 1
        else:
            if count:
                r.append((c, count))
            c = x
            count = 1
    return r


def test(arr, x):
    r = 0
    for y in arr:
        r += abs(y - x)
    return r

def match(arr):
    avg = float(sum(arr)) / len(arr)
    avg = int(avg) - 1
    avg = max(1, avg)
    return min(test(arr, avg), test(arr, avg+1), test(arr, avg+2), test(arr, avg+3))


def main():
    T = int(sys.stdin.readline())
    for t in xrange(1, T+1):
        N = int(sys.stdin.readline())
        a = []
        for i in xrange(N):
            a.append(compress(sys.stdin.readline().strip()))
        signature = [x[0] for x in a[0]]
        good = True
        for r in a:
            if [x[0] for x in r] != signature:
                print "Case #" + str(t) + ": Fegla Won"
                good = False
                break
        if not good:
            continue
        ret = sum(match([x[i][1] for x in a]) for i in xrange(len(signature)))
        print "Case #" + str(t) + ": " + str(ret)



if __name__ == '__main__':
    main()
