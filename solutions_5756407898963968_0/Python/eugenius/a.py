import sys

STDIN = sys.stdin
num_cases = int(STDIN.readline())

def parse_single_answer():
    answer = int(STDIN.readline())
    cards = [STDIN.readline() for x in range(4)][answer-1]
    cards = map(int, cards.split(' '))
    return cards

def parse_case(case_num):
    cards1 = set(parse_single_answer())
    cards2 = set(parse_single_answer())
    common_cards = cards1.intersection(cards2)

    if len(common_cards) == 1:
        print 'Case #{}: {}'.format(case_num, list(common_cards)[0])
    elif len(common_cards) > 1:
        print 'Case #{}: Bad magician!'.format(case_num)
    elif len(common_cards) < 1:
        print 'Case #{}: Volunteer cheated!'.format(case_num)

for case in range(num_cases):
    parse_case(case+1)
