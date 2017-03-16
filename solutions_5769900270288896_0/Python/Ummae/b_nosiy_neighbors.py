import sys
import itertools
rl = lambda: sys.stdin.readline().strip()


def is_adj(a, b):
    dx = abs(a[0] - b[0])
    dy = abs(a[1] - b[1])
    if dx + dy == 1:
        return True


def count_unhappy(crds):
    duple = set()
    for pair in itertools.combinations(crds, 2):
        a, b = pair
        if is_adj(a, b):
            a, b = min(a, b), max(a, b)
            duple.add((a, b))
    return len(duple)


T = int(rl())
for tcase in range(1, T + 1):
    print >> sys.stderr, tcase
    R, C, N = map(int, rl().split())
    ac = [(r, c) for r in range(R) for c in range(C)]

    ans = N * N
    for crds in itertools.combinations(ac, N):
        ans = min(ans, count_unhappy(crds))
    print 'Case #%d: %d' % (tcase, ans)
