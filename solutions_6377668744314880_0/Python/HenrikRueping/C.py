from math import *
f = open("C-small-attempt2.in",'r')
#f = open("C-large.in",'r')
#f = open("C-sample.in",'r')
output  = open("output.txt",'w')
cases =int(f.readline())

for case in range(1,cases+1):
    N= int(f.readline())
    P=[[int(j) for j in str.split(f.readline())] for i in range(N)]
    A =[0 for j in range(N)]
    for i in range(N):
        L=[]#0 for j in range(N-1)]
        for j in range(N):
            if i!=j:
                dx =P[j][0]-P[i][0]
                dy =P[j][1]-P[i][1]
                d = sqrt(dx**2+dy**2)
                angle= acos(dy/d)
                if dx<0:
                    angle=2*pi-angle
                L=L+[angle]
        L.sort()
        A[i]=L
    #precomputation done A[i][j] = angle of the line from i to j
    #print(A)
    res =[N for i in range(N)]
    for t in range(N):
        mini= N
        for i in range(N-1):
            j=(i+1)%(N-1)
            diff =A[t][j]-A[t][i]
            if diff<0:
                diff+=2*pi
            while(diff<=pi) and (mini>0):  
                if i==j:
                    mini =0
                j+=1
                if j==(N-1):
                    j=0
                diff =A[t][j]-A[t][i]
                if diff<0:
                    diff+=2*pi
                #print([t,i,j,mini,diff])
            mini=min(mini,N-1-(j-i) if j>i else i-j)
        res[t]=mini
    #print(N)
    #print(P)
    #print(A)
    if N<3:
        res= [0 for i in range(N)]
    output.write("Case #"+str(case)+":\n")
    print("Case #"+str(case)+":\n")
    for i in range(N):
        output.write(str(res[i])+"\n")    
output.close()
f.close()
