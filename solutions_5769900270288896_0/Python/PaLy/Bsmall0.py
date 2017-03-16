def main():
    r, c, n = map(int, input().split())
    rc = r * c
    res = 100000000000000000
    for m in range(0, 1 << rc):
        mapa = [[None for _ in range(c)] for _ in range(r)]
        tt = 0
        for i in range(rc):
            if (m >> i) & 1 == 1:
                mapa[i // c][i % c] = 1
                tt += 1
            else:
                mapa[i // c][i % c] = 0
        if tt == n:
            s = 0
            for i in range(r):
                for j in range(c):
                    if mapa[i][j] == 1:
                        if i + 1 < r:
                            s += mapa[i + 1][j]
                        if j + 1 < c:
                            s += mapa[i][j + 1]
            res = min(res, s)
    return res


if __name__ == '__main__':
    t = int(input())
    for ti in range(1, t + 1):
        print("Case #" + str(ti) + ": " + str(main()))
