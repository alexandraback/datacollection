T = int(raw_input())

for t in xrange(T):
    N = int(raw_input())
    m = [int(x) for x in raw_input().split(' ')]
    
    a = 0
    r = 0
    for i in xrange(1, len(m)):
        if m[i] < m[i - 1]:
            a += m[i - 1] - m[i]
            r = max(r, m[i - 1] - m[i])

    b = 0
    for x in m[:-1]:
        b += min(r, x)

    print 'Case #' + str(t + 1) + ': ' + str(a) + ' ' + str(b)
