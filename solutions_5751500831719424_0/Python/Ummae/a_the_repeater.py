import sys
rl = lambda: sys.stdin.readline().strip()

T = int(rl())

for tcase in range(T):
    n = int(rl())
    ss = [rl() for i in range(n)]
    sss = []
    for s in ss:
        before = None
        sh = []
        for c in s:
            if c != before:
                sh.append(c)
                before = c
        ns = ''.join(sh)
        sss.append(ns)

    if len(set(sss)) != 1:
        print 'Case #%d: Fegla Won' % (tcase + 1)
        continue

    ans = 987654321
    #if sss[0] not in ss:
    #    ss.append(sss[0])

    ssc = []
    for s in ss:
        sc = []
        idx = -1
        b = None
        for c in s:
            if c != b:
                b = c
                sc.append([1, c])
                idx += 1
            else:
                sc[idx][0] += 1
        ssc.append(sc)

    max_occured = [0 for i in range(len(ssc[0]))]
    for idx in range(len(ssc[0])):
        for sc in ssc:
            max_occured[idx] = max(max_occured[idx], sc[idx][0])

    ans = 0
    for idx in range(len(ssc[0])):
        min_c = 987654321
        for o in range(1, max_occured[idx] + 1):
            cost = 0
            for sc in ssc:
                cost += abs(sc[idx][0] - o)
            min_c = min(cost, min_c)
        ans += min_c
    print 'Case #%d: %d' % (tcase + 1, ans)
