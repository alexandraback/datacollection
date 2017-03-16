#!/usr/bin/env python
# -*- coding: utf-8 -*-


def readint():
    return int(raw_input())


def readarray(f):
    return map(f, raw_input().split())


def isBetween(a, b, c):
    crossproduct = (c[1] - a[1]) * (b[0] - a[0]) - (c[0] - a[0]) * (b[1] - a[1])
    if abs(crossproduct) > 0.00001:
        return False
    dotproduct = (c[0] - a[0]) * (b[0] - a[0]) + (c[1] - a[1])*(b[1] - a[1])
    if dotproduct < 0:
        return False
    squaredlengthba = (b[0] - a[0])*(b[0] - a[0]) + (b[1] - a[1])*(b[1] - a[1])
    if dotproduct > squaredlengthba:
        return False
    return True

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a
def lcm(a, b):
    return a * b / gcd(a, b)


def convex_hull(points):
    """Computes the convex hull of a set of 2D points.

    Input: an iterable sequence of (x, y) pairs representing the points.
    Output: a list of vertices of the convex hull in counter-clockwise order,
      starting from the vertex with the lexicographically smallest coordinates.
    Implements Andrew's monotone chain algorithm. O(n log n) complexity.
    """

    # Sort the points lexicographically (tuples are compared lexicographically).
    # Remove duplicates to detect the case we have just one unique point.
    points = sorted(set(points))

    # Boring case: no points or a single point, possib[1] repeated multiple times.
    if len(points) <= 1:
        return points

    # 2D cross product of OA and OB vectors, i.e. z-component of their 3D cross product.
    # Returns a positive value, if OAB makes a counter-clockwise turn,
    # negative for clockwise turn, and zero if the points are collinear.
    def cross(o, a, b):
        return (a[0] - o[0]) * (b[1] - o[1]) - (a[1] - o[1]) * (b[0] - o[0])

    # Build lower hull
    lower = []
    for p in points:
        while len(lower) >= 2 and cross(lower[-2], lower[-1], p) <= 0:
            lower.pop()
        lower.append(p)

    # Build upper hull
    upper = []
    for p in reversed(points):
        while len(upper) >= 2 and cross(upper[-2], upper[-1], p) <= 0:
            upper.pop()
        upper.append(p)

    # Concatenation of the lower and upper hulls gives the convex hull.
    # Last point of each list is omitted because it is repeated at the beginning of the other list.
    return lower[:-1] + upper[:-1]


def onBoundary(point, points):
    if point in set(points):
        return True
    for i, e in enumerate(points):
        if i == len(points) - 1:
            if isBetween(points[i], points[0], point):
                return True
        else:
            if isBetween(points[i], points[i + 1], point):
                return True
    return False

T = readint()

for t in xrange(T):
    n = readint()
    points = []
    print "Case #%d:" % (t+1)
    for i in xrange(n):
        x, y = readarray(int)
        points.append((x, y))
    convexHull = convex_hull(points)
    for e in points:
        if onBoundary(e, convexHull):
            print 0
        else:
            bfs = []
            ans = []
            points2 = points[:]
            ans.append(0)
            bfs.append(points2)
            now = 0
            flag = False
            while len(bfs) != 0:
                curPoints = bfs[now]
                curAns = ans[now]
                for i in xrange(len(curPoints)):
                    clonePoints = curPoints[:]
                    del clonePoints[i]
                    if onBoundary(e, convex_hull(clonePoints)):
                        print curAns + 1
                        flag = True
                        break
                    else:
                        bfs.append(clonePoints)
                        ans.append(curAns + 1)
                if flag:
                    break
                now += 1
