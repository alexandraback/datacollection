import itertools
import math

inFile = open("C:\\Users\\Eric\\Downloads\\infile.in", "r")
outFile = open("C:\\Users\\Eric\\Downloads\\outfile.out", "w")
inString = inFile.readline()
numOfTestCase = int(inString)

for i in range(numOfTestCase):
   R,C, N = inFile.readline().split()
   R = int(R)
   C = int(C)
   N = int(N)
   roomList = []

   stuff = [ j for j in range(int(R)*int(C))]
      
   for j in range(R):
      roomList.append([0 for k in range(C)])

   minCount = -1
   for test in itertools.combinations(stuff, N):
      count = 0
      for j in test:
         #print(j, R, C)
         roomList[math.trunc(j/C)][j % C] = 1

      for j in range(R - 1):
         for k in range(C):
            if roomList[j][k] == roomList[j+1][k] == 1:
               count += 1
      for j in range(C - 1):
         for k in range(R):
            if roomList[k][j] == roomList[k][j+1] == 1:
               count += 1
      if minCount == -1 or minCount > count:
         minCount = count
      for j in test:
         roomList[math.trunc(j/C)][j % C] = 0
      count = 0
   

        
   outFile.write("Case #"+str(i+1)+": "+str(minCount) + '\n')
            
outFile.close()
inFile.close()
