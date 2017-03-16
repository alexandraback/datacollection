# python 3
import string
import itertools
import sys
from pprint import pprint

STR_IMPOSSIBLE = 'Fegla Won'

def letter_counts(s):
    cnt = [(k, sum(1 for i in g)) for k,g in itertools.groupby(s)]
    return cnt

def min_dist(nums):
    N = len(nums)
    res = min(sum(abs(cntr-k)
                  for k in nums)
              for cntr in nums)
    return res
        
def process_case(data):
    N = len(data)
    result = None
    cnts = [letter_counts(s) for s in data]
    L = len(cnts[0])
    for cnt in cnts:
        if len(cnt) != L:
            return None
    result = 0
    for i in range(L):
        ch = cnts[0][i][0]
        for n in range(N):
            if cnts[n][i][0] != ch:
                return None
    for i in range(L):
        nums = [cnts[n][i][1] for n in range(N)]
        result += min_dist(nums)
    return result

def result_gen(lines):
    ncases = int(next(lines))
    for ci in range(1,ncases+1):
        N = int(next(lines))
        data = [next(lines).strip() for i in range(N)]
        result = process_case(data)
        if result is None:
            result = STR_IMPOSSIBLE
        yield 'Case #{0}: {1}\n'.format(ci, result)
    
def line_of_numbers(s):
    return [int(sub) for sub in s.split()]

def input_gen(f_in):
    for line in f_in:
        if line.endswith('\n'):
            line = line[:-1]
        yield line

def start(basename):
    infile = basename + '.in'
    outfile = basename + '.out'
    f_in = open(infile, 'r')
    f_out = open(outfile, 'w')
    f_out.writelines(result_gen(input_gen(f_in)))
    f_in.close()
    f_out.close()

##start('A-test')
##start('A-small-attempt0')
start('A-large')
