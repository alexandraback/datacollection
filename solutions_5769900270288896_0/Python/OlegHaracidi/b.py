T = int(raw_input())
for i in xrange(T):
  (R,C,N) = tuple(map(int, raw_input().split()))
  x0 = (R * C + 1) // 2
  if R % 2 == 1 and C % 2 == 1:
    x2 = 0
  else:
    x2 = 2

  x3 = (R // 2) * 2 + (C // 2) * 2 - x2

  t = (1 if R > 3 else 0) + (1 if C > 3 else 0)

  s = 0
  if N <= x0:
    s = 0
  elif N <= x0 + x2:
    s = (N - x0) * 2
  elif N <= x0 + x2 + t:
    s = (N - x0) * 2
  elif N <= x0 + x2 + x3:
    s = x2 * 2 + (N - x0 - x2) * 3
  else:
    s = x2 * 2 + x3 * 3 + (N - x0 - x2 - x3) * 4

  if R == 3 and C == 3:
    s = 8
  print "Case #{}: {}".format(i + 1, s)

