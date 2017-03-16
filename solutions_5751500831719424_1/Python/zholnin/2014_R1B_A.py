import sys # standard Python library
import itertools # standard Python library
#from PerfectAllocation import PerfectAllocation # http://pastebin.com/5sv1quf0
from operator import itemgetter # standard Python library
import bisect # standard Python library
import math # standard Python library
import copy # standard Python library
from fractions import gcd # standard Python library
from utilities import *  # this is helper file which can be found at http://pastebin.com/5gkyim8x
# from blist import blist # add-on library which can be downloaded from https://pypi.python.org/pypi/blist/


sys.setrecursionlimit(1000) #1000 is default
Prep = []


def preprocess():
    return None
    
def readinput(Input):
    N = Input.readint()
    
    Words = []
    
    for _ in range(N):
        Words.append(Input.readstring())
    
    return Words

def solve(Problem, Prep):
    Words = Problem
    D = {}
    
    for w in Words:
        D[w] = {}
        seq = 0
        count = 1
        letter = ""
        for i in w:
            if letter == i:
                count += 1
            else:
                if letter <> "":
                    D[w][seq] = (letter, count)
                    seq += 1
                letter = i
                count = 1
        D[w][seq] = (letter, count)
        if len(D[w]) <> len(D[Words[0]]):
            return "Fegla Won"
    
    count = 0
    for i in range(len(D[Words[0]])):
        List = []
        letter = D[Words[0]][i][0]
        for w in D:
            if D[w][i][0] <> letter:
                return "Fegla Won" 
            List.append(D[w][i][1])
        
        maximum = max(List)
        best = 10000
        for i in range(1, maximum + 1):
            difference = sum([abs(j - i) for j in List ])
            if difference < best:
                best = difference
        count += best
    
    return count
    
    
    
    

    return 0


if __name__ == "__main__":
    doit(preprocess, readinput, solve, MultiCore = True, Verify = False, Input = LARGE, Filename = None, Problem = "A", Attempt = 0)
