#!/usr/bin/python3

import sys

memo = dict()

def solve(r, c):
    for n in range(r*c+1):
        memo[(r, c, n)] = 100000
    m = 1 << (r*c)
    # happy = 1000000
    grid = [[None for y in range(c)] for x in range(r)]
    for bmap in range(0, m):
        count = 0
        for i in range(r):
            for j in range(c):
                grid[i][j] = bmap & 1
                bmap >>= 1
                if grid[i][j] == 1:
                    count += 1
        sreca = 0
        for i in range(r-1):
            for j in range(c):
                if grid[i][j] == 1 and grid[i+1][j] == 1:
                    sreca += 1
        for i in range(r):
            for j in range(c-1):
                if grid[i][j] == 1 and grid[i][j+1] == 1:
                    sreca += 1
        memo[(r, c, count)] = min(memo[(r, c, count)], sreca)
    # return happy
        

t = int(sys.stdin.readline())
for test_case_id in range(1, t+1):
    r, c, n = map(int, sys.stdin.readline().split())
    if (r, c, n) not in memo:
        solve(r, c)
    print('Case #{0}: {1}'.format(test_case_id, memo[(r, c, n)]))
