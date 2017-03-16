
for _t in range(input()):
    _=input()
    M=map(int,raw_input().split())
    D=[max(0,M[i-1]-M[i]) for i in range(1,len(M))]
    r1=sum(D)
    d=max(D)
    r2=sum(min(m,d) for m in M[:-1])
    print 'Case #{}: {} {}'.format(_t+1,r1,r2)
