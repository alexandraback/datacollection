# Written for Python 2.7.5

from optparse import OptionParser
from StringIO import StringIO
import re
import sys

# Expected format of TEST_CASES is a list of tuples of (input, expected_output)
TEST_CASES = [("""5
2
mmaw
maw
2
gcj
cj
3
aaabbb
ab
aabb
2
abc
abc
3
aabc
abbc
abcc
""","""Case #1: 1
Case #2: Fegla Won
Case #3: 4
Case #4: 0
Case #5: 3
""")]

def parse_input(input_reader):
    case_count = int(input_reader.readline())
    case_idx = 0
    while case_count > case_idx:
        case_idx += 1
        # Implementation of parsing code goes here.
        string_count = int(input_reader.readline())
        string_idx = 0
        strings = []
        while string_count > string_idx:
            string_idx += 1
            strings.append(input_reader.readline())
        input_values = {"case": case_idx,
                        "string_count": string_count,
                        "strings": strings
                       }
        yield input_values


def solve_problem(output_writer=sys.stdout, **kwargs):
    case = kwargs['case']
    string_count = kwargs['string_count']
    strings = kwargs['strings']
    msg = "Fegla Won" # Default if it's a loss
    fail = False

    if all([s==strings[0] for s in strings]):
        msg = 0
    else:
        letter_pattern = ['^']
        last_letter = None
        for letter in strings[0]:
            if letter != last_letter:
                letter_pattern.append("(%s+)" % letter)
            last_letter = letter
        letter_pattern.append('$')
        full_pattern = re.compile("".join(letter_pattern))
        groups = []
        avgs = []
        for string in strings:
            match = full_pattern.match(string)
            if not match:
                fail = True
                break
            groups.append([len(g) for g in match.groups()])
        if not fail:
            msg = 0
            for idx in range(len(groups[0])):
                avgs.append(int(round(reduce(lambda x,y: y[idx] + x, groups, 0)/float(string_count))))
                msg += reduce(lambda x,y: abs(y[idx] - avgs[idx]) + x, groups, 0)
    print >>output_writer, "Case #%d: %s" % (case, msg)

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