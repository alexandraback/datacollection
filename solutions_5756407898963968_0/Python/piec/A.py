import sys
import string

numcases = int(sys.stdin.readline())
for casenum in range(1,numcases+1):
  firstRow = int(sys.stdin.readline()) - 1
  firstBoard = []
  for i in range(4):
    firstBoard.append(string.split(sys.stdin.readline().strip()))

  secondRow = int(sys.stdin.readline()) - 1
  secondBoard = []
  for i in range(4):
    secondBoard.append(string.split(sys.stdin.readline().strip()))

  rowsIntersection = list(set(firstBoard[firstRow]) & set(secondBoard[secondRow]))
  if len(rowsIntersection) == 1:
    result = rowsIntersection[0]
  elif len(rowsIntersection) == 0:
    result = "Volunteer cheated!"
  else:
    result = "Bad magician!"

  print 'Case #' + repr(casenum) + ': ' + result
