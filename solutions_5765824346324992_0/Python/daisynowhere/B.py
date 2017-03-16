def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)


def lcm(a, b):
    return a * b / gcd(a, b)

Tc = int(raw_input())
for ri in range(Tc):
    n, m = map(int, raw_input().split())
    a = map(int, raw_input().split())
    assert len(a) == n
    l = 1
    for u in a:
        l = lcm(l, u)
    s = 0
    for u in a:
        s += l / u
    m %= s
    if m == 0:
        m = s
    #print s, m
    b = [0] * n
    c = [False] * n
    last = -1
    for i in range(m):
        minv = int(1e9)
        minj = -1
        for j in range(n):
            if b[j] == 0 and not c[j]:
                minv = 0
                minj = j
                break
            elif a[j] - b[j] < minv :
                minv = a[j] - b[j];
                minj = j
        for j in range(n):
            b[j] += minv
            if b[j] == a[j]:
                b[j] = 0
                c[j] = False
        last = minj
        #print "hhh", last, minv
        c[last] = True
    print "Case #" + str(ri + 1) + ":", last + 1
