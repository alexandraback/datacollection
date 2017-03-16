#from __future__ import division

from Tools import gcj
#from __future__ import division
#from functools32.functools32 import lru_cache
import sys
import itertools
import os
import re
import string
import math
import sys
import heapq
from collections import namedtuple, defaultdict, deque
from Tools.gcj import printd
from copy import deepcopy
#from simpleai.search import SearchProblem, astar
import random
import operator
#from Tools import primes
#from itertools import product


def is_empty(s):
    emp = True
    for w in s:
        if w[1] > 0:
            emp = False
            break
    return emp

def total_w(s):
    sum = 0
    for w in s:
        sum += w[1]
    return sum


def solver(n, p):
    sizes = {}
    plan = ""
    for i in xrange(n):
        name = chr(ord('A') + i)
        sizes[name] = p[i]

    sorted_sizes = sorted(sizes.items(), key=operator.itemgetter(1), reverse=True)
    while not is_empty(sorted_sizes):
        if (len(plan) > 0):
            plan += " "

        first = sorted_sizes[0]
        second = sorted_sizes[1]
        if total_w(sorted_sizes) == 3:
            #take one from first
            plan += first[0]
            sorted_sizes[0] = (first[0], first[1] - 1)

        else:
            if first[1] > second[1] and first[1] > 1:
                #take two from first
                plan += first[0] + first[0]
                sorted_sizes[0] = (first[0], first[1] - 2)
            elif first[1] == second[1]:
                plan += first[0] + second[0]
                sorted_sizes[0] = (first[0], first[1] - 1)
                sorted_sizes[1] = (second[0], second[1] - 1)
            elif first[1] > second[1] and first[1] == 1:
                #take two from first
                plan += first[0]
                sorted_sizes[0] = (first[0], first[1] - 1)
            else:
                print "WRONG CASE!!!!"
                exit(1)



        sorted_sizes = sorted(sorted_sizes, key=operator.itemgetter(1), reverse=True)

    return plan

def reader(in_file):
    """
    @type in_file: gcj.FileWrapper
    """
    n = in_file.getInt()
    p = in_file.getInts()

    return {
        'n': n,
        'p': p
    }


if __name__ == "__main__":
    ### GCJ module http://jamftw.blogspot.com.es/2012/05/python-code-jam-wrapper.html
    gcj.GCJ(reader, solver, os.getcwd(), "").run()
