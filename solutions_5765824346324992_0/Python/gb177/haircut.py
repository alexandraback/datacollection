#!/usr/bin/python

from fractions import gcd
import heapq
import sys

def NN(): return list(map(int, sys.stdin.readline().split()))

def lcm2(a, b):
    return a * b / gcd(a, b)

def lcm(L):
    if len(L) == 2:
        return lcm2(L[0], L[1])
    else:
        l2 = lcm(L[1:])
        return lcm2(L[0], l2)

T = NN()[0]
for t in range(1, T + 1):
    B, N = NN()
    M = NN()
    l = lcm(M)
    
    #print "lcm", lcm(M)    
    h = []
    for i in range(B):
        heapq.heappush(h, (0, i))

    order = [] 
    while True:
        #print "from h ", heapq.nsmallest(3, h)
        T, i = heapq.heappop(h)
        if T == l and i == 0:
            break
        order.append(i)
        heapq.heappush(h, (T+M[i], i))
        
    #print "Order", order

    answer = order[(N-1) % len(order)] + 1
    print "Case #%d: %d" % (t, answer)

