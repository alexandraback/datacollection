'''
Created on May 3, 2014

@author: sergey

Problem A. The Repeater
'''

import os


def get_data(fullpath):
    if(not os.path.exists(fullpath)):
        print 'file does not exist'
        return []

    result = []
    is_first_line = True
    line_in_test = 0
    number_of_test_cases = 0
    with open(fullpath, 'r') as input_file:
        for line in input_file:

            print '---', line_in_test, line
            if(is_first_line):
                is_first_line = False
                number_of_test_cases = int(line)
                if(number_of_test_cases >= 1 and number_of_test_cases <= 100):
                    line_in_test = 1
                    continue

                print 'invalid number of test cases', number_of_test_cases
                return []

            if(line_in_test == 1):
                n = int(line)
                if(n < 2 or n > 100):
                    print "invalid n", n
                    return []
                result += [{
                            'n': n,
                            's': []
                             }]
                line_in_test += 1

            elif(line_in_test > 1):
                s = line.strip()
                result[-1]['s'] += [s]
                if(line_in_test == (result[-1]['n'] + 1)):
                    line_in_test = 1
                    continue
                line_in_test += 1

    print 'expected', number_of_test_cases, 'test cases, got', len(result)
    if(number_of_test_cases != len(result)):
        return []

    return result

def normalize_string(s):
    result = s[0]
    for i in s[1:]:
        if(result[-1] != i):
            result += i
    return result

def list_of_tuples(s):

    prev = s[0]
    result = [(prev, 0)]
    for i in s:
        if(i == prev):
            item, count = result[-1]
            result[-1] = (item, count + 1)
        else:
            prev = i
            result += [(prev, 1)]
    return result

def get_solution_for_tuple(index, tuples_s):
    t = []
    for i in tuples_s:
        c, counter = i[index]
        t += [counter]

    results = {}
    for i in xrange(len(t)):
        results[i] = 0
        for j in xrange(len(t)):
            results[i] += abs(t[i] - t[j])
    return min(results.values())

def get_result3(s):
    string_are_equal = True
    for i in s[1:]:
        if(s[0] != i):
            string_are_equal = False
            break
    if(string_are_equal):
        return '0'

    normalized_s = [normalize_string(i) for i in s]
    for i in normalized_s[1:]:
        if(normalized_s[0] != i):
            return 'Fegla Won'

    tuples_s = [list_of_tuples(i) for i in s]

    result = 0
    for i in xrange(len(tuples_s[0])):
        result += get_solution_for_tuple(i, tuples_s)

    return str(result)

def main():

    input_filename = 'A-large.in'
    output_filename = 'A-large.out'

    data = get_data(input_filename)
    for item in data:
        print item

    print '-' * 75

    with open(output_filename, 'wb') as output_file:
        case_number = 0
        for item in data:
            case_number += 1

            if(case_number == 2):
                pass

            result = get_result3(item['s'])

            print 'Case #%d: %s' % (case_number, result), item
            output_file.write('Case #%d: %s\n' % (case_number, result))

if __name__ == "__main__":
    main()
