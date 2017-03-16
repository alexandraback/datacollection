#!/bin/env python

input_file = None

import os
import sys

times = None

def calc(minutes, target):
        return -1

def binary_search(low, high, target):
    while True:
        minutes = int((low + high) / 2)
        hit = len(times)
        matches = []
        for barber, t in enumerate(times):
            hit += int(minutes / t)
            if minutes % t == 0:
                matches.append(barber + 1)
        if target > hit - len(matches) and target <= hit:
            return matches[target - (hit - len(matches)) - 1]
        elif target <= hit - len(matches):
            high = (high + low) / 2
        else:
            low = (high + low + 1) / 2

def main():
    global times
    cases = readone(int)
    output = []
    for case_num in range(1, cases + 1):
        result = None
        ### Begin solution code
        b, n = readmany(int)
        times = readmany(int)
        m = min(times)
        maxtime = (n - b) * m
        if n <= b:
            result = n
        else:
            result = binary_search(0, maxtime, n)
        ### End solution code
        output.append('Case #%d: ' % (case_num,) + str(result))
    output_file = open(output_filename, 'w')
    output_file.write('\n'.join(output))
    output_file.close()
    if output_filename.endswith('sample.out'):
        their_output = open('B-their-sample.out')
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
    if os.path.exists('B-large.in'):
        input_file = open('B-large.in')
        output_filename = 'B-large.out'
    elif os.path.exists('B-small.in'):
        input_file = open('B-small.in')
        output_filename = 'B-small.out'
    elif os.path.exists('B-sample.in'):
        input_file = open('B-sample.in')
        output_filename = 'B-sample.out'
    main()
    input_file.close()