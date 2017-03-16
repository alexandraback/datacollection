#f = open("B-small-attempt1.in",'r')
f = open("B-large.in",'r')
#f = open("B-sample.in",'r')
output  = open("output.txt",'w')
cases =int(f.readline())

def fu(B,t):
    ret =0
    for i in range(len(B)):
        ret+=t//B[i]+ (1 if t%B[i]!=0 else 0)
    return ret

def BinSearch(N,B):
    L=0
    R=1000000000000000
    while (R-L>1):
        #print([L,R])
        M=(L+R)//2
        if(fu(B,M)>=N):
            R=M
        else:
            L=M
    return L

for case in range(1,cases+1):
    [B,N]=[int(j) for j in str.split(f.readline())]
    M=[int(j) for j in str.split(f.readline())]
    t=BinSearch(N,M)
    free =[j+1 for j in range(len(M)) if ((t)%M[j]==0)]
    diff = N-fu(M,t)
    #print([B,N])
    #print(M)
    #print("T:"+str(t))
    #print(N)
    #print(free)
    #print(diff)
    output.write("Case #"+str(case)+": "+str(free[diff-1])+"\n")
output.close()
f.close()
