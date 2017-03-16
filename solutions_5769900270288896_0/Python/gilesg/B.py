def ints():
    return map(int, raw_input().split())

INF = 10 ** 9

LIM = 16

num_cases, = ints()

def count(grid):
    R = len(grid)
    C = len(grid[0])
    ret = 0
    for i in range(R):
        for j in range(C):
            for d in ((0, 1), (1, 0)):
                ii = i + d[0]
                jj = j + d[1]
                if ii < R and jj < C:
                    if grid[i][j] and grid[ii][jj]:
                        ret += 1
    return ret

def construct(R, C, x):
    ret = []
    for i in range(R):
        row = [0] * C
        for j in range(C):
            row[j] = x % 2
            x /= 2
        ret.append(row)
    return ret

def bf(R, C):
    ret = [INF] * (R*C + 1)
    for x in range(2 ** (R*C)):
        grid = construct(R, C, x)
        n = sum(sum(row) for row in grid)
        cost = count(grid)
        ret[n] = min(ret[n], cost)
    return ret

d = {}
for R in range(1, LIM+1):
    for C in range(1, LIM+1):
        if R * C <= LIM:
            d[(R, C)] = bf(R, C)

for case_num in xrange(1, num_cases + 1):
    R, C, N = ints()
    print "Case #%d: %s" % (case_num, d[(R, C)][N])
