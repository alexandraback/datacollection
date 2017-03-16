from itertools import combinations

fi = open("B-small-attempt0.in", "r")
fo = open("B-small-attempt0.out", "w")

T = int(fi.readline())

for case in xrange(1, T+1):
    R, C, N = [int(x) for x in fi.readline().split()]

    # brute force! yaaaaay
    cells = []
    for i in range(0, R):
        for j in range (0, C):
            cells.append((i,j))

    best = -1
    for c in combinations(cells, N):
        # fill in a grid
        grid = [[False]*C for i in range(R)]
        for row,col in c:
            grid[row][col] = True

        # count the walls
        count = 0

        # count in between rows (vertical)
        # check below that cell
        for row in range(0, R-1):
            for col in range(0, C):
                if grid[row][col] and grid[row+1][col]:
                    count += 1

        # count in between cols (horizontal)
        for row in range(0, R):
            for col in range(0, C-1):
                if grid[row][col] and grid[row][col+1]:
                    count += 1

        if best == -1 or count < best:
            best = count

    out = "Case #{}: {}".format(case, best)
    print out
    fo.write(out + "\n")

fi.close()
fo.close()
