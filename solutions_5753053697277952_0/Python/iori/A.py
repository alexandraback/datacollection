#!/usr/bin/env python3

T = int(input())
for t in range(1, T+1):
    ans = ''
    N = int(input())
    p = list(zip(map(int, input().split()), 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'))
    while True:
        total = 0
        for num, alphabet in p:
            total += num
        if total == 3:
            p.sort(key=lambda a: a[0], reverse=True)
            if p[0][0] == p[1][0] == p[2][0]:
                ans += p[0][1] + ' '
                p[0] = (p[0][0]-1, p[0][1])
            else:
                print("error occured")
                print(p)
                break
        if total <= 2:
            for num, alphabet in p:
                ans += alphabet * num
            break
        else:
            p.sort(key=lambda a: a[0], reverse=True)
            if ((1.0 * p[1][0]) / (total - 1)) >= 0.5:
                ans += p[0][1] + p[1][1] + ' '
                p[0] = (p[0][0]-1, p[0][1])
                p[1] = (p[1][0]-1, p[1][1])
            else:
                ans += p[0][1] + ' '
                p[0] = (p[0][0]-1, p[0][1])
    print("Case #{}: {}".format(t, ans))
