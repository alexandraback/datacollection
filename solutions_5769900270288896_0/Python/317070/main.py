import glob, pprint, pickle, os, time, sys
from copy import copy
from numpy import array, sin, cos, zeros
import itertools
import math



def solve(t,r,c):
    tb = t
    #greedy?
    #app = zeros(r,c)
    r,c = min(r,c), max(r,c)
    if r==1:
        if c%2==1:
            t -= (c-c/2) #up for free
            return max(2*t,0),
        else:
            t -= c/2
            t -= 1
            return max(1+2*t,0),

    """route A"""
    # start with corners
    # first r*c/2 up for free
    t -= (r*c - r*c/2)
    # then r/2 down *2 and c/2 down *2 3 walls
    if t<=0:
        route_a = 0
    else:
        if r%2==0 or c%2==0:
            corners = 2
        else:
            corners = 0
        route_a = min(corners,t)*2
        t-= corners
        if t>0:
            if r%2==0 or c%2==0:
                edges = r+c
            else:
                edges = (r/2)*2 + (c/2)*2
            edges -= corners*2
            route_a += min(edges, t)*3
            print edges
            t -= edges
            if t>0:
                route_a += t*4

    """route B"""

    # first r*c/2 down for free
    t = tb
    t -= (r*c/2)
    if t<=0:
        route_b = 0
    else:
        # then r/2 up *2 and c/2 up *2 3 walls
        if r%2==0 or c%2==0:
            corners = 2
        elif r%2==1 and c%2==1:
            corners = 4
        else:
            corners = 0
        route_b = min(corners,t)*2
        t-= corners
        if t>0:
            if r%2==0 or c%2==0:
                edges = r+c
            else:
                edges = (r - r/2)*2 + (c - c/2)*2

            edges -= corners*2

            route_b += min(edges, t)*3

            t -= edges
            if t>0:
                route_b += t*4


    return min(route_a, route_b),


output = ""
TIC = time.time()
with open(sys.argv[1] if len(sys.argv) > 1 else "default.in") as f:
    def read_ints():
        return [int(x) for x in f.readline().strip().split(' ')]
    def read_frac():
        return [int(x) for x in f.readline().strip().split('/')]
    def read_strs():
        return [x for x in f.readline().strip().split(' ')]
    def read_floats():
        return [float(x) for x in f.readline().strip().split(' ')]

    (numquestions,) = read_ints()
    for questionindex in xrange(numquestions):

        ### calculate answer ###
        r,c,t = read_ints()
        answer = solve(t,r,c)

        ### output ###
        answer_str = "Case #{}: {}".format(questionindex+1, " ".join([str(a) for a in answer]))
        output += answer_str + '\n'
        print answer_str

ofile = open('output', 'w').write(output)
TOC = time.time()