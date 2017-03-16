
Tc = int(raw_input())
for ri in range(Tc):
    n, m = map(int, raw_input().split())
    a = map(int, raw_input().split())
    l, r = 0, int(1e20)
    while l < r:
        mid = (l + r) / 2
        count = 0
        for u in a:
            count += mid / u + 1
        if count >= m:
            r = mid
        else:
            l = mid + 1
    #print r
    s = 0
    for i in range(n):
        s += (r + a[i] - 1) / a[i]
    assert s < m
    for i in range(n):
        if r % a[i] == 0:
            s += 1
            if s == m:
                print "Case #" + str(ri + 1) + ":", i + 1
                break
