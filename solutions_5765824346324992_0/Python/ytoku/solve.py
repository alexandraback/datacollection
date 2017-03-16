import sys
import Queue
T = int(sys.stdin.readline())

def solve(B, N, M):
    S = map(lambda x: 1.0/x, M)
    Ssum = sum(S)

    done = 0
    q = Queue.PriorityQueue()
    mint = 0xfffffffff
    for b in xrange(B):
        a = int(N * S[b]/Ssum)
        if a < 1000: a = 0
        elif a >= 1000: a -= 1000
        # (end_time, #barber)
        q.put((a * M[b], b))
        done += a
        mint = min(mint, a * M[b])

    for i in xrange(done, N-1):
        (t, b) = q.get()
        q.put((t + M[b], b))

    return q.get()[1] + 1

for _t in range(T):
    [B, N] = map(int, sys.stdin.readline().split())
    M = map(int, sys.stdin.readline().split())

    ans = solve(B, N, M)
    print "Case #%d: %d" % (_t + 1, ans)
