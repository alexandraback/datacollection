from collections import Counter

T = input()
for case in xrange(T):
    N = input()

    P = map(int,raw_input().split())

    cnt = Counter()
    for i,p in enumerate(P):
        cnt[i] = p

    evac = []
    while cnt.most_common(1)[0][1] > 0:
        m = cnt.most_common(1)[0]
        cnt[m[0]] -= 1
        e = chr(ord('A')+m[0])

        # Evac another if there is a majority
        m = cnt.most_common(1)[0]
        if m[1] > sum(map(lambda w: w[1], cnt.most_common()))/2:
            cnt[m[0]] -= 1
            e += chr(ord('A')+m[0])
        evac.append(e)

    sol = ' '.join(evac)
    print 'Case #'+str(case+1)+": " + sol
