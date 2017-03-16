import numpy as np
from sys import stdin

T = int(stdin.readline())
for case in xrange(1, T+1):
    r, c, n = map(int, stdin.readline().split(' '))
    grid = np.zeros((r, c))
    def search(i, j, filled, cost):
        if filled == n:
            return cost
        if j == c:
            return float('inf')
        ni = i + 1
        nj = j
        if ni == r:
            ni = 0
            nj = j + 1
        e = search(ni, nj, filled, cost)
        grid[i][j] = 1
        dcost = 0
        if i > 0 and grid[i-1][j]:
            dcost += 1
        if j > 0 and grid[i][j-1]:
            dcost += 1
        f = search(ni, nj, filled + 1, cost + dcost)
        grid[i][j] = 0
        return min(e, f)
    mc = search(0, 0, 0, 0)
    print "Case #%d: %d" % (case, mc)
