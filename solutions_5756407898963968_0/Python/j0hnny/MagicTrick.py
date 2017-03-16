__author__ = 'j0hnny'


if __name__ == '__main__':
    magic = []

    with open('A-small-attempt0 (1).in', 'r') as input:
        cases = int(input.readline())
        for c in range(cases):

            def read_cards():
                return [{int(x) for x in input.readline().split()} for r in range(4)]

            r1 = int(input.readline()) - 1
            cards1 = read_cards()
            r2 = int(input.readline()) - 1
            cards2 = read_cards()

            magic.append(cards1[r1] & cards2[r2])

    with open('output', 'w') as output:
        for c in range(cases):
            l = list(magic[c])
            if len(l) == 0:
                s = 'Case #%d: %s\n' % (c+1, 'Volunteer cheated!')
            elif len(l) == 1:
                s = 'Case #%d: %d\n' % (c+1, l[0])
            else:
                s = s = 'Case #%d: %s\n' % (c+1, 'Bad magician!')
            print s
            output.write(s)