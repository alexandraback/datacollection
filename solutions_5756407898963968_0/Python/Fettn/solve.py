from optparse import OptionParser


def read_grid(input_file):
    answer = int(input_file.readline())
    grid = []
    for line in range(4):
        parts = input_file.readline().split()
        grid.append([int(i) for i in parts])
    return answer, grid


def solve_case(input_file):
    (choice1, grid1) = read_grid(input_file)
    possible_results = grid1[choice1 -1]
    (choice2, grid2) = read_grid(input_file)
    final_results = []
    for card in grid2[choice2 - 1]:
        if card in possible_results:
            final_results.append(card)
    if len(final_results) == 0:
        return 'Volunteer cheated!'
    elif len(final_results) == 1:
        return str(final_results[0])
    else:
        return 'Bad magician!'


def process_files(input_file, output_file):
    number_of_cases = int(input_file.readline())
    for case in range(number_of_cases):
        result = solve_case(input_file)
        output_file.write('Case #%i: %s\n' % (case + 1, result))


if __name__ == '__main__':
    parser = OptionParser()
    parser.add_option('-i', '--input', dest='inputFile',
                      help='test case file', metavar='FILE')
    parser.add_option('-o', '--output', dest='outputFile',
                      help='result file', metavar='FILE')
    (options, args) = parser.parse_args()

    if not options.inputFile or not options.outputFile:
        parser.error("options -a and -b are mutually exclusive")
    else:
        process_files(open(options.inputFile, 'r'), open(options.outputFile, 'w'))

