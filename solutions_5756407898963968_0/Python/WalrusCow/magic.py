import sys

def readCards():
    ''' Read the cards, return a 1d array of sets. '''
    return [set(sys.stdin.readline().split()) for _ in range(4)]


def findCard():
    ''' Find the card (do a test case). '''

    row = int(sys.stdin.readline()) - 1
    cards = readCards()
    possible = cards[row]

    row = int(sys.stdin.readline()) - 1
    cards = readCards()
    # Set intersection
    possible &= cards[row]

    l = len(possible)
    if l == 0:
        return 'Volunteer cheated!'
    elif l == 1:
        return ''.join(possible) # one elem
    else:
        return 'Bad magician!'


def main(n):
    ''' Read and perform n test cases. '''

    for i in range(n):
        answer = findCard()
        print('Case #{}: {}'.format(i+1, answer))


if __name__ == '__main__':
    n = int(sys.stdin.readline())
    main(n)
