def solve():
    b, n = [int(x) for x in raw_input().split()]
    n -= 1
    m = [int(x) for x in raw_input().split()]
    assert len(m) == b
    def head(t):
        out = 0
        for mi in m:
            out += (t - 1) / mi + 1
        return out
    low = 0
    high = m[0] * n + 1
    assert head(low) <= n
    assert head(high) > n
    while low + 1 < high:
        mid = (low + high) / 2
        if head(mid) > n:
            high = mid
        else:
            low = mid
    assert head(low) <= n
    assert head(high) > n
    poss = []
    for i in range(b):
        if low % m[i] == 0: poss.append(i)
    #assert sorted(poss) == poss
    return 1 + poss[n - head(low)]

for i in range(int(raw_input())):
    print "Case #%d: %d" % (i+1, solve())
