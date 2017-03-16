#!/usr/bin/env python

import sys
import random
import math

def log_min(atans):
    atans.sort()
    MAX = 99999999999
    minumum = MAX
    for i in atans:
        if i < 0.0:
            lb = i
            mb = i + math.pi
        else:
            mb = i
            lb = i - math.pi

        bound = 0
        zone1 = 0
        zone2 = 0
        for j in atans:
            if abs(j - lb) < 1e-10 or abs(j - mb) < 1e-10:
                bound += 1
            elif j > lb and j < mb:
                zone1 += 1
            elif j < lb or j > mb:
                zone2 += 1
        minumum = min(zone1, zone2, minumum)
    if minumum == MAX:
        return 0
    return minumum


def run(trees):
    for my_idx, my_tree in enumerate(trees):
        atans = []
        for idx, tree in enumerate(trees):
            if idx != my_idx:
                delta = (tree[0] - my_tree[0], tree[1] - my_tree[1])
                atan = math.atan2(delta[1], delta[0])
                atans.append(atan)
        res = log_min(atans)
        print res

trees = []
for i in xrange(1000):
    trees.append((random.randint(-1000000, 1000000),
                  random.randint(-1000000, 1000000)))

with open(sys.argv[1]) as fp:
    T = int(fp.readline())
    for i in xrange(T):
        N = int(fp.readline())
        trees = []
        print "Case #%s:" % (i + 1)
        for _ in xrange(N):
            x, y = [int(x) for x in fp.readline().split()]
            trees.append((x, y))
        run(trees)
