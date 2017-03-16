# fname = "A-small-attempt0.in"
fname = "A-large.in"
# fname = "test.in"
import numpy as np

def solve(M):
  m1 = np.array(M[:-1])
  m2 = np.array(M[1:])
  diff = m1 - m2
  res1 = sum(diff[diff > 0])

  mx = max(diff)
  res2 = sum(np.minimum(mx, m1))
  return '%s %s' % (res1, res2)

def main():
  with open(fname) as f:
    for i in xrange(int(f.readline())):
      N = int(f.readline())
      M = map(int, f.readline().split())
      print 'Case #%s: %s' % (i + 1, solve(M))

main()