
from math import sin
from math import cos
from math import pi
from bisect import bisect_left
from pylab import frange

E = 1e-2

def transform(P, d, pos): 
    rx, ry, idx = P[pos] 

    def rotate(t): 
        x, y, i = t
        return cos(d)*(x-rx) - sin(d)*(y-ry) + rx, \
                cos(d)*(y-ry) + sin(d)*(x-rx) + ry, i

    return map(lambda t: rotate(t), P)

def cnt_lt(A, x): 
    cnt = 0
    for a in A: 
        if a < x and abs(a - x) > E: 
            cnt += 1
    return cnt 

T = input() 

for t in range(T): 
    n = input() 
    P = [] 
    for i in range(n): 
        x, y = map(float, raw_input().split()) 
        P.append((x, y, i)) 

    print 'Case #%d:' %(t+1)

    for i in range(n): 
        cnt = n 
        for d in frange(0.0, 2*pi, 0.002): 
            R = transform(P, d, i)
            x, y, idx = R[i] 
            X = [x2 for x2, y2, i2 in sorted(R)] 
            # pos = bisect_left(X, x)
            pos = cnt_lt(X, x) 
            if cnt > pos: 
                cnt = pos 

        print cnt 
