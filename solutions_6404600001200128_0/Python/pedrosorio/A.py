T = int(raw_input())

def solve(m):
    y, z = 0, 0
    mnrate = 0
    for i in xrange(1, len(m)):
        y += max(0, m[i-1] - m[i])
        mnrate = max(mnrate, m[i-1] - m[i])
    for i in xrange(1, len(m)):
        z += min(m[i-1], mnrate)
    return y, z

for case in xrange(1,T+1):
    N = int(raw_input())
    m = map(int,raw_input().split())
    y, z = solve(m)
    print "Case #{}: {} {}".format(case, y, z)
