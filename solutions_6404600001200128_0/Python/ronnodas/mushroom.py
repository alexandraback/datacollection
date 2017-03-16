T = int(input())
for case in range(1,T+1):
    N = int(input())
    ms = [int(x) for x in input().split()]
    ds = [max(ms[i-1]-ms[i],0) for i in range(1,N)]
    # print(ds)
    ans1 = sum(ds)
    rate = max(ds)
    # print(rate)
    ans2 = sum([min(rate,m) for m in ms[:-1]])
    print("Case #",case,": ",ans1,' ',ans2,sep = '')

