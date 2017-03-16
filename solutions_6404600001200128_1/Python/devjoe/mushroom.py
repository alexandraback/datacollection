t=input()
for j in xrange(t):
  n=input()
  m=map(int,raw_input().strip().split())
  res1=0
  maxeat=0
  last=m[0]
  for cur in m[1:]:
    eaten=last-cur
    if eaten>0:
      res1+=eaten
    if eaten>maxeat:
      maxeat=eaten
    last=cur
  res2=0
  last=m[0]
  for cur in m[1:]:
    if last>maxeat:
      res2+=maxeat
    else:
      res2+=last
    last=cur
  print "Case #"+str(j+1)+": "+str(res1)+" "+str(res2)
