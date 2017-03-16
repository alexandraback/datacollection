T = int(raw_input())
for _case_ in xrange(T):
    N = int(raw_input())
    m = [int(_) for _ in raw_input().split()]
    ans1 = 0
    rate = 0
    diffs = [0]*(N-1)
    for i in xrange(1, N):
        diff = m[i-1] - m[i]
        diffs[i-1] = diff
        if diff > 0:
            ans1 += diff
        if diff > rate:
            rate = diff
    ans2 = 0
    for i in xrange(N-1):
        ans2 += min(m[i], rate)
    print "Case #"+str(_case_+1)+": "+str(ans1)+" "+str(ans2)

