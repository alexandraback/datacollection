#!/usr/bin/python2
import sys
import multiprocessing
import logging
import os
import itertools
import math
import gmpy2
import copy
import collections
import string
import scipy.stats as stats
import argparse


def solve(casedata):
    """ Solve case """
    R, C, N = casedata
    rc = R*C
    result = list()
    nbempty = R*C - N
    res = -1
    def score(epos):
        sc = 0
        # lines
        prev = False
        for i in range(rc):
            if i % C == 0:
                prev = False
            pres = i not in epos
            if prev and pres:
                sc += 1
            prev = pres
        # columns
        prev = False
        for c in range(C):
            for r in range(R):
                nb = r*C + c
                pres = nb not in epos
                if prev and pres:
                    sc += 1
                prev = pres
            prev = False
        return sc

    for emptyspots in itertools.combinations(range(R*C), nbempty):
        # list of empty spots
        s = score(emptyspots)
        if res < 0 or s < res:
            res = s
        
    return str(res)

def parse():
    """ Returns a list of N lists containing imput data for each case """
    t = int(sys.stdin.readline())
    cases = list()
    for case in range(t):
        R, C, N = map(int, sys.stdin.readline().rstrip('\n').split())
        casedata = [R, C, N]
        cases.append(casedata)
    return cases

if __name__ == '__main__':
    aparser = argparse.ArgumentParser()
    aparser.add_argument('-m', '--multiprocessing', action='store_true', default=False, required=False)
    args = aparser.parse_args()
    cases = parse()
    if args.multiprocessing:
        p = multiprocessing.Pool(multiprocessing.cpu_count())
        resultobjs = [p.apply_async(solve, [case]) for case in cases]
        for case, resultobj in enumerate(resultobjs):
            print('Case #%d: %s' % (case + 1, resultobj.get()))
            sys.stdout.flush()
    else:
        for case, data in enumerate(cases):
            result = solve(data)
            print('Case #%d: %s' % (case + 1, result))
            #sys.stdout.flush()
        p = multiprocessing.Pool(multiprocessing.cpu_count())

    #results = p.map(solve, cases)
    #for case, result in enumerate(results):
    #    print('Case #%d: %s' % (case + 1, result))
    #    sys.stdout.flush()


    #p = multiprocessing.Pool(multiprocessing.cpu_count())
    #resultobjs = [p.apply_async(solve, [case]) for case in cases]
    #for case, resultobj in enumerate(resultobjs):
    #    print('Case #%d: %s' % (case + 1, resultobj.get()))
    #    sys.stdout.flush()
