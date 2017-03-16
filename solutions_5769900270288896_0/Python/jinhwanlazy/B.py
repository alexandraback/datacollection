# brute force
from itertools import combinations
def solve(R, C, N):

    best = (R*C)**2
    for perm in combinations(range(R*C), N):
        count = 0
        grid = [0] * (R*C)
        for i in perm:
            grid[i] = 1
        grid = [grid[i*C:i*C+C] for i in range(R)]
        for i, row in enumerate(grid):
            for j, v in enumerate(row):
                if v == 0:
                    continue
                for y, x in ((i, j+1), (i, j-1), (i+1, j), (i-1, j)):
                    if x < 0 or C <= x or y < 0 or R <= y:
                        continue
                    if grid[y][x] == 1:
#                        print(i, j)
                        count += 1
        best = min(best, count)
#        print(R, C, N, list(perm), grid , count)
#        if best == 0:
#            return best // 2
    return best // 2

for case in range(int(input())):
    R, C, N = map(int, input().split())
    print("Case #%d: %s" % (case+1, solve(R, C, N)))

