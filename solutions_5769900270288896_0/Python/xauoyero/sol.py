#!/usr/bin/env python
import itertools
def sol(R, C, N):
    all = []
    for i in xrange(R):
        for j in xrange(C):
            all.append((i, j))
    ans = R*C
    if (R == 1) and (C == 1):
        return 0
    for ps in itertools.combinations(all, N):
        a = [ [False for j in xrange(C)] for i in xrange(R) ]
        for i, j in ps:
            a[i][j] = True
        es = 0
        if R == 1:
            for j in xrange(C - 1):
                if a[0][j] and a[0][j + 1]:
                    es += 1
        elif C == 1:
            for i in xrange(R - 1):
                if a[i][0] and a[i + 1][0]:
                    es += 1
        else:
            for i in xrange(R):
                for j in xrange(C - 1):
                    if a[i][j] and a[i][j + 1]:
                        es += 1
            for j in xrange(C):
                for i in xrange(R - 1):
                    if a[i][j] and a[i + 1][j]:
                        es += 1
        ans = min(ans, es)
    return ans

T = int(raw_input())
for cas in xrange(1, T + 1):
    R, C, N = map(int, raw_input().strip().split())
    ans = sol(R, C, N)
    print("Case #%s: %s"%(cas, ans))
