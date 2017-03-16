ncase = int(raw_input())
for cid in range(1, ncase+1):
    n = int(raw_input())
    seq = []
    for i in range(n):
        s = raw_input()
        j = 0
        a = []
        while j < len(s):
            k = j
            while k < len(s) and s[k] == s[j]:
                k+=1
            a.append((s[j], k-j))
            j = k
        seq.append(a)
    ss = ''.join([x for x, y in seq[0]])
    if any([ss != ''.join([x for x, y in a]) for a in seq]):
        print 'Case #%d: Fegla Won' % cid
        continue
    ans = 0
    for j in range(len(seq[0])):
        scost = 1e10
        med = sorted([a[j][1] for a in seq])[n / 2]
        for t in range(med-5, med + 5):
            cost = sum([abs(t-a[j][1]) for a in seq])
            if cost < scost:
                scost = cost
        ans += scost
    print 'Case #%d: %d' % (cid, ans)
