#!/usr/bin/python
from sys import stdout
import string
def f(l):
  while l:
    l = sorted(l, key=lambda x:-x[1]) 
    if len(l)>2:
      l[0][1]-=1
      stdout.write(l[0][0]+' ')
      if l[0][1]==0:
        l = l[1:]
    elif len(l)==2:
      for i in range(l[0][1]):
        stdout.write(l[0][0]+l[1][0]+' ')
      break

testcases = int(raw_input())
for testcase in range(testcases):
  number_of_senators = int(raw_input())
  senators = map(list,zip(string.ascii_uppercase, map(int, raw_input().split())))
  stdout.write("Case #"+str(testcase+1)+": ")
  f(senators)
  stdout.write('\n')
