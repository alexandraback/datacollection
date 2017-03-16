import sys

def safeget(l,x,y):
  try:
    return l[x][y]
  except:
    return '.'

ncases = int(sys.stdin.readline().rstrip('\n'))
for case in range(ncases):
  out="Case #%i: "%(case+1)
  arg1=int(sys.stdin.readline().rstrip('\n'))
  mi=sys.stdin.readline().rstrip('\n').split(' ')
  mi=list(map(int,mi))
  
  dmi = []
  # method 1
  for i in range(arg1-1):
    dmi.append(mi[i]-mi[i+1])
  n1 = sum(filter(lambda x: x>0,dmi))
 
  # method 2
  n2 = 0
  max_rate=max(dmi)
  for i in range(arg1-1):
    if mi[i]<max_rate:
      n2 += mi[i]
    else:
      n2 += max_rate
      
  print(out+str(n1)+' '+str(n2))