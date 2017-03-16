def solve(ix):
    N = int(raw_input().strip())
    S = []
    for _ in range(N):
        S.append(str(raw_input().strip()))

    prefix = [] 
    def get_prefix(s):
        p = []
        prev = None
        counter = 0
        for c in s:
            if c != prev:
                if prev is not None:
                    p.append((prev, counter)) 
                counter = 1
                prev = c
            else:
                counter += 1
        if prev == s[-1]:
            p.append((prev, counter))
        return p    

    for s in S:
        prefix.append(get_prefix(s))
    
    mask = tuple(c for c, _ in prefix[0])
    for i in range(1, N):
        last_mask = tuple(c for c, _ in prefix[i])
        if last_mask != mask:
            print 'Case #%d: Fegla Won' % ix
            return

    ans = 0
    l = len(mask)
    for i in range(l):
        nc = sorted(prefix[j][i][1] for j in range(N))
        dist = 10 ** 18
        for x in range(nc[0], nc[-1]+1):
            dist = min(dist, sum(abs(x-j) for j in nc))
        ans += dist    
    
    print 'Case #%d: %s' % (ix, ans)   
    

T = int(raw_input())
for ix in range(T):
    solve(ix+1)
