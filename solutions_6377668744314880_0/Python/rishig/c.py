import sys
from scipy.spatial import ConvexHull
import numpy as np

def angle(c,r,l):
    cx, cy = c
    rx = r[0]-cx
    ry = r[1]-cy
    lx = l[0]-cx
    ly = l[1]-cy
    dp = rx*lx + ry*ly
    if dp < 0:
        dp2 = - dp*dp
    else: dp2 = dp*dp
    bsq = lx*lx + ly*ly
    return dp2, bsq # num, den

def comp(a,b):
    an,ad = a[1] # numerators migth be negative
    bn,bd = b[1]
    xx =  an*bd - ad*bn
    if xx > 0:
        return 1
    if xx < 0:
        return -1
    return 0

def iseq(a,b):
    if not a:
        return False
    return a[0]*b[1] == a[1]*b[0]

def isline(pts):
    x,y = pts[0]
    for i in range(len(pts)):
        pts[i] = [pts[i][0]-x, pts[i][1]-y]
    flag = True
    for p in pts[2:]:
        if not iseq(p, pts[1]):
            flag = False
    return flag

def run(pts):
    N = len(pts)
    if N < 4:
        return [0]*N
    il = isline(pts)
    if il:
        return [0]*N
    htemp = ConvexHull(pts)
    hull = list(htemp.vertices)
    mins = [N for iii in range(N)]
    for h in hull:
        mins[h] = 0

    hull2 = hull[1:]
    hull2.append(hull[0])
    for h1,h2 in zip(hull, hull2):
        # sweep right to left
        angles = [[0,0] for iii in range(N)]
        angles[h1] = [10**14,1]
        for i in range(N):
            if i == h1:
                continue
            angles[i] = angle(pts[h1],pts[h2],pts[i])
        tosort = list(enumerate(angles))
        tosort.sort(cmp = comp, reverse = True)
        assert tosort[0][0] == h1

        count = 0
        curval = None
        curbucket = []
        for p in tosort[1:]:
            if iseq(curval, p[1]):
                curbucket.append(p[0])
                continue
            # deal with curbucket
            left = count
            right = N - 1 - len(curbucket) - count
            better = min(left, right)
            for q in curbucket:
                mins[q] = min(mins[q], better)
            count += len(curbucket)
            curbucket = [p[0]]
            curval = p[1]
        # deal with curbucket at end
        left = count
        right = N - 1 - len(curbucket) - count
        better = min(left, right)
        for q in curbucket:
            mins[q] = min(mins[q], better)
    return mins


fin = open(sys.argv[1])
T = int(fin.readline().strip())
for i in range(1,T+1):
    N = int(fin.readline().strip())
    mat = []
    for j in range(N):
        mat.append([int(x) for x in fin.readline().strip().split()])
    ans = run(mat)
    print('Case #%d:' % i)
    for xx in ans:
        print xx
