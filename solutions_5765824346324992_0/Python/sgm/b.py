# coding: utf-8

import sys
import fractions

def lcm(a, b):
  g = fractions.gcd(a, b)
  return a * b / g

def case(t):
  B, N = map(int, sys.stdin.readline().split())
  M = map(int, sys.stdin.readline().split())
  l = 1
  for m in M:
    l = lcm(l, m)
  sgm = [None]
  for i in xrange(l):
    sgm.append([])
  S = list(M)
  for i in xrange(B):
    S[i] = (i + 1, S[i])
  S.sort()
  for j in xrange(1, l + 1):
    for (i, m) in S:
      if j % m == 0:
        sgm[j].append(i)
  k = []
  for i in xrange(l, 0, -1):
    k += sgm[i]
  n = N % len(k)
  print "Case #%d: %d" % (t, k[n - 1])

T = int(sys.stdin.readline())
for t in xrange(1, T + 1):
  case(t)
