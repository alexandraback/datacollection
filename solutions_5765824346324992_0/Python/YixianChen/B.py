import sys, heapq, bisect, numpy, math
from collections import defaultdict
from operator import itemgetter

def back ( rem, N, m ):
    #print "rem", rem, "N", N
    h = [ (mm-r, -i) for r, mm, i in zip( rem, m, range(len(m)) ) ]
    heapq.heapify( h )
    for i in range(N):
        r, b = heapq.heappop( h )
        heapq.heappush( h, (r+m[b], b ) )
    r, b = heapq.heappop( h )
    #print -b
    return -b

def forward( rem, N, m ):
    #print "rem", rem, "N", N
    h = [ (r, i) for r, mm, i in zip( rem, m, range(len(m)) ) ]
    heapq.heapify( h )
    for i in range(N):
        r, b = heapq.heappop( h )
        heapq.heappush( h, (r+m[b], b ) )
    r, b = heapq.heappop( h )
    #print b
    return b

def solve ( B, N, m ):
    v = sum([ 1.0/i for i in m ])
    t = int( (N-1)/v )
    done = [ t / i for i in m ]
    rem = [ (-t % i) for i in m ]
    #print "rem", rem, "t", t, "m", m
    n = sum(done)+len(filter(None, rem))
    #print "t", t, "m", m, "done", done, "rem", rem, "n", n
    if n >= N:
        ans = back ( rem, n-N, m )
    else:
        ans = forward ( rem, N-n-1, m )
    return ans+1

def main():
    f = open(sys.argv[1])
    T = int( f.next() )
    for i in range(T):
        B, N = map( int, f.next().strip().split() )
        m = map( int, f.next().strip().split() )
        print "Case #{0}: {1}".format( i+1, solve( B, N, m ) )

main()
