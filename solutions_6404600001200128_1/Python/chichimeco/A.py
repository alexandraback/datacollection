def solveAny(L,N):

    eaten = 0
    for i in xrange(1,N):
      eaten += max(0, L[i-1]-L[i])

    return eaten

def solveConstant(L,N):

    rate = 0
    for i in xrange(1,N):
      rate = max(rate, L[i-1]-L[i])

    eaten = 0
    for i in xrange(1,N):
      eaten += min(L[i-1], rate)

    return eaten



if __name__ == '__main__':

  T = int(raw_input())
  for t in xrange(T):

    N = int(raw_input())
    L = map(int, raw_input().strip().split())

    print "Case #%d: %d %d" % (t+1, solveAny(L,N), solveConstant(L,N))


