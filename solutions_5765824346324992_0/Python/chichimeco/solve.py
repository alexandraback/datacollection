#!/Library/Frameworks/Python.framework/Versions/2.7/bin/python
from math import ceil

def solve(N,M,B):

  def f(t):
    return sum([ int(ceil(t/float(M[k]))) for k in xrange(B) ])

  lb = 0
  ub = N * max(M)

  assert lb < ub

  while ub-lb > 1:

    t = int((lb + ub)/2)
    v = f(t)
    if v >= N:
      ub = t
    else:
      lb = t

  assert lb < ub
  assert f(lb) < N 
  assert f(ub) >= N

  current = f(lb)

  for k in xrange(B):
    if lb % M[k] == 0:
      current += 1
      if current == N:
        return k+1

  assert False


if __name__ == '__main__':

  T = int(raw_input())

  for t in xrange(T):

    B,N = map(int, raw_input().strip().split(" "))
    M = list(map(int, raw_input().strip().split(" ")))

    print "Case #%d: %d" % (t+1, solve(N,M,B))

