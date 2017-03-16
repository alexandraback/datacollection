t = int(raw_input())
for kei in xrange(t):
    n = int(raw_input())
    strings = []
    for i in xrange(n):
        s = raw_input()
        p = None
        f = 0
        ls = []
        for c in s:
            if p is None:
                p = c
                f += 1
            else:
                if p == c:
                    f += 1
                else:
                    ls.append((p, f))
                    p = c
                    f = 1
        if p is not None:
            ls.append((p,f))
        strings.append(ls)
    # print kei
    # print strings
    ok = True
    for i in xrange(n-1):
        if len(strings[i]) != len(strings[i+1]):
            ok = False
            break
    if ok:
        l = len(strings[0])
        for i in xrange(n-1):
            for j in xrange(l):
                if strings[i][j][0] != strings[i+1][j][0]:
                    ok = False
                    break
            if not ok:
                break
    if ok:
        l = len(strings[0])
        diff = 0
        for i in xrange(l):
            ls = []
            for j in xrange(n):
                ls.append(strings[j][i][1])
            ls.sort()
            median = ls[len(ls)/2]
            for j in ls:
                diff += abs(j-median)
        print 'Case #%d: %d' % (kei+1,diff)
    else:
        print 'Case #%d: Fegla Won' % (kei+1,)


