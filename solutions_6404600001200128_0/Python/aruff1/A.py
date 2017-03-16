for t in xrange(input()):
    N = input()
    M = map(int,raw_input().split())
    y = z = 0
    mx = 0
    for i in xrange(1,N):
        x = M[i-1]-M[i]
        mx = max(mx,x)
        if x>0: y+=x
    for i in xrange(1,N):
        z+=min(M[i-1],mx)
    print "Case #%d: %s %s"%(t+1,y,z)
