import sys
import math
import os

from fractions import gcd


def nex(t=int):
    return t(sys.stdin.readline().strip())


def mcm(x, y):
    return x * y / gcd(x, y)


def solve(b, n, l):

    sl = sorted(l)[::-1]
    t = 0
    for lmaxi in range(b):
        fac = 1000000000
        while fac >= 1:
            nt = t + fac * sl[lmaxi]
            acumn = sum([(nt + x - 1) / x for x in sl])
            if acumn < n:
                t = nt
                # print 'nt , acumn, rem = ', nt, acumn, n - acumn
            else:
                fac /= 10
    acumn = sum([(t + x - 1) / x for x in sl])
    # print 'acumn = %s' % acumn
    n -= acumn
    assert n
    bs = [(x - (t % x)) % x for x in l]
    # print 'bs = ', bs
    i = 1
    while i < n:
        mi = bs.index(min(bs))

        if bs[mi] == 0:
            # print 'mi = ', mi
            bs[mi] = l[mi]
            i += 1
            # print 'bs = ', bs
        else:
            bs = [x - bs[mi] for x in bs]
    return bs.index(min(bs)) + 1



def solve2(b, n, l):
    m = 1
    for x in l:
        m = mcm(m, x)

    tomod = sum([m / x for x in l])
    # print 'tomod = %s' % tomod
    n = (n - 1) % tomod + 1
    # print m
    # print l
    # print sum([m / x for x in l])
    # print n

    bs = [0] * b

    i = 1
    while i < n:
        mi = bs.index(min(bs))

        if bs[mi] == 0:
            bs[mi] = l[mi]
            i += 1
            # print bs
        else:
            bs = [x - bs[mi] for x in bs]
    return bs.index(min(bs)) + 1

def main():
    t = nex()
    for case in range(1, t + 1):
        ans = 0

        b, n = [int(s) for s in sys.stdin.readline().split()]
        l = [int(s) for s in sys.stdin.readline().split()]


        ans = solve(b, n, l)
        # ans2 = solve2(b, n, l)

        # if ans != ans2:
        #     print '********' * 20
        #     print 'b, n, l = ', b, n, l
        #     print 'ans = ', ans, ans2

        sys.stdout.write('Case #%s: %s\n' % (case, ans))


if __name__ == '__main__':
    main()
