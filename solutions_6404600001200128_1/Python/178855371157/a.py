import sys

T = int(sys.stdin.readline())

for n in range(1, T+1):
    N = int(sys.stdin.readline())
    M = [int(m) for m in sys.stdin.readline().split()]

    min1 = 0
    min_rate = 0
    for i in range(1, N):
        min1 += max(M[i-1] - M[i], 0)
        min_rate = max(min_rate, max(M[i-1] - M[i], 0))

    min2 = 0
    for i in range(1, N):
        min2 += min(min_rate, M[i-1])

    print "Case #{}: {} {}".format(n, min1, min2)
