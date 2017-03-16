tt = int(raw_input())
for t in xrange(1, tt+1):
    n = int(raw_input())
    x = map(int, raw_input().split())
    ansa = 0
    rateb = 0
    ansb = 0
    for i in xrange(1, n):
        if x[i] < x[i-1]:
            ansa += x[i-1] - x[i]
            rateb = max(rateb, x[i-1] - x[i])
    for i in xrange(1, n):
        ansb += min(rateb, x[i-1])
    print "Case #%d: %d %d" % (t, ansa, ansb)