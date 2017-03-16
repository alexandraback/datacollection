#!/usr/bin/env python

import sys

def bc(n):
    r = 0
    while n:
        r += n & 1
        n >>= 1
    return r

ls = sys.stdin.readlines()
ls = ls[1:]
nc = 1
while len(ls):
    r, c, n = [int(x) for x in ls[0].split()]
    ls = ls[1:]

    a = r * c

    ans = -1
    for bm in xrange(2 ** a):
        cans = 0
        if bc(bm) != n:
            continue
        pr = 0
        for j in xrange(r):
            cr = (bm >> j * c) & ((1 << c) - 1)
            cans += bc(cr & (cr >> 1)) + bc(pr & cr)
            pr = cr
        if ans == -1:
            ans = cans
        else:
            ans = min(ans, cans)
        

    print "Case #%d: %d" % (nc, ans)
    nc += 1
