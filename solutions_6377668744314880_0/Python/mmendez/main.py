# 2D cross product of OA and OB vectors, i.e. z-component of their 3D cross product.
# Returns a positive value, if OAB makes a counter-clockwise turn,
# negative for clockwise turn, and zero if the points are collinear.
def cross(o, a, b):
    return (a[0] - o[0]) * (b[1] - o[1]) - (a[1] - o[1]) * (b[0] - o[0])
def convex_hull(points):
    """Computes the convex hull of a set of 2D points.

    Input: an iterable sequence of (x, y) pairs representing the points.
    Output: a list of vertices of the convex hull in counter-clockwise order,
      starting from the vertex with the lexicographically smallest coordinates.
    Implements Andrew's monotone chain algorithm. O(n log n) complexity.
    """

    # Boring case: no points or a single point, possibly repeated multiple times.
    if len(points) <= 1:
        return points

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

def w(o):
    print >>fout, o

def solve():
    case = "Case #%d:"
    T = int(reader.r()) + 1
    for t in xrange(1, T):
        N = int(reader.r())
        x = [(int(reader.r()),int(reader.r())) for i in xrange(N)]
        y = sorted(x)
        ch = convex_hull(y)
        w(case % (t))
        for i in x:
            if i in ch:
                w(0)
            else:
                minc = -1
                for y1 in ch:
                    count1 = 0
                    count2 = 0
                    for x1 in x:
                        if y1 <> x1 and x1 <> i and cross(i, y1, x1) < 0:
                            count1 += 1
                        if y1 <> x1 and x1 <> i and cross(i, y1, x1) > 0:
                            count2 += 1
                    if count1 < minc or minc < 0:
                        minc = count1
                    if count2 < minc or minc < 0:
                        minc = count2
                w(minc)

class reader:
    buffer = []
    @staticmethod
    def r():
        if not reader.buffer:
            reader.buffer = fin.readline().rstrip().split()
        temp = reader.buffer[0]
        reader.buffer = reader.buffer[1:]
        return temp
    @staticmethod
    def rl():
        return fin.readline().rstrip()

fin = open('test.in', 'r')
fout = open('test.out', 'w')
solve();
fin.close()
fout.close()

