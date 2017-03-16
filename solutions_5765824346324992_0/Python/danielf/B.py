def bytime(B, t):
    if t == 0: return 0
    return sum([ (t+x-1)/x for x in B])

_42 = int(raw_input())
for _41 in xrange(_42):
    B, N = map(int, raw_input().split())
    M = map(int, raw_input().split())

    l = 1
    r = (10**9)*100000
    whattime = (10**9)*100000
    while r > l:
        me = (l+r)/2
        if bytime(M, me) >= N:
            whattime = me
            r = me
        else:
            l = me+1
    whattime -= 1
    N -= bytime(M, whattime)
    for i in xrange(B):
        if whattime % M[i] == 0:
            N -= 1
        if N == 0:
            ans = i+1
            break

    print "Case #{}: {}".format(_41+1, ans)
