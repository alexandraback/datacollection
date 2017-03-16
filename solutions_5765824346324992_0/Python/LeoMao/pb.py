#! /usr/bin/env python

def count_n(ms, t):
    return sum([t // m + 1 for m in ms])

T = int(input())

for t in range(1, T+1):
    b, n = [int(x) for x in input().split()]
    ms = [int(x) for x in input().split()]
    if n <= b:
        ans = n
    else:
        mmax = max(ms)
        tl = 0
        tr = mmax * n
        now = (tl + tr) // 2
        cnt = count_n(ms, now)
        while cnt != n - 1 and tr - tl > 1:
            if cnt > n - 1:
                tr = now
            else:
                tl = now
            now = (tl + tr) // 2
            cnt = count_n(ms, now)
        
        left = n - cnt
        bnow = [((now // m + 1) * m, i + 1) for i, m in enumerate(ms)]
        bnow.sort()
        ans = bnow[left - 1][1]

    print("Case #{}: {}".format(t, ans))


