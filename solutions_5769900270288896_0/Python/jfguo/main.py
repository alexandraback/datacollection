
import os
import sys
import glob
import subprocess
import random
import fileinput


next_line = 0
lines = [line.strip() for line in fileinput.input()]
def get_line():
    global next_line
    i = next_line
    next_line += 1
    return lines[i]

def bn(i):
    ans = 0
    while i > 0:
        i &= i - 1
        ans += 1
    return ans

def calc():
    s = get_line()
    parts = s.split()
    R = int(parts[0])
    C = int(parts[1])
    N = int(parts[2])

    dr = [-1, 0, 0, 1]
    dc = [0, -1, 1, 0]

    ans = N * 4
    for i in range(1<<(R*C)):
        if bn(i) != N:
            continue

        t = 0
        for r in range(R):
            for c in range(C):
                if (i & (1<<(r*C+c))) == 0:
                    continue

                for j in range(4):
                    nr = r + dr[j]
                    nc = c + dc[j]
                    if nr < 0 or nr >= R or nc < 0 or nc >= C:
                        continue
                    if (i & (1<<(nr*C+nc))) != 0:
                        t += 1
        if t < ans:
            ans = t
    return ans / 2


T = int(get_line())
for i in range(1, T + 1):
    print('Case #%d: %s' % (i, calc()))
