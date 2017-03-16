
import sys

def deter((x1, y1), (x2, y2), (x3, y3)):
    mat = [[1, x1, y1], [1, x2, y2], [1, x3, y3]]
    return (mat[0][0] * mat[1][1] * mat[2][2]
          + mat[0][1] * mat[1][2] * mat[2][0]
          + mat[0][2] * mat[1][0] * mat[2][1]
          - mat[0][0] * mat[1][2] * mat[2][1]
          - mat[0][1] * mat[1][0] * mat[2][2]
          - mat[0][2] * mat[1][1] * mat[2][0])

def min_points_on_side_of_line(points, line_pt1, line_pt2):
    above = below = 0

    for pt in points:
        det = deter(pt, line_pt1, line_pt2)
        if det > 0:
            above += 1
        elif det < 0:
            below += 1

    return min(above, below)


def read():
    return sys.stdin.readline().strip()

num_cases = int(read())
for case in xrange(num_cases):
    num_pts = int(read())
    print "Case #%d:" % (case + 1)
    
    points = []
    for l in xrange(num_pts):
        x, y = read().split(" ")
        points.append((int(x), int(y)))

    for pt1 in points:
        Min = len(points) - 1
        for pt2 in points:
            if pt1 == pt2: continue
            min_on_side = min_points_on_side_of_line(points, pt1, pt2)
            Min = min(Min, min_on_side)
        print Min

