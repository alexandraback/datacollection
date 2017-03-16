if __name__ == '__main__':
    for casenum in range(input()):
        first_answer = input()

        first_arr = [0] * 4
        second_arr = [0] * 4

        for i in range(4):
            first_arr[i] = [int(e) for e in raw_input().split()]

        second_answer = input()

        for i in range(4):
            second_arr[i] = [int(e) for e in raw_input().split()]

        guess1 = first_arr[first_answer - 1]
        guess2 = second_arr[second_answer - 1]

        ans = set(guess1) & set(guess2)

        print 'Case #%d:' % (casenum + 1),
        if len(ans) == 1:
            print ans.pop()
        elif len(ans) > 1:
            print 'Bad magician!'
        else:
            print 'Volunteer cheated!'
