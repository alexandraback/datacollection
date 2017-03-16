#!/usr/bin/env python3

from string import ascii_uppercase
from heapq import nlargest


def solve(sizes):
    senators = []
    for i in range(len(sizes)):
        senators.append([sizes[i], ascii_uppercase[i], i])
    res = []
    remaining = sum(sizes)
    while remaining > 0:
        top, second = nlargest(2, senators)
        if top[0] == second[0] and remaining % 2 == 0:
            top[0] -= 1
            second[0] -= 1
            res.append("%s%s" % (top[1], second[1]))
            remaining -= 2
        else:
            top[0] -= 1
            res.append(top[1])
            remaining -= 1
    for s in senators:
        assert s[0] == 0, senators
    return ' '.join(res)


def main():
    for i in range(int(input())):
        n = int(input())
        sizes = [int(s) for s in input().split()]
        assert len(sizes) == n
        print("Case #%s: %s" % (i+1, solve(sizes)))
main()