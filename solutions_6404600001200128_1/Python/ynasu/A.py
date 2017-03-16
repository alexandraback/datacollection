#!/usr/bin/env python2.7

T = int(raw_input())
for x in xrange(1, T + 1):
    N = int(raw_input())
    m = map(int, raw_input().split())
    y = sum(max(0, m[i - 1] - m[i]) for i in xrange(1, N))
    a = max(0, max(m[i - 1] - m[i] for i in xrange(1, N)))
    z = sum(min(a, m[i - 1]) for i in xrange(1, N))
    print 'Case #{}: {} {}'.format(x, y, z)
