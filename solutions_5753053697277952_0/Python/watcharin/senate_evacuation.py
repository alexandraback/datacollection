import sys
import operator

def solve(n, p):
    # TODO Solve the problem
    rv = []
    remaining = sum(p)

    while remaining > 0:
        if remaining % 2 == 1:
            max_index, max_value = max(enumerate(p), key=operator.itemgetter(1))
            p[max_index] -= 1

            rv.append(chr(ord('A') + max_index))

            remaining -= 1
        else:
            pair = ''

            max_index, max_value = max(enumerate(p), key=operator.itemgetter(1))
            p[max_index] -= 1
            pair += chr(ord('A') + max_index)

            max_index, max_value = max(enumerate(p), key=operator.itemgetter(1))
            p[max_index] -= 1
            pair += chr(ord('A') + max_index)

            rv.append(pair)

            remaining -= 2

    return " ".join(rv)

### Convert the input file into a list of strings ###
in_file = sys.argv[1]

with open(in_file, "r") as f:
    data = f.read()

lines = data.splitlines()
### Convert the input file into a list of strings ###

### Interpret the arguments ###
cases = int(lines.pop(0))

for i in range(1, cases + 1):
    n = int(lines.pop(0))
    p = lines.pop(0).split()

    p = [ int(x) for x in p ]

    answer = solve(n, p)

    print 'Case #%d: %s' % (i, answer)
### Interpret the arguments ###
