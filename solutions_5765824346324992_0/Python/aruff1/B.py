for case in xrange(input()):
    B,N = map(int,raw_input().split())
    M = map(int,raw_input().split())
    lt = 0
    ht = 10**15
    mt = 1
    x = -1
    while lt<ht-1:
        t = (ht+lt)/2
        x = sum(t/m for m in M)
        if x>N-1: ht = t
        else:     lt = t
    t = lt
    x = sum(t/m for m in M)
    x=N-x-1
    i = sorted((-t%m,i) for i,m in enumerate(M))[x][1]
    print "Case #%d: %s"%(case+1,i+1)
