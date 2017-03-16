#!/usr/local/bin/python3.4 -t

import itertools
import sys

class vector:
    @staticmethod
    def add(a, b):
        return (a[0] + b[0], a[1] + b[1])

    @staticmethod
    def sub(a, b):
        return (a[0] - b[0], a[1] - b[1])

    @staticmethod
    def mul(v, a):
        return (v[0] * a, v[1] * a)

    @staticmethod
    def neg(v):
        return (-v[0], -v[1])

    @staticmethod
    def dot(a, b):
        return a[0] * b[0] + a[1] * b[1]

    @staticmethod
    def perp(a):
        return (-a[1], a[0])

def ccw(v0, v1, v2):
    v10, v20 = ((v1[0] - v0[0], v1[1] - v0[1]),
                (v2[0] - v0[0], v2[1] - v0[1]))
    return v10[0] * v20[1] - v10[1] * v20[0]

def pointsontheright(s, e, iterable):
    return (pt for pt in iterable if ccw(s, e, pt) < 0)

def quickhull(iterable):
    def _(s, e, pts):
        pts = tuple(pts)
        if not pts:
            return
        at = vector.neg(vector.perp(vector.sub(e, s)))
        i = max(enumerate(pts),
                key=lambda x: vector.dot(at, vector.sub(x[1], s)))[0]
        for pt in _(s, pts[i], pointsontheright(s, pts[i], pts[:i] + pts[i+1:])):
            yield pt
        yield pts[i]
        for pt in _(pts[i], e, pointsontheright(pts[i], e, pts[:i] + pts[i+1:])):
            yield pt
    pts = tuple(iterable)
    im = min(enumerate(pts), key=lambda x: x[1][0])[0]
    ip = max(enumerate(pts), key=lambda x: x[1][0])[0]
    ptm, ptp = pts[im], pts[ip]
    if im < ip:
        pts = pts[:im] + pts[im+1:ip] + pts[ip+1:]
    else:
        pts = pts[:ip] + pts[ip+1:im] + pts[im+1:]

    yield ptm
    for pt in _(ptm, ptp, pointsontheright(ptm, ptp, pts)):
        yield pt
    yield ptp
    for pt in _(ptp, ptm, pointsontheright(ptp, ptm, pts)):
        yield pt

if __name__ == '__main__':
    def _(f):
        for l in f:
            for i in l.split():
                yield int(i)

    g = _(sys.stdin)

    T = next(g)

    for t in range(1, T + 1):
        print("Case #%d:" % t)
        
        N = next(g)

        pts = []

        for i in range(N):
            x, y = (next(g),
                    next(g),
                    )

            pts.append((x, y))

        nm = [10 ** 18] * N

        for i in range(2 ** N):
            if i:
                b = i

                a = []
                for j in range(N):
                    if b & 1:
                        a.append(pts[j])
                    b >>= 1

                if len(a) <= 3:
                    for j in range(N):
                        if pts[j] in a:
                            if N - len(a) < nm[j]:
                                nm[j] = N - len(a)
                else:
                    qhull = tuple(quickhull(a))

                    for j in range(N):
                        if pts[j] in qhull:
                            if N - len(a) < nm[j]:
                                nm[j] = N - len(a)

                        for k in range(len(qhull)):
                            kk = (k + 1) % len(qhull)

                            x1, y1 = (qhull[kk][0] - qhull[k][0],
                                      qhull[kk][1] - qhull[k][1],
                                  )
                            
                            x2, y2 = (pts[j][0] - qhull[k][0],
                                      pts[j][1] - qhull[k][1],
                                      )

                            if x1 * y2 == x2 * y1:
                                if x2 * x2 + y2 * y2 <= x1 * x1 + y1 * y2:
                                    if N - len(a) < nm[j]:
                                        nm[j] = N - len(a)
                                        break

        for i in nm:
            print(i)
