#!/usr/bin/python3.4
#Brute force small case

from itertools import *

T = int(input())

for c in range(1, T + 1):
    R, C, N = map(int, input().split())
    ans = 1000000
    for layout in combinations(range(R*C), N):
        unhappiness = 0
        for i in layout:
            if ((i % C) < (C - 1)) and (i + 1) in layout: unhappiness += 1
            if (i + C) in layout: unhappiness += 1
        ans = min(ans, unhappiness)
    print("Case #%d: %d" % (c, ans))
