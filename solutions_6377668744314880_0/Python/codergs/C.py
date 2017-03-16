#! /opt/local/bin/python
#import numpy as np
#import heapq
from itertools import combinations
f = open("C-small-attempt0.in")
#f = open("B-large.in")
#f = open("exC.in")

T= int(f.readline().strip());




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
    for n in range(N):
        (x,y)=[int(pt) for pt in f.readline().strip().split()]
        pts+=[(x,y)]
    print "Case #"+str(t+1)+": "
    for pt in pts:
      ret_val=N
      for n in range(N):
          for cmb in combinations(range(N),n):
              #print cmb
              pts_cpy=pts[:]
              for i in cmb:
                  #print n,i,pts_cpy,pts[i]
                  pts_cpy.remove(pts[i])
              if pt in convex_hull(pts_cpy):
                  ret_val=n
                  print n
                  break
          if ret_val<N:
              break


