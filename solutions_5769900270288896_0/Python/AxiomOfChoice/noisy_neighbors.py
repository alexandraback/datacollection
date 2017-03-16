from collections import *
from fractions import *
import heapq
from itertools import *
from math import *
#from functools import *
import sys

INF = float('inf')

def rec(grid, i, j, a, b, n):
    if n == 0:
        return 0
    if i == a:
        return INF

    ii, jj = (i, j + 1) if j + 1 < b else (i + 1, 0)

    no = rec(grid, ii, jj, a, b, n)

    add = 0
    if i > 0:
        add += grid[i - 1][j]
    if j > 0:
        add += grid[i][j - 1]
    grid[i][j] = 1
    yes = add + rec(grid, ii, jj, a, b, n - 1)
    grid[i][j] = 0

    return min(no, yes)

def work(a, b, n):
    grid = [[0 for j in range(b)] for i in range(a)]
    return rec(grid, 0, 0, a, b, n)

t = int(input())
for i in range(t):
    a, b, n = map(int, input().split())
    print('Case #{}: {}'.format(i + 1, work(a, b, n)))
