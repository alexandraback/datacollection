#!/usr/bin/env python3

T = int(input())

for t in range(T):
    N = int(input())
    counts = list(map(int, input().split()))
    
    # method 1
    m1 = 0
    last = counts[0]
    for c in counts[1:]:
        if c < last:
            m1 += last - c
        last = c

    # method 2
    m2 = 0
    last = counts[0]
    maxdiff = 0
    for c in counts[1:]:
        diff = last - c
        if diff > maxdiff:
            maxdiff = diff
        last = c

    for c in counts[:-1]:
        m2 += min(c, maxdiff)

    print('Case #{}: {} {}'.format(t+1, m1, m2))

