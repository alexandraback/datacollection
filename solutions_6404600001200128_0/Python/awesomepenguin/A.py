t = int(raw_input())

for qq in xrange(1, t+1):
    
    raw_input()
    mush = map(int, raw_input().split())
    time = len(mush) - 1

    diffs = [mush[i] - mush[i+1] for i in xrange(time)]
    ans1 = sum([x for x in diffs if x > 0])

    most = max(diffs)
    pos2 = [min(most, mush[i]) for i in xrange(time)]
    ans2 = sum(pos2)

    print 'Case #%d: %d %d' % (qq, ans1, ans2)
