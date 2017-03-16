from sys import stdin
T = int(stdin.readline())
for case in xrange(1, T+1):
    n = int(stdin.readline())
    m = map(int, stdin.readline().split(' '))
    y = z = maxd = 0
    for i in xrange(len(m) - 1):
        if m[i+1] < m[i]:
            y += m[i] - m[i+1]
            maxd = max(maxd, m[i] - m[i+1])
    for i in xrange(len(m) - 1):
        z += min(maxd, m[i])
    print "Case #%d: %d %d" % (case, y, z)
