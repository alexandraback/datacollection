#!/usr/bin/env python2
# -*- coding: utf-8 -*-
# $File: work.py
# $Date: Sat Apr 12 20:41:32 2014 +0800
# $Author: jiakai <jia.kai66@gmail.com>

def read():
    return map(int, raw_input().split())

nr_case, = read()

for case in range(1, nr_case + 1):
    r1, = read()
    mat1 = [read() for _ in range(4)]
    r2, = read()
    mat2 = [read() for _ in range(4)]
    cand = list(set(mat1[r1 - 1]) & set(mat2[r2 - 1]))
    print 'Case #{}:'.format(case),
    if len(cand) == 1:
        print cand[0]
    elif len(cand) > 1:
        print 'Bad magician!'
    else:
        print 'Volunteer cheated!'
