
def parse_string(s):
   a=[]
   s = s.strip()  
   for c in s:
      if(len(a) >0 and c == a[-1][0] ):
         a[-1] = (c,a[-1][1]+1)
      else:
         a.append( (c,1) )

   return a

import numpy as np

def median_moves(NN):
   a = np.array(NN)
   a.sort()
   mmin=np.inf
   for i in range(len(a)):
      v = np.sum( np.abs(a - a[i]) )
      mmin = min(mmin,v)

   return mmin


f = open('in')
ncases = int(f.readline())

for case in range(ncases):

   nstrings = int(f.readline())

   strings = {}
   for s in range(nstrings):
      strings[s] =  parse_string(f.readline())

   # same *lenght*
   fail=0;
   moves=0;
   for c in range(len(strings[0])):
      C0 = strings[0][c]
      #initialize NN
      NN = [0 for i in range(nstrings)]
      for s in range(nstrings):
         # failsafe
         if not len(strings[s]) == len(strings[0]):
            fail=1;

         if c<len(strings[s])  and strings[s][c][0] == C0[0]:
            NN[s] = strings[s][c][1]
         else: 
            fail=1;

   #   print NN
      if not fail:
#         print C0
#         print median_moves(NN)
         moves +=  median_moves(NN)

   if not fail:
      print "Case #%d: %s"%(case+1, moves)
   else:
      print "Case #%d: Fegla Won"%(case+1)

