T = int(raw_input())

for t in xrange(T):
    b, n = [int(x) for x in raw_input().split(' ')]
    m = [int(x) for x in raw_input().split(' ')]


    def numServedBy(endTime):
        total = 0
        for x in m:
            if endTime % x == 0:
                total += endTime // x
            else:
                total += endTime // x  + 1
        return total

    lo = 0
    hi = max(m) * n
    while lo < hi:
        mid = (lo + hi) // 2
        if numServedBy(mid) < n:
            lo = mid + 1
        else: 
            hi = mid

    #for i in xrange(20): print i, numServedBy(i)

    time = lo - 1
    numServed = numServedBy(time)
    assert numServed < n
    #print time, numServed, n
    delta = n - numServed
    def timeTilNext(i, x):
        if time % x == 0:
            return 0
        return ((time // x) + 1) * x - time
    #print sorted(enumerate(m), key=lambda x: (timeTilNext(x[0], x[1]), x[0]))
    ans = sorted(enumerate(m), key=lambda x: (timeTilNext(x[0], x[1]), x[0]))[delta - 1][0] + 1

    print 'Case #' + str(t + 1) + ': ' + str(ans)
