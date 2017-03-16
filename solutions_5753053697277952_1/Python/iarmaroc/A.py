from heapq import *


T = int(raw_input())
for t in xrange(1, T + 1):
    N = int(raw_input())
    p = [int(x) for x in raw_input().split(' ')]

    h = []
    for i, v in enumerate(p):
        ch = chr(ord('A') + i)
        heappush(h, (-v, ch))

    sol = []
    while len(h) > 2:
        v, ch = heappop(h)
        sol.append(ch)

        v += 1
        if v < 0:
            heappush(h, (v, ch))

    p1 = heappop(h)
    p2 = heappop(h)

    maxv, maxch = max(p1, p2)
    minv, minch = min(p1, p2)

    diff = -(minv - maxv)
    for _ in xrange(diff):
        sol.append(minch)

    for _ in xrange(-maxv):
        sol.append(minch + maxch)

    print "Case #{}: {}".format(t, ' '.join(sol))
