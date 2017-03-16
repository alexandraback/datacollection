# -*- coding: utf-8 -*-

from itertools import groupby

def solve(xs):
    assert 2 <= len(xs)

    f = lambda x: ''.join(k for k, f in groupby(x))
    origin = f(xs[0])
    for x in xs:
        if origin != f(x):
            return 'Fegla Won'

    repeats = [[len(xs[0])] * len(origin) for i in xrange(len(xs))]
    for i, x in enumerate(xs):
        cursor = 0
        for j, c in enumerate(origin):
            repeat = 0
            while cursor < len(x) and x[cursor] == c:
                repeat += 1
                cursor += 1
            repeats[i][j] = repeat

    count = 0
    for j in xrange(len(origin)):
        nums = sorted([repeats[i][j] for i in xrange(len(xs))])
        base = nums[len(nums) / 2]
        for i in xrange(len(xs)):
            count += abs(base - repeats[i][j])
    return count


T = int(raw_input())
for test_case in xrange(1, T + 1):
    N = int(raw_input())
    S = [raw_input() for i in xrange(N)]

    answer = solve(S)
    print 'Case #{}: {}'.format(test_case, answer)
