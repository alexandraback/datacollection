import time
f=lambda p1,p2,p3:p1[0]*p2[1]+p2[0]*p3[1]+p3[0]*p1[1] \
    -p2[0]*p1[1]-p3[0]*p2[1]-p1[0]*p3[1]

def f2(n,m,mi,mj):
    a=0;b=0
    for i in [j for j in m if j not in (mi,mj)]:
        t=f(mi,mj,i)
        if t>0:
            a+=1
        elif t<0:
            b+=1
##        print mi,mj,i,t,a,b
    return min(a,b)
def f1(n,m,mi):
    if n<=2: return 0
    a=min([f2(n,m,mi,i) for i in m if i<>mi])
##    print mi,a
    return a

def solve(n,m):
    ans=[f1(n,m,i) for i in m]
    ans='\n'+'\n'.join(map(str,ans))

    return ans

def main():
    fi=file('cs.in')
    fo=file('c.out','w')
    time0=time.time()
    t=int(fi.readline())
    for ti in range(t):
        time1=time.time()
        n=int(fi.readline())
        m=[]
        for i in range(n):
            m.append(map(int,fi.readline().split()))
        ans="Case #%d: %s"%(ti+1,solve(n,m))
        print ans,"%.3f"%(time.time()-time1)
        fo.write(ans+'\n')
    print "%.3f"%(time.time()-time0)
    fi.close()
    fo.close()

if __name__ == '__main__':
    main()
