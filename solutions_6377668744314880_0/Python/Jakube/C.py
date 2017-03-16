import math

def atan2(y, x):
    result = math.atan2(y, x)
    if result < 0:
        result += 2*math.pi
    return result


def read_number(f):
    return int(f.readline().strip())


def read_tuple(f):
    return tuple(map(int, f.readline().split()))


def computation(points):
    points_unsorted = points[:]


    # Graham scan
    def ccw(p1, p2, p3):
        return (p2[0] - p1[0])*(p3[1] - p1[1]) - (p2[1] - p1[1])*(p3[0] - p1[0])

    points.sort(key=lambda x: x[::-1])
    start_point = points[0]
    other_points = sorted(points[1:], key=lambda x: atan2(x[1]-start_point[1], x[0]-start_point[0]))
    points2 = other_points + [start_point]

    convex_hull = [start_point]
    for i in range(len(other_points)):
        if ccw(convex_hull[-1], points2[i], points2[i+1]) >= 0:
            convex_hull.append(points2[i])

    convex_hull2 = [start_point]
    for i in range(len(other_points)):
        if ccw(convex_hull2[-1], points2[i], points2[i+1]) > 0:
            convex_hull2.append(points2[i])

    #print(points2)
    #print(convex_hull2)

    output = []
    for point in points_unsorted:
        if point in convex_hull:
            output.append(0)
        else:
            convex_hull_new = convex_hull2[:]
            res = []
            for i in range(len(convex_hull_new)):
                p1_idx = i - 1
                p2_idx = i + 1
                while ccw(convex_hull_new[p1_idx], point, convex_hull_new[p2_idx%len(convex_hull_new)]) < 0:
                    p2_idx += 1

                p1 = convex_hull_new[p1_idx]
                p2 = convex_hull_new[p2_idx%len(convex_hull_new)]

                idx1 = points2.index(p1)
                idx2 = points2.index(p2)

                p3 = points2[idx1 - 1]
                p4 = points2[(idx2 + 1)%len(points2)]

                interesting_points = points2[idx1:idx2]
                if not interesting_points:
                    interesting_points = points2[idx1:] + points2[:idx2]

                for q in points:
                    if atan2(q[1]-p1[1], q[0]-p1[0]) == atan2(p3[1]-p1[1], p3[0]-p1[0]):
                        interesting_points.append(q)
                    #if atan2(q[1]-p2[1], q[0]-p2[0]) == atan2(p4[1]-p2[1], p4[0]-p2[0]):
                    #    interesting_points.append(q)

                interesting_points = list(set(interesting_points))

                number = 0
                number += len([p for p in interesting_points
                               if p != p1 and
                               atan2(p[1]-p1[1], p[0]-p1[0]) < atan2(point[1]-p1[1], point[0]-p1[0])])
                res.append(number)
                #print(point, i, number)
            output.append(min(res))

    #print(convex_hull)
    return output




def main():
    with open('C-small-attempt3.in', 'r') as f:
        test_cases = read_number(f)

        for test_case in range(test_cases):
            N = read_number(f)
            points = [read_tuple(f) for _ in range(N)]
            output = computation(points)
            print('Case #{}:'.format(test_case + 1))
            for i in output:
                print(i)

if __name__ == '__main__':
    main()
