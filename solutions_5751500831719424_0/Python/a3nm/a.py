#!/usr/bin/python

import sys

T = int(sys.stdin.readline().strip())

def rle(x):
  last = None
  nocc = 0
  res = []
  y = list(x)
  y.append(None)
  for i in range(len(y)):
    if y[i] == last:
      nocc += 1
    else:
      if last:
        res.append((last, nocc))
      last = y[i]
      nocc = 1
  return res

for testcase in range(T):
  N = int(sys.stdin.readline().strip())
  s = []
  for j in range(N):
    s.append(sys.stdin.readline().rstrip())
  s = [rle(x) for x in s]
  labs = [[y[0] for y in x] for x in s]
  if len(set([''.join(x) for x in labs])) > 1:
    answer = "Fegla won"
  else:
    s = [[y[1] for y in x] for x in s]
    total = 0
    for i in range(len(s[0])):
      avg = int(round(float(sum(x[i] for x in s))/len(s)))
      total += sum(abs(x[i] - avg) for x in s)
    answer = total
  print ("Case #%d: %s" % (testcase+1, answer))

