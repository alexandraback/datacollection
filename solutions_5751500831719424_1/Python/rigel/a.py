from collections import Counter


def process(ss):
    enxutas = []
    cnts = []
    for s in ss:
        enx = []
        cnt = []
        last = s[0]
        c = 1
        for el in s:
            if el != last:
                enx.append(last)
                cnt.append(c)
                last = el
                c = 1
                continue
            c += 1
        enx.append(last)
        cnt.append(c)
        enxutas.append(enx)
        cnts.append(cnt)
        if not enx == enxutas[0]:
            return 'Fegla Won'

    letcnts = list(zip(*cnts))
    allmin = []
    allminval = []
    for lc in letcnts:
        mincnt = min(lc)
        maxcnt = max(lc)
        minimum = 1000000000
        for i in range(mincnt, maxcnt+1):
            cntsum = 0
            for c in lc:
                cntsum += i - c if i > c else c - i
            if cntsum < minimum:
                minimum = cntsum
                minval = i
        allmin.append(minimum)
        allminval.append(minval)

    return sum(allmin)

T = input()

for casenbr in range(T):
    N = input()
    ss = []
    for i in range(N):
        ss.append(raw_input().strip())
    print "Case #%d: %s" % (casenbr+1, str(process(ss)))
