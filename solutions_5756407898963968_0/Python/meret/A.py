d = int(raw_input())

for case_no in range(1, d + 1):
    r1 = int(raw_input())
    t1 = [list(map(int, raw_input().split(' '))) for _ in range(4)]
    r2 = int(raw_input())
    t2 = [list(map(int, raw_input().split(' '))) for _ in range(4)]
    r1 -= 1
    r2 -= 1
    answer = []
    for i in range(1, 17):
        got1 = False
        got2 = False
        for x in range(4):
            if t1[r1][x] == i:
                got1 = True
            if t2[r2][x] == i:
                got2 = True
        if got1 and got2:
            answer.append(i)
    print "Case #{0}:".format(case_no),
    if not answer:
        print 'Volunteer cheated!'
    elif len(answer) > 1:
        print 'Bad magician!'
    else:
        print answer[0]

