import sys

def comb(result, curr, rest, n):
  if n == 0:
    result.append(curr)
  else:
    for i in range(len(rest)):
      comb(result, curr + [True], rest[i+1:], n-1)
      curr.append(False)

def run(t):
  R, C, N = map(int, raw_input().split())
  ns = []
  comb(ns, [], range(R*C), N)
  min_unhappiness = R*C*4
  for n in ns:
    n.extend([False] * (R*C - len(n)))
    unhappiness = 0
    for i in range(R*C):
      if n[i]:
        if C > 1 and i % C > 0 and n[i-1]:
          unhappiness += 1
        if C > 1 and i % C < C-1 and n[i+1]:
          unhappiness += 1
        if i >= C and n[i-C]:
          unhappiness += 1
        if i < R*C - C and n[i+C]:
          unhappiness += 1
    min_unhappiness = min(min_unhappiness, unhappiness / 2)
    if min_unhappiness == 0:
      break

  print('Case #{}: {}'.format(t, min_unhappiness))

T = int(raw_input())
for t in xrange(1, T + 1):
  run(t)
