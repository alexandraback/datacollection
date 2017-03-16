from itertools import *
from statistics import *
from math import *

read_line = lambda: [int(i) for i in input().split()]

def canonical(s):
    cs, ds = [], []
    for k, g in groupby(s):
        cs.append(k)
        ds.append(len(list(g)))
    return cs, ds

def work():
    n = read_line()[0]
    ps, qs = zip(*[canonical(input()) for i in range(n)])
    for i in range(1, n):
        if ps[i] != ps[0]:
            return 'Fegla Won'
    ans = 0
    for q in zip(*qs):
        med = median_low(q)
        ans += sum(abs(r - med) for r in q)
    return ans

T = read_line()[0]
for t in range(1, T + 1):
    print('Case #{0}:'.format(t), work())
