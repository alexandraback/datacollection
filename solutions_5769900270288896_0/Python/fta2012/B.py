T = int(raw_input())


for t in xrange(T):
    r, c, n = [int(x) for x in raw_input().split(' ')]

    grid = [[0 for x in xrange(c)] for y in xrange(r)]

    def unhappiness(grid):
        ret = 0
        for x in xrange(1, r):
            for y in xrange(c):
                if grid[x][y] == grid[x - 1][y] == '1':
                    ret += 1
        for x in xrange(r):
            for y in xrange(1, c):
                if grid[x][y] == grid[x][y - 1] == '1':
                    ret += 1
        return ret
        
    best = 9999999999
    for i in xrange(2 ** (r * c)):
        binary = bin(i)[2:]
        if binary.count("1") == n:
            binary = binary.zfill(r * c)
            for x in xrange(r):
                for y in xrange(c):
                    grid[x][y] = binary[x * c + y]
            best = min(best, unhappiness(grid))

    print 'Case #' + str(t + 1) + ': ' + str(best)
