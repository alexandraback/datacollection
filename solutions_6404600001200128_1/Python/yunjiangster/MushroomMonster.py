import sys,re,math

def Min1(Ms):
    prev_m = None
    next_m = None
    eaten = 0
    for i,m in enumerate(Ms):
        if i < len(Ms) -1:
            next_m = Ms[i+1]
        eaten += max(m - next_m,0)
    return eaten

def Min2(Ms):
    # try different rates
    for rate in xrange(0,(max(Ms) * 10 +1)):
        eaten = 0
        left = 0
        next_m = None
        succeed = True
        for i,m in enumerate(Ms):
            if i < len(Ms) -1:
                eaten += min(m,rate)
                left = m - min(m,rate)
                next_m = Ms[i+1]
                if left > next_m:
                    succeed = False
                    break
        if succeed: return eaten

T = int(sys.stdin.readline().strip('\n'))
for q in xrange(T):
    N = int(sys.stdin.readline().strip('\n'))
    Ms = map(int,sys.stdin.readline().strip('\n').split())
    ret1= Min1(Ms)
    ret2 = Min2(Ms)
    print 'Case #%d: %d %d'%(q+1,ret1,ret2)

