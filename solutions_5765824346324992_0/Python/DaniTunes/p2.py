#!/bin/env python

# google code jam 2015 problem 2

from numpy import argmin


def gcd(a, b):
    while b > 0:      
        a, b = b, a % b
    return a

def lcm(a, b):
    return a * b / gcd(a, b)

def lcmm(x):
    r = 1
    for n in x:
	r = lcm(n, r)
    return r

def solve(m, n):
    k = len(m)
    lc = lcmm(m)
    p = 0
    for i in m:
	p += lc / i
    n1 = ((n-1) % p) + 1
    #print m, "lcm=", lc, "p=", p,  n, n1
    n = n1
    t = [0] * k
    for i in range(n-1):
	z = argmin(t)
	t[z] += m[z]
	#print t
    return argmin(t)+1

tests = int(raw_input())
for k in range(tests):
    b, n = [int(x) for x in raw_input().split()]
    m = [int(x) for x in raw_input().split()]
    #print n, b, len(m), m
    a = solve(m, n)
    print "Case #%d: %d" % (k+1, a)
