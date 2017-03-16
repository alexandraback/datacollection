#!/usr/bin/python

import sys

def major(P):
  s = sum(P)
  for i in xrange(len(P)):
    if (2*P[i]) > s:
      return i

  return None

def check(P):
  s = sum(P)
  for i in P:
    assert(2*i <= s)

def case(P):
  rc = ""
  m = max(P)
  while m > 0:
    check(P)
    #print P
    i = P.index(m)
    rc += chr(65+i)
    P[i] -= 1

    j = major(P)
    if j is not None:
      rc += chr(65+j)
      P[j] -= 1
    else:
      m = max(P)
      j = P.index(m)
      P[j] -= 1
      if major(P) is None:
        rc += chr(65+j)
      else:
        P[j] += 1

    rc += ' '
    m = max(P)

  return rc.strip()


f = open(sys.argv[1])
T = int(f.readline())
for i in xrange(T):
  N=int(f.readline())
  P=map(int, f.readline().split())
  print "Case #%d: %s"%(i+1, case(P))

