import sys

def d(*args):
    sys.stderr.write(', '.join(map(str, args)) + "\n")

def printf(*args):
    print(''.join(map(str, args)))

def int_input():
    return list(map(int, input().split(' ')))

def unhap(grid, r, c):
    res = 0
    if r == 1:
        for i in range(c-1):
            if grid[0][i] == 1 and grid[0][i+1] == 1:
                res += 1
    elif c == 1:
        for i in range(r-1):
            if grid[i][0] == 1 and grid[i+1][0] == 1:
                res += 1
    else:
        for i in range(r):
            for j in range(c):
                if i != r-1 and grid[i][j] == 1 and grid[i+1][j] == 1:
                    res += 1
                if j != c-1 and grid[i][j] == 1 and grid[i][j+1] == 1:
                    res += 1
    return res

def solve(r, c, n):
    grid = [[0]*c for i in range(r)]
    m = 2**31 #inf
    puis = 2**(r*c)
    for i in range(puis):
        g = bin(i+puis)[3:]
        if len([x for x in g if x == "1"]) != n:
            continue
        for j in range(len(g)):
            grid[j//c][j%c] = int(g[j])
        k = unhap(grid, r, c)
        m = min(m, k)
    return m




def read_input():
    return tuple(int_input())


if __name__ == '__main__':
    for i in range(int(input())):
        printf("Case #", i+1, ": ", str(solve(*read_input())))
