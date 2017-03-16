import itertools

def solve(r, c, n):
    if n == 0:
        return 0
    S = []
    for i in xrange(r*c):
        S.append(i)
    mm = r*c*r*c*r*c
    for perm in itertools.combinations(S, n):
        cur = 0
        mp = [[False for i in range(c)] for j in range(r)]
        for i in xrange(r):
            for j in xrange(c):
                mp[i][j] = False
        for i in xrange(len(perm)):
            x = int(perm[i] / c)
            y = perm[i] % c
            mp[x][y] = True
        for i in xrange(r):
            for j in xrange(c):
                if j == 0:
                    continue
                if mp[i][j] and mp[i][j-1]:
                    cur = cur + 1
        for j in xrange(c):
            for i in xrange(r):
                if i == 0:
                    continue
                if mp[i][j] and mp[i-1][j]:
                    cur = cur + 1
        mm = min(mm, cur)
    return mm

for tc in range(int(input())):
    rcm = map(int, raw_input().split())
    print "Case #%d: %d" % (tc+1, solve(rcm[0], rcm[1], rcm[2]))
