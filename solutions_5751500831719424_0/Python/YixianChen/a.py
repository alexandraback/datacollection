#!/usr/bin/env python
import sys, operator as op, itertools as itt, math, collections, bisect
debug = False
#if debug: print

def minform ( s ):
    it = iter(s)
    c = it.next()
    x = []
    n = 1
    for d in it:
        if c != d:
            x.append( ( c, n ) )
            c = d
            n = 1
        else:
            n += 1
    x.append( (c, n) )
    #return "".join( map(op.itemgetter(0), x) ), x
    return zip(*x)

def cover( *args ):
    return map( max, zip(*args) )

def cover2( args ):
    return map( max, zip(*args) )

def mindist ( nums ):
    nums = sorted(nums)
    m = nums[ len(nums)/2 ]
    return sum([ abs(i-m) for i in nums ])

def mindist2 ( nums ):
    def dist(m):
        return sum([ abs(i-m) for i in nums ])
    return min( [ dist(j) for j in nums ] )

def solve( s ):
    x, n = zip( *map ( minform, s ) )
    if len(frozenset(x)) == 1:
        if debug: print x[0]
        if debug:
            for i in n: print i
        m = zip(*n)
        d = map( mindist, m )
        if debug: print d
        return sum(d)
    else:
        return None

def main():
    f = sys.stdin
    T = int( f.next() )
    
    for c in xrange(1, T+1):
        N = int( f.next() )
        strings = [ f.next().strip() for i in xrange(N) ]
        x = solve(strings)
        
        print "Case #{0}: {1}".format ( c, x if x!=None else "Fegla Won" )
    return 0

sys.exit ( main() )
