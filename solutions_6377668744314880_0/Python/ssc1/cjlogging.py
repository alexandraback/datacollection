fi=open("c2.in")
t=int(fi.readline())
fo=open("out","w")
def f(l,a,b,n):
    if a==b:
        return n
    dx=l[b][0]-l[a][0]
    dy=l[b][1]-l[a][1]
    x=l[a][0]
    y=l[a][1]
    c=0
    c1=0
    c2=0
    com=dx*y-dy*x
    for i in l:
        tp=dx*i[1]-dy*i[0]
        if tp>com:
            c+=1
        elif tp<com:
            c1+=1
        else:
            c2+=1
    if c+c1+c2!=n:
        print "WRONG"
    return min(c,c1)
for j in range(t):
    fo.write("Case #%d:\n"%(j+1))
    n=int(fi.readline())
    l=[]
    for i in range(n):
        x,y= map(int, fi.readline().split())
        l.append((x,y))
    for i in range(n):
        #print [f(l,i,x,n) for x in range(n)]
        if n!=1:
            fo.write("%d\n"%min([f(l,i,x,n) for x in range(n)]))
        else: 
            fo.write("0\n")
fi.close()
fo.close()
print "done"