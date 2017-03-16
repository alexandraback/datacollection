import copy
import fractions
import os
import re
import string
import sys
import time

start = time.time()

filename = sys.argv[1]
file = open(filename, "rb")

cases = int(file.readline())
for case in range(1, cases+1):
   
   sys.stderr.write("%d\n" % (case))
   
   # Code Here
   n = int(file.readline())
   m = map(int, file.readline().split())
   
   # First method
   eat1 = 0
   for i in xrange(1, len(m)):
   
      if (m[i] < m[i-1]):
         eat1 += (m[i-1] - m[i])
   
   # Second method
   eat2 = 0xffffffff
   for rate in range(0, max(m)+1):
      
      eat = 0
      for i in xrange(1, len(m)):
      
         this_round = min(rate, m[i-1])
         if ((m[i-1]-this_round) > m[i]):
            eat = 0xffffffff
            break
         else:
            eat += this_round
      
      # print (rate, eat)
      eat2 = min(eat, eat2)
   
   print "Case #%d: %s %s" % (case, eat1, eat2)
   
file.close()

end = time.time()
sys.stderr.write("%f\n" % (end-start))
