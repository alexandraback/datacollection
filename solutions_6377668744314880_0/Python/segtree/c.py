T = input()
p = []
n = 0

def check(x0, l):
    a = [p[x0]]
    for i in range(n):
        if i != x0 and l[i] == 0:
            a.append(p[i])
    if len(a) == 1:
        return 1
    for i in range(1, len(a)):
        r = []
        for j in range(1, len(a)):
            y = [a[0][0] - a[j][0], a[0][1] - a[j][1]]
            z = [a[i][0] - a[j][0], a[i][1] - a[j][1]]
            r.append(y[0] * z[1] - y[1] * z[0])
        flag = 1
        r = filter(lambda x: x != 0, r)
        for j in range(1, len(r)):
            if r[j] * r[0] < 0:
                flag = 0
        if flag:
            return 1
    return 0

def go(x0, x, l):
    if x == n:
        return reduce(lambda x, y: x + y, l) - l[x0] if check(x0, l) else n
    a = go(x0, x + 1, l + [0])
    if x > 0 and a <= reduce(lambda x, y: x + y, l) - l[x0] if x0 < len(l) else 0:
        return a
    b = go(x0, x + 1, l + [1])
    return a if a < b else b

for t in range(T):
    print 'Case #%d:' % (t + 1)
    n = input()
    p = []
    for i in range(n):
        p.append(map(int, raw_input().split(' ')))
    for i in range(n):
        print go(i, 0, [])
