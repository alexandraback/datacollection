import collections

ri = lambda : raw_input().strip()
rim = lambda tp, deli: map(tp, ri().split(deli))

n = int(ri())

for i in xrange(0, n):
    k1 = int(ri()) - 1
    cards = []
    for j in xrange(4):
        cards.append(rim(int, ' '))

    k2 = int(ri()) - 1
    cards_arr = []
    for j in xrange(4):
        cards_arr.append(rim(int, ' '))
    
    result = set(cards[k1]).intersection(set(cards_arr[k2]))    
    
    
    print 'Case #{0}:'.format(i+1),
    
    if len(result) == 0:
        print 'Volunteer cheated!'
    elif len(result) == 1:
        print list(result)[0]
    elif len(result) > 1:
        print 'Bad magician!'
