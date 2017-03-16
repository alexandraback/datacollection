import sys
import string


chars = string.ascii_uppercase

def solve(number):
    senators = map(int, number.split())
    if len(senators) == 2 and senators[0] == senators[1]:
        return 'AB ' * senators[0]

    plan = ''
    while not all_evacuated(senators):
        plan = plan + chars[get_biggest(senators)]

        if sum(i > 0 for i in senators) == 1:
            plan = plan + chars[get_biggest(senators)]
        plan = plan + ' '
    return plan

def all_evacuated(l):
    return max(l) == 0

def get_biggest(l):
    max_ = max(l)
    index = l.index(max_)
    num = l[index]
    l[index] = l[index] - 1

    return index

filename = 'input.txt'
if len(sys.argv) > 1:
    filename = sys.argv[1]

with open(filename, 'r') as f:
    data = f.read()

    data = data.split("\n")
    data.pop(0)

    case = 0
    number = 0
    for line in data:
        number = number + 1
        if number % 2 != 0: continue
        if line == '': continue
        case = case + 1

        print "Case #{}: {}".format(case, solve(line))


