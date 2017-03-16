import sys

def are_cutting(M, t):
  n = 0
  for m in M:
    n += (t + m-1) // m
  return n

def can_cut(x, M, t):
  return are_cutting(M, t) >= x

def solve(N, M, B):
  L = 0
  
  R = N * min(M)
  while L != R:
    mid = (L+R)//2
    if can_cut(N, M, mid):
      R = mid
    else:
      L = mid+1
  t = L-1
  before = are_cutting(M, t)
  after = are_cutting(M, t+1)
  #print('{0} {1} {2} {3} {4}'.format(M, N, L, before, after))
  taken_at_t = N-before

  for i, m in enumerate(M):
    if t % m == 0:
      if taken_at_t > 1:
        taken_at_t -= 1
      else:
        return i+1
  assert False  

T = int(input())

for iCase in range(T):
  B, N = [int(x) for x in input().split(' ')]
  M = [int(x) for x in input().split(' ')]
  print('Case #{0}: {1}'.format(iCase+1, solve(N, M, B)))
