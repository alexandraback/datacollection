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

def readint():
    return int(fi.readline())

def readints():
    return [int(X) for X in fi.readline().split()]

def readfloats():
    return [float(X) for X in fi.readline().split()]

def readstr():
    return fi.readline().rstrip()

def read_case():
    N = readint()
    return [readstr() for I in range(N)]

def movecount(l):
    b = 99999999
    for C in range(min(l),1+max(l)):
        c = 0
        for X in l: c += abs(X - C)
        if c < b: b = c
    return b

def parse(w):
    ch = []
    ct = []
    for C in w:
        if len(ch) == 0 or C != ch[-1]:
            ch.append(C)
            ct.append(1)
        else:
            ct[-1] += 1
    return (ch, ct)

def solve_case(l):
    X = [parse(W) for W in l]
    for Z in X:
      if Z[0] != X[0][0]:
        return 'Fegla Won'
    c = 0
    for I in range(len(X[0][0])):
        Z = [Q[1][I] for Q in X]
        c += movecount(Z)
    return c

def print_solution(case):
    val = solve_case(case[1])
    msg = "Case #{}: {}".format(case[0], val)
    print msg
    return msg

t0 = time()
# Initialisation here
t1 = time()
print "Intialisation took %f seconds" % (t1 - t0)

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
        print ''
    fi = open(fni, 'r')

    numcases = readint()
    cases = [(I, read_case()) for I in range(1,1+numcases)]

    mt = False
    if mt:
        print "Running multi-threaded"
        p = Pool(8)
        output = p.map(print_solution, cases)
    else:
        print "Running single-threaded"
        output = map(print_solution, cases)
    print "Elapsed time %f seconds " % (time() - t1)

    if os.path.isfile(fno):
        print 'Verifying against existing results'
        fo = open(fno, 'r')
        oc = re.split('(Case #[0-9]+:\s*)', fo.read())[1:]
        refout = [(A+B).rstrip() for (A,B) in zip(oc[::2], oc[1::2])]
        diffs = 0
        for C in range(numcases):
           if refout[C] != output[C]:
               print '-'*20
               print 'Input {}\nReference Output {}\nGenerated Output {}'.format(cases[C][1], refout[C], output[C])
               print '-'*20
               diffs += 1
        print '{} diffs found'.format(diffs)
    else:
        fo = open(fno, 'w')
        fo.write('\n'.join(output))
        print '{} cases written'.format(len(output))

