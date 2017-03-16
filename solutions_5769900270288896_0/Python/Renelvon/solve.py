#!/usr/bin/env python3
import sys


def main():
    input_file = sys.argv[1]
    solve(input_file)


def solve(input_file):
    with open(input_file) as f_in:
        t = int(next(f_in))
        for case in range(t):
            r, c, n = tuple(int(num) for num in next(f_in).split())
            r, c = sorted([r, c])
            output = solve_instance(r, c, n)
            print("Case #%d: %d" % (case + 1, output))


def solve_instance(r, c, n):
    if r == 1:
        return solve1(c, n)
    elif r == 2:
        return solve2(c, n)
    elif r == 3:
        return solve3(c, n)
    else:  # r == 4
        return solve4(n)


def solve1(c, n):
    if c % 2 == 1:
        if n <= (c + 1) // 2:
            return 0
        else:
            return (n - (c + 1) // 2) * 2
    else:
        if n <= c // 2:
            return 0
        elif n == c // 2 + 1:
            return 1
        else:
            return 1 + (n - c // 2 - 1) * 2


def solve2(c, n):
    if n <= c:
        return 0
    elif c < n <= c + 2:
        return (n - c) * 2
    else:
        return 4 + (n - c - 2) * 3


def solve3(c, n):
    if c == 3:
        if n <= 5:
            return 0
        elif n == 6:
            return 3
        elif n == 7:
            return 6
        elif n == 8:
            return 8
        else:  # n == 9
            return 12
    elif c == 4:
        if n <= 6:
            return 0
        elif n == 7:
            return 2
        elif n == 8:
            return 4
        elif n == 9:
            return 7
        elif n == 10:
            return 10
        elif n == 11:
            return 13
        else:  # n == 12
            return 17
    elif c == 5:
        if n <= 8:
            return 0
        elif n == 9:
            return 3
        elif n == 10:
            return 6
        elif n == 11:
            return 8
        elif n == 12:
            return 11
        elif n == 13:
            return 14
        elif n == 14:
            return 18
        else:  # n == 15
            return 22


def solve4(n):
    if n <= 8:
        return 0
    elif n == 9:
        return 2
    elif n == 10:
        return 4
    elif n == 11:
        return 7
    elif n == 12:
        return 10
    elif n == 13:
        return 13
    elif n == 14:
        return 16
    elif n == 15:
        return 20
    else:  # n == 16
        return 24


if __name__ == '__main__':
    main()
