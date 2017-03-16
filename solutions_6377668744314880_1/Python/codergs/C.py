#! /opt/local/bin/python
#import numpy as np
#import heapq
from itertools import combinations
#f = open("C-small-attempt0.in")
f = open("C-large.in")
#f = open("exC.in")

T= int(f.readline().strip());



#I know this is wrong :)
def convex_hull(points):

    points = sorted(set(points))

    if len(points) <= 1:
        return points

    def cross(o, a, b):
        return (a[0] - o[0]) * (b[1] - o[1]) - (a[1] - o[1]) * (b[0] - o[0])

    lower = []
    for p in points:
        while len(lower) >= 2 and cross(lower[-2], lower[-1], p) < 0:
            lower.pop()
        lower.append(p)

    upper = []
    for p in reversed(points):
        while len(upper) >= 2 and cross(upper[-2], upper[-1], p) < 0:
            upper.pop()
        upper.append(p)

    return lower[:-1] + upper[:-1]


# Example: convex hull of a 10-by-10 grid.
#assert convex_hull([(i/10, i%10) for i in range(100)]) == [(0, 0), (9, 0), (9, 9), (0, 9)]

for t in range(T):
    N = int(f.readline().strip())
    pts=[]
    G={}
    for n in range(N):
        (x,y)=[int(pt) for pt in f.readline().strip().split()]
        pts+=[(x,y)]
        G[(x,y)]=n
    print "Case #"+str(t+1)+": "

    Num_trees=[N+1]*N;
    pts_cpy=pts[:]
    itera =0
    while(max(Num_trees)>N) or len(pts_cpy)>0:
        #pick out one tree at a time and upate Num_trees
        cvx=convex_hull(pts_cpy)
        #print cvx, pts_cpy
        for i in cvx:
            Num_trees[G[i]]=min(Num_trees[G[i]],itera)
            if i in pts_cpy:
                pts_cpy.remove(i)
            itera+=1
    for i in Num_trees:
        print i
