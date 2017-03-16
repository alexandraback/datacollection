import sys
lines = open(sys.argv[1] + ".in", "rU").read().split("\n")
t, lines = int(lines[0]), lines[1:]

outfile = open(sys.argv[1] + ".out", "w")

def solve(trees, n):
    if len(trees) == 1: return [0]
    results = []
    for item in trees:
        results.append(min(find(item, p, trees) for p in trees if p != item))
    return results

def find(p1, p2, trees): # from point n on hull
    return min(count(p1, p2, trees), count(p2, p1, trees))

def count(p1, p2, trees):
    return sum(cross(p1, i, p2) > 0 for i in trees)

# Returns a positive value, if OAB makes a counter-clockwise turn,
# negative for clockwise turn, and zero if the points are collinear.
def cross(o, a, b):
    return (a[0] - o[0]) * (b[1] - o[1]) - (a[1] - o[1]) * (b[0] - o[0])

line = 0
for i in range(t):
    n = int(lines[line])
    trees = [tuple(map(int, l.split())) for l in lines[line + 1:line + n + 1]]
    line += n + 1

    print("Case #{}:\n{}".format(i + 1, "\n".join(map(str, solve(trees, n)))), file=outfile)
