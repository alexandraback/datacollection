
T = int(raw_input())


for t in range(0,T):

    imena='ABCDEFGHIJKLMNOPQRSTUVWXWZ'
    N = int(raw_input())
    P=raw_input().split()
    count={}
    total=0
    for i in range(0,N):
        count[i]=int(P[i])
        total+=count[i]

    rv=''
    while True:
        #max=count['A']
        max=-1
        letter = '0'
        indexmax =-1
        prev=''
        previndex = -1
        tmax=-1
        imax,imax2=0,0
        havedouble=False
        havetriple=False
        for i in range(0,N):
            if tmax<count[i]:
                tmax = count[i]
                imax = i
                #print 'tmax',tmax, 'imax',imax
                havedoulbe=False
                havetriple=False
            elif tmax==count[i]:
               # print 'ex tmax',tmax2,'tmax2', tmax2
                tmax2=count[i]
                imax2 = i
                if havedouble==True:
                    havetriple=True
                havedouble=True
        if tmax==0:
            break
       # print 'havedouble', havedouble
        if havedouble==False or havetriple==True:
            
            rv+=' '+imena[imax]
            count[imax]-=1
            total-=1
        else:
            rv+=' '+imena[imax]+imena[imax2]
            count[imax]-=1
            count[imax2]-=1
            total-=2
            
            
      
    print "Case #"+str(t+1)+":",rv
