def solve(p):
  if sum(p) == 0:
    return []
  m1 = m2 = -1
  large1 = large2 = 0
  for i in xrange(len(p)):
    if p[i] > large1:
      m2 = m1
      large2 = large1
      m1 = i
      large1 = p[i]
    elif p[i] > large2:
      m2 = i
      large2 = p[i]
  n = sum(p)
  #print "p is ", p, "nonzero is ", n
  if n % 2:
    p[m1] -= 1
    #print "Rem:", p
    return [chr(65 + m1)] + solve(p)
  p[m1] -= 1
  p[m2] -= 1
  #print "Rem:", p
  return [chr(65 + m1) + chr(65 + m2)] + solve(p)

T = int(raw_input())
for i in xrange(T):
  N = int(raw_input())
  p = [int(x) for x in raw_input().split()]
  ans = solve(p)
  print "Case #%d: %s" % (i+1, " ".join(ans))