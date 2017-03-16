#!/usr/bin/python
# vi: set fileencoding=utf-8 :

def unhappy(ap, R, C):
    u = 0
    for i in range(R):
        for j in range(C - 1):
            if ap[i][j] == 1 and ap[i][j + 1] == 1:
                u += 1
    for i in range(R - 1):
        for j in range(C):
            if ap[i][j] == 1 and ap[i + 1][j] == 1:
                u += 1
    return u


def enum(ap, opt, i, j, x, R, C, N):
    ap[i][j] = x
    s = 0
    for r in range(R):
        s += sum(ap[r])
    if s == N:
        return min(opt, unhappy(ap, R, C))
    else:
        if j == C - 1:
            j = 0
            if i == R - 1:
                return (R + 1) * (C + 1)
            else:
                i += 1
        else:
            j += 1
        return min(enum(ap, opt, i, j, 0, R, C, N), enum(ap, opt, i, j, 1, R, C, N))


def minimum_unhappy(R, C, N):
    ap = [[0 for c in range(C)] for r in range(R)]
    opt = (R + 1) * (C + 1)
    return min(enum(ap, opt, 0, 0, 0, R, C, N), enum(ap, opt, 0, 0, 1, R, C, N))


T = int(raw_input())
for case_number in range(1, T + 1):
    R, C, N = map(int, raw_input().split())
    print 'Case #%d: %d' % (case_number, minimum_unhappy(R, C, N))
