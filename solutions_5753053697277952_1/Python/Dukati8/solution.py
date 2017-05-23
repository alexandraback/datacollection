T=int(input())
for i in range (T):
    alfabet="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    N=int(input())
    line2=input().split()
    P=[]
    maxi=0
    for j in range (N):
        P.append(int(line2[j]))
        maxi=max(maxi,P[-1])
    out=""
    while (maxi>0):
        x=P.count(maxi)
        if (x==0):
            maxi-=1
        elif (x==1):
            y=P.count(maxi-1)
            if (y==1):
                remove1=P.index(maxi)
                P[remove1]-=1
                out+=" " + alfabet[remove1]
            else:
                remove1=P.index(maxi)
                P[remove1]-=2
                out+=" " + alfabet[remove1] + alfabet[remove1]
        elif (x==3):
            remove1=P.index(maxi)
            P[remove1]-=1
            out+=" " + alfabet[remove1]
        else:
            remove1=P.index(maxi)
            P[remove1]-=1
            remove2=P.index(maxi)
            P[remove2]-=1
            out+=" " + alfabet[remove1] + alfabet[remove2]
    print("Case #" + str(i+1) + ":" + out)
            
    
    
