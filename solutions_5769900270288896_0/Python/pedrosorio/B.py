
T = int(raw_input())

def count_u(grid):
    R, C = len(grid), len(grid[0])
    u = 0
    for i in xrange(R):
        for j in xrange(C):
            if grid[i][j] == 1:
                if j < C-1:
                    u += grid[i][j+1]
                if i < R-1:
                    u += grid[i+1][j]
    return u

def count_bits(v):
    return sum([1 for i in xrange(16) if (1<<i) & v])

def solve_small(R,C,N):
    sz = R*C
    min_u = 9000
    for v in xrange(2**sz):
        if count_bits(v) == N:
            grid = [[1 if (1<<(C*i+j)) & v else 0 for j in xrange(C)] for i in xrange(R)]
            min_u = min(min_u, count_u(grid))
    return min_u

for case in xrange(1, T+1):
    R, C, N = map(int, raw_input().split())
    print "Case #{}: {}".format(case, solve_small(R,C,N))
