"""
This script may use libraries publicly available at: https://github.com/grokit/dcore.

Does this solution solve:
   Small: ?.
   Big:   ?.
"""

import dcore.gcj_boot as boot

def readProblem(fh):

    r, c, n = [int(x) for x in fh.readline().strip().split()]

    return (r, c, n)

def cost(r, c, m):
    unhap = 0

    for i in range(r):
        for j in range(c):
            neigs = []

            neigs.append( (i+1, j) )
            neigs.append( (i, j+1) )
            neigs.append( (i-1, j) )
            neigs.append( (i, j-1) )

            for nn in neigs:
                ii, jj = nn
                if ii < 0 or jj < 0:
                    continue
                if ii >= r or jj >= c:
                    continue

                if m[i][j] == 1 and m[ii][jj] == 1:
                    unhap += 1

    return unhap 

def rec(m, r, c, n, flat, tot):

    if tot == n:
        return cost(r, c, m)

    if flat >= r*c:
        return int(2e30)

    i = flat % r
    j = int(flat/r)

    m1 = rec(m, r, c, n, flat+1, tot)

    m[i][j] = 1
    m2 = rec(m, r, c, n, flat+1, tot+1)
    m[i][j] = 0

    return min(m1, m2)

def solve(p):
    r, c, n = p

    m = []
    for i in range(r):
        m.append([0]*c)

    m = rec(m, r, c, n, 0, 0)

    return int(m/2)

boot.solve(solve, readProblem, '.*small')
