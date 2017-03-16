# import sys
# sys.setrecursionlimit(100000)
# dynamic programming

# from __future__ import division
# import math
# import numpy as np
# import bisect
# import itertools
# import collections


from collections import Counter

fname = "A-large.in.txt"
# fname = "test.in"

def shrink(l):
  # print l
  if len(l) == 1:
    return l, 1, ""
  s0 = l[0]
  count = 0
  for i in range(len(l)):
    if l[i] == s0:
      count += 1
    else:
      return s0, count, l[i:]
  return s0, count, ""

def getmin(nums):
  if len(set(nums)) == 1:
    return 0
  cnts = Counter(nums)
  # print cnts
  minz = 10000
  for k in cnts.keys():
    tot = 0
    for j in cnts.keys():
      if j != k:
        tot += abs(j-k) * cnts[j]
    minz = min(tot, minz)
  # print minz
  return minz

def solve(L):
  cnt = 0
  while True:
    LL = []
    nums = []
    lets = []
    for l in L:
      let, num, st = shrink(l)
      LL.append(st)
      nums.append(num)
      lets.append(let)
    # print LL
    if len(set(lets)) != 1:
      return "Fegla Won"
    cnt += getmin(nums)
    if any(v == 0 for v in map(len, LL)):
      if all(v == 0 for v in map(len, LL)):
        return cnt
      else:
        return "Fegla Won"
    L = list(LL)

def main():
  with open(fname) as f:
    for i in xrange(int(f.readline())):
      L = []
      for j in xrange(int(f.readline())):
        L.append(f.readline().strip())
      print 'Case #%s: %s' % (i + 1, solve(L))
  
main()