import sys

class angle:
  def __init__(self, x, y):
    self.x = x
    self.y = y

  def __lt__(self, o):
    return self.y * o.x < self.x * o.y

  def __ge__(self, o):
    return self.y * o.x >= self.x * o.y

  def __str__(self):
    return '[{0} {1}]'.format(self.x, self.y)

  def __repr__(self):
    return '[{0} {1}]'.format(self.x, self.y)

def make_angle(x, y):
  if x > 0 and y >= 0:
    return (0, angle(x, y))
  elif y > 0 and x <= 0:
    return (1, angle(y, -x))
  elif x < 0 and y <= 0:
    return (2, angle(-x, -y))
  else:
    return (3, angle(-y, x))

def bisect_left(pt, ar):
  l = 0
  r = len(ar)
  while l != r:
    m = (l+r)//2
    if ar[m] >= pt:
      r = m
    else:
      l = m+1
  return l

def solve0(pointsq):
  for i in range(4):
    pointsq[i].sort()
  qsizes = [len(pp) for pp in pointsq]
  res = sum(qsizes)
  for i in range(4):
    cut = qsizes[i] + qsizes[(i+1)%4]
    j = (i + 2) % 4
    for pt in pointsq[i]:
      cut -= 1
      try:
        r = bisect_left(pt, pointsq[j])
      except:
        print (pt)
        print (pointsq[j])
        print (len(pointsq[j]))
        raise 'aaa'
      res = min(res, cut + r)
  return res

def solve(p):
  res = []
  for i in range(len(p)):
    pointsq = [[] for a in range(4)]
    xi, yi = p[i]
    for j in range(len(p)):
      if i == j: continue
      xj, yj = p[j]
      q, pt = make_angle(xj-xi, yj-yi)
      pointsq[q].append(pt)
    res.append(solve0(pointsq))
  return res

T = int(input())

for iCase in range(T):
  n = int(input())
  p = []
  for i in range(n):
    p.append([int(x) for x in input().split(' ')])
  print('Case #{0}:'.format(iCase+1))
  res = solve(p)
  for i in res:
    print(i)

