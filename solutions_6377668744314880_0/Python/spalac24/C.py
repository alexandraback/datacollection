import sys
import math
import os
from itertools import combinations


def nex(t=int):
    return t(sys.stdin.readline().strip())

def convex_hull(points):

    points = sorted(points)

    if len(points) == 1:
        return points

    def cross(c, u, v):
        return (u[0] - c[0]) * (v[1] - c[1]) - (u[1] - c[1]) * (v[0] - c[0])

    lower = []
    for p in points:
        while len(lower) >= 2 and cross(lower[-2], lower[-1], p) < 0:
            lower.pop()
        lower.append(p)

    upper = []
    for p in points[::-1]:
        while len(upper) >= 2 and cross(upper[-2], upper[-1], p) < 0:
            upper.pop()
        upper.append(p)

    return lower[:-1] + upper[:-1]


def main():
    t = nex()
    for case in range(1, t + 1):
        sys.stdout.write('Case #%s:\n' % case)

        n = nex()
        l = [] * n
        for _ in range(n):
            l.append(tuple([int(x) for x in  sys.stdin.readline().split()]))

        ol = l
        l = set(l)
        for x in range(0, n):
            for y in range(0, n):
                allcomb = combinations(l, y)
                found = False
                for com in allcomb:
                    com = set(com)
                    nl = l - com
                    # print 'nl = ', nl
                    cvx = convex_hull(nl)
                    # print 'cvx = ', cvx
                    if ol[x] in cvx:
                        print y
                        found = True
                        break

                if found:
                    break





if __name__ == '__main__':
    main()
