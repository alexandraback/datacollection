import sys
import math

def run(t):
  N = int(raw_input())
  ms = map(int, raw_input().split())

  m1 = 0;
  prev = 0
  rate = 0
  for m in ms:
    if m < prev:
      m1 = m1 + prev - m
      rate = max(rate, prev - m)
    prev = m

  m2 = 0
  prev = 0
  for m in ms[:-1]:
    m2 = m2 + min(rate, m)

  print('Case #{}: {} {}'.format(t, m1, m2))

T = int(raw_input())
for t in xrange(1, T + 1):
  run(t)
