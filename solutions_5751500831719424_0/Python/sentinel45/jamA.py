def median(a):
    return sorted(a)[len(a)/2]
def calc(a):
    m=median(a)
    return sum(abs(a[i]-m) for i in xrange(len(a)))
fin=open("input.txt",'r')
fout=open("output.txt",'w')
t=int(fin.readline())
for T in xrange(1,t+1):
    n=int(fin.readline())
    ar=[fin.readline().strip()+'#'for _ in xrange(n)]
    rep=['' for _ in xrange(n)]
    cnt=[[] for _ in xrange(n)]
    for i in xrange(n):
        ct=1        
        for j in xrange(len(ar[i])-1):
            if ar[i][j]==ar[i][j+1]:
                ct+=1                
            else:
                rep[i]+=ar[i][j]
                cnt[i].append(ct)
                ct=1
    s=rep[0]
    if all(rep[i]==rep[0] for i in xrange(n)):
        ans=0
        for j in xrange(len(rep[0])):
            ans+=calc([cnt[i][j] for i in xrange(n)])
        fout.write("Case #"+str(T)+': '+str(ans)+"\n")
    else:
        fout.write("Case #"+str(T)+': '+'Fegla Won'+'\n')
    
fin.close()
fout.close()
