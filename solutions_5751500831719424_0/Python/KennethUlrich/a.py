import argparse
import collections
import fractions
import functools
import itertools
import math
import operator

from sys import exit, stdin
from multiprocessing import Pool

def solve_star(args):
    return solve(*args)

def read_int():
    return int(stdin.readline().strip())

def read_ints():
    return [int(n) for n in stdin.readline().strip().split()]

def read_floats():
    return [float(n) for n in stdin.readline().strip().split()]

def read_words():
    return stdin.readline().strip()

def parse():
    result = []
    for i in range(read_int()):
        result.append(read_words())
    return [result]

def solvable(strings):
    z = set()
    for s in strings:
        result = [s[0]]
        old_c = s[0]
        count = 0
        for i, c in enumerate(s):
            if c == old_c:
                pass
            else:
                result.append(c)
            old_c = c
        z.add("".join(result))
    return len(z) == 1

        
    r = set([''.join(collections.OrderedDict.fromkeys(s).keys()) for s in strings])
    return len(r) == 1

def get_counts(s):
    result = [0]
    old_c = s[0]
    count = 0
    for i, c in enumerate(s):
        if c == old_c:
            pass
        else:
            result.append(i)
        old_c = c
    for i in range(len(result) - 1):
        result[i] = result[i + 1] - result[i]
    result[-1] = len(s) - result[-1]
    return result

def solve(strings):
    if not solvable(strings):
        return "Fegla Won"
    counts = [get_counts(s) for s in strings]
    zipped = zip(*counts)
    total = 0
    for z in zipped:
        best = None
        for y in z:
            score = sum(abs(y - yy) for yy in z)
            if best is None or best > score:
                best = score
        total += best
    return total
        

if __name__ == "__main__":
    
    parser = argparse.ArgumentParser()
    parser.add_argument("-m", "--multi", help="turn on multiprocessing", action="store_true")
    args = parser.parse_args()
    
    with open("out.txt", "w") as f:
        if args.multi:
            pool = Pool()
            iter = pool.imap(solve_star, (parse() for i in range(read_int())))
            for i, result in enumerate(iter):
                s = "Case #{}: {}".format(i + 1, result)
                print(s)
                f.write(s + "\n")
        
        else:
            for i in range(read_int()):
                s = "Case #{}: {}".format(i + 1, solve(*parse()))
                print(s)
                f.write(s + "\n")
