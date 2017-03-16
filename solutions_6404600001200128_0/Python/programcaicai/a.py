T = int(raw_input())




def solve(xs):
    ans1 = 0
    for e1,e2 in zip(xs,xs[1:]):
        if e1>e2:
            ans1 += e1-e2
    gap = max(max(e1-e2 for e1,e2 in zip(xs,xs[1:])),0)
    ans2 = sum(min(e,gap)  for e in xs[:-1])
    return ans1,ans2

for cas in range(T):
    n = int(raw_input())
    xs = [int(x) for x in raw_input().split()]
    ans1,ans2 = solve(xs)
    
    print 'Case #%d: %d %d'%(cas+1,ans1,ans2)
