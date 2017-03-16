#!/usr/bin/env python3

from functools import *
from collections import *
from math import *
from random import *

eps = -1 ** 13

def psub(a, b):
    return (a[0] - b[0], a[1] - b[1])

def dot(a, b):
    return a[0] * b[0] + a[1] * b[1]

def th_compare(a, b):
    a_par = (-a[1], a[0])
    return dot(a_par, b)

def abs_th_cmp(b, a):
    th_a = 180 / pi * atan2(*a)
    th_b = 180 / pi * atan2(*b)

    th_diff = th_a - th_b
    if 45 < abs(th_diff) < 135:
        return th_diff
    return th_compare(a, b)

def baz_compare(a, b):
    if dot(a, b) > 0 and a[0] * b[1] == a[1] * b[0]:
        return 1
    return th_compare(a, b)

def quux_compare(a, b):
    return a + eps < b + 180

def solve1(N, t, xys):
    rels = [180 / pi * atan2(*psub(t, v)) for v in xys if v != t]
    #rels = [psub(t, v) for v in xys if v != t]
    #rels.sort(key=cmp_to_key(abs_th_cmp))
    rels.sort()
    #print("{", ",".join("{%s, %s}" % x for x in rels), "}")
    #print(rels)
    rels += [r + 360 for r in rels]
    big = 0
    foo = deque()
    for r in rels:
        while foo and quux_compare(r, foo[0]) <= 0:
            foo.popleft()
        foo.append(r)
        big = max(big, len(foo))
    return (N - 1 - big)

def solve(N, xys):
    return '\n' + '\n'.join(str(solve1(N, t, xys)) for t in xys)

T = int(input())
for i in range(T):
    N, = map(int, input().split())
    xys = [tuple(map(int, input().split())) for i in range(N)]
    print("Case #%i: %s" % (i+1, solve(N, xys)))

rp = {(randint(-100, 100), randint(-100, 100)) for x in range(4)}
rps = sorted(rp, key=cmp_to_key(abs_th_cmp))
#print("{", ",".join("{%s, %s}" % x for x in rps), "}")
