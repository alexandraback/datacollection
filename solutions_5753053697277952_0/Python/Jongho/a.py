cases = int(raw_input())
for c in xrange(cases):
    N = int(raw_input())
    parties = map(int, raw_input().split())

    ph = []
    res = []
    party_letter = 0x41
    for p in parties:
        ph.append((p,chr(party_letter)))
        party_letter += 1
    # print ph
    ph.sort()
    while (len(ph)>0):
        # print ph
        first = ph.pop()
        second = ph.pop()

        if first[0] == second[0]:
            if first[0]==1 and len(ph)==1:
                # print "len is 3"
                res.append(first[1])
                ph.append((second[0],second[1]))
            else:
                res.append(first[1]+second[1])
                if first[0]>1:
                    ph.append((second[0]-1,second[1]))
                    ph.append((first[0]-1,first[1]))
        else:
            res.extend([first[1]]*(first[0]-second[0]))
            ph.append((second[0],second[1]))
            ph.append((second[0],first[1]))
        ph.sort()
    print "Case #%d: %s" % (c+1,' '.join(res))
