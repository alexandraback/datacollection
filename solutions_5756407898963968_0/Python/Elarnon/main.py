#!/usr/bin/env python3

import sys

def one_square(f):
    row = int(f.readline())
    for i in range(1, row):
        f.readline()
    res = set(int(x) for x in f.readline().split())
    for i in range(row + 1, 5):
        f.readline()
    return res

def one_case(f):
    possible = one_square(f)
    possible &= one_square(f)
    if len(possible) == 1:
        return possible.pop()
    elif len(possible) > 1:
        return "Bad magician!"
    else: # len(possible) == 0
        return "Volunteer cheated!"

def solve(f, g):
    ncases = int(f.readline())
    for i in range(1, ncases + 1):
        print("Case #{}: {}".format(i, one_case(f)), file=g)
    
if __name__ == '__main__':
    solve(sys.stdin, sys.stdout)