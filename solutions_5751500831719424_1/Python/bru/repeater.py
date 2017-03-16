#!/usr/bin/env python
import fileinput
from itertools import groupby


def median(numbers):
    numbers = sorted(numbers)
    l = len(numbers)
    return numbers[l / 2]


def solve(game):
    all_letters = [[l for l, _ in groupby(g)] for g in game]
    first = all_letters[0]
    if any(first != other for other in all_letters[1:]):
        return None

    # get letter count for each word
    letters_count = [[len(list(letters)) for _, letters in groupby(g)] for g in game]

    moves = 0
    for letter_idx in range(len(letters_count[0])):
        # go for each letter
        letters = [count[letter_idx] for count in letters_count]
        med = median(letters)
        moves += sum(abs(l - med) for l in letters)
    return moves


def make_answer(case, solution):
    if solution is None:
        solution = "Fegla Won"
    return "Case #%i: %s" % (case, solution)


def get_input(lines):
    nextline = lambda: next(lines)
    cases = int(nextline())
    for _ in range(cases):
        string_c = int(nextline())
        strings = []
        for _ in range(string_c):
            strings.append(nextline())
        yield strings


def main():
    for i, game in enumerate(get_input(fileinput.input()), 1):
        print(make_answer(i, solve(game)))

if __name__ == '__main__':
    main()
