__author__ = 'sean'

from itertools import combinations


# io_type = 'test'
io_type = 'small'
# io_type = 'large'

if io_type == 'large':
    IN_FILE = 'C-large.in'
    OUT_FILE = 'large_out.txt'

elif io_type == 'small':
    IN_FILE = 'C-small.in'
    OUT_FILE = 'small_out.txt'

else:
    IN_FILE = 'test_input.txt'
    OUT_FILE = 'test_output.txt'


def distance(a, b):
    dist_x = a[0] - b[0]
    dist_y = a[1] - b[1]
    return dist_x*dist_x + dist_y*dist_y


def turn(a, b, c):
    value = (b[0] - a[0])*(c[1] - a[1]) - (c[0] - a[0])*(b[1] - a[1])
    if value > 0:
        return 1
    elif value < 0:
        return -1
    return 0


def next_hull_pt(points, current_point):
    rv = current_point
    for point in points:
        t = turn(current_point, rv, point)
        if t == -1 or t == 0 and distance(current_point, point) > distance(current_point, rv):
            rv = point
    return rv


def are_collinear(points):
    if len(points) < 3:
        return True

    first = points[0]
    second = points[1]
    for j in range(2, len(points)):
        if not (first[1] - second[1]) * (first[0] - points[j][0]) == (first[1] - points[j][1]) * (first[0] - second[0]):
            return False

    return True


def gift_wrap(points):
    if are_collinear(points):
        return points

    conv_hull = [min(points)]
    for point in conv_hull:
        next_point = next_hull_pt(points, point)
        if not next_point == conv_hull[0]:
            conv_hull.append(next_point)
    return conv_hull


def get_lowest(tree_hull, all_trees, tree):
    iter_trees = all_trees[:]
    iter_trees.remove(tree)

    if tree in tree_hull:
        return 0
    if len(tree_hull) > 1:
        if are_collinear((tree_hull[0], tree_hull[len(tree_hull)-1], tree)):
            return 0

        for q in range(len(tree_hull)-1):
            if are_collinear((tree_hull[q], tree_hull[q+1], tree)):
                return 0

    for num_trees in range(1, len(iter_trees)+1):
        combos = combinations(iter_trees, num_trees)
        while True:
            try:
                lesser_trees = all_trees[:]
                combo = next(combos)
                for p in combo:
                    lesser_trees.remove(p)
                new_tree_hull = gift_wrap(lesser_trees)

                if tree in new_tree_hull:
                    return num_trees

                for q in range(len(new_tree_hull)-1):
                    if are_collinear((new_tree_hull[q], new_tree_hull[q+1], tree)):
                        return num_trees

                if len(new_tree_hull) > 1:
                    if are_collinear((new_tree_hull[0], new_tree_hull[len(new_tree_hull)-1], tree)):
                        return num_trees
            except StopIteration:
                break

    return -1

with open(IN_FILE, 'r') as fileIn:
    fileLines = fileIn.readlines()

it = iter(fileLines)
numbCases = int(next(it))
output = ""


for case in range(numbCases):
    n = int(next(it))
    all_points = []
    for i in range(n):
        all_points.append(tuple(int(i) for i in next(it).rstrip().split(' ')))

    hull = gift_wrap(all_points)

    answer = '\n'
    for i in range(n):
        answer += str(get_lowest(hull, all_points, all_points[i])) + '\n'

    answer = answer[0:len(answer)-1]
    line = "Case #{0}: {1}\n".format(str(case+1), str(answer))
    output += line


with open(OUT_FILE, 'w') as fileOut:
    fileOut.write(output)