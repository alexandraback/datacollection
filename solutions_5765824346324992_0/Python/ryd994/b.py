import sys

def mcp (lst):
  maxp = 1
  for i in lst:
    maxp *= i
  for i in range(max(lst),maxp):
    if not [1 for x in lst if i%x!=0]:
      # all divisble
      return i
  return maxp

def docase(B,N,M):
  #print B,N,M
  bstate = [0] * B
  while True:
    ma = min(bstate)
    for i in range(B):
      #print bstate
      if bstate[i]==0:    #if this barber is free
        N -=1
        #print N
        if N==0:
          return i+1
        bstate[i] = M[i] - ma
      else:
        bstate[i] -= ma
        
ncases = int(sys.stdin.readline().rstrip('\n'))
for case in range(ncases):
  out="Case #%i: "%(case+1)
  arg1=sys.stdin.readline().rstrip('\n').split(' ')
  arg2=sys.stdin.readline().rstrip('\n').split(' ')
  
  B = int(arg1[0])
  N = int(arg1[1])
  M = map(int,arg2)
  
  roundt = mcp(M)
  roundn = sum([roundt/x for x in M])
  remain = N%roundn
  
  #print roundt,roundn,remain
  if remain == 0: remain = roundn
  print(out+str(docase(B,remain,M)))
  