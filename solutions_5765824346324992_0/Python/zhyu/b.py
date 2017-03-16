import heapq


def gcd(x, y):
    if y == 0:
        return x
    return gcd(y, x % y)


def lcm(x, y):
    return x * y / gcd(x, y)

t = int(raw_input())
for cas in xrange(t):
    b, n = map(int, raw_input().split())
    m = map(int, raw_input().split())
    q = [(0, i) for i in xrange(b)]
    heapq.heapify(q)
    k = 1
    for x in m:
        k = lcm(k, x)
    kk = 0
    for x in m:
        kk += (k/x)
    if n > kk:
        n %= kk
    if n == 0:
        n = kk
    while True:
        x = heapq.heappop(q)
        n -= 1
        heapq.heappush(q, (x[0]+m[x[1]], x[1]))
        if n == 0:
            print 'Case #{0}: {1}'.format(cas+1, x[1]+1)
            break
