#!/usr/bin/python
def find_maxdiff(M, N):
    max_diff = -10001
    for i in range(0, N-1):
        if (M[i] - M[i+1] > max_diff):
            max_diff = M[i] - M[i+1]
    return max_diff

for ii in xrange(input()):
    N = input()
    M = map(int, raw_input().split())
    T1 = 0
    for i in range(1, N):
        if(M[i] < M[i-1]):
            T1 += M[i-1] - M[i]
    T2 = 0
    R = find_maxdiff(M, N)
    if R > 0:
        for i in range(0, N-1):
            if (M[i] < R):
                T2 += M[i]
            else:
                T2 += R
    print "Case #%d: %d %d" % (ii+1, T1, T2)
