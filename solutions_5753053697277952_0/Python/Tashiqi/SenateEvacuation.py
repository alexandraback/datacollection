T=int(input())
for t in range(T):
    res = ""
    N=int(input())
    tab = []
    v=list(map(int,input().split()))
    for n in range(N):
        tab+=[[v[n],n]]
    l=max(tab)
    while l[0]!=0:
        l[0]-=1
        res+=chr(65+l[1])
        l=max(tab)
        if l[0]!=0:
            l[0]-=1
            res+=chr(65+l[1]) + " "
        l=max(tab)
    print("Case #" + str(t+1) + ":", res[:-1] if res[-1]==" " else res[:-3]+" "+res[-3]+res[-1])
