#!/usr/bin/python2.7

for case in range(input()):
    N = int(input())
    p = map(int, raw_input().split())

    sol = []
    if (N == 2):
        a = p[0]
        b = p[1]
        if (a > b):
            while (a > b):
                sol.append('A')
                a -= 1
        if (b > a):
            while (b > a):
                sol.append('B')
                b -= 1
        for i in xrange(a):
            sol.append('AB')
    else:
        m = max(p)
        mi = p.index(m)
        while (m > 1):
            sol.append(str(unichr(65+mi)))
            p[mi] -= 1
            m = max(p)
            mi = p.index(m)
        for i in xrange(2, N):
            sol.append(str(unichr(65+i)))
        sol.append('AB')

    print 'Case #%s: %s' % ((case + 1), ' '.join(sol))
