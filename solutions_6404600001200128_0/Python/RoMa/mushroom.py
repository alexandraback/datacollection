
T = int(raw_input())

for x in xrange(1, T+1):
    N = int(raw_input())
    M = [int(m) for m in raw_input().split()]
    y = 0
    rate = 0
    for i in xrange(1, N):
        d = M[i] - M[i-1]
        rate = max(-d, rate)
        y += max(0, -d)
    
    z = 0
    for i in xrange(0, N - 1):
        z += min(rate, M[i])
    
    print 'Case #{}: {} {}'.format(x, y, z)
    
        
        
