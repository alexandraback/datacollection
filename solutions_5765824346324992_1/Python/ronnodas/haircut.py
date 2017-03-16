def number(time,ms):
    ret = 0
    last = 0
    indices = []
    for (i,m) in enumerate(ms):
        n = time//m
        if (n*m) > last:
            last = n*m
            indices = [i]
        elif (n*m) == last:
            indices.append(i)
        ret += n+1
    # print(time,ret,indices)
    return (ret,indices)

def search(n,ms):
    low,high = -1, (n+1)*min(ms) #answer is in (low,high]
    while low+1<high:
        mid = (low+high)//2
        test,_ = number(mid,ms)
        if test < n:
            low = mid
        else:
            high = mid
    up,indices = number(high,ms)
    return indices[n-up-1]+1

T = int(input())
for case in range(1,T+1):
    B,N = (int(x) for x in input().split())
    ms = [int(x) for x in input().split()]
    ans = search(N,ms)
    print("Case #",case,": ",ans,sep = '')
