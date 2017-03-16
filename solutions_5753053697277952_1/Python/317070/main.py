import glob, pprint, pickle, os, time, sys
from copy import copy
from numpy import array, sin, cos
import numpy as np
import itertools
import math


def solve(p):
    result = ""
    while sum(p)>0:
        idx = np.argmax(p)
        p[idx] -= 1
        result += "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[idx]
        if max(p) <= 1.0*sum(p)/2:
            result += " "

    result = result.strip()
    #result = result[:-2]+result[-1]
    return (result,)


output = ""
TIC = time.time()
with open(sys.argv[1] if len(sys.argv) > 1 else "default.in") as f:
    def read_ints():
        return [int(x) for x in f.readline().strip().split(' ')]
    def read_frac():
        return [int(x) for x in f.readline().strip().split('/')]
    def read_strs():
        return [x for x in f.readline().strip().split(' ')]
    def read_chrs():
        return [x for x in f.readline().strip()]
    def read_floats():
        return [float(x) for x in f.readline().strip().split(' ')]

    (numquestions,) = read_ints()
    for questionindex in xrange(numquestions):

        ### calculate answer ###
        _ = read_ints()
        parties = read_ints()
        answer = solve(parties)

        ### output ###
        answer_str = "Case #{}: {}".format(questionindex+1, " ".join([str(a) for a in answer]))
        output += answer_str + '\n'
        print answer_str

ofile = open('output', 'w').write(output)
TOC = time.time()