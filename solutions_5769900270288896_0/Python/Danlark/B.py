from itertools import combinations
ouf = open('output.txt', 'w')
t = int(input())

def prov(r, c):
    l = 0
    for i in range(r):
        for j in range(c - 1):
            if mat[i][j] == mat[i][j + 1] == True:
                l += 1
    for i in range(c):
        for j in range(r - 1):
            if mat[j][i] == mat[j + 1][i] == True:
                l += 1
    return l


for pop in range(t):
    p = 10**9
    r, c, n = map(int, input().split())
    a = [i for i in range(r*c)]
    for k in combinations(a, n):
        mat = [[[False] for i in range(c)] for j in range(r)]
        for j in range(len(k)):
            mat[k[j] // c][k[j] % c] = True
        for i in range(r):
            for j in range(c):
                l = prov(r, c)
                if l < p:
                    p = l
    print('Case #', pop + 1, ':', ' ', p, sep = '', file = ouf)

ouf.close()