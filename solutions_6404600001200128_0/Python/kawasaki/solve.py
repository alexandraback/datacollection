T = int(raw_input())
for test_index in xrange(T):
    N = int(raw_input())
    m = map(int, raw_input().split())

    y = 0
    for i in xrange(N - 1):
        y += max(m[i] - m[i + 1], 0)

    d = max(max(m[i] - m[i + 1], 0) for i in xrange(N - 1))
    z = 0
    for i in xrange(N - 1):
        z += min(d, m[i])
    print 'Case #{}: {} {}'.format(test_index + 1, y, z)
