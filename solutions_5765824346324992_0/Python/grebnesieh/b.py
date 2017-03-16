for t in xrange(input()):
    b, n = map(int, raw_input().split())
    B = map(int, raw_input().split())
    lo = 0
    hi = 10 ** 14
    if n <= b:
        ans = n
    else:
        while True:
            mi = (lo + hi)/2
            nx = sum([(mi + 1)/x + 1 for x in B])
            nw = sum([mi/x + 1 for x in B])
            if nx >= n and nw < n:
                break
            elif nx < n:
                lo = mi + 1
            else:
                hi = mi
        ans = [i + 1 for (i, x) in enumerate(B) if (mi + 1) % x == 0]
        ans = ans[n - nw - 1]
    print "Case #" + str(t + 1) + ": " + str(ans)
