# -*- coding: utf-8 -*-
fin = open("in", "r")
fout = open("out", "w")


def calc_noise(r, c, m):
    a = [0] * r
    for i in range(r):
        a[i] = [0] * c

    res = 0
    num = 0
    for i in range(r):
        for j in range(c):
            if m & (2 ** num):
                a[i][j] = 1
            num += 1

            res += (a[i][j] == 1 and i > 0 and a[i - 1][j] == 1)
            res += (a[i][j] == 1 and j > 0 and a[i][j - 1] == 1)

    return res


t = int(fin.readline())
for tt in range(t):
    r, c, n = map(int, fin.readline().split(' '))
    rc = r * c
    ans = int(1e9)
    for mask in range(2 ** rc):
        cnt = 0
        for i in range(rc):
            if mask & (2 ** i) > 0:
                cnt += 1

        if cnt != n:
            continue

        ans = min(ans, calc_noise(r, c, mask))

    fout.write("Case #%d: %d\n" % (tt + 1, ans))
