__author__ = 'sean'

# io_type = 'test'
# io_type = 'small'
io_type = 'large'

if io_type == 'large':
    IN_FILE = 'A-large.in'
    OUT_FILE = 'large_out.txt'

elif io_type == 'small':
    IN_FILE = 'A-small.in'
    OUT_FILE = 'small_out.txt'

else:
    IN_FILE = 'test_input.txt'
    OUT_FILE = 'test_output.txt'


with open(IN_FILE, 'r') as fileIn:
    fileLines = fileIn.readlines()

it = iter(fileLines)
numbCases = int(next(it))
output = ""


for case in range(numbCases):
    n = int(next(it))
    mushrooms = [int(i) for i in next(it).rstrip().split(' ')]

    first_method = 0
    second_method = 0
    largest_decrease = 0

    for i in range(len(mushrooms)-1):
        difference = mushrooms[i] - mushrooms[i+1]
        first_method += max(difference, 0)
        largest_decrease = max(largest_decrease, difference)

    for i in range(len(mushrooms)-1):
        second_method += min(largest_decrease, mushrooms[i])

    line = "Case #{0}: {1} {2}\n".format(str(case+1), str(first_method), str(second_method))
    output += line


with open(OUT_FILE, 'w') as fileOut:
    fileOut.write(output)