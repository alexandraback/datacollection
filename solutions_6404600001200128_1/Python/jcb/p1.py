#!/usr/bin/python
# -*- coding: UTF-8 -*-

import sys

def solve(f):
  #parse
  num = int(f.readline().strip())
  n = [int(x) for x in f.readline().strip().split()]  
  #print n
  if num  != len(n):
    print "Wrong number of levels on line:", line
    sys.exit(0)

  eaten = 0
  max_eaten = 0
  for i in xrange(len(n) - 1):
    diff = n[i] - n[i+1]
    if diff <= 0:
      continue
    if diff > max_eaten:
      max_eaten = diff
    eaten += diff

  eaten_2 = 0
  for d in n[:-1]:
    eaten_2 += min(d, max_eaten)

  return str(eaten) + " " + str(eaten_2)

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

