#!/usr/bin/python

import sys

#check for four in a row
def checkheight(yard,pos,updown):
   height = yard[pos[0]][pos[1]]
   if updown:
      startpos = [pos[0],0]
      vec = (0,1)
   else:
      startpos = [0,pos[1]]
      vec = (1,0)

   curpos = list(startpos)
   while curpos[0] < len(yard) and curpos[1] < len(yard[0]):
      if yard[curpos[0]][curpos[1]] > height:
         return False
      curpos[0] += vec[0]
      curpos[1] += vec[1]
   return True

def processCase(case):
   row1 = int(sys.stdin.readline())
   cards1 = [[int(x) for x in sys.stdin.readline().split()],[int(x) for x in sys.stdin.readline().split()],[int(x) for x in sys.stdin.readline().split()],[int(x) for x in sys.stdin.readline().split()]]

   row2 = int(sys.stdin.readline())
   cards2 = [[int(x) for x in sys.stdin.readline().split()],[int(x) for x in sys.stdin.readline().split()],[int(x) for x in sys.stdin.readline().split()],[int(x) for x in sys.stdin.readline().split()]]

   set1 = set(cards1[row1-1])
   set2 = set(cards2[row2-1])
   
   isect = set1.intersection(set2)
   if len(isect) == 0:
      print "Case #%d: Volunteer cheated!" % (case+1,)
   elif len(isect) == 1:
      print "Case #%d: %d" % (case+1,isect.pop())
   else:
      print "Case #%d: Bad magician!" % (case+1,)


num = int(sys.stdin.readline())

for case in range(0,num):
    processCase(case)
