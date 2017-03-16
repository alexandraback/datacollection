def readint(): return int(raw_input())
def readlist(f): return map(f, raw_input().split())

from fractions import gcd

def lcm(a, b):
  return a*b/gcd(a, b)

def solve():
  B, N = readlist(int)
  M = readlist(int)

#  P = reduce(lcm, M)
  times = [0]*B
  l = list(range(B))
  time = 0
  while True:
    for i in range(B):
      # One barber is busy
      if time - times[i] < M[i]: break
    else:
      # All are free
      break
    for i in range(B):
      # Find a free barber
      if time - times[i] >= M[i]: break
    else:
      time += 1
      continue
    l.append(i)
    times[i] = time
  return l[(N-1)%len(l)]+1

T = readint()
for t in range(T):
  print 'Case #{}: {}'.format(t+1, solve())
