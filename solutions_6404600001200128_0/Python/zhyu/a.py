def solve1(n, m):
    res = 0
    for i in xrange(1, n):
        res += max(m[i-1]-m[i], 0)
    return res


def check(mid, m):
    for i in xrange(1, n):
        if m[i-1] - mid > m[i]:
            return False
    return True


def solve2(n, m):
    l, r = 0, max(m)
    while l < r:
        mid = (l+r) / 2
        if check(mid, m):
            r = mid
        else:
            l = mid + 1
    res = 0
    for i in xrange(n-1):
        res += min(m[i], r)
    return res

t = int(raw_input())
for cas in xrange(t):
    n = int(raw_input())
    m = map(int, raw_input().split())
    res1 = solve1(n, m)
    res2 = solve2(n, m)
    print 'Case #{0}: {1} {2}'.format(cas+1, res1, res2)
