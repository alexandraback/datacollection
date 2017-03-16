inn=open("c:/downloads/in.in",'r')
rs=open("c:/downloads/rs.rs",'w')
#print(inn.readline())
#rs.write()
T=int(inn.readline())
def streq(s1,s2):
    n1=len(s1)
    n2=len(s2)
    if n1!=n2:
        return False
    for i in range(n1):
        if s1[i]!=s2[i]:
            return False
    return True
def cumdist(l,x):
    n=len(l)
    D=0
    for i in range(n):
        D+=abs(l[i]-x)
    return D
def numoves(l):
    n=len(l)
    mn=min(l)
    mx=max(l)
    D=cumdist(l,mn)
    for i in range(mn,mx+1):
        if cumdist(l,i)<D:
            D=cumdist(l,i)
    return D
        
def nodups(s):
    charseq=str('')
    n=len(s)
    prevc='Q'
    for i in range(n):
        if s[i]==prevc:
            continue
        else:
            charseq=charseq+s[i]
            prevc=s[i]
    return charseq
def rlist(s,cs):
    #returns repatlist of chars in cs in s, assumes skeleton of s is cs
    cl=[]
    n=len(s)
    k=0
    r=0
    for i in range(n):
        if(s[i]==cs[k]):
           r+=1
        else:
            cl.append(r)
            r=1
            k+=1
    cl.append(r)
    return cl
for I in range(T):
    N=int(inn.readline())
    s=[]
    for i in range(N):
        s.append(inn.readline())
   # n0=len(s[0])
   # if s[0][n0-1]!='\n':
   #     s[0]+='\n'
    charseq=nodups(s[0])
    #now charseq is a list of chars all other strings must match
    m=len(charseq)
    possible=True
    l=[] #will be a len N list of length m lists of char repeat numbers
    for i in range(N):
        cs=s[i]#current string
        nd=nodups(cs)#nodups version
        n0=len(nd)
        if nd[n0-1]!='\n':
             nd+='\n'
        if nd!=charseq:
          #  print("nd="+repr(nd))
          #  print('charseq='+repr(charseq))
            possible=False
            break
        else:
            l.append(rlist(cs,charseq))
    if not possible:
        rs.write("Case #"+str(I+1)+": Fegla Won\n")
    else:
        nm=0
        for j in range(m-1):
            lj=[l[i][j] for i in range(N)]
            nm+=numoves(lj)
        rs.write("Case #"+str(I+1)+": "+str(nm)+'\n')
    #now either it's impossible to rearrange or l contains a list of lists
    #of repeats of the core charseq inside each of N strings
inn.close()
rs.close()
