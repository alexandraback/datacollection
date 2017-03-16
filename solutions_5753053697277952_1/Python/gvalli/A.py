#! /#!/usr/bin/env python
# -*- coding: utf-8 -*-

from operator import itemgetter
import sys


def total(ls):
    res = 0
    for l in ls:
        res += l[0]
    return res

fh = open(sys.argv[1], 'r')
T = int(fh.readline())  # number of test cases
for t in range(T):
    N = int(fh.readline())  # number of parties
    nums = [[int(v), chr(ord('A') + i)] for i, v in enumerate(fh.readline().split())]

    res = list()
    while total(nums) > 0:
        nums.sort(key=itemgetter(0), reverse=True)
        s = total(nums)
        if (nums[0][0] >= 2) and (nums[1][0] <= (s - 2) / 2.0):
            # take 2 from the biggest, the second is not gaining majority
            nums[0][0] -= 2
            res.append(nums[0][1] + nums[0][1])
        elif (nums[0][0] >= 1) and (nums[1][0] <= (s - 1) / 2.0):
            # take 1 from the biggest, the second is not gaining majority
            nums[0][0] -= 1
            res.append(nums[0][1])
        elif len(nums) == 2:
            # only two parties
            nums[0][0] -= 1
            nums[1][0] -= 1
            res.append(nums[0][1] + nums[1][1])
        elif (nums[0][0] >= 1) and (nums[1][0] >= 1) and (nums[2][0] <= (s - 2) / 2.0):
            # take from the two first, third is not gaining majority
            nums[0][0] -= 1
            nums[1][0] -= 1
            res.append(nums[0][1] + nums[1][1])
    res = ' '.join(res)

    print('Case #{:d}: {}'.format(t + 1, res))
