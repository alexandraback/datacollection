#!/usr/bin/python

def isMore(I,S):
  for i in range(len(I)):
    if len(S[i]) > I[i]:
      return True
  return False

def allSame(I,S):
  for i in range(len(I)):
    if len(S[i]) <= I[i]:
      return False
    if S[i][I[i]] != S[0][I[0]]:
      return False
  return True


import os,sys
T=int(raw_input())
for t in range(T):
  N = int( raw_input())
  S = [""]*N
  for i in range(N):
    S[i] = raw_input()

  same = True
  I = [0]*N
  res = 0 
  while isMore(I,S):
    if allSame(I,S):
      for i in range(len(I)):
        I[i] += 1
      continue
    # number or same than previous
    csame = 0
    for i in range(len(I)):
      if I[i] < len(S[i]) and I[i]>0 and S[i][I[i]] == S[i][I[i]-1]:
        I[i] += 1
        csame += 1
    res += min(csame,len(I)-csame)
    if csame == 0:
      same = False
      break
     
  if same:
    print 'Case #'+str(t+1)+': '+str(res)
  else:
    print 'Case #'+str(t+1)+': Fegla Won'
 

