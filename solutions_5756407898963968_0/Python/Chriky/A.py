import codejam as gcj

T = gcj.read_input('i')
for t in range(T):
    a, A, b, B = gcj.read_input('i', 4, 'i[]', 'i', 4, 'i[]')

    possible = [x for x in A[a - 1] if x in B[b - 1]]

    if len(possible) == 0:
        answer = 'Volunteer cheated!'
    elif len(possible) > 1:
        answer = 'Bad magician!'
    else:
        answer = possible[0]

    print 'Case #%i:' % (t + 1), answer