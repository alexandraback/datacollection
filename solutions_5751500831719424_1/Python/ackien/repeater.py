import sys

def solveCase(N,strings):
  solutionFormats = []
  for string in strings:
    chunk = None
    solutionFormat = []
    for char in string:
      if chunk is None: chunk = [char]
      elif char == chunk[0]:
        chunk.append(char)
      else:
        if len(chunk) == 1:
          solutionFormat.append((chunk[0],len(chunk)))
          chunk = [char]
        elif len(chunk) > 1:
          solutionFormat.append((chunk[0],len(chunk)))
          chunk = [char]
    solutionFormats.append(solutionFormat)
  formatLength = len(solutionFormats[0])
  for solutionFormat in solutionFormats:
    if len(solutionFormat) != formatLength:
      return "Fegla Won"
  totalDifferences = 0
  for i,charTuple in enumerate(solutionFormats[0]):
    for solutionFormat in solutionFormats[1:]:
      if charTuple[0] != solutionFormat[i][0]: return "Fegla Won"
    totalDifferences += min(differences(map(lambda x: x[i][1], solutionFormats)))
  return str(totalDifferences)

def differences(l):
  allDifferences = []
  for i in range(len(l)):
    curDifferences = 0
    for j in range(len(l)):
      if i == j: continue
      curDifferences += abs(l[i]-l[j])
    allDifferences.append(curDifferences)
  return allDifferences

filename = sys.argv[1]
fileIn = open(filename, 'r')
fileOut = open("out.txt", 'w')
T =  int(fileIn.readline())
for case in range(T):
  N = int(fileIn.readline())
  strings = [fileIn.readline() for n in range(N)]
  answer = solveCase(N,strings)
  fileOut.write("Case #{:d}: {:s}\n".format(case+1, answer))
fileOut.close()
fileIn.close()
