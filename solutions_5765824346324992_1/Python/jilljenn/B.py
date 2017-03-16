from heapq import heappush, heappop

T = int(raw_input())
for t in range(T):
    B, N = map(int, raw_input().split())
    M = map(int, raw_input().split())
    h = []
    for i in range(B):
        heappush(h, (0, i))
    for _ in range(N):
        time, b_id = heappop(h)
        heappush(h, (time + M[b_id], b_id))
    print 'Case #%d: %s' % (t + 1, b_id + 1)
