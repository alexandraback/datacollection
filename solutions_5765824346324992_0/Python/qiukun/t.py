from fractions import gcd

t = int(raw_input())
kase = 1


def lcm(a, b):
    return a/gcd(a, b)*b


def solve():
    b, n = map(int, raw_input().split())
    m = map(int, raw_input().split())
    if n <= b:
        return n
    n -= b
    mlcm = reduce(lcm, m, 1)
    ww = []
    for i, v in enumerate(m):
        t = range(v, mlcm+1, v)
        ww += zip(t, [i]*len(t))
    ww = sorted(ww)
    return ww[(n-1) % len(ww)][1]+1

while kase <= t:
    print "Case #" + str(kase) + ": " + str(solve())
    kase += 1
