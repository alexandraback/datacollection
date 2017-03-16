# -*- coding: utf-8 -*-
import sys,copy,math,heapq,itertools as it,fractions,re,bisect,collections as coll

alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
T = int(raw_input())
for case in xrange(1, T + 1):
    N = int(raw_input())
    P = map(int, raw_input().split())

    ans = []
    A = sum(P)
    P = [(-Pi, i) for i, Pi in enumerate(P)]
    heapq.heapify(P)
    while P:
        X = heapq.heappop(P) 
        Pi, i = -X[0], X[1]
        if 2*Pi > A:
            ans[-1] += alpha[i]
        else:
            ans.append(alpha[i])
        A -= 1
        Pi -= 1
        if Pi > 0:
            heapq.heappush(P, (-Pi, i))

    print "Case #%d: %s" % (case, " ".join(ans))
