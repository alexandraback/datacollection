import os
from fractions import gcd
import sys

__author__ = 'dkopiychenko'

def lcm(a, b):
    return a * b // gcd(a, b)

def lcmm(l):
    return reduce(lcm, l)

def solve(l, n):
    if n < len(l) + 1: return n
    bb = []
    for x in l:
        bb.append(x)
    c = len(l)
    for i in range(1, n*max(l)+1):
        for j in range(len(bb)):
            if bb[j] <= i:
                c += 1
                if c == n: return j + 1
                bb[j] += l[j]



def solve2(l, n):
    p = lcmm(l)
    npp = 0
    for x in l:
        npp += p/x
    m = n % npp
    if m == 0 :
        return solve(l, npp)
    return solve(l, m)



sys.setrecursionlimit(10000)

with open(os.path.expanduser("~/Downloads/B-small-attempt2 (1).in")) as f:
# with open(os.path.expanduser("~/gcj2015/A-test.in.txt")) as f:
    n = f.readline().strip('\n')
    print n
    lines = [x.strip('\n') for x in f.readlines()]
    counter = 1
    for i in range(len(lines)/2):
        b, n = [int(g) for g in lines[2*i].split(' ')]
        l = [int(g) for g in lines[2*i + 1].split(' ')]
        print 'Case #' + str(counter) + ': ' + str(solve2(l, n))
        counter += 1