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
    return stdin.readline().strip().split()

def parse():
    return read_ints()

def neighbors(i, r, c):
    result = []
    my_r, my_c = divmod(i, c)
    #print ("test", i, my_r, my_c)
    if r - 1 > my_r >= 0:
        #print("a")
        result.append((my_r + 1) * c + my_c)
    if 0 < my_r <= r - 1:
        #print("b")
        result.append((my_r - 1) * c + my_c)
    if c - 1 > my_c >= 0:
        #print("c")
        result.append(my_r * c + my_c + 1)
    if 0 < my_c <= c - 1:
        #print("d")
        result.append(my_r * c + my_c - 1)
    return result

def solve(r, c, n):
    best = 1000000
    for comb in itertools.combinations(range(r * c), n):
        pain = 0
        for t in comb:
            #print (t, "has", neighbors(t, r, c))
            for n in neighbors(t, r, c):

                if n in comb:
                    pain += 1
            #print (t, pain)
        if pain < best:
            best = pain
    return int(best / 2)

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
