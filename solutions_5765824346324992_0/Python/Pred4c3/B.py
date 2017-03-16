from fractions import Fraction,gcd
from math import floor,ceil
import heapq
import sys

def lcm(a,b):
    return (a*b)//gcd(a,b)

def lcm_reduce(li):
    ans = 1
    for n in li:
        ans = lcm(ans,n)
    return ans

T=int(input())
for case_id in range(1,T+1):
    B,N = map(int,input().split())
    M = list(map(int,input().split()))
    lcmr = lcm_reduce(M)
    mod = sum(lcmr//m for m in M)
    N = ((N-1)%mod)+1

    def solve():
        if N<=B:
            return N
        speeds = [Fraction(1,m) for m in M]
        t = N/sum(speeds)
        #cuts = [max(0,ceil(t*s-3)) for s in speeds]
        #print(N,cuts, file=sys.stderr)
        cuts = [0 for s in speeds]
        next_times = [(cuts[i]*M[i],i) for i in range(len(M))]
        heapq.heapify(next_times)
        curr = sum(cuts)
        while curr<N:
            c = heapq.heappop(next_times)
            curr+=1
            if curr==N:
                return c[1]+1
            heapq.heappush(next_times, (c[0]+M[c[1]],c[1]))

        assert(False)
        return -1

    ans = solve()
    
    print('Case #%d: %d' % (case_id, ans))
    print('Case #%d: %d' % (case_id, ans), file=sys.stderr)
