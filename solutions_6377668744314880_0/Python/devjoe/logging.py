import fractions
t=input()
for j in xrange(t):
  print "Case #"+str(j+1)+":"
  n=input()
  coords=[]
  for k in xrange(n):
    coords.append(map(int,raw_input().strip().split()))
  for focus in xrange(n):
    left=[]
    right=[]
    linf=0
    rinf=0
    for tree in xrange(n):
      if tree==focus:
        continue
      if coords[tree][0]==coords[focus][0]:
        if coords[tree][1]<coords[focus][1]:
          rinf+=1
        else:
          linf+=1
      else:
        slope=fractions.Fraction(coords[tree][1]-coords[focus][1],
                                 coords[tree][0]-coords[focus][0])
        if coords[tree][0]<coords[focus][0]:
          left.append(slope)
        else:
          right.append(slope)
    left.sort()
    right.sort()
    #print focus,left,right,linf,rinf
    leftcut=len(left)
    rightcut=len(right)
    mintrees=min(leftcut,rightcut)
    lpos=0
    rpos=0
    lcur=linf
    rcur=rinf
    while lpos<len(left) and rpos<len(right):
      curangle=min(left[lpos],right[rpos])
      leftcut+=rcur
      rightcut+=lcur
      lcur=0
      rcur=0
      while lpos<len(left) and left[lpos]==curangle:
        lpos+=1
        lcur+=1
        leftcut-=1
      while rpos<len(right) and right[rpos]==curangle:
        rpos+=1
        rcur+=1
        rightcut-=1
      mintreesnow=min(leftcut,rightcut)
      if mintreesnow<mintrees:
        mintrees=mintreesnow
    #check final line. One of these while conditions will already be true when
    #we get here; this plays out the remaining side.
    while lpos<len(left):
      curangle=left[lpos]
      leftcut+=rcur
      rightcut+=lcur
      lcur=0
      rcur=0
      while lpos<len(left) and left[lpos]==curangle:
        lpos+=1
        lcur+=1
        leftcut-=1
      mintreesnow=min(leftcut,rightcut)
      if mintreesnow<mintrees:
        mintrees=mintreesnow
    while rpos<len(right):
      curangle=right[rpos]
      leftcut+=rcur
      rightcut+=lcur
      lcur=0
      rcur=0
      while rpos<len(right) and right[rpos]==curangle:
        rpos+=1
        rcur+=1
        rightcut-=1
      mintreesnow=min(leftcut,rightcut)
      if mintreesnow<mintrees:
        mintrees=mintreesnow
    print mintrees

    
        
