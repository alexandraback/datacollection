#Noisy neighbors
# BF

MAX = 1000000000

import itertools

def prnt(g):
    for i in g:
        for j in i:
            print(j, end=' ')
        print()

def cntneigh(g):
    total = 0
    r = len(g)
    c = len(g[0])

    for i in range(r):
        for j in range(1, c):
            if g[i][j] == 1 and g[i][j-1]==1:
                total += 1

    for i in range(1, r):
        for j in range(c):
            if g[i][j]==1 and g[i-1][j]==1:
                total += 1

    return total

def prob(r, c, n):
    mn = itertools.combinations(range(0, r*c), n)
    best = MAX
    
    for case in mn:
        #print(case)


        #Build grid
        grid = []
        for i in range(r):
            tmp = []
            for j in range(c):
                tmp.append(0)
            grid.append(tmp)

        #prnt(grid)

        for i in case:
            grid[i%r][i//r] = 1

        #prnt(grid)

        tmp = cntneigh(grid)
        if (tmp < best):
            best = tmp

    return best



t = int(input())
for i in range(t):
    tmp = input().split()
    r = int(tmp[0])
    c = int(tmp[1])
    n = int(tmp[2])
    
    print("Case #", i+1, ": ", prob(r, c, n), sep='') 
