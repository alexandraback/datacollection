
fout = open('a.out', 'w')
fin = open('A-small-attempt0.in', 'r')

t = int(fin.readline())
for x in range(1,t+1):
    s = fin.readline()
    n = int(s)
    s = fin.readline()
    partyStrArr = s.split(" ")
    parties = map(int, partyStrArr)
    total = sum(parties)

    fout.write('Case #{}: '.format(x))
    while total > 0:

        candidate = max(parties)
        fout.write('{}'.format(chr(65+parties.index(candidate))))
        parties[parties.index(candidate)] -= 1
        total -= 1

        if total != 2:
            candidate = max(parties)
            fout.write('{}'.format(chr(65+parties.index(candidate))))
            parties[parties.index(candidate)] -= 1
            total -= 1

        fout.write('{}'.format(' '))

    fout.write('{}'.format('\n'))
