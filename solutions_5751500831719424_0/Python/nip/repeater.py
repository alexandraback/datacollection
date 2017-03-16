#! /usr/bin/env python

from sys import stdin
import numpy as np

ntest = input()

for test in xrange(ntest):
    n = input()
    strings = []
    for i in xrange(n):
        s = stdin.readline().strip() + '*'        
        sig = []
        c = s[0]
        nrep = 1
        for i in s[1:]:
            if i == c:
                nrep += 1
            else:
                sig.append((c, nrep))
                c = i
                nrep = 1
        strings.append(sig)
    
    if len({''.join([i for i, j in sig]) for sig in strings}) == 1:
        med = len(strings) / 2
        y = 0
        for i in xrange(len(strings[0])):
            h = sorted([sig[i][1] for sig in strings])
            m = h[med]
            for k in h:
                y += abs(m - k)
        print "Case #{}: {}".format(test+1, y)
    else:
        print "Case #{}: Fegla Won".format(test+1)
        