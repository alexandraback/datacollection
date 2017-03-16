def first_method(mushrooms):
    value = 0
    for i in xrange(1, len(mushrooms)):
        if mushrooms[i] < mushrooms[i - 1]:
            value += mushrooms[i-1] - mushrooms[i]
    return value


def second_method(mushrooms):
    maximum_diff = 0
    for i in xrange(1, len(mushrooms)):
        maximum_diff = max(mushrooms[i-1] - mushrooms[i], maximum_diff)
    value = 0
    for i in xrange(0, len(mushrooms) - 1):
        value += min(mushrooms[i], maximum_diff)
    return value


input_file = open('a-small.in')
cases = int(input_file.readline().strip())
case = 0
while case < cases:
    case += 1
    input_file.readline()
    mushrooms = [int(c) for c in input_file.readline().strip().split(' ')]
    first = first_method(mushrooms)
    second = second_method(mushrooms)
    print "Case #{}: {} {}".format(case, first, second)
