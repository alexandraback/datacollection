#!/usr/bin/python


def enc(st):
  return ''.join([chr(x) for x in st])



Mem = {}

def simu(B, N):
  if N <= len(B):
    return N;
  M = len(B)
  N -= M
  st = list(B)
  cs = M
  while N > 0:
    est = enc(st)
    try:
      last = Mem[est]
      df = cs - last
      if df > 0:
        N = (N - 1)%df + 1
    except KeyError:
      Mem[est] = cs
    tm = min(st)
    for i in xrange(M):
      st[i] -= tm
      if st[i] == 0:
        N -= 1
        cs += 1
        if N == 0:
          return i + 1
        st[i] = B[i]
  return -1


import sys

T = int(sys.stdin.readline().strip())
for t in xrange(1, T + 1):
  b, n = [int(x) for x in sys.stdin.readline().split()]
  B = [int(x) for x in sys.stdin.readline().split()]
  Mem.clear()
  print 'Case #%d: %d' % (t, simu(B, n))
