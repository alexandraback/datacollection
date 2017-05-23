import sys
sys.stdin=open("small11.in",'r')
sys.stdout=open("small11.out",'w')
v=int(raw_input())+1
for t in xrange(1,v):
    N=int(raw_input())
    vals=map(int,raw_input().split())
    out=[]
    while sum(vals):
        u=list(set(vals))
        if len(u)==1 and u[0]==1:break
        if len(u)==1:
            ind1,ind2=-1,-1
            for i in xrange(N):
                if vals[i]:
                    if ind1==-1:
                        ind1=i
                    else:
                        ind2=i
            vals[ind1]-=1
            vals[ind2]-=1
            out.append(chr(ord('A')+ind1)+chr(ord('A')+ind2))   
        else:
            m1,m2=0,0
            ind1,ind2=-1,-1
            for i in xrange(N):
                if vals[i]>m2:
                    m2=vals[i]
                    ind2=i
            out.append(chr(ord('A')+ind2))
            vals[ind2]-=1
    temp=[]
    for i in xrange(N):
        if vals[i]:
            temp.append(chr(ord('A')+i))
    if len(temp)%2:
        out.append(temp.pop())
    while temp:
        out.append(temp.pop()+temp.pop())
    print 'Case #%i:'%(t),
    for i in out:print i,
    print
sys.stdout.close()
            
