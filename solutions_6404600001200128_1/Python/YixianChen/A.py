import sys, heapq, bisect, numpy
from collections import defaultdict
from operator import itemgetter

def solve ( N, m ):
    d = map( lambda x,y: y-x, m[1:], m[:-1] )
    s1 = sum([ i for i in d if i > 0 ])
    r = max(d)
    s2 = sum([ min( r, i ) for i in m[:-1] ])
    return s1, s2

def main():
    f = open(sys.argv[1])
    T = int( f.next() )
    for i in range(T):
        N = int( f.next() )
        m = map( int, f.next().strip().split() )
        print "Case #{0}: {1} {2}".format( i+1, *solve( N, m ) )

main()
