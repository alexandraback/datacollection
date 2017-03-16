#! /usr/bin/env python

T = int(input())

for t in range(1, T+1):
    n = int(input())
    ms = [int(x) for x in input().split()]
    pre = 0
    cnt = 0
    maxd = 0
    for m in ms:
        if m < pre:
            cnt += pre - m
            maxd = max(maxd, pre - m)
        pre = m

    cnt2 = 0
    for m in ms[:-1]:
        cnt2 += min(m, maxd)

    print("Case #{}: {} {}".format(t, cnt, cnt2))
