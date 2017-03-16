#!/usr/bin/env python
# -*- coding: utf-8 -*-
import math
import numpy as np
import sys
import copy
import itertools as it
import re
import collections

def rint():
    return map(int, raw_input().split())

def rstr():
    return raw_input().split()

def rlist(*lfn):
    return  [f(a) for (f, a) in zip(lfn, raw_input().split())]

if __name__ == "__main__":
    testcases = input()
     
    for caseNr in xrange(testcases):
        [R, C, N] = rint()
        T = 0
        if R > C:
            C, R = R, C
        if R == 1:
            if C % 2 == 0:
                if N <= C / 2:
                    T = 0
                else:
                    U = N - C / 2
                    T = 2 * U - 1
            else:
                if N <= (C + 1) / 2:
                    T = 0
                else:
                    U = N - (C + 1) / 2
                    T = 2 * U
        else:
            if (R * C) % 2 == 1:
                B4 = ((R - 2) * (C - 2) + 1)/2
                B3 = R - 3 + C - 3
                HR = R * C / 2
                if N <= R*C - HR:
                    T = 0
                elif (R * C - N) > B3 + B4:
                    T = (N - (R * C + 1) / 2) * 3
                else:
                    U = R * C - N
                    if U <= B4:
                        T = 2 * R * C - R - C - 4 * U
                    else:
                        T = 2 * R * C - R - C - 4 * B4 - 3 * (U - B4)
            else:
                A2, A3, A4 = 2, R + C - 4, (R - 2)*(C - 2)/2
                HR = R * C / 2
                if N <= R*C - HR:
                    T = 0
                else:
                    U = N - (R*C - HR)
                    if U <= A2:
                        T = 2 * U
                    elif U <= A3 + A2:
                        T = 2 * A2 + (U - A2) * 3
                    else:
                        T = 2 * A2 + 3 * A3 + (U - A2 - A3) * 4

        print("Case #%i: %i" % (caseNr + 1, T))
#        print("Case #%i:" % (caseNr + 1))
