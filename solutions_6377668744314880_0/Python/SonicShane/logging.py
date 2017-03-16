from scipy.spatial import ConvexHull
import fileinput
import numpy as np
import sys

def line():
    return sys.stdin.readline()

def recurse(i, N, hulls, mask):
    # Base Case
    if hulls[mask][i]:
        return 0

    # Recursive Step
    best = 0
    for i in range(N):
        if (mask & (1 << i)) > 0:
            mnew = mask ^ (1 << i)
            best = min(best, recurse(i,N,hulls,mnew))
    return best+1

T = np.int(line())
for t in range(T):
    N = np.int(line())
    P = []
    for i in range(N):
        P.append([np.int(v) for v in line().split()])

    # Compute the presence of points in the 2^N hulls
    hulls = []
    alltrue = [True for i in range(N)]
    for i in range(1 << N):
        pts = []
        for j in range(N):
            if i & (1 << j) > 0:
                pts.append(P[j])
        if len(pts) > 3:
            # How the hell do you make qhull return points
            # that lie exactly on the boundary??
            hull = ConvexHull(pts, qhull_options="-Fx")
            res = [j in hull.vertices for j in range(N)]
            hulls.append(res)
        else:
            res = [(i&(1<<j)>0) for j in range(N)]
            hulls.append(res)
    
    # Recurse and go
    print "Case #%d:" % (t+1)
    for i in range(N):
        print recurse(i, N, hulls, (1<<N)-1)
