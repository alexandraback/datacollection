import os
import math
import copy
import sys
from collections import *
from functools import reduce

def gcd(a, b):
    """Return greatest common divisor using Euclid's Algorithm."""
    while b:      
        a, b = b, a % b
    return a

def lcm(a, b):
    """Return lowest common multiple."""
    return a * b // gcd(a, b)

def lcmm(*args):
    """Return lcm of args."""   
    return reduce(lcm, args)

os.chdir('/Users/Dana/Downloads')
f = open('B-small-attempt0.in','r')
fo = open('B.out','w')
T = int(f.readline())
for ite in range(T):
    b,n = str.split(f.readline())
    b,n = int(b),int(n)
    m = [int(x) for x in str.split(f.readline())]
    temp = 1
    for i in range(b):
        temp = lcm(temp,m[i])
    s = 0
    for i in range(b):
        s = s+temp/m[i]
    s = int(s)
    n = n % s
    if n==0:
        n = s
    m1 = list(m)
    p1 = list(range(1,b+1))
    index = b+1
    while index<=n:
        m1 = [m1[t]-min(m1) for t in range(b)]
        p = m1.index(min(m1))
        p1[p] = index
        m1[p] = m[p]
        index = index+1
        #print(p1)
        #print(m1)
    res = p1.index(n)+1
    #print(ite)
    #print(res)
    fo.write('Case #')
    fo.write(str(ite+1))
    fo.write(': ')
    fo.write(str(res))
    fo.write('\n')
fo.close()

