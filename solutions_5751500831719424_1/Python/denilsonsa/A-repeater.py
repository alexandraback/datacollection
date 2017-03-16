#!/usr/bin/env python2

from __future__ import division
from __future__ import print_function

import multiprocessing
import sys
sys.setrecursionlimit(20000)

try:
    # Python2 compatibility
    input = raw_input
except:
    pass


def get_letters(s):
    letters = []
    counts = []
    last_letter = ''
    for letter in s:
        if letter != last_letter:
            letters.append(letter)
            counts.append(1)
            last_letter = letter
        else:
            counts[-1] += 1
    return letters, counts


def calc_cost(nums):
    return min(
        sum( abs(n - target) for n in nums )
        for target in range(min(nums), max(nums) + 1)
    )


def solve_testcase(N, strings):
    tmp = [ get_letters(s) for s in strings ]
    letters = [ l for l, c in tmp]

    if any(letters[0] != l for l in letters[1:]):
        return 'Fegla Won'

    # Letter count by string, i.e. counts[i] is the string i.
    counts = [ c for l, c in tmp]
    # Transposing, now counts[i] are all the counts for the letter i.
    counts = zip(*counts)

    costs = [ calc_cost(c) for c in counts ]

    return sum(costs)


def print_testcase(params):
    num, args = params
    return 'Case #{0}: {1}'.format(num, solve_testcase(*args))


def read_testcase_input():
    N = int(input())
    strings = [input().strip() for i in range(N)]
    return (N, strings)


def main():
    num_testcases = int(input())
    testcase_input = [
        (i + 1, read_testcase_input()) for i in range(num_testcases)
    ]
    pool = multiprocessing.Pool()
    answers = pool.map(print_testcase, testcase_input, 1)
    for answer in answers:
        print(answer)


if __name__ == '__main__':
    main()
