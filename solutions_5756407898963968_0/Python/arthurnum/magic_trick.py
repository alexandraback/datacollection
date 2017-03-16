__author__ = 'arthurnum'


input = open('A-small-attempt0.in', 'r')
output = open('output.out', 'w')


def get_row():
    row_number = int(input.readline())
    cards = []
    for i in range(4):
        cards.extend([int(x) for x in input.readline().split()])
    start_index = 0 + ((row_number - 1) * 4)
    return cards[start_index:(start_index + 4)]


def try_determine(first_selected_row, second_selected_row):
    guess = 0
    bingo = 0
    for x in first_selected_row:
        if x in second_selected_row:
            guess += 1
            if bingo == 0:
                bingo = x

    if guess == 1:
        return "Case #%d: %d\n" % (case + 1, bingo)
    if guess > 1:
        return "Case #%d: Bad magician!\n" % (case + 1)
    if guess == 0:
        return "Case #%d: Volunteer cheated!\n" % (case + 1)


cases = int(input.readline())
for case in range(cases):
    first_selected_row = get_row()
    second_selected_row = get_row()
    output.write(try_determine(first_selected_row, second_selected_row))

input.close()
output.close()