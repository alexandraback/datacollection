def f(r, c, n, p):
    L = [0]*5
    S = set()
    for i in range(r):
        for j in range(c):
            if (i + j)%2 == p:
                S.add((i, j))
    L[0] = len(S)
    for i in range(r):
        for j in range(c):
            if (i, j) not in S:
                x = 0
                for k, l in ((-1, 0), (0, 1), (1, 0), (0, -1)):
                    if (i + k, j + l) in S:
                        x += 1
                L[x] += 1
    h = 0
    for i, x in enumerate(L):
        if n:
            h += i*min(x, n)
            n -= min(x, n)
    return h

t = int(input())
output = 'Case #{}: {}'
for i in range(t):
    r, c, n = map(int, input().split())
    h = min(f(r, c, n, 0), f(r, c, n, 1))
    print(output.format(i + 1, h))
