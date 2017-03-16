for cas in xrange(1, input()+1):
  print "Case #%d:" % cas,
  B, N = map(int, raw_input().split())
  M = map(int, raw_input().split())
  # Binary search on minutes.
  def tot(minutes):
    t = 0
    for m in M:
      t += 1 + minutes//m
    return t
  lo = 0
  hi = 10**100
  while lo < hi:
    mid = (lo+hi)//2
    if tot(mid) >= N:
      hi = mid
    else:
      lo = mid+1
  assert lo == hi
  mins = lo
  offset = tot(mins) - N
  for i in reversed(xrange(B)):
    if mins % M[i] == 0:
      if offset:
        offset -= 1
      else:
        ans = i+1
        break
  assert 0 < ans <= N
  print ans
