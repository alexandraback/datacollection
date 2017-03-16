import sys
num_tests = int(sys.stdin.readline())
tests = []


class TestCase(object):
    def __init__(self, number):
        self.number = number
        self.arrangements = []

    def add_arrangement(self, answer, arrangement):
        self.arrangements.append((answer, arrangement))

    def solve(self):
        sieved = [0] * 16
        for answer, arrangement in self.arrangements:
            for i in arrangement[answer]:
                sieved[i] += 1
        result = [i + 1 for i, n in enumerate(sieved) if n == 2]
        if not result:
            print 'Case #{0}: Volunteer cheated!'.format(self.number)
        elif len(result) == 1:
            print 'Case #{0}: {1}'.format(self.number, result[0])
        else:
            print 'Case #{0}: Bad magician!'.format(self.number)

    def __repr__(self):
        return repr(self.arrangements)

for i in range(num_tests):
    test_case = TestCase(i + 1)
    tests.append(test_case)

    for _ in range(2):
        answer = int(sys.stdin.readline()) - 1
        arrangement = []
        for _ in range(4):
            row = [int(x) - 1 for x in sys.stdin.readline().split()]
            arrangement.append(row)

        test_case.add_arrangement(answer, arrangement)

#print tests
for test_case in tests:
    test_case.solve()
