import sys
import os
from itertools import islice 


def problem_specific_parser(src):
    def aux():
        selected_line = int(next(src))
        board = [[int(e) for e in l.split()] for l in islice(src, 4)]
        return (selected_line, board)

    return aux(), aux()


def solve(data):
    t0, t1 = data
    sl0, b0 = t0
    l0 = set(b0[sl0 - 1])

    sl1, b1 = t1
    l1 = set(b1[sl1 - 1])
    num = l0.intersection(l1)
    if not num:
        return "Volunteer cheated!"
    if len(num) > 1:
        return "Bad magician!"
    return num.pop()


def parse(src):
    lines = iter(src.split(os.linesep))
    nproblems = int(next(lines))

    for problem in range(nproblems):
        yield problem_specific_parser(lines)


def main():
    src = sys.stdin.read()
    for i, data in enumerate(parse(src)):
        print("Case #{0}: {1}".format(i + 1, solve(data)))

    
if __name__ == '__main__':
    main()
