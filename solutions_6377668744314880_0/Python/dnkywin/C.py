from fractions import Fraction
from itertools import izip, imap

def solve(N, X, Y, myx, myy):
    up = 0
    down = 0
    slopes = {}
    for x, y in izip(X, Y):
        if x == myx:
            if myy < y:
                down += 1
            elif myy > y:
                up += 1
        else:
            slope = Fraction(myy - y, myx - x)
            if (True, slope) in slopes:
                slopes[(myx > x, slope)] += 1
            else:
                slopes[(myx > x, slope)] = 1
                slopes[(myx < x, slope)] = 0

    slopes[(True, Fraction(1000000000, 1))] = up
    slopes[(False, Fraction(1000000000, 1))] = down
    moreslopes = sorted(slopes.items())
    vals = [num for _, num in moreslopes]
    assert(sum(vals) == N - 1)
    lines = len(vals) / 2
    psum = [0]
    for i in xrange(2 * lines):
        psum.append(psum[-1] + vals[i])
    ans = N - 1
    for i in xrange(1, lines + 1):
        side1 = psum[i + lines - 1] - psum[i]
        side2 = N - 1 - side1 - vals[i + lines - 1] - vals[i - 1]
        ans = min(ans, min(side1, side2))

    return ans




def solve_case(t):
    print "Case #%d:" % t
    N = int(raw_input())
    X = []
    Y = []
    for i in xrange(N):
        x,y = map(int, raw_input().split())
        X.append(x)
        Y.append(y)
    for i in xrange(N):
        print solve(N, X, Y, X[i], Y[i])


T = int(raw_input())
for i in xrange(T):
    solve_case(i + 1)



