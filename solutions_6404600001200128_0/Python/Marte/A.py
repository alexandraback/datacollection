for cas in xrange(1, input()+1):
  print "Case #%d:" % cas,
  N = input()
  m = map(int, raw_input().split())
  ans1 = 0
  prev = m[0]
  max_per_int = 0
  for curr in m[1:]:
    if prev > curr:
      ans1 += prev-curr
      max_per_int = max(max_per_int, prev-curr)
    prev = curr
  ans2 = 0
  for curr in m[:-1]:
    ans2 += min(curr, max_per_int)
  print ans1, ans2
