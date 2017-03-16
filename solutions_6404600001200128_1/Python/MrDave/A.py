
import csv
import itertools
import copy
import time
import numpy


def read_file(filename):
    f = open(filename)
    csv_r = csv.reader(f, delimiter=' ')
    T = int(csv_r.next()[0])
    test_lst = []
    for i in xrange(T):
        N = csv_r.next()[0]
        v = csv_r.next()
        test_lst.append([int(N), [int(e) for e in v]])
    f.close() 
    return test_lst 


def solve_test(test_case):
    N, v = test_case
    d = numpy.diff(v)
    m1 = sum([-e for e in d if e <= 0])
    rate = max([-e for e in d if e <= 0])
    m2 = sum([min(rate, vv) for vv in v[:-1]])
    return m1, m2


def init():
    pass


def main(filename):
    test_lst = read_file(filename)
    init()
    for i_test, test_case in enumerate(test_lst):
        m1, m2 = solve_test(test_case)
        print "Case #%i: %i %i" % (1+i_test, m1, m2)


if __name__ == '__main__':
    #main('./simple.in')
    main('./A-large.in')
    #main('./C-small-attempt2.in')

