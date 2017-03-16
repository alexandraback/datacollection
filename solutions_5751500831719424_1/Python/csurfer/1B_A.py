from io import open

def process(inp):
  n = int(inp.readline())
  stArr = [list(inp.readline())[:-1] for i in xrange(n)]
  uniqueArr = []
  for st in stArr:
    arr = []
    for ch in st:
      if len(arr) == 0:
        arr.append(ch)
      elif ch != arr[-1]:
        arr.append(ch)
    uniqueArr.append(arr)
  
  # Test Immpossibility
  for i in xrange(1,len(uniqueArr)):
    if uniqueArr[i] != uniqueArr[i-1]:
      return "Fegla Won"
  
  # Get minimum
  stCnt = []
  for i in xrange(len(uniqueArr)):
    #print stArr[i]
    tempArr = []
    while len(uniqueArr[i])>0:
      ch = uniqueArr[i][0]
      uniqueArr[i] = uniqueArr[i][1:]
      cnt = 0
      while len(stArr[i])>0:
        if ch == stArr[i][0]:
          cnt += 1
          stArr[i] = stArr[i][1:]
        else:
          break
      tempArr.append(cnt)
    stCnt.append(tempArr)
    #print tempArr

  # Calculate Min
  flag = True
  for i in xrange(1,len(stCnt)):
    if stCnt[i] != stCnt[i-1]:
      flag = False
  if flag:
    return 0

  action = 0
  for i in xrange(len(stCnt[0])):
    calArr = [el[i] for el in stCnt]
    calArr = sorted(calArr)
    if len(calArr)%2 == 0:
      # Even case
      action1 = 0
      action2 = 0
      median = calArr[(len(calArr)-1)//2]
      for num in calArr:
        action1 += abs(median-num)
      median = calArr[((len(calArr)-1)//2)+1]
      for num in calArr:
        action2 += abs(median-num)
      action += min(action1, action2)
    else:
      # Odd case
      median = calArr[len(calArr)//2]
      for num in calArr:
        action += abs(median-num)
  return action

def output(strOut, out):
  print strOut
  out.write(u"{}\n".format(strOut))

def main():
  inp = open("input.txt")
  out = open("output.txt", "wb+")
  tC = int(inp.readline())
  tc = tC
  while tc > 0:
    tc -= 1
    ans = process(inp)
    output(u"Case #{}: {}".format(tC-tc, ans), out)
  inp.close()
  out.close()

if __name__ == "__main__":
  main()
