from math import ceil

T = int(raw_input())
for t in range(T):
    N = int(raw_input())
    m = map(int, raw_input().split())
    method1 = 0
    for i in range(1, N):
        if m[i] < m[i - 1]:
            method1 += m[i - 1] - m[i]
    speed_min = max(m[i - 1] - m[i] for i in range(1, N))
    method2 = 0
    for i in range(N - 1):
        method2 += min(speed_min, m[i])
    print 'Case #%d: %d %d' % (t + 1, method1, method2)
