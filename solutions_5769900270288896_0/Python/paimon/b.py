from itertools import combinations

def g(r, c, S):
    x = 0
    for i in range(r):
        for j in range(c):
            if (i, j) in S:
                if (i - 1, j) in S:
                    x += 1
                if (i, j - 1) in S:
                    x += 1
    return x

def f(r, c, n):
    L = []
    for i in range(r):
        for j in range(c):
            L.append((i, j))
    return min(g(r, c, S) for S in combinations(L, n))

t = int(input())
output = 'Case #{}: {}'
for i in range(t):
    r, c, n = map(int, input().split())
    print(output.format(i + 1, f(r, c, n)))

