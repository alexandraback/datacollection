NUMBER_ANSWERS = 2
NUMBER_ROWS = 4


with open('input') as in_file:
    with open('output', 'w') as out_file:
        t = int(in_file.readline())
        for i in range(t):
            possible_cards = set(range(1, 17))
            for _ in range(NUMBER_ANSWERS):
                answer = int(in_file.readline()) - 1
                for j in range(NUMBER_ROWS):
                    cards_in_row = set(map(int, in_file.readline().split()))
                    if j == answer:
                        possible_cards = possible_cards & cards_in_row
            if len(possible_cards) == 1:
                out_file.write('Case #{}: {}\n'.format(
                        i + 1, possible_cards.pop()))
            elif len(possible_cards) == 0:
                out_file.write('Case #{}: Volunteer cheated!\n'.format(i + 1))
            else:
                out_file.write('Case #{}: Bad magician!\n'.format(i + 1))
