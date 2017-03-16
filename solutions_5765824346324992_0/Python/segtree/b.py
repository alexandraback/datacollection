T = input()
for t in range(T):
    a = map(int, raw_input().split(' '))
    b = a[0]
    n = a[1]
    a = map(int, raw_input().split(' '))
    l = -1
    r = 100000000000000
    while r - l > 1:
        m = (l + r) / 2
        c = 0
        for i in range(b):
            c += m / a[i] + 1
        if c >= n:
            r = m
        else:
            l = m
    f = -1
    c = 0
    for i in range(b):
        c += r / a[i] + 1 - int(r % a[i] == 0)
    for i in range(b):
        c += int(r % a[i] == 0)
        if c == n:
            f = i
            break
    print 'Case #%d: %d' % (t + 1, f + 1)
