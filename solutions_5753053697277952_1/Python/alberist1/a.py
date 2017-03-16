#!/usr/bin/python3
# -*- coding: utf-8 -*-


def solve():
    n = int(input())
    p = [[int(x), chr(ord('A') + i)] for i, x in enumerate(input().split())]
    s = sum(x[0] for x in p)
    res = []
    while s:
        x = max(p)
        x[0] -= 1
        s -= 1
        if s % 2 == 0:
            res.append(x[1])
            continue
        x2 = max(p)
        x2[0] -= 1
        s -= 1
        res.append(x[1] + x2[1])
    return ' '.join(res)


if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        print('Case #%d:' % (i+1), solve())
