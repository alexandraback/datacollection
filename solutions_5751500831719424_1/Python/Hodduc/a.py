def converter(s):
    r = []
    last = None
    ln = 0

    for ch in s:
        if ch == last:
            ln += 1
        else:
            if last:
                r.append((last, ln))
            last = ch
            ln = 1

    if last:
        r.append((last, ln))

    return r


T = input()
for t in xrange(1, T+1):
    N = input()
    strs = []
    for i in range(N):
        strs.append(converter(raw_input()))

    #print strs
    spec = [x[0] for x in strs[0]]

    for s in strs:
        if [x[0] for x in s] != spec:
            print 'Case #%d: Fegla Won' % t
            break
    else:
        tot = 0
        for i in range(len(strs[0])):
            p = sorted([s[i][1] for s in strs])
            tot += sum([abs(p[N/2]-pp) for pp in p])
        print 'Case #%d:' % t, tot
