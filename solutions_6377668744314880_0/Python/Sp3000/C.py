from scipy.spatial import ConvexHull
import numpy as np

def convex_hull(points):
    if len(points) <= 3:
        return list(range(len(points)))

    try:
        apoints = np.asarray(points)
        hull = list(ConvexHull(apoints).vertices)
        h = hull + [hull[0]]
        L = len(hull)

        for v in set(range(len(points))) - set(hull):
            for i in range(L):
                a,b = points[h[i]]
                c,d = points[v]
                e,f = points[h[i+1]]

                if (b-d)*(c-e)==(a-c)*(d-f) and (a<=c<=e or a>=c>=e) and (b<=d<=f or b>=d>=f):
                    hull.append(v)

        return hull

    except:
        return list(range(len(points)))
    

with open("C-small-attempt0.in") as infile:
    with open("C.out", "w") as outfile:
        ncases = int(next(infile))

        for case in range(1, ncases + 1):
            npoints = int(next(infile))
            points = []

            for p in range(npoints):
                points.append(tuple(map(int, next(infile).split())))

            print(points)

            d = {x: npoints-1 for x in range(npoints)}

            for i in range(2**npoints):
                v = [points[x] for x in range(npoints) if i&(1<<x)]
                h = convex_hull(v)

                for x in h:
                    j = points.index(v[x])
                    d[j] = min(d[j], npoints - len(v))

            print("Case #{}:".format(case), file=outfile)

            for n in range(npoints):
                print(d[n], file=outfile)
