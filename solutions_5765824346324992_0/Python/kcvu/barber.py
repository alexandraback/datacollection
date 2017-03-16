import sys
from fractions import gcd

def readInput(fileName):
  global inputData

  inputFile = open(fileName)

  inputFile.readline() # number of test cases
  firstLine = True
  for line in inputFile:
    if firstLine:
      firstLine = False
      _, n = [int(v) for v in line.strip().split(' ')]
      tmp = {'n':n}
    else:
      firstLine = True
      speedList = [int(m) for m in line.strip().split(' ')]
      tmp['m'] = speedList
      yield tmp
  
def lcm2numbers(n1, n2):
  return n1 * n2 / gcd(n1,n2)
      
def lcm(nl):
  l = len(nl)
  if l == 0:
    return 0
  if l == 1:
    return nl[0]
  if l == 2:
    return lcm2numbers(nl[0],nl[1])
  return lcm2numbers(nl[0],lcm(nl[1:]))
 
def gcdAll(speedList):
  l = len(speedList)
  if l == 0:
    return 0
  if l == 1:
    return speedList[0]
  if l == 2:
    return gcd(speedList[0],speedList[1])
  return gcd(speedList[0],gcdAll(speedList[1:]))
  
def servedPerInterval(t, speedList):
  totalServed = 0
  for s in speedList:
    totalServed += (t/s)
  return totalServed
   
def nextRoundPositions(t,speedList):
  freeSlot = []
  totalServed = 0
  j = 0
  for s in speedList:
    j += 1
    served = t/s
    totalServed += served
    if t % s == 0:
      freeSlot.append(j)
    else:
      totalServed += 1
  return (totalServed,freeSlot)
  
def findSlot(n,step,interval,speedList):
  t = 0
    
  while t < interval:
    totalServed, freeSlot = nextRoundPositions(t,speedList)
    #print "T={0}, served:{1}, slots:{2}".format(t,totalServed,freeSlot)
    if totalServed + len(freeSlot) >= n:
      index = n - totalServed - 1
      return freeSlot[index]
    t += step
    

i = 0    
for data in readInput(sys.argv[1]):
  n = data['n']
  speedList = data['m']
  interval = lcm(speedList)
  servedInterval = servedPerInterval(interval, speedList)
  
  n = n % servedInterval
  if n == 0:
    n = servedInterval
  
  #print "Interval: {0}, servedInterval: {1}, newN: {2}".format(interval, servedInterval, n)
  result = findSlot(n,gcdAll(speedList),interval,speedList)
    
  i += 1
  print "Case #{0}: {1}".format(i,result)