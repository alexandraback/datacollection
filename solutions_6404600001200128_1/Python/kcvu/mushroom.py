import sys

def readInput(fileName):
  global inputData

  inputFile = open(fileName)

  inputFile.readline() # number of test cases
  firstLine = True
  for line in inputFile:
    if firstLine:
      firstLine = False
    else:
      firstLine = True
      mushroom= [int(m) for m in line.strip().split(' ')]
      yield mushroom
      
i = 0
for mList in readInput(sys.argv[1]):
  maxDiff = 0
  preM = None
  res1 = 0
  res2 = 0
  for m in mList:
    if preM is not None:
      diff = preM - m
      preM = m
      if diff > 0:
        res1 += diff
      if diff > maxDiff:
        maxDiff = diff
    else:
      preM = m
     
  preM = None 
  for j in range(len(mList)-1):
    m = mList[j]
    if m < maxDiff:
      res2 += m
    else:
      res2 += maxDiff
      
  i += 1
  print "Case #{0}: {1} {2}".format(i,res1,res2)