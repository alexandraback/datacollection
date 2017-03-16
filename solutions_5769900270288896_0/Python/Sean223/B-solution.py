__author__ = 'sean'

from itertools import combinations
from copy import deepcopy

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


for case in range(numbCases):
    line = next(it).rstrip().split(' ')
    r, c, n = int(line[0]), int(line[1]), int(line[2])

    apartments = [False for v in range(r*c)]

    apts = range(r*c)
    combos = combinations(apts, n)

    best = float("inf")

    for combo in combos:
        arrangement = apartments[:]
        current_unhappy = 0
        for value in combo:
            arrangement[value] = True

        for i in range(r*c):
            if arrangement[i]:
                current_row, current_col = i // c, i % c
                if current_col < c-1 and arrangement[i+1]:
                    current_unhappy += 1
                if current_row < r-1 and arrangement[i + c]:
                    current_unhappy += 1

        best = min(best, current_unhappy)

    answer = best

    line = "Case #{0}: {1}\n".format(str(case+1), str(answer))
    output += line


with open(OUT_FILE, 'w') as fileOut:
    fileOut.write(output)