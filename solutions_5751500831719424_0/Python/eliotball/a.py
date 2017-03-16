import math

def acc(string):
  res = [[" ", 0]]
  for s in string:
    if s == res[-1][0]:
      res[-1][1] += 1
    else:
      res += [[s, 1]]
  return res

def solve():
  raw_input()
  a = acc(raw_input())
  b = acc(raw_input())
  count = 0
  if len(a) != len(b):
    return "Fegla Won"
  for i in range(len(a)):
    if a[i][0] != b[i][0]:
      return "Fegla Won"
    else:
      count += int(math.fabs(a[i][1] - b[i][1]))
  return count

cases = int(raw_input())
for case in range(cases):
  print "Case #" + str(case + 1) + ": " + str(solve())
