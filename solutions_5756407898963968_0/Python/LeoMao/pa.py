#! /usr/bin/env python

T = int(input())
for t in range(1, T + 1):
    g = {}
    r = int(input())
    for i in range(1, 5):
        g[i] = input().split()
    f1 = set(g[r].copy())
    r = int(input())
    for i in range(1, 5):
        g[i] = input().split()
    f2 = set(g[r].copy())
    ans = f1 & f2
    if len(ans) == 1:
        ans = ans.pop()
    elif len(ans) == 0:
        ans = "Volunteer cheated!"
    else:
        ans = "Bad magician!"
    print("Case #{}: {}".format(t, ans))

