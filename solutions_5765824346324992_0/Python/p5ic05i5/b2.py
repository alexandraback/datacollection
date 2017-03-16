from heapq import *
from fractions import gcd

def lcm(a,b):
    return (a*b) / gcd(a, b)

def solve(B, n, M):
    h = []
    for i in xrange(B):
        heappush(h, (0, i))

    s = 0
    for i in xrange(n+1):
        time, barber = heappop(h)
        heappush(h, (time + M[barber], barber))
        if i == n:
            s = barber+1
    return s

T = int(raw_input())
for x in xrange(1, T+1):
    B, N = map(int, raw_input().split())
    M = map(int, raw_input().split())

    i = reduce(lcm, M)
    s = reduce(lambda a, b: a + i / b, M, 0)

    #print "lcm: {}, achieved: {}, N reduced from {} to {}".format(i, s, N, N % s)
    print "Case #{}: {}".format(x, solve(B, (N-1) % s, M))
