# You lost the game.
R = []
A = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
f = open("input.txt","r")
T = int(f.readline())
for k in range(T):
    print(k)
    n = int(f.readline())
    P = list(map(int, f.readline().strip().split()))
    P = [[i,P[i]] for i in range(n)]
    r = ""
    while max([P[i][1] for i in range(n)]) > 0:
        m = P[0]
        i = 0

        def ct(a):
            return a[1]

        P.sort(key=ct,reverse=True)
        if len(P) == 2:
            if P[0][1] > P[1][1]:
                r = r + A[P[0][0]] + " "
                P[0][1] -= 1
            else:
                r = r + A[P[0][0]] + A[P[1][0]] + " "
                P[0][1] -= 1
                P[1][1] -= 1
        elif len(P) == 3:
            if P[0][1] == P[1][1] and P[1][1] == P[2][1] and P[0][1] == 1:
                r  = r + A[P[0][0]] + " " + A[P[1][0]] + A[P[2][0]] + " "
                P[0][1] -= 1
                P[1][1] -= 1
                P[2][1] -= 1
            else:
                r = r + A[P[0][0]] + A[P[1][0]] + " "
                P[0][1] -= 1
                P[1][1] -= 1
        else:
            r = r + A[P[0][0]] + A[P[1][0]] + " "
            P[0][1] -= 1
            P[1][1] -= 1
    R = R + [r]                
            

f.close()
f = open("output.txt","w")
for k in range(T):
    f.write("Case #"+str(k+1)+": "+str(R[k])+"\n")
f.close()

    
