for T in xrange(int(raw_input())):
    a = int(raw_input())
    ac = [raw_input().split(' ') for _ in xrange(4)]
    b = int(raw_input())
    bc = [raw_input().split(' ') for _ in xrange(4)]
    answer = set(ac[a-1]) & set(bc[b-1])
    if len(answer) == 1:
        y = answer.pop()
    elif len(answer) > 1:
        y = 'Bad magician!'
    else:
        y = 'Volunteer cheated!'
    print 'Case #%d: %s' % (T+1, y)
