"""
Author: Eugene Yurtsev
"""
import sys
import math
from pylab import array, inf

debug=False

def d1(c, x):
    return sum(abs(x-c))

def scan_min(c):
    min_x = min(c)
    max_x = max(c)
    dist = inf
    for x in range(min_x, max_x+1):
        cost =  d1(c, x)
        if dist >  cost:
            dist = cost
    return dist

def calc_min(mat):
    #for c in mat.T:
    #    print scan_min(c)
    return sum([scan_min(c) for c in mat.T])

def parse_case(stream):
    N = int(stream.readline())
    specs = [stream.readline()[:-1] for n in range(N)]
    return N, specs

def find_primary_sequence(s):
    p = [s[0]]
    c = [0]
    for i in s:
        if p[-1] != i:
            p.append(i)
            c.append(1)
        else:
            c[-1] += 1
    p = ''.join(p)
    return p, c

def solve_case(specs):
    c = []
    p1, c1 = find_primary_sequence(specs[1][0])
    c.append(c1)
    for s in specs[1][1:]:
        p, ct = find_primary_sequence(s)
        if p1 <> p:
            return 'Fegla Won'
        else:
            c.append(ct)
    return calc_min(array(c))

def main(stream):
    num_cases = int(stream.readline())

    for case in range(num_cases):
        specs = parse_case(stream)
        print 'Case #{}: {}'.format(case+1, solve_case(specs))

    #if debug:
        #print '-'*40
        #print 'solution'
        #print ''.join(stream.readlines())

if __name__ == '__main__':
    if debug:
        with open('test.in', 'r') as stream:
            main(stream)
    else:
        main(sys.stdin)
