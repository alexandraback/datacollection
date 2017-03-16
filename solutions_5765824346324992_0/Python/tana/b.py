tt = int(raw_input())
for t in xrange(1, tt+1):
    (b, n) = map(int, raw_input().split())
    x = map(int, raw_input().split())
    pr = 1
    for num in x:
        pr *= num
    ppl = 0
    for num in x:
        ppl += pr/num
    n -= 1
    n %= ppl
    n += 1
    y = [0]*b
    for i in xrange(n):
        for j in xrange(b):
            if y[j] == 0:
                y[j] = x[j]
                ans = j
                break
        msub = min(y)
        for j in xrange(b):
            y[j] -= msub
    print "Case #%d: %d" % (t, ans+1)