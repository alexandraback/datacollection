_42 = int(raw_input())
for _41 in xrange(_42):
    N = int(raw_input())
    m = map(int, raw_input().split())
    ans1 = 0
    for i in xrange(N-1):
        ans1 += max(m[i] - m[i+1], 0)

    rate = 0
    for i in xrange(N-1):
        if m[i+1] >= m[i]: continue
        rate = max(rate, m[i]-m[i+1])
    ans2 = 0
    for i in xrange(N-1):
        ans2 += min(rate, m[i])

    print "Case #{}: {} {}".format(_41+1, ans1, ans2)
