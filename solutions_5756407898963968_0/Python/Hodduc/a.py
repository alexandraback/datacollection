for i in range(input()):
    row1 = input() - 1
    map1 = [raw_input() for _ in range(4)]
    row2 = input() - 1
    map2 = [raw_input() for _ in range(4)]

    num1 = set(map(int, map1[row1].split()))
    num2 = set(map(int, map2[row2].split()))

    common = num1 & num2
    if len(common) == 0:
        ans = 'Volunteer cheated!'
    elif len(common) > 1:
        ans = 'Bad magician!'
    else:
        ans = list(common)[0]

    print 'Case #{}: {}'.format(i+1, ans)
