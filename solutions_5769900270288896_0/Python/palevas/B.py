from numpy import zeros

T = int(raw_input())

def neis(r, c, arr):
    return arr[r-1, c] + arr[r+1, c] + arr[r, c-1] + arr[r, c+1]

def add(max_ns, arr, R, C, N):
    add_ns = 0
    add_zh = 0
    for r in range(1, R + 1):
        for c in range(1, C + 1):
            if arr[r, c] == 0:
                ns = neis(r, c, arr)
                
                if ns <= max_ns:
                    #print r, c, ns, max_ns
                    add_ns += ns
                    add_zh += 1
                    arr[r,c] = 1
                    if add_zh == N:
                        return add_zh, add_ns
    return add_zh, add_ns

for tc in range(1, T+1):
    R, C, N = [int(a) for a in raw_input().strip().split()]
    N2 = N
    matr = zeros((R+2,C+2), dtype=int)
    
    noise = 0
    
    add_zh, add_ns = add(0, matr, R, C, N)
    noise += add_ns
    N -= add_zh
    if N > 0:
        add_zh, add_ns = add(2, matr, R, C, N)
        noise += add_ns
        N -= add_zh
    if N > 0:
        add_zh, add_ns = add(3, matr, R, C, N)
        noise += add_ns
        N -= add_zh

    if N > 0:
        add_zh, add_ns = add(4, matr, R, C, N)
        noise += add_ns
        N -= add_zh
    


    N = N2
    matr = zeros((R+2,C+2), dtype=int)
    
    noise2 = 0
    matr[1,1]=1
    matr[0,2]=-1
    matr[2,0]=-1
    add_zh, add_ns = add(0, matr, R, C, N)
    noise2 += add_ns
    N -= add_zh
    matr[1,1]=0
    matr[0,2]=0
    matr[2,0]=0
    if N > 0:
        add_zh, add_ns = add(2, matr, R, C, N)
        noise2 += add_ns
        N -= add_zh
    if N > 0:
        add_zh, add_ns = add(3, matr, R, C, N)
        noise2 += add_ns
        N -= add_zh

    if N > 0:
        add_zh, add_ns = add(4, matr, R, C, N)
        noise2 += add_ns
        N -= add_zh

    
    print "Case #%d: %d" % (tc, min(noise,noise2))
