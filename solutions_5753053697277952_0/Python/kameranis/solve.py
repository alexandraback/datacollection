#!/usr/bin/env python

import numpy as np

A = ord('A')

def two_largest(numbers):
    m1 = m2 = float('-inf')
    p1 = p2 = -1
    for i,x in enumerate(numbers):
        if x > m2:
            if x >= m1:
                m1, m2 = x, m1
                p1, p2 = i, p1
            else:
                m2 = x
                p2 = i
    return (m1, p1, m2, p2)

def print_evac(p1, p2):
    return chr(A+p1)+chr(A+p2)

for i in xrange(int(raw_input())):
    N = int(raw_input())
    P = [int(k) for k in raw_input().split()]
    evac = []
    if sum(P) % 2 == 1:
        p1 = P.index(max(P))
        evac.append(chr(A+p1))
        P[p1] -= 1
    while sum(P) > 0:
        m1, p1, m2, p2 = two_largest(P)
        if m1 > m2 + 1:
            evac.append(print_evac(p1, p1))
            P[p1] -= 2
        else:
            evac.append(print_evac(p1, p2))
            P[p1] -= 1
            P[p2] -= 1
    evac = ' '.join(evac)
    print "Case #{}:".format(i+1), evac

