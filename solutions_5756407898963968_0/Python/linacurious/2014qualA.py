attempt = "A-small-attempt0"

import time
time.clock()

def solve(a1,a2):
  answer = a1&a2
  if not answer: 
    return 'Volunteer cheated!'
  else:
    if len(answer) == 1:
      return str(answer.pop())
    else:
      return 'Bad magician!'

fin = open(attempt + ".in", 'r')
fout = open(attempt + ".out",'w')

numcases = int(fin.readline())

for casenum in range(1,numcases+1):
  # read first answer into a set
  q1 = int(fin.readline())
  for i in range(1,5):
    if q1 == i:
      a1 = set(int(n) for n in fin.readline().split())
    else:
      fin.readline()
  # read second answer into a set
  q2 = int(fin.readline())
  for i in range(1,5):
    if q2 == i:
      a2 = set(int(n) for n in fin.readline().split())
    else:
      fin.readline()
  # print result after comparing sets
  print('Case #' + repr(casenum) + ': ' + solve(a1,a2), file=fout)

fin.close()
fout.close()
print(time.clock())