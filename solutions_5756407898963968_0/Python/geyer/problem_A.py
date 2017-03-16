# Magic Trick


def chosen_number(row1, row2):
    """ get chosen rows as sets, return string.

        return chosen number if unique,
        return 'Volunteer cheated!' if not existent,
        return 'Bad magician!' if not unique.
    """
    a = row1 & row2
    if len(a) == 0:
        return "Volunteer cheated!"
    elif len(a) > 1:
        return "Bad magician!"
    elif len(a) == 1:
        return a.pop()
    print 'There was a serious problem with the input!'

with open('A-small-attempt0.in.txt', 'r') as fin, open('A-small.out', 'w') as fout:
    T = int((fin.readline().split())[0])
    for case in range(T):
        output = 'Case #' + str(case + 1) + ': '
        t = []
        for n in range(10):
            t.append(map(int, fin.readline().split()))
        row1 = t[0][0]
        row2 = t[5][0]
        output = output + str(chosen_number(set(t[row1]), set(t[row2 + 5])))
        fout.write(output + '\n')
