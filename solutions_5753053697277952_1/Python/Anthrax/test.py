import sys
sys.setrecursionlimit(100000000)

answer = ""

A = list("ABCDEFGHIJKLMNOPQRSTUVWXYZ")

def solve(N,P):
    left = sum([x[0] for x in P])

    S = [];
    
    while sum([x[0] for x in P])>0:
        for i in range(N):
            if P[i][0] > 0:
                P[i][0] -= 1
                S.append(P[i][1])

    S.reverse()
    b = ""
    if len(S) % 2 == 1:
        print(A[S[0]], end='')
        del S[0]
        b = " "
    while S:
        print(b+A[S[0]]+A[S[1]], end='')
        del S[0:2]
        b = " "
    print()
    
    #P.sort()
    #print(left)
    #if left % 2 == 1:
    #    P[0][0] -= 1
    #    left -= 1
    #
    #while left>0:
    #    P.sort()
    #    if P[0][0] == 1:
    #        P[0]
    #    
    #return 0  



T = int(input())

for t in range(T):
    N = int(input())
    P = [[int(x),i] for i,x in enumerate(input().split())]
    
    print("Case #%d: " % (t+1), end='')
    ans = solve(N,P)
    
    
