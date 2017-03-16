for test in xrange(int(raw_input().strip())):
    b, n = map(int, raw_input().strip().split())
    m = map(int, raw_input().strip().split())
    le = 0
    ri = 10000000000000005
    while ri > le + 1:
        mi = (le + ri) / 2
        c = 0
        for t in m:
            c += (mi + t - 1) / t
        if c >= n:
            ri = mi
        else:
            le = mi
    c = n
    for t in m:
        c = c - (le + t - 1) / t
    for i in xrange(b):
        if le % m[i] == 0:
            c = c - 1
        if c == 0:
            print "Case #%d: %d" % (test + 1, i + 1)
            break
