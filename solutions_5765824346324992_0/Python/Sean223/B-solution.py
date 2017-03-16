__author__ = 'sean'

from fractions import gcd

# io_type = 'test'
io_type = 'small'
# io_type = 'large'

if io_type == 'large':
    IN_FILE = 'B-large.in'
    OUT_FILE = 'large_out.txt'

elif io_type == 'small':
    IN_FILE = 'B-small.in'
    OUT_FILE = 'small_out.txt'

else:
    IN_FILE = 'test_input.txt'
    OUT_FILE = 'test_output.txt'


with open(IN_FILE, 'r') as fileIn:
    fileLines = fileIn.readlines()

it = iter(fileLines)
numbCases = int(next(it))
output = ""


def lcm(values):
    current_lcm = values[0]
    for i in range(1, len(values)):
        current_lcm = (current_lcm * values[i]) // gcd(current_lcm, values[i])

    return current_lcm


for case in range(numbCases):
    first_line = next(it).rstrip().split(' ')
    b, n = int(first_line[0]), int(first_line[1])
    barber_times = [int(i) for i in next(it).rstrip().split(' ')]

    barber_next_available = [0 for i in range(b)]
    mapping = {}
    current_person = 1

    lcm_time = lcm(barber_times)
    for minute in range(0, lcm_time):
        for barber_number in range(1, b+1):
            barber_index = barber_number-1
            if barber_next_available[barber_index] == 0:
                mapping[current_person] = barber_number
                current_person += 1
                barber_next_available[barber_index] = barber_times[barber_index] - 1
            else:
                barber_next_available[barber_index] -= 1

    total_people = current_person - 1
    equivalent_n = n % total_people

    if equivalent_n == 0:
        equivalent_n = total_people
    answer = mapping[equivalent_n]

    line = "Case #{0}: {1}\n".format(str(case+1), str(answer))
    output += line


with open(OUT_FILE, 'w') as fileOut:
    fileOut.write(output)