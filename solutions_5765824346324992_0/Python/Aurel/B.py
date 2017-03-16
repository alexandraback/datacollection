import sys
import itertools
import math
import collections
import functools
from fractions import gcd

sys.setrecursionlimit(10000)

def inputInts():
    return map(int, raw_input().split())

def lcm(a, b):
    g = gcd(a, b)
    return a * b / g

def vlcm(v):
    out = 1
    for i in v:
        out = lcm(out, i)
    return out

def hasStartedAfter(B, N, M, t):
    done = 0
    for i in M:
        done += t // i
    return done + B >= N

def timeToStart(B, N, M):
    if N <= B:
        return 0
    a = 0
    b = 100000 * B * N

    while a < b:
        mid = (a + b) // 2
        if a == mid:
            break
        if hasStartedAfter(B, N, M, mid):
            b = mid
        else:
            a = mid
    return b

    
def solve(B, N, M):
    # compute LCM and how many clients are handled in that many minutes
    l = vlcm(M)
    clients = 0
    for i in M:
        clients += l // i

    # now we can remove those
    N = N % clients
    if N == 0:
        N = clients

    if N <= B:
        return N

    start = timeToStart(B, N, M)

    # Compute how many started before that
    aboutToStart = []
    for b in xrange(B):
        i = M[b]
        delta = start // i
        N -= delta
        diff = delta * i - start
        if diff < 0:
            N -= 1
        elif diff == 0:
            aboutToStart.append(b+1)
    return aboutToStart[N-1]

T = int(raw_input())
for testId in range(T):
    B, N = inputInts()
    M = inputInts()
    print "Case #{:d}: {:d}".format(testId+1, solve(B, N, M))
