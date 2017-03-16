#!/usr/bin/python

import sys, datetime

def solve(n,l):
    c1 = 0
    d = 0
    for i in xrange(n-1):
        if l[i] > l[i+1]:
            c1 += l[i]-l[i+1]
            d = max(d,l[i]-l[i+1])
    c2 = 0
    for i in xrange(n-1):
        c2 += min(d, l[i])

    return "%d %d" % (c1,c2)

def parse(input_file):
        n = int(input_file.readline().strip())
        l = map(int, input_file.readline().strip().split())
        return  (n,l)

def main():
    start = datetime.datetime.now()
    input_file = open(sys.argv[1])
    output_file = None
    if len(sys.argv) >= 3:
        output_file = open(sys.argv[2], 'w')
    test_cases = int(input_file.readline().strip())
    print '-----------------'
    print 'Test cases: %d ' % test_cases
    if output_file:
        print 'Writing to %s' % sys.argv[2]
    else:
        print 'No output file'
    print '-----------------'
    for test_case_number in xrange(1, test_cases+1):
        string = 'Case #%d: %s' % (test_case_number, solve(*parse(input_file)))
        print string
        if output_file:
            output_file.write(string + '\n')
    print '-----------------'
    if output_file:
        print 'Written to %s' % sys.argv[2]
    else:
        print 'No output file'
    print 'Elapsed time: %s' % (datetime.datetime.now() - start)
    print '-----------------'
    input_file.close()
    if output_file:
        output_file.close()

if __name__ == '__main__':
    main()
