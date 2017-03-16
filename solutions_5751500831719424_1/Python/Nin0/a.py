#!/usr/bin/python3

import sys

t = int(sys.stdin.readline())

def to_rep_list(s):
    ret = []
    prev = s[0]
    cnt = 0
    for c in s:
        if c == prev:
            cnt += 1
        else:      
            ret.append((prev, cnt))
            prev = c
            cnt = 1
    ret.append((prev, cnt))
    return ret

def get_moves(l):
    a = min(l)
    b = max(l)
    best = float('inf')
    for i in range(a, b+1):
        cnt = 0
        for x in l:
            cnt += abs(i - x)
        best = min(best, cnt)
    return best

def solve(s_list, n):
    rl = [to_rep_list(s) for s in s_list]
    m = len(rl[0])
    for r in rl:
        if len(r) != m:
            return "Fegla Won"
    min_moves = 0
    for i in range(m):
        ch = rl[0][i][0]
        for j in range(n):
            if ch != rl[j][i][0]:
                return "Fegla Won"
        nums = [rl[j][i][1] for j in range(n)]
        min_moves += get_moves(nums)
    return min_moves

for i in range(1, t+1):
    n = int(sys.stdin.readline())
    s_list = [sys.stdin.readline().strip() for j in range(n)]
    print("Case #%d:" % i, solve(s_list, n))
