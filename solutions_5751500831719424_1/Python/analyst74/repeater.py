__author__ = 'Bill'

# developed with python3.3 + numpy

import sys, time, numpy as np


def parse_case(file):
    n = int(file.readline())
    strings = []
    for i in range(n):
        strings.append(file.readline().strip('\n'))

    return strings

def process_case(case):
    strings = case

    baseForms = []
    repeats = []
    for s in strings:
        f, r = process_string(s)
        baseForms.append(f)
        repeats.append(r)

    if not is_same(baseForms):
        return "Fegla Won"

    return calc_count(repeats)

def process_string(s):
    cur = ''
    repeat = []
    baseForm = ''
    r = 0
    for i in range(len(s)):
        if cur == s[i]:
            r += 1
        else:
            cur = s[i]
            baseForm += cur
            if r > 0:
                repeat.append(r)
            r = 1
    repeat.append(r)

    return baseForm, repeat


def is_same(baseForms):
    first = baseForms[0]
    for f in baseForms:
        if first != f:
            return False

    return True

def calc_count(repeats):
    npArr = np.array(repeats)
    result = []
    for col in npArr.T:
        result.append(get_sum_distance(col))

    return sum(result)

def get_sum_distance(arr):
    nr = sorted(arr)
    if len(nr) % 2 == 0:
        median = nr[int(len(nr)/2)]
    else:
        median = nr[int((len(nr)-1)/2)]

    result = 0
    for n in nr:
        result += abs(n-median)

    return int(result)

if __name__ == '__main__':
    t0 = time.clock()

    if len(sys.argv) > 1:
        filename = sys.argv[1]
    else:
        filename = "sample.in"

    input_file = open(filename, "r")
    output_file = open(filename.replace('in','out'), "w")
    case_count = int(input_file.readline())
    for i in range(case_count):
        result = process_case(parse_case(input_file))
        output_line = 'Case #%d: %s\n' % (i+1, result)
        print(output_line)
        output_file.writelines(output_line)

    input_file.close()
    output_file.close()

    print('Total Time: %s' % str(time.clock() - t0))