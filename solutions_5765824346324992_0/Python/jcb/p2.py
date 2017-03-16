#!/usr/bin/python
# -*- coding: UTF-8 -*-

import sys
import fractions

def lcm(x, y):
  return (x * y) / fractions.gcd(x, y)

def solve(f):
  #parse
  num_barbers, n = tuple([int(x) for x in f.readline().strip().split(" ")])
  barbers = [[i + 1, int(x), 0] for i, x in enumerate(f.readline().strip().split(" "))]
  #print num_barbers, n, barbers
  if num_barbers != len(barbers):
    print "Wrong number of barbers on line:", line
    sys.exit(0)

  l = reduce(lcm, [x[1] for x in barbers])
  #print l

  cycle = 0
  for i in xrange(num_barbers):
    cycle += l / barbers[i][1]

  left = n % cycle

  if left == 0:
    left = cycle

  while left > 0:
    smallest = None
    #print barbers
    for i in xrange(num_barbers):

      if barbers[i][2] == 0:
        barbers[i][2] = barbers[i][1]
        left -= 1
        if left == 0:
          return barbers[i][0]

      if not smallest or barbers[i][2] < smallest:
        smallest = barbers[i][2]
      
    #print barbers
    #print smallest
    for i in xrange(num_barbers):
      barbers[i][2] -= smallest
    #print barbers
  


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
  else:
    break

if count < total:
  print "Wrong number of test cases"
  sys.exit(0)

