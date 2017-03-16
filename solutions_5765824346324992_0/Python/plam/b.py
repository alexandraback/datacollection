#!/usr/bin/python

import sys, heapq

data = file(sys.argv[1]).read().splitlines()

T = int(data.pop(0))

def time(T,K):
    return T*1000000 + K

def gcd(a,b):
    while b != 0:
        t = b
        b = a % b
        a = t
    return a

def brute(B,N,M):
    t = 0
    cur = 1
    H = []

    # find lcm
    lcm = M[0]
    for k in xrange(1,B):
        lcm = (lcm * M[k]) / gcd(lcm,M[k])

#    print lcm
    rate = 0
    for k in xrange(0,B):
        rate = rate + lcm/M[k]
        assert lcm % M[k] == 0

#    print lcm,rate
    x = (N-1) / rate
    t = lcm * x
    cur = (x * rate) + 1

#    print cur,N,t

    for k in xrange(0,B):
        heapq.heappush(H,(time(t,k),t,k))

    
    while cur < N:
        (_,t,k) = heapq.heappop(H)
        cur = cur + 1
        t = t + M[k]
        heapq.heappush(H,(time(t,k),t,k))

    (_,t,k) = heapq.heappop(H)

    return k+1

for CASE in xrange(1,T+1):
    print 'Case #%d:' % (CASE),
    (B,N)= [int(x) for x in data.pop(0).split()]
    M = [int(x) for x in data.pop(0).split()]
    
    print brute(B,N,M)


