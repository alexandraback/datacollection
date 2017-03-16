#f = open("B-small-attempt2.in",'r')
f = open("B-large.in",'r')
#f = open("B-sample.in",'r')
output  = open("output.txt",'w')
cases =int(f.readline())
for case in range(1,cases+1):
    [R,C,N]= [int(s) for s in str.split(f.readline())]
    #print([R,C,N])
    odd = R*C%2!=0
    ret=0
    if min(R,C)==1:
        if R>1:
            [R,C]=[C,R]
        ret =0
        N-= min(N,(C+1)//2)
        #print([N,ret])
        if C%2==0:
            ret = max(2*N-1,0)
        else:
            ret =2*N
        #print([N,ret])
    else:
        if odd:
            Nbuf =N
        #1st with corners filled:
            #print(N)
            N=N-min(N,(R*C+1)//2)
            ret1=0
        #print([N,ret1])
            if N>0:
                circ = 2*(R//2+C//2)
                ret1 += 3*min(circ,N)
                N-=min(circ,N)
                #print([N,ret1])
                ret1 += 4*N
                #print([N,ret1])
            #corners empty:
            N=Nbuf
            N=N-min(N,(R*C)//2)
            ret2=0
            if N>0:
                #print([N,ret2])
                ret2 += 2*min(4,N)
                N-= min(4,N)
                #print([N,ret2])
                circ = 2*(R//2+C//2-2)
                ret2 += 3*min(circ,N)
                N-=min(circ,N)
                #print([N,ret2])
                ret2 += 4*N
                #print([N,ret2])
            ret = min(ret1,ret2)
        else:
            ret = 0
            N=N-min(N,(R*C)//2)
            circ =R+C-4
            ret += 2*min(2,N)
            N-= min(2,N)
            #print([N,ret])
            ret += 3*min(circ,N)
            N-=min(circ,N)
            #print([N,ret])
            ret += 4*N
            #print([N,ret])
    #print(N)
    #print(S)
    #print(diff)
    output.write("Case #"+str(case)+": "+str(ret)+"\n")
    print("Case #"+str(case)+": "+str(ret))
output.close()
f.close()
