#!/usr/bin/python

import sys, re, string, math, fractions, itertools
from fractions import Fraction
import heapq

ssr = sys.stdin.readline
ssw = sys.stdout.write
def rdline(): return ssr().strip()
def rdstrs(): return ssr().split()
def rdints(): return map(int, ssr().split())
def rd1int(): return int(rdline())



def do_one_case(cnum):
    (B, N) = rdints()
    M = rdints()
    assert len(M)==B
    avg = sum(1.0/x for x in M)
    t = max(0, math.floor((N-2*B-2.1)/avg - 2.2))
    nQ = [ int(math.ceil((t-.1)/x)) for x in M ]
    Q = [ ( M[i]*nQ[i], i ) for i in range(B) ]
    n = sum(nQ)
    assert n<N
    heapq.heapify(Q)
    while n<N:
        n += 1
        (t, i) = Q[0]
        heapq.heapreplace(Q, (t+M[i], i))
    print "Case #%d: %d" % (cnum, i+1)




def main():
    T = rd1int()
    for i in range(T):
        do_one_case(i+1)
        sys.stdout.flush()


if __name__ == "__main__":
    main()
