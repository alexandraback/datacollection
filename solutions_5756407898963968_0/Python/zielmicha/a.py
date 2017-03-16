c = int(raw_input())
for casei in xrange(c):

    row1 = int(raw_input())
    for i in xrange(4):
        c = map(int, raw_input().split())
        if i == row1-1:
            cards1 = set(c)
    row2 = int(raw_input())
    for i in xrange(4):
        c = map(int, raw_input().split())
        if i == row2-1:
            cards2 = set(c)

    cards = cards1 & cards2
    print 'Case #%d:' % (casei + 1),
    if len(cards) == 1:
        print list(cards)[0]
    elif cards:
        print 'Bad magician!'
    else:
        print 'Volunteer cheated!'
