import fileinput

class TestCase(object):
  def __init__(self, num, waitT):
    self.num = num
    self.waitT = waitT

def solve(index, t):
  if (t.num <= len(t.waitT)) :
    return t.num
  w = list(t.waitT)
  s = len(t.waitT) + 1
  while(s < t.num + 1):
    minimalT = min(w)
    #print "test " + str(i) + " min is " + str(minimalT)
    for j, x in enumerate(w):
      w[j] = w[j] - minimalT 
      if (w[j] == 0):
        #print "barbar " + str(j+1) + " is empty"
        if (s == t.num):
          return (j+1)
        s = s + 1
        w[j] = t.waitT[j]
        #print " wtf " + str(w[j]) + " " + str(t.waitT[j])

  
  return -1

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
    data = [int(x) for x in line.split()]
    t = TestCase(data[1], [])
    testCases.append(t)
  else:
    testCases[ i /2].waitT = [int(x) for x in line.split()]

  i = i + 1

i = 1

f = open('answer', 'w')

for t in testCases:
  if (t.num > 10000): 
    maxT = max(t.waitT)

    index = 0
    print "found maxT " + str(maxT)
    while (index < len(t.waitT)):
      if maxT % t.waitT[index] == 0:
        index = index + 1
        #print "index is " + str(index) + " maxT is " + str(maxT)
        continue

      #print "here " + str(t.waitT[index])
       
      maxT = maxT + max(t.waitT)
      index = 0

    print "found maxT " + str(maxT)
    count = 0
    for index, x in enumerate(t.waitT):
      count = count + (maxT / x)

    if t.num > count:
      t.num = t.num - count * (t.num / count)
    
    print "new t.num is " + str(t.num)
    if t.num == 0:
      m = min(t.waitT)
      newT = list(t.waitT)
      newT.reverse()
      for index, x in enumerate(newT):
        if x == m:
          print "Case #" + str(i) + ": " + str(len(newT) - index) 
          f.write("Case #" + str(i) + ": " + str(len(newT) - index) + "\n")
          break
      i = i +1
      print "about to continue"
      continue


  answer = solve(i, t)
  f.write("Case #" + str(i) + ": " + str(answer) + "\n")
  print "Case #:" + str(i) + " " + str(answer) 
  i = i + 1




