#!/usr/bin/env python
import sys


def read_arrangement():
    row = int(sys.stdin.readline())
    arrangement = []
    for _ in range(4):
        arrangement.append(map(int, sys.stdin.readline().strip().split()))
    return row, arrangement

def solve():
    possible_answers = set([i + 1 for i in range(16)])
    for _ in range(2):
        row, arrangement = read_arrangement()
        possible_answers &= set(arrangement[row - 1])
    if not possible_answers:
        return "Volunteer cheated!"
    if len(possible_answers) > 1:
        return "Bad magician!"
    return next(iter(possible_answers))

def main():
    num_tests = int(sys.stdin.readline())
    for test_id in range(num_tests):
        print "Case #{0}: {1}".format(test_id + 1, solve())

if __name__ == "__main__":
    main()
