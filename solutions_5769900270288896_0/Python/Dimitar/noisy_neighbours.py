from sys import stdin, stdout, stderr
import itertools


def nums(fd, t):
    l = fd.readline()
    return [t(n) for n in l.split(" ")]


def count(grid):
    count = 0
    for r, row in enumerate(grid):
        for c, col in enumerate(row):
            n = neighbours(r, c, grid)
            if grid[r][c]:
                count += n.count(1)

    return count / 2


def neighbours(r, c, grid):
    n = []
    if r > 0:
        n.append(grid[r-1][c])
    if r < len(grid) - 1:
        n.append(grid[r+1][c])
    if c > 0:
        n.append(grid[r][c-1])
    if c < len(grid[0]) - 1:
        n.append(grid[r][c+1])

    return n


def grid(C, e_grid):
    return [e_grid[r:r+C] for r in xrange(0, len(e_grid), C)]


def solve(R, C, N):
    if N == 0:
        return 0
    e_grid = [0] * (R * C)
    best = 10**6
    for comb in itertools.combinations(range(0, len(e_grid)), N):
        copy = e_grid[:]
        for i in comb:
            copy[i] = 1
        best = min(best, count(grid(C, copy)))

    return best


if __name__ == "__main__":
    cases = int(stdin.readline())
    for c in range(1, cases + 1):
        R, C, N = [int(i) for i in stdin.readline().split()]
        ans = solve(R, C, N)
        stdout.write("Case #{0}: {1}\n".format(c, ans))
        stderr.write("Case #{0}: {1}\n".format(c, ans))
