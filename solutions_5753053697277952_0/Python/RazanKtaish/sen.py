output=[]
alpha='ABCDEFGHIJKLMNOPQRSTUVWXYZ'
t = int(raw_input())
for a0 in xrange(t):
    n=int(raw_input())
    
    p=map(int,raw_input().split())
    
        
    
    Evacuate=''
    while max(p)>0:
        
        if sum(p)==3:
            max_s=max(p)
            i=p.index(max_s)
            p[i]=p[i]-1
            Evacuate +=alpha[i]
        else :
            max_s=max(p)
            i=p.index(max_s)
            p[i]=p[i]-1
            Evacuate +=alpha[i]
        
            max_s=max(p)
        
            j= p.index(max_s)
            p[j]=p[j]-1
            Evacuate +=alpha[j]
    
        Evacuate +=' '
    output.append(Evacuate)

for i in xrange(len(output)):
    print 'Case #'+str(i+1)+': '+output[i]
    
    
