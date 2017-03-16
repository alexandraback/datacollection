from sys import stdin
import re
import operator
import bisect
import sys
import random
from collections import defaultdict
from functools import reduce # Valid in Python 2.6+, required in Python 3
import operator
from fractions import gcd

cases = int(stdin.next().strip())
for case in range(1, cases+1):
    B, N = map(int, stdin.next().split())
    M = map(int, stdin.next().split())
    g = reduce(operator.mul, M, 1)
    #g = reduce(gcd, M)
    my_mod = sum([g/m for m in M])
    N = N % my_mod
    if N == 0:
        N = my_mod
    counters = [(0, i) for i in range(B)]
    mini = min(counters)
    for x in range(N):
        mini = min(counters)
        counters[mini[1]] = (mini[0] + M[mini[1]], mini[1])
    print 'Case #%d: %d' % (case, mini[1] + 1)