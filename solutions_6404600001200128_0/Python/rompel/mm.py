#!/usr/bin/python

import sys, re, string, math, fractions, itertools
from fractions import Fraction

ssr = sys.stdin.readline
ssw = sys.stdout.write
def rdline(): return ssr().strip()
def rdstrs(): return ssr().split()
def rdints(): return map(int, ssr().split())
def rd1int(): return int(rdline())



def do_one_case(cnum):
    N = rd1int()
    m = rdints()
    assert len(m)==N
    d = [ m[i]-m[i-1] for i in range(1,N) ]
    Y = -sum(min(0,x) for x in d)
    r = -min(0, min(d))
    Z = sum(min(x, r) for x in m[:N-1])
    print "Case #%d: %d %d" % (cnum, Y, Z)



def main():
    T = rd1int()
    for i in range(T):
        do_one_case(i+1)
        sys.stdout.flush()


if __name__ == "__main__":
    main()
