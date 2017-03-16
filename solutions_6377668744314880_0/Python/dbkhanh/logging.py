#!/usr/bin/env python

import os, sys
import random

lines = {}
def get_line(tree, other):
    if (tree, other) in lines:
        return lines[(tree, other)]
    if (other, tree) in lines:
        return lines[(other, tree)]
    if other[0] != tree[0]:
        m = float(other[1] - tree[1]) / (other[0] - tree[0])
        intercept = -m * tree[0] + tree[1]
        return (m, intercept)
    else:
        return ("vertical", tree[0])

def count_side(line, trees):
    above = below = 0
    for tree in trees:
        if line[0] == "vertical":
            if tree[0] < line[1]:
                above += 1
            elif tree[0] > line[1]:
                below += 1
        else:
            m, intercept = line
            y = m * tree[0] + intercept
            if tree[1] > y:
                above += 1
            elif tree[1] < y:
                below += 1
    return min(above, below)

def solve(trees):
    lines = {}
    answers = []
    for tree in trees:
        answer = 1e9
        for other in trees:
            if tree == other: continue
            answer = min(answer, count_side(get_line(tree, other), trees))
        answers.append(answer)
    return answers

def main():
    lines = open(sys.argv[1]).read().rstrip().splitlines()
    T = int(lines[0])
    i = 1
    for case in range(1, T+1):
        N = int(lines[i])
        trees = [tuple(map(int, lines[i+n+1].split())) for n in xrange(N)]
        i += N + 1
        answers = solve(trees)
        print("Case #{}:".format(case))
        for answer in answers:
            print(answer)

def gen_big():
    print(100)
    for t in xrange(100):
        N = random.randint(1, 1000000000)
        print("1000 {}".format(N))
        ms = []
        for i in xrange(1000):
            ms.append(random.randint(1, 100000))
        print(" ".join(map(str, ms)))

if __name__ == "__main__":
    # gen_big()
    main()
