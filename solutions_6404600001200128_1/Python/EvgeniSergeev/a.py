import sys
stdin = sys.stdin

T = int(stdin.readline())
for icase in range(1, T+1):
    N = int(stdin.readline())
    ms = map(int, stdin.readline().strip().split())

    r1 = 0
    r2 = 0
    maxrate = 0
    for i in range(1, N):
        if ms[i] < ms[i-1]:
            r1 += ms[i-1] - ms[i]
        maxrate = max(maxrate, ms[i-1] - ms[i])
    for i in range(1, N):
        r2 += min(maxrate, ms[i-1])

    print "Case #%d: %d %d" % (icase, r1, r2)

    
