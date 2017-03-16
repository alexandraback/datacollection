import sys

def solve(l):
  res1 = 0
  rate = 0
  for i in range(len(l)-1):
    res1 += max(0, l[i] - l[i+1])
    rate = max(rate, l[i] - l[i+1])

  res2 = 0
  for i in range(len(l)-1):
    res2 += min(rate, l[i])
  return '{0} {1}'.format(res1, res2)

T = int(input())

for iCase in range(T):
  n = int(input())
  l = [int(x) for x in input().split(' ')]
  print('Case #{0}: {1}'.format(iCase+1, solve(l)))
