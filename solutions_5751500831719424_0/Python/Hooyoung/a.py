#!/usr/bin/env python

import itertools

def solve(L):
  a,b = min(L),max(L)
  if a==b: return 0
  best = b*len(L)
  for x in xrange(a,b+1):
    s = 0
    for v in L:
      s += abs(v-x)
    if s < best:
      best = s
  return best
  

T = int(raw_input())

for t in xrange(T):
  N = int(raw_input())
  lens = []
  chars = None
  bad = False
  for i in xrange(N):
    s = raw_input().strip()
    last = None
    cs = []
    counts = []
    for c in s:
      if c == last:
        counts[-1] += 1
      else:
        cs.append(c)
        counts.append(1)
      last = c
    if chars is None:
      chars = cs
    elif chars != cs:
      bad = True
    lens.append(counts)
  if bad:
    print 'Case #%d: Fegla Won' % (t+1)
    continue
  out = 0
  for i in xrange(len(chars)):
    out += solve([l[i] for l in lens])
  print 'Case #%d:' %(t+1), out

