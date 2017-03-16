#!/usr/bin/python

import sys, datetime

# https://code.google.com/p/gmpy/
from gmpy import lcm

def solve(b,n,m):
    if n <= b:
        return n
    if b == 1:
        return 1
    z = 1
    for i in xrange(b):
        z = lcm(z,m[i])
    c = sum(z/m[i] for i in xrange(b))
    if n%c != 0:
        n -= (n/c)*c
    else:
        n -= ((n-1)/c)*c
    if n <= b:
        return n
    t = list(m)
    for i in xrange(b,n-1):
        x = min(t)
        if x > 0:
            for j in xrange(b):
                t[j] -= x
        k = t.index(0)
        t[k] = m[k]
    x = min(t)
    k = t.index(x)
    return k+1

def parse(input_file):
        b,n = map(int, input_file.readline().strip().split())
        m = map(int, input_file.readline().strip().split())
        return (b,n,m)

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
