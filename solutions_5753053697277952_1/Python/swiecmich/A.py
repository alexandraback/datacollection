import operator


t = int(raw_input())
for i in xrange(1, t + 1):
    parties = {}
    n = int(raw_input())
    p_list = [int(s) for s in raw_input().split()]
    for j, p in enumerate(p_list):
        parties[chr(j + ord('A'))] = p
    # print(parties)
    steps = []
    senators = sum(parties.values())
    # print(senators)
    while senators > 0:
        p1 = max(parties.iteritems(), key=operator.itemgetter(1))[0]
        parties[p1] -= 1
        senators -= 1
        p2 = None
        for k, v in parties.items():
            if v > senators / 2:
                p2 = k
                parties[p2] -= 1
                senators -= 1
        if p2 is None:
            steps.append(p1)
        else:
            steps.append('%s%s' % (p1, p2))
    # print(steps)
    print "Case #{}: {}".format(i, ' '.join(steps))
