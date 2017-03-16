def process(senators):
    sens = map(lambda x: int(x), senators.split(' '))
    rv = []

    while sum(sens) > 0:
        max_party = 0
        max_num = sens[0]
        party_num = 0
        for i in range(len(sens)):
            if sens[i] > 0:
                party_num += 1
            if sens[i] > max_num:
                max_num = sens[i]
                max_party = i
        if party_num == 2:
            l = ''
            for i in range(len(sens)):
                if sens[i] > 0:
                    l += chr(ord('A') + i)
                    sens[i] -= 1
            rv.append(l)
        else:
            rv.append(chr(ord('A') + max_party))
            sens[max_party] -= 1

    return ' '.join(rv)


t = int(raw_input())
for i in xrange(1, t + 1):
    parties = raw_input()
    line = raw_input()
    #print line
    print("Case #{}: {}".format(i, process(line.lower())))
