from sys import stdin
import sys
if len(sys.argv) > 1:
    sys.stdout = open(sys.argv[1], 'w')
from fractions import gcd

def lcm(x, y):
    return x*y/gcd(x, y)
            
def each_case(B, N, M):
    L = reduce(lcm, M)
    N = (N - 1) % sum(L/m for m in M) + 1
    endtime = [0] * B
    for n in xrange(N):
        min_b, min_e = 0, endtime[0]
        for b, e in enumerate(endtime):
            if min_e > e:
                min_b, min_e = b, e
        if min_e > 1000000:
            for b in xrange(B):
                endtime[b] -= min_e
        endtime[min_b] += M[min_b]

    return min_b + 1

T = int(stdin.readline())
for t in xrange(1,T+1):
    B, N = map(int, stdin.readline().split())
    M = map(int, stdin.readline().split()[:B])
    print 'Case #{}: {}'.format(t, each_case(B, N, M))
