from itertools import *
from functools import *
from operator import *
from math import *
from collections import Counter
from statistics import *
import heapq

import os
import sys
sys.setrecursionlimit(10000)
os.chdir(os.path.dirname(os.path.realpath(__file__)))

filename = "B-small-attempt1"
result_string = "Case #{}: {}"

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def lcm(a, b):
    return a * b // gcd(a, b)

def lcmm(*args):
    return reduce(lcm, args)
def generate_barber_cycle(MS):
    for i in count():
        for j, ms in enumerate(MS, start=1):
            if i % ms == 0:
                yield (j, ms)   

def main(input_filename, output_filename):
    with open(input_filename) as input, open(output_filename, 'w') as output:
        T, = nis(input)
        for t in range(T):
            B, N = nis(input)
            MS = nis(input)
            # print(MS)
            l = lcmm(*MS)
            c = sum(int(l/ms) for ms in MS)
            # print("the lcm is {}, during {} minutes the barbers cut {} clients".format(l,l, c))
            our_cycle = ceil(N / c)
            # print("our cycle {}".format(our_cycle))
            our_rank = (N-1)%c
            # print("our rank in the cycle {}".format(our_rank))
            gen = iter(generate_barber_cycle(MS))
            while our_rank > 0:
                # print(next(gen))
                next(gen)
                our_rank -= 1
            res = next(gen)[0]
            # res = None
            # print(res)
            w(output, t, res)

def w(output, t, res):
    print(result_string.format(t+1, res))
    output.write(result_string.format(t+1, res)+'\n')

def nis(input):
    return list(map(int, input.readline().split()))

def sis(input):
    return input.readline().split()

def integer_sqrt(i):
    """return tuple (s, b), where b is true if and only if i is a perfect square
    and s is the integer square root
    """
    if not i: return 0
    if i < 0: raise ValueError("cannot calculate square root of negative")
    def n(xn):
        return (xn + i/xn)/2
    xn, xnp, xnpp = i, n(i), n(n(i))
    while xn != xnpp:
        xn, xnp, xnpp = xnp, xnpp, n(xnpp)
    return min(xnp, xnp)

class Memoize(object):
    def __init__(self, f):
        self.f = f
        self.memory = {}
    def __call__(self, *args, **kwargs):
        if (tuple(args), tuple(kwargs.items())) in self.memory:
            return self.memory[(tuple(args), tuple(kwargs.items()))]
        else:
            val = self.f(*args, **kwargs)
            self.memory[(tuple(args), tuple(kwargs.items()))] = val
            return val

def inversion_count(seq):
    if len(seq) < 2:
        return seq, 0
    l = len(seq)/2
    seq1, c1 = inversion_count(seq[:l])
    seq2, c2 = inversion_count(seq[l:])
    inv = 0
    seq = []
    while seq1 or seq2:
        if not seq1:
            seq += seq2
            seq2 = []
        elif not seq2:
            seq += seq1
            seq1 = []
        else:
            e1 = seq1[0]
            e2 = seq2[0]
            if e1 > e2:
                inv += len(seq1)
                seq.append(e2)
                seq2 = seq2[1:]
            else:
                seq.append(e1)
                seq1 = seq1[1:]
    return seq, inv + c1 + c2


if __name__ == '__main__':
    input_filename = "{}.in".format(filename)
    output_filename = "{}.out".format(filename)
    main(input_filename, output_filename)