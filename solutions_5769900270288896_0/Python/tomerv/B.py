import sys
import copy
import itertools
from collections import defaultdict
import math
import datetime

epsilon = 1e-6

N_MAX = 1e6

def log(msg):
    print(msg, file=sys.stderr)

def popcnt(x):
    old_x = x
    res = 0
    while x != 0:
        res += x % 2
        x = x // 2
    # log('popcnt({}) == {}'.format(old_x,res))
    return res

def count_unhappiness(rooms, rows, cols):
    res = 0
    for row in range(rows):
        for col in range(cols):
            if rooms[row][col]:
                if row+1 < rows and rooms[row+1][col]:
                    res += 1
                if col+1 < cols and rooms[row][col+1]:
                    res += 1
    # log('count_unhappiness({}) == {}'.format(rooms,res))
    return res

def solve(r, c, n):
    res = n * 4
    for i in range(2**(r*c)):
        if popcnt(i) != n:
            continue
        rooms = [[0 for x in range(c)] for x in range(r)] 
        # log('i={}'.format(i))
        # log(rooms)
        for j in range(r*c):
            # log(j)
            # log(i & (1 << j))
            if i & (1 << j) != 0:
                rooms[j//c][j%c] = 1
            # log(rooms)
        res = min(res, count_unhappiness(rooms, r, c))
    return res

def testcase():
    r, c, n = map(int,sys.stdin.readline().strip().split())
    solution = solve(r, c, n)
    testcase.id += 1
    print('Case #{}: {}'.format(testcase.id, solution))
testcase.id = 0

start = datetime.datetime.now()
t = int(sys.stdin.readline())
for i in range(t):
    log('Case #{}'.format(i+1))
    testcase()
log(datetime.datetime.now() - start)

