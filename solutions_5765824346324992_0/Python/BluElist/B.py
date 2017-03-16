from fractions import gcd

T = int(input())

for CC in range(T):
    B, N = map(int,input().split())
    M = list(map(int,input().split()))

    GT, loopc = 1, 0
    for x in M:
        a = gcd(GT, x)
        GT *= x/a

    for x in M:
        loopc += int(GT/x)

    N = N % int(loopc)

#    print(GT,loopc, N)

    Now = [0]*B
    Ans = 0

    if N == 0:
        mins, point = M[0], 0
        for x in range(B):
            if M[x] <= mins:
                mins = M[x]
                point = x
        Ans = point+1
        
    while Ans == 0:
        for x in range(B):
            if Now[x] == 0:
                Now[x] = M[x]
                N -= 1
            if N == 0:
                Ans = x+1
                break
        
        minN = min(Now)
        Now = list(map(lambda x:x-minN,Now))

    print('Case #{}: {}'.format(CC+1,Ans))
    
