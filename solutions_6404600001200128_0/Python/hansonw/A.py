T = int(raw_input())
for t in range(1, T+1):
    raw_input()
    M = map(int, raw_input().split())
    A = 0
    N = len(M)
    rate = 0
    max_delta = 0
    for i in range(1, N):
        if M[i] < M[i-1]:
            delta = M[i-1] - M[i]
            A += delta
            max_delta = max(max_delta, delta)

    B = 0
    for i in range(N-1):
        B += min(M[i], max_delta)

    print "Case #%d: %d %d" % (t, A, B)
