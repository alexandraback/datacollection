def convex_hull(pointz):
    points = sorted(set(pointz))

    if len(points) <= 1:
        return points

    def cross(o, a, b):
        return (a[0] - o[0]) * (b[1] - o[1]) - (a[1] - o[1]) * (b[0] - o[0])
 
    lower = []
    for p in points:
        while len(lower) >= 2 and cross(lower[-2], lower[-1], p) < 0:
            lower.pop()
        lower.append(p)
 
    upper = []
    for p in reversed(points):
        while len(upper) >= 2 and cross(upper[-2], upper[-1], p) < 0:
            upper.pop()
        upper.append(p)
 
    return lower[:-1] + upper[:-1]

raw = open("C-small-attempt0.in").read().strip().split('\n')
fout = open("out.txt", "w")

ncase = int(raw[0])
xline = 0

def Solve(candidates):
    global best
    if candidates[ID] == 0: return

    nextforest = []
    for k in range(nnode):
        if candidates[k] == 1:
            nextforest.append(tuple(points[k][:]))

    hulls = convex_hull(tuple(nextforest))
    sethulls = set(hulls)

    if tuple(points[ID]) in sethulls:
        best = min(best, nnode - sum(candidates))

def Backtrack(k, n, res):
    if k == n:
        if best > nnode-sum(res):
            Solve(res)
        return

    for i in range(2):
        res[k] = i
        Backtrack(k+1, n, res)

for icase in range(1, ncase+1):
    xline += 1
    nnode = int(raw[xline])
    
    points = []
    for i in range(nnode):
        xline += 1
        points.append([int(x) for x in raw[xline].strip().split(' ')])

    print >>fout, "Case #" + str(icase) + ":"
    for ID in range(0, nnode):
        print icase, ID, nnode
        best = nnode
        Backtrack(0, nnode, [0 for x in range(nnode)])
        print >>fout, best
