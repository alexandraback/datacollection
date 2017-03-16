
f = open("bl.in")
fo=open('out','w')
def raw_input():
    return f.readline().strip()
def x(r,c):
    if r*c%2==0:
        return r*c/2
    else:
        return (r+1)*c/2-c//2
for z in range(int(raw_input())):
    r,c,n= map(int, raw_input().split())
    if r>c:
        r,c=c,r
    if r==1:
        mx=x(c,r)
        tp=0
        if n<=mx:
            tp=0
        elif c%2==1:
            tp=(n-mx)*2
        else:
            tp=(n-mx-1)*2+1
        fo.write("Case #%d: %d\n" % (z + 1,tp))
    else:
        l=[0]*3
        if r*c%2==0:
            mx=r*c/2
            if n<=mx:
                fo.write("Case #%d: 0\n" % (z + 1))
            else:
                l[0]=2
                l[1]=r+c-4
                l[2]=r*n-mx-l[0]-l[1]
                n-=mx
                i=0
                t=0
                while n>0:
                    mn=min(n,l[i])
                    t+=mn*(i+2)
                    n-=mn
                    i+=1
                fo.write("Case #%d: %d\n" % (z + 1,t))
        else:
            mx=(r+1)*c/2-c//2
            if n<=mx:
                fo.write("Case #%d: 0\n" % (z + 1))
            else:
                l[1]=2*(r//2+c//2)
                l[2]=r*n-mx-l[1]
                n1=n
                n-=mx
                n1=n
                i=0
                t=0
                while n>0:
                    mn=min(n,l[i])
                    t+=mn*(i+2)
                    n-=mn
                    i+=1
                t1=t
                t=0
                i=0
                n=n1+1
                l[0]=4
                l[1]=2*(c//2+r//2-2)
                l[2]=r*n-mx-l[0]-l[1]
                while n>0:
                    mn=min(n,l[i])
                    t+=mn*(i+2)
                    n-=mn
                    i+=1
                fo.write("Case #%d: %d\n" % (z + 1,min(t,t1)))
print "d"