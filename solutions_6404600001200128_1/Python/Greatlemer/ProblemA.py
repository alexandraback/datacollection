# Written for Python 2.7.9

from optparse import OptionParser
from StringIO import StringIO
import sys

# Expected format of TEST_CASES is a list of tuples of (input, expected_output)
TEST_CASES = [("""4
4
10 5 15 5
2
100 100
8
81 81 81 81 81 81 81 0
6
23 90 40 0 100 9
""","""Case #1: 15 25
Case #2: 0 0
Case #3: 81 567
Case #4: 181 244
""")]

def parse_input(input_reader):
    case_count = int(input_reader.readline())
    case_idx = 0
    while case_count > case_idx:
        case_idx += 1
        # Implementation of parsing code goes here.
        intervals = int(input_reader.readline().strip())
        observations = input_reader.readline().strip().split()
        input_values = {"case": case_idx,}
        input_values['intervals'] = intervals
        input_values['observations'] = [int(x) for x in observations]
        yield input_values


def solve_problem(output_writer=sys.stdout, **kwargs):
    case = kwargs['case']
    intervals = kwargs['intervals']
    observations = kwargs['observations']
    max_eat = 0
    min_eat_1 = 0
    min_eat_2 = 0
    for index in range(intervals - 1):
        diff = observations[index] - observations[index + 1]
        if diff > max_eat:
            max_eat = diff
        if diff > 0:
            min_eat_1 += diff
    for index in range(intervals - 1):
        min_eat_2 += min(max_eat, observations[index])
    answer = "{0} {1}".format(min_eat_1, min_eat_2)
    # Implementation of code to solve the problem goes here.
    print >>output_writer, "Case #%d: %s" % (case, answer)

def solve_inputs(input_reader, output_writer):
    """
    Loop through each problem input in input reader and solve it.

    Outputs responses to output_writer.
    """
    for input_values in parse_input(input_reader):
        solve_problem(output_writer=output_writer, **input_values)

def run_tests():
    idx = 0
    all_pass = True
    for problem_input, expected_output in TEST_CASES:
        idx += 1
        input_reader = StringIO(problem_input)
        output_writer = StringIO()
        solve_inputs(input_reader, output_writer)
        problem_output = output_writer.getvalue()
        if problem_output == expected_output:
            print "Test %d: Success" % idx
        else:
            all_pass = False
            print "Test %d: Failure" % idx
        print problem_output
        input_reader.close()
        output_writer.close()
    if all_pass:
        print "All tests were successful!"
    else:
        print "Something didn't match - try again."

def main():
    parser = OptionParser()
    parser.add_option("-f", "--file",
                      dest="filename_stem",
                      help="read input from FILE.in and write to FILE.out",
                      metavar="FILE")

    (options, args) = parser.parse_args()
    if options.filename_stem:
        print "Running in file mode."
        input_reader = open("%s.in" % options.filename_stem, "r")
        output_writer = open("%s.out" % options.filename_stem, "w")
        solve_inputs(input_reader, output_writer)
    else:
        print "Running in test mode."
        run_tests()

if __name__ == "__main__":
    main()