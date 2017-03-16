import math
from time import time
import itertools
import operator
from sys import *
from heapq import *
from time import time
from multiprocessing import Pool
from collections import *
import itertools
from copy import deepcopy
from bisect import *
setrecursionlimit(10000)
from math import *
from time import sleep
import os
import sys
import re
import numpy as np
import heapq

def readint():
    return int(fi.readline())

def readints():
    return [int(X) for X in fi.readline().split()]

def read_case():
    n = readint()
    xy = [readints() for _ in range(n)]
    return (n, xy)

# Three points are a counter-clockwise turn if ccw > 0, clockwise if
# ccw < 0, and collinear if ccw = 0 because ccw is a determinant that
# gives the signed area of the triangle formed by p1, p2 and p3.
def ccw(p1, p2, p3):
    return (p2[0]-p1[0])*(p3[1]-p1[1])-(p2[1]-p1[1])*(p3[0]-p1[0])

def solvecase(n, xy):
    for S in xy:
        best = n-1
        for P in xy:
            if S==P: continue
            r = 0
            l = 0
            for Q in xy:
                c = ccw(S,P,Q)
                if c < 0: r += 1
                if c > 0: l += 1
            best = min(best, l, r)
        yield str(best)

def solve_case(n, xy):
    return "\n" + "\n".join(solvecase(n, xy))

def print_solution(case):
    val = solve_case(*case[1])
    msg = "Case #{}: {}".format(case[0], val)
    print(msg)
    return msg

t0 = time()
t1 = time()
print("Intialisation took %f seconds" % (t1 - t0))
if (t1-t0 > 5): input("Press Enter to continue...")
t1 = time()

if __name__ == '__main__':
    fni = "%s-%s-%s.in" % (argv[1], argv[2], argv[3])
    fno = "%s-%s-%s.out" % (argv[1], argv[2], argv[3])

    if not os.path.isfile(fni):
        sys.stdout.write('Waiting for input file {}...'.format(fni))
        while not os.path.isfile(fni):
            sys.stdout.flush()
            sleep(1)
            sys.stdout.write(".")
        sleep(1)
        print('')
    fi = open(fni, 'r')

    numcases = readint()
    cases = [(I, read_case()) for I in range(1,1+numcases)]

    mt = False
    if mt:
        print("Running multi-threaded")
        p = Pool(8)
        output = list(p.map(print_solution, cases))
    else:
        print("Running single-threaded")
        output = list(map(print_solution, cases))
    print("Elapsed time %f seconds " % (time() - t1))

    if os.path.isfile(fno):
        print('Verifying against existing results')
        fo = open(fno, 'r')
        oc = re.split('(Case #[0-9]+:\s*)', fo.read())[1:]
        refout = [(A+B).rstrip() for (A,B) in zip(oc[::2], oc[1::2])]
        diffs = 0
        for C in range(numcases):
           if refout[C] != output[C]:
               print('-'*20)
               print('Input {}\nReference Output {}\nGenerated Output {}'.format(cases[C][1], refout[C], output[C]))
               print('-'*20)
               diffs += 1
        print('{} diffs found'.format(diffs))
    else:
        fo = open(fno, 'w')
        fo.write('\n'.join(output))
        print('{} cases written'.format(len(output)))

