from __future__ import division
from __future__ import print_function
import itertools
from collections import defaultdict


def read_many(input_type=int):
    return map(input_type, raw_input().strip().split(' '))


def print_result(n, result):
    print('Case #%d: %s' % (n, result))


def read_task():
    return read_many()


def solve_flat(C, N):
    assert C > 1
    Y = C // 2 + C % 2
    m = N - Y
    if m <= 0:
        return 0
    else:
        if C % 2 == 1:
            return 2*m
        else:
            if m == 1:
                return 1
            else:
                return 1 + (m - 1)*2


def solve(task):
    R, C, N = task

    if N <= 1:
        return 0

    if R == 1 or C == 1:
        return solve_flat(max(R, C), N)

    Y = (R * C) // 2  + (R * C) % 2
    m = N - Y

    #max_unhappiness = (R - 1)*C + (C - 1)*R
    #print('max:', max_unhappiness)

    if m <= 0:
        return 0

    if R % 2 == 1 and C % 2 == 1:
        if m < 3:
            return 3 * m
        elif m == 3:
            return 8

        X = 2*(C // 2 + R // 2 - 2)

        if m - 3 <= X:
            return 8 + 3*(m - 3)

        occupied = X + Y + 3

        return 4*(N - occupied) + 3*X + 8

    elif R % 2 == 1 or C % 2 == 1:
        if R % 2 == 1:
            R, C = C, R
        X = 2*(R // 2 - 1) + C // 2 + C // 2 - 1
    else:
        X = 2*(C // 2 + R // 2 - 2)

    if m <= 2:
        return 2*m
    if m - 2 <= X:
        return 4 + 3*(m - 2)

    occupied = X + Y + 2
    return 4*(N - occupied) + 3*X + 4

if __name__ == '__main__':
    t = input()
    for i in range(t):
        task = read_task()
        result = solve(task)
        print_result(i + 1, result)
