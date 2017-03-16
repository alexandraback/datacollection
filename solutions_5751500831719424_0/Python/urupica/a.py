#!/usr/bin/python

import sys, datetime

def solve(n, l):
    seq = ''
    for x in l[0]:
        if seq == '' or seq[-1] != x:
            seq += x
    stats = [[0]*len(seq) for i in xrange(n)]
    for i, s in enumerate(l):
        if s[0] != seq[0]:
            return "Fegla Won"
        j = 0
        for x in s:
            if x == seq[j]:
                stats[i][j] += 1
                continue
            else:
                j += 1
                if j >= len(seq) or  x != seq[j]:
                    return "Fegla Won"
                else:
                    stats[i][j] += 1
        if j != len(seq)-1:
            return "Fegla Won"

    c = 0
    for i in xrange(len(seq)):
        m = None
        for z in xrange(min(stats[j][i] for j in xrange(n)), max(stats[j][i] for j in xrange(n))+1):
            s = sum(abs(z-stats[k][i]) for k in xrange(n))
            if m == None or s < m:
                m = s
        c += m
    return c





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

        s = []
        for i in xrange(n):
            s.append(inputFile.readline().strip())

        string = 'Case #%d: %s' % (testCaseNumber, solve(n, s))

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
