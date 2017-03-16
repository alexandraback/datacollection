def result(test):
    p1 = test['1p'] - 1
    p2 = test['2p'] - 1
    r1 = test['1t'][p1]
    r2 = test['2t'][p2]
    u = None
    for i in r1:
        if i in r2:
            if u is None:
                u = i
            else:
                return 'Bad magician!'
    if u is None:
        return 'Volunteer cheated!'
    else:
        return str(u)


def valid_16(data):
    if not len(data) == 4:
        return -1
    else:
        for i in data:
            if not len(i) == 4:
                return -1
    return 1


def valid_test(test):
    if '1p' not in test:
        print 'no 1p'
        return -1
    elif test['1p'] > 4 or test['1p'] < 1:
        print 'invalid 1p'
        return -1
    if '2p' not in test:
        print 'no 2p'
        return -1
    elif test['2p'] > 4 or test['2p'] < 1:
        print 'invalid 2p'
        return -1
    if '1t' not in test:
        print 'no 1t'
        return -1
    if '2t' not in test:
        print 'no 2t'
        return -1
    if not valid_16(test['1t']):
        print 'invalid 1t'
        return -1
    if not valid_16(test['2t']):
        print 'invalid 2t'
        return -1
    return 1


def main():
    with open('magictrick_input.txt', 'r') as f:
        testcase = {'count': 0, 'tests': []}
        test = {}
        for i, l in enumerate(f):
            l = l.strip()
            if i == 0:
                testcase['count'] = int(l)
            elif (i - 1) % 10 == 0:
                if test and valid_test(test) == 1:
                    testcase['tests'].append(test)
                test = {}
                test['1p'] = int(l)
            elif (i - 1) % 10 in (1, 2, 3, 4):
                if '1t' not in test:
                    test['1t'] = []
                test['1t'].append(l.split(' '))
            elif (i - 1) % 10 == 5:
                test['2p'] = int(l)
            elif (i - 1) % 10 in (6, 7, 8, 9):
                if '2t' not in test:
                    test['2t'] = []
                test['2t'].append(l.split(' '))
        if test and valid_test(test) == 1:
            testcase['tests'].append(test)

    if not testcase['count'] == len(testcase['tests']):
        print testcase['count'], len(testcase['tests'])
        raise ValueError

    for i, t in enumerate(testcase['tests']):
        print 'Case #%d: %s' % ((i + 1), result(t))


if __name__ == '__main__':
    main()
