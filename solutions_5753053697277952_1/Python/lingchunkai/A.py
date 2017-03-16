# -*- coding: utf-8 -*-
import heapq

class MyHeap(object):
   def __init__(self, initial=None, key=lambda x:x):
       self.key = key
       if initial:
           self._data = [(key(item), item) for item in initial]
           heapq.heapify(self._data)
       else:
           self._data = []

   def push(self, item):
       heapq.heappush(self._data, (self.key(item), item))

   def pop(self):
       return heapq.heappop(self._data)[1]

T = int(raw_input())

QQ = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q','R', 'S', 'T','U', 'V', 'W','X','Y','Z']
for t in xrange(T):

  N = int(raw_input())
  Z = map(int, raw_input().split())
  ZZ = zip(Z, QQ[0:len(Z)])
  #print ZZ

  H=MyHeap(ZZ, lambda x:-x[0])
  #print "==="
  #print "hehehe", H._data

  ans = []
  while (len(H._data)>0):
    # print H._data
    # special case:
    if len(H._data) == 3:
      if H._data[0][1][0]==1 and H._data[1][1][0]==1 and H._data[2][1][0]==1:
        ans.append(H.pop()[1])
        continue 
    addme = ""
    for g in xrange(2):
      if len(H._data)==0: continue
      poop = H.pop()
      addme = addme+poop[1]
      if poop[0]>1:
        H.push((poop[0]-1, poop[1]))
    ans.append(addme)
  print "Case #" + str(t+1) + ": " + ' '.join(ans)