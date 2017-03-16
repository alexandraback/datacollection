for test in range(1, int(input()) + 1):
    n = int(input())
    a = list(map(int, input().split()))

    f = 0
    mx = 0
    for i in range(1, n):
        if a[i] < a[i - 1]:
            f += a[i - 1] - a[i]
            mx = max(mx, a[i - 1] - a[i])

    s = 0 
    if mx > 0:
        for i in range(1, n):
            if a[i - 1] >= mx:
                s += mx
            else:
                s += a[i - 1]
    print('Case #%d: %d %d' % (test, f, s))
