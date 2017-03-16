from heapq import heappush, heappop
import fileinput

class TestCase(object):
  def __init__(self, r, c, n):
    self.r = r
    self.c = c
    self.n = n

def solve(t):
  total = t.r * t.c
  if (total % 2 == 0) and ((total / 2) >= t.n):
    return 0
  if (total % 2 == 1) and ((total / 2 + 1) >= t.n):
    return 0

  matrix = [[0 for x in range(t.c)] for x in range(t.r)] 
  #print str(matrix)

  unhappy = 0
  
  count = total / 2
  if (total % 2 == 1):
    count = count + 1
   
  for i in range(t.r):
    for j in range(t.c):
      if ((i + j) % 2) == 0:
        #print str(i) + " " + str(j) + " " + str(t.r) + " " + str(t.c)
        matrix[i][j] = 1

  #scan through and make a queue

  #print str(matrix)
  dx = [1, 0, -1, 0]
  dy = [0, 1, 0, -1]
  unHappyHeap = []
  for i in range(t.r):
    for j in range(t.c):
      if (matrix[i][j] != 1):
        print "evaluating " + str(i) + " " + str(j)
        unH = 0
        for k in range(4):
          if i+dx[k] >= 0 and i+dx[k] < t.r and j+dy[k] >= 0 and j+dy[k] < t.c:
            if matrix[i+dx[k]][j+dy[k]] == 1:
              unH = unH + 1
        print "unH is " + str(unH)
        heappush(unHappyHeap, unH)

  print "test " + str(unHappyHeap)

  diff = t.n - (count)

  while diff != 0:
    unhappy = unhappy + heappop(unHappyHeap)
    diff = diff - 1
  print "unhappy " + str(unhappy)
  
  unhappy1 = unhappy
  unhappy = 0
  
  matrix = [[0 for x in range(t.c)] for x in range(t.r)] 
  for i in range(t.r):
    for j in range(t.c):
      if ((i + j) % 2) == 1:
        #print str(i) + " " + str(j) + " " + str(t.r) + " " + str(t.c)
        matrix[i][j] = 1

  unHappyHeap = []
  for i in range(t.r):
    for j in range(t.c):
      if (matrix[i][j] != 1):
        print "evaluating " + str(i) + " " + str(j)
        unH = 0
        for k in range(4):
          if i+dx[k] >= 0 and i+dx[k] < t.r and j+dy[k] >= 0 and j+dy[k] < t.c:
            if matrix[i+dx[k]][j+dy[k]] == 1:
              unH = unH + 1
        print "unH is " + str(unH)
        heappush(unHappyHeap, unH)

  print "test " + str(unHappyHeap)

  diff = t.n - (count)

  if ((t.r %2 == 1) and (t.c %2  == 1)):
    diff = diff + 1

  while diff != 0:
    unhappy = unhappy + heappop(unHappyHeap)
    diff = diff - 1

  print "two results " + str(unhappy1) + " " + str(unhappy)
  return min(unhappy1, unhappy)
  #print str(t.r) + " " + str(t.c) + " " + str(t.n)

start = True
i = 0
numberOfT = 0
testCases = []

for line in fileinput.input():
  if start:
    numberOfT = int(line)
    start = False
    continue
    
  data = [x for x in line.split()]
  t = TestCase(int(data[0]), int(data[1]), int(data[2]))
  testCases.append(t)

i = 1

f = open('answer', 'w')

for t in testCases:
  answer = solve(t)
  f.write("Case #" + str(i) + ": " + str(answer) + "\n")
  i = i + 1


