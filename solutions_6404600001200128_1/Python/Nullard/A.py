#!/bin/env python

input_file = None

import os
import sys

def main():
    cases = readone(int)
    output = []
    for case_num in range(1, cases + 1):
        result = None
        ### Begin solution code
        readone(int)
        shrooms = readmany(int)
        last_s = 0
        max_diff = 0
        method_1 = 0
        method_2 = 0
        for s in shrooms:
            if s < last_s:
                method_1 += last_s - s
                max_diff = max(max_diff, last_s - s)
            last_s = s
        last_s = 0
        for s in shrooms:
            if last_s < max_diff:
                method_2 += last_s
            else:
                method_2 += max_diff
            last_s = s
        result = '%d %d' % (method_1, method_2)
        ### End solution code
        output.append('Case #%d: ' % (case_num,) + str(result))
    output_file = open(output_filename, 'w')
    output_file.write('\n'.join(output))
    output_file.close()
    if output_filename.endswith('sample.out'):
        their_output = open('A-their-sample.out')
        for line_num, line in enumerate(output):
            their_line = their_output.readline().strip()
            if line == their_line:
                print line
            else:
                print line_num, ' yours :', line
                print line_num, ' theirs:', their_line
        their_output.close()
    else:
        print '\n'.join(output)

def readone(t):
    line = input_file.readline()
    assert(len(line.split()) == 1)
    return t(line.strip())

def readmany(t):
    return map(t, input_file.readline().split())

if __name__ == '__main__':
    input_file = sys.stdin
    output_filename = 'test.out'
    if os.path.exists('A-large.in'):
        input_file = open('A-large.in')
        output_filename = 'A-large.out'
    elif os.path.exists('A-small.in'):
        input_file = open('A-small.in')
        output_filename = 'A-small.out'
    elif os.path.exists('A-sample.in'):
        input_file = open('A-sample.in')
        output_filename = 'A-sample.out'
    main()
    input_file.close()