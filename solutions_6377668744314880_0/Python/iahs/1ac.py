from sys import stdin
from itertools import chain, combinations
# Graham Scan - Tom Switzer <thomas.switzer@gmail.com>

TURN_LEFT, TURN_RIGHT, TURN_NONE = (1, -1, 0)

def turn(p, q, r):
    return cmp((q[0] - p[0])*(r[1] - p[1]) - (r[0] - p[0])*(q[1] - p[1]), 0)

def _keep_left(hull, r):
    while len(hull) > 1 and turn(hull[-2], hull[-1], r) == TURN_RIGHT:
            hull.pop()
    if not len(hull) or hull[-1] != r:
        hull.append(r)
    return hull

def convex_hull(points):
    """Returns points on convex hull of an array of points in CCW order."""
    points = sorted(points)
    l = reduce(_keep_left, points, [])
    u = reduce(_keep_left, reversed(points), [])
    return l.extend(u[i] for i in xrange(1, len(u) - 1)) or l

T = int(stdin.readline())
for case in xrange(1, T+1):
    n = int(stdin.readline())
    points = []
    for i in xrange(n):
        points.append(tuple(map(int, stdin.readline().split(' '))))
    ans = {}
    target = set(points)
    for z in chain.from_iterable(combinations(points, r) for r in xrange(len(points), 0, -1)):
        size = n - len(z)
        for p in convex_hull(z):
            if p in target:
                target.remove(p)
                ans[p] = size
        if not target:
            break
    print "Case #%d:" % case
    for p in points:
        print ans[p]
