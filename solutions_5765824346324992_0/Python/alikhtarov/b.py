#!/usr/bin/env python

import sys

ls = sys.stdin.readlines()
ls = ls[1:]
nc = 1
while len(ls) >= 2:
    b, n = [int(x) for x in ls[0].split()]
    bs = [int(x) for x in ls[1].split()]
    ls = ls[2:]

    if n == 1:
        print "Case #%d: %d" % (nc, 1)
        nc += 1
        continue
        

    mn = 0
    mx = 10000000000
    
    while mx - mn > 1:
        md = (mn + mx) / 2
        f = sum((md + x - 1)/x for x in bs)
 #       print md, f
        if f <= n - 1:
            mn = md
        else:
            mx = md

#    print mn, mx
    
    j = -1
    skip = n - 1 - sum((mn + x - 1)/x for x in bs)
#    print skip
    for i in xrange(len(bs)):
        if mn % bs[i] == 0:
            if skip == 0:
                j = i
                break
            else:
                skip -= 1
    print "Case #%d: %d" % (nc, j + 1)
    nc += 1

