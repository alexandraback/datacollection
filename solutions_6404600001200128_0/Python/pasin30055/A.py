for test in xrange(int(raw_input().strip())):
    n = int(raw_input().strip())
    L = map(int, raw_input().strip().split())
    a = 0
    b = 0
    c = 0
    for i in xrange(n - 1):
        a = a + max(0, L[i] - L[i + 1])
        b = max(b, L[i] - L[i + 1])
    for i in xrange(n - 1):
        c = c + min(b, L[i])
    print "Case #%d: %d %d" % (test + 1, a , c)
