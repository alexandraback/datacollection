def unhappiness(R, C, grid):
    unhappiness = 0
    for r in range(R):
        for c in range(C - 1):
            if grid[r][c] and grid[r][c+1]:
                unhappiness += 1
    for c in range(C):
        for r in range(R - 1):
            if grid[r][c] and grid[r+1][c]:
                unhappiness += 1
    return unhappiness


def compute_help(R, C, N, grid, tenants, current_cell):
    if tenants == N:
        return unhappiness(R, C, grid)
    if R * C - current_cell < (N - tenants):
        return float('inf')
    if current_cell == R * C:
        return unhappiness(R, C, grid)
    row = current_cell / C
    col = current_cell % C
    grid[row][col] = True
    with_tenant = compute_help(R, C, N, grid, tenants + 1, current_cell + 1)
    grid[row][col] = False
    without_tenant = compute_help(R, C, N, grid, tenants, current_cell + 1)
    return min(with_tenant, without_tenant)


def compute(R, C, N):
    grid = []
    for i in range(R):
        grid.append([False] * C)
    return compute_help(R, C, N, grid, 0, 0)


input_file = open('b-small.in')
cases = int(input_file.readline().strip())
case = 0
while case < cases:
    case += 1
    R, C, N = [int(c) for c in input_file.readline().strip().split()]
    print "Case #{}: {}".format(case, compute(R, C, N))
