'''
Created on Apr 11, 2014

@author: sergey

Problem A. Magic Trick
'''

import os


def get_data(fullpath):
    if(not os.path.exists(fullpath)):
        print 'file does not exist'
        return []

    result = []
    is_first_line = True
    number_of_test_cases = 0
    is_in_test_case = False
    line_in_test = 0
    with open(fullpath, 'r') as f:
        for line in f:

            print '---', line_in_test, line
            if(is_first_line):
                is_first_line = False
                t = int(line)
                if(t >= 1 and t <= 100):
                    print 'number of test cases', t
                    continue

                print 'invalid number of test cases', t
                return []

            if(is_in_test_case and line_in_test == 5):
                q2 = int(line)
                if(q2 < 1 or q2 > 4):
                    print "invalid q2", q2
                    return []
                result[-1]['q2'] = int(line)
                line_in_test += 1
            elif(is_in_test_case and line_in_test >= 1 and line_in_test <= 4):
                # using set it will be faster to compare
                row = set([int(i) for i in line.split(' ')])
                if(len(row) != 4):
                    print "invalid number of items in row"
                    return []
                result[-1]['q1_rows'] += [row]
                line_in_test += 1
            elif(is_in_test_case and line_in_test >= 6 and line_in_test <= 9):
                row = set([int(i) for i in line.split(' ')])
                if(len(row) != 4):
                    print "invalid number of items in row"
                    return []
                result[-1]['q2_rows'] += [row]
                line_in_test += 1
            else:
                q1 = int(line)
                if(q1 < 1 or q1 > 4):
                    print "invalid q1", q1
                    return []
                result += [{
                            'q1': q1,
                             'q1_rows': [],
                             'q2_rows': []
                             }]

                is_in_test_case = True
                line_in_test = 1

                continue

    return result

def main():

#     input_filename = 'A-test-small.in'
#     output_filename = 'A-test-small.out'
    input_filename = 'A-small-attempt1.in'
    output_filename = 'A-small-attempt1.out'

    data = get_data(input_filename)
    for item in data:
        print item

    print '-' * 75

    with open(output_filename, 'wb') as f:

        case_number = 0
        for item in data:
            case_number += 1
            row1 = item['q1_rows'][item['q1'] - 1]
            row2 = item['q2_rows'][item['q2'] - 1]

            print item['q1'], row1, item['q2'], row2

            intersection = row1.intersection(row2)
            print intersection
            intersection_length = len(intersection)
            print intersection_length
            if(intersection_length == 1):
                print 'Case #%d: %d' % (case_number, next(iter(intersection)))
                f.write('Case #%d: %d\n' % (case_number, next(iter(intersection))))
            elif(intersection_length == 0):
                print 'Case #%d: Bad magician!' % case_number
                f.write('Case #%d: Volunteer cheated!\n' % case_number)
            else:
                print 'Case #%d: Volunteer cheated!' % case_number
                f.write('Case #%d: Bad magician!\n' % case_number)



if __name__ == "__main__":
    main()
