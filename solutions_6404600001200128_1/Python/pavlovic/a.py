import sys

t = int(sys.stdin.readline().strip())

for i in range(t):
    n = int(sys.stdin.readline().strip())
    m = sys.stdin.readline().strip().split()
    for j in range(n):
        m[j] = int(m[j])

    p = 0
    max_diff = 0
    for j in range(n - 1):
        p += max(0, m[j] - m[j + 1])
        max_diff = max(max_diff, m[j] - m[j + 1])

    q = 0
    for j in range(n - 1):
        q += min(m[j], max_diff)

    print "Case #%d: %d %d" % (i + 1, p, q)
