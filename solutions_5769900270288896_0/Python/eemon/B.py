#!/usr/bin/env python
# -*- coding: utf-8 -*-
import itertools
import copy

def check(building):
    count = 0
    for i in range(R):
        for j in range(C):
            if building[i][j] is not False:
                if i+1 < R and building[i+1][j] is not False:
                    count += 1
                if j+1 < C and building[i][j+1] is not False:
                    count += 1
    return count

T = int(input())
for case in range(T):
    R,C,N = map(int,input().split())
    mapping = dict()
    building = []
    ans = 10**9
    count = 0
    for i in range(R):
        building.append([])
        for j in range(C):
            building[i].append(False)
            mapping[count] = (i,j)
            count += 1
    for comb in itertools.combinations(range(R*C),N):
        _building = copy.deepcopy(building)
        for x in comb:
            r,c = mapping[x]
            _building[r][c] = True
        ans = min(ans,check(_building))
    print("Case #{0}: {1}".format(case+1,ans))


