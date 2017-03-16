CurrentPathIn = "small.in"
CurrentPathOut = "output"

fr = open(CurrentPathIn,"r")
fw = open(CurrentPathOut,"w")  

T = int(fr.readline())
for t in range(T):
    R, C, N = list(map(int,fr.readline().split()))
    res = 0
    if ((R*C) % 2 == 0):
        P = N - (R*C)//2
        if P <= 0:
            res = 0
        elif P<=2:
            res += 2*P
        elif P<=R + C  -2:
            res += 4
            res += 3*(P-2)
        else:
            res += 4
            res += 3*(R + C -4)
            res += 4*(P - (R + C - 2))
    else:
        res1 = 0
        res2 = 0
        P = N - ((R*C) + 1)//2
        if P <= 0:
            res1 = 0
        elif P<=R + C  -2:
            res1 += 3*P
        else:
            res1 += 3*(R + C - 2)
            res1 += 4*(P - (R + C - 2))
        P = N - ((R*C) - 1)//2
        if P <= 0:
            res2 = 0
        elif P<=4:
            res2 += P*2
        elif P<=R + C  -2:
            res2 += 8
            res2 += 3*(P-4)
        else:
            res2 += 8
            res2 += 3*(R + C - 6)
            res2 += 4*(P - (R + C - 2))
        res = min(res1,res2)
    if R==2 or C==2:
        res = 0
        P = N - (R*C)//2
        if P <= 0:
            res = 0
        elif P<=2:
            res += 2*P
        else:
            res += 4
            res += 3*(P-2)
    if R==1 or C==1:
        res = 0
        if (R*C) %2 == 1:
            if N <= ((R*C) + 1)//2:
                res = 0
            else:
                res = 2* (N - ((R*C) + 1)//2)
        else:
            P = N - (R*C)//2
            if P<=0:
                res = 0
            elif P == 1:
                res +=1
            else:
                res += 1
                res += 2*(P - 1)
    print(res)
    fw.write("Case #"+str(t+1)+": "+str(res)+"\n")
fr.close()
fw.close()
