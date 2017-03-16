from sys import stdin

def each_case(stdin):
    n1 = int(stdin.readline()) - 1
    t1 = [stdin.readline() for i in xrange(4)]
    n2 = int(stdin.readline()) - 1
    t2 = [stdin.readline() for i in xrange(4)]

    card = set(t1[n1].strip().split()) & set(t2[n2].strip().split())
    if not card:
        return 'Volunteer cheated!'
    elif len(card) > 1:
        return 'Bad magician!'
    else:
        return card.pop()


T = int(stdin.readline())
for t in xrange(T):
    print 'Case #{}: {}'.format(t+1, each_case(stdin))
stdin.close()
