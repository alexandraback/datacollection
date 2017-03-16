import math

def read_case(input_file):
    num_lines = int(input_file.readline())
    fegla_lines = []
    for i in xrange(num_lines):
        fegla_lines.append(input_file.readline())
    return fegla_lines

def solve_case(fegla_lines):
    count = 0

    num_lines = len(fegla_lines)

    # Cut return symbol.
    for i in xrange(num_lines):
        fegla_lines[i] = fegla_lines[i].replace('\n', '')
    #print fegla_lines

    while True:

        # Check strings.
        empty = 0
        non_empty = 0;
        for i in xrange(num_lines):
            if len(fegla_lines[i]) == 0:
                empty += 1
            else:
                non_empty += 1
        if empty * non_empty != 0:
            return -1
        if empty == num_lines:
            break

        # Check symbols.
        first_symbol = fegla_lines[0][0]
        for i in xrange(num_lines):
            if fegla_lines[i][0] != first_symbol:
                return -1

        # Read groups.
        heights = [0] * num_lines
        for i in xrange(num_lines):
            j = 0
            while fegla_lines[i][j] == first_symbol:
                j += 1
                if j == len(fegla_lines[i]):
                    break
            heights[i] = j

        # Cut lines.
        for i in xrange(num_lines):
            fegla_lines[i] = fegla_lines[i][heights[i]:]

        # Find average.
        avg = 0
        for i in xrange(num_lines):
            avg += heights[i]
        avg /= num_lines

        # Find distance.
        dist = 0
        for i in xrange(num_lines):
            dist += int(math.fabs(avg - heights[i]))

        count += dist

    return count

def write_solution(solution):
    pass

input = []
input_file = open('A.in', 'r')
output_file = open('A.out', 'w')

number_of_cases = int(input_file.readline())
print 'number_of_cases:', number_of_cases

for i in xrange(number_of_cases):
    case = read_case(input_file)
    solution = solve_case(case)
    output_str = 'Case #' + str(i + 1) + ': '
    if solution == -1:
        output_str += 'Fegla Won'
    else:
        output_str += str(solution)
    print output_str
    output_file.write(output_str + '\r\n')

print "Done!!!"