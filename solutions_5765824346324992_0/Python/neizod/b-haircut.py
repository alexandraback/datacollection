#!/usr/bin/env python3

from fractions import gcd
from functools import reduce

def lcm(ns):
    lcm_pair = lambda a, b: a*b // gcd(a, b)
    return reduce(lcm_pair, ns, 1)

def group(ns):
    l = lcm(ns)
    return sum(l//n for n in ns)

def do_haircut(barbers):
    m = min(barbers)
    return [b - m for b in barbers]

def get_barber(n, ms):
    n -= 1
    n %= group(ms)
    barbers = [0 for _ in ms]
    while n:
        barbers = do_haircut(barbers)
        i = barbers.index(0)
        barbers[i] = ms[i]
        n -= 1
    barbers = do_haircut(barbers)
    return 1 + barbers.index(0)

for case in range(int(input())):
    _, n = [int(i) for i in input().split()]
    ms = [int(i) for i in input().split()]
    ans = get_barber(n, ms)
    print('Case #{}: {}'.format(case+1, ans))
