import math
x = []
y = []
def gcd(pp, qq):
    p = max(abs(pp), abs(qq))
    q = min(abs(pp), abs(qq))
    while q != 0:
        r = p % q
        p = q
        q = r
    return p

tt = int(raw_input())
for t in xrange(1, tt+1):
    n = int(raw_input())
    x = [0] * n
    y = [0] * n
    ans = [n] * n
    for i in xrange(n):
        (x[i], y[i]) = map(int, raw_input().split())
    if n == 1:
        ans = [0]
    else:
        for i in xrange(n):
            dmap = {}
            ds = []
            pos = 0
            neg = 0
            for j in xrange(n):
                if i == j:
                    continue
                dx = x[j] - x[i]
                dy = y[j] - y[i]
                dm = gcd(dx, dy)
                dx /= dm
                dy /= dm
                ddx = dx
                ddy = dy
                if ddx < 0 or (ddx == 0 and ddy > 0):
                    ddx *= -1
                    ddy *= -1
                if (ddx, ddy) not in dmap:
                    dmap[(ddx, ddy)] = (0, 0)
                if dx > 0 or (dx == 0 and dy < 0):
                    dmap[(ddx, ddy)] = (dmap[(ddx, ddy)][0] + 1, dmap[(ddx, ddy)][1])
                    pos += 1
                else:
                    dmap[(ddx, ddy)] = (dmap[(ddx, ddy)][0], dmap[(ddx, ddy)][1] + 1)
                    neg += 1
            #if t == 2 and i == 1:
            #    print dmap
            for (ddx, ddy) in dmap:
                ds.append((-math.atan2(ddx, ddy), dmap[(ddx, ddy)][0], dmap[(ddx, ddy)][1]))
            ds.sort()
            #if t == 2 and i == 1:
            #    print ds
            #    print (pos,neg)
            for angle, p0, p1 in ds:
                pos -= p0
                neg -= p1
                ans[i] = min(ans[i], min(pos, neg))
                #if t == 2 and i == 1:
                #    print '!! %d %d' % (pos,neg)
                pos += p1
                neg += p0
                #if t == 2 and i == 1:
                #    print (pos,neg)

    print "Case #%d:" % t
    for i in xrange(n):
        print ans[i]