from sys import argv

f = open(argv[1], 'r')

T = int(f.readline()[:-1])
for case in xrange(1,T+1):
    answer = list()
    cards  = list()
    for _ in xrange(2):
        answer.append(int(f.readline()[:-1]) - 1)
        card = list()
        for _ in xrange(4):
            card.append(map(int, f.readline()[:-1].split(' ')))
        cards.append(card)
    guess = set(cards[0][answer[0]]).intersection(set(cards[1][answer[1]]))
    if len(guess) == 0:
        result = 'Volunteer cheated!'
    elif len(guess) == 1:
        result = list(guess)[0]
    elif len(guess) > 1:
        result = 'Bad magician!'
    print "Case #%d:" % case, result
