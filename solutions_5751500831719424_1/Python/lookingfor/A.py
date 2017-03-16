import StringIO

def uniqueN(s):
    r, nn = StringIO.StringIO(), []
    cprev = ""
    for c in s:
        if c != cprev:
            cprev = c
            nn.append(1)
            r.write(c)
        else:
            nn[-1] += 1
    return (r.getvalue(), nn)

def solve1d(a):
    res = 10000000000000
    n = len(a)
    for x in a:
        r = 0
        for y in a:
            r += abs(x-y)
        res = min(res, r)
    return res


def solve(s):
    N = len(s)
    R, nn = [0]*N, [0]*N
    for i in xrange(N):
        R[i], nn[i] = uniqueN(s[i])
    for i in xrange(1, N):
        if R[i] != R[0]:
            return "Fegla Won"
    res = 0
    for i in xrange(len(nn[0])):
        a = [0]*N
        for j in xrange(N):
            a[j] = nn[j][i]
        res += solve1d(a)
    return str(res)

T = int(raw_input())
for z in xrange(T):
    N = int(raw_input())
    s = map(lambda i: raw_input().strip(), xrange(N))
    print "Case #%d: %s" % (z+1, solve(s))