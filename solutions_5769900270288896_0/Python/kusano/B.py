T = input()
for t in range(T):
    R,C,N = map(int, raw_input().split())
    ans = 2*R*C
    for b in range(2**(R*C)):
        if sum(b>>i&1 for i in range(R*C))==N:
            A = [[0]*C for y in range(R)]
            for y in range(R):
                for x in range(C):
                    A[y][x] = b&1
                    b >>= 1
            c = 0
            for y in range(R-1):
                for x in range(C):
                    if A[y][x] and A[y+1][x]:
                        c += 1
            for y in range(R):
                for x in range(C-1):
                    if A[y][x] and A[y][x+1]:
                        c += 1
            ans = min(ans, c)
    print "Case #%s: %s"%(t+1, ans)
