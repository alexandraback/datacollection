import copy
import fractions
import math
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
   (b, n) = map(int, file.readline().split())
   m = map(int, file.readline().split())
   
   # Number of minutes
   inc = reduce(lambda x,y: fractions.gcd(x,y), m, 0)
   
   barber = -1
   if (b >= n):
      barber = n

   else:
      
      # Find the starting value
      imax = max(m)*n
      imin = 0

      imid = (imax+imin)/2
      smid = b + reduce(lambda x,y: x+imid/y, m, 0)
      
      while (1):
      
         if (smid < (n-b)):
            imin = imid+inc
         elif (smid > n):
            imax = imid-inc
         else:
            break
            
         imid = (imax+imin)/2
         smid = b + reduce(lambda x,y: x+imid/y, m, 0)
         
      imid -= min(m)
      imid -= (imid % inc)
      
      minutes = imid
      count = b + reduce(lambda x,y: x+imid/y, m, 0)
      
      # print minutes
      # print count
      # print inc
      
      while (barber == -1):
         minutes += inc
         for i in xrange(b):
            if (minutes % m[i] == 0):
               count += 1
               if (count == n):
                  barber = i+1
                  break
            
   print "Case #%d: %d" % (case, barber)
   
file.close()

end = time.time()
sys.stderr.write("%f\n" % (end-start))
