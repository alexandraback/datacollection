br = open('A-large.in')
pw = open('a.out', 'w')
oo = 1 << 20

f = lambda: br.readline()
t = int(f())

def solve(a, n): 
  r, j, bs = 0, 0, a[0][0]
  for i in range(1, len(a[0])):
    if bs[j] != a[0][i]: 
      bs += a[0][i]
      j += 1
  id = [0 for t in range(n)]
  for i in range(len(bs)):
    cn = [0 for t in range(n)]
    for j in range(n):
      while id[j] < len(a[j]) and a[j][id[j]] == bs[i]:
        cn[j] += 1
        id[j] += 1
      if cn[j] == 0: return -1
    wn = oo
    for j in range(max(cn) + 1):
      dif_sum = 0
      for k in cn:
        dif_sum += abs(k - j)
      wn = min(wn, dif_sum)
    r += wn
  return [r, -1][any(el < len(a[j]) for j, el in enumerate(id))]

for i in range(t):
  n = int(f())
  a = [f().strip() for j in range(n)]

  s = solve(a, n)
  print 'Case #%d: %s' % (i + 1, ['Fegla Won', s][s >= 0])
  pw.write('Case #%d: %s\n' % (i + 1, ['Fegla Won', s][s >= 0]))
