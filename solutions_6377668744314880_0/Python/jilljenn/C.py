from itertools import combinations

def turn(p, q, r):
    return cmp((q[0] - p[0])*(r[1] - p[1]) - (r[0] - p[0])*(q[1] - p[1]), 0)
 
def redux(hull, r):
    while len(hull) > 1 and turn(hull[-2], hull[-1], r) != 1:
        hull.pop()
    if not len(hull) or hull[-1] != r:
        hull.append(r)
    return hull
 
def convex_hull(points):
    points = sorted(points)
    l = reduce(redux, points, [])
    u = reduce(redux, reversed(points), [])
    return l.extend(u[i] for i in xrange(1, len(u) - 1)) or l

def belongs(m, a, b):
    return (m[0] - a[0]) * (b[1] - a[1]) == (m[1] - a[1]) * (b[0] - a[0])

T = int(raw_input())
for t in range(T):
    N = int(raw_input())
    points = []
    for _ in range(N):
        points.append(tuple(map(int, raw_input().split())))
    score = {point: N - 1 for point in points}
    for k in range(2, N + 1):
        for subset in combinations(points, k):
            # print(subset)
            hull = convex_hull(subset)
            for point in hull:
                score[point] = min(score[point], N - k)
            h = len(hull)
            for point in subset:
                if any(belongs(point, hull[i], hull[(i + 1) % h]) for i in range(h)):
                    score[point] = min(score[point], N - k)
    print 'Case #%d:' % (t + 1)
    for i in range(N):
        print(score[points[i]])
