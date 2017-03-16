from math import ceil

T=int(input())
for i in range(1,T+1):
    data=[int(x) for x in input().split()]
    R=data[0]
    C=data[1]
    N=data[2]
    if R==3 and C==3:
        if N<=5:
            A=0
        elif N==6:
            A=3
        elif N<=8:
            A=(N-4)*2
        else:
            A=12
    elif R*C==15 and R!=1 and C!=1:
        if N<=8:
            A=0
        elif N==9:
            A=3
        elif N<=11:
            A=(N-7)*2
        elif N<=13:
            A=(N-11)*3+4*2
        else:
            A=(N-13)*4+2*3+4*2
    elif (N==0) or (R*C==1) or (ceil(R*C/2)>=N):
        A=0
    else:
        temp=N-ceil(R*C/2)
        if R==1 or C==1:
            A=temp*2
            if R*C%2==0:
                A-=1
        elif R==2 or C==2:
            if temp<=2:
                A=temp*2
            else:
                A=2*2+(temp-2)*3
        elif R==4 and C==4:
            if temp<=2:
                A=temp*2
            elif temp<=6:
                A=2*2+(temp-2)*3
            else:
                A=2*2+3*4+(temp-6)*4
        else:
            if temp<=2:
                A=temp*2
            elif temp<=5:
                A=2*2+(temp-2)*3
            else:
                A=2*2+3*3+4
    print("Case #{}: {}".format(i,A))
        
