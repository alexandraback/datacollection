from sys import stdin
import re

def yolo(t):
  best = 99999999999
  for x in xrange(1,101):
    tmp = sum(abs(x-y) for y in t)
    best = min(tmp,best)
  return best

Q = int(stdin.readline())
for qq in xrange(Q):
  N = int(stdin.readline())
  equiv = None
  reg = None
  strs = []
  arr = []
  for qqq in xrange(N):
    strs.append(stdin.readline())
  can_win = True
  for s in strs:
    if equiv is None:
      equiv = ""
      for c in s:
        if len(equiv) == 0 or c != equiv[-1]:
          equiv += c
      reg = re.compile("^"+reduce(lambda a,b:a+b, (x+"+" for x in equiv), "")+"$")
    else:
      can_win = can_win and reg.match(s)
    arr.append([])
    n,prev = 0,None
    for c in s:
      if c != prev:
        if prev:
          arr[-1].append(n)
        prev = c
        n = 1
      else:
        n += 1
  res = "Fegla Won"
  if can_win:
    res = str(sum(yolo(x) for x in zip(*arr)))
  print "Case #"+str(qq+1)+": "+res