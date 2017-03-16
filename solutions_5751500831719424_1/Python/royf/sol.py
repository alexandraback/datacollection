
import math
import itertools
import numpy as NP

################################################################################

def read_case(f):
    N = read_int(f)
    S = [read_word(f) for i in range(N)]
    return (N, S)

def solve_small(case):
    (N, S) = case
    L = []
    for s in S:
        l = [[s[0], 1]]
        for i in range(1, len(s)):
            if s[i] == s[i-1]:
                l[-1][-1] += 1
            else:
                l.append([s[i], 1])
        L.append(l)
    x0 = [x[0] for x in L[0]]
    if not all([x[0] for x in l] == x0 for l in L[1:]):
        return 'Fegla Won'
    res = 0
    for i in range(len(x0)):
        c = sorted([l[i][1] for l in L])
        res += sum(abs(x-c[N//2]) for x in c)
    return res

def solve_large(case):
    return solve_small(case)

def write_case(f, i, res):
    f.write('Case #%d: '%i)
    f.write('%s'%res)
    f.write('\n')

################################################################################

def read_word(f):
    return next(f).strip()

def read_int(f, b=10):
    return int(read_word(f), b)

def read_letters(f):
    return list(read_word(f))

def read_digits(f, b=10):
    return [int(x, b) for x in read_letters(f)]

def read_words(f, d=' '):
    return read_word(f).split(d)

def read_ints(f, b=10, d=' '):
    return [int(x, b) for x in read_words(f, d)]

def read_floats(f, d=' '):
    return [float(x) for x in read_words(f, d)]

def read_arr(f, R, reader=read_ints, *args, **kwargs):
    return [reader(f, *args, **kwargs) for i in range(R)]

def solve(solver, fn, out_fn=None):
    in_fn = fn + '.in'
    if out_fn is None:
        out_fn = fn + '.out'
    with open(in_fn, 'r') as fi:
        with open(out_fn, 'w') as fo:
            T = read_int(fi)
            for i in range(T):
                case = read_case(fi)
                res = solver(case)
                write_case(fo, i, res)

DEBUG = 'i'

from run import *
