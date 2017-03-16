#!/usr/bin/python

import sys
from collections import defaultdict
from heapq import heapify, heappush, heappop, nsmallest

f = open("small.in","rb")
t = int(f.readline())
global res

def solve(s):
    res = []
    hp = []
    i = 0
    for j in s:
        heappush(hp, (-j, i))
        i+=1
    while True:
        x = heappop(hp)
        if x[0] == 0:
            return res
        x = (x[0]+1, x[1])
        heappush(hp, x)
        r = chr(x[1]+65)
        if ok_to_remove(hp):
            y = heappop(hp)
            y = (y[0]+1, y[1])
            r += chr(y[1]+65)
            heappush(hp, y)
        res.append(r)

def ok_to_remove(hp):
    total = 0
    for x in hp:
        total += abs(x[0])

    t1 = abs(hp[0][0])
    t2 = abs(hp[1][0])
    t3 = t2 if (t1==t2) else t2-1
    if t3 <= (total-1)/2:
        return True
    return False

for i in range(t):
    n = int(f.readline().strip())
    s = f.readline().strip().split(" ")
    si = [int(x) for x in s]
    out = solve(si)

    print "Case #%s:" % (i+1), " ".join(out)
