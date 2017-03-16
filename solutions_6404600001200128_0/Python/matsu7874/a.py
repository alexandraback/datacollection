T = int(input())
for test_case in range(T):
    N = int(input())
    M = [int(x) for x in input().split()]
    y_cnt = 0
    z_cnt = 0
    for i in range(1,N):
        y_cnt += max(M[i-1]-M[i],0)
    z_rate = max([M[i-1]-M[i] for i in range(1,N)])
    for i in range(0,N-1):
        z_cnt += min(z_rate,M[i])
    print('Case #'+str(test_case+1)+': '+str(y_cnt),z_cnt)
