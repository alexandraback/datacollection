T = int(raw_input())

def sq_norm(pt):
    return pt[0]**2 + pt[1] ** 2

def more_left(pts, i, cpt, vec, endpt, hull):
    disc = (pts[i][0]-cpt[0]) * vec[0] + (pts[i][1]-cpt[1]) * vec[1]
    if disc > 0:
        return True
    elif disc == 0:
        return (i not in hull and endpt in hull) or (i not in hull and sq_norm((pts[i][0]-cpt[0], pts[i][1]-cpt[1])) < sq_norm((pts[endpt][0]-cpt[0],pts[endpt][1]-cpt[1])))

def convex_hull(pts):
    st = min(pts)
    for i in xrange(len(pts)):
        if pts[i] == st:
            stp = i
            break
    hull = set([stp])
    cpti = stp
    cpt = st
    endpt = -1
    while endpt != stp and len(hull) < len(pts):
        endpt = 0
        vec = (cpt[1]-pts[endpt][1], pts[endpt][0]-cpt[0])
        for i in xrange(1, len(pts)):
            if i == cpti:
                continue
            if (endpt == cpti) or more_left(pts,i,cpt,vec,endpt,hull):
                endpt = i
                vec = (cpt[1]-pts[endpt][1], pts[endpt][0]-cpt[0])
        hull.add(endpt)
        cpt = pts[endpt]
        cpti = endpt
    return hull

def solve(pts):
    ret = [len(pts) for i in xrange(len(pts))]
    for st in xrange(2**len(pts)-1,1,-1):
        pp = []
        crp = []
        for i in xrange(len(pts)):
            if (2**i) & st:
                pp.append(pts[i])
                crp.append(i)
        need = False
        for p in crp:
            if ret[p] > len(pts)-len(pp):
                need = True
                break
        if not need:
            continue
        if len(pp) < 4:
            hull = [i for i in xrange(len(pp))]
        else:
            hull = convex_hull(pp)
        for p in hull:
            ret[crp[p]] = min(ret[crp[p]], len(pts)-len(pp))
    return ret

for case in xrange(1,T+1):
    N = int(raw_input())
    pts = []
    for i in xrange(N):
        x, y = map(int,raw_input().split())
        pts.append((x,y))
    nums = solve(pts)
    print "Case #{}:".format(case)
    for num in nums:
        print num
