#!/usr/bin/python
# -*- coding: UTF-8 -*-

import sys
from math import atan2, cos, sin, tan, degrees, pi


def solve(f):
  #parse
  num_points = int(f.readline())
  p = []
  for i in xrange(num_points):
    p.append([int(x) for x in f.readline().strip().split()] + [num_points,])
  #print levels
  if num_points != len(p):
    print "Wrong number of points on line:", line
    sys.exit(0)

  #print p

  for i in xrange(num_points):
    for j in xrange(i + 1, num_points):
      #print i, j, p[i], p[j]
      xs = [(p[i][1] - p[j][1], p[j][0] - p[i][0]), (p[j][0] - p[i][0],  p[j][1] - p[i][1]), (p[j][1] - p[i][1], p[j][0] - p[i][0]), (p[i][0] - p[j][0],  p[j][1] - p[i][1])]
      for x in xs:
        #print x
        p2 = []
        for k in xrange(num_points):
          p2.append([k, p[k][0] * x[0] + p[k][1] * x[1], 0])
        p2.sort(key = lambda x: x[1])
        #print p2
        #print [x[0] for x in p2]
        r = 0
        p2[0][2] = 0
        for k in xrange(1, num_points):
          if p2[k][1] == p2[k-1][1]:
            p2[k][2] = p2[k-1][2]
          else:
            p2[k][2] = k
        r = p2[-1][2]

        #print r
        #print [(x[0], x[2]) for x in p2]
        for k in xrange(num_points):
          s = min(p2[k][2], r - p2[k][2])
          #print k, s
          if s < p[p2[k][0]][2]:
            p[p2[k][0]][2] = s
        #print [(x[0], x[1][2]) for x in enumerate(p)]
        #print " "

  return "\n" + "\n".join([str(x[2]) for x in p])


total = None
count = 0
f = sys.stdin
while f:
  if not total:
    total = int(f.readline().strip())
    continue
  elif count < total:
    count += 1
    print "Case #%d: %s" % (count, solve(f))
#    sys.exit(0)
  else:
    break

if count < total:
  print "Wrong number of test cases"
  sys.exit(0)

