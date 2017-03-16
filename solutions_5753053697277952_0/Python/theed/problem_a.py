# pylint: disable=missing-docstring
import sys
# from collections import OrderedDict


def problem(case):
    plan = ""
    while sum(case) != 0:
        i, num = max(enumerate(case), key=lambda x: x[1])
        case[i] -= 1
        plan += chr(65 + i)
        if max(case) > sum(case) / 2:
            i2, num = max(enumerate(case), key=lambda x: x[1])
            case[i2] -= 1
            plan += chr(65 + i2)
        if sum(case) != 0:
            plan += " "
    return plan


def main():
    name = sys.argv[1]
    with open(name, 'r') as input_file:
        content = input_file.read()
    lines = content.splitlines()
    num = lines[0]
    result = ''
    for run in range(int(num)):
        case = lines[2 + run * 2].split(" ")
        case = [int(x) for x in case]
        result += 'Case #{}: {}\n'.format(1 + run, problem(case))
    with open(name.replace('in', 'sol'), 'w') as result_file:
        result_file.write(result)


def test():
    cases = {

    }
    for inp, expected in cases.items():
        actual = problem(inp)
        assert actual == expected, 'Got {}, expected {} on {}'.format(
            actual, expected, inp)


if __name__ == '__main__':
    main()
