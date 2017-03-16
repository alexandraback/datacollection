import sys, os

tn = int(sys.stdin.readline())

for ti in xrange(1, tn+1):
    r, c, n = map(int, sys.stdin.readline().split())
    sol = 0
    if n > (r*c+1)//2:
        def calc(k):
            m = [[True for i in xrange(c)] for j in xrange(r)]
            for i in xrange(1, r-1, 2):
                for j in xrange(1 if ((i&1) != 0) else 2, c-1, 2):
                    if k <= 0:
                        return m
                    #print (i, j),
                    m[i][j] = False
                    k -= 1
            for x in [4, 3, 2, 1, 0]:
                for i in xrange(r):
                    for j in xrange(c):
                        if k <= 0:
                            return m
                        if m[i][j]:
                            y = 0
                            if i > 0 and m[i-1][j]:
                                y += 1
                            if i < r-1 and m[i+1][j]:
                                y += 1
                            if j > 0 and m[i][j-1]:
                                y += 1
                            if j < c-1 and m[i][j+1]:
                                y += 1
                            if x == y:
                                m[i][j] = False
                                k -= 1
        m2 = calc(r*c-n)
        for i in xrange(r-1):
            for j in xrange(c):
                if m2[i][j] and m2[i+1][j]:
                    sol += 1
        for i in xrange(r):
            for j in xrange(c-1):
                if m2[i][j] and m2[i][j+1]:
                    sol += 1
    def t(x):
        sol = 0
        m2 = [[(x&(1<<(i*c+j)) != 0) for j in xrange(c)] for i in xrange(r)]
        for i in xrange(r):
            for j in xrange(c):
                if m2[i][j]:
                    sol += 1
        if sol != n:
            return 1000000000000
        sol = 0
        for i in xrange(r-1):
            for j in xrange(c):
                if m2[i][j] and m2[i+1][j]:
                    sol += 1
        for i in xrange(r):
            for j in xrange(c-1):
                if m2[i][j] and m2[i][j+1]:
                    sol += 1
        #if sol == 3:
        #    print m2
        return sol
    sol2 = min([t(x) for x in xrange(1<<(r*c))])
    print 'Case #{0}:'.format(ti), sol2
