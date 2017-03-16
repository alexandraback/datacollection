#!/usr/bin/python

import sys, datetime
import itertools
import string
import math
import random

# Import third-party libraries (optional)
# https://code.google.com/p/gmpy/
# import gmpy

alphabet = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']

def solve(senators):
    '''
    ' Write your code here
    ' Return solution
    '''
    sen_dict = {alphabet[i]: x for i, x in enumerate(senators)}

    sen_list = sorted(sen_dict.iteritems(), key=lambda (k, v): (-v, k))

    sen_dict.pop(sen_list[0][0], None)
    sen_dict.pop(sen_list[1][0], None)

    results = ''
    top_two_diff = sen_list[0][1] - sen_list[1][1]
    results += (sen_list[0][0] + sen_list[0][0] + ' ') * (top_two_diff / 2)
    if top_two_diff % 2 != 0:
        results += sen_list[0][0] + ' '

    for sen in sen_dict:
        num = sen_dict[sen]
        if (num / 2) != 0:
            results += (sen) * (num / 2) * 2 + ' '
        if num % 2 != 0:
            results += sen + ' '

    for x in xrange(0, sen_list[1][1]):
        results += (sen_list[0][0] + sen_list[1][0]) + ' '

    return results

def main():
    # Test if at least input file is provided
    if len(sys.argv) < 2:
        print 'Please provide input file'
        print 'Usage: %s inputfile [outputfile]' % sys.argv[0]
        return
    # Start time
    timestart = datetime.datetime.now()

    # Open input and output files
    try:
        inputFile = open(sys.argv[1])
    except:
        print 'Failed to read input file %s' % sys.argv[1]
        return
    try:
        outputFile = open(sys.argv[2], 'w') if len(sys.argv) >= 3 else None
    except:
        print 'Failed to create output file %s' % sys.argv[2]
        return

    # First line of input file usually is the number of test cases.
    # Adjust if necessary
    testCases = int(inputFile.readline().strip())

    # Display number of test cases and output file name
    print '-----------------'
    print 'Test cases: %d ' % testCases
    print 'No output file' if len(sys.argv) < 3 else 'Writing to %s' % sys.argv[2]
    print '-----------------'

    # Loop through all test cases
    for testCaseNumber in range(1, testCases+1):

        '''
        ' Edit this section
        ' Read Test Case input and adjust output format
        ' Uncomment the necessary parts and adjust to your needs
        '''

        '''
        ' Integers
        '''
        # Read an integer
        n = int(inputFile.readline().strip())


        # Read a list of integers
        n_list = map(int, inputFile.readline().strip().split())

        # Read a matrix of integers
        #n_matrix = []
        #for i in range(n):
        #    n_matrix.append(map(int, inputFile.readline().strip().split()))

        '''
        ' Floats
        '''
        # Read a float
        #f = float(inputFile.readline().strip())

        # Read a list of flots
        #f_list = map(float, inputFile.readline().strip().split())

        '''
        ' Strings
        '''
        # Read a string
        # s = inputFile.readline().strip()

        # Read a list of strings
        # s_list = inputFile.readline().strip().split()

        '''
        ' Return string.
        ' Add necessary arguments to solve() function
        ' Adjust return type if necessary (%s for string, %f for floats, etc)
        '''
        string = 'Case #%d: %s' % (testCaseNumber, solve(n_list))

        '''
        ' End of edit section
        '''

        # print return string and write it to output file
        print string
        if outputFile:
            outputFile.write(string + '\n')

    # Print some final info: output file name and execution time
    print '-----------------'
    print 'Written to %s' % sys.argv[2] if outputFile else 'No output file'
    print 'Elapsed time: %s' % (datetime.datetime.now() - timestart)
    print '-----------------'

    # Close input and output files
    inputFile.close()
    if outputFile:
        outputFile.close()

if __name__=='__main__':
    main()
    # test()