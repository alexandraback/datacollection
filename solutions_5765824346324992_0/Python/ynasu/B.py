#!/usr/bin/env python2.7

T = int(raw_input())
for x in xrange(1, T + 1):
    B, N = map(int, raw_input().split())
    M = map(int, raw_input().split())
    elapsed = 0
    b = 1 << 50
    while b:
        elapsed |= b
        if sum((elapsed - 1) / m + 1 for m in M) >= N:
            elapsed ^= b
        b >>= 1
    done = sum((elapsed - 1) / m + 1 for m in M)
    y = filter(lambda j: elapsed % M[j] == 0, xrange(B))[N - done - 1] + 1
    print 'Case #{}: {}'.format(x, y)
