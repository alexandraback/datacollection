#!/usr/bin/env python

for nnn in xrange(1, int(raw_input())+1):
  print "Case #%d:" % (nnn),
  N = int(raw_input())
  m = [int(x) for x in raw_input().split()]
  y, z, zrate = 0, 0, 0
  l = len(m)-1
  for i in xrange(l):
    diff = m[i]-m[i+1]
    y += max(0, diff)
    zrate = max(diff, zrate)
  for i in xrange(l):
    z += min(zrate, m[i])
  print y, z

