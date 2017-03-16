import unittest
import sys
from collections import deque


def getProblemAnswer(S):
    s1 = set(S[0].split(' '))
    s2 = set(S[1].split(' '))
    l = len(s1 & s2)
    if l == 1:
        return (s1 & s2).pop()
    elif l == 0:
        return 'Volunteer cheated!'
    else:
        return 'Bad magician!'


class Tests(unittest.TestCase):

    def test_unit(self):
        self.assertEqual(getProblemAnswer(['1 2 3 4', '5 6 7 1']), '1')
        self.assertEqual(
            getProblemAnswer(['1 2 3 4', '5 6 7 8']), 'Volunteer cheated!'
        )
        self.assertEqual(getProblemAnswer(
            ['1 2 3 4', '5 1 2 8']), 'Bad magician!'
        )

    def test_sample(self):
        path = '0A'
        f = open(path + '.out')
        lines = f.readlines()
        f.close()
        f = open(path + '.expected.out')
        expected_lines = f.readlines()
        f.close()
        self.assertEqual(lines, expected_lines)


def main(arg1):
    print 'opening ' + arg1
    f = open(arg1 + '.in')
    lines = f.readlines()
    f.close()
    lines = deque([case[:-1] for case in lines])
    #print [case for case in lines]
    number_test_cases = int(lines.popleft())
    print 'a total of ' + str(number_test_cases) + ' cases'

    output = []

    for case_number in range(number_test_cases):
        chosen_cards = [None, None]
        selected_row = int(lines.popleft())
        for i in range(1, 5):
            if i == selected_row:
                chosen_cards[0] = lines.popleft()
            else:
                lines.popleft()
        selected_row = int(lines.popleft())
        for i in range(1, 5):
            if i == selected_row:
                chosen_cards[1] = lines.popleft()
            else:
                lines.popleft()
        # print chosen_cards
        result = getProblemAnswer(chosen_cards)
        output.append('Case #' + str(case_number + 1) + ': ' + result)
    output = '\n'.join(output)

    should_write = False
    should_write = True
    if should_write:
        write_answer(arg1 + '.out', output)
    else:
        print 'NOT WRITING ANYTHING \n'


def write_answer(name, output):
    f = open(name, 'w+')
    f.write(output)
    f.close()
    print 'ANSWERS WRITTEN\n'


if __name__ == '__main__':
    if len(sys.argv) == 2:
        sys.exit(main(sys.argv[1]))
    else:
        unittest.main()
