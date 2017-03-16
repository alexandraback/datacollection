def read(parse):
  return [parse(_) for _ in raw_input().split()]

def clock(v1, v2):
  x1, y1 = v1
  x2, y2 = v2
  return x1 * y2 - x2 * y1 < 0

def solve():
  N = input()
  X, Y = zip(*[read(int) for i in range(N)])
  def vec(a, b):
    return (X[b] - X[a], Y[b] - Y[a])

  ans = [N - 1] * N
  for i in range(N):
    for j in range(N):
      if i == j:
        continue
      bad = sum(1 for k in range(N) if clock(vec(i, j), vec(i, k)))
      for x in [i, j]:
        ans[x] = min(ans[x], bad)
  return ans

T = input()
for t in range(1, T + 1):
  print 'Case #%d:' % t
  for x in solve():
    print x
