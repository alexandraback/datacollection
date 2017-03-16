def getInput():
  return raw_input('').split()

def getIntInput():
  return [int(x) for x in getInput()]

def getcnt(total, one):
  return total / one

def available(total, one):
  return total % one == 0

def solve():
  n, m = getIntInput()
  b = getIntInput()
  lt, rt = 0, 10 ** 20
  while lt < rt:
    md = (lt + rt) >> 1

    done = sum(getcnt(md, e) for e in b)
    if done + n < m:
      lt = md + 1
    else:
      rt = md
  # print rt
  done = sum(getcnt(rt, e) for e in b)
  ok = sum(available(rt, e) for e in b)
  ing = n - ok
  need = m - done - ing
  for i in xrange(n):
    if available(rt, b[i]):
      need -= 1
      if not need:
        return i + 1

T = getIntInput()[0]
for tcase in xrange(1, T + 1):
  print 'Case #%d: %d' % (tcase, solve())
  