#!/usr/bin/python

import os
import sys
import itertools
import collections
import decimal

decimal.getcontext().prec = 50

def solve(f, skip=False):
    n = f.read_int()
    p = f.read_int_list()
    if skip: return 0

    ss = sum(p)
    s = sum(p)
    ans = []

    if s%2 == 1:
        i = max(p)
        a = p.index(i)
        ans.append(chr(ord('A')+a))
        p[a] -= 1

    for _ in xrange(s/2):
        i = max(p)
        a = p.index(i)
        p[a] -= 1
        i = max(p)
        b = p.index(i)
        p[b] -= 1
        ans.append(chr(ord('A')+a)+chr(ord('A')+b))

    return " ".join(ans)

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
    def read_decimal(self):
        self.linenum += 1
        return decimal.Decimal(self.f.readline().strip())
    def read_str(self):
        self.linenum += 1
        return self.f.readline().strip()

    def read_int_list(self):
        self.linenum += 1
        return map(int, self.f.readline().split())
    def read_float_list(self):
        self.linenum += 1
        return map(float, self.f.readline().split())
    def read_decimal_list(self):
        self.linenum += 1
        return map(decimal.Decimal, self.f.readline().split())
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
