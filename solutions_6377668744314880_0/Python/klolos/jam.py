#!/usr/bin/env python
import sys

case_num = 1
def printres(result):
    global case_num
    print "Case #%s: %s" % (case_num, result)
    case_num += 1

def readline(): 
    return sys.stdin.readline().rstrip('\n')
def splitline(f):
    return map(f, readline().split())

def calc(t1, t2, tree):
    x1, y1 = t1
    x2, y2 = t2
    x3, y3 = tree

    if x1 == x2:
        if x3 < x2:
            return 0 # "above"
        elif x3 > x2:
            return 1 # "below"
        else:
            return 2 # "none"

    #slope = (y1-y2)/(x1-x2)
    #y4 = y1 + slope * (x3 - x1)
    a = (y3-y1) * (x1-x2)
    b = (y1-y2) * (x3-x1)
    if a > b:
        return 0 # "above"
    elif a < b:
        return 1 # "below"
    else:
        return 2 # "none"

def calc_cut(t1, t2, trees):
    above = 0
    below = 0
    for tree in trees:
        if (tree != t1) and (tree != t2):
            pos = calc(t1, t2, tree)
            if pos == 0: # "above"
                above += 1
            elif pos == 1: #"below"
                below += 1

    return min(above, below)
    

def calc_min_cut(t, trees):
    if len(trees) < 4:
        return 0

    min_cut = 10**10
    for tree in trees:
        if t != tree:
            min_cut = min(min_cut, calc_cut(t, tree, trees))
    return min_cut

def solve():
    N = int(readline())
    trees = []
    for i in range(N):
        x, y = splitline(int)
        trees.append((x, y))

    printres("")
    for t in trees:
        print calc_min_cut(t, trees)

def main():
    for i in range(int(readline())): solve()

if __name__ == '__main__': 
    main()

