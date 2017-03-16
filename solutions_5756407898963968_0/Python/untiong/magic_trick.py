# -*- coding: utf-8 -*-
"""
Created on Fri Apr 11 19:32:41 2014

@author: Yun-Jhong Wu
"""

with open('A-small-attempt0.in', 'r') as dat, open('output.txt', '+w') as output:
    n = int(dat.readline())
    for i in range(n):
        r1 = int(dat.readline())
        for j in range(4):
            if j < r1:
                line1 = list(map(int, dat.readline().strip('\n').split()))
            else:
                list(map(int, dat.readline().strip('\n').split()))
        r2 = int(dat.readline())
        for j in range(4):
            if j < r2:
                line2 = list(map(int, dat.readline().strip('\n').split()))
            else:
                list(map(int, dat.readline().strip('\n').split()))

        a = set(line1).intersection( set(line2) )      

        if len(a) > 1:
            output.write('Case #' + str(i + 1) + ': Bad magician!\n')
        elif len(a) == 0:
            output.write('Case #' + str(i + 1) + ': Volunteer cheated!\n')
        else:
            output.write('Case #' + str(i + 1) + ': ' + str(a.pop()) + '\n')