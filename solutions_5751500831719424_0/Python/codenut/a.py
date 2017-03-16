br = open('a.in')
br = open('A-small-attempt1.in')
pw = open('a.out', 'w')
oo = 1 << 20

f = lambda: br.readline()
t = int(f())

def diff(s, t):
  if len(s) > len(t): s, t = t, s
  j, r = 0, 0
  n, m, d = len(s), len(t), s[0]
  for i in range(1, n):
    if s[i] != d[j]:
      d += s[i]
      j += 1
  a, b = 0, 0
  for i in range(len(d)):
    x, y = 0, 0
    while a < len(s) and s[a] == d[i]:
      x += 1
      a += 1
    while b < len(t) and t[b] == d[i]:
      y += 1
      b += 1
    if x == 0 or y == 0: return -1
    r += abs(x - y)
  return [-1, r][len(s) == a and len(t) == b]

def solve(a, n): 
  r = oo
  for i in range(n):
    s = 0
    for j in range(n):
      x = diff(a[i], a[j])
      if x == -1: return -1
      s += x
    r = min(r, s)
  return r

for i in range(t):
  n = int(f())
  a = [f().strip() for j in range(n)]

  s = solve(a, n)
  print 'Case #%d: %s' % (i + 1, ['Fegla Won', s][s >= 0])
  pw.write('Case #%d: %s\n' % (i + 1, ['Fegla Won', s][s >= 0]))
