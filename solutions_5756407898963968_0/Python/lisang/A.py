def solve(test, lines, f):
    # Read first table.
    first_row = int(lines[-1])
    del lines[-1]
    first_table = [set()] * 4
    for i in range(4):
       first_table[i] = set(lines[-1].split())
       del lines[-1]

    # Read second table.
    second_row = int(lines[-1])
    del lines[-1]
    second_table = [set()] * 4
    for i in range(4):
       second_table[i] = set(lines[-1].split())
       del lines[-1]

    res = first_table[first_row - 1] & second_table[second_row - 1]
    if len(res) > 1:
        print 'Case #{0}: {1}'.format(test + 1, 'Bad magician!')
        f.write('Case #{0}: {1}\n'.format(test + 1, 'Bad magician!'))
    elif len(res) == 1:
        print 'Case #{0}: {1}'.format(test + 1, list(res)[0])
        f.write('Case #{0}: {1}\n'.format(test + 1, list(res)[0]))
    elif len(res) == 0:
        print 'Case #{0}: {1}'.format(test + 1, 'Volunteer cheated!')
        f.write('Case #{0}: {1}\n'.format(test + 1, 'Volunteer cheated!'))


lines = [line.strip() for line in open('A-small-attempt0.in', 'r').readlines()][::-1]
f = open('output', 'w')
tests = int(lines[-1])
del lines[-1]

for test in range(tests):
    solve(test, lines, f)
f.close()
