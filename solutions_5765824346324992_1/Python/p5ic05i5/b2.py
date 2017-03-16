from heapq import *
from fractions import gcd

def lcm(a,b):
    return (a*b) / gcd(a, b)

def solve(B, N, M, t):
    h = []
    S = reduce(lambda a, b: a + (t / b) + 1 , M, 0)
    while S >= N:
        t -= 1
        S = reduce(lambda a, b: a + (t / b) + 1 , M, 0)

    for i in xrange(B):
        heappush(h, (M[i] - (t % M[i]), i))

    s = 0
    for i in xrange(S, N):
        time, barber = heappop(h)
        heappush(h, (time + M[barber], barber))
        if i == N-1:
            s = barber+1
    return s

def search_time(B, N, M):
    def st(lower, upper):
        if upper - lower < 2:
            return lower
        t = (upper + lower) / 2
        s = reduce(lambda a, b: a + (t / b) + 1 , M, 0)
        if s < N:
            return st(t, upper)
        elif s > N:
            return st(lower, t)
        else:
            return t

    return st(0, max(M)*N)
    
    

T = int(raw_input())
for x in xrange(1, T+1):
    B, N = map(int, raw_input().split())
    M = map(int, raw_input().split())
    t = search_time(B, N, M)
    print "Case #{}: {}".format(x, solve(B, N, M, t))
