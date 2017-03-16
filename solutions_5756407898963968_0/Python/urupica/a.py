#!/usr/bin/python

import sys, datetime

def solve(n, cards1, m, cards2):
    row1 = set(cards1[n-1])
    row2 = set(cards2[m-1])
    inter = row1.intersection(row2)
    if len(inter) == 1:
        return inter.pop()
    if len(inter) > 1:
        return 'Bad magician!'
    return 'Volunteer cheated!'




def main():
    if len(sys.argv) < 2:
        print 'Please provide input file'
        print 'Usage: %s inputfile [outputfile]' % sys.argv[0]
        return
    timestart = datetime.datetime.now()

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

    testCases = int(inputFile.readline().strip())

    print '-----------------'
    print 'Test cases: %d ' % testCases
    print 'No output file' if len(sys.argv) < 3 else 'Writing to %s' % sys.argv[2]
    print '-----------------'

    for testCaseNumber in range(1, testCases+1):

        n = int(inputFile.readline().strip())
        cards1 = []
        for i in range(4):
            cards1.append(map(int, inputFile.readline().strip().split()))

        m = int(inputFile.readline().strip())
        cards2 = []
        for i in range(4):
            cards2.append(map(int, inputFile.readline().strip().split()))

        string = 'Case #%d: %s' % (testCaseNumber, solve(n, cards1, m, cards2))

        print string
        if outputFile:
            outputFile.write(string + '\n')

    print '-----------------'
    print 'Written to %s' % sys.argv[2] if outputFile else 'No output file'
    print 'Elapsed time: %s' % (datetime.datetime.now() - timestart)
    print '-----------------'

    inputFile.close()
    if outputFile:
        outputFile.close()

if __name__=='__main__':
    main()
