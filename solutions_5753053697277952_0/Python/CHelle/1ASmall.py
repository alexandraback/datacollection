f = open("1AsInput.in","r")
T = int(f.readline())
##import sys
##T = int(sys.stdin.readline())
n = ""
for i in range (0,T):
    N = int(f.readline())
    P = f.readline().split()
##    N = int(sys.stdin.readline())
##    P = sys.stdin.readline().split()
    t = ""
    if N == 2:
        for j in range (0,int(P[0])):
            t = t+" AB"
    else:
        m = 0
        for j in range (0,len(P)):
            P[j] = int(P[j])
            m = m+P[j]
        while m > 3:
            t = t+" "
            x = P.index(max(P))
            t = t+chr(x+65)
            P[x] = P[x]-1
            x = P.index(max(P))
            t = t+chr(x+65)
            P[x] = P[x]-1
            m = m-2
        if m == 2:
            t = t+" "
            x = P.index(max(P))
            t = t+chr(x+65)
            P[x] = P[x]-1
            x = P.index(max(P))
            t = t+chr(x+65)
            P[x] = P[x]-1
        if m == 3:
            t = t+" "
            x = P.index(max(P))
            t = t+chr(x+65)
            P[x] = P[x]-1
            t = t+" "
            x = P.index(max(P))
            t = t+chr(x+65)
            P[x] = P[x]-1
            x = P.index(max(P))
            t = t+chr(x+65)
            P[x] = P[x]-1
    n = n+"Case #"+str(i+1)+":"+t+"\n"
n = n.strip()
##print(n)
f.close()
f = open("1AsOutput.txt","w")
f.write(n)
f.close()
