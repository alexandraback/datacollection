import os
import sys
import StringIO
import itertools
from collections import defaultdict

inputs="""\
4
2
2 2
3
3 2 2
3
1 1 2
3
2 3 1
"""

inf = StringIO.StringIO(inputs) if sys.stdin.isatty() else sys.stdin
#sys.setrecursionlimit(10000)

def valid(plan):
  plan = [p[1] for p in plan]
  s = sum(plan)
  return s == 0 or all(1.0*p/s <= 0.5 for p in plan)

def solve(P):
  sol = []
  PP = enumerate(P)
  PP = [pp for pp in PP if pp[1] > 0]
  while PP:
    #print "PP=", PP
    PP.sort(key=lambda pp: pp[1])
    plan = PP[:-2] + [(pp[0],pp[1]-1) for pp in PP[-2:]]
    if valid(plan):
      sol.append(PP[-2:])
      PP = plan
    else:
      sol.append([PP[-1]])
      PP = PP[:-1] + [(PP[-1][0],PP[-1][1]-1)]
    PP = [pp for pp in PP if pp[1] > 0]
  return ' '.join([''.join(map(lambda y:chr(ord('A') + y), [x[0] for x in s])) for s in sol])

def nextVal():
  return inf.readline().rstrip('\n')

T = int(nextVal())
for t in range(1,T+1):
  N = int(nextVal())
  P = map(int, nextVal().split())
  print "Case #%d: %s"%(t, solve(P),)
