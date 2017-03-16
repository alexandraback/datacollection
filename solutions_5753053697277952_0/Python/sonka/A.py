#!/usr/bin/python
import sys
import numpy as np

inputs = [line.strip() for line in sys.stdin]

alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
T = int(inputs[0])

def find2max(P):
  a1 = -1
  a2 = -1
  v1 = -1
  v2 = -1
  for i in xrange(len(P)):
    if P[i] > v1:
      v2 = v1
      a2 = a1
      v1 = P[i]
      a1 = i
    elif P[i] > v2:
      v2 = P[i]
      a2 = i
  return a1, a2

for t in xrange(T):
  N = int(inputs[2*t+1])
  out = []
  P = [int(x) for x in inputs[2*t+2].split()]
  n = sum(P)
  while n > 0:
    arg1, arg2 = find2max(P)
    if n != 3 and (P[arg1] == P[arg2] or P[arg2] > (n-2)/2):
      P[arg1] -= 1
      n -= 1
      if P[arg2] > 0:
        P[arg2] -= 1
        n -= 1
        out.append("" + alphabet[arg1] + alphabet[arg2])
      else:
        out.append("" + alphabet[arg1])
    elif n != 3 and P[arg1] >= 2:
      P[arg1] -= 2
      n -= 2
      out.append("" + alphabet[arg1] + alphabet[arg1])
    else:
      P[arg1] -= 1
      n -= 1
      out.append("" + alphabet[arg1])

  print("Case #{0}: {1}".format(t+1, " ".join(out)))
