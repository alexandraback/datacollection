def solve(n, m):
    # method 1
    ret1 = 0
    prev = m[0]
    for i in xrange(1, n):
        curr = m[i]
        if curr < prev:
            ret1 += (prev - curr)
        prev = curr

    # method 2
    ret2 = 0
    max_diff = 0
    prev = m[0]
    for i in xrange(1, n):
        curr = m[i]
        if (prev - curr) > max_diff:
            max_diff = (prev - curr)
        prev = curr
        
    # max_diff is the greatest # of mushrooms we eat in a 10-second period
    prev = m[0]
    for i in xrange(1, n):
        curr = m[i]
        diff = prev - curr
        ret2 += min(max_diff, prev)
        prev = curr

    return '%d %d' % (ret1, ret2)



t = int(raw_input())
test_cases = []

for i in xrange(t):
    n = int(raw_input())
    m = map(int, raw_input().split(' '))
    test_cases.append((n, m))

for i in xrange(t):
    n, m = test_cases[i]
    print "Case #%d: %s" % (i + 1, solve(n, m))
