import sys

tc = int(sys.stdin.readline())
for tmp_tc in xrange(tc):
  [ R, C, N ] = map(lambda x: int(x), sys.stdin.readline().split(' '))
  res = R*C + 10**10
  for i in xrange(1 << (R*C)):
    bits = 0
    ii = i
    while ii != 0:
      bits += ii % 2
      ii /= 2
    if bits != N: continue
    walls = 0
    for x in xrange(R-1):
      for y in xrange(C):
        tmp = 1 if (i & (1<<(x+R*y))) and int(i & (1<<(x+1+R*y))) else 0
        walls += tmp
    for y in xrange(C-1):
      for x in xrange(R):
        tmp = 1 if (i & (1<<(x+R*y))) and int(i & (1<<(x+R*(1+y)))) else 0
        walls += tmp
    res = min(walls, res)
  print "Case #%d: %d" % (tmp_tc + 1, res)
