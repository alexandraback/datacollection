dij = [(1, 0), (-1, 0), (0, 1), (0, -1)]

def cvt(r, c, m):
    ret = 0
    for i in xrange(r):
        for j in xrange(c):
            ret <<= 1
            if m[i][j]:
                ret += 1
    return ret

def calc(r, c, m):
    ret = 0
    for i in xrange(r):
        for j in xrange(c):
            if m[i][j]:
                for k in xrange(len(dij)):
                    nxt = (i + dij[k][0], j + dij[k][1])
                    if nxt[0] >= 0 and nxt[0] < r and nxt[1] >= 0 and nxt[1] < c and m[nxt[0]][nxt[1]]:
                        ret += 1
    return ret / 2

def dfs(r, c, n, m, dp):
    if dp[cvt(r, c, m)]:
        return dp[cvt(r, c, m)]
    if n == 0:
        return calc(r, c, m)
    ret = 1000
    for i in xrange(r):
        for j in xrange(c):
            if not m[i][j]:
                m[i][j] = True
                ret = min(ret, dfs(r, c, n - 1, m, dp))
                m[i][j] = False
    dp[cvt(r, c, m)] = ret
    return ret


T = int(raw_input())
for cs in  xrange(1, T + 1):
    r, c, n = map(int, raw_input().split())
    m = [[False] * c for _ in xrange(r)]
    dp = [None] * 100000
    ans = dfs(r, c, n, m, dp)
    print 'Case #{}: {}'.format(cs, ans)
