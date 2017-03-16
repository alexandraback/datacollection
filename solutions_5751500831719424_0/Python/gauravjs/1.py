def shorten(word):
  base=word[0]
  for i in word[1:]:
    if i != base[-1]:
      base+=i
  return base

def same(words):
  return len(set(map(shorten, words)))==1

def nums(word):
  nums=[1]
  prev=word[0]
  for i in word[1:]:
    if i is prev:
      nums[-1]+=1
    else:
      prev=i
      nums.append(1)
  return nums

def changes(nums):
  i=0
  minchange = sum(nums)
  while i<max(nums):
    i+=1
    minchange = min(minchange, sum(map(lambda x: abs(x-i),nums)))
  return minchange
    

with open('/home/gauravjs/Documents/Google Code Jam/20141B/input1s','r') as f:
  cases=int(f.readline())

  for i in range(cases):
    lines = int(f.readline())
    words=[]
    for j in range(lines):
      words.append(f.readline().strip())
    if same(words):
      words = map(nums, words)
      cost = 0
      for j in range(len(words[0])):
        cost+=changes(map(lambda x: x[j], words))
      s = cost
    else:
      s = "Fegla Won"
    print 'Case #'+str((i+1))+':',s
