import string

testIndex=1

problemRoot="d:/prog/versenyek/googlejam"
problemDir="2015/round1b"
inputFiles= ["B_example.in",  "B-small.in",  "B-large.in"]
outputFiles=["B_example.out", "B-small.out", "B-large.out"]

fileName=string.strip(problemRoot)+"/"+problemDir+"/"+inputFiles[testIndex]
inputData=[map(int, line.split()) for line in open(fileName,'r') if line.strip()]
fileName=string.strip(problemRoot)+"/"+problemDir+"/"+outputFiles[testIndex]
fileToWrite=open(fileName,'w')
for iCase in range(inputData[0][0]):
  R,C,N=inputData[iCase+1]
  empty=R*C-N
  allWalls=2*R*C-(R+C)
  insideMaxEmpty=((R-2)*(C-2)+1)/2
  if R>C:
    R,C=C,R
  if R==1:
    if N<=(C+1)/2: # every second is enough
      fileToWrite.write("Case #"+str(iCase+1)+": 0\n")
    else: # all empty makes 2 less noisy walls
      fileToWrite.write("Case #"+str(iCase+1)+": "+str(C-1-2*empty)+"\n")
  elif N<=(R*C+1)/2: # chess table
    fileToWrite.write("Case #"+str(iCase+1)+": 0\n")
  elif empty<=insideMaxEmpty: # all walls minus empty*4: all empty can be inside
    fileToWrite.write("Case #"+str(iCase+1)+": "+str(allWalls-4*empty)+"\n")
  elif (R%2)*(C%2)==1: # both odd, chesstable the whole and add some border pieces
    fileToWrite.write("Case #"+str(iCase+1)+": "+str(3*(N-(R*C+1)/2))+"\n")
  else: # exactly 2 empty corners by chesstable
    if N-R*C/2<=2: # chesstable plus 1 or 2 corner
      fileToWrite.write("Case #"+str(iCase+1)+": "+str(2*(N-R*C/2))+"\n")
    else: # chesstable plus 2 corners plus some border pieces
      fileToWrite.write("Case #"+str(iCase+1)+": "+str(3*(N-R*C/2)-2)+"\n")
fileToWrite.close()
