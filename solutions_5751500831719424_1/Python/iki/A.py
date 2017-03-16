""" Solution to Google Code Jam 2014 Round 1B Problem A

Problem: https://code.google.com/codejam/contest/2994486/dashboard#s=p0

>>> test(
...   testlabel='sample via parse()',
...   testinput='''5
... 2
... mmaw
... maw
... 2
... gcj
... cj
... 3
... aaabbb
... ab
... aabb
... 2
... abc
... abc
... 3
... aabc
... abbc
... abcc
... ''')  #doctest: +NORMALIZE_WHITESPACE
Case #1: 1
Case #2: Fegla Won
Case #3: 4
Case #4: 0
Case #5: 3
"""

import sys, os.path
sys.path.insert(0, os.path.abspath('../.lib'));

from codejam import *

NONE = 'Fegla Won'


def median(l):
  s = sorted(l)
  n = len(s)
  if n % 2:
    return s[n/2]
  else:
    return (s[n/2] + s[n/2-1]) / 2


def d(C):
  return ' '.join('-'.join(map(str, c)) for c in C)

def d2(C):
  return ' '.join('-'.join(map(str, c)) for c in C if len(set(c)) > 1)


def solve(N, S):
  if N < 2:
    return 0

  A = []
  C = []
  a = None
  i = -1

  for c in S[0]:
    if c == a:
      C[i][0] += 1
    else:
      a = c
      A.append(c)
      i += 1
      C.append([1])

  I = i  # len(A) - 1

  A = ''.join(A)

  if log.debug: log.debug([N, S[0], I, A, d(C)])

  for s in xrange(1, N):
    a = None
    i = -1
    for c in S[s]:
      if c == a:
        C[i][s] += 1

      elif i >= I or c != A[i+1]:
        if log.debug: log.debug([s, S[s], i+1, c, A[min(i+1, I)]])
        return NONE

      else:
        a = c
        i += 1
        C[i].append(1)

    if i != I:
      if log.debug: log.debug([s, S[s], i, c, A[I]])
      return NONE

    if log.debug: log.debug([s, S[s], d2(C)])

  R = 0
  for X in C:
    if len(set(X)) > 1:
      M = median(X)
      for c in X:
        R += abs(M - c)

  return R

def parse(fi):
  N = int(fi.next().strip())
  return N, [fi.next().strip() for n in xrange(N)]

def format(r):
  return r

if __name__ == '__main__':
    main(solve, parse, format)
