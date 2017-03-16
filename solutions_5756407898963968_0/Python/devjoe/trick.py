#!/usr/bin/python

import sys

numcases=int(sys.stdin.readline())
for j in range(numcases):
  v1=int(sys.stdin.readline())
  lines1=[]
  for k in range(4):
    lines1.append(sys.stdin.readline().split())
  v2=int(sys.stdin.readline())
  lines2=[]
  for k in range(4):
    lines2.append(sys.stdin.readline().split())
  matches=[]
  for number in lines1[v1-1]:
    if number in lines2[v2-1]:
      matches.append(number)
  if len(matches)==1:
    res=matches[0]
  elif len(matches)>1:
    res="Bad magician!"
  else:
    res="Volunteer cheated!"
  sys.stdout.write("Case #"+repr(j+1)+": "+res+"\n")

