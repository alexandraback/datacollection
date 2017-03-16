__author__ = 'horban'

import unittest


def gen_cases(test_txt):
    els = test_txt.split()
    n = int(els.pop(0))
    for t in range(1, n + 1):
        a = els[:17]
        els = els[17:]
        b = els[:17]
        els = els[17:]
        yield t, a, b


def carts_pick(case1):
    row = int(case1.pop(0)) - 1
    return map(int, case1[0 + row * 4:4 + row * 4])


def answer(row, rowOne):
    s = set(row) & set(rowOne)
    if len(s) == 0:
        return 'Volunteer cheated!'
    elif len(s) == 1:
        return next(iter(s))
    else:
        return 'Bad magician!'

def solveCase(inName):
    with open(inName) as inf:
        with open(inName.replace('in', 'out'), 'w') as outf:
            for t, l1, l2 in gen_cases(inf.read()):
                a = answer(carts_pick(l1), carts_pick(l2))
                outf.write('Case #{}: {}\n'.format(t, a))

class TestA(unittest.TestCase):
    def setUp(self):
        self.test_txt = '''3
2
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
3
1 2 5 4
3 11 6 15
9 10 7 12
13 14 8 16
2
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
2
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
2
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
3
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16'''

        with open('test.in', 'w') as f:
            f.write(self.test_txt)

        self.case1 = (1,
                      ['2', '1', '2', '3', '4', '5', '6', '7', '8', '9', '10', '11', '12', '13', '14', '15', '16'],
                      ['3', '1', '2', '5', '4', '3', '11', '6', '15', '9', '10', '7', '12', '13', '14', '8', '16'])
        self.row = [5, 6, 7, 8]
        self.rowOne = [5, 0, 1, 2]
        self.rowMul = [5, 6, 0, 1]
        self.rowNone = [0, 1, 2, 3]


    def test_test_parse(self):
        self.assertEqual(self.case1,
                         next(gen_cases(self.test_txt)))

    def test_cards_pick(self):
        self.assertEqual(self.row, carts_pick(self.case1[1]))

    def test_ans(self):
        self.assertEqual(answer(self.row, self.rowOne), 5)
        self.assertEqual(answer(self.row, self.rowMul), 'Bad magician!')
        self.assertEqual(answer(self.row, self.rowNone), 'Volunteer cheated!')


