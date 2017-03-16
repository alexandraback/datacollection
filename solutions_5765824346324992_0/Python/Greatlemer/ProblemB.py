# Written for Python 2.7.9

from optparse import OptionParser
from StringIO import StringIO
import sys

# Expected format of TEST_CASES is a list of tuples of (input, expected_output)
TEST_CASES = [("""3
2 4
10 5
3 12
7 7 7
3 8
4 2 1
""","""Case #1: 1
Case #2: 3
Case #3: 1
""")]


def gcd(a, b):
    # Euclid's algorithm for greatest common divisor
    while b:
        a, b = b, a % b
    return a

def lcm(a, b):
    return a * b / gcd(a, b)


def parse_input(input_reader):
    case_count = int(input_reader.readline())
    case_idx = 0
    while case_count > case_idx:
        case_idx += 1
        # Implementation of parsing code goes here.
        bits = input_reader.readline().strip().split()
        speeds = input_reader.readline().strip().split()
        input_values = {"case": case_idx,}
        input_values['barbers'] = int(bits[0])
        input_values['position'] = int(bits[1])
        input_values['speeds'] = [int(x) for x in speeds]
        yield input_values


def served_by(barbers, speeds, position):
    if position <= barbers:
        return position
    # After this time we're effectively back at the start
    min_cycle = reduce(lcm, speeds, 1)
    customers_seen = 0
    for speed in speeds:
        customers_seen += min_cycle / speed
    # Position after removing extra cycles
    position -= (customers_seen * (position / customers_seen))
    if position == 0:
        position = customers_seen
    if position <= barbers:
        return position
    serving = list(speeds)
    position -= barbers
    while position:
        index = 0
        min_time = 100001
        while index < barbers:
            if serving[index] == 0:
                serving[index] = speeds[index]
                position -= 1
                if position == 0:
                    return index + 1
            if min_time > serving[index]:
                min_time = serving[index]
            index += 1
        serving = [(time - min_time) for time in serving]


def solve_problem(output_writer=sys.stdout, **kwargs):
    case = kwargs['case']
    barbers = kwargs['barbers']
    position = kwargs['position']
    speeds = kwargs['speeds']

    answer = "{0}".format(served_by(barbers, speeds, position))
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