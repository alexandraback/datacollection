line = lambda: map(int, raw_input().split())

def main():
    for t in range(input()):
        points = [tuple(line()) for n in range(input())]
        print 'Case #{}:'.format(t + 1)
        solve(points)

def solve(points):
    if len(points) == 1:
        print 0
        return
    res = {}
    for p1 in range(len(points)):
        for p2 in range(p1):
            x1, y1 = points[p1]
            x2, y2 = points[p2]
            a, b = 0, 0
            for x, y in points:
                det = (x2-x1)*(y-y1) - (y2-y1)*(x-x1)
                if det < 0: a += 1
                if det > 0: b += 1
            res[p1] = min(res.get(p1, 10000), a, b)
            res[p2] = min(res.get(p2, 10000), a, b)
    #print res, points
    for x in range(len(points)):
        print res[x]

main()
