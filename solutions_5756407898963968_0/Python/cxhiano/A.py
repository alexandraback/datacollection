import sys

def getRow():
    ans = int(raw_input())
    cards = []
    for r in range(4):
        cards.append(raw_input().split())
    return set(cards[ans - 1])

if __name__ == '__main__':
    T = int(raw_input())
    for t in range(T):
        a1 = getRow()
        a2 = getRow()
        card = a1.intersection(a2)
        sys.stdout.write('Case #{0}: '.format(t + 1))
        if len(card) == 0:
            print 'Volunteer cheated!'
        elif len(card) > 1:
            print 'Bad magician!'
        else:
            print list(card)[0]
