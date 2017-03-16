def wow(i):
    s=sum(i)
    if s==1: return chr(65+i.index(1))
    m=max(i)
    j=i.index(m)
    i[j]=m-1
    return (chr(65+j) if s%2==0 else chr(65+j)+" ")+wow(i)
    
    
def sleep(n):
    i=list(map(int,n.split()))
    wow=[]
    while True:
        s=sum(i)
        if s==1:
            wow.append(chr(65+i.index(1)))
            break
        m=max(i)
        j=i.index(m)
        i[j]=m-1
        wow.append(chr(65+j) if s%2==0 else chr(65+j)+" ")
    return "".join(wow)
    

inp=open("1e.txt")
x=int(inp.readline()[:-1])
out=open("1ea.txt","w")
case=1
for n in range(x):
    inp.readline()
    out.write("Case #"+str(case)+": "+str(sleep(inp.readline()[:-1]))+"\n")
    case+=1
inp.close()
out.close()
    
