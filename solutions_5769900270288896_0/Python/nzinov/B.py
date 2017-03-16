t = int(input())
for case in range(t):
    r, c, n = map(int, input().split())
    m = [[False for i in range(c)] for j in range(r)]
    count = 0
    ans = 1000000
    try:
        if n == 0:
            ans = 0
            raise TypeError
        while True:
            ind = 0
            while True:
                x = ind // c
                y = ind % c
                if x == r:
                    raise TypeError
                if not m[x][y]:
                    m[x][y] = True
                    count += 1
                    break
                m[x][y] = False
                count -= 1
                ind += 1
            if count != n:
                continue
            cur = 0
            for i in range(1, r):
                for j in range(c):
                    if m[i][j] and m[i-1][j]:
                        cur += 1
            for i in range(r):
                for j in range(1, c):
                    if m[i][j] and m[i][j-1]:
                        cur += 1
            ans = min(ans, cur)
    except TypeError:
        pass
    print("Case #{}: {}".format(case + 1, ans))

