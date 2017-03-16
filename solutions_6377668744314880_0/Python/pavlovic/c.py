import sys

t = int(sys.stdin.readline().strip())

for i in range(t):
    n = int(sys.stdin.readline().strip())
    x = []
    y = []
    for j in range(n):
        p, q = sys.stdin.readline().strip().split()
        x.append(int(p))
        y.append(int(q))

    print "Case #%d:" % (i + 1)
    for j in range(n):
        m = None
        for k in range(n):
            p = 0
            q = 0
            if k == j:
                continue

            for l in range(n):
                cross = (x[k] - x[j]) * (y[l] - y[j]) - (y[k] - y[j]) * (x[l] - x[j])
                if cross < 0:
                    p += 1
                if cross > 0:
                    q += 1

            if ((m is None) or (m > min(p, q))):
                m = min(p, q)
        print 0 if m is None else m
