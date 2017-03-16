
import argparse

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
    numbers = [int(x) for x in input.split()]
    numbers.reverse()

    cases_count = numbers.pop()

    cases = []
    for i in xrange(cases_count):
        chosen1 = numbers.pop()
        rows1 = [[numbers.pop() for x in xrange(4)] for y in xrange(4)]

        chosen2 = numbers.pop()
        rows2 = [[numbers.pop() for x in xrange(4)] for y in xrange(4)]

        cases.append((chosen1, rows1, chosen2, rows2))

    assert(len(numbers) == 0)

    return cases

def solve(case):
    chosen1, rows1, chosen2, rows2 = case

    cards1 = rows1[chosen1 - 1]
    cards2 = rows2[chosen2 - 1]

    intersection = set(cards1) & set(cards2)

    if len(intersection) == 0:
        return 'Volunteer cheated!'
    elif len(intersection) == 1:
        card = intersection.pop()
        return str(card)
    else:
        return 'Bad magician!'

def format_solution(solution, index):
    format = 'Case #%d: %s'
    return format % (index + 1, solution)

if __name__ == '__main__':
    main()
