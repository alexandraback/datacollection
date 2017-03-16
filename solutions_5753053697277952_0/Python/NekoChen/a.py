import sys, numpy as np
from itertools import combinations
from operator import itemgetter
from collections import deque, defaultdict
import heapq

def step( prob ):
    Q, N = prob
    c, p = heapq.heappop( Q )
    ans = [ p ]
    c += 1
    N -= 1    
    if c < 0:
        heapq.heappush( Q, (c, p) )
    
    if N & 1:
        c, p = heapq.heappop( Q )
        ans.append( p )
        c += 1
        N -= 1    
        if c < 0:
            heapq.heappush( Q, (c, p) )
            
    prob[1] = N
    #print "".join(ans), Q
    return "".join(ans)
    

def solve( N, P ):
    Q = [ (-c, p) for p, c in zip( "ABCDEFGHIJKLMNOPQRSTUVWXYZ", P ) ]
    heapq.heapify( Q )
    ans = []
    prob = [ Q, sum(P) ]
    while Q:
        ans.append( step(prob) )
    return " ".join(ans)

def main():
    f = open( sys.argv[1] ) if len(sys.argv)>=2 else sys.stdin
    #f = sys.stdin
    T = int(f.next())
    for case in range(1,T+1):
        N = int( f.next().strip() )
        P = map( int, f.next().strip().split() )
        print "Case #{0}: {1}".format( case, solve(N, P) )
        

if __name__ == "__main__":
    main()
