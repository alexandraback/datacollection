from sys import stdin
import re
import operator
import bisect
import sys
import random

cases = int(stdin.next().strip())
for case in range(1, cases+1):
    N = int(stdin.next().strip())
    M = map(int, stdin.next().split())
    drops = [max(i-j,0) for i, j in zip(M[:-1], M[1:])]
    max_eaten = [min(max(drops), x) for x in M[:-1]]
    print 'Case #%d: %d %d' % (case, sum(drops), sum(max_eaten))