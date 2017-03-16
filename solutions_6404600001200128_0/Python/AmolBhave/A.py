#!/usr/bin/env python2

T = input()
for t in range(1, T+1):
    m_size = input()
    m = map(int, raw_input().split())
    ans1 = 0
    max_diff = 0
    for i in range(1, len(m)):
        if m[i] < m[i-1]:
            max_diff = max(max_diff, m[i-1]-m[i])
            ans1 += m[i-1] - m[i]
    ans2 = 0
    for i in range(0, len(m)-1):
        if m[i] < max_diff:
            ans2 += m[i]
        else:
            ans2 += max_diff

    print 'Case #' + str(t) + ': ' + str(ans1) + " " + str(ans2)
