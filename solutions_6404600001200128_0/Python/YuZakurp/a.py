T = int(input())
for t in range(T):
    N = int(input())
    s = list(map(int, input().split()))
    v1, d, v2 = 0, 0, 0
    for i in range(1, len(s)):
        v1 += max(0, s[i - 1] - s[i])
        d = max(d, s[i - 1] - s[i])
    for i in range(1, len(s)):
        v2 += min(s[i - 1], d)
    print('Case #{0}: {1} {2}'.format(t + 1, v1, v2))
