#!/usr/bin/env python
import math
import sys

history = set([])
final = 0, 0
delta = [(-1, 0), (0, -1), (1, 0), (0, 1)]

def maps_to_bits(maps):
    ans = 0
    for i in xrange(len(maps)):
        for j in xrange(len(maps[i])):
            if maps[i][j]:
                ans += (1<<(i*len(maps[0]) + j))
    return ans
def dfs(maps, n, current):
    global final
    global history
    if n == 0:
        # print current
        if current < final:
            final = current
        return

    if maps_to_bits(maps) in history:
        return
    history.add(maps_to_bits(maps))

    r = len(maps)
    c = len(maps[0])
    for i in xrange(r):
        for j in xrange(c):
            if maps[i][j]:
                continue
            maps[i][j] = True
            count = 0
            for k in xrange(4):
                if i + delta[k][0] >= 0 and i + delta[k][0] < r and j + delta[k][1] >= 0 and j+delta[k][1] < c:
                    if maps[i+delta[k][0]][j+delta[k][1]]:
                        count += 1
            dfs(maps, n - 1, current + count)
            maps[i][j] = False

def solve():
    global final
    global history
    line = raw_input()
    r,c,n = [int(x) for x in line.split()]

    OO = float("inf")

    uh_count = 0
    maps = [None] * r;
    for i in xrange(r):
        maps[i] = [False] * c

    history = set([])
    final = float("inf")
    dfs(maps, n, 0)

    return final

case_num = input()
for case in range(1, case_num + 1):
    ans = solve()
    sys.stderr.write(str(case) + "\n")
    print("Case #%i: %i" % (case, ans))
