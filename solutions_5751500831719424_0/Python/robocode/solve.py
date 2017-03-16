import argparse
from itertools import groupby
from pygame.transform import average_color


def main():
    args = parse_arguments()
    parse_and_solve(args.input, args.output)

def parse_arguments():
    parser = argparse.ArgumentParser()
    parser.add_argument('input', type=argparse.FileType('r'),
                        nargs='?', default='input.txt', help='input file')
    parser.add_argument('output', type=argparse.FileType('w'),
                        nargs='?', default='output.txt', help='output file')

    return parser.parse_args()

def parse_and_solve(input, output):
    content = input.read()

    cases = parse_input(content)

    solutions = [solve(case) for case in cases]

    formatted_solutions = [format_solution(solution, i) for i, solution in enumerate(solutions)]
    joined_solutions = '\n'.join(formatted_solutions)

    output.write(joined_solutions)
    print joined_solutions

def parse_input(input):
    elements = [x for x in input.split()]
    elements.reverse()

    cases_count = int(elements.pop())

    cases = []
    for i in xrange(cases_count):
        strings_count = int(elements.pop())
        strings = []
        for j in xrange(strings_count):
            string = elements.pop()
            strings.append(string)
        cases.append(strings)

    assert(len(elements) == 0)

    return cases

def solve(case):
    strings = case

    char_maps = []
    char_counts = []
    for string in strings:
        char_map = []
        counts = []
        for char, group in groupby(string):
            count = len(list(group))
            char_map.append(char)
            counts.append(count)
        char_maps.append(char_map)
        char_counts.append(counts)

    first_char_map = char_maps[0]
    if not all(x == first_char_map for x in char_maps):
        return 'Fegla Won'

    counts = transpose(char_counts)
    moves = 0
    for count in counts:
        amount = len(count)
        lowest = min(count)
        highest = max(count)
        # There's gotta be a smarter way to do this, but i don't have an idea right now...
        sums = []
        for x in xrange(lowest, highest+1):
            s = 0
            for value in count:
                d = abs(value - x)
                s += d
            sums.append(s)
        min_sum = min(sums)
        moves += min_sum

    return moves



def transpose(lists):
    return zip(*lists)


def format_solution(solution, index):
    format = 'Case #%d: %s'
    return format % (index + 1, solution)

if __name__ == '__main__':
    main()
