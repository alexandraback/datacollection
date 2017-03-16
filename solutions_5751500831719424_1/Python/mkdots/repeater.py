T = int(raw_input())

def redu(x):
    res = []
    for c in x:
        if len(res) == 0 or c != res[-1]:
            res.append(c)
    return ''.join(res)

for t in xrange(T):
    n = int(raw_input())
    s = [raw_input().strip() for _ in xrange(n)]
    
    q = set(map(redu, s))
    pr = next(iter(q))
    m = len(pr)
    
    if len(q) > 1:
        print 'Case #{}: {}'.format(t + 1, 'Fegla Won')
    else:
        cnt = [[0]*m for _ in xrange(n)]

        for i in xrange(n):
            k = 0
            for j in xrange(m):
                while k < len(s[i]) and pr[j] == s[i][k]:
                    cnt[i][j] += 1
                    k += 1
        
        ans = 0
        
        for col in xrange(m):
            best = 100500
            x = [cnt[i][col] for i in xrange(n)]
            for xx in x:
                temp = sum(map(lambda z: abs(xx - z), x))
                if (temp < best):
                    best = temp
            ans += best
        
        print 'Case #{}: {}'.format(t + 1, ans)