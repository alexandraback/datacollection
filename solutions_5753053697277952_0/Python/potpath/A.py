import string
from collections import Counter

T = int(input())
for t in range(1, T + 1):
    print('Case #%d: ' % t, end='')
    N = int(input())
    Ps = map(int, input().split())
    c = Counter()
    s = 0
    for i, p in enumerate(Ps):
        c[string.ascii_uppercase[i]] = p
        s += p
    ans = []
    while s:
        a = c.most_common(2)
        if len(a) == 2:
            (q, w), (e, r) = a
            if w == r and s != 3:
                ans.append(q + e)
                c[q] -= 1
                c[e] -= 1
                s -= 2
            else:
                ans.append(q)
                c[q] -= 1
                s -= 1
        else:
            q, w = a[0]
            ans += [q] * w
            break
    print(' '.join(ans))
