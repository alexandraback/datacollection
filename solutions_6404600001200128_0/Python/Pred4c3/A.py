T=int(input())
for case_id in range(1,T+1):
    N=int(input())
    M = list(map(int,input().split()))

    res1,res2,maxdel = 0,0,0
    for i in range(1,len(M)):
        res1 += max(0,M[i-1]-M[i])
        maxdel = max(maxdel,M[i-1]-M[i])

    if maxdel > 0:
        res2 = sum(min(m,maxdel) for m in M[:-1])

    print('Case #%d: %d %d' % (case_id, res1, res2))
    import sys
    print('Case #%d: %d %d' % (case_id, res1, res2), file=sys.stderr)
