T = int(input())
for tc in range(1,T + 1):
    N = int(input())
    P = list(map(int,input().split()))
    first = 0
    second = 0
    r = 0
    for i in range(N - 1):
        d = P[i] - P[i + 1]
        first+= (d)if (d > 0) else 0
        r = max(r,d if (d > 0) else 0)
    for i in range(N-1):
        second += min(r,P[i])
    print("Case #{0}: {1} {2}".format(tc,first,second))