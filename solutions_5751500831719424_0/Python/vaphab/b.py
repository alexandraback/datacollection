#!/usr/bin/python
import os,sys
T=int(raw_input())
for t in range(T):
  N = int( raw_input())
  strings = [""]*N
  A = raw_input()
  B = raw_input()

  same = True
  ia = 0
  ib = 0
  res = 0 
  while ia < len(A) or ib < len(B):
    if ia < len(A) and ib < len(B) and A[ia] == B[ib]:
      ia += 1
      ib += 1
    elif (ia > 0 and ia<len(A) and A[ia] == A[ia-1]):
      tmp = A[ia-1]
      while ia < len(A) and A[ia] == tmp:
        ia += 1
        res += 1
    elif ib > 0 and ib < len(B) and B[ib] == B[ib-1]:  
      tmp = B[ib-1]
      while ib < len(B) and B[ib] == tmp:
        ib += 1
        res += 1
    else:
      same = False
      break
    
   
  if same:
    print 'Case #'+str(t+1)+': '+str(res)
  else:
    print 'Case #'+str(t+1)+': Fegla Won'
 

