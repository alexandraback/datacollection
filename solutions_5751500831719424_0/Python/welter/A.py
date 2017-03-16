#!/usr/bin/python

import sys
from itertools import groupby
from numpy import median

def read_obj(cls):
    return cls(sys.stdin.readline().strip())

def read_obj_list(cls):
    return map(cls, sys.stdin.readline().strip().split())

def calculate(k):
    md = int(median(k))
    return sum([abs(md - a) for a in k])

def solve():
    t = read_obj(int)
    for i in xrange(1, t + 1):
        n = read_obj(int)
        data = []
        for j in xrange(n):
            s = read_obj(str)
            info = [(lt, sum(1 for _ in it)) for (lt, it) in groupby(s)]
            lts, nums = zip(*info)
            lts, nums = list(lts), list(nums)
            data.append((lts, nums))
        print "Case #%d:" % i,
        if all([lts == data[0][0] for (lts, _) in data]):
            res = 0
            ks = map(list, zip(*[nums for (_, nums) in data]))
            for k in ks:
                res += calculate(k)
            print res
        else:
            print "Fegla won"

if __name__ == "__main__":
    solve()
