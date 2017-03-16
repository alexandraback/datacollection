def hull(pts):
  # Based on
  # http://en.wikibooks.org/wiki/Algorithm_Implementation/Geometry/Convex_hull/Monotone_chain#Python
  pts = sorted(pts)
  if len(pts) <= 1:
    return pts

  def cross(o, a, b):
    return (a[0] - o[0]) * (b[1] - o[1]) - (a[1] - o[1]) * (b[0] - o[0])

  lower = []
  for p in pts:
    while len(lower) >= 2 and cross(lower[-2], lower[-1], p) < 0:
      lower.pop()
    lower.append(p)
      
  upper = []
  for p in reversed(pts):
    while len(upper) >= 2 and cross(upper[-2], upper[-1], p) < 0:
      upper.pop()
    upper.append(p)
   
  return lower[:-1] + upper[:-1]


for cas in xrange(1, input()+1):
  print "Case #%d:" % cas
  N = input()
  points = []
  for _ in xrange(N):
    points.append(tuple(map(int, raw_input().split())))
  for i in xrange(N):
    ans = N
    for j in xrange(1 << N):
      if not (j & (1 << i)):
        continue
      new_points = []
      for k in xrange(N):
        if j & (1 << k):
          new_points.append(points[k])
      if points[i] in hull(new_points):
        ans = min(ans, N-len(new_points))
    print ans
