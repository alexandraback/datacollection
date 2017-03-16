import sys
import numpy as np
from scipy.spatial import ConvexHull

def convex_hull(points):
    """Computes the convex hull of a set of 2D points.
    Source: http://en.wikibooks.org/wiki/Algorithm_Implementation/Geometry/Convex_hull/Monotone_chain
    Input: an iterable sequence of (x, y) pairs representing the points.
    Output: a list of vertices of the convex hull in counter-clockwise order,
      starting from the vertex with the lexicographically smallest coordinates.
    Implements Andrew's monotone chain algorithm. O(n log n) complexity.
    """
 
    # Sort the points lexicographically (tuples are compared lexicographically).
    # Remove duplicates to detect the case we have just one unique point.
    points = sorted(set(points))
 
    # Boring case: no points or a single point, possibly repeated multiple times.
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

def crossproduct(a, b, x):
    return (x[1]-a[1])*(b[0]-a[0]) - (x[0]-a[0])*(b[1]-a[1])

def on_line(points, p):
    for i in range(-1, len(points)-1):
        if crossproduct(points[i], points[i+1], p) == 0:
            return True
    return False
def all_linear(points):
    for i in range(2, len(points)):
        if crossproduct(points[0], points[1], points[i]) != 0:
            return False
    return True

nb_testcases = int(sys.stdin.readline())
for current_case in range(1, nb_testcases + 1):
    N = int(sys.stdin.readline())
    original_order =[]
    best_for = dict()
    points = []
    for i in range(N):
        x, y = [int(a) for a in sys.stdin.readline().split()]
        points.append((x, y))
        original_order.append((x,y))
        best_for[(x,y)] = N
    if N >= 3:
        for i in range(1<<N):
            current_points = [points[x] for x in range(N) if (i & (1<<x)) != 0]
            result = current_points
            if not all_linear(current_points):
                result = convex_hull(current_points)
            for x in range(N):
                if points[x] in result or on_line(result, points[x]):
                    if best_for[points[x]] > N-len(current_points):
                        best_for[points[x]] = N-len(current_points)
    else:
        for p in points:
            best_for[p] = 0
    print("Case #"+str(current_case)+":")
    for x in range(N):
        print(best_for[original_order[x]])
            

