def read_cards():
    cards = []
    for i in xrange(4):
        row = raw_input().strip().split()
        row = set(int(x) for x in row)
        cards.append(row)
    return cards

def solve():
    row1 = int(raw_input())
    cards1 = read_cards()
    poss1 = cards1[row1-1]

    row2 = int(raw_input())
    cards2 = read_cards()
    poss2 = cards2[row2-1]

    poss = poss1.intersection(poss2)

    if len(poss) > 1:
        return "Bad magician!"
    elif len(poss) < 1:
        return "Volunteer cheated!"
    else:
        return str(poss.pop())

if __name__ == '__main__':
    count = int(raw_input())
    for i in xrange(count):
        print "Case #%d: %s" % (i+1, solve())
