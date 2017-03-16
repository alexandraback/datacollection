
def get_vth_Raw(v):
    for i in range(4):
        if i + 1 == v:
            r = map(int, raw_input().split())
        else:
            raw_input()
    return r


t = int(raw_input())

INF = 1000000000
def get(s):

    ans = []
    st = ''
    last_ch = s[0]
    q = 1
    for ch in s[1:]:
        if ch != last_ch:
            ans.append(q)
            st += last_ch
            q = 1
            last_ch = ch
        else:
            q += 1
    ans.append(q)
    st += last_ch
    return st, ans

for i in xrange(t):
    cs = 'Case #' + str(i + 1) + ':'
    k = int(raw_input())
    fl = False
    st_first, ms = get(raw_input())
    mses = [ms]
    n = len(ms)
    for j in xrange(k - 1):
        st, ms = get(raw_input())
        mses.append(ms)
        if st != st_first or len(ms) != n:
            fl = True
            break
    if fl:
        print cs, 'Fegla Won'
        continue

    res = 0
    for j in xrange(n):
        ans = INF
        for pivot in xrange(101):
            tmpans = sum(abs(mses[p][j] -pivot) for p in xrange(k))
            ans = min(ans, tmpans)
        res += ans


    print cs, res
