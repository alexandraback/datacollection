#! /usr/bin/python

import sys
from collections import OrderedDict

def merge(s0, s1, fst_s0_pos, fst_s1_pos):
  action = 0
  s0_pos = fst_s0_pos
  s1_pos = fst_s1_pos
  s0_len = len(s0)
  s1_len = len(s1)
  s0 += " "
  s1 += " "
  while True:
#    print s0, s1, s0_pos, s1_pos
    if s0[s0_pos] == s1[s1_pos]:
      if s0_pos == s0_len and s1_pos == s1_len:
        return action
      s0_pos += 1
      s1_pos += 1
      
    else:
      if s0[s0_pos] == s1[s1_pos-1]:
#        print s0, s1, s0_pos, s1_pos, 1
        action += 1
        s0_pos += 1
      elif s1[s1_pos] == s0[s0_pos-1]:
#        print s0, s1, s0_pos, s1_pos, 2
        action += 1
        s1_pos += 1
      else:
        return "Fegla Won"
        print s0, s1, s0_pos, s1_pos
        sys.exit()


def solve(t, s):
  reduced_s = []
  identical = True
  reduced_identical = True

  for i in xrange(t):
    reduced_s.append("".join(OrderedDict.fromkeys(s[i])))
    if s[0] != s[i]:
      identical = False
    if reduced_s[0] != reduced_s[i]:
      reduced_identical = False

#  print reduced_s, reduced_identical

  if identical:
    return 0

  if not reduced_identical:
    return "Fegla Won"

  return merge(s[0], s[1], 1, 1)

    
fd = open(sys.argv[1])

num_cases = int(fd.readline())

for i in range(0, num_cases):
  t = int(fd.readline().strip())
  s = []
  for j in xrange(t):
    s.append(fd.readline().strip())
  output = solve(t, s)
  print "Case #%d:" % (i+1), output

