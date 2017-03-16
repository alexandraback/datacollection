from fractions import gcd
fi=open("b.in")
t=int(fi.readline())
fo=open("out","w")
for j in range(t):
    b,n= map(int, fi.readline().strip().split())
    l= map(int, fi.readline().split())
    cy=reduce(lambda x,y:x*y//gcd(x,y),l)
    s=sum([cy/x for x in l])
    n%=s
    def f(l1,l2,n):
        if n==0:
            return 1
        while True:
            for i in range(len(l2)):
                if l2[i]==0:
                    n-=1
                    if n==0:
                        return i+1
                    l2[i]=l1[i]
            mn=min(l2)
            for i in range(len(l2)):
                l2[i]-=mn
    fo.write("Case #%d: %d\n"%(j+1,f(l,[0]*b,n if n!=0 else s)))
fi.close()
fo.close()
print "done"