#!/usr/bin/env python3

import sys
rl = lambda: sys.stdin.readline()
T = int(rl())

def solve(casei):
    line = rl()
    N = int(line)
    m = []
    for x in rl().split():
        m.append(int(x))
    #print("DEBUG:", m)
    ans1 = 0
    ans2 = 0
    mymax = 0
    for i in range(1, len(m)):
        t = m[i] - m[i-1]
        if t < 0:
            ans1 += -t
        if -t > mymax:
            mymax = -t
    for i in range(1, len(m)):
        ans2 += min(m[i-1], mymax)
    print("Case #{}: {} {}".format(casei, ans1, ans2))

for i in range(1, T+1):
    solve(i)
