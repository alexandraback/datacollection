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
    return (readint(), readints())

def solve_case(n, m):
    s1 = sum((A-B) for A,B in zip(m[:-1],m[1:]) if B < A)
    r = 0
    try:
       r = max((A-B) for A,B in zip(m[:-1],m[1:]) if B < A)
    except:
       pass
    s2 = sum(min(r,A) for A in m[:-1])
    return (s1, s2)


def print_solution(case):
    val = solve_case(*case[1])
    msg = "Case #{}: {} {}".format(case[0], val[0], val[1])
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

