#! /usr/bin/python

import sys
from collections import OrderedDict

def merge(t, s):
  action = 0
  s_pos = []
  s_len = []
  for i in xrange(t):
    s_pos.append(1)
    s_len.append(len(s[i]))
    s[i] += " "

  cur_char = s[0][0]

  if t % 2 == 0:
    threshold = t // 2
  else:
    threshold = t // 2 + 1

  while True:
    ident = True
    last_pos = True
    num_match_prev = 0

    for i in xrange(t):
      if s[i][s_pos[i]] == cur_char:
        num_match_prev += 1
      if s[0][s_pos[0]] != s[i][s_pos[i]]:
        ident = False
      elif s_pos[i] != s_len[i]:
        last_pos = False

#    print s, s_pos, ident, num_match_prev, action, cur_char

    if ident:
      if last_pos:
        return action
      for i in xrange(t):
        s_pos[i] += 1
      cur_char = s[0][s_pos[0]-1]
      
    else:
      # find if better to add or substract
      if num_match_prev < threshold:
#        print 1
        # should substract
        for i in xrange(t):
          if s[i][s_pos[i]] == cur_char:
             action += 1
             s_pos[i] += 1

      else:
#        print 2
        # should add
        for i in xrange(t):
          if s[i][s_pos[i]] != cur_char:
             action += 1
          else:
             s_pos[i] += 1

def solve(t, s):
  reduced_s = []
  identical = True
  reduced_identical = True

  for i in xrange(t):
    tmp = ""
    prev_char = " "
    for j in xrange(len(s[i])):
      if prev_char != s[i][j]:
        tmp += s[i][j]
        prev_char = s[i][j]
    reduced_s.append(tmp)
    if s[0] != s[i]:
      identical = False
    if reduced_s[0] != reduced_s[i]:
      reduced_identical = False

  if identical:
    return 0

  if not reduced_identical:
    return "Fegla Won"

  return merge(t, s)

    
fd = open(sys.argv[1])

num_cases = int(fd.readline())

for i in range(0, num_cases):
  t = int(fd.readline().strip())
  s = []
  for j in xrange(t):
    s.append(fd.readline().strip())
  output = solve(t, s)
  print "Case #%d:" % (i+1), output

