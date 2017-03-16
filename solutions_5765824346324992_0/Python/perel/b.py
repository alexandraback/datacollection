import time
def gcd(a,b):
    if a<b:
        a,b=b,a
    c=a%b
    while c:
        a,b=b,c
        c=a%b
    return b

def mm(m):
    b=reduce(lambda x,y:x*y/gcd(x,y),m)
##    print m,b
    return b
def solve(b,n,m):
    mm1=mm(m)
    tcir=sum([mm1/i for i in m])
    n%=tcir;
    if n==0:
        n=tcir
    if n<=b:
        return n
    t=[0,mm1]
    while 1:
        if t[1]-t[0]==1:
            break
        tmid=(t[1]+t[0])/2
        nc=b+sum([tmid/i for i in m])
##        print t,tmid,n,nc
        if n<=nc:
            t[1]=tmid
        elif n>nc:
            t[0]=tmid
    ans=[i+1 for i in range(b) if t[1]%m[i]==0]#;print ans,n,t,mm1
    return ans[n-b-sum([t[0]/i for i in m])-1]

def main():
    fi=file('bs.in')
    fo=file('b.out','w')
    time0=time.time()
    t=int(fi.readline())
    for ti in range(t):
        time1=time.time()
        b,n=map(int,fi.readline().split())
        m=map(int,fi.readline().split())
        ans="Case #%d: %s"%(ti+1,solve(b,n,m))
        print ans,"%.3f"%(time.time()-time1)
        fo.write(ans+'\n')
    print "%.3f"%(time.time()-time0)
    fi.close()
    fo.close()

if __name__ == '__main__':
    main()
