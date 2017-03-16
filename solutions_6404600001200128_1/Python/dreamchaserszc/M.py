import fileinput

class TestCase(object):
  def __init__(self, num, count):
    self.num = num
    self.count = count


def solve(index, t):
  answerA = 0
  
  prev = t.count[0]
  for i, x in enumerate(t.count):
    if i == 0:
      continue
    if (prev - x > 0):
      answerA = answerA + (prev - x)

    prev = x

  answerB = 0
  maxD = 0
  prev = t.count[0]
  for i, x in enumerate(t.count):
    if i == 0:
      continue
    if (maxD < (prev - x)):
      maxD = prev - x
    prev = x

  #print "max : " +str(maxD)
  prev = t.count[0]
  for i, x in enumerate(t.count):
    if i == 0:
      continue
    if prev <= maxD:
      answerB = answerB + prev
    else:
      answerB = answerB + maxD
    prev = x

  #print "t: " + str(t.num) + " " + str(t.count) + " " + str(answerA) + " " + str(answerB)
  f.write("Case #" + str(index) + ": " + str(answerA) + " " + str(answerB) + "\n")
  return

start = True
i = 0
numberOfT = 0
testCases = []

for line in fileinput.input():
  if start:
    numberOfT = int(line)
    start = False
    continue

  if (i % 2) == 0:
    t = TestCase(int(line), [])
    testCases.append(t)
  else:
    testCases[ i /2].count = [int(x) for x in line.split()]

  i = i + 1

i = 1

f = open('answer', 'w')

for t in testCases:
  answer = solve(i, t)
  i = i + 1



