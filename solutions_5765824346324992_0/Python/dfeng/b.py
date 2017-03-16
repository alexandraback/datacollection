from __future__ import division
import math
fname = "B-small-attempt3.in"
# fname = "B-large.in"
# fname = "test.in"
# import numpy as np

def solve(B, N, M):
  # print N, B
  # nm = np.array(M)
  # prods = np.prod(M)
  x = (N - B) / sum([1 / i for i in M])
  # print x
  # tests = []
  for j in xrange(len(M), 0, -1):
    # print "j", j
    m = M[j-1]
    # print "m", m
    test = math.floor(x / m) * m
    minus = sum([test % M[i] == 0 for i in xrange(len(M))][j:])
    # print "minus", minus
    # print "test", test
    # minus = tests.count(test)
    # print "min", minus
    # tests.append(test)
    # now i need to check how many other tests are there
    missed = sum([math.floor(test / i) for i in M]) + B - minus - N
    # print "missed by", missed
    if missed == 0:
      return j
    while missed < 0:
      test += m
      minus = sum([test % M[i] == 0 for i in xrange(len(M))][j:])
      missed = sum([math.floor(test / i) for i in M]) + B - minus - N
      # print "second missed by", missed
    if missed == 0:
      return j

  # for j in xrange(len(M), 0, -1):
  #   # print "j", j
  #   m = M[j-1]
  #   # print "m", m
  #   test = math.floor(x / m) * m
  #   minus = sum([test % M[i] == 0 for i in xrange(len(M))][j:])
  #   # print "minus", minus
  #   # print "test", test
  #   # minus = tests.count(test)
  #   # print "min", minus
  #   # tests.append(test)
  #   # now i need to check how many other tests are there
  #   missed = sum([math.floor(test / i) for i in M]) + B - minus - N
  #   # print "missed by", missed
  #   if missed == 0:
  #     return j
  #   while missed < 0:
  #     test += 1
  #     minus = sum([test % M[i] == 0 for i in xrange(len(M))][j:])
  #     missed = sum([math.floor(test / i) for i in M]) + B - minus - N
  #     # print "second missed by", missed
  #   if missed == 0:
  #     return j

def main():
  with open(fname) as f:
    for i in xrange(int(f.readline())):
      B, N = map(int, f.readline().split())
      M = map(int, f.readline().split())
      print 'Case #%s: %s' % (i + 1, solve(B, N, M))

main()