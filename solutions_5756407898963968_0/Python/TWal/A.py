import sys

def d(*args):
    sys.stderr.write(', '.join(map(str, args)) + "\n")

def printf(*args):
    print ''.join(map(str, args))

def int_input():
    return map(int, raw_input().split(' '))

def solve(cards1, cards2, nb1, nb2):
    set1 = set(cards1[nb1-1])
    cards = filter(lambda x: x in set1, cards2[nb2-1])
    if len(cards) == 1:
        return cards[0]
    elif len(cards) == 0:
        return "Volunteer cheated!"
    else:
        return "Bad magician!"

def read_input():
    nb1 = int(raw_input())
    cards1 = map(lambda _: int_input(), xrange(4))
    nb2 = int(raw_input())
    cards2 = map(lambda _: int_input(), xrange(4))
    return cards1, cards2, nb1, nb2

if __name__ == '__main__':
    for i in xrange(int(raw_input())):
        printf("Case #", i+1, ": ", str(solve(*read_input())))
