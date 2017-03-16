#!/usr/bin/python

import os
import sys
import itertools
import numpy as np

def find_time(n, m):
    bound = [long(0), long(1.1e10)]

    while bound[1] - bound[0] > 1:
        t = (bound[1]-bound[0])/2+bound[0]
        if calc_count(m, t) < n:
            bound[0] = t
        else:
            bound[1] = t

    return bound[0]

def calc_count(m, t):
    return sum([t/mi+1 for mi in m])

def solve(f, skip=False):

    if skip: return 0
    b,n = f.read_long_list()
    m = f.read_long_list()

    if n <= len(m): return n

    t = find_time(n,m)
    print t

    s = calc_count(m, t)
    print s, n, [(t+1)%mi for mi in m]
    for i, mi in enumerate(m):
        if (t+1)%mi == 0:
            s += 1
            if s == n:
                return i+1


class Reader(object):
    def __init__(self, filename):
        self.f = open(filename)
        self.linenum = 1

    def read_int(self):
        self.linenum += 1
        return int(self.f.readline().strip())
    def read_float(self):
        self.linenum += 1
        return float(self.f.readline().strip())
    def read_long(self):
        self.linenum += 1
        return long(self.f.readline().strip())
    def read_str(self):
        self.linenum += 1
        return self.f.readline().strip()

    def read_int_list(self):
        self.linenum += 1
        return map(int, self.f.readline().split())
    def read_float_list(self):
        self.linenum += 1
        return map(float, self.f.readline().split())
    def read_long_list(self):
        self.linenum += 1
        return map(long, self.f.readline().split())
    def read_str_list(self):
        self.linenum += 1
        return self.f.readline().split()

if __name__ == '__main__':
    filename = sys.argv[1] if len(sys.argv) > 1 else sys.argv[0].replace('.py', '-sample.in')
    cnum = int(sys.argv[2]) if len(sys.argv) > 2 else None
    output = filename[:-3]+'.out' if filename[-3:] == '.in' else filename+'.out'
    f = Reader(filename)
    cases = f.read_int()

    if cnum:
        for case in xrange(cases):
            if cnum == case+1:
                print '(line: %d) '%f.linenum
                line = 'Case #%d: %s\n'%(case+1,str(solve(f)))
                print line,
            else:
                solve(f, skip=True)
    else:
        g = open(output, 'w')
        for case in xrange(cases):
            line = 'Case #%d: %s\n'%(case+1,str(solve(f)))
            g.write(line)
            print line,
