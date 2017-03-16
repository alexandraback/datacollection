#!/usr/bin/python
# -*- coding: utf-8 -*-

f = open("A.large","r");

def readInts():
  return map(int, f.readline().split())

caseCnt = int(f.readline())

def parts(string):
  parts = {}
  curr = string[0]
  idx = 0
  cnt = 0
  for c in string:
    if c == curr: 
      cnt += 1
      continue
    parts[idx] = (curr, cnt)
    cnt = 1
    curr = c
    idx += 1
  
  parts[idx] = (c, cnt)
  return parts

for caseNr in range(1, caseCnt + 1):
  #go for it

  n = readInts()[0]
  
  strings = []
  counted = []
  for x in xrange(n):
    strings.append(f.readline().strip())
    counted.append(parts(strings[x]))
  
  
  # check for impossible:
  l = len(counted[0])
  impossible = False
  for x in xrange(n):
    if(len(counted[x]) != l):
      impossible = True
      break
    for y in xrange(l):
      if counted[0][y][0] != counted[x][y][0]:
        impossible = True
        break
        
  if impossible:
    print "Case #" + str(caseNr) + ": Fegla Won"
    continue
    
  #print counted
  
  # count
  moves = 0
  for y in xrange(l):
    mini = 999999999
    
    start = 999
    end = 0
    for x in xrange(n):
      wupp = counted[x][y][1]
      if wupp < start:
        start = wupp
      if wupp > end:
        end = wupp
    
    if start < 1:
      start = 1
    if end < start:
      start = 1
      end = 103
    
    for z in range(start, end+1):
      m = 0
      for x in xrange(n):
        need = abs(counted[x][y][1] - z)
        m += need
      if m < mini:
        mini = m
    #print "For", y, "we need", mini, "moves"
    moves += mini
  
  print "Case #" + str(caseNr) + ": " + str(moves)
  
