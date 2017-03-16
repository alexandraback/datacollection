def numcuts(minutes,m):
  #Calculate the number of cuts these barbers start in minutes minutes.
  res=0
  for mk in m:
    #If minutes is exactly p * mk, then p+1 customers are cut or started
    #by this barber If minutes is p * mk - 1, only p are cut.
    res+=1+(minutes//mk)
  return res

t=input()
for j in xrange(t):
  b,n=map(int,raw_input().strip().split())
  m=map(int,raw_input().strip().split())
  #Special case: We start our cut at time 0
  if n<=b:
    print "Case #"+str(j+1)+": "+str(n)
    continue
  #Estimate time until we are served
  cutsperminute=0
  for mk in m:
    cutsperminute+=1.0/mk
  min1=int((n-b)/cutsperminute)
  ncut1=numcuts(min1,m)
  if ncut1>=n:
    minb=min1
    ncutb=ncut1
    mina=0
    ncuta=b
  else:
    mina=min1
    ncuta=ncut1
    minb=mina+int(b/cutsperminute)+1
    ncutb=numcuts(minb,m)
    while ncutb<n:
      minb+=int(b/cutsperminute)+1
      ncutb=numcuts(minb,m)
  #Interval halving
  while minb-mina>1:
    minc=(mina+minb)//2
    ncutc=numcuts(minc,m)
    if ncutc<n:
      mina=minc
      ncuta=ncutc
    else:
      minb=minc
      ncutb=ncutc
  #Which barber cuts our hair?
  npos=n-ncuta
  #The npos'th one who starts a cut at time minb does
  xbarber=[]
  for k in xrange(b):
    if minb%m[k]==0:
      xbarber.append(k+1)
  print "Case #"+str(j+1)+": "+str(xbarber[npos-1])
 

  
