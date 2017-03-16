def convex_hull(points):
  points = sorted(set(points))

  if len(points) <= 1:
      return points

  def cross(o, a, b):
      return (a[0] - o[0]) * (b[1] - o[1]) - (a[1] - o[1]) * (b[0] - o[0])

  # Build lower hull 
  lower = []
  for p in points:
      while len(lower) >= 2 and cross(lower[-2], lower[-1], p) <= 0:
          lower.pop()
      lower.append(p)

  # Build upper hull
  upper = []
  for p in reversed(points):
      while len(upper) >= 2 and cross(upper[-2], upper[-1], p) <= 0:
          upper.pop()
      upper.append(p)

  return lower[:-1] + upper[:-1]

def process():
  pts = int(input())
  ptsArr = []
  for i in xrange(pts):
    pt = map(int, raw_input().split())
    ptsArr.append(pt)
  pts = [tuple(i) for i in ptsArr]

  mapping = dict()
  level = 0
  while True:
    convexHullSet = convex_hull(pts)
    if convexHullSet == sorted(set(pts)):
      break
    newPts = []
    for item in pts:
      if item not in convexHullSet:
        newPts.append(item)
      else:
        mapping[tuple(item)] = level
    pts = [item for item in newPts]
    level += 1

  resArr = []
  for item in ptsArr:
    if tuple(item) in mapping.keys():
      resArr.append(mapping[tuple(item)])
    else:
      resArr.append(level)
  return resArr

def main():
  T = int(raw_input())
  tc = T
  while tc > 0:
    tc -= 1
    ans = process()
    print u"Case #{}:".format(T-tc)
    for item in ans:
      print item

if __name__ == "__main__":
  main()
