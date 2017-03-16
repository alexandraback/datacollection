import sys
import math
import os

from fractions import gcd


def nex(t=int):
    return t(sys.stdin.readline().strip())


def mcm(x, y):
    return x * y / gcd(x, y)


def main():
    t = nex()
    for case in range(1, t + 1):
        ans = 0

        b, n = [int(s) for s in sys.stdin.readline().split()]
        l = [int(s) for s in sys.stdin.readline().split()]

        m = 1
        for x in l:
            m = mcm(m, x)

        n = (n - 1) % sum([m / x for x in l]) + 1
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

        ans = bs.index(min(bs)) + 1
        sys.stdout.write('Case #%s: %s\n' % (case, ans))


if __name__ == '__main__':
    main()
