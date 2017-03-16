#!/usr/bin/python
import sys
import multiprocessing
import logging
import os
import itertools
import math
#import gmpy2
import copy
import collections
import string
import scipy.stats as stats


def solve(casedata):
    """ Solve case """
    (q1, a1, q2, a2) = casedata
    poss1 = set(a1[q1-1])
    poss2 = set(a2[q2-1])
    inter = poss1 & poss2
    if len(inter) == 1:
        return str(inter.pop())
    elif len(inter) == 0:
        return "Volunteer cheated!"
    else:
        return "Bad magician!"

def parse():
    """ Returns a list of N lists containing imput data for each case """
    t = int(sys.stdin.readline())
    cases = list()
    for case in range(t):
        q1 = int(sys.stdin.readline())
        a1 = []
        for i in range(4):
            a1.append(sys.stdin.readline().rstrip('\n').split(' '))
        q2 = int(sys.stdin.readline())
        a2 = []
        for i in range(4):
            a2.append(sys.stdin.readline().rstrip('\n').split(' '))
        casedata = [q1, a1, q2, a2]
        cases.append(casedata)
    return cases

if __name__ == '__main__':
    cases = parse()
    #p = multiprocessing.Pool(multiprocessing.cpu_count())
    #results = p.map(solve, cases)
    #for case, result in enumerate(results):
    #    print('Case #%d: %s' % (case + 1, result))
    #    sys.stdout.flush()

    for case, data in enumerate(cases):
        result = solve(data)
        print('Case #%d: %s' % (case + 1, result))
        sys.stdout.flush()

    #p = multiprocessing.Pool(multiprocessing.cpu_count())
    #resultobjs = [p.apply_async(solve, [case]) for case in cases]
    #for case, resultobj in enumerate(resultobjs):
    #    print('Case #%d: %s' % (case + 1, resultobj.get()))
    #    sys.stdout.flush()
