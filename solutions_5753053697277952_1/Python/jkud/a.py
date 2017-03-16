#!/usr/bin/env python


def solve(P):
    init = ''.join(chr(65+i) * j for i, j in enumerate(P))
    result = ""
    while sum(P) > 4:
        mx = max(P)
        e = P.index(mx)
        P[e] -= 1
        try:
            e2 = P.index(mx)
            P[e2] -= 1
            result += " " + chr(65+e) + chr(65+e2)
        except:
            result += " " + chr(65+e)
    while sum(P) > 0:
        e = P.index(max(P))
        P[e] -= 1
        if sum(P) % 2 == 0:
            result += " " + chr(65+e)
            continue
        e2 = P.index(max(P))
        P[e2] -= 1
        result += " " + chr(65+e) + chr(65+e2)
    return result.strip()


T = int(raw_input().strip())
for t in range(T):
    N = int(raw_input().strip())
    P = [int(i) for i in raw_input().strip().split()]
    print 'Case #%d: %s' % (t+1, solve(P))
