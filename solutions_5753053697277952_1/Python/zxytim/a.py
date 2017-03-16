#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# $File: a.py
# $Date: Sun May 08 17:13:21 2016 +0800
# $Author: Xinyu Zhou <zxytim[at]gmail[dot]com>

import math
import numpy as np

def solve():
    n = int(input().strip())
    nums = list(map(int, input().strip().split()))
    cnt = [[v, k] for k, v in enumerate(nums)]

    ans = []
    while True:
        cnt = list(filter(lambda x: x[0] > 0,
                     sorted(cnt, key=lambda x: x[0], reverse=True)))
        if len(cnt) == 0:
            break
        tot = sum(x[0] for x in cnt)
        if len(cnt) == 2 and cnt[0][0] == cnt[1][0]:
            cnt[0][0] -= 1
            cnt[1][0] -= 1
            ans.append((cnt[0][1], cnt[1][1]))
        else:
            cnt[0][0] -= 1
            ans.append((cnt[0][1],))
    s = ' '.join([''.join([chr(ord('A') + i) for i in e])
         for e in ans])
    print(s)

# print(solve())
nr_case = int(input().strip())

for case_id in range(1, nr_case + 1):
    print('Case #{}: '.format(case_id), end='')
    solve()


# vim: foldmethod=marker

