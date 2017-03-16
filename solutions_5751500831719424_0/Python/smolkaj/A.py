#### Template. Destription ####

# from math import sqrt, ceil, floor
from statistics import median_low

# input
filename = "input"
lines = (line.rstrip('\n') for line in open(filename))
T = int(lines.__next__())

# output
output = open('output', 'w+')

def nums(s):
  c_ = s[0]
  n = 0
  ns = []
  for c in s:
    if c == c_:
      n +=1
    else:
      ns.append(n)
      n = 1
      c_ = c
  ns.append(n)
  return ns

def sig(s):
  c_ = False
  sg = ""
  for c in s:
    if c != c_:
      c_ = c
      sg += c
  return sg

# test case loop
for caseIdx in range(T):
  N = int(lines.__next__())
  strs = []
  for _ in range(N):
    strs.append(str(lines.__next__()))
  nss = zip(*map(nums, strs))
  sigs = set(map(sig, strs))

  if len(sigs) == 1:
    actions = 0
    for ns in nss:
      m = median_low(ns)
      for n in ns:
        actions += abs(m - n)
    msg = str(actions)
  else:
    msg = 'Fegla Won'

  # print output
  out = 'Case #' + str(caseIdx + 1) + ': ' + msg + '\n'
  output.write(out)
  print(out)

output.close()
# print(open('output', 'r').read())