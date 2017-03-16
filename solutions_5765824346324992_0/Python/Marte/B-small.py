for cas in xrange(1, input()+1):
  print "Case #%d:" % cas,
  B, N = map(int, raw_input().split())
  M = map(int, raw_input().split())
  interval = reduce(lambda x, y: x*y, M)
  arr = []
  for n, m in enumerate(M):
    arr.extend(map(lambda x: (x*m, n), range(interval//m)))
  arr.sort()
  print arr[(N-1)%len(arr)][1]+1
