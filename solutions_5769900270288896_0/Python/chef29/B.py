from collections import deque
#from decimal import Decimal
from sys import stdin, stderr
import copy
import fractions
import heapq
import itertools
import math
#import networkx as nx
import random
import re
import sys

sys.setrecursionlimit(100)

isa = isinstance

def encode(i,j,R,C):
    x = i * C + j
    return x
def decode(x,R,C):
    i = x / C
    j = x % C
    return i,j

dx = (1,0)
dy = (0,1)
inf = 1 << 50
def solve(R,C,N):
    ans = inf
    for mask in range(1<<(R*C)):
        cnt = 0
        res = 0
        for i in range(R*C):
            if mask & (1<<i):
                cnt += 1
        if cnt != N:
            continue
        for i in range(R*C):
            if mask & (1<<i):
                x,y = decode(i,R,C)
                for d in (0,1):
                    X = x + dx[d]
                    Y = y + dy[d]
                    if 0 <= X < R and 0 <= Y < C:
                        j = encode(X,Y,R,C)
                        if mask & (1<<j):
                            res += 1
        ans = min(ans,res)
    return ans

def output():
    for case in xrange(1, int(stdin.next()) + 1):
        R,C,N = [int(a) for a in stdin.next().strip().split()]
        # print >>stderr, '--', case
        # if case in [12]:
        #     print >>stderr, A
        #     break
        # print >>stderr, A
        ans = solve(R,C,N)
        print 'Case #%d:' % case, ans
        print >>stderr, 'Case #%d:' % case, ans

#if __name__ == '__main__':
# unit_test()
output()
