#!/usr/bin/env python

for nnn in xrange(1, int(raw_input())+1):
  print "Case #%d:" % (nnn),
  B, N = [int(x) for x in raw_input().split()]
  M = [int(x) for x in raw_input().split()]
  if N <= B:
    print N
    continue
  N -= B

  max_period = 1
  for m in M:
    max_period *= m
  q = []
  M_copy = [x for x in M]
  p = 0
  while p < max_period:
    leftover = min(M_copy)
    p += leftover
    for i in xrange(len(M)):
      M_copy[i] -= leftover
      if M_copy[i] == 0:
        q.append(i)
        M_copy[i] = M[i]

  print q[(N-1)%len(q)] + 1

