from multiprocessing import Pool

def ok(N, P):
    max_ = 0
    max_i = 0
    for i in xrange(N):
        if max_ < P[i]:
            max_ = P[i]
            max_i = i
    return float(max_) / sum(P) <= 0.5

def solve((N, P)):
    ans = ''
    while sum(P) != 0:
        max_ = 0
        max_i = 0
        for i in xrange(N):
            if max_ < P[i]:
                max_ = P[i]
                max_i = i
        ans += chr(ord('A') + max_i) + ' '
        P[max_i] -= 1
        if not ok(N, P):
            max_ = 0
            max_i = 0
            for i in xrange(N):
                if max_ < P[i]:
                    max_ = P[i]
                    max_i = i
            ans = ans[:-1] + chr(ord('A') + max_i) + ' '
            P[max_i] -= 1
    return ans

T = int(raw_input())
p = Pool(4)
args = []
for i in range(T):
    N = int(raw_input())
    P = map(int, raw_input().split())
    args.append((N, P))
ans = p.map(solve, args)
for i in range(T):
    print 'Case #%d:' % (i + 1), ans[i]
