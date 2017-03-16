import sys
import math
import itertools as it
import operator as op
import fractions as fr


alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
def has_maj_any(P):
  s = int(math.ceil(float(sum(P)) / 2 + .0001))
  l = filter(lambda p: p >= s, P)
  return len(l) > 0

t = int(sys.stdin.readline())
for tc in range(1,t+1):
  n = int(sys.stdin.readline().strip())
  P = map(int, sys.stdin.readline().split())

  r = ''
  while sum(P):
    idx1 = idx2 = None
    
    _,idx1 = max(zip(P,range(n)), key = lambda e: e[0])
    P[idx1] -= 1

    _,idx2 = max(zip(P,range(n)), key = lambda e: e[0])
    P[idx2] -= 1
    if has_maj_any(P):
      P[idx2] += 1
      idx2 = None

    assert(not has_maj_any(P))

    r += alphabet[idx1]
    if idx2 is not None: r += alphabet[idx2]
    r += ' '


  print('Case #{}: {}'.format(tc, r))
