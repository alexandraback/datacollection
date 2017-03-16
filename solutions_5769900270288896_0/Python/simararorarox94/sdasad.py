import itertools
t=input()
xx=1
while t>0:
    r,c,n=map(int,raw_input().split())
    b=[]
    for i in range(0,r*c):
        b.append(i)
    x=list(itertools.combinations(b,n))
    m=1000000
    for i in range(0,len(x)):
        a=[[]]
        for j in range(0,r):
            a.append([])
            for k in range(0,c):
                a[j].append(0)
        y=x[i]
        cnt=0
        for j in range(0,r):
            for k in range(0,c):
                z=j*c+k
                if cnt<n and z==y[cnt]:
                    a[j][k]=1
                    cnt+=1
        cnt=0
        for j in range(0,r):
            for k in range(0,c):
                if (j+1)<r and a[j][k]==1 and a[j+1][k]==1:
                    cnt+=1
                if (k+1)<c and a[j][k]==1 and a[j][k+1]==1:
                    cnt+=1
        m=min(cnt,m)
    print "Case #%d: %d"%(xx,m)
    xx+=1
    t-=1

                    
                    
                
