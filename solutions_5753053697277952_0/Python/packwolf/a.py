import string
names = string.ascii_uppercase

with open('A-small-attempt0.in') as f:
    with open('a.out', 'w') as out:
        cases = f.readline()
        cases = int(cases)
        for i in xrange(1, cases+1):
            line = f.readline()
            count = map(int, f.readline().split())
            all = sum(count)
            parties = zip(count, names)
            parties.sort(key=lambda x: x[0])
            res = []
            while parties[-1][0] > parties[-2][0]:
                res.append(parties[-1][1])
                parties[-1] = (parties[-1][0]-1, parties[-1][1])
            while len(parties) > 2:
                party = parties.pop(0)
                for _ in range(party[0]):
                    res.append(party[1])
            for _ in range(parties[0][0]):
                res.append(parties[0][1] + parties[1][1])
            res = ' '.join(res)

            print 'Case #{i}: {z}'.format(z=res, i=i)
            out.write('Case #{i}: {z}\n'.format(z=res, i=i))