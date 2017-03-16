#!/usr/bin/python2
# coding: utf-8

import itertools
from sys import stdin

T = int(stdin.readline().rstrip())

for ct in range(T):
    N = int(stdin.readline())
    inpc = None
    inpn = []
    ans = None
    for i in range(N):
        curc = []
        curn = []
        l = stdin.readline().rstrip()
        for c in l:
            if curc and curc[-1] == c:
                curn[-1] += 1
            else:
                curc.append(c)
                curn.append(1)
        if inpc and curc != inpc:
            ans = 'Fegla Won'
        else:
            inpc = curc
        inpn.append(curn)

    if ans is None:
        ans = 0
        for i in range(len(inpc)):
            cca = 100000
            for ptn in inpn:
                ca = 0
                for oth in inpn:
                    ca += abs(ptn[i] - oth[i])
                cca = min(cca, ca)
            ans += cca

    print 'Case #{0}: {1}'.format(ct + 1, ans)
