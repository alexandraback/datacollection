from util import *

def main():
    r = reader("input")
    num = int(r.next())
    ans = []
    for _ in range(num):
        N = int(r.next())
        points = []
        for i in range(N):
            points.append(map(int, r.next().split(" ")))

        removals = ""
        for i in range(N):
            if N <= 3:
                removals += "\n0"
                continue
            minRemoved = N + 1
            for j in range(N):
                if i ==j:
                    continue
                left = 0
                right = 0
                for k in range(N):
                    if i == k or j == k:
                        continue
                    if ccw(points[i], points[j], points[k]) > 0:
                        left += 1
                    else:
                        right += 1
                minRemoved = min(minRemoved, left, right)
            removals += "\n%s" % minRemoved
        ans.append(removals)

    write("output", ans)

# ccw = 0, colinear
# ccw > 0, counter clockwise
# ccw < 0, clockwise
def ccw(p1, p2, p3):
    return (p2[0] - p1[0])*(p3[1] - p1[1]) - (p2[1] - p1[1])*(p3[0] - p1[0])

if __name__ == '__main__':
    main()
