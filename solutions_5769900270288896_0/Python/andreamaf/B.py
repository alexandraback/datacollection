from itertools import combinations


def solve(case):
    R, C, N = map(int, raw_input().strip().split())

    xy = [(i, j) for i in xrange(R) for j in xrange(C)]

    ans = 10 ** 9
    for tup in combinations(xy, N):
        Z = [[0] * C for _ in xrange(R)]
        for x, y in tup:
            Z[x][y] = 1
        count = 0
        for i in xrange(R):
            for j in xrange(C):
                if j < C - 1 and Z[i][j] == 1 and Z[i][j+1] == 1:
                    count += 1
                if i < R - 1 and Z[i][j] == 1 and Z[i+1][j] == 1:
                    count += 1
        ans = min(ans, count)

    print "Case #%d: %d" % (case, ans)


if __name__ == '__main__':
    T = int(raw_input().strip())
    for t in xrange(1, T+1):
        solve(t)
