import sys
T = int(sys.stdin.readline())

for _t in range(T):
    N = int(sys.stdin.readline())
    m = map(int, sys.stdin.readline().split())
    maxdec = 0
    for i in range(1, len(m)):
        maxdec = max(maxdec, m[i - 1] - m[i])

    ans1 = 0
    ans2 = 0
    for i in range(1, len(m)):
        d = m[i - 1] - m[i]
        if d > 0:
            ans1 += d
        ans2 += min(maxdec, m[i - 1])
    print "Case #%d: %d %d" % (_t + 1, ans1, ans2)
