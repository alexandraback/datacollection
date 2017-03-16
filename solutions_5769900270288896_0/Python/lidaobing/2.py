import sys

def reverse(i):
  res = 0
  while i > 0:
    res = res * 10 + (i % 10)
    i = i // 10
  return res

def fill():
  res = [-1] * (10**6+5)
  res[1] = 1
  count = {}
  count[1] = [1]
  for i in range(1, 10**6):
    t = count[i]
    count[i+1] = []
    for x in t:
      if x+1 > 10**6:
        continue
      if res[x+1] == -1:
        #print x+1, res[x+1]
        res[x+1] = i+1
        count[i+1].append(x+1)
        #print x+1, res[x+1], count[2]
      x2 = reverse(x)
      if x2 < 1 or x2 > 1000000:
        continue
      if res[x2] == -1:
        res[x2] = i+1
        count[i+1].append(x2)
    #print count[i+1]
  return res

def enum2(n1, n2):
  for i in range(2**n1):
    t = 0
    i2 = i
    while i2 > 0:
      t += i2 % 2
      i2 = i2 // 2
    if t != n2:
      continue
    yield i

def foo2(r, c, x):
  x1 = x
  a = [[0] * (c+1) for i in range(r+1)]
  i1 = 0
  i2 = 0
  while x > 0:
    t = x % 2
    a[i1][i2] = t
    x = x // 2
    i2 += 1
    if i2 == c:
      i2 = 0
      i1 += 1
  res = 0
  for i in range(r):
    for j in range(c):
      if a[i][j] == 0:
        continue
      if a[i][j+1] == 1:
        res += 1
      if a[i+1][j] == 1:
        res += 1
  return res

def foo(ifile):
  r,c,n = [int(x) for x in ifile.readline().split()]
  res = 10000
  for x in enum2(r*c, n):
    res = min(res, foo2(r,c,x))
  return res



def main():
  n = int(sys.stdin.readline().strip())
  for i in range(n):
    print 'Case #%d: %s' % (i+1, foo(sys.stdin))

main()
