
import csv
import itertools
import copy
import time
import numpy
import itertools


def read_file(filename):
    f = open(filename)
    csv_r = csv.reader(f, delimiter=' ')
    T = int(csv_r.next()[0])
    test_lst = []
    for i in xrange(T):
        R, C, N = csv_r.next()
        test_lst.append([int(R), int(C), int(N)])
    f.close() 
    return test_lst 


def eval_happiness(g):
    h = 0
    for r in g:
        for c1, c2 in itertools.izip(r[:-1], r[1:]):
            if c1 == 1 and c2 == 1:
                h += 1
    return h
        

def solve_test(test_case):
    R, C, N = test_case
    glb_res = None
    for combin in itertools.combinations(range(R*C), N):
        g = []
        for rr in xrange(R):
           g.append([0] * C)
        for e in combin:
            i, j = e % R, e / R
            g[i][j] = 1
        res = eval_happiness(g) + eval_happiness(numpy.array(g).transpose())
        if glb_res is None:
            glb_res = res
        else:
            glb_res = min(res, glb_res)
    return glb_res


def init():
    pass


def main(filename):
    test_lst = read_file(filename)
    init()
    for i_test, test_case in enumerate(test_lst):
        res = solve_test(test_case)
        print "Case #%i: %i" % (1+i_test, res)


if __name__ == '__main__':
    main('./B-small-attempt0.in')
    #main('./C-small-attempt2.in')

