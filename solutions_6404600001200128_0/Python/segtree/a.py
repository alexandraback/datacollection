T = input()
for t in range(T):
    n = input()
    l = map(int, raw_input().split(' '))
    a = 0
    b = -1
    for i in range(n - 1):
        a += l[i] - l[i + 1] if l[i] > l[i + 1] else 0
    for i in range(10001):
        flag = 1
        c = 0
        for j in range(n - 1):
            if l[j + 1] < l[j] - i:
                flag = 0
                break
            else:
                c += i if l[j] > i else l[j]
        if flag and (b > c or b == -1):
            b = c
    print 'Case #%d: %d %d' % (t + 1, a, b)
