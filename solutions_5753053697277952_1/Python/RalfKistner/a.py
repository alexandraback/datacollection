#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# Uses https://github.com/rkistner/contest-algorithms

import sys


def debug(*args):
    print(*args, file=sys.stderr)

fin = sys.stdin
T = int(fin.readline())
for case in range(1, T + 1):
    N = int(fin.readline())
    inparty = list(map(int, fin.readline().split()))
    mylist = []
    for i, num in enumerate(inparty):
        c = chr(65 + i)
        mylist.append((num, c))

    result = []
    total = sum(inparty)
    debug(total, inparty)
    while total > 0:
        mylist.sort(reverse=True)
        if mylist[0][0]*2 > total:
            debug("INVALID!!!", mylist)
        debug(mylist)
        if mylist[0][0] == mylist[1][0] and (len(mylist) < 3 or mylist[2][0] < mylist[1][0]):
            result.append(mylist[0][1] + mylist[1][1])
            mylist[0] = (mylist[0][0] - 1, mylist[0][1])
            mylist[1] = (mylist[1][0] - 1, mylist[1][1])
            total -= 2
        else:
            result.append(mylist[0][1])
            mylist[0] = (mylist[0][0] - 1, mylist[0][1])
            total -= 1
    debug(mylist)

    print("Case #%d: %s" % (case, ' '.join(result)))

