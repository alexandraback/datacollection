#!/usr/bin/env python

import sys

f = open(sys.argv[1], 'r')
T = int(f.readline())

def check(first_arr, second_arr):
  return first_arr & second_arr

for t in range(T):
  first_reply = int(f.readline()) 
  for tt in range(1,5):
    if tt == first_reply:
      first_arr = f.readline().strip().split()
    else:
      f.readline()

  second_reply = int(f.readline())
  for tt in range(1,5):
    if tt == second_reply:
      second_arr = f.readline().strip().split()
    else:
      f.readline()

  r = check(set(first_arr), set(second_arr))
  l = len(r)

  if l == 1:
    print "Case #%d: %s" % ((t+1), r.pop())
  elif l > 1:
    print "Case #%d: Bad magician!" % (t+1)
  elif l < 1:
    print "Case #%d: Volunteer cheated!" % (t+1) 
