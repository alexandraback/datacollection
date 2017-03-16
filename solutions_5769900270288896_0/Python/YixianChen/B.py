import sys, itertools as itt, StringIO
#import heapq, bisect, numpy, math
from collections import defaultdict, namedtuple, deque, Counter
from operator import itemgetter
from types import FunctionType

lines = lambda f: "\n".join( map( str, f ) )
def linearg ( f, fmt = None ):
    if fmt == None:
        return f.next().strip().split()
    elif isinstance( fmt, (type,FunctionType) ):
        return [ fmt(i) for i in f.next().strip().split() ]
    else:
        return [ i(j) for i, j in zip( fmt, f.next().strip().split() ) ]

class Graph ( defaultdict ):
    def __init__ ( self, pairs ):
        defaultdict.__init__( self, list )
        for i, j in pairs:
            self[i].append(j)
            self[j].append(i)


def ones(x):
    a = 0
    while x:
        a += (x&1)
        x >>= 1
    return a

def decom( x, s ):
    m = (1<<s)-1
    while x:
        yield x & m
        x >>= s

def unhappy( i, R, C ):
    rows = list( decom(i, R) )
    u = 0
    last = 0
    for r in rows:
        u += ones( r & (r>>1) )
        u += ones( last & r )
        last = r
    return u

def func( R, C, N ):
    u = R*C*4
    for i in range( 2**(R*C) ):
        if ones(i) != N: continue
        u = min( unhappy(i, R, C), u )
    return u

def solve( R, C, N ):
    a = ((R*C)+1)/2
    if N <= a :
        return 0
    return func( R, C, N )

def main(f):
    T = int( f.next() )
    for i in range(T):
        R, C, N = linearg( f, int )
        print "Case #{0}: {1}".format( i+1, solve( R, C, N ) )

if len(sys.argv) >= 2:
    main(open(sys.argv[1]))
else:
    main(   StringIO.StringIO(  """\
4
2 3 6
4 1 2
3 3 8
5 2 0""" ))

