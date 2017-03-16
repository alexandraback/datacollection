fi=open("a.in")
t=int(fi.readline())
fo=open("out","w")
for j in range(t):
    n=int(fi.readline())
    l= map(int, fi.readline().split())
    l1=[]
    for i in range(1,n):
        l1.append(0 if l[i]>l[i-1] else l[i-1]-l[i])
    mx=max(l1)
    fo.write("Case #%d: %d %d\n"%(j+1,sum(l1),sum([(x if x<mx else mx) for x in l[0:n-1]])))
fi.close()
fo.close()
print "done"